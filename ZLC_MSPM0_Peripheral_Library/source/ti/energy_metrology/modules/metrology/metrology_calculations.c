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
#include "metrology_setup.h"
#include "metrology_calibration.h"
#include "metrology_calculations.h"

//*****************************************************************************
// Global Functions
//*****************************************************************************

/*!
 * @brief isqrt64()
 *        64-bit Square root function
 * @param[in]  h value
 * @return square root of input value in Q32 format
 */
uint64_t isqrt64(uint64_t h)
{
    uint64_t x = 0;
    uint64_t y = 0;
    int i;
    /* The answer is calculated as a 64 bit value, where the last
       32 bits are fractional.
       Calling with negative numbers is not a good idea :-) */
    for (i = 0;  i < 64;  i++)
    {
        x = (x << 1) | 1;
        if (y < x)
            x -= 2;
        else
            y -= x;
        x++;
        y <<= 1;
        if ((h & 0x8000000000000000ULL))
            y |= 1;
        h <<= 1;
        y <<= 1;
        if ((h & 0x8000000000000000ULL))
            y |= 1;
        h <<= 1;
    }
    return  x;
}

/*!
 * @brief calculate RMS Voltage
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return  RMS Voltage in volts (IQ19 format)
 */
_iq19 calculateRMSVoltage(phaseMetrology *phase, phaseCalibrationData *phaseCal)
{
    _iq19 RMSVoltage;

    if(phase->status & PHASE_STATUS_V_OVERRANGE)
    {
        /* input voltage is out of range    */
        return RMS_VOLTAGE_OVERRANGE;
    }

    /* index of the dot product currently set for foreground processing */
    int8_t dp = phase->params.dpSet;
    voltageDPSet *voltage = &phase->params.dotProd[dp];

    if(!voltage->sampleCount)
    {
        /* Number of samples is zero    */
        RMSVoltage = 0;
    }
    else
    {
        int64_t sqrms = voltage->voltageSq/voltage->sampleCount;

        /* We are doing the calculations in 64 bit to avoid any truncation errors(when input
         * is a low value)
         * For better accuracy we are using 64 bit isqrt64(). it results in 64 bit in which
         * LSB 32 bits is fraction part, MSB 32 bits it integer part. The rms after sqrt is a
         * 24 bit result stored in MSB 32 bits. Right shifting by 24 bits, the required
         * 24 bits are not lost when type casted to 32 bit and after typecasting the result
         * will be in IQ31 format.
         */
        int32_t rms = isqrt64(sqrms) >> 24;

        /*
         * Multiplying rms(IQ31) and scalefactor(IQ19) as integer multiplication and right
         * shifting by 31 will give the result in IQ19 format
         */
        RMSVoltage = (rms * (int64_t)(phaseCal->VscaleFactor)) >> 31;

        if(RMSVoltage < phaseCal->VacOffset)
        {
            /* RMS voltage is smaller than offset error */
            RMSVoltage = 0;
        }
        else
        {
            RMSVoltage -= phaseCal->VacOffset;
        }
    }
    return RMSVoltage;
}

/*!
 * @brief calculate RMS Current
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return RMS Current in amps (IQ19 format)
 */
_iq19 calculateRMSCurrent(phaseMetrology *phase, phaseCalibrationData *phaseCal)
{
    _iq19 RMSCurrent;

    if(phase->status & PHASE_STATUS_I_OVERRANGE)
    {
        /* Input current is out of range    */
        return RMS_CURRENT_OVERRANGE;
    }

    /* index of the dot product currently set for foreground processing */
    int8_t dp = phase->params.dpSet;
    currentDPSet *current = &phase->params.current.dotProd[dp];

    if(!current->sampleCount)
    {
        /* Number of samples is zero    */
        RMSCurrent = 0;
    }
    else
    {
        int64_t sqrms = current->currentSq/current->sampleCount;

        /* We are doing the calculations in 64 bit to avoid any truncation errors(when input
         * is a low value)
         * For better accuracy we are using 64 bit isqrt64(). it results in 64 bit in which
         * LSB 32 bits is fraction part, MSB 32 bits it integer part. The rms after sqrt is a
         * 24 bit result stored in MSB 32 bits. Right shifting by 24 bits, the required
         * 24 bits are not lost when type casted to 32 bit and after typecasting the result
         * will be in IQ31 format.
         */
        int32_t rms = isqrt64(sqrms) >> 24;

        /*
         * Multiplying rms(IQ31) and scalefactor(IQ19) as integer multiplication and right
         * shifting by 31 will give the result in IQ19 format
         */
        RMSCurrent = (rms * (int64_t)(phaseCal->current.IscaleFactor)) >> 31;

        if(RMSCurrent < phaseCal->current.IacOffset)
        {
            /* RMS current is smaller than offset error */
            RMSCurrent = 0;
        }
        else
        {
            RMSCurrent -= phaseCal->current.IacOffset;
        }
    }
    return RMSCurrent;
}

/*!
 * @brief calculate active power
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Active Power in watts (IQ13 format)
 */
_iq13 calculateActivePower(phaseMetrology *phase, phaseCalibrationData *phaseCal)
{
    _iq13 activePower;

    if(phase->status & (PHASE_STATUS_V_OVERRANGE | PHASE_STATUS_I_OVERRANGE))
    {
        /* Input voltage or current is out of range */
        return POWER_OVERRANGE;
    }

    /* index of the dot product currently set for foreground processing */
    int8_t dp = phase->params.dpSet;
    currentDPSet *current = &phase->params.current.dotProd[dp];

    if(!current->sampleCount)
    {
        /* Number of samples is zero    */
        activePower = 0;
    }
    else
    {
        int64_t actpower = current->activePower/ current->sampleCount;
        actpower >>= 13;
        int64_t scaling = ((int64_t)phaseCal->current.PscaleFactor * phase->params.current.phaseCorrection.firGain) >> 14;
        activePower = (actpower * scaling) >> 30;
    }
    return (activePower);
}

