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
 *  ======== BEEPERMSPM0.syscfg.js ========
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

}

function pinmuxRequirements(inst)
{
    let resources = [];
    if(inst.beeperEnable){
        resources.push({
            name            : "beeperPin",
            displayName     : "Beeper Output Pin",
            interfaceNames  : ["BEEPER"],
        });
    }
	let sysctl = {
        name          : "peripheral",
        displayName   : "Beeper",
        interfaceName : "SYSCTL",
		canShareWith  : "CLOCK_TREE",
        resources     : resources,
		signalTypes   : {
            beeperPin    : ["BEEPER"],
        }
    };
	if(resources.length > 0){
		return [sysctl];
	} else {
		return [];
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
    return (true);
}

/************************* BEEPER Option Structures *************************/


/************************* Profiles functions *******************************/
const profilesBEEPER = [
    {
        //TODO: Determine supported quick profile options
    },
];

let beeperConfig  = [
    {
        name: "GROUP_BASIC",
        displayName: "Basic Operation Configuration",
        longDescription: `Basic BEEPER options`,
        collapsed: false,
        config: [
            // enableBeeperOutput/disableBeeperOutput
            {
                name: "beeperEnable",
                displayName: "Enable Beeper Output",
                description: "",
                hidden: false,
                default: false,
                onChange: (inst,ui) => {
                    ui.beeperFreq.hidden = !inst.beeperEnable;
                }
            },
            // enableBeeperOutput/disableBeeperOutput
            {
                name: "beeperFreq",
                displayName: "Set Beeper Frequency",
                description: "Set the target frequency of the Beeper output",
                hidden: true,
                default: "1",
                // DL_SYSCTL_BEEPER_FREQ_[...]KHZ
                options: [
                    { name: "1", displayName: "1 KHz"},
                    { name: "2", displayName: "2 KHz"},
                    { name: "4", displayName: "4 KHz"},
                    { name: "8", displayName: "8 KHz"},
                ]
            },
        ]
    },
];

beeperConfig = beeperConfig.concat(getAdvancedGroupConfig());

function getAdvancedGroupConfig()
{
    return [
        {
            name: "GROUP_ADVANCED",
            displayName: "Advanced Operation Configuration",
            longDescription: `Advanced BEEPER options`,
            collapsed: false,
            config: [
                // N/A
            ]
        },
    ];
}

function moduleInstances(inst){
    let modInstances = []
    return modInstances;
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: beeperConfig,

    /* override generic requirements with  device-specific reqs (if any) */
    validate: validate,

    validatePinmux: validatePinmux,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    moduleInstances: moduleInstances,

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
    /* Special static extend */
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    /* moduleStatic specific to BEEPER as it's statically defined */
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
