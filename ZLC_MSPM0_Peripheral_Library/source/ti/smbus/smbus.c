/* --COPYRIGHT--,BSD
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
 * --/COPYRIGHT--*/
//
// Include files
//
#include <stdint.h>
#include "smbus.h"
#include "smbus_nwk.h"
#include "smbus_phy.h"


void SMBus_processDone(SMBus *smbus)
{
    if (smbus->ctrl.bits.swackEn == true)
    {
        /* Send a manual ACK if no issues processing received data */
        if (smbus->phy.SMBus_Phy_AckPending == true)
        {
            if ( (smbus->state == SMBus_State_Target_FirstByte) ||
                 (smbus->state == SMBus_State_Target_ByteReceived) )
            {
                SMBus_PHY_targetManualACK(smbus,  true);
            }
            else
            {
                SMBus_PHY_targetManualACK(smbus,  false);
            }
        }
    }
    // Clear the State of SMBus target
    smbus->state = SMBus_State_OK;
}

uint16_t SMBus_getRxPayloadAvailable(SMBus *smbus)
{
    return(SMBus_NWK_getRxPayloadSize(smbus));
}

SMBus_State SMBus_getState(SMBus *smbus)
{
    return(smbus->state);
}


void SMBus_enablePEC(SMBus *smbus)
{
    smbus->ctrl.bits.pecEn = 1;
}

void SMBus_disablePEC(SMBus *smbus)
{
    smbus->ctrl.bits.pecEn = 0;
}


void SMBus_targetInit(SMBus *smbus, I2C_Regs *i2cAddr)
{
    smbus->nwk.eState = SMBus_NwkState_Idle;
    smbus->nwk.currentCmd = 0;
    smbus->nwk.currentAddr = 0;
    smbus->nwk.rxBuffPtr = NULL;
    smbus->nwk.rxSize = 0;
    smbus->nwk.rxLen = 0;
    smbus->nwk.rxIndex = 0;
    smbus->nwk.txBuffPtr = NULL;
    smbus->nwk.txSize = 0;
    smbus->nwk.txIndex = 0;
    smbus->nwk.txLen = 0;
    smbus->nwk.recByteTxPtr = &smbus->status.u8byte;
    smbus->nwk.pecBlockLenOverride = 0;
    smbus->ctrl.u8byte = 0;
    smbus->status.u8byte = 0;
    smbus->state = SMBus_State_OK;
    smbus->ctrl.bits.controller = 0;  // Update control flag;

    SMBus_PHY_targetInit(smbus, i2cAddr);
}

void SMBus_targetEnableInt(SMBus *smbus)
{
    SMBus_PHY_targetEnableInt(smbus);
}

void SMBus_targetDisableInt(SMBus *smbus)
{
    SMBus_PHY_targetDisableInt(smbus);
}


SMBus_State SMBus_targetProcessInt(SMBus *smbus)
{
    SMBus_State New_State;
    New_State = SMBus_PHY_targetProcessInt(smbus);

    if(New_State != SMBus_State_Target_NTR)
    {
        smbus->state = New_State;
    }

    return(New_State);
}

void SMBus_targetSetAddress(SMBus *smbus,
                           uint8_t targetAddr)
{
    // Set new Target Address
    smbus->ownTargetAddr = targetAddr;
}

void SMBus_targetSetRxBuffer(SMBus *smbus,
                            uint8_t *data,
                            uint16_t size)
{
    // Set pointer and size of RX Buffer
    smbus->nwk.rxBuffPtr = data;
    smbus->nwk.rxSize = size;
}

void SMBus_targetSetTxBuffer(SMBus *smbus,
                            uint8_t *data,
                            uint16_t size)
{
    // Set pointer and size of TX Buffer
    smbus->nwk.txBuffPtr = data;
    smbus->nwk.txSize = size;
}

void SMBus_targetReportError(SMBus *smbus,
                            SMBus_ErrorCode errorCode)
{
    switch(errorCode)
    {
    case SMBus_ErrorCode_Packet:
        smbus->status.bits.packErr = 1;
        smbus->state = SMBus_State_Target_Error;
        break;
    case SMBus_ErrorCode_Cmd:
        smbus->status.bits.cmdErr = 1;
        smbus->state = SMBus_State_Target_Error;
        break;
    default:
        return;
    }
    // Update flags in order to invalidate current packet
    smbus->nwk.eState = SMBus_NwkState_Error;
}

