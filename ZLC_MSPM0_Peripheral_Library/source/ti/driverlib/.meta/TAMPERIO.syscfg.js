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
 *  ======== TAMPERIO.syscfg.js ========
 */

"use strict";

/* get Common /ti/drivers utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let logError = Common.logError;
let logWarning = Common.logWarning;
let logInfo = Common.logInfo;

/* generic configuration parameters for GPIO instances */
let tamperioConfig = [

];

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
 *  Define the base properties and methods
 */
let base = {
    displayName: "TAMPER IO",
    description: "Tamper IO Module for MSPM0",
    defaultInstanceName: "TAMPERIO",
    longDescription: `
The **Tamper I/O (TIO) module** is part of the LFSS IP and is a GPIO which is sourced by the VBAT power domain.
The I/O’s have two modes of operation. In IOMUX mode the tamper I/O input and
output path are connected to the SoC IOMUX module and the I/O’s can be used as a 2nd function like SPI, UART or Timer PWM.
The second mode is the Tamper mode. In this mode the I/O  will remain functional during the power loss of the main supply or during SHUTDOWN mode.
Similar to the GPIO module, the tamper I/O can be configured in input or output mode. For the input mode operation, the I/O can be configured with an internal pull-up or
pull-down resistor connected to the I/O pad.
The tamper mode also supports several LFSS related internal secondary functions:
- Tamper event detection
- Timestamp event output
- Heart beat generator
- LF-Clock output

        `,
    initPriority: -1,
    uiAdd: "staticOnly",

    moduleStatic: {
        config: tamperioConfig,
    },

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/tamperio/TAMPERIO.Board.c.xdt",
        boardh: "/ti/driverlib/tamperio/TAMPERIO.Board.h.xdt",
        Call: true,
        Reset: false,
        Power: false,
        GPIO: false,
        Function: true,
    },

    _getPinResources: _getPinResources
};

/* extend the base exports to include family-specific content */
let deviceTIO = system.getScript("/ti/driverlib/tamperio/TAMPERIOMSPM0");
exports = deviceTIO.extend(base);
