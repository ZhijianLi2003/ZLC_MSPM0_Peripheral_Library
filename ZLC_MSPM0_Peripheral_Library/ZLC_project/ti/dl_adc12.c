/*
 * Copyright (c) 2020, Texas Instruments Incorporated
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

#include <ti/driverlib/dl_adc12.h>

#ifdef __MSPM0_HAS_ADC12__

void DL_ADC12_setClockConfig(ADC12_Regs *adc12, DL_ADC12_ClockConfig *config)
{
    DL_Common_updateReg(&adc12->ULLMEM.GPRCM.CLKCFG,
        (ADC12_CLKCFG_KEY_UNLOCK_W | (uint32_t) config->clockSel),
        (ADC12_CLKCFG_KEY_MASK | ADC12_CLKCFG_SAMPCLK_MASK));

    DL_Common_updateReg(&adc12->ULLMEM.CTL0, (uint32_t) config->divideRatio,
        ADC12_CTL0_SCLKDIV_MASK);

    adc12->ULLMEM.CLKFREQ = (uint32_t) config->freqRange;
}

void DL_ADC12_getClockConfig(ADC12_Regs *adc12, DL_ADC12_ClockConfig *config)
{
    uint32_t clockConfig =
        adc12->ULLMEM.GPRCM.CLKCFG & ADC12_CLKCFG_SAMPCLK_MASK;
    uint32_t divideRatio = adc12->ULLMEM.CTL0 & ADC12_CTL0_SCLKDIV_MASK;
    uint32_t freqRange   = adc12->ULLMEM.CLKFREQ & ADC12_CLKFREQ_FRANGE_MASK;

    config->clockSel = (DL_ADC12_CLOCK)(clockConfig);

    config->divideRatio = (DL_ADC12_CLOCK_DIVIDE)(divideRatio);

    config->freqRange = (DL_ADC12_CLOCK_FREQ_RANGE)(freqRange);
}

#endif /* __MSPM0_HAS_ADC12__ */
