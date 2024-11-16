/*
 * Copyright (c) 2020, Texas Instruments Incorporated
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
 */

#include <ti/driverlib/dl_rtc_common.h>

#if defined __MSPM0_HAS_RTC_A__ || defined __MSPM0_HAS_RTC__

void DL_RTC_Common_initCalendar(RTC_Regs *rtc_common,
    DL_RTC_Common_Calendar calendarTime, DL_RTC_COMMON_FORMAT formatSelect)
{
    DL_RTC_Common_setClockFormat(rtc_common, formatSelect);

    if (formatSelect == DL_RTC_COMMON_FORMAT_BINARY) {
        DL_RTC_Common_setCalendarSecondsBinary(
            rtc_common, calendarTime.seconds);
        DL_RTC_Common_setCalendarMinutesBinary(
            rtc_common, calendarTime.minutes);
        DL_RTC_Common_setCalendarHoursBinary(rtc_common, calendarTime.hours);
        /*
         * Back to back writes to counter/calendar registers such as
         * SEC, MIN, HOUR, DAY, MON, YEAR need to be avoided since writes
         * to calendar registers take 2 to 3 RTCCLK cycles to take effect.
         */
        DL_Common_updateReg(&rtc_common->DAY,
            (uint32_t) calendarTime.dayOfWeek |
                ((uint32_t) calendarTime.dayOfMonth << RTC_DAY_DOMBIN_OFS),
            RTC_DAY_DOW_MASK | RTC_DAY_DOMBIN_MASK);
        DL_RTC_Common_setCalendarMonthBinary(rtc_common, calendarTime.month);
        DL_RTC_Common_setCalendarYearBinary(rtc_common, calendarTime.year);
    } else {
        DL_RTC_Common_setCalendarSecondsBCD(rtc_common, calendarTime.seconds);
        DL_RTC_Common_setCalendarMinutesBCD(rtc_common, calendarTime.minutes);
        DL_RTC_Common_setCalendarHoursBCD(rtc_common, calendarTime.hours);
        DL_Common_updateReg(&rtc_common->DAY,
            (uint32_t) calendarTime.dayOfWeek |
                ((uint32_t) calendarTime.dayOfMonth << RTC_DAY_DOMLOWBCD_OFS),
            RTC_DAY_DOW_MASK | RTC_DAY_DOMLOWBCD_MASK |
                RTC_DAY_DOMHIGHBCD_MASK);
        DL_RTC_Common_setCalendarMonthBCD(rtc_common, calendarTime.month);
        DL_RTC_Common_setCalendarYearBCD(rtc_common, calendarTime.year);
    }
}

DL_RTC_Common_Calendar DL_RTC_Common_getCalendarTime(RTC_Regs *rtc_common)
{
    DL_RTC_Common_Calendar calendarTime;
    DL_RTC_COMMON_FORMAT format;

    format = DL_RTC_Common_getClockFormat(rtc_common);

    if (format == DL_RTC_COMMON_FORMAT_BINARY) {
        calendarTime.seconds =
            DL_RTC_Common_getCalendarSecondsBinary(rtc_common);
        calendarTime.minutes =
            DL_RTC_Common_getCalendarMinutesBinary(rtc_common);
        calendarTime.hours = DL_RTC_Common_getCalendarHoursBinary(rtc_common);
        calendarTime.dayOfWeek =
            DL_RTC_Common_getCalendarDayOfWeekBinary(rtc_common);
        calendarTime.dayOfMonth =
            DL_RTC_Common_getCalendarDayOfMonthBinary(rtc_common);
        calendarTime.month = DL_RTC_Common_getCalendarMonthBinary(rtc_common);
        calendarTime.year  = DL_RTC_Common_getCalendarYearBinary(rtc_common);
    } else {
        calendarTime.seconds = DL_RTC_Common_getCalendarSecondsBCD(rtc_common);
        calendarTime.minutes = DL_RTC_Common_getCalendarMinutesBCD(rtc_common);
        calendarTime.hours   = DL_RTC_Common_getCalendarHoursBCD(rtc_common);
        calendarTime.dayOfWeek =
            DL_RTC_Common_getCalendarDayOfWeekBCD(rtc_common);
        calendarTime.dayOfMonth =
            DL_RTC_Common_getCalendarDayOfMonthBCD(rtc_common);
        calendarTime.month = DL_RTC_Common_getCalendarMonthBCD(rtc_common);
        calendarTime.year  = DL_RTC_Common_getCalendarYearBCD(rtc_common);
    }

    return calendarTime;
}

