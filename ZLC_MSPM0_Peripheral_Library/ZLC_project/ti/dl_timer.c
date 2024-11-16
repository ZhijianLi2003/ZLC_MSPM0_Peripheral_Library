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

#include <ti/driverlib/dl_timera.h>
#include <ti/driverlib/dl_timerg.h>

#if defined(__MSPM0_HAS_TIMER_A__) || defined(__MSPM0_HAS_TIMER_G__)

typedef struct {
    DL_TIMER_CC_INDEX index;
    uint32_t ccpInput;
    uint32_t timerConfig;
    uint32_t ccpInputDir;
} Timer_Input_Chan_Config;

typedef struct {
    DL_TIMER_CC_INDEX index;
} Timer_Input_Pair_Chan_Config;

static void DL_Timer_getInChanConfig(
    DL_TIMER_INPUT_CHAN chan, Timer_Input_Chan_Config *config);
static void DL_Timer_getInChanPairConfig(
    DL_TIMER_INPUT_CHAN chan, Timer_Input_Pair_Chan_Config *config);

void DL_Timer_setClockConfig(
    GPTIMER_Regs *gptimer, DL_Timer_ClockConfig *config)
{
    gptimer->CLKSEL = (uint32_t)(config->clockSel);

    gptimer->CLKDIV = (uint32_t)(config->divideRatio);

    gptimer->COMMONREGS.CPS = (config->prescale);
}

void DL_Timer_getClockConfig(
    GPTIMER_Regs *gptimer, DL_Timer_ClockConfig *config)
{
    config->clockSel = (DL_TIMER_CLOCK)(gptimer->CLKSEL);

    config->divideRatio = (DL_TIMER_CLOCK_DIVIDE)(gptimer->CLKDIV);

    config->prescale = (uint8_t)(gptimer->COMMONREGS.CPS);
}

void DL_Timer_initTimerMode(
    GPTIMER_Regs *gptimer, DL_Timer_TimerConfig *config)
{
    DL_Timer_setLoadValue(gptimer, config->period);

    switch (config->timerMode) {
        /* All four cases below should set counter value to ZERO when enabled */
        case DL_TIMER_TIMER_MODE_ONE_SHOT_UP:
        case DL_TIMER_TIMER_MODE_PERIODIC_UP:
        case DL_TIMER_TIMER_MODE_ONE_SHOT_UP_DOWN:
        case DL_TIMER_TIMER_MODE_PERIODIC_UP_DOWN:
            DL_Timer_setCounterValueAfterEnable(
                gptimer, DL_TIMER_COUNT_AFTER_EN_ZERO);
            break;
        /* The two cases below should set counter value to LOAD when enabled */
        case DL_TIMER_TIMER_MODE_ONE_SHOT:
        case DL_TIMER_TIMER_MODE_PERIODIC:
            DL_Timer_setCounterValueAfterEnable(
                gptimer, DL_TIMER_COUNT_AFTER_EN_LOAD_VAL);
            break;
        default:
            /* Code should not reach this case */
            break;
    }

    DL_Timer_setCaptureCompareValue(
        gptimer, config->counterVal, DL_TIMER_CC_0_INDEX);

    DL_Timer_setCaptureCompareCtl(gptimer, (uint32_t) config->genIntermInt,
        DL_TIMER_CC_ACOND_TIMCLK, DL_TIMER_CC_0_INDEX);

    gptimer->COUNTERREGS.CTRCTL =
        ((uint32_t) config->timerMode | (uint32_t) config->startTimer);
}

void DL_Timer_initCaptureMode(
    GPTIMER_Regs *gptimer, DL_Timer_CaptureConfig *config)
{
    Timer_Input_Chan_Config captConfig;

    DL_Timer_getInChanConfig(config->inputChan, &captConfig);

    DL_Timer_setCaptureCompareInput(gptimer, (uint32_t) config->inputInvMode,
        captConfig.ccpInput, captConfig.index);

    DL_Timer_setLoadValue(gptimer, config->period);

    switch (config->captureMode) {
        case DL_TIMER_CAPTURE_MODE_EDGE_TIME:
            DL_Timer_setCaptureCompareCtl(gptimer, DL_TIMER_CC_MODE_CAPTURE,
                (DL_TIMER_CC_ZCOND_NONE | DL_TIMER_CC_ACOND_TIMCLK |
                    DL_TIMER_CC_LCOND_NONE | (uint32_t) config->edgeCaptMode),
                captConfig.index);
            break;
        case DL_TIMER_CAPTURE_MODE_PERIOD_CAPTURE:
            if (DL_TIMER_CAPTURE_EDGE_DETECTION_MODE_RISING ==
                config->edgeCaptMode) {
                DL_Timer_setCaptureCompareCtl(gptimer,
                    DL_TIMER_CC_MODE_CAPTURE,
                    (DL_TIMER_CC_ZCOND_NONE | DL_TIMER_CC_ACOND_TIMCLK |
                        DL_TIMER_CC_LCOND_TRIG_RISE |
                        (uint32_t) config->edgeCaptMode),
                    captConfig.index);
            } else {
                DL_Timer_setCaptureCompareCtl(gptimer,
                    DL_TIMER_CC_MODE_CAPTURE,
                    (DL_TIMER_CC_ZCOND_NONE | DL_TIMER_CC_ACOND_TIMCLK |
                        DL_TIMER_CC_LCOND_TRIG_FALL |
                        (uint32_t) config->edgeCaptMode),
                    captConfig.index);
            }
            break;
        case DL_TIMER_CAPTURE_MODE_PULSE_WIDTH:
            if (DL_TIMER_CAPTURE_EDGE_DETECTION_MODE_RISING ==
                config->edgeCaptMode) {
                DL_Timer_setCaptureCompareCtl(gptimer,
                    DL_TIMER_CC_MODE_CAPTURE,
                    (DL_TIMER_CC_ZCOND_NONE | DL_TIMER_CC_ACOND_TIMCLK |
                        DL_TIMER_CC_LCOND_TRIG_RISE |
                        DL_TIMER_CC_CCOND_TRIG_FALL),
                    captConfig.index);
            } else {
                DL_Timer_setCaptureCompareCtl(gptimer,
                    DL_TIMER_CC_MODE_CAPTURE,
                    (DL_TIMER_CC_ZCOND_NONE | DL_TIMER_CC_ACOND_TIMCLK |
                        DL_TIMER_CC_LCOND_TRIG_FALL |
                        DL_TIMER_CC_CCOND_TRIG_RISE),
                    captConfig.index);
            }
            break;
        default:
            break;
    }

    DL_Timer_setCCPDirection(gptimer, captConfig.ccpInputDir);

    switch (config->captureMode) {
        case DL_TIMER_CAPTURE_MODE_EDGE_TIME_UP:
        case DL_TIMER_CAPTURE_MODE_PERIOD_CAPTURE_UP:
        case DL_TIMER_CAPTURE_MODE_PULSE_WIDTH_UP:
            captConfig.timerConfig =
                ((uint32_t) captConfig.timerConfig | GPTIMER_CTRCTL_CM_UP);
            break;
        default:
            /* Default timer count is down counting mode. No need to
              change counting mode */
            break;
    }

    DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
        ((uint32_t) captConfig.timerConfig | GPTIMER_CTRCTL_CVAE_LDVAL |
            GPTIMER_CTRCTL_CM_DOWN | GPTIMER_CTRCTL_REPEAT_REPEAT_1 |
            (uint32_t) config->startTimer),
        (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
            GPTIMER_CTRCTL_CLC_MASK | GPTIMER_CTRCTL_CVAE_MASK |
            GPTIMER_CTRCTL_CM_MASK | GPTIMER_CTRCTL_REPEAT_MASK |
            GPTIMER_CTRCTL_EN_MASK));
}

