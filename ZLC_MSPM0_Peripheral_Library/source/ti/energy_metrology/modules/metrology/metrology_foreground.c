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
#include "metrology_defines.h"
#include "metrology_structs.h"
#include "metrology_calibration.h"
#include "metrology_calculations.h"
#include "metrology_foreground.h"
#include "metrology.h"

/*!
 * @brief    Calculate phase parameters
 * @param[in] workingData The metrology instance
 * @param[in] ph          phase number
 */
void Metrology_calculatePhaseReadings(metrologyData *workingData, PHASES ph)
{
    phaseMetrology *phase = &workingData->phases[ph];
    phaseCalibrationData *phaseCal = &calInfo->phases[ph];
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & VRMS_SUPPORT) == VRMS_SUPPORT)
    {
        phase->readings.RMSVoltage      = calculateRMSVoltage(phase, phaseCal);
        phase->params.V_dc_estimate_logged = calculateVdcEstimate(phase, phaseCal);
    }
    if((supportParams & IRMS_SUPPORT) == IRMS_SUPPORT)
    {
        phase->readings.RMSCurrent      = calculateRMSCurrent(phase, phaseCal);
        phase->params.current.I_dc_estimate_logged = calculateIdcEstimate(phase, phaseCal);
    }
    if((supportParams & ACTIVE_POWER_SUPPORT) == ACTIVE_POWER_SUPPORT)
    {
        phase->readings.activePower     = calculateActivePower(phase, phaseCal);
    }
    if((supportParams & REACTIVE_POWER_SUPPORT) == REACTIVE_POWER_SUPPORT)
    {
        phase->readings.reactivePower   = calculateReactivePower(phase, phaseCal);
    }
    if((supportParams & APPARENT_POWER_SUPPORT) == APPARENT_POWER_SUPPORT)
    {
        phase->readings.apparentPower   = calculateApparentPower(phase);
    }
    if((supportParams & FUNDAMENTAL_VRMS_SUPPORT) == FUNDAMENTAL_VRMS_SUPPORT)
    {
        phase->readings.FRMSVoltage     = calculateFundamentalRMSVoltage(phase, phaseCal);
    }
    if((supportParams & FUNDAMENTAL_ACTIVE_POWER_SUPPORT) == FUNDAMENTAL_ACTIVE_POWER_SUPPORT)
    {
        phase->readings.FActivePower    = calculateFundamentalActivePower(phase, phaseCal);
    }
    if((supportParams & FUNDAMENTAL_REACTIVE_POWER_SUPPORT) == FUNDAMENTAL_REACTIVE_POWER_SUPPORT)
    {
        phase->readings.FReactivePower  = calculateFundamentalReactivePower(phase, phaseCal);
    }
    if((supportParams & FUNDAMENTAL_APPARENT_POWER_SUPPORT) == FUNDAMENTAL_APPARENT_POWER_SUPPORT)
    {
        phase->readings.FApparentPower  = calculateFundamentalApparentPower(phase);
    }
    if((supportParams & FUNDAMENTAL_IRMS_SUPPORT) == FUNDAMENTAL_IRMS_SUPPORT)
    {
        phase->readings.FRMSCurrent     = calculateFundamentalRMSCurrent(phase, phaseCal);
    }
    if((supportParams & ACTIVE_ENERGY_SUPPORT) == ACTIVE_ENERGY_SUPPORT)
    {
        accumulateActiveEnergy(workingData, ph);
    }
    if((supportParams & REACTIVE_ENERGY_SUPPORT) == REACTIVE_ENERGY_SUPPORT)
    {
        accumulateReactiveEnergy(workingData, ph);
    }
    if((supportParams & FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT) == FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT)
    {
        accumulateFundamentalActiveEnergy(workingData, ph);
    }
    if((supportParams & FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT) == FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT)
    {
        accumulateFundamentalReactiveEnergy(workingData, ph);
    }
    if((supportParams & APPARENT_ENERGY_SUPPORT) == APPARENT_ENERGY_SUPPORT)
    {
        accumulateApparentEnergy(workingData, ph);
    }
    if((supportParams & FUNDAMENTAL_APPARENT_POWER_SUPPORT) == FUNDAMENTAL_APPARENT_POWER_SUPPORT)
    {
        accumulateFundamentalApparentEnergy(workingData, ph);
    }
    if((supportParams & POWER_FACTOR_SUPPORT) == POWER_FACTOR_SUPPORT)
    {
        phase->readings.powerFactor     = calculatePowerFactor(phase);
    }
    if((supportParams & POWER_FACTOR_ANGLE_SUPPORT) == POWER_FACTOR_ANGLE_SUPPORT)
    {
        phase->readings.powerFactorAngle = calculateAngleVoltagetoCurrent(phase);
    }
    if((supportParams & VOLTAGE_OVER_DEVIATION) == VOLTAGE_OVER_DEVIATION)
    {
        phase->readings.overdeviation   = calculateOverDeviation(phase);
    }
    if((supportParams & VOLTAGE_UNDER_DEVIATION) == VOLTAGE_UNDER_DEVIATION)
    {
        phase->readings.underdeviation  = calculateUnderDeviation(phase);
    }
    if((supportParams & VOLTAGE_THD_SUPPORT) == VOLTAGE_THD_SUPPORT)
    {
        phase->readings.voltageTHD      = calculateVoltageTHD(phase);
    }
    if((supportParams & CURRENT_THD_SUPPORT) == CURRENT_THD_SUPPORT)
    {
        phase->readings.currentTHD      = calculateCurrentTHD(phase);
    }
    if((supportParams & FREQUENCY_SUPPORT) == FREQUENCY_SUPPORT)
    {
        phase->readings.frequency       = calculateMainsfrequency(phase, phaseCal);
    }
}

