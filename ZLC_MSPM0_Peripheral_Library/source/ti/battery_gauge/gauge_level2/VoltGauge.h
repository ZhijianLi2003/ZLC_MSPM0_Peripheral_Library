/*
 * Copyright (c) 2024, Texas Instruments Incorporated
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
#ifndef GAUGE_V_GAUGE_H_
#define GAUGE_V_GAUGE_H_

#include "Gauge.h"
#include "Gauge_Type.h"

_iq15 VGauge_IQ15CalMidNum(_iq15 X, _iq15 X1, _iq15 X2, _iq15 Y1, _iq15 Y2);

/**
 *  @brief      Search the SOC value related to the OCV input
 *
 *  @param[in]  u16Ocv             OCV input search
 *  @param[in]  u8TableLength      The length of battery circuit table
 *  @param[in]  pCircuitTable       A pointer to the battery circuit table
 *
 *  @param[out] SOC                searched SOC
 *
 *  NOTE: Need to avoid X2 equal to X1
 */
_iq15 VGuage_BattSocSerach(
    _iq15 iq15Ocv, uint8_t u8TableLength, tBattCircuitParams *pCircuitTable);

/**
 *  @brief      Search the SOC value related to the OCV input
 *
 *  @param[in]  u16Ocv             OCV input search
 *  @param[in]  u8TableLength      The length of battery circuit table
 *  @param[in]  pCircuitTable       A pointer to the battery circuit table
 *
 *  @param[out] slopeRate
 *
 */
_iq20 VGauge_SlopeRateSearch(
    _iq15 iq15Ocv, uint8_t u8TableLength, tBattCircuitParams *pCircuitTable);

/**
 *  @brief      Search the SOC value related to the OCV input
 *
 *  @param[in]  u16Ocv             OCV input search
 *  @param[in]  u8TableLength      The length of battery circuit table
 *  @param[in]  pCircuitTable       A pointer to the battery circuit table
 *
 *  @param[out] Rcell
 *
 */
_iq15 VGuage_BattRcellSerach(_iq15 iq15Ocv, uint8_t u8TableLength,
    tBattCircuitParams *pCircuitTable, tBattInfoInput *pBattInfoInput,
    tBattParamsConfig *pBattParamsCfg);
#endif /* GAUGE_V_GAUGE_H_ */
