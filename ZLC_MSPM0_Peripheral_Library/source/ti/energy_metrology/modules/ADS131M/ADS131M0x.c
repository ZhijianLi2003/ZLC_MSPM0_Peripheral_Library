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

//*****************************************************************************
// the includes
//*****************************************************************************
#include "ADS131M0x.h"
#include <string.h>

/*!
 * @brief get upper byte data
 * @param[in] uint16_Word 16 bit word
 * @return upper byte of 16 bit word
 */
uint8_t ADS_upperByteData(uint16_t uint16_Word);

/*!
 * @brief get lower byte data
 * @param[in] uint16_Word 16 bit word
 * @return lower byte of 16 bit word
 */
uint8_t  ADS_lowerByteData(uint16_t uint16_Word);

/*!
 * @brief combine 2 bytes
 * @param[in] upperByte upper byte in 16 bit word
 * @param[in] lowerByte lower byte in 16 bit word
 * @return 16 bit word
 */
uint16_t ADS_combineBytes(uint8_t upperByte, uint8_t lowerByte);

/*!
 * @brief Build array to send data
 * @param[in] adsHandle     The ADS Instance
 * @param[in] opcodeArray   The opcode array
 * @param[in] numberOpcodes The number of opcodes
 * @param[in] dataArray     The data array
 * @param[in] dataArraySize The data array size
 * @return Number of bytes of data
 */
uint8_t  ADS_buildSPIArray(ADS_Instance *adsHandle, const uint16_t opcodeArray[], uint8_t numberOpcodes, uint8_t byteArray[], uint8_t dataArraySize);

/*!
 * @brief Calculate CRC
 * @param[in] crcType       The crc type
 * @param[in] dataBytes[]   The data array
 * @param[in] numberBytes   The data array length
 * @return CRC
 */
uint16_t ADS_calculateCRC(ADS_CRC_TYPE crcType, const uint8_t dataBytes[], uint8_t numberBytes);

/*!
 * @brief Combine 8 bit data to signed 32 bit
 * @param[in] adsHandle     The ADS Instance
 * @param[in] dataBytes[]   The data array
 * @return 32 bit data
 */
int32_t  ADS_signExtend(ADS_Instance *adsHandle, uint8_t dataBytes[]);

/*!
 * @brief Read ADS Register
 * @param[in] adsHandle     The ADS Instance
 * @return ADS register data
 */
uint16_t ADS_readReg(ADS_Instance *adsHandle);

/*!
 * @brief get upper byte data
 * @param[in] uint16_Word 16 bit word
 * @return upper byte of 16 bit word
 */
uint8_t ADS_upperByteData(uint16_t uint16_Word)
{
    return ((uint8_t)((uint16_Word & ADS_UPPER_BYTE_MASK) >> 8));
}

/*!
 * @brief get lower byte data
 * @param[in] uint16_Word 16 bit word
 * @return lower byte of 16 bit word
 */
uint8_t ADS_lowerByteData(uint16_t uint16_Word)
{
    return ((uint8_t)(uint16_Word & ADS_LOWER_BYTE_MASK));
}

/*!
 * @brief combine 2 bytes
 * @param[in] upperByte upper byte in 16 bit word
 * @param[in] lowerByte lower byte in 16 bit word
 * @return 16 bit word
 */
uint16_t ADS_combineBytes(uint8_t upperByte, uint8_t lowerByte)
{
    return (((uint16_t)upperByte << 8) | ((uint16_t)lowerByte));
}

/*!
 * @brief Build array to send data
 * @param[in] adsHandle     The ADS Instance
 * @param[in] opcodeArray   The opcode array
 * @param[in] numberOpcodes The number of opcodes
 * @param[in] dataArray     The data array
 * @param[in] dataArraySize The data array size
 * @return Number of bytes of data
 */
