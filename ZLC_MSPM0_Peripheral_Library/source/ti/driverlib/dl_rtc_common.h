/*
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 * PURPOSE ARE DISCLAIMED. IN NO SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY TfHEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*!****************************************************************************
 *  @file       dl_rtc_common.h
 *  @brief      Real Time Clock A (RTC Common) Peripheral Interface
 *  @defgroup   Common Real Time Clock (RTC_Common)
 *
 *  @anchor ti_devices_msp_dl_rtc_common_Overview
 *  # Overview
 *  The RTC Common Driver Library allows full configuration of the MSPM0 RTC Common module.
 *  The real-time clock (RTC Common) module provides clock counters with calendar mode,
 *  a flexible programmable alarm, offset calibration, and a provision for
 *  temperature compensation. The module also provides a separate time stamp calendar
 *  capable of capturing a time stamp event upon loss of VDD or detection of a tamper event
 *  on a tamper I/O pin.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup RTC_Common
 * @{
 */
#ifndef ti_dl_dl_rtc_common__include
#define ti_dl_dl_rtc_common__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#if defined __MSPM0_HAS_RTC_A__ || defined __MSPM0_HAS_RTC__ || \
    defined(DOXYGEN__INCLUDE)

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/** @addtogroup DL_RTC_COMMON_INTERRUPT
 *  @{
 */

/**
 * @brief RTC Common alarm 1 interrupt
 */
#define DL_RTC_COMMON_INTERRUPT_CALENDAR_ALARM1          (RTC_CPU_INT_IMASK_RTCA1_SET)

/**
 * @brief RTC Common alarm 2 interrupt
 */
#define DL_RTC_COMMON_INTERRUPT_CALENDAR_ALARM2          (RTC_CPU_INT_IMASK_RTCA2_SET)

/**
 * @brief RTC Common prescaler 0 interrupt
 */
#define DL_RTC_COMMON_INTERRUPT_PRESCALER0               (RTC_CPU_INT_IMASK_RT0PS_SET)

/**
 * @brief RTC Common prescaler 1 interrupt
 */
#define DL_RTC_COMMON_INTERRUPT_PRESCALER1               (RTC_CPU_INT_IMASK_RT1PS_SET)

#ifdef __MSPM0_HAS_RTC_A__
/**
 * @brief RTC Common prescaler 2 interrupt
 */
#define DL_RTC_COMMON_INTERRUPT_PRESCALER2                (RTC_CPU_INT_IMASK_RT2PS_SET)
#endif

/**
 * @brief RTC Common interval timer interrupt
 */
#define DL_RTC_COMMON_INTERRUPT_INTERVAL_ALARM           (RTC_CPU_INT_IMASK_RTCTEV_SET)

/**
 * @brief RTC Common ready interrupt
 */
#define DL_RTC_COMMON_INTERRUPT_READY                    (RTC_CPU_INT_IMASK_RTCRDY_SET)

#ifdef __MSPM0_HAS_RTC_A__
/**
 * @brief RTC Time Stamp Event interrupt
 */
#define DL_RTC_COMMON_INTERRUPT_TSEVT                    (RTC_CPU_INT_IMASK_TSEVT_SET)
#endif

/** @}*/

/** @addtogroup DL_RTC_COMMON_EVENT
 *  @{
 */

/**
 * @brief RTC Common alarm 1 event
 */
#define DL_RTC_COMMON_EVENT_CALENDAR_ALARM1              (RTC_GEN_EVENT_IMASK_RTCA1_SET)

/**
 * @brief RTC Common alarm 2 event
 */
#define DL_RTC_COMMON_EVENT_CALENDAR_ALARM2              (RTC_GEN_EVENT_IMASK_RTCA2_SET)

/**
 * @brief RTC Common prescaler 0 event
 */
#define DL_RTC_COMMON_EVENT_PRESCALER0                   (RTC_GEN_EVENT_IMASK_RT0PS_SET)

/**
 * @brief RTC Common prescaler 1 event
 */
#define DL_RTC_COMMON_EVENT_PRESCALER1                   (RTC_GEN_EVENT_IMASK_RT1PS_SET)

#ifdef __MSPM0_HAS_RTC_A__
/**
 * @brief RTC Common prescaler 2 event
 */
#define DL_RTC_COMMON_EVENT_PRESCALER2                   (RTC_GEN_EVENT_IMASK_RT2PS_SET)
#endif

/**
 * @brief RTC Common interval timer event
 */
#define DL_RTC_COMMON_EVENT_INTERVAL_ALARM               (RTC_GEN_EVENT_IMASK_RTCTEV_SET)

/**
 * @brief RTC Common ready event
 */
#define DL_RTC_COMMON_EVENT_READY                        (RTC_GEN_EVENT_IMASK_RTCRDY_SET)

#ifdef __MSPM0_HAS_RTC_A__
/**
 * @brief RTC Common time stamp event
 */
#define DL_RTC_COMMON_EVENT_TSEVT                        (RTC_GEN_EVENT_IMASK_TSEVT_SET)
#endif

/** @}*/

#ifdef __MSPM0_HAS_RTC_A__
/** @addtogroup DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE
 *  @{
 */

/**
 * @brief Tamper IO 0 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_0       (RTC_TSSTAT_TSTIOEVT0_SET)

/**
 * @brief Tamper IO 1 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_1       (RTC_TSSTAT_TSTIOEVT1_SET)

/**
 * @brief Tamper IO 2 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_2       (RTC_TSSTAT_TSTIOEVT2_SET)

/**
 * @brief Tamper IO 3 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_3       (RTC_TSSTAT_TSTIOEVT3_SET)

/**
 * @brief Tamper IO 4 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_4       (RTC_TSSTAT_TSTIOEV4_SET)

/**
 * @brief Tamper IO 5 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_5       (RTC_TSSTAT_TSTIOEVT5_SET)

/**
 * @brief Tamper IO 6 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_6       (RTC_TSSTAT_TSTIOEVT6_SET)

/**
 * @brief Tamper IO 7 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_7       (RTC_TSSTAT_TSTIOEVT7_SET)

/**
 * @brief Tamper IO 8 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_8       (RTC_TSSTAT_TSTIOEV8_SET)

/**
 * @brief Tamper IO 9 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_9       (RTC_TSSTAT_TSTIOEVT9_SET)

/**
 * @brief Tamper IO 10 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_10      (RTC_TSSTAT_TSTIOEVT10_SET)

/**
 * @brief Tamper IO 11 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_11      (RTC_TSSTAT_TSTIOEVT11_SET)

/**
 * @brief Tamper IO 12 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_12      (RTC_TSSTAT_TSTIOEVT12_SET)

/**
 * @brief Tamper IO 13 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_13      (RTC_TSSTAT_TSTIOEVT13_SET)

/**
 * @brief Tamper IO 14 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_14      (RTC_TSSTAT_TSTIOEVT14_SET)

/**
 * @brief Tamper IO 15 caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_TIO_15      (RTC_TSSTAT_TSTIOEVT15_SET)

/**
 * @brief Loss of VDD caused the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE_VDD_LOSS    (RTC_TSSTAT_TSVDDEVT_SET)

/** @}*/

/** @addtogroup DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE
 *  @{
 */

/**
 * @brief Enable Tamper IO 0 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_0      (RTC_TSCTL_TSTIOEN0_ENABLE)

/**
 * @brief Enable Tamper IO 1 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_1      (RTC_TSCTL_TSTIOEN1_ENABLE)

/**
 * @brief Enable Tamper IO 2 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_2      (RTC_TSCTL_TSTIOEN2_ENABLE)

/**
 * @brief Enable Tamper IO 3 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_3      (RTC_TSCTL_TSTIOEN3_ENABLE)

/**
 * @brief Enable Tamper IO 4 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_4      (RTC_TSCTL_TSTIOEN4_ENABLE)

/**
 * @brief Enable Tamper IO 5 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_5      (RTC_TSCTL_TSTIOEN5_ENABLE)

/**
 * @brief Enable Tamper IO 6 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_6      (RTC_TSCTL_TSTIOEN6_ENABLE)

/**
 * @brief Enable Tamper IO 7 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_7      (RTC_TSCTL_TSTIOEN8_ENABLE)

/**
 * @brief Enable Tamper IO 8 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_8      (RTC_TSCTL_TSTIOEN8_ENABLE)

/**
 * @brief Enable Tamper IO 9 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_9      (RTC_TSCTL_TSTIOEN9_ENABLE)

/**
 * @brief Enable Tamper IO 10 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_10     (RTC_TSCTL_TSTIOEN10_ENABLE)

/**
 * @brief Enable Tamper IO 11 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_11     (RTC_TSCTL_TSTIOEN11_ENABLE)

/**
 * @brief Enable Tamper IO 12 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_12     (RTC_TSCTL_TSTIOEN12_ENABLE)

/**
 * @brief Enable Tamper IO 13 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_13     (RTC_TSCTL_TSTIOEN13_ENABLE)

/**
 * @brief Enable Tamper IO 14 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_14     (RTC_TSCTL_TSTIOEN14_ENABLE)

/**
 * @brief Enable Tamper IO 15 as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_TIO_15     (RTC_TSCTL_TSTIOEN15_ENABLE)

/**
 * @brief Enable VDD loss detection as a source to trigger the time stamp event
 */
#define DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE_VDD_LOSS   (RTC_TSCTL_TSVDDEN_ENABLE)

/** @}*/
#endif

/*! @enum DL_RTC_COMMON_STATUS */
typedef enum {
    /*! RTC Common is safe for reading */
    DL_RTC_COMMON_STATUS_READY = RTC_STA_RTCRDY_READY,
    /*! RTC Common is not safe for reading */
    DL_RTC_COMMON_STATUS_NOT_READY = RTC_STA_RTCRDY_NOT_READY
} DL_RTC_COMMON_STATUS;

/*! @enum DL_RTC_COMMON_COMPENSATION_STATUS */
typedef enum {
    /*! RTC Common ready to get new compensation values */
    DL_RTC_COMMON_COMPENSATION_STATUS_READY = RTC_STA_RTCTCRDY_READY,
    /*! RTC Common not ready to get new compensaiton values */
    DL_RTC_COMMON_COMPENSATION_STATUS_NOT_READY = RTC_STA_RTCTCRDY_NOT_READY
} DL_RTC_COMMON_COMPENSATION_STATUS;

/*! @enum DL_RTC_COMMON_COMPENSATION_WRITE_RESULT */
typedef enum {
    /*! Compensation write successful */
    DL_RTC_COMMON_COMPENSATION_WRITE_RESULT_OK = RTC_STA_RTCTCOK_OK,
    /*! Compensation write unsuccessful */
    DL_RTC_COMMON_COMPENSATION_WRITE_RESULT_NOT_OK = RTC_STA_RTCTCOK_NOT_OK
} DL_RTC_COMMON_COMPENSATION_WRITE_RESULT;

/*! @enum DL_RTC_COMMON_OFFSET_CALIBRATION_SIGN */
typedef enum {
    /*! Calibration frequency adjusted down */
    DL_RTC_COMMON_OFFSET_CALIBRATION_SIGN_DOWN = RTC_CAL_RTCOCALS_DOWN,
    /*! Calibration frequency adjusted up */
    DL_RTC_COMMON_OFFSET_CALIBRATION_SIGN_UP = RTC_CAL_RTCOCALS_UP
} DL_RTC_COMMON_OFFSET_CALIBRATION_SIGN;

