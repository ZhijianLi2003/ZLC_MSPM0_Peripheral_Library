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
 *  @file       dl_i2c.h
 *  @brief      Inter-Integrated Circuit (I2C) Driver Library
 *  @defgroup   I2C  Inter-Integrated Circuit (I2C)
 *
 *  @anchor ti_dl_dl_i2c_Overview
 *  # Overview
 *
 *   The I2C Library allows full configuration of the MSPM0 I2C module.
 *   The I2C module provides a standardized serial interface to transfer data
 *   between MSP devices and other external I2C devices (such as a sensors,
 *   memory, or DACs).
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup I2C
 * @{
 */
#ifndef ti_dl_dl_i2c__include
#define ti_dl_dl_i2c__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_I2C__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/*!
 * @brief I2C number of bytes which could be put into the TX FIFO
 *
 * This variable is device specific and is calculated using the system parameter
 * I2C_SYS_FENTRIES defined in each devices header file.
*/
#define DL_I2C_TX_FIFO_COUNT_MAXIMUM          ((uint32_t)I2C_SYS_FENTRIES << 8)

/*!
 * @brief I2C number of bytes which could be put into the RX FIFO
 *
 * This variable is device specific and is calculated using the system parameter
 * I2C_SYS_FENTRIES defined in each devices header file.
*/
#define DL_I2C_RX_FIFO_COUNT_MAXIMUM               ((uint32_t)I2C_SYS_FENTRIES)

/** @addtogroup DL_I2C_CONTROLLER_STATUS
 *  @{
 */
/*!
 * @brief I2C is busy
 *
 * The BUSY bit is set during an ongoing transaction, so is set during the
 * transmit/receive of the amount of data set in WBLEN including START, RESTART,
 * Address and STOP signal generation when required for the current transaction
 */
#define DL_I2C_CONTROLLER_STATUS_BUSY                       (I2C_MSR_BUSY_MASK)

/*!
 * @brief I2C error detected
 *
 * The error can be from the target address not being acknowledged or the
 * transmit data not being acknowledged
 */
#define DL_I2C_CONTROLLER_STATUS_ERROR                       (I2C_MSR_ERR_MASK)

/*!
 * @brief I2C address acknowledged
 */
#define DL_I2C_CONTROLLER_STATUS_ADDR_ACK                 (I2C_MSR_ADRACK_MASK)

/*!
 * @brief I2C data acknowledged
 */
#define DL_I2C_CONTROLLER_STATUS_DATA_ACK                 (I2C_MSR_DATACK_MASK)

/*!
 * @brief I2C arbitration lost
 */
#define DL_I2C_CONTROLLER_STATUS_ARBITRATION_LOST         (I2C_MSR_ARBLST_MASK)

/*!
 * @brief I2C idle
 */
#define DL_I2C_CONTROLLER_STATUS_IDLE                       (I2C_MSR_IDLE_MASK)

/*!
 * @brief I2C bus busy
 *
 * The bit changes based on the START and STOP conditions
 */
#define DL_I2C_CONTROLLER_STATUS_BUSY_BUS                 (I2C_MSR_BUSBSY_MASK)

/** @}*/


/** @addtogroup DL_I2C_TARGET_STATUS
 *  @{
 */

/*!
 * @brief Indicates the address for which target address match happened
 */
#define DL_I2C_TARGET_STATUS_ADDRESS_MATCH             (I2C_SSR_ADDRMATCH_MASK)

/*!
 * @brief I2C Target Stale TX FIFO
 *
 * Set = The target TX FIFO data is stale. This occurs when the TX FIFO was not
 *   emptied during the previous I2C transaction
 * Clear = The target TX FIFO data is not stale
 */
#define DL_I2C_TARGET_STATUS_STALE_TX_FIFO          (I2C_SSR_STALE_TXFIFO_MASK)

/*!
 * @brief I2C Target TX Mode
 *
 * Set = Target is in the TX_DATA, TX_ACK, TX_WAIT, or ADDR_ACK state with the
 *   bus direction set to read
 * Clear = Target is not in the TX_DATA, TX_ACK, TX_WAIT, or ADDR_ACK state
 *   with the bus direction set to read
 */
#define DL_I2C_TARGET_STATUS_TX_MODE                      (I2C_SSR_TXMODE_MASK)

/*!
 * @brief I2C Target Bus Busy
 *
 * Set = The I2C bus is busy. This is cleared on a timeout
 * Clear = The I2C bus is not busy. This bit is cleared when a STOP condition is
 *   detected on the bus.
 */
#define DL_I2C_TARGET_STATUS_BUS_BUSY                     (I2C_SSR_BUSBSY_MASK)

/*!
 * @brief I2C Target RX Mode
 *
 * Set = Target is in the RX_DATA, RX_ACK, RX_WAIT, RX_ACK_WAIT or ADDR_ACK
 *   state with the bus direction set to write
 * Clear = Target is not in the RX_DATA, RX_ACK, RX_WAIT, RX_ACK_WAIT or ADDR_ACK
 *   state with the bus direction set to write
 */
#define DL_I2C_TARGET_STATUS_RX_MODE                      (I2C_SSR_RXMODE_MASK)


/*!
 * @brief Direction of I2C Quick Command
 * Only valid when QCMDST is set. @sa DL_I2C_TARGET_STATUS_QUICK_COMMAND_STATUS.
 * Set = Quick command was a read
 * Clear = Quick command was a write
 */
#define DL_I2C_TARGET_STATUS_QUICK_COMMAND_READ_WRITE     (I2C_SSR_QCMDRW_MASK)

/*!
 * @brief Status of I2C Quick Command
 * @sa DL_I2C_TARGET_STATUS_QUICK_COMMAND_READ_WRITE.
 * Set = Last transaction was a Quick Comand transaction
 * Clear = Last transaction was normal or has not occurred
 */
#define DL_I2C_TARGET_STATUS_QUICK_COMMAND_STATUS         (I2C_SSR_QCMDST_MASK)

/*!
 * @brief I2C Target Own Address Alternate Matched
 */
#define DL_I2C_TARGET_STATUS_OWN_ADDR_ALTERNATE_MATCHED  (I2C_SSR_OAR2SEL_MASK)

/*!
 * @brief I2C Target Transmit Request
 */
#define DL_I2C_TARGET_STATUS_TRANSMIT_REQUEST               (I2C_SSR_TREQ_MASK)

/*!
 * @brief I2C Target Receive Request
 */
#define DL_I2C_TARGET_STATUS_RECEIVE_REQUEST                (I2C_SSR_RREQ_MASK)

/** @}*/

/** @addtogroup DL_I2C_INTERRUPT
 *  @{
 */
/*!
 * @brief Controller Receive Transaction completed Interrupt
 */
#define DL_I2C_INTERRUPT_CONTROLLER_RX_DONE  (I2C_CPU_INT_IMASK_MRXDONE_SET)

/*!
 * @brief Controller Transmit Transaction completed Interrupt
 */
#define DL_I2C_INTERRUPT_CONTROLLER_TX_DONE  (I2C_CPU_INT_IMASK_MTXDONE_SET)

/*!
 * @brief Controller Receive FIFO Trigger when >= defined bytes
 */
#define DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER                            \
                                          (I2C_CPU_INT_IMASK_MRXFIFOTRG_SET)

/*!
 * @brief Controller Transmit FIFO Trigger when <= defined bytes
 */
#define DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER                            \
                                          (I2C_CPU_INT_IMASK_MTXFIFOTRG_SET)

/*!
 * @brief Controller Receive FIFO is full
 */
#define DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_FULL                               \
                                         (I2C_CPU_INT_IMASK_MRXFIFOFULL_SET)

/*!
 * @brief Controller Transmit FIFO is empty
 */
#define DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_EMPTY                              \
                                            (I2C_CPU_INT_IMASK_MTXEMPTY_SET)

/*!
 * @brief Address/Data NACK Interrupt
 */
#define DL_I2C_INTERRUPT_CONTROLLER_NACK       (I2C_CPU_INT_IMASK_MNACK_SET)

/*!
 * @brief START Detection Interrupt
 */
#define DL_I2C_INTERRUPT_CONTROLLER_START     (I2C_CPU_INT_IMASK_MSTART_SET)

/*!
 * @brief STOP Detection Interrupt
 */
#define DL_I2C_INTERRUPT_CONTROLLER_STOP       (I2C_CPU_INT_IMASK_MSTOP_SET)

/*!
 * @brief Arbitration Lost Interrupt
 */
#define DL_I2C_INTERRUPT_CONTROLLER_ARBITRATION_LOST                          \
                                            (I2C_CPU_INT_IMASK_MARBLOST_SET)

/*!
 * @brief Controller DMA Done on Event 1 publisher
 */
#define DL_I2C_INTERRUPT_CONTROLLER_EVENT1_DMA_DONE                           \
                                       (I2C_CPU_INT_IMASK_MDMA_DONE_TX_SET)

/*!
 * @brief Controller DMA Done on Event 2 publisher
 */
#define DL_I2C_INTERRUPT_CONTROLLER_EVENT2_DMA_DONE                           \
                                       (I2C_CPU_INT_IMASK_MDMA_DONE_RX_SET)


/*!
 * @brief Controller SMBus/PMBus PEC Receive Error Interrupt
 */
#define DL_I2C_INTERRUPT_CONTROLLER_PEC_RX_ERROR                              \
                                         (I2C_CPU_INT_IMASK_MPEC_RX_ERR_SET)


/*!
 * @brief Target Receive Data Interrupt (byte has been received)
 */
#define DL_I2C_INTERRUPT_TARGET_RX_DONE      (I2C_CPU_INT_IMASK_SRXDONE_SET)

/*!
 * @brief Target Transmit Transaction completed Interrupt
 */
#define DL_I2C_INTERRUPT_TARGET_TX_DONE      (I2C_CPU_INT_IMASK_STXDONE_SET)

/*!
 * @brief Target Receive FIFO Trigger
 */
#define DL_I2C_INTERRUPT_TARGET_RXFIFO_TRIGGER                                \
                                          (I2C_CPU_INT_IMASK_SRXFIFOTRG_SET)

/*!
 * @brief Target Transmit FIFO Trigger
 */
#define DL_I2C_INTERRUPT_TARGET_TXFIFO_TRIGGER                                \
                                          (I2C_CPU_INT_IMASK_STXFIFOTRG_SET)

/*!
 * @brief Target RX FIFO full
 */
#define DL_I2C_INTERRUPT_TARGET_RXFIFO_FULL                                   \
                                         (I2C_CPU_INT_IMASK_SRXFIFOFULL_SET)

/*!
 * @brief Target TX FIFO empty. All data in Transmit FIFO shifted out and
 * transmit goes into idle mode.
 */
#define DL_I2C_INTERRUPT_TARGET_TXFIFO_EMPTY                                  \
                                            (I2C_CPU_INT_IMASK_STXEMPTY_SET)

/*!
 * @brief Target Start Condition detected
 */
#define DL_I2C_INTERRUPT_TARGET_START                                         \
                                              (I2C_CPU_INT_IMASK_SSTART_SET)

/*!
 * @brief Target Stop Condition detected
 */
#define DL_I2C_INTERRUPT_TARGET_STOP           (I2C_CPU_INT_IMASK_SSTOP_SET)

/*!
 * @brief General Call Interrupt
 */
#define DL_I2C_INTERRUPT_TARGET_GENERAL_CALL                                  \
                                            (I2C_CPU_INT_IMASK_SGENCALL_SET)

/*!
 * @brief Target DMA Done on Event 1 Publisher
 */
#define DL_I2C_INTERRUPT_TARGET_EVENT1_DMA_DONE                               \
                                        (I2C_CPU_INT_IMASK_SDMA_DONE_TX_SET)

/*!
 * @brief Target DMA Done on Event 2 Publisher
 */
#define DL_I2C_INTERRUPT_TARGET_EVENT2_DMA_DONE                               \
                                        (I2C_CPU_INT_IMASK_SDMA_DONE_RX_SET)


/*!
 * @brief Target SMBus/PMBus PEC Receive Error Interrupt
 */
#define DL_I2C_INTERRUPT_TARGET_PEC_RX_ERROR                                  \
                                         (I2C_CPU_INT_IMASK_SPEC_RX_ERR_SET)

/*!
 * @brief Target TX FIFO Underflow Interrupt
 */
#define DL_I2C_INTERRUPT_TARGET_TXFIFO_UNDERFLOW                              \
                                            (I2C_CPU_INT_IMASK_STX_UNFL_SET)

/*!
 * @brief Target RX FIFO Overflow Interrupt
 */
#define DL_I2C_INTERRUPT_TARGET_RXFIFO_OVERFLOW                              \
                                            (I2C_CPU_INT_IMASK_SRX_OVFL_SET)

/*!
 * @brief Target Arbitration Lost Interrupt
 */
#define DL_I2C_INTERRUPT_TARGET_ARBITRATION_LOST                              \
                                            (I2C_CPU_INT_IMASK_SARBLOST_SET)

/*!
 * @brief Interrupt Overflow Interrupt. Occurs when Target START or STOP
 *        interrupts overflow (i.e. occurs twice without being serviced)
 */
#define DL_I2C_TARGET_INTERRUPT_OVERFLOW   (I2C_CPU_INT_IMASK_INTR_OVFL_SET)

/*!
 * @brief Timeout A Interrupt
 */
#define DL_I2C_INTERRUPT_TIMEOUT_A          (I2C_CPU_INT_IMASK_TIMEOUTA_SET)

/*!
 * @brief Timeout B Interrupt
 */
#define DL_I2C_INTERRUPT_TIMEOUT_B          (I2C_CPU_INT_IMASK_TIMEOUTB_SET)


/** @}*/

/** @addtogroup DL_I2C_DMA_INTERRUPT
 *  @{
 */
/*!
 * @brief Peripheral Transmit FIFO Trigger interrupt for DMA trigger
 */
#define DL_I2C_DMA_INTERRUPT_TARGET_TXFIFO_TRIGGER                            \
                                          (I2C_DMA_TRIG1_IMASK_STXFIFOTRG_SET)

/*!
 * @brief Peripheral Receive FIFO Trigger interrupt for DMA trigger
 */
#define DL_I2C_DMA_INTERRUPT_TARGET_RXFIFO_TRIGGER                            \
                                          (I2C_DMA_TRIG1_IMASK_SRXFIFOTRG_SET)

/*!
 * @brief Controller Transmit FIFO Trigger when <= defined bytes for DMA trigger
 */
#define DL_I2C_DMA_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER                        \
                                          (I2C_DMA_TRIG1_IMASK_MTXFIFOTRG_SET)

/*!
 * @brief Controller Receive FIFO Trigger when >= defined bytes for DMA trigger
 */
#define DL_I2C_DMA_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER                        \
                                          (I2C_DMA_TRIG1_IMASK_MRXFIFOTRG_SET)

/** @}*/

/* clang-format on */

/*! @enum DL_I2C_DMA_IIDX */
typedef enum {
    /*! I2C interrupt index for enabling I2C Target Transmit FIFO Trigger as DMA trigger */
    DL_I2C_DMA_IIDX_TARGET_TXFIFO_TRIGGER = I2C_DMA_TRIG1_IIDX_STAT_MTXFIFOTRG,
    /*! I2C interrupt index for enabling I2C Target Receive FIFO Trigger as DMA trigger */
    DL_I2C_DMA_IIDX_TARGET_RXFIFO_TRIGGER = I2C_DMA_TRIG1_IIDX_STAT_MRXFIFOTRG,
    /*! I2C interrupt index for enabling I2C Controller Transmit FIFO Trigger as DMA trigger */
    DL_I2C_DMA_IIDX_CONTROLLER_TXFIFO_TRIGGER =
        I2C_DMA_TRIG1_IIDX_STAT_STXFIFOTRG,
    /*! I2C interrupt index for enabling I2C Controller Receive FIFO Trigger as DMA trigger */
    DL_I2C_DMA_IIDX_CONTROLLER_RXFIFO_TRIGGER =
        I2C_DMA_TRIG1_IIDX_STAT_SRXFIFOTRG
} DL_I2C_DMA_IIDX;

/** @enum DL_I2C_EVENT_ROUTE */
typedef enum {
    /*! I2C event route 1 */
    DL_I2C_EVENT_ROUTE_1 = 0,
    /*! I2C event route 2 */
    DL_I2C_EVENT_ROUTE_2 = 12
} DL_I2C_EVENT_ROUTE;

/** @enum DL_I2C_CLOCK */
typedef enum {
    /*!  BUSCLK enabled as I2C clock source */
    DL_I2C_CLOCK_BUSCLK = I2C_CLKSEL_BUSCLK_SEL_ENABLE,
    /*!  MFCLK enabled as I2C clock source */
    DL_I2C_CLOCK_MFCLK = I2C_CLKSEL_MFCLK_SEL_ENABLE,
} DL_I2C_CLOCK;

/** @enum DL_I2C_CLOCK_DIVIDE */
typedef enum {
    /*!  I2C Clock Divided by 1 */
    DL_I2C_CLOCK_DIVIDE_1 = I2C_CLKDIV_RATIO_DIV_BY_1,
    /*!  I2C Clock Divided by 2 */
    DL_I2C_CLOCK_DIVIDE_2 = I2C_CLKDIV_RATIO_DIV_BY_2,
    /*!  I2C Clock Divided by 3 */
    DL_I2C_CLOCK_DIVIDE_3 = I2C_CLKDIV_RATIO_DIV_BY_3,
    /*!  I2C Clock Divided by 4 */
    DL_I2C_CLOCK_DIVIDE_4 = I2C_CLKDIV_RATIO_DIV_BY_4,
    /*!  I2C Clock Divided by 5 */
    DL_I2C_CLOCK_DIVIDE_5 = I2C_CLKDIV_RATIO_DIV_BY_5,
    /*!  I2C Clock Divided by 6 */
    DL_I2C_CLOCK_DIVIDE_6 = I2C_CLKDIV_RATIO_DIV_BY_6,
    /*!  I2C Clock Divided by 7 */
    DL_I2C_CLOCK_DIVIDE_7 = I2C_CLKDIV_RATIO_DIV_BY_7,
    /*!  I2C Clock Divided by 8 */
    DL_I2C_CLOCK_DIVIDE_8 = I2C_CLKDIV_RATIO_DIV_BY_8,
} DL_I2C_CLOCK_DIVIDE;

/** @enum DL_I2C_TARGET_ADDRESSING_MODE */
typedef enum {
    /*! Enable Target in 7-bit addressing mode */
    DL_I2C_TARGET_ADDRESSING_MODE_7_BIT = I2C_SOAR_SMODE_MODE7,
    /*! Enable Target in 10-bit addressing mode */
    DL_I2C_TARGET_ADDRESSING_MODE_10_BIT = I2C_SOAR_SMODE_MODE10,
} DL_I2C_TARGET_ADDRESSING_MODE;

/** @enum DL_I2C_TARGET_PEC_STATUS */
typedef enum {
    /*!  I2C Target SMBus/PMBus PEC was checked in the transaction that occurred
     *   before the last Stop */
    DL_I2C_TARGET_PEC_STATUS_CHECKED = I2C_TARGET_PECSR_PECSTS_CHECK_SET,
    /*!  I2C Target SMBus/PMBus PEC was not checked in the transaction that
     *   occurred before the last Stop */
    DL_I2C_TARGET_PEC_STATUS_NOT_CHECKED =
        I2C_TARGET_PECSR_PECSTS_CHECK_CLEARED,
} DL_I2C_TARGET_PEC_STATUS;

/** @enum DL_I2C_ANALOG_GLITCH_FILTER_WIDTH */
typedef enum {
    /*!  Pulses shorter than 5ns in length are filtered.  */
    DL_I2C_ANALOG_GLITCH_FILTER_WIDTH_5NS = I2C_GFCTL_AGFSEL_AGLIT_5,
    /*!  Pulses shorter than 10ns in length are filtered.  */
    DL_I2C_ANALOG_GLITCH_FILTER_WIDTH_10NS = I2C_GFCTL_AGFSEL_AGLIT_10,
    /*!  Pulses shorter than 25ns in length are filtered.  */
    DL_I2C_ANALOG_GLITCH_FILTER_WIDTH_25NS = I2C_GFCTL_AGFSEL_AGLIT_25,
    /*!  Pulses shorter than 50ns in length are filtered.  */
    DL_I2C_ANALOG_GLITCH_FILTER_WIDTH_50NS = I2C_GFCTL_AGFSEL_AGLIT_50,
} DL_I2C_ANALOG_GLITCH_FILTER_WIDTH;

/** @enum DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH */
typedef enum {
    /*!  Pulses filtering disabled.  */
    DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH_DISABLED = I2C_GFCTL_DGFSEL_DISABLED,
    /*!  Pulses shorter than 1 functional clock tick in length are filtered.  */
    DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH_CLOCKS_1 = I2C_GFCTL_DGFSEL_CLK_1,
    /*!  Pulses shorter than 2 functional clock ticks in length are filtered.  */
    DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH_CLOCKS_2 = I2C_GFCTL_DGFSEL_CLK_2,
    /*!  Pulses shorter than 3 functional clock ticks in length are filtered.  */
    DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH_CLOCKS_3 = I2C_GFCTL_DGFSEL_CLK_3,
    /*!  Pulses shorter than 4 functional clock ticks in length are filtered.  */
    DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH_CLOCKS_4 = I2C_GFCTL_DGFSEL_CLK_4,
    /*!  Pulses shorter than 8 functional clock ticks in length are filtered.  */
    DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH_CLOCKS_8 = I2C_GFCTL_DGFSEL_CLK_8,
    /*!  Pulses shorter than 16 functional clock ticks in length are filtered.  */
    DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH_CLOCKS_16 = I2C_GFCTL_DGFSEL_CLK_16,
    /*!  Pulses shorter than 31 functional clock ticks in length are filtered.  */
    DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH_CLOCKS_31 = I2C_GFCTL_DGFSEL_CLK_31,
} DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH;

/** @enum DL_I2C_CONTROLLER_DIRECTION */
typedef enum {
    /*! Set direction to controller transmitting to target */
    DL_I2C_CONTROLLER_DIRECTION_TX = I2C_MSA_DIR_TRANSMIT,
    /*! Set direction to controller receiving from target */
    DL_I2C_CONTROLLER_DIRECTION_RX = I2C_MSA_DIR_RECEIVE,
} DL_I2C_CONTROLLER_DIRECTION;

/** @enum DL_I2C_CONTROLLER_ADDRESSING_MODE */
typedef enum {
    /*! Enable Controller in 7-bit addressing mode */
    DL_I2C_CONTROLLER_ADDRESSING_MODE_7_BIT = I2C_MSA_MMODE_MODE7,
    /*! Enable Controller in 10-bit addressing mode */
    DL_I2C_CONTROLLER_ADDRESSING_MODE_10_BIT = I2C_MSA_MMODE_MODE10,
} DL_I2C_CONTROLLER_ADDRESSING_MODE;

/** @enum DL_I2C_CONTROLLER_PEC_STATUS */
typedef enum {
    /*!  I2C Controller SMBus/PMBus PEC was checked in the transaction that
     *   occurred before the last Stop */
    DL_I2C_CONTROLLER_PEC_STATUS_CHECKED =
        I2C_CONTROLLER_PECSR_PECSTS_CHECK_SET,
    /*!  I2C Controller SMBus/PMBus PEC was not checked in the transaction that
     *   occurred the last Stop */
    DL_I2C_CONTROLLER_PEC_STATUS_NOT_CHECKED =
        I2C_CONTROLLER_PECSR_PECSTS_CHECK_CLEARED,
} DL_I2C_CONTROLLER_PEC_STATUS;

/** @enum DL_I2C_CONTROLLER_PEC_CHECK_ERROR */
typedef enum {
    /*! I2C Controller SMBus/PMBus PEC check error occurred in the transaction
     *  before the last stop */
    DL_I2C_CONTROLLER_PEC_CHECK_ERROR_SET =
        I2C_CONTROLLER_PECSR_PECSTS_ERROR_SET,
    /*! I2C Controller SMBus/PMBus PEC check error did not occur in the
     *  transaction before the last stop */
    DL_I2C_CONTROLLER_PEC_CHECK_ERROR_CLEARED =
        I2C_CONTROLLER_PECSR_PECSTS_ERROR_CLEARED,
} DL_I2C_CONTROLLER_PEC_CHECK_ERROR;

/** @enum DL_I2C_CONTROLLER_SCL */
typedef enum {
    /*!  I2C SCL signal high */
    DL_I2C_CONTROLLER_SCL_HIGH = I2C_MBMON_SCL_SET,
    /*!  I2C SCL signal low */
    DL_I2C_CONTROLLER_SCL_LOW = I2C_MBMON_SCL_CLEARED,
} DL_I2C_CONTROLLER_SCL;

/** @enum DL_I2C_CONTROLLER_SDA */
typedef enum {
    /*!  I2C SDA signal high */
    DL_I2C_CONTROLLER_SDA_HIGH = I2C_MBMON_SDA_SET,
    /*!  I2C SDA signal low */
    DL_I2C_CONTROLLER_SDA_LOW = I2C_MBMON_SDA_CLEARED,
} DL_I2C_CONTROLLER_SDA;

/** @enum DL_I2C_CONTROLLER_START */
typedef enum {
    /*!  Controller generates START condition */
    DL_I2C_CONTROLLER_START_ENABLE = I2C_MCTR_START_ENABLE,
    /*!  Controller doesn't generate START condition */
    DL_I2C_CONTROLLER_START_DISABLE = I2C_MCTR_START_DISABLE,
} DL_I2C_CONTROLLER_START;

/** @enum DL_I2C_CONTROLLER_STOP */
typedef enum {
    /*!  Controller generates STOP condition */
    DL_I2C_CONTROLLER_STOP_ENABLE = I2C_MCTR_STOP_ENABLE,
    /*!  Controller doesn't generate STOP condition */
    DL_I2C_CONTROLLER_STOP_DISABLE = I2C_MCTR_STOP_DISABLE,
} DL_I2C_CONTROLLER_STOP;

/** @enum DL_I2C_CONTROLLER_ACK */
typedef enum {
    /*!  Last received data byte of a transaction is not ACKed automatically */
    DL_I2C_CONTROLLER_ACK_ENABLE = I2C_MCTR_ACK_ENABLE,
    /*!  Last received data byte of a transaction is ACKed automatically */
    DL_I2C_CONTROLLER_ACK_DISABLE = I2C_MCTR_ACK_DISABLE,
} DL_I2C_CONTROLLER_ACK;

/** @enum DL_I2C_TX_FIFO_LEVEL */
typedef enum {
    /*!  Trigger when the TX FIFO is empty */
    DL_I2C_TX_FIFO_LEVEL_EMPTY = I2C_MFIFOCTL_TXTRIG_EMPTY,
    /*!  Trigger when TX FIFO contains 1 byte */
    DL_I2C_TX_FIFO_LEVEL_BYTES_1 = I2C_MFIFOCTL_TXTRIG_LEVEL_1,
    /*!  Trigger when TX FIFO contains 2 bytes */
    DL_I2C_TX_FIFO_LEVEL_BYTES_2 = I2C_MFIFOCTL_TXTRIG_LEVEL_2,
    /*!  Trigger when TX FIFO contains 3 bytes */
    DL_I2C_TX_FIFO_LEVEL_BYTES_3 = I2C_MFIFOCTL_TXTRIG_LEVEL_3,
    /*!  Trigger when TX FIFO contains 4 bytes */
    DL_I2C_TX_FIFO_LEVEL_BYTES_4 = I2C_MFIFOCTL_TXTRIG_LEVEL_4,
    /*!  Trigger when TX FIFO contains 5 bytes */
    DL_I2C_TX_FIFO_LEVEL_BYTES_5 = I2C_MFIFOCTL_TXTRIG_LEVEL_5,
    /*!  Trigger when TX FIFO contains 6 bytes */
    DL_I2C_TX_FIFO_LEVEL_BYTES_6 = I2C_MFIFOCTL_TXTRIG_LEVEL_6,
    /*!  Trigger when TX FIFO contains 7 bytes */
    DL_I2C_TX_FIFO_LEVEL_BYTES_7 = I2C_MFIFOCTL_TXTRIG_LEVEL_7,
} DL_I2C_TX_FIFO_LEVEL;

/** @enum DL_I2C_RX_FIFO_LEVEL */
typedef enum {
    /*!  Trigger when RX FIFO contains at least 1 byte */
    DL_I2C_RX_FIFO_LEVEL_BYTES_1 = I2C_MFIFOCTL_RXTRIG_LEVEL_1,
    /*!  Trigger when RX FIFO contains at least 2 bytes */
    DL_I2C_RX_FIFO_LEVEL_BYTES_2 = I2C_MFIFOCTL_RXTRIG_LEVEL_2,
    /*!  Trigger when RX FIFO contains at least 3 bytes */
    DL_I2C_RX_FIFO_LEVEL_BYTES_3 = I2C_MFIFOCTL_RXTRIG_LEVEL_3,
    /*!  Trigger when RX FIFO contains at least 4 bytes */
    DL_I2C_RX_FIFO_LEVEL_BYTES_4 = I2C_MFIFOCTL_RXTRIG_LEVEL_4,
    /*!  Trigger when RX FIFO contains at least 5 bytes */
    DL_I2C_RX_FIFO_LEVEL_BYTES_5 = I2C_MFIFOCTL_RXTRIG_LEVEL_5,
    /*!  Trigger when RX FIFO contains at least 6 bytes */
    DL_I2C_RX_FIFO_LEVEL_BYTES_6 = I2C_MFIFOCTL_RXTRIG_LEVEL_6,
    /*!  Trigger when RX FIFO contains at least 7 bytes */
    DL_I2C_RX_FIFO_LEVEL_BYTES_7 = I2C_MFIFOCTL_RXTRIG_LEVEL_7,
    /*!  Trigger when RX FIFO contains at least 8 bytes */
    DL_I2C_RX_FIFO_LEVEL_BYTES_8 = I2C_MFIFOCTL_RXTRIG_LEVEL_8,
} DL_I2C_RX_FIFO_LEVEL;

/** @enum DL_I2C_TARGET_RESPONSE_OVERRIDE_VALUE */
typedef enum {
    /*!  Target manual ACK for valid data or command.  */
    DL_I2C_TARGET_RESPONSE_OVERRIDE_VALUE_ACK = I2C_SACKCTL_ACKOVAL_DISABLE,
    /*!  Target manual NACK for invalid data or command.  */
    DL_I2C_TARGET_RESPONSE_OVERRIDE_VALUE_NACK = I2C_SACKCTL_ACKOVAL_ENABLE,
} DL_I2C_TARGET_RESPONSE_OVERRIDE_VALUE;

/*! @enum DL_I2C_IIDX */
typedef enum {
    /*! Interrupt index for I2C if no interrupt is pending */
    DL_I2C_IIDX_NO_INT = I2C_CPU_INT_IIDX_STAT_NO_INTR,
    /*! Interrupt index for I2C Controller Receive Transaction completed */
    DL_I2C_IIDX_CONTROLLER_RX_DONE = I2C_CPU_INT_IIDX_STAT_MRXDONEFG,
    /*! Interrupt index for Controller Transmit Transaction completed */
    DL_I2C_IIDX_CONTROLLER_TX_DONE = I2C_CPU_INT_IIDX_STAT_MTXDONEFG,
    /*! Interrupt index for I2C Controller Receive FIFO Trigger */
    DL_I2C_IIDX_CONTROLLER_RXFIFO_TRIGGER = I2C_CPU_INT_IIDX_STAT_MRXFIFOTRG,
    /*! Interrupt index for I2C Controller Transmit FIFO Trigger */
    DL_I2C_IIDX_CONTROLLER_TXFIFO_TRIGGER = I2C_CPU_INT_IIDX_STAT_MTXFIFOTRG,
    /*! Interrupt index for I2C Controller Receive when FIFO is full */
    DL_I2C_IIDX_CONTROLLER_RXFIFO_FULL = I2C_CPU_INT_IIDX_STAT_MRXFIFOFULL,
    /*! Interrupt index for I2C Controller when Transmit FIFO is empty */
    DL_I2C_IIDX_CONTROLLER_TXFIFO_EMPTY = I2C_CPU_INT_IIDX_STAT_MTX_EMPTY,
    /*! Interrupt index for Address/Data NACK */
    DL_I2C_IIDX_CONTROLLER_NACK = I2C_CPU_INT_IIDX_STAT_MNACKFG,
    /*! Interrupt index for I2C controller START Detection */
    DL_I2C_IIDX_CONTROLLER_START = I2C_CPU_INT_IIDX_STAT_MSTARTFG,
    /*! Interrupt index for I2C controller STOP Detection */
    DL_I2C_IIDX_CONTROLLER_STOP = I2C_CPU_INT_IIDX_STAT_MSTOPFG,
    /*! Interrupt index for I2C controller Arbitration Lost */
    DL_I2C_IIDX_CONTROLLER_ARBITRATION_LOST = I2C_CPU_INT_IIDX_STAT_MARBLOSTFG,
    /*! Interrupt index for I2C controller Event 1 DMA Done */
    DL_I2C_IIDX_CONTROLLER_EVENT1_DMA_DONE =
        I2C_CPU_INT_IIDX_STAT_MDMA_DONE_TX,
    /*! Interrupt index for I2C controller Event 2 DMA Done */
    DL_I2C_IIDX_CONTROLLER_EVENT2_DMA_DONE =
        I2C_CPU_INT_IIDX_STAT_MDMA_DONE_RX,

    /*! Interrupt index for I2C controller SMBus/PMBus PEC Receive Error Event */
    DL_I2C_IIDX_CONTROLLER_PEC_RX_ERROR = I2C_CPU_INT_IIDX_STAT_MPEC_RX_ERR,
    /*! Interrupt index for I2C Timeout A Event */
    DL_I2C_IIDX_TIMEOUT_A = I2C_CPU_INT_IIDX_STAT_TIMEOUTA,
    /*! Interrupt index for I2C Timeout B Event */
    DL_I2C_IIDX_TIMEOUT_B = I2C_CPU_INT_IIDX_STAT_TIMEOUTB,

    /*! Interrupt index for I2C Target Receive Data */
    DL_I2C_IIDX_TARGET_RX_DONE = I2C_CPU_INT_IIDX_STAT_SRXDONEFG,
    /*! Interrupt index for I2C Target Transmit Transaction completed */
    DL_I2C_IIDX_TARGET_TX_DONE = I2C_CPU_INT_IIDX_STAT_STXDONEFG,
    /*! Interrupt index for I2C Target Receive FIFO Trigger */
    DL_I2C_IIDX_TARGET_RXFIFO_TRIGGER = I2C_CPU_INT_IIDX_STAT_SRXFIFOTRG,
    /*! Interrupt index for I2C Target Transmit FIFO Trigger */
    DL_I2C_IIDX_TARGET_TXFIFO_TRIGGER = I2C_CPU_INT_IIDX_STAT_STXFIFOTRG,
    /*! Interrupt index for I2C Target RX FIFO full */
    DL_I2C_IIDX_TARGET_RXFIFO_FULL = I2C_CPU_INT_IIDX_STAT_SRXFIFOFULL,
    /*! Interrupt index for I2C Target TX FIFO empty.
     * All data in Transmit FIFO shifted out and transmit goes into idle mode. */
    DL_I2C_IIDX_TARGET_TXFIFO_EMPTY = I2C_CPU_INT_IIDX_STAT_STXEMPTY,
    /*! Interrupt index for I2C Target Start Condition detected */
    DL_I2C_IIDX_TARGET_START = I2C_CPU_INT_IIDX_STAT_SSTARTFG,
    /*! Interrupt index for I2C Target Stop Condition detected */
    DL_I2C_IIDX_TARGET_STOP = I2C_CPU_INT_IIDX_STAT_SSTOPFG,
    /*! Interrupt index for I2C General Call */
    DL_I2C_IIDX_TARGET_GENERAL_CALL = I2C_CPU_INT_IIDX_STAT_SGENCALL,
    /*! Interrupt index for I2C Target Event 1 DMA Done */
    DL_I2C_IIDX_TARGET_EVENT1_DMA_DONE = I2C_CPU_INT_IIDX_STAT_SDMA_DONE_TX,
    /*! Interrupt index for I2C Target Event 2 DMA Done */
    DL_I2C_IIDX_TARGET_EVENT2_DMA_DONE = I2C_CPU_INT_IIDX_STAT_SDMA_DONE_RX,

    /*! Interrupt index for I2C Target SMBus/PMBus PEC Receive Error Event */
    DL_I2C_IIDX_TARGET_PEC_RX_ERROR = I2C_CPU_INT_IIDX_STAT_SPEC_RX_ERR,
    /*! Interrupt index for I2C Target TX FIFO underflow event */
    DL_I2C_IIDX_TARGET_TXFIFO_UNDERFLOW = I2C_CPU_INT_IIDX_STAT_STX_UNFL,
    /*! Interrupt index for I2C Target RX FIFO overflow event */
    DL_I2C_IIDX_TARGET_RXFIFO_OVERFLOW = I2C_CPU_INT_IIDX_STAT_SRX_OVFL,
    /*! Interrupt index for I2C Target arbitration lost event */
    DL_I2C_IIDX_TARGET_ARBITRATION_LOST = I2C_CPU_INT_IIDX_STAT_SARBLOST,
    /*! Interrupt index for I2C interrupt overflow event */
    DL_I2C_IIDX_INTERRUPT_OVERFLOW = I2C_CPU_INT_IIDX_STAT_INTR_OVFL,

} DL_I2C_IIDX;

/**
 * @brief  Configuration struct for @ref DL_I2C_setClockConfig.
 */
typedef struct {
    /*! I2C module clock source. One of @ref DL_I2C_CLOCK */
    DL_I2C_CLOCK clockSel;
    /*! I2C clock divider selection. One of @ref DL_I2C_CLOCK_DIVIDE */
    DL_I2C_CLOCK_DIVIDE divideRatio;
} DL_I2C_ClockConfig;

/**
 *  @brief      Configure I2C source clock
 *
 *  @param[in]  i2c    Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  config  Pointer to the clock configuration struct
 *                       @ref DL_I2C_ClockConfig.
 */
void DL_I2C_setClockConfig(I2C_Regs *i2c, DL_I2C_ClockConfig *config);

/**
 *  @brief      Get I2C source clock configuration
 *
 *  @param[in]  i2c    Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  config  Pointer to the clock configuration struct
 *                      @ref DL_I2C_ClockConfig.
 */
void DL_I2C_getClockConfig(I2C_Regs *i2c, DL_I2C_ClockConfig *config);

/**
 *  @brief      Fills the controller TX FIFO with data
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  buffer  Pointer to buffer of bytes
 *  @param[in]  count   Number of bytes to fill controller TX FIFO from buffer
 *
 *  @return     Number of bytes that were successfully written
 */
uint16_t DL_I2C_fillControllerTXFIFO(
    I2C_Regs *i2c, uint8_t *buffer, uint16_t count);

/**
 *  @brief      Flushes/removes all elements in the controller TX FIFO
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
void DL_I2C_flushControllerTXFIFO(I2C_Regs *i2c);

/**
 *  @brief      Flushes/removes all elements in the controller RX FIFO
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
void DL_I2C_flushControllerRXFIFO(I2C_Regs *i2c);

/**
 *  @brief      Checks if controller TX FIFO is full
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If controller TX FIFO is full
 *
 *  @retval     true if controller TX FIFO is full
 *  @retval     false if controller TX FIFO is not full
 */
__STATIC_INLINE bool DL_I2C_isControllerTXFIFOFull(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MFIFOSR & I2C_MFIFOSR_TXFIFOCNT_MASK) ==
            I2C_MFIFOSR_TXFIFOCNT_MINIMUM);
}

