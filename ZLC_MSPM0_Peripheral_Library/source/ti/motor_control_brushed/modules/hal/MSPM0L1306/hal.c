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
#include <stdint.h>
#include "hal.h"

#define PWM_TIMER_CLK_FREQ      (GENERIC_PWM_CHAN_0_INST_CLK_FREQ)
#define ADC_LAST_CHAN_LOADED_IRQ (DL_ADC12_IIDX_MEM2_RESULT_LOADED)

#define CYCLES_TO_1_US_DELAY    (CPUCLK_FREQ/1000000)
#define CYCLES_TO_1_MS_DELAY    (CPUCLK_FREQ/1000)
#define DEFAULT_ADC_REFVOLTAGE  (3300)
#define MAX_ADC_VALUE           (4095)

typedef struct {
    IOMUX_PINCM         iomux;
    GPIO_Regs *         port;
    uint32_t            pin;
} HAL_GPIO_PINS;

/* In the HAL PWM and ADC channel is different than PWM and ADC channel on the
 * MCU. In the HAL a channel refers to 1 specific pin. So each of the sequential
 * channels may not on the same peripheral instances for example */
typedef struct {
    uint32_t            iomux_func;
    uint32_t            pin;
    GPTIMER_Regs *      inst;
    GPIO_Regs *         port;
    IOMUX_PINCM         iomux;
    DL_TIMER_CC_INDEX   ccIndex;
} HAL_PWM_CHAN;

typedef struct {
    ADC12_Regs *        inst;
    uint16_t            value;
    uint16_t            refVoltage_mV;
    DL_ADC12_MEM_IDX    memIDX;
    DL_ADC12_IIDX       endOfSeq;
} HAL_ADC_CHAN;

HAL_GPIO_PINS       gpioOutputPin[GPIO_OUTPUT_PINS_MAX];

HAL_GPIO_PINS       gpioInputPin[GPIO_INPUT_PINS_MAX];
HAL_PWM_CHAN        pwmChannel[PWM_CHANNELS_MAX];
SPI_Regs *          spiChannel[SPI_CHANNELS_MAX];
DL_SPI_CHIP_SELECT  spiCS[SPI_CS_MAX];
uint8_t             pwmDutyCycle[PWM_CHANNELS_MAX];
HAL_ADC_CHAN        adcChannel[ADC_CHANS_MAX];


void HAL_configurePin(GPIO_Regs *port,
                      IOMUX_PINCM iomux,
                      uint32_t pin,
                      PIN_MODE mode);

