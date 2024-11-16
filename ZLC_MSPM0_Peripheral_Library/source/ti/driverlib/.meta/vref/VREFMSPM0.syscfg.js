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
 *  ======== VREFMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

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
function validateVREF(inst, validation)
{
    // // the 3rd argument is a "field" argument and it dictates where the warning
    // // will appear. It usually makes sense to put the name of the configurable
    // // that is causing the warning.
    // Common.logWarning(validation, inst, "moduleHigh", "Here's an example warning");

    /* Internal Mode */
    if (inst.basicMode.includes("DL_VREF_ENABLE_ENABLE"))
    {
        // Validate if MFCLK is enabled if selected
        if(inst.advClockConfigEnable){
            if (inst.advClkSrc == "DL_VREF_CLOCK_MFCLK"){
                if(!system.modules["/ti/driverlib/SYSCTL"].$static.clockTreeEn){
                    if(system.modules["/ti/driverlib/SYSCTL"].$static.MFCLKEn != true ){
                        Common.logError(validation, inst,
                                        "advClkSrc",
                                        "MFCLK not initialized in SYSCTL");
                    }
                }
                /* Clock Tree Validation */
                else{
                    if(!system.clockTree.MFCLKGATE.enable){
                        Common.logError(validation, inst,
                            "advClkSrc",
                            "MFCLK not initialized in Clock Tree");
                    }
                }
            }
        }

        // Validate S&H settings
        if (inst.advSHEnable == true)
        {
            if (getValueAdvSHSample(inst) < 30e-6)
            {
                Common.logWarning(validation, inst,
                    "advSHSample",
                    "Sample-and-Hold sample time recommended to be >31us");
            }
            if (getValueAdvSHHold(inst) < 6e-3)
            {
                Common.logWarning(validation, inst,
                    "advSHHold",
                    "Sample-and-Hold hold time recommended to be >6ms");
            }
        }


        /* Special Case: COMP & OPA Validation for MSPM0L */
        if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
            /* Check if any COMP instance enables VREF */
            let COMPMod = system.modules["/ti/driverlib/COMP"];
            if (COMPMod){
                let COMPInsts = COMPMod.$instances
                let compError = false;
                for(let singleCOMP of COMPInsts){
                    if (["DL_COMP_REF_SOURCE_VREF_DAC","DL_COMP_REF_SOURCE_VREF"].includes(singleCOMP.vSource)){
                        compError = true;
                    }
                }
                if (compError && !inst.basicMode.includes("DL_VREF_ENABLE_DISABLE")){
                    validation.logError("Internal reference is not supported when sourcing COMP for the selected device.", inst, ["basicMode"]);
                }
            }
        }
        if(Common.isDeviceM0L()){
            /* Check if any OPA instance enables VREF */
            let OPAMod = system.modules["/ti/driverlib/OPA"];
            if (OPAMod){
                let OPAInsts = OPAMod.$instances
                let opaError = false;
                for(let singleOPA of OPAInsts){
                    if (["VREF"].includes(singleOPA.cfg0PSELChannel)){
                        opaError = true;
                    }
                }
                if (opaError && !inst.basicMode.includes("DL_VREF_ENABLE_DISABLE")){
                    validation.logError("Internal reference is not supported when sourcing OPA for the selected device.", inst, ["basicMode"]);
                }
            }
        }
    }

    /* External Mode */
    if (inst.basicMode.includes("DL_VREF_ENABLE_DISABLE"))
    {

    }

    // This is something Common does on its own to check uniqueness and the like
    // I don't see a reason to remove it
    //Common.validateNames(inst, validation);


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
    /* No External Pins to be configured for M0C */
    if(Common.isDeviceM0C()){
        return [];
    }
    let pinResources = []
    if(Common.isDeviceM0G() || ((Common.isDeviceM0L() || Common.isDeviceM0C()) && (inst.basicMode.includes("DL_VREF_ENABLE_DISABLE")))){
        pinResources.push(
            {
                name:"vrefPosPin",
                displayName:"VREF Positive (VREF+)",
                interfaceNames:["VREF+"],
            },
        );

        if (inst.basicVrefPins == "VREF+-")
        {
            pinResources.push(
                {
                    name:"vrefNegPin",
                    displayName:"VREF Negative (VREF-)",
                    interfaceNames:["VREF-"],
                }
            )
        }
    }

    let vref = {
        name: "peripheral",
        displayName: "VREF Peripheral",
        interfaceName: "VREF",
        resources: pinResources,
        signalTypes: {
            vrefPosPin: ["VREF+"],
            vrefNegPin: ["VREF-"],
        }
    };

    return ([vref]);
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

