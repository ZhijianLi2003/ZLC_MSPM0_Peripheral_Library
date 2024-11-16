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
 * tcan114x.c
 *
 *  Created on: Dec 4, 2018
 *      Author: a0225039
 *
 *  2018/12/04: Version 0.1
 *   - Basic functions written and complete
 *  2022/10/20: Version 0.2
 *   - Added support to read device ID
 */
#include "tcan114x.h"

/*
 * @brief Reads the current device mode
 * @returns TCAN114X_MODE_ENUM of the current mode. If unknown mode detected, then sleep will be returned
 */
TCAN114X_MODE_ENUM
TCAN114x_Mode_Read(void)
{
    TCAN114x_Mode_Control modeRegister;
    TCAN114x_Mode_Control_Read(&modeRegister);

    switch (modeRegister.MODE_SEL) {
        default:
            return TCAN114X_MODE_SLEEP;
        case REG_BITS_TCAN114X_MODE_CNTRL_MODE_STANDBY:
            return TCAN114X_MODE_STANDBY;
        case REG_BITS_TCAN114X_MODE_CNTRL_MODE_LISTEN:
            return TCAN114X_MODE_LISTEN;
        case REG_BITS_TCAN114X_MODE_CNTRL_MODE_NORMAL:
            return TCAN114X_MODE_NORMAL;
    }
}

/*
 * @brief Changes the device's mode to the requested @param modeRequest parameter
 * @param modeRequest is a @c TCAN114X_MODE_ENUM enum for the requested mode change
 * @returns TCAN114X_STATUS_ENUM if the change was successful or not. Note that sleep mode will always return true because SPI is not accessible in sleep
 */
TCAN114X_STATUS_ENUM
TCAN114x_Mode_Set(TCAN114X_MODE_ENUM modeRequest)
{
    TCAN114x_Mode_Control modeRegister;
    TCAN114x_Mode_Control_Read(&modeRegister);

    switch (modeRequest) {
        default:
            return TCAN114X_FAIL;
        case TCAN114X_MODE_SLEEP: {
            modeRegister.MODE_SEL = REG_BITS_TCAN114X_MODE_CNTRL_MODE_SLEEP;
            TCAN114x_Mode_Control_Write(&modeRegister);
            return TCAN114X_SUCCESS;
        }

        case TCAN114X_MODE_STANDBY:
            modeRegister.MODE_SEL = REG_BITS_TCAN114X_MODE_CNTRL_MODE_STANDBY;
            break;
        case TCAN114X_MODE_LISTEN:
            modeRegister.MODE_SEL = REG_BITS_TCAN114X_MODE_CNTRL_MODE_LISTEN;
            break;
        case TCAN114X_MODE_NORMAL:
            modeRegister.MODE_SEL = REG_BITS_TCAN114X_MODE_CNTRL_MODE_NORMAL;
            break;
    }

    if (TCAN114x_Mode_Control_Write(&modeRegister) != TCAN114X_SUCCESS)
        return TCAN114X_FAIL;

    return TCAN114X_SUCCESS;
}

/* ************************************* *
 *            Get/Set Functions          *
 * ************************************* */

/*
 * @brief Reads the contents of the mode control register, and updates the @param ModeControl parameter
 * @param ModeControl is a @c TCAN114x_Mode_Control struct containing the contents of the mode control register
 * @returns TCAN114X_STATUS_ENUM if the read was successful or failed
 */
TCAN114X_STATUS_ENUM
TCAN114x_Mode_Control_Read(TCAN114x_Mode_Control *ModeControl)
{
    uint8_t readValue;
    TCAN_READ(REG_TCAN114X_MODE_CONTROL, &readValue);
    ModeControl->word = readValue;
    return TCAN114X_SUCCESS;
}

/*
 * @brief Writes the contents of the @param ModeControl struct to the TCAN114x
 * @param ModeControl is a @c TCAN114x_Mode_Control struct containing the contents of the mode control register
 * @returns TCAN114X_STATUS_ENUM if the write was successful or failed. If @c TCAN114X_CONFIGURE_VERIFY_WRITES is defined, then the write will be verified
 */
TCAN114X_STATUS_ENUM
TCAN114x_Mode_Control_Write(TCAN114x_Mode_Control *ModeControl)
{
    TCAN_WRITE(REG_TCAN114X_MODE_CONTROL, &ModeControl->word);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
    uint8_t readValue;
    TCAN_READ(REG_TCAN114X_MODE_CONTROL, &readValue);
    if (readValue != ModeControl->word) return TCAN114X_FAIL;
#endif
    return TCAN114X_SUCCESS;
}

