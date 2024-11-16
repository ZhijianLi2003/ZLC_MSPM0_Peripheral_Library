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
 *  ======== PWMTimerMSP432.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let EVENT = system.getScript("/ti/driverlib/EVENT.syscfg.js");

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    return "";
}

const pwmFilterElementsUsed = ["deadBandEn", "ccIndex", "faultHandlerEn", "clockPrescale"];

const memoizedPWMFilter = _.memoize(curryPWMFilter,
    (inst) => JSON.stringify(_.pick(inst, pwmFilterElementsUsed)));

function curryPWMFilter(inst) {
    const args = _.pick(inst, pwmFilterElementsUsed);
    return (peripheral) => PWMFilter(peripheral, args);
}

const memoizedPWMResourceFilter = _.memoize(curryPWMResourceFilter,
    (inst) => JSON.stringify(_.pick(inst, pwmFilterElementsUsed)));

function curryPWMResourceFilter(inst) {
    const args = _.pick(inst, pwmFilterElementsUsed);
    return (_, peripheral) => PWMFilter(peripheral, args);
}

function PWMFilter(peripheral, inst) {
    let validPeripheral = true;
    let chanEnabled = [false, false, false, false];
    for (let cc of inst.ccIndex) {
        chanEnabled[cc] = true;
    }
    if(chanEnabled[2] || chanEnabled[3]) {
        validPeripheral &= /TIMA0/.test(peripheral.name);
    }

    if(Common.hasTimerA()){
        if(inst.deadBandEn) {
            validPeripheral &= /TIMA\d/.test(peripheral.name);
        }
        if(inst.faultHandlerEn) {
            validPeripheral &= /TIMA\d/.test(peripheral.name);
        }
    }
    if(inst.clockPrescale !== 1){
        // cannot be TIMG12
        validPeripheral &= !(/TIMG12\d/.test(peripheral.name));
    }

    return validPeripheral;
}

/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured PWM instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{
    let allResources = [
        {
            name: "ccp0Pin",
            displayName: "Capture/Compare Pin 0",
            interfaceNames: ["CCP0"],
        },

        {
            name: "ccp1Pin",
            displayName: "Capture/Compare Pin 1",
            interfaceNames: ["CCP1"],
        },
        {
            name: "ccp2Pin",
            displayName: "Capture/Compare Pin 2",
            interfaceNames: ["CCP2"],
        },
        {
            name: "ccp3Pin",
            displayName: "Capture/Compare Pin 3",
            interfaceNames: ["CCP3"],
        },
        {
            name: "ccp0Pin_cmpl",
            displayName: "Capture/Compare Complementary Pin 0",
            interfaceNames: ["CCP0_CMPL"],
        },
        {
            name: "ccp1Pin_cmpl",
            displayName: "Capture/Compare Complementary Pin 1",
            interfaceNames: ["CCP1_CMPL"],
        },
        {
            name: "ccp2Pin_cmpl",
            displayName: "Capture/Compare Complementary Pin 2",
            interfaceNames: ["CCP2_CMPL"],
        },
        {
            name: "ccp3Pin_cmpl",
            displayName: "Capture/Compare Complementary Pin 3",
            interfaceNames: ["CCP3_CMPL"],
        },
    ];
    let timer = {
        name: "peripheral",
        displayName: "Timer Peripheral",
        interfaceName: "GPTIMER",
        resources: [
            // start off empty to get filled-in by the table
        ],
        signalTypes: {
            ccp0Pin: ["CCP0"],
            ccp1Pin: ["CCP1"],
            ccp2Pin: ["CCP2"],
            ccp3Pin: ["CCP3"],
            ccp0Pin_cmpl: ["CCP0_CMPL"],
            ccp1Pin_cmpl: ["CCP1_CMPL"],
            ccp2Pin_cmpl: ["CCP2_CMPL"],
            ccp3Pin_cmpl: ["CCP3_CMPL"],
        },

    };

    for (let cc of inst.ccIndex) {
        timer.resources.push(allResources[cc]);
        if(Common.hasTimerA()){
            if((inst.ccIndexCmpl).includes(cc)){
                timer.resources.push(allResources[cc+4]);
            }
        }
    }

    return ([timer]);
}



/*
 *  ========= filterHardware ========
 *  Check 'component' signals for compatibility with PWM
 *
 *  param component - hardware object describing signals and
 *                    resources they're attached to
 *  returns Boolean indicating whether or not to allow the component to
 *           be assigned to an instance's $hardware config
 */
function filterHardware(component)
{
// TODO: copied this functionality from TIMER, double check proper behavior.
     let modulePin;

    for (let sig in component.signals) {
        let type = component.signals[sig].type;
        if (Common.typeMatches(type, ["TIM."])) modulePin = sig;
    }
    let result = modulePin ? true : false;

    return (result);
}

/*
 *  ======== moduleInstances ========
 *  Add individual Counter Compare settings
 */
function moduleInstances(inst) {
    let modInstances = new Array();
    let firstCollapse = false;
    // gets all numbers out of the string array
    let dutyVals = inst.dutyArgs.match(/[\d.]+/g);
    /*
    let modInst = {
        str: "PWM_CHANNELS",
        displayStr: "PWM Channels",
        description: "Channel Specific Configurables for PWM Channels",
        longDescription: `Calculates the configurables for PWM Channels and the actual duty cycle on the device. Only Counter Compare value
         or Desired Duty Cycle will need to be entered. Actual Duty Cycle is based off of the counter compare value.`,
        useArray: true, // makes a module instance adder
        defaultInstanceCount: 1,
        minInstanceCount: 0,
        maxInstanceCount: 4,
        moduleName: "/ti/driverlib/pwm/PWMTimerCC",
        hidden: false,
        args: {
            passedCount: inst.timerCount,
            passedPwmMode: inst.pwmMode
        }
    }

    if(!inst.fourChannelCapable){
        modInst.maxInstanceCount = 2;
    }
    */
    for(let i in inst.ccIndex){
        let cc = inst.ccIndex[i];
        let str = "PWM_CHANNEL_"+ cc;
        let displayStr = "PWM Channel "+ cc;
        let desc = "Channel Specific Configurables for PWM Channel "+cc;
        let longDescription = `Calculates the configurables for PWM Channel ` + cc + ` and the actual duty cycle on the device. Only Counter Compare value
            or Desired Duty Cycle will need to be entered. Actual Duty Cycle is based off of the counter compare value.`;
        let mod = {
            name: str,
            displayName: displayStr,
            description: desc,
            longDescription: longDescription,
            group: "GROUP_PWM_CONFIG",
            collapsed: firstCollapse,
            moduleName: "/ti/driverlib/pwm/PWMTimerCC",
            hidden: false,
            args: {
                passedCount: inst.timerCount,
                passedPwmMode: inst.pwmMode
            }
        };

        if(dutyVals !== null && !_.isUndefined(dutyVals[cc])) {
            // this signifies a new profile with a duty argument. Reset the
            // channel to the default state here
            let ccValue = 0;
            let dutyCycle = parseFloat(dutyVals[cc]);

            mod.args.initVal = "LOW";
            mod.args.dutyCycle = dutyCycle;
            mod.args.invert = false;
            mod.args.shadowUpdateMode = "IMMEDIATE";
        }

        modInstances.push(mod);

        firstCollapse = true; // subsequent modules are not collapsed
    }


    /*
     * Gets a Peripheral GPIO Configuration submodule
     */
    /* CONDITIONS CODE START */
    // ccp0, ccp1, ccp2, ccp3 + complementary pins
    let pwmConfig = [false, false, false, false, false, false, false, false];

    for (let cc of inst.ccIndex) {
        pwmConfig[cc] = true;
        if(Common.hasTimerA()){
            if((inst.ccIndexCmpl).includes(cc)){
                pwmConfig[cc+4] = true;
            }
        }
    }
    /* CONDITIONS CODE END */
    /* CCP0 */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   pwmConfig[0],    "ccp0Pin",
     "C0", "Capture/Compare Pin 0",
     "OUTPUT");
    /* CCP1 */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   pwmConfig[1],    "ccp1Pin",
     "C1", "Capture/Compare Pin 1",
     "OUTPUT");
    /* CCP2 */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   pwmConfig[2],    "ccp2Pin",
     "C2", "Capture/Compare Pin 2",
     "OUTPUT");
    /* CCP3 */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   pwmConfig[3],    "ccp3Pin",
     "C3", "Capture/Compare Pin 3",
     "OUTPUT");
    /* CCP0_CMPL */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   pwmConfig[4],    "ccp0Pin_cmpl",
     "C0_CMPL", "Counter/Compare Complementary Pin 0",
     "OUTPUT");
    /* CCP1_CMPL */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   pwmConfig[5],    "ccp1Pin_cmpl",
     "C1_CMPL", "Counter/Compare Complementary Pin 1",
     "OUTPUT");
    /* CCP2_CMPL */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   pwmConfig[6],    "ccp2Pin_cmpl",
     "C2_CMPL", "Counter/Compare Complementary Pin 2",
     "OUTPUT");
    /* CCP_CMPL3 */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   pwmConfig[7],    "ccp3Pin_cmpl",
     "C3_CMPL", "Counter/Compare Complementary Pin 3",
     "OUTPUT");


    return (modInstances);
}

function sharedModuleInstances(inst) {
    let modInstances = [];
    let longDescription = ``;

    if((Common.hasTimerA()) && inst.faultHandlerEn){
        let result = ["0","1","2"].some(i => (inst.faultSource).includes(i));
        if (result){
            let modInst = {
                name: "associatedFault",
                displayName: "Shared Fault Pin Configuration",
                longDescription: longDescription,
                group: "GROUP_FAULT_CONFIG",
                collapsed: false,
                moduleName: "/ti/driverlib/TIMERFault",
                hidden: false,
            };
            modInstances.push(modInst);
        }
    }

    return (modInstances);
}

/* This is a frequency changed exception dependent on if the
   frequency is changed when deadband is enabled, changing rise and fall delays */
