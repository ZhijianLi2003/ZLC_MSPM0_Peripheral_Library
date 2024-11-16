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
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 *  ======== DAC12MSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common  = system.getScript("/ti/driverlib/Common.js");
let EVENT   = system.getScript("/ti/driverlib/EVENT.syscfg.js");


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
    // Common.validateNames(inst, validation);

    /* Validate Calculated Voltage */
    if(inst.dacPosVREF == "VDDA" && inst.dacOutputPinEn){
        validation.logInfo(
            "Assuming VDDA = 3.3V for calculated value.",
            inst, "calcVoltage"
        );
    }

    /* Check if MFPCLK enabled */
    if(system.modules["/ti/driverlib/SYSCTL"].$static.MFPCLK_Freq == 0) {
        validation.logError("MFPCLK must be enabled in order to use DAC12.", inst, ["dacEnable"]);
    }

    /* FIFO Validation */
    if(inst.dacFIFOEn){
        if((inst.dacFIFOTrigger == "SAMPLETIMER") && ( !inst.dacSampleTimerEn)){
            validation.logError("Must enable Sample Time Generator in order to use as FIFO trigger.", inst, ["dacFIFOTrigger","dacSampleTimerEn"]);
        }
        if((inst.dacFIFOTrigger == "HWTRIG0") && (inst.sub0ChanID == 0)){
            validation.logError("Hardware trigger 0 event fabric is enabled AND the corresponding subscriber hasn't been configured.", inst, ["dacFIFOTrigger","sub0ChanID"]);
        }
    }

    /* Event Validation */
    if(inst.sub0ChanID != 0){
        if(!inst.dacFIFOEn){
            validation.logInfo("Event 0 Subscriber is configured but not used as a DAC trigger.", inst, ["dacFIFOEn","sub0ChanID"]);
        }
        else if(inst.dacFIFOTrigger != "HWTRIG0"){
            validation.logInfo("Event 0 Subscriber is configured but not used as a DAC trigger.", inst, ["dacFIFOTrigger","sub0ChanID"]);
        }
    }
    if(((inst.enabledEvents).length>0)&& (inst.pubChanID == 0)){
        validation.logInfo("Event Publisher has not been configured.", inst, ["pubChanID"]);
    }

    /* Special Case: COMP Input validation */
    if(!inst.dacOutputPinEn){
        let COMPMod = system.modules["/ti/driverlib/COMP"];
        if (COMPMod){
            let COMPInsts = COMPMod.$instances
            for(let singleCOMP of COMPInsts){
                if (singleCOMP.channelEnable.includes("POS") && singleCOMP.posChannel == "DL_COMP_IPSEL_CHANNEL_5"){
                    validation.logError("DAC Output pin should be enabled when configured for COMP input.", inst, ["dacOutputPinEn"]);
                }
            }
        }
        let OPAMod = system.modules["/ti/driverlib/OPA"];
        if (OPAMod){
            let OPAInsts = OPAMod.$instances
            for(let singleOPA of OPAInsts){
                if (singleOPA.cfg0PSELChannel == "DAC_OUT" || singleOPA.cfg0MSELChannel == "DAC_OUT"){
                    validation.logError("DAC Output pin should be enabled when configured for OPA input.", inst, ["dacOutputPinEn"]);
                }
            }
        }
    }

    /* Validate Event selection for case of switching devices.
     * Checks that selected event is withing the valid options
     * for current device.
     */
    if(inst.enabledEvents.length>0){
        EVENT.validatePublisherOptions(inst,validation,"pubChanID");
    }
    EVENT.validateSubscriberOptions(inst,validation,"sub0ChanID");
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
    let resources = [];

    let out = {
        name:"OutPin",
        displayName:"DAC12 Output Pin",
        interfaceNames:["OUT"],
    };

    if (inst.dacOutputPinEn == true)
    {
        resources.push(out);
    }

    let dac12 = {
        name          : "peripheral",
        displayName   : "DAC12 Peripheral",
        interfaceName : "DAC",
        resources     : resources,
        signalTypes   : {

        }
    };
    return [dac12];
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
        if (Common.typeMatches(type, ["DAC12"])) modulePin = sig;
    }
    let result = modulePin ? true : false;

    return (result);
}