/*
 * @brief Reads the contents of the wake pin configuration register, and updates the @param WakePin parameter
 * @param WakePin is a @c TCAN114x_Wake_Pin_Config struct containing the contents of the wake pin configuration register
 * @returns TCAN114X_STATUS_ENUM if the read was successful or failed
 */
TCAN114X_STATUS_ENUM
TCAN114x_Wake_Pin_Config_Read(TCAN114x_Wake_Pin_Config *WakePin)
{
    uint8_t readValue;
    TCAN_READ(REG_TCAN114X_WAKE_PIN_CONFIG, &readValue);
    WakePin->word = readValue;
    return TCAN114X_SUCCESS;
}

/*
 * @brief Writes the contents of the @param WakePin struct to the TCAN114x
 * @param WakePin is a @c TCAN114x_Wake_Pin_Config struct containing the contents of the wake pin configuration register
 * @returns TCAN114X_STATUS_ENUM if the write was successful or failed. If @c TCAN114X_CONFIGURE_VERIFY_WRITES is defined, then the write will be verified
 */
TCAN114X_STATUS_ENUM
TCAN114x_Wake_Pin_Config_Write(TCAN114x_Wake_Pin_Config *WakePin)
{
    TCAN_WRITE(REG_TCAN114X_WAKE_PIN_CONFIG, &WakePin->word);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
    uint8_t readValue;
    TCAN_READ(REG_TCAN114X_WAKE_PIN_CONFIG, &readValue);
    if (readValue != WakePin->word) return TCAN114X_FAIL;
#endif
    return TCAN114X_SUCCESS;
}

/*
 * @brief Reads the contents of the device pin configuration register, and updates the @param PinConfig parameter
 * @param PinConfig is a @c TCAN114x_Pin_Config struct containing the contents of the pin configuration register
 * @returns TCAN114X_STATUS_ENUM if the read was successful or failed
 */
TCAN114X_STATUS_ENUM
TCAN114x_Device_Pin_Config_Read(TCAN114x_Pin_Config *PinConfig)
{
    uint8_t readValue;
    TCAN_READ(REG_TCAN114X_PIN_CONFIG, &readValue);
    PinConfig->word = readValue;
    return TCAN114X_SUCCESS;
}

/*
 * @brief Writes the contents of the @param PinConfig struct to the TCAN114x
 * @param PinConfig is a @c TCAN114x_Pin_Config struct containing the contents of the device pin configuration register
 * @returns TCAN114X_STATUS_ENUM if the write was successful or failed. If @c TCAN114X_CONFIGURE_VERIFY_WRITES is defined, then the write will be verified
 */
TCAN114X_STATUS_ENUM
TCAN114x_Device_Pin_Config_Write(TCAN114x_Pin_Config *PinConfig)
{
    TCAN_WRITE(REG_TCAN114X_PIN_CONFIG, &PinConfig->word);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
    uint8_t readValue;
    TCAN_READ(REG_TCAN114X_PIN_CONFIG, &readValue);
    if (readValue != PinConfig->word) return TCAN114X_FAIL;
#endif
    return TCAN114X_SUCCESS;
}

/*
 * @brief Reads the contents of partial networking registers and updates the the @param pnConfig struct
 * @param pnConfig is a @c TCAN114x_PN_Config struct containing settings needed to configure the partial networking registers
 * @returns TCAN114X_STATUS_ENUM if the read was successful or failed.
 */
