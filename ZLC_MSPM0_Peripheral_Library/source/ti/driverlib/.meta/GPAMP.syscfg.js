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
 *  ======== GPAMP.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for DEBUG instances */
let gpampConfig = []; /* nothing (yet) beyond generic driver configs */

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
/* istanbul ignore next */
function _getPinResources(inst)
{
    return;
}


/*
 *  ======== base ========
 *  Define the base GPAMP properties and methods
 */
let base = {
    displayName: "GPAMP",
    description: "GPAMP module for MSPM0",
    longDescription: `
The **GPAMP module** is a chopper stabilized general purpose operational amplifier with
rail-to-rail input and output.

Under *Basic Configuration* users can:
- Configure non-inverting and inverting channels
- Configure chopping

Under *Advanced Configuration* users can configure rail-to-rail input.

GPAMP Block Diagram:

![GPAMP Block Diagram](../docs/english/sysconfig/images/gpAmpBlockDiagM0G3xx.png "GPAMP Block Diagram")

Check the datasheet of your selected device for more detailed information.
    `,
    defaultInstanceName: "GPAMP_",
    config: Common.addNameConfig(gpampConfig, "/ti/driverlib/gpamp", "GPAMP_"),
    validate: validate,
    modules: Common.autoForceModules(["SYSCTL", "Board"]),



    _getPinResources: _getPinResources
};

let deviceGPAMP = system.getScript("/ti/driverlib/gpamp/GPAMPMSPM0");

exports = deviceGPAMP.extend(base);