/*! @enum DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY */
typedef enum {
    #ifdef __MSPM0_HAS_RTC__
    /*! No frequency output to RTCCLK pin */
    DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY_OFF = RTC_CAL_RTCCALFX_OFF,
    #endif
    #ifdef __MSPM0_HAS_RTC_A__
    /*! 32 kHz frequency output to RTCLK pin */
    DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY_32_KHZ = LFSS_CAL_RTCCALFX_F32KHZ,
    #endif
    /*! 512 Hz frequency output to RTCLK pin */
    DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY_512 = RTC_CAL_RTCCALFX_F512HZ,
    /*! 256 Hz frequency output to RTCLK pin */
    DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY_256 = RTC_CAL_RTCCALFX_F256HZ,
    /*! 1 Hz frequency output to RTCLK pin */
    DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY_1 = RTC_CAL_RTCCALFX_F1HZ
} DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY;

/*! @enum DL_RTC_COMMON_TEMP_CALIBRATION */
typedef enum {
    /*! Calibrate at steps of -1 */
    DL_RTC_COMMON_TEMP_CALIBRATION_DOWN1PPM = RTC_TCMP_RTCTCMPS_DOWN,
    /*! Calibrate at steps of +1 */
    DL_RTC_COMMON_TEMP_CALIBRATION_UP1PPM = RTC_TCMP_RTCTCMPS_UP
} DL_RTC_COMMON_TEMP_CALIBRATION;

/*! @enum DL_RTC_COMMON_FORMAT */
typedef enum {
    /*! Select binary format for the real-time clock */
    DL_RTC_COMMON_FORMAT_BINARY = RTC_CTL_RTCBCD_BINARY,
    /*! Select BCD format for the real-time clock */
    DL_RTC_COMMON_FORMAT_BCD = RTC_CTL_RTCBCD_BCD
} DL_RTC_COMMON_FORMAT;

/*! @enum DL_RTC_COMMON_INTERVAL_ALARM */
typedef enum {
    /*! Assert Calendar interrupt on every minute */
    DL_RTC_COMMON_INTERVAL_ALARM_MINUTECHANGE = RTC_CTL_RTCTEVTX_MINUTE,
    /*! Assert Calendar interrupt on every hour */
    DL_RTC_COMMON_INTERVAL_ALARM_HOURCHANGE = RTC_CTL_RTCTEVTX_HOUR,
    /*! Assert Calendar interrupt when hour is 12 */
    DL_RTC_COMMON_INTERVAL_ALARM_NOON = RTC_CTL_RTCTEVTX_NOON,
    /*! Assert Calendar interrupt when hour is 0 */
    DL_RTC_COMMON_INTERVAL_ALARM_MIDNIGHT = RTC_CTL_RTCTEVTX_MIDNIGHT
} DL_RTC_COMMON_INTERVAL_ALARM;

/*! @enum DL_RTC_COMMON_PRESCALER0_DIVIDE */
typedef enum {
    /*! Prescaler 0 Divide by 8 */
    DL_RTC_COMMON_PRESCALER0_DIVIDE_8 = RTC_PSCTL_RT0IP_DIV8,
    /*! Prescaler 0 Divide by 16 */
    DL_RTC_COMMON_PRESCALER0_DIVIDE_16 = RTC_PSCTL_RT0IP_DIV16,
    /*! Prescaler 0 Divide by 32 */
    DL_RTC_COMMON_PRESCALER0_DIVIDE_32 = RTC_PSCTL_RT0IP_DIV32,
    /*! Prescaler 0 Divide by 64 */
    DL_RTC_COMMON_PRESCALER0_DIVIDE_64 = RTC_PSCTL_RT0IP_DIV64,
    /*! Prescaler 0 Divide by 128 */
    DL_RTC_COMMON_PRESCALER0_DIVIDE_128 = RTC_PSCTL_RT0IP_DIV128,
    /*! Prescaler 0 Divide by 256 */
    DL_RTC_COMMON_PRESCALER0_DIVIDE_256 = RTC_PSCTL_RT0IP_DIV256
} DL_RTC_COMMON_PRESCALER0_DIVIDE;

/*! @enum DL_RTC_COMMON_PRESCALER1_DIVIDE */
typedef enum {
    /*! Prescaler 1 Divide by 2 */
    DL_RTC_COMMON_PRESCALER1_DIVIDE_2 = RTC_PSCTL_RT1IP_DIV2,
    /*! Prescaler 1 Divide by 4 */
    DL_RTC_COMMON_PRESCALER1_DIVIDE_4 = RTC_PSCTL_RT1IP_DIV4,
    /*! Prescaler 1 Divide by 8 */
    DL_RTC_COMMON_PRESCALER1_DIVIDE_8 = RTC_PSCTL_RT1IP_DIV8,
    /*! Prescaler 1 Divide by 16 */
    DL_RTC_COMMON_PRESCALER1_DIVIDE_16 = RTC_PSCTL_RT1IP_DIV16,
    /*! Prescaler 1 Divide by 32 */
    DL_RTC_COMMON_PRESCALER1_DIVIDE_32 = RTC_PSCTL_RT1IP_DIV32,
    /*! Prescaler 1 Divide by 64 */
    DL_RTC_COMMON_PRESCALER1_DIVIDE_64 = RTC_PSCTL_RT1IP_DIV64,
    /*! Prescaler 1 Divide by 128 */
    DL_RTC_COMMON_PRESCALER1_DIVIDE_128 = RTC_PSCTL_RT1IP_DIV128,
    /*! Prescaler 1 Divide by 256 */
    DL_RTC_COMMON_PRESCALER1_DIVIDE_256 = RTC_PSCTL_RT1IP_DIV256
} DL_RTC_COMMON_PRESCALER1_DIVIDE;

/*! @enum DL_RTC_COMMON_PRESCALER2_DIVIDE */
typedef enum {
    /*! Interval every 4 seconds */
    DL_RTC_COMMON_PRESCALER2_4_SEC = RTC_EXTPSCTL_RT2PS_INT4S,
    /*! Interval every 8 seconds */
    DL_RTC_COMMON_PRESCALER2_8_SEC = RTC_EXTPSCTL_RT2PS_INT8S,
    /*! Interval every 16 seconds */
    DL_RTC_COMMON_PRESCALER2_16_SEC = RTC_EXTPSCTL_RT2PS_INT16S
} DL_RTC_COMMON_PRESCALER2_DIVIDE;

/*! @enum DL_RTC_COMMON_IIDX */
typedef enum {
    /*! RTC Common interrupt index for alarm 1 */
    DL_RTC_COMMON_IIDX_ALARM1 = RTC_CPU_INT_IIDX_STAT_RTCA1,
    /*! RTC Common interrupt index for alarm 2 */
    DL_RTC_COMMON_IIDX_ALARM2 = RTC_CPU_INT_IIDX_STAT_RTCA2,
    /*! RTC Common interrupt index for prescaler 0 */
    DL_RTC_COMMON_IIDX_PRESCALER0 = RTC_CPU_INT_IIDX_STAT_RT0PS,
    /*! RTC Common interrupt index for prescaler 1 */
    DL_RTC_COMMON_IIDX_PRESCALER1 = RTC_CPU_INT_IIDX_STAT_RT1PS,
    /*! RTC Common interrupt index for prescaler 2 */
    DL_RTC_COMMON_IIDX_PRESCALER2 = RTC_CPU_INT_IIDX_STAT_RT2PS,
    /*! RTC Common interrupt index for interval timer */
    DL_RTC_COMMON_IIDX_INTERVAL_TIMER = RTC_CPU_INT_IIDX_STAT_RTCTEV,
    /*! RTC Common interrupt index for RTC Common ready */
    DL_RTC_COMMON_IIDX_READY = RTC_CPU_INT_IIDX_STAT_RTCRDY,
    /*! RTC Common interrupt index for Time Stamp */
    #ifdef __MSPM0_HAS_RTC_A__
    DL_RTC_COMMON_IIDX_TSEVT = RTC_CPU_INT_IIDX_STAT_TSEVT,
    /*! RTC Common interrupt index for Tamper IO 0 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_0 = RTC_CPU_INT_IIDX_STAT_TIO0,
    /*! RTC Common interrupt index for Tamper IO 1 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_1 = RTC_CPU_INT_IIDX_STAT_TIO1,
    /*! RTC Common interrupt index for Tamper IO 2 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_2 = RTC_CPU_INT_IIDX_STAT_TIO2,
    /*! RTC Common interrupt index for Tamper IO 3 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_3 = RTC_CPU_INT_IIDX_STAT_TIO3,
    /*! RTC Common interrupt index for Tamper IO 4 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_4 = RTC_CPU_INT_IIDX_STAT_TIO4,
    /*! RTC Common interrupt index for Tamper IO 5 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_5 = RTC_CPU_INT_IIDX_STAT_TIO5,
    /*! RTC Common interrupt index for Tamper IO 6 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_6 = RTC_CPU_INT_IIDX_STAT_TIO6,
    /*! RTC Common interrupt index for Tamper IO 7 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_7 = RTC_CPU_INT_IIDX_STAT_TIO7,
    /*! RTC Common interrupt index for Tamper IO 8 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_8 = RTC_CPU_INT_IIDX_STAT_TIO8,
    /*! RTC Common interrupt index for Tamper IO 9 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_9 = RTC_CPU_INT_IIDX_STAT_TIO9,
    /*! RTC Common interrupt index for Tamper IO 10 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_10 = RTC_CPU_INT_IIDX_STAT_TIO10,
    /*! RTC Common interrupt index for Tamper IO 11 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_11 = RTC_CPU_INT_IIDX_STAT_TIO11,
    /*! RTC Common interrupt index for Tamper IO 12 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_12 = RTC_CPU_INT_IIDX_STAT_TIO12,
    /*! RTC Common interrupt index for Tamper IO 13 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_13 = RTC_CPU_INT_IIDX_STAT_TIO13,
    /*! RTC Common interrupt index for Tamper IO 14 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_14 = RTC_CPU_INT_IIDX_STAT_TIO14,
    /*! RTC Common interrupt index for Tamper IO 15 */
    DL_RTC_COMMON_IIDX_TAMPER_IO_15 = RTC_CPU_INT_IIDX_STAT_TIO15,
    #endif
} DL_RTC_COMMON_IIDX;

#ifdef __MSPM0_HAS_RTC_A__
/*! @enum DL_RTC_COMMON_TIME_STAMP_EVENT_CAPTURE */
typedef enum {
    /*! Time stamp holds RTC capture at first occurrence of time stamp event */
    DL_RTC_COMMON_TIME_STAMP_EVENT_CAPTURE_FIRST = RTC_TSCTL_TSCAPTURE_FIRST,
    /*! Time stamp holds RTC capture at last occurrence of time stamp event */
    DL_RTC_COMMON_TIME_STAMP_EVENT_CAPTURE_LAST = RTC_TSCTL_TSCAPTURE_LAST,
} DL_RTC_COMMON_TIME_STAMP_EVENT_CAPTURE;
#endif

/* clang-format on */

/**
 * @brief   Alarm struct to use in DL_RTC_Common_setCalendarAlarm
 *
 * @note    All struct values must be in the same format (Binary OR BCD).
 *          RTC Common format is set during initialization.
 */
typedef struct {
    /** The minute to set the Alarm time to. Valid values are 0-59 in Binary
     * format OR 0x0-0x59 in BCD format. */
    uint8_t minutes;
    /** The hour to set the Alarm time to. Valid values are 0-23 in Binary
     * format OR 0x0-0x23 in BCD format. */
    uint8_t hours;
    /** The day of the week to set the Alarm time to. Valid values are 0-6
     * in Binary format OR 0x0-0x6 in BCD format. */
    uint8_t dayOfWeek;
    /** The day of the month to set the Alarm time to. Valid values are 1-31
     * in Binary format OR 0x1-0x31 in BCD format. */
    uint8_t dayOfMonth;
} DL_RTC_Common_CalendarAlarm;

/**
 * @brief   Calendar struct to use in DL_RTC_Common_initCalendar()
 *
 * @note    All struct values must be in the same format (Binary OR BCD).
 *          RTC Common format is set during initialization.
 */
