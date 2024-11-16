/*
 * Copyright (c) 2023-2024 Texas Instruments Incorporated - http://www.ti.com
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
let Common = system.getScript("/ti/driverlib/Common.js");
let BoardFamily = Common.getDeviceFamily();

exports = {
    getRTCCalenderC : getRTCCalenderC,
    getRTCCalenderAlarm1 : getRTCCalenderAlarm1,
    getRTCCalenderAlarm2 : getRTCCalenderAlarm2,
    getRTCSyscfgInit   : getRTCSyscfgInit,
}

function getRTCCalenderC(stat, peripheral) {
    let calendarString = "";
    let daysOfTheWeek = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    /* Get calendar day of the week */
    let calDOWString = daysOfTheWeek[stat.calDOW];
    /* Get calendar month */
    let months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
    let calMonthString = months[(stat.calMonth - 1)];
    if(stat.rtcFormat == "BINARY"){
    /* RTC Calendar Config */
        calendarString += "static const DL_";
        calendarString += peripheral + "_Calendar gRTCCalendarConfig = {" +
        "\n\t\t.seconds    = " +  stat.calSec + ",   /* Seconds = " + stat.calSec  + " */" +
        "\n\t\t.minutes    = " +  stat.calMin + ",   /* Minute = " + stat.calMin + " */" +
        "\n\t\t.hours      = " +  stat.calHour + ",   /* Hour = " + stat.calHour + " */" +
        "\n\t\t.dayOfWeek  = " +  stat.calDOW + ",    /* Day of week = " + stat.calDOW + " (" +  calDOWString + ") */" +
        "\n\t\t.dayOfMonth = " +  stat.calDOM + ",    /* Day of month = " + stat.calDOM + "*/" +
        "\n\t\t.month      = " +  stat.calMonth + ",    /* Month = " + stat.calMonth + " (" + calMonthString + ") */" +
        "\n\t\t.year       = " +  stat.calYear + ", /* Year = " + stat.calYear + " */" +
        "\n};";
    }
    else if(stat.rtcFormat == "BCD"){
        calendarString += "static const DL_";
        calendarString += peripheral + "_Calendar gRTCCalendarConfig = {" +
        "\n\t\t.seconds    =" + "0x"+stat.calSec+ ",   /* Seconds = " + stat.calSec + " */" +
        "\n\t\t.minutes    =" + "0x"+stat.calMin+ ",   /* Minute = " + stat.calMin + " */" +
        "\n\t\t.hours      =" + "0x"+stat.calHour+ ",   /* Hour = " + stat.calHour + " */" +
        "\n\t\t.dayOfWeek  =" + "0x"+stat.calDOW+ ",    /* Day of week = " + stat.calDOW +  " (" + calDOWString + ") */" +
        "\n\t\t.dayOfMonth =" + "0x"+stat.calDOM+ ",    /* Day of month = " + stat.calDOM + " */" +
        "\n\t\t.month      =" + "0x"+stat.calMonth+ ",    /* Month = " + stat.calMonth + " (" + calMonthString  + ") */" +
        "\n\t\t.year       =" + "0x"+stat.calYear+ ", /* Year = " + stat.calYear + " */" +
        "\n};";
    }
    return calendarString;
}

