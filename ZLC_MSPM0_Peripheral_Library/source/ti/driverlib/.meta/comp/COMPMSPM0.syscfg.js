/*
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, DL_COMP_REF_SOURCE_NONEINCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 *  ======== COMPMSPM0.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let EVENT = system.getScript("/ti/driverlib/EVENT.syscfg.js");
let blankingOptionsRef = system.getScript("/ti/driverlib/comp/COMP_blankingSources.js").blankingSources;

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    let pin;

    if (inst.module) {
        let modPin = "DIO" + inst.module.modulePin.$solution.devicePinName;
        modPin = modPin.match(/P\d+\.\d+/)[0];

        pin = "\nMODPIN: " + modPin;

        if (inst.$hardware && inst.$hardware.displayName) {
            pin += "\n" + inst.$hardware.displayName;
        }
    }

    return (pin);


}

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    Common.validateNames(inst, validation);

    /* VDDA Validation */
    if(["DL_COMP_REF_SOURCE_VDDA_DAC"].includes(inst.vSource)){
        if(inst.controlSelect == "DL_COMP_DAC_CONTROL_COMP_OUT"){
            validation.logInfo(
                "DACCODE selection is being controlled by comparator output, calculation assumes DACCODE0 here. Assuming VDDA = 3.3V for calculated value.",
                inst, "calcVoltage"
            );
        }
        else{
            validation.logInfo(
                "Assuming VDDA = 3.3V for calculated value.",
                inst, "calcVoltage"
            );
        }
    }
    /* VREF Validation */
    if(["DL_COMP_REF_SOURCE_VREF_DAC","DL_COMP_REF_SOURCE_VREF"].includes(inst.vSource)){
        // Calculation for Voltage assumes DACCODE0 if selection controlled by comparator output
        if(inst.controlSelect == "DL_COMP_DAC_CONTROL_COMP_OUT"){
            validation.logInfo(
                "DACCODE selection is being controlled by comparator output, calculation assumes DACCODE0 here.",
                inst, "calcVoltage"
            );
        }
        // validate if MSPM0L11XX_L13XX & VREF enabled, check that its not internal reference.
        let vrefInstance = system.modules["/ti/driverlib/VREF"];
        if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
            if (vrefInstance){
                if(!(vrefInstance.$static.basicMode).includes("DL_VREF_ENABLE_DISABLE"))
                validation.logError(
                    "Selected device does not support sourcing internal VREF for COMP, requires enabling external VREF",
                    inst, "vSource"
                );
            }
        }
        /* VREF mode validation for MSPM0L122X_L222X */
        if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
            /* External VREF validation */
            if(inst.vrefMode == "EXTERNAL"){
                if(!vrefInstance.$static.basicMode.includes("DL_VREF_ENABLE_DISABLE")){
                    validation.logError(
                        "External Reference is not enabled in VREF module.",
                        inst, "vrefMode"
                    );
                }
            }
            /* Internal VREF validation */
            else if(inst.vrefMode == "INTERNAL"){
                if(!vrefInstance.$static.basicMode.includes("DL_VREF_ENABLE_ENABLE")){
                    validation.logError(
                        "Internal Reference is not enabled in VREF module.",
                        inst, "vrefMode"
                    );
                }
            }
        }
    }

    /* check if VREF external for Fast Mode profile */
    if(inst.chosenProfile == "fastDAC"){
        let vrefInstance = system.modules["/ti/driverlib/VREF"];
        if (vrefInstance){
            let vrefMode = vrefInstance.$static.basicMode
            if(vrefMode!="DL_VREF_ENABLE_ENABLE"){
                validation.logWarning(
                    "Selected profile requires VREF mode be set to internal.",
                    inst, "chosenProfile"
                );
            }
        }
    }

    /* validate all blanking Enums */
    let dynamicEnums = ["blankingSource", "posChannel", "negChannel"];
    for(let dE of dynamicEnums){
        let validOptions = inst.$module.$configByName[dE].options();
        let selectedOption = inst[dE];
        let found = _.find(validOptions, (o) => o.name === selectedOption);
        if(!found) {
            validation.logError("Invalid Option, please Reselect", inst, dE);
        }
    }

    /* COMP Output Filter is only available in Fast mode, not available in ULP mode */
    if(inst.enableOutputFilter && (inst.compMode == "DL_COMP_MODE_ULP")) {
        validation.logError("Comparator Output Filter is only available when Comparator is in Fast mode", inst, ["enableOutputFilter","compMode"]);
    }

    /* validate that we subscribe to 2 events in sampled mode (beginning and end of sampling window) */
    if (inst.enableSampledMode) {
        if (inst.sub0ChanID != 0 && inst.sub1ChanID == 0) {
            validation.logError("When in Sampled Mode, COMP must subscribe to 2 events to define the start and stop of the sampling window", inst, "sub1ChanID");
        }
        if (inst.sub0ChanID == 0 && inst.sub1ChanID != 0) {
            validation.logError("When in Sampled Mode, COMP must subscribe to 2 events to define the start and stop of the sampling window", inst, "sub0ChanID");
        }
        if (inst.sub0ChanID == 0 && inst.sub1ChanID == 0) {
            validation.logError("When in Sampled Mode, COMP must subscribe to 2 events to define the start and stop of the sampling window", inst, "enableSampledMode");
        }
    }

    if(Common.isDeviceM0G()){
        /* Special Case: DAC12 Validation */
        if(inst.channelEnable.includes("POS") && inst.posChannel == "DL_COMP_IPSEL_CHANNEL_5"){
            let DACMod = system.modules["/ti/driverlib/DAC12"];
            if (DACMod){
                let DACInst = DACMod.$static
                if (!DACInst.dacOutputPinEn){
                    validation.logError("DAC Output Pin should be enabled when configured as input.", inst, ["posChannel"]);
                }
            }
        }
    }

    /* Validate Event selection for case of switching devices.
     * Checks that selected event is withing the valid options
     * for current device.
     */
    EVENT.validatePublisherOptions(inst,validation,"pubChanID");
    if(inst.enableSampledMode){
        EVENT.validateSubscriberOptions(inst,validation,"sub0ChanID");
        EVENT.validateSubscriberOptions(inst,validation,"sub1ChanID");
    }

}

