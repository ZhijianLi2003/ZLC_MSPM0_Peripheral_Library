/*
 * Copyright (c) 2021, Texas Instruments Incorporated
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
 *  @file       dl_mcan.h
 *  @brief      Modular Controller Area Network (MCAN) Driver Library
 *  @defgroup   MCAN Modular Controller Area Network (MCAN)
 *
 *  @anchor ti_dl_dl_mcan_Overview
 *  # Overview
 *
 *  The MCAN Driver Library allows full configuration of the MSPM0 MCAN (CAN-FD)
 *  module.
 *  The Modular Controller Area Network (MCAN) peripheral supports both
 *  communication through classic CAN and CAN-FD protocols.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup MCAN
 * @{
 */
#ifndef ti_dl_dl_mcan__include
#define ti_dl_dl_mcan__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_MCAN__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/**
 *  @brief  Macro defines mask for all the interrupts status for MCAN.
 */
#define DL_MCAN_INTR_MASK_ALL (MCAN_IR_RF0N_MASK |                          \
                               MCAN_IR_RF0W_MASK |                          \
                               MCAN_IR_RF0F_MASK |                          \
                               MCAN_IR_RF0L_MASK |                          \
                               MCAN_IR_RF1N_MASK |                          \
                               MCAN_IR_RF1W_MASK |                          \
                               MCAN_IR_RF1F_MASK |                          \
                               MCAN_IR_RF1L_MASK |                          \
                               MCAN_IR_HPM_MASK  |                          \
                               MCAN_IR_TC_MASK   |                          \
                               MCAN_IR_TCF_MASK  |                          \
                               MCAN_IR_TFE_MASK  |                          \
                               MCAN_IR_TEFN_MASK |                          \
                               MCAN_IR_TEFW_MASK |                          \
                               MCAN_IR_TEFF_MASK |                          \
                               MCAN_IR_TEFL_MASK |                          \
                               MCAN_IR_TSW_MASK  |                          \
                               MCAN_IR_MRAF_MASK |                          \
                               MCAN_IR_TOO_MASK  |                          \
                               MCAN_IR_DRX_MASK  |                          \
                               MCAN_IR_BEU_MASK  |                          \
                               MCAN_IR_ELO_MASK  |                          \
                               MCAN_IR_EP_MASK   |                          \
                               MCAN_IR_EW_MASK   |                          \
                               MCAN_IR_BO_MASK   |                          \
                               MCAN_IR_WDI_MASK  |                          \
                               MCAN_IR_PEA_MASK  |                          \
                               MCAN_IR_PED_MASK  |                          \
                               MCAN_IR_ARA_MASK)

/**
 *  @brief  Maximum payload supported by CAn-FD protocol in bytes.
 */
#define DL_MCAN_MAX_PAYLOAD_BYTES                                          (64U)


/** @addtogroup DL_MCAN_INTERRUPT
 *  @{
 */
/*!
 * @brief Access to Reserved Address interrupt
 */
#define DL_MCAN_INTERRUPT_ARA                                 (MCAN_IR_ARA_MASK)

/*!
 * @brief Protocol Error in Data Phase interrupt
 */
#define DL_MCAN_INTERRUPT_PED                                 (MCAN_IR_PED_MASK)

/*!
 * @brief Protocol Error in Arbitration Phase interrupt
 */
#define DL_MCAN_INTERRUPT_PEA                                 (MCAN_IR_PEA_MASK)

/*!
 * @brief Watchdog interrupt
 */
#define DL_MCAN_INTERRUPT_WDI                                 (MCAN_IR_WDI_MASK)

/*!
 * @brief Bus_Off Status interrupt
 */
#define DL_MCAN_INTERRUPT_BO                                   (MCAN_IR_BO_MASK)

/*!
 * @brief Warning Status interrupt
 */
#define DL_MCAN_INTERRUPT_EW                                 (MCAN_IR_EW_MASK)

/*!
 * @brief Error Passive interrupt
 */
#define DL_MCAN_INTERRUPT_EP                                 (MCAN_IR_EP_MASK)

/*!
 * @brief Error Logging Overflow interrupt
 */
#define DL_MCAN_INTERRUPT_ELO                                 (MCAN_IR_ELO_MASK)

/*!
 * @brief Bit Error Uncorrected. Message RAM bit error detected, uncorrected interrupt
 */
#define DL_MCAN_INTERRUPT_BEU                                 (MCAN_IR_BEU_MASK)

/*!
 * @brief Message Stored to Dedicated Rx Buffer interrupt
 */
#define DL_MCAN_INTERRUPT_DRX                                 (MCAN_IR_DRX_MASK)

/*!
 * @brief Timeout Occurred interrupt
 */
#define DL_MCAN_INTERRUPT_TOO                                 (MCAN_IR_TOO_MASK)

/*!
 * @brief Message RAM Access Failure interrupt
 */
#define DL_MCAN_INTERRUPT_MRAF                               (MCAN_IR_MRAF_MASK)

/*!
 * @brief Timestamp Wraparound interrupt
 */
#define DL_MCAN_INTERRUPT_TSW                                 (MCAN_IR_TSW_MASK)

/*!
 * @brief Tx Event FIFO Element Lost interrupt
 */
#define DL_MCAN_INTERRUPT_TEFL                               (MCAN_IR_TEFL_MASK)

/*!
 * @brief Tx Event FIFO Full interrupt
 */
#define DL_MCAN_INTERRUPT_TEFF                               (MCAN_IR_TEFF_MASK)

/*!
 * @brief Tx Event FIFO Watermark Reached interrupt
 */
#define DL_MCAN_INTERRUPT_TEFW                               (MCAN_IR_TEFW_MASK)

/*!
 * @brief Tx Event FIFO New Entry interrupt
 */
#define DL_MCAN_INTERRUPT_TEFN                               (MCAN_IR_TEFN_MASK)

/*!
 * @brief Tx FIFO Empty interrupt
 */
#define DL_MCAN_INTERRUPT_TFE                                 (MCAN_IR_TFE_MASK)

/*!
 * @brief Transmission Cancellation Finished interrupt
 */
#define DL_MCAN_INTERRUPT_TCF                                 (MCAN_IR_TCF_MASK)

/*!
 * @brief Transmission Completed interrupt
 */
#define DL_MCAN_INTERRUPT_TC                                   (MCAN_IR_TC_MASK)

/*!
 * @brief High Priority Message interrupt
 */
#define DL_MCAN_INTERRUPT_HPM                                 (MCAN_IR_HPM_MASK)

/*!
 * @brief Rx FIFO 1 Message Lost interrupt
 */
#define DL_MCAN_INTERRUPT_RF1L                               (MCAN_IR_RF1L_MASK)

/*!
 * @brief Rx FIFO 1 Full interrupt
 */
#define DL_MCAN_INTERRUPT_RF1F                               (MCAN_IR_RF1F_MASK)

/*!
 * @brief Rx FIFO 1 Watermark Reached interrupt
 */
#define DL_MCAN_INTERRUPT_RF1W                               (MCAN_IR_RF1W_MASK)

/*!
 * @brief Rx FIFO 1 New Message interrupt
 */
#define DL_MCAN_INTERRUPT_RF1N                               (MCAN_IR_RF1N_MASK)

/*!
 * @brief Rx FIFO 0 Message Lost interrupt
 */
#define DL_MCAN_INTERRUPT_RF0L                               (MCAN_IR_RF0L_MASK)

/*!
 * @brief Rx FIFO 0 Full interrupt
 */
#define DL_MCAN_INTERRUPT_RF0F                               (MCAN_IR_RF0F_MASK)

/*!
 * @brief Rx FIFO 0 Watermark interrupt
 */
#define DL_MCAN_INTERRUPT_RF0W                               (MCAN_IR_RF0W_MASK)

/*!
 * @brief Rx FIFO 0 New Message interrupt
 */
#define DL_MCAN_INTERRUPT_RF0N                               (MCAN_IR_RF0N_MASK)

/** @}*/

/** @addtogroup DL_MCAN_MSP_INTERRUPT
 *  @{
 */
/*!
 * @brief Clock Stop Wake Up interrupt
 */
#define DL_MCAN_MSP_INTERRUPT_WAKEUP                     (MCAN_IMASK_WAKEUP_SET)

/*!
 * @brief External Timestamp Counter Overflow interrupt
 */
#define DL_MCAN_MSP_INTERRUPT_TIMESTAMP_OVERFLOW (MCAN_IMASK_EXT_TS_CNTR_OVFL_SET)

/*!
 * @brief Message RAM Double Error Detection interrupt
 */
#define DL_MCAN_MSP_INTERRUPT_DOUBLE_ERROR_DETECTION        (MCAN_IMASK_DED_SET)

/*!
 * @brief Message RAM Single Error Correction interrupt
 */
#define DL_MCAN_MSP_INTERRUPT_SINGLE_ERROR_CORRECTION       (MCAN_IMASK_SEC_SET)

/*!
 * @brief MCAN Interrupt Line 1
 */
#define DL_MCAN_MSP_INTERRUPT_LINE1                       (MCAN_IMASK_INTL1_SET)

/*!
 * @brief MCAN Interrupt Line 0
 */
#define DL_MCAN_MSP_INTERRUPT_LINE0                       (MCAN_IMASK_INTL0_SET)

/** @}*/

/** @addtogroup DL_MCAN_INTR_SRC
 *  @{
 */
/*!
 * @brief Rx FIFO 0 New Message interrupt
 */
#define DL_MCAN_INTR_SRC_RX_FIFO0_NEW_MSG                    (MCAN_IR_RF0N_MASK)

/*!
 * @brief Rx FIFO 0 Watermark Reached interrupt
 */
#define DL_MCAN_INTR_SRC_RX_FIFO0_WATERMARK                  (MCAN_IR_RF0W_MASK)

/*!
 * @brief Rx FIFO 0 Full interrupt
 */
#define DL_MCAN_INTR_SRC_RX_FIFO0_FULL                       (MCAN_IR_RF0F_MASK)

/*!
 * @brief Rx FIFO 0 Message Lost interrupt
 */
#define DL_MCAN_INTR_SRC_RX_FIFO0_MSG_LOST                   (MCAN_IR_RF0L_MASK)

/*!
 * @brief Rx FIFO 1 New Message interrupt
 */
#define DL_MCAN_INTR_SRC_RX_FIFO1_NEW_MSG                    (MCAN_IR_RF1N_MASK)

/*!
 * @brief Rx FIFO 1 Watermark Reached interrupt
 */
#define DL_MCAN_INTR_SRC_RX_FIFO1_WATERMARK                  (MCAN_IR_RF1W_MASK)

/*!
 * @brief Rx FIFO 1 Full interrupt
 */
#define DL_MCAN_INTR_SRC_RX_FIFO1_FULL                       (MCAN_IR_RF1F_MASK)

/*!
 * @brief Rx FIFO 1 Message Lost interrupt
 */
#define DL_MCAN_INTR_SRC_RX_FIFO1_MSG_LOST                   (MCAN_IR_RF1L_MASK)

/*!
 * @brief High Priority Message interrupt
 */
#define DL_MCAN_INTR_SRC_HIGH_PRIO_MSG                        (MCAN_IR_HPM_MASK)

/*!
 * @brief Transmission Completed interrupt
 */
#define DL_MCAN_INTR_SRC_TRANS_COMPLETE                        (MCAN_IR_TC_MASK)

/*!
 * @brief Transmission Cancellation Finished interrupt
 */
#define DL_MCAN_INTR_SRC_TRANS_CANCEL_FINISH                  (MCAN_IR_TCF_MASK)

/*!
 * @brief Tx FIFO Empty interrupt
 */
#define DL_MCAN_INTR_SRC_TX_FIFO_EMPTY                        (MCAN_IR_TFE_MASK)

/*!
 * @brief Tx Event FIFO New Entry interrupt
 */
#define DL_MCAN_INTR_SRC_TX_EVT_FIFO_NEW_ENTRY               (MCAN_IR_TEFN_MASK)

/*!
 * @brief Tx Event FIFO Watermark Reached interrupt
 */
#define DL_MCAN_INTR_SRC_TX_EVT_FIFO_WATERMARK               (MCAN_IR_TEFW_MASK)

/*!
 * @brief Tx Event FIFO Full interrupt
 */
#define DL_MCAN_INTR_SRC_TX_EVT_FIFO_FULL                    (MCAN_IR_TEFF_MASK)

/*!
 * @brief Tx Event FIFO Element Lost interrupt
 */
#define DL_MCAN_INTR_SRC_TX_EVT_FIFO_ELEM_LOST               (MCAN_IR_TEFL_MASK)

/*!
 * @brief Timestamp Wraparound interrupt
 */
#define DL_MCAN_INTR_SRC_TIMESTAMP_WRAPAROUND                 (MCAN_IR_TSW_MASK)

/*!
 * @brief Message RAM Access Failure interrupt
 */
#define DL_MCAN_INTR_SRC_MSG_RAM_ACCESS_FAILURE              (MCAN_IR_MRAF_MASK)

/*!
 * @brief Timeout Occurred interrupt
 */