uint8_t ADS_buildSPIArray(ADS_Instance *adsHandle, const uint16_t opcodeArray[], uint8_t numberOpcodes, uint8_t dataArray[], uint8_t dataArraySize)
{
    /*
     * Frame size = opcode word(s) + optional CRC word
     * Number of bytes per word = 2, 3, or 4
     * Total bytes = bytes per word * number of words
     */
    uint8_t numberWords     = numberOpcodes + adsHandle->crcEnable;
    uint8_t numberOfBytes   = numberWords * ADS_WORDLENGTH;

    int i;
    for (i = 0; ((i < numberOpcodes) && (i < dataArraySize/ADS_WORDLENGTH)); i++)
    {
        // NOTE: Be careful not to accidentally overflow the array here.
        // The array and opcodes are defined in the calling function, so
        // we are trusting that no mistakes were made in the calling function!
        dataArray[(i*ADS_WORDLENGTH) + 0] = ADS_upperByteData(opcodeArray[i]);
        dataArray[(i*ADS_WORDLENGTH) + 1] = ADS_lowerByteData(opcodeArray[i]);
    }

    if(adsHandle->crcEnable)
    {
    /* Calculate CRC and put it into TX array   */
    uint16_t crcWord = ADS_calculateCRC(adsHandle->crcType, &dataArray[0], numberOfBytes);
    dataArray[(i*ADS_WORDLENGTH) + 0] = ADS_upperByteData(crcWord);
    dataArray[(i*ADS_WORDLENGTH) + 1] = ADS_lowerByteData(crcWord);
    }

    return( numberOfBytes );
}

/*!
 * @brief Calculate CRC
 * @param[in] crcType       The crc type
 * @param[in] dataBytes[]   The data array
 * @param[in] numberBytes   The data array length
 * @return CRC
 */
uint16_t ADS_calculateCRC(ADS_CRC_TYPE crcType, const uint8_t dataBytes[], uint8_t numberBytes)
{
    int  bitIndex, byteIndex;
    bool dataMSb;    /* Most significant bit of data byte   */
    bool crcMSb;     /* Most significant bit of crc byte    */
    uint16_t poly;

    //  Initial value of crc register, NOTE: The ADS131M0x defaults to 0xFFFF,
    // but can be set at function call to continue an on-going calculation
    uint16_t crc = ADS_CRC_INITAL_VALUE;

    if(crcType == ADS_CRC_TYPE_ANSI)
    {
        /* ANSI CRC polynomial = x^16 + x^12 + x^5 + 1  */
        poly = 0x8005;
    }
    else
    {
        /* CCITT CRC polynomial = x^16 + x^15 + x^2 + 1 */
        poly = 0x1021;
    }

    /*
     * CRC Algorithm
     */
    /* Loop through all bytes in dataBytes arrray   */
    for(byteIndex = 0; byteIndex < numberBytes; byteIndex++)
    {
        /* Point to MSb in byte */
        bitIndex = 0x80u;

        /* Loop through all bits in the current byte    */
        while (bitIndex > 0)
        {
            /* Check MSB's of data and crc  */
            dataMSb = (bool) (dataBytes[byteIndex] & bitIndex);
            crcMSb  = (bool) (crc & 0x8000u);

            /* Left shift CRC register */
            crc <<= 1;

            /* Check if XOR operation of MSBs results in additional XOR operations  */
            if (dataMSb ^ crcMSb)
            {
                /* XOR crc with polynomial */
                crc ^= poly;
            }
            /* Shift MSB pointer to the next data bit   */
            bitIndex >>= 1;
        }
    }
    return (crc);
}

/*!
 * @brief Combine 8 bit data to signed 32 bit
 * @param[in] adsHandle     The ADS Instance
 * @param[in] dataBytes[]   The data array
 * @return 32 bit data
 */
