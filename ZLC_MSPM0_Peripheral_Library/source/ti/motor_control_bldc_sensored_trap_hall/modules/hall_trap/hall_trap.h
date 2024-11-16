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
 *  @file       hall_trap.h
 *  @brief      HALL_TRAP_MODULE Module
 *
 *  @anchor hall_trap_h
 *  # Overview
 *  
 *  API's releated to hall_trap
 * 
 *  <hr>
 ******************************************************************************/
/** @addtogroup HALL_TRAP_MODULE Hall Trap
 * @{
 */

#ifndef hall_trap_h
#define hall_trap_h

//*****************************************************************************
// the includes
//*****************************************************************************
#include "hal.h"

#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
//defines
//*****************************************************************************
/*! @brief Defines the halt time before changing the motor direction  */
#define HALLTRAP_HALT_TIME_US      (1e6)

//*****************************************************************************
// typedefs
//*****************************************************************************
/*! @enum HALL*/
typedef enum
{
    /*! @brief Defines hall A */
    HALL_A = 0,
    /*! @brief Defines hall B */
    HALL_B,
    /*! @brief Defines hall C */
    HALL_C,
    /*! @brief Maximum hall signals */
    HALL_MAX
}HALL;

/*! @enum MOTOR_DIR*/
typedef enum
{
    /*! @brief Defines Motor Directions Forward */
    MOTOR_DIR_FORWARD = 0,
    /*! @brief Defines Motor Directions Reverse */
    MOTOR_DIR_REVERSE
}MOTOR_DIR;

/*! @enum MOTOR_BRAKE_TYPE*/
typedef enum
{
    /*! @brief Defines Motor Brake Type Coast */
    MOTOR_BRAKE_TYPE_COAST = 0,
    /*! @brief Defines Motor Brake Type Brake */
    MOTOR_BRAKE_TYPE_BRAKE
}MOTOR_BRAKE_TYPE;

/*! @enum MOTOR_STATE*/
typedef enum
{
    /*! @brief Defines Motor Run */
    MOTOR_STATE_RUN = 0,
    /*! @brief Defines Motor Stop */
    MOTOR_STATE_STOP
}MOTOR_STATE;

/*! @enum HALLTRAP_COMM_STATE */
typedef enum
{
    /**
     * @brief current from C to A in forward control
     * and A to C in reverse control, phase B is open
     */
    HALLTRAP_COMM_STATE_C_TO_A = 1,
    /**
     * @brief current from A to B in forward control
     * and B to A in reverse control, phase C is open
     */
    HALLTRAP_COMM_STATE_A_TO_B = 2,
    /**
     * @brief current from C to B in forward control
     * and B to C in reverse control, phase A is open
     */
    HALLTRAP_COMM_STATE_C_TO_B = 3,
    /**
     * @brief current from B to C in forward control
     * and C to B in reverse control, phase A is open
     */
    HALLTRAP_COMM_STATE_B_TO_C = 4,
    /**
     * @brief current from B to A in forward control
     * and A to B in reverse control, phase C is open
     */
    HALLTRAP_COMM_STATE_B_TO_A = 5,
    /**
     * @brief current from A to C in forward control
     * and C to A in reverse control, phase B is open
     */
    HALLTRAP_COMM_STATE_A_TO_C = 6
}HALLTRAP_COMM_STATE;

/*! @brief Defines a halltrap instance  */
typedef struct
{
    /*! @brief HALL A GPIO    */
    HAL_GPIO_IN hallA;
    /*! @brief HALL B GPIO    */
    HAL_GPIO_IN hallB;
    /*! @brief HALL C GPIO    */
    HAL_GPIO_IN hallC;
    /*! @brief Phase A timer    */
    HAL_PWM phaseA;
    /*! @brief Phase B timer    */
    HAL_PWM phaseB;
    /*! @brief Phase C timer    */
    HAL_PWM phaseC;
    /*! @brief input capture    */
    HAL_CAPTURE_TIMER captureInput;
}Halltrap_Instance;

