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
 *  @file       metrology_calculations.h
 *  @brief      API's releated to metrology calculations
 *
 *  @anchor metrology_calculations_h
 *  # Overview
 *
 *  API's releated to metrology calculations in metrology module
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup Metrology
 * @{
 */

#ifndef _METROLOGY_CALCULATIONS_H_
#define _METROLOGY_CALCULATIONS_H_

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief calculate RMS Voltage
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return  RMS Voltage in volts (IQ19 format)
 */
_iq19 calculateRMSVoltage(phaseMetrology *phase, phaseCalibrationData *phaseCal);

/*!
 * @brief calculate RMS Current
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return RMS Current in amps (IQ19 format)
 */
_iq19 calculateRMSCurrent(phaseMetrology *phase, phaseCalibrationData *phaseCal);

/*!
 * @brief calculate active power
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Active Power in watts (IQ13 format)
 */
_iq13 calculateActivePower(phaseMetrology *phase, phaseCalibrationData *phaseCal);

/*!
 * @brief calculate active power
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Reactive Power in VAR (IQ13 format)
 */
_iq13 calculateReactivePower(phaseMetrology *phase, phaseCalibrationData *phaseCal);

/*!
 * @brief calculate apparent power
 * @param[in] phase    The phase metrology
 * @return Apparent Power in VA (IQ13 format)
 */
_iq13 calculateApparentPower(phaseMetrology *phase);

/*!
 * @brief calculate fundamental RMS Voltage
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Fundamental RMS Voltage in volts (IQ19 format)
 */
_iq19 calculateFundamentalRMSVoltage(phaseMetrology *phase, phaseCalibrationData *phaseCal);

/*!
 * @brief calculate fundamental RMS Current
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Fundamental RMS Current in amps (IQ19 format)
 */
_iq19 calculateFundamentalRMSCurrent(phaseMetrology *phase, phaseCalibrationData *phaseCal);

/*!
 * @brief calculate fundamental active Power
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Fundamental Active Power in watts (IQ13 format)
 */
_iq13 calculateFundamentalActivePower(phaseMetrology *phase, phaseCalibrationData *phaseCal);

/*!
 * @brief calculate fundamental reactive Power
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Fundamental Reactive Power in VAR (IQ13 format)
 */
_iq13 calculateFundamentalReactivePower(phaseMetrology *phase, phaseCalibrationData *phaseCal);

/*!
 * @brief calculate fundamental apparent Power
 * @param[in] phase    The phase metrology
 * @return Fundamental Apparent Power in VA (IQ13 format)
 */
_iq13 calculateFundamentalApparentPower(phaseMetrology *phase);

/*!
 * @brief accumulate active energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateActiveEnergy(metrologyData *workingData, PHASES ph);

/*!
 * @brief accumulate reactive energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateReactiveEnergy(metrologyData *workingData, PHASES ph);

/*!
 * @brief accumulate appparent energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateApparentEnergy(metrologyData *workingData, PHASES ph);

/*!
 * @brief accumulate fundamental active energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateFundamentalActiveEnergy(metrologyData *workingData, PHASES ph);

/*!
 * @brief accumulate fundamental reactive energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateFundamentalReactiveEnergy(metrologyData *workingData, PHASES ph);

/*!
 * @brief accumulate fundamental apparent energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateFundamentalApparentEnergy(metrologyData *workingData, PHASES ph);

/*!
 * @brief calculate power factor
 * @param[in] phase  The phase metrology
 * @return Power factor (IQ13 format)
 */
_iq13 calculatePowerFactor(phaseMetrology *phase);

/*!
 * @brief calculate power factor angle
 * @param[in] phase  The phase metrology
 * @return Power factor angle in per unit with base value of 180 degrees(3.14 radians)
 *         180 degrees corresponds to 1
 *         -180 degrees corresponds to -1
 */
_iq15 calculateAngleVoltagetoCurrent(phaseMetrology *phase);

/*!
 * @brief calculate voltage over deviation
 * @param[in] phase  The phase metrology
 * @return Voltage over deviation in percentage (IQ19 format)
 */
_iq19 calculateOverDeviation(phaseMetrology *phase);

/*!
 * @brief calculate voltage under deviation
 * @param[in] phase  The phase metrology
 * @return Voltage under deviation in percentage (IQ19 format)
 */
_iq19 calculateUnderDeviation(phaseMetrology *phase);

/*!
 * @brief calculate voltage THD
 * @param[in] phase  The phase metrology
 * @return Voltage THD in percentage (IQ19 format)
 */
_iq19 calculateVoltageTHD(phaseMetrology *phase);

/*!
 * @brief calculate current THD
 * @param[in] phase  The phase metrology
 * @return Current THD in percentage (IQ19 format)
 */
_iq19 calculateCurrentTHD(phaseMetrology *phase);

/*!
 * @brief calculate mains frequency
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Mains Frequency (IQ15 format)
 */
_iq15 calculateMainsfrequency(phaseMetrology *phase, phaseCalibrationData *phaseCal);

/*!
 * @brief    Calculate total active power
 * @param[in] workingData The metrology instance
 * @return Total Active Power in watts (IQ13 format)
 */
_iq13 calculateTotalActivePower(metrologyData *workingData);

/*!
 * @brief    Calculate total reactive power
 * @param[in] workingData The metrology instance
 * @return Total Reactive Power in VAR (IQ13 format)
 */
_iq13 calculateTotalReactivePower(metrologyData *workingData);

/*!
 * @brief    Calculate total apparent power
 * @param[in] workingData The metrology instance
 * @return Total Apparent Power in VA (IQ13 format)
 */
_iq13 calculateTotalApparentPower(metrologyData *workingData);

/*!
 * @brief    Calculate total fundamental active power
 * @param[in] workingData The metrology instance
 * @return Total Fundamental Active Power in watts (IQ13 format)
 */
_iq13 calculateTotalFundamentalActivePower(metrologyData *workingData);

/*!
 * @brief    Calculate total fundamental reactive power
 * @param[in] workingData The metrology instance
 * @return Total Fundamental Reactive Power in VAR (IQ13 format)
 */
_iq13 calculateTotalFundamentalReactivePower(metrologyData *workingData);

/*!
 * @brief    Calculate total fundamental apparent power
 * @param[in] workingData The metrology instance
 * @return Total Fundamental Apparent Power in VA (IQ13 format)
 */
_iq13 calculateTotalFundamentalApparentPower(metrologyData *workingData);

/*!
 * @brief    Calculate line to line voltage
 * @param[in] phase1  The phase1 metrology
 * @param[in] phase2  The phase2 metrology
 * @return    line to line voltage in volts (IQ19 format)
 */
_iq19 calculateLinetoLineVoltage(phaseMetrology *phase1, phaseMetrology *phase2);

/*!
 * @brief    Calculate fundamental line to line voltage
 * @param[in] phase1  The phase1 metrology
 * @param[in] phase2  The phase2 metrology
 * @return    fundamental line to line voltage in volts (IQ19 format)
 */
_iq19 calculateFundamentalLinetoLineVoltage(phaseMetrology *phase1, phaseMetrology *phase2);

/*!
 * @brief    Calculate aggregate power factor
 * @param[in] workingData The metrology instance
 * @return Aggregate power factor in IQ13 format
 */
_iq13 calculateAggregatePowerfactor(metrologyData *workingData);

/*!
 * @brief    Calculate current vector sum
 * @param[in] workingData The metrology instance
 * @return Current vector sum in amps (IQ19 format)
 */
_iq19 calculateVectorCurrentSum(metrologyData *workingData);

/*!
 * @brief calculate Neutral RMS Current
 * @param[in] neutral    The neutral metrology
 * @param[in] neutralCal The neutral calibration data
 * @return Neutral RMS current in amps (IQ19 format)
 */
_iq19 calculateNeutralRMSCurrent(neutralMetrology *neutral, currentSensorCalibrationData *neutralCal);

/*!
 * @brief    Read Line to Line Voltage
 * param[in] workingData The metrology instance
 */
void readLinetoLineVoltage(metrologyData *workingData);

/*!
 * @brief    Read Fundamental Line to Line Voltage
 * param[in] workingData The metrology instance
 */
void readFundamentalLinetoLineVoltage(metrologyData *workingData);

/*!
 * @brief Integrate Power to Energy
 * @param[in] en          The energy instance
 * @param[in] power       Power
 * @param[in] samples     Number of samples
 * @return energy steps
 */
uint64_t integratePowertoEnergy(energyIntegrator *en, _iq13 power, uint32_t samples);

/*!
 * @brief Cycle RMS Voltage Calculation
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 * @return cycle RMS Voltage in volts (IQ19 format)
 */
_iq19 calculateCycleRMSVoltage(metrologyData *workingData, PHASES ph);

/*!
 * @brief Check for sag swell events
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void checkSagSwellEvents(metrologyData *workingData, PHASES ph);

/*!
 * @brief calculate dc estimate voltage
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return  DC Estimate Voltage in volts (IQ19 format)
 */
_iq19 calculateVdcEstimate(phaseMetrology *phase, phaseCalibrationData *phaseCal);

/*!
 * @brief calculate dc estimate current
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return  DC Estimate current in amps (IQ19 format)
 */
_iq19 calculateIdcEstimate(phaseMetrology *phase, phaseCalibrationData *phaseCal);

/*!
 * @brief calculate neutral dc estimate current
 * @param[in] neutral    The neutral metrology
 * @param[in] neutralCal The neutral calibration data
 * @return  Neutral DC Estimate current in amps (IQ19 format)
 */
_iq19 calculateNeutralIdcEstimate(neutralMetrology *neutral, currentSensorCalibrationData *neutralCal);

#ifdef __cplusplus
}
#endif
#endif /* _METROLOGY_CALCULATIONS_H_ */
/** @}*/
