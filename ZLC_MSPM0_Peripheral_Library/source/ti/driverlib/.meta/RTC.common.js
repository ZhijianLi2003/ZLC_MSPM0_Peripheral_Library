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
 *  ======== RTC.Common.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let EVENT = system.getScript("/ti/driverlib/EVENT.syscfg.js");

exports = {
    getBasicConfig      : getBasicConfig,
    getProfileConfig    : getProfileConfig,
    setRequiredModules  : setRequiredModules,
    getValidation       : getValidation,
    checkAlarms         : checkAlarms,
};

/************************ Options **********************************/
function getIntOptions(peripheral)
{
    let allOptions = [];
    if(peripheral == "RTC_A") {
        allOptions = allOptions.concat([
            {name: "CALENDAR_ALARM1", displayName: "Calendar Alarm 1 interrupt"},
            {name: "CALENDAR_ALARM2", displayName: "Calendar Alarm 2 interrupt"},
            {name: "PRESCALER0", displayName: "Prescaler 0 interrupt"},
            {name: "PRESCALER1", displayName: "Prescaler 1 interrupt"},
            {name: "PRESCALER2", displayName: "Prescaler 2 interrupt"},
            {name: "INTERVAL_ALARM", displayName: "Interval Alarm interrupt"},
            {name: "READY", displayName: "RTC Ready interrupt"},
            {name: "TSEVT", displayName: "Time Stamp Event"}
        ]);
    }
    else if (peripheral == "RTC")
    {
        allOptions = allOptions.concat([
            {name: "CALENDAR_ALARM1", displayName: "Calendar Alarm 1 interrupt"},
            {name: "CALENDAR_ALARM2", displayName: "Calendar Alarm 2 interrupt"},
            {name: "PRESCALER0", displayName: "Prescaler 0 interrupt"},
            {name: "PRESCALER1", displayName: "Prescaler 1 interrupt"},
            {name: "PRESCALER2", displayName: "Prescaler 2 interrupt"},
            {name: "INTERVAL_ALARM", displayName: "Interval Alarm interrupt"},
            {name: "READY", displayName: "RTC Ready interrupt"},
        ]);
    }
    return allOptions;
}

function getEventOptions(peripheral)
{
    let allOptions = [];
    if(peripheral == "RTC_A") {
        allOptions = allOptions.concat([
            {name: "CALENDAR_ALARM1", displayName: "Calendar Alarm 1 interrupt"},
            {name: "CALENDAR_ALARM2", displayName: "Calendar Alarm 2 interrupt"},
            {name: "PRESCALER0", displayName: "Prescaler 0 interrupt"},
            {name: "PRESCALER1", displayName: "Prescaler 1 interrupt"},
            {name: "PRESCALER2", displayName: "Prescaler 2 interrupt"},
            {name: "INTERVAL_ALARM", displayName: "Interval Alarm interrupt"},
            {name: "READY", displayName: "RTC Ready interrupt"},
            {name: "TSEVT", displayName: "Time Stamp Event"},
        ]);
    }
    else if (peripheral == "RTC")
    {
        allOptions = allOptions.concat([
            {name: "CALENDAR_ALARM1", displayName: "Calendar Alarm 1 event"},
            {name: "CALENDAR_ALARM2", displayName: "Calendar Alarm 2 event"},
            {name: "PRESCALER0", displayName: "Prescaler 0 event"},
            {name: "PRESCALER1", displayName: "Prescaler 1 event"},
            {name: "INTERVAL_ALARM", displayName: "Interval Alarm event"},
            {name: "READY", displayName: "RTC Ready event"},
        ]);
    }
    return allOptions;
}

function getTimeStampEventOptions() {
    // Only applies to RTC_A for now
    let tsOptions = [];
    tsOptions = tsOptions.concat([
        {name: "TIME_STAMP_EVENT_SOURCE_VDD_LOSS", displayName: "VDD loss"},
        {name: "TIME_STAMP_EVENT_SOURCE_TIO_0", displayName: "Tamper I/O 0"},
        {name: "TIME_STAMP_EVENT_SOURCE_TIO_1", displayName: "Tamper I/O 1"},
        {name: "TIME_STAMP_EVENT_SOURCE_TIO_2", displayName: "Tamper I/O 2"},
    ]);
    return tsOptions;
}

/************************* General functions **********************************/

function onChangeSetCustomProfile(inst,ui){
    inst.profile = "CUSTOM";
}

function checkAlarms(inst,ui) {
    onCalAlarm1Enable(inst, ui);
    onCalAlarm2Enable(inst, ui);
    onPerAlarm0Enable(inst, ui);
    onPerAlarm1Enable(inst, ui);
    onIntervalAlarmEnable(inst, ui);
    updateGUIInterrupts(inst, ui);
}

function updateGUIInterrupts(inst, ui){
    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
}

function onCalAlarm1Enable(inst, ui){
    if(inst.enCalAlarm1){
        ui.rtcCalAlarm1Date.hidden = false
        ui.enCalAlarm1Min.hidden = false
        ui.enCalAlarm1Hour.hidden = false
        ui.enCalAlarm1DOW.hidden = false
        ui.enCalAlarm1DOM.hidden = false
        if (inst.enCalAlarm1Min)
        {
            ui.calAlarm1Min.hidden = false
        }
        if (inst.enCalAlarm1Hour)
        {
            ui.calAlarm1Hour.hidden = false
        }
        if (inst.enCalAlarm1DOW)
        {
            ui.calAlarm1DOW.hidden = false
        }
        if (inst.enCalAlarm1DOM)
        {
            ui.calAlarm1DOM.hidden = false
        }

    }
    else {
        ui.rtcCalAlarm1Date.hidden = true
        ui.enCalAlarm1Min.hidden = true
        ui.enCalAlarm1Hour.hidden = true
        ui.enCalAlarm1DOW.hidden = true
        ui.enCalAlarm1DOM.hidden = true
        ui.calAlarm1Min.hidden = true
        ui.calAlarm1Hour.hidden = true
        ui.calAlarm1DOW.hidden = true
        ui.calAlarm1DOM.hidden = true
    }
}

function onCalAlarm1MinEnable(inst, ui){
    if(inst.enCalAlarm1Min){
        ui.calAlarm1Min.hidden = false
    }
    else {
        ui.calAlarm1Min.hidden = true
    }
}

function onCalAlarm1HourEnable(inst, ui){
    if(inst.enCalAlarm1Hour){
        ui.calAlarm1Hour.hidden = false
    }
    else {
        ui.calAlarm1Hour.hidden = true
    }
}

function onCalAlarm1DOWEnable(inst, ui){
    if(inst.enCalAlarm1DOW){
        ui.calAlarm1DOW.hidden = false
    }
    else {
        ui.calAlarm1DOW.hidden = true
    }
}

function onCalAlarm1DOMEnable(inst, ui){
    if(inst.enCalAlarm1DOM){
        ui.calAlarm1DOM.hidden = false
    }
    else {
        ui.calAlarm1DOM.hidden = true
    }
}