/************************* Profiles functions *******************************/
const profilesDAC12 = [

];

function onChangeSetCustomProfile(inst, ui)
{
    inst.profile = "CUSTOM";
}

function onChangeDAC12Profile(inst, ui)
{
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = profilesDAC12.filter(obj =>
                                        {return obj.name === inst.profile});
        if (selectedProfileArray.length != 0)
        {
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
    }
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
        name: "GROUP_PROFILE",
        displayName: "Quick Profiles",
        description: "",
        collapsed: false,
        config: [
            {
                name: "profile",
                displayName: "DAC12 Profiles",
                description: "Pre-defined profiles for typical DAC12 configurations",
                longDescription: ``,
                hidden: false,
                default: "CUSTOM",
                options: [
                    {name: "CUSTOM", displayName: "Custom"},
                ],
                onChange: onChangeDAC12Profile,
            },
        ],
    },
]

config  = config.concat([
    {
        name: "GROUP_BASIC",
        displayName: "Basic Operation Configuration",
        longDescription: `Basic DAC12 options.`,
        collapsed: false,
        config: [
            // DL_DAC12_enable()
            {
                name        : "dacEnable",
                displayName : "Enable DAC",
                description : 'Enables the DAC module',
                hidden      : false,
                default     : true,
            },
            // DL_DAC12_init -> DL_DAC12_init
            {
                name        : "dacPosVREF",
                displayName : "Positive Voltage Reference",
                description : 'The positive voltage reference.',
                hidden      : false,
                default     : "VDDA",
                options     : [
                    {name: "VDDA", displayName: "Positive reference is VDDA"},
                    {name: "VEREFP", displayName: "Positive reference is VREF+"},
                ],
            },
            {
                name        : "dacNegVREF",
                displayName : "Negative Voltage Reference",
                description : 'The negative voltage reference.',
                hidden      : false,
                default     : "VSSA",
                options     : [
                    {name: "VSSA", displayName: "Negative reference is VSSA"},
                    {name: "VEREFN", displayName: "Negative reference is VREF-"},
                ],
            },
            // DL_DAC12_FIFO
            {
                name        : "dacFIFOEn",
                displayName : "Enable FIFO",
                description : 'The FIFO enable.',
                hidden      : false,
                default     : false,
                onChange    : (inst,ui) => {
                    ui.dacFIFOTrigger.hidden = !(inst.dacFIFOEn);
                    ui.dacFIFOThresh.hidden = !(inst.dacFIFOEn & inst.dacConfigureDMA);
                    if(inst.dacFIFOEn && (inst.dacFIFOTrigger == "SAMPLETIMER")){
                        inst.dacSampleTimerEn = true;
                        ui.dacSampleTimerRate.hidden = false;
                    }
                }

            },
            // DL_DAC12_FIFO_TRIGGER
            {
                name        : "dacFIFOTrigger",
                displayName : "FIFO Trigger Source",
                description : 'The FIFO Trigger source.',
                hidden      : true,
                default     : "SAMPLETIMER",
                options     : [
                    {name: "SAMPLETIMER", displayName: "Sample time generator"},
                    {name: "HWTRIG0", displayName: "Hardware trigger 0 event fabric"},
                ],
                onChange    : (inst,ui) => {
                    if(inst.dacFIFOEn && (inst.dacFIFOTrigger == "SAMPLETIMER")){
                        inst.dacSampleTimerEn = true;
                        ui.dacSampleTimerRate.hidden = false;
                    }
                },
            },
            {
                name: "GROUP_DMA",
                displayName: "DMA Configuration",
                description: "",
                longDescription: "",
                collapsed: true,
                config: [
                    // DL_DAC12_DMA_TRIGGER
                    {
                        name        : "dacConfigureDMA",
                        displayName : "Configure DMA Trigger",
                        hidden      : false,
                        default     : false,
                        onChange    : (inst,ui) => {
                            ui.dacFIFOThresh.hidden = !(inst.dacFIFOEn & inst.dacConfigureDMA);
                            ui.dacDMATrigger.hidden = !(inst.dacConfigureDMA);
                        }
                    },
                    {
                        name        : "dacDMATrigger",
                        displayName : "Enable DMA Trigger",
                        description : 'The bit to enable a DMA trigger source to use the DMA instead of the CPU to input data.',
                        hidden      : true,
                        default     : true,

                    },

                ]
            },
            // DL_DAC12_FIFO_THRESHOLD
            {
                name        : "dacFIFOThresh",
                displayName : "FIFO Threshold",
                description : 'The FIFO Threshold at which the DMA Trigger is asserted.',
                hidden      : true,
                default     : "ONE_QTR_EMPTY",
                options     : [
                    {name: "ONE_QTR_EMPTY", displayName: "1/4th of locations are empty"},
                    {name: "TWO_QTRS_EMPTY", displayName: "2/4th of locations are empty"},
                    {name: "THREE_QTRS_EMPTY", displayName: "3/4th of locations are empty"},
                ],
            },
            // DL_DAC12_SAMPLETIMER
            {
                name        : "dacSampleTimerEn",
                displayName : "Enable Sample Time Generator",
                description : 'Enables the sample time generator as the FIFO trigger.',
                hidden      : false,
                default     : false,
                onChange    : (inst,ui) => {
                    ui.dacSampleTimerRate.hidden = !(inst.dacSampleTimerEn);
                }
            },
            // DL_DAC12_SAMPLES_PER_SECOND
            {
                name        : "dacSampleTimerRate",
                displayName : "Sample Time Generator Rate",
                description : 'Rate of the sample time generator.',
                hidden      : true,
                default     : "500",
                options     : [
                    {name: "500", displayName: "500 SPS"},
                    {name: "1K", displayName: "1 kSPS"},
                    {name: "2K", displayName: "2 kSPS"},
                    {name: "4K", displayName: "4 kSPS"},
                    {name: "8K", displayName: "8 kSPS"},
                    {name: "16K", displayName: "16 kSPS"},
                    {name: "100K", displayName: "100 kSPS"},
                    {name: "200K", displayName: "200 kSPS"},
                    {name: "500K", displayName: "500 kSPS"},
                    {name: "1M", displayName: "1 MSPS"},
                ],
            },
            //DL_DAC12_enableOutputPin
            {
                name        : "dacOutputPinEn",
                displayName : "Enable DAC Output",
                description : 'Enables the DAC output by connecting it to the OUT0 pin',
                hidden      : false,
                default     : false,
                onChange    : (inst,ui) => {
                    ui.calcVoltage.hidden = !(inst.dacOutputPinEn);
                    ui.dacOutput8.hidden = !(inst.dacRes == "8BIT")||!(inst.dacOutputPinEn);
                    ui.dacOutput12.hidden = !(inst.dacRes == "12BIT")||!(inst.dacOutputPinEn);
                },
            },
            {
                name        : "dacOutput8",
                displayName : "Default DAC Value (8-Bit)",
                description : '',
                hidden      : true,
                default     : 0,
                isInteger   : true,
                range       : [0x0,0xFF],
            },
            {
                name        : "dacOutput12",
                displayName : "Default DAC Value (12-Bit)",
                description : '',
                hidden      : true,
                default     : 0,
                isInteger   : true,
                range       : [0x0,0xFFF],
            },
            {
                name        : "calcVoltage",
                longDescription: `
Calculated voltage based on user provided parameters:\n
8-bit resolution: Voltage = (DATA Value) * (VREF) / 256\n
12-bit resolution: Voltage = (DATA Value) * (VREF) / 4096`,
                displayName : "Calculated Voltage",
                default     : "0V",
                getValue    : (inst) => {
                    //
                    let resValue = 256;
                    if(inst.dacRes == "12BIT"){
                        resValue = 4096;
                    }
                    //
                    let calcVoltage = 0;
                    // 	○ Dac Code Value * (chosen vref) / resValue
                    let vrefVoltage = 0;
                    let dacCode = 0;
                    if(inst.dacPosVREF == "VDDA"){
                        vrefVoltage = 3.3
                    }
                    else{
                        let vrefInstance = system.modules["/ti/driverlib/VREF"];
                        if (vrefInstance){
                            // TODO: if VREF is updated to use getUnitPrefix, will need to undo conversion here
                            vrefVoltage = (vrefInstance.$static.basicVREFVoltage)/1000
                        }
                    }
                    dacCode = inst.dacOutput8;
                    if(inst.dacRes == "12BIT"){
                        dacCode = inst.dacOutput12;
                    }
                    calcVoltage = dacCode * vrefVoltage / resValue
                    return (Common.getUnitPrefix(calcVoltage)).str+"V";
                },
                hidden      : true,
            },

        ],
    },
    {
        name: "GROUP_ADVANCED",
        displayName: "Advanced Configuration",
        description: "",
        longDescription: "",
	    collapsed: true,
        config: [
            // DL_DAC12_init -> DL_DAC12_init
            // DL_DAC12_RESOLUTION
            {
                name        : "dacRes",
                displayName : "Output Resolution",
                description : 'The bit resolution.',
                hidden      : false,
                default     : "12BIT",
                options     : [
                    {name: "12BIT", displayName: "12-bit resolution"},
                    {name: "8BIT", displayName: "8-bit resolution"},
                ],
                onChange    : (inst,ui) => {
                    ui.dacOutput8.hidden = !(inst.dacRes == "8BIT")||!(inst.dacOutputPinEn);
                    ui.dacOutput12.hidden = !(inst.dacRes == "12BIT")||!(inst.dacOutputPinEn);
                },
            },
            // DL_DAC12_REPRESENTATION
            {
                name        : "dacRepresentation",
                displayName : "Input Data Format",
                description : 'The input data representation.',
                hidden      : false,
                default     : "BINARY",
                options     : [
                    {name: "BINARY", displayName: "Binary representation"},
                    {name: "TWOS_COMPLEMENT", displayName: "Two's complement representation"},
                ],
            },
            // DL_DAC12_setAmplifier
            {
                name        : "dacAmplifier",
                displayName : "DAC And Output Amplifer",
                description : 'Sets the DAC and output amplifer setting',
                hidden      : false,
                default     : "OFF_TRISTATE",
                options     : [
                    // DL_DAC12_AMP_
                    {name: "OFF_TRISTATE", displayName: "Output and Input Amplifiers off with high impedance tristate output"},
                    {name: "OFF_0V", displayName: "Output and Input Amplifiers off with 0V output"},
                    {name: "ON", displayName: "Output and Input amplifiers on"},
                ],
            },
        ]
    },
    {
        name: "GROUP_INTERRUPT",
        displayName: "Interrupt Configuration",
        longDescription: ``,
        collapsed: false,
        config: [
            // DL_DAC12_enableInterrupt
            {
                name        : "dacEnabledInterrupts",
                displayName : "Enable Interrupts",
                description : '',
                hidden      : false,
                default     : [],
                minSelections: 0,
                options     : [
                    // DL_DAC12_INTERRUPT_
                    {name: "MODULE_READY",          displayName: "Module ready event has occurred"},
                    {name: "FIFO_EMPTY",            displayName: "FIFO is empty"},
                    {name: "FIFO_THREE_QTRS_EMPTY", displayName: "FIFO is 3/4th empty"},
                    {name: "FIFO_TWO_QTRS_EMPTY",   displayName: "FIFO is 2/4ths empty"},
                    {name: "FIFO_ONE_QTR_EMPTY",    displayName: "FIFO is 1/4th empty"},
                    {name: "FIFO_FULL",             displayName: "FIFO is full"},
                    {name: "FIFO_UNDERRUN",         displayName: "FIFO is underrun (tried to read from an empty FIFO)"},
                    {name: "DMA_DONE",              displayName: "Acknowledgement to the DMA completing a transfer"},
                ],
                onChange    : (inst, ui) => {
                    ui.interruptPriority.hidden = (inst.dacEnabledInterrupts.length === 0);
                }
            },
            {
                name: "interruptPriority",
                displayName: "Interrupt Priority",
                description: "Specifies interrupt priority",
                longDescription: '',
                hidden: true,
                default: "DEFAULT",
                options: Common.InterruptPriorityOptions,
            },
        ],
    },
    {
        name: "GROUP_EVENTS",
        displayName: "Event Configuration",
        description: "",
        longDescription: "",
	    collapsed: true,
        config: [
            /* DL_DAC12_enableEvent / DL_DAC12_disableEvent */
            {
                name        : "enabledEvents",
                displayName : "Enable Publisher Events",
                description : 'Enable DAC12 event',
                hidden      : false,
                default     : [],
                minSelections: 0,
                options     : [
                    // DL_DAC12_EVENT_
                    {name: "MODULE_READY",          displayName: "Module ready event has occurred"},
                    {name: "FIFO_EMPTY",            displayName: "FIFO is empty"},
                    {name: "FIFO_THREE_QTRS_EMPTY", displayName: "FIFO is 3/4th empty"},
                    {name: "FIFO_TWO_QTRS_EMPTY",   displayName: "FIFO is 2/4ths empty"},
                    {name: "FIFO_ONE_QTR_EMPTY",    displayName: "FIFO is 1/4th empty"},
                    {name: "FIFO_FULL",             displayName: "FIFO is full"},
                    {name: "FIFO_UNDERRUN",         displayName: "FIFO is underrun (tried to read from an empty FIFO)"},
                    {name: "DMA_DONE",              displayName: "Acknowledgement to the DMA completing a transfer"},
                ],
                onChange: (inst,ui) => {
                    ui.pubChanID.hidden = !(inst.enabledEvents.length>0);
                }
            },
            /* DL_DAC12_setPublisherChanID */
            {
                name        : "pubChanID",
                displayName : "Event Publisher Channel ID",
                description : 'Sets the event publisher channel ID',
                hidden      : true,
                default: 0,
                options: EVENT.getPublisherOptions,
                getDisabledOptions: EVENT.getPublisherDisabledOptions,
            },
            /* DL_DAC12_setSubscriberChanID */
            {
                name        : "sub0ChanID",
                displayName : "Event 0 Subscriber Channel ID",
                description : 'Sets the event 0 subscriber channel ID',
                hidden      : false,
                default: 0,
                options: EVENT.getSubscriberOptions,
                getDisabledOptions: EVENT.getSubscriberDisabledOptions,
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
                    if(result.length == 0){
                        result = [""];
                    }
                    return result;
                }
            }
        ]
    },
])