function getRTCCalenderAlarm1(stat, peripheral) {
    let calendarString = "";
    let daysOfTheWeek = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    /* Get calendar day of the week */
    let calDOWString = daysOfTheWeek[stat.calDOW];
    /* Get calendar month */
    let months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
    let calMonthString = months[(stat.calMonth - 1)];
    let alarmString = "";
    //%if(stat.rtcFormat == "BCD")
    /* Get calendar alarm 1 day of the week */
    let calAlarm1DOWString = daysOfTheWeek[stat.calAlarm1DOW];
    if(stat.enCalAlarm1 && (stat.enCalAlarm1Min || stat.enCalAlarm1Hour || stat.enCalAlarm1DOW || stat.enCalAlarm1DOM)) {
        if(stat.rtcFormat == "BINARY"){
            alarmString += "static const DL_";
            alarmString += peripheral + "_CalendarAlarm gRTCAlarm1Config = {";
            if(stat.enCalAlarm1Min) {
                alarmString += "\n\t\t.minutes    = " + stat.calAlarm1Min + ", /* Minute = " + stat.calAlarm1Min + " */";
            }
            if(stat.enCalAlarm1Hour) {
                alarmString += "\n\t\t.hours      = " + stat.calAlarm1Hour + ", /* Hour = " + stat.calAlarm1Hour + " */";
            }
            if(stat.enCalAlarm1DOW) {
                alarmString += "\n\t\t.dayOfWeek  = " + stat.calAlarm1DOW + ",  /* Day of week = " + stat.calAlarm1DOW +  " (" + calAlarm1DOWString + ") */";
            }
            if(stat.enCalAlarm1DOM) {
                alarmString += "\n\t\t.dayOfMonth = " + stat.calAlarm1DOM + ",  /* Day of month = " + stat.calAlarm1DOM + " */";
            }
            alarmString += "\n};";
        }
        else if(stat.rtcFormat == "BCD"){
            alarmString += "static const DL_";
            alarmString += peripheral + "_CalendarAlarm gRTCAlarm1Config = {";
            if(stat.enCalAlarm1Min) {
                alarmString += "\n\t\t.minutes    = " + "0x"+stat.calAlarm1Min+ ", /* Minute = " + stat.calAlarm1Min + " */";
            }
            if(stat.enCalAlarm1Hour) {
                alarmString += "\n\t\t.hours      = " + "0x"+stat.calAlarm1Hour+ ", /* Hour = " + stat.calAlarm1Hour + " */";
            }
            if(stat.enCalAlarm1DOW) {
                alarmString += "\n\t\t.dayOfWeek  = " + "0x"+stat.calAlarm1DOW+ ",  /* Day of week = " + stat.calAlarm1DOW + " (" + calAlarm1DOWString + ") */";
            }
            if(stat.enCalAlarm1DOM) {
                alarmString += "\n\t\t.dayOfMonth = " + "0x"+stat.calAlarm1DOM+ ",  /* Day of month = " + stat.calAlarm1DOM + " */";
            }
            alarmString += "\n};";
        };
    }
    return alarmString;
}

function getRTCCalenderAlarm2(stat, peripheral) {
    let calendarString = "";
    let daysOfTheWeek = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    /* Get calendar day of the week */
    let calDOWString = daysOfTheWeek[stat.calDOW];
    /* Get calendar month */
    let months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
    let calMonthString = months[(stat.calMonth - 1)];
    let alarmString = "";
    //%if(stat.rtcFormat == "BCD")
    /* Get calendar alarm 2 day of the week */
    let calAlarm2DOWString = daysOfTheWeek[stat.calAlarm2DOW];
    if(stat.enCalAlarm2 && (stat.enCalAlarm2Min || stat.enCalAlarm2Hour || stat.enCalAlarm2DOW || stat.enCalAlarm2DOM)) {
        if(stat.rtcFormat == "BINARY"){
            alarmString += "static const DL_";
            alarmString += peripheral + "_CalendarAlarm gRTCAlarm2Config = {";
            if(stat.enCalAlarm2Min) {
                alarmString += "\n\t\t.minutes    = " + stat.calAlarm2Min + ", /* Minute = " + stat.calAlarm2Min + " */";
            }
            if(stat.enCalAlarm2Hour) {
                alarmString += "\n\t\t.hours      = " + stat.calAlarm2Hour + ", /* Hour = " + stat.calAlarm2Hour + " */";
            }
            if(stat.enCalAlarm2DOW) {
                alarmString += "\n\t\t.dayOfWeek  = " + stat.calAlarm2DOW + ",  /* Day of week = " + stat.calAlarm2DOW +  " (" + calAlarm2DOWString + ") */";
            }
            if(stat.enCalAlarm2DOM) {
                alarmString += "\n\t\t.dayOfMonth = " + stat.calAlarm2DOM + ",  /* Day of month = " + stat.calAlarm2DOM + " */";
            }
            alarmString += "\n\};";
        }
        else if(stat.rtcFormat == "BCD"){
            alarmString += "static const DL_";
            alarmString += peripheral + "_CalendarAlarm gRTCAlarm2Config = {";
            if(stat.enCalAlarm2Min) {
                alarmString += "\n\t\t.minutes    = " + "0x"+stat.calAlarm2Min+ ", /* Minute = " + stat.calAlarm2Min + " */";
            }
            if(stat.enCalAlarm2Hour) {
                alarmString += "\n\t\t.hours      = " + "0x"+stat.calAlarm2Hour+ ", /* Hour = " + stat.calAlarm2Hour + " */";
            }
            if(stat.enCalAlarm2DOW) {
                alarmString += "\n\t\t.dayOfWeek  = " + "0x"+stat.calAlarm2DOW+ ",  /* Day of week = " + stat.calAlarm2DOW + " (" + calAlarm2DOWString + ") */";
            }
            if(stat.enCalAlarm2DOM) {
                alarmString += "\n\t\t.dayOfMonth = " + "0x"+stat.calAlarm2DOM+ ",  /* Day of month = " + stat.calAlarm2DOM + " */";
            }
            alarmString += "\n};";
        };
    }
    return alarmString;
}

