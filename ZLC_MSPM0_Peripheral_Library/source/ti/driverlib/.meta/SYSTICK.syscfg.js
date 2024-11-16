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
 *  ======== SYSTICK.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for DEBUG instances */
let SYSTICKConfig = []; /* nothing (yet) beyond generic driver configs */

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
 *  Define the base SYSTICK properties and methods
 */
let base = {
    displayName: "SYSTICK",
    description: "SYSTICK module for MSPM0",
    defaultInstanceName: "SYSTICK",
    longDescription: `
The **System Tick Timer (SYSTICK) module** is a tightly-coupled timer
clocked by MCLK, which can be used for system time keeping.

The SysTick timer is a simple 24-bit down counter, which can be used in
several differen ways. Examples include:

As an RTOS timer which fires at a programmable rate (for example, 100Hz)
and invokes a SysTick routine
- A high-speed alarm timer
- A simple counter used to measure time to completion and time used in an application
- A timeout counter to check that a routine has not timed out within a specified period

Check the datasheet of your selected device for more detailed information.
    `,
    validate: validate,
    uiAdd: "staticOnly",

    moduleStatic: {
        config: SYSTICKConfig,
        modules: Common.autoForceModules(["SYSCTL", "Board"]),
    },

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/systick/SYSTICK.Board.c.xdt",
        boardh: "/ti/driverlib/systick/SYSTICK.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: false,
        Function: true
    },



    _getPinResources: _getPinResources
};

let deviceSYSTICK = system.getScript("/ti/driverlib/systick/SYSTICKMSPM0");

exports = deviceSYSTICK.extend(base);
