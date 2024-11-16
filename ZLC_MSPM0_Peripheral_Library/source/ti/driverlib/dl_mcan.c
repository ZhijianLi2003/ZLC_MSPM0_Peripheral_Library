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

#include <ti/driverlib/dl_mcan.h>

#ifdef __MSPM0_HAS_MCAN__

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 * \brief  MCAN MSG RAM BANK number for ECC AGGR.
 */
#define MCANSS_MSG_RAM_NUM (0U)

/**
 * \brief  Maximum Number of Rx Buffers.
 */
#define MCANSS_RX_BUFFER_MAX (64U)

/**
 * \brief  Maximum Number of Tx Buffers.
 */
#define MCANSS_TX_BUFFER_MAX (32U)

/**
 * \brief  Macro for standard Message ID filter.
 */
#define MCANSS_STD_ID_FILTER_SIZE_WORDS (1U)

/**
 * \brief  Macro for extended Message ID filter.
 */
#define MCANSS_EXT_ID_FILTER_SIZE_WORDS (2U)

/**
 * \brief  Macro for Tx Event FIFO element size.
 */
#define MCANSS_TX_EVENT_FIFO_SIZE_WORDS (2U)

/**
 * \brief  Macro for Interrupt Line enable mask.
 */
#define MCANSS_INTR_LINE_EN_MASK ((MCAN_ILE_EINT0_MASK | MCAN_ILE_EINT1_MASK))

/**
 * \brief  Mask and shift for Tx Buffers elements.
 */
#define MCANSS_TX_BUFFER_ELEM_ID_SHIFT (0U)
#define MCANSS_TX_BUFFER_ELEM_ID_MASK (0x1FFFFFFFU)
#define MCANSS_TX_BUFFER_ELEM_RTR_SHIFT (29U)
#define MCANSS_TX_BUFFER_ELEM_RTR_MASK (0x20000000U)
#define MCANSS_TX_BUFFER_ELEM_XTD_SHIFT (30U)
#define MCANSS_TX_BUFFER_ELEM_XTD_MASK (0x40000000U)
#define MCANSS_TX_BUFFER_ELEM_ESI_SHIFT (31U)
#define MCANSS_TX_BUFFER_ELEM_ESI_MASK (0x80000000U)
#define MCANSS_TX_BUFFER_ELEM_DLC_SHIFT (16U)
#define MCANSS_TX_BUFFER_ELEM_DLC_MASK (0x000F0000U)
#define MCANSS_TX_BUFFER_ELEM_BRS_SHIFT (20U)
#define MCANSS_TX_BUFFER_ELEM_BRS_MASK (0x00100000U)
#define MCANSS_TX_BUFFER_ELEM_FDF_SHIFT (21U)
#define MCANSS_TX_BUFFER_ELEM_FDF_MASK (0x00200000U)
#define MCANSS_TX_BUFFER_ELEM_EFC_SHIFT (23U)
#define MCANSS_TX_BUFFER_ELEM_EFC_MASK (0x00800000U)
#define MCANSS_TX_BUFFER_ELEM_MM_SHIFT (24U)
#define MCANSS_TX_BUFFER_ELEM_MM_MASK (0xFF000000U)

/**
 * \brief  Mask and shift for Rx Buffers elements.
 */
#define MCANSS_RX_BUFFER_ELEM_ID_SHIFT (0U)
#define MCANSS_RX_BUFFER_ELEM_ID_MASK (0x1FFFFFFFU)
#define MCANSS_RX_BUFFER_ELEM_RTR_SHIFT (29U)
#define MCANSS_RX_BUFFER_ELEM_RTR_MASK (0x20000000U)
#define MCANSS_RX_BUFFER_ELEM_XTD_SHIFT (30U)
#define MCANSS_RX_BUFFER_ELEM_XTD_MASK (0x40000000U)
#define MCANSS_RX_BUFFER_ELEM_ESI_SHIFT (31U)
#define MCANSS_RX_BUFFER_ELEM_ESI_MASK (0x80000000U)
#define MCANSS_RX_BUFFER_ELEM_RXTS_SHIFT (0U)
#define MCANSS_RX_BUFFER_ELEM_RXTS_MASK (0x0000FFFFU)
#define MCANSS_RX_BUFFER_ELEM_DLC_SHIFT (16U)
#define MCANSS_RX_BUFFER_ELEM_DLC_MASK (0x000F0000U)
#define MCANSS_RX_BUFFER_ELEM_BRS_SHIFT (20U)
#define MCANSS_RX_BUFFER_ELEM_BRS_MASK (0x00100000U)
#define MCANSS_RX_BUFFER_ELEM_FDF_SHIFT (21U)
#define MCANSS_RX_BUFFER_ELEM_FDF_MASK (0x00200000U)
#define MCANSS_RX_BUFFER_ELEM_FIDX_SHIFT (24U)
#define MCANSS_RX_BUFFER_ELEM_FIDX_MASK (0x7F000000U)
#define MCANSS_RX_BUFFER_ELEM_ANMF_SHIFT (31U)
#define MCANSS_RX_BUFFER_ELEM_ANMF_MASK (0x80000000U)

/**
 * \brief  Mask and shift for Standard Message ID Filter Elements.
 */
#define MCANSS_STD_ID_FILTER_SFID2_SHIFT (0U)
#define MCANSS_STD_ID_FILTER_SFID2_MASK (0x000003FFU)
#define MCANSS_STD_ID_FILTER_SFID1_SHIFT (16U)
#define MCANSS_STD_ID_FILTER_SFID1_MASK (0x03FF0000U)
#define MCANSS_STD_ID_FILTER_SFEC_SHIFT (27U)
#define MCANSS_STD_ID_FILTER_SFEC_MASK (0x38000000U)
#define MCANSS_STD_ID_FILTER_SFT_SHIFT (30U)
#define MCANSS_STD_ID_FILTER_SFT_MASK (0xC0000000U)

/**
 * \brief  Extended Message ID Filter Element.
 */
#define MCANSS_EXT_ID_FILTER_EFID2_SHIFT (0U)
#define MCANSS_EXT_ID_FILTER_EFID2_MASK (0x1FFFFFFFU)
#define MCANSS_EXT_ID_FILTER_EFID1_SHIFT (0U)
#define MCANSS_EXT_ID_FILTER_EFID1_MASK (0x1FFFFFFFU)
#define MCANSS_EXT_ID_FILTER_EFEC_SHIFT (29U)
#define MCANSS_EXT_ID_FILTER_EFEC_MASK (0xE0000000U)
#define MCANSS_EXT_ID_FILTER_EFT_SHIFT (30U)
#define MCANSS_EXT_ID_FILTER_EFT_MASK (0xC0000000U)

/**
 * \brief  Mask and shift for Tx Event FIFO elements.
 */
#define MCANSS_TX_EVENT_FIFO_ELEM_ID_SHIFT (0U)
#define MCANSS_TX_EVENT_FIFO_ELEM_ID_MASK (0x1FFFFFFFU)
#define MCANSS_TX_EVENT_FIFO_ELEM_RTR_SHIFT (29U)
#define MCANSS_TX_EVENT_FIFO_ELEM_RTR_MASK (0x20000000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_XTD_SHIFT (30U)
#define MCANSS_TX_EVENT_FIFO_ELEM_XTD_MASK (0x40000000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_ESI_SHIFT (31U)
#define MCANSS_TX_EVENT_FIFO_ELEM_ESI_MASK (0x80000000U)

#define MCANSS_TX_EVENT_FIFO_ELEM_TXTS_SHIFT (0U)
#define MCANSS_TX_EVENT_FIFO_ELEM_TXTS_MASK (0x0000FFFFU)
#define MCANSS_TX_EVENT_FIFO_ELEM_DLC_SHIFT (16U)
#define MCANSS_TX_EVENT_FIFO_ELEM_DLC_MASK (0x000F0000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_BRS_SHIFT (20U)
#define MCANSS_TX_EVENT_FIFO_ELEM_BRS_MASK (0x00100000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_FDF_SHIFT (21U)
#define MCANSS_TX_EVENT_FIFO_ELEM_FDF_MASK (0x00200000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_ET_SHIFT (22U)
#define MCANSS_TX_EVENT_FIFO_ELEM_ET_MASK (0x00C00000U)
#define MCANSS_TX_EVENT_FIFO_ELEM_MM_SHIFT (24U)
#define MCANSS_TX_EVENT_FIFO_ELEM_MM_MASK (0xFF000000U)

#define HW_RD_REG32(addr) (uint32_t)(HW_RD_REG32_RAW((uint32_t)(addr)))

#define HW_WR_REG32(addr, value) \
    (HW_WR_REG32_RAW((uint32_t)(addr), (uint32_t)(value)))

