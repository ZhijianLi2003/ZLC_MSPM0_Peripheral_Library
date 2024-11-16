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
#ifndef __SMBUS_NWK_H__
#define __SMBUS_NWK_H__

//*****************************************************************************
//
//! \addtogroup smbus_nwk NWK layer
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Include files
//
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "smbus.h"

//*****************************************************************************
// Internal functions called by the physical layer and internal smbus
// processing. Application programs should not call these functions directly.
//*****************************************************************************
//*****************************************************************************
//
//! \brief   Returns the number of received bytes from last transaction
//
//! \param smbus       Pointer to SMBus structure
//
//! \return  Number of bytes in the RX buffer. PEC byte is *not* included.
//
//*****************************************************************************
extern uint16_t SMBus_NWK_getRxPayloadSize(SMBus *smbus);


//*****************************************************************************
//
//! \brief Start the TX transfer process
//
//! \param smbus       Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_NWK_startTxTransfer(SMBus *smbus);

//*****************************************************************************
//
//! \brief Start the RX transfer process
//
//! \param smbus       Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_NWK_startRxTransfer(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Start callback for SMBus
//
//! Handles the protocol when a Start is received. Depending on the
//! current state, the start could also mean re-start.
//
//!  \param smbus   Pointer to SMBus structure
//!  \param addrRw  Current Address+RW as received by PHY_DL
//
//! \return  SMBus_State value as follows:
//! - \b SMBus_State_Target_NotReady    : Packet in progress
//! - \b SMBus_State_PECError          : Packet was invalid
//! - \b SMBus_State_Target_CmdComplete : restart received after command,
//!                                      process previous packet
//
//*****************************************************************************
extern SMBus_State SMBus_NWK_targetProcessStart(SMBus *smbus,
                                               uint8_t addrRw);

//*****************************************************************************
//
//! \brief   RX callback for SMBus target
//
//! Handles the protocol when a reception is requested.
//
//!  \param smbus Pointer to SMBus structure
//!  \param data  Data byte as received by the PHY layer
//
//! \return  SMBus_State value as follows:
//!   - \b SMBus_State_OK
//!   - \b SMBus_State_Target_NotReady      : Packet in progress
//!   - \b SMBus_State_Target_FirstByte     : First byte (Command) was received
//!   - \b SMBus_State_Target_BlockLengthByte : Length byte (2nd) was received
//!   - \b SMBus_State_Target_ByteReceived  : Data byte (2-n) was received
//!   - \b SMBus_State_Target_Error         : not expecting RX
//!   - \b SMBus_State_Target_NotReady      : not ready for RX
//!   - \b SMBus_State_DataSizeError       : Max packet size exceeded
//
//*****************************************************************************
extern SMBus_State SMBus_NWK_targetProcessRx(SMBus *smbus,
                                            uint8_t data);

//*****************************************************************************
//
//! \brief   TX callback for SMBus target
//
//! Handles the protocol when a transmission is requested.
//
//!  \param smbus Pointer to SMBus structure
//!  \param *data Pointer to tranmission byte, must be written with value
//!               being sent
//
//! \return  SMBus_State value as follows:
//!   - \b SMBus_State_OK
//!   - \b SMBus_State_Target_NotReady      : Buffer not initialized
//!   - \b SMBus_State_Target_Error         : not expecting TX
//!   - \b SMBus_State_Target_NotReady      : not ready for TX
//!   - \b SMBus_State_DataSizeError       : Max packet size exceeded
//
//*****************************************************************************
extern SMBus_State SMBus_NWK_targetProcessTx(SMBus *smbus,
                                            uint8_t *data);

