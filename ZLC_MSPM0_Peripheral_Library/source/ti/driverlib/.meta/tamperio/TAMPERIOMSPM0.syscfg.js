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
 *  ======== TAMPERIOMSPM0.syscfg.js ========
 */

"use strict";
let Common = system.getScript("/ti/driverlib/Common.js");
let EVENT = system.getScript("/ti/driverlib/EVENT.syscfg.js");

//TODO: Paramterize based on number tamper, defaulting to 3 for now
let tamperPinConfigs = [];
for(let i = 0; i < 3; i++) {
    let pin = "tio" + i.toString();
    let pinConfig = [
    {
        name: pin + "direction",
        displayName: "Direction",
        hidden: true,
        default: "INPUT",
        options: [
            { name: "INPUT", displayName: "Input" },
            { name: "OUTPUT", displayName: "Output" }
        ],
        onChange: updateGUIBasedOnPinConfig
    },
    {
        name: pin + "polarityEnable", // INPUT only
        displayName: "Polarity Detection",
        description: "Enables and configures edge detection polarity for TIO",
        hidden: true,
        default: "DISABLED",
        options: [
            {name: "DISABLED", displayName: "Edge detection disabled"},
            {name: "RISE", displayName: "Detects rising edge of input event"},
            {name: "FALL", displayName: "Detects falling edge of input event"},
            {name: "BOTH", displayName: "Detects both rising and falling edges"},
        ],
    },
    {
        name: pin + "outputInversion", // OUTPUT only
        displayName: "Output Inversion Enable",
        description: "Enables Output Inversion",
        hidden: true,
        default: "DISABLE",
        options: [
            {name: "DISABLE", displayName: "Disabled"},
            {name: "ENABLE", displayName: "Enabled"},
        ],
    },
    {
        name: pin + "toutControl", // OUTPUT only
        displayName: "Tamper Output Control",
        description: "Selects the source for the TOUT control",
        hidden: true,
        default: "TOUT",
        options: [
            {name: "TOUT", displayName: "TOUT Register"},
            {name: "LFCLK", displayName: "LFCLK Output"},
            {name: "HEARTBEAT", displayName: "Heart Beat Generator"},
            {name: "TIME_STAMP_EVENT", displayName: "Time Stamp Event Status"}
        ],
        onChange: updateGUIBasedOnPinConfig
    },
    {
        name: pin + "initialValue",
        displayName: "Initial Value",
        description: "Initial Output Value for the pin, set or cleared before enabling.",
        longDescription: `Sets the initial state of a pin when configured as an output.
        The state also depends on other IOMUX configuration settings, such as Invert and High-Impedance
        `,
        hidden: true,
        default: "CLEARED",
        options: [
            {name: "CLEARED", displayName: "Cleared" },
            {name: "SET", displayName: "Set" },
        ]
    },
    {
        name: pin + "CONFIG_FEATURE_GROUP",
        displayName: "Advanced Configuration",
        longDescription: "Various configuration settings for TIO",
        config: [
            {
                name: pin + "internalResistor", // Both INPUT/OUTPUT
                displayName: "Internal Resistor",
                description: "Optional Internal Resistor to add to GPIO",
                hidden: true,
                default: "NONE",
                options: [
                    {name: "NONE", displayName: "No Resistor"},
                    {name: "PULL_UP", displayName: "Pull-Up Resistor"},
                    {name: "PULL_DOWN", displayName: "Pull-Down Resistor"}
                ],
            },
            {
                name: pin + "filterEnable", // INPUT only
                displayName: "Digital Glitch Filter Enable",
                description: "Sets the counter length of digital glitch filter for TIO",
                hidden: true,
                default: "NONE",
                options: [
                    {name: "NONE", displayName: "No filter beyond CDC synchronization sample"},
                    {name: "30_USEC", displayName: "1 LFCLK minimum sample (30us)"},
                    {name: "100_USEC", displayName: "3 LFCLK minimum samples (100 us)"},
                    {name: "200_USEC", displayName: "6 LFCLK minimum samples (200 us)"},
                ],
            },
        ]
    },
    ]
    tamperPinConfigs.push(pinConfig);
}