/**
 *  @brief      Checks if controller TX FIFO is empty
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If controller TX FIFO is empty
 *
 *  @retval     true if controller TX FIFO is empty
 *  @retval     false if controller TX FIFO is not empty
 */
__STATIC_INLINE bool DL_I2C_isControllerTXFIFOEmpty(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MFIFOSR & I2C_MFIFOSR_TXFIFOCNT_MASK) ==
            I2C_MFIFOSR_TXFIFOCNT_MAXIMUM);
}

/**
 *  @brief      Checks if controller RX FIFO is empty
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If controller RX FIFO is empty
 *
 *  @retval     true if controller RX FIFO is empty
 *  @retval     false if controller RX FIFO is not empty
 */
__STATIC_INLINE bool DL_I2C_isControllerRXFIFOEmpty(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MFIFOSR & I2C_MFIFOSR_RXFIFOCNT_MASK) ==
            I2C_MFIFOSR_RXFIFOCNT_MINIMUM);
}

/**
 *  @brief      Reset transfers from from I2C controller
 *
 *  Resets transfer register to initialize I2C
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_resetControllerTransfer(I2C_Regs *i2c)
{
    // Resets all Controller functionality
    i2c->MASTER.MCTR = 0x00;
}

/**
 *  @brief      Sets up a transfer from I2C controller
 *
 *  Set target address, transfer direction, burst length, START+STOP generation.
 *  @note   Reading/writing data must be done separately.
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *  @param[in]  targetAddr  Target address [0x00, 0x3FF]
 *  @param[in]  direction   One of @ref DL_I2C_CONTROLLER_DIRECTION
 *  @param[in]  length      Intended burst length in number of bytes
 */
