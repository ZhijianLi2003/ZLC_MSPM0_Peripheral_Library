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
#include "metrology_structs.h"
#include "metrology_readings.h"

/*!
 * @brief Read RMS Voltage
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return RMS voltage in milli volts (int32_t)
 */
int32_t Metrology_getRMSVoltage(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & VRMS_SUPPORT) == VRMS_SUPPORT)
    {
        return _IQ9mpyI32int(_IQ19toIQ9(workingData->phases[ph].readings.RMSVoltage), 1000);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read RMS Current
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return RMS Current in micro ampere (int32_t)
 */
int32_t Metrology_getRMSCurrent(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & IRMS_SUPPORT) == IRMS_SUPPORT)
    {
        return _IQ19mpy(workingData->phases[ph].readings.RMSCurrent, METROLOGY_IQ19_TO_MICROAMPS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read Active Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Active Power in milli watts (int32_t)
 */
int32_t Metrology_getActivePower(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & ACTIVE_POWER_SUPPORT) == ACTIVE_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->phases[ph].readings.activePower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read Reactive Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Reactive Power in milli VAR (int32_t)
 */
int32_t Metrology_getReactivePower(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & REACTIVE_POWER_SUPPORT) == REACTIVE_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->phases[ph].readings.reactivePower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read Apparent Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Apparent Power in milli VA (int32_t)
 */
int32_t Metrology_getApparentPower(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & APPARENT_POWER_SUPPORT) == APPARENT_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->phases[ph].readings.apparentPower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read Fundamental RMS Voltage
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental RMS Voltage in milli volts (int32_t)
 */
int32_t Metrology_getFundamentalRMSVoltage(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_VRMS_SUPPORT) == FUNDAMENTAL_VRMS_SUPPORT)
    {
        return _IQ9mpyI32int(_IQ19toIQ9(workingData->phases[ph].readings.FRMSVoltage), 1000);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read Fundamental RMS Current
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental RMS Current in micro ampere (int32_t)
 */
int32_t Metrology_getFundamentalRMSCurrent(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_IRMS_SUPPORT) == FUNDAMENTAL_IRMS_SUPPORT)
    {
        return _IQ19mpy(workingData->phases[ph].readings.FRMSCurrent, METROLOGY_IQ19_TO_MICROAMPS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read Fundamental Active Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental Active Power in milli watts (int32_t)
 */
int32_t Metrology_getFundamentalActivePower(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_ACTIVE_POWER_SUPPORT) == FUNDAMENTAL_ACTIVE_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->phases[ph].readings.FActivePower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read Fundamental Reactive Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental Reactive Power in milli VAR (int32_t)
 */
int32_t Metrology_getFundamentalReactivePower(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_REACTIVE_POWER_SUPPORT) == FUNDAMENTAL_REACTIVE_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->phases[ph].readings.FReactivePower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read Fundamental Apparent Power
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental Apparent Power in milli VA (int32_t)
 */
int32_t Metrology_getFundamentalApparentPower(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_APPARENT_POWER_SUPPORT) == FUNDAMENTAL_APPARENT_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->phases[ph].readings.FApparentPower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read phase power factor
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Power factor in steps of 0.0001 (int16_t)
 */
int16_t Metrology_getPowerFactor(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & POWER_FACTOR_SUPPORT) == POWER_FACTOR_SUPPORT)
    {
        return (int16_t)(_IQ13mpyI32int(workingData->phases[ph].readings.powerFactor, 10000));
    }
    else
    {
        return(0);
    }
}

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
int16_t Metrology_getAngleVoltagetoCurrent(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & POWER_FACTOR_ANGLE_SUPPORT) == POWER_FACTOR_ANGLE_SUPPORT)
    {
        return (int16_t)(workingData->phases[ph].readings.powerFactorAngle);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read voltage over deviation
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return voltage over deviation in steps of 0.01% (int16_t)
 */
int16_t Metrology_getOverDeviation(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & VOLTAGE_OVER_DEVIATION) == VOLTAGE_OVER_DEVIATION)
    {
        return (int16_t)(_IQ15mpyI32int(_IQ19toIQ15(workingData->phases[ph].readings.overdeviation), 100));
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read voltage under deviation
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return voltage under deviation in steps of 0.01% (int16_t)
 */
int16_t Metrology_getUnderDeviation(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & VOLTAGE_UNDER_DEVIATION) == VOLTAGE_UNDER_DEVIATION)
    {
        return (int16_t)(_IQ15mpyI32int(_IQ19toIQ15(workingData->phases[ph].readings.underdeviation), 100));
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read voltage THD
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return voltage THD in steps of 0.01% (int16_t)
 */
int16_t Metrology_getVoltageTHD(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & VOLTAGE_OVER_DEVIATION) == VOLTAGE_OVER_DEVIATION)
    {
        return (int16_t)(_IQ15mpyI32int(_IQ19toIQ15(workingData->phases[ph].readings.voltageTHD), 100));
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read current THD
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return current THD in steps of 0.01% (int16_t)
 */
int16_t Metrology_getCurrentTHD(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & VOLTAGE_OVER_DEVIATION) == VOLTAGE_OVER_DEVIATION)
    {
        return (int16_t)(_IQ15mpyI32int(_IQ19toIQ15(workingData->phases[ph].readings.currentTHD), 100));
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read mains frequency
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Mains frequency in steps of 0.01 (int16_t)
 */
int16_t Metrology_getMainsFrequency(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FREQUENCY_SUPPORT) == FREQUENCY_SUPPORT)
    {
        return (int16_t)(_IQ15mpyI32int(workingData->phases[ph].readings.frequency, 100));
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read maximum swell voltage
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Maximum swell voltage in milli volts (int32_t)
 */
int32_t Metrology_getMaxSwellValue(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & SAG_SWELL_SUPPORT) == SAG_SWELL_SUPPORT)
    {
        return _IQ9mpyI32int(_IQ19toIQ9(workingData->phases[ph].params.swellValue), 1000);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read minimum sag voltage
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Minimum sag voltage in milli volts (int32_t)
 */
int32_t Metrology_getMinSagValue(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & SAG_SWELL_SUPPORT) == SAG_SWELL_SUPPORT)
    {
        return _IQ9mpyI32int(_IQ19toIQ9(workingData->phases[ph].params.sagValue), 1000);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read number of sag events
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Number of sag events
 */
uint16_t Metrology_getSagEvents(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & SAG_SWELL_SUPPORT) == SAG_SWELL_SUPPORT)
    {
        return workingData->phases[ph].params.sagEvents;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read Sag duration
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Sag duration
 */
uint32_t Metrology_getSagDuration(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & SAG_SWELL_SUPPORT) == SAG_SWELL_SUPPORT)
    {
        return workingData->phases[ph].params.sagDuration;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read number of swell events
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Number of swell events
 */
uint16_t Metrology_getSwellEvents(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & SAG_SWELL_SUPPORT) == SAG_SWELL_SUPPORT)
    {
        return workingData->phases[ph].params.swellEvents;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read swell duration
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Swell duration
 */
uint32_t Metrology_getSwellDuration(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & SAG_SWELL_SUPPORT) == SAG_SWELL_SUPPORT)
    {
        return workingData->phases[ph].params.swellDuration;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read number of interruption events
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Number of interruption events
 */
uint16_t Metrology_getInterruptionEvents(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & SAG_SWELL_SUPPORT) == SAG_SWELL_SUPPORT)
    {
        return workingData->phases[ph].params.interruptionEvents;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read interruption duration
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return interruption duration
 */
uint32_t Metrology_getInterruptionDuration(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & SAG_SWELL_SUPPORT) == SAG_SWELL_SUPPORT)
    {
        return workingData->phases[ph].params.interruptionDuration;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total active power
 * @param[in] workingData The metrology instance
 * @return Total active power in milli watts (int32_t)
 */
int32_t Metrology_getTotalActivePower(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_ACTIVE_POWER_SUPPORT) == TOTAL_ACTIVE_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->totals.readings.activePower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total reactive power
 * @param[in] workingData The metrology instance
 * @return Total reactive power in milli VAR (int32_t)
 */
int32_t Metrology_getTotalReactivePower(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_REACTIVE_POWER_SUPPORT) == TOTAL_REACTIVE_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->totals.readings.reactivePower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total apparent power
 * @param[in] workingData The metrology instance
 * @return Total apparent power in milli VA (int32_t)
 */
int32_t Metrology_getTotalApparentPower(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_APPARENT_POWER_SUPPORT) == TOTAL_APPARENT_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->totals.readings.apparentPower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total fundamental active power
 * @param[in] workingData The metrology instance
 * @return Total fundamental active power in milli watts (int32_t)
 */
int32_t Metrology_getTotalFundamentalActivePower(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_FUNDAMENTAL_ACTIVE_POWER_SUPPORT) == TOTAL_FUNDAMENTAL_ACTIVE_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->totals.readings.fundamentalActivePower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total fundamental reactive power
 * @param[in] workingData The metrology instance
 * @return Total fundamental reactive power in milli VAR (int32_t)
 */
int32_t Metrology_getTotalFundamentalReactivePower(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_FUNDAMENTAL_REACTIVE_POWER_SUPPORT) == TOTAL_FUNDAMENTAL_REACTIVE_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->totals.readings.fundamentalReactivePower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total fundamental apparent power
 * @param[in] workingData The metrology instance
 * @return Total fundamental apparent power in milli VA (int32_t)
 */
int32_t Metrology_getTotalFundamentalApparentPower(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_FUNDAMENTAL_APPARENT_POWER_SUPPORT) == TOTAL_FUNDAMENTAL_APPARENT_POWER_SUPPORT)
    {
        return _IQ13mpy(workingData->totals.readings.fundamentalApparentPower, METROLOGY_IQ13_TO_MILLIWATTS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read active energy imported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Active energy imported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getActiveEnergyImported(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & ACTIVE_ENERGY_SUPPORT) == ACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.activeEnergyImported.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read active energy exported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Active energy exported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getActiveEnergyExported(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & ACTIVE_ENERGY_SUPPORT) == ACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.activeEnergyExported.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read fundamental active energy imported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental active energy imported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalActiveEnergyImported(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT) == FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.fundamentalActiveEnergyImported.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read fundamental active energy exported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental active energy exported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalActiveEnergyExported(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT) == FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.fundamentalActiveEnergyExported.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read reactive energy frist quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Reactive energy frist quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getReactiveEnergyFirstQuadrant(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & REACTIVE_ENERGY_SUPPORT) == REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.reactiveEnergyQuardrantI.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read reactive energy second quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Reactive energy second quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getReactiveEnergySecondQuadrant(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & REACTIVE_ENERGY_SUPPORT) == REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.reactiveEnergyQuardrantII.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read reactive energy third quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Reactive energy third quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getReactiveEnergyThirdQuadrant(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & REACTIVE_ENERGY_SUPPORT) == REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.reactiveEnergyQuardrantIII.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read reactive energy fourth quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Reactive energy fourth quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getReactiveEnergyFourthQuadrant(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & REACTIVE_ENERGY_SUPPORT) == REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.reactiveEnergyQuardrantIV.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read fundamental reactive energy frist quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental reactive energy frist quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalReactiveEnergyFirstQuadrant(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT) == FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.fundamentalReactiveEnergyQuardrantI.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read fundamental reactive energy second quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental reactive energy second quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalReactiveEnergySecondQuadrant(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT) == FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.fundamentalReactiveEnergyQuardrantII.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read fundamental reactive energy third quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental reactive energy third quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalReactiveEnergyThirdQuadrant(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT) == FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.fundamentalReactiveEnergyQuardrantIII.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read fundamental reactive energy fourth quadrant
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental reactive energy fourth quadrant in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalReactiveEnergyFourthQuadrant(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT) == FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.fundamentalReactiveEnergyQuardrantIV.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read apparent energy imported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Apparent energy imported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getApparentEnergyImported(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & APPARENT_ENERGY_SUPPORT) == APPARENT_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.appparentEnergyImported.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read apparent energy exported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Apparent energy exported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getApparentEnergyExported(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & APPARENT_ENERGY_SUPPORT) == APPARENT_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.appparentEnergyExported.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read fundamental apparent energy imported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental apparent energy imported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalApparentEnergyImported(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_APPARENT_ENERGY_SUPPORT) == FUNDAMENTAL_APPARENT_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.fundamentalAppparentEnergyImported.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read fundamental apparent energy exported
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return Fundamental apparent energy exported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getFundamentalApparentEnergyExported(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_APPARENT_ENERGY_SUPPORT) == FUNDAMENTAL_APPARENT_ENERGY_SUPPORT)
    {
        return workingData->phases[ph].energy.fundamentalAppparentEnergyExported.energy;
    }
    else
    {
        return (0);
    }
}

