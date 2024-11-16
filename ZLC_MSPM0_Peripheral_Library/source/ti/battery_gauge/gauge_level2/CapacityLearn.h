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
#ifndef GAUGE_ALGORITHM_CAPACITYLEARN_H_
#define GAUGE_ALGORITHM_CAPACITYLEARN_H_

#include "Gauge.h"
#include "Gauge_Type.h"

/**
 *  @brief      initialize  Capacity learn algorithm
 *  @param[in]  pBattGlobalParams        Pointer to the global battery parameters
 */
void CL_Init(tGaugeApplication *pGaugeApp);

/**
 *  @brief      Capacity learn algorithm running
 *  @param[in]  pBattGlobalParams        Pointer to the global battery parameters
 */
void CL_Handler(tGaugeApplication *pGaugeApp);

/**
 *  @brief      IIR filter
 *  @param[in]  u16Raw         Input Raw data
 *  @param[in]  u16Filtered    Previous filtered data
 *  @param[in]  ui8Beta        Filter level
 */
uint16_t CL_U16ComputeIIR(
    uint16_t u16Raw, uint16_t u16Filtered, uint8_t ui8Beta);

#endif /* GAUGE_ALGORITHM_CAPACITYLEARN_H_ */