__STATIC_INLINE void DL_I2C_startControllerTransfer(I2C_Regs *i2c,
    uint32_t targetAddr, DL_I2C_CONTROLLER_DIRECTION direction,
    uint16_t length)
{
    // Specify target address and read/write mode
    DL_Common_updateReg(&i2c->MASTER.MSA,
        ((targetAddr << I2C_MSA_SADDR_OFS) | (uint32_t) direction),
        (I2C_MSA_SADDR_MASK | I2C_MSA_DIR_MASK));

    // STOP bit is generated after burst length number of bytes transferred
    DL_Common_updateReg(&i2c->MASTER.MCTR,
        (((uint32_t) length << I2C_MCTR_MBLEN_OFS) | I2C_MCTR_BURSTRUN_ENABLE |
            I2C_MCTR_START_ENABLE | I2C_MCTR_STOP_ENABLE),
        (I2C_MCTR_MBLEN_MASK | I2C_MCTR_BURSTRUN_MASK | I2C_MCTR_START_MASK |
            I2C_MCTR_STOP_MASK));
}

/**
 *  @brief      Sets up a transfer from I2C controller with control of START,
 *  STOP and ACK
 *
 *  @note   Reading/writing data must be done separately.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  targetAddr  7-bit target address [0x00, 0x7f]
 *  @param[in]  direction   One of @ref DL_I2C_CONTROLLER_DIRECTION
 *  @param[in]  length      Intended burst length in number of bytes
 *  @param[in]  start       One of @ref DL_I2C_CONTROLLER_START
 *  @param[in]  stop        One of @ref DL_I2C_CONTROLLER_STOP
 *  @param[in]  ack         One of @ref DL_I2C_CONTROLLER_ACK
 */
__STATIC_INLINE void DL_I2C_startControllerTransferAdvanced(I2C_Regs *i2c,
    uint32_t targetAddr, DL_I2C_CONTROLLER_DIRECTION direction,
    uint16_t length, DL_I2C_CONTROLLER_START start,
    DL_I2C_CONTROLLER_STOP stop, DL_I2C_CONTROLLER_ACK ack)
{
    // Specify target address and read/write mode
    DL_Common_updateReg(&i2c->MASTER.MSA,
        ((targetAddr << I2C_MSA_SADDR_OFS) | (uint32_t) direction),
        (I2C_MSA_SADDR_MASK | I2C_MSA_DIR_MASK));

    DL_Common_updateReg(&i2c->MASTER.MCTR,
        (((uint32_t) length << I2C_MCTR_MBLEN_OFS) | I2C_MCTR_BURSTRUN_ENABLE |
            (uint32_t) start | (uint32_t) stop | (uint32_t) ack),
        (I2C_MCTR_MBLEN_MASK | I2C_MCTR_BURSTRUN_MASK | I2C_MCTR_START_MASK |
            I2C_MCTR_STOP_MASK | I2C_MCTR_ACK_MASK));
}

/**
 *  @brief      Checks if target TX FIFO is full
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target TX FIFO is full
 *
 *  @retval     true if target TX FIFO is full
 *  @retval     false if target TX FIFO is not full
 */
__STATIC_INLINE bool DL_I2C_isTargetTXFIFOFull(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SFIFOSR & I2C_SFIFOSR_TXFIFOCNT_MASK) ==
            I2C_SFIFOSR_TXFIFOCNT_MINIMUM);
}

/**
 *  @brief      Checks if target TX FIFO is empty
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target TX FIFO is empty
 *
 *  @retval     true if target TX FIFO is empty
 *  @retval     false if target TX FIFO is not empty
 */
__STATIC_INLINE bool DL_I2C_isTargetTXFIFOEmpty(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SFIFOSR & I2C_SFIFOSR_TXFIFOCNT_MASK) ==
            DL_I2C_TX_FIFO_COUNT_MAXIMUM);
}

/**
 *  @brief      Checks if target RX FIFO is empty
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target RX FIFO is empty
 *
 *  @retval     true if target RX FIFO is empty
 *  @retval     false if target RX FIFO is not empty
 */
__STATIC_INLINE bool DL_I2C_isTargetRXFIFOEmpty(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SFIFOSR & I2C_SFIFOSR_RXFIFOCNT_MASK) ==
            I2C_SFIFOSR_RXFIFOCNT_MINIMUM);
}

/**
 *  @brief      Fills the target TX FIFO with data
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  buffer  Pointer to buffer of bytes
 *  @param[in]  count   Number of bytes to fill target TX FIFO from buffer
 *
 *  @return     Number of bytes that were successfully written
 */
uint8_t DL_I2C_fillTargetTXFIFO(I2C_Regs *i2c, uint8_t *buffer, uint8_t count);

/**
 *  @brief      Flushes/removes all elements in the target TX FIFO
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
void DL_I2C_flushTargetTXFIFO(I2C_Regs *i2c);

/**
 *  @brief      Flushes/removes all elements in the target RX FIFO
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
void DL_I2C_flushTargetRXFIFO(I2C_Regs *i2c);

/**
 *  @brief  Transmit target data, waiting until transmit request
 *
 *  @note   Setting own target addresses and enabling target should be done
 *  separately.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  data    Byte of data to transmit
 */
void DL_I2C_transmitTargetDataBlocking(I2C_Regs *i2c, uint8_t data);

/**
 *  @brief  Transmit target data
 *
 *  @note   Setting own target addresses and enabling target should be done
 *  separately.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  data    Byte of data to transmit
 *
 *  @return Whether data could be transmitted or not
 *  @retval true if data could be transmitted
 *  @retval false if data could not be transmitted
 */
bool DL_I2C_transmitTargetDataCheck(I2C_Regs *i2c, uint8_t data);

/**
 *  @brief  Receive target data, waiting until receive request
 *
 *  @note   Setting own target addresses and enabling target should be done
 *  separately.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return Data received from target
 */
uint8_t DL_I2C_receiveTargetDataBlocking(I2C_Regs *i2c);

/**
 *  @brief  Receive target data
 *
 *  @note   Setting own target addresses and enabling target should be done
 *  separately.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  buffer  Pointer to where byte of received data should be stored
 *
 *  @return Whether data could be received or not
 *  @retval true if data could be received
 *  @retval false if data could not be received
 */
bool DL_I2C_receiveTargetDataCheck(I2C_Regs *i2c, uint8_t *buffer);

/**
 * @brief Enables power on I2C module
 *
 * @param i2c        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enablePower(I2C_Regs *i2c)
{
    i2c->GPRCM.PWREN = (I2C_PWREN_KEY_UNLOCK_W | I2C_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Disables power on i2c module
 *
 * @param i2c        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disablePower(I2C_Regs *i2c)
{
    i2c->GPRCM.PWREN = (I2C_PWREN_KEY_UNLOCK_W | I2C_PWREN_ENABLE_DISABLE);
}

/**
 * @brief Returns if  power on i2c module
 *
 * @param i2c        Pointer to the register overlay for the peripheral
 *
 * @return true if power is enabled
 * @return false if power is disabled
 */