void DL_Timer_initCaptureTriggerMode(
    GPTIMER_Regs *gptimer, DL_Timer_CaptureTriggerConfig *config)
{
    DL_Timer_setLoadValue(gptimer, config->period);

    DL_Timer_setCaptureCompareInput(gptimer, DL_TIMER_CC_INPUT_INV_NOINVERT,
        DL_TIMER_CC_IN_SEL_TRIG, DL_TIMER_CC_0_INDEX);

    switch (config->captureMode) {
        case DL_TIMER_CAPTURE_MODE_EDGE_TIME:
            DL_Timer_setCaptureCompareCtl(gptimer, DL_TIMER_CC_MODE_CAPTURE,
                (DL_TIMER_CC_ZCOND_NONE | DL_TIMER_CC_ACOND_TIMCLK |
                    DL_TIMER_CC_LCOND_NONE | DL_TIMER_CC_CCOND_TRIG_RISE),
                DL_TIMER_CC_0_INDEX);
            break;
        case DL_TIMER_CAPTURE_MODE_PERIOD_CAPTURE:
            DL_Timer_setCaptureCompareCtl(gptimer, DL_TIMER_CC_MODE_CAPTURE,
                (DL_TIMER_CC_ZCOND_NONE | DL_TIMER_CC_ACOND_TIMCLK |
                    DL_TIMER_CC_LCOND_TRIG_RISE | DL_TIMER_CC_CCOND_TRIG_RISE),
                DL_TIMER_CC_0_INDEX);
            break;
        case DL_TIMER_CAPTURE_MODE_PULSE_WIDTH:
            DL_Timer_setCaptureCompareCtl(gptimer, DL_TIMER_CC_MODE_CAPTURE,
                (DL_TIMER_CC_ZCOND_NONE | DL_TIMER_CC_ACOND_TIMCLK |
                    DL_TIMER_CC_LCOND_TRIG_RISE | DL_TIMER_CC_CCOND_TRIG_FALL),
                DL_TIMER_CC_0_INDEX);
            break;
        default:
            break;
    }

    switch (config->captureMode) {
        case DL_TIMER_CAPTURE_MODE_EDGE_TIME_UP:
        case DL_TIMER_CAPTURE_MODE_PERIOD_CAPTURE_UP:
        case DL_TIMER_CAPTURE_MODE_PULSE_WIDTH_UP:
            DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
                (GPTIMER_CTRCTL_CLC_CCCTL0_LCOND |
                    GPTIMER_CTRCTL_CAC_CCCTL0_ACOND |
                    GPTIMER_CTRCTL_CZC_CCCTL0_ZCOND |
                    GPTIMER_CTRCTL_CVAE_LDVAL | GPTIMER_CTRCTL_CM_UP |
                    GPTIMER_CTRCTL_REPEAT_REPEAT_1 |
                    (uint32_t) config->startTimer),
                (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
                    GPTIMER_CTRCTL_CLC_MASK | GPTIMER_CTRCTL_CVAE_MASK |
                    GPTIMER_CTRCTL_CM_MASK | GPTIMER_CTRCTL_REPEAT_MASK |
                    GPTIMER_CTRCTL_EN_MASK));
            break;
        default:
            DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
                (GPTIMER_CTRCTL_CLC_CCCTL0_LCOND |
                    GPTIMER_CTRCTL_CAC_CCCTL0_ACOND |
                    GPTIMER_CTRCTL_CZC_CCCTL0_ZCOND |
                    GPTIMER_CTRCTL_CVAE_LDVAL | GPTIMER_CTRCTL_CM_DOWN |
                    GPTIMER_CTRCTL_REPEAT_REPEAT_1 |
                    (uint32_t) config->startTimer),
                (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
                    GPTIMER_CTRCTL_CLC_MASK | GPTIMER_CTRCTL_CVAE_MASK |
                    GPTIMER_CTRCTL_CM_MASK | GPTIMER_CTRCTL_REPEAT_MASK |
                    GPTIMER_CTRCTL_EN_MASK));
            break;
    }
}

void DL_Timer_initCaptureCombinedMode(
    GPTIMER_Regs *gptimer, DL_Timer_CaptureCombinedConfig *config)
{
    Timer_Input_Chan_Config captConfig;
    Timer_Input_Pair_Chan_Config captPairConfig;

    DL_Timer_getInChanConfig(config->inputChan, &captConfig);
    DL_Timer_getInChanPairConfig(config->inputChan, &captPairConfig);

    DL_Timer_setLoadValue(gptimer, config->period);

    DL_Timer_setCaptureCompareInput(gptimer, (uint32_t) config->inputInvMode,
        captConfig.ccpInput, captConfig.index);
    DL_Timer_setCaptureCompareInput(gptimer, (uint32_t) config->inputInvMode,
        GPTIMER_IFCTL_01_ISEL_CCPX_INPUT_PAIR, captPairConfig.index);

    /*
     * Setting load condition to none due to GPTimer combined capture limitation
     */
    DL_Timer_setCaptureCompareCtl(gptimer, DL_TIMER_CC_MODE_CAPTURE,
        (DL_TIMER_CC_ZCOND_NONE | DL_TIMER_CC_ACOND_TIMCLK |
            DL_TIMER_CC_LCOND_NONE | DL_TIMER_CC_CCOND_TRIG_FALL),
        captConfig.index);
    DL_Timer_setCaptureCompareCtl(gptimer, DL_TIMER_CC_MODE_CAPTURE,
        (DL_TIMER_CC_ZCOND_NONE | DL_TIMER_CC_ACOND_TIMCLK |
            DL_TIMER_CC_LCOND_NONE | DL_TIMER_CC_CCOND_TRIG_RISE),
        captPairConfig.index);

    DL_Timer_setCCPDirection(gptimer, captConfig.ccpInputDir);

    switch (config->captureMode) {
        case DL_TIMER_CAPTURE_COMBINED_MODE_PULSE_WIDTH_AND_PERIOD_UP:
            captConfig.timerConfig =
                ((uint32_t) captConfig.timerConfig | GPTIMER_CTRCTL_CM_UP);
            break;
        default:
            /* Default timer count is down counting mode. No need to
              change counting mode */
            break;
    }

    DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
        ((uint32_t) captConfig.timerConfig | GPTIMER_CTRCTL_CVAE_LDVAL |
            GPTIMER_CTRCTL_CM_DOWN | GPTIMER_CTRCTL_REPEAT_REPEAT_1 |
            (uint32_t) config->startTimer),
        (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
            GPTIMER_CTRCTL_CLC_MASK | GPTIMER_CTRCTL_CVAE_MASK |
            GPTIMER_CTRCTL_CM_MASK | GPTIMER_CTRCTL_REPEAT_MASK |
            GPTIMER_CTRCTL_EN_MASK));
}