function getRTCSyscfgInit(stat, peripheral) {
    let initString = "";
    initString += "\t/* Initialize RTC Calendar */";
    initString += "\n\tDL_" + peripheral + "_initCalendar(" + peripheral + " , gRTCCalendarConfig, DL_" + peripheral + "_FORMAT_" + stat.rtcFormat + ");";
    initString += "\n";
    if(stat.enCalAlarm1 && (stat.enCalAlarm1Min || stat.enCalAlarm1Hour || stat.enCalAlarm1DOW || stat.enCalAlarm1DOM)) {
        if(stat.rtcFormat == "BINARY") {

            initString += "\n\t/* Clear RTC Calendar Alarm 1 */";
            initString += "\n\tDL_" + peripheral + "_disableAlarm1MinutesBinary(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm1HoursBinary(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm1DayOfWeekBinary(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm1DayOfMonthBinary(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableInterrupt(" + peripheral + ", DL_" + peripheral + "_INTERRUPT_CALENDAR_ALARM1);";
            initString += "\n";
            initString += "\n\t/* Configure RTC Calendar Alarm 1 */";
            initString += "\n\tDL_" + peripheral + "_setCalendarAlarm1(" + peripheral + ", gRTCAlarm1Config);";
            if(stat.enCalAlarm1Min) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm1MinutesBinary(" + peripheral + ");";
            }
            if(stat.enCalAlarm1Hour) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm1HoursBinary(" + peripheral + ");";
            }
            if(stat.enCalAlarm1DOW) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm1DayOfWeekBinary(" + peripheral + ");";
            }
            if(stat.enCalAlarm1DOM) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm1DayOfMonthBinary(" + peripheral + ");";
            }
            initString += "\n";
        }
        if(stat.rtcFormat == "BCD") {

            initString += "\n\t/* Clear RTC Calendar Alarm 1 */";
            initString += "\n\tDL_" + peripheral + "_disableAlarm1MinutesBCD(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm1HoursBCD(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm1DayOfWeekBCD(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm1DayOfMonthBCD(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableInterrupt(" + peripheral + ", DL_" + peripheral + "_INTERRUPT_CALENDAR_ALARM1);";
            initString += "\n";
            initString += "\n\t/* Configure RTC Calendar Alarm 1 */";
            initString += "\n\tDL_" + peripheral + "_setCalendarAlarm1(" + peripheral + ", gRTCAlarm1Config);";
            if(stat.enCalAlarm1Min) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm1MinutesBCD(" + peripheral + ");";
            }
            if(stat.enCalAlarm1Hour) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm1HoursBCD(" + peripheral + ");";
            }
            if(stat.enCalAlarm1DOW) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm1DayOfWeekBCD(" + peripheral + ");";
            }
            if(stat.enCalAlarm1DOM) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm1DayOfMonthBCD(" + peripheral + ");";
            }
            initString += "\n";
        }
    }
    if(stat.enCalAlarm2 && (stat.enCalAlarm2Min || stat.enCalAlarm2Hour || stat.enCalAlarm2DOW || stat.enCalAlarm2DOM)) {
        if(stat.rtcFormat == "BINARY") {
            initString += "\n\t/* Clear RTC Calendar Alarm 2 */";
            initString += "\n\tDL_" + peripheral + "_disableAlarm2MinutesBinary(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm2HoursBinary(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm2DayOfWeekBinary(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm2DayOfMonthBinary(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableInterrupt(" + peripheral + ", DL_" + peripheral + "_INTERRUPT_CALENDAR_ALARM2);";
            initString += "\n";
            initString += "\n\t/* Configure RTC Calendar Alarm 2 */";
            initString += "\n\tDL_" + peripheral + "_setCalendarAlarm2(" + peripheral + ", gRTCAlarm2Config);";
            if(stat.enCalAlarm2Min) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm2MinutesBinary(" + peripheral + ");";
            }
            if(stat.enCalAlarm2Hour) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm2HoursBinary(" + peripheral + ");";
            }
            if(stat.enCalAlarm2DOW) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm2DayOfWeekBinary(" + peripheral + ");";
            }
            if(stat.enCalAlarm2DOM) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm2DayOfMonthBinary(" + peripheral + ");";
            }
            initString += "\n";
        }
        if(stat.rtcFormat == "BCD") {

            initString += "\n\t/* Clear RTC Calendar Alarm 2 */";
            initString += "\n\tDL_" + peripheral + "_disableAlarm2MinutesBCD(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm2HoursBCD(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm2DayOfWeekBCD(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableAlarm2DayOfMonthBCD(" + peripheral + ");";
            initString += "\n\tDL_" + peripheral + "_disableInterrupt(" + peripheral + ", DL_" + peripheral + "_INTERRUPT_CALENDAR_ALARM2);";

            initString += "\n\t/* Configure RTC Calendar Alarm 2 */";
            initString += "\n\tDL_" + peripheral + "_setCalendarAlarm2(" + peripheral + ", gRTCAlarm2Config);";
            if(stat.enCalAlarm2Min) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm2MinutesBCD(" + peripheral + ");";
            }
            if(stat.enCalAlarm2Hour) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm2HoursBCD(" + peripheral + ");";
            }
            if(stat.enCalAlarm2DOW) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm2DayOfWeekBCD(" + peripheral + ");";
            }
            if(stat.enCalAlarm2DOM) {
                initString += "\n\tDL_" + peripheral + "_enableAlarm2DayOfMonthBCD(" + peripheral + ");";
            }
            initString += "\n";
        }
    }
    if(stat.enIntervalAlarm) {
        initString += "\n";
        initString += "\n\t/* Configure Interval Alarm */";
        initString += "\n\tDL_" + peripheral + "_setIntervalAlarm(" + peripheral + ", DL_" + peripheral + "_INTERVAL_ALARM_" + stat.intervalAlarmEvent + ");";
    }
    if(stat.enPerAlarm0) {
        let perscalar0Freq;
        if(peripheral == "RTC_A") {
            var spliced = stat.perAlarm0Divider.split('_');
            var MicroSeconds = spliced[0];
            if(spliced.length > 2) {
                MicroSeconds = MicroSeconds + "." + spliced[1];
            }
            initString += "\n\t/* Configure Periodic Alarm 0 interval to every " + MicroSeconds + " microseconds */";
            initString += "\n\tDL_" + peripheral + "_setPeriodicAlarm0(" + peripheral + ", DL_" + peripheral + "_PRESCALER0_" + stat.perAlarm0Divider + ");";
            initString += "\n";
        }
        else {
            perscalar0Freq = 32768/Common.sliceNumber(stat.perAlarm0Divider);
            initString += "\n\t/* Configure Periodic Alarm 0 frequency to " + perscalar0Freq + "Hz */";
            initString += "\n\tDL_" + peripheral + "_setPeriodicAlarm0(" + peripheral + ", DL_" + peripheral + "_PRESCALER0_" + stat.perAlarm0Divider + ");";
            initString += "\n";
        }
    }
    if(stat.enPerAlarm1) {
        let perscalar1Freq;
        if(peripheral == "RTC_A") {
            var spliced = stat.perAlarm1Divider.split('_');
            var divideVal = spliced[1];
            perscalar1Freq = 128/divideVal;
            initString += "\n\t/* Configure Periodic Alarm 1 frequency to " + perscalar1Freq + "Hz */";
            initString += "\n\tDL_" + peripheral + "_setPeriodicAlarm1(" + peripheral + ", DL_" + peripheral + "_PRESCALER1_" + stat.perAlarm1Divider + ");";
            initString += "\n";
        }
        else {
            perscalar1Freq = 128/Common.sliceNumber(stat.perAlarm1Divider);
            initString += "\n\t/* Configure Periodic Alarm 1 frequency to " + perscalar1Freq + "Hz */";
            initString += "\n\tDL_" + peripheral + "_setPeriodicAlarm1(" + peripheral + ", DL_" + peripheral + "_PRESCALER1_" + stat.perAlarm1Divider + ");";
            initString += "\n";
        }
    }
    if(peripheral == "RTC_A" && stat.enPerAlarm2) {
        var spliced = stat.perAlarm2Divider.split('_');
        var seconds = spliced[0];
        initString += "\n\t/* Configure Periodic Alarm 2 interval to every " + seconds + " seconds */";
        initString += "\n\tDL_" + peripheral + "_setPeriodicAlarm2(" + peripheral + ", DL_" + peripheral + "_PRESCALER2_" + stat.perAlarm2Divider + ");";
        initString += "\n";
    }
    if(stat.enabledInterrupts.length > 0){
        let interArgs = "";
        let interCount = 0
        for (let inter of stat.enabledInterrupts) {
            if (interCount == 0) {
               interArgs += "DL_" + peripheral + "_INTERRUPT_"+inter;
           } else {
               interArgs += "\n\t";
               interArgs += " | " + "DL_" + peripheral + "_INTERRUPT_"+inter;
           }
               interCount++;
        }
        initString += "\n\t/* Configure Interrupts */";
        initString +=  "\n\tDL_" + peripheral + "_enableInterrupt(" + peripheral + ", "+interArgs+");";

        if(stat.interruptPriority !== "DEFAULT"){
            let irqnStr = peripheral + "_INT_IRQn";
            initString += "\n\tNVIC_SetPriority(" + irqnStr + ", " + stat.interruptPriority + ");";
            initString += "\n";
        }
        } else {
            // interFCT remains empty
        }
    if(stat.pubChanID != 0) {
        initString += "\n\tDL_" + peripheral + "_setPublisherChanID(" + peripheral + ", " + peripheral + "_PUB_CH);";
    }

    if(peripheral == "RTC_A" && stat.timeStampEvents.length > 0 ) {
        var tsSourcesEnableOR = "(";
        for(let timeStampSource of stat.timeStampEvents) {
            /* The last event should end with a closing parenthesis */
            if (timeStampSource == stat.timeStampEvents[stat.timeStampEvents.length - 1])
            {
                tsSourcesEnableOR += ("DL_" + peripheral + "_" + timeStampSource + ")");
            }
            else
            {
                tsSourcesEnableOR += ("DL_" + peripheral + "_" + timeStampSource + " |");
                tsSourcesEnableOR += "\n\t";
            }
        }
        initString += "\n";
        initString += "\n\t/* Configure sources for Time Stamp Event */";
        initString += "\n\tDL_" + peripheral + "_setTimeStampEventSource(" + peripheral + ", " + tsSourcesEnableOR + ");";
        initString += "\n\tDL_" + peripheral + "_setTimeStampEventCapture(" + peripheral + ", " + "DL_" + peripheral + '_' + stat.tsCaptureMethod + ");"
    }

    if((stat.pubChanID != 0) && (stat.enabledEvents.length > 0)) {
    {
    /* Event bit mask to be used in DL_LFSS_RTC_enableEvent() */
    var eventsToEnableOR = "(";

    for (let eventToEnable of stat.enabledEvents)
    {
        /* The last event should end with a closing parenthesis */
        if (eventToEnable == stat.enabledEvents[stat.enabledEvents.length - 1])
        {
            eventsToEnableOR += ("DL_" + peripheral + "_EVENT_" + eventToEnable + ")");
        }
        else
        {
            eventsToEnableOR += ("DL_" + peripheral + "_EVENT_" + eventToEnable + " |");
            eventsToEnableOR += "\n\t\t";
        }
    }
    }
    initString += "\n";
    initString += "\n\t/* Configure Events */";
    initString += "\n\tDL_" + peripheral + "_enableEvent(" + peripheral + ", " + eventsToEnableOR + ");";
    }

    if (stat.offsetCalFreq != "OFF") {
        initString += "\n\t/* Configure the Crystal Offset Error Calibration */";
        initString += "\n\tDL_" + peripheral + "_setOffsetCalibrationFrequency(" + peripheral + ", DL_" + peripheral + "_OFFSET_CALIBRATION_FREQUENCY_" + stat.offsetCalFreq + ");";
    }
    return initString;
}
