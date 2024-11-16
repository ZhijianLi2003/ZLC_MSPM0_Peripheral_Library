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

#include "DLT645.h"

uint8_t commStatus;

/*!
 * @brief Finds upper 16 bits of 32 bit value
 * @param[in] value 32 bit value
 * @return upper 16 bits of given 32 bit value
 */
uint16_t __attribute__((section(".TI.ramfunc"))) DLT645_findHigh16(uint32_t value);

/*!
 * @brief Finds lower 16 bits of 32 bit value
 * @param[in] value 32 bit value
 * @return lower 16 bits of given 32 bit value
 */
uint16_t __attribute__((section(".TI.ramfunc"))) DLT645_findLow16(uint32_t value);

/*!
 * @brief Write data over UART
 * @param[in] dlt645 The dlt645 instance
 * @param[in] len    Length of array
 */
void __attribute__((section(".TI.ramfunc"))) DLT645_serialWrite(DLT645Buf *dlt645, uint8_t len);

/*!
 * @brief Configure serial communication
 * @param[in] dlt645 The dlt645 instance
 */
void __attribute__((section(".TI.ramfunc"))) DLT645_serialConfigure(DLT645Buf *dlt645);

/*!
 * @brief Prepare transfer message
 * @param[in] dlt645 The dlt645 instance
 * @param[in] len    Length of array
 */
int __attribute__((section(".TI.ramfunc"))) DLT645_prepareTxMessage(DLT645Buf *dlt645, uint8_t len);

/*!
 * @brief Send Aggregate consumption report
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendAggregateConsumptionReport(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg);

/*!
 * @brief Send phase readings report
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 * @param[in] ph          The phase number
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendPhaseReadingsReport(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg, PHASES ph);

/*!
 * @brief Send phase extra readings report
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 * @param[in] ph          The phase number
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendPhaseExtraReadingsReport(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg, PHASES ph);

/*!
 * @brief Send neutral readings
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendNeutralReadings(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg);

/*!
 * @brief Send neutral extra readings report
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendNeutralExtraReadingsReport(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg);

/*!
 * @brief Send phase consumption report
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 * @param[in] ph          The phase number
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendPhaseConsumptionReport(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg, PHASES ph);

/*!
 * @brief Send phase calibration data
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 * @param[in] ph          The phase number
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendPhaseCalibrationData(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg, PHASES ph);

/*!
 * @brief Send neutral calibration data
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendNeutralCalibrationData(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg);

/*!
 * @brief Set phase calibration data
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 * @param[in] ph          The phase number
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_setPhaseCalibrationData(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg, PHASES ph);

/*!
 * @brief Set neutral calibration data
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_setNeutralCalibrationData(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg);

/*!
 * @brief Process Rx data
 * @param[in] workingData The Metrology instance
 * @param[in] dlt645      The DLT645 instance
 * @param[in] rxMsg       Received data buffer
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_processRxMessage(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg);

/*!
 * @brief DLT645 UART receive DMA init
 * @param[in] dlt645      The DLT645 instance
 */
void DLT645_UARTRxdmaInit(DLT645Buf *dlt645)
{
    HAL_startUARTDMARecieve(dlt645->uartChan, dlt645->rxMsg.buf.uint8, 14);
}

/*!
 * @brief Finds upper 16 bits of 32 bit value
 * @param[in] value 32 bit value
 * @return upper 16 bits of given 32 bit value
 */
uint16_t __attribute__((section(".TI.ramfunc"))) DLT645_findHigh16(uint32_t value)
{
    return value >> 16;
}

/*!
 * @brief Finds lower 16 bits of 32 bit value
 * @param[in] value 32 bit value
 * @return lower 16 bits of given 32 bit value
 */
uint16_t __attribute__((section(".TI.ramfunc"))) DLT645_findLow16(uint32_t value)
{
    return value & 0xFFFF;
}

/*!
 * @brief Write data over UART
 * @param[in] dlt645 The dlt645 instance
 * @param[in] len    Length of array
 */
void __attribute__((section(".TI.ramfunc"))) DLT645_serialWrite(DLT645Buf *dlt645, uint8_t len)
{
    dlt645->txInProgress = true;
    dlt645->txMsg.ptr = 0;
    dlt645->txMsg.len = len;

    HAL_enableUARTInterrupt(dlt645->uartChan);
}

/*!
 * @brief Configure serial communication
 * @param[in] dlt645 The dlt645 instance
 */
void __attribute__((section(".TI.ramfunc"))) DLT645_serialConfigure(DLT645Buf *dlt645)
{
    dlt645->txMsg.len = 0;
    dlt645->txMsg.ptr = 0;
    dlt645->rxMsg.ptr = 0;
    dlt645->rxPending = false;
    dlt645->txInProgress = false;

}

/*!
 * @brief Prepare transfer message
 * @param[in] dlt645 The dlt645 instance
 * @param[in] len    Length of array
 */
int __attribute__((section(".TI.ramfunc"))) DLT645_prepareTxMessage(DLT645Buf *dlt645, uint8_t len)
{
    uint8_t *tx8;

    tx8 = dlt645->txMsg.buf.uint8;

    tx8[0] = 0xFE;
    tx8[1] = 0xFE;
    tx8[2] = 0xFE;
    tx8[3] = 0xFE;
    tx8[4] = 0x68;
    tx8[5] = 0x99;
    tx8[6] = 0x99;
    tx8[7] = 0x99;
    tx8[8] = 0x99;
    tx8[9] = 0x99;
    tx8[10] = 0x99;
    tx8[11] = 0x68;
    tx8[12] = 0x23;
    tx8[13] = len;
    tx8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES + len] = 0;
    for(int i = DLT645_PREAMBLE_BYTES; i < DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES + len; i++)
    {
        tx8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES + len] += tx8[i];
    }

    tx8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES + len + 1] = 0x16;
    uint8_t length = DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES + len + DLT645_MESSAGE_TRAILER_BYTES;

    if(length > DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES + MAX_DLT645_MSG_BODY + DLT645_MESSAGE_TRAILER_BYTES)
    {
        return false;
    }

    HAL_startUARTDMATransmit(dlt645->uartChan, tx8, length);

    return true;
}

