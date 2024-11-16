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
 *  @brief      Brushed Motor Driver Library HAL Module
 *  @defgroup   BSM__MSPM0L_HAL LP_MSPM0L1306 - Hardware Abstraction Layer (HAL)
 *  
 *
 *  @anchor bsm_lp_mpsm0l1306_hal_Overview
 *  # Overview
 * 
 *  The HAL module provides micro-controller agnostic set of application
 *  programming interfaces (APIs) to be used by other module's in the library
 *  as well as in the user's application code.
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup BSM__MSPM0L_HAL
 * @{
 */
#ifndef bsm_lp_mpsm0l1306_hal_h
#define bsm_lp_mpsm0l1306_hal_h

#include "ti_msp_dl_config.h"
#include <ti/iqmath/include/IQmathLib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Set GPIO output to high
 */
#define HIGH    (PIN_MODE_OUTPUT_HIGH)

/*!
 * @brief Set GPIO output to low
 */
#define LOW     (PIN_MODE_OUTPUT_LOW)

/*! @enum PIN_MODE */
typedef enum {
    /*! Pin to be configured as a low gpio output */
    PIN_MODE_OUTPUT_LOW = 0,
    /*! Pin to be configured as a high gpio output */
    PIN_MODE_OUTPUT_HIGH,
    /*! Pin to be configured as a gpio input with an internal pullup */
    PIN_MODE_INPUT_PU,
    /*! Pin to be configured as a gpio input with an internal pulldown */
    PIN_MODE_INPUT_PD,
    /*! Pin to be configured as a gpio input with no internal pullup or
     *  pulldown.
     */
    PIN_MODE_INPUT_HZ,
    /*! Indicates you want pin set to the peripheral mode */
    PIN_MODE_PERIPHERAL,
    /*! Indicates the max amount of pin mode's supported */
    PIN_MODE_MAX
} PIN_MODE;

/*! @enum PWM_CHANNELS 
 *  @brief Channels described here simply references individual PWM output
 *         pins. This means a micro-controller can have a single peripheral
 *         such as a timer that can be used to generate 1 or more different
 *         PWM signals. Each of those PWM signals are considered seperate
 *         PWM channels.
 */
typedef enum {
    /*! Reference the 1st generic PWM output */
    PWM_CHANNEL_0 = 0,
    /*! Reference the 2nd generic PWM output */
    PWM_CHANNEL_1,
    /*! Indicates the max amount of PWM outputs */
    PWM_CHANNELS_MAX
} PWM_CHANNELS;

/*! @enum SPI_CHANNELS
 *  @brief Channels described usually references individual SPI peripheral
 *         instances ie ( SCLK, PICO and POCI).
 */
typedef enum {
    /*! Reference the 1st generic SPI channel */
    SPI_CHANNEL_0 = 0,
    /*! Indicates the max amount of SPI channels */
    SPI_CHANNELS_MAX
} SPI_CHANNELS;

/*! @enum SPI_CS
 *  @brief The chip select number here has no relationship with the physical
 *         chip select that the SPI peripheral instance has. For example,
 *         SPI_CS_0 can be mapped to the peripheral's CS2 or even a GPIO pin
 *         that is being used as a chip select.
 */
typedef enum {
    /*! Reference the 1st generic SPI chip select */
    SPI_CS_0 = 0,
    /*! Reference the 2nd generic SPI chip select */
    SPI_CS_1,
    /*! Reference the 3rd generic SPI chip select */
    SPI_CS_2,
    /*! Reference the 4th generic SPI chip select */
    SPI_CS_3,
    /*! Indicates the max amount of SPI chip selects */
    SPI_CS_MAX
} SPI_CS;

/*! @enum GPIO_OUTPUT_PINS */
typedef enum {
    /*! Reference the 1st generic gpio output pin */
    GPIO_OUTPUT_PIN_0 = 0,
    /*! Reference the 2nd generic gpio output pin */
    GPIO_OUTPUT_PIN_1,
    /*! Reference the 3rd generic gpio output pin */
    GPIO_OUTPUT_PIN_2,
    /*! Reference the 4th generic gpio output pin */
    GPIO_OUTPUT_PIN_3,
    /*! Reference the 5th generic gpio output pin */
    GPIO_OUTPUT_PIN_4,
    /*! Indicates the max amount of gpio output pins */
    GPIO_OUTPUT_PINS_MAX
} GPIO_OUTPUT_PINS;

/*! @enum GPIO_INPUT_PINS */
typedef enum {
    /*! Reference the 1st generic gpio input pin */
    GPIO_INPUT_PIN_0 = 0,
    /*! Indicates the max amount of gpio input pins */
    GPIO_INPUT_PINS_MAX
} GPIO_INPUT_PINS;

/*! @enum ADC_CHANS */
typedef enum {
    /*! Reference the 1st generic adc channel */
    ADC_CHAN_0 = 0,
    /*! Reference the 2nd generic adc channel */
    ADC_CHAN_1,
    /*! Indicates the max amount of adc channels */
    ADC_CHANS_MAX
} ADC_CHANS;

/**
 * @brief Sets the PWM duty cycle for a specific channel.
 *
 * @param[in] pwmChan The targetted PWM channel
 * @param[in] targetDutyCycle The duty cycle you want the PWM channel to be set
 *                            to.
 *
 */
void HAL_setDutyCycle(PWM_CHANNELS pwmChan,uint8_t targetDutyCycle);

/**
 * @brief Sets the PWM frequency for a specific channel
 *
 * @param[in] pwmChan The targetted PWM channel
 * @param[in] targetFreq Frequency you want to set PWM channel to.
 */
void HAL_setPWMFreq(PWM_CHANNELS pwmChan, uint32_t targetFreq);

/**
 * @brief Sets the PWM pin to specified pin mode
 *
 * @param[in] pwmChan The targetted PWM channel
 * @param[in] mode Pin mode you want to configure pin to. Should only use
 *                 the output or peripheral modes. Other modes may result
 *                 in unexpected behavior.
 */
void HAL_configurePWMPin(PWM_CHANNELS pwmChan,PIN_MODE mode);

/**
 * @brief Performs a 8-bit SPI write with timeout
 *
 * @param[in] spi_chan The targetted SPI channel
 * @param[in] cs_chan The targetted SPI chip select
 * @param[in] data Data to send
 * @param[in] timeout (Not currently used)
 *
 */
void HAL_writeSPI8withTimeout(SPI_CHANNELS spi_chan,
                              SPI_CS cs_chan,
                              uint8_t data,
                              uint32_t timeout);

/**
 * @brief Performs a 8-bit SPI read with timeout
 *
 * @param[in] spi_chan The targetted SPI channel
 * @param[in] cs_chan The targetted SPI chip select
 * @param[in] timeout (Not currently used)
 *
 * @return 8-bit data read back.
 *
 */
uint8_t HAL_readSPI8withTimeout(SPI_CHANNELS spi_chan,
                                SPI_CS cs_chan,
                                uint32_t timeout);

/**
 * @brief Performs a 16-bit SPI write with timeout
 *
 * @param[in] spi_chan The targetted SPI channel
 * @param[in] cs_chan The targetted SPI chip select
 * @param[in] data Data to send
 * @param[in] timeout (Not currently used)
 *
 */
void HAL_writeSPI16withTimeout(SPI_CHANNELS spi_chan,
                               SPI_CS cs_chan,
                               uint16_t data,
                               int32_t timeout);

/**
 * @brief Performs a 16-bit SPI write with timeout
 *
 * @param[in] spi_chan The targetted SPI channel
 * @param[in] cs_chan The targetted SPI chip select
 * @param[in] timeout (Not currently used)
 *
 * @return 16-bit data read back
 *
 */
uint16_t HAL_readSPI16withTimeout(SPI_CHANNELS spi_chan,
                                  SPI_CS cs_chan,
                                  int32_t timeout);

/**
 * @brief Delay function in microseconds
 *
 * @param[in] num_us The number of microseconds you want to delay for
 */
void HAL_delayMicroSeconds(uint32_t num_us);

/**
 * @brief Delay function in milliseconds
 *
 * @param[in] num_us The number of milliseconds you want to delay for
 */
void HAL_delayMilliSeconds(uint32_t num_us);

/**
 * @brief Read GPIO input pin value
 *
 * @param[in] pin The targetted pin you want to read
 * @return True if the input pin is high and false if input pin is low
 */

bool HAL_readGPIOInput(GPIO_INPUT_PINS pin);

/**
 * @brief Set output pin's value
 *
 * @param[in] pin The targetted pin whose output value you want to set
 * @param[in] mode Pin mode you want to configure the pin to. Should only use
 *                 one of the output modes
 */
void HAL_setGPIOOutput(GPIO_OUTPUT_PINS pin,PIN_MODE mode);

/**
 * @brief Function called to run initialization code needed by the HAL
 *
 */
void HAL_Init();

/**
 * @brief Set the reference voltage that specified ADC channel is using. The
 *        software doesn't know what reference voltage is associated with the
 *        ADC channel so this needs to be manually configured.
 *
 * @param adcChan The targetted adc channel
 * @param voltage_mV The reference voltage in mV ie 1.32V = 1320mV
 */
void HAL_setADCRefVoltage(ADC_CHANS adcChan, uint16_t voltage_mV);

/**
 * @brief Return the latest raw ADC value from the specified ADC channel
 *
 * @param adcChan The targetted adc channel
 * @return unsigned 16-bit value
 */
uint16_t HAL_getRawADCValue(ADC_CHANS adcChan);

/**
 * @brief Returns the voltage in mV read from the specified ADC channel.
 *        <b>Important</b>
 *        This function depends on the correct ADC reference voltage being
 *        set @ref HAL_setADCRefVoltage.
 *
 * @param adcChan The targetted adc channel
 * @return Converted ADC channel voltage in mV
 */
uint32_t HAL_getmVfromADC(ADC_CHANS adcChan);

/**
 * @brief Returns the voltage in mV in IQ20 format read from the specified ADC
 *        channel
 *        <b>Important</b>
 *        This function depends on the correct ADC reference voltage being
 *        set @ref HAL_setADCRefVoltage.
 *
 * @param adcChan The ADC channel to get the voltage from.
 * @return Converted ADC channel voltage in mV using the IQ20 format
 */
_iq20 HAL_getIQ20VoltageFromADC(ADC_CHANS adcChan);

/**
 * @brief Function to process ADC interrupts and read converted ADC values.
 *        Should only be used in ADC irqs
 *
 * @param adcInst MSPM0 ADC Driverlib instance that the IRQ was for
 * @return DL_ADC12_IIDX returns interrupt information that caused the IRQ
 *         to fire.
 */
DL_ADC12_IIDX HAL_processADCIRQ(ADC12_Regs *adcInst);

#ifdef __cplusplus
}
#endif

#endif
/** @}*/