let gClkFrequencyChanged = false;
let gClkFrequencyRevert = 0x0; /* Gives persistence to rise and fall if necessary*/
let gDeadBandRiseDelayChanged = false;
let gDeadBandFallDelayChanged = false;
/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - PWM instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{


    /* Validation of all Dynamic Enums */

    let multiDynamEnum = [
        "event1ControllerInterruptEn",
        "event2ControllerInterruptEn",
        "interrupts",
    ];
    for(let mde of multiDynamEnum){
        let validOptions = _.map(inst.$module.$configByName[mde].options(inst), "name");
        let selectedOptions = inst[mde];
        let invalidOptions = _.difference(selectedOptions, validOptions);
        if(invalidOptions.length) {
            validation.logError("Invalid Options Selected, please reselect", inst, mde);
        }
    }

    let singleSelectDynamicEnum = ["secondaryCrossTriggerSource"];
    for(let ssde of singleSelectDynamicEnum){
        let validOptions = inst.$module.$configByName[ssde].options(inst);
        let selectedOption = inst[ssde];
        let found = _.find(validOptions, (o) => o.name === selectedOption);
        if(!found){
            validation.logError("Invalid Options Selected, please reselect", inst, ssde);
        }
    }

    /* Validate the timer count based on the presence of TIMG12 */
    if(inst.peripheral === undefined){
        throw 'peripheral undefined';
    }
    let assignment = inst.peripheral.$assign;
    let chanEnabled = [false, false, false, false];
    for (let cc of inst.ccIndex) {
        chanEnabled[cc] = true;
    }


    if(Common.hasTimerA()){
        /* Dead Band Validation */
        if(inst.deadBandEn){
            if((inst.ccIndexCmpl.length == 0) || !(inst.ccIndexCmpl.some(r=> inst.ccIndex.includes(r)))){
                validation.logWarning("Dead Band configuration requires configuring a complimentary output", inst, ["ccIndexCmpl", "deadBandEn"]);
            }
            if(inst.dbInsertionMode == "Mode1" && inst.pwmMode != "CENTER_ALIGN") {
                validation.logError("Dead Band unable to use Mode 1 without Center Alignment", inst, "dbInsertionMode");
            }
        }

        /* Validate Dead band if there is a change that has occurred */

        if(gClkFrequencyChanged && inst.deadBandEn){
            if(inst.dbRiseDelayTimerCount > 0 && !gDeadBandRiseDelayChanged){
                validation.logWarning("Clock Frequency changed while dead band rise delay is enabled. The dead band rise delay should be re-examined", inst, "dbRiseDelayTimerCount");
            } else {
                gClkFrequencyRevert |= 0x01;
            }
            if(inst.dbFallDelayTimerCount > 0 && !gDeadBandFallDelayChanged){
                validation.logWarning("Clock Frequency changed while dead band fall delay is enabled. The dead band fall delay should be re-examined", inst, "dbFallDelayTimerCount");
            } else {
                gClkFrequencyRevert |= 0x10;
            }
        }

        if(gDeadBandRiseDelayChanged){
            gClkFrequencyRevert |= 0x01;
            gDeadBandRiseDelayChanged = false;
        }
        if(gDeadBandFallDelayChanged){
            gClkFrequencyRevert |= 0x10;
            gDeadBandFallDelayChanged = false;
        }
        if(gClkFrequencyRevert == 0x11){
            gClkFrequencyChanged = false;
            gClkFrequencyRevert = 0x00;
        }

        /* Fault Validation */
        if(inst.faultHandlerEn) {
            /* Fault Handler Validation */
            if(inst.faultCTEn){
                if(!inst.crossTriggerEn || !(inst.faultTriggerIn == "TFIM_ENABLED")){
                    validation.logError("Trigger Fault Input and Cross Trigger must be enabled to enable Fault Cross Trigger",inst,["faultTriggerIn","crossTriggerEn","faultCTEn"]);
                }
            }
        }
    }

    /* Make sure clocks are initialized properly */
    if(inst.inputClock_Freq == 0)
    {
        let str = "Clock Source " + inst.clockSource + " not properly initialized in SYSCTL";
        validation.logError(str, inst, "clockSource");
    }

    /* Cross Trigger Source Validation */
    if(inst.crossTriggerEn){
        if(inst.crossTriggerAuthority == "Main"){
            if(inst.mainCrossTriggerSource.includes("FSUB")){
                if (inst.mainCTSubscriberChannel == 0){
                    validation.logWarning("Selected Cross Trigger Source is not configured.", inst, "mainCTSubscriberChannel");
                }
            }
            if(!inst.timerStartTimer) {
                validation.logInfo("Note that the cross trigger will not be generated unless Start Timer is enabled.", inst, ["crossTriggerAuthority","timerStartTimer"]);
            }
        }
        else if(inst.crossTriggerAuthority == "Secondary"){
            if(inst.secondaryCrossTriggerSource.includes("SubscriberPort")){
                if (inst.secondaryCTSubscriberChannel == 0){
                    validation.logWarning("Selected Cross Trigger Source is not configured.", inst, "secondaryCTSubscriberChannel");
                }
            }
        }
    }



    /* Second Capture Compare Validation */
    if(inst.secondCompEn){
        if((inst.ccIndex.length == 0)){
            validation.logError("Cannot configure Second Capture Compare if no PWM Channels are enabled.", inst, ["ccIndex", "secondCompEn"]);
        }
        /* Validate user does not select a disabled PWM Channel for Second Compare */
        for(let pwmChannel in inst.ccIndex){
            if(inst["secondCompDirectionCH"+pwmChannel].includes("UP")){
                if( !inst.ccIndex.includes(inst["secondCompUpSourceCH"+pwmChannel]) && !(Common.isInternalTimerChannel(inst["secondCompUpSourceCH"+pwmChannel]))) {
                    validation.logError(
                        "Selected source must be an enabled PWM Channel or valid Internal Channel",
                        inst, ["secondCompUpSourceCH"+pwmChannel,"ccIndex"]
                    );
                }
            }
            if(inst["secondCompDirectionCH"+pwmChannel].includes("DOWN")){
                if( !inst.ccIndex.includes(inst["secondCompDownSourceCH"+pwmChannel]) && !(Common.isInternalTimerChannel(inst["secondCompDownSourceCH"+pwmChannel]))) {
                    validation.logError(
                        "Selected source must be an enabled PWM Channel or valid Internal Channel",
                        inst, ["secondCompDownSourceCH"+pwmChannel,"ccIndex"]
                    );
                }
            }
        }
    }

    /* Validate Event selection for case of switching devices.
     * Checks that selected event is withing the valid options
     * for current device.
     */
    EVENT.validatePublisherOptions(inst,validation,"event1PublisherChannel");
    EVENT.validatePublisherOptions(inst,validation,"event2PublisherChannel");
    if(inst.subscriberPort != "Disabled"){
        EVENT.validateSubscriberOptions(inst,validation,"subscriberChannel");
    }

    Common.validateNames(inst, validation);
}

/*
 *  ======== validatePinmux ========
 *  Validation run after solution
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validatePinmux(inst, validation) {
    /* Validation run after solution */
    let solution = inst.peripheral.$solution.peripheralName;
    if(Common.hasTimerA()){
        if(inst.enableRepeatCounter){
            if(!(/TIMA/.test(solution))){
                validation.logError("Repeat Counter only available on Timer A instances. Please select a Timer A instance from PinMux if available.",inst,"enableRepeatCounter");
            }
        }
        let hasInternal = inst.ccIndex.some(i => Common.isInternalTimerChannel(i));
        if(hasInternal && (!(/TIMA/.test(solution)))){
            validation.logError("Internal Timer Channels are only available on Timer A instances. Please select a Timer A instance from PinMux if available",inst,"ccIndex");
        }
    }
    if(Common.hasTimerA()){
        if(inst.ccIndexCmpl.length>0) {
            if(!(/TIMA\d/.test(solution))){
                validation.logError("Complementary Pins only available on Timer A instances. Please select a Timer A instance from PinMux if available", inst, "ccIndexCmpl");
            }
        }
        if(inst.deadBandEn) {
            if(!(/TIMA\d/.test(solution))){
                validation.logError("Dead Band only available on Timer A instances. Please select a Timer A instance from PinMux if available", inst, "deadBandEn");
            }
        }
        if(inst.faultHandlerEn) {
            /* Fault Handler Validation */
            if(!(/TIMA\d/.test(solution))){
                validation.logError("Fault Handler only available on Timer A instances. Please select a Timer A instance from PinMux if available.",inst,"faultHandlerEn");
            }
        }
        let chanEnabled = [false, false, false, false];
        for (let cc of inst.ccIndex) {
            chanEnabled[cc] = true;
        }
        if(chanEnabled[2] || chanEnabled[3]) {
            if(Common.isDeviceM0C()){
                if(!(/TIMA0|TIMG14/.test(solution))){
                    validation.logError("PWM Channels 2 & 3 only available on TIMA0 module. Please select a TIMA0 instance from PinMux if available.",inst,"ccIndex");
                };
            }
            else{
                if(!(/TIMA0/.test(solution))){
                    validation.logError("PWM Channels 2 & 3 only available on TIMA0 module. Please select a TIMA0 instance from PinMux if available.",inst,"ccIndex");
                };
            }
        }
    }
    /* Prescale validation */
    if(/TIMG12|TIMG13/.test(solution)){
        if(inst.clockPrescale !== 1) {
            validation.logError("Prescaler is not available for 32-bit Timers. Select a prescale value of 1, or a different peripheral in PinMux section", inst, "clockPrescale");
        }
    } else {
        if(inst.timerCount > (1 << 16) -1) {
            validation.logError("Timer Count Exceeds non-TIMG12 bounds. If a larger count is desired and TIMG12 is on the device, specify TIMG12 in PinMux", inst, "timerCount");
        }
    }

    /* Validate Timer instance supports Shadow load */
    if(inst.enableShadowLoad){

        if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
            if(!(/TIMG4/.test(solution))){
                validation.logError("Shadow Load is only supported on Timer G4 instances. Please select a Timer G4 instance from PinMux if available.",inst,"enableShadowLoad");
            }
        }
        else if (Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
            if(!(/TIMA/.test(solution)) && !(/TIMG4/.test(solution))){
                validation.logError("Shadow Load is only supported on Timer A instances and Timer G4 instances . Please select a valid Timer instance from PinMux if available.",inst,"enableShadowLoad");
            }
        }
        else if (Common.isDeviceM0G()){
            if(!(/TIMA/.test(solution)) && !(/TIMG6|7/.test(solution))){
                validation.logError("Shadow Load is only supported on Timer A instances and Timer G6-G7 instances. Please select a valid Timer instance from PinMux if available.",inst,"enableShadowLoad");
            }
        }
        else if (Common.isDeviceM0C()){
            if(!(/TIMA/.test(solution))){
                validation.logError("Shadow Load is only supported on Timer A instances. Please select a valid Timer instance from PinMux if available.",inst,"enableShadowLoad");
            }
        }
    }

    /* Validate Timer instance supports Phase load */
    if(inst.enablePhaseLoad){
        if (Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
            if(!(/TIMA/.test(solution))){
                validation.logError("Phase Load is only supported on Timer A instances. Please select a valid Timer instance from PinMux if available.",inst,"enablePhaseLoad");
            }
        }
        else if (Common.isDeviceM0G()){
            if(!(/TIMA/.test(solution))){
                validation.logError("Phase Load is only supported on Timer A instances. Please select a valid Timer instance from PinMux if available.",inst,"enablePhaseLoad");
            }
        }
        else if (Common.isDeviceM0C()){
            if(!(/TIMA/.test(solution))){
                validation.logError("Phase Load is only supported on Timer A instances. Please select a valid Timer instance from PinMux if available.",inst,"enablePhaseLoad");
            }
        }
    }

    let CCMod = system.modules["/ti/driverlib/pwm/PWMTimerCC"];
    if(CCMod){
        let CCInst = CCMod.$instances;
        for(let singleCC of CCInst){
            if(singleCC.shadowUpdateMode != "IMMEDIATE"){
                if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
                    if(!(/TIMG4/.test(solution))){
                        validation.logError("Shadow Capture Compare mode is only supported on Timer G4 instances. Please select a Timer G4 instance from PinMux if available.",singleCC,"shadowUpdateMode");
                    }
                }else if (Common.hasTimerA()){
                    if(!(/TIMA/.test(solution)) && !(/TIMG6|7/.test(solution))){
                        validation.logError("Shadow Capture Compare mode is only supported on on Timer A instances and Timer G6-G7 instances. Please select a Timer instance from PinMux if available.",singleCC,"shadowUpdateMode");
                    }
                }
            }
        }
    }

    /* Retention Validation */
    Common.getRetentionValidation(inst,validation);

    /* Internal Channel Validation */
    // CC4-5 internal channels only available for TIMA instances.
    if(Common.hasTimerA() && !(/TIMA/.test(solution))){
        // Second Capture Compare Validation
        if(inst.secondCompEn){
            /* Validate user does not select a disabled PWM Channel for Second Compare */
            for(let pwmChannel in inst.ccIndex){
                if(inst["secondCompDirectionCH"+pwmChannel].includes("UP")){
                    if(Common.isInternalTimerChannel(inst["secondCompUpSourceCH"+pwmChannel])){
                        validation.logError(
                            "Internal Channels are only available to be configured on TIMA instances.",
                            inst, ["secondCompUpSourceCH"+pwmChannel,"ccIndex"]
                        );
                    }
                }
                if(inst["secondCompDirectionCH"+pwmChannel].includes("DOWN")){
                    if(Common.isInternalTimerChannel(inst["secondCompDownSourceCH"+pwmChannel])){
                        validation.logError(
                            "Internal Channels are only available to be configured on TIMA instances.",
                            inst, ["secondCompDownSourceCH"+pwmChannel,"ccIndex"]
                        );
                    }
                }
            }
        }
        if((inst.interrupts).some(r=>(r.match("CC4|CC5")))){
            validation.logError(
                "Internal Channels are only available to be configured on TIMA instances.",
                inst, ["interrupts"]
            );
        }
        if((inst.event1PublisherChannel !== 0) && (inst.event1ControllerInterruptEn.some(r=>(r.match("CC4|CC5"))))){
            validation.logError(
                "Internal Channels are only available to be configured on TIMA instances.",
                inst, ["event1ControllerInterruptEn"]
            );
        }
        if((inst.event2PublisherChannel !== 0) && (inst.event2ControllerInterruptEn.some(r=>(r.match("CC4|CC5"))))){
            validation.logError(
                "Internal Channels are only available to be configured on TIMA instances.",
                inst, ["event2ControllerInterruptEn"]
            );
        }
    }
}

/* PROFILES */
const EmptyPWMProfile = {
    clockSource: "BUSCLK",
    clockDivider: 1,
    clockPrescale: 1,
    timerCount: 1000,
    pwmMode: "EDGE_ALIGN",
    ccIndex: [0,1],
    timerStartTimer: false,
    crossTriggerEn: false,
    crossTriggerAuthority: "Main",
    mainCrossTriggerSource: "SW",
    secondaryCrossTriggerSource: "InputTrigger_0",
    interrupts: [],
    interruptPriority: "DEFAULT",
    event1PublisherChannel: 0,
    event1ControllerInterruptEn: [],
    event2PublisherChannel: 0,
    event2ControllerInterruptEn: [],
    subscriberPort: "Disabled",
    subscriberChannel: 0,
    dutyArgs: "[0,0,0,0]"
};
const EmptyPWMProfileAdvanced = {
    deadBandEn: false,
    dbInsertionMode: "Mode0",
    dbRiseDelayTimerCount: 0,
    dbFallDelayTimerCount: 0,
    faultHandlerEn: false,
    faultSource: [],
    faultPin0Sense: "SENSE_LOW",
    faultPin1Sense: "SENSE_LOW",
    faultPin2Sense: "SENSE_LOW",
    COMP0Sense: "SENSE_LOW",
    COMP1Sense: "SENSE_LOW",
    COMP2Sense: "SENSE_LOW",
    faultInputFilterEn: false,
    faultFilterType: "CONSEC_PER",
    faultFilterSamplePeriod: "3",
    faultChannel0BehaviorEntry: "DISABLED",
    faultChannel0BehaviorExit: "DISABLED",
    faultChannel1BehaviorEntry: "DISABLED",
    faultChannel1BehaviorExit: "DISABLED",
    faultChannel2BehaviorEntry: "DISABLED",
    faultChannel2BehaviorExit: "DISABLED",
    faultChannel3BehaviorEntry: "DISABLED",
    faultChannel3BehaviorExit: "DISABLED",
    faultTriggerIn: "TFIM_DISABLED",
    faultConditionDuration: "FL_NO_LATCH",
    faultInput: "FI_INDEPENDENT",
    faultInputEn: "FIEN_DISABLED",
    faultCTEn: false,
    faultInputDetect: false,
    faultSrcClkDetect: false,
}

