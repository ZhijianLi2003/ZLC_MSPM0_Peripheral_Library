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
 *  ======== WWDT.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for DEBUG instances */
let WWDTConfig = []; /* nothing (yet) beyond generic driver configs */

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

let maxInstances = system.deviceData.interfaces["WWDT"].peripherals.length;
/*
 *  ======== base ========
 *  Define the base WWDT properties and methods
 */
let base = {
    displayName: "WWDT",
    description: "WWDT module for MSPM0",
    defaultInstanceName: "WWDT",
    longDescription: `
The **Window Watchdog Timer (WWDT) module** is used to initiate a system
restart (SYSRST) when correct operation of the device has failed due to an
unexpected software or system delay.

Under *Basic Configuration* users can:
- Configure the clock source and frequency
- Configure window period settings
- Enable WWDT running during sleep

The WWDT module provides one interrupt source which can be configured to
source a CPU interrupt event. This interrupt indicates that the WWDT interval
timer period has expired.

Check the datasheet of your selected device for more detailed information.
    `,
    validate: validate,

    config: WWDTConfig,
    modules: Common.autoForceModules(["SYSCTL", "Board"]),
    maxInstances: maxInstances,

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/wwdt/WWDT.Board.c.xdt",
        boardh: "/ti/driverlib/wwdt/WWDT.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: false,
        Function: true
    },



    _getPinResources: _getPinResources
};

let deviceWWDT = system.getScript("/ti/driverlib/wwdt/WWDTMSPM0");

exports = deviceWWDT.extend(base);
