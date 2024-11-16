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
 *  ======== RTCAMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let RTCCommon = system.getScript("/ti/driverlib/RTC.common.js");

function onChangeRTCAProfile(inst, ui) {
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = RTCCommon.getProfileConfig("RTC_A").filter(obj =>
                                        {return obj.name === inst.profile});
        if (selectedProfileArray.length != 0)
        {
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
    }
    RTCCommon.checkAlarms(inst, ui);
}

let rtc_a_Config = [
    /****** PROFILES CONFIGURATION *******/
    {
        name: "RTC_Config",
        displayName: "Real Time Clock (RTC) Configuration",
        description: "",
        collapsed: false,
        config: [
            {
                name        : "profile",
                displayName : "RTC Profiles",
                description : 'Pre-defined profiles for typical RTC configurations',
                longDescription: `
The real-time clock (RTC_A) module is part of the LFSS IP and
provides time-keeping for the application, with counters for seconds, minutes,
hours, day of the week, day of the month, and year, in selectable binary or binary-coded decimal (BCD) format.
A variety of programmable interrupt alarms are provided.

The Quick Profile Options are:
* **Calendar Alarm 1 at 4:30 Saturday, 15th day, Binary Format**:
    * RTC Format: Binary
    * Calendar Alarm 1 Enabled
        * Minute: 30
        * Hour: 4
        * Day of Week: Saturday
        * Day of Month: 15
    * Interrupts Enabled: Calendar Alarm 1 Interrupt

* **Calendar Alarm 2 at 00:00 Tuesday, BCD Format**:
    * RTC Format: BCD
    * Calendar Alarm 2 Enabled
        * Day of Week: Tuesday
    * Interrupts Enabled: Calendar Alarm 2 Interrupt

* **Interval Alarm at every minute change, BCD Format**:
    * RTC Format: BCD
    * Interval Alarm Enabled
        * Every Minute
    * Interrupts Enabled: Interval Alarm Interrupt

* **Periodic Alarm 0 at 1024 Hz, Binary format**:
    * RTC Format: Binary
    * Periodic Alarm 0 Enabled
        * Alarm frequency is 1024 Hz (Prescalar 0 Divider is 32)
    * Interrupts Enabled: Prescalar 0 Interrupt

* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "CUSTOM",
                options     : [

                    {name: "CUSTOM", displayName: "Custom"},
                    {name: "CONFIG_PROFILE_1", displayName: "Calendar Alarm 1 at 4:30 Saturday, 15th day, Binary Format"},
                    {name: "CONFIG_PROFILE_2", displayName: "Calendar Alarm 2 at 00:00 Tuesday, BCD Format"},
                    {name: "CONFIG_PROFILE_3", displayName: "Interval Alarm at every minute change, BCD Format"},
                    {name: "CONFIG_PROFILE_4", displayName: "Periodic Alarm 0 at 1024 Hz, Binary Format"},
                ],
                onChange    : onChangeRTCAProfile,
            },
        ],
    },
]

rtc_a_Config = rtc_a_Config.concat(RTCCommon.getBasicConfig(undefined, undefined, "RTC_A"));

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

function validate(inst, validation)
{
    validation.logWarning("Note: VBAT needs to be powered for RTC_A operation.", inst);

    RTCCommon.getValidation(inst,validation);
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
    let resources = [];

    let RTCAOut = {
        name              : "rtcaOutPin",  /* config script name */
        displayName       : "RTC_A Out Pin", /* GUI name */
        interfaceNames    : ["RTC_OUT"]   /* pinmux tool name */
    };
    resources.push(RTCAOut);


    let rtc_a = {
        name          : "peripheral",
        displayName   : "RTC_A Peripheral",
        interfaceName : "LFSS",
        canShareWith  : "LFSS",
        resources     : resources,
        signalTypes   : {
            rtcOut     : ['RTC_OUT'],
        }
    };
    return [rtc_a];
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

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: rtc_a_Config,

    /* override generic requirements with  device-specific reqs (if any) */
    validate: validate,

    pinmuxRequirements: pinmuxRequirements,

    modules: setRequiredModules,

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
    /* moduleStatic specific to LFSS as it's statically defined */
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
