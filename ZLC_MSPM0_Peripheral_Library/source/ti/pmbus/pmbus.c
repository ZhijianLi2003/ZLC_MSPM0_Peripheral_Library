/* --COPYRIGHT--,BSD
 * Copyright (c) 2015, Texas Instruments Incorporated
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
#include "ti/smbus/smbus.h"
#include "pmbus.h"

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#define PMB_RESERVED                                0x00

#define PMB_NO_READ                                 0x01
#define PMB_READ_BYTE                               0x02
#define PMB_READ_WORD                               0x03
#define PMB_BLOCK_READ                              0x40

#define PMB_NO_WRITE                                0x10
#define PMB_SEND_BYTE                               0x20
#define PMB_WRITE_BYTE                              0x30
#define PMB_WRITE_WORD                              0x40
#define PMB_BLOCK_WRITE                             0x50

uint8_t PMBus_Commands[] =
{
    // writeTransaction|readTransaction,       // Command name, opcode
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // PAGE,00h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // OPERATION,01h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // ON_OFF_CONFIG,02h
    PMB_SEND_BYTE | PMB_NO_READ,               // CLEAR_FAULTS,03h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // PHASE,04h
    PMB_BLOCK_WRITE | PMB_NO_READ,             // PAGE_PLUS_WRITE,05h
    PMB_RESERVED,                              // PAGE_PLUS_READ,06h
    PMB_RESERVED,                              // RESERVED,07h
    PMB_WRITE_WORD | PMB_READ_WORD,            // ZONE_ACTIVE,08h
    PMB_RESERVED,                              // RESERVED,09h
    PMB_RESERVED,                              // RESERVED,0Ah
    PMB_RESERVED,                              // RESERVED,0Bh
    PMB_RESERVED,                              // RESERVED,0Ch
    PMB_RESERVED,                              // RESERVED,0Dh
    PMB_RESERVED,                              // RESERVED,0Eh
    PMB_RESERVED,                              // RESERVED,0Fh
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // WRITE_PROTECT,10h
    PMB_SEND_BYTE | PMB_NO_READ,               // STORE_DEFAULT_ALL,11h
    PMB_SEND_BYTE | PMB_NO_READ,               // RESTORE_DEFAULT_ALL,12h
    PMB_WRITE_BYTE | PMB_NO_READ,              // STORE_DEFAULT_CODE,13h
    PMB_WRITE_BYTE | PMB_NO_READ,              // RESTORE_DEFAULT_CODE,14h
    PMB_SEND_BYTE | PMB_NO_READ,               // STORE_USER_ALL,15h
    PMB_SEND_BYTE | PMB_NO_READ,               // RESTORE_USER_ALL,16h
    PMB_WRITE_BYTE | PMB_NO_READ,              // STORE_USER_CODE,17h
    PMB_WRITE_BYTE | PMB_NO_READ,              // RESTORE_USER_CODE,18h
    PMB_NO_WRITE | PMB_READ_BYTE,              // CAPABILITY,19h
    PMB_RESERVED,                              // QUERY,1Ah
    PMB_RESERVED,                              // SMBALERT_MASK,1Bh
    PMB_RESERVED,                              // RESERVED,1Ch
    PMB_RESERVED,                              // RESERVED,1Dh
    PMB_RESERVED,                              // RESERVED,1Eh
    PMB_RESERVED,                              // RESERVED,1Fh
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // VOUT_MODE,20h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_COMMAND,21h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_TRIM,22h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_CAL_OFFSET,23h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_MAX,24h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_MARGIN_HIGH,25h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_MARGIN_LOW,26h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_TRANSITION_RATE,27h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_DROOP,28h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_SCALE_LOOP,29h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_SCALE_MONITOR,2Ah
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_MIN,2Bh
    PMB_RESERVED,                              // RESERVED,2Ch
    PMB_RESERVED,                              // RESERVED,2Dh
    PMB_RESERVED,                              // RESERVED,2Eh
    PMB_RESERVED,                              // RESERVED,2Fh
    PMB_RESERVED,                              // COEFFICIENTS,30h
    PMB_WRITE_WORD | PMB_READ_WORD,            // POUT_MAX,31h
    PMB_WRITE_WORD | PMB_READ_WORD,            // MAX_DUTY,32h
    PMB_WRITE_WORD | PMB_READ_WORD,            // FREQUENCY_SWITCH,33h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // POWER_MODE,34h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VIN_ON,35h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VIN_OFF,36h
    PMB_WRITE_WORD | PMB_READ_WORD,            // INTERLEAVE,37h
    PMB_WRITE_WORD | PMB_READ_WORD,            // IOUT_CAL_GAIN,38h
    PMB_WRITE_WORD | PMB_READ_WORD,            // IOUT_CAL_OFFSET,39h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // FAN_CONFIG_1_2,3Ah
    PMB_WRITE_WORD | PMB_READ_WORD,            // FAN_COMMAND_1,3Bh
    PMB_WRITE_WORD | PMB_READ_WORD,            // FAN_COMMAND_2,3Ch
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // FAN_CONFIG_3_4,3Dh
    PMB_WRITE_WORD | PMB_READ_WORD,            // FAN_COMMAND_3,3Eh
    PMB_WRITE_WORD | PMB_READ_WORD,            // FAN_COMMAND_4,3Fh
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_OV_FAULT_LIMIT,40h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // VOUT_OV_FAULT_RESPONSE,41h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_OV_WARN_LIMIT,42h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_UV_WARN_LIMIT,43h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VOUT_UV_FAULT_LIMIT,44h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // VOUT_UV_FAULT_RESPONSE,45h
    PMB_WRITE_WORD | PMB_READ_WORD,            // IOUT_OC_FAULT_LIMIT,46h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // IOUT_OC_FAULT_RESPONSE,47h
    PMB_WRITE_WORD | PMB_READ_WORD,            // IOUT_OC_LV_FAULT_LIMIT,48h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // IOUT_OC_LV_FAULT_RESPONSE,49h
    PMB_WRITE_WORD | PMB_READ_WORD,            // IOUT_OC_WARN_LIMIT,4Ah
    PMB_WRITE_WORD | PMB_READ_WORD,            // IOUT_UC_FAULT_LIMIT,4Bh
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // IOUT_UC_FAULT_RESPONSE,4Ch
    PMB_RESERVED,                              // RESERVED,4Dh
    PMB_RESERVED,                              // RESERVED,4Eh
    PMB_WRITE_WORD | PMB_READ_WORD,            // OT_FAULT_LIMIT,4Fh
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // OT_FAULT_RESPONSE,50h
    PMB_WRITE_WORD | PMB_READ_WORD,            // OT_WARN_LIMIT,51h
    PMB_WRITE_WORD | PMB_READ_WORD,            // UT_WARN_LIMIT,52h
    PMB_WRITE_WORD | PMB_READ_WORD,            // UT_FAULT_LIMIT,53h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // UT_FAULT_RESPONSE,54h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VIN_OV_FAULT_LIMIT,55h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // VIN_OV_FAULT_RESPONSE,56h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VIN_OV_WARN_LIMIT,57h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VIN_UV_WARN_LIMIT,58h
    PMB_WRITE_WORD | PMB_READ_WORD,            // VIN_UV_FAULT_LIMIT,59h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // VIN_UV_FAULT_RESPONSE,5Ah
    PMB_WRITE_WORD | PMB_READ_WORD,            // IIN_OC_FAULT_LIMIT,5Bh
    PMB_WRITE_WORD | PMB_READ_WORD,            // IIN_OC_FAULT_RESPONSE,5Ch
    PMB_WRITE_WORD | PMB_READ_WORD,            // IIN_OC_WARN_LIMIT,5Dh
    PMB_WRITE_WORD | PMB_READ_WORD,            // POWER_GOOD_ON,5Eh
    PMB_WRITE_WORD | PMB_READ_WORD,            // POWER_GOOD_OFF,5Fh
    PMB_WRITE_WORD | PMB_READ_WORD,            // TON_DELAY,60h
    PMB_WRITE_WORD | PMB_READ_WORD,            // TON_RISE,61h
    PMB_WRITE_WORD | PMB_READ_WORD,            // TON_MAX_FAULT_LIMIT,62h
    PMB_WRITE_WORD | PMB_READ_WORD,            // TON_MAX_FAULT_RESPONSE,63h
    PMB_WRITE_WORD | PMB_READ_WORD,            // TOFF_DELAY,64h
    PMB_WRITE_WORD | PMB_READ_WORD,            // TOFF_FALL,65h
    PMB_WRITE_WORD | PMB_READ_WORD,            // TOFF_MAX_WARN_LIMIT,66h
    PMB_RESERVED,                              // RESERVED,67h
    PMB_WRITE_WORD | PMB_READ_WORD,            // POUT_OP_FAULT_LIMIT,68h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // POUT_OP_FAULT_RESPONSE,69h
    PMB_WRITE_WORD | PMB_READ_WORD,            // POUT_OP_WARN_LIMIT,6Ah
    PMB_WRITE_WORD | PMB_READ_WORD,            // PIN_OP_WARN_LIMIT,6Bh
    PMB_RESERVED,                              // RESERVED,6Ch
    PMB_RESERVED,                              // RESERVED,6Dh
    PMB_RESERVED,                              // RESERVED,6Eh
    PMB_RESERVED,                              // RESERVED,6Fh
    PMB_RESERVED,                              // RESERVED,70h
    PMB_RESERVED,                              // RESERVED,71h
    PMB_RESERVED,                              // RESERVED,72h
    PMB_RESERVED,                              // RESERVED,73h
    PMB_RESERVED,                              // RESERVED,74h
    PMB_RESERVED,                              // RESERVED,75h
    PMB_RESERVED,                              // RESERVED,76h
    PMB_RESERVED,                              // RESERVED,77h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // STATUS_BYTE,78h
    PMB_WRITE_WORD | PMB_READ_WORD,            // STATUS_WORD,79h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // STATUS_VOUT,7Ah
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // STATUS_IOUT,7Bh
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // STATUS_INPUT,7Ch
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // STATUS_TEMPERATURE,7Dh
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // STATUS_CML,7Eh
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // STATUS_OTHER,7Fh
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // STATUS_MFR_SPECIFIC,80h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // STATUS_FANS_1_2,81h
    PMB_WRITE_BYTE | PMB_READ_BYTE,            // STATUS_FANS_3_4,82h
    PMB_RESERVED,                              // RESERVED,83h
    PMB_RESERVED,                              // RESERVED,84h
    PMB_WRITE_WORD | PMB_READ_WORD,            // READ_KWH_CONFIG,85h
    PMB_NO_WRITE | PMB_BLOCK_READ,             // READ_EIN,86h
    PMB_NO_WRITE | PMB_BLOCK_READ,             // READ_EOUT,87h
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_VIN,88h
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_IIN,89h
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_VCAP,8Ah
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_VOUT,8Bh
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_IOUT,8Ch
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_TEMPERATURE_1,8Dh
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_TEMPERATURE_2,8Eh
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_TEMPERATURE_3,8Fh
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_FAN_SPEED_1,90h
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_FAN_SPEED_2,91h
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_FAN_SPEED_3,92h
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_FAN_SPEED_4,93h
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_DUTY_CYCLE,94h
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_FREQUENCY,95h
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_POUT,96h
    PMB_NO_WRITE | PMB_READ_WORD,              // READ_PIN,97h
    PMB_NO_WRITE | PMB_READ_BYTE,              // PMBUS_REVISION,98h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // MFR_ID,99h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // MFR_MODEL,9Ah
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // MFR_REVISION,9Bh
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // MFR_LOCATION,9Ch
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // MFR_DATE,9Dh
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // MFR_SERIAL,9Eh
    PMB_NO_WRITE | PMB_BLOCK_READ,             // APP_PROFILE_SUPPORT,9Fh
    PMB_NO_WRITE | PMB_READ_WORD,              // MFR_VIN_MIN,A0h
    PMB_NO_WRITE | PMB_READ_WORD,              // MFR_VIN_MAX,A1h
    PMB_NO_WRITE | PMB_READ_WORD,              // MFR_IIN_MAX,A2h
    PMB_NO_WRITE | PMB_READ_WORD,              // MFR_PIN_MAX,A3h
    PMB_NO_WRITE | PMB_READ_WORD,              // MFR_VOUT_MIN,A4h
    PMB_NO_WRITE | PMB_READ_WORD,              // MFR_VOUT_MAX,A5h
    PMB_NO_WRITE | PMB_READ_WORD,              // MFR_IOUT_MAX,A6h
    PMB_NO_WRITE | PMB_READ_WORD,              // MFR_POUT_MAX,A7h
    PMB_NO_WRITE | PMB_READ_WORD,              // MFR_TAMBIENT_MAX,A8h
    PMB_NO_WRITE | PMB_READ_WORD,              // MFR_TAMBIENT_MIN,A9h
    PMB_NO_WRITE | PMB_BLOCK_READ,             // MFR_EFFICIENCY_LL,AAh
    PMB_NO_WRITE | PMB_BLOCK_READ,             // MFR_EFFICIENCY_HL,ABh
    PMB_NO_WRITE | PMB_READ_BYTE,              // MFR_PIN_ACCURACY,ACh
    PMB_NO_WRITE | PMB_BLOCK_READ,             // IC_DEVICE_ID,ADh
    PMB_NO_WRITE | PMB_BLOCK_READ,             // IC_DEVICE_REV,AEh
    PMB_RESERVED,                              // RESERVED,Afh
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_00,B0h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_01,B1h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_02,B2h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_03,B3h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_04,B4h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_05,B5h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_06,B6h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_07,B7h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_08,B8h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_09,B9h
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_10,BAh
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_11,BBh
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_12,BCh
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_13,BDh
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_14,BEh
    PMB_BLOCK_WRITE | PMB_BLOCK_READ,          // USER_DATA_15,BFh
    PMB_WRITE_WORD | PMB_READ_WORD,            // MFR_MAX_TEMP_1,C0h
    PMB_WRITE_WORD | PMB_READ_WORD,            // MFR_MAX_TEMP_2,C1h
    PMB_WRITE_WORD | PMB_READ_WORD,            // MFR_MAX_TEMP_3,C2h
};

/*! SMBus Controller Struct  */
static SMBus SMB;