#define DL_MCAN_INTR_SRC_TIMEOUT                              (MCAN_IR_TOO_MASK)

/*!
 * @brief Message stored to Dedicated Rx Buffer interrupt
 */
#define DL_MCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG                (MCAN_IR_DRX_MASK)

/*!
 * @brief Bit Error Uncorrected interrupt
 */
#define DL_MCAN_INTR_SRC_BIT_ERR_UNCORRECTED                  (MCAN_IR_BEU_MASK)

/*!
 * @brief Error Logging Overflow interrupt
 */
#define DL_MCAN_INTR_SRC_ERR_LOG_OVRFLW                       (MCAN_IR_ELO_MASK)

/*!
 * @brief Error Passive interrupt
 */
#define DL_MCAN_INTR_SRC_ERR_PASSIVE                           (MCAN_IR_EP_MASK)

/*!
 * @brief Warning Status interrupt
 */
#define DL_MCAN_INTR_SRC_WARNING_STATUS                        (MCAN_IR_EW_MASK)

/*!
 * @brief Bus_Off Status interrupt
 */
#define DL_MCAN_INTR_SRC_BUS_OFF_STATUS                        (MCAN_IR_BO_MASK)

/*!
 * @brief Watchdog Interrupt interrupt
 */
#define DL_MCAN_INTR_SRC_WATCHDOG                             (MCAN_IR_WDI_MASK)

/*!
 * @brief Protocol Error in Arbitration Phase interrupt
 */
#define DL_MCAN_INTR_SRC_PROTOCOL_ERR_ARB                     (MCAN_IR_PEA_MASK)

/*!
 * @brief Protocol Error in Data Phase interrupt
 */
#define DL_MCAN_INTR_SRC_PROTOCOL_ERR_DATA                    (MCAN_IR_PED_MASK)

/*!
 * @brief Access to Reserved Address interrupt
 */
#define DL_MCAN_INTR_SRC_RES_ADDR_ACCESS                      (MCAN_IR_ARA_MASK)

/** @}*/

/* User defined ranges */
/*!
 * @brief Maximum data synch jump width
 */
#define DL_MCAN_DBTP_DSJW_MAX                                             (0xFU)
/*!
 *  @brief Max data time segment 2
 */
#define DL_MCAN_DBTP_DTSEG2_MAX                                           (0xFU)
/*!
 *  @brief Max data time segment 1
 */
#define DL_MCAN_DBTP_DTSEG1_MAX                                          (0x1FU)
/*!
 *  @brief Max data date rate prescalar
 */
#define DL_MCAN_DBTP_DBRP_MAX                                            (0x1FU)
/*!
 *  @brief Max nom synch jump width
 */
#define DL_MCAN_NBTP_NSJW_MAX                                            (0x7FU)
/*!
 *  @brief Max nom synch time segment 2
 */
#define DL_MCAN_NBTP_NTSEG2_MAX                                          (0x7FU)
/*!
 *  @brief Max nom synch time segment 1
 */
#define DL_MCAN_NBTP_NTSEG1_MAX                                          (0xFFU)
/*!
 *  @brief Max nom data date rate prescalar
 */
#define DL_MCAN_NBTP_NBRP_MAX                                           (0x1FFU)
/*!
 *  @brief Max wdc preload
 */
#define DL_MCAN_RWD_WDC_MAX                                              (0xFFU)
/*!
 *  @brief Transmitter Delay Compensation Filter Window Length
 */
#define DL_MCAN_TDCR_TDCF_MAX                                            (0x7FU)
/*!
 *  @brief Transmitter Delay Compensation Offset
 */
#define DL_MCAN_TDCR_TDCO_MAX                                            (0x7FU)
/*!
 *  @brief Max MCAN extended id mask
 */
#define DL_MCAN_XIDAM_EIDM_MAX                                     (0x1FFFFFFFU)
/*!
 *  @brief Max timestamp counter prescaler
 */
#define DL_MCAN_TSCC_TCP_MAX                                              (0xFU)
/*!
 *  @brief Max timeout preload
 */
#define DL_MCAN_TOCC_TOP_MAX                                           (0xFFFFU)

/* clang-format on */

/**
 *  @brief   Enum to select the MCAN instance
 */
typedef enum {
    /*! Selects CANFD instance 0 of device */
    DL_MCAN_INSTANCE_0 = SYSCTL_SYSSTATUS_MCAN0READY_MASK,
} DL_MCAN_INSTANCE;

/**
 *  @brief   Enum to select source clock for CANCLK
 */
typedef enum {
    /*! Selects SYSPLLCLK1 as the source clock for CANCLK */
    DL_MCAN_FCLK_SYSPLLCLK1 = SYSCTL_GENCLKCFG_CANCLKSRC_SYSPLLOUT1,
    /*! Selects HFCLK as the source clock for CANCLK */
    DL_MCAN_FCLK_HFCLK = SYSCTL_GENCLKCFG_CANCLKSRC_HFCLK,
} DL_MCAN_FCLK;

/**
 *  @brief   Enum to select CANCLK divider
 */
typedef enum {
    /*! Clock divider 1 */
    DL_MCAN_FCLK_DIV_1 = MCAN_CLKDIV_RATIO_DIV_BY_1_,
    /*! Clock divider 2 */
    DL_MCAN_FCLK_DIV_2 = MCAN_CLKDIV_RATIO_DIV_BY_2_,
    /*! Clock divider 4 */
    DL_MCAN_FCLK_DIV_4 = MCAN_CLKDIV_RATIO_DIV_BY_4_,
} DL_MCAN_FCLK_DIV;

/**
 *  @brief   Enum to select the MCAN interrupt lines
 */
typedef enum {
    /*! MCAN interrupt line 0 */
    DL_MCAN_INTR_LINE_NUM_0 = 0U,
    /*! MCAN interrupt line 1 */
    DL_MCAN_INTR_LINE_NUM_1 = 1U

} DL_MCAN_INTR_LINE_NUM;

/**
 *  @brief   Enum to represent the MCAN Identifier Type
 */
typedef enum {

    /*! 11bit MCAN Identifier */
    DL_MCAN_ID_TYPE_11_BIT = 0U,
    /*! 29bit MCAN Identifier */
    DL_MCAN_ID_TYPE_29_BIT = 1U

} DL_MCAN_ID_TYPE;

/**
 *  @brief   Enum to represent the MCAN mode of operation
 */
typedef enum {
    /*! MCAN normal mode */
    DL_MCAN_OPERATION_MODE_NORMAL = 0U,
    /*! MCAN SW initialization mode */
    DL_MCAN_OPERATION_MODE_SW_INIT = 1U

} DL_MCAN_OPERATION_MODE;

/**
 *  @brief   Enum to represent the MCAN Message RAM type.
 */
typedef enum {
    /*! MCAN Msg RAM buffers */
    DL_MCAN_MEM_TYPE_BUF = 0U,
    /*! MCAN Msg RAM FIFO/Queue */
    DL_MCAN_MEM_TYPE_FIFO = 1U

} DL_MCAN_MEM_TYPE;

/**
 *  @brief   Enum to represent the MCAN Rx FIFO number
 */
typedef enum {
    /*! MCAN Rx FIFO 0 */
    DL_MCAN_RX_FIFO_NUM_0 = 0U,
    /*! MCAN Rx FIFO 1 */
    DL_MCAN_RX_FIFO_NUM_1 = 1U
} DL_MCAN_RX_FIFO_NUM;

/**
 *  @brief   Enum to represent the MCAN pin type
 */
typedef enum {
    /*! MCAN Rx Pin */
    DL_MCAN_PIN_TYPE_RX = 0U,
    /*! MCAN Tx Pin */
    DL_MCAN_PIN_TYPE_TX = 1U
} DL_MCAN_PIN_TYPE;

/**
 *  @brief   Enum to represent FIFO/Buffer element Size
 */
typedef enum {
    /*! 8 byte data field */
    DL_MCAN_ELEM_SIZE_8BYTES = 0U,
    /*! 12 byte data field */
    DL_MCAN_ELEM_SIZE_12BYTES = 1U,
    /*! 16 byte data field */
    DL_MCAN_ELEM_SIZE_16BYTES = 2U,
    /*! 20 byte data field */
    DL_MCAN_ELEM_SIZE_20BYTES = 3U,
    /*! 24 byte data field */
    DL_MCAN_ELEM_SIZE_24BYTES = 4U,
    /*! 32 byte data field */
    DL_MCAN_ELEM_SIZE_32BYTES = 5U,
    /*! 48 byte data field */
    DL_MCAN_ELEM_SIZE_48BYTES = 6U,
    /*! 64 byte data field */
    DL_MCAN_ELEM_SIZE_64BYTES = 7U
} DL_MCAN_ELEM_SIZE;

/**
 *  @brief   Enum to represent the MCAN time-out counter configuration
 */
typedef enum {
    /*! Continuous operation Mode */
    DL_MCAN_TIMEOUT_SELECT_CONT = 0U,
    /*! Timeout controlled by Tx Event FIFO */
    DL_MCAN_TIMEOUT_SELECT_TX_EVENT_FIFO = 1U,
    /*! Timeout controlled by Rx FIFO 0 */
    DL_MCAN_TIMEOUT_SELECT_RX_FIFO0 = 2U,
    /*! Timeout controlled by Rx FIFO 1 */
    DL_MCAN_TIMEOUT_SELECT_RX_FIFO1 = 3U

} DL_MCAN_TIMEOUT_SELECT;

/**
 *  @brief   Enum to select the MCAN instance
 */
typedef enum {
    /*! MCAN interrupt source was triggered by external time stamp*/
    DL_MCAN_INTR_SRC_MCAN_EXT_TS = 0x0,
    /*! MCAN interrupt source was triggered by Line 0 */
    DL_MCAN_INTR_SRC_MCAN_LINE_0 = 0x1,
    /*! MCAN interrupt source was triggered by Line 1 */
    DL_MCAN_INTR_SRC_MCAN_LINE_1 = 0x2,
} DL_MCAN_INTR_SRC_MCAN;

/**
 *  @brief   Enum to represent the ECC Error Types
 */
typedef enum {
    /*! ECC Single Error Correction */
    DL_MCAN_ECC_ERR_TYPE_SEC = 0U,
    /*! ECC Single Error Detection */
    DL_MCAN_ECC_ERR_TYPE_DED = 1U

} DL_MCAN_ECC_ERR_TYPE;

/**
 *  @brief   Enum to select the MCAN Loopback mode
 */
typedef enum {
    /*! Internal Loop Back Mode
     *   This mode can be used for hot self-test and this mode will not
     *   affect bus state.
     */
    DL_MCAN_LPBK_MODE_INTERNAL = 0U,
    /*! External Loop Back Mode
    *   In this mode, MCAN the M_CAN treats its own
    *   transmitted messages as
    *   received messages and stores them (if they
    *   pass acceptance filtering)
    *   into an Rx Buffer or an Rx FIFO.
    *   This mode will affect bus state
    */
    DL_MCAN_LPBK_MODE_EXTERNAL = 1U

} DL_MCAN_LPBK_MODE;

/**
 *  @brief   Enum to represent MCAN's communication state
 */
typedef enum {
    /*! MCAN is synchronizing on CAN communication */
    DL_MCAN_COM_STATE_SYNCHRONIZING = 0U,
    /*! MCAN is neither receiver nor transmitter */
    DL_MCAN_COM_STATE_IDLE = 1U,
    /*! MCAN is operating as receiver */
    DL_MCAN_COM_STATE_RECEIVER = 2U,
    /*! MCAN is operating as transmitter */
    DL_MCAN_COM_STATE_TRANSMITTER = 3U
} DL_MCAN_COM_STATE;

/**
 *  @brief   Enum to represent MCAN's Error Code
 */
typedef enum {
    /*! No error occurred since LEC has been reset by
     *   successful reception or transmission.
     */
    DL_MCAN_ERR_CODE_NO_ERROR = 0U,
    /*! More than 5 equal bits in a sequence have occurred in a part of
     *   a received message where this is not allowed.
     */
    DL_MCAN_ERR_CODE_STUFF_ERROR = 1U,
    /*! A fixed format part of a received frame has the wrong format. */
    DL_MCAN_ERR_CODE_FORM_ERROR = 2U,
    /*! The message transmitted by the M_CAN was not acknowledged
     *   by another node.
     */
    DL_MCAN_ERR_CODE_ACK_ERROR = 3U,
    /*! During the transmission of a message (with the exception of
     *   the arbitration field), the device wanted to send a
     *   recessive level (bit of logical value 1),
     *  but the monitored bus value was dominant.
     */
    DL_MCAN_ERR_CODE_BIT1_ERROR = 4U,
    /*! During the transmission of a message (or acknowledge bit,
     *   or active error flag, or overload flag), the device wanted to send
     *   a dominant level (data or identifier bit logical value 0),
     *   but the monitored bus value was recessive. During Bus_Off recovery
     *   this status is set each time a sequence of 11 recessive bits has been
     *   monitored. This enables the CPU to monitor the proceeding of
     *   the Bus_Off recovery sequence (indicating the bus is not stuck at
     *   dominant or continuously disturbed).
     */
    DL_MCAN_ERR_CODE_BIT0_ERROR = 5U,
    /*! The CRC check sum of a received message was incorrect.
     *   The CRC of an incoming message does not match with the
     *   CRC calculated from the received data.
     */
    DL_MCAN_ERR_CODE_CRC_ERROR = 6U,
    /*! Any read access to the Protocol Status Register re-initializes
     * the LEC to 7. When the LEC shows the value 7,no CAN bus event was
     * detected since the last CPU read access to the Protocol Status Register.
     */
    DL_MCAN_ERR_CODE_NO_CHANGE = 7U

} DL_MCAN_ERR_CODE;