#define HW_GET_FIELD(regVal, REG_FIELD) \
    (((regVal) & (uint32_t) REG_FIELD##_MASK) >> (uint32_t) REG_FIELD##_OFS)

#define HW_SET_FIELD32(regVal, REG_FIELD, fieldVal)                       \
    ((regVal) = ((regVal) & (uint32_t)(~(uint32_t) REG_FIELD##_MASK)) |   \
                ((((uint32_t)(fieldVal)) << (uint32_t) REG_FIELD##_OFS) & \
                    (uint32_t) REG_FIELD##_MASK))

#define HW_WR_FIELD32(regAddr, REG_FIELD, fieldVal)                      \
    (HW_WR_FIELD32_RAW((uint32_t)(regAddr), (uint32_t) REG_FIELD##_MASK, \
        (uint32_t) REG_FIELD##_OFS, (uint32_t)(fieldVal)))

#define HW_RD_FIELD32(regAddr, REG_FIELD)                                \
    (HW_RD_FIELD32_RAW((uint32_t)(regAddr), (uint32_t) REG_FIELD##_MASK, \
        (uint32_t) REG_FIELD##_OFS))

#define STW_SOK ((int32_t) 0)
#define STW_EFAIL (-((int32_t) 1))
#define STW_EBADARGS (-((int32_t) 2))
#define STW_EINVALID_PARAMS (-((int32_t) 3))
#define STW_ETIMEOUT (-((int32_t) 4))
#define STW_EOUT_OF_RANGE (-((int32_t) 5))
#define STW_EUNSUPPORTED_CMD (-((int32_t) 6))
#define STW_EUNSUPPORTED_OPS (-((int32_t) 7))

#define MCAN_MCAN_MSG_MEM (0x0U)

/* To fix Misra-C errors */
#ifndef TRUE
#define TRUE ((Bool) 1)
#endif
#ifndef FALSE
#define FALSE ((Bool) 0)
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API will unblock write access to write protected registers.
 *
 * \param   mcan        Base Address of the MCAN Registers.
 *
 * \return  None.
 */
static void DL_MCAN_writeProtectedRegAccessUnlock(MCAN_Regs *mcan);

/**
 * \brief   This API will block write access to write protected registers.
 *
 * \param   mcan        Base Address of the MCAN Registers.
 *
 * \return  None.
 */
static void DL_MCAN_writeProtectedRegAccessLock(MCAN_Regs *mcan);

/**
 * \brief   This API will load the register from ECC memory bank.
 *
 * \param   mcan        Base Address of the MCAN Registers.
 * \param   regOffset       Offset of the register to read.
 *
 * \return  None.
 */
static void DL_MCAN_eccLoadRegister(MCAN_Regs *mcan, uint32_t regOffset);

/**
 * \brief   This API will read the message object from Message RAM.
 *
 * \param   mcan        Base Address of the MCAN Registers.
 * \param   elemAddr        Address of the message object.
 * \param   elem            Message Object.
 *                          Refer struct #DL_MCAN_RxBufElement.
 *
 * \return  None.
 */
static void DL_MCAN_readMsg(
    uint32_t mcan, uint32_t elemAddr, DL_MCAN_RxBufElement *elem);

/**
 * \brief   This API will write the message object to Message RAM.
 *
 * \param   mcan        Base Address of the MCAN Registers.
 * \param   elemAddr        Address of the message object.
 * \param   elem            Message Object.
 *                          Refer struct #MCAN_TXBufElement.
 *
 * \return  None.
 */
static void DL_MCAN_writeMsg(
    uint32_t mcan, uint32_t elemAddr, const DL_MCAN_TxBufElement *elem);

/**
 * \brief   This API will return payload depending on 'dlc'  field.
 *
 * \param   dlc             Data Length Code.
 *
 * \return  data size       Size of the payload.
 */
static uint32_t DL_MCAN_getDataSize(uint32_t dlc);

/**
 * \brief   This API will return message object size.
 *
 * \param   elemSize        Element Size.
 *
 * \return  message object size
 *                          Size of the message object stored in Message RAM.
 */
static uint32_t DL_MCAN_getMsgObjSize(uint32_t elemSize);

/**
 *  \brief   This function reads a 32-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 32-bit value read from a register.
 */
__STATIC_INLINE uint32_t HW_RD_REG32_RAW(uint32_t addr);

/**
 *  \brief   This function writes a 32-bit value to a hardware register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   value   unsigned 32-bit value which has to be written to the
 *                   register.
 */
__STATIC_INLINE void HW_WR_REG32_RAW(uint32_t addr, uint32_t value);

/**
 *  \brief   This function reads a 32 bit register, modifies specific set of
 *           bits and writes back to the register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   mask    Mask for the bit field.
 *  \param   shift   Bit field shift from LSB.
 *  \param   value   Value to be written to bit-field.
 */
__STATIC_INLINE void HW_WR_FIELD32_RAW(
    uint32_t addr, uint32_t mask, uint32_t shift, uint32_t value);

/**
 *  \brief   This function reads a 32 bit register, masks specific set of bits
 *           and the left shifted value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   mask    Mask for the bit field.
 *  \param   shift   Bit field shift from LSB.
 *
 *  \return  Bit-field value (absolute value - shifted to LSB position)
 */
__STATIC_INLINE uint32_t HW_RD_FIELD32_RAW(
    uint32_t addr, uint32_t mask, uint32_t shift);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

bool DL_MCAN_isReady(DL_MCAN_INSTANCE instance)
{
    return ((SYSCTL->SOCLOCK.SYSSTATUS & (uint32_t) instance) ==
            (uint32_t) instance);
}

void DL_MCAN_setClockConfig(MCAN_Regs *mcan, DL_MCAN_ClockConfig *config)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.GENCLKCFG,
        (uint32_t) config->clockSel, SYSCTL_GENCLKCFG_CANCLKSRC_MASK);

    mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKDIV = (uint32_t) config->divider;
}

void DL_MCAN_getClockConfig(MCAN_Regs *mcan, DL_MCAN_ClockConfig *config)
{
    uint32_t clockSource =
        (SYSCTL->SOCLOCK.GENCLKCFG & SYSCTL_GENCLKCFG_CANCLKSRC_MASK);

    config->clockSel = (DL_MCAN_FCLK)(clockSource);
}

bool DL_MCAN_isInReset(MCAN_Regs *mcan)
{
    uint32_t reset;
    bool state;

    reset = HW_RD_FIELD32(
        &mcan->MCANSS.STAT, MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT_RESET);
    if (1U == reset) {
        state = true;
    } else {
        state = false;
    }
    return state;
}

bool DL_MCAN_isFDOpEnable(MCAN_Regs *mcan)
{
    uint32_t fdoe;
    bool state;

    fdoe = HW_RD_FIELD32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_STAT,
        MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT_ENABLE_FDOE);
    if (1U == fdoe) {
        state = true;
    } else {
        state = false;
    }
    return state;
}

bool DL_MCAN_isMemInitDone(MCAN_Regs *mcan)
{
    uint32_t memInit;
    bool state;

    memInit = HW_RD_FIELD32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_STAT,
        MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT_MEM_INIT_DONE);
    if (1U == memInit) {
        state = true;
    } else {
        state = false;
    }
    return state;
}

void DL_MCAN_setOpMode(MCAN_Regs *mcan, uint32_t mode)
{
    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_INIT, mode);
}

uint32_t DL_MCAN_getOpMode(MCAN_Regs *mcan)
{
    return (HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_INIT));
}

int32_t DL_MCAN_init(MCAN_Regs *mcan, const DL_MCAN_InitParams *initParams)
{
    int32_t status;
    uint32_t regVal;

    /* Configure MCAN wakeup and clock stop controls */
    regVal = HW_RD_REG32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_CTRL);
    HW_SET_FIELD32(regVal, MCAN_TI_WRAPPER_REGS_CTRL_WAKEUPREQEN,
        initParams->wkupReqEnable);
    HW_SET_FIELD32(regVal, MCAN_TI_WRAPPER_REGS_CTRL_AUTOWAKEUP,
        initParams->autoWkupEnable);
    HW_SET_FIELD32(regVal, MCAN_TI_WRAPPER_REGS_CTRL_DBGSUSP_FREE,
        initParams->emulationEnable);

    HW_WR_REG32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_CTRL, regVal);

    DL_MCAN_writeProtectedRegAccessUnlock(mcan);

    /* Configure MCAN mode(FD vs Classic CAN operation) and controls */
    regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_CCCR);
    HW_SET_FIELD32(regVal, MCAN_CCCR_FDOE, initParams->fdMode);
    HW_SET_FIELD32(regVal, MCAN_CCCR_BRSE, initParams->brsEnable);
    HW_SET_FIELD32(regVal, MCAN_CCCR_TXP, initParams->txpEnable);
    HW_SET_FIELD32(regVal, MCAN_CCCR_EFBI, initParams->efbi);
    HW_SET_FIELD32(regVal, MCAN_CCCR_PXHD, initParams->pxhddisable);
    HW_SET_FIELD32(regVal, MCAN_CCCR_DAR, initParams->darEnable);
    HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_CCCR, regVal);

    if ((DL_MCAN_TDCR_TDCF_MAX >= initParams->tdcConfig.tdcf) &&
        (DL_MCAN_TDCR_TDCO_MAX >= initParams->tdcConfig.tdco) &&
        (DL_MCAN_RWD_WDC_MAX >= initParams->wdcPreload)) {
        /* Configure Transceiver Delay Compensation */
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TDCR, MCAN_TDCR_TDCF,
            initParams->tdcConfig.tdcf);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TDCR, MCAN_TDCR_TDCO,
            initParams->tdcConfig.tdco);
        /* Configure MSG RAM watchdog counter preload value */
        HW_WR_FIELD32(
            &mcan->MCANSS.MCAN.MCAN_RWD, MCAN_RWD_WDC, initParams->wdcPreload);
        /* Enable/Disable Transceiver Delay Compensation */
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_DBTP, MCAN_DBTP_TDC,
            initParams->tdcEnable);
        status = STW_SOK;
    } else {
        status = STW_EFAIL;
    }

    DL_MCAN_writeProtectedRegAccessLock(mcan);

    return status;
}

int32_t DL_MCAN_config(
    MCAN_Regs *mcan, const DL_MCAN_ConfigParams *configParams)
{
    int32_t status;

    DL_MCAN_writeProtectedRegAccessUnlock(mcan);

    /* Configure MCAN control registers */
    HW_WR_FIELD32(
        &mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_MON, configParams->monEnable);
    HW_WR_FIELD32(
        &mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_ASM, configParams->asmEnable);
    /* Configure Global Filter */
    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_GFC, MCAN_GFC_RRFE,
        configParams->filterConfig.rrfe);
    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_GFC, MCAN_GFC_RRFS,
        configParams->filterConfig.rrfs);
    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_GFC, MCAN_GFC_ANFE,
        configParams->filterConfig.anfe);
    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_GFC, MCAN_GFC_ANFS,
        configParams->filterConfig.anfs);

    if ((DL_MCAN_TSCC_TCP_MAX >= configParams->tsPrescalar) &&
        (DL_MCAN_TOCC_TOP_MAX >= configParams->timeoutPreload)) {
        /* Configure Time-stamp counter */
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TSCC, MCAN_TSCC_TSS,
            configParams->tsSelect);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TSCC, MCAN_TSCC_TCP,
            (configParams->tsPrescalar - 1U));
        /* Configure Time-out counter */
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TOCC, MCAN_TOCC_TOS,
            configParams->timeoutSelect);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TOCC, MCAN_TOCC_TOP,
            configParams->timeoutPreload);
        /* Enable Time-out counter */
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TOCC, MCAN_TOCC_ETOC,
            configParams->timeoutCntEnable);
        status = STW_SOK;
    } else {
        status = STW_EFAIL;
    }

    DL_MCAN_writeProtectedRegAccessLock(mcan);

    return status;
}

void DL_MCAN_eccConfig(
    MCAN_Regs *mcan, const DL_MCAN_ECCConfigParams *configParams)
{
    DL_MCAN_eccLoadRegister(mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER
                                      .PROCESSORS.MCAN_ECC_REGS.MCANERR_CTRL);
    HW_WR_FIELD32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_CTRL,
        MCAN_TI_WRAPPER_ECC_REGS_CTRL_ECC_CHECK, configParams->enableChk);
    DL_MCAN_eccLoadRegister(mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER
                                      .PROCESSORS.MCAN_ECC_REGS.MCANERR_CTRL);
    HW_WR_FIELD32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_CTRL,
        MCAN_TI_WRAPPER_ECC_REGS_CTRL_ECC_ENABLE, configParams->enable);
    DL_MCAN_eccLoadRegister(mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER
                                      .PROCESSORS.MCAN_ECC_REGS.MCANERR_CTRL);
    HW_WR_FIELD32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_CTRL,
        MCAN_TI_WRAPPER_ECC_REGS_CTRL_ENABLE_RMW, configParams->enableRdModWr);
    DL_MCAN_eccLoadRegister(mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER
                                      .PROCESSORS.MCAN_ECC_REGS.MCANERR_CTRL);
}

