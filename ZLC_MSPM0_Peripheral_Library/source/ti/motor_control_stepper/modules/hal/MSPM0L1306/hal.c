/*
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
 */
#include "hal.h"

/**
 * @brief Array for storing the SPI instances
 */
HAL_SPI spi[HAL_SPI_CHANNEL_MAX];

/**
 * @brief Array for storing chip selects for spi peripheral
 */
DL_SPI_CHIP_SELECT  spiCS[HAL_SPI_CS_MAX];

/**
 * @brief Array for storing the DAC instances
 */
HAL_DAC dac[HAL_DAC_CHANNEL_MAX];

/**
 * @brief Array for storing the ADC instances
 */
HAL_ADC adc[HAL_ADC_CHANNEL_MAX];

/**
 * @brief Array for storing the PWM instances
 */
HAL_PWM pwm[HAL_PWM_CHANNEL_MAX];

/**
 * @brief Array for storing the Timer instances
 */
HAL_TIM tim[HAL_TIM_CHANNEL_MAX];

/**
 * @brief Array for storing the input GPIO pin instances
 */
HAL_GPIO gpioIN[HAL_GPIO_IN_PIN_MAX];

/**
 * @brief Array for storing the ouput GPIO pin instances
 */
HAL_GPIO gpioOUT[HAL_GPIO_OUT_PIN_MAX];

/**
 * @brief Scale factor for converting ADC data to voltage
 */
_iq15 adcSf;