TCAN114X_STATUS_ENUM
TCAN114x_PN_Config_Read(TCAN114x_PN_Config *pnConfig)
{
    uint8_t data[17]     = {0};  // Data stream of the registers
    uint8_t sw_config[2] = {
        0};  // Registers for the selective wake configuration registers
    uint8_t index   = 0;
    uint32_t id     = 0;
    uint8_t address = REG_TCAN114X_SW_ID_1;
    for (index = 0; index < 17; index++) {
        TCAN_READ(address, &data[index]);
        address++;  // Increment the address we're writing to
    }
    // Read the sw_config registers
    TCAN_READ(REG_TCAN114X_SW_CONFIG_1, &sw_config[0]);
    TCAN_READ(REG_TCAN114X_SW_CONFIG_3, &sw_config[1]);

    // If IDE is enabled...
    if (data[2] & REG_BITS_TCAN114X_SW_ID3_IDE) {
        pnConfig->IDE = 1;
        id = (uint32_t) data[0] << 10;  //SW_ID1[7:0] which is ID[17:10]
        id |= (uint32_t) data[1] << 2;  //SW_ID2[7:0] which is ID[9:2]
        id |= (uint32_t)(data[2] & 0x1F)
              << 24;  //SW_ID3[4:0] which is ID[28:24]
        id |= (uint32_t)(data[2] & 0xC0) >> 6;  //SW_ID3[7:6] which is ID[1:0]
        id |= ((uint32_t)(data[3] & 0xFC) >> 2)
              << 18;  //SW_ID4[7:2] which is ID[23:18]
        pnConfig->ID = id;

        id = (uint32_t)(data[4] & 0x03)
             << 16;                      //SW_ID_MASK1[1:0] which is IDM[17:16]
        id |= (uint32_t) data[5] << 8;   //SW_ID_MASK2[7:0] which is IDM[15:8]
        id |= (uint32_t) data[6];        //SW_ID_MASK3[7:0] which is IDM[7:0]
        id |= (uint32_t) data[7] << 21;  //SW_ID_MASK4[7:0] which is IDM[28:21]
        id |= ((uint32_t)(data[8] & 0xE0) >> 5)
              << 18;  //SW_ID_MASK_DLC[7:5] which is IDM[20:18]
        pnConfig->IDMask = id;
        pnConfig->DLC    = ((data[8] >> 1) & 0x0F);

    } else {
        // Else we just build the normal ID
        pnConfig->IDE = 0;
        id = (uint32_t)(data[2] & 0x3F) << 6;   //SW_ID3[5:0] which is ID[10:6]
        id |= (uint32_t)(data[3] & 0xFC) >> 2;  //SW_ID4[7:2] which is ID[5:0]
        pnConfig->ID = id;

        id = (uint32_t) data[7] << 3;  //SW_ID_MASK4[7:0] which is ID[10:3]
        id |= (uint32_t)(data[8] & 0xE0) >>
              5;  //SW_ID_MASK_DLC[7:5] which is ID[2:0]
        pnConfig->IDMask = id;
        pnConfig->DLC    = ((data[8] >> 1) & 0x0F);
    }

    // Check if data mask is enabled
    if (data[7] & REG_BITS_TCAN114X_SW_ID_MASK_DLC_DATA_MASK_EN)
        pnConfig->DataMaskEN = 1;

    // Move the data fields over to the struct
    for (index = 0; index < 8; index++) {
        pnConfig->DATA[index] = data[index + 9];
    }

    // Now the selective wake configuration registers

    // If SWFD passive bit is set
    if (sw_config[0] & 0x80)
        pnConfig->SWFDPassive = 1;
    else
        pnConfig->SWFDPassive = 0;

    pnConfig->CAN_DR              = ((sw_config[0] >> 4) & 0x07);
    pnConfig->FD_DR               = ((sw_config[0] >> 2) & 0x03);
    pnConfig->FrameErrorThreshold = sw_config[1];
    return TCAN114X_SUCCESS;
}

/*
 * @brief Writes the contents of the @param pnConfig struct to the TCAN114x partial networking registers
 * @param pnConfig is a @c TCAN114x_PN_Config struct containing settings needed to configure the partial networking registers
 * @returns TCAN114X_STATUS_ENUM if the write was successful or failed. If @c TCAN114X_CONFIGURE_VERIFY_WRITES is defined, then the writes will be verified
 */