typedef struct {
    /** The second to set the Calendar time to. Valid values are 0-59 in Binary
     * format OR 0x0-0x59 in BCD format. */
    uint8_t seconds;
    /** The minute to set the Calendar time to. Valid values are 0-59 in Binary
     * format OR 0x0-0x59 in BCD format. */
    uint8_t minutes;
    /** The hour to set the Calendar time to. Valid values are 0-23 in Binary
     * format OR 0x0-0x23 in BCD format. */
    uint8_t hours;
    /** The day of the week to set the Calendar time to. Valid values are 0-6
     * in Binary format OR 0x0-0x6 in BCD format. */
    uint8_t dayOfWeek;
    /** The day of the month to set the Calendar time to. Valid values are 1-31
     * in Binary format OR 0x1-0x31 in BCD format. */
    uint8_t dayOfMonth;
    /** The month to set the Calendar time to. Valid values are 1-12 in Binary
     * format OR 0x1-0x12 in BCD format. */
    uint8_t month;
    /** The year to set the Calendar time to. Valid values are 0-4095 in Binary
     * format OR 0x0-0x4095 in BCD format. */
    uint16_t year;
} DL_RTC_Common_Calendar;

/**
 *  @brief Returns if LFCLK is selected as clock source
 *
 * If the LFCLK is enabled, the RTC Common module will select it as the clock source.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return true  If LFCLK is selected as the clock source
 *  @return false If LFCLK is not selected as the clock source
 */
__STATIC_INLINE bool DL_RTC_Common_isClockSourceLFCLK(RTC_Regs *rtc_common)
{
    return ((rtc_common->CLKSEL & RTC_CLKSEL_LFCLK_SEL_MASK) ==
            RTC_CLKSEL_LFCLK_SEL_MASK);
}

/**
 *  @brief      Enables the supply of the 32kHz clock to the RTC Common. It will not
 *              power up the 32kHz crystal oscillator. This needs to be done
 *              in the Clock System Module.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 */
__STATIC_INLINE void DL_RTC_Common_enableClockControl(RTC_Regs *rtc_common)
{
    rtc_common->CLKCTL = RTC_CLKCTL_MODCLKEN_ENABLE;
}

/**
 *  @brief      Disables the supply of the 32kHz clock to the RTC Common.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 */
__STATIC_INLINE void DL_RTC_Common_disableClockControl(RTC_Regs *rtc_common)
{
    rtc_common->CLKCTL = RTC_CLKCTL_MODCLKEN_DISABLE;
}

/**
 *  @brief      Enable power to the RTC Common module.
 *
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 */
__STATIC_INLINE void DL_RTC_Common_enablePower(RTC_Regs *rtc_common)
{
    rtc_common->GPRCM.PWREN =
        (RTC_PWREN_KEY_UNLOCK_W | RTC_PWREN_ENABLE_ENABLE);
}

/**
 *  @brief      Disable power to the RTC Common module.
 *
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 */
__STATIC_INLINE void DL_RTC_Common_disablePower(RTC_Regs *rtc_common)
{
    rtc_common->GPRCM.PWREN =
        (RTC_PWREN_KEY_UNLOCK_W | RTC_PWREN_ENABLE_DISABLE);
}

/**
 *  @brief Returns if power is enabled for the RTC Common module
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return true if power is enabled
 *  @return false if power is disabled
 */
__STATIC_INLINE bool DL_RTC_Common_isPowerEnabled(RTC_Regs *rtc_common)
{
    return ((rtc_common->GPRCM.PWREN & RTC_PWREN_ENABLE_MASK) ==
            RTC_PWREN_ENABLE_ENABLE);
}

/**
 *  @brief      Resets all registers in the RTC Common module.
 *
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 */
__STATIC_INLINE void DL_RTC_Common_reset(RTC_Regs *rtc_common)
{
    rtc_common->GPRCM.RSTCTL =
        (RTC_RSTCTL_KEY_UNLOCK_W | RTC_RSTCTL_RESETSTKYCLR_CLR |
            RTC_RSTCTL_RESETASSERT_ASSERT);
}

/**
 *  @brief      Returns if the RTC Common module was reset
 *
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return true if module was reset
 *  @return false if module was not reset
 */
__STATIC_INLINE bool DL_RTC_Common_isReset(RTC_Regs *rtc_common)
{
    return ((rtc_common->GPRCM.STAT & RTC_STAT_RESETSTKY_MASK) ==
            RTC_STAT_RESETSTKY_RESET);
}

/**
 *  @brief      Enables interrupts when the CPU is in debug mode. Interrupt
 *              requests are signaled to the interrupt controller.
 *
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 */
__STATIC_INLINE void DL_RTC_Common_enableDebugInterrupts(RTC_Regs *rtc_common)
{
    rtc_common->DBGCTL |= RTC_DBGCTL_DBGINT_ON;
}

/**
 *  @brief      Disables interrupts when the CPU is in debug mode. Interrupts
 *              of the RTC Common module will not be captured. There will be no
 *              updates to the RTCRIS, RTCMISC and RTCIIDX registers.
 *
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 */
__STATIC_INLINE void DL_RTC_Common_disableDebugInterrupts(RTC_Regs *rtc_common)
{
    rtc_common->DBGCTL &= ~(RTC_DBGCTL_DBGINT_MASK);
}

/**
 *  @brief      Enables the RTC Common modules debug mode.
 *
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 */
__STATIC_INLINE void DL_RTC_Common_enableDebugMode(RTC_Regs *rtc_common)
{
    rtc_common->DBGCTL |= RTC_DBGCTL_DBGRUN_RUN;
}

/**
 *  @brief      Disables the RTC Common modules debug mode.
 *
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 */
__STATIC_INLINE void DL_RTC_Common_disableDebugMode(RTC_Regs *rtc_common)
{
    rtc_common->DBGCTL &= ~(RTC_DBGCTL_DBGRUN_MASK);
}

/**
 *  @brief      Set the format of the real-time clock
 *
 * The format must be selected before the time is set.
 *
 *  @param[in]  rtc_common     Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  formatSelect    Selectable format the RTC Common peripheral will
 *                              provide time in. One of @ref DL_RTC_COMMON_FORMAT
 */
__STATIC_INLINE void DL_RTC_Common_setClockFormat(
    RTC_Regs *rtc_common, DL_RTC_COMMON_FORMAT formatSelect)
{
    rtc_common->CTL |= (uint32_t) formatSelect;
}

/**
 *  @brief      Get the format currently being used for counting the
 *              real-time clock.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            Format for counting the real-time clock.
 *
 *  @retval            One of @ref DL_RTC_COMMON_FORMAT
 */
__STATIC_INLINE DL_RTC_COMMON_FORMAT DL_RTC_Common_getClockFormat(
    RTC_Regs *rtc_common)
{
    uint32_t format = (rtc_common->CTL & RTC_CTL_RTCBCD_MASK);

    return (DL_RTC_COMMON_FORMAT)(format);
}

/**
 *  @brief      Sets the interval alarm event condition
 *
 * The interval alarm can be configured to generate an interval alarm event
 * when one of the following events occurs:
 * - MIN changes
 * - HOUR changes
 * - Every day at midnight (00:00:00)
 * - Every day at noon (12:00:00)
 *
 * The interval alarm sources the @ref DL_RTC_COMMON_INTERRUPT_INTERVAL_ALARM interrupt
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  alarmEvent  The interval alarm interrupt condition. One of
 *                          @ref DL_RTC_COMMON_INTERVAL_ALARM
 */
__STATIC_INLINE void DL_RTC_Common_setIntervalAlarm(
    RTC_Regs *rtc_common, DL_RTC_COMMON_INTERVAL_ALARM alarmEvent)
{
    DL_Common_updateReg(
        &rtc_common->CTL, (uint32_t) alarmEvent, RTC_CTL_RTCTEVTX_MASK);
}

/**
 *  @brief      Gets the interval alarm event condition
 *
 * The interval alarm can be configured to generate an interval alarm event
 * when one of the following events occurs:
 * - MIN changes
 * - HOUR changes
 * - Every day at midnight (00:00:00)
 * - Every day at noon (12:00:00)
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return DL_RTC_COMMON_INTERVAL_ALARM
 */
__STATIC_INLINE DL_RTC_COMMON_INTERVAL_ALARM DL_RTC_Common_getIntervalAlarm(
    RTC_Regs *rtc_common)
{
    uint32_t alarm = (rtc_common->CTL & RTC_CTL_RTCTEVTX_MASK);

    return (DL_RTC_COMMON_INTERVAL_ALARM)(alarm);
}

/**
 *  @brief      Checks if RTC Common is safe for reading
 *
 * This API checks if the counter/calender registers can be safely read.
 *
 * The RTC Common counter/calendar registers are updated once per second. To prevent
 * reading any counter/calendar register at the time of an update (which could
 * result in an invalid time being read), a keep-out window is provided. The
 * keep-out window is approximately 128/32768 seconds before the counters
 * update.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return true if RTC Common is safe for reading
 *  @return false if RTC Common values are in transition
 *
 */
__STATIC_INLINE bool DL_RTC_Common_isSafeToRead(RTC_Regs *rtc_common)
{
    return ((rtc_common->STA & RTC_STA_RTCRDY_MASK) == RTC_STA_RTCRDY_READY);
}

/**
 *  @brief      Checks if RTC Common is ready to get new calibration values
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return true if RTC Common can get new calibration values
 *  @return false if RTC Common is not ready to get new calibration values
 *
 */
__STATIC_INLINE bool DL_RTC_Common_isReadyToCalibrate(RTC_Regs *rtc_common)
{
    return (
        (rtc_common->STA & RTC_STA_RTCTCRDY_MASK) == RTC_STA_RTCTCRDY_READY);
}

/**
 *  @brief      Checks if RTC Common new calibration values were written OK
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return true if calibration write was successful
 *  @return false if calibration write was unsuccessful
 *
 */
__STATIC_INLINE bool DL_RTC_Common_isCalibrationWriteResultOK(
    RTC_Regs *rtc_common)
{
    return ((rtc_common->STA & RTC_STA_RTCTCOK_MASK) == RTC_STA_RTCTCOK_OK);
}

/**
 *  @brief      Sets output frequency for offset calibration
 *
 * Sets the frequency output to RTC_OUT pin for calibration measurement.
 * The corresponding port must be configured for the peripheral module
 * function.
 *
 *  @param[in]  rtc_common   Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  offsetFrequency   The frequency of offset calibration.
 *                                Valid values are one of
 *                                @ref DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY
 */
__STATIC_INLINE void DL_RTC_Common_setOffsetCalibrationFrequency(
    RTC_Regs *rtc_common,
    DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY offsetFrequency)
{
    DL_Common_updateReg(
        &rtc_common->CAL, (uint32_t) offsetFrequency, RTC_CAL_RTCCALFX_MASK);
}

/**
 *  @brief      Sets the offset error calibration adjustment value.
 *
 * Each LSB represents approximately +1ppm (RTCOCALXS = 1) or
 * -1ppm (RTCOCALXS = 0) adjustment in frequency. Maximum effective calibration
 * value is +/-240ppm.
 * Excess values written above +/-240ppm will be ignored by hardware.
 *
 *  @param[in]  rtc_common   Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  offsetSign        The sign of offset calibration.
 *                                Valid values are one of
 *                                @ref DL_RTC_COMMON_OFFSET_CALIBRATION_SIGN
 *  @param[in]  offsetValue       The value that the offset will be a factor of.
 *                                Must be any integer from 1-240.
 */
__STATIC_INLINE void DL_RTC_Common_setOffsetCalibrationAdjValue(
    RTC_Regs *rtc_common, DL_RTC_COMMON_OFFSET_CALIBRATION_SIGN offsetSign,
    uint8_t offsetValue)
{
    DL_Common_updateReg(&rtc_common->CAL,
        ((uint32_t) offsetSign | (uint32_t) offsetValue),
        (RTC_CAL_RTCOCALX_MASK | RTC_CAL_RTCOCALS_MASK));
}

