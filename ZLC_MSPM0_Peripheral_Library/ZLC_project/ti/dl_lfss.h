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
 * PURPOSE ARE DISCLAIMED. IN NO SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*!****************************************************************************
 *  @file       dl_lfss.h
 *  @brief      LFSS(Low Frequency Sub-System) Peripheral Interface
 *  @defgroup   LFSS Low Frequeuncy Sub-System (LFSS)
 *
 *  @anchor ti_devices_msp_dl_lfss_Overview
 *  # Overview
 *  The Low Frequency Sub-System (LFSS) Driver Library allows full configuration
 *  of the MSPM0 LFSS module.
 *  The LFSS IP enables a separate, dedicated battery supply used for
 *  maintaining continuous operation of real time clock (RTC), tamper detection
 *  input / output (TIO) module, an independent asynchronous watchdog timer
 *  (IWDT) and a small scratchpad memory storage (SPM).
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup LFSS
 * @{
 */
#ifndef ti_dl_dl_lfss__include
#define ti_dl_dl_lfss__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#if defined(__MSPM0_HAS_LFSS__) || defined(DOXYGEN__INCLUDE)

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */


/** @addtogroup DL_LFSS_TAMPERIO_INTERRUPT
 *  @{
 */

/**
 * @brief LFSS Tamper IO 0 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_0                   (LFSS_CPU_INT_IMASK_TIO0_SET)

/**
 * @brief LFSS Tamper IO 1 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_1                   (LFSS_CPU_INT_IMASK_TIO1_SET)

/**
 * @brief LFSS Tamper IO 2 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_2                   (LFSS_CPU_INT_IMASK_TIO2_SET)

/**
 * @brief LFSS Tamper IO 3 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_3                   (LFSS_CPU_INT_IMASK_TIO3_SET)

/**
 * @brief LFSS Tamper IO 4 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_4                   (LFSS_CPU_INT_IMASK_TIO4_SET)

/**
 * @brief LFSS Tamper IO 5 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_5                   (LFSS_CPU_INT_IMASK_TIO6_SET)

/**
 * @brief LFSS Tamper IO 6 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_6                   (LFSS_CPU_INT_IMASK_TIO6_SET)

/**
 * @brief LFSS Tamper IO 7 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_7                   (LFSS_CPU_INT_IMASK_TIO7_SET)

/**
 * @brief LFSS Tamper IO 8 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_8                   (LFSS_CPU_INT_IMASK_TIO8_SET)

/**
 * @brief LFSS Tamper IO 9 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_9                   (LFSS_CPU_INT_IMASK_TIO9_SET)

/**
 * @brief LFSS Tamper IO 10 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_10                   (LFSS_CPU_INT_IMASK_TIO10_SET)

/**
 * @brief LFSS Tamper IO 11 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_11                   (LFSS_CPU_INT_IMASK_TIO11_SET)

/**
 * @brief LFSS Tamper IO 12 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_12                   (LFSS_CPU_INT_IMASK_TIO12_SET)

/**
 * @brief LFSS Tamper IO 13 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_13                   (LFSS_CPU_INT_IMASK_TIO13_SET)

/**
 * @brief LFSS Tamper IO 14 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_14                   (LFSS_CPU_INT_IMASK_TIO14_SET)

/**
 * @brief LFSS Tamper IO 15 interrupt
 */
#define DL_LFSS_TAMPERIO_INTERRUPT_TAMPERIO_15                   (LFSS_CPU_INT_IMASK_TIO15_SET)

/** @}*/

/** @addtogroup DL_LFSS_TAMPERIO_EVENT
 *  @{
 */
/**
 * @brief LFSS Tamper IO 0 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_0                   (LFSS_GEN_EVENT_IMASK_TIO0_SET)

/**
 * @brief LFSS Tamper IO 1 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_1                   (LFSS_GEN_EVENT_IMASK_TIO1_SET)

/**
 * @brief LFSS Tamper IO 2 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_2                   (LFSS_GEN_EVENT_IMASK_TIO2_SET)

/**
 * @brief LFSS Tamper IO 3 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_3                   (LFSS_GEN_EVENT_IMASK_TIO3_SET)

/**
 * @brief LFSS Tamper IO 4 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_4                   (LFSS_GEN_EVENT_IMASK_TIO4_SET)

/**
 * @brief LFSS Tamper IO 5 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_5                   (LFSS_GEN_EVENT_IMASK_TIO5_SET)

/**
 * @brief LFSS Tamper IO 6 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_6                   (LFSS_GEN_EVENT_IMASK_TIO6_SET)

/**
 * @brief LFSS Tamper IO 7 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_7                   (LFSS_GEN_EVENT_IMASK_TIO7_SET)

/**
 * @brief LFSS Tamper IO 8 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_8                   (LFSS_GEN_EVENT_IMASK_TIO8_SET)

/**
 * @brief LFSS Tamper IO 9 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_9                   (LFSS_GEN_EVENT_IMASK_TIO9_SET)

/**
 * @brief LFSS Tamper IO 10 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_10                   (LFSS_GEN_EVENT_IMASK_TIO10_SET)

/**
 * @brief LFSS Tamper IO 11 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_11                   (LFSS_GEN_EVENT_IMASK_TIO11_SET)

/**
 * @brief LFSS Tamper IO 12 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_12                   (LFSS_GEN_EVENT_IMASK_TIO12_SET)

/**
 * @brief LFSS Tamper IO 13 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_13                   (LFSS_GEN_EVENT_IMASK_TIO13_SET)

/**
 * @brief LFSS Tamper IO 14 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_14                   (LFSS_GEN_EVENT_IMASK_TIO14_SET)

/**
 * @brief LFSS Tamper IO 15 event
 */
#define DL_LFSS_TAMPERIO_EVENT_TAMPERIO_15                   (LFSS_GEN_EVENT_IMASK_TIO15_SET)

/** @}*/

/**
 * @brief Individual Tamper IO pin enable
 */
#define LFSS_TAMPER_IO_PIN_ENABLE 0x1

/**
 * @brief Individual Tamper IO pin mask
 */
#define LFSS_TAMPER_IO_PIN_MASK 0x1

/*! @enum DL_LFSS_TAMPERIO */
typedef enum {
    /*! LFSS Tamper IO 0 */
    DL_LFSS_TAMPERIO_0 = 0x0000,
    /*! LFSS Tamper IO 1 */
    DL_LFSS_TAMPERIO_1 = 0x0001,
    /*! LFSS Tamper IO 2 */
    DL_LFSS_TAMPERIO_2 = 0x0002,
    /*! LFSS Tamper IO 3 */
    DL_LFSS_TAMPERIO_3 = 0x0003,
    /*! LFSS Tamper IO 4 */
    DL_LFSS_TAMPERIO_4 = 0x0004,
    /*! LFSS Tamper IO 5 */
    DL_LFSS_TAMPERIO_5 = 0x0005,
    /*! LFSS Tamper IO 6 */
    DL_LFSS_TAMPERIO_6 = 0x0006,
    /*! LFSS Tamper IO 7 */
    DL_LFSS_TAMPERIO_7 = 0x0007,
    /*! LFSS Tamper IO 8 */
    DL_LFSS_TAMPERIO_8 = 0x0008,
    /*! LFSS Tamper IO 9 */
    DL_LFSS_TAMPERIO_9 = 0x0009,
    /*! LFSS Tamper IO 10 */
    DL_LFSS_TAMPERIO_10 = 0x000A,
    /*! LFSS Tamper IO 11 */
    DL_LFSS_TAMPERIO_11 = 0x000B,
    /*! LFSS Tamper IO 12 */
    DL_LFSS_TAMPERIO_12 = 0x000C,
    /*! LFSS Tamper IO 13 */
    DL_LFSS_TAMPERIO_13 = 0x000D,
    /*! LFSS Tamper IO 14 */
    DL_LFSS_TAMPERIO_14 = 0x000E,
    /*! LFSS Tamper IO 15 */
    DL_LFSS_TAMPERIO_15 = 0x000F,
} DL_LFSS_TAMPERIO;

/*! @enum DL_LFSS_TAMPERIO_VALUE */
typedef enum {
    /*! LFSS Tamper IO Value is 0 */
    DL_LFSS_TAMPERIO_VALUE_0 = 0x00000,
    /*! LFSS Tamper IO Value is 1 */
    DL_LFSS_TAMPERIO_VALUE_1 = 0x0001,
} DL_LFSS_TAMPERIO_VALUE;

/*! @enum DL_LFSS_TAMPERIO_OUTPUT_SOURCE */
typedef enum {
    /*! The TOUT register is the source for the tamper output (TOUT) control */
    DL_LFSS_TAMPERIO_OUTPUT_SOURCE_TOUT = LFSS_TIOCTL_TOUTSEL_TOUT,
    /*! LFCLK is the source for the tamper output (TOUT) control */
    DL_LFSS_TAMPERIO_OUTPUT_SOURCE_LFCLK = LFSS_TIOCTL_TOUTSEL_LFCLKEXT,
    /*! The heart beat generator is the source for the tamper output (TOUT)
     *  control */
    DL_LFSS_TAMPERIO_OUTPUT_SOURCE_HEARTBEAT = LFSS_TIOCTL_TOUTSEL_HEARTBEAT,
    /*! The time stamp event is the source for the tamper output (TOUT)
     *  control */
    DL_LFSS_TAMPERIO_OUTPUT_SOURCE_TIME_STAMP_EVENT = LFSS_TIOCTL_TOUTSEL_TSEVTSTAT,
} DL_LFSS_TAMPERIO_OUTPUT_SOURCE;

/*! @enum DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH */
typedef enum {
    /*! No filtering on the Tamper IO beyond CDS synchronization sample */
    DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_NONE = LFSS_TIOCTL_FILTEREN_NO_FLT,
    /*! Pulses on the Tamper IO less than 30us are filtered */
    DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_30_USEC = LFSS_TIOCTL_FILTEREN_FLT_1,
    /*! Pulses on the Tamper IO less than 100us are filtered */
    DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_100_USEC = LFSS_TIOCTL_FILTEREN_FLT_2,
    /*! Pulses on the Tamper IO less than 200us are filtered */
    DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH_200_USEC = LFSS_TIOCTL_FILTEREN_FLT_3,
} DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH;

/*! @enum DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY */
typedef enum {
    /*! Edge detection polarity is disabled */
    DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_DISABLE = LFSS_TIOCTL_POLARITY_DISABLE,
    /*! Enables rising edge detection of input event */
    DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_RISE = LFSS_TIOCTL_POLARITY_RISE,
    /*! Enables falling edge detection of input event */
    DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_FALL = LFSS_TIOCTL_POLARITY_FALL,
    /*! Enables both rising and falling edge detection of input event */
    DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY_BOTH = LFSS_TIOCTL_POLARITY_BOTH,

} DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY;

/*! @enum DL_LFSS_TAMPERIO_MODE */
typedef enum {
    /*! The Tamper IO is set to tamper mode */
    DL_LFSS_TAMPERIO_MODE_TAMPER = LFSS_TIOCTL_IOMUX_TAMPER,
    /*! The Tamper IO is set to IOMUX mode */
    DL_LFSS_TAMPERIO_MODE_IOMUX = LFSS_TIOCTL_IOMUX_IOMUX
} DL_LFSS_TAMPERIO_MODE;

/*! @enum DL_LFSS_HEARTBEAT_INTERVAL */
typedef enum {
    /*! Heart beat generator interval is 0.125 sec */
    DL_LFSS_HEARTBEAT_INTERVAL_0_125_SEC = LFSS_HEARTBEAT_HBINTERVAL_HBINT0P125,
    /*! Heart beat generator interval is 0.25 sec */
    DL_LFSS_HEARTBEAT_INTERVAL_0_25_SEC = LFSS_HEARTBEAT_HBINTERVAL_HBINT0P25,
    /*! Heart beat generator interval is 0.5 sec */
    DL_LFSS_HEARTBEAT_INTERVAL_05_SEC = LFSS_HEARTBEAT_HBINTERVAL_HBINT0P5,
    /*! Heart beat generator interval is 1 sec */
    DL_LFSS_HEARTBEAT_INTERVAL_1_SEC = LFSS_HEARTBEAT_HBINTERVAL_HBINT1,
    /*! Heart beat generator interval is 2 sec */
    DL_LFSS_HEARTBEAT_INTERVAL_2_SEC = LFSS_HEARTBEAT_HBINTERVAL_HBINT2,
    /*! Heart beat generator interval is 4 sec */
    DL_LFSS_HEARTBEAT_INTERVAL_4_SEC = LFSS_HEARTBEAT_HBINTERVAL_HBINT4,
    /*! Heart beat generator interval is 8 sec */
    DL_LFSS_HEARTBEAT_INTERVAL_8_SEC = LFSS_HEARTBEAT_HBINTERVAL_HBINT8,
    /*! Heart beat generator interval is 16 sec */
    DL_LFSS_HEARTBEAT_INTERVAL_16_SEC = LFSS_HEARTBEAT_HBINTERVAL_HBINT16,
} DL_LFSS_HEARTBEAT_INTERVAL;

/*! @enum DL_LFSS_HEARTBEAT_PULSE_WIDTH */
typedef enum {
    /*! Heart beat generator pulse width is 1 msec */
    DL_LFSS_HEARTBEAT_PULSE_WIDTH_1_MSEC = LFSS_HEARTBEAT_HBWIDTH_HBPWDTH1,
    /*! Heart beat generator pulse width is 2 msec */
    DL_LFSS_HEARTBEAT_PULSE_WIDTH_2_MSEC = LFSS_HEARTBEAT_HBWIDTH_HBPWDTH2,
    /*! Heart beat generator pulse width is 4 msec */
    DL_LFSS_HEARTBEAT_PULSE_WIDTH_4_MSEC = LFSS_HEARTBEAT_HBWIDTH_HBPWDTH4,
    /*! Heart beat generator pulse width is 8 msec */
    DL_LFSS_HEARTBEAT_PULSE_WIDTH_8_MSEC = LFSS_HEARTBEAT_HBWIDTH_HBPWDTH8,
    /*! Heart beat generator pulse width is 16 msec */
    DL_LFSS_HEARTBEAT_PULSE_WIDTH_16_MSEC = LFSS_HEARTBEAT_HBWIDTH_HBPWDTH16,
    /*! Heart beat generator pulse width is 32 msec */
    DL_LFSS_HEARTBEAT_PULSE_WIDTH_32_MSEC = LFSS_HEARTBEAT_HBWIDTH_HBPWDTH32,
    /*! Heart beat generator pulse width is 64 msec */
    DL_LFSS_HEARTBEAT_PULSE_WIDTH_64_MSEC = LFSS_HEARTBEAT_HBWIDTH_HBPWDTH64,
    /*! Heart beat generator pulse width is 128 msec */
    DL_LFSS_HEARTBEAT_PULSE_WIDTH_128_MSEC = LFSS_HEARTBEAT_HBWIDTH_HBPWDTH128,
} DL_LFSS_HEARTBEAT_PULSE_WIDTH;

/*! @enum DL_LFSS_HEARTBEAT_MODE */
typedef enum {
    /*! Heart beat generator mode is disabled */
    DL_LFSS_HEARTBEAT_MODE_DISABLED = LFSS_HEARTBEAT_HBMODE_HB_DIS,
    /*! Heart beat generator mode is always enabled */
    DL_LFSS_HEARTBEAT_MODE_ALWAYS_ON = LFSS_HEARTBEAT_HBMODE_HB_ALLWAYS,
    /*! Heart beat generator mode is enabled when time stamp event is detected */
    DL_LFSS_HEARTBEAT_MODE_TIME_STAMP = LFSS_HEARTBEAT_HBMODE_HB_TS,
    /*! Heart beat generator mode is enabled when the main power supply fails */
    DL_LFSS_HEARTBEAT_MODE_POWER_FAIL = LFSS_HEARTBEAT_HBMODE_HB_VDDFAIL,
} DL_LFSS_HEARTBEAT_MODE;

/*! @enum DL_LFSS_TAMPERIO_IIDX */
typedef enum {
    /*! LFSS Tamper interrupt index for Tamper IO 0 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_0 = LFSS_CPU_INT_IIDX_STAT_TIO0,
    /*! LFSS Tamper interrupt index for Tamper IO 1 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_1 = LFSS_CPU_INT_IIDX_STAT_TIO1,
    /*! LFSS Tamper interrupt index for Tamper IO 2 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_2 = LFSS_CPU_INT_IIDX_STAT_TIO2,
    /*! LFSS Tamper interrupt index for Tamper IO 3 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_3 = LFSS_CPU_INT_IIDX_STAT_TIO3,
    /*! LFSS Tamper interrupt index for Tamper IO 4 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_4 = LFSS_CPU_INT_IIDX_STAT_TIO4,
    /*! LFSS Tamper interrupt index for Tamper IO 5 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_5 = LFSS_CPU_INT_IIDX_STAT_TIO5,
    /*! LFSS Tamper interrupt index for Tamper IO 6 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_6 = LFSS_CPU_INT_IIDX_STAT_TIO6,
    /*! LFSS Tamper interrupt index for Tamper IO 7 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_7 = LFSS_CPU_INT_IIDX_STAT_TIO7,
    /*! LFSS Tamper interrupt index for Tamper IO 8 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_8 = LFSS_CPU_INT_IIDX_STAT_TIO8,
    /*! LFSS Tamper interrupt index for Tamper IO 9 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_9 = LFSS_CPU_INT_IIDX_STAT_TIO9,
    /*! LFSS Tamper interrupt index for Tamper IO 10 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_10 = LFSS_CPU_INT_IIDX_STAT_TIO10,
    /*! LFSS Tamper interrupt index for Tamper IO 11 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_11 = LFSS_CPU_INT_IIDX_STAT_TIO11,
    /*! LFSS Tamper interrupt index for Tamper IO 12 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_12 = LFSS_CPU_INT_IIDX_STAT_TIO12,
    /*! LFSS Tamper interrupt index for Tamper IO 13 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_13 = LFSS_CPU_INT_IIDX_STAT_TIO13,
    /*! LFSS Tamper interrupt index for Tamper IO 14 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_14 = LFSS_CPU_INT_IIDX_STAT_TIO14,
    /*! LFSS Tamper interrupt index for Tamper IO 15 */
    DL_LFSS_TAMPERIO_IIDX_TAMPER_IO_15 = LFSS_CPU_INT_IIDX_STAT_TIO15,
} DL_LFSS_TAMPERIO_IIDX;

/*! @enum DL_LFSS_SCRATCHPAD_MEM_WORD */
typedef enum {
    /*! LFSS Scratch Pad memory word 0 */
    DL_LFSS_SCRATCHPAD_MEM_WORD_0 = 0x0000,
    /*! LFSS Scratch Pad memory word 1 */
    DL_LFSS_SCRATCHPAD_MEM_WORD_1 = 0x0001,
    /*! LFSS Scratch Pad memory word 2 */
    DL_LFSS_SCRATCHPAD_MEM_WORD_2 = 0x0002,
    /*! LFSS Scratch Pad memory word 3 */
    DL_LFSS_SCRATCHPAD_MEM_WORD_3 = 0x0003,
    /*! LFSS Scratch Pad memory word 4 */
    DL_LFSS_SCRATCHPAD_MEM_WORD_4 = 0x0004,
    /*! LFSS Scratch Pad memory word 5 */
    DL_LFSS_SCRATCHPAD_MEM_WORD_5 = 0x0005,
    /*! LFSS Scratch Pad memory word 6 */
    DL_LFSS_SCRATCHPAD_MEM_WORD_6 = 0x0006,
    /*! LFSS Scratch Pad memory word 7 */
    DL_LFSS_SCRATCHPAD_MEM_WORD_7 = 0x0007,
} DL_LFSS_SCRATCHPAD_MEM_WORD;

/*! @enum DL_LFSS_SCRATCHPAD_MEM_BYTE */
typedef enum {
    /*! LFSS Scratch Pad memory byte 0 of the given Scratch Pad memory word */
    DL_LFSS_SCRATCHPAD_MEM_BYTE_0 = 0x0000,
    /*! LFSS Scratch Pad memory byte 1 of the given Scratch Pad memory word */
    DL_LFSS_SCRATCHPAD_MEM_BYTE_1 = 0x0001,
    /*! LFSS Scratch Pad memory byte 2 of the given Scratch Pad memory word */
    DL_LFSS_SCRATCHPAD_MEM_BYTE_2 = 0x0002,
    /*! LFSS Scratch Pad memory byte 3 of the given Scratch Pad memory word */
    DL_LFSS_SCRATCHPAD_MEM_BYTE_3 = 0x0003,
} DL_LFSS_SCRATCHPAD_MEM_BYTE;

/*! @enum DL_LFSS_IWDT_CLOCK_DIVIDE */
typedef enum {
    /*! WDT Clock divide by 1 */
    DL_LFSS_IWDT_CLOCK_DIVIDE_1 = 0x00000000,
    /*! WDT Clock divide by 2 */
    DL_LFSS_IWDT_CLOCK_DIVIDE_2 = 0x00000001,
    /*! WDT Clock divide by 3 */
    DL_LFSS_IWDT_CLOCK_DIVIDE_3 = 0x00000002,
    /*! WDT Clock divide by 4 */
    DL_LFSS_IWDT_CLOCK_DIVIDE_4 = 0x00000003,
    /*! WDT Clock divide by 5 */
    DL_LFSS_IWDT_CLOCK_DIVIDE_5 = 0x00000004,
    /*! WDT Clock divide by 6 */
    DL_LFSS_IWDT_CLOCK_DIVIDE_6 = 0x00000005,
    /*! WDT Clock divide by 7 */
    DL_LFSS_IWDT_CLOCK_DIVIDE_7 = 0x00000006,
    /*! WDT Clock divide by 8 */
    DL_LFSS_IWDT_CLOCK_DIVIDE_8 = 0x00000007
} DL_LFSS_IWDT_CLOCK_DIVIDE;

/*! @enum DL_LFSS_IWDT_TIMER_PERIOD */
typedef enum {
    /*! WDT 2^6 timer period count */
    DL_LFSS_IWDT_TIMER_PERIOD_6_BITS = LFSS_WDTCTL_PER_PER_EN_6,
    /*! WDT 2^8 timer period count */
    DL_LFSS_IWDT_TIMER_PERIOD_8_BITS = LFSS_WDTCTL_PER_PER_EN_8,
    /*! WDT 2^10 timer period count */
    DL_LFSS_IWDT_TIMER_PERIOD_10_BITS = LFSS_WDTCTL_PER_PER_EN_10,
    /*! WDT 2^12 timer period count */
    DL_LFSS_IWDT_TIMER_PERIOD_12_BITS = LFSS_WDTCTL_PER_PER_EN_12,
    /*! WDT 2^15 timer period count */
    DL_LFSS_IWDT_TIMER_PERIOD_15_BITS = LFSS_WDTCTL_PER_PER_EN_15,
    /*! WDT 2^18 timer period count */
    DL_LFSS_IWDT_TIMER_PERIOD_18_BITS = LFSS_WDTCTL_PER_PER_EN_18,
    /*! WDT 2^21 timer period count */
    DL_LFSS_IWDT_TIMER_PERIOD_21_BITS = LFSS_WDTCTL_PER_PER_EN_21,
    /*! WDT 2^25 timer period count */
    DL_LFSS_IWDT_TIMER_PERIOD_25_BITS = LFSS_WDTCTL_PER_PER_EN_25
} DL_LFSS_IWDT_TIMER_PERIOD;

/* clang-format on */

/**
 *  @brief      Enable output inversion for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_enableOutputInversion(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] |=
        LFSS_TIOCTL_OUTINV_ENABLE;
}

/**
 *  @brief      Checks if output inversion is enabled for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 *
 *  @return     Returns if output inversion is enabled
 *
 *  @retval     true  Output inversion for the Tamper I/O is enabled
 *  @retval     false Output inversion for the Tamper I/O is disabled
 */
__STATIC_INLINE bool DL_LFSS_TamperIO_isOutputInversionEnabled(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    return ((lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &
                LFSS_TIOCTL_OUTINV_MASK) == LFSS_TIOCTL_OUTINV_ENABLE);
}

/**
 *  @brief      Disable output inversion for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 */
__STATIC_INLINE void DL_LFSS_TamperIO_disableOutputInversion(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &=
        ~(LFSS_TIOCTL_OUTINV_MASK);
}

/**
 *  @brief      Selects the source for the tamper output (TOUT) control for
 *              the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 *  @param[in]  source    The source for the tamper output control.
 *                        One of @ref DL_LFSS_TAMPERIO_OUTPUT_SOURCE.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_setOutputSource(LFSS_Regs *lfss,
    DL_LFSS_TAMPERIO tamperIO, DL_LFSS_TAMPERIO_OUTPUT_SOURCE source)
{
    DL_Common_updateReg(&lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO],
        (uint32_t) source, LFSS_TIOCTL_TOUTSEL_MASK);
}

/**
 *  @brief      Gets the source for the tamper output (TOUT) control for
 *              the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO.
 *                        One of @ref DL_LFSS_TAMPERIO
 *
 *  @return     The output source of the tamper IO
 *
 *  @retval     One of @ref DL_LFSS_TAMPERIO_OUTPUT_SOURCE
 */
__STATIC_INLINE DL_LFSS_TAMPERIO_OUTPUT_SOURCE
DL_LFSS_TamperIO_getOutputSource(LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    return ((DL_LFSS_TAMPERIO_OUTPUT_SOURCE)(
        lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &
        LFSS_TIOCTL_TOUTSEL_MASK));
}

/**
 *  @brief      Selects the filter width for the digital glitch filter for
 *              the specified Tamper IO
 *
 *  The tamper event detection allows to configure one or more tamper IO’s to
 *  trigger a timestamp event and to generate an interrupt to the CPU. To
 *  minimize false triggers, a digital filter circuit is inserted into the IO
 *  path. Only pulses that are longer than the configured filter width will be
 *  registered as a tamper event.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 *  @param[in]  width     The width of the digital glitch filter. Pulses
 *                        smaller than this width will be filtered.
 *                        One of @ref DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_setGlitchFilterWidth(LFSS_Regs *lfss,
    DL_LFSS_TAMPERIO tamperIO, DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH width)
{
    DL_Common_updateReg(&lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO],
        (uint32_t) width, LFSS_TIOCTL_FILTEREN_MASK);
}

/**
 *  @brief      Gets the filter width for the digital glitch filter for
 *              the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO.
 *                        One of @ref DL_LFSS_TAMPERIO
 *
 *  @return     The digital glitch filter width
 *
 *  @retval     One of @ref DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH
 */
__STATIC_INLINE DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH
DL_LFSS_TamperIO_getGlitchFilterWidth(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    return ((DL_LFSS_TAMPERIO_GLITCH_FILTER_WIDTH)(
        lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &
        LFSS_TIOCTL_FILTEREN_MASK));
}

/**
 *  @brief      Selects the edge detection polarity for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 *  @param[in]  polarity  The edge detection polarity.
 *                        One of @ref DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_setEdgeDetectionPolarity(LFSS_Regs *lfss,
    DL_LFSS_TAMPERIO tamperIO,
    DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY polarity)
{
    DL_Common_updateReg(&lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO],
        (uint32_t) polarity, LFSS_TIOCTL_POLARITY_MASK);
}

/**
 *  @brief      Gets the edge detection polarity for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO.
 *                        One of @ref DL_LFSS_TAMPERIO
 *
 *  @return     The edge detection polarity for the specified Tamper IO
 *
 *  @retval     One of @ref DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY
 */
__STATIC_INLINE DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY
DL_LFSS_TamperIO_getEdgeDetectionPolarity(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    return ((DL_LFSS_TAMPERIO_EDGE_DETECTION_POLARITY)(
        lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &
        LFSS_TIOCTL_POLARITY_MASK));
}

/**
 *  @brief      Enable internal pull-up resistor for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_enableInternalPullUp(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] |=
        LFSS_TIOCTL_PIPU_ENABLE;
}

/**
 *  @brief      Checks if internal pull-up resistor is enabled for the specified
 *              Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 *
 *  @return     Returns the internal pull-up resistor enabled status
 *
 *  @retval     true  Internal pull-up resistor for the Tamper I/O is enabled
 *  @retval     false Internal pull-up resistor for the Tamper I/O is disabled
 */
__STATIC_INLINE bool DL_LFSS_TamperIO_isInternalPullUpEnabled(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    return ((lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &
                LFSS_TIOCTL_PIPU_MASK) == LFSS_TIOCTL_PIPU_ENABLE);
}

/**
 *  @brief      Disable internal pull-up resistor for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 */
__STATIC_INLINE void DL_LFSS_TamperIO_disableInternalPullUp(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &=
        ~(LFSS_TIOCTL_PIPU_MASK);
}

/**
 *  @brief      Enable internal pull-down resistor for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_enableInternalPullDown(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] |=
        LFSS_TIOCTL_PIPD_ENABLE;
}

/**
 *  @brief      Checks if internal pull-down resistor is enabled for the specified
 *              Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 *
 *  @return     Returns the internal pull-down resistor enabled status
 *
 *  @retval     true  Internal pull-down resistor for the Tamper I/O is enabled
 *  @retval     false Internal pull-down resistor for the Tamper I/O is disabled
 */
__STATIC_INLINE bool DL_LFSS_TamperIO_isInternalPullDownEnabled(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    return ((lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &
                LFSS_TIOCTL_PIPD_MASK) == LFSS_TIOCTL_PIPD_ENABLE);
}

/**
 *  @brief      Disable internal pull-down resistor for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 */
__STATIC_INLINE void DL_LFSS_TamperIO_disableInternalPullDown(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &=
        ~(LFSS_TIOCTL_PIPD_MASK);
}

/**
 *  @brief      Enable input path for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_enableInput(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] |=
        LFSS_TIOCTL_INENA_ENABLE;
}

/**
 *  @brief      Checks if input is enabled for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 *
 *  @return     Returns the input enabled status
 *
 *  @retval     true  Input for the Tamper I/O is enabled
 *  @retval     false Input for the Tamper I/O is disabled
 */
__STATIC_INLINE bool DL_LFSS_TamperIO_isInputEnabled(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    return ((lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &
                LFSS_TIOCTL_INENA_MASK) == LFSS_TIOCTL_INENA_ENABLE);
}

/**
 *  @brief      Disable input path for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 */
__STATIC_INLINE void DL_LFSS_TamperIO_disableInput(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &=
        ~(LFSS_TIOCTL_INENA_MASK);
}

/**
 *  @brief      Selects the mode for the specified Tamper IO
 *
 * The tamper IOs have two modes of operation:
 *     - In IOMUX mode (@ref DL_LFSS_TAMPERIO_MODE_IOMUX), the tamper IO input
 *         and output path are connected to the SoC IOMUX module and the IO can
 *         be used as a second function.
 *     - In tamper mode (@ref DL_LFSS_TAMPERIO_MODE_TAMPER), the tamper IO is
 *         completely controlled by the VBAT IP and will remain functional
 *         during the power loss of the main supply or during SHUTDOWN mode.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO to configure.
 *                        One of @ref DL_LFSS_TAMPERIO
 *  @param[in]  mode      The mode for the specified tamper IO.
 *                        One of @ref DL_LFSS_TAMPERIO_MODE.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_setMode(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO, DL_LFSS_TAMPERIO_MODE mode)
{
    DL_Common_updateReg(&lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO],
        (uint32_t) mode, LFSS_TIOCTL_IOMUX_MASK);
}

/**
 *  @brief      Gets the mode for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO.
 *                        One of @ref DL_LFSS_TAMPERIO
 *
 *  @return     The mode for the specified Tamper IO
 *
 *  @retval     One of @ref DL_LFSS_TAMPERIO_MODE
 */
__STATIC_INLINE DL_LFSS_TAMPERIO_MODE DL_LFSS_TamperIO_getMode(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    return ((DL_LFSS_TAMPERIO_MODE)(
        lfss->IPSPECIFIC_TIO.TIOCTL[(uint32_t) tamperIO] &
        LFSS_TIOCTL_IOMUX_MASK));
}

/**
 *  @brief      Enable data output for the specified Tamper IO
 *
 *  @param[in]  lfss       Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO   Specifies the tamper IO to configure.
 *                         One of @ref DL_LFSS_TAMPERIO.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_enableOutput(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_TIO.TOE3_0;

    /* Point to correct TOE register */
    pReg = (uint32_t *) ((uint8_t *) pReg + (uint8_t) tamperIO);

    /* Set just the one bit for the specified tamper IO */
    *pReg |= LFSS_TAMPER_IO_PIN_ENABLE;
}