/**
 *  @brief  Structure for CANCLK configuration.
 */
typedef struct {
    /*! Specifies the clock source for MCAN_FCLK (CANCLK). One of
        @ref DL_MCAN_FCLK */
    DL_MCAN_FCLK clockSel;
    /*! Specifies clock divider for CANCLK. One of @ref DL_MCAN_FCLK_DIV */
    DL_MCAN_FCLK_DIV divider;
} DL_MCAN_ClockConfig;

/**
 *  @brief  Structure for bit timing calculation.
 *         Bit timing related to data phase will be valid only in case where
 *         MCAN is put in CAN-FD mode and will be '0' otherwise.
 */
typedef struct {
    /*! Nominal Baud Rate Pre-scaler
     *   Range:[0x0-0x1FF]
     */
    uint32_t nomRatePrescalar;
    /*! Nominal Time segment before sample point
     *   Range:[0x0-0xFF]
     */
    uint32_t nomTimeSeg1;
    /*! Nominal Time segment after sample point
     *   Range:[0x0-0x7F]
     */
    uint32_t nomTimeSeg2;
    /*! Nominal (Re)Synchronization Jump Width
     *   Range:[0x0-0x7F]
     */
    uint32_t nomSynchJumpWidth;
    /*! Data Baud Rate Pre-scaler
     *   Range:[0x0-0x1F]
     */
    uint32_t dataRatePrescalar;
    /*! Data Time segment before sample point
     *   Range:[0x0-0x1F]
     */
    uint32_t dataTimeSeg1;
    /*! Data Time segment after sample point
     *   Range:[0x0-0xF]
     */
    uint32_t dataTimeSeg2;
    /*! Data (Re)Synchronization Jump Width
     *   Range:[0x0-0xF]
     */
    uint32_t dataSynchJumpWidth;
} DL_MCAN_BitTimingParams;

/**
 *  @brief  Structure for MCAN Transmitter Delay Compensation parameters.
 */
typedef struct {
    /*! Transmitter Delay Compensation Filter Window Length
     *   Range:[0x0-0x7F]
     */
    uint32_t tdcf;
    /*! Transmitter Delay Compensation Offset
     *   Range:[0x0-0x7F]
     */
    uint32_t tdco;
} DL_MCAN_TDCConfig;

/**
 *  @brief  Structure for MCAN Global Filter Configuration parameters.
 */
typedef struct {
    /*! Reject Remote Frames Extended
     *   0 = Filter remote frames with 29-bit extended IDs
     *   1 = Reject all remote frames with 29-bit extended IDs
     */
    uint32_t rrfe;
    /*! Reject Remote Frames Standard
     *   0 = Filter remote frames with 11-bit standard IDs
     *   1 = Reject all remote frames with 11-bit standard IDs
     */
    uint32_t rrfs;
    /*! Accept Non-matching Frames Extended
     *   0 = Accept in Rx FIFO 0
     *   1 = Accept in Rx FIFO 1
     *   others = Reject
     */
    uint32_t anfe;
    /*! Accept Non-matching Frames Standard
     *   0 = Accept in Rx FIFO 0
     *   1 = Accept in Rx FIFO 1
     *   others = Reject
     */
    uint32_t anfs;
} DL_MCAN_GlobalFiltConfig;

/**
 *  @brief  Structure for MCAN initialization parameters.
 */
typedef struct {
    /*! CAN-FD Operation Enable
     *   0 = FD operation disabled (Operates in CAN Classic mode)
     *   1 = FD operation enabled
     */
    uint32_t fdMode;
    /*! Bit Rate Switch Enable
     *   This is valid only when CAN-FD operation is enabled (fdMode = 1).
     *   0 = Bit rate switching for transmissions disabled
     *   1 = Bit rate switching for transmissions enabled
     */
    uint32_t brsEnable;
    /*! Transmit Pause. MCAN pauses for two CAN bit times before starting the
     *  next transmission after itself has successfully transmitted a frame
     *   0 = Transmit pause disabled
     *   1 = Transmit pause enabled
     */
    uint32_t txpEnable;
    /*! Edge Filtering during Bus Integration
     *   0 = Edge filtering disabled
     *   1 = Two consecutive dominant tq required to detect an edge for
     *       hard synchronization
     */
    uint32_t efbi;
    /*! Protocol Exception Handling. When protocol exception handling is
     *  disabled, the MCAN will transmit an error frame when it detects a
     *  protocol exception condition.
     *   0 = Protocol exception handling enabled
     *   1 = Protocol exception handling disabled
     */
    uint32_t pxhddisable;
    /*! Disable Automatic Retransmission
     *   0 = Automatic retransmission of messages not transmitted successfully
     *       enabled
     *   1 = Automatic retransmission disabled
     */
    uint32_t darEnable;
    /*! Wakeup Request Enable
     *   0 = Wakeup request is disabled
     *   1 = Wakeup request is enabled
     */
    uint32_t wkupReqEnable;
    /*! Auto-Wakeup Enable
     *   0 = Auto-Wakeup is disabled
     *   1 = Auto-Wakeup is enabled
     */
    uint32_t autoWkupEnable;
    /*! Emulation/Debug Suspend Enable
     *   0 = Emulation/Debug Suspend is disabled
     *   1 = Emulation/Debug Suspend is enabled
     */
    uint32_t emulationEnable;
    /*! Start value of the Message RAM Watchdog Counter
     *   Range:[0x0-0xFF]
     */
    uint32_t wdcPreload;
    /*! Transmitter Delay Compensation parameters.
     *   @ref DL_MCAN_TDCConfig.
     */
    DL_MCAN_TDCConfig tdcConfig;
    /*! Transmitter Delay Compensation Enable
     *   0 = Transmitter Delay Compensation is disabled
     *   1 = Transmitter Delay Compensation is enabled
     */
    uint32_t tdcEnable;
} DL_MCAN_InitParams;

/**
 *  @brief  Structure for MCAN configuration parameters.
 */
typedef struct {
    /*! Bus Monitoring Mode
     *   0 = Bus Monitoring Mode is disabled
     *   1 = Bus Monitoring Mode is enabled
     */
    uint32_t monEnable;
    /*! Restricted Operation Mode
     *   0 = Normal CAN operation
     *   1 = Restricted Operation Mode active
     *   This mode should not be combined with test modes.
     */
    uint32_t asmEnable;
    /*! Timestamp Counter Prescaler.
     *   Range:[0x0-0xF]
     */
    uint32_t tsPrescalar;
    /*! Timestamp source selection.
     *   00= Timestamp counter value always 0x0000
     *   01= Timestamp counter value incremented according to tsPrescalar
     *   10= External timestamp counter value used
     *   11= Same as 0b00
     */
    uint32_t tsSelect;
    /*! Time-out counter source select.
     *   One of @ref DL_MCAN_TIMEOUT_SELECT.
     */
    uint32_t timeoutSelect;
    /*! Start value of the Timeout Counter (down-counter).
     *   The Timeout Counter is decremented in multiples of CAN bit times [1-16]
     *   depending on the configuration of the tsPrescalar.
     *   Range:[0x0-0xFFFF]
     */
    uint32_t timeoutPreload;
    /*! Time-out Counter Enable
     *   0 = Time-out Counter is disabled
     *   1 = Time-out Counter is enabled
     */
    uint32_t timeoutCntEnable;
    /*! Global Filter Configuration parameters.
     *    @ref DL_MCAN_GlobalFiltConfig.
     */
    DL_MCAN_GlobalFiltConfig filterConfig;
} DL_MCAN_ConfigParams;

/**
 *  @brief  Structure for MCAN error logging counters status.
 */
typedef struct {
    /*! Transmit Error Counter */
    uint32_t transErrLogCnt;
    /*! Receive Error Counter */
    uint32_t recErrCnt;
    /*! Receive Error Passive
     *   0 = The Receive Error Counter is below the error passive level(128)
     *   1 = The Receive Error Counter has reached the error passive level(128)
     */
    uint32_t rpStatus;
    /*! CAN Error Logging */
    uint32_t canErrLogCnt;
} DL_MCAN_ErrCntStatus;

/**
 *  @brief  Structure for MCAN protocol status.
 */
typedef struct {
    /*! Last Error Code
     *   One of @ref DL_MCAN_ERR_CODE
     */
    uint32_t lastErrCode;
    /*! Activity - Monitors the module's CAN communication state.
     *   One of @ref DL_MCAN_COM_STATE
     */
    uint32_t act;
    /*! Error Passive
     *   0 = The M_CAN is in the Error_Active state
     *   1 = The M_CAN is in the Error_Passive state
     */
    uint32_t errPassive;
    /*! Warning Status
     *   0 = Both error counters are below the Error_Warning limit of 96
     *   1 = At least one of error counter has reached the Error_Warning
     *       limit of 96
     */
    uint32_t warningStatus;
    /*! Bus_Off Status
     *   0 = The M_CAN is not Bus_Off
     *   1 = The M_CAN is in Bus_Off state
     */
    uint32_t busOffStatus;
    /*! Data Phase Last Error Code
     *   One of @ref DL_MCAN_ERR_CODE
     */
    uint32_t dlec;
    /*! ESI flag of last received CAN FD Message
     *   0 = Last received CAN FD message did not have its ESI flag set
     *   1 = Last received CAN FD message had its ESI flag set
     */
    uint32_t resi;
    /*! BRS flag of last received CAN FD Message
     *   0 = Last received CAN FD message did not have its BRS flag set
     *   1 = TLast received CAN FD message had its BRS flag set
     */
    uint32_t rbrs;
    /*! Received a CAN FD Message
     *   0 = Since this bit was reset by the CPU, no CAN FD message has been
     *       received
     *   1 = Message in CAN FD format with FDF flag set has been received
     */
    uint32_t rfdf;
    /*! Protocol Exception Event
     *   0 = No protocol exception event occurred since last read access
     *   1 = Protocol exception event occurred
     */
    uint32_t pxe;
    /*! Transmitter Delay Compensation Value */
    uint32_t tdcv;
} DL_MCAN_ProtocolStatus;

/**
 *  @brief  Structure for MCAN Message RAM Configuration Parameters.
 *         Message RAM can contain following sections:
 *         Standard ID filters, Extended ID filters, TX FIFO(or TX Q),
 *         TX Buffers, TX EventFIFO, RX FIFO0, RX FIFO1, RX Buffer.
 *         Note: If particular section in the RAM is not used then it's size
 *         should be initialized to '0'
 *         (Number of buffers in case of Tx/Rx buffer).
 */
