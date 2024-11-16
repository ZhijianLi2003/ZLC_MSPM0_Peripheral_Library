/*
 * Copyright (c) 2023 Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== GPAMPMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/************************* General functions *******************************/
function hasMuxablePins(interfaceName, pinName) {
    /*
     * _.some returns true if the function supplied in the second parameter
     *  returns true for any element)
     */

    const interfacePin = system.deviceData.interfaces[interfaceName].interfacePins[pinName];
    return _.some(interfacePin.pinMappings, (peripheralPin) => peripheralPin.pinMappings.length !== 0);
}

/************************* Profiles functions *******************************/
const profilesGPAMP = [
    {
        /* GENERAL PURPOSE RRI mode, chopping enabled*/
        name                    : "CONFIG_PROFILE_1",
        advRRI                  : "RAIL_TO_RAIL",
        cfgPSELChannel          : "IN_POS",
        cfgNSELChannel          : "IN_NEG",
        cfgOutputPin            : "ENABLED",
        cfgChoppingMode         : "STANDARD",
        cfgChoppingFreq         : "4KHZ",
    },
    {
        /* ADC BUFFER MODE, ADC-assisted chopping */
        name                    : "CONFIG_PROFILE_2",
        advRRI                  : "PMOS_INPUT",
        cfgPSELChannel          : "IN_POS",
        cfgNSELChannel          : "INTERNAL_OUTPUT",
        cfgOutputPin            : "DISABLED",
        cfgChoppingMode         : "ADC_ASSISTED",
        cfgChoppingFreq         : "16KHZ",
    },
    {
        /* Unity Gain Mode */
        name                    : "CONFIG_PROFILE_3",
        advRRI                  : "PMOS_INPUT",
        cfgPSELChannel         : "IN_POS",
        cfgNSELChannel         : "OUTPUT_PIN",
        cfgOutputPin           : "ENABLED",
        cfgChoppingMode         : "DISABLED",
        cfgChoppingFreq         : "16KHZ",
    },
];

function onChangeGPAMPProfile(inst, ui) {
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = profilesGPAMP.filter(obj =>
                                        {return obj.name === inst.profile});
        if (selectedProfileArray.length != 0)
        {
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            //selectedProfile = selectedProfile[0];
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
        updateGUIbasedonConfig(inst, ui);
    }
}

function updateGUIbasedonConfig(inst, ui)
{
    updateGUIChoppingMode(inst, ui);
}

function updateGUIChoppingMode(inst, ui)
{
    if (inst.cfgChoppingMode == "DISABLED")
    {
        ui.cfgChoppingFreq.hidden = true;
    }
    else
    {
        ui.cfgChoppingFreq.hidden = false;
    }
}

function onChangeSetCustomProfile(inst,ui){
    inst.profile = "CUSTOM";
}