/**
 *  @brief      Disable data output for the specified Tamper IO
 *
 *  @param[in]  lfss       Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO   Specifies the tamper IO to configure.
 *                         One of @ref DL_LFSS_TAMPERIO.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_disableOutput(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_TIO.TOE3_0;

    /* Point to correct TOE register */
    pReg = (uint32_t *) ((uint8_t *) pReg + (uint8_t) tamperIO);

    /* Clear just the one bit for the specified tamper IO */
    *pReg &= ~(LFSS_TAMPER_IO_PIN_ENABLE);
}

/**
 *  @brief      Checks if data output for the specified Tamper IO is enabled
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO.
 *                        One of @ref DL_LFSS_TAMPERIO
 *
 *  @return     If data output for the specified Tamper IO is enabled
 *
 *  @retval     true   Data output for the tamper IO is enabled
 *  @retval     false  Data output for the tamper IO is disabled
 */
__STATIC_INLINE uint32_t DL_LFSS_TamperIO_isOutputEnabled(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_TIO.TOE3_0;

    /* Point to correct TIOCTLx register */
    pReg = (uint32_t *) ((uint8_t *) pReg + (uint8_t) tamperIO);

    /* Get just the one bit for the specified tamper IO */
    return ((*pReg & LFSS_TAMPER_IO_PIN_MASK) == LFSS_TAMPER_IO_PIN_ENABLE);
}