let profileOptions = [
    {name: "INT_1_4_V", displayName: "Internal 1.4V with Sample-and-Hold using LFCLK"},
    {name: "INT_2_5_V", displayName: "Internal 2.5V with Sample-and-Hold disabled"},
];
if(!Common.isDeviceM0C()){
    profileOptions.push({name: "EXT_2_0_V", displayName: "External 2V"});
}
profileOptions.push({name: "CUSTOM", displayName: "Custom"});


let vrefConfig = [
    /****** PROFILES CONFIGURATION *******/
    {
        name: "GROUP_PROFILE",
        displayName: "Quick Profiles",
        description: "",
	    collapsed: false,
        config: [
            {
                name        : "profile",
                displayName : "VREF Profiles",
                description : 'Pre-defined profiles for typical VREF configurations',
                longDescription: `
The VREF module for the MSPM0Gxx family is a shared voltage reference module
which can be leveraged by a variety on on-board analog peripherals.
VREF allows users to choose between using an internally generated reference
voltage or using an externally provided reference voltage from outside the MCU.

![VREF Block Diagram](../docs/english/sysconfig/images/vrefBlockDiagM0G3xx.png "VREF Block Diagram")

The Quick Profile Options are:
* **Internal 1.4V**:
    * Selects internal 1.4V reference.
    * Uses LFCLK as clock source.
    * Sample-and-Hold enabled with sample = 31us and hold = 6ms.
    * Uses VREF+ output, but not VREF-.
* **Internal 2.5V**:
    * Selects internal 2.5V reference.
    * Uses LFCLK as clock source.
    * Sample-and-Hold disabled.
    * Uses VREF+ output, but not VREF-.
* **External**:
    * Selects external 2V reference.
    * Sample-and-Hold disabled.
    * Uses VREF+ as positive input, while negative reference is GND.
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "CUSTOM",
                options     : profileOptions,
                onChange    : onChangeVrefProfile,
            },
        ],
    },
]

let vrefBasicConfig = [];
/* long description for basicMode, device-dependent */
let basicModeLongDesc = `
When enabled, VREF can be sourced:
* Internally: CTL0.ENABLE=1. Configurable to 1.4V or 2.5V (see datasheet for
device specific values). An external decoupling capacitor is required on VREF+-.
* Externally: CTL0.ENABLE=0. Connect an external reference to VREF+-.`
/* long description for basicExtVolt, device-dependent */
let basicExtVoltLongDesc = `This value is only used for calculations.`
if(Common.isDeviceM0G()){
basicExtVoltLongDesc=`
This value is only used for calculations.
\n**Internal VREF must be disabled when applying an external reference to VREF+- pins.**`

basicModeLongDesc=`
When enabled, VREF can be sourced:
* Internally: CTL0.ENABLE=1. Configurable to 1.4V or 2.5V (see datasheet for
device specific values). An external decoupling capacitor is required on VREF+-.
* Externally: CTL0.ENABLE=0. Connect an external reference to VREF+-.

Be sure internal VREF is disabled when applying an external reference to VREF+-
pins.`
}

if(Common.isDeviceM0G()){
    vrefBasicConfig = vrefBasicConfig.concat(
        [
            {
                name        : "basicMode",
                displayName : "Mode",
                description : 'Configures VREF for internal or external mode',
                longDescription: basicModeLongDesc,
                hidden      : false,
                default     : "DL_VREF_ENABLE_ENABLE",
                options     : [
                    {name: "DL_VREF_ENABLE_ENABLE", displayName: "Internal"},
                    {name: "DL_VREF_ENABLE_DISABLE", displayName: "External"},
                ],
                onChange    : onChangeBasicMode,
            },
        ]
        )
    } else if(Common.isDeviceM0L() ){
        vrefBasicConfig = vrefBasicConfig.concat(
            [
                {
                    name        : "basicMode",
                    displayName : "Mode",
                    description : 'Configures VREF for internal or external mode',
                    longDescription: basicModeLongDesc,
                    hidden      : false,
                    default     : ["DL_VREF_ENABLE_ENABLE"],
                    minSelections: 1,
                    options     : [
                        {name: "DL_VREF_ENABLE_ENABLE", displayName: "Internal"},
                        {name: "DL_VREF_ENABLE_DISABLE", displayName: "External"},
                    ],
                    onChange    : onChangeBasicMode,
                },
            ]
        )
    } else if(Common.isDeviceM0C()){
        /* MSPM0C only supports internal VREF */
        vrefBasicConfig = vrefBasicConfig.concat(
            [
                {
                    name        : "basicMode",
                    displayName : "Mode",
                    description : 'Configures VREF for internal or external mode',
                    longDescription: basicModeLongDesc,
                    readOnly    : true,
                    hidden      : false,
                    default     : "DL_VREF_ENABLE_ENABLE",
                    options     : [
                        {name: "DL_VREF_ENABLE_ENABLE", displayName: "Internal"},
                    ],
                    onChange    : onChangeBasicMode,
                },
            ]
        )
    }


    vrefBasicConfig = vrefBasicConfig.concat(
        [
            {
                name        : "basicVrefPins",
                displayName : "VREF+/VREF- Configuration",
                description : 'Configures VREF+/VREF- functionality',
                longDescription:`
Depending on the mode, VREF is configured as follows:
* Internal:
    * VREF+: Always configured as the reference positive output. Requires an
external capacitor. Consult datasheet for details.
    * VREF-: When enabled, it serves as the reference negative/ground output.
When not enabled, VSS is used as ground reference.
* External:
    * VREF+: Always configured as the reference positive input. An external
decoupling capacitor is recommended. Consult datasheet for details.
    * VREF-: When enabled, it serves as the reference negative/ground input.
When not enabled, VSS is used as ground reference.

    **Note: If VREF- is not available in package, the option won't be available.**`,
                hidden      : Common.isDeviceM0L() || Common.isDeviceM0C(),
                default     : "VREF+",
                options     : [
                    {name: "VREF+", displayName: "VREF+ enabled, VREF- disabled"},
                    {name: "VREF+-", displayName: "VREF+ enabled, VREF- enabled"},
                ],
                getDisabledOptions: getVrefPinsDisabledOptions,
                onChange    : onChangeVrefPins,
            },
            {
                name        : "basicIntVolt",
                displayName : "Internal Voltage (V)",
                description : 'Configures output voltage of internal VREF',
                longDescription:`
    When enabled as an internal source, VREF can be configured to output:
    * 2.5V, or
    * 1.4V

    Consult datasheet for specifications. `,
                hidden      : false,
                default     : "DL_VREF_BUFCONFIG_OUTPUT_1_4V",
                options     : [
                    {name: "DL_VREF_BUFCONFIG_OUTPUT_1_4V", displayName: "1.4"},
                    {name: "DL_VREF_BUFCONFIG_OUTPUT_2_5V", displayName: "2.5"},
                ],
                onChange    : onChangeBasicIntVolt,
            },
            {
                name        : "basicExtVolt",
                displayName : "External Voltage (V)",
                description : 'Defines the external voltage on VREF+-',
                longDescription: basicExtVoltLongDesc,
                hidden      : true,
                range       : [0, 3.6],
                default     : 2,
                onChange    : onChangeBasicExtVolt,
            },
            {
                name        : "basicVREFVoltage",
                displayName : "VREF Voltage (mV)",
                description : 'Shows VREF voltage in mV',
                longDescription:``,
                hidden      : true,
                getValue    : (inst) => getVREFmV(inst),
                default     : 0,
            },
            {
                name        : "basicVREFVoltageInternal",
                displayName : "VREF Voltage (mV)",
                description : 'Shows VREF voltage in mV',
                longDescription:``,
                hidden      : true,
                getValue    : (inst) => getVREFmVInternal(inst),
                default     : 0,
            },
            {
                name        : "basicVREFVoltageExternal",
                displayName : "VREF Voltage (mV)",
                description : 'Shows VREF voltage in mV',
                longDescription:``,
                hidden      : true,
                getValue    : (inst) => getVREFmVExternal(inst),
                default     : 0,
            },
            {
                name        : "checkVREFReady",
                displayName : "Enable Delay for VREF Startup",
                description : 'Generates a software delay waiting for VREF startup',
                longDescription:
`Enables a software delay waiting for the VREF startup time. Developers can
skip this delay but consider the VREF startup time before using it on the
application.`,
                hidden      : false,
                default     : false,
                onChange    : onChangeSetCustomProfile,
            },
        ]
    );

    vrefConfig = vrefConfig.concat([
        /****** BASIC CONFIGURATION *******/
        {
            name: "GROUP_BASIC",
            displayName: "Basic Configuration",
            description: "",
            longDescription:`
    Basic VREF configuration includes voltage settings and internal vs external
    mode.`,
            collapsed: false,
            config: vrefBasicConfig,
        },
    ])

let advancedConfig = [
            {
                name: "GROUP_ADV_CLOCK_CONFIG",
                displayName: "Clock Configuration",
                description: "",
                collapsed: true,
                config: [
                    {
                        name        : "advClockConfigEnable",
                        displayName : "Configure Clock",
                        description : 'Enable Clock Configuration',
                        longDescription: ``,
                        hidden      : false,
                        default     : false,
                        onChange    : onChangeadvClockConfigEnable,
                    },
                    {
                        name        : "advClkSrc",
                        displayName : "Clock Source",
                        description : 'VREF clock source selection',
                        longDescription:`
VREF clock sources include:
* BUSCLK: **ULPCLK** for PD0. Limited to 40MHz and derived from **MCLK** sourced
from **SYSPLL**, **HFXT**, or **HFCLK_IN**.
* MFCLK: Fixed 4MHz clock, derived from **SYSOSC**.
* LFCLK: Fixed 32kHz clock, derived from **LFOSC**, **LFXT** or **LFCLK_IN**.
Check **SYSCTL** module for more information. `,
                        hidden      : true,
                        default     : "DL_VREF_CLOCK_LFCLK",
                        options     : [
                            {name: "DL_VREF_CLOCK_BUSCLK", displayName: "BUSCLK"},
                            {name: "DL_VREF_CLOCK_MFCLK", displayName: "MFCLK"},
                            {name: "DL_VREF_CLOCK_LFCLK", displayName: "LFCLK"},
                        ],
                        onChange    : onChangeAdvClkSrc,
                    },
                    {
                        name        : "advClkDiv",
                        displayName : "Clock Divider",
                        description : 'VREF clock divider selection',
                        hidden      : true,
                        default     : "DL_VREF_CLOCK_DIVIDE_1",
                        options     : [
                            {name: "DL_VREF_CLOCK_DIVIDE_1", displayName: "1"},
                            {name: "DL_VREF_CLOCK_DIVIDE_2", displayName: "2"},
                            {name: "DL_VREF_CLOCK_DIVIDE_4", displayName: "4"},
                            {name: "DL_VREF_CLOCK_DIVIDE_6", displayName: "6"},
                            {name: "DL_VREF_CLOCK_DIVIDE_8", displayName: "8"},
                        ],
                        onChange    : onChangeAdvClkDiv,
                    },
                    {
                        name        : "advClkSrcCalc",
                        displayName : "Calculated Clock Source (Hz)",
                        description : 'Calculated VREF Clock Source in Hz',
                        longDescription:`
The VREF clock is calculated as:

        VREF_Clock = VREF_Clock_Source / VREF_Clock_Divider
        Where:
            VREF_Clock_Source:
                * BUSCLK: ULPCLK for PD0. Derived from MCLK sourced from \
SYSPLL, HFXT, or HFCLK_IN.
                * MFCLK: Fixed 4MHz clock, derived from SYSOSC.
                * LFCLK: Fixed 32kHz clock, derived from LFOSC, LFXT or \
LFCLK_IN.
            VREF_Clock_Divider:
                1,2,4,6, or 8
Check **SYSCTL** module for more information. `,
                        hidden      : true,
                        getValue    : (inst) => getVREFClockSourceFreq(inst),
                        default     : 0,
                    },
                    {
                        name        : "advClkSrcCalc_units",
                        displayName : "Calculated Clock Source",
                        description : 'Calculated VREF Clock Source in Hz',
                        longDescription:`
The VREF clock is calculated as:

        VREF_Clock = VREF_Clock_Source / VREF_Clock_Divider
        Where:
            VREF_Clock_Source:
                * BUSCLK: ULPCLK for PD0. Derived from MCLK sourced from \
SYSPLL, HFXT, or HFCLK_IN.
                * MFCLK: Fixed 4MHz clock, derived from SYSOSC.
                * LFCLK: Fixed 32kHz clock, derived from LFOSC, LFXT or \
LFCLK_IN.
            VREF_Clock_Divider:
                1,2,4,6, or 8
Check **SYSCTL** module for more information. `,
                        hidden      : true,
                        getValue    : (inst) => {
                            return Common.getUnitPrefix(getVREFClockSourceFreq(inst)).str+"Hz";
                        },
                        default     : "0 Hz",
                    },
                ],
            },
            {
                name: "GROUP_ADV_SH_CONFIG",
                displayName: "Sample-and-Hold Mode Configuration",
                description: "",
                collapsed: true,
                config: [
                    {
                        name        : "advSHEnable",
                        displayName : "Enable Sample-and-Hold Mode",
                        description : 'Enable Sample-and-Hold Mode',
                        longDescription: ``,
                        hidden      : false,
                        default     : false,
                        onChange    : onChangeadvSHEnable,
                    },
                    {
                        name        : "advSHSample",
                        displayName : "Set S&H Sample Cycles",
                        description : 'Configure number of cycles for sampling in Sample-and-Hold',
                        longDescription: `
        The recommended sample time is >30us waiting for VREF to stabilize.\n
        The timing is calculated as:\n
                Sample_time =Sample_cycles/VREF_Clock\n
                Where:
                    VREF_Clock = VREF_Clock_Source/VREF_Clock_Divider
                    (See Clock Configuration section for more details).\n
                    Sample_cycles = 0 to 65535.\n
                If VREF_Clock is 32.768kHz (i.e. LFCLK), and Sample_cycles = 1, the resulting Sample_time will be ~30.51us.\n`,
                        hidden      : true,
                        default     : 0,
                        isInteger   : true,
                        range       : [0, 65535],
                        onChange    : onChangeAdvSHSample,
                    },
                    {
                        name        : "advSHSampleCalc",
                        displayName : "Calculated S&H Sample Timing",
                        description : `Calculated time for sampling in Sample-and-Hold`,
                        longDescription: ``,
                        hidden      : true,
                        default     : "0s",
                        getValue    : (inst) => (Common.getUnitPrefix((getValueAdvSHSample(inst))).str+'s'),
                    },
                    {
                        name        : "advSHHold",
                        displayName : "Set S&H Hold Cycles",
                        description : 'Configure number of cycles for hold in Sample-and-Hold',
                        longDescription: `
        Hold time should be such that the accuracy degradation due to leakage is within
        DAC acceptable limits. The recommended hold time is 6ms.\n
        The timing is calculated as:\n
                Hold_time = Hold_cycles / VREF_Clock\n
                Where:
                    VREF_Clock = VREF_Clock_Source/VREF_Clock_Divider
                    (See Clock Configuration section for more details).\n
                    Hold_cycles = 0 to 65535.\n
                If VREF_Clock is 32.768kHz (i.e. LFCLK), and Hold_cycles = 197, the resulting Sample_time will be ~6.01ms.\n`,
                        hidden      : true,
                        default     : 0,
                        isInteger   : true,
                        range       : [0, 65535],
                        onChange    : onChangeAdvSHHold,
                    },
                    {
                        name        : "advSHHoldCalc",
                        displayName : "Calculated S&H Hold Timing",
                        description : `Calculated time for hold in Sample-and-Hold`,
                        longDescription: ``,
                        hidden      : true,
                        default     : "0s",
                        getValue    : (inst) => (Common.getUnitPrefix((getValueAdvSHHold(inst))).str+'s'),
                    },
                ]
            },
        ];

if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
    advancedConfig=advancedConfig.concat([
        // DL_VREF_enableInternalRefCOMP
        {
            name: "enableCOMPVREF",
            displayName: "Enable VREF as internal reference for COMP",
            default: false,
        },
    ]);
}