__STATIC_INLINE bool DL_I2C_isPowerEnabled(I2C_Regs *i2c)
{
    return (
        (i2c->GPRCM.PWREN & I2C_PWREN_ENABLE_MASK) == I2C_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Resets i2c peripheral
 *
 * @param i2c        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_reset(I2C_Regs *i2c)
{
    i2c->GPRCM.RSTCTL =
        (I2C_RSTCTL_KEY_UNLOCK_W | I2C_RSTCTL_RESETSTKYCLR_CLR |
            I2C_RSTCTL_RESETASSERT_ASSERT);
}

/**
 * @brief Returns if i2c peripheral was reset
 *
 * @param i2c        Pointer to the register overlay for the peripheral
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_I2C_isReset(I2C_Regs *i2c)
{
    return ((i2c->GPRCM.STAT & I2C_STAT_RESETSTKY_MASK) ==
            I2C_STAT_RESETSTKY_RESET);
}

/**
 * @brief Set Clock Source
 *
 *  Clock sources depend on device and clock should be enabled
 *
 *  @param[in]  i2c            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  clockSource    One of @ref DL_I2C_CLOCK.
 *
 */
__STATIC_INLINE void DL_I2C_selectClockSource(
    I2C_Regs *i2c, DL_I2C_CLOCK clockSource)
{
    DL_Common_updateReg(&i2c->CLKSEL, (uint32_t) clockSource,
        I2C_CLKSEL_BUSCLK_SEL_MASK | I2C_CLKSEL_MFCLK_SEL_MASK);
}

/**
 * @brief Set Clock Divider
 *
 *  @param[in]  i2c            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  clockDivider   One of @ref DL_I2C_CLOCK_DIVIDE.
 *
 */
__STATIC_INLINE void DL_I2C_selectClockDivider(
    I2C_Regs *i2c, DL_I2C_CLOCK_DIVIDE clockDivider)
{
    DL_Common_updateReg(
        &i2c->CLKDIV, (uint32_t) clockDivider, I2C_CLKDIV_RATIO_MASK);
}

/**
 *  @brief      Get Analog Glitch Suppression Pulse Width
 *
 *  Pulse width for the analog glitch suppression on SCL/SDA lines.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     Analog glitch suppression pulse width
 *
 *  @retval     One of @ref DL_I2C_ANALOG_GLITCH_FILTER_WIDTH.
 */
__STATIC_INLINE DL_I2C_ANALOG_GLITCH_FILTER_WIDTH
DL_I2C_getAnalogGlitchFilterPulseWidth(I2C_Regs *i2c)
{
    uint32_t filterWidth = i2c->GFCTL & I2C_GFCTL_AGFSEL_MASK;

    return (DL_I2C_ANALOG_GLITCH_FILTER_WIDTH)(filterWidth);
}

/**
 *  @brief      Set Analog Glitch Suppression Pulse Width
 *
 *  Pulse width for the analog glitch suppression on SCL/SDA lines.
 *
 *  @param[in]  i2c            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  filterWidth    One of @ref DL_I2C_ANALOG_GLITCH_FILTER_WIDTH.
 */
__STATIC_INLINE void DL_I2C_setAnalogGlitchFilterPulseWidth(
    I2C_Regs *i2c, DL_I2C_ANALOG_GLITCH_FILTER_WIDTH filterWidth)
{
    DL_Common_updateReg(
        &i2c->GFCTL, (uint32_t) filterWidth, I2C_GFCTL_AGFSEL_MASK);
}

/**
 *  @brief      Get Digital Glitch Suppression Pulse Width
 *
 *  Pulse width for the digital glitch suppression on SCL/SDA lines.
 *  Values are in terms of functional clock ticks.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     Digital glitch suppression pulse width
 *
 *  @retval     One of @ref DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH.
 */
__STATIC_INLINE DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH
DL_I2C_getDigitalGlitchFilterPulseWidth(I2C_Regs *i2c)
{
    uint32_t filterWidth = i2c->GFCTL & I2C_GFCTL_DGFSEL_MASK;

    return (DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH)(filterWidth);
}

/**
 *  @brief      Set Digital Glitch Suppression Pulse Width
 *
 *  Pulse width for the digital glitch suppression on SCL/SDA lines.
 *  Values are in terms of functional clock ticks.
 *
 *  @param[in]  i2c             Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  filterWidth     One of @ref DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH.
 */
__STATIC_INLINE void DL_I2C_setDigitalGlitchFilterPulseWidth(
    I2C_Regs *i2c, DL_I2C_DIGITAL_GLITCH_FILTER_WIDTH filterWidth)
{
    DL_Common_updateReg(
        &i2c->GFCTL, (uint32_t) filterWidth, I2C_GFCTL_DGFSEL_MASK);
}

/**
 *  @brief      Disable Analog Glitch Suppression
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableAnalogGlitchFilter(I2C_Regs *i2c)
{
    i2c->GFCTL &= ~(I2C_GFCTL_AGFEN_MASK);
}

/**
 *  @brief      Checks if analog glitch suppression is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If analog glitch suppression is enabled
 *
 *  @retval     true if analog glitch suppression is enabled
 *  @retval     false if analog glitch suppression is disabled
 */
__STATIC_INLINE bool DL_I2C_isAnalogGlitchFilterEnabled(I2C_Regs *i2c)
{
    return ((i2c->GFCTL & I2C_GFCTL_AGFEN_MASK) == I2C_GFCTL_AGFEN_ENABLE);
}

/**
 *  @brief      Enable Analog Glitch Suppression
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableAnalogGlitchFilter(I2C_Regs *i2c)
{
    i2c->GFCTL |= I2C_GFCTL_AGFEN_ENABLE;
}

/**
 *  @brief      Get direction of next controller operation
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     Direction of next controller operation
 *
 *  @retval     One of @ref DL_I2C_CONTROLLER_DIRECTION
 */
__STATIC_INLINE DL_I2C_CONTROLLER_DIRECTION DL_I2C_getControllerDirection(
    I2C_Regs *i2c)
{
    uint32_t direction = i2c->MASTER.MSA & I2C_MSA_DIR_MASK;

    return (DL_I2C_CONTROLLER_DIRECTION)(direction);
}

/**
 *  @brief      Set direction of next controller operation
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @param[in]  direction   Direction of next controller operation.
 *                          One of @ref DL_I2C_CONTROLLER_DIRECTION.
 */
__STATIC_INLINE void DL_I2C_setControllerDirection(
    I2C_Regs *i2c, DL_I2C_CONTROLLER_DIRECTION direction)
{
    DL_Common_updateReg(
        &i2c->MASTER.MSA, (uint32_t) direction, I2C_MSA_DIR_MASK);
}

/**
 *  @brief      Get the address of the target being addressed when configured
 *              as an I2C controller
 *
 *  Specifies bits A9 through A0 of the target address.
 *  In 7-bit addressing mode as selected by @ref DL_I2C_setTargetAddressingMode,
 *  the top 3 bits are don't care.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     The target address
 *
 *  @retval     [0x00, 0x07FE]
 *
 *  @sa         DL_I2C_setTargetAddressingMode
 */
__STATIC_INLINE uint32_t DL_I2C_getTargetAddress(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MSA & I2C_MSA_SADDR_MASK) >> I2C_MSA_SADDR_OFS);
}

/**
 *  @brief      Set the address of the target being addressed when configured
 *              as an I2C controller
 *
 *  Specifies bits A9 through A0 of the target address.
 *  In 7-bit addressing mode as selected by @ref DL_I2C_setTargetAddressingMode,
 *  the top 3 bits are don't care.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  targetAddress    Target address to set [0x00, 0x07FE]
 *
 *  @sa         DL_I2C_setTargetAddressingMode
 */
__STATIC_INLINE void DL_I2C_setTargetAddress(
    I2C_Regs *i2c, uint32_t targetAddress)
{
    DL_Common_updateReg(&i2c->MASTER.MSA, (targetAddress << I2C_MSA_SADDR_OFS),
        I2C_MSA_SADDR_MASK);
}

/**
 *  @brief      Get controller addressing mode
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     Addressing mode the controller is set to
 *
 *  @retval     One of @ref DL_I2C_CONTROLLER_ADDRESSING_MODE
 *
 */
__STATIC_INLINE DL_I2C_CONTROLLER_ADDRESSING_MODE
DL_I2C_getControllerAddressingMode(I2C_Regs *i2c)
{
    uint32_t mode = i2c->MASTER.MSA & I2C_MSA_MMODE_MASK;

    return (DL_I2C_CONTROLLER_ADDRESSING_MODE)(mode);
}

/**
 *  @brief      Set controller addressing mode between 7-bit and 10-bit mode
 *
 *  Selects the addressing mode between 7-bit and 10-bit mode to be used when
 *  device is configured as a controller
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  mode    Addressing mode to set the target to.
 *                      One of @ref DL_I2C_CONTROLLER_ADDRESSING_MODE.
 */
__STATIC_INLINE void DL_I2C_setControllerAddressingMode(
    I2C_Regs *i2c, DL_I2C_CONTROLLER_ADDRESSING_MODE mode)
{
    DL_Common_updateReg(&i2c->MASTER.MSA, (uint32_t) mode, I2C_MSA_MMODE_MASK);
}

/**
 *  @brief      Disable controller ACK override
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableControllerACKOverride(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR &= ~(I2C_MCTR_MACKOEN_MASK);
}

/**
 *  @brief      Checks if controller ACK override is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If controller ACK override is enabled
 *
 *  @retval     true if controller ACK override is enabled
 *  @retval     false if controller ACK override is disabled
 */
__STATIC_INLINE bool DL_I2C_isControllerACKOverrideEnabled(I2C_Regs *i2c)
{
    return (
        (i2c->MASTER.MCTR & I2C_MCTR_MACKOEN_MASK) == I2C_MCTR_MACKOEN_ENABLE);
}

/**
 *  @brief      Enable controller ACK override
 *
 *  When enabled and the controller is receiving data and the number of bytes
 *  indicated in MCTR.MBLEN have been received, the state machine will generate
 *  an RXDONE interrupt and wait at the start of the ACK for FW to indicate if
 *  an ACK or NACK should be sent. The ACK or NACK is selected by writing the
 *  MCTR register and setting ACK accordingly. The other fields in this register
 *  can also be written at this time to continue on with the transaction. If a
 *  NACK is sent the state machine will automatically send a Stop.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 * @sa          DL_I2C_setTransactionLength
 */
__STATIC_INLINE void DL_I2C_enableControllerACKOverride(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR |= I2C_MCTR_MACKOEN_ENABLE;
}

/**
 *  @brief      Disable controller read on TX empty
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableControllerReadOnTXEmpty(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR &= ~(I2C_MCTR_RD_ON_TXEMPTY_MASK);
}

/**
 *  @brief      Checks if controller read on TX empty is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If controller read on TX empty is enabled
 *
 *  @retval     true if controller read on TX empty is enabled
 *  @retval     false if controller read on TX empty is disabled
 */
__STATIC_INLINE bool DL_I2C_isControllerReadOnTXEmptyEnabled(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MCTR & I2C_MCTR_RD_ON_TXEMPTY_MASK) ==
            I2C_MCTR_RD_ON_TXEMPTY_ENABLE);
}

/**
 *  @brief      Enable controller read on TX empty
 *
 *  When enabled, the controller will transmit all bytes from the TX FIFO
 *  before continuing with the programmed Burst Run Read. If the DIR is not
 *  set to Read in the MSA then this bit is ignored. The Start must be set in
 *  the MCTR for proper I2C protocol. The controller will first send the Start
 *  Condition, I2C Address with R/W bit set to write, before sending the bytes
 *  in the TX FIFO. When the TX FIFO is empty, the I2C transaction will
 *  continue as programmed in MTCR and MSA without sending a Stop Condition.
 *  This is intended to be used to perform simple I2C command based reads
 *  transition that will complete after initiating them without having to get
 *  an interrupt to turn the bus around.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_I2C_enableControllerReadOnTXEmpty(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR |= I2C_MCTR_RD_ON_TXEMPTY_ENABLE;
}

/**
 *  @brief      Get the SMBus/PMBus Packet Error Checking (PEC) count value
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     The value the PEC count is set to
 *
 *  @retval     Value between [0x0, 0x01FF]
 */
__STATIC_INLINE uint32_t DL_I2C_getControllerPECCountValue(I2C_Regs *i2c)
{
    return (i2c->MASTER.CONTROLLER_I2CPECCTL &
            I2C_CONTROLLER_I2CPECCTL_PECCNT_MASK);
}

/**
 *  @brief      Set the SMBus/PMBus Packet Error Checking (PEC) count value
 *
 *  When this field is non zero, the number of I2C data bytes are counted.
 *  Refer to the device TRM for more details.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  count   The value to set the PEC count to.
 *                      Value between [0x0, 0x01FF]
 */
__STATIC_INLINE void DL_I2C_setControllerPECCountValue(
    I2C_Regs *i2c, uint32_t count)
{
    DL_Common_updateReg(&i2c->MASTER.CONTROLLER_I2CPECCTL, count,
        I2C_CONTROLLER_I2CPECCTL_PECCNT_MASK);
}

/**
 *  @brief      Disable controller SMBus/PMBus Packet Error Checking (PEC)
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableControllerPEC(I2C_Regs *i2c)
{
    i2c->MASTER.CONTROLLER_I2CPECCTL &= ~(I2C_CONTROLLER_I2CPECCTL_PECEN_MASK);
}

/**
 *  @brief      Checks if controller SMBus/PMBus Packet Error Checking (PEC)
 *              is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If controller PEC is enabled
 *
 *  @retval     true if controller PEC is enabled
 *  @retval     false if controller PEC is disabled
 */
__STATIC_INLINE bool DL_I2C_isControllerPECEnabled(I2C_Regs *i2c)
{
    return ((i2c->MASTER.CONTROLLER_I2CPECCTL &
                I2C_CONTROLLER_I2CPECCTL_PECEN_MASK) ==
            I2C_CONTROLLER_I2CPECCTL_PECEN_ENABLE);
}

/**
 *  @brief      Enable controller SMBus/PMBus Packet Error Checking (PEC)
 *
 *  When enabled, the PEC is calculated on all bits accept the Start, Stop, ACK
 *  and NACK. The PEC LSFR and the Byte Counter is set to 0 when the State
 *  Machine is in the IDLE state, which occurs following a Stop or when a
 *  timeout occurs. The Counter is also set to 0 after the PEC byte is sent or
 *  received. Note that the NACK is automatically sent following a PEC byte
 *  that results in a PEC error.
 *  The PEC Polynomial is x^8 + x^2 + x^1 + 1.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_I2C_enableControllerPEC(I2C_Regs *i2c)
{
    i2c->MASTER.CONTROLLER_I2CPECCTL |= I2C_CONTROLLER_I2CPECCTL_PECEN_ENABLE;
}

/**
 *  @brief      Get the current SMBus/PMBus PEC byte count of the controller
 *              state machine
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     The current PEC byte count of the controller state machine
 *
 *  @retval     Value between [0x0, 0x01FF]
 */
__STATIC_INLINE uint32_t DL_I2C_getControllerCurrentPECCount(I2C_Regs *i2c)
{
    return (
        i2c->MASTER.CONTROLLER_PECSR & I2C_CONTROLLER_PECSR_PECSTS_CHECK_MASK);
}

/**
 *  @brief      If controller SMBus/PMBus PEC was checked in last transaction
 *
 *  The status of if the controller PEC was checked in the transaction that
 *  occurred before the last Stop. Latched on Stop.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     Status of controller PEC checked in last transaction
 *
 *  @retval     One of @ref DL_I2C_CONTROLLER_PEC_STATUS
 */
__STATIC_INLINE DL_I2C_CONTROLLER_PEC_STATUS
DL_I2C_getControllerPECCheckedStatus(I2C_Regs *i2c)
{
    uint32_t status =
        i2c->MASTER.CONTROLLER_PECSR & I2C_CONTROLLER_PECSR_PECSTS_CHECK_MASK;

    return (DL_I2C_CONTROLLER_PEC_STATUS)(status);
}

/**
 *  @brief      Get the status of the controller SMBus/PMBus PEC Check error
 *
 *  The status of if a PEC check error occurred in the transaction that
 *  occurred before the last Stop. Latched on Stop.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     Status of controller PEC check error
 *
 *  @retval     One of @ref DL_I2C_CONTROLLER_PEC_CHECK_ERROR
 */
__STATIC_INLINE DL_I2C_CONTROLLER_PEC_CHECK_ERROR
DL_I2C_getControllerPECCheckError(I2C_Regs *i2c)
{
    uint32_t error =
        i2c->MASTER.CONTROLLER_PECSR & I2C_CONTROLLER_PECSR_PECSTS_ERROR_MASK;

    return (DL_I2C_CONTROLLER_PEC_CHECK_ERROR)(error);
}

/**
 *  @brief      Disable I2C controller burst mode
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableControllerBurst(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR &= ~(I2C_MCTR_BURSTRUN_MASK);
}

/**
 *  @brief      Checks if I2C controller burst mode is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If I2C controller burst mode is enabled
 *
 *  @retval     true if I2C controller burst mode is enabled
 *  @retval     false if I2C controller burst mode is disabled
 */
__STATIC_INLINE bool DL_I2C_isControllerBurstEnabled(I2C_Regs *i2c)
{
    return ((i2c->GFCTL & I2C_MCTR_BURSTRUN_MASK) == I2C_MCTR_BURSTRUN_ENABLE);
}

/**
 *  @brief      Enable I2C controller burst mode
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableControllerBurst(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR |= I2C_MCTR_BURSTRUN_ENABLE;
}

/**
 *  @brief      Disable I2C START generation
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableStartCondition(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR &= ~(I2C_MCTR_START_MASK);
}

/**
 *  @brief      Checks if I2C START generation is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If I2C START generation is enabled
 *
 *  @retval     true if I2C START generation is enabled
 *  @retval     false if I2C START generation is disabled
 */
__STATIC_INLINE bool DL_I2C_isStartConditionEnabled(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MCTR & I2C_MCTR_START_MASK) == I2C_MCTR_START_ENABLE);
}

/**
 *  @brief      Enable I2C START generation
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableStartCondition(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR |= I2C_MCTR_START_ENABLE;
}

/**
 *  @brief      Disable I2C STOP generation
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableStopCondition(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR &= ~(I2C_MCTR_STOP_MASK);
}

/**
 *  @brief      Checks if I2C STOP generation is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If I2C STOP generation is enabled
 *
 *  @retval     true if I2C STOP generation is enabled
 *  @retval     false if I2C STOP generation is disabled
 */
__STATIC_INLINE bool DL_I2C_isStopConditionEnabled(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MCTR & I2C_MCTR_STOP_MASK) == I2C_MCTR_STOP_ENABLE);
}

/**
 *  @brief      Enable I2C STOP generation
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableStopCondition(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR |= I2C_MCTR_STOP_ENABLE;
}

/**
 *  @brief      Disable I2C controller data acknowledge (ACK or NACK)
 *
 *  When the I2C module operates in Controller receiver mode, the ACK bit can be
 *  cleared when no further data needs to be received from the target
 *  transmitter.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableControllerACK(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR &= ~(I2C_MCTR_ACK_MASK);
}

/**
 *  @brief      Checks if I2C controller data acknowledge (ACK or NACK) is
 *              enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If I2C controller data acknowledge is enabled
 *
 *  @retval     true if I2C controller data acknowledge is enabled
 *  @retval     false if I2C controller data acknowledge is disabled
 */
__STATIC_INLINE bool DL_I2C_isControllerACKEnabled(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MCTR & I2C_MCTR_ACK_MASK) == I2C_MCTR_ACK_ENABLE);
}

/**
 *  @brief      Enable I2C controller data acknowledge (ACK or NACK)
 *
 *  When the I2C module operates in Controller receiver mode, the ACK bit is
 *  normally set causing the I2C bus controller to transmit an acknowledge
 *  automatically after each byte.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableControllerACK(I2C_Regs *i2c)
{
    i2c->MASTER.MCTR |= I2C_MCTR_ACK_MASK;
}

/**
 *  @brief      Get transaction length in bytes
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     Length of I2C transaction in bytes
 *
 *  @retval     [0x000, 0xfff]
 */
__STATIC_INLINE uint32_t DL_I2C_getTransactionLength(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MCTR & I2C_MCTR_MBLEN_MASK) >> I2C_MCTR_MBLEN_OFS);
}

/**
 *  @brief      Set transaction length in bytes
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @param[in]  length      Length of I2C transaction in bytes [0x000, 0xfff]
 */
