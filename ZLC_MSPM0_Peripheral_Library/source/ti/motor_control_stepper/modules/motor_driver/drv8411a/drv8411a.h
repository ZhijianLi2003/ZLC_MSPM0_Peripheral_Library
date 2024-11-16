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
 *  @file       drv8411a.h
 *  @brief      MD_MODULE Module
 *
 *
 *  @anchor drv8411a_h
 *  # Overview
 *
 *  Does stuff
 *
 *  <hr>
 ******************************************************************************/
/** @defgroup MD_MODULE Motor_Driver/DRV8411A
 * @{
 */
#ifndef DRV8411A_H
#define DRV8411A_H

#include <stdbool.h>
#include "hal.h"
#include "stepper.h"

/* include the IQmath Library */
#include <ti/iqmath/include/IQmathLib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief value of AIropoi in uA/A
 */
#define DRV8411A_A_IPROPI                       (200)

/*!
 * @brief Max Timer frequency limit
 */
#define DRV8411A_MAX_SET_FREQ                   (80000)

/*! @enum DRV8411A_DIR */
typedef enum
{
    /*! Forward direction */
    DRV8411A_DIR_FORWARD = 0,
    /*! Reverse direction */
    DRV8411A_DIR_REVERSE,
}DRV8411A_DIR;

/*! @enum DRV8411A_STEP */
typedef enum
{
    /*! Full step mode */
    DRV8411A_STEP_FULL_STEP = 0,
    /*! Half step mode */
    DRV8411A_STEP_HALF_STEP_NC,
    /*! Total number of step mode */
    DRV8411A_STEP_MAX,
}DRV8411A_STEP;

/*! @enum DRV8411A_DECAY */
typedef enum
{
    /*! Slow decay mode */
    DRV8411A_DECAY_SLOW = 0,
    /*! Fast decay mode */
    DRV8411A_DECAY_FAST,
}DRV8411A_DECAY;

/*! @enum DRV8411A_CONTROL_MODE */
typedef enum
{
    /*! Spin mode */
    DRV8411A_CONTROL_MODE_SPIN = 0,
    /*! Step mode */
    DRV8411A_CONTROL_MODE_STEP,
}DRV8411A_CONTROL_MODE;

/*! @enum DRV8411A_DRIVE */
typedef enum
{
    /*! Disabled mode */
    DRV8411A_DRIVE_DISABLED =0,
    /*! Enabled mode */
    DRV8411A_DRIVE_ENABLED,
}DRV8411A_DRIVE;

/*! @brief Define drv8411a structure */
typedef struct {
    /*!  Stores the selected step mode. @ref DRV8411A_STEP */
    DRV8411A_STEP stepMode;
    /*!  Stores the selected decay mode. @ref DRV8411A_DECAY */
    DRV8411A_DECAY decayMode;
    /*!  Stores the selected control mode. @ref DRV8411A_CONTROL_MODE */
    DRV8411A_CONTROL_MODE controlMode;
    /*!  Stores the selected drive state. @ref DRV8411A_DRIVE */
    DRV8411A_DRIVE driveState;
    /*!  Stores the steps to move */
    uint32_t setStep;
    /*!  Stores the step count */
    uint32_t stepCount;
    /*!  Stores the ripropi value in Q15 */
    _iq15 ripropiVal;
    /*! Stores the indexer timer frequency */
    uint32_t setFreq;
    /*!  GPIO pin set for ain1. @ref HAL_GPIO_OUT_PIN */
    HAL_GPIO_OUT_PIN ain1;
    /*!  GPIO pin set for ain2. @ref HAL_GPIO_OUT_PIN */
    HAL_GPIO_OUT_PIN ain2;
    /*!  GPIO pin set for bin1. @ref HAL_GPIO_OUT_PIN */
    HAL_GPIO_OUT_PIN bin1;
    /*!  GPIO pin set for bin2. @ref HAL_GPIO_OUT_PIN */
    HAL_GPIO_OUT_PIN bin2;
    /*!  GPIO pin set for nfault. @ref HAL_GPIO_IN_PIN */
    HAL_GPIO_IN_PIN nfault;
    /*!  ADC channel set for aipropi. @ref HAL_ADC_CHANNEL */
    HAL_ADC_CHANNEL aipropi;
    /*!  ADC channel set for bipropi. @ref HAL_ADC_CHANNEL */
    HAL_ADC_CHANNEL bipropi;
    /*!  DAC channel set for vref. @ref HAL_DAC_CHANNEL */
    HAL_DAC_CHANNEL vref;
    /*!  TIM channel set for indexer timer. @ref HAL_TIM_CHANNEL */
    HAL_TIM_CHANNEL indexerTimer;
    /*!  TIM channel set for ADC trigger timer. @ref HAL_TIM_CHANNEL */
    HAL_TIM_CHANNEL ADCTriggerTimer;
    /*!  Corresponding Indexer instance */
    INDEXER_Instance indexer;
    /*!  Itrip scale factor */
    _iq15 itripSf;
    /*!  Current scale factor */
    _iq15 iSf;
} DRV8411A_Instance;

