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

//*****************************************************************************
// the includes
//*****************************************************************************
#include "hal.h"

//*****************************************************************************
//defines
//*****************************************************************************
/**
 * @brief Array for storing the output GPIO pin instances
 */
HAL_GPIO_Instance    gpioOutputPin[HAL_GPIO_OUT_MAX];

/**
 * @brief Array for storing the input GPIO pin instances
 */
HAL_GPIO_Instance    gpioInputPin[HAL_GPIO_IN_MAX];

/**
 * @brief Array for storing the SPI instances
 */
SPI_Regs *           SPIChannel[HAL_SPI_CHAN_MAX];

/**
 * @brief Array for storing the chip selects for SPI peripheral
 */
DL_SPI_CHIP_SELECT   SPICS[HAL_SPI_CS_MAX];

/**
 * @brief Array for storing the ADC instances
 */
HAL_ADC_instance     ADCChannel[HAL_ADC_CHAN_MAX];

/**
 * @brief Array for storing the PWM instances
 */
HAL_Timer_Instance   PWMBase[HAL_PWM_MAX];

/**
 * @brief Array to store the capture instances
 */
HAL_Timer_Instance   inputCapture[HAL_CAPTURE_TIMER_MAX];

/**
 * @brief Array to store the fault instances
 */
HAL_fault_Instance   faultInput[HAL_FAULT_INPUT_MAX];

/**
 * @brief Variable for tracking which ADC channels require sampling
 */
bool gFirstADCPass = true;

/**
 * @brief  Initializes the hal module
 */
