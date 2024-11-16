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
#include "hall_trap.h"

//*****************************************************************************
// the internal function prototypes
//*****************************************************************************
void Halltrap_PWMUpdateForward(Halltrap_Instance *hallTrap,
                               uint16_t pwmDuty,
                               HALLTRAP_COMM_STATE commState);

void Halltrap_PWMUpdateReverse(Halltrap_Instance *hallTrap,
                               uint16_t pwmDuty,
                               HALLTRAP_COMM_STATE commState);

/**
 * @brief   Initialize the halltrap module
 * @param[in] hallTrap   The halltrap instance
 */
void Halltrap_Init(Halltrap_Instance *hallTrap)
{
    /* enable the hall sensor gpio interrupt    */
    HAL_enableGPIOInterrupt(hallTrap->hallA);
    HAL_enableGPIOInterrupt(hallTrap->hallB);
    HAL_enableGPIOInterrupt(hallTrap->hallC);

    HAL_enableCaptureInterrupt(hallTrap->captureInput);
}

/**
 * @brief     updates the pwm when driving in forward direction
 * @param[in] hallTrap   The halltrap instance
 * @param[in] pwmDuty    The pwmduty
 * @param[in] commState  The commutation state
 */
void Halltrap_PWMUpdateForward(Halltrap_Instance *hallTrap,
                               uint16_t pwmDuty,
                               HALLTRAP_COMM_STATE commState)
{
    HAL_PWM posPhase;
    HAL_PWM gndPhase;
    HAL_PWM opnPhase;

/**
 * Commutation table for Trapezoidal control in forward direction
 * ===========================|===============|===============|==============
 *          HALL_STATE        | MOTOR_PAHSE_A | MOTOR_PHASE_B | MOTOR_PHASE_C
 * ===========================|===============|===============|==============
 * HALLTRAP_COMM_STATE_B_TO_A |    gndPhase   |    posPhase   |   opnPhase
 * HALLTRAP_COMM_STATE_C_TO_A |    gndPhase   |    opnPhase   |   posPhase
 * HALLTRAP_COMM_STATE_C_TO_B |    opnPhase   |    gndPhase   |   posPhase
 * HALLTRAP_COMM_STATE_A_TO_B |    posPhase   |    gndPhase   |   opnPhase
 * HALLTRAP_COMM_STATE_A_TO_C |    posPhase   |    opnPhase   |   gndPhase
 * HALLTRAP_COMM_STATE_B_TO_C |    opnPhase   |    posPhase   |   gndPhase
 */

    switch (commState)
    {
    case HALLTRAP_COMM_STATE_B_TO_A:
        posPhase = hallTrap->phaseB;
        gndPhase = hallTrap->phaseA;
        opnPhase = hallTrap->phaseC;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
    break;
    case HALLTRAP_COMM_STATE_C_TO_A:
        posPhase = hallTrap->phaseC;
        gndPhase = hallTrap->phaseA;
        opnPhase = hallTrap->phaseB;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
    break;
    case HALLTRAP_COMM_STATE_C_TO_B:
        posPhase = hallTrap->phaseC;
        gndPhase = hallTrap->phaseB;
        opnPhase = hallTrap->phaseA;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
    break;
    case HALLTRAP_COMM_STATE_A_TO_B:
        posPhase = hallTrap->phaseA;
        gndPhase = hallTrap->phaseB;
        opnPhase = hallTrap->phaseC;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
    break;
    case HALLTRAP_COMM_STATE_A_TO_C:
        posPhase = hallTrap->phaseA;
        gndPhase = hallTrap->phaseC;
        opnPhase = hallTrap->phaseB;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
    break;
    case HALLTRAP_COMM_STATE_B_TO_C:
        posPhase = hallTrap->phaseB;
        gndPhase = hallTrap->phaseC;
        opnPhase = hallTrap->phaseA;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
    break;
    default:
        /* This is expected to be empty */
    break;
    }
}

/**
 * @brief     updates the pwm when driving in reverse direction
 * @param[in] hallTrap   The halltrap instance
 * @param[in] pwmDuty    The pwmduty
 * @param[in] commState  The commutation state
 */
