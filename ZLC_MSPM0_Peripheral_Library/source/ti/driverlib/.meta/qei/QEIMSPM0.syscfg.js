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
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SO4FTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 *  ======== QEIMSPM0.js ========
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
 *  param inst       - PWM instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    if(inst.crossTriggerEn) {

        if(inst.crossTriggerAuthority == "Main"){
            let str = "QEI is not typically configured as Main Cross-Trigger";
            validation.logInfo(str, inst, "crossTriggerAuthority");
        }
    }

    /* Make sure clocks are initialized properly */
    if(inst.inputClock_Freq == 0)
    {
        let str = "Clock Source " + inst.clockSource + " not properly initialized in SYSCTL";
        validation.logError(str, inst, "clockSource");
    }

    /* validate dynmaicEnums */
    let dynamicEnums = ["secondaryCrossTriggerSource"];
    for(let dE of dynamicEnums){
        let validOptions = inst.$module.$configByName[dE].options();
        let selOption = inst[dE];
        let found = _.find(validOptions, (o) => o.name === selOption);
        if(!found){
            validation.logError("Invalid Option Selected. Please reselect", inst, dE);
        }
    }

    if(inst.enableHallInput && !inst.enableIndexInput){
        validation.logError("3 Pin Mode must be enabled when configuring Hall Input Mode", inst, ["enableHallInput","enableIndexInput"]);
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

    if(inst.clockSource == "BUSCLK" && inst.busClockSource == "MCLK") {
        // Power Domain 1 instances only
        if(solution.match("TIMG(10|11)") == null){
            validation.logError("Selected source of Bus Clock is only available for Power Domain 1 instances.", inst, ["clockSource","busClockSource"]);
        }
    } else if(inst.clockSource == "BUSCLK" && inst.busClockSource == "ULPCLK") {
        // Power Domain 0 instances only
        if(solution.match("TIMG(8|9)") == null){
            validation.logError("Selected source of Bus Clock is only available for Power Domain 0 instances.", inst, ["clockSource","busClockSource"]);
        }
    }
    /* Prescale validation */
    if(/TIMG12|TIMG13/.test(solution)){
        if(inst.clockPrescale !== 1) {
            validation.logError("Prescaler is not available for 32-bit Timers. Select a prescale value of 1, or a different peripheral in PinMux section", inst, "clockPrescale");
        }
    }
    /* Retention Validation */
    Common.getRetentionValidation(inst,validation);
}

const QEIFilterElementsUsed = [];

const memoizedQEIFilter = _.memoize(curryQEIFilter,
    (inst) => JSON.stringify(_.pick(inst, QEIFilterElementsUsed)));

function curryQEIFilter(inst) {
    const args = _.pick(inst, QEIFilterElementsUsed);
    return (peripheral) => QEIFilter(peripheral, args);
}

/* QEI resource Filter currently not getting called from the tool, commented out */
const memoizedQEIResourceFilter = _.memoize(curryQEIResourceFilter,
    (inst) => JSON.stringify(_.pick(inst, QEIFilterElementsUsed)));

function curryQEIResourceFilter(inst) {
    const args = _.pick(inst, QEIFilterElementsUsed);
    return (_, peripheralPin) => QEIFilter(peripheralPin, args);
}

