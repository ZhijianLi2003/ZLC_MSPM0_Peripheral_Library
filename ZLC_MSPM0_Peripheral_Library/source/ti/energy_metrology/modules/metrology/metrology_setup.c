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
#include "metrology_setup.h"

/*!
 * @brief Metrology Init
 * @param[in] workingData The metrology data
 */
void Metrology_init(metrologyData *workingData)
{
    Metrology_initializeCalibrationData();
    Metrology_initNVData(workingData);
    Metrology_alignwithNVData(workingData);
}

/*!
 * @brief Metrology Init nv data
 * @param[in] workingData The metrology data
 */
void Metrology_initNVData(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    for(int ph=0; ph<MAX_PHASES; ph++)
    {
        phaseMetrology *phase = &workingData->phases[ph];
        phaseCalibrationData *phaseCal = &calInfo->phases[ph];

        phase->params.V_dc_estimate = _IQ19toIQ23(_IQ19div(phaseCal->VinitialDcEstimate, phaseCal->VscaleFactor));
        phase->params.current.I_dc_estimate = _IQ19toIQ23(_IQ19div(phaseCal->current.IinitialDcEstimate, phaseCal->current.IscaleFactor));
        phase->params.current.currentEndStops = ENDSTOP_HITS_FOR_OVERLOAD;
        phase->params.voltageEndStops = ENDSTOP_HITS_FOR_OVERLOAD;
        phase->params.voltagePeriod.period = (SAMPLES_PER_SECOND / MAINS_NOMINAL_FREQUENCY) << 8;
        phase->params.voltagePeriod.cyclePeriod = _IQ23div((int32_t)phase->params.voltagePeriod.period,256);
    }

    if((supportParams & NEUTRAL_MONITOR_SUPPORT) == NEUTRAL_MONITOR_SUPPORT)
    {
        workingData->neutral.params.I_dc_estimate = calInfo->neutral.IinitialDcEstimate;
        workingData->neutral.params.currentEndStops = ENDSTOP_HITS_FOR_OVERLOAD;
    }
}

/*!
 * @brief Metrology Align with nv data
 * @param[in] workingData The metrology data
 */
void Metrology_alignwithNVData(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;
    workingData->metrologyState |= METROLOGY_STATUS_PHASE_VOLTAGE_OK;

    for(int ph = 0; ph < MAX_PHASES; ph++)
    {
        phaseMetrology *phase = &workingData->phases[ph];
        phaseCalibrationData *phaseCal = &calInfo->phases[ph];

        Metrology_setPhaseCorrection(&phase->params.current.phaseCorrection, -phaseCal->current.phaseOffset);

        if(supportParams & SAG_SWELL_SUPPORT)
        {
            phase->params.sagThresholdStart     = _IQ19mpy(MAINS_NOMINAL_VOLTAGE_IQ19, _IQ19div((_IQ19(100) - _IQ19(SAG_THRESHOLD)), _IQ19(100)));
            phase->params.sagMinVoltage         = MIN_SAG_VOLTAGE;
            phase->params.sagThresholdStop      = phase->params.sagThresholdStart + SAG_HYSTERESIS;
            phase->params.swellThresholdStart   = _IQ19mpy(MAINS_NOMINAL_VOLTAGE_IQ19, _IQ19div((_IQ19(100) + _IQ19(SWELL_THRESHOLD)), _IQ19(100)));
            phase->params.swellThresholdStop    = phase->params.swellThresholdStart - SWELL_HYSTERESIS;
            phase->params.sagSwellState         = SAG_SWELL_VOLTAGE_NORMAL;
            phase->params.sagValue              = MAINS_NOMINAL_VOLTAGE_IQ19;
            phase->params.swellValue            = MAINS_NOMINAL_VOLTAGE_IQ19;
            phase->params.interruptionLevel     = _IQ15mpy(_IQ15div(_IQ15mpy(MIN_SAG_VOLTAGE, MIN_SAG_VOLTAGE),phaseCal->VscaleFactor), _IQ15div(phase->params.voltagePeriod.period, phaseCal->VscaleFactor));
            phase->params.interruptionLevelHalf = phase->params.interruptionLevel >> 1;
        }
    }

    if((supportParams & NEUTRAL_MONITOR_SUPPORT) == NEUTRAL_MONITOR_SUPPORT)
    {
        neutralMetrology *neutral = &workingData->neutral;
        currentSensorCalibrationData *neutralCal = &calInfo->neutral;
        Metrology_setPhaseCorrection(&neutral->params.phaseCorrection, -neutralCal->phaseOffset);
    }
    workingData->operatingMode = OPERATING_MODE_NORMAL;
}

/*!
 * @brief Set phase Correction
 * @param[in] phCorr The phase correction data
 * @param[in] correction correction value
 */
void Metrology_setPhaseCorrection(phaseCorrection *phCorr, int32_t correction)
{
    int tableEntry;

    correction += PHASE_SHIFT_FIR_TABLE_ELEMENTS >> 1;
    phCorr->step = I_HISTORY_STEPS + (correction / PHASE_SHIFT_FIR_TABLE_ELEMENTS);
    tableEntry = PHASE_SHIFT_FIR_TABLE_ELEMENTS - (correction % PHASE_SHIFT_FIR_TABLE_ELEMENTS);
    while(tableEntry >= PHASE_SHIFT_FIR_TABLE_ELEMENTS)
    {
        phCorr->step--;
        tableEntry -= PHASE_SHIFT_FIR_TABLE_ELEMENTS;
    }
    phCorr->firBeta = (phase_shift_fir_coeffs[tableEntry][0]);
    phCorr->firGain = (phase_shift_fir_coeffs[tableEntry][1]);
}

/*!
 * @brief Metrology Align with calibration data
 * @param[in] workingData The metrology data
 */
void Metrology_alignWithCalibrationData(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    for(int ph = 0; ph < MAX_PHASES; ph++)
    {
        phaseMetrology *phase = &workingData->phases[ph];
        phaseCalibrationData *phaseCal = &calInfo->phases[ph];
        Metrology_setPhaseCorrection(&phase->params.current.phaseCorrection, -phaseCal->current.phaseOffset);
    }

    if((supportParams & NEUTRAL_MONITOR_SUPPORT) == NEUTRAL_MONITOR_SUPPORT)
    {
        neutralMetrology *neutral = &workingData->neutral;
        currentSensorCalibrationData *neutralCal =&calInfo->neutral;
        Metrology_setPhaseCorrection(&neutral->params.phaseCorrection, -neutralCal->phaseOffset);
    }
}