//*****************************************************************************
// the function prototypes
//*****************************************************************************
/**
 * @brief   Initialize the halltrap module
 * @param[in] hallTrap   The halltrap instance
 */
void Halltrap_Init(Halltrap_Instance *hallTrap);

/**
 * @brief  Updates the PWM
 * @param[in] hallTrap The halltrap instance
 * @param[in] dir Motor direction of rotation
 * @param[in] pwmDuty PWMDuty in percentage
 */
void Halltrap_PWMUpdate(
        Halltrap_Instance *hallTrap, MOTOR_DIR dir, uint16_t pwmDuty);

/**
 * @brief Calculates motor speed
 * @param[in] hallTrap  The halltrap instance
 * @param[in] poles     Number of motor poles
 * @return Speed
 */
uint32_t Halltrap_calculateMotorSpeed(
        Halltrap_Instance *hallTrap, uint32_t poles);

/**
 * @brief  Sets the deadband in all phases
 * @param[in] hallTrap    The halltrap instance
 * @param[in] deadtime_ns Delay time in nanoseconds
 */
__STATIC_INLINE void Halltrap_setDeadband(
        Halltrap_Instance *hallTrap, uint16_t deadtime_ns)
{
    HAL_setDeadband(hallTrap->phaseA, deadtime_ns);
    HAL_setDeadband(hallTrap->phaseB, deadtime_ns);
    HAL_setDeadband(hallTrap->phaseC, deadtime_ns);
}

/**
 * @brief  Sets the pwm frequency in all phases
 * @param[in] hallTrap The halltrap instance
 * @param[in] pwmFreq The frequency of PWM
 */
__STATIC_INLINE void Halltrap_setPWMFreq(
        Halltrap_Instance *hallTrap, uint32_t pwmFreq)
{
    HAL_setPWMFreq(hallTrap->phaseA, pwmFreq);
    HAL_setPWMFreq(hallTrap->phaseB, pwmFreq);
    HAL_setPWMFreq(hallTrap->phaseC, pwmFreq);
}

/**
 * @brief  Stops the motor
 * @param[in] hallTrap     The halltrap instance
 * @param[in] brakeType    Type of braking applied
 */
__STATIC_INLINE void Halltrap_stopMotor(
        Halltrap_Instance *hallTrap, MOTOR_BRAKE_TYPE brakeType)
{
    if(brakeType == MOTOR_BRAKE_TYPE_COAST)
    {
        HAL_PWMOutputLow(hallTrap->phaseA, hallTrap->phaseB, hallTrap->phaseC);
    }
    else
    {
        HAL_PWMOutputHigh(hallTrap->phaseA, hallTrap->phaseB, hallTrap->phaseC);
    }
}

/**
 * @brief  Disable the PWM output
 * @param[in] hallTrap  The halltrap instance
 */
__STATIC_INLINE void Halltrap_disablePWM(Halltrap_Instance *hallTrap)
{
    HAL_PWMOutputLow(hallTrap->phaseA, hallTrap->phaseB, hallTrap->phaseC);
}

/**
 * @brief  Changes the motor direction
 * @param[in] hallTrap  The halltrap instance
 * @param[in] dir Motor direction of rotation
 */
__STATIC_INLINE void Halltrap_changeMotorDirection(
        Halltrap_Instance *hallTrap, MOTOR_DIR dir)
{
    HAL_PWMOutputLow(hallTrap->phaseA, hallTrap->phaseB, hallTrap->phaseC);
    /* motor is halted for 1 second to allow the freewheeling
     * currents to circulate
     */
    HAL_delayMicroSeconds(HALLTRAP_HALT_TIME_US);
    uint16_t pulseWidth = 0;
    Halltrap_PWMUpdate(hallTrap, dir, pulseWidth);
}

#ifdef __cplusplus
}
#endif
#endif /* hall_trap_h */
/** @}*/
