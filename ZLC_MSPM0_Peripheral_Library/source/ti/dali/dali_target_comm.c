/*
 * Copyright (c) 2021, Texas Instruments Incorporated
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
 *
 */

#include "dali_target_comm.h"

const uint32_t defaultInfo[EEPROM_EMULATION_DATA_SIZE / sizeof(uint32_t)] =
{
 (uint32_t)LAST_LIGHT_LEVEL_DEFAULT,
 (uint32_t)POWER_ON_LEVEL_DEFAULT,
 (uint32_t)SYSTEM_FAILURE_LEVEL_DEFAULT,
 (uint32_t)MIN_LEVEL_DEFAULT,
 (uint32_t)MAX_LEVEL_DEFAULT,
 (uint32_t)FADE_RATE_DEFAULT,
 (uint32_t)FADE_TIME_DEFAULT,
 (uint32_t)SHORT_ADDRESS_DEFAULT,
 (uint32_t)RANDOM_ADDRESS_DEFAULT,
 (uint32_t)GROUP_DEFAULT,
 (uint32_t)SCENE_0_DEFAULT,
 (uint32_t)SCENE_1_DEFAULT,
 (uint32_t)SCENE_2_DEFAULT,
 (uint32_t)SCENE_3_DEFAULT,
 (uint32_t)SCENE_4_DEFAULT,
 (uint32_t)SCENE_5_DEFAULT,
 (uint32_t)SCENE_6_DEFAULT,
 (uint32_t)SCENE_7_DEFAULT,
 (uint32_t)SCENE_8_DEFAULT,
 (uint32_t)SCENE_9_DEFAULT,
 (uint32_t)SCENE_10_DEFAULT,
 (uint32_t)SCENE_11_DEFAULT,
 (uint32_t)SCENE_12_DEFAULT,
 (uint32_t)SCENE_13_DEFAULT,
 (uint32_t)SCENE_14_DEFAULT,
 (uint32_t)SCENE_15_DEFAULT,
 0,
 0,
 0,
 0
};


uint32_t flash_data[EEPROM_EMULATION_DATA_SIZE / sizeof(uint32_t)];


void DALI_Target_init(){
    DALI_Target_loadDefaults();
    gControlVar1.actualLevel = gControlVar1.powerOnLevel;
    gControlVar1.targetLevel = gControlVar1.powerOnLevel;
    gControlVar1.minLevel = PHYS_MIN_LEVEL;
    gControlVar1.maxLevel = MAX_LEVEL_DEFAULT;
    gControlVar1.fadeRate = 1;
    gControlVar1.resetState = false;
}
void DALI_Target_receive(uint8_t * rxBuffer)
{
    while(gControlVar1.resetState){
        /* Do not receive/execute commands during reset */
    }
    while(!gReceive)
    {

    }
    DL_UART_Extend_drainRXFIFO(UART_0_INST, rxBuffer, DATA_SIZE);
    gReceive = false;
    if((rxBuffer[0] & 0x80) == 0x00){
        if(((rxBuffer[0] & 0x7F) >> 1) == gControlVar1.shortAddress){

            DALI_Target_execute(rxBuffer);

        }
    }
    else if((rxBuffer[0] & 0xE0) == 0x80){
        if(gControlVar1.gearGroups >> ((rxBuffer[0] & 0x1E) >> 1) == 0x01){
            DALI_Target_execute(rxBuffer);
        }
    }
    else if( (rxBuffer[0] == 0xFC) || (rxBuffer[0] == 0xFD) ){
        DALI_Target_execute(rxBuffer);
    }
    else if( (rxBuffer[0] == 0xFE) || (rxBuffer[0] == 0xFF) ){
        DALI_Target_execute(rxBuffer);
    }
    else if( (rxBuffer[0] >= 0xA0) || (rxBuffer[0] <= 0xCB) ){
        DALI_Target_execute(rxBuffer);
    }
}

