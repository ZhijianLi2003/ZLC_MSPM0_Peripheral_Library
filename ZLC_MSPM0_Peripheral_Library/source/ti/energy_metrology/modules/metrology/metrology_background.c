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
#include "metrology_background.h"

/*!
 * @brief log phase parameters
 * @param[in] workingData The metrology data
 * @param[in] ph          Phase number
 */
void logPhaseParameters(metrologyData *workingData, int ph);

/*!
 * @brief log neutral phase parameters
 * @param[in] workingData The metrology data
 */
void logNeutralParameters(metrologyData *workingData);

/*!
 * @brief log phase parameters
 * @param[in] workingData The metrology data
 * @param[in] ph          Phase number
 */
void logPhaseParameters(metrologyData *workingData, int ph)
{
    phaseMetrology *phase = &workingData->phases[ph];

    /*
     * If the voltage hits the max ADC value more than limited number of hits
     * it is considered as over range.
     */
    if (phase->params.voltageEndStops <= 0)
    {
        phase->status |= PHASE_STATUS_V_OVERRANGE;
    }
    else
    {
        phase->status &= ~PHASE_STATUS_V_OVERRANGE;
    }

    /* Reload the limited number of hits value */
    phase->params.voltageEndStops = ENDSTOP_HITS_FOR_OVERLOAD;

    /*
     * If the current hits the max ADC value more than limited number of hits
     * it is considered as over range.
     */
    if(phase->params.current.currentEndStops <= 0)
    {
        phase->status |= PHASE_STATUS_I_OVERRANGE;
    }
    else
    {
        phase->status &= ~PHASE_STATUS_I_OVERRANGE;
    }

    /* Reload the limited number of hits value */
    phase->params.current.currentEndStops = ENDSTOP_HITS_FOR_OVERLOAD;

    if(++ph >= MAX_PHASES)
    {
        ph = 0;
    }

    /*
     *  PurePhase is signed 32 bit integer (IQ31) right shifting by 16 bits
     *  to convert it to IQ15 in per units with base value of 180 degrees
     */
    phase->readings.phasetoPhaseAngle = (workingData->phases[ph].params.purePhase >> 16) - (phase->params.purePhase >> 16);

    /* Reset the dpset data for next sampling */
    uint8_t dp = phase->params.dpSet;

    phase->params.dotProd[dp].voltageSq = 0;
    phase->params.dotProd[dp].sampleCount = 0;
    phase->params.current.dotProd[dp].currentSq = 0;
    phase->params.current.dotProd[dp].activePower = 0;
    phase->params.current.dotProd[dp].reactivePower = 0;
    phase->params.current.dotProd[dp].sampleCount = 0;

    phase->params.dotProd[dp].fVoltageSq = 0;
    phase->params.current.dotProd[dp].FActivePower = 0;
    phase->params.current.dotProd[dp].FReactivePower = 0;
    phase->params.dpSet ^= 1;

    phase->status |= PHASE_STATUS_NEW_LOG;
}

/*!
 * @brief log neutral parameters
 * @param[in] workingData The metrology data
 */
void logNeutralParameters(metrologyData *workingData)
{
    neutralMetrology * neutral = &workingData->neutral;

    /*
     * If the current hits the max ADC value more than limited number of hits
     * it is considered as over range.
     */
    if (neutral->params.currentEndStops <= 0)
    {
        neutral->status |= PHASE_STATUS_I_OVERRANGE;
    }
    else
    {
        neutral->status &= ~PHASE_STATUS_I_OVERRANGE;
    }

    /*
     * Reload the limited number of hits value
     */
    neutral->params.currentEndStops = ENDSTOP_HITS_FOR_OVERLOAD;
    neutral->params.I_dc_estimate_logged = neutral->params.I_dc_estimate;

    /*
     * Reset the dpset data for next sampling
     */
    uint8_t dp = neutral->params.dpSet;
    neutral->params.dotProd[dp].currentSq = 0;
    neutral->params.dotProd[dp].sampleCount = 0;
    neutral->params.dpSet ^= 1;

    neutral->status |= PHASE_STATUS_NEW_LOG;
}