/*!
 * @brief Send Aggregate consumption report
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendAggregateConsumptionReport(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg)
{
    SerialMsgBuf *tx;
    uint8_t msgLen = 0;
    uint8_t *tx8;
    uint16_t *tx16;

    tx = &dlt645->txMsg;
    tx8 = &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];
    tx16 = (uint16_t *) &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];

    tx8[0] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES];
    tx8[1] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES + 1] | 0x80;
    msgLen += 2;
    *((uint64_t *) &tx16[1])  = Metrology_getTotalActiveEnergyImported(workingData);
    msgLen += 8;
    *((uint64_t *) &tx16[5])  = Metrology_getTotalActiveEnergyExported(workingData);
    msgLen += 8;
    *((uint64_t *) &tx16[9])  = Metrology_getTotalFundamentalActiveEnergyImported(workingData);
    msgLen += 8;
    *((uint64_t *) &tx16[13]) = Metrology_getTotalFundamentalActiveEnergyExported(workingData);
    msgLen += 8;
    *((uint64_t *) &tx16[17]) = Metrology_getTotalReactiveEnergyFirstQuadrant(workingData);
    msgLen += 8;
    *((uint64_t *) &tx16[21]) = Metrology_getTotalReactiveEnergySecondQuadrant(workingData);
    msgLen += 8;
    *((uint64_t *) &tx16[25]) = Metrology_getTotalReactiveEnergyThirdQuadrant(workingData);
    msgLen += 8;
    *((uint64_t *) &tx16[29]) = Metrology_getTotalReactiveEnergyFourthQuadrant(workingData);
    msgLen += 8;
    *((uint64_t *) &tx16[33]) = Metrology_getTotalApparentEnergyImported(workingData);
    msgLen += 8;
    *((uint64_t *) &tx16[37]) = Metrology_getTotalApparentEnergyExported(workingData);
    msgLen += 8;
    *((int32_t *) &tx16[41])  = Metrology_getLinetoLineVoltagePhase0toPhase1(workingData);
    msgLen += 4;
    *((int32_t *) &tx16[43])  = Metrology_getLinetoLineVoltagePhase1toPhase2(workingData);
    msgLen += 4;
    *((int32_t *) &tx16[45])  = Metrology_getLinetoLineVoltagePhase2toPhase0(workingData);
    msgLen += 4;
    *((int32_t *) &tx16[47])  = Metrology_getFundamentalLinetoLineVoltagePhase0toPhase1(workingData);
    msgLen += 4;
    *((int32_t *) &tx16[49])  = Metrology_getFundamentalLinetoLineVoltagePhase1toPhase2(workingData);
    msgLen += 4;
    *((int32_t *) &tx16[51])  = Metrology_getFundamentalLinetoLineVoltagePhase2toPhase0(workingData);
    msgLen += 4;
    *((int32_t *) &tx16[53])  = Metrology_getCurrentVectorSum(workingData);
    msgLen += 4;

    DLT645_prepareTxMessage(dlt645, msgLen);
}

/*!
 * @brief Send phase readings report
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 * @param[in] ph          The phase number
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendPhaseReadingsReport(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg, PHASES ph)
{
    SerialMsgBuf *tx;
    uint8_t msgLen = 0;
    uint8_t *tx8;
    uint16_t *tx16;

    tx = &dlt645->txMsg;
    tx8 = &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];
    tx16 = (uint16_t *) &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];

    tx8[0] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES];
    tx8[1] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES + 1] | 0x80;
    msgLen += 2;
    *((int32_t *) &tx16[1]) = Metrology_getRMSVoltage(workingData, ph);
    msgLen += 4;
    *((int32_t *) &tx16[3]) = Metrology_getRMSCurrent(workingData, ph);
    msgLen += 4;
    *((int32_t *) &tx16[5]) = Metrology_getActivePower(workingData, ph);
    msgLen += 4;
    *((int32_t *) &tx16[7]) = Metrology_getReactivePower(workingData, ph);
    msgLen += 4;
    *((int32_t *) &tx16[9]) = Metrology_getApparentPower(workingData, ph);
    msgLen += 4;
    tx16[11] = Metrology_getPowerFactor(workingData, ph);
    msgLen += 2;
    tx16[12] = Metrology_getMainsFrequency(workingData, ph);
    msgLen += 2;
    *((int32_t *) &tx16[13]) = Metrology_getVdcEstimate(workingData, ph);
    msgLen += 4;
    *((int32_t *) &tx16[15]) = Metrology_getIdcEstimate(workingData, ph);
    msgLen += 4;
    tx16[17] = Metrology_getAngleVoltagetoCurrent(workingData, ph);
    msgLen += 2;

    DLT645_prepareTxMessage(dlt645, msgLen);
}

/*!
 * @brief Send phase extra readings report
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 * @param[in] ph          The phase number
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendPhaseExtraReadingsReport(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg, PHASES ph)
{
    SerialMsgBuf *tx;
    uint8_t msgLen = 0;
    uint8_t *tx8;
    uint16_t *tx16;

    tx = &(dlt645->txMsg);
    tx8 = &(tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES]);
    tx16 = (uint16_t *) &(tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES]);

    tx8[0] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES];
    tx8[1] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES + 1] | 0x80;
    msgLen += 2;
    *((int32_t * ) &tx16[1]) = Metrology_getFundamentalActivePower(workingData, ph);
    msgLen += 4;
    *((int32_t * ) &tx16[3]) = Metrology_getFundamentalReactivePower(workingData, ph);
    msgLen += 4;
    *((int32_t * ) &tx16[5]) = Metrology_getFundamentalApparentPower(workingData, ph);
    msgLen += 4;
    *((int32_t * ) &tx16[7]) = Metrology_getFundamentalRMSVoltage(workingData, ph);
    msgLen += 4;
    *((int32_t * ) &tx16[9]) = Metrology_getFundamentalRMSCurrent(workingData, ph);
    msgLen += 4;
    tx16[11] = Metrology_getVoltageTHD(workingData, ph);
    msgLen += 2;
    tx16[12] = Metrology_getCurrentTHD(workingData, ph);
    msgLen += 2;
    tx16[13] = Metrology_getPhasetoPhaseAngle(workingData, ph);
    msgLen += 2;
    tx16[14] = Metrology_getSagEvents(workingData, ph);
    msgLen += 2;
    *((uint32_t * ) &tx16[15]) = Metrology_getSagDuration(workingData, ph);
    msgLen += 4;
    *((uint32_t * ) &tx16[17]) = Metrology_getMinSagValue(workingData, ph);
    msgLen += 4;
    tx16[19] = Metrology_getSwellEvents(workingData, ph);
    msgLen += 2;
    /* *((int32_t * ) &tx16[20]) = Metrology_getSwellDuration(workingData, ph); */
    uint32_t swellDuration = Metrology_getSwellDuration(workingData, ph);
    tx16[20] = DLT645_findLow16(swellDuration);
    tx16[21] = DLT645_findHigh16(swellDuration);
    msgLen += 4;
    /* *((int32_t * ) &tx16[22]) = Metrology_getMaxSwellValue(workingData, ph); */
    uint32_t maxSwellValue = Metrology_getMaxSwellValue(workingData, ph);
    tx16[22] = DLT645_findLow16(maxSwellValue);
    tx16[23] = DLT645_findHigh16(maxSwellValue);
    msgLen += 4;
    tx16[24] = Metrology_getUnderDeviation(workingData, ph);
    msgLen += 2;
    tx16[25] = Metrology_getOverDeviation(workingData, ph);
    msgLen += 2;
    tx16[26] = Metrology_getInterruptionEvents(workingData, ph);
    msgLen += 2;
    *((uint32_t * ) &tx16[27]) = Metrology_getInterruptionDuration(workingData, ph);
    msgLen += 4;

    DLT645_prepareTxMessage(dlt645, msgLen);
}