__STATIC_INLINE void DL_I2C_setTransactionLength(
    I2C_Regs *i2c, uint32_t length)
{
    DL_Common_updateReg(&i2c->MASTER.MCTR, (length << I2C_MCTR_MBLEN_OFS),
        I2C_MCTR_MBLEN_MASK);
}

/**
 *  @brief      Get status of I2C bus controller for controller
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @return     Status of I2C bus controller for controller
 *
 *  @retval     Bitwise OR of @ref DL_I2C_CONTROLLER_STATUS
 */
__STATIC_INLINE uint32_t DL_I2C_getControllerStatus(I2C_Regs *i2c)
{
    return (i2c->MASTER.MSR);
}

/**
 *  @brief      Get transaction count in bytes
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @return     Current 12-bit countdown value of the transaction
 *
 *  @retval     [0x000, 0xfff]
 */
__STATIC_INLINE uint16_t DL_I2C_getTransactionCount(I2C_Regs *i2c)
{
    return ((uint16_t)(
        (i2c->MASTER.MSR & I2C_MSR_MBCNT_MASK) >> I2C_MSR_MBCNT_OFS));
}

/**
 *  @brief      Get byte of data from I2C controller
 *
 *  If using FIFO, it is first byte from the RX FIFO.
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @return     Last received byte of data
 *
 *  @retval     [0x00, 0xff]
 */
__STATIC_INLINE uint8_t DL_I2C_receiveControllerData(I2C_Regs *i2c)
{
    return ((uint8_t)(i2c->MASTER.MRXDATA & I2C_MRXDATA_VALUE_MASK));
}

/**
 *  @brief      Set next byte to be transferred during the next transaction
 *
 *  Does not transmit data until @ref DL_I2C_startControllerTransfer
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  data    Data to be transferred during the next transaction.
 *                      [0x00, 0xff]
 */
__STATIC_INLINE void DL_I2C_transmitControllerData(I2C_Regs *i2c, uint8_t data)
{
    i2c->MASTER.MTXDATA = data;
}

/**
 *  @brief      Get timer period
 *  This field is used in the equation to configure SCL_PERIOD:
 *
 *  SCL_PERIOD = (1 + TPR) * (SCL_LP + SCL_HP) * INT_CLK_PRD
 *
 *  where:
 *  SCL_PRD is the SCL line period (I2C clock)
 *
 *  TPR is the Timer Period register value (range of 1 to 127)
 *
 *  SCL_LP is the SCL Low period (fixed at 6)
 *  SCL_HP is the SCL High period (fixed at 4)
 *
 *  CLK_PRD is the functional clock period in ns
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @return     Timer period
 *
 *  @retval     [0x00, 0x7f]
 */
__STATIC_INLINE uint8_t DL_I2C_getTimerPeriod(I2C_Regs *i2c)
{
    return ((uint8_t)(i2c->MASTER.MTPR & I2C_MTPR_TPR_MASK));
}

/**
 *  @brief      Set timer period
 *  This field is used in the equation to configure SCL_PERIOD:
 *
 *  SCL_PERIOD = (1 + TPR) * (SCL_LP + SCL_HP) * INT_CLK_PRD
 *
 *  where:
 *  SCL_PRD is the SCL line period (I2C clock)
 *
 *  TPR is the Timer Period register value (range of 1 to 127)
 *
 *  SCL_LP is the SCL Low period (fixed at 6)
 *  SCL_HP is the SCL High period (fixed at 4)
 *
 *  CLK_PRD is the functional clock period in ns
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  period  Timer period [0x00, 0x7f]
 */
__STATIC_INLINE void DL_I2C_setTimerPeriod(I2C_Regs *i2c, uint8_t period)
{
    i2c->MASTER.MTPR = period;
}

/**
 *  @brief      Disable loopback mode
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableLoopbackMode(I2C_Regs *i2c)
{
    i2c->MASTER.MCR &= ~(I2C_MCR_LPBK_MASK);
}

/**
 *  @brief      Checks if loopback mode is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If loopback mode is enabled
 *
 *  @retval     true if loopback mode is enabled
 *  @retval     false if loopback mode is disabled
 */
__STATIC_INLINE bool DL_I2C_isLoopbackModeEnabled(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MCR & I2C_MCR_LPBK_MASK) == I2C_MCR_LPBK_ENABLE);
}

/**
 *  @brief      Enable loopback mode
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableLoopbackMode(I2C_Regs *i2c)
{
    i2c->MASTER.MCR |= I2C_MCR_LPBK_ENABLE;
}

/**
 *  @brief      Disable multicontroller mode
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableMultiControllerMode(I2C_Regs *i2c)
{
    i2c->MASTER.MCR &= ~(I2C_MCR_MMST_MASK);
}

/**
 *  @brief      Checks if multicontroller mode is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If multicontroller mode is enabled
 *
 *  @retval     true if multicontroller mode is enabled
 *  @retval     false if multicontroller mode is disabled
 */
__STATIC_INLINE bool DL_I2C_isMultiControllerModeEnabled(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MCR & I2C_MCR_MMST_MASK) == I2C_MCR_MMST_ENABLE);
}

/**
 *  @brief      Enable multicontroller mode
 *
 *  In multicontroller mode, the SCL high time counts once the SCL line has been
 *  detected high. If this is not enabled, the high time counts as soon as the
 *  SCL line has been set high by the I2C controller
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableMultiControllerMode(I2C_Regs *i2c)
{
    i2c->MASTER.MCR |= I2C_MCR_MMST_ENABLE;
}

/**
 *  @brief      Disable controller
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableController(I2C_Regs *i2c)
{
    i2c->MASTER.MCR &= ~(I2C_MCR_ACTIVE_MASK);
}

/**
 *  @brief      Checks if controller is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If controller is enabled
 *
 *  @retval     true if controller is enabled
 *  @retval     false if controller is disabled
 */
__STATIC_INLINE bool DL_I2C_isControllerEnabled(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MCR & I2C_MCR_ACTIVE_MASK) == I2C_MCR_ACTIVE_ENABLE);
}

/**
 *  @brief      Enable controller
 *
 *  After controller has enabled, it should not be re-enabled unless it has been
 *  disabled or by a reset, otherwise transfer failures may occur.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableController(I2C_Regs *i2c)
{
    i2c->MASTER.MCR |= I2C_MCR_ACTIVE_ENABLE;
}

/**
 *  @brief      Disable controller clock stretching
 *
 *  Clock stretching can be disabled if no target on the bus supports clock
 *  stretching; however, it should be typically enabled to be compliant with
 *  I2C specification.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableControllerClockStretching(I2C_Regs *i2c)
{
    i2c->MASTER.MCR &= ~(I2C_MCR_CLKSTRETCH_MASK);
}

/**
 *  @brief      Checks if controller clock stretching is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If controller clock stretching is enabled
 *
 *  @retval     true if controller clock stretching is enabled
 *  @retval     false if controller clock stretching is disabled
 */
__STATIC_INLINE bool DL_I2C_isControllerClockStretchingEnabled(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MCR & I2C_MCR_CLKSTRETCH_MASK) ==
            I2C_MCR_CLKSTRETCH_ENABLE);
}

/**
 *  @brief      Enable controller clock stretching
 *
 *  Clock stretching can be disabled if no target on the bus supports clock
 *  stretching; however, it should be typically enabled to be compliant with I2C
 *  specification.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableControllerClockStretching(I2C_Regs *i2c)
{
    i2c->MASTER.MCR |= I2C_MCR_CLKSTRETCH_ENABLE;
}

/**
 *  @brief      Get SCL signal status
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @return     Status of SCL signal
 *
 *  @retval     One of @ref DL_I2C_CONTROLLER_SCL
 */
__STATIC_INLINE DL_I2C_CONTROLLER_SCL DL_I2C_getSCLStatus(I2C_Regs *i2c)
{
    uint32_t sclStatus = i2c->MASTER.MBMON & I2C_MBMON_SCL_MASK;

    return (DL_I2C_CONTROLLER_SCL)(sclStatus);
}

/**
 *  @brief      Get SDA signal status
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @return     Status of SDA signal
 *
 *  @retval     One of @ref DL_I2C_CONTROLLER_SDA
 */
__STATIC_INLINE DL_I2C_CONTROLLER_SDA DL_I2C_getSDAStatus(I2C_Regs *i2c)
{
    uint32_t sdaStatus = i2c->MASTER.MBMON & I2C_MBMON_SDA_MASK;

    return (DL_I2C_CONTROLLER_SDA)(sdaStatus);
}

/**
 *  @brief      Get controller TX FIFO threshold level
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @return     Indicates at what fill level in the TX FIFO a threshold will be
 *              generated
 *
 *  @retval     One of @ref DL_I2C_TX_FIFO_LEVEL
 */
__STATIC_INLINE DL_I2C_TX_FIFO_LEVEL DL_I2C_getControllerTXFIFOThreshold(
    I2C_Regs *i2c)
{
    uint32_t level = i2c->MASTER.MFIFOCTL & I2C_MFIFOCTL_TXTRIG_MASK;

    return (DL_I2C_TX_FIFO_LEVEL)(level);
}

/**
 *  @brief      Set controller TX FIFO threshold level
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  level   Indicates at what fill level in the TX FIFO a threshold
 *                      will be generated.
 *                      One of @ref DL_I2C_TX_FIFO_LEVEL.
 */
__STATIC_INLINE void DL_I2C_setControllerTXFIFOThreshold(
    I2C_Regs *i2c, DL_I2C_TX_FIFO_LEVEL level)
{
    DL_Common_updateReg(
        &i2c->MASTER.MFIFOCTL, (uint32_t) level, I2C_MFIFOCTL_TXTRIG_MASK);
}

/**
 *  @brief      Stop controller TX FIFO flush
 *
 *  Before stopping the flush, check if @ref DL_I2C_isControllerTXFIFOEmpty,
 *  indicating flush is complete.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_stopFlushControllerTXFIFO(I2C_Regs *i2c)
{
    i2c->MASTER.MFIFOCTL &= ~(I2C_MFIFOCTL_TXFLUSH_MASK);
}

/**
 *  @brief      Start controller TX FIFO flush
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_startFlushControllerTXFIFO(I2C_Regs *i2c)
{
    i2c->MASTER.MFIFOCTL |= I2C_MFIFOCTL_TXFLUSH_MASK;
}

/**
 *  @brief      Get controller RX FIFO threshold level
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @return     Indicates at what fill level in the RX FIFO a threshold will be
 *              generated
 *
 *  @retval     One of @ref DL_I2C_RX_FIFO_LEVEL
 */
__STATIC_INLINE DL_I2C_RX_FIFO_LEVEL DL_I2C_getControllerRXFIFOThreshold(
    I2C_Regs *i2c)
{
    uint32_t level = i2c->MASTER.MFIFOCTL & I2C_MFIFOCTL_RXTRIG_MASK;

    return (DL_I2C_RX_FIFO_LEVEL)(level);
}

/**
 *  @brief      Set controller RX FIFO threshold level
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  level   Indicates at what fill level in the RX FIFO a threshold
 *                      will be generated.
 *                      One of @ref DL_I2C_RX_FIFO_LEVEL.
 */
__STATIC_INLINE void DL_I2C_setControllerRXFIFOThreshold(
    I2C_Regs *i2c, DL_I2C_RX_FIFO_LEVEL level)
{
    DL_Common_updateReg(
        &i2c->MASTER.MFIFOCTL, (uint32_t) level, I2C_MFIFOCTL_RXTRIG_MASK);
}

/**
 *  @brief      Stop controller RX FIFO flush
 *
 *  Before stopping the flush, check if @ref DL_I2C_isControllerRXFIFOEmpty,
 *  indicating flush is complete.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_stopFlushControllerRXFIFO(I2C_Regs *i2c)
{
    i2c->MASTER.MFIFOCTL &= ~(I2C_MFIFOCTL_RXFLUSH_MASK);
}

/**
 *  @brief      Start controller RX FIFO flush
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_startFlushControllerRXFIFO(I2C_Regs *i2c)
{
    i2c->MASTER.MFIFOCTL |= I2C_MFIFOCTL_RXFLUSH_MASK;
}

/**
 *  @brief      Get number of bytes which can be read from RX FIFO
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @return     Number of bytes which can be read from RX FIFO
 *
 *  @retval     [0x0, 0x8]
 */
__STATIC_INLINE uint32_t DL_I2C_getControllerRXFIFOCounter(I2C_Regs *i2c)
{
    return (i2c->MASTER.MFIFOSR & I2C_MFIFOSR_RXFIFOCNT_MASK);
}

/**
 *  @brief      Get number of bytes which can be put into TX FIFO
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @return     Number of bytes which can be put into TX FIFO
 *
 *  @retval     [0x0, 0x8]
 */
__STATIC_INLINE uint32_t DL_I2C_getControllerTXFIFOCounter(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MFIFOSR & I2C_MFIFOSR_TXFIFOCNT_MASK) >>
            I2C_MFIFOSR_TXFIFOCNT_OFS);
}

/**
 *  @brief      Checks if controller RX FIFO flush is active
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If controller RX FIFO flush is active
 *
 *  @retval     true if controller RX FIFO flush is active
 *  @retval     false if controller RX FIFO flush is not active
 */
__STATIC_INLINE bool DL_I2C_isControllerRXFIFOFlushActive(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MFIFOSR & I2C_MFIFOSR_RXFLUSH_MASK) ==
            I2C_MFIFOSR_RXFLUSH_ACTIVE);
}

/**
 *  @brief      Checks if controller TX FIFO flush is active
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If controller TX FIFO flush is active
 *
 *  @retval     true if controller TX FIFO flush is active
 *  @retval     false if controller TX FIFO flush is not active
 */
__STATIC_INLINE bool DL_I2C_isControllerTXFIFOFlushActive(I2C_Regs *i2c)
{
    return ((i2c->MASTER.MFIFOSR & I2C_MFIFOSR_TXFLUSH_MASK) ==
            I2C_MFIFOSR_TXFLUSH_ACTIVE);
}

/**
 *  @brief      Set target own address
 *
 * This field specifies bits A9 through A0 of the target own address.
 *
 * In 7-bit addressing mode as selected by @ref DL_I2C_setTargetAddressingMode,
 * the top 3 bits are don't care
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  addr    Value of target own address [0x00, 0x3FF]
 */
__STATIC_INLINE void DL_I2C_setTargetOwnAddress(I2C_Regs *i2c, uint32_t addr)
{
    DL_Common_updateReg(&i2c->SLAVE.SOAR, addr, I2C_SOAR_OAR_MASK);
}

/**
 *  @brief      Get target own address
 *
 * Get bits A9 through A0 of the target own address.
 *
 * In 7-bit addressing mode as selected by @ref DL_I2C_setTargetAddressingMode,
 * the top 3 bits are don't care
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @return     Target own address
 *
 *  @retval     [0x00, 0x3FF]
 */
__STATIC_INLINE uint32_t DL_I2C_getTargetOwnAddress(I2C_Regs *i2c)
{
    return (i2c->SLAVE.SOAR & I2C_SOAR_OAR_MASK);
}

/**
 *  @brief      Enable target own address
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @sa DL_I2C_setTargetOwnAddress
 */
__STATIC_INLINE void DL_I2C_enableTargetOwnAddress(I2C_Regs *i2c)
{
    i2c->SLAVE.SOAR |= I2C_SOAR_OAREN_ENABLE;
}

/**
 *  @brief      Disable target own address
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableTargetOwnAddress(I2C_Regs *i2c)
{
    i2c->SLAVE.SOAR &= ~(I2C_SOAR_OAREN_MASK);
}

/**
 *  @brief      Checks if target own address is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target own address is enabled
 *
 *  @retval     true if target own address is enabled
 *  @retval     false if target own address is disabled
 */
__STATIC_INLINE bool DL_I2C_isTargetOwnAddressEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SOAR & I2C_SOAR_OAREN_MASK) == I2C_SOAR_OAREN_ENABLE);
}

/**
 *  @brief      Set target addressing mode
 *
 *  Selects the addressing mode to be used when device is configured as a
 *  target
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  mode    Addressing mode to set the target to.
 *                      One of @ref DL_I2C_TARGET_ADDRESSING_MODE.
 */
__STATIC_INLINE void DL_I2C_setTargetAddressingMode(
    I2C_Regs *i2c, DL_I2C_TARGET_ADDRESSING_MODE mode)
{
    DL_Common_updateReg(
        &i2c->SLAVE.SOAR, (uint32_t) mode, I2C_SOAR_SMODE_MASK);
}

/**
 *  @brief      Get target addressing mode
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     Addressing mode the target is set to
 *
 *  @retval     One of @ref DL_I2C_TARGET_ADDRESSING_MODE
 */
__STATIC_INLINE DL_I2C_TARGET_ADDRESSING_MODE DL_I2C_getTargetAddressingMode(
    I2C_Regs *i2c)
{
    uint32_t mode = i2c->SLAVE.SOAR & I2C_SOAR_SMODE_MASK;

    return (DL_I2C_TARGET_ADDRESSING_MODE)(mode);
}

/**
 *  @brief      Get target own address alternate
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @return     Target own address alternate
 *
 *  @retval     [0x00, 0x7f]
 */
__STATIC_INLINE uint32_t I2C_getTargetOwnAddressAlternate(I2C_Regs *i2c)
{
    return (i2c->SLAVE.SOAR2 & I2C_SOAR2_OAR2_MASK);
}

