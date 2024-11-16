/*
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== CaptTimerMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let EVENT = system.getScript("/ti/driverlib/EVENT.syscfg.js");



/* =================== Timer Options ============================ */

function optionsGetCrossTriggerTimerInstances(inst) {
    let allTimers = [];
    let name_template = "Timer_";
    let displayName_template = "Timer ";
    for(let j = 0; j < 16; j++){
        allTimers.push({name: name_template + j, displayName: displayName_template + j});
    }
    return allTimers;
}

function onChangeSetCustomProfile(inst, ui) {
    inst.profile = "CUSTOM";
}

const EmptyTimerProfile = {
    timerClkSrc: "BUSCLK",
    timerClkDiv: 1,
    timerClkPrescale: 1,
    timerPeriod: "0 ms",
    timerStartTimer: false,
    crossTriggerEn: false,
    crossTriggerAuthority: "Main",
    mainCrossTriggerSource: "SW",
    secondaryCrossTriggerSource: "Timer_0",
    interrupts: [],
    interruptPriority: "DEFAULT",
    event1PublisherChannel: 0,
    event1ControllerInterruptEn: [],
    event2PublisherChannel: 0,
    event2ControllerInterruptEn: [],
    subscriberPort: "Disabled",
    subscriberChannel: 0,
};

const EmptyTimerProfileAdvanced = {
    enableRepeatCounter: false,
    repeatCounter: 1,
}

const TimerProfiles = [
    {
        name                : "duty_cycle_period",
        timerClkSrc         : "BUSCLK",
        timerClkPrescale    : 1,
        // Period = 2000
        timerPeriod         : "62.52 us",
        captureInputMode    : "single",
        captSelect          : "base",
        captMode            : "EDGE_TIME",
        captEdgeDetection   : "RISING",
        ccIndex       : 0,
        captInputInvMode    : false,
        timerStartTimer     : false,
        interrupts          : ["CC0_DN"],
    },
];

function onChangeTimerProfile(inst, ui) {
    if(inst.profile !== "CUSTOM") {
        // matches name shorthand
        let selectedProfile = _.filter(TimerProfiles, ['name', inst.profile]);
        if(selectedProfile.length === 1){
            // assigns the empty profile with the selected profile on top
            Object.assign(inst, EmptyTimerProfile,
                _.pickBy(selectedProfile[0], (_,key) => key !== 'name'));

            if(Common.hasTimerA()){
                Object.assign(inst, EmptyTimerProfileAdvanced,
                    _.pickBy(selectedProfile[0], (_,key) => key !== 'name'));
            }
        } else {
            throw `profileError`;
        }
        updateGUI_Profile(inst,ui);
    }
}

const InterruptOptions = [
    { name: "ZERO", displayName: "Zero event", description: "Timer reaches zero" },
    { name: "LOAD", displayName: "Load event", description: "Timer reloads count value" },
    { name: "OVERFLOW", displayName: "Trigger Overflow event", description:"Trigger Overflow event"},
    { name: "REPC", displayName: "Repeat Count", description: "Repeat counter reaches zero" },
    { name: "CC0_DN", displayName: "Channel 0 compare down event", description: "Channel 0 compare value reached in timer down counting mode" },
    { name: "CC0_UP", displayName: "Channel 0 compare up event"  , description: "Channel 0 compare value reached in timer up counting mode" },
    { name: "CC1_DN", displayName: "Channel 1 compare down event", description: "Channel 1 compare value reached in timer down counting mode" },
    { name: "CC1_UP", displayName: "Channel 1 compare up event"  , description: "Channel 1 compare value reached in timer up counting mode" },
    { name: "CC2_DN", displayName: "Channel 2 compare down event", description: "Channel 2 compare value reached in timer down counting mode" },
    { name: "CC2_UP", displayName: "Channel 2 compare up event"  , description: "Channel 2 compare value reached in timer up counting mode" },
    { name: "CC3_DN", displayName: "Channel 3 compare down event", description: "Channel 3 compare value reached in timer down counting mode" },
    { name: "CC3_UP", displayName: "Channel 3 compare up event"  , description: "Channel 3 compare value reached in timer up counting mode" },
];

const EventOptions = [
    { name: "ZERO_EVENT", displayName: "Zero event" },
    { name: "LOAD_EVENT", displayName: "Load event" },
    { name: "OVERFLOW_EVENT", displayName: "Overflow event"},
    { name: "CC0_DN_EVENT", displayName: "Channel 0 compare down event"},
    { name: "CC0_UP_EVENT", displayName: "Channel 0 compare up event"},
    { name: "CC1_DN_EVENT", displayName: "Channel 1 compare down event"},
    { name: "CC1_UP_EVENT", displayName: "Channel 1 compare up event"},
    { name: "CC2_DN_EVENT", displayName: "Channel 2 compare down event"},
    { name: "CC2_UP_EVENT", displayName: "Channel 2 compare up event"},
    { name: "CC3_DN_EVENT", displayName: "Channel 3 compare down event"},
    { name: "CC3_UP_EVENT", displayName: "Channel 3 compare up event"},
];

const TimerClockSourceOptions = [
    { name: "BUSCLK", displayName: "BUSCLK" },
    { name: "MFCLK", displayName: "MFCLK" },
    { name: "LFCLK", displayName: "LFCLK" },
];

const TimerClockDividerOptions = [
    { name: 1, displayName: "Divided by 1"},
    { name: 2, displayName: "Divided by 2"},
    { name: 3, displayName: "Divided by 3"},
    { name: 4, displayName: "Divided by 4"},
    { name: 5, displayName: "Divided by 5"},
    { name: 6, displayName: "Divided by 6"},
    { name: 7, displayName: "Divided by 7"},
    { name: 8, displayName: "Divided by 8"}
];

function getRepeatCntOptions(inst)
{
    /* All Clock Source Options */
    let repeatCntOptions = [
        { name: 1, displayName: "1" },
        { name: 2, displayName: "2" },
        { name: 3, displayName: "3" },
        { name: 4, displayName: "4" },
    ];
    return repeatCntOptions;
}

/* ========= dynamic Changes ========== */
function getDisabledOptionsInterrupts(inst,ui)
{
    let disabled = [];

    if((Common.hasTimerA()) && !isFourCCCapable(inst))
    {
        disabled.push({ name: "CC2_DN", displayName: "Channel 2 compare down event", reason: "Not supported by Timer instance"});
        disabled.push({ name: "CC2_UP", displayName: "Channel 2 compare up event",   reason: "Not supported by Timer instance"});
        disabled.push({ name: "CC3_DN", displayName: "Channel 3 compare down event", reason: "Not supported by Timer instance"});
        disabled.push({ name: "CC3_UP", displayName: "Channel 3 compare up event",   reason: "Not supported by Timer instance"});
    }

    return disabled;
}

function getDisabledOptionsEvents(inst,ui)
{

    let disabled = [];

    if((Common.hasTimerA()) && !isFourCCCapable(inst))
    {
        disabled.push({ name: "CC2_DN_EVENT", displayName: "Channel 2 compare down event", reason: "Not supported by Timer instance"});
        disabled.push({ name: "CC2_UP_EVENT", displayName: "Channel 2 compare up event",   reason: "Not supported by Timer instance"});
        disabled.push({ name: "CC3_DN_EVENT", displayName: "Channel 3 compare down event", reason: "Not supported by Timer instance"});
        disabled.push({ name: "CC3_UP_EVENT", displayName: "Channel 3 compare up event",   reason: "Not supported by Timer instance"});
    }

    return disabled;
}

function getDisabledEvents(inst)
{
    let allOptions = EventOptions;

    if(!isFourCCCapable(inst)) {
        allOptions = allOptions.filter( (el) => !el.name.match("CC2|3") );
    }

    return [];
}

/* ==================== Helper Funtions ================================== */

// Returns true if the device is TIMA0 and thus has four capture compare channels
function isFourCCCapable(inst)
{
    try{
        return (inst.peripheral.$solution.peripheralName.match(/TIMA0|TIMG14/) != null);
    }catch (e) {
        return false;
    }
}

function isHighResolutionCapable(inst)
{
    try{
        return (inst.peripheral.$solution.peripheralName.match("TIMG12") !==  null);
    }catch (e) {
        return false
    }
}

function getTimerClockSourceFreq(inst) {
    let timerClockFreq = 0;
   switch (inst.timerClkSrc){
        case "BUSCLK":
            timerClockFreq = Common.getBUSCLKFreq(inst, "GPTIMER");
        break;
        case "MFCLK":
            timerClockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.MFCLK_Freq;
        break;
        case "LFCLK":
            timerClockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq;
        break;
   }
   timerClockFreq = timerClockFreq / inst.timerClkDiv;

   return timerClockFreq;
}

function getTimerClockFreq(inst,ui)
{
    let timerClkFreq;
    let timerDivider;
    let timerPrescaler;

    switch (inst.timerClkSrc)
    {
        case "BUSCLK":
            timerClkFreq = Common.getBUSCLKFreq(inst, "GPTIMER");
            break;
        case "MFCLK":
            timerClkFreq = system.modules["/ti/driverlib/SYSCTL"].$static.MFCLK_Freq;
            break;
        case "LFCLK":
            timerClkFreq = system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq;
            break;
    }

    timerDivider = inst.timerClkDiv;

    if(isHighResolutionCapable(inst)){
        timerPrescaler = 1;
    }else{
        timerPrescaler = (inst.timerClkPrescale);
    }

    timerClkFreq = (timerClkFreq / (timerDivider * timerPrescaler));

    return timerClkFreq;

}

function getTimerClockFreqStr(inst,ui)
{
    let freq = getTimerClockFreq(inst,ui);
    let freqStr = Common.getUnitPrefix(freq);

    return freqStr.str + "Hz";
}

function getTimerCountBitRes(inst,ui)
{
    let bitRes;

    if(isHighResolutionCapable(inst))
    {
        bitRes = 32;
    }else{
        bitRes = 16;
    }

    return bitRes;
}