typedef struct {
    /*! Standard ID Filter List Start Address */
    uint32_t flssa;
    /*! List Size: Standard ID
     *   0 = No standard Message ID filter
     *   1-127 = Number of standard Message ID filter elements
     *   others = Values greater than 128 are interpreted as 128
     */
    uint32_t lss;
    /*! Extended ID Filter List Start Address */
    uint32_t flesa;
    /*! List Size: Extended ID
     *   0 = No standard Message ID filter
     *   1-64 = Number of standard Message ID filter elements
     *   others = Values greater than 64 are interpreted as 64
     */
    uint32_t lse;
    /*! Tx Buffers Start Address */
    uint32_t txStartAddr;
    /*! Number of Dedicated Transmit Buffers
     *   0 = No Dedicated Tx Buffers
     *   1-32 = Number of Dedicated Tx Buffers
     *   others = Values greater than 32 are interpreted as 32
     */
    uint32_t txBufNum;
    /*! Transmit FIFO/Queue Size
     *   0 = No Tx FIFO/Queue
     *   1-32 = Number of Tx Buffers used for Tx FIFO/Queue
     *   others = Values greater than 32 are interpreted as 32
     */
    uint32_t txFIFOSize;
    /*! Tx FIFO/Queue Mode
     *   0 = Tx FIFO operation
     *   1 = Tx Queue operation
     */
    uint32_t txBufMode;
    /*! Tx Buffer Element Size */
    uint32_t txBufElemSize;
    /*! Tx Event FIFO Start Address */
    uint32_t txEventFIFOStartAddr;
    /*! Event FIFO Size
     *   0 = Tx Event FIFO disabled
     *   1-32 = Number of Tx Event FIFO elements
     *   others = Values greater than 32 are interpreted as 32
     */
    uint32_t txEventFIFOSize;
    /*! Tx Event FIFO Watermark
     *   0 = Watermark interrupt disabled
     *   1-32 = Level for Tx Event FIFO watermark interrupt
     *   others = Watermark interrupt disabled
     */
    uint32_t txEventFIFOWaterMark;
    /*! Rx FIFO0 Start Address */
    uint32_t rxFIFO0startAddr;
    /*! Rx FIFO0 Size
     *   0 = No Rx FIFO
     *   1-64 = Number of Rx FIFO elements
     *   others = Values greater than 64 are interpreted as 64
     */
    uint32_t rxFIFO0size;
    /*! Rx FIFO0 Watermark
     *   0 = Watermark interrupt disabled
     *   1-63 = Level for Rx FIFO 0 watermark interrupt
     *   others = Watermark interrupt disabled
     */
    uint32_t rxFIFO0waterMark;
    /*! Rx FIFO0 Operation Mode
     *   0 = FIFO blocking mode
     *   1 = FIFO overwrite mode
     */
    uint32_t rxFIFO0OpMode;
    /*! Rx FIFO1 Start Address */
    uint32_t rxFIFO1startAddr;
    /*! Rx FIFO1 Size
     *   0 = No Rx FIFO
     *   1-64 = Number of Rx FIFO elements
     *   others = Values greater than 64 are interpreted as 64
     */
    uint32_t rxFIFO1size;
    /*! Rx FIFO1 Watermark
     *   0 = Watermark interrupt disabled
     *   1-63 = Level for Rx FIFO 1 watermark interrupt
     *   others = Watermark interrupt disabled
     */
    uint32_t rxFIFO1waterMark;
    /*! Rx FIFO1 Operation Mode
     *   0 = FIFO blocking mode
     *   1 = FIFO overwrite mode
     */
    uint32_t rxFIFO1OpMode;
    /*! Rx Buffer Start Address */
    uint32_t rxBufStartAddr;
    /*! Rx Buffer Element Size */
    uint32_t rxBufElemSize;
    /*! Rx FIFO0 Element Size */
    uint32_t rxFIFO0ElemSize;
    /*! Rx FIFO1 Element Size */
    uint32_t rxFIFO1ElemSize;
} DL_MCAN_MsgRAMConfigParams;

/**
 *  @brief  Structure for MCAN High Priority Message.
 */
typedef struct {
    /*! Buffer Index
     *   Only valid when MSI[1] = 1.
     */
    uint32_t bufIdx;
    /*! Message Storage Indicator
     *   MSI[1:0]
     *       00  = No FIFO selected
     *       01  = FIFO message lost
     *       10  = Message stored in FIFO 0
     *       11  = Message stored in FIFO 1
     */
    uint32_t msi;
    /*! Filter Index */
    uint32_t filterIdx;
    /*! Indicates the filter list of the matching filter element
     *   0 = Standard Filter List
     *   1 = Extended Filter List
     */
    uint32_t filterList;
} DL_MCAN_HighPriorityMsgInfo;

/**
 *  @brief  Structure for MCAN new data flag for Rx buffer.
 */
typedef struct {
    /*! New data flag for Rx buffer no. 0 to 31 */
    uint32_t statusLow;
    /*! New data flag for Rx buffer no. 32 to 63 */
    uint32_t statusHigh;
} DL_MCAN_RxNewDataStatus;

/**
 *  @brief  Structure for MCAN Rx FIFO Status.
 */
typedef struct {
    /*! Rx FIFO number
     *   One of @ref DL_MCAN_RX_FIFO_NUM
     */
    uint32_t num;
    /*! Rx FIFO Fill Level */
    uint32_t fillLvl;
    /*! Rx FIFO Get Index */
    uint32_t getIdx;
    /*! Rx FIFO Put Index */
    uint32_t putIdx;
    /*! Rx FIFO Full
     *   0 = Rx FIFO not full
     *   1 = Rx FIFO full
     */
    uint32_t fifoFull;
    /*! Rx FIFO Message Lost */
    uint32_t msgLost;
} DL_MCAN_RxFIFOStatus;

/**
 *  @brief  Structure for MCAN Tx FIFO Status.
 */
typedef struct {
    /*! Tx FIFO Free Level */
    uint32_t freeLvl;
    /*! Tx FIFO Get Index
     *   Read as zero when Tx Queue operation is configured.
     */
    uint32_t getIdx;
    /*! Tx FIFO/Queue Put Index */
    uint32_t putIdx;
    /*! Tx FIFO/Queue Full
     *   0 = Tx FIFO/Queue not full
     *   1 = Tx FIFO/Queue full
     */
    uint32_t fifoFull;
} DL_MCAN_TxFIFOStatus;

/**
 *  @brief  Structure for MCAN Tx Event FIFO Status.
 */
typedef struct {
    /*! Event FIFO Fill Level */
    uint32_t fillLvl;
    /*! Event FIFO Gut Index */
    uint32_t getIdx;
    /*! Event FIFO Put Index */
    uint32_t putIdx;
    /*! Event FIFO Full
     *   0 = Tx Event FIFO not full
     *   1 = Tx Event FIFO full
     */
    uint32_t fifoFull;
    /*! Tx Event FIFO Element Lost
     *   0 = No Tx Event FIFO element lost
     *   1 = Tx Event FIFO element lost, also set after write attempt to
     *       Tx Event FIFO of size zero.
     */
    uint32_t eleLost;
} DL_MCAN_TxEventFIFOStatus;

/**
 *  @brief  Structure for ECC Error forcing.
 */
typedef struct {
    /*! Error type to be forced
     *   Refer enum  #DL_MCAN_ECC_ERR_TYPE.
     */
    uint32_t errType;
    /*! Row address where error needs to be applied. */
    uint32_t rowNum;
    /*! Column/Data bit that needs to be flipped when
     *   force_sec or force_ded is set
     */
    uint32_t bit1;
    /*! Data bit that needs to be flipped when force_ded is set */
    uint32_t bit2;
    /*! Force Error once
     *   1: The error will inject an error to the specified row only once
     */
    uint32_t errOnce;
    /*! Force error on the next RAM read */
    uint32_t errForce;
} DL_MCAN_ECCErrForceParams;

/**
 *  @brief  Structure for ECC Error Status.
 */
typedef struct {
    /*! Single Bit Error Status
     *   0 = No Single Bit Error pending
     *   1 = Single Bit Error pending
     */
    uint32_t secErr;
    /*! Double Bit Error Status
     *   0 = No Double Bit Error pending
     *   1 = Double Bit Error pending
     */
    uint32_t dedErr;
    /*! Indicates the row/address where the single or double bit
     *   error occurred.
     */
    uint32_t row;
    /*! Indicates the bit position in the ram data that is in error */
    uint32_t bit1;

} DL_MCAN_ECCErrStatus;

/**
 *  @brief  Structure for accessing Revision ID and Core Release Info.
 *         of MCAN module.
 */
typedef struct {
    /*! Scheme */
    uint32_t scheme;
    /*! Module ID */
    uint32_t modId;
    /*! Major revision */
    uint32_t major;
    /*! Minor revision */
    uint32_t minor;
    /*! Time Stamp Day. Two digits, BCD-coded. */
    uint32_t day;
    /*! Time Stamp Month. Two digits, BCD-coded. */
    uint32_t mon;
    /*! Time Stamp Year. Single digit, BCD-coded. */
    uint32_t year;
    /*! Sub-step of Core Release Single digit, BCD-coded. */
    uint32_t subStep;
    /*! Step of Core Release.Two digits, BCD-coded Single digit, BCD-coded. */
    uint32_t step;
    /*! Core Release. Single digit, BCD-coded. */
    uint32_t rel;
} DL_MCAN_RevisionId;

/**
 *  @brief  Structure for accessing Revision ID of ECC AGGR.
 */
typedef struct {
    /*! Scheme */
    uint32_t scheme;
    /*! Module ID */
    uint32_t modId;
    /*! Major revision */
    uint32_t major;
    /*! Minor revision */
    uint32_t minor;
} DL_MCAN_ECCAggrRevisionId;

/**
 *  @brief  Structure for MCAN ECC configuration parameters.
 */
typedef struct {
    /*! Enable/disable ECC
     *   0 = Disable ECC
     *   1 = Enable ECC
     */
    uint32_t enable;
    /*! Enable/disable ECC Check
     *   0 = Disable ECC Check
     *   1 = Enable ECC Check
     */
    uint32_t enableChk;
    /*! Enable/disable Read Modify Write operation
     *   0 = Disable Read Modify Write operation
     *   1 = Enable Read Modify Write operation
     */
    uint32_t enableRdModWr;
} DL_MCAN_ECCConfigParams;

/**
 *  @brief  Structure for accessing Revision ID of ECC wrapper.
 */
typedef struct {
    /*! Scheme */
    uint32_t scheme;
    /*! Module ID */
    uint32_t modId;
    /*! Major revision */
    uint32_t major;
    /*! Minor revision */
    uint32_t minor;
} DL_MCAN_ECCWrapRevisionId;

/**
 *  @brief  Structure for MCAN Tx Buffer element.
 */
typedef struct {
    /*! Identifier */
    uint32_t id;
    /*! Remote Transmission Request
     *   0 = Transmit data frame
     *   1 = Transmit remote frame
     */
    uint32_t rtr;
    /*! Extended Identifier
     *   0 = 11-bit standard identifier
     *   1 = 29-bit extended identifier
     */
    uint32_t xtd;
    /*! Error State Indicator
     *   0 = ESI bit in CAN FD format depends only on error passive flag
     *   1 = ESI bit in CAN FD format transmitted recessive
     */
    uint32_t esi;
    /*! Data Length Code
     *   0-8  = CAN + CAN FD: transmit frame has 0-8 data bytes
     *   9-15 = CAN: transmit frame has 8 data bytes
     *   9-15 = CAN FD: transmit frame has 12/16/20/24/32/48/64 data bytes
     */
    uint32_t dlc;
    /*! Bit Rat Switching
     *   0 = CAN FD frames transmitted without bit rate switching
     *   1 = CAN FD frames transmitted with bit rate switching
     */
    uint32_t brs;
    /*! FD Format
     *   0 = Frame transmitted in Classic CAN format
     *   1 = Frame transmitted in CAN FD format
     */
    uint32_t fdf;
    /*! Event FIFO Control
     *   0 = Don't store Tx events
     *   1 = Store Tx events
     */
    uint32_t efc;
    /*! Message Marker */
    uint32_t mm;
    /*! Data bytes.
     *   Only first dlc number of bytes are valid.
     */
    uint16_t data[DL_MCAN_MAX_PAYLOAD_BYTES];
} DL_MCAN_TxBufElement;

/**
 *  @brief  Structure for MCAN Rx Buffer element.
 */
typedef struct {
    /*! Identifier */
    uint32_t id;
    /*! Remote Transmission Request
     *   0 = Received frame is a data frame
     *   1 = Received frame is a remote frame
     */
    uint32_t rtr;
    /*! Extended Identifier
     *   0 = 11-bit standard identifier
     *   1 = 29-bit extended identifier
     */
    uint32_t xtd;
    /*! Error State Indicator
     *   0 = Transmitting node is error active
     *   1 = Transmitting node is error passive
     */
    uint32_t esi;
    /*! Rx Timestamp */
    uint32_t rxts;
    /*! Data Length Code
     *   0-8  = CAN + CAN FD: received frame has 0-8 data bytes
     *   9-15 = CAN: received frame has 8 data bytes
     *   9-15 = CAN FD: received frame has 12/16/20/24/32/48/64 data bytes
     */
    uint32_t dlc;
    /*! Bit Rat Switching
     *   0 = Frame received without bit rate switching
     *   1 = Frame received with bit rate switching
     */
    uint32_t brs;
    /*! FD Format
     *   0 = Standard frame format
     *   1 = CAN FD frame format (new DLC-coding and CRC)
     */
    uint32_t fdf;
    /*! Filter Index */
    uint32_t fidx;
    /*! Accepted Non-matching Frame
     *   0 = Received frame matching filter index FIDX
     *   1 = Received frame did not match any Rx filter element
     */
    uint32_t anmf;
    /*! Data bytes.
     *   Only first dlc number of bytes are valid.
     */
    uint16_t data[DL_MCAN_MAX_PAYLOAD_BYTES];
} DL_MCAN_RxBufElement;

/**
 *  @brief  Structure for MCAN Tx Event FIFO element.
 */
typedef struct {
    /*! Identifier */
    uint32_t id;
    /*! Remote Transmission Request
     *   0 = Data frame transmitted
     *   1 = Remote frame transmitted
     */
    uint32_t rtr;
    /*! Extended Identifier
     *   0 = 11-bit standard identifier
     *   1 = 29-bit extended identifier
     */
    uint32_t xtd;
    /*! Error State Indicator
     *   0 = Transmitting node is error active
     *   1 = Transmitting node is error passive
     */
    uint32_t esi;
    /*! Tx Timestamp */
    uint32_t txts;
    /*! Data Length Code
     *   0-8  = CAN + CAN FD: frame with 0-8 data bytes transmitted
     *   9-15 = CAN: frame with 8 data bytes transmitted
     *   9-15 = CAN FD: frame with 12/16/20/24/32/48/64 data bytes transmitted
     */
    uint32_t dlc;
    /*! Bit Rat Switching
     *   0 = Frame transmitted without bit rate switching
     *   1 = Frame transmitted with bit rate switching
     */
    uint32_t brs;
    /*! FD Format
     *   0 = Standard frame format
     *   1 = CAN FD frame format (new DLC-coding and CRC)
     */
    uint32_t fdf;
    /*! Event Type
     *   00 = Reserved
     *   01 = Tx event
     *   10 = Transmission in spite of cancellation
     *        (always set for transmissions in DAR mode)
     *   11 = Reserved
     */
    uint32_t et;
    /*! Message Marker */
    uint32_t mm;
} DL_MCAN_TxEventFIFOElement;

