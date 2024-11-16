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
 *  ======== SYSCTL.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for SYSCTL instances */
let sysctlConfig = []; /* nothing (yet) beyond generic driver configs */


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
 *  Define the base SYSCTL properties and methods
 */
let base = {
    displayName: "SYSCTL",
    description: "System Control Module. Controls Power and Clocking",
    defaultInstanceName: "SYSCTL",
    longDescription: `
The **SYSCTL (System Control) module** allows you to configure power and clocking
for your specific application.

Under *Power & Systems Configuration* users can:
- Specify what power policy the device will use
- Set BOR threshold
- Enable/Disable:
    - Write lock
    - Sleep on exit
    - processor wakeup on pending events
    - NRST pin functionality
- Enable and configure frequency clock counter (FCC)
- Enable FlashCtl and power/system interrupts

Under *Clock Configuration* users can:
- Configure clocks:
    - Main Clock (MCLK)
    - Middle Frequency Clock (MFCLK)
    - Low Frequency Clock (LFCLK)
    - Middle Frequency Precision Clock (MFPCLK)
    - Low Power Clock (ULPCLK)
    - High Frequency Clock (HFCLK)
- Configure oscillators
    - Internal Oscillators (SYSOSC, SYSPLL)
    - External Oscillators (High/low frequency crystal oscillators)
- Configure clock interrupts
- View all clock output frequencies

Check the datasheet of your selected device for more detailed information.
    `,
    initPriority: -1,
    uiAdd: "staticOnly",

    moduleStatic: {
        config: sysctlConfig,
        modules: Common.autoForceModules(["Board"]),

    },

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/sysctl/SYSCTL.Board.c.xdt",
        boardh: "/ti/driverlib/sysctl/SYSCTL.Board.h.xdt",
        Call: true,
        Reset: false,
        Power: false,
        GPIO: true,
        Function: true
    },

    //_getPinResources: _getPinResources
};

let deviceSYSCTL = system.getScript("/ti/driverlib/sysctl/SYSCTLMSPM0");

exports = deviceSYSCTL.extend(base);