vrefConfig = vrefConfig.concat(
    /****** ADVANCED CONFIGURATION *******/
    {
        name: "GROUP_ADVANCED",
        displayName: "Advanced Configuration",
        description: "",
        longDescription: "Configures clock and sample and hold timing",
        collapsed: true,
        config: advancedConfig,
    }
);

/* Add Pinmux Peripheral Configuration group */
vrefConfig = vrefConfig.concat(Common.getGPIOGroupConfig());

function moduleInstances(inst){
    let modInstances = [];

    /*
     * Gets a Peripheral GPIO Configuration submodule
     */
    /* CONDITIONS CODE START */
    let vrefPosConfig, vrefNegConfig = false;
    if(Common.isDeviceM0G() || (Common.isDeviceM0L() && (inst.basicMode.includes("DL_VREF_ENABLE_DISABLE")))){
        vrefPosConfig = true;

        if (inst.basicVrefPins == "VREF+-")
        {
            vrefNegConfig = true;
        }
    }
    /* CONDITIONS CODE END */
    /* VREF+ */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   vrefPosConfig,    "vrefPosPin",
     "VREFPOS", "VREF Positive (VREF+)",
     "INPUT");
    /* VREF- */
    Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   vrefNegConfig,    "vrefNegPin",
     "VREFNEG", "VREF Negative (VREF-)",
     "INPUT");

    return modInstances;
}