/**
 *  @brief  Structure for MCAN Standard Message ID Filter Element.
 */
typedef struct {
    /*! Standard Filter ID 2 */
    uint32_t sfid2;
    /*! Standard Filter ID 1 */
    uint32_t sfid1;
    /*! Standard Filter Element Configuration
     *   000 = Disable filter element
     *   001 = Store in Rx FIFO 0 if filter matches
     *   010 = Store in Rx FIFO 1 if filter matches
     *   011 = Reject ID if filter matches
     *   100 = Set priority if filter matches
     *   101 = Set priority and store in FIFO 0 if filter matches
     *   110 = Set priority and store in FIFO 1 if filter matches
     *   111 = Store into Rx Buffer or as debug message,
     *         configuration of SFT[1:0] ignored.
     *   If SFEC = 0b100, 0b101, or 0b110 a match sets high priority
     *   message event is generated.
     */
    uint32_t sfec;
    /*! Standard Filter Type
     *   00 = Range filter from SFID1 to SFID2 (SFID2 ≥ SFID1)
     *   01 = Dual ID filter for SFID1 or SFID2
     *   10 = Classic filter: SFID1 = filter, SFID2 = mask
     *   11 = Filter element disabled
     */
    uint32_t sft;
} DL_MCAN_StdMsgIDFilterElement;

/**
 *  @brief  Structure for MCAN Extended Message ID Filter Element.
 */
typedef struct {
    /*! Extended Filter ID 1 */
    uint32_t efid1;
    /*! Extended Filter Element Configuration
     *   000 = Disable filter element
     *   001 = Store in Rx FIFO 0 if filter matches
     *   010 = Store in Rx FIFO 1 if filter matches
     *   011 = Reject ID if filter matches
     *   100 = Set priority if filter matches
     *   101 = Set priority and store in FIFO 0 if filter matches
     *   110 = Set priority and store in FIFO 1 if filter matches
     *   111 = Store into Rx Buffer or as debug message,
     *         configuration of SFT[1:0] ignored.
     *   If EFEC = 0b100, 0b101, or 0b110 a match sets high priority
     *   message event is generated.
     */
    uint32_t efec;
    /*! Extended Filter ID 2 */
    uint32_t efid2;
    /*! Extended Filter Type
     *   00 = Range filter from EFID1 to EFID2 (EFID2 ≥ EFID1)
     *   01 = Dual ID filter for EFID1 or EFID2
     *   10 = Classic filter: EFID1 = filter, EFID2 = mask
     *   11 = Range filter from EFID1 to EFID2 (EFID2 ≥ EFID1),
     *        XIDAM mask not applied
     */
    uint32_t eft;
} DL_MCAN_ExtMsgIDFilterElement;

/**
 * @brief Configuration structure to backup MCAN peripheral state before
 *        entering STOP or STANDBY mode. Not required after PG 1.0 silicon.
 *        Used by @ref DL_MCAN_saveConfiguration and
 *        @ref DL_MCAN_restoreConfiguration
 */
typedef struct {
    /*! MCAN Clock Divider Configuration */
    uint32_t clkDivConf;

    /*! MCAN Clock Stop Configuration */
    uint32_t clkConf;

    /*! MCAN Clock Configuration */
    uint32_t clkEnConf;

    /*! MCAN Control Configuration */
    uint32_t ctrlConf;

    /*! MCAN Nominal Bit Time Configuration */
    uint32_t nomBitTimeConf;

    /*! MCAN Data Bit Time Configuration */
    uint32_t dataBitTimeConf;

    /*! MCAN Timestamp Configuration */
    uint32_t timeCntConf;

    /*! MCAN Timestamp Counter Value */
    uint32_t timeCntVal;

    /*! MCAN Time-out Configuration */
    uint32_t timeOutConf;

    /*! MCAN Time-out Counter Value */
    uint32_t timeOutCntVal;

    /*! MCAN Transmitter Delay Compensation */
    uint32_t txDelCompConf;

    /*! MCAN Interrupt Configuration */
    uint32_t intEnConf;

    /*! MCAN Interrupt Line Select */
    uint32_t intLnSelConf;

    /*! MCAN Interrupt Line Enable */
    uint32_t intLnEnableConf;

    /*! MCAN Global Filter Configuration */
    uint32_t globFiltIDConf;

    /*! MCAN Standard ID Filter Configuration */
    uint32_t stdFiltIDConf;

    /*! MCAN Extended ID Filter Configuration */
    uint32_t exFiltIDConf;

    /*! MCAN Extended ID and Mask */
    uint32_t exFiltIDMsk;

    /*! MCAN Rx FIFO 0 Configuration */
    uint32_t rxFIFO0Conf;

    /*! MCAN Rx Buffer Configuration */
    uint32_t rxBuffConf;

    /*! MCAN Rx FIFO 1 Configuration */
    uint32_t rxFIFO1Conf;

    /*! MCAN Rx Element Size for Rx Buff and FIFOs */
    uint32_t rxDataSize;

    /*! MCAN Tx Buffer Configuration */
    uint32_t txBuffConf;

    /*! MCAN Tx Element Size for Tx Buff*/
    uint32_t txDataSize;

    /*! MCAN Tx Buffer Transmission Interrupt Enable Configuration */
    uint32_t txBuffTxIntConf;

    /*! MCAN Tx Buffer Cancellation Finished Interrupt Enable */
    uint32_t txBuffCancIntConf;

    /*! MCAN Tx Event FIFO Configuration */
    uint32_t txEvntFIFOConf;

    /*! MCAN Subsystem Control Configuration */
    uint32_t ssCtrlConf;

    /*! MCAN Subsystem Interrupt Enable Configuration */
    uint32_t ssIntEnConf;

    /*! MCAN Subsystem External Timestamp Prescaler 0 */
    uint32_t preSclConf;

    /*! MCAN Error detection and correction vector */
    uint32_t edcVecConf;

    /*! MCAN Error detection and correction control Configuration 2 */
    uint32_t edcConf2;

    /*! MCAN Error detection and correction control Configuration 1 */
    uint32_t edcConf1;

    /*! MCAN Error detection and correction control Configuration 0 */
    uint32_t edcConf0;

    /*! MCAN Interrupt Configuration */
    uint32_t intEvnt0Conf;

    /*! MCAN Watchdog Configuration */
    uint32_t ramWDConf;

    /*! MCAN Test Configuration */
    uint32_t testConf;

    /*! Boolean flag indicating whether or not a valid configuration structure
     *  exists. Should not be modified by the user. */
    bool backupRdy;
} DL_MCAN_backupConfig;

/*! @enum DL_MCAN_CLOCK_DIVIDE */
typedef enum {
    /*! Divide MCAN clock by 1 */
    DL_MCAN_CLOCK_DIVIDE_1 = MCAN_CLKDIV_RATIO_DIV_BY_1_,
    /*! Divide MCAN clock by 2 */
    DL_MCAN_CLOCK_DIVIDE_2 = MCAN_CLKDIV_RATIO_DIV_BY_2_,
    /*! Divide MCAN clock by 4 */
    DL_MCAN_CLOCK_DIVIDE_4 = MCAN_CLKDIV_RATIO_DIV_BY_4_
} DL_MCAN_CLOCK_DIVIDE;

/*! @enum DL_MCAN_IIDX */
typedef enum {
    /*! Interrupt index for MCAN clock stop wake up interrupt pending. */
    DL_MCAN_IIDX_WAKEUP = MCAN_IIDX_STAT_WAKEUP,
    /*! Interrupt index for MCAN external timestamp counter overflow interrupt
     *  pending. */
    DL_MCAN_IIDX_TIMESTAMP_OVERFLOW = MCAN_IIDX_STAT_EXT_TS_CNTR_OVFL,
    /*! Interrupt index for MCAN message RAM double error detection interrupt
     *  pending. */
    DL_MCAN_IIDX_DOUBLE_ERROR_DETECTION = MCAN_IIDX_STAT_DED,
    /*! Interrupt index for MCAN message RAM single error correction interrupt
     *  pending. */
    DL_MCAN_IIDX_SINGLE_ERROR_CORRECTION = MCAN_IIDX_STAT_SEC,
    /*! Interrupt index for MCAN interrupt line 1 interrupt pending. */
    DL_MCAN_IIDX_LINE1 = MCAN_IIDX_STAT_INTL1,
    /*! Interrupt index for MCAN interrupt line 0 interrupt pending. */
    DL_MCAN_IIDX_LINE0 = MCAN_IIDX_STAT_INTL0
} DL_MCAN_IIDX;

/**
 *  @brief if MCAN instance is ready to be configured
 *
 *  @param[in] instance      Specifies the CANFD instance. One of
 *                           @ref DL_MCAN_INSTANCE
 *
 *  @return true if MCAN instance is ready to configured
 *  @return false if MCAN instance clock synchronization is ongoing.
 */
bool DL_MCAN_isReady(DL_MCAN_INSTANCE instance);

/**
 *  @brief      Configure CANCLK source clock
 *  @param[in]  mcan        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  config         Pointer to the clock configuration struct
 *                             @ref DL_MCAN_ClockConfig.
 */
void DL_MCAN_setClockConfig(MCAN_Regs *mcan, DL_MCAN_ClockConfig *config);

/**
 *  @brief     Get  CANCLK clock configuration
 *  @param[in]  mcan        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  config         Pointer to the clock configuration struct
 *                             @ref DL_MCAN_ClockConfig.
 */
void DL_MCAN_getClockConfig(MCAN_Regs *mcan, DL_MCAN_ClockConfig *config);
/**
 *  @brief   This function checks if the MCAN module is in Reset.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 * @retval  state     Returns TRUE if reset is in progress.
 *                    Else returns FALSE.
 */
bool DL_MCAN_isInReset(MCAN_Regs *mcan);

/**
 *  @brief   This API will return flexible data rate operation status
 *          MCAN module.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 * @return  state     Returns TRUE if flexible data rate operation
 *                    is enabled. Else returns FALSE.
 */
bool DL_MCAN_isFDOpEnable(MCAN_Regs *mcan);

/**
 *  @brief   This function checks if the memory initialization is done for
 *          MCAN module.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @retval  state    Returns TRUE if memory initialization is done.
 *                    Else returns FALSE.
 */
bool DL_MCAN_isMemInitDone(MCAN_Regs *mcan);

/**
 *  @brief  This API will set MCAN module mode of operation.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *  @param[in]  mode  Mode of operation. One of @ref DL_MCAN_OPERATION_MODE.
 *
 *  @return  None.
 */
void DL_MCAN_setOpMode(MCAN_Regs *mcan, uint32_t mode);

/**
 *  @brief            This API will return MCAN module mode of operation.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  mode     Mode of operation. One of @ref DL_MCAN_OPERATION_MODE.
 */
uint32_t DL_MCAN_getOpMode(MCAN_Regs *mcan);

/**
 *  @brief   This API will initialize MCAN module.
 *
 *  @param[in]  mcan          Pointer to the register overlay for the peripheral
 *  @param[in]  initParams    Initialization parameters.
 *                            @ref DL_MCAN_InitParams.
 *
 *  @return  status           Initialization status.
 */
int32_t DL_MCAN_init(MCAN_Regs *mcan, const DL_MCAN_InitParams *initParams);

/**
 *  @brief   This API will configure MCAN module.
 *
 *  @param[in]  mcan          Pointer to the register overlay for the peripheral
 *  @param[in]  configParams  Configuration parameters.
 *                            @ref DL_MCAN_ConfigParams.
 *
 *  @return  status          Configuration status.
 */
int32_t DL_MCAN_config(
    MCAN_Regs *mcan, const DL_MCAN_ConfigParams *configParams);

/**
 *  @brief   This API will enable/disable ECC on the Message RAM.
 *
 *  @param[in]  mcan         Pointer to the register overlay for the peripheral
 *  @param[in]  configParams MCAN ECC Configuration Parameters.
 *                           @ref DL_MCAN_ECCConfigParams.
 *
 *  @return  None.
 */
void DL_MCAN_eccConfig(
    MCAN_Regs *mcan, const DL_MCAN_ECCConfigParams *configParams);

/**
 *  @brief   This API will configure a bit timings for MCAN module.
 *
 *  @param[in]  mcan         Pointer to the register overlay for the peripheral
 *  @param[in]  configParams Configuration parameters for MCAN bit timing.
 *                           @ref DL_MCAN_BitTimingParams.
 *
 *  @return  status          Bit Timings configuration status.
 */