const EmptyPWMChannel = {
    initVal: "LOW",
    dutyCycle: 0.0,
    invert: false
};

const PWMProfiles = [
    {
        name: "basic_single_channel_center_align",
        clockPrescale: 256,
        timerCount: 100,
        pwmMode: "CENTER_ALIGN",
        ccIndex: [0],
        dutyArgs: "[50,0,0,0]"
    },
    {
        name: "basic_dual_channel_edge_align_lfclk",
        clockSource: "LFCLK",
        clockPrescale: 1,
        timerCount: 32,
        ccIndex: [0,1],
        dutyArgs: "[25,75,0,0]"
    },
    {
        name: "deadband_insertion_center_aligned",
        clockPrescale: 256,
        pwmMode: "CENTER_ALIGN",
        ccIndex: [0],
        ccIndexCmpl: [0],
        dutyArgs: "[50,0,0,0]",
        deadBandEn: true,
        dbRiseDelayTimerCount: 15
    },
];

/**********************************/
/******     ON CHANGE       *******/
/**********************************/
function onChangeEnableRepeatCounter(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
    updateGUI_RepeatCounter(inst, ui);
}

function updateGUI_RepeatCounter(inst, ui) {

    if(Common.hasTimerA()){
        ui.repeatCounter.hidden = !(inst.enableRepeatCounter);
    }
}

function onChangePWMProfile(inst, ui){
    if(inst.profile !== "CUSTOM") {

        inst.ccIndex = []; // force to re-run moduleInstances and pass args
        let selectedProfile = _.filter(PWMProfiles, ['name', inst.profile])[0];
        if(selectedProfile === undefined) throw 'bad profiles';
        Object.assign(inst, EmptyPWMProfile,
            _.pickBy(selectedProfile, (_,key) => key !== 'name'));

        if(Common.hasTimerA()){
            Object.assign(inst, EmptyPWMProfileAdvanced,
                _.pickBy(selectedProfile, (_,key) => key !== 'name'));
        }
        // reset global validation variables
        gClkFrequencyChanged = false;
        gClkFrequencyRevert = 0x0; /* Gives persistence to rise and fall if necessary*/
        gDeadBandRiseDelayChanged = false;
        gDeadBandFallDelayChanged = false;

        updateGUI_Profile(inst, ui);
    }
}

function onChangeCCIndex(inst,ui){
    /* Fails sanity Tests :/
    let dutyVals = inst.dutyArgs.match(/\d+/g);
    let dutyValNums = [];
    _.forEach(dutyVals, (a) => dutyValNums.push(parseInt(a)));

    for(let i = 0; i < 4; i++) {
        if(!inst.ccIndex.includes(i)){
            // zeroize the appropriate duty arg
            dutyValNums[i] = 0;
        }
    }
    inst.dutyArgs = JSON.stringify(dutyValNums);
    */
    onChangeResetProfile(inst, ui);
    updateGUI_FaultHandler(inst,ui);
    updateGUI_SecondCompare(inst, ui);
}

function onChangeResetProfile(inst, ui) {
    inst.profile = "CUSTOM";

}

function updateGUI_Profile(inst, ui) {
    updateGUI_PWMMode(inst, ui);
    updateGUI_FaultHandler(inst, ui);
    updateGUI_DeadBand(inst, ui);
    updateGUI_CrossTrigger(inst, ui);
    updateGUI_Interrupts(inst, ui);
}

function onChangeEnableShadowLoad(inst,ui)
{
    onChangeResetProfile(inst, ui);
}

/*  ======== onChange handlers ======== */
function onChangeEnablePhaseLoad(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
    if(inst.enablePhaseLoad)
        ui.phaseLoadValue.hidden = false;
    else
        ui.phaseLoadValue.hidden = true;
}

function onChangeCrossTrigger(inst, ui){
    onChangeResetProfile(inst, ui);
    updateGUI_CrossTrigger(inst, ui);
}

function updateGUI_CrossTrigger(inst, ui) {
    if(!inst.crossTriggerEn){
        ui.crossTriggerAuthority.hidden = true;
        ui.mainCrossTriggerSource.hidden = true;
        ui.mainCTSubscriberChannel.hidden = true;
        ui.secondaryCrossTriggerSource.hidden = true;
        ui.secondaryCTSubscriberChannel.hidden = true;
    } else {
        ui.crossTriggerAuthority.hidden = false;
        if(inst.crossTriggerAuthority == "Main") {
            ui.mainCrossTriggerSource.hidden = false;
            ui.mainCTSubscriberChannel.hidden = !inst.mainCrossTriggerSource.includes("FSUB");
        } else {
            ui.mainCrossTriggerSource.hidden = true;
            ui.mainCTSubscriberChannel.hidden = true;
        }
        if(inst.crossTriggerAuthority == "Secondary") {
            ui.secondaryCrossTriggerSource.hidden = false;
            ui.secondaryCTSubscriberChannel.hidden = !inst.secondaryCrossTriggerSource.includes("SubscriberPort");
        } else {
            ui.secondaryCrossTriggerSource.hidden = true;
            ui.secondaryCTSubscriberChannel.hidden = true;
        }
    }
}

function onChangeFaultHandler(inst, ui){
    onChangeResetProfile(inst, ui);
    updateGUI_FaultHandler(inst, ui);
}

function updateGUI_FaultHandler(inst, ui) {

    if(Common.hasTimerA()){
        let hide = [true, true, true, true, true, true];
        ui.faultSource.hidden = !inst.faultHandlerEn;
        ui.faultInputFilterEn.hidden = !inst.faultHandlerEn;
        ui.faultFilterType.hidden = !(inst.faultInputFilterEn && inst.faultHandlerEn);
        ui.faultFilterSamplePeriod.hidden = !(inst.faultInputFilterEn && inst.faultHandlerEn);
        if(inst.faultHandlerEn){
            for(let pin of inst.faultSource){
                if(pin != ""){
                    hide[parseInt(pin)] = false;
                }
            }
        }
        ui.faultPin0Sense.hidden = hide[0];
        ui.faultPin1Sense.hidden = hide[1];
        ui.faultPin2Sense.hidden = hide[2];
        ui.COMP0Sense.hidden = hide[3];
        ui.COMP1Sense.hidden = hide[4];
        ui.COMP2Sense.hidden = hide[5];


        /* for channel behaviors */
        let chanHide = [true, true, true, true];
        let ind;
        if(inst.faultHandlerEn){
            for (let cc of inst.ccIndex) {
                chanHide[cc] = false;
            }
        }
        ui.faultChannel0BehaviorEntry.hidden = chanHide[0];
        ui.faultChannel0BehaviorExit.hidden = chanHide[0];
        ui.faultChannel1BehaviorEntry.hidden = chanHide[1];
        ui.faultChannel1BehaviorExit.hidden = chanHide[1];
        ui.faultChannel2BehaviorEntry.hidden = chanHide[2];
        ui.faultChannel2BehaviorExit.hidden = chanHide[2];
        ui.faultChannel3BehaviorEntry.hidden = chanHide[3];
        ui.faultChannel3BehaviorExit.hidden = chanHide[3];

        ui.faultTriggerIn.hidden = !inst.faultHandlerEn;
        ui.faultConditionDuration.hidden = !inst.faultHandlerEn;
        ui.faultInput.hidden = !inst.faultHandlerEn;
        ui.faultInputEn.hidden = !inst.faultHandlerEn;
        ui.faultTimerCountEntry.hidden = !inst.faultHandlerEn;
        ui.faultTimerCountExit.hidden = !inst.faultHandlerEn;
        ui.faultCTEn.hidden = !inst.faultHandlerEn;
        ui.faultInputDetect.hidden = !inst.faultHandlerEn;
        ui.faultSrcClkDetect.hidden = !inst.faultHandlerEn;
    };
}

function updateGUI_SecondCompare(inst, ui){
    for(let pwmChannel of ccIndexOptions){
        let channelEnabled = inst.ccIndex.includes(pwmChannel.name);
        let upCountingEn = (inst["secondCompDirectionCH"+pwmChannel.name.toString()]).includes("UP");
        let downCountingEn = (inst["secondCompDirectionCH"+pwmChannel.name.toString()]).includes("DOWN");

        ui["secondCompDirectionCH"+pwmChannel.name.toString()].hidden = !channelEnabled || !inst.secondCompEn;
        ui["secondCompUpSourceCH"+pwmChannel.name.toString()].hidden =  !channelEnabled || !upCountingEn || !inst.secondCompEn;
        ui["secondCompUpActionCH"+pwmChannel.name.toString()].hidden =  !channelEnabled || !upCountingEn || !inst.secondCompEn;
        ui["secondCompDownSourceCH"+pwmChannel.name.toString()].hidden =   !channelEnabled || !downCountingEn || !inst.secondCompEn;
        ui["secondCompDownActionCH"+pwmChannel.name.toString()].hidden =   !channelEnabled || !downCountingEn || !inst.secondCompEn;
    }
};

function updateGUI_PWMMode(inst, ui){
    ui.counterZero.hidden = !(inst.pwmMode == "CENTER_ALIGN");
    ui.counterLoad.hidden = !((inst.pwmMode == "EDGE_ALIGN") || (inst.pwmMode == "EDGE_ALIGN_UP"));
}

function updateGUI_Interrupts(inst, ui){
    ui.interruptPriority.hidden = (inst.interrupts.length === 0);
}

function onChangeDeadBand(inst, ui){
    onChangeResetProfile(inst, ui);
    updateGUI_DeadBand(inst, ui);
}

function updateGUI_DeadBand(inst, ui) {

    if(Common.hasTimerA()){
        let hide = !inst.deadBandEn;
        ui.dbInsertionMode.hidden = hide;
        ui.dbRiseDelayTimerCount.hidden = hide;
        ui.dbCalculatedRiseDelay.hidden = hide;
        ui.dbFallDelayTimerCount.hidden = hide;
        ui.dbCalculatedFallDelay.hidden = hide;
    }
}

function onChangeCLK(inst, ui) {
    gClkFrequencyChanged = true; // useful for validation
    onChangeResetProfile(inst, ui);
}

/**********************************/
/******       OPTIONS       *******/
/**********************************/

const BehaviorOptions = [
        {name: "DISABLED", displayName: "Not affected"},
        {name: "HIGH", displayName: "Set high"},
        {name: "LOW", displayName: "Set low"},
        {name: "TOGGLE", displayName: "Toggled"},
        {name: "HIGHZ", displayName: "High-Z"},
];

let allEventOptions = [
    { name: "ZERO_EVENT", displayName: "Zero event", description: "PWM Timer reaches zero" },
    { name: "LOAD_EVENT", displayName: "Load event", description: "PWM Timer loads Timer Count Value" },
    { name: "FAULT_EVENT", displayName: "Fault event", reason: "Fault not Capable" },
    { name: "OVERFLOW_EVENT", displayName: "Overflow event" },
    { name: "CC0_DN_EVENT", displayName: "Channel 0 capture or compare down event", reason: "Channel Not In Use" },
    { name: "CC0_UP_EVENT", displayName: "Channel 0 capture or compare up event", reason: "Channel Not In Use" },
    { name: "CC1_DN_EVENT", displayName: "Channel 1 capture or compare down event", reason: "Channel Not In Use" },
    { name: "CC1_UP_EVENT", displayName: "Channel 1 capture or compare up event", reason: "Channel Not In Use" },
    { name: "CC2_DN_EVENT", displayName: "Channel 2 capture or compare down event", reason: "Channel Not In Use" },
    { name: "CC2_UP_EVENT", displayName: "Channel 2 capture or compare up event", reason: "Channel Not In Use" },
    { name: "CC3_DN_EVENT", displayName: "Channel 3 capture or compare down event", reason: "Channel Not In Use" },
    { name: "CC3_UP_EVENT", displayName: "Channel 3 capture or compare up event", reason: "Channel Not In Use" },
    { name: "CC4_DN_EVENT", displayName: "Channel 4 capture or compare down event", reason: "Channel Not In Use" },
    { name: "CC4_UP_EVENT", displayName: "Channel 4 capture or compare up event", reason: "Channel Not In Use" },
    { name: "CC5_DN_EVENT", displayName: "Channel 5 capture or compare down event", reason: "Channel Not In Use" },
    { name: "CC5_UP_EVENT", displayName: "Channel 5 capture or compare up event", reason: "Channel Not In Use" },
];

