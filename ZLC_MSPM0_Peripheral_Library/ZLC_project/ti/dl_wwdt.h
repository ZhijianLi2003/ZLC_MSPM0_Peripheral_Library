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
/*!****************************************************************************
 *  @file       dl_wwdt.h
 *  @brief      Window Watchdog Timer (WWDT) Driver Library
 *  @defgroup   WWDT Window Watchdog Timer (WWDT)
 *
 *  @anchor ti_dl_dl_wwdt_Overview
 *  # Overview
 *
 *  The Window Watchdog Timer Driver Library allows full configuration of
 *  the MSPM0 WWDT module.
 *  The window watchdog timer (WWDT) supervises code execution.
 *  If the application software does not successfully reset the window
 *  watchdog within the programmed open time window, the window watchdog
 *  generates a SYSRST.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup WWDT
 * @{
 */
#ifndef ti_dl_dl_wwdt__include
#define ti_dl_dl_wwdt__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>

#ifdef __MSPM0_HAS_WWDT__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/*! @enum DL_WWDT_CLOCK_DIVIDE */
typedef enum {
    /*! Clock source divide by 1 */
    DL_WWDT_CLOCK_DIVIDE_1 = 0x00000000,
    /*! Clock source divide by 2 */
    DL_WWDT_CLOCK_DIVIDE_2 = 0x00000001,
    /*! Clock source divide by 3 */
    DL_WWDT_CLOCK_DIVIDE_3 = 0x00000002,
    /*! Clock source divide by 4 */
    DL_WWDT_CLOCK_DIVIDE_4 = 0x00000003,
    /*! Clock source divide by 5 */
    DL_WWDT_CLOCK_DIVIDE_5 = 0x00000004,
    /*! Clock source divide by 6 */
    DL_WWDT_CLOCK_DIVIDE_6 = 0x00000005,
    /*! Clock source divide by 7 */
    DL_WWDT_CLOCK_DIVIDE_7 = 0x00000006,
    /*! Clock source divide by 8 */
    DL_WWDT_CLOCK_DIVIDE_8 = 0x00000007
} DL_WWDT_CLOCK_DIVIDE;

/*! @enum DL_WWDT_WINDOW */
typedef enum {
    /*! Window 0 active */
    DL_WWDT_WINDOW0 = WWDT_WWDTCTL1_WINSEL_WIN0,
    /*! Window 1 active */
    DL_WWDT_WINDOW1 = WWDT_WWDTCTL1_WINSEL_WIN1
} DL_WWDT_WINDOW;

/*! @enum DL_WWDT_WINDOW_PERIOD */
typedef enum {
    /*! 0% closed window period */
    DL_WWDT_WINDOW_PERIOD_0 = WWDT_WWDTCTL0_WINDOW0_SIZE_0,
    /*! 12% closed window period */
    DL_WWDT_WINDOW_PERIOD_12 = WWDT_WWDTCTL0_WINDOW0_SIZE_12,
    /*! 18% closed window period */
    DL_WWDT_WINDOW_PERIOD_18 = WWDT_WWDTCTL0_WINDOW0_SIZE_18,
    /*! 25% closed window period */
    DL_WWDT_WINDOW_PERIOD_25 = WWDT_WWDTCTL0_WINDOW0_SIZE_25,
    /*! 50% closed window period */
    DL_WWDT_WINDOW_PERIOD_50 = WWDT_WWDTCTL0_WINDOW0_SIZE_50,
    /*! 75% closed window period */
    DL_WWDT_WINDOW_PERIOD_75 = WWDT_WWDTCTL0_WINDOW0_SIZE_75,
    /*! 81% closed window period */
    DL_WWDT_WINDOW_PERIOD_81 = WWDT_WWDTCTL0_WINDOW0_SIZE_81,
    /*! 87% closed window period */
    DL_WWDT_WINDOW_PERIOD_87 = WWDT_WWDTCTL0_WINDOW0_SIZE_87
} DL_WWDT_WINDOW_PERIOD;

