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
/*!****************************************************************************
 *  @file       hal.h
 *  @brief      HAL Module
 *  
 *
 *  @anchor hal_h
 *  # Overview
 *
 *  Does stuff
 *
 *  <hr>
 ******************************************************************************/
/** @defgroup   HAL HAL/LP_MSPM0L1306
 * @{
 */
#ifndef HAL_H
#define HAL_H

/* Including all the sysconfig generated defines */
#include "ti_msp_dl_config.h"

//include the IQmath Library
#include <ti/iqmath/include/IQmathLib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief MCU clock frequency
 */
#define HAL_MCU_CLK_SPEED_HZ                        (32000000)

/*!
 * @brief Cycles for 1 ms delay
 */
#define HAL_CYCLES_TO_1_MS_DELAY                    (HAL_MCU_CLK_SPEED_HZ/1000)

/*!
 * @brief Maximum value of data from the ADC
 */
#define HAL_ADC_MAX_VALUE                           (4095)

/*!
 * @brief Maximum value of data set to DAC
 */
#define HAL_DAC_MAX_VALUE                           (255)

/*!
 * @brief Value of default ADC reference voltage in volts
 */
#define HAL_ADC_DEFAULT_REF_VOLTAGE                 (3.3f)

/*!
 * @brief Value of default DAC reference voltage in volts
 */
#define HAL_DAC_DEFAULT_REF_VOLTAGE                 (3.3f)

/*!
 * @brief Value of the source clock for the timer peripherals
 */
#define HAL_TIM_PERIPHERAL_CLOCK_SOURCE             (32000000)

/*! @brief Define SPI instance */
typedef struct {
    /*! SPI inst address of the channel */
    SPI_Regs *inst;
}HAL_SPI;

/*! @brief Define DAC instance */
typedef struct {
    /*! Comparator inst address of the channel */
    COMP_Regs *  compBase;
    /*! Reference voltage of the channel */
    _iq15 refVoltage;
}HAL_DAC;

/*! @brief Define ADC instance */
typedef struct {
    /*! ADC inst address of the channel */
    ADC12_Regs *inst;
    /*! Reference voltage of the channel */
    _iq15 refVoltage;
    /*! ADC converted data */
    uint16_t value;
    /*! IRQ number for the ADC channel */
    IRQn_Type irqn;
    /*! Memory index for the ADC channel */
    DL_ADC12_MEM_IDX memIDX;
    /*! End of Sequence for the ADC inst */
    DL_ADC12_IIDX endOfSeq;
}HAL_ADC;

/*! @brief Define PWM instance */
typedef struct {
    /*! PWM timer inst address of the channel */
    GPTIMER_Regs *inst;
    /*! IRQ number for the PWM channel */
    IRQn_Type irqn;
    /*! Capture compare index for the PWM channel */
    DL_TIMER_CC_INDEX CCIndex;
}HAL_PWM;

/*! @brief Define TIM instance */
typedef struct {
    /*! Timer inst address of the channel */
    GPTIMER_Regs *inst;
    /*! IRQ number for the Timer channel */
    IRQn_Type irqn;
}HAL_TIM;

/*! @brief Define GPIO instance */
typedef struct {
    /*! Pincm iomux */
    IOMUX_PINCM iomux;
    /*! Pin port */
    GPIO_Regs *port;
    /*! Pin */
    uint32_t pin;
}HAL_GPIO;

/*! @enum HAL_PWM_CHANNEL */
typedef enum
{
    /*! Index associated to PWM channel 0 */
    HAL_PWM_CHANNEL_0 = 0,
    /*! Index associated to PWM channel 1 */
    HAL_PWM_CHANNEL_1,
    /*! Total number of PWM channels */
    HAL_PWM_CHANNEL_MAX,
}HAL_PWM_CHANNEL;

/*! @enum HAL_TIM_CHANNEL */
typedef enum
{
    /*! Index associated to Timer channel 0 */
    HAL_TIM_CHANNEL_0 = 0,
    /*! Index associated to Timer channel 1 */
    HAL_TIM_CHANNEL_1,
    /*! Total number of Timer channels */
    HAL_TIM_CHANNEL_MAX,
}HAL_TIM_CHANNEL;

/*! @enum HAL_ADC_CHANNEL */
typedef enum{
    /*! Index associated to ADC channel 0 */
    HAL_ADC_CHANNEL_0 = 0,
    /*! Index associated to ADC channel 1 */
    HAL_ADC_CHANNEL_1,
    /*! Total number of ADC channels */
    HAL_ADC_CHANNEL_MAX
}HAL_ADC_CHANNEL;