void DL_Timer_initCompareMode(
    GPTIMER_Regs *gptimer, DL_Timer_CompareConfig *config)
{
    Timer_Input_Chan_Config inChanConfig;

    DL_Timer_getInChanConfig(config->inputChan, &inChanConfig);

    DL_Timer_setCaptureCompareInput(gptimer, (uint32_t) config->inputInvMode,
        inChanConfig.ccpInput, inChanConfig.index);

    DL_Timer_setLoadValue(gptimer, config->count);

    DL_Timer_setCaptureCompareCtl(gptimer, DL_TIMER_CC_MODE_COMPARE,
        (DL_TIMER_CC_ZCOND_NONE | (uint32_t) config->edgeDetectMode |
            DL_TIMER_CC_LCOND_NONE | DL_TIMER_CC_CCOND_NOCAPTURE),
        inChanConfig.index);

    switch (config->compareMode) {
        case DL_TIMER_COMPARE_MODE_EDGE_COUNT:
            DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
                ((uint32_t) inChanConfig.timerConfig |
                    GPTIMER_CTRCTL_CVAE_LDVAL | GPTIMER_CTRCTL_CM_DOWN |
                    GPTIMER_CTRCTL_REPEAT_REPEAT_1 |
                    (uint32_t) config->startTimer),
                (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
                    GPTIMER_CTRCTL_CLC_MASK | GPTIMER_CTRCTL_CVAE_MASK |
                    GPTIMER_CTRCTL_CM_MASK | GPTIMER_CTRCTL_REPEAT_MASK |
                    GPTIMER_CTRCTL_EN_MASK));
            break;
        case DL_TIMER_COMPARE_MODE_EDGE_COUNT_UP:
            DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
                ((uint32_t) inChanConfig.timerConfig |
                    GPTIMER_CTRCTL_CVAE_LDVAL | GPTIMER_CTRCTL_CM_UP |
                    GPTIMER_CTRCTL_REPEAT_REPEAT_1 |
                    (uint32_t) config->startTimer),
                (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
                    GPTIMER_CTRCTL_CLC_MASK | GPTIMER_CTRCTL_CVAE_MASK |
                    GPTIMER_CTRCTL_CM_MASK | GPTIMER_CTRCTL_REPEAT_MASK |
                    GPTIMER_CTRCTL_EN_MASK));
            break;
        case DL_TIMER_COMPARE_MODE_EDGE_COUNT_UP_DOWN:
            DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
                ((uint32_t) inChanConfig.timerConfig |
                    GPTIMER_CTRCTL_CVAE_LDVAL | GPTIMER_CTRCTL_CM_UP_DOWN |
                    GPTIMER_CTRCTL_REPEAT_REPEAT_1 |
                    (uint32_t) config->startTimer),
                (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
                    GPTIMER_CTRCTL_CLC_MASK | GPTIMER_CTRCTL_CVAE_MASK |
                    GPTIMER_CTRCTL_CM_MASK | GPTIMER_CTRCTL_REPEAT_MASK |
                    GPTIMER_CTRCTL_EN_MASK));
            break;
        default:
            /* Code should not reach this case */
            break;
    }
}

void DL_Timer_initCompareTriggerMode(
    GPTIMER_Regs *gptimer, DL_Timer_CompareTriggerConfig *config)
{
    DL_Timer_setCaptureCompareInput(gptimer, DL_TIMER_CC_INPUT_INV_NOINVERT,
        DL_TIMER_CC_IN_SEL_TRIG, DL_TIMER_CC_0_INDEX);

    DL_Timer_setLoadValue(gptimer, config->count);

    DL_Timer_setCaptureCompareCtl(gptimer, DL_TIMER_CC_MODE_COMPARE,
        (DL_TIMER_CC_ZCOND_NONE | (uint32_t) config->edgeDetectMode |
            DL_TIMER_CC_LCOND_NONE | DL_TIMER_CC_CCOND_NOCAPTURE),
        DL_TIMER_CC_0_INDEX);

    switch (config->compareMode) {
        case DL_TIMER_COMPARE_MODE_EDGE_COUNT:
            DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
                (GPTIMER_CTRCTL_CLC_CCCTL0_LCOND |
                    GPTIMER_CTRCTL_CAC_CCCTL0_ACOND |
                    GPTIMER_CTRCTL_CZC_CCCTL0_ZCOND |
                    GPTIMER_CTRCTL_CVAE_LDVAL | GPTIMER_CTRCTL_CM_DOWN |
                    GPTIMER_CTRCTL_REPEAT_REPEAT_1 |
                    (uint32_t) config->startTimer),
                (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
                    GPTIMER_CTRCTL_CLC_MASK | GPTIMER_CTRCTL_CVAE_MASK |
                    GPTIMER_CTRCTL_CM_MASK | GPTIMER_CTRCTL_REPEAT_MASK |
                    GPTIMER_CTRCTL_EN_MASK));
            break;
        case DL_TIMER_COMPARE_MODE_EDGE_COUNT_UP:
            DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
                (GPTIMER_CTRCTL_CLC_CCCTL0_LCOND |
                    GPTIMER_CTRCTL_CAC_CCCTL0_ACOND |
                    GPTIMER_CTRCTL_CZC_CCCTL0_ZCOND |
                    GPTIMER_CTRCTL_CVAE_LDVAL | GPTIMER_CTRCTL_CM_UP |
                    GPTIMER_CTRCTL_REPEAT_REPEAT_1 |
                    (uint32_t) config->startTimer),
                (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
                    GPTIMER_CTRCTL_CLC_MASK | GPTIMER_CTRCTL_CVAE_MASK |
                    GPTIMER_CTRCTL_CM_MASK | GPTIMER_CTRCTL_REPEAT_MASK |
                    GPTIMER_CTRCTL_EN_MASK));
            break;
        case DL_TIMER_COMPARE_MODE_EDGE_COUNT_UP_DOWN:
            DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
                (GPTIMER_CTRCTL_CLC_CCCTL0_LCOND |
                    GPTIMER_CTRCTL_CAC_CCCTL0_ACOND |
                    GPTIMER_CTRCTL_CZC_CCCTL0_ZCOND |
                    GPTIMER_CTRCTL_CVAE_LDVAL | GPTIMER_CTRCTL_CM_UP_DOWN |
                    GPTIMER_CTRCTL_REPEAT_REPEAT_1 |
                    (uint32_t) config->startTimer),
                (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
                    GPTIMER_CTRCTL_CLC_MASK | GPTIMER_CTRCTL_CVAE_MASK |
                    GPTIMER_CTRCTL_CM_MASK | GPTIMER_CTRCTL_REPEAT_MASK |
                    GPTIMER_CTRCTL_EN_MASK));
            break;
        default:
            /* Code should not reach this case */
            break;
    }
}