/*!
 * @brief Read DC voltage estimate
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return DC voltage estimate in volts (IQ8 format)
 */
_iq8 Metrology_getVdcEstimate(metrologyData *workingData, PHASES ph)
{
    return _IQ19toIQ8(workingData->phases[ph].params.V_dc_estimate_logged);
}

/*!
 * @brief Read DC current estimate
 * @param[in] workingData The metrology instance
 * @param[in] ph          Phase number
 * @return DC current estimate in amps (IQ8 format)
 */
_iq8 Metrology_getIdcEstimate(metrologyData *workingData, PHASES ph)
{
    return _IQ19toIQ8(workingData->phases[ph].params.current.I_dc_estimate_logged);
}

/*!
 * @brief Read Neutral DC current estimate
 * @param[in] workingData The metrology instance
 * @return Neutral DC current estimate in amps (IQ8 format)
 */
_iq8 Metrology_getNeutralIdcEstimate(metrologyData *workingData)
{
    return _IQ19toIQ8(workingData->neutral.params.I_dc_estimate_logged);
}

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
int16_t Metrology_getPhasetoPhaseAngle(metrologyData *workingData, PHASES ph)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & POWER_FACTOR_ANGLE_SUPPORT) == POWER_FACTOR_ANGLE_SUPPORT)
    {
        return (int16_t)(workingData->phases[ph].readings.phasetoPhaseAngle);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total active energy imported
 * @param[in] workingData The metrology instance
 * @return Total active energy imported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getTotalActiveEnergyImported(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_ACTIVE_ENERGY_SUPPORT) == TOTAL_ACTIVE_ENERGY_SUPPORT)
    {
        return workingData->totals.energy.activeEnergyImported.energy;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total active energy exported
 * @param[in] workingData The metrology instance
 * @return Total active energy exported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getTotalActiveEnergyExported(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_ACTIVE_ENERGY_SUPPORT) == TOTAL_ACTIVE_ENERGY_SUPPORT)
    {
        return workingData->totals.energy.activeEnergyExported.energy;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total fundamental active energy imported
 * @param[in] workingData The metrology instance
 * @return Total fundamental active energy imported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getTotalFundamentalActiveEnergyImported(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT) == TOTAL_FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT)
    {
        return workingData->totals.energy.fundamentalActiveEnergyImported.energy;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total fundamental active energy exported
 * @param[in] workingData The metrology instance
 * @return Total fundamental active energy exported in 100milli watt-hr (uint64_t)
 */
uint64_t Metrology_getTotalFundamentalActiveEnergyExported(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT) == TOTAL_FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT)
    {
        return workingData->totals.energy.fundamentalActiveEnergyExported.energy;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total reactive energy in quadrant I
 * @param[in] workingData The metrology instance
 * @return Total reactive energy in quadrant I in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getTotalReactiveEnergyFirstQuadrant(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_REACTIVE_ENERGY_SUPPORT) == TOTAL_REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->totals.energy.reactiveEnergyQuardrantI.energy;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total reactive energy in quadrant II
 * @param[in] workingData The metrology instance
 * @return Total reactive energy in quadrant II in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getTotalReactiveEnergySecondQuadrant(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_REACTIVE_ENERGY_SUPPORT) == TOTAL_REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->totals.energy.reactiveEnergyQuardrantII.energy;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total reactive energy in quadrant III
 * @param[in] workingData The metrology instance
 * @return Total reactive energy in quadrant III in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getTotalReactiveEnergyThirdQuadrant(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_REACTIVE_ENERGY_SUPPORT) == TOTAL_REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->totals.energy.reactiveEnergyQuardrantIII.energy;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total reactive energy in quadrant IV
 * @param[in] workingData The metrology instance
 * @return Total reactive energy in quadrant IV in 100milli VAR-hr (uint64_t)
 */
uint64_t Metrology_getTotalReactiveEnergyFourthQuadrant(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_REACTIVE_ENERGY_SUPPORT) == TOTAL_REACTIVE_ENERGY_SUPPORT)
    {
        return workingData->totals.energy.reactiveEnergyQuardrantIV.energy;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total apparent energy imported
 * @param[in] workingData The metrology instance
 * @return Total apparent energy imported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getTotalApparentEnergyImported(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_APPARENT_ENERGY_SUPPORT) == TOTAL_APPARENT_ENERGY_SUPPORT)
    {
        return workingData->totals.energy.appparentEnergyImported.energy;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read total apparent energy exported
 * @param[in] workingData The metrology instance
 * @return Total apparent energy exported in 100milli VA-hr (uint64_t)
 */
uint64_t Metrology_getTotalApparentEnergyExported(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & TOTAL_APPARENT_ENERGY_SUPPORT) == TOTAL_APPARENT_ENERGY_SUPPORT)
    {
        return workingData->totals.energy.appparentEnergyExported.energy;
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read line to line voltage phase 0 to phase 1
 * @param[in] workingData The metrology instance
 * @return Phase 0 to Phase 1 line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getLinetoLineVoltagePhase0toPhase1(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & LINETOLINE_VOLTAGE_SUPPORT) == LINETOLINE_VOLTAGE_SUPPORT)
    {
        return _IQ9mpyI32int(_IQ19toIQ9(workingData->LLReadings.LLRMSVoltage_ab), 1000);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read line to line voltage phase 1 to phase 2
 * @param[in] workingData The metrology instance
 * @return Phase 1 to Phase 2 line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getLinetoLineVoltagePhase1toPhase2(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & LINETOLINE_VOLTAGE_SUPPORT) == LINETOLINE_VOLTAGE_SUPPORT)
    {
        return _IQ9mpyI32int(_IQ19toIQ9(workingData->LLReadings.LLRMSVoltage_bc), 1000);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read line to line voltage phase 2 to phase 0
 * @param[in] workingData The metrology instance
 * @return Phase 2 to Phase 0 line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getLinetoLineVoltagePhase2toPhase0(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & LINETOLINE_VOLTAGE_SUPPORT) == LINETOLINE_VOLTAGE_SUPPORT)
    {
        return _IQ9mpyI32int(_IQ19toIQ9(workingData->LLReadings.LLRMSVoltage_ca), 1000);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read fundamental line to line voltage phase 0 to phase 1
 * @param[in] workingData The metrology instance
 * @return Phase 0 to Phase 1 fundamental line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getFundamentalLinetoLineVoltagePhase0toPhase1(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_LINETOLINE_VOLTAGE_SUPPORT) == FUNDAMENTAL_LINETOLINE_VOLTAGE_SUPPORT)
    {
        return _IQ9mpyI32int(_IQ19toIQ9(workingData->LLReadings.FLLRMSVoltage_ab), 1000);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read fundamental line to line voltage phase 1 to phase 2
 * @param[in] workingData The metrology instance
 * @return Phase 0 to Phase 1 fundamental line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getFundamentalLinetoLineVoltagePhase1toPhase2(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_LINETOLINE_VOLTAGE_SUPPORT) == FUNDAMENTAL_LINETOLINE_VOLTAGE_SUPPORT)
    {
        return _IQ9mpyI32int(_IQ19toIQ9(workingData->LLReadings.FLLRMSVoltage_bc), 1000);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read fundamental line to line voltage phase 2 to phase0
 * @param[in] workingData The metrology instance
 * @return Phase 0 to Phase 1 fundamental line to line voltage in milli volts (int32_t)
 */
int32_t Metrology_getFundamentalLinetoLineVoltagePhase2toPhase0(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & FUNDAMENTAL_LINETOLINE_VOLTAGE_SUPPORT) == FUNDAMENTAL_LINETOLINE_VOLTAGE_SUPPORT)
    {
        return _IQ9mpyI32int(_IQ19toIQ9(workingData->LLReadings.FLLRMSVoltage_ca), 1000);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read current vector sum
 * @param[in] workingData The metrology instance
 * @return current vector sum in micro ampere (int32_t)
 */
int32_t Metrology_getCurrentVectorSum(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & CURRENT_VECTOR_SUM) == CURRENT_VECTOR_SUM)
    {
        return _IQ19mpy(workingData->totals.currentVectorSum, METROLOGY_IQ19_TO_MICROAMPS);
    }
    else
    {
        return(0);
    }
}

