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
 *  @brief      Hall Sensored Trap Motor Control Library HAL Module
 *  @defgroup   HALL_SENSORED_TRAP__MSPM0L_HAL LP_MSPM0L1306 - \
 *  Hardware Abstraction Layer (HAL)
 *
 *
 *  @anchor hall_sensored_trap_lp_mpsm0l1306_hal_Overview
 *  # Overview
 *
 *  The HAL module provides micro-controller agnostic set of application
 *  programming interfaces (APIs) to be used by other module's in the library
 *  as well as in the user's application code.
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup HALL_SENSORED_TRAP__MSPM0L_HAL
 * @{
 */

#ifndef HAL_H
#define HAL_H

#include "ti_msp_dl_config.h"
#include <ti/iqmath/include/IQmathLib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! @brief Defines the system clock frequency, MHz */
#define HAL_SYSTEM_FREQ_MHZ                         ((int32_t)32)

/*! @brief Defines the pwm timer frequency in MHz    */
#define HAL_PWM_TIMER_FREQ_MHZ                      ((int32_t)32)

/*! @brief Defines the input capture timer frequency in Hz    */
#define HAL_CAPTURE_TIMER_FREQ                      ((int32_t)40000)

/*! @brief Defines default ADC refernce voltage  */
#define HAL_VDDA_REFVOLTAGE                         (3300)

/*! @brief Defines ADC max value */
#define MAX_ADC_VALUE                               (4095)

/*! @enum HAL_GPIO_STATE*/
typedef enum
{
    /*! @brief GPIO set to low */
    HAL_GPIO_PIN_LOW = 0,
    /*! @brief GPIO set to high */
    HAL_GPIO_PIN_HIGH
}HAL_GPIO_STATE;

/*! @enum HAL_ADC_CHAN */
typedef enum
{
    /*! @brief Index associated to ADC Channel 0 */
    HAL_ADC_CHAN_0 = 0,
    /*! @brief Index associated to ADC Channel 1 */
    HAL_ADC_CHAN_1,
    /*! @brief Total number of ADC channels  */
    HAL_ADC_CHAN_MAX
}HAL_ADC_CHAN;

/*! @enum HAL_GPIO_IN */
typedef enum
{
    /*! @brief Index associated to input GPIO PIN 1 */
    HAL_GPIO_IN_01 = 0,
    /*! @brief Index associated to input GPIO PIN 2 */
    HAL_GPIO_IN_02,
    /*! @brief Index associated to input GPIO PIN 3 */
    HAL_GPIO_IN_03,
    /*! @brief Index associated to input GPIO PIN 4 */
    HAL_GPIO_IN_04,
    /*! @brief Total number of input GPIO pins */
    HAL_GPIO_IN_MAX
}HAL_GPIO_IN;

/*! @enum HAL_GPIO_OUT*/
typedef enum
{
    /*! @brief Index associated to output GPIO PIN 1 */
    HAL_GPIO_OUT_01 = 0,
    /*! @brief Index associated to output GPIO PIN 2 */
    HAL_GPIO_OUT_02,
    /*! @brief Index associated to output GPIO PIN 3 */
    HAL_GPIO_OUT_03,
    /*! @brief Total number of output GPIO pins */
    HAL_GPIO_OUT_MAX
}HAL_GPIO_OUT;

/*! @enum HAL_PWM */
typedef enum
{
    /*! @brief Index associated to PWM channel 1 */
    HAL_PWM_01 = 0,
    /*! @brief Index associated to PWM channel 2 */
    HAL_PWM_02,
    /*! @brief Index associated to PWM channel 3 */
    HAL_PWM_03,
    /*! @brief Total number of PWM channels */
    HAL_PWM_MAX
}HAL_PWM;

/*! @enum HAL_CAPTURE_TIMER  */
typedef enum
{
    /*! @brief Index associated to input capture 1 */
    HAL_CAPTURE_TIMER_01 = 0,
    /*! @brief Total number of input captures */
    HAL_CAPTURE_TIMER_MAX
}HAL_CAPTURE_TIMER;

/*! @enum HAL_FAULT_INPUT   */
typedef enum
{
    /*! @brief Index associated to fault 1  */
    HAL_FAULT_INPUT_1,
    /*! @brief Total number of faults  */
    HAL_FAULT_INPUT_MAX
}HAL_FAULT_INPUT;

/*! @enum HAL_SPI_CHAN */
typedef enum {
    /*! @brief Index associated to SPI channel 0 */
    HAL_SPI_CHAN_0 = 0,
    /*! @brief Total number of SPI channels */
    HAL_SPI_CHAN_MAX
} HAL_SPI_CHAN;

/*! @enum HAL_SPI_CS */
typedef enum {
    /*! @brief Index associated to chip select 0 */
    HAL_SPI_CS_0 = 0,
    /*! @brief Index associated to chip select 0 */
    HAL_SPI_CS_1,
    /*! @brief Index associated to chip select 0 */
    HAL_SPI_CS_2,
    /*! @brief Index associated to chip select 0 */
    HAL_SPI_CS_3,
    /*! @brief Total number of chip select pins */
    HAL_SPI_CS_MAX
} HAL_SPI_CS;

/*! @enum HAL_ADC_VREF */
typedef enum
{
    /*! @brief ADC Reference VDDA */
    HAL_ADC_VREF_VDDA = 0,
    /*! @brief ADC Internal Reference */
    HAL_ADC_VREF_INTERNAL,
    /*! @brief ADC External Reference */
    HAL_ADC_VREF_EXTERNAL
}HAL_ADC_VREF;

/*! @enum HAL_ADC_INT_VREF */
typedef enum
{
    /*! @brief ADC Internal Reference 2.5V */
    HAL_ADC_INT_VREF_2P5V = DL_VREF_BUFCONFIG_OUTPUT_2_5V,
    /*! @brief ADC Internal Reference 1.4V */
    HAL_ADC_INT_VREF_1P4V = DL_VREF_BUFCONFIG_OUTPUT_1_4V
}HAL_ADC_INT_VREF;

/*! @enum HAL_ADC_IIDX   */
typedef enum
{
    /*! @brief  ADC12 interrupt index for MEMRESX overflow */
    HAL_ADC_IIDX_OVERFLOW = DL_ADC12_IIDX_OVERFLOW,

     /*! @brief  ADC12 interrupt index for sequence conversion trigger overflow */
    HAL_ADC_IIDX_TRIG_OVERFLOW = DL_ADC12_IIDX_TRIG_OVERFLOW,

     /*! @brief  ADC12 interrupt index for MEMRESx result higher than window
      * comparator high threshold */
    HAL_ADC_IIDX_WINDOW_COMP_HIGH = DL_ADC12_IIDX_WINDOW_COMP_HIGH,

     /*! @brief  ADC12 interrupt index for MEMRESx result lower than window
     *  comparator low threshold */
    HAL_ADC_IIDX_WINDOW_COMP_LOW = DL_ADC12_IIDX_WINDOW_COMP_LOW,

     /*! @brief  ADC12 interrupt index for result in range */
    HAL_ADC_IIDX_INIFG = DL_ADC12_IIDX_INIFG,

     /*! @brief  ADC12 interrupt index for DMA done */
    HAL_ADC_IIDX_DMA_DONE = DL_ADC12_IIDX_DMA_DONE,

     /*! @brief  ADC12 interrupt index for MEMRESX underflow */
    HAL_ADC_IIDX_UNDERFLOW = DL_ADC12_IIDX_UNDERFLOW,

     /*! @brief  ADC12 interrupt index for MEM0 result loaded interrupt */
    HAL_ADC_IIDX_MEM0_RESULT_LOADED = DL_ADC12_IIDX_MEM0_RESULT_LOADED,

     /*! @brief  ADC12 interrupt index for MEM1 result loaded interrupt */
    HAL_ADC_IIDX_MEM1_RESULT_LOADED = DL_ADC12_IIDX_MEM1_RESULT_LOADED,

     /*! @brief  ADC12 interrupt index for MEM2 result loaded interrupt */
    HAL_ADC_IIDX_MEM2_RESULT_LOADED = DL_ADC12_IIDX_MEM2_RESULT_LOADED,

     /*! @brief  ADC12 interrupt index for MEM3 result loaded interrupt */
    HAL_ADC_IIDX_MEM3_RESULT_LOADED = DL_ADC12_IIDX_MEM3_RESULT_LOADED,

     /*! @brief  ADC12 interrupt index for MEM4 result loaded interrupt */
    HAL_ADC_IIDX_MEM4_RESULT_LOADED = DL_ADC12_IIDX_MEM4_RESULT_LOADED,

     /*! @brief  ADC12 interrupt index for MEM5 result loaded interrupt */
    HAL_ADC_IIDX_MEM5_RESULT_LOADED = DL_ADC12_IIDX_MEM5_RESULT_LOADED,

     /*! @brief  ADC12 interrupt index for MEM6 result loaded interrupt */
    HAL_ADC_IIDX_MEM6_RESULT_LOADED = DL_ADC12_IIDX_MEM6_RESULT_LOADED,

     /*! @brief  ADC12 interrupt index for MEM7 result loaded interrupt */
    HAL_ADC_IIDX_MEM7_RESULT_LOADED = DL_ADC12_IIDX_MEM7_RESULT_LOADED,

     /*! @brief  ADC12 interrupt index for MEM8 result loaded interrupt */
    HAL_ADC_IIDX_MEM8_RESULT_LOADED = DL_ADC12_IIDX_MEM8_RESULT_LOADED,

     /*! @brief  ADC12 interrupt index for MEM9 result loaded interrupt */
    HAL_ADC_IIDX_MEM9_RESULT_LOADED = DL_ADC12_IIDX_MEM9_RESULT_LOADED,

     /*! @brief  ADC12 interrupt index for MEM10 result loaded interrupt */
    HAL_ADC_IIDX_MEM10_RESULT_LOADED = DL_ADC12_IIDX_MEM10_RESULT_LOADED,

     /*! @brief  ADC12 interrupt index for MEM10 result loaded interrupt */
    HAL_ADC_IIDX_MEM11_RESULT_LOADED = DL_ADC12_IIDX_MEM11_RESULT_LOADED,
}HAL_ADC_IIDX;

/*! @brief Defines a GPIO instance  */
typedef struct HAL_GPIO_Instance_
{
    /*! @brief IOMUX    */
    IOMUX_PINCM         iomux;
    /*! @brief GPIO port    */
    GPIO_Regs *         port;
    /*! @brief GPIO pin    */
    uint32_t            pin;
    /*! @brief GPIO IRQN    */
    IRQn_Type           IRQn;
}HAL_GPIO_Instance;

/*! @brief Defines a ADC instance  */
typedef struct HAL_ADC_instance_
{
    /*! @brief ADC register    */
    ADC12_Regs *        inst;
    /*! @brief ADC end of sequence    */
    HAL_ADC_IIDX        endOfSeq;
    /*! @brief ADC IRQN    */
    IRQn_Type           IRQn;
    /*! @brief ADC result    */
    uint16_t            value;
    /*! @brief ADC reference voltage    */
    uint16_t            refVoltagemV;
    /*! @brief ADC memory IDX    */
    DL_ADC12_MEM_IDX    memIdx;
}HAL_ADC_instance;

/*! @brief Defines a timer instance  */
typedef struct HAL_Timer_Instance_
{
    /*! @brief Timer Register    */
    GPTIMER_Regs        *gptimer;
    /*! @brief Timer ccIndex    */
    DL_TIMER_CC_INDEX   ccIndex;
    /*! @brief Timer ccIndex    */
    DL_TIMER_CC_INDEX   ccCompIndex;
    /*! @brief Deadband */
    uint16_t            deadBand;
    /*! @brief Timer IRQN    */
    IRQn_Type           IRQn;
}HAL_Timer_Instance;

/*! @brief Defines a fault instance  */
typedef struct HAL_fault_instance
{
    /*! @brief Timer Register    */
    GPTIMER_Regs        *gptimer;
    /*! @brief GPIO port    */
    GPIO_Regs *         port;
    /*! @brief GPIO pin    */
    uint32_t            pin;
}HAL_fault_Instance;

extern HAL_Timer_Instance  PWMBase[HAL_PWM_MAX];

extern HAL_Timer_Instance  inputCapture[HAL_CAPTURE_TIMER_MAX];

extern HAL_ADC_instance    ADCChannel[HAL_ADC_CHAN_MAX];

extern HAL_fault_Instance  faultInput[HAL_FAULT_INPUT_MAX];

/**
 * @brief     Initializes the hal object
 */
void HAL_init();

/**
 * @brief     Reads a GPIOpin
 * @param[in] pin   GPIOpin to be read
 * @return    Status of pin
 */
bool HAL_readGPIOPin(HAL_GPIO_IN pin);

/**
 * @brief Write to GPIOpin
 * @param[in] pin GPIOpin to write
 * @param[in] value Value to be written
 */
void HAL_writeGPIOPin(HAL_GPIO_OUT pin, HAL_GPIO_STATE value);

/**
 * @brief     Sets deadband for timer
 * @param[in] pwm       PWM timer
 * @param[in] deadband  Delay time in nanoseconds
 */
void HAL_setDeadband(HAL_PWM pwm, uint16_t deadband);

/**
 * @brief     Sets PWMfreq for all timers
 * @param[in] pwm      PWM timer
 * @param[in] PWMFreq  PWM frequency of the motor phase
 */
void HAL_setPWMFreq(HAL_PWM pwm, uint32_t PWMFreq);

/**
 * @brief Write data to spi
 * @param[in] chan  The SPI channel
 * @param[in] cs    Channel select pin
 * @param[in] data  Data to write
 */
void HAL_writeSPI16(HAL_SPI_CHAN chan, HAL_SPI_CS cs, uint16_t data);

/**
 * @brief Read data from spi
 * @param[in] chan  The SPI channel
 * @param[in] cs    Channel select pin
 * @return          Data recieved
 */
uint16_t HAL_readSPI16(HAL_SPI_CHAN chan, HAL_SPI_CS cs);

/**
 * @brief Set ADC reference voltage
 * @param[in] chan       The ADC channel
 * @param[in] voltage_mV Reference voltage
 */
void HAL_setADCRefVoltage(HAL_ADC_CHAN chan, uint16_t voltage_mV);

/**
 * @brief Get milli volts from ADC
 * @param[in] chan  The ADC channel
 * @return    The ADC value in milli volts
 */
uint32_t HAL_getmvFromADC(HAL_ADC_CHAN chan);

/**
 * @brief Get volts from ADC in _IQ20
 * @param[in] chan  The ADC channel
 * @return    Return ADC Channel result
 */
_iq20 HAL_getIQ20VoltageFromADC(HAL_ADC_CHAN chan);

/**
 * @brief Read ADC values from results
 * @param[in] adcInst ADC instances
 * @return    Return ADC IRQ Index
 */
HAL_ADC_IIDX HAL_processADCIRQ(ADC12_Regs *adcInst);

/**
 * @brief Enables ADC interrupts
 * @param[in] chan  The ADC channel
 */
void HAL_enableADCInterrupt(HAL_ADC_CHAN chan);

/**
 * @brief Enables GPIO interrupts
 * @param[in] pin The GPIO pin
 */
void HAL_enableGPIOInterrupt(HAL_GPIO_IN pin);

/**
 * @brief Enables PWM interrupts
 * @param[in] pwm  The PWM channel
 */
void HAL_enablePWMInterrupt(HAL_PWM PWM);

/**
 * @brief Enables capture interrupts
 * @param[in] capture  The capture channel
 */
void HAL_enableCaptureInterrupt(HAL_CAPTURE_TIMER capture);

/**
 * @brief Set ADC voltage reference to VDDA
 * @param[in] chan  The ADC channel
 */
void HAL_setADCVRefVDDA(HAL_ADC_CHAN chan);

/**
 * @brief Set ADC voltage reference to internal reference
 * @param[in] chan  The ADC channel
 * @param[in] internalVRef Internal reference voltage
 */
void HAL_setADCVRefInternal(HAL_ADC_CHAN chan, HAL_ADC_INT_VREF internalVRef);

/**
 * @brief Set ADC voltage reference to external reference
 * @param[in] chan  The ADC channel
 * @param[in] externalVRef External reference voltage
 */
void HAL_setADCVRefExternal(HAL_ADC_CHAN chan, uint16_t externalVRef);

/**
 * @brief Read the PWM timer fault bit
 * @param[in]  fault The fault input
 * @return     The fault status
 */
bool HAL_getTimerFaultStatus(HAL_FAULT_INPUT fault);

/**
 * @brief Calculates the capture frequency
 * @param[in]  capture  The capture channel
 * @return     The capture frequency
 */
uint32_t HAL_getCaptureFrequency(HAL_CAPTURE_TIMER capture);

/**
 * @brief updates the adc voltage reference
 * @param[in] adcRef ADC voltage reference
 * @param[in] chan The ADC channel name
 * @param[in] internalVRef  Internal reference voltage
 * @param[in] externalVRef  External reference voltage
 */
void HAL_ADCVRefSel(HAL_ADC_VREF adcRef, HAL_ADC_CHAN chan,
                        HAL_ADC_INT_VREF internalVRef, uint16_t externalVRef);

/**
 * @brief     Delays for specific time in microseconds
 * @param[in] microSeconds Delayed time in microseconds
 */
__STATIC_INLINE void HAL_delayMicroSeconds(uint32_t microSeconds)
{
  delay_cycles(HAL_SYSTEM_FREQ_MHZ * microSeconds);
  return;
}

/**
 * @brief     Writes the pwm to the pinouts
 * @param[in] posPhase  phase whose output should be pwm
 * @param[in] gndPhase  phase whose output should be ground
 * @param[in] opnPhase  phase whose output should be open
 * @param[in] PWMDuty   dutycycle of the pwm in percentage
 */
__STATIC_INLINE void HAL_updatePWM(const HAL_PWM posPhase,
                                   const HAL_PWM gndPhase,
                                   const HAL_PWM opnPhase,
                                   const uint16_t PWMDuty)
{
    HAL_Timer_Instance *positivePhase = &PWMBase[posPhase];
    HAL_Timer_Instance *groundPhase = &PWMBase[gndPhase];
    HAL_Timer_Instance *openPhase = &PWMBase[opnPhase];

    /* get the timer load value */
    uint16_t PWMPeriodC0 = DL_TimerG_getLoadValue(positivePhase->gptimer);

    uint16_t deadBand = PWMBase[posPhase].deadBand;

    /* Calculate the capture compare value  */
    uint16_t posPhaseC0_cmpValue = PWMPeriodC0 - (PWMPeriodC0 * PWMDuty)/100 + deadBand;
    uint16_t posPhaseC1_cmpValue = PWMPeriodC0 - (PWMPeriodC0 * PWMDuty)/100 - deadBand;

    /* Set the capture compare value to positive phase  */
    DL_TimerG_setCaptureCompareValue(positivePhase->gptimer,
                                     posPhaseC0_cmpValue,
                                     positivePhase->ccIndex);
    DL_TimerG_setCaptureCompareValue(positivePhase->gptimer,
                                     posPhaseC1_cmpValue,
                                     positivePhase->ccCompIndex);

    DL_Timer_overrideCCPOut(positivePhase->gptimer, DL_TIMER_FORCE_OUT_DISABLED,
                            0, positivePhase->ccIndex);
    DL_Timer_overrideCCPOut(positivePhase->gptimer, DL_TIMER_FORCE_OUT_DISABLED,
                            0, positivePhase->ccCompIndex);

    DL_Timer_overrideCCPOut(groundPhase->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, groundPhase->ccIndex);
    DL_Timer_overrideCCPOut(groundPhase->gptimer, DL_TIMER_FORCE_OUT_HIGH,
                            0, groundPhase->ccCompIndex);

    DL_Timer_overrideCCPOut(openPhase->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, openPhase->ccIndex);
    DL_Timer_overrideCCPOut(openPhase->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, openPhase->ccCompIndex);
}

/**
 * @brief     Set all PWM outputs low
 * @param[in] gndPhase_1  phase whose output should be open
 * @param[in] gndPhase_2  phase whose output should be open
 * @param[in] gndPhase_3  phase whose output should be open
 */
__STATIC_INLINE void HAL_PWMOutputLow(const HAL_PWM gndPhase_1,
                                         const HAL_PWM gndPhase_2,
                                         const HAL_PWM gndPhase_3)
{
    HAL_Timer_Instance *groundPhase01 = &PWMBase[gndPhase_1];
    HAL_Timer_Instance *groundPhase02 = &PWMBase[gndPhase_2];
    HAL_Timer_Instance *groundPhase03 = &PWMBase[gndPhase_3];

    DL_Timer_overrideCCPOut(groundPhase01->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, groundPhase01->ccIndex);
    DL_Timer_overrideCCPOut(groundPhase01->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, groundPhase01->ccCompIndex);

    DL_Timer_overrideCCPOut(groundPhase02->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, groundPhase02->ccIndex);
    DL_Timer_overrideCCPOut(groundPhase02->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, groundPhase02->ccCompIndex);

    DL_Timer_overrideCCPOut(groundPhase03->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, groundPhase03->ccIndex);
    DL_Timer_overrideCCPOut(groundPhase03->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, groundPhase03->ccCompIndex);
}

/**
 * @brief     Set complementary PWM outputs high
 * @param[in] gndPhase_1  phase whose output should be grounded
 * @param[in] gndPhase_2  phase whose output should be grounded
 * @param[in] gndPhase_3  phase whose output should be grounded
 */
__STATIC_INLINE void HAL_PWMOutputHigh(const HAL_PWM gndPhase_1,
                                              const HAL_PWM gndPhase_2,
                                              const HAL_PWM gndPhase_3)
{
    HAL_Timer_Instance *groundPhase01 = &PWMBase[gndPhase_1];
    HAL_Timer_Instance *groundPhase02 = &PWMBase[gndPhase_2];
    HAL_Timer_Instance *groundPhase03 = &PWMBase[gndPhase_3];

    DL_Timer_overrideCCPOut(groundPhase01->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, groundPhase01->ccIndex);
    DL_Timer_overrideCCPOut(groundPhase01->gptimer, DL_TIMER_FORCE_OUT_HIGH,
                            0, groundPhase01->ccCompIndex);

    DL_Timer_overrideCCPOut(groundPhase02->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, groundPhase02->ccIndex);
    DL_Timer_overrideCCPOut(groundPhase02->gptimer, DL_TIMER_FORCE_OUT_HIGH,
                            0, groundPhase02->ccCompIndex);

    DL_Timer_overrideCCPOut(groundPhase03->gptimer, DL_TIMER_FORCE_OUT_LOW,
                            0, groundPhase03->ccIndex);
    DL_Timer_overrideCCPOut(groundPhase03->gptimer, DL_TIMER_FORCE_OUT_HIGH,
                            0, groundPhase03->ccCompIndex);
}

#ifdef __cplusplus
}
#endif
#endif /* HAL_H */
/** @}*/