int32_t DL_MCAN_setBitTime(
    MCAN_Regs *mcan, const DL_MCAN_BitTimingParams *configParams)
{
    int32_t status;

    DL_MCAN_writeProtectedRegAccessUnlock(mcan);

    if ((DL_MCAN_NBTP_NSJW_MAX >= configParams->nomSynchJumpWidth) &&
        (DL_MCAN_NBTP_NTSEG2_MAX >= configParams->nomTimeSeg2) &&
        (DL_MCAN_NBTP_NTSEG1_MAX >= configParams->nomTimeSeg1) &&
        (DL_MCAN_NBTP_NBRP_MAX >= configParams->nomRatePrescalar)) {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_NBTP, MCAN_NBTP_NSJW,
            configParams->nomSynchJumpWidth);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_NBTP, MCAN_NBTP_NTSEG2,
            configParams->nomTimeSeg2);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_NBTP, MCAN_NBTP_NTSEG1,
            configParams->nomTimeSeg1);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_NBTP, MCAN_NBTP_NBRP,
            configParams->nomRatePrescalar);
        status = STW_SOK;
    } else {
        status = STW_EFAIL;
    }
    if (STW_SOK == status) {
        if ((DL_MCAN_DBTP_DSJW_MAX >= configParams->dataSynchJumpWidth) &&
            (DL_MCAN_DBTP_DTSEG2_MAX >= configParams->dataTimeSeg2) &&
            (DL_MCAN_DBTP_DTSEG1_MAX >= configParams->dataTimeSeg1) &&
            (DL_MCAN_DBTP_DBRP_MAX >= configParams->dataRatePrescalar)) {
            HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_DBTP, MCAN_DBTP_DSJW,
                configParams->dataSynchJumpWidth);
            HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_DBTP, MCAN_DBTP_DTSEG2,
                configParams->dataTimeSeg2);
            HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_DBTP, MCAN_DBTP_DTSEG1,
                configParams->dataTimeSeg1);
            HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_DBTP, MCAN_DBTP_DBRP,
                configParams->dataRatePrescalar);
            status = STW_SOK;
        } else {
            status = STW_EFAIL;
        }
    }

    DL_MCAN_writeProtectedRegAccessLock(mcan);
    return status;
}

int32_t DL_MCAN_msgRAMConfig(
    MCAN_Regs *mcan, const DL_MCAN_MsgRAMConfigParams *msgRAMConfigParams)
{
    int32_t status;
    uint32_t elemNum = 0U;

    DL_MCAN_writeProtectedRegAccessUnlock(mcan);

    /* Configure Message Filters section */
    if (0U != msgRAMConfigParams->lss) {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_SIDFC, MCAN_SIDFC_FLSSA,
            (msgRAMConfigParams->flssa >> 2U));
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_SIDFC, MCAN_SIDFC_LSS,
            msgRAMConfigParams->lss);
    }
    if (0U != msgRAMConfigParams->lse) {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_XIDFC, MCAN_XIDFC_FLESA,
            (msgRAMConfigParams->flesa >> 2U));
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_XIDFC, MCAN_XIDFC_LSE,
            msgRAMConfigParams->lse);
    }
    /* Configure Rx FIFO 0 section */
    if (0U != msgRAMConfigParams->rxFIFO0size) {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXF0C, MCAN_RXF0C_F0SA,
            (msgRAMConfigParams->rxFIFO0startAddr >> 2U));
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXF0C, MCAN_RXF0C_F0S,
            msgRAMConfigParams->rxFIFO0size);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXF0C, MCAN_RXF0C_F0WM,
            msgRAMConfigParams->rxFIFO0waterMark);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXF0C, MCAN_RXF0C_F0OM,
            msgRAMConfigParams->rxFIFO0OpMode);
        /* Configure Rx FIFO0 elements size */
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXESC, MCAN_RXESC_F0DS,
            msgRAMConfigParams->rxFIFO0ElemSize);
    }
    /* Configure Rx FIFO 1 section */
    if (0U != msgRAMConfigParams->rxFIFO1size) {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXF1C, MCAN_RXF1C_F1SA,
            (msgRAMConfigParams->rxFIFO1startAddr >> 2U));
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXF1C, MCAN_RXF1C_F1S,
            msgRAMConfigParams->rxFIFO1size);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXF1C, MCAN_RXF1C_F1WM,
            msgRAMConfigParams->rxFIFO1waterMark);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXF1C, MCAN_RXF1C_F1OM,
            msgRAMConfigParams->rxFIFO1OpMode);
        /* Configure Rx FIFO1 elements size */
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXESC, MCAN_RXESC_F1DS,
            msgRAMConfigParams->rxFIFO1ElemSize);
    }
    /* Configure Rx Buffer Start Address */
    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXBC, MCAN_RXBC_RBSA,
        (msgRAMConfigParams->rxBufStartAddr >> 2U));
    /* Configure Rx Buffer elements size */
    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXESC, MCAN_RXESC_RBDS,
        msgRAMConfigParams->rxBufElemSize);
    /* Configure Tx Event FIFO section */
    if (0U != msgRAMConfigParams->txEventFIFOSize) {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXEFC, MCAN_TXEFC_EFSA,
            (msgRAMConfigParams->txEventFIFOStartAddr >> 2U));
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXEFC, MCAN_TXEFC_EFS,
            msgRAMConfigParams->txEventFIFOSize);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXEFC, MCAN_TXEFC_EFWM,
            msgRAMConfigParams->txEventFIFOWaterMark);
    }
    /* Configure Tx Buffer and FIFO/Q section */
    elemNum = msgRAMConfigParams->txBufNum + msgRAMConfigParams->txFIFOSize;
    if ((MCANSS_TX_BUFFER_MAX >= elemNum) &&
        ((0U != msgRAMConfigParams->txBufNum) ||
            (0U != msgRAMConfigParams->txFIFOSize))) {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXBC, MCAN_TXBC_TBSA,
            (msgRAMConfigParams->txStartAddr >> 2U));
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXBC, MCAN_TXBC_NDTB,
            msgRAMConfigParams->txBufNum);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXBC, MCAN_TXBC_TFQS,
            msgRAMConfigParams->txFIFOSize);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXBC, MCAN_TXBC_TFQM,
            msgRAMConfigParams->txBufMode);
        /* Configure Tx Buffer/FIFO0/FIFO1 elements size */
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXESC, MCAN_TXESC_TBDS,
            msgRAMConfigParams->txBufElemSize);
        status = STW_SOK;
    } else {
        status = STW_EFAIL;
    }

    DL_MCAN_writeProtectedRegAccessLock(mcan);

    return status;
}

int32_t DL_MCAN_setExtIDAndMask(MCAN_Regs *mcan, uint32_t idMask)
{
    int32_t status;

    if (DL_MCAN_XIDAM_EIDM_MAX >= idMask) {
        DL_MCAN_writeProtectedRegAccessUnlock(mcan);

        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_XIDAM, MCAN_XIDAM_EIDM, idMask);

        DL_MCAN_writeProtectedRegAccessLock(mcan);
        status = STW_SOK;
    } else {
        status = STW_EFAIL;
    }
    return status;
}

void DL_MCAN_writeMsgRam(MCAN_Regs *mcan, uint32_t memType, uint32_t bufNum,
    const DL_MCAN_TxBufElement *elem)
{
    uint32_t startAddr = 0U, elemSize = 0U, elemAddr = 0U;
    uint32_t idx = 0U, enableMod = 0U;

    if (((uint32_t) DL_MCAN_MEM_TYPE_BUF) == memType) {
        idx       = bufNum;
        enableMod = 1U;
    }
    if (((uint32_t) DL_MCAN_MEM_TYPE_FIFO) == memType) {
        idx = HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXFQS, MCAN_TXFQS_TFQP);
        enableMod = 1U;
    }
    if (1U == enableMod) {
        startAddr =
            HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXBC, MCAN_TXBC_TBSA);
        elemSize =
            HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXESC, MCAN_TXESC_TBDS);
        startAddr = (uint32_t)(startAddr << 2U);
        elemSize  = DL_MCAN_getMsgObjSize(elemSize);
        elemSize *= 4U;
        elemAddr = startAddr + (elemSize * idx);
        elemAddr += MCAN_MCAN_MSG_MEM;
        DL_MCAN_writeMsg((uint32_t) mcan, elemAddr, elem);
    }
}

int32_t DL_MCAN_TXBufAddReq(MCAN_Regs *mcan, uint32_t bufNum)
{
    int32_t status;
    uint32_t regVal;

    if (MCANSS_TX_BUFFER_MAX > bufNum) {
        regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_TXBAR);
        regVal |= ((uint32_t) 1U << bufNum);

        /*
         * For writing to TXBAR CCE bit should be '0'. This need not be
         * reverted because for other qualified writes this is locked state
         * and can't be written.
         */
        DL_MCAN_writeProtectedRegAccessLock(mcan);
        HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_TXBAR, regVal);

        status = STW_SOK;
    } else {
        status = STW_EFAIL;
    }
    return status;
}

void DL_MCAN_getNewDataStatus(
    MCAN_Regs *mcan, DL_MCAN_RxNewDataStatus *newDataStatus)
{
    newDataStatus->statusLow  = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_NDAT1);
    newDataStatus->statusHigh = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_NDAT2);
}

void DL_MCAN_clearNewDataStatus(
    MCAN_Regs *mcan, const DL_MCAN_RxNewDataStatus *newDataStatus)
{
    HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_NDAT1, newDataStatus->statusLow);
    HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_NDAT2, newDataStatus->statusHigh);
}