uint8_t SMBus_targetGetCommand(SMBus *smbus)
{
    return (smbus->nwk.currentCmd);
}

void SMBus_targetReportBlock(SMBus *smbus){
    /* report a block such that the next state upon receiving should be considered
     * a block Length, such that it's interpreted as a length.
     */
    if (smbus->ctrl.bits.pecEn == 1) {
        smbus->nwk.pecBlockLenOverride = 1;
    }
}


void SMBus_targetReportLength(SMBus *smbus, uint16_t length){
    /* The PECCount should be the length plus the PECbit as well*/
    if (smbus->ctrl.bits.pecEn == 1) {
        SMBus_PHY_targetSetPECCount(smbus, length + 1);
    }
}

uint8_t SMBus_targetClearStatusReg(SMBus *smbus,
                                  uint8_t val)
{
    smbus->status.u8byte &= val;
    return(smbus->status.u8byte);
}

uint8_t SMBus_targetWriteCtrlReg(SMBus *smbus,
                                uint8_t val)
{
    smbus->ctrl.writeableBits.writeBits = val;

    return(smbus->ctrl.u8byte);
}

int8_t SMBus_targetHostAlert(SMBus *smbus,
                                 uint8_t deviceAddress,
                                 uint8_t *txData)
{
    if(smbus->nwk.eState != SMBus_NwkState_Idle)
    {
        return(SMBUS_RET_ERROR);
    }

    smbus->nwk.currentCmd = deviceAddress;
    smbus->nwk.rxLen = 0; // No bytes to read
    smbus->nwk.txLen = 1 + 2; // Command + Size
    smbus->nwk.txBuffPtr = txData;
    smbus->nwk.eState = SMBus_NwkState_TXHostAlert;
    smbus->nwk.currentAddr = SMB_HOST_DEFAULT_ADDRESS;

    SMBus_NWK_startTxTransfer(smbus);

    return(SMBUS_RET_OK);
}

void SMBus_controllerInit(SMBus *smbus,
                      I2C_Regs *i2cAddr,
                      uint32_t busClk)
{
    smbus->nwk.eState = SMBus_NwkState_Idle;
    smbus->nwk.currentAddr = 0;
    smbus->nwk.rxBuffPtr = NULL;
    smbus->nwk.rxSize = 0;
    smbus->nwk.rxLen = 0;
    smbus->nwk.rxIndex = 0;
    smbus->nwk.txBuffPtr = NULL;
    smbus->nwk.txSize = 0;
    smbus->nwk.txIndex = 0;
    smbus->nwk.txLen = 0;
    smbus->nwk.recByteTxPtr = &smbus->status.u8byte;
    smbus->nwk.pecBlockLenOverride = 0;
    smbus->ctrl.u8byte = 0;
    smbus->status.u8byte = 0;
    smbus->state = SMBus_State_OK;
    smbus->ctrl.bits.controller = 1;  // Update control flag;

    SMBus_PHY_controllerInit(smbus, i2cAddr, busClk);
}

void SMBus_controllerEnableInt(SMBus *smbus)
{
    SMBus_PHY_controllerEnableInt(smbus);
}

void SMBus_controllerDisableInt(SMBus *smbus)
{
    SMBus_PHY_controllerEnableInt(smbus);
}


SMBus_State SMBus_controllerProcessInt(SMBus *smbus)
{
    return(SMBus_PHY_controllerProcessInt(smbus));
}

void SMBus_controllerReset(SMBus *smbus)
{
    SMBus_NWK_controllerReset(smbus);
}

