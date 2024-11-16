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

#include <ti/driverlib/dl_trng.h>

#ifdef __MSPM0_HAS_TRNG__

bool DL_TRNG_saveConfiguration(TRNG_Regs *trng, DL_TRNG_backupConfig *ptr)
{
    bool stateSaved = !ptr->backupRdy;
    if (stateSaved) {
        ptr->controlWord   = trng->CTL;
        ptr->clockDivider  = trng->CLKDIVIDE;
        ptr->interruptMask = trng->CPU_INT.IMASK;
        ptr->backupRdy     = true;
    }
    return stateSaved;
}

bool DL_TRNG_restoreConfiguration(TRNG_Regs *trng, DL_TRNG_backupConfig *ptr)
{
    bool stateRestored = ptr->backupRdy;
    if (stateRestored) {
        DL_Common_updateReg(
            &trng->CTL, ptr->controlWord, TRNG_CTL_DECIM_RATE_MASK);
        trng->CLKDIVIDE     = ptr->clockDivider;
        trng->CPU_INT.IMASK = ptr->interruptMask;

        /* If TRNG was originally in OFF state, then send PWROFF command */
        if (((ptr->controlWord & TRNG_STAT_FSM_STATE_MASK) >>
                TRNG_STAT_FSM_STATE_OFS) == (uint32_t) DL_TRNG_STATE_OFF) {
            DL_TRNG_sendCommand(trng, DL_TRNG_CMD_PWROFF);
        }

        ptr->backupRdy = false;
    }
    return stateRestored;
}

#endif /* __MSPM0_HAS_TRNG__ */