void HAL_initializeArrays() {

    if(SPI_CHANNELS_MAX >= 1) {
        spiChannel[SPI_CHANNEL_0] = GENERIC_SPI_CHAN_0_INST;
    }

    pwmChannel[PWM_CHANNEL_0].inst      = GENERIC_PWM_CHAN_0_INST;
    pwmChannel[PWM_CHANNEL_0].ccIndex    = DL_TIMER_CC_0_INDEX;
    pwmChannel[PWM_CHANNEL_0].iomux      = GPIO_GENERIC_PWM_CHAN_0_C0_IOMUX;
    pwmChannel[PWM_CHANNEL_0].iomux_func = GPIO_GENERIC_PWM_CHAN_0_C0_IOMUX_FUNC;
    pwmChannel[PWM_CHANNEL_0].port       = GPIO_GENERIC_PWM_CHAN_0_C0_PORT;
    pwmChannel[PWM_CHANNEL_0].pin        = GPIO_GENERIC_PWM_CHAN_0_C0_PIN;

    pwmChannel[PWM_CHANNEL_1].ccIndex    = DL_TIMER_CC_1_INDEX;
    pwmChannel[PWM_CHANNEL_1].iomux      = GPIO_GENERIC_PWM_CHAN_0_C1_IOMUX;
    pwmChannel[PWM_CHANNEL_1].iomux_func = GPIO_GENERIC_PWM_CHAN_0_C1_IOMUX_FUNC;
    pwmChannel[PWM_CHANNEL_1].port       = GPIO_GENERIC_PWM_CHAN_0_C1_PORT;
    pwmChannel[PWM_CHANNEL_1].pin        = GPIO_GENERIC_PWM_CHAN_0_C1_PIN;
    pwmChannel[PWM_CHANNEL_1].inst       = GENERIC_PWM_CHAN_0_INST;

    gpioOutputPin[GPIO_OUTPUT_PIN_0].iomux  = GEN_GPIO_OUTPUT_PINO_0_IOMUX ;
    gpioOutputPin[GPIO_OUTPUT_PIN_0].port   = GEN_GPIO_OUTPUT_PORT;
    gpioOutputPin[GPIO_OUTPUT_PIN_0].pin    = GEN_GPIO_OUTPUT_PINO_0_PIN;

    gpioOutputPin[GPIO_OUTPUT_PIN_1].iomux  = GEN_GPIO_OUTPUT_PINO_1_IOMUX;
    gpioOutputPin[GPIO_OUTPUT_PIN_1].port   = GEN_GPIO_OUTPUT_PORT;
    gpioOutputPin[GPIO_OUTPUT_PIN_1].pin    = GEN_GPIO_OUTPUT_PINO_1_PIN;

    gpioOutputPin[GPIO_OUTPUT_PIN_2].iomux  = GEN_GPIO_OUTPUT_PINO_2_IOMUX;
    gpioOutputPin[GPIO_OUTPUT_PIN_2].port   = GEN_GPIO_OUTPUT_PORT;
    gpioOutputPin[GPIO_OUTPUT_PIN_2].pin    = GEN_GPIO_OUTPUT_PINO_2_PIN;

    gpioOutputPin[GPIO_OUTPUT_PIN_3].iomux  = GEN_GPIO_OUTPUT_PINO_3_IOMUX ;
    gpioOutputPin[GPIO_OUTPUT_PIN_3].port   = GEN_GPIO_OUTPUT_PORT;
    gpioOutputPin[GPIO_OUTPUT_PIN_3].pin    = GEN_GPIO_OUTPUT_PINO_3_PIN;

    gpioInputPin[GPIO_INPUT_PIN_0].iomux = GEN_GPIO_INPUT_PINI_0_IOMUX;
    gpioInputPin[GPIO_INPUT_PIN_0].port = GEN_GPIO_INPUT_PORT;
    gpioInputPin[GPIO_INPUT_PIN_0].pin = GEN_GPIO_INPUT_PINI_0_PIN;

    for(int x = 0;x<PWM_CHANNELS_MAX;x++) {
        HAL_setDutyCycle(x,0);
        HAL_setPWMFreq(x,0);

    }

    spiCS[SPI_CS_0] = DL_SPI_CHIP_SELECT_0;
    spiCS[SPI_CS_1] = DL_SPI_CHIP_SELECT_1;
    spiCS[SPI_CS_2] = DL_SPI_CHIP_SELECT_2;
    spiCS[SPI_CS_3] = DL_SPI_CHIP_SELECT_3;

    for(int x = 0;x<ADC_CHANS_MAX;x++) {
        adcChannel[x].refVoltage_mV = 0;
        adcChannel[x].value = 0;
    }

    adcChannel[ADC_CHAN_0].inst = GENERIC_ADC_CHAN_0_INST;
    adcChannel[ADC_CHAN_0].memIDX = GENERIC_ADC_CHAN_0_ADCMEM_0;
    adcChannel[ADC_CHAN_0].endOfSeq = DL_ADC12_IIDX_MEM1_RESULT_LOADED;
    HAL_setADCRefVoltage(ADC_CHAN_0,DEFAULT_ADC_REFVOLTAGE);

    adcChannel[ADC_CHAN_1].inst = GENERIC_ADC_CHAN_0_INST;
    adcChannel[ADC_CHAN_1].memIDX = GENERIC_ADC_CHAN_0_ADCMEM_1;
    adcChannel[ADC_CHAN_1].endOfSeq = DL_ADC12_IIDX_MEM1_RESULT_LOADED;
    HAL_setADCRefVoltage(ADC_CHAN_1,DEFAULT_ADC_REFVOLTAGE);

}

