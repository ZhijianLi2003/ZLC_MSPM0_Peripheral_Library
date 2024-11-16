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
 *  @file       dl_flashctl.h
 *  @brief      Flash Controller Driver Library
 *  @defgroup   FLASHCTL Flash Controller (FLASHCTL)
 *
 *  @anchor ti_dl_dl_flashctl_Overview
 *  # Overview
 *
 *  The Flash Controller Driver Library allows full configuration of
 *  the MSPM0 Non-Volatile memory system.
 *  The non-volatile memory (NVM) system provides nonvolatile flash memory for
 *  storing executable code and data.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup FLASHCTL
 * @{
 */
#ifndef ti_dl_dl_flashctl__include
#define ti_dl_dl_flashctl__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>
#include <ti/driverlib/m0p/dl_factoryregion.h>
#include <ti/driverlib/m0p/dl_sysctl.h>

#ifdef __cplusplus
extern "C" {
#endif

#if (FLASHCTL_SYS_DATAWIDTH == 128)
/*!
 * @brief Device has 128 bit flash word width
 */
#define DEVICE_HAS_FLASH_128_BIT_WORD
#endif

#if (FLASHCTL_SYS_WEPROTAWIDTH == 0)
/*!
 *  @brief Device does not have CMDWEPROTA
 */
#define DEVICE_HAS_NO_CMDWEPROTA
#endif

/* clang-format off */

/*!
 * @brief Address for Bank 0
 */
#define FLASHCTL_BANK0_ADDRESS                                      (0x00000000)

/*!
 * @brief Address for MAIN memory region
 */
#define FLASHCTL_MAIN_ADDRESS                                       (0x00000000)

/*!
 * @brief Address for NONMAIN memory region
 */
#define FLASHCTL_NONMAIN_ADDRESS                                    (0x41c00000)

/*!
 * @brief Number of NONMAIN sectors
 */
#define NUMBER_OF_NONMAIN_SECTORS                                            (1)

/*!
 * @brief Address for DATA memory region
 */
#define FLASHCTL_DATA_ADDRESS                                       (0x41d00000)

/*!
 * @brief Enable programming 8 bits without ECC enabled
 */
#define DL_FLASHCTL_PROGRAM_8_WITHOUT_ECC                           (0x00000001)

/*!
 * @brief Enable programming 16 bits without ECC enabled
 */
#define DL_FLASHCTL_PROGRAM_16_WITHOUT_ECC                          (0x00000003)

/*!
 * @brief Enable programming 32 bits without ECC enabled
 */
#define DL_FLASHCTL_PROGRAM_32_WITHOUT_ECC                          (0x0000000F)

/*!
 * @brief Enable programming 64 bits without ECC enabled
 */
#define DL_FLASHCTL_PROGRAM_64_WITHOUT_ECC                          (0x000000FF)

/*!
 * @brief Enable programming 8 bits with ECC enabled
 */
#define DL_FLASHCTL_PROGRAM_8_WITH_ECC                              (0x00000101)

/*!
 * @brief Enable programming 16 bits with ECC enabled
 */
#define DL_FLASHCTL_PROGRAM_16_WITH_ECC                             (0x00000103)

/*!
 * @brief Enable programming 32 bits with ECC enabled
 */
#define DL_FLASHCTL_PROGRAM_32_WITH_ECC                             (0x0000010F)

/*!
 * @brief Enable programming 64 bits with ECC enabled
 */
#define DL_FLASHCTL_PROGRAM_64_WITH_ECC                             (0x000001FF)

/*!
 * @brief Enable programming 64 bits with ECC enabled
 */
#define DL_FLASHCTL_READ_VERIFY_8_WITHOUT_ECC                       (0x00000001)

/*!
 * @brief Enable programming 64 bits with ECC enabled
 */
#define DL_FLASHCTL_READ_VERIFY_16_WITHOUT_ECC                      (0x00000003)

/*!
 * @brief Enable programming 64 bits with ECC enabled
 */
#define DL_FLASHCTL_READ_VERIFY_32_WITHOUT_ECC                      (0x0000000F)

/*!
 * @brief Enable programming 64 bits with ECC enabled
 */
#define DL_FLASHCTL_READ_VERIFY_64_WITHOUT_ECC                      (0x000000FF)

/*!
 * @brief Enable programming 64 bits with ECC enabled
 */
#define DL_FLASHCTL_READ_VERIFY_8_WITH_ECC                          (0x00000101)

/*!
 * @brief Enable programming 64 bits with ECC enabled
 */
#define DL_FLASHCTL_READ_VERIFY_16_WITH_ECC                         (0x00000103)

/*!
 * @brief Enable programming 64 bits with ECC enabled
 */
#define DL_FLASHCTL_READ_VERIFY_32_WITH_ECC                         (0x0000010F)

/*!
 * @brief Enable programming 64 bits with ECC enabled
 */
#define DL_FLASHCTL_READ_VERIFY_64_WITH_ECC                         (0x000001FF)

/** @addtogroup DL_FLASHCTL_INTERRUPT
 *  @{
 */
/*!
 * @brief Flash Command execution has completed
 */
#define DL_FLASHCTL_INTERRUPT_DONE                       (FLASHCTL_MIS_DONE_SET)
/** @}*/

/** @addtogroup DL_FLASHCTL_COMMAND_TYPE
 *  @{
 */
/*!
 * @brief No Operation Flash Command
 */
#define DL_FLASHCTL_COMMAND_TYPE_NO_OPERATION    (FLASHCTL_CMDTYPE_COMMAND_NOOP)

/*!
 * @brief Program Command Type
 */
#define DL_FLASHCTL_COMMAND_TYPE_PROGRAM      (FLASHCTL_CMDTYPE_COMMAND_PROGRAM)

/*!
 * @brief Erase Command Type
 */
#define DL_FLASHCTL_COMMAND_TYPE_ERASE          (FLASHCTL_CMDTYPE_COMMAND_ERASE)

/*!
 * @brief Read-Verify Command Type
 */
#define DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY                                   \
                                           (FLASHCTL_CMDTYPE_COMMAND_READVERIFY)

/*!
 * @brief Blank Verify Command Type
 */
#define DL_FLASHCTL_COMMAND_TYPE_BLANK_VERIFY                                  \
                                          (FLASHCTL_CMDTYPE_COMMAND_BLANKVERIFY)

/*!
 * @brief Mode Change Command Type
 */
#define DL_FLASHCTL_COMMAND_TYPE_MODE_CHANGE                                   \
                                           (FLASHCTL_CMDTYPE_COMMAND_MODECHANGE)

/*!
 * @brief Clear Status Command Type
 */
#define DL_FLASHCTL_COMMAND_TYPE_CLEAR_STATUS                                  \
                                          (FLASHCTL_CMDTYPE_COMMAND_CLEARSTATUS)
/** @}*/

/* clang-format on */

/*! @enum DL_FLASHCTL_COMMAND_SIZE */
typedef enum {
    /*! Flash Command size is one word */
    DL_FLASHCTL_COMMAND_SIZE_ONE_WORD = FLASHCTL_CMDTYPE_SIZE_ONEWORD,
    /*! Flash Command size is two words */
    DL_FLASHCTL_COMMAND_SIZE_TWO_WORDS = FLASHCTL_CMDTYPE_SIZE_TWOWORD,
    /*! Flash Command size is four words */
    DL_FLASHCTL_COMMAND_SIZE_FOUR_WORDS = FLASHCTL_CMDTYPE_SIZE_FOURWORD,
    /*! Flash Command size is eight words */
    DL_FLASHCTL_COMMAND_SIZE_EIGHT_WORDS = FLASHCTL_CMDTYPE_SIZE_EIGHTWORD,
    /*! Flash Command size is a sector */
    DL_FLASHCTL_COMMAND_SIZE_SECTOR = FLASHCTL_CMDTYPE_SIZE_SECTOR,
    /*! Flash Command size is a bank */
    DL_FLASHCTL_COMMAND_SIZE_BANK = FLASHCTL_CMDTYPE_SIZE_BANK

} DL_FLASHCTL_COMMAND_SIZE;

/*! @enum DL_FLASHCTL_REGION_SELECT */
typedef enum {
    /*! Flash Region Select Main */
    DL_FLASHCTL_REGION_SELECT_MAIN = FLASHCTL_CMDCTL_REGIONSEL_MAIN,
    /*! Flash Region Select Non-Main */
    DL_FLASHCTL_REGION_SELECT_NONMAIN = FLASHCTL_CMDCTL_REGIONSEL_NONMAIN

} DL_FLASHCTL_REGION_SELECT;

/*! @enum DL_FLASHCTL_BANK_SELECT */
typedef enum {
    /*! Bank 0 */
    DL_FLASHCTL_BANK_SELECT_0 = FLASHCTL_CMDCTL_BANKSEL_BANK0,
    /*! Bank 1 */
    DL_FLASHCTL_BANK_SELECT_1 = FLASHCTL_CMDCTL_BANKSEL_BANK1,
    /*! Bank 2 */
    DL_FLASHCTL_BANK_SELECT_2 = FLASHCTL_CMDCTL_BANKSEL_BANK2,
    /*! Bank 3 */
    DL_FLASHCTL_BANK_SELECT_3 = FLASHCTL_CMDCTL_BANKSEL_BANK3,
    /*! Bank 4 */
    DL_FLASHCTL_BANK_SELECT_4 = FLASHCTL_CMDCTL_BANKSEL_BANK4
} DL_FLASHCTL_BANK_SELECT;

/*! @enum DL_FLASHCTL_FAIL_TYPE */
typedef enum {
    /*! Flash Command did not fail during execution  */
    DL_FLASHCTL_FAIL_TYPE_NO_FAILURE = 0x0,
    /*! Flash Command failed due to write/erase protect sector violation */
    DL_FLASHCTL_FAIL_TYPE_WRITE_ERASE_PROTECT =
        (FLASHCTL_STATCMD_FAILWEPROT_STATFAIL),
    /*! Flash Command failed due to verify error */
    DL_FLASHCTL_FAIL_TYPE_VERIFY_ERROR = FLASHCTL_STATCMD_FAILVERIFY_STATFAIL,
    /*! Flash Command failed due to the use of an illegal address */
    DL_FLASHCTL_FAIL_TYPE_ILLEGAL_ADDRESS =
        FLASHCTL_STATCMD_FAILILLADDR_STATFAIL,
    /*! Flash Command failed because a bank has been set to a mode other than READ */
    DL_FLASHCTL_FAIL_TYPE_WRONG_BANK_MODE = FLASHCTL_STATCMD_FAILMODE_STATFAIL,
    /*! Flash Command failed due to an undefined error */
    DL_FLASHCTL_FAIL_TYPE_MISCELLANEOUS = FLASHCTL_STATCMD_FAILMISC_STATFAIL,
} DL_FLASHCTL_FAIL_TYPE;

/*! @enum DL_FLASHCTL_COMMAND_STATUS */
typedef enum {
    /*! Flash Command passed */
    DL_FLASHCTL_COMMAND_STATUS_PASSED = (FLASHCTL_STATCMD_CMDDONE_STATDONE |
                                         FLASHCTL_STATCMD_CMDPASS_STATPASS),
    /*! Flash Command failed */
    DL_FLASHCTL_COMMAND_STATUS_FAILED = (FLASHCTL_STATCMD_CMDDONE_STATDONE |
                                         FLASHCTL_STATCMD_CMDPASS_STATFAIL),
    /*! Flash Command is still in progress */
    DL_FLASHCTL_COMMAND_STATUS_IN_PROGRESS =
        (FLASHCTL_STATCMD_CMDINPROGRESS_STATINPROGRESS)

} DL_FLASHCTL_COMMAND_STATUS;

/*! @enum DL_FLASHCTL_IIDX */
typedef enum {
    /*! DONE Interrupt Pending */
    DL_FLASHCTL_IIDX_DONE = FLASHCTL_IIDX_STAT_DONE
} DL_FLASHCTL_IIDX;

/**
 *  @brief      Enable flash interrupt
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_FlashCTL_enableInterrupt(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.IMASK = FLASHCTL_IMASK_DONE_ENABLED;
}

/**
 *  @brief      Disable flash interrupt
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_FlashCTL_disableInterrupt(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.IMASK = FLASHCTL_IMASK_DONE_DISABLED;
}

/**
 *  @brief      Check if the flash interrupt is enabled
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     If the flash interrupt is enabled
 *
 *  @retval     false if interrupt is disabled
 *  @retval     true if interrupt is enabled
 */
__STATIC_INLINE bool DL_FlashCTL_isInterruptEnabled(FLASHCTL_Regs *flashctl)
{
    return (flashctl->GEN.IMASK == FLASHCTL_IMASK_DONE_ENABLED);
}

/**
 *  @brief      Check interrupt flag of enabled flash interrupt
 *
 *  Checks if the flash interrupt that was previously enabled is pending.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     If the flash interrupt is pending
 *
 *  @retval     0 if no interrupt is enabled
 *  @retval     The value of @ref DL_FLASHCTL_INTERRUPT
 */
__STATIC_INLINE uint32_t DL_FlashCTL_getEnabledInterruptStatus(
    FLASHCTL_Regs *flashctl)
{
    return (flashctl->GEN.MIS);
}

/**
 *  @brief      Check interrupt flag of the flash interrupt
 *
 *  Checks if the flash interrupt is pending. Interrupts do not have to be
 *  previously enabled.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     If the flash interrupt is pending
 *
 *  @retval     0 if no interrupt is enabled
 *  @retval     The value of @ref DL_FLASHCTL_INTERRUPT
 */
__STATIC_INLINE uint32_t DL_FlashCTL_getRawInterruptStatus(
    FLASHCTL_Regs *flashctl)
{
    return (flashctl->GEN.RIS);
}

/**
 *  @brief      Get highest priority pending flash interrupt
 *
 *  Checks if the flash interrupt is pending. Interrupts do not have to be
 *  previously enabled.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     The highest priority pending FLASH interrupt
 *
 */
__STATIC_INLINE uint32_t DL_FlashCTL_getPendingInterrupt(
    FLASHCTL_Regs *flashctl)
{
    return (flashctl->GEN.IIDX);
}

/**
 *  @brief      Clear pending flash interrupt
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_FlashCTL_clearInterruptStatus(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.ICLR = FLASHCTL_ICLR_DONE_CLR;
}

/**
 *  @brief      Checks if a command execution has been initiated
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     If a command has been set to execute
 *
 */
__STATIC_INLINE bool DL_FlashCTL_isCommandExecuted(FLASHCTL_Regs *flashctl)
{
    return (flashctl->GEN.CMDEXEC == FLASHCTL_CMDEXEC_VAL_EXECUTE);
}

/**
 *  @brief      Initiates a command execution
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_FlashCTL_setCommandExecute(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

/**
 *  @brief      Disable Stair-Step Erase
 *
 * The default VHV trim voltage setting will be used for all erase pulses.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_FlashCTL_disbleStairStepErase(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDCTL |= FLASHCTL_CMDCTL_SSERASEDIS_DISABLE;
}

/**
 *  @brief      Checks if stair-step erase is disabled
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     If stair-step erase is disabled
 *
 */
__STATIC_INLINE bool DL_FlashCTL_isStairStepEraseDisabled(
    FLASHCTL_Regs *flashctl)
{
    return ((flashctl->GEN.CMDCTL & FLASHCTL_CMDCTL_SSERASEDIS_MASK) ==
            FLASHCTL_CMDCTL_SSERASEDIS_DISABLE);
}

/**
 *  @brief      Enable Stair-Step Erase
 *
 * The VHV voltage will be stepped during successive erase pulses. The step
 * count, step voltage, begin and end voltages are all hard-wired. This is
 * enabled by default.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_FlashCTL_enableStairStepErase(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDCTL &= ~(FLASHCTL_CMDCTL_SSERASEDIS_MASK);
}

/**
 *  @brief      Enable address override mode
 *
 * This overrides hardware address translation in CMDADDR from a system address
 * to a bank address and bank ID. Use data written to CMDADDR directly as the
 * bank address. Use the value written to CMDCTL.BANKSEL directly as the bank
 * ID. Use the value written to CMDCTL.REGIONSEL directly as the region ID.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 * @sa DL_FlashCTL_setCommandAddress
 * @sa DL_FlashCTL_setBankSelect
 * @sa DL_FlashCTL_setRegionSelect
 */
__STATIC_INLINE void DL_FlashCTL_enableAddressOverrideMode(
    FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDCTL |= FLASHCTL_CMDCTL_ADDRXLATEOVR_OVERRIDE;
}

/**
 *  @brief      Checks if address override mode is enabled
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     If address override mode is enabled
 */
__STATIC_INLINE bool DL_FlashCTL_isAddressOverrideModeEnabled(
    FLASHCTL_Regs *flashctl)
{
    return ((flashctl->GEN.CMDCTL & FLASHCTL_CMDCTL_ADDRXLATEOVR_MASK) ==
            FLASHCTL_CMDCTL_ADDRXLATEOVR_OVERRIDE);
}

/**
 *  @brief      Disable address override mode
 *
 * Disable address override mode and return to system addressed mode.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_FlashCTL_disableAddressOverrideMode(
    FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDCTL &= ~(FLASHCTL_CMDCTL_ADDRXLATEOVR_MASK);
}

/**
 *  @brief      Enable overriding hardware generation of ECC code
 *
 * Override hardware ECC code generation by the flash controller. When enabled,
 * the user can then manually set the ECC code to be programmed by calling
 * @ref DL_FlashCTL_setCommandDataECC.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 * @sa DL_FlashCTL_setCommandDataECC
 */
__STATIC_INLINE void DL_FlashCTL_enableOverrideHardwareGeneratedECC(
    FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDCTL |= FLASHCTL_CMDCTL_ECCGENOVR_OVERRIDE;
}

/**
 *  @brief      Checks if overriding hardware generation of ECC code is enabled
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     If overriding hardware generation of ECC code is enabled
 */
__STATIC_INLINE bool DL_FlashCTL_isOverrideHardwareGeneratedECCEnabled(
    FLASHCTL_Regs *flashctl)
{
    return ((flashctl->GEN.CMDCTL & FLASHCTL_CMDCTL_ECCGENOVR_MASK) ==
            FLASHCTL_CMDCTL_ECCGENOVR_OVERRIDE);
}

/**
 *  @brief      Disable overriding hardware generation of ECC code
 *
 * Disable overriding hardware generation of ECC code, so the flash controller
 * will handle generating the needed ECC bits from the data
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_FlashCTL_disableOverrideHardwareGeneratedECC(
    FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDCTL &= ~(FLASHCTL_CMDCTL_ECCGENOVR_MASK);
}

/**
 *  @brief      Set the region select
 *
 * A specific region ID can be written to this field to indicate to which
 * region an operation should be applied if CMDCTL.ADDRXLATEOVR is set.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  region      Region to select. One of @ref DL_FLASHCTL_REGION_SELECT
 *
 *  @sa DL_FlashCTL_enableAddressOverrideMode
 */
__STATIC_INLINE void DL_FlashCTL_setRegionSelect(
    FLASHCTL_Regs *flashctl, DL_FLASHCTL_REGION_SELECT region)
{
    DL_Common_updateReg(&flashctl->GEN.CMDCTL, (uint32_t) region,
        (uint32_t) FLASHCTL_CMDCTL_REGIONSEL_MASK);
}

/**
 *  @brief      Get the region select
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *
 *  @return     The region selected
 *
 *  @retval     One of @ref DL_FLASHCTL_REGION_SELECT
 */
__STATIC_INLINE DL_FLASHCTL_REGION_SELECT DL_FlashCTL_getRegionSelect(
    FLASHCTL_Regs *flashctl)
{
    uint32_t region = flashctl->GEN.CMDCTL & FLASHCTL_CMDCTL_REGIONSEL_MASK;

    return (DL_FLASHCTL_REGION_SELECT)(region);
}

/**
 *  @brief      Set the bank select
 *
 * A specific bank ID can be written to this field to indicate which bank an
 * operation should be applied if CMDCTL.ADDRXLATEOVR is set.
 *
 *  @note Refer to the device datasheet for the number of banks that are
 *  available on your device.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *  @param[in]  bank      Bank to select. One of @ref DL_FLASHCTL_BANK_SELECT
 *
 *  @sa DL_FlashCTL_enableAddressOverrideMode
 */
__STATIC_INLINE void DL_FlashCTL_setBankSelect(
    FLASHCTL_Regs *flashctl, DL_FLASHCTL_BANK_SELECT bank)
{
    DL_Common_updateReg(&flashctl->GEN.CMDCTL, (uint32_t) bank,
        (uint32_t) FLASHCTL_CMDCTL_BANKSEL_MASK);
}

/**
 *  @brief      Get the bank select
 *
 *  @note Refer to the device datasheet for the number of banks that are
 *  available on your device.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *
 *  @return     The bank selected
 *
 *  @retval     One of @ref DL_FLASHCTL_BANK_SELECT
 */
__STATIC_INLINE DL_FLASHCTL_BANK_SELECT DL_FlashCTL_getBankSelect(
    FLASHCTL_Regs *flashctl)
{
    uint32_t bank = flashctl->GEN.CMDCTL & FLASHCTL_CMDCTL_BANKSEL_MASK;

    return (DL_FLASHCTL_BANK_SELECT)(bank);
}

/**
 *  @brief      Set the bytes to enable for programming data
 *
 * This register forms a per-byte enable for programming data. Each bit in
 * CMDBYTEN corresponds to a byte in the addressed flash word to be programmed,
 * including the ECC byte. This allows sub-word programming (programming of
 * less than the full 64 or 72 bit flash word) if desired.
 *
 * ECC data bytes are protected by the MSB bits in this register, depending on
 * the presence of ECC and the flash word data width. Note: Refer to the TRM on
 * how to correctly handle ECC for sub-word programs. You cannot correctly
 * program the ECC bits if the whole 64 bits of the data word is not
 * programmed, so the ECC byte should not be enabled until all 64 bits of the
 * flash word are programmed.
 *
 * This register is written to all 0 after the completion of all FLASHCTL
 * commands.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  byteMask   Mask of bytes to enable. Between [0,0x1FF].
 *                         For example:
 *                         - byteMask = 0x0, Disable all bytes for programming
 *                         - byteMask = 0x1, Enable 8-bit programming
 *                         - byteMask = 0x3, Enable 16-bit programming
 *                         - byteMask = 0xF, Enable 32-bit programming
 *                         - byteMask = 0xFF, Enable 64-bit programming
 *                         - byteMask = 0x1FF, Enable 64-bit programming with
 *                           ECC enabled
 */
__STATIC_INLINE void DL_FlashCTL_setCommandByteEnable(
    FLASHCTL_Regs *flashctl, uint32_t byteMask)
{
    flashctl->GEN.CMDBYTEN = byteMask;
}

/**
 *  @brief      Get the bytes that are enabled for programming data
 *
 * This register forms a per-byte enable for programming data. Each bit in
 * CMDBYTEN corresponds to a byte in the addressed flash word to be programmed,
 * including the ECC byte. This allows sub-word programming (programming of
 * less than the full 64 or 72 bit flash word) if desired.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *
 *  @return     The enabled bytes
 *
 *  @retval     Value between [0,0x1FF].
 */
__STATIC_INLINE uint32_t DL_FlashCTL_getCommandByteEnable(
    FLASHCTL_Regs *flashctl)
{
    return ((uint32_t) flashctl->GEN.CMDCTL &
            (uint32_t)(FLASHCTL_CMDBYTEN_VAL_MASK));
}

/**
 *  @brief      Set the data for a command data register
 *
 * The command data registers, CMDDATAx, are used to form the data for a
 * command. For devices which only support single word programming, only the
 * CMDDATA0 and CMDDATA1 registers are used to load data to be programmed to
 * the flash memory. CMDDATA0 is always loaded with BIT31-BIT0 of the target
 * data, and CMDDATA1 is always loaded with BIT63-BIT32 of the target data.
 * If fewer than 64 data bits are being programmed, see the special handling
 * requirements section in the device TRM for programming less than one flash
 * word.
 *
 * @note Ensure that you have enabled the correct bytes for programming enabled
 * with @ref DL_FlashCTL_setCommandByteEnable.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  index      Select the command data register to write to.
 *                         Please see the device TRM for the number of CMDDATA
 *                         registers. For example:
 *                         - index = 0, Select CMDDATA0
 *                         - index = 1, Select CMDDATA1
 *  @param[in]  data       Data to write to the command data register.
 *                         Value between [0,0xFFFFFFFF]
 */
__STATIC_INLINE void DL_FlashCTL_setCommandData(
    FLASHCTL_Regs *flashctl, uint8_t index, uint32_t *data)
{
    volatile uint32_t *pReg = &(flashctl->GEN.CMDDATA0) + index;

    *pReg = *data;
}

/**
 *  @brief      Get the data from a command data register
 *
 * For devices which only support single word programming, only the
 * CMDDATA0 and CMDDATA1 registers are used to load data to be programmed to
 * the flash memory. CMDDATA0 is always loaded with BIT31-BIT0 of the target
 * data, and CMDDATA1 is always loaded with BIT63-BIT32 of the target data.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  index      Select the command data register to write to.
 *                         Please see the device TRM for the number of CMDDATA
 *                         registers. For example:
 *                         - index = 0, Select CMDDATA0
 *                         - index = 1, Select CMDDATA1
 *
 *  @return     The data in the command data register
 *
 *  @retval     Value between [0,0xFFFFFFFF].
 */
__STATIC_INLINE uint32_t DL_FlashCTL_getCommandData(
    FLASHCTL_Regs *flashctl, uint8_t index)
{
    volatile uint32_t *pReg = &(flashctl->GEN.CMDDATA0);

    return (
        (uint32_t)(*(pReg + index) & (uint32_t) FLASHCTL_CMDDATA0_VAL_MASK));
}

/**
 *  @brief      Set the ECC code in the command data ECC register
 *
 * This register forms the ECC portion of the data for a command.
 *
 * @note The ECC data can be manually set only when hardware ECC code
 * generation is disabled with
 * @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *
 * @note Ensure that you have enabled the correct bytes for programming ECC
 * enabled with @ref DL_FlashCTL_setCommandByteEnable
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  index      Select the command data ECC register to write to.
 *                         Please see the device TRM for the number of
 *                         CMDDATAECC registers. For example:
 *                         - index = 0, Select CMDDATAECC0
 *                         - index = 1, Select CMDDATAECC1
 *  @param[in]  data       Data to write to the command data ECC register.
 *                         Value between [0, 0xFF]
 */
__STATIC_INLINE void DL_FlashCTL_setCommandDataECC(
    FLASHCTL_Regs *flashctl, uint8_t index, uint8_t *data)
{
    volatile uint32_t *pReg = &(flashctl->GEN.CMDDATAECC0) + index;

    *pReg = *data;
}

/**
 *  @brief      Get the ECC code in the command data ECC register
 *
 * This register forms the ECC portion of the data for a command.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  index      Select the command data register ECC to write to.
 *                         Please see the device TRM for the number of
 *                         CMDDATAECC registers. For example:
 *                         - index = 0, Select CMDDATAECC0
 *                         - index = 1, Select CMDDATAECC1
 *
 *  @return     The data in the command data ECC register
 *
 *  @retval     Value between [0,0xFF].
 */
__STATIC_INLINE uint8_t DL_FlashCTL_getCommandDataECC(
    FLASHCTL_Regs *flashctl, uint8_t index)
{
    volatile uint32_t *pReg = &(flashctl->GEN.CMDDATAECC0);

    return ((uint8_t)(
        *(pReg + index) & (uint32_t) FLASHCTL_CMDDATAECC0_VAL0_MASK));
}

/**
 *  @brief      Sets the target address for a command
 *
 *  The target address for a command must be flash word (64-bit) aligned. This
 *  means that the target address must be aligned to a 0b000 boundary (for
 *  example, the 3 LSBs in the address must be zero).
 *
 *  1) For single-word program, this address indicates the flash bank word to be
 *     programmed.
 *  2) For multi-word program, this address indicates the first flash bank
 *     address for the program. The address will be incremented
 *  3) For sector and bank erase, this address indicates the sector or bank to
 *     be erased.
 *  4) For read verify, this address forms the start address for the verify
 *     operation.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *  @param[in]  address   Destination address to program/erase/read
 *
 */
__STATIC_INLINE void DL_FlashCTL_setCommandAddress(
    FLASHCTL_Regs *flashctl, uint32_t address)
{
    flashctl->GEN.CMDADDR = address;
}

/**
 *  @brief      Returns the status  of the current command
 *
 *  Checks if the command is still in progress or finished and if it passed or
 *  failed
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of the current command
 *
 *  @retval     One of @ref DL_FLASHCTL_COMMAND_STATUS values
 */
__STATIC_INLINE DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_getCommandStatus(
    FLASHCTL_Regs *flashctl)
{
    uint32_t commandStatus =
        flashctl->GEN.STATCMD &
        (FLASHCTL_STATCMD_CMDDONE_MASK | FLASHCTL_STATCMD_CMDPASS_MASK |
            FLASHCTL_STATCMD_CMDINPROGRESS_MASK |
            FLASHCTL_STATCMD_CMDPASS_STATFAIL);

    return (DL_FLASHCTL_COMMAND_STATUS)(commandStatus);
}

/**
 *  @brief      Returns the reason a command failed
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     The type of command failure
 *
 *  @retval     One of @ref DL_FLASHCTL_FAIL_TYPE values
 */
__STATIC_INLINE DL_FLASHCTL_FAIL_TYPE DL_FlashCTL_getFailureStatus(
    FLASHCTL_Regs *flashctl)
{
    uint32_t commandFailureType =
        flashctl->GEN.STATCMD &
        (FLASHCTL_STATCMD_FAILWEPROT_MASK | FLASHCTL_STATCMD_FAILVERIFY_MASK |
            FLASHCTL_STATCMD_FAILILLADDR_MASK |
            FLASHCTL_STATCMD_FAILMODE_MASK | FLASHCTL_STATCMD_FAILMISC_MASK);

    return (DL_FLASHCTL_FAIL_TYPE)(commandFailureType);
}

/**
 *  @brief      Blocking function that waits for a command execution to finish
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true if command was successful
 */
__STATIC_INLINE bool DL_FlashCTL_waitForCmdDone(FLASHCTL_Regs *flashctl)
{
    /* Wait for command to complete */
    while ((flashctl->GEN.STATCMD & FLASHCTL_STATCMD_CMDDONE_MASK) !=
           FLASHCTL_STATCMD_CMDDONE_STATDONE) {
        ;
    }

    return ((flashctl->GEN.STATCMD & FLASHCTL_STATCMD_CMDPASS_MASK) ==
            FLASHCTL_STATCMD_CMDPASS_STATPASS);
}

/**
 *  @brief      Sets clear status bit and executes command
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_FlashCTL_executeClearStatus(FLASHCTL_Regs *flashctl)
{
    /* Set COMMAND bit within CMDTYPE register to clear status*/
    flashctl->GEN.CMDTYPE = DL_FLASHCTL_COMMAND_TYPE_CLEAR_STATUS;
    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

/**
 *  @brief      Gets the sector number of the input address over the whole
 *              memory map
 *
 *  If the device has two 128KB banks, and the input address is 0x20000, then
 *  this API will return the sector number as 128.
 *  To get the sector number over the whole memory map of the device, refer to
 *  @ref DL_FlashCTL_getFlashSectorNumberInBank.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *  @param[in]  addr      Memory address within the desired sector
 *
 *  @return     The sector number that contains the input address
 */
__STATIC_INLINE uint32_t DL_FlashCTL_getFlashSectorNumber(
    FLASHCTL_Regs *flashctl, uint32_t addr)
{
    return (addr >> (uint32_t) 10);
}

/**
 *  @brief      Gets the sector number of the input address relative to the
 *              bank of the address
 *
 *  If the device has two 128KB banks, and the input address is 0x20000, then
 *  this API will return the sector number as 0. This is because 0x20000 is in
 *  Sector 0 of Bank 1.
 *  To get the sector number over the whole memory map of the device, refer to
 *  @ref DL_FlashCTL_getFlashSectorNumber.
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *  @param[in]  addr      Memory address within the desired sector
 *
 *  @return     The sector number in the current bank that contains the address
 */
__STATIC_INLINE uint32_t DL_FlashCTL_getFlashSectorNumberInBank(
    FLASHCTL_Regs *flashctl, uint32_t addr)
{
    uint8_t numBanks       = DL_FactoryRegion_getNumBanks();
    uint32_t mainFlashSize = DL_FactoryRegion_getMAINFlashSize();
    uint32_t sector, bankSectors, sectorInBank;

    /* Current sector over the whole memory map */
    sector = DL_FlashCTL_getFlashSectorNumber(flashctl, addr);
    if (numBanks > 1) {
        /* Number of sectors per bank, considered max sector
         * count for a bank-adjusted sector. Assume banks are
         * evenly distributed */
        bankSectors = (mainFlashSize / numBanks);
        /* We will not assume that the maximum number of bank sectors is a
         * multiple of 2. Which does mean incurring a modulo operation. */
        sectorInBank = sector % bankSectors;
    } else {
        sectorInBank = sector;
    }

    return sectorInBank;
}

/**
 *  @brief      Set the number of wait states used by the Flash
 *
 *  Changes the number of wait states used by the Flash controller. When
 *  changing the frequency of the clock, the number of wait states may need to
 *  be updated.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  waitState  Number of wait states to set. Recommended values
 *                         are based on the system clock speed:
 *                           - 0MHz-24MHz: 0 wait state
 *                           - 24MHz-48MHz: 1 wait state
 *                           - 48MHz-72MHz: 2 wait states
 *                           - 72MHz-80MHz: 3 wait states
 */
__STATIC_INLINE void DL_FlashCTL_setWaitState(
    FLASHCTL_Regs *flashctl, uint32_t waitState)
{
    flashctl->GEN.CFGCMD = waitState;
}

/**
 *  @brief      Get the number of wait states used by the Flash
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *
 *  @return     The number of wait states used by the Flash
 */
__STATIC_INLINE uint32_t DL_FlashCTL_getWaitState(FLASHCTL_Regs *flashctl)
{
    return (flashctl->GEN.CFGCMD & FLASHCTL_CFGCMD_WAITSTATE_MASK);
}

/**
 *  @brief      Performs an erase on unprotected memory
 *
 *  Performs an erase on unprotected memory within a sector or bank of memory
 *  containing the input memory address.
 *
 *  NOTE: The user is responsible for unprotecting the regions of memory prior
 *  to calling this API. Memory will be automatically protected following the
 *  command execution.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address       Memory address within desired sector or bank to
 *                            erase
 *  @param[in]  memorySize    The size of the memory block to erase. One of:
 *                            @arg DL_FLASHCTL_COMMAND_SIZE_BANK
 *                            @arg DL_FLASHCTL_COMMAND_SIZE_SECTOR
 *
 * @post        This API just starts the erase process. Check the result of it
 *              using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 */
void DL_FlashCTL_eraseMemory(FLASHCTL_Regs *flashctl, uint32_t address,
    DL_FLASHCTL_COMMAND_SIZE memorySize);

/**
 *  @brief      Performs an erase on unprotected memory, and executes command
 *              from RAM
 *
 *  Performs an erase on unprotected memory within a sector or bank of memory
 *  containing the input memory address.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  NOTE: The user is responsible for unprotecting the regions of memory prior
 *  to calling this API. Memory will be automatically protected following the
 *  command execution.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address       Memory address within desired sector or bank to
 *                            erase
 *  @param[in]  memorySize    The size of the memory block to erase. One of:
 *                            @arg DL_FLASHCTL_COMMAND_SIZE_BANK
 *                            @arg DL_FLASHCTL_COMMAND_SIZE_SECTOR
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 * @post        This API just starts the erase process. Check the result of it
 *              using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_eraseMemoryFromRAM(
    FLASHCTL_Regs *flashctl, uint32_t address,
    DL_FLASHCTL_COMMAND_SIZE memorySize);

/**
 *  @brief      Performs a mass erase on main memory on one bank
 *
 *  Performs a mass erase on main memory on Bank 0 only. This API should be used
 *  on single bank devices.
 *
 *  NOTE: This API sets all main memory to unprotected from erase/program
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     Whether or not the erase succeeded
 *
 *  @retval     false if erase didn't succeed
 *  @retval     true  if erase was successful
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 */
bool DL_FlashCTL_massErase(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Performs a mass erase on main memory, and executes command
 *              from RAM
 *
 *  Performs a mass erase on main memory on Bank 0 only. This API should be used
 *  on single bank devices.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  NOTE: This API sets all main memory to unprotected from erase/program
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     Whether or not the erase succeeded
 *
 *  @retval     false if erase didn't succeed
 *  @retval     true  if erase was successful
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_massEraseFromRAM(
    FLASHCTL_Regs *flashctl);

/**
 *  @brief      Performs a mass erase on main memory, and erases all flash banks
 *
 *  Performs a mass erase on main memory within each flash bank.
 *
 *  NOTE: This API sets all main memory to unprotected from erase/program
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     Whether or not the erase succeeded
 *
 *  @retval     false if erase didn't succeed
 *  @retval     true  if erase was successful
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 */
bool DL_FlashCTL_massEraseMultiBank(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Performs a factory reset erase on main and non-main memory
 *
 *  Performs an erase on Bank 0 of main memory and non-main memory on the
 *  device. This API should be used on single bank devices.
 *
 *  NOTE: This API sets all main memory to protected from erase/program if
 *        successful. If unsuccessful, all memory will be unprotected
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     Whether or not the erase succeeded
 *
 *  @retval     false if erase didn't succeed
 *  @retval     true  if erase was successful
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 */
bool DL_FlashCTL_factoryReset(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Performs a factory reset erase on main and non-main memory, and
 *              executes command from RAM
 *
 *  Performs an erase on Bank 0 of main memory and non-main memory on the
 *  device. This API should be used on single bank devices.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  NOTE: This API sets all main memory to protected from erase/program if
 *        successful. If unsuccessful, all memory will be unprotected
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     Whether or not the erase succeeded
 *
 *  @retval     false if erase didn't succeed
 *  @retval     true  if erase was successful
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_factoryResetFromRAM(
    FLASHCTL_Regs *flashctl);

/**
 *  @brief      Performs a factory reset erase on main and non-main memory
 *
 *  Performs an erase on all flash banks of main memory and non-main memory on
 *  the device.
 *
 *  NOTE: This API sets all main memory to protected from erase/program if
 *        successful. If unsuccessful, all memory will be unprotected
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     Whether or not the erase succeeded
 *
 *  @retval     false if erase didn't succeed
 *  @retval     true  if erase was successful
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 */
bool DL_FlashCTL_factoryResetMultiBank(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Programs 8 bit data to unprotected memory at the given address
 *
 * The device datasheet specifies a maximum limit on program operations per
 * word line before erasure of the sector containing the word line is required.
 * Exceeding this maximum may result in data corruption within the word line.
 * If 8-bit (byte) program operations are performed, or the same memory
 * locations are programmed more than once, the max program limit per word line
 * must be considered and not exceeded. Because of that, it is better to buffer
 * data and use the @ref DL_FlashCTL_programMemory16,
 * @ref DL_FlashCTL_programMemory32 or @ref DL_FlashCTL_programMemory64 APIs to
 * program memory to reduce in the number of program operations in a wordline.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 8-bit source data
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
void DL_FlashCTL_programMemory8(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data);

/**
 *  @brief      Programs 8 bit data to unprotected memory at the given address,
 *              and executes command from RAM
 *
 * The device datasheet specifies a maximum limit on program operations per
 * word line before erasure of the sector containing the word line is required.
 * Exceeding this maximum may result in data corruption within the word line.
 * If 8-bit (byte) program operations are performed, or the same memory
 * locations are programmed more than once, the max program limit per word line
 * must be considered and not exceeded. Because of that, it is better to buffer
 * data and use the @ref DL_FlashCTL_programMemory16,
 * @ref DL_FlashCTL_programMemory32 or @ref DL_FlashCTL_programMemory64 APIs to
 * program memory to reduce in the number of program operations in a wordline.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 8-bit source data
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM8(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data);

/**
 *  @brief      Programs 16 bit data to unprotected memory at the given address
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 16-bit source data
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
void DL_FlashCTL_programMemory16(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data);

/**
 *  @brief      Programs 16 bit data to unprotected memory at the given
 *              address, and executes command from RAM
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 16-bit source data
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM16(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data);

/**
 *  @brief      Programs 32 bit data to unprotected memory at the given address
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
void DL_FlashCTL_programMemory32(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Programs 32 bit data to unprotected memory at the given
 *              address, and executes command from RAM
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM32(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Programs 64 bit data to unprotected memory at the given address
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
void DL_FlashCTL_programMemory64(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Programs 64 bit data to unprotected memory at the given
 *              address, and executes command from RAM
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM64(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Programs 8 bit data with hardware generated ECC code
 *
 *  Programs 8 bit data, along with the 8 ECC bits which correspond to the
 *  8-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 8-bit source data
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_programMemory8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data);

/**
 *  @brief      Programs 8 bit data with hardware generated ECC code, and
 *              executes command from RAM
 *
 *  Programs 8 bit data, along with the 8 ECC bits which correspond to the
 *  8-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 8-bit source data
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data);

/**
 *  @brief      Programs 16 bit data with hardware generated ECC code
 *
 *  Programs 16 bit data, along with the 8 ECC bits which correspond to the
 *  16-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 16-bit source data
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_programMemory16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data);

/**
 *  @brief      Programs 16 bit data with hardware generated ECC code, and
 *              executes command from RAM
 *
 *  Programs 16 bit data, along with the 8 ECC bits which correspond to the
 *  16-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *   The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 16-bit source data
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data);

/**
 *  @brief      Programs 32 bit data with hardware generated ECC code
 *
 *  Programs 32 bit data, along with the 8 ECC bits which correspond to the
 *  32-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_programMemory32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Programs 32 bit data with hardware generated ECC code, and
 *              executes command from RAM
 *
 *  Programs 16 bit data, along with the 8 ECC bits which correspond to the
 *  16-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *   The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Programs 64 bit data with hardware generated ECC code
 *
 *  Programs 64 bit data, along with the 8 ECC bits which correspond to the
 *  64-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_programMemory64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Programs 64 bit data with hardware generated ECC code, and
 *              executes command from RAM
 *
 *  Programs 16 bit data, along with the 8 ECC bits which correspond to the
 *  16-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *   The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Programs 8 bit data with user provided ECC code
 *
 *  Programs 8 bit data, along with the 8 ECC bits which correspond to the
 *  8-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code HAS been disabled,
 *  and so the user must provide the ECC code to program.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 8-bit source data
 *  @param[in]  eccCode    Pointer to the ECC code to program
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_programMemory8WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint8_t *data, uint8_t *eccCode);

/**
 *  @brief      Programs 8 bit data with user provided ECC code, and executes
 *              command from RAM
 *
 *  Programs 8 bit data, along with the 8 ECC bits which correspond to the
 *  8-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code HAS been disabled,
 *  and so the user must provide the ECC code to program.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 8-bit source data
 *  @param[in]  eccCode    Pointer to the ECC code to program
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM8WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data,
    uint8_t *eccCode);

/**
 *  @brief      Programs 16 bit data with user provided ECC code
 *
 *  Programs 16 bit data, along with the 8 ECC bits which correspond to the
 *  16-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code HAS been disabled,
 *  and so the user must provide the ECC code to program.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 16-bit source data
 *  @param[in]  eccCode    Pointer to the ECC code to program
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_programMemory16WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint16_t *data, uint8_t *eccCode);

/**
 *  @brief      Programs 16 bit data with user provided ECC code, and executes
 *              command from RAM
 *
 *  Programs 16 bit data, along with the 8 ECC bits which correspond to the
 *  16-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code HAS been disabled,
 *  and so the user must provide the ECC code to program.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 16-bit source data
 *  @param[in]  eccCode    Pointer to the ECC code to program
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM16WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data,
    uint8_t *eccCode);

/**
 *  @brief      Programs 32 bit data with user provided ECC code
 *
 *  Programs 32 bit data, along with the 8 ECC bits which correspond to the
 *  32-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code HAS been disabled,
 *  and so the user must provide the ECC code to program.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *  @param[in]  eccCode    Pointer to the ECC code to program
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_programMemory32WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode);

/**
 *  @brief      Programs 32 bit data with user provided ECC code, and executes
 *              command from RAM
 *
 *  Programs 32 bit data, along with the 8 ECC bits which correspond to the
 *  32-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code HAS been disabled,
 *  and so the user must provide the ECC code to program.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *  @param[in]  eccCode    Pointer to the ECC code to program
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM32WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode);

/**
 *  @brief      Programs 64 bit data with user provided ECC code
 *
 *  Programs 64 bit data, along with the 8 ECC bits which correspond to the
 *  64-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code HAS been disabled,
 *  and so the user must provide the ECC code to program.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *  @param[in]  eccCode    Pointer to the ECC code to program
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_programMemory64WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode);

/**
 *  @brief      Programs 64 bit data with user provided ECC code, and executes
 *              command from RAM
 *
 *  Programs 64 bit data, along with the 8 ECC bits which correspond to the
 *  64-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code HAS been disabled,
 *  and so the user must provide the ECC code to program.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *  @param[in]  eccCode    Pointer to the ECC code to program
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM64WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode);

/**
 *  @brief      Programs provided data with hardware generated ECC code
 *
 *  Blocking function that programs a set of data, along with the 8 ECC bits
 *  which correspond to the data at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  dataSize      The number of 32-bit words to program. Value
 *                            should be an even number, to ensure data is
 *                            programmed 64-bits at a time.
 *  @param[in]  data          Pointer to the data source to program into flash
 *  @param[in]  regionSelect  The region of memory to erase. One of
 *                            @ref DL_FLASHCTL_REGION_SELECT
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     false   Program didn't succeed, or invalid dataSize
 *  @retval     true    Program was successful
 *
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
bool DL_FlashCTL_programMemoryBlocking64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect);

/**
 *  @brief      Programs provided data with hardware generated ECC code, and
 *              executes command from RAM
 *
 *  Blocking function that programs a set of data, along with the 8 ECC bits
 *  which correspond to the data at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  dataSize      The number of 32-bit words to program. Value
 *                            should be an even number, to ensure data is
 *                            programmed 64-bits at a time.
 *  @param[in]  data          Pointer to the data source to program into flash
 *  @param[in]  regionSelect  The region of memory to erase. One of
 *                            @ref DL_FLASHCTL_REGION_SELECT
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     false   Program didn't succeed, or invalid dataSize
 *  @retval     true    Program was successful
 *
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
DL_FLASHCTL_COMMAND_STATUS
DL_FlashCTL_programMemoryBlockingFromRAM64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect);

/**
 *  @brief      Programs provided data with user provided ECC code
 *
 *  Blocking function that programs a set of data, along with the 8 ECC bits
 *  which correspond to the data at the given address. This API assumes that
 *  hardware generation of the ECC code HAS been disabled, and so the user
 *  must provide the ECC code to program.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  dataSize      The number of 32-bit words to program. Value
 *                            should be an even number, to ensure data is
 *                            programmed 64-bits at a time.
 *  @param[in]  data          Pointer to the data source to program into flash
 *  @param[in]  eccCode       Pointer to ECC code to program corresponding to data
 *  @param[in]  regionSelect  The region of memory to erase. One of
 *                            @ref DL_FLASHCTL_REGION_SELECT
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     false   Program didn't succeed, or invalid dataSize
 *  @retval     true    Program was successful
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
bool DL_FlashCTL_programMemoryBlocking64WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode, uint32_t dataSize,
    DL_FLASHCTL_REGION_SELECT regionSelect);

/**
 *  @brief      Programs provided data with user provided ECC code, and
 *              executes command from RAM
 *
 *  Blocking function that programs a set of data, along with the 8 ECC bits
 *  which correspond to the data at the given address. This API assumes that
 *  hardware generation of the ECC code HAS been disabled, and so the user
 *  must provide the ECC code to program.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  dataSize      The number of 32-bit words to program. Value
 *                            should be an even number, to ensure data is
 *                            programmed 64-bits at a time.
 *  @param[in]  data          Pointer to the data source to program into flash
 *  @param[in]  eccCode       Pointer to ECC code to program corresponding to data
 *  @param[in]  regionSelect  The region of memory to erase. One of
 *                            @ref DL_FLASHCTL_REGION_SELECT
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     false   Program didn't succeed, or invalid dataSize
 *  @retval     true    Program was successful
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
DL_FLASHCTL_COMMAND_STATUS
DL_FlashCTL_programMemoryBlockingFromRAM64WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode, uint32_t dataSize,
    DL_FLASHCTL_REGION_SELECT regionSelect);

/**
 *  @brief      Programs provided data to unprotected memory at a given address
 *
 *  Blocking function that programs a set of data. Data will be programmed as
 *  flash words (64-bits). If dataSize is an odd number, then the last word
 *  will be programmed as 32-bit data.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  dataSize      The number of 32-bit words to program
 *  @param[in]  data          Pointer to the data source to program into flash
 *  @param[in]  regionSelect  The region of memory to erase. One of
 *                            @ref DL_FLASHCTL_REGION_SELECT
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     false   Program didn't succeed
 *  @retval     true    Program was successful
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
bool DL_FlashCTL_programMemoryBlocking(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint32_t dataSize,
    DL_FLASHCTL_REGION_SELECT regionSelect);

/**
 *  @brief      Programs provided data to unprotected memory at a given
 *              address, and executes command from RAM
 *
 *  Blocking function that programs a set of data. Data will be programmed as
 *  flash words (64-bits). If dataSize is an odd number, then the last word
 *  will be programmed as 32-bit data.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  dataSize      The number of 32-bit words to program
 *  @param[in]  data          Pointer to the data source to program into flash
 *  @param[in]  regionSelect  The region of memory to erase. One of
 *                            @ref DL_FLASHCTL_REGION_SELECT
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     false   Program didn't succeed
 *  @retval     true    Program was successful
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect);

/**
 *  @brief      Unprotects all main memory from erase/program
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
void DL_FlashCTL_unprotectMainMemory(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Unprotects all data memory from erase/program
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
void DL_FlashCTL_unprotectDataMemory(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Protects all main memory from erase/program
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
void DL_FlashCTL_protectMainMemory(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Unprotects all non-main memory from erase/program
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
void DL_FlashCTL_unprotectNonMainMemory(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Protects all non-main memory from erase/program
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
void DL_FlashCTL_protectNonMainMemory(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Unprotects all user memory from erase/program
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
void DL_FlashCTL_unprotectAllMemory(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Protects all user memory from erase/program
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 */
void DL_FlashCTL_protectAllMemory(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Sets a given sector to unprotected from erase/program
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  addr          Address of sector to unprotect
 *  @param[in]  regionSelect  The region of memory to unprotect. One of
 *                            @ref DL_FLASHCTL_REGION_SELECT
 */
void DL_FlashCTL_unprotectSector(FLASHCTL_Regs *flashctl, uint32_t addr,
    DL_FLASHCTL_REGION_SELECT regionSelect);

/**
 *  @brief      Sets a given sector to protected from erase/program
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  addr          Address of sector to protect
 *  @param[in]  regionSelect  The region of memory to protect. One of
 *                            @ref DL_FLASHCTL_REGION_SELECT
 */
void DL_FlashCTL_protectSector(FLASHCTL_Regs *flashctl, uint32_t addr,
    DL_FLASHCTL_REGION_SELECT regionSelect);

/**
 *  @brief      Verifies 8-bit data in specified address
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 */
void DL_FlashCTL_readVerify8(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data);

/**
 *  @brief      Verifies 8-bit data in specified address, and executes command
 *              from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM8(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data);

/**
 *  @brief      Verifies 16-bit data in specified address
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 */
void DL_FlashCTL_readVerify16(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data);

/**
 *  @brief      Verifies 16-bit data in specified address, and executes command
 *              from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM16(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data);

/**
 *  @brief      Verifies 32-bit data in specified address
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 */
void DL_FlashCTL_readVerify32(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Verifies 32-bit data in specified address, and executes command
 *              from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM32(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Verifies 64-bit data in specified address
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify.
 *  @param[in]  data        Pointer to the data source to verify
 */
void DL_FlashCTL_readVerify64(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Verifies 64-bit data in specified address, and executes command
 *              from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify.
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM64(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Verifies 8-bit data in specified address with hardware
 *              generated ECC code
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code has NOT
 * been disabled, and so the flash controller will generate the ECC bits.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_readVerify8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data);

/**
 *  @brief      Verifies 8-bit data in specified address with hardware generated
 *              ECC code, and executes command from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code has NOT
 * been disabled, and so the flash controller will generate the ECC bits.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data);

/**
 *  @brief      Verifies 16-bit data in specified address with hardware
 *              generated ECC code
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code has NOT
 * been disabled, and so the flash controller will generate the ECC bits.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_readVerify16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data);

/**
 *  @brief      Verifies 16-bit data in specified address with hardware
 *              generated ECC code, and executes command from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code has NOT
 * been disabled, and so the flash controller will generate the ECC bits.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data);

/**
 *  @brief      Verifies 32-bit data in specified address with hardware
 *              generated ECC code
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code has NOT
 * been disabled, and so the flash controller will generate the ECC bits.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_readVerify32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Verifies 32-bit data in specified address with hardware
 *              generated ECC code, and executes command from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code has NOT
 * been disabled, and so the flash controller will generate the ECC bits.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Verifies 64-bit data in specified address with hardware
 *              generated ECC code
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code has NOT
 * been disabled, and so the flash controller will generate the ECC bits.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_readVerify64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Verifies 32-bit data in specified address with hardware
 *              generated ECC code, and executes command from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code has NOT
 * been disabled, and so the flash controller will generate the ECC bits.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Verifies 8-bit data in specified address with user provided ECC
 *              code
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code HAS been
 * disabled, so the user must provide the ECC code to program.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *  @param[in]  eccCode     Pointer to ECC code to program corresponding to data
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_readVerify8WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint8_t *data, uint8_t *eccCode);

/**
 *  @brief      Verifies 8-bit data in specified address with user provided ECC
 *              code, and executes command from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code HAS been
 * disabled, so the user must provide the ECC code to program.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *  @param[in]  eccCode     Pointer to ECC code to program corresponding to data
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM8WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data,
    uint8_t *eccCode);

/**
 *  @brief      Verifies 16-bit data in specified address with user provided ECC
 *              code
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code HAS been
 * disabled, so the user must provide the ECC code to program.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *  @param[in]  eccCode     Pointer to ECC code to program corresponding to data
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_readVerify16WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint16_t *data, uint8_t *eccCode);

/**
 *  @brief      Verifies 16-bit data in specified address with user provided ECC
 *              code, and executes command from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code HAS been
 * disabled, so the user must provide the ECC code to program.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *  @param[in]  eccCode     Pointer to ECC code to program corresponding to data
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM16WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data,
    uint8_t *eccCode);

/**
 *  @brief      Verifies 32-bit data in specified address with user provided ECC
 *              code
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code HAS been
 * disabled, so the user must provide the ECC code to program.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *  @param[in]  eccCode     Pointer to ECC code to program corresponding to data
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_readVerify32WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode);

/**
 *  @brief      Verifies 32-bit data in specified address with user provided ECC
 *              code, and executes command from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code HAS been
 * disabled, so the user must provide the ECC code to program.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *  @param[in]  eccCode     Pointer to ECC code to program corresponding to data
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM32WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode);

/**
 *  @brief      Verifies 64-bit data in specified address with user provided ECC
 *              code
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code HAS been
 * disabled, so the user must provide the ECC code to program.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *  @param[in]  eccCode     Pointer to ECC code to program corresponding to data
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_readVerify64WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode);

/**
 *  @brief      Verifies 64-bit data in specified address with user provided ECC
 *              code, and executes command from RAM
 *
 * The READVERIFY command may be used to read a flash location and compare it
 * to data to be verified along with the 8 ECC bits which correspond to the
 * data. This API assumes that hardware generation of the ECC code HAS been
 * disabled, so the user must provide the ECC code to program.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *  @param[in]  data        Pointer to the data source to verify
 *  @param[in]  eccCode     Pointer to ECC code to program corresponding to data
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM64WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode);

/**
 *  @brief      Verifies that a flash word is blank
 *
 * A blank flash word is defined as a flash word which has been successfully
 * erased with the ERASE command and not yet programmed away from that
 * non-erased state with the PROGRAM command. The BLANKVERIFY command may be
 * used to test if a flash word is in a blank state, indicating it has not yet
 * been programmed away from an erased state. The BLANKVERIFY command may only
 * be applied to a single flash word at a time.
 *
 * @post        This API just starts the command process. Check if the command
 *              completed execution using an interrupt or the
 *              @ref DL_FlashCTL_waitForCmdDone API.
 * @post        @ref DL_FlashCTL_getFailureStatus should be called to determine
 *              the result of the BLANKVERIFY command. The
 *              @ref DL_FlashCTL_getFailureStatus API will return
 *              @ref DL_FLASHCTL_FAIL_TYPE_VERIFY_ERROR if the flash location has
 *              not been erased, and return @ref DL_FLASHCTL_FAIL_TYPE_NO_FAILURE
 *              if the flash location is blank.
 *
 *  NOTE: After this command is executed, the flash controller will
 *  configure all memory to a protected state.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify

 */
void DL_FlashCTL_blankVerify(FLASHCTL_Regs *flashctl, uint32_t address);

/**
 *  @brief      Verifies that a flash word is blank, and executes command from
 *              RAM
 *
 * A blank flash word is defined as a flash word which has been successfully
 * erased with the ERASE command and not yet programmed away from that
 * non-erased state with the PROGRAM command. The BLANKVERIFY command may be
 * used to test if a flash word is in a blank state, indicating it has not yet
 * been programmed away from an erased state. The BLANKVERIFY command may only
 * be applied to a single flash word at a time.
 *
 * The command is executed from RAM, and blocks until the command is finished.
 *
 * @post        This API just starts the command process. Check if the command
 *              completed execution using an interrupt or the
 *              @ref DL_FlashCTL_waitForCmdDone API.
 * @post        @ref DL_FlashCTL_getFailureStatus should be called to determine
 *              the result of the BLANKVERIFY command. The
 *              @ref DL_FlashCTL_getFailureStatus API will return
 *              @ref DL_FLASHCTL_FAIL_TYPE_VERIFY_ERROR if the flash location has
 *              not been erased, and return @ref DL_FLASHCTL_FAIL_TYPE_NO_FAILURE
 *              if the flash location is blank.
 *
 *  NOTE: After this command is executed, the flash controller will
 *  configure all memory to a protected state.
 *
 *  @param[in]  flashctl    Pointer to the register overlay for the peripheral
 *  @param[in]  address     Memory address of flash to verify
 *
 *  @return     Whether or not the command was successful
 *
 *  @retval     false if command didn't succeed
 *  @retval     true  if command was successful
 *
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_blankVerifyFromRAM(
    FLASHCTL_Regs *flashctl, uint32_t address);

/**
 *  @brief      Programs 128 bit data to unprotected memory at the given address
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
void DL_FlashCTL_programMemory128(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Programs 128 bit data with hardware generated ECC code
 *
 *  Programs 128 bit data, along with the 16 ECC bits which correspond to the
 *  128-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_programMemory128WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Programs 128 bit data with hardware generated ECC code
 *
 *  Programs 128 bit data, along with the 16 ECC bits which correspond to the
 *  128-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code has NOT been disabled,
 *  and so the flash controller will generate the ECC bits.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_programMemory128WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data);

/**
 *  @brief      Programs 128 bit data with user provided ECC code
 *
 *  Programs 128 bit data, along with the 16 ECC bits which correspond to the
 *  128-bit data word, to unprotected memory at the given address. This API
 *  assumes that hardware generation of the ECC code HAS been disabled,
 *  and so the user must provide the ECC code to program.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  data       Pointer to the 32-bit source data
 *  @param[in]  eccCode    Pointer to the ECC code to program
 *
 *  @pre         User must call @ref DL_FlashCTL_enableOverrideHardwareGeneratedECC
 *               to disable hardware generation of the ECC code, so the ECC code
 *               can be manually provided for programming. This override setting
 *               will persist through multiple programs, until
 *               @ref DL_FlashCTL_disableOverrideHardwareGeneratedECC is called
 *  @pre         Before programming memory, the user must unprotect the region
 *               of memory to program. Refer to @ref DL_FlashCTL_unprotectSector
 *  @post        This API just starts the program process. Check the result of it
 *               using an interrupt or the @ref DL_FlashCTL_waitForCmdDone API
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: After completion of a program operation, the flash controller will
 *  disable programming of the ECC code (regardless of whether ECC code is
 *  hardware generated or manually provided).
 */
void DL_FlashCTL_programMemory128WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode);

/**
 *  @brief      Programs provided data up to 128-bits with ECC generated
 *              while blocking between writes
 *
 *  Blocking function that programs a set of data using multi-word programming
 *  for up to 2 flash words. Refer to the device datasheet if the device
 *  supports multi-word programming.
 *  When possible, the data will be programmed as either 64-bit data or as
 *  32-bit data.
 *
 *  @param[in]  flashctl   Pointer to the register overlay for the peripheral
 *  @param[in]  address    Destination memory address to program data. The
 *                         address must be flash word (64-bit) aligned i.e.
 *                         aligned to a 0b000 boundary.
 *  @param[in]  dataSize      The number of 32-bit words to program
 *  @param[in]  data          Pointer to the data source to program into flash
 *  @param[in]  regionSelect  The region of memory to erase. One of
 *                            @ref DL_FLASHCTL_REGION_SELECT
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     false   Program didn't succeed
 *  @retval     true    Program was successful
 *
 *  NOTE: After completion of a program operation, the flash controller will
 *  configure all memory to a protected state.
 *  NOTE: This API does not enable programming the ECC code.
 */
bool DL_FlashCTL_programMemoryBlocking128WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect);

/**
 *  @brief      Performs an erase on DATA bank
 *
 *  Performs an erase on DATA bank only. This API should be used
 *  on devices with a DATA bank. To determine if device has DATA
 *  bank use @ref DL_FactoryRegion_getDATAFlashSize API.
 *
 *  NOTE: This API erases all of DATA bank
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     Whether or not the erase succeeded
 *
 *  @retval     false If erase didn't succeed
 *  @retval     true  If erase was successful
 *
 */
bool DL_FlashCTL_eraseDataBank(FLASHCTL_Regs *flashctl);

/**
 *  @brief      Performs an erase on DATA bank, and executes command
 *              from RAM
 *
 *  Performs an erase on DATA bank only. This API should be used
 *  on devices with a DATA bank. To determine if device has DATA
 *  bank use @ref DL_FactoryRegion_getDATAFlashSize API.
 *
 *  The command is executed from RAM, and blocks until the command is finished.
 *
 *  NOTE: This API erases all of DATA bank
 *
 *  @param[in]  flashctl  Pointer to the register overlay for the peripheral
 *
 *  @return     Whether or not the erase succeeded
 *
 *  @retval     DL_FLASHCTL_COMMAND_STATUS_FAILED If erase didn't succeed
 *  @retval     DL_FLASHCTL_COMMAND_STATUS_PASSED If erase was successful
 *
 */
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_eraseDataBankFromRAM(
    FLASHCTL_Regs *flashctl);

#ifdef __cplusplus
}
#endif

#endif /* ti_dl_dl_flashctl__include */
/** @}*/