/* For now, this on change function loops through all tamper pins
   even though at any given time only one pin is changing. I added
   a check to determine if the pin is even enabled, but ultimately this function
   may need to be abstracted to having one per pin. From what I see, there is also
   no good way to pass around which pin is being changed, which would solve the problem.
*/
function updateGUIBasedOnPinConfig(inst, ui) {
    //TODO: Parametrize based on number of tampers
    for(let i = 0; i < 3; i++) {
        let pin = "tio" + i.toString();
        //Pin not enabled -> hide all configs
        if(!inst["enable" + pin]) {

            ui[pin + "polarityEnable"].hidden = true;
            ui[pin + "filterEnable"].hidden = true;
            ui[pin + "toutControl"].hidden = true;
            ui[pin + "initialValue"].hidden = true;
            ui[pin + "direction"].hidden = true;
            ui[pin + "internalResistor"].hidden = true;
        }
        else {
            ui[pin + "direction"].hidden = false;
            ui[pin + "internalResistor"].hidden = false;
            //GUI for an input pin
            if(inst[pin + "direction"] === "INPUT") {
                ui[pin + "polarityEnable"].hidden = false;
                ui[pin + "filterEnable"].hidden = false;
                //Hide all output specifics
                ui[pin + "toutControl"].hidden = true;
                ui[pin + "initialValue"].hidden = true;
            }
            //GUI for an output pin
            else if(inst[pin + "direction"] === "OUTPUT") {
                ui[pin + "toutControl"].hidden = false;
                //Hide all input specific options
                ui[pin + "polarityEnable"].hidden = true;
                ui[pin + "filterEnable"].hidden = true;
                //TOUT Control Options
                if(inst[pin + "toutControl"] === "TOUT") {
                    ui[pin + "initialValue"].hidden = false;
                }
                else if(inst[pin + "toutControl"] === "HEARTBEAT") {
                    ui[pin + "initialValue"].hidden = true;
                }
                else if(inst[pin + "toutControl"] === "LFCLK") {
                    ui[pin + "initialValue"].hidden = true;
                }
                else if(inst[pin + "toutControl"] === "TIME_STAMP_EVENT") {
                    ui[pin + "initialValue"].hidden = true;
                }
            }
        }
    }
}

function updateGUIInterrupts(inst, ui){
    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
}

/************************ Options **********************************/
function getIntOptions(inst, ui)
{
    let allOptions = [];
    for(let i = 0; i < 3; i++) {
        let pin = "tio" + i.toString();
        allOptions = allOptions.concat([{name: "TAMPERIO_" + i.toString(), displayName: "Tamper I/O " + i.toString() + " interrupt"}]);
    }
    return allOptions;
}

function getDisabledIntOptions(inst) {
    let disabledOptions = [];
    for(let i = 0; i < 3; i++) {
        let pin = "tio" + i.toString();
        if(!inst["enable" + pin] || inst[pin + "direction"] === "OUTPUT") {
            disabledOptions.push({name: "TAMPERIO_" + i.toString(), reason: "Tamper I/O is not enabled as an input" });
        }
    }
    return disabledOptions;
}

function getEventOptions(inst, ui)
{
    let allOptions = [];
    for(let i = 0; i < 3; i++) {
        let pin = "tio" + i.toString();
        allOptions = allOptions.concat([{name: "TAMPERIO_" + i.toString(), displayName: "Tamper I/O " + i.toString() + " event"}]);
    }
    return allOptions;
}

function getDisabledEventOptions(inst) {
    let disabledOptions = [];
    for(let i = 0; i < 3; i++) {
        let pin = "tio" + i.toString();
        if(!inst["enable" + pin] || inst[pin + "direction"] === "OUTPUT") {
            disabledOptions.push({name: "TAMPERIO_" + i.toString(), reason: "Tamper I/O is not enabled as an input" });
        }
    }
    return disabledOptions;
}

