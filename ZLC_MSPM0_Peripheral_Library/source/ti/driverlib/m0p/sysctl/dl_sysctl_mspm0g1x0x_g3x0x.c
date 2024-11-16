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

#include <stdint.h>
#include <ti/devices/DeviceFamily.h>

#if (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0G1X0X_G3X0X)

#include <ti/driverlib/m0p/dl_core.h>
#include <ti/driverlib/m0p/sysctl/dl_sysctl_mspm0g1x0x_g3x0x.h>

void DL_SYSCTL_configSYSPLL(DL_SYSCTL_SYSPLLConfig *config)
{
    /* PLL configurations are retained in lower reset levels. Set default
     * behavior of disabling the PLL to keep a consistent behavior regardless
     * of reset level. */
    DL_SYSCTL_disableSYSPLL();

    /* Check that SYSPLL is disabled before configuration */
    while ((DL_SYSCTL_getClockStatus() & (DL_SYSCTL_CLK_STATUS_SYSPLL_OFF)) !=
           (DL_SYSCTL_CLK_STATUS_SYSPLL_OFF)) {
        ;
    }

    // set SYSPLL reference clock
    DL_Common_updateReg(&SYSCTL->SOCLOCK.SYSPLLCFG0,
        ((uint32_t) config->sysPLLRef), SYSCTL_SYSPLLCFG0_SYSPLLREF_MASK);

    // set predivider PDIV (divides reference clock)
    DL_Common_updateReg(&SYSCTL->SOCLOCK.SYSPLLCFG1, ((uint32_t) config->pDiv),
        SYSCTL_SYSPLLCFG1_PDIV_MASK);

    // save CPUSS CTL state and disable the cache
    uint32_t ctlTemp = DL_CORE_getInstructionConfig();
    DL_CORE_configInstruction(DL_CORE_PREFETCH_ENABLED, DL_CORE_CACHE_DISABLED,
        DL_CORE_LITERAL_CACHE_ENABLED);

    // populate SYSPLLPARAM0/1 tuning registers from flash, based on input freq
    SYSCTL->SOCLOCK.SYSPLLPARAM0 =
        *(volatile uint32_t *) ((uint32_t) config->inputFreq);
    SYSCTL->SOCLOCK.SYSPLLPARAM1 =
        *(volatile uint32_t *) ((uint32_t) config->inputFreq + (uint32_t) 0x4);

    // restore CPUSS CTL state
    CPUSS->CTL = ctlTemp;

    // set feedback divider QDIV (multiplies to give output frequency)
    DL_Common_updateReg(&SYSCTL->SOCLOCK.SYSPLLCFG1,
        ((config->qDiv << SYSCTL_SYSPLLCFG1_QDIV_OFS) &
            SYSCTL_SYSPLLCFG1_QDIV_MASK),
        SYSCTL_SYSPLLCFG1_QDIV_MASK);

    // write clock output dividers, enable outputs, and MCLK source to SYSPLLCFG0
    DL_Common_updateReg(&SYSCTL->SOCLOCK.SYSPLLCFG0,
        (((config->rDivClk2x << SYSCTL_SYSPLLCFG0_RDIVCLK2X_OFS) &
             SYSCTL_SYSPLLCFG0_RDIVCLK2X_MASK) |
            ((config->rDivClk1 << SYSCTL_SYSPLLCFG0_RDIVCLK1_OFS) &
                SYSCTL_SYSPLLCFG0_RDIVCLK1_MASK) |
            ((config->rDivClk0 << SYSCTL_SYSPLLCFG0_RDIVCLK0_OFS) &
                SYSCTL_SYSPLLCFG0_RDIVCLK0_MASK) |
            config->enableCLK2x | config->enableCLK1 | config->enableCLK0 |
            (uint32_t) config->sysPLLMCLK),
        (SYSCTL_SYSPLLCFG0_RDIVCLK2X_MASK | SYSCTL_SYSPLLCFG0_RDIVCLK1_MASK |
            SYSCTL_SYSPLLCFG0_RDIVCLK0_MASK |
            SYSCTL_SYSPLLCFG0_ENABLECLK2X_MASK |
            SYSCTL_SYSPLLCFG0_ENABLECLK1_MASK |
            SYSCTL_SYSPLLCFG0_ENABLECLK0_MASK |
            SYSCTL_SYSPLLCFG0_MCLK2XVCO_MASK));

    // enable SYSPLL
    SYSCTL->SOCLOCK.HSCLKEN |= SYSCTL_HSCLKEN_SYSPLLEN_ENABLE;

    // wait until SYSPLL startup is stabilized
    while ((DL_SYSCTL_getClockStatus() & SYSCTL_CLKSTATUS_SYSPLLGOOD_MASK) !=
           DL_SYSCTL_CLK_STATUS_SYSPLL_GOOD) {
        ;
    }
}

