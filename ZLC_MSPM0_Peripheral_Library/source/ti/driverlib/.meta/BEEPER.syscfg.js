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
 *  ======== BEEPER.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for BEEPER instances */
let beeperConfig = []; /* nothing (yet) beyond generic driver configs */

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    return;
}


/*
 *  ======== base ========
 *  Define the base BEEPER properties and methods
 */
let base = {
    displayName: "Beeper",
    description: "Beeper Module for MSPM0",
    longDescription: `
Beeper function is used to generate square wave outputs. A fixed frequency
MFCLK (4MHz) is divided down to generate the BEEP output. The following
output frequencies are supported: 1, 2, 4 or 8 KHz.

![Beeper Circuit](../docs/english/sysconfig/images/beeperCircuit.png "Beeper Circuit")
    `,
    defaultInstanceName: "BEEPER",
    initPriority: -1,
    uiAdd: "staticOnly",

    moduleStatic: {
        config: beeperConfig,
    },

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/beeper/BEEPER.Board.c.xdt",
        boardh: "/ti/driverlib/beeper/BEEPER.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true,
    },

    _getPinResources: _getPinResources // Ignore
};

let deviceBEEPER = system.getScript("/ti/driverlib/beeper/BEEPERMSPM0");

exports = deviceBEEPER.extend(base);