/**
 *  @brief      Enable data output value as zero for the specified Tamper IO
 *
 *  @param[in]  lfss       Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO   Specifies the tamper IO to configure.
 *                         One of @ref DL_LFSS_TAMPERIO.
 *  @param[in]  outVal     The data value to set the tamper IO output to.
 *                         One of @ref DL_LFSS_TAMPERIO_VALUE.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_setOutputValue(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO, DL_LFSS_TAMPERIO_VALUE outVal)
{
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_TIO.TOUT3_0;

    /* Point to correct TOE register */
    pReg = (uint32_t *) ((uint8_t *) pReg + (uint8_t) tamperIO);

    DL_Common_updateReg(pReg, (uint32_t) outVal, LFSS_TAMPER_IO_PIN_MASK);
}

/**
 *  @brief      Gets the output data value for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO.
 *                        One of @ref DL_LFSS_TAMPERIO
 *
 *  @return     The output data value for the specified tamper IO
 *
 *  @retval     One of @ref DL_LFSS_TAMPERIO_VALUE
 */
__STATIC_INLINE DL_LFSS_TAMPERIO_VALUE DL_LFSS_TamperIO_getOutputValue(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_TIO.TOUT3_0;

    /* Point to correct TOE register */
    pReg = (uint32_t *) ((uint8_t *) pReg + (uint8_t) tamperIO);

    uint32_t outVal = *pReg & LFSS_TAMPER_IO_PIN_MASK;

    return (DL_LFSS_TAMPERIO_VALUE)(outVal);
}