/*! @enum DL_WWDT_TIMER_PERIOD */
typedef enum {
    /*! 2^6 timer period count */
    DL_WWDT_TIMER_PERIOD_6_BITS = WWDT_WWDTCTL0_PER_EN_6,
    /*! 2^8 timer period count */
    DL_WWDT_TIMER_PERIOD_8_BITS = WWDT_WWDTCTL0_PER_EN_8,
    /*! 2^10 timer period count */
    DL_WWDT_TIMER_PERIOD_10_BITS = WWDT_WWDTCTL0_PER_EN_10,
    /*! 2^12 timer period count */
    DL_WWDT_TIMER_PERIOD_12_BITS = WWDT_WWDTCTL0_PER_EN_12,
    /*! 2^15 timer period count */
    DL_WWDT_TIMER_PERIOD_15_BITS = WWDT_WWDTCTL0_PER_EN_15,
    /*! 2^18 timer period count */
    DL_WWDT_TIMER_PERIOD_18_BITS = WWDT_WWDTCTL0_PER_EN_18,
    /*! 2^21 timer period count */
    DL_WWDT_TIMER_PERIOD_21_BITS = WWDT_WWDTCTL0_PER_EN_21,
    /*! 2^25 timer period count */
    DL_WWDT_TIMER_PERIOD_25_BITS = WWDT_WWDTCTL0_PER_EN_25
} DL_WWDT_TIMER_PERIOD;

/*! @enum DL_WWDT_SLEEP_MODE */
typedef enum {
    /*! Stop the watchdog while in sleep */
    DL_WWDT_STOP_IN_SLEEP = WWDT_WWDTCTL0_STISM_STOP,
    /*! Keep the watchdog running in sleep */
    DL_WWDT_RUN_IN_SLEEP = WWDT_WWDTCTL0_STISM_CONT
} DL_WWDT_SLEEP_MODE;

/*! @enum DL_WWDT_MODE */
typedef enum {
    /*! The watchdog is in watchdog mode */
    DL_WWDT_WATCHDOG_MODE = 0x0,
    /*! The watchdog is in interval timer mode */
    DL_WWDT_INTERVAL_TIMER_MODE = WWDT_WWDTCTL0_MODE_INTERVAL
} DL_WWDT_MODE;

/*! @enum DL_WWDT_IIDX */
typedef enum {
    /*! Interrupt index for WWDT if no interrupt is pending */
    DL_WWDT_IIDX_NO_INT = WWDT_IIDX_STAT_NO_INTR,
    /*! WWDT interrupt index for interval timer */
    DL_WWDT_IIDX_INTERVAL_TIMER = WWDT_IIDX_STAT_INTTIM
} DL_WWDT_IIDX;

/* clang-format on */

/*!
 *  @brief      Initializes the Window Watchdog Timer in watchdog mode
 *
 *  While in watchdog mode, the Window Watchdog Timer must be serviced
 *  periodically or the device will be reset. After calling this initialization
 *  API the watchdog will automatically start running with whatever window is
 *  currently selected. See @ref DL_WWDT_setActiveWindow for setting the active
 *  window, this is typically window 0 upon startup.
 *
 *  Once running, the watchdog will need to be restarted periodically with @ref
 *  DL_WWDT_restart.
 *
 *  The watchdog can only be initialized once, so this API can only be called
 *  once, and you may not later call @ref DL_WWDT_initIntervalTimerMode.
 *
 *  @param[in]  wwdt                Pointer to the register overlay for
 *                                  peripheral
 *  @param[in]  divider             Clock divider for the timer. One of @ref
 *                                  DL_WWDT_CLOCK_DIVIDE.
 *  @param[in]  period              Period for the timer. One of @ref
 *                                  DL_WWDT_TIMER_PERIOD.
 *  @param[in]  sleepMode           Enable/disable the timer running in sleep
 *                                  mode. One of @ref DL_WWDT_SLEEP_MODE.
 *  @param[in]  window0ClosedPeriod The percentage of the total period that
 *                                  reset window 0 should be closed. One of
 *                                  @ref DL_WWDT_WINDOW_PERIOD.
 *  @param[in]  window1ClosedPeriod The percentage of the total period that
 *                                  reset window 1 should be closed. One of
 *                                  @ref DL_WWDT_WINDOW_PERIOD.
 *
 *  @sa         DL_WWDT_initIntervalTimerMode
 *  @sa         DL_WWDT_setActiveWindow
 *  @sa         DL_WWDT_restart
 *
 */