function getScaledPeriod(valueInSec)
{
    let value;
    let maxPerUnits;
    let maxPeriodStr;

    /* Avoid ks notation */
    if((valueInSec / 1000) > 1)
    {
        value = (valueInSec / 60);
        /* Avoid kmin notation */
        if((value / 1000) > 1)
        {
            value = (value / 60);
            maxPerUnits = "hrs ";
        }else
        {
            maxPerUnits = "min ";
        }
    }else{
       value = valueInSec;
       maxPerUnits = "s ";
    }

     maxPeriodStr = Common.getUnitPrefix(value).str;

     return [maxPeriodStr , maxPerUnits]
}

function getTimerPeriodRangeStr(inst,ui)
{
    let bitRes;
    let minPeriod;
    let maxPeriod;
    let maxPeriodScaled;
    let maxPeriodVal;
    let maxPeriodUnits;
    let resolution;
    let timerFreq;

    timerFreq = getTimerClockFreq(inst,ui);

    bitRes = getTimerCountBitRes(inst,ui);

    resolution = minPeriod = Common.getUnitPrefix( 1 / timerFreq);
    maxPeriod  = Math.pow(2,bitRes) / timerFreq;

    maxPeriodScaled = getScaledPeriod(maxPeriod);
    maxPeriodVal = maxPeriodScaled[0];
    maxPeriodUnits = maxPeriodScaled[1];

    let str = minPeriod.str + "s to " + maxPeriodVal + maxPeriodUnits + "w/ resolution of " + resolution.str + "s";
    return str;
}

function getActualTimerPeriodTicks(inst)
{
    let desiredPeriod = Common.parseFloatUnitInput(inst.timerPeriod,"s");
    if(desiredPeriod === NaN){
        return "NaN";
    }
    let timerFreq = getTimerClockFreq(inst);

    return (Math.round(desiredPeriod * timerFreq));

}

function getActualTimerPeriod(inst)
{
    let timerFreq = getTimerClockFreq(inst);
    let maxTimerTicks = Math.pow(2,getTimerCountBitRes(inst));
    let timerTicks;
    let actualStr;


    timerTicks = getActualTimerPeriodTicks(inst);

    if(timerTicks > maxTimerTicks)
    {
        actualStr = 'Desired Timer Period is out of range'
    }else{
        let result = getScaledPeriod(timerTicks / timerFreq);
        actualStr = result[0] + result[1];
    }
    return actualStr;
}

/*  ======== onChange handlers ======== */
function onChangeEnableRepeatCounter(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
    updateGUI_RepeatCounter(inst, ui);
}

function updateGUI_RepeatCounter(inst, ui) {

    if(Common.hasTimerA()){
        ui.repeatCounter.hidden = !(inst.enableRepeatCounter);
    }
}

function onChangeUpdateMultiChanView(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
    updateMultiChanView(inst,ui);
}

function onChangeInterrupts(inst,ui)
{
    onChangeSetCustomProfile(inst, ui);
    updateGUI_Interrupts(inst, ui);
}

function updateGUI_Interrupts(inst, ui)
{
    ui.interruptPriority.hidden = (inst.interrupts.length === 0);
}

/* Somewhat redundant for finer configurables but this makes editing and readability much easier */
function onChangeCrossTrigger(inst, ui){
    onChangeSetCustomProfile(inst, ui);
    updateGUI_CrossTrigger(inst, ui);
}

function onChangeSetInputMode(inst,ui){
    let isMultiInput = (inst.captureInputMode == "multi");
    let isFilteringDisabled = (inst.captFilter == false);

    // Single channel options
    ui.captSelect.hidden = isMultiInput;
    ui.captFilter.hidden = isMultiInput;
    ui.filteringMode.hidden = (isMultiInput || isFilteringDisabled);
    ui.filterPeriod.hidden = (isMultiInput || isFilteringDisabled);
    ui.captMode.hidden = isMultiInput;
    ui.captEdgeDetection.hidden = isMultiInput;
    ui.ccIndex.hidden = isMultiInput;
    ui.captInputInvMode.hidden = isMultiInput;

    // Multi channel options
    ui.ccIndexMulti.hidden = !isMultiInput;
    ui.multi_cvae.hidden = !isMultiInput;
    ui.multi_countMode.hidden = !isMultiInput;
    ui.multi_countRep.hidden = !isMultiInput;
    ui.multi_ch_zero.hidden = !isMultiInput;


    for(let channels = 0; channels < 4; channels++)
    {
        let groupName = "GROUP_MULTI_CHAN_" + channels;
        let inFiltGrpName = "GROUP_MULTI_CH" + channels +"_CAPT_FILTER"
        system.utils.hideGroupConfig(groupName, inst, ui);
        system.utils.hideGroupConfig(inFiltGrpName, inst, ui);
    }

    if(isMultiInput)
    {
        let enabledCh = [];
        for(let channel of inst.ccIndexMulti)
        {
            enabledCh.push(channel);
        }

        for(let channel of enabledCh)
        {
            let groupName = "GROUP_MULTI_CHAN_" + channel;
            let inFiltGrpName = "GROUP_MULTI_CH" + channel +"_CAPT_FILTER"
            let inputFiltMode = inst["multi_ch"+ channel +"_input_filter"]
            system.utils.showGroupConfig(groupName, inst, ui);
            if(inputFiltMode)
            {
                system.utils.showGroupConfig(inFiltGrpName, inst, ui);
            }else{
                system.utils.hideGroupConfig(inFiltGrpName, inst, ui);
            }
        }
    }

}

function updateGUI_CrossTrigger(inst, ui) {
    if(!inst.crossTriggerEn){
        ui.crossTriggerAuthority.hidden = true;
        ui.mainCrossTriggerSource.hidden = true;
        ui.mainCTSubscriberChannel.hidden = true;
        ui.secondaryCrossTriggerSource.hidden = true;
        ui.secondaryCTSubscriberChannel.hidden = true;
    } else {
        ui.crossTriggerAuthority.hidden = false;
        if(inst.crossTriggerAuthority == "Main") {
            ui.mainCrossTriggerSource.hidden = false;
            ui.mainCTSubscriberChannel.hidden = !inst.mainCrossTriggerSource.match("FSUB");
        } else {
            ui.mainCrossTriggerSource.hidden = true;
            ui.mainCTSubscriberChannel.hidden = true;
        }
        if(inst.crossTriggerAuthority == "Secondary") {
            ui.secondaryCrossTriggerSource.hidden = false;
            ui.secondaryCTSubscriberChannel.hidden = !inst.secondaryCrossTriggerSource.match("SubscriberPort");
        } else {
            ui.secondaryCrossTriggerSource.hidden = true;
            ui.secondaryCTSubscriberChannel.hidden = true;
        }
    }
}

// Updates the entire UI state based on a profile change
function updateGUI_Profile(inst, ui)
{
    updateGUI_RepeatCounter(inst, ui);
    updateGUI_Interrupts(inst, ui);
    updateGUI_CrossTrigger(inst, ui);
    onChangeSetInputMode(inst,ui);
}

/* Retention configurable */
let retentionConfig = [];
if(Common.isDeviceM0G()){
    retentionConfig = retentionConfig.concat(
        {
            name        : "enableRetention",
            default     : false,
            hidden      : true,
            getValue: (inst) => {
                let solution = false;
                try{
                    solution = (/TIMA|TIMG6|TIMG7/.test(inst.peripheral.$solution.peripheralName));
                }catch (e) {
                    // do nothing
                }
                return solution;
            }
        },
        {
            name        : "enableRetentionUI",
            displayName : "Low-Power Register Retention",
            default     : "",
            longDescription: `
Some MSPM0G peripherals residing in PD1 domain do not retain register contents when
entering STOP or STANDBY modes.\n
Please view the datasheet for more details.\n
Developers can decide to re-initialize the peripheral using the default
initialization from SysConfig in their application. This approach is more
memory-efficient.\n
Alternatively, the user may also call the provided DriverLib APIs to save and
restore the register configuration of the peripheral before and after entering
low-power mode. This approach is recommended if the peripheral configuration is
modified at runtime.
            `,
            getValue: (inst) => {
                let solution = false;
                try{
                    solution = (/TIMA|TIMG6|TIMG7/.test(inst.peripheral.$solution.peripheralName)) && !(/SLEEP/.test(system.modules["/ti/driverlib/SYSCTL"].$static.powerPolicy));
                }catch (e) {
                    // do nothing
                }
                return (solution?"Registers not retained":"Registers retained");
            }
        },
        {
            name        : "overrideRetention",
            displayName : "Disable Retention APIs",
            longDescription: `
When selected, the retention APIs will not be generated regardless of selected peripheral.`,
            default     : false,
            hidden      : false,
            onChange    : (inst,ui) =>{
                ui.retentionRestoreCnt.hidden = inst.overrideRetention;
            }
        },
        {
            name            : "retentionRestoreCnt",
            displayName     : "Restore Counter",
            longDescription : `If selected timer counter value is also restored
            (e.g. resume counts of edge counts). Otherwise, timer counter is not restored.`,
            default         : false,
            hidden          : false,

        },
    );
}

let configAdvanced = [];

