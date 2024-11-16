/*
 * Copyright (c) 2018-2019, Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== RTC.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for DEBUG instances */
let RTCConfig = []; /* nothing (yet) beyond generic driver configs */

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    // Common.validateNames(inst, validation);
}

/*
 *  ======== _getPinResources ========
 */
/* istanbul ignore next */
function _getPinResources(inst)
{
    return;
}


/*
 *  ======== base ========
 *  Define the base RTC properties and methods
 */
let base = {
    displayName: "RTC",
    description: "RTC module for MSPM0",
    defaultInstanceName: "RTC",
    longDescription: `
The **Real-Time Clock (RTC) module** provides time-keeping for the application,
with counters for seconds, minutes, hours, day of the week, day of the
month, and year.

Under *Alarm Configuration* users can
- Set up to 2 Calendar alarms based on settings contained in the alarm registers
- Set an Interval alarm on these conditions:
    - MIN changes
    - HOUR changes
    - Every day at midnight
    - Every day at noon
- Set up to 2 Periodic alarms to generate 2 periodic time bases for the application.

Check the datasheet of your selected device for more detailed information.
    `,
    validate: validate,
    uiAdd: "staticOnly",

    moduleStatic: {
        config: RTCConfig,
        modules: Common.autoForceModules(["SYSCTL", "Board"]),
    },

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/rtc/RTC.Board.c.xdt",
        boardh: "/ti/driverlib/rtc/RTC.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true
    },



    _getPinResources: _getPinResources
};

let deviceRTC = system.getScript("/ti/driverlib/rtc/RTCMSPM0");

exports = deviceRTC.extend(base);