int32_t DL_MCAN_setBitTime(
    MCAN_Regs *mcan, const DL_MCAN_BitTimingParams *configParams);

/**
 *  @brief   This API will configure Different sections of Message RAM.
 *
 *  @param[in]  mcan        Pointer to the register overlay for the peripheral
 *  @param[in]  msgRAMConfigParams
 *                          Message RAM Configuration parameters.
 *                          @ref DL_MCAN_MsgRAMConfigParams.
 *
 *  @return  status          Configuration Status.
 */
int32_t DL_MCAN_msgRAMConfig(
    MCAN_Regs *mcan, const DL_MCAN_MsgRAMConfigParams *msgRAMConfigParams);

/**
 *  @brief   This API will configure Extended ID AND Mask.
 *
 *  @param[in]  mcan      Pointer to the register overlay for the peripheral
 *  @param[in]  idMask    Configuration parameters for MCAN Extended Id mask.
 *                        This value is 29 bit wide.
 *
 *  @return  status       Extended ID AND Mask configuration status.
 */
int32_t DL_MCAN_setExtIDAndMask(MCAN_Regs *mcan, uint32_t idMask);

/**
 *  @brief   This API is used to write Tx message to message RAM.
 *
 *  @param[in]  mcan       Pointer to the register overlay for the peripheral
 *  @param[in]  memType    Part of message ram to which given message to write.
 *                         One of @ref DL_MCAN_MEM_TYPE.
 *  @param[in]  bufNum     Buffer  number where message to write.
 *                         This parameter will ignored if memType is FIFO/Q.
 *  @param[in]  elem       Message Object.
 *                         @ref DL_MCAN_TxBufElement.
 *
 *  @return  None.
 */
void DL_MCAN_writeMsgRam(MCAN_Regs *mcan, uint32_t memType, uint32_t bufNum,
    const DL_MCAN_TxBufElement *elem);

/**
 *  @brief   This API will set Tx Buffer Add Request.
 *
 *  @param[in]  mcan    Pointer to the register overlay for the peripheral
 *  @param[in]  bufNum  Tx Buffer number for which request is to be added.
 *
 *  @return  status     Configuration Status.
 */
int32_t DL_MCAN_TXBufAddReq(MCAN_Regs *mcan, uint32_t bufNum);

/**
 *  @brief   This API will return New Data Message Status.
 *
 *  @param[in]  mcan          Pointer to the register overlay for the peripheral
 *  @param[in]  newDataStatus Rx Buffer new data status.
 *                            @ref DL_MCAN_RxNewDataStatus.
 *
 *  @return  None.
 */
void DL_MCAN_getNewDataStatus(
    MCAN_Regs *mcan, DL_MCAN_RxNewDataStatus *newDataStatus);

/**
 *  @brief   This API clear New Data Message Status.
 *
 *  @param[in]  mcan          Pointer to the register overlay for the peripheral
 *  @param[in]  newDataStatus Rx Buffer new data status.
 *                            @ref DL_MCAN_RxNewDataStatus.
 *
 *  @return  None.
 */
void DL_MCAN_clearNewDataStatus(
    MCAN_Regs *mcan, const DL_MCAN_RxNewDataStatus *newDataStatus);

/**
 *  @brief   This API is used to read received message form message RAM.
 *
 *  @param[in]  mcan        Pointer to the register overlay for the peripheral
 *  @param[in]  memType     Part of message ram to which given message to
 *                          write.One of @ref DL_MCAN_MEM_TYPE.
 *  @param[in]  bufNum      Buffer  number from where message is to read.
 *                          This parameter will ignored if memType is FIFO/Q.
 *  @param[in]  fifoNum     FIFOs number from where message is to read.
 *                          One of @ref DL_MCAN_RX_FIFO_NUM.
 *                          This parameter will ignored if memType is buffer.
 *  @param[in]  elem        Message Object.
 *                          @ref DL_MCAN_RxBufElement.
 *
 *  @return  None.
 */
void DL_MCAN_readMsgRam(MCAN_Regs *mcan, uint32_t memType, uint32_t bufNum,
    uint32_t fifoNum, DL_MCAN_RxBufElement *elem);

/**
 *  @brief   This API is used to read message form Tx Event FIFO.
 *
 *  @param[in]  mcan         Pointer to the register overlay for the peripheral
 *  @param[in]  txEventElem  Tx Event FIFO Message Object.
 *                           @ref DL_MCAN_TxEventFIFOElement.
 *
 *  @return  None.
 */
void DL_MCAN_readTxEventFIFO(
    MCAN_Regs *mcan, DL_MCAN_TxEventFIFOElement *txEventElem);

/**
 *  @brief   This API is used to add Standard Message ID Filter Element.
 *
 *  @note MCAN RAM must be configured @ref DL_MCAN_msgRAMConfig before
 *  calling this API.
 *
 *  @param[in]  mcan       Pointer to the register overlay for the peripheral
 *  @param[in]  filtNum    Filter number.
 *  @param[in]  elem       Filter Object. @ref DL_MCAN_StdMsgIDFilterElement.
 *
 *  @return  None.
 *
 *  @sa DL_MCAN_msgRAMConfig
 */
void DL_MCAN_addStdMsgIDFilter(MCAN_Regs *mcan, uint32_t filtNum,
    const DL_MCAN_StdMsgIDFilterElement *elem);

/**
 *  @brief   This API is used to add Extended Message ID Filter Element.
 *
 *  @note MCAN RAM must be configured @ref DL_MCAN_msgRAMConfig before
 *  calling this API.
 *
 *  @param[in]  mcan     Pointer to the register overlay for the peripheral
 *  @param[in]  filtNum  Filter  number.
 *  @param[in]  elem     Filter Object. @ref DL_MCAN_ExtMsgIDFilterElement.
 *
 *  @return  None.
 *
 *  @sa DL_MCAN_msgRAMConfig
 */
void DL_MCAN_addExtMsgIDFilter(MCAN_Regs *mcan, uint32_t filtNum,
    const DL_MCAN_ExtMsgIDFilterElement *elem);

/**
 *  @brief   This API will enable/disable Loop Back Test Mode for
 *           MCAN module.
 *
 *  @param[in]  mcan      Pointer to the register overlay for the peripheral
 *  @param[in]  lpbkMode  Loopback mode for MCAN.
 *                        One of @ref DL_MCAN_LPBK_MODE.
 *  @param[in]  enable    Loop Back Mode is enabled if it is TRUE.
 *                        Loop Back Mode is disabled if it is FALSE.
 *
 *  @return  None.
 * \note    This API can be called only when MCAN is in Software
 *          Initialization mode of operation.
 */
void DL_MCAN_lpbkModeEnable(MCAN_Regs *mcan, uint32_t lpbkMode, bool enable);

/**
 *  @brief   This API will return error counter status for MCAN module.
 *
 *  @param[in]  mcan       Pointer to the register overlay for the peripheral
 *  @param[in]  errCounter Error Counter Status. @ref DL_MCAN_ErrCntStatus.
 *
 *  @return  None.
 */
void DL_MCAN_getErrCounters(MCAN_Regs *mcan, DL_MCAN_ErrCntStatus *errCounter);

/**
 *  @brief   This API will return protocol status for MCAN module.
 *
 *  @param[in]  mcan        Pointer to the register overlay for the peripheral
 *  @param[in]  protStatus  Protocol Status. @ref DL_MCAN_ProtocolStatus.
 *
 *  @return  None.
 */
void DL_MCAN_getProtocolStatus(
    MCAN_Regs *mcan, DL_MCAN_ProtocolStatus *protStatus);

/**
 *  @brief   This API is used to enable/disable interrupts.
 *
 *  @param[in]  mcan      Pointer to the register overlay for the peripheral
 *  @param[in]  intrMask  Interrupts to enable. One of @ref DL_MCAN_INTR_SRC.
 *  @param[in]  enable    Interrupt is enabled if it is TRUE.
 *                        Interrupt is disabled if it is FALSE.
 *
 *  @return  None.
 */
void DL_MCAN_enableIntr(MCAN_Regs *mcan, uint32_t intrMask, bool enable);

/**
 *  @brief   This API is used to select interrupt line.
 *
 *  @param[in]  mcan      Pointer to the register overlay for the peripheral
 *  @param[in]  intrMask  Interrupt Number for which interrupt
 *                        line is to be selected. One of @ref DL_MCAN_INTR_SRC.
 *  @param[in]  lineNum   Interrupt Line to select.
 *                        One of @ref DL_MCAN_INTR_LINE_NUM,
 *
 *  @return  None.
 */
void DL_MCAN_selectIntrLine(
    MCAN_Regs *mcan, uint32_t intrMask, uint32_t lineNum);

/**
 *  @brief   This API is used to get interrupt line selected for each interrupt.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  status   Interrupt Line Select Status.
 */
uint32_t DL_MCAN_getIntrLineSelectStatus(MCAN_Regs *mcan);

/**
 *  @brief   This API is used to enable/disable selected interrupt line.
 *
 *  @param[in]  mcan      Pointer to the register overlay for the peripheral
 *  @param[in]  lineNum   Interrupt Line to select.
 *                        One of @ref DL_MCAN_INTR_LINE_NUM,
 *  @param[in]  enable    Interrupt Line is enabled if it is TRUE.
 *                        Interrupt Line is disabled if it is FALSE.
 *
 *  @return  None.
 */
void DL_MCAN_enableIntrLine(MCAN_Regs *mcan, uint32_t lineNum, bool enable);

/**
 *  @brief   This API will return interrupt status.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  status   Interrupt Status.
 */
uint32_t DL_MCAN_getIntrStatus(MCAN_Regs *mcan);

/**
 *  @brief   This API is used to clear the interrupt status.
 *
 *  @param[in]  mcan       Pointer to the register overlay for the peripheral
 *  @param[in]  intrMask   Interrupts to clear status.
 *  @param[in]  eoi        Specified the associated. @ref DL_MCAN_INTR_SRC
 *
 *  @return  None.
 */
void DL_MCAN_clearIntrStatus(
    MCAN_Regs *mcan, uint32_t intrMask, DL_MCAN_INTR_SRC_MCAN eoi);

/**
 *  @brief   This API will return High Priority Message Status.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *  @param[in]  hpm   High Priority Message Status.
 *                    @ref DL_MCAN_HighPriorityMsgInfo.
 *
 *  @return  None.
 */
void DL_MCAN_getHighPriorityMsgStatus(
    MCAN_Regs *mcan, DL_MCAN_HighPriorityMsgInfo *hpm);

/**
 *  @brief   This API will Rx FIFO status.
 *
 *  @param[in]  mcan       Pointer to the register overlay for the peripheral
 *  @param[in]  fifoStatus Rx FIFO Status. @ref DL_MCAN_RxFIFOStatus.
 *
 *  @return  None.
 */
void DL_MCAN_getRxFIFOStatus(
    MCAN_Regs *mcan, DL_MCAN_RxFIFOStatus *fifoStatus);

/**
 *  @brief   This API will write Rx FIFO Acknowledgement.
 *
 *  @param[in]  mcan     Pointer to the register overlay for the peripheral
 *  @param[in]  fifoNum  FIFO Number. One of @ref DL_MCAN_RX_FIFO_NUM.
 *  @param[in]  idx      Rx FIFO Acknowledge Index
 *
 *  @return  status      Acknowledgement Status.
 */
int32_t DL_MCAN_writeRxFIFOAck(
    MCAN_Regs *mcan, uint32_t fifoNum, uint32_t idx);

/**
 *  @brief   This API will Tx FIFO status.
 *
 *  @param[in]  mcan        Pointer to the register overlay for the peripheral
 *  @param[in]  fifoStatus  Tx FIFO Status. @ref DL_MCAN_TxFIFOStatus.
 *
 *  @return  None.
 */
void DL_MCAN_getTxFIFOQueStatus(
    MCAN_Regs *mcan, DL_MCAN_TxFIFOStatus *fifoStatus);

/**
 *  @brief   This API will return Tx Buffer Request Pending status.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  status   Tx Buffer Request Pending status.
 */
uint32_t DL_MCAN_getTxBufReqPend(MCAN_Regs *mcan);

/**
 *  @brief   This API will set Tx Buffer Cancellation Request.
 *
 *  @param[in]  mcan      Pointer to the register overlay for the peripheral
 *  @param[in]  buffNum   Tx Buffer number for which request is to be added.
 *
 *  @return  status       Configuration Status.
 */
int32_t DL_MCAN_txBufCancellationReq(MCAN_Regs *mcan, uint32_t buffNum);

/**
 *  @brief   This API will return Tx Buffer Transmission Occurred status.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  status   Tx Buffer Transmission Occurred status.
 */
uint32_t DL_MCAN_getTxBufTransmissionStatus(MCAN_Regs *mcan);

/**
 *  @brief   This API will return Transmit Buffer Cancellation Finished status.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  status   Transmit Buffer Cancellation Finished status.
 */
uint32_t DL_MCAN_txBufCancellationStatus(MCAN_Regs *mcan);