TCAN114X_STATUS_ENUM
TCAN114x_PN_Config_Write(TCAN114x_PN_Config *pnConfig)
{
    uint8_t sw_id[4]  = {0};  // Selective wake registers used for ID/XID
    uint8_t sw_idm[5] = {0};  // Selective wake registers used for ID/XID Mask
    uint8_t data[8]   = {0};  // Data field if used.
    uint8_t sw_config = 0;    // Selective wake configuration register
    uint8_t index     = 0;

    // If XID is enabled...
    if (pnConfig->IDE) {
        sw_id[0] =
            (uint8_t)(pnConfig->ID >> 10);  //SW_ID1[7:0] which is ID[17:10]
        sw_id[1] =
            (uint8_t)(pnConfig->ID >> 2);  //SW_ID2[7:0] which is ID[9:2]
        sw_id[2] = (uint8_t)(
            (pnConfig->ID >> 24) & 0x1F);  //SW_ID3[4:0] which is ID[28:24]
        sw_id[2] |=
            (uint8_t)(pnConfig->ID << 6);  //SW_ID3[7:6] which is ID[1:0]
        sw_id[2] |= 0x20;                  //SW_ID3[5] which sets the IDE flag
        sw_id[3] = (uint8_t)(((pnConfig->ID >> 18) << 2) &
                             0xFC);  //SW_ID4[7:2] which is ID[23:18]

        sw_idm[0] = (uint8_t)((pnConfig->IDMask >> 16) &
                              0x03);  //SW_ID_MASK1[1:0] which is IDM[17:16]
        sw_idm[1] = (uint8_t)(
            pnConfig->IDMask >> 8);  //SW_ID_MASK2[7:0] which is IDM[15:8]
        sw_idm[2] =
            (uint8_t)(pnConfig->IDMask);  //SW_ID_MASK3[7:0] which is IDM[7:0]
        sw_idm[3] = (uint8_t)(
            pnConfig->IDMask >> 21);  //SW_ID_MASK4[7:0] which is IDM[28:21]
        sw_idm[4] = (uint8_t)(((pnConfig->IDMask >> 18) << 5) &
                              0xE0);  //SW_ID_MASK_DLC[7:5] which is IDM[20:18]

    } else {
        // Else we just build the normal ID
        sw_id[2] = (uint8_t)(
            (pnConfig->ID >> 6) & 0x1F);  //SW_ID3[5:0] which is ID[10:6]
        sw_id[3] = (uint8_t)(
            (pnConfig->ID << 2) & 0xFC);  //SW_ID4[7:2] which is ID[5:0]

        sw_idm[3] = (uint8_t)(
            pnConfig->IDMask >> 3);  //SW_ID_MASK4[7:0] which is ID[10:3]
        sw_idm[4] = (uint8_t)((pnConfig->IDMask << 5) &
                              0xE0);  //SW_ID_MASK_DLC[7:5] which is ID[2:0]
    }
    sw_idm[4] |= (uint8_t)(pnConfig->DLC)
                 << 1;  //SW_ID_MASK_DLC[4:1] which is the DLC

    // Check if data mask is enabled
    if (pnConfig->DataMaskEN)
        sw_idm[4] |= 1;  //SW_ID_MASK_DLC[0] which is the DATA_MASK_EN

    // If data mask is enabled
    if (pnConfig->DataMaskEN) {
        for (index = 0; index < 8; index++) {
            data[index] = pnConfig->DATA[index];
        }
    }

    // All our temporary buffers have been created. Now to write to the device.
    uint8_t address = REG_TCAN114X_SW_ID_1;
    for (index = 0; index < 17; index++) {
        uint8_t buffer;
        // If we're under 4, then we're on SW_ID
        if (index < 4) {
            buffer = sw_id[index];

        } else if (index < 9) {
            // If we're under index 9, then we're on ID mask
            buffer = sw_idm[index - 4];
        } else {
            // Then we're on the data mask
            buffer = data[index - 9];
        }

        TCAN_WRITE(address, &buffer);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
        uint8_t readBuffer;
        TCAN_READ(address, &readBuffer);
        if (readBuffer != buffer) return TCAN114X_FAIL;
#endif
        address++;  // Increment the address we're writing to
    }

    // Now to do the selective wake configuration registers
    sw_config = pnConfig->SWFDPassive << 7;
    sw_config |= pnConfig->CAN_DR << 4;
    sw_config |= pnConfig->FD_DR << 2;
    TCAN_WRITE(REG_TCAN114X_SW_CONFIG_1, &sw_config);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
    uint8_t readBuffer;
    TCAN_READ(REG_TCAN114X_SW_CONFIG_1, &readBuffer);
    if (readBuffer != sw_config) return TCAN114X_FAIL;
#endif

    sw_config = pnConfig->FrameErrorThreshold;
    TCAN_WRITE(REG_TCAN114X_SW_CONFIG_3, &sw_config);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
    TCAN_READ(REG_TCAN114X_SW_CONFIG_3, &readBuffer);
    if (readBuffer != sw_config) return TCAN114X_FAIL;
#endif

    // This write must be the last one to enable the selective wake, otherwise another config write will clear the selective wake configured bit.
    sw_config = REG_BITS_TCAN114X_SW_CONFIG_4_SWCFG;
    TCAN_WRITE(REG_TCAN114X_SW_CONFIG_4, &sw_config);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
    TCAN_READ(REG_TCAN114X_SW_CONFIG_4, &readBuffer);
    if (readBuffer != sw_config) return TCAN114X_FAIL;
#endif
    return TCAN114X_SUCCESS;
}