let tamperioConfig = [
    {
        name: "Tamper I/0 Configuration",
        displayName: "Tamper I/0 Configuration",
        collapsed: false,
        config: [
            {
                name: "enabletio0",
                displayName: "Enable Tamper I/0 0",
                description: "Enables Tamper I/0 0 to be used",
                longDescription: ``,
                default: false,
                onChange: updateGUIBasedOnPinConfig
            },
            {
                name: "tio0Config",
                displayName: "Pin Configuration",
                description: "",
                longDescription: ``,
                collapsed: false,
                config: tamperPinConfigs[0]
            },
            {
                name: "enabletio1",
                displayName: "Enable Tamper I/0 1",
                description: "Enables Tamper I/0 1 to be used",
                longDescription: ``,
                default: false,
                onChange: updateGUIBasedOnPinConfig
            },
            {
                name: "tio1Config",
                displayName: "Pin Configuration",
                description: "",
                longDescription: ``,
                collapsed: false,
                config: tamperPinConfigs[1]
            },
            {
                name: "enabletio2",
                displayName: "Enable Tamper I/0 2",
                description: "Enables Tamper I/0 2 to be used",
                longDescription: ``,
                default: false,
                onChange: updateGUIBasedOnPinConfig
            },
            {
                name: "tio2Config",
                displayName: "Pin Configuration",
                description: "",
                longDescription: ``,
                collapsed: false,
                config: tamperPinConfigs[2]
            },
        ]
    },
    {
        name: "HEARTBEAT_CONFIG",
        displayName: "Heart Beat Configuration",
        longDescription: "This section allows configuring of the heart beat generator for the TAMPERIOs",
        collapsed: true,
        config: [
            {
                name: "heartBeatMode", //OUTPUT only
                displayName: "Heart Beat Mode",
                description: "Selects the type of Heart Beat Mode used",
                hidden: false,
                default: "DISABLED",
                options: [
                    {name: "DISABLED", displayName: "Disabled"},
                    {name: "ALWAYS_ON", displayName: "Always On"},
                    {name: "TIME_STAMP", displayName: "On Following Time Stamp Event"},
                    {name: "POWER_FAIL", displayName: "On Following Power Fail"}
                ],
                onChange: updateGUIBasedOnPinConfig
            },
            {
                name: "startHeartBeat", //OUTPUT only
                displayName: "Start Heart Beat",
                description: "Configures the Heart Beat to start",
                hidden: false,
                default: false,
                onChange: updateGUIBasedOnPinConfig
            },
            {
                name: "heartBeatPWM",
                displayName: "Heart Beat PWM",
                description: "Sets PWM for Heart Beat Mode",
                hidden: false,
                default: "1_MSEC",
                options: [
                    {name: "1_MSEC", displayName: "1 Millisecond"},
                    {name: "2_MSEC", displayName: "2 Milliseconds"},
                    {name: "4_MSEC", displayName: "4 Milliseconds"},
                    {name: "8_MSEC", displayName: "8 Milliseconds"},
                    {name: "16_MSEC", displayName: "16 Milliseconds"},
                    {name: "32_MSEC", displayName: "32 Milliseconds"},
                    {name: "64_MSEC", displayName: "64 Milliseconds"},
                    {name: "128_MSEC", displayName: "128 Milliseconds"},
                ],
            },
            {
                name: "heartBeatInterval",
                displayName: "Heart Beat Interval",
                description: "Sets the Interval for Heart Beat Mode",
                hidden: false,
                default: "0_125_SEC",
                options: [
                    {name: "0_125_SEC", displayName: "0.125 Seconds"},
                    {name: "0_25_SEC", displayName: "0.25 Seconds"},
                    {name: "0_5_SEC", displayName: "0.5 Seconds"},
                    {name: "1_SEC", displayName: "1 Second"},
                    {name: "2_SEC", displayName: "2 Seconds"},
                    {name: "4_SEC", displayName: "4 Seconds"},
                    {name: "8_SEC", displayName: "8 Seconds"},
                    {name: "16_SEC", displayName: "16 Seconds"},
                ],
            },
        ]
    },
    {
        name: "GROUP_INTERRUPTS",
        displayName: "Interrupt Configuration",
        longDescription: "This section allows enabling/disabling Tamper I/O interrupts",
        collapsed: true,
        config: [
            {
                name        : "enabledInterrupts",
                displayName : "Enable Interrupts",
                description : 'Enable Tamper I/O interrupt',
                default     : [],
                minSelections : 0,
                options     : getIntOptions,
                getDisabledOptions: getDisabledIntOptions,
                onChange    : (inst, ui) => {
                    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
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
        name: "GROUP_EVENTS",
        displayName: "Event Configuration",
        longDescription: "This section allows enabling/disabling Tamper I/O events",
        collapsed: true,
        config: [
            {
                name        : "enabledEvents",
                displayName : "Enable Events",
                description : 'Enable Tamper I/O event',
                default     : [],
                minSelections : 0,
                options     : getEventOptions,
                getDisabledOptions: getDisabledEventOptions,
                onChange    : (inst, ui) => {
                    ui.interruptPriority.hidden = (inst.enabledEvents.length === 0);
                }
            },
            {
                name        : "pubChanID",
                displayName : "Event Publisher Channel ID",
                description : 'Sets the event publisher channel id',
                hidden      : false,
                default: 0,
                options: EVENT.getPublisherOptions,
                getDisabledOptions: EVENT.getPublisherDisabledOptions,
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
                    return options;
                },
                getValue: (inst) => {
                    let result = [];
                    if(inst.pubChanID != 0){
                        result.push(inst.pubChanID.toString() + "pub");
                    }
                    if(result.length == 0){
                        result = [""];
                    }
                    return result;
                }
            },
        ]
    }
];


/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base GPIO configuration
 */
let devSpecific = {
    config: tamperioConfig,

    //TODO: Wait for update to device data to filter pins for tamper
    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    validate: validate,

    modules: setRequiredModules,

    //_getPinResources: _getPinResources
};


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
   return true;
}

const memoizedTamperFilter = _.memoize(curryGPIOFilter, (validPinSet) => JSON.stringify(validPinSet));

function curryGPIOFilter(validPinSet) {
	return (devicePin, peripheralPin) => GPIOFilter(devicePin, validPinSet);
}

function GPIOFilter(devicePin, validPinSet) {
    return validPinSet.includes(devicePin.name);
}

function setRequiredModules(inst){
    let theModules = ["Board", "SYSCTL"]

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

function pinmuxRequirements(inst)
{
    let validPinTamper0Set = [];
    let validPinTamper1Set = [];
    let validPinTamper2Set = [];

    for(let pinIdx in system.deviceData.gpio.pinInfo){
        let pin = system.deviceData.gpio.pinInfo[pinIdx];
        if(pin.peripheralPin.name === "PA7" && inst.enabletio0)
            validPinTamper0Set.push(pinIdx);
        if(pin.peripheralPin.name === "PB2" && inst.enabletio1)
            validPinTamper1Set.push(pinIdx);
        if(pin.peripheralPin.name === "PB3" && inst.enabletio2)
            validPinTamper2Set.push(pinIdx);
    }


    let tio0_pin = {
        name: "tio0_pin",
        displayName: "Tamper IO 0",
        interfaceName: "GPIO",
        filter: memoizedTamperFilter(validPinTamper0Set)
    };

    let tio1_pin = {
        name: "tio1_pin",
        displayName: "Tamper IO 1",
        interfaceName: "GPIO",
        filter: memoizedTamperFilter(validPinTamper1Set)
    };

    let tio2_pin = {
        name: "tio2_pin",
        displayName: "Tamper IO 2",
        interfaceName: "GPIO",
        filter: memoizedTamperFilter(validPinTamper2Set)
    };

    let pins = []
    if(inst.enabletio0) pins.push(tio0_pin);
    if(inst.enabletio1) pins.push(tio1_pin);
    if(inst.enabletio2) pins.push(tio2_pin);

    let lfss = {
        name          : "peripheral",
        displayName   : "LFSS Peripheral",
        interfaceName : "LFSS",
        canShareWith  : "LFSS",
        resources     : []
    };
    return [lfss].concat(pins);
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
    validation.logWarning("Note: VBAT needs to be powered for Tamper I/O operation.", inst);

    if(inst.enabletio0 && inst.tio0toutControl == "HEARTBEAT" && inst.startHeartBeat == false) {
        validation.logInfo(
            "The heart beat generator will not start unless enabled below in heart beat configuration.",
            inst,
            ["tio0toutControl"]
        );
    }
    if(inst.enabletio1 && inst.tio1toutControl == "HEARTBEAT" && inst.startHeartBeat == false) {
        validation.logInfo(
            "The heart beat generator will not start unless enabled below in heart beat configuration.",
            inst,
            ["tio1toutControl"]
        );
    }
    if(inst.enabletio2 && inst.tio2toutControl == "HEARTBEAT" && inst.startHeartBeat == false) {
        validation.logInfo(
            "The heart beat generator will not start unless enabled below in heart beat configuration.",
            inst,
            ["tio2toutControl"]
        );
    }
    if(inst.startHeartBeat == true) {
        validation.logInfo(
            "Starting the heat beat generator enables the RTC_A clock and will start any configured calendar alarms.",
            inst,
            ["startHeartBeat"]
        );
    }
}

function validatePinmux(inst, validation)
{
    /* Check input IOMux parameters based on what the pin is capable of */
    /* Look for IOMux Structure */
}

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
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic GPIO module to
 *  allow us to augment/override as needed for MSPM0
 */
function extend(base)
{
    /* Special static extend */
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    /* moduleStatic specific to  as it's statically defined */
    result.config = base.moduleStatic.config.concat(devSpecific.config);
    base.moduleStatic = result;

    return (base);
}

/*
 *  ======== exports ========
 *  Export device-specific extensions to base exports
 */
exports = {
    extend: extend
};