/*! @enum HAL_DAC_CHANNEL */
typedef enum{
    /*! Index associated to DAC channel 0 */
    HAL_DAC_CHANNEL_0 = 0,
    /*! Total number of DAC channels */
    HAL_DAC_CHANNEL_MAX
}HAL_DAC_CHANNEL;

/*! @enum HAL_GPIO_IN_PIN */
typedef enum{
    /*! Index associated to input GPIO PIN 0 */
    HAL_GPIO_IN_PIN_0 = 0,
    /*! Total number of input GPIO pins */
    HAL_GPIO_IN_PIN_MAX,
}HAL_GPIO_IN_PIN;

/*! @enum HAL_GPIO_OUT_PIN */
typedef enum{
    /*! Index associated to output GPIO PIN 0 */
    HAL_GPIO_OUT_PIN_0 = 0,
    /*! Index associated to output GPIO PIN 1 */
    HAL_GPIO_OUT_PIN_1,
    /*! Index associated to output GPIO PIN 2 */
    HAL_GPIO_OUT_PIN_2,
    /*! Index associated to output GPIO PIN 3 */
    HAL_GPIO_OUT_PIN_3,
    /*! Index associated to output GPIO PIN 4 */
    HAL_GPIO_OUT_PIN_4,
    /*! Index associated to output GPIO PIN 5 */
    HAL_GPIO_OUT_PIN_5,
    /*! Index associated to output GPIO PIN 6 */
    HAL_GPIO_OUT_PIN_6,
    /*! Index associated to output GPIO PIN 7 */
    HAL_GPIO_OUT_PIN_7,
    /*! Index associated to output GPIO PIN 8 */
    HAL_GPIO_OUT_PIN_8,
    /*! Index associated to output GPIO PIN 9 */
    HAL_GPIO_OUT_PIN_9,
    /*! Total number of output GPIO pins */
    HAL_GPIO_OUT_PIN_MAX,
}HAL_GPIO_OUT_PIN;

/*! @enum HAL_SPI_CHANNEL */
typedef enum{
    /*! Index associated to SPI channel 0 */
    HAL_SPI_CHANNEL_0 = 0,
    /*! Total number of SPI channels */
    HAL_SPI_CHANNEL_MAX,
}HAL_SPI_CHANNEL;

/*! @enum HAL_SPI_CS */
typedef enum {
    HAL_SPI_CS_0 = 0,
    HAL_SPI_CS_1,
    HAL_SPI_CS_2,
    HAL_SPI_CS_3,
    HAL_SPI_CS_MAX
} HAL_SPI_CS;

/*! @enum HAL_GPIO_VALUE */
typedef enum {
    /*! GPIO set to low */
    HAL_GPIO_VALUE_LOW = 0,
    /*! GPIO set to high */
    HAL_GPIO_VALUE_HIGH,
} HAL_GPIO_VALUE;

/*! @enum HAL_PWM_CHANNEL_MODE */
typedef enum {
    /*! PWM channel in PWM mode */
    HAL_PWM_CHANNEL_MODE_PWM = GPTIMER_CCACT_01_SWFRCACT_DISABLED,
    /*! PWM channel forced to high */
    HAL_PWM_CHANNEL_MODE_FORCED_HIGH = GPTIMER_CCACT_01_SWFRCACT_CCP_HIGH,
    /*! PWM channel forced to low */
    HAL_PWM_CHANNEL_MODE_FORCED_LOW = GPTIMER_CCACT_01_SWFRCACT_CCP_LOW,
}HAL_PWM_CHANNEL_MODE;

/*! @enum HAL_PIN_MODE */
typedef enum {
    /*! Indicates you want pin set as a gpio output and with a low value*/
    HAL_PIN_MODE_OUTPUT_LOW = 0,
    /*! Indicates you want pin set as a gpio output and with a high value*/
    HAL_PIN_MODE_OUTPUT_HIGH,
    /*! Indicates you want pin set as a gpio input with a pullup */
    HAL_PIN_MODE_INPUT_PU,
    /*! Indicates you want pin set as a gpio input with a pulldown */
    HAL_PIN_MODE_INPUT_PD,
    /*! Indicates you want pin set as a gpio input */
    HAL_PIN_MODE_INPUT_HZ,
} HAL_PIN_MODE;

/* Extern the peripheral arrays*/
extern HAL_GPIO gpioOUT[HAL_GPIO_OUT_PIN_MAX];

/**
 * @brief     Initializes the hal module
 */