void DL_Timer_initPWMMode(GPTIMER_Regs *gptimer, DL_Timer_PWMConfig *config)
{
    switch (config->pwmMode) {
        case DL_TIMER_PWM_MODE_EDGE_ALIGN:
            DL_Timer_setLoadValue(gptimer, (config->period - (uint32_t) 1));
            DL_Timer_setCaptureCompareAction(gptimer,
                (DL_TIMER_CC_LACT_CCP_HIGH | DL_TIMER_CC_CDACT_CCP_LOW),
                DL_TIMER_CC_0_INDEX);
            DL_Timer_setCaptureCompareAction(gptimer,
                (DL_TIMER_CC_LACT_CCP_HIGH | DL_TIMER_CC_CDACT_CCP_LOW),
                DL_TIMER_CC_1_INDEX);
            break;
        case DL_TIMER_PWM_MODE_EDGE_ALIGN_UP:
            DL_Timer_setLoadValue(gptimer, (config->period - (uint32_t) 1));
            DL_Timer_setCaptureCompareAction(gptimer,
                (DL_TIMER_CC_ZACT_CCP_HIGH | DL_TIMER_CC_CUACT_CCP_LOW),
                DL_TIMER_CC_0_INDEX);
            DL_Timer_setCaptureCompareAction(gptimer,
                (DL_TIMER_CC_ZACT_CCP_HIGH | DL_TIMER_CC_CUACT_CCP_LOW),
                DL_TIMER_CC_1_INDEX);
            DL_Timer_setCounterValueAfterEnable(
                gptimer, DL_TIMER_COUNT_AFTER_EN_ZERO);
            break;
        default:  // DL_TIMER_PWM_MODE_CENTER_ALIGN
            DL_Timer_setLoadValue(gptimer, (config->period >> 1));
            DL_Timer_setCaptureCompareAction(gptimer,
                (DL_TIMER_CC_CUACT_CCP_HIGH | DL_TIMER_CC_CDACT_CCP_LOW),
                DL_TIMER_CC_0_INDEX);
            DL_Timer_setCaptureCompareAction(gptimer,
                (DL_TIMER_CC_CUACT_CCP_HIGH | DL_TIMER_CC_CDACT_CCP_LOW),
                DL_TIMER_CC_1_INDEX);
            break;
    }

    DL_Timer_setCaptureCompareCtl(
        gptimer, DL_TIMER_CC_MODE_COMPARE, 0, DL_TIMER_CC_0_INDEX);

    DL_Timer_setCaptureCompareCtl(
        gptimer, DL_TIMER_CC_MODE_COMPARE, 0, DL_TIMER_CC_1_INDEX);

    DL_Timer_setCaptureCompareOutCtl(gptimer, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
        DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
        DL_TIMER_CC_0_INDEX);

    DL_Timer_setCaptureCompareOutCtl(gptimer, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
        DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
        DL_TIMER_CC_1_INDEX);

    DL_Timer_setCaptureCompareInput(gptimer, DL_TIMER_CC_INPUT_INV_NOINVERT,
        DL_TIMER_CC_IN_SEL_CCPX, DL_TIMER_CC_0_INDEX);

    DL_Timer_setCaptureCompareInput(gptimer, DL_TIMER_CC_INPUT_INV_NOINVERT,
        DL_TIMER_CC_IN_SEL_CCPX, DL_TIMER_CC_1_INDEX);

    DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
        (GPTIMER_CTRCTL_REPEAT_REPEAT_1 | (uint32_t) config->pwmMode |
            (uint32_t) config->startTimer),
        (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
            GPTIMER_CTRCTL_CLC_MASK | GPTIMER_CTRCTL_CVAE_MASK |
            GPTIMER_CTRCTL_CM_MASK | GPTIMER_CTRCTL_REPEAT_MASK |
            GPTIMER_CTRCTL_EN_MASK));
}

void DL_Timer_setCaptureCompareValue(
    GPTIMER_Regs *gptimer, uint32_t value, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CC_01[0];
    pReg += (uint32_t) ccIndex;

    *pReg = (value);
}

uint32_t DL_Timer_getCaptureCompareValue(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CC_01[0];
    pReg += (uint32_t) ccIndex;

    return (*pReg & GPTIMER_CC_01_CCVAL_MASK);
}

void DL_Timer_setCaptureCompareCtl(GPTIMER_Regs *gptimer, uint32_t ccMode,
    uint32_t ccCondMask, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CCCTL_01[0];
    pReg += (uint32_t) ccIndex;

    DL_Common_updateReg(pReg, (ccMode | ccCondMask),
        (GPTIMER_CCCTL_01_COC_MASK | GPTIMER_CCCTL_01_ZCOND_MASK |
            GPTIMER_CCCTL_01_LCOND_MASK | GPTIMER_CCCTL_01_ACOND_MASK |
            GPTIMER_CCCTL_01_CCOND_MASK));
}

uint32_t DL_Timer_getCaptureCompareCtl(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CCCTL_01[0];
    pReg += (uint32_t) ccIndex;

    return (
        *pReg & (GPTIMER_CCCTL_01_COC_MASK | GPTIMER_CCCTL_01_ZCOND_MASK |
                    GPTIMER_CCCTL_01_LCOND_MASK | GPTIMER_CCCTL_01_ACOND_MASK |
                    GPTIMER_CCCTL_01_CCOND_MASK));
}

void DL_Timer_enableSuppressionOfCompEvent(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CCCTL_01[0];
    pReg += (uint32_t) ccIndex;

    *pReg |= (GPTIMER_CCCTL_01_SCERCNEZ_ENABLED);
}

void DL_Timer_disableSuppressionOfCompEvent(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CCCTL_01[0];
    pReg += (uint32_t) ccIndex;

    *pReg &= ~(GPTIMER_CCCTL_01_SCERCNEZ_ENABLED);
}

void DL_Timer_setCaptCompUpdateMethod(GPTIMER_Regs *gptimer,
    DL_TIMER_CC_UPDATE_METHOD ccUpdtMode, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CCCTL_01[0];
    pReg += (uint32_t) ccIndex;

    DL_Common_updateReg(
        pReg, (uint32_t) ccUpdtMode, GPTIMER_CCCTL_01_CCUPD_MASK);
}

DL_TIMER_CC_UPDATE_METHOD DL_Timer_getCaptCompUpdateMethod(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CCCTL_01[0];
    pReg += (uint32_t) ccIndex;

    uint32_t ccUpdtMode = *pReg & GPTIMER_CCCTL_01_CCUPD_MASK;

    return ((DL_TIMER_CC_UPDATE_METHOD)(ccUpdtMode));
}

void DL_Timer_setCaptureCompareOutCtl(GPTIMER_Regs *gptimer, uint32_t ccpIV,
    uint32_t ccpOInv, uint32_t ccpO, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.OCTL_01[0];
    pReg += (uint32_t) ccIndex;

    *pReg = (ccpIV | ccpOInv | ccpO);
}

uint32_t DL_Timer_getCaptureCompareOutCtl(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.OCTL_01[0];
    pReg += (uint32_t) ccIndex;

    return (*pReg);
}

void DL_Timer_setCaptureCompareAction(
    GPTIMER_Regs *gptimer, uint32_t actionsMask, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CCACT_01[0];
    pReg += (uint32_t) ccIndex;

    DL_Common_updateReg(pReg, (uint32_t) actionsMask,
        (GPTIMER_CCACT_01_FEXACT_MASK | GPTIMER_CCACT_01_FENACT_MASK |
            GPTIMER_CCACT_01_CUACT_MASK | GPTIMER_CCACT_01_CDACT_MASK |
            GPTIMER_CCACT_01_LACT_MASK | GPTIMER_CCACT_01_ZACT_MASK));
}

