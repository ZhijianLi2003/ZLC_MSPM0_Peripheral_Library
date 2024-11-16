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

#include <ti/driverlib/dl_keystorectl.h>

#ifdef __MSPM0_HAS_KEYSTORE_CTL__

static void DL_KEYSTORECTL_loadData(
    volatile uint32_t *pDest, uint32_t *pSrc, uint8_t len);
static uint8_t DL_KEYSTORECTL_getWordsFromSize(
    DL_KEYSTORECTL_KEY_SIZE keySize);

void DL_KEYSTORECTL_loadKey(KEYSTORECTL_Regs *keystorectl, uint32_t *key)
{
    DL_KEYSTORECTL_KEY_SIZE keySize;
    uint8_t numWords;
    volatile uint32_t *destPtr = (volatile uint32_t *) &keystorectl->KEYIN;
    uint32_t *srcPtr           = (uint32_t *) key;

    keySize  = DL_KEYSTORECTL_getDestinationKeySize(keystorectl);
    numWords = DL_KEYSTORECTL_getWordsFromSize(keySize);

    DL_KEYSTORECTL_loadData(destPtr, srcPtr, numWords);
}

DL_KEYSTORECTL_STATUS DL_KEYSTORECTL_writeKey(
    KEYSTORECTL_Regs *keystorectl, DL_KEYSTORECTL_KeyWrConfig *keyWrConfig)
{
    DL_KEYSTORECTL_STATUS status = DL_KEYSTORECTL_STATUS_VALID;
    uint32_t validSlot;
    uint8_t numWords;
    volatile uint32_t *destPtr = (volatile uint32_t *) &keystorectl->KEYIN;

    /* 1. Confirm valid status on the KEYSTORECTL */
    status = DL_KEYSTORECTL_getStatus(keystorectl);

    /* 2. Configure the key write by writing size and slot */
    if (status == DL_KEYSTORECTL_STATUS_VALID) {
        DL_Common_updateReg(&keystorectl->KEYWR,
            (((uint32_t) keyWrConfig->keySize) |
                ((uint32_t) keyWrConfig->keySlot)),
            (KEYSTORECTL_KEYWR_KEYSZSEL_MASK |
                KEYSTORECTL_KEYWR_KEYSLOTSEL_MASK));

        /* 3. Confirm a valid write configuration */
        status = DL_KEYSTORECTL_getStatus(keystorectl);
    }

    /* 4. Write key to the input buffer*/
    if (status == DL_KEYSTORECTL_STATUS_VALID) {
        numWords = DL_KEYSTORECTL_getWordsFromSize(keyWrConfig->keySize);

        DL_KEYSTORECTL_loadData(destPtr, keyWrConfig->key, numWords);

        /* 5. Loop until status is back to valid (no longer busy) */
        status = DL_KEYSTORECTL_getStatus(keystorectl);
        while (status == DL_KEYSTORECTL_STATUS_BUSY_RX) {
            status = DL_KEYSTORECTL_getStatus(keystorectl);
        }
    }

    /* 6. Confirm key slots were successfully written */
    if (status == DL_KEYSTORECTL_STATUS_VALID) {
        validSlot = (keyWrConfig->keySlot &
                     DL_KEYSTORECTL_getValidKeySlots(keystorectl));
        if (validSlot != keyWrConfig->keySlot) {
            status = DL_KEYSTORECTL_STATUS_WRITE_FAILED;
        }
    }

    return status;
}

DL_KEYSTORECTL_STATUS DL_KEYSTORECTL_transferKey(
    KEYSTORECTL_Regs *keystorectl, DL_KEYSTORECTL_Config *config)
{
    DL_KEYSTORECTL_STATUS status = DL_KEYSTORECTL_STATUS_VALID;

    /* 1. Confirm valid status on the KEYSTORECTL */
    status = DL_KEYSTORECTL_getStatus(keystorectl);

    /* 2. Configure the read transfer by writing size, slot, and recipient */
    if (status == DL_KEYSTORECTL_STATUS_VALID) {
        DL_Common_updateReg(&keystorectl->KEYRD,
            (((uint32_t) config->keySize) | ((uint32_t) config->cryptoSel) |
                ((uint32_t) config->keySlot)),
            (KEYSTORECTL_KEYRD_KEYSZSEL_MASK |
                KEYSTORECTL_KEYRD_CRYPTOSEL_MASK |
                KEYSTORECTL_KEYRD_KEYSLOTSEL_MASK));

        /* 3. Confirm a valid status and transfer configuration */
        status = DL_KEYSTORECTL_getStatus(keystorectl);
    }

    /* 4. Loop until status is back to valid */
    if (status == DL_KEYSTORECTL_STATUS_VALID) {
        status = DL_KEYSTORECTL_getStatus(keystorectl);
        while (status == DL_KEYSTORECTL_STATUS_BUSY_TX) {
            status = DL_KEYSTORECTL_getStatus(keystorectl);
        }
    }

    return status;
}

static void DL_KEYSTORECTL_loadData(
    volatile uint32_t *pDest, uint32_t *pSrc, uint8_t len)
{
    uint8_t i;
    uint32_t *pTemp;

    pTemp = pSrc;

    for (i = 0; i < len; i++) {
        *pDest = *pTemp++;
    }
}

static uint8_t DL_KEYSTORECTL_getWordsFromSize(DL_KEYSTORECTL_KEY_SIZE keySize)
{
    uint8_t numWords;

    switch (keySize) {
        case DL_KEYSTORECTL_KEY_SIZE_128_BITS:
            numWords = 4;
            break;
        case DL_KEYSTORECTL_KEY_SIZE_256_BITS:
            numWords = 8;
            break;
        default:
            numWords = 0;
            break;
    }

    return numWords;
}

#endif /* __MSPM0_HAS_KEYSTORE_CTL__ */
