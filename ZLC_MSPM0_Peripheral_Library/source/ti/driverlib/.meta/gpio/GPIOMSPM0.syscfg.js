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
 *  ======== GPIOMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/drivers utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");




let gpioConfig = [
    {
        name: "$name",
        defaultPrefix: "GPIO_GRP_",
        hidden: false
    },
    {
        name: "port",
        displayName: "Port",
        description: "Optional Port that all GPIO pins must be from",
        default: "Any",
        options: (inst) => {
            let portOptions = [
                {name: "Any"},
            ];
            if(Common.hasGPIOPortA()){
                portOptions.push(
                    {name: "PORTA"}
                )
            }
            if(Common.hasGPIOPortB()){
                portOptions.push(
                    {name: "PORTB"}
                )
            }
            if(Common.hasGPIOPortC()){
                portOptions.push(
                    {name: "PORTC"}
                )
            }
            return portOptions;
        }
    },
    {
        name: "portSegment",
        displayName: "Port Segment",
        description: "Optionally select wheter all pins are in the upper or lower section of the port",
        default: "Any",
        options: [
            {name: "Any"},
            {name: "Lower"},
            {name: "Upper"},
        ]
    },
    {
        name: "groupPins",
        displayName: "GPIO Pins",
        longDescription:
`Configuration for the specified group of pins
`,
        collapsed: false,
        config: [

        ]
    }, /****** End of BASIC CONFIGURATION *******/
];

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base GPIO configuration
 */
let devSpecific = {
    config: gpioConfig,

    //pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    moduleInstances: moduleInstances,

    templates: {
        boardc : "/ti/driverlib/gpio/GPIO.Board.c.xdt",
        boardh : "/ti/driverlib/gpio/GPIO.Board.h.xdt",
        Call: false,
        Reset: false,
        Power: false,
        GPIO: true,
        Function: false
    },

    validate: validate,

    _getPinResources: _getPinResources
};

/*
 *  ======== moduleInstances ========
 *  Add individual GPIO groups
 */
function moduleInstances(inst) {
    let modInstances = new Array();
    let firstCollapse = false;

    let longDescription = ``;
    let modInst = {
        name: "associatedPins",
        displayName: "Group Pins",
        useArray: true,
        defaultInstanceCount: 1,
        minInstanceCount: 1,
        longDescription: longDescription,
        //group: "groupPins",
        collapsed: firstCollapse,
        moduleName: "/ti/driverlib/gpio/GPIOPin",
        hidden: false,
        args: {
            //parentName: inst.$name,
            //$name: inst.$name + "_PIN_" + pin;
        },
        requiredArgs: {
            //assignedPort: inst.port,
            //assignedPortSegment: inst.portSegment,
        }
    };
    if(inst.port !== "Any"){
        modInst.requiredArgs.assignedPort = inst.port;
    } else {
        modInst.args.assignedPort = inst.port;
    }
    if(inst.portSegment !== "Any"){
        modInst.requiredArgs.assignedPortSegment = inst.portSegment;
    } else {
        modInst.args.assignedPortSegment = inst.portSegment;
    }
    modInstances.push(modInst);
    firstCollapse = true;

    return (modInstances);
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
   return true;
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
    /* Only one pin can be subscribed to an event per port segment */

    /* Only one event channel can be selected per port segment */

    /* Check input IOMux parameters based on what the pin is capable of */
    /* Look for IOMux Structure */
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
    if(system.deviceData.package !== "LQFP-64(PM)"){
        delete devSpecific.moduleStatic;
    }
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base, devSpecific);



    result.config = base.config.concat(devSpecific.config);

    return (result);
}

/*
 *  ======== exports ========
 *  Export device-specific extensions to base exports
 */
exports = {
    extend: extend
};