if(Common.hasTimerA()){
configAdvanced.push(
    {
        name            : "enableRepeatCounter",
        displayName     : "Enable Repeat Counter",
        description     : "Enable Repeat Counter",
        longDescription : `Enables repeat counter feature. Only supported in TIMA0`,
        default         : false,
        onChange        : onChangeEnableRepeatCounter
    },
    {
        name           : "repeatCounter",
        displayName    : "Times to Repeat Counter",
        description    : "Timer to Repeat Counter",
        longDescription: `Specifies number of timer reloads events before
        triggering repeat counter interrupt.`,
        default        : 1,
        hidden         : true,
        options        : [
            { name: 1, displayName: "1" },
            { name: 2, displayName: "2" },
            { name: 3, displayName: "3" },
            { name: 4, displayName: "4" },
        ],
        onChange       : onChangeSetCustomProfile
    },
);
};
configAdvanced.push(
    {
        name: "crossTriggerEn",
        displayName: "Enable Cross Trigger",
        description: "Enable the ability to have this GP timer trigger or be triggered by another module or hardware element",
        longDescription: `The cross trigger feature can be used to trigger more than one timer module to start counting simultaneously`,
        default: false,
        onChange: onChangeCrossTrigger
    },
    {
        name: "crossTriggerAuthority",
        displayName: "Cross Trigger Configuration",
        description: "Determines Cross Trigger Function",
        longDescription: `Determines if the timer will Trigger other modules and/or be triggered by other modules.`,
        default: "Main",
        hidden: true,
        options: [
            {name: "Main"},
            {name: "Secondary"},
        ],
        onChange: onChangeCrossTrigger
    },
    {
        name: "mainCrossTriggerConfig",
        displayName: "Main Cross Trigger Configuration",
        longDescription: `Enable this timer module to trigger other timer modules to start simultaneously`,
        collapsed: false,
        config: [
            {
                name: "mainCrossTriggerSource",
                displayName: "Cross Trigger Source",
                description: "Determines what will cause the Main to Trigger",
                longDescription: `The Main Cross Trigger Source causes the Main to send out the
                Cross Trigger Signal to whichever timers are configured in the Timer Instances Controlled.
                \n Software Describes a cause that is linked to the code and writing to a register
                \n Subscriber Ports would be used in the case of an event on a specific channel.`,
                hidden: true,
                default: "SW",
                options: [
                    {name: "SW", displayName: "Software"},
                    {name: "FSUB0", displayName: "Subscriber Port 0"},
                    {name: "FSUB1", displayName: "Subscriber Port 1"},
                    {name: "ZERO", displayName: "Zero"},
                    {name: "LOAD", displayName: "Load"},
                    {name: "CCD0", displayName: "Capture Compare Down 0 event"},
                    {name: "CCD1", displayName: "Capture Compare Down 1 event"},
                    {name: "CCD2", displayName: "Capture Compare Down 2 event"},
                    {name: "CCD3", displayName: "Capture Compare Down 3 event"},
                    {name: "CCU0", displayName: "Capture Compare Up 0 event"},
                    {name: "CCU1", displayName: "Capture Compare Up 1 event"},
                    {name: "CCU2", displayName: "Capture Compare Up 2 event"},
                    {name: "CCU3", displayName: "Capture Compare Up 3 event"},
                ],
                onChange: onChangeCrossTrigger,
            },
            {
                name: "mainCTSubscriberChannel",
                displayName: "Subscriber Channel ID",
                description: "Corresponding Channel of The Subscriber Port",
                longDescription: `Corresponding Channel on the Subscriber Port that's used to cause the
                triggering of secondary timer modules controlled by this module.`,
                hidden: true,
                default: 1,
                options: [
                    { name: 0 , displayName: "Disabled (0)"}, { name: 1 }, {name: 2 }, {name: 3 }, {name: 4 }, {name: 5 },
                    {name: 6 }, {name: 7 }, {name: 8 }, {name: 9 }, {name: 10 },
                    {name: 11 }, {name: 12 }, {name: 13 }, {name: 14 }, {name: 15}
                ],
                getValue: (inst) => {
                    if(inst.mainCrossTriggerSource == inst.subscriberPort){
                        return inst.subscriberChannel;
                    }
                    else{
                        return 0;
                    }
                }
            },
        ]
    },
    {
        name: "secondaryCrossTriggerConfig",
        displayName: "Secondary Cross Trigger Configuration",
        longDescription: `Enable this module to be triggered by other timer modules`,
        collapsed: false,
        config: [
            {
                name: "secondaryCrossTriggerSource",
                displayName: "Cross Trigger Input Source",
                description: "Input from a main cross trigger that will start this timer",
                longDescription: `This will start this module timer from a specific source. If a Timer is chosen,
                that corresponding timer will need to be enabled as a main cross trigger. Additionally, the
                specific wiring of physical timer instance to timer input (e.g. TimerG0 -> Timer1) is device
                dependent and can be verified in the datasheet.`,
                hidden: true,
                default: "Timer_0",
                options: (inst) => {
                    let other = [
                        {name: "SubscriberPort0"},
                        {name: "SubscriberPort1"}
                    ];
                    let validTimers = optionsGetCrossTriggerTimerInstances(inst);
                    return validTimers.concat(other);
                },
                onChange: onChangeCrossTrigger,
            },
            {
                name: "secondaryCTSubscriberChannel",
                displayName: "Subscriber Channel ID",
                description: "Corresponding Channel of The Subscriber Port",
                longDescription: `Corresponding Channel on the Subscriber Port that's used
                to trigger the start of this timer module`,
                hidden: true,
                default: 1,
                options: [
                    { name: 0, displayName: "Disabled (0)" }, { name: 1 },  { name: 2 },  { name: 3 },  { name: 4 },  { name: 5 },
                    { name: 6 },  { name: 7 },  { name: 8 },  { name: 9 },  { name: 10 },
                    { name: 11 }, { name: 12 }, { name: 13 }, { name: 14 }, { name: 15}
                ],
                getValue: (inst) => {
                    if(inst.secondaryCrossTriggerSource == "SubscriberPort0" && inst.subscriberPort == "FSUB0"){
                        return inst.subscriberChannel;
                    }
                    if(inst.secondaryCrossTriggerSource == "SubscriberPort1" && inst.subscriberPort == "FSUB1"){
                        return inst.subscriberChannel;
                    }
                    else{
                        return 0;
                    }
                }
            },
        ]
    },
    {
        name: "GROUP_RETENTION",
        displayName: "Retention Configuration",
        description: "",
        longDescription: ``,
        collapsed: false,
        config: retentionConfig,
    },
);

let ccIndexOptions = [
    { name: 0, displayName: "Capture Channel 0" },
    { name: 1, displayName: "Capture Channel 1" },
];

if(Common.hasTimerA()){
    ccIndexOptions.push(
        { name: 2, displayName: "Capture Channel 2" },
        { name: 3, displayName: "Capture Channel 3" }
    );
}

let ccIndexOptionsZero = [
    { name: -1, displayName: "None" },
    { name: 0,  displayName: "Capture Channel 0" },
    { name: 1,  displayName: "Capture Channel 1" },
]


if(Common.hasTimerA()){
    ccIndexOptionsZero.push(
        { name: 2, displayName: "Capture Channel 2" },
        { name: 3, displayName: "Capture Channel 3" }
    );
}


