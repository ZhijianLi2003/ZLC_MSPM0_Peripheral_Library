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
 *  @file       metrology_readings.h
 *  @brief      APIs to read the metrology readings
 *
 *  @anchor metrology_readings_h
 *  # Overview
 *
 *  APIs to read the metrology readings
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup Metrology
 * @{
 */

#ifndef METROLOGY_READINGS_H_
#define METROLOGY_READINGS_H_

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Defines conversion factor from IQ19 to micro amps
 *
 * current in micro amps = current in IQ19 * 1000000 / 2pow(19)
 */
#define METROLOGY_IQ19_TO_MICROAMPS     _IQ19(1.9073486328125)

/*!
 * @brief Defines conversion factor from IQ13 to milli watts
 *
 * power in milli watts = power in IQ13 * 1000 / 2pow(13)
 */
#define METROLOGY_IQ13_TO_MILLIWATTS    _IQ13(0.1220703125)

/*!
 * @brief Read RMS Voltage
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return RMS voltage in milli volts (int32_t)
 */
int32_t Metrology_getRMSVoltage(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read RMS Current
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return RMS Current in micro ampere (int32_t)
 */
int32_t Metrology_getRMSCurrent(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read Active Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Active Power in milli watts (int32_t)
 */
int32_t Metrology_getActivePower(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read Reactive Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Reactive Power in milli VAR (int32_t)
 */
int32_t Metrology_getReactivePower(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read Apparent Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Apparent Power in milli VA (int32_t)
 */
int32_t Metrology_getApparentPower(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read Fundamental RMS Voltage
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental RMS Voltage in milli volts (int32_t)
 */
int32_t Metrology_getFundamentalRMSVoltage(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read Fundamental RMS Current
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental RMS Current in micro ampere (int32_t)
 */
int32_t Metrology_getFundamentalRMSCurrent(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read Fundamental Active Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental Active Power in milli watts (int32_t)
 */
int32_t Metrology_getFundamentalActivePower(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read Fundamental Reactive Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental Reactive Power in milli VAR (int32_t)
 */
int32_t Metrology_getFundamentalReactivePower(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read Fundamental Apparent Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental Apparent Power in milli VA (int32_t)
 */
int32_t Metrology_getFundamentalApparentPower(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read phase power factor
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Power factor in steps of 0.0001 (int16_t)
 */
int16_t Metrology_getPowerFactor(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read phase power factor angle
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Power factor angle in per units (int16_t)
 *         0x0000 corresponds to 0 degrees
 *         0x7FFF corresponds to 179.99 degrees
 *         0x8000 corresponds to -180 degrees
 *
 *         Conversion inside GUI
 *         angle in degrees = angle * 180 / 2^15
 */
int16_t Metrology_getAngleVoltagetoCurrent(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read voltage over deviation
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return voltage over deviation in steps of 0.01% (int16_t)
 */
int16_t Metrology_getOverDeviation(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read voltage under deviation
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return voltage under deviation in steps of 0.01% (int16_t)
 */
int16_t Metrology_getUnderDeviation(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read voltage THD
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return voltage THD in steps of 0.01% (int16_t)
 */
int16_t Metrology_getVoltageTHD(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read current THD
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return current THD in steps of 0.01% (int16_t)
 */
int16_t Metrology_getCurrentTHD(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read mains frequency
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Mains frequency in steps of 0.01 (int16_t)
 */
int16_t Metrology_getMainsFrequency(metrologyData *workingData, PHASES ph);


/*!
 * @brief Read maximum swell voltage
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Maximum swell voltage in milli volts (int32_t)
 */
int32_t Metrology_getMaxSwellValue(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read minimum sag voltage
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Minimum sag voltage in milli volts (int32_t)
 */
int32_t Metrology_getMinSagValue(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read number of sag events
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Number of sag events
 */
uint16_t Metrology_getSagEvents(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read Sag duration
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Sag duration
 */
uint32_t Metrology_getSagDuration(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read number of swell events
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Number of swell events
 */
uint16_t Metrology_getSwellEvents(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read swell duration
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Swell duration
 */
uint32_t Metrology_getSwellDuration(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read number of interruption events
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Number of interruption events
 */
uint16_t Metrology_getInterruptionEvents(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read interruption duration
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return interruption duration
 */
uint32_t Metrology_getInterruptionDuration(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read total active power
 * @param[in] workingData The metrology instance
 * @return Total active power in milli watts (int32_t)
 */
int32_t Metrology_getTotalActivePower(metrologyData *workingData);

/*!
 * @brief Read total reactive power
 * @param[in] workingData The metrology instance
 * @return Total reactive power in milli VAR (int32_t)
 */
int32_t Metrology_getTotalReactivePower(metrologyData *workingData);

/*!
 * @brief Read total apparent power
 * @param[in] workingData The metrology instance
 * @return Total apparent power in milli VA (int32_t)
 */
int32_t Metrology_getTotalApparentPower(metrologyData *workingData);

/*!
 * @brief Read total fundamental active power
 * @param[in] workingData The metrology instance
 * @return Total fundamental active power in milli watts (int32_t)
 */
int32_t Metrology_getTotalFundamentalActivePower(metrologyData *workingData);

/*!
 * @brief Read total fundamental reactive power
 * @param[in] workingData The metrology instance
 * @return Total fundamental reactive power in milli VAR (int32_t)
 */
int32_t Metrology_getTotalFundamentalReactivePower(metrologyData *workingData);

/*!
 * @brief Read total fundamental apparent power
 * @param[in] workingData The metrology instance
 * @return Total fundamental apparent power in milli VA (int32_t)
 */
int32_t Metrology_getTotalFundamentalApparentPower(metrologyData *workingData);

/*!
 * @brief Read active energy imported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Active energy imported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getActiveEnergyImported(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read active energy exported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Active energy exported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getActiveEnergyExported(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read fundamental active energy imported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental active energy imported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalActiveEnergyImported(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read fundamental active energy exported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental active energy exported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalActiveEnergyExported(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read reactive energy frist quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Reactive energy frist quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getReactiveEnergyFirstQuadrant(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read reactive energy second quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Reactive energy second quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getReactiveEnergySecondQuadrant(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read reactive energy third quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Reactive energy third quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getReactiveEnergyThirdQuadrant(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read reactive energy fourth quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Reactive energy fourth quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getReactiveEnergyFourthQuadrant(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read fundamental reactive energy frist quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental reactive energy frist quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalReactiveEnergyFirstQuadrant(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read fundamental reactive energy second quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental reactive energy second quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalReactiveEnergySecondQuadrant(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read fundamental reactive energy third quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental reactive energy third quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalReactiveEnergyThirdQuadrant(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read fundamental reactive energy fourth quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental reactive energy fourth quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalReactiveEnergyFourthQuadrant(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read apparent energy imported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Apparent energy imported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getApparentEnergyImported(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read apparent energy exported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Apparent energy exported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getApparentEnergyExported(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read fundamental apparent energy imported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental apparent energy imported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalApparentEnergyImported(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read fundamental apparent energy exported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental apparent energy exported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalApparentEnergyExported(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read DC voltage estimate
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return DC voltage estimate in volts (IQ8 format)
 */
_iq8 Metrology_getVdcEstimate(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read DC current estimate
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return DC current estimate in amps (IQ8 format)
 */
_iq8 Metrology_getIdcEstimate(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read Neutral DC current estimate
 * @param[in] workingData The metrology instance
 * @return Neutral DC current estimate in amps (IQ8 format)
 */
_iq8 Metrology_getNeutralIdcEstimate(metrologyData *workingData);

/*!
 * @brief Read Phase to phase angle
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Phase to Phase angle in per units (int16_t)
 *         0x0000 corresponds to 0 degrees
 *         0x7FFF corresponds to 179.99 degrees
 *         0x8000 corresponds to -180 degrees
 *
 *         Conversion inside GUI
 *         angle in degrees = angle * 180 / 2^15
 */
int16_t Metrology_getPhasetoPhaseAngle(metrologyData *workingData, PHASES ph);

/*!
 * @brief Read total active energy imported
 * @param[in] workingData The metrology instance
 * @return Total active energy imported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getTotalActiveEnergyImported(metrologyData *workingData);

/*!
 * @brief Read total active energy exported
 * @param[in] workingData The metrology instance
 * @return Total active energy exported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getTotalActiveEnergyExported(metrologyData *workingData);

/*!
 * @brief Read total fundamental active energy imported
 * @param[in] workingData The metrology instance
 * @return Total fundamental active energy imported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getTotalFundamentalActiveEnergyImported(metrologyData *workingData);

/*!
 * @brief Read total fundamental active energy exported
 * @param[in] workingData The metrology instance
 * @return Total fundamental active energy exported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getTotalFundamentalActiveEnergyExported(metrologyData *workingData);

/*!
 * @brief Read total reactive energy in quadrant I
 * @param[in] workingData The metrology instance
 * @return Total reactive energy in quadrant I in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getTotalReactiveEnergyFirstQuadrant(metrologyData *workingData);


/*!
 * @brief Read total reactive energy in quadrant II
 * @param[in] workingData The metrology instance
 * @return Total reactive energy in quadrant II in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getTotalReactiveEnergySecondQuadrant(metrologyData *workingData);

/*!
 * @brief Read total reactive energy in quadrant III
 * @param[in] workingData The metrology instance
 * @return Total reactive energy in quadrant III in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getTotalReactiveEnergyThirdQuadrant(metrologyData *workingData);


/*!
 * @brief Read total reactive energy in quadrant IV
 * @param[in] workingData The metrology instance
 * @return Total reactive energy in quadrant IV in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getTotalReactiveEnergyFourthQuadrant(metrologyData *workingData);

/*!
 * @brief Read total apparent energy imported
 * @param[in] workingData The metrology instance
 * @return Total apparent energy imported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getTotalApparentEnergyImported(metrologyData *workingData);

/*!
 * @brief Read total apparent energy exported
 * @param[in] workingData The metrology instance
 * @return Total apparent energy exported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getTotalApparentEnergyExported(metrologyData *workingData);

/*!
 * @brief Read line to line voltage phase 0 to phase 1
 * @param[in] workingData The metrology instance
 * @return Phase 0 to Phase 1 line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getLinetoLineVoltagePhase0toPhase1(metrologyData *workingData);

/*!
 * @brief Read line to line voltage phase 1 to phase 2
 * @param[in] workingData The metrology instance
 * @return Phase 1 to Phase 2 line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getLinetoLineVoltagePhase1toPhase2(metrologyData *workingData);

/*!
 * @brief Read line to line voltage phase 2 to phase 0
 * @param[in] workingData The metrology instance
 * @return Phase 2 to Phase 0 line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getLinetoLineVoltagePhase2toPhase0(metrologyData *workingData);

/*!
 * @brief Read fundamental line to line voltage phase 0 to phase 1
 * @param[in] workingData The metrology instance
 * @return Phase 0 to Phase 1 fundamental line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getFundamentalLinetoLineVoltagePhase0toPhase1(metrologyData *workingData);

/*!
 * @brief Read fundamental line to line voltage phase 1 to phase 2
 * @param[in] workingData The metrology instance
 * @return Phase 0 to Phase 1 fundamental line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getFundamentalLinetoLineVoltagePhase1toPhase2(metrologyData *workingData);

/*!
 * @brief Read fundamental line to line voltage phase 2 to phase0
 * @param[in] workingData The metrology instance
 * @return Phase 0 to Phase 1 fundamental line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getFundamentalLinetoLineVoltagePhase2toPhase0(metrologyData *workingData);

/*!
 * @brief Read current vector sum
 * @param[in] workingData The metrology instance
 * @return current vector sum in micro ampere (int32_t)
 */
int32_t Metrology_getCurrentVectorSum(metrologyData *workingData);

/*!
 * @brief Read raw active power
 * @param[in] workingData The metrology instance
 * @param[in] samples  pointer to store number of samples
 * @param[in] ph       The phase number
 * @return Raw active power
 */
int64_t Metrology_getRawActivePower(metrologyData *workingData, uint16_t *samples, PHASES ph);

/*!
 * @brief Read raw reactive power
 * @param[in] workingData The metrology instance
 * @param[in] samples  pointer to store number of samples
 * @param[in] ph       The phase number
 * @return Raw reactive power
 */
int64_t Metrology_getRawReactivePower(metrologyData *workingData, uint16_t *samples, PHASES ph);

/*!
 * @brief Read Neutral RMS Current
 * @param[in] workingData The metrology instance
 * @return Neutral RMS Current in micro ampere in micro ampere (int32_t)
 */
int32_t Metrology_getNeutralRMSCurrent(metrologyData *workingData);

#ifdef __cplusplus
}
#endif
#endif /* METROLOGY_READINGS_H_ */
/** @}*/