int8_t SMBus_controllerProcessCall(SMBus *smbus,
                               uint8_t targetAddr,
                               uint8_t command,
                               uint8_t *txData,
                               uint8_t *rxData)
{
    if(smbus->nwk.eState != SMBus_NwkState_Idle)
    {
        return(SMBUS_RET_ERROR);
    }

    smbus->nwk.currentCmd = command;
    smbus->nwk.rxLen = 2; // Read 2 bytes
    smbus->nwk.rxBuffPtr = rxData;
    smbus->nwk.txLen = 3; // 2 bytes + Cmd
    smbus->nwk.txBuffPtr = txData;
    smbus->nwk.eState = SMBus_NwkState_TX;
    smbus->nwk.currentAddr = targetAddr;

    SMBus_NWK_startTxTransfer(smbus);

    return(SMBUS_RET_OK);
}

int8_t SMBus_controllerProcessCallBlock(SMBus *smbus,
                                    uint8_t targetAddr,
                                    uint8_t command,
                                    uint8_t *txData,
                                    uint8_t txSize,
                                    uint8_t *rxData)
{
    if(smbus->nwk.eState != SMBus_NwkState_Idle)
    {
        return(SMBUS_RET_ERROR);
    }

    if((txSize == 0) || (txSize > SMB_MAX_PAYLOAD_SIZE))
    {
        return(SMBUS_RET_ERROR);
    }

    smbus->nwk.currentCmd = command;
    smbus->nwk.rxLen = 3; // Minimal size until we get the real Byte count
    smbus->nwk.rxBuffPtr = rxData;
    smbus->nwk.txLen = txSize + 2; // Size includes Command and byte count
    smbus->nwk.txBuffPtr = txData;
    smbus->nwk.eState = SMBus_NwkState_TX_Block;
    smbus->nwk.currentAddr = targetAddr;

    SMBus_NWK_startTxTransfer(smbus);

    return(SMBUS_RET_OK);
}

int8_t SMBus_controllerSendByte(SMBus *smbus,
                            uint8_t targetAddr,
                            uint8_t txData)
{
    if(smbus->nwk.eState != SMBus_NwkState_Idle)
    {
        return(SMBUS_RET_ERROR);
    }
    smbus->nwk.currentCmd = txData;
    smbus->nwk.rxLen = 0;  //No read
    smbus->nwk.txLen = 1; // Only Command(Data)
    smbus->nwk.eState = SMBus_NwkState_TX;
    smbus->nwk.currentAddr = targetAddr;

    SMBus_NWK_startTxTransfer(smbus);

    return(SMBUS_RET_OK);
}

int8_t SMBus_controllerReceiveByte(SMBus *smbus,
                               uint8_t targetAddr,
                               uint8_t *rxData)
{
    if(smbus->nwk.eState != SMBus_NwkState_Idle)
    {
        return(SMBUS_RET_ERROR);
    }
    smbus->nwk.rxLen = 1;  //Read 1 byte
    smbus->nwk.rxBuffPtr = rxData;
    smbus->nwk.txLen = 0; // Only Command(Data)
    smbus->nwk.eState = SMBus_NwkState_RX;
    smbus->nwk.currentAddr = targetAddr;

    // Send Start and stop after address is sent
    SMBus_NWK_startRxTransfer(smbus);

    return(SMBUS_RET_OK);
}

int8_t SMBus_controllerReadBlock(SMBus *smbus,
                             uint8_t targetAddr,
                             uint8_t command,
                             uint8_t *rxData)
{
    if(smbus->nwk.eState != SMBus_NwkState_Idle)
    {
        return(SMBUS_RET_ERROR);
    }

    smbus->nwk.currentCmd = command;
    smbus->nwk.rxLen = 1;
    smbus->nwk.rxBuffPtr = rxData;
    smbus->nwk.txLen = 1; // Only send command
    smbus->nwk.eState = SMBus_NwkState_TX_Block;
    smbus->nwk.currentAddr = targetAddr;

    SMBus_NWK_startTxTransfer(smbus);

    return(SMBUS_RET_OK);
}