/************************* General functions *******************************/
function hasMuxablePins(interfaceName, pinName) {
    /*
     * _.some returns true if the function supplied in the second parameter
     *  returns true for any element)
     */

    const interfacePin = system.deviceData.interfaces[interfaceName].interfacePins[pinName];
    return _.some(interfacePin.pinMappings, (peripheralPin) => peripheralPin.pinMappings.length !== 0);
}

function updateGUIbasedonConfig(inst, ui)
{
    /* Mode Selection */
    if(Common.isDeviceM0L() || Common.isDeviceM0C()){
        let boolInternal = (inst.basicMode).includes("DL_VREF_ENABLE_ENABLE");
        let boolExternal = (inst.basicMode).includes("DL_VREF_ENABLE_DISABLE");

        ui.advClkSrc.hidden             = !boolInternal;
        ui.advClkDiv.hidden             = !boolInternal;
        ui.advClkSrcCalc_units.hidden   = !boolInternal;
        ui.basicIntVolt.hidden          = !boolInternal;
        ui.advClockConfigEnable.hidden  = !boolInternal;
        ui.advSHEnable.hidden           = !boolInternal;
        ui.basicExtVolt.hidden          = !boolExternal;
        ui.basicVrefPins.hidden         = !boolExternal;
    }
    else if(Common.isDeviceM0G()){
        switch (inst.basicMode)
        {
            case "DL_VREF_ENABLE_ENABLE":
                ui.advClkSrc.hidden = false;
                ui.advClkDiv.hidden = false;
                ui.advClkSrcCalc_units.hidden = false;
                ui.basicIntVolt.hidden = false;
                ui.basicExtVolt.hidden = true;
                ui.advClockConfigEnable.hidden = false;
                ui.advSHEnable.hidden = false;
            break;
            case "DL_VREF_ENABLE_DISABLE":
                ui.advClkSrc.hidden = true;
                ui.advClkDiv.hidden = true;
                ui.advClkSrcCalc_units.hidden = true;
                ui.basicIntVolt.hidden = true;
                ui.basicExtVolt.hidden = false;
                ui.advClockConfigEnable.hidden = true;
                ui.advSHEnable.hidden = true;
            break;
        }
    }
    /* Sample & Hold Configuration Parameters */
    if ( (ui.advSHEnable.hidden == true) ||
         (inst.advSHEnable == false) )
    {
        ui.advSHSample.hidden = true;
        ui.advSHSampleCalc.hidden = true;
        ui.advSHHold.hidden = true;
        ui.advSHHoldCalc.hidden = true;
    }
    else
    {
        ui.advSHSample.hidden = false;
        ui.advSHSampleCalc.hidden = false;
        ui.advSHHold.hidden = false;
        ui.advSHHoldCalc.hidden = false;
    }
    /* Clock Configuration parameters */
    if ( (ui.advClockConfigEnable.hidden == true) ||
         (inst.advClockConfigEnable == false) )
    {
        ui.advClkSrc.hidden = true;
        ui.advClkDiv.hidden = true;
        ui.advClkSrcCalc_units.hidden = true
    }
    else
    {
        ui.advClkSrc.hidden = false;
        ui.advClkDiv.hidden = false;
        ui.advClkSrcCalc_units.hidden = false;
    }
}