/**
 *  @brief   This API is used to enable/disable Tx Buffer Transmission Interrupt.
 *
 *  @param[in]  mcan    Pointer to the register overlay for the peripheral
 *  @param[in]  bufNum  Buffer number for which interrupt is to enable.
 *  @param[in]  enable  Interrupt is enabled if it is TRUE.
 *                      Interrupt is disabled if it is FALSE.
 *
 *  @return  status     Configuration status.
 */
int32_t DL_MCAN_TXBufTransIntrEnable(
    MCAN_Regs *mcan, uint32_t bufNum, bool enable);

/**
 *  @brief   This API is used to enable/disable Tx Buffer Cancellation Finished
 *          Interrupt.
 *
 *  @param[in]  mcan     Pointer to the register overlay for the peripheral
 *  @param[in]  bufNum   Buffer number for which interrupt is to enable.
 *  @param[in]  enable   Interrupt is enabled if it is TRUE.
 *                       Interrupt is disabled if it is FALSE.
 *
 *  @return  status          Configuration status.
 */
int32_t DL_MCAN_getTxBufCancellationIntrEnable(
    MCAN_Regs *mcan, uint32_t bufNum, bool enable);

/**
 *  @brief   This API add clock stop request for MCAN module to put it in
 *          power down mode.
 *
 *  @param[in]  mcan    Pointer to the register overlay for the peripheral
 *  @param[in]  enable  Add Clock Stop Request.
 *                      Adds Clock Stop Request is TRUE otherwise
 *                      removes it.
 *
 *  @return  None.
 */
void DL_MCAN_addClockStopRequest(MCAN_Regs *mcan, bool enable);

/**
 *  @brief   This API will Tx Event FIFO status.
 *
 *  @param[in]  mcan        Pointer to the register overlay for the peripheral
 *  @param[in]  fifoStatus  Tx Event FIFO Status.
 *                          @ref DL_MCAN_TxEventFIFOStatus.
 *
 *  @return  None.
 */
void DL_MCAN_getTxEventFIFOStatus(
    MCAN_Regs *mcan, DL_MCAN_TxEventFIFOStatus *fifoStatus);

/**
 *  @brief   This API will write Event FIFO Acknowledge Index.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *  @param[in]  idx   Event FIFO Acknowledge Index
 *
 *  @return  status   Acknowledgement Status.
 */
int32_t DL_MCAN_writeTxEventFIFOAck(MCAN_Regs *mcan, uint32_t idx);

/**
 *  @brief   This API will Force Error on ECC.
 *
 *  @param[in]  mcan    Pointer to the register overlay for the peripheral
 *  @param[in]  eccErr  Force Error on ECC configuration.
 *                      @ref DL_MCAN_ECCErrForceParams.
 *
 *  @return  status     Configuration status.
 */
void DL_MCAN_eccForceError(
    MCAN_Regs *mcan, const DL_MCAN_ECCErrForceParams *eccErr);

/**
 *  @brief   This API will return ECC Error status.
 *
 *  @param[in]  mcan    Pointer to the register overlay for the peripheral
 *  @param[in]  eccErr  ECC error status. @ref DL_MCAN_ECCErrStatus.
 *
 *  @return  None.
 */
void DL_MCAN_eccGetErrorStatus(MCAN_Regs *mcan, DL_MCAN_ECCErrStatus *eccErr);

/**
 *  @brief   This API is used to clear the ECC Error status.
 *
 *  @param[in]  mcan     Pointer to the register overlay for the peripheral
 *  @param[in]  errType  Error type to clear status.
 *                       One of @ref DL_MCAN_ECC_ERR_TYPE.
 *
 *  @return  None.
 */
void DL_MCAN_eccClearErrorStatus(MCAN_Regs *mcan, uint32_t errType);

/**
 *  @brief   This API is used to write End of Interrupt for ECC interrupt.
 *
 *  @param[in]  mcan      Pointer to the register overlay for the peripheral
 *  @param[in]  errType   Interrupt to enable. One of @ref DL_MCAN_ECC_ERR_TYPE.
 *
 *  @return  None.
 */
void DL_MCAN_eccWriteEOI(MCAN_Regs *mcan, uint32_t errType);

/**
 *  @brief   This API is used to enable ECC interrupt.
 *
 *  @param[in]  mcan    Pointer to the register overlay for the peripheral
 *  @param[in]  errType Interrupt to enable. One of @ref DL_MCAN_ECC_ERR_TYPE.
 *  @param[in]  enable  ECC Interrupt is enabled if it is TRUE.
 *                      ECC Interrupt is disabled if it is FALSE.
 *
 *  @return  None.
 */
void DL_MCAN_eccEnableIntr(MCAN_Regs *mcan, uint32_t errType, bool enable);

/**
 *  @brief   This API is used to get ECC interrupt status.
 *
 *  @param[in]  mcan     Pointer to the register overlay for the peripheral
 *  @param[in]  errType  Interrupt status to read.
 *                       One of @ref DL_MCAN_ECC_ERR_TYPE.
 *
 *  @return  None.
 */
uint32_t DL_MCAN_eccGetIntrStatus(MCAN_Regs *mcan, uint32_t errType);

/**
 *  @brief   This API is used to clear ECC interrupt status.
 *
 *  @param[in]  mcan     Pointer to the register overlay for the peripheral
 *  @param[in]  errType  Interrupt status to clear.
 *                       One of @ref DL_MCAN_ECC_ERR_TYPE.
 *
 *  @return  None.
 */
void DL_MCAN_eccClearIntrStatus(MCAN_Regs *mcan, uint32_t errType);

/**
 *  @brief   This API will configure external timestamp counter for MCAN module.
 *
 *  @param[in]  mcan        Pointer to the register overlay for the peripheral
 *  @param[in]  prescalar   Timestamp Counter Prescaler. Range:[0x0-0xFFFFFF]
 *
 *  @return  None.
 *
 * \note    Actual value programmed prescalar values is (prescalar - 1).
 */
void DL_MCAN_extTSCounterConfig(MCAN_Regs *mcan, uint32_t prescalar);

/**
 *  @brief   This API will enable/disable fast external time stamp counter for
 *          MCAN module.
 *
 *  @param[in]  mcan    Pointer to the register overlay for the peripheral
 *  @param[in]  enable  External TS is enabled if it is TRUE.
 *                      External TS is disabled if it is FALSE.
 *
 *  @return  None.
 */
void DL_MCAN_extTSCounterEnable(MCAN_Regs *mcan, bool enable);

/**
 *  @brief   This API will enable/disable External TimeStamp Counter
 *           Overflow Interrupt for MCAN module.
 *
 *  @param[in]  mcan    Pointer to the register overlay for the peripheral
 *  @param[in]  enable  External TimeStamp Counter Overflow Interrupt is
 *                      enabled if it is TRUE.
 *                      External TimeStamp Counter Overflow Interrupt is
 *                      disabled if it is FALSE.
 *
 *  @return  None.
 */
void DL_MCAN_extTSEnableIntr(MCAN_Regs *mcan, bool enable);

/**
 *  @brief   This API is used to write End of Interrupt for External TimeStamp
 *          Counter Overflow Interrupt.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  None.
 */
void DL_MCAN_extTSWriteEOI(MCAN_Regs *mcan);

/**
 *  @brief   This API returns Number of unserviced rollover/overflow
 *          interrupts for external TimeStamp counter.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  status   Returns Number of unserviced rollover/overflow
 *                    interrupts for external TimeStamp counter.
 *                    Maximum number of unserviced interrupts is 0xF.
 */
uint32_t DL_MCAN_extTSGetUnservicedIntrCount(MCAN_Regs *mcan);

/* ========================================================================== */
/*                          Advance Functions                                 */
/* ========================================================================== */

/**
 *  @brief   This API is used get the MCAN revision ID.
 *
 *  @param[in]  mcan     Pointer to the register overlay for the peripheral
 *  @param[in]  revId    Contains Revision ID of MCAN module.
 *                       @ref DL_MCAN_RevisionId.
 *
 *  @return  None.
 */
void DL_MCAN_getRevisionId(MCAN_Regs *mcan, DL_MCAN_RevisionId *revId);

/**
 *  @brief   This API get clock stop acknowledgement for MCAN module.
 *          It return whether MCAN is power down mode or not.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  status  Return Clock Stop Acknowledgement status.
 *                   Return '1' if M_CAN is set in power down mode else
 *                   returns '0'.
 */
uint32_t DL_MCAN_getClockStopAck(MCAN_Regs *mcan);

/**
 *  @brief   This API will set External TimeStamp Counter Overflow Interrupt
 *          Raw status for MCAN module.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  None.
 */
void DL_MCAN_extTSSetRawStatus(MCAN_Regs *mcan);

/**
 *  @brief   This API will clear External TimeStamp Counter Overflow Interrupt
 *          raw status for MCAN module.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  None.
 */
void DL_MCAN_extTSClearRawStatus(MCAN_Regs *mcan);

/**
 *  @brief   This API will return Rx pin state of MCAN module.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  state    MCAN Rx Pin State.
 *                    0= The CAN bus is dominant
 *                    1= The CAN bus is recessive
 */
uint32_t DL_MCAN_getRxPinState(MCAN_Regs *mcan);

/**
 *  @brief   This API will set Tx pin state of MCAN module.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *  @param[in]  state MCAN Tx Pin State.
 *                    00= Reset value
 *                    01= Sample Point can be monitored at tx pin
 *                    10= The CAN bus is dominant
 *                    11= The CAN bus is recessive
 *                    other= It will treated as 11.
 *
 *  @return  None.
 */
void DL_MCAN_setTxPinState(MCAN_Regs *mcan, uint32_t state);

/**
 *  @brief   This API will return Tx pin state of MCAN module.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  state    MCAN Tx Pin State.
 *                    00= Reset value
 *                    01= Sample Point can be monitored at tx pin
 *                    10= The CAN bus is dominant
 *                    11= The CAN bus is recessive
 */
uint32_t DL_MCAN_getTxPinState(MCAN_Regs *mcan);

/**
 *  @brief   This API will return current timestamp counter value.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  val             Current Timestamp counter value.
 */
uint32_t DL_MCAN_getTSCounterVal(MCAN_Regs *mcan);

/**
 *  @brief   This API will return clock stop acknowledgement
 *          for MCAN module.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  ack   Clock Stop Acknowledge
 *                 0= No clock stop acknowledged
 *                 1= M_CAN may be set in power down
 */
uint32_t DL_MCAN_getClkStopAck(MCAN_Regs *mcan);

/**
 *  @brief   This API will get the configured bit timings for MCAN module.
 *
 *  @param[in]  mcan          Pointer to the register overlay for the peripheral
 *  @param[in]  configParams  Configuration parameters for MCAN bit timing.
 *                            @ref DL_MCAN_BitTimingParams.
 *
 *  @return  None.
 */
void DL_MCAN_getBitTime(
    MCAN_Regs *mcan, DL_MCAN_BitTimingParams *configParams);

/**
 *  @brief   This API will reset timestamp counter value.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  None.
 */
void DL_MCAN_resetTSCounter(MCAN_Regs *mcan);

/**
 *  @brief   This API will return current time-out counter value.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  val      Current Time-out counter value.
 */
uint32_t DL_MCAN_getTOCounterVal(MCAN_Regs *mcan);

/**
 *  @brief   This API is used get the ECC AGGR revision ID.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *  @param[in]  revId Contains Revision ID of ECC AGGR.
 *                    @ref DL_MCAN_ECCAggrRevisionId.
 *
 *  @return  None.
 */
void DL_MCAN_eccAggrGetRevisionId(
    MCAN_Regs *mcan, DL_MCAN_ECCAggrRevisionId *revId);

/**
 *  @brief   This API is used get the ECC Wrapper revision ID.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *  @param[in]  revId Contains Revision ID of ECC Wrapper
 *                    @ref DL_MCAN_ECCWrapRevisionId.
 *
 *  @return  None.
 */
void DL_MCAN_eccWrapGetRevisionId(
    MCAN_Regs *mcan, DL_MCAN_ECCWrapRevisionId *revId);

/**
 *  @brief   This API returns External TimeStamp Counter Overflow Interrupt
 *          enable status for MCAN module.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  status   Returns TRUE if External TimeStamp Counter Overflow
 *                    Interrupt is enabled.
 *                    Else returns FALSE.
 */
bool DL_MCAN_extTSIsIntrEnable(MCAN_Regs *mcan);

/**
 *  @brief   This function return endianness value of MCAN module.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 * @retval  val             Endianness value. (0x87654321)
 */
uint32_t DL_MCAN_getEndianVal(MCAN_Regs *mcan);

/**
 *  @brief   This API will get the configured Extended ID AND Mask.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return  idMask          Extended ID AND Mask.
 */
uint32_t DL_MCAN_getExtIDANDMask(MCAN_Regs *mcan);