int32_t ADS_signExtend(ADS_Instance *adsHandle, uint8_t dataBytes[])
{
    if(ADS_WORDLENGTH == ADS_REG_WORD_LENGTH_24BIT)
    {
        return (((int32_t) ((dataBytes[0] << 24) | (dataBytes[1] << 16) | (dataBytes[2] << 8))) >> 8);
    }
    else if(ADS_WORDLENGTH == ADS_REG_WORD_LENGTH_16BIT)
    {
        return (((int32_t) ((dataBytes[0] << 24) | (dataBytes[1] << 16))) >> 16);
    }
    else if(ADS_WORDLENGTH == ADS_REG_WORD_LENGTH_32BIT_SIGN_EXTEND)
    {
        return ((dataBytes[0] << 24) | (dataBytes[1] << 16) | (dataBytes[2] << 8) | dataBytes[3]);
    }
    else if(ADS_WORDLENGTH == ADS_REG_WORD_LENGTH_32BIT_ZERO_PADDED)
    {
        return (((int32_t) ((dataBytes[0] << 24) | (dataBytes[1] << 16) | (dataBytes[2] << 8))) >> 8);
    }
    else
    {
        return 0;
    }
}

/*!
 * @brief Read ADS Register
 * @param[in] adsHandle     The ADS Instance
 * @return ADS register data
 */
uint16_t ADS_readReg(ADS_Instance *adsHandle)
{
    HAL_SPI_CHAN chan = adsHandle->spiChan;
    HAL_SPI_CS cs = adsHandle->spiCs;

    uint8_t dataTx[ADS_BYTELENGTH] = {0};
    uint8_t dataRx[ADS_BYTELENGTH] = {0};
    uint16_t opcode = ADS_OPCODE_NULL;

    uint8_t numberOfBytes = ADS_buildSPIArray(adsHandle, &opcode, 1, dataTx, sizeof(dataTx));
    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes,  chan, cs);
    adsHandle->DMAWait = ADS_DMA_WAITING;
    while(adsHandle->DMAStatus != ADS_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    adsHandle->DMAStatus = ADS_DMA_TRANSFER_READY;

    return ADS_combineBytes(dataRx[0], dataRx[1]);
}

/*!
 * @brief Reset ADS
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_reset(ADS_Instance *adsHandle)
{
    HAL_writeGPIOPin(adsHandle->sync, HAL_GPIO_PIN_LOW);
    HAL_delayMicroSeconds(300);
    HAL_writeGPIOPin(adsHandle->sync, HAL_GPIO_PIN_HIGH);
    HAL_delayMicroSeconds(35);
}

/*!
 * @brief Sync ADS
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_toggleSYNC(ADS_Instance *adsHandle)
{
    HAL_writeGPIOPin(adsHandle->sync, HAL_GPIO_PIN_LOW);
    HAL_delayMicroSeconds(1);
    HAL_writeGPIOPin(adsHandle->sync, HAL_GPIO_PIN_HIGH);
}

/*!
 * @brief ADS initialization
 * @param[in] adsHandle     The ADS Instance
 * @return status
 */
bool ADS_init(ADS_Instance *adsHandle)
{
    ADS_reset(adsHandle);
    if(!ADS_unlockRegisters(adsHandle))
    {
        return false;
    }
    ADS_initalizeADSRegisters(adsHandle);

    return true;
}