/**
 *  @brief      Sets the offset error calibration.
 *
 * Each LSB represents approximately +1ppm (RTCOCALXS = 1) or
 * -1ppm (RTCOCALXS = 0) adjustment in frequency. Maximum effective calibration
 * value is +/-240ppm.
 * Excess values written above +/-240ppm will be ignored by hardware.
 *
 * Sets the frequency output to RTCCLK pin for calibration measurement.
 * The corresponding port must be configured for the peripheral module
 * function.
 *
 *  @param[in]  rtc_common   Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  offsetFrequency   The frequency of offset calibration.
 *                                Valid values are one of
 *                                @ref DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY
 *  @param[in]  offsetSign        The sign of offset calibration.
 *                                Valid values are one of
 *                                @ref DL_RTC_COMMON_OFFSET_CALIBRATION_SIGN
 *  @param[in]  offsetValue       The value that the offset will be a factor of.
 *                                Must be any integer from 1-240.
 */
__STATIC_INLINE void DL_RTC_Common_setOffsetCalibration(RTC_Regs *rtc_common,
    DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY offsetFrequency,
    DL_RTC_COMMON_OFFSET_CALIBRATION_SIGN offsetSign, uint8_t offsetValue)
{
    rtc_common->CAL = (offsetValue & RTC_CAL_RTCOCALX_MASK) |
                      (uint32_t) offsetFrequency | (uint32_t) offsetSign;
}

/**
 *  @brief      Gets the offset calibration frequency.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            Frequency used in offset calibration.
 *
 *  @retval            One of @ref DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY
 */
__STATIC_INLINE DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY
DL_RTC_Common_getOffsetCalibrationFrequency(RTC_Regs *rtc_common)
{
    uint32_t freq = (rtc_common->CAL & RTC_CAL_RTCCALFX_MASK);

    return (DL_RTC_COMMON_OFFSET_CALIBRATION_FREQUENCY)(freq);
}

/**
 *  @brief      Gets the offset calibration sign.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            Sign used in offset calibration.
 *
 *  @retval            One of @ref DL_RTC_COMMON_OFFSET_CALIBRATION_SIGN
 */
__STATIC_INLINE DL_RTC_COMMON_OFFSET_CALIBRATION_SIGN
DL_RTC_Common_getOffsetCalibrationSign(RTC_Regs *rtc_common)
{
    uint32_t sign = (rtc_common->CAL & RTC_CAL_RTCOCALS_MASK);

    return (DL_RTC_COMMON_OFFSET_CALIBRATION_SIGN)(sign);
}

/**
 *  @brief      Set the specified RTC Common temperature compensation.
 *
 *  This function sets the calibration offset to make the RTC Common as accurate as
 *  possible. The offsetDirection can be either +1-ppm or -1-ppm, and the
 *  offsetValue should be from 1-240 and is multiplied by the direction setting
 *  (i.e. +1-ppm * 8 (offsetValue) = +8-ppm).
 *
 *  @param[in]  rtc_common             Pointer to the register overlay for the RTC Common
 *                                peripheral
 *  @param[in]  offsetDirection   The direction that the calibration offset
 *                                will go. Valid values are one of
 *                                @ref DL_RTC_COMMON_TEMP_CALIBRATION
 *  @param[in]  offsetValue       The value that the offset will be a factor of.
 *                                Must be any integer from 1-240.
 */
__STATIC_INLINE void DL_RTC_Common_setTemperatureCompensation(
    RTC_Regs *rtc_common, DL_RTC_COMMON_TEMP_CALIBRATION offsetDirection,
    uint32_t offsetValue)
{
    rtc_common->TCMP =
        (offsetValue & RTC_TCMP_RTCTCMPX_MASK) | (uint32_t) offsetDirection;
}

/**
 *  @brief      Get the RTC Common temperature compensation.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The cumulative temperature compensation
 *
 *  @retval            Signed addition of RTCOCALX and RTCTCMPX values, and
 *                     the updated sign bit (RTCTCMPS) of the addition result.
 *
 */
__STATIC_INLINE uint32_t DL_RTC_Common_getTemperatureCompensation(
    RTC_Regs *rtc_common)
{
    return (rtc_common->TCMP);
}

/**
 *  @brief      Set the seconds in BCD in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  seconds    Value for the seconds of the RTC Common calendar
 *                         Valid values are 0x0-0x59.
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarSecondsBCD(
    RTC_Regs *rtc_common, uint8_t seconds)
{
    rtc_common->SEC = ((uint32_t) seconds << RTC_SEC_SECLOWBCD_OFS) &
                      (RTC_SEC_SECLOWBCD_MASK | RTC_SEC_SECHIGHBCD_MASK);
}

/**
 *  @brief      Get the seconds in in BCD the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The seconds in the RTC Common calendar
 *
 *  @retval            Value in range: 0x0-0x59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarSecondsBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->SEC &
                         (RTC_SEC_SECLOWBCD_MASK | RTC_SEC_SECHIGHBCD_MASK)) >>
                     RTC_SEC_SECLOWBCD_OFS);
}

/**
 *  @brief      Set the minutes in in BCD the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  minutes    Value for the minutes of the RTC Common calendar
 *                         Valid values are 0x0-0x59.
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarMinutesBCD(
    RTC_Regs *rtc_common, uint8_t minutes)
{
    rtc_common->MIN = ((uint32_t) minutes << RTC_MIN_MINLOWBCD_OFS) &
                      (RTC_MIN_MINLOWBCD_MASK | RTC_MIN_MINHIGHBCD_MASK);
}

/**
 *  @brief      Get the minutes in in BCD the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The minutes in the RTC Common calendar
 *
 *  @retval            Value in range: 0x0-0x59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarMinutesBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->MIN &
                         (RTC_MIN_MINLOWBCD_MASK | RTC_MIN_MINHIGHBCD_MASK)) >>
                     RTC_MIN_MINLOWBCD_OFS);
}

/**
 *  @brief      Set the hours in in BCD the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  hours    Value for the hours of the RTC Common calendar
 *                       Valid values are 0x0-0x23
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarHoursBCD(
    RTC_Regs *rtc_common, uint8_t hours)
{
    rtc_common->HOUR = ((uint32_t) hours << RTC_HOUR_HOURLOWBCD_OFS) &
                       (RTC_HOUR_HOURLOWBCD_MASK | RTC_HOUR_HOURHIGHBCD_MASK);
}

/**
 *  @brief      Get the hours in in BCD the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The hours in the RTC Common calendar
 *
 *  @retval            Value in range: 0x0-0x23
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarHoursBCD(RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->HOUR & (RTC_HOUR_HOURLOWBCD_MASK |
                                             RTC_HOUR_HOURHIGHBCD_MASK)) >>
                     RTC_HOUR_HOURLOWBCD_OFS);
}

/**
 *  @brief      Set the day of the week in BCD in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the week of the RTC Common calendar
 *                     Valid values are 0x0-0x6
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarDayOfWeekBCD(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->DAY, day, RTC_DAY_DOW_MASK);
}

/**
 *  @brief      Get the day of the week in BCD in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The day of the week in the RTC Common calendar
 *
 *  @retval            Value in range: 0x0-0x6
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarDayOfWeekBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->DAY & RTC_DAY_DOW_MASK);
}

/**
 *  @brief      Set the day of the month in BCD in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the month of the RTC Common calendar
 *                     Valid values are 0x1-0x31
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarDayOfMonthBCD(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->DAY,
        (uint32_t) day << RTC_DAY_DOMLOWBCD_OFS,
        (RTC_DAY_DOMLOWBCD_MASK | RTC_DAY_DOMHIGHBCD_MASK));
}

/**
 *  @brief      Get the day of the month in BCD in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The day of the month in the RTC Common calendar
 *
 *  @retval            Value in range: 0x1-0x31
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarDayOfMonthBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->DAY &
                         (RTC_DAY_DOMLOWBCD_MASK | RTC_DAY_DOMHIGHBCD_MASK)) >>
                     RTC_DAY_DOMLOWBCD_OFS);
}

/**
 *  @brief      Set the month in in BCD the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  month    Value for the month of the RTC Common calendar
 *                       Valid values are 0x1-0x12
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarMonthBCD(
    RTC_Regs *rtc_common, uint8_t month)
{
    rtc_common->MON = ((uint32_t) month << RTC_MON_MONLOWBCD_OFS) &
                      (RTC_MON_MONLOWBCD_MASK | RTC_MON_MONHIGHBCD_MASK);
}

/**
 *  @brief      Get the month of the year in BCD in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The month of the year in the RTC Common calendar
 *
 *  @retval            Value in range: 0x1-0x12
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarMonthBCD(RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->MON &
                         (RTC_MON_MONLOWBCD_MASK | RTC_MON_MONHIGHBCD_MASK)) >>
                     RTC_MON_MONLOWBCD_OFS);
}

/**
 *  @brief      Set the year in in BCD the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  year    Value for the year of the RTC Common calendar
 *                      Valid values are 0x0-0x4095
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarYearBCD(
    RTC_Regs *rtc_common, uint16_t year)
{
    rtc_common->YEAR =
        ((uint32_t) year << RTC_YEAR_YEARLOWESTBCD_OFS) &
        (RTC_YEAR_YEARLOWESTBCD_MASK | RTC_YEAR_DECADEBCD_MASK |
            RTC_YEAR_CENTLOWBCD_MASK | RTC_YEAR_CENTHIGHBCD_MASK);
}

/**
 *  @brief      Get the year in in BCD the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The year in the RTC Common calendar
 *
 *  @retval            Value in range: 0x0-0x4095
 *
 */
__STATIC_INLINE uint16_t DL_RTC_Common_getCalendarYearBCD(RTC_Regs *rtc_common)
{
    return (uint16_t)(
        (rtc_common->YEAR &
            (RTC_YEAR_YEARLOWESTBCD_MASK | RTC_YEAR_DECADEBCD_MASK |
                RTC_YEAR_CENTLOWBCD_MASK | RTC_YEAR_CENTHIGHBCD_MASK)) >>
        RTC_YEAR_YEARLOWESTBCD_OFS);
}