int8_t SMBus_controllerWriteBlock(SMBus *smbus,
                              uint8_t targetAddr,
                              uint8_t command,
                              uint8_t *txData,
                              uint16_t txSize)
{
    if(smbus->nwk.eState != SMBus_NwkState_Idle)
    {
        return(SMBUS_RET_ERROR);
    }
    if((txSize == 0) || (txSize > SMB_MAX_PAYLOAD_SIZE))
    {
        return(SMBUS_RET_ERROR);
    }

    smbus->nwk.currentCmd = command;
    smbus->nwk.rxLen = 0;
    smbus->nwk.txLen = txSize + 2; // Size includes Command and byte count
    smbus->nwk.txBuffPtr = txData;
    smbus->nwk.eState = SMBus_NwkState_TX_Block;
    smbus->nwk.currentAddr = targetAddr;

    SMBus_NWK_startTxTransfer(smbus);

    return(SMBUS_RET_OK);
}

int8_t SMBus_controllerReadByteWord(SMBus *smbus,
                                uint8_t targetAddr,
                                uint8_t command,
                                uint8_t *rxData,
                                uint8_t rxSize)
{
    if(smbus->nwk.eState != SMBus_NwkState_Idle)
    {
        return(SMBUS_RET_ERROR);
    }

    if((rxSize != 1) && (rxSize != 2) && (rxSize != 4) && (rxSize != 8))
    {
        return(SMBUS_RET_ERROR);
    }

    smbus->nwk.currentCmd = command;
    smbus->nwk.rxLen = rxSize; // Read 1 or 2 bytes
    smbus->nwk.rxBuffPtr = rxData;
    smbus->nwk.txLen = 1; // Only send command
    smbus->nwk.eState = SMBus_NwkState_TX;
    smbus->nwk.currentAddr = targetAddr;

    SMBus_NWK_startTxTransfer(smbus);

    return(SMBUS_RET_OK);
}

int8_t SMBus_controllerWriteByteWord(SMBus *smbus,
                                 uint8_t targetAddr,
                                 uint8_t command,
                                 uint8_t *txData,
                                 uint8_t txSize)
{
    if(smbus->nwk.eState != SMBus_NwkState_Idle)
    {
        return(SMBUS_RET_ERROR);
    }

    if((txSize != 1) && (txSize != 2))
    {
        return(SMBUS_RET_ERROR);
    }

    smbus->nwk.currentCmd = command;
    smbus->nwk.rxLen = 0; // Read 1 or 2 bytes
    smbus->nwk.txLen = 1 + txSize; // Command + Size
    smbus->nwk.txBuffPtr = txData;
    smbus->nwk.eState = SMBus_NwkState_TX;
    smbus->nwk.currentAddr = targetAddr;

    SMBus_NWK_startTxTransfer(smbus);

    return(SMBUS_RET_OK);
}

int8_t SMBus_controllerQuickCommand(SMBus *smbus,
                                uint8_t targetAddr,
                                bool write)
{
    if(smbus->nwk.eState != SMBus_NwkState_Idle)
    {
        return(SMBUS_RET_ERROR);
    }

    if(write != true)
    {
        return(SMBUS_RET_ERROR);
    }

    smbus->nwk.rxLen = 0;  //No read
    smbus->nwk.txLen = 0; // No Command
    smbus->nwk.eState = SMBus_NwkState_TXQuickCMD;
    smbus->nwk.currentAddr = targetAddr;

    if(write == true)
    {
        SMBus_NWK_startTxTransfer(smbus);
    }

    return(SMBUS_RET_OK);
}

int8_t SMBus_controllerWaitUntilDone(SMBus *smbus,
                                 int32_t timeout)
{
    while((smbus->nwk.eState != SMBus_NwkState_Idle) && timeout)
    {
        timeout--;
    }

    if(!timeout)
    {
        return(SMBUS_RET_ERROR);
    }
    else
    {
        return(SMBUS_RET_OK);
    }
}

void SMBus_controllerEnableHostNotify(SMBus *smbus, uint8_t *hostAlertBuffer)
{
    SMBus_NWK_controllerEnableHostNotify(smbus, hostAlertBuffer);
    SMBus_PHY_controllerEnableHostNotify(smbus);
    smbus->ctrl.bits.hostNotifyEn = 1;
}

void SMBus_controllerDisableHostNotify(SMBus *smbus)
{
    SMBus_NWK_controllerDisableHostNotify(smbus);
    SMBus_PHY_controllerDisableHostNotify(smbus);
    smbus->ctrl.bits.hostNotifyEn = 0;
}