__STATIC_INLINE void DL_WWDT_initWatchdogMode(WWDT_Regs *wwdt,
    DL_WWDT_CLOCK_DIVIDE divider, DL_WWDT_TIMER_PERIOD period,
    DL_WWDT_SLEEP_MODE sleepMode, DL_WWDT_WINDOW_PERIOD window0ClosedPeriod,
    DL_WWDT_WINDOW_PERIOD window1ClosedPeriod)
{
    /* Window1 is shifted because the #defines used as an input are shared
       between window 0 and window 1 */
    wwdt->WWDTCTL0 =
        (WWDT_WWDTCTL0_KEY_UNLOCK_W | (uint32_t) divider | (uint32_t) period |
            (uint32_t) sleepMode | (uint32_t) window0ClosedPeriod |
            ((uint32_t) window1ClosedPeriod << 4));
}

/*!
 *  @brief      Initializes the Window Watchdog Timer in interval timer mode
 *
 *  The Window Watchdog Timer can be used as a simple interval timer if you do
 *  not need watchdog/reset functionality. After calling this initialization
 *  API the timer will automatically start running and start interrupting
 *  periodically.
 *
 *  The WWDT can only be initialized once, so this API can only be called once,
 *  and you may not later call @ref DL_WWDT_initWatchdogMode.
 *
 *  @param[in]  wwdt      Pointer to the register overlay for peripheral
 *  @param[in]  divider   Clock divider for the timer. One of
 *                        @ref DL_WWDT_CLOCK_DIVIDE.
 *  @param[in]  period    Period for the timer. One of @ref
 *                        DL_WWDT_TIMER_PERIOD.
 *  @param[in]  sleepMode Enable/disable the timer running in sleep mode. One
 *                        of @ref DL_WWDT_SLEEP_MODE.
 *
 *  @sa         DL_WWDT_initWatchdogMode
 */
__STATIC_INLINE void DL_WWDT_initIntervalTimerMode(WWDT_Regs *wwdt,
    DL_WWDT_CLOCK_DIVIDE divider, DL_WWDT_TIMER_PERIOD period,
    DL_WWDT_SLEEP_MODE sleepMode)
{
    wwdt->WWDTCTL0 =
        (WWDT_WWDTCTL0_KEY_UNLOCK_W | (uint32_t) divider | (uint32_t) period |
            (uint32_t) sleepMode | WWDT_WWDTCTL0_MODE_INTERVAL);
}

/**
 * @brief Enables power on WWDT module
 *
 * @param wwdt        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_WWDT_enablePower(WWDT_Regs *wwdt)
{
    wwdt->GPRCM.PWREN = (WWDT_PWREN_KEY_UNLOCK_W | WWDT_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Disables power on wwdt module
 *
 * @param wwdt        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_WWDT_disablePower(WWDT_Regs *wwdt)
{
    wwdt->GPRCM.PWREN = (WWDT_PWREN_KEY_UNLOCK_W | WWDT_PWREN_ENABLE_DISABLE);
}

/**
 * @brief Returns if  power on wwdt module
 *
 * @param wwdt        Pointer to the register overlay for the peripheral
 *
 * @return true if power is enabled
 * @return false if power is disabled
 */
