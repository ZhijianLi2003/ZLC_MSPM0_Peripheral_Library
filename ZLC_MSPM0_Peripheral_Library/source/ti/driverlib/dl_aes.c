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

#include <ti/driverlib/dl_aes.h>

#ifdef __MSPM0_HAS_AES__

static void DL_AES_loadDataWord(
    volatile uint32_t *pReg, const uint32_t *pData, uint8_t len);

static const uint32_t *DL_AES_checkAlignmentAndReturnPointer(
    const uint8_t *ptr);

DL_AES_STATUS DL_AES_setKey(
    AES_Regs *aes, const uint8_t *key, DL_AES_KEY_LENGTH keyLength)
{
    DL_AES_STATUS status = DL_AES_STATUS_SUCCESS;
    const uint32_t *keyAligned;

    keyAligned = DL_AES_checkAlignmentAndReturnPointer(key);
    if (keyAligned != NULL) {
        DL_AES_setKeyAligned(aes, keyAligned, keyLength);
    } else {
        status = DL_AES_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AES_setKeyAligned(
    AES_Regs *aes, const uint32_t *keyAligned, DL_AES_KEY_LENGTH keyLength)
{
    uint8_t numWords;

    switch (keyLength) {
        case DL_AES_KEY_LENGTH_128:
            numWords = 4U;
            break;
        case DL_AES_KEY_LENGTH_256:
            numWords = 8U;
            break;
        default:
            numWords = 0U;
            break;
    }

    DL_AES_loadDataWord(&aes->AESAKEY, keyAligned, numWords);
}

DL_AES_STATUS DL_AES_loadDataIn(AES_Regs *aes, const uint8_t *data)
{
    DL_AES_STATUS status = DL_AES_STATUS_SUCCESS;
    const uint32_t *dataAligned;

    dataAligned = DL_AES_checkAlignmentAndReturnPointer(data);
    if (dataAligned != NULL) {
        DL_AES_loadDataInAligned(aes, dataAligned);
    } else {
        status = DL_AES_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AES_loadDataInAligned(AES_Regs *aes, const uint32_t *dataAligned)
{
    DL_AES_loadDataWord(&aes->AESADIN, dataAligned, 4);
}

DL_AES_STATUS DL_AES_getDataOut(AES_Regs *aes, uint8_t *data)
{
    DL_AES_STATUS status = DL_AES_STATUS_SUCCESS;
    uint32_t *dataAligned;

    uint32_t address = (uint32_t) data;
    if ((address << 30) != 0x00000000u) {
        /* Unaligned access */
        status = DL_AES_STATUS_UNALIGNED_ACCESS;
    } else {
        /* Aligned Access */
        dataAligned = (uint32_t *) address;
        DL_AES_getDataOutAligned(aes, dataAligned);
    }
    return status;
}

void DL_AES_getDataOutAligned(AES_Regs *aes, uint32_t *dataAligned)
{
    uint8_t i;
    uint32_t *pData;
    volatile uint32_t const *aesPtr;

    pData  = dataAligned;
    aesPtr = (volatile uint32_t const *) &(aes->AESADOUT);

    for (i = 0U; i < 4U; i++) {
        *pData = *aesPtr;
        pData++;
    }
}

DL_AES_STATUS DL_AES_loadXORDataIn(AES_Regs *aes, const uint8_t *data)
{
    DL_AES_STATUS status = DL_AES_STATUS_SUCCESS;
    const uint32_t *dataAligned;

    dataAligned = DL_AES_checkAlignmentAndReturnPointer(data);
    if (dataAligned != NULL) {
        DL_AES_loadXORDataInAligned(aes, dataAligned);
    } else {
        status = DL_AES_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AES_loadXORDataInAligned(AES_Regs *aes, const uint32_t *dataAligned)
{
    DL_AES_loadDataWord(&aes->AESAXDIN, dataAligned, 4);
}

DL_AES_STATUS DL_AES_loadXORDataInWithoutTrigger(
    AES_Regs *aes, const uint8_t *data)
{
    DL_AES_STATUS status = DL_AES_STATUS_SUCCESS;
    const uint32_t *dataAligned;

    dataAligned = DL_AES_checkAlignmentAndReturnPointer(data);
    if (dataAligned != NULL) {
        DL_AES_loadXORDataInWithoutTriggerAligned(aes, dataAligned);
    } else {
        status = DL_AES_STATUS_UNALIGNED_ACCESS;
    }
    return status;
}

void DL_AES_loadXORDataInWithoutTriggerAligned(
    AES_Regs *aes, const uint32_t *dataAligned)
{
    DL_AES_loadDataWord(&aes->AESAXIN, dataAligned, 4);
}

DL_AES_STATUS DL_AES_xorData(
    uint8_t *data, uint8_t *xorData, uint8_t *xorOutputData)
{
    DL_AES_STATUS status = DL_AES_STATUS_SUCCESS;
    uint32_t *dataAligned;
    uint32_t *xorDataAligned;
    uint32_t *xorOutputDataAligned;

    uint32_t dataAddress          = (uint32_t) data;
    uint32_t xorDataAddress       = (uint32_t) xorData;
    uint32_t xorOutputDataAddress = (uint32_t) xorOutputData;

    if (((dataAddress << 30) != 0x00000000u) ||
        ((xorDataAddress << 30) != 0x00000000u) ||
        ((xorOutputDataAddress << 30) != 0x00000000u)) {
        /* Unaligned access */
        status = DL_AES_STATUS_UNALIGNED_ACCESS;
    } else {
        /* Aligned Access */
        dataAligned          = (uint32_t *) dataAddress;
        xorDataAligned       = (uint32_t *) xorDataAddress;
        xorOutputDataAligned = (uint32_t *) xorOutputDataAddress;
        DL_AES_xorDataAligned(
            dataAligned, xorDataAligned, xorOutputDataAligned);
    }
    return status;
}

void DL_AES_xorDataAligned(uint32_t *dataAligned, uint32_t *xorDataAligned,
    uint32_t *xorOutputDataAligned)
{
    uint8_t i;

    uint32_t *tempData          = dataAligned;
    uint32_t *tempXorData       = xorDataAligned;
    uint32_t *tempXorOutputData = xorOutputDataAligned;

    for (i = 0U; i < 4U; i++) {
        *tempXorOutputData = *tempData ^ *tempXorData;
        tempXorOutputData++;
        tempData++;
        tempXorData++;
    }
}

static void DL_AES_loadDataWord(
    volatile uint32_t *pReg, const uint32_t *pData, uint8_t len)
{
    uint8_t i;
    const uint32_t *pTemp;

    pTemp = pData;

    for (i = 0; i < len; i++) {
        *pReg = *pTemp;
        pTemp++;
    }
}

static const uint32_t *DL_AES_checkAlignmentAndReturnPointer(
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

bool DL_AES_saveConfiguration(AES_Regs *aes, DL_AES_backupConfig *ptr)
{
    bool stateSaved = !ptr->backupRdy;
    if (stateSaved) {
        ptr->controlWord0   = aes->AESACTL0;
        ptr->controlWord1   = aes->AESACTL1;
        ptr->interruptMask0 = aes->CPU_INT.IMASK;
        ptr->interruptMask1 = aes->DMA_TRIG0.IMASK;
        ptr->interruptMask2 = aes->DMA_TRIG1.IMASK;
        ptr->interruptMask3 = aes->DMA_TRIG2.IMASK;
        ptr->backupRdy      = true;
    }
    return stateSaved;
}

bool DL_AES_restoreConfiguration(AES_Regs *aes, DL_AES_backupConfig *ptr)
{
    bool stateRestored = ptr->backupRdy;
    if (stateRestored) {
        aes->AESACTL0        = ptr->controlWord0;
        aes->AESACTL1        = ptr->controlWord1;
        aes->CPU_INT.IMASK   = ptr->interruptMask0;
        aes->DMA_TRIG0.IMASK = ptr->interruptMask1;
        aes->DMA_TRIG1.IMASK = ptr->interruptMask2;
        aes->DMA_TRIG2.IMASK = ptr->interruptMask3;
        ptr->backupRdy       = false;
    }
    return stateRestored;
}

#endif /* __MSPM0_HAS_AES__ */