/*!
 * @brief Metrology sin lookup
 * @param[in] phase The phase angle
 * @return sinvalue
 */
int32_t Metrology_ddsSinLookup(uint32_t phase)
{
    int32_t amp;
    uint32_t step;

    phase >>= METROLOGY_DDS_BIT_SHIFT;
    step = phase & (METROLOGY_DDS_STEPS - 1);
    if ((phase & METROLOGY_DDS_STEPS))
        step = METROLOGY_DDS_STEPS - step;
    amp = sineTable[step];
    if ((phase & (2*METROLOGY_DDS_STEPS)))
        amp = -amp;
    return amp;
}

/*!
 * @brief Start active energy pulse
 * @param[in] workingData The metrology Data
 */
void Metrology_startActiveEnergyPulse(metrologyData *workingData)
{
    HAL_writeGPIOPin(workingData->activePulse, 0);
}

/*!
 * @brief End active energy pulse
 * @param[in] workingData The metrology Data
 */
void Metrology_endActiveEnergyPulse(metrologyData *workingData)
{
    HAL_writeGPIOPin(workingData->activePulse, 1);
}

/*!
 * @brief Start reactive energy pulse
 * @param[in] workingData The metrology Data
 */
void Metrology_startReactiveEnergyPulse(metrologyData *workingData)
{
    HAL_writeGPIOPin(workingData->reactivePulse, 0);
}

/*!
 * @brief End reactive energy pulse
 * @param[in] workingData The metrology Data
 */
void Metrology_endReactiveEnergyPulse(metrologyData *workingData)
{
    HAL_writeGPIOPin(workingData->reactivePulse, 1);
}

/*!
 * @brief Metrology per phase sampling
 * @param[in] workingData The metrology data
 */