/*!
 * @brief calculate active power
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Reactive Power in VAR (IQ13 format)
 */
_iq13 calculateReactivePower(phaseMetrology *phase, phaseCalibrationData *phaseCal)
{
    _iq13 reactivePower;

    if(phase->status & (PHASE_STATUS_V_OVERRANGE | PHASE_STATUS_I_OVERRANGE))
    {
        /* Input voltage or current is out of range */
        return POWER_OVERRANGE;
    }

    /* index of the dot product currently set for foreground processing */
    int8_t dp = phase->params.dpSet;

    currentDPSet *current = &phase->params.current.dotProd[dp];

    if(!phase->params.current.dotProd[dp].sampleCount)
    {
        /* Number of samples is zero    */
        reactivePower = 0;
    }
    else
    {
        int64_t reactpower = current->reactivePower/ current->sampleCount;
        reactpower >>= 13;
        int64_t scaling = ((int64_t)phaseCal->current.PscaleFactor * phase->params.current.quadratureCorrection.firGain) >> 14;
        reactivePower = (reactpower * scaling) >> 30;
    }
    return reactivePower;
}

/*!
 * @brief calculate apparent power
 * @param[in] phase    The phase metrology
 * @return Apparent Power in VA (IQ13 format)
 */
_iq13 calculateApparentPower(phaseMetrology *phase)
{
    return _IQ13mag(phase->readings.activePower, phase->readings.reactivePower);
}

/*!
 * @brief calculate fundamental RMS Voltage
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Fundamental RMS Voltage in volts (IQ19 format)
 */
_iq19 calculateFundamentalRMSVoltage(phaseMetrology *phase, phaseCalibrationData *phaseCal)
{
    _iq19 FRMSVoltage;

    if(phase->status & PHASE_STATUS_V_OVERRANGE)
    {
        return RMS_VOLTAGE_OVERRANGE;
    }

    /* index of the dot product currently set for foreground processing */
    int8_t dp = phase->params.dpSet;
    voltageDPSet *voltage = &phase->params.dotProd[dp];

    /* Fundamental RMS Voltage Calculation  */
    if(!phase->params.dotProd[dp].sampleCount)
    {
        FRMSVoltage = 0;
    }
    else
    {
        int64_t fVoltage = voltage->fVoltageSq/voltage->sampleCount;
        int64_t scaling = ((int64_t)phaseCal->VscaleFactor * phase->params.current.phaseCorrection.firGain)>>27;
        FRMSVoltage = (fVoltage * scaling) >> 32;
        FRMSVoltage = _IQ19div(FRMSVoltage, _IQ19sqrt(_IQ19(2)));

        if (FRMSVoltage < phaseCal->VFundamentalAcOffset)
        {
            FRMSVoltage = 0;
        }
        else
        {
            FRMSVoltage -=phaseCal->VFundamentalAcOffset;
        }
    }
    /* negative value is an error   */
    if(FRMSVoltage < 0)
    {
        FRMSVoltage = 0;
    }
    return FRMSVoltage;
}

/*!
 * @brief calculate fundamental RMS Current
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Fundamental RMS Current in amps (IQ19 format)
 */
_iq19 calculateFundamentalRMSCurrent(phaseMetrology *phase, phaseCalibrationData *phaseCal)
{
    _iq19 FRMSCurrent;

    if(phase->status & PHASE_STATUS_I_OVERRANGE)
    {
        return RMS_CURRENT_OVERRANGE;
    }

    /* avoid dividing by 0 and negative value voltages  */
    if(phase->readings.FRMSVoltage <= 0)
    {
        FRMSCurrent = 0;
    }
    else
    {
        /* Fundamental RMS current calculation  */
        FRMSCurrent = _IQ13toIQ19(_IQ13div(phase->readings.FApparentPower, _IQ19toIQ13(phase->readings.FRMSVoltage)));
        /* Calibration  */
        if(FRMSCurrent < phaseCal->current.IFAcOffset)
        {
            FRMSCurrent = 0;
        }
        else
        {
            FRMSCurrent -= phaseCal->current.IFAcOffset;
        }
    }
    return FRMSCurrent;
}


/*!
 * @brief calculate fundamental active Power
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Fundamental Active Power in watts (IQ13 format)
 */
_iq13 calculateFundamentalActivePower(phaseMetrology *phase, phaseCalibrationData *phaseCal)
{
    _iq13 FActivePower;

    if(phase->status & (PHASE_STATUS_V_OVERRANGE | PHASE_STATUS_I_OVERRANGE))
    {
        return POWER_OVERRANGE;
    }

    /* index of the dot product currently set for foreground processing */
    int8_t dp = phase->params.dpSet;
    currentDPSet *current = &phase->params.current.dotProd[dp];

    /* Fundamental Active Power Calculation */
    if(!current->sampleCount)
    {
        FActivePower = 0;
    }
    else
    {
        int64_t factpower = current->FActivePower/current->sampleCount;
        factpower >>= 12;
        int64_t scaling1 = (phase->params.dotProd[dp].fVoltageSq/phase->params.current.dotProd[dp].sampleCount);
        scaling1 >>= 24;
        int64_t scaling = (scaling1 * phaseCal->current.PscaleFactor) >> 28;
        scaling = (scaling * phase->params.current.phaseCorrection.firGain) >> 14;
        FActivePower = (factpower * scaling) >> 24;
    }
    return FActivePower;
}

