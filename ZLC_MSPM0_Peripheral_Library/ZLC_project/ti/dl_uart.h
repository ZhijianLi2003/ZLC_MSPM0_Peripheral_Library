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
 *  @file       dl_uart.h
 *  @brief      UART Driver Library
 *  @defgroup   UART Universal Asynchronous Receiver-Transmitter (UART)
 *
 *  @anchor ti_dl_dl_uart_Overview
 *  # Overview
 *
 *  The Universal Asynchronous Receiver-Transmitter Driver Library allows
 *  full configuration of the MSPM0 UART module.
 *  This module provides common functionality for UART-Main and UART-Extend, but
 *  developers should use the corresponding dl_uart_extend or dl_uart_main APIs
 *  directly.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup UART
 * @{
 */
#ifndef ti_dl_dl_uart__include
#define ti_dl_dl_uart__include

#if defined(ti_dl_dl_uart_main__include) || \
    defined(ti_dl_dl_uart_extend__include) || defined(DOXYGEN__INCLUDE)

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#if defined(__MSPM0_HAS_UART_MAIN__) || defined(__MSPM0_HAS_UART_EXTD__)

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/** @addtogroup DL_UART_INTERRUPT
 *  @{
 */
/*!
 * @brief DMA done on transmit interrupt
 */
#define DL_UART_INTERRUPT_DMA_DONE_TX   (UART_CPU_INT_IMASK_DMA_DONE_TX_SET)

/*!
 * @brief DMA done on receive interrupt
 */
#define DL_UART_INTERRUPT_DMA_DONE_RX   (UART_CPU_INT_IMASK_DMA_DONE_RX_SET)

/*!
 * @brief Clear to send interrupt
 */
#define DL_UART_INTERRUPT_CTS_DONE              (UART_CPU_INT_IMASK_CTS_SET)

/*!
 * @brief 9-bit mode address match interrupt
 */
#define DL_UART_INTERRUPT_ADDRESS_MATCH  (UART_CPU_INT_IMASK_ADDR_MATCH_SET)

/*!
 * @brief LINC0 match interrupt
 */
#define DL_UART_INTERRUPT_LINC0_MATCH         (UART_CPU_INT_IMASK_LINC0_SET)

/*!
 * @brief End of transmission interrupt
 */
#define DL_UART_INTERRUPT_EOT_DONE              (UART_CPU_INT_IMASK_EOT_SET)

/*!
 * @brief UART transmit interrupt
 */
#define DL_UART_INTERRUPT_TX                  (UART_CPU_INT_IMASK_TXINT_SET)

/*!
 * @brief UART receive interrupt
 */
#define DL_UART_INTERRUPT_RX                  (UART_CPU_INT_IMASK_RXINT_SET)

/*!
 * @brief LIN hardware counter overflow interrupt
 */
#define DL_UART_INTERRUPT_LIN_COUNTER_OVERFLOW                                \
                                             (UART_CPU_INT_IMASK_LINOVF_SET)

/*!
 * @brief LIN rising edge LINC1 interrupt
 */
#define DL_UART_INTERRUPT_LIN_RISING_EDGE                                     \
                                              (UART_CPU_INT_IMASK_LINC1_SET)

/*!
 * @brief LIN falling edge LINC0 interrupt
 */
#define DL_UART_INTERRUPT_LIN_FALLING_EDGE                                    \
                                              (UART_CPU_INT_IMASK_LINC0_SET)

/*!
 * @brief Positive Edge on UARTxRXD interrupt
 */
#define DL_UART_INTERRUPT_RXD_POS_EDGE         (UART_CPU_INT_IMASK_RXPE_SET)

/*!
 * @brief Negative Edge on UARTxRXD interrupt
 */
#define DL_UART_INTERRUPT_RXD_NEG_EDGE         (UART_CPU_INT_IMASK_RXNE_SET)

/*!
 * @brief Overrun error interrupt
 */
#define DL_UART_INTERRUPT_OVERRUN_ERROR      (UART_CPU_INT_IMASK_OVRERR_SET)

/*!
 * @brief Break error interrupt
 */
#define DL_UART_INTERRUPT_BREAK_ERROR        (UART_CPU_INT_IMASK_BRKERR_SET)

/*!
 * @brief Parity error interrupt
 */
#define DL_UART_INTERRUPT_PARITY_ERROR       (UART_CPU_INT_IMASK_PARERR_SET)

/*!
 * @brief Framing error interrupt
 */
#define DL_UART_INTERRUPT_FRAMING_ERROR      (UART_CPU_INT_IMASK_FRMERR_SET)

/*!
 * @brief Receive timeout interrupt
 */
#define DL_UART_INTERRUPT_RX_TIMEOUT_ERROR    (UART_CPU_INT_IMASK_RTOUT_SET)


/*!
 * @brief Noise error interrupt
 */
#define DL_UART_INTERRUPT_NOISE_ERROR          (UART_CPU_INT_IMASK_NERR_SET)


/** @}*/

/*! @enum DL_UART_IIDX */
typedef enum {
    /*! UART interrupt index for DMA done on transmit */
    DL_UART_IIDX_DMA_DONE_TX = UART_CPU_INT_IIDX_STAT_DMA_DONE_TX,
    /*! UART interrupt index for DMA done on receive */
    DL_UART_IIDX_DMA_DONE_RX = UART_CPU_INT_IIDX_STAT_DMA_DONE_RX,
    /*! UART interrupt index for clear to send */
    DL_UART_IIDX_CTS_DONE = UART_CPU_INT_IIDX_STAT_CTS,
    /*! UART interrupt index for 9-bit mode address match */
    DL_UART_IIDX_ADDRESS_MATCH = UART_CPU_INT_IIDX_STAT_MODE_9B,
    /*! UART interrupt index for end of transmission */
    DL_UART_IIDX_EOT_DONE = UART_CPU_INT_IIDX_STAT_EOT,
    /*! UART interrupt index for UART transmit */
    DL_UART_IIDX_TX = UART_CPU_INT_IIDX_STAT_TXIFG,
    /*! UART interrupt index for UART receive */
    DL_UART_IIDX_RX = UART_CPU_INT_IIDX_STAT_RXIFG,
    /*! UART interrupt index for LIN hardware counter overflow */
    DL_UART_IIDX_LIN_COUNTER_OVERFLOW = UART_CPU_INT_IIDX_STAT_LINOVF,
    /*! UART interrupt index for LIN rising edge LINC1 */
    DL_UART_IIDX_LIN_RISING_EDGE = UART_CPU_INT_IIDX_STAT_LINC1,
    /*! UART interrupt index for LIN falling edge LINC0 */
    DL_UART_IIDX_LIN_FALLING_EDGE = UART_CPU_INT_IIDX_STAT_LINC0,
    /*! UART interrupt index for positive edge on UARTxRXD */
    DL_UART_IIDX_RXD_POS_EDGE = UART_CPU_INT_IIDX_STAT_RXPE,
    /*! UART interrupt index for negative edge on UARTxRXD */
    DL_UART_IIDX_RXD_NEG_EDGE = UART_CPU_INT_IIDX_STAT_RXNE,
    /*! UART interrupt index for overrun error */
    DL_UART_IIDX_OVERRUN_ERROR = UART_CPU_INT_IIDX_STAT_OEFG,
    /*! UART interrupt index for break error */
    DL_UART_IIDX_BREAK_ERROR = UART_CPU_INT_IIDX_STAT_BEFG,
    /*! UART interrupt index for parity error */
    DL_UART_IIDX_PARITY_ERROR = UART_CPU_INT_IIDX_STAT_PEFG,
    /*! UART interrupt index for framing error */
    DL_UART_IIDX_FRAMING_ERROR = UART_CPU_INT_IIDX_STAT_FEFG,
    /*! UART interrupt index for receive timeout */
    DL_UART_IIDX_RX_TIMEOUT_ERROR = UART_CPU_INT_IIDX_STAT_RTFG,


    /*! UART interrupt index for noise error */
    DL_UART_IIDX_NOISE_ERROR = UART_CPU_INT_IIDX_STAT_NERR_EVT,


    /*! UART interrupt index for no interrupt */
    DL_UART_IIDX_NO_INTERRUPT = UART_CPU_INT_IIDX_STAT_NO_INTR
} DL_UART_IIDX;

/*! @enum DL_UART_DMA_IIDX_RX */
typedef enum {
    /*! UART interrupt index for enabling UART receive as DMA trigger */
    DL_UART_DMA_IIDX_RX_TRIGGER = UART_DMA_TRIG_RX_IIDX_STAT_RXIFG,
    /*! UART interrupt index for enabling UART receive timeout as DMA trigger */
    DL_UART_DMA_IIDX_RX_TIMEOUT_TRIGGER = UART_DMA_TRIG_RX_IIDX_STAT_RTFG
} DL_UART_DMA_IIDX_RX;

/*! @enum DL_UART_DMA_IIDX_TX */
typedef enum {
    /*! UART interrupt index for enabling UART transmit as DMA trigger */
    DL_UART_DMA_IIDX_TX_TRIGGER = UART_DMA_TRIG_TX_IIDX_STAT_TXIFG
} DL_UART_DMA_IIDX_TX;

/** @addtogroup DL_UART_DMA_INTERRUPT_RX
 *  @{
 */
/*!
 * @brief UART interrupt for enabling UART receive as DMA trigger
 */
#define DL_UART_DMA_INTERRUPT_RX              (UART_DMA_TRIG_RX_IMASK_RXINT_SET)

/*!
 * @brief UART interrupt for enabling UART receive timeout as DMA trigger
 */
#define DL_UART_DMA_INTERRUPT_RX_TIMEOUT      (UART_DMA_TRIG_RX_IMASK_RTOUT_SET)

/** @}*/

/*!
 * @brief UART interrupt for enabling UART transmit as DMA trigger
 */
#define DL_UART_DMA_INTERRUPT_TX              (UART_DMA_TRIG_TX_IMASK_TXINT_SET)

/** @addtogroup DL_UART_ERROR
 *  @{
 */
/*!
 * @brief Overrun error ocurred
 */
#define DL_UART_ERROR_OVERRUN                          (UART_RXDATA_OVRERR_SET)

/*!
 * @brief Break error ocurred
 */
#define DL_UART_ERROR_BREAK                            (UART_RXDATA_BRKERR_SET)

/*!
 * @brief Parity error ocurred
 */
#define DL_UART_ERROR_PARITY                           (UART_RXDATA_PARERR_SET)

/*!
 * @brief Framing error ocurred
 */
#define DL_UART_ERROR_FRAMING                          (UART_RXDATA_FRMERR_SET)

/** @}*/

/*! @enum DL_UART_PULSE_WIDTH */
typedef enum {
    /*! Pulses shorter then 5ns length are filtered */
    DL_UART_PULSE_WIDTH_5_NS = UART_GFCTL_AGFSEL_AGLIT_5,
    /*! Pulses shorter then 10ns length are filtered */
    DL_UART_PULSE_WIDTH_10_NS = UART_GFCTL_AGFSEL_AGLIT_10,
    /*! Pulses shorter then 25ns length are filtered */
    DL_UART_PULSE_WIDTH_25_NS = UART_GFCTL_AGFSEL_AGLIT_25,
    /*! Pulses shorter then 50ns length are filtered */
    DL_UART_PULSE_WIDTH_50_NS = UART_GFCTL_AGFSEL_AGLIT_50
} DL_UART_PULSE_WIDTH;

/*! @enum DL_UART_OVERSAMPLING_RATE */
typedef enum {
    /*! Set oversampling rate to 16x */
    DL_UART_OVERSAMPLING_RATE_16X = UART_CTL0_HSE_OVS16,
    /*! Set oversampling rate to 8x */
    DL_UART_OVERSAMPLING_RATE_8X = UART_CTL0_HSE_OVS8,
    /*! Set oversampling rate to 3x.
     * IrDA, Manchester and DALI are not supported when 3x oversampling is
     * enabled. */
    DL_UART_OVERSAMPLING_RATE_3X = UART_CTL0_HSE_OVS3
} DL_UART_OVERSAMPLING_RATE;

/*! @enum DL_UART_PARITY */
typedef enum {
    /*! Enable even parity generation, checks for an even number of 1s */
    DL_UART_PARITY_EVEN = (UART_LCRH_PEN_ENABLE | UART_LCRH_EPS_EVEN),
    /*! Enable odd parity generation, checks for an odd number of 1s */
    DL_UART_PARITY_ODD = (UART_LCRH_PEN_ENABLE | UART_LCRH_EPS_ODD),
    /*! Enable stick parity with a parity bit of '1'
     * When enabled, a permanent '1' is set as parity when transmitting and
     * checked as '1' when receiving data. */
    DL_UART_PARITY_STICK_ONE = (UART_LCRH_PEN_ENABLE | UART_LCRH_SPS_ENABLE | UART_LCRH_EPS_ODD),
    /*! Enable stick parity with a parity bit of '0'
     * When enabled, a permanent '0' is set as parity when transmitting and
     * checked as '0' when receiving data. */
    DL_UART_PARITY_STICK_ZERO = (UART_LCRH_PEN_ENABLE | UART_LCRH_SPS_ENABLE | UART_LCRH_EPS_EVEN),
    /*! Disable parity checking and generation */
    DL_UART_PARITY_NONE = UART_LCRH_PEN_DISABLE
} DL_UART_PARITY;

/*! @enum DL_UART_WORD_LENGTH */
typedef enum {
    /*! Word length is 5 bits */
    DL_UART_WORD_LENGTH_5_BITS = UART_LCRH_WLEN_DATABIT5,
    /*! Word length is 6 bits */
    DL_UART_WORD_LENGTH_6_BITS = UART_LCRH_WLEN_DATABIT6,
    /*! Word length is 7 bits */
    DL_UART_WORD_LENGTH_7_BITS = UART_LCRH_WLEN_DATABIT7,
    /*! Word length is 8 bits */
    DL_UART_WORD_LENGTH_8_BITS = UART_LCRH_WLEN_DATABIT8
} DL_UART_WORD_LENGTH;

/*! @enum DL_UART_MODE */
typedef enum {
    /*! Normal operation */
    DL_UART_MODE_NORMAL = UART_CTL0_MODE_UART,
    /*! Operate in RS485 mode */
    DL_UART_MODE_RS485 = UART_CTL0_MODE_RS485,
    /*! Operate in Idle Line mode */
    DL_UART_MODE_IDLE_LINE = UART_CTL0_MODE_IDLELINE,
    /*! Operate in 9 Bit Address mode */
    DL_UART_MODE_ADDR_9_BIT = UART_CTL0_MODE_ADDR9BIT,
    /*! Operate in ISO7816 Smart Card Support mode */
    DL_UART_MODE_SMART_CARD = UART_CTL0_MODE_SMART,
    /*! Operate in DALI mode */
    DL_UART_MODE_DALI = UART_CTL0_MODE_DALI
} DL_UART_MODE;

/*! @enum DL_UART_DIRECTION */
typedef enum {
    /*! Enable UART transmitter */
    DL_UART_DIRECTION_TX = UART_CTL0_TXE_ENABLE,
    /*! Enable UART receiver */
    DL_UART_DIRECTION_RX = UART_CTL0_RXE_ENABLE,
    /*! Enable UART transmitter and receiver */
    DL_UART_DIRECTION_TX_RX = (UART_CTL0_RXE_ENABLE | UART_CTL0_TXE_ENABLE),
    /*! Disable UART transmitter and receiver */
    DL_UART_DIRECTION_NONE = (UART_CTL0_RXE_DISABLE | UART_CTL0_TXE_DISABLE)
} DL_UART_DIRECTION;

/*! @enum DL_UART_CLOCK */
typedef enum {
    /*! Selects BUSCLK as the clock source */
    DL_UART_CLOCK_BUSCLK = UART_CLKSEL_BUSCLK_SEL_ENABLE,
    /*! Selects MFCLK as the clock source */
    DL_UART_CLOCK_MFCLK = UART_CLKSEL_MFCLK_SEL_ENABLE,
    /*! Selects LFCLK as the clock source */
    DL_UART_CLOCK_LFCLK = UART_CLKSEL_LFCLK_SEL_ENABLE
} DL_UART_CLOCK;

/*! @enum DL_UART_FLOW_CONTROL */
typedef enum {
    /*! Enable request to send */
    DL_UART_FLOW_CONTROL_RTS = UART_CTL0_RTSEN_ENABLE,
    /*! Enable clear to send */
    DL_UART_FLOW_CONTROL_CTS = UART_CTL0_CTSEN_ENABLE,
    /*! Enable request to send and clear to send */
    DL_UART_FLOW_CONTROL_RTS_CTS = (UART_CTL0_RTSEN_ENABLE | UART_CTL0_CTSEN_ENABLE),
    /*! Disable flow control */
    DL_UART_FLOW_CONTROL_NONE = (UART_CTL0_CTSEN_DISABLE | UART_CTL0_RTSEN_DISABLE)
} DL_UART_FLOW_CONTROL;

/*! @enum DL_UART_RTS */
typedef enum {
    /*! RTS is asserted indicating data in RX FIFO is below threshold */
    DL_UART_RTS_ASSERT = UART_CTL0_RTS_SET,
    /*! RTS is deasserted indicating data in RX FIFO is at or above threshold */
    DL_UART_RTS_DEASSERT = UART_CTL0_RTS_CLR
} DL_UART_RTS;

/*! @enum DL_UART_STOP_BITS */
typedef enum {
    /*! One stop bit is transmitted at the end of the frame */
    DL_UART_STOP_BITS_ONE = UART_LCRH_STP2_DISABLE,
    /*! Two stop bits are transmitted at the end of the frame */
    DL_UART_STOP_BITS_TWO = UART_LCRH_STP2_ENABLE
} DL_UART_STOP_BITS;

/*! @enum DL_UART_TXD_OUT */
typedef enum {
    /*! TXD pin is low */
    DL_UART_TXD_OUT_LOW = UART_CTL0_TXD_OUT_LOW,
    /*! TXD pin is high */
    DL_UART_TXD_OUT_HIGH = UART_CTL0_TXD_OUT_HIGH
} DL_UART_TXD_OUT;

/*! @enum DL_UART_TX_FIFO_LEVEL */
typedef enum {
    /*! Interrupt triggers when FIFO <= 3/4 empty */
    DL_UART_TX_FIFO_LEVEL_3_4_EMPTY = UART_IFLS_TXIFLSEL_LVL_3_4,
    /*! Interrupt triggers when FIFO <= 1/2 empty */
    DL_UART_TX_FIFO_LEVEL_1_2_EMPTY = UART_IFLS_TXIFLSEL_LVL_1_2,
    /*! Interrupt triggers when FIFO <= 1/4 empty */
    DL_UART_TX_FIFO_LEVEL_1_4_EMPTY = UART_IFLS_TXIFLSEL_LVL_1_4,
    /*! Interrupt triggers when FIFO is empty */
    DL_UART_TX_FIFO_LEVEL_EMPTY = UART_IFLS_TXIFLSEL_LVL_EMPTY,
    /*! Interrupt triggers when FIFO >= 1 entry */
    DL_UART_TX_FIFO_LEVEL_ONE_ENTRY = UART_IFLS_TXIFLSEL_LVL_1
} DL_UART_TX_FIFO_LEVEL;

/*! @enum DL_UART_RX_FIFO_LEVEL */
typedef enum {
    /*! Interrupt triggers when FIFO >= 1 entry available. Required for
     *! DMA trigger */
    DL_UART_RX_FIFO_LEVEL_ONE_ENTRY = UART_IFLS_RXIFLSEL_LVL_1,
    /*! Interrupt triggers when FIFO is full */
    DL_UART_RX_FIFO_LEVEL_FULL = UART_IFLS_RXIFLSEL_LVL_FULL,
    /*! Interrupt triggers when FIFO >= 3/4 full */
    DL_UART_RX_FIFO_LEVEL_3_4_FULL = UART_IFLS_RXIFLSEL_LVL_3_4,
    /*! Interrupt triggers when FIFO >= 1/2 full */
    DL_UART_RX_FIFO_LEVEL_1_2_FULL = UART_IFLS_RXIFLSEL_LVL_1_2,
    /*! Interrupt triggers when FIFO >= 1/4 full */
    DL_UART_RX_FIFO_LEVEL_1_4_FULL = UART_IFLS_RXIFLSEL_LVL_1_4,
} DL_UART_RX_FIFO_LEVEL;

/*! @enum DL_UART_IRDA_CLOCK */
typedef enum {
    /*! IrDA encode data is based on the Baud Rate clock */
    DL_UART_IRDA_CLOCK_BAUD_RATE = UART_IRCTL_IRTXCLK_BRCLK,
    /*! IrDA encode data is based on the Functional clock */
    DL_UART_IRDA_CLOCK_FUNCTIONAL = UART_IRCTL_IRTXCLK_BITCLK
} DL_UART_IRDA_CLOCK;

/*! @enum DL_UART_IRDA_POLARITY */
typedef enum {
    /*! IrDA transceiver delivers a low pulse when a light pulse is seen */
    DL_UART_IRDA_POLARITY_LOW = UART_IRCTL_IRRXPL_LOW,
    /*! IrDA transceiver delivers a high pulse when a light pulse is seen */
    DL_UART_IRDA_POLARITY_HIGH = UART_IRCTL_IRRXPL_HIGH
} DL_UART_IRDA_POLARITY;

/*!
 * @brief Sets the IrDA pulse width to 3/16 bit period when using the BITCLK16
 */
#define DL_UART_PULSE_WIDTH_3_16_BIT_PERIOD           ((uint32_t) 0x00000000U)

/*! @enum DL_UART_CLOCK_DIVIDE_RATIO */
typedef enum {
    /*! UART source clock divide ratio set to 1 */
    DL_UART_CLOCK_DIVIDE_RATIO_1 = UART_CLKDIV_RATIO_DIV_BY_1,
    /*! UART source clock divide ratio set to 2 */
    DL_UART_CLOCK_DIVIDE_RATIO_2 = UART_CLKDIV_RATIO_DIV_BY_2,
    /*! UART source clock divide ratio set to 3 */
    DL_UART_CLOCK_DIVIDE_RATIO_3 = UART_CLKDIV_RATIO_DIV_BY_3,
    /*! UART source clock divide ratio set to 4 */
    DL_UART_CLOCK_DIVIDE_RATIO_4 = UART_CLKDIV_RATIO_DIV_BY_4,
    /*! UART source clock divide ratio set to 5 */
    DL_UART_CLOCK_DIVIDE_RATIO_5 = UART_CLKDIV_RATIO_DIV_BY_5,
    /*! UART source clock divide ratio set to 6 */
    DL_UART_CLOCK_DIVIDE_RATIO_6 = UART_CLKDIV_RATIO_DIV_BY_6,
    /*! UART source clock divide ratio set to 7 */
    DL_UART_CLOCK_DIVIDE_RATIO_7 = UART_CLKDIV_RATIO_DIV_BY_7,
    /*! UART source clock divide ratio set to 8 */
    DL_UART_CLOCK_DIVIDE_RATIO_8 = UART_CLKDIV_RATIO_DIV_BY_8
} DL_UART_CLOCK_DIVIDE_RATIO;

/*! @enum DL_UART_CLOCK_DIVIDE2_RATIO */
typedef enum {
    /*! UART source clock divide 2 ratio set to 1 */
    DL_UART_CLOCK_DIVIDE2_RATIO_1 = UART_CLKDIV2_RATIO_DIV_BY_1,
    /*! UART source clock divide 2 ratio set to 2 */
    DL_UART_CLOCK_DIVIDE2_RATIO_2 = UART_CLKDIV2_RATIO_DIV_BY_2,
    /*! UART source clock divide 2 ratio set to 3 */
    DL_UART_CLOCK_DIVIDE2_RATIO_3 = UART_CLKDIV2_RATIO_DIV_BY_3,
    /*! UART source clock divide 2 ratio set to 4 */
    DL_UART_CLOCK_DIVIDE2_RATIO_4 = UART_CLKDIV2_RATIO_DIV_BY_4,
    /*! UART source clock divide 2 ratio set to 5 */
    DL_UART_CLOCK_DIVIDE2_RATIO_5 = UART_CLKDIV2_RATIO_DIV_BY_5,
    /*! UART source clock divide 2 ratio set to 6 */
    DL_UART_CLOCK_DIVIDE2_RATIO_6 = UART_CLKDIV2_RATIO_DIV_BY_6,
    /*! UART source clock divide 2 ratio set to 7 */
    DL_UART_CLOCK_DIVIDE2_RATIO_7 = UART_CLKDIV2_RATIO_DIV_BY_7,
    /*! UART source clock divide 2 ratio set to 8 */
    DL_UART_CLOCK_DIVIDE2_RATIO_8 = UART_CLKDIV2_RATIO_DIV_BY_8
} DL_UART_CLOCK_DIVIDE2_RATIO;

/* clang-format on */

/*!
 *  @brief  Configuration struct for @ref DL_UART_init
 */
typedef struct {
    /*! The communication mode and protocol used. One of @ref DL_UART_MODE */
    DL_UART_MODE mode;

    /*! The communication direction. One of @ref DL_UART_DIRECTION. */
    DL_UART_DIRECTION direction;

    /*! The flow control configuration. One of @ref DL_UART_FLOW_CONTROL */
    DL_UART_FLOW_CONTROL flowControl;

    /*! The parity configuration. One of @ref DL_UART_PARITY */
    DL_UART_PARITY parity;

    /*! The size of the data transfer. One of @ref DL_UART_WORD_LENGTH */
    DL_UART_WORD_LENGTH wordLength;

    /*! One of @ref DL_UART_STOP_BITS  */
    DL_UART_STOP_BITS stopBits;

} DL_UART_Config;

/*!
 *  @brief  Configuration struct for @ref DL_UART_setClockConfig.
 */
typedef struct {
    /*! Selects uart module clock source @ref DL_UART_CLOCK */
    DL_UART_CLOCK clockSel;

    /*! Selects the divide ratio. One of @ref DL_UART_CLOCK_DIVIDE_RATIO */
    DL_UART_CLOCK_DIVIDE_RATIO divideRatio;

} DL_UART_ClockConfig;

#ifdef __MSPM0_HAS_UART_MAIN__

/**
 * @brief Configuration structure to backup UART Main peripheral state before
 *        going to STOP/STANDBY mode. Used by
 *        @ref DL_UART_Main_saveConfiguration and
 *        @ref DL_UART_Main_restoreConfiguration
 */
typedef struct {
    /*! Combination of basic UART control configurations that are
     *  compressed to a single word as they are stored in the UART
     *  registers. See @ref DL_UART_init for how the peripheral control word
     *  is created. */
    uint32_t controlWord;

    /*! UART module clock source. One of  @ref DL_UART_CLOCK */
    uint32_t clockSel;

    /*! UART clock divider. One of @ref DL_UART_CLOCK_DIVIDE_RATIO */
    uint32_t divideRatio;

    /*! Combination of UART interrupt FIFO level select configurations that are
     *  compressed to a single word as they are stored in the UART
     * registers. */
    uint32_t interruptFifoLevelSelectWord;

    /*! UART integer baud rate divisor. Value between 0 - 65535. */
    uint32_t ibrd;

    /*! UART fractional baud rate divisor. Value between 0 - 63. */
    uint32_t fbrd;

    /*! Combination of UART Line Control Register configurations that are
     *  compressed to a single word as they are stored in the UART
     *  registers. See @ref DL_UART_init for how the peripheral control word
     *  is created. */
    uint32_t lineControlRegisterWord;

    /*! Combination of UART glitch filter configurations that are
     *  compressed to a single word as they are stored in the UART
     *  registers. */
    uint32_t glitchFilterControlWord;

    /*! UART interrupt mask for EVENT0.
     * Bitwise OR of @ref DL_UART_INTERRUPT */
    uint32_t interruptMask0;

    /*! UART interrupt mask for EVENT1.
     * Bitwise OR of @ref DL_UART_DMA_INTERRUPT_RX */
    uint32_t interruptMask1;

    /*! UART interrupt mask for EVENT2.
     * Bitwise OR of @ref DL_UART_DMA_INTERRUPT_TX */
    uint32_t interruptMask2;

    /*! Boolean flag indicating whether or not a valid configuration structure
     *  exists. Should not be modified by the user. */
    bool backupRdy;
} DL_UART_Main_backupConfig;

#endif /* __MSPM0_HAS_UART_MAIN__ */

#ifdef __MSPM0_HAS_UART_EXTD__

/**
 * @brief Configuration structure to backup UART Extend peripheral state before
 *        going to STOP/STANDBY mode. Used by
 *        @ref DL_UART_Extend_saveConfiguration and
 *        @ref DL_UART_Extend_restoreConfiguration
 */
typedef struct {
    /*! Combination of basic UART control configurations that are
     *  compressed to a single word as they are stored in the UART
     *  registers. See @ref DL_UART_init for how the peripheral control word
     *  is created. */
    uint32_t controlWord;

    /*! UART module clock source. One of  @ref DL_UART_CLOCK */
    uint32_t clockSel;

    /*! UART clock divider. One of @ref DL_UART_CLOCK_DIVIDE_RATIO */
    uint32_t divideRatio;

    /*! Combination of UART Line Control Register configurations that are
     *  compressed to a single word as they are stored in the UART
     *  registers. See @ref DL_UART_init for how the peripheral control word
     *  is created. */
    uint32_t lineControlRegisterWord;

    /*! Combination of UART interrupt FIFO level select configurations that are
     *  compressed to a single word as they are stored in the UART
     * registers. */
    uint32_t interruptFifoLevelSelectWord;

    /*! UART integer baud rate divisor. Value between 0 - 65535. */
    uint32_t ibrd;

    /*! UART fractional baud rate divisor. Value between 0 - 63. */
    uint32_t fbrd;

    /*! Combination of UART glitch filter configurations that are
     *  compressed to a single word as they are stored in the UART
     *  registers. */
    uint32_t glitchFilterControlWord;

    /*! Combination of UART LIN basic configurations that are
     *  compressed to a single word as they are stored in the UART
     *  registers. */
    uint32_t linControlWord;

    /*! Combination of UART IrDA basic configurations that are
     *  compressed to a single word as they are stored in the UART
     *  registers. */
    uint32_t irdaControlWord;

    /*! UART address mask for 9-bit or Idle mode. */
    uint32_t addressMask;

    /*! UART address that should be matched for 9-bit or Idle mode. */
    uint32_t address;

    /*! UART interrupt status for EVENT0.
     * Bitwise OR of @ref DL_UART_INTERRUPT */
    uint32_t interruptMask0;

    /*! UART interrupt status for EVENT1.
     * Bitwise OR of @ref DL_UART_DMA_INTERRUPT_RX */
    uint32_t interruptMask1;

    /*! UART interrupt status for EVENT2.
     * Bitwise OR of @ref DL_UART_DMA_INTERRUPT_TX */
    uint32_t interruptMask2;

    /*! Boolean flag indicating whether or not a valid configuration structure
     *  exists. Should not be modified by the user. */
    bool backupRdy;
} DL_UART_Extend_backupConfig;

#endif /* __MSPM0_HAS_UART_EXTD__ */

/**
 *  @brief      Initialize the UART peripheral
 *
 *  Initializes all the common configurable options for the UART peripheral. Any
 *  other custom configuration can be done after calling this API. The UART is
 *  not enabled in this API.
 *
 *  @param[in]  uart    Pointer to the register overlay for the peripheral
 *  @param[in]  config  Configuration for UART peripheral
 */
void DL_UART_init(UART_Regs *uart, DL_UART_Config *config);

/**
 * @brief Enables power on UART module
 *
 * @param uart        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enablePower(UART_Regs *uart)
{
    uart->GPRCM.PWREN = (UART_PWREN_KEY_UNLOCK_W | UART_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Disables power on uart module
 *
 * @param uart        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disablePower(UART_Regs *uart)
{
    uart->GPRCM.PWREN = (UART_PWREN_KEY_UNLOCK_W | UART_PWREN_ENABLE_DISABLE);
}

/**
 * @brief Returns if  power on uart module
 *
 * @param uart        Pointer to the register overlay for the peripheral
 *
 * @return true if power is enabled
 * @return false if power is disabled
 */
__STATIC_INLINE bool DL_UART_isPowerEnabled(UART_Regs *uart)
{
    return ((uart->GPRCM.PWREN & UART_PWREN_ENABLE_MASK) ==
            UART_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Resets uart peripheral
 *
 * @param uart        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_reset(UART_Regs *uart)
{
    uart->GPRCM.RSTCTL =
        (UART_RSTCTL_KEY_UNLOCK_W | UART_RSTCTL_RESETSTKYCLR_CLR |
            UART_RSTCTL_RESETASSERT_ASSERT);
}

/**
 * @brief Returns if uart peripheral was reset
 *
 * @param uart        Pointer to the register overlay for the peripheral
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_UART_isReset(UART_Regs *uart)
{
    return ((uart->GPRCM.STAT & UART_GPRCM_STAT_RESETSTKY_MASK) ==
            UART_GPRCM_STAT_RESETSTKY_RESET);
}

/**
 *  @brief      Enable the UART peripheral
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enable(UART_Regs *uart)
{
    uart->CTL0 |= UART_CTL0_ENABLE_ENABLE;
}

/**
 *  @brief      Checks if the UART peripheral is enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the enabled status of the UART
 *
 *  @retval     true  The UART peripheral is enabled
 *  @retval     false The UART peripheral is disabled

 */
__STATIC_INLINE bool DL_UART_isEnabled(UART_Regs *uart)
{
    return ((uart->CTL0 & UART_CTL0_ENABLE_MASK) == UART_CTL0_ENABLE_ENABLE);
}

/**
 *  @brief      Disable the UART peripheral
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disable(UART_Regs *uart)
{
    uart->CTL0 &= ~(UART_CTL0_ENABLE_MASK);
}

/**
 *  @brief      Configure UART source clock
 *
 *  @param[in]  uart    Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  config  Pointer to the clock configuration struct
 *                       @ref DL_UART_ClockConfig.
 */
void DL_UART_setClockConfig(UART_Regs *uart, DL_UART_ClockConfig *config);

/**
 *  @brief      Get UART source clock configuration
 *
 *  @param[in]  uart    Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  config  Pointer to the clock configuration struct
 *                      @ref DL_UART_ClockConfig.
 */
void DL_UART_getClockConfig(UART_Regs *uart, DL_UART_ClockConfig *config);

/**
 *  @brief      Configure the baud rate
 *
 *  Given the target baud rate and the frequency of the UART clock source, this
 *  API determines and sets the recommended oversampling setting, and then
 *  calculates and sets the required baud rate divisors.
 *
 * The oversampling rate that will be set is the highest possible oversampling
 * rate given the target baud rate and UART clock frequency.
 *
 * If the user wishes to avoid having the CPU calculate the baud rate divisors
 * or not use the recommended calculated values, the user can call
 * @ref DL_UART_setOversampling and @ref DL_UART_setBaudRateDivisor directly.
 *
 *  @param[in]  uart       Pointer to the register overlay for the peripheral
 *  @param[in]  clockFreq  The clock frequency in Hz of the UART clock source
 *  @param[in]  baudRate   The target baud rate
 *
 * @sa          DL_UART_setOversampling
 * @sa          DL_UART_setBaudRateDivisor
 */
void DL_UART_configBaudRate(
    UART_Regs *uart, uint32_t clockFreq, uint32_t baudRate);

/**
 *  @brief      Set the oversampling rate
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *  @param[in]  rate  The oversampling rate to use.
 *                    One of @ref DL_UART_OVERSAMPLING_RATE
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 */
__STATIC_INLINE void DL_UART_setOversampling(
    UART_Regs *uart, DL_UART_OVERSAMPLING_RATE rate)
{
    DL_Common_updateReg(&uart->CTL0, (uint32_t) rate, UART_CTL0_HSE_MASK);
}

/**
 *  @brief      Get the oversampling rate
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The current oversampling rate
 *
 *  @retval     One of @ref DL_UART_OVERSAMPLING_RATE
 *
 */
__STATIC_INLINE DL_UART_OVERSAMPLING_RATE DL_UART_getOversampling(
    UART_Regs *uart)
{
    uint32_t rate = uart->CTL0 & UART_CTL0_HSE_MASK;

    return (DL_UART_OVERSAMPLING_RATE)(rate);
}

/**
 *  @brief      Enable loopback mode
 *
 *  Enables the loopback mode. When enabled, the UARTxTXD path is fed through
 *  the UARTxRXD path.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 */
__STATIC_INLINE void DL_UART_enableLoopbackMode(UART_Regs *uart)
{
    uart->CTL0 |= UART_CTL0_LBE_ENABLE;
}

/**
 *  @brief      Check if loopback mode is enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of loopback mode
 *
 *  @retval     true  Loopback mode is enabled
 *  @retval     false Loopback mode is disabled
 */
__STATIC_INLINE bool DL_UART_isLoopbackModeEnabled(UART_Regs *uart)
{
    return ((uart->CTL0 & UART_CTL0_LBE_MASK) == UART_CTL0_LBE_ENABLE);
}

/**
 *  @brief      Disable loopback mode
 *
 *  Disables the loopback mode. When disabled, the UARTxTXD path is not fed through
 *  the UARTxRXD path.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 */
__STATIC_INLINE void DL_UART_disableLoopbackMode(UART_Regs *uart)
{
    uart->CTL0 &= ~(UART_CTL0_LBE_MASK);
}

/**
 *  @brief      Set the direction of the UART communication
 *
 *  If the UART is disabled in the middle of a transmit or receive, it
 *  completes the current character before stopping.
 *
 *  @param[in]  uart       Pointer to the register overlay for the peripheral
 *  @param[in]  direction  Direction to set UART communication to.
 *                         One of @ref DL_UART_DIRECTION.
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 *
 */
__STATIC_INLINE void DL_UART_setDirection(
    UART_Regs *uart, DL_UART_DIRECTION direction)
{
    DL_Common_updateReg(&uart->CTL0, (uint32_t) direction,
        UART_CTL0_TXE_MASK | UART_CTL0_RXE_MASK);
}

/**
 *  @brief      Get the direction of the UART communication
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The direction of UART communication.
 *
 *  @retval     One of @ref DL_UART_DIRECTION
 */
__STATIC_INLINE DL_UART_DIRECTION DL_UART_getDirection(UART_Regs *uart)
{
    uint32_t direction =
        uart->CTL0 & (UART_CTL0_TXE_MASK | UART_CTL0_RXE_MASK);

    return (DL_UART_DIRECTION)(direction);
}

/**
 *  @brief      Enable majority voting control
 *
 *  When enabled, the three center bits are used to determine received sample
 *  value. The value corresponding to at least two of the three samples is
 *  considered to be the received value.In case of error (i.e. all 3 bits are
 *  not the same), noise error is detected and bits RIS.NERR and register
 *  RXDATA.NERR are set.
 *
 *  When enabled with oversampling of 16, samples 7, 8, and 9 are
 *  majority voted to decide the sampled bit value.
 *
 *  When enabled with oversampling of 8, samples 3, 4, and 5 are majority
 *  voted to decide the sampled bit value. The value corresponding to at least 2
 *  of the 3 samples is considered to be the received value.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 *
 *  @sa          DL_UART_setOversampling
 */
__STATIC_INLINE void DL_UART_enableMajorityVoting(UART_Regs *uart)
{
    uart->CTL0 |= UART_CTL0_MAJVOTE_ENABLE;
}

/**
 *  @brief      Check if majority voting is enabled
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *
 *  @return     The status of majority control feature
 *
 *  @retval     true  Majority voting is enabled
 *  @retval     false Majority voting is disabled
 */
__STATIC_INLINE bool DL_UART_isMajorityVotingEnabled(UART_Regs *uart)
{
    return ((uart->CTL0 & UART_CTL0_MAJVOTE_MASK) == UART_CTL0_MAJVOTE_ENABLE);
}

/**
 *  @brief      Disable majority voting control
 *
 *  When disabled, only a single sample of the received bit of is taken.
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 */
__STATIC_INLINE void DL_UART_disableMajorityVoting(UART_Regs *uart)
{
    uart->CTL0 &= ~(UART_CTL0_MAJVOTE_MASK);
}

/**
 *  @brief      Enable most significant bit (MSB) first
 *
 *  When enabled, the most significant bit (MSB) is sent first in the protocol
 *  packet. This bit has effect on both the way the protocol byte is
 *  transmitted and received.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 */
__STATIC_INLINE void DL_UART_enableMSBFirst(UART_Regs *uart)
{
    uart->CTL0 |= UART_CTL0_MSBFIRST_ENABLE;
}

/**
 *  @brief      Check if most significant bit (MSB) first is enabled
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *
 *  @return     The status of majority control feature
 *
 *  @retval     true  MSB first is enabled
 *  @retval     false MSB first is disabled
 */
__STATIC_INLINE bool DL_UART_isMSBFirstEnabled(UART_Regs *uart)
{
    return (
        (uart->CTL0 & UART_CTL0_MSBFIRST_MASK) == UART_CTL0_MSBFIRST_ENABLE);
}

/**
 *  @brief      Disable most significant bit (MSB) first
 *
 *  When disabled, the least significant bit (LSB) is sent first in the protocol
 *  packet. This bit has effect on both the way the protocol byte is
 *  transmitted and received.
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 */
__STATIC_INLINE void DL_UART_disableMSBFirst(UART_Regs *uart)
{
    uart->CTL0 &= ~(UART_CTL0_MSBFIRST_MASK);
}

/**
 *  @brief      Enable control of the TXD pin
 *
 *  When enabled, the TXD pin can be controlled by the TXD_OUT bit. The UART
 *  transmit section must first be disabled.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 *
 *  @sa          DL_UART_setDirection
 *  @sa          DL_UART_setTXDPin
 */
__STATIC_INLINE void DL_UART_enableTransmitPinManualControl(UART_Regs *uart)
{
    uart->CTL0 |= UART_CTL0_TXD_OUT_EN_ENABLE;
}

/**
 *  @brief      Check if control of the TXD pin is enabled
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *
 *  @return     The status of control of the TXD pin
 *
 *  @retval     true  Control of the TXD pin is enabled
 *  @retval     false Control of the TXD pin is disabled
 */
__STATIC_INLINE bool DL_UART_isTransmitPinManualControlEnabled(UART_Regs *uart)
{
    return ((uart->CTL0 & UART_CTL0_TXD_OUT_EN_MASK) ==
            UART_CTL0_TXD_OUT_EN_ENABLE);
}

/**
 *  @brief      Disable control of the TXD pin
 *
 *  When disabled, the TXD pin can not be controlled by the TXD_OUT bit
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 */
__STATIC_INLINE void DL_UART_disableTransmitPinManualControl(UART_Regs *uart)
{
    uart->CTL0 &= ~(UART_CTL0_TXD_OUT_EN_MASK);
}

/**
 *  @brief      Set the output of the TXD pin
 *
 *  Control the output transmit data pin only when TXD_OUT_EN is enabled and
 *  TXE is disabled.
 *
 *  The TXD pin is set to manual control if it hadn't been
 *  previously set.
 *
 *  @param[in]  uart       Pointer to the register overlay for the peripheral
 *  @param[in]  txdOutVal  Value to set the TXD pin output to.
 *                         One of @ref DL_UART_TXD_OUT
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 *
 *  @sa          DL_UART_disableTransmit
 *  @sa          DL_UART_enableTransmitPinManualControl
 */
__STATIC_INLINE void DL_UART_setTransmitPinManualOutput(
    UART_Regs *uart, DL_UART_TXD_OUT txdOutVal)
{
    DL_Common_updateReg(&uart->CTL0,
        UART_CTL0_TXD_OUT_EN_ENABLE | (uint32_t) txdOutVal,
        UART_CTL0_TXD_OUT_EN_MASK | UART_CTL0_TXD_OUT_MASK);
}

/**
 *  @brief      Get the output value of the TXD pin
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The value of the TXD pin
 *
 *  @retval     One of @ref DL_UART_TXD_OUT
 */
__STATIC_INLINE DL_UART_TXD_OUT DL_UART_getTransmitPinManualOutput(
    UART_Regs *uart)
{
    uint32_t txdOutVal = uart->CTL0 & UART_CTL0_TXD_OUT_MASK;

    return (DL_UART_TXD_OUT)(txdOutVal);
}

/**
 *  @brief      Enable Manchester encoding
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enableManchesterEncoding(UART_Regs *uart)
{
    uart->CTL0 |= UART_CTL0_MENC_ENABLE;
}

/**
 *  @brief      Disable Manchester encoding
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableManchesterEncoding(UART_Regs *uart)
{
    uart->CTL0 &= ~(UART_CTL0_MENC_MASK);
}

/**
 *  @brief      Check if Manchester encoding is enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of Manchester encode
 *
 *  @retval     true  Manchester encoding is enabled
 *  @retval     false Manchester encoding is disabled
 */
__STATIC_INLINE bool DL_UART_isManchesterEncodingEnabled(UART_Regs *uart)
{
    return ((uart->CTL0 & UART_CTL0_MENC_MASK) == UART_CTL0_MENC_ENABLE);
}

/**
 *  @brief      Set the communication mode/protocol to use
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *  @param[in]  mode  Value to set the UART communication protocol to.
 *                     One of @ref DL_UART_MODE
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 */
__STATIC_INLINE void DL_UART_setCommunicationMode(
    UART_Regs *uart, DL_UART_MODE mode)
{
    DL_Common_updateReg(&uart->CTL0, (uint32_t) mode, UART_CTL0_MODE_MASK);
}

/**
 *  @brief      Get the communication mode/protocol being used
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The communication mode/protocol being used by the UART
 *
 *  @retval     One of @ref DL_UART_MODE
 */
__STATIC_INLINE DL_UART_MODE DL_UART_getCommunicationMode(UART_Regs *uart)
{
    uint32_t mode = uart->CTL0 & UART_CTL0_MODE_MASK;

    return (DL_UART_MODE)(mode);
}

/**
 *  @brief      Set the flow control configuration
 *
 *  @param[in]  uart    Pointer to the register overlay for the peripheral
 *  @param[in]  config  The flow control configuration to use.
 *                      One of @ref DL_UART_FLOW_CONTROL.
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 */
__STATIC_INLINE void DL_UART_setFlowControl(
    UART_Regs *uart, DL_UART_FLOW_CONTROL config)
{
    DL_Common_updateReg(&uart->CTL0, (uint32_t) config,
        UART_CTL0_RTSEN_MASK | UART_CTL0_CTSEN_MASK);
}

/**
 *  @brief      Check the flow control configuration
 *
 *  @param[in]  uart  Pointer to the register overlay for the
 *                    peripheral
 *
 *  @return     The flow control configuration
 *
 *  @retval     One of @ref DL_UART_FLOW_CONTROL values
 */
__STATIC_INLINE DL_UART_FLOW_CONTROL DL_UART_getFlowControl(UART_Regs *uart)
{
    uint32_t config =
        uart->CTL0 & (UART_CTL0_RTSEN_MASK | UART_CTL0_CTSEN_MASK);

    return (DL_UART_FLOW_CONTROL)(config);
}

/**
 *  @brief      Set the request to send output signal
 *
 *  The RTS output signal indicates the state of the RX FIFO, and is
 *  linked to the programmable receive FIFO threshold levels. When RTS flow
 *  control is enabled, the RTS signal is asserted (low) when the data in the
 *  RX FIFO is less than the threshold level. When the RX FIFO threshold level
 *  is reached, the RTS signal is deasserted (high). The RTS signal is
 *  reasserted (low) when data has been read out  of the RX FIFO so it is less
 *  than the threshold.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *  @param[in]  val   The RTS output signal. One of @ref DL_UART_RTS
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 *
 *  @sa         DL_UART_setTXFIFOThreshold
 */
__STATIC_INLINE void DL_UART_setRTSOutput(UART_Regs *uart, DL_UART_RTS val)
{
    DL_Common_updateReg(&uart->CTL0, (uint32_t) val, UART_CTL0_RTS_MASK);
}

/**
 *  @brief      Get the request to send output signal
 *
 *  The RTS output signal indicates the state of the RX FIFO, and is
 *  linked to the programmable receive FIFO threshold levels. When RTS flow
 *  control is enabled, the RTS signal is asserted (low) when the data in the
 *  RX FIFO is less than the threshold level. When the RX FIFO threshold level
 *  is reached, the RTS signal is deasserted (high). The RTS signal is
 *  reasserted (low) when data has been read out  of the RX FIFO so it is less
 *  than the threshold.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The RTS signal status
 *
 *  @retval     One of @ref DL_UART_RTS
 *
 *  @sa         DL_UART_setTXFIFOThreshold
 */
__STATIC_INLINE DL_UART_RTS DL_UART_getRTSOutput(UART_Regs *uart)
{
    uint32_t val = uart->CTL0 & UART_CTL0_RTS_MASK;

    return (DL_UART_RTS)(val);
}

/**
 *  @brief      Enable FIFOs
 *
 *  Enables the transmit and receive FIFO buffers.
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *
 *  @sa         DL_UART_init
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 */
__STATIC_INLINE void DL_UART_enableFIFOs(UART_Regs *uart)
{
    uart->CTL0 |= UART_CTL0_FEN_ENABLE;
}

/**
 *  @brief      Disable FIFOs
 *
 *  Disables the transmit and receive FIFO buffers. The receiver will now
 *  only hold 1-byte of data.
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *
 *  @pre  If the UART has already been enabled, then it must be made ready for
 *        configuration by first calling @ref DL_UART_changeConfig
 *  @post If @ref DL_UART_changeConfig was called, then the UART must be
 *        re-enabled by calling @ref DL_UART_enable
 */
__STATIC_INLINE void DL_UART_disableFIFOs(UART_Regs *uart)
{
    uart->CTL0 &= ~(UART_CTL0_FEN_MASK);
}

/**
 *  @brief      Check if FIFOs are enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of the FIFOs
 *
 *  @retval     true  FIFOs are enabled
 *  @retval     false FIFOs are disabled
 */
__STATIC_INLINE bool DL_UART_isFIFOsEnabled(UART_Regs *uart)
{
    return ((uart->CTL0 & UART_CTL0_FEN_MASK) == UART_CTL0_FEN_ENABLE);
}

/**
 *  @brief      Enable send break (for LIN protocol)
 *
 *  When enabled, a low level is continually output on the TXD signal after completing
 *  transmission of the current character. For the proper execution of the
 *  break command, software must set this bit for at least two frames (character periods).
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enableLINSendBreak(UART_Regs *uart)
{
    uart->LCRH |= UART_LCRH_BRK_ENABLE;
}

/**
 *  @brief      Disable send break
 *
 *  When disabled, a low level is not continually output on the TXD signal
 *  after completing transmission of the current character.
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableLINSendBreak(UART_Regs *uart)
{
    uart->LCRH &= ~(UART_LCRH_BRK_MASK);
}

/**
 *  @brief      Check if send break is enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of send break
 *
 *  @retval     true  Send break is enabled
 *  @retval     false Send break is disabled
 */
__STATIC_INLINE bool DL_UART_isLINSendBreakEnabled(UART_Regs *uart)
{
    return ((uart->LCRH & UART_LCRH_BRK_MASK) == UART_LCRH_BRK_ENABLE);
}

/**
 *  @brief      Check if parity is enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of parity
 *
 *  @retval     true  Parity is enabled
 *  @retval     false Parity is disabled
 */
__STATIC_INLINE bool DL_UART_isParityEnabled(UART_Regs *uart)
{
    return ((uart->LCRH & UART_LCRH_PEN_MASK) == UART_LCRH_PEN_ENABLE);
}

/**
 *  @brief      Set the parity mode
 *
 *  For 9-bit UART mode transmissions, the parity mode affects the address
 *  byte and data byte indication (9th bit). If DL_UART_PARITY_EVEN or
 *  DL_UART_PARITY_STICK_ZERO is enabled, then the transferred byte is a data
 *  byte.  If DL_UART_PARITY_EVEN or DL_UART_PARITY_STICK_ZERO is not enabled,
 *  then the transferred byte is an address byte.
 *
 *  @param[in]  uart    Pointer to the register overlay for the peripheral
 *  @param[in]  parity  Parity mode to set UART to.
 *                      One of @ref DL_UART_PARITY
 */
__STATIC_INLINE void DL_UART_setParityMode(
    UART_Regs *uart, DL_UART_PARITY parity)
{
    DL_Common_updateReg(&uart->LCRH, (uint32_t) parity,
        (UART_LCRH_PEN_MASK | UART_LCRH_EPS_MASK | UART_LCRH_SPS_MASK));
}

/**
 *  @brief      Get parity mode
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The current parity mode being used
 *
 *  @retval     One of @ref DL_UART_PARITY
 *
 */
__STATIC_INLINE DL_UART_PARITY DL_UART_getParityMode(UART_Regs *uart)
{
    uint32_t parity = uart->LCRH & (UART_LCRH_PEN_MASK | UART_LCRH_EPS_MASK |
                                       UART_LCRH_SPS_MASK);

    return (DL_UART_PARITY)(parity);
}

/**
 *  @brief      Set the number of stop bits
 *
 *  When in 7816 smart code mode (DL_UART_MODE_SMART_CARD mode), the number of
 *  stop bits is forced to 2
 *
 *  @param[in]  uart         Pointer to the register overlay for the peripheral
 *  @param[in]  numStopBits  The number of stop bits transmitted.
 *                           One of @ref DL_UART_STOP_BITS
 */
__STATIC_INLINE void DL_UART_setStopBits(
    UART_Regs *uart, DL_UART_STOP_BITS numStopBits)
{
    DL_Common_updateReg(
        &uart->LCRH, (uint32_t) numStopBits, UART_LCRH_STP2_MASK);
}

/**
 *  @brief      Get the number of stop bits
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The number of stop bits transmitted.
 *
 *  @retval     One of @ref DL_UART_STOP_BITS
 */
__STATIC_INLINE DL_UART_STOP_BITS DL_UART_getStopBits(UART_Regs *uart)
{
    uint32_t numStopBits = uart->LCRH & UART_LCRH_STP2_MASK;

    return (DL_UART_STOP_BITS)(numStopBits);
}

/**
 *  @brief      Set the word length
 *
 *  @param[in]  uart        Pointer to the register overlay for the peripheral
 *  @param[in]  wordLength  The number of data bits transmitted or received in
 *                           a frame. One of @ref DL_UART_WORD_LENGTH
 */
__STATIC_INLINE void DL_UART_setWordLength(
    UART_Regs *uart, DL_UART_WORD_LENGTH wordLength)
{
    DL_Common_updateReg(
        &uart->LCRH, (uint32_t) wordLength, UART_LCRH_WLEN_MASK);
}

/**
 *  @brief      Get the word length
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The length of the data bits transmitted or received in a frame
 *
 *  @retval     One of @ref DL_UART_WORD_LENGTH
 */
__STATIC_INLINE DL_UART_WORD_LENGTH DL_UART_getWordLength(UART_Regs *uart)
{
    uint32_t wordLength = uart->LCRH & UART_LCRH_WLEN_MASK;

    return (DL_UART_WORD_LENGTH)(wordLength);
}

/**
 *  @brief      Send idle pattern
 *
 *  When enabled, a SENDIDLE period of 11 bit times will be sent on the TX
 *  line. The bit is cleared by hardware afterwards.
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enableSendIdlePattern(UART_Regs *uart)
{
    uart->LCRH |= UART_LCRH_SENDIDLE_ENABLE;
}

/**
 *  @brief      Disable send idle pattern
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableSendIdlePattern(UART_Regs *uart)
{
    uart->LCRH &= ~(UART_LCRH_SENDIDLE_MASK);
}

/**
 *  @brief      Check if send idle pattern is enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of the send idle pattern
 *
 *  @retval     true  Send idle pattern is enabled
 *  @retval     false Send idle pattern is disabled
 */
__STATIC_INLINE bool DL_UART_isSendIdlePatternEnabled(UART_Regs *uart)
{
    return (
        (uart->LCRH & UART_LCRH_SENDIDLE_MASK) == UART_LCRH_SENDIDLE_ENABLE);
}

/**
 *  @brief      Set external driver setup value
 *
 *  Defines the number of UARTclk ticks the signal to control the external
 *  driver for the RS485 will be set before the START bit is sent
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *  @param[in]  val   The number of UARTclk ticks the signal before the RS485
 *                    is setup. Value between 0 - 31.
 */
__STATIC_INLINE void DL_UART_setExternalDriverSetup(
    UART_Regs *uart, uint32_t val)
{
    DL_Common_updateReg(&uart->LCRH, val << UART_LCRH_EXTDIR_SETUP_OFS,
        UART_LCRH_EXTDIR_SETUP_MASK);
}

/**
 *  @brief      Get the external driver setup value
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return    The number of UARTclk ticks the signal to control the
 *             external driver
 *
 *  @retval     0 - 31 The number of UARTclk ticks
 */
__STATIC_INLINE uint32_t DL_UART_getExternalDriverSetup(UART_Regs *uart)
{
    return ((uart->LCRH &
             UART_LCRH_EXTDIR_SETUP_MASK >> UART_LCRH_EXTDIR_SETUP_OFS));
}

/**
 *  @brief      Set external driver setup hold
 *
 *  Defines the number of UARTclk ticks the signal to control the external
 *  driver for the RS485 will be reset after the beginning of the stop bit.
 *  If 2 STOP bits are enabled, the RS485 will be reset at the beginning of
 *  the 2nd STOP bit.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *  @param[in]  val   The number of UARTclk ticks the signal to hold the
 *                    external driver before the RS485 will be reset.
 *                    Value between 0 - 31.
 */
__STATIC_INLINE void DL_UART_setExternalDriverHold(
    UART_Regs *uart, uint32_t val)
{
    DL_Common_updateReg(&uart->LCRH, val << UART_LCRH_EXTDIR_HOLD_OFS,
        UART_LCRH_EXTDIR_HOLD_MASK);
}

/**
 *  @brief      Get the external driver setup hold
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *
 *  @return     The number of UARTclk ticks the signal to hold the
 *              external driver before the RS485 will be reset
 *
 *  @retval     0 - 31 The number of UARTclk ticks
 */
__STATIC_INLINE uint32_t DL_UART_getExternalDriverHold(UART_Regs *uart)
{
    return ((
        uart->LCRH & UART_LCRH_EXTDIR_HOLD_MASK >> UART_LCRH_EXTDIR_HOLD_OFS));
}

/**
 *  @brief      Checks if the UART is busy
 *
 *  This bit is set as soon as the transmit FIFO or TXDATA register becomes
 *  non-empty (regardless of whether UART is enabled) or if a receive data is
 *  currently ongoing (after the start edge have been detected until a complete
 *  byte, including all stop bits, has been received by the shift register).
 *
 *  In IDLE Line mode the Busy signal also stays set during the idle time
 *  generation.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of the UART Busy bit
 *
 *  @retval     true   The UART is busy
 *  @retval     false  The UART is not busy
 *
 */
__STATIC_INLINE bool DL_UART_isBusy(UART_Regs *uart)
{
    return ((uart->STAT & UART_STAT_BUSY_MASK) == UART_STAT_BUSY_SET);
}

/**
 *  @brief      Checks if the RX FIFO is empty
 *
 *  The meaning of this bit depends on if the FIFOs were enabled.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the empty status of the RX FIFO
 *
 *  @retval     true   If the FIFO is enabled, the receive FIFO is empty.
 *                     If the FIFO is disabled, the receiver has no data.
 *  @retval     false  The receiver is not empty
 *
 *  @sa         DL_UART_enableFIFOs
 */
__STATIC_INLINE bool DL_UART_isRXFIFOEmpty(UART_Regs *uart)
{
    return ((uart->STAT & UART_STAT_RXFE_MASK) == UART_STAT_RXFE_SET);
}

/**
 *  @brief      Checks if the RX FIFO is full
 *
 *  The meaning of this bit depends on if the FIFOs were enabled.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the full status of the RX FIFO
 *
 *  @retval     true   If the FIFO is enabled, the receive FIFO is full.
 *                     If the FIFO is disabled, the receiver has 1-byte
 *                     of data.
 *  @retval     false  The receiver is not full
 *
 *  @sa         DL_UART_enableFIFOs
 */
__STATIC_INLINE bool DL_UART_isRXFIFOFull(UART_Regs *uart)
{
    return ((uart->STAT & UART_STAT_RXFF_MASK) == UART_STAT_RXFF_SET);
}

/**
 *  @brief      Checks if the TX FIFO is empty
 *
 *  The meaning of this bit depends on if the FIFOs were enabled.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the empty status of the TX FIFO
 *
 *  @retval     true   If the FIFO is enabled, the transmit FIFO is empty.
 *                     If the FIFO is disabled, the transmitter has no data.
 *  @retval     false  The transmitter is not empty
 *
 *  @sa         DL_UART_enableFIFOs
 */
__STATIC_INLINE bool DL_UART_isTXFIFOEmpty(UART_Regs *uart)
{
    return ((uart->STAT & UART_STAT_TXFE_MASK) == UART_STAT_TXFE_SET);
}

/**
 *  @brief      Checks if the TX FIFO is full
 *
 *  The meaning of this bit depends on if the FIFOs were enabled.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the full status of the TX FIFO
 *
 *  @retval     true   If the FIFO is enabled, the transmit FIFO is full.
 *                     If the FIFO is disabled, the transmitter has 1-byte
 *                     of data.
 *  @retval     false  The transmitter is not full
 *
 *  @sa         DL_UART_enableFIFOs
 */
__STATIC_INLINE bool DL_UART_isTXFIFOFull(UART_Regs *uart)
{
    return ((uart->STAT & UART_STAT_TXFF_MASK) == UART_STAT_TXFF_SET);
}

/**
 *  @brief      Checks if UART is clear to send
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the status of the CTS signal
 *
 *  @retval     true   The CTS signal is asserted (low)
 *  @retval     false  The CTS signal is not asserted (high)
 *
 *  @sa         DL_UART_isClearToSendEnabled
 */
__STATIC_INLINE bool DL_UART_isClearToSend(UART_Regs *uart)
{
    return ((uart->STAT & UART_STAT_CTS_MASK) == UART_STAT_CTS_SET);
}

/**
 *  @brief      Checks if Idle mode has been detected
 *
 *  Idle mode has been detected in Idleline-Multiprocessor-Mode. The IDLE bit
 *  is used as an address tag for each block of characters. In idle-line
 *  multiprocessor format, this bit is set when a received character is an
 *  address.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the status if Idle mode has been detected
 *
 *  @retval     true  Idle has been detected before last received character
 *  @retval     false Idle has not been detected before last received character
 *
 */
__STATIC_INLINE bool DL_UART_isIdleModeDetected(UART_Regs *uart)
{
    return ((uart->STAT & UART_STAT_IDLE_MASK) == UART_STAT_IDLE_SET);
}

/**
 *  @brief      Set the TX FIFO interrupt threshold level
 *
 *  Select the threshold for the transmit FIFO interrupt. The interrupts are
 *  generated based on a transition through a level rather than being based on
 *  the level. That is, the interrupts are generated when the fill level
 *  progresses through the trigger level. For example, if the transmit trigger
 *  level is set to the half-way mark, the interrupt is triggered when the
 *  transmit FIFO becomes half empty. In other words, if the transmit FIFO was
 *  filled with four characters, the interrupt would trigger once there are
 *  two or less characters after transmitting.
 *
 *  @param[in]  uart       Pointer to the register overlay for the peripheral
 *  @param[in]  threshold  One of @ref DL_UART_TX_FIFO_LEVEL
 *
 */
__STATIC_INLINE void DL_UART_setTXFIFOThreshold(
    UART_Regs *uart, DL_UART_TX_FIFO_LEVEL threshold)
{
    DL_Common_updateReg(
        &uart->IFLS, (uint32_t) threshold, UART_IFLS_TXIFLSEL_MASK);
}

/**
 *  @brief      Get the TX FIFO interrupt threshold level
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The TX FIFO interrupt threshold level
 *
 *  @retval     One of @ref DL_UART_TX_FIFO_LEVEL
 */
__STATIC_INLINE DL_UART_TX_FIFO_LEVEL DL_UART_getTXFIFOThreshold(
    UART_Regs *uart)
{
    uint32_t threshold = uart->IFLS & UART_IFLS_TXIFLSEL_MASK;

    return (DL_UART_TX_FIFO_LEVEL)(threshold);
}

/**
 *  @brief      Set the RX FIFO interrupt threshold level. The interrupts are
 *  generated based on a transition through a level rather than being based on
 *  the level. That is, the interrupts are generated when the fill level
 *  progresses through the trigger level. For example, if the receive trigger
 *  level is set to the half-way mark, the interrupt is triggered when the
 *  receive FIFO becomes half full. In other words, the interrupt is triggered
 *  after the receive FIFO is filled with two or more characters.
 *
 *  @param[in]  uart       Pointer to the register overlay for the peripheral
 *  @param[in]  threshold  One of @ref DL_UART_RX_FIFO_LEVEL
 */
__STATIC_INLINE void DL_UART_setRXFIFOThreshold(
    UART_Regs *uart, DL_UART_RX_FIFO_LEVEL threshold)
{
    DL_Common_updateReg(
        &uart->IFLS, (uint32_t) threshold, UART_IFLS_RXIFLSEL_MASK);
}

/**
 *  @brief      Get the RX FIFO interrupt threshold level
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The RX FIFO interrupt threshold level
 *
 *  @retval     One of @ref DL_UART_RX_FIFO_LEVEL
 */
__STATIC_INLINE DL_UART_RX_FIFO_LEVEL DL_UART_getRXFIFOThreshold(
    UART_Regs *uart)
{
    uint32_t threshold = uart->IFLS & UART_IFLS_RXIFLSEL_MASK;

    return (DL_UART_RX_FIFO_LEVEL)(threshold);
}

/**
 *  @brief      Set the RX interrupt timeout
 *
 *  When an additional character has not been received within the set
 *  timeout, a RX interrupt will still trigger even if the FIFO level has not
 *  been reached. A value of 0 disables this function.
 *
 *  @param[in]  uart     Pointer to the register overlay for the peripheral
 *  @param[in]  timeout  Timeout to set the RX interrupt to.
 *                       Value between 0 - 15
 */
__STATIC_INLINE void DL_UART_setRXInterruptTimeout(
    UART_Regs *uart, uint32_t timeout)
{
    DL_Common_updateReg(
        &uart->IFLS, timeout << UART_IFLS_RXTOSEL_OFS, UART_IFLS_RXTOSEL_MASK);
}

/**
 *  @brief      Get the RX interrupt timeout
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The RX interrupt timeout value
 *
 *  @retval     0 - 15  The RX interrupt timeout value
 *
 */
__STATIC_INLINE uint32_t DL_UART_getRXInterruptTimeout(UART_Regs *uart)
{
    return ((uart->IFLS & UART_IFLS_RXTOSEL_MASK) >> UART_IFLS_RXTOSEL_OFS);
}

/**
 *  @brief      Get Integer Baud-Rate Divisor
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The integer component of the baud rate divisor
 *
 *  @retval     0 - 65535 The integer baud date divisor
 */
__STATIC_INLINE uint32_t DL_UART_getIntegerBaudRateDivisor(UART_Regs *uart)
{
    return (uart->IBRD & UART_IBRD_DIVINT_MASK);
}

/**
 *  @brief      Get Fractional Baud-Rate Divisor
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The fractional component of the baud rate divisor
 *
 *  @retval     0 - 63  The fractional baud date divisor
 */
__STATIC_INLINE uint32_t DL_UART_getFractionalBaudRateDivisor(UART_Regs *uart)
{
    return (uart->FBRD & UART_FBRD_DIVFRAC_MASK);
}

/**
 *  @brief      Set the baud rate divisor
 *
 *  Set the integer baud rate divisor and fractional baud rate divisor
 *  components of the baud rate divisor
 *
 *  @param[in]  uart               Pointer to the register overlay for the
 *                                 peripheral
 *  @param[in]  integerDivisor     The integer component of the baud rate
 *                                 divisor
 *  @param[in]  fractionalDivisor  The fractional component of the baud rate
 *                                 divisor
 */
__STATIC_INLINE void DL_UART_setBaudRateDivisor(
    UART_Regs *uart, uint32_t integerDivisor, uint32_t fractionalDivisor)
{
    DL_Common_updateReg(&uart->IBRD, integerDivisor, UART_IBRD_DIVINT_MASK);
    DL_Common_updateReg(
        &uart->FBRD, fractionalDivisor, UART_FBRD_DIVFRAC_MASK);

    // When updating the baud-rate divisor (UARTIBRD or UARTIFRD),
    // the LCRH register must also be written to (any bit in LCRH can
    // be written to for updating the baud-rate divisor).
    DL_Common_updateReg(
        &uart->LCRH, (uart->LCRH & UART_LCRH_BRK_MASK), UART_LCRH_BRK_MASK);
}

/**
 *  @brief      Set the baud rate divisor for IrDA mode
 *
 *  Set the integer baud rate divisor and fractional baud rate divisor
 *  components of the baud rate divisor
 *  Divide integerDivisor by clkDivisor2 + 1 as a way of reducing the UART
 *  clock frequency, which in turn reduces the baud rate divisor further
 *  in accordance to IrDA standards
 *
 *  @param[in]  uart               Pointer to the register overlay for the
 *                                 peripheral
 *  @param[in]  integerDivisor     The integer component of the baud rate
 *                                 divisor
 *  @param[in]  fractionalDivisor  The fractional component of the baud rate
 *                                 divisor
 *  @param[in]  clkDivisor2        The additional factor to divide the clock,
 *                                 One of @ref DL_UART_CLOCK_DIVIDE2_RATIO
 *
 */
__STATIC_INLINE void DL_UART_setIrDABaudRateDivisor(UART_Regs *uart,
    uint32_t integerDivisor, uint32_t fractionalDivisor,
    DL_UART_CLOCK_DIVIDE2_RATIO clkDivisor2)
{
    DL_Common_updateReg(&uart->IBRD,
        (integerDivisor / ((uint32_t) clkDivisor2 + 1)),
        UART_IBRD_DIVINT_MASK);
    DL_Common_updateReg(
        &uart->FBRD, fractionalDivisor, UART_FBRD_DIVFRAC_MASK);

    // When updating the baud-rate divisor (UARTIBRD or UARTIFRD),
    // the LCRH register must also be written to (any bit in LCRH can
    // be written to for updating the baud-rate divisor).
    DL_Common_updateReg(
        &uart->LCRH, (uart->LCRH & UART_LCRH_BRK_MASK), UART_LCRH_BRK_MASK);
}

/**
 *  @brief      Set the pulse width select for the digital glitch suppresion
 *
 *  Controls the pulse width select for glitch suppression on the RX line.
 *  The glitch suppression values are in terms of functional clocks.
 *
 *  In IrDA mode, this sets the receive filter length. The minimum pulse
 *  length for receive is given by: t(MIN) = (DGFSEL) / f(IRTXCLK)
 *
 *  @param[in]  uart        Pointer to the register overlay for the peripheral
 *  @param[in]  pulseWidth  Pulse width select for the glitch suppresion.
 *                          Value between 0 - 63.
 */
__STATIC_INLINE void DL_UART_setDigitalPulseWidth(
    UART_Regs *uart, uint32_t pulseWidth)
{
    DL_Common_updateReg(&uart->GFCTL, pulseWidth, UART_GFCTL_DGFSEL_MASK);
}

/**
 *  @brief      Get the pulse width select for the digital glitch suppresion
 *
 *  Gets the pulse width select for glitch suppression on the RX line.
 *  The glitch suppression values are in terms of functional clocks.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The digital glitch suppression pulse width
 *
 *  @retval     0 indicating digital glitch suppression is disabled
 *  @retval     1 - 63 the digital glitch suppression pulse width
 */
__STATIC_INLINE uint32_t DL_UART_getDigitalPulseWidth(UART_Regs *uart)
{
    return (uart->GFCTL & UART_GFCTL_DGFSEL_MASK);
}

/**
 *  @brief      Writes data into the TX FIFO to transmit
 *
 *  Puts the data into the TX FIFO without checking it's status. Use if already
 *  sure the TX FIFO has space for the write. See related APIs for additional
 *  transmit options.
 *
 *  For transmitted data, if the FIFO is enabled, data written to this
 *  location is pushed onto the transmit FIFO. If the FIFO is disabled,
 *  data is stored in the 1-byte deep transmitter.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *  @param[in]  data  The data to transmit
 *
 *
 *  @sa         DL_UART_transmitDataBlocking
 *  @sa         DL_UART_transmitDataCheck
 */
__STATIC_INLINE void DL_UART_transmitData(UART_Regs *uart, uint8_t data)
{
    uart->TXDATA = data;
}

/**
 *  @brief      Reads data from the RX FIFO
 *
 *  Reads the data from the RX FIFO without checking its status. Use if
 *  already sure the RX FIFO has data available. See related APIs for
 *  additional receive options.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The data in the RX FIFO
 *
 *  @sa         DL_UART_receiveDataBlocking
 *  @sa         DL_UART_receiveDataCheck
 */
__STATIC_INLINE uint8_t DL_UART_receiveData(UART_Regs *uart)
{
    return ((uint8_t)(uart->RXDATA & UART_RXDATA_DATA_MASK));
}

/**
 *  @brief      Gets the status of the error flags of the received data
 *
 *  @param[in]  uart       Pointer to the register overlay for the peripheral
 *  @param[in]  errorMask  Bit mask of error flags to check. Bitwise OR of
 *                         @ref DL_UART_ERROR.
 *
 *  @return     The status of the requested UART error flags
 *
 *  @retval     Bitwise OR of @ref DL_UART_ERROR values
 */
__STATIC_INLINE uint32_t DL_UART_getErrorStatus(
    UART_Regs *uart, uint32_t errorMask)
{
    return (uart->RXDATA & errorMask);
}

/**
 *  @brief      Set the LIN counter value
 *
 *  The LIN counter is a 16 bit up counter clocked by the functional clock of
 *  the UART
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *  @param[in]  value  Pulse width select for the glitch suppresion.
 */
__STATIC_INLINE void DL_UART_setLINCounterValue(
    UART_Regs *uart, uint16_t value)
{
    DL_Common_updateReg(&uart->LINCNT, value, UART_LINCNT_VALUE_MASK);
}

/**
 *  @brief      Get the LIN counter value
 *
 *  The LIN counter is a 16 bit up counter clocked by the module clock of
 *  the UART
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The clock counter value
 *
 *  @retval     0 - 65535  The clock counter value
 *
 */
__STATIC_INLINE uint16_t DL_UART_getLINCounterValue(UART_Regs *uart)
{
    return ((uint16_t)(uart->LINCNT & UART_LINCNT_VALUE_MASK));
}

/**
 *  @brief      Enable the LIN counter
 *
 *  The LIN counter will only count when enabled.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enableLINCounter(UART_Regs *uart)
{
    uart->LINCTL |= UART_LINCTL_CTRENA_ENABLE;
}

/**
 *  @brief      Check if the LIN counter is enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of the LIN counter
 *
 *  @retval     true   LIN counter is enabled
 *  @retval     false  LIN counter is disabled
 */
__STATIC_INLINE bool DL_UART_isLINCounterEnabled(UART_Regs *uart)
{
    return (
        (uart->LINCTL & UART_LINCTL_CTRENA_MASK) == UART_LINCTL_CTRENA_ENABLE);
}

/**
 *  @brief      Disable the LIN counter
 *
 *  LIN counter will only count when enabled.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableLINCounter(UART_Regs *uart)
{
    uart->LINCTL &= ~(UART_LINCTL_CTRENA_MASK);
}

/**
 *  @brief   Enable LIN counter clear and start counting on falling edge of RXD
 *
 *  When enabled, the counter is set to 0 and starts counting on the LIN counter
 *  on a falling edge of RXD.
 *
 *  The LIN counter will only count when it is enabled.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @sa  DL_UART_enableLINCounter
 */
__STATIC_INLINE void DL_UART_enableLINCounterClearOnFallingEdge(
    UART_Regs *uart)
{
    uart->LINCTL |= UART_LINCTL_ZERONE_ENABLE;
}

/**
 *  @brief      Check if LIN counting on falling edge of RXD is enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of counting on falling edge of RXD
 *
 *  @retval     true   Counting on falling edge is enabled
 *  @retval     false  Counting on falling edge is disabled
 */
__STATIC_INLINE bool DL_UART_isLINCounterClearOnFallingEdge(UART_Regs *uart)
{
    return (
        (uart->LINCTL & UART_LINCTL_ZERONE_MASK) == UART_LINCTL_ZERONE_ENABLE);
}

/**
 *  @brief      Disable LIN counting on falling edge of RXD
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableLINCounterClearOnFallingEdge(
    UART_Regs *uart)
{
    uart->LINCTL &= ~(UART_LINCTL_ZERONE_MASK);
}

/**
 *  @brief      Enable LIN counter incrementing while RXD signal is low
 *
 *  When LIN counter is enabled and the signal on RXD is low, the counter
 *  increments
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @sa  DL_UART_enableLINCounter
 */
__STATIC_INLINE void DL_UART_enableLINCountWhileLow(UART_Regs *uart)
{
    uart->LINCTL |= UART_LINCTL_CNTRXLOW_ENABLE;
}

/**
 *  @brief   Check if LIN counter increments while RXD signal is low is enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of counter increments while RXD signal is low
 *
 *  @retval     true   Counter increments while RXD signal is low is enabled
 *  @retval     false  Counter increments while RXD signal is low is disabled
 */
__STATIC_INLINE bool DL_UART_isLINCountWhileLowEnabled(UART_Regs *uart)
{
    return ((uart->LINCTL & UART_LINCTL_CNTRXLOW_MASK) ==
            UART_LINCTL_CNTRXLOW_ENABLE);
}

/**
 *  @brief      Disable LIN counter increments while RXD signal is low
 *
 *  LIN counter will not increment while the RXD signal is low
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableLINCountWhileLow(UART_Regs *uart)
{
    uart->LINCTL &= ~(UART_LINCTL_CNTRXLOW_MASK);
}

/**
 *  @brief      Enable capture of the LIN counter on a falling edge
 *
 *  When enabled, the LIN counter value is captured to the LINC0 register on
 *  each falling RXD edge. A LINC0 interrupt is triggered when enabled.
 *  Disables counter compare match mode if enabled.
 *
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @sa  DL_UART_configLINMode
 */
__STATIC_INLINE void DL_UART_enableLINFallingEdgeCapture(UART_Regs *uart)
{
    DL_Common_updateReg(&uart->LINCTL,
        UART_LINCTL_LINC0CAP_ENABLE | UART_LINCTL_LINC0_MATCH_DISABLE,
        UART_LINCTL_LINC0CAP_MASK | UART_LINCTL_LINC0_MATCH_MASK);
}

/**
 *  @brief      Check status of capture of LIN counter on a falling edge
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of capture the LIN counter on a falling edge
 *
 *  @retval     true   Capture to LINC0 on falling RXD edge is enabled
 *  @retval     false  Capture to LINC0 on falling RXD edge is disabled
 */
__STATIC_INLINE bool DL_UART_isLINFallingEdgeCaptureEnabled(UART_Regs *uart)
{
    return ((uart->LINCTL & UART_LINCTL_LINC0CAP_MASK) ==
            UART_LINCTL_LINC0CAP_ENABLE);
}

/**
 *  @brief      Disable capture of LIN counter on a falling edge
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableLINFallingEdgeCapture(UART_Regs *uart)
{
    uart->LINCTL &= ~(UART_LINCTL_LINC0CAP_MASK);
}

/**
 *  @brief      Enable capture of the LIN counter on a rising edge
 *
 *  When enabled the LIN counter value is captured to LINC1 register on each
 *  rising RXD edge. A LINC1 interrupt is triggered when enabled.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_UART_enableLINRisingEdgeCapture(UART_Regs *uart)
{
    uart->LINCTL |= UART_LINCTL_LINC1CAP_ENABLE;
}

/**
 *  @brief      Check status of capture of LIN counter on a rising edge
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of capture of LIN counter on a rising edge
 *
 *  @retval     true   Capture to LINC1 on rising RXD edge is enabled
 *  @retval     false  Capture to LINC1 on rising RXD edge is disabled
 */
__STATIC_INLINE bool DL_UART_isLINRisingEdgeCaptureEnabled(UART_Regs *uart)
{
    return ((uart->LINCTL & UART_LINCTL_LINC1CAP_MASK) ==
            UART_LINCTL_LINC1CAP_ENABLE);
}

/**
 *  @brief      Disable capture of LIN counter on a rising edge
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableLINRisingEdgeCapture(UART_Regs *uart)
{
    uart->LINCTL &= ~(UART_LINCTL_LINC1CAP_MASK);
}

/**
 *  @brief      Enable LIN counter compare match mode
 *
 *  When enabled, a match between a value in LINC0 and the LIN counter can
 *  trigger a LINC0 interrupt. Disables capture on falling edge if enabled.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enableLINCounterCompareMatch(UART_Regs *uart)
{
    DL_Common_updateReg(&uart->LINCTL,
        UART_LINCTL_LINC0_MATCH_ENABLE | UART_LINCTL_LINC0CAP_DISABLE,
        UART_LINCTL_LINC0CAP_MASK | UART_LINCTL_LINC0_MATCH_MASK);
}

/**
 *  @brief      Setup LIN counter control for sync field validation
 *
 *  Enable LIN counter capture on rising RX edge. Enable LIN counter capture on falling RX edge.
 *  Enable LIN counter clearing on RX falling edge. Enable LIN counter.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enableLINSyncFieldValidationCounterControl(
    UART_Regs *uart)
{
    DL_Common_updateReg(&uart->LINCTL,
        UART_LINCTL_LINC0CAP_ENABLE | UART_LINCTL_LINC1CAP_ENABLE |
            UART_LINCTL_ZERONE_ENABLE | UART_LINCTL_CTRENA_ENABLE,
        UART_LINCTL_LINC0CAP_MASK | UART_LINCTL_LINC1CAP_MASK |
            UART_LINCTL_ZERONE_MASK | UART_LINCTL_CTRENA_MASK);
}

/**
 *  @brief      Setup LIN counter control for LIN reception
 *
 * Enable count while low signal on RXD. Enable LIN counter clearing on RXD falling edge.
 * Enable LIN counter.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enableLINReceptionCountControl(UART_Regs *uart)
{
    DL_Common_updateReg(&uart->LINCTL,
        UART_LINCTL_CNTRXLOW_ENABLE | UART_LINCTL_ZERONE_ENABLE |
            UART_LINCTL_CTRENA_ENABLE,
        UART_LINCTL_CNTRXLOW_MASK | UART_LINCTL_ZERONE_MASK |
            UART_LINCTL_CTRENA_MASK);
}

/**
 *  @brief      Check if LIN counter compare match mode is enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of counter compare match mode
 *
 *  @retval     true   LIN counter compare match mode is enabled
 *  @retval     false  LIN counter compare match mode is disabled
 */
__STATIC_INLINE bool DL_UART_isLINCounterCompareMatchEnabled(UART_Regs *uart)
{
    return ((uart->LINCTL & UART_LINCTL_LINC0_MATCH_MASK) ==
            UART_LINCTL_LINC0_MATCH_ENABLE);
}

/**
 *  @brief      Disable LIN counter compare match mode
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableLINCounterCompareMatch(UART_Regs *uart)
{
    uart->LINCTL &= ~(UART_LINCTL_LINC0_MATCH_MASK);
}

/**
 *  @brief      Set the value to be compared to the LIN counter
 *
 *  Sets the value of LINC0 to be used to compare to the LIN counter. For use
 *  when LIN counter compare match mode is enabled.
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *  @param[in]  value  Value to be compared to the LIN counter for matching.
 *                     Value between 0 - 65535.
 *
 *  @sa  DL_UART_enableLINCounterCompareMatch
 */
__STATIC_INLINE void DL_UART_setLINCounterCompareValue(
    UART_Regs *uart, uint16_t value)
{
    DL_Common_updateReg(&uart->LINC0, value, UART_LINC0_DATA_MASK);
}

/**
 *  @brief      Get the LINC0 counter value
 *
 *  Captures current LINCTR value on RXD falling edge.
 *
 *  If capture is enabled with @ref DL_UART_enableLINFallingEdgeCapture, a
 *  capture can generate a LINC0 interrupt.
 *  If compare mode is enabled with @ref DL_UART_enableLINCounterCompareMatch,
 *  a counter match can generate a LINC0 interrupt.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The LINC0 counter value
 *
 *  @retval     0 - 65535  The LINC0 counter value
 *
 *  @sa  DL_UART_enableLINFallingEdgeCapture
 *  @sa  DL_UART_enableLINCounterCompareMatch
 */
__STATIC_INLINE uint16_t DL_UART_getLINFallingEdgeCaptureValue(UART_Regs *uart)
{
    return ((uint16_t)(uart->LINC0 & UART_LINC0_DATA_MASK));
}

/**
 *  @brief      Get the LINC1 counter value
 *
 *  Captures current LINCTR value on RXD rising edge. For use when LIN rising
 *  edge capture is enabled. It can generate a LINC1 interrupt on capture.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The LINC1 counter value
 *
 *  @retval     0 - 65535  The LINC1 counter value
 *
 *  @sa  DL_UART_enableLINRisingEdgeCapture
 */
__STATIC_INLINE uint16_t DL_UART_getLINRisingEdgeCaptureValue(UART_Regs *uart)
{
    return ((uint16_t)(uart->LINC1 & UART_LINC1_DATA_MASK));
}

/**
 *  @brief      Enable the IrDA encoder/decoder
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enableIrDAMode(UART_Regs *uart)
{
    uart->IRCTL |= UART_IRCTL_IREN_ENABLE;
}

/**
 *  @brief      Check if the IrDA encoder/decoder is enabled
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of IrDA mode
 *
 *  @retval     true   IrDA mode is enabled
 *  @retval     false  IrDA mode is disabled
 */
__STATIC_INLINE bool DL_UART_isIrDAModeEnabled(UART_Regs *uart)
{
    return ((uart->IRCTL & UART_IRCTL_IREN_MASK) == UART_IRCTL_IREN_ENABLE);
}

/**
 *  @brief      Disable the IrDA encoder/decoder
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableIrDAMode(UART_Regs *uart)
{
    uart->IRCTL &= ~(UART_IRCTL_IREN_MASK);
}

/**
 *  @brief      Set the IrDA transmit pulse clock select
 *
 *  @param[in]  uart   Pointer to the register overlay for the peripheral
 *  @param[in]  uartClock  The clock select for the IrDA pulse data to be based on.
 *                     One of @ref DL_UART_IRDA_CLOCK
 */
__STATIC_INLINE void DL_UART_setIrDATXPulseClockSelect(
    UART_Regs *uart, DL_UART_IRDA_CLOCK uartClock)
{
    DL_Common_updateReg(
        &uart->IRCTL, (uint32_t) uartClock, UART_IRCTL_IRTXCLK_MASK);
}

/**
 *  @brief      Get the IrDA transmit pulse clock select
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The clock select that the IrDA pulse data is based on
 *
 *  @retval     One of @ref DL_UART_IRDA_CLOCK
 *
 */
__STATIC_INLINE DL_UART_IRDA_CLOCK DL_UART_getIrDATXPulseClockSelect(
    UART_Regs *uart)
{
    uint32_t uartClock = uart->IRCTL & UART_IRCTL_IRTXCLK_MASK;

    return (DL_UART_IRDA_CLOCK)(uartClock);
}

/**
 *  @brief      Set the IrDA configurations
 *
 *  Calculates the baud rate divisor given the clock output of the UART clock
 *  source and the target baud rate. This API also enables IrDA mode.
 *
 *  @param[in]  uart         Pointer to the register overlay for the peripheral
 *  @param[in]  polarity     The receive input polarity.
 *                           One of @ref DL_UART_IRDA_POLARITY.
 *  @param[in]  pulseLength  The length of the IrDA transmit pulse.
 *  @param[in]  irdaClk      The clock used for the transmit pulse.
 *                           One of @ref DL_UART_IRDA_CLOCK.
 */
void DL_UART_configIrDAMode(UART_Regs *uart, DL_UART_IRDA_POLARITY polarity,
    uint32_t pulseLength, DL_UART_IRDA_CLOCK irdaClk);

/**
 *  @brief      Set the IrDA transmit pulse length
 *
 *  The pulse length can be calculated with the following equation:
 *      IRTXPLx = pulseLength * 2 * irdaClk - 1
 *      (IRTXCLK = functional clock of the UART)
 *
 *  To set the pulse time of 3/16 bit period required by the IrDA period,
 *  16-bit oversampling is selected with HSE = 0, the baud rate clock is
 *  selected with IRTXCLK = 1, and the pulse length is set to six one-half
 *  clock cycles with IRTXPLx = 6 - 1 - 5.
 *
 *  @param[in]  uart         Pointer to the register overlay for the peripheral
 *  @param[in]  pulseLength  The length of the IrDA transmit pulse.
 *  @param[in]  irdaClk      The clock used for the transmit pulse.
 *                           One of @ref DL_UART_IRDA_CLOCK.
 */
void DL_UART_setIrDAPulseLength(
    UART_Regs *uart, uint32_t pulseLength, DL_UART_IRDA_CLOCK irdaClk);

/**
 *  @brief      Get the IrDA transmit pulse length
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The IrDA transmit pulse length is set to
 *
 *  @retval     0 - 63  The IrDA transmit pulse length
 */
__STATIC_INLINE uint32_t DL_UART_getIrDATXPulseLength(UART_Regs *uart)
{
    return (uart->IRCTL & UART_IRCTL_IRTXPL_MASK);
}

/**
 *  @brief      Set the IrDA receive input UCAxRXD polarity
 *
 *  @param[in]  uart      Pointer to the register overlay for the peripheral
 *  @param[in]  polarity  The value to set the IrDA RX pulse polarity to.
 *                        One of @ref DL_UART_IRDA_POLARITY
 */
__STATIC_INLINE void DL_UART_setIrDARXPulsePolarity(
    UART_Regs *uart, DL_UART_IRDA_POLARITY polarity)
{
    DL_Common_updateReg(
        &uart->IRCTL, (uint32_t) polarity, UART_IRCTL_IRRXPL_MASK);
}

/**
 *  @brief      Get the IrDA receive input UCAxRXD polarity
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The IrDA RX pulse polarity
 *
 *  @retval     One of @ref DL_UART_IRDA_POLARITY
 */
__STATIC_INLINE DL_UART_IRDA_POLARITY DL_UART_getIrDARXPulsePolarity(
    UART_Regs *uart)
{
    uint32_t polarity = uart->IRCTL & UART_IRCTL_IRRXPL_MASK;

    return (DL_UART_IRDA_POLARITY)(polarity);
}

/**
 *  @brief      Set the address mask for DALI, 9-bit, or Idle-Line mode
 *
 *  The address bits are masked to create a set of addresses to be matched
 *  with the received address byte.
 *
 *  A 0 bit in the MSK bitfield configures that the corresponding bit in the
 *  ADDR bitfield of the ADDR register is don't care.
 *  A 1 bit in the MSK bitfield configures, that the corresponding bit in the
 *  ADDR bitfield of the ADDR register must match.
 *
 *  Used in DALI, UART 9-Bit or Idle-Line mode.
 *
 *  @param[in]  uart         Pointer to the register overlay for the peripheral
 *  @param[in]  addressMask  The address mask to set
 */
__STATIC_INLINE void DL_UART_setAddressMask(
    UART_Regs *uart, uint32_t addressMask)
{
    DL_Common_updateReg(&uart->AMASK, addressMask, UART_AMASK_VALUE_MASK);
}

/**
 *  @brief      Get the address mask being used
 *
 *  The address bits are masked to create a set of addresses to be matched
 *  with the received address byte.
 *
 *  A 0 bit in the MSK bitfield configures that the corresponding bit in the
 *  ADDR bitfield of the ADDR register is don't care.
 *  A 1 bit in the MSK bitfield configures, that the corresponding bit in the
 *  ADDR bitfield of the ADDR register must match.
 *
 *  Used in DALI, UART 9-Bit or Idle-Line mode.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The address mask being used
 *
 *  @retval     0-255  The address mask
 *
 */
__STATIC_INLINE uint32_t DL_UART_getAddressMask(UART_Regs *uart)
{
    return (uart->AMASK & UART_AMASK_VALUE_MASK);
}

/**
 *  @brief      Set the address
 *
 *  Used to write the specific address that should be matched with the
 *  receiving byte when the Address Mask (AMASK) is set to FFh. This register
 *  is used in conjunction with AMASK to form a match for address-byte
 *  received.
 *
 *  Used in DALI, UART 9-Bit or Idle-Line mode.
 *
 *  @param[in]  uart     Pointer to the register overlay for the peripheral
 *  @param[in]  address  The address to set
 */
__STATIC_INLINE void DL_UART_setAddress(UART_Regs *uart, uint32_t address)
{
    DL_Common_updateReg(&uart->ADDR, address, UART_ADDR_VALUE_MASK);
}

/**
 *  @brief      Get the address being used
 *
 *  Used to write the specific address that should be matched with the
 *  receiving byte when the Address Mask (AMASK) is set to FFh. This register
 *  is used in conjunction with AMASK to form a match for address-byte
 *  received.
 *
 *  Used in DALI, UART 9-Bit or Idle-Line mode.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The address being used
 *
 *  @retval     0-255  The address being used
 *
 */
__STATIC_INLINE uint32_t DL_UART_getAddress(UART_Regs *uart)
{
    return (uart->ADDR & UART_ADDR_VALUE_MASK);
}

/**
 *  @brief      Enable UART interrupts
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_UART_INTERRUPT.
 */
__STATIC_INLINE void DL_UART_enableInterrupt(
    UART_Regs *uart, uint32_t interruptMask)
{
    uart->CPU_INT.IMASK |= interruptMask;
}

/**
 *  @brief      Disable UART interrupts
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to disable. Bitwise OR of
 *                             @ref DL_UART_INTERRUPT.
 */
__STATIC_INLINE void DL_UART_disableInterrupt(
    UART_Regs *uart, uint32_t interruptMask)
{
    uart->CPU_INT.IMASK &= ~(interruptMask);
}

/**
 *  @brief      Check which UART interrupts are enabled
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_UART_INTERRUPT.
 *
 *  @return     Which of the requested UART interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_UART_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_UART_getEnabledInterrupts(
    UART_Regs *uart, uint32_t interruptMask)
{
    return (uart->CPU_INT.IMASK & interruptMask);
}

/**
 *  @brief      Check interrupt flag of enabled UART interrupts
 *
 *  Checks if any of the UART interrupts that were previously enabled are
 *  pending.
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_UART_INTERRUPT.
 *
 *  @return     Which of the requested UART interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_UART_INTERRUPT values
 *
 *  @sa         DL_UART_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_UART_getEnabledInterruptStatus(
    UART_Regs *uart, uint32_t interruptMask)
{
    return (uart->CPU_INT.MIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of any UART interrupt
 *
 *  Checks if any of the UART interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_UART_INTERRUPT.
 *
 *  @return     Which of the requested UART interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_UART_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_UART_getRawInterruptStatus(
    UART_Regs *uart, uint32_t interruptMask)
{
    return (uart->CPU_INT.RIS & interruptMask);
}

/**
 *  @brief      Get highest priority pending UART interrupt
 *
 *  Checks if any of the UART interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The highest priority pending UART interrupt
 *
 *  @retval     TBD
 */
__STATIC_INLINE DL_UART_IIDX DL_UART_getPendingInterrupt(UART_Regs *uart)
{
    return (DL_UART_IIDX)(uart->CPU_INT.IIDX);
}

/**
 *  @brief      Clear pending UART interrupts
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_UART_INTERRUPT.
 */
__STATIC_INLINE void DL_UART_clearInterruptStatus(
    UART_Regs *uart, uint32_t interruptMask)
{
    uart->CPU_INT.ICLR = interruptMask;
}

/**
 *  @brief      Prepares the UART to change the configuration
 *
 *  If the UART has already been enabled, then it is recommended to call this
 *  function before calling other APIs that make changes to the CTL0 register.
 *  If changes are made to the CTL0 register without disabling the UART, then
 *  results are unpredictable. This API performs the following:
 *  1. Disable the UART.
 *  2. Wait for the end of transmission or reception of the current character.
 *  3. Flush the transmit FIFO by clearing bit FEN in the UART control
 *  register CTL0.
 *
 *  @post After calling this API, the user must be re-enabled by calling
 *        @ref DL_UART_enable.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_changeConfig(UART_Regs *uart)
{
    DL_UART_disable(uart);
    while (DL_UART_isBusy(uart)) {
        ;
    }
    DL_UART_disableFIFOs(uart);
}

/**
 *  @brief      Enable the analog glitch filter on the RX input
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enableAnalogGlitchFilter(UART_Regs *uart)
{
    uart->GFCTL |= UART_GFCTL_AGFEN_ENABLE;
}

/**
 *  @brief      Disable the analog glitch filter on the RX input
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableAnalogGlitchFilter(UART_Regs *uart)
{
    uart->GFCTL &= ~(UART_GFCTL_AGFEN_MASK);
}

/**
 * @brief      Returns if analog glitch filter is enabled
 *
 * @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 * @return true   if analog glitch filter is enabled
 * @return false  if analog glitch filter is disabled
 */
__STATIC_INLINE bool DL_UART_isAnalogGlitchFilterEnabled(UART_Regs *uart)
{
    return ((uart->GFCTL & UART_GFCTL_AGFEN_MASK) == UART_GFCTL_AGFEN_ENABLE);
}

/**
 *  @brief      Enable analog and digital noise glitch filter chaining
 *
 * When enabled, analog and digital glitch filters are chained and the output
 * of the combination is made available to the IP logic for sampling.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_enableGlitchFilterChaining(UART_Regs *uart)
{
    uart->GFCTL |= UART_GFCTL_CHAIN_ENABLED;
}

/**
 *  @brief      Disable analog and digital noise glitch filter chaining
 *
 * When disabled, only digital filter output is available to the IP logic
 * for sampling.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_UART_disableGlitchFilterChaining(UART_Regs *uart)
{
    uart->GFCTL &= ~(UART_GFCTL_CHAIN_MASK);
}

/**
 * @brief      Returns if glitch filter chaining enabled
 *
 * @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 * @return true   if glitch filter chaining is enabled
 * @return false  if glitch filter chaining is disabled
 */
__STATIC_INLINE bool DL_UART_isGlitchFilterChainingEnabled(UART_Regs *uart)
{
    return ((uart->GFCTL & UART_GFCTL_CHAIN_MASK) == UART_GFCTL_CHAIN_ENABLED);
}

/**
 *  @brief      Set the pulse width select for the analog glitch suppresion
 *
 *  Sets the pulse width select for the analog glitch
 *  suppression on the RX line. See device datasheet for exact values.
 *
 *  This only applies to Power Domain 0 (PD0).
 *
 *  @param[in]  uart        Pointer to the register overlay for the peripheral
 *  @param[in]  pulseWidth  Pulse width select for the glitch suppresion.
                            One of @ref DL_UART_PULSE_WIDTH
 */
__STATIC_INLINE void DL_UART_setAnalogPulseWidth(
    UART_Regs *uart, DL_UART_PULSE_WIDTH pulseWidth)
{
    DL_Common_updateReg(
        &uart->GFCTL, (uint32_t) pulseWidth, UART_GFCTL_AGFSEL_MASK);
}

/**
 *  @brief      Get the pulse width select for the glitch suppresion
 *
 *  Gets the pulse width select for the analog glitch
 *  suppression on the RX line. See device datasheet for exact values.
 *
 *  This only applies to Power Domain 0 (PD0).
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @return     The pulse width select for the glitch suppression
 *
 *  @retval     One of @ref DL_UART_PULSE_WIDTH

 */
__STATIC_INLINE DL_UART_PULSE_WIDTH DL_UART_getAnalogPulseWidth(
    UART_Regs *uart)
{
    uint32_t pulseWidth = uart->GFCTL & UART_GFCTL_AGFSEL_MASK;

    return (DL_UART_PULSE_WIDTH)(pulseWidth);
}

/**
 *  @brief      Blocks to ensure transmit is ready before sending data
 *
 *  Puts the data into the TX FIFO after blocking to ensure the TX FIFO is not
 *  full. Will wait indefintely until there is space in the TX FIFO. See
 *  related APIs for additional transmit options.
 *
 *  Can be used for any data transfers that are less than or equal to 8 bits.
 *
 *  @param[in]  uart  pointer to the register overlay for the peripheral
 *  @param[in]  data  data to send
 *
 *  @sa         DL_UART_transmitData
 *  @sa         DL_UART_transmitDataCheck
 */
void DL_UART_transmitDataBlocking(UART_Regs *uart, uint8_t data);

/**
 *  @brief      Blocks to ensure receive is ready before reading data
 *
 *  Reads the data from the RX FIFO after blocking to ensure the RX FIFO is not
 *  empty. Will wait indefintely until there is data in the RX FIFO. See
 *  related APIs for additional receive options.
 *
 *  Can be used for any data transfers that are less than or equal to 8 bits.
 *
 *  @param[in]  uart  pointer to the register overlay for the peripheral
 *
 *  @return     The data in the RX FIFO
 *
 *  @sa         DL_UART_transmitData
 *  @sa         DL_UART_transmitDataCheck
 */
uint8_t DL_UART_receiveDataBlocking(UART_Regs *uart);

/**
 *  @brief      Checks the TX FIFO before trying to transmit data
 *
 *  Checks if the TX FIFO is already full before trying to add new data to the
 *  FIFO. Exits immediately if full rather than trying to block. See related
 *  APIs for additional transmit options.
 *
 *  Can be used for any data transfers that are less than or equal to 8 bits.
 *
 *  @param[in]  uart  pointer to the register overlay for the peripheral
 *  @param[in]  data  data to send
 *
 *  @return     If the transmit occurred
 *
 *  @retval     true  if data was added to the TX FIFO
 *  @retval     false if the TX FIFO was full and data was not added
 *
 *  @sa         DL_UART_transmitData
 *  @sa         DL_UART_transmitDataBlocking
 */
bool DL_UART_transmitDataCheck(UART_Regs *uart, uint8_t data);

/**
 *  @brief      Checks the RX FIFO before trying to transmit data
 *
 *  Checks if the RX FIFO is already empty before trying to read new data from
 *  the FIFO. Exits immediately if empty rather than trying to block. See
 *  related APIs for additional receive options.
 *
 *  Can be used for any data transfers that are less than or equal to 8 bits.
 *
 *  @param[in]  uart   pointer to the register overlay for the peripheral
 *  @param[in]  buffer a buffer to write the received data into
 *
 *  @return     If the receive occurred
 *
 *  @retval     true  if data was read from the RX FIFO
 *  @retval     false if the RX FIFO was empty and data was not read
 *
 *  @sa         DL_UART_receiveData
 *  @sa         DL_UART_receiveDataBlocking
 */
bool DL_UART_receiveDataCheck(UART_Regs *uart, uint8_t *buffer);

/**
 *  @brief       Read all available data out of the RX FIFO using 8 bit access
 *
 *  @param[in]   uart      Pointer to the register overlay for the peripheral
 *  @param[out]  buffer    Buffer to write received data into
 *  @param[in]   maxCount  Max number of bytes to read from the RX FIFO
 *
 *  @return      Number of bytes read from the RX FIFO
 */
uint32_t DL_UART_drainRXFIFO(
    UART_Regs *uart, uint8_t *buffer, uint32_t maxCount);

/**
 *  @brief      Fill the TX FIFO until full using 8 bit access
 *
 *  Continuously write data into the TX FIFO until it is filled up or count has
 *  been reached.
 *
 *  @param[in]  uart    Pointer to the register overlay for the peripheral
 *  @param[in]  buffer  Buffer of data to write to the TX FIFO
 *  @param[in]  count   Max number of bytes to write to the TX FIFO
 *
 *  @return     Number of bytes written to the TX FIFO
 */
uint32_t DL_UART_fillTXFIFO(UART_Regs *uart, uint8_t *buffer, uint32_t count);

/**
 *  @brief      Enable UART interrupt for triggering the DMA receive event
 *
 * Enables the UART interrupt to be used as the condition to generate an
 * event to directly trigger the DMA. This API configures the DMA_TRIG_RX
 * register, which is the event publisher used for triggering the DMA to do
 * a receive data transfer.
 *
 * @note Only one interrupt source should be enabled at a time.
 *
 *  @param[in]  uart       Pointer to the register overlay for the
 *                         peripheral
 *  @param[in]  interrupt  Interrupt to enable as the trigger condition for
 *                         the DMA. One of @ref DL_UART_DMA_INTERRUPT_RX.
 */
__STATIC_INLINE void DL_UART_enableDMAReceiveEvent(
    UART_Regs *uart, uint32_t interrupt)
{
    uart->DMA_TRIG_RX.IMASK = interrupt;
}

/**
 *  @brief      Enable UART interrupt for triggering the DMA transmit event
 *
 * Enables the UART interrupt to be used as the condition to generate an
 * event to directly trigger the DMA. This API configures the DMA_TRIG_TX
 * register, which is the event publisher used for triggering the DMA to do
 * a transmit data transfer.
 *
 * @note DMA_TRIG_TX only has one transmit interrupt source
 *
 *  @param[in]  uart       Pointer to the register overlay for the
 *                         peripheral
 */
__STATIC_INLINE void DL_UART_enableDMATransmitEvent(UART_Regs *uart)
{
    uart->DMA_TRIG_TX.IMASK = UART_DMA_TRIG_TX_IMASK_TXINT_SET;
}

/**
 *  @brief      Disables UART interrupt from triggering the DMA receive event
 *
 * Disables the UART interrupt as the condition to generate an event to
 * directly trigger the DMA. This API configures the DMA_TRIG_RX
 * register, which is the event publisher used for triggering the DMA to do
 * a receive data transfer.
 *
 *  @param[in]  uart       Pointer to the register overlay for the
 *                         peripheral
 *  @param[in]  interrupt  Interrupt to disable as the trigger condition for
 *                         the DMA. One of @ref DL_UART_DMA_INTERRUPT_RX.
 */
__STATIC_INLINE void DL_UART_disableDMAReceiveEvent(
    UART_Regs *uart, uint32_t interrupt)
{
    uart->DMA_TRIG_RX.IMASK &= ~(interrupt);
}

/**
 *  @brief      Disables UART interrupt from triggering the DMA transmit event
 *
 * Disables the UART interrupt as the condition to generate an event to
 * directly trigger the DMA. This API configures the DMA_TRIG_TX
 * register, which is the event publisher used for triggering the DMA to do
 * a transmit data transfer.
 *
 * @note DMA_TRIG_TX only has one transmit interrupt source
 *
 *  @param[in]  uart       Pointer to the register overlay for the
 *                         peripheral
 */
__STATIC_INLINE void DL_UART_disableDMATransmitEvent(UART_Regs *uart)
{
    uart->DMA_TRIG_TX.IMASK = UART_DMA_TRIG_TX_IMASK_TXINT_CLR;
}

/**
 *  @brief      Check which UART interrupt for DMA receive events is enabled
 *
 *  This API checks the DMA_TRIG_RX register, which is the event publisher used
 *  for triggering the DMA to do a receive data transfer.
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check Bitwise OR of
 *                             @ref DL_UART_DMA_INTERRUPT_RX.
 *
 *  @return     Which of the requested UART interrupts is enabled
 *
 *  @retval     One of @ref DL_UART_DMA_INTERRUPT_RX
 */
__STATIC_INLINE uint32_t DL_UART_getEnabledDMAReceiveEvent(
    UART_Regs *uart, uint32_t interruptMask)
{
    return (uart->DMA_TRIG_RX.IMASK & interruptMask);
}

/**
 *  @brief      Check if UART interrupt for DMA transmit event is enabled
 *
 *  This API checks the DMA_TRIG_TX register, which is the event publisher used
 *  for triggering the DMA to do a transmit data transfer.
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The requested UART interrupt status
 *
 *  @retval     DL_UART_DMA_INTERRUPT_TX if enabled, 0 if not enabled
 */
__STATIC_INLINE uint32_t DL_UART_getEnabledDMATransmitEvent(UART_Regs *uart)
{
    return (uart->DMA_TRIG_TX.IMASK & UART_DMA_TRIG_TX_IMASK_TXINT_MASK);
}

/**
 *  @brief      Check interrupt flag of enabled UART interrupt for DMA receive event
 *
 * Checks if any of the UART interrupts for the DMA receive event that were
 * previously enabled are pending.
 * This API checks the DMA_TRIG_RX register, which is the event publisher used
 * for triggering the DMA to do a receive data transfer.
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_UART_DMA_INTERRUPT_RX.
 *
 *  @return     The requested UART interrupt status
 *
 *  @retval     One of @ref DL_UART_DMA_INTERRUPT_RX
 *
 *  @sa         DL_UART_enableDMAReceiveEvent
 */
__STATIC_INLINE uint32_t DL_UART_getEnabledDMAReceiveEventStatus(
    UART_Regs *uart, uint32_t interruptMask)
{
    return (uart->DMA_TRIG_RX.MIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of enabled UART interrupt for DMA transmit event
 *
 * Checks if the UART interrupt for the DMA transmit event that was
 * previously enabled is pending.
 * This API checks the DMA_TRIG_TX register, which is the event publisher used
 * for triggering the DMA to do a transmit data transfer.
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The requested UART interrupt status
 *
 *  @retval     DL_UART_DMA_INTERRUPT_TX if enabled, 0 if not enabled
 *
 *  @sa         DL_UART_enableDMATransmitEvent
 */
__STATIC_INLINE uint32_t DL_UART_getEnabledDMATransmitEventStatus(
    UART_Regs *uart)
{
    return (uart->DMA_TRIG_TX.MIS & UART_DMA_TRIG_TX_MIS_TXINT_MASK);
}

/**
 *  @brief      Check interrupt flag of any UART interrupt for DMA receive event
 *
 *  Checks if any of the UART interrupts for DMA receive event are pending.
 *  Interrupts do not have to be previously enabled.
 *  This API checks the DMA_TRIG_RX register, which is the event publisher used
 *  for triggering the DMA to do a receive data transfer.
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_UART_DMA_INTERRUPT_RX.
 *
 *  @return     Which of the requested UART interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_UART_DMA_INTERRUPT_RX values
 */
__STATIC_INLINE uint32_t DL_UART_getRawDMAReceiveEventStatus(
    UART_Regs *uart, uint32_t interruptMask)
{
    return (uart->DMA_TRIG_RX.RIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of any UART interrupt for DMA transmit event
 *
 *  Checks if any of the UART interrupts for DMA transmit event are pending.
 *  Interrupts do not have to be previously enabled.
 *  This API checks the DMA_TRIG_TX register, which is the event publisher used
 *  for triggering the DMA to do a transmit data transfer.
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The requested UART interrupt status
 *
 *  @retval     DL_UART_DMA_INTERRUPT_TX if enabled, 0 if not enabled
 */
__STATIC_INLINE uint32_t DL_UART_getRawDMATransmitEventStatus(UART_Regs *uart)
{
    return (uart->DMA_TRIG_TX.RIS & UART_DMA_TRIG_TX_RIS_TXINT_MASK);
}

/**
 *  @brief      Get highest priority pending UART interrupt for DMA receive event
 *
 *  Checks if any of the UART interrupts for DMA receive event are pending.
 *  Interrupts do not have to be previously enabled.
 *  This API checks the DMA_TRIG_RX register, which is the event publisher used
 *  for triggering the DMA to do a receive data transfer.
 *
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The highest priority pending UART interrupt
 *
 *  @retval     One of @ref DL_UART_DMA_IIDX_RX
 */
__STATIC_INLINE DL_UART_DMA_IIDX_RX DL_UART_getPendingDMAReceiveEvent(
    UART_Regs *uart)
{
    return (DL_UART_DMA_IIDX_RX)(uart->DMA_TRIG_RX.IIDX);
}

/**
 *  @brief      Get highest priority pending UART interrupt for DMA transmit event
 *
 *  Checks if the UART interrupt for DMA transmit event is pending.
 *  Interrupts do not have to be previously enabled.
 *  This API checks the DMA_TRIG_TX register, which is the event publisher used
 *  for triggering the DMA to do a transmit data transfer.
 *
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The highest priority pending UART interrupt
 *
 *  @retval     DL_UART_DMA_IIDX_TX if pending, 0 if not pending
 */
__STATIC_INLINE DL_UART_DMA_IIDX_TX DL_UART_getPendingDMATransmitEvent(
    UART_Regs *uart)
{
    return (DL_UART_DMA_IIDX_TX)(uart->DMA_TRIG_TX.IIDX);
}

/**
 *  @brief      Clear pending UART interrupts for DMA receive event
 *
 *  This API checks the DMA_TRIG_RX register, which is the event publisher used
 *  for triggering the DMA to do a receive data transfer.
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_UART_DMA_INTERRUPT_RX.
 */
__STATIC_INLINE void DL_UART_clearDMAReceiveEventStatus(
    UART_Regs *uart, uint32_t interruptMask)
{
    uart->DMA_TRIG_RX.ICLR = interruptMask;
}

/**
 *  @brief      Clear pending UART interrupt for DMA transmit event
 *
 *  This API checks the DMA_TRIG_TX register, which is the event publisher used
 *  for triggering the DMA to do a transmit data transfer.
 *
 *  @param[in]  uart           Pointer to the register overlay for the
 *                             peripheral
 * @note DMA_TRIG_TX only has one transmit interrupt source
 */
__STATIC_INLINE void DL_UART_clearDMATransmitEventStatus(UART_Regs *uart)
{
    uart->DMA_TRIG_TX.ICLR = UART_DMA_TRIG_TX_ICLR_TXINT_CLR;
}

/*!
 *  @brief Sets the second clock divider ratio
 *
 *  This API sets the CLKDIV2 register, which stores the clock divider ratio
 *  used to further divide the UART function clock in IrDA UART mode
 *
 *  @param[in]  uart    Pointer to the register overlay for the peripheral
 *  @param[in]  ratio   The CLKDIV2 value.  One of @ref DL_UART_CLOCK_DIVIDE_RATIO
 */
__STATIC_INLINE void DL_UART_setClockDivider2(
    UART_Regs *uart, DL_UART_CLOCK_DIVIDE2_RATIO ratio)
{
    uart->CLKDIV2 = (uint32_t) ratio;
}

/*!
 *  @brief Gets the value of CLKDIV2
 *
 *  This API gets the value stored in the CLKDIV2 register, which stores the
 *  clock divider ratio to further divide the UART function clock in IrDA Mode
 *
 *  @param[in]  uart    Pointer to the register overlay for the peripheral
 *
 *  @return     The clock divider ratio stored in the CLKDIV2 register
 *
 *  @retval     The CLKDIV2 value.  One of @ref DL_UART_CLOCK_DIVIDE2_RATIO
 */

__STATIC_INLINE DL_UART_CLOCK_DIVIDE2_RATIO DL_UART_getClockDivider2(
    UART_Regs *uart)
{
    uint32_t ratio = uart->CLKDIV2;
    return (DL_UART_CLOCK_DIVIDE2_RATIO) ratio;
}
#ifdef __MSPM0_HAS_UART_MAIN__

/**
 *  @brief      Save UART Main configuration before entering a power loss state.
 *
 *  Some MSPM0G peripherals residing in PD1 domain do not retain register
 *  contents when entering STOP or STANDBY modes. Please refer to the datasheet
 *  for the full list of peripheral instances that exhibit this behavior.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr  Configuration backup setup structure. See
 *                  @ref DL_UART_Main_backupConfig.
 *
 *  @retval     FALSE if a configuration already exists in ptr (will not be
 *              overwritten). TRUE if a configuration was successfully saved
 *
 */
bool DL_UART_Main_saveConfiguration(
    UART_Regs *uart, DL_UART_Main_backupConfig *ptr);

/**
 *  @brief      Restore UART Main configuration after leaving a power loss state.
 *
 *  Some MSPM0G peripherals residing in PD1 domain do not retain register
 *  contents when entering STOP or STANDBY modes. Please refer to the datasheet
 *  for the full list of peripheral instances that exhibit this behavior.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr   Configuration backup setup structure. See
 *                    @ref DL_UART_Main_backupConfig.
 *
 *  @retval     FALSE if a configuration does not exist in ptr (will not be
 *              loaded). TRUE if a configuration successfully loaded
 *
 */
bool DL_UART_Main_restoreConfiguration(
    UART_Regs *uart, DL_UART_Main_backupConfig *ptr);

#endif /* __MSPM0_HAS_UART_MAIN__ */

#ifdef __MSPM0_HAS_UART_EXTD__

/**
 *  @brief      Save UART Extend configuration before entering a power loss
 *              state.
 *
 *  Some MSPM0G peripherals residing in PD1 domain do not retain register
 *  contents when entering STOP or STANDBY modes. Please refer to the datasheet
 *  for the full list of peripheral instances that exhibit this behavior.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr   Configuration backup setup structure. See
 *                    @ref DL_UART_Extend_backupConfig.
 *
 *  @retval     FALSE if a configuration already exists in ptr (will not be
 *              overwritten). TRUE if a configuration was successfully saved
 *
 */
bool DL_UART_Extend_saveConfiguration(
    UART_Regs *uart, DL_UART_Extend_backupConfig *ptr);

/**
 *  @brief      Restore UART Extend configuration after leaving a power loss
 *              state.
 *
 *  Some MSPM0G peripherals residing in PD1 domain do not retain register
 *  contents when entering STOP or STANDBY modes. Please refer to the datasheet
 *  for the full list of peripheral instances that exhibit this behavior.
 *
 *  @param[in]  uart  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr   Configuration backup setup structure. See
 *                    @ref DL_UART_Extend_backupConfig.
 *
 *  @retval     FALSE if a configuration does not exist in ptr (will not be
 *              loaded). TRUE if a configuration successfully loaded
 *
 */
bool DL_UART_Extend_restoreConfiguration(
    UART_Regs *uart, DL_UART_Extend_backupConfig *ptr);

#endif /* __MSPM0_HAS_UART_EXTD__ */

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_UART_MAIN__ || __MSPM0_HAS_UART_EXTD__ */

#else
#warning \
    "TI highly recommends accessing uart with dl_uart_main, dl_uart_extend.h only."
#endif /* ti_dl_dl_uart_main__include ti_dl_dl_uart_extend__include */

#endif /* ti_dl_dl_uart__include */
/** @}*/