void HAL_init()
{
    /* Define GPIO output array */
#ifdef GEN_GPIO_OUT_PINO_01_PIN
    gpioOutputPin[HAL_GPIO_OUT_01].iomux  = GEN_GPIO_OUT_PINO_01_IOMUX;
    gpioOutputPin[HAL_GPIO_OUT_01].port   = GEN_GPIO_OUT_PORT;
    gpioOutputPin[HAL_GPIO_OUT_01].pin    = GEN_GPIO_OUT_PINO_01_PIN;
#endif

#ifdef GEN_GPIO_OUT_PINO_02_PIN
    gpioOutputPin[HAL_GPIO_OUT_02].iomux  = GEN_GPIO_OUT_PINO_02_IOMUX;
    gpioOutputPin[HAL_GPIO_OUT_02].port   = GEN_GPIO_OUT_PORT;
    gpioOutputPin[HAL_GPIO_OUT_02].pin    = GEN_GPIO_OUT_PINO_02_PIN;
#endif

#ifdef GEN_GPIO_IN_PINI_01_PIN
    gpioInputPin[HAL_GPIO_IN_01].iomux    = GEN_GPIO_IN_PINI_01_IOMUX;
    gpioInputPin[HAL_GPIO_IN_01].port     = GEN_GPIO_IN_PORT;
    gpioInputPin[HAL_GPIO_IN_01].pin      = GEN_GPIO_IN_PINI_01_PIN;
    gpioInputPin[HAL_GPIO_IN_01].IRQn     = GEN_GPIO_IN_INT_IRQN;
#endif

#ifdef GEN_GPIO_IN_PINI_02_PIN
    gpioInputPin[HAL_GPIO_IN_02].iomux    = GEN_GPIO_IN_PINI_02_IOMUX;
    gpioInputPin[HAL_GPIO_IN_02].port     = GEN_GPIO_IN_PORT;
    gpioInputPin[HAL_GPIO_IN_02].pin      = GEN_GPIO_IN_PINI_02_PIN;
    gpioInputPin[HAL_GPIO_IN_02].IRQn     = GEN_GPIO_IN_INT_IRQN;
#endif

#ifdef GEN_GPIO_IN_PINI_03_PIN
    gpioInputPin[HAL_GPIO_IN_03].iomux    = GEN_GPIO_IN_PINI_03_IOMUX;
    gpioInputPin[HAL_GPIO_IN_03].port     = GEN_GPIO_IN_PORT;
    gpioInputPin[HAL_GPIO_IN_03].pin      = GEN_GPIO_IN_PINI_03_PIN;
    gpioInputPin[HAL_GPIO_IN_03].IRQn     = GEN_GPIO_IN_INT_IRQN;
#endif

    /* Define SPI instances */
#ifdef GEN_SPI_1_INST
    SPIChannel[HAL_SPI_CHAN_0] = GEN_SPI_1_INST;

    SPICS[HAL_SPI_CS_0] = DL_SPI_CHIP_SELECT_0;
    SPICS[HAL_SPI_CS_1] = DL_SPI_CHIP_SELECT_1;
    SPICS[HAL_SPI_CS_2] = DL_SPI_CHIP_SELECT_2;
    SPICS[HAL_SPI_CS_3] = DL_SPI_CHIP_SELECT_3;
#endif

    /* Define ADC instances */
    ADCChannel[HAL_ADC_CHAN_0].inst     = GEN_ADC_CHAN_0_INST;
    ADCChannel[HAL_ADC_CHAN_0].IRQn     = GEN_ADC_CHAN_0_INST_INT_IRQN;
    ADCChannel[HAL_ADC_CHAN_0].endOfSeq = HAL_ADC_IIDX_MEM1_RESULT_LOADED;
    ADCChannel[HAL_ADC_CHAN_0].memIdx   = GEN_ADC_CHAN_0_ADCMEM_0;

    ADCChannel[HAL_ADC_CHAN_1].inst     = GEN_ADC_CHAN_0_INST;
    ADCChannel[HAL_ADC_CHAN_1].IRQn     = GEN_ADC_CHAN_0_INST_INT_IRQN;
    ADCChannel[HAL_ADC_CHAN_1].endOfSeq = HAL_ADC_IIDX_MEM1_RESULT_LOADED;
    ADCChannel[HAL_ADC_CHAN_1].memIdx   = GEN_ADC_CHAN_0_ADCMEM_1;

    /* Set ADC reference to default value */
    for(int x=0; x<HAL_ADC_CHAN_MAX; x++)
    {
        ADCChannel[x].refVoltagemV = HAL_VDDA_REFVOLTAGE;
        ADCChannel[x].value = 0;
    }

    /* Define Motor Phase PWM Timers */
    PWMBase[HAL_PWM_01].gptimer     = PWM_0_INST;           // INHA
    PWMBase[HAL_PWM_01].ccIndex     = GPIO_PWM_0_C0_IDX;
    PWMBase[HAL_PWM_01].ccCompIndex = GPIO_PWM_0_C1_IDX;
    PWMBase[HAL_PWM_01].deadBand    = 10;
    PWMBase[HAL_PWM_01].IRQn        = PWM_0_INST_INT_IRQN;

    PWMBase[HAL_PWM_02].gptimer     = PWM_1_INST;           // INHB
    PWMBase[HAL_PWM_02].ccIndex     = GPIO_PWM_1_C0_IDX;
    PWMBase[HAL_PWM_02].ccCompIndex = GPIO_PWM_1_C1_IDX;
    PWMBase[HAL_PWM_02].deadBand    = 10;
    PWMBase[HAL_PWM_02].IRQn        = PWM_1_INST_INT_IRQN;

    PWMBase[HAL_PWM_03].gptimer     = PWM_2_INST;           // INHC
    PWMBase[HAL_PWM_03].ccIndex     = GPIO_PWM_2_C0_IDX;
    PWMBase[HAL_PWM_03].ccCompIndex = GPIO_PWM_2_C1_IDX;
    PWMBase[HAL_PWM_03].deadBand    = 10;
    PWMBase[HAL_PWM_03].IRQn        = PWM_2_INST_INT_IRQN;

    inputCapture[HAL_CAPTURE_TIMER_01].gptimer   = CAPTURE_0_INST;
    inputCapture[HAL_CAPTURE_TIMER_01].ccIndex   = DL_TIMER_CC_0_INDEX;
    inputCapture[HAL_CAPTURE_TIMER_01].IRQn      = CAPTURE_0_INST_INT_IRQN;

    faultInput[HAL_FAULT_INPUT_1].port    = GEN_GPIO_IN_PORT;
    faultInput[HAL_FAULT_INPUT_1].pin     = GEN_GPIO_IN_FAULT_1_PIN;
}