void PMBus_init(I2C_Regs* i2cAddr,
                uint32_t busClk)
{
    // Initialize SMBus Controller
    SMBus_controllerInit(&SMB,i2cAddr, busClk);
    // Enable SMBus Interrupts, after initializing I2C
    SMBus_controllerEnableInt(&SMB);
}

void PMBus_processInt()
{
    // Process SMBus ISR as Controller, store result flags
    // Note that the Controller starts transfers in Main loop and this function
    // handles the SMBus State machine. The main loop just waits for completion
    SMBus_State sSMBState = SMBus_controllerProcessInt(&SMB);
}


void PMBus_enablePEC()
{
    SMBus_enablePEC(&SMB);
}

void PMBus_disablePEC()
{
    SMBus_disablePEC(&SMB);
}

int8_t PMBus_cmdRead(uint8_t targetAddress,
                     uint8_t commandId,
                     uint8_t* rxData,
                     uint8_t* rxSize,
                     uint32_t timeout)
{
    // Make sure commandId is in range
    if(commandId >= sizeof(PMBus_Commands) / sizeof(PMBus_Commands[0]))
    {
        return(PMBUS_RET_ERROR);
    }
    int8_t ret = PMBUS_RET_ERROR;
    uint8_t transaction = (PMBus_Commands[commandId] & 0x0F);
    switch(transaction)
    {
    case PMB_NO_READ:
        ret = PMBUS_RET_OK;
        break;
    case PMB_READ_BYTE:
        ret = PMBus_cmdReadByte(targetAddress,
                                commandId,
                                rxData,
                                timeout);
        *rxSize = 1;
        break;
    case PMB_READ_WORD:
        ret = PMBus_cmdReadWord(targetAddress,
                                commandId,
                                rxData,
                                timeout);
        *rxSize = 2;
        break;
    case PMB_BLOCK_READ:
        ret = PMBus_cmdBlockRead(targetAddress,
                                 commandId,
                                 rxData,
                                 rxSize,
                                 timeout);
        break;
    case PMB_RESERVED:
    default:
        ret = PMBUS_RET_ERROR;
    }
    return(ret);
}