void DALI_Target_execute(uint8_t * receivedData){
    if((receivedData[0] & 0x01) == 0x00){
        DALI_DAPC(receivedData);
    }
    else if(receivedData[0] == 0xA1){
        DALI_terminate();
    }
    else if(receivedData[0] == 0xA3){
        DALI_dtr0(receivedData);
    }
    else if(receivedData[0] == 0xA5){
        DALI_initialize();
    }
    else if(receivedData[0] == 0xA7){
        DALI_randomiseAddress();
    }
    else if(receivedData[0] == 0xA9){
        DALI_compareAddress();
    }
    else if(receivedData[0] == 0xAB){
        DALI_withdraw();
    }
    else if(receivedData[0] == 0xB1){
        DALI_searchAddrH(receivedData);
    }
    else if(receivedData[0] == 0xB3){
        DALI_searchAddrM(receivedData);
    }
    else if(receivedData[0] == 0xB5){
        DALI_searchAddrL(receivedData);
    }
    else if(receivedData[0] == 0xB7){
        DALI_programShortAddress(receivedData);
    }
    else if(receivedData[0] == 0xB9){
        DALI_verifyShortAddress(receivedData);
    }
    else if(receivedData[0] == 0xBB){
        DALI_queryShortAddress();
    }
    else if(receivedData[0] == 0xC1){
        DALI_enableDeviceType(receivedData);
    }
    else if(receivedData[0] == 0xC3){
        DALI_dtr1(receivedData);
    }
    else if(receivedData[0] == 0xC5){
        DALI_dtr2(receivedData);
    }
    else if(receivedData[0] == 0xC7){
        DALI_writeMemoryLocation(receivedData);
    }
    else if(receivedData[0] == 0xC9){
        DALI_writeMemoryLocationNoReply(receivedData);
    }
    else if(receivedData[1] == 0x00){
        DALI_turnOff();
    }
    else if(receivedData[1] == 0x01){
        DALI_up();
    }
    else if(receivedData[1] == 0x02){
        DALI_down();
    }
    else if(receivedData[1] == 0x03){
        DALI_stepUp();
    }
    else if(receivedData[1] == 0x04){
        DALI_stepDown();
    }
    else if(receivedData[1] == 0x05){
        DALI_recallMaxLevel();
    }
    else if(receivedData[1] == 0x06){
        DALI_recallMinLevel();
    }
    else if(receivedData[1] == 0x20){
        DALI_reset();
    }
    else if(receivedData[1] == 0x21){
        DALI_storeActualLevelDTR0();
    }
    else if(receivedData[1] == 0x23){
        DALI_setOperatingMode();
    }
    else if(receivedData[1] == 0x24){
        DALI_resetMemoryBank();
    }
    else if(receivedData[1] == 0x25){
        DALI_identifyDevice();
    }
    else if(receivedData[1] == 0x2A){
        DALI_setMaxLevel();
    }
    else if(receivedData[1] == 0x2B){
        DALI_setMinLevel();
    }
    else if(receivedData[1] == 0x2C){
        DALI_setSystemFailureLevel();
    }
    else if(receivedData[1] == 0x2D){
        DALI_setPowerOnLevel();
    }
    else if(receivedData[1] == 0x2E){
        DALI_setFadeTime();
    }
    else if(receivedData[1] == 0x2F){
        DALI_setFadeRate();
    }
    else if(receivedData[1] == 0x30){
        DALI_setExtendedFadeTime();
    }
    else if( (receivedData[1] >= 0x40) && (receivedData[1] <= 0x4F) ){
        DALI_setScene(receivedData);
    }
    else if( (receivedData[1] >= 0x50) && (receivedData[1] <= 0x5F) ){
        DALI_removeFromScene(receivedData);
    }
    else if( (receivedData[1] >= 0x60) && (receivedData[1] <= 0x6F) ){
        DALI_addToGroup(receivedData);
    }
    else if( (receivedData[1] >= 0x70) && (receivedData[1] <= 0x7F) ){
        DALI_removeGroup(receivedData);
    }
    else if(receivedData[1] == 0x80){
        DALI_setShortAddress();
    }
    else if(receivedData[1] == 0x81){
        DALI_enableWriteMemory();
    }
    else if(receivedData[1] == 0x90){
        DALI_queryStatus();
    }
    else if(receivedData[1] == 0x91){
        DALI_queryControlGearPresent();
    }
    else if(receivedData[1] == 0x92){
        DALI_queryLampFailure();
    }
    else if(receivedData[1] == 0x93){
        DALI_queryLampPowerOn();
    }
    else if(receivedData[1] == 0x94){
        DALI_queryLimitError();
    }
    else if(receivedData[1] == 0x95){
        DALI_queryResetState();
    }
    else if(receivedData[1] == 0x96){
        DALI_queryMissingShortAddress();
    }
    else if(receivedData[1] == 0x97){
        DALI_queryVersionNumber();
    }
    else if(receivedData[1] == 0x98){
        DALI_queryContentDTR0();
    }
    else if(receivedData[1] == 0x99){
        DALI_queryDeviceType();
    }
    else if(receivedData[1] == 0x9A){
        DALI_queryPhysicalMinimum();
    }
    else if(receivedData[1] == 0x9B){
        DALI_queryPowerFailure();
    }
    else if(receivedData[1] == 0x9C){
        DALI_queryContentDTR1();
    }
    else if(receivedData[1] == 0x9D){
        DALI_queryContentDTR2();
    }
    else if(receivedData[1] == 0x9E){
        DALI_queryOperatingMode();
    }
    else if(receivedData[1] == 0x9F){
        DALI_queryLightSourceType();
    }
    else if(receivedData[1] == 0xA0){
        DALI_queryActualLevel();
    }
    else if(receivedData[1] == 0xA1){
        DALI_queryMaxLevel();
    }
    else if(receivedData[1] == 0xA2){
        DALI_queryMinLevel();
    }
    else if(receivedData[1] == 0xA3){
        DALI_queryPowerOnLevel();
    }
    else if(receivedData[1] == 0xA4){
        DALI_querySystemFailureLevel();
    }
    else if(receivedData[1] == 0xA5){
        DALI_queryFadeRateTime();
    }
    else if(receivedData[1] == 0xA6){
        DALI_queryManufacturerMode();
    }
    else if(receivedData[1] == 0xA7){
        DALI_queryNextDeviceType();
    }
    else if(receivedData[1] == 0xA8){
        DALI_queryExtendedFadeTime();
    }
    else if(receivedData[1] == 0xAA){
        DALI_queryControlGearFailure();
    }
    else if( (receivedData[1] >= 0xB0) && (receivedData[1] <= 0xBF) ){
        DALI_querySceneLevel(receivedData);
    }
    else if(receivedData[1] == 0xC0){
        DALI_queryGroup0_7();
    }
    else if(receivedData[1] == 0xC1){
        DALI_queryGroups8_15();
    }
    else if(receivedData[1] == 0xC2){
        DALI_queryRandomAddressHigh();
    }
    else if(receivedData[1] == 0xC3){
        DALI_queryRandomAddressMiddle();
    }
    else if(receivedData[1] == 0xC4){
        DALI_queryRandomAddressLow();
    }
    else if(receivedData[1] == 0xC5){
        DALI_readMemoryLocation();
    }
    else if(receivedData[1] == 0xE0){
        DALI_LED_referenceSystemPower();
    }
    else if(receivedData[1] == 0xE3){
        DALI_LED_selectDimmingCurve();
    }
    else if(receivedData[1] == 0xE4){
        DALI_LED_setFastFadeTime();
    }
    else if(receivedData[1] == 0xED){
        DALI_LED_queryControlGearType();
    }
    else if(receivedData[1] == 0xEE){
        DALI_LED_queryDimmingCurve();
    }
    else if(receivedData[1] == 0xF0){
        DALI_LED_queryFeatures();
    }
    else if(receivedData[1] == 0xF1){
        DALI_LED_queryFailureStatus();
    }
    else if(receivedData[1] == 0xF4){
        DALI_LED_queryLoadDecrease();
    }
    else if(receivedData[1] == 0xF5){
        DALI_LED_queryLoadIncrease();
    }
    else if(receivedData[1] == 0xF7){
        DALI_LED_queryThermalShutdown();
    }
    else if(receivedData[1] == 0xF8){
        DALI_LED_queryThermalOverload();
    }
    else if(receivedData[1] == 0xF9){
        DALI_LED_queryReferenceRunning();
    }
    else if(receivedData[1] == 0xFA){
        DALI_LED_queryReferenceMeasurementFailed();
    }
    else if(receivedData[1] == 0xFD){
        DALI_LED_queryFastFadeTime();
    }
    else if(receivedData[1] == 0xFE){
        DALI_LED_queryMinFastFadeTime();
    }
    else if(receivedData[1] == 0xFF){
        DALI_LED_queryExtendedVersionNumber();
    }


}