void HAL_Init() {
    HAL_initializeArrays();
    SYSCFG_DL_init();
}

uint8_t HAL_getDutyCycle(PWM_CHANNELS chan) {
    return pwmDutyCycle[chan];
}

void HAL_setPWMFreq(PWM_CHANNELS chan, uint32_t targetFreq) {
    uint32_t dutyCycle_0, dutyCycle_1, period;
    PWM_CHANNELS pwmChan_0, pwmChan_1;
    GPTIMER_Regs * timerInstance;

    /* Assumption is that the PWM channel 0 and channel 1 uses the same
     * PWM instance */
    if (chan == PWM_CHANNEL_0 || chan == PWM_CHANNEL_1) {
        pwmChan_0 = PWM_CHANNEL_0;
        pwmChan_1 = PWM_CHANNEL_1;
        timerInstance =  pwmChannel[pwmChan_0].inst;
    }

    /* For center align target freq used for calculations should be 2x what
     * the user requested for the rest of the math to work.
     */
    targetFreq *= 2;

    /* First we need to figure out the current duty cycle being used for both
     * channels
     */
    dutyCycle_0 = HAL_getDutyCycle(pwmChan_0);
    dutyCycle_1 = HAL_getDutyCycle(pwmChan_1);

    /* Calculate new target frequency */
    period = PWM_TIMER_CLK_FREQ/targetFreq;

    /* Changing load value not safe for a running counter */
    DL_Timer_disableClock(timerInstance);
    DL_TimerG_setLoadValue(timerInstance,period);
    HAL_setDutyCycle(pwmChan_0,(uint8_t)dutyCycle_0);
    HAL_setDutyCycle(pwmChan_1,(uint8_t)dutyCycle_1);

    /* We need to reset the counter to avoid glitches */
    DL_Timer_enableClock(timerInstance);
}

void HAL_configurePWMPin(PWM_CHANNELS chan,PIN_MODE mode) {
    if (mode == PIN_MODE_PERIPHERAL) {
        DL_GPIO_initPeripheralOutputFunction(pwmChannel[chan].iomux,
                                             pwmChannel[chan].iomux_func);
    } else {
        HAL_configurePin(pwmChannel[chan].port,
                         pwmChannel[chan].iomux,
                         pwmChannel[chan].pin,
                         mode);
    }
}

void HAL_setGPIOOutput(GPIO_OUTPUT_PINS pin,PIN_MODE mode) {
    if (mode == PIN_MODE_OUTPUT_LOW) {
        DL_GPIO_clearPins(gpioOutputPin[pin].port, gpioOutputPin[pin].pin);
    } else if(mode == PIN_MODE_OUTPUT_HIGH) {
        DL_GPIO_setPins(gpioOutputPin[pin].port, gpioOutputPin[pin].pin);
    } else {
        /* Code shouldn't get here */
    }
}

bool HAL_readGPIOInput(GPIO_INPUT_PINS pin) {
    return DL_GPIO_readPins(gpioInputPin[pin].port, gpioInputPin[pin].pin);
}