int8_t PMBus_cmdWrite(uint8_t targetAddress,
                      uint8_t commandId,
                      uint8_t* txData,
                      uint8_t txSize,
                      uint32_t timeout)
{
    // Make sure commandId is in range
    if(commandId >= sizeof(PMBus_Commands) / sizeof(PMBus_Commands[0]))
    {
        return(PMBUS_RET_ERROR);
    }
    uint8_t transaction = (PMBus_Commands[commandId] & 0xF0);

    int8_t ret = PMBUS_RET_ERROR;
    switch(transaction)
    {
    case PMB_NO_WRITE:
        ret = PMBUS_RET_OK;
        break;
    case PMB_SEND_BYTE:
        if(txSize != 0)
        {
            return (PMBUS_RET_ERROR);
        }
        ret = PMBus_cmdSendByte(targetAddress,
                                commandId,
                                timeout);
        break;
    case PMB_WRITE_BYTE:
        if(txSize != 1)
        {
            return (PMBUS_RET_ERROR);
        }
        ret = PMBus_cmdWriteByte(targetAddress,
                                 commandId,
                                 txData,
                                 timeout);
        break;
    case PMB_WRITE_WORD:
        if(txSize != 2)
        {
            return (PMBUS_RET_ERROR);
        }
        ret = PMBus_cmdWriteWord(targetAddress,
                                 commandId,
                                 txData,
                                 timeout);
        break;
    case PMB_BLOCK_WRITE:
        ret = PMBus_cmdBlockWrite(targetAddress,
                                  commandId,
                                  txData,
                                  txSize,
                                  timeout);
        break;
    case PMB_RESERVED:
    default:
        ret = PMBUS_RET_ERROR;
    }
    return(ret);
}