/**
 *  @brief      Enable minutes in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm1MinutesBCD(RTC_Regs *rtc_common)
{
    rtc_common->A1MIN |= RTC_A1MIN_AMINAEBCD_ENABLE;
}

/**
 *  @brief      Disable minutes in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm1MinutesBCD(
    RTC_Regs *rtc_common)
{
    rtc_common->A1MIN &= ~(RTC_A1MIN_AMINAEBCD_MASK);
}

/**
 *  @brief      Set the minutes in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  minutes    Value for the minutes of alarm 1
 *                         Valid values are 0x0-0x59
 *
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm1MinutesBCD(
    RTC_Regs *rtc_common, uint8_t minutes)
{
    rtc_common->A1MIN =
        ((uint32_t) minutes << RTC_A1MIN_AMINLOWBCD_OFS) &
        (RTC_A1MIN_AMINLOWBCD_MASK | RTC_A1MIN_AMINHIGHBCD_MASK);
}

/**
 *  @brief      Get the minutes in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The minutes of alarm 1
 *
 *  @retval            Value in range: 0x0-0x59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm1MinutesBCD(RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->A1MIN & (RTC_A1MIN_AMINLOWBCD_MASK |
                                              RTC_A1MIN_AMINHIGHBCD_MASK)) >>
                     RTC_A1MIN_AMINLOWBCD_OFS);
}

/**
 *  @brief      Enable hours in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm1HoursBCD(RTC_Regs *rtc_common)
{
    rtc_common->A1HOUR |= RTC_A1HOUR_AHOURAEBIN_ENABLE;
}

/**
 *  @brief      Disable hours in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm1HoursBCD(RTC_Regs *rtc_common)
{
    rtc_common->A1HOUR &= ~(RTC_A1HOUR_AHOURAEBIN_MASK);
}

/**
 *  @brief      Set the hours in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  hours    Value for the hours of alarm 1
 *                       Valid values are 0x0-0x23
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm1HoursBCD(
    RTC_Regs *rtc_common, uint8_t hours)
{
    rtc_common->A1HOUR =
        ((uint32_t) hours << RTC_A1HOUR_AHOURLOWBCD_OFS) &
        (RTC_A1HOUR_AHOURLOWBCD_MASK | RTC_A1HOUR_AHOURHIGHBCD_MASK);
}

/**
 *  @brief      Get the hours in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The hours of alarm 1
 *
 *  @retval            Value in range: 0x0-0x23
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm1HoursBCD(RTC_Regs *rtc_common)
{
    return (uint8_t)(
        (rtc_common->A1HOUR &
            (RTC_A1HOUR_AHOURLOWBCD_MASK | RTC_A1HOUR_AHOURHIGHBCD_MASK)) >>
        RTC_A1HOUR_AHOURLOWBCD_OFS);
}

/**
 *  @brief      Enable day of the week in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm1DayOfWeekBCD(
    RTC_Regs *rtc_common)
{
    rtc_common->A1DAY |= RTC_A1DAY_ADOWAE_ENABLE;
}

/**
 *  @brief      Disable day of the week in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm1DayOfWeekBCD(
    RTC_Regs *rtc_common)
{
    rtc_common->A1DAY &= ~(RTC_A1DAY_ADOWAE_MASK);
}

/**
 *  @brief      Set the day of the week in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the week of the RTC Common calendar
 *                     Valid values are 0x0-0x6
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm1DayOfWeekBCD(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->A1DAY, day, RTC_A1DAY_ADOW_MASK);
}

/**
 *  @brief      Get the day of the week in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The day of the week in the RTC Common calendar
 *
 *  @retval            Value in range: 0x0-0x6
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm1DayOfWeekBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->DAY & RTC_A1DAY_ADOW_MASK);
}

/**
 *  @brief      Enable day of the month in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm1DayOfMonthBCD(
    RTC_Regs *rtc_common)
{
    rtc_common->A1DAY |= RTC_A1DAY_ADOMAEBCD_ENABLE;
}

/**
 *  @brief      Disable day of the month in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm1DayOfMonthBCD(
    RTC_Regs *rtc_common)
{
    rtc_common->A1DAY &= ~(RTC_A1DAY_ADOMAEBCD_MASK);
}

/**
 *  @brief      Set the day of the month in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the month of the RTC Common calendar
 *                     Valid values are 0x1-0x31
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm1DayOfMonthBCD(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->A1DAY,
        (uint32_t) day << RTC_A1DAY_ADOMLOWBCD_OFS,
        (RTC_A1DAY_ADOMLOWBCD_MASK | RTC_A1DAY_ADOMHIGHBCD_MASK));
}

/**
 *  @brief      Get the day of the month in BCD for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The day of the month in the RTC Common calendar
 *
 *  @retval            Value in range: 0x1-0x31
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm1DayOfMonthBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->A1DAY & (RTC_A1DAY_ADOMLOWBCD_MASK |
                                              RTC_A1DAY_ADOMHIGHBCD_MASK)) >>
                     RTC_A1DAY_ADOMLOWBCD_OFS);
}

/**
 *  @brief      Enable minutes in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm2MinutesBCD(RTC_Regs *rtc_common)
{
    rtc_common->A2MIN |= RTC_A2MIN_AMINAEBCD_ENABLE;
}

/**
 *  @brief      Disable minutes in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm2MinutesBCD(
    RTC_Regs *rtc_common)
{
    rtc_common->A2MIN &= ~(RTC_A2MIN_AMINAEBCD_MASK);
}

/**
 *  @brief      Set the minutes in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common      Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  minutes    Value for the minutes of alarm 2
 *                         Valid values are 0x0-0x59
 *
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm2MinutesBCD(
    RTC_Regs *rtc_common, uint8_t minutes)
{
    rtc_common->A2MIN =
        ((uint32_t) minutes << RTC_A2MIN_AMINLOWBCD_OFS) &
        (RTC_A2MIN_AMINLOWBCD_MASK | RTC_A2MIN_AMINHIGHBCD_MASK);
}

/**
 *  @brief      Get the minutes in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The minutes of alarm 2
 *
 *  @retval            Value in range: 0x0-0x59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm2MinutesBCD(RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->A2MIN & (RTC_A2MIN_AMINLOWBCD_MASK |
                                              RTC_A2MIN_AMINHIGHBCD_MASK)) >>
                     RTC_A2MIN_AMINLOWBCD_OFS);
}

/**
 *  @brief      Enable hours in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm2HoursBCD(RTC_Regs *rtc_common)
{
    rtc_common->A2HOUR |= RTC_A2HOUR_AHOURAEBIN_ENABLE;
}

/**
 *  @brief      Disable hours in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm2HoursBCD(RTC_Regs *rtc_common)
{
    rtc_common->A2HOUR &= ~(RTC_A2HOUR_AHOURAEBIN_MASK);
}

/**
 *  @brief      Set the hours in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  hours    Value for the hours of alarm 2
 *                       Valid values are 0x0-0x23
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm2HoursBCD(
    RTC_Regs *rtc_common, uint8_t hours)
{
    rtc_common->A2HOUR =
        ((uint32_t) hours << RTC_A2HOUR_AHOURLOWBCD_OFS) &
        (RTC_A2HOUR_AHOURLOWBCD_MASK | RTC_A2HOUR_AHOURHIGHBCD_MASK);
}

/**
 *  @brief      Get the hours in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The hours of alarm 2
 *
 *  @retval            Value in range: 0x0-0x23
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm2HoursBCD(RTC_Regs *rtc_common)
{
    return (uint8_t)(
        (rtc_common->A2HOUR &
            (RTC_A2HOUR_AHOURLOWBCD_MASK | RTC_A2HOUR_AHOURHIGHBCD_MASK)) >>
        RTC_A2HOUR_AHOURLOWBCD_OFS);
}

/**
 *  @brief      Enable day of the week in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm2DayOfWeekBCD(
    RTC_Regs *rtc_common)
{
    rtc_common->A2DAY |= RTC_A2DAY_ADOWAE_ENABLE;
}

/**
 *  @brief      Disable day of the week in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm2DayOfWeekBCD(
    RTC_Regs *rtc_common)
{
    rtc_common->A2DAY &= ~(RTC_A2DAY_ADOWAE_MASK);
}

/**
 *  @brief      Set the day of the week in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the week of the RTC Common calendar
 *                     Valid values are 0x0-0x6
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm2DayOfWeekBCD(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->A2DAY, day, RTC_A2DAY_ADOW_MASK);
}

/**
 *  @brief      Get the day of the week in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The day of the week in the RTC Common calendar
 *
 *  @retval            Value in range: 0x0-0x6
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm2DayOfWeekBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->DAY & RTC_A2DAY_ADOW_MASK);
}

/**
 *  @brief      Enable day of the month in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm2DayOfMonthBCD(
    RTC_Regs *rtc_common)
{
    rtc_common->A2DAY |= RTC_A2DAY_ADOMAEBCD_ENABLE;
}

/**
 *  @brief      Disable day of the month in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm2DayOfMonthBCD(
    RTC_Regs *rtc_common)
{
    rtc_common->A2DAY &= ~(RTC_A2DAY_ADOMAEBCD_MASK);
}

/**
 *  @brief      Set the day of the month in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the month of the RTC Common calendar
 *                     Valid values are 0x1-0x31
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm2DayOfMonthBCD(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->A2DAY,
        (uint32_t) day << RTC_A2DAY_ADOMLOWBCD_OFS,
        (RTC_A2DAY_ADOMLOWBCD_MASK | RTC_A2DAY_ADOMHIGHBCD_MASK));
}

/**
 *  @brief      Get the day of the month in BCD for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The day of the month in the RTC Common calendar
 *
 *  @retval            Value in range: 0x1-0x31
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm2DayOfMonthBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->A2DAY & (RTC_A2DAY_ADOMLOWBCD_MASK |
                                              RTC_A2DAY_ADOMHIGHBCD_MASK)) >>
                     RTC_A2DAY_ADOMLOWBCD_OFS);
}

/**
 *  @brief      Set the seconds in binary the RTC Common calendar
 *
 *  @param[in]  rtc_common      Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  seconds    Value for the seconds of the RTC Common calendar
 *                         Valid values are 0-59
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarSecondsBinary(
    RTC_Regs *rtc_common, uint8_t seconds)
{
    rtc_common->SEC = (seconds & RTC_SEC_SECBIN_MASK);
}

/**
 *  @brief      Get the seconds in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The seconds in the RTC Common calendar
 *
 *  @retval            Value in range: 0-59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarSecondsBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->SEC & RTC_SEC_SECBIN_MASK);
}

/**
 *  @brief      Set the minutes in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  minutes    Value for the minutes of the RTC Common calendar
 *                         Valid values are 0-59
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarMinutesBinary(
    RTC_Regs *rtc_common, uint8_t minutes)
{
    rtc_common->MIN = (minutes & RTC_MIN_MINBIN_MASK);
}

/**
 *  @brief      Get the minutes in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The minutes in the RTC Common calendar
 *
 *  @retval            Value in range: 0-59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarMinutesBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->MIN & RTC_MIN_MINBIN_MASK);
}

/**
 *  @brief      Set the hours in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  hours    Value for the hours of the RTC Common calendar
 *                       Valid values are 0-23
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarHoursBinary(
    RTC_Regs *rtc_common, uint8_t hours)
{
    rtc_common->HOUR = (hours & RTC_HOUR_HOURBIN_MASK);
}

/**
 *  @brief      Get the hours in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The hours in the RTC Common calendar
 *
 *  @retval            Value in range: 0-23
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarHoursBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->HOUR & RTC_HOUR_HOURBIN_MASK);
}

/**
 *  @brief      Set the day of the week in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the week of the RTC Common calendar
 *                     Valid values are 0-6
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarDayOfWeekBinary(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->DAY, day, RTC_DAY_DOW_MASK);
}

/**
 *  @brief      Get the day of the week in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The day of the week in the RTC Common calendar
 *
 *  @retval            Value in range: 0-6
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarDayOfWeekBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->DAY & RTC_DAY_DOW_MASK);
}

/**
 *  @brief      Set the day of the month in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the month of the RTC Common calendar
 *                     Valid values are 1-31
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarDayOfMonthBinary(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->DAY, (uint32_t) day << RTC_DAY_DOMBIN_OFS,
        RTC_DAY_DOMBIN_MASK);
}

/**
 *  @brief      Get the day of the month in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The day of the month in the RTC Common calendar
 *
 *  @retval            Value in range: 1-31
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarDayOfMonthBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(
        (rtc_common->DAY & RTC_DAY_DOMBIN_MASK) >> RTC_DAY_DOMBIN_OFS);
}

/**
 *  @brief      Set the month in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  month    Value for the month of the RTC Common calendar
 *                       Valid values are 1-12
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarMonthBinary(
    RTC_Regs *rtc_common, uint8_t month)
{
    rtc_common->MON = (month & RTC_MON_MONBIN_MASK);
}

/**
 *  @brief      Get the month of the year in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The month of the year in the RTC Common calendar
 *
 *  @retval            Value in range: 1-12
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getCalendarMonthBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->MON & RTC_MON_MONBIN_MASK);
}

/**
 *  @brief      Set the year in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  year    Value for the year of the RTC Common calendar
 *                      Valid values are 0-4095
 */
__STATIC_INLINE void DL_RTC_Common_setCalendarYearBinary(
    RTC_Regs *rtc_common, uint16_t year)
{
    rtc_common->YEAR = ((uint32_t) year & (RTC_YEAR_YEARLOWBIN_MASK |
                                              RTC_YEAR_YEARHIGHBIN_MASK));
}