uint32_t DL_Timer_getCaptureCompareAction(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CCACT_01[0];
    pReg += (uint32_t) ccIndex;

    return (
        *pReg & (GPTIMER_CCACT_01_FEXACT_MASK | GPTIMER_CCACT_01_FENACT_MASK |
                    GPTIMER_CCACT_01_CUACT_MASK | GPTIMER_CCACT_01_CDACT_MASK |
                    GPTIMER_CCACT_01_LACT_MASK | GPTIMER_CCACT_01_ZACT_MASK));
}

void DL_Timer_overrideCCPOut(GPTIMER_Regs *gptimer, DL_TIMER_FORCE_OUT out,
    DL_TIMER_FORCE_CMPL_OUT outComp, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CCACT_01[0];
    pReg += (uint32_t) ccIndex;

    DL_Common_updateReg(pReg, ((uint32_t) out | ((uint32_t) outComp)),
        (GPTIMER_CCACT_01_SWFRCACT_CMPL_MASK |
            GPTIMER_CCACT_01_SWFRCACT_MASK));
}

void DL_Timer_setCaptureCompareInput(GPTIMER_Regs *gptimer, uint32_t inv,
    uint32_t isel, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.IFCTL_01[0];
    pReg += (uint32_t) ccIndex;

    DL_Common_updateReg(pReg, (inv | isel),
        (GPTIMER_IFCTL_01_INV_MASK | GPTIMER_IFCTL_01_ISEL_MASK));
}

uint32_t DL_Timer_getCaptureCompareInput(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.IFCTL_01[0];
    pReg += (uint32_t) ccIndex;

    return (*pReg & (GPTIMER_IFCTL_01_INV_MASK | GPTIMER_IFCTL_01_ISEL_MASK));
}

void DL_Timer_setCaptureCompareInputFilter(GPTIMER_Regs *gptimer, uint32_t cpv,
    uint32_t fp, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.IFCTL_01[0];
    pReg += (uint32_t) ccIndex;

    DL_Common_updateReg(pReg, (cpv | fp),
        (GPTIMER_IFCTL_01_CPV_MASK | GPTIMER_IFCTL_01_FP_MASK));
}

uint32_t DL_Timer_getCaptureCompareInputFilter(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.IFCTL_01[0];
    pReg += (uint32_t) ccIndex;

    return (*pReg & (GPTIMER_IFCTL_01_CPV_MASK | GPTIMER_IFCTL_01_FP_MASK));
}

void DL_Timer_enableCaptureCompareInputFilter(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.IFCTL_01[0];
    pReg += (uint32_t) ccIndex;

    *pReg |= (GPTIMER_IFCTL_01_FE_ENABLED);
}

void DL_Timer_disableCaptureCompareInputFilter(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.IFCTL_01[0];
    pReg += (uint32_t) ccIndex;

    *pReg &= ~(GPTIMER_IFCTL_01_FE_ENABLED);
}

bool DL_Timer_isCaptureCompareInputFilterEnabled(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.IFCTL_01[0];
    pReg += (uint32_t) ccIndex;

    return (GPTIMER_IFCTL_01_FE_ENABLED == (*pReg & GPTIMER_IFCTL_01_FE_MASK));
}

bool DL_Timer_saveConfiguration(
    GPTIMER_Regs *gptimer, DL_Timer_backupConfig *ptr)
{
    bool saveState = !ptr->backupRdy;
    if (saveState) {
        /* Generic Events configuration */
        ptr->sub0PortConf = gptimer->FSUB_0;
        ptr->sub1PortConf = gptimer->FSUB_1;
        ptr->pub0PortConf = gptimer->FPUB_0;
        ptr->pub1PortConf = gptimer->FPUB_1;

        /* Clock configuration */
        ptr->clkDivConf   = gptimer->CLKDIV;
        ptr->clockPscConf = gptimer->COMMONREGS.CPS;
        ptr->clkSelConf   = gptimer->CLKSEL;
        ptr->countClkConf = gptimer->COMMONREGS.CCLKCTL;

        /* Interrupt and Event Configuration */
        ptr->intEvnt0Conf = gptimer->CPU_INT.IMASK;
        ptr->intEvnt1Conf = gptimer->GEN_EVENT0.IMASK;
        ptr->intEvnt2Conf = gptimer->GEN_EVENT1.IMASK;

        /* Cross-trigger configuration */
        ptr->crossTrigCtl  = gptimer->COMMONREGS.CTTRIGCTL;
        ptr->crossTrigConf = gptimer->COMMONREGS.CTTRIG;

        /* Timer configuration */
        ptr->cntVal     = gptimer->COUNTERREGS.CTR;
        ptr->cntCtlConf = gptimer->COUNTERREGS.CTRCTL;
        ptr->loadVal    = gptimer->COUNTERREGS.LOAD;
        ptr->tSelConf   = gptimer->COUNTERREGS.TSEL;
        ptr->ccpDirConf = gptimer->COMMONREGS.CCPD;
        ptr->outDisConf = gptimer->COMMONREGS.ODIS;

        /* Capture or Compare configuration */
        ptr->cc0Val     = gptimer->COUNTERREGS.CC_01[0];
        ptr->cc1Val     = gptimer->COUNTERREGS.CC_01[1];
        ptr->cc0Ctl     = gptimer->COUNTERREGS.CCCTL_01[0];
        ptr->cc1Ctl     = gptimer->COUNTERREGS.CCCTL_01[1];
        ptr->cc0OutCtl  = gptimer->COUNTERREGS.OCTL_01[0];
        ptr->cc1OutCtl  = gptimer->COUNTERREGS.OCTL_01[1];
        ptr->cc0ActCtl  = gptimer->COUNTERREGS.CCACT_01[0];
        ptr->cc1ActCtl  = gptimer->COUNTERREGS.CCACT_01[1];
        ptr->in0FiltCtl = gptimer->COUNTERREGS.IFCTL_01[0];
        ptr->in1FiltCtl = gptimer->COUNTERREGS.IFCTL_01[1];

        ptr->backupRdy = true;
    }
    return saveState;
}

