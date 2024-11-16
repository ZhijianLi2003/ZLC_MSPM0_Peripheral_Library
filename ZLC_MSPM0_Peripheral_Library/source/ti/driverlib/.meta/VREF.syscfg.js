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
 *  ======== VREF.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for DEBUG instances */
let vrefConfig = []; /* nothing (yet) beyond generic driver configs */


/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    return;
}

/*
 *  ======== base ========
 *  Define the base VREF properties and methods
 */
let base = {
    displayName: "VREF",
    description: "VREF Module for MSPM0",
    defaultInstanceName: "VREF",
    longDescription: `
The **VREF module** for the MSPM0Gxx family is a shared voltage reference module
which can be leveraged by a variety of on-board analog peripherals.

Under *Basic Configuration* users can:
- Choose between internal or external reference mode
- Configure VREF+/VREF-

Under *Advanced Configuration* users can:
- Configure a clock source
- Enable and congfiure sample-and-hold mode

This module supports interfacing with other peripherals:
- VREF to ADC
- VREF to COMP
- VREF to DAC
- VREF to OPA

VREF Block Diagram:

![VREF Block Diagram](../docs/english/sysconfig/images/vrefBlockDiag.png "VREF Block Diagram")

Check the datasheet of your selected device for more detailed information.
    `,
    initPriority: -1,
    uiAdd: "staticOnly",

    moduleStatic: {
        config: vrefConfig,
        modules:             Common.autoForceModules(["SYSCTL", "Board"]),

    },

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/vref/VREF.Board.c.xdt",
        boardh: "/ti/driverlib/vref/VREF.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true
    },

    _getPinResources: _getPinResources // Ignore
};

let deviceVREF = system.getScript("/ti/driverlib/vref/VREFMSPM0");

exports = deviceVREF.extend(base);