/**
 * @brief     Enables the necessary interrupts
 * @param[in] handle    A pointer to drv8411a instance
 */
__STATIC_INLINE void DRV8411A_init(DRV8411A_Instance *handle)
{   
    HAL_enableADCInterrupt(handle->aipropi);
    HAL_enableADCInterrupt(handle->bipropi);
    HAL_enableTIMInterrupt(handle->indexerTimer);
    HAL_enableTIMInterrupt(handle->ADCTriggerTimer);
}

/**
 * @brief     Enables the drive
 * @param[in] handle    A pointer to drv8411a instance
 */
void DRV8411A_enableDrive(DRV8411A_Instance *handle);

/**
 * @brief     Disables the drive
 * @param[in] handle    A pointer to drv8411a instance
 */
void DRV8411A_disableDrive(DRV8411A_Instance *handle);

/**
 * @brief     Starts the motor
 * @param[in] handle    A pointer to drv8411a instance
 */
void DRV8411A_startMotor(DRV8411A_Instance *handle);

/**
 * @brief     Stops the motor
 * @param[in] handle    A pointer to drv8411a instance
 */
void DRV8411A_stopMotor(DRV8411A_Instance *handle);

/**
 * @brief     Checks if the motor is currently running 
 * @param[in] handle    A pointer to drv8411a instance
 * @return    Returns the running status of motor
 * 
 * @retval    true  Motor is currently running
 * @retval    false Motor is not currently running
 */
bool DRV8411A_isMotorRunning(DRV8411A_Instance *handle);

/**
 * @brief     Gets if any fault occurred at the instant 
 * @param[in] handle    A pointer to drv8411a instance
 * @return    Returns if fault occurred 
 * 
 * @retval    true  Fault currently present
 * @retval    false No fault is currently present
 */
bool DRV8411A_isFaultOccurred(DRV8411A_Instance *handle);

/**
 * @brief     Sets the direction of motor
 * @param[in] handle    A pointer to drv8411a instance
 * @param[in] dir       New direction to be set. One of @ref DRV8411A_DIR
 */
void DRV8411A_setDirection(DRV8411A_Instance *handle, DRV8411A_DIR dir);

/**
 * @brief     Sets the step mode
 * @param[in] handle   A pointer to drv8411a instance
 * @param[in] stepMode Step mode to be set.
 *                     One of @ref DRV8411A_STEP
 */
void DRV8411A_setStepMode(
    DRV8411A_Instance *handle, DRV8411A_STEP stepMode);

/**
 * @brief     Sets the decay mode
 * @param[in] handle    A pointer to drv8411a instance
 * @param[in] decayMode Decay mode to be set. One of @ref DRV8411A_DECAY
 */
__STATIC_INLINE void DRV8411A_setDecayMode(
                            DRV8411A_Instance *handle, DRV8411A_DECAY decayMode)
{
    handle->decayMode = decayMode;
}

/**
 * @brief     Sets the motor speed by setting the timer frequency
 * @param[in] handle    A pointer to drv8411a instance
 * @param[in] timFreq   Timer frequency to be set
 */
