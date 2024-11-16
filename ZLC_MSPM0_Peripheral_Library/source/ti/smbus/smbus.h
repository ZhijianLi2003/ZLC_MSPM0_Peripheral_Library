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
#ifndef __SMBUS_H__
#define __SMBUS_H__

//*****************************************************************************
//
//! \addtogroup smbus Application API layer
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

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

//*****************************************************************************
// defines
//*****************************************************************************


//*****************************************************************************
// Configuration
//*****************************************************************************

//*****************************************************************************
//
//! Enables Host Notify support as target
//
//*****************************************************************************
#ifndef SMB_TARGET_SUPPORTS_HOST_NOTIFY
#define SMB_TARGET_SUPPORTS_HOST_NOTIFY         (true)
#endif

//*****************************************************************************
//
//! Enables Host Notify support as Controller
//
//*****************************************************************************
#ifndef SMB_CONTROLLER_SUPPORTS_HOST_NOTIFY
#define SMB_CONTROLLER_SUPPORTS_HOST_NOTIFY     (true)
#endif

//*****************************************************************************
// Constant definitions
//*****************************************************************************

//*****************************************************************************
//
//! Maximum payload as specified by SMBus Spec
//
//*****************************************************************************
#define SMB_MAX_PAYLOAD_SIZE                    (255)

//*****************************************************************************
//
//! Max packet size = Payload+PEC+CMD+Len
//
//*****************************************************************************
#define SMB_MAX_PACKET_SIZE                     (SMB_MAX_PAYLOAD_SIZE + 3)

//*****************************************************************************
//
//! Host Alert packet size = Address + Data Byte Low + Data Byte High
//
//*****************************************************************************
#define SMB_HOST_ALERT_PACKET_SIZE              (3)

//*****************************************************************************
//
//! Default Host Address used for Host Alert
//
//*****************************************************************************
#define SMB_HOST_DEFAULT_ADDRESS                (0x08)

//*****************************************************************************
//
//! Default response when there's nothing to send
//
//*****************************************************************************
#define RESPONSE_NTR                             0x00

//*****************************************************************************
//
//! Return value when successful
//
//*****************************************************************************
#define SMBUS_RET_OK                            (1)
#define SMBUS_RET_OK_FIXED                      (2)
#define SMBUS_RET_OK_BLOCK                      (3)


//*****************************************************************************
//
//! Return value when an error ocurred
//
//*****************************************************************************
#define SMBUS_RET_ERROR                         (-1)

//*****************************************************************************
//
//! Definition when using variable lenght for block transactions
//
//*****************************************************************************
#define SMBUS_BLOCK_LENGTH                      (0xFFFF)

//*****************************************************************************
// typedefs
//*****************************************************************************

//*****************************************************************************
//
//! List of stop codes used within the NWK and PHY layers
//
//*****************************************************************************
typedef enum
{
    SMBus_Stop_After_Transfer = 0,
    SMBus_No_Stop_After_Transfer
} SMBus_Stop;

//*****************************************************************************
//
//! List of start codes used within the NWK and PHY layers
//
//*****************************************************************************
typedef enum
{
    SMBus_Start_Before_Transfer = 0,
    SMBus_No_Start_Before_Transfer
} SMBus_Start;

//*****************************************************************************
//
//! List of auto ack codes used within the NWK and PHY layers
//
//*****************************************************************************
typedef enum
{
    SMBus_Auto_Ack_Last_Byte = 0,
    SMBus_No_Auto_Ack_Last_Byte
} SMBus_Auto_Ack;

//*****************************************************************************
//
//! SMBus control register
//
//*****************************************************************************
typedef union
{
    //*****************************************************************************
    //
    //! Defines the control bit fields
    //
    //*****************************************************************************
    struct
    {
    /*! Enables PEC functionality */
        uint8_t pecEn       : 1;
    /*! Enable Host Notify  */
        uint8_t hostNotifyEn : 1;
    /*! SW_ACK is enabled (read only) */
        uint8_t swackEn     : 1;
    /*! Interrupts are enabled (read only) */
        uint8_t intEn       : 1;
    /*! SMBus PHY is enabled (read only) */
        uint8_t phyEn       : 1;
    /*! Acting in Controller mode (read only) */
        uint8_t controller  : 1;
    /*! Reserved */
        uint8_t reserved2   : 2;
    } bits;
    //*****************************************************************************
    //
    //! Allows access to the writeable bits on the structure
    //
    //*****************************************************************************
    struct
    {
    /*! Control bits that are writable */
        uint8_t writeBits  : 2;
    /*! Masks the read only control */
        uint8_t reserved   : 6;
    } writeableBits;
    /*! Whole Control byte access */
    uint8_t u8byte;
} SMBus_Ctrl;