/*!
 * @brief Read raw active power
 * @param[in] workingData The metrology instance
 * @param[in] samples  pointer to store number of samples
 * @param[in] ph       The phase number
 * @return Raw active power
 */
int64_t Metrology_getRawActivePower(metrologyData *workingData, uint16_t *samples, PHASES ph)
{
    *samples = (int16_t) workingData->phases[ph].params.current.dotProd[1].sampleCount;
    return((int64_t) _IQ13toF(workingData->phases[ph].params.current.dotProd[1].activePower));
}

/*!
 * @brief Read raw reactive power
 * @param[in] workingData The metrology instance
 * @param[in] samples  pointer to store number of samples
 * @param[in] ph       The phase number
 * @return Raw reactive power
 */
int64_t Metrology_getRawReactivePower(metrologyData *workingData, uint16_t *samples, PHASES ph)
{
    *samples = (int16_t) workingData->phases[ph].params.current.dotProd[1].sampleCount;
    return((int64_t) _IQ15toF(workingData->phases[ph].params.current.dotProd[1].reactivePower));
}

/*!
 * @brief Read Neutral RMS Current
 * @param[in] workingData The metrology instance
 * @return Neutral RMS Current in micro ampere in micro ampere (int32_t)
 */
int32_t Metrology_getNeutralRMSCurrent(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    if((supportParams & NEUTRAL_MONITOR_SUPPORT) == NEUTRAL_MONITOR_SUPPORT)
    {
        return _IQ19mpy(workingData->neutral.readings.RMSCurrent, METROLOGY_IQ19_TO_MICROAMPS);
    }
    else
    {
        return(0);
    }
}