/**
 *  @brief      Set target own address alternate
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  addr    Value of target own address alternate [0x00, 0x7f]
 */
__STATIC_INLINE void DL_I2C_setTargetOwnAddressAlternate(
    I2C_Regs *i2c, uint32_t addr)
{
    DL_Common_updateReg(&i2c->SLAVE.SOAR2, addr, I2C_SOAR2_OAR2_MASK);
}

/**
 *  @brief      Get target own address alternate mask
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     Which bits of the target address are matched
 *
 *  @retval     Bit mask with each bit corresponding to bits A6 through A0 of
 *              the target address. Value between [0x00, 0x7F]
 */
__STATIC_INLINE uint32_t I2C_getTargetOwnAddressAlternateMask(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SOAR2 & I2C_SOAR2_OAR2_MASK_MASK) >>
            I2C_SOAR2_OAR2_MASK_OFS);
}

/**
 *  @brief      Set target own address alternate mask
 *
 * This field specifies bits A6 through A0 of the target address. The bits with
 * a value of 1 in the SOAR2.OAR2_MASK field will make the corresponding
 * incoming address bits to match by default regardless of the value inside
 * SOAR2.OAR2 i.e. corresponding SOAR2.OAR2 bit is a don't care.
 *
 *  @param[in]  i2c           Pointer to the register overlay for the peripheral
 *  @param[in]  addressMask   Bit mask of address bits to match.
 *                            Value between [0x00, 0x7F]
 */
__STATIC_INLINE void DL_I2C_setTargetOwnAddressAlternateMask(
    I2C_Regs *i2c, uint32_t addressMask)
{
    DL_Common_updateReg(&i2c->SLAVE.SOAR2,
        addressMask << I2C_SOAR2_OAR2_MASK_OFS, I2C_SOAR2_OAR2_MASK_MASK);
}

/**
 *  @brief      Disable usage of target own address alternate
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableTargetOwnAddressAlternate(I2C_Regs *i2c)
{
    i2c->SLAVE.SOAR2 &= ~(I2C_SOAR2_OAR2EN_MASK);
}

/**
 *  @brief      Checks if target own address alternate is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target own address alternate is enabled
 *
 *  @retval     true if target own address alternate is enabled
 *  @retval     false if target own address alternate is disabled
 */
__STATIC_INLINE bool DL_I2C_isTargetOwnAddressAlternateEnabled(I2C_Regs *i2c)
{
    return (
        (i2c->SLAVE.SOAR2 & I2C_SOAR2_OAR2EN_MASK) == I2C_SOAR2_OAR2EN_ENABLE);
}

/**
 *  @brief      Enable usage of target own address alternate
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableTargetOwnAddressAlternate(I2C_Regs *i2c)
{
    i2c->SLAVE.SOAR2 |= I2C_SOAR2_OAR2EN_ENABLE;
}

/**
 *  @brief      Get the address for which address match happened
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     Matched Target address
 *
 *  @retval     Bit mask with each bit corresponding to the target address.
 *  Value between [0x00, 0x7F] in 7-bit mode, or [0x00, 0x3FF] in 10-bit mode.
 */
__STATIC_INLINE uint32_t DL_I2C_getTargetAddressMatch(I2C_Regs *i2c)
{
    return (
        (i2c->SLAVE.SSR & I2C_SSR_ADDRMATCH_MASK) >> I2C_SSR_ADDRMATCH_OFS);
}

/**
 *  @brief      Disable target clock stretching
 *
 *  Clock stretching should be enabled to be compliant with I2C specification
 *  and the SCL will be stretched when data must be read or written from the
 *  FIFO. It can optionally be disabled if a controller does not support it or
 *  to achieve maximum I2C frequency; however the developer should ensure that
 *  the FIFO is written or read on time.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableTargetClockStretching(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR &= ~(I2C_SCTR_SCLKSTRETCH_MASK);
}

/**
 *  @brief      Checks if target clock stretching is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target clock stretching is enabled
 *
 *  @retval     true if target clock stretching is enabled
 *  @retval     false if target clock stretching is disabled
 */
__STATIC_INLINE bool DL_I2C_isTargetClockStretchingEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SCTR & I2C_SCTR_SCLKSTRETCH_MASK) ==
            I2C_SCTR_SCLKSTRETCH_ENABLE);
}

/**
 *  @brief      Enable target clock stretching
 *
 *  Clock stretching should be enabled to be compliant with I2C specification
 *  and the SCL will be stretched when data must be read or written from the
 *  FIFO. It can optionally be disabled if a controller does not support it or
 *  to achieve maximum I2C frequency; however the developer should ensure that
 *  the FIFO is written or read on time.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableTargetClockStretching(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR |= I2C_SCTR_SCLKSTRETCH_ENABLE;
}

/**
 *  @brief      Disable target TX empty interrupt on transmit request
 *
 * When disabled, RIS.STXEMPTY will be set when only the Target TX FIFO is
 * empty. This allows the STXEMPTY interrupt to be used to indicate that the
 * I2C bus is being clock stretched and that Target TX data is required.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @sa         DL_I2C_isTargetClockStretchEnabled
 */
__STATIC_INLINE void DL_I2C_disableTargetTXEmptyOnTXRequest(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR &= ~(I2C_SCTR_TXEMPTY_ON_TREQ_MASK);
}

/**
 *  @brief      Checks if target TX empty interrupt on transmit request is
 *              enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If TX empty interrupt on transmit request is enabled
 *
 *  @retval     true if TX empty interrupt on transmit request is enabled
 *  @retval     false if TX empty interrupt on transmit request disabled
 */
__STATIC_INLINE bool DL_I2C_isTargetTXEmptyOnTXRequestEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SCTR & I2C_SCTR_TXEMPTY_ON_TREQ_MASK) ==
            I2C_SCTR_TXEMPTY_ON_TREQ_ENABLE);
}

/**
 *  @brief      Enable target TX empty interrupt on transmit request
 *
 *  When enabled, RIS.STXEMPTY will be set when the Target state machine is in
 *  the TX_WAIT state which occurs when the TX FIFO is empty AND the I2C
 *  transaction is clock stretched waiting for the FIFO to receive data.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableTargetTXEmptyOnTXRequest(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR |= I2C_SCTR_TXEMPTY_ON_TREQ_ENABLE;
}

/**
 *  @brief      Disable target TX trigger in TX mode
 *
 * When disabled, RIS.TXFIFOTRG will only be set when the Target TX FIFO is at
 * or above the trigger level.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableTargetTXTriggerInTXMode(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR &= ~(I2C_SCTR_TXTRIG_TXMODE_MASK);
}

/**
 *  @brief      Checks if target TX trigger in TX mode is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target TX trigger in TX mode is enabled
 *
 *  @retval     true if target TX trigger in TX mode is enabled
 *  @retval     false if target TX trigger in TX mode is disabled
 */
__STATIC_INLINE bool DL_I2C_isTargetTXTriggerInTXModeEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SCTR & I2C_SCTR_TXTRIG_TXMODE_MASK) ==
            I2C_SCTR_TXTRIG_TXMODE_ENABLE);
}

/**
 *  @brief      Enable TX trigger when target is in TX mode
 *
 *  When enabled, RIS.TXFIFOTRG will be set when the Target TX FIFO has reached
 *  the trigger level AND the Target state machine is in the TXMODE as defined
 *  in the SSR register. When cleared RIS.TXFIFOTRG will be set when the Target
 *  TX FIFO is at or above the trigger level. This setting can be used to hold
 *  off the TX DMA until a transaction starts. This allows the DMA to be
 *  configured when the I2C is idle but have it wait till the transaction
 *  starts to load the Target TX FIFO, so it can load from a memory buffer that
 *  might be changing over time.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @sa                 DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER
 */
__STATIC_INLINE void DL_I2C_enableTargetTXTriggerInTXMode(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR |= I2C_SCTR_TXTRIG_TXMODE_ENABLE;
}

/**
 *  @brief      Disable target TX transfer waits when stale data in TX FIFO
 *
 *  When disabled, the TX FIFO empty signal to the Target state machine
 *  indicates that the TX FIFO is empty.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableTargetTXWaitWhenTXFIFOStale(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR &= ~(I2C_SCTR_TXWAIT_STALE_TXFIFO_MASK);
}

/**
 *  @brief      Checks if target TX transfer waits when stale data in TX FIFO
 *              is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target TX transfer waits when stale data in TX FIFO is
 *              enabled
 *
 *  @retval     true   if target TX transfer waits when stale data in TX FIFO
 *                     is enabled
 *  @retval     false  if target TX transfer waits when stale data in TX FIFO
 *                     is disabled
 */
__STATIC_INLINE bool DL_I2C_isTargetTXWaitWhenTXFIFOStaleEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SCTR & I2C_SCTR_TXWAIT_STALE_TXFIFO_MASK) ==
            I2C_SCTR_TXWAIT_STALE_TXFIFO_ENABLE);
}

/**
 *  @brief      Enable target TX transfer waits when stale data in TX FIFO
 *
 *  When enabled, the TX FIFO empty signal to the Target state machine will
 *  indicate that the TX FIFO is empty or that the TX FIFO data is stale. The
 *  TX FIFO data is determined to be stale when there is data in the TX FIFO
 *  when the Target state machine leaves the TXMODE as defined in the SSR
 *  register. This can occur is a Stop or timeout occur when there are bytes
 *  left in the TX FIFO.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableTargetTXWaitWhenTXFIFOStale(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR |= I2C_SCTR_TXWAIT_STALE_TXFIFO_ENABLE;
}

/**
 *  @brief      Disable target RX full interrupt on receive request
 *
 *  When disabled, RIS.SRXFULL will be set when only the Target RX FIFO is
 *  full. This allows the SRXFULL interrupt to be used to indicate that the
 *  I2C bus is being clock stretched and that the FW must either read the RX
 *  FIFO or ACK/NACK the current RX byte.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @sa         DL_I2C_isTargetClockStretchEnabled
 */
__STATIC_INLINE void DL_I2C_disableTargetRXFullOnRXRequest(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR &= ~(I2C_SCTR_RXFULL_ON_RREQ_MASK);
}

/**
 *  @brief      Checks if target RX full interrupt on receive request is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target RX full interrupt on receive request enabled
 *
 *  @retval     true   if target RX full interrupt on receive request enabled
 *  @retval     false  if target RX full interrupt on receive request disabled
 */
__STATIC_INLINE bool DL_I2C_isTargetRXFullOnRXRequestEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SCTR & I2C_SCTR_RXFULL_ON_RREQ_MASK) ==
            I2C_SCTR_RXFULL_ON_RREQ_ENABLE);
}

/**
 *  @brief      Enable target RX full interrupt on receive request
 *
 *  When enabled, RIS.SRXFULL will be set when the Target state machine is in
 *  the RX_WAIT or RX_ACK_WAIT states which occurs when the I2C transaction is
 *  clock stretched because the RX FIFO is full or the ACKOEN has been set and
 *  the state machine is waiting for FW to ACK/NACK the current byte.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_I2C_enableTargetRXFullOnRXRequest(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR |= I2C_SCTR_RXFULL_ON_RREQ_ENABLE;
}

/**
 *  @brief      Disable SMBus/PMBus default host address of 000 1000b
 *
 *  When disabled, the default host address is not matched.
 *  NOTE: The host address may still be matched if programmed as an own address.
 *    The I2C module can still be addressed as a target if enabled and own
 *  address match is enabled.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableDefaultHostAddress(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR &= ~(I2C_SCTR_EN_DEFHOSTADR_MASK);
}

/**
 *  @brief      Checks if SMBus/PMBus default host address of 000 1000b is
 *              enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If default host address is enabled
 *
 *  @retval     true   if default host address is enabled
 *  @retval     false  if default host address disabled
 */
__STATIC_INLINE bool DL_I2C_isDefaultHostAddressEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SCTR & I2C_SCTR_EN_DEFHOSTADR_MASK) ==
            I2C_SCTR_EN_DEFHOSTADR_ENABLE);
}

/**
 *  @brief      Enable SMBus/PMBus default host address of 000 1000b
 *
 *  When enabled, default host address of 0x0001000 is always matched by the
 *  target address match logic
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableDefaultHostAddress(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR |= I2C_SCTR_EN_DEFHOSTADR_ENABLE;
}

/**
 *  @brief      Disable SMBus/PMBus Alert response address (ARA) of 000 1100b
 *
 *  When disabled, the alert response address 0x0001100 is not matched.
 *  NOTE: The alert response address may still be matched if programmed as an
 *  own address.
 *    The I2C module can still be addressed as a target if enabled and own
 *  address match is enabled.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableAlertResponseAddress(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR &= ~(I2C_SCTR_EN_ALRESPADR_MASK);
}

/**
 *  @brief      Checks if SMBus/PMBus Alert response address (ARA) of 000 1100b
 * is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If alert response address is enabled
 *
 *  @retval     true   if alert response address is enabled
 *  @retval     false  if alert response address disabled
 */
__STATIC_INLINE bool DL_I2C_isAlertResponseAddressEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SCTR & I2C_SCTR_EN_ALRESPADR_MASK) ==
            I2C_SCTR_EN_ALRESPADR_ENABLE);
}

/**
 *  @brief      Enable SMBus/PMBus Alert response address (ARA) of 000 1100b
 *
 *  When enabled, default alert response address of 0x0001100 is always matched
 *  by the target address match logic
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableAlertResponseAddress(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR |= I2C_SCTR_EN_ALRESPADR_ENABLE;
}

/**
 *  @brief      Disable SMBus/PMBus default device address of 110 0001b
 *
 *  Used for Address Resolution Protocol. When disabled, the default device
 *  address is not matched.
 *  NOTE: The host address may still be matched if programmed as an own address.
 *    The I2C module can still be addressed as a target if enabled and own
 *  address match is enabled.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableDefaultDeviceAddress(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR &= ~(I2C_SCTR_EN_DEFDEVADR_MASK);
}

/**
 *  @brief      Checks SMBus/PMBus default device address of 110 0001b is
 *              enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If default device address is enabled
 *
 *  @retval     true   if default device address is enabled
 *  @retval     false  if default device address disabled
 */
__STATIC_INLINE bool DL_I2C_isDefaultDeviceAddressEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SCTR & I2C_SCTR_EN_DEFDEVADR_MASK) ==
            I2C_SCTR_EN_DEFDEVADR_ENABLE);
}

/**
 *  @brief      Enable SMBus/PMBus default device address of 110 0001b
 *
 *  Used for Address Resolution Protocol. When enabled, default device address
 *  of 110 0001b is always matched by the target address match logic.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableDefaultDeviceAddress(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR |= I2C_SCTR_EN_DEFDEVADR_ENABLE;
}

/**
 *  @brief      Disable target wakeup
 *
 *  When disabled, the target is not allowed to clock stretch on START
 *  detection.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableTargetWakeup(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR &= ~(I2C_SCTR_SWUEN_MASK);
}

/**
 *  @brief      Checks if target wakeup is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target wakeup is enabled
 *
 *  @retval     true   if target wakeup is enabled
 *  @retval     false  if target wakeup disabled
 */
__STATIC_INLINE bool DL_I2C_isTargetWakeupEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SCTR & I2C_SCTR_SWUEN_MASK) == I2C_SCTR_SWUEN_ENABLE);
}

/**
 *  @brief      Enable target wakeup
 *
 *  Enables low-power wake-up, however it is recommended to enable target clock
 *  stretching to stretch the clock while the module is waking up.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @sa         DL_I2C_enableTargetClockStretching
 */
__STATIC_INLINE void DL_I2C_enableTargetWakeup(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR |= I2C_SCTR_SWUEN_ENABLE;
}

/**
 *  @brief      Disable target functionality
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableTarget(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR &= ~(I2C_SCTR_ACTIVE_MASK);
}

/**
 *  @brief      Checks if target functionality is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target functionality is enabled
 *
 *  @retval     true if target functionality is enabled
 *  @retval     false if target functionality is disabled
 */
__STATIC_INLINE bool DL_I2C_isTargetEnabled(I2C_Regs *i2c)
{
    return (
        (i2c->SLAVE.SCTR & I2C_SCTR_ACTIVE_MASK) == I2C_SCTR_ACTIVE_ENABLE);
}

/**
 *  @brief      Enable usage of target functionality
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableTarget(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR |= I2C_SCTR_ACTIVE_ENABLE;
}

/**
 *  @brief      Disable general call address of 000 0000b
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableGeneralCall(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR &= ~(I2C_SCTR_GENCALL_MASK);
}

/**
 *  @brief      Checks if general call address of 000 0000b is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If general call is enabled
 *
 *  @retval     true if general call is enabled
 *  @retval     false if general call is disabled
 */
__STATIC_INLINE bool DL_I2C_isGeneralCallEnabled(I2C_Regs *i2c)
{
    return (
        (i2c->SLAVE.SCTR & I2C_SCTR_GENCALL_MASK) == I2C_SCTR_GENCALL_ENABLE);
}

/**
 *  @brief      Enable usage of general call address of 000 0000b
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableGeneralCall(I2C_Regs *i2c)
{
    i2c->SLAVE.SCTR |= I2C_SCTR_GENCALL_ENABLE;
}

/**
 *  @brief      Get status of I2C bus controller for target
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @return     Status of I2C bus controller for target
 *
 *  @retval     Bitwise OR of @ref DL_I2C_TARGET_STATUS
 */