//*****************************************************************************
//
//! Physical and Data Link Layer object
//
//*****************************************************************************
typedef struct
{
    /*! I2C register map struct */
    I2C_Regs*  SMBus_Phy_i2cBase;  
    /*! Send different types of Stop as controller */
    SMBus_Stop SMBus_Phy_stop;     
    /*! Waiting for ACK */
    bool       SMBus_Phy_AckPending;
} SMBus_Phy;

//*****************************************************************************
//
//! SMBus network layer states
//
//*****************************************************************************
typedef enum
{
    /*! Network is idle and waiting for new packet */
    SMBus_NwkState_Idle = 0,              
    /*! Network is receiving a packet */
    SMBus_NwkState_RX,                    
    /*! Network is transmitting after receive byte */
    SMBus_NwkState_TX,
    /*! Network is transmitting Host Alert*/
    SMBus_NwkState_TXHostAlert,
    /*! Network is sending Quick Command */
    SMBus_NwkState_TXQuickCMD,            
    /*! Network is transmitting a response after restart */
    SMBus_NwkState_TX_Resp,               
    /*! Network is transmitting a block */
    SMBus_NwkState_TX_Block,              
    /*! Network is receiving a block */
    SMBus_NwkState_RX_Block_Byte_Count,   
    /*! Network is receiving a block */
    SMBus_NwkState_RX_Block_Payload,      
    /*! Network is finishing transfer */
    SMBus_NwkState_Ending,                
    /*! Network error detected */
    SMBus_NwkState_Error                  
} SMBus_NwkState;

/****************************************************************************** */

//
//! Definition of SMBus Network structure
//
//*****************************************************************************
typedef struct
{
    /*! Network state machine */
    volatile SMBus_NwkState eState;       
    /*! Current Address+R/W */
    uint8_t currentAddr;                  
    /*! Current Command */
    uint8_t currentCmd;                   
    /*! RX Byte counter */
    uint16_t rxIndex;
    /*! Bytes to receive */
    uint16_t rxLen;
    /*! Max size of buffer */
    uint16_t rxSize;
    /*! Reception Buffer pointer */
    uint8_t *rxBuffPtr;                   
    /*! Byte counter */
    uint16_t txIndex;
    /*! Bytes to send */
    uint16_t txLen;
    /*! Transmission pointer */
    uint8_t *txBuffPtr;                   
    /*! Receive Byte response */
    uint8_t *recByteTxPtr;                
    /*! Max size of buffer */
    uint16_t txSize;
    /*! PEC block length override */
    uint8_t pecBlockLenOverride;
    /*! Host Notify Buffer pointer */
    uint8_t *hostNotifyRxBuffPtr;
} SMBus_Nwk;

//*****************************************************************************
//
//! List of error codes used by the application to indicate an error to the library
//
//*****************************************************************************
typedef enum
{
    /*! No error detected */
    SMBus_ErrorCode_NoError = 0,   
    /*! Incorrect packet was received */
    SMBus_ErrorCode_Packet,        
    /*! Command is not supported */
    SMBus_ErrorCode_Cmd            
} SMBus_ErrorCode;

//*****************************************************************************
//
//! SMBus state sent to application layer
//
//*****************************************************************************
typedef enum
{
    /*! Nothing special to report */
    SMBus_State_OK = 0,                 
    /*! Incorrect packet size */
    SMBus_State_DataSizeError,          
    /*! PEC Error detected */
    SMBus_State_PECError,               
    /*! Timeout Error */
    SMBus_State_TimeOutError,           
    /*! 1st byte (cmd) received */
    SMBus_State_Target_FirstByte, 
    /*! Case where second byte is length in a block command */
    SMBus_State_Target_ByteReceived,     
    /*! Quick Command detected */
    SMBus_State_Target_QCMD,             
    /*! Complete packet received by target */
    SMBus_State_Target_CmdComplete,      
    /*! SMBus Target Error */
    SMBus_State_Target_Error,            
    /*! SMBus Buffers haven't been initialized */
    SMBus_State_Target_NotReady,         
    /*! No Interrupt flags detected */
    SMBus_State_Target_NTR,              
    /*! Arbitration Lost */
    SMBus_State_Controller_ArbLost,         
    /*! Unexpected NACKed */
    SMBus_State_Controller_NACK,            
    /*! SMBus Controller error */
    SMBus_State_Controller_Error,           
    /*! SMBus Controller Host Notify Received*/
    SMBus_State_Controller_HostNotify,
    /*! SMBus State Unknown */
    SMBus_State_Unknown
} SMBus_State;

/****************************************************************************** */