void Metrology_perSampleProcessing(metrologyData *workingData)
{
    uint32_t supportedParams        = workingData->supportedParams;
    OPERATING_MODES operatingMode   = workingData->operatingMode;

    _iq23 voltageSample;
    _iq23 voltageCorrected;
    _iq23 voltageQuadCorrected;
    _iq23 voltagePure;
    _iq23 voltageQuardPure;
    int64_t voltageSq;
    int64_t cross_corr;
    _iq23 currentSample;
    _iq23 currentCorrected;
    _iq23 neutralCurrent;

    voltageDPSet *phaseDP;
    cyclePhaseDPSet *cyclePhaseDP;
    currentDPSet *currentDP;
    neutralDPSet *neutralDP;

    /* Flag used to store which phase sampling is completed */
    int8_t phLog;

    phLog = 0;

    for(PHASES ph = PHASE_ONE; ph < MAX_PHASES; ph++)
    {
        phaseMetrology *phase = &workingData->phases[ph];

        uint8_t dp = (phase->params.dpSet ^ 0x01) & 0x01;
        phaseDP = &phase->params.dotProd[dp];
        uint8_t cycleDp = (phase->params.cycleDpSet ^ 0x01) & 0x01;
        cyclePhaseDP = &phase->params.cycleDotProd[cycleDp];

        voltageSample = workingData->rawVoltageData[ph];
        if((voltageSample >= V_ADC_MAX || voltageSample <= V_ADC_MIN) && phase->params.voltageEndStops)
        {
            phase->params.voltageEndStops--;
        }
        voltageSample = metrology_dcFilter(&(phase->params.V_dc_estimate), voltageSample);

#ifdef ROGOSWKI_SUPPORT
        /*
         * With rogowski coils, current samples will pass through 2 filters, to compensate the
         * delay between voltage and current samples, voltage samples are also passed through
         * 2 filters.
         */
        voltageSample = metrology_dcFilter(&(phase->params.V_dc_estimate1), voltageSample);
#endif

        if((supportedParams & VRMS_SUPPORT) == VRMS_SUPPORT)
        {
            voltageSq = ((int64_t)voltageSample) * voltageSample;
            phaseDP->voltageSq += voltageSq;
            ++phaseDP->sampleCount;
            if((supportedParams & SAG_SWELL_SUPPORT) == SAG_SWELL_SUPPORT)
            {
                cyclePhaseDP->cycleVoltageSq += voltageSq;
                ++cyclePhaseDP->cycleSampleCount;
            }
        }

        phase->params.vHistory[phase->params.vHistoryIndex] = voltageSample;

        if(operatingMode == OPERATING_MODE_NORMAL)
        {
            voltageCorrected = _IQ23mpyIQX(phase->params.vHistory[(phase->params.vHistoryIndex - phase->params.current.phaseCorrection.step - 1) & V_HISTORY_MASK], 23,
                                (phase->params.current.phaseCorrection.firBeta), 15)
                               + (phase->params.vHistory[(phase->params.vHistoryIndex - phase->params.current.phaseCorrection.step) & V_HISTORY_MASK]);

            if((supportedParams & FUNDAMENTAL_VRMS_SUPPORT) == FUNDAMENTAL_VRMS_SUPPORT)
            {
                /* The dot product of the raw and the pure voltage signals allows us to precisely estimate
                   the amplitude of the fundamental component of the mains voltage waveform. This is needed,
                   during the foreground processing, to correctly scale the answer from the dot product of the
                   full scale pure voltage waveform and the current signal.
                   The answer from this estimator will only be correct once the pure waveform is properly phase
                   locked. */
                voltagePure = Metrology_ddsSinLookup(phase->params.purePhase);
                phaseDP->fVoltageSq += ((int64_t)voltageCorrected) * voltagePure;
                /* If we look for maximum correlation when the real and synthetic waveforms are in sync:
                        - the sensitivity to errors is not that big around the match
                        - we don't know what the peak should be
                        - we don't know which side of the peak we are.
                   If we look for minimum correlation in quadrature signals we solve all three issues in one go. */
                /* Cross correlate the real voltage signal with the synthesised quadrature one, and tune the phase to
                   minimise the correlation. This assumes the phase rate is being accurately derived from the mains
                   frequency measurement, and we only need to adjust the phase here. This is a sort of PLL, with the
                   frequency and phase aspects of the lock being seperately evaluated. */
                voltageQuardPure = Metrology_ddsSinLookup(phase->params.purePhase + 0x40000000);
                cross_corr = (((int64_t)voltageCorrected) * voltageQuardPure);
                cross_corr >>=16;
                /* We need to filter hard at this point, to massively suppress the harmonics. We do this with a single
                   pole with a very low turnover point. Obviously, this only tails off at 6dB/octave, so the downside
                   it a very slow pull-in during the initial phase locking. */
                /*
                 *          Simple 1st order filter
                 *              cross_sum(n) = cross_sum(n-1) + [(2^13 - 1)/2^13]cross_sum(n-1)
                 *              pure_phase(n) = pure_phase(n-1) - cross_sum(n)/2^5 + pure_phase_rate(n-1)
                 */
                phase->params.crossSum += (cross_corr - phase->params.crossSum) >> 13;
                phase->params.purePhase += phase->params.crossSum >> 5;
                phase->params.purePhase += phase->params.purePhaseRate;
            }
        }

        currentDP = &phase->params.current.dotProd[dp];

        _iq23 currentData;
        _iq23 inputCurrent;
        _iq23 integratorOutput;

#ifdef ROGOSWKI_SUPPORT
        inputCurrent = metrology_dcFilter(&(phase->params.current.I_dc_estimate), workingData->rawCurrentData[ph]);
        _iq23 intnewcurrent = (inputCurrent + workingData->lastRawCurrentData[ph])/2;
        workingData->lastRawCurrentData[ph] = inputCurrent;

        workingData->currentIntegrationData[ph] += _IQ23div(intnewcurrent, phase->params.voltagePeriod.cyclePeriod);

        currentData = metrology_dcFilter(&(phase->params.current.I_dc_estimate_integral), workingData->currentIntegrationData[ph]);

#else
        currentData = metrology_dcFilter(&(phase->params.current.I_dc_estimate), workingData->rawCurrentData[ph]);
#endif

        currentSample = phase->params.current.IHistory[0];

        if((currentSample >= I_ADC_MAX || currentSample <= I_ADC_MIN) && phase->params.current.currentEndStops)
        {
            phase->params.current.currentEndStops--;
        }
        phase->params.current.IHistory[0] = phase->params.current.IHistory[1];
        phase->params.current.IHistory[1] = currentData;
        if((supportedParams & IRMS_SUPPORT) == IRMS_SUPPORT)
        {
            currentDP->currentSq += ((int64_t)(currentSample) *(currentSample));
            ++currentDP->sampleCount;
        }

        if (operatingMode == OPERATING_MODE_NORMAL)
        {
            if((supportedParams & ACTIVE_POWER_SUPPORT) == ACTIVE_POWER_SUPPORT)
            {
                voltageCorrected = _IQ23mpyIQX(phase->params.vHistory[(phase->params.vHistoryIndex - phase->params.current.phaseCorrection.step - 1) & V_HISTORY_MASK], 23,
                                    (phase->params.current.phaseCorrection.firBeta), 15)
                                   + (phase->params.vHistory[(phase->params.vHistoryIndex - phase->params.current.phaseCorrection.step) & V_HISTORY_MASK]);

                currentDP->activePower += ((int64_t)currentSample) * voltageCorrected;
                if((supportedParams & FUNDAMENTAL_ACTIVE_POWER_SUPPORT) == FUNDAMENTAL_ACTIVE_POWER_SUPPORT)
                {
                    currentDP->FActivePower += ((int64_t)currentSample) * voltagePure;
                }
            }

            if((supportedParams & REACTIVE_POWER_SUPPORT) == REACTIVE_POWER_SUPPORT)
            {
                voltageQuadCorrected = _IQ23mpyIQX(phase->params.vHistory[(phase->params.vHistoryIndex - phase->params.current.quadratureCorrection.step - 1) & V_HISTORY_MASK], 23,
                                                (phase->params.current.quadratureCorrection.firBeta), 15)
                                                  + (phase->params.vHistory[(phase->params.vHistoryIndex - phase->params.current.quadratureCorrection.step) & V_HISTORY_MASK]);

                currentDP->reactivePower += ((int64_t)currentSample) * voltageQuadCorrected;
                if((supportedParams & FUNDAMENTAL_REACTIVE_POWER_SUPPORT) == FUNDAMENTAL_REACTIVE_POWER_SUPPORT)
                {
                    currentDP->FReactivePower += ((int64_t)currentSample) * -voltageQuardPure;
                }
            }
        }
    phase->params.vHistoryIndex = (phase->params.vHistoryIndex + 1) & V_HISTORY_MASK;

/*
 * Frequency measurement:
 * time between 2 voltage samples is divided into 256(2 power 8) parts
 * first will detect the change of voltage form positive to negative or vice versa
 * when voltage changes from negative to positive frequency calculation is started
 * else do nothing.
 * every time a sample is sampled cycleSamples is incremented by 256
 * when voltage is changed from negative to positive check the cycle samples limit
 * it has to be in between cycles for min freq and max freq.
 * if it is out of limits something has gone wrong and restart the cycle samples
 * as we divided the time between 2 samples into 256, now we have to estimate the approximate
 * samples it taken before zero crossing
 * for that we are doing successive approximation 8 times which give the approx number of cycles
 * Finally we are applying a filter to get the stable value
 */

    if((supportedParams & FREQUENCY_SUPPORT) == FREQUENCY_SUPPORT)
    {
        /*
         * Each ADC sample is divided into 256 samples, so cycleSamples are
         * incremented by 256
         */
        phase->params.voltagePeriod.cycleSamples +=256;

        /* checking for zero crossing   */
        if(_IQ23abs(voltageCorrected - phase->params.lastVoltageSample) <= MAX_PER_SAMPLE_VOLTAGE_SLEW)
        {
            /* This is not a spike. Do mains cycle detection and estimate the precise main period  */
            if((voltageCorrected < 0))
            {
                /* voltage is in negative cycle    */
                phase->status &= ~PHASE_STATUS_V_POS;
            }
            else
            {
                if (!(phase->status & PHASE_STATUS_V_POS))
                {
                    /* Zero crossing occurred, voltage changed from negative to positive    */
                    /* check the number of cycleSamples counted is with in the limit if not reset the cycle count   */
                    if(METROLOGY_MIN_CYCLE_SAMPLES <= phase->params.voltagePeriod.cycleSamples
                            && phase->params.voltagePeriod.cycleSamples <= METROLOGY_MAX_CYCLE_SAMPLES)
                    {
                        if((supportedParams & SAG_SWELL_SUPPORT) == SAG_SWELL_SUPPORT)
                          {
                              int cdp = phase->params.cycleDpSet;
                              phase->params.cycleDotProd[cdp].cycleVoltageSq = 0;
                              phase->params.cycleDotProd[cdp].cycleSampleCount = 0;

                              phase->params.cycleDpSet ^= 1;
                              phase->cycleStatus &= ~PHASE_STATUS_ZERO_CROSSING_MISSED;
                              phase->cycleStatus |= PHASE_STATUS_NEW_LOG;
                          }

                        /* Interpolate the zero crossing by successive approx   */
                        _iq23 diffVoltage = voltageCorrected - phase->params.lastVoltageSample;
                        _iq23 approxVoltage = 0;
                        uint32_t samples = 0;

                        for (int i = 0; i<8; i++)
                        {
                            samples <<= 1;
                            diffVoltage >>= 1;
                            approxVoltage += diffVoltage;

                            if(approxVoltage > voltageCorrected)
                            {
                                approxVoltage -= diffVoltage;
                            }
                            else
                            {
                                samples |= 1;
                            }
                        }

                        uint32_t z = samples;

                        while(phase->params.sinceLast > 1)
                        {
                            z += samples;
                            phase->params.sinceLast--;
                        }
                        phase->params.voltagePeriod.period += ((int32_t)(phase->params.voltagePeriod.cycleSamples - z) << 12) - (phase->params.voltagePeriod.period >> 4);
                        phase->params.voltagePeriod.period = phase->params.voltagePeriod.cycleSamples - z;
                        /* start next cycle count */
                        phase->params.voltagePeriod.cycleSamples = z;
                        phaseDP->cycleNumber++;
                        phase->params.voltagePeriod.cyclePeriod = _IQ23div(_IQ23div((int32_t)phase->params.voltagePeriod.period,256),PI2);
                    }
                    else
                    {
                      phase->params.voltagePeriod.cycleSamples = 0;
                      phaseDP->cycleNumber = 0;
                      phase->cycleStatus |= PHASE_STATUS_ZERO_CROSSING_MISSED;
                    }

                    if (phaseDP->cycleNumber >= CYCLES_PER_COMPUTATION)
                    {
                        phLog |= 1;
                        phaseDP->cycleNumber = 0;
                    }
                }
                phase->status |= PHASE_STATUS_V_POS;
            }
            phase->params.sinceLast = 0;
            phase->params.lastVoltageSample = voltageCorrected;
        }
        phase->params.sinceLast++;
    }

    if(phaseDP->sampleCount >= SAMPLE_RATE)
    {
        phLog |= 1;
    }

    if(cyclePhaseDP->cycleSampleCount >= TWICE_CYCLES_PER_NOMINAL_FREQUENCY)
    {
        cyclePhaseDP->cycleVoltageSq = 0;
        cyclePhaseDP->cycleSampleCount = 0;
    }

    phLog <<= 1;
    }

    /* if sampling is done its data is logged and used for foreground activity  */
    if(phLog)
    {
        for(PHASES ph = PHASE_ONE; ph < MAX_PHASES; ph++)
        {
            if(phLog & (1 << (MAX_PHASES - ph)))
            {
                logPhaseParameters(workingData, ph);
            }
        }
    }

    if(supportedParams & NEUTRAL_MONITOR_SUPPORT)
    {
        neutralMetrology *neutral = &workingData->neutral;

        int8_t dp = (neutral->params.dpSet ^ 0x01) & 0x01;
        neutralDP = &neutral->params.dotProd[dp];

        _iq15 neutralData = workingData->rawNeutralData;
        neutralCurrent = metrology_dcFilter(&neutral->params.I_dc_estimate, neutral->params.I_History[0]);
        if((neutralCurrent >= I_ADC_MAX || neutralCurrent <= I_ADC_MIN) && workingData->neutral.params.currentEndStops)
        {
            workingData->neutral.params.currentEndStops--;
        }
        neutral->params.I_History[0] = neutral->params.I_History[1];
        neutral->params.I_History[1] = neutralData;
        neutralDP->currentSq += ((int64_t)neutralCurrent) * neutralCurrent;
        if(++neutralDP->sampleCount >= SAMPLE_RATE)
        {
            logNeutralParameters(workingData);
        }
    }
}

