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
 *  ======== COMP.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for DEBUG instances */
let debugConfig = []; /* nothing (yet) beyond generic driver configs */


/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    // IGNORE FOR NOW - Jackson 8/5/21
    return;
}


/*
 *  ======== base ========
 *  Define the base COMP properties and methods
 */
let base = {
    displayName: "COMP",
    description: "",
    longDescription: `
The **Comparator module** can be useful for supply voltage supervision and
monitoring of external analog signals.

Under *Basic Configuration* users can:
- Configure operating modes, inputs, and outputs
- Enable programmable hysteresis voltages (in fast and ultra-low-power modes)
- Configure reference voltage generation

Under *Advanced Configuration* users can:
- Change input configurations
- Configure interrupts
- Enable output filters, windowing, and blanking

Comparator Block Diagram:

![Comparator Block Diagram](../docs/english/sysconfig/images/compBlockDiag.png "Comparator Block Diagram")

Check the datasheet of your selected device for more detailed information.
    `,
    defaultInstanceName: "COMP_",
    config: Common.addNameConfig(debugConfig, "/ti/driverlib/COMP", "COMP_"),
    modules: Common.autoForceModules(["Board", "SYSCTL"]),

    _getPinResources: _getPinResources // Ignore
};

let deviceDEBUG = system.getScript("/ti/driverlib/comp/COMPMSPM0");

exports = deviceDEBUG.extend(base);