void HAL_init(void);

/**
 * @brief     Sets the ADC reference voltage
 * @param[in] adcChan   An ADC Channel. One of @ref HAL_ADC_CHANNEL
 * @param[in] value     Reference volatage to be set in IQ
 */
void HAL_setADCRefVoltage(HAL_ADC_CHANNEL adcChan, _iq15 value);

/**
 * @brief     Sets the DAC reference voltage
 * @param[in] dacChan   An DAC Channel. One of @ref HAL_DAC_CHANNEL
 * @param[in] value     Reference volatage to be set in IQ
 */
void HAL_setDacRefVoltage(HAL_DAC_CHANNEL dacChan, _iq15 value);

/**
 * @brief     Sets the ADC scale factor
 */
void HAL_setADCSf(void);

/**
 * @brief     If the IRQ is disabled it is enabled
 * @param[in] irqn   An IRQn.
 */
void HAL_checkAndEnableIRQ(IRQn_Type irqn);

/**
 * @brief     Enable ADC interrupt
 * @param[in] adcChan   An ADC Channel. One of @ref HAL_ADC_CHANNEL
 */
void HAL_enableADCInterrupt(HAL_ADC_CHANNEL adcChan);

/**
 * @brief     Disable ADC interrupt
 * @param[in] adcChan   An ADC Channel. One of @ref HAL_ADC_CHANNEL
 */
void HAL_disableADCInterrupt(HAL_ADC_CHANNEL adcChan);

/**
 * @brief     Enable PWM interrupt
 * @param[in] pwmChan   A PWM channel. One of @ref HAL_PWM_CHANNEL
 */
void HAL_enablePWMInterrupt(HAL_PWM_CHANNEL pwmChan);

/**
 * @brief     Disable PWM interrupt
 * @param[in] pwmChan   A PWM channel. One of @ref HAL_PWM_CHANNEL
 */
void HAL_disablePWMInterrupts(HAL_PWM_CHANNEL pwmChan);

/**
 * @brief     Enable TIM interrupt
 * @param[in] timChan   A TIM channel. One of @ref HAL_TIM_CHANNEL
 */
void HAL_enableTIMInterrupt(HAL_TIM_CHANNEL timChan);

/**
 * @brief     Disable TIM interrupt
 * @param[in] timChan   A TIM channel. One of @ref HAL_TIM_CHANNEL
 */
void HAL_disableTIMInterrupt(HAL_TIM_CHANNEL timChan);

/**
 * @brief     Set value to GPIO pin
 * @param[in] gpioPin   A GPIO pin. One of @ref HAL_GPIO_OUT_PIN
 * @param[in] value     Value to be set to pin. One of @ref HAL_GPIO_VALUE
 */
__STATIC_INLINE void HAL_setGPIOVal(HAL_GPIO_OUT_PIN gpioPin, HAL_GPIO_VALUE value)
{
   if(value == HAL_GPIO_VALUE_HIGH)
   {
       DL_GPIO_setPins(gpioOUT[gpioPin].port, gpioOUT[gpioPin].pin);
   }
   else
   {
       DL_GPIO_clearPins(gpioOUT[gpioPin].port, gpioOUT[gpioPin].pin);
   }
}

/**
 * @brief     Read GPIO pin
 * @param[in] gpioPin   A GPIO pin. One of @ref HAL_GPIO_IN_PIN
 * @return    Returns the value of the GPIO pin. One of @ref HAL_GPIO_VALUE
 */
HAL_GPIO_VALUE HAL_readGPIOVal(HAL_GPIO_IN_PIN gpioPin);

/**
 * @brief     Configure pin
 * @param[in] port      GPIO Port for the pin
 * @param[in] iomux     IOMUX for the pin
 * @param[in] pin       Port of the pin
 * @param[in] mode      Mode to set. One of @ref HAL_PIN_MODE
 */
void HAL_configurePin(
        GPIO_Regs *port, IOMUX_PINCM iomux, uint32_t pin, HAL_PIN_MODE mode);

/**
 * @brief     Configure GPIO OUT pin
 * @param[in] gpioPin   A GPIO OUT pin. One of @ref HAL_GPIO_OUT_PIN
 * @param[in] mode      Mode to set. One of @ref HAL_PIN_MODE
 */
void HAL_configureGPIOOUTPin(HAL_GPIO_OUT_PIN gpioPin, HAL_PIN_MODE mode);

/**
 * @brief     Configure GPIO IN pin
 * @param[in] gpioPin   A GPIO IN pin. One of @ref HAL_GPIO_IN_PIN
 * @param[in] mode      Mode to set. One of @ref HAL_PIN_MODE
 */