void HAL_init(void)
{
    /* Set the SPI array */
    spi[HAL_SPI_CHANNEL_0].inst             = (SPI_Regs *)SPI0_BASE;
    
    spiCS[HAL_SPI_CS_0] = DL_SPI_CHIP_SELECT_0;
    spiCS[HAL_SPI_CS_1] = DL_SPI_CHIP_SELECT_1;
    spiCS[HAL_SPI_CS_2] = DL_SPI_CHIP_SELECT_2;
    spiCS[HAL_SPI_CS_3] = DL_SPI_CHIP_SELECT_3;

    /* Set the DAC array */
    dac[HAL_DAC_CHANNEL_0].compBase         = (COMP_Regs *)COMP0_BASE;
    HAL_setDacRefVoltage(HAL_DAC_CHANNEL_0, _IQ15(HAL_DAC_DEFAULT_REF_VOLTAGE));

    /* Set the ADC array */
    for(int x = 0;x < HAL_ADC_CHANNEL_MAX ;x++)
    {
        adc[x].refVoltage = 0;
        adc[x].value = 0;
    }
#ifdef GENERIC_ADC_0_INST
    adc[HAL_ADC_CHANNEL_0].inst             = (ADC12_Regs *)GENERIC_ADC_0_INST;
    adc[HAL_ADC_CHANNEL_0].irqn             = GENERIC_ADC_0_INST_INT_IRQN;
    adc[HAL_ADC_CHANNEL_0].memIDX           = GENERIC_ADC_0_ADCMEM_0;
    adc[HAL_ADC_CHANNEL_0].endOfSeq         = DL_ADC12_IIDX_MEM1_RESULT_LOADED;
    HAL_setADCRefVoltage(HAL_ADC_CHANNEL_0, _IQ15(HAL_ADC_DEFAULT_REF_VOLTAGE));
    
    adc[HAL_ADC_CHANNEL_1].inst             = (ADC12_Regs *)GENERIC_ADC_0_INST;
    adc[HAL_ADC_CHANNEL_1].irqn             = GENERIC_ADC_0_INST_INT_IRQN;
    adc[HAL_ADC_CHANNEL_1].memIDX           = GENERIC_ADC_0_ADCMEM_1;
    adc[HAL_ADC_CHANNEL_1].endOfSeq         = DL_ADC12_IIDX_MEM1_RESULT_LOADED;
    HAL_setADCRefVoltage(HAL_ADC_CHANNEL_1, _IQ15(HAL_ADC_DEFAULT_REF_VOLTAGE));

    /* Set the ADC scaling factor*/
    HAL_setADCSf();
#endif

    /* Set the PWM array */
#ifdef GENERIC_PWM_CHANNEL_0_INST
    pwm[HAL_PWM_CHANNEL_0].inst         = GENERIC_PWM_CHANNEL_0_INST;
    pwm[HAL_PWM_CHANNEL_0].irqn         = GENERIC_PWM_CHANNEL_0_INST_INT_IRQN;
    pwm[HAL_PWM_CHANNEL_0].CCIndex      = DL_TIMER_CC_0_INDEX;
#endif

#ifdef GENERIC_PWM_CHANNEL_1_INST
    pwm[HAL_PWM_CHANNEL_1].inst         = GENERIC_PWM_CHANNEL_1_INST;
    pwm[HAL_PWM_CHANNEL_1].irqn         = GENERIC_PWM_CHANNEL_1_INST_INT_IRQN;
    pwm[HAL_PWM_CHANNEL_1].CCIndex      = DL_TIMER_CC_0_INDEX;
#endif

    /* Set all PWM channels to 0% dutycycle */
    for(int x = 0;x < HAL_PWM_CHANNEL_MAX;x++)
    {
        HA_setPWMDutyCycle(x,0);
    }

    /* Set the TIM array*/
#ifdef GENERIC_TIM_CHANNEL_0_INST
    tim[HAL_TIM_CHANNEL_0].inst         = GENERIC_TIM_CHANNEL_0_INST;
    tim[HAL_TIM_CHANNEL_0].irqn         = GENERIC_TIM_CHANNEL_0_INST_INT_IRQN;
#endif

#ifdef GENERIC_TIM_CHANNEL_1_INST
    tim[HAL_TIM_CHANNEL_1].inst         = GENERIC_TIM_CHANNEL_1_INST;
    tim[HAL_TIM_CHANNEL_1].irqn         = GENERIC_TIM_CHANNEL_1_INST_INT_IRQN;
#endif

    /* Set the GPIO input array */
#ifdef GENERIC_GPIO_IN_PINI_0_PIN
    gpioIN[HAL_GPIO_IN_PIN_0].iomux     = GENERIC_GPIO_IN_PINI_0_IOMUX;
    gpioIN[HAL_GPIO_IN_PIN_0].port      = GENERIC_GPIO_IN_PORT;
    gpioIN[HAL_GPIO_IN_PIN_0].pin       = GENERIC_GPIO_IN_PINI_0_PIN;
#endif

    /* Set the GPIO output array */

#ifdef GENERIC_GPIO_OUT_PINO_0_PIN
    gpioOUT[HAL_GPIO_OUT_PIN_0].iomux   = GENERIC_GPIO_OUT_PINO_0_IOMUX;
    gpioOUT[HAL_GPIO_OUT_PIN_0].port    = GENERIC_GPIO_OUT_PORT;
    gpioOUT[HAL_GPIO_OUT_PIN_0].pin     = GENERIC_GPIO_OUT_PINO_0_PIN;
#endif

#ifdef GENERIC_GPIO_OUT_PINO_1_PIN
    gpioOUT[HAL_GPIO_OUT_PIN_1].iomux   = GENERIC_GPIO_OUT_PINO_1_IOMUX;
    gpioOUT[HAL_GPIO_OUT_PIN_1].port    = GENERIC_GPIO_OUT_PORT;
    gpioOUT[HAL_GPIO_OUT_PIN_1].pin     = GENERIC_GPIO_OUT_PINO_1_PIN;    
#endif

#ifdef GENERIC_GPIO_OUT_PINO_2_PIN
    gpioOUT[HAL_GPIO_OUT_PIN_2].iomux   = GENERIC_GPIO_OUT_PINO_2_IOMUX;
    gpioOUT[HAL_GPIO_OUT_PIN_2].port    = GENERIC_GPIO_OUT_PORT;
    gpioOUT[HAL_GPIO_OUT_PIN_2].pin     = GENERIC_GPIO_OUT_PINO_2_PIN;    
#endif

#ifdef GENERIC_GPIO_OUT_PINO_3_PIN
    gpioOUT[HAL_GPIO_OUT_PIN_3].iomux   = GENERIC_GPIO_OUT_PINO_3_IOMUX;
    gpioOUT[HAL_GPIO_OUT_PIN_3].port    = GENERIC_GPIO_OUT_PORT;
    gpioOUT[HAL_GPIO_OUT_PIN_3].pin     = GENERIC_GPIO_OUT_PINO_3_PIN;    
#endif

#ifdef GENERIC_GPIO_OUT_PINO_4_PIN
    gpioOUT[HAL_GPIO_OUT_PIN_4].iomux   = GENERIC_GPIO_OUT_PINO_4_IOMUX;
    gpioOUT[HAL_GPIO_OUT_PIN_4].port    = GENERIC_GPIO_OUT_PORT;
    gpioOUT[HAL_GPIO_OUT_PIN_4].pin     = GENERIC_GPIO_OUT_PINO_4_PIN;    
#endif

#ifdef GENERIC_GPIO_OUT_PINO_5_PIN
    gpioOUT[HAL_GPIO_OUT_PIN_5].iomux   = GENERIC_GPIO_OUT_PINO_5_IOMUX;
    gpioOUT[HAL_GPIO_OUT_PIN_5].port    = GENERIC_GPIO_OUT_PORT;
    gpioOUT[HAL_GPIO_OUT_PIN_5].pin     = GENERIC_GPIO_OUT_PINO_5_PIN;    
#endif

#ifdef GENERIC_GPIO_OUT_PINO_6_PIN
    gpioOUT[HAL_GPIO_OUT_PIN_6].iomux   = GENERIC_GPIO_OUT_PINO_6_IOMUX;
    gpioOUT[HAL_GPIO_OUT_PIN_6].port    = GENERIC_GPIO_OUT_PORT;
    gpioOUT[HAL_GPIO_OUT_PIN_6].pin     = GENERIC_GPIO_OUT_PINO_6_PIN;    
#endif

#ifdef GENERIC_GPIO_OUT_PINO_7_PIN
    gpioOUT[HAL_GPIO_OUT_PIN_7].iomux   = GENERIC_GPIO_OUT_PINO_7_IOMUX;
    gpioOUT[HAL_GPIO_OUT_PIN_7].port    = GENERIC_GPIO_OUT_PORT;
    gpioOUT[HAL_GPIO_OUT_PIN_7].pin     = GENERIC_GPIO_OUT_PINO_7_PIN;    
#endif

#ifdef GENERIC_GPIO_OUT_PINO_8_PIN
    gpioOUT[HAL_GPIO_OUT_PIN_8].iomux   = GENERIC_GPIO_OUT_PINO_8_IOMUX;
    gpioOUT[HAL_GPIO_OUT_PIN_8].port    = GENERIC_GPIO_OUT_PORT;
    gpioOUT[HAL_GPIO_OUT_PIN_8].pin     = GENERIC_GPIO_OUT_PINO_8_PIN;    
#endif

#ifdef GENERIC_GPIO_OUT_PINO_9_PIN
    gpioOUT[HAL_GPIO_OUT_PIN_9].iomux   = GENERIC_GPIO_OUT_PINO_9_IOMUX;
    gpioOUT[HAL_GPIO_OUT_PIN_9].port    = GENERIC_GPIO_OUT_PORT;
    gpioOUT[HAL_GPIO_OUT_PIN_9].pin     = GENERIC_GPIO_OUT_PINO_9_PIN;    
#endif

}