void DALI_Target_transmit(void){
    if(gControlVar1.transmitDataFlag){
        delay_cycles(32000000 * 0.007);
        DL_UART_transmitData(UART_0_INST, gControlVar1.transmitData);
        DL_UART_receiveDataBlocking(UART_0_INST);
    }
    gControlVar1.transmitDataFlag = false;
}

void DALI_Target_failure(){
    /* TEMPLATE FOR FAILURE CHECKING
     * Check for any light source failures here
     * set status bits
     */
}

void DALI_Target_flashUpdate(){

    if(gControlVar1.updateFlash){
        /* THIS IMPLEMENTATION USES EEPROM TYPE A WHICH BACKS UP THE ENTIRE BLOCK
        EEPROM TYPE B BACKS UP INDIVIDUAL VARIABLES, CAN BE USED IN ALTERNATE IMPLEMENTATIONS */
        flash_data[0] = gControlVar1.lastLightLevel;
        flash_data[1] = gControlVar1.powerOnLevel;
        flash_data[2] = gControlVar1.systemFailureLevel;
        flash_data[3] = gControlVar1.minLevel;
        flash_data[4] = gControlVar1.maxLevel;
        flash_data[5] = gControlVar1.fadeRate;
        flash_data[6] = gControlVar1.fadeTime;
        flash_data[7] = gControlVar1.shortAddress;
        flash_data[8] = gControlVar1.randomAddress;
        flash_data[9] = gControlVar1.gearGroups;
        flash_data[10] = gControlVar1.sceneX[0];
        flash_data[11] = gControlVar1.sceneX[1];
        flash_data[12] = gControlVar1.sceneX[2];
        flash_data[13] = gControlVar1.sceneX[3];
        flash_data[14] = gControlVar1.sceneX[4];
        flash_data[15] = gControlVar1.sceneX[5];
        flash_data[16] = gControlVar1.sceneX[6];
        flash_data[17] = gControlVar1.sceneX[7];
        flash_data[18] = gControlVar1.sceneX[8];
        flash_data[19] = gControlVar1.sceneX[9];
        flash_data[20] = gControlVar1.sceneX[10];
        flash_data[21] = gControlVar1.sceneX[11];
        flash_data[22] = gControlVar1.sceneX[12];
        flash_data[23] = gControlVar1.sceneX[13];
        flash_data[24] = gControlVar1.sceneX[14];
        flash_data[25] = gControlVar1.sceneX[15];

        EEPROM_TypeA_writeData(&flash_data[0]);
        if(gEEPROMTypeAEraseFlag){
            EEPROM_TypeA_eraseLastSector();
            gEEPROMTypeAEraseFlag = 0;
        }
        gControlVar1.updateFlash = false;
    }

}