/*!
 * @brief Start Data Collection
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_startDataCollection(ADS_Instance *adsHandle)
{
    ADS_toggleSYNC(adsHandle);

    HAL_enableGPIOInterrupt(adsHandle->ready);

    adsHandle->datacollectionStatus = 1;
}

/*!
 * @brief Start DMA Transfer
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_startDMADataTransfer(ADS_Instance *adsHandle)
{
    HAL_SPI_CHAN chan = adsHandle->spiChan;
    HAL_SPI_CS cs = adsHandle->spiCs;

    uint8_t dataTx[ADS_BYTELENGTH] = {0};

    HAL_startSPIDataTransfer(dataTx, adsHandle->rawdata, ADS_BYTELENGTH, chan, cs);
}

/*!
 * @brief Get ADS Channel Data
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_getChannelData(ADS_Instance *adsHandle)
{
    ADS_channelData *adsData = &adsHandle->channelData;

    adsData->response = adsHandle->rawdata[0] << 8 | adsHandle->rawdata[1];

#if ADS_CHANNELCOUNT > 0
    adsData->chan0 = ADS_signExtend(adsHandle, &adsHandle->rawdata[(ADS_CMDLENGTH + 0) * ADS_WORDLENGTH]);
#endif

#if ADS_CHANNELCOUNT > 1
    adsData->chan1 = ADS_signExtend(adsHandle, &adsHandle->rawdata[(ADS_CMDLENGTH + 1) * ADS_WORDLENGTH]);
#endif

#if ADS_CHANNELCOUNT > 2
    adsData->chan2 = ADS_signExtend(adsHandle, &adsHandle->rawdata[(ADS_CMDLENGTH + 2) * ADS_WORDLENGTH]);
#endif

#if ADS_CHANNELCOUNT > 3
    adsData->chan3 = ADS_signExtend(adsHandle, &adsHandle->rawdata[(ADS_CMDLENGTH + 3) * ADS_WORDLENGTH]);
#endif

#if ADS_CHANNELCOUNT > 4
    adsData->chan4 = ADS_signExtend(adsHandle, &adsHandle->rawdata[(ADS_CMDLENGTH + 4) * ADS_WORDLENGTH]);
#endif

#if ADS_CHANNELCOUNT > 5
    adsData->chan5 = ADS_signExtend(adsHandle, &adsHandle->rawdata[(ADS_CMDLENGTH + 5) * ADS_WORDLENGTH]);
#endif

#if ADS_CHANNELCOUNT > 6
    adsData->chan6 = ADS_signExtend(adsHandle, &adsHandle->rawdata[(ADS_CMDLENGTH + 6) * ADS_WORDLENGTH]);
#endif

#if ADS_CHANNELCOUNT > 7
    adsData->chan7 = ADS_signExtend(adsHandle, &adsHandle->rawdata[(ADS_CMDLENGTH + 7) * ADS_WORDLENGTH]);
#endif

    adsData->crc = adsHandle->rawdata[(ADS_CMDLENGTH + ADS_CHANNELCOUNT) * ADS_WORDLENGTH] << 8 | adsHandle->rawdata[(ADS_CMDLENGTH + ADS_CHANNELCOUNT) * ADS_WORDLENGTH + 1];

    ADS_verifyADSCRC(adsHandle, adsData);
}

/*!
 * @brief Initialize ADS Registers
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_initalizeADSRegisters(ADS_Instance *adsHandle)
{
    HAL_SPI_CHAN chan = adsHandle->spiChan;
    HAL_SPI_CS cs = adsHandle->spiCs;

    uint8_t dataTx[(NUM_REGISTERS + 1 + 1) * ADS_WORDLENGTH] = {0};
    uint8_t dataRx[(NUM_REGISTERS + 1 + 1) * ADS_WORDLENGTH] = {0};
    uint8_t numberOfBytes = ADS_buildSPIArray(adsHandle, &adsHandle->ADS_initRegData[0], (NUM_REGISTERS + 1), dataTx, sizeof(dataTx));

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    adsHandle->DMAWait = ADS_DMA_WAITING;
    while(adsHandle->DMAStatus != ADS_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    adsHandle->DMAStatus = ADS_DMA_TRANSFER_READY;
}

/*!
 * @brief Wakeup ADS
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_wakeupCommand(ADS_Instance *adsHandle)
{
    HAL_SPI_CHAN chan = adsHandle->spiChan;
    HAL_SPI_CS cs = adsHandle->spiCs;

    uint8_t dataTx[ADS_BYTELENGTH] = {0};
    uint8_t dataRx[ADS_BYTELENGTH] = {0};
    uint16_t opcode = ADS_OPCODE_WAKEUP;
    uint8_t numberOfBytes = ADS_buildSPIArray(adsHandle, &opcode, 1, dataTx, sizeof(dataTx));

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    adsHandle->DMAWait = ADS_DMA_WAITING;
    while(adsHandle->DMAStatus != ADS_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    adsHandle->DMAStatus = ADS_DMA_TRANSFER_READY;
}

/*!
 * @brief ADS standby mode
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_standbymode(ADS_Instance *adsHandle)
{
    HAL_SPI_CHAN chan = adsHandle->spiChan;
    HAL_SPI_CS cs = adsHandle->spiCs;

    uint8_t dataTx[ADS_BYTELENGTH] = {0};
    uint8_t dataRx[ADS_BYTELENGTH] = {0};
    uint16_t opcode = ADS_OPCODE_STANDBY;
    uint8_t numberOfBytes = ADS_buildSPIArray(adsHandle, &opcode, 1, dataTx, sizeof(dataTx));

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    adsHandle->DMAWait = ADS_DMA_WAITING;
    while(adsHandle->DMAStatus != ADS_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    adsHandle->DMAStatus = ADS_DMA_TRANSFER_READY;
}

/*!
 * @brief Unlock ADS Registers
 * @param[in] adsHandle     The ADS Instance
 * @return Register status
 */
