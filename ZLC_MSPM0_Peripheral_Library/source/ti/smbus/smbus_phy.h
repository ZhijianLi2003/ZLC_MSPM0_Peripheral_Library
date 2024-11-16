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
#ifndef __SMBUS_PHY_H__
#define __SMBUS_PHY_H__

//*****************************************************************************
//
//! \addtogroup smbus_MSPM0_phy MSPM0 PHY layer
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

#include "smbus_phy.h"
#include "smbus.h"

/*! R/W state when write is received */
#define I2C_WRITE      0
/*! R/W state when read is received */
#define I2C_READ       1

/*! Software timeout to avoid lockup */
#define SMB_SW_TIMEOUT              (10000)
/*! Delay cycles after reseting the I2C interface on timeout */
#define SMB_TIMEOUT_WAIT_CYCLES     (200)
/*! Delay cycles for module Power up */
#define SMB_POWER_STARTUP_DELAY     (16)

//*****************************************************************************
//
//! \brief   Disables the PHY and Data Link layer
//
//! \param *smbus     Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_disable(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Enables the PHY and Data Link layer for target operation
//
//! \param *smbus     Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_targetEnable(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Initializes the I2C Target module supporting SMBus functionality
//
//!  - Resets and then configures the I2C for SMBus support
//!  - I2C is enabled using Automatic ACK and Target address is initialized to 0x00
//!  - Call SMBus_targetSetAddress() in order to set the Target address
//
//! \param *smbus     Pointer to SMBus structure
//! \param i2cAddr    Base address of I2C module
//
// \return  None
//
//*****************************************************************************
extern void SMBus_PHY_targetInit(SMBus *smbus,
                                I2C_Regs *i2cAddr);

//*****************************************************************************
//
//! \brief   Enables the I2C interrupts
//
//!  This function enables the I2C Start ,Stop, RX ,TX, Timeout interrupts.
//!  SMBus_PHY_targetInit() must be called before this function.
//
//! \param *smbus     Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_targetEnableInt(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Disables the I2C interrupts
//
//!  This function disables the I2C Start ,Stop, RX ,TX, Timeout interrupts.
//
//! \param *smbus     Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_targetDisableInt(SMBus *smbus);

//*****************************************************************************
//
//! \brief   I2C Interrupt Service routine for SMBus Target
//
//!  Handles the interrupts from I2C module and passes the information to
//!  the network layer. Should be called by application when acting as
//!  a target and an I2C interrupt is detected.
//!  Note that a target can also act as Host in some scenarios (like Host
//!  notify), so the ISR needs to handle such cases.
//
//! \param smbus    Pointer to SMBus structure
//
//! \return  The new state of Target (see SMBus_targetProcessInt())
//
//*****************************************************************************
extern SMBus_State SMBus_PHY_targetProcessInt(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Sets the number of bytes left to be counted. 
//
//!  This function should be called when the number of bytes left to be 
//!  received is known by the application.
//!  Once written, the I2C hardware will calculate the PEC and either indicate
//!  that the PEC was checked correctly, or than a PEC error occurred. 
//
//! \param smbus    Pointer to SMBus structure
//! \param length   Number of bytes left to be counted in current packet
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_targetSetPECCount(SMBus * smbus, uint16_t length);

//*****************************************************************************
//
//! \brief   Send a Manual ACK or NACK depending on data validity
//
//!  Sends a NACK or ACK manually.
//!  Note that the bus is stretched by the I2C hardware until data is validated
//!   and a NACK/ACK is sent.
//
//! \param smbus    Pointer to SMBus structure
//! \param ackVal   true for ACK, false for NACK
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_targetManualACK(SMBus *smbus, bool ackVal);

//*****************************************************************************
//
//! \brief   Enables the PHY and Data Link layer
//
//! \param *smbus     Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_controllerEnable(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Initializes the I2C Controller module supporting SMBus functionality
//
//! - Resets and then configures the I2C for SMBus support
//! - I2C is enabled using Automatic ACK and Target address is initialized to 0x00
//
//! \param smbus      Pointer to SMBus structure
//! \param i2cAddr    Base address of I2C module
//! \param busClk     SMCLK Frequency (used for I2C)
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_controllerInit(SMBus *smbus,
                                 I2C_Regs *i2cAddr,
                                 uint32_t busClk);

//*****************************************************************************
//
//! \brief   Enables the I2C interrupts for Controller
//
//!  This function enables the I2C Start, Stop, RX,TX, Timeout interrupts.
//!  SMBus_PHY_targetInit() must be called before this function.
//
//! \param *smbus     Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_controllerEnableInt(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Disables the I2C interrupts for Controller
//
//!  This function disables the I2C Start, Stop, RX,TX, Timeout interrupts.
//
//! \param *smbus     Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_controllerDisableInt(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Generate Stop condition if it hasn't been sent
//
//! \param smbus      Pointer to SMBus structure
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_controllerSendStop(SMBus *smbus);


//*****************************************************************************
//
//! \brief   Start a TX transfer
//
//! \param smbus      Pointer to SMBus structure
//! \param targetaddr Target target address
//! \param length     Number of bytes to send, not including the address byte
//! \param stopFlag   Indicates whether the HW will generate stop condition
//! \param setPEC   Packet Error Checking (PEC) count value
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_controllerStartTx(SMBus *smbus,
                                    uint8_t targetaddr,
                                    uint16_t length,
                                    SMBus_Stop stopFlag,
                                    uint8_t setPEC);

//*****************************************************************************
//
//! \brief   Start a RX transfer
//! \param smbus      Pointer to SMBus structure
//! \param targetaddr Target target address
//! \param length     Number of bytes to send, not including the address byte
//! \param stopFlag   Indicates whether the HW will generate stop condition
//! \param startFlag  Indicates whether the HW will generate start condition
//! \param ackFlag    Indicates whether the HW will auto ack the last byte
//! \param setPEC   Packet Error Checking (PEC) count value
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_PHY_controllerStartRx(SMBus *smbus,
                                    uint8_t targetaddr,
                                    uint16_t length,
                                    SMBus_Start startFlag,
                                    SMBus_Stop stopFlag,
                                    SMBus_Auto_Ack ackFlag,
                                    uint8_t setPEC);

//*****************************************************************************
//
//! \brief   I2C Interrupt Service routine for SMBus Controller
//
//!  Handles the interrupts from I2C module and passes the information to
//!  the network layer. Should be called by application when acting as
//!  a controller and an I2C interrupt is detected.
//!  Note that a controller can also act as target in some scenarios (like Host
//!  notify), so the ISR needs to handle such cases.
//
//! \param smbus    Pointer to SMBus structure
//
//! \return  The new state of controller (see SMBus_controllerProcessInt())
//
//*****************************************************************************
extern SMBus_State SMBus_PHY_controllerProcessInt(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Enable the hardware functionality to respond to Host Default
//!          address (0b000_1000)
//
//! \param smbus    Pointer to SMBus structure
//
//! \return  The new state of controller (see SMBus_controllerProcessInt())
//
//*****************************************************************************
extern void SMBus_PHY_controllerEnableHostNotify(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Disable the hardware functionality to respond to Host Default
//!          address (0b000_1000)
//
//! \param smbus    Pointer to SMBus structure
//
//! \return  The new state of controller (see SMBus_controllerProcessInt())
//
//*****************************************************************************
extern void SMBus_PHY_controllerDisableHostNotify(SMBus *smbus);

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

#endif //__SMBUS_PHY_H__