/**
 * @brief     Reads a GPIOpin
 * @param[in] pin   GPIOpin to be read
 * @return    Status of pin
 */
bool HAL_readGPIOPin(HAL_GPIO_IN pin)
{
    return(DL_GPIO_readPins(gpioInputPin[pin].port, gpioInputPin[pin].pin));
}

/**
 * @brief Write to GPIOpin
 * @param[in] pin GPIOpin to write
 * @param[in] value Value to be written
 */
void HAL_writeGPIOPin(HAL_GPIO_OUT pin, HAL_GPIO_STATE value)
{
    if (value == HAL_GPIO_PIN_HIGH)
    {
        DL_GPIO_setPins(gpioOutputPin[pin].port, gpioOutputPin[pin].pin);
    }
    else if (value == HAL_GPIO_PIN_LOW)
    {
        DL_GPIO_clearPins(gpioOutputPin[pin].port, gpioOutputPin[pin].pin);
    }
    else
    {
        /* Code shouldn't get here  */
    }
}

/**
 * @brief     Sets deadband for timer
 * @param[in] pwm       PWM timer
 * @param[in] deadband  Delay time in nanoseconds
 */
void HAL_setDeadband(HAL_PWM pwm, uint16_t deadband)
{
    PWMBase[pwm].deadBand = (uint16_t)(deadband * HAL_PWM_TIMER_FREQ_MHZ/1000);
}

/**
 * @brief     Sets PWMfreq for all timers
 * @param[in] pwm      PWM timer
 * @param[in] PWMFreq  PWM frequency of the motor phase
 */
void HAL_setPWMFreq(HAL_PWM pwm, uint32_t PWMFreq)
{
    GPTIMER_Regs *gptimer = PWMBase[pwm].gptimer;
    uint32_t loadValue = HAL_PWM_TIMER_FREQ_MHZ * 1e6/(2* PWMFreq);
    DL_TimerG_setLoadValue(gptimer, loadValue);
}

/**
 * @brief Write data to spi
 * @param[in] chan  The SPI channel
 * @param[in] cs    Channel select pin
 * @param[in] data  Data to write
 */
void HAL_writeSPI16(HAL_SPI_CHAN chan, HAL_SPI_CS cs, uint16_t data)
{
    SPI_Regs *spi = SPIChannel[chan];
    /* clear the RX buffer  */
    while (!DL_SPI_isRXFIFOEmpty(spi))
    {
        DL_SPI_receiveData16(spi);
    }

    DL_SPI_setChipSelect(spi, SPICS[cs]);
    DL_SPI_transmitData16(spi, data);
}

/**
 * @brief Read data from spi
 * @param[in] chan  The SPI channel
 * @param[in] cs    Channel select pin
 * @return          Data recieved
 */
uint16_t HAL_readSPI16(HAL_SPI_CHAN chan, HAL_SPI_CS cs)
{
    SPI_Regs *spi = SPIChannel[chan];
    while (DL_SPI_isRXFIFOEmpty(spi))
    {

    }
    DL_SPI_setChipSelect(spi, SPICS[cs]);
    return DL_SPI_receiveData16(spi);
}

/**
 * @brief Set ADC reference voltage
 * @param[in] chan       The ADC channel
 * @param[in] voltage_mV Reference voltage
 */
void HAL_setADCRefVoltage(HAL_ADC_CHAN chan, uint16_t voltage_mV)
{
    ADCChannel[chan].refVoltagemV = voltage_mV;
}

/**
 * @brief Get milli volts from ADC
 * @param[in] chan  The ADC channel
 * @return    The ADC value in milli volts
 */
uint32_t HAL_getmvFromADC(HAL_ADC_CHAN chan)
{
    uint32_t num = ADCChannel[chan].refVoltagemV *
                   ADCChannel[chan].value;
    return num/MAX_ADC_VALUE;
}