/*!
 * @brief Send neutral extra readings report
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendNeutralExtraReadingsReport(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg)
{
    SerialMsgBuf *tx;
    uint8_t msgLen = 0;
    uint8_t *tx8;
    uint16_t *tx16;

    tx = &(dlt645->txMsg);
    tx8 = &(tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES]);
    tx16 = (uint16_t *) &(tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES]);

    tx8[0] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES];
    tx8[1] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES + 1] | 0x80;
    msgLen += 2;
    tx16[1] = 0;
    tx16[2] = 0;
    tx16[3] = 0;
    tx16[4] = 0;
    tx16[5] = 0;
    tx16[6] = 0;
    tx16[7] = 0;
    tx16[8] = 0;
    tx16[9] = 0;
    tx16[10] = 0;
    tx16[11] = 0;
    tx16[12] = 0;
    tx16[13] = 0;
    tx16[14] = 0;
    tx16[15] = 0;
    tx16[16] = 0;
    msgLen += 32;

    DLT645_prepareTxMessage(dlt645, msgLen);
}

/*!
 * @brief Send neutral readings
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendNeutralReadings(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg)
{
    SerialMsgBuf *tx;
    uint8_t msgLen = 0;
    uint8_t *tx8;
    uint16_t *tx16;

    tx = &dlt645->txMsg;
    tx8 = &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];
    tx16 = (uint16_t *) &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];

    tx8[0] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES];
    tx8[1] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES + 1] | 0x80;
    msgLen += 2;

    tx16[1] = 0;
    msgLen += 2;
    tx16[2] = 0;
    msgLen += 2;
    *((uint32_t *) &tx16[3]) = Metrology_getNeutralRMSCurrent(workingData);
    msgLen += 4;
    tx16[5] = 0;
    msgLen += 2;
    tx16[6] = 0;
    msgLen += 2;
    tx16[7] = 0;
    msgLen += 2;
    tx16[8] = 0;
    msgLen += 2;
    tx16[9] = 0;
    msgLen += 2;
    tx16[10] = 0;
    msgLen += 2;
    tx16[11] = 0;
    msgLen += 2;
    tx16[12] = 0;
    msgLen += 2;
    tx16[13] = 0;
    msgLen += 2;
    tx16[14] = 0;
    msgLen += 2;
    *((int32_t *) &tx16[15]) = Metrology_getNeutralIdcEstimate(workingData);
    msgLen += 4;

    DLT645_prepareTxMessage(dlt645, msgLen);
}

/*!
 * @brief Send phase consumption report
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 * @param[in] ph          The phase number
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendPhaseConsumptionReport(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg, PHASES ph)
{
    SerialMsgBuf *tx;
    uint8_t msgLen = 0;
    uint8_t *tx8;
    uint16_t *tx16;

    tx = &dlt645->txMsg;
    tx8 = &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];
    tx16 = (uint16_t *) &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];

    tx8[0] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES];
    tx8[1] = rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES + 1] | 0x80;
    msgLen += 2;
    *((uint64_t *) &tx16[1]) = Metrology_getActiveEnergyImported(workingData, ph);
    msgLen += 8;
    *((uint64_t *) &tx16[5]) = Metrology_getActiveEnergyExported(workingData, ph);
    msgLen += 8;
    *((uint64_t *) &tx16[9]) = Metrology_getFundamentalActiveEnergyImported(workingData, ph);
    msgLen += 8;
    *((uint64_t *) &tx16[13])= Metrology_getFundamentalActiveEnergyExported(workingData, ph);
    msgLen += 8;
    *((uint64_t *) &tx16[17])= Metrology_getReactiveEnergyFirstQuadrant(workingData, ph);
    msgLen += 8;
    *((uint64_t *) &tx16[21])= Metrology_getReactiveEnergySecondQuadrant(workingData, ph);
    msgLen += 8;
    *((uint64_t *) &tx16[25])= Metrology_getReactiveEnergyThirdQuadrant(workingData, ph);
    msgLen += 8;
    *((uint64_t *) &tx16[29])= Metrology_getReactiveEnergyFourthQuadrant(workingData, ph);
    msgLen += 8;
    *((uint64_t *) &tx16[33])= Metrology_getApparentEnergyImported(workingData, ph);
    msgLen += 8;
    *((uint64_t *) &tx16[37])= Metrology_getApparentEnergyExported(workingData, ph);
    msgLen += 8;

    DLT645_prepareTxMessage(dlt645, msgLen);
}

/*!
 * @brief Send phase calibration data
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 * @param[in] ph          The phase number
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendPhaseCalibrationData(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg, PHASES ph)
{
    uint8_t msgLen = 0;
    SerialMsgBuf *tx;
    uint8_t *tx8;
    uint16_t *tx16;

    tx = &dlt645->txMsg;
    tx8 = &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];
    tx16 = (uint16_t *) &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];

    tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
    tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
    msgLen += 2;
    tx16[1] = Metrology_getVdcEstimate(workingData, ph);
    msgLen += 2;
    tx16[2] = 0;
    msgLen += 2;
    tx16[3] = Metrology_getIdcEstimate(workingData, ph);
    msgLen += 2;
    tx16[4] = 0;
    msgLen += 2;
    /* *((uint32_t *) &tx16[5]) = Metrology_getPhaseVacOffset(workingData, ph); */
    uint32_t VacOffset = Metrology_getPhaseVacOffset(workingData, ph);
    tx16[5] = DLT645_findLow16(VacOffset);
    tx16[6] = DLT645_findHigh16(VacOffset);
    msgLen += 4;
    /* *((uint32_t *) &tx16[7]) = Metrology_getPhaseIacOffset(workingData, ph); */
    uint32_t IacOffset = Metrology_getPhaseIacOffset(workingData, ph);
    tx16[7] = DLT645_findLow16(IacOffset);
    tx16[8] = DLT645_findHigh16(IacOffset);
    msgLen += 4;
    tx16[9] = Metrology_getPhaseCorrectionParameters(workingData, ph);
    msgLen += 2;
    /* *((uint32_t *) &tx16[10]) = Metrology_getPhaseVRMSScaling(workingData, ph); */
    uint32_t VrmsScaling = Metrology_getPhaseVRMSScaling(workingData, ph);
    tx16[10] = DLT645_findLow16(VrmsScaling);
    tx16[11] = DLT645_findHigh16(VrmsScaling);
    msgLen += 4;
    tx16[12] = 0;
    tx16[13] = 0;
    msgLen += 4;
    /* *((uint32_t *) &tx16[14]) = Metrology_getPhaseIRMSScaling(workingData, ph); */
    uint32_t IrmsScaling = Metrology_getPhaseIRMSScaling(workingData, ph);
    tx16[14] = DLT645_findLow16(IrmsScaling);
    tx16[15] = DLT645_findHigh16(IrmsScaling);
    msgLen += 4;
    tx16[16] = 0;
    tx16[17] = 0;
    msgLen += 4;
    /* *((uint32_t *) &tx16[18]) = Metrology_getPhasePScaling(workingData, ph); */
    uint32_t Pscaling = Metrology_getPhasePScaling(workingData, ph);
    tx16[18] = DLT645_findLow16(Pscaling);
    tx16[19] = DLT645_findHigh16(Pscaling);
    msgLen += 4;
    /* *((uint32_t *) &tx16[20]) = Metrology_getPhasePOffset(workingData, ph); */
    uint32_t POffset = Metrology_getPhasePOffset(workingData, ph);
    tx16[20] = DLT645_findLow16(POffset);
    tx16[21] = DLT645_findHigh16(POffset);
    msgLen += 4;
    /* *((uint32_t *) &tx16[22]) = Metrology_getPhaseQOffset(workingData, ph); */
    uint32_t QOffset = Metrology_getPhaseQOffset(workingData, ph);
    tx16[22] = DLT645_findLow16(QOffset);
    tx16[23] = DLT645_findHigh16(QOffset);
    msgLen += 4;
    /* *((uint32_t *) &tx16[24]) = Metrology_getPhaseFundPOffset(workingData, ph); */
    uint32_t POffsetFund = Metrology_getPhaseFundPOffset(workingData, ph);
    tx16[24] = DLT645_findLow16(POffsetFund);
    tx16[25] = DLT645_findHigh16(POffsetFund);
    msgLen += 4;
    //*((uint32_t *) &tx16[26]) = Metrology_getPhaseFundQOffset(workingData, ph);
    uint32_t QOffsetFund = Metrology_getPhaseFundQOffset(workingData, ph);
    tx16[26] = DLT645_findLow16(QOffsetFund);
    tx16[27] = DLT645_findHigh16(QOffsetFund);
    msgLen += 4;
    //*((uint32_t *) &tx16[28]) = Metrology_getPhaseFundVOffset(workingData, ph);
    uint32_t VOffsetFund = Metrology_getPhaseFundVOffset(workingData, ph);
    tx16[28] = DLT645_findLow16(VOffsetFund);
    tx16[29] = DLT645_findHigh16(VOffsetFund);
    msgLen += 4;
    //*((uint32_t *) &tx16[30]) = Metrology_getPhaseFundIOffset(workingData, ph);
    uint32_t IOffsetFund = Metrology_getPhaseFundIOffset(workingData, ph);
    tx16[30] = DLT645_findLow16(IOffsetFund);
    tx16[31] = DLT645_findHigh16(IOffsetFund);
    msgLen += 4;

    DLT645_prepareTxMessage(dlt645, msgLen);
}