void HAL_setADCRefVoltage(HAL_ADC_CHANNEL adcChan, _iq15 value)
{
    adc[adcChan].refVoltage = value;
}

void HAL_setDacRefVoltage(HAL_DAC_CHANNEL dacChan, _iq15 value)
{
    dac[dacChan].refVoltage = value;
}

void HAL_setADCSf(void)
{
    adcSf = _IQ15div(_IQ15(1), _IQ15(HAL_ADC_MAX_VALUE));
}

void HAL_checkAndEnableIRQ(IRQn_Type irqn)
{
    if(!NVIC_GetEnableIRQ(irqn))
    {
        NVIC_EnableIRQ(irqn);
    }
}

void HAL_enableADCInterrupt(HAL_ADC_CHANNEL adcChan)
{
    HAL_checkAndEnableIRQ(adc[adcChan].irqn);
}

void HAL_disableADCInterrupt(HAL_ADC_CHANNEL adcChan)
{
    NVIC_DisableIRQ(adc[adcChan].irqn);
}

void HAL_enableTIMInterrupt(HAL_TIM_CHANNEL timChan)
{
    HAL_checkAndEnableIRQ(tim[timChan].irqn);
}

void HAL_disableTIMInterrupts(HAL_TIM_CHANNEL timChan)
{
    NVIC_DisableIRQ(tim[timChan].irqn);
}

void HAL_enablePWMInterrupt(HAL_PWM_CHANNEL pwmChan)
{
    HAL_checkAndEnableIRQ(pwm[pwmChan].irqn);
}

void HAL_disablePWMInterrupts(HAL_PWM_CHANNEL pwmChan)
{
    NVIC_DisableIRQ(pwm[pwmChan].irqn);
}

HAL_GPIO_VALUE HAL_readGPIOVal(HAL_GPIO_IN_PIN gpioPin)
{
    return DL_GPIO_readPins(gpioIN[gpioPin].port,
                            gpioIN[gpioPin].pin)?
                            HAL_GPIO_VALUE_HIGH : HAL_GPIO_VALUE_LOW;
}