int8_t PMBus_cmdSendByte(uint8_t targetAddress,
                         uint8_t commandByte,
                         uint32_t timeout)
{
    if(SMBus_controllerSendByte(&SMB,                          // SMB struct
                            targetAddress,                  // Target Addr
                            commandByte) != PMBUS_RET_OK)  // PMB Command
    {
        return(PMBUS_RET_ERROR);
    }

    if((SMBus_controllerWaitUntilDone(&SMB,timeout) != PMBUS_RET_OK) ||
       (SMBus_getState(&SMB) != SMBus_State_OK))
    {
        SMBus_controllerReset(&SMB); // Force a reset, so we can retry later
        return(PMBUS_RET_ERROR);
    }

    return(PMBUS_RET_OK);
}

int8_t PMBus_cmdWriteByte(uint8_t targetAddress,
                          uint8_t commandByte,
                          uint8_t* txData,
                          uint32_t timeout)
{
    if(SMBus_controllerWriteByteWord(&SMB,               // SMB struct
                                 targetAddress,       // Target Addr
                                 commandByte,        // PMB Command
                                 txData,             // DataPtr
                                 1) != PMBUS_RET_OK) // 1 byte data
    {
        return(PMBUS_RET_ERROR);
    }

    if((SMBus_controllerWaitUntilDone(&SMB,timeout) != PMBUS_RET_OK) ||
       (SMBus_getState(&SMB) != SMBus_State_OK))
    {
        SMBus_controllerReset(&SMB); // Force a reset, so we can retry later
        return(PMBUS_RET_ERROR);
    }

    return(PMBUS_RET_OK);
}