bool DL_Timer_restoreConfiguration(
    GPTIMER_Regs *gptimer, DL_Timer_backupConfig *ptr, bool restoreCounter)
{
    bool stateRestored = ptr->backupRdy;
    if (stateRestored) {
        ptr->backupRdy = false;
        /* Generic Events Configuration */
        gptimer->FSUB_0 = ptr->sub0PortConf;
        gptimer->FSUB_1 = ptr->sub1PortConf;
        gptimer->FPUB_0 = ptr->pub0PortConf;
        gptimer->FPUB_1 = ptr->pub1PortConf;

        /* Clock Configuration */
        gptimer->CLKSEL = ptr->clkSelConf;
        gptimer->CLKDIV = ptr->clkDivConf;

        /**
         *  Since the only difference between TIMG and TIMH is the prescaler
         * register, restore function will ommit restoring prescaler by
         * comparing to gptimer pointer to the TIMH0 expected base address
         * (i.e. 0x40880000U) in MSPM0G devices. MSPM0L devices don't have a
         * TIMH instances.*/
        if (((uint32_t) &gptimer) == 0x40880000U) {
            gptimer->COMMONREGS.CPS = ptr->clockPscConf;
        } else {
            // Configuration of prescaler is ommited
        }
        gptimer->COMMONREGS.CCLKCTL = ptr->countClkConf;

        /* Timer Configuration */
        if (true == restoreCounter) {
            gptimer->COUNTERREGS.CTR = ptr->cntVal;
        }
        gptimer->COUNTERREGS.LOAD = ptr->loadVal;
        gptimer->COUNTERREGS.TSEL = ptr->tSelConf;
        gptimer->COMMONREGS.CCPD  = ptr->ccpDirConf;
        gptimer->COMMONREGS.ODIS  = ptr->outDisConf;

        /* Capture or Compare Configuration */
        gptimer->COUNTERREGS.CC_01[0]    = ptr->cc0Val;
        gptimer->COUNTERREGS.CC_01[1]    = ptr->cc1Val;
        gptimer->COUNTERREGS.CCCTL_01[0] = ptr->cc0Ctl;
        gptimer->COUNTERREGS.CCCTL_01[1] = ptr->cc1Ctl;
        gptimer->COUNTERREGS.OCTL_01[0]  = ptr->cc0OutCtl;
        gptimer->COUNTERREGS.OCTL_01[1]  = ptr->cc1OutCtl;
        gptimer->COUNTERREGS.CCACT_01[0] = ptr->cc0ActCtl;
        gptimer->COUNTERREGS.CCACT_01[1] = ptr->cc1ActCtl;
        gptimer->COUNTERREGS.IFCTL_01[0] = ptr->in0FiltCtl;
        gptimer->COUNTERREGS.IFCTL_01[1] = ptr->in1FiltCtl;

        /* Cross-trigger Configuration */
        gptimer->COMMONREGS.CTTRIGCTL = ptr->crossTrigCtl;
        gptimer->COMMONREGS.CTTRIG    = ptr->crossTrigConf;

        /* Interrupt and Event Configuration */
        gptimer->CPU_INT.IMASK    = ptr->intEvnt0Conf;
        gptimer->GEN_EVENT0.IMASK = ptr->intEvnt1Conf;
        gptimer->GEN_EVENT1.IMASK = ptr->intEvnt2Conf;

        /* Restores Timer counter state until the end to prevent unexpected
         * behavior */
        gptimer->COUNTERREGS.CTRCTL = ptr->cntCtlConf;
    }
    return stateRestored;
}

#ifdef __MSPM0_HAS_TIMER_A__

void DL_TimerA_initPWMMode(GPTIMER_Regs *gptimer, DL_TimerA_PWMConfig *config)
{
    DL_Timer_PWMConfig pwmConfig;

    if (true == config->isTimerWithFourCC) {
        switch (config->pwmMode) {
            case DL_TIMER_PWM_MODE_EDGE_ALIGN:
                DL_Timer_setCaptureCompareAction(gptimer,
                    (DL_TIMER_CC_LACT_CCP_HIGH | DL_TIMER_CC_CDACT_CCP_LOW),
                    DL_TIMER_CC_2_INDEX);
                DL_Timer_setCaptureCompareAction(gptimer,
                    (DL_TIMER_CC_LACT_CCP_HIGH | DL_TIMER_CC_CDACT_CCP_LOW),
                    DL_TIMER_CC_3_INDEX);
                break;
            case DL_TIMER_PWM_MODE_EDGE_ALIGN_UP:
                DL_Timer_setCaptureCompareAction(gptimer,
                    (DL_TIMER_CC_LACT_CCP_LOW | DL_TIMER_CC_CUACT_CCP_HIGH),
                    DL_TIMER_CC_2_INDEX);
                DL_Timer_setCaptureCompareAction(gptimer,
                    (DL_TIMER_CC_LACT_CCP_LOW | DL_TIMER_CC_CUACT_CCP_HIGH),
                    DL_TIMER_CC_3_INDEX);
                break;
            default:  // DL_TIMER_PWM_MODE_CENTER_ALIGN
                DL_Timer_setCaptureCompareAction(gptimer,
                    (DL_TIMER_CC_CUACT_CCP_HIGH | DL_TIMER_CC_CDACT_CCP_LOW),
                    DL_TIMER_CC_2_INDEX);
                DL_Timer_setCaptureCompareAction(gptimer,
                    (DL_TIMER_CC_CUACT_CCP_HIGH | DL_TIMER_CC_CDACT_CCP_LOW),
                    DL_TIMER_CC_3_INDEX);
                break;
        }

        DL_Timer_setCaptureCompareCtl(
            gptimer, DL_TIMER_CC_MODE_COMPARE, 0, DL_TIMER_CC_2_INDEX);

        DL_Timer_setCaptureCompareCtl(
            gptimer, DL_TIMER_CC_MODE_COMPARE, 0, DL_TIMER_CC_3_INDEX);

        DL_Timer_setCaptureCompareOutCtl(gptimer,
            DL_TIMER_CC_OCTL_INIT_VAL_LOW, DL_TIMER_CC_OCTL_INV_OUT_DISABLED,
            DL_TIMER_CC_OCTL_SRC_FUNCVAL, DL_TIMER_CC_2_INDEX);

        DL_Timer_setCaptureCompareOutCtl(gptimer,
            DL_TIMER_CC_OCTL_INIT_VAL_LOW, DL_TIMER_CC_OCTL_INV_OUT_DISABLED,
            DL_TIMER_CC_OCTL_SRC_FUNCVAL, DL_TIMER_CC_3_INDEX);

        DL_Timer_setCaptureCompareInput(gptimer,
            DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_IN_SEL_CCPX,
            DL_TIMER_CC_2_INDEX);

        DL_Timer_setCaptureCompareInput(gptimer,
            DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_IN_SEL_CCPX,
            DL_TIMER_CC_3_INDEX);
    }

    pwmConfig.period     = config->period;
    pwmConfig.pwmMode    = config->pwmMode;
    pwmConfig.startTimer = config->startTimer;

    DL_Timer_initPWMMode(gptimer, &pwmConfig);
}

void DL_Timer_setFaultSourceConfig(GPTIMER_Regs *gptimer, uint32_t source)
{
    DL_Common_updateReg(&gptimer->COUNTERREGS.FCTL,
        (source >> 16) &
            (GPTIMER_FCTL_FSENAC0_MASK | GPTIMER_FCTL_FSENAC1_MASK |
                GPTIMER_FCTL_FSENAC2_MASK | GPTIMER_FCTL_FSENEXT0_MASK |
                GPTIMER_FCTL_FSENEXT1_MASK | GPTIMER_FCTL_FSENEXT2_MASK),
        (GPTIMER_FCTL_FSENAC0_MASK | GPTIMER_FCTL_FSENAC1_MASK |
            GPTIMER_FCTL_FSENAC2_MASK | GPTIMER_FCTL_FSENEXT0_MASK |
            GPTIMER_FCTL_FSENEXT1_MASK | GPTIMER_FCTL_FSENEXT2_MASK));

    DL_Common_updateReg(&gptimer->COMMONREGS.FSCTL, source,
        (GPTIMER_FSCTL_FAC0EN_MASK | GPTIMER_FSCTL_FAC1EN_MASK |
            GPTIMER_FSCTL_FAC2EN_MASK | GPTIMER_FSCTL_FEX0EN_MASK |
            GPTIMER_FSCTL_FEX1EN_MASK | GPTIMER_FSCTL_FEX2EN_MASK));
}

