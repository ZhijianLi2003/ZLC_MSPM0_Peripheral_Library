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
 *  @file       dl_keystorectl.h
 *  @brief      KEYSTORECTL (Keystore Controller) Driver Library
 *  @defgroup   KEYSTORECTL Keystore Controller (KEYSTORECTL)
 *
 *  @anchor ti_dl_dl_keystorectl_Overview
 *  # Overview
 *
 *  The Keystore Controller (KEYSTORECTL) DriverLib allows full configuration
 *  of the MSPM0 KEYSTORECTL Module.
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup KEYSTORECTL
 * @{
 */
#ifndef ti_dl_dl_keystorectl__include
#define ti_dl_dl_keystorectl__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_KEYSTORE_CTL__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/** @addtogroup DL_KEYSTORECTL_KEY_SLOT
 * @{
 */

/*! @brief Keystore Controller Key Slot 0 */
#define DL_KEYSTORECTL_KEY_SLOT_0           (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT0)

/*! @brief Keystore Controller Key Slot 1 */
#define DL_KEYSTORECTL_KEY_SLOT_1           (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT1)

/*! @brief Keystore Controller Key Slot 2 */
#define DL_KEYSTORECTL_KEY_SLOT_2           (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT2)

/*! @brief Keystore Controller Key Slot 3 */
#define DL_KEYSTORECTL_KEY_SLOT_3           (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT3)

/*! @brief Keystore Controller Key Slot 4 */
#define DL_KEYSTORECTL_KEY_SLOT_4           (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT4)

/*! @brief Keystore Controller Key Slot 5 */
#define DL_KEYSTORECTL_KEY_SLOT_5           (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT5)

/*! @brief Keystore Controller Key Slot 6 */
#define DL_KEYSTORECTL_KEY_SLOT_6           (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT6)

/*! @brief Keystore Controller Key Slot 7 */
#define DL_KEYSTORECTL_KEY_SLOT_7           (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT7)


/*! @brief Keystore Controller Key Combined Slot 0 and 1 */
#define DL_KEYSTORECTL_KEY_SLOT_0_AND_1    ((KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT0) | \
                                            (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT1))

/*! @brief Keystore Controller Key Combined Slot 2 and 3 */
#define DL_KEYSTORECTL_KEY_SLOT_2_AND_3    ((KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT2) | \
                                            (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT3))

/*! @brief Keystore Controller Key Combined Slot 4 and 5 */
#define DL_KEYSTORECTL_KEY_SLOT_4_AND_5    ((KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT4) | \
                                            (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT5))

/*! @brief Keystore Controller Key Combined Slot 6 and 7 */
#define DL_KEYSTORECTL_KEY_SLOT_6_AND_7    ((KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT6) | \
                                            (KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT7))

/** @}*/

/* clang-format on */

/*! @enum DL_KEYSTORECTL_NUM_256_KEYS */
typedef enum {
    /*! No 256-bit keys */
    DL_KEYSTORECTL_NUM_256_KEYS_ZERO = KEYSTORECTL_CFG_NK256_ZERO,
    /*! One 256-bit keys */
    DL_KEYSTORECTL_NUM_256_KEYS_ONE = KEYSTORECTL_CFG_NK256_ONE,
    /*! Two 256-bit keys */
    DL_KEYSTORECTL_NUM_256_KEYS_TWO = KEYSTORECTL_CFG_NK256_TWO,
    /*! Three 256-bit keys */
    DL_KEYSTORECTL_NUM_256_KEYS_THREE = KEYSTORECTL_CFG_NK256_THREE,
    /*! Four 256-bit keys */
    DL_KEYSTORECTL_NUM_256_KEYS_FOUR = KEYSTORECTL_CFG_NK256_FOUR,
} DL_KEYSTORECTL_NUM_256_KEYS;

