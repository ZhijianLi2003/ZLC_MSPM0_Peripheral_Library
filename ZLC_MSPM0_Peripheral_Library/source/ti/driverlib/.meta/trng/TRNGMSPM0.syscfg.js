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
 *  ======== TRNGMSPM0.js ========
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
 *  ======== validatePinmux ========
 *  Validation run after solution
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validatePinmux(inst, validation) {
    /* Retention Validation */
    Common.getRetentionValidation(inst,validation);
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
    /* TRNG is only available on M0G devices */
    if (Common.isDeviceM0G())
    {
        /* TRNG functional clock must be within allowed frequency range */
        if (inst.clockFreq > 25000000)
        {
            validation.logError(
                "TRNG functional clock should not be greater than 25 MHz.",
                inst, "clockFreqWithUnits");
        }
        else if (inst.clockFreq < 9500000)
        {
            validation.logError(
                "TRNG functional clock should not be less than 9.5 MHz.",
                inst, "clockFreqWithUnits");
        }

        /*
         * TI recommends using decimate-by-4 or greater when using TRNG in
         * cryptographic applications
         */
        let avoidedDecRates = ["DL_TRNG_DECIMATION_RATE_1",
            "DL_TRNG_DECIMATION_RATE_2",
            "DL_TRNG_DECIMATION_RATE_3"];
        if (avoidedDecRates.includes(inst.decimationRate))
        {
            validation.logWarning(
                "TI recommends using decimate-by-4 or greater when using the TRNG in cryptographic applications.",
                inst, "decimationRate"
            );
        }

        /*
         * Inform customers that they must handle failures in the
         * digital/analog start up self tests
         */
        if (inst.executeDigitalBlockSelfTest ||
            inst.executeAnalogBlockSelfTest)
        {
            validation.logInfo(
                "Refer to the Health Tests section of the TRM on how to handle test failures.",
                inst,
                ["executeDigitalBlockSelfTest", "executeAnalogBlockSelfTest"]
            );
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
    /* TRNG has no pinmux requirements */
    return ([]);
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
    return (true);
}

/************************* Profiles functions *******************************/
const profilesTRNG = [
    {
        name: "trngBasic",
        clockDivider: "DL_TRNG_CLOCK_DIVIDE_2",
        decimationRate: "DL_TRNG_DECIMATION_RATE_4",
        enabledInterrupts: [],
        interruptPriority: "DEFAULT"
    },
];

function onChangeSetCustomProfile(inst, ui)
{
    inst.profile = "CUSTOM";
}

function onChangeTRNGProfile(inst, ui)
{
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = profilesTRNG.filter(obj =>
                                        {return obj.name === inst.profile});
        if (selectedProfileArray.length != 0)
        {
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
    }
}

/* onChange functions */
function onChangeClockDivider(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeDecimationRate(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeInterrupts(inst,ui)
{
    updateGUIInterrupts(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function updateGUIInterrupts(inst, ui){
    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
}

let trngConfig = [
    {
        name: "GROUP_PROFILE",
        displayName: "Quick Profiles",
        description: "",
        collapsed: false,
        config: [
            {
                name: "profile",
                displayName: "TRNG Profiles",
                description: "Pre-defined profiles for typical TRNG configurations",
                longDescription: `
The true random number generator (TRNG) module securely generates random 32-bit
numbers through an internal analog entropy source and digital conditioning/decimation blocks.
The TRNG can be used as an entropy source to derive true random seed values when
implementing a deterministic random bit generator (DRBG). The TRNG is suitable
for use in creating a DRBG system which can pass the NIST SP800-22 statistical
test suite for cryptographic random number generators.

![TRNG Block Diagram](../docs/english/sysconfig/images/trngBlockDiag.png "TRNG Block Diagram")

The Quick Profile Options are:
* **TRNG using MCLK/2**:
    * Configures the TRNG with a frequency for proper operation and a decimation
      rate required to obtain the minimum entropy to pass the NIST SP800-22
      statistical test suite.
    * Clock Divider: Divide by 2
    * Decimation Rate: Decimate by 4
* **Custom**:
    * Allows custom configuration
`,
                hidden: false,
                default: "trngBasic",
                options: [
                    {name: "trngBasic", displayName: "TRNG using MCLK/2"},
                    {name: "CUSTOM", displayName: "Custom"},
                ],
                onChange: onChangeTRNGProfile,
            },
        ],
    },
]

const clockDividerOptions = [
    {name: "DL_TRNG_CLOCK_DIVIDE_1", displayName: "Divide by 1"},
    {name: "DL_TRNG_CLOCK_DIVIDE_2", displayName: "Divide by 2"},
    {name: "DL_TRNG_CLOCK_DIVIDE_4", displayName: "Divide by 4"},
    {name: "DL_TRNG_CLOCK_DIVIDE_6", displayName: "Divide by 6"},
    {name: "DL_TRNG_CLOCK_DIVIDE_8", displayName: "Divide by 8"},
];

const decimationRateOptions = [
    {name: "DL_TRNG_DECIMATION_RATE_1", displayName: "Decimation by 1 (no decimation)"},
    {name: "DL_TRNG_DECIMATION_RATE_2", displayName: "Decimation by 2 (skip every other sample)"},
    {name: "DL_TRNG_DECIMATION_RATE_3", displayName: "Decimation by 3 (take every 3rd sample)"},
    {name: "DL_TRNG_DECIMATION_RATE_4", displayName: "Decimation by 4 (take every 4th sample)"},
    {name: "DL_TRNG_DECIMATION_RATE_5", displayName: "Decimation by 5 (take every 5th sample)"},
    {name: "DL_TRNG_DECIMATION_RATE_6", displayName: "Decimation by 6 (take every 6th sample)"},
    {name: "DL_TRNG_DECIMATION_RATE_7", displayName: "Decimation by 7 (take every 7th sample)"},
    {name: "DL_TRNG_DECIMATION_RATE_8", displayName: "Decimation by 8 (take every 8th sample)"},
];

trngConfig = trngConfig.concat([
    /****** BASIC CONFIGURATION *******/
    {
        name: "GROUP_BASIC",
        displayName: "Basic Configuration",
        description: "",
        longDescription:'',
        collapsed: false,
        config: [
            {
                name: "sourceClock",
                displayName: "Source Clock",
                description: "MCLK sources the TRNG module",
                default: "",
                getValue: (inst) => {
                    return ("MCLK");
                }
            },
            {
                name: "sourceClockFreq",
                displayName: "Source Clock Frequency",
                description: "The frequency of the clock that sources the TRNG",
                default: "0 Hz",
                getValue: (inst) => {
                    return (Common.getUnitPrefix(system.modules["/ti/driverlib/SYSCTL"].$static.MCLK_Freq).str + "Hz");
                }
            },
            /* DL_TRNG_setClockDivider */
            {
                name: "clockDivider",
                displayName: "TRNG Clock Divider",
                description: "Clock divider to set the TRNG clock frequency within range",
                /*
                 * Given the MCLK default frequency of 32MHz, the divider
                 * should be 2 to prevent an error when adding the TRNG module
                 */
                default: "DL_TRNG_CLOCK_DIVIDE_2",
                options: clockDividerOptions,
                onChange: onChangeClockDivider,
            },
            {
                name: "clockFreqWithUnits",
                displayName: "Calculated TRNG Clock Frequency",
                description: "Calculated TRNG Clock Frequency",
                longDescription: `
The TRNG functional clock is derived from MCLK, and the TRNG requires a
functional clock with a typical frequency of 10 MHz.\n
The allowed frequency range for the TRNG is typically 9.5 to 25 MHz
(see device-specific data sheet for allowed TRNG frequency range on a given device).
`,
                hidden: false,
                default: "0 Hz",
                getValue: (inst) => {
                    /* Extract the clock divider and convert to int */
                    let clockDivider = parseInt((inst.clockDivider).match("[0-9]+")[0]);
                    let clockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.MCLK_Freq / clockDivider;

                    /*
                     * getUnitPrefix returns the numerical value + unit prefix
                     * i.e. 32M as an object
                     */
                    let clockFreqUnit = Common.getUnitPrefix(clockFreq);
                    return (clockFreqUnit.str + "Hz");
                }
            },
            /*
             * The clock frequency without units. Mainly used in the background
             * for validation purposes and for other calculations. Hidden for
             * the user as clockFreqWithUnits is more user-friendly
             */
            {
                name: "clockFreq",
                displayName: "Calculated TRNG Clock Frequency",
                description: "Calculated TRNG Clock Frequency",
                longDescription: ``,
                hidden: true,
                default: 0,
                getValue: (inst) => {
                    /* Extract the clock divider and convert to int */
                    let clockDivider = parseInt((inst.clockDivider).match("[0-9]+")[0]);

                    let clockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.MCLK_Freq / clockDivider;
                    return (clockFreq);
                }
            },
            /* DL_TRNG_setDecimationRate */
            {
                name: "decimationRate",
                displayName: "Decimation Rate",
                description: "Decimation rate to increase the entropy",
                longDescription: `
Within the TRNG digital block, a decimation block is provided to increase the
overall entropy of the TRNG by merging the entropy from a configurable number
of samples. The decimation block accumulates bits from the conditioning block
and decimates down to 1 sample every *n* samples, where *n* is the decimation
value.\n
A decimation rate of decimate-by-4 or greater is required to obtain the
minimum entropy to pass the NIST SP800-22 statistical test suite. TI recommends
using decimate-by-4 or greater when using TRNG in cryptographic applications.
`,
                default: "DL_TRNG_DECIMATION_RATE_4",
                options: decimationRateOptions,
                onChange: onChangeDecimationRate,
            },
            {
                name: "entropyGenerationCycles",
                displayName: "Calculated Entropy Gen Cycles",
                description: "Number of clock cycles required to capture 32 random bits based on the selected decimation rate",
                longDescription: `Number of clock cycles required to capture 32 random bits based on the selected decimation rate`,
                hidden: false,
                default: 0,
                getValue: (inst) => {
                    /* Extract the decimation rate and convert to int */
                    let decimationRate = parseInt((inst.decimationRate).match("[0-9]+")[0]);
                    let numberOfRandomBits = 32;
                    return (decimationRate * numberOfRandomBits);
                }
            },
            {
                name: "entropyGenerationLatency",
                displayName: "Calculated Entropy Gen Latency",
                description: "Total latency required to capture 32 random bits",
                longDescription: `Total latency required to capture 32 random bits`,
                hidden: false,
                default: "0 s",
                getValue: (inst) => {
                    let latencyUnit = Common.getUnitPrefix(inst.entropyGenerationCycles / inst.clockFreq);
                    return (latencyUnit.str + "s")
                }
            },
            {
                name: "executeDigitalBlockSelfTest",
                displayName: "Execute Digital Block Start Up Self Test",
                description: "Checks to see if the digital block is functioning properly",
                //TODO: Hidden for now. More testing is needed and requires follow up with Systems/Design
                hidden: true,
                default: false,
            },
            {
                name: "executeAnalogBlockSelfTest",
                displayName: "Execute Analog Block Start Up Self Test",
                description: "Checks to see if the analog block is functioning properly",
                //TODO: Hidden for now. More testing is needed and requires follow up with Systems/Design
                hidden: true,
                default: false,
            },
        ]
    },
    /* Retention configurable */
    {
        name: "GROUP_RETENTION",
        displayName: "Retention Configuration",
        description: "",
        longDescription: ``,
        collapsed: false,
        config: Common.getRetentionConfig(),
    },
])

const interruptOptions = [
    {name: "DL_TRNG_INTERRUPT_HEALTH_FAIL_EVENT", displayName: "Health test failed"},
    {name: "DL_TRNG_INTERRUPT_CMD_DONE_EVENT", displayName: "Issued CMD has completed"},
    {name: "DL_TRNG_INTERRUPT_CMD_FAIL_EVENT", displayName: "Issued CMD has failed"},
    {name: "DL_TRNG_INTERRUPT_CAPTURE_RDY_EVENT", displayName: "32-bit data word of random data available to be read"},
];

trngConfig = trngConfig.concat([
    /****** INTERRUPT CONFIGURATION *******/
    {
        name: "GROUP_INTERRUPTS",
        displayName: "Interrupt Configuration",
        description: "",
        collapsed: true,
        longDescription: '',
        config: [
            /* DL_TRNG_enableInterrupt */
            {
                name: "enabledInterrupts",
                displayName: "Enable Interrupts",
                description: "",
                default: [],
                minSelections: 0,
                options: interruptOptions,
                onChange: onChangeInterrupts,
            },
            {
                name: "interruptPriority",
                displayName: "Interrupt Priority",
                description: "Specifies interrupt priority",
                longDescription: `
The TRNG interrupt is placed in the INT_GROUP1 peripheral group,
thus their interrupt priority is tied to other members of the group.

INT_GROUP1:
* GPIO (all)
* COMP
* TRNG
                `,
                hidden: true,
                default: "DEFAULT",
                options: Common.InterruptPriorityOptions,
            },
        ]
    },
])

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: trngConfig,

    /* override generic requirements with  device-specific reqs (if any) */
    validate: validate,

    validatePinmux: validatePinmux,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

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
    /* Special static extend */
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    /* moduleStatic specific to TRNG as it's statically defined */
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