/**
 *  @brief      Get the year in binary in the RTC Common calendar
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The year in the RTC Common calendar
 *
 *  @retval            Value in range: 0-4095
 *
 */
__STATIC_INLINE uint16_t DL_RTC_Common_getCalendarYearBinary(
    RTC_Regs *rtc_common)
{
    return (uint16_t)(rtc_common->YEAR &
                      (RTC_YEAR_YEARLOWBIN_MASK | RTC_YEAR_YEARHIGHBIN_MASK));
}

/**
 *  @brief      Enable minutes in binary in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm1MinutesBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A1MIN |= RTC_A1MIN_AMINAEBIN_ENABLE;
}

/**
 *  @brief      Disable minutes in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm1MinutesBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A1MIN &= ~(RTC_A1MIN_AMINAEBIN_MASK);
}

/**
 *  @brief      Set the minutes in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  minutes    Value for the minutes of alarm 1
 *                         Valid values are 0-59
 *
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm1MinutesBinary(
    RTC_Regs *rtc_common, uint8_t minutes)
{
    rtc_common->A1MIN = (minutes & RTC_A1MIN_AMINBIN_MASK);
}

/**
 *  @brief      Get the minutes in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The minutes of alarm 1
 *
 *  @retval            Value in range: 0-59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm1MinutesBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->A1MIN & RTC_A1MIN_AMINBIN_MASK);
}

/**
 *  @brief      Enable hours in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm1HoursBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A1HOUR |= RTC_A1HOUR_AHOURAEBIN_ENABLE;
}

/**
 *  @brief      Disable hours in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm1HoursBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A1HOUR &= ~(RTC_A1HOUR_AHOURAEBIN_MASK);
}

/**
 *  @brief      Set the hours in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  hours    Value for the hours of alarm 1
 *                       Valid values are 0-23
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm1HoursBinary(
    RTC_Regs *rtc_common, uint8_t hours)
{
    rtc_common->A1HOUR = (hours & RTC_A1HOUR_AHOURBIN_MASK);
}

/**
 *  @brief      Get the hours in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The hours of alarm 1
 *
 *  @retval            Value in range: 0-23
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm1HoursBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->A1HOUR & RTC_A1HOUR_AHOURBIN_MASK);
}

/**
 *  @brief      Enable day of the week in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm1DayOfWeekBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A1DAY |= RTC_A1DAY_ADOWAE_ENABLE;
}

/**
 *  @brief      Disable day of the week in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm1DayOfWeekBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A1DAY &= ~(RTC_A1DAY_ADOWAE_MASK);
}

/**
 *  @brief      Set the day of the week in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the week of the RTC Common calendar
 *                     Valid values are 0-6
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm1DayOfWeekBinary(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->A1DAY, day, RTC_A1DAY_ADOW_MASK);
}

/**
 *  @brief      Get the day of the week in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The day of the week in the RTC Common calendar
 *
 *  @retval            Value in range: 0-6
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm1DayOfWeekBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->A1DAY & RTC_A1DAY_ADOW_MASK);
}

/**
 *  @brief      Enable day of the month in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm1DayOfMonthBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A1DAY |= RTC_A1DAY_ADOMAEBIN_ENABLE;
}

/**
 *  @brief      Disable day of the month in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm1DayOfMonthBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A1DAY &= ~(RTC_A1DAY_ADOMAEBIN_MASK);
}

/**
 *  @brief      Set the day of the month in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the month of the RTC Common calendar
 *                     Valid values are 1-31
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm1DayOfMonthBinary(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->A1DAY,
        (uint32_t) day << RTC_A1DAY_ADOMBIN_OFS, RTC_A1DAY_ADOMBIN_MASK);
}

/**
 *  @brief      Get the day of the month in binary for RTC Common Calendar Alarm 1
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The day of the month in the RTC Common calendar
 *
 *  @retval            Value in range: 1-31
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm1DayOfMonthBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(
        (rtc_common->A1DAY & RTC_A1DAY_ADOMBIN_MASK) >> RTC_A1DAY_ADOMBIN_OFS);
}

/**
 *  @brief      Enable minutes in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm2MinutesBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A2MIN |= RTC_A2MIN_AMINAEBIN_ENABLE;
}

/**
 *  @brief      Disable minutes in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm2MinutesBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A2MIN &= ~(RTC_A2MIN_AMINAEBIN_MASK);
}

/**
 *  @brief      Set the minutes in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  minutes    Value for the minutes of alarm 2
 *                         Valid values are 0-59
 *
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm2MinutesBinary(
    RTC_Regs *rtc_common, uint8_t minutes)
{
    rtc_common->A2MIN = (minutes & RTC_A2MIN_AMINBIN_MASK);
}

/**
 *  @brief      Get the minutes in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The minutes of alarm 2
 *
 *  @retval            Value in range: 0-59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm2MinutesBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->A2MIN & RTC_A2MIN_AMINBIN_MASK);
}

/**
 *  @brief      Enable hours in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm2HoursBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A2HOUR |= RTC_A2HOUR_AHOURAEBIN_ENABLE;
}

/**
 *  @brief      Disable hours in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm2HoursBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A2HOUR &= ~(RTC_A2HOUR_AHOURAEBIN_MASK);
}

/**
 *  @brief      Set the hours in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  hours    Value for the hours of alarm 2
 *                       Valid values are 0-23
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm2HoursBinary(
    RTC_Regs *rtc_common, uint8_t hours)
{
    rtc_common->A2HOUR = (hours & RTC_A2HOUR_AHOURBIN_MASK);
}

/**
 *  @brief      Get the hours in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The hours of alarm 2
 *
 *  @retval            Value in range: 0-23
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm2HoursBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->A2HOUR & RTC_A2HOUR_AHOURBIN_MASK);
}

/**
 *  @brief      Enable day of the week in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm2DayOfWeekBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A2DAY |= RTC_A2DAY_ADOWAE_ENABLE;
}

/**
 *  @brief      Disable day of the week in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm2DayOfWeekBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A2DAY &= ~(RTC_A2DAY_ADOWAE_MASK);
}

/**
 *  @brief      Set the day of the week in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the week of the RTC Common calendar
 *                     Valid values are 0-6
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm2DayOfWeekBinary(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->A2DAY, day, RTC_A2DAY_ADOW_MASK);
}

/**
 *  @brief      Get the day of the week in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The day of the week in the RTC Common calendar
 *
 *  @retval            Value in range: 0-6
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm2DayOfWeekBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->A2DAY & RTC_A2DAY_ADOW_MASK);
}

/**
 *  @brief      Enable day of the month in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_enableAlarm2DayOfMonthBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A2DAY |= RTC_A2DAY_ADOMAEBIN_ENABLE;
}

/**
 *  @brief      Disable day of the month in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
__STATIC_INLINE void DL_RTC_Common_disableAlarm2DayOfMonthBinary(
    RTC_Regs *rtc_common)
{
    rtc_common->A2DAY &= ~(RTC_A2DAY_ADOMAEBIN_MASK);
}

/**
 *  @brief      Set the day of the month in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  day    Value for the day of the month of the RTC Common calendar
 *                     Valid values are 1-31
 */
__STATIC_INLINE void DL_RTC_Common_setAlarm2DayOfMonthBinary(
    RTC_Regs *rtc_common, uint8_t day)
{
    DL_Common_updateReg(&rtc_common->A2DAY,
        (uint32_t) day << RTC_A2DAY_ADOMBIN_OFS, RTC_A2DAY_ADOMBIN_MASK);
}

/**
 *  @brief      Get the day of the month in binary for RTC Common Calendar Alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            The day of the month in the RTC Common calendar
 *
 *  @retval            Value in range: 1-31
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getAlarm2DayOfMonthBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(
        (rtc_common->A2DAY & RTC_A2DAY_ADOMBIN_MASK) >> RTC_A2DAY_ADOMBIN_OFS);
}

/**
 *  @brief      Set prescale interrupt interval for timer 0 and 1
 *
 *  Set prescale timer interrupt interval to DL_RTC_COMMON_PRESCALE_NONE to keep the
 *  timer disabled.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @param[in]  prescaler0Divider    Value to set for prescaler 0
 *                                       interrupt interval
 *                                       One of @ref DL_RTC_COMMON_PRESCALER0_DIVIDE
 *
 *  @param[in]  prescaler1Divider    Value to set for prescaler 1
 *                                       interrupt interval
 *                                       One of @ref DL_RTC_COMMON_PRESCALER1_DIVIDE
 *  @param[in]  prescaler2Divider    Value to set for prescaler 2
 *                                   interrupt interval.
 *                                   One of @ref DL_RTC_COMMON_PRESCALER2_DIVIDE
 */
__STATIC_INLINE void DL_RTC_Common_setPrescalerEvents(RTC_Regs *rtc_common,
    DL_RTC_COMMON_PRESCALER0_DIVIDE prescaler0Divider,
    DL_RTC_COMMON_PRESCALER1_DIVIDE prescaler1Divider,
    DL_RTC_COMMON_PRESCALER2_DIVIDE prescaler2Divider)
{
    rtc_common->PSCTL =
        (((uint32_t) prescaler0Divider & RTC_PSCTL_RT0IP_MASK) |
            ((uint32_t) prescaler1Divider & RTC_PSCTL_RT1IP_MASK));
    rtc_common->EXTPSCTL =
        ((uint32_t) prescaler2Divider & RTC_EXTPSCTL_RT2PS_MASK);
}

/**
 *  @brief      Set periodic alarm 0
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @param[in]  prescaler0Divider  Value to set for prescaler 0 interrupt
 *                                 interval. One of @ref DL_RTC_COMMON_PRESCALER0_DIVIDE
 *
 */
__STATIC_INLINE void DL_RTC_Common_setPeriodicAlarm0(
    RTC_Regs *rtc_common, DL_RTC_COMMON_PRESCALER0_DIVIDE prescaler0Divider)
{
    DL_Common_updateReg(&rtc_common->PSCTL, (uint32_t) prescaler0Divider,
        RTC_PSCTL_RT0IP_MASK);
}

/**
 *  @brief      Set periodic alarm 1

 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @param[in]  prescaler1Divider  Value to set for prescaler 1 interrupt
 *                                 interval. One of @ref DL_RTC_COMMON_PRESCALER1_DIVIDE
 */
__STATIC_INLINE void DL_RTC_Common_setPeriodicAlarm1(
    RTC_Regs *rtc_common, DL_RTC_COMMON_PRESCALER1_DIVIDE prescaler1Divider)
{
    DL_Common_updateReg(&rtc_common->PSCTL, (uint32_t) prescaler1Divider,
        RTC_PSCTL_RT1IP_MASK);
}

/**
 *  @brief      Set periodic alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @param[in]  prescaler2Divider  Value to set for prescaler 2 interrupt
 *                                 interval. One of @ref DL_RTC_COMMON_PRESCALER2_DIVIDE
 */
__STATIC_INLINE void DL_RTC_Common_setPeriodicAlarm2(
    RTC_Regs *rtc_common, DL_RTC_COMMON_PRESCALER2_DIVIDE prescaler2Divider)
{
    DL_Common_updateReg(&rtc_common->EXTPSCTL, (uint32_t) prescaler2Divider,
        RTC_EXTPSCTL_RT2PS_MASK);
}

/**
 *  @brief      Get prescaler 0 interrupt interval
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            Value for prescaler 0 interrupt interval
 *
 *  @retval            One of @ref DL_RTC_COMMON_PRESCALER0_DIVIDE
 *
 */
__STATIC_INLINE DL_RTC_COMMON_PRESCALER0_DIVIDE DL_RTC_Common_getPrescaler0(
    RTC_Regs *rtc_common)
{
    uint32_t prescaler = (rtc_common->PSCTL & RTC_PSCTL_RT0IP_MASK);

    return (DL_RTC_COMMON_PRESCALER0_DIVIDE)(prescaler);
}