/*! @enum DL_KEYSTORECTL_KEY_SIZE */
typedef enum {
    /*! Key size set to 128 */
    DL_KEYSTORECTL_KEY_SIZE_128_BITS = KEYSTORECTL_KEYWR_KEYSZSEL_K128,
    /*! Key size set to 256  */
    DL_KEYSTORECTL_KEY_SIZE_256_BITS = KEYSTORECTL_KEYWR_KEYSZSEL_K256,
} DL_KEYSTORECTL_KEY_SIZE;

/*! @enum DL_KEYSTORECTL_NUM_SLOTS */
typedef enum {
    /*! Two 128-bit key slots present on device */
    DL_KEYSTORECTL_NUM_SLOTS_TWO = KEYSTORECTL_STATUS_NKEYSLOTS_TWO,
    /*! Three 128-bit key slots present on device */
    DL_KEYSTORECTL_NUM_SLOTS_THREE = KEYSTORECTL_STATUS_NKEYSLOTS_THREE,
    /*! Four 128-bit key slots present on device */
    DL_KEYSTORECTL_NUM_SLOTS_FOUR = KEYSTORECTL_STATUS_NKEYSLOTS_FOUR,
} DL_KEYSTORECTL_NUM_SLOTS;

/*! @enum DL_KEYSTORECTL_CRYPTO_SEL */
typedef enum {
    /*! Transfer the key from keystore KEYSTORECTL to the AES engine */
    DL_KEYSTORECTL_CRYPTO_SEL_AES = KEYSTORECTL_KEYRD_CRYPTOSEL_AES,
} DL_KEYSTORECTL_CRYPTO_SEL;

/*! @enum DL_KEYSTORECTL_STATUS */
typedef enum {
    /*! Valid status bit. Configuration is valid or operation completed. */
    DL_KEYSTORECTL_STATUS_VALID = KEYSTORECTL_STATUS_STAT_VALID,
    /*! No Configuration Status bit, no number of 256 keys has been identified.
     *  The user must call @ref DL_KEYSTORECTL_setNumberOf256Keys. */
    DL_KEYSTORECTL_STATUS_NO_CONFIG = KEYSTORECTL_STATUS_STAT_NO_CFG,
    /*! Invalid number set during @ref DL_KEYSTORECTL_setNumberOf256Keys */
    DL_KEYSTORECTL_STATUS_INVALID_NUM_KEYS =
        KEYSTORECTL_STATUS_STAT_INVALID_NK256,
    /*! Busy RX status bit. The engine is busy receiving a key deposit. */
    DL_KEYSTORECTL_STATUS_BUSY_RX = KEYSTORECTL_STATUS_STAT_BUSY_RECEIVE,
    /*! Busy TX status bit. The engine is busy transmitting a key to a crypto engine */
    DL_KEYSTORECTL_STATUS_BUSY_TX = KEYSTORECTL_STATUS_STAT_BUSY_TRANSMIT,
    /*! Invalid key write configuration. This means one or more of the
     *  following: the selected slot exceeds available slots, the selected slot
     *  already contains a valid programmed key, the selected slot has a
     *  mismatched key size compared to the KEYSTORECTL configuration. */
    DL_KEYSTORECTL_STATUS_INVALID_SLOT_WR =
        KEYSTORECTL_STATUS_STAT_INVALID_KEYSLOTSELW,
    /*! Invalid key read configuration (transmitting a key). This means one or
     *  more of the following: the selected slot exceeds available slots, the
     *  selected slot does not contain a valid programmed key, the selected slot
     *  has a mismatched key size */
    DL_KEYSTORECTL_STATUS_INVALID_SLOT_RD =
        KEYSTORECTL_STATUS_STAT_INVALID_KEYSLOTSELR,
    /*! Key slots are not valid after a write. Write failed during the
        @ref DL_KEYSTORECTL_writeKey (driver library specific). */
    DL_KEYSTORECTL_STATUS_WRITE_FAILED = 0x0BAD,
} DL_KEYSTORECTL_STATUS;

/*!
 *  @brief Configuration struct for @ref DL_KEYSTORECTL_writeKey
 */