/*!
 * @brief Send neutral calibration data
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_sendNeutralCalibrationData(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg)
{
    uint8_t msgLen = 0;
    SerialMsgBuf *tx;
    uint8_t *tx8;
    uint16_t *tx16;

    tx = &dlt645->txMsg;
    tx8 = &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];
    tx16 = (uint16_t *) &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];

    tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
    tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
    msgLen += 2;
    tx16[1] = 0;
    msgLen += 2;
    tx16[2] = 0;
    msgLen += 2;
    tx16[3] = Metrology_getNeutralInitialIdcEstimate(workingData);
    msgLen += 2;
    tx16[4] = 0;
    msgLen += 2;
    tx16[5] = 0;
    msgLen += 2;
    tx16[6] = 0;
    msgLen += 2;
    uint32_t Iacoffset = Metrology_getNeutralIacOffset(workingData);
    tx16[7] = DLT645_findLow16(Iacoffset);
    tx16[8] = DLT645_findHigh16(Iacoffset);
    msgLen += 4;
    tx16[9] = Metrology_getNeutralCorrectionParameters(workingData);
    msgLen += 2;
    tx16[10] = 0;
    msgLen += 2;
    tx16[11] = 0;
    msgLen += 2;
    tx16[12] = 0;
    msgLen += 2;
    tx16[13] = 0;
    msgLen += 2;
    /* *((uint32_t *) &tx16[14]) = Metrology_getNeutralIRMSScaling(workingData); */
    uint32_t Irmsscaling = Metrology_getNeutralIRMSScaling(workingData);
    tx16[14] = DLT645_findLow16(Irmsscaling);
    tx16[15] = DLT645_findHigh16(Irmsscaling);
    msgLen += 4;
    tx16[16] = 0;
    msgLen += 2;
    tx16[17] = 0;
    msgLen += 2;
    /* *((uint32_t *) &tx16[18]) = Metrology_getNeutralPScaling(workingData); */
    uint32_t Pscaling = Metrology_getNeutralPScaling(workingData);
    tx16[18] = DLT645_findLow16(Pscaling);
    tx16[19] = DLT645_findHigh16(Pscaling);
    msgLen += 4;
    /* *((uint32_t *) &tx16[20]) = Metrology_getNeutralPOffset(workingData); */
    uint32_t Poffset = Metrology_getNeutralPOffset(workingData);
    tx16[20] = DLT645_findLow16(Poffset);
    tx16[21] = DLT645_findHigh16(Poffset);
    msgLen += 4;
    /* *((uint32_t *) &tx16[22]) = Metrology_getNeutralQOffset(workingData); */
    uint32_t Qoffset = Metrology_getNeutralQOffset(workingData);
    tx16[22] = DLT645_findLow16(Qoffset);
    tx16[23] = DLT645_findHigh16(Qoffset);
    msgLen += 4;
    /* *((uint32_t *) &tx16[24]) = Metrology_getNeutralFundPOffset(workingData); */
    uint32_t Poffsetfund = Metrology_getNeutralFundPOffset(workingData);
    tx16[24] = DLT645_findLow16(Poffsetfund);
    tx16[25] = DLT645_findHigh16(Poffsetfund);
    msgLen += 4;
    /* *((uint32_t *) &tx16[26]) = Metrology_getNeutralFundQOffset(workingData); */
    uint32_t Qoffsetfund = Metrology_getNeutralFundQOffset(workingData);
    tx16[26] = DLT645_findLow16(Qoffsetfund);
    tx16[27] = DLT645_findHigh16(Qoffsetfund);
    msgLen += 4;
    /* *((uint32_t *) &tx16[28]) = Metrology_getNeutralFundVOffset(workingData); */
    uint32_t Voffsetfund = Metrology_getNeutralFundVOffset(workingData);
    tx16[28] = DLT645_findLow16(Voffsetfund);
    tx16[29] = DLT645_findHigh16(Voffsetfund);
    msgLen += 4;
    /* *((uint32_t *) &tx16[30]) = Metrology_getNeutralFundIOffset(workingData); */
    uint32_t Ioffsetfund = Metrology_getNeutralFundIOffset(workingData);
    tx16[30] = DLT645_findLow16(Ioffsetfund);
    tx16[31] = DLT645_findHigh16(Ioffsetfund);
    msgLen += 4;

    DLT645_prepareTxMessage(dlt645, msgLen);
}