void DL_MCAN_readMsgRam(MCAN_Regs *mcan, uint32_t memType, uint32_t bufNum,
    uint32_t fifoNum, DL_MCAN_RxBufElement *elem)
{
    uint32_t startAddr = 0U, elemSize = 0U, elemAddr = 0U;
    uint32_t enableMod = 0U, idx = 0U;

    if (((uint32_t) DL_MCAN_MEM_TYPE_BUF) == memType) {
        startAddr =
            HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXBC, MCAN_RXBC_RBSA);
        elemSize =
            HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXESC, MCAN_RXESC_RBDS);
        idx       = bufNum;
        enableMod = 1U;
    }
    if (((uint32_t) DL_MCAN_MEM_TYPE_FIFO) == memType) {
        switch (fifoNum) {
            case ((uint32_t) DL_MCAN_RX_FIFO_NUM_0):
                startAddr = HW_RD_FIELD32(
                    &mcan->MCANSS.MCAN.MCAN_RXF0C, MCAN_RXF0C_F0SA);
                elemSize = HW_RD_FIELD32(
                    &mcan->MCANSS.MCAN.MCAN_RXESC, MCAN_RXESC_F0DS);
                idx = HW_RD_FIELD32(
                    &mcan->MCANSS.MCAN.MCAN_RXF0S, MCAN_RXF0S_F0GI);
                enableMod = 1U;
                break;
            case ((uint32_t) DL_MCAN_RX_FIFO_NUM_1):
                startAddr = HW_RD_FIELD32(
                    &mcan->MCANSS.MCAN.MCAN_RXF1C, MCAN_RXF1C_F1SA);
                elemSize = HW_RD_FIELD32(
                    &mcan->MCANSS.MCAN.MCAN_RXESC, MCAN_RXESC_F1DS);
                idx = HW_RD_FIELD32(
                    &mcan->MCANSS.MCAN.MCAN_RXF1S, MCAN_RXF1S_F1GI);
                enableMod = 1U;
                break;
            default:
                /* Invalid option */
                break;
        }
    }
    if (1U == enableMod) {
        startAddr = (uint32_t)(startAddr << 2U);
        elemSize  = DL_MCAN_getMsgObjSize(elemSize);
        elemSize *= 4U;
        elemAddr = startAddr + (elemSize * idx);
        elemAddr += MCAN_MCAN_MSG_MEM;
        DL_MCAN_readMsg((uint32_t) mcan, elemAddr, elem);
    }
}

void DL_MCAN_readTxEventFIFO(
    MCAN_Regs *mcan, DL_MCAN_TxEventFIFOElement *txEventElem)
{
    uint32_t startAddr = 0U, elemSize = 0U, elemAddr = 0U;
    uint32_t idx = 0U, regVal;

    startAddr = HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXEFC, MCAN_TXEFC_EFSA);
    elemSize  = MCANSS_TX_EVENT_FIFO_SIZE_WORDS;
    idx       = HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXEFS, MCAN_TXEFS_EFGI);

    startAddr = (uint32_t)(startAddr << 2U);
    elemSize *= 4U;
    elemAddr = startAddr + (elemSize * idx);
    elemAddr += MCAN_MCAN_MSG_MEM;

    regVal = HW_RD_REG32(((uint32_t) mcan + (uint32_t) elemAddr));
    txEventElem->id =
        (uint32_t)((regVal & MCANSS_TX_EVENT_FIFO_ELEM_ID_MASK) >>
                   MCANSS_TX_EVENT_FIFO_ELEM_ID_SHIFT);
    txEventElem->rtr =
        (uint32_t)((regVal & MCANSS_TX_EVENT_FIFO_ELEM_RTR_MASK) >>
                   MCANSS_TX_EVENT_FIFO_ELEM_RTR_SHIFT);
    txEventElem->xtd =
        (uint32_t)((regVal & MCANSS_TX_EVENT_FIFO_ELEM_XTD_MASK) >>
                   MCANSS_TX_EVENT_FIFO_ELEM_XTD_SHIFT);
    txEventElem->esi =
        (uint32_t)((regVal & MCANSS_TX_EVENT_FIFO_ELEM_ESI_MASK) >>
                   MCANSS_TX_EVENT_FIFO_ELEM_ESI_SHIFT);
    elemAddr += 4U;

    regVal = HW_RD_REG32(((uint32_t) mcan + (uint32_t) elemAddr));

    txEventElem->txts =
        (uint32_t)((regVal & MCANSS_TX_EVENT_FIFO_ELEM_TXTS_MASK) >>
                   MCANSS_TX_EVENT_FIFO_ELEM_TXTS_SHIFT);
    txEventElem->dlc =
        (uint32_t)((regVal & MCANSS_TX_EVENT_FIFO_ELEM_DLC_MASK) >>
                   MCANSS_TX_EVENT_FIFO_ELEM_DLC_SHIFT);
    txEventElem->brs =
        (uint32_t)((regVal & MCANSS_TX_EVENT_FIFO_ELEM_BRS_MASK) >>
                   MCANSS_TX_EVENT_FIFO_ELEM_BRS_SHIFT);
    txEventElem->fdf =
        (uint32_t)((regVal & MCANSS_TX_EVENT_FIFO_ELEM_FDF_MASK) >>
                   MCANSS_TX_EVENT_FIFO_ELEM_FDF_SHIFT);
    txEventElem->et =
        (uint32_t)((regVal & MCANSS_TX_EVENT_FIFO_ELEM_ET_MASK) >>
                   MCANSS_TX_EVENT_FIFO_ELEM_ET_SHIFT);
    txEventElem->mm =
        (uint32_t)((regVal & MCANSS_TX_EVENT_FIFO_ELEM_MM_MASK) >>
                   MCANSS_TX_EVENT_FIFO_ELEM_MM_SHIFT);
}

void DL_MCAN_addStdMsgIDFilter(MCAN_Regs *mcan, uint32_t filtNum,
    const DL_MCAN_StdMsgIDFilterElement *elem)
{
    uint32_t startAddr, elemAddr, regVal;

    startAddr = HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_SIDFC, MCAN_SIDFC_FLSSA);
    startAddr = (uint32_t)(startAddr << 2U);
    elemAddr  = startAddr + (filtNum * MCANSS_STD_ID_FILTER_SIZE_WORDS * 4U);
    elemAddr += MCAN_MCAN_MSG_MEM;

    regVal = 0U;
    regVal |= (uint32_t)(elem->sfid2 << MCANSS_STD_ID_FILTER_SFID2_SHIFT);
    regVal |= (uint32_t)(elem->sfid1 << MCANSS_STD_ID_FILTER_SFID1_SHIFT);
    regVal |= (uint32_t)(elem->sfec << MCANSS_STD_ID_FILTER_SFEC_SHIFT);
    regVal |= (uint32_t)(elem->sft << MCANSS_STD_ID_FILTER_SFT_SHIFT);
    HW_WR_REG32(((uint32_t) mcan + (uint32_t) elemAddr), regVal);
}

void DL_MCAN_addExtMsgIDFilter(MCAN_Regs *mcan, uint32_t filtNum,
    const DL_MCAN_ExtMsgIDFilterElement *elem)
{
    uint32_t startAddr, elemAddr, regVal;

    startAddr = HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_XIDFC, MCAN_XIDFC_FLESA);
    startAddr = (uint32_t)(startAddr << 2U);
    elemAddr  = startAddr + (filtNum * MCANSS_EXT_ID_FILTER_SIZE_WORDS * 4U);
    elemAddr += MCAN_MCAN_MSG_MEM;

    regVal = 0U;
    regVal |= (uint32_t)(elem->efid1 << MCANSS_EXT_ID_FILTER_EFID1_SHIFT);
    regVal |= (uint32_t)(elem->efec << MCANSS_EXT_ID_FILTER_EFEC_SHIFT);
    HW_WR_REG32(((uint32_t) mcan + (uint32_t) elemAddr), regVal);

    elemAddr += 4U;
    regVal = 0U;
    regVal |= (uint32_t)(elem->efid2 << MCANSS_EXT_ID_FILTER_EFID2_SHIFT);
    regVal |= (uint32_t)(elem->eft << MCANSS_EXT_ID_FILTER_EFT_SHIFT);
    HW_WR_REG32(((uint32_t) mcan + (uint32_t) elemAddr), regVal);
}

void DL_MCAN_lpbkModeEnable(MCAN_Regs *mcan, uint32_t lpbkMode, bool enable)
{
    DL_MCAN_writeProtectedRegAccessUnlock(mcan);

    if (true == enable) {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_TEST, 0x1U);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TEST, MCAN_TEST_LBCK, enable);
        if (((uint32_t) DL_MCAN_LPBK_MODE_INTERNAL) == lpbkMode) {
            HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_MON, 0x1U);
        }
    } else {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TEST, MCAN_TEST_LBCK, enable);
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_TEST, 0x0U);
        if (((uint32_t) DL_MCAN_LPBK_MODE_INTERNAL) == lpbkMode) {
            HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_MON, 0x0U);
        }
    }
    DL_MCAN_writeProtectedRegAccessLock(mcan);
}

void DL_MCAN_getErrCounters(MCAN_Regs *mcan, DL_MCAN_ErrCntStatus *errCounter)
{
    errCounter->canErrLogCnt =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_ECR, MCAN_ECR_CEL);
    errCounter->transErrLogCnt =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_ECR, MCAN_ECR_TEC);
    errCounter->recErrCnt =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_ECR, MCAN_ECR_REC);
    errCounter->rpStatus =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_ECR, MCAN_ECR_RP);
}

void DL_MCAN_getProtocolStatus(
    MCAN_Regs *mcan, DL_MCAN_ProtocolStatus *protStatus)
{
    uint32_t regVal;

    regVal                    = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_PSR);
    protStatus->lastErrCode   = HW_GET_FIELD(regVal, MCAN_PSR_LEC);
    protStatus->act           = HW_GET_FIELD(regVal, MCAN_PSR_ACT);
    protStatus->errPassive    = HW_GET_FIELD(regVal, MCAN_PSR_EP);
    protStatus->warningStatus = HW_GET_FIELD(regVal, MCAN_PSR_EW);
    protStatus->busOffStatus  = HW_GET_FIELD(regVal, MCAN_PSR_BO);
    protStatus->dlec          = HW_GET_FIELD(regVal, MCAN_PSR_DLEC);
    protStatus->resi          = HW_GET_FIELD(regVal, MCAN_PSR_RESI);
    protStatus->rbrs          = HW_GET_FIELD(regVal, MCAN_PSR_RBRS);
    protStatus->rfdf          = HW_GET_FIELD(regVal, MCAN_PSR_RFDF);
    protStatus->pxe           = HW_GET_FIELD(regVal, MCAN_PSR_PXE);
    protStatus->tdcv          = HW_GET_FIELD(regVal, MCAN_PSR_TDCV);
}

void DL_MCAN_enableIntr(MCAN_Regs *mcan, uint32_t intrMask, bool enable)
{
    uint32_t regVal;

    if (true == enable) {
        regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_IE);
        regVal |= intrMask;
        HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_IE, regVal);
    } else {
        regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_IE);
        regVal &= ~intrMask;
        HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_IE, regVal);
    }
}

