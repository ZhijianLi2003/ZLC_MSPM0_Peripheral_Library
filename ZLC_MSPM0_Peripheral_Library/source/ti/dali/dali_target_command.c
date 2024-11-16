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
 */


#include "dali_target_command.h"
#include "dali_target_led_command.h"

volatile uint32_t gCounter = 0;
volatile uint32_t gNumLoops = 0;
volatile uint32_t gInitCounter = 0;
volatile uint32_t gRandCounter = 0;
volatile uint32_t gResetCounter = 0;

static uint32_t DALI_linearLightOutputConversion(void){
    /* Calculate the light output when using linear scale*/
    return (uint32_t)((LINEAR_FADE_SLOPE) * (float)gControlVar1.actualLevel + LINEAR_FADE_OFFSET);
}

static uint32_t DALI_logarithmicLightOutputConversion(void){
    /* Calculate the light output when using logarithmic scale*/
    float power = ( (float)(gControlVar1.actualLevel - 1) / (float)(253 / 3) ) - 1;
    _iq16 qPower = _IQ16mpy(_IQ16(power), _IQ16log(_IQ16(10)));
    _iq16 qOutput = _IQ16exp(qPower);
    return (uint32_t)(_IQ16int(qOutput));
}

static uint32_t DALI_LightOutputConversion(void){
    /* Switch between logarithmic and linear scale*/
    if(gControlVar1.ledControlGear.dimmingCurve == 0){
        return DALI_logarithmicLightOutputConversion();
    }
    else{
        return DALI_linearLightOutputConversion();
    }
}

static uint32_t DALI_FadeRateConversion(void){
    /* Convert Fade Rate from scalar to actual rate*/
    /* See header declaration for UP/DOWN commands for equation*/
    _iq16 qPower = _IQ16div(_IQ16mpy(_IQ16(gControlVar1.fadeRate),  _IQ16log(_IQ16(2))) , _IQ16(2));
    _iq16 qExponent = _IQ16exp(qPower);
    _iq16 qQuotient = _IQ16div(_IQ16(506), qExponent);
    return (uint32_t)(_IQ16int(qQuotient));
}

static uint32_t DALI_rateToTimeConversion(void){
    /* Convert the rate into the LOAD value
     * Used to increment actual level, but only on every other tick*/
    uint32_t rate = DALI_FadeRateConversion();
    uint32_t period = (32768 / (2 * rate)) - 1;
    return period;
}

static uint8_t calculateMSB(uint32_t value){
    /* Calculate the most significant bit for fade time computation*/
    uint8_t msb = 0;
    value = value / 2;
    while(value != 0){
        value = value / 2;
        msb++;
    }
    return msb;
}

static uint32_t DALI_timeToPeriodConversion(uint32_t level){
    /* Convert Fade Time Scalar into load value relative to shift in level*/
    uint32_t delta = 0;
    /* Determine what the shift in level will be*/
    if(level > gControlVar1.actualLevel){
        delta = level - gControlVar1.actualLevel;
    }
    else{
        delta = gControlVar1.actualLevel - level;
    }
    uint8_t msb = calculateMSB(2 * delta);
    uint8_t power = (gControlVar1.fadeTime / 2) - 1;
    uint32_t buffer = 0;
    /* Using the MSB and the power from the fade time equation(reference DAPC function declaration),
     *  compute the load value for the timer and prescaler for the clock
     */
    if(gControlVar1.fadeTime == 1){
        return (uint32_t)(((0xB505 >> 1) / (2 * delta)) & 0x0000FFFF);
    }
    if(msb >= power){
        DL_Timer_ClockConfig config;
        DL_Timer_getClockConfig(TIMER_0_INST, &config);
        config.prescale = 0;
        DL_Timer_setClockConfig(TIMER_0_INST, &config);
        if(gControlVar1.fadeTime % 2 == 1){
            buffer = ODD_BUFFER_VALUE;
        }
        else{
            buffer = EVEN_BUFFER_VALUE;

        }
        buffer = buffer << power;
        buffer = buffer / (2 * delta);
        buffer &= 0x0000FFFF;
        return buffer;
    }
    else{
        DL_Timer_ClockConfig config;
        DL_Timer_getClockConfig(TIMER_0_INST, &config);
        config.prescale = (0x01 << (power - msb)) - 1;
        DL_Timer_setClockConfig(TIMER_0_INST, &config);
        if(gControlVar1.fadeTime % 2 == 1){
            buffer = (ODD_BUFFER_VALUE << (msb)) / (2 * delta);
        }
        else{
            buffer = (EVEN_BUFFER_VALUE << (msb)) / (2 * delta);
        }
        return buffer;
    }
}