void HAL_configureGPIOINPin(HAL_GPIO_IN_PIN gpioPin, HAL_PIN_MODE mode);

/**
 * @brief     Set voltage on DAC channel
 * @param[in] dacChan   A DAC channel. One of @ref HAL_DAC_CHANNEL
 * @param[in] volt      Voltage to be set on DAC in _iq15.
 */
void HAL_setDACVoltage(HAL_DAC_CHANNEL dacChan, _iq15 volt);

/**
 * @brief     Gets the Load value of the timer associated with the PWM channel
 * @param[in] pwmChan   A PWM channel. One of @ref HAL_PWM_CHANNEL
 * @return    Returns the load register value of the timer instance of the 
 *            specified PWM channel
 */
uint32_t HAL_getPWMLoadValue(HAL_PWM_CHANNEL pwmChan);

/**
 * @brief     Start the timer associated with the PWM channel
 * @param[in] pwmChan   A PWM channel. One of @ref HAL_PWM_CHANNEL
 */
void HAL_startPWMCounter(HAL_PWM_CHANNEL pwmChan);

/**
 * @brief     Stops the timer associated with the PWM channel
 * @param[in] pwmChan   A PWM channel. One of @ref HAL_PWM_CHANNEL
 */
void HAL_stopPWMCounter(HAL_PWM_CHANNEL pwmChan);

/**
 * @brief     Start the timer associated with the TIM channel
 * @param[in] timChan   A TIM channel. One of @ref HAL_TIM_CHANNEL
 */
void HAL_startTIMCounter(HAL_TIM_CHANNEL timChan);

/**
 * @brief     Stops the timer associated with the TIM channel
 * @param[in] timChan   A TIM channel. One of @ref HAL_PWM_CHANNEL
 */
void HAL_stopTIMCounter(HAL_TIM_CHANNEL timChan);

/**
 * @brief     Checks if the timer counter is running
 * @param[in] pwmChan   A PWM channel. One of @ref HAL_PWM_CHANNEL
 * @return    Returns the running status of timer
 *
 * @retval     true  Timer is running
 * @retval     false Timer is not running
 */
bool HAL_isPWMCounterRunning(HAL_PWM_CHANNEL pwmChan);

/**
 * @brief     Checks if the timer counter is running
 * @param[in] timChan   A TIM channel. One of @ref HAL_TIM_CHANNEL
 * @return    Returns the running status of timer
 *
 * @retval     true  Timer is running
 * @retval     false Timer is not running
 */
bool HAL_isTIMCounterRunning(HAL_TIM_CHANNEL timChan);

/**
 * @brief     Set dutycycle to a pwm channel
 * @param[in] pwmChan   A PWM channel. One of @ref HAL_PWM_CHANNEL
 * @param[in] dutycycle Percentage dutycycle to be set in the PWM channel .
 */
void HA_setPWMDutyCycle(HAL_PWM_CHANNEL pwmChan,uint8_t dutycycle);

/**
 * @brief     Set the frequency of the timer associated with the PWM channel
 * @param[in] pwmChan   A PWM channel. One of @ref HAL_PWM_CHANNEL
 * @param[in] freq      PWM frequency to be set.
 */
void HAL_setPWMFreq(HAL_PWM_CHANNEL pwmChan, uint32_t freq);

/**
 * @brief     Set the frequency of the timer associated with the TIM channel
 * @param[in] timChan   A TIM channel. One of @ref HAL_TIM_CHANNEL
 * @param[in] freq      TIM frequency to be set.
 */
void HAL_setTIMFreq(HAL_TIM_CHANNEL timChan, uint32_t freq);

/**
 * @brief     Set the Load value of the timer associated with the PWM channel
 * @param[in] pwmChan   A PWM channel. One of @ref HAL_PWM_CHANNEL
 * @param[in] loadValue Load value to be set to the specified PWM channel.
 */
void HAL_setPWMLoadVal(HAL_PWM_CHANNEL pwmChan, uint32_t loadValue);

/**
 * @brief     Set the Load value of the timer associated with the TIM channel
 * @param[in] timChan   A TIM channel. One of @ref HAL_TIM_CHANNEL
 * @param[in] loadValue Load value to be set to the specified TIM channel.
 */
void HAL_setTIMLoadVal(HAL_TIM_CHANNEL timChan, uint32_t loadValue);