__STATIC_INLINE bool DL_WWDT_isPowerEnabled(WWDT_Regs *wwdt)
{
    return ((wwdt->GPRCM.PWREN & WWDT_PWREN_ENABLE_MASK) ==
            WWDT_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Resets wwdt peripheral
 *
 * @param wwdt        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_WWDT_reset(WWDT_Regs *wwdt)
{
    wwdt->GPRCM.RSTCTL =
        (WWDT_RSTCTL_KEY_UNLOCK_W | WWDT_RSTCTL_RESETSTKYCLR_CLR |
            WWDT_RSTCTL_RESETASSERT_ASSERT);
}

/**
 * @brief Returns if wwdt peripheral was reset
 *
 * @param wwdt        Pointer to the register overlay for the peripheral
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_WWDT_isReset(WWDT_Regs *wwdt)
{
    return ((wwdt->GPRCM.STAT & WWDT_STAT_RESETSTKY_MASK) ==
            WWDT_STAT_RESETSTKY_RESET);
}

/*!
 *  @brief      Restarts the Window Watchdog
 *
 *  When the Window Watchdog Timer is in watchdog mode it must be periodically
 *  serviced to avoid a hardware reset. This API must be called after the
 *  closed window of the watchdog has passed but before the watchdog resets the
 *  device.
 *
 *  @param[in]  wwdt  Pointer to the register overlay for peripheral
 */
__STATIC_INLINE void DL_WWDT_restart(WWDT_Regs *wwdt)
{
    wwdt->WWDTCNTRST = 0x00A7;
}

/*!
 *  @brief      Checks if the Window Watchdog Timer is actively running
 *
 *  @param[in]  wwdt  Pointer to the register overlay for peripheral
 *
 *  @return     Returns the running status of the Window Watchdog Timer
 *
 *  @retval     true  The Window Watchdog Timer is running
 *  @retval     false The Window Watchdog Timer is not running
 */
__STATIC_INLINE bool DL_WWDT_isRunning(WWDT_Regs *wwdt)
{
    return (wwdt->WWDTSTAT == WWDT_WWDTSTAT_RUN_ON);
}

/*!
 *  @brief Set the active window being used
 *
 *  The Window Watchdog Timer module allows you to switch between two different
 *  configured windows. This allows you to configure the watchdog with two
 *  different window sizes and switch between them during your application.
 *
 *  @param[in]  wwdt    Pointer to the register overlay for peripheral
 *  @param[in]  window  The window to set as active. One of @ref
 *                      DL_WWDT_WINDOW.
 *
 */
__STATIC_INLINE void DL_WWDT_setActiveWindow(
    WWDT_Regs *wwdt, DL_WWDT_WINDOW window)
{
    wwdt->WWDTCTL1 = (WWDT_WWDTCTL1_KEY_UNLOCK_W | (uint32_t) window);
}

/*!
 *  @brief      Get the active window being used
 *
 *  @param[in]  wwdt  Pointer to the register overlay for peripheral
 *
 *  @return     The active window being used
 *
 *  @retval     One of @ref DL_WWDT_WINDOW
 */
__STATIC_INLINE DL_WWDT_WINDOW DL_WWDT_getActiveWindow(WWDT_Regs *wwdt)
{
    uint32_t window = (wwdt->WWDTCTL1 & WWDT_WWDTCTL1_WINSEL_MASK);

    return (DL_WWDT_WINDOW)(window);
}

/*!
 *  @brief      Get the sleep mode being used
 *
 *  @param[in]  wwdt  Pointer to the register overlay for peripheral
 *
 *  @return     The current sleep mode
 *
 *  @retval     One of @ref DL_WWDT_SLEEP_MODE
 */
__STATIC_INLINE DL_WWDT_SLEEP_MODE DL_WWDT_getSleepMode(WWDT_Regs *wwdt)
{
    uint32_t mode = (wwdt->WWDTCTL0 & WWDT_WWDTCTL0_STISM_MASK);

    return (DL_WWDT_SLEEP_MODE)(mode);
}

/*!
 *  @brief      Get the mode the watchdog is running in
 *
 *  @param[in]  wwdt  Pointer to the register overlay for peripheral
 *
 *  @return     The current mode the watchdog is running in
 *
 *  @retval     One of @ref DL_WWDT_MODE
 */
__STATIC_INLINE DL_WWDT_MODE DL_WWDT_getMode(WWDT_Regs *wwdt)
{
    uint32_t mode = (wwdt->WWDTCTL0 & WWDT_WWDTCTL0_MODE_MASK);

    return (DL_WWDT_MODE)(mode);
}

/*!
 *  @brief      Get the window closed percentage for a watchdog window
 *
 *  @param[in]  wwdt    Pointer to the register overlay for peripheral
 *  @param[in]  window  The window to get the closed window percentage of. One
 *                      of @ref DL_WWDT_WINDOW.
 *
 *  @return     The desired window's closed percentage
 *
 *  @retval     One of @ref DL_WWDT_WINDOW_PERIOD
 */
__STATIC_INLINE DL_WWDT_WINDOW_PERIOD DL_WWDT_getWindowPeriod(
    WWDT_Regs *wwdt, DL_WWDT_WINDOW window)
{
    uint32_t period;

    if (window == DL_WWDT_WINDOW0) {
        period = (wwdt->WWDTCTL0 & WWDT_WWDTCTL0_WINDOW0_MASK);
    } else {
        period = ((wwdt->WWDTCTL0 & WWDT_WWDTCTL0_WINDOW1_MASK) >> 4);
    }

    return (DL_WWDT_WINDOW_PERIOD)(period);
}

/*!
 *  @brief      Get the timer period for the watchdog
 *
 *  @param[in]  wwdt  Pointer to the register overlay for peripheral
 *
 *  @return     The current timer period for the watchdog
 *
 *  @retval     One of @ref DL_WWDT_TIMER_PERIOD
 */
__STATIC_INLINE DL_WWDT_TIMER_PERIOD DL_WWDT_getTimerPeriod(WWDT_Regs *wwdt)
{
    uint32_t period = (wwdt->WWDTCTL0 & WWDT_WWDTCTL0_PER_MASK);

    return (DL_WWDT_TIMER_PERIOD)(period);
}

/*!
 *  @brief      Get the clock divider for the watchdog
 *
 *  @param[in]  wwdt  Pointer to the register overlay for peripheral
 *
 *  @return     The current clock divider used
 *
 *  @retval     One of @ref DL_WWDT_CLOCK_DIVIDE
 */
__STATIC_INLINE DL_WWDT_CLOCK_DIVIDE DL_WWDT_getClockDivider(WWDT_Regs *wwdt)
{
    uint32_t clockDivider = (wwdt->WWDTCTL0 & WWDT_WWDTCTL0_CLKDIV_MASK);

    return (DL_WWDT_CLOCK_DIVIDE)(clockDivider);
}

/**
 *  @brief      Enable WWDT interrupt
 *
 *  @param[in]  wwdt  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_WWDT_enableInterrupt(WWDT_Regs *wwdt)
{
    wwdt->CPU_INT.IMASK = WWDT_IMASK_INTTIM_SET;
}

/**
 *  @brief      Disable WWDT interrupt
 *
 *  @param[in]  wwdt  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_WWDT_disableInterrupt(WWDT_Regs *wwdt)
{
    wwdt->CPU_INT.IMASK = WWDT_IMASK_INTTIM_CLR;
}

/**
 *  @brief      Check if WWDT interrupt is enabled
 *
 *  @param[in]  wwdt Pointer to the register overlay for the peripheral
 *
 *  @return     If the WWDT interrupt is enabled
 *
 *  @retval     true  The WWDT interrupt is enabled
 *  @retval     false The WWDT interrupt is disabled
 */
__STATIC_INLINE bool DL_WWDT_isInterruptEnabled(WWDT_Regs *wwdt)
{
    return ((wwdt->CPU_INT.IMASK & WWDT_IMASK_INTTIM_SET) ==
            WWDT_IMASK_INTTIM_SET);
}

/**
 *  @brief      Check interrupt flag of enabled WWDT interrupt
 *
 *  Checks if the WWDT interrupt that was previously enabled is pending.
 *
 *  @param[in]  wwdt  Pointer to the register overlay for the peripheral
 *
 *  @return     If the enabled WWDT interrupt is pending
 *
 *  @retval     true  The WWDT interrupt is pending
 *  @retval     false The WWDT interrupt is not pending
 *
 *  @sa         DL_WWDT_enableInterrupt
 */
__STATIC_INLINE bool DL_WWDT_getEnabledInterruptStatus(WWDT_Regs *wwdt)
{
    return ((wwdt->CPU_INT.MIS & WWDT_MIS_INTTIM_SET) == WWDT_MIS_INTTIM_SET);
}

/**
 *  @brief      Check interrupt flag of any WWDT interrupt
 *
 *  Checks if the WWDT interrupt is pending. Interrupt does not have to
 *  be previously enabled.
 *
 *  @param[in]  wwdt  Pointer to the register overlay for the peripheral
 *
 *  @return     If the WWDT interrupt is pending
 *
 *  @retval     true  The WWDT interrupt is pending
 *  @retval     false The WWDT interrupt is not pending
 */
__STATIC_INLINE uint32_t DL_WWDT_getRawInterruptStatus(WWDT_Regs *wwdt)
{
    return (wwdt->CPU_INT.RIS & WWDT_RIS_INTTIM_SET);
}

/**
 *  @brief      Get highest priority pending WWDT interrupt
 *
 *  Checks if any of the WWDT interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  wwdt  Pointer to the register overlay for the peripheral
 *
 *  @return     The highest priority pending WWDT interrupt
 *
 *  @retval     One of @ref DL_WWDT_IIDX
 */
__STATIC_INLINE DL_WWDT_IIDX DL_WWDT_getPendingInterrupt(WWDT_Regs *wwdt)
{
    return (DL_WWDT_IIDX)(wwdt->CPU_INT.IIDX);
}

/**
 *  @brief      Clear pending WWDT interrupt
 *
 *  @param[in]  wwdt  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_WWDT_clearInterruptStatus(WWDT_Regs *wwdt)
{
    wwdt->CPU_INT.ICLR = WWDT_ICLR_INTTIM_CLR;
}

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_WWDT__ */

#endif /* ti_dl_dl_wwdt__include */
/** @}*/