function getTimerClockSourceFreq(inst) {
    let timerClockFreq = 0;
   switch (inst.clockSource){
       case "BUSCLK":
            timerClockFreq = Common.getBUSCLKFreq(inst, "GPTIMER");
        break;
        case "MFCLK":
            timerClockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.MFCLK_Freq;
        break;
        case "LFCLK":
            timerClockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq;
        break;
   }
   timerClockFreq = timerClockFreq / inst.clockDivider;

   return timerClockFreq;
}

function getEventOptions(inst)
{
    let options = [];
    //let pubs = system.modules["/ti/driverlib/EVENT"].$static.channel2Pub;
    for(let option of allEventOptions){
        options.push({name: option["name"], displayName: option["displayName"]});
    }

    if(!inst.fourChannelCapable) {
        options = options.filter( (el) => !el.name.match("CC2|3") );
        if(!inst.timerACapable) {
             options.splice(2,1); // remove fault
        }
    }
    if(!Common.hasTimerA()) {
        options = options.filter( (el) => !el.name.match("CC4|5") );
    }
    return options;
}

function getDisabledEvents(inst)
{
    let allOptions = allEventOptions;

    if(!inst.fourChannelCapable) {
        allOptions = _.filter( allOptions, (el) => !el.name.match("CC2|3") );
    }

    let channels = [0,1,2,3];
    for (let cc of inst.ccIndex) {
        // remove the channels that are active, since these are not disabled
        channels.splice(channels.indexOf(cc),1);
    }

    var str = "CC"
    if(channels.length != 0) {
        for (let chan of channels){
            str += chan + '|';
        }
        // remove last '|' before matching
        return allOptions.filter( (el) => el.name.match(str.slice(0,-1)) );
    }
    return [];
}

function getDisabledCCIndexCmplOptions(inst)
{
    let disabledOptions = [];
    for (let ccOption in ccIndexOptions){
        if(!(inst.ccIndex.toString()).includes(ccOption)){
            let currentCC = ccIndexOptions[ccOption];
            disabledOptions.push({name: currentCC.name, displayName: currentCC.displayName,  reason: "channel not enabled"});
        }
    }
    return disabledOptions;
}

function optionsGetCrossTriggerTimerInstances(inst, template) {
    let allTimers = [];
    let name_template = template+"_";
    let displayName_template = template + " ";
    for(let j = 0; j < 16; j++){
        allTimers.push({name: name_template + j, displayName: displayName_template + j});
    }
    return allTimers;
}

function onChangeSetCustomProfile(inst, ui) {
    inst.profile = "CUSTOM";
}

/* Retention configurable */
let retentionConfig = [];
if(Common.isDeviceM0G()){
    retentionConfig = retentionConfig.concat(
        {
            name        : "enableRetention",
            default     : false,
            hidden      : true,
            getValue: (inst) => {
                let solution = false;
                try{
                    solution = (/TIMA|TIMG6|TIMG7/.test(inst.peripheral.$solution.peripheralName));
                }catch (e) {
                    // do nothing
                }
                return solution;
            }
        },
        {
            name        : "enableRetentionUI",
            displayName : "Low-Power Register Retention",
            default     : "",
            longDescription: `
Some MSPM0G peripherals residing in PD1 domain do not retain register contents when
entering STOP or STANDBY modes. Please view the datasheet for more details.\n
Developers can decide to re-initialize the peripheral using the default
initialization from SysConfig in their application. This approach is more
memory-efficient.\n
Alternatively, the user may also call the provided DriverLib APIs to save and
restore the register configuration of the peripheral before and after entering
low-power mode. This approach is recommended if the peripheral configuration is
modified at runtime.
            `,
            getValue: (inst) => {
                let solution = false;
                try{
                    solution = (/TIMA|TIMG6|TIMG7/.test(inst.peripheral.$solution.peripheralName)) && !(/SLEEP/.test(system.modules["/ti/driverlib/SYSCTL"].$static.powerPolicy));
                }catch (e) {
                    // do nothing
                }
                return (solution?"Registers not retained":"Registers retained");
            }
        },
        {
            name        : "overrideRetention",
            displayName : "Disable Retention APIs",
            longDescription: `
When selected, the retention APIs will not be generated regardless of selected peripheral.`,
            default     : false,
            hidden      : false,
            onChange    : (inst,ui) =>{
                ui.retentionRestoreCnt.hidden = inst.overrideRetention;
            }
        },
        {
            name            : "retentionRestoreCnt",
            displayName     : "Restore Counter",
            longDescription : `If selected timer counter value is also restored
            (e.g. resume counts of edge counts). Otherwise, timer counter is not restored.`,
            default         : false,
            hidden          : false,

        },
    );
}

let configAdvanced = [
    {
        name            : "enableShadowLoad",
        displayName     : "Enable Shadow Load",
        description     : "Enables Shadow Load",
        longDescription : `Enables shadow load feature. Only supported in TIMAx and TIMG4-TIMG7 instances.
        \n When enabled updates to the timer's LOAD register are synchronized with the timer's ZERO event`,
        default         : false,
        onChange        : onChangeEnableShadowLoad
    },
    {
        name            : "enablePhaseLoad",
        displayName     : "Enable Phase Load",
        description     : "Enables Phase Load",
        longDescription : `In TIMA only, phase load provides the capability count from a value other
        \nthan zero or TIMA.LOAD in Up/Down counting mode.`,
        default         : false,
        onChange        : onChangeEnablePhaseLoad
    },
    {
        name            : "phaseLoadValue",
        displayName     : "Phase Load Value",
        description     : "Sets the value for Phase Load",
        hidden          : true,
        default         : 0,
        range           : [0, 0xFFFF],
    }
]

if(Common.hasTimerA()){
configAdvanced.push(
    {
        name            : "enableRepeatCounter",
        displayName     : "Enable Repeat Counter",
        description     : "Enable Repeat Counter",
        longDescription : `Enables repeat counter feature. Only supported in TIMA0`,
        default         : false,
        onChange        : onChangeEnableRepeatCounter
    },
    {
        name           : "repeatCounter",
        displayName    : "Times to Repeat Counter",
        description    : "Timer to Repeat Counter",
        longDescription: `Specifies number of timer reloads events before
        triggering repeat counter interrupt.`,
        default        : 1,
        hidden         : true,
        options        : [
            { name: 1, displayName: "1" },
            { name: 2, displayName: "2" },
            { name: 3, displayName: "3" },
            { name: 4, displayName: "4" },
        ],
        onChange       : onChangeSetCustomProfile
    },
);
};

/* Advance Config: Cross Trigger options */
configAdvanced.push(
    {
        name: "crossTriggerEn",
        displayName: "Enable Cross Trigger",
        description: "Enable the ability to have this GP timer trigger or be triggered by another module or hardware element",
        longDescription: `The cross trigger feature can be used to trigger more than one timer module to start counting simultaneously`,
        default: false,
        onChange: onChangeCrossTrigger
    },
    {
        name: "crossTriggerAuthority",
        displayName: "Cross Trigger Configuration",
        description: "Determines Cross Trigger Function",
        longDescription: `Determines if the timer will Trigger other modules and/or be triggered by other modules.`,
        default: "Main",
        hidden: true,
        options: [
            {name: "Main"},
            {name: "Secondary"},
        ],
        onChange: onChangeCrossTrigger
    },
    {
        name: "mainCrossTriggerConfig",
        displayName: "Main Cross Trigger Configuration",
        longDescription: `Enable this timer module to trigger other timer modules to start simultaneously`,
        collapsed: false,
        config: [
            {
                name: "mainCrossTriggerSource",
                displayName: "Cross Trigger Source",
                description: "Determines what will cause the Main to Trigger",
                longDescription: `The Main Cross Trigger Source causes the Main to send out the
                Cross Trigger Signal to whichever timers are configured in the Timer Instances Controlled.
                \n Software Describes a cause that is linked to the code and writing to a register
                \n Subscriber Ports would be used in the case of an event on a specific channel.`,
                hidden: true,
                default: "SW",
                options: [
                    {name: "SW", displayName: "Software"},
                    {name: "FSUB0", displayName: "Subscriber Port 0"},
                    {name: "FSUB1", displayName: "Subscriber Port 1"},
                    {name: "ZERO", displayName: "Zero"},
                    {name: "LOAD", displayName: "Load"},
                    {name: "CCD0", displayName: "Capture Compare Down 0 event"},
                    {name: "CCD1", displayName: "Capture Compare Down 1 event"},
                    {name: "CCD2", displayName: "Capture Compare Down 2 event"},
                    {name: "CCD3", displayName: "Capture Compare Down 3 event"},
                    {name: "CCU0", displayName: "Capture Compare Up 0 event"},
                    {name: "CCU1", displayName: "Capture Compare Up 1 event"},
                    {name: "CCU2", displayName: "Capture Compare Up 2 event"},
                    {name: "CCU3", displayName: "Capture Compare Up 3 event"},
                ],
                onChange: onChangeCrossTrigger,
            },
            {
                name: "mainCTSubscriberChannel",
                displayName: "Subscriber Channel ID",
                description: "Corresponding Channel of The Subscriber Port",
                longDescription: `Corresponding Channel on the Subscriber Port that's used to cause the
                triggering of secondary timer modules controlled by this module.`,
                hidden: true,
                default: 0,
                options: [
                    { name: 0 , displayName: "Disabled (0)"}, { name: 1 }, {name: 2 }, {name: 3 }, {name: 4 }, {name: 5 },
                    {name: 6 }, {name: 7 }, {name: 8 }, {name: 9 }, {name: 10 },
                    {name: 11 }, {name: 12 }, {name: 13 }, {name: 14 }, {name: 15}
                ],
                getValue: (inst) => {
                    if(inst.mainCrossTriggerSource == inst.subscriberPort){
                        return inst.subscriberChannel;
                    }
                    else{
                        return 0;
                    }
                }
            },
        ]

    },
    {
        name: "secondaryCrossTriggerConfig",
        displayName: "Secondary Cross Trigger Configuration",
        longDescription: `Enable this module to be triggered by other timer modules`,
        collapsed: false,
        config: [
            {
                name: "secondaryCrossTriggerSource",
                displayName: "Cross Trigger Input Source",
                description: "Input from a main cross trigger that will start this timer",
                longDescription: `This will start this module timer from a specific input source. If a Timer is chosen,
                that corresponding timer will need to be enabled as a main cross trigger. Additionally, the
                specific wiring of physical timer instance to timer input (e.g. TimerG0 -> Timer1) is device
                dependent and can be verified in the datasheet.`,
                hidden: true,
                default: "InputTrigger_0",
                options: (inst) => {
                    let other = [
                        {name: "SubscriberPort0"},
                        {name: "SubscriberPort1"}
                    ];
                    let validTimers = optionsGetCrossTriggerTimerInstances(inst, "InputTrigger");
                    return validTimers.concat(other);
                },
                onChange: onChangeCrossTrigger,
            },
            {
                name: "secondaryCTSubscriberChannel",
                displayName: "Subscriber Channel ID",
                description: "Corresponding Channel of The Subscriber Port",
                longDescription: `Corresponding Channel on the Subscriber Port that's used
                to trigger the start of this timer module`,
                hidden: true,
                default: 1,
                options: [
                    { name: 0, displayName: "Disabled (0)" }, { name: 1 },  { name: 2 },  { name: 3 },  { name: 4 },  { name: 5 },
                    { name: 6 },  { name: 7 },  { name: 8 },  { name: 9 },  { name: 10 },
                    { name: 11 }, { name: 12 }, { name: 13 }, { name: 14 }, { name: 15}
                ],
                getValue: (inst) => {
                    if(inst.secondaryCrossTriggerSource == "SubscriberPort0" && inst.subscriberPort == "FSUB0"){
                        return inst.subscriberChannel;
                    }
                    if(inst.secondaryCrossTriggerSource == "SubscriberPort1" && inst.subscriberPort == "FSUB1"){
                        return inst.subscriberChannel;
                    }
                    else{
                        return 0;
                    }
                }
            },
        ]
    },
)

/*
 * MSPM0G Series-Specific Option:
 * Dead Band & Fault Handler options only available for TIMA, which is not available
 * for MSPM0L
 */