/* Filter to allow only QEI compatible timer peripherals */
function QEIFilter(peripheral, inst){
    let eligible = true;
    eligible &= (peripheral.name.match("TIMG(8|9|10|11)") !== null);
    return eligible;
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

    let idx = {
        name              : "idxPin",
        displayName       : "IDX Pin",
        interfaceNames    : ["IDX"],
        filter            : memoizedQEIResourceFilter(inst)
    };

    let qei = {
        name: "peripheral",
        displayName: "QEI Peripheral",
        interfaceName: "GPTIMER",
        resources: [
            {
                name: "ccp0Pin",            /* config script name */
                displayName: "Capture/Compare Pin 0",    /* GUI name */
                interfaceNames: ["CCP0"],   /* pinmux tool name */
                filter : memoizedQEIResourceFilter(inst)
            },
            {
                name: "ccp1Pin",
                displayName: "Capture/Compare Pin 1",
                interfaceNames: ["CCP1"],
                filter: memoizedQEIResourceFilter(inst)
            }
        ],
        filter: memoizedQEIFilter(inst),
        signalTypes: {
            ccp0Pin: ["CCP0"], /* warning: device-specific signal name */
            ccp1Pin: ["CCP1"], /* warning: device-specific signal name */
            idxPin: ["IDX"]
        }
    };

    if(inst.enableIndexInput) {
        qei.resources.push(idx);
    }

    return ([qei]);
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

/* On Change Helper Functions */

/* Somewhat redundant for finer configurables but this makes editing and readability much easier */
function onChangeCrossTrigger(inst, ui){
    if(!inst.crossTriggerEn){
        ui.crossTriggerAuthority.hidden = true;
        ui.mainCrossTriggerSource.hidden = true;
        ui.secondaryCrossTriggerSource.hidden = true;
    } else {
        ui.crossTriggerAuthority.hidden = false;
        if(inst.crossTriggerAuthority == "Main") {
            ui.mainCrossTriggerSource.hidden = false;
        } else {
            ui.mainCrossTriggerSource.hidden = true;
        }
        if(inst.crossTriggerAuthority == "Secondary") {
            ui.secondaryCrossTriggerSource.hidden = false;
        } else {
            ui.secondaryCrossTriggerSource.hidden = true;
        }
    }
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

let allEventOptions = [
    { name: "ZERO_EVENT", displayName: "Zero event", description: "Fires when counter reaches zero." },
    { name: "LOAD_EVENT", displayName: "Load event", description: "Used for QEI 3 signal mode when IDX signal triggers a load event" },
    { name: "DC_EVENT", displayName: "Direction change event", reason: "Direction has changed" },
    { name: "CC0_DN_EVENT", displayName: "Channel 0 compare down event", description: "Channel 0 compare value reached in timer down counting mode" },
    { name: "CC0_UP_EVENT", displayName: "Channel 0 compare up event"  , description: "Channel 0 compare value reached in timer up counting mode" },
    { name: "CC1_DN_EVENT", displayName: "Channel 1 compare down event", description: "Channel 1 compare value reached in timer down counting mode" },
    { name: "CC1_UP_EVENT", displayName: "Channel 1 compare up event"  , description: "Channel 1 compare value reached in timer up counting mode" },
];

function getEventOptions(inst)
{
    let options = [];
    //let pubs = system.modules["/ti/driverlib/EVENT"].$static.channel2Pub;
    for(let option of allEventOptions){
        options.push({name: option["name"], displayName: option["displayName"]});
    }

    return options;
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
                    solution = (/TIMG8/.test(inst.peripheral.$solution.peripheralName));
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
                    solution = (/TIMG8/.test(inst.peripheral.$solution.peripheralName)) && !(/SLEEP/.test(system.modules["/ti/driverlib/SYSCTL"].$static.powerPolicy));
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

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */

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
                            by the clock modules. The rate the ccp0, ccp1 and idx pins are sampled is based on the source for the TIMG (QEI) clock.
        \nBUSCLK - Source of BUSCLK is based on the power domain the timer instance is apart of.\n
        -> Power Domain 0 - Source is ULPCLK which supports operation up to 40 MHz.
        -> Power Domain 1 - Source is MCLK which supports operation up to 80 MHz.
        \nMFCLK - Fixed 4 MHz clock.
        \nLFCLK - Fixed 32 kHz clock.`,
                            default: "BUSCLK",
                            options: [
                                { name: "BUSCLK", displayName: "BUSCLK" },
                                { name: "MFCLK", displayName: "MFCLK" },
                                { name: "LFCLK", displayName: "LFCLK" },
                            ],
                            onChange: (inst,ui) => {
                                ui.busClockSource.hidden = (inst.clockSource != "BUSCLK");
                            }
                        },
                        {
                            name: "busClockSource",
                            displayName: "Select Source of Bus Clock",
                            description: "Bus Clock Source",
                            longDescription:`Only include QEI timer instances in power domain selected. This is only needed when BUSCLK is used as the timer
                            source since max speed of the clock will differ.`,
                            default: "ULPCLK",
                            hidden      : false,
                            options: [
                                { name: "MCLK", displayName: "MCLK - PD1" },
                                { name: "ULPCLK", displayName: "ULPCLK - PD0" },
                            ],
                            getValue: (inst) => {
                                let retVal = "ULPCLK";
                                let powerPolicy = "";
                                try{
                                    let peripheralIndex = system.deviceData.interfaces.GPTIMER.peripherals.findIndex(object => { return object.name === inst.peripheral.$solution.peripheralName });
                                    powerPolicy = system.deviceData.interfaces.GPTIMER.peripherals[peripheralIndex].attributes.power_domain;
                                }catch (e) {
                                    // do nothing
                                }
                                // Power Domain 0
                                if(powerPolicy == "PD_ULP_AON"){
                                    retVal = "ULPCLK";
                                }
                                // Power Domain 1
                                else if(powerPolicy == "PD_ULP_AAON"){
                                    retVal = "MCLK"
                                }
                                return retVal;
                            },
                        },
                        {
                            name: "inputClock_Freq",
                            hidden: true,
                            default: 0,
                            getValue: (inst,ui) => {
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
                            ]
                        },
                        {
                            name: "clockPrescale",
                            displayName: "Timer Clock Prescale",
                            description: "Selects the timer module clock prescaler. Valid range 1-256",
                            longDescription:  `The clock prescale reduces the timer clock frequency by a factor of 1 (none) to 256.
                            \nClock Frequency = Input Clock Frequency / ( divider * (prescale))`,
                            default: 1,
                            isInteger: true,
                            range: [1, 256]
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
                                    displayName: "Calculated Timer Frequency (Hz)",
                                    description: "Clock Frequency at which the timer will be decremented/incremented",
                                    longDescription: `This is the clock frequency that is seen by the timer count register. It is after the input clock has been
                                    divided and prescaled`,
                                    default: 0,
                                    getValue: (inst) => {
                                            return inst.inputClock_Freq / (inst.clockDivider * (inst.clockPrescale));
                                    }
                                },
                            ],
                        },
                        {
                            name        : "timerStartTimer",
                            displayName : 'Start Timer',
                            description : 'Start Timer',
                            longDescription: `The timer will start
                            counting after the call for DL_TimerX_startCounter.`,
                            hidden      : false,
                            default     : false,
                        },
                    ],
                },
                {
                    name: "GROUP_QEI_CONFIG",
                    displayName: "QEI Configuration",
                    description: "",
                    longDescription: "",
                    collapsed: false,
                    config: [
                        {
                            name        : "enableIndexInput",
                            displayName : "Enable QEI 3 Pin Mode",
                            description : 'Enable Index Input (3 Pin Mode)',
                            longDescription: `Enable Index Input (3 Pin Mode)`,
                            hidden      : false,
                            default     : false,
                        },
                        {
                            name        : "enableHallInput",
                            displayName : "Enable QEI Hall Input Mode",
                            description : 'Enable QEI Hall Input Mode',
                            longDescription: `Enable QEI Hall Input Mode`,
                            hidden      : false,
                            default     : false,
                        },
                        {
                            name        : "loadValue",
                            displayName : "Load Value",
                            description : 'The value to set the LOAD register to',
                            longDescription: `The contents of LOAD register are copied to CTR on any operation designated to do a "LOAD". The LOAD is
used to compare with the CTR for generating a "Load Event" that can be used for interrupt, trigger, or signal
generator actions.`,
                            default     : 0xFFFF,
                            isInteger   : true,
                            range       : [0x1, 0xFFFF],
                            hidden      : false,
                        },
                    ],
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
            config: [
                {
                    name: "crossTriggerEn",
                    displayName: "Enable Cross Trigger",
                    description: "Enable the ability to have this GP timer trigger or be triggered by another module or hardware element",
                    longDescription: `The cross trigger feature can be used to trigger more than one timer module to start counting simultaneously`,
                    default: false,
                    readOnly: true,
                    hidden: true,
                    // onChange: onChangeCrossTrigger
                },
                {
                    name: "crossTriggerAuthority",
                    displayName: "Cross Trigger Configuration",
                    description: "Determines Cross Trigger Function",
                    longDescription: `Determines if the timer will Trigger other modules and/or be triggered by other modules.`,
                    default: "Secondary",
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
                            \n Software Describes a cause that is linked to the code and writing to a register`,
                            hidden: true,
                            default: "SW",
                            options: [
                                {name: "SW", displayName: "Software"},
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
                                return optionsGetCrossTriggerTimerInstances(inst, "InputTrigger");
                            },
                            onChange: onChangeCrossTrigger,
                        },
                    ]
                },
                {
                    name: "GROUP_RETENTION",
                    displayName: "Retention Configuration",
                    description: "",
                    longDescription: ``,
                    collapsed: false,
                    config: retentionConfig,
                },
            ]
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
                    onChange: (inst, ui) => {
                        ui.interruptPriority.hidden = (inst.interrupts.length === 0);
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
                    options: (inst) => {
                        return EVENT.getPublisherOptions(inst);
                    },
                    getDisabledOptions: (inst) => {
                        return EVENT.getPublisherDisabledOptions(inst);
                    },
                    onChange: (inst,ui) => {
                        ui.event1ControllerInterruptEn.hidden = (inst.event1PublisherChannel == 0);
                    }
                },
                {
                    name: "event1ControllerInterruptEn",
                    displayName: "Event 1 Enable Controller Interrupts",
                    description: "Determines the Timer Events that will trigger an Event 1 condition",
                    longDescription: `Selects all possible timer Events that will create an Event 1 condition`,
                    hidden: true,
                    default: [],
                    options: getEventOptions
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
                        if(result.length == 0){
                            result = [""];
                        }
                        return result;
                    }
                }

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
    /* CCP0 */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   true,    "ccp0Pin",
     "PHA", "Capture/Compare Pin 0",
     "INPUT");
    /* CCP1 */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   true,    "ccp1Pin",
     "PHB", "Capture/Compare Pin 1",
     "INPUT");
    /* IDX */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   inst.enableIndexInput,    "idxPin",
     "IDX", "IDX Pin",
     "INPUT");

    return (modInstances);
}

let devSpecific = {

    config: config,

    maxInstances: 1,

    /* override generic requirements with  device-specific reqs (if any) */
    validate: validate,

    validatePinmux: validatePinmux,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    moduleInstances: moduleInstances,

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/qei/QEI.Board.c.xdt",
        boardh: "/ti/driverlib/qei/QEI.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true,
        Retention: Common.isDeviceM0G(),

    },

    _getPinResources: _getPinResources
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