void DL_SYSCTL_setLFCLKSourceLFXT(DL_SYSCTL_LFCLKConfig *config)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.LFCLKCFG,
        ((uint32_t) config->lowCap << SYSCTL_LFCLKCFG_LOWCAP_OFS) |
            (uint32_t) config->xt1Drive,
        (SYSCTL_LFCLKCFG_XT1DRIVE_MASK | SYSCTL_LFCLKCFG_LOWCAP_MASK));
    // start the LFXT oscillator
    SYSCTL->SOCLOCK.LFXTCTL =
        (SYSCTL_LFXTCTL_KEY_VALUE | SYSCTL_LFXTCTL_STARTLFXT_TRUE);
    // wait until LFXT oscillator is stable
    // if it does not stabilize, check the hardware/IOMUX settings
    while ((DL_SYSCTL_getClockStatus() & SYSCTL_CLKSTATUS_LFXTGOOD_MASK) !=
           DL_SYSCTL_CLK_STATUS_LFXT_GOOD) {
        ;
    }
    if (config->monitor) {
        // set the LFCLK monitor
        SYSCTL->SOCLOCK.LFCLKCFG |= SYSCTL_LFCLKCFG_MONITOR_ENABLE;
    }

    // switch LFCLK source from LFOSC to LFXT
    SYSCTL->SOCLOCK.LFXTCTL =
        (SYSCTL_LFXTCTL_KEY_VALUE | SYSCTL_LFXTCTL_SETUSELFXT_TRUE);
}

void DL_SYSCTL_switchMCLKfromSYSOSCtoLFCLK(bool disableSYSOSC)
{
    if (disableSYSOSC == false) {
        // Set SYSOSC back to base frequency if left enabled
        DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
        SYSCTL->SOCLOCK.SYSOSCCFG &= ~SYSCTL_SYSOSCCFG_DISABLE_ENABLE;
    } else {
        SYSCTL->SOCLOCK.SYSOSCCFG |= SYSCTL_SYSOSCCFG_DISABLE_ENABLE;
    }
    SYSCTL->SOCLOCK.MCLKCFG |= SYSCTL_MCLKCFG_USELFCLK_ENABLE;

    // Verify LFCLK -> MCLK
    while ((DL_SYSCTL_getClockStatus() & SYSCTL_CLKSTATUS_CURMCLKSEL_MASK) !=
           DL_SYSCTL_CLK_STATUS_MCLK_SOURCE_LFCLK) {
        ;
    }
}

void DL_SYSCTL_switchMCLKfromLFCLKtoSYSOSC(void)
{
    // Only one should have been set, but clear both because unknown incoming state
    // Clear SYSOSCCFG.DISABLE to get SYSOSC running again
    // Clear MCLKCFG.USELFCLK to switch MCLK source from LFCLK to SYSOSC
    SYSCTL->SOCLOCK.SYSOSCCFG &= ~SYSCTL_SYSOSCCFG_DISABLE_ENABLE;
    SYSCTL->SOCLOCK.MCLKCFG &= ~SYSCTL_MCLKCFG_USELFCLK_ENABLE;

    // Verify SYSOSC -> MCLK
    while (((DL_SYSCTL_getClockStatus() & SYSCTL_CLKSTATUS_CURMCLKSEL_MASK) ==
            DL_SYSCTL_CLK_STATUS_MCLK_SOURCE_LFCLK)) {
        ;
    }
}