/*!
 * @brief Metrology per sample energy pulse processing
 * @param[in] workingData The metrology data
 */
void Metrology_perSampleEnergyPulseProcessing(metrologyData *workingData)
{
    uint32_t supportParams = workingData->supportedParams;

    totalParams *total = &workingData->totals;

    int32_t pow;

    if((supportParams & ACTIVE_POWER_SUPPORT) == ACTIVE_POWER_SUPPORT)
    {
        pow = _IQ13mpy(_IQ13abs(workingData->totals.readings.activePower), _IQ13(0.1220703125));

        total->energy.activeEnergyPulse.integrator += (uint64_t)pow;

        if(total->energy.activeEnergyPulse.integrator >= TOTAL_ACTIVE_ENERGY_PULSE_THRESHOLD)
        {
            total->energy.activeEnergyPulse.integrator -= TOTAL_ACTIVE_ENERGY_PULSE_THRESHOLD;
            total->energy.activeEnergyPulse.pulseRemainingTime = ENERGY_PULSE_DURATION;

            Metrology_startActiveEnergyPulse(workingData);
        }

        if(--total->energy.activeEnergyPulse.pulseRemainingTime == 0)
        {
            Metrology_endActiveEnergyPulse(workingData);
        }
    }

    if((supportParams & REACTIVE_POWER_SUPPORT) == REACTIVE_POWER_SUPPORT)
    {
        pow = _IQ13mpy(_IQ13abs(workingData->totals.readings.reactivePower), _IQ13(0.1220703125));

        total->energy.reactiveEnergyPulse.integrator += (uint64_t)pow;

        if(total->energy.reactiveEnergyPulse.integrator >= TOTAL_REACTIVE_ENERGY_PULSE_THRESHOLD)
        {
            total->energy.reactiveEnergyPulse.integrator -= TOTAL_REACTIVE_ENERGY_PULSE_THRESHOLD;
            total->energy.reactiveEnergyPulse.pulseRemainingTime = ENERGY_PULSE_DURATION;

            Metrology_startReactiveEnergyPulse(workingData);
        }

        if(--total->energy.reactiveEnergyPulse.pulseRemainingTime == 0)
        {
            Metrology_endReactiveEnergyPulse(workingData);
        }
    }
}





