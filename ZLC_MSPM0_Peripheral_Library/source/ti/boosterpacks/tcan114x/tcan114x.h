/*
 * Copyright (c) 2022, Texas Instruments Incorporated
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
/*
 * tcan114x.h
 *
 *  Created on: December 4, 2018
 *      Author: a0225039
 *  Updated on: October 20, 2022
 *      Author: a0272979
 *
 *      @brief The main file for the includes needed for the TCAN114x family of devices
 */

#ifndef TESTER_SUITE_CAN_TCAN114X_H_
#define TESTER_SUITE_CAN_TCAN114X_H_

// Uncomment the below define to have all device configuration writes be re-read for a verification
#define TCAN114X_CONFIGURE_VERIFY_WRITES
#define TCAN114X_INTERRUPTS_VERIFY_WRITES

#include "tcan114x_data_structs.h"
#include "tcan114x_reg.h"
#include "tcan114x_spi.h"

typedef enum {
    TCAN114X_SUCCESS = 0U,
    TCAN114X_FAIL    = 1U
} TCAN114X_STATUS_ENUM;

#define TCAN114X_PN_DLC_0B 0
#define TCAN114X_PN_DLC_1B 1
#define TCAN114X_PN_DLC_2B 2
#define TCAN114X_PN_DLC_3B 3
#define TCAN114X_PN_DLC_4B 4
#define TCAN114X_PN_DLC_5B 5
#define TCAN114X_PN_DLC_6B 6
#define TCAN114X_PN_DLC_7B 7
#define TCAN114X_PN_DLC_8B 8

#define TCAN114X_PN_CAN_50KBPS 0
#define TCAN114X_PN_CAN_100KBPS 1
#define TCAN114X_PN_CAN_125KBPS 2
#define TCAN114X_PN_CAN_250KBPS 3
#define TCAN114X_PN_CAN_500KBPS 5
#define TCAN114X_PN_CAN_1MBPS 7

#define TCAN114X_PN_CANFD_LESSTHAN4XCANRATE 0
#define TCAN114X_PN_CANFD_GT5x_LT10x 1
#define TCAN114X_PN_CANFD_8MBPS_WITH500KCAN 2

typedef struct TCAN114x_Dev_ID {
    //! DEVID ID address 0
    uint8_t addr0;
    //! DEVID ID address 1
    uint8_t addr1;
    //! DEVID ID address 2
    uint8_t addr2;
    //! DEVID ID address 3
    uint8_t addr3;
    //! DEVID ID address 4
    uint8_t addr4;
    //! DEVID ID address 5
    uint8_t addr5;
    //! DEVID ID address 6
    uint8_t addr6;
    //! DEVID ID address 7
    uint8_t addr7;
} TCAN114x_Dev_ID;

typedef struct TCAN114x_PN_Config {
    //! ID: The ID to look for for selective wake. Right justified whether 11 or 29 bits. If using extended ID, make sure to set IDE to 1.
    uint32_t ID : 29;

    //! IDE: ID Extended used. Set to 1 if using an extended ID in the ID field
    //! \n Valid values are: 0, 1
    uint8_t IDE : 1;

    //! IDMask: The value to be used for masking the ID. All 0's means all bits must match exactly. A 1 means that bit is ignored in the ID field
    uint32_t IDMask : 29;

    //! DLC: A DLC field value to match.
    //! \n Valid values are: 0 to 15
    uint8_t DLC : 4;

    //! Data Mask Enable: Set to 1 if using a data field mask. Turning this on requires the DLC to match, and the data fields are masks. A 1 means match this bit in the data fields. A single match across all the data fields will be a valid WUF
    //! \n Valid values are 0, 1
    uint8_t DataMaskEN : 1;

    //! CAN Data to match
    uint8_t DATA[8];

    //! Selective wake FD passive: Set to 1 to ignore frames with FD enabled. A 0 [default] results in error counter increment
    //! \n Valid values are 0 [default], 1
    uint8_t SWFDPassive : 1;

    //! CAN Data Rate
    uint8_t CAN_DR : 3;

    //! CAN FD Data Rate vs the selected CAN Data Rate
    uint8_t FD_DR : 2;

    //! Frame counter threshold: Sets at what value the error counter must reach to set a frame overflow flag (+1). Default is 31
    uint8_t FrameErrorThreshold : 8;

} TCAN114x_PN_Config;

typedef enum {
    TCAN114X_MODE_SLEEP,
    TCAN114X_MODE_STANDBY,
    TCAN114X_MODE_LISTEN,
    TCAN114X_MODE_NORMAL
} TCAN114X_MODE_ENUM;

/* ************************************ *
 *           Device Functions           *
 * ************************************ */
TCAN114X_MODE_ENUM TCAN114x_Mode_Read(void);
TCAN114X_STATUS_ENUM TCAN114x_Mode_Set(TCAN114X_MODE_ENUM modeRequest);

/* ************************************* *
 *             Helper Functions          *
 * ************************************* */
TCAN114X_STATUS_ENUM TCAN114x_Mode_Control_Read(
    TCAN114x_Mode_Control *ModeControl);
TCAN114X_STATUS_ENUM TCAN114x_Mode_Control_Write(
    TCAN114x_Mode_Control *ModeControl);
TCAN114X_STATUS_ENUM TCAN114x_Wake_Pin_Config_Read(
    TCAN114x_Wake_Pin_Config *WakePin);
TCAN114X_STATUS_ENUM TCAN114x_Wake_Pin_Config_Write(
    TCAN114x_Wake_Pin_Config *WakePin);
TCAN114X_STATUS_ENUM TCAN114x_Device_Pin_Config_Read(
    TCAN114x_Pin_Config *PinConfig);
TCAN114X_STATUS_ENUM TCAN114x_Device_Pin_Config_Write(
    TCAN114x_Pin_Config *PinConfig);
TCAN114X_STATUS_ENUM TCAN114x_PN_Config_Read(TCAN114x_PN_Config *pnConfig);
TCAN114X_STATUS_ENUM TCAN114x_PN_Config_Write(TCAN114x_PN_Config *pnConfig);

TCAN114X_STATUS_ENUM TCAN114x_Device_Interrupts_Read(TCAN114x_Interrupts *ir);
TCAN114X_STATUS_ENUM TCAN114x_Device_Interrupts_Clear(TCAN114x_Interrupts *ir);
TCAN114X_STATUS_ENUM TCAN114x_Device_Interrupts_ClearAll(void);
TCAN114X_STATUS_ENUM TCAN114x_Device_ID_Read(TCAN114x_Dev_ID *devID);
#endif /* TESTER_SUITE_CAN_TCAN114X_H_ */