void DL_SYSCTL_switchMCLKfromSYSOSCtoHSCLK(DL_SYSCTL_HSCLK_SOURCE source)
{
    // Assume desired HS sources already enabled per their requirements (SYSPLL, HFXT, HFCLK_IN)
    // Selected desired HSCLK source
    DL_SYSCTL_setHSCLKSource(source);

    // Verify HSCLK source is valid
    while ((DL_SYSCTL_getClockStatus() & SYSCTL_CLKSTATUS_HSCLKGOOD_MASK) !=
           DL_SYSCTL_CLK_STATUS_HSCLK_GOOD) {
        ;
    }

    // Switch MCLK to HSCLK
    SYSCTL->SOCLOCK.MCLKCFG |= SYSCTL_MCLKCFG_USEHSCLK_ENABLE;

    // Verify HSCLK -> MCLK
    while ((DL_SYSCTL_getClockStatus() & SYSCTL_CLKSTATUS_HSCLKMUX_MASK) !=
           DL_SYSCTL_CLK_STATUS_MCLK_SOURCE_HSCLK) {
        ;
    }
}

void DL_SYSCTL_switchMCLKfromHSCLKtoSYSOSC(void)
{
    // Switch MCLK to SYSOSC
    SYSCTL->SOCLOCK.MCLKCFG &= ~SYSCTL_MCLKCFG_USEHSCLK_ENABLE;

    // Verify SYSOSC -> MCLK
    while ((DL_SYSCTL_getClockStatus() & SYSCTL_CLKSTATUS_HSCLKMUX_MASK) ==
           DL_SYSCTL_CLK_STATUS_MCLK_SOURCE_HSCLK) {
        ;
    }
}

void DL_SYSCTL_setHFCLKSourceHFXT(DL_SYSCTL_HFXT_RANGE range)
{
    /* Some crystal configurations are retained in lower reset levels. Set
     * default behavior of HFXT to keep a consistent behavior regardless of
     * reset level. */
    DL_SYSCTL_disableHFXT();

    DL_SYSCTL_setHFXTFrequencyRange(range);
    /* Set startup time to ~0.512ms based on TYP datasheet recommendation */
    DL_SYSCTL_setHFXTStartupTime(8);
    SYSCTL->SOCLOCK.HSCLKEN |= SYSCTL_HSCLKEN_HFXTEN_ENABLE;
    DL_SYSCTL_enableHFCLKStartupMonitor();
    /* Wait until HFXT oscillator is stable. If it does not stabilize, check the
     hardware/IOMUX settings */
    while ((DL_SYSCTL_getClockStatus() & SYSCTL_CLKSTATUS_HFCLKGOOD_MASK) !=
           DL_SYSCTL_CLK_STATUS_HFCLK_GOOD) {
        ;
    }
}

void DL_SYSCTL_setHFCLKSourceHFXTParams(
    DL_SYSCTL_HFXT_RANGE range, uint32_t startupTime, bool monitorEnable)
{
    /* Some crystal configurations are retained in lower reset levels. Set
     * default behavior of HFXT to keep a consistent behavior regardless of
     * reset level. */
    DL_SYSCTL_disableHFXT();

    DL_SYSCTL_setHFXTFrequencyRange(range);
    DL_SYSCTL_setHFXTStartupTime(startupTime);
    SYSCTL->SOCLOCK.HSCLKEN |= SYSCTL_HSCLKEN_HFXTEN_ENABLE;

    if (monitorEnable == true) {
        DL_SYSCTL_enableHFCLKStartupMonitor();
        /* Wait until HFXT oscillator is stable. If it does not stabilize, check the
        hardware/IOMUX settings */
        while (
            (DL_SYSCTL_getClockStatus() & SYSCTL_CLKSTATUS_HFCLKGOOD_MASK) !=
            DL_SYSCTL_CLK_STATUS_HFCLK_GOOD) {
            ;
        }
    } else {
        DL_SYSCTL_disableHFCLKStartupMonitor();
    }
}

void DL_SYSCTL_configFCC(DL_SYSCTL_FCC_TRIG_TYPE trigLvl,
    DL_SYSCTL_FCC_TRIG_SOURCE trigSrc, DL_SYSCTL_FCC_CLOCK_SOURCE clkSrc)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.GENCLKCFG,
        (uint32_t) trigLvl | (uint32_t) trigSrc | (uint32_t) clkSrc,
        SYSCTL_GENCLKCFG_FCCLVLTRIG_MASK | SYSCTL_GENCLKCFG_FCCTRIGSRC_MASK |
            SYSCTL_GENCLKCFG_FCCSELCLK_MASK);
}

