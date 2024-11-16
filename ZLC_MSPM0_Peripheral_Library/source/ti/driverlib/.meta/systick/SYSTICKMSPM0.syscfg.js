/*
 * Copyright (c) 2023 Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== SYSTICKMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

let SYSTICKConfig = [
    {
        name: "GROUP_SYSTICK_CONFIG",
        displayName: "Configuration",
        description: "",
        longDescription:
`
The system tick timer (SysTick) is a simple 24-bit down counter that is part of the Cortex-M architecture. Its
intended purpose is to provide a periodic interrupt for an RTOS, but it can
be used for other simple timing purposes.\n
The SysTick timer counts down from its reload value to zero. Upon
reaching zero, SysTick will re-load the value programmed into the reload value register on the next
clock cycle, and then again begin counting down to zero.
`,
	    collapsed: false,
        config: [
            {
                name        : "periodEnable",
                displayName : "Initialize Period",
                description : 'Enable setting the SysTick Period',
                longDescription:
`
Initializes the System Tick Timer by configuring the desired period. Also resets the counter so that,
once enabled, the SysTick starts counting from 0.\n
Does not start the timer or enable the interrupt.
 `,
                hidden      : false,
                default     : false,
                onChange    : (inst,ui) => {
                    ui.period.hidden = !(inst.periodEnable);
                    ui.calcPeriod.hidden = !(inst.periodEnable);
                },
            },
            // TODO: period range verification. we can set actual number of ticks, and then calculate period?
            {
                name        : "period",
                displayName : "Period (In MCLK Cycles)",
                description : 'The period in MCLK cycles for the SysTick to fire',
                hidden      : true,
                isInteger   : true,
                range       : [0x00000002,0x01000000],
                default     : 0x00000002,
            },
            {
                name: "calcPeriod",
                displayName: "Calculated Period",
                default: "0s",
                hidden: true,
                getValue: (inst) => {
                    let MCLK_Freq = system.modules["/ti/driverlib/SYSCTL"].$static.MCLK_Freq;
                    return (Common.getUnitPrefix(inst.period/MCLK_Freq)).str+"s";
                },

            },
            // DL_SYSTICK_enableInterrupt
            {
                name        : "interruptEnable",
                displayName : "Enable SysTick Interrupt",
                description : 'A SysTick interrupt is generated when the SysTick counter reaches zero.',
                hidden      : false,
                default     : false,
                onChange    : (inst, ui) => {
                    ui.interruptPriority.hidden = !inst.interruptEnable;
                }
            },
            {
                name: "interruptPriority",
                displayName: "Interrupt Priority",
                description: "Specifies interrupt priority",
                longDescription: '',
                hidden: true,
                default: "DEFAULT",
                options: Common.InterruptPriorityOptions,
            },
            // DL_SYSTICK_init
            {
                name        : "systickEnable",
                displayName : "Enable SysTick And Start Counting",
                description : 'Enable SysTick and start counting when enabled',
                longDescription :
`
The SysTick is available in RUN and SLEEP modes but is not available for use in STOP, STANDBY, or
SHUTDOWN modes.\n
Once the SysTick is enabled, the SysTick will start counting from whatever value it was initialized.
It is recommended to initialize the period before enabling and starting the SysTick.
`,
                hidden      : false,
                default     : false,
            },
        ]
    },
]


/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    if ((inst.systickEnable) && (!(inst.periodEnable))){
        validation.logError(
            "It is recommended to initialize the SysTick to a known value before enabling the timer.",
            inst, ["systickEnable"]
        );
    }
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: SYSTICKConfig,

    validate: validate,

};

/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic module module to
 *  allow us to augment/override as needed for the MSPM0.
 */
function extend(base)
{
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    // moduleStatic specific to SYSTICK as it's statically defined
    result.config = base.moduleStatic.config.concat(devSpecific.config);
    base.moduleStatic = result;

    return (base);
}

/*
 *  ======== exports ========
 *  Export device-specific extensions to base exports
 */
exports = {
    /* required function, called by base module module */
    extend: extend
};