/**
 *  @brief      Gets the input data value for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  tamperIO  Specifies the tamper IO.
 *                        One of @ref DL_LFSS_TAMPERIO
 *
 *  @return     The input data value for the specified tamper IO
 *
 *  @retval     One of @ref DL_LFSS_TAMPERIO_VALUE
 */
__STATIC_INLINE DL_LFSS_TAMPERIO_VALUE DL_LFSS_TamperIO_getInputValue(
    LFSS_Regs *lfss, DL_LFSS_TAMPERIO tamperIO)
{
    const volatile uint32_t *pReg = &lfss->IPSPECIFIC_TIO.TIN3_0;

    /* Point to correct TOE register */
    pReg = (uint32_t *) ((uint8_t *) pReg + (uint8_t) tamperIO);

    uint32_t inputVal = *pReg & LFSS_TAMPER_IO_PIN_MASK;

    return (DL_LFSS_TAMPERIO_VALUE)(inputVal);
}

/**
 *  @brief      Sets the interval for the heart beat generator
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  interval  The interval of the heart beat generator.
 *                        One of @ref DL_LFSS_HEARTBEAT_INTERVAL
 */
__STATIC_INLINE void DL_LFSS_TamperIO_setHeartBeatInterval(
    LFSS_Regs *lfss, DL_LFSS_HEARTBEAT_INTERVAL interval)
{
    DL_Common_updateReg(&lfss->IPSPECIFIC_TIO.HEARTBEAT, (uint32_t) interval,
        LFSS_HEARTBEAT_HBINTERVAL_MASK);
}

