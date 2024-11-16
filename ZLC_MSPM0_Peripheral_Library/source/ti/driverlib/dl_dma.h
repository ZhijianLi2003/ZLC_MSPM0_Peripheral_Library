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
/*!****************************************************************************
 *  @file       dl_dma.h
 *  @brief      Direct Memory Access (DMA) Driver Library
 *  @defgroup   DMA Direct Memory Access (DMA)
 *
 *  @anchor ti_dl_dl_m0p_dma_Overview
 *  # Overview
 *
 *  The Direct Memory Access (DMA) Library allows full configuration of
 *  the MSPM0 DMA module.
 *  The DMA controller transfers data from one address to another, without CPU
 *  intervention, across the entire address range.
 *  DMA controllers have multiple channels that can be configured independently
 *
 ******************************************************************************
 */
/** @addtogroup DMA
 * @{
 */
#ifndef ti_dl_dl_m0p_dma__include
#define ti_dl_dl_m0p_dma__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __cplusplus
extern "C" {
#endif

#if (DMA_SYS_N_DMA_FULL_CHANNEL > 0)
/*!
 * @brief Device has support for DMA FULL channels
 */
#define DEVICE_HAS_DMA_FULL_CHANNEL
#endif

/* clang-format off */

/** @addtogroup DL_DMA_INTERRUPT
 *  @{
 */
/*!
 * @brief DMA channel 0 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL0                        (DMA_CPU_INT_IMASK_DMACH0_SET)

/*!
 * @brief DMA channel 1 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL1                        (DMA_CPU_INT_IMASK_DMACH1_SET)

/*!
 * @brief DMA channel 2 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL2                        (DMA_CPU_INT_IMASK_DMACH2_SET)

/*!
 * @brief DMA channel 3 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL3                        (DMA_CPU_INT_IMASK_DMACH3_SET)

/*!
 * @brief DMA channel 4 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL4                        (DMA_CPU_INT_IMASK_DMACH4_SET)

/*!
 * @brief DMA channel 5 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL5                        (DMA_CPU_INT_IMASK_DMACH5_SET)

/*!
 * @brief DMA channel 6 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL6                        (DMA_CPU_INT_IMASK_DMACH6_SET)

/*!
 * @brief DMA channel 7 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL7                        (DMA_CPU_INT_IMASK_DMACH7_SET)

/*!
 * @brief DMA channel 8 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL8                        (DMA_CPU_INT_IMASK_DMACH8_SET)

/*!
 * @brief DMA channel 9 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL9                        (DMA_CPU_INT_IMASK_DMACH9_SET)

/*!
 * @brief DMA channel 10 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL10                      (DMA_CPU_INT_IMASK_DMACH10_SET)

/*!
 * @brief DMA channel 12 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL12                      (DMA_CPU_INT_IMASK_DMACH12_SET)

/*!
 * @brief DMA channel 13 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL13                      (DMA_CPU_INT_IMASK_DMACH13_SET)

/*!
 * @brief DMA channel 14 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL14                      (DMA_CPU_INT_IMASK_DMACH14_SET)

/*!
 * @brief DMA channel 15 interrupt
 */
#define DL_DMA_INTERRUPT_CHANNEL15                      (DMA_CPU_INT_IMASK_DMACH15_SET)

#ifdef DEVICE_HAS_DMA_FULL_CHANNEL
/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 0 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_INTERRUPT_EARLY_CHANNEL0        (DMA_CPU_INT_IMASK_PREIRQCH0_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 1 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_INTERRUPT_EARLY_CHANNEL1        (DMA_CPU_INT_IMASK_PREIRQCH1_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 2 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_INTERRUPT_EARLY_CHANNEL2        (DMA_CPU_INT_IMASK_PREIRQCH2_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 3 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_INTERRUPT_EARLY_CHANNEL3        (DMA_CPU_INT_IMASK_PREIRQCH3_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 4 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_INTERRUPT_EARLY_CHANNEL4        (DMA_CPU_INT_IMASK_PREIRQCH4_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 5 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_INTERRUPT_EARLY_CHANNEL5        (DMA_CPU_INT_IMASK_PREIRQCH5_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 6 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_INTERRUPT_EARLY_CHANNEL6        (DMA_CPU_INT_IMASK_PREIRQCH6_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 7 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_INTERRUPT_EARLY_CHANNEL7        (DMA_CPU_INT_IMASK_PREIRQCH7_SET)
#endif /* DEVICE_HAS_DMA_FULL_CHANNEL */

/*!
 * @brief DMA address error, source address not reachable
 */
#define DL_DMA_INTERRUPT_ADDR_ERROR                      (DMA_CPU_INT_IMASK_ADDRERR_SET)
/*!
 * @brief DMA data error, source data might be corrupted (PAR or ECC error)
 */
#define DL_DMA_INTERRUPT_DATA_ERROR                      (DMA_CPU_INT_IMASK_DATAERR_SET)

/** @}*/

/** @addtogroup DL_DMA_EVENT
 *  @{
 */
/*!
 * @brief DMA channel 0 interrupt
 */
#define DL_DMA_EVENT_CHANNEL0                             (DMA_GEN_EVENT_IMASK_DMACH0_SET)

/*!
 * @brief DMA channel 1 interrupt
 */
#define DL_DMA_EVENT_CHANNEL1                             (DMA_GEN_EVENT_IMASK_DMACH1_SET)

/*!
 * @brief DMA channel 2 interrupt
 */
#define DL_DMA_EVENT_CHANNEL2                             (DMA_GEN_EVENT_IMASK_DMACH2_SET)

/*!
 * @brief DMA channel 3 interrupt
 */
#define DL_DMA_EVENT_CHANNEL3                             (DMA_GEN_EVENT_IMASK_DMACH3_SET)

/*!
 * @brief DMA channel 4 interrupt
 */
#define DL_DMA_EVENT_CHANNEL4                             (DMA_GEN_EVENT_IMASK_DMACH4_SET)

/*!
 * @brief DMA channel 5 interrupt
 */
#define DL_DMA_EVENT_CHANNEL5                             (DMA_GEN_EVENT_IMASK_DMACH5_SET)

/*!
 * @brief DMA channel 6 interrupt
 */
#define DL_DMA_EVENT_CHANNEL6                             (DMA_GEN_EVENT_IMASK_DMACH6_SET)

/*!
 * @brief DMA channel 7 interrupt
 */
#define DL_DMA_EVENT_CHANNEL7                             (DMA_GEN_EVENT_IMASK_DMACH7_SET)

/*!
 * @brief DMA channel 8 interrupt
 */
#define DL_DMA_EVENT_CHANNEL8                             (DMA_GEN_EVENT_IMASK_DMACH8_SET)

/*!
 * @brief DMA channel 9 interrupt
 */
#define DL_DMA_EVENT_CHANNEL9                             (DMA_GEN_EVENT_IMASK_DMACH9_SET)

/*!
 * @brief DMA channel 10 interrupt
 */
#define DL_DMA_EVENT_CHANNEL10                           (DMA_GEN_EVENT_IMASK_DMACH10_SET)

/*!
 * @brief DMA channel 12 interrupt
 */
#define DL_DMA_EVENT_CHANNEL12                           (DMA_GEN_EVENT_IMASK_DMACH12_SET)

/*!
 * @brief DMA channel 13 interrupt
 */
#define DL_DMA_EVENT_CHANNEL13                           (DMA_GEN_EVENT_IMASK_DMACH13_SET)

/*!
 * @brief DMA channel 14 interrupt
 */
#define DL_DMA_EVENT_CHANNEL14                           (DMA_GEN_EVENT_IMASK_DMACH14_SET)

/*!
 * @brief DMA channel 15 interrupt
 */
#define DL_DMA_EVENT_CHANNEL15                           (DMA_GEN_EVENT_IMASK_DMACH15_SET)

#ifdef DEVICE_HAS_DMA_FULL_CHANNEL
/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 0 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_EVENT_EARLY_CHANNEL0            (DMA_GEN_EVENT_IMASK_PREIRQCH0_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 1 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_EVENT_EARLY_CHANNEL1            (DMA_GEN_EVENT_IMASK_PREIRQCH1_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 2 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_EVENT_EARLY_CHANNEL2            (DMA_GEN_EVENT_IMASK_PREIRQCH2_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 3 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_EVENT_EARLY_CHANNEL3            (DMA_GEN_EVENT_IMASK_PREIRQCH3_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 4 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_EVENT_EARLY_CHANNEL4            (DMA_GEN_EVENT_IMASK_PREIRQCH4_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 5 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_EVENT_EARLY_CHANNEL5            (DMA_GEN_EVENT_IMASK_PREIRQCH5_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 6 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_EVENT_EARLY_CHANNEL6            (DMA_GEN_EVENT_IMASK_PREIRQCH6_SET)

/*!
 * @brief Available for FULL-channel configuration only. Early IRQ for DMA
 * channel 7 interrupt. Size counter has reached early IRQ threshold.
 */
#define DL_DMA_FULL_CH_EVENT_EARLY_CHANNEL7            (DMA_GEN_EVENT_IMASK_PREIRQCH7_SET)
#endif /* DEVICE_HAS_DMA_FULL_CHANNEL */

/*!
 * @brief DMA address error, source address not reachable
 */
#define DL_DMA_EVENT_ADDR_ERROR                     (DMA_GEN_EVENT_IMASK_ADDRERR_SET)
/*!
 * @brief DMA data error, source data might be corrupted (PAR or ECC error)
 */
#define DL_DMA_EVENT_DATA_ERROR                     (DMA_GEN_EVENT_IMASK_DATAERR_SET)

/** @}*/

/*! @enum DL_DMA_TRANSFER_MODE */
typedef enum {
    /*! Each DMA trigger results in a single data transfer, once */
    DL_DMA_SINGLE_TRANSFER_MODE = DMA_DMACTL_DMATM_SINGLE,
    /*! Each DMA trigger results in a transfer of a block of data, once */
    DL_DMA_SINGLE_BLOCK_TRANSFER_MODE = DMA_DMACTL_DMATM_BLOCK,
#ifdef DEVICE_HAS_DMA_FULL_CHANNEL
    /*! Available for FULL-channel configuration only. Each DMA trigger results
     *  in a single data transfer, repeating */
    DL_DMA_FULL_CH_REPEAT_SINGLE_TRANSFER_MODE = DMA_DMACTL_DMATM_RPTSNGL,
    /*! Available for FULL-channel configuration only. Each DMA trigger results
     *  in a transfer of a block of data, repeating */
    DL_DMA_FULL_CH_REPEAT_BLOCK_TRANSFER_MODE = DMA_DMACTL_DMATM_RPTBLCK,
#endif /* DEVICE_HAS_DMA_FULL_CHANNEL */
} DL_DMA_TRANSFER_MODE;

/*! @enum DL_DMA_EXTENDED_MODE */
typedef enum {
    /*! Normal operation */
    DL_DMA_NORMAL_MODE = DMA_DMACTL_DMAEM_NORMAL,
#ifdef DEVICE_HAS_DMA_FULL_CHANNEL
    /*! Available for FULL-channel configuration only. Reads data from
     *  address table located at source address and transfers data to
     *  destination address */
    DL_DMA_FULL_CH_GATHER_MODE = DMA_DMACTL_DMAEM_GATHERMODE,
    /*! Available for FULL-channel configuration only. Fills the destination
     *  with a specific value */
    DL_DMA_FULL_CH_FILL_MODE = DMA_DMACTL_DMAEM_FILLMODE,
    /*! Available for FULL-channel configuration only. The source data contains
     *  addresses and data */
    DL_DMA_FULL_CH_TABLE_MODE = DMA_DMACTL_DMAEM_TABLEMODE,
#endif /* DEVICE_HAS_DMA_FULL_CHANNEL */
} DL_DMA_EXTENDED_MODE;

/*! @enum DL_DMA_INCREMENT */
typedef enum {
    /*! Do not change address after each transfer */
    DL_DMA_ADDR_UNCHANGED = DMA_DMACTL_DMASRCINCR_UNCHANGED,
    /*! Decrement address by 1 * DL_DMA_WIDTH after each transfer */
    DL_DMA_ADDR_DECREMENT = DMA_DMACTL_DMASRCINCR_DECREMENT,
    /*! Increment address by 1 * DL_DMA_WIDTH after each transfer */
    DL_DMA_ADDR_INCREMENT = DMA_DMACTL_DMASRCINCR_INCREMENT,
    /*! Stride mode 2, increment address by 2 * DL_DMA_WIDTH (skip over every
     * other element) */
    DL_DMA_ADDR_STRIDE_2 = DMA_DMACTL_DMASRCINCR_STRIDE_2,
    /*! Stride mode 3, increment address by 3 * DL_DMA_WIDTH (skip over two
     * elements */
    DL_DMA_ADDR_STRIDE_3 = DMA_DMACTL_DMASRCINCR_STRIDE_3,
    /*! Stride mode 4, increment address by 4 * DL_DMA_WIDTH (skip over three
     * elements */
    DL_DMA_ADDR_STRIDE_4 = DMA_DMACTL_DMASRCINCR_STRIDE_4,
    /*! Stride mode 5, increment address by 5 * DL_DMA_WIDTH (skip over four
     * elements */
    DL_DMA_ADDR_STRIDE_5 = DMA_DMACTL_DMASRCINCR_STRIDE_5,
    /*! Stride mode 6, increment address by 6 * DL_DMA_WIDTH (skip over five
     * elements */
    DL_DMA_ADDR_STRIDE_6 = DMA_DMACTL_DMASRCINCR_STRIDE_6,
    /*! Stride mode 7, increment address by 7 * DL_DMA_WIDTH (skip over six
     * elements */
    DL_DMA_ADDR_STRIDE_7 = DMA_DMACTL_DMASRCINCR_STRIDE_7,
    /*! Stride mode 8, increment address by 8 * DL_DMA_WIDTH (skip over seven
     * elements */
    DL_DMA_ADDR_STRIDE_8 = DMA_DMACTL_DMASRCINCR_STRIDE_8,
    /*! Stride mode 9, increment address by 9 * DL_DMA_WIDTH (skip over eight
     * elements */
    DL_DMA_ADDR_STRIDE_9 = DMA_DMACTL_DMASRCINCR_STRIDE_9,
} DL_DMA_INCREMENT;

/*! @enum DL_DMA_EARLY_INTERRUPT_THRESHOLD */
typedef enum {
    /*! Disable early interrupt events */
    DL_DMA_EARLY_INTERRUPT_THRESHOLD_DISABLED = DMA_DMACTL_DMAPREIRQ_PREIRQ_DISABLE,
    /*! Generate Early-IRQ event with one transfer pending (DMASZ=1) */
    DL_DMA_EARLY_INTERRUPT_THRESHOLD_1 = DMA_DMACTL_DMAPREIRQ_PREIRQ_1,
    /*! Generate Early-IRQ event with two transfers pending (DMASZ=2) */
    DL_DMA_EARLY_INTERRUPT_THRESHOLD_2 = DMA_DMACTL_DMAPREIRQ_PREIRQ_2,
    /*! Generate Early-IRQ event with three transfers pending (DMASZ=4) */
    DL_DMA_EARLY_INTERRUPT_THRESHOLD_4 = DMA_DMACTL_DMAPREIRQ_PREIRQ_4,
    /*! Generate Early-IRQ event with eight transfers pending (DMASZ=8) */
    DL_DMA_EARLY_INTERRUPT_THRESHOLD_8 = DMA_DMACTL_DMAPREIRQ_PREIRQ_8,
    /*! Generate Early-IRQ event with 32 transfers pending (DMASZ=32) */
    DL_DMA_EARLY_INTERRUPT_THRESHOLD_32 = DMA_DMACTL_DMAPREIRQ_PREIRQ_32,
    /*! Generate Early-IRQ event with 64 transfers pending (DMASZ=64) */
    DL_DMA_EARLY_INTERRUPT_THRESHOLD_64 = DMA_DMACTL_DMAPREIRQ_PREIRQ_64,
    /*! Generate Early-IRQ event when DMASZ reaches the half size point of the
     * original transfer size */
    DL_DMA_EARLY_INTERRUPT_THRESHOLD_HALF = DMA_DMACTL_DMAPREIRQ_PREIRQ_HALF,
} DL_DMA_EARLY_INTERRUPT_THRESHOLD;

/*! @enum DL_DMA_BURST_SIZE */
typedef enum {
    /*! No burst interruption. The block transfer always transfers all elements
     * defined in the DMASZ register before priority is newly evaluated */
    DL_DMA_BURST_SIZE_INFINITY = DMA_DMAPRIO_BURSTSZ_INFINITI,
    /*! Burst size of a block transfer is 8 */
    DL_DMA_BURST_SIZE_8 = DMA_DMAPRIO_BURSTSZ_BURST_8,
    /*! Burst size of a block transfer is 16 */
    DL_DMA_BURST_SIZE_16 = DMA_DMAPRIO_BURSTSZ_BUSRT_16,
    /*! Burst size of a block transfer is 32 */
    DL_DMA_BURST_SIZE_32 = DMA_DMAPRIO_BURSTSZ_BURST_32,
} DL_DMA_BURST_SIZE;

/*! @enum DL_DMA_TRIGGER_TYPE */
typedef enum {
    /*! Internal DMA channel is selected as the DMA trigger */
    DL_DMA_TRIGGER_TYPE_INTERNAL = DMA_DMATCTL_DMATINT_INTERNAL,
    /*! External DMA channel is selected as the DMA trigger */
    DL_DMA_TRIGGER_TYPE_EXTERNAL = DMA_DMATCTL_DMATINT_EXTERNAL,
} DL_DMA_TRIGGER_TYPE;

/*! @enum DL_DMA_WIDTH */
typedef enum {
    /*! Byte Acccess (8-bit) */
    DL_DMA_WIDTH_BYTE = DMA_DMACTL_DMASRCWDTH_BYTE,
    /*! Half Word Acccess (16-bit) */
    DL_DMA_WIDTH_HALF_WORD = DMA_DMACTL_DMASRCWDTH_HALF,
    /*! Word Acccess (32-bit) */
    DL_DMA_WIDTH_WORD = DMA_DMACTL_DMASRCWDTH_WORD,
    /*! Long Acccess (64-bit) */
    DL_DMA_WIDTH_LONG = DMA_DMACTL_DMASRCWDTH_LONG,
    /*! Long-long Acccess (128-bit) */
    DL_DMA_WIDTH_LONG_LONG = DMA_DMACTL_DMASRCWDTH_LONGLONG,
} DL_DMA_WIDTH;

/*! @enum DL_DMA_EVENT_IIDX */
typedef enum {
    /*! Enum to indicate that no DMA event has taken place */
    DL_DMA_EVENT_IIDX_NO_INTR = DMA_GEN_EVENT_IIDX_STAT_NO_INTR,
    /*! Enum to indicate that the channel 0 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH0 = DMA_GEN_EVENT_IIDX_STAT_DMACH0,
    /*! Enum to indicate that the channel 1 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH1 = DMA_GEN_EVENT_IIDX_STAT_DMACH1,
    /*! Enum to indicate that the channel 2 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH2 = DMA_GEN_EVENT_IIDX_STAT_DMACH2,
    /*! Enum to indicate that the channel 3 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH3 = DMA_GEN_EVENT_IIDX_STAT_DMACH3,
    /*! Enum to indicate that the channel 4 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH4 = DMA_GEN_EVENT_IIDX_STAT_DMACH4,
    /*! Enum to indicate that the channel 5 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH5 = DMA_GEN_EVENT_IIDX_STAT_DMACH5,
    /*! Enum to indicate that the channel 6 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH6 = DMA_GEN_EVENT_IIDX_STAT_DMACH6,
    /*! Enum to indicate that the channel 7 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH7 = DMA_GEN_EVENT_IIDX_STAT_DMACH7,
    /*! Enum to indicate that the channel 8 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH8 = DMA_GEN_EVENT_IIDX_STAT_DMACH8,
    /*! Enum to indicate that the channel 9 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH9 = DMA_GEN_EVENT_IIDX_STAT_DMACH9,
    /*! Enum to indicate that the channel 10 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH10 = DMA_GEN_EVENT_IIDX_STAT_DMACH10,
    /*! Enum to indicate that the channel 11 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH11 = DMA_GEN_EVENT_IIDX_STAT_DMACH11,
    /*! Enum to indicate that the channel 12 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH12 = DMA_GEN_EVENT_IIDX_STAT_DMACH12,
    /*! Enum to indicate that the channel 13 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH13 = DMA_GEN_EVENT_IIDX_STAT_DMACH13,
    /*! Enum to indicate that the channel 14 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH14 = DMA_GEN_EVENT_IIDX_STAT_DMACH14,
    /*! Enum to indicate that the channel 15 interrupt has fired */
    DL_DMA_EVENT_IIDX_DMACH15 = DMA_GEN_EVENT_IIDX_STAT_DMACH15,
#ifdef DEVICE_HAS_DMA_FULL_CHANNEL
    /*! Available for FULL-channel configuration only. Enum to indicate that the
     *  early interrupt event for channel 0 interrupt has fired */
    DL_DMA_FULL_CH_EVENT_IIDX_EARLY_IRQ_DMACH0 = DMA_GEN_EVENT_IIDX_STAT_PREIRQCH0,
    /*! Available for FULL-channel configuration only. Enum to indicate that the
     *  early interrupt event for channel 1 interrupt has fired */
    DL_DMA_FULL_CH_EVENT_IIDX_EARLY_IRQ_DMACH1 = DMA_GEN_EVENT_IIDX_STAT_PREIRQCH1,
    /*! Available for FULL-channel configuration only. Enum to indicate that the
     *  early interrupt event for channel 2 interrupt has fired */
    DL_DMA_FULL_CH_EVENT_IIDX_EARLY_IRQ_DMACH2 = DMA_GEN_EVENT_IIDX_STAT_PREIRQCH2,
    /*! Available for FULL-channel configuration only. Enum to indicate that the
     *  early interrupt event for channel 3 interrupt has fired */
    DL_DMA_FULL_CH_EVENT_IIDX_EARLY_IRQ_DMACH3 = DMA_GEN_EVENT_IIDX_STAT_PREIRQCH3,
    /*! Available for FULL-channel configuration only. Enum to indicate that the
     *  early interrupt event for channel 4 interrupt has fired */
    DL_DMA_FULL_CH_EVENT_IIDX_EARLY_IRQ_DMACH4 = DMA_GEN_EVENT_IIDX_STAT_PREIRQCH4,
    /*! Available for FULL-channel configuration only. Enum to indicate that the
     *  early interrupt event for channel 5 interrupt has fired */
    DL_DMA_FULL_CH_EVENT_IIDX_EARLY_IRQ_DMACH5 = DMA_GEN_EVENT_IIDX_STAT_PREIRQCH5,
    /*! Available for FULL-channel configuration only. Enum to indicate that the
     *  early interrupt event for channel 6 interrupt has fired */
    DL_DMA_FULL_CH_EVENT_IIDX_EARLY_IRQ_DMACH6 = DMA_GEN_EVENT_IIDX_STAT_PREIRQCH6,
    /*! Available for FULL-channel configuration only. Enum to indicate that the
     *  early interrupt event for channel 7 interrupt has fired */
    DL_DMA_FULL_CH_EVENT_IIDX_EARLY_IRQ_DMACH7 = DMA_GEN_EVENT_IIDX_STAT_PREIRQCH7,
#endif /* DEVICE_HAS_DMA_FULL_CHANNEL */
    /*! Enum to indicate that a DMA address error has occurred */
    DL_DMA_EVENT_IIDX_ADDR_ERROR = DMA_GEN_EVENT_IIDX_STAT_ADDRERR,

    /*! Enum to indicate that a DMA data error has occurred */
    DL_DMA_EVENT_IIDX_DATA_ERROR = DMA_GEN_EVENT_IIDX_STAT_DATAERR
} DL_DMA_EVENT_IIDX;

/*! @enum DL_DMA_PUBLISHER_INDEX */
typedef enum {
    /*! DMA Publisher index 0 */
    DL_DMA_PUBLISHER_INDEX_0 = 0,
} DL_DMA_PUBLISHER_INDEX;

/*! @enum DL_DMA_SUBSCRIBER_INDEX */
typedef enum {
    /*! DMA Subscriber index 0 */
    DL_DMA_SUBSCRIBER_INDEX_0 = 0,
    /*! DMA Subscriber index 1 */
    DL_DMA_SUBSCRIBER_INDEX_1 = 1
} DL_DMA_SUBSCRIBER_INDEX;

/*! @enum DL_DMA_AUTOEN */
typedef enum {
    /*! No automatic DMA enable */
    DL_DMA_AUTOEN_DISABLE = DMA_DMACTL_DMAAUTOEN_DISABLE,
    /*! Automatic DMA enable on DMASA register write */
    DL_DMA_AUTOEN_DMASA = DMA_DMACTL_DMAAUTOEN_DMASA,
    /*! Automatic DMA enable on DMADA register write */
    DL_DMA_AUTOEN_DMADA = DMA_DMACTL_DMAAUTOEN_DMADA,
    /*! Automatic DMA enable on DMASZ register write */
    DL_DMA_AUTOEN_DMASZ = DMA_DMACTL_DMAAUTOEN_DMASZ,
} DL_DMA_AUTOEN;

/* clang-format on */

/*!
 *  @brief Configuration struct for @ref DL_DMA_initChannel.
 */
typedef struct {
    /*!
     *  The event that should trigger a DMA transfer. Refer to the datasheet of
     *  the device for which DMA trigger values map to which events.
     */
    uint8_t trigger;

    /*!
     *  Configure whether the DMA selects an internal or external channel as
     *  the DMA trigger
     */
    DL_DMA_TRIGGER_TYPE triggerType;

    /*!
     * The transfer mode to use. Refer to the device datasheet to determine
     * which modes are supported in the selected channel.
     * One of @ref DL_DMA_TRANSFER_MODE.
     */
    DL_DMA_TRANSFER_MODE transferMode;

    /*! The extended mode to use. One of @ref DL_DMA_EXTENDED_MODE. */
    DL_DMA_EXTENDED_MODE extendedMode;

    /*! The width of the DMA source. One of @ref DL_DMA_WIDTH. */
    DL_DMA_WIDTH srcWidth;

    /*! The width of the DMA destination. One of @ref DL_DMA_WIDTH. */
    DL_DMA_WIDTH destWidth;

    /*!
     *  Amount to increment/decrement the DMA source address by. One of
     *  @ref DL_DMA_INCREMENT.
     */
    DL_DMA_INCREMENT srcIncrement;

    /*!
     *  Amount to increment/decrement the DMA destination address by. One of
     *  @ref DL_DMA_INCREMENT.
     */
    DL_DMA_INCREMENT destIncrement;
} DL_DMA_Config;

/**
 *  @brief      Initialize a DMA channel
 *
 *  Initializes all the configurable options for a DMA channel. The DMA channel
 *  is not enabled in this API.
 *
 *  @param[in]  dma           Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum    DMA channel to operate on
 *  @param[in]  config        Pointer to DMA channel configuration settings
 */
void DL_DMA_initChannel(
    DMA_Regs *dma, uint8_t channelNum, DL_DMA_Config *config);

/**
 *  @brief      Configure a DMA channel for a transfer
 *
 *  Configures the transfer settings for a DMA channel. The DMA channel is
 *  not enabled in this API.
 *
 *  @param[in]  dma           Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum    DMA channel to operate on
 *  @param[in]  transferMode  The transfer mode to use. Refer to the device
 *                            datasheet to determine which modes are supported
 *                            in the selected channel. One of
 *                            @ref DL_DMA_TRANSFER_MODE.
 *  @param[in]  extendedMode  The extended mode to use. One of
 *                            @ref DL_DMA_EXTENDED_MODE.
 *  @param[in]  srcWidth      The width of the DMA source. One of
 *                            @ref DL_DMA_WIDTH.
 *  @param[in]  destWidth     The width of the DMA destination. One of
 *                            @ref DL_DMA_WIDTH.
 *  @param[in]  srcIncrement  Amount to increment/decrement the DMA source
 *                            address by. One of @ref DL_DMA_INCREMENT.
 *  @param[in]  destIncrement Amount to increment/decrement the DMA destination
 *                            address by. One of @ref DL_DMA_INCREMENT.
 */
__STATIC_INLINE void DL_DMA_configTransfer(DMA_Regs *dma, uint8_t channelNum,
    DL_DMA_TRANSFER_MODE transferMode, DL_DMA_EXTENDED_MODE extendedMode,
    DL_DMA_WIDTH srcWidth, DL_DMA_WIDTH destWidth,
    DL_DMA_INCREMENT srcIncrement, DL_DMA_INCREMENT destIncrement)
{
    dma->DMACHAN[channelNum].DMACTL =
        ((uint32_t) transferMode | (uint32_t) extendedMode |
            (((uint32_t) destIncrement) << 4) | (uint32_t) srcIncrement |
            ((uint32_t) destWidth << 4) | (uint32_t) srcWidth);
}

/**
 *  @brief      Configure the DMA for round-robin priority
 *
 *  When round-robin priority is enabled, the channel that completes a transfer
 *  becomes the lowest priority. If multiple triggers happen simultaneously or
 *  are pending, the channel that transferred least recently will transfer
 *  first. Once it's complete the next highest priority channel will transfer.
 *
 *  @param[in]  dma  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_DMA_enableRoundRobinPriority(DMA_Regs *dma)
{
    dma->DMAPRIO |= DMA_DMAPRIO_ROUNDROBIN_ENABLE;
}

/**
 *  @brief      Disable round-robin priority for the DMA
 *
 *  When round-robin priority is disabled, the channel priorities are fixed
 *  in ascending order (Channel 0 is the lowed priority). If multiple triggers
 *  happen simultaneously or are pending, the channel with the highest priority
 *  completes its transfer before the next-highest transfer can start.
 *
 *  @param[in]  dma  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_DMA_disableRoundRobinPriority(DMA_Regs *dma)
{
    dma->DMAPRIO &= ~(DMA_DMAPRIO_ROUNDROBIN_MASK);
}

/**
 *  @brief      Check if round-robin priority is enabled for the DMA
 *
 *  @param[in]  dma  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of round-robin priority
 *
 *  @retval     true  Round-robin priority is enabled
 *  @retval     false Round-robin priority is disabled
 */
__STATIC_INLINE bool DL_DMA_isRoundRobinPriorityEnabled(DMA_Regs *dma)
{
    return ((dma->DMAPRIO & DMA_DMAPRIO_ROUNDROBIN_MASK) ==
            DMA_DMAPRIO_ROUNDROBIN_ENABLE);
}

/**
 *  @brief      Set the burst size for block transfers
 *
 *  After the DMA transfers the amount of transfers defined by
 *  @ref DL_DMA_BURST_SIZE, the ongoing block transfer is interrupted and the
 *  priority encoder has the chance to assign a higher priority channel. The
 *  previously interrupted block transfer is internally marked as pending and
 *  when no other high priority channel is pending the block transfer will
 *  continue with the next burst or until DMASZ counts down to 0.
 *
 *  @param[in]  dma           Pointer to the register overlay for the peripheral
 *  @param[in]  burstSize     The burst size to set. One of
 *                            @ref DL_DMA_BURST_SIZE.
 *
 *  @sa         DL_DMA_configTransfer
 */
__STATIC_INLINE void DL_DMA_setBurstSize(
    DMA_Regs *dma, DL_DMA_BURST_SIZE burstSize)
{
    DL_Common_updateReg(
        &dma->DMAPRIO, (uint32_t) burstSize, DMA_DMAPRIO_BURSTSZ_MASK);
}

/**
 *  @brief      Get the burst size for block transfers
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *
 *  @return     The burst size for block transfers
 *
 *  @retval     One of @ref DL_DMA_BURST_SIZE
 */
__STATIC_INLINE DL_DMA_BURST_SIZE DL_DMA_getBurstSize(DMA_Regs *dma)
{
    uint32_t burstSize = dma->DMAPRIO & DMA_DMAPRIO_BURSTSZ_MASK;

    return (DL_DMA_BURST_SIZE)(burstSize);
}

/**
 *  @brief      Enable a DMA channel for transfers
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 */
__STATIC_INLINE void DL_DMA_enableChannel(DMA_Regs *dma, uint8_t channelNum)
{
    dma->DMACHAN[channelNum].DMACTL |= DMA_DMACTL_DMAEN_ENABLE;
}

/**
 *  @brief      Disable a DMA channel for transfers
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 */
__STATIC_INLINE void DL_DMA_disableChannel(DMA_Regs *dma, uint8_t channelNum)
{
    dma->DMACHAN[channelNum].DMACTL &= ~(DMA_DMACTL_DMAEN_MASK);
}

/**
 *  @brief      Check if a DMA channel is enabled for transfers
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     The status of the DMA channel
 *
 *  @retval     true  The DMA channel is enabled
 *  @retval     false The DMA channel is disabled
 */
__STATIC_INLINE bool DL_DMA_isChannelEnabled(DMA_Regs *dma, uint8_t channelNum)
{
    return ((dma->DMACHAN[channelNum].DMACTL & DMA_DMACTL_DMAEN_MASK) ==
            DMA_DMACTL_DMAEN_ENABLE);
}

/**
 *  @brief      Configure the mode for a DMA channel
 *
 *  @param[in]  dma          Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum   DMA channel to operate on
 *  @param[in]  transferMode  The transfer mode to set for the channel. Refer to
 *                            the device datasheet to determine which modes are
 *                            supported in the selected channel. One of
 *                            @ref DL_DMA_TRANSFER_MODE.
 *  @param[in]  extendedMode The extended operation mode to set for the
 *                           channel. One of @ref DL_DMA_EXTENDED_MODE.
 *
 *  @sa         DL_DMA_configTransfer
 */
__STATIC_INLINE void DL_DMA_configMode(DMA_Regs *dma, uint8_t channelNum,
    DL_DMA_TRANSFER_MODE transferMode, DL_DMA_EXTENDED_MODE extendedMode)
{
    DL_Common_updateReg(&dma->DMACHAN[channelNum].DMACTL,
        (uint32_t) transferMode | (uint32_t) extendedMode,
        DMA_DMACTL_DMATM_MASK | DMA_DMACTL_DMAEM_MASK);
}

/**
 *  @brief      Set a DMA channel's transfer mode
 *
 *  @param[in]  dma           Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum    DMA channel to operate on
 *  @param[in]  transferMode  The transfer mode to use. Refer to the device
 *                            datasheet to determine which modes are supported
 *                            in the selected channel. One of
 *                            @ref DL_DMA_TRANSFER_MODE.
 *
 *  @sa         DL_DMA_configMode
 *  @sa         DL_DMA_configTransfer
 */
__STATIC_INLINE void DL_DMA_setTransferMode(
    DMA_Regs *dma, uint8_t channelNum, DL_DMA_TRANSFER_MODE transferMode)
{
    DL_Common_updateReg(&dma->DMACHAN[channelNum].DMACTL,
        (uint32_t) transferMode, DMA_DMACTL_DMATM_MASK);
}

/**
 *  @brief      Get a DMA channel's transfer mode
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     The channel's transfer mode
 *
 *  @retval     One of @ref DL_DMA_TRANSFER_MODE
 */
__STATIC_INLINE DL_DMA_TRANSFER_MODE DL_DMA_getTransferMode(
    DMA_Regs *dma, uint8_t channelNum)
{
    uint32_t mode = (dma->DMACHAN[channelNum].DMACTL & DMA_DMACTL_DMATM_MASK);

    return (DL_DMA_TRANSFER_MODE)(mode);
}

/**
 *  @brief      Set a DMA channel's extended mode
 *
 *  @param[in]  dma           Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum    DMA channel to operate on
 *  @param[in]  extendedMode  The transfer mode to use. One of
 *                            @ref DL_DMA_EXTENDED_MODE.
 *
 *  @sa         DL_DMA_configMode
 *  @sa         DL_DMA_configTransfer
 */
__STATIC_INLINE void DL_DMA_setExtendedMode(
    DMA_Regs *dma, uint8_t channelNum, DL_DMA_EXTENDED_MODE extendedMode)
{
    DL_Common_updateReg(&dma->DMACHAN[channelNum].DMACTL,
        (uint32_t) extendedMode, DMA_DMACTL_DMAEM_MASK);
}

/**
 *  @brief      Get a DMA channel's extended mode
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     The channel's transfer mode
 *
 *  @retval     One of @ref DL_DMA_EXTENDED_MODE
 */
__STATIC_INLINE DL_DMA_EXTENDED_MODE DL_DMA_getExtendedMode(
    DMA_Regs *dma, uint8_t channelNum)
{
    uint32_t mode = (dma->DMACHAN[channelNum].DMACTL & DMA_DMACTL_DMAEM_MASK);

    return (DL_DMA_EXTENDED_MODE)(mode);
}

/**
 *  @brief      Start a DMA transfer using software
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 */
__STATIC_INLINE void DL_DMA_startTransfer(DMA_Regs *dma, uint8_t channelNum)
{
    dma->DMACHAN[channelNum].DMACTL |= DMA_DMACTL_DMAREQ_REQUEST;
}

/**
 *  @brief      Set a channel's trigger for a DMA transfer
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *  @param[in]  trigger     What should trigger a DMA transfer. Refer to the
 *                          datasheet of the device for which DMA trigger
 *                          values map to which events.
 *  @param[in]  triggerType Whether an internal or external DMA channel is
 *                          selected as the DMA trigger. Refer to the datasheet
 *                          for more information on the DMA channels.
 */
__STATIC_INLINE void DL_DMA_setTrigger(DMA_Regs *dma, uint8_t channelNum,
    uint8_t trigger, DL_DMA_TRIGGER_TYPE triggerType)
{
    DL_Common_updateReg(&dma->DMATRIG[channelNum].DMATCTL,
        trigger | (uint32_t) triggerType,
        DMA_DMATCTL_DMATSEL_MASK | DMA_DMATCTL_DMATINT_MASK);
}

/**
 *  @brief      Get the current trigger for a DMA channel
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     What is configured to trigger a DMA transfer.
 *
 *  @retval     Check the device datasheet for what values are mapped to on
 *              your device.
 */
__STATIC_INLINE uint32_t DL_DMA_getTrigger(DMA_Regs *dma, uint8_t channelNum)
{
    return (dma->DMATRIG[channelNum].DMATCTL & DMA_DMATCTL_DMATSEL_MASK);
}

/**
 *  @brief      Get the current trigger type for a DMA channel
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     Whether an internal or external DMA channel is selected as the
 *              DMA trigger.
 *
 *  @retval     One of @ref DL_DMA_TRIGGER_TYPE
 */
__STATIC_INLINE DL_DMA_TRIGGER_TYPE DL_DMA_getTriggerType(
    DMA_Regs *dma, uint8_t channelNum)
{
    uint32_t triggerType =
        (dma->DMATRIG[channelNum].DMATCTL & DMA_DMATCTL_DMATINT_MASK);

    return (DL_DMA_TRIGGER_TYPE)(triggerType);
}

/**
 *  @brief      Set a DMA channel's source address
 *
 *  Set the source address for a DMA channel for transferring data from. This
 *  address can be automatically incremented/decremented after the completion
 *  of a transfer by using the @ref DL_DMA_setSrcIncrement function.
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *  @param[in]  srcAddr     Address to set as the DMA source
 *
 *  @sa         DL_DMA_setSrcIncrement
 */
__STATIC_INLINE void DL_DMA_setSrcAddr(
    DMA_Regs *dma, uint8_t channelNum, uint32_t srcAddr)
{
    dma->DMACHAN[channelNum].DMASA = srcAddr;
}

/**
 *  @brief      Get a DMA channel's source address
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     Source address for the DMA channel
 */
__STATIC_INLINE uint32_t DL_DMA_getSrcAddr(DMA_Regs *dma, uint8_t channelNum)
{
    return dma->DMACHAN[channelNum].DMASA;
}

/**
 *  @brief      Set a DMA channel's destination address
 *
 *  Set the destination address for a DMA channel for transferring data to.
 *  This address can be automatically incremented/decremented after the
 *  completion of a transfer by using the @ref DL_DMA_setDestIncrement
 *  function.
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *  @param[in]  destAddr    Address to set as the DMA destination
 *
 *  @sa         DL_DMA_setDestIncrement
 */
__STATIC_INLINE void DL_DMA_setDestAddr(
    DMA_Regs *dma, uint8_t channelNum, uint32_t destAddr)
{
    dma->DMACHAN[channelNum].DMADA = destAddr;
}

/**
 *  @brief      Get a DMA channel's destination address
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     Destination address for the DMA channel
 */
__STATIC_INLINE uint32_t DL_DMA_getDestAddr(DMA_Regs *dma, uint8_t channelNum)
{
    return dma->DMACHAN[channelNum].DMADA;
}

/**
 *  @brief      Set the size of a block for a DMA transfer
 *
 *  Defines the size of the block of data to transfer.
 *
 *  When the transfer mode @ref DL_DMA_TRANSFER_MODE is a Block transfer mode,
 *  this is the size of the block of data transferred every trigger.
 *
 *  When in the transfer mode @ref DL_DMA_TRANSFER_MODE is a Single transfer
 *  mode, this is how many triggers need to occur before the block is considered
 *  done, which then sets the interrupt status.
 *
 *  @param[in]  dma           Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum    DMA channel to operate on
 *  @param[in]  size          The size of the block of data to transfer. Value
 *                            between 0 - 65535.
 */
__STATIC_INLINE void DL_DMA_setTransferSize(
    DMA_Regs *dma, uint8_t channelNum, uint16_t size)
{
    dma->DMACHAN[channelNum].DMASZ = size;
}

/**
 *  @brief      Get a channel's size of block of data for a DMA transfer
 *
 *  @param[in]  dma           Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum    DMA channel to operate on
 *
 *  @return     The channel's size of block of data to transfer
 *
 *  @retval     A value between 0 - 65535.
 */
__STATIC_INLINE uint16_t DL_DMA_getTransferSize(
    DMA_Regs *dma, uint8_t channelNum)
{
    return (uint16_t)(dma->DMACHAN[channelNum].DMASZ & DMA_DMASZ_SIZE_MASK);
}

/**
 *  @brief      Set a channel's source address increment amount
 *
 *  After each DMA transfer the channel source address, which can be set by
 *  @ref DL_DMA_setSrcAddr, can be incremented, decremented or remain
 *  unchanged. This controls if the DMA is copying from a fixed address or a
 *  block of addresses.
 *
 *  The amount that is incremented/decremented is controlled by the width of
 *  the source, set by @ref DL_DMA_setSrcWidth.
 *
 *  @param[in]  dma           Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum    DMA channel to operate on
 *  @param[in]  srcIncrement  Amount to increment/decrement the DMA source
 *                            address by. One of @ref DL_DMA_INCREMENT.
 *
 *  @sa         DL_DMA_configTransfer
 *  @sa         DL_DMA_setSrcAddr
 *  @sa         DL_DMA_setSrcWidth
 */
__STATIC_INLINE void DL_DMA_setSrcIncrement(
    DMA_Regs *dma, uint8_t channelNum, DL_DMA_INCREMENT srcIncrement)
{
    DL_Common_updateReg(&dma->DMACHAN[channelNum].DMACTL,
        (uint32_t) srcIncrement, DMA_DMACTL_DMASRCINCR_MASK);
}

/**
 *  @brief      Return a channel's source address increment amount
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     The source address increment amount for selected channel
 *
 *  @retval     One of @ref DL_DMA_INCREMENT.
 */
__STATIC_INLINE DL_DMA_INCREMENT DL_DMA_getSrcIncrement(
    DMA_Regs *dma, uint8_t channelNum)
{
    uint32_t incrementAmount =
        (dma->DMACHAN[channelNum].DMACTL & DMA_DMACTL_DMASRCINCR_MASK);

    return (DL_DMA_INCREMENT)(incrementAmount);
}

/**
 *  @brief      Set a channel's destination address increment amount
 *
 *  After each DMA transfer the channel destination address, which can be set by
 *  @ref DL_DMA_setDestAddr, can be incremented, decremented or remain
 *  unchanged. This controls if the DMA is copying from a fixed address or a
 *  block of addresses.
 *
 *  The amount that is incremented/decremented is controlled by the width of
 *  the destination, set by @ref DL_DMA_setDestWidth.
 *
 *  @param[in]  dma           Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum    DMA channel to operate on
 *  @param[in]  destIncrement Amount to increment/decrement the DMA destination
 *                            address by. One of @ref DL_DMA_INCREMENT.
 *
 *  @sa         DL_DMA_configTransfer
 *  @sa         DL_DMA_setDestAddr
 *  @sa         DL_DMA_setDestWidth
 */
__STATIC_INLINE void DL_DMA_setDestIncrement(
    DMA_Regs *dma, uint8_t channelNum, DL_DMA_INCREMENT destIncrement)
{
    /* Left shifted by 4 so the defines align with bitfield */
    DL_Common_updateReg(&dma->DMACHAN[channelNum].DMACTL,
        ((uint32_t) destIncrement) << 4, DMA_DMACTL_DMADSTINCR_MASK);
}

/**
 *  @brief      Return a channel's destination address increment amount
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     The destination address increment amount for selected channel
 *
 *  @retval     One of @ref DL_DMA_INCREMENT.
 */
__STATIC_INLINE DL_DMA_INCREMENT DL_DMA_getDestIncrement(
    DMA_Regs *dma, uint8_t channelNum)
{
    /* Right shifted by 4 to align with provided defines */
    uint32_t incrementAmount =
        (dma->DMACHAN[channelNum].DMACTL & DMA_DMACTL_DMADSTINCR_MASK) >> 4;

    return (DL_DMA_INCREMENT)(incrementAmount);
}

/**
 *  @brief      Set the width of the DMA source address for a channel
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *  @param[in]  srcWidth    The width of the DMA source. One of
 *                          @ref DL_DMA_WIDTH.
 *
 *  @sa         DL_DMA_configTransfer
 */
__STATIC_INLINE void DL_DMA_setSrcWidth(
    DMA_Regs *dma, uint8_t channelNum, DL_DMA_WIDTH srcWidth)
{
    DL_Common_updateReg(&dma->DMACHAN[channelNum].DMACTL, (uint32_t) srcWidth,
        DMA_DMACTL_DMASRCWDTH_MASK);
}

/**
 *  @brief      Get the width of the DMA source address for a channel
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     The width of the DMA source for selected channel
 *
 *  @retval     One of @ref DL_DMA_WIDTH.
 */
__STATIC_INLINE DL_DMA_WIDTH DL_DMA_getSrcWidth(
    DMA_Regs *dma, uint8_t channelNum)
{
    uint32_t width =
        (dma->DMACHAN[channelNum].DMACTL & DMA_DMACTL_DMASRCWDTH_MASK);

    return (DL_DMA_WIDTH)(width);
}

/**
 *  @brief      Set the width of the DMA destination address for a channel
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *  @param[in]  destWidth   The width of the DMA destination. One of
 *                          @ref DL_DMA_WIDTH.
 *
 *  @sa         DL_DMA_configTransfer
 */
__STATIC_INLINE void DL_DMA_setDestWidth(
    DMA_Regs *dma, uint8_t channelNum, DL_DMA_WIDTH destWidth)
{
    /* Left shifted by 4 to align with provided defines */
    DL_Common_updateReg(&dma->DMACHAN[channelNum].DMACTL,
        ((uint32_t) destWidth) << 4, DMA_DMACTL_DMADSTWDTH_MASK);
}

/**
 *  @brief      Get the width of the DMA destination address for a channel
 *
 *  @param[in]  dma         Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     The width of the DMA destination for selected channel
 *
 *  @retval     One of @ref DL_DMA_WIDTH.
 */
__STATIC_INLINE DL_DMA_WIDTH DL_DMA_getDestWidth(
    DMA_Regs *dma, uint8_t channelNum)
{
    /* Right shifted by 4 to align with provided defines */
    uint32_t width =
        (dma->DMACHAN[channelNum].DMACTL & DMA_DMACTL_DMADSTWDTH_MASK) >> 4;

    return (DL_DMA_WIDTH)(width);
}
#ifdef DEVICE_HAS_DMA_FULL_CHANNEL
/**
 *  @brief      Set the early interrupt event.
 *
 *  This functionality is available for FULL-channel configuration only. Please
 *  refer to the device datasheet to map which channels have FULL or BASIC
 *  capability.
 *
 *  The DMA has the capability to generate an early interrupt with a
 *  given amount of transfer cycles before the DMA complete-interrupt is issued.
 *  This allows to start the ISR context switch in parallel with the completion
 *  of the DMA, and compensates the latency for the task switch into the ISR.
 *
 *  Ideally when the ISR starts to execute and read IIDX, the IIDX will already
 *  point to the channel-complete interrupt (always higher priority than the
 *  PRE-IRQ). In this case the latency is minimal and the ISR needs to clear
 *  the PRE-IRQ interrupt flag (RIS) manually.
 *  Should for whatever reason the DMA not complete in time, the IIDX will point
 *  to the PRE-IRQ handler and the handler needs to poll for the DMAEN bit in
 *  the DMA channel control register (DMACTL) to catch the moment that the DMA
 *  transfer has completed. Then the handler needs to clear the DMA
 *  channel-complete IRQ flag manually.
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  channelNum     DMA channel to operate on
 *  @param[in]  threshold      When to generate the early interrupt. One of
 *                             @ref DL_DMA_EARLY_INTERRUPT_THRESHOLD.
 */
__STATIC_INLINE void DL_DMA_Full_Ch_setEarlyInterruptThreshold(DMA_Regs *dma,
    uint8_t channelNum, DL_DMA_EARLY_INTERRUPT_THRESHOLD threshold)
{
    DL_Common_updateReg(&dma->DMACHAN[channelNum].DMACTL, (uint32_t) threshold,
        DMA_DMACTL_DMAPREIRQ_MASK);
}

/**
 *  @brief      Get the early interrupt event threshold.
 *
 *  This functionality is available for FULL-channel configuration only. Please
 *  refer to the device datasheet to map which channels have FULL or BASIC
 *  capability.
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  channelNum     DMA channel to operate on
 *
 *  @return     The early interrupt event threshold
 *
 *  @retval     One of @ref DL_DMA_EARLY_INTERRUPT_THRESHOLD.
 */
__STATIC_INLINE DL_DMA_EARLY_INTERRUPT_THRESHOLD
DL_DMA_Full_Ch_getEarlyInterruptThreshold(DMA_Regs *dma, uint8_t channelNum)
{
    uint32_t threshold =
        dma->DMACHAN[channelNum].DMACTL & DMA_DMACTL_DMAPREIRQ_MASK;

    return (DL_DMA_EARLY_INTERRUPT_THRESHOLD)(threshold);
}
#endif /* DEVICE_HAS_DMA_FULL_CHANNEL */

/**
 *  @brief      Enable DMA interrupts
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_DMA_INTERRUPT.
 */
__STATIC_INLINE void DL_DMA_enableInterrupt(
    DMA_Regs *dma, uint32_t interruptMask)
{
    dma->CPU_INT.IMASK |= interruptMask;
}

/**
 *  @brief      Disable DMA interrupts
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to disable. Bitwise OR of
 *                             @ref DL_DMA_INTERRUPT.
 */
__STATIC_INLINE void DL_DMA_disableInterrupt(
    DMA_Regs *dma, uint32_t interruptMask)
{
    dma->CPU_INT.IMASK &= ~(interruptMask);
}

/**
 *  @brief      Check which DMA interrupts are enabled
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_DMA_INTERRUPT.
 *
 *  @return     Which of the requested DMA interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_DMA_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_DMA_getEnabledInterrupts(
    DMA_Regs *dma, uint32_t interruptMask)
{
    return (dma->CPU_INT.IMASK & interruptMask);
}

/**
 *  @brief      Check interrupt flag of enabled DMA interrupts
 *
 *  Checks if any of the DMA interrupts that were previously enabled are
 *  pending.
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_DMA_INTERRUPT.
 *
 *  @return     Which of the requested DMA interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_DMA_INTERRUPT values
 *
 *  @sa         DL_DMA_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_DMA_getEnabledInterruptStatus(
    DMA_Regs *dma, uint32_t interruptMask)
{
    return (dma->CPU_INT.MIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of any DMA interrupt
 *
 *  Checks if any of the DMA interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_DMA_INTERRUPT.
 *
 *  @return     Which of the requested DMA interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_DMA_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_DMA_getRawInterruptStatus(
    DMA_Regs *dma, uint32_t interruptMask)
{
    return (dma->CPU_INT.RIS & interruptMask);
}

/**
 *  @brief      Get highest priority pending DMA interrupt
 *
 *  Checks if any of the DMA interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The highest priority pending DMA interrupt
 *
 *  @retval     One of @ref DL_DMA_EVENT_IIDX
 */
__STATIC_INLINE DL_DMA_EVENT_IIDX DL_DMA_getPendingInterrupt(DMA_Regs *dma)
{
    return (DL_DMA_EVENT_IIDX) dma->CPU_INT.IIDX;
}

/**
 *  @brief      Clear pending DMA interrupts
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_DMA_INTERRUPT.
 */
__STATIC_INLINE void DL_DMA_clearInterruptStatus(
    DMA_Regs *dma, uint32_t interruptMask)
{
    dma->CPU_INT.ICLR = interruptMask;
}

/**
 *  @brief Sets the event publisher channel id
 *
 *  @param[in]  dma     Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  index   Specifies the register event index to be configured
 *  @param[in]  chanID  Channel ID number. Valid range 0-15. If ChanID == 0
 *                      publisher is disconnected.
 */
__STATIC_INLINE void DL_DMA_setPublisherChanID(
    DMA_Regs *dma, DL_DMA_PUBLISHER_INDEX index, uint8_t chanID)
{
    volatile uint32_t *pReg = &dma->FPUB_1;

    *(pReg + (uint32_t) index) = (chanID & DMA_FPUB_1_CHANID_MAXIMUM);
}

/**
 *  @brief Gets the event publisher channel id
 *
 *  @param[in]  dma     Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  index   Specifies the register event index to be configured
 *
 *  @return     Event publisher channel ID
 *
 */
__STATIC_INLINE uint8_t DL_DMA_getPublisherChanID(
    DMA_Regs *dma, DL_DMA_PUBLISHER_INDEX index)
{
    volatile uint32_t *pReg = &dma->FPUB_1;

    return ((uint8_t)(*(pReg + (uint32_t) index) & DMA_FPUB_1_CHANID_MASK));
}

/**
 *  @brief Sets the event subscriber channel id
 *
 *  @param[in]  dma     Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  index   Specifies the register event index to be configured
 *  @param[in]  chanID  Channel ID number. Valid range 0-15. If ChanID == 0
 *                      subscriber is disconnected.
 */
__STATIC_INLINE void DL_DMA_setSubscriberChanID(
    DMA_Regs *dma, DL_DMA_SUBSCRIBER_INDEX index, uint8_t chanID)
{
    volatile uint32_t *pReg = &dma->FSUB_0;

    *(pReg + (uint32_t) index) = (chanID & DMA_FSUB_0_CHANID_MAXIMUM);
}

/**
 *  @brief Gets the event subscriber channel id
 *
 *  @param[in]  dma     Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  index   Specifies the register event index to be configured
 *
 *  @return     Event subscriber channel ID
 *
 */
__STATIC_INLINE uint8_t DL_DMA_getSubscriberChanID(
    DMA_Regs *dma, DL_DMA_SUBSCRIBER_INDEX index)
{
    volatile uint32_t *pReg = &dma->FSUB_0;

    return ((uint8_t)(*(pReg + (uint32_t) index) & DMA_FSUB_0_CHANID_MASK));
}

/**
 *  @brief      Enable DMA event
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of events to enable. Bitwise OR of
 *                             @ref DL_DMA_EVENT.
 */
__STATIC_INLINE void DL_DMA_enableEvent(DMA_Regs *dma, uint32_t eventMask)
{
    dma->GEN_EVENT.IMASK |= (eventMask);
}

/**
 *  @brief      Disable DMA event
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of events to enable. Bitwise OR of
 *                             @ref DL_DMA_EVENT.
 */
__STATIC_INLINE void DL_DMA_disableEvent(DMA_Regs *dma, uint32_t eventMask)
{
    dma->GEN_EVENT.IMASK &= ~(eventMask);
}

/**
 *  @brief      Check which dma events triggers are enabled
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of events to check. Bitwise OR of
 *                             @ref DL_DMA_EVENT.
 *
 *  @return     Which of the requested dma events are enabled
 *
 *  @retval     Bitwise OR of @ref DL_DMA_EVENT values
 */
__STATIC_INLINE uint32_t DL_DMA_getEnabledEvents(
    DMA_Regs *dma, uint32_t eventMask)
{
    return (dma->GEN_EVENT.IMASK & eventMask);
}

/**
 *  @brief      Check event flag of enabled dma event
 *
 *  Checks if any of the dma events that were previously enabled are
 *  pending.
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of events to check. Bitwise OR of
 *                             @ref DL_DMA_EVENT.
 *
 *  @return     Which of the requested dma events are pending
 *
 *  @retval     Bitwise OR of @ref DL_DMA_EVENT values
 *
 *  @sa         DL_DMA_enableEvent
 */
__STATIC_INLINE uint32_t DL_DMA_getEnabledEventStatus(
    DMA_Regs *dma, uint32_t eventMask)
{
    return (dma->GEN_EVENT.MIS & ~(eventMask));
}

/**
 *  @brief      Check event flag of any dma event
 *
 *  Checks if any events are pending. Events do not have to
 *  be previously enabled.
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of event to check. Bitwise OR of
 *                             @ref DL_DMA_EVENT.
 *
 *  @return     Which of the requested dma event are pending
 *
 *  @retval     Bitwise OR of @ref DL_DMA_EVENT values
 */
__STATIC_INLINE uint32_t DL_DMA_getRawEventsStatus(
    DMA_Regs *dma, uint32_t eventMask)
{
    return (dma->GEN_EVENT.RIS & ~(eventMask));
}

/**
 *  @brief      Clear pending dma events
 *
 *  @param[in]  dma            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of events to clear. Bitwise OR of
 *                             @ref DL_DMA_EVENT.
 */
__STATIC_INLINE void DL_DMA_clearEventsStatus(
    DMA_Regs *dma, uint32_t eventMask)
{
    dma->GEN_EVENT.ICLR |= (eventMask);
}

/**
 *  @brief      Configure the DMA for auto-enable
 *
 *  @param[in]  dma             Pointer to the register overlay for the peripheral
 *  @param[in]  mode            Enable auto-enable for DMA on a specified register write. One of @ref DL_DMA_AUTOEN
 *  @param[in]  channelNum      DMA channel to operate on
 */
__STATIC_INLINE void DL_DMA_enableAutoEnable(
    DMA_Regs *dma, DL_DMA_AUTOEN mode, uint8_t channelNum)
{
    dma->DMACHAN[channelNum].DMACTL |= mode;
}

/**
 *  @brief      Disable auto-enable for DMA
 *
 *  @param[in]  dma             Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  channelNum      DMA channel to operate on
 */
__STATIC_INLINE void DL_DMA_disableAutoEnable(
    DMA_Regs *dma, uint8_t channelNum)
{
    dma->DMACHAN[channelNum].DMACTL &= ~(DMA_DMACTL_DMAAUTOEN_MASK);
}

/**
 *  @brief      Check if auto-enable is enabled for the DMA
 *
 *  @param[in]  dma  Pointer to the register overlay for the peripheral
 *  @param[in]  channelNum  DMA channel to operate on
 *
 *  @return     The status of auto-enable
 *
 *  @retval     true    auto-enable is enabled
 *  @retval     false   auto-enable is disabled
 */
__STATIC_INLINE bool DL_DMA_isAutoEnableEnabled(
    DMA_Regs *dma, uint8_t channelNum)
{
    return ((dma->DMACHAN[channelNum].DMACTL & DMA_DMACTL_DMAAUTOEN_MASK) !=
            DMA_DMACTL_DMAAUTOEN_DISABLE);
}

#ifdef __cplusplus
}
#endif

#endif /* ti_dl_dl_m0p_dma__include */
/** @}*/