/*!
 * @brief calculate fundamental reactive Power
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Fundamental Reactive Power in VAR (IQ13 format)
 */
_iq13 calculateFundamentalReactivePower(phaseMetrology *phase, phaseCalibrationData *phaseCal)
{
    _iq13 FReactivePower;

    if(phase->status & (PHASE_STATUS_V_OVERRANGE | PHASE_STATUS_I_OVERRANGE))
    {
        return POWER_OVERRANGE;
    }

    int8_t dp = phase->params.dpSet;
    currentDPSet *current = &phase->params.current.dotProd[dp];

    if(!current->sampleCount)
    {
        FReactivePower = 0;
    }
    else
    {
       int64_t freactpower = current->FReactivePower/current->sampleCount;
       freactpower >>= 12;
       int64_t scaling1 = (phase->params.dotProd[dp].fVoltageSq/phase->params.current.dotProd[dp].sampleCount);
       scaling1 >>= 24;
       int64_t scaling = (scaling1 * phaseCal->current.PscaleFactor) >> 28;
       scaling = (scaling * phase->params.current.phaseCorrection.firGain) >> 14;
       FReactivePower = (freactpower * scaling) >> 24;
    }
    return FReactivePower;
}

/*!
 * @brief calculate fundamental apparent Power
 * @param[in] phase    The phase metrology
 * @return Fundamental Apparent Power in VA (IQ13 format)
 */
_iq13 calculateFundamentalApparentPower(phaseMetrology *phase)
{
    return _IQ13mag(phase->readings.FActivePower, phase->readings.FReactivePower);
}