/* Add Pinmux Peripheral Configuration group */
config = config.concat(Common.getGPIOGroupConfig());

function moduleInstances(inst){
    let modInstances = []
    /*
    * Gets a DMA module if available
    */
    if(inst.dacConfigureDMA){
        let mod = {
            name: "DMA_CHANNEL",
            displayName: "DMA Channel",
            moduleName: '/ti/driverlib/DMAChannel',
            group: "GROUP_DMA",
            args: {
                //triggerSelect: inst.dmaPassedSolution
            },
            requiredArgs: {
                hideTriggerSelect: true
                /* empty for now */
            },

        }
        modInstances.push(mod);
    }

    /*
     * Gets a Peripheral GPIO Configuration submodule
     */
    /* CONDITIONS CODE START */
    let OutConfig = false;
    if (inst.dacOutputPinEn == true)
    {
        OutConfig = true;
    }
    /* CONDITIONS CODE END */
    /* OUT */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   OutConfig,    "OutPin",
     "OUT", "DAC12 Output Pin",
     "OUTPUT");


    return modInstances;
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: config,

    /* override generic requirements with  device-specific reqs (if any) */
    validate: validate,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    moduleInstances: moduleInstances,

    modules: setRequiredModules,

    _getPinResources: _getPinResources
};

function setRequiredModules(inst){
    let theModules = ["Board", "SYSCTL", "EVENT"]
    if(["VEREFP"].includes(inst.dacPosVREF)||["VEREFN"].includes(inst.dacNegVREF)){
        theModules.push("VREF");
    }
    if(inst.dacConfigureDMA){
        theModules.push("DMA");
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

    return modArray
};

/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic module module to
 *  allow us to augment/override as needed for the MSP432.
 */
function extend(base)
{
    /* Special static extend */
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    /* moduleStatic specific to DAC12 as it's statically defined */
    result.config = base.moduleStatic.config.concat(devSpecific.config);
    base.moduleStatic = result;

    return (base);
}

/*
 *  ======== exports ========
 *  Export device-specific extensions to base exports
 */
exports = {
    /* required function, called by base module module */
    extend: extend
};
