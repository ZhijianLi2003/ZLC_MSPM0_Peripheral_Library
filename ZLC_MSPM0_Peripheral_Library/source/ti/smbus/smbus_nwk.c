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

#include <stdint.h>
#include "smbus.h"
#include "smbus_nwk.h"
#include "smbus_phy.h"

uint16_t SMBus_NWK_getRxPayloadSize(SMBus *smbus)
{
    uint16_t data_size = smbus->nwk.rxIndex;

    if(smbus->ctrl.bits.pecEn == 1)
    {
        data_size--;   // Remove 1 byte for PEC
    }
    return(data_size);
}

void SMBus_NWK_startTxTransfer(SMBus *smbus)
{
    uint8_t targetAddr = smbus->nwk.currentAddr;
    uint16_t length = smbus->nwk.txLen;
    SMBus_Stop stop;
    SMBus_Auto_Ack ack;
    uint8_t setPEC;

    // Reset state
    smbus->state = SMBus_State_OK;
    smbus->nwk.rxIndex = 0;
    smbus->nwk.txIndex = 0;


    // TX only
    if (smbus->nwk.rxLen == 0) {
        stop = SMBus_Stop_After_Transfer; // Nothing after TX only, so send a stop
        ack = SMBus_Auto_Ack_Last_Byte; // ack is a don't care because the target will perform the ack

        if ((smbus->nwk.eState != SMBus_NwkState_TXQuickCMD) && ((smbus->nwk.eState != SMBus_NwkState_TXHostAlert)))
        {
          if (smbus->ctrl.bits.pecEn == 1) {
              // Add 1 to account for pec after payload
              length += 1;
          }
        }
        if (smbus->nwk.eState != SMBus_NwkState_TXHostAlert){
            setPEC = 1;
        }
        else
        {
            setPEC = 0;
        }
    }
    // TX packet followed by RX
    else
    {
        stop = SMBus_No_Stop_After_Transfer; // Repeated start so NO stop between TX and RX
        ack = SMBus_Auto_Ack_Last_Byte; // ack is a don't care because the target will perform the ack
        setPEC = 0;
    }

    SMBus_PHY_controllerStartTx(smbus, targetAddr, length, stop, setPEC);
}

void SMBus_NWK_startRxTransfer(SMBus *smbus)
{
    SMBus_Start start;
    SMBus_Stop stop;
    SMBus_Auto_Ack ack;
    uint8_t setPEC = 1;

    smbus->nwk.rxIndex = 0;
    smbus->nwk.pecBlockLenOverride = 0;
    smbus->state = SMBus_State_OK;

    if(smbus->ctrl.bits.pecEn == 1)
    {
        smbus->nwk.rxLen++;
    }

    SMBus_NwkState next_eState;
    uint16_t length = smbus->nwk.rxLen;
    if(smbus->nwk.eState == SMBus_NwkState_RX)
    {
        next_eState = SMBus_NwkState_RX;

        start = SMBus_Start_Before_Transfer;
        stop = SMBus_Stop_After_Transfer;
        ack = SMBus_No_Auto_Ack_Last_Byte;

    }
    else if(smbus->nwk.eState == SMBus_NwkState_TX)
    {
        next_eState = SMBus_NwkState_RX;

        start = SMBus_Start_Before_Transfer;
        stop = SMBus_Stop_After_Transfer;
        ack = SMBus_No_Auto_Ack_Last_Byte;

    }
    else if(smbus->nwk.eState == SMBus_NwkState_TX_Block)
    {
        next_eState = SMBus_NwkState_RX_Block_Byte_Count;

        start = SMBus_Start_Before_Transfer;
        stop = SMBus_No_Stop_After_Transfer;
        ack = SMBus_Auto_Ack_Last_Byte;

        // Don't enable PEC on the first portion of the TX block transfer because
        // it's only the byte_count. The main payload will be transfer after.
        setPEC = 0;

        // The first byte of the RX block is the length (which is only 1 byte).
        // The first read transaction gets the length of
        // the payload. Once the length is known a new
        // transaction will read the entire payload
        length = 1;

    }
    else
    {
        next_eState = SMBus_NwkState_Error;
    }

    smbus->nwk.eState = next_eState;
    SMBus_PHY_controllerStartRx(smbus, smbus->nwk.currentAddr, length, start, stop, ack, setPEC);

}