/*!
 * @brief Set phase calibration data
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 * @param[in] ph          The phase number
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_setPhaseCalibrationData(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg, PHASES ph)
{
    uint8_t msgLen = 0;
    SerialMsgBuf *tx;
    uint8_t *tx8;
    uint16_t *tx16;

    tx = &dlt645->txMsg;
    tx8 = &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];
    tx16 = (uint16_t *) &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];

    Metrology_setPhaseVdcEstimate(workingData, rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 1], ph);

    Metrology_setPhaseIdcEstimate(workingData, rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 3], ph);

    Metrology_setPhaseVacOffset(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 5])[0], ph);

    Metrology_setPhaseIacOffset(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 7])[0], ph);

    Metrology_setPhaseOffset(workingData, rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 9], ph);

    Metrology_setPhaseVRMSScaling(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 10])[0], ph);

    Metrology_setPhaseIRMSScaling(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 14])[0], ph);

    Metrology_setPhasePScaling(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 18])[0], ph);

    Metrology_setPhasePOffset(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 20])[0], ph);

    Metrology_setPhaseQOffset(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 22])[0], ph);

    Metrology_setPhaseFundPOffset(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 24])[0], ph);

    Metrology_setPhaseFundQOffset(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 26])[0], ph);

    Metrology_setPhaseFundVOffset(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 28])[0], ph);

    Metrology_setPhaseFundIOffset(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 30])[0], ph);

    Metrology_updateCalibrationData(workingData);

    tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
    tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
    msgLen += 2;

    DLT645_prepareTxMessage(dlt645, msgLen);
}

/*!
 * @brief Set neutral calibration data
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The dlt645 buffer
 * @param[in] rxMsg       The rx message
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_setNeutralCalibrationData(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg)
{
    uint8_t msgLen = 0;
    SerialMsgBuf *tx;
    uint8_t *tx8;
    uint16_t *tx16;

    tx = &dlt645->txMsg;
    tx8 = &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];
    tx16 = (uint16_t *) &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];

    Metrology_setNeutralIdcEstimate(workingData, rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 3]);

    Metrology_setNeutralIacOffset(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 7])[0]);

    Metrology_setNeutralOffset(workingData, rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 9]);

    Metrology_setNeutralIRMSScaling(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 14])[0]);

    Metrology_setNeutralPScaling(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 18])[0]);

    Metrology_setNeutralPOffset(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 20])[0]);

    Metrology_setNeutralQOffset(workingData, ((uint32_t *) &rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 22])[0]);

    Metrology_updateCalibrationData(workingData);

    tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
    tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
    msgLen += 2;

    DLT645_prepareTxMessage(dlt645, msgLen);
}

/*!
 * @brief Process Rx data
 * @param[in] workingData The Metrology instance
 * @param[in] dlt645      The DLT645 instance
 * @param[in] rxMsg       Received data buffer
 */