if(Common.hasTimerA()){
    /* Advance Config: Dead Band options */
    configAdvanced.push(
        {
            name: "deadBandEn",
            displayName: "Enable Dead Band Insertion",
            description: "Enables Dead Band Insertion between PWM Channel and its complementary PWM channel",
            longDescription: `Enables Dead Band Insertion. Note: PWM Channel and its complementary PWM channel must both be enabled for this functionality.
            Only TIMA instance supports dead band`,
            default: false,
            onChange: onChangeDeadBand
        },
        {
            name: "deadBandConfig",
            displayName: "Complementary PWM with Dead Band Insertion",
            longDescription: `The specific configurables within dead band include the channel select
            and rise and fall delay to create deadband between complementary PWM Channels`,
            collapsed: false,
            config: [
                {
                    name: "dbInsertionMode",
                    displayName: "Insertion Mode",
                    description: "Dead Band Insertion Mode. Mode 1 only valid when center-aligned",
                    longDescription: `The Dead Band Insertion Mode. Controls how the rising and falling edges behave.
                    \n Mode 0: Available in either setting. The Rise delay affects the rise of the first channel after a load event
                            (second channel always falls on the load event).
                            The Fall delay affects the rise of the second channel after the comparison event
                            (first channel always falls on comparison event).
                    \n Mode 1: Available only when center aligned. The first signal rises and falls at the comparison event.
                            The Rise delay dictates how early the second channel will fall before the first channel rises.
                            The Fall delay dictates how late the second channel will rise after the first channel falls.`,
                    hidden: true,
                    default: "Mode0",
                    options: [
                        {name: "Mode0", displayName: "Mode 0"},
                        {name: "Mode1", displayName: "Mode 1"}
                    ],
                    getDisabledOptions: (inst) => {
                        if(inst.pwmMode != "CENTER_ALIGN"){
                            return [{name: "Mode1", displayName: "Mode 1", reason: "Mode 1 only valid with center-alignment"}];
                        }
                        return [];
                    },
                    onChange: onChangeResetProfile
                },
                {
                    name: "dbRiseDelayTimerCount",
                    displayName: "Rise Delay Timer Counts",
                    description: "Optional delay based on the rising edge of the first channel",
                    longDescription: `Mode 0: The Rise delay affects the rise of the first channel after a load event
                    (second channel always falls on the load event).
                    Mode 1: The Rise delay dictates how early the second channel will fall before the first channel rises.
                    \nCalculation Rise Delay = Timer Counts / Timer Clock Frequency`,
                    hidden: true,
                    default: 0,
                    range: [0,4095],
                    onChange: (inst, ui) => {
                        gDeadBandRiseDelayChanged = true;
                        onChangeResetProfile(inst, ui);
                    }
                },
                {
                    name: "dbCalculatedRiseDelay",
                    displayName: "Calculated Rise Delay",
                    hidden: true,
                    default: "0 s",
                    getValue: (inst) => {
                        if(inst.timerClk_Freq != 0){
                            let delay = Common.getUnitPrefix(inst.dbRiseDelayTimerCount / inst.timerClk_Freq);
                            return delay.str + "s";
                        } else {
                            return "0 s"
                        }
                    }
                },
                {
                    name: "dbFallDelayTimerCount",
                    displayName: "Fall Delay Timer Counts",
                    description: "Optional delay based on the falling edge of the first signal",
                    longDescription: `Mode 0: The Fall delay affects the rise of the second channel after the comparison event
                    (first channel always falls on comparison event).
                    Mode 1: The Fall delay dictates how late the second channel will rise after the first channel falls
                    \nCalculation Fall Delay = Timer Counts / Timer Clock Frequency`,
                    hidden: true,
                    default: 0,
                    range: [0,4095],
                    onChange: (inst,ui) => {
                        gDeadBandFallDelayChanged = true;
                        onChangeResetProfile(inst, ui);
                    }
                },
                {
                    name: "dbCalculatedFallDelay",
                    displayName: "Calculated Fall Delay",
                    hidden: true,
                    default: "0",
                    getValue: (inst) => {
                        if(inst.timerClk_Freq != 0){
                            let delay = Common.getUnitPrefix(inst.dbFallDelayTimerCount / inst.timerClk_Freq);
                            return delay.str + "s";
                        } else {
                            return "0 s"
                        }
                    }
                }
            ]
        },
    );
    /* Advance Config: Fault Handler options */
    configAdvanced.push(
        {
            name: "faultHandlerEn",
            displayName: "Enable Fault Handler",
            description: "Enables handling of external fault events",
            longDescription: `Enables handling of external fault events. Faults can be filtered
            and detected in several ways and the timers output can be configured to a known value`,
            default: false,
            onChange: onChangeFaultHandler
        },
        {
            name: "faultHandlerConfig",
            displayName: "Fault Handler Configuration",
            collapsed: false,
            config: [
                {
                    name: "faultSource",
                    displayName: "Fault Source",
                    description: "Fault Sources that can trigger a fault on the device",
                    longDescription: `Determine the fault sources that are applicable to this instance and
                    can trigger a fault condition.`,
                    hidden: true,
                    default: [],
                    minSelections: 0,
                    options: [
                            {name: "0", displayName: "FaultPin0"},
                            {name: "1", displayName: "FaultPin1"},
                            {name: "2", displayName: "FaultPin2"},
                            {name: "3", displayName: "COMP0"},
                            {name: "4", displayName: "COMP1"},
                            {name: "5", displayName: "COMP2"},
                    ],
                    onChange: onChangeFaultHandler
                },
                {
                    name: "faultPin0Sense",
                    displayName: "Fault Pin 0 Sense",
                    description: "Determines what level will trigger a fault",
                    longDescription: `Determines what level of the input will trigger a fault condition.`,
                    hidden: true,
                    default: "SENSE_LOW",
                    options: [{name: "SENSE_LOW", displayName: "Active Low"},
                            {name: "SENSE_HIGH", displayName: "Active High"}],
                    onChange: onChangeResetProfile
                },
                {
                    name: "faultPin1Sense",
                    displayName: "Fault Pin 1 Sense",
                    description: "Determines what level will trigger a fault",
                    longDescription: `Determines what level of the input will trigger a fault condition.`,
                    hidden: true,
                    default: "SENSE_LOW",
                    options: [{name: "SENSE_LOW", displayName: "Active Low"},
                            {name: "SENSE_HIGH", displayName: "Active High"}],
                    onChange: onChangeResetProfile
                },
                {
                    name: "faultPin2Sense",
                    displayName: "Fault Pin 2 Sense",
                    description: "Determines what level will trigger a fault",
                    longDescription: `Determines what level of the input will trigger a fault condition.`,
                    hidden: true,
                    default: "SENSE_LOW",
                    options: [{name: "SENSE_LOW", displayName: "Active Low"},
                            {name: "SENSE_HIGH", displayName: "Active High"}],
                    onChange: onChangeResetProfile
                },
                {
                    name: "COMP0Sense",
                    displayName: "COMP 0 Sense",
                    hidden: true,
                    description: "Determines what level will trigger a fault",
                    longDescription: `Determines what level of the input will trigger a fault condition.`,
                    hidden: true,
                    default: "SENSE_LOW",
                    options: [{name: "SENSE_LOW", displayName: "Active Low"},
                            {name: "SENSE_HIGH", displayName: "Active High"}],
                    onChange: onChangeResetProfile
                },
                {
                    name: "COMP1Sense",
                    displayName: "COMP 1 Sense",
                    hidden: true,
                    description: "Determines what level will trigger a fault",
                    longDescription: `Determines what level of the input will trigger a fault condition.`,
                    hidden: true,
                    default: "SENSE_LOW",
                    options: [{name: "SENSE_LOW", displayName: "Active Low"},
                            {name: "SENSE_HIGH", displayName: "Active High"}],
                    onChange: onChangeResetProfile
                },
                {
                    name: "COMP2Sense",
                    displayName: "COMP 2 Sense",
                    hidden: true,
                    description: "Determines what level will trigger a fault",
                    longDescription: `Determines what level of the input will trigger a fault condition.`,
                    hidden: true,
                    default: "SENSE_LOW",
                    options: [{name: "SENSE_LOW", displayName: "Active Low"},
                            {name: "SENSE_HIGH", displayName: "Active High"}],
                    onChange: onChangeResetProfile
                },
                {
                    name: "GROUP_FAULT_CONFIG",
                    displayName: "Fault Configuration",
                    description: "",
                    longDescription: "",
                    collapsed: false,
                    config: [
                        /* DL_TIMER_FAULT_CONFIG_TFIM */
                        {
                            name        : "faultTriggerIn",
                            displayName : "Trigger Fault Input",
                            description : '',
                            hidden      : true,
                            default     : "TFIM_DISABLED",
                            options     : [
                                {name: "TFIM_DISABLED", displayName: "Selected trigger doesn't participate as a fault input."},
                                {name: "TFIM_ENABLED", displayName: "Selected trigger participates as a fault input."},
                            ],
                            onChange: onChangeResetProfile
                        },
                        /* DL_TIMER_FAULT_CONFIG_FL */
                        {
                            name: "faultConditionDuration",
                            displayName: "Fault Latch Mode",
                            description: "Duration of the Fault Condition before normal operation is resumed",
                            longDescription: `Duration Types that are supported:
                            \n Input Duration: The fault lasts the period of time from fault assertion to de-assertion (post Filter if enabled).
                            \n Latched, Software Clear: The fault lasts as long as the period of time that TIMx.RIS.F is set. This bit is cleared by software, presumably
                            after dealing with the external condition
                            \n Latched, Zero Event Clear: Fault condition is cleared on a zero event if the fault input is 0
                            \n Latched, Load Clear: Fault condition is cleared on a load event if the fault input is 0
                            `,
                            hidden: true,
                            default: "FL_NO_LATCH",
                            options: [
                                {name: "FL_NO_LATCH", displayName: "Input Duration"},
                                {name: "FL_LATCH_SW_CLR", displayName: "Latched to TIMx.RIS.F, Software Clear"},
                                {name: "FL_LATCH_Z_CLR", displayName: "Latched to TIMx.RIS.F, Zero Event Clear"},
                                {name: "FL_LATCH_LD_CLR", displayName: "Latched to TIMx.RIS.F, Load Clear"},
                            ],
                            onChange: onChangeResetProfile
                        },
                        /* DL_TIMER_FAULT_CONFIG_FI */
                        {
                            name        : "faultInput",
                            displayName : "Fault Input Condition",
                            description : '',
                            hidden      : true,
                            default     : "FI_INDEPENDENT",
                            options     : [
                                {name: "FI_INDEPENDENT", displayName: "Fault condition is independent on all selected fault sources coming into the Timer"},
                                {name: "FI_DEPENDENT", displayName: "Fault condition is dependent on all selected fault sources coming into the Timer"},
                            ],
                            onChange: onChangeResetProfile
                        },
                        /* DL_TIMER_FAULT_CONFIG_FIEN */
                        {
                            name        : "faultInputEn",
                            displayName : "Fault Input Enable",
                            description : '',
                            hidden      : true,
                            default     : "FIEN_DISABLED",
                            options     : [
                                {name: "FIEN_DISABLED", displayName: "Disables the input for fault detection from the device pin."},
                                {name: "FIEN_ENABLED", displayName: "Enables the input for fault detection from the device pin."},
                            ],
                            onChange: onChangeResetProfile
                        },
                        /* DL_TIMER_FAULT_ENTRY_CTR */
                        {
                            name        : "faultTimerCountEntry",
                            displayName : "Timer Counter Fault Entry Behavior",
                            description : 'Timer counter behavior when entering fault state',
                            hidden      : true,
                            default     : "FAULT_ENTRY_CTR_CONT_COUNT",
                            options     : [
                                {name: "FAULT_ENTRY_CTR_CONT_COUNT", displayName: "Timer counter continues running during fault"},
                                {name: "FAULT_ENTRY_CTR_SUSP_COUNT", displayName: "Timer counter is suspended during fault"},

                            ],
                            onChange    : onChangeResetProfile
                        },
                        /* DL_TIMER_FAULT_EXIT_CTR_RESUME */
                        {
                            name        : "faultTimerCountExit",
                            displayName : "Timer Counter Fault Exit Behavior",
                            description : 'Timer counter behavior when exiting fault state',
                            hidden      : true,
                            default     : "FAULT_EXIT_CTR_RESUME",
                            options     : [
                                {name: "FAULT_EXIT_CTR_RESUME", displayName: "Timer counter resume counting"},
                                {name: "FAULT_EXIT_CTR_CVAE_ACTION", displayName: "Timer counter is set to the period value"},
                            ],
                            onChange    : onChangeResetProfile
                        },
                    ]
                },
                {
                    name: "faultInputFilterEn",
                    displayName: "Enable Fault Input Filter",
                    description: "Enables a Fault Input Filter",
                    longDescription: `Enables a Fault Input Filter that can be configured as either
                    Consecutive Period or Majority Voting.
                    \n Consecutive Period: The input must be at a specific logic level for the period
                    defined by the Sample Period before it is passed to the filter output.
                    \n Majority Voting. The filter ignores one clock of opposite logic over the filter period.
                    Over the number of samples defined by Sample Period, up to 1 sample may be of an opposite value.`,
                    hidden: true,
                    default: false,
                    onChange: (inst, ui) => {
                        ui.faultFilterType.hidden = !inst.faultInputFilterEn;
                        ui.faultFilterSamplePeriod.hidden = !inst.faultInputFilterEn;
                        onChangeResetProfile(inst, ui);
                    }
                },
                {
                    name: "faultFilterType",
                    displayName: "Filter Type",
                    description: "Sets the type of Filter in Use",
                    longDescription: `Filter Types:
                    \nConsecutive Period: The input must be at a specific logic level for the period
                    defined by the Sample Period before it is passed to the filter output.
                    \n Majority Voting. The filter ignores one clock of opposite logic over the filter period.
                    Over the number of samples defined by Sample Period, up to 1 sample may be of an opposite value.`,
                    hidden: true,
                    default: "CONSEC_PER",
                    options: [
                        {name: "CONSEC_PER", displayName: "Consecutive Period"},
                        {name: "VOTING", displayName: "Majority Voting"}
                    ],
                    onChange: onChangeResetProfile
                },
                {
                    name: "faultFilterSamplePeriod",
                    displayName: "Sample Period",
                    description: "The Number of Samples used in the Filter",
                    longDescription: `The number of samples used in the filter, setting the duration for the two filter types.`,
                    hidden: true,
                    default: "3",
                    options: [
                        {name: "3", displayName: "3 Timer Clocks"},
                        {name: "5", displayName: "5 Timer Clocks"},
                        {name: "8", displayName: "8 Timer Clocks"},
                    ],
                    onChange: onChangeResetProfile
                },
                {
                    name: "faultChannel0BehaviorConfig",
                    displayName: "Channel 0 Output Behavior",
                    collapsed: false,
                    config: [
                        {
                            name: "faultChannel0BehaviorEntry",
                            displayName: "Output Behavior On Fault Entry",
                            description: "Determines how the channel will respond to entering a fault.",
                            longDescription: `The channel value upon entry will be set according to the possible options`,
                            default: "DISABLED",
                            hidden: true,
                            options: BehaviorOptions,
                            onChange: onChangeResetProfile
                        },
                        {
                            name: "faultChannel0BehaviorExit",
                            displayName: "Output Behavior On Fault Exit",
                            description: "Determines how the channel will respond to exiting a fault.",
                            longDescription: `The channel value upon exit will be set according to the possible options`,
                            hidden: true,
                            default: "DISABLED",
                            options: BehaviorOptions,
                            onChange: onChangeResetProfile
                        }
                    ]
                },
                {
                    name: "faultChannel1BehaviorConfig",
                    displayName: "Channel 1 Output Behavior",
                    collapsed: false,
                    config: [
                        {
                            name: "faultChannel1BehaviorEntry",
                            displayName: "Output Behavior On Fault Entry",
                            description: "Determines how the channel will respond to entering a fault.",
                            longDescription: `The channel value upon entry will be set according to the possible options`,
                            hidden: true,
                            default: "DISABLED",
                            options: BehaviorOptions,
                            onChange: onChangeResetProfile
                        },
                        {
                            name: "faultChannel1BehaviorExit",
                            displayName: "Output Behavior On Fault Exit",
                            description: "Determines how the channel will respond to exiting a fault.",
                            longDescription: `The channel value upon exit will be set according to the possible options`,
                            hidden: true,
                            default: "DISABLED",
                            options: BehaviorOptions,
                            onChange: onChangeResetProfile
                        }
                    ]
                },
                {
                    name: "faultChannel2BehaviorConfig",
                    displayName: "Channel 2 Output Behavior",
                    collapsed: false,
                    config: [
                        {
                            name: "faultChannel2BehaviorEntry",
                            displayName: "Output Behavior On Fault Entry",
                            description: "Determines how the channel will respond to entering a fault.",
                            longDescription: `The channel value upon entry will be set according to the possible options`,
                            hidden: true,
                            default: "DISABLED",
                            options: BehaviorOptions,
                            onChange: onChangeResetProfile
                        },
                        {
                            name: "faultChannel2BehaviorExit",
                            displayName: "Output Behavior On Fault Exit",
                            description: "Determines how the channel will respond to exiting a fault.",
                            longDescription: `The channel value upon exit will be set according to the possible options`,
                            hidden: true,
                            default: "DISABLED",
                            options: BehaviorOptions,
                            onChange: onChangeResetProfile
                        }
                    ]
                },
                {
                    name: "faultChannel3BehaviorConfig",
                    displayName: "Channel 3 Output Behavior",
                    collapsed: false,
                    config: [
                        {
                            name: "faultChannel3BehaviorEntry",
                            displayName: "Output Behavior On Fault Entry",
                            description: "Determines how the channel will respond to entering a fault.",
                            longDescription: `The channel value upon entry will be set according to the possible options`,
                            hidden: true,
                            default: "DISABLED",
                            options: BehaviorOptions,
                            onChange: onChangeResetProfile
                        },
                        {
                            name: "faultChannel3BehaviorExit",
                            displayName: "Output Behavior On Fault Exit",
                            description: "Determines how the channel will respond to exiting a fault.",
                            longDescription: `The channel value upon exit will be set according to the possible options`,
                            hidden: true,
                            default: "DISABLED",
                            options: BehaviorOptions,
                            onChange: onChangeResetProfile
                        }
                    ]
                },
                {
                    name        : "faultCTEn",
                    displayName : "Enable Fault Cross Trigger Input Sel",
                    description : 'Enable Fault Cross Trigger Input Selection',
                    hidden      : true,
                    default     : false,
                    onChange: onChangeResetProfile
                },
                {
                    name        : "faultInputDetect",
                    displayName : "Enable Fault Input Detection",
                    description : 'Specifies which of all available timer instance fault inputs from the fault cross trigger participate in generating the fault assertion.',
                    hidden      : true,
                    default     : false,
                    onChange: onChangeResetProfile
                },
                {
                    name        : "faultSrcClkDetect",
                    displayName : "Enable Source Clock Fault Detection",
                    description : '',
                    hidden      : true,
                    default     : false,
                    onChange: onChangeResetProfile
                },
            ]

        },
    );
}
if(Common.isDeviceM0G()){
    configAdvanced.push(
        {
            name: "GROUP_RETENTION",
            displayName: "Retention Configuration",
            description: "",
            longDescription: ``,
            collapsed: false,
            config: retentionConfig,
        },
    );
};