/* Execution Commands */

void DALI_DAPC(uint8_t * receivedData){
    /* Set target level to value sent from command*/
    gControlVar1.targetLevel = receivedData[1];
    gControlVar1.lastActiveLevel = gControlVar1.targetLevel;
    /* Turn on lamp/device if off, do not include in timer period computation*/
    if(gControlVar1.actualLevel == 0x00){
        gControlVar1.actualLevel = gControlVar1.minLevel;
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_startCounter(PWM_0_INST);
    }
    /* Set upper and lower bounds for increasing and decreasing the actual level*/
    if(gControlVar1.targetLevel > gControlVar1.actualLevel){
        gNumLoops = 2 * (gControlVar1.targetLevel - gControlVar1.actualLevel);
    }
    else{
        gNumLoops = 2 * (gControlVar1.actualLevel - gControlVar1.targetLevel);
    }
    /* Start timer and fade routine if actual level and target level are not equal*/
    if((gControlVar1.actualLevel != gControlVar1.targetLevel)){
        /* Compute and set timer period*/
        DL_Timer_setLoadValue(TIMER_0_INST, DALI_timeToPeriodConversion(gControlVar1.targetLevel));
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, 1000 - (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_setTimerCount(TIMER_0_INST, DALI_timeToPeriodConversion(gControlVar1.targetLevel));
        NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
        DL_Timer_startCounter(TIMER_0_INST);
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_startCounter(PWM_0_INST);
        gControlVar1.fadeRunning = true;
    }
}

void DALI_turnOff(void)
{
    gControlVar1.targetLevel = 0x00;
    gControlVar1.actualLevel = 0x00;
    DL_Timer_setCaptureCompareValue(
            PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
    DL_Timer_startCounter(PWM_0_INST);
}

void DALI_up(void){
    /* Turn off fade and calculate target level*/
    /* Calculate with respect to upper and lower bounds of possible target level*/
    gControlVar1.fadeRunning = false;
    uint32_t totalSteps = DALI_FadeRateConversion() * 200 * .001;
    if(gControlVar1.maxLevel - totalSteps > gControlVar1.targetLevel){
        gControlVar1.targetLevel = totalSteps + gControlVar1.actualLevel + 1;
    }
    else{
        gControlVar1.targetLevel = gControlVar1.maxLevel;
    }
    /* Turn on lamp/device if off, do not include in timer period computation*/
    if(gControlVar1.actualLevel == 0x00){
        gControlVar1.actualLevel = gControlVar1.minLevel;
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_startCounter(PWM_0_INST);
    }
    gControlVar1.lastActiveLevel = gControlVar1.targetLevel;
    /* Calculate number of times timer has to count*/
    gNumLoops = (200.0 * 0.001) / (0.5 / DALI_FadeRateConversion());
    /* Ensure reaction to command */
    if(gControlVar1.actualLevel < gControlVar1.targetLevel){
        gControlVar1.actualLevel++;
    }
    /* If conditions are met, start timer to initiate fade*/
    if((gControlVar1.actualLevel < gControlVar1.targetLevel) && (gControlVar1.actualLevel != gControlVar1.maxLevel) && (gControlVar1.actualLevel != 0)){
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, 1000 - (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
        DL_Timer_startCounter(TIMER_0_INST);
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_startCounter(PWM_0_INST);
        gControlVar1.fadeRunning = true;

    }

}

void DALI_down(void){
    /* Turn off fade and calculate target level*/
    /* Calculate with respect to upper and lower bounds of possible target level*/
    gControlVar1.fadeRunning = false;
    uint32_t totalSteps = DALI_FadeRateConversion() * (200.0 * .001);
    if(gControlVar1.minLevel + totalSteps + 1 < gControlVar1.targetLevel){
        gControlVar1.targetLevel = gControlVar1.actualLevel - totalSteps - 1;
    }
    else{
        gControlVar1.targetLevel = gControlVar1.minLevel;
    }
    gControlVar1.lastActiveLevel = gControlVar1.targetLevel;
    /* Calculate number of times timer has to count*/
    gNumLoops = (200.0 * 0.001) / (0.5 / DALI_FadeRateConversion());
    /* Ensure reaction to command */
    if(gControlVar1.actualLevel > gControlVar1.targetLevel){
        gControlVar1.actualLevel--;
    }
    /* If conditions are met, start timer to initiate fade*/
    if(gControlVar1.actualLevel > gControlVar1.targetLevel && gControlVar1.actualLevel != gControlVar1.minLevel && gControlVar1.actualLevel != 0){
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, 1000 - (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
        DL_Timer_startCounter(TIMER_0_INST);
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_startCounter(PWM_0_INST);
        gControlVar1.fadeRunning = true;
    }
}

void DALI_stepUp(void){
    /* If target level is currently 0, it stays at 0*/
    if(gControlVar1.targetLevel == 0){
        gControlVar1.targetLevel = 0;
    }
    /* If target level is greater than min level and less than max, then increment by one*/
    else if(gControlVar1.targetLevel >= gControlVar1.minLevel && gControlVar1.targetLevel < gControlVar1.maxLevel){
        gControlVar1.targetLevel += 1;
        gControlVar1.lastActiveLevel = gControlVar1.targetLevel;
    }
    /* Otherwise it stays at max level*/
    else{
        gControlVar1.targetLevel = gControlVar1.maxLevel;
        gControlVar1.lastActiveLevel = gControlVar1.targetLevel;
    }
    /* Immediately switch actual level to new target level and update light*/
    gControlVar1.actualLevel = gControlVar1.targetLevel;
    DL_Timer_setCaptureCompareValue(
            PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
    DL_Timer_startCounter(PWM_0_INST);
}

void DALI_stepDown(void){
    /* If target level is currently 0, it stays at 0*/
    if(gControlVar1.targetLevel == 0){
        gControlVar1.targetLevel = 0;
    }
    /* If target level is less than max level and greater than min, then decrement by one*/
    else if(gControlVar1.targetLevel <= gControlVar1.maxLevel && gControlVar1.targetLevel > gControlVar1.minLevel){
        gControlVar1.targetLevel -= 1;
        gControlVar1.lastActiveLevel = gControlVar1.targetLevel;
    }
    /* Otherwise it stays at min level*/
    else{
        gControlVar1.targetLevel = gControlVar1.minLevel;
        gControlVar1.lastActiveLevel = gControlVar1.targetLevel;
    }
    /* Immediately switch actual level to new target level and update light*/
    gControlVar1.actualLevel = gControlVar1.targetLevel;
    DL_Timer_setCaptureCompareValue(
            PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
    DL_Timer_startCounter(PWM_0_INST);
}

void DALI_recallMinLevel(void){
    /* If not initialized, set target and actual level to minLevel and update light*/
    if(gControlVar1.initialisationState == DISABLED){
        gControlVar1.targetLevel = gControlVar1.minLevel;
        gControlVar1.actualLevel = gControlVar1.minLevel;
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_startCounter(PWM_0_INST);
    }
    /* If initialized or in initialization, set light level to physical minimum level*/
    else{
        gControlVar1.targetLevel = gControlVar1.minLevel;
        gControlVar1.actualLevel = PHYS_MIN_LEVEL;
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_startCounter(PWM_0_INST);
        gControlVar1.actualLevel = gControlVar1.minLevel;
    }
}

void DALI_recallMaxLevel(void){
    /* If not initialized, set target and actual level to maxLevel and update light*/
    if(gControlVar1.initialisationState == DISABLED){
        gControlVar1.targetLevel = gControlVar1.maxLevel;
        gControlVar1.actualLevel = gControlVar1.maxLevel;
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_startCounter(PWM_0_INST);
    }
    /* If initialized or in initialization, set light level to absolute max level(or whatever value is closest to 100%)*/
    else{
        gControlVar1.targetLevel = gControlVar1.maxLevel;
        gControlVar1.actualLevel = MAX_LEVEL_DEFAULT - 1;
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_startCounter(PWM_0_INST);
        gControlVar1.actualLevel = gControlVar1.maxLevel;
    }
}

/* Configuration Command */
void DALI_reset(void){
    /* set reset state to true, start reset timer, and set all reset values*/
    gControlVar1.resetState = true;
    gControlVar1.terminate = false;
    NVIC_EnableIRQ(TIMER_2_INST_INT_IRQN);
    DL_Timer_startCounter(TIMER_2_INST);
    gControlVar1.actualLevel = ACTUAL_LEVEL_RESET;
    gControlVar1.targetLevel = TARGET_LEVEL_RESET;
    gControlVar1.lastActiveLevel = LAST_ACTIVE_LEVEL_RESET;
    gControlVar1.lastLightLevel = LAST_LIGHT_LEVEL_RESET;
    gControlVar1.powerOnLevel = POWER_ON_LEVEL_RESET;
    gControlVar1.systemFailureLevel = SYSTEM_FAILURE_LEVEL_RESET;
    gControlVar1.minLevel = MIN_LEVEL_RESET;
    gControlVar1.maxLevel = MAX_LEVEL_RESET;
    gControlVar1.fadeRate = FADE_RATE_RESET;
    gControlVar1.fadeTime = FADE_TIME_RESET;
    gControlVar1.searchAddress = SEARCH_ADDRESS_RESET;
    gControlVar1.randomAddress = RANDOM_ADDRESS_RESET;
    gControlVar1.writeEnableState = DISABLED;
    gControlVar1.limitError = LIMIT_ERROR_RESET;
    gControlVar1.fadeRunning = FADE_RUNNING_RESET;
    gControlVar1.resetState = RESET_STATE_RESET;
    gControlVar1.powerCycleSeen = POWER_CYCLE_SEEN_RESET;
    gControlVar1.gearGroups = GROUP_RESET;
    for(uint8_t i = 0; i < 16; i++){
        gControlVar1.sceneX[i] = MASK;
    }
    /* Update light value with reset value*/
    DL_Timer_setCaptureCompareValue(
            PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
    DL_Timer_startCounter(PWM_0_INST);
    /* Update timers to reset fade rate*/
    gControlVar1.dataTransferRegister0 = gControlVar1.fadeRate;
    DALI_setFadeRate();
}

void DALI_storeActualLevelDTR0(void){
    gControlVar1.dataTransferRegister0 = gControlVar1.actualLevel;
}

void DALI_setOperatingMode(void){
    gControlVar1.operatingMode = gControlVar1.dataTransferRegister0;
}

void DALI_resetMemoryBank(void){
    /* TEMPLATE FOR RESET MEMORY BANK
     * Resets the values for memory banks
     * If other memory banks are implemented, use the value in DTR0 to identify which
     * memory bank to reset(0 means all, a number means a specific non-zero memory bank)
     * */
    if(gControlVar1.dataTransferRegister0 == 0){
        /* Reset all memory banks excluding 0 */
    }
    else{
        /* check what value of DTR0 is and reset that memory bank*/
    }
}

void DALI_identifyDevice(void){
    /* TEMPLATE FOR IDENTIFY DEVICE COMMAND (COMMAND NUMBER: ) */
}

void DALI_setMaxLevel(void){
    /* if the minimum level is greater than what the max value will be set to, set max level to min level*/
    if(gControlVar1.minLevel >= gControlVar1.dataTransferRegister0){
        gControlVar1.maxLevel = gControlVar1.minLevel;
    }
    /* If the value being sent by command is MASK, then set to default max*/
    else if(gControlVar1.dataTransferRegister0 == MASK){
        gControlVar1.maxLevel = MAX_LEVEL_DEFAULT;
    }
    /* Otherwise set max level to value sent by command*/
    else{
        gControlVar1.maxLevel = gControlVar1.dataTransferRegister0;
    }
    /*
     * If the actual level is greater than the new max level value, then adjust target and actual level
     * to the new max level and adjust light output
     */
    if(gControlVar1.actualLevel > gControlVar1.maxLevel && gControlVar1.targetLevel <= 0xFE){
        gControlVar1.targetLevel = gControlVar1.maxLevel;
        gControlVar1.actualLevel = gControlVar1.targetLevel;
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_startCounter(PWM_0_INST);
    }
    else{
        /* do nothing */
    }
    gControlVar1.lastLightLevel = gControlVar1.targetLevel;
}


void DALI_setMinLevel(void){
    /* If the physical minimum level is greater than the value of new minimum level, set minLevel to PHM*/
    if(PHYS_MIN_LEVEL >= gControlVar1.dataTransferRegister0 && gControlVar1.dataTransferRegister0 >= 0){
        gControlVar1.minLevel = PHYS_MIN_LEVEL;
    }
    /* If the value of new minimum is greater than max level, min level should equal max level*/
    else if(gControlVar1.dataTransferRegister0 >= gControlVar1.maxLevel){
        gControlVar1.minLevel = gControlVar1.maxLevel;
    }
    /* Otherwise min level should equal new value*/
    else{
        gControlVar1.minLevel = gControlVar1.dataTransferRegister0;
    }
    /*
     * If actual level is less than new minimum level, then adjust actual and target to new minimum level
     * and adjust light output
     */
    if(gControlVar1.actualLevel < gControlVar1.minLevel && gControlVar1.targetLevel > 0){
        gControlVar1.targetLevel = gControlVar1.minLevel;
        gControlVar1.actualLevel = gControlVar1.targetLevel;
        DL_Timer_setCaptureCompareValue(
                PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
        DL_Timer_startCounter(PWM_0_INST);
    }
    else{
        /* do nothing */
    }
    gControlVar1.lastLightLevel = gControlVar1.targetLevel;
}

void DALI_setSystemFailureLevel(void){
    gControlVar1.systemFailureLevel = gControlVar1.dataTransferRegister0;
}

void DALI_setPowerOnLevel(void){
    gControlVar1.powerOnLevel = gControlVar1.dataTransferRegister0;
}

void DALI_setFadeTime(void){
    /* Set the fade time to value between 1-15, anything over 15 should default to 15*/
    if(gControlVar1.dataTransferRegister0 > 15){
        gControlVar1.dataTransferRegister0 = 15;
    }
    else{
        gControlVar1.dataTransferRegister0 = gControlVar1.dataTransferRegister0;
    }
    gControlVar1.fadeTime = gControlVar1.dataTransferRegister0;

}

void DALI_setFadeRate(void){
    /* Set the fade rate to value between 1-15
     * anything over 15 should default to 15
     * Anything over 0 should default to 1
     */
    if(gControlVar1.dataTransferRegister0 > 15){
        gControlVar1.dataTransferRegister0 = 15;
    }
    else if(gControlVar1.dataTransferRegister0 == 0){
        gControlVar1.dataTransferRegister0 = 1;
    }
    else{
        /* Do nothing */
    }
    /*
     * Adjust clock to utilize prescaler of 0 and set the load value of the timer
     */
    gControlVar1.fadeRate = gControlVar1.dataTransferRegister0;
    DL_Timer_ClockConfig config;
    DL_Timer_getClockConfig(TIMER_0_INST, &config);
    config.prescale = 0;
    DL_Timer_setClockConfig(TIMER_0_INST, &config);
    DL_Timer_setLoadValue(TIMER_0_INST, DALI_rateToTimeConversion());
}

void DALI_setExtendedFadeTime(void){
    /* TEMPLATE FOR SET EXTENDED FADE TIME */
}

void DALI_setScene(uint8_t * receivedData){
    uint8_t sceneNumber = receivedData[1] - 0x40;
    gControlVar1.sceneX[sceneNumber] = gControlVar1.dataTransferRegister0;

}

void DALI_removeFromScene(uint8_t * receivedData){
    uint8_t sceneNumber = receivedData[1] - 0x40;
    gControlVar1.sceneX[sceneNumber] = MASK;
}

void DALI_addToGroup(uint8_t * receivedData){
    uint8_t groupNumber = receivedData[1] - 0x60;
    gControlVar1.gearGroups |= (0x01 << groupNumber);
}

void DALI_removeGroup(uint8_t * receivedData){
    uint8_t groupNumber = receivedData[1] - 0x70;
    uint16_t removeMask = 0x00;
    for(uint8_t i = 0; i < 16; i++){
        if(i != groupNumber){
            removeMask |= (0x01 << i);
        }
        else{
            removeMask |= (0x00);
        }
    }
    gControlVar1.gearGroups &= removeMask;
}

void DALI_setShortAddress(void){
    /* If value sent is MASK, short address should be MASK(device is not initialized*/
    if(gControlVar1.dataTransferRegister0 == MASK){
        gControlVar1.shortAddress = MASK;
    }
    /*
     * otherwise if DTR0 has correctly formatted address value,
     * set to new value
     */
    else if((gControlVar1.dataTransferRegister0 & 0x81) == 0x01){
        gControlVar1.shortAddress = gControlVar1.dataTransferRegister0 >> 1;
    }
    /*
     * Otherwise maintain old value
     */
    else{
        /* Do nothing */
    }
}

void DALI_enableWriteMemory(void){
    gControlVar1.writeEnableState = ENABLED;
}


/* Query Commands */
void DALI_queryStatus(void){
    uint8_t answer = 0x00;
    /*
     * For each status bit, write its value to answer, and transmit answer
     */
    if(gControlVar1.controlGearFailure){
        answer += 0x01;
    }
    if(gControlVar1.lampFailure){
        answer += 0x02;
    }
    if(gControlVar1.lampOn){
        answer += 0x04;
    }
    if(gControlVar1.limitError){
        answer += 0x08;
    }
    if(gControlVar1.fadeRunning){
        answer += 0x10;
    }
    if(gControlVar1.resetState){
        answer += 0x20;
    }
    if(gControlVar1.shortAddress == MASK){
        answer += 0x40;
    }
    if(gControlVar1.powerCycleSeen){
        answer += 0x80;
    }
    gControlVar1.transmitData = (answer);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryControlGearPresent(void){
    gControlVar1.transmitData = (0xFF);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryControlGearFailure(void){
    if(gControlVar1.controlGearFailure){
        gControlVar1.transmitData = (0xFF);
    }
    else{
        gControlVar1.transmitData = (0x00);
    }
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryLampFailure(void){
    if(gControlVar1.lampFailure){
        gControlVar1.transmitData = (0xFF);
    }
    else{
        gControlVar1.transmitData = (0x00);
    }
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryLampPowerOn(void){
    if(gControlVar1.lampOn){
        gControlVar1.transmitData = (0xFF);
    }
    else{
        gControlVar1.transmitData = (0x00);
    }
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryLimitError(void){
    if(gControlVar1.limitError){
        gControlVar1.transmitData = (0xFF);
    }
    else{
        gControlVar1.transmitData = (0x00);
    }
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryResetState(void){
    if(gControlVar1.resetState){
        gControlVar1.transmitData = (0xFF);
    }
    else{
        gControlVar1.transmitData = (0x00);
    }
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryMissingShortAddress(void){
    if(gControlVar1.shortAddress == MASK){
        gControlVar1.transmitData = (0xFF);
    }
    else{
        gControlVar1.transmitData = (0x00);
    }
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryVersionNumber(void){
    gControlVar1.transmitData = (gControlVar1.versionNumber);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryContentDTR0(void){
    gControlVar1.transmitData = (gControlVar1.dataTransferRegister0);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryDeviceType(void){
    gControlVar1.transmitData = (207);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryNextDeviceType(void){
    /* TEMPLATE FOR QUERY NEXT DEVICE TYPE COMMAND(COMMAND NUM:) */
}

void DALI_queryPhysicalMinimum(void){
    gControlVar1.transmitData = (gControlVar1.PHM);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryPowerFailure(void){
    if(gControlVar1.powerCycleSeen){
        gControlVar1.transmitData = (0xFF);
    }
    else{
        gControlVar1.transmitData = (0x00);
    }
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryContentDTR1(void){
    gControlVar1.transmitData = (gControlVar1.dataTransferRegister1);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryContentDTR2(void){
    gControlVar1.transmitData = (gControlVar1.dataTransferRegister2);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryOperatingMode(void){
    gControlVar1.transmitData = (gControlVar1.operatingMode);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryLightSourceType(void){
    gControlVar1.transmitData = (6);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryActualLevel(void){
    gControlVar1.transmitData = (gControlVar1.actualLevel);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryMaxLevel(void){
    gControlVar1.transmitData = (gControlVar1.maxLevel);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryMinLevel(void){
    gControlVar1.transmitData = (gControlVar1.minLevel);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryPowerOnLevel(void){
    gControlVar1.transmitData = (gControlVar1.powerOnLevel);
    gControlVar1.transmitDataFlag = true;
}

void DALI_querySystemFailureLevel(void){
    gControlVar1.transmitData = (gControlVar1.systemFailureLevel);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryFadeRateTime(void){
    uint8_t answer = 0x00;
    answer += (gControlVar1.fadeRate);
    answer += (gControlVar1.fadeTime << 4);
    gControlVar1.transmitData = (answer);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryExtendedFadeTime(void){
    uint8_t answer = 0x00;
    answer += gControlVar1.extendedFadeTimeBase;
    answer += (gControlVar1.extendedFadeTimeMultiplier << 4);
    gControlVar1.transmitData = (answer);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryManufacturerMode(void){
    if(gControlVar1.operatingMode >= 0x80 && gControlVar1.operatingMode <= 0xFF){
        gControlVar1.transmitData = (0xFF);
    }
    else{
        gControlVar1.transmitData = (0x00);
    }
    gControlVar1.transmitDataFlag = true;
}

void DALI_querySceneLevel(uint8_t * receivedData){
    /* sceneX is opcode - 0xB0 */
    gControlVar1.transmitData = (gControlVar1.sceneX[receivedData[1] - 0xB0]);
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryGroup0_7(void){
    gControlVar1.transmitData = ((gControlVar1.gearGroups & 0x00FF));
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryGroups8_15(void){
    gControlVar1.transmitData = (((gControlVar1.gearGroups & 0xFF00) >> 8));
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryRandomAddressHigh(void){
    gControlVar1.transmitData = ((uint8_t)((gControlVar1.randomAddress & 0x00FF0000) >> 16));
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryRandomAddressMiddle(void){
    gControlVar1.transmitData = ((uint8_t)((gControlVar1.randomAddress & 0x0000FF00) >> 8));
    gControlVar1.transmitDataFlag = true;
}

void DALI_queryRandomAddressLow(void){
    gControlVar1.transmitData = ((uint8_t)(gControlVar1.randomAddress & 0x000000FF));
    gControlVar1.transmitDataFlag = true;
}

void DALI_readMemoryLocation(void){
    /* Use DTR1 to determine what memory bank and DTR0 for what content to get */
    if(gControlVar1.dataTransferRegister1 == 0){
        if(gControlVar1.dataTransferRegister0 < MEM_BANK_SIZE){
            gControlVar1.transmitData = gControlVar1.memoryBank0[gControlVar1.dataTransferRegister0];
            gControlVar1.transmitDataFlag = true;
        }
        else{
            gControlVar1.transmitData = 0x00;
            gControlVar1.transmitDataFlag = true;
        }
    }
}



/* Special Commands */
void DALI_initialize(void){
    /* Start initialization process if sent twice*/
    gInitCounter++;
    if(gInitCounter == 2){
        gControlVar1.initialisationState = ENABLED;
        gControlVar1.terminate = false;
        gInitCounter = 0;
        NVIC_EnableIRQ(TIMER_1_INST_INT_IRQN);
        DL_Timer_startCounter(TIMER_1_INST);
    }

}

void DALI_terminate(void){
    /* Terminate any special command or reset */
    gControlVar1.terminate = true;
}

void DALI_dtr0(uint8_t * receivedData){
    gControlVar1.dataTransferRegister0 = receivedData[1];
}

void DALI_randomiseAddress(void){
    /* Generate Random Address*/
    gRandCounter++;
    if(gControlVar1.initialisationState == ENABLED && gRandCounter == 2){
        DL_CRC_setSeed32(CRC, gInitCounter);
        DL_CRC_feedData32(CRC, gInitCounter);
        gControlVar1.randomAddress = (DL_CRC_getResult32(CRC) && 0x00FFFFFF);
        gRandCounter = 0;
    }
}

void DALI_compareAddress(void){
    /* Compare random and search address*/
    if(gControlVar1.initialisationState == ENABLED){
        if(gControlVar1.randomAddress <= gControlVar1.searchAddress){
            gControlVar1.transmitData = (0xFF);
        }
        else{
            gControlVar1.transmitData = (0x00);
        }
        gControlVar1.transmitDataFlag = true;
    }
}

void DALI_withdraw(void){
    /* Withdraw from any further initialization processes*/
    if(gControlVar1.initialisationState == ENABLED && gControlVar1.randomAddress == gControlVar1.searchAddress){
        gControlVar1.initialisationState = WITHDRAWN;
    }
}

void DALI_searchAddrH(uint8_t * receivedData){
    if(gControlVar1.initialisationState != DISABLED){
        uint32_t temp = receivedData[1];
        gControlVar1.searchAddress &= 0x0000FFFF;
        gControlVar1.searchAddress |= (temp << 16);
    }
}
void DALI_searchAddrM(uint8_t * receivedData){
    if(gControlVar1.initialisationState != DISABLED){
        uint32_t temp = receivedData[1];
        gControlVar1.searchAddress &= 0x00FF00FF;
        gControlVar1.searchAddress |= (temp << 8);
    }
}
void DALI_searchAddrL(uint8_t * receivedData){
    if(gControlVar1.initialisationState != DISABLED){
        uint32_t temp = receivedData[1];
        gControlVar1.searchAddress &= 0x00FFFF00;
        gControlVar1.searchAddress |= (temp);
    }
}

void DALI_programShortAddress(uint8_t * receivedData){
    /* Set short address during initialization process*/
    if(gControlVar1.initialisationState == ENABLED && gControlVar1.randomAddress == gControlVar1.searchAddress){
        if(receivedData[1] == MASK){
            gControlVar1.shortAddress = MASK;
        }
        else if((receivedData[1] & 0x81) == 0x01){
            gControlVar1.shortAddress = receivedData[1] >> 1;
        }
        else{
            /* Do nothing */
        }
    }
}

void DALI_verifyShortAddress(uint8_t * receivedData){
    /* Verify short address during initialization process*/
    if(gControlVar1.initialisationState != DISABLED){
        if(((receivedData[1] & 0x81) == 0x01) && gControlVar1.shortAddress == receivedData[1] >> 1){
            gControlVar1.transmitData = (0xFF);
            gControlVar1.transmitDataFlag = true;
        }
    }
}

void DALI_queryShortAddress(void){
    if(gControlVar1.initialisationState != DISABLED && gControlVar1.randomAddress == gControlVar1.searchAddress){
        gControlVar1.transmitData = (gControlVar1.shortAddress << 1) + 1;
        gControlVar1.transmitDataFlag = true;
    }
}

void DALI_enableDeviceType(uint8_t * receivedData){
    gControlVar1.deviceType = receivedData[1];
    DALI_LED_enableDeviceType();

}

void DALI_dtr1(uint8_t * receivedData){
    gControlVar1.dataTransferRegister1 = receivedData[1];
}

void DALI_dtr2(uint8_t * receivedData){
    gControlVar1.dataTransferRegister2 = receivedData[1];
}

void DALI_writeMemoryLocation(uint8_t * receivedData){
    /* TEMPLATE FOR WRITE MEMORY LOCATION COMMAND(COMMAND NUM:)*/
    if(gControlVar1.writeEnableState){
        if(gControlVar1.dataTransferRegister0 < 0xFF && gControlVar1.dataTransferRegister0 > 0x80 && gControlVar1.dataTransferRegister1 == 0){
            gControlVar1.memoryBank0[gControlVar1.dataTransferRegister0] = receivedData[1];
            gControlVar1.transmitData = receivedData[1];
        }
        else{
            gControlVar1.transmitData = 0x00;
            gControlVar1.transmitDataFlag = true;
        }
    }
}

void DALI_writeMemoryLocationNoReply(uint8_t * receivedData){
    /* TEMPLATE FOR WRITE MEMORY LOCATION NO REPLY COMMAND(COMMAND NUM:)*/
    if(gControlVar1.writeEnableState){
        if(gControlVar1.dataTransferRegister0 < 0xFF && gControlVar1.dataTransferRegister0 > 0x80 && gControlVar1.dataTransferRegister1 == 0){
            gControlVar1.memoryBank0[gControlVar1.dataTransferRegister0] = receivedData[1];
        }
    }
}




void TIMER_0_INST_IRQHandler(){
    switch(DL_Timer_getPendingInterrupt(TIMER_0_INST)){
    case DL_TIMER_IIDX_ZERO:
        gCounter++;
        /* Check if fade is running*/
        if(gControlVar1.fadeRunning){
            /* If actual level is not equal to target level or min level */
            if(gControlVar1.actualLevel > gControlVar1.targetLevel && gControlVar1.actualLevel > gControlVar1.minLevel){
                /* this only should run in a down command */
                if(gCounter % 2 == 1 && gCounter < gNumLoops){
                    gControlVar1.actualLevel--;
                    DL_Timer_setCaptureCompareValue(
                            PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
                }
            }
            /* If actual level is not equal to target level or max level */
            else if(gControlVar1.actualLevel < gControlVar1.targetLevel && gControlVar1.actualLevel < gControlVar1.maxLevel){
                /* this only should run in an up command */

                if(gCounter % 2 == 1 && gCounter < gNumLoops){
                    gControlVar1.actualLevel++;
                    DL_Timer_setCaptureCompareValue(
                            PWM_0_INST, (uint32_t)((double)DALI_LightOutputConversion() / 100.0 * 1000.0), DL_TIMER_CC_0_INDEX);
                }
            }
            else{
                /* Do Nothing */
            }
        }
        /* Reset for next fade command */
        if(gCounter >= gNumLoops){
            gControlVar1.fadeRunning = false;
            gCounter = 0;
            gNumLoops = 0;
            DL_Timer_stopCounter(TIMER_0_INST);
        }
        break;
    default:
        break;
    }
}


void TIMER_1_INST_IRQHandler(){
    switch(DL_Timer_getPendingInterrupt(TIMER_1_INST)){
    case DL_TIMER_IIDX_ZERO:
        if(gControlVar1.terminate || gInitCounter == 900000 || gControlVar1.initialisationState != ENABLED){
            /* End initialization if terminate or 15 minutes have passed or initialization has ended */
            gControlVar1.terminate = false;
            DL_Timer_stopCounter(TIMER_1_INST);
        }
        else{
            gInitCounter++;

        }
    default:
        break;
    }
}

void TIMER_2_INST_IRQHandler(){
    switch(DL_Timer_getPendingInterrupt(TIMER_2_INST)){
    case DL_TIMER_IIDX_ZERO:
        if(gControlVar1.terminate){
            /* End reset process via terminate */
            gControlVar1.terminate = false;
            DL_Timer_stopCounter(TIMER_2_INST);
        }
        else if(gResetCounter == 150){
            /* End reset after 300 ms expries*/
            gControlVar1.resetState = false;
            DL_Timer_stopCounter(TIMER_2_INST);
        }
        else{
            gResetCounter++;

        }
    default:
        break;
    }

}