function onCalAlarm2Enable(inst, ui){
    if(inst.enCalAlarm2){
        ui.rtcCalAlarm2Date.hidden = false
        ui.enCalAlarm2Min.hidden = false
        ui.enCalAlarm2Hour.hidden = false
        ui.enCalAlarm2DOW.hidden = false
        ui.enCalAlarm2DOM.hidden = false
        if (inst.enCalAlarm2Min)
        {
            ui.calAlarm2Min.hidden = false
        }
        if (inst.enCalAlarm2Hour)
        {
            ui.calAlarm2Hour.hidden = false
        }
        if (inst.enCalAlarm2DOW)
        {
            ui.calAlarm2DOW.hidden = false
        }
        if (inst.enCalAlarm2DOM)
        {
            ui.calAlarm2DOM.hidden = false
        }

    }
    else {
        ui.rtcCalAlarm2Date.hidden = true
        ui.enCalAlarm2Min.hidden = true
        ui.enCalAlarm2Hour.hidden = true
        ui.enCalAlarm2DOW.hidden = true
        ui.enCalAlarm2DOM.hidden = true
        ui.calAlarm2Min.hidden = true
        ui.calAlarm2Hour.hidden = true
        ui.calAlarm2DOW.hidden = true
        ui.calAlarm2DOM.hidden = true

    }
}

function onCalAlarm2MinEnable(inst, ui){
    if(inst.enCalAlarm2Min){
        ui.calAlarm2Min.hidden = false
    }
    else {
        ui.calAlarm2Min.hidden = true
    }
}

function onCalAlarm2HourEnable(inst, ui){
    if(inst.enCalAlarm2Hour){
        ui.calAlarm2Hour.hidden = false
    }
    else {
        ui.calAlarm2Hour.hidden = true
    }
}

function onCalAlarm2DOWEnable(inst, ui){
    if(inst.enCalAlarm2DOW){
        ui.calAlarm2DOW.hidden = false
    }
    else {
        ui.calAlarm2DOW.hidden = true
    }
}

function onCalAlarm2DOMEnable(inst, ui){
    if(inst.enCalAlarm2DOM){
        ui.calAlarm2DOM.hidden = false
    }
    else {
        ui.calAlarm2DOM.hidden = true
    }
}

function onIntervalAlarmEnable(inst, ui){
    if(inst.enIntervalAlarm){
        ui.intervalAlarmEvent.hidden = false
    }
    else {
        ui.intervalAlarmEvent.hidden = true
    }
}

function onPerAlarm0Enable(inst, ui){
    if(inst.enPerAlarm0){
        ui.perAlarm0Divider.hidden = false
    }
    else {
        ui.perAlarm0Divider.hidden = true
    }
}

function onPerAlarm1Enable(inst, ui){
    if(inst.enPerAlarm1){
        ui.perAlarm1Divider.hidden = false
    }
    else {
        ui.perAlarm1Divider.hidden = true
    }
}

function onPerAlarm2Enable(inst, ui){
    if(inst.enPerAlarm2){
        ui.perAlarm2Divider.hidden = false
    }
    else {
        ui.perAlarm2Divider.hidden = true
    }
}

function getCalDOW(inst, userDOW){
    let daysOfTheWeek = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    let dow = daysOfTheWeek[Common.sliceNumber(userDOW)];
    return dow;
}

function getCalMonth(inst, userMonth){
    let months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
    let month = months[(userMonth - 1)];
    return month;
}

function getBaseCalendarDate(inst){
    let date = inst.calHour + ":" + inst.calMin + ":" + inst.calSec + " (HH:MM:SS) " + getCalMonth(inst, inst.calMonth) + " " + inst.calDOM + ", " + getCalDOW(inst, inst.calDOW) + ", " + inst.calYear;
    return date;
}

function getSuffix(inst, day){
    let suffix = ""
    switch(day){
    case 1:
    case 21:
    case 31:
        suffix = "st"
        break;
    case 2:
    case 22:
        suffix = "nd"
        break;
    case 3:
    case 23:
        suffix = "rd"
        break;
    default:
        suffix = "th";
        break;
    }
    return suffix
}

function getCalAlarm1Date(inst){

    let events = "";

    if (inst.enCalAlarm1Hour || inst.enCalAlarm1Min)
    {
        events += inst.calAlarm1Hour + ":" + inst.calAlarm1Min + " (HH:MM) ";
    }

    if(inst.enCalAlarm1DOW){
        events += getCalDOW(inst, inst.calAlarm1DOW) + ", "
    }
    if(inst.enCalAlarm1DOM){

        events += inst.calAlarm1DOM + getSuffix(inst, inst.calAlarm1DOM) +" day of the month "
    }
    if (events.length == 0){
        return "No alarm events enabled"
    }

    return events;
}

function getCalAlarm2Date(inst){

    let events = "";

    if (inst.enCalAlarm2Hour || inst.enCalAlarm2Min)
    {
        events += inst.calAlarm2Hour + ":" + inst.calAlarm2Min + " (HH:MM) ";
    }

    if(inst.enCalAlarm2DOW){
        events += getCalDOW(inst, inst.calAlarm2DOW) + ", "
    }
    if(inst.enCalAlarm2DOM){

        events += inst.calAlarm2DOM + getSuffix(inst, inst.calAlarm2DOM) +" day of the month "
    }
    if (events.length == 0){
        return "No alarm events enabled"
    }

    return events;
}

/************************* Basic functions *******************************/
/* onChange functions for Basic Configuration */