let ccIndexOptions = [
    { name: 0, displayName: "PWM Channel 0" },
    { name: 1, displayName: "PWM Channel 1" },
];
let ccIndexAllOptions = [
    { name: 0, displayName: "PWM Channel 0" },
    { name: 1, displayName: "PWM Channel 1" },
];
if(Common.hasTimerA()){
    ccIndexOptions.push(
        { name: 2, displayName: "PWM Channel 2" },
        { name: 3, displayName: "PWM Channel 3" },
    );
    ccIndexAllOptions.push(
        { name: 2, displayName: "PWM Channel 2" },
        { name: 3, displayName: "PWM Channel 3" },
        { name: 4, displayName: "Internal Channel 4" },
        { name: 5, displayName: "Internal Channel 5" },

    );
}



/* Advanced Config: Secondary Compare */
configAdvanced.push(
    {
        name: "GROUP_SECOND_COMP",
        displayName: "Second Capture Compare Event Configuration",
        description: "",
        longDescription: ``,
        collapsed: false,
        config: [
            {
                name: "secondCompEn",
                displayName: "Enable Secondary Capture Compare Configuration",
                description: "",
                longDescription: ``,
                default: false,
                onChange: updateGUI_SecondCompare,
            },
            {
                name: "GROUP_SECOND_CH0",
                displayName: "PWM Channel 0",
                description: "",
                longDescription: ``,
                collapsed: false,
                config: [
                    {
                        name: "secondCompDirectionCH0",
                        displayName: "Secondary Capture Compare Direction",
                        description: "",
                        longDescription: ``,
                        default: [],
                        minSelections: 0,
                        hidden: true,
                        options: [
                            {name: "UP", displayName: "Capture Compare Up"},
                            {name: "DOWN", displayName: "Capture Compare Down"},
                        ],
                        onChange: updateGUI_SecondCompare,
                    },
                    {
                        name: "secondCompUpSourceCH0",
                        displayName: "Up Counting Event Source",
                        description: "Configures source for second capture compare up event",
                        longDescription: ``,
                        default: 0,
                        hidden: true,
                        options: ccIndexAllOptions,
                        getDisabledOptions: getDisabledCCIndexCmplOptions,
                    },
                    {
                        name: "secondCompUpActionCH0",
                        displayName: "Up Counting Event Action",
                        description: "Configures action for second capture compare up event",
                        longDescription: ``,
                        default: "DISABLED",
                        hidden: true,
                        options: [
                            {name: "DISABLED", displayName: "Disable"},
                            {name: "HIGH", displayName: "High"},
                            {name: "LOW", displayName: "Low"},
                            {name: "TOGGLE", displayName: "Toggle"},
                        ],
                    },
                    {
                        name: "secondCompDownSourceCH0",
                        displayName: "Down Counting Event Source",
                        description: "Configures source for second capture compare down event",
                        longDescription: ``,
                        default: 0,
                        hidden: true,
                        options: ccIndexAllOptions,
                        getDisabledOptions: getDisabledCCIndexCmplOptions,
                    },
                    {
                        name: "secondCompDownActionCH0",
                        displayName: "Down Counting Event Action",
                        description: "Configures action for second capture compare down event",
                        longDescription: ``,
                        default: "DISABLED",
                        hidden: true,
                        options: [
                            {name: "DISABLED", displayName: "Disable"},
                            {name: "HIGH", displayName: "High"},
                            {name: "LOW", displayName: "Low"},
                            {name: "TOGGLE", displayName: "Toggle"},
                        ],
                    },
                ],
            },
            {
                name: "GROUP_SECOND_CH1",
                displayName: "PWM Channel 1",
                description: "",
                longDescription: ``,
                collapsed: false,
                config: [
                    {
                        name: "secondCompDirectionCH1",
                        displayName: "Secondary Capture Compare Direction",
                        description: "",
                        longDescription: ``,
                        default: [],
                        minSelections: 0,
                        hidden: true,
                        options: [
                            {name: "UP", displayName: "Capture Compare Up"},
                            {name: "DOWN", displayName: "Capture Compare Down"},
                        ],
                        onChange: updateGUI_SecondCompare,
                    },
                    {
                        name: "secondCompUpSourceCH1",
                        displayName: "Up Counting Event Source",
                        description: "Configures source for second capture compare up event",
                        longDescription: ``,
                        default: 0,
                        hidden: true,
                        options: ccIndexAllOptions,
                        getDisabledOptions: getDisabledCCIndexCmplOptions,
                    },
                    {
                        name: "secondCompUpActionCH1",
                        displayName: "Up Counting Event Action",
                        description: "Configures action for second capture compare up event",
                        longDescription: ``,
                        default: "DISABLED",
                        hidden: true,
                        options: [
                            {name: "DISABLED", displayName: "Disable"},
                            {name: "HIGH", displayName: "High"},
                            {name: "LOW", displayName: "Low"},
                            {name: "TOGGLE", displayName: "Toggle"},
                        ],
                    },
                    {
                        name: "secondCompDownSourceCH1",
                        displayName: "Down Counting Event Source",
                        description: "Configures source for second capture compare down event",
                        longDescription: ``,
                        default: 0,
                        hidden: true,
                        options: ccIndexAllOptions,
                        getDisabledOptions: getDisabledCCIndexCmplOptions,
                    },
                    {
                        name: "secondCompDownActionCH1",
                        displayName: "Down Counting Event Action",
                        description: "Configures action for second capture compare down event",
                        longDescription: ``,
                        default: "DISABLED",
                        hidden: true,
                        options: [
                            {name: "DISABLED", displayName: "Disable"},
                            {name: "HIGH", displayName: "High"},
                            {name: "LOW", displayName: "Low"},
                            {name: "TOGGLE", displayName: "Toggle"},
                        ],
                    },
                ],
            },
            {
                name: "GROUP_SECOND_CH2",
                displayName: "PWM Channel 2",
                description: "",
                longDescription: ``,
                collapsed: false,
                config: [
                    {
                        name: "secondCompDirectionCH2",
                        displayName: "Secondary Capture Compare Direction",
                        description: "",
                        longDescription: ``,
                        default: [],
                        minSelections: 0,
                        hidden: true,
                        options: [
                            {name: "UP", displayName: "Capture Compare Up"},
                            {name: "DOWN", displayName: "Capture Compare Down"},
                        ],
                        onChange: updateGUI_SecondCompare,
                    },
                    {
                        name: "secondCompUpSourceCH2",
                        displayName: "Up Counting Event Source",
                        description: "Configures source for second capture compare up event",
                        longDescription: ``,
                        default: 0,
                        hidden: true,
                        options: ccIndexAllOptions,
                        getDisabledOptions: getDisabledCCIndexCmplOptions,
                    },
                    {
                        name: "secondCompUpActionCH2",
                        displayName: "Up Counting Event Action",
                        description: "Configures action for second capture compare up event",
                        longDescription: ``,
                        default: "DISABLED",
                        hidden: true,
                        options: [
                            {name: "DISABLED", displayName: "Disable"},
                            {name: "HIGH", displayName: "High"},
                            {name: "LOW", displayName: "Low"},
                            {name: "TOGGLE", displayName: "Toggle"},
                        ],
                    },
                    {
                        name: "secondCompDownSourceCH2",
                        displayName: "Down Counting Event Source",
                        description: "Configures source for second capture compare down event",
                        longDescription: ``,
                        default: 0,
                        hidden: true,
                        options: ccIndexAllOptions,
                        getDisabledOptions: getDisabledCCIndexCmplOptions,
                    },
                    {
                        name: "secondCompDownActionCH2",
                        displayName: "Down Counting Event Action",
                        description: "Configures action for second capture compare down event",
                        longDescription: ``,
                        default: "DISABLED",
                        hidden: true,
                        options: [
                            {name: "DISABLED", displayName: "Disable"},
                            {name: "HIGH", displayName: "High"},
                            {name: "LOW", displayName: "Low"},
                            {name: "TOGGLE", displayName: "Toggle"},
                        ],
                    },
                ],
            },
            {
                name: "GROUP_SECOND_CH3",
                displayName: "PWM Channel 3",
                description: "",
                longDescription: ``,
                collapsed: false,
                config: [
                    {
                        name: "secondCompDirectionCH3",
                        displayName: "Secondary Capture Compare Direction",
                        description: "",
                        longDescription: ``,
                        default: [],
                        minSelections: 0,
                        hidden: true,
                        options: [
                            {name: "UP", displayName: "Capture Compare Up"},
                            {name: "DOWN", displayName: "Capture Compare Down"},
                        ],
                        onChange: updateGUI_SecondCompare,
                    },
                    {
                        name: "secondCompUpSourceCH3",
                        displayName: "Up Counting Event Source",
                        description: "Configures source for second capture compare up event",
                        longDescription: ``,
                        default: 0,
                        hidden: true,
                        options: ccIndexAllOptions,
                        getDisabledOptions: getDisabledCCIndexCmplOptions,
                    },
                    {
                        name: "secondCompUpActionCH3",
                        displayName: "Up Counting Event Action",
                        description: "Configures action for second capture compare up event",
                        longDescription: ``,
                        default: "DISABLED",
                        hidden: true,
                        options: [
                            {name: "DISABLED", displayName: "Disable"},
                            {name: "HIGH", displayName: "High"},
                            {name: "LOW", displayName: "Low"},
                            {name: "TOGGLE", displayName: "Toggle"},
                        ],
                    },
                    {
                        name: "secondCompDownSourceCH3",
                        displayName: "Down Counting Event Source",
                        description: "Configures source for second capture compare down event",
                        longDescription: ``,
                        default: 0,
                        hidden: true,
                        options: ccIndexAllOptions,
                        getDisabledOptions: getDisabledCCIndexCmplOptions,
                    },
                    {
                        name: "secondCompDownActionCH3",
                        displayName: "Down Counting Event Action",
                        description: "Configures action for second capture compare down event",
                        longDescription: ``,
                        default: "DISABLED",
                        hidden: true,
                        options: [
                            {name: "DISABLED", displayName: "Disable"},
                            {name: "HIGH", displayName: "High"},
                            {name: "LOW", displayName: "Low"},
                            {name: "TOGGLE", displayName: "Toggle"},
                        ],
                    },
                ],
            },
        ],
    },
);

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base PWM configuration
 */

