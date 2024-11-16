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
 *  ======== WWDTMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/************************* Profiles functions *******************************/
const profilesWWDT = [
    {
        /* Watchdog Mode, 250ms period */
        name                    : "CONFIG_PROFILE_1",
        clockDivider            : "8",
        wwdtMode                : "WATCHDOG",
        periodCount             : "10",
        activeWindow            : "0",
        window0ClosedPeriod     : "0",
        window1ClosedPeriod     : "0",
        sleepMode               : true,
        enabledInterrupts       : false,
        interruptPriority       : "DEFAULT",
    },
    {
        /* Watchdog Mode, 500ms period, Window0 25% closed, Window1 0% closed */
        name                    : "CONFIG_PROFILE_2",
        clockDivider            : "4",
        wwdtMode                : "WATCHDOG",
        periodCount             : "12",
        activeWindow            : "0",
        window0ClosedPeriod     : "25",
        window1ClosedPeriod     : "0",
        sleepMode               : true,
        enabledInterrupts       : false,
        interruptPriority       : "DEFAULT",
    },
    {
        /* Interval Timer Mode, 1s period */
        name                    : "CONFIG_PROFILE_3",
        clockDivider            : "1",
        wwdtMode                : "INTERVAL",
        periodCount             : "15",
        activeWindow            : "0",
        window0ClosedPeriod     : "0",
        window1ClosedPeriod     : "0",
        sleepMode               : true,
        enabledInterrupts       : true,
        interruptPriority       : "DEFAULT",
    },
];

/************************* General functions **********************************/


function onChangeSetCustomProfile(inst,ui){
    inst.profile = "CUSTOM";
}

function onChangeWWDTProfile(inst, ui) {
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = profilesWWDT.filter(obj =>
                                        {return obj.name === inst.profile});
        if (selectedProfileArray.length != 0)
        {
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
    }
    updateWWDTMode(inst, ui);
}

function updateWWDTMode(inst, ui)
{
    if (inst.wwdtMode == "WATCHDOG") {
        ui.window0ClosedPeriod.hidden = false
        ui.window1ClosedPeriod.hidden = false
        ui.activeWindow.hidden = false
        ui.window0ClosedPeriodCalculated.hidden = false
        ui.window1ClosedPeriodCalculated.hidden = false

    }
    else {
        ui.window0ClosedPeriod.hidden = true
        ui.window1ClosedPeriod.hidden = true
        ui.activeWindow.hidden = true
        ui.window0ClosedPeriodCalculated.hidden = true
        ui.window1ClosedPeriodCalculated.hidden = true
    }
    ui.interruptPriority.hidden = !inst.enabledInterrupts;
}

function getWWDTClockSourceFreq(inst) {
    let wwdtClockFreq = (system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq) / inst.clockDivider;

   return wwdtClockFreq;
}

function getWWDTPeriod(inst) {
    let clockDiv = parseInt((inst.clockDivider).match("[0-9]+")[0]);
    let perCount = parseInt((inst.periodCount).match("[0-9]+")[0]);
    perCount = 2**perCount;

    let wwdtPer = (clockDiv * perCount) / 32768;

   return wwdtPer;
}

function getWWDTWin0Per(inst) {
    let winPercent = parseInt((inst.window0ClosedPeriod).match("[0-9]+")[0]);

    switch (inst.window0ClosedPeriod) {
        case "12":
            winPercent = 12.5;
            break;
        case "18":
            winPercent = 18.75;
            break;
        case "81":
            winPercent = 81.25;
            break;
        case "87":
            winPercent = 87.5;
            break;
        default:
            break;
    }
    let win0Per = winPercent * getWWDTPeriod(inst) / 100;

   return win0Per;
}

function getWWDTWin1Per(inst) {
    let winPercent = parseInt((inst.window1ClosedPeriod).match("[0-9]+")[0]);

    switch (inst.window1ClosedPeriod) {
        case "12":
            winPercent = 12.5;
            break;
        case "18":
            winPercent = 18.75;
            break;
        case "81":
            winPercent = 81.25;
            break;
        case "87":
            winPercent = 87.5;
            break;
        default:
            break;
    }
    let win1Per = winPercent * getWWDTPeriod(inst) / 100;

   return win1Per;
}


/************************* Basic functions *******************************/
/* onChange functions for Basic Configuration */

