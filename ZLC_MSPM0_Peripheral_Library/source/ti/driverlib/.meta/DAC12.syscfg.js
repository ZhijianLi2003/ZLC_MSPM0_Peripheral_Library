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
 *  ======== DAC12.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for DAC12 instances */
let dac12Config = []; /* nothing (yet) beyond generic driver configs */

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    Common.validateNames(inst, validation);
}

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    return;
}


/*
 *  ======== base ========
 *  Define the base DAC12 properties and methods
 */
let base = {
    displayName: "DAC12",
    description: "DAC12 Module for MSPM0",
    longDescription: `
The **DAC module** allows the user to configure
an 8-bit or 12-bit voltage-output DAC that can be used in conjunction with the system DMA

Under *Basic Configuration* users can:
- Configure voltage references
- Enable FIFO, sample time generator, and DAC output
- Configure DMA trigger
- Configure a specific DMA channel

Under *Advanced configuration* users can:
- Configure output resolution, input data format, and input/output amplifiers

DAC Block Diagram:

![DAC Block Diagram](../docs/english/sysconfig/images/dacBlockDiag.png "DAC Block Diagram")

Check the datasheet of your selected device for more detailed information.
    `,
    defaultInstanceName: "DAC12",
    uiAdd: "staticOnly",
    moduleStatic:{
        config: dac12Config,
        modules: Common.autoForceModules(["Board", "SYSCTL", "EVENT"]),
            /* override device-specific templates */

    },
    templates: {
        boardc: "/ti/driverlib/dac12/DAC12.Board.c.xdt",
        boardh: "/ti/driverlib/dac12/DAC12.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true
    },

    validate: validate,

    _getPinResources: _getPinResources // Ignore
};

let deviceDAC12 = system.getScript("/ti/driverlib/dac12/DAC12MSPM0");

exports = deviceDAC12.extend(base);