void SMBus_NWK_startRxBlockPayloadTransfer(SMBus *smbus) {

    SMBus_Start start;
    SMBus_Stop stop;
    SMBus_Auto_Ack ack;
    SMBus_NwkState next_eState;
    uint16_t length;

    if(smbus->nwk.eState == SMBus_NwkState_RX_Block_Byte_Count)
    {
        next_eState = SMBus_NwkState_RX_Block_Payload;

        start = SMBus_No_Start_Before_Transfer;
        stop = SMBus_Stop_After_Transfer;
        ack = SMBus_No_Auto_Ack_Last_Byte;

        // A block read operation is split into 2 I2C transfer regions from the perspective of the
        // HW: RX_Block_Byte_Count and RX_Block_Payload. This function is called during the transition
        // from RX_Block_Byte_Count to RX_Block_Payload. Since rxLen contains the total amount of bytes
        // to be transfered (including the byte count) we need to subtract 1 byte because the byte count
        // has already been sent.
        length = smbus->nwk.rxLen - 1;

    }
    else
    {
        // This function should only be called after the RX_Block_Byte_Count transfer has happened, any
        // other state is invalid
        next_eState = SMBus_NwkState_Error;
    }

    // Enable I2C HW PEC by default
    uint8_t setPEC = 1;

    smbus->nwk.eState = next_eState;
    SMBus_PHY_controllerStartRx(smbus, smbus->nwk.currentAddr, length, start, stop, ack, setPEC);

}

SMBus_State SMBus_NWK_targetProcessStart(SMBus *smbus,
                                        uint8_t addrRw)
{

    SMBus_State ret_state = SMBus_State_OK;

    // Init counters and variables
    smbus->nwk.txIndex = 0;
    smbus->nwk.currentAddr = addrRw;

    /* Handle Target Start when used as SMBus Target */
    if (smbus->ctrl.bits.controller == 0)
    {
        // SMBus set the PEC counter to 0. It will be set correctly before it is needed.
        DL_I2C_setTargetPECCountValue(smbus->phy.SMBus_Phy_i2cBase, 0);

        // Clear rxIndex if previous bus state was Idle. If the bus was
        // not idle assume we are in a restart condition where the application
        // may want to read this counter
        if (smbus->nwk.eState == SMBus_NwkState_Idle)
        {
            smbus->nwk.rxIndex = 0;
        }

        if((smbus->state == SMBus_State_Target_QCMD) ||
           (smbus->state == SMBus_State_Target_CmdComplete))
        {
            // If the previous packet wasn't cleared by application, flag overrun
            smbus->status.bits.packOvrErr = 1;
        }

        // If we receive a start condition and eState is RX we assume that
        // the host is requesting to read back data
        if(smbus->nwk.eState == SMBus_NwkState_RX)
        {
            smbus->nwk.txLen = 0;  // Nothing to respond by default
            // Previous Start was a Write from the host. This is a restart condition.
            // Process packet and prepare response

            ret_state = SMBus_State_Target_CmdComplete; // Command is ready to process
            smbus->nwk.eState = SMBus_NwkState_TX_Resp;  // Responding
        }
    }
    else
    {
        /* Handle Target Start when used as SMBus Controller */
        smbus->nwk.rxIndex = 0;
        if ((smbus->nwk.currentAddr == SMB_HOST_DEFAULT_ADDRESS) && (smbus->ctrl.bits.hostNotifyEn))
        {
            /* Expecting to receive 3 bytes for Host Notify */
            smbus->nwk.rxLen = 3;
        }
    }

    return(ret_state);
}