typedef struct {
    /*! The key slot (or slots in the case of 256-bit keys) to be written.
     *  One of @ref DL_KEYSTORECTL_KEY_SLOT */
    uint32_t keySlot;
    /*! The size of the key (128-bit or 256-bit).
     *  One of @ref DL_KEYSTORECTL_KEY_SIZE */
    DL_KEYSTORECTL_KEY_SIZE keySize;
    /*! uint32_t pointer to the current key in memory */
    uint32_t *key;
} DL_KEYSTORECTL_KeyWrConfig;

/*!
 *  @brief Configuration struct for @ref DL_KEYSTORECTL_transferKey
 */
typedef struct {
    /*! The key slot (or slots in the case of 256-bit keys) to be transferred.
     *  One of @ref DL_KEYSTORECTL_KEY_SLOT */
    uint32_t keySlot;
    /*! The size of the key (128-bit or 256-bit).
     *  One of @ref DL_KEYSTORECTL_KEY_SIZE */
    DL_KEYSTORECTL_KEY_SIZE keySize;
    /*! The intended crypto recipient. One of @ref DL_KEYSTORECTL_CRYPTO_SEL */
    DL_KEYSTORECTL_CRYPTO_SEL cryptoSel;
} DL_KEYSTORECTL_Config;

/**
 *  @brief Sets the number of combined 256 key slots
 *
 *  For a given number of 128-bit key slots n, there can be up to n/2 slots
 *  combined to work as one 256-bit key slot. These larger slots are added to
 *  earlier slots first. Thus, a 4-slot device with one 256-key slot will have
 *  slots 0 and 1 combined, and slot 2 and 3 will remain 128-bit key slots.
 *      Refer to the device datasheet for the specific number of key slots.
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *  @param[in] numKeys      Number of 256-bit keys, one of
 *                          @ref DL_KEYSTORECTL_NUM_256_KEYS. Must be less than
 *                          the total key slots on the device divided by two
 *
 *  @note this function can only be written in a secure operating state before
 *        the INITDONE signal is asserted.
 */
__STATIC_INLINE void DL_KEYSTORECTL_setNumberOf256Keys(
    KEYSTORECTL_Regs *keystorectl, DL_KEYSTORECTL_NUM_256_KEYS numKeys)
{
    DL_Common_updateReg(
        &keystorectl->CFG, (uint32_t) numKeys, KEYSTORECTL_CFG_NK256_MASK);
}

/**
 *  @brief Returns the current number of combined 256 key slots
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *
 *  @return number of 256-bit keys. One of @ref DL_KEYSTORECTL_NUM_256_KEYS
 *
 *  @sa DL_KEYSTORECTL_setNumberOf256Keys
 */
__STATIC_INLINE DL_KEYSTORECTL_NUM_256_KEYS DL_KEYSTORECTL_getNumberOf256Keys(
    KEYSTORECTL_Regs *keystorectl)
{
    uint32_t numKeys = (keystorectl->CFG & KEYSTORECTL_CFG_NK256_MASK);

    return (DL_KEYSTORECTL_NUM_256_KEYS)(numKeys);
}

/**
 *  @brief Sets the intended destination key slot for the next write
 *
 *  Sets the destination key slot for a data write to that region. In the case
 *  of 128-bit key slot, only one slot should be selected. In the case of a 256-
 *  bit key slot, both registers should be selected and the key size should also
 *  reflect this change. If 256- it keys are desired, they should be configured
 *  using @ref DL_KEYSTORECTL_NUM_256_KEYS.
 *      Refer to the device datasheet for the specific number of key slots.
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *  @param[in] keySlot      The intended key slot. Can be 128-bit or a 256-bit.
 *                          One of @ref DL_KEYSTORECTL_KEY_SLOT
 *
 *  @note this function can only be written in a secure operating state before
 *        the INITDONE signal is asserted.
 *
 *  @sa DL_KEYSTORECTL_setNumberOf256Keys
 *  @sa DL_KEYSTORECTL_setDestinationKeySize
 */