//*****************************************************************************
//
//! \brief   Stop callback for SMBus-based protocol
//
//! Handles SMus protocol when a stop is detected
//
//! \param smbus       Pointer to SMBus structure
//
//! \return  SMBus_State value as follows:
//! - \b SMBus_State_OK
//! - \b SMBus_State_Target_NotReady    : Packet in progress
//! - \b SMBus_State_PECError          : Packet was invalid
//! - \b SMBus_State_Target_QCMD        : Quick Command was detected
//! - \b SMBus_State_Target_CmdComplete : Stop was detected and packet is ready
//!                                      to process
//
//*****************************************************************************
extern SMBus_State SMBus_NWK_targetProcessStop(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Handles the SMBus protocol when a Timeout error is detected by PHY
//
//! \param smbus       Pointer to SMBus structure
//
//! \return  SMBus_State_TimeOutError
//
//*****************************************************************************
extern SMBus_State SMBus_NWK_targetProcessTimeout(SMBus *smbus);

//*****************************************************************************
//
//! \brief   RX callback for SMBus controller
//
//! Handles the protocol when a reception is requested.
//
//!  \param smbus Pointer to SMBus structure
//!  \param data  Data byte as received by the PHY layer
//
//! \return  SMBus_State value as follows:
//!   - \b SMBus_State_OK
//!   - \b SMBus_State_Controller_Error       : not expecting RX
//!   - \b SMBus_State_DataSizeError      : Max packet size exceeded, or greater
//!                                         than expected
//
//*****************************************************************************
extern SMBus_State SMBus_NWK_controllerProcessRx(SMBus *smbus,
                                             uint8_t data);

//*****************************************************************************
//
//! \brief   TX callback for SMBus controller
//
//! Handles the protocol when a transmission is requested.
//
//!  \param smbus Pointer to SMBus structure
//!  \param *data Pointer to tranmission byte, must be written with value
//!               being sent
//
//! \return  SMBus_State value as follows:
//!   - \b SMBus_State_OK
//!   - \b SMBus_State_Controller_Error        : not expecting TX
//
//*****************************************************************************
extern SMBus_State SMBus_NWK_controllerProcessTx(SMBus *smbus,
                                             uint8_t *data);


//*****************************************************************************
//
//! \brief   Process a Done condition, between restarts
//
//
//!  \param smbus Pointer to SMBus structure
//
//! \return  Current SMBus_State.
//
//*****************************************************************************
extern SMBus_State SMBus_NWK_controllerTxDone(SMBus *smbus);
//*****************************************************************************
//
//! \brief   Process a Stop condition
//
//
//!  \param smbus Pointer to SMBus structure
//
//! \return  SMBus_State value as follows:
//!   - \b SMBus_State_OK
//!   - \b SMBus_State_PECError
//
//*****************************************************************************
extern SMBus_State SMBus_NWK_controllerProcessStop(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Handles the SMBus protocol when a Timeout error is detected by PHY
//
//! \param smbus       Pointer to SMBus structure
//
//! \return  SMBus_State_TimeOutError
//
//*****************************************************************************
extern SMBus_State SMBus_NWK_controllerProcessTimeout(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Handles the SMBus protocol when a NACK
//
//! \param smbus       Pointer to SMBus structure
//
//! \return  SMBus_State value as follows:
//!   - \b SMBus_State_OK
//!   - \b SMBus_State_Controller_NACK
//
//*****************************************************************************
extern SMBus_State SMBus_NWK_controllerProcessNACK(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Resets the SMBus network layer
//
//! \param smbus       Pointer to SMBus structure
//
//! \return  none
//
//*****************************************************************************
extern void SMBus_NWK_controllerReset(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Enable network functions for Host Notify
//
//! \param smbus    Pointer to SMBus structure
//! \param buff     Pointer to Host Notify buffer
//
//! \return  The new state of controller (see SMBus_controllerProcessInt())
//
//*****************************************************************************
extern void SMBus_NWK_controllerEnableHostNotify(SMBus *smbus, uint8_t *buff);

//*****************************************************************************
//
//! \brief   Disable network functions for Host Notify
//
//! \param smbus    Pointer to SMBus structure
//
//! \return  The new state of controller (see SMBus_controllerProcessInt())
//
//*****************************************************************************
extern void SMBus_NWK_controllerDisableHostNotify(SMBus *smbus);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

#endif //__SMBUS_NWK_H__