SMBus_State SMBus_NWK_targetProcessRx(SMBus *smbus,
                                     uint8_t data)
{

    SMBus_State ret_state = SMBus_State_OK;

    /* Handle Target RX when used as SMBus Target */
    if (smbus->ctrl.bits.controller == 0)
    {
        // Host is requesting to Write data
        if(smbus->nwk.eState == SMBus_NwkState_Idle)
        {
            // Default packet is QUICK_COMMAND(W) unless data is received
            smbus->nwk.rxIndex = 0;
            smbus->nwk.eState = SMBus_NwkState_RX;
        }

        // Check if the SMBus is expecting reception
        if(smbus->nwk.eState != SMBus_NwkState_RX)
        {
            smbus->status.bits.packErr = 1;
            smbus->nwk.eState = SMBus_NwkState_Error;
            SMBus_PHY_targetManualACK(smbus, false);
            return(SMBus_State_Target_Error);
        }
        // Check packet size
        if((smbus->nwk.rxIndex >= SMB_MAX_PACKET_SIZE) ||
           (smbus->nwk.rxIndex >= smbus->nwk.rxSize))
        {
            smbus->status.bits.packErr = 1;
            smbus->nwk.eState = SMBus_NwkState_Error;
            SMBus_PHY_targetManualACK(smbus, false);
            return(SMBus_State_DataSizeError);
        }
        if((smbus->nwk.rxBuffPtr == NULL) || (smbus->nwk.rxSize == 0))
        {
            // Buffer hasn't been initialized
            smbus->nwk.eState = SMBus_NwkState_Error;
            SMBus_PHY_targetManualACK(smbus, false);
            return(SMBus_State_Target_NotReady);
        }

        // If no errors, continue
        if((smbus->state == SMBus_State_Target_FirstByte) ||
           (smbus->state == SMBus_State_Target_ByteReceived))
        {
            // Previous byte wasn't processed, flag byte overrun
            smbus->status.bits.byteOvrErr = 1;
        }

        smbus->nwk.rxBuffPtr[smbus->nwk.rxIndex] = data;
        // Pass the packet to application network, note that the SMBus spec
        // requires to validate the cmd+data and ACK/NACK appropiately and
        // immediately depending on its validity.
        smbus->phy.SMBus_Phy_AckPending = true;
        if(smbus->nwk.rxIndex == 0)
        {
            // First byte (command) was received. Application should use this
            // state in order to validate the command
            ret_state = SMBus_State_Target_FirstByte;
            smbus->nwk.currentCmd = data;
        }
        else if (smbus->nwk.pecBlockLenOverride == 1){
            // The first byte was received and the application has reported a block
            // back to the network, such that the next byte received is to be
            // interpreted as the length (including PEC BYTE)
            SMBus_PHY_targetSetPECCount(smbus, data+1);
            smbus->nwk.pecBlockLenOverride = 0;
            ret_state = SMBus_State_Target_ByteReceived;
        }
        else
        {
            // Data byte was received. Application can use this to process each
            // byte
            ret_state = SMBus_State_Target_ByteReceived;
        }
        smbus->nwk.rxIndex++;
    }
    else
    {
        /* Handle Target RX when used as SMBus Controller */
        if ( (smbus->nwk.currentAddr == SMB_HOST_DEFAULT_ADDRESS) && (smbus->ctrl.bits.hostNotifyEn))
        {
            if((smbus->nwk.rxIndex >= SMB_MAX_PACKET_SIZE) ||
                       (smbus->nwk.rxIndex >= smbus->nwk.rxLen))
            {
                smbus->status.bits.packErr = 1;
                smbus->nwk.eState = SMBus_NwkState_Error;
                return(SMBus_State_DataSizeError);
            }
            else
            {
                smbus->nwk.hostNotifyRxBuffPtr[smbus->nwk.rxIndex] = data;
                smbus->nwk.rxIndex++;
            }
        }
    }

    return(ret_state);
}