/************************* Profiles functions *******************************/
/*
 *  ======== onChangeVrefProfile ========
 *  Called when VREF Profile is changed.
 *  Pre-configures VREF according to profiles
 *
 */
const profilesVref = [
    {
        name            : "INT_1_4_V",
        basicMode       : ((Common.isDeviceM0G()||Common.isDeviceM0C())?"DL_VREF_ENABLE_ENABLE":["DL_VREF_ENABLE_ENABLE"]),
        basicIntVolt    : "DL_VREF_BUFCONFIG_OUTPUT_1_4V",
        basicVrefPins   : "VREF+",
        advClockConfigEnable     : true,
        advClkSrc       : "DL_VREF_CLOCK_LFCLK",
        advClkDiv       : "DL_VREF_CLOCK_DIVIDE_1",
        advSHEnable     : true,
        advSHSample     : 1,
        advSHHold       : 197,
    },
    {
        name            : "INT_2_5_V",
        basicMode       : ((Common.isDeviceM0G()||Common.isDeviceM0C())?"DL_VREF_ENABLE_ENABLE":["DL_VREF_ENABLE_ENABLE"]),
        basicIntVolt    : "DL_VREF_BUFCONFIG_OUTPUT_2_5V",
        basicVrefPins   : "VREF+",
        advClockConfigEnable     : true,
        advClkSrc       : "DL_VREF_CLOCK_LFCLK",
        advClkDiv       : "DL_VREF_CLOCK_DIVIDE_1",
        advSHEnable     : false,
        advSHSample     : 0,
        advSHHold       : 0,
    },
];
if(!Common.isDeviceM0C()){
    profilesVref.push({
        name            : "EXT_2_0_V",
        basicMode       : ((Common.isDeviceM0G())?"DL_VREF_ENABLE_DISABLE":["DL_VREF_ENABLE_DISABLE"]),
        basicExtVolt    : 2.0,
        basicVrefPins   : "VREF+",
        advClockConfigEnable     : false,
        advSHEnable     : false,
        advSHSample     : 0,
        advSHHold       : 0,
    },)
}