uint32_t DL_Timer_getFaultSourceConfig(GPTIMER_Regs *gptimer)
{
    uint32_t faultMode;
    uint32_t faultSense;

    faultMode  = gptimer->COMMONREGS.FSCTL;
    faultSense = gptimer->COUNTERREGS.FCTL;

    return (((faultSense &
                 (GPTIMER_FCTL_FSENAC0_MASK | GPTIMER_FCTL_FSENAC1_MASK |
                     GPTIMER_FCTL_FSENAC2_MASK | GPTIMER_FCTL_FSENEXT0_MASK |
                     GPTIMER_FCTL_FSENEXT1_MASK | GPTIMER_FCTL_FSENEXT2_MASK))
                << 16) |
            (faultMode &
                ((GPTIMER_FSCTL_FAC0EN_MASK | GPTIMER_FSCTL_FAC1EN_MASK |
                    GPTIMER_FSCTL_FAC2EN_MASK | GPTIMER_FSCTL_FEX0EN_MASK |
                    GPTIMER_FSCTL_FEX1EN_MASK | GPTIMER_FSCTL_FEX2EN_MASK))));
}

bool DL_TimerA_saveConfiguration(
    GPTIMER_Regs *gptimer, DL_TimerA_backupConfig *ptr)
{
    bool saveState = !ptr->backupRdy;
    if (saveState) {
        /* Generic Events configuration */
        ptr->sub0PortConf = gptimer->FSUB_0;
        ptr->sub1PortConf = gptimer->FSUB_1;
        ptr->pub0PortConf = gptimer->FPUB_0;
        ptr->pub1PortConf = gptimer->FPUB_1;

        /* Clock configuration */
        ptr->clkDivConf   = gptimer->CLKDIV;
        ptr->clockPscConf = gptimer->COMMONREGS.CPS;
        ptr->clkSelConf   = gptimer->CLKSEL;
        ptr->countClkConf = gptimer->COMMONREGS.CCLKCTL;

        /* Interrupt and Event Configuration */
        ptr->intEvnt0Conf = gptimer->CPU_INT.IMASK;
        ptr->intEvnt1Conf = gptimer->GEN_EVENT0.IMASK;
        ptr->intEvnt2Conf = gptimer->GEN_EVENT1.IMASK;

        /* Cross-trigger configuration */
        ptr->crossTrigCtl  = gptimer->COMMONREGS.CTTRIGCTL;
        ptr->crossTrigConf = gptimer->COMMONREGS.CTTRIG;

        /* Timer configuration */
        ptr->cntVal     = gptimer->COUNTERREGS.CTR;
        ptr->cntCtlConf = gptimer->COUNTERREGS.CTRCTL;
        ptr->loadVal    = gptimer->COUNTERREGS.LOAD;
        ptr->phaseVal   = gptimer->COUNTERREGS.PL;
        ptr->tSelConf   = gptimer->COUNTERREGS.TSEL;
        ptr->ccpDirConf = gptimer->COMMONREGS.CCPD;
        ptr->outDisConf = gptimer->COMMONREGS.ODIS;

        /* Capture or Compare configuration */
        ptr->cc0Val     = gptimer->COUNTERREGS.CC_01[0];
        ptr->cc1Val     = gptimer->COUNTERREGS.CC_01[1];
        ptr->cc2Val     = gptimer->COUNTERREGS.CC_23[0];
        ptr->cc3Val     = gptimer->COUNTERREGS.CC_23[1];
        ptr->cc0Ctl     = gptimer->COUNTERREGS.CCCTL_01[0];
        ptr->cc1Ctl     = gptimer->COUNTERREGS.CCCTL_01[1];
        ptr->cc2Ctl     = gptimer->COUNTERREGS.CCCTL_23[0];
        ptr->cc3Ctl     = gptimer->COUNTERREGS.CCCTL_23[1];
        ptr->cc0OutCtl  = gptimer->COUNTERREGS.OCTL_01[0];
        ptr->cc1OutCtl  = gptimer->COUNTERREGS.OCTL_01[1];
        ptr->cc2OutCtl  = gptimer->COUNTERREGS.OCTL_23[0];
        ptr->cc3OutCtl  = gptimer->COUNTERREGS.OCTL_23[1];
        ptr->cc0ActCtl  = gptimer->COUNTERREGS.CCACT_01[0];
        ptr->cc1ActCtl  = gptimer->COUNTERREGS.CCACT_01[1];
        ptr->cc2ActCtl  = gptimer->COUNTERREGS.CCACT_23[0];
        ptr->cc3ActCtl  = gptimer->COUNTERREGS.CCACT_23[1];
        ptr->in0FiltCtl = gptimer->COUNTERREGS.IFCTL_01[0];
        ptr->in1FiltCtl = gptimer->COUNTERREGS.IFCTL_01[1];
        ptr->in2FiltCtl = gptimer->COUNTERREGS.IFCTL_23[0];
        ptr->in3FiltCtl = gptimer->COUNTERREGS.IFCTL_23[1];

        /* Dead Band Configuration */
        ptr->dbCtlConf = gptimer->COUNTERREGS.DBCTL;

        /* Repeat Counter Configuration */
        ptr->rcConf = gptimer->COUNTERREGS.RCLD;

        /* Fault Configuration */
        ptr->faultSrcHndlConf = gptimer->COUNTERREGS.FCTL;
        ptr->faultInCtl       = gptimer->COUNTERREGS.FIFCTL;
        ptr->backupRdy        = true;
    }
    return saveState;
}