/**
 * @brief Get volts from ADC in _IQ20
 * @param[in] chan  The ADC channel
 * @return    Return ADC Channel result
 */
_iq20 HAL_getIQ20VoltageFromADC(HAL_ADC_CHAN chan)
{
    uint32_t voltage_mV = HAL_getmvFromADC(chan);
    /* Using IQ13 to support potential upto 262 V ie 262,000 mV. If you know
     * you need less then you can use a larger Q value. If you know you will
     * need more you can use a smaller Q value.
     */
    _iq13 temp = _IQ13div(_IQ13(voltage_mV),_IQ13(1000));
    /* Converting to IQ20 to use as a common Q value for other functions. Since
     * the units are not in V not mV IQ20 still supports the previous stated
     * max of 262 V.
     */
    return _IQ13toIQ20(temp);
}

/**
 * @brief Read ADC values from results
 * @param[in] adcInst ADC instances
 * @return    Return ADC IRQ Index
 */
HAL_ADC_IIDX HAL_processADCIRQ(ADC12_Regs *adcInst)
{
    HAL_ADC_IIDX pendIRQ = (HAL_ADC_IIDX)DL_ADC12_getPendingInterrupt(adcInst);

    for(int x = 0;x<HAL_ADC_CHAN_MAX;x++)
    {
        if(adcInst == ADCChannel[x].inst &&
                pendIRQ == ADCChannel[x].endOfSeq)
        {
            ADCChannel[x].value =
                    DL_ADC12_getMemResult(adcInst, ADCChannel[x].memIdx);
        }
    }
    return pendIRQ;
}

/**
 * @brief Enables ADC interrupts
 * @param[in] chan  The ADC channel
 */
void HAL_enableADCInterrupt(HAL_ADC_CHAN chan)
{
    IRQn_Type irqn = ADCChannel[chan].IRQn;
    NVIC_EnableIRQ(irqn);
}

/**
 * @brief Enables GPIO interrupts
 * @param[in] pin The GPIO pin
 */
void HAL_enableGPIOInterrupt(HAL_GPIO_IN pin)
{
    IRQn_Type irqn = gpioInputPin[pin].IRQn;
    NVIC_EnableIRQ(irqn);
}

/**
 * @brief Enables PWM interrupts
 * @param[in] pwm  The PWM channel
 */
void HAL_enablePWMInterrupt(HAL_PWM pwm)
{
    IRQn_Type irqn = PWMBase[pwm].IRQn;
    NVIC_EnableIRQ(irqn);
}

/**
 * @brief Enables capture interrupts
 * @param[in] capture  The capture channel
 */
void HAL_enableCaptureInterrupt(HAL_CAPTURE_TIMER capture)
{
    IRQn_Type irqn = inputCapture[capture].IRQn;
    NVIC_EnableIRQ(irqn);
}

/**
 * @brief Set ADC voltage reference to VDDA
 * @param[in] chan  The ADC channel
 */
void HAL_setADCVRefVDDA(HAL_ADC_CHAN chan)
{
    ADC12_Regs *adc = ADCChannel[chan].inst;
    DL_ADC12_MEM_IDX idx = ADCChannel[chan].memIdx;

    DL_ADC12_disableConversions(adc);
    DL_Common_updateReg(&adc->ULLMEM.MEMCTL[idx], DL_ADC12_REFERENCE_VOLTAGE_VDDA, ADC12_MEMCTL_VRSEL_MASK);
    DL_ADC12_enableConversions(adc);

    ADCChannel[chan].refVoltagemV = HAL_VDDA_REFVOLTAGE;
}

/**
 * @brief Set ADC voltage reference to internal reference
 * @param[in] chan  The ADC channel
 * @param[in] internalVRef Internal reference voltage
 */