/*!
 * @brief accumulate active energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateActiveEnergy(metrologyData *workingData, PHASES ph)
{
    phaseMetrology *phase = &workingData->phases[ph];
    totalParams *total = &workingData->totals;
    int8_t dp = phase->params.dpSet;
    volatile uint64_t energy;

    _iq13 power = _IQ13abs(phase->readings.activePower);
    if(phase->readings.activePower >= 0)
    {
        energy = integratePowertoEnergy(&phase->energy.activeEnergyImported, power, phase->params.current.dotProd[dp].sampleCount);
        if(energy)
        {
            phase->energy.activeEnergyImported.energy += energy;
            total->energy.activeEnergyImported.energy += energy;
        }
    }
    else
    {
        energy = integratePowertoEnergy(&phase->energy.activeEnergyExported, power, phase->params.current.dotProd[dp].sampleCount);
        if(energy)
        {
            phase->energy.activeEnergyExported.energy += energy;
            total->energy.activeEnergyExported.energy += energy;
        }
    }
}

/*!
 * @brief accumulate reactive energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateReactiveEnergy(metrologyData *workingData, PHASES ph)
{
    phaseMetrology *phase = &workingData->phases[ph];
    totalParams *total = &workingData->totals;
    int8_t dp = phase->params.dpSet;
    volatile uint64_t energy;

    _iq13 power = _IQ13abs(phase->readings.reactivePower);
    if(phase->readings.reactivePower >= 0)
    {
        if(phase->readings.activePower >= 0)
        {
            energy = integratePowertoEnergy(&phase->energy.reactiveEnergyQuardrantI, power, phase->params.current.dotProd[dp].sampleCount);
            if(energy)
            {
                phase->energy.reactiveEnergyQuardrantI.energy += energy;
                total->energy.reactiveEnergyQuardrantI.energy += energy;
            }
        }
        else
        {
            energy = integratePowertoEnergy(&phase->energy.reactiveEnergyQuardrantII, power, phase->params.current.dotProd[dp].sampleCount);
            if(energy)
            {
                phase->energy.reactiveEnergyQuardrantII.energy += energy;
                total->energy.reactiveEnergyQuardrantII.energy += energy;
            }
        }
    }
    else
    {
        if(phase->readings.activePower >= 0)
        {
            energy = integratePowertoEnergy(&phase->energy.reactiveEnergyQuardrantIV, power, phase->params.current.dotProd[dp].sampleCount);
            if(energy)
            {
                phase->energy.reactiveEnergyQuardrantIV.energy += energy;
                total->energy.reactiveEnergyQuardrantIV.energy += energy;
            }
        }
        else
        {
            energy = integratePowertoEnergy(&phase->energy.reactiveEnergyQuardrantIII, power, phase->params.current.dotProd[dp].sampleCount);
            if(energy)
            {
                phase->energy.reactiveEnergyQuardrantIII.energy += energy;
                total->energy.reactiveEnergyQuardrantIII.energy += energy;
            }
        }
    }
}

/*!
 * @brief accumulate appparent energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateApparentEnergy(metrologyData *workingData, PHASES ph)
{
    phaseMetrology *phase = &workingData->phases[ph];
    totalParams *total = &workingData->totals;
    int8_t dp = phase->params.dpSet;
    volatile uint64_t energy;

    _iq13 power = _IQ13abs(phase->readings.apparentPower);
    if(phase->readings.apparentPower >= 0)
    {
        energy = integratePowertoEnergy(&phase->energy.appparentEnergyImported, power, phase->params.current.dotProd[dp].sampleCount);
        if(energy)
        {
            phase->energy.appparentEnergyImported.energy += energy;
            total->energy.appparentEnergyImported.energy += energy;
        }
    }
    else
    {
        energy = integratePowertoEnergy(&phase->energy.appparentEnergyExported, power, phase->params.current.dotProd[dp].sampleCount);
        if(energy)
        {
            phase->energy.appparentEnergyExported.energy += energy;
            total->energy.appparentEnergyExported.energy += energy;
        }
    }
}

/*!
 * @brief accumulate fundamental active energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateFundamentalActiveEnergy(metrologyData *workingData, PHASES ph)
{
    phaseMetrology *phase = &workingData->phases[ph];
    totalParams *total = &workingData->totals;
    int8_t dp = phase->params.dpSet;
    volatile uint64_t energy;

    _iq13 power = _IQ13abs(phase->readings.FActivePower);
    if(phase->readings.FActivePower >= 0)
    {
        energy = integratePowertoEnergy(&phase->energy.fundamentalActiveEnergyImported, power, phase->params.current.dotProd[dp].sampleCount);
        if(energy)
        {
            phase->energy.fundamentalActiveEnergyImported.energy += energy;
            total->energy.fundamentalActiveEnergyImported.energy += energy;
        }
    }
    else
    {
        energy = integratePowertoEnergy(&phase->energy.fundamentalActiveEnergyExported, power, phase->params.current.dotProd[dp].sampleCount);
        if(energy)
        {
            phase->energy.fundamentalActiveEnergyExported.energy += energy;
            total->energy.fundamentalActiveEnergyExported.energy += energy;
        }
    }
}

/*!
 * @brief accumulate fundamental reactive energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateFundamentalReactiveEnergy(metrologyData *workingData, PHASES ph)
{
    phaseMetrology *phase = &workingData->phases[ph];
    totalParams *total = &workingData->totals;
    int8_t dp = phase->params.dpSet;
    volatile uint64_t energy;

    _iq13 power = _IQabs(phase->readings.FReactivePower);
    if(phase->readings.FReactivePower >= 0)
    {
        if(phase->readings.activePower >= 0)
        {
            energy = integratePowertoEnergy(&phase->energy.fundamentalReactiveEnergyQuardrantI, power, phase->params.current.dotProd[dp].sampleCount);
            if(energy)
            {
                phase->energy.fundamentalReactiveEnergyQuardrantI.energy += energy;
                total->energy.fundamentalReactiveEnergyQuardrantI.energy += energy;
            }
        }
        else
        {
            energy = integratePowertoEnergy(&phase->energy.fundamentalReactiveEnergyQuardrantII, power, phase->params.current.dotProd[dp].sampleCount);
            if(energy)
            {
                phase->energy.fundamentalReactiveEnergyQuardrantII.energy += energy;
                total->energy.fundamentalReactiveEnergyQuardrantII.energy += energy;
            }
        }
    }
    else
    {
        if(phase->readings.activePower >= 0)
        {
            energy = integratePowertoEnergy(&phase->energy.fundamentalReactiveEnergyQuardrantIV, power, phase->params.current.dotProd[dp].sampleCount);
            if(energy)
            {
                phase->energy.fundamentalReactiveEnergyQuardrantIV.energy += energy;
                total->energy.fundamentalReactiveEnergyQuardrantIV.energy += energy;
            }
        }
        else
        {
            energy = integratePowertoEnergy(&phase->energy.fundamentalReactiveEnergyQuardrantIII, power, phase->params.current.dotProd[dp].sampleCount);
            if(energy)
            {
                phase->energy.fundamentalReactiveEnergyQuardrantIII.energy += energy;
                total->energy.fundamentalReactiveEnergyQuardrantIII.energy += energy;
            }
        }
    }
}

/*!
 * @brief accumulate fundamental apparent energy
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void accumulateFundamentalApparentEnergy(metrologyData *workingData, PHASES ph)
{
    phaseMetrology *phase = &workingData->phases[ph];
    totalParams *total = &workingData->totals;
    int8_t dp = phase->params.dpSet;
    volatile uint64_t energy;

    _iq13 power = _IQ13abs(phase->readings.FApparentPower);
    if(phase->readings.FApparentPower >= 0)
    {
        energy = integratePowertoEnergy(&phase->energy.fundamentalAppparentEnergyImported, power, phase->params.current.dotProd[dp].sampleCount);
        if(energy)
        {
            phase->energy.fundamentalAppparentEnergyImported.energy += energy;
            total->energy.fundamentalAppparentEnergyImported.energy += energy;
        }
    }
    else
    {
        energy = integratePowertoEnergy(&phase->energy.fundamentalAppparentEnergyExported, power, phase->params.current.dotProd[dp].sampleCount);
        if(energy)
        {
            phase->energy.fundamentalAppparentEnergyExported.energy += energy;
            total->energy.fundamentalAppparentEnergyExported.energy += energy;
        }
    }
}

/*!
 * @brief calculate power factor
 * @param[in] phase  The phase metrology
 * @return Power factor (IQ13 format)
 */
_iq13 calculatePowerFactor(phaseMetrology *phase)
{
  _iq13 powerFactor = _IQ13div(phase->readings.activePower, phase->readings.apparentPower);

  if(phase->readings.reactivePower > 0)
  {
      powerFactor = -powerFactor;
  }
  if(phase->readings.activePower < 0)
  {
      powerFactor = -powerFactor;
  }

return powerFactor;
}

/*!
 * @brief calculate power factor angle
 * @param[in] phase  The phase metrology
 * @return Power factor angle in per unit with base value of 180 degrees(3.14 radians)
 *         180 degrees corresponds to 1
 *         -180 degrees corresponds to -1
 */
_iq15 calculateAngleVoltagetoCurrent(phaseMetrology *phase)
{
    _iq15 angle = _IQ15atan2(phase->readings.reactivePower, phase->readings.activePower);
    angle = _IQ15div(angle, _IQ15(3.1415));
    return angle;
}

/*!
 * @brief calculate voltage over deviation
 * @param[in] phase  The phase metrology
 * @return Voltage over deviation in percentage (IQ19 format)
 */
