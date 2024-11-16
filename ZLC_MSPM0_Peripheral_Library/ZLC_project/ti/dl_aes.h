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
 *  @file       dl_aes.h
 *  @brief      Advanced Encryption Standard (AES) Driver Library
 *  @defgroup   AES Advanced Encryption Standard (AES)
 *
 *  @anchor ti_dl_dl_aes_Overview
 *  # Overview
 *
 *  The AES DriverLib allows full configuration of the MSPM0 AES module.
 *  The AES accelerator module accelerates encryption and decryption operations in hardware based
 *  on the FIPS PUB 197 advanced encryption standard (AES).
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup AES
 * @{
 */
#ifndef ti_dl_dl_aes__include
#define ti_dl_dl_aes__include

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_AES__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/*!
 * @brief AES Ready interrupt
 */
#define DL_AES_INTERRUPT_AES_READY            (AES_CPU_INT_IMASK_AESRDY_MASK)

/*!
 * @brief DMA Trigger Event 0
 */
#define DL_AES_EVENT_AES_DMA_TRIGGER0           (AES_DMA_TRIG0_IMASK_DMA0_MASK)

/*!
 * @brief DMA Trigger Event 1
 */
#define DL_AES_EVENT_AES_DMA_TRIGGER1            (AES_DMA_TRIG1_IMASK_DMA1_SET)

/*!
 * @brief DMA Trigger Event 2
 */
#define DL_AES_EVENT_AES_DMA_TRIGGER2            (AES_DMA_TRIG2_IMASK_DMA2_SET)

/* clang-format on */

/*! @enum DL_AES_MODE */
typedef enum {
    /*! @brief Selects encryption using Electronic Code Book (ECB) mode. */
    DL_AES_MODE_ENCRYPT_ECB_MODE =
        (AES_AESACTL0_OPX_OP0 | AES_AESACTL0_CMX_ECB),

    /*! @brief Selects encryption using Cipher Block Chaining (CBC) mode. */
    DL_AES_MODE_ENCRYPT_CBC_MODE =
        (AES_AESACTL0_OPX_OP0 | AES_AESACTL0_CMX_CBC),

    /*! @brief Selects encryption using Output Feedback (OFB) mode. */
    DL_AES_MODE_ENCRYPT_OFB_MODE =
        (AES_AESACTL0_OPX_OP0 | AES_AESACTL0_CMX_OFB),

    /*! @brief Selects encryption using Cipher Feedback (CFB) mode. */
    DL_AES_MODE_ENCRYPT_CFB_MODE =
        (AES_AESACTL0_OPX_OP0 | AES_AESACTL0_CMX_CFB),

    /*! @brief Selects decryption using Electronic Code Book (ECB) mode. */
    DL_AES_MODE_DECRYPT_SAME_KEY_ECB_MODE =
        (AES_AESACTL0_OPX_OP1 | AES_AESACTL0_CMX_ECB),

    /*! @brief Selects decryption using Cipher Block Chaining (CBC) mode. */
    DL_AES_MODE_DECRYPT_SAME_KEY_CBC_MODE =
        (AES_AESACTL0_OPX_OP1 | AES_AESACTL0_CMX_CBC),

    /*! @brief Selects decryption using Output Feedback (OFB) mode. */
    DL_AES_MODE_DECRYPT_SAME_KEY_OFB_MODE =
        (AES_AESACTL0_OPX_OP1 | AES_AESACTL0_CMX_OFB),

    /*! @brief Selects decryption using Cipher Feedback (CFB) mode. */
    DL_AES_MODE_DECRYPT_SAME_KEY_CFB_MODE =
        (AES_AESACTL0_OPX_OP1 | AES_AESACTL0_CMX_CFB),

    /*! @brief Selects first round key for Electronic Code Book (ECB) mode. */
    DL_AES_MODE_GEN_FIRST_ROUND_KEY_ECB_MODE =
        (AES_AESACTL0_OPX_OP2 | AES_AESACTL0_CMX_ECB),

    /*! @brief Selects first round key using Cipher Block Chaining (CBC) mode. */
    DL_AES_MODE_GEN_FIRST_ROUND_KEY_CBC_MODE =
        (AES_AESACTL0_OPX_OP2 | AES_AESACTL0_CMX_CBC),

    /*! @brief Selects first round key using Output Feedback (OFB) mode. */
    DL_AES_MODE_GEN_FIRST_ROUND_KEY_OFB_MODE =
        (AES_AESACTL0_OPX_OP2 | AES_AESACTL0_CMX_OFB),

    /*! @brief Selects first round key using Cipher Feedback (CFB) mode. */
    DL_AES_MODE_GEN_FIRST_ROUND_KEY_CFB_MODE =
        (AES_AESACTL0_OPX_OP2 | AES_AESACTL0_CMX_CFB),

    /*! @brief Selects decryption with 1st round key using ECB mode. */
    DL_AES_MODE_DECRYPT_KEY_IS_FIRST_ROUND_KEY_ECB_MODE =
        (AES_AESACTL0_OPX_OP3 | AES_AESACTL0_CMX_ECB),

    /*! @brief Selects decryption with 1st round key using CBC mode. */
    DL_AES_MODE_DECRYPT_KEY_IS_FIRST_ROUND_KEY_CBC_MODE =
        (AES_AESACTL0_OPX_OP3 | AES_AESACTL0_CMX_CBC),

    /*! @brief Selects decryption with 1st round key using OFB mode. */
    DL_AES_MODE_DECRYPT_KEY_IS_FIRST_ROUND_KEY_OFB_MODE =
        (AES_AESACTL0_OPX_OP3 | AES_AESACTL0_CMX_OFB),

    /*! @brief Selects decryption with 1st round key using CFB mode. */
    DL_AES_MODE_DECRYPT_KEY_IS_FIRST_ROUND_KEY_CFB_MODE =
        (AES_AESACTL0_OPX_OP3 | AES_AESACTL0_CMX_CFB),
} DL_AES_MODE;

/*! @enum DL_AES_IIDX */
typedef enum {
    /*! AES interrupt index for AES module ready */
    DL_AES_IIDX_AES_READY = AES_CPU_INT_IIDX_STAT_AESRDY,
    /*! AES interrupt index for enabling DMA trigger event 0 */
    DL_AES_IIDX_AES_DMA_TRIGGER0 = AES_DMA_TRIG0_IIDX_STAT_DMA0,
    /*! AES interrupt index for enabling DMA trigger event 1 */
    DL_AES_IIDX_AES_DMA_TRIGGER1 = AES_DMA_TRIG1_IIDX_STAT_DMA1,
    /*! AES interrupt index for enabling DMA trigger event 2 */
    DL_AES_IIDX_AES_DMA_TRIGGER2 = AES_DMA_TRIG2_IIDX_STAT_DMA2
} DL_AES_IIDX;

/*! @enum DL_AES_OPERATION */
typedef enum {
    /*! Encryption mode selected  */
    DL_AES_OPERATION_ENC = AES_AESACTL0_OPX_OP0,
    /*! Decryption. The provided key is the same key used for encryption.  */
    DL_AES_OPERATION_DEC_SAME_KEY = AES_AESACTL0_OPX_OP1,
    /*! Generate first round key required for decryption.  */
    DL_AES_OPERATION_GEN_FIRST_ROUND = AES_AESACTL0_OPX_OP2,
    /*! Decryption. The provided key is the first round key required for
     *  decryption  */
    DL_AES_OPERATION_DEC_KEY_IS_FIRST_ROUND = AES_AESACTL0_OPX_OP3,
} DL_AES_OPERATION;

/*! @enum DL_AES_KEY_LENGTH */
typedef enum {
    /*! Key length set to 128 */
    DL_AES_KEY_LENGTH_128 = AES_AESACTL0_KLX_AES128,
    /*! Key length set to 256  */
    DL_AES_KEY_LENGTH_256 = AES_AESACTL0_KLX_AES256,
} DL_AES_KEY_LENGTH;

/*! @enum DL_AES_STATUS */
typedef enum {
    /*! Operation was successful */
    DL_AES_STATUS_SUCCESS,
    /*! Operation was not performed because address was unaligned */
    DL_AES_STATUS_UNALIGNED_ACCESS,
} DL_AES_STATUS;

/**
 * @brief Configuration structure to backup AES peripheral state before going
 *        to STOP/STANDBY mode. Used by @ref DL_AES_saveConfiguration
 */
typedef struct {
    /*! Combination of AESACTL0 fields, compressed to a single word as they
     *  are stored in the AES registers. See @ref DL_AES_init for
     *  how the peripheral control word 0 is created */
    uint32_t controlWord0;
    /*! Combination of AESACTL1 fields, compressed to a single word as they
     *  are stored in the AES registers. See @ref DL_AES_init for
     *  how the peripheral control word 1 is created */
    uint32_t controlWord1;
    /*! AES interrupt mask 0. Value of @ref DL_AES_INTERRUPT_AES_READY stored
     * from the current state of the AES Interrupt Event 0 register set */
    uint32_t interruptMask0;
    /*! AES interrupt mask 1. Value of @ref DL_AES_EVENT_AES_DMA_TRIGGER0 stored
     *  from the current state of the AES Interrupt Event 1 register set */
    uint32_t interruptMask1;
    /*! AES interrupt mask 2. Value of @ref DL_AES_EVENT_AES_DMA_TRIGGER1 stored
     * from the current state of the AES Interrupt Event 2 register set */
    uint32_t interruptMask2;
    /*! AES interrupt mask 3. Value of @ref DL_AES_EVENT_AES_DMA_TRIGGER2 stored
     * from the current state of the AES Interrupt Event 3 register set */
    uint32_t interruptMask3;
    /*! Boolean flag indicating whether or not a valid configuration structure
       exists. Should not be modified by the user. */
    bool backupRdy;
} DL_AES_backupConfig;

/**
 * @brief Enables power on AES module
 *
 * @param aes        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_AES_enablePower(AES_Regs *aes)
{
    aes->GPRCM.PWREN = (AES_PWREN_KEY_UNLOCK_W | AES_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Disables power on AES module
 *
 * @param aes        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_AES_disablePower(AES_Regs *aes)
{
    aes->GPRCM.PWREN = (AES_PWREN_KEY_UNLOCK_W | AES_PWREN_ENABLE_DISABLE);
}

/**
 * @brief Returns if power enabled on AES module
 *
 * @param aes        Pointer to the register overlay for the peripheral
 *
 * @return true if power is enabled
 * @return false if power is disabled
 */
__STATIC_INLINE bool DL_AES_isPowerEnabled(AES_Regs *aes)
{
    return (
        (aes->GPRCM.PWREN & AES_PWREN_ENABLE_MASK) == AES_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Resets AES peripheral
 *
 * @param aes        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_AES_reset(AES_Regs *aes)
{
    aes->GPRCM.RSTCTL =
        (AES_RSTCTL_KEY_UNLOCK_W | AES_RSTCTL_RESETSTKYCLR_CLR |
            AES_RSTCTL_RESETASSERT_ASSERT);
}

/**
 * @brief Returns if AES peripheral was reset
 *
 * @param aes        Pointer to the register overlay for the peripheral
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_AES_isReset(AES_Regs *aes)
{
    return ((aes->GPRCM.STAT & AES_STAT_RESETSTKY_MASK) ==
            AES_STAT_RESETSTKY_RESET);
}

/**
 *  @brief  Initializes AES peripheral
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *
 *  @param[in] aesConfig     Configures AES cipher mode, key length and
 *                           operation configuration. One of @ref DL_AES_MODE
 *  @param[in] keyLength     Configures AES key length. One of
 *                           @ref DL_AES_KEY_LENGTH
 */

__STATIC_INLINE void DL_AES_init(
    AES_Regs *aes, DL_AES_MODE aesConfig, DL_AES_KEY_LENGTH keyLength)
{
    DL_Common_updateReg(&aes->AESACTL0,
        ((uint32_t) aesConfig | (uint32_t) keyLength),
        (uint32_t)(AES_AESACTL0_OPX_MASK | AES_AESACTL0_CMX_MASK |
                   AES_AESACTL0_KLX_MASK));
}

/**
 *  @brief Immediately resets the complete AES accelerator module even when
 *         busy.
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *
 */

__STATIC_INLINE void DL_AES_softwareReset(AES_Regs *aes)
{
    aes->AESACTL0 |= (AES_AESACTL0_SWRST_RST);
}

/**
 *  @brief Returns status of AES error flag
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *
 *  @return Status of AES module fault flag
 *
 *  @retval true flag is set
 *  @retval false flag is cleared
 */
__STATIC_INLINE bool DL_AES_isFaultFlagSet(AES_Regs *aes)
{
    return (
        (aes->AESACTL0 & AES_AESACTL0_ERRFG_MASK) == AES_AESACTL0_ERRFG_ERR);
}

/**
 *  @brief Clears AES error flag
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *
 */
__STATIC_INLINE void DL_AES_clearFaultFlag(AES_Regs *aes)
{
    aes->AESACTL0 &= ~(AES_AESACTL0_ERRFG_ERR);
}

/**
 *  @brief Enables cipher mode
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *
 */
__STATIC_INLINE void DL_AES_enableCipherMode(AES_Regs *aes)
{
    aes->AESACTL0 |= (AES_AESACTL0_CMEN_ENABLE);
}

/**
 *  @brief Disables cipher mode
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *
 */
__STATIC_INLINE void DL_AES_disablesCipherMode(AES_Regs *aes)
{
    aes->AESACTL0 &= ~(AES_AESACTL0_CMEN_ENABLE);
}

/**
 * @brief Set cipher block counter value
 *
 * Sets the number of blocks to be encrypted or decrypted, the block counter
 * decrements with each performed encryption or decryption.
 * Block cipher mode must be enabled with @ref DL_AES_enableCipherMode. If block
 * cipher mode is disabled, writes to this register are ignored.
 * If this register has a value > 0 and block cipher mode has been enabled,
 * further writes to this register are ignored until the value of this register
 * is 0.
 *
 * @param       aes      Pointer to the register overlay for the peripheral
 *
 *  @param[in]  count    The value to set the cipher block counter to.
 *                       Value between [0x0, 0xFF]
 *
 * @sa          DL_AES_enableCipherMode
 */
__STATIC_INLINE void DL_AES_setCipherBlockCounter(
    AES_Regs *aes, uint32_t count)
{
    DL_Common_updateReg(&aes->AESACTL1, count, AES_AESACTL1_BLKCNTX_MASK);
}

/**
 * @brief Get current cipher block counter value
 *
 * The block counter decrements with each performed encryption or decryption.
 *
 * @param aes        Pointer to the register overlay for the peripheral
 *
 * @return           The current cipher block counter value
 *
 * @retval           Value between [0x0, 0xFF]
 */
__STATIC_INLINE uint32_t DL_AES_getCipherBlockCounter(AES_Regs *aes)
{
    return (aes->AESACTL1 & AES_AESACTL1_BLKCNTX_MASK);
}

/**
 *
 * @brief Gets the AES module busy status.
 *
 * @param[in] aes           Pointer to the register overlay for the
 *                          peripheral
 * @return Status of AES module
 *
 * @retval true. Module is busy
 * @retval false. Module is in idle state
 *
 */
__STATIC_INLINE bool DL_AES_isBusy(AES_Regs *aes)
{
    return (
        (aes->AESASTAT & AES_AESASTAT_BUSY_MASK) == AES_AESASTAT_BUSY_BUSY);
}

/**
 *
 * @brief Gets the DATAOUT read status
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 * @return Status of DATAOUT read status
 *
 * @retval true. All bytes read
 * @retval false. Not all bytes read
 *
 */
__STATIC_INLINE bool DL_AES_getDataOutReadStatus(AES_Regs *aes)
{
    return (
        (aes->AESASTAT & AES_AESASTAT_DOUTRD_MASK) == AES_AESASTAT_DOUTRD_ALL);
}

/**
 *
 * @brief Gets Key byte count
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *
 * @return Number of Key bytes loaded
 *
 */
__STATIC_INLINE uint8_t DL_AES_getKeyBytesCount(AES_Regs *aes)
{
    return ((uint8_t)((aes->AESASTAT & AES_AESASTAT_KEYCNTX_MAXNUM) >> 4));
}

/**
 *
 * @brief Gets Data In byte count
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *
 * @return Number of Data In bytes loaded
 *
 */
__STATIC_INLINE uint8_t DL_AES_getDataInBytesCount(AES_Regs *aes)
{
    return ((uint8_t)((aes->AESASTAT & AES_AESASTAT_DINCNTX_MAXNUM) >> 8));
}

/**
 *
 * @brief Gets Data Out byte count
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *
 * @return Number of Data Out bytes loaded
 *
 */
__STATIC_INLINE uint8_t DL_AES_getDataOutBytesCount(AES_Regs *aes)
{
    return ((uint8_t)((aes->AESASTAT & AES_AESASTAT_DOUTCNTX_MAXNUM) >> 12));
}

/**
 *
 * @brief Set bit to write all STATE bytes to STATE registers
 *        and triggers a new encryption
 *
 * @param[in] aes            Pointer to the register overlay for the
 *                           peripheral
 *
 */
__STATIC_INLINE void DL_AES_setAllDataWritten(AES_Regs *aes)
{
    aes->AESASTAT |= AES_AESASTAT_DINWR_ALL;
}

/**
 *
 * @brief Set bit to write all KEY bytes to KEY register,
 *        which is used to encrypt and decrypt data
 *
 * @param[in] aes            Pointer to the register overlay for the
 *                           peripheral
 *
 */
__STATIC_INLINE void DL_AES_setAllKeyWritten(AES_Regs *aes)
{
    aes->AESASTAT |= AES_AESASTAT_KEYWR_ALL;
}

/**
 *
 * @brief Check if all bytes are to be written to
 *        registers containing STATE info
 *
 * @param[in] aes            Pointer to the register overlay for the
 *                           peripheral
 *
 * @retval true All bytes are written to these registers
 * @retval false Not all bytes are written to these registers
 *
 */
__STATIC_INLINE bool DL_AES_isAllDataWritten(AES_Regs *aes)
{
    return (aes->AESASTAT & AES_AESASTAT_DINWR_MASK) == AES_AESASTAT_DINWR_ALL;
}

/**
 *
 * @brief Check if all bytes are to be written to
 *        registers containing KEY info
 *
 * @param[in] aes            Pointer to the register overlay for the
 *                           peripheral
 *
 * @retval true All bytes are written to these registers
 * @retval false Not all bytes are written to these registers
 */
__STATIC_INLINE bool DL_AES_isAllKeysWritten(AES_Regs *aes)
{
    return (aes->AESASTAT & AES_AESASTAT_KEYWR_MASK) == AES_AESASTAT_KEYWR_ALL;
}

/**
 *
 *  @brief Loads a 128 or 256 bit key to AES module.
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *
 *  @param[in] key           Pointer to an aligned uint8_t array that contains
 *                           the cipher key.
 *
 *  @param[in] keyLength     length of the key. One of @ref DL_AES_KEY_LENGTH
 *
 *  @return Status of operation. Operation will fail if not 32-bit aligned. One
 *          of @ref DL_AES_STATUS.
 *
 *  @note This function adds additional cycles in order to verify no unaligned
 *        access, if this is not necessary, consider using uint32_t pointers and
 *        @ref DL_AES_setKeyAligned
 *
 */
DL_AES_STATUS DL_AES_setKey(
    AES_Regs *aes, const uint8_t *key, DL_AES_KEY_LENGTH keyLength);

/**
 *
 *  @brief Loads a 128 or 256 bit key to AES module.
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *
 *  @param[in] keyAligned    Pointer to an uint32_t array that contains the
 *                           cipher key.
 *
 *  @param[in] keyLength     length of the key. One of @ref DL_AES_KEY_LENGTH
 *
 *  @sa DL_AES_setKey
 *
 */
void DL_AES_setKeyAligned(
    AES_Regs *aes, const uint32_t *keyAligned, DL_AES_KEY_LENGTH keyLength);

/**
 *
 *  @brief XORs an AES 128-bit block of data in software
 *
 *  @param[in] data           Pointer to initial data block for the operation
 *  @param[in] xorData        Pointer to 128-bit data block to xor with data
 *  @param[out] xorOutputData Pointer to output block of data ^ xorData
 *
 *  @return Status of operation. Operation will fail if not 32-bit aligned. One
 *          of @ref DL_AES_STATUS.
 *
 *  @note This function adds additional cycles in order to verify no unaligned
 *        access, if this is not necessary, consider using uint32_t pointers and
 *        @ref DL_AES_xorDataAligned
 *
 */
DL_AES_STATUS DL_AES_xorData(
    uint8_t *data, uint8_t *xorData, uint8_t *xorOutputData);

/**
 *
 *  @brief XORs an aligned 128-bit data block in software
 *
 *  @param[in] dataAligned           Pointer to initial data block for the
 *                                   operation
 *  @param[in] xorDataAligned        Pointer to 128-bit data block to xor with
 *                                   data
 *  @param[out] xorOutputDataAligned Pointer to output block of data ^ xorData
 *
 *  @sa DL_AES_xorData
 */
void DL_AES_xorDataAligned(uint32_t *dataAligned, uint32_t *xorDataAligned,
    uint32_t *xorOutputDataAligned);

/**
 *
 *  @brief Encrypts a block of data using the AES module.
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *  @param[in] data          Is a pointer to an aligned uint8_t array with a
 *                           length of 16 that contains data to be encrypted.
 *
 *  @return Status of operation. Operation will fail if not 32-bit aligned. One
 *          of @ref DL_AES_STATUS.
 *
 *  @note This function adds additional cycles in order to verify no unaligned
 *        access, if this is not necessary, consider using uint32_t pointers and
 *        @ref DL_AES_loadDataInAligned
 */
DL_AES_STATUS DL_AES_loadDataIn(AES_Regs *aes, const uint8_t *data);

/**
 *
 *  @brief Encrypts a block of data using the AES module.
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *  @param[in] dataAligned   Is a pointer to an uint32_t array with a length of
 *                           4 that contains data to be encrypted.
 *
 *  @sa DL_AES_loadDataIn
 *
 */
void DL_AES_loadDataInAligned(AES_Regs *aes, const uint32_t *dataAligned);

/**
 *
 *  @brief Gets output of encrypted data
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *  @param[out] data         Is a pointer to an uint8_t array with a length of
 *                           16 where the output of the AES module will
 *                           be placed.
 *
 *  @return Status of operation. Operation will fail if not 32-bit aligned. One
 *          of @ref DL_AES_STATUS.
 *
 *  @note This function adds additional cycles in order to verify no unaligned
 *        writes, if this is not necessary, consider using uint32_t pointers and
 *        @ref DL_AES_getDataOutAligned
 */
DL_AES_STATUS DL_AES_getDataOut(AES_Regs *aes, uint8_t *data);

/**
 *
 *  @brief Gets output of encrypted data
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *  @param[in] dataAligned   Is a pointer to an uint32_t array with a length of
 *                           4 where the output of the AES module will
 *                           be placed.
 *  @sa DL_AES_getDataOut
 *
 */
void DL_AES_getDataOutAligned(AES_Regs *aes, uint32_t *dataAligned);

/**
 *
 *  @brief Data is XORed with the current word of the state and then block of
 *         data is encrypted. Encryption or decryption is started immediately
 *         after loading data.
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *  @param[in] data          Is a pointer to an aligned uint8_t array with a
 *                           length of 16 that contains data to be encrypted.
 *
 *  @return Status of operation. Operation will fail if not 32-bit aligned. One
 *          of @ref DL_AES_STATUS.
 *
 *  @note This function adds additional cycles in order to verify no unaligned
 *        access, if this is not necessary, consider using uint32_t pointers and
 *        @ref DL_AES_loadXORDataInAligned
 *
 */
DL_AES_STATUS DL_AES_loadXORDataIn(AES_Regs *aes, const uint8_t *data);

/**
 *
 *  @brief Data is XORed with the current word of the state and then block of
 *         data is encrypted. Encryption or decryption is started immediately
 *         after loading data.
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *  @param[in] dataAligned   Is a pointer to an uint32_t array with a length of
 *                           4 that contains data to be encrypted.
 *
 *  @sa DL_AES_loadXORDataIn
 *
 */
void DL_AES_loadXORDataInAligned(AES_Regs *aes, const uint32_t *dataAligned);

/**
 *
 *  @brief Data is XORed with the current word of the state and then block of
 *         data is encrypted. Encryption or decryption is NOT started after
 *         loading data.
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *  @param[in] data          Is a pointer to an aligned uint8_t array with a
 *                           length of 16 that contains data to be encrypted.
 *
 *  @return Status of operation. Operation will fail if not 32-bit aligned. One
 *          of @ref DL_AES_STATUS.
 *
 *  @note This function adds additional cycles in order to verify no unaligned
 *        access, if this is not necessary, consider using uint32_t pointers and
 *        @ref DL_AES_loadXORDataInWithoutTriggerAligned
 *
 */
DL_AES_STATUS DL_AES_loadXORDataInWithoutTrigger(
    AES_Regs *aes, const uint8_t *data);

/**
 *
 *  @brief Data is XORed with the current word of the state and then block of
 *         data is encrypted. Encryption or decryption is NOT started after
 *         loading data.
 *
 *  @param[in] aes           Pointer to the register overlay for the
 *                           peripheral
 *  @param[in] dataAligned   Is a pointer to an uint32_t array with a length of
 *                           4 that contains data to be encrypted.
 *
 *  @sa DL_AES_loadXORDataInWithoutTrigger
 *
 */
void DL_AES_loadXORDataInWithoutTriggerAligned(
    AES_Regs *aes, const uint32_t *dataAligned);

/**
 *  @brief      Enable AES Ready interrupt
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                            peripheral
 */
__STATIC_INLINE void DL_AES_enableInterrupt(AES_Regs *aes)
{
    aes->CPU_INT.IMASK |= DL_AES_INTERRUPT_AES_READY;
}

/**
 *  @brief      Enables DMA trigger 0 to publish AES events to the DMA
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                            peripheral
 */
__STATIC_INLINE void DL_AES_enableDMATrigger0Interrupt(AES_Regs *aes)
{
    aes->DMA_TRIG0.IMASK |= DL_AES_EVENT_AES_DMA_TRIGGER0;
}

/**
 *  @brief      Enables DMA trigger 1 to publish AES events to the DMA
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                            peripheral
 */
__STATIC_INLINE void DL_AES_enableDMATrigger1Interrupt(AES_Regs *aes)
{
    aes->DMA_TRIG1.IMASK |= DL_AES_EVENT_AES_DMA_TRIGGER1;
}

/**
 *  @brief      Enables DMA trigger 2 to publish AES events to the DMA
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                            peripheral
 */
__STATIC_INLINE void DL_AES_enableDMATrigger2Interrupt(AES_Regs *aes)
{
    aes->DMA_TRIG2.IMASK |= DL_AES_EVENT_AES_DMA_TRIGGER2;
}

/**
 *  @brief      Disable AES Ready interrupt
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_AES_disableInterrupt(AES_Regs *aes)
{
    aes->CPU_INT.IMASK &= ~(AES_CPU_INT_IMASK_AESRDY_MASK);
}

/**
 *  @brief      Disable DMA Trigger 0 Event
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_AES_disableDMATrigger0Event(AES_Regs *aes)
{
    aes->DMA_TRIG0.IMASK &= ~(AES_DMA_TRIG0_IMASK_DMA0_MASK);
}

/**
 *  @brief      Disable DMA Trigger 1 Event
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_AES_disableDMATrigger1Event(AES_Regs *aes)
{
    aes->DMA_TRIG1.IMASK &= ~(AES_DMA_TRIG1_IMASK_DMA1_MASK);
}

/**
 *  @brief      Disable DMA Trigger 2 Event
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_AES_disableDMATrigger2Event(AES_Regs *aes)
{
    aes->DMA_TRIG2.IMASK &= ~(AES_DMA_TRIG2_IMASK_DMA2_MASK);
}

/**
 *  @brief      Check if AES Ready interrupt is enabled
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                            peripheral
 *
 *  @return     If AES Ready interrupt is enabled
 *
 *  @retval      DL_AES_INTERRUPT_AES_READY if AES Ready interrupt is enabled
 *  @retval      0 if AES Ready interrupt is not enabled
 */
__STATIC_INLINE uint32_t DL_AES_getEnabledInterrupts(AES_Regs *aes)
{
    return (aes->CPU_INT.IMASK & AES_CPU_INT_IMASK_AESRDY_MASK);
}

/**
 *  @brief      Check if DMA Trigger 0 Event is enabled
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                            peripheral
 *
 *  @return     If DMA Trigger 0 Event is enabled
 *
 *  @retval      DL_AES_EVENT_AES_DMA_TRIGGER0 if DMA Trigger 0 Event is enabled
 *  @retval      0 if DMA Trigger 0 Event is not enabled
 */
__STATIC_INLINE uint32_t DL_AES_getEnabledDMATrigger0Event(AES_Regs *aes)
{
    return (aes->DMA_TRIG0.IMASK & AES_DMA_TRIG0_IMASK_DMA0_MASK);
}

/**
 *  @brief      Check if DMA Trigger 1 Event is enabled
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                            peripheral
 *
 *  @return     If DMA Trigger 1 Event is enabled
 *
 *  @retval      DL_AES_EVENT_AES_DMA_TRIGGER1 if DMA Trigger 1 Event is enabled
 *  @retval      0 if DMA Trigger 1 Event is not enabled
 */
__STATIC_INLINE uint32_t DL_AES_getEnabledDMATrigger1Event(AES_Regs *aes)
{
    return (aes->DMA_TRIG1.IMASK & AES_DMA_TRIG1_IMASK_DMA1_MASK);
}

/**
 *  @brief      Check if DMA Trigger 2 Event is enabled
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                            peripheral
 *
 *  @return     If DMA Trigger 2 Event is enabled
 *
 *  @retval      DL_AES_EVENT_AES_DMA_TRIGGER2 if DMA Trigger 2 Event is enabled
 *  @retval      0 if DMA Trigger 2 Event is not enabled
 */
__STATIC_INLINE uint32_t DL_AES_getEnabledDMATrigger2Event(AES_Regs *aes)
{
    return (aes->DMA_TRIG2.IMASK & AES_DMA_TRIG2_IMASK_DMA2_MASK);
}

/**
 *  @brief      Check interrupt flag of AES Ready interrupt
 *
 *  Checks if AES Ready interrupt that was previously enabled is pending.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     If AES Ready interrupt is pending
 *
 *  @retval      DL_AES_INTERRUPT_AES_READY if AES Ready interrupt is pending
 *  @retval      0 if AES Ready interrupt is not pending
 *
 *  @sa         DL_AES_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_AES_getEnabledInterruptStatus(AES_Regs *aes)
{
    return (aes->CPU_INT.MIS & AES_CPU_INT_IMASK_AESRDY_MASK);
}

/**
 *  @brief      Check interrupt flag of DMA Trigger 0 Event
 *
 *  Checks if DMA Trigger 0 Event that was previously enabled is pending.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     If DMA Trigger 0 Event is pending
 *
 *  @retval      DL_AES_EVENT_AES_DMA_TRIGGER0 if DMA Trigger 0 Event is pending
 *  @retval      0 if DMA Trigger 0 Event is not pending
 *
 *  @sa         DL_AES_enableDMATrigger0Event
 */
__STATIC_INLINE uint32_t DL_AES_getEnabledDMATrigger0EventStatus(AES_Regs *aes)
{
    return (aes->DMA_TRIG0.MIS & AES_DMA_TRIG0_IMASK_DMA0_MASK);
}

/**
 *  @brief      Check interrupt flag of DMA Trigger 1 Event
 *
 *  Checks if DMA Trigger 1 Event that was previously enabled is pending.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     If DMA Trigger 1 Event is pending
 *
 *  @retval      DL_AES_EVENT_AES_DMA_TRIGGER1 if DMA Trigger 1 Event is pending
 *  @retval      0 if DMA Trigger 1 Event is not pending
 *
 *  @sa         DL_AES_enableDMATrigger1Event
 */
__STATIC_INLINE uint32_t DL_AES_getEnabledDMATrigger1EventStatus(AES_Regs *aes)
{
    return (aes->DMA_TRIG1.MIS & AES_DMA_TRIG1_IMASK_DMA1_MASK);
}

/**
 *  @brief      Check interrupt flag of DMA Trigger 2 Event
 *
 *  Checks if DMA Trigger 2 Event that was previously enabled is pending.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     If DMA Trigger 2 Event is pending
 *
 *  @retval      DL_AES_EVENT_AES_DMA_TRIGGER2 if DMA Trigger 2 Event is pending
 *  @retval      0 if DMA Trigger 2 Event is not pending
 *
 *  @sa         DL_AES_enableDMATrigger2Event
 */
__STATIC_INLINE uint32_t DL_AES_getEnabledDMATrigger2EventStatus(AES_Regs *aes)
{
    return (aes->DMA_TRIG2.MIS & AES_DMA_TRIG2_IMASK_DMA2_MASK);
}

/**
 *  @brief      Check interrupt flag of AES Ready interrupt
 *
 *  Checks if AES Ready Interrupt is pending. Interrupt does not have to
 *  be previously enabled.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     If AES Ready interrupt is pending
 *
 *  @retval      DL_AES_EVENT_AES_DMA_TRIGGER0 if AES Ready interrupt is pending
 *  @retval      0 if AES Ready interrupt is not pending
 */
__STATIC_INLINE uint32_t DL_AES_getRawInterruptStatus(AES_Regs *aes)
{
    return (aes->CPU_INT.RIS & AES_CPU_INT_IMASK_AESRDY_MASK);
}

/**
 *  @brief      Check interrupt flag of DMA Trigger 0 Event
 *
 *  Checks if DMA Trigger 0 Event is pending. Event does not have to
 *  be previously enabled.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     If DMA Trigger 0 Event is pending
 *
 *  @retval      DL_AES_EVENT_AES_DMA_TRIGGER0 if DMA Trigger 0 Event is pending
 *  @retval      0 if DMA Trigger 0 Event is not pending
 */
__STATIC_INLINE uint32_t DL_AES_getRawDMATrigger0EventStatus(AES_Regs *aes)
{
    return (aes->DMA_TRIG0.RIS & AES_DMA_TRIG0_IMASK_DMA0_MASK);
}

/**
 *  @brief      Check interrupt flag of DMA Trigger 1 Event
 *
 *  Checks if DMA Trigger 1 Event is pending. Event does not have to
 *  be previously enabled.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     If DMA Trigger 1 Event is pending
 *
 *  @retval      DL_AES_EVENT_AES_DMA_TRIGGER0 if DMA Trigger 1 Event is pending
 *  @retval      0 if DMA Trigger 1 Event is not pending
 */
__STATIC_INLINE uint32_t DL_AES_getRawDMATrigger1EventStatus(AES_Regs *aes)
{
    return (aes->DMA_TRIG1.RIS & AES_DMA_TRIG1_IMASK_DMA1_MASK);
}

/**
 *  @brief      Check interrupt flag of DMA Trigger 2 Event
 *
 *  Checks if DMA Trigger 2 Event is pending. Event does not have to
 *  be previously enabled.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     If DMA Trigger 2 Event is pending
 *
 *  @retval      DL_AES_EVENT_AES_DMA_TRIGGER0 if DMA Trigger 2 Event is pending
 *  @retval      0 if DMA Trigger 2 Event is not pending
 */
__STATIC_INLINE uint32_t DL_AES_getRawDMATrigger2EventStatus(AES_Regs *aes)
{
    return (aes->DMA_TRIG2.RIS & AES_DMA_TRIG2_IMASK_DMA2_MASK);
}

/**
 *  @brief      Get highest priority pending AES interrupt
 *
 *  Checks if AES Ready Interrupt is pending. Interrupt does not have to
 *  be previously enabled.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The highest priority pending AES interrupt
 */
__STATIC_INLINE DL_AES_IIDX DL_AES_getPendingInterrupt(AES_Regs *aes)
{
    uint32_t interruptIdx = (uint32_t) aes->CPU_INT.IIDX;

    return (DL_AES_IIDX) interruptIdx;
}

/**
 *  @brief      Get highest priority pending DMA Trigger 0 Event
 *
 *  Checks if DMA Trigger 0 Event os pending. Event does not have to
 *  be previously enabled.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The highest priority pending DMA Trigger 0 Event
 */
__STATIC_INLINE DL_AES_IIDX DL_AES_getPendingDMATrigger0Event(AES_Regs *aes)
{
    uint32_t eventIdx = (uint32_t) aes->DMA_TRIG0.IIDX;

    return (DL_AES_IIDX) eventIdx;
}

/**
 *  @brief      Get highest priority pending DMA Trigger 1 Event
 *
 *  Checks if DMA Trigger 1 Event os pending. Event does not have to
 *  be previously enabled.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The highest priority pending DMA Trigger 1 Event
 */
__STATIC_INLINE DL_AES_IIDX DL_AES_getPendingDMATrigger1Event(AES_Regs *aes)
{
    uint32_t eventIdx = (uint32_t) aes->DMA_TRIG1.IIDX;

    return (DL_AES_IIDX) eventIdx;
}

/**
 *  @brief      Get highest priority pending DMA Trigger 2 Event
 *
 *  Checks if DMA Trigger 2 Event os pending. Event does not have to
 *  be previously enabled.
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The highest priority pending DMA Trigger 2 Event
 */
__STATIC_INLINE DL_AES_IIDX DL_AES_getPendingDMATrigger2Event(AES_Regs *aes)
{
    uint32_t eventIdx = (uint32_t) aes->DMA_TRIG2.IIDX;

    return (DL_AES_IIDX) eventIdx;
}

/**
 *  @brief      Clear pending AES Ready Interrupt
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_AES_clearInterruptStatus(AES_Regs *aes)
{
    aes->CPU_INT.ICLR |= AES_CPU_INT_IMASK_AESRDY_MASK;
}

/**
 *  @brief      Clear pending DMA Trigger 0 Event
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_AES_clearDMATrigger0EventStatus(AES_Regs *aes)
{
    aes->DMA_TRIG0.ICLR |= AES_DMA_TRIG0_IMASK_DMA0_MASK;
}

/**
 *  @brief      Clear pending DMA Trigger 1 Event
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_AES_clearDMATrigger1EventStatus(AES_Regs *aes)
{
    aes->DMA_TRIG1.ICLR |= AES_DMA_TRIG1_IMASK_DMA1_MASK;
}

/**
 *  @brief      Clear pending DMA Trigger 2 Event
 *
 *  @param[in]  aes           Pointer to the register overlay for the
 *                            peripheral
 */
__STATIC_INLINE void DL_AES_clearDMATrigger2EventStatus(AES_Regs *aes)
{
    aes->DMA_TRIG2.ICLR |= AES_DMA_TRIG2_IMASK_DMA2_MASK;
}

/**
 *  @brief      Save AES configuration before entering a power loss state.
 *              Note that operation-specific variables (intermediate data,
 *              key, IV) will need to be re-loaded after picking up the
 *              peripheral from a powerloss state.
 *
 *  @param[in]  aes  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr  Configuration backup setup structure. See
 *              @ref DL_AES_backupConfig.
 *
 *  @retval     FALSE if a configuration already exists in ptr (will not be
 *              overwritten). TRUE if a configuration was successfully saved
 *
 */
bool DL_AES_saveConfiguration(AES_Regs *aes, DL_AES_backupConfig *ptr);

/**
 *  @brief      Restore AES configuration after leaving a power loss state.
 *              Note that operation-specific variables (intermediate data,
 *              key, IV) will need to be re-loaded after picking up the
 *              peripheral from a powerloss state.
 *
 *  @param[in]  aes  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr  Configuration backup setup structure. See
 *              @ref DL_AES_backupConfig.
 *
 *  @retval     FALSE if a configuration does not exist in ptr (will not be
 *              loaded). TRUE if a configuration successfully loaded
 *
 */
bool DL_AES_restoreConfiguration(AES_Regs *aes, DL_AES_backupConfig *ptr);

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_AES__ */

#endif /* ti_dl_dl_aes__include */
/** @}*/
