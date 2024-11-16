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
 *  @file       dl_tamperio.h
 *  @brief      Tamper Input/Output (TIO) Driver Library
 *  @defgroup   Tamper Input/Output (TIO)
 *
 *  @anchor ti_dl_dl_tio_Overview
 *  # Overview
 *
 *  The tamper I/O is a GPIO which is sourced by the VBAT power domain.
 *  The LFSS IP will contain up to 16 I/O’s of this type. The I/O’s have two modes of operation.
 *  In IOMUX mode the tamper I/O input and output path are connected to the SoC IOMUX module
 *  and the I/O’s can be used as a 2nd function like SPI, UART or Timer PWM. The second mode is
 *  the Tamper mode. In this mode the I/O is completely controlled by the LFSS IP and will remain
 *  functional during the power loss of the main supply or during SHUTDOWN mode.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup TAMPERIO
 * @{
 */
#ifndef ti_dl_dl_tio__include
#define ti_dl_dl_tio__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/driverlib/dl_lfss.h>

#ifdef __MSPM0_HAS_TIO__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_0
 */
#define DL_TAMPERIO_0                               DL_LFSS_TAMPERIO_0

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_1
 */
#define DL_TAMPERIO_1                               DL_LFSS_TAMPERIO_1

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_2
 */
#define DL_TAMPERIO_2                               DL_LFSS_TAMPERIO_2

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_3
 */
#define DL_TAMPERIO_3                               DL_LFSS_TAMPERIO_3

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_4
 */
#define DL_TAMPERIO_4                               DL_LFSS_TAMPERIO_4

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_5
 */
#define DL_TAMPERIO_5                               DL_LFSS_TAMPERIO_5

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_6
 */
#define DL_TAMPERIO_6                               DL_LFSS_TAMPERIO_6

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_7
 */
#define DL_TAMPERIO_7                               DL_LFSS_TAMPERIO_7

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_8
 */
#define DL_TAMPERIO_8                               DL_LFSS_TAMPERIO_8

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_9
 */
#define DL_TAMPERIO_9                               DL_LFSS_TAMPERIO_9

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_10
 */
#define DL_TAMPERIO_10                              DL_LFSS_TAMPERIO_10

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_11
 */
#define DL_TAMPERIO_11                               DL_LFSS_TAMPERIO_11

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_12
 */
#define DL_TAMPERIO_12                              DL_LFSS_TAMPERIO_12

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_13
 */
#define DL_TAMPERIO_13                               DL_LFSS_TAMPERIO_13

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_14
 */
#define DL_TAMPERIO_14                              DL_LFSS_TAMPERIO_14

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_15
 */
#define DL_TAMPERIO_15                               DL_LFSS_TAMPERIO_15

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_VALUE_0
 */
#define DL_TAMPERIO_VALUE_0                          DL_LFSS_TAMPERIO_VALUE_0

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_VALUE_1
 */
#define DL_TAMPERIO_VALUE_1                          DL_LFSS_TAMPERIO_VALUE_1

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_0
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_0                    DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_0

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_1
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_1                    DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_1

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_2
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_2                    DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_2

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_3
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_3                    DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_3

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_4
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_4                    DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_4

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_5
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_5                    DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_5

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_6
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_6                    DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_6

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_7
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_7                    DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_8

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_8
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_8                    DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_8

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_9
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_9                    DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_9

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_10
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_10                   DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_10

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_11
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_11                   DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_11

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_12
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_12                   DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_12

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_13
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_13                   DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_13

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_14
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_14                   DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_14

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_15
 */
#define DL_TAMPERIO_INTERRUPT_TAMPERIO_15                   DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_15

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_0
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_0                        DL_LFSS_TAMPERIO_EVENT_TAMPERIO_0

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_1
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_1                        DL_LFSS_TAMPERIO_EVENT_TAMPERIO_1

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_2
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_2                        DL_LFSS_TAMPERIO_EVENT_TAMPERIO_2

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_3
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_3                        DL_LFSS_TAMPERIO_EVENT_TAMPERIO_3

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_4
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_4                        DL_LFSS_TAMPERIO_EVENT_TAMPERIO_4

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_5
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_5                        DL_LFSS_TAMPERIO_EVENT_TAMPERIO_5

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_6
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_6                        DL_LFSS_TAMPERIO_EVENT_TAMPERIO_6

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_7
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_7                        DL_LFSS_TAMPERIO_EVENT_TAMPERIO_8

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_8
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_8                        DL_LFSS_TAMPERIO_EVENT_TAMPERIO_8

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_9
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_9                        DL_LFSS_TAMPERIO_EVENT_TAMPERIO_9

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_10
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_10                       DL_LFSS_TAMPERIO_EVENT_TAMPERIO_10

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_11
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_11                       DL_LFSS_TAMPERIO_EVENT_TAMPERIO_11

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_12
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_12                       DL_LFSS_TAMPERIO_EVENT_TAMPERIO_12

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_13
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_13                       DL_LFSS_TAMPERIO_EVENT_TAMPERIO_13

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_14
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_14                       DL_LFSS_TAMPERIO_EVENT_TAMPERIO_14

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EVENT_TAMPERIO_15
 */
#define DL_TAMPERIO_EVENT_TAMPERIO_15                       DL_LFSS_TAMPERIO_EVENT_TAMPERIO_15

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_0
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_0                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_0

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_1
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_1                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_1

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_2
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_2                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_2

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_3
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_3                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_3

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_4
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_4                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_4

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_5
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_5                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_5

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_6
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_6                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_6

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_7
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_7                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_7

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_8
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_8                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_8

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_9
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_9                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_9

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_10
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_10                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_10

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_11
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_11                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_11

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_12
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_12                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_12

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_13
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_13                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_13

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_14
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_14                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_14

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_15
 */
#define DL_TAMPERIO_IIDX_TAMPER_IO_15                       DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_15

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_OUTPUT_SOURCE_TOUT
 */
#define DL_TAMPERIO_OUTPUT_SOURCE_TOUT                      DL_LFSS_TAMPERIO_OUTPUT_SOURCE_TOUT

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_OUTPUT_SOURCE_LFCLK
 */
#define DL_TAMPERIO_OUTPUT_SOURCE_LFCLK                     DL_LFSS_TAMPERIO_OUTPUT_SOURCE_LFCLK

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_OUTPUT_SOURCE_HEARTBEAT
 */
#define DL_TAMPERIO_OUTPUT_SOURCE_HEARTBEAT                 DL_LFSS_TAMPERIO_OUTPUT_SOURCE_HEARTBEAT

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_OUTPUT_SOURCE_TIME_STAMP_EVENT
 */
#define DL_TAMPERIO_OUTPUT_SOURCE_TIME_STAMP_EVENT          DL_LFSS_TAMPERIO_OUTPUT_SOURCE_TIME_STAMP_EVENT

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_NONE
 */
#define DL_TAMPERIO_GLITCH_FILTER_WIDTH_NONE                DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_NONE

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_30_USEC
 */
#define DL_TAMPERIO_GLITCH_FILTER_WIDTH_30_USEC             DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_30_USEC

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_100_USEC
 */
#define DL_TAMPERIO_GLITCH_FILTER_WIDTH_100_USEC            DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_100_USEC

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_200_USEC
 */
#define DL_TAMPERIO_GLITCH_FILTER_WIDTH_200_USEC            DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_200_USEC

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_DISABLE
 */
#define DL_TAMPERIO_EDGE_DETECTION_POLARITY_DISABLE            DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_DISABLE

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_RISE
 */
#define DL_TAMPERIO_EDGE_DETECTION_POLARITY_RISE                DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_RISE

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_FALL
 */
#define DL_TAMPERIO_EDGE_DETECTION_POLARITY_FALL                DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_FALL

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_BOTH
 */
#define DL_TAMPERIO_EDGE_DETECTION_POLARITY_BOTH            DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_BOTH

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_MODE_IOMUX
 */
#define DL_TAMPERIO_MODE_TAMPER                             DL_LFSS_TAMPERIO_MODE_TAMPER

/*!
 * @brief Redirects to common @ref DL_LFSS_TAMPERIO_MODE_IOMUX
 */
#define DL_TAMPERIO_MODE_IOMUX                              DL_LFSS_TAMPERIO_MODE_IOMUX

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_INTERVAL_0_125_SEC
 */
#define DL_TAMPERIO_HEARTBEAT_INTERVAL_0_125_SEC            DL_LFSS_HEARTBEAT_INTERVAL_0_125_SEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_INTERVAL_0_25_SEC
 */
#define DL_TAMPERIO_HEARTBEAT_INTERVAL_0_25_SEC             DL_LFSS_HEARTBEAT_INTERVAL_0_25_SEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_INTERVAL_05_SEC
 */
#define DL_TAMPERIO_HEARTBEAT_INTERVAL_05_SEC                DL_LFSS_HEARTBEAT_INTERVAL_05_SEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_INTERVAL_1_SEC
 */
#define DL_TAMPERIO_HEARTBEAT_INTERVAL_1_SEC                 DL_LFSS_HEARTBEAT_INTERVAL_1_SEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_INTERVAL_2_SEC
 */
#define DL_TAMPERIO_HEARTBEAT_INTERVAL_2_SEC                 DL_LFSS_HEARTBEAT_INTERVAL_2_SEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_INTERVAL_4_SEC
 */
#define DL_TAMPERIO_HEARTBEAT_INTERVAL_4_SEC                  DL_LFSS_HEARTBEAT_INTERVAL_4_SEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_INTERVAL_8_SEC
 */
#define DL_TAMPERIO_HEARTBEAT_INTERVAL_8_SEC                  DL_LFSS_HEARTBEAT_INTERVAL_8_SEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_INTERVAL_16_SEC
 */
#define DL_TAMPERIO_HEARTBEAT_INTERVAL_16_SEC                 DL_LFSS_HEARTBEAT_INTERVAL_16_SEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_PULSE_WIDTH_1_MSEC
 */
#define DL_TAMPERIO_HEARTBEAT_PULSE_WIDTH_1_MSEC              DL_LFSS_HEARTBEAT_PULSE_WIDTH_1_MSEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_PULSE_WIDTH_2_MSEC
 */
#define DL_TAMPERIO_HEARTBEAT_PULSE_WIDTH_2_MSEC               DL_LFSS_HEARTBEAT_PULSE_WIDTH_2_MSEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_PULSE_WIDTH_4_MSEC
 */
#define DL_TAMPERIO_HEARTBEAT_PULSE_WIDTH_4_MSEC               DL_LFSS_HEARTBEAT_PULSE_WIDTH_4_MSEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_PULSE_WIDTH_8_MSEC
 */
#define DL_TAMPERIO_HEARTBEAT_PULSE_WIDTH_8_MSEC                     DL_LFSS_HEARTBEAT_PULSE_WIDTH_8_MSEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_PULSE_WIDTH_16_MSEC
 */
#define DL_TAMPERIO_HEARTBEAT_PULSE_WIDTH_16_MSEC                    DL_LFSS_HEARTBEAT_PULSE_WIDTH_16_MSEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_PULSE_WIDTH_32_MSEC
 */
#define DL_TAMPERIO_HEARTBEAT_PULSE_WIDTH_32_MSEC                    DL_LFSS_HEARTBEAT_PULSE_WIDTH_32_MSEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_PULSE_WIDTH_64_MSEC
 */
#define DL_TAMPERIO_HEARTBEAT_PULSE_WIDTH_64_MSEC                    DL_LFSS_HEARTBEAT_PULSE_WIDTH_64_MSEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_PULSE_WIDTH_128_MSEC
 */
#define DL_TAMPERIO_HEARTBEAT_PULSE_WIDTH_128_MSEC                   DL_LFSS_HEARTBEAT_PULSE_WIDTH_128_MSEC

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_MODE_DISABLED
 */
#define DL_TAMPERIO_HEARTBEAT_MODE_DISABLED                          DL_LFSS_HEARTBEAT_MODE_DISABLED

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_MODE_ALWAYS_ON
 */
#define DL_TAMPERIO_HEARTBEAT_MODE_ALWAYS_ON                         DL_LFSS_HEARTBEAT_MODE_ALWAYS_ON

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_MODE_TIME_STAMP
 */
#define DL_TAMPERIO_HEARTBEAT_MODE_TIME_STAMP                        DL_LFSS_HEARTBEAT_MODE_TIME_STAMP

/*!
 * @brief Redirects to common @ref DL_LFSS_HEARTBEAT_MODE_POWER_FAIL
 */
#define DL_TAMPERIO_HEARTBEAT_MODE_POWER_FAIL               DL_LFSS_HEARTBEAT_MODE_POWER_FAIL

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_enableOutputInversion
 */
#define DL_TamperIO_enableOutputInversion                   DL_LFSS_TamperIO_enableOutputInversion

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_isOutputInversionEnabled
 */
#define DL_TamperIO_isOutputInversionEnabled                DL_LFSS_TamperIO_isOutputInversionEnabled

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_disableOutputInversion
 */
#define DL_TamperIO_disableOutputInversion                  DL_LFSS_TamperIO_disableOutputInversion

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_setOutputSource
 */
#define DL_TamperIO_setOutputSource                         DL_LFSS_TamperIO_setOutputSource

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getOutputSource
 */
#define DL_TamperIO_getOutputSource                         DL_LFSS_TamperIO_getOutputSource

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_setGlitchFilterWidth
 */
#define DL_TamperIO_setGlitchFilterWidth                    DL_LFSS_TamperIO_setGlitchFilterWidth

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getGlitchFilterWidth
 */
#define DL_TamperIO_getGlitchFilterWidth                    DL_LFSS_TamperIO_getGlitchFilterWidth

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_setEdgeDetectionPolarity
 */
#define DL_TamperIO_setEdgeDetectionPolarity                DL_LFSS_TamperIO_setEdgeDetectionPolarity

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getEdgeDetectionPolarity
 */
#define DL_TamperIO_getEdgeDetectionPolarity                DL_LFSS_TamperIO_getEdgeDetectionPolarity

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_enableInternalPullUp
 */
#define DL_TamperIO_enableInternalPullUp                    DL_LFSS_TamperIO_enableInternalPullUp

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_isInternalPullUpEnabled
 */
#define DL_TamperIO_isInternalPullUpEnabled                 DL_LFSS_TamperIO_isInternalPullUpEnabled

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_disableInternalPullUp
 */
#define DL_TamperIO_disableInternalPullUp                   DL_LFSS_TamperIO_disableInternalPullUp

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_enableInternalPullDown
 */
#define DL_TamperIO_enableInternalPullDown                  DL_LFSS_TamperIO_enableInternalPullDown

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_isInternalPullDownEnabled
 */
#define DL_TamperIO_isInternalPullDownEnabled               DL_LFSS_TamperIO_isInternalPullDownEnabled

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_disableInternalPullDown
 */
#define DL_TamperIO_disableInternalPullDown                 DL_LFSS_TamperIO_disableInternalPullDown

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_enableInput
 */
#define DL_TamperIO_enableInput                             DL_LFSS_TamperIO_enableInput

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_isInputEnabled
 */
#define DL_TamperIO_isInputEnabled                          DL_LFSS_TamperIO_isInputEnabled

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_disableInput
 */
#define DL_TamperIO_disableInput                            DL_LFSS_TamperIO_disableInput

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_setMode
 */
#define DL_TamperIO_setMode                                 DL_LFSS_TamperIO_setMode

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getMode
 */
#define DL_TamperIO_getMode                                 DL_LFSS_TamperIO_getMode

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_enableOutput
 */
#define DL_TamperIO_enableOutput                            DL_LFSS_TamperIO_enableOutput

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_disableOutput
 */
#define DL_TamperIO_disableOutput                           DL_LFSS_TamperIO_disableOutput

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_isOutputEnabled
 */
#define DL_TamperIO_isOutputEnabled                         DL_LFSS_TamperIO_isOutputEnabled

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_setOutputValue
 */
#define DL_TamperIO_setOutputValue                          DL_LFSS_TamperIO_setOutputValue

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getOutputValue
 */
#define DL_TamperIO_getOutputValue                          DL_LFSS_TamperIO_getOutputValue

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getInputValue
 */
#define DL_TamperIO_getInputValue                           DL_LFSS_TamperIO_getInputValue

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_setHeartBeatInterval
 */
#define DL_TamperIO_setHeartBeatInterval                    DL_LFSS_TamperIO_setHeartBeatInterval

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getHeartBeatInterval
 */
#define DL_TamperIO_getHeartBeatInterval                    DL_LFSS_TamperIO_getHeartBeatInterval

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_setHeartBeatPulseWidth
 */
#define DL_TamperIO_setHeartBeatPulseWidth                  DL_LFSS_TamperIO_setHeartBeatPulseWidth

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getHeartBeatPulseWidth
 */
#define DL_TamperIO_getHeartBeatPulseWidth                  DL_LFSS_TamperIO_getHeartBeatPulseWidth

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_setHeartBeatMode
 */
#define DL_TamperIO_setHeartBeatMode                        DL_LFSS_TamperIO_setHeartBeatMode

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getHeartBeatMode
 */
#define DL_TamperIO_getHeartBeatMode                        DL_LFSS_TamperIO_getHeartBeatMode

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_enableWriteProtectLock
 */
#define DL_TamperIO_enableWriteProtectLock                  DL_LFSS_TamperIO_enableWriteProtectLock

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_isWriteProtectLockEnabled
 */
#define DL_TamperIO_isWriteProtectLockEnabled               DL_LFSS_TamperIO_isWriteProtectLockEnabled

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_disableWriteProtectLock
 */
#define DL_TamperIO_disableWriteProtectLock                 DL_LFSS_TamperIO_disableWriteProtectLock

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_enableInterrupt
 */
#define DL_TamperIO_enableInterrupt                         DL_LFSS_TamperIO_enableInterrupt

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_enableInterrupt
 */
#define DL_TamperIO_disableInterrupt                        DL_LFSS_TamperIO_disableInterrupt

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getEnabledInterrupts
 */
#define DL_TamperIO_getEnabledInterrupts                    DL_LFSS_TamperIO_getEnabledInterrupts

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getEnabledInterruptStatus
 */
#define DL_TamperIO_getEnabledInterruptStatus               DL_LFSS_TamperIO_getEnabledInterruptStatus

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getRawInterruptStatus
 */
#define DL_TamperIO_getRawInterruptStatus                   DL_LFSS_TamperIO_getRawInterruptStatus

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getPendingInterrupt
 */
#define DL_TamperIO_getPendingInterrupt                     DL_LFSS_TamperIO_getPendingInterrupt

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_clearInterruptStatus
 */
#define DL_TamperIO_clearInterruptStatus                    DL_LFSS_TamperIO_clearInterruptStatus

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_enableEvent
 */
#define DL_TamperIO_enableEvent                             DL_LFSS_TamperIO_enableEvent

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_disableEvent
 */
#define DL_TamperIO_disableEvent                            DL_LFSS_TamperIO_disableEvent

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getEnabledEvents
 */
#define DL_TamperIO_getEnabledEvents                        DL_LFSS_TamperIO_getEnabledEvents

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getEnabledEventStatus
 */
#define DL_TamperIO_getEnabledEventStatus                   DL_LFSS_TamperIO_getEnabledEventStatus

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getRawEventsStatus
 */
#define DL_TamperIO_getRawEventsStatus                      DL_LFSS_TamperIO_getRawEventsStatus

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_clearEventsStatus
 */
#define DL_TamperIO_clearEventsStatus                       DL_LFSS_TamperIO_clearEventsStatus

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_setPublisherChanID
 */
#define DL_TamperIO_setPublisherChanID                    DL_LFSS_TamperIO_setPublisherChanID

/*!
 * @brief Redirects to common @ref DL_LFSS_TamperIO_getPublisherChanID
 */
#define DL_TamperIO_getPublisherChanID                    DL_LFSS_TamperIO_getPublisherChanID

/* clang-format on */

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_TIO__ */

#endif /* ti_dl_dl_tio__include */
/** @}*/