__STATIC_INLINE void DL_KEYSTORECTL_setDestinationKeySlot(
    KEYSTORECTL_Regs *keystorectl, uint32_t keySlot)
{
    DL_Common_updateReg(
        &keystorectl->KEYWR, keySlot, KEYSTORECTL_KEYWR_KEYSLOTSEL_MASK);
}

/**
 *  @brief Returns the intended destination key slot for the next write
 *
 *  Refer to the device datasheet for the specific number of key slots.
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *
 *  @returns   The intended key slot. Can be 128-bit or a 256-bit. One of
 *             @ref DL_KEYSTORECTL_KEY_SLOT
 *
 *  @note this function can only be read in a secure operating state before
 *        the INITDONE signal is asserted.
 *
 *  @sa DL_KEYSTORECTL_setDestinationKeySlot
 */
__STATIC_INLINE uint32_t DL_KEYSTORECTL_getDestinationKeySlot(
    KEYSTORECTL_Regs *keystorectl)
{
    return (keystorectl->KEYWR & KEYSTORECTL_KEYWR_KEYSLOTSEL_MASK);
}

/**
 *  @brief Sets the intended destination key slot size for next write
 *
 *  Sets the destination key slot size for a data write to that region. If 256-
 *  bit keys are desired, they should be  configured using
 *  @ref DL_KEYSTORECTL_NUM_256_KEYS.
 *      Refer to the device datasheet for the specific number of key slots.
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *  @param[in] keySize      The intended key size. One of
 *                          @ref DL_KEYSTORECTL_KEY_SIZE
 *
 *  @note this function can only be written in a secure operating state before
 *        the INITDONE signal is asserted.
 *
 *  @sa DL_KEYSTORECTL_setNumberOf256Keys
 *  @sa DL_KEYSTORECTL_setDestinationKeySlot
 */
__STATIC_INLINE void DL_KEYSTORECTL_setDestinationKeySize(
    KEYSTORECTL_Regs *keystorectl, DL_KEYSTORECTL_KEY_SIZE keySize)
{
    DL_Common_updateReg(&keystorectl->KEYWR, (uint32_t) keySize,
        KEYSTORECTL_KEYWR_KEYSZSEL_MASK);
}

/**
 *  @brief Returns the intended destination key size for the next write
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *
 *  @returns   The intended key size. One of @ref DL_KEYSTORECTL_KEY_SIZE
 *
 *  @note this function can only be read in a secure operating state before
 *        the INITDONE signal is asserted.
 *
 *  @sa DL_KEYSTORECTL_setDestinationKeySize
 */
__STATIC_INLINE DL_KEYSTORECTL_KEY_SIZE DL_KEYSTORECTL_getDestinationKeySize(
    KEYSTORECTL_Regs *keystorectl)
{
    uint32_t keySize = (keystorectl->KEYWR & KEYSTORECTL_KEYWR_KEYSZSEL_MASK);

    return (DL_KEYSTORECTL_KEY_SIZE)(keySize);
}

/**
 *  @brief Sets the intended destination key slot size for next write
 *
 *  Loads a key of the provided size into the KEYSTORECTL provided there is a
 *  valid bit set. The specific intended slot and size should already be set by
 *  the user before using this.
 *      Refer to the device datasheet for the specific number of key slots.
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *  @param[in] key          Pointer to an uint32_t array containing the key.
 *
 *  @note this function can only be written in a secure operating state before
 *        the INITDONE signal is asserted.
 *
 *  @sa DL_KEYSTORECTL_setDestinationKeySlot
 *  @sa DL_KEYSTORECTL_setDestinationKeySize
 */
void DL_KEYSTORECTL_loadKey(KEYSTORECTL_Regs *keystorectl, uint32_t *key);