__STATIC_INLINE uint32_t DL_I2C_getTargetStatus(I2C_Regs *i2c)
{
    return (i2c->SLAVE.SSR);
}

/**
 *  @brief      Get byte of data from I2C target
 *
 *  If using FIFO, it is first byte from the RX FIFO.
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @return     Last received byte of data
 *
 *  @retval     [0x00, 0xff]
 */
__STATIC_INLINE uint8_t DL_I2C_receiveTargetData(I2C_Regs *i2c)
{
    return (uint8_t)(i2c->SLAVE.SRXDATA & I2C_SRXDATA_VALUE_MASK);
}

/**
 *  @brief      Set next byte to be transferred during the next transaction
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  data    Byte of data to be transferred during the next
 *                      transaction. [0x00, 0xff]
 */
__STATIC_INLINE void DL_I2C_transmitTargetData(I2C_Regs *i2c, uint8_t data)
{
    i2c->SLAVE.STXDATA = data;
}

/**
 *  @brief      Disable target ACK override
 *
 *  Disable manual ACK override to automatically ACK all received bytes until
 *  the RX FIFO is full.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableTargetACKOverride(I2C_Regs *i2c)
{
    i2c->SLAVE.SACKCTL &= ~(I2C_SACKCTL_ACKOEN_MASK);
}

/**
 *  @brief      Checks if target ACK override is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target ACK override is enabled
 *
 *  @retval     true if target ACK override is enabled
 *  @retval     false if target ACK override is disabled
 */
__STATIC_INLINE bool DL_I2C_isTargetACKOverrideEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SACKCTL & I2C_SACKCTL_ACKOEN_MASK) ==
            I2C_SACKCTL_ACKOEN_ENABLE);
}

/**
 *  @brief      Enable target ACK override
 *
 *  When manual ACK override is enabled, the I2C target SCL is pulled low after
 *  the last data is received until the ACK override value (through
 *  @ref DL_I2C_setTargetACKOverrideValue) is written.
 *  Disable manual ACK override to automatically ACK all received bytes until
 *  the RX FIFO is full.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableTargetACKOverride(I2C_Regs *i2c)
{
    i2c->SLAVE.SACKCTL |= I2C_SACKCTL_ACKOEN_ENABLE;
}

/**
 *  @brief      Get target acknowledge override value
 *
 *  @note for General Call this bit will be ignored if set to NACK and target
 *  continues to receive data.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     What type of response will be generated
 *
 *  @retval     One of @ref DL_I2C_TARGET_RESPONSE_OVERRIDE_VALUE.
 */
__STATIC_INLINE DL_I2C_TARGET_RESPONSE_OVERRIDE_VALUE
DL_I2C_getTargetACKOverrideValue(I2C_Regs *i2c)
{
    uint32_t value = i2c->SLAVE.SACKCTL & I2C_SACKCTL_ACKOVAL_MASK;

    return (DL_I2C_TARGET_RESPONSE_OVERRIDE_VALUE)(value);
}

/**
 *  @brief      Set target acknowledge override value
 *
 *  @note for General Call this bit will be ignored if set to NACK and target
 *  continues to receive data.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  value   Indicates what type of response will be generated.
 *                      One of @ref DL_I2C_TARGET_RESPONSE_OVERRIDE_VALUE.
 *
 *  @sa         DL_I2C_enableTargetACKOverride
 */
__STATIC_INLINE void DL_I2C_setTargetACKOverrideValue(
    I2C_Regs *i2c, DL_I2C_TARGET_RESPONSE_OVERRIDE_VALUE value)
{
    DL_Common_updateReg(
        &i2c->SLAVE.SACKCTL, (uint32_t) value, I2C_SACKCTL_ACKOVAL_MASK);
}

/**
 *  @brief      Disable target ACK override on Start Condition
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableACKOverrideOnStart(I2C_Regs *i2c)
{
    i2c->SLAVE.SACKCTL &= ~(I2C_SACKCTL_ACKOEN_ON_START_MASK);
}

/**
 *  @brief      Checks if target ACK override on Start condition is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target ACK override on Start condition is enabled
 *
 *  @retval     true if target ACK override on Start condition is enabled
 *  @retval     false if target ACK override on Start condition is disabled
 */
__STATIC_INLINE bool DL_I2C_isACKOverrideOnStartEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SACKCTL & I2C_SACKCTL_ACKOEN_ON_START_MASK) ==
            I2C_SACKCTL_ACKOEN_ON_START_ENABLE);
}

/**
 *  @brief      Enable target ACK override on Start condition
 *
 *  When enabled, this bit will automatically turn on the Target ACKOEN field
 *  following a Start condition.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @sa                 DL_I2C_enableTargetACKOverride
 */
__STATIC_INLINE void DL_I2C_enableACKOverrideOnStart(I2C_Regs *i2c)
{
    i2c->SLAVE.SACKCTL |= I2C_SACKCTL_ACKOEN_ON_START_ENABLE;
}

/**
 *  @brief      Disable target ACK override when SMBus/PMBus PEC is next byte
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableACKOverrideOnPECNext(I2C_Regs *i2c)
{
    i2c->SLAVE.SACKCTL &= ~(I2C_SACKCTL_ACKOEN_ON_PECNEXT_MASK);
}

/**
 *  @brief      Checks if target ACK override when SMBus/PMBus PEC is next byte
 *              is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target ACK override when PEC is next byte is enabled
 *
 *  @retval     true if target ACK override when PEC is next byte is enabled
 *  @retval     false if target ACK override when PEC is next byte is disabled
 */
__STATIC_INLINE bool DL_I2C_isACKOverrideOnPECNextEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SACKCTL & I2C_SACKCTL_ACKOEN_ON_PECNEXT_MASK) ==
            I2C_SACKCTL_ACKOEN_ON_PECNEXT_ENABLE);
}

/**
 *  @brief      Enable target ACK override when SMBus/PMBus PEC is next byte
 *
 *  When enabled, this bit will automatically turn on the Target ACKOEN field
 *  following the ACK/NACK of the byte received just prior to the PEC byte.
 *  Note that when ACKOEN is set, the PEC byte will not automatically be
 *  ACKed/NACKed by the state machine and FW must perform this function by
 *  writing SLAVE_SACKCTL.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @sa                 DL_I2C_enableTargetACKOverride
 */
__STATIC_INLINE void DL_I2C_enableACKOverrideOnPECNext(I2C_Regs *i2c)
{
    i2c->SLAVE.SACKCTL |= I2C_SACKCTL_ACKOEN_ON_PECNEXT_ENABLE;
}

/**
 *  @brief      Disable target ACK override when SMBus/PMBus PEC is next byte
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableACKOverrideOnPECDone(I2C_Regs *i2c)
{
    i2c->SLAVE.SACKCTL &= ~(I2C_SACKCTL_ACKOEN_ON_PECDONE_MASK);
}

/**
 *  @brief      Checks if target ACK override when SMBus/PMBus PEC is next byte
 *              is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target ACK override when PEC is next byte is enabled
 *
 *  @retval     true if target ACK override when PEC is next byte is enabled
 *  @retval     false if target ACK override when PEC is next byte is disabled
 */
__STATIC_INLINE bool DL_I2C_isACKOverrideOnPECDoneEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SACKCTL & I2C_SACKCTL_ACKOEN_ON_PECDONE_MASK) ==
            I2C_SACKCTL_ACKOEN_ON_PECDONE_ENABLE);
}

/**
 *  @brief      Enable target ACK override when SMBus/PMBus PEC is done
 *
 *  When enabled, this bit will automatically turn on the Target ACKOEN field
 * following the ACK/NACK of the received PEC byte.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @sa                 DL_I2C_enableTargetACKOverride
 */
__STATIC_INLINE void DL_I2C_enableACKOverrideOnPECDone(I2C_Regs *i2c)
{
    i2c->SLAVE.SACKCTL |= I2C_SACKCTL_ACKOEN_ON_PECDONE_ENABLE;
}

/**
 *  @brief      Get the target SMBus/PMBus Packet Error Checking (PEC) count
 *              value
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     The value the PEC count is set to
 *
 *  @retval     Value between [0x0, 0x01FF]
 */
__STATIC_INLINE uint32_t DL_I2C_getTargetPECCountValue(I2C_Regs *i2c)
{
    return (i2c->SLAVE.TARGET_PECCTL & I2C_TARGET_PECCTL_PECCNT_MASK);
}

/**
 *  @brief      Set the target SMBus/PMBus Packet Error Checking (PEC) count
 *              value
 *
 *  When this field is non zero, the number of I2C data bytes are counted.
 *  Refer to the device TRM for more details.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  count   The value to set the PEC count to.
 *                      Value between [0x0, 0x01FF]
 */
__STATIC_INLINE void DL_I2C_setTargetPECCountValue(
    I2C_Regs *i2c, uint32_t count)
{
    DL_Common_updateReg(
        &i2c->SLAVE.TARGET_PECCTL, count, I2C_TARGET_PECCTL_PECCNT_MASK);
}

/**
 *  @brief      Disable target SMBus/PMBus Packet Error Checking (PEC)
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableTargetPEC(I2C_Regs *i2c)
{
    i2c->SLAVE.TARGET_PECCTL &= ~(I2C_TARGET_PECCTL_PECEN_MASK);
}

/**
 *  @brief      Checks if target SMBus/PMBus Packet Error Checking (PEC) is
 *              enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target PEC is enabled
 *
 *  @retval     true if target PEC is enabled
 *  @retval     false if target PEC is disabled
 */
__STATIC_INLINE bool DL_I2C_isTargetPECEnabled(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.TARGET_PECCTL & I2C_TARGET_PECCTL_PECEN_MASK) ==
            I2C_TARGET_PECCTL_PECEN_ENABLE);
}

/**
 *  @brief      Enable target SMBus/PMBus Packet Error Checking (PEC)
 *
 *  When enabled, the PEC is calculated on all bits accept the Start, Stop, ACK
 *  and NACK. The PEC LSFR and the Byte Counter is set to 0 when the State
 *  Machine is in the IDLE state, which occurs following a Stop or when a
 *  timeout occurs. The Counter is also set to 0 after the PEC byte is sent or
 *  received. Note that the NACK is automatically sent following a PEC byte
 *  that results in a PEC error.
 *  The PEC Polynomial is x^8 + x^2 + x^1 + 1.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_I2C_enableTargetPEC(I2C_Regs *i2c)
{
    i2c->SLAVE.TARGET_PECCTL |= I2C_TARGET_PECCTL_PECEN_ENABLE;
}

/**
 *  @brief      Get the current SMBus/PMBus PEC byte count of the Target state
 *              machine
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     The current PEC byte count of the target state macione
 *
 *  @retval     Value between [0x0, 0x01FF]
 */
__STATIC_INLINE uint32_t DL_I2C_getTargetCurrentPECCount(I2C_Regs *i2c)
{
    return (i2c->SLAVE.TARGET_PECCTL & I2C_TARGET_PECSR_PECBYTECNT_MASK);
}

/**
 *  @brief      Get status if SMBus/PMBus target PEC was checked in last
 *              transaction
 *
 *  The status of if the target PEC was checked in the transaction that
 *  occurred before the last Stop. Latched on Stop.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     Status of PEC target checked
 *
 *  @retval     One of @ref DL_I2C_TARGET_PEC_STATUS
 */
__STATIC_INLINE DL_I2C_TARGET_PEC_STATUS DL_I2C_getTargetPECCheckedStatus(
    I2C_Regs *i2c)
{
    uint32_t status =
        i2c->SLAVE.TARGET_PECSR & I2C_TARGET_PECSR_PECSTS_CHECK_MASK;

    return (DL_I2C_TARGET_PEC_STATUS)(status);
}

/**
 *  @brief      Get target TX FIFO threshold level
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @return     Indicates at what fill level in the TX FIFO a threshold will be
 *              generated
 *
 *  @retval     One of @ref DL_I2C_TX_FIFO_LEVEL
 */
__STATIC_INLINE DL_I2C_TX_FIFO_LEVEL DL_I2C_getTargetTXFIFOThreshold(
    I2C_Regs *i2c)
{
    uint32_t level = i2c->SLAVE.SFIFOCTL & I2C_SFIFOCTL_TXTRIG_MASK;

    return (DL_I2C_TX_FIFO_LEVEL)(level);
}

/**
 *  @brief      Set target TX FIFO threshold level
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  level   Indicates at what fill level in the TX FIFO a threshold
 *                      will be generated.
 *                      One of @ref DL_I2C_TX_FIFO_LEVEL.
 */
__STATIC_INLINE void DL_I2C_setTargetTXFIFOThreshold(
    I2C_Regs *i2c, DL_I2C_TX_FIFO_LEVEL level)
{
    DL_Common_updateReg(&i2c->SLAVE.SFIFOCTL, (uint32_t) level,
        (uint32_t) I2C_SFIFOCTL_TXTRIG_MASK);
}

/**
 *  @brief      Stop target TX FIFO flush
 *
 *  Before stopping the flush, check if @ref DL_I2C_isTargetTXFIFOEmpty,
 *  indicating flush is complete.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_stopFlushTargetTXFIFO(I2C_Regs *i2c)
{
    i2c->SLAVE.SFIFOCTL &= ~(I2C_SFIFOCTL_TXFLUSH_MASK);
}

/**
 *  @brief      Start target TX FIFO flush
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_startFlushTargetTXFIFO(I2C_Regs *i2c)
{
    i2c->SLAVE.SFIFOCTL |= I2C_SFIFOCTL_TXFLUSH_MASK;
}

/**
 *  @brief      Stop target RX FIFO flush
 *
 *  Before stopping the flush, check if @ref DL_I2C_isTargetRXFIFOEmpty,
 *  indicating flush is complete.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_stopFlushTargetRXFIFO(I2C_Regs *i2c)
{
    i2c->SLAVE.SFIFOCTL &= ~(I2C_SFIFOCTL_RXFLUSH_MASK);
}

/**
 *  @brief      Start target RX FIFO flush
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_startFlushTargetRXFIFO(I2C_Regs *i2c)
{
    i2c->SLAVE.SFIFOCTL |= I2C_SFIFOCTL_RXFLUSH_MASK;
}

/**
 *  @brief      Get target RX FIFO threshold level
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @return     Indicates at what fill level in the RX FIFO a threshold will be
 *              generated
 *
 *  @retval     One of @ref DL_I2C_RX_FIFO_LEVEL
 */
__STATIC_INLINE DL_I2C_RX_FIFO_LEVEL DL_I2C_getTargetRXFIFOThreshold(
    I2C_Regs *i2c)
{
    uint32_t level = i2c->SLAVE.SFIFOCTL & I2C_SFIFOCTL_RXTRIG_MASK;

    return (DL_I2C_RX_FIFO_LEVEL)(level);
}

/**
 *  @brief      Set target RX FIFO threshold level
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *  @param[in]  level   Indicates at what fill level in the RX FIFO a threshold
 *                      will be generated.
 *                      One of @ref DL_I2C_RX_FIFO_LEVEL.
 */
__STATIC_INLINE void DL_I2C_setTargetRXFIFOThreshold(
    I2C_Regs *i2c, DL_I2C_RX_FIFO_LEVEL level)
{
    DL_Common_updateReg(
        &i2c->SLAVE.SFIFOCTL, (uint32_t) level, I2C_SFIFOCTL_RXTRIG_MASK);
}

/**
 *  @brief      Get number of bytes which can be read from RX FIFO
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @return     Number of bytes which can be read from RX FIFO
 *
 *  @retval     [0x0, 0x8]
 */
__STATIC_INLINE uint32_t DL_I2C_getTargetRXFIFOCounter(I2C_Regs *i2c)
{
    return (i2c->SLAVE.SFIFOSR & I2C_SFIFOSR_RXFIFOCNT_MASK);
}

/**
 *  @brief      Get number of bytes which can be put into TX FIFO
 *
 *  @param[in]  i2c         Pointer to the register overlay for the peripheral
 *
 *  @return     Number of bytes which can be put into TX FIFO
 *
 *  @retval     [0x0, 0x8]
 */
__STATIC_INLINE uint32_t DL_I2C_getTargetTXFIFOCounter(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SFIFOSR & I2C_SFIFOSR_TXFIFOCNT_MASK) >>
            I2C_SFIFOSR_TXFIFOCNT_OFS);
}

/**
 *  @brief      Checks if target RX FIFO flush is active
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target RX FIFO flush is active
 *
 *  @retval     true if target RX FIFO flush is active
 *  @retval     false if target RX FIFO flush is not active
 */
__STATIC_INLINE bool DL_I2C_isTargetRXFIFOFlushActive(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SFIFOSR & I2C_SFIFOSR_RXFLUSH_MASK) ==
            I2C_SFIFOSR_RXFLUSH_ACTIVE);
}

/**
 *  @brief      Checks if target TX FIFO flush is active
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If target TX FIFO flush is active
 *
 *  @retval     true if target TX FIFO flush is active
 *  @retval     false if target TX FIFO flush is not active
 */
__STATIC_INLINE bool DL_I2C_isTargetTXFIFOFlushActive(I2C_Regs *i2c)
{
    return ((i2c->SLAVE.SFIFOSR & I2C_SFIFOSR_TXFLUSH_MASK) ==
            I2C_SFIFOSR_TXFLUSH_ACTIVE);
}