DL_SYSCTL_POWER_POLICY_RUN_SLEEP DL_SYSCTL_getPowerPolicyRUNSLEEP(void)
{
    DL_SYSCTL_POWER_POLICY_RUN_SLEEP policy =
        DL_SYSCTL_POWER_POLICY_RUN_SLEEP_NOT_ENABLED;

    // Check if SLEEP is enabled
    if ((SCB->SCR & SCB_SCR_SLEEPDEEP_Msk) != SCB_SCR_SLEEPDEEP_Msk) {
        // Check which policy is enabled
        if ((SYSCTL->SOCLOCK.MCLKCFG & SYSCTL_MCLKCFG_USELFCLK_MASK) ==
            SYSCTL_MCLKCFG_USELFCLK_ENABLE) {
            policy = DL_SYSCTL_POWER_POLICY_RUN_SLEEP1;
        } else if ((SYSCTL->SOCLOCK.SYSOSCCFG &
                       SYSCTL_SYSOSCCFG_DISABLESTOP_MASK) ==
                   SYSCTL_SYSOSCCFG_DISABLESTOP_ENABLE) {
            policy = DL_SYSCTL_POWER_POLICY_RUN_SLEEP2;
        } else {
            policy = DL_SYSCTL_POWER_POLICY_RUN_SLEEP0;
        }
    }
    return policy;
}

DL_SYSCTL_POWER_POLICY_STOP DL_SYSCTL_getPowerPolicySTOP(void)
{
    DL_SYSCTL_POWER_POLICY_STOP policy =
        DL_SYSCTL_POWER_POLICY_STOP_NOT_ENABLED;

    // Check if STOP is enabled
    if ((SYSCTL->SOCLOCK.PMODECFG == SYSCTL_PMODECFG_DSLEEP_STOP) &&
        (SCB->SCR & SCB_SCR_SLEEPDEEP_Msk) == SCB_SCR_SLEEPDEEP_Msk) {
        // Check which policy is enabled
        if ((SYSCTL->SOCLOCK.SYSOSCCFG & SYSCTL_SYSOSCCFG_USE4MHZSTOP_MASK) ==
            SYSCTL_SYSOSCCFG_USE4MHZSTOP_ENABLE) {
            policy = DL_SYSCTL_POWER_POLICY_STOP1;
        } else if ((SYSCTL->SOCLOCK.SYSOSCCFG &
                       SYSCTL_SYSOSCCFG_DISABLESTOP_MASK) ==
                   SYSCTL_SYSOSCCFG_DISABLESTOP_ENABLE) {
            policy = DL_SYSCTL_POWER_POLICY_STOP2;
        } else {
            policy = DL_SYSCTL_POWER_POLICY_STOP0;
        }
    }
    return policy;
}

DL_SYSCTL_POWER_POLICY_STANDBY DL_SYSCTL_getPowerPolicySTANDBY(void)
{
    DL_SYSCTL_POWER_POLICY_STANDBY policy =
        DL_SYSCTL_POWER_POLICY_STANDBY_NOT_ENABLED;

    // Check if STOP is enabled
    if ((SYSCTL->SOCLOCK.PMODECFG == SYSCTL_PMODECFG_DSLEEP_STANDBY) &&
        (SCB->SCR & SCB_SCR_SLEEPDEEP_Msk) == SCB_SCR_SLEEPDEEP_Msk) {
        // Check which policy is enabled
        if ((SYSCTL->SOCLOCK.MCLKCFG & SYSCTL_MCLKCFG_STOPCLKSTBY_MASK) ==
            SYSCTL_MCLKCFG_STOPCLKSTBY_ENABLE) {
            policy = DL_SYSCTL_POWER_POLICY_STANDBY1;
        } else {
            policy = DL_SYSCTL_POWER_POLICY_STANDBY0;
        }
    }
    return policy;
}

#endif /* DeviceFamily_PARENT_MSPM0G1X0X_G3X0X */