/*
 *  ======== validatePinmux ========
 *  Validate this inst's Pinmux configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validatePinmux(inst, validation){
    /* Some negative and positive channels are only available on
       lower number COMP instances. Each higher number instance is
       strictly a subset of the previous inst, so we can check for the
       set that is exclusive to the lower instance and go more general */
    let peripheralName = inst.peripheral.$solution.peripheralName;
    let nC = parseInt(inst.negChannel.slice(-1)); // retrieve channel num
    let pC = parseInt(inst.posChannel.slice(-1)); // retrieve channel num
    // if the channels selected are COMP0 - specific
    if(!(peripheralName.match(/^COMP0$/) !== null)){
        if(pC === 6){
            validation.logError("Selected channel only available for COMP0", inst, ["posChannel"]);
        }
        if(nC === 6){
            validation.logError("Selected channel only available for COMP0", inst, ["negChannel"]);
        }
    }
    if(!(peripheralName.match(/^COMP(0|1)/) !== null)){
        if ([2,7].includes(pC)){
            validation.logError("Selected channel only available for COMP0 and COMP1", inst, ["posChannel"]);
        }
        if(nC === 2){
            validation.logError("Selected channel only available for COMP0 and COMP1", inst, ["negChannel"]);
        }

    }

    /* Blanking Validation */
    if(inst.blankingSource != "DL_COMP_BLANKING_SOURCE_DISABLE"){
        let PWMMod = system.modules["/ti/driverlib/PWM"];
        let blankingEntry = parseInt(inst.blankingSource.replace("DL_COMP_BLANKING_SOURCE_",""));
        let timerPeripheral = blankingOptionsRef[blankingEntry].peripheral;
        if(!PWMMod){
            /* PWM not configured */
            validation.logError("Selected Blanking Source requires PWM Channel "+parseInt(blankingOptionsRef[blankingEntry].channel)+" to be configured for "+timerPeripheral+". PWM is currently not configured.", inst, ["blankingSource"]);
        }
        else{
            let PWMInst = Common.getTimerPWMInstance(timerPeripheral);
            if(!PWMInst){
                /* Timer Peripheral Instance not configured */
                validation.logError("Selected Blanking Source requires PWM Channel "+parseInt(blankingOptionsRef[blankingEntry].channel)+" to be configured for "+timerPeripheral+". "+timerPeripheral+" is not configured as PWM.", inst, ["blankingSource"]);
            }
            else if(!PWMInst.ccIndex.includes(parseInt(blankingOptionsRef[blankingEntry].channel))){
                /* PWM Channel not configured for desired instance */
                validation.logError("Selected Blanking Source requires PWM Channel "+parseInt(blankingOptionsRef[blankingEntry].channel)+" to be configured for "+timerPeripheral+". PWM Channel is not configured.", inst, ["blankingSource"]);
            }
        }
    }
}

/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured module instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{
    let allResources = [
        {
            name:"compPinPos0",
            displayName:"COMP Positive Channel 0 Pin",
            interfaceNames:["IN0+"],
        },
        {
            name:"compPinNeg0",
            displayName:"COMP Negative Channel 0 Pin",
            interfaceNames:["IN0-"],
        },
        {
            name:"compPinPos1",
            displayName:"COMP Positive Channel 1 Pin",
            interfaceNames:["IN1+"],
        },
        {
            name:"compPinNeg1",
            displayName:"COMP Negative Channel 1 Pin",
            interfaceNames:["IN1-"],
        },
        {
            name:"compPinPos2",
            displayName:"COMP Positive Channel 2 Pin",
            interfaceNames:["IN2+"],
        },
        {
            name:"compPinNeg2",
            displayName:"COMP Negative Channel 2 Pin",
            interfaceNames:["IN2-"],
        },
        {
            name:"compPinPos3",
            displayName:"COMP Positive Channel 3 Pin",
            interfaceNames:["IN3+"],
        },
    ];

    let outPin =
    {
        name:"compPinOut",
        displayName:"COMP Output Pin",
        interfaceNames:["OUT"],
    };

    let comp = {
        name: "peripheral",
        displayName: "COMP Peripheral",
        interfaceName: "COMP",
        resources: [
            // start off empty to get filled-in by the table
        ],
        signalTypes: {
            compPinPos0: ["IN0+"],
            compPinPos1: ["IN1+"],
            compPinPos2: ["IN2+"],
            compPinPos3: ["IN3+"],
            compPinNeg0: ["IN0-"],
            compPinNeg1: ["IN1-"],
            compPinNeg2: ["IN2-"],
            compPinOut: ["OUT"],
        },
    };

    if (inst.outputEnable) {
        comp.resources.push(outPin);
    }

    let ind = 0;
    let compChanRange= 7;
    for(let compChanIdx = 0; compChanIdx < compChanRange; compChanIdx++){
        // Positive Channel pinmux configuration
        if(((inst.channelEnable).includes("POS"))&&((inst.posChannel) ==("DL_COMP_IPSEL_CHANNEL_"+compChanIdx.toString()))){
            if(compChanIdx<3){
                ind = compChanIdx*2
                if(!((comp.resources).includes(allResources[ind]))){
                    comp.resources.push(allResources[ind])
                }
            }
            else if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() && (compChanIdx==3)){
                ind = 6;
                if(!((comp.resources).includes(allResources[ind]))){
                    comp.resources.push(allResources[ind])
                }
            }
        }
        // Negative Channel pinmux configuration
        if(((inst.channelEnable).includes("NEG"))&&((inst.negChannel) ==("DL_COMP_IMSEL_CHANNEL_"+compChanIdx.toString()))){
            if(compChanIdx<3){
                ind = (compChanIdx*2)+1
                if(!((comp.resources).includes(allResources[ind]))){
                    comp.resources.push(allResources[ind])
                }
            }
        }
    }

    return [comp];
}

/*
 *  ========= filterHardware ========
 *  Check 'component' signals for compatibility with module
 *
 *  param component - hardware object describing signals and
 *                    resources they're attached to
 *  returns Boolean indicating whether or not to allow the component to
 *           be assigned to an instance's $hardware config
 */
function filterHardware(component)
{
    let modulePin;

    for (let sig in component.signals) {
        let type = component.signals[sig].type;
        if (Common.typeMatches(type, ["DIN","DOUT"])) modulePin = sig;
    }
    let result = modulePin ? true : false;

    return (result);
}

/*
 *  ======== onChangeVREF ========
 *  Hide fields depending on voltage source selection.
 *
 */