void DL_RTC_Common_setCalendarAlarm1(
    RTC_Regs *rtc_common, DL_RTC_Common_CalendarAlarm alarmTime)
{
    DL_RTC_COMMON_FORMAT format;

    format = DL_RTC_Common_getClockFormat(rtc_common);

    if (format == DL_RTC_COMMON_FORMAT_BINARY) {
        DL_RTC_Common_setAlarm1MinutesBinary(rtc_common, alarmTime.minutes);
        DL_RTC_Common_setAlarm1HoursBinary(rtc_common, alarmTime.hours);
        DL_RTC_Common_setAlarm1DayOfWeekBinary(
            rtc_common, alarmTime.dayOfWeek);
        DL_RTC_Common_setAlarm1DayOfMonthBinary(
            rtc_common, alarmTime.dayOfMonth);
    } else {
        DL_RTC_Common_setAlarm1MinutesBCD(rtc_common, alarmTime.minutes);
        DL_RTC_Common_setAlarm1HoursBCD(rtc_common, alarmTime.hours);
        DL_RTC_Common_setAlarm1DayOfWeekBCD(rtc_common, alarmTime.dayOfWeek);
        DL_RTC_Common_setAlarm1DayOfMonthBCD(rtc_common, alarmTime.dayOfMonth);
    }
}

DL_RTC_Common_CalendarAlarm DL_RTC_Common_getCalendarAlarm1(
    RTC_Regs *rtc_common)
{
    DL_RTC_Common_CalendarAlarm alarmTime;
    DL_RTC_COMMON_FORMAT format;

    format = DL_RTC_Common_getClockFormat(rtc_common);

    if (format == DL_RTC_COMMON_FORMAT_BINARY) {
        alarmTime.minutes = DL_RTC_Common_getAlarm1MinutesBinary(rtc_common);
        alarmTime.hours   = DL_RTC_Common_getAlarm1HoursBinary(rtc_common);
        alarmTime.dayOfWeek =
            DL_RTC_Common_getAlarm1DayOfWeekBinary(rtc_common);
        alarmTime.dayOfMonth =
            DL_RTC_Common_getAlarm1DayOfMonthBinary(rtc_common);
    } else {
        alarmTime.minutes   = DL_RTC_Common_getAlarm1MinutesBCD(rtc_common);
        alarmTime.hours     = DL_RTC_Common_getAlarm1HoursBCD(rtc_common);
        alarmTime.dayOfWeek = DL_RTC_Common_getAlarm1DayOfWeekBCD(rtc_common);
        alarmTime.dayOfMonth =
            DL_RTC_Common_getAlarm1DayOfMonthBCD(rtc_common);
    }

    return alarmTime;
}

void DL_RTC_Common_enableCalendarAlarm1(RTC_Regs *rtc_common)
{
    DL_RTC_COMMON_FORMAT format;

    format = DL_RTC_Common_getClockFormat(rtc_common);

    if (format == DL_RTC_COMMON_FORMAT_BINARY) {
        DL_RTC_Common_enableAlarm1MinutesBinary(rtc_common);
        DL_RTC_Common_enableAlarm1HoursBinary(rtc_common);
        DL_RTC_Common_enableAlarm1DayOfWeekBinary(rtc_common);
        DL_RTC_Common_enableAlarm1DayOfMonthBinary(rtc_common);
    } else {
        DL_RTC_Common_enableAlarm1MinutesBCD(rtc_common);
        DL_RTC_Common_enableAlarm1HoursBCD(rtc_common);
        DL_RTC_Common_enableAlarm1DayOfWeekBCD(rtc_common);
        DL_RTC_Common_enableAlarm1DayOfMonthBCD(rtc_common);
    }
}

void DL_RTC_Common_disableCalendarAlarm1(RTC_Regs *rtc_common)
{
    DL_RTC_COMMON_FORMAT format;

    format = DL_RTC_Common_getClockFormat(rtc_common);

    if (format == DL_RTC_COMMON_FORMAT_BINARY) {
        DL_RTC_Common_disableAlarm1MinutesBinary(rtc_common);
        DL_RTC_Common_disableAlarm1HoursBinary(rtc_common);
        DL_RTC_Common_disableAlarm1DayOfWeekBinary(rtc_common);
        DL_RTC_Common_disableAlarm1DayOfMonthBinary(rtc_common);
    } else {
        DL_RTC_Common_disableAlarm1MinutesBCD(rtc_common);
        DL_RTC_Common_disableAlarm1HoursBCD(rtc_common);
        DL_RTC_Common_disableAlarm1DayOfWeekBCD(rtc_common);
        DL_RTC_Common_disableAlarm1DayOfMonthBCD(rtc_common);
    }
}