/**
 *  @brief      Enable I2C interrupts
 *
 *  @param[in]  i2c            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_I2C_INTERRUPT.
 */
__STATIC_INLINE void DL_I2C_enableInterrupt(
    I2C_Regs *i2c, uint32_t interruptMask)
{
    i2c->CPU_INT.IMASK |= interruptMask;
}

/**
 *  @brief      Disable I2C interrupts
 *
 *  @param[in]  i2c            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to disable. Bitwise OR of
 *                             @ref DL_I2C_INTERRUPT.
 */
__STATIC_INLINE void DL_I2C_disableInterrupt(
    I2C_Regs *i2c, uint32_t interruptMask)
{
    i2c->CPU_INT.IMASK &= ~(interruptMask);
}

/**
 *  @brief      Check which I2C interrupts are enabled
 *
 *  @param[in]  i2c            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_I2C_INTERRUPT.
 *
 *  @return     Which of the requested I2C interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_I2C_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_I2C_getEnabledInterrupts(
    I2C_Regs *i2c, uint32_t interruptMask)
{
    return (i2c->CPU_INT.IMASK & interruptMask);
}

/**
 *  @brief      Check interrupt flag of enabled I2C interrupts
 *
 *  Checks if any of the I2C interrupts that were previously enabled are
 *  pending.
 *
 *  @param[in]  i2c            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_I2C_INTERRUPT.
 *
 *  @return     Which of the requested I2C interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_I2C_INTERRUPT values
 *
 *  @sa         DL_I2C_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_I2C_getEnabledInterruptStatus(
    I2C_Regs *i2c, uint32_t interruptMask)
{
    return (i2c->CPU_INT.MIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of any I2C interrupt
 *
 *  Checks if any of the I2C interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  i2c            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_I2C_INTERRUPT.
 *
 *  @return     Which of the requested I2C interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_I2C_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_I2C_getRawInterruptStatus(
    I2C_Regs *i2c, uint32_t interruptMask)
{
    return (i2c->CPU_INT.RIS & interruptMask);
}

/**
 *  @brief      Get highest priority pending I2C interrupt
 *
 *  Checks if any of the I2C interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  i2c  Pointer to the register overlay for the peripheral
 *
 *  @return     The highest priority pending I2C interrupt
 *
 *  @retval     One of @ref DL_I2C_IIDX
 */
__STATIC_INLINE DL_I2C_IIDX DL_I2C_getPendingInterrupt(I2C_Regs *i2c)
{
    return ((DL_I2C_IIDX) i2c->CPU_INT.IIDX);
}

/**
 *  @brief      Clear pending I2C interrupts
 *
 *  @param[in]  i2c            Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_I2C_INTERRUPT.
 */
__STATIC_INLINE void DL_I2C_clearInterruptStatus(
    I2C_Regs *i2c, uint32_t interruptMask)
{
    i2c->CPU_INT.ICLR = interruptMask;
}

/**
 *  @brief Enables I2C interrupt for triggering DMA events
 *
 * Enables the I2C interrupt to be used as the condition to generate an
 * event to directly trigger the DMA.
 *
 * Each event publisher @ref DL_I2C_EVENT_ROUTE can set any one of
 * @ref DL_I2C_DMA_INTERRUPT.
 *
 * @note Only one interrupt source should be enabled at a time.
 *
 *  @param[in]  i2c        Pointer to the register overlay for the peripheral
 *  @param[in]  index      Specifies the register event publisher to configure
 *  @param[in]  interrupt  Interrupt to enable as the trigger condition for
 *                         the DMA. One of @ref DL_I2C_DMA_INTERRUPT.
 */
__STATIC_INLINE void DL_I2C_enableDMAEvent(
    I2C_Regs *i2c, DL_I2C_EVENT_ROUTE index, uint32_t interrupt)
{
    switch (index) {
        case DL_I2C_EVENT_ROUTE_1:
            i2c->DMA_TRIG1.IMASK = interrupt;
            break;
        case DL_I2C_EVENT_ROUTE_2:
            i2c->DMA_TRIG0.IMASK = interrupt;
            break;
        default:
            break;
    }
}

/**
 *  @brief Disables I2C interrupt from triggering DMA events
 *
 * Disables the I2C interrupt from being used as the condition to generate an
 * event to directly trigger the DMA.
 *
 * Each event publisher @ref DL_I2C_EVENT_ROUTE can set any one of
 * @ref DL_I2C_DMA_INTERRUPT.
 *
 *  @param[in]  i2c        Pointer to the register overlay for the peripheral
 *  @param[in]  index      Specifies the register event publisher to configure
 *  @param[in]  interrupt  Interrupt to disable as the trigger condition for
 *                         the DMA. One of @ref DL_I2C_DMA_INTERRUPT.
 */
__STATIC_INLINE void DL_I2C_disableDMAEvent(
    I2C_Regs *i2c, DL_I2C_EVENT_ROUTE index, uint32_t interrupt)
{
    switch (index) {
        case DL_I2C_EVENT_ROUTE_1:
            i2c->DMA_TRIG1.IMASK &= ~(interrupt);
            break;
        case DL_I2C_EVENT_ROUTE_2:
            i2c->DMA_TRIG0.IMASK &= ~(interrupt);
            break;
        default:
            break;
    }
}

/**
 *  @brief Check which I2C interrupt for DMA receive events is enabled
 *
 *  This API checks the event publisher register as selected by
 *  @ref DL_I2C_EVENT_ROUTE, which are used for triggering the DMA for
 *  Controller or Target and receive or transmit events.
 *
 *  @param[in]  i2c            Pointer to the register overlay for the peripheral
 *  @param[in]  index          Specifies the register event publisher to configure
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_I2C_DMA_INTERRUPT.
 *
 *  @note Only one interrupt source should be enabled at a time.
 *
 *  @return     The requested I2C interrupt status
 *
 *  @retval     One of @ref DL_I2C_DMA_INTERRUPT
 */
__STATIC_INLINE uint32_t DL_I2C_getEnabledDMAEvents(
    I2C_Regs *i2c, DL_I2C_EVENT_ROUTE index, uint32_t interruptMask)
{
    volatile uint32_t *pReg = &i2c->DMA_TRIG1.IMASK;

    return ((*(pReg + (uint32_t) index) & interruptMask));
}

/**
 *  @brief Check interrupt flag of enabled I2C interrupt for DMA event
 *
 *  Checks if any of the I2C interrupts for the DMA receive event that were
 *  previously enabled are pending.
 *  This API checks the event publisher register as selected by
 *  @ref DL_I2C_EVENT_ROUTE, which are used for triggering the DMA for
 *  Controller or Target and receive or transmit events.
 *
 *  @param[in]  i2c            Pointer to the register overlay for the peripheral
 *  @param[in]  index          Specifies the register event publisher to configure
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_I2C_DMA_INTERRUPT.
 *
 *  @note Only one interrupt source should be enabled at a time.
 *
 *  @return     The requested I2C interrupt status
 *
 *  @retval     One of @ref DL_I2C_DMA_INTERRUPT
 *
 *  @sa         DL_I2C_enableDMAEvent
 */
__STATIC_INLINE uint32_t DL_I2C_getEnabledDMAEventStatus(
    I2C_Regs *i2c, DL_I2C_EVENT_ROUTE index, uint32_t interruptMask)
{
    const volatile uint32_t *pReg = &i2c->DMA_TRIG1.MIS;

    return ((*(pReg + (uint32_t) index) & interruptMask));
}

/**
 *  @brief Check interrupt flag of any I2C interrupt for DMA event
 *
 *  Checks if any of the I2C interrupts for DMA receive event are pending.
 *  Interrupts do not have to be previously enabled.
 *  This API checks the event publisher register as selected by
 *  @ref DL_I2C_EVENT_ROUTE, which are used for triggering the DMA for
 *  Controller or Target and receive or transmit events.
 *
 *  @param[in]  i2c            Pointer to the register overlay for the peripheral
 *  @param[in]  index          Specifies the register event publisher to configure
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_I2C_DMA_INTERRUPT.
 *
 *  @return     Which of the requested I2C interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_I2C_DMA_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_I2C_getRawDMAEventStatus(
    I2C_Regs *i2c, DL_I2C_EVENT_ROUTE index, uint32_t interruptMask)
{
    const volatile uint32_t *pReg = &i2c->DMA_TRIG1.RIS;

    return ((*(pReg + (uint32_t) index) & interruptMask));
}

/**
 *  @brief Get highest priority pending I2C interrupt for DMA  event
 *
 *  Checks if any of the I2C interrupts for DMA receive event are pending.
 *  Interrupts do not have to be previously enabled.
 *  This API checks the event publisher register as selected by
 *  @ref DL_I2C_EVENT_ROUTE, which are used for triggering the DMA for
 *  Controller or Target and receive or transmit events.
 *
 *  @param[in]  i2c        Pointer to the register overlay for the peripheral
 *  @param[in]  index      Specifies the register event publisher to configure
 *
 *  @return     The highest priority pending I2C interrupt
 *
 *  @retval     One of @ref DL_I2C_DMA_IIDX
 */
__STATIC_INLINE DL_I2C_DMA_IIDX DL_I2C_getPendingDMAEvent(
    I2C_Regs *i2c, DL_I2C_EVENT_ROUTE index)
{
    const volatile uint32_t *pReg = &i2c->DMA_TRIG1.IIDX;

    return (DL_I2C_DMA_IIDX)((*(pReg + (uint32_t) index)));
}

/**
 *  @brief Clear pending SPI interrupts for DMA events
 *
 *  This API checks the event publisher register as selected by
 *  @ref DL_I2C_EVENT_ROUTE, which are used for triggering the DMA for
 *  Controller or Target and receive or transmit events.
 *
 *  @param[in]  i2c        Pointer to the register overlay for the peripheral
 *  @param[in]  index      Specifies the register event publisher to configure
 *  @param[in]  interrupt  Interrupt to clear. One of @ref DL_I2C_DMA_INTERRUPT
 */
__STATIC_INLINE void DL_I2C_clearDMAEvent(
    I2C_Regs *i2c, DL_I2C_EVENT_ROUTE index, uint32_t interrupt)
{
    switch (index) {
        case DL_I2C_EVENT_ROUTE_1:
            i2c->DMA_TRIG1.ICLR |= interrupt;
            break;
        case DL_I2C_EVENT_ROUTE_2:
            i2c->DMA_TRIG0.ICLR |= interrupt;
            break;
        default:
            break;
    }
}

/**
 *  @brief      Disable analog and digital glitch filter chaining
 *
 *  Chaining is disabled and only digital filter output is available to IP
 *  sampling logic.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableGlitchFilterChaining(I2C_Regs *i2c)
{
    i2c->GFCTL &= ~(I2C_GFCTL_CHAIN_MASK);
}

/**
 *  @brief      Checks if analog and digital glitch filter chaining is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If glitch filter chaining is enabled
 *
 *  @retval     true if glitch filter chaining is enabled
 *  @retval     false if glitch filter chaining is disabled
 */
__STATIC_INLINE bool DL_I2C_isGlitchFilterChainingEnabled(I2C_Regs *i2c)
{
    return ((i2c->GFCTL & I2C_GFCTL_CHAIN_MASK) == I2C_GFCTL_CHAIN_ENABLE);
}

/**
 *  @brief      Enable analog and digitial glitch filter chaining
 *
 *  When enabled, analog and digital glitch filters are chained and the output
 *  of the combination is made available to IP sampling logic.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableGlitchFilterChaining(I2C_Regs *i2c)
{
    i2c->GFCTL |= I2C_GFCTL_CHAIN_ENABLE;
}

/**
 *  @brief      Get the Timeout Counter A value
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     The Timeout A counter value
 *
 *  @retval     Value between [0x0, 0xFF]
 */
__STATIC_INLINE uint32_t DL_I2C_getTimeoutACount(I2C_Regs *i2c)
{
    return (i2c->TIMEOUT_CTL & I2C_TIMEOUT_CTL_TCNTLA_MASK);
}

/**
 *  @brief      Set the Timeout Counter A value
 *
 *  Timeout A is used for SCL low detection. This field contains the upper 8
 *  bits of a 12-bit pre-load value for the Timeout A count.
 *  NOTE: The value of the counter must be greater than 1 to enable the
 *  timeout. Each count is equal to 520 times the timeout period of the
 *  functional clock. For example, with 8MHz functional clock and a
 *  100KHz operating I2C clock, one timeout period will be equal to
 *  (1 / 8MHz) * 520 = 65us.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  count   The value to set the Timeout A counter to.
 *                      Value between [0x0, 0xFF]
 */
__STATIC_INLINE void DL_I2C_setTimeoutACount(I2C_Regs *i2c, uint32_t count)
{
    DL_Common_updateReg(&i2c->TIMEOUT_CTL, count, I2C_TIMEOUT_CTL_TCNTLA_MASK);
}

/**
 *  @brief      Disable Timeout Counter A
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableTimeoutA(I2C_Regs *i2c)
{
    i2c->TIMEOUT_CTL &= ~(I2C_TIMEOUT_CTL_TCNTAEN_MASK);
}

/**
 *  @brief      Checks if Timeout Counter A is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If Timeout Counter A is enabled
 *
 *  @retval     true if Timeout Counter A is enabled
 *  @retval     false if Timeout Counter A is disabled
 */
__STATIC_INLINE bool DL_I2C_isTimeoutAEnabled(I2C_Regs *i2c)
{
    return ((i2c->TIMEOUT_CTL & I2C_TIMEOUT_CTL_TCNTAEN_MASK) ==
            I2C_TIMEOUT_CTL_TCNTAEN_ENABLE);
}

/**
 *  @brief      Enable Timeout Counter A
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableTimeoutA(I2C_Regs *i2c)
{
    i2c->TIMEOUT_CTL |= I2C_TIMEOUT_CTL_TCNTAEN_ENABLE;
}

/**
 *  @brief      Get the current Timer Counter A value
 *
 *  This field contains the upper 8 bits of a 12-bit current counter for
 *  Timeout Counter A.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     The Timeout A counter value
 *
 *  @retval     Value between [0x0, 0xFF]
 */
__STATIC_INLINE uint32_t DL_I2C_getCurrentTimeoutACounter(I2C_Regs *i2c)
{
    return (i2c->TIMEOUT_CNT & I2C_TIMEOUT_CNT_TCNTA_MASK);
}

/**
 *  @brief      Get the Timeout Counter B value
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     The Timeout B counter value
 *
 *  @retval     Value between [0x0, 0xFF]
 */
__STATIC_INLINE uint32_t DL_I2C_getTimeoutBCount(I2C_Regs *i2c)
{
    return ((i2c->TIMEOUT_CTL & I2C_TIMEOUT_CTL_TCNTLB_MASK) >>
            I2C_TIMEOUT_CTL_TCNTLB_OFS);
}

/**
 *  @brief      Set the Timeout Counter B value
 *
 *  Timeout B is used for SCL high detection. This field contains the upper 8
 *  bits of a 12-bit pre-load value for the Timeout A count.
 *  NOTE: The value of the counter must be greater than 1 to enable the
 *  timeout. Each count is equal to 1* clock period. For example, with 10MHz
 *  functional clock one timeout period will be equal to 1 * 10ns.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  count   The value to set the Timeout A counter to.
 *                      Value between [0x0, 0xFF]
 */
__STATIC_INLINE void DL_I2C_setTimeoutBCount(I2C_Regs *i2c, uint32_t count)
{
    DL_Common_updateReg(&i2c->TIMEOUT_CTL,
        (count << I2C_TIMEOUT_CTL_TCNTLB_OFS), I2C_TIMEOUT_CTL_TCNTLB_MASK);
}

/**
 *  @brief      Disable Timeout Counter B
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_disableTimeoutB(I2C_Regs *i2c)
{
    i2c->TIMEOUT_CTL &= ~(I2C_TIMEOUT_CTL_TCNTBEN_MASK);
}

/**
 *  @brief      Checks if Timeout Counter B is enabled
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     If Timeout Counter B is enabled
 *
 *  @retval     true if Timeout Counter B is enabled
 *  @retval     false if Timeout Counter B is disabled
 */
__STATIC_INLINE bool DL_I2C_isTimeoutBEnabled(I2C_Regs *i2c)
{
    return ((i2c->TIMEOUT_CTL & I2C_TIMEOUT_CTL_TCNTBEN_MASK) ==
            I2C_TIMEOUT_CTL_TCNTBEN_ENABLE);
}

/**
 *  @brief      Enable Timeout Counter B
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_I2C_enableTimeoutB(I2C_Regs *i2c)
{
    i2c->TIMEOUT_CTL |= I2C_TIMEOUT_CTL_TCNTBEN_ENABLE;
}

/**
 *  @brief      Get the current Timer Counter B value
 *
 *  This field contains the upper 8 bits of a 12-bit current counter for
 *  Timeout Counter B.
 *
 *  @param[in]  i2c     Pointer to the register overlay for the peripheral
 *
 *  @return     The Timeout B counter value
 *
 *  @retval     Value between [0x0, 0xFF]
 */
__STATIC_INLINE uint32_t DL_I2C_getCurrentTimeoutBCounter(I2C_Regs *i2c)
{
    return (i2c->TIMEOUT_CNT & I2C_TIMEOUT_CNT_TCNTB_MASK);
}

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_I2C__ */

#endif /* ti_dl_dl_i2c__include */
/** @}*/
