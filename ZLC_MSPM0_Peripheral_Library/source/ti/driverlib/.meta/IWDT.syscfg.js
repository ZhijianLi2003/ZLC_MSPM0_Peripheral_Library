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
 *  ======== IWDT.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for WDT instances */
let iwdtConfig = []; /* nothing (yet) beyond generic driver configs */

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    return;
}

/*
 *  ======== base ========
 *  Define the base IWDT properties and methods
 */
let base = {
    displayName: "IWDT",
    description: "IWDT Module for MSPM0",
    defaultInstanceName: "IWDT",
    longDescription: `
The **Independent Watchdog timer (IWDT)** is part of the LFSS IP and is an SoC independent supervisor which monitors code execution
and overall hang up scenarios of the SoC. Due to the nature of the LFSS IP, this WDT has its own system
independent power and clock source. If the application software does not successfully reset the watchdog within
the programmed time, the watchdog generates a POR reset to the SoC.

Under *Basic Configuration* users can:
- Configure the clock divider and frequency
- Configure IWDT period
- Enable IWDT to continue running when the CPU is halted for debug
- Enable lock function protection of WDT registers so they cannot be changed after initial configuration on accident by software or
    during an address transient error during an intentional write access

Check the datasheet of your selected device for more detailed information.
    `,
    initPriority: -1,
    uiAdd: "staticOnly",
    moduleStatic: {
        config: iwdtConfig,
        modules: Common.autoForceModules(["Board"]),

    },

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/iwdt/IWDT.Board.c.xdt",
        boardh: "/ti/driverlib/iwdt/IWDT.Board.h.xdt",
        Call: true,
        Reset: false,
        Power: false,
        GPIO: false,
        Function: true,
    },

    _getPinResources: _getPinResources // Ignore
};

let deviceIWDT = system.getScript("/ti/driverlib/iwdt/IWDTMSPM0");

exports = deviceIWDT.extend(base);