/*!
 * @brief    Calculate three phase parameters
 * @param[in] workingData The metrology instance
 */
void Metrology_calculateThreePhaseParameters(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & LINETOLINE_VOLTAGE_SUPPORT) == LINETOLINE_VOLTAGE_SUPPORT)
    {
        readLinetoLineVoltage(workingData);
    }
    if((supportParams & FUNDAMENTAL_LINETOLINE_VOLTAGE_SUPPORT) == FUNDAMENTAL_LINETOLINE_VOLTAGE_SUPPORT)
    {
        readFundamentalLinetoLineVoltage(workingData);
    }
    if((supportParams & CURRENT_VECTOR_SUM) == CURRENT_VECTOR_SUM)
    {
        workingData->totals.currentVectorSum = calculateVectorCurrentSum(workingData);
    }
    if((supportParams & AGGREGATE_POWER_FACTOR) == AGGREGATE_POWER_FACTOR)
    {
        workingData->totals.powerFactor = calculateAggregatePowerfactor(workingData);
    }
}

/*!
 * @brief    Calculate total parameters
 * @param[in] workingData The metrology instance
 */
void Metrology_calculateTotalParameters(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_ACTIVE_POWER_SUPPORT) == TOTAL_ACTIVE_POWER_SUPPORT)
    {
        workingData->totals.readings.activePower = calculateTotalActivePower(workingData);
    }
    if((supportParams & TOTAL_REACTIVE_POWER_SUPPORT) == TOTAL_REACTIVE_POWER_SUPPORT)
    {
        workingData->totals.readings.reactivePower = calculateTotalReactivePower(workingData);
    }
    if((supportParams & TOTAL_APPARENT_POWER_SUPPORT) == TOTAL_APPARENT_POWER_SUPPORT)
    {
        workingData->totals.readings.apparentPower = calculateTotalApparentPower(workingData);
    }
    if((supportParams & TOTAL_FUNDAMENTAL_ACTIVE_POWER_SUPPORT) == TOTAL_FUNDAMENTAL_ACTIVE_POWER_SUPPORT)
    {
        workingData->totals.readings.fundamentalActivePower = calculateTotalFundamentalActivePower(workingData);
    }
    if((supportParams & TOTAL_FUNDAMENTAL_REACTIVE_POWER_SUPPORT) == TOTAL_FUNDAMENTAL_REACTIVE_POWER_SUPPORT)
    {
        workingData->totals.readings.fundamentalReactivePower = calculateTotalFundamentalReactivePower(workingData);
    }
    if((supportParams & TOTAL_FUNDAMENTAL_APPARENT_POWER_SUPPORT) == TOTAL_FUNDAMENTAL_APPARENT_POWER_SUPPORT)
    {
        workingData->totals.readings.fundamentalApparentPower = calculateTotalFundamentalApparentPower(workingData);
    }
}

/*!
 * @brief    Calculate neutral parameters
 * @param[in] workingData The metrology instance
 */
void Metrology_calculateNeutralReadings(metrologyData *workingData)
{
    neutralMetrology *neutral = &workingData->neutral;
    currentSensorCalibrationData *neutralCal = &calInfo->neutral;
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & NEUTRAL_MONITOR_SUPPORT) == NEUTRAL_MONITOR_SUPPORT)
    {
        neutral->readings.RMSCurrent = calculateNeutralRMSCurrent(neutral, neutralCal);
        neutral->params.I_dc_estimate_logged = calculateNeutralIdcEstimate(neutral, neutralCal);
    }
}

/*!
 * @brief    Sag Swell Detection
 * @param[in] workingData The metrology instance
 * @param[in] ph          phase number
 */
void Metrology_sagSwellDetection(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & SAG_SWELL_SUPPORT) == SAG_SWELL_SUPPORT)
    {
        checkSagSwellEvents(workingData, ph);
    }
}
