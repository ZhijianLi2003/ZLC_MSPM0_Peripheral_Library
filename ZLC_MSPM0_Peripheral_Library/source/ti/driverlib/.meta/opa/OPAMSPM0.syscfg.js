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
 *  ======== OPAMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/************************Interrupt Functions **********************************/


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
const profilesOPA = [
    {
        /* GENERAL PURPOSE MODE */
        name                    : "CONFIG_PROFILE_1",
        advRRI                  : true,
        advBW                   : "HIGH",
        cfg0PSELChannel         : "IN0_POS",
        cfg0NSELChannel         : "IN0_NEG",
        cfg0MSELChannel         : "OPEN",
        cfg0Gain                : "N1_P2",
        cfg0OutputPin           : "ENABLED",
        cfg0Chop                : "DISABLE",
    },
    {
        /* BUFFER MODE */
        name                    : "CONFIG_PROFILE_2",
        advRRI                  : false,
        advBW                   : "LOW",
        cfg0PSELChannel         : "IN0_POS",
        cfg0NSELChannel         : "RTOP",
        cfg0MSELChannel         : "OPEN",
        cfg0Gain                : "N1_P2",
        cfg0OutputPin           : "DISABLED",
        cfg0Chop                : "STANDARD",
    },
    {
        /* DAC8 Output Buffer MODE */
        name                    : "CONFIG_PROFILE_3",
        advRRI                  : false,
        advBW                   : "HIGH",
        cfg0PSELChannel         : "DAC8_OUT",
        cfg0NSELChannel         : "RTOP",
        cfg0MSELChannel         : "OPEN",
        cfg0Gain                : "N1_P2",
        cfg0OutputPin           : "ENABLED",
        cfg0Chop                : "STANDARD",
    },
    {
        /* Inverting PGA with -1x using DAC8 as bias */
        name                    : "CONFIG_PROFILE_4",
        advRRI                  : false,
        advBW                   : "HIGH",
        cfg0PSELChannel         : "DAC8_OUT",
        cfg0NSELChannel         : "RTAP",
        cfg0MSELChannel         : "IN1_NEG",
        cfg0Gain                : "N1_P2",
        cfg0OutputPin           : "ENABLED",
        cfg0Chop                : "ADC_AVERAGING",
    },
    {
        /* 1st stage cascaded amplifier */
        name                    : "CONFIG_PROFILE_6",
        advRRI                  : false,
        advBW                   : "HIGH",
        cfg0PSELChannel         : "IN0_POS",
        cfg0NSELChannel         : "RTAP",
        cfg0MSELChannel         : "GND",
        cfg0Gain                : "N1_P2",
        cfg0OutputPin           : "DISABLED",
        cfg0Chop                : "DISABLE",
    },
    {
        /* 2nd stage cascaded amplifier */
        name                    : "CONFIG_PROFILE_7",
        advRRI                  : false,
        advBW                   : "HIGH",
        cfg0PSELChannel         : "RTOP",
        cfg0NSELChannel         : "RTAP",
        cfg0MSELChannel         : "GND",
        cfg0Gain                : "N1_P2",
        cfg0OutputPin           : "ENABLED",
        cfg0Chop                : "DISABLE",
    },
];