/**
 *  @brief      Get prescaler 1 interrupt interval
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            Value for prescaler 1 interrupt interval
 *
 *  @retval            One of @ref DL_RTC_COMMON_PRESCALER1_DIVIDE
 */
__STATIC_INLINE DL_RTC_COMMON_PRESCALER1_DIVIDE DL_RTC_Common_getPrescaler1(
    RTC_Regs *rtc_common)
{
    uint32_t prescaler = (rtc_common->PSCTL & RTC_PSCTL_RT1IP_MASK);

    return (DL_RTC_COMMON_PRESCALER1_DIVIDE)(prescaler);
}

/**
 *  @brief      Get prescaler 2 interrupt interval
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return            Value for prescaler 2 interrupt interval
 *
 *  @retval            One of @ref DL_RTC_COMMON_PRESCALER2_DIVIDE
 */
__STATIC_INLINE DL_RTC_COMMON_PRESCALER2_DIVIDE DL_RTC_Common_getPrescaler2(
    RTC_Regs *rtc_common)
{
    uint32_t prescaler = (rtc_common->EXTPSCTL & RTC_EXTPSCTL_RT2PS_MASK);

    return (DL_RTC_COMMON_PRESCALER2_DIVIDE)(prescaler);
}

/**
 *  @brief      Get the seconds in BCD in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The seconds in the time stamp
 *
 *  @retval            Value in range: 0x0-0x59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampSecondsBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->TSSEC & (RTC_TSSEC_SECLOWBCD_MASK |
                                              RTC_TSSEC_SECHIGHBCD_MASK)) >>
                     RTC_TSSEC_SECLOWBCD_OFS);
}

/**
 *  @brief      Get the minutes in BCD in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The minutes in the time stamp
 *
 *  @retval            Value in range: 0x0-0x59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampMinutesBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->TSMIN & (RTC_TSMIN_MINLOWBCD_MASK |
                                              RTC_TSMIN_MINHIGHBCD_MASK)) >>
                     RTC_TSMIN_MINLOWBCD_OFS);
}

/**
 *  @brief      Get the hours in BCD in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The hours in the time stamp
 *
 *  @retval            Value in range: 0x0-0x23
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampHoursBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->TSHOUR & (RTC_TSHOUR_HOURLOWBCD_MASK |
                                               RTC_TSHOUR_HOURHIGHBCD_MASK)) >>
                     RTC_TSHOUR_HOURLOWBCD_OFS);
}

/**
 *  @brief      Get the day of the week in BCD in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The day of the week in the time stamp
 *
 *  @retval            Value in range: 0x0-0x6
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampDayOfWeekBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->TSDAY & RTC_TSDAY_DOW_MASK);
}

/**
 *  @brief      Get the day of the month in BCD in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The day of the month in the time stamp
 *
 *  @retval            Value in range: 0x1-0x31
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampDayOfMonthBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->TSDAY & (RTC_TSDAY_DOMLOWBCD_MASK |
                                              RTC_TSDAY_DOMHIGHBCD_MASK)) >>
                     RTC_TSDAY_DOMLOWBCD_OFS);
}

/**
 *  @brief      Get the month of the year in BCD in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The month of the year in the time stamp
 *
 *  @retval            Value in range: 0x1-0x12
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampMonthBCD(
    RTC_Regs *rtc_common)
{
    return (uint8_t)((rtc_common->TSMON & (RTC_TSMON_MONLOWBCD_MASK |
                                              RTC_TSMON_MONHIGHBCD_MASK)) >>
                     RTC_TSMON_MONLOWBCD_OFS);
}

/**
 *  @brief      Get the year in BCD in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The year in the time stamp
 *
 *  @retval            Value in range: 0x0-0x4095
 *
 */
__STATIC_INLINE uint16_t DL_RTC_Common_getTimeStampYearBCD(
    RTC_Regs *rtc_common)
{
    return (uint16_t)(
        (rtc_common->TSYEAR &
            (RTC_TSYEAR_YERARLOWESTBCD_MASK | RTC_TSYEAR_DECADEBCD_MASK |
                RTC_TSYEAR_CENTLOWBCD_MASK | RTC_TSYEAR_CENTHIGHBCD_MASK)) >>
        RTC_TSYEAR_YERARLOWESTBCD_OFS);
}

/**
 *  @brief      Get the seconds in binary in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The seconds in the time stamp
 *  @retval            Value in range: 0-59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampSecondsBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->TSSEC & RTC_TSSEC_SECBIN_MASK);
}

/**
 *  @brief      Get the minutes in binary in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The minutes in the time stamp
 *
 *  @retval            Value in range: 0-59
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampMinutesBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->TSMIN & RTC_TSMIN_MINBIN_MASK);
}

/**
 *  @brief      Get the hours in binary in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The hours in the time stamp
 *
 *  @retval            Value in range: 0-23
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampHoursBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->TSHOUR & RTC_TSHOUR_HOURBIN_MASK);
}

/**
 *  @brief      Get the day of the week in binary in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The day of the week in the time stamp
 *
 *  @retval            Value in range: 0-6
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampDayOfWeekBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->TSDAY & RTC_TSDAY_DOW_MASK);
}

/**
 *  @brief      Get the day of the month in binary in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The day of the month in the time stamp
 *
 *  @retval            Value in range: 1-31
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampDayOfMonthBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(
        (rtc_common->TSDAY & RTC_TSDAY_DOMBIN_MASK) >> RTC_TSDAY_DOMBIN_OFS);
}

/**
 *  @brief      Get the month of the year in binary in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The month of the year in the time stamp
 *
 *  @retval            Value in range: 1-12
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getTimeStampMonthBinary(
    RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->TSMON & RTC_TSMON_MONBIN_MASK);
}

/**
 *  @brief      Get the year in binary in the time stamp
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @pre To prevent reading any counter/calendar registers while those registers
 *  are being updated, the user can call @ref DL_RTC_Common_isSafeToRead to ensure that
 *  the registers are safe to read.
 *
 *  @return            The year in the time stamp
 *
 *  @retval            Value in range: 0-4095
 *
 */
__STATIC_INLINE uint16_t DL_RTC_Common_getTimeStampYearBinary(
    RTC_Regs *rtc_common)
{
    return (uint16_t)(rtc_common->TSYEAR & (RTC_TSYEAR_YEARLOWBIN_MASK |
                                               RTC_TSYEAR_YEARHIGHBIN_MASK));
}

/**
 *  @brief      Enable RTC Common interrupts
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Logical OR of
 *                             @ref DL_RTC_COMMON_INTERRUPT.
 */
__STATIC_INLINE void DL_RTC_Common_enableInterrupt(
    RTC_Regs *rtc_common, uint32_t interruptMask)
{
    rtc_common->CPU_INT.IMASK |= interruptMask;
}

/**
 *  @brief      Disable RTC Common interrupts
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Logical OR of
 *                             @ref DL_RTC_COMMON_INTERRUPT
 */
__STATIC_INLINE void DL_RTC_Common_disableInterrupt(
    RTC_Regs *rtc_common, uint32_t interruptMask)
{
    rtc_common->CPU_INT.IMASK &= ~(interruptMask);
}

/**
 *  @brief      Check which RTC Common interrupts are enabled
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Logical OR of
 *                             @ref DL_RTC_COMMON_INTERRUPT
 *
 *  @return     Which of the requested RTC Common interrupts are enabled
 *
 *  @retval     Logical OR of @ref DL_RTC_COMMON_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_RTC_Common_getEnabledInterrupts(
    RTC_Regs *rtc_common, uint32_t interruptMask)
{
    return (rtc_common->CPU_INT.IMASK & interruptMask);
}

/**
 *  @brief      Check interrupt flag of enabled RTC Common interrupts
 *
 *  Checks if any of the RTC Common interrupts that were previously enabled are
 *  pending.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Logical OR of
 *                             @ref DL_RTC_COMMON_INTERRUPT
 *
 *  @return     Which of the requested RTC Common interrupts are pending
 *
 *  @retval     Logical OR of @ref DL_RTC_COMMON_INTERRUPT values
 *
 *  @sa         DL_RTC_COMMON_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_RTC_Common_getEnabledInterruptStatus(
    RTC_Regs *rtc_common, uint32_t interruptMask)
{
    return (rtc_common->CPU_INT.MIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of any RTC Common interrupt
 *
 *  Checks if any of the RTC Common interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Logical OR of
 *                             @ref DL_RTC_COMMON_INTERRUPT
 *
 *  @return     Which of the requested RTC Common interrupts are pending
 *
 *  @retval     Logical OR of @ref DL_RTC_COMMON_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_RTC_Common_getRawInterruptStatus(
    RTC_Regs *rtc_common, uint32_t interruptMask)
{
    return (rtc_common->CPU_INT.RIS & interruptMask);
}

/**
 *  @brief      Get highest priority pending RTC Common interrupt
 *
 *  Checks if any of the RTC Common interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return     The highest priority pending RTC Common interrupt
 *
 *  @retval     One of @ref DL_RTC_COMMON_IIDX
 */
__STATIC_INLINE DL_RTC_COMMON_IIDX DL_RTC_Common_getPendingInterrupt(
    RTC_Regs *rtc_common)
{
    return (DL_RTC_COMMON_IIDX)(rtc_common->CPU_INT.IIDX);
}

/**
 *  @brief      Clear pending RTC Common interrupts
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Logical OR of
 *                             @ref DL_RTC_COMMON_INTERRUPT
 */
__STATIC_INLINE void DL_RTC_Common_clearInterruptStatus(
    RTC_Regs *rtc_common, uint32_t interruptMask)
{
    rtc_common->CPU_INT.ICLR = interruptMask;
}

/**
 *  @brief      Enable RTC Common event
 *
 *  @param[in]  rtc_common       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to enable. Bitwise OR of
 *                          @ref DL_RTC_COMMON_EVENT.
 */
__STATIC_INLINE void DL_RTC_Common_enableEvent(
    RTC_Regs *rtc_common, uint32_t eventMask)
{
    rtc_common->GEN_EVENT.IMASK |= (eventMask);
}

/**
 *  @brief      Disable RTC Common event
 *
 *  @param[in]  rtc_common       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to enable. Bitwise OR of
 *                          @ref DL_RTC_COMMON_EVENT.
 */
__STATIC_INLINE void DL_RTC_Common_disableEvent(
    RTC_Regs *rtc_common, uint32_t eventMask)
{
    rtc_common->GEN_EVENT.IMASK &= ~(eventMask);
}

/**
 *  @brief      Check which RTC Common events are enabled
 *
 *  @param[in]  rtc_common       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to check. Bitwise OR of
 *                          @ref DL_RTC_COMMON_EVENT.
 *
 *  @return     Which of the requested RTC Common interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_RTC_COMMON_EVENT values
 */
__STATIC_INLINE uint32_t DL_RTC_Common_getEnabledEvents(
    RTC_Regs *rtc_common, uint32_t eventMask)
{
    return ((rtc_common->GEN_EVENT.IMASK) & (eventMask));
}

/**
 *  @brief      Check event flag of enabled RTC Common event
 *
 *  Checks if any of the RTC Common events that were previously enabled are
 *  pending.
 *
 *  @param[in]  rtc_common       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to check. Bitwise OR of
 *                          @ref DL_RTC_COMMON_EVENT.
 *
 *  @return     Which of the requested RTC Common interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_RTC_COMMON_EVENT values
 *
 *  @sa         DL_RTC_COMMON_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_RTC_Common_getEnabledEventStatus(
    RTC_Regs *rtc_common, uint32_t eventMask)
{
    return ((rtc_common->GEN_EVENT.MIS) & eventMask);
}

/**
 *  @brief      Check interrupt flag of any RTC Common event
 *
 *  Checks if any events are pending. Events do not have to
 *  be previously enabled.
 *
 *  @param[in]  rtc_common       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to check. Bitwise OR of
 *                          @ref DL_RTC_COMMON_EVENT.
 *
 *  @return     Which of the requested RTC Common interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_RTC_COMMON_EVENT values
 */