void HAL_configurePin(GPIO_Regs *port,
                      IOMUX_PINCM iomux,
                      uint32_t pin,
                      PIN_MODE mode) {
    if (mode == PIN_MODE_OUTPUT_LOW) {
        DL_GPIO_clearPins(port, pin);
        DL_GPIO_initDigitalOutput(iomux);
        DL_GPIO_enableOutput(port, pin);
    } else if(mode == PIN_MODE_OUTPUT_HIGH) {
        DL_GPIO_setPins(port, pin);
        DL_GPIO_initDigitalOutput(iomux);
        DL_GPIO_enableOutput(port, pin);
    } else if (mode == PIN_MODE_INPUT_PU) {
        DL_GPIO_disableOutput(port, pin);
        DL_GPIO_initDigitalInputFeatures(iomux,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    } else if (mode == PIN_MODE_INPUT_PD) {
        DL_GPIO_disableOutput(port, pin);
        DL_GPIO_initDigitalInputFeatures(iomux,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    } else if (mode == PIN_MODE_INPUT_HZ) {
        DL_GPIO_disableOutput(port, pin);
        DL_GPIO_initDigitalInputFeatures(iomux,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_NONE,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    } else {
        /* Code shouldn't get here */
    }
}

void HAL_setDutyCycle(PWM_CHANNELS chan,uint8_t dutyCycle) {
    GPTIMER_Regs * timerInstance;
    uint32_t loadVal, ccVal;

    timerInstance = pwmChannel[chan].inst;
    loadVal = DL_TimerG_getLoadValue(timerInstance);

    /* Duty Cycle is represented as a whole number to avoid floating point
     * calculation
     */
    ccVal = (100 - ((uint32_t)dutyCycle))*loadVal/100;

    DL_TimerG_setCaptureCompareValue(timerInstance, ccVal, pwmChannel[chan].ccIndex);

    pwmDutyCycle[chan] = dutyCycle;
}

void HAL_writeSPI8withTimeout(SPI_CHANNELS chan,
                              SPI_CS cs,
                              uint8_t data,
                              uint32_t timeout) {
    SPI_Regs *spi = spiChannel[chan];
    while (DL_SPI_isTXFIFOFull(spi)) {
    };

	DL_SPI_setChipSelect(spi,spiCS[cs]);
    DL_SPI_transmitData8(spi, data);
}

uint8_t HAL_readSPI8withTimeout(SPI_CHANNELS chan,
                                SPI_CS cs,
                                uint32_t timeout) {
    SPI_Regs *spi = spiChannel[chan];
    while (DL_SPI_isRXFIFOEmpty(spi)) {
    };

    DL_SPI_setChipSelect(spi,spiCS[cs]);
    return DL_SPI_receiveData8(spi);
}


void HAL_writeSPI16withTimeout(SPI_CHANNELS chan,
                               SPI_CS cs,
                               uint16_t data,
                               int32_t timeout) {
    SPI_Regs *spi = spiChannel[chan];
    while (DL_SPI_isTXFIFOFull(spi)) {
    };

    DL_SPI_setChipSelect(spi,spiCS[cs]);
    DL_SPI_transmitData16(spi, data);
}

uint16_t HAL_readSPI16withTimeout(SPI_CHANNELS chan,
                                  SPI_CS cs,
                                  int32_t timeout) {
    SPI_Regs *spi = spiChannel[chan];
    while (DL_SPI_isRXFIFOEmpty(spi)) {
    };

    DL_SPI_setChipSelect(spi,spiCS[cs]);
    return DL_SPI_receiveData16(spi);
}

void HAL_delayMicroSeconds(uint32_t num_us) {
    if(num_us == 0)
        return;

    DL_Common_delayCycles(num_us*CYCLES_TO_1_US_DELAY);
}

void HAL_delayMilliSeconds(uint32_t num_ms) {
    if(num_ms == 0)
        return;

    DL_Common_delayCycles(num_ms*CYCLES_TO_1_MS_DELAY);
}

void HAL_setADCRefVoltage(ADC_CHANS chan, uint16_t voltage_mV) {
    adcChannel[chan].refVoltage_mV = voltage_mV;
}
uint16_t HAL_getRawADCValue(ADC_CHANS chan) {
    return adcChannel[chan].value;
}

uint32_t HAL_getmVfromADC(ADC_CHANS chan) {
    uint32_t num = adcChannel[chan].refVoltage_mV * adcChannel[chan].value;
    return num/MAX_ADC_VALUE;
}

_iq20 HAL_getIQ20VoltageFromADC(ADC_CHANS chan) {
    uint32_t voltage_mV = HAL_getmVfromADC(chan);
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

DL_ADC12_IIDX HAL_processADCIRQ(ADC12_Regs *adcInst) {
    DL_ADC12_IIDX pend_irq = DL_ADC12_getPendingInterrupt(adcInst);

    for(int x = 0;x<ADC_CHANS_MAX;x++) {
        if(adcInst == adcChannel[x].inst && pend_irq ==  adcChannel[x].endOfSeq)
            adcChannel[x].value = DL_ADC12_getMemResult(adcInst, adcChannel[x].memIDX);
    }
    return pend_irq;
}