function onChangeVREF(inst,ui){
    updateGUIVREF(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUIVREF(inst,ui){
    if(inst.vSource == "DL_COMP_REF_SOURCE_NONE"){
        ui.terminalSelect.hidden = true;
        ui.vMode.hidden = true;
    }
    else{
        ui.terminalSelect.hidden = false;
        ui.vMode.hidden = false;
    }
    updateGUIDACControl(inst,ui);

    if(["DL_COMP_REF_SOURCE_VREF_DAC","DL_COMP_REF_SOURCE_VREF","DL_COMP_REF_SOURCE_VDDA_DAC"].includes(inst.vSource)){
        ui.calcVoltage.hidden = false;
    }
    else{
        ui.calcVoltage.hidden = true;
    }

    /* Internal/External VREF toggle for COMP */
    if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
        if(["DL_COMP_REF_SOURCE_VREF_DAC","DL_COMP_REF_SOURCE_VREF"].includes(inst.vSource)){
            ui.vrefMode.hidden = false;
        }
        else{
            ui.vrefMode.hidden = true;
        }
    }
}

/*
 *  ======== onChangeDACControl ========
 *  Determines if DACCODE selection is controled by comparator output or DACSW bit,
 *  show/hide options accordingly
 *  Show/hide DAC Code options depending on if user enabled, if control is set to DACSW
 *
 */
function onChangeDACControl(inst,ui){
    updateGUIDACControl(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUIDACControl(inst,ui){
    /* in the process of executing this function, the following visual elements should be set:
     * controlSelect, inputSelect, setDACCode0, setDACCode0.
     * This should be determined solely by:
     * vSource, controlSelect, inputSelect
     * */
    if(inst.vSource == "DL_COMP_REF_SOURCE_NONE" || inst.vSource == "DL_COMP_REF_SOURCE_VREF"){
        // DAC off
        ui.controlSelect.hidden = true;
        ui.inputSelect.hidden = true;
        ui.setDACCode0.hidden = true;
        ui.setDACCode1.hidden = true;
    } else {
        ui.controlSelect.hidden =false;
        // DAC on
        if(inst.controlSelect == "DL_COMP_DAC_CONTROL_COMP_OUT"){
            ui.inputSelect.hidden = true;
            ui.setDACCode0.hidden = false;
            ui.setDACCode1.hidden = false;
        }
        else{ // Control Select == CONTROL_SW
            ui.inputSelect.hidden = false;
            if(inst.inputSelect == "DL_COMP_DAC_INPUT_DACCODE0") {
                ui.setDACCode0.hidden = false;
                ui.setDACCode1.hidden = true;
            }
            else { // inst.inputSelect == "DL_COMP_DAC_INPUT_DACCODE1"
                ui.setDACCode0.hidden = true;
                ui.setDACCode1.hidden = false;
            }
        }
    }

}

/*
 *  ======== onChangeEnabledChannels ========
 *  Show/hide channel input options depending on if user enabled
 *
 */
function onChangeEnabledChannels(inst,ui){
    updateGUIEnabledChannels(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUIEnabledChannels(inst,ui){
    if((inst.channelEnable).includes("POS")){
        ui.posChannel.hidden = false;
    }
    else{
        ui.posChannel.hidden = true;
    }
    if((inst.channelEnable).includes("NEG")){
        ui.negChannel.hidden = false;
    }
    else{
        ui.negChannel.hidden = true;
    }
}

/*
 *  ======== onChangeOutputFilter ========
 *  Show/hide output filter selection based on if user enabled
 *
 */
function onChangeOutputFilter(inst,ui){
    updateGUIOutputFilter(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUIOutputFilter(inst,ui){
    if(inst.enableOutputFilter){
        ui.selectOutputFilter.hidden = false;
    }
    else{
        ui.selectOutputFilter.hidden = true;
    }
}

/*
 *  ======== onChangeSampledMode ========
 *  Show/hide event subscriptions based on if user enabled sampled mode
 *
 */
function onChangeSampledMode(inst,ui){
    updateGUISampledMode(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUISampledMode(inst,ui){
    if(inst.enableSampledMode){
        ui.sub0ChanID.hidden = false;
        ui.sub1ChanID.hidden = false;
    }
    else{
        ui.sub0ChanID.hidden = true;
        ui.sub1ChanID.hidden = true;
    }
}

function onChangeInterrupts(inst, ui){
    updateGUIInterrupts(inst, ui);
    onChangeCustomProfile(inst, ui);
}

function updateGUIInterrupts(inst, ui){
    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
}
/************************* Profiles functions *******************************/
/*
 *  ======== onChangeProfiles ========
 *  Called when COMP Profile is changed.
 *  Pre-configures COMP according to profiles
 *
 */

// TODO: enforce for wincomp profiles that first one is COMP0, second is COMP1.
const profilesCOMP = [
    {
        name                : "ulpGeneral",
        channelEnable       :["POS","NEG"],
        posChannel          :"DL_COMP_IPSEL_CHANNEL_0",
        negChannel          :"DL_COMP_IMSEL_CHANNEL_0",
        compMode            : "DL_COMP_MODE_ULP",
        enableOutputFilter  : true,
    },
    {
        name                : "fastDAC",
        compMode            : "DL_COMP_MODE_FAST",
        vSource             : "DL_COMP_REF_SOURCE_VREF_DAC",
        terminalSelect      : "DL_COMP_REF_TERMINAL_SELECT_NEG",
        enabledInterrupts   : ["DL_COMP_INTERRUPT_OUTPUT_READY"],
        interruptPriority   : "DEFAULT",
        controlSelect       : "DL_COMP_DAC_CONTROL_SW",
        inputSelect         : "DL_COMP_DAC_INPUT_DACCODE0",

    },
];

/*
 * Window comparator profiles are complimentary and involve 2 comparators.
 * Simply checking the device name i.e. M0G vs M0L isn't sufficient since some
 * M0G devices don't have a comparator i.e. those of the M0xx1xx series.
 */
if (Common.peripheralCount("COMP") > 1)
{
    profilesCOMP.push(
        {
            name                : "winCompHigh",
            enableWinComp       : true,
            channelEnable       :["POS"],
            posChannel          : "DL_COMP_IPSEL_CHANNEL_0",
        },
        {
            name                : "winCompLow",
            enableWinComp       : false,
            channelEnable       :["POS"],
            posChannel          : "DL_COMP_IPSEL_CHANNEL_7",
        },
    );
}
else
{
    profilesCOMP.push(
        {
            name                        : "default",
            compMode                    : "DL_COMP_MODE_FAST",
            channelEnable               : [],
            posChannel                  : "DL_COMP_IPSEL_CHANNEL_0",
            negChannel                  : "DL_COMP_IMSEL_CHANNEL_0",
            polarity                    : "DL_COMP_POLARITY_NON_INV",
            hysteresis                  : "DL_COMP_HYSTERESIS_NONE",
            vSource                     : "DL_COMP_REF_SOURCE_NONE",
            vMode                       : "DL_COMP_REF_MODE_STATIC",
            terminalSelect              : "DL_COMP_REF_TERMINAL_SELECT_POS",
            controlSelect               : "DL_COMP_DAC_CONTROL_COMP_OUT",
            inputSelect                 : "DL_COMP_DAC_INPUT_DACCODE0",
            setDACCode0                 : 0,
            setDACCode1                 : 0,
            enableExchangeInputs        : false,
            enableShortInputTerminals   : false,
            outputInterruptEdge         : "DL_COMP_OUTPUT_INT_EDGE_RISING",
            enableOutputFilter          : false,
            selectOutputFilter          : "DL_COMP_FILTER_DELAY_70",
            enableWinComp               : false,
            blankingSource              : "DL_COMP_BLANKING_SOURCE_DISABLE",
            pubChanID                   : 0,
            enabledEvents               : [],
            enabledInterrupts           : [],
            interruptPriority           : "DEFAULT",
        }
    );
}

/*
 *  ======== onChangeProfiles ========
 *  Set options based on configuration profiles selection
 */

function onChangeCOMP(inst, ui){
    updateGUIbasedonConfig(inst,ui);
    onChangeCustomProfile(inst,ui);
}

function onChangeProfiles(inst,ui){
    if (inst.chosenProfile != "custom"){
        /* set configuration to default */
        let defaultingProfileArray = profilesCOMP.filter(obj =>
            {return obj.name === "default"});
        const defaultProfile = Object.assign({}, defaultingProfileArray[0]);
        delete defaultProfile.name;
        Object.assign(inst, defaultProfile)
        /* set configuration to selected profile */
        let selectedProfileArray = profilesCOMP.filter(obj =>
                                        {return obj.name === inst.chosenProfile});
        if (selectedProfileArray.length != 0){
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
        updateGUIbasedonConfig(inst, ui);
    }
}

function onChangeCustomProfile(inst,ui){
    inst.chosenProfile = "custom";
}

function updateGUIbasedonConfig(inst,ui){
    updateGUIEnabledChannels(inst,ui); // dependent on channelEnable
    updateGUIVREF(inst,ui); // dependent on vSource, control select, input select, calls updateGUIDACControl
    updateGUIOutputFilter(inst,ui); // dependent on enableOutputFilter
    updateGUIInterrupts(inst,ui);
}

const eventOptions = [
    {name: "DL_COMP_EVENT_OUTPUT_READY", displayName: "Comparator output ready event"},
    {name: "DL_COMP_EVENT_OUTPUT_EDGE", displayName: "Rising or falling edge of comparator output (selected by IES bit) event"},
    {name: "DL_COMP_EVENT_OUTPUT_EDGE_INV ", displayName: "Rising or falling edge of comparator inverted output (selected by IES bit) event"},
]
const interruptOptions = [
    { name: "DL_COMP_INTERRUPT_OUTPUT_READY", displayName: "Comparator output ready interrupt"},
    { name: "DL_COMP_INTERRUPT_OUTPUT_EDGE", displayName: "Rising or falling edge of comparator output (selected by IES bit) interrupt"},
    { name: "DL_COMP_INTERRUPT_OUTPUT_EDGE_INV", displayName: "Rising or falling edge of comparator inverted output (selected by IES bit) interrupt"},
]

/*
 *  ======== getPositiveChannelOptions ========
 *  generate positive channel options
 */
function getPositiveChannelOptionsWithReason(inst){
    let PositiveChannelOptionsWithReason= [];

    /* MSPM0G-specific options */
    if(Common.isDeviceM0G()){
        PositiveChannelOptionsWithReason = [
            {name: "DL_COMP_IPSEL_CHANNEL_0", displayName: "COMPx_IN0+", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IPSEL_CHANNEL_1", displayName: "COMPx_IN1+", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IPSEL_CHANNEL_2", displayName: "COMPx_IN2+", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IPSEL_CHANNEL_5", displayName: "DAC12 output", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IPSEL_CHANNEL_6", displayName: "OPA1 output", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IPSEL_CHANNEL_7", displayName: "COMPy positive terminal signal", reason: "not available on chosen COMP instance"},
        ];

    }
    /* MSPM0L-specific options */
    else if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
        PositiveChannelOptionsWithReason = [
            {name: "DL_COMP_IPSEL_CHANNEL_0", displayName: "COMPx_IN0+", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IPSEL_CHANNEL_1", displayName: "COMPx_IN1+", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IPSEL_CHANNEL_6", displayName: "OPA1 output", reason: "not available on chosen COMP instance"},
        ];
    }
    else if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
        PositiveChannelOptionsWithReason = [
            {name: "DL_COMP_IPSEL_CHANNEL_0", displayName: "COMPx_IN0+", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IPSEL_CHANNEL_1", displayName: "COMPx_IN1+", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IPSEL_CHANNEL_2", displayName: "COMPx_IN2+", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IPSEL_CHANNEL_3", displayName: "COMPx_IN3+", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IPSEL_CHANNEL_6", displayName: "OPA1 output", reason: "not available on chosen COMP instance"},
        ];
    }
    return PositiveChannelOptionsWithReason;
}

function getPositiveChannelOptions(inst){
    return _.map(getPositiveChannelOptionsWithReason(inst), ({reason, ...naming}) => naming);
}

function getDisabledPositiveChannelOptions(inst){
    let validChannels;
    switch(inst.peripheral.$solution.peripheralName){
        case "COMP0":
            validChannels = [ 0, 1, 2, 5, 6, 7 ];
            if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
                validChannels.push(3);
            }
            break;
        case "COMP1":
            validChannels = [ 0, 1, 2, 5, 7 ];
            break;
        case "COMP2":
            validChannels = [ 0, 1, 5 ];
            break;
        default:
            validChannels = [ 0, 1, 2, 5, 6, 7];
            break;
    }
    let invalidChannels = _.differenceWith(getPositiveChannelOptionsWithReason(inst), validChannels,
        (a,b) => parseInt(a.name.slice(-1)) === b)
    return invalidChannels;
}

/*
 *  ======== getNegativeChannelOptions ========
 *  generate negative channel options
 */
function getNegativeChannelOptionsWithReason(inst){
    let NegativeChannelOptionsWithReason= [];

    /* MSPM0G-specific options */
    if(Common.isDeviceM0G()){
        NegativeChannelOptionsWithReason = [
            {name: "DL_COMP_IMSEL_CHANNEL_0", displayName: "COMPx_IN0-", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IMSEL_CHANNEL_1", displayName: "COMPx_IN1-", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IMSEL_CHANNEL_2", displayName: "COMPx_IN2-", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IMSEL_CHANNEL_5", displayName: "Temperature Sensor", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IMSEL_CHANNEL_6", displayName: "OPA0 Output", reason: "not available on chosen COMP instance"},
        ];

    }
    /* MSPM0L-specific options */
    else if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
        NegativeChannelOptionsWithReason = [
            {name: "DL_COMP_IMSEL_CHANNEL_0", displayName: "COMPx_IN0-", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IMSEL_CHANNEL_1", displayName: "COMPx_IN1-", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IMSEL_CHANNEL_5", displayName: "Temperature Sensor", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IMSEL_CHANNEL_6", displayName: "OPA0 Output", reason: "not available on chosen COMP instance"},
        ];
    }
    else if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
        NegativeChannelOptionsWithReason = [
            {name: "DL_COMP_IMSEL_CHANNEL_0", displayName: "COMPx_IN0-", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IMSEL_CHANNEL_1", displayName: "COMPx_IN1-", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IMSEL_CHANNEL_2", displayName: "COMPx_IN2-", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IMSEL_CHANNEL_5", displayName: "Temperature Sensor", reason: "not available on chosen COMP instance"},
            {name: "DL_COMP_IMSEL_CHANNEL_6", displayName: "OPA0 Output", reason: "not available on chosen COMP instance"},
        ];
    }
    return NegativeChannelOptionsWithReason;
}

function getNegativeChannelOptions(inst){
    return _.map(getNegativeChannelOptionsWithReason(inst), ({reason, ...naming}) => naming);
}

function getNegativeChannelDisabledOptions(inst) {
    let validChannels;
    switch(inst.peripheral.$solution.peripheralName){
        case "COMP0":
            validChannels = [ 0, 1, 2, 5, 6];
            break;
        case "COMP1":
            validChannels = [ 0, 1, 2, 5];
            break;
        case "COMP2":
            validChannels = [ 0, 1, 5];
            break;
        default:
            validChannels = [ 0, 1, 2, 5, 6];
            break;
    }
    let invalidChannels = _.differenceWith(getNegativeChannelOptionsWithReason(inst), validChannels,
        (a,b) => parseInt(a.name.slice(-1)) === b);
    return invalidChannels;
}

/*
 *  ======== getBlankingOptions ========
 *  Determine blanking options based on device family.
 *
 */
function getBlankingOptions(inst){
    let blankingOptions =
    [
        {name: "DL_COMP_BLANKING_SOURCE_DISABLE", displayName: "No blanking"},
    ];
    /* Get Blanking Options from reference file */
    for(let entry in blankingOptionsRef){
        let selectEntry = blankingOptionsRef[entry];
        blankingOptions.push({name: "DL_COMP_BLANKING_SOURCE_"+entry, displayName:""+selectEntry.peripheral+" CC"+selectEntry.channel});
    }
    return blankingOptions;
}

/*
 *  ======== calculateVoltage ========
 *  calculate voltage based on user provided parameters
 */
function calculateVoltage(inst){
    let calcVoltage = 0;
    // 	○ Dac Code Value * (chosen vref) / 256
    let vrefVoltage = 0;
    let dacCode = 0;
    if(inst.vSource == "DL_COMP_REF_SOURCE_VDDA_DAC"){
        vrefVoltage = 3.3
    }
    else{
        let vrefInstance = system.modules["/ti/driverlib/VREF"];
        if (vrefInstance){
            if(Common.isDeviceM0G()){
                // TODO: if VREF is updated to use getUnitPrefix, will need to undo conversion here
                vrefVoltage = (vrefInstance.$static.basicVREFVoltage)/1000
            }
            else if(Common.isDeviceM0L()){
                vrefVoltage = (vrefInstance.$static.basicVREFVoltageExternal)/1000
            }

        }
    }
    dacCode = inst.setDACCode0;
    if(["DL_COMP_REF_SOURCE_VREF_DAC","DL_COMP_REF_SOURCE_VDDA_DAC"].includes(inst.vSource)){
        if(inst.controlSelect == "DL_COMP_DAC_CONTROL_SW"){
            if(inst.inputSelect == "DL_COMP_DAC_INPUT_DACCODE0"){
                dacCode = inst.setDACCode0;
            }
            else if(inst.inputSelect == "DL_COMP_DAC_INPUT_DACCODE1"){
                dacCode = inst.setDACCode1;
            }
        }
        calcVoltage = dacCode * vrefVoltage / 256
    }
    else if(inst.vSource == "DL_COMP_REF_SOURCE_VREF"){
        calcVoltage = vrefVoltage
    }
    return (Common.getUnitPrefix(calcVoltage)).str+"V";
}

/* Voltage Source Options: */
let vSourceOptions = [
    {name: "DL_COMP_REF_SOURCE_NONE", displayName: "Reference voltage generator is disabled (local reference buffer as well as DAC)"},
    {name: "DL_COMP_REF_SOURCE_VDDA_DAC", displayName: "VDDA selected as the reference source to DAC and DAC output applied as reference to comparator"},
    {name: "DL_COMP_REF_SOURCE_VREF_DAC", displayName: "VREF selected as the reference source to DAC and DAC output applied as reference to comparator"},
    {name: "DL_COMP_REF_SOURCE_VREF", displayName: "VREF applied as reference to comparator. DAC is switched off."},
];

function getQuickProfilesConfig()
{
    let quickProfilesConfig = [];

    if (Common.peripheralCount("COMP") > 1)
    {
        quickProfilesConfig.push(
            {
                name        : "chosenProfile",
                displayName : "COMP Profiles",
                description : '',
                longDescription: `
Pre-defined profiles for typical COMP configurations.

The Quick Profile Options are:
* **Ultra-low-power general-purpose with output filter**:
    * Enables positive and negative channel input
        * Sets positive channel input to COMP0_IN0+
        * Sets negative channel input to COMP0_IN0-
    * Sets operating mode to Ultra-Low Power
    * Enables Output Filter
* **Fast mode with internal DAC with digital output**:
    * Sets operating mode to Fast
    * Sets Reference Source to VREF and COMP output applied as reference to comparator
        * VREF should be set to Internal Mode
    * DAC Control set to be SW using DACCODE0
* **Window Comparator High-Side**:
    * **COMP Peripheral should be set to COMP0**
    * Enables window comparator
    * Enables positive channel input
        * Sets COMP0_IN0+ as positive input
* **Window Comparator Low-Side**:
    * **COMP Peripheral should be set to COMP1**
    * Disables window comparator
    * Enables positive channel input
        * Sets COMP0 positive terminal signal as positive input
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "custom",
                onChange    : onChangeProfiles,
                options     : [
                    {name: "ulpGeneral", displayName: "Ultra-low-power general-purpose with output filter"},
                    {name: "fastDAC", displayName: "Fast mode with internal DAC with digital output"},
                    {name: "winCompHigh", displayName: "Window Comparator High-Side"},
                    {name: "winCompLow", displayName: "Window Comparator Low-Side"},
                    {name: "custom", displayName: "Custom"},
                ],
            },
        );
    }
    else
    {
        quickProfilesConfig.push(
            {
                name        : "chosenProfile",
                displayName : "COMP Profiles",
                description : '',
                longDescription: `
Pre-defined profiles for typical COMP configurations.

The Quick Profile Options are:
* **Ultra-low-power general-purpose with output filter**:
    * Enables positive and negative channel input
        * Sets positive channel input to COMP0_IN0+
        * Sets negative channel input to COMP0_IN0-
    * Sets operating mode to Ultra-Low Power
    * Enables Output Filter
* **Fast mode with internal DAC with digital output**:
    * Sets operating mode to Fast
    * Sets Reference Source to VREF and COMP output applied as reference to comparator
        * VREF should be set to Internal Mode
    * DAC Control set to be SW using DACCODE0
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "custom",
                onChange    : onChangeProfiles,
                options     : [
                    {name: "ulpGeneral", displayName: "Ultra-low-power general-purpose with output filter"},
                    {name: "fastDAC", displayName: "Fast mode with internal DAC with digital output"},
                    {name: "custom", displayName: "Custom"},
                ],
            },
        );
    }

    return quickProfilesConfig;
}

function getPinName(inst, passedPin){
    let pinInfo =  "-"
    if(inst.peripheral.$solution){
        let baseName = inst.peripheral.$solution.peripheralName
        let peripheral = system.deviceData.peripherals[baseName];
        if (peripheral){
            let peripheralPins = system.deviceData.peripherals[baseName].peripheralPins[baseName+"."+passedPin]
            if(peripheralPins){
                let pinMappings = peripheralPins.pinMappings["0"]
                if(pinMappings){
                    pinInfo = pinMappings.designSignalName
                }
            }
        }
    }

    return pinInfo
}

let config = [
    /* Show selected peripheral below instance name */
    {
        name: "selectedInstance",
        displayName: "Selected Peripheral",
        default: "",
        longDescription: `Refer to the PinMux section for peripheral selection. Chosen instance name is not indicative of active peripheral.`,
        getValue: (inst) => {
            let solution = "";
            try{
                solution = inst.peripheral.$solution.peripheralName;
            }catch (e) {
                // do nothing
            }
            return solution;
        }
    },
    {
        name: "GROUP_PROFILES",
        displayName: "Quick Profiles",
        collapsed: false,
        config: getQuickProfilesConfig(),
    },
    {
        name: "GROUP_BASIC",
        displayName: "Basic Configuration",
        description: "",
        longDescription: `Initializes all the common configurable options for the
                            COMP peripheral and reference voltage generator.`,
        collapsed: false,
        config: [
            /* DL_COMP_init*/
            {
                name        : "compMode",
                displayName : "Operating Mode",
                description : 'The operating mode of the comparator',
                hidden      : false,
                default     : "DL_COMP_MODE_FAST",
                options     : [
                    {name: "DL_COMP_MODE_FAST", displayName: "Fast mode"},
                    {name: "DL_COMP_MODE_ULP", displayName: "Ultra-low power (ULP) mode"},
                ],
                onChange    : onChangeCOMP,
            },
            {
                name        : "channelEnable",
                displayName : "Enable Channel Inputs",
                description : 'The channel inputs to the comparator terminals to enable',
                hidden      : false,
                default     : [],
                minSelections: 0,
                onChange    : onChangeEnabledChannels,
                options     : [
                    {name: "POS", displayName: "Channel input enabled for the positive terminal"},
                    {name: "NEG", displayName: "Channel input enabled for the negative terminal"},
                ],
            },
            {
                name        : "outputEnable",
                displayName : "Enable Output",
                description : 'Enable the output of the comparator',
                hidden      : false,
                default     : false,
                onChange    : onChangeCustomProfile,
            },
            {
                name        : "posChannel",
                displayName : "Positive Terminal Channel Input",
                description : 'The channel input for the positive terminal of the comparator',
                hidden      : true,
                default     : "DL_COMP_IPSEL_CHANNEL_0",
                options     : getPositiveChannelOptions,
                getDisabledOptions: getDisabledPositiveChannelOptions,
                onChange    : onChangeCustomProfile,
            },
            /* Hidden helper field to determine selected pin name */
            {
                name        : "posChannel1Pin",
                displayName : "Positive Channel 1 Pin Name",
                getValue    : (inst) => getPinName(inst, "IN1+"),
                default     : "-",
                hidden      : true,
            },
            {
                name        : "negChannel",
                displayName : "Negative Terminal Channel Input",
                description : 'The channel input for the negative terminal of the comparator',
                hidden      : true,
                default     : "DL_COMP_IMSEL_CHANNEL_0",
                options     : getNegativeChannelOptions,
                getDisabledOptions: getNegativeChannelDisabledOptions,
                onChange    : onChangeCustomProfile,
            },
            {
                name        : "polarity",
                displayName : "Output Polarity",
                description : 'The polarity of the comparator output',
                hidden      : false,
                default     : "DL_COMP_POLARITY_NON_INV",
                options     : [
                    {name: "DL_COMP_POLARITY_NON_INV", displayName: "Non-inverted."},
                    {name: "DL_COMP_POLARITY_INV", displayName: "Inverted."},
                ],
                onChange    : onChangeCustomProfile,
            },
            {
                name        : "hysteresis",
                displayName : "Hysteresis",
                description : 'The hysteresis of the comparator',
                hidden      : false,
                default     : "DL_COMP_HYSTERESIS_NONE",
                options     : [
                    {name: "DL_COMP_HYSTERESIS_NONE", displayName: "No hysteresis"},
                    {name: "DL_COMP_HYSTERESIS_10", displayName: "10mV"},
                    {name: "DL_COMP_HYSTERESIS_20", displayName: "20mV"},
                    {name: "DL_COMP_HYSTERESIS_30", displayName: "30mV"},
                ],
                onChange    : onChangeCustomProfile,
            },
            /* DL_COMP_refVoltageInit */
            {
                name: "GROUP_VREF",
                displayName: "Reference Voltage Generator Configuration",
                description: "",
                longDescription: "",
                collapsed: false,
                config: [
                    // TODO: improve wording for these options, might also change to have a separate checkbox or something. point is, it can be improved.
                    {
                        name        : "vSource",
                        displayName : "Reference Source",
                        description : 'The reference source of the comparator',
                        hidden      : false,
                        default     : "DL_COMP_REF_SOURCE_NONE",
                        onChange    : onChangeVREF,
                        options     : vSourceOptions,
                    },
                    {
                        name        : "vrefMode",
                        displayName : "VREF Mode",
                        description : 'Select internal or external VREF for COMP use',
                        hidden      : true,
                        default     : "EXTERNAL",
                        onChange    : onChangeCustomProfile,
                        options     : [
                            {name: "INTERNAL", displayName: "Internal"},
                            {name: "EXTERNAL", displayName: "External"},
                        ],
                    },
                    {
                        name        : "vMode",
                        displayName : "Reference Operating Mode",
                        description : 'The operating mode of the reference voltage generator',
                        hidden      : true,
                        default     : "DL_COMP_REF_MODE_STATIC",
                        options     : [
                            {name: "DL_COMP_REF_MODE_STATIC", displayName: "Static"},
                            {name: "DL_COMP_REF_MODE_SAMPLED", displayName: "Sampled"},
                        ],
                        onChange    : onChangeCustomProfile,
                    },
                    {
                        name        : "terminalSelect",
                        displayName : "Terminal",
                        description : 'The terminals the reference voltage is applied to',
                        hidden      : true,
                        default     : "DL_COMP_REF_TERMINAL_SELECT_POS",
                        options     : [
                            {name: "DL_COMP_REF_TERMINAL_SELECT_POS", displayName: "Reference applied to positive terminal"},
                            {name: "DL_COMP_REF_TERMINAL_SELECT_NEG", displayName: "Reference applied to negative terminal"},
                        ],
                        onChange    : onChangeCustomProfile,
                    },
                    /* TODO: check on better naming for this option */
                    {
                        name        : "controlSelect",
                        displayName : "DAC Control",
                        description : 'Determines what controls the selection between DACCODE0 and DACCODE1',
                        hidden      : true,
                        default     : "DL_COMP_DAC_CONTROL_COMP_OUT",
                        onChange    : onChangeDACControl,
                        options     : [
                            {name: "DL_COMP_DAC_CONTROL_COMP_OUT", displayName: "Comparator output controls selection betwen DACCODE0 and DACCODE1"},
                            {name: "DL_COMP_DAC_CONTROL_SW", displayName: "DACSW bit controls selection betwen DACCODE0 and DACCODE1"},
                        ],
                    },
                    /* TODO: check on DAC Control dependency of options */
                    {
                        name        : "inputSelect",
                        displayName : "DAC Input",
                        description : 'If DL_COMP_DAC_CONTROL_SW is enabled, selects between DACCODE0 and DACCODE1',
                        hidden      : true,
                        default     : "DL_COMP_DAC_INPUT_DACCODE0",
                        onChange    : onChangeDACControl,
                        options     : [
                            {name: "DL_COMP_DAC_INPUT_DACCODE0", displayName: "DACCODE0 selected as input for 8-bit COMP when DACCTL bit is 1"},
                            {name: "DL_COMP_DAC_INPUT_DACCODE1", displayName: "DACCODE1 selected as input for 8-bit COMP when DACCTL bit is 1"},
                        ],
                    },
                    /* DL_COMP_setDACCode0 */
                    {
                        name        : "setDACCode0",
                        displayName : "Input Code Through DACCODE0",
                        description : 'Set the 8-bit COMP input code through DACCODE0',
                        hidden      : true,
                        displayFormat: "hex",
                        range       : [0,255],
                        default     : 0,
                        onChange    : onChangeCustomProfile,
                    },
                    /* DL_COMP_setDACCode1 */
                    {
                        name        : "setDACCode1",
                        displayName : "Input Code Through DACCODE1",
                        description : 'Set the 8-bit COMP input code through DACCODE1',
                        hidden      : true,
                        displayFormat: "hex",
                        range       : [0,255],
                        default     : 0,
                        onChange    : onChangeCustomProfile,
                    },
                    {
                        name        : "calcVoltage",
                        longDescription: `
Calculated voltage based on user provided parameters:
Voltage = (DACCODE Value) * (VREF) / 256`,
                        displayName : "Calculated Voltage",
                        default     : "0V",
                        getValue    : (inst) => calculateVoltage(inst),
                        hidden      : true,
                    },
                ]
            },
        ]
    },
    {
        name: "GROUP_ADVANCED",
        displayName: "Advanced Configuration",
        description: "",
        longDescription: "",
        collapsed: false,
        config: [
            /* enableExhangeInputs / disableExhangeInputs */
            {
                name        : "enableExchangeInputs",
                displayName : "Exchange Inputs",
                description : 'Enable exchange of the comparator inputs, and invert output',
                hidden      : false,
                default     : false,
                onChange    : onChangeCustomProfile,
            },
            /* DL_COMP_enableShortInputTerminals / DL_COMP_disableShortInputTerminals */
            {
                name        : "enableShortInputTerminals",
                displayName : "Short Intput Terminals",
                description : 'Enable shorting of the comparator inputs',
                hidden      : false,
                default     : false,
                onChange    : onChangeCustomProfile,
            },
            /* DL_COMP_setOutputInterruptEdge */
            {
                name        : "outputInterruptEdge",
                displayName : "Output Interrupt Edge",
                description : 'Set the interrupt edge for the comparator output',
                hidden      : false,
                default     : "DL_COMP_OUTPUT_INT_EDGE_RISING",
                options     : [
                    {name: "DL_COMP_OUTPUT_INT_EDGE_RISING", displayName: "Rising edge sets COMPIFG and falling edge sets COMPINVIFG"},
                    {name: "DL_COMP_OUTPUT_INT_EDGE_FALLING", displayName: "Falling edge sets COMPIFG and rising edge sets COMPINVIFG"},
                ],
                onChange    : onChangeCustomProfile,
            },
            /* DL_COMP_enableOutputFilter / DL_COMP_disableOutputFilter */
            {
                name        : "enableOutputFilter",
                displayName : "Enable Output Filter",
                description : '',
                hidden      : false,
                default     : false,
                onChange    : onChangeOutputFilter,
            },
            {
                name        : "selectOutputFilter",
                displayName : "Select Output Filter Delay",
                description : '',
                hidden      : true,
                default     : "DL_COMP_FILTER_DELAY_70",
                options     : [
                    {name: "DL_COMP_FILTER_DELAY_70", displayName: "70ns"},
                    {name: "DL_COMP_FILTER_DELAY_500", displayName: "500ns"},
                    {name: "DL_COMP_FILTER_DELAY_1200", displayName: "1200ns"},
                    {name: "DL_COMP_FILTER_DELAY_2700", displayName: "2700ns"},
                ],
                onChange    : onChangeCustomProfile,
            },
            /* DL_COMP_enableWindowComparator / DL_COMP_disableWindowComparator */
            {
                name        : "enableWinComp",
                displayName : "Enable Window Comparator",
                description : '',
                hidden      : false,
                default     : false,
                onChange    : onChangeCustomProfile,
            },
            /* DL_COMP_setBlankingSource */
            {
                name        : "blankingSource",
                displayName : "Blanking Source",
                description : 'Set the blanking source for the comparator',
                hidden      : false,
                default     : "DL_COMP_BLANKING_SOURCE_DISABLE",
                options     : (inst) => getBlankingOptions(inst),
                onChange    : onChangeCustomProfile,
            },
            /* DL_COMP_enableSampledMode */
            {
                name        : "enableSampledMode",
                displayName : "Enable Sampled Mode",
                description : 'Enable Sampled Mode for the comparator',
                hidden      : false,
                default     : false,
                onChange    : onChangeSampledMode,
            },
        ]
    },
    {
        name: "GROUP_EVENTS",
        displayName: "Event Configuration",
        description: "",
        longDescription: "",
        collapsed: false,
        config: [
            /* DL_COMP_setPublisherChanID */
            {
                name        : "pubChanID",
                displayName : "Publisher Channel ID",
                description : '',
                hidden      : false,
                default     : 0,
                options     : EVENT.getPublisherOptions,
                getDisabledOptions: EVENT.getPublisherDisabledOptions,
                onChange    : onChangeCustomProfile,
            },
            /* DL_COMP_enableEvent / DL_COMP_disableEvent */
            {
                name        : "enabledEvents",
                displayName : "Enable Events",
                description : '',
                hidden      : false,
                default     : [],
                minSelections: 0,
                options     : eventOptions,
                onChange    : onChangeCustomProfile,
            },
            /* DL_COMP_setSubscriberChanID */
            {
                name        : "sub0ChanID",
                displayName : "Event 0 Subscriber Channel ID",
                description : 'Sets the event 0 subscriber channel ID',
                hidden      : true,
                default: 0,
                options: EVENT.getSubscriberOptions,
                getDisabledOptions: EVENT.getSubscriberDisabledOptions,
                onChange    : onChangeCustomProfile,
            },
            /* DL_COMP_setSubscriberChanID */
            {
                name        : "sub1ChanID",
                displayName : "Event 1 Subscriber Channel ID",
                description : 'Sets the event 1 subscriber channel ID',
                hidden      : true,
                default: 0,
                options: EVENT.getSubscriberOptions,
                getDisabledOptions: EVENT.getSubscriberDisabledOptions,
                onChange    : onChangeCustomProfile,
            },
            {
                name: "eventInfo",
                description: "information about configured events that's passed on to the EVENT module",
                default: [""],
                hidden: true,
                options: (inst) => {
                    let options = [{name: ""}]
                    if(inst.pubChanID != 0){
                        options.push({name: inst.pubChanID.toString() + "pub"});
                    }
                    if(inst.sub0ChanID != 0){
                        options.push({name: inst.sub0ChanID.toString() + "sub"});
                    }
                    if(inst.sub1ChanID != 0){
                        options.push({name: inst.sub1ChanID.toString() + "sub"});
                    }
                    return options;
                },
                getValue: (inst) => {
                    let result = [];
                    if(inst.pubChanID != 0){
                        result.push(inst.pubChanID.toString() + "pub");
                    }
                    if(inst.sub0ChanID != 0){
                        result.push(inst.sub0ChanID.toString() + "sub");
                    }
                    if(inst.sub1ChanID != 0){
                        result.push(inst.sub1ChanID.toString() + "sub");
                    }
                    if(result.length == 0){
                        result = [""];
                    }
                    return result;
                }
            }
        ]
    },
    {
        name: "GROUP_INTERRUPTS",
        displayName: "Interrupt Configuration",
        description: "",
        longDescription: "",
        collapsed: false,
        config: [
            /* DL_COMP_enableInterrupt / DL_COMP_disableInterrupt */
            {
                name        : "enabledInterrupts",
                displayName : "Enable Interrupts",
                description : '',
                hidden      : false,
                default     : [],
                minSelections: 0,
                options     : interruptOptions,
                onChange    : onChangeInterrupts,
            },
            {
                name: "interruptPriority",
                displayName: "Interrupt Priority",
                description: "Specifies interrupt priority (GROUP 1)",
                longDescription: `
COMP Modules are placed in the INT_GROUP1 peripheral group,
thus their interrupt priority is tied to other members of the group.

INT_GROUP1:
* GPIO (all)
* COMP
* TRNG (if available)
                    `,
                hidden: true,
                default: "DEFAULT",
                options: Common.InterruptPriorityOptions,
            },
        ]
    },
];

/* Add Pinmux Peripheral Configuration group */
config = config.concat(Common.getGPIOGroupConfig());

function moduleInstances(inst){
    let modInstances = [];

    /*
     * Gets a Peripheral GPIO Configuration submodule
     */
    /* CONDITIONS CODE START */
    // IN0+, IN0-, IN1+, IN1-, IN2+, IN2-,
    let compConfig = [false, false, false, false, false, false];
    let compPinOut = false;

    if (inst.outputEnable) {
        compPinOut = true;
    }
    let ind = 0;
    let compChanRange= 7;
    for(let compChanIdx = 0; compChanIdx < compChanRange; compChanIdx++){
        // Positive Channel pinmux configuration
        if(((inst.channelEnable).includes("POS"))&&((inst.posChannel) ==("DL_COMP_IPSEL_CHANNEL_"+compChanIdx.toString()))){
            if(compChanIdx<3){
                ind = compChanIdx*2
                compConfig[ind] = true;
            }
        }
        // Negative Channel pinmux configuration
        if(((inst.channelEnable).includes("NEG"))&&((inst.negChannel) ==("DL_COMP_IMSEL_CHANNEL_"+compChanIdx.toString()))){
            if(compChanIdx<3){
                ind = (compChanIdx*2)+1
                compConfig[ind] = true;
            }
        }
    }
    /* CONDITIONS CODE END */
    /* IN0+ */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   compConfig[0],    "compPinPos0",
     "IN0P", "COMP Positive Channel 0 Pin",
     "INPUT");

    /* IN1+ */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   compConfig[2],    "compPinPos1",
     "IN1P", "COMP Positive Channel 1 Pin",
     "INPUT");

    /* IN2+ */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   compConfig[4],    "compPinPos2",
     "IN2P", "COMP Positive Channel 2 Pin",
     "INPUT");

    /* IN0- */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   compConfig[1],    "compPinNeg0",
     "IN0N", "COMP Negative Channel 0 Pin",
     "INPUT");

    /* IN1- */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   compConfig[3],    "compPinNeg1",
     "IN1N", "COMP Negative Channel 1 Pin",
     "INPUT");

    /* IN2- */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   compConfig[5],    "compPinNeg2",
    "IN2N", "COMP Negative Channel 2 Pin",
    "INPUT");

    /* OUT */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   compPinOut,    "compPinOut",
     "OUT", "COMP Output Pin",
     "OUTPUT");


    return modInstances;
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: config,

    maxInstances: Common.peripheralCount("COMP"),

    /* override generic requirements with  device-specific reqs (if any) */
    validate: validate,

    validatePinmux: validatePinmux,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/comp/COMP.Board.c.xdt",
        boardh: "/ti/driverlib/comp/COMP.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true
    },
    modules: setRequiredModules,

    moduleInstances: moduleInstances,

    _getPinResources: _getPinResources
};