__STATIC_INLINE uint32_t DL_RTC_Common_getRawEventsStatus(
    RTC_Regs *rtc_common, uint32_t eventMask)
{
    return ((rtc_common->GEN_EVENT.RIS) & eventMask);
}

/**
 *  @brief      Clear pending RTC Common events
 *
 *  @param[in]  rtc_common       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to clear. Bitwise OR of
 *                          @ref DL_RTC_COMMON_EVENT.
 */
__STATIC_INLINE void DL_RTC_Common_clearEventsStatus(
    RTC_Regs *rtc_common, uint32_t eventMask)
{
    rtc_common->GEN_EVENT.ICLR |= (eventMask);
}

/**
 *  @brief Sets the event publisher channel ID
 *
 *  @param[in]  rtc_common   Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  chanID  Channel ID number. Valid range 0-15. If ChanID == 0
 *                      publisher is disconnected.
 */
__STATIC_INLINE void DL_RTC_Common_setPublisherChanID(
    RTC_Regs *rtc_common, uint8_t chanID)
{
    rtc_common->FPUB_0 = (chanID & RTC_FPUB_0_CHANID_MAXIMUM);
}

/**
 *  @brief Gets the event publisher channel ID
 *
 *  @param[in]  rtc_common Pointer to the register overlay for the
 *                  peripheral
 *
 *  @return     Event publisher channel ID
 *
 */
__STATIC_INLINE uint8_t DL_RTC_Common_getPublisherChanID(RTC_Regs *rtc_common)
{
    return (uint8_t)(rtc_common->FPUB_0 & RTC_FPUB_0_CHANID_MAXIMUM);
}

/**
 *  @brief      Gets the cause of the time stamp event

 *  @param[in]  rtc_common Pointer to the register overlay for the peripheral
 *  @param[in]  tsEventMask  Bit mask of events to check. Logical OR of
 *                           @ref DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE.
 *
 *  @return     The cause of the time stamp event
 *
 *  @retval     Logical OR of @ref DL_RTC_COMMON_TIME_STAMP_EVENT_CAUSE values
 */
__STATIC_INLINE uint32_t DL_RTC_Common_getTimeStampEventCause(
    RTC_Regs *rtc_common, uint32_t tsEventMask)
{
    return (rtc_common->TSSTAT & tsEventMask);
}

/**
 *  @brief      Initializes the settings to operate the RTC Common in Calendar mode.
 *
 *  @param[in]  rtc_common               Pointer to the register overlay for the
 *                                  RTC Common peripheral
 *  @param[in]  calendarTime        Structure containing the values for the
 *                                  Calendar to be initialized to
 *  @param[in]  formatSelect        Selectable format the RTC Common peripheral will
 *                                  provide time in.
 *                                  @ref DL_RTC_COMMON_FORMAT
 *
 */
void DL_RTC_Common_initCalendar(RTC_Regs *rtc_common,
    DL_RTC_Common_Calendar calendarTime, DL_RTC_COMMON_FORMAT formatSelect);

/**
 *  @brief      Returns the Calendar Time
 *
 *  @param[in]  rtc_common             Pointer to the register overlay for the
 *                                  RTC Common peripheral
 *
 * This function returns the current Calendar Time in the form of a Calendar
 * structure.
 * The time returned will be in the previously selected format.
 *
 *  @return            A Calendar structure containing the current time.
 *
 */
DL_RTC_Common_Calendar DL_RTC_Common_getCalendarTime(RTC_Regs *rtc_common);

/**
 *  @brief      Set calendar alarm 1
 *
 *  @param[in]  rtc_common             Pointer to the register overlay for the
 *                                  RTC Common peripheral
 *  @param[in]  alarmTime           Structure containing the values for the
 *                                  alarm to be set to
 *
 */
void DL_RTC_Common_setCalendarAlarm1(
    RTC_Regs *rtc_common, DL_RTC_Common_CalendarAlarm alarmTime);

/**
 *  @brief      Get calendar alarm 1
 *
 *  @param[in]  rtc_common               Pointer to the register overlay for the
 *                                  RTC Common peripheral
 *
 *  @return     A Alarm structure containing the set time for alarm 1
 *
 */
DL_RTC_Common_CalendarAlarm DL_RTC_Common_getCalendarAlarm1(
    RTC_Regs *rtc_common);

/**
 *  @brief      Enable calendar alarm 1
 *
 *  @param[in]  rtc_common               Pointer to the register overlay for the
 *                                  RTC Common peripheral
 *
 */
void DL_RTC_Common_enableCalendarAlarm1(RTC_Regs *rtc_common);

/**
 *  @brief      Disable calendar alarm 1
 *
 *  @param[in]  rtc_common               Pointer to the register overlay for the
 *                                  RTC Common peripheral
 *
 */
void DL_RTC_Common_disableCalendarAlarm1(RTC_Regs *rtc_common);

/**
 *  @brief      Set calendar alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  alarmTime           Structure containing the values for the
 *                                  alarm to be set to
 *
 */
void DL_RTC_Common_setCalendarAlarm2(
    RTC_Regs *rtc_common, DL_RTC_Common_CalendarAlarm alarmTime);

/**
 *  @brief      Get calendar alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return     A Alarm structure containing the set time for alarm 2
 *
 */
DL_RTC_Common_CalendarAlarm DL_RTC_Common_getCalendarAlarm2(
    RTC_Regs *rtc_common);

/**
 *  @brief      Enable calendar alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
void DL_RTC_Common_enableCalendarAlarm2(RTC_Regs *rtc_common);

/**
 *  @brief      Disable calendar alarm 2
 *
 *  @param[in]  rtc_common  Pointer to the register overlay for the RTC Common peripheral
 *
 */
void DL_RTC_Common_disableCalendarAlarm2(RTC_Regs *rtc_common);

#ifdef __MSPM0_HAS_RTC_A__
/**
 *  @brief      Set the sources to trigger a time stamp capture event
 *
 *  The timestamp event can be triggered by an edge detection of any of the
 *  tamper IO. This API sets which source(s) will trigger a time stamp capture
 *  event.
 *
 *  @param[in]  rtc_common      Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  sourceMask  The sources that can trigger a time stamp capture
 *                          event. Logical OR of
 *                          @ref DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE
 */
__STATIC_INLINE void DL_RTC_Common_setTimeStampEventSource(
    RTC_Regs *rtc_common, uint32_t sourceMask)
{
    rtc_common->TSCTL |= (RTC_TSCTL_KEY_UNLOCK_W | sourceMask);
}

/**
 *  @brief      Get the sources that can trigger a time stamp capture event
 *
 *  @param[in]  rtc_common      Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  sourceMask  The sources that can trigger a time stamp capture
 *                          event. Logical OR of
 *                          @ref DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE
  *
 *  @return     The sources of the time stamp event
 *
 *  @retval     Logical OR of @ref DL_RTC_COMMON_TIME_STAMP_EVENT_SOURCE values
 */
__STATIC_INLINE uint32_t DL_RTC_Common_getTimeStampEventSource(
    RTC_Regs *rtc_common, uint32_t sourceMask)
{
    return (rtc_common->TSCTL & sourceMask);
}

/**
 *  @brief      Set the capture method when a time stamp capture event occurs
 *
 *  The timestamp event can be triggered by an edge detection of any of the
 *  tamper IO. This API sets whether the first or last occurrence of the event
 *  is captured.
 *
 *  @param[in]  rtc_common   Pointer to the register overlay for the RTC Common peripheral
 *  @param[in]  capture  The capture method for the time stamp event.
 *                       One of @ref DL_RTC_COMMON_TIME_STAMP_EVENT_CAPTURE
 */
__STATIC_INLINE void DL_RTC_Common_setTimeStampEventCapture(
    RTC_Regs *rtc_common, DL_RTC_COMMON_TIME_STAMP_EVENT_CAPTURE capture)
{
    DL_Common_updateReg(&rtc_common->TSCTL,
        (RTC_TSCTL_KEY_UNLOCK_W | (uint32_t) capture),
        (RTC_TSCTL_TSCAPTURE_MASK | RTC_TSCTL_KEY_MASK));
}

/**
 *  @brief      Get the capture method when a time stamp capture event occurs
 *
 *  The timestamp event can be triggered by an edge detection of any of the
 *  tamper IO. This API sets whether the first or last occurrence of the event
 *  is captured.
 *
 *  @param[in]  rtc_common   Pointer to the register overlay for the RTC Common peripheral
  *
 *  @return     The capture method for a time stamp capture event
 *
 *  @retval     One of @ref DL_RTC_COMMON_TIME_STAMP_EVENT_CAPTURE
 */
__STATIC_INLINE DL_RTC_COMMON_TIME_STAMP_EVENT_CAPTURE
DL_RTC_Common_getTimeStampEventCapture(RTC_Regs *rtc_common)
{
    uint32_t capture = (rtc_common->TSCTL & RTC_TSCTL_TSCAPTURE_MASK);

    return (DL_RTC_COMMON_TIME_STAMP_EVENT_CAPTURE)(capture);
}

/**
 * @brief Clear the time stamp and time stamp event status
 *
 *  The time stamp and the time stamp event status are sticky, and will stay
 *  active until cleared by software.
 *
 * @param[in] rtc_common      Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_RTC_Common_clearTimeStamp(RTC_Regs *rtc_common)
{
    rtc_common->TSCLR = (RTC_TSCLR_KEY_UNLOCK_W | RTC_TSCLR_CLR_CLR);
}

/**
 *  @brief      Enable write protection lock of the CLKCTL, SEC, MIN, HOUR,
 *              DAY, MON, YEAR and LFSSRST registers from accidental updates
 *
 *  When enabled, the CLKCTL, SEC, MIN, HOUR, DAY, MON, YEAR and LFSSRST
 *  registers will have read-only properties.
 *
 *  @param[in]  rtc_common    Pointer to the register overlay for the RTC Common peripheral
 */
__STATIC_INLINE void DL_RTC_Common_enableWriteProtect(RTC_Regs *rtc_common)
{
    rtc_common->RTCLOCK = (RTC_RTCLOCK_PROTECT_SET | RTC_RTCLOCK_KEY_UNLOCK_W);
}

/**
 *  @brief      Checks if write protection lock of the CLKCTL, SEC, MIN, HOUR,
 *              DAY, MON, YEAR and LFSSRST registers is enabled
 *
 *  @param[in]  rtc_common    Pointer to the register overlay for the RTC Common peripheral
 *
 *  @return     Returns the enabled status of the write protection lock
 *
 *  @retval     true  Write protection lock is enabled
 *  @retval     false Write protection lock is disabled
 */
__STATIC_INLINE bool DL_RTC_Common_isWriteProtectEnabled(RTC_Regs *rtc_common)
{
    return ((rtc_common->RTCLOCK & RTC_RTCLOCK_PROTECT_MASK) ==
            RTC_RTCLOCK_PROTECT_SET);
}

/**
 *  @brief      Disable write protection lock of the CLKCTL, SEC, MIN, HOUR,
 *              DAY, MON, YEAR and LFSSRST registers
 *
 *  @param[in]  rtc_common    Pointer to the register overlay for the RTC Common peripheral
 */
__STATIC_INLINE void DL_RTC_Common_disableWriteProtect(RTC_Regs *rtc_common)
{
    rtc_common->RTCLOCK = (RTC_RTCLOCK_PROTECT_CLR | RTC_RTCLOCK_KEY_UNLOCK_W);
}
#endif

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_RTC_A__ || __MSPM0_HAS_RTC__ */

#endif /* ti_dl_dl_rtc_common__include */
/** @}*/