/**
 *  @brief Gets the intended source key slot for the next transfer
 *
 *  Sets the source key slot for a data transfer to another crypto peripheral.
 *  In the case of 128-bit key slot, only one slot should be selected. In the
 *  case of a 256-bit key slot, both registers should be selected and the key
 *  size should also reflect this change. If 256- it keys are desired, they
 *  can be accessed using @ref DL_KEYSTORECTL_getNumberOf256Keys.
 *      Refer to the device datasheet for the specific number of key slots.
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *  @param[in] keySlot      The intended key slot. Can be 128-bit or a 256-bit.
 *                          One of @ref DL_KEYSTORECTL_KEY_SLOT
 *
 *  @sa DL_KEYSTORECTL_getNumOf256Keys
 *  @sa DL_KEYSTORECTL_setSourceKeySize
 */
__STATIC_INLINE void DL_KEYSTORECTL_setSourceKeySlot(
    KEYSTORECTL_Regs *keystorectl, uint32_t keySlot)
{
    DL_Common_updateReg(
        &keystorectl->KEYRD, keySlot, KEYSTORECTL_KEYRD_KEYSLOTSEL_MASK);
}

/**
 *  @brief Gets the intended source key slot for the next transfer
 *
 *  Refer to the device datasheet for the specific number of key slots.
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *
 *  @returns   The intended key slot. Can be 128-bit or a 256-bit. One of
 *             @ref DL_KEYSTORECTL_KEY_SLOT
 *
 *  @sa DL_KEYSTORECTL_setSourceKeySlot
 */
__STATIC_INLINE uint32_t DL_KEYSTORECTL_getSourceKeySlot(
    KEYSTORECTL_Regs *keystorectl)
{
    return (keystorectl->KEYRD & KEYSTORECTL_KEYRD_KEYSLOTSEL_MASK);
}

/**
 *  @brief Gets the intended source key slot size for next transfer
 *
 *  Sets the source key slot size for a data transfer to that region. If 256-
 *  bit keys are desired, they should be  configured using
 *  @ref DL_KEYSTORECTL_NUM_256_KEYS.
 *      Refer to the device datasheet for the specific number of key slots.
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *  @param[in] keySize      The intended key size. One of
 *                          @ref DL_KEYSTORECTL_KEY_SIZE
 *
 *  @sa DL_KEYSTORECTL_setNumberOf256Keys
 *  @sa DL_KEYSTORECTL_setSourceKeySlot
 */
__STATIC_INLINE void DL_KEYSTORECTL_setSourceKeySize(
    KEYSTORECTL_Regs *keystorectl, DL_KEYSTORECTL_KEY_SIZE keySize)
{
    DL_Common_updateReg(&keystorectl->KEYRD, (uint32_t) keySize,
        KEYSTORECTL_KEYRD_KEYSZSEL_MASK);
}

/**
 *  @brief Gets the intended source key size for the next transfer
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *
 *  @returns   The intended key size. One of @ref DL_KEYSTORECTL_KEY_SIZE
 *
 *  @sa DL_KEYSTORECTL_setSourceKeySize
 */
__STATIC_INLINE DL_KEYSTORECTL_KEY_SIZE DL_KEYSTORECTL_getSourceKeySize(
    KEYSTORECTL_Regs *keystorectl)
{
    uint32_t keySize = (keystorectl->KEYRD & KEYSTORECTL_KEYRD_KEYSZSEL_MASK);

    return (DL_KEYSTORECTL_KEY_SIZE)(keySize);
}

/**
 *  @brief Gets the current status of the KEYSTORECTL module
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *
 *  @return    The status of the keystorectl. One of @ref DL_KEYSTORECTL_STATUS
 */
__STATIC_INLINE DL_KEYSTORECTL_STATUS DL_KEYSTORECTL_getStatus(
    KEYSTORECTL_Regs *keystorectl)
{
    uint32_t status = (keystorectl->STATUS & KEYSTORECTL_STATUS_STAT_MASK);

    return (DL_KEYSTORECTL_STATUS)(status);
}

/**
 *  @brief Gets currently written key slots
 *
 *  To understand the key slot configuration, consider the configuration of the
 *  keys including the number of 256-bit keys, and the number of available key
 *  slots
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *
 *  @return    Bitwise OR of all valid slots, corresponding to
 *             @ref DL_KEYSTORECTL_KEY_SLOT values.
 */
