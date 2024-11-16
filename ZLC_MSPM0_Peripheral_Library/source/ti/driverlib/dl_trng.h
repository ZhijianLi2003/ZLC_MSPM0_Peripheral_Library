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
 *  @file       dl_trng.h
 *  @brief      True Random Number Generator (TRNG) Driver Library
 *  @defgroup   TRNG True Random Number Generator (TRNG)
 *
 *  @anchor ti_dl_dl_m0p_trng_Overview
 *  # Overview
 *
 *  The True Random Number Generator Driver Library allows full configuration of
 *  the MSPM0 TRNG module.
 *  The true random number generator (TRNG) block is an entropy source which
 *  can be used to generate random bit sequences.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup TRNG
 * @{
 */
#ifndef ti_dl_dl_trng__include
#define ti_dl_dl_trng__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_TRNG__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/** @addtogroup DL_TRNG_INTERRUPT
 *  @{
 */

/*!
* @brief TRNG interrupt definition for health test failed
*/
#define DL_TRNG_INTERRUPT_HEALTH_FAIL_EVENT   (TRNG_IMASK_IRQ_HEALTH_FAIL_MASK)

/*!
* @brief TRNG interrupt definition for commafnd done
*/
#define DL_TRNG_INTERRUPT_CMD_DONE_EVENT         (TRNG_IMASK_IRQ_CMD_DONE_MASK)

/*!
* @brief TRNG interrupt definition for command fail
*/
#define DL_TRNG_INTERRUPT_CMD_FAIL_EVENT         (TRNG_IMASK_IRQ_CMD_FAIL_MASK)

/*!
* @brief TRNG interrupt definition for capture ready
*/
#define DL_TRNG_INTERRUPT_CAPTURE_RDY_EVENT  (TRNG_IMASK_IRQ_CAPTURED_RDY_MASK)
/** @}*/

/** @addtogroup DL_TRNG_HEALTH_TEST_SUCCESS
 *  @{
 */

/*!
* @brief TRNG Digital health test success value
*/
#define DL_TRNG_DIGITAL_HEALTH_TEST_SUCCESS                              (0xFF)

/*!
* @brief TRNG Analog health test success value
*/
#define DL_TRNG_ANALOG_HEALTH_TEST_SUCCESS                                (0x1)
/** @}*/

/* clang-format on */

/*! @enum DL_TRNG_IIDX */
typedef enum {
    /*! TRNG interrupt index for health fail */
    DL_TRNG_IIDX_HEALTH_FAIL = TRNG_IIDX_STAT_IRQ_HEALTH_FAIL,
    /*! TRNG interrupt index for command done */
    DL_TRNG_IIDX_CMD_DONE = TRNG_IIDX_STAT_IRQ_CMD_DONE,
    /*! TRNG interrupt index for command fail */
    DL_TRNG_IIDX_CMD_FAIL = TRNG_IIDX_STAT_IRQ_CMD_FAIL,
    /*! TRNG interrupt index indicating the capture buffer is ready */
    DL_TRNG_IIDX_CAPTURED_READY = TRNG_IIDX_STAT_IRQ_CAPTURED_RDY,
} DL_TRNG_IIDX;

/*! @enum DL_TRNG_DECIMATION_RATE */
typedef enum {
    /*! Decimation by 1 (no decimation) */
    DL_TRNG_DECIMATION_RATE_1 = 0x0,
    /*! Decimation rate 2 -- take every other sample */
    DL_TRNG_DECIMATION_RATE_2 = 0x1,
    /*! Decimation rate 3 -- take every third sample */
    DL_TRNG_DECIMATION_RATE_3 = 0x2,
    /*! Decimation rate 4 -- take every fourth sample */
    DL_TRNG_DECIMATION_RATE_4 = 0x3,
    /*! Decimation rate 5 -- take every fifth sample */
    DL_TRNG_DECIMATION_RATE_5 = 0x4,
    /*! Decimation rate 6 -- take every sixth sample */
    DL_TRNG_DECIMATION_RATE_6 = 0x5,
    /*! Decimation rate 7 -- take every seventh sample */
    DL_TRNG_DECIMATION_RATE_7 = 0x6,
    /*! Decimation rate 8 -- take every eighth sample */
    DL_TRNG_DECIMATION_RATE_8 = 0x7,
} DL_TRNG_DECIMATION_RATE;

/*! @enum DL_TRNG_CMD */
typedef enum {
    /*! TRNG command to power off analog blocks and digital blocks are gated */
    DL_TRNG_CMD_PWROFF = TRNG_CTL_CMD_PWR_OFF,
    /*! TRNG command to execute digital power-on self-tests */
    DL_TRNG_CMD_TEST_DIG = TRNG_CTL_CMD_PWRUP_DIG,
    /*! TRNG command to execute digital power-on self-tests */
    DL_TRNG_CMD_TEST_ANA = TRNG_CTL_CMD_PWRUP_ANA,
    /*! TRNG command to go into normal operating mode */
    DL_TRNG_CMD_NORM_FUNC = TRNG_CTL_CMD_NORM_FUNC,
} DL_TRNG_CMD;

/*! @enum DL_TRNG_CLOCK_DIVIDE */
typedef enum {
    /*! Clock divide by 1 */
    DL_TRNG_CLOCK_DIVIDE_1 = TRNG_CLKDIVIDE_RATIO_DIV_BY_1,
    /*! Clock divide by 2 */
    DL_TRNG_CLOCK_DIVIDE_2 = TRNG_CLKDIVIDE_RATIO_DIV_BY_2,
    /*! Clock divide by 4 */
    DL_TRNG_CLOCK_DIVIDE_4 = TRNG_CLKDIVIDE_RATIO_DIV_BY_4,
    /*! Clock divide by 6 */
    DL_TRNG_CLOCK_DIVIDE_6 = TRNG_CLKDIVIDE_RATIO_DIV_BY_6,
    /*! Clock divide by 8 */
    DL_TRNG_CLOCK_DIVIDE_8 = TRNG_CLKDIVIDE_RATIO_DIV_BY_8,
} DL_TRNG_CLOCK_DIVIDE;

/*! @enum DL_TRNG_STATE */
typedef enum {
    /*! Current state of the TRNG is OFF */
    DL_TRNG_STATE_OFF = 0x0,
    /*! Current state of the TRNG is PWRUP_ES */
    DL_TRNG_STATE_PWRUP_ES = 0x1,
    /*! Current state of the TRNG is NORM_FUNC */
    DL_TRNG_STATE_NORM_FUNC = 0x3,
    /*! Current state of the TRNG is TEST_DIG */
    DL_TRNG_STATE_TEST_DIG = 0x7,
    /*! Current state of the TRNG is TEST_ANA */
    DL_TRNG_STATE_TEST_ANA = 0xB,
    /*! Current state of the TRNG is ERROR */
    DL_TRNG_STATE_ERROR = 0xA,
    /*! Current state of the TRNG is PWRDOWN_ES */
    DL_TRNG_STATE_PWRDOWN = 0x2,
} DL_TRNG_STATE;

/**
 * @brief Configuration structure to backup TRNG peripheral state before
 *        going to STOP/STANDBY mode. Not required after PG 1.0 silicon. Used
 *        by @ref DL_TRNG_saveConfiguration
 */
typedef struct {
    /*! TRNG control word. Combination of @ref DL_TRNG_DECIMATION_RATE and
     *  @ref DL_TRNG_CMD */
    uint32_t controlWord;
    /*! TRNG clock divider. Must be one of @ref DL_TRNG_CLOCK_DIVIDE */
    uint32_t clockDivider;
    /*! TRNG interrupt status. Must be one of @ref DL_TRNG_IIDX */
    uint32_t interruptMask;
    /*! Boolean flag indicating whether or not a valid configuration structure
       exists. Should not be modified by the user. */
    bool backupRdy;
} DL_TRNG_backupConfig;

/**
 * @brief Enables power on TRNG module
 *
 * @param trng  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_TRNG_enablePower(TRNG_Regs *trng)
{
    trng->GPRCM.PWREN = TRNG_PWREN_KEY_UNLOCK_W | TRNG_PWREN_ENABLE_ENABLE;
}

/**
 * @brief Disable power on TRNG module
 *
 * @param trng  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_TRNG_disablePower(TRNG_Regs *trng)
{
    trng->GPRCM.PWREN = TRNG_PWREN_KEY_UNLOCK_W | TRNG_PWREN_ENABLE_DISABLE;
}

/**
 * @brief Get the clock divider on the TRNG module
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return      Clock divider value for the TRNG module
 */
__STATIC_INLINE DL_TRNG_CLOCK_DIVIDE DL_TRNG_getClockDivider(TRNG_Regs *trng)
{
    return (DL_TRNG_CLOCK_DIVIDE) trng->CLKDIVIDE;
}

/**
 * @brief Set the clock divider on the TRNG module
 *
 * @param trng          Pointer to the register overlay for the peripheral
 *
 * @param clockDivider  Clock divider value for the TRNG module.
 *                      One of @ref DL_TRNG_CLOCK_DIVIDE
 */
__STATIC_INLINE void DL_TRNG_setClockDivider(
    TRNG_Regs *trng, DL_TRNG_CLOCK_DIVIDE clockDivider)
{
    trng->CLKDIVIDE = (uint32_t) clockDivider;
}

/**
 * @brief Resets the TRNG module
 *
 * @param trng  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_TRNG_reset(TRNG_Regs *trng)
{
    trng->GPRCM.RSTCTL =
        TRNG_RSTCTL_RESETASSERT_ASSERT | TRNG_RSTCTL_KEY_UNLOCK_W;
}

/**
 * @brief Returns if TRNG peripheral was reset
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 */
__STATIC_INLINE bool DL_TRNG_isReset(TRNG_Regs *trng)
{
    return (trng->GPRCM.STAT & TRNG_GPRCM_STAT_RESETSTKY_MASK) ==
           TRNG_GPRCM_STAT_RESETSTKY_RESET;
}

/**
 * @brief Returns if the data capture is ready
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return true if the data capture is ready
 * @return false if the data capture is not ready
 */
__STATIC_INLINE bool DL_TRNG_isCaptureReady(TRNG_Regs *trng)
{
    return ((trng->CPU_INT.RIS & TRNG_RIS_IRQ_CAPTURED_RDY_MASK)) ==
           TRNG_RIS_IRQ_CAPTURED_RDY_SET;
}

/**
 * @brief Returns if the issued TRNG command is done
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return true if the issued command is done
 * @return false if the issued command is not done
 */
__STATIC_INLINE bool DL_TRNG_isCommandDone(TRNG_Regs *trng)
{
    return ((trng->CPU_INT.RIS & TRNG_RIS_IRQ_CMD_DONE_MASK)) ==
           TRNG_RIS_IRQ_CMD_DONE_SET;
}

/**
 * @brief Returns if the issued TRNG command failed
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return true if the issued command failed
 * @return false if the issued command failed
 */
__STATIC_INLINE bool DL_TRNG_isCommandFail(TRNG_Regs *trng)
{
    return ((trng->CPU_INT.RIS & TRNG_RIS_IRQ_CMD_FAIL_MASK)) ==
           TRNG_RIS_IRQ_CMD_FAIL_SET;
}

/**
 * @brief Returns if a health test failed
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return true if a health test is failed
 * @return false if a health test did not fail
 */
__STATIC_INLINE bool DL_TRNG_isHealthTestFail(TRNG_Regs *trng)
{
    return ((trng->CPU_INT.RIS & TRNG_RIS_IRQ_HEALTH_FAIL_MASK)) ==
           TRNG_RIS_IRQ_HEALTH_FAIL_SET;
}

/**
 * @brief Set the decimation rate
 *
 * @param trng            Pointer to the register overlay for the peripheral
 *
 * @param decimationRate  Decimation rate to set.
 *                        One of @ref DL_TRNG_DECIMATION_RATE
 */
__STATIC_INLINE void DL_TRNG_setDecimationRate(
    TRNG_Regs *trng, DL_TRNG_DECIMATION_RATE decimationRate)
{
    DL_Common_updateReg(&trng->CTL,
        ((uint32_t) decimationRate << TRNG_CTL_DECIM_RATE_OFS),
        TRNG_CTL_DECIM_RATE_MASK);
}

/**
 *  @brief      Get the decimation rate
 *
 *  @param[in]  trng  Pointer to the register overlay for the peripheral
 *
 *  @return     The decimation rate of the TRNG module
 *
 *  @retval     One of @ref DL_TRNG_DECIMATION_RATE
 */
__STATIC_INLINE DL_TRNG_DECIMATION_RATE DL_TRNG_getDecimationRate(
    TRNG_Regs *trng)
{
    uint32_t decimationRate =
        ((trng->CTL & TRNG_CTL_DECIM_RATE_MASK) >> TRNG_CTL_DECIM_RATE_OFS);

    return (DL_TRNG_DECIMATION_RATE)(decimationRate);
}

/**
 * @brief Get the digital health test results
 *
 * The test sequence includes eight tests, and each test reports its status in
 * an individual result bit. As each test passes, the corresponding bit is set.
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return The results of the digital health tests
 *
 * @retval DL_TRNG_DIGITAL_HEALTH_TEST_SUCCESS if all tests passed,
 *         otherwise a bitmask of which tests passed
 */
__STATIC_INLINE uint8_t DL_TRNG_getDigitalHealthTestResults(TRNG_Regs *trng)
{
    return (uint8_t)(trng->TEST_RESULTS & TRNG_TEST_RESULTS_DIG_TEST_MASK);
}

/**
 * @brief Get the analog health test results
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return The results of the analog health test
 *
 * @retval DL_TRNG_ANALOG_HEALTH_TEST_SUCCESS if success
 * @retval 0 if test failed
 */
__STATIC_INLINE uint8_t DL_TRNG_getAnalogHealthTestResults(TRNG_Regs *trng)
{
    return (uint8_t)((trng->TEST_RESULTS & TRNG_TEST_RESULTS_ANA_TEST_MASK) >>
                     TRNG_TEST_RESULTS_ANA_TEST_OFS);
}

/**
 * @brief Get the current state of the TRNG front end FSM
 *
 * This API should be called twice since two reads of the state are required as
 * there is a chance of metastability when reading this register.
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return The current state of the TRNG
 *
 * @retval One of @ref DL_TRNG_STATE
 */
__STATIC_INLINE uint32_t DL_TRNG_getCurrentState(TRNG_Regs *trng)
{
    return ((trng->STAT & TRNG_STAT_FSM_STATE_MASK)) >>
           TRNG_STAT_FSM_STATE_OFS;
}

/**
 * @brief Get the last accepted command that was issued to the TRNG
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return The last issued accepted command
 *
 * @retval One of @ref DL_TRNG_CMD
 */
__STATIC_INLINE uint32_t DL_TRNG_getIssuedCommand(TRNG_Regs *trng)
{
    return ((trng->STAT & TRNG_STAT_ISSUED_CMD_MASK)) >>
           TRNG_STAT_ISSUED_CMD_OFS;
}

/**
 * @brief Indicates if the repetition counter test caused the most recent
 *        failure
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return The status of the repetition test
 *
 * @retval true if the repetition test failed
 * @retval false if the repetition test did not fail
 */
__STATIC_INLINE bool DL_TRNG_isRepetitionTestFail(TRNG_Regs *trng)
{
    return ((trng->STAT & TRNG_STAT_REP_FAIL_MASK)) == TRNG_STAT_REP_FAIL_MASK;
}

/**
 * @brief Indicates if the Adaptive Proportion Test (1,2,3, or 4-bit counters)
 *        caused the most recent failure
 *
 * @param trng  Pointer to the register overlay for the peripheral
 *
 * @return The status of the Adaptive Proportion Test
 *
 * @retval true if the repetition test failed
 * @retval false if the repetition test did not fail
 */
__STATIC_INLINE bool DL_TRNG_isAdaptiveTestFail(TRNG_Regs *trng)
{
    return ((trng->STAT & TRNG_STAT_ADAP_FAIL_MASK)) ==
           TRNG_STAT_ADAP_FAIL_MASK;
}

/**
 *  @brief      Enable TRNG interrupt
 *
 *  @param[in]  trng  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TRNG_INTERRUPT.
 */
__STATIC_INLINE void DL_TRNG_enableInterrupt(
    TRNG_Regs *trng, uint32_t interruptMask)
{
    trng->CPU_INT.IMASK |= interruptMask;
}

/**
 *  @brief      Disable TRNG interrupt
 *
 *  @param[in]  trng  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TRNG_INTERRUPT.
 */
__STATIC_INLINE void DL_TRNG_disableInterrupt(
    TRNG_Regs *trng, uint32_t interruptMask)
{
    trng->CPU_INT.IMASK &= ~interruptMask;
}

/**
 *  @brief      Check which TRNG interrupts are enabled
 *
 *  @param[in]  trng           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TRNG_IIDX.
 *
 *  @return     Which of the requested TRNG interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_TRNG_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_TRNG_getEnabledInterrupts(
    TRNG_Regs *trng, uint32_t interruptMask)
{
    return trng->CPU_INT.IMASK & interruptMask;
}

/**
 *  @brief      Check interrupt flag of enabled TRNG interrupt
 *
 *  Checks if the TRNG interrupt that was previously enabled is pending.
 *
 *  @param[in]  trng           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TRNG_INTERRUPT.
 *
 *  @return     If the enabled TRNG interrupt is pending
 *
 *  @sa         DL_TRNG_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_TRNG_getEnabledInterruptStatus(
    TRNG_Regs *trng, uint32_t interruptMask)
{
    return (trng->CPU_INT.MIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of any TRNG interrupt
 *
 *  Checks if the TRNG interrupt is pending. Interrupt does not have to
 *  be previously enabled.
 *
 *  @param[in]  trng           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TRNG_INTERRUPT.
 *
 *  @return     If the trng interrupt is pending
 */
__STATIC_INLINE uint32_t DL_TRNG_getRawInterruptStatus(
    TRNG_Regs *trng, uint32_t interruptMask)
{
    return trng->CPU_INT.RIS & interruptMask;
}

/**
 *  @brief      Get highest priority pending TRNG interrupt
 *
 *  Checks if any of the TRNG interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  trng  Pointer to the register overlay for the peripheral
 *
 *  @return     The highest priority pending TRNG interrupt
 *
 *  @retval     One of @ref DL_TRNG_IIDX
 */
__STATIC_INLINE DL_TRNG_IIDX DL_TRNG_getPendingInterrupt(TRNG_Regs *trng)
{
    return (DL_TRNG_IIDX) trng->CPU_INT.IIDX;
}

/**
 *  @brief      Clear pending TRNG interrupt
 *
 *  @param[in]  trng           Pointer to the register overlay for the
 *                             peripheral
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TRNG_INTERRUPT.
 */
__STATIC_INLINE void DL_TRNG_clearInterruptStatus(
    TRNG_Regs *trng, uint32_t interruptMask)
{
    trng->CPU_INT.ICLR = interruptMask;
}

/**
 *  @brief      Update control register's command bits to send a TRNG command
 *
 *  @param[in]  trng  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  cmd   Command to update the control register with
 */
__STATIC_INLINE void DL_TRNG_sendCommand(TRNG_Regs *trng, DL_TRNG_CMD cmd)
{
    DL_Common_updateReg(&trng->CTL, (uint32_t) cmd, TRNG_CTL_CMD_MASK);
}

/**
 *  @brief      Get word capture from TRNG
 *
 *  Gets the captured data from the decimation block.
 *
 *  @param[in]  trng  Pointer to the register overlay for the peripheral
 *
 *  @retval     TRNG capture value
 *
 *  @pre The IRQ_CAPTURED_RDY IRQ should be asserted first, indicating that
 *  random bits are available for read-out.
 *
 *  @sa         DL_TRNG_isCaptureReady
 */
__STATIC_INLINE uint32_t DL_TRNG_getCapture(TRNG_Regs *trng)
{
    return trng->DATA_CAPTURE;
}

/**
 *  @brief      Save TRNG configuration before entering a power loss state.
 *              Only necessary for PG 1.0 silicon.
 *
 *  @param[in]  trng  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr   Configuration backup setup structure. See
 *                    @ref DL_TRNG_backupConfig.
 *
 *  @retval     FALSE if a configuration already exists in ptr (will not be
 *              overwritten). TRUE if a configuration was successfully saved
 */
bool DL_TRNG_saveConfiguration(TRNG_Regs *trng, DL_TRNG_backupConfig *ptr);

/**
 *  @brief      Restore TRNG configuration after leaving a power loss state.
 *              Upon restoration, if the TRNG was not originally in OFF state,
 *              then the TRNG will be set to the normal operating mode.
 *              Only necessary for PG 1.0 silicon.
 *
 *  @param[in]  trng  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr   Configuration backup setup structure. See
 *                    @ref DL_TRNG_backupConfig.
 *
 *  @retval     FALSE if a configuration does not exist in ptr (will not be
 *              loaded). TRUE if a configuration successfully loaded
 */
bool DL_TRNG_restoreConfiguration(TRNG_Regs *trng, DL_TRNG_backupConfig *ptr);

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_TRNG__ */

#endif /* ti_dl_dl_trng__include */
/** @}*/