_iq19 calculateOverDeviation(phaseMetrology *phase)
{
    _iq19 overDeviation;
    if(phase->readings.RMSVoltage < MAINS_NOMINAL_VOLTAGE_IQ19)
    {
        overDeviation = 0;
    }
    else
    {
        overDeviation = _IQ19div((phase->readings.RMSVoltage - MAINS_NOMINAL_VOLTAGE_IQ19), MAINS_NOMINAL_VOLTAGE_IQ19);
    }
    return _IQ19mpy(overDeviation, _IQ19(100));
}

/*!
 * @brief calculate voltage under deviation
 * @param[in] phase  The phase metrology
 * @return Voltage under deviation in percentage (IQ19 format)
 */
_iq19 calculateUnderDeviation(phaseMetrology *phase)
{
    _iq19 underDeviation;
    if(phase->readings.RMSVoltage > MAINS_NOMINAL_VOLTAGE_IQ19)
    {
        underDeviation = 0;
    }
    else
    {
        underDeviation = _IQ19div((MAINS_NOMINAL_VOLTAGE_IQ19 - phase->readings.RMSVoltage), MAINS_NOMINAL_VOLTAGE_IQ19);
    }
    return _IQ19mpy(underDeviation, _IQ19(100));
}

/*!
 * @brief calculate voltage THD
 * @param[in] phase  The phase metrology
 * @return Voltage THD in percentage (IQ19 format)
 */
_iq19 calculateVoltageTHD(phaseMetrology *phase)
{
    _iq5 x = _IQ19toIQ5(phase->readings.RMSVoltage);
    _iq5 y = _IQ19toIQ5(phase->readings.FRMSVoltage);

    _iq19 voltageTHD = _IQ19div(_IQ5toIQ19(_IQ5sqrt(_IQ5mpy(x, x) - _IQ5mpy(y, y))), phase->readings.RMSVoltage);

    return _IQ19mpy(voltageTHD, _IQ19(100));
}

/*!
 * @brief calculate current THD
 * @param[in] phase  The phase metrology
 * @return Current THD in percentage (IQ19 format)
 */
_iq19 calculateCurrentTHD(phaseMetrology *phase)
{
    _iq5 x = _IQ19toIQ5(phase->readings.RMSCurrent);
    _iq5 y = _IQ19toIQ5(phase->readings.FRMSCurrent);

    _iq19 currentTHD = _IQ19div(_IQ5toIQ19(_IQ5sqrt(_IQ5mpy(x, x) - _IQ5mpy(y, y))), phase->readings.RMSCurrent);

    return _IQ19mpy(currentTHD, _IQ19(100));
}

/*!
 * @brief calculate mains frequency
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return Mains Frequency (IQ15 format)
 */
_iq15 calculateMainsfrequency(phaseMetrology *phase, phaseCalibrationData *phaseCal)
{
    uint32_t period;
    uint32_t quardOffset;

    period = phase->params.voltagePeriod.period;
    quardOffset = period >> 2;
    Metrology_setPhaseCorrection(&phase->params.current.quadratureCorrection, quardOffset - phaseCal->current.phaseOffset);

    /* purePhaserate is rate of increment in angle per sample
     * each sample is divided into 256 samples while estimating period
     */
    phase->params.purePhaseRate = ((int64_t)0x100000000000000LL/(int64_t) period) >> 16;

    _iq10 freq = _IQ10div(_IQ10mpy(_IQ10(SAMPLE_RATE), _IQ10(256)), _IQ10(period));

    phase->params.interruptionLevel = _IQ15mpy(_IQ15div(_IQ15mpy(MIN_SAG_VOLTAGE, MIN_SAG_VOLTAGE), phaseCal->VscaleFactor), _IQ15div(period, phaseCal->VscaleFactor));
    phase->params.interruptionLevelHalf = phase->params.interruptionLevel >> 1;

    return _IQ10toIQ15(freq);
}

/*!
 * @brief    Calculate total active power
 * @param[in] workingData The metrology instance
 * @return Total Active Power in watts (IQ13 format)
 */
_iq13 calculateTotalActivePower(metrologyData *workingData)
{
    _iq13 activePower = 0;

    for(int ph = 0; ph < MAX_PHASES; ph++)
    {
        activePower += workingData->phases[ph].readings.activePower;
    }

    if(_IQ13abs(activePower) < TOTAL_RESIDUAL_POWER_CUTOFF)
    {
        activePower = 0;
    }
    return activePower;
}

/*!
 * @brief    Calculate total reactive power
 * @param[in] workingData The metrology instance
 * @return Total Reactive Power in VAR (IQ13 format)
 */
_iq13 calculateTotalReactivePower(metrologyData *workingData)
{
    _iq13 reactivePower = 0;

    for(int ph = 0; ph < MAX_PHASES; ph++)
    {
        reactivePower += workingData->phases[ph].readings.reactivePower;
    }

    if(_IQ13abs(reactivePower) < TOTAL_RESIDUAL_POWER_CUTOFF)
    {
        reactivePower = 0;
    }
    return reactivePower;
}

/*!
 * @brief    Calculate total apparent power
 * @param[in] workingData The metrology instance
 * @return Total Apparent Power in VA (IQ13 format)
 */
_iq13 calculateTotalApparentPower(metrologyData *workingData)
{
    _iq13 apparentPower = 0;

    for(int ph = 0; ph < MAX_PHASES; ph++)
    {
        apparentPower += workingData->phases[ph].readings.apparentPower;
    }

    if(_IQ13abs(apparentPower) < TOTAL_RESIDUAL_POWER_CUTOFF)
    {
        apparentPower = 0;
    }
    return apparentPower;
}