function onChangeFormat(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeCalAlarm1(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onCalAlarm1Enable(inst, ui);
}

function onChangeCalAlarm1Min(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onCalAlarm1MinEnable(inst, ui);
}

function onChangeCalAlarm1Hour(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onCalAlarm1HourEnable(inst, ui);
}

function onChangeCalAlarm1DOW(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onCalAlarm1DOWEnable(inst, ui);
}

function onChangeCalAlarm1DOM(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onCalAlarm1DOMEnable(inst, ui);
}

function onChangeCalAlarm2(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onCalAlarm2Enable(inst, ui);
}

function onChangeCalAlarm2Min(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onCalAlarm2MinEnable(inst, ui);
}

function onChangeCalAlarm2Hour(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onCalAlarm2HourEnable(inst, ui);
}

function onChangeCalAlarm2DOW(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onCalAlarm2DOWEnable(inst, ui);
}

function onChangeCalAlarm2DOM(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onCalAlarm2DOMEnable(inst, ui);
}

function onChangeIntervalAlarm(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onIntervalAlarmEnable(inst, ui);
}

function onChangePerAlarm0(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onPerAlarm0Enable(inst, ui);
}

function onChangePerAlarm1(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onPerAlarm1Enable(inst, ui);
}

function onChangePerAlarm2(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    onPerAlarm2Enable(inst, ui);
}

function onChangeInt(inst, ui)
{
    updateGUIInterrupts(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function getProfileConfig(peripheral){
    if(peripheral == "RTC_A") {
        return [
            {
                /* Calendar Alarm 1 at 4:30 Saturday, 15th day, Binary Format */
                name                    : "CONFIG_PROFILE_1",
                rtcFormat               : "BINARY",
                enCalAlarm1             : true,
                enCalAlarm1Min          : true,
                calAlarm1Min            : 30,
                enCalAlarm1Hour         : true,
                calAlarm1Hour           : 4,
                enCalAlarm1DOW          : true,
                calAlarm1DOW            : "6",
                enCalAlarm1DOM          : true,
                calAlarm1DOM            : 15,
                enCalAlarm2             : false,
                enCalAlarm2Min          : false,
                calAlarm2Min            : 1,
                enCalAlarm2Hour         : false,
                calAlarm2Hour           : 0,
                enCalAlarm2DOW          : false,
                calAlarm2DOW            : "0",
                enCalAlarm2DOM          : false,
                calAlarm2DOM            : 1,
                enIntervalAlarm         : false,
                intervalAlarmEvent      : "MINUTECHANGE",
                enPerAlarm0             : false,
                perAlarm0Divider        : "DIVIDE_8",
                enPerAlarm1             : false,
                perAlarm1Divider        : "DIVIDE_2",
                offsetCalFreq           : "32_KHZ",
                enabledInterrupts       :["CALENDAR_ALARM1"],
                interruptPriority       : "DEFAULT",
                pubChanID: 0,
                enabledEvents: [],
            },
            {
                /* Calendar Alarm 2 at 00:00 Tuesday, BCD Format */
                name                    : "CONFIG_PROFILE_2",
                rtcFormat               : "BCD",
                enCalAlarm1             : false,
                enCalAlarm1Min          : false,
                calAlarm1Min            : 1,
                enCalAlarm1Hour         : false,
                calAlarm1Hour           : 0,
                enCalAlarm1DOW          : false,
                calAlarm1DOW            : "0",
                enCalAlarm1DOM          : false,
                calAlarm1DOM            : 1,
                enCalAlarm2             : true,
                enCalAlarm2Min          : false,
                calAlarm2Min            : 0,
                enCalAlarm2Hour         : false,
                calAlarm2Hour           : 0,
                enCalAlarm2DOW          : true,
                calAlarm2DOW            : "2",
                enCalAlarm2DOM          : false,
                calAlarm2DOM            : 1,
                enIntervalAlarm         : false,
                intervalAlarmEvent      : "MINUTECHANGE",
                enPerAlarm0             : false,
                perAlarm0Divider        : "DIVIDE_8",
                enPerAlarm1             : false,
                perAlarm1Divider        : "DIVIDE_2",
                offsetCalFreq           : "32_KHZ",
                enabledInterrupts       :["CALENDAR_ALARM2"],
                interruptPriority       : "DEFAULT",
                pubChanID: 0,
                enabledEvents: [],
            },
            {
                /* Interval Alarm at every minute change, BCD Format */
                name                    : "CONFIG_PROFILE_3",
                rtcFormat               : "BCD",
                enCalAlarm1             : false,
                enCalAlarm1Min          : false,
                calAlarm1Min            : 1,
                enCalAlarm1Hour         : false,
                calAlarm1Hour           : 0,
                enCalAlarm1DOW          : false,
                calAlarm1DOW            : "0",
                enCalAlarm1DOM          : false,
                calAlarm1DOM            : 1,
                enCalAlarm2             : false,
                enCalAlarm2Min          : false,
                calAlarm2Min            : 1,
                enCalAlarm2Hour         : false,
                calAlarm2Hour           : 0,
                enCalAlarm2DOW          : false,
                calAlarm2DOW            : "0",
                enCalAlarm2DOM          : false,
                calAlarm2DOM            : 1,
                enIntervalAlarm         : true,
                intervalAlarmEvent      : "MINUTECHANGE",
                enPerAlarm0             : false,
                perAlarm0Divider        : "DIVIDE_8",
                enPerAlarm1             : false,
                perAlarm1Divider        : "DIVIDE_2",
                offsetCalFreq           : "32_KHZ",
                enabledInterrupts       :["INTERVAL_ALARM"],
                interruptPriority       : "DEFAULT",
                pubChanID: 0,
                enabledEvents: [],
            },
            {
                /* Periodic Alarm 0 at 1024 Hz, Binary Format */
                name                    : "CONFIG_PROFILE_4",
                rtcFormat               : "BINARY",
                enCalAlarm1             : false,
                enCalAlarm1Min          : false,
                calAlarm1Min            : 1,
                enCalAlarm1Hour         : false,
                calAlarm1Hour           : 0,
                enCalAlarm1DOW          : false,
                calAlarm1DOW            : "0",
                enCalAlarm1DOM          : false,
                calAlarm1DOM            : 1,
                enCalAlarm2             : false,
                enCalAlarm2Min          : false,
                calAlarm2Min            : 1,
                enCalAlarm2Hour         : false,
                calAlarm2Hour           : 0,
                enCalAlarm2DOW          : false,
                calAlarm2DOW            : "0",
                enCalAlarm2DOM          : false,
                calAlarm2DOM            : 1,
                enIntervalAlarm         : false,
                intervalAlarmEvent      : "MINUTECHANGE",
                enPerAlarm0             : true,
                perAlarm0Divider        : "DIVIDE_32",
                enPerAlarm1             : false,
                perAlarm1Divider        : "DIVIDE_2",
                offsetCalFreq           : "32_KHZ",
                enabledInterrupts       :["PRESCALER0"],
                interruptPriority       : "DEFAULT",
                pubChanID: 0,
                enabledEvents: [],
            },
        ];
    }
    else {
        return [
            {
                /* Calendar Alarm 1 at 4:30 Saturday, 15th day, Binary Format */
                name                    : "CONFIG_PROFILE_1",
                rtcFormat               : "BINARY",
                enCalAlarm1             : true,
                enCalAlarm1Min          : true,
                calAlarm1Min            : 30,
                enCalAlarm1Hour         : true,
                calAlarm1Hour           : 4,
                enCalAlarm1DOW          : true,
                calAlarm1DOW            : "6",
                enCalAlarm1DOM          : true,
                calAlarm1DOM            : 15,
                enCalAlarm2             : false,
                enCalAlarm2Min          : false,
                calAlarm2Min            : 1,
                enCalAlarm2Hour         : false,
                calAlarm2Hour           : 0,
                enCalAlarm2DOW          : false,
                calAlarm2DOW            : "0",
                enCalAlarm2DOM          : false,
                calAlarm2DOM            : 1,
                enIntervalAlarm         : false,
                intervalAlarmEvent      : "MINUTECHANGE",
                enPerAlarm0             : false,
                perAlarm0Divider        : "DIVIDE_8",
                enPerAlarm1             : false,
                perAlarm1Divider        : "DIVIDE_2",
                offsetCalFreq           : "OFF",
                enabledInterrupts       :["CALENDAR_ALARM1"],
                interruptPriority       : "DEFAULT",
                pubChanID: 0,
                enabledEvents: [],
            },
            {
                /* Calendar Alarm 2 at 00:00 Tuesday, BCD Format */
                name                    : "CONFIG_PROFILE_2",
                rtcFormat               : "BCD",
                enCalAlarm1             : false,
                enCalAlarm1Min          : false,
                calAlarm1Min            : 1,
                enCalAlarm1Hour         : false,
                calAlarm1Hour           : 0,
                enCalAlarm1DOW          : false,
                calAlarm1DOW            : "0",
                enCalAlarm1DOM          : false,
                calAlarm1DOM            : 1,
                enCalAlarm2             : true,
                enCalAlarm2Min          : false,
                calAlarm2Min            : 0,
                enCalAlarm2Hour         : false,
                calAlarm2Hour           : 0,
                enCalAlarm2DOW          : true,
                calAlarm2DOW            : "2",
                enCalAlarm2DOM          : false,
                calAlarm2DOM            : 1,
                enIntervalAlarm         : false,
                intervalAlarmEvent      : "MINUTECHANGE",
                enPerAlarm0             : false,
                perAlarm0Divider        : "DIVIDE_8",
                enPerAlarm1             : false,
                perAlarm1Divider        : "DIVIDE_2",
                offsetCalFreq           : "OFF",
                enabledInterrupts       :["CALENDAR_ALARM2"],
                interruptPriority       : "DEFAULT",
                pubChanID: 0,
                enabledEvents: [],
            },
            {
                /* Interval Alarm at every minute change, BCD Format */
                name                    : "CONFIG_PROFILE_3",
                rtcFormat               : "BCD",
                enCalAlarm1             : false,
                enCalAlarm1Min          : false,
                calAlarm1Min            : 1,
                enCalAlarm1Hour         : false,
                calAlarm1Hour           : 0,
                enCalAlarm1DOW          : false,
                calAlarm1DOW            : "0",
                enCalAlarm1DOM          : false,
                calAlarm1DOM            : 1,
                enCalAlarm2             : false,
                enCalAlarm2Min          : false,
                calAlarm2Min            : 1,
                enCalAlarm2Hour         : false,
                calAlarm2Hour           : 0,
                enCalAlarm2DOW          : false,
                calAlarm2DOW            : "0",
                enCalAlarm2DOM          : false,
                calAlarm2DOM            : 1,
                enIntervalAlarm         : true,
                intervalAlarmEvent      : "MINUTECHANGE",
                enPerAlarm0             : false,
                perAlarm0Divider        : "DIVIDE_8",
                enPerAlarm1             : false,
                perAlarm1Divider        : "DIVIDE_2",
                offsetCalFreq           : "OFF",
                enabledInterrupts       :["INTERVAL_ALARM"],
                interruptPriority       : "DEFAULT",
                pubChanID: 0,
                enabledEvents: [],
            },
            {
                /* Periodic Alarm 0 at 1024 Hz, Binary Format */
                name                    : "CONFIG_PROFILE_4",
                rtcFormat               : "BINARY",
                enCalAlarm1             : false,
                enCalAlarm1Min          : false,
                calAlarm1Min            : 1,
                enCalAlarm1Hour         : false,
                calAlarm1Hour           : 0,
                enCalAlarm1DOW          : false,
                calAlarm1DOW            : "0",
                enCalAlarm1DOM          : false,
                calAlarm1DOM            : 1,
                enCalAlarm2             : false,
                enCalAlarm2Min          : false,
                calAlarm2Min            : 1,
                enCalAlarm2Hour         : false,
                calAlarm2Hour           : 0,
                enCalAlarm2DOW          : false,
                calAlarm2DOW            : "0",
                enCalAlarm2DOM          : false,
                calAlarm2DOM            : 1,
                enIntervalAlarm         : false,
                intervalAlarmEvent      : "MINUTECHANGE",
                enPerAlarm0             : true,
                perAlarm0Divider        : "DIVIDE_32",
                enPerAlarm1             : false,
                perAlarm1Divider        : "DIVIDE_2",
                offsetCalFreq           : "OFF",
                enabledInterrupts       :["PRESCALER0"],
                interruptPriority       : "DEFAULT",
                pubChanID: 0,
                enabledEvents: [],
            },
        ];
        }
}

function getPeriodicAlarmConfig(peripheral)
{
    let alarmConfig = []
    alarmConfig = alarmConfig.concat([
        {
            name        : "enPerAlarm0",
            displayName : "Enable Periodic Alarm 0",
            description : 'Enable the RTC Periodic Alarm 0',
            longDescription:`
    The Periodic Alarm 0 can be configured to generate a periodic interrupt at one of the following rates:
    * 4096 Hz
    * 2048 Hz
    * 1024 Hz
    * 512 Hz
    * 256 Hz
    * 128 Hz

    The Periodic Alarm 0 sources the Periodic Alarm 0 Interrupt.
            `,
            hidden      : false,
            default     : false,
            onChange    : onChangePerAlarm0,
        },
        {
            name        : "perAlarm0Divider",
            displayName : "Periodic Alarm 0 Event",
            description : 'Set alarm event for periodic alarm 0 divider',
            hidden      : true,
            default     : "DIVIDE_8",
            options     : [
                {name: "DIVIDE_8", displayName: "4096 Hz"},
                {name: "DIVIDE_16", displayName: "2048 Hz"},
                {name: "DIVIDE_32", displayName: "1024 Hz"},
                {name: "DIVIDE_64", displayName: "512 Hz"},
                {name: "DIVIDE_128", displayName: "256 Hz"},
                {name: "DIVIDE_256", displayName: "128 Hz"},
            ],
            onChange    : onChangeSetCustomProfile,
        },
        //  DL_RTC_setPeriodicAlarm1
        {
            name        : "enPerAlarm1",
            displayName : "Enable Periodic Alarm 1",
            description : 'Enable the RTC Periodic Alarm 1',
            longDescription:`
The Periodic Alarm 1 can be configured to generate a periodic interrupt at one of the following rates:
* 64 Hz
* 32 Hz
* 16 Hz
* 8 Hz
* 4 Hz
* 2 Hz
* 1 Hz
* 0.5 Hz

The Periodic Alarm 1 sources the Periodic Alarm 1 Interrupt.
            `,
            hidden      : false,
            default     : false,
            onChange    : onChangePerAlarm1,
        },
        {
            name        : "perAlarm1Divider",
            displayName : "Periodic Alarm 1 Event",
            description : 'Set the alarm event for the periodic alarm 1 divider',
            hidden      : true,
            default     : "DIVIDE_2",
            options     : [
                {name: "DIVIDE_2", displayName: "64 Hz"},
                {name: "DIVIDE_4", displayName: "32 Hz"},
                {name: "DIVIDE_8", displayName: "16 Hz"},
                {name: "DIVIDE_16", displayName: "8 Hz"},
                {name: "DIVIDE_32", displayName: "4 Hz"},
                {name: "DIVIDE_64", displayName: "2 Hz"},
                {name: "DIVIDE_128", displayName: "1 Hz"},
                {name: "DIVIDE_256", displayName: "0.5 Hz"},
            ],
            onChange    : onChangeSetCustomProfile,
        }
    ])

    if(peripheral == "RTC_A") {
        alarmConfig = alarmConfig.concat( [
            {
                name        : "enPerAlarm2",
                displayName : "Enable Periodic Alarm 2",
                description : 'Enable the RTC Periodic Alarm 2',
                longDescription:`
The Periodic Alarm 2 can be configured to generate a periodic interrupt at one of the following rates:
* 4 s (0.25 Hz)
* 8 s (0.125 Hz)
* 16 s (0.0625 Hz)

The Periodic Alarm 2 sources the Periodic Alarm 2 Interrupt.
                `,
                hidden      : false,
                default     : false,
                onChange    : onChangePerAlarm2,
            },
            {
                name        : "perAlarm2Divider",
                displayName : "Periodic Alarm 2 Event",
                description : 'Set the alarm event for the periodic alarm 2 divider',
                hidden      : true,
                default     : "4_SEC",
                options     : [
                    {name: "4_SEC", displayName: "4 Seconds (0.25 Hz)"},
                    {name: "8_SEC", displayName: "8 Seconds (0.125 Hz)"},
                    {name: "16_SEC", displayName: "16 Seconds (0.0625 Hz)"},
                ],
                onChange    : onChangeSetCustomProfile,
            },
        ])
    }

    return alarmConfig;
}

function getAdvancedConfig(peripheral)
{
    let advancedConfig = []
    if(peripheral == "RTC_A") {
        advancedConfig = advancedConfig.concat([
        {
            name        : "offsetCalFreq",
            displayName : "Offset Error Calibration Frequency",
            description : 'Sets the output frequency for offset calibration',
            hidden      : false,
            default     : "32_KHZ",
            options     : [
                {name: "32_KHZ", displayName: "LFCLK (32 kHz) output"},
                {name: "512", displayName: "512 Hz frequency output"},
                {name: "256", displayName: "256 Hz frequency output"},
                {name: "1", displayName: "1 Hz frequency output"},
            ],
        },
        {
            name        : "enableWriteProtect",
            displayName : "Enable Write Protect",
            description : "The RTC lock bit protects the CLKCTL, SEC, MIN, HOUR, DAY, MON, YEAR and LFSSRST registers from accidental updates.",
            hidden      : false,
            default     : false,
        },
        {
            name        : "timeStampEvents",
            displayName : "Time Stamp Event Sources",
            description : 'Sets the sources for a time stamp event',
            hidden      : false,
            default     : [],
            minSelections: 0,
            options     : getTimeStampEventOptions,
        },
        {
            name        : "tsCaptureMethod",
            displayName : "Time Stamp Capture Method",
            description : "Defines the capture method of the RTC timestamp",
            longDescription:
            `The capture method can be set to hold the first or last occurrence of a time stamp event.
            `,
            hidden      : false,
            default     : "TIME_STAMP_EVENT_CAPTURE_FIRST",
            options     : [
                {name: "TIME_STAMP_EVENT_CAPTURE_FIRST", displayName: "Holds First Occurrence"},
                {name: "TIME_STAMP_EVENT_CAPTURE_LAST", displayName: "Holds Last Occurrence"},
            ],
        },
        ])
    }
    if(peripheral == "RTC") {
        advancedConfig = advancedConfig.concat([
        {
            name        : "offsetCalFreq",
            displayName : "Offset Error Calibration Frequency",
            description : 'Sets the output frequency for offset calibration',
            hidden      : false,
            default     : "OFF",
            options     : [
                {name: "OFF", displayName: "Frequency output off"},
                {name: "512", displayName: "512 Hz frequency output"},
                {name: "256", displayName: "256 Hz frequency output"},
                {name: "1", displayName: "1 Hz frequency output"},
            ],
        }
        ])
    }
    return advancedConfig;
}

function getEventConfigs(peripheral) {
    let eventConfig = [];
    if(peripheral == "RTC_A") {
        eventConfig = eventConfig.concat([
        {
            name        : "pubChanID",
            displayName : "Event Publisher Channel ID",
            description : 'Sets the event publisher channel id',
            hidden      : false,
            default: 0,
            options: EVENT.getPublisherOptions,
            getDisabledOptions: EVENT.getPublisherDisabledOptions,
            onChange    : onChangeSetCustomProfile,
        },
        {
            name        : "enabledEvents",
            displayName : "Enable Events",
            description : 'Enable RTC event',
            hidden      : false,
            default     : [],
            minSelections: 0,
            options     : getEventOptions(peripheral),
            onChange    : onChangeSetCustomProfile,
        },
        {
            name: "eventInfo",
            description: "information about configured events that's passed on to the EVENT module",
            default: [""],
            hidden: true,
            options: (inst) => {
                let options = [{name: ""}]
                if(inst.pubChanID != 0){
                    options.push({name: inst.pubChanID.toString() + "pub"});
                }
                return options;
            },
            getValue: (inst) => {
                let result = [];
                if(inst.pubChanID != 0){
                    result.push(inst.pubChanID.toString() + "pub");
                }
                if(result.length == 0){
                    result = [""];
                }
                return result;
            }
        }])
    }
    else if(peripheral == "RTC") {
        eventConfig = eventConfig.concat([
            {
                name        : "pubChanID",
                displayName : "Event Publisher Channel ID",
                description : 'Sets the event publisher channel id',
                hidden      : false,
                default: 0,
                options: EVENT.getPublisherOptions,
                getDisabledOptions: EVENT.getPublisherDisabledOptions,
                onChange    : onChangeSetCustomProfile,
            },
            {
                name        : "enabledEvents",
                displayName : "Enable Events",
                description : 'Enable RTC event',
                hidden      : false,
                default     : [],
                minSelections: 0,
                options     : getEventOptions(peripheral),
                onChange    : onChangeSetCustomProfile,
            },
            {
                name: "eventInfo",
                description: "information about configured events that's passed on to the EVENT module",
                default: [""],
                hidden: true,
                options: (inst) => {
                    let options = [{name: ""}]
                    if(inst.pubChanID != 0){
                        options.push({name: inst.pubChanID.toString() + "pub"});
                    }
                    return options;
                },
                getValue: (inst) => {
                    let result = [];
                    if(inst.pubChanID != 0){
                        result.push(inst.pubChanID.toString() + "pub");
                    }
                    if(result.length == 0){
                        result = [""];
                    }
                    return result;
                }
            }])
    }
    return eventConfig;
}

function getBasicConfig(inst, ui, peripheral){
    return [
        {
            name: "GROUP_BASIC",
            displayName: "Calendar Configuration",
            description: "",
            longDescription:
    `Basic RTC options allow configuration of the real-time calendar mode providing seconds, minutes, hours, day of week, day of month, and year.
    `,
            collapsed: false,
            config: [
                // DL_RTC_setClockFormat
                {
                    name        : "rtcFormat",
                    displayName : "RTC Format",
                    description : 'Set the RTC format',
                    longDescription:`
    The RTC provides seconds, minutes, hours, day of week, day of month, month, and year in selectable binary or
    binary-coded decimal (BCD) format.
            `,
                    hidden      : false,
                    default     : "BINARY",
                    options     : [
                        {name: "BINARY", displayName: "Binary"},
                        {name: "BCD", displayName: "BCD"},
                    ],
                    onChange    : onChangeFormat,
                },
                {
                    name        : "rtcBaseCalDate",
                    displayName : "RTC Calendar Date",
                    description : 'The current calendar date in format of HH:MM:SS MONTH DAYOFMONTH, DAYOFWEEK, YEAR',
                    hidden      : false,
                    default     : "00:00:00 January 1, Sunday, 2022",
                    getValue    : (inst) => getBaseCalendarDate(inst),
                },
                // DL_RTC_initCalendar
                {
                    name        : "calSec",
                    displayName : "Calendar Seconds",
                    description : 'Set the value for seconds',
                    hidden      : false,
                    default     : 0,
                    isInteger   : true,
                    range       : [0, 59],
                },
                {
                    name        : "calMin",
                    displayName : "Calendar Minutes",
                    description : 'Set the value for minutes',
                    hidden      : false,
                    default     : 0,
                    isInteger   : true,
                    range       : [0, 59],
                },
                {
                    name        : "calHour",
                    displayName : "Calendar Hours",
                    description : 'Set the value for hours',
                    hidden      : false,
                    default     : 0,
                    isInteger   : true,
                    range       : [0, 23],
                },
                {
                    name        : "calDOW",
                    displayName : "Calendar Day Of Week",
                    description : 'Set the value for the day of the week',
                    hidden      : false,
                    default     : "0",
                    options     : [
                        {name: "0", displayName: "Sunday"},
                        {name: "1", displayName: "Monday"},
                        {name: "2", displayName: "Tuesday"},
                        {name: "3", displayName: "Wednesday"},
                        {name: "4", displayName: "Thursday"},
                        {name: "5", displayName: "Friday"},
                        {name: "6", displayName: "Saturday"},
                    ],
                },
                {
                    name        : "calDOM",
                    displayName : "Calendar Day Of Month",
                    description : 'Set the value for the day of the month',
                    hidden      : false,
                    default     : 1,
                    isInteger   : true,
                },
                {
                    name        : "calMonth",
                    displayName : "Calendar Month",
                    description : 'Set the value for the month',
                    hidden      : false,
                    default     : "1",
                    options     : [
                        {name: "1", displayName: "January"},
                        {name: "2", displayName: "February "},
                        {name: "3", displayName: "March"},
                        {name: "4", displayName: "April"},
                        {name: "5", displayName: "May"},
                        {name: "6", displayName: "June"},
                        {name: "7", displayName: "July"},
                        {name: "8", displayName: "August"},
                        {name: "9", displayName: "September"},
                        {name: "10", displayName: "October"},
                        {name: "11", displayName: "November"},
                        {name: "12", displayName: "December"},
                    ],
                },
                {
                    name        : "calYear",
                    displayName : "Calendar Year",
                    description : 'Set the value for the year',
                    hidden      : false,
                    default     : 2022,
                    isInteger   : true,
                    range       : [0, 4095],
                },
            ]
        },
        {
            name: "GROUP_ALARMS",
            displayName: "Alarm Configuration",
            longDescription: `
    The RTC offers a selection of programmable interrupt alarms:\n
    * **Two Calendar Alarms**, that interrupts based on minute, hour, day of week, and day of month
    * **Interval Alarm**, to wake every minute, every hour, at midnight, and/or at noon
    * **Periodic Alarm 0**, that can interrupt at 4096, 2048, 1024, 512, 256, or 128 Hz
    * **Periodic Alarm 1**, that can interrupt at 64, 32, 16, 8, 4, 2, 1, and 0.5 Hz
    `,
            collapsed: true,
            config: [
            {
                 name: "GROUP_CAL_ALARM_1",
                displayName: "Calendar Alarm 1 Configuration",
                longDescription: `
    The RTC provides a flexible alarm system. There are two user-programmable alarms which can enable and configure individual alarm events for the following:
    * Minutes
    * Hours
    * Day of Week
    * Day of Month

    This configuaration will configure Calendar Alarm 1.\n
    The Calendar Alarm 1 sources the Calendar Alarm 1 Interrupt.
                `,
                collapsed: true,
                config: [
                    {
                        name        : "enCalAlarm1",
                        displayName : "Configure Calendar Alarm 1",
                        description : 'Enable configuration of the RTC Calendar Alarm 1',
                        longDescription:`
    The RTC provides a flexible alarm system. There are two user-programmable alarms which can be
    programmed based on the settings contained in the alarm registers for minutes, hours, day of week, and day of
    month.\n
    This configuaration will configure Calendar Alarm 1.\n
    The Calendar Alarm 1 sources the Calendar Alarm 1 Interrupt.
                `,
                        hidden      : false,
                        default     : false,
                        onChange    : onChangeCalAlarm1,
                    },
                {
                    name        : "rtcCalAlarm1Date",
                    displayName : "Calendar Alarm 1 Events",
                    description : 'List of the current configured events for Calendar Alarm 1',
                    hidden      : true,
                    default     : "No alarm events enabled",
                    getValue    : (inst) => {return getCalAlarm1Date(inst)}
                },
                    //  DL_RTC_setCalendarAlarm1
                    {
                        name        : "enCalAlarm1Min",
                        displayName : "Enable Alarm 1 Minutes",
                        description : 'Enable the RTC Calendar Alarm 1 Minutes',
                        longDescription:`
     Enable setting a Calendar Alarm 1 event on a specified minute.\n
     For example, to set an alarm every hour at 15 minutes past the hour (00:15:00, 01:15:00, etc.), set the value of Calendar Alarm 1 Minutes to 15.\n
     When the Calendar Alarm 1 interrupt is enabled, the interrupt will then be triggered when the count transitions from 00:14:59 to 00:15:00, 01:14:59 to 01:15:00, etc.
                `,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeCalAlarm1Min,
                    },
                    {
                        name        : "calAlarm1Min",
                        displayName : "Alarm 1 Minutes",
                        description : 'Set the value for minutes',
                        hidden      : true,
                        default     : 0,
                        isInteger   : true,
                        range       : [0, 59],
                        onChange    : onChangeSetCustomProfile,
                    },
                    {
                        name        : "enCalAlarm1Hour",
                        displayName : "Enable Alarm 1 Hour",
                        description : 'Enable the RTC Calendar Alarm 1 Hour',
                        longDescription:`
     Enable setting a Calendar Alarm 1 event on a specified hour.\n
     For example, to set an alarm every day at 04:00:00, set the value of Calendar Alarm 1 Hour to 4.
     When the Calendar Alarm 1 interrupt is enabled, the interrupt will then be triggered when the count transitions from 00:03:59 to 00:04:00
                `,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeCalAlarm1Hour,
                    },
                    {
                        name        : "calAlarm1Hour",
                        displayName : "Alarm 1 Hours",
                        description : 'Set the value for hours',
                        hidden      : true,
                        default     : 0,
                        isInteger   : true,
                        range       : [0, 23],
                        onChange    : onChangeSetCustomProfile,
                    },
                    {
                        name        : "enCalAlarm1DOW",
                        displayName : "Enable Alarm 1 Day Of The Week",
                        description : 'Enable the RTC Calendar Alarm 1 Day of the Week',
                        longDescription:`
     Enable setting a Calendar Alarm 1 event on a specified day of the week.\n
     For example, to set an alarm every Tuesday at 06:30:00, set the value of the Calendar Alarm 1 Day of the Week to Tuesday, and then set the Alarm 1 Hour to 6 and the Alarm 1 Minutes to 30.
     When the Calendar Alarm 1 interrupt is enabled, the interrupt will then be triggered when the Day of the Week transitions from Monday to Tuesday, and the time count transitions from 06:29:59 to 06:30:00.
                `,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeCalAlarm1DOW,
                    },
                    {
                        name        : "calAlarm1DOW",
                        displayName : "Alarm 1 Day Of Week",
                        description : 'Set the value for the day of the week',
                        hidden      : true,
                        default     : "0",
                        options     : [
                            {name: "0", displayName: "Sunday"},
                            {name: "1", displayName: "Monday"},
                            {name: "2", displayName: "Tuesday"},
                            {name: "3", displayName: "Wednesday"},
                            {name: "4", displayName: "Thursday"},
                            {name: "5", displayName: "Friday"},
                            {name: "6", displayName: "Saturday"},
                        ],
                        onChange    : onChangeSetCustomProfile,
                    },
                    {
                        name        : "enCalAlarm1DOM",
                        displayName : "Enable Alarm 1 Day Of The Month",
                        description : 'Enable the RTC Calendar Alarm 1 Day of the Month',
                        longDescription:`
     Enable setting a Calendar Alarm 1 event on a specified day of the month.\n
     For example, to set an alarm on the fifth day of each month at 06:30:00, set the value of the Calendar Alarm 1 Day of the Month to 5, and then set the Alarm 1 Hour to 6 and the Alarm 1 Minutes to 30.
     When the Calendar Alarm 1 interrupt is enabled, the interrupt will then be triggered when the Day of the Month transitions from 4 to 5, and the time count transitions from 06:29:59 to 06:30:00.
                `,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeCalAlarm1DOM,
                    },
                    {
                        name        : "calAlarm1DOM",
                        displayName : "Alarm 1 Day Of Month",
                        description : 'Set the value for the day of the month',
                        hidden      : true,
                        default     : 1,
                        isInteger   : true,
                        onChange    : onChangeSetCustomProfile,
                    },
            ],
        },
            {
                 name: "GROUP_CAL_ALARM_2",
                displayName: "Calendar Alarm 2 Configuration",
                longDescription: `
    The RTC provides a flexible alarm system. There are two user-programmable alarms which can enable and configure individual alarm events for the following:
    * Minutes
    * Hours
    * Day of Week
    * Day of Month

    This configuaration will configure Calendar Alarm 2.\n
    The Calendar Alarm 2 sources the Calendar Alarm 2 Interrupt.
                `,
                collapsed: true,
                config: [
                    {
                        name        : "enCalAlarm2",
                        displayName : "Configure Calendar Alarm 2",
                        description : 'Enable configuration of the RTC Calendar Alarm 2',
                        longDescription:`
    The RTC provides a flexible alarm system. There are two user-programmable alarms which can be
    programmed based on the settings contained in the alarm registers for minutes, hours, day of week, and day of
    month.\n
    This configuaration will configure Calendar Alarm 2.\n
    The Calendar Alarm 2 sources the Calendar Alarm 2 Interrupt.
                `,
                        hidden      : false,
                        default     : false,
                        onChange    : onChangeCalAlarm2,
                    },
                {
                    name        : "rtcCalAlarm2Date",
                    displayName : "Calendar Alarm 2 Events",
                    description : 'List of the current configured events for Calendar Alarm 2',
                    hidden      : true,
                    default     : "No alarm events enabled",
                    getValue    : (inst) => {return getCalAlarm2Date(inst)}
                },
                    //  DL_RTC_setCalendarAlarm2
                    {
                        name        : "enCalAlarm2Min",
                        displayName : "Enable Alarm 2 Minutes",
                        description : 'Enable the RTC Calendar Alarm 2 Minutes',
                        longDescription:`
     Enable setting a Calendar Alarm 2 event on a specified minute.\n
     For example, to set an alarm every hour at 15 minutes past the hour (00:15:00, 01:15:00, etc.), set the value of Calendar Alarm 2 Minutes to 15.\n
     When the Calendar Alarm 2 interrupt is enabled, the interrupt will then be triggered when the count transitions from 00:14:59 to 00:15:00, 01:14:59 to 01:15:00, etc.
                `,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeCalAlarm2Min,
                    },
                    {
                        name        : "calAlarm2Min",
                        displayName : "Alarm 2 Minutes",
                        description : 'Set the value for minutes',
                        hidden      : true,
                        default     : 0,
                        isInteger   : true,
                        range       : [0, 59],
                        onChange    : onChangeSetCustomProfile,
                    },
                    {
                        name        : "enCalAlarm2Hour",
                        displayName : "Enable Alarm 2 Hour",
                        description : 'Enable the RTC Calendar Alarm 2 Hour',
                        longDescription:`
     Enable setting a Calendar Alarm 2 event on a specified hour.\n
     For example, to set an alarm every day at 04:00:00, set the value of Calendar Alarm 2 Hour to 4.
     When the Calendar Alarm 2 interrupt is enabled, the interrupt will then be triggered when the count transitions from 00:03:59 to 00:04:00
                `,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeCalAlarm2Hour,
                    },
                    {
                        name        : "calAlarm2Hour",
                        displayName : "Alarm 2 Hours",
                        description : 'Set the value for hours',
                        hidden      : true,
                        default     : 0,
                        isInteger   : true,
                        range       : [0, 23],
                        onChange    : onChangeSetCustomProfile,
                    },
                    {
                        name        : "enCalAlarm2DOW",
                        displayName : "Enable Alarm 2 Day Of The Week",
                        description : 'Enable the RTC Calendar Alarm 2 Day Of The Week',
                        longDescription:`
     Enable setting a Calendar Alarm 2 event on a specified day of the week.\n
     For example, to set an alarm every Tuesday at 06:30:00, set the value of the Calendar Alarm 2 Day of the Week to Tuesday, and then set the Alarm 2 Hour to 6 and the Alarm 2 Minutes to 30.
     When the Calendar Alarm 2 interrupt is enabled, the interrupt will then be triggered when the Day of the Week transitions from Monday to Tuesday, and the time count transitions from 06:29:59 to 06:30:00.
                `,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeCalAlarm2DOW,
                    },
                    {
                        name        : "calAlarm2DOW",
                        displayName : "Alarm 2 Day Of Week",
                        description : 'Set the value for the day of the week',
                        hidden      : true,
                        default     : "0",
                        options     : [
                            {name: "0", displayName: "Sunday"},
                            {name: "1", displayName: "Monday"},
                            {name: "2", displayName: "Tuesday"},
                            {name: "3", displayName: "Wednesday"},
                            {name: "4", displayName: "Thursday"},
                            {name: "5", displayName: "Friday"},
                            {name: "6", displayName: "Saturday"},
                        ],
                        onChange    : onChangeSetCustomProfile,
                    },
                    {
                        name        : "enCalAlarm2DOM",
                        displayName : "Enable Alarm 2 Day Of The Month",
                        description : 'Enable the RTC Calendar Alarm 2 Day of the Month',
                        longDescription:`
     Enable setting a Calendar Alarm 2 event on a specified day of the month.\n
     For example, to set an alarm on the fifth day of each month at 06:30:00, set the value of the Calendar Alarm 2 Day of the Month to 5, and then set the Alarm 2 Hour to 6 and the Alarm 2 Minutes to 30.
     When the Calendar Alarm 2 interrupt is enabled, the interrupt will then be triggered when the Day of the Month transitions from 4 to 5, and the time count transitions from 06:29:59 to 06:30:00.
                `,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeCalAlarm2DOM,
                    },
                    {
                        name        : "calAlarm2DOM",
                        displayName : "Alarm 2 Day Of Month",
                        description : 'Set the value for the day of the month',
                        hidden      : true,
                        default     : 1,
                        isInteger   : true,
                        onChange    : onChangeSetCustomProfile,
                    },
            ],
        },
            {
                 name: "GROUP_INTERVAL_ALARM",
                displayName: "Interval Alarm Configuration",
                longDescription: `
    The interval alarm and can be configured to generate an interval alarm event when the following events occur:
    * Every minute
    * Every hour
    * Every day at midnight
    * Every day at noon

    The Interval Alarm sources the Interval Alarm Interrupt.
                `,
                collapsed: true,
                config: [
                //  DL_RTC_setInteralAlarm
                {
                    name        : "enIntervalAlarm",
                    displayName : "Enable Interval Alarm",
                    description : 'Enable the RTC Interval Alarm',
                    longDescription:`
    The interval alarm is provided in addition to the two calendar alarms, and can be configured to generate an
    interval alarm event.

    The Interval Alarm sources the Interval Alarm Interrupt.
                    `,
                    hidden      : false,
                    default     : false,
                    onChange    : onChangeIntervalAlarm,
                },
                {
                    name        : "intervalAlarmEvent",
                    displayName : "Interval Alarm Event",
                    description : 'Set the triggers for the interval alarm event',
                    longDescription:`
    The interval alarm and can be configured to generate an interval alarm event when the following events occur:
    * Every minute
    * Every hour
    * Every day at midnight
    * Every day at noon
                    `,
                    hidden      : true,
                    default     : "MINUTECHANGE",
                    options     : [
                        {name: "MINUTECHANGE", displayName: "Every minute"},
                        {name: "HOURCHANGE", displayName: "Every hour"},
                        {name: "NOON", displayName: "Noon (Hour is 12)"},
                        {name: "MIDNIGHT", displayName: "Midnight (Hour is 0)"},
                    ],
                    onChange    : onChangeSetCustomProfile,
                },
            ],
        },
        {
                 name: "GROUP_PERIODIC_ALARM",
                displayName: "Periodic Alarm Configuration",
                longDescription: `
    Two prescale dividers, RT0PS and RT1PS, can be configured to generate two periodic alarms.\n
    The Prescale 0 Divider (RT0PS) is sourced directly from LFCLK at 32 kHz. The output of the RT0PS divider block is 32 kHz/256, or 128 Hz, and
    is used to source the input of the RT1PS divider block.\n
                `,
                collapsed: true,
                config: getPeriodicAlarmConfig(peripheral)
        },
    ],
    },
        {
            name: "GROUP_ADVANCED",
            displayName: "Advanced Configuration",
            longDescription: ``,
            collapsed: true,
            config: getAdvancedConfig(peripheral)
        },
        {
            name: "GROUP_INTERRUPTS",
            displayName: "Interrupt Configuration",
            longDescription: "This section allows enabling/disabling RTC interrupts",
            collapsed: true,
            config: [
                /* DL_RTC_enableInterrupt */
                {
                    name        : "enabledInterrupts",
                    displayName : "Enable Interrupts",
                    description : 'Enable RTC interrupt',
                    default     : [],
                    minSelections : 0,
                    options     : getIntOptions(peripheral),
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
        {
            name: "eventConfig",
            displayName: "Event Configuration",
            longDescription: `Specifies the RTC Events that are to trigger an Event Condition and where the events are to be published`,
            collapsed: true,
            config: getEventConfigs(peripheral)
        },
    ]
}


/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function getValidation(inst, validation)
{
    // Common.validateNames(inst, validation);

    if(inst.enCalAlarm1 && !(inst.enabledInterrupts.includes("CALENDAR_ALARM1"))){
        validation.logInfo(
            "Calendar Alarm 1 will not trigger an interrupt until the Calendar Alarm 1 Interrupt is enabled in the Interrupt Configuration section.",
            inst, ["enCalAlarm1"]
        );
    }
    if(inst.enCalAlarm2 && !(inst.enabledInterrupts.includes("CALENDAR_ALARM2"))){
        validation.logInfo(
            "Calendar Alarm 2 will not trigger an interrupt until the Calendar Alarm 2 Interrupt is enabled in the Interrupt Configuration section.",
            inst, ["enCalAlarm2"]
        );
    }
    if(inst.enIntervalAlarm && !(inst.enabledInterrupts.includes("INTERVAL_ALARM"))){
        validation.logInfo(
            "Interval Alarm will not trigger an interrupt until the Interval Alarm Interrupt is enabled in the Interrupt Configuration section.",
            inst, ["enIntervalAlarm"]
        );
    }
    if(inst.enPerAlarm0 && !(inst.enabledInterrupts.includes("PRESCALER0"))){
        validation.logInfo(
            "Periodic Alarm 0 will not trigger an interrupt until the Prescaler Alarm 0 Interrupt is enabled in the Interrupt Configuration section.",
            inst, ["enPerAlarm0"]
        );
    }
   if(inst.enPerAlarm1 && !(inst.enabledInterrupts.includes("PRESCALER1"))){
        validation.logInfo(
            "Periodic Alarm 1 will not trigger an interrupt until the Prescaler Alarm 1 Interrupt is enabled in the Interrupt Configuration section.",
            inst, ["enPerAlarm1"]
        );
    }

    if (inst.calDOM < 1) {
        validation.logError(
            "An invalid date has been entered for the selected month.",
            inst, ["calDOM"]
        );
    }

    if (inst.calAlarm1DOM < 1) {
        validation.logError(
            "An invalid date has been entered for the selected month.",
            inst, ["calAlarm1DOM"]
        );
    }

    if (inst.calAlarm2DOM < 1) {
        validation.logError(
            "An invalid date has been entered for the selected month.",
            inst, ["calAlarm2DOM"]
        );
    }

    switch(inst.calMonth){
        case "1":
        case "3":
        case "5":
        case "7":
        case "8":
        case "10":
        case "12":
            if (inst.calDOM > 31) {
                validation.logError(
                    "An invalid date has been entered for the selected month.",
                    inst, ["calDOM"]
                );
            }
            break;
        case "4":
        case "6":
        case "9":
        case "11":
            if (inst.calDOM > 30) {
                validation.logError(
                    "An invalid date has been entered for the selected month.",
                    inst, ["calDOM"]
                );
            }
            break;
        case "2":
            if ((inst.calDOM > 28 && inst.calYear % 4 != 0) || (inst.calDOM > 29 && inst.calYear % 4 == 0)) {
                validation.logError(
                    "An invalid date has been entered for the selected month.",
                    inst, ["calDOM"]
                );
            }

        default:
            break
    }

    if (inst.enCalAlarm1 && inst.enCalAlarm1DOM) {
        switch(inst.calMonth){
            case "1":
            case "3":
            case "5":
            case "7":
            case "8":
            case "10":
            case "12":
                if (inst.calAlarm1DOM > 31) {
                    validation.logError(
                        "An invalid date has been entered for the selected month.",
                        inst, ["calAlarm1DOM"]
                    );
                }
                break;
            case "4":
            case "6":
            case "9":
            case "11":
                if (inst.calAlarm1DOM > 30) {
                    validation.logError(
                        "An invalid date has been entered for the selected month.",
                        inst, ["calAlarm1DOM"]
                    );
                }
                break;
            case "2":
                if ((inst.calAlarm1DOM > 28 && inst.calYear % 4 != 0) || (inst.calAlarm1DOM > 29 && inst.calYear % 4 == 0)) {
                    validation.logError(
                        "An invalid date has been entered for the selected month.",
                        inst, ["calAlarm1DOM"]
                    );
                }

            default:
                break
        }
    }

    if (inst.enCalAlarm2 && inst.enCalAlarm2DOM) {
        switch(inst.calMonth){
            case "1":
            case "3":
            case "5":
            case "7":
            case "8":
            case "10":
            case "12":
                if (inst.calAlarm2DOM > 31) {
                    validation.logError(
                        "An invalid date has been entered for the selected month.",
                        inst, ["calAlarm2DOM"]
                    );
                }
                break;
            case "4":
            case "6":
            case "9":
            case "11":
                if (inst.calAlarm2DOM > 30) {
                    validation.logError(
                        "An invalid date has been entered for the selected month.",
                        inst, ["calAlarm2DOM"]
                    );
                }
                break;
            case "2":
                if ((inst.calAlarm2DOM > 28 && inst.calYear % 4 != 0) || (inst.calAlarm2DOM > 29 && inst.calYear % 4 == 0)) {
                    validation.logError(
                        "An invalid date has been entered for the selected month.",
                        inst, ["calAlarm2DOM"]
                    );
                }

            default:
                break
        }
    }

    /* Validate Event selection for case of switching devices.
     * Checks that selected event is withing the valid options
     * for current device.
     */
    EVENT.validatePublisherOptions(inst,validation,"pubChanID");

    /* Validate Tamper I/O pins are enabled as input before setting up time stamp sources */

}

function setRequiredModules(inst){
    let theModules = ["Board", "SYSCTL"]

    let kwargs = theModules;
    let modArray = [];

    for (let args = kwargs.length - 1; args >= 0; args--) {
        let modPath = kwargs[args];
        if (modPath.indexOf('/') == -1) {
            modPath = "/ti/driverlib/" + modPath;
        }
        modArray.push({
            name      : modPath.substring(modPath.lastIndexOf('/') + 1),
            moduleName: modPath,
            hidden    : true
        });
    }

    return modArray
};