void DL_MCAN_selectIntrLine(
    MCAN_Regs *mcan, uint32_t intrMask, uint32_t lineNum)
{
    uint32_t regVal;

    if (((uint32_t) DL_MCAN_INTR_LINE_NUM_0) == lineNum) {
        regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_ILS);
        regVal &= ~intrMask;
        HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_ILS, regVal);
    } else {
        regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_ILS);
        regVal |= intrMask;
        HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_ILS, regVal);
    }
}

uint32_t DL_MCAN_getIntrLineSelectStatus(MCAN_Regs *mcan)
{
    return (HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_ILS));
}

void DL_MCAN_enableIntrLine(MCAN_Regs *mcan, uint32_t lineNum, bool enable)
{
    uint32_t regVal;

    lineNum &= MCANSS_INTR_LINE_EN_MASK;
    regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_ILE);
    regVal &= ~((uint32_t) 0x1U << lineNum);
    regVal |= ((uint32_t) enable << lineNum);
    HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_ILE, regVal);
}

uint32_t DL_MCAN_getIntrStatus(MCAN_Regs *mcan)
{
    return (HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_IR));
}

void DL_MCAN_clearIntrStatus(
    MCAN_Regs *mcan, uint32_t intrMask, DL_MCAN_INTR_SRC_MCAN eoi)
{
    HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_IR, intrMask);
    HW_WR_REG32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_EOI,
        (uint32_t) eoi);
}

void DL_MCAN_getHighPriorityMsgStatus(
    MCAN_Regs *mcan, DL_MCAN_HighPriorityMsgInfo *hpm)
{
    hpm->bufIdx = HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_HPMS, MCAN_HPMS_BIDX);
    hpm->msi    = HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_HPMS, MCAN_HPMS_MSI);
    hpm->filterIdx =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_HPMS, MCAN_HPMS_FIDX);
    hpm->filterList =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_HPMS, MCAN_HPMS_FLST);
}

void DL_MCAN_getRxFIFOStatus(MCAN_Regs *mcan, DL_MCAN_RxFIFOStatus *fifoStatus)
{
    uint32_t regVal;

    switch (fifoStatus->num) {
        case ((uint32_t) DL_MCAN_RX_FIFO_NUM_0):
            regVal               = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_RXF0S);
            fifoStatus->fillLvl  = HW_GET_FIELD(regVal, MCAN_RXF0S_F0FL);
            fifoStatus->getIdx   = HW_GET_FIELD(regVal, MCAN_RXF0S_F0GI);
            fifoStatus->putIdx   = HW_GET_FIELD(regVal, MCAN_RXF0S_F0PI);
            fifoStatus->fifoFull = HW_GET_FIELD(regVal, MCAN_RXF0S_F0F);
            fifoStatus->msgLost  = HW_GET_FIELD(regVal, MCAN_RXF0S_RF0L);
            break;
        case ((uint32_t) DL_MCAN_RX_FIFO_NUM_1):
            regVal               = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_RXF1S);
            fifoStatus->fillLvl  = HW_GET_FIELD(regVal, MCAN_RXF1S_F1FL);
            fifoStatus->getIdx   = HW_GET_FIELD(regVal, MCAN_RXF1S_F1GI);
            fifoStatus->putIdx   = HW_GET_FIELD(regVal, MCAN_RXF1S_F1PI);
            fifoStatus->fifoFull = HW_GET_FIELD(regVal, MCAN_RXF1S_F1F);
            fifoStatus->msgLost  = HW_GET_FIELD(regVal, MCAN_RXF1S_RF1L);
            break;
        default:
            /* Invalid option */
            break;
    }
}

int32_t DL_MCAN_writeRxFIFOAck(MCAN_Regs *mcan, uint32_t fifoNum, uint32_t idx)
{
    int32_t status;
    uint32_t size;

    switch (fifoNum) {
        case ((uint32_t) DL_MCAN_RX_FIFO_NUM_0):
            size =
                HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXF0C, MCAN_RXF0C_F0S);
            if (size >= idx) {
                HW_WR_FIELD32(
                    &mcan->MCANSS.MCAN.MCAN_RXF0A, MCAN_RXF0A_F0AI, idx);
                status = STW_SOK;
            } else {
                status = STW_EFAIL;
            }
            break;
        case ((uint32_t) DL_MCAN_RX_FIFO_NUM_1):
            size =
                HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_RXF1C, MCAN_RXF1C_F1S);
            if (size >= idx) {
                HW_WR_FIELD32(
                    &mcan->MCANSS.MCAN.MCAN_RXF1A, MCAN_RXF1A_F1AI, idx);
                status = STW_SOK;
            } else {
                status = STW_EFAIL;
            }
            break;
        default:
            status = STW_EFAIL;
            break;
    }

    return status;
}

void DL_MCAN_getTxFIFOQueStatus(
    MCAN_Regs *mcan, DL_MCAN_TxFIFOStatus *fifoStatus)
{
    uint32_t regVal;

    regVal               = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_TXFQS);
    fifoStatus->freeLvl  = HW_GET_FIELD(regVal, MCAN_TXFQS_TFFL);
    fifoStatus->getIdx   = HW_GET_FIELD(regVal, MCAN_TXFQS_TFGI);
    fifoStatus->putIdx   = HW_GET_FIELD(regVal, MCAN_TXFQS_TFQP);
    fifoStatus->fifoFull = HW_GET_FIELD(regVal, MCAN_TXFQS_TFQF);
}

uint32_t DL_MCAN_getTxBufReqPend(MCAN_Regs *mcan)
{
    return (HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_TXBRP));
}

int32_t DL_MCAN_txBufCancellationReq(MCAN_Regs *mcan, uint32_t buffNum)
{
    int32_t status;
    uint32_t regVal;

    if (MCANSS_TX_BUFFER_MAX > buffNum) {
        regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_TXBCR);
        regVal |= ((uint32_t) 1U << buffNum);

        /*
         * For writing to TXBCR CCE bit should be '0'. This need not be
         * reverted because for other qualified writes this is locked state
         * and can't be written.
         */
        DL_MCAN_writeProtectedRegAccessLock(mcan);
        HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_TXBCR, regVal);

        status = STW_SOK;
    } else {
        status = STW_EFAIL;
    }
    return status;
}

uint32_t DL_MCAN_getTxBufTransmissionStatus(MCAN_Regs *mcan)
{
    return (HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_TXBTO));
}

uint32_t DL_MCAN_txBufCancellationStatus(MCAN_Regs *mcan)
{
    return (HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_TXBCF));
}

int32_t DL_MCAN_TXBufTransIntrEnable(
    MCAN_Regs *mcan, uint32_t bufNum, bool enable)
{
    int32_t status;
    uint32_t regVal;

    if (MCANSS_TX_BUFFER_MAX > bufNum) {
        if (true == enable) {
            regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_TXBTIE);
            regVal |= ((uint32_t) 1U << bufNum);
            HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_TXBTIE, regVal);
        } else {
            regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_TXBTIE);
            regVal &= ~((uint32_t) 0x1U << bufNum);
            HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_TXBTIE, regVal);
        }
        status = STW_SOK;
    } else {
        status = STW_EFAIL;
    }
    return status;
}

int32_t DL_MCAN_getTxBufCancellationIntrEnable(
    MCAN_Regs *mcan, uint32_t bufNum, bool enable)
{
    int32_t status;
    uint32_t regVal;

    if (MCANSS_TX_BUFFER_MAX > bufNum) {
        if (true == enable) {
            regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_TXBCIE);
            regVal |= ((uint32_t) 0x1U << bufNum);
            HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_TXBCIE, regVal);
        } else {
            regVal = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_TXBCIE);
            regVal &= ~((uint32_t) 0x1U << bufNum);
            HW_WR_REG32(&mcan->MCANSS.MCAN.MCAN_TXBCIE, regVal);
        }
        status = STW_SOK;
    } else {
        status = STW_EFAIL;
    }
    return status;
}

void DL_MCAN_getTxEventFIFOStatus(
    MCAN_Regs *mcan, DL_MCAN_TxEventFIFOStatus *fifoStatus)
{
    uint32_t regVal;

    regVal               = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_TXEFS);
    fifoStatus->fillLvl  = HW_GET_FIELD(regVal, MCAN_TXEFS_EFFL);
    fifoStatus->getIdx   = HW_GET_FIELD(regVal, MCAN_TXEFS_EFGI);
    fifoStatus->putIdx   = HW_GET_FIELD(regVal, MCAN_TXEFS_EFPI);
    fifoStatus->fifoFull = HW_GET_FIELD(regVal, MCAN_TXEFS_EFF);
    fifoStatus->eleLost  = HW_GET_FIELD(regVal, MCAN_TXEFS_TEFL);
}

void DL_MCAN_addClockStopRequest(MCAN_Regs *mcan, bool enable)
{
    if (true == enable) {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_CSR, 0x1U);
    } else {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_CSR, 0x0U);
    }
}

int32_t DL_MCAN_writeTxEventFIFOAck(MCAN_Regs *mcan, uint32_t idx)
{
    int32_t status;
    uint32_t size;

    size = HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXEFC, MCAN_TXEFC_EFS);

    if (size >= idx) {
        HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TXEFA, MCAN_TXEFA_EFAI, idx);
        status = STW_SOK;
    } else {
        status = STW_EFAIL;
    }

    return status;
}

void DL_MCAN_eccForceError(
    MCAN_Regs *mcan, const DL_MCAN_ECCErrForceParams *eccErr)
{
    uint32_t regVal;

    if ((eccErr->errType == ((uint32_t) DL_MCAN_ECC_ERR_TYPE_SEC)) ||
        (eccErr->errType == ((uint32_t) DL_MCAN_ECC_ERR_TYPE_DED))) {
        DL_MCAN_eccLoadRegister(
            mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                      .MCANERR_ERR_CTRL1);
        regVal = HW_RD_REG32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                                  .MCANERR_ERR_CTRL1);
        HW_SET_FIELD32(regVal, MCAN_ERR_CTRL1_ECC_ROW, eccErr->rowNum);
        HW_WR_REG32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                         .MCANERR_ERR_CTRL1,
            regVal);
        DL_MCAN_eccLoadRegister(
            mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                      .MCANERR_ERR_CTRL2);
        regVal = HW_RD_REG32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                                  .MCANERR_ERR_CTRL2);
        HW_SET_FIELD32(regVal, MCAN_ERR_CTRL2_ECC_BIT1, eccErr->bit1);
        HW_SET_FIELD32(regVal, MCAN_ERR_CTRL2_ECC_BIT2, eccErr->bit2);
        HW_WR_REG32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                         .MCANERR_ERR_CTRL2,
            regVal);
        DL_MCAN_eccLoadRegister(
            mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                      .MCANERR_CTRL);
        regVal = HW_RD_REG32(
            &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_CTRL);
        HW_SET_FIELD32(regVal, MCAN_TI_WRAPPER_ECC_REGS_CTRL_FORCE_N_ROW,
            eccErr->errForce);
        HW_SET_FIELD32(
            regVal, MCAN_TI_WRAPPER_ECC_REGS_CTRL_ERROR_ONCE, eccErr->errOnce);
        if (eccErr->errType == ((uint32_t) DL_MCAN_ECC_ERR_TYPE_SEC)) {
            HW_SET_FIELD32(
                regVal, MCAN_TI_WRAPPER_ECC_REGS_CTRL_FORCE_SEC, 0x1U);
        } else {
            /* eccErr->errType == ((uint32_t) DL_MCAN_ECC_ERR_TYPE_DED) */
            HW_SET_FIELD32(
                regVal, MCAN_TI_WRAPPER_ECC_REGS_CTRL_FORCE_DED, 0x1U);
        }
        HW_WR_REG32(
            &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_CTRL,
            regVal);
        DL_MCAN_eccLoadRegister(
            mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                      .MCANERR_CTRL);
    }
}