SMBus_State SMBus_NWK_targetProcessTx(SMBus *smbus,
                                     uint8_t *data)
{

    SMBus_State ret_state = SMBus_State_OK;
    *data = RESPONSE_NTR;   // Default data if nothing to report

    /* Handle Target TX when used as SMBus Target */
    if (smbus->ctrl.bits.controller == 0)
    {
        if(smbus->nwk.eState == SMBus_NwkState_Idle)
        {
            // If the previous state was not Write_Req, then we need to respond
            // to a receive byte or QUICK_COMMAND(R)
            // We can't recognize QUICK_COMMAND(R) because of the double-buffer
            // mechanism. By default, we will try to respond as a RECEIVE_BYTE
            // sending the TxPtr
            smbus->nwk.txLen = 1;
            smbus->nwk.eState = SMBus_NwkState_TX;
        }

        if((smbus->nwk.eState != SMBus_NwkState_TX_Resp) &&
           (smbus->nwk.eState != SMBus_NwkState_TX))
        {
            // Invalid state
            smbus->status.bits.packErr = 1;
            smbus->nwk.eState = SMBus_NwkState_Error;
            return(SMBus_State_Target_Error);
        }

        if((smbus->nwk.txIndex > SMB_MAX_PACKET_SIZE) ||
           (smbus->nwk.txIndex > smbus->nwk.txSize))
        {
            smbus->status.bits.packErr = 1;
            smbus->nwk.eState = SMBus_NwkState_Error;
            return(SMBus_State_DataSizeError);
        }

        if((smbus->nwk.txBuffPtr == NULL) || (smbus->nwk.txSize == 0))
        {
            // Buffer hasn't been initialized
            smbus->nwk.eState = SMBus_NwkState_Error;
            return(SMBus_State_Target_NotReady);
        }

        // If no errors, continue
        if(smbus->nwk.txIndex < smbus->nwk.txLen)
        {
            if(smbus->nwk.eState == SMBus_NwkState_TX)
            {
                // Send the TX Pointer if this is a RECEIVE_BYTE
                *data = *smbus->nwk.recByteTxPtr;
            }
            else
            {
                // Send buffer if this is a Response
                *data = smbus->nwk.txBuffPtr[smbus->nwk.txIndex];
            }
            smbus->nwk.txIndex++;
        }
        else if((smbus->ctrl.bits.pecEn == 1)  &&
                (smbus->nwk.txIndex == smbus->nwk.txLen))
        {
            DL_I2C_setTargetPECCountValue(smbus->phy.SMBus_Phy_i2cBase, 1);
            *data = 0x00; // Dummy data, I2C PEC HW will overlay correct PEC value
            smbus->nwk.txIndex++;
        }
    }


    return(ret_state);
}

SMBus_State SMBus_NWK_targetProcessStop(SMBus *smbus)
{
    SMBus_State ret_state = SMBus_State_OK;

    /* Handle Target Stop when used as SMBus Target */
    if (smbus->ctrl.bits.controller == 0)
    {
        // Quick command is detected when a TX is detected with no data
        // We can't detect Quick_Command(R) because of double-buffer mechanism
        if(smbus->nwk.eState == SMBus_NwkState_RX)
        {
            if(smbus->nwk.rxIndex == 0)
            {
                // Process quick command
                ret_state = SMBus_State_Target_QCMD;
            }
            else {
                /* Check if a PEC was processed correctly */
                if (smbus->ctrl.bits.pecEn == 1)
                {
                    if ( (DL_I2C_getTargetPECCheckedStatus(smbus->phy.SMBus_Phy_i2cBase) !=
                        DL_I2C_TARGET_PEC_STATUS_CHECKED) ||
                         (DL_I2C_getTargetPECCheckError(smbus->phy.SMBus_Phy_i2cBase) !=
                          DL_I2C_TARGET_PEC_CHECK_ERROR_CLEARED) )
                    {
                        smbus->nwk.eState = SMBus_NwkState_Error;
                        ret_state = SMBus_State_Target_Error;
                    }
                    else
                    {
                        ret_state = SMBus_State_Target_CmdComplete;
                    }
                }
                else
                {
                    ret_state = SMBus_State_Target_CmdComplete;
                }
            }
        }
        else if((smbus->nwk.eState == SMBus_NwkState_Idle) &&
                (smbus->nwk.rxIndex == 0))
        {
            // case when Quick command is detected but Stop flag cleared Start
            // before it was set
            ret_state = SMBus_State_Target_QCMD;
        }
        else
        {
            // If the state is SMBus_State_Respond or SMBus_State_ReadReq, then we
            // don't need to do anything during a stop
        }

        /* Restart PEC */
        if (smbus->ctrl.bits.pecEn == 1)
        {
            DL_I2C_setTargetPECCountValue(smbus->phy.SMBus_Phy_i2cBase, 0);
        }
        // Set the network state machine to idle in order to get new packet
        smbus->nwk.eState = SMBus_NwkState_Idle;
    }
    else
    {
        /* Handle Target Stop when used as SMBus Controller */
        if ( (smbus->nwk.currentAddr == SMB_HOST_DEFAULT_ADDRESS) &&
             (smbus->ctrl.bits.hostNotifyEn) )
        {
            ret_state = SMBus_State_Controller_HostNotify;
        }
    }

    return(ret_state);
}