void HAL_setADCVRefInternal(HAL_ADC_CHAN chan, HAL_ADC_INT_VREF internalVRef)
{
    ADC12_Regs *adc = ADCChannel[chan].inst;
    DL_ADC12_MEM_IDX idx = ADCChannel[chan].memIdx;

    DL_ADC12_disableConversions(adc);
    DL_Common_updateReg(&adc->ULLMEM.MEMCTL[idx], DL_ADC12_REFERENCE_VOLTAGE_INTREF, ADC12_MEMCTL_VRSEL_MASK);
    DL_ADC12_enableConversions(adc);

    DL_Common_updateReg(&VREF->CTL0, DL_VREF_ENABLE_ENABLE | internalVRef, VREF_CTL0_ENABLE_MASK | VREF_CTL0_BUFCONFIG_MASK);

    switch(internalVRef)
    {
    case HAL_ADC_INT_VREF_2P5V:
        ADCChannel[chan].refVoltagemV = 2500;
        break;
    case HAL_ADC_INT_VREF_1P4V:
        ADCChannel[chan].refVoltagemV = 1400;
        break;
    default:
        /* Expected to be empty */
        break;
    }
}

/**
 * @brief Set ADC voltage reference to external reference
 * @param[in] chan  The ADC channel
 * @param[in] externalVRef External reference voltage
 */
void HAL_setADCVRefExternal(HAL_ADC_CHAN chan, uint16_t externalVRef)
{
    ADC12_Regs *adc = ADCChannel[chan].inst;
    DL_ADC12_MEM_IDX idx = ADCChannel[chan].memIdx;

    DL_ADC12_disableConversions(adc);
    DL_Common_updateReg(&adc->ULLMEM.MEMCTL[idx], DL_ADC12_REFERENCE_VOLTAGE_EXTREF, ADC12_MEMCTL_VRSEL_MASK);
    DL_ADC12_enableConversions(adc);

    DL_Common_updateReg(&VREF->CTL0, DL_VREF_ENABLE_DISABLE, VREF_CTL0_ENABLE_MASK);

    ADCChannel[chan].refVoltagemV = externalVRef;
}

/**
 * @brief Read the PWM timer fault bit
 * @param[in] fault The fault input
 * @return     The fault status
 */
bool HAL_getTimerFaultStatus(HAL_FAULT_INPUT fault)
{
    return DL_GPIO_readPins(faultInput[fault].port, faultInput[fault].pin);
}

/**
 * @brief Calculates the capture frequency
 * @param[in]  capture  The capture channel
 * @return     The capture frequency
 */
uint32_t HAL_getCaptureFrequency(HAL_CAPTURE_TIMER capture)
{
    GPTIMER_Regs *gptimer = inputCapture[capture].gptimer;
    DL_TIMER_CC_INDEX ccIndex = inputCapture[capture].ccIndex;

    static volatile uint32_t captureValue0;
    static volatile uint32_t captureValue1;

    uint32_t loadValue = DL_Timer_getLoadValue(gptimer);
    uint32_t capturePeriod;

    captureValue1 = captureValue0;

    captureValue0 = DL_Timer_getCaptureCompareValue(gptimer, ccIndex);

    if(captureValue1 > captureValue0)
    {
        capturePeriod = captureValue1 - captureValue0;
    }
    else
    {
        capturePeriod = loadValue + captureValue1 - captureValue0;
    }

    return ((HAL_CAPTURE_TIMER_FREQ)/(capturePeriod + 1));
}

/**
 * @brief updates the adc voltage reference
 * @param[in] adcRef ADC voltage reference
 * @param[in] chan The ADC channel name
 * @param[in] internalVRef  Internal reference voltage
 * @param[in] externalVRef  External reference voltage
 */
void HAL_ADCVRefSel(HAL_ADC_VREF adcRef, HAL_ADC_CHAN chan,
                        HAL_ADC_INT_VREF internalVRef, uint16_t externalVRef)
{
    switch(adcRef)
    {
    case HAL_ADC_VREF_VDDA:
        HAL_setADCVRefVDDA(chan);
        break;
    case HAL_ADC_VREF_INTERNAL:
        HAL_setADCVRefInternal(chan, internalVRef);
        break;
    case HAL_ADC_VREF_EXTERNAL:
        HAL_setADCVRefExternal(chan, externalVRef);
        break;
    default:
        /* This is expected to be empty */
        break;
    }
}