//
//! SMBus Status Register
//
//*****************************************************************************
typedef union
{
    //*****************************************************************************
    //
    //! Status flag register
    //
    //*****************************************************************************
    struct
    {
        /*! PEC error */
        uint8_t pecErr      : 1;    
        /*! Timeout error */
        uint8_t toErr       : 1;    
        /*! Error in packet format */
        uint8_t packErr     : 1;    
        /*! Packet Overrun error */
        uint8_t packOvrErr  : 1;    
        /*! Byte Overrun error */
        uint8_t byteOvrErr  : 1;    
        /*! Incorrect command */
        uint8_t cmdErr      : 1;    
        /*! Reserved bits */
        uint8_t reserved    : 2;    
    } bits;
    /*! Whole status byte access */
    uint8_t u8byte;
} SMBus_Status;

//*****************************************************************************
//
//! Main SMBus object
//
//*****************************************************************************
typedef struct
{
    /*! PHY and DataLink object */
    SMBus_Phy phy;                  
    /*! Network object */
    SMBus_Nwk nwk;                  
    /*! SMBus Control register */
    SMBus_Ctrl ctrl;                
    /*! SMBus Status register */
    SMBus_Status status;            
    /*! SMBus reported state */
    SMBus_State state;              
    /*! Own Target address */
    uint8_t ownTargetAddr;           
} SMBus;

//*****************************************************************************
// globals
//*****************************************************************************

//*****************************************************************************
// Public functions called by applications
//*****************************************************************************
//*****************************************************************************
//
//! \brief   Clears the current state of SMBus
//
//!  Must be called by application in order to clear the state machine
//!  when a byte/packet was processed
//
//! \param smbus     Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_processDone(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Returns the number of received bytes from last transaction
//
//! \param smbus     Pointer to SMBus structure
//
//! \return  Number of bytes in the RX buffer. PEC byte is *not* included.
//
//*****************************************************************************
extern uint16_t SMBus_getRxPayloadAvailable(SMBus *smbus);