/**
 * @brief Enables power on MCAN module
 *
 *  @param mcan         Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_MCAN_enablePower(MCAN_Regs *mcan)
{
    mcan->MCANSS.PWREN = (MCAN_PWREN_KEY_UNLOCK_W | MCAN_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Disables power on mcan module
 *
 *  @param mcan         Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_MCAN_disablePower(MCAN_Regs *mcan)
{
    mcan->MCANSS.PWREN = (MCAN_PWREN_KEY_UNLOCK_W | MCAN_PWREN_ENABLE_DISABLE);
}

/**
 * @brief Returns if  power on mcan module
 *
 *  @param mcan         Pointer to the register overlay for the peripheral
 *
 *  @return true if power is enabled
 *  @return false if power is disabled
 */
__STATIC_INLINE bool DL_MCAN_isPowerEnabled(MCAN_Regs *mcan)
{
    return ((mcan->MCANSS.PWREN & MCAN_PWREN_ENABLE_MASK) ==
            MCAN_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Resets mcan peripheral
 *
 *  @param mcan         Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_MCAN_reset(MCAN_Regs *mcan)
{
    mcan->MCANSS.RSTCTL =
        (MCAN_RSTCTL_KEY_UNLOCK_W | MCAN_RSTCTL_RESETSTKYCLR_CLR |
            MCAN_RSTCTL_RESETASSERT_ASSERT);
}

/**
 * @brief Returns if mcan peripheral was reset
 *
 *  @param mcan         Pointer to the register overlay for the peripheral
 *
 *  @return true if peripheral was reset
 *  @return false if peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_MCAN_isReset(MCAN_Regs *mcan)
{
    return ((mcan->MCANSS.STAT & MCAN_STAT_RESETSTKY_MASK) ==
            MCAN_STAT_RESETSTKY_RESET);
}

/**
 *  @brief      Enable MCAN interrupts
 *
 *  @param[in]  mcan           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_MCAN_INTERRUPT.
 */
__STATIC_INLINE void DL_MCAN_enableInterrupt(
    MCAN_Regs *mcan, uint32_t interruptMask)
{
    mcan->MCANSS.TI_WRAPPER.MSP.CPU_INT.IMASK |= interruptMask;
}

/**
 *  @brief      Disable MCAN interrupts
 *
 *  @param[in]  mcan           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to disable. Bitwise OR of
 *                             mcan interrupts.
 */
__STATIC_INLINE void DL_MCAN_disableInterrupt(
    MCAN_Regs *mcan, uint32_t interruptMask)
{
    mcan->MCANSS.TI_WRAPPER.MSP.CPU_INT.IMASK &= ~(interruptMask);
}

/**
 *  @brief      Check which MCAN interrupts are enabled
 *
 *  @param[in]  mcan           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_MCAN_INTERRUPT.
 *
 *  @return     Which of the requested MCAN interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_MCAN_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_MCAN_getEnabledInterrupts(
    MCAN_Regs *mcan, uint32_t interruptMask)
{
    return (mcan->MCANSS.TI_WRAPPER.MSP.CPU_INT.IMASK & interruptMask);
}

/**
 *  @brief      Check interrupt flag of enabled MCAN interrupts
 *
 *  Checks if any of the MCAN interrupts that were previously enabled are
 *  pending.
 *
 *  @param[in]  mcan           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_MCAN_INTERRUPT.
 *
 *  @return     Which of the requested MCAN interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_MCAN_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_MCAN_getEnabledInterruptStatus(
    MCAN_Regs *mcan, uint32_t interruptMask)
{
    return (mcan->MCANSS.TI_WRAPPER.MSP.CPU_INT.MIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of any MCAN interrupt
 *
 *  Checks if any of the MCAN interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  mcan           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_MCAN_INTERRUPT.
 *
 *  @return     Which of the requested MCAN interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_MCAN_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_MCAN_getRawInterruptStatus(
    MCAN_Regs *mcan, uint32_t interruptMask)
{
    return (mcan->MCANSS.TI_WRAPPER.MSP.CPU_INT.RIS & interruptMask);
}

/**
 *  @brief      Get highest priority pending MCAN interrupt
 *
 *  Checks if any of the MCAN interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return     The highest priority pending MCAN interrupt. One of
 *              @ref DL_MCAN_IIDX
 *
 */
__STATIC_INLINE DL_MCAN_IIDX DL_MCAN_getPendingInterrupt(MCAN_Regs *mcan)
{
    // TODO: Need to figure out return values for this.
    return ((DL_MCAN_IIDX) mcan->MCANSS.TI_WRAPPER.MSP.CPU_INT.IIDX);
}

/**
 *  @brief      Clear pending MCAN interrupts
 *
 *  @param[in]  mcan           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_MCAN_INTERRUPT.
 */
__STATIC_INLINE void DL_MCAN_clearInterruptStatus(
    MCAN_Regs *mcan, uint32_t interruptMask)
{
    mcan->MCANSS.TI_WRAPPER.MSP.CPU_INT.ICLR = interruptMask;
}

/**
 *  @brief      Checks if the MCAN module clock request is enabled
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return     If the MCAN module clock request is enabled
 *
 */
__STATIC_INLINE bool DL_MCAN_isModuleClockEnabled(MCAN_Regs *mcan)
{
    return ((mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKEN &
                MCAN_CLKEN_CLK_REQEN_MASK) == MCAN_CLKEN_CLK_REQEN_SET);
}

/**
 *  @brief      Enables the MCAN functional module clock
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MCAN_enableModuleClock(MCAN_Regs *mcan)
{
    mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKEN = MCAN_CLKEN_CLK_REQEN_SET;
}

/**
 *  @brief      Disables the MCAN functional module clock
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MCAN_disableModuleClock(MCAN_Regs *mcan)
{
    mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKEN = MCAN_CLKEN_CLK_REQEN_CLR;
}

/**
 *  @brief      Gets the MCAN functional module clock divide ratio
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return     The current clock divide ratio, one of @ref DL_MCAN_CLOCK_DIVIDE
 *
 */
__STATIC_INLINE uint32_t DL_MCAN_getModuleClockDivider(MCAN_Regs *mcan)
{
    return (
        mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKDIV & MCAN_CLKDIV_RATIO_MASK);
}

/**
 *  @brief      Configures clock divide settings for the MCAN functional module
 *              clock
 *
 *  @param[in]  mcan    Pointer to the register overlay for the peripheral
 *  @param[in]  clkdiv  The desired clock divide ratio, one of
 *                      @ref DL_MCAN_CLOCK_DIVIDE
 *
 */
__STATIC_INLINE void DL_MCAN_setModuleClockDivider(
    MCAN_Regs *mcan, uint32_t clkdiv)
{
    DL_Common_updateReg(&mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKDIV, clkdiv,
        MCAN_CLKDIV_RATIO_MASK);
}

/**
 *  @brief      Checks if the MCAN clock gating request is enabled
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return     If the the MCAN module clock gating request is enabled/disabled
 *
 */
__STATIC_INLINE bool DL_MCAN_isClockStopGateRequestEnabled(MCAN_Regs *mcan)
{
    return ((mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKCTL &
                MCAN_CLKCTL_STOPREQ_MASK) == MCAN_CLKCTL_STOPREQ_ENABLE);
}

/**
 *  @brief      Enables the MCAN clock gating request
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MCAN_enableClockStopGateRequest(MCAN_Regs *mcan)
{
    DL_Common_updateReg(&mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKCTL,
        MCAN_CLKCTL_STOPREQ_ENABLE, MCAN_CLKCTL_STOPREQ_MASK);
}

/**
 *  @brief      Disables the MCAN clock gating request
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MCAN_disableClockStopGateRequest(MCAN_Regs *mcan)
{
    DL_Common_updateReg(&mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKCTL,
        MCAN_CLKCTL_STOPREQ_DISABLE, MCAN_CLKCTL_STOPREQ_MASK);
}

/**
 *  @brief      Checks if the MCAN clock stop wakeup interrupt is enabled
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return     If the the MCAN module clock wakeup interrupt is
 *              enabled/disabled
 *
 */
__STATIC_INLINE bool DL_MCAN_isClockStopWakeupInterruptEnabled(MCAN_Regs *mcan)
{
    return ((mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKCTL &
                MCAN_CLKCTL_WAKEUP_INT_EN_MASK) ==
            MCAN_CLKCTL_WAKEUP_INT_EN_ENABLE);
}

/**
 *  @brief      Enables the MCAN clock stop wakeup interrupt
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MCAN_enableClockStopWakeupInterrupt(MCAN_Regs *mcan)
{
    DL_Common_updateReg(&mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKCTL,
        MCAN_CLKCTL_WAKEUP_INT_EN_ENABLE, MCAN_CLKCTL_WAKEUP_INT_EN_MASK);
}

/**
 *  @brief      Disables the MCAN clock stop wakeup interrupt
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MCAN_disableClockStopWakeupInterrupt(MCAN_Regs *mcan)
{
    DL_Common_updateReg(&mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKCTL,
        MCAN_CLKCTL_WAKEUP_INT_EN_DISABLE, MCAN_CLKCTL_WAKEUP_INT_EN_MASK);
}

/**
 *  @brief      Checks if the glitch filter on MCAN RXD input is enabled
 *
 *  When the glitch filter is enabled in MCAN RXD input, it wakes up the MCAN
 *  controller to exit clock gating
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return     If the the glitch filter on MCAN RXD input is enabled/disabled
 *
 */
__STATIC_INLINE bool DL_MCAN_isGlitchFilterWakeupEnabled(MCAN_Regs *mcan)
{
    return ((mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKCTL &
                MCAN_CLKCTL_WKUP_GLTFLT_EN_MASK) ==
            MCAN_CLKCTL_WKUP_GLTFLT_EN_ENABLE);
}

/**
 *  @brief      Enables the glitch filter on MCAN RXD input
 *
 *  When the glitch filter is enabled in MCAN RXD input, it wakes up the MCAN
 *  controller to exit clock gating
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MCAN_enableGlitchFilterWakeup(MCAN_Regs *mcan)
{
    DL_Common_updateReg(&mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKCTL,
        MCAN_CLKCTL_WKUP_GLTFLT_EN_ENABLE, MCAN_CLKCTL_WKUP_GLTFLT_EN_MASK);
}

/**
 *  @brief      Disables the glitch filter on MCAN RXD input
 *
 *  When the glitch filter is enabled in MCAN RXD input, it wakes up the MCAN
 *  controller to exit clock gating
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MCAN_disableGlitchFilterWakeup(MCAN_Regs *mcan)
{
    DL_Common_updateReg(&mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKCTL,
        MCAN_CLKCTL_WKUP_GLTFLT_EN_DISABLE, MCAN_CLKCTL_WKUP_GLTFLT_EN_MASK);
}

/**
 *  @brief      Gets the clock stop acknowledge status
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return     The clock stop acknowledge status
 *
 */
__STATIC_INLINE bool DL_MCAN_getClockStopAcknowledgeStatus(MCAN_Regs *mcan)
{
    return ((mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKSTS &
                MCAN_CLKSTS_CLKSTOP_ACKSTS_MASK) ==
            MCAN_CLKSTS_CLKSTOP_ACKSTS_SET);
}

/**
 *  @brief      Gets the clock stop hardware override status
 *
 *  This bit indicates when the MCANSS_CLKCTL.STOPREQ bit has been cleared by
 *  HW when a clock-stop wake-up event via CAN RX activity is triggered
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return     The clock stop hardware override status
 *
 */
__STATIC_INLINE bool DL_MCAN_getClockStopHardwareOverrideStatus(
    MCAN_Regs *mcan)
{
    return ((mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKSTS &
                MCAN_CLKSTS_STOPREQ_HW_OVR_MASK) ==
            MCAN_CLKSTS_STOPREQ_HW_OVR_SET);
}

/**
 *  @brief      Gets the status of MCAN controller clock request from GPRCM
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of the MCAN controller clock request from GPRCM
 *
 */
__STATIC_INLINE bool DL_MCAN_getControllerClockRequestStatus(MCAN_Regs *mcan)
{
    return ((mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKSTS &
                MCAN_CLKSTS_CCLKDONE_MASK) == MCAN_CLKSTS_CCLKDONE_SET);
}

/**
 *  @brief      Saves MCAN configuration before entering STOP or STANDBY mode.
 *              Only necessary for PG 1.0 silicon.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr   Configuration backup setup structure. See
 *                       @ref DL_MCAN_backupConfig.
 *
 *  @retval     FALSE if a configuration already exists in ptr (will not be
 *              overwritten). TRUE if a configuration was successfully saved
 *
 */
bool DL_MCAN_saveConfiguration(MCAN_Regs *mcan, DL_MCAN_backupConfig *ptr);

/**
 *  @brief      Restore MCAN configuration after leaving STOP or STANDBY mode.
 *              Only necessary for PG 1.0 silicon.
 *
 *  @param[in]  mcan  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr      Configuration backup setup structure. See
 *                       @ref DL_MCAN_backupConfig.
 *
 *  @retval     FALSE if a configuration does not exist in ptr (will not be
 *              loaded). TRUE if a configuration successfully loaded
 *
 */
bool DL_MCAN_restoreConfiguration(MCAN_Regs *mcan, DL_MCAN_backupConfig *ptr);

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_MCAN__ */

#endif /* ti_dl_dl_mcan__include */
/** @}*/