void DRV8411A_setSpeed(DRV8411A_Instance *handle, uint32_t timFreq);

/**
 * @brief     Sets Itrip scale factor
 * @param[in] handle    A pointer to drv8411a instance
 */
__STATIC_INLINE void DRV8411A_setItripSf(DRV8411A_Instance *handle)
{
    handle->itripSf = _IQ15div(handle->ripropiVal, handle->iSf);
}

/**
 * @brief     Sets Phase current scale factors
 * @param[in] handle        A pointer to drv8411a instance
 * @param[in] _1ByAIpropoi  Value of 1/AIpropi to be set as scale factor
 */
__STATIC_INLINE void DRV8411A_setISf(DRV8411A_Instance *handle,
                                     _iq15 _1ByAIpropoi)
{
    handle->iSf = _1ByAIpropoi;
}

/**
 * @brief     Sets ripropi value
 * @param[in] handle    A pointer to drv8411a instance
 * @param[in] value     Ripropi value to be set
 */
__STATIC_INLINE void DRV8411A_setRIPROPI(
    DRV8411A_Instance *handle, uint32_t value)
{
    handle->ripropiVal = _IQ15(value);
    DRV8411A_setItripSf(handle);
}

/**
 * @brief     Sets trip current
 * @param[in] handle    A pointer to drv8411a instance
 * @param[in] itrip     Trip current value to be set in IQ
 */
__STATIC_INLINE void DRV8411A_setItrip(DRV8411A_Instance *handle, _iq15 itrip)
{
    _iq15 volt = _IQ15mpy(itrip, handle->itripSf);
    HAL_setDACVoltage(handle->vref, volt);
}

/**
 * @brief     Sets the reference voltage for the current measurements
 * @param[in] handle     A pointer to drv8411a instance
 * @param[in] refVoltage Reference voltage to be set in IQ
 */
__STATIC_INLINE void DRV8411A_setPhaseCurrentRefVoltage(
                                    DRV8411A_Instance *handle, _iq15 refVoltage)
{
    HAL_setADCRefVoltage(handle->aipropi, refVoltage);
    HAL_setADCRefVoltage(handle->bipropi, refVoltage);
}

/**
 * @brief     Sets the reference voltage for the vref output
 * @param[in] handle     A pointer to drv8411a instance
 * @param[in] refVoltage Reference voltage to be set in IQ
 */
__STATIC_INLINE void DRV8411A_setVrefRefVoltage(
                                    DRV8411A_Instance *handle, _iq15 refVoltage)
{
    HAL_setDacRefVoltage(handle->vref, refVoltage);
}

/**
 * @brief     Gets the converted IA current
 * @param[in] handle    A pointer to drv8411a instance
 * @return    Returns the converted IA current in IQ
 */
__STATIC_INLINE _iq15 DRV8411A_getIA(DRV8411A_Instance *handle)
{
    _iq15 adcVal = HAL_getADCResult(handle->aipropi);
    return _IQ15div(_IQ15mpy(adcVal, handle->iSf), handle->ripropiVal);
}

/**
 * @brief     Gets the converted IB current
 * @param[in] handle    A pointer to drv8411a instance
 * @return    Returns the converted IB current in IQ
 */
__STATIC_INLINE _iq15 DRV8411A_getIB(DRV8411A_Instance *handle)
{
    _iq15 adcVal = HAL_getADCResult(handle->bipropi);
    return _IQ15div(_IQ15mpy(adcVal, handle->iSf), handle->ripropiVal);
}

/**
 * @brief     Sets the steps to move in step mode
 * @param[in] handle    A pointer to drv8411a instance
 * @param[in] setSteps  Steps to move in step mode
 */
__STATIC_INLINE void DRV8411A_setStep(
    DRV8411A_Instance *handle, uint16_t setSteps)
{
    handle->setStep = setSteps;
}

/**
 * @brief     Sets the control mode
 * @param[in] handle     A pointer to drv8411a instance
 * @param[in] ctrl_mode  Control mode to be set.
 *                       One of @ref DRV8411A_CONTROL_MODE_STEP
 */