let profileOptions = [
    { name: "basic_single_channel_center_align", displayName: "Basic Single Channel Center Align using BUSCLK" },
    { name: "basic_dual_channel_edge_align_lfclk", displayName: "Basic Two-Channel Edge Align using LFCLK"},
    { name: "deadband_insertion_center_aligned", displayName: "Dead Band Insertion Center Aligned"},
    { name: "CUSTOM", displayName: "Custom" }
];

if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()) {
    /* remove deadband insertion for M0L */
    profileOptions.splice(2,1);
}

let configPWM = [
    {
        name: "pwmMode",
        displayName: "PWM Mode",
        description: "Specifies the PWM alignment",
        longDescription: `Specifies how the PWM form is aligned with the timer.
        \nEdge-aligned Down Counting: The Timer is configured as count down. On each load, the output signal is set high.
        Once the compare value is met (which will specify the duty cycle), the corresponding output signal is set low.
        Therefore, each pwm channel will have the same rise time and different fall times.
        \nEdge-aligned Up Counting: The Timer is configured as count up. On each zero, the output signal is set high.
        Once the compare value is met (which will specify the duty cycle), the corresponding output signal is set high.
        Therefore, each pwm channel will have the same rise time and different fall times.
        \nCenter-Aligned: The Timer is configured as count up/down. When ascending past the compare value, the
        ouput will be set to high. When descending past the same compare value, the output will be set to low. Thus,
        the center of each pwm channel will be when the timer's LOAD value is in the counter.`,
        default: "EDGE_ALIGN",
        options: [
            { name: "EDGE_ALIGN", displayName: "Edge-aligned Down Counting" },
            { name: "EDGE_ALIGN_UP", displayName: "Edge-aligned Up Counting" },
            { name: "CENTER_ALIGN", displayName: "Center-aligned" },
        ],
        /*
         * counterZero should only be selectable for center
         * aligned PWM.
         * counterLoad should only be selectable for edge aligned
         * PWM.
         */
        onChange: (inst, ui) => {
            updateGUI_PWMMode(inst, ui);
            onChangeResetProfile(inst, ui);
        }
    },
    {
        name: "ccIndex",
        displayName: "PWM Channel(s)",
        description: "Specifies which Channels are Active",
        longDescription: `Determine which PWM output channels are in use.
        For certain advanced functionality such as dead band, complementary
        channels such as 0 and 1 must both be active
        \n **NOTE:** Channels 2 and 3 are only available on TIMA0`,
        default: [0,1],
        minSelections: 0,
        options: ccIndexOptions,
        onChange: onChangeCCIndex
    },
];
if(Common.hasTimerA()){
    configPWM.push({
        name: "ccIndexCmpl",
        displayName: "Enable Channel Complimentary Output",
        description: "Specifies which Channel Complimentary Output to enable",
        longDescription: `Specifies which PWM Channel(s) Complimentary Output to enable, both channels must be active.`,
        default: [],
        minSelections: 0,
        options: ccIndexOptions,
        getDisabledOptions: getDisabledCCIndexCmplOptions,
        onChange: onChangeFaultHandler
    })
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
            name: "QUICK_PROFILE_GROUP",
            displayName: "Quick Profiles",
            collapsed: false,
            config: [
                {
                    name: "profile",
                    displayName: "PWM Profiles",
                    description: "Pre-defined profiles for typical PWM configurations",
                    longDescription: `
The TIMER module for the MSPM0 family is a set of general purpose timers
that can be configured to generate output waveforms.
The module allows the use of TIMA, TIMG, and TIMG12 instances. A specific
instance can be selected in the PinMux Section, or one can be solved for based
on the given capabilities
* **TIMA**:
    * 16-bit counter with 8-bit prescaler and Fault Handling (uses external pin)
    * TIMA0 also has a repeat counter
    * **Only available on MSPM0Gxx**
* **TIMG**:
    * 16-bit counter with 8-bit prescaler
* **TIMG12**:
    * 32-bit counter without a prescaler
    * **Only available on MSPM0Gxx**\n

The Quick Profile Options are:
* **Basic Single Channel Center Align using BUSCLK**:
    * Outputs a 1.25kHz center aligned PWM at a 50% duty cycle
* **Basic Dual Channel Edge Aligned using LFCLK**:
    * Outputs a pair of 1kHz edge aligned PWM signal at 25% and 75% duty cycle
* **Dead Band Insertion Center Aligned**:
    * Configures TIMA in PWM center align mode and outputs 2 PWM signals at 50% duty cycles
    * Signals on C0 and C1 are complementary signals with deadband insertion
    * **Only available on TIMA (MSPM0Gxx-only)**
    * Dead band insertion mode 0
    * Rise delay timer counts: 15
* **Custom**:
    * Allows custom configuration
`,
                    default: "CUSTOM",
                    options: profileOptions,
                    onChange: onChangePWMProfile
                }
            ]
        },
        {
            name: "basicConfig",
            displayName: "Basic Configuration",
            longDescription: "Configure the timer and the PWM channels that will be used",
            collapsed: false,
            config: [
                {
                    name: "GROUP_CLOCK",
                    displayName: "Clock Configuration",
                    description: "",
                    longDescription: "Configures Timer clock source, divider and prescaler",
                    collapsed: false,
                    config: [
                        {
                            name: "clockSource",
                            displayName: "Timer Clock Source",
                            description: "Configure timer source clock",
                            longDescription:`The frequency of the clock sources are configured
                            by the clock modules.`,
                            default: "BUSCLK",
                            options: [
                                { name: "BUSCLK", displayName: "BUSCLK" },
                                { name: "MFCLK", displayName: "MFCLK" },
                                { name: "LFCLK", displayName: "LFCLK" },
                            ],
                            onChange: onChangeCLK
                        },
                        {
                            name: "inputClock_Freq",
                            hidden: true,
                            default: 0,
                            getValue: (inst) => {
                                switch(inst.clockSource){
                                    case "BUSCLK":
                                        return Common.getBUSCLKFreq(inst, "GPTIMER");
                                    case "MFCLK":
                                        return system.modules["/ti/driverlib/SYSCTL"].$static.MFCLK_Freq;
                                    case "LFCLK":
                                        return system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq;
                                }
                            }
                        },
                        {
                            name: "clockDivider",
                            displayName: "Timer Clock Divider",
                            description: "Selects the timer module clock divide ratio",
                            longDescription: `The clock divider reduces the timer clock frequency by a factor of 1 (none) to 8.
                            \nClock Frequency = Input Clock Frequency / ( divider * (prescale))`,
                            default: 1,
                            options: [
                                { name: 1, displayName: "Divided by 1"},
                                { name: 2, displayName: "Divided by 2"},
                                { name: 3, displayName: "Divided by 3"},
                                { name: 4, displayName: "Divided by 4"},
                                { name: 5, displayName: "Divided by 5"},
                                { name: 6, displayName: "Divided by 6"},
                                { name: 7, displayName: "Divided by 7"},
                                { name: 8, displayName: "Divided by 8"}
                            ],
                            onChange: onChangeCLK
                        },
                        {
                            name        : "timerClockSourceCalculated",
                            displayName : "Calculated Timer Clock Source",
                            description : 'Calculated Timer Clock Source in Hz',
                            hidden      : false,
                            getValue    : (inst) => getTimerClockSourceFreq(inst),
                            default     : 0
                        },
                        {
                            name: "clockPrescale",
                            displayName: "Timer Clock Prescale",
                            description: "Selects the timer module clock prescaler. Valid Range: 1-256",
                            longDescription: `The clock prescale reduces the timer clock frequency by a factor of 1 (none) to 256.
                            Valid Range: 1 - 256
                            \nClock Frequency = Input Clock Frequency / ( divider * (prescale))`,
                            default: 1,
                            isInteger: true,
                            range: [1, 256],
                            onChange: onChangeCLK
                        },
                        {
                            name: "GROUP_CLOCK_CAL",
                            displayName: "Calculated Timer Clock Values",
                            description: "",
                            collapsed: false,
                            config:
                            [
                                {
                                    name: "timerClk_Freq",
                                    displayName: "Calculated Clock Frequency (Hz)",
                                    description: "Clock Frequency at which the timer will be decremented/incremented",
                                    longDescription:
`
This is the clock frequency that is seen by the timer count register. It is after the input clock has been
divided and prescaled.\n
Timer Clock Frequency calculation: timerClkFreq = (timerClkSrc / (timerClkDiv \* timerClkPrescale))\n
ex.\n
Timer clock sourced by BUSCLK running at 32000000 Hz\n
Timer clock source divider set to 2\n
Timer clock prescale set to 4\n
            timerClkFreq = (timerClkSrc / (timerClkDivRatio * timerClkPrescale))\n
            4000000 Hz = 16000000 Hz / (2 * 4)\n
`,
                                    default: 0,
                                    getValue: (inst) => {
                                        // in the case of TIMG12, prescale should be 1
                                        return inst.inputClock_Freq / (inst.clockDivider * (inst.clockPrescale));
                                    }
                                },
                                {
                                    name: "timerClk_Info",
                                    displayName: "Timer Clock Information",
                                    default: "1 Hz to 100 KHz w/ resolution of 0.1ms",
                                    description: "Information Concerning Current Timer Range and Resolution for Timer Count",
                                    longDescription: `Calculated information about the possible frequencies and resolution possible for the Timer Count with the
                                    given PWM alignment mode and clock frequency`,
                                    getValue: (inst) => {
                                        let increment = Common.getUnitPrefix(1 / inst.timerClk_Freq); // in us
                                        let timerFreq = Common.getUnitPrefix(inst.timerClk_Freq / 2);
                                        let maxCount = (1<<16);
                                        if(inst.peripheral.$solution !== undefined) {
                                            if(inst.peripheral.$solution.peripheralName.match(/TIMG12\d/)) {
                                                maxCount = (4294967295);
                                            }
                                        }
                                        let minFreq;
                                        if(inst.pwmMode == "EDGE_ALIGN") {
                                            minFreq = Common.getUnitPrefix(inst.timerClk_Freq / maxCount);
                                        } else {
                                            minFreq = Common.getUnitPrefix(inst.timerClk_Freq / ((maxCount - 1) * 2));
                                        }
                                        let str = minFreq.str + "Hz to " + timerFreq.str + "Hz w/ resolution of " + increment.str + "s";
                                        return str;
                                    }
                                },
                            ],
                        },
                    ],
                },
                {
                    name: "timerCount",
                    displayName: "PWM Period Count",
                    description: "Value loaded into timer during a load event",
                    longDescription: `This is the value put into the timer on a load event.
                    It will require this many ticks + 1 for the device to complete a counting cycle.
                    The PWM compare value, used for duty cycle, must be smaller than this period.
                    This value will be loaded and counted down from in the event of the edge-align mode, or
                    will be counted up to and then down from in the center-align mode`,
                    isInteger: true,
                    default: 1000,
                    range: [1, 4294967295],
                    onChange: onChangeResetProfile
                },
                {
                    name: "timer_Freq",
                    displayName: "Calculated PWM Frequency (Hz)",
                    description: "The frequency at which the clock will complete a counting cycle",
                    longDescription: `This is the frequency at which the clock will complete one counting iteration.
                    \n Edge-Align Mode: This frequency is for the timer to count down from the loaded value.
                    It is equal to the Timer Clock Frequency divided by the count.
                    \n Center-Align: This is the frequency that it takes for the timer to count up to the load value and back down.
                    It is equal to the Clock Frequency divided by the count.`,
                    default: 0,
                    getValue: (inst) => {
                        /* Note: for center align the frequency is divided by 2 as part of the initPWM function */
                        return inst.timerClk_Freq / (inst.timerCount);
                    }
                },
                {
                    name        : "timerStartTimer",
                    displayName : 'Start Timer',
                    description : 'Start Timer',
                    longDescription: `When selected, the timer starts counting
                    after the Timer is initialized. Otherwise the timer will start
                    counting after the application calls DL_TimerX_startCounter.`,
                    hidden      : false,
                    default     : false,
                    onChange    : onChangeResetProfile
                },
                {
                    name: "GROUP_PWM_CONFIG",
                    displayName: "PWM Configuration",
                    description: "",
                    longDescription: "",
                    collapsed: false,
                    config: configPWM,
                },
            ]
        },

        {
            name: "advancedConfig",
            displayName: "Advanced Configuration",
            longDescription: `This section contains configuration parameters that may not be necessary for most simple operations.
            These include:
            \n* Cross Triggering: The ability to have this GP timer trigger or be triggered by another module or hardware element
            \n* Dead Band Insertion: Two PWMs, one reference signal and one other signal, create complementary PWM signals that have non-overlapping transitions
            \n* Fault Handling: Detection of some fault signal in the device that can put the timer into a configurable known state
            `,
            collapsed: true,
            config: configAdvanced,
        },
        {
            name: "interruptsConfig",
            displayName: "Interrupts Configuration",
            longDescription: `If interrupts are to be used by this module, this configures which interrupts are set for the timer`,
            collapsed: true,
            config: [
                {
                    name: "interrupts",
                    displayName: "Enable Interrupts",
                    description: "Specifies which interrupts are to be set",
                    longDescription: `Specifies the timer events that are to trigger an interrupt`,
                    default: [],
                    options: getEventOptions,
                    getDisabledOptions: getDisabledEvents,
                    onChange: (inst, ui) => {
                        onChangeResetProfile(inst, ui);
                        updateGUI_Interrupts(inst, ui);
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
            ]
        },
        {
            name: "eventConfig",
            displayName: "Event Configuration",
            longDescription: `Specifies the Timer Events that are to trigger an Event Condition and where the events are to be published`,
            collapsed: true,
            config: [
                {
                    name: "event1PublisherChannel",
                    displayName: "Event 1 Publisher Channel ID",
                    description: "Specifies the Channel For Event 1",
                    longDescription: `Specifies the Channel to which Timer Events in Event 1 will be published for use by other modules`,
                    default: 0,
                    options: EVENT.getPublisherOptions,
                    getDisabledOptions: EVENT.getPublisherDisabledOptions,
                    onChange: (inst,ui) => {
                        ui.event1ControllerInterruptEn.hidden = (inst.event1PublisherChannel == 0);
                        onChangeResetProfile(inst, ui);
                    }
                },
                {
                    name: "event1ControllerInterruptEn",
                    displayName: "Event 1 Enable Controller Interrupts",
                    description: "Determines the Timer Events that will trigger an Event 1 condition",
                    longDescription: `Selects all possible timer Events that will create an Event 1 condition`,
                    hidden: true,
                    default: [],
                    options: getEventOptions,
                    getDisabledOptions: getDisabledEvents,
                    onChange: onChangeResetProfile
                },
                {
                    name: "event2PublisherChannel",
                    displayName: "Event 2 Publisher Channel ID",
                    description: "Specifies the Channel For Event 2",
                    longDescription: `Specifies the Channel to which Timer Events in Event 2 will be published for use by other modules`,
                    default: 0,
                    options: (inst) => {
                        return EVENT.getPublisherOptions(inst);
                    },
                    getDisabledOptions: (inst) => {
                        return EVENT.getPublisherDisabledOptions(inst);
                    },
                    onChange: (inst,ui) => {
                        ui.event2ControllerInterruptEn.hidden = (inst.event2PublisherChannel == 0);
                        onChangeResetProfile(inst, ui);
                    }
                },
                {
                    name: "event2ControllerInterruptEn",
                    displayName: "Event 2 Enable Controller Interrupts",
                    description: "Determines the Timer Events that will trigger an Event 2 condition",
                    longDescription: `Selects all possible timer Events that will create an Event 2 condition`,
                    hidden: true,
                    default: [],
                    options: getEventOptions,
                    getDisabledOptions: getDisabledEvents,
                    onChange: onChangeResetProfile
                },
                {
                    name: "subscriberPort",
                    displayName: "Subscriber Port Selection",
                    description: "Specifies the subscriber port to be used",
                    longDescription: `Specifies the subscriber port to be used`,
                    default: "Disabled",
                    options: [
                        {name: "Disabled", displayName: "Disabled"},
                        {name: "FSUB0", displayName: "SubscriberPort0"},
                        {name: "FSUB1", displayName: "SubscriberPort1"}
                    ],
                    onChange: (inst, ui) => {
                        ui.subscriberChannel.hidden = (inst.subscriberPort == "Disabled");
                    }
                },
                {
                    name: "subscriberChannel",
                    displayName: "Subscriber Port Channel Selection",
                    description: "Specifies the channel for a subscriber port",
                    longDescription: `Specifies the event subscriber channel`,
                    hidden: true,
                    default: 0,
                    options: (inst) => {
                        return EVENT.getSubscriberOptions(inst);
                    },
                    getDisabledOptions: (inst) => {
                        return EVENT.getSubscriberDisabledOptions(inst);
                    },
                },
                {
                    name: "counterZero",
                    displayName: "Zero Counter On A Published Event",
                    description: "Specifies whether the counter should be zeroed on a published event",
                    longDescription: `For synchronizing center-aligned PWM
                    signals. When selected, a published event causes
                    center-aligned PWM signals to synchronize.`,
                    hidden: true,
                    default: false,
                },
                {
                    name: "counterLoad",
                    displayName: "Load Counter On A Published Event",
                    description: "Specifies whether the counter should be reloaded on a published event",
                    longDescription: `For synchronizing edge-aligned PWM
                    signals. When selected, a published event causes
                    edge-aligned PWM signals to synchronize.`,
                    /*
                     * Note, this is assuming that the default PWM mode upon
                     * module instantiation is edge aligned. If the default
                     * changes, the hidden value should be changed.
                     */
                    hidden: false,
                    default: false,
                },
                {
                    name: "eventInfo",
                    description: "information about configured events that's passed on to the EVENT module",
                    default: [""],
                    hidden: true,
                    options: (inst) => {
                        let options = [{name: ""}]
                        if(inst.event1PublisherChannel != 0){
                            options.push({name: inst.event1PublisherChannel.toString() + "pub"});
                        }
                        if(inst.event2PublisherChannel != 0){
                            options.push({name: inst.event2PublisherChannel.toString() + "pub"});
                        }
                        if((inst.subscriberPort != "Disabled") && (inst.subscriberChannel != 0)){
                            options.push({name: inst.subscriberChannel.toString() + "sub"});
                        }
                        return options;
                    },
                    getValue: (inst) => {
                        let result = [];
                        if(inst.event1PublisherChannel != 0){
                            result.push(inst.event1PublisherChannel.toString() + "pub");
                        }
                        if(inst.event2PublisherChannel != 0){
                            result.push(inst.event2PublisherChannel.toString() + "pub");
                        }
                        if((inst.subscriberPort != "Disabled") && (inst.subscriberChannel != 0)){
                            result.push(inst.subscriberChannel.toString() + "sub");
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
            /* this is a read-only array of the timers that are actually present on the device,
             * can be used to limit the allowable timers to those that make sense
             *
             * TODO: useful to detect the presence of TIMER A, to toggle the visibility of certain
             *       functionality
             */
            name: "timers",
            default: [""],
            /* superset of all possible timers */
            options: [
                {name: "TIMA0"}, {name: "TIMA1"},
                {name: "TIMG0"}, {name: "TIMG1"}, {name: "TIMG2"}, {name: "TIMG3"}, {name: "TIMG4"}, {name: "TIMG5"},
                {name: "TIMG6"}, {name: "TIMG7"}, {name: "TIMG8"}, {name: "TIMG9"}, {name: "TIMG10"}, {name: "TIMG11"},
                {name: "TIMG12"}, {name: "TIMG14"}, {name: ""}
            ],
            hidden: true,
            getValue: (inst) => {
                let array = _.map(system.deviceData.interfaces.GPTIMER.peripherals, (v)=> v.name);
                return array;
            }
        },
        {
            name: "fourChannelCapable",
            default: true,
            hidden: true,
            getValue: (inst) => {
                let available = inst.timerAssignment.match("Any") || inst.timerAssignment.match("TIMA0|TIMG14");
                let onDevice = inst.timers.includes("TIMA0") || inst.timers.includes("TIMG14");
                return (available && onDevice)?true:false;
            }
        },
        {
            name: "timerACapable",
            default: true,
            hidden: true,
            getValue: (inst) => {
                let available = inst.timerAssignment.match("Any") || inst.timerAssignment.match("TIMA.");
                let onDevice = inst.timers.includes("TIMA0") || inst.timers.includes("TIMA1");
                return (available && onDevice)?true:false;
            }
        },
        {
            // Removes undefined possibility for timer assignment
            name: "timerAssignment",
            default: "Any",
            hidden: true,
            getValue: (inst) => {
                if(inst.peripheral) {
                    return inst.peripheral.$assign;
                } else {
                    return "Any";
                }
            }
        },
        {
            /* used by onChangePWMProfile to pass a value to CCValue */
            name: "dutyArgs",
            hidden: true,
            default: "[0,0,0,0]",
        }
    ];

/* Add Pinmux Peripheral Configuration group */
config = config.concat(Common.getGPIOGroupConfig());

let devSpecific = {
    config: config,

    /* override generic requirements with  device-specific reqs (if any) */
    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    moduleInstances: moduleInstances,

    sharedModuleInstances: sharedModuleInstances,

    maxInstances: Common.peripheralCount("GPTIMER"),

    validate: validate,

    validatePinmux: validatePinmux,

    modules: setRequiredModules,

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/pwm/PWMTimer.Board.c.xdt",
        boardh: "/ti/driverlib/pwm/PWMTimer.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true,
        Retention: Common.isDeviceM0G(),
    },

    _getPinResources: _getPinResources
};

function setRequiredModules(inst){
    let theModules = ["Board", "SYSCTL", "EVENT"]
    // if(inst.faultHandlerEn){
    //     let result = ["0","1","2"].some(i => (inst.faultSource).includes(i));
    //     if(result){
    //         theModules.push("TIMERFault");
    //     }
    // }

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
 *  This function is invoked by the generic PWM module to
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
    /* required function, called by base PWM module */
    extend: extend
};