let config = [
    /* Show selected peripheral below instance name */
    {
        name: "selectedInstance",
        displayName: "Selected Peripheral",
        default: "",
        longDescription: `Refer to the PinMux section for peripheral selection. Chosen instance name is not indicative of active peripheral.`,
        getValue: (inst) => {
            let solution = "";
            try{
                solution = inst.peripheral.$solution.peripheralName;
            }catch (e) {
                // do nothing
            }
            return solution;
        }
    },
    {
        name: "GROUP_QUICK_PROFILE",
        displayName: "Quick Profiles",
        description: "",
        collapsed: false,
        config: [
            {
                name: "profile",
                displayName: "Timer Profiles",
                description: "Pre-defined profiles for typical TIMER configurations",
                longDescription: `
The TIMER module for the MSPM0 family is a set of general purpose timers
that can be used to generate capture events and record time signals. Capture
mode can be used for speed computation or time measurements.
The module allows the use of TIMA, TIMG, and TIMG12 instances. A specific
instance can be selected in the PinMux Section, or one can be solved for based
on the given capabilities
* **TIMA**:
    * 16-bit counter with 8-bit prescaler and Fault Handling (uses external pin)
    * TIMA0 also has a repeat counter
    * **Only available on MSPM0Gxx**
* **TIMG**:
    * 16-bit counter with 8-bit prescaler
* **TIMG12**:
    * 32-bit counter without a prescaler
    * **Only available on MSPM0Gxx**\n

The Quick Profile Options are:
* **Capture Duty Cycle and Period**:
    * Configures timer in combined capture mode to measure a PWM
      signal's period and duty cycle
    * Uses BUSCLK/1/1
    * Timer period 62.52 us
    * Input capture mode set to single
    * Capture trigger configuration set to external pin
    * Capture mode set to edge time
    * Capture edge detection mode set to rising edge detection
    * Input channel set to capture channel 0
    * Channel 0 compare down event interrupt enabled
* **Custom**:
    * Allows custom configuration
`,
                default: "CUSTOM",
                options: [
                    { name: "CUSTOM", displayName: "Custom" },
                    { name: "duty_cycle_period", displayName: "Capture Duty Cycle and Period"}
                ],
                onChange: onChangeTimerProfile
            }
        ]
    },
    {
        name: "GROUP_BASIC",
        displayName: "Basic Configuration",
        description: "",
        longDescription: "",
        collapsed: false,
            config: [
                {
                    name: "GROUP_CLOCK",
                    displayName: "Clock Configuration",
                    description: "",
                    longDescription: "Configures Timer clock source, divider and prescaler",
                    collapsed: false,
                    config: [
                        {
                            name        : "timerClkSrc",
                            displayName : 'Timer Clock Source',
                            description : 'Timer clock source selection',
                            hidden      : false,
                            default     : "BUSCLK",
                            options     : TimerClockSourceOptions,
                            onChange    : onChangeSetCustomProfile
                        },
                        {
                            name        : "timerClkDiv",
                            displayName : 'Timer Clock Divider',
                            description : 'Timer Clock Divider',
                            hidden      : false,
                            default     : 1,
                            options     : TimerClockDividerOptions,
                            onChange    : onChangeSetCustomProfile
                        },
                        {
                            name        : "timerClockSourceCalculated",
                            displayName : "Calculated Timer Clock Source",
                            description : 'Calculated Timer Clock Source in Hz',
                            hidden      : false,
                            getValue    : (inst) => getTimerClockSourceFreq(inst),
                            default     : 0
                        },
                        {
                            name        : "timerClkPrescale",
                            displayName : 'Timer Clock Prescaler',
                            description : 'Timer Clock Prescaler',
                            hidden      : false,
                            isInteger   : true,
                            default     : 1,
                            range       : [1, 256],
                            onChange    : onChangeSetCustomProfile
                        },
                        {
                            name: "GROUP_CLOCK_CAL",
                            displayName: "Calculated Timer Clock Values",
                            description: "",
                            collapsed: false,
                            config:
                            [
                                {
                                    name: "timerClockFreqNum",
                                    displayName : 'Timer Clock Frequency',
                                    description : 'Timer Clock Frequency',
                                    hidden: true,
                                    default: 0,
                                    getValue: getTimerClockFreq,
                                },
                                {
                                    name: "timerClockFreqStr",
                                    displayName : 'Timer Clock Frequency',
                                    description : 'Timer Clock Frequency',
                                    longDescription:
`
This is the clock frequency that is seen by the timer count register. It is after the input clock has been
divided and prescaled.\n
Timer Clock Frequency calculation: timerClkFreq = (timerClkSrc / (timerClkDiv \* timerClkPrescale))\n
ex.\n
Timer clock sourced by BUSCLK running at 32000000 Hz\n
Timer clock source divider set to 2\n
Timer clock prescale set to 4\n
          timerClkFreq = (timerClkSrc / (timerClkDivRatio * timerClkPrescale))\n
          4000000 Hz = 16000000 Hz / (2 * 4)\n
`,
                                    readOnly: true,
                                    hidden: false,
                                    default: "0 Hz",
                                    getValue: getTimerClockFreqStr,
                                },
                                {
                                    name: "timerPeriodRangeStr",
                                    displayName : 'Timer Period Range And Resolution',
                                    description : 'Range and Resolution of currently selected Timer instance',
                                    longDescription: 'Take into account if selected Timer instance has a 16-bit or 32-bit counter.',
                                    readOnly: true,
                                    hidden: false,
                                    default: "0 Hz",
                                    getValue: getTimerPeriodRangeStr,
                                },
                            ]
                        },
                        {
                            name: "timerClockFreq",
                            hidden: true,
                            default: 0,
                            getValue: getTimerClockFreq,
                        },
                    ]
                },
            ]
        },
        {
            name        : "timerPeriod",
            displayName : 'Desired Timer Period',
            description : 'Desired Timer Period in seconds',
            longDescription: `The desired timer period is an input string that can set the period of the timer.
                                Expected units (s). Valid formats:
* Units with supported prefixes (G, M, k, c, m, u, n):
* 234.56 ms, 150ns
* Units without a prefix:
* 0.0123 s, 1.0 s
* Exponential form with units
* 123.45e-8 s
* No units or prefix (interpreted as seconds):
* 1.234`,
            hidden      : false,
            default     : "0 ms",
            onChange    : onChangeSetCustomProfile
        },
        {
            name        : "timerPeriodActualTicks",
            displayName : 'hidden-actualTimerTicks',
            description : 'hidden-actualTimerTicks',
            hidden      : true,
            default     : 0,
            getValue    : getActualTimerPeriodTicks,
        },
        {
            name        : "timerPeriodActual",
            displayName : 'Actual Timer Period',
            description : 'Actual Timer Period',
            hidden      : false,
            default     : "0 s",
            getValue    : getActualTimerPeriod,
        },
        {
            name        : "timerStartTimer",
            displayName : 'Start Timer',
            description : 'Start Timer',
            longDescription: `When selected, the timer starts counting
            after the Timer is initialized. Otherwise the timer will start
            counting after the application calls DL_TimerX_startCounter.`,
            hidden      : false,
            default     : false,
            onChange    : onChangeSetCustomProfile
        },
        {
            name: "GROUP_CAPTURE_CONFIG",
            displayName: "Capture Configuration",
            description: "",
            longDescription: "",
            collapsed: false,
            config:
            [
                {
                    name        : "captureInputMode",
                    displayName : 'Input Capture Mode',
                    description : 'Input Capture Mode',
                    longDescription: `Selects between Single or Multi Input mode`,
                    hidden      : false,
                    default     : "single",
                    options     : [
                        {name: "single", displayName: "Single"},
                        {name: "multi",  displayName: "Multi"},
                    ],
                    onChange    : (inst,ui) => {
                        onChangeSetInputMode(inst,ui);
                    },

                },
                {
                    name: "GROUP_CAPTURE_SINGLE_CONFIG",
                    displayName: "Single Capture Configuration",
                    description: "",
                    longDescription: "",
                    collapsed: false,
                    config: [
                        // initCaptureMode / initCaptureTriggerMode
                        {
                            name        : "captSelect",
                            displayName : "Capture Trigger Configuration",
                            description : '',
                            longDescription: `
The Capture Mode Options are:
* **External Pin:**  Configure timer in period capture, edge time or
pulse-width capture mode using the trigger as input source.
* **Event Trigger:** Configure timer in period capture, edge time or
pulse-width capture mode using the trigger as input source.`,
                            hidden      : false,
                            default     : "base",
                            options     : [
                                {name: "base", displayName: "External Pin"},
                                {name: "Trigger", displayName: "Event Trigger"},
                            ],
                            onChange    : (inst,ui) => {
                                ui.captEdgeDetection.hidden = (inst.captSelect != "base");
                                /* Trigger Capture does not support input channel or filtering */
                                ui.ccIndex.hidden     = (inst.captSelect == "Trigger");
                                ui.captInputInvMode.hidden     = (inst.captSelect == "Trigger");
                                ui.captFilter.hidden = (inst.captSelect == "Trigger");
                                ui.filteringMode.hidden = (inst.captSelect == "Trigger" || !inst.captFilter);
                                ui.filterPeriod.hidden = (inst.captSelect == "Trigger" || !inst.captFilter);
                                /* Capture Edge Detection Mode selection not available for combined mode */
                                ui.captEdgeDetection.hidden = (inst.captMode == "COMBINED") || (inst.captMode == "COMBINED_UP");

                                onChangeSetCustomProfile(inst,ui);
                            }
                        },
                        // DL_Timer_setCaptureCompareInputFilter / enableCaptureCompareInputFilter
                        {
                            name        : "captFilter",
                            displayName : "Enable Capture Compare Filtering",
                            description : '',
                            hidden      : false,
                            default     : false,
                            onChange    : (inst,ui) => {
                                ui.filteringMode.hidden = (!inst.captFilter);
                                ui.filterPeriod.hidden = (!inst.captFilter);
                                onChangeSetCustomProfile(inst,ui);
                            },
                        },
                        {
                            name: "GROUP_CAPT_FILTER",
                            displayName: "Input Filter Configuration",
                            description: "",
                            longDescription: "",
                            collapsed: false,
                            config: [
                                // cpv - DL_TIMER_CC_INPUT_FILT_CPV
                                {
                                    name        : "filteringMode",
                                    displayName : "Filtering Mode",
                                    description : '',
                                    hidden      : true,
                                    default     : "CONSEC_PER",
                                    options     : [
                                        {name: "CONSEC_PER", displayName: "Stricter consecutive period count"},
                                        {name: "VOTING", displayName: "Majority voting"},
                                    ],
                                    onChange    : onChangeSetCustomProfile,
                                },
                                // fp - DL_TIMER_CC_INPUT_FILT_FP
                                {
                                    name        : "filterPeriod",
                                    displayName : "Filter Period",
                                    description : '',
                                    hidden      : true,
                                    default     : "PER_3",
                                    options     : [
                                        {name: "PER_3", displayName: "3 TIMCLK"},
                                        {name: "PER_5", displayName: "5 TIMCLK"},
                                        {name: "PER_8", displayName: "8 TIMCLK"},
                                    ],
                                    onChange    : onChangeSetCustomProfile,
                                },
                            ]
                        },
                        // DL_TIMER_CAPTURE_MODE captureMode
                        {
                            name        : "captMode",
                            displayName : "Capture Mode",
                            description : 'Selects capture mode.',
                            hidden      : false,
                            default     : "EDGE_TIME",
                            longDescription: `
Up/down counting mode is currently not supported in capture mode.\n
Users can still override the default counting mode by calling
DL_Timer_setCounterMode API after SYSCFG_DL_init in the application to configure
custom capture mode.\n`,
                            options     : [
                                {name: "EDGE_TIME_UP", displayName: "Edge Time Up Counting"},
                                {name: "EDGE_TIME", displayName: "Edge Time Down Counting"},
                                {name: "PERIOD_CAPTURE_UP", displayName: "Period Capture Up Counting"},
                                {name: "PERIOD_CAPTURE", displayName: "Period Capture Down Counting"},
                                {name: "PULSE_WIDTH_UP", displayName: "Pulse-Width Capture Up Counting"},
                                {name: "PULSE_WIDTH", displayName: "Pulse-Width Capture Down Counting"},
                                {name: "COMBINED_UP", displayName: "Combined Capture Up Counting"},
                                {name: "COMBINED", displayName: "Combined Capture Down Counting"},
                            ],
                            onChange    : (inst,ui) => {
                                /* Capture Edge Detection Mode selection not available for combined mode */
                                ui.captEdgeDetection.hidden = ((inst.captMode == "COMBINED") || (inst.captMode == "COMBINED_UP"));
                                onChangeSetCustomProfile(inst,ui);
                            }
                        },
                        // DL_TIMER_EDGE_DETECTION_MODE edgeCaptMode
                        {
                            name        : "captEdgeDetection",
                            displayName : "Capture Edge Detection Mode",
                            description : 'Edge detection modes supported in capture mode.',
                            hidden      : false,
                            default     : "RISING",
                            options     : [
                                {name: "RISING", displayName: "Rising Edge detection"},
                                {name: "FALLING", displayName: "Falling Edge detection"},
                                {name: "EDGE", displayName: "Rising and Falling Edge detection"},
                            ],
                            onChange    : onChangeSetCustomProfile,
                        },
                        // DL_TIMER_INPUT_CHAN inputChan
                        {
                            name        : "ccIndex",
                            displayName : "Input Channel",
                            description : 'Selects input channel used for capture mode',
                            hidden      : false,
                            default: 0,
                            options: ccIndexOptions,
                            onChange    : onChangeSetCustomProfile,
                        },
                        // DL_TIMER_CC_INPUT_INV inputInvMode
                        {
                            name        : "captInputInvMode",
                            displayName : "Invert Input",
                            description : 'Specifies if input should be inverted',
                            hidden      : false,
                            default     : false,
                            onChange    : onChangeSetCustomProfile,
                        },
                    ]
                },
                {
                    name: "GROUP_CAPTURE_MULTI_CONFIG",
                    displayName: "Capture Multi Input Configuration",
                    description: "",
                    longDescription: "",
                    collapsed: false,
                    config:
                    [
                        // DL_TIMER_INPUT_CHAN inputChan
                        {
                            name        : "ccIndexMulti",
                            displayName : "Input Channel(s)",
                            description : 'Selects input channels used for capture mode',
                            hidden      : true,
                            default: [],
                            minSelections: 0,
                            options: ccIndexOptions,
                            getDisabledOptions:(inst) => {
                                let disabledOptions = [];
                                if((Common.hasTimerA()) && !isFourCCCapable(inst)){
                                    disabledOptions.push(ccIndexOptions[2]);
                                    disabledOptions.push(ccIndexOptions[3]);
                                    return _.map(disabledOptions, o => ({name: o.name, reason: "Only valid for TIMA0"}) );
                                }
                                else {
                                    return [];
                                }
                                },
                            onChange : (inst,ui) => {
                                onChangeSetInputMode(inst,ui);
                            },
                        },
                        {
                            name        : "multi_countMode",
                            displayName : "Counting Mode",
                            description : 'Select between down or up/down mode',
                            longDescription: `
Timer can be configured to run in DOWN, UP/DOWN or UP mode`,
                            hidden      : true,
                            default     : "DL_TIMER_COUNT_MODE_DOWN",
                            options     : [
                                {name:"DL_TIMER_COUNT_MODE_DOWN",    displayName: "DOWN"},
                                {name:"DL_TIMER_COUNT_MODE_UP_DOWN", displayName: "UP_DOWN"},
                                {name:"DL_TIMER_COUNT_MODE_UP",      displayName: "UP"},
                            ]
                        },
                        {
                            name        : "multi_countRep",
                            displayName : "Repeat Mode",
                            description : 'Timer counter behavior when reaching Zero event',
                            longDescription: `
Timer counter behavior when reaching the following zero event:\n\n
- DISABLED: Does not automatically advance following a zero event.\n
- ENABLED: Continues to advance following a zero event.\n
- ENABLED DEBUG: Continues to advance following a zero event if the debug mode is not
in effect, or following the release of the debug mode.\n`,
                            hidden      : true,
                            default     : "DL_TIMER_REPEAT_MODE_DISABLED",
                            options     : [
                                {name:"DL_TIMER_REPEAT_MODE_DISABLED",      displayName: "DISABLED"},
                                {name:"DL_TIMER_REPEAT_MODE_ENABLED",       displayName: "ENABLED"},
                                {name:"DL_TIMER_REPEAT_MODE_ENABLED_DEBUG", displayName: "ENABLED DEBUG"},
                            ]
                        },
                        {
                            name        : "multi_cvae",
                            displayName : "Counter Value After Enabled",
                            description : 'Counter Value Efter Enabled',
                            longDescription: `
Specifies the initialization condition of the counter when timer is started.`,
                            hidden      : true,
                            default     : "DL_TIMER_COUNT_AFTER_EN_LOAD_VAL",
                            options     : [
                                {name: "DL_TIMER_COUNT_AFTER_EN_LOAD_VAL",  displayName: "Counter is set to Timer Period value"},
                                {name: "DL_TIMER_COUNT_AFTER_EN_NO_CHANGE", displayName: "Counter value is unchanged from its current value"},
                                {name: "DL_TIMER_COUNT_AFTER_EN_ZERO",      displayName: "Counter is set to zero"},
                            ],
                        },
                        {
                            name: "multi_ch_zero",
                            displayName: "Timer Channel Generating Zero Event",
                            description : 'Timer channel which generates zero event',
                            longDescription: `
when the selected capture channel detects a capture event the timer count will
be set to zero.`,
                            hidden      : true,
                            default     : -1,
                            options: ccIndexOptionsZero,
                            getDisabledOptions:(inst) => {
                                let disabledOptions = [];
                                if((Common.hasTimerA()) && !isFourCCCapable(inst)){
                                    disabledOptions.push(ccIndexOptionsZero[3]);
                                    disabledOptions.push(ccIndexOptionsZero[4]);
                                    return _.map(disabledOptions, o => ({name: o.name, reason: "Only valid for TIMA0"}) );
                                }
                                else {
                                    return [];
                                }
                            },
                        },
                        /* Multi channel configuration */
                        {
                            name: "GROUP_CAPTURE_MULTI_CONFIG",
                            displayName: "Capture channel configuration",
                            description: "",
                            longDescription: "",
                            collapsed: false,
                            config:
                            [
                                {
                                    name: "GROUP_MULTI_CHAN_0",
                                    displayName: "CHANNEL 0 configuration",
                                    collapsed: false,
                                    config:
                                    [
                                        {
                                            name: "multi_ch0_input_mode",
                                            displayName: "Input Mode",
                                            description : '',
                                            longDescription: ``,
                                            hidden      : true,
                                            default     : "DL_TIMER_CC_IN_SEL_CCPX",
                                            options     : [
                                                {name: "DL_TIMER_CC_IN_SEL_CCPX", displayName: "External Pin CCP0"},
                                                {name: "DL_TIMER_CC_IN_SEL_CCPX_PAIR", displayName: "External Pin CCP1"},
                                                {name: "DL_TIMER_CC_IN_SEL_TRIG", displayName: "External Trigger"},
                                                {name: "DL_TIMER_CC_IN_SEL_CCP_XOR", displayName: "XOR of Capture Channels"},
                                                {name: "DL_TIMER_CC_IN_SEL_FSUB0", displayName: "Subscriber 0 event"},
                                                {name: "DL_TIMER_CC_IN_SEL_FSUB1", displayName: "Subscriber 1 event"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP0", displayName: "Comp0"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP1", displayName: "Comp1"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP2", displayName: "Comp2"},
                                            ],
                                        },
                                        {
                                            name        : "multi_ch0_input_filter",
                                            displayName : "Enable Input Filtering",
                                            description : '',
                                            hidden      : true,
                                            default     : false,
                                            onChange    : (inst,ui) => {
                                                ui.multi_ch0_filteringMode.hidden = (!inst.multi_ch0_input_filter);
                                                ui.multi_ch0_filterPeriod.hidden = (!inst.multi_ch0_input_filter);
                                                onChangeSetCustomProfile(inst,ui);
                                            },
                                        },
                                        {
                                            name: "GROUP_MULTI_CH0_CAPT_FILTER",
                                            displayName: "Input Filter Configuration",
                                            description: "",
                                            longDescription: "",
                                            collapsed: false,
                                            config: [
                                                // cpv - DL_TIMER_CC_INPUT_FILT_CPV
                                                {
                                                    name        : "multi_ch0_filteringMode",
                                                    displayName : "Filtering Mode",
                                                    description : '',
                                                    hidden      : true,
                                                    default     : "CONSEC_PER",
                                                    options     : [
                                                        {name: "CONSEC_PER", displayName: "Stricter consecutive period count"},
                                                        {name: "VOTING", displayName: "Majority voting"},
                                                    ],
                                                    onChange    : onChangeSetCustomProfile,
                                                },
                                                // fp - DL_TIMER_CC_INPUT_FILT_FP
                                                {
                                                    name        : "multi_ch0_filterPeriod",
                                                    displayName : "Filter Period",
                                                    description : '',
                                                    hidden      : true,
                                                    default     : "PER_3",
                                                    options     : [
                                                        {name: "PER_3", displayName: "3 TIMCLK"},
                                                        {name: "PER_5", displayName: "5 TIMCLK"},
                                                        {name: "PER_8", displayName: "8 TIMCLK"},
                                                    ],
                                                    onChange    : onChangeSetCustomProfile,
                                                },
                                            ]
                                        },
                                        {
                                            // DL_TIMER_EDGE_DETECTION_MODE edgeCaptMode
                                            name        : "multi_ch0_captEdgeDetection",
                                            displayName : "Capture Edge Detection Mode",
                                            description : 'Edge detection modes supported in capture mode.',
                                            hidden      : true,
                                            default     : "DL_TIMER_CC_CCOND_TRIG_RISE",
                                            options     : [
                                                {name: "DL_TIMER_CC_CCOND_TRIG_RISE", displayName: "Rising Edge detection"},
                                                {name: "DL_TIMER_CC_CCOND_TRIG_FALL", displayName: "Falling Edge detection"},
                                                {name: "DL_TIMER_CC_CCOND_TRIG_EDGE", displayName: "Both Rising and Falling Edge detection"},
                                            ],
                                            onChange    : onChangeSetCustomProfile,
                                        },
                                        {
                                            name        : "multi_ch0_InputInvMode",
                                            displayName : "Invert Input",
                                            description : 'Specifies if input should be inverted',
                                            hidden      : true,
                                            default     : false,
                                            onChange    : onChangeSetCustomProfile,
                                        },
                                    ]
                                },
                                {
                                    name: "GROUP_MULTI_CHAN_1",
                                    displayName: "CHANNEL 1 configuration",
                                    collapsed: false,
                                    config:
                                    [
                                        {
                                            name: "multi_ch1_input_mode",
                                            displayName: "Input Mode",
                                            description : '',
                                            longDescription: ``,
                                            hidden      : true,
                                            default     : "DL_TIMER_CC_IN_SEL_CCPX",
                                            options     : [
                                                {name: "DL_TIMER_CC_IN_SEL_CCPX", displayName: "External Pin CCP1"},
                                                {name: "DL_TIMER_CC_IN_SEL_CCPX_PAIR", displayName: "External Pin CCP0"},
                                                {name: "DL_TIMER_CC_IN_SEL_TRIG", displayName: "External Trigger"},
                                                {name: "DL_TIMER_CC_IN_SEL_CCP_XOR", displayName: "XOR of Capture Channels"},
                                                {name: "DL_TIMER_CC_IN_SEL_FSUB0", displayName: "Subscriber 0 event"},
                                                {name: "DL_TIMER_CC_IN_SEL_FSUB1", displayName: "Subscriber 1 event"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP0", displayName: "Comp0"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP1", displayName: "Comp1"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP2", displayName: "Comp2"},
                                            ],
                                        },
                                        {
                                            name        : "multi_ch1_input_filter",
                                            displayName : "Enable Input Filtering",
                                            description : '',
                                            hidden      : true,
                                            default     : false,
                                            onChange    : (inst,ui) => {
                                                ui.multi_ch1_filteringMode.hidden = (!inst.multi_ch1_input_filter);
                                                ui.multi_ch1_filterPeriod.hidden = (!inst.multi_ch1_input_filter);
                                                onChangeSetCustomProfile(inst,ui);
                                            },
                                        },
                                        {
                                            name: "GROUP_MULTI_CH1_CAPT_FILTER",
                                            displayName: "Input Filter Configuration",
                                            description: "",
                                            longDescription: "",
                                            collapsed: false,
                                            config: [
                                                // cpv - DL_TIMER_CC_INPUT_FILT_CPV
                                                {
                                                    name        : "multi_ch1_filteringMode",
                                                    displayName : "Filtering Mode",
                                                    description : '',
                                                    hidden      : true,
                                                    default     : "CONSEC_PER",
                                                    options     : [
                                                        {name: "CONSEC_PER", displayName: "Stricter consecutive period count"},
                                                        {name: "VOTING", displayName: "Majority voting"},
                                                    ],
                                                    onChange    : onChangeSetCustomProfile,
                                                },
                                                // fp - DL_TIMER_CC_INPUT_FILT_FP
                                                {
                                                    name        : "multi_ch1_filterPeriod",
                                                    displayName : "Filter Period",
                                                    description : '',
                                                    hidden      : true,
                                                    default     : "PER_3",
                                                    options     : [
                                                        {name: "PER_3", displayName: "3 TIMCLK"},
                                                        {name: "PER_5", displayName: "5 TIMCLK"},
                                                        {name: "PER_8", displayName: "8 TIMCLK"},
                                                    ],
                                                    onChange    : onChangeSetCustomProfile,
                                                },
                                            ]
                                        },
                                        {
                                            // DL_TIMER_EDGE_DETECTION_MODE edgeCaptMode
                                            name        : "multi_ch1_captEdgeDetection",
                                            displayName : "Capture Edge Detection Mode",
                                            description : 'Edge detection modes supported in capture mode.',
                                            hidden      : true,
                                            default     : "DL_TIMER_CC_CCOND_TRIG_RISE",
                                            options     : [
                                                {name: "DL_TIMER_CC_CCOND_TRIG_RISE", displayName: "Rising Edge detection"},
                                                {name: "DL_TIMER_CC_CCOND_TRIG_FALL", displayName: "Falling Edge detection"},
                                                {name: "DL_TIMER_CC_CCOND_TRIG_EDGE", displayName: "Both Rising and Falling Edge detection"},
                                            ],
                                            onChange    : onChangeSetCustomProfile,
                                        },
                                        {
                                            name        : "multi_ch1_InputInvMode",
                                            displayName : "Invert Input",
                                            description : 'Specifies if input should be inverted',
                                            hidden      : true,
                                            default     : false,
                                            onChange    : onChangeSetCustomProfile,
                                        },
                                    ]
                                },
                                {
                                    name: "GROUP_MULTI_CHAN_2",
                                    displayName: "CHANNEL 2 configuration",
                                    collapsed: false,
                                    config:
                                    [
                                        {
                                            name: "multi_ch2_input_mode",
                                            displayName: "Input Mode",
                                            description : '',
                                            longDescription: ``,
                                            hidden      : true,
                                            default     : "DL_TIMER_CC_IN_SEL_CCPX",
                                            options     : [
                                                {name: "DL_TIMER_CC_IN_SEL_CCPX", displayName: "External Pin CCP2"},
                                                {name: "DL_TIMER_CC_IN_SEL_CCPX_PAIR", displayName: "External Pin CCP3"},
                                                {name: "DL_TIMER_CC_IN_SEL_CCP0", displayName: "External Pin CCP0"},
                                                {name: "DL_TIMER_CC_IN_SEL_TRIG", displayName: "External Trigger"},
                                                {name: "DL_TIMER_CC_IN_SEL_CCP_XOR", displayName: "XOR of Capture Channels"},
                                                {name: "DL_TIMER_CC_IN_SEL_FSUB0", displayName: "Subscriber 0 event"},
                                                {name: "DL_TIMER_CC_IN_SEL_FSUB1", displayName: "Subscriber 1 event"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP0", displayName: "Comp0"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP1", displayName: "Comp1"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP2", displayName: "Comp2"},
                                            ],
                                        },
                                        {
                                            name        : "multi_ch2_input_filter",
                                            displayName : "Enable Input Filtering",
                                            description : '',
                                            hidden      : true,
                                            default     : false,
                                            onChange    : (inst,ui) => {
                                                ui.multi_ch2_filteringMode.hidden = (!inst.multi_ch2_input_filter);
                                                ui.multi_ch2_filterPeriod.hidden = (!inst.multi_ch2_input_filter);
                                                onChangeSetCustomProfile(inst,ui);
                                            },
                                        },
                                        {
                                            name: "GROUP_MULTI_CH2_CAPT_FILTER",
                                            displayName: "Input Filter Configuration",
                                            description: "",
                                            longDescription: "",
                                            collapsed: false,
                                            config: [
                                                // cpv - DL_TIMER_CC_INPUT_FILT_CPV
                                                {
                                                    name        : "multi_ch2_filteringMode",
                                                    displayName : "Filtering Mode",
                                                    description : '',
                                                    hidden      : true,
                                                    default     : "CONSEC_PER",
                                                    options     : [
                                                        {name: "CONSEC_PER", displayName: "Stricter consecutive period count"},
                                                        {name: "VOTING", displayName: "Majority voting"},
                                                    ],
                                                    onChange    : onChangeSetCustomProfile,
                                                },
                                                // fp - DL_TIMER_CC_INPUT_FILT_FP
                                                {
                                                    name        : "multi_ch2_filterPeriod",
                                                    displayName : "Filter Period",
                                                    description : '',
                                                    hidden      : true,
                                                    default     : "PER_3",
                                                    options     : [
                                                        {name: "PER_3", displayName: "3 TIMCLK"},
                                                        {name: "PER_5", displayName: "5 TIMCLK"},
                                                        {name: "PER_8", displayName: "8 TIMCLK"},
                                                    ],
                                                    onChange    : onChangeSetCustomProfile,
                                                },
                                            ]
                                        },
                                        {
                                            // DL_TIMER_EDGE_DETECTION_MODE edgeCaptMode
                                            name        : "multi_ch2_captEdgeDetection",
                                            displayName : "Capture Edge Detection Mode",
                                            description : 'Edge detection modes supported in capture mode.',
                                            hidden      : true,
                                            default     : "DL_TIMER_CC_CCOND_TRIG_RISE",
                                            options     : [
                                                {name: "DL_TIMER_CC_CCOND_TRIG_RISE", displayName: "Rising Edge detection"},
                                                {name: "DL_TIMER_CC_CCOND_TRIG_FALL", displayName: "Falling Edge detection"},
                                                {name: "DL_TIMER_CC_CCOND_TRIG_EDGE", displayName: "Both Rising and Falling Edge detection"},
                                            ],
                                            onChange    : onChangeSetCustomProfile,
                                        },
                                        {
                                            name        : "multi_ch2_InputInvMode",
                                            displayName : "Invert Input",
                                            description : 'Specifies if input should be inverted',
                                            hidden      : true,
                                            default     : false,
                                            onChange    : onChangeSetCustomProfile,
                                        },
                                    ]
                                },
                                {
                                    name: "GROUP_MULTI_CHAN_3",
                                    displayName: "CHANNEL 3 configuration",
                                    collapsed: false,
                                    config:
                                    [
                                        {
                                            name: "multi_ch3_input_mode",
                                            displayName: "Input Mode",
                                            description : '',
                                            longDescription: ``,
                                            hidden      : true,
                                            default     : "DL_TIMER_CC_IN_SEL_CCPX",
                                            options     : [
                                                {name: "DL_TIMER_CC_IN_SEL_CCPX", displayName: "External Pin CCP3"},
                                                {name: "DL_TIMER_CC_IN_SEL_CCPX_PAIR", displayName: "External Pin CCP2"},
                                                {name: "DL_TIMER_CC_IN_SEL_CCP0", displayName: "External Pin CCP0"},
                                                {name: "DL_TIMER_CC_IN_SEL_TRIG", displayName: "External Trigger"},
                                                {name: "DL_TIMER_CC_IN_SEL_CCP_XOR", displayName: "XOR of Capture Channels"},
                                                {name: "DL_TIMER_CC_IN_SEL_FSUB0", displayName: "Subscriber 0 event"},
                                                {name: "DL_TIMER_CC_IN_SEL_FSUB1", displayName: "Subscriber 1 event"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP0", displayName: "Comp0"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP1", displayName: "Comp1"},
                                                {name: "DL_TIMER_CC_IN_SEL_COMP2", displayName: "Comp2"},
                                            ],
                                        },
                                        {
                                            name        : "multi_ch3_input_filter",
                                            displayName : "Enable Input Filtering",
                                            description : '',
                                            hidden      : true,
                                            default     : false,
                                            onChange    : (inst,ui) => {
                                                ui.multi_ch3_filteringMode.hidden = (!inst.multi_ch3_input_filter);
                                                ui.multi_ch3_filterPeriod.hidden = (!inst.multi_ch3_input_filter);
                                                onChangeSetCustomProfile(inst,ui);
                                            },
                                        },
                                        {
                                            name: "GROUP_MULTI_CH3_CAPT_FILTER",
                                            displayName: "Input Filter Configuration",
                                            description: "",
                                            longDescription: "",
                                            collapsed: false,
                                            config: [
                                                // cpv - DL_TIMER_CC_INPUT_FILT_CPV
                                                {
                                                    name        : "multi_ch3_filteringMode",
                                                    displayName : "Filtering Mode",
                                                    description : '',
                                                    hidden      : true,
                                                    default     : "CONSEC_PER",
                                                    options     : [
                                                        {name: "CONSEC_PER", displayName: "Stricter consecutive period count"},
                                                        {name: "VOTING", displayName: "Majority voting"},
                                                    ],
                                                    onChange    : onChangeSetCustomProfile,
                                                },
                                                // fp - DL_TIMER_CC_INPUT_FILT_FP
                                                {
                                                    name        : "multi_ch3_filterPeriod",
                                                    displayName : "Filter Period",
                                                    description : '',
                                                    hidden      : true,
                                                    default     : "PER_3",
                                                    options     : [
                                                        {name: "PER_3", displayName: "3 TIMCLK"},
                                                        {name: "PER_5", displayName: "5 TIMCLK"},
                                                        {name: "PER_8", displayName: "8 TIMCLK"},
                                                    ],
                                                    onChange    : onChangeSetCustomProfile,
                                                },
                                            ]
                                        },
                                        {
                                            // DL_TIMER_EDGE_DETECTION_MODE edgeCaptMode
                                            name        : "multi_ch3_captEdgeDetection",
                                            displayName : "Capture Edge Detection Mode",
                                            description : 'Edge detection modes supported in capture mode.',
                                            hidden      : true,
                                            default     : "DL_TIMER_CC_CCOND_TRIG_RISE",
                                            options     : [
                                                {name: "DL_TIMER_CC_CCOND_TRIG_RISE", displayName: "Rising Edge detection"},
                                                {name: "DL_TIMER_CC_CCOND_TRIG_FALL", displayName: "Falling Edge detection"},
                                                {name: "DL_TIMER_CC_CCOND_TRIG_EDGE", displayName: "Both Rising and Falling Edge detection"},
                                            ],
                                            onChange    : onChangeSetCustomProfile,
                                        },
                                        {
                                            name        : "multi_ch3_InputInvMode",
                                            displayName : "Invert Input",
                                            description : 'Specifies if input should be inverted',
                                            hidden      : true,
                                            default     : false,
                                            onChange    : onChangeSetCustomProfile,
                                        },
                                    ]
                                }
                            ]
                        },

                    ]
                },
            ]
        },
        {
            name: "GROUP_ADVANCED",
            displayName: "Advanced Configuration",
            collapsed: true,
            config: configAdvanced,
        },
        {
            name: "interruptsConfig",
            displayName: "Interrupts Configuration",
            collapsed: true,
            config: [
                {
                    name: "interrupts",
                    displayName: "Enable Interrupts",
                    description: "Specifies which interrupts are to be enabled",
                    longDescription: `Specifies the timer interrupts will be triggered`,
                    default: [],
                    options: InterruptOptions,
                    minSelections: 0,
                    onChange: onChangeInterrupts,
                    getDisabledOptions: getDisabledOptionsInterrupts,
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
        {
            name: "eventConfig",
            displayName: "Event Configuration",
            longDescription: `Specifies the Timer Events that are to trigger an Event Condition and where the events are to be published`,
            collapsed: true,
            config: [
                {
                    name: "event1PublisherChannel",
                    displayName: "Event 1 Publisher Channel ID",
                    description: "Specifies the Channel For Event 1",
                    longDescription: `Specifies the Channel to which Timer Events in Event 1 will be published for use by other modules`,
                    default: 0,
                    options: (inst) => {
                        return EVENT.getPublisherOptions(inst);
                    },
                    getDisabledOptions: (inst) => {
                        return EVENT.getPublisherDisabledOptions(inst);
                    },
                    onChange: (inst,ui) => {
                        ui.event1ControllerInterruptEn.hidden = (inst.event1PublisherChannel == 0);
                    }
                },
                {
                    name: "event1ControllerInterruptEn",
                    displayName: "Event 1 Enable Controller Interrupts",
                    description: "Determines the Timer Events that will trigger an Event 1 condition",
                    longDescription: `Selects all possible timer Events that will create an Event 1 condition`,
                    hidden: true,
                    default: [],
                    options: EventOptions,
                    minSelections: 0,
                    getDisabledOptions: getDisabledOptionsEvents
                },
                {
                    name: "event2PublisherChannel",
                    displayName: "Event 2 Publisher Channel ID",
                    description: "Specifies the Channel For Event 2",
                    longDescription: `Specifies the Channel to which Timer Events in Event 2 will be published for use by other modules`,
                    default: 0,
                    options: (inst) => {
                        return EVENT.getPublisherOptions(inst);
                    },
                    getDisabledOptions: (inst) => {
                        return EVENT.getPublisherDisabledOptions(inst);
                    },
                    onChange: (inst,ui) => {
                        ui.event2ControllerInterruptEn.hidden = (inst.event2PublisherChannel == 0);
                    }
                },
                {
                    name: "event2ControllerInterruptEn",
                    displayName: "Event 2 Enable Controller Interrupts",
                    description: "Determines the Timer Events that will trigger an Event 2 condition",
                    longDescription: `Selects all possible timer Events that will create an Event 2 condition`,
                    hidden: true,
                    default: [],
                    options: EventOptions,
                    minSelections: 0,
                    getDisabledOptions: getDisabledOptionsEvents
                },
                {
                    name: "subscriberPort",
                    displayName: "Subscriber Port Selection",
                    description: "Specifies the subscriber port to be used",
                    longDescription: `Specifies the subscriber port to be used`,
                    default: "Disabled",
                    options: [
                        {name: "Disabled", displayName: "Disabled"},
                        {name: "FSUB0", displayName: "SubscriberPort0"},
                        {name: "FSUB1", displayName: "SubscriberPort1"}
                    ],
                    onChange: (inst, ui) => {
                        ui.subscriberChannel.hidden = (inst.subscriberPort == "Disabled");
                    }
                },
                {
                    name: "subscriberChannel",
                    displayName: "Subscriber Port Channel Selection",
                    description: "Specifies the channel for a subscriber port",
                    longDescription: `Specifies the event subscriber channel`,
                    hidden: true,
                    default: 0,
                    options: (inst) => {
                        return EVENT.getSubscriberOptions(inst);
                    },
                    getDisabledOptions: (inst) => {
                        return EVENT.getSubscriberDisabledOptions(inst);
                    },
                },
                {
                    name: "eventInfo",
                    description: "information about configured events that's passed on to the EVENT module",
                    default: [""],
                    hidden: true,
                    options: (inst) => {
                        let options = [{name: ""}]
                        if(inst.event1PublisherChannel != 0){
                            options.push({name: inst.event1PublisherChannel.toString() + "pub"});
                        }
                        if(inst.event2PublisherChannel != 0){
                            options.push({name: inst.event2PublisherChannel.toString() + "pub"});
                        }
                        if((inst.subscriberPort != "Disabled") && (inst.subscriberChannel != 0)){
                            options.push({name: inst.subscriberChannel.toString() + "sub"});
                        }
                        return options;
                    },
                    getValue: (inst) => {
                        let result = [];
                        if(inst.event1PublisherChannel != 0){
                            result.push(inst.event1PublisherChannel.toString() + "pub");
                        }
                        if(inst.event2PublisherChannel != 0){
                            result.push(inst.event2PublisherChannel.toString() + "pub");
                        }
                        if((inst.subscriberPort != "Disabled") && (inst.subscriberChannel != 0)){
                            result.push(inst.subscriberChannel.toString() + "sub");
                        }
                        if(result.length == 0){
                            result = [""];
                        }
                        return result;
                    }
                }

            ]
        },
]

/* Add Pinmux Peripheral Configuration group */
config = config.concat(Common.getGPIOGroupConfig());

const TimerFilterElementsUsed = ["enableRepeatCounter", "ccIndex", "clockPrescale"];

const memoizedTimerFilter = _.memoize(curryTimerFilter,
    (inst) => JSON.stringify(_.pick(inst,TimerFilterElementsUsed)));

function curryTimerFilter(inst) {
    const args = _.pick(inst, TimerFilterElementsUsed);
    return (peripheral) => TimerFilter(peripheral, args);
}

const memoizedPWMResourceFilter = _.memoize(curryTimerResourceFilter,
    (inst) => JSON.stringify(_.pick(inst, TimerFilterElementsUsed)));

function curryTimerResourceFilter(inst) {
    const args = _.pick(inst, TimerFilterElementsUsed);
    return (_, peripheral) => TimerFilter(peripheral, args);
}

function TimerFilter(peripheral, inst) {
    let validPeripheral = true;
    let chanEnabled = [false, false, false, false];
    if(inst.captureInputMode == "multi")
    {
        for (let channel of inst.ccIndexMulti) {
            let cc = inst.ccIndexMulti[channel];
            let multiCCName = "multi_ch"+ cc.toString() +"_input_mode"
            switch (inst[multiCCName] ) {
                case "DL_TIMER_CC_IN_SEL_CCPX":
                case "DL_TIMER_CC_IN_SEL_CCP_XOR":
                    chanEnabled[cc] = true;
                    break;
                case "DL_TIMER_CC_IN_SEL_CCPX_PAIR":
                    let pairCh;
                    switch (cc) {
                        case 0:
                            pairCh = 1;
                            break;
                        case 1:
                            pairCh = 0;
                            break;
                        case 2:
                            pairCh = 3;
                            break;
                        case 3:
                            pairCh = 2;
                            break;
                        default:
                            break;
                    }
                    chanEnabled[pairCh] = true;
                        break;
                    case "DL_TIMER_CC_IN_SEL_CCP0_PAIR":
                        chanEnabled[0] = true;
                        break;
                default:
                    break;
            }
        }
    }else{
            chanEnabled[inst.ccIndex] = true;

    }

    if(chanEnabled[2] || chanEnabled[3]) {
        validPeripheral &= /TIMA0/.test(peripheral.name);
    }


    if(inst.clockPrescale !== 1){
        // cannot be TIMG12
        validPeripheral &= !(/TIMG12\d/.test(peripheral.name));
    }
    return validPeripheral;
}

/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured PWM instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{
    let allResources = [
        {
            name: "ccp0Pin",
            displayName: "Capture/Compare Pin 0",
            interfaceNames: ["CCP0"],
        },
        {
            name: "ccp1Pin",
            displayName: "Capture/Compare Pin 1",
            interfaceNames: ["CCP1"],
        },
        {
            name: "ccp2Pin",
            displayName: "Capture/Compare Pin 2",
            interfaceNames: ["CCP2"],
        },
        {
            name: "ccp3Pin",
            displayName: "Capture/Compare Pin 3",
            interfaceNames: ["CCP3"],
        },
    ];

    let timer = {
        name: "peripheral",
        displayName: "Capture Timer Peripheral",
        interfaceName: "GPTIMER",
        resources: [],
        signalTypes: {
            ccp0Pin: ["CCP0"],
            ccp1Pin: ["CCP1"],
            ccp2Pin: ["CCP2"],
            ccp3Pin: ["CCP3"],
        },
    };

    if(inst.captSelect != "Trigger"){
        if(inst.captureInputMode == "multi")
        {
            for (let cc of inst.ccIndexMulti) {
                let multiCCName = "multi_ch"+ cc.toString() +"_input_mode"
                switch (inst[multiCCName] ) {
                    case "DL_TIMER_CC_IN_SEL_CCPX":
                    case "DL_TIMER_CC_IN_SEL_CCP_XOR":
                        if(timer.resources)
                        timer.resources.push(allResources[cc]);
                        break;
                    case "DL_TIMER_CC_IN_SEL_CCPX_PAIR":
                        let pairCh;
                        switch (cc) {
                            case 0:
                                pairCh = 1;
                                break;
                            case 1:
                                pairCh = 0;
                                break;
                            case 2:
                                pairCh = 3;
                                break;
                            case 3:
                                pairCh = 2;
                                break;
                            default:
                                break;
                        }
                        timer.resources.push(allResources[pairCh]);
                        break;
                    case "DL_TIMER_CC_IN_SEL_CCP0":
                        timer.resources.push(allResources[0]);
                        break;
                    default:
                        break;
                }
            }
        }else{
            timer.resources.push(allResources[inst.ccIndex]);
        }
    }

    return ([timer]);
}

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    /* validate dynmaicEnums */
    let dynamicEnums = ["secondaryCrossTriggerSource"];
    for(let dE of dynamicEnums){
        let validOptions = inst.$module.$configByName[dE].options();
        let selOption = inst[dE];
        let found = _.find(validOptions, (o) => o.name === selOption);
        if(!found){
            validation.logError("Invalid Option Selected. Please reselect", inst, dE);
        }
    }


    if((inst.ccIndexMulti.includes(inst.multi_ch_zero) == false) && (inst.multi_ch_zero != -1 )){
        validation.logError("Selected channel is not currently configured.",
            inst, ["ccIndexMulti", "multi_ch_zero"])
    }

    /* Cross Trigger Source Validation */
    if(inst.crossTriggerEn){
        if(inst.crossTriggerAuthority == "Main"){
            if(inst.mainCrossTriggerSource.includes("FSUB")){
                if (inst.mainCTSubscriberChannel == 0){
                    validation.logWarning("Selected Cross Trigger Source is not configured.", inst, "mainCTSubscriberChannel");
                }
            }
            if(!inst.timerStartTimer) {
                validation.logInfo("Note that the cross trigger will not be generated unless Start Timer is enabled.", inst, ["crossTriggerAuthority","timerStartTimer"]);
            }
        }
        else if(inst.crossTriggerAuthority == "Secondary"){
            if(inst.secondaryCrossTriggerSource.includes("SubscriberPort")){
                if (inst.secondaryCTSubscriberChannel == 0){
                    validation.logWarning("Selected Cross Trigger Source is not configured.", inst, "secondaryCTSubscriberChannel");
                }
            }
        }
    }

    /* validate use of combined capture mode */
    if(inst.captSelect == ("Trigger") && ((inst.captMode == "COMBINED") || (inst.captMode == "COMBINED_UP")))
    {
        validation.logError("Combined mode is not available for Event Trigger configuration", inst, ["captSelect", "captMode"]);
    }

    /* Validate Event selection for case of switching devices.
     * Checks that selected event is withing the valid options
     * for current device.
     */
    EVENT.validatePublisherOptions(inst,validation,"event1PublisherChannel");
    EVENT.validatePublisherOptions(inst,validation,"event2PublisherChannel");
    if(inst.subscriberPort != "Disabled"){
        EVENT.validateSubscriberOptions(inst,validation,"subscriberChannel");
    }

    Common.validateNames(inst, validation);
}

/*
 *  ======== validatePinmux ========
 *  Validation run after solution
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validatePinmux(inst, validation) {
    /* Validation run after solution */
    let solution = inst.peripheral.$solution.peripheralName;
    if(Common.hasTimerA()){
        if(inst.enableRepeatCounter){
            if(!(/TIMA/.test(solution))){
                validation.logError("Repeat Counter only available on Timer A instances. Please select a Timer A instance from PinMux if available.",inst,"enableRepeatCounter");
            }
        }
    }

    /* timerClkPrescale validation */
    if(/TIMG12|TIMG13/.test(solution)){
        if(inst.timerClkPrescale !== 1) {
            validation.logError("Prescaler is not available for 32-bit Timers. Select a prescale value of 1, or a different peripheral in PinMux section", inst, "timerClkPrescale");
        }
    }

    /* Retention Validation */
    Common.getRetentionValidation(inst,validation);

    /* Clock Source Validation - BUSCLK can change based on selected peripheral */
    if(inst.timerClockFreq == 0)
    {
        let str = "Clock Source " + inst.timerClkSrc + " not properly initialized in SYSCTL";
        validation.logError(str, inst, "timerClkSrc");
    }
    /* Timer Period Validation - valid range can change based on selected peripheral */
    try{
        // match rather than parse a second time to avoid doing multiple parses
        if(inst.timerPeriodActual.match("NaN")){
            validation.logError("Unrecognized number or unit. Valid formats in description", inst, "timerPeriod");
        } else {
            if(inst.timerPeriodActual.match("out of range"))
            {
                let period = getScaledPeriod(Common.parseFloatUnitInput(inst.timerPeriod, "s"));
                let str = "Desired Timer Period: " + period[0] + period[1] +" is out of range with current timer clock configuration. Please refer to \"Timer Period Range and Resolution\" for valid range.";
                validation.logError(str, inst, "timerPeriod");
            }
        }

    }catch (e) {
        // do nothing
    }
}

/*
 *  ========= filterHardware ========
 *  Check 'component' signals for compatibility with module
 *
 *  param component - hardware object describing signals and
 *                    resources they're attached to
 *  returns Boolean indicating whether or not to allow the component to
 *           be assigned to an instance's $hardware config
 */
function filterHardware(component)
{
    let modulePin;

    for (let sig in component.signals) {
        let type = component.signals[sig].type;
        if (Common.typeMatches(type, ["TIM."])) modulePin = sig;
    }
    let result = modulePin ? true : false;

    return (result);
}

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    return "";
}

function moduleInstances(inst){
    let modInstances = [];

    /*
     * Gets a Peripheral GPIO Configuration submodule
     */
    /* CONDITIONS CODE START */
    // ccp0, ccp1, ccp2, ccp3
    let timerConfig = [false, false, false, false];

    if(inst.captSelect != "Trigger"){
        if(inst.captureInputMode == "multi")
        {
            for (let cc of inst.ccIndexMulti) {
                let multiCCName = "multi_ch"+ cc.toString() +"_input_mode"
                switch (inst[multiCCName] ) {
                    case "DL_TIMER_CC_IN_SEL_CCPX":
                    case "DL_TIMER_CC_IN_SEL_CCP_XOR":
                        timerConfig[cc] = true;
                        break;
                    case "DL_TIMER_CC_IN_SEL_CCPX_PAIR":
                        let pairCh;
                        switch (cc) {
                            case 0:
                                pairCh = 1;
                                break;
                            case 1:
                                pairCh = 0;
                                break;
                            case 2:
                                pairCh = 3;
                                break;
                            case 3:
                                pairCh = 2;
                                break;
                            default:
                                break;
                        }
                        timerConfig[pairCh] = true;
                        break;
                    case "DL_TIMER_CC_IN_SEL_CCP0":
                        timerConfig[0] = true;
                        break;
                    default:
                        break;
                }
            }
        }else{
            timerConfig[inst.ccIndex] = true;
        }
    }
    /* CONDITIONS CODE END */

    /* CCP0 */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   timerConfig[0],    "ccp0Pin",
     "C0", "Capture/Compare Pin 0",
     "INPUT");
    /* CCP1 */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   timerConfig[1],    "ccp1Pin",
     "C1", "Capture/Compare Pin 1",
     "INPUT");
    /* CCP2 */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   timerConfig[2],    "ccp2Pin",
     "C2", "Capture/Compare Pin 2",
     "INPUT");
    /* CCP3 */
    Common.pushGPIOConfigInstAlt(inst, modInstances,   timerConfig[3],    "ccp3Pin",
     "C3", "Capture/Compare Pin 3",
     "INPUT");

    return (modInstances);
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: config,

    /* override generic requirements with  device-specific reqs (if any) */

    maxInstances : Common.peripheralCount("GPTIMER"),

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    validate: validate,

    validatePinmux: validatePinmux,

    moduleInstances: moduleInstances,

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/capture/CaptTimer.Board.c.xdt",
        boardh: "/ti/driverlib/capture/CaptTimer.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true,
        Retention: Common.isDeviceM0G(),
    },

    _getPinResources: _getPinResources
};

/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic module module to
 *  allow us to augment/override as needed for the MSP432.
 */
function extend(base)
{
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base, devSpecific);

    /* concatenate device-specific configs */
    result.config = base.config.concat(devSpecific.config);

    return (result);
}

/*
 *  ======== exports ========
 *  Export device-specific extensions to base exports
 */
exports = {
    /* required function, called by base module module */
    extend: extend
};