__STATIC_INLINE void DRV8411A_setControlMode(
    DRV8411A_Instance *handle, DRV8411A_CONTROL_MODE ctrl_mode)
{
    handle->controlMode = ctrl_mode;
}

/**
 * @brief     Checks if motor has moved the required steps in step mode
 * @param[in] handle    A pointer to drv8411a instance
 */
__STATIC_INLINE void DRV8411A_checkStep(DRV8411A_Instance *handle)
{
    if(handle->controlMode == DRV8411A_CONTROL_MODE_STEP)
    {
        handle->stepCount += 1;
        if(handle->stepCount >= handle->setStep)
        {
            handle->stepCount = 0;
            DRV8411A_stopMotor(handle);
        }
    }
}

/**
 * @brief     Updates both phase drive states if drv state is enabled
 * @param[in] in1           GPIO pin for input 1
 * @param[in] in2           GPIO pin for input 2
 * @param[in] drive         New drive state to be set.
 *                          One of @ref STEPPER_DRIVE
 * @param[in] decayMode    A decay mode. One of @ref DRV8411A_DECAY
 */
__STATIC_INLINE void DRV8411A_setPWMDrive(
                                HAL_GPIO_OUT_PIN in1, HAL_GPIO_OUT_PIN in2,
                                STEPPER_DRIVE drive, DRV8411A_DECAY decayMode)
{
    HAL_GPIO_VALUE in1GpioVal  = HAL_GPIO_VALUE_LOW;
    HAL_GPIO_VALUE in2GpioVal  = HAL_GPIO_VALUE_LOW;
    switch (drive)
    {
        case STEPPER_DRIVE_DISABLE:
            in1GpioVal = HAL_GPIO_VALUE_LOW;
            in2GpioVal = HAL_GPIO_VALUE_LOW;
            break;
        case STEPPER_DRIVE_DECAY:
            if(decayMode == DRV8411A_DECAY_SLOW)
            {
                in1GpioVal = HAL_GPIO_VALUE_HIGH;
                in2GpioVal = HAL_GPIO_VALUE_HIGH;
            }
            else
            {
                in1GpioVal = HAL_GPIO_VALUE_LOW;
                in2GpioVal = HAL_GPIO_VALUE_LOW;
            }
            break;
        case STEPPER_DRIVE_FORWARD:
            in1GpioVal = HAL_GPIO_VALUE_HIGH;
            in2GpioVal = HAL_GPIO_VALUE_LOW;
            break;
        case STEPPER_DRIVE_REVERSE:
            in1GpioVal = HAL_GPIO_VALUE_LOW;
            in2GpioVal = HAL_GPIO_VALUE_HIGH;
            break;
        default:
            /* This is expected to be empty */
            break;
    }
    HAL_setGPIOVal(in1, in1GpioVal);
    HAL_setGPIOVal(in2, in2GpioVal);
}

/**
 * @brief     Updates both phase drive states if drv state is enabled
 * @param[in] handle    A pointer to drv8411a instance
 */
__STATIC_INLINE void DRV8411A_setPWMDrives(DRV8411A_Instance *handle)
{
    INDEXER_Instance* indexer = &handle->indexer;
    if(handle->driveState == DRV8411A_DRIVE_DISABLED)
    {
        indexer->IaDrive = STEPPER_DRIVE_DISABLE;
        indexer->IbDrive = STEPPER_DRIVE_DISABLE;
    }
    DRV8411A_setPWMDrive(handle->ain1, handle->ain2,
                                        indexer->IaDrive, handle->decayMode);
                            
    DRV8411A_setPWMDrive(handle->bin1, handle->bin2,
                                        indexer->IbDrive, handle->decayMode);
}

/**
 * @brief     Calls the indexer to update the commutation state
 * @param[in] handle    A pointer to drv8411a instance
 */
__STATIC_INLINE void DRV8411A_setComm(DRV8411A_Instance *handle)
{
    STEPPER_indexer(&handle->indexer);
    
    DRV8411A_setPWMDrives(handle);

    DRV8411A_checkStep(handle);
}

#ifdef __cplusplus
}
#endif
#endif /* DRV8411A_H */
/** @}*/