static void __attribute__((section(".TI.ramfunc"))) DLT645_processRxMessage(metrologyData *workingData, DLT645Buf *dlt645, SerialMsg *rxMsg)
{
    uint8_t msgLen = 0;
    SerialMsgBuf *tx;
    uint8_t *tx8;
    uint16_t *tx16;

    tx = &dlt645->txMsg;
    tx8 = &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];
    tx16 = (uint16_t *) &tx->buf.uint8[DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES];

    if(rxMsg->uint8[8] != 0x23)
    {
        /* Messages with type 0x23 are custom messages we
          use for calibration, password protection, etc.
          All other message types go to a custom message
          handler (if available). */
        return;
    }

    if(rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] & 0x80)
    {
        /* This looks like one of our own messages, which has echoed back
           to us */
        return;
    }

    /* Only process messages if the password has been given correctly
       (except for the password test message, of course). */
    if(!(commStatus & DLT645_STATUS_PASSWORD_OK) && rxMsg->uint8[DLT645_MESSAGE_HEADER_BYTES] != HOST_CMD_SET_PASSWORD)
    {
        return;
    }

    switch(rxMsg->uint8[DLT645_MSG_RX_START_BODY])
    {
    case HOST_CMD_GET_METER_CONFIGURATION:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        tx8[2] = MAX_PHASES;
        msgLen += 1;
#if defined(NEUTRAL_SUPPORT)
        tx8[3] = DLT645_NEUTRAL_SUPPORT;
#else
        tx8[3] = 0;
#endif
        msgLen += 1;
        tx8[4] = DLT645_PHASE_CORRECTION_SUPPORT;
        msgLen += 1;
        tx8[5] = METER_CONFIG_1_ACTIVE_POWER   |
                 METER_CONFIG_1_REACTIVE_POWER |
                 METER_CONFIG_1_APPARENT_POWER |
                 METER_CONFIG_1_VRMS           |
                 METER_CONFIG_1_IRMS           |
                 METER_CONFIG_1_POWER_FACTOR   |
                 METER_CONFIG_1_MAINS_FREQUENCY|
                 METER_CONFIG_1_QUADRATURE_REACTIVE_POWER ;
        tx8[6] = METER_CONFIG_2_FUNDAMENTAL_APPARENT_POWER |
                 METER_CONFIG_2_FUNDAMENTAL_ACTIVE_POWER   |
                 METER_CONFIG_2_FUNDAMENTAL_REACTIVE_POWER |
                 METER_CONFIG_2_FUNDAMENTAL_VRMS           |
                 METER_CONFIG_2_FUNDAMENTAL_IRMS           |
                 METER_CONFIG_2_VOLTAGE_THD                |
                 METER_CONFIG_2_CURRENT_THD                |
                 METER_CONFIG_2_SAG_SWELL ;
        msgLen += 2;
        tx8[7] = 0x0;
        msgLen += 1;
        tx16[4] = MAINS_NOMINAL_FREQUENCY;
        msgLen += 2;
        tx16[5] = MAINS_NOMINAL_VOLTAGE;
        msgLen += 2;
        tx16[6] = MAINS_BASIS_CURRENT;
        msgLen += 2;
        tx16[7] = MAINS_MAXIMUM_CURRENT;
        msgLen += 2;
        /* *((uint32_t *) &tx16[8]) = (SAMPLES_PER_SECOND * 100); */
        uint32_t calc = (uint32_t) (SAMPLES_PER_SECOND * 100);
        tx16[8] = DLT645_findLow16(calc);
        tx16[9] = DLT645_findHigh16(calc);
        msgLen += 4;
#if defined(SPLIT_PHASE_SUPPORT)
        tx8[21] = 1;
#else
        tx8[21] = 0;
#endif
        msgLen += 1;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
    case HOST_CMD_SET_METER_CONSUMPTION:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
    case HOST_CMD_SET_RTC:
        HAL_setRTC(&rxMsg->uint8[DLT645_MSG_RX_START_BODY + 2]);
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
    case HOST_CMD_GET_RTC:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        HAL_getRTC(&tx8[2]);
        msgLen += 6;
        tx16[4] = 0;
        msgLen += 2;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
    case HOST_CMD_ALIGN_WITH_CALIBRATION_FACTORS:
        Metrology_alignWithCalibrationData(workingData);
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
    case HOST_CMD_SET_PASSWORD:
        if (rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 1] == SERIAL_CALIBRATION_PASSWORD_1
            &&
            rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 2] == SERIAL_CALIBRATION_PASSWORD_2
            &&
            rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 3] == SERIAL_CALIBRATION_PASSWORD_3
            &&
            rxMsg->uint16[DLT645_MSG_RX_START_BODY_W + 4] == SERIAL_CALIBRATION_PASSWORD_4)
        {
            commStatus |= DLT645_STATUS_PASSWORD_OK;
            tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
            tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
            DLT645_prepareTxMessage(dlt645, 2);
        }
        else
        {
            /* Only respond to a bad password, if the password was good before. That lets
               us know we have unset the password OK, but doesn't give any information to
               people trying to attack the meter. */
            if (commStatus & DLT645_STATUS_PASSWORD_OK)
            {
                tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
                tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
                DLT645_prepareTxMessage(dlt645, 2);
            }
            commStatus &= ~DLT645_STATUS_PASSWORD_OK;
        }
        break;