/*!
 * @brief    Calculate total fundamental active power
 * @param[in] workingData The metrology instance
 * @return Total Fundamental Active Power in watts (IQ13 format)
 */
_iq13 calculateTotalFundamentalActivePower(metrologyData *workingData)
{
    _iq13 fundamentalActivePower = 0;

    for(int ph = 0; ph < MAX_PHASES; ph++)
    {
        fundamentalActivePower += workingData->phases[ph].readings.FActivePower;
    }

    if(_IQ13abs(fundamentalActivePower) < TOTAL_RESIDUAL_POWER_CUTOFF)
    {
        fundamentalActivePower = 0;
    }
    return fundamentalActivePower;
}

/*!
 * @brief    Calculate total fundamental reactive power
 * @param[in] workingData The metrology instance
 * @return Total Fundamental Reactive Power in VAR (IQ13 format)
 */
_iq13 calculateTotalFundamentalReactivePower(metrologyData *workingData)
{
    _iq13 fundamentalReactivePower = 0;

    for(int ph = 0; ph < MAX_PHASES; ph++)
    {
        fundamentalReactivePower += workingData->phases[ph].readings.FReactivePower;
    }

    if(_IQ13abs(fundamentalReactivePower) < TOTAL_RESIDUAL_POWER_CUTOFF)
    {
        fundamentalReactivePower = 0;
    }
    return fundamentalReactivePower;
}

/*!
 * @brief    Calculate total fundamental apparent power
 * @param[in] workingData The metrology instance
 * @return Total Fundamental Apparent Power in VA (IQ13 format)
 */
_iq13 calculateTotalFundamentalApparentPower(metrologyData *workingData)
{
    _iq13 fundamentalApparentPower = 0;

    for(int ph = 0; ph < MAX_PHASES; ph++)
    {
        fundamentalApparentPower += workingData->phases[ph].readings.FApparentPower;
    }

    if(_IQ13abs(fundamentalApparentPower) < TOTAL_RESIDUAL_POWER_CUTOFF)
    {
        fundamentalApparentPower = 0;
    }
    return fundamentalApparentPower;
}

/*!
 * @brief    Calculate line to line voltage
 * @param[in] phase1  The phase1 metrology
 * @param[in] phase2  The phase2 metrology
 * @return    line to line voltage in volts (IQ19 format)
 */
_iq19 calculateLinetoLineVoltage(phaseMetrology *phase1, phaseMetrology *phase2)
{
    _iq19 llVoltage;

    _iq19 VRMS1 = phase1->readings.RMSVoltage;
    _iq19 VRMS2 = phase2->readings.RMSVoltage;
    _iq19 angle = _IQ15toIQ19(phase1->readings.phasetoPhaseAngle) >> 1;

    _iq19 x, y;

    x = VRMS1 - _IQ19mpy(VRMS2, _IQ19cosPU(angle));
    y = _IQ19mpy(VRMS2, _IQ19sinPU(angle));

    llVoltage = _IQ19mag(x,y);

return llVoltage;
}

/*!
 * @brief    Calculate fundamental line to line voltage
 * @param[in] phase1  The phase1 metrology
 * @param[in] phase2  The phase2 metrology
 * @return    fundamental line to line voltage in volts (IQ19 format)
 */
_iq19 calculateFundamentalLinetoLineVoltage(phaseMetrology *phase1, phaseMetrology *phase2)
{
    _iq19 llFVoltage;

    _iq19 VFRMS1 = phase1->readings.FRMSVoltage;
    _iq19 VFRMS2 = phase2->readings.FRMSVoltage;
    _iq19 angle = _IQ15toIQ19(phase1->readings.phasetoPhaseAngle) >> 1;

    _iq19 x, y;

    x = VFRMS1 - _IQ19mpy(VFRMS2, _IQ19cosPU(angle));
    y = _IQ19mpy(VFRMS2, _IQ19sinPU(angle));

    llFVoltage = _IQ19mag(x,y);

return llFVoltage;
}

/*!
 * @brief    Calculate aggregate power factor
 * @param[in] workingData The metrology instance
 * @return Aggregate power factor in IQ13 format
 */
_iq13 calculateAggregatePowerfactor(metrologyData *workingData)
{
    totalParams total = workingData->totals;

    _iq13 powerFactor = _IQ13div(total.readings.activePower, total.readings.apparentPower);

    if(total.readings.reactivePower > 0)
    {
        powerFactor = -powerFactor;
    }
    if(total.readings.activePower < 0)
    {
        powerFactor = -powerFactor;
    }

  return powerFactor;
}

/*!
 * @brief    Calculate current vector sum
 * @param[in] workingData The metrology instance
 * @return Current vector sum in amps (IQ19 format)
 */
_iq19 calculateVectorCurrentSum(metrologyData *workingData)
{
    _iq19 vectorCurrentSum = 0;

#ifdef THREE_PHASE_SUPPORT
    _iq19 current0 = workingData->phases[0].readings.RMSCurrent;
    _iq19 current1 = workingData->phases[1].readings.RMSCurrent;
    _iq19 current2 = workingData->phases[2].readings.RMSCurrent;
    _iq19 angle1 = (_IQ15toIQ19(workingData->phases[0].readings.phasetoPhaseAngle + workingData->phases[0].readings.powerFactorAngle - workingData->phases[1].readings.powerFactorAngle) >> 1);
    _iq19 angle2 = (_IQ15toIQ19(workingData->phases[1].readings.phasetoPhaseAngle + workingData->phases[1].readings.powerFactorAngle - workingData->phases[2].readings.powerFactorAngle) >> 1);
    _iq19 ix, iy;

    ix = current0 + _IQ19mpy(current1, _IQ19cosPU(angle1))
            + _IQ19mpy(current2, _IQ19cosPU(angle2 + angle1));

    iy = _IQ19mpy(current1, _IQ19sinPU(angle1))
            + _IQ19mpy(current2, _IQ19sinPU(angle2 + angle1));

    vectorCurrentSum = _IQ19mag(ix,iy);
#endif
    return vectorCurrentSum;
}