void HAL_configurePin(
            GPIO_Regs *port, IOMUX_PINCM iomux, uint32_t pin, HAL_PIN_MODE mode)
{
    if (mode == HAL_PIN_MODE_OUTPUT_LOW)
    {
        DL_GPIO_clearPins(port, pin);
        DL_GPIO_initDigitalOutput(iomux);
        DL_GPIO_enableOutput(port, pin);
    }
    else if(mode == HAL_PIN_MODE_OUTPUT_HIGH)
    {
        DL_GPIO_setPins(port, pin);
        DL_GPIO_initDigitalOutput(iomux);
        DL_GPIO_enableOutput(port, pin);
    }
    else if (mode == HAL_PIN_MODE_INPUT_PU)
    {
        DL_GPIO_disableOutput(port, pin);
        DL_GPIO_initDigitalInputFeatures(iomux,
		                DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		                DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    }
    else if (mode == HAL_PIN_MODE_INPUT_PD)
    {
        DL_GPIO_disableOutput(port, pin);
        DL_GPIO_initDigitalInputFeatures(iomux,
		                DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		                DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    }
    else if (mode == HAL_PIN_MODE_INPUT_HZ)
    {
        DL_GPIO_disableOutput(port, pin);
        DL_GPIO_initDigitalInputFeatures(iomux,
		                DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_NONE,
		                DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    }
    else
    {
        /* This is expected to be empty */
    }
}

void HAL_configureGPIOOUTPin(HAL_GPIO_OUT_PIN gpioPin, HAL_PIN_MODE mode)
{
    HAL_configurePin(gpioOUT[gpioPin].port, gpioOUT[gpioPin].iomux,
                     gpioOUT[gpioPin].pin, mode);
}

void HAL_configureGPIOINPin(HAL_GPIO_IN_PIN gpioPin, HAL_PIN_MODE mode)
{
    HAL_configurePin(gpioIN[gpioPin].port, gpioIN[gpioPin].iomux,
                     gpioIN[gpioPin].pin, mode);
}

void HAL_setDACVoltage(HAL_DAC_CHANNEL dacChan, _iq15 volt)
{
    uint8_t DAC_OUT = _IQ15int(_IQ15mpy(volt,
                 _IQ15div(_IQ15(HAL_DAC_MAX_VALUE), dac[dacChan].refVoltage)));
    DL_COMP_setDACCode0(dac[dacChan].compBase, DAC_OUT);
}

uint32_t HAL_getPWMLoadValue(HAL_PWM_CHANNEL pwmChan)
{
    uint32_t loadVal = DL_TimerG_getLoadValue(pwm[pwmChan].inst);
    return  loadVal;
}

void HAL_startPWMCounter(HAL_PWM_CHANNEL pwmChan)
{
    DL_TimerG_startCounter(pwm[pwmChan].inst);
}

void HAL_stopPWMCounter(HAL_PWM_CHANNEL pwmChan)
{
    DL_TimerG_stopCounter(pwm[pwmChan].inst);
}

void HAL_startTIMCounter(HAL_TIM_CHANNEL timChan)
{
    DL_TimerG_startCounter(tim[timChan].inst);
}

void HAL_stopTIMCounter(HAL_TIM_CHANNEL timChan)
{
    DL_TimerG_stopCounter(tim[timChan].inst);
}

bool HAL_isPWMCounterRunning(HAL_PWM_CHANNEL pwmChan)
{
    return DL_TimerG_isRunning(pwm[pwmChan].inst);
}

bool HAL_isTIMCounterRunning(HAL_TIM_CHANNEL timChan)
{
    return DL_TimerG_isRunning(tim[timChan].inst);
}

void HA_setPWMDutyCycle(HAL_PWM_CHANNEL pwmChan,uint8_t dutycycle)
{
    GPTIMER_Regs * timerInst;
    uint32_t loadVal, ccVal;

    timerInst = pwm[pwmChan].inst;
    loadVal = DL_TimerG_getLoadValue(timerInst);

    /* Duty Cycle is represented as a whole number to avoid floating point
     * calculation
     */
    ccVal = (100 - ((uint32_t)dutycycle))*loadVal/100;

    DL_TimerG_setCaptureCompareValue(timerInst, ccVal, pwm[pwmChan].CCIndex);
}

void HAL_setPWMFreq(HAL_PWM_CHANNEL pwmChan, uint32_t freq)
{
    HAL_setFreq(pwm[pwmChan].inst, freq);
}

void HAL_setTIMFreq(HAL_TIM_CHANNEL timChan, uint32_t freq)
{
    HAL_setFreq(tim[timChan].inst, freq);
}

void HAL_setPWMLoadVal(HAL_PWM_CHANNEL pwmChan, uint32_t loadValue)
{
    GPTIMER_Regs * timerInst = pwm[pwmChan].inst; 
    HAL_setLoadVal(timerInst, loadValue);
}

void HAL_setTIMLoadVal(HAL_TIM_CHANNEL timChan, uint32_t loadValue)
{
    GPTIMER_Regs * timerInst = tim[timChan].inst; 
    HAL_setLoadVal(timerInst, loadValue);
}

void HAL_setFreq(GPTIMER_Regs * timerInst, uint32_t freq)
{
    DL_Timer_ClockConfig clockConfig;
    DL_Timer_getClockConfig(timerInst, &clockConfig);
    uint32_t loadValue = HAL_TIM_PERIPHERAL_CLOCK_SOURCE/((uint8_t)clockConfig.divideRatio + 1);
    loadValue /= freq;
    uint32_t psc = loadValue/65535;
    if(psc>256)
    {
        psc = 255;
    }
    loadValue /= (psc+1);
    clockConfig.prescale = (uint8_t)psc;
    DL_Timer_setClockConfig(timerInst, &clockConfig);
    HAL_setLoadVal(timerInst, loadValue);
}

void HAL_setLoadVal(GPTIMER_Regs * timerInst, uint32_t loadValue)
{
    /*
    * The clock is disable before changing the load value for safety
    */
    DL_Timer_disableClock(timerInst);
    DL_Timer_setLoadValue(timerInst, loadValue);
    DL_Timer_enableClock(timerInst);
}

uint16_t HAL_getADCData(HAL_ADC_CHANNEL adcChan)
{
    uint16_t data = DL_ADC12_getMemResult(
                                    adc[adcChan].inst, adc[adcChan].memIDX);
    return data;
}

_iq15 HAL_getADCResult(HAL_ADC_CHANNEL adcChan)
{
    _iq15 ret = _IQ15mpy(_IQ15mpy(_IQ15(adc[adcChan].value),adc[adcChan].refVoltage), adcSf);
    return ret;
}

DL_ADC12_IIDX HAL_processADCIRQ(ADC12_Regs *adcInst)
{
    DL_ADC12_IIDX pendIrq = DL_ADC12_getPendingInterrupt(adcInst);
    for(int x = 0;x < HAL_ADC_CHANNEL_MAX;x++)
    {
        if(adcInst == adc[x].inst && pendIrq ==  adc[x].endOfSeq)
        {
            adc[x].value = HAL_getADCData(x);
        }
    }
    return pendIrq;
}

void HAL_delayMilliSeconds(uint32_t num_ms)
{
    if(num_ms == 0)
    {
        return;
    }
    DL_Common_delayCycles(num_ms*HAL_CYCLES_TO_1_MS_DELAY);
}

void HAL_configurePWMPin(HAL_PWM_CHANNEL pwmChan, HAL_PWM_CHANNEL_MODE pwmMode)
{
    GPTIMER_Regs *gptimer = pwm[pwmChan].inst;
    DL_TIMER_CC_INDEX ccIndex = pwm[pwmChan].CCIndex;
    DL_Common_updateReg(&gptimer->COUNTERREGS.CCACT_01[ccIndex], pwmMode,
                        GPTIMER_CCACT_01_SWFRCACT_MASK);
}

bool HAL_isSPIRxFifoEmpty(HAL_SPI_CHANNEL spiPeripheral)
{
    return DL_SPI_isRXFIFOEmpty(spi[spiPeripheral].inst);
}

uint16_t HAL_receiveSPIData16(HAL_SPI_CHANNEL spiPeripheral, HAL_SPI_CS cs)
{
    DL_SPI_setChipSelect(spi[spiPeripheral].inst, spiCS[cs]);
    return DL_SPI_receiveData16(spi[spiPeripheral].inst);
}

void HAL_transmitSPIData16(
                    HAL_SPI_CHANNEL spiPeripheral, HAL_SPI_CS cs, uint16_t data)
{
    DL_SPI_setChipSelect(spi[spiPeripheral].inst, spiCS[cs]);
    DL_SPI_transmitData16(spi[spiPeripheral].inst, data);
}

bool HAL_isSPIBusy(HAL_SPI_CHANNEL spiPeripheral)
{
    return DL_SPI_isBusy(spi[spiPeripheral].inst);
}
