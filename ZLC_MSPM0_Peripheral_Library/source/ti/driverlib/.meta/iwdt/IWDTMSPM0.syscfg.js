/*
 * Copyright (c) 2023-2024 Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== WDTMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{

}

/*
 *  ======== validatePinmux ========
 *  Validation run after solution
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validatePinmux(inst, validation) {

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
    validation.logWarning("Note: VBAT needs to be powered for IWDT operation.", inst);

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
    /* IWDT has no pins but shares the LFSS resource */
    let lfss = {
        name          : "peripheral",
        displayName   : "LFSS Peripheral",
        interfaceName : "LFSS",
        canShareWith  : "LFSS",
        resources     : [],
        signalTypes   : {

        }
    };
    return [lfss];
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

/************************* IWDT Option Structures *************************/

/************************* Profiles functions *******************************/
const profilesIWDT = [
    {
        //TODO: Determine supported quick profile options
    },
];

/*
 *  ======== onChangeProfiles ========
 *  Set options based on configuration profiles selection
 */
function onChangeProfiles(inst,ui)
{
    //TODO when profiles are defined
}

function onChangeCustomProfile(inst,ui)
{
    // TODO when profiles are defined
    // inst.chosenProfile = "custom";
}

function getWDTClockSourceFreq(inst) {
    let wdtClockFreq = (system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq) / inst.clockDivider;

    return wdtClockFreq;
}

function getWDTPeriod(inst) {
    let clockDiv = parseInt((inst.clockDivider).match("[0-9]+")[0]);
    let perCount = parseInt((inst.periodCount).match("[0-9]+")[0]);
    perCount = 2**perCount;

    let wdtPer = (clockDiv * perCount) / 32768;

    return wdtPer;
}

let iwdtConfig = [
    {
        name: "GROUP_PROFILE",
        displayName: "Quick Profiles",
        description: "",
        collapsed: false,
        config: [
            {
                name        : "profile",
                displayName : "IWDT Profiles",
                description : 'Pre-defined profiles for typical IWDT configurations',
                longDescription: ``,
                hidden      : true, //TODO: keep hidden until profiles are defined (if it all)
                default     : "TODO: PLACEHOLDER FOR NOW",
            },
        ],
    },
    {
        name: "GROUP_BASIC",
        displayName: "Independent Watchdog Timer (IWDT) Configuration",
        longDescription: `Basic IWDT Configuration Options`,
        collapsed: false,
        config: [
            {
                name: "sourceClock",
                displayName: "IWDT Clock Source",
                description: "LFOSC sources the IWDT",
                hidden: false,
                default: "LFOSC",
                getValue: (inst) => {
                    return ("LFOSC");
                }
            },
            {
                name        : "clockDivider",
                displayName : "IWDT Clock Divider",
                description : 'Clock divider for the IWDT clock source',
        longDescription:
`The IWDT runs from the 32-kHz low-frequency oscillator (LFOSC). A clock divider supports dividing the input clock
from Divide by 1 (no divide) to Divide by 8. The default setting is Divide by 4 (32 kHz divided by 4, or 8 kHz).
`,
                hidden      : false,
                default     : "4",
                options     : [
                    {name: "1", displayName: "Divide by 1"},
                    {name: "2", displayName: "Divide by 2"},
                    {name: "3", displayName: "Divide by 3"},
                    {name: "4", displayName: "Divide by 4"},
                    {name: "5", displayName: "Divide by 5"},
                    {name: "6", displayName: "Divide by 6"},
                    {name: "7", displayName: "Divide by 7"},
                    {name: "8", displayName: "Divide by 8"},
                ],
            },
            {
                name        : "clockSourceCalculated",
                displayName : "Calculated IWDT Source Frequency",
                description : 'The calculated frequency of the IWDT Clock Source in Hz',
                hidden      : false,
                default     : "0Hz",
                getValue    : (inst) => (Common.getUnitPrefix((getWDTClockSourceFreq(inst))).str+'Hz'),
            },
            {
                name        : "periodCount",
                displayName : "IWDT Period Count",
                description : 'Period Count for the IWDT timer',
                longDescription:
`The IWDT has a 25-bit counter which is initially stopped after power up of the LFSS power domain.
The total timer count is selected to be one of 8 possible period count values. \n
The total IWDT period is calculated as follows:\n
TIWDT = (CLKDIV + 1) ∗ PERCOUNT / 32768 Hz
`,
                hidden      : false,
                default     : "12",
                options     : [
                    {name: "6", displayName: "2^6 timer period count"},
                    {name: "8", displayName: "2^8 timer period count"},
                    {name: "10", displayName: "2^10 timer period count"},
                    {name: "12", displayName: "2^12 timer period count"},
                    {name: "15", displayName: "2^15 timer period count"},
                    {name: "18", displayName: "2^18 timer period count"},
                    {name: "21", displayName: "2^21 timer period count"},
                    {name: "25", displayName: "2^25 timer period count"},
                ],
            },
            {
                name        : "periodCalculated",
                displayName : "Calculated IWDT Period",
                description : 'The calculated total IWDT period in seconds',
                longDescription:
`
The total IWDT period is calculated as follows:\n
TIWDT = (CLKDIV + 1) ∗ PERCOUNT / 32768 Hz
`,
                hidden      : false,
                default     : "0s",
                getValue    : (inst) => (Common.getUnitPrefix((getWDTPeriod(inst))).str+'s')
            },
            {
                name        : "enableFreeRun",
                displayName : "Enable Free Run Mode",
                description : "Enables free run mode of IWDT, which continues counting when the CPU is halted for debug.",
                hidden      : false,
                default     : false,
            },
            {
                name        : "enableWriteProtect",
                displayName : "Enable Write Protect",
                description : "Enables Write Protection of WDTEN and WDTCTL registers",
                hidden      : false,
                default     : false,
            },
        ]
    },
];

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: iwdtConfig,

    /* override generic requirements with  device-specific reqs (if any) */
    validate: validate,

    validatePinmux: validatePinmux,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    modules: setRequiredModules,

    _getPinResources: _getPinResources
};

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

/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic module module to
 *  allow us to augment/override as needed for the MSP432.
 */
function extend(base)
{
    // Special static extend

    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    // moduleStatic specific to SYSCTL as it's statically defined
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