void DALI_Target_loadDefaults(){
    uint32_t state = EEPROM_TypeA_init(&flash_data[0]);
    if(state == EEPROM_EMULATION_INIT_OK && gEEPROMTypeASearchFlag == false){
        for(uint8_t i = 0; i < EEPROM_EMULATION_DATA_SIZE / sizeof(uint32_t); i++){
            flash_data[i] = defaultInfo[i];
        }
        EEPROM_TypeA_writeData(&flash_data[0]);
    }
    gControlVar1.memoryBank0[0] = MEM_BANK_0_START_ADDRESS;
    gControlVar1.memoryBank0[1] = MEM_BANK_SIZE;
    gControlVar1.memoryBank0[2] = 0x00;
    gControlVar1.memoryBank0[3] = 0;
    gControlVar1.memoryBank0[4] = 1;
    gControlVar1.memoryBank0[5] = 2;
    gControlVar1.memoryBank0[6] = 3;
    gControlVar1.memoryBank0[7] = 4;
    gControlVar1.memoryBank0[8] = 5;
    gControlVar1.memoryBank0[9] = 1;
    gControlVar1.memoryBank0[10] = 0;
    gControlVar1.memoryBank0[11] = 0;
    gControlVar1.memoryBank0[12] = 1;
    gControlVar1.memoryBank0[13] = 2;
    gControlVar1.memoryBank0[14] = 3;
    gControlVar1.memoryBank0[15] = 4;
    gControlVar1.lastLightLevel = flash_data[0];
    gControlVar1.powerOnLevel = flash_data[1];
    gControlVar1.systemFailureLevel = flash_data[2];
    gControlVar1.minLevel = flash_data[3];
    gControlVar1.maxLevel = flash_data[4];
    gControlVar1.fadeRate = flash_data[5];
    gControlVar1.fadeTime = flash_data[6];
    gControlVar1.shortAddress = flash_data[7];
    gControlVar1.randomAddress = flash_data[8];
    gControlVar1.gearGroups = flash_data[9];
    gControlVar1.sceneX[0] = flash_data[10];
    gControlVar1.sceneX[1] = flash_data[11];
    gControlVar1.sceneX[2] = flash_data[12];
    gControlVar1.sceneX[3] = flash_data[13];
    gControlVar1.sceneX[4] = flash_data[14];
    gControlVar1.sceneX[5] = flash_data[15];
    gControlVar1.sceneX[6] = flash_data[16];
    gControlVar1.sceneX[7] = flash_data[17];
    gControlVar1.sceneX[8] = flash_data[18];
    gControlVar1.sceneX[9] = flash_data[19];
    gControlVar1.sceneX[10] = flash_data[20];
    gControlVar1.sceneX[11] = flash_data[21];
    gControlVar1.sceneX[12] = flash_data[22];
    gControlVar1.sceneX[13] = flash_data[23];
    gControlVar1.sceneX[14] = flash_data[24];
    gControlVar1.sceneX[15] = flash_data[25];

    /* POWER ON Settings */
    /* General Control Gear POWER ON Levels */
    gControlVar1.actualLevel = 0;
    gControlVar1.targetLevel = 0;
    gControlVar1.lastActiveLevel = gControlVar1.maxLevel;
    gControlVar1.initialisationState = DISABLED;
    gControlVar1.searchAddress = MASK >> 8;
    gControlVar1.writeEnableState = DISABLED;
    gControlVar1.lampFailure = false;
    gControlVar1.powerCycleSeen = true;
    gControlVar1.lampOn = true;
    gControlVar1.limitError = false;
    gControlVar1.fadeRunning = false;
    gControlVar1.resetState = true;
    /* LED Module Specific POWER ON Levels */
    gControlVar1.ledControlGear.dimmingCurve = DIMMING_CURVE_DEFAULT;
    gControlVar1.ledControlGear.deviceType = DEVICE_TYPE_DEFAULT;
    gControlVar1.ledControlGear.controlGearType = CONTROL_GEAR_TYPE_DEFAULT;
    gControlVar1.ledControlGear.features = FEATURES_DEFAULT;
    gControlVar1.ledControlGear.fastFadeTime = FAST_FADE_TIME_DEFAULT;
    gControlVar1.ledControlGear.minFastFadeTime = MIN_FAST_FADE_TIME_DEFAULT;
    gControlVar1.ledControlGear.enableLEDDevice = false;
}