function setRequiredModules(inst){
    let theModules = ["Board", "SYSCTL", "EVENT"]
    /* Add VREF to required modules when configured as voltage source */
    if(["DL_COMP_REF_SOURCE_VREF_DAC","DL_COMP_REF_SOURCE_VREF"].includes(inst.vSource)){
        theModules.push("VREF");
    }
    /* Add DAC to required modules when selected as input: only selectable in MSPM0G devices through Channel 5 */
    if(Common.isDeviceM0G() && inst.channelEnable.includes("POS") && inst.posChannel == "DL_COMP_IPSEL_CHANNEL_5"){
        theModules.push("DAC12");
    }

    let kwargs = theModules;
    let modArray = [];

    for (let args = kwargs.length - 1; args >= 0; args--) {
        let modPath = kwargs[args];
        if (modPath.indexOf('/') == -1) {
            modPath = "/ti/driverlib/" + modPath;
        }
        modArray.push({
            name      : modPath.substring(modPath.lastIndexOf('/') + 1),
            moduleName: modPath,
            hidden    : true
        });
    }

    return modArray;
}




/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic module module to
 *  allow us to augment/override as needed for the MSP432.
 */
function extend(base)
{
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base, devSpecific);

    /* concatenate device-specific configs */
    result.config = base.config.concat(devSpecific.config);

    return (result);
}

/*
 *  ======== exports ========
 *  Export device-specific extensions to base exports
 */
exports = {
    /* required function, called by base module module */
    extend: extend
};