/**
 * @brief     Set the frequency for timer peripheral
 * @param[in] timerInst Pointer to a timer peripheral.
 * @param[in] freq      Frequency to be set to peripheral.
 */
void HAL_setFreq(GPTIMER_Regs * timerInst, uint32_t freq);

/**
 * @brief     Set the Load value of a timer peripheral
 * @param[in] timerInst Pointer to a timer peripheral.
 * @param[in] loadValue Load value to be set to the timer peripheral.
 */
void HAL_setLoadVal(GPTIMER_Regs * timerInst, uint32_t loadValue);

/**
 * @brief     Gets the ADC sampled value
 * @param[in] adcChan   An ADC Channel. One of @ref HAL_ADC_CHANNEL
 * @return    Returns the ADC sampled value
 */
uint16_t HAL_getADCData(HAL_ADC_CHANNEL adcChan);

/**
 * @brief     Gets the converted value in adc
 * @param[in] adcChan   An ADC Channel. One of @ref HAL_ADC_CHANNEL
 * @return    Returns the converted value in adc
 */
_iq15 HAL_getADCResult(HAL_ADC_CHANNEL adcChan);

/**
 * @brief     Collects the ADC data if the adc convertion is over
 * @param[in] adcInst   Pointer to a ADC peripheral
 * @return DL_ADC12_IIDX returns interrupt information that caused the IRQ
 *         to fire.
 */
DL_ADC12_IIDX HAL_processADCIRQ(ADC12_Regs *adcInst);

/**
 * @brief     Blocks for the specified delay time
 * @param[in] num_ms   Delay in ms
 */
void HAL_delayMilliSeconds(uint32_t num_ms);

/**
 * @brief     Change the configuration of PWM channel
 * @param[in] pwmChan   A PWM channel. One of @ref HAL_PWM_CHANNEL
 * @param[in] pwmMode   PWM Mode to be set. One of @ref HAL_PWM_CHANNEL_MODE
 */
void HAL_configurePWMPin(HAL_PWM_CHANNEL pwmChan, HAL_PWM_CHANNEL_MODE pwmMode);

/**
 * @brief     Gets status of RX Fifo 
 * @param[in] spiPeripheral   A SPI peripheral. One of @ref HAL_SPI_CHANNEL
 * @return    Returns empty status of RX Fifo 
 * 
 *  @retval     true  The RX FIFO is empty
 *  @retval     false The RX FIFO is not empty
 */
bool HAL_isSPIRxFifoEmpty(HAL_SPI_CHANNEL spiPeripheral);

/**
 * @brief     Reads 16 bit data in SPI peripheral 
 * @param[in] spiPeripheral   A SPI peripheral. One of @ref HAL_SPI_CHANNEL
 * @param[in] cs     A SPI chip select. One of @ref HAL_SPI_CS
 * @return    Data received in SPI peripheral
 */
uint16_t HAL_receiveSPIData16(HAL_SPI_CHANNEL spiPeripheral, HAL_SPI_CS cs);

/**
 * @brief     Writes 16 bit data in SPI peripheral 
 * @param[in] spiPeripheral   A SPI peripheral. One of @ref HAL_SPI_CHANNEL
 * @param[in] cs     A SPI chip select. One of @ref HAL_SPI_CS
 * @param[in] data   Data to be written in to the SPI peripheral
 */
void HAL_transmitSPIData16(
                HAL_SPI_CHANNEL spiPeripheral, HAL_SPI_CS cs, uint16_t data);

/**
 * @brief     Gets busy status of SPI peripheral
 * @param[in] spiPeripheral   A SPI peripheral. One of @ref HAL_SPI_CHANNEL
 * @return    Returns busy status of RX Fifo 
 * 
 * @retval     true  The SPI peripheral is currently busy with transmitting data
 * @retval     false The SPI peripheral is in idle
 */
bool HAL_isSPIBusy(HAL_SPI_CHANNEL spiPeripheral);

/**
 * @brief     Clears the RX Fifo if the SPI peripheral 
 * @param[in] spiPeripheral   A SPI peripheral. One of @ref HAL_SPI_CHANNEL
 * @param[in] cs     A SPI chip select. One of @ref HAL_SPI_CS
 */
__STATIC_INLINE void HAL_SPI_clearRXFifo(
                                HAL_SPI_CHANNEL spiPeripheral, HAL_SPI_CS cs)
{
    while (!HAL_isSPIRxFifoEmpty(spiPeripheral))
    {
        HAL_receiveSPIData16(spiPeripheral, cs);
    }
}

#ifdef __cplusplus
}
#endif
#endif /* HAL_H */
/** @}*/