bool DL_TimerA_restoreConfiguration(
    GPTIMER_Regs *gptimer, DL_TimerA_backupConfig *ptr, bool restoreCounter)
{
    bool stateRestored = ptr->backupRdy;
    if (stateRestored) {
        ptr->backupRdy = false;
        /* Generic Events Configuration */
        gptimer->FSUB_0 = ptr->sub0PortConf;
        gptimer->FSUB_1 = ptr->sub1PortConf;
        gptimer->FPUB_0 = ptr->pub0PortConf;
        gptimer->FPUB_1 = ptr->pub1PortConf;

        /* Clock Configuration */
        gptimer->CLKSEL             = ptr->clkSelConf;
        gptimer->CLKDIV             = ptr->clkDivConf;
        gptimer->COMMONREGS.CPS     = ptr->clockPscConf;
        gptimer->COMMONREGS.CCLKCTL = ptr->countClkConf;

        /* Timer Configuration */
        if (true == restoreCounter) {
            gptimer->COUNTERREGS.CTR = ptr->cntVal;
        }
        gptimer->COUNTERREGS.LOAD = ptr->loadVal;
        gptimer->COUNTERREGS.PL   = ptr->phaseVal;
        gptimer->COUNTERREGS.TSEL = ptr->tSelConf;
        gptimer->COMMONREGS.CCPD  = ptr->ccpDirConf;
        gptimer->COMMONREGS.ODIS  = ptr->outDisConf;

        /* Capture or Compare Configuration */
        gptimer->COUNTERREGS.CC_01[0]    = ptr->cc0Val;
        gptimer->COUNTERREGS.CC_01[1]    = ptr->cc1Val;
        gptimer->COUNTERREGS.CC_23[0]    = ptr->cc2Val;
        gptimer->COUNTERREGS.CC_23[1]    = ptr->cc3Val;
        gptimer->COUNTERREGS.CCCTL_01[0] = ptr->cc0Ctl;
        gptimer->COUNTERREGS.CCCTL_01[1] = ptr->cc1Ctl;
        gptimer->COUNTERREGS.CCCTL_23[0] = ptr->cc2Ctl;
        gptimer->COUNTERREGS.CCCTL_23[1] = ptr->cc3Ctl;
        gptimer->COUNTERREGS.OCTL_01[0]  = ptr->cc0OutCtl;
        gptimer->COUNTERREGS.OCTL_01[1]  = ptr->cc1OutCtl;
        gptimer->COUNTERREGS.OCTL_23[0]  = ptr->cc2OutCtl;
        gptimer->COUNTERREGS.OCTL_23[1]  = ptr->cc3OutCtl;
        gptimer->COUNTERREGS.CCACT_01[0] = ptr->cc0ActCtl;
        gptimer->COUNTERREGS.CCACT_01[1] = ptr->cc1ActCtl;
        gptimer->COUNTERREGS.CCACT_23[0] = ptr->cc2ActCtl;
        gptimer->COUNTERREGS.CCACT_23[1] = ptr->cc3ActCtl;
        gptimer->COUNTERREGS.IFCTL_01[0] = ptr->in0FiltCtl;
        gptimer->COUNTERREGS.IFCTL_01[1] = ptr->in1FiltCtl;
        gptimer->COUNTERREGS.IFCTL_23[0] = ptr->in2FiltCtl;
        gptimer->COUNTERREGS.IFCTL_23[1] = ptr->in3FiltCtl;

        /* Cross-trigger Configuration */
        gptimer->COMMONREGS.CTTRIGCTL = ptr->crossTrigCtl;
        gptimer->COMMONREGS.CTTRIG    = ptr->crossTrigConf;

        /* Dead Band Configuration */
        gptimer->COUNTERREGS.DBCTL = ptr->dbCtlConf;

        /* Repeat Counter Configuration */
        ptr->rcConf = gptimer->COUNTERREGS.RCLD;

        /* Fault Configuration */
        ptr->faultSrcHndlConf = gptimer->COUNTERREGS.FCTL;
        ptr->faultInCtl       = gptimer->COUNTERREGS.FIFCTL;

        /* Interrupt and Event Configuration */
        gptimer->CPU_INT.IMASK    = ptr->intEvnt0Conf;
        gptimer->GEN_EVENT0.IMASK = ptr->intEvnt1Conf;
        gptimer->GEN_EVENT1.IMASK = ptr->intEvnt2Conf;

        /* Restores Timer counter state until the end to prevent unexpected
         * behavior */
        gptimer->COUNTERREGS.CTRCTL = ptr->cntCtlConf;
    }
    return stateRestored;
}

#endif /* __MSPM0_HAS_TIMER_A__ */

static void DL_Timer_getInChanConfig(
    DL_TIMER_INPUT_CHAN chan, Timer_Input_Chan_Config *config)
{
    switch (chan) {
        case DL_TIMER_INPUT_CHAN_0:
            config->index    = (DL_TIMER_CC_0_INDEX);
            config->ccpInput = (DL_TIMER_CC_IN_SEL_CCP0);
            config->timerConfig =
                (GPTIMER_CTRCTL_CLC_CCCTL0_LCOND |
                    GPTIMER_CTRCTL_CAC_CCCTL0_ACOND |
                    GPTIMER_CTRCTL_CZC_CCCTL0_ZCOND | GPTIMER_CTRCTL_CM_DOWN);
            config->ccpInputDir = DL_TIMER_CC0_INPUT;
            break;
        case DL_TIMER_INPUT_CHAN_1:
            config->index    = (DL_TIMER_CC_1_INDEX);
            config->ccpInput = (DL_TIMER_CC_IN_SEL_CCPX);
            config->timerConfig =
                (GPTIMER_CTRCTL_CLC_CCCTL1_LCOND |
                    GPTIMER_CTRCTL_CAC_CCCTL1_ACOND |
                    GPTIMER_CTRCTL_CZC_CCCTL1_ZCOND | GPTIMER_CTRCTL_CM_DOWN);
            config->ccpInputDir = (DL_TIMER_CC1_INPUT);
            break;
        case DL_TIMER_INPUT_CHAN_2:
            config->index    = (DL_TIMER_CC_2_INDEX);
            config->ccpInput = (DL_TIMER_CC_IN_SEL_CCP0);
            config->timerConfig =
                (GPTIMER_CTRCTL_CLC_CCCTL2_LCOND |
                    GPTIMER_CTRCTL_CAC_CCCTL2_ACOND |
                    GPTIMER_CTRCTL_CZC_CCCTL2_ZCOND | GPTIMER_CTRCTL_CM_DOWN);
            config->ccpInputDir = (DL_TIMER_CC2_INPUT);
            break;
        case DL_TIMER_INPUT_CHAN_3:
            config->index    = (DL_TIMER_CC_3_INDEX);
            config->ccpInput = (DL_TIMER_CC_IN_SEL_CCPX);
            config->timerConfig =
                (GPTIMER_CTRCTL_CLC_CCCTL3_LCOND |
                    GPTIMER_CTRCTL_CAC_CCCTL3_ACOND |
                    GPTIMER_CTRCTL_CZC_CCCTL3_ZCOND | GPTIMER_CTRCTL_CM_DOWN);
            config->ccpInputDir = (DL_TIMER_CC3_INPUT);
            break;
        default:
            /* This case shouldn't be reached */
            break;
    }
}

static void DL_Timer_getInChanPairConfig(
    DL_TIMER_INPUT_CHAN chan, Timer_Input_Pair_Chan_Config *config)
{
    switch (chan) {
        case DL_TIMER_INPUT_CHAN_0:
            config->index = (DL_TIMER_CC_1_INDEX);
            break;
        case DL_TIMER_INPUT_CHAN_1:
            config->index = (DL_TIMER_CC_0_INDEX);
            break;
        case DL_TIMER_INPUT_CHAN_2:
            config->index = (DL_TIMER_CC_3_INDEX);
            break;
        case DL_TIMER_INPUT_CHAN_3:
            config->index = (DL_TIMER_CC_2_INDEX);
            break;
        default:
            /* This case shouldn't be reached */
            break;
    }
}

void DL_Timer_configQEIHallInputMode(GPTIMER_Regs *gptimer)
{
    /* Set channels for capture mode */
    gptimer->COUNTERREGS.CCCTL_01[0] = GPTIMER_CCCTL_01_COC_CAPTURE;
    gptimer->COUNTERREGS.CCCTL_01[1] = GPTIMER_CCCTL_01_COC_CAPTURE;

    /* Set channels as input */
    DL_Timer_setCCPDirection(
        gptimer, (DL_TIMER_CC0_INPUT | DL_TIMER_CC1_INPUT));

    /* Select XOR option for Hall signals */
    gptimer->COUNTERREGS.IFCTL_01[0] = DL_TIMER_CC_IN_SEL_CCP_XOR;
    gptimer->COUNTERREGS.IFCTL_01[1] = DL_TIMER_CC_IN_SEL_CCP_XOR;
}

#endif /* __MSPM0_HAS_TIMER_A__ || __MSPM0_HAS_TIMER_G__ */