__STATIC_INLINE uint32_t DL_KEYSTORECTL_getValidKeySlots(
    KEYSTORECTL_Regs *keystorectl)
{
    return (keystorectl->STATUS & KEYSTORECTL_STATUS_VALID_MASK);
}

/**
 *  @brief Gets the total number of 128-bit key slots in HW on the device
 *
 *  This is the number of key slots that the KEYSTORECTL module has in HW on the
 *  device. It does not reflect the configuration or the number of 256-bit keys,
 *  only the total number of slots. This also governs the valid configurations,
 *  and the number of 256-bit keys must be less than or equal to half the value.
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *
 *  @return    The number of 128-bit slots on the device. One of
 *             @ref DL_KEYSTORECTL_NUM_SLOTS
 */
__STATIC_INLINE DL_KEYSTORECTL_NUM_SLOTS DL_KEYSTORECTL_getNumSlots(
    KEYSTORECTL_Regs *keystorectl)
{
    uint32_t numSlots =
        (keystorectl->STATUS & KEYSTORECTL_STATUS_NKEYSLOTS_MASK);

    return (DL_KEYSTORECTL_NUM_SLOTS)(numSlots);
}

/**
 *  @brief Writes a key into the KEYSTORE
 *
 *  The sequence this function will follow:
 *
 *  1. Confirm valid status on the KEYSTORECTL
 *  2. Configure the key write by writing size and slot to the key that is to be
 *          written. Passed in via @ref DL_KEYSTORECTL_KeyWrConfig
 *  3. Confirm a valid write configuration
 *  4. Write key to the input buffer
 *  5. Loop until status is back to valid
 *  6. Confirm key slots are successfully written
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *
 *  @param[in] keyWrConfig  Pointer to the write key configuration struct
 *                          @ref DL_KEYSTORECTL_KeyWrConfig
 *
 *  @return    Status of the operation of type @ref DL_KEYSTORECTL_STATUS. Type
 *             will be DL_KEYSTORECTL_STATUS_VALID if successful, or return the
 *             error status.
 *
 *  @note The function @ref DL_KEYSTORECTL_setNumberOf256Keys must be run
 *        before this can be executed.
 *  @note It is not possible to overwrite a previously configured key. A full
 *        BOOTRST must be executed before the KEYSTORECTL is erased and can be
 *        re-initialized and written.
 *  @note this function can only be written in a secure operating state before
 *        the INITDONE signal is asserted.
 */
DL_KEYSTORECTL_STATUS DL_KEYSTORECTL_writeKey(
    KEYSTORECTL_Regs *keystorectl, DL_KEYSTORECTL_KeyWrConfig *keyWrConfig);

/**
 *  @brief Transfers key loaded in KEYSTORE into intended crypto
 *
 *  Combination of previous functions in order to give the entire operation.
 *  Expected runtime sequence:
 *
 *  1. Confirm valid status on the KEYSTORECTL
 *  2. Configure the read transfer by writing size, slot, and recipient
 *        This is passed in via the struct @ref DL_KEYSTORECTL_Config
 *  3. Confirm a valid status and transfer configuration of the KEYSTORECTL
 *  4. Loop until status is back to valid
 *
 *  @param[in] keystorectl  Pointer to the register overlay for the peripheral
 *  @param[in] config       Pointer to a filled out config struct of type
 *                          @ref DL_KEYSTORECTL_Config
 *
 *  @return    Status of the operation of type @ref DL_KEYSTORECTL_STATUS. Type
 *             will be DL_KEYSTORECTL_STATUS_VALID if successful, or return the
 *             error status.
 */
DL_KEYSTORECTL_STATUS DL_KEYSTORECTL_transferKey(
    KEYSTORECTL_Regs *keystorectl, DL_KEYSTORECTL_Config *config);

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_KEYSTORE_CTL__ */

#endif /* ti_dl_dl_KEYSTORECTL__include */
/** @}*/
