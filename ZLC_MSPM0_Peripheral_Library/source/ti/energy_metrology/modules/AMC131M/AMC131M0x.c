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
#include "AMC131M0x.h"
#include <string.h>

/*!
 * @brief get upper byte data
 * @param[in] uint16_Word 16 bit word
 * @return upper byte of 16 bit word
 */
uint8_t AMC_upperByteData(uint16_t uint16_Word);

/*!
 * @brief get lower byte data
 * @param[in] uint16_Word 16 bit word
 * @return lower byte of 16 bit word
 */
uint8_t  AMC_lowerByteData(uint16_t uint16_Word);

/*!
 * @brief combine 2 bytes
 * @param[in] upperByte upper byte in 16 bit word
 * @param[in] lowerByte lower byte in 16 bit word
 * @return 16 bit word
 */
uint16_t AMC_combineBytes(uint8_t upperByte, uint8_t lowerByte);

/*!
 * @brief Build array to send data
 * @param[in] amcHandle     The AMC Instance
 * @param[in] opcodeArray   The opcode array
 * @param[in] numberOpcodes The number of opcodes
 * @param[in] dataArray     The data array
 * @return Number of bytes of data
 */
uint8_t  AMC_buildSPIArray(AMC_Instance *amcHandle, const uint16_t opcodeArray[], uint8_t numberOpcodes, uint8_t byteArray[]);

/*!
 * @brief Calculate CRC
 * @param[in] crcType       The crc type
 * @param[in] dataBytes[]   The data array
 * @param[in] numberBytes   The data array length
 * @return CRC
 */
uint16_t AMC_calculateCRC(AMC_CRC_TYPE crcType, const uint8_t dataBytes[], uint8_t numberBytes);

/*!
 * @brief Combine 8 bit data to signed 32 bit
 * @param[in] amcHandle     The AMC Instance
 * @param[in] dataBytes[]   The data array
 * @return 32 bit data
 */
int32_t  AMC_signExtend(AMC_Instance *amcHandle, uint8_t dataBytes[]);

/*!
 * @brief Read AMC Register
 * @param[in] amcHandle     The AMC Instance
 * @return AMC register data
 */
uint16_t AMC_readReg(AMC_Instance *amcHandle);

/*!
 * @brief get upper byte data
 * @param[in] uint16_Word 16 bit word
 * @return upper byte of 16 bit word
 */
uint8_t AMC_upperByteData(uint16_t uint16_Word)
{
    return ((uint8_t)((uint16_Word & AMC_UPPER_BYTE_MASK) >> 8));
}

/*!
 * @brief get lower byte data
 * @param[in] uint16_Word 16 bit word
 * @return lower byte of 16 bit word
 */
uint8_t AMC_lowerByteData(uint16_t uint16_Word)
{
    return ((uint8_t)(uint16_Word & AMC_LOWER_BYTE_MASK));
}

/*!
 * @brief combine 2 bytes
 * @param[in] upperByte upper byte in 16 bit word
 * @param[in] lowerByte lower byte in 16 bit word
 * @return 16 bit word
 */
uint16_t AMC_combineBytes(uint8_t upperByte, uint8_t lowerByte)
{
    return (((uint16_t)upperByte << 8) | ((uint16_t)lowerByte));
}

/*!
 * @brief Build array to send data
 * @param[in] amcHandle     The AMC Instance
 * @param[in] opcodeArray   The opcode array
 * @param[in] numberOpcodes The number of opcodes
 * @param[in] dataArray     The data array
 * @return Number of bytes of data
 */
