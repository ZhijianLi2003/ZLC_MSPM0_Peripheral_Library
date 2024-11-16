/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== MODULE.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for Non Main */
let nonMainConfig = []; /* nothing (yet) */


/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    return;
}


/*
 *  ======== base ========
 *  Define the base NONMAIN properties and methods
 */
let base = {
    displayName: "Configuration NVM",
    description: "Configuration NVM (NONMAIN) Configurator Module for MSPM0",
    longDescription: `
The **Configuration NVM (NONMAIN) Configurator** assists the user in modifying the configuration
policies for the start-up boot routines by altering the values programmed into
the Configuration NVM flash region.

After a BOOTRST, the device always executes the start-up boot routines from
read-only memory (ROM) to configure the device for operation before starting
the main application. There are two boot routines: the **boot configuration
routine (BCR)**, and the **bootstrap loader (BSL)**.

The **BCR** sets up the device security policies, configures the device for
operation, and optionally starts the BSL.

The **BSL**, if started by the BCR, can be used to program and/or verify the
device memory (flash and SRAM) through the use of a standard serial
interface (UART or I2C).
`,
    //TODO: does this ever change? Event module has this as 0
    initPriority: -1,
    uiAdd: "staticOnly",

    moduleStatic: {
        config: nonMainConfig,
        // /*
        //  * Force Board module to be loaded so that ti_msp_dl_config.h is
        //  * generated as well. The boot files include this at the top
        //  */
        // modules: Common.autoForceModules(["Board"]),
    },

    /* override device-specific templates */
    templates: {
        "/ti/driverlib/nonmain/NonMain.c.xdt" : true,
        "/ti/driverlib/nonmain/NonMain.h.xdt" : true,
    },

    _getPinResources: _getPinResources // Ignore
};

let deviceNonMain = system.getScript("/ti/driverlib/nonmain/NONMAINMSPM0");

exports = deviceNonMain.extend(base);