SMBus_State SMBus_NWK_targetProcessTimeout(SMBus *smbus)
{
    // Signal the error
    smbus->status.bits.toErr = 1;

    // Restart the SMBus Interface
    SMBus_PHY_disable(smbus);
    delay_cycles(SMB_TIMEOUT_WAIT_CYCLES);
    SMBus_PHY_targetEnable(smbus);
    // After restart, be ready to accept new packet
    smbus->nwk.eState = SMBus_NwkState_Idle;

    return(SMBus_State_TimeOutError);
}

SMBus_State SMBus_NWK_controllerProcessRx(SMBus *smbus,
                                      uint8_t data)
{
    uint16_t data_len = smbus->nwk.rxLen;
    if((smbus->nwk.eState != SMBus_NwkState_RX) &&
       (smbus->nwk.eState != SMBus_NwkState_RX_Block_Byte_Count) &&
       (smbus->nwk.eState != SMBus_NwkState_RX_Block_Payload))
    {
        SMBus_PHY_controllerSendStop(smbus);
        smbus->nwk.eState = SMBus_NwkState_Error;
        smbus->state = SMBus_State_Controller_Error;
        return(smbus->state);
    }
    if((smbus->nwk.rxIndex >= smbus->nwk.rxLen) ||
       (smbus->nwk.rxIndex >= SMB_MAX_PACKET_SIZE))
    {
        SMBus_PHY_controllerSendStop(smbus);
        smbus->status.bits.packErr = 1;
        smbus->nwk.eState = SMBus_NwkState_Error;
        smbus->state = SMBus_State_DataSizeError;
        return(smbus->state);
    }

    if((smbus->nwk.rxIndex == 0) &&
       (smbus->nwk.eState == SMBus_NwkState_RX_Block_Byte_Count))
    {

        // Update the length based on received Byte count
        if((data == 0) || (data > SMB_MAX_PAYLOAD_SIZE))
        {
            SMBus_PHY_controllerSendStop(smbus);
            smbus->status.bits.packErr = 1;
            smbus->nwk.eState = SMBus_NwkState_Error;
            smbus->state = SMBus_State_DataSizeError;
            return(smbus->state);
        }
        else
        {
            smbus->nwk.rxLen = data + 1; // One extra byte due to Byte count
            if(smbus->ctrl.bits.pecEn == 1)
            {
                smbus->nwk.rxLen++;
            }
            SMBus_NWK_startRxBlockPayloadTransfer(smbus);
            return(smbus->state);
        }
    }
    // If no error continue

    if(smbus->ctrl.bits.pecEn == 1)
    {
        data_len--;
    }

    // Store the received byte
    if(smbus->nwk.rxIndex < data_len)
    {
        smbus->nwk.rxBuffPtr[smbus->nwk.rxIndex] = data;
    }

    smbus->nwk.rxIndex++;

    return(smbus->state);
}

SMBus_State SMBus_NWK_controllerProcessTx(SMBus *smbus,
                                      uint8_t *data)
{
    if (smbus->nwk.eState == SMBus_NwkState_Idle)
    {
        /* Ignore if TX is triggered during initialization */
        *data = 0;
        return(smbus->state);
    }
    // Check current state of the State Machine
    if((smbus->nwk.eState != SMBus_NwkState_TX_Block) &&
       (smbus->nwk.eState != SMBus_NwkState_TX) &&
       (smbus->nwk.eState != SMBus_NwkState_TXQuickCMD) &&
       (smbus->nwk.eState != SMBus_NwkState_TXHostAlert))
    {
        smbus->nwk.eState = SMBus_NwkState_Error;
        smbus->state = SMBus_State_Controller_Error;
        return(smbus->state);
    }


    if(smbus->nwk.txIndex < smbus->nwk.txLen)
    {
        if(smbus->nwk.txIndex == 0)
        {
            // Start by sending the command (1st byte)
            *data = smbus->nwk.currentCmd;
        }
        else if((smbus->nwk.txIndex == 1) &&
                (smbus->nwk.eState == SMBus_NwkState_TX_Block))
        {
            *data = smbus->nwk.txLen - 2;    // Send Byte count
        }
        else
        {
            if(smbus->nwk.eState == SMBus_NwkState_TX_Block)
            {
                *data = smbus->nwk.txBuffPtr[smbus->nwk.txIndex - 2];
            }
            else
            {
                *data = smbus->nwk.txBuffPtr[smbus->nwk.txIndex - 1];
            }
        }
    }
    else if((smbus->nwk.txIndex == smbus->nwk.txLen) && (smbus->ctrl.bits.pecEn == 1))
    {
         *data = 0x00; // Dummy byte, HW will overlay correct PEC value
    }
    else
    {
        // This pathway implies that txIndex is an unexpected value. Return with an error.
//        __BKPT(0);
//        smbus->nwk.eState = SMBus_NwkState_Error;
//        smbus->state = SMBus_State_Controller_Error;
    }

    smbus->nwk.txIndex++;

    return(smbus->state);
}