/**
 *  @brief      Gets the interval for the heart beat generator
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *
 *  @return     The interval for the heart beat generator.
 *
 *  @retval     One of @ref DL_LFSS_HEARTBEAT_INTERVAL
 */
__STATIC_INLINE DL_LFSS_HEARTBEAT_INTERVAL
DL_LFSS_TamperIO_getHeartBeatInterval(LFSS_Regs *lfss)
{
    uint32_t interval =
        lfss->IPSPECIFIC_TIO.HEARTBEAT & LFSS_HEARTBEAT_HBINTERVAL_MASK;

    return (DL_LFSS_HEARTBEAT_INTERVAL)(interval);
}

/**
 *  @brief      Sets the pulse width for the heart beat generator
 *
 *  @param[in]  lfss   Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  width  The pulse width of the heart beat generator.
 *                     One of @ref DL_LFSS_HEARTBEAT_PULSE_WIDTH
 */
__STATIC_INLINE void DL_LFSS_TamperIO_setHeartBeatPulseWidth(
    LFSS_Regs *lfss, DL_LFSS_HEARTBEAT_PULSE_WIDTH width)
{
    DL_Common_updateReg(&lfss->IPSPECIFIC_TIO.HEARTBEAT, (uint32_t) width,
        LFSS_HEARTBEAT_HBWIDTH_MASK);
}

/**
 *  @brief      Gets the pulse width for the heart beat generator
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *
 *  @return     The pulse width for the heart beat generator.
 *
 *  @retval     One of @ref DL_LFSS_HEARTBEAT_PULSE_WIDTH
 */
__STATIC_INLINE DL_LFSS_HEARTBEAT_PULSE_WIDTH
DL_LFSS_TamperIO_getHeartBeatPulseWidth(LFSS_Regs *lfss)
{
    uint32_t width =
        (lfss->IPSPECIFIC_TIO.HEARTBEAT & LFSS_HEARTBEAT_HBWIDTH_MASK);

    return (DL_LFSS_HEARTBEAT_PULSE_WIDTH)(width);
}

/**
 *  @brief      Sets the mode for the heart beat generator
 *
 *  @param[in]  lfss  Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  mode  The mode of the heart beat generator.
 *                    One of @ref DL_LFSS_HEARTBEAT_MODE
 */
__STATIC_INLINE void DL_LFSS_TamperIO_setHeartBeatMode(
    LFSS_Regs *lfss, DL_LFSS_HEARTBEAT_MODE mode)
{
    DL_Common_updateReg(&lfss->IPSPECIFIC_TIO.HEARTBEAT, (uint32_t) mode,
        LFSS_HEARTBEAT_HBMODE_MASK);
}

/**
 *  @brief      Gets the pulse mode for the heart beat generator
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *
 *  @return     The pulse mode for the heart beat generator.
 *
 *  @retval     One of @ref DL_LFSS_HEARTBEAT_MODE
 */
__STATIC_INLINE DL_LFSS_HEARTBEAT_MODE DL_LFSS_TamperIO_getHeartBeatMode(
    LFSS_Regs *lfss)
{
    uint32_t mode =
        (lfss->IPSPECIFIC_TIO.HEARTBEAT & LFSS_HEARTBEAT_HBMODE_MASK);

    return (DL_LFSS_HEARTBEAT_MODE)(mode);
}

/**
 *  @brief      Enable write protection lock of the TIOCTL and HEARTBEAT
 *              registers from accidental updates
 *
 *  When enabled, the TIOCTL and HEARTBEAT registers will have read-only access.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 */
__STATIC_INLINE void DL_LFSS_TamperIO_enableWriteProtectLock(LFSS_Regs *lfss)
{
    lfss->IPSPECIFIC_TIO.TIOLOCK =
        (LFSS_TIOLOCK_PROTECT_SET | LFSS_TIOLOCK_KEY_UNLOCK_W);
}

/**
 *  @brief      Checks if write protection lock of the TIOCTL and HEARTBEAT
 *              registers is enabled for the specified Tamper IO
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *
 *  @return     Returns the enabled status of the write protection lock
 *
 *  @retval     true  Write protection lock is enabled
 *  @retval     false Write protection lock is disabled
 */
__STATIC_INLINE bool DL_LFSS_TamperIO_isWriteProtectLockEnabled(
    LFSS_Regs *lfss)
{
    return ((lfss->IPSPECIFIC_TIO.TIOLOCK & LFSS_TIOLOCK_PROTECT_MASK) ==
            LFSS_TIOLOCK_PROTECT_SET);
}

/**
 *  @brief      Disable write protection lock of the TIOCTL and HEARTBEAT
 *              registers
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 */
__STATIC_INLINE void DL_LFSS_TamperIO_disableWriteProtectLock(LFSS_Regs *lfss)
{
    lfss->IPSPECIFIC_TIO.TIOLOCK =
        (LFSS_TIOLOCK_PROTECT_CLR | LFSS_TIOLOCK_KEY_UNLOCK_W);
}

/**
 * @brief Enables the Watchdog module
 *
 * @param lfss        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LFSS_IWDT_enableModule(LFSS_Regs *lfss)
{
    lfss->IPSPECIFIC_WDT.WDTEN =
        (LFSS_WDTEN_KEY_UNLOCK_W | LFSS_WDTEN_ENABLE_SET);
}

/**
 * @brief Disables the Watchdog module
 *
 * @param lfss        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LFSS_IWDT_disableModule(LFSS_Regs *lfss)
{
    lfss->IPSPECIFIC_WDT.WDTEN =
        (LFSS_WDTEN_KEY_UNLOCK_W | LFSS_WDTEN_ENABLE_CLR);
}

/**
 * @brief Returns if Watchdog module is on
 *
 * @param lfss        Pointer to the register overlay for the peripheral
 *
 * @return true  Watchdog is enabled
 * @return false Watchdog is disabled
 */
__STATIC_INLINE bool DL_LFSS_IWDT_isModuleEnabled(LFSS_Regs *lfss)
{
    return ((lfss->IPSPECIFIC_WDT.WDTEN & LFSS_WDTEN_ENABLE_MASK) ==
            LFSS_WDTEN_ENABLE_SET);
}

/**
 * @brief Enables the Watchdog free run control
 *
 *  When enabled, the Watchdog will continue to free run and ignores the state
 *  of the CPU halted debug state
 *
 * @param lfss        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LFSS_IWDT_enableFreeRun(LFSS_Regs *lfss)
{
    lfss->IPSPECIFIC_WDT.WDTDBGCTL = LFSS_WDTDBGCTL_FREE_RUN;
}

/**
 * @brief Disables the Watchdog free run control
 *
 * @param lfss        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LFSS_IWDT_disableFreeRun(LFSS_Regs *lfss)
{
    lfss->IPSPECIFIC_WDT.WDTDBGCTL = LFSS_WDTDBGCTL_FREE_STOP;
}

/**
 * @brief Returns if Watchdog free run control is enabled
 *
 * @param lfss        Pointer to the register overlay for the peripheral
 *
 * @return true  Watchdog free run control is enabled
 * @return false Watchdog free run control is disabled
 */