/*!
 * @brief calculate Neutral RMS Current
 * @param[in] neutral    The neutral metrology
 * @param[in] neutralCal The neutral calibration data
 * @return Neutral RMS current in amps (IQ19 format)
 */
_iq19 calculateNeutralRMSCurrent(neutralMetrology *neutral, currentSensorCalibrationData *neutralCal)
{
    _iq19 NeutralRMSCurrent;

    /* index of the dot product currently set for foreground processing */
    int8_t dp = neutral->params.dpSet;
    neutralDPSet *current = &neutral->params.dotProd[dp];

    /* RMS Neutral Current calculation  */
    if(!neutral->params.dotProd[dp].sampleCount)
    {
        /* Number of samples is zero    */
        NeutralRMSCurrent = 0;
    }
    else
    {
        int64_t sqrms = current->currentSq/current->sampleCount;
        int32_t rms = isqrt64(sqrms) >> 24;

        NeutralRMSCurrent = (rms * (int64_t)(neutralCal->IscaleFactor)) >> 31;

        if(NeutralRMSCurrent < neutralCal->IacOffset)
        {
            /* RMS current is smaller than offset error */
            NeutralRMSCurrent = 0;
        }
        else
        {
            NeutralRMSCurrent -= neutralCal->IacOffset;
        }
    }
    return NeutralRMSCurrent;
}

/*!
 * @brief    Read Line to Line Voltage
 * param[in] workingData The metrology instance
 */
void readLinetoLineVoltage(metrologyData *workingData)
{
#ifdef THREE_PHASE_SUPPORT
    workingData->LLReadings.LLRMSVoltage_ab = calculateLinetoLineVoltage(&workingData->phases[PHASE_ONE], &workingData->phases[PHASE_TWO]);
    workingData->LLReadings.LLRMSVoltage_bc = calculateLinetoLineVoltage(&workingData->phases[PHASE_TWO], &workingData->phases[PHASE_THERE]);
    workingData->LLReadings.LLRMSVoltage_ca = calculateLinetoLineVoltage(&workingData->phases[PHASE_THERE], &workingData->phases[PHASE_ONE]);
#endif
}

/*!
 * @brief    Read Fundamental Line to Line Voltage
 * param[in] workingData The metrology instance
 */
void readFundamentalLinetoLineVoltage(metrologyData *workingData)
{
#ifdef THREE_PHASE_SUPPORT
    workingData->LLReadings.FLLRMSVoltage_ab = calculateFundamentalLinetoLineVoltage(&workingData->phases[PHASE_ONE], &workingData->phases[PHASE_TWO]);
    workingData->LLReadings.FLLRMSVoltage_bc = calculateFundamentalLinetoLineVoltage(&workingData->phases[PHASE_TWO], &workingData->phases[PHASE_THERE]);
    workingData->LLReadings.FLLRMSVoltage_ca = calculateFundamentalLinetoLineVoltage(&workingData->phases[PHASE_THERE], &workingData->phases[PHASE_ONE]);
#endif
}

/*!
 * @brief Integrate Power to Energy
 * @param[in] en          The energy instance
 * @param[in] power       Power
 * @param[in] samples     Number of samples
 * @return energy steps
 */
uint64_t integratePowertoEnergy(energyIntegrator *en, _iq13 power, uint32_t samples)
{
    volatile _iq13 energy;
    volatile uint64_t energyStep;

    energy = _IQ13mpy(power, _IQ13div(_IQ13(samples),_IQ13(SAMPLE_RATE))) + en->energyResidual;
    energyStep = 0;
    while(energy >= ENERGY_100mWATT_HOUR_THRESHOLD_IQ)
    {
        energy -= ENERGY_100mWATT_HOUR_THRESHOLD_IQ;
        energyStep++;
    }

    en->energyResidual = energy;

    return energyStep;
}

/*!
 * @brief Cycle RMS Voltage Calculation
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 * @return cycle RMS Voltage in volts (IQ19 format)
 */
_iq19 calculateCycleRMSVoltage(metrologyData *workingData, PHASES ph)
{
    phaseMetrology *phase = &workingData->phases[ph];
    phaseCalibrationData *phaseCal = &calInfo->phases[ph];

    _iq19 voltage;

    int cycleDp = phase->params.cycleDpSet;
    cyclePhaseDPSet *dpSet = &phase->params.cycleDotProd[cycleDp];

    if(!dpSet->cycleSampleCount)
    {
        voltage = 0;
    }
    else
    {
        int64_t sqrms = dpSet->cycleVoltageSq/dpSet->cycleSampleCount;
        int32_t rms = isqrt64(sqrms) >> 24;
        voltage = (rms * (int64_t)(phaseCal->VscaleFactor)) >> 31;

        if(voltage < phaseCal->VacOffset)
        {
            voltage = 0;
        }
        else
        {
            voltage -= phaseCal->VacOffset;
        }
    }

    phase->readings.RMSVoltageCycle = voltage;
return voltage;
}

/*!
 * @brief Check for sag swell events
 * @param[in] workingData   The Metrology Instance
 * @param[in] ph            Phase number
 */
