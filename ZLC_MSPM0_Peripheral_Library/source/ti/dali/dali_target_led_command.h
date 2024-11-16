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
/*!****************************************************************************
 *  @file       dali_target_led_command.h
 *  @brief      DALI LED Command List and Functionality
 *  @defgroup   DALI Library (DALI)
 *
 *  @anchor ti_dali_led_commands_overview
 *  # Overview
 *
 *  The DALI LED Commands and Functionality
 *
 *  <hr>
 ******************************************************************************/

#ifndef DALI_TARGET_LED_COMMAND_H_
#define DALI_TARGET_LED_COMMAND_H_

#include "dali_variables.h"

/**
 * @brief Operate as if gear accepted reference system power
 *
 * @note Feature of Load Deviation, which is not part of this implementation
 *
 *
 */
void DALI_LED_referenceSystemPower(void);

/**
 * @brief set desired dimming curve
 *
 * This function selects either a linear or logarithmic dimming curve
 * to increase/decrease the light level
 *
 */
void DALI_LED_selectDimmingCurve(void);

/**
 * @brief set fast fade time
 *
 * This function selects either a linear or logarithmic dimming curve
 * to increase/decrease the light level
 *
 */
void DALI_LED_setFastFadeTime(void);

/**
 * @brief transmit the control gear type back to the host
 *
 */
void DALI_LED_queryControlGearType(void);

/**
 * @brief transmit the selected dimming curve type back to the host
 *
 */
void DALI_LED_queryDimmingCurve(void);

/**
 * @brief transmit the available features back to the host
 *
 */
void DALI_LED_queryFeatures(void);

/**
 * @brief transmit the failure status back to the host
 *
 */
void DALI_LED_queryFailureStatus(void);

/**
 * @brief transmit the control gear type back to the host
 *
 */
void DALI_LED_queryLoadDecrease(void);

/**
 * @brief transmit the control gear type back to the host
 *
 */
void DALI_LED_queryLoadIncrease(void);

/**
 * @brief transmit if thermal gear/lamp shutdown occurred back to the host
 *
 */
void DALI_LED_queryThermalShutdown(void);

/**
 * @brief transmit if thermal gear/lamp overload occurred back to the host
 *
 */
void DALI_LED_queryThermalOverload(void);

/**
 * @brief transmit the control gear type back to the host
 *
 */
void DALI_LED_queryReferenceRunning(void);

/**
 * @brief transmit the control gear type back to the host
 *
 */
void DALI_LED_queryReferenceMeasurementFailed(void);

/**
 * @brief transmit the fast fade time back to the host
 *
 */
void DALI_LED_queryFastFadeTime(void);

/**
 * @brief transmit the minimum fast fade time back to the host
 *
 */
void DALI_LED_queryMinFastFadeTime(void);

/**
 * @brief transmit the extended version number back to the host
 *
 */
void DALI_LED_queryExtendedVersionNumber(void);

/**
 * @brief enables the control gear to execute LED specific commands
 *
 * This function sets a flag indicating that the control gear can execute any of the
 * LED specific functions per IEC 62386-207.  This flag resides in the LED Control Gear variable
 * that is stored within the overall control gear variable.
 */
void DALI_LED_enableDeviceType(void);

#endif /* DALI_TARGET_LED_COMMAND_H_ */