function onChangeOPAProfile(inst, ui) {
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = profilesOPA.filter(obj =>
                                        {return obj.name === inst.profile});
        if (selectedProfileArray.length != 0)
        {
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            //selectedProfile = selectedProfile[0];
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
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

function onChangeCfgMSELChannel(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeCfgGain(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeCfgOutputEnable(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeCfgChopping(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/************************* Advanced functions *******************************/
/* onChange functions for Advanced Configuration */
function onChangeAdvRRI(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvBW(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/************************Interrupt Functions **********************************/
function onChangeInt(inst, ui)
{
    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
    onChangeSetCustomProfile(inst, ui);
}

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


    /* VREF Validation */
    if(Common.isDeviceM0L()){
        if(["VREF"].includes(inst.cfg0PSELChannel)){
            // validate if A2 & VREF enabled, check that its not internal reference.
            let vrefInstance = system.modules["/ti/driverlib/VREF"];
            if (vrefInstance){
                if(!(vrefInstance.$static.basicMode).includes("DL_VREF_ENABLE_DISABLE"))
                validation.logError(
                    "Selected device does not support sourcing internal VREF for OPA.",
                    inst, "cfg0PSELChannel"
                );
            }
        }
    }

    if(Common.isDeviceM0G()){
        /* Special Case: DAC12 Validation */
        if(inst.cfg0PSELChannel == "DAC_OUT" || inst.cfg0MSELChannel == "DAC_OUT"){
            let DACMod = system.modules["/ti/driverlib/DAC12"];
            if (DACMod){
                let DACInst = DACMod.$static
                if (!DACInst.dacOutputPinEn){
                    if(inst.cfg0PSELChannel == "DAC_OUT"){
                        validation.logError("DAC Output Pin should be enabled when configured as Non-Inverting Channel.", inst, ["cfg0PSELChannel"]);
                    }
                    if(inst.cfg0MSELChannel == "DAC_OUT"){
                        validation.logError("DAC Output Pin should be enabled when configured as Input MUX.", inst, ["cfg0MSELChannel"]);
                    }
                }
            }
        }
    }
}

const PSELChOptions = [
    {name: "OPEN", displayName: "Open"},
    {name: "IN0_POS", displayName: "IN0+ pin"},
    {name: "IN1_POS", displayName: "IN1+ pin"},
    {name: "DAC_OUT", displayName: "DAC Output"},
    {name: "DAC8_OUT", displayName: "COMP.DAC8 Output"},
    {name: "VREF", displayName: "VREF"},
    {name: "RTOP", displayName: "OPA[x-1]_RTOP"},
    {name: "GPAMP_OUT", displayName: "GPAMP Output"},
    {name: "GND", displayName: "GND"},
];

function getPSELChDisabledOptions(inst)
{
    let disabledOptions = [];

    if (!hasMuxablePins("OA", "IN0+"))
    {
        disabledOptions.push({name: "IN0_POS",
                              displayName: "IN0+ pin not available",
                              reason: "IN0+ pin is not available"});
    }

    if (!hasMuxablePins("OA", "IN1+"))
    {
        disabledOptions.push({name: "IN1_POS",
                              displayName: "IN1+ pin not available",
                              reason: "IN1+ pin is not available"});
    }

    return disabledOptions;
}

const NSELChOptions = [
        {name: "OPEN", displayName: "Open"},
        {name: "IN0_NEG", displayName: "IN0- pin"},
        {name: "IN1_NEG", displayName: "IN1- pin"},
        {name: "RBOT", displayName: "OPA[x-1]_RBOT"},
        {name: "RTAP", displayName: "RTAP"},
        {name: "RTOP", displayName: "RTOP"},
];

function getNSELChDisabledOptions(inst)
{
    let disabledOptions = [];

    if (!hasMuxablePins("OA", "IN0-"))
    {
        disabledOptions.push({name: "IN0_NEG",
                              displayName: "IN0- pin not available",
                              reason: "IN0- pin is not available"});
    }

    if (!hasMuxablePins("OA", "IN1-"))
    {
        disabledOptions.push({name: "IN1_NEG",
                              displayName: "IN1- pin not available",
                              reason: "IN1- pin is not available"});
    }
    return disabledOptions;
}

const MSELChOptions = [
    {name: "OPEN", displayName: "Open"},
    {name: "IN1_NEG", displayName: "IN1- pin (Inverting amplifier)"},
    {name: "GND", displayName: "GND (NonInverting amplifier)"},
    {name: "DAC_OUT", displayName: "DAC Output"},
    {name: "RTOP", displayName: "OPA[x-1]_RTOP"},
];

function getMSELChDisabledOptions(inst)
{
    let disabledOptions = [];

    if (!hasMuxablePins("OA", "IN1-"))
    {
        disabledOptions.push({name: "IN1_NEG",
                              displayName: "IN1- pin not available",
                              reason: "IN1- pin is not available"});
    }
    return disabledOptions;
}

/*
function getGainOptions(inst)
{
    let posOptions = [
        {name: "N0_P1", displayName: "1x"},
        {name: "N1_P2", displayName: "2x"},
        {name: "N3_P4", displayName: "4x"},
        {name: "N7_P8", displayName: "8x"},
        {name: "N15_P16", displayName: "16x"},
        {name: "N31_P32", displayName: "32x"},
    ];
    let negOptions = [
        {name: "N0_P1", displayName: "Invalid"},
        {name: "N1_P2", displayName: "-1x"},
        {name: "N3_P4", displayName: "-3x"},
        {name: "N7_P8", displayName: "-7x"},
        {name: "N15_P16", displayName: "-15x"},
        {name: "N31_P32", displayName: "-31x"},
    ];
    let posnegOptions = [
        {name: "N0_P1", displayName: "Non-Inverting: 1x / Inverting: Invalid"},
        {name: "N1_P2", displayName: "Non-Inverting: 2x / Inverting: -1x"},
        {name: "N3_P4", displayName: "Non-Inverting: 4x / Inverting: -3x"},
        {name: "N7_P8", displayName: "Non-Inverting: 8x / Inverting: -7x"},
        {name: "N15_P16", displayName: "Non-Inverting: 16x / Inverting: -15x"},
        {name: "N31_P32", displayName: "Non-Inverting: 32x / Inverting: -31x"},
    ];

    return posnegOptions;
}
*/
const GainOptions = [
    {name: "N0_P1", displayName: "Non-Inverting: Not vaild / Inverting: Not valid"},
    {name: "N1_P2", displayName: "Non-Inverting: 2x / Inverting: -1x"},
    {name: "N3_P4", displayName: "Non-Inverting: 4x / Inverting: -3x"},
    {name: "N7_P8", displayName: "Non-Inverting: 8x / Inverting: -7x"},
    {name: "N15_P16", displayName: "Non-Inverting: 16x / Inverting: -15x"},
    {name: "N31_P32", displayName: "Non-Inverting: 32x / Inverting: -31x"},
];

function getOpaPresetConfig()
{
    let cfg = [
    {
        name        : "cfg0PSELChannel",
        displayName : "Non-Inverting Channel (PSEL)",
        description : 'Select the channel to OPA Non-Inverting input (PSEL)',
        longDescription:`
The OPA non-Inverting channel (PSEL)can be configured from the following sources:
* Open
* OPAx_IN0+ pin
* OPAx_IN1+ pin
* DAC_OUT
* DAC8.x_OUT, refers to COMP reference DAC
* VREF
* OPA[x-1]_RTOP, refers to instances where there are 2 OPAs in a device
* GPAMP_OUT
* GND\n
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
        name        : "cfg0NSELChannel",
        displayName : "Inverting Channel (NSEL)",
        description : 'Selects the channel to OPA Inverting input (NSEL)',
        longDescription:`
The OPA Inverting channel (NSEL) can be configured from the following sources:
* Open
* OPAx_IN0- pin
* OPAx_IN1- pin
* OPA[x-1]_RBOT, refers to instances where there are 2 OPAs in a device
* RTAP
* RTOP\n
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
        name        : "cfg0MSELChannel",
        displayName : "Input MUX (MSEL)",
        description : 'Selects the channel to the OPA Input MUX (MSEL)',
        longDescription:`
The OPA input MUX (MSEL) can be configured from the following sources:
* Open
* OPAx_IN1-
* GND
* DAC_OUT
* OPA[x-1]_RTOP, refers to instances where there are 2 OPAs in a device\n
Refer to block diagram in Quick Profiles to review connections.\n
**Note: Some pins might not be available on the device. The PinMux section will
highlight any conflicts.**
`,
        hidden      : false,
        default     : "OPEN",
        options     : MSELChOptions,
        getDisabledOptions: getMSELChDisabledOptions,
        onChange    : onChangeCfgMSELChannel,
    },
    {
        name        : "cfg0Gain",
        displayName : "Gain",
        description : 'Configure the gain',
        longDescription:`
The OPA integrates a programmable gain stage in the feedback loop.\n
The gain stage is a feedback resistance ladder and it supports up to 32x
amplification.\n
The possible settings are:\n
* Inverting PGA mode (Input MUX = IN1-)
* -1x, -3x, -7x, -15x, -31x
* Non-Inverting PGA mode (Input Mux = GND)
* 2x, 4x, 8x, 16x, 32x\n
A value of GAIN = 0x0 is Not Valid in both Inverting and Non-Inverting PGA modes.
Refer to block diagram in Quick Profiles to review connections.
`,
        hidden      : false,
        default     : "N0_P1",
        options     : GainOptions,
        onChange    : onChangeCfgGain,
    },
    {
        name        : "cfg0OutputPin",
        displayName : "Enable OPA Output Pin",
        description : 'Enable/Disable the OPA output pin',
        longDescription:`
The OPA output can be enabled or disabled.\n
Refer to block diagram in Quick Profiles to review connections.
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
        name        : "cfg0Chop",
        displayName : "Chopping Configuration",
        description : 'Configures chopping mode',
        longDescription:`
The OPA peripheral implements chopper stabilization in order to reduce offset,
drift, and 1/f noise.\n
If enabled, chopping mode can be set to:\n
**Standard:**
Requires an external filter (see device specific datasheet for
recommended values).
Note that the OPA automatically scales the chopping frequency based on the gain
configuration when using the internal PGA, but is also needed with external gain
when chopping is used.\n
The chopping frequency is as follows:
* Gain          Chopping Freq
* 1x            250kHz
* -1x/2x        125kHz
* -3x/4x        62.5kHz
* -7x/8x        31.25kHz
* -15x/16x      15.6kHz
* -31x/32x      7.8kHz\n
The disadvantage of standard chopping, is that it results in AC ripple at the
chopping frequency but for applications where this can be filtered out it is
not a problem.\n
**ADC Averaging:**
If the OPA output goes to an ADC input and the ADC has hardware averaging,
then an additional ADC assisted chopping mode can be selected.\n
In this mode an external filter is not needed and instead of a clock being used
for chopping the ADC provides a control signal to act as the clock and change
the chopping mode before each ADC sample so the averaging does the "filtering".\n
See the device specific datasheet for electrical performance with and without
chopping.\n
`,
        hidden      : false,
        default     : "DISABLE",
        options     : [
            {name: "DISABLE", displayName: "Chopping disabled"},
            {name: "STANDARD", displayName: "Standard chopping mode"},
            {name: "ADC_AVERAGING", displayName: "ADC averaging chopping mode"},
        ],
        onChange    : onChangeCfgChopping,
    }];

    return cfg;
}

/* PROFILES CONFIGURATION */
let opaConfig = [
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
    /****** PROFILES CONFIGURATION *******/
    {
        name: "GROUP_PROFILE",
        displayName: "Quick Profiles",
        description: "",
        collapsed: false,
        config: [
            {
                name        : "profile",
                displayName : "OPA Profiles",
                description : 'Pre-defined profiles for typical OPA configurations',
                longDescription: `
The OPA is a zero-drift chopper stabilized operational amplifier with a
programmable gain stage.

![OPA Block Diagram](../docs/english/sysconfig/images/opaBlockDiagM0G3xx.png "OPA Block Diagram")

The Quick Profile Options are:
* **General Purpose RRI mode**:
    * Inputs: IN0+/IN0-
    * Output: enabled
    * Gain: N/A (-1x/2x by default)
    * Chopping: disabled
    * Rail-to-Rail: enabled
    * Bandwidth: standard
* **Buffer mode, LP mode**:
    * Inputs: IN0+
    * Output: disabled
    * Gain: N/A (-1x/2x by default)
    * Chopping: standard
    * Rail-to-Rail: disabled
    * Bandwidth: LP
* **DAC8 output buffer mode**:
    * Inputs: DAC8 (internal)
    * Output: enabled
    * Gain: N/A (-1x/2x by default)
    * Chopping: standard
    * Rail-to-Rail: disabled
    * Bandwidth: standard
* **Inverting -1x PGA with DAC8 as bias**:
    * Inputs: IN1-, DAC8 uses as positive bias
    * Output: enabled
    * Gain: -1x
    * Chopping: ADC averaging
    * Rail-to-Rail: disabled
    * Bandwidth: standard
* **Non-inverting 1x PGA**:
    * Inputs: IN0+
    * Output: enabled
    * Gain: 1x
    * Chopping: standard
    * Rail-to-Rail: disabled
    * Bandwidth: standard
* **1st stage non-inverting cascaded amplifier**:
    * Inputs: IN0+
    * Output: to 2nd stage (internal)
    * Gain: 2x
    * Chopping: disabled
    * Rail-to-Rail: disabled
    * Bandwidth: standard
* **2nd stage non-inverting cascaded amplifier**:
    * Inputs: 1st stage (internal)
    * Output: enabled
    * Gain: 2x
    * Chopping: disabled
    * Rail-to-Rail: disabled
    * Bandwidth: standard
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "CUSTOM",
                options     : [
                    {name: "CONFIG_PROFILE_1", displayName: "General Purpose RRI"},
                    {name: "CONFIG_PROFILE_2", displayName: "Buffer mode, LP mode"},
                    {name: "CONFIG_PROFILE_3", displayName: "DAC8 output buffer mode"},
                    {name: "CONFIG_PROFILE_4", displayName: "Inverting -1x PGA with DAC8 as bias"},
                    {name: "CONFIG_PROFILE_6", displayName: "1st stage non-inverting cascaded amplifier"},
                    {name: "CONFIG_PROFILE_7", displayName: "2nd stage non-inverting cascaded amplifier"},
                    {name: "CUSTOM", displayName: "Custom"},
                ],
                onChange    : onChangeOPAProfile,
            },
        ],
    },
]

opaConfig = opaConfig.concat([
    {
        name: "GROUP_BASIC",
        displayName: "OPA Pre-Set Configuration",
        description: "",
        longDescription:
`Basic OPA options allow configuration of the inputs and gain.
`,
        collapsed: false,
        config: getOpaPresetConfig(),
    }
])

opaConfig = opaConfig.concat([
    {
        name: "GROUP_ADVANCED",
        displayName: "Advanced Configuration",
        description: "",
        longDescription:
`Advanced options configure bandwidth and Rail-to-Rail mode.`,
        collapsed: true,
        config: [
            {
                name: "advRRI",
                displayName: "Enable Rail-to-Rail Input",
                description: "Enables Rail-to-Rail",
                longDescription: `
In some basic signal conditioning applications, rail-to-rail input is not
required and thus can be disabled to reduce overall power consumption.
`,
                default: false,
                onChange : onChangeAdvRRI,
            },
            {
                name: "advBW",
                displayName: "Bandwidth",
                description: "Configures the OPA bandwidth",
                longDescription: `
The OPA supports:
* Standard (STD) mode: 6MHz bandwidth
* Low-Power (LP) mode: 1MHz bandwidth\n
General purpose applications which require <1MHz GBW can benefit of the lower
power consumption of LP mode.
`,
                default: "LOW",
                options     : [
                    {name: "LOW", displayName: "1MHz Low Power (LP)"},
                    {name: "HIGH", displayName: "6MHz Standard (STD) mode"},
                ],
                onChange : onChangeAdvBW,
            },
        ]
    },
])

opaConfig = opaConfig.concat([
    {
        name: "GROUP_INTERRUPTS",
        displayName: "Interrupt Configuration",
        longDescription: `
This section allows enabling/disabling OPA interrupts`,
        collapsed: true,
        config: [
            {
                name        : "enabledInterrupts",
                displayName : "Enable Interrupts",
                description : 'Enable OPA interrupt',
                longDescription: `
The supported interrupts are:\n
* Enable Error: triggered if OPA is enabled and another request is received\n
* IO authentication: triggered if any errors are detected during IO authentication`,
                minSelections: 0,
                default     : [],
                options     : [
                    {name: "IO_AUTHENTICATION", displayName: "IO authentication error"},
                    {name: "ENABLE_ERROR", displayName: "Enable error"},
                ],
                onChange    : onChangeInt
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
])

/* Helper Configurables */
opaConfig = opaConfig.concat([
    /*
     * Helper Configurables
     * These are invisible to sysconfig and have no influence on code generation, but give the module additional
     * visibility based on the state of the system and the specific M0 device being configured
     */
    {
        name: "pinIn0PosUsed",
        displayName: "IN0+ is used",
        default: false,
        hidden: true,
        getValue: (inst) => {
            if (inst["cfg0PSELChannel"] == "IN0_POS")
            {
                return true;
            }

            return false;
        }
    },
    {
        name: "pinIn1PosUsed",
        displayName: "IN1+ is used",
        default: false,
        hidden: true,
        getValue: (inst) => {
            if (inst["cfg0PSELChannel"] == "IN1_POS")
            {
                return true;
            }

            return false;
        }
    },
    {
        name: "pinIn0NegUsed",
        displayName: "IN0- is used",
        default: false,
        hidden: true,
        getValue: (inst) => {
            if (inst["cfg0NSELChannel"] == "IN0_NEG")
            {
                return true;
            }

            return false;
        }
    },
    {
        name: "pinIn1NegUsed",
        displayName: "IN1- is used",
        default: false,
        hidden: true,
        getValue: (inst) => {
            if ( (inst["cfg0NSELChannel"] == "IN1_NEG") ||
                    (inst["cfg0MSELChannel"] == "IN1_NEG") )
            {
                return true;
            }

            return false;
        }
    },
    {
        name: "pinOutUsed",
        displayName: "OUT is used",
        default: false,
        hidden: true,
        getValue: (inst) => {
            if (inst["cfg0OutputPin"] == "ENABLED")
            {
                return true;
            }

            return false;
        }
    },
    /****** End of Helper Configurables *******/
])

/* Add Pinmux Peripheral Configuration group */
opaConfig = opaConfig.concat(Common.getGPIOGroupConfig());

function moduleInstances(inst){
    let modInstances = [];

    /*
     * Gets a Peripheral GPIO Configuration submodule
     */
    /* CONDITIONS CODE START */
    let In0NegPin, In1NegPin, In0PosPin, In1PosPin, OutPin = false;

    if (inst.pinIn0PosUsed == true)
    {
        In0PosPin = true;
    }
    if (inst.pinIn1PosUsed == true)
    {
        In1PosPin = true;
    }
    if (inst.pinIn0NegUsed == true)
    {
        In0NegPin = true;
    }
    if (inst.pinIn1NegUsed == true)
    {
        In1NegPin = true;
    }
    if (inst.pinOutUsed == true)
    {
        OutPin = true;
    }
    /* CONDITIONS CODE END */

    /* IN0- */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   In0NegPin,    "In0NegPin",
     "IN0NEG", "OPA Inverting input 0 Pin",
     "INPUT");

    /* IN1- */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   In1NegPin,    "In1NegPin",
     "IN1NEG", "OPA Inverting input 1 Pin",
     "INPUT");

    /* IN0+ */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   In0PosPin,    "In0PosPin",
     "IN0POS", "OPA Non-inverting input 0 Pin",
     "INPUT");

    /* IN1+ */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   In1PosPin,    "In1PosPin",
     "IN1POS", "OPA Non-inverting input 1 Pin",
     "INPUT");

    /* OUT */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   OutPin,    "OutPin",
     "OUT", "OPA Output0 Pin",
     "OUTPUT");


    return modInstances;
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: opaConfig,


    maxInstances: Common.peripheralCount("OA"),

   /* override generic requirements with  device-specific reqs (if any) */
   validate: validate,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/opa/OPA.Board.c.xdt",
        boardh: "/ti/driverlib/opa/OPA.Board.h.xdt",
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
    let theModules = ["Board", "SYSCTL"]
     /* Add VREF to required modules when configured as voltage source */
    if(["VREF"].includes(inst.cfg0PSELChannel)){
        theModules.push("VREF");
    }
    /* Add DAC to required modules: only selectable in MSPM0G devices*/
    if(Common.isDeviceM0G() && (inst.cfg0PSELChannel == "DAC_OUT" || inst.cfg0MSELChannel == "DAC_OUT")){
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
    let in0neg = {
        name:"In0NegPin",
        displayName:"OPA Inverting input 0 Pin",
        interfaceNames:["IN0-"],
    };
    let in1neg = {
        name:"In1NegPin",
        displayName:"OPA Inverting input 1 Pin",
        interfaceNames:["IN1-"],
    };
    let in0pos = {
        name:"In0PosPin",
        displayName:"OPA Non-inverting input 0 Pin",
        interfaceNames:["IN0+"],
    };
    let in1pos = {
        name:"In1PosPin",
        displayName:"OPA Non-inverting input 1 Pin",
        interfaceNames:["IN1+"],
    };
    let out = {
        name:"OutPin",
        displayName:"OPA Output Pin",
        interfaceNames:["OUT"],
    };
    let resources = [];

    if (inst.pinIn0PosUsed == true)
    {
        resources.push(in0pos);
    }
    if (inst.pinIn1PosUsed == true)
    {
        resources.push(in1pos);
    }
    if (inst.pinIn0NegUsed == true)
    {
        resources.push(in0neg);
    }
    if (inst.pinIn1NegUsed == true)
    {
        resources.push(in1neg);
    }
    if (inst.pinOutUsed == true)
    {
        resources.push(out);
    }

    let opa = {
        name: "peripheral",
        displayName: "OPA Peripheral",
        interfaceName: "OA",
        resources: resources,
        signalTypes: {
            In0NegPin: ["IN0-"],
            In1NegPin: ["IN1-"],
            In0PosPin: ["IN0+"],
            In1PosPin: ["IN1+"],
            OutPin: ["OUT"],
        }
    };

    return ([opa]);
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
        if (Common.typeMatches(type, ["OPA"])) modulePin = sig;
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