function onChangeInt(inst, ui)
{
    ui.interruptPriority.hidden = !(inst.enabledInterrupts);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeMode(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    updateWWDTMode(inst,ui);
}

function pinmuxRequirements(inst){
    let wwdt = {
        name          : "peripheral",
        displayName   : "Watchdog Peripheral",
        interfaceName : "WWDT",
        resources     : [],
        signalTypes   : {

        }
    };
    return [wwdt];
}

/* PROFILES CONFIGURATION */
let WWDTConfig = [
    /****** PROFILES CONFIGURATION *******/
    {
        name: "GROUP_PROFILE",
        displayName: "Quick Profiles",
        description: "",
        collapsed: false,
        config: [
            {
                name        : "profile",
                displayName : "WWDT Profiles",
                description : 'Pre-defined profiles for typical WWDT configurations',
                longDescription: `
The primary function of the window watchdog timer (WWDT) is to initiate a system restart (SYSRST) when
correct operation of the device has failed due to an unexpected software or system delay. The WWDT can
be programmed with a predefined time window within which the application software must restart the timer,
indicating that application execution is proceeding normally. If application software fails to restart the timer within
the specified window, the WWDT will issue an error signal to SYSCTL to generate a SYSRST, resetting the CPU
and peripheral state.

![WWDT Block Diagram](../docs/english/sysconfig/images/wwdtBlockDiagram.png "WWDT Block Diagram")

The Quick Profile Options are:
* **Watchdog Mode, 250ms period**:
    * Mode: Watchdog Mode
    * Clock Divider: Divide by 8
    * Period Count: 2^10
    * Active Window: Window0
    * Window0 Period: 0% Closed, 100% Open (Window0 Disabled)
    * Window1 Period: 0% Closed, 100% Open (Window1 Disabled)
    * Run in Sleep Mode: Enabled
    * Watchdog Interrupt: Disabled
* **Watchdog Mode, 500ms period, Window0 25% closed, Window1 disabled**:
    * Mode: Watchdog Mode
    * Clock Divider: Divide by 4
    * Period Count: 2^12
    * Active Window: Window0
    * Window0 Period: 25% Closed, 75% Open
    * Window1 Period: 0% Closed, 100% Open (Window1 Disabled)
    * Run in Sleep Mode: Enabled
    * Watchdog Interrupt: Disabled
* **Interval Timer Mode, 1s period**:
    * Mode: Interval Timer Mode
    * Clock Divider: Divide by 1
    * Period Count: 2^15
    * Run in Sleep Mode: Enabled
    * Watchdog Interrupt: Enabled
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "CUSTOM",
                options     : [
                    {name: "CONFIG_PROFILE_1", displayName: "Watchdog Mode, 250ms period"},
                    {name: "CONFIG_PROFILE_2", displayName: "Watchdog Mode, 500ms period, Window0 25% closed, Window1 disabled"},
                    {name: "CONFIG_PROFILE_3", displayName: "Interval Timer Mode, 1s period"},
                    {name: "CUSTOM", displayName: "Custom"},
                ],
                onChange    : onChangeWWDTProfile,
            },
        ],
    },
]

WWDTConfig = WWDTConfig.concat([
    {
        name: "GROUP_BASIC",
        displayName: "Configuration",
        description: "",
        longDescription:
`Basic WWDT options allow configuration of polynomial, bit order, endianess, and
seed value.
`,
        collapsed: false,
        config: [
            {
                name: "sourceClock",
                displayName: "WWDT Source Clock",
                description: "LFCLK sources the WWDT module",
                default: "LFCLK",
                getValue: (inst) => {
                    return ("LFCLK");
                }
            },
            {
                name        : "clockDivider",
                displayName : "WWDT Clock Divider",
                description : 'Clock divider for the WWDT clock source',
        longDescription:
`The WWDT runs from the 32-kHz low-frequency clock (LFCLK). A clock divider supports dividing the input clock
from Divide by 1 (no divide) to Divide by 8. The default setting is Divide by 4 (32 kHz divided by 4, or 8 kHz).

`,
                hidden      : false,
                default     : "4",
                options     : [
                    {name: "1", displayName: "Divide by 1"},
                    {name: "2", displayName: "Divide by 2"},
                    {name: "3", displayName: "Divide by 3"},
                    {name: "4", displayName: "Divide by 4"},
                    {name: "5", displayName: "Divide by 5"},
                    {name: "6", displayName: "Divide by 6"},
                    {name: "7", displayName: "Divide by 7"},
                    {name: "8", displayName: "Divide by 8"},
                ],
                onChange    : onChangeSetCustomProfile,
            },
            {
                name        : "clockSourceCalculated",
                displayName : "Calculated WWDT Source Frequency",
                description : 'The calculated frequency of the  WWDT Clock Source in Hz',
                hidden      : false,
                default     : "0Hz",
                getValue    : (inst) => (Common.getUnitPrefix((getWWDTClockSourceFreq(inst))).str+'Hz'),
            },
            {
                name        : "wwdtMode",
                displayName : "WWDT Mode",
                description : 'Select the operating mode for the WWDT',
                longDescription:
`
The WWDT can be set to one of two modes:
* **Watchdog Mode:**
When the WWDT is in watchdog mode, the WWDT counter must be restarted within the open window period by
writing the RESTART value (0x000000A7) to the WWDTCNTRST register. After a reset or restart, the WWDT
counter will restart from zero. A failure to restart the WWDT within the open window or an attempt to restart the
WWDT counter during the closed window will generate a WWDT violation to SYSCTL, resulting in a SYSRST.
Writing any value other than the RESTART value to the WWDTCNTRST register also generates a WWDT
violation and a SYSRST.\n
* **Interval Timer Mode:**
When the WWDT is in interval mode, the timer acts as an interval timer, generating WWDT interrupts to the CPU
as specified by the WWDT period. As soon as the WWDT is enabled in interval mode, the WWDT interval timer interrupt will be asserted after the expiration of the timer. It is not necessary to restart the WWDT in interval timer
mode.
`,
                hidden      : false,
                default     : "WATCHDOG",
                options     : [
                    {name: "WATCHDOG", displayName: "Watchdog Mode"},
                    {name: "INTERVAL", displayName: "Interval Timer Mode"},
                ],
                onChange    : onChangeMode
            },
            {
                name        : "periodCount",
                displayName : "WWDT Period Count",
                description : 'Period Count for the WWDT timer',
                longDescription:
`The WWDT has a 25-bit counter which is initially stopped after a SYSRST.
The total timer count is selected to be one of 8 possible period count values. \n
The total WWDT period is calculated as follows:\n
TWWDT = (CLKDIV + 1) ∗ PERCOUNT / 32768 Hz
`,
                hidden      : false,
                default     : "12",
                options     : [
                    {name: "6", displayName: "2^6 timer period count"},
                    {name: "8", displayName: "2^8 timer period count"},
                    {name: "10", displayName: "2^10 timer period count"},
                    {name: "12", displayName: "2^12 timer period count"},
                    {name: "15", displayName: "2^15 timer period count"},
                    {name: "18", displayName: "2^18 timer period count"},
                    {name: "21", displayName: "2^21 timer period count"},
                    {name: "25", displayName: "2^25 timer period count"},
                ],
                onChange    : onChangeSetCustomProfile,
            },
            {
                name        : "periodCalculated",
                displayName : "Calculated WWDT Period",
                description : 'The calculated total WWDT period in seconds',
                longDescription:
`
The total WWDT period is calculated as follows:\n
TWWDT = (CLKDIV + 1) ∗ PERCOUNT / 32768 Hz
`,
                hidden      : false,
                default     : "0s",
                getValue    : (inst) => (Common.getUnitPrefix((getWWDTPeriod(inst))).str+'s')
            },
            {
                name        : "activeWindow",
                displayName : "Active Window",
                description : 'Select which window, Window0 or Window1, is active. The active window can be changed after the WWDT has been enabled.',
                longDescription:
`
The window watchdog timer supports detecting both a "too late" response as well as a "too early" response
through the use of an optional closed window. The WWDT period consists of a closed
window period and an open window period. The closed window period begins first, followed by the open window
period. The WWDT can only be restarted during the open window period. An attempt to restart the WWDT
during the closed window period results in a SYSRST. Following the closed window, if the WWDT is not restarted
before the end of the open window, the WWDT period expires and a SYSRST is also generated.\n
If the closed window functionality is not desired, it can be disabled (set to 0%), giving traditional watchdog timer
functionality where the WWDT can be reset any time before the WWDT period expires.\n
The active window selection can be changed after the WWDT has been enabled.\n
![WWDT Window Functionality](../docs/english/sysconfig/images/wwdtWindowFunc.png "WWDT Window Functionality")
`,
                hidden      : false,
                default     : "0",
                options     : [
                    {name: "0", displayName: "Window 0 is active"},
                    {name: "1", displayName: "Window 1 is active"},
                ],
                onChange    : onChangeSetCustomProfile,
            },
            {
                name        : "window0ClosedPeriod",
                displayName : "Window 0 Closed Period",
                description : 'The percentage of the total period that Reset Window 0 should be closed',
                longDescription:
`
Either window can be set to one of 8 possible window settings.\n
Setting a WINDOWx value to 0% closed, 100% open is equivalent to disabling the window function of the
WWDT. In this configuration, the WWDT can be restarted at any point during the WWDT period.
`,
                hidden      : false,
                default     : "0",
                options     : [
                    {name: "0", displayName: "0% closed, 100% open (Window 0 disabled)"},
                    {name: "12", displayName: "12.5% closed, 87.5% open"},
                    {name: "18", displayName: "18.75% closed, 81.25% open"},
                    {name: "25", displayName: "25% closed, 75% open"},
                    {name: "50", displayName: "50% closed, 50% open"},
                    {name: "75", displayName: "75% closed, 25% open"},
                    {name: "81", displayName: "81.25% closed, 18.75 open"},
                    {name: "87", displayName: "87.5% closed, 12.5% open"},
                ],
                onChange    : onChangeSetCustomProfile,
            },
            {
                name        : "window0ClosedPeriodCalculated",
                displayName : "Calculated Window 0 Period",
                description : 'The calculated closed period of Window 0',
                hidden      : false,
                default     : "0s",
                getValue    : (inst) => (Common.getUnitPrefix((getWWDTWin0Per(inst))).str+'s')
            },
            {
                name        : "window1ClosedPeriod",
                displayName : "Window 1 Closed Period",
                description : 'The percentage of the total period that Reset Window 1 should be closed',
                hidden      : false,
                default     : "0",
                options     : [
                    {name: "0", displayName: "0% closed, 100% open (Window 1 disabled)"},
                    {name: "12", displayName: "12.5% closed, 87.5% open"},
                    {name: "18", displayName: "18.75% closed, 81.25% open"},
                    {name: "25", displayName: "25% closed, 75% open"},
                    {name: "50", displayName: "50% closed, 50% open"},
                    {name: "75", displayName: "75% closed, 25% open"},
                    {name: "81", displayName: "81.25% closed, 18.75 open"},
                    {name: "87", displayName: "87.5% closed, 12.5% open"},
                ],
                onChange    : onChangeSetCustomProfile,
            },
            {
                name        : "window1ClosedPeriodCalculated",
                displayName : "Calculated Window 1 Period",
                description : 'The calculated closed period of Window 1',
                hidden      : false,
                default     : "0s",
                getValue    : (inst) => (Common.getUnitPrefix((getWWDTWin1Per(inst))).str+'s')
            },
            {
                name        : "sleepMode",
                displayName : "Enable WWDT Running During Sleep",
                description : 'Enable or disable the WWDT timer running while the device is in a low-power mode',
                longDescription:
`
When enabled, the WWDT counter is configured to continue counting when the device is in a low-power mode (CPU is
disabled).
When disabled, the WWDT will not count in low-power modes. In this case, when the low-power mode is exited and the CPU returns to operation, the WWDT
counter will resume counting from the same value it was stopped at before entering the low-power mode.
`,
                hidden      : false,
                default     : false,
                onChange    : onChangeSetCustomProfile,
            },
        ],
    },
    {
        name: "GROUP_INTERRUPTS",
        displayName: "Interrupt Configuration",
        longDescription: "This section allows enabling/disabling of the WWDT interval timer interrupt",
        collapsed: false,
        config: [
            {
                name        : "enabledInterrupts",
                displayName : "Enable WWDT Interval Timer Interrupt",
                description : 'Enable WWDT Interval Timer interrupt',
                default     : false,
                onChange    : onChangeInt
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
        ]
    },
])


/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    // Common.validateNames(inst, validation);
    if (inst.wwdtMode == "INTERVAL")
    {

    }
    if(inst.wwdtMode == "INTERVAL" && !(inst.enabledInterrupts)){
        validation.logInfo(
            "The WWDT Interval Timer will not trigger an interrupt unless the WWDT Interval Timer Interrupt is enabled",
            inst, ["enabledInterrupts"]
        );
    }

    if(inst.wwdtMode == "WATCHDOG" && inst.enabledInterrupts){
        validation.logInfo(
            "The WWDT Interval Timer Interrupt will not trigger unless the WWDT mode is set to Interval Timer",
            inst, ["wwdtMode"]
        );
    }
}

/*
 * Gets a DMA module if available
 */
function moduleInstances(inst){
    let modInstances = []
    if(inst.enableWWDTCalcWithDMA){
        let mod = {
            name: "DMA_CHANNEL_WWDT",
            displayName: "DMA Channel for WWDT",
            moduleName: '/ti/driverlib/DMAChannel',
            group: "GROUP_DMA",
            args: {

            },
            requiredArgs: {
                hideTriggerSelect: false,
                passedTriggerSelect: 0,
                triggerNumber: "DMA_SOFTWARE_TRIG",
                triggerSelect:"SW",
                addressMode:"b2f",
                transferMode:"SINGLE_BLOCK",
                transferSize: 1,
                tableSrcAddressInc:"UNCHANGED",
            },

        }
        modInstances.push(mod);
    }
    return modInstances;
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: WWDTConfig,

    validate: validate,

    pinmuxRequirements: pinmuxRequirements,

    moduleInstances: moduleInstances,

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/wwdt/WWDT.Board.c.xdt",
        boardh: "/ti/driverlib/wwdt/WWDT.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: false,
        Function: true

    },

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
    Object.assign(base, devSpecific);

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