uint8_t AMC_buildSPIArray(AMC_Instance *amcHandle, const uint16_t opcodeArray[], uint8_t numberOpcodes, uint8_t dataArray[])
{
    /*
     * Frame size = opcode word(s) + optional CRC word
     * Number of bytes per word = 2, 3, or 4
     * Total bytes = bytes per word * number of words
     */
    uint8_t numberWords     = numberOpcodes + amcHandle->crcEnable;
    uint8_t numberOfBytes   = numberWords * AMC_WORDLENGTH;

    int i;
    for (i = 0; i < numberOpcodes; i++)
    {
        // NOTE: Be careful not to accidentally overflow the array here.
        // The array and opcodes are defined in the calling function, so
        // we are trusting that no mistakes were made in the calling function!
        dataArray[(i*AMC_WORDLENGTH) + 0] = AMC_upperByteData(opcodeArray[i]);
        dataArray[(i*AMC_WORDLENGTH) + 1] = AMC_lowerByteData(opcodeArray[i]);
    }

    if(amcHandle->crcEnable)
    {
    /* Calculate CRC and put it into TX array   */
    uint16_t crcWord = AMC_calculateCRC(amcHandle->crcType, &dataArray[0], numberOfBytes);
    dataArray[(i*AMC_WORDLENGTH) + 0] = AMC_upperByteData(crcWord);
    dataArray[(i*AMC_WORDLENGTH) + 1] = AMC_lowerByteData(crcWord);
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
uint16_t AMC_calculateCRC(AMC_CRC_TYPE crcType, const uint8_t dataBytes[], uint8_t numberBytes)
{
    int  bitIndex, byteIndex;
    bool dataMSb;    /* Most significant bit of data byte   */
    bool crcMSb;     /* Most significant bit of crc byte    */
    uint16_t poly;

    //  Initial value of crc register, NOTE: The AMC131M0x defaults to 0xFFFF,
    // but can be set at function call to continue an on-going calculation
    uint16_t crc = AMC_CRC_INITAL_VALUE;

    if(crcType == AMC_CRC_TYPE_ANSI)
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
 * @param[in] amcHandle     The AMC Instance
 * @param[in] dataBytes[]   The data array
 * @return 32 bit data
 */
int32_t AMC_signExtend(AMC_Instance *amcHandle, uint8_t dataBytes[])
{
    if(AMC_WORDLENGTH == AMC_REG_WORD_LENGTH_24BIT)
    {
        return (((int32_t) ((dataBytes[0] << 24) | (dataBytes[1] << 16) | (dataBytes[2] << 8))) >> 8);
    }
    else if(AMC_WORDLENGTH == AMC_REG_WORD_LENGTH_16BIT)
    {
        return (((int32_t) ((dataBytes[0] << 24) | (dataBytes[1] << 16))) >> 16);
    }
    else if(AMC_WORDLENGTH == AMC_REG_WORD_LENGTH_32BIT_SIGN_EXTEND)
    {
        return ((dataBytes[0] << 24) | (dataBytes[1] << 16) | (dataBytes[2] << 8) | dataBytes[3]);
    }
    else if(AMC_WORDLENGTH == AMC_REG_WORD_LENGTH_32BIT_ZERO_PADDED)
    {
        return (((int32_t) ((dataBytes[0] << 24) | (dataBytes[1] << 16) | (dataBytes[2] << 8))) >> 8);
    }
    else
    {
        return 0;
    }
}

/*!
 * @brief Read AMC Register
 * @param[in] amcHandle     The AMC Instance
 * @return AMC register data
 */
uint16_t AMC_readReg(AMC_Instance *amcHandle)
{
    HAL_SPI_CHAN chan = amcHandle->spiChan;
    HAL_SPI_CS cs = amcHandle->spiCs;

    uint8_t dataTx[AMC_BYTELENGTH] = {0};
    uint8_t dataRx[AMC_BYTELENGTH] = {0};
    uint16_t opcode = AMC_OPCODE_NULL;

    uint8_t numberOfBytes = AMC_buildSPIArray(amcHandle, &opcode, 1, dataTx);
    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes,  chan, cs);
    amcHandle->DMAWait = AMC_DMA_WAITING;
    while(amcHandle->DMAStatus != AMC_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    amcHandle->DMAStatus = AMC_DMA_TRANSFER_READY;

    return AMC_combineBytes(dataRx[0], dataRx[1]);
}

/*!
 * @brief Reset AMC
 * @param[in] amcHandle     The AMC Instance
 */
void AMC_reset(AMC_Instance *amcHandle)
{
    HAL_writeGPIOPin(amcHandle->sync, HAL_GPIO_PIN_LOW);
    HAL_delayMicroSeconds(300);
    HAL_writeGPIOPin(amcHandle->sync, HAL_GPIO_PIN_HIGH);
    HAL_delayMicroSeconds(35);
}

/*!
 * @brief Sync AMC
 * @param[in] amcHandle     The AMC Instance
 */
void AMC_toggleSYNC(AMC_Instance *amcHandle)
{
    HAL_writeGPIOPin(amcHandle->sync, HAL_GPIO_PIN_LOW);
    HAL_delayMicroSeconds(1);
    HAL_writeGPIOPin(amcHandle->sync, HAL_GPIO_PIN_HIGH);
}

/*!
 * @brief AMC initialization
 * @param[in] amcHandle     The AMC Instance
 * @return status
 */
bool AMC_init(AMC_Instance *amcHandle)
{
    AMC_reset(amcHandle);
    AMC_unlockRegisters(amcHandle);

    AMC_initalizeAMCRegisters(amcHandle);

    return true;
}

/*!
 * @brief Start Data Collection
 * @param[in] amcHandle     The AMC Instance
 */
void AMC_startDataCollection(AMC_Instance *amcHandle)
{
    AMC_toggleSYNC(amcHandle);

    HAL_enableGPIOInterrupt(amcHandle->ready);

    amcHandle->datacollectionStatus = 1;
}

/*!
 * @brief Start DMA Transfer
 * @param[in] amcHandle     The AMC Instance
 */
void AMC_startDMADataTransfer(AMC_Instance *amcHandle)
{
    HAL_SPI_CHAN chan = amcHandle->spiChan;
    HAL_SPI_CS cs = amcHandle->spiCs;

    uint8_t dataTx[AMC_BYTELENGTH] = {0};

    HAL_startSPIDataTransfer(dataTx, amcHandle->rawdata, AMC_BYTELENGTH, chan, cs);
}

/*!
 * @brief Get AMC Channel Data
 * @param[in] amcHandle     The AMC Instance
 */
void AMC_getChannelData(AMC_Instance *amcHandle)
{
    AMC_channelData *amcData = &amcHandle->channelData;

    amcData->response = amcHandle->rawdata[0] << 8 | amcHandle->rawdata[1];

#if AMC_CHANNELCOUNT > 0
    amcData->chan0 = AMC_signExtend(amcHandle, &amcHandle->rawdata[(AMC_CMDLENGTH + 0) * AMC_WORDLENGTH]);
#endif

#if AMC_CHANNELCOUNT > 1
    amcData->chan1 = AMC_signExtend(amcHandle, &amcHandle->rawdata[(AMC_CMDLENGTH + 1) * AMC_WORDLENGTH]);
#endif

#if AMC_CHANNELCOUNT > 2
    amcData->chan2 = AMC_signExtend(amcHandle, &amcHandle->rawdata[(AMC_CMDLENGTH + 2) * AMC_WORDLENGTH]);
#endif

#if AMC_CHANNELCOUNT > 3
    amcData->chan3 = AMC_signExtend(amcHandle, &amcHandle->rawdata[(AMC_CMDLENGTH + 3) * AMC_WORDLENGTH]);
#endif

#if AMC_CHANNELCOUNT > 4
    amcData->chan4 = AMC_signExtend(amcHandle, &amcHandle->rawdata[(AMC_CMDLENGTH + 4) * AMC_WORDLENGTH]);
#endif

#if AMC_CHANNELCOUNT > 5
    amcData->chan5 = AMC_signExtend(amcHandle, &amcHandle->rawdata[(AMC_CMDLENGTH + 5) * AMC_WORDLENGTH]);
#endif

#if AMC_CHANNELCOUNT > 6
    amcData->chan6 = AMC_signExtend(amcHandle, &amcHandle->rawdata[(AMC_CMDLENGTH + 6) * AMC_WORDLENGTH]);
#endif

#if AMC_CHANNELCOUNT > 7
    amcData->chan7 = AMC_signExtend(amcHandle, &amcHandle->rawdata[(AMC_CMDLENGTH + 7) * AMC_WORDLENGTH]);
#endif
    amcData->crc = amcHandle->rawdata[(AMC_CMDLENGTH + AMC_CHANNELCOUNT) * AMC_WORDLENGTH] << 8 | amcHandle->rawdata[(AMC_CMDLENGTH + AMC_CHANNELCOUNT) * AMC_WORDLENGTH + 1];

    AMC_verifyAMCCRC(amcHandle, amcData);
}

/*!
 * @brief Initialize AMC Registers
 * @param[in] amcHandle     The AMC Instance
 */
void AMC_initalizeAMCRegisters(AMC_Instance *amcHandle)
{
    HAL_SPI_CHAN chan = amcHandle->spiChan;
    HAL_SPI_CS cs = amcHandle->spiCs;

    uint8_t dataTx[(NUM_REGISTERS + 1 + 1) * AMC_WORDLENGTH] = {0};
    uint8_t dataRx[(NUM_REGISTERS + 1 + 1) * AMC_WORDLENGTH] = {0};
    uint8_t numberOfBytes = AMC_buildSPIArray(amcHandle, &amcHandle->AMC_initRegData[0], (NUM_REGISTERS + 1), dataTx);

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    amcHandle->DMAWait = AMC_DMA_WAITING;
    while(amcHandle->DMAStatus != AMC_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    amcHandle->DMAStatus = AMC_DMA_TRANSFER_READY;
}

/*!
 * @brief Wakeup AMC
 * @param[in] amcHandle     The AMC Instance
 */
void AMC_wakeupCommand(AMC_Instance *amcHandle)
{
    HAL_SPI_CHAN chan = amcHandle->spiChan;
    HAL_SPI_CS cs = amcHandle->spiCs;

    uint8_t dataTx[AMC_BYTELENGTH] = {0};
    uint8_t dataRx[AMC_BYTELENGTH] = {0};
    uint16_t opcode = AMC_OPCODE_WAKEUP;
    uint8_t numberOfBytes = AMC_buildSPIArray(amcHandle, &opcode, 1, dataTx);

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    amcHandle->DMAWait = AMC_DMA_WAITING;
    while(amcHandle->DMAStatus != AMC_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    amcHandle->DMAStatus = AMC_DMA_TRANSFER_READY;
}

/*!
 * @brief AMC standby mode
 * @param[in] amcHandle     The AMC Instance
 */
void AMC_standbymode(AMC_Instance *amcHandle)
{
    HAL_SPI_CHAN chan = amcHandle->spiChan;
    HAL_SPI_CS cs = amcHandle->spiCs;

    uint8_t dataTx[AMC_BYTELENGTH] = {0};
    uint8_t dataRx[AMC_BYTELENGTH] = {0};
    uint16_t opcode = AMC_OPCODE_STANDBY;
    uint8_t numberOfBytes = AMC_buildSPIArray(amcHandle, &opcode, 1, dataTx);

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    amcHandle->DMAWait = AMC_DMA_WAITING;
    while(amcHandle->DMAStatus != AMC_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    amcHandle->DMAStatus = AMC_DMA_TRANSFER_READY;
}

/*!
 * @brief Unlock AMC Registers
 * @param[in] amcHandle     The AMC Instance
 * @return Register status
 */
bool AMC_unlockRegisters(AMC_Instance *amcHandle)
{
    HAL_SPI_CHAN chan = amcHandle->spiChan;
    HAL_SPI_CS cs = amcHandle->spiCs;

    uint8_t dataTx[AMC_BYTELENGTH] = {0};
    uint8_t dataRx[AMC_BYTELENGTH] = {0};
    uint16_t opcode = AMC_OPCODE_UNLOCK;
    uint8_t numberOfBytes = AMC_buildSPIArray(amcHandle, &opcode, 1, dataTx);

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);

    amcHandle->DMAWait = AMC_DMA_WAITING;
    while(amcHandle->DMAStatus != AMC_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    amcHandle->DMAStatus = AMC_DMA_TRANSFER_READY;
    uint16_t statusRegData = AMC_readReg(amcHandle);

    if(!(statusRegData & STATUS_LOCK_MASK))
    {
        return false;
    }
    return true;
}

/*!
 * @brief Lock AMC Registers
 * @param[in] amcHandle     The AMC Instance
 * @return Register status
 */
bool AMC_lockRegisters(AMC_Instance *amcHandle)
{
    HAL_SPI_CHAN chan = amcHandle->spiChan;
    HAL_SPI_CS cs = amcHandle->spiCs;

    uint8_t dataTx[AMC_BYTELENGTH] = {0};
    uint8_t dataRx[AMC_BYTELENGTH] = {0};
    AMC_OPCODES opcode = AMC_OPCODE_LOCK;
    uint8_t numberOfBytes = AMC_buildSPIArray(amcHandle, &opcode, 1, dataTx);

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes,  chan, cs);
    amcHandle->DMAWait = AMC_DMA_WAITING;
    while(amcHandle->DMAStatus != AMC_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    amcHandle->DMAStatus = AMC_DMA_TRANSFER_READY;
    uint16_t statusRegData = AMC_readReg(amcHandle);

    if(statusRegData & STATUS_LOCK_MASK)
    {
        return false;
    }
    return true;
}

/*!
 * @brief Reset AMC
 * @param[in] amcHandle     The AMC Instance
 */
void AMC_resetDevice(AMC_Instance *amcHandle)
{
    HAL_SPI_CHAN chan = amcHandle->spiChan;
    HAL_SPI_CS cs = amcHandle->spiCs;

    uint8_t dataTx[AMC_BYTELENGTH] = {0};
    uint8_t dataRx[AMC_BYTELENGTH] = {0};
    uint16_t opcode[10] = {0};
    opcode[0] = AMC_OPCODE_RESET;
    uint8_t numberOfBytes = AMC_buildSPIArray(amcHandle, &opcode[0], 10, dataTx);

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    amcHandle->DMAWait = AMC_DMA_WAITING;
    while(amcHandle->DMAStatus != AMC_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    amcHandle->DMAStatus = AMC_DMA_TRANSFER_READY;
}

/*!
 * @brief Write to a single register
 * @param[in] amcHandle     The AMC Instance
 * @param[in] regAddr       The register address
 * @param[in] data          Data to be written
 * @param[in] readCheck     write check
 * @return Write status
 */
bool AMC_writeSingleSPIReg(AMC_Instance *amcHandle, uint8_t regAddr, uint16_t data, bool readCheck)
{
    HAL_SPI_CHAN chan = amcHandle->spiChan;
    HAL_SPI_CS cs = amcHandle->spiCs;

    uint8_t dataTx[AMC_BYTELENGTH] = {0};
    uint8_t dataRx[AMC_BYTELENGTH] = {0};
    uint16_t opcodes[2] = { 0 };
    opcodes[0] = AMC_OPCODE_WREG | (((uint16_t) regAddr) << 7);
    opcodes[1] = data;
    uint8_t numberOfBytes = AMC_buildSPIArray(amcHandle, &opcodes[0], 2, dataTx);

    HAL_startSPIDataTransfer(dataTx, dataRx, numberOfBytes, chan, cs);
    amcHandle->DMAWait = AMC_DMA_WAITING;
    while(amcHandle->DMAStatus != AMC_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    amcHandle->DMAStatus = AMC_DMA_TRANSFER_READY;

    if ( readCheck )
    {
        uint16_t dataRead = AMC_readSingleSPIReg(amcHandle, regAddr);
        if ( data != dataRead )
        {
            return false;
        }
    }
    return true;
}

/*!
 * @brief Read a single register
 * @param[in] amcHandle     The AMC Instance
 * @param[in] regAddr       The register address
 * @return Register Data
 */
uint16_t AMC_readSingleSPIReg(AMC_Instance *amcHandle, uint8_t regAddr)
{
    HAL_SPI_CHAN chan = amcHandle->spiChan;
    HAL_SPI_CS cs = amcHandle->spiCs;

    uint8_t datax[AMC_BYTELENGTH] = {0};
    uint8_t dataRx[AMC_BYTELENGTH] = {0};
    uint16_t opcode = 0;
    opcode = AMC_OPCODE_RREG | (((uint16_t) regAddr) << 7);
    uint8_t numberOfBytes = AMC_buildSPIArray(amcHandle, &opcode, 1, datax);

    HAL_startSPIDataTransfer(datax, dataRx, numberOfBytes, chan, cs);
    amcHandle->DMAWait = AMC_DMA_WAITING;
    while(amcHandle->DMAStatus != AMC_DMA_TRANSFER_DONE)
    {
        __WFE();
    }
    amcHandle->DMAStatus = AMC_DMA_TRANSFER_READY;
    return AMC_readReg(amcHandle);
}

/*!
 * @brief verify CRC for channel data
 * @param[in] amcHandle   The AMC Instance
 * @param[in] amcData     The AMC channel data
 */
void AMC_verifyAMCCRC(AMC_Instance *amcHandle, AMC_channelData *amcData)
{
    /* HW CRC check */
    volatile uint16_t CRCResult;

    HAL_setCRCSeed(HAL_CRC_0, 0xFFFF);

    memcpy((void*) CRC_IN_ADDRESS, &amcHandle->rawdata, (AMC_CMDLENGTH + AMC_CHANNELCOUNT) * AMC_WORDLENGTH);
    CRCResult = HAL_getCRCOut(HAL_CRC_0);
    if(amcData->crc == CRCResult)
    {
        amcHandle->crcPassCount++;
    }
    else
    {
        amcHandle->crcFailCount++;
    }

    /* SW CRC ckeck */
    /*
    volatile uint16_t crcWord;
    crcWord = AMC_calculateCRC(amcHandle->crcType, amcHandle->rawdata, (AMC_CMDLENGTH + AMC_CHANNELCOUNT) * AMC_WORDLENGTH);
    if (!crcWord)
    {
        amcHandle->crcFailCount++;
    }
    else
    {
        amcHandle->crcPassCount++;
    }
    */
}