function onChangeVrefProfile(inst, ui) {
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = profilesVref.filter(obj =>
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


/************************* Basic functions *******************************/
/*
 *  ======== onChange functions ========
 *  Called when these basic parameters are changed
 *
 */
function onChangeBasicMode(inst, ui) {
    updateGUIbasedonConfig(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeVrefPins(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeBasicIntVolt(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeBasicExtVolt(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeSetCustomProfile(inst,ui){
    inst.profile = "CUSTOM";
}

/*
 *  ======== getVREFmV ========
 *  Get the VREF voltage in mV
 *
 */
function getVREFmV(inst) {
    var vRefOutput = 0;
    if((inst.basicMode).includes("DL_VREF_ENABLE_ENABLE")){
        /* Internal mode */
        if (inst.basicIntVolt == "DL_VREF_BUFCONFIG_OUTPUT_1_4V")
        {
            vRefOutput = 1400;
        }
        else if (inst.basicIntVolt == "DL_VREF_BUFCONFIG_OUTPUT_2_5V")
        {
            vRefOutput = 2500;
        }
    }
    else if((inst.basicMode).includes("DL_VREF_ENABLE_DISABLE")){
        /* External */
        vRefOutput = Math.round(inst.basicExtVolt * 1000);
    }
    return vRefOutput;
}

function getVREFmVInternal(inst) {
    var vRefOutput = 0;
    if((inst.basicMode).includes("DL_VREF_ENABLE_ENABLE")){
        /* Internal mode */
        if (inst.basicIntVolt == "DL_VREF_BUFCONFIG_OUTPUT_1_4V")
        {
            vRefOutput = 1400;
        }
        else if (inst.basicIntVolt == "DL_VREF_BUFCONFIG_OUTPUT_2_5V")
        {
            vRefOutput = 2500;
        }
    }
    return vRefOutput;
}

function getVREFmVExternal(inst) {
    var vRefOutput = 0;
    if((inst.basicMode).includes("DL_VREF_ENABLE_DISABLE")){
        /* External */
        vRefOutput = Math.round(inst.basicExtVolt * 1000);
    }
    return vRefOutput;
}

function getVrefPinsDisabledOptions(inst)
{
    let disabledOptions = [];

    if (!hasMuxablePins("VREF", "VREF-"))
    {
        disabledOptions.push({name: "VREF+-",
                              displayName: "VREF+ enabled, VREF- enabled",
                              reason: "VREF- is not available in this package"});
    }

    return disabledOptions;
}


/************************* Advanced functions *******************************/
/*
 *  ======== onChange functions ========
 *  Called when these Advanced parameters are changed
 *
 */
function onChangeAdvClkSrc(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvClkDiv(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeadvSHEnable(inst, ui) {
    updateGUIbasedonConfig(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeadvClockConfigEnable(inst, ui) {
    updateGUIbasedonConfig(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvSHSample(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvSHHold(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/*
 *  ======== getVREFClockSourceFreq ========
 *  Get the VREF Clock source frequency in Hz
 *
 */
function getVREFClockSourceFreq(inst) {
    var vREFClockFreq = 0;
    var vREFDiv = 1;

    switch (inst.advClkSrc){
       case "DL_VREF_CLOCK_BUSCLK":
            vREFClockFreq = Common.getBUSCLKFreq(inst, "VREF");
        break;
        case "DL_VREF_CLOCK_MFCLK":
            vREFClockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.MFCLK_Freq;
        break;
        case "DL_VREF_CLOCK_LFCLK":
            vREFClockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq;
        break;
   }
   switch (inst.advClkDiv){
    case "DL_VREF_CLOCK_DIVIDE_1":
        vREFDiv = 1;
     break;
     case "DL_VREF_CLOCK_DIVIDE_2":
        vREFDiv = 2;
     break;
     case "DL_VREF_CLOCK_DIVIDE_4":
        vREFDiv = 4;
     break;
     case "DL_VREF_CLOCK_DIVIDE_6":
        vREFDiv = 6;
     break;
     case "DL_VREF_CLOCK_DIVIDE_8":
        vREFDiv = 8;
     break;
}

   vREFClockFreq = vREFClockFreq / vREFDiv;

   return vREFClockFreq;
}

/*
 *  ======== getValueAdvSHSample ========
 *  Get the Sample time of S&H in us
 *
 */
function getValueAdvSHSample(inst) {
    var clockSourceHz;
    var sampleCycles;

    clockSourceHz = inst.advClkSrcCalc;
    sampleCycles = inst.advSHSample;

    return (sampleCycles/clockSourceHz);
}

/*
 *  ======== getValueAdvSHHold ========
 *  Get the Hold time of S&H in us
 *
 */
function getValueAdvSHHold(inst) {
    var clockSourceHz;
    var holdCycles;

    clockSourceHz = inst.advClkSrcCalc;
    holdCycles = inst.advSHHold;

    return (holdCycles/clockSourceHz);

}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    /* This is where you should be putting all of your configurable information.
    If you want a configurable or variable that is not visible, you can make it
    hidden
     */

    config: vrefConfig,

    moduleInstances: moduleInstances,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    validate: validateVREF,

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
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    // moduleStatic specific to VREF as it's statically defined
    result.config = base.moduleStatic.config.concat(devSpecific.config);
    base.moduleStatic = result;

    // Todo: This is causing issues declaring the module
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