#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT) || defined(SINGLE_PHASE_SUPPORT)
    case HOST_CMD_GET_READINGS_PHASE_1:
        DLT645_sendPhaseReadingsReport(workingData, dlt645, rxMsg, PHASE_ONE);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT)
    case HOST_CMD_GET_READINGS_PHASE_2:
        DLT645_sendPhaseReadingsReport(workingData, dlt645, rxMsg, PHASE_TWO);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT)
    case HOST_CMD_GET_READINGS_PHASE_3:
        DLT645_sendPhaseReadingsReport(workingData, dlt645, rxMsg, PHASE_THERE);
        break;
#endif

    case HOST_CMD_GET_READINGS_NEUTRAL:
        DLT645_sendNeutralReadings(workingData, dlt645, rxMsg);
        break;

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT) || defined(SINGLE_PHASE_SUPPORT)
    case HOST_CMD_GET_CONSUMPTION_PHASE_1:
        DLT645_sendPhaseConsumptionReport(workingData, dlt645, rxMsg, PHASE_ONE);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT)
    case HOST_CMD_GET_CONSUMPTION_PHASE_2:
        DLT645_sendPhaseConsumptionReport(workingData, dlt645, rxMsg, PHASE_TWO);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT)
    case HOST_CMD_GET_CONSUMPTION_PHASE_3:
        DLT645_sendPhaseConsumptionReport(workingData, dlt645, rxMsg, PHASE_THERE);
        break;
#endif

    case HOST_CMD_GET_CONSUMPTION_AGGREGATE:
        DLT645_sendAggregateConsumptionReport(workingData, dlt645, rxMsg);
        break;

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT) || defined(SINGLE_PHASE_SUPPORT)
    case HOST_CMD_GET_EXTRA_READINGS_PHASE_1:
        DLT645_sendPhaseExtraReadingsReport(workingData, dlt645, rxMsg, PHASE_ONE);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT)
    case HOST_CMD_GET_EXTRA_READINGS_PHASE_2:
        DLT645_sendPhaseExtraReadingsReport(workingData, dlt645, rxMsg, PHASE_TWO);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT)
    case HOST_CMD_GET_EXTRA_READINGS_PHASE_3:
        DLT645_sendPhaseExtraReadingsReport(workingData, dlt645, rxMsg, PHASE_THERE);
        break;
#endif

    case HOST_CMD_GET_EXTRA_READINGS_NEUTRAL:
        DLT645_sendNeutralExtraReadingsReport(workingData, dlt645, rxMsg);
        break;
    case HOST_CMD_SUMCHECK_MEMORY:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT) || defined(SINGLE_PHASE_SUPPORT)
    case HOST_CMD_GET_RAW_ACTIVE_POWER_PHASE_1:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        *((uint64_t *) &tx16[2]) = Metrology_getRawActivePower(workingData, &tx16[1], PHASE_ONE);
        msgLen += 10;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT)
    case HOST_CMD_GET_RAW_ACTIVE_POWER_PHASE_2:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        *((uint64_t *) &tx16[2]) = Metrology_getRawActivePower(workingData, &tx16[1], PHASE_TWO);
        msgLen += 10;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT)
    case HOST_CMD_GET_RAW_ACTIVE_POWER_PHASE_3:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        *((uint64_t *) &tx16[2]) = Metrology_getRawActivePower(workingData, &tx16[1], PHASE_THERE);
        msgLen += 10;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT) || defined(SINGLE_PHASE_SUPPORT)
    case HOST_CMD_GET_RAW_REACTIVE_POWER_PHASE_1:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
       *((uint64_t *) &tx16[2]) = Metrology_getRawReactivePower(workingData, &tx16[1], PHASE_ONE);
        msgLen += 10;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT)
    case HOST_CMD_GET_RAW_REACTIVE_POWER_PHASE_2:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        *((uint64_t *) &tx16[2]) = Metrology_getRawReactivePower(workingData, &tx16[1], PHASE_TWO);
        msgLen += 10;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT)
    case HOST_CMD_GET_RAW_REACTIVE_POWER_PHASE_3:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        *((uint64_t *) &tx16[2]) = Metrology_getRawReactivePower(workingData, &tx16[1], PHASE_THERE);
        msgLen += 10;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