void Halltrap_PWMUpdateReverse(Halltrap_Instance *hallTrap,
                               uint16_t pwmDuty,
                               HALLTRAP_COMM_STATE commState)
{
    HAL_PWM posPhase;
    HAL_PWM gndPhase;
    HAL_PWM opnPhase;

/**
 * Commutation table for Trapezoidal control in reverse direction
 * ===========================|===============|===============|==============
 *          HALL_STATE        | MOTOR_PAHSE_A | MOTOR_PHASE_B | MOTOR_PHASE_C
 * ===========================|===============|===============|==============
 * HALLTRAP_COMM_STATE_B_TO_A |    posPhase   |    gndPhase   |   opnPhase
 * HALLTRAP_COMM_STATE_C_TO_A |    posPhase   |    opnPhase   |   gndPhase
 * HALLTRAP_COMM_STATE_C_TO_B |    opnPhase   |    posPhase   |   gndPhase
 * HALLTRAP_COMM_STATE_A_TO_B |    gndPhase   |    posPhase   |   opnPhase
 * HALLTRAP_COMM_STATE_A_TO_C |    gndPhase   |    opnPhase   |   posPhase
 * HALLTRAP_COMM_STATE_B_TO_C |    opnPhase   |    gndPhase   |   posPhase
 */

    switch (commState)
    {
    case HALLTRAP_COMM_STATE_B_TO_A:
        posPhase = hallTrap->phaseA;
        gndPhase = hallTrap->phaseB;
        opnPhase = hallTrap->phaseC;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
        break;
    case HALLTRAP_COMM_STATE_C_TO_A:
        posPhase = hallTrap->phaseA;
        gndPhase = hallTrap->phaseC;
        opnPhase = hallTrap->phaseB;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
        break;
    case HALLTRAP_COMM_STATE_C_TO_B:
        posPhase = hallTrap->phaseB;
        gndPhase = hallTrap->phaseC;
        opnPhase = hallTrap->phaseA;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
        break;
    case HALLTRAP_COMM_STATE_A_TO_B:
        posPhase = hallTrap->phaseB;
        gndPhase = hallTrap->phaseA;
        opnPhase = hallTrap->phaseC;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
        break;
    case HALLTRAP_COMM_STATE_A_TO_C:
        posPhase = hallTrap->phaseC;
        gndPhase = hallTrap->phaseA;
        opnPhase = hallTrap->phaseB;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
        break;
    case HALLTRAP_COMM_STATE_B_TO_C:
        posPhase = hallTrap->phaseC;
        gndPhase = hallTrap->phaseB;
        opnPhase = hallTrap->phaseA;
        HAL_updatePWM(posPhase, gndPhase, opnPhase, pwmDuty);
        break;
    default:
        /* This is expected to be empty */
        break;
    }
}

/**
 * @brief  Updates the PWM
 * @param[in] hallTrap The halltrap instance
 * @param[in] dir Motor direction of rotation
 * @param[in] pwmDuty PWMDuty in percentage
 */
void Halltrap_PWMUpdate(
        Halltrap_Instance *hallTrap, MOTOR_DIR dir, uint16_t pwmDuty)
{
    uint8_t sensorStatus[HALL_MAX];

    sensorStatus[HALL_A] = HAL_readGPIOPin(hallTrap->hallA);
    sensorStatus[HALL_B] = HAL_readGPIOPin(hallTrap->hallB);
    sensorStatus[HALL_C] = HAL_readGPIOPin(hallTrap->hallC);

    HALLTRAP_COMM_STATE commState = (HALLTRAP_COMM_STATE)(
            (sensorStatus[HALL_A]) + (sensorStatus[HALL_B] * 2) + (sensorStatus[HALL_C] * 4));

    if(dir == MOTOR_DIR_FORWARD)
    {
        Halltrap_PWMUpdateForward(hallTrap, pwmDuty, commState);
    }
    else
    {
        Halltrap_PWMUpdateReverse(hallTrap, pwmDuty, commState);
    }
}

/**
 * @brief Calculates motor speed
 * @param[in] hallTrap  The halltrap instance
 * @param[in] poles     Number of motor poles
 * @return Speed
 */
uint32_t Halltrap_calculateMotorSpeed(
        Halltrap_Instance *hallTrap, uint32_t poles)
{
    uint32_t frequency = HAL_getCaptureFrequency(hallTrap->captureInput);

    /*
     * interrupt is captured twice in one cycle.
     * speed = (120 * frequency / poles)/2
     */
    return (60*frequency/poles);
}