void checkSagSwellEvents(metrologyData *workingData, PHASES ph)
{
    phaseMetrology *phase = &workingData->phases[ph];

    _iq19 cycleRMSVoltage = calculateCycleRMSVoltage(workingData, ph);

    if(cycleRMSVoltage < phase->params.sagThresholdStart)
    {
        /* sag condition    */
        if(cycleRMSVoltage > phase->params.sagMinVoltage)
        {
            if((phase->params.sagSwellState != SAG_SWELL_VOLTAGE_SAG_ONSET)
                    && (phase->params.sagSwellState != SAG_SWELL_VOLTAGE_SAG_CONTINUING))
            {
                /* new sag condition    */
                phase->params.sagSwellState = SAG_SWELL_VOLTAGE_SAG_ONSET;
                phase->params.sagValue = cycleRMSVoltage;

                phase->params.sagEvents ++;
                phase->params.sagDuration = 1;
            }
            else
            {
                /* continuing sag condition */
                phase->params.sagSwellState = SAG_SWELL_VOLTAGE_SAG_CONTINUING;
                if(cycleRMSVoltage < phase->params.sagValue)
                {
                    phase->params.sagValue = cycleRMSVoltage;
                }
                phase->params.sagDuration++;
            }
        }
        else
        {
            if((phase->params.sagSwellState != SAG_SWELL_VOLTAGE_INTERRUPTION_ONSET)
                    &&(phase->params.sagSwellState != SAG_SWELL_VOLTAGE_INTERRUPTION_CONTINUING))
            {
                /* new interruption */
                phase->params.sagSwellState = SAG_SWELL_VOLTAGE_INTERRUPTION_ONSET;
                phase->params.interruptionEvents++;
                phase->params.interruptionDuration = 1;
            }
            else
            {
                /* continue interruption    */
                phase->params.sagSwellState = SAG_SWELL_VOLTAGE_INTERRUPTION_CONTINUING;
                phase->params.interruptionDuration++;
            }

        }
    }
    else if(cycleRMSVoltage > phase->params.swellThresholdStart)
    {
        /* swell condition  */
        if((phase->params.sagSwellState != SAG_SWELL_VOLTAGE_SWELL_ONSET)
                && (phase->params.sagSwellState != SAG_SWELL_VOLTAGE_SWELL_CONTINUING))
        {
            /* new swell condition  */
            phase->params.sagSwellState = SAG_SWELL_VOLTAGE_SWELL_ONSET;
            phase->params.swellValue = cycleRMSVoltage;
            phase->params.swellEvents++;
            phase->params.swellDuration = 1;
        }
        else
        {
            /* continuing swell condition   */
            phase->params.sagSwellState = SAG_SWELL_VOLTAGE_SWELL_CONTINUING;
            if(cycleRMSVoltage > phase->params.swellValue)
            {
                phase->params.swellValue = cycleRMSVoltage;
            }
            phase->params.swellDuration++;
        }
    }
    else
    {
        if((cycleRMSVoltage > phase->params.sagThresholdStop)
                &&((phase->params.sagSwellState == SAG_SWELL_VOLTAGE_SAG_CONTINUING)
                        || (phase->params.sagSwellState == SAG_SWELL_VOLTAGE_SAG_ONSET)
                        || (phase->params.sagSwellState == SAG_SWELL_VOLTAGE_INTERRUPTION_CONTINUING)
                        || (phase->params.sagSwellState == SAG_SWELL_VOLTAGE_INTERRUPTION_ONSET)))
        {
            /* sag ended    */
            phase->params.sagSwellState = SAG_SWELL_VOLTAGE_NORMAL;
        }
        else if((cycleRMSVoltage < phase->params.swellThresholdStop)
                &&((phase->params.sagSwellState == SAG_SWELL_VOLTAGE_SWELL_CONTINUING)
                        || (phase->params.sagSwellState == SAG_SWELL_VOLTAGE_SWELL_ONSET)))
        {
            /* swell ended  */
            phase->params.sagSwellState = SAG_SWELL_VOLTAGE_NORMAL;
        }
    }
}

/*!
 * @brief calculate dc estimate voltage
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return  DC Estimate Voltage in volts (IQ19 format)
 */
_iq19 calculateVdcEstimate(phaseMetrology *phase, phaseCalibrationData *phaseCal)
{
    _iq23 Vdclogged = (int32_t)(phase->params.V_dc_estimate >> 16);
    _iq19 VdcEstimate = _IQ19mpyIQX(Vdclogged, 23, phaseCal->VscaleFactor, 19);
    return VdcEstimate;
}

/*!
 * @brief calculate dc estimate current
 * @param[in] phase    The phase metrology
 * @param[in] phaseCal The phase calibration data
 * @return  DC Estimate current in amps (IQ19 format)
 */
_iq19 calculateIdcEstimate(phaseMetrology *phase, phaseCalibrationData *phaseCal)
{
    _iq23 Idclogged = (int32_t)(phase->params.current.I_dc_estimate >> 16);
    _iq19 IdcEstimate = _IQ19mpyIQX(Idclogged, 23, phaseCal->current.IscaleFactor, 19);
    return IdcEstimate;
}

/*!
 * @brief calculate neutral dc estimate current
 * @param[in] neutral    The neutral metrology
 * @param[in] neutralCal The neutral calibration data
 * @return  Neutral DC Estimate current in amps (IQ19 format)
 */
_iq19 calculateNeutralIdcEstimate(neutralMetrology *neutral, currentSensorCalibrationData *neutralCal)
{
    _iq23 Idclogged = (int32_t)(neutral->params.I_dc_estimate >> 16);
    _iq19 IdcEstimate = _IQ19mpyIQX(Idclogged, 23, neutralCal->IscaleFactor, 19);
    return IdcEstimate;
}