void DL_MCAN_eccGetErrorStatus(MCAN_Regs *mcan, DL_MCAN_ECCErrStatus *eccErr)
{
    uint32_t regVal;

    DL_MCAN_eccLoadRegister(
        mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                  .MCANERR_ERR_STAT1);
    regVal = HW_RD_REG32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_ERR_STAT1);
    eccErr->secErr = HW_GET_FIELD(regVal, MCAN_ERR_STAT1_ECC_SEC);
    eccErr->dedErr = HW_GET_FIELD(regVal, MCAN_ERR_STAT1_ECC_DED);
    eccErr->bit1   = HW_GET_FIELD(regVal, MCAN_ERR_STAT1_ECC_BIT1);
    DL_MCAN_eccLoadRegister(
        mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                  .MCANERR_ERR_STAT2);
    regVal = HW_RD_REG32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_ERR_STAT2);
    eccErr->row = HW_GET_FIELD(regVal, MCAN_ERR_STAT2_ECC_ROW);
}

void DL_MCAN_eccClearErrorStatus(MCAN_Regs *mcan, uint32_t errType)
{
    DL_MCAN_eccLoadRegister(
        mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                  .MCANERR_ERR_STAT1);
    switch (errType) {
        case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_SEC):
            HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                               .MCANERR_ERR_STAT1,
                MCAN_ERR_STAT1_ECC_SEC, 0x1U);
            break;
        case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_DED):
            HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                               .MCANERR_ERR_STAT1,
                MCAN_ERR_STAT1_ECC_DED, 0x1U);
            break;
        default:
            /* Invalid option */
            break;
    }
    DL_MCAN_eccLoadRegister(
        mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                  .MCANERR_ERR_STAT1);
}

void DL_MCAN_eccWriteEOI(MCAN_Regs *mcan, uint32_t errType)
{
    switch (errType) {
        case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_SEC):
            HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                               .MCANERR_SEC_EOI,
                MCAN_SEC_EOI_EOI_WR, 0x1U);
            break;
        case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_DED):
            HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                               .MCANERR_DED_EOI,
                MCAN_DED_EOI_EOI_WR, 0x1U);
            break;
        default:
            /* Invalid option */
            break;
    }
}

void DL_MCAN_eccEnableIntr(MCAN_Regs *mcan, uint32_t errType, bool enable)
{
    if (true == enable) {
        switch (errType) {
            case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_SEC):
                HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                                   .MCANERR_SEC_ENABLE_SET,
                    MCAN_SEC_ENABLE_SET_MSGMEM_ENABLE_SET, 0x1U);
                break;
            case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_DED):
                HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                                   .MCANERR_DED_ENABLE_SET,
                    MCAN_DED_ENABLE_SET_MSGMEM_ENABLE_SET, 0x1U);
                break;
            default:
                /* Invalid option */
                break;
        }
    } else {
        switch (errType) {
            case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_SEC):
                HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                                   .MCANERR_SEC_ENABLE_CLR,
                    MCAN_SEC_ENABLE_CLR_MSGMEM_ENABLE_CLR, 0x1U);
                break;
            case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_DED):
                HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                                   .MCANERR_DED_ENABLE_CLR,
                    MCAN_DED_ENABLE_CLR_MSGMEM_ENABLE_CLR, 0x1U);
                break;
            default:
                /* Invalid option */
                break;
        }
    }
}

uint32_t DL_MCAN_eccGetIntrStatus(MCAN_Regs *mcan, uint32_t errType)
{
    uint32_t retVal = 0U;

    switch (errType) {
        case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_SEC):
            retVal = HW_RD_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS
                                        .MCAN_ECC_REGS.MCANERR_SEC_STATUS,
                MCAN_SEC_STATUS_MSGMEM_PEND);
            break;
        case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_DED):
            retVal = HW_RD_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS
                                        .MCAN_ECC_REGS.MCANERR_DED_STATUS,
                MCAN_DED_STATUS_MSGMEM_PEND);
            break;
        default:
            retVal = 0U;
            break;
    }
    return retVal;
}

void DL_MCAN_eccClearIntrStatus(MCAN_Regs *mcan, uint32_t errType)
{
    switch (errType) {
        case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_SEC):
            HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                               .MCANERR_SEC_STATUS,
                MCAN_SEC_STATUS_MSGMEM_PEND, 0x1U);
            break;
        case ((uint32_t) DL_MCAN_ECC_ERR_TYPE_DED):
            HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                               .MCANERR_DED_STATUS,
                MCAN_DED_STATUS_MSGMEM_PEND, 0x1U);
            break;
        default:
            break;
    }
}

void DL_MCAN_extTSCounterConfig(MCAN_Regs *mcan, uint32_t prescalar)
{
    HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS
                       .MCANSS_EXT_TS_PRESCALER,
        MCAN_EXT_TS_PRESCALER_PRESCALER, prescalar);
}

void DL_MCAN_extTSCounterEnable(MCAN_Regs *mcan, bool enable)
{
    HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_CTRL,
        MCAN_TI_WRAPPER_REGS_CTRL_EXT_TS_CNTR_EN, enable);
}

void DL_MCAN_extTSEnableIntr(MCAN_Regs *mcan, bool enable)
{
    if (true == enable) {
        HW_WR_FIELD32(
            &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_IE,
            MCAN_TI_WRAPPER_PROCESSORS_REGS_IE_EXT_TS_CNTR_OVFL, 1U);
    } else {
        HW_WR_FIELD32(
            &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_IECS,
            MCAN_IECS_EXT_TS_CNTR_OVFL, 1U);
    }
}

void DL_MCAN_extTSWriteEOI(MCAN_Regs *mcan)
{
    HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_EOI,
        MCAN_EOI_EOI, 0x1U);
}

uint32_t DL_MCAN_extTSGetUnservicedIntrCount(MCAN_Regs *mcan)
{
    return (HW_RD_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS
                               .MCANSS_EXT_TS_UNSERVICED_INTR_CNTR,
        MCAN_EXT_TS_UNSERVICED_INTR_CNTR_EXT_TS_INTR_CNTR));
}

/* ========================================================================== */
/*                          Advance Functions                                 */
/* ========================================================================== */

void DL_MCAN_getRevisionId(MCAN_Regs *mcan, DL_MCAN_RevisionId *revId)
{
    uint32_t regVal;

    regVal = HW_RD_REG32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_PID);
    revId->minor  = HW_GET_FIELD(regVal, MCAN_PID_MINOR);
    revId->major  = HW_GET_FIELD(regVal, MCAN_PID_MAJOR);
    revId->modId  = HW_GET_FIELD(regVal, MCAN_PID_MODULE_ID);
    revId->scheme = HW_GET_FIELD(regVal, MCAN_PID_SCHEME);

    regVal         = HW_RD_REG32(&mcan->MCANSS.MCAN.MCAN_CREL);
    revId->day     = HW_GET_FIELD(regVal, MCAN_CREL_DAY);
    revId->mon     = HW_GET_FIELD(regVal, MCAN_CREL_MON);
    revId->year    = HW_GET_FIELD(regVal, MCAN_CREL_YEAR);
    revId->subStep = HW_GET_FIELD(regVal, MCAN_CREL_SUBSTEP);
    revId->step    = HW_GET_FIELD(regVal, MCAN_CREL_STEP);
    revId->rel     = HW_GET_FIELD(regVal, MCAN_CREL_REL);
}

uint32_t DL_MCAN_getClockStopAck(MCAN_Regs *mcan)
{
    return (HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_CSR));
}

void DL_MCAN_extTSSetRawStatus(MCAN_Regs *mcan)
{
    HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_IRS,
        MCAN_IRS_EXT_TS_CNTR_OVFL, 1U);
}

void DL_MCAN_extTSClearRawStatus(MCAN_Regs *mcan)
{
    HW_WR_FIELD32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_ICS,
        MCAN_ICS_EXT_TS_CNTR_OVFL, 1U);
}

uint32_t DL_MCAN_getRxPinState(MCAN_Regs *mcan)
{
    return (HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_TEST, MCAN_TEST_RX));
}

void DL_MCAN_setTxPinState(MCAN_Regs *mcan, uint32_t state)
{
    DL_MCAN_writeProtectedRegAccessUnlock(mcan);

    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_TEST, 0x1U);
    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TEST, MCAN_TEST_TX, state);

    DL_MCAN_writeProtectedRegAccessLock(mcan);
}

uint32_t DL_MCAN_getTxPinState(MCAN_Regs *mcan)
{
    return (HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_TEST, MCAN_TEST_TX));
}

uint32_t DL_MCAN_getTSCounterVal(MCAN_Regs *mcan)
{
    return (HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_TSCV, MCAN_TSCV_TSC));
}

uint32_t DL_MCAN_getClkStopAck(MCAN_Regs *mcan)
{
    return (HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_CSA));
}

void DL_MCAN_getBitTime(MCAN_Regs *mcan, DL_MCAN_BitTimingParams *configParams)
{
    configParams->nomSynchJumpWidth =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_NBTP, MCAN_NBTP_NSJW);
    configParams->nomTimeSeg2 =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_NBTP, MCAN_NBTP_NTSEG2);
    configParams->nomTimeSeg1 =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_NBTP, MCAN_NBTP_NTSEG1);
    configParams->nomRatePrescalar =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_NBTP, MCAN_NBTP_NBRP);

    configParams->dataSynchJumpWidth =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_DBTP, MCAN_DBTP_DSJW);
    configParams->dataTimeSeg2 =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_DBTP, MCAN_DBTP_DTSEG2);
    configParams->dataTimeSeg1 =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_DBTP, MCAN_DBTP_DTSEG1);
    configParams->dataRatePrescalar =
        HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_DBTP, MCAN_DBTP_DBRP);
}