void DL_RTC_Common_setCalendarAlarm2(
    RTC_Regs *rtc_common, DL_RTC_Common_CalendarAlarm alarmTime)
{
    DL_RTC_COMMON_FORMAT format;

    format = DL_RTC_Common_getClockFormat(rtc_common);

    if (format == DL_RTC_COMMON_FORMAT_BINARY) {
        DL_RTC_Common_setAlarm2MinutesBinary(rtc_common, alarmTime.minutes);
        DL_RTC_Common_setAlarm2HoursBinary(rtc_common, alarmTime.hours);
        DL_RTC_Common_setAlarm2DayOfWeekBinary(
            rtc_common, alarmTime.dayOfWeek);
        DL_RTC_Common_setAlarm2DayOfMonthBinary(
            rtc_common, alarmTime.dayOfMonth);
    } else {
        DL_RTC_Common_setAlarm2MinutesBCD(rtc_common, alarmTime.minutes);
        DL_RTC_Common_setAlarm2HoursBCD(rtc_common, alarmTime.hours);
        DL_RTC_Common_setAlarm2DayOfWeekBCD(rtc_common, alarmTime.dayOfWeek);
        DL_RTC_Common_setAlarm2DayOfMonthBCD(rtc_common, alarmTime.dayOfMonth);
    }
}

DL_RTC_Common_CalendarAlarm DL_RTC_Common_getCalendarAlarm2(
    RTC_Regs *rtc_common)
{
    DL_RTC_Common_CalendarAlarm alarmTime;
    DL_RTC_COMMON_FORMAT format;

    format = DL_RTC_Common_getClockFormat(rtc_common);

    if (format == DL_RTC_COMMON_FORMAT_BINARY) {
        alarmTime.minutes = DL_RTC_Common_getAlarm2MinutesBinary(rtc_common);
        alarmTime.hours   = DL_RTC_Common_getAlarm2HoursBinary(rtc_common);
        alarmTime.dayOfWeek =
            DL_RTC_Common_getAlarm2DayOfWeekBinary(rtc_common);
        alarmTime.dayOfMonth =
            DL_RTC_Common_getAlarm2DayOfMonthBinary(rtc_common);
    } else {
        alarmTime.minutes   = DL_RTC_Common_getAlarm2MinutesBCD(rtc_common);
        alarmTime.hours     = DL_RTC_Common_getAlarm2HoursBCD(rtc_common);
        alarmTime.dayOfWeek = DL_RTC_Common_getAlarm2DayOfWeekBCD(rtc_common);
        alarmTime.dayOfMonth =
            DL_RTC_Common_getAlarm2DayOfMonthBCD(rtc_common);
    }

    return alarmTime;
}

void DL_RTC_Common_enableCalendarAlarm2(RTC_Regs *rtc_common)
{
    DL_RTC_COMMON_FORMAT format;

    format = DL_RTC_Common_getClockFormat(rtc_common);

    if (format == DL_RTC_COMMON_FORMAT_BINARY) {
        DL_RTC_Common_enableAlarm2MinutesBinary(rtc_common);
        DL_RTC_Common_enableAlarm2HoursBinary(rtc_common);
        DL_RTC_Common_enableAlarm2DayOfWeekBinary(rtc_common);
        DL_RTC_Common_enableAlarm2DayOfMonthBinary(rtc_common);
    } else {
        DL_RTC_Common_enableAlarm2MinutesBCD(rtc_common);
        DL_RTC_Common_enableAlarm2HoursBCD(rtc_common);
        DL_RTC_Common_enableAlarm2DayOfWeekBCD(rtc_common);
        DL_RTC_Common_enableAlarm2DayOfMonthBCD(rtc_common);
    }
}

void DL_RTC_Common_disableCalendarAlarm2(RTC_Regs *rtc_common)
{
    DL_RTC_COMMON_FORMAT format;

    format = DL_RTC_Common_getClockFormat(rtc_common);

    if (format == DL_RTC_COMMON_FORMAT_BINARY) {
        DL_RTC_Common_disableAlarm2MinutesBinary(rtc_common);
        DL_RTC_Common_disableAlarm2HoursBinary(rtc_common);
        DL_RTC_Common_disableAlarm2DayOfWeekBinary(rtc_common);
        DL_RTC_Common_disableAlarm2DayOfMonthBinary(rtc_common);
    } else {
        DL_RTC_Common_disableAlarm2MinutesBCD(rtc_common);
        DL_RTC_Common_disableAlarm2HoursBCD(rtc_common);
        DL_RTC_Common_disableAlarm2DayOfWeekBCD(rtc_common);
        DL_RTC_Common_disableAlarm2DayOfMonthBCD(rtc_common);
    }
}

#endif /* __MSPM0_HAS_RTC_A__ || defined __MSPM0_HAS_RTC__ */