SMBus_State SMBus_NWK_controllerTxDone(SMBus *smbus)
{
    // Controller TX Done is only used during a compound transaction
    // where the controller is doing a write immediately followed by a read.
    // Instead of relying on STOP the controller will use TX_DONE
    // to signal the transition from TX to RX
    if(smbus->nwk.rxLen > 0)
    {
        SMBus_NWK_startRxTransfer(smbus);
    }
    return(smbus->state);
}

SMBus_State SMBus_NWK_controllerProcessStop(SMBus *smbus)
{
    /* Handle Stop bit as a Controller */
    if (smbus->ctrl.bits.controller == 1)
    {
        if((smbus->nwk.eState == SMBus_NwkState_RX) ||
           (smbus->nwk.eState == SMBus_NwkState_RX_Block_Payload))
        {
            if(smbus->ctrl.bits.pecEn == 1)
            {
                if(DL_I2C_getRawInterruptStatus(smbus->phy.SMBus_Phy_i2cBase,
                                  DL_I2C_INTERRUPT_CONTROLLER_PEC_RX_ERROR) ==
                                  DL_I2C_INTERRUPT_CONTROLLER_PEC_RX_ERROR)
                {
                    smbus->status.bits.pecErr = 1;
                    smbus->nwk.eState = SMBus_NwkState_Idle;
                    smbus->state = SMBus_State_PECError;
                }
            }
        }
        // Set machine to Idle in order to set next packet
        smbus->nwk.eState = SMBus_NwkState_Idle;
    }
    else
    {
        /*
         * When used as a Target, this routine is only used for Host Notify.
         */
        if (smbus->nwk.eState == SMBus_NwkState_TXHostAlert)
        {
            // Set machine to Idle in order to set next packet
            smbus->nwk.eState = SMBus_NwkState_Idle;
        }
    }

    return(smbus->state);
}

void SMBus_NWK_controllerReset(SMBus *smbus)
{
    // Restart the SMBus Interface
    SMBus_PHY_disable(smbus);
    SMBus_PHY_controllerEnable(smbus);
    // After restart, be ready to accept new packet
    smbus->nwk.eState = SMBus_NwkState_Idle;
}

SMBus_State SMBus_NWK_controllerProcessTimeout(SMBus *smbus)
{
    // Signal the error
    smbus->status.bits.toErr = 1;

    SMBus_NWK_controllerReset(smbus);

    smbus->state = SMBus_State_TimeOutError;

    return(smbus->state);
}

SMBus_State SMBus_NWK_controllerProcessNACK(SMBus *smbus)
{
    if(smbus->nwk.eState != SMBus_NwkState_Ending)
    {
        SMBus_PHY_controllerSendStop(smbus);
        smbus->nwk.eState = SMBus_NwkState_Error;
        smbus->state = SMBus_State_Controller_NACK;
    }
    else
    {
        smbus->state = SMBus_State_OK;
    }

    return(smbus->state);
}

void SMBus_NWK_controllerEnableHostNotify(SMBus *smbus, uint8_t *buff)
{
    smbus->nwk.hostNotifyRxBuffPtr = buff;
}

void SMBus_NWK_controllerDisableHostNotify(SMBus *smbus)
{
    /* Nothing to do */
}