void DL_MCAN_resetTSCounter(MCAN_Regs *mcan)
{
    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_TSCV, MCAN_TSCV_TSC, 0x0U);
}

uint32_t DL_MCAN_getTOCounterVal(MCAN_Regs *mcan)
{
    return (HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_TOCV, MCAN_TOCV_TOC));
}

void DL_MCAN_eccAggrGetRevisionId(
    MCAN_Regs *mcan, DL_MCAN_ECCAggrRevisionId *revId)
{
    uint32_t regVal;

    regVal = HW_RD_REG32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_REV);
    revId->minor  = HW_GET_FIELD(regVal, MCAN_REV_REVMIN);
    revId->major  = HW_GET_FIELD(regVal, MCAN_REV_REVMAJ);
    revId->modId  = HW_GET_FIELD(regVal, MCAN_REV_MODULE_ID);
    revId->scheme = HW_GET_FIELD(regVal, MCAN_REV_SCHEME);
}

void DL_MCAN_eccWrapGetRevisionId(
    MCAN_Regs *mcan, DL_MCAN_ECCWrapRevisionId *revId)
{
    uint32_t regVal;

    DL_MCAN_eccLoadRegister(
        mcan, (uint32_t) &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                  .MCANERR_WRAP_REV);
    regVal = HW_RD_REG32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_WRAP_REV);
    revId->minor  = HW_GET_FIELD(regVal, MCAN_WRAP_REV_REVMIN);
    revId->major  = HW_GET_FIELD(regVal, MCAN_WRAP_REV_REVMAJ);
    revId->modId  = HW_GET_FIELD(regVal, MCAN_WRAP_REV_MODULE_ID);
    revId->scheme = HW_GET_FIELD(regVal, MCAN_WRAP_REV_SCHEME);
}

bool DL_MCAN_extTSIsIntrEnable(MCAN_Regs *mcan)
{
    bool status;

    if (1U == HW_RD_FIELD32(
                  &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_IES,
                  MCAN_IES_EXT_TS_CNTR_OVFL)) {
        status = true;
    } else {
        status = false;
    }

    return status;
}

uint32_t DL_MCAN_getEndianVal(MCAN_Regs *mcan)
{
    return (HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_ENDN, MCAN_ENDN_ETV));
}

uint32_t DL_MCAN_getExtIDANDMask(MCAN_Regs *mcan)
{
    return (HW_RD_FIELD32(&mcan->MCANSS.MCAN.MCAN_XIDAM, MCAN_XIDAM_EIDM));
}

/* ========================================================================== */
/*                          Internal Functions                                */
/* ========================================================================== */

static void DL_MCAN_writeProtectedRegAccessUnlock(MCAN_Regs *mcan)
{
    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_CCE, 0x1U);
}

static void DL_MCAN_writeProtectedRegAccessLock(MCAN_Regs *mcan)
{
    HW_WR_FIELD32(&mcan->MCANSS.MCAN.MCAN_CCCR, MCAN_CCCR_CCE, 0x0U);
}

static void DL_MCAN_eccLoadRegister(MCAN_Regs *mcan, uint32_t regOffset)
{
    uint32_t regVal = 0U, offset;

    offset = regOffset & 0xFFU;
    regVal |= ((uint32_t) MCANSS_MSG_RAM_NUM << MCAN_VECTOR_ECC_VECTOR_OFS);
    regVal |= (offset << MCAN_VECTOR_RD_SVBUS_ADDRESS_OFS);
    regVal |= ((uint32_t) 1U << MCAN_VECTOR_RD_SVBUS_OFS);
    HW_WR_REG32(
        &mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_VECTOR,
        regVal);
    while (MCAN_VECTOR_RD_SVBUS_DONE_MASK !=
           (HW_RD_REG32(&mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS
                             .MCANERR_VECTOR) &
               MCAN_VECTOR_RD_SVBUS_DONE_MASK)) {
    }
}

static void DL_MCAN_readMsg(
    uint32_t mcan, uint32_t elemAddr, DL_MCAN_RxBufElement *elem)
{
    uint32_t regVal = 0U, loopCnt = 0U;

    regVal    = HW_RD_REG32(((uint32_t) mcan + (uint32_t) elemAddr));
    elem->id  = (uint32_t)((regVal & MCANSS_RX_BUFFER_ELEM_ID_MASK) >>
                          MCANSS_RX_BUFFER_ELEM_ID_SHIFT);
    elem->rtr = (uint32_t)((regVal & MCANSS_RX_BUFFER_ELEM_RTR_MASK) >>
                           MCANSS_RX_BUFFER_ELEM_RTR_SHIFT);
    elem->xtd = (uint32_t)((regVal & MCANSS_RX_BUFFER_ELEM_XTD_MASK) >>
                           MCANSS_RX_BUFFER_ELEM_XTD_SHIFT);
    elem->esi = (uint32_t)((regVal & MCANSS_RX_BUFFER_ELEM_ESI_MASK) >>
                           MCANSS_RX_BUFFER_ELEM_ESI_SHIFT);

    elemAddr += 4U;
    regVal     = HW_RD_REG32(((uint32_t) mcan + (uint32_t) elemAddr));
    elem->rxts = (uint32_t)((regVal & MCANSS_RX_BUFFER_ELEM_RXTS_MASK) >>
                            MCANSS_RX_BUFFER_ELEM_RXTS_SHIFT);
    elem->dlc  = (uint32_t)((regVal & MCANSS_RX_BUFFER_ELEM_DLC_MASK) >>
                           MCANSS_RX_BUFFER_ELEM_DLC_SHIFT);
    elem->brs  = (uint32_t)((regVal & MCANSS_RX_BUFFER_ELEM_BRS_MASK) >>
                           MCANSS_RX_BUFFER_ELEM_BRS_SHIFT);
    elem->fdf  = (uint32_t)((regVal & MCANSS_RX_BUFFER_ELEM_FDF_MASK) >>
                           MCANSS_RX_BUFFER_ELEM_FDF_SHIFT);
    elem->fidx = (uint32_t)((regVal & MCANSS_RX_BUFFER_ELEM_FIDX_MASK) >>
                            MCANSS_RX_BUFFER_ELEM_FIDX_SHIFT);
    elem->anmf = (uint32_t)((regVal & MCANSS_RX_BUFFER_ELEM_ANMF_MASK) >>
                            MCANSS_RX_BUFFER_ELEM_ANMF_SHIFT);
    elemAddr += 4U;

    loopCnt = 0U;
    /* Reading words from message RAM and forming payload bytes out of it */
    while ((4U <= (DL_MCAN_getDataSize(elem->dlc) - loopCnt)) &&
           (0U != (DL_MCAN_getDataSize(elem->dlc) - loopCnt))) {
        regVal = HW_RD_REG32(((uint32_t) mcan + (uint32_t) elemAddr));
        elem->data[loopCnt]        = (uint16_t)(regVal & 0x000000FFU);
        elem->data[(loopCnt + 1U)] = (uint16_t)((regVal & 0x0000FF00U) >> 8U);
        elem->data[(loopCnt + 2U)] = (uint16_t)((regVal & 0x00FF0000U) >> 16U);
        elem->data[(loopCnt + 3U)] = (uint16_t)((regVal & 0xFF000000U) >> 24U);
        elemAddr += 4U;
        loopCnt += 4U;
    }
    /* Reading remaining bytes from message RAM */
    if (0U < (DL_MCAN_getDataSize(elem->dlc) - loopCnt)) {
        regVal = HW_RD_REG32(((uint32_t) mcan + (uint32_t) elemAddr));
        elem->data[loopCnt]        = (uint16_t)(regVal & 0x000000FFU);
        elem->data[(loopCnt + 1U)] = (uint16_t)((regVal & 0x0000FF00U) >> 8U);
        elem->data[(loopCnt + 2U)] = (uint16_t)((regVal & 0x00FF0000U) >> 16U);
    }
}

static void DL_MCAN_writeMsg(
    uint32_t mcan, uint32_t elemAddr, const DL_MCAN_TxBufElement *elem)
{
    uint32_t regVal = 0, loopCnt = 0U;

    regVal = 0U;
    regVal |= (((uint32_t)(elem->id << MCANSS_TX_BUFFER_ELEM_ID_SHIFT)) |
               ((uint32_t)(elem->rtr << MCANSS_TX_BUFFER_ELEM_RTR_SHIFT)) |
               ((uint32_t)(elem->xtd << MCANSS_TX_BUFFER_ELEM_XTD_SHIFT)) |
               ((uint32_t)(elem->esi << MCANSS_TX_BUFFER_ELEM_ESI_SHIFT)));
    HW_WR_REG32(((uint32_t) mcan + (uint32_t) elemAddr), regVal);
    elemAddr += 4U;

    regVal = 0U;
    regVal |= ((uint32_t)(elem->dlc << MCANSS_TX_BUFFER_ELEM_DLC_SHIFT)) |
              ((uint32_t)(elem->brs << MCANSS_TX_BUFFER_ELEM_BRS_SHIFT)) |
              ((uint32_t)(elem->fdf << MCANSS_TX_BUFFER_ELEM_FDF_SHIFT)) |
              ((uint32_t)(elem->efc << MCANSS_TX_BUFFER_ELEM_EFC_SHIFT)) |
              ((uint32_t)(elem->mm << MCANSS_TX_BUFFER_ELEM_MM_SHIFT));
    HW_WR_REG32(((uint32_t) mcan + (uint32_t) elemAddr), regVal);
    elemAddr += 4U;

    loopCnt = 0U;
    /* Framing words out of the payload bytes and writing it to message RAM */
    while ((4U <= (DL_MCAN_getDataSize(elem->dlc) - loopCnt)) &&
           (0U != (DL_MCAN_getDataSize(elem->dlc) - loopCnt))) {
        regVal = 0U;
        regVal |= ((uint32_t) elem->data[loopCnt] |
                   ((uint32_t) elem->data[(loopCnt + 1U)] << 8U) |
                   ((uint32_t) elem->data[(loopCnt + 2U)] << 16U) |
                   ((uint32_t) elem->data[(loopCnt + 3U)] << 24U));
        HW_WR_REG32(((uint32_t) mcan + (uint32_t) elemAddr), regVal);
        elemAddr += 4U;
        loopCnt += 4U;
    }
    /* Framing a word out of remaining payload bytes and writing it to
     * message RAM */
    if (0U < (DL_MCAN_getDataSize(elem->dlc) - loopCnt)) {
        regVal = 0U;
        regVal |= ((uint32_t) elem->data[loopCnt] |
                   ((uint32_t) elem->data[(loopCnt + 1U)] << 8U) |
                   ((uint32_t) elem->data[(loopCnt + 2U)] << 16U) |
                   ((uint32_t) elem->data[(loopCnt + 3U)] << 24U));
        HW_WR_REG32(((uint32_t) mcan + (uint32_t) elemAddr), regVal);
    }
}