#endif
    case HOST_CMD_CLEAR_CALIBRATION_DATA:
        Metrology_clearCalibrationData(workingData);
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen+=2;
        if(dlt645->txMsg.ptr !=0)
        {
            dlt645->txMsg.ptr=0;
        }
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT) || defined(SINGLE_PHASE_SUPPORT)
    case HOST_CMD_SET_CALIBRATION_PHASE_1:
        DLT645_setPhaseCalibrationData(workingData, dlt645, rxMsg, PHASE_ONE);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT)
    case HOST_CMD_SET_CALIBRATION_PHASE_2:
        DLT645_setPhaseCalibrationData(workingData, dlt645, rxMsg, PHASE_TWO);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT)
    case HOST_CMD_SET_CALIBRATION_PHASE_3:
        DLT645_setPhaseCalibrationData(workingData, dlt645, rxMsg, PHASE_THERE);
        break;
#endif
    case HOST_CMD_SET_CALIBRATION_NEUTRAL:
        DLT645_setNeutralCalibrationData(workingData, dlt645, rxMsg);
        break;
    case HOST_CMD_SET_CALIBRATION_EXTRAS:
        Metrology_setCalibrationStatus(workingData , rxMsg->uint16[1]);
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT) || defined(SINGLE_PHASE_SUPPORT)
    case HOST_CMD_GET_CALIBRATION_PHASE_1:
        DLT645_sendPhaseCalibrationData(workingData, dlt645, rxMsg, PHASE_ONE);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT)
    case HOST_CMD_GET_CALIBRATION_PHASE_2:
        DLT645_sendPhaseCalibrationData(workingData, dlt645, rxMsg, PHASE_TWO);
        break;
#endif

#if defined(THREE_PHASE_SUPPORT)
    case HOST_CMD_GET_CALIBRATION_PHASE_3:
        DLT645_sendPhaseCalibrationData(workingData, dlt645, rxMsg, PHASE_THERE);
        break;
#endif
    case HOST_CMD_GET_CALIBRATION_NEUTRAL:
        DLT645_sendNeutralCalibrationData(workingData, dlt645, rxMsg);
        break;
    case HOST_CMD_GET_CALIBRATION_EXTRAS:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = rxMsg->uint8[DLT645_MSG_RX_START_BODY + 1] | 0x80;
        msgLen += 2;
        tx16[1] = Metrology_getCalibrationStatus(workingData);
        msgLen += 2;
        tx16[2] = 0;
        msgLen += 2;
        tx16[3] = 0;
        msgLen += 2;
        tx16[4] = 0;
        msgLen += 2;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
    default:
        tx8[0] = rxMsg->uint8[DLT645_MSG_RX_START_BODY];
        tx8[1] = 0xFF;
        msgLen += 2;
        DLT645_prepareTxMessage(dlt645, msgLen);
        break;
    }
}

/*!
 * @brief DLT645 service
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The DLT645 instance
 */
void DLT645_service(metrologyData *workingData, DLT645Buf *dlt645)
{
    if(dlt645->rxPending)
    {
        DLT645_processRxMessage(workingData, dlt645, &dlt645->rxMsg.buf);
        dlt645->rxPending = 0;
    }
}

/*!
 * @brief Read UART receive byte
 * @param[in] dlt645 The dlt645 instance
 */
void DLT645_UARTRxByte(DLT645Buf *dlt645)
{
    if(!dlt645->txInProgress)
    {
        dlt645->rxMsg.len = 10 + dlt645->rxMsg.buf.uint8[9] + 2;

        /* This is end of packet    */
        if(dlt645->rxMsg.buf.uint8[dlt645->rxMsg.len - 1] == 0x16)
        {
            uint8_t sum = dlt645->rxMsg.buf.uint8[0];
            for(int i = 1; i < dlt645->rxMsg.len - 2; i++)
            {
                sum += dlt645->rxMsg.buf.uint8[i];
            }
            if(dlt645->rxMsg.buf.uint8[dlt645->rxMsg.len - 2] == (sum & 0xFF))
            {
                dlt645->rxPending = true;
            }
        }
    }
}

/*!
 * @brief Get UART transmit byte
 * @param[in] dlt645 The dlt645 instance
 * @return UART transmit byte
 */
uint16_t DLT645_UARTTxByte(DLT645Buf *dlt645)
{
    if(!dlt645->txInProgress)
    {
        return 0x8800;
    }
    uint8_t tx = dlt645->txMsg.buf.uint8[dlt645->txMsg.ptr++];
    if(dlt645->txMsg.ptr >= dlt645->txMsg.len)
    {
        dlt645->txMsg.ptr = 0;
        dlt645->txMsg.len = 0;
        dlt645->txInProgress = false;
        return 0x8000 | tx;
    }
    return tx;
}