int8_t PMBus_cmdWriteWord(uint8_t targetAddress,
                          uint8_t commandByte,
                          uint8_t* txData,
                          uint32_t timeout)
{
    if(SMBus_controllerWriteByteWord(&SMB,                  // SMB struct
                                 targetAddress,          // Target Addr
                                 commandByte,           // PMB Command
                                 txData,                // DataPtr
                                 2) != PMBUS_RET_OK)    // 2 bytes data
    {
        return(PMBUS_RET_ERROR);
    }

    if((SMBus_controllerWaitUntilDone(&SMB,timeout) != PMBUS_RET_OK) ||
       (SMBus_getState(&SMB) != SMBus_State_OK))
    {
        SMBus_controllerReset(&SMB); // Force a reset, so we can retry later
        return(PMBUS_RET_ERROR);
    }

    return(PMBUS_RET_OK);
}

int8_t PMBus_cmdBlockWrite(uint8_t targetAddress,
                           uint8_t commandByte,
                           uint8_t* txData,
                           uint8_t txSize,
                           uint32_t timeout)
{
    if(SMBus_controllerWriteBlock(&SMB,                       // SMB struct
                              targetAddress,               // Target Addr
                              commandByte,                // PMB Command
                              txData,                     // Data ptr
                              txSize) != PMBUS_RET_OK)    // number of bytes
    {
        return(PMBUS_RET_ERROR);
    }

    if((SMBus_controllerWaitUntilDone(&SMB,timeout) != PMBUS_RET_OK) ||
       (SMBus_getState(&SMB) != SMBus_State_OK))
    {
        SMBus_controllerReset(&SMB); // Force a reset, so we can retry later
        return(PMBUS_RET_ERROR);
    }

    return(PMBUS_RET_OK);
}