static uint32_t DL_MCAN_getDataSize(uint32_t dlc)
{
    uint32_t dataSize[16] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};
    return (dataSize[dlc]);
}

static uint32_t DL_MCAN_getMsgObjSize(uint32_t elemSize)
{
    uint32_t objSize[8] = {4, 5, 6, 7, 8, 10, 14, 18};
    return (objSize[elemSize]);
}

__STATIC_INLINE uint32_t HW_RD_REG32_RAW(uint32_t addr)
{
    uint32_t regVal = *(volatile uint32_t *) addr;
    return (regVal);
}

__STATIC_INLINE void HW_WR_REG32_RAW(uint32_t addr, uint32_t value)
{
    *(volatile uint32_t *) addr = value;
    return;
}

__STATIC_INLINE void HW_WR_FIELD32_RAW(
    uint32_t addr, uint32_t mask, uint32_t shift, uint32_t value)
{
    uint32_t regVal = *(volatile uint32_t *) addr;
    regVal &= (~mask);
    regVal |= (value << shift) & mask;
    *(volatile uint32_t *) addr = regVal;
    return;
}
__STATIC_INLINE uint32_t HW_RD_FIELD32_RAW(
    uint32_t addr, uint32_t mask, uint32_t shift)
{
    uint32_t regVal = *(volatile uint32_t *) addr;
    regVal          = (regVal & mask) >> shift;
    return (regVal);
}

bool DL_MCAN_saveConfiguration(MCAN_Regs *mcan, DL_MCAN_backupConfig *ptr)
{
    bool saveState = !ptr->backupRdy;
    if (saveState) {
        /* Clock configuration */
        ptr->clkDivConf = mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKDIV;
        ptr->clkConf    = mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKCTL;
        ptr->clkEnConf  = mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKEN;

        /* Interrupt Configuration */
        ptr->txBuffTxIntConf   = mcan->MCANSS.MCAN.MCAN_TXBTIE;
        ptr->txBuffCancIntConf = mcan->MCANSS.MCAN.MCAN_TXBCIE;
        ptr->intLnSelConf      = mcan->MCANSS.MCAN.MCAN_ILS;
        ptr->intLnEnableConf   = mcan->MCANSS.MCAN.MCAN_ILE;
        ptr->ssIntEnConf =
            mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_IE;
        ptr->intEnConf    = mcan->MCANSS.MCAN.MCAN_IE;
        ptr->intEvnt0Conf = mcan->MCANSS.TI_WRAPPER.MSP.CPU_INT.IMASK;

        /* MCAN configuration */
        ptr->ctrlConf        = mcan->MCANSS.MCAN.MCAN_CCCR;
        ptr->nomBitTimeConf  = mcan->MCANSS.MCAN.MCAN_NBTP;
        ptr->dataBitTimeConf = mcan->MCANSS.MCAN.MCAN_DBTP;
        ptr->timeCntConf     = mcan->MCANSS.MCAN.MCAN_TSCC;
        ptr->timeCntVal      = mcan->MCANSS.MCAN.MCAN_TSCV;
        ptr->timeOutConf     = mcan->MCANSS.MCAN.MCAN_TOCC;
        ptr->timeOutCntVal   = mcan->MCANSS.MCAN.MCAN_TOCV;
        ptr->txDelCompConf   = mcan->MCANSS.MCAN.MCAN_TDCR;
        ptr->globFiltIDConf  = mcan->MCANSS.MCAN.MCAN_GFC;
        ptr->stdFiltIDConf   = mcan->MCANSS.MCAN.MCAN_SIDFC;
        ptr->exFiltIDConf    = mcan->MCANSS.MCAN.MCAN_XIDFC;
        ptr->exFiltIDMsk     = mcan->MCANSS.MCAN.MCAN_XIDAM;
        ptr->rxFIFO0Conf     = mcan->MCANSS.MCAN.MCAN_RXF0C;
        ptr->rxBuffConf      = mcan->MCANSS.MCAN.MCAN_RXBC;
        ptr->rxFIFO1Conf     = mcan->MCANSS.MCAN.MCAN_RXF1C;
        ptr->rxDataSize      = mcan->MCANSS.MCAN.MCAN_RXESC;
        ptr->txBuffConf      = mcan->MCANSS.MCAN.MCAN_TXBC;
        ptr->txDataSize      = mcan->MCANSS.MCAN.MCAN_TXESC;
        ptr->txEvntFIFOConf  = mcan->MCANSS.MCAN.MCAN_TXEFC;
        ptr->ssCtrlConf =
            mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_CTRL;
        ptr->preSclConf = mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS
                              .MCANSS_EXT_TS_PRESCALER;
        ptr->edcVecConf =
            mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_VECTOR;
        ptr->edcConf2 =
            mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_CTRL;
        ptr->edcConf1 =
            mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_ERR_CTRL1;
        ptr->edcConf0 =
            mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_ERR_CTRL2;
        ptr->ramWDConf = mcan->MCANSS.MCAN.MCAN_RWD;
        ptr->testConf  = mcan->MCANSS.MCAN.MCAN_TEST;
        ptr->backupRdy = true;
    }
    return saveState;
}

bool DL_MCAN_restoreConfiguration(MCAN_Regs *mcan, DL_MCAN_backupConfig *ptr)
{
    bool stateRestored = ptr->backupRdy;
    bool cceState;
    bool initState;
    if (stateRestored) {
        ptr->backupRdy = false;

        /**
         * Stores actual state of Configuration Change Enable. CCE will be set
         * during restore operation and will configure CCE actual state at the
         * end.
         */
        cceState =
            ((ptr->ctrlConf & MCAN_CCCR_CCE_MASK) == MCAN_CCCR_CCE_MASK);
        initState =
            ((ptr->ctrlConf & MCAN_CCCR_INIT_MASK) == MCAN_CCCR_INIT_MASK);

        /**
         * MCAN configuration only overwrittring CCE configuration since INIT
         * reset value is 0x1. CCE and INIT must be set to 0x1 to allow
         * reconfiguration of MCAN.
         */
        mcan->MCANSS.MCAN.MCAN_CCCR  = (ptr->ctrlConf |= MCAN_CCCR_CCE_MASK);
        mcan->MCANSS.MCAN.MCAN_NBTP  = ptr->nomBitTimeConf;
        mcan->MCANSS.MCAN.MCAN_DBTP  = ptr->dataBitTimeConf;
        mcan->MCANSS.MCAN.MCAN_TSCC  = ptr->timeCntConf;
        mcan->MCANSS.MCAN.MCAN_TSCV  = ptr->timeCntVal;
        mcan->MCANSS.MCAN.MCAN_TOCC  = ptr->timeOutConf;
        mcan->MCANSS.MCAN.MCAN_TOCV  = ptr->timeOutCntVal;
        mcan->MCANSS.MCAN.MCAN_TDCR  = ptr->txDelCompConf;
        mcan->MCANSS.MCAN.MCAN_GFC   = ptr->globFiltIDConf;
        mcan->MCANSS.MCAN.MCAN_SIDFC = ptr->stdFiltIDConf;
        mcan->MCANSS.MCAN.MCAN_XIDFC = ptr->exFiltIDConf;
        mcan->MCANSS.MCAN.MCAN_XIDAM = ptr->exFiltIDMsk;
        mcan->MCANSS.MCAN.MCAN_RXF0C = ptr->rxFIFO0Conf;
        mcan->MCANSS.MCAN.MCAN_RXBC  = ptr->rxBuffConf;
        mcan->MCANSS.MCAN.MCAN_RXF1C = ptr->rxFIFO1Conf;
        mcan->MCANSS.MCAN.MCAN_RXESC = ptr->rxDataSize;
        mcan->MCANSS.MCAN.MCAN_TXBC  = ptr->txBuffConf;
        mcan->MCANSS.MCAN.MCAN_TXESC = ptr->txDataSize;
        mcan->MCANSS.MCAN.MCAN_TXEFC = ptr->txEvntFIFOConf;
        mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_CTRL =
            ptr->ssCtrlConf;
        mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS
            .MCANSS_EXT_TS_PRESCALER = ptr->preSclConf;
        mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_VECTOR =
            ptr->edcVecConf;
        mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_CTRL =
            ptr->edcConf2;
        mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_ERR_CTRL1 =
            ptr->edcConf1;
        mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCAN_ECC_REGS.MCANERR_ERR_CTRL2 =
            ptr->edcConf0;
        mcan->MCANSS.MCAN.MCAN_RWD  = ptr->ramWDConf;
        mcan->MCANSS.MCAN.MCAN_TEST = ptr->testConf;

        /* Clock configuration */
        mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKDIV = ptr->clkDivConf;
        mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKCTL = ptr->clkConf;
        mcan->MCANSS.TI_WRAPPER.MSP.MCANSS_CLKEN  = ptr->clkEnConf;

        /* Interrupt Configuration */
        mcan->MCANSS.MCAN.MCAN_TXBTIE = ptr->txBuffTxIntConf;
        mcan->MCANSS.MCAN.MCAN_TXBCIE = ptr->txBuffCancIntConf;
        mcan->MCANSS.MCAN.MCAN_ILS    = ptr->intLnSelConf;
        mcan->MCANSS.MCAN.MCAN_ILE    = ptr->intLnEnableConf;
        mcan->MCANSS.TI_WRAPPER.PROCESSORS.MCANSS_REGS.MCANSS_IE =
            ptr->ssIntEnConf;
        mcan->MCANSS.MCAN.MCAN_IE                 = ptr->intEnConf;
        mcan->MCANSS.TI_WRAPPER.MSP.CPU_INT.IMASK = ptr->intEvnt0Conf;

        /* Restores MCAN configuration change state */
        if (false == cceState) {
            DL_Common_updateReg(
                &mcan->MCANSS.MCAN.MCAN_CCCR, 0, MCAN_CCCR_CCE_MASK);
        } else {
            DL_Common_updateReg(&mcan->MCANSS.MCAN.MCAN_CCCR,
                MCAN_CCCR_CCE_MASK, MCAN_CCCR_CCE_MASK);
        }

        /* Restores MCAN intialization status */
        if (false == initState) {
            DL_Common_updateReg(
                &mcan->MCANSS.MCAN.MCAN_CCCR, 0, MCAN_CCCR_INIT_MASK);
        } else {
            DL_Common_updateReg(&mcan->MCANSS.MCAN.MCAN_CCCR,
                MCAN_CCCR_INIT_MASK, MCAN_CCCR_INIT_MASK);
        }
    }

    return stateRestored;
}

#endif /* __MSPM0_HAS_MCAN__ */