__STATIC_INLINE bool DL_LFSS_IWDT_isFreeRunEnabled(LFSS_Regs *lfss)
{
    return ((lfss->IPSPECIFIC_WDT.WDTDBGCTL & LFSS_WDTDBGCTL_FREE_MASK) ==
            LFSS_WDTDBGCTL_FREE_RUN);
}

/**
 *  @brief      Sets the clock divider for the WDT module
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  divider   The WDT clock divider to set.
 *                        One of @ref DL_LFSS_IWDT_CLOCK_DIVIDE.
 */
__STATIC_INLINE void DL_LFSS_IWDT_setClockDivider(
    LFSS_Regs *lfss, DL_LFSS_IWDT_CLOCK_DIVIDE divider)
{
    DL_Common_updateReg(&lfss->IPSPECIFIC_WDT.WDTCTL,
        ((uint32_t) divider | LFSS_WDTCTL_KEY_UNLOCK_W),
        LFSS_WDTCTL_CLKDIV_MASK | LFSS_WDTCTL_KEY_MASK);
}

/**
 *  @brief      Gets the clock divider for the WDT module
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *
 *  @return     The clock divider for the WDT module
 *
 *  @retval     One of @ref DL_LFSS_IWDT_CLOCK_DIVIDE
 */
__STATIC_INLINE DL_LFSS_IWDT_CLOCK_DIVIDE DL_LFSS_IWDT_getClockDivider(
    LFSS_Regs *lfss)
{
    uint32_t divider =
        (lfss->IPSPECIFIC_WDT.WDTCTL & LFSS_WDTCTL_CLKDIV_MASK) + (uint32_t) 1;

    return (DL_LFSS_IWDT_CLOCK_DIVIDE)(divider);
}

/**
 *  @brief      Sets the timer period for the WDT module
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  period    The WDT timer period to set.
 *                        One of @ref DL_LFSS_IWDT_TIMER_PERIOD.
 */
__STATIC_INLINE void DL_LFSS_IWDT_setTimerPeriod(
    LFSS_Regs *lfss, DL_LFSS_IWDT_TIMER_PERIOD period)
{
    DL_Common_updateReg(&lfss->IPSPECIFIC_WDT.WDTCTL,
        ((uint32_t) period | LFSS_WDTCTL_KEY_UNLOCK_W),
        LFSS_WDTCTL_PER_MASK | LFSS_WDTCTL_KEY_MASK);
}

/*!
 *  @brief      Get the timer period for the WDT module
 *
 *  @param[in]  lfss  Pointer to the register overlay for peripheral
 *
 *  @return     The current timer period for the WDT module
 *
 *  @retval     One of @ref DL_LFSS_IWDT_TIMER_PERIOD
 */
__STATIC_INLINE DL_LFSS_IWDT_TIMER_PERIOD DL_LFSS_IWDT_getTimerPeriod(
    LFSS_Regs *lfss)
{
    uint32_t period = (lfss->IPSPECIFIC_WDT.WDTCTL & LFSS_WDTCTL_PER_MASK);

    return (DL_LFSS_IWDT_TIMER_PERIOD)(period);
}

/*!
 *  @brief      Restarts the Watchdog
 *
 *  @param[in]  lfss  Pointer to the register overlay for peripheral
 */
__STATIC_INLINE void DL_LFSS_IWDT_restart(LFSS_Regs *lfss)
{
    lfss->IPSPECIFIC_WDT.WDTCNTRST = LFSS_WDTCNTRST_RESTART_VALUE;
}

/**
 * @brief Returns if Watchdog module is running
 *
 * @param lfss        Pointer to the register overlay for the peripheral
 *
 * @return true  Watchdog module is running
 * @return false Watchdog counter has stopped
 */
__STATIC_INLINE bool DL_LFSS_IWDT_isWatchdogRunning(LFSS_Regs *lfss)
{
    return ((lfss->IPSPECIFIC_WDT.WDTSTAT & LFSS_WDTSTAT_RUN_MASK) ==
            LFSS_WDTSTAT_RUN_RUN);
}

/**
 *  @brief      Enable write protection lock of the WDTEN and WDTCTL
 *              registers from accidental updates
 *
 *  When enabled, the WDTEN and WDTCTL registers will have read-only access.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 */
__STATIC_INLINE void DL_LFSS_IWDT_enableWriteProtect(LFSS_Regs *lfss)
{
    lfss->IPSPECIFIC_WDT.WDTLOCK =
        (LFSS_WDTLOCK_PROTECT_SET | LFSS_WDTLOCK_KEY_UNLOCK_W);
}

/**
 *  @brief      Checks if write protection lock of the WDTEN and WDTCTL
 *              registers is enabled
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *
 *  @return     Returns the enabled status of the write protection lock
 *
 *  @retval     true  Write protection lock is enabled
 *  @retval     false Write protection lock is disabled
 */
__STATIC_INLINE bool DL_LFSS_IWDT_isWriteProtectEnabled(LFSS_Regs *lfss)
{
    return ((lfss->IPSPECIFIC_WDT.WDTLOCK & LFSS_WDTLOCK_PROTECT_MASK) ==
            LFSS_WDTLOCK_PROTECT_SET);
}

/**
 *  @brief      Disable write protection lock of the WDTEN and WDTCTL
 *              registers
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 */
__STATIC_INLINE void DL_LFSS_IWDT_disableWriteProtect(LFSS_Regs *lfss)
{
    lfss->IPSPECIFIC_WDT.WDTLOCK =
        (LFSS_WDTLOCK_PROTECT_CLR | LFSS_WDTLOCK_KEY_UNLOCK_W);
}

/**
 *  @brief      Write a word in scratch pad memory
 *
 *  The VBAT scratch pad memory is register based memory that will retain data
 *  as long as VBAT is supplied. Refer to the device TRM for details on the
 *  specific size and implementation of the scratch pad memory.
 *
 *  This API wil write 32-bit data to the selected word in the scratch pad
 *  memory.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  memIndex  The specified scratch pad memory word to write to.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_WORD
 *  @param[in]  data      The 32-bit data to write to the specified scratch pad
 *                        memory word. Value in range of [0x0, 0xFFFFFFF].
 */
__STATIC_INLINE void DL_LFSS_writeScratchPadData32(
    LFSS_Regs *lfss, DL_LFSS_SCRATCHPAD_MEM_WORD memIndex, uint32_t data)
{
    lfss->IPSPECIFIC_MEM.SPMEM[(uint32_t) memIndex] = data;
}

/**
 *  @brief      Write to a single byte in scratch pad memory
 *
 *  The VBAT scratch pad memory is register based memory that will retain data
 *  as long as VBAT is supplied. Refer to the device TRM for details on the
 *  specific size and implementation of the scratch pad memory.
 *
 *  This API will write 8-bit data to the selected byte in the scratch pad
 *  memory. The byte to write to is given in context of the scratch pad memory
 *  word that contains that byte.
 *      For example, to write to BYTE5 of scratch pad memory, the user will call
 *      this API with parameters @ref DL_LFSS_SCRATCHPAD_MEM_WORD_1 and
 *      @ref DL_LFSS_SCRATCHPAD_MEM_BYTE_1.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  memIndex  The specified scratch pad memory word to write to.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_WORD
 *  @param[in]  byteIndex The specified scratch pad memory byte to write to.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_BYTE
 *  @param[in]  data      The 8-bit data to write to the specified scratch pad
 *                        memory byte. Value in range of [0x0, 0xFF].
 */

__STATIC_INLINE void DL_LFSS_writeScratchPadData8(LFSS_Regs *lfss,
    DL_LFSS_SCRATCHPAD_MEM_WORD memIndex,
    DL_LFSS_SCRATCHPAD_MEM_BYTE byteIndex, uint32_t data)
{
    /* Point to correct SPMEM word */
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_MEM.SPMEM[(uint32_t) memIndex];

    /* Get the correct bit based on the byteIndex */
    uint32_t offset = ((uint32_t) byteIndex * (uint32_t) 8);
    data            = data << offset;
    uint32_t mask   = ((uint32_t) 0x000000FFU) << offset;

    DL_Common_updateReg(pReg, data, mask);
}

/**
 *  @brief      Read the specified word in scratch pad memory
 *
 *  The VBAT scratch pad memory is register based memory that will retain data
 *  as long as VBAT is supplied. Refer to the device TRM for details on the
 *  specific size and implementation of the scratch pad memory.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  memIndex  The specified scratch pad memory word to read.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_WORD
 *
 *  @return     The 32-bit data in the specified scratch pad memory word
 */
__STATIC_INLINE uint32_t DL_LFSS_readScratchPadDataWord(
    LFSS_Regs *lfss, DL_LFSS_SCRATCHPAD_MEM_WORD memIndex)
{
    return (lfss->IPSPECIFIC_MEM.SPMEM[(uint32_t) memIndex]);
}