int8_t PMBus_cmdReceiveByte(uint8_t targetAddress,
                            uint8_t* rxData,
                            uint32_t timeout)
{
    if(SMBus_controllerReceiveByte(&SMB,                      // SMB struct
                               targetAddress,              // Target Addr
                               rxData) != PMBUS_RET_OK)   // DataPtr
    {
        return(PMBUS_RET_ERROR);
    }

    if((SMBus_controllerWaitUntilDone(&SMB,timeout) != PMBUS_RET_OK) ||
       (SMBus_getState(&SMB) != SMBus_State_OK))
    {
        SMBus_controllerReset(&SMB); // Force a reset, so we can retry later
        return(PMBUS_RET_ERROR);
    }

    // Get the length of payload for response
    if(SMBus_getRxPayloadAvailable(&SMB) != 1)
    {
        return(PMBUS_RET_ERROR);  // RX Data size Error
    }

    return(PMBUS_RET_OK);
}

int8_t PMBus_cmdReadByte(uint8_t targetAddress,
                         uint8_t commandByte,
                         uint8_t* rxData,
                         uint32_t timeout)
{
    if(SMBus_controllerReadByteWord(&SMB,                      // SMB struct
                                targetAddress,              // Target Addr
                                commandByte,               // PMB Command
                                rxData,                    // DataPtr
                                1) != PMBUS_RET_OK)        // 1 byte data
    {
        return(PMBUS_RET_ERROR);
    }

    if((SMBus_controllerWaitUntilDone(&SMB,timeout) != PMBUS_RET_OK) ||
       (SMBus_getState(&SMB) != SMBus_State_OK))
    {
        SMBus_controllerReset(&SMB); // Force a reset, so we can retry later
        return(PMBUS_RET_ERROR);
    }

    // Get the length of payload for response
    if(SMBus_getRxPayloadAvailable(&SMB) != 1)
    {
        return(PMBUS_RET_ERROR);  // RX Data size Error
    }

    return(PMBUS_RET_OK);
}