bool ADS_unlockRegisters(ADS_Instance *adsHandle)
{
    HAL_SPI_CHAN chan = adsHandle->spiChan;
    HAL_SPI_CS cs = adsHandle->spiCs;

    uint8_t dataTx[ADS_BYTELENGTH] = {0};
    uint8_t dataRx[ADS_BYTELENGTH] = {0};
    uint16_t opcode = ADS_OPCODE_UNLOCK;
    uint8_t numberOfBytes = ADS_buildSPIArray(adsHandle, &opcode, 1, dataTx, sizeof(dataTx));

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    adsHandle->DMAWait = ADS_DMA_WAITING;
    while(adsHandle->DMAStatus != ADS_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    adsHandle->DMAStatus = ADS_DMA_TRANSFER_READY;
    uint16_t statusRegData = ADS_readReg(adsHandle);
    if(statusRegData & STATUS_LOCK_MASK)
    {
        return false;
    }
    return true;
}

/*!
 * @brief Lock ADS Registers
 * @param[in] adsHandle     The ADS Instance
 * @return Register status
 */
bool ADS_lockRegisters(ADS_Instance *adsHandle)
{
    HAL_SPI_CHAN chan = adsHandle->spiChan;
    HAL_SPI_CS cs = adsHandle->spiCs;

    uint8_t dataTx[ADS_BYTELENGTH] = {0};
    uint8_t dataRx[ADS_BYTELENGTH] = {0};
    ADS_OPCODES opcode = ADS_OPCODE_LOCK;
    uint8_t numberOfBytes = ADS_buildSPIArray(adsHandle, &opcode, 1, dataTx, sizeof(dataTx));

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes,  chan, cs);
    adsHandle->DMAWait = ADS_DMA_WAITING;
    while(adsHandle->DMAStatus != ADS_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    adsHandle->DMAStatus = ADS_DMA_TRANSFER_READY;
    uint16_t statusRegData = ADS_readReg(adsHandle);

    if(!(statusRegData & STATUS_LOCK_MASK))
    {
        return false;
    }
    return true;
}

/*!
 * @brief Reset ADS
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_resetDevice(ADS_Instance *adsHandle)
{
    HAL_SPI_CHAN chan = adsHandle->spiChan;
    HAL_SPI_CS cs = adsHandle->spiCs;

    uint8_t dataTx[ADS_BYTELENGTH] = {0};
    uint8_t dataRx[ADS_BYTELENGTH] = {0};
    uint16_t opcode[10] = {0};
    opcode[0] = ADS_OPCODE_RESET;
    uint8_t numberOfBytes = ADS_buildSPIArray(adsHandle, &opcode[0], 10, dataTx, sizeof(dataTx));

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    adsHandle->DMAWait = ADS_DMA_WAITING;
    while(adsHandle->DMAStatus != ADS_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    adsHandle->DMAStatus = ADS_DMA_TRANSFER_READY;
}

/*!
 * @brief Write to a single register
 * @param[in] adsHandle     The ADS Instance
 * @param[in] regAddr       The register address
 * @param[in] data          Data to be written
 * @param[in] readCheck     write check
 * @return Write status
 */
bool ADS_writeSingleSPIReg(ADS_Instance *adsHandle, uint8_t regAddr, uint16_t data, bool readCheck)
{
    HAL_SPI_CHAN chan = adsHandle->spiChan;
    HAL_SPI_CS cs = adsHandle->spiCs;

    uint8_t dataTx[ADS_BYTELENGTH] = {0};
    uint8_t dataRx[ADS_BYTELENGTH] = {0};
    uint16_t opcodes[2] = { 0 };
    opcodes[0] = ADS_OPCODE_WREG | (((uint16_t) regAddr) << 7);
    opcodes[1] = data;
    uint8_t numberOfBytes = ADS_buildSPIArray(adsHandle, &opcodes[0], 2, dataTx, sizeof(dataTx));

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    adsHandle->DMAWait = ADS_DMA_WAITING;
    while(adsHandle->DMAStatus != ADS_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    adsHandle->DMAStatus = ADS_DMA_TRANSFER_READY;

    if ( readCheck )
    {
        uint16_t dataRead = ADS_readSingleSPIReg(adsHandle, regAddr);
        if ( data != dataRead )
        {
            return false;
        }
    }
    return true;
}

/*!
 * @brief Read a single register
 * @param[in] adsHandle     The ADS Instance
 * @param[in] regAddr       The register address
 * @return Register Data
 */
uint16_t ADS_readSingleSPIReg(ADS_Instance *adsHandle, uint8_t regAddr)
{
    HAL_SPI_CHAN chan = adsHandle->spiChan;
    HAL_SPI_CS cs = adsHandle->spiCs;

    uint8_t dataTx[ADS_BYTELENGTH] = {0};
    uint8_t dataRx[ADS_BYTELENGTH] = {0};
    uint16_t opcode = 0;
    opcode = ADS_OPCODE_RREG | (((uint16_t) regAddr) << 7);
    uint8_t numberOfBytes = ADS_buildSPIArray(adsHandle, &opcode, 1, dataTx, sizeof(dataTx));

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    adsHandle->DMAWait = ADS_DMA_WAITING;
    while(adsHandle->DMAStatus != ADS_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    adsHandle->DMAStatus = ADS_DMA_TRANSFER_READY;
    return ADS_readReg(adsHandle);
}

/*!
 * @brief verify CRC for channel data
 * @param[in] adsHandle   The ADS Instance
 * @param[in] adsData     The ADS channel data
 */
void ADS_verifyADSCRC(ADS_Instance *adsHandle, ADS_channelData *adsData)
{
    /* HW CRC check */
    volatile uint16_t CRCResult;

    HAL_setCRCSeed(HAL_CRC_0, 0xFFFF);

    memcpy((void*) CRC_IN_ADDRESS, &adsHandle->rawdata, (ADS_CMDLENGTH + ADS_CHANNELCOUNT) * ADS_WORDLENGTH);
    CRCResult = HAL_getCRCOut(HAL_CRC_0);
    if(adsData->crc == CRCResult)
    {
        adsHandle->crcPassCount++;
    }
    else
    {
        adsHandle->crcFailCount++;
    }

    /* SW CRC ckeck */
    /*
    volatile uint16_t crcWord;
    crcWord = ADS_calculateCRC(adsHandle->crcType, adsHandle->rawdata, (ADS_CMDLENGTH + ADS_CHANNELCOUNT) * ADS_WORDLENGTH);
    if (!crcWord)
    {
        adsHandle->crcFailCount++;
    }
    else
    {
        adsHandle->crcPassCount++;
    }
    */
}