/**
 *  @brief      Read the specified byte in scratch pad memory
 *
 *  The VBAT scratch pad memory is register based memory that will retain data
 *  as long as VBAT is supplied. Refer to the device TRM for details on the
 *  specific size and implementation of the scratch pad memory.
 *
 *  This API will read 8-bit data from the selected byte in the scratch pad
 *  memory. The byte to read to is given in context of the scratch pad memory
 *  word that contains that byte.
 *      For example, to read BYTE5 of scratch pad memory, the user will call
 *      this API with parameters @ref DL_LFSS_SCRATCHPAD_MEM_WORD_1 and
 *      @ref DL_LFSS_SCRATCHPAD_MEM_BYTE_1.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  memIndex  The specified scratch pad memory word to read.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_WORD
 *  @param[in]  byteIndex The specified scratch pad memory byte to read.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_BYTE
 *
 *  @return     The 8-bit data in the specified scratch pad memory byte
 */
__STATIC_INLINE uint8_t DL_LFSS_readScratchPadDataByte(LFSS_Regs *lfss,
    DL_LFSS_SCRATCHPAD_MEM_WORD memIndex,
    DL_LFSS_SCRATCHPAD_MEM_BYTE byteIndex)
{
    /* Point to correct SPMEM word */
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_MEM.SPMEM[(uint32_t) memIndex];

    /* Get the correct bit based on the byteIndex */
    uint32_t offset = ((uint32_t) byteIndex * (uint32_t) 8);
    uint32_t mask   = ((uint32_t) 0x000000FFU) << offset;

    return (((*pReg & mask)) >> offset);
}

/**
 *  @brief     Enable write protection lock of the specified byte in scratch pad
 *             memory from accidental updates
 *
 *  When enabled, the specified byte in scratch pad memory will have read-only
 *  access.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  memIndex  The specified scratch pad memory word.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_WORD
 *  @param[in]  byteIndex The specified byte in scratch pad memory word to
 *                        enable write protection for
 */
__STATIC_INLINE void DL_LFSS_enableScratchPadWriteProtectByte(LFSS_Regs *lfss,
    DL_LFSS_SCRATCHPAD_MEM_WORD memIndex,
    DL_LFSS_SCRATCHPAD_MEM_BYTE byteIndex)
{
    /* Point to correct SPMWPROT register */
    uint32_t regIndex       = (uint32_t) memIndex >> (uint32_t) 2;
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_MEM.SPMWPROT0 + regIndex;

    /* Get the correct bit based on the byteIndex */
    uint32_t mask = (uint32_t) 1 << ((((uint32_t) memIndex % (uint32_t) 4)
                                         << (uint32_t) 2) +
                                     (uint32_t) byteIndex);

    *pReg |= (LFSS_SPMWPROT0_KEY_UNLOCK_W | mask);
}

/**
 *  @brief      Checks if write protection is enabled for the specified byte in
 *              scratch pad memory
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  memIndex  The specified scratch pad memory word.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_WORD
 *  @param[in]  byteIndex The specified scratch pad memory byte.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_BYTE
 *
 *  @return     Returns if write protection is enabled for the specified byte
 *
 *  @retval     true  Write protection for the specified byte is enabled
 *  @retval     false Write protection for the specified byte is disabled
 */
__STATIC_INLINE bool DL_LFSS_isScratchPadWriteProtectByteEnabled(
    LFSS_Regs *lfss, DL_LFSS_SCRATCHPAD_MEM_WORD memIndex,
    DL_LFSS_SCRATCHPAD_MEM_BYTE byteIndex)
{
    /* Point to correct SPMWPROT index */
    uint32_t regIndex       = (uint32_t) memIndex >> (uint32_t) 2;
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_MEM.SPMWPROT0 + regIndex;

    /* Get the correct bit based on the byteIndex */
    uint32_t mask = (uint32_t) 1 << ((((uint32_t) memIndex % (uint32_t) 4)
                                         << (uint32_t) 2) +
                                     (uint32_t) byteIndex);

    return ((*pReg & mask) == mask);
}

/**
 *  @brief     Disable write protection lock of the specified byte in scratch
 *             pad memory
 *
 *  When disables, the specified byte in scratch pad memory will have read-only
 *  access.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  memIndex  The specified scratch pad memory word.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_WORD
 *  @param[in]  byteIndex The specified byte in scratch pad memory word to
 *                        disable write protection for.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_BYTE
 */
__STATIC_INLINE void DL_LFSS_disableScratchPadWriteProtectByte(LFSS_Regs *lfss,
    DL_LFSS_SCRATCHPAD_MEM_WORD memIndex,
    DL_LFSS_SCRATCHPAD_MEM_BYTE byteIndex)
{
    /* Point to correct SPMWPROT index */
    uint32_t regIndex       = (uint32_t) memIndex >> (uint32_t) 2;
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_MEM.SPMWPROT0 + regIndex;

    /* Get the correct bit based on the byteIndex */
    uint32_t mask = (uint32_t) 1 << ((((uint32_t) memIndex % (uint32_t) 4)
                                         << (uint32_t) 2) +
                                     (uint32_t) byteIndex);

    *pReg = ((*pReg & (~mask)) | LFSS_SPMWPROT1_KEY_UNLOCK_W);
}

/**
 *  @brief     Enable tamper erase of the specified byte in scratch pad
 *             memory
 *
 *  When enabled, the specified byte in scratch pad memory will be erased in the
 *  event of a tamper detect.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  memIndex  The specified scratch pad memory word.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_WORD
 *  @param[in]  byteIndex The specified byte in scratch pad memory word to
 *                        enable tamper erase for.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_BYTE
 */
__STATIC_INLINE void DL_LFSS_enableScratchPadTamperEraseByte(LFSS_Regs *lfss,
    DL_LFSS_SCRATCHPAD_MEM_WORD memIndex,
    DL_LFSS_SCRATCHPAD_MEM_BYTE byteIndex)
{
    /* Point to correct SPMTERASE index */
    uint32_t regIndex       = (uint32_t) memIndex >> (uint32_t) 2;
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_MEM.SPMTERASE0 + regIndex;

    /* Get the correct bit based on the byteIndex */
    uint32_t mask = (uint32_t) 1 << ((((uint32_t) memIndex % (uint32_t) 4)
                                         << (uint32_t) 2) +
                                     (uint32_t) byteIndex);

    *pReg |= (LFSS_SPMTERASE0_KEY_UNLOCK_W | mask);
}

/**
 *  @brief      Checks if tamper erase is enabled for the specified byte in
 *              scratch pad memory
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  memIndex  The specified scratch pad memory word.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_WORD
 *  @param[in]  byteIndex The specified byte in scratch pad memory byte.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_BYTE
 *
 *  @return     Returns if tamper erase is enabled for the specified byte
 *
 *  @retval     true  Tamper erase for the specified byte is enabled
 *  @retval     false tamper erase for the specified byte is disabled
 */
__STATIC_INLINE bool DL_LFSS_isScratchPadTamperEraseByteEnabled(
    LFSS_Regs *lfss, DL_LFSS_SCRATCHPAD_MEM_WORD memIndex,
    DL_LFSS_SCRATCHPAD_MEM_BYTE byteIndex)
{
    /* Point to correct SPMTERASE index */
    uint32_t regIndex       = (uint32_t) memIndex >> (uint32_t) 2;
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_MEM.SPMTERASE0 + regIndex;

    /* Get the correct bit based on the byteIndex */
    uint32_t mask = (uint32_t) 1 << ((((uint32_t) memIndex % (uint32_t) 4)
                                         << (uint32_t) 2) +
                                     (uint32_t) byteIndex);

    return ((*pReg & mask) == mask);
}

/**
 *  @brief     Disable tamper erase of the specified byte in scratch pad memory
 *
 *  The specified byte in scratch pad memory will not be erased in the event of
 *  a tamper detect.
 *
 *  @param[in]  lfss      Pointer to the register overlay for the LFSS peripheral
 *  @param[in]  memIndex  The specified scratch pad memory word to write to.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_WORD
 *  @param[in]  byteIndex The specified byte in scratch pad memory word to
 *                        disable tamper erase for.
 *                        One of @ref DL_LFSS_SCRATCHPAD_MEM_BYTE
 */
__STATIC_INLINE void DL_LFSS_disableScratchPadTamperEraseByte(LFSS_Regs *lfss,
    DL_LFSS_SCRATCHPAD_MEM_WORD memIndex,
    DL_LFSS_SCRATCHPAD_MEM_BYTE byteIndex)
{
    /* Point to correct SPMTERASE index */
    uint32_t regIndex       = (uint32_t) memIndex >> (uint32_t) 2;
    volatile uint32_t *pReg = &lfss->IPSPECIFIC_MEM.SPMTERASE0 + regIndex;

    /* Get the correct bit based on the byteIndex */
    uint32_t mask = (uint32_t) 1 << ((((uint32_t) memIndex % (uint32_t) 4)
                                         << (uint32_t) 2) +
                                     (uint32_t) byteIndex);

    *pReg = ((*pReg & (~mask)) | LFSS_SPMWPROT2_KEY_UNLOCK_W);
}