int8_t PMBus_cmdReadWord(uint8_t targetAddress,
                         uint8_t commandByte,
                         uint8_t* rxData,
                         uint32_t timeout)
{
    if(SMBus_controllerReadByteWord(&SMB,                      // SMB struct
                                targetAddress,              // Target Addr
                                commandByte,               // PMB Command
                                rxData,                    // DataPtr
                                2) != PMBUS_RET_OK)        // 2 byte data
    {
        return(PMBUS_RET_ERROR);
    }

    if((SMBus_controllerWaitUntilDone(&SMB,timeout) != PMBUS_RET_OK) ||
       (SMBus_getState(&SMB) != SMBus_State_OK))
    {
        SMBus_controllerReset(&SMB); // Force a reset, so we can retry later
        return(PMBUS_RET_ERROR);
    }

    // Get the length of payload for response
    if(SMBus_getRxPayloadAvailable(&SMB) != 2)
    {
        return(PMBUS_RET_ERROR); // RX Data size Error
    }

    return(PMBUS_RET_OK);
}

int8_t PMBus_cmdBlockRead(uint8_t targetAddress,
                          uint8_t commandByte,
                          uint8_t* rxData,
                          uint8_t* rxSize,
                          uint32_t timeout)
{
    if(SMBus_controllerReadBlock(&SMB,                            // SMB struct
                             targetAddress,                    // Target Addr
                             commandByte,                     // PMB Command
                             rxData) != PMBUS_RET_OK)         // DataPtr
    {
        return(PMBUS_RET_ERROR);
    }

    if((SMBus_controllerWaitUntilDone(&SMB,timeout) != PMBUS_RET_OK) ||
       (SMBus_getState(&SMB) != SMBus_State_OK))
    {
        SMBus_controllerReset(&SMB); // Force a reset, so we can retry later
        return(PMBUS_RET_ERROR);
    }

    // Return the number of bytes received
    *rxSize = SMBus_getRxPayloadAvailable(&SMB);

    return(PMBUS_RET_OK);
}

int8_t PMBus_cmdProcessCall(uint8_t targetAddress,
                            uint8_t commandByte,
                            uint8_t* txData,
                            uint8_t* rxData,
                            uint32_t timeout)
{
    if(SMBus_controllerProcessCall(&SMB,                      // SMB struct
                               targetAddress,              // Target Addr
                               commandByte,               // PMB Command
                               txData,                    // Tx data
                               rxData) != PMBUS_RET_OK)   // DataPtr
    {
        return(PMBUS_RET_ERROR);
    }

    if((SMBus_controllerWaitUntilDone(&SMB,timeout) != PMBUS_RET_OK) ||
       (SMBus_getState(&SMB) != SMBus_State_OK))
    {
        SMBus_controllerReset(&SMB); // Force a reset, so we can retry later
        return(PMBUS_RET_ERROR);
    }

    // Get the length of payload for response
    if(SMBus_getRxPayloadAvailable(&SMB) != 2)
    {
        return(PMBUS_RET_ERROR); // RX Data size Error
    }

    return(PMBUS_RET_OK);
}

int8_t PMBus_cmdBlockWriteBlockReadProcessCall(uint8_t targetAddress,
                                               uint8_t commandByte,
                                               uint8_t* txData,
                                               uint8_t txSize,
                                               uint8_t* rxData,
                                               uint8_t* rxSize,
                                               uint32_t timeout)
{
    if(SMBus_controllerProcessCallBlock(&SMB,                         // SMB struct
                                    targetAddress,                 // Target Addr
                                    commandByte,                  // PMB Command
                                    txData,                       // Tx data
                                    txSize,                       // Tx data size
                                    rxData) != PMBUS_RET_OK)      // DataPtr
    {
        return(PMBUS_RET_ERROR);
    }

    if((SMBus_controllerWaitUntilDone(&SMB,timeout) != PMBUS_RET_OK) ||
       (SMBus_getState(&SMB) != SMBus_State_OK))
    {
        SMBus_controllerReset(&SMB); // Force a reset, so we can retry later
        return(PMBUS_RET_ERROR);
    }

    // Return the number of bytes received
    *rxSize = SMBus_getRxPayloadAvailable(&SMB);

    return(PMBUS_RET_OK);
}

int8_t PMBus_ReceiveByteARA(uint8_t *rxData,
                            uint32_t timeout)
{
    return(PMBus_cmdReceiveByte(PMBUS_ARA, rxData, timeout));
}