/************************* Basic functions *******************************/
/* onChange functions for Basic Configuration */
function onChangeCfgPSELChannel(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeCfgNSELChannel(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeCfgOutputEnable(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeCfgChoppingMode(inst, ui)
{
    updateGUIChoppingMode(inst, ui);
    onChangeSetCustomProfile(inst, ui);

}

function onChangeCfgChoppingFreq(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/************************* Advanced functions *******************************/
/* onChange functions for Advanced Configuration */
function onChangeAdvRRI(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/************************Interrupt Functions **********************************/

/************************* General functions **********************************/

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
}

const PSELChOptions = [
    {name: "OPEN", displayName: "Open"},
    {name: "IN_POS", displayName: "GPAMP_IN+ pin"},
];


function getPSELChDisabledOptions(inst)
{
    let disabledOptions = [];

    if (!hasMuxablePins("GPAMP", "IN+"))
    {
        disabledOptions.push({name: "IN_POS",
                              displayName: "IN+ pin not available",
                              reason: "IN+ pin is not available"});
    }
    return disabledOptions;
}

const NSELChOptions = [
    {name: "OPEN", displayName: "Open"},
    {name: "OUTPUT_PIN", displayName: "GPAMP_OUT pin"},
    {name: "IN_NEG", displayName: "GPAMP_IN- pin"},
    {name: "INTERNAL_OUTPUT", displayName: "Internal GPAMP output"},
];

function getNSELChDisabledOptions(inst)
{
    let disabledOptions = [];

    if (!hasMuxablePins("GPAMP", "IN-"))
    {
        disabledOptions.push({name: "IN_NEG",
                              displayName: "IN- pin not available",
                              reason: "IN- pin is not available"});
    }
    return disabledOptions;
}

/* PROFILES CONFIGURATION */
let gpampConfig = [
    /****** PROFILES CONFIGURATION *******/
    {
        name: "GROUP_PROFILE",
        displayName: "Quick Profiles",
        description: "",
	    collapsed: false,
        config: [
            {
                name        : "profile",
                displayName : "GPAMP Profiles",
                description : 'Pre-defined profiles for typical GPAMP configurations',
                longDescription: `
The GPAMP is a chopper stabilized general purpose operational amplifier with
rail-to-rail input and output.

![GPAMP Block Diagram](../docs/english/sysconfig/images/gpAmpBlockDiagM0G3xx.png "GPAMP Block Diagram")

The Quick Profile Options are:
* **General Purpose RRI mode with standard chopping**:
    * Inputs: IN+/IN-
    * Output: enabled
    * Chopping: standard at 4kHz
    * Rail-to-Rail: enabled
* **ADC Buffer mode, ADC-assisted chopping**:
    * Inputs: IN+, inverting connected to internal GPAMP output
    * Output: disabled
    * Chopping: ADC-assisted
    * Rail-to-Rail: disabled
* **Unity-Gain mode**:
    * Inputs: IN+, inverting connected to GPAMP OUT
    * Output: enabled
    * Chopping: disabled
    * Rail-to-Rail: disabled
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "CUSTOM",
                options     : [
                    {name: "CONFIG_PROFILE_1", displayName: "General Purpose RRI mode with standard chopping"},
                    {name: "CONFIG_PROFILE_2", displayName: "ADC Buffer mode, ADC-assisted chopping"},
                    {name: "CONFIG_PROFILE_3", displayName: "Unity-Gain mode"},
                    {name: "CUSTOM", displayName: "Custom"},
                ],
                onChange    : onChangeGPAMPProfile,
            },
        ],
    },
]

gpampConfig = gpampConfig.concat([
    {
        name: "GROUP_BASIC",
        displayName: "Basic Configuration",
        description: "",
        longDescription:
`Basic GPAMP options allow configuration of the inputs, output, and chopping mode.
`,
        collapsed: false,
        config: [
            {
                name        : "cfgPSELChannel",
                displayName : "Non-Inverting Channel (PCHENABLE)",
                description : 'Select the channel to GPAMP Non-Inverting input (PCHENABLE)',
                longDescription:`
The GPAMP non-Inverting channel can be configured from the following sources:
* Open
* GPAMPx_IN+ pin\n
Refer to block diagram in Quick Profiles to review connections.\n
**Note: Some pins might not be available on the device. The PinMux section will
highlight any conflicts.**
        `,
                hidden      : false,
                default     : "OPEN",
                options     : PSELChOptions,
                getDisabledOptions: getPSELChDisabledOptions,
                onChange    : onChangeCfgPSELChannel,
            },
            {
                name        : "cfgNSELChannel",
                displayName : "Inverting Channel (NSEL)",
                description : 'Selects the channel to GPAMP Inverting input (NSEL)',
                longDescription:`
The GPAMP Inverting channel (NSEL) can be configured from the following sources:
* Open
* GPAMPx IN- pin
* GPAMP_OUT pin
* GPAMP internal output\n
Refer to block diagram in Quick Profiles to review connections.\n
**Note: Some pins might not be available on the device. The PinMux section will
highlight any conflicts.**
        `,
                hidden      : false,
                default     : "OPEN",
                options     : NSELChOptions,
                getDisabledOptions: getNSELChDisabledOptions,
                onChange    : onChangeCfgNSELChannel,
            },
            {
                name        : "cfgOutputPin",
                displayName : "GPAMP Output Pin Enable",
                description : 'GPAMP Output Pin Enable',
                longDescription:`
The GPAMP output can be enabled or disabled.\n
Refer to block diagram in Quick Profiles to review connections.
**Note: Some pins might not be available on the device. The PinMux section will
highlight any conflicts.**
`,
                hidden      : false,
                default     : "DISABLED",
                options     : [
                    {name: "DISABLED", displayName: "Output disabled"},
                    {name: "ENABLED", displayName: "Output enabled"},
                ],
                onChange    : onChangeCfgOutputEnable,
            },
            {
                name        : "cfgChoppingMode",
                displayName : "Chopping Configuration",
                description : 'Configures chopping mode',
                longDescription:`
The GPAMP peripheral implements chopper stabilization in order to reduce
offset, drift, and 1/f noise.\n
**Standard chopping mode** requires an external filter. See device specific
datasheet for recommended values.\n
The chopping frequency needs to scale down as the gain increases. See more
information in Chopping Frequency parameter.\n
The disadvantage of standard chopping is that it results in AC ripple at the
chopping frequency, but that's not a problem for applications where this can be filtered out.\n
**ADC Assisted mode** can be used if the GPAMP output goes to an ADC input, and
the ADC has hardware averaging.\n
An external filter is not needed in this mode, and instead of a clock being
used for chopping, the ADC provides a control signal to act as the clock and
change the chopping mode before each ADC sample so the averaging does the
"filtering".\n
See the device specific datasheet for electrical performance with and without
chopping.\n
`,
                hidden      : false,
                default     : "DISABLED",
                options     : [
                    {name: "DISABLED", displayName: "Chopping disabled"},
                    {name: "STANDARD", displayName: "Standard chopping mode"},
                    {name: "ADC_ASSISTED", displayName: "ADC-assisted chopping mode"},
                ],
                onChange    : onChangeCfgChoppingMode,
            },
            {
                name        : "cfgChoppingFreq",
                displayName : "Chopping Frequency",
                description : 'Configures chopping frequency',
                longDescription:`
The chopping frequency, needs to scale down as the gain increases as shown:\n
        External Gain         Chopping Frequency
        -1x/2x                 16kHz
        -3x/4x                 8kHz
        -7x/8x                 4kHz
        -15x/16x               2kHz
`,
                hidden      : true,
                default     : "16KHZ",
                options     : [
                    {name: "16KHZ", displayName: "16kHz"},
                    {name: "8KHZ", displayName: "8kHz"},
                    {name: "4KHZ", displayName: "4kHz"},
                    {name: "2KHZ", displayName: "2kHz"},
                ],
                onChange    : onChangeCfgChoppingFreq,
            },
        ],
    },

])

gpampConfig = gpampConfig.concat([
    {
        name: "GROUP_ADVANCED",
        displayName: "Advanced Configuration",
        description: "",
        longDescription:
`Advanced options configure Rail-to-Rail mode.`,
	    collapsed: true,
        config: [
            {
                name: "advRRI",
                displayName: "Rail-to-Rail Mode",
                description: "Configures Rail-to-Rail",
                longDescription: `
In some basic signal conditioning applications, rail-to-rail input is not
required and thus can be disabled to reduce overall power consumption.\n
Rail-to-rail input can be disabled by configuring Mode 0.\n
Refer to the GPAMP specifications in the device specific datasheet for
supported common-mode input ranges in the various RRI modes.
`,
                default: "PMOS_INPUT",
                options     : [
                    {name: "PMOS_INPUT", displayName: "Mode0/Disabled"},
                    {name: "NMOS_INPUT", displayName: "Mode1"},
                    {name: "RAIL_TO_RAIL", displayName: "Mode2"},
                    {name: "SAMPLE_CHANNEL_0", displayName: "Sample Channel 0"}
                ],
                onChange : onChangeAdvRRI,
            },

        ]
    },
])

/* Add Pinmux Peripheral Configuration group */
gpampConfig = gpampConfig.concat(Common.getGPIOGroupConfig());

function moduleInstances(inst){
    let modInstances = [];

    /*
     * Gets a Peripheral GPIO Configuration submodule
     */
    /* CONDITIONS CODE START */
    let pselConfig, nselConfig, OutConfig = false;
    if (inst["cfgPSELChannel"] == "IN_POS")
    {
        pselConfig = true;
    }
    if (inst["cfgNSELChannel"] == "IN_NEG")
    {
        nselConfig = true;
    }
    if (inst["cfgOutputPin"] == "ENABLED")
    {
        OutConfig = true;
    }
    /* CONDITIONS CODE END */
    /* IN- */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   nselConfig,    "InNegPin",
     "INNEG", "GPAMP Inverting input Pin",
     "INPUT");
    /* IN+ */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   pselConfig,    "InPosPin",
     "INPOS", "GPAMP Non-inverting input Pin",
     "INPUT");
    /* OUT */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   OutConfig,    "OutPin",
     "OUT", "GPAMP Output Pin",
     "OUTPUT");

    return modInstances;
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: gpampConfig,


    maxInstances: Common.peripheralCount("GPAMP"),

   /* override generic requirements with  device-specific reqs (if any) */
   validate: validate,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    moduleInstances: moduleInstances,

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/gpamp/GPAMP.Board.c.xdt",
        boardh: "/ti/driverlib/gpamp/GPAMP.Board.h.xdt",
        Call: true,
        Reset: false,
        Power: false,
        GPIO: true,
        Function: true

    },

    _getPinResources: _getPinResources
};



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

/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured module instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{
    let inneg = {
        name:"InNegPin",
        displayName:"GPAMP Inverting input Pin",
        interfaceNames:["IN-"],
    };
    let inpos = {
        name:"InPosPin",
        displayName:"GPAMP Non-inverting input Pin",
        interfaceNames:["IN+"],
    };
    let out = {
        name:"OutPin",
        displayName:"GPAMP Output Pin",
        interfaceNames:["OUT"],
    };
    let resources = [];

    if (inst["cfgPSELChannel"] == "IN_POS")
    {
        resources.push(inpos);
    }
    if (inst["cfgNSELChannel"] == "IN_NEG")
    {
        resources.push(inneg);
    }
    if (inst["cfgOutputPin"] == "ENABLED")
    {
        resources.push(out);
    }

    let gpamp = {
        name: "peripheral",
        displayName: "GPAMP Peripheral",
        interfaceName: "GPAMP",
        resources: resources,
        signalTypes: {
            InNegPin: ["IN-"],
            InPosPin: ["IN+"],
            OutPin: ["OUT"],
        }
    };

    return ([gpamp]);
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
        if (Common.typeMatches(type, ["GPAMP"])) modulePin = sig;
    }
    let result = modulePin ? true : false;

    return (result);
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
