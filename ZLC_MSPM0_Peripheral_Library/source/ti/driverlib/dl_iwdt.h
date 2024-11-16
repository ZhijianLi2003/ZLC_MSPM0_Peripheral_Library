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
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*!****************************************************************************
 *  @file       dl_iwdt.h
 *  @brief      Independent Watchdog Timer (iWDT) Driver Library
 *  @defgroup   iWDT Independent Watchdog Timer (iWDT)
 *
 *  @anchor ti_dl_dl_iwdt_Overview
 *  # Overview
 *
 *  The Independent Watchdog Timer Driver Library allows full configuration of
 *  the MSPM0 iWDT module.
 *  The independent window watchdog timer (iWDT) in the LFSS IP is an SoC independent supervisor
 *  which monitors code execution and overall hang up scenarios of the SoC. Due to
 *  the nature of the LFSS IP, this iWDT has its own system independent power and clock source.
 *  If the application software does not successfully reset the watchdog within the programmed time,
 *  the watchdog generates a POR reset to the SoC
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup IWDT
 * @{
 */
#ifndef ti_dl_dl_iwdt__include
#define ti_dl_dl_iwdt__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/driverlib/dl_lfss.h>

#ifdef __MSPM0_HAS_IWDT__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_CLOCK_DIVIDE_1
 */
#define DL_IWDT_CLOCK_DIVIDE_1                           DL_LFSS_IWDT_CLOCK_DIVIDE_1

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_CLOCK_DIVIDE_2
 */
#define DL_IWDT_CLOCK_DIVIDE_2                           DL_LFSS_IWDT_CLOCK_DIVIDE_2

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_CLOCK_DIVIDE_3
 */
#define DL_IWDT_CLOCK_DIVIDE_3                           DL_LFSS_IWDT_CLOCK_DIVIDE_3

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_CLOCK_DIVIDE_4
 */
#define DL_IWDT_CLOCK_DIVIDE_4                           DL_LFSS_IWDT_CLOCK_DIVIDE_4

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_CLOCK_DIVIDE_5
 */
#define DL_IWDT_CLOCK_DIVIDE_5                           DL_LFSS_IWDT_CLOCK_DIVIDE_5

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_CLOCK_DIVIDE_6
 */
#define DL_IWDT_CLOCK_DIVIDE_6                           DL_LFSS_IWDT_CLOCK_DIVIDE_6

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_CLOCK_DIVIDE_7
 */
#define DL_IWDT_CLOCK_DIVIDE_7                           DL_LFSS_IWDT_CLOCK_DIVIDE_7

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_CLOCK_DIVIDE_8
 */
#define DL_IWDT_CLOCK_DIVIDE_8                           DL_LFSS_IWDT_CLOCK_DIVIDE_8

/*!
 * @brief Redirects to common @ref  DL_LFSS_IWDT_TIMER_PERIOD_6_BITS
 */
#define DL_IWDT_TIMER_PERIOD_6_BITS                     DL_LFSS_IWDT_TIMER_PERIOD_6_BITS

/*!
 * @brief Redirects to common @ref  DL_LFSS_IWDT_TIMER_PERIOD_8_BITS
 */
#define DL_IWDT_TIMER_PERIOD_8_BITS                     DL_LFSS_IWDT_TIMER_PERIOD_8_BITS

/*!
 * @brief Redirects to common @ref  DL_LFSS_IWDT_TIMER_PERIOD_10_BITS
 */
#define DL_IWDT_TIMER_PERIOD_10_BITS                    DL_LFSS_IWDT_TIMER_PERIOD_10_BITS

/*!
 * @brief Redirects to common @ref  DL_LFSS_IWDT_TIMER_PERIOD_12_BITS
 */
#define DL_IWDT_TIMER_PERIOD_12_BITS                    DL_LFSS_IWDT_TIMER_PERIOD_12_BITS

/*!
 * @brief Redirects to common @ref  DL_LFSS_IWDT_TIMER_PERIOD_15_BITS
 */
#define DL_IWDT_TIMER_PERIOD_15_BITS                    DL_LFSS_IWDT_TIMER_PERIOD_15_BITS

/*!
 * @brief Redirects to common @ref  DL_LFSS_IWDT_TIMER_PERIOD_18_BITS
 */
#define DL_IWDT_TIMER_PERIOD_18_BITS                    DL_LFSS_IWDT_TIMER_PERIOD_18_BITS

/*!
 * @brief Redirects to common @ref  DL_LFSS_IWDT_TIMER_PERIOD_21_BITS
 */
#define DL_IWDT_TIMER_PERIOD_21_BITS                    DL_LFSS_IWDT_TIMER_PERIOD_21_BITS

/*!
 * @brief Redirects to common @ref  DL_LFSS_IWDT_TIMER_PERIOD_25_BITS
 */
#define DL_IWDT_TIMER_PERIOD_25_BITS                    DL_LFSS_IWDT_TIMER_PERIOD_25_BITS

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_enableModule
 */
#define DL_IWDT_enableModule                             DL_LFSS_IWDT_enableModule

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_disableModule
 */
#define DL_IWDT_disableModule                            DL_LFSS_IWDT_disableModule

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_isModuleEnabled
 */
#define DL_IWDT_isModuleEnabled                          DL_LFSS_IWDT_isModuleEnabled

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_enableFreeRun
 */
#define DL_IWDT_enableFreeRun                            DL_LFSS_IWDT_enableFreeRun

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_disableFreeRun
 */
#define DL_IWDT_disableFreeRun                           DL_LFSS_IWDT_disableFreeRun

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_isFreeRunEnabled
 */
#define DL_IWDT_isFreeRunEnabled                         DL_LFSS_IWDT_isFreeRunEnabled

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_setClockDivider
 */
#define DL_IWDT_setClockDivider                          DL_LFSS_IWDT_setClockDivider

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_getClockDivider
 */
#define DL_IWDT_getClockDivider                          DL_LFSS_IWDT_getClockDivider

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_setTimerPeriod
 */
#define DL_IWDT_setTimerPeriod                           DL_LFSS_IWDT_setTimerPeriod

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_getTimerPeriod
 */
#define DL_IWDT_getTimerPeriod                           DL_LFSS_IWDT_getTimerPeriod

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_restart
 */
#define DL_IWDT_restart                                  DL_LFSS_IWDT_restart

/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_isWatchdogRunning
 */
#define DL_IWDT_isWatchDogRunning                        DL_LFSS_IWDT_isWatchdogRunning


/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_enableWriteProtect
 */
#define DL_IWDT_enableWriteProtect                       DL_LFSS_IWDT_enableWriteProtect


/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_isWriteProtectEnabled
 */
#define DL_IWDT_isWriteProtectEnabled                    DL_LFSS_IWDT_isWriteProtectEnabled


/*!
 * @brief Redirects to common @ref DL_LFSS_IWDT_disableWriteProtect
 */
#define DL_IWDT_disableWriteProtect                      DL_LFSS_IWDT_disableWriteProtect

/* clang-format on */

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_IWDT__ */

#endif /* ti_dl_dl_iwdt__include */
/** @}*/