//*****************************************************************************
//
//! \brief  Returns the state of the SMBus module
//
//! \param smbus    Pointer to SMBus structure
//
//! \return State of the SMBus module
//
//*****************************************************************************
extern SMBus_State SMBus_getState(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Enables PEC support
//
//! \param smbus    Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_enablePEC(SMBus *smbus);
//*****************************************************************************
//
//! \brief   Disables PEC support
//
//! \param smbus    Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_disablePEC(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Initialize the SMBus interface as a target
//
//! Initializes the NWK and PHY layers.
//
//!  \param smbus     Pointer to SMBus structure
//!  \param i2cAddr   Base address of I2C module.
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_targetInit(SMBus *smbus, I2C_Regs *i2cAddr);

//*****************************************************************************
//
//! \brief   Enables the I2C interrupts for a target
//
//! This function enables the I2C Start, Stop, RX, TX, Timeout interrupts
//
//! \param smbus     Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_targetEnableInt(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Disables the I2C interrupts for a target
//
//! This function disables the I2C Start, Stop, RX, TX, Timeout interrupts
//
//! \param smbus     Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_targetDisableInt(SMBus *smbus);

//*****************************************************************************
//
//! \brief   I2C Interrupt Service routine for a target
//
//! Handles the interrupts for SMBus passing information to NWK layer
//! Should be called by application when I2C interrupt is detected
//
//! \param smbus    Pointer to SMBus structure
//
//! \return  Processing State (SMBus_State)
//!       - \b SMBus_State_Target_NotReady - Packet is not ready
//!       - \b SMBus_State_Target_FirstByte - First byte received (application can use
//!                                    it to validate the command)
//!       - \b SMBus_State_Target_ByteReceived - Byte 2+ received (application can use
//!                                    it to validate each byte)
//!       - \b SMBus_State_Target_QCMD - Quick command received
//!       - \b SMBus_State_Target_CmdComplete - Packet complete and if PEC enabled,
//!                                    validated.
//
//*****************************************************************************
extern SMBus_State SMBus_targetProcessInt(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Force reset to SMBus controller interface
//
//! Resets the network and PHY layers
//
//! \param smbus    Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_controllerReset(SMBus *smbus);

//*****************************************************************************
//
//! \brief  Set the target's own I2C address
//
//! \param smbus     Pointer to SMBus structure
//! \param targetAddr  Target I2C address
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_targetSetAddress(SMBus *smbus,
                                  uint8_t targetAddr);

//*****************************************************************************
//
//! \brief   Initialize the reception buffer for target
//
//! \param smbus     Pointer to SMBus structure
//! \param data      Pointer to Application RX buffer
//! \param size       Maximum size of buffer
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_targetSetRxBuffer(SMBus *smbus,
                                   uint8_t *data,
                                   uint16_t size);

//*****************************************************************************
//
//! \brief   Initialize the transmission buffer for target
//
//! \param smbus    Pointer to SMBus structure
//! \param data     Pointer to Application TX buffer
//! \param size      Maximum size of buffer
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_targetSetTxBuffer(SMBus *smbus,
                                   uint8_t *data,
                                   uint16_t size);

//*****************************************************************************
//
//! \brief   Reports an error to SMBus driver from the target
//
//! Used to signal an error when incorrect command/data is detected by the target
//
//! \param smbus       Pointer to SMBus structure
//! \param errorCode    SMBus_ErrorCode
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_targetReportError(SMBus *smbus,
                                   SMBus_ErrorCode errorCode);

//*****************************************************************************
//
//! \brief   Return the current command (Rxbuffer[0]) received by the target
//
//! \param smbus       Pointer to SMBus structure
//
//! \return  Current command byte
//
//*****************************************************************************
extern uint8_t SMBus_targetGetCommand(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Report to hardware that the command type is a block command
//
//! \param smbus       Pointer to SMBus structure
//
//*****************************************************************************
extern void SMBus_targetReportBlock(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Report to hardware the fixed length of a given command
//
//! \param smbus       Pointer to SMBus structure
//! \param length	   Length of payload (without PEC byte), max supported is 0xFF
//
//*****************************************************************************
extern void SMBus_targetReportLength(SMBus *smbus, uint16_t length);

//*****************************************************************************
//
//! \brief   Clear the target's status register
//
//! \param smbus    Pointer to SMBus structure
//! \param val       Bits cleared from status register (1=X, 0=clear)
//
//! \return  Value of Status register after clearing flags
//
//*****************************************************************************
extern uint8_t SMBus_targetClearStatusReg(SMBus *smbus,
                                         uint8_t val);

//*****************************************************************************
//
//! \brief   Write a value to the target's control register
//
//! \param smbus    Pointer to SMBus structure
//! \param  val      Value being written to the Control register
//
//! \return  Value of Control register after write
//
//*****************************************************************************
extern uint8_t SMBus_targetWriteCtrlReg(SMBus *smbus,
                                       uint8_t val);

//*****************************************************************************
//
//! \brief   Send a Host Alert from the target
//
//!
//!~~~~~~~~
//! SMBus Host Alert protocol
//!
//! Modified Write Word:
//!      1         7         1    1         8        1       8           1          8         1   1
//!    ----------------------------------------------------------------------------------------------
//!    | S | Default Host Address | Wr | A | Device Address | A | Data Byte Low | A | Data Byte High | A | P |
//!    ----------------------------------------------------------------------------------------------
//!
//! where:
//!     S = Start bit
//!     Wr = Write bit (0)
//!     Default Host Address = 0x08
//!     Device Address = Own address to transmit
//!     Data Byte = data sent to target
//!     A = Acknowledge from target
//!     P = Stop bit
//!~~~~~~~~
//
//! \param smbus            Pointer to SMBus structure
//! \param deviceAddress    Own Address
//! \param txData           Pointer to TX data (2 bytes)
//
//! \return  \b SMBUS_RET_ERROR, or \b SMBUS_RET_OK
//
//*****************************************************************************
extern int8_t SMBus_targetHostAlert(SMBus *smbus,
                                 uint8_t deviceAddress,
                                 uint8_t *txData);

//*****************************************************************************
//
//! \brief   Initialize the SMBus Interface for a controller
//
//! Initializes the NWK and PHY layers
//
//! \param smbus     Pointer to SMBus structure
//! \param i2cAddr   Base address of I2C module.
//! \param busClk    SMCLK Frequency
//
// \return  None
//
//*****************************************************************************
extern void SMBus_controllerInit(SMBus *smbus,
                             I2C_Regs *i2cAddr,
                             uint32_t busClk);

//*****************************************************************************
//
//! \brief   Enables the I2C interrupts for a controller
//
//! This function enables the I2C Start, Stop, RX, TX, Timeout interrupts.
//! SMBus_controllerInit() must be called before this function.
//
//! \param smbus     Pointer to SMBus structure
//
//! \return  none
//
//*****************************************************************************
extern void SMBus_controllerEnableInt(SMBus *smbus);

//*****************************************************************************
//
//! \brief   Disables the I2C interrupts for a controller
//
//! This function disables the I2C Start, Stop, RX, TX, Timeout interrupts.
//
//! \param smbus     Pointer to SMBus structure
//
//! \return  none
//
//*****************************************************************************
extern void SMBus_controllerDisableInt(SMBus *smbus);


//*****************************************************************************
//
//! \brief   I2C Interrupt Service routine for a controller
//
//! Handles the interrupts for SMBus passing information to NWK layer
//! Should be called by application when I2C interrupt is detected
//
//! \param smbus    Pointer to SMBus structure
//
//! \return  Processing State (SMBus_State)
//
//*****************************************************************************
extern SMBus_State SMBus_controllerProcessInt(SMBus *smbus);


//*****************************************************************************
//
//! \brief   Sends a process call to a target
//
//! Send process call to the target. A command byte and 2 bytes of TX data are
//! required. Two bytes of data will be returned by the target in rxData.
//!
//!~~~~~~~~
//! SMBus Process Call command protocol
//!
//! Process Call:
//!      1         7         1    1         8        1       8           1          8         1  
//!    ------------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Data Byte Low | A | Data Byte High | A | ...
//!    ------------------------------------------------------------------------------------------
//!      1         7          1    1         8         1       8           1    1  
//!    ----------------------------------------------------------------------------
//!    | Sr | Target Address | Rd | A | Data Byte Low | A | Data Byte High | A | P |
//!    ----------------------------------------------------------------------------
//! Process Call with PEC:
//!      1         7         1    1         8        1       8           1          8         1  
//!    ------------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Data Byte Low | A | Data Byte High | A | ...
//!    ------------------------------------------------------------------------------------------
//!      1         7          1    1         8         1       8            1    8    1   1  
//!    --------------------------------------------------------------------------------------
//!    | Sr | Target Address | Rd | A | Data Byte Low | A | Data Byte High | A | PEC | A | P |
//!    --------------------------------------------------------------------------------------
//!
//! where: 
//!     S = Start bit
//!     Sr = Reapeated Start bit
//!     Wr = Write bit (0)
//!     Target Adddress = SMBus address for target
//!     Command Code = Command byte sent to target
//!     Data Byte = data sent to target
//!     A = Acknowledge from target
//!     PEC = Optional Packet Error Code
//!     P = Stop bit
//!~~~~~~~~
//
//! \param smbus     Pointer to SMBus structure
//! \param targetAddr Target address
//! \param command    Command byte for target
//! \param txData    TX data buffer
//! \param rxData    RX data buffer
//
//! \return  \b SMBUS_RET_ERROR, or \b SMBUS_RET_OK
//
//*****************************************************************************
extern int8_t SMBus_controllerProcessCall(SMBus *smbus,
                                      uint8_t targetAddr,
                                      uint8_t command,
                                      uint8_t *txData,
                                      uint8_t *rxData);

//*****************************************************************************
//
//! \brief   Sends a block write-block read process call
//
//! Send block write-block read process call to the target. A command byte,
//! length and tx data byte  array are required. Ensure that rxData is large
//! enough to hold the data received from the target.
//
//!
//!~~~~~~~~
//! SMBus Block write-block read process call protocol
//!
//! Block write-block read process call:
//!      1         7         1    1         8        1         8          1       8         1
//!    ----------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Byte Count = M | A | Data Byte 1 | A | ...
//!    ----------------------------------------------------------------------------------------
//!           8        1                8        1  
//!    -------------------       -------------------
//!    | Data Byte 2 | A |  ...  | Data Byte M | A | ...
//!    -------------------       -------------------
//!       1        7           1   1         8          1       8         1
//!    ----------------------------------------------------------------------
//!    | Sr | Target Address | Rd | A | Byte Count = N | A | Data Byte 1 | A | ...
//!    ----------------------------------------------------------------------
//!           8        1                8        1   1 
//!    -------------------       -----------------------
//!    | Data Byte 2 | A |  ...  | Data Byte N | A | P |
//!    -------------------       -----------------------
//! Block write-block read process call with PEC:
//!      1         7         1    1         8        1         8          1       8         1
//!    ----------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Byte Count = M | A | Data Byte 1 | A | ...
//!    ----------------------------------------------------------------------------------------
//!           8        1                8        1  
//!    -------------------       -------------------
//!    | Data Byte 2 | A |  ...  | Data Byte M | A | ...
//!    -------------------       -------------------
//!       1        7           1   1         8          1       8         1
//!    ----------------------------------------------------------------------
//!    | Sr | Target Address | Rd | A | Byte Count = N | A | Data Byte 1 | A | ...
//!    ----------------------------------------------------------------------
//!           8        1                8        1    8    1   1 
//!    -------------------       ---------------------------------
//!    | Data Byte 2 | A |  ...  | Data Byte N | A | PEC | A | P |
//!    -------------------       ---------------------------------
//!
//! where: 
//!     S = Start bit
//!     Sr = Reapeated Start bit
//!     Wr = Write bit (0)
//!     Rd = Read bit (1)
//!     Target Adddress = SMBus address for target
//!     Command Code = Command byte sent to target
//!     Data Byte = data sent to target
//!     A = Acknowledge from target
//!     PEC = Optional Packet Error Code
//!     P = Stop bit
//!~~~~~~~~
//
//! \param smbus     Pointer to SMBus structure
//! \param targetAddr Target address
//! \param command    Command byte for target
//! \param txData    TX data buffer
//! \param txSize    Size of the txData buffer
//! \param rxData    RX data buffer
//
//! \return  \b SMBUS_RET_ERROR, or \b SMBUS_RET_OK
//
//*****************************************************************************
extern int8_t SMBus_controllerProcessCallBlock(SMBus *smbus,
                                           uint8_t targetAddr,
                                           uint8_t command,
                                           uint8_t *txData,
                                           uint8_t txSize,
                                           uint8_t *rxData);

//*****************************************************************************
//
//! \brief   Sends byte to the target
//
//!
//!~~~~~~~~
//! SMBus Send Byte command protocol
//!
//!      1         7         1    1        8       1   1
//!    ---------------------------------------------------
//!    | S | Target Address | Wr | A |  Data Byte | A | P |
//!    ---------------------------------------------------
//! Send Byte with PEC:
//!      1         7         1    1       8       1    8    1   1
//!    ------------------------------------------------------------
//!    | S | Target Address | Wr | A | Data Byte | A | PEC | A | P | 
//!    ------------------------------------------------------------
//!
//! where: 
//!     S = Start bit
//!     Wr = Write bit (0)
//!     Target Adddress = SMBus address for target
//!     Data Byte = data sent to target
//!     A = Acknowledge from target
//!     PEC = Optional Packet Error Code
//!     P = Stop bit
//!~~~~~~~~
//
//! \param smbus     Pointer to SMBus structure
//! \param targetAddr Target address
//! \param txData    TX data buffer
//
//! \return  \b SMBUS_RET_ERROR, or \b SMBUS_RET_OK
//
//*****************************************************************************
extern int8_t SMBus_controllerSendByte(SMBus *smbus,
                                   uint8_t targetAddr,
                                   uint8_t txData);

//*****************************************************************************
//
//! \brief   Receive a byte from the target
//
//!~~~~~~~~
//! SMBus Receive Byte command protocol
//!
//!      1         7         1    1       8       1   1
//!    --------------------------------------------------
//!    | S | Target Address | Rd | A | Data Byte | A | P |
//!    --------------------------------------------------
//! With PEC:
//!      1         7         1    1       8       1    8    1   1
//!    ------------------------------------------------------------
//!    | S | Target Address | Rd | A | Data Byte | A | PEC | A | P |
//!    ------------------------------------------------------------
//!
//! where: 
//!     S = Start bit
//!     Rd = Read bit (1)
//!     Target Adddress = SMBus address for target
//!     Data Byte = data received from target
//!     A = Acknowledge from target
//!     PEC = Optional Packet Error Code
//!     P = Stop bit
//!~~~~~~~~
//
//! \param smbus     Pointer to SMBus structure
//! \param targetAddr Target address
//! \param rxData    RX data buffer
//
//! \return  \b SMBUS_RET_ERROR, or \b SMBUS_RET_OK
//
//*****************************************************************************
extern int8_t SMBus_controllerReceiveByte(SMBus *smbus,
                                      uint8_t targetAddr,
                                      uint8_t *rxData);

//*****************************************************************************
//
//! \brief   Receive a block of data from the target
//
//! Send block data receive call to the target. A command byte, length and rx
//! data byte array are required. Ensure that rxData is large enough to hold
//! the data received from the target.
//
//!
//!~~~~~~~~
//! SMBus Block Read command protocol
//!
//! Block Read:
//!      1         7         1    1         8        1   1         8          1    1  
//!    -------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Sr | Target Address | Rd | A | ...
//!    -------------------------------------------------------------------------------
//!              8        1        8        1        8        1                8        1   1
//!    ----------------------------------------------------------------------------------------
//!    | Byte Count = N | A | Data Byte 1 | A | Data Byte 2 | A |  ...  | Data Byte N | A | P |
//!    ----------------------------------------------------------------------------------------
//! Block Read with PEC:
//!      1         7         1    1         8        1   1         8          1    1  
//!    -------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Sr | Target Address | Rd | A | ...
//!    -------------------------------------------------------------------------------
//!              8        1        8        1        8        1                8        1  
//!    ------------------------------------------------------------------------------------
//!    | Byte Count = N | A | Data Byte 1 | A | Data Byte 2 | A |  ...  | Data Byte N | A |...
//!    ------------------------------------------------------------------------------------
//!       8    1   1
//!    ---------------
//!    | PEC | A | P |
//!    ---------------
//!
//! where: 
//!     S = Start bit
//!     Sr = Reapeated Start bit
//!     Wr = Write bit (0)
//!     Rd = Read bit (1)
//!     Target Adddress = SMBus address for target
//!     Command Code = Command byte sent to target
//!     Data Byte = data sent to target
//!     A = Acknowledge from target
//!     PEC = Optional Packet Error Code
//!     P = Stop bit
//!~~~~~~~~
//
//! \param smbus     Pointer to SMBus structure
//! \param targetAddr Target address
//! \param command    Command byte for target
//! \param rxData    RX data buffer
//
//! \return  \b SMBUS_RET_ERROR, or \b SMBUS_RET_OK
//
//*****************************************************************************
extern int8_t SMBus_controllerReadBlock(SMBus *smbus,
                                    uint8_t targetAddr,
                                    uint8_t command,
                                    uint8_t *rxData);

//*****************************************************************************
//
//! \brief   Transmit a block of data to the target
//
//! Send block of data to the target. A command byte, length and tx
//! data byte array are required.
//
//!
//!~~~~~~~~
//! SMBus Block Write command protocol
//!
//! Block Write:
//!      1         7         1    1         8        1         8          1          8      1  
//!    ----------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Byte Count = N | A | Data Byte 1 | A | ...
//!    ----------------------------------------------------------------------------------------
//!            8       1                 8       1   1
//!    --------------------      -----------------------
//!    | Data Byte 2 | A |  ...  | Data Byte N | A | P |
//!    --------------------      -----------------------
//! Block Write with PEC:
//!      1         7         1    1         8        1         8          1          8      1  
//!    ----------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Byte Count = N | A | Data Byte 1 | A | ...
//!    ----------------------------------------------------------------------------------------
//!            8       1                 8       1    8    1   1
//!    --------------------      ---------------------------------
//!    | Data Byte 2 | A |  ...  | Data Byte N | A | PEC | A | P |
//!    --------------------      ---------------------------------
//!
//! where: 
//!     S = Start bit
//!     Wr = Write bit (0)
//!     Target Adddress = SMBus address for target
//!     Command Code = Command byte sent to target
//!     Data Byte = data sent to target
//!     A = Acknowledge from target
//!     PEC = Optional Packet Error Code
//!     P = Stop bit
//!~~~~~~~~
//
//! \param smbus     Pointer to SMBus structure
//! \param targetAddr Target address
//! \param command    Command byte for target
//! \param txData    TX data buffer
//! \param txSize    Size of the txData buffer
//
//! \return  \b SMBUS_RET_ERROR, or \b SMBUS_RET_OK
//
//*****************************************************************************
extern int8_t SMBus_controllerWriteBlock(SMBus *smbus,
                                     uint8_t targetAddr,
                                     uint8_t command,
                                     uint8_t *txData,
                                     uint16_t txSize);

//*****************************************************************************
//
//! \brief   Send a command requesting a byte or word of data from the target
//
//
//!~~~~~~~~
//! SMBus Read ByteWord command protocol
//!
//! Read Byte:
//!      1         7         1    1         8        1       8           1    1       8       1   1
//!    ----------------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | S | Target Address | Rd | A | Data Byte | A | P |
//!    ----------------------------------------------------------------------------------------------
//! Read Byte with PEC:
//!      1         7         1    1         8        1       8           1    1       8       1   1
//!    ----------------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | S | Target Address | Rd | A | Data Byte | A | P | ...
//!    ----------------------------------------------------------------------------------------------
//!     8    1   1
//!    ---------------
//!    | PEC | A | P |
//!    ---------------
//!
//! Read Word:
//!      1         7         1    1         8        1       8           1    1       8           1   1
//!    --------------------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | S | Target Address | Rd | A | Data Byte Low | A | P | ...
//!    --------------------------------------------------------------------------------------------------
//!             8         1   1
//!    --------------------------
//!    | Data Byte High | A | P |
//!    --------------------------
//! Read Word with PEC:
//!      1         7         1    1         8        1       8           1    1       8           1   1
//!    --------------------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | S | Target Address | Rd | A | Data Byte Low | A | P | ...
//!    --------------------------------------------------------------------------------------------------
//!             8         1   1    8    1   1
//!    ----------------------------------------
//!    | Data Byte High | A | P | PEC | A | P |
//!    ----------------------------------------
//!
//! where: 
//!     S = Start bit
//!     Wr = Read bit (0)
//!     Rd = Read bit (1)
//!     Target Adddress = SMBus address for target
//!     Command Code = Command byte sent to target
//!     Data Byte = data sent to target
//!     A = Acknowledge from target
//!     PEC = Optional Packet Error Code
//!     P = Stop bit
//!~~~~~~~~
//
//! \param smbus     Pointer to SMBus structure
//! \param targetAddr Target address
//! \param command    Command byte for target
//! \param rxData    RX data buffer
//! \param rxSize    Must be 1 or 2 bytes
//
//! \return  \b SMBUS_RET_ERROR, or \b SMBUS_RET_OK
//
//*****************************************************************************
extern int8_t SMBus_controllerReadByteWord(SMBus *smbus,
                                       uint8_t targetAddr,
                                       uint8_t command,
                                       uint8_t *rxData,
                                       uint8_t rxSize);

//*****************************************************************************
//
//! \brief   Send a command transmitting a byte or word of data from the target
//!
//!~~~~~~~~
//! SMBus Write ByteWord command protocol
//!
//! Write Byte:
//!      1         7         1    1         8        1       8       1   1
//!    ---------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Data Byte | A | P |
//!    ---------------------------------------------------------------------
//! Write Byte with PEC:
//!      1         7         1    1         8        1       8       1    8    1   1
//!    -------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Data Byte | A | PEC | A | P |
//!    -------------------------------------------------------------------------------
//!
//! Write Word:
//!      1         7         1    1         8        1       8           1          8         1   1
//!    ----------------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Data Byte Low | A | Data Byte High | A | P |
//!    ----------------------------------------------------------------------------------------------
//! Write Word with PEC:
//!      1         7         1    1         8        1       8           1          8         1    8    1   1
//!    --------------------------------------------------------------------------------------------------------
//!    | S | Target Address | Wr | A | Command Code | A | Data Byte Low | A | Data Byte High | A | PEC | A | P |
//!    --------------------------------------------------------------------------------------------------------
//!
//! where: 
//!     S = Start bit
//!     Wr = Write bit (0)
//!     Target Adddress = SMBus address for target
//!     Command Code = Command byte sent to target
//!     Data Byte = data sent to target
//!     A = Acknowledge from target
//!     PEC = Optional Packet Error Code
//!     P = Stop bit
//!~~~~~~~~
//
//! \param smbus     Pointer to SMBus structure
//! \param targetAddr Target address
//! \param command    Command byte for target
//! \param txData    TX data buffer
//! \param txSize    Must be 1 or 2 bytes
//
//! \return  \b SMBUS_RET_ERROR, or \b SMBUS_RET_OK
//
//*****************************************************************************
extern int8_t SMBus_controllerWriteByteWord(SMBus *smbus,
                                        uint8_t targetAddr,
                                        uint8_t command,
                                        uint8_t *txData,
                                        uint8_t txSize);

//*****************************************************************************
//
//! \brief   Send a SMBus "quick command"
//
//! A "quick command" is only a trigger. There is no data sent or received.
//!
//!~~~~~~~~
//! SMBus Quick Commmand Protocol:
//!      1         7           1     1   1
//!    -------------------------------------
//!    | S | Target Address | Rd/Wr | A | P |
//!    -------------------------------------
//! where: 
//!     S = Start bit
//!     Rd/Wr = Read or Write bit
//!     Target Adddress = SMBus address for target
//!     A = Acknowledge from target
//!     P = Stop bit
//!~~~~~~~~
//
//! \param smbus     Pointer to SMBus structure
//! \param targetAddr Target address
//! \param write      true if this is a write command, false if this is a read command
//
//! \return  \b SMBUS_RET_ERROR, or \b SMBUS_RET_OK
//
//*****************************************************************************
extern int8_t SMBus_controllerQuickCommand(SMBus *smbus,
                                       uint8_t targetAddr,
                                       bool write);

//*****************************************************************************
//
//! \brief   Wait until the previous SMBus command is executed
//
//! \param smbus      Pointer to SMBus structure
//! \param timeout    Software timeout
//
//! \return  \b SMBUS_RET_ERROR, or \b SMBUS_RET_OK
//
//*****************************************************************************
extern int8_t SMBus_controllerWaitUntilDone(SMBus *smbus,
                                        int32_t timeout);

//*****************************************************************************
//
//! \brief   Enable support for Host Notify Protocol
//
//! Controller will respond to Default host address and recognize a host notify
//!   protocol.
//
//! \param smbus            Pointer to SMBus structure
//! \param hostAlertBuffer  Pointer to buffer to store host Alert response
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_controllerEnableHostNotify(SMBus *smbus, uint8_t *hostAlertBuffer);

//*****************************************************************************
//
//! \brief   Disable support for Host Notify Protocol
//
//! Controller will not respond to Default host address and won't recognize 
//! the host notify protocol.
//
//! \param smbus    Pointer to SMBus structure
//
//! \return  None
//
//*****************************************************************************
extern void SMBus_controllerDisableHostNotify(SMBus *smbus);

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

#endif //__SMBUS_H__