/*
 * @brief Reads all applicable interrupt registers from the TCAN114x and updates the passed @c TCAN114x_Interrupts struct
 * @param ir is a @c TCAN114x_Interrupts struct containing all interrupts available for the TCAN114x
 * @returns TCAN114X_STATUS_ENUM if the read was successful or failed.
 */
TCAN114X_STATUS_ENUM
TCAN114x_Device_Interrupts_Read(TCAN114x_Interrupts *ir)
{
    uint8_t data = 0;
    TCAN_READ(REG_TCAN114X_INT_GLOBAL, &data);
    TCAN_READ(REG_TCAN114X_INT_1, &data);
    TCAN_READ(REG_TCAN114X_INT_2, &data);
    TCAN_READ(REG_TCAN114X_INT_3, &data);
    TCAN_READ(REG_TCAN114X_INT_CANBUS, &data);

    return TCAN114X_SUCCESS;
}

/*
 * @brief Clears all applicable interrupts that are set in the passed @c TCAN114x_Interrupts struct to the TCAN114x
 * @param ir is a @c TCAN114x_Interrupts struct containing all interrupts available for the TCAN114x
 * @returns TCAN114X_STATUS_ENUM if the clear was successful or failed. Will verify if interrupts were cleared if the @c TCAN114X_INTERRUPTS_VERIFY_WRITES define is defined
 */
TCAN114X_STATUS_ENUM
TCAN114x_Device_Interrupts_Clear(TCAN114x_Interrupts *ir)
{
    if (ir->word_int1) {
        TCAN_WRITE(REG_TCAN114X_INT_1, &ir->word_int1);
    }

    if (ir->word_int2) {
        TCAN_WRITE(REG_TCAN114X_INT_2, &ir->word_int2);
    }

    if (ir->word_int3) {
        TCAN_WRITE(REG_TCAN114X_INT_3, &ir->word_int3);
    }

    if (ir->word_canbus) {
        TCAN_WRITE(REG_TCAN114X_INT_CANBUS, &ir->word_canbus);
    }

#ifdef TCAN114X_INTERRUPTS_VERIFY_WRITES
    TCAN114x_Interrupts irCompare = {0};
    TCAN114x_Device_Interrupts_Read(&irCompare);
    if (irCompare.word_int_global != 0) return TCAN114X_FAIL;
#endif
    return TCAN114X_SUCCESS;
}

/*
 * @brief Clears all interrupts
 * @returns TCAN114X_STATUS_ENUM if the clear was successful or failed. Will verify if interrupts were cleared if the @c TCAN114X_INTERRUPTS_VERIFY_WRITES define is defined
 */
TCAN114X_STATUS_ENUM
TCAN114x_Device_Interrupts_ClearAll(void)
{
    uint8_t data = 0xFF;
    TCAN_WRITE(REG_TCAN114X_INT_1, &data);
    TCAN_WRITE(REG_TCAN114X_INT_2, &data);
    TCAN_WRITE(REG_TCAN114X_INT_3, &data);
    TCAN_WRITE(REG_TCAN114X_INT_CANBUS, &data);

#ifdef TCAN114X_INTERRUPTS_VERIFY_WRITES
    TCAN114x_Interrupts irCompare = {0};
    TCAN114x_Device_Interrupts_Read(&irCompare);
    if (irCompare.word_int_global != 0) return TCAN114X_FAIL;
#endif
    return TCAN114X_SUCCESS;
}

/*
 * @brief Returns device ID
 * @param devID is struct to store the device ID information
 * @returns TCAN114X_STATUS_ENUM if the read was successful or failed.
 */
TCAN114X_STATUS_ENUM TCAN114x_Device_ID_Read(TCAN114x_Dev_ID *devID)
{
    TCAN_READ(REG_TCAN114X_DEVICEID0, &devID->addr0);
    TCAN_READ(REG_TCAN114X_DEVICEID1, &devID->addr1);
    TCAN_READ(REG_TCAN114X_DEVICEID2, &devID->addr2);
    TCAN_READ(REG_TCAN114X_DEVICEID3, &devID->addr3);
    TCAN_READ(REG_TCAN114X_DEVICEID4, &devID->addr4);
    TCAN_READ(REG_TCAN114X_DEVICEID5, &devID->addr5);
    TCAN_READ(REG_TCAN114X_DEVICEID6, &devID->addr6);
    TCAN_READ(REG_TCAN114X_DEVICEID7, &devID->addr7);

    return TCAN114X_SUCCESS;
}
