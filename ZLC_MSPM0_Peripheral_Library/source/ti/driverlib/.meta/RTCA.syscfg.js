/*
 * Copyright (c) 2023-2024, Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== IRTC.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for IRTC instances */
let RTC_A_Config = []; /* nothing (yet) beyond generic driver configs */

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    return;
}

/*
 *  ======== base ========
 *  Define the base IRTC properties and methods
 */
let base = {
    displayName: "RTC_A",
    description: "RTC_A Module for MSPM0",
    defaultInstanceName: "RTC_A",
    longDescription: `
The **Real-Time Clock A (RTC_A) module** is part of the LFSS IP and provides time-keeping
for the application, with counters for seconds, minutes, hours, day of the week, day of the
month, and year.

It also provides a method of generating a time stamp event, which
can be used to keep track of tamper events, configurable via tamper IO pins, or
VDD power loss to the system. Upon detection of one these events, the values in calendar
registers from seconds till years will be copied to a set of time stamp capture registers.

Under *Alarm Configuration* users can
- Set up to 2 Calendar alarms based on settings contained in the alarm registers
- Set an Interval alarm on these conditions:
    - MIN changes
    - HOUR changes
    - Every day at midnight
    - Every day at noon
- Set up to 3 Periodic alarms to generate 3 periodic time bases for the application.

Check the datasheet of your selected device for more detailed information.
    `,
    uiAdd: "staticOnly",

    moduleStatic: {
        config: RTC_A_Config,
    },

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/rtc_a/RTCA.Board.c.xdt",
        boardh: "/ti/driverlib/rtc_a/RTCA.Board.h.xdt",
        Call: true,
        Reset: false,
        Power: false,
        GPIO: true,
        Function: true,
    },

    _getPinResources: _getPinResources // Ignore
};

let deviceRTC_A = system.getScript("/ti/driverlib/rtc_a/RTCAMSPM0");

exports = deviceRTC_A.extend(base);
