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

#include <ti/driverlib/dl_aesadv.h>

#ifdef __MSPM0_HAS_AESADV__

static void DL_AESADV_loadData(
    volatile uint32_t *destPtr, const uint32_t *srcPtr, uint8_t numWords);
static void DL_AESADV_readData(
    uint32_t *destPtr, volatile const uint32_t *srcPtr, uint8_t numWords);

static const uint32_t *DL_AESADV_checkAlignmentAndReturnConstPtr(
    const uint8_t *ptr);

static uint32_t *DL_AESADV_checkAlignmentAndReturnPtr(uint8_t *ptr);

DL_AESADV_STATUS DL_AESADV_setKey(
    AESADV_Regs *aesadv, const uint8_t *key, DL_AESADV_KEY_SIZE keySize)
{
    DL_AESADV_STATUS status = DL_AESADV_STATUS_SUCCESS;
    const uint32_t *keyAligned;

    keyAligned = DL_AESADV_checkAlignmentAndReturnConstPtr(key);
    if (keyAligned != NULL) {
        DL_AESADV_setKeyAligned(aesadv, keyAligned, keySize);
    } else {
        status = DL_AESADV_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AESADV_setKeyAligned(AESADV_Regs *aesadv, const uint32_t *keyAligned,
    DL_AESADV_KEY_SIZE keySize)
{
    uint8_t numWords;

    switch (keySize) {
        case DL_AESADV_KEY_SIZE_128_BIT:
            numWords = 4U;
            break;
        case DL_AESADV_KEY_SIZE_256_BIT:
            numWords = 8U;
            break;
        default:
            /* invalid key size*/
            numWords = 0U;
            break;
    }

    DL_Common_updateReg(
        &aesadv->CTRL, (uint32_t) keySize, AESADV_CTRL_KEYSIZE_MASK);

    DL_AESADV_loadData(&aesadv->KEY0, keyAligned, numWords);

    return;
}

DL_AESADV_STATUS DL_AESADV_setGCMHashKey(
    AESADV_Regs *aesadv, const uint8_t *hashKey)
{
    DL_AESADV_STATUS status = DL_AESADV_STATUS_SUCCESS;
    const uint32_t *hashKeyAligned;

    hashKeyAligned = DL_AESADV_checkAlignmentAndReturnConstPtr(hashKey);
    if (hashKeyAligned != NULL) {
        DL_AESADV_setGCMHashKeyAligned(aesadv, hashKeyAligned);
    } else {
        status = DL_AESADV_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AESADV_setGCMHashKeyAligned(
    AESADV_Regs *aesadv, const uint32_t *hashKeyAligned)
{
    uint8_t numWords = 4U;

    DL_AESADV_loadData(&aesadv->GHASH_H0, hashKeyAligned, numWords);

    return;
}

DL_AESADV_STATUS DL_AESADV_setSecondKey(
    AESADV_Regs *aesadv, const uint8_t *secondKey)
{
    DL_AESADV_STATUS status = DL_AESADV_STATUS_SUCCESS;
    const uint32_t *secondKeyAligned;

    secondKeyAligned = DL_AESADV_checkAlignmentAndReturnConstPtr(secondKey);
    if (secondKeyAligned != NULL) {
        DL_AESADV_setSecondKeyAligned(aesadv, secondKeyAligned);
    } else {
        status = DL_AESADV_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AESADV_setSecondKeyAligned(
    AESADV_Regs *aesadv, const uint32_t *secondKeyAligned)
{
    uint8_t numWords = 4U;

    DL_AESADV_loadData(&aesadv->GHASH_H0, secondKeyAligned, numWords);

    return;
}

DL_AESADV_STATUS DL_AESADV_setThirdKey(
    AESADV_Regs *aesadv, const uint8_t *thirdKey)
{
    DL_AESADV_STATUS status = DL_AESADV_STATUS_SUCCESS;
    const uint32_t *thirdKeyAligned;

    thirdKeyAligned = DL_AESADV_checkAlignmentAndReturnConstPtr(thirdKey);
    if (thirdKeyAligned != NULL) {
        DL_AESADV_setThirdKeyAligned(aesadv, thirdKeyAligned);
    } else {
        status = DL_AESADV_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AESADV_setThirdKeyAligned(
    AESADV_Regs *aesadv, const uint32_t *thirdKeyAligned)
{
    uint8_t numWords = 4U;

    DL_AESADV_loadData(&aesadv->GCMCCM_TAG0, thirdKeyAligned, numWords);

    return;
}

DL_AESADV_STATUS DL_AESADV_loadIntermediateTAG(
    AESADV_Regs *aesadv, const uint8_t *tag)
{
    DL_AESADV_STATUS status = DL_AESADV_STATUS_SUCCESS;
    const uint32_t *tagAligned;

    tagAligned = DL_AESADV_checkAlignmentAndReturnConstPtr(tag);
    if (tagAligned != NULL) {
        DL_AESADV_loadIntermediateTAGAligned(aesadv, tagAligned);
    } else {
        status = DL_AESADV_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AESADV_loadIntermediateTAGAligned(
    AESADV_Regs *aesadv, const uint32_t *tagAligned)
{
    uint8_t numWords = 4U;

    DL_AESADV_loadData(&aesadv->GCMCCM_TAG0, tagAligned, numWords);

    return;
}

DL_AESADV_STATUS DL_AESADV_loadInitializationVector(
    AESADV_Regs *aesadv, uint8_t *iv)
{
    DL_AESADV_STATUS status = DL_AESADV_STATUS_SUCCESS;
    uint32_t *ivAligned;

    ivAligned = DL_AESADV_checkAlignmentAndReturnPtr(iv);
    if (ivAligned != NULL) {
        DL_AESADV_loadInitializationVectorAligned(aesadv, ivAligned);
    } else {
        status = DL_AESADV_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AESADV_loadInitializationVectorAligned(
    AESADV_Regs *aesadv, uint32_t *ivAligned)
{
    uint8_t numWords = 4U;

    DL_AESADV_loadData(&aesadv->IV0, ivAligned, numWords);

    return;
}

DL_AESADV_STATUS DL_AESADV_readInitializationVector(
    AESADV_Regs *aesadv, uint8_t *iv)
{
    DL_AESADV_STATUS status = DL_AESADV_STATUS_SUCCESS;
    uint32_t *ivAligned;

    ivAligned = DL_AESADV_checkAlignmentAndReturnPtr(iv);
    if (ivAligned != NULL) {
        DL_AESADV_readInitializationVectorAligned(aesadv, ivAligned);
    } else {
        status = DL_AESADV_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AESADV_readInitializationVectorAligned(
    AESADV_Regs *aesadv, uint32_t *ivAligned)
{
    uint8_t numWords = 4U;
    volatile uint32_t *sourcePtr;

    sourcePtr = (volatile uint32_t *) &aesadv->IV0;

    DL_AESADV_readData(ivAligned, sourcePtr, numWords);

    return;
}

void DL_AESADV_loadCCMNonceAndCounter(
    AESADV_Regs *aesadv, uint8_t *nonce, DL_AESADV_CCM_CTR_WIDTH ctrWidth)
{
    uint8_t *noncePtr = nonce;
    uint8_t numWords  = 4U;
    uint32_t ivArray[4];
    uint8_t *ivPtr = (uint8_t *) &ivArray[0];
    uint8_t i;

    /* calculation of the nonce length. (Length described in table in header) */
    uint8_t ccml = (uint8_t)((uint32_t) ctrWidth >> AESADV_CTRL_CCML_OFS);
    uint8_t counterWidthInBytes = (ccml + 1U);

    /* subtracting the counterWidth in bytes as well as the flag byte */
    uint8_t nonceWidthInBytes = 14U - ccml;

    *ivPtr++ = ccml;

    /* addition of the Nonce */
    for (i = 0; i < nonceWidthInBytes; i++) {
        *ivPtr++ = *noncePtr++;
    }

    /* Counter is always initialized to zeros */
    for (i = 0; i < counterWidthInBytes; i++) {
        *ivPtr++ = 0x00;
    }

    DL_AESADV_loadData(&aesadv->IV0, ivArray, numWords);

    return;
}

DL_AESADV_STATUS DL_AESADV_loadInputData(AESADV_Regs *aesadv, uint8_t *data)
{
    DL_AESADV_STATUS status = DL_AESADV_STATUS_SUCCESS;
    uint32_t *dataAligned;

    dataAligned = DL_AESADV_checkAlignmentAndReturnPtr(data);
    if (dataAligned != NULL) {
        DL_AESADV_loadInputDataAligned(aesadv, dataAligned);
    } else {
        status = DL_AESADV_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AESADV_loadInputDataAligned(AESADV_Regs *aesadv, uint32_t *dataAligned)
{
    uint8_t numWords = 4U;

    DL_AESADV_loadData(&aesadv->DATA0, dataAligned, numWords);

    return;
}

DL_AESADV_STATUS DL_AESADV_readOutputData(AESADV_Regs *aesadv, uint8_t *data)
{
    DL_AESADV_STATUS status = DL_AESADV_STATUS_SUCCESS;
    uint32_t *dataAligned;

    dataAligned = DL_AESADV_checkAlignmentAndReturnPtr(data);
    if (dataAligned != NULL) {
        DL_AESADV_readOutputDataAligned(aesadv, dataAligned);
    } else {
        status = DL_AESADV_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AESADV_readOutputDataAligned(
    AESADV_Regs *aesadv, uint32_t *dataAligned)
{
    uint8_t numWords = 4U;

    DL_AESADV_readData(dataAligned, &aesadv->DATA0, numWords);

    return;
}

DL_AESADV_STATUS DL_AESADV_readTAG(AESADV_Regs *aesadv, uint8_t *tag)
{
    DL_AESADV_STATUS status = DL_AESADV_STATUS_SUCCESS;
    uint32_t *tagAligned;

    tagAligned = DL_AESADV_checkAlignmentAndReturnPtr(tag);
    if (tagAligned != NULL) {
        DL_AESADV_readTAGAligned(aesadv, tagAligned);
    } else {
        status = DL_AESADV_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AESADV_readTAGAligned(AESADV_Regs *aesadv, uint32_t *tagAligned)
{
    uint8_t numWords = 4U;

    DL_AESADV_readData(tagAligned, &aesadv->TAG0, numWords);

    return;
}

void DL_AESADV_initECB(AESADV_Regs *aesadv, DL_AESADV_Config *config)
{
    DL_Common_updateReg(&aesadv->CTRL,
        ((uint32_t) DL_AESADV_MODE_ECB | config->direction),
        ((uint32_t) DL_AESADV_MODE_MASK | AESADV_CTRL_DIR_MASK |
            AESADV_CTRL_SAVE_CNTXT_MASK));

    DL_AESADV_setUpperCryptoLength(aesadv, config->upperCryptoLength);
    DL_AESADV_setLowerCryptoLength(aesadv, config->lowerCryptoLength);
}

void DL_AESADV_initCBC(AESADV_Regs *aesadv, DL_AESADV_Config *config)
{
    DL_Common_updateReg(&aesadv->CTRL,
        ((uint32_t) DL_AESADV_MODE_CBC | config->direction),
        ((uint32_t) DL_AESADV_MODE_MASK | AESADV_CTRL_DIR_MASK |
            AESADV_CTRL_SAVE_CNTXT_MASK));

    DL_AESADV_loadInitializationVector(aesadv, config->iv);

    DL_AESADV_setUpperCryptoLength(aesadv, config->upperCryptoLength);
    DL_AESADV_setLowerCryptoLength(aesadv, config->lowerCryptoLength);
}

void DL_AESADV_initCFB(AESADV_Regs *aesadv, DL_AESADV_Config *config)
{
    DL_Common_updateReg(&aesadv->CTRL,
        (((uint32_t) DL_AESADV_MODE_CFB) | ((uint32_t) config->direction) |
            ((uint32_t) config->cfb_fbWidth)),
        (DL_AESADV_MODE_MASK | AESADV_CTRL_DIR_MASK |
            AESADV_CTRL_CTR_WIDTH_MASK | AESADV_CTRL_SAVE_CNTXT_MASK));

    DL_AESADV_loadInitializationVector(aesadv, config->iv);

    DL_AESADV_setUpperCryptoLength(aesadv, config->upperCryptoLength);
    DL_AESADV_setLowerCryptoLength(aesadv, config->lowerCryptoLength);
}

void DL_AESADV_initOFB(AESADV_Regs *aesadv, DL_AESADV_Config *config)
{
    DL_Common_updateReg(&aesadv->CTRL,
        (((uint32_t) DL_AESADV_MODE_OFB) | ((uint32_t) config->direction) |
            ((uint32_t) config->cfb_fbWidth)),
        (DL_AESADV_MODE_MASK | AESADV_CTRL_DIR_MASK |
            AESADV_CTRL_CTR_WIDTH_MASK | AESADV_CTRL_SAVE_CNTXT_MASK));

    DL_AESADV_loadInitializationVector(aesadv, config->iv);

    DL_AESADV_setUpperCryptoLength(aesadv, config->upperCryptoLength);
    DL_AESADV_setLowerCryptoLength(aesadv, config->lowerCryptoLength);
}

void DL_AESADV_initCTR(AESADV_Regs *aesadv, DL_AESADV_Config *config)
{
    DL_Common_updateReg(&aesadv->CTRL,
        (((uint32_t) DL_AESADV_MODE_CTR) | ((uint32_t) config->direction) |
            ((uint32_t) config->ctr_ctrWidth)),
        (DL_AESADV_MODE_MASK | AESADV_CTRL_DIR_MASK |
            AESADV_CTRL_CTR_WIDTH_MASK | AESADV_CTRL_SAVE_CNTXT_MASK));

    DL_AESADV_loadInitializationVector(aesadv, config->iv);

    DL_AESADV_setUpperCryptoLength(aesadv, config->upperCryptoLength);
    DL_AESADV_setLowerCryptoLength(aesadv, config->lowerCryptoLength);
}

void DL_AESADV_initICM(AESADV_Regs *aesadv, DL_AESADV_Config *config)
{
    DL_Common_updateReg(&aesadv->CTRL,
        ((uint32_t) DL_AESADV_MODE_ICM | ((uint32_t) config->direction)),
        (DL_AESADV_MODE_MASK | AESADV_CTRL_DIR_MASK |
            AESADV_CTRL_SAVE_CNTXT_MASK));

    DL_AESADV_loadInitializationVector(aesadv, config->iv);

    DL_AESADV_setUpperCryptoLength(aesadv, config->upperCryptoLength);
    DL_AESADV_setLowerCryptoLength(aesadv, config->lowerCryptoLength);
}

void DL_AESADV_initCMAC(AESADV_Regs *aesadv, DL_AESADV_Config *config)
{
    uint32_t zeroArray[4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000};

    /* Set the second and third keys, and zero out the initialization vector */
    DL_AESADV_setSecondKey(aesadv, config->k1);
    DL_AESADV_setThirdKey(aesadv, config->k2);
    DL_AESADV_loadInitializationVectorAligned(aesadv, &zeroArray[0]);

    DL_Common_updateReg(&aesadv->CTRL,
        ((uint32_t) DL_AESADV_MODE_CMAC | ((uint32_t) DL_AESADV_DIR_ENCRYPT) |
            ((uint32_t) AESADV_CTRL_SAVE_CNTXT_ENABLE)),
        (DL_AESADV_MODE_MASK | AESADV_CTRL_DIR_MASK |
            AESADV_CTRL_SAVE_CNTXT_MASK));

    DL_AESADV_setUpperCryptoLength(aesadv, config->upperCryptoLength);
    DL_AESADV_setLowerCryptoLength(aesadv, config->lowerCryptoLength);
}

void DL_AESADV_initCBCMAC(AESADV_Regs *aesadv, DL_AESADV_Config *config)
{
    uint32_t zeroArray[4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000};

    /* Zero out the second and third keys and the IV for CBC-MAC as per spec */
    DL_AESADV_setSecondKeyAligned(aesadv, &zeroArray[0]);
    DL_AESADV_setThirdKeyAligned(aesadv, &zeroArray[0]);
    DL_AESADV_loadInitializationVectorAligned(aesadv, &zeroArray[0]);

    DL_Common_updateReg(&aesadv->CTRL,
        ((uint32_t) DL_AESADV_MODE_CBCMAC |
            ((uint32_t) DL_AESADV_DIR_ENCRYPT) |
            ((uint32_t) AESADV_CTRL_SAVE_CNTXT_ENABLE)),
        (DL_AESADV_MODE_MASK | AESADV_CTRL_DIR_MASK |
            AESADV_CTRL_SAVE_CNTXT_MASK));

    DL_AESADV_setUpperCryptoLength(aesadv, config->upperCryptoLength);
    DL_AESADV_setLowerCryptoLength(aesadv, config->lowerCryptoLength);
}

void DL_AESADV_initGCM(AESADV_Regs *aesadv, DL_AESADV_Config *config)
{
    uint32_t zeroArray[4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000};

    /* Zero out the intermediate TAG for GCM as per spec */
    DL_AESADV_loadIntermediateTAGAligned(aesadv, &zeroArray[0]);

    DL_AESADV_loadInitializationVector(aesadv, config->iv);

    DL_Common_updateReg(&aesadv->CTRL,
        (((uint32_t) config->mode) | ((uint32_t) config->direction) |
            ((uint32_t) DL_AESADV_CTR_WIDTH_32_BIT |
                (uint32_t) AESADV_CTRL_SAVE_CNTXT_ENABLE)),
        ((uint32_t) DL_AESADV_MODE_MASK | AESADV_CTRL_DIR_MASK |
            AESADV_CTRL_CTR_WIDTH_MASK | AESADV_CTRL_SAVE_CNTXT_MASK));

    DL_AESADV_setUpperCryptoLength(aesadv, config->upperCryptoLength);
    DL_AESADV_setLowerCryptoLength(aesadv, config->lowerCryptoLength);

    DL_AESADV_setAADLength(aesadv, config->aadLength);
}

void DL_AESADV_initCCM(AESADV_Regs *aesadv, DL_AESADV_Config *config)
{
    DL_AESADV_loadCCMNonceAndCounter(
        aesadv, config->nonce, config->ccm_ctrWidth);

    DL_Common_updateReg(&aesadv->CTRL,
        (((uint32_t) DL_AESADV_MODE_CCM) | ((uint32_t) config->direction) |
            ((uint32_t) config->ccm_ctrWidth) |
            ((uint32_t) config->ccm_tagWidth) |
            ((uint32_t) DL_AESADV_CTR_WIDTH_64_BIT) |
            ((uint32_t) AESADV_CTRL_SAVE_CNTXT_ENABLE)),
        (DL_AESADV_MODE_MASK | AESADV_CTRL_DIR_MASK | AESADV_CTRL_CCML_MASK |
            AESADV_CTRL_CCMM_MASK | AESADV_CTRL_CTR_WIDTH_MASK |
            AESADV_CTRL_SAVE_CNTXT_MASK));

    DL_AESADV_setUpperCryptoLength(aesadv, config->upperCryptoLength);
    DL_AESADV_setLowerCryptoLength(aesadv, config->lowerCryptoLength);

    DL_AESADV_setAADLength(aesadv, config->aadLength);
}

static void DL_AESADV_loadData(
    volatile uint32_t *destPtr, const uint32_t *srcPtr, uint8_t numWords)
{
    uint8_t i;
    for (i = 0; i < numWords; i++) {
        *destPtr++ = *srcPtr++;
    }
    return;
}

static void DL_AESADV_readData(
    uint32_t *destPtr, volatile const uint32_t *srcPtr, uint8_t numWords)
{
    uint8_t i;
    for (i = 0; i < numWords; i++) {
        *destPtr++ = *srcPtr++;
    }
    return;
}

static const uint32_t *DL_AESADV_checkAlignmentAndReturnConstPtr(
    const uint8_t *ptr)
{
    uint32_t address = (uint32_t) ptr;
    const uint32_t *alignedPtr;
    if ((address << 30) != 0x00000000u) {
        /* Unaligned access */
        alignedPtr = NULL;
    } else {
        /* Aligned Access */
        alignedPtr = (const uint32_t *) address;
    }
    return alignedPtr;
}

static uint32_t *DL_AESADV_checkAlignmentAndReturnPtr(uint8_t *ptr)
{
    uint32_t address = (uint32_t) ptr;
    uint32_t *alignedPtr;
    if ((address << 30) != 0x00000000u) {
        /* Unaligned access */
        alignedPtr = NULL;
    } else {
        /* Aligned Access */
        alignedPtr = (uint32_t *) address;
    }
    return alignedPtr;
}

#endif /* __MSPM0_HAS_AESADV__ */