/**
 *  @brief      Enable LFSS Tamper Interrupts
 *
 *  @param[in]  lfss  Pointer to the register overlay for the LFSS Tamper peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Logical OR of
 *                             @ref DL_LFSS_TAMPERIO_INTERRUPT.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_enableInterrupt(
    LFSS_Regs *lfss, uint32_t interruptMask)
{
    lfss->CPU_INT.IMASK |= interruptMask;
}

/**
 *  @brief      Disable LFSS Tamper interrupts
 *
 *  @param[in]  lfss  Pointer to the register overlay for the LFSS Tamper peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Logical OR of
 *                             @ref DL_LFSS_TAMPERIO_INTERRUPT
 */
__STATIC_INLINE void DL_LFSS_TamperIO_disableInterrupt(
    LFSS_Regs *lfss, uint32_t interruptMask)
{
    lfss->CPU_INT.IMASK &= ~(interruptMask);
}

/**
 *  @brief      Check which LFSS Tamper interrupts are enabled
 *
 *  @param[in]  lfss  Pointer to the register overlay for the LFSS Tamper peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Logical OR of
 *                             @ref DL_LFSS_TAMPERIO_INTERRUPT
 *
 *  @return     Which of the requested LFSS interrupts are enabled
 *
 *  @retval     Logical OR of @ref DL_LFSS_TAMPERIO_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_LFSS_TamperIO_getEnabledInterrupts(
    LFSS_Regs *lfss, uint32_t interruptMask)
{
    return (lfss->CPU_INT.IMASK & interruptMask);
}

/**
 *  @brief      Check interrupt flag of enabled LFSS Tamper interrupts
 *
 *  Checks if any of the LFSS Tamper interrupts that were previously enabled are
 *  pending.
 *
 *  @param[in]  lfss  Pointer to the register overlay for the LFSS Tamper peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Logical OR of
 *                             @ref DL_LFSS_TAMPERIO_INTERRUPT
 *
 *  @return     Which of the requested LFSS Tamper interrupts are pending
 *
 *  @retval     Logical OR of @ref DL_LFSS_TAMPERIO_INTERRUPT values
 *
 *  @sa         DL_LFSS_TAMPERIO_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_LFSS_TamperIO_getEnabledInterruptStatus(
    LFSS_Regs *lfss, uint32_t interruptMask)
{
    return (lfss->CPU_INT.MIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of any LFSS Tamper interrupt
 *
 *  Checks if any of the LFSS Tamper interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  lfss  Pointer to the register overlay for the LFSS Tamper peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Logical OR of
 *                             @ref DL_LFSS_TAMPERIO_INTERRUPT
 *
 *  @return     Which of the requested LFSS Tamper interrupts are pending
 *
 *  @retval     Logical OR of @ref DL_LFSS_TAMPERIO_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_LFSS_TamperIO_getRawInterruptStatus(
    LFSS_Regs *lfss, uint32_t interruptMask)
{
    return (lfss->CPU_INT.RIS & interruptMask);
}

/**
 *  @brief      Get highest priority pending LFSS interrupt
 *
 *  Checks if any of the LFSS interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  lfss  Pointer to the register overlay for the LFSS Tamper peripheral
 *
 *  @return     The highest priority pending LFSS Tamper interrupt
 *
 *  @retval     One of @ref DL_LFSS_TAMPERIO_IIDX
 */
__STATIC_INLINE DL_LFSS_TAMPERIO_IIDX DL_LFSS_TamperIO_getPendingInterrupt(
    LFSS_Regs *lfss)
{
    return (DL_LFSS_TAMPERIO_IIDX)(lfss->CPU_INT.IIDX);
}

/**
 *  @brief      Clear pending LFSS Tamper interrupts
 *
 *  @param[in]  lfss  Pointer to the register overlay for the LFSS Tamper peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Logical OR of
 *                             @ref DL_LFSS_TAMPERIO_INTERRUPT
 */
__STATIC_INLINE void DL_LFSS_TamperIO_clearInterruptStatus(
    LFSS_Regs *lfss, uint32_t interruptMask)
{
    lfss->CPU_INT.ICLR = interruptMask;
}

/**
 *  @brief      Enable LFSS Tamper event
 *
 *  @param[in]  lfss       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to enable. Bitwise OR of
 *                          @ref DL_LFSS_TAMPERIO_EVENT.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_enableEvent(
    LFSS_Regs *lfss, uint32_t eventMask)
{
    lfss->GEN_EVENT.IMASK |= (eventMask);
}

/**
 *  @brief      Disable LFSS Tamper event
 *
 *  @param[in]  lfss       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to enable. Bitwise OR of
 *                          @ref DL_LFSS_TAMPERIO_EVENT.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_disableEvent(
    LFSS_Regs *lfss, uint32_t eventMask)
{
    lfss->GEN_EVENT.IMASK &= ~(eventMask);
}

/**
 *  @brief      Check which LFSS Tamper events are enabled
 *
 *  @param[in]  lfss       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to check. Bitwise OR of
 *                          @ref DL_LFSS_TAMPERIO_EVENT.
 *
 *  @return     Which of the requested LFSS Tamper interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_LFSS_TAMPERIO_EVENT values
 */
__STATIC_INLINE uint32_t DL_LFSS_TamperIO_getEnabledEvents(
    LFSS_Regs *lfss, uint32_t eventMask)
{
    return ((lfss->GEN_EVENT.IMASK) & (eventMask));
}

/**
 *  @brief      Check event flag of enabled LFSS Tamper event
 *
 *  Checks if any of the LFSS Tamper events that were previously enabled are
 *  pending.
 *
 *  @param[in]  lfss       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to check. Bitwise OR of
 *                          @ref DL_LFSS_TAMPERIO_EVENT.
 *
 *  @return     Which of the requested LFSS Tamper interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_LFSS_TAMPERIO_EVENT values
 *
 *  @sa         DL_LFSS_TamperIO_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_LFSS_TamperIO_getEnabledEventStatus(
    LFSS_Regs *lfss, uint32_t eventMask)
{
    return ((lfss->GEN_EVENT.MIS) & eventMask);
}

/**
 *  @brief      Check interrupt flag of any LFSS Tamper event
 *
 *  Checks if any events are pending. Events do not have to
 *  be previously enabled.
 *
 *  @param[in]  lfss       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to check. Bitwise OR of
 *                          @ref DL_LFSS_TAMPERIO_EVENT.
 *
 *  @return     Which of the requested LFSS Tamper interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_LFSS_TAMPERIO_EVENT values
 */
__STATIC_INLINE uint32_t DL_LFSS_TamperIO_getRawEventsStatus(
    LFSS_Regs *lfss, uint32_t eventMask)
{
    return ((lfss->GEN_EVENT.RIS) & eventMask);
}

/**
 *  @brief      Clear pending LFSS Tamper events
 *
 *  @param[in]  lfss       Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask   Bit mask of interrupts to clear. Bitwise OR of
 *                          @ref DL_LFSS_TAMPERIO_EVENT.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_clearEventsStatus(
    LFSS_Regs *lfss, uint32_t eventMask)
{
    lfss->GEN_EVENT.ICLR |= (eventMask);
}

/**
 *  @brief Sets the LFSS Tamper event publisher channel ID
 *
 *  @param[in]  lfss       Pointer to the register overlay for the peripheral
 *  @param[in]  chanID  Channel ID number. Valid range 0-15. If ChanID == 0
 *                      publisher is disconnected.
 */
__STATIC_INLINE void DL_LFSS_TamperIO_setPublisherChanID(
    LFSS_Regs *lfss, uint8_t chanID)
{
    lfss->FPUB_0 = (chanID & LFSS_FPUB_0_CHANID_MAXIMUM);
}

/**
 *  @brief Gets the event publisher channel ID
 *
 *  @param[in]  lfss       Pointer to the register overlay for the peripheral
 *
 *  @return     Event publisher channel ID
 *
 */
__STATIC_INLINE uint8_t DL_LFSS_TamperIO_getPublisherChanID(LFSS_Regs *lfss)
{
    return (uint8_t)(lfss->FPUB_0 & LFSS_FPUB_0_CHANID_MAXIMUM);
}

/**
 *  @brief Requests a reset to the LFSS module
 *
 *  @param[in]  lfss       Pointer to the register overlay for the peripheral
 *
 *
 */
__STATIC_INLINE void DL_LFSS_reset(LFSS_Regs *lfss)
{
    lfss->IPSPECIFIC_RTC.LFSSRST =
        (LFSS_LFSSRST_KEY_UNLOCK_W | LFSS_LFSSRST_VBATPOR_SET);
}

#ifdef __cplusplus
}
#endif
#endif /* __MSPM0_HAS_LFSS__ */
#endif /* ti_dl_dl_lfss__include */
/** @}*/
