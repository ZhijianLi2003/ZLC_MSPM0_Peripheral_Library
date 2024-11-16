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
 *  @file       dl_timer.h
 *  @brief      Common General Purpose Timer (TIMx) Driver Library
 *  @defgroup   TIMX Common General Purpose Timer (TIMx)
 *
 *  @anchor ti_dl_dl_timer__Overview
 *  # Overview
 *  GPTimer module has different variations and have been defined as TimerG
 *  and TimerA. This file contains APIs which are common between
 *  different variations.
 *  <hr>
 *  @anchor ti_devices_msp_DL_TIMER_Usage
 *  # Usage
 *  It is not recommended to include this header file in the application.
 *  In order to access TimerG and TimerA functionality include
 *  to appropriate timer header file at the application level. Accessing the
 *  functionality via the corresponding header file will allow user to
 *  determine the functionality supported by the each Timer variant.
 *
 *  To access TimerG functionality:
 *  @code
 *  // Import TIMG definitions
 *  #include <ti/driverlib/dl_timerg.h>
 *  @endcode
 *
 *  To access TimerA functionality:
 *  @code
 *  // Import TIMA definitions
 *  #include <ti/driverlib/dl_timera.h>
 *  @endcode
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup TIMX
 * @{
 */
#ifndef ti_dl_dl_timer__include
#define ti_dl_dl_timer__include

#if defined(ti_dl_dl_timera__include) || defined(ti_dl_dl_timerg__include) || \
    defined(DOXYGEN__INCLUDE)

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#if defined(__MSPM0_HAS_TIMER_A__) || defined(__MSPM0_HAS_TIMER_G__)

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/** @addtogroup DL_TIMER_CCx
 *  @{
 */

/*!
 * @brief Selects Output direction for CCP0
 */
#define DL_TIMER_CC0_OUTPUT                     (GPTIMER_CCPD_C0CCP0_OUTPUT)

/*!
 * @brief Selects Input direction for CCP0
 */
#define DL_TIMER_CC0_INPUT                      (GPTIMER_CCPD_C0CCP0_INPUT)

/*!
 * @brief Selects Output direction for CCP1
 */
#define DL_TIMER_CC1_OUTPUT                     (GPTIMER_CCPD_C0CCP1_OUTPUT)

/*!
 * @brief Selects Input direction for CCP1
 */
#define DL_TIMER_CC1_INPUT                      (GPTIMER_CCPD_C0CCP1_INPUT)

/*!
 * @brief Selects Output direction for CCP2
 */
#define DL_TIMER_CC2_OUTPUT                     (GPTIMER_CCPD_C0CCP2_OUTPUT)

/*!
 * @brief Selects Input direction for CCP2
 */
#define DL_TIMER_CC2_INPUT                      (GPTIMER_CCPD_C0CCP2_INPUT)

/*!
 * @brief Selects Output direction for CCP3
 */
#define DL_TIMER_CC3_OUTPUT                     (GPTIMER_CCPD_C0CCP3_OUTPUT)

/*!
 * @brief Selects Input direction for CCP3
 */
#define DL_TIMER_CC3_INPUT                      (GPTIMER_CCPD_C0CCP3_INPUT)

/** @}*/

/** @addtogroup DL_TIMER_CC_MODE
 *  @{
 */
/*!
 * @brief Configures CC in Compare mode
 */
#define DL_TIMER_CC_MODE_COMPARE                  (GPTIMER_CCCTL_01_COC_COMPARE)
/*!
 * @brief Configures CC in Capture mode
 */
#define DL_TIMER_CC_MODE_CAPTURE                 (GPTIMER_CCCTL_01_COC_CAPTURE)

/** @}*/

/** @addtogroup DL_TIMER_CC_ZCOND
 *  @{
 */

/*!
 * @brief No event generates zero pulse
 */
#define DL_TIMER_CC_ZCOND_NONE             (GPTIMER_CCCTL_01_ZCOND_CC_TRIG_NO_EFFECT)

/*!
 * @brief Rising edge of CCP or trigger assertion edge generates zero pulse
 */
#define DL_TIMER_CC_ZCOND_TRIG_RISE        (GPTIMER_CCCTL_01_ZCOND_CC_TRIG_RISE)

/*!
 * @brief Falling edge of CCP or trigger or de-assertion edge generates zero
 *        pulse
 */
#define DL_TIMER_CC_ZCOND_TRIG_FALL        (GPTIMER_CCCTL_01_ZCOND_CC_TRIG_FALL)
/*!
 * @brief Either edge of CCP or trigger change (assertion/de-assertion edge)
 *        generates zero pulse
 */
#define DL_TIMER_CC_ZCOND_TRIG_EDGE        (GPTIMER_CCCTL_01_ZCOND_CC_TRIG_EDGE)

/** @}*/

/** @addtogroup DL_TIMER_CC_LCOND
 *  @{
 */

/*!
 * @brief No event generates load pulse
 */
#define DL_TIMER_CC_LCOND_NONE            (GPTIMER_CCCTL_01_LCOND_CC_TRIG_NO_EFFECT)

/*!
 * @brief Rising edge of CCP or trigger assertion edge generates load pulse
 */
#define DL_TIMER_CC_LCOND_TRIG_RISE       (GPTIMER_CCCTL_01_LCOND_CC_TRIG_RISE)

/*!
 * @brief Falling edge of CCP or trigger or de-assertion edge generates load
 *        pulse
 */
#define DL_TIMER_CC_LCOND_TRIG_FALL       (GPTIMER_CCCTL_01_LCOND_CC_TRIG_FALL)

/*!
 * @brief Either edge of CCP or trigger change (assertion/de-assertion edge)
 *        generates load pulse
 */
#define DL_TIMER_CC_LCOND_TRIG_EDGE       (GPTIMER_CCCTL_01_LCOND_CC_TRIG_EDGE)

/** @}*/

/** @addtogroup DL_TIMER_CC_ACOND
 *  @{
 */

/*!
 * @brief Each TIMCLK generates an advance pulse
 */
#define DL_TIMER_CC_ACOND_TIMCLK                 (GPTIMER_CCCTL_01_ACOND_TIMCLK)

/*!
 * @brief Rising edge of CCP or trigger assertion edge generates an advance
 *        pulse
 */
#define DL_TIMER_CC_ACOND_TRIG_RISE       (GPTIMER_CCCTL_01_ACOND_CC_TRIG_RISE)

/*!
 * @brief Falling edge of CCP or trigger de-assertion edge generates an advance
 *        pulse
 */
#define DL_TIMER_CC_ACOND_TRIG_FALL       (GPTIMER_CCCTL_01_ACOND_CC_TRIG_FALL)
/*!
 * @brief Either edge of CCP or trigger change (assertion/de-assertion edge)
 *        generates an advance pulse.
 */
#define DL_TIMER_CC_ACOND_TRIG_EDGE       (GPTIMER_CCCTL_01_ACOND_CC_TRIG_EDGE)
/*!
 * @brief CCP High or Trigger assertion generates an advance pulse.
 */
#define DL_TIMER_CC_ACOND_TRIG_HIGH       (GPTIMER_CCCTL_01_ACOND_CC_TRIG_HIGH)

/** @}*/

/** @addtogroup DL_TIMER_CC_CCOND
 *  @{
 */

/*!
 * @brief None (never captures)
 */
#define DL_TIMER_CC_CCOND_NOCAPTURE       (GPTIMER_CCCTL_01_CCOND_NOCAPTURE)

/*!
 * @brief Rising edge of CCP or trigger assertion edge generates a capture
 *        pulse
 */
#define DL_TIMER_CC_CCOND_TRIG_RISE       (GPTIMER_CCCTL_01_CCOND_CC_TRIG_RISE)
/*!
 * @brief Falling edge of CCP or trigger de-assertion edge generates a capture
 *        pulse
 */
#define DL_TIMER_CC_CCOND_TRIG_FALL       (GPTIMER_CCCTL_01_CCOND_CC_TRIG_FALL)
/*!
 * @brief Either edge of CCP or trigger change (assertion/de-assertion edge)
 *        generates a capture pulse
 */
#define DL_TIMER_CC_CCOND_TRIG_EDGE       (GPTIMER_CCCTL_01_CCOND_CC_TRIG_EDGE)

/** @}*/


/** @addtogroup DL_TIMER_CC_OCTL_INIT_VAL
 *  @{
 */
/*!
 * @brief CCP is low while output is disabled
 */
#define DL_TIMER_CC_OCTL_INIT_VAL_LOW              (GPTIMER_OCTL_01_CCPIV_LOW)

/*!
 * @brief CCP is high while output is disabled
 */
#define DL_TIMER_CC_OCTL_INIT_VAL_HIGH             (GPTIMER_OCTL_01_CCPIV_HIGH)

/** @}*/

/** @addtogroup DL_TIMER_CC_OCTL_INV_OUT
 *  @{
 */
/*!
 * @brief CCP Output inversion is enabled
 */
#define DL_TIMER_CC_OCTL_INV_OUT_ENABLED        (GPTIMER_OCTL_01_CCPOINV_INV)

/*!
 * @brief CCP Output inversion is disabled
 */
#define DL_TIMER_CC_OCTL_INV_OUT_DISABLED       (GPTIMER_OCTL_01_CCPOINV_NOINV)

/** @}*/

/** @addtogroup DL_TIMER_CC_OCTL_SRC
 *  @{
 */
/*!
 * @brief Output controlled by function values (e.g. PWM)
 */
#define DL_TIMER_CC_OCTL_SRC_FUNCVAL       (GPTIMER_OCTL_01_CCPO_FUNCVAL)

/*!
 * @brief Output controlled by load event
 */
#define DL_TIMER_CC_OCTL_SRC_LOAD          (GPTIMER_OCTL_01_CCPO_LOAD)

/*!
 * @brief Output controlled by compare value = counter condition.
 */
#define DL_TIMER_CC_OCTL_SRC_CMPVAL        (GPTIMER_OCTL_01_CCPO_CMPVAL)

/*!
 * @brief Output controlled by zero event.
 */
#define DL_TIMER_CC_OCTL_SRC_ZERO          (GPTIMER_OCTL_01_CCPO_ZERO)

/*!
 * @brief Output controlled by capture event.
 */
#define DL_TIMER_CC_OCTL_SRC_CAPCOND       (GPTIMER_OCTL_01_CCPO_CAPCOND)

/*!
 * @brief Output controlled by fault condition.
 */
#define DL_TIMER_CC_OCTL_SRC_FAULTCOND       (GPTIMER_OCTL_01_CCPO_FAULTCOND)

/*!
 * @brief Mirror CCP of first capture and compare register in counter group.
 */
#define DL_TIMER_CC_OCTL_SRC_CC0_MIRR_ALL  (GPTIMER_OCTL_01_CCPO_CC0_MIRROR_ALL)

/*!
 * @brief Mirror CCP of second capture and compare register in counter group.
 */
#define DL_TIMER_CC_OCTL_SRC_CC1_MIRR_ALL  (GPTIMER_OCTL_01_CCPO_CC1_MIRROR_ALL)

/*!
 * @brief Dead band inserted output
 */
#define DL_TIMER_CC_OCTL_SRC_DEAD_BAND           (GPTIMER_OCTL_01_CCPO_DEADBAND)

/*!
 * @brief Counter direction.
 */
#define DL_TIMER_CC_OCTL_SRC_CNTDIR                (GPTIMER_OCTL_01_CCPO_CNTDIR)
/** @}*/

/** @addtogroup DL_TIMER_CC_SWFRCACT_CMPL
 *  @{
 */

/*!
 * @brief The CCP complimentary output value is unaffected by the event.
 */
#define DL_TIMER_CC_SWFRCACT_CMPL_DISABLED           (GPTIMER_CCACT_01_SWFRCACT_CMPL_DISABLED)

/*!
 * @brief CCP complimentary output value is set high.
 */
#define DL_TIMER_CC_SWFRCACT_CMPL_HIGH               (GPTIMER_CCACT_01_SWFRCACT_CMPL_CCP_HIGH)

/*!
 * @brief CCP complimentary output value is set low.
 */
#define DL_TIMER_CC_SWFRCACT_CMPL_LOW                 (GPTIMER_CCACT_01_SWFRCACT_CMPL_CCP_LOW)

/** @}*/

/** @addtogroup DL_TIMER_CC_SWFRCACT
 *  @{
 */

/*!
 * @brief The CCP output value is unaffected by the event.
 */
#define DL_TIMER_CC_SWFRCACT_DISABLED           (GPTIMER_CCACT_01_SWFRCACT_DISABLED)

/*!
 * @brief CCP output value is set high.
 */
#define DL_TIMER_CC_SWFRCACT_HIGH               (GPTIMER_CCACT_01_SWFRCACT_CCP_HIGH)

/*!
 * @brief CCP output value is set low.
 */
#define DL_TIMER_CC_SWFRCACT_LOW                 (GPTIMER_CCACT_01_SWFRCACT_CCP_LOW)

/** @}*/

/** @addtogroup DL_TIMER_CC_FEXACT
 *  @{
 */

/*!
 * @brief The CCP output value is unaffected by the event.
 */
#define DL_TIMER_CC_FEXACT_DISABLED           (GPTIMER_CCACT_01_FEXACT_DISABLED)

/*!
 * @brief CCP output value is set high.
 */
#define DL_TIMER_CC_FEXACT_HIGH               (GPTIMER_CCACT_01_FEXACT_CCP_HIGH)

/*!
 * @brief CCP output value is set low.
 */
#define DL_TIMER_CC_FEXACT_LOW                 (GPTIMER_CCACT_01_FEXACT_CCP_LOW)

/*!
 * @brief CCP output value is toggled.
 */
#define DL_TIMER_CC_FEXACT_TOGGLE           (GPTIMER_CCACT_01_FEXACT_CCP_TOGGLE)


/*!
 * @brief CCP output value is Hi-Z.
 */
#define DL_TIMER_CC_FEXACT_HIGHZ           (GPTIMER_CCACT_01_FEXACT_CCP_HIGHZ)


/** @}*/

/** @addtogroup DL_TIMER_CC_FENACT
 *  @{
 */

/*!
 * @brief The CCP output value is unaffected by the event.
 */
#define DL_TIMER_CC_FENACT_DISABLED           (GPTIMER_CCACT_01_FENACT_DISABLED)

/*!
 * @brief CCP output value is set high.
 */
#define DL_TIMER_CC_FENACT_CCP_HIGH           (GPTIMER_CCACT_01_FENACT_CCP_HIGH)

/*!
 * @brief CCP output value is set low
 */
#define DL_TIMER_CC_FENACT_CCP_LOW             (GPTIMER_CCACT_01_FENACT_CCP_LOW)

/*!
 * @brief CCP output value is toggled.
 */
#define DL_TIMER_CC_FENACT_CCP_TOGGLE      \
                                            (GPTIMER_CCACT_01_FENACT_CCP_TOGGLE)

/*!
 * @brief CCP output value is Hi-Z.
 */
#define DL_TIMER_CC_FENACT_HIGHZ           (GPTIMER_CCACT_01_FENACT_CCP_HIGHZ)


/** @}*/

/** @addtogroup DL_TIMER_CC_CC2UACT
 *  @{
 */

/*!
 * @brief The CCP output value is unaffected by the event.
 */
#define DL_TIMER_CC_CC2UACT_DISABLED           (GPTIMER_CCACT_01_CC2UACT_DISABLED)

/*!
 * @brief CCP output value is set high.
 */
#define DL_TIMER_CC_CC2UACT_CCP_HIGH           (GPTIMER_CCACT_01_CC2UACT_CCP_HIGH)

/*!
 * @brief CCP output value is set low
 */
#define DL_TIMER_CC_CC2UACT_CCP_LOW             (GPTIMER_CCACT_01_CC2UACT_CCP_LOW)

/*!
 * @brief CCP output value is toggled.
 */
#define DL_TIMER_CC_CC2UACT_CCP_TOGGLE      \
                                            (GPTIMER_CCACT_01_CC2UACT_CCP_TOGGLE)

/** @}*/

/** @addtogroup DL_TIMER_CC_CC2DACT
 *  @{
 */

/*!
 * @brief The CCP output value is unaffected by the event.
 */
#define DL_TIMER_CC_CC2DACT_DISABLED           (GPTIMER_CCACT_01_CC2DACT_DISABLED)

/*!
 * @brief CCP output value is set high.
 */
#define DL_TIMER_CC_CC2DACT_CCP_HIGH           (GPTIMER_CCACT_01_CC2DACT_CCP_HIGH)

/*!
 * @brief CCP output value is set low
 */
#define DL_TIMER_CC_CC2DACT_CCP_LOW             (GPTIMER_CCACT_01_CC2DACT_CCP_LOW)

/*!
 * @brief CCP output value is toggled.
 */
#define DL_TIMER_CC_CC2DACT_CCP_TOGGLE      \
                                            (GPTIMER_CCACT_01_CC2DACT_CCP_TOGGLE)

/** @}*/

 /** @addtogroup DL_TIMER_CC_CUACT
 *  @{
 */
/*!
 * @brief The CCP output value is unaffected by the event
 */
#define DL_TIMER_CC_CUACT_DISABLED         (GPTIMER_CCACT_01_CUACT_DISABLED)
/*!
 * @brief CCP output value is set high
 */
#define DL_TIMER_CC_CUACT_CCP_HIGH         (GPTIMER_CCACT_01_CUACT_CCP_HIGH)
/*!
 * @brief CCP output value is set low
 */
#define DL_TIMER_CC_CUACT_CCP_LOW          (GPTIMER_CCACT_01_CUACT_CCP_LOW)
/*!
 * @brief CCP output value is toggled
 */
#define DL_TIMER_CC_CUACT_CCP_TOGGLE       (GPTIMER_CCACT_01_CUACT_CCP_TOGGLE)

/** @}*/

 /** @addtogroup DL_TIMER_CC_CDACT
 *  @{
 */
/*!
 * @brief The CCP output value is unaffected by the event
 */
#define DL_TIMER_CC_CDACT_DISABLED         (GPTIMER_CCACT_01_CDACT_DISABLED)
/*!
 * @brief CCP output value is set high
 */
#define DL_TIMER_CC_CDACT_CCP_HIGH         (GPTIMER_CCACT_01_CDACT_CCP_HIGH)
/*!
 * @brief CCP output value is set low
 */
#define DL_TIMER_CC_CDACT_CCP_LOW          (GPTIMER_CCACT_01_CDACT_CCP_LOW)
/*!
 * @brief CCP output value is toggled
 */
#define DL_TIMER_CC_CDACT_CCP_TOGGLE       (GPTIMER_CCACT_01_CDACT_CCP_TOGGLE)

/** @}*/

/** @addtogroup DL_TIMER_CC_LACT
 *  @{
 */

/*!
 * @brief The CCP output value is unaffected by the event
 */

#define DL_TIMER_CC_LACT_DISABLED         (GPTIMER_CCACT_01_LACT_DISABLED)

/*!
 * @brief CCP output value is set high
 */
#define DL_TIMER_CC_LACT_CCP_HIGH         (GPTIMER_CCACT_01_LACT_CCP_HIGH)

/*!
 * @brief CCP output value is low
 */
#define DL_TIMER_CC_LACT_CCP_LOW          (GPTIMER_CCACT_01_LACT_CCP_LOW)

/*!
 * @brief CCP output value is toggled
 */
#define DL_TIMER_CC_LACT_CCP_TOGGLE       (GPTIMER_CCACT_01_LACT_CCP_TOGGLE)

/** @}*/

/** @addtogroup DL_TIMER_CC_ZACT
 *  @{
 */
/*!
 * @brief The CCP output value is unaffected by the event
 */
#define DL_TIMER_CC_ZACT_DISABLED         (GPTIMER_CCACT_01_ZACT_DISABLED)

/*!
 * @brief CCP output value is high
 */
#define DL_TIMER_CC_ZACT_CCP_HIGH         (GPTIMER_CCACT_01_ZACT_CCP_HIGH)

/*!
 * @brief CCP output value is low
 */
#define DL_TIMER_CC_ZACT_CCP_LOW          (GPTIMER_CCACT_01_ZACT_CCP_LOW)

/*!
 * @brief CCP output value is toggled
 */
#define DL_TIMER_CC_ZACT_CCP_TOGGLE       (GPTIMER_CCACT_01_ZACT_CCP_TOGGLE)

/** @}*/

/** @addtogroup DL_TIMER_CC_INPUT_INV
 *  @{
 */

/*!
 * @brief CCP input is not inverted
 */
#define DL_TIMER_CC_INPUT_INV_NOINVERT (GPTIMER_IFCTL_01_INV_NOINVERT)

/*!
 * @brief CCP input is inverted
 */
#define DL_TIMER_CC_INPUT_INV_INVERT   (GPTIMER_IFCTL_01_INV_INVERT)

/** @}*/

/** @addtogroup DL_TIMER_CC_IN_SEL
 *  @{
 */

/*!
 * @brief CCP of the corresponding capture compare unit
 */
#define DL_TIMER_CC_IN_SEL_CCPX      (GPTIMER_IFCTL_01_ISEL_CCPX_INPUT)

/*!
 * @brief Input pair CCPX of the capture compare unit. For CCP0 input
 *        pair is CCP1 and viceversa.
 */
#define DL_TIMER_CC_IN_SEL_CCPX_PAIR  (GPTIMER_IFCTL_01_ISEL_CCPX_INPUT_PAIR)

/*!
 * @brief CCP0 of the counter
 */
#define DL_TIMER_CC_IN_SEL_CCP0      (GPTIMER_IFCTL_01_ISEL_CCP0_INPUT)

/*!
 * @brief Trigger
 */
#define DL_TIMER_CC_IN_SEL_TRIG      (GPTIMER_IFCTL_01_ISEL_TRIG_INPUT)


/*!
 * @brief XOR of CCP inputs as input source
 */
#define DL_TIMER_CC_IN_SEL_CCP_XOR      (GPTIMER_IFCTL_01_ISEL_CCP_XOR)

/*!
 * @brief subscriber 0 event as input source
 */
#define DL_TIMER_CC_IN_SEL_FSUB0      (GPTIMER_IFCTL_01_ISEL_FSUB0)

/*!
 * @brief subscriber 1 event as input source
 */
#define DL_TIMER_CC_IN_SEL_FSUB1      (GPTIMER_IFCTL_01_ISEL_FSUB1)

/*!
 * @brief Comparator 0 output
 */
#define DL_TIMER_CC_IN_SEL_COMP0      (GPTIMER_IFCTL_01_ISEL_COMP0)

/*!
 * @brief Comparator 1 output
 */
#define DL_TIMER_CC_IN_SEL_COMP1      (GPTIMER_IFCTL_01_ISEL_COMP1)

/*!
 * @brief Comparator 2 output.
 */
#define DL_TIMER_CC_IN_SEL_COMP2      (GPTIMER_IFCTL_01_ISEL_COMP2)



/** @}*/

/** @addtogroup DL_TIMER_FAULT_SOURCE
 *  @{
 */

/*!
* @brief Disables COMP0 as fault source
*/
#define DL_TIMER_FAULT_SOURCE_COMP0_DISABLE                                   \
        (GPTIMER_FSCTL_FAC0EN_DISABLE | (GPTIMER_FCTL_FSENAC0_LOWCTIVE << 16))

/*!
* @brief Enables COMP0 as fault source and fault input is active low
*/
#define DL_TIMER_FAULT_SOURCE_COMP0_SENSE_LOW                                 \
        (GPTIMER_FSCTL_FAC0EN_ENABLE | (GPTIMER_FCTL_FSENAC0_LOWCTIVE << 16))

/*!
* @brief Enables COMP0 as fault source and fault input is active high
*/
#define DL_TIMER_FAULT_SOURCE_COMP0_SENSE_HIGH                                \
        (GPTIMER_FSCTL_FAC0EN_ENABLE | (GPTIMER_FCTL_FSENAC0_HIGHACTIVE << 16))

/*!
* @brief Disables COMP1 as fault source
*/
#define DL_TIMER_FAULT_SOURCE_COMP1_DISABLE                                   \
        (GPTIMER_FSCTL_FAC1EN_DISABLE | (GPTIMER_FCTL_FSENAC1_LOWCTIVE << 16))

/*!
* @brief Enables COMP1 as fault source and fault input is active low
*/
#define DL_TIMER_FAULT_SOURCE_COMP1_SENSE_LOW                                 \
        (GPTIMER_FSCTL_FAC1EN_ENABLE | (GPTIMER_FCTL_FSENAC1_LOWCTIVE << 16))

/*!
* @brief Enables COMP1 as fault source and fault input is active high
*/
#define DL_TIMER_FAULT_SOURCE_COMP1_SENSE_HIGH                                \
        (GPTIMER_FSCTL_FAC1EN_ENABLE | (GPTIMER_FCTL_FSENAC1_HIGHACTIVE << 16))

/*!
* @brief Disables COMP2 as fault source
*/
#define DL_TIMER_FAULT_SOURCE_COMP2_DISABLE                                   \
        (GPTIMER_FSCTL_FAC2EN_DISABLE | (GPTIMER_FCTL_FSENAC2_LOWCTIVE << 16))

/*!
* @brief Enables COMP2 as fault source and fault input is active low
*/
#define DL_TIMER_FAULT_SOURCE_COMP2_SENSE_LOW                                 \
        (GPTIMER_FSCTL_FAC2EN_ENABLE | (GPTIMER_FCTL_FSENAC2_LOWCTIVE << 16))

/*!
* @brief Enables COMP2 as fault source and fault input is active high
*/
#define DL_TIMER_FAULT_SOURCE_COMP2_SENSE_HIGH                                \
        (GPTIMER_FSCTL_FAC2EN_ENABLE | (GPTIMER_FCTL_FSENAC2_HIGHACTIVE << 16))

/*!
* @brief Disables external fault pin 0 as fault source
*/
#define DL_TIMER_FAULT_SOURCE_EXTERNAL_0_DISABLE                              \
        (GPTIMER_FSCTL_FEX0EN_DISABLE | (GPTIMER_FCTL_FSENEXT0_LOWCTIVE << 16))

/*!
* @brief Enables external fault pin 0 as fault source and fault input is active
*        low
*/
#define DL_TIMER_FAULT_SOURCE_EXTERNAL_0_SENSE_LOW                            \
        (GPTIMER_FSCTL_FEX0EN_ENABLE | (GPTIMER_FCTL_FSENEXT0_LOWCTIVE << 16))

/*!
* @brief Enables external fault pin 0 as fault source and fault input is active
*        high
*/
#define DL_TIMER_FAULT_SOURCE_EXTERNAL_0_SENSE_HIGH                           \
        (GPTIMER_FSCTL_FEX0EN_ENABLE | (GPTIMER_FCTL_FSENEXT0_HIGHACTIVE << 16))

/*!
* @brief Disables external fault pin 1 as fault source
*/
#define DL_TIMER_FAULT_SOURCE_EXTERNAL_1_DISABLE                              \
        (GPTIMER_FSCTL_FEX1EN_DISABLE | (GPTIMER_FCTL_FSENEXT1_LOWCTIVE << 16))

/*!
* @brief Enables external fault pin 1 as fault source and fault input is active
*        low
*/
#define DL_TIMER_FAULT_SOURCE_EXTERNAL_1_SENSE_LOW                            \
        (GPTIMER_FSCTL_FEX1EN_ENABLE | (GPTIMER_FCTL_FSENEXT1_LOWCTIVE << 16))

/*!
* @brief Enables external fault pin 1 as fault source and fault input is active
*        high
*/
#define DL_TIMER_FAULT_SOURCE_EXTERNAL_1_SENSE_HIGH                           \
        (GPTIMER_FSCTL_FEX1EN_ENABLE | (GPTIMER_FCTL_FSENEXT1_HIGHACTIVE << 16))

/*!
* @brief Disables external fault pin 2 as fault source
*/
#define DL_TIMER_FAULT_SOURCE_EXTERNAL_2_DISABLE                              \
        (GPTIMER_FSCTL_FEX2EN_DISABLE | (GPTIMER_FCTL_FSENEXT2_LOWCTIVE << 16))

/*!
* @brief Enables external fault pin 2 as fault source and fault input is active
*        low
*/
#define DL_TIMER_FAULT_SOURCE_EXTERNAL_2_SENSE_LOW                            \
        (GPTIMER_FSCTL_FEX2EN_ENABLE | (GPTIMER_FCTL_FSENEXT2_LOWCTIVE << 16))

/*!
* @brief Enables external fault pin 2 as fault source and fault input is active
*        high
*/
#define DL_TIMER_FAULT_SOURCE_EXTERNAL_2_SENSE_HIGH                           \
        (GPTIMER_FSCTL_FEX2EN_ENABLE | (GPTIMER_FCTL_FSENEXT2_HIGHACTIVE << 16))

/** @}*/


/** @addtogroup DL_TIMER_FAULT_CONFIG_TFIM
 *  @{
 */

/*!
 * @brief Selected trigger doesn't participate as a fault input.
 */
#define DL_TIMER_FAULT_CONFIG_TFIM_DISABLED         (GPTIMER_FCTL_TFIM_DISABLED)

/*!
 * @brief Selected trigger participates as a fault input.
 */
#define DL_TIMER_FAULT_CONFIG_TFIM_ENABLED           (GPTIMER_FCTL_TFIM_ENABLED)

/** @}*/


/** @addtogroup DL_TIMER_FAULT_CONFIG_FL
 *  @{
 */
/*!
 * @brief Overall fault condition is not dependent on the F bit in RIS
 */
#define DL_TIMER_FAULT_CONFIG_FL_NO_LATCH  (GPTIMER_FCTL_FL_NO_LATCH)

/*!
 * @brief Overall fault condition is dependent on the F bit in RIS
 */
#define DL_TIMER_FAULT_CONFIG_FL_LATCH_SW_CLR    (GPTIMER_FCTL_FL_LATCH_SW_CLR)

/*!
 * @brief Fault condition is latched. Fault condition is cleared on a zero event
 *        if the fault input is 0
 */
#define DL_TIMER_FAULT_CONFIG_FL_LATCH_Z_CLR   (GPTIMER_FCTL_FL_LATCH_Z_CLR)

/*!
 * @brief Fault condition is latched. Fault condition is cleared on a load event
 *        if the fault input is 0
 */
#define DL_TIMER_FAULT_CONFIG_FL_LATCH_LD_CLR    (GPTIMER_FCTL_FL_LATCH_LD_CLR)

/** @}*/

/** @addtogroup DL_TIMER_FAULT_CONFIG_FI
 *  @{
 */

/*!
 * @brief Fault condition is independent on all selected fault sources
 *        coming into the Timer
 */
#define DL_TIMER_FAULT_CONFIG_FI_INDEPENDENT  (GPTIMER_FCTL_FI_INDEPENDENT)

/*!
 * @brief Fault condition is dependent on all selected fault sources
 *        coming into the Timer
 */
#define DL_TIMER_FAULT_CONFIG_FI_DEPENDENT    (GPTIMER_FCTL_FI_DEPENDENT)

/** @}*/

/** @addtogroup DL_TIMER_FAULT_CONFIG_FIEN
 *  @{
 */

/*!
 * @brief Disables the input for fault detection from the device pin.
 */
#define DL_TIMER_FAULT_CONFIG_FIEN_DISABLED  (GPTIMER_FCTL_FIEN_DISABLED)

/*!
 * @brief Enables the input for fault detection from the device pin.
 */
#define DL_TIMER_FAULT_CONFIG_FIEN_ENABLED   (GPTIMER_FCTL_FIEN_ENABLED)

/** @}*/

/** @addtogroup DL_TIMER_FAULT_FILT
 *  @{
 */
/*!
 * @brief Input bypasses filter
 */
#define DL_TIMER_FAULT_FILTER_BYPASS     (GPTIMER_FIFCTL_FILTEN_BYPASS)

/*!
 * @brief Input filter is enabled
 */
#define DL_TIMER_FAULT_FILTER_FILTERED   (GPTIMER_FIFCTL_FILTEN_FILTERED)

/** @}*/

/** @addtogroup DL_TIMER_FAULT_FILTER_CPV
 *  @{
 */

/*!
 * @brief Input filter uses a stricter consecutive period count
 */
#define DL_TIMER_FAULT_FILTER_CPV_CONSEC_PER  (GPTIMER_FIFCTL_CPV_CONSEC_PER)

/*!
 * @brief Input filter uses majority voting
 */
#define DL_TIMER_FAULT_FILTER_CPV_VOTING      (GPTIMER_FIFCTL_CPV_VOTING)


/** @}*/

/** @addtogroup DL_TIMER_FAULT_FILTER_FP
 *  @{
 */
/*!
 * @brief Sample period for the input filter is set to 3 TIMCLK
 */
#define DL_TIMER_FAULT_FILTER_FP_PER_3   (GPTIMER_FIFCTL_FP_PER_3)

/*!
 * @brief Sample period for the input filter is set to 5 TIMCLK
 */
#define DL_TIMER_FAULT_FILTER_FP_PER_5   (GPTIMER_FIFCTL_FP_PER_5)

/*!
 * @brief Sample period for the input filter is set to 8 TIMCLK
 */
#define DL_TIMER_FAULT_FILTER_FP_PER_8   (GPTIMER_FIFCTL_FP_PER_8)

/** @}*/

/** @addtogroup DL_TIMER_CC_INPUT_FILT_CPV
 *  @{
 */

/*!
 * @brief Input filter uses a stricter consecutive period count
 */
#define DL_TIMER_CC_INPUT_FILT_CPV_CONSEC_PER (GPTIMER_IFCTL_01_CPV_CONSECUTIVE)

/*!
 * @brief Input filter uses majority voting
 */
#define DL_TIMER_CC_INPUT_FILT_CPV_VOTING          (GPTIMER_IFCTL_01_CPV_VOTING)


/** @}*/

/** @addtogroup DL_TIMER_CC_INPUT_FILT_FP
 *  @{
 */
/*!
 * @brief Sample period for the input filter is set to 3 TIMCLK
 */
#define DL_TIMER_CC_INPUT_FILT_FP_PER_3                 (GPTIMER_IFCTL_01_FP__3)

/*!
 * @brief Sample period for the input filter is set to 5 TIMCLK
 */
#define DL_TIMER_CC_INPUT_FILT_FP_PER_5                 (GPTIMER_IFCTL_01_FP__5)

/*!
 * @brief Sample period for the input filter is set to 8 TIMCLK
 */
#define DL_TIMER_CC_INPUT_FILT_FP_PER_8                 (GPTIMER_IFCTL_01_FP__8)

/** @}*/

/** @addtogroup DL_TIMER_INTERRUPT
 *  @{
 */

/*!
 * @brief Repeat Counter interrupt
 */
#define DL_TIMER_INTERRUPT_REPC_EVENT           (GPTIMER_CPU_INT_IMASK_REPC_SET)

/*!
 * @brief Fault interrupt
 */
#define DL_TIMER_INTERRUPT_FAULT_EVENT             (GPTIMER_CPU_INT_IMASK_F_SET)

/*!
 * @brief Timer zero interrupt
 */
#define DL_TIMER_INTERRUPT_ZERO_EVENT                      (GPTIMER_CPU_INT_IMASK_Z_SET)

/*!
* @brief Timer load interrupt
*/
#define DL_TIMER_INTERRUPT_LOAD_EVENT                      (GPTIMER_CPU_INT_IMASK_L_SET)

/*!
* @brief Timer capture for compare 0 down interrupt
*/
#define DL_TIMER_INTERRUPT_CC0_DN_EVENT                 (GPTIMER_CPU_INT_IMASK_CCD0_SET)

/*!
* @brief Timer capture for compare 1 down interrupt
*/
#define DL_TIMER_INTERRUPT_CC1_DN_EVENT                 (GPTIMER_CPU_INT_IMASK_CCD1_SET)

/*!
* @brief Timer capture for compare 2 down interrupt
*/
#define DL_TIMER_INTERRUPT_CC2_DN_EVENT                 (GPTIMER_CPU_INT_IMASK_CCD2_SET)

/*!
* @brief Timer capture for compare 3 down interrupt
*/
#define DL_TIMER_INTERRUPT_CC3_DN_EVENT                 (GPTIMER_CPU_INT_IMASK_CCD3_SET)

/*!
* @brief Timer capture for compare 4 down interrupt
*/
#define DL_TIMER_INTERRUPT_CC4_DN_EVENT                 (GPTIMER_CPU_INT_IMASK_CCD4_SET)

/*!
* @brief Timer capture for compare 5 down interrupt
*/
#define DL_TIMER_INTERRUPT_CC5_DN_EVENT                 (GPTIMER_CPU_INT_IMASK_CCD5_SET)

/*!
* @brief Timer capture for compare 0 up interrupt
*/
#define DL_TIMER_INTERRUPT_CC0_UP_EVENT                 (GPTIMER_CPU_INT_IMASK_CCU0_SET)

/*!
* @brief Timer capture for compare 1 up interrupt
*/
#define DL_TIMER_INTERRUPT_CC1_UP_EVENT                 (GPTIMER_CPU_INT_IMASK_CCU1_SET)

/*!
* @brief Timer capture for compare 2 up interrupt
*/
#define DL_TIMER_INTERRUPT_CC2_UP_EVENT                 (GPTIMER_CPU_INT_IMASK_CCU2_SET)

/*!
* @brief Timer capture for compare 3 up interrupt
*/
#define DL_TIMER_INTERRUPT_CC3_UP_EVENT                 (GPTIMER_CPU_INT_IMASK_CCU3_SET)

/*!
* @brief Timer capture for compare 4 up interrupt
*/
#define DL_TIMER_INTERRUPT_CC4_UP_EVENT                 (GPTIMER_CPU_INT_IMASK_CCU4_SET)

/*!
* @brief Timer capture for compare 5 up interrupt
*/
#define DL_TIMER_INTERRUPT_CC5_UP_EVENT                 (GPTIMER_CPU_INT_IMASK_CCU5_SET)

/*!
* @brief Timer over flow interrupt
*/
#define DL_TIMER_INTERRUPT_OVERFLOW_EVENT                (GPTIMER_CPU_INT_IMASK_TOV_SET)

/*!
* @brief Timer QEI mode direction change event
*/
#define DL_TIMER_INTERRUPT_DC_EVENT                       (GPTIMER_CPU_INT_IMASK_DC_SET)


/*!
* @brief Timer QEI mode transition error
*/
#define DL_TIMER_INTERRUPT_QEIERR_EVENT               (GPTIMER_CPU_INT_IMASK_QEIERR_SET)


/** @}*/

/** @addtogroup DL_TIMER_EVENT
 *  @{
 */

/*!
 * @brief Repeat Counter event
 */
#define DL_TIMER_EVENT_REPC_EVENT            (GPTIMER_GEN_EVENT0_IMASK_REPC_SET)

/*!
 * @brief Fault event
 */
#define DL_TIMER_EVENT_FAULT_EVENT              (GPTIMER_GEN_EVENT0_IMASK_F_SET)

/*!
 * @brief Timer zero event
 */
#define DL_TIMER_EVENT_ZERO_EVENT                          (GPTIMER_GEN_EVENT0_IMASK_Z_SET)

/*!
* @brief Timer load event
*/
#define DL_TIMER_EVENT_LOAD_EVENT                          (GPTIMER_GEN_EVENT0_IMASK_L_SET)

/*!
* @brief Timer capture for compare 0 down event
*/
#define DL_TIMER_EVENT_CC0_DN_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCD0_SET)

/*!
* @brief Timer capture for compare 1 down event
*/
#define DL_TIMER_EVENT_CC1_DN_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCD1_SET)

/*!
* @brief Timer capture for compare 2 down interrupt
*/
#define DL_TIMER_EVENT_CC2_DN_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCD2_SET)

/*!
* @brief Timer capture for compare 3 down event
*/
#define DL_TIMER_EVENT_CC3_DN_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCD3_SET)

/*!
* @brief Timer capture for compare 4 down event
*/
#define DL_TIMER_EVENT_CC4_DN_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCD4_SET)

/*!
* @brief Timer capture for compare 5 down event
*/
#define DL_TIMER_EVENT_CC5_DN_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCD5_SET)

/*!
* @brief Timer capture for compare 0 up event
*/
#define DL_TIMER_EVENT_CC0_UP_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCU0_SET)

/*!
* @brief Timer capture for compare 1 up event
*/
#define DL_TIMER_EVENT_CC1_UP_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCU1_SET)

/*!
* @brief Timer capture for compare 2 up event
*/
#define DL_TIMER_EVENT_CC2_UP_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCU2_SET)

/*!
* @brief Timer capture for compare 3 up event
*/
#define DL_TIMER_EVENT_CC3_UP_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCU3_SET)

/*!
* @brief Timer capture for compare 4 up event
*/
#define DL_TIMER_EVENT_CC4_UP_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCU4_SET)

/*!
event
*/
#define DL_TIMER_EVENT_CC5_UP_EVENT                     (GPTIMER_GEN_EVENT0_IMASK_CCU5_SET)

/*!
* @brief Timer over flow event
*/
#define DL_TIMER_EVENT_OVERFLOW_EVENT                    (GPTIMER_GEN_EVENT0_IMASK_TOV_SET)

/*!
* @brief Timer qei mode direction change event
*/
#define DL_TIMER_EVENT_DC_EVENT                           (GPTIMER_GEN_EVENT0_IMASK_DC_SET)


/*!
* @brief Timer qei mode transition error
*/
#define DL_TIMER_EVENT_QEIERR_EVENT                   (GPTIMER_GEN_EVENT0_IMASK_QEIERR_SET)


/** @}*/

/** @addtogroup DL_TIMER_CCP0_DIS_OUT_ADV
 *  @{
 */

/**
 *  @brief CCP0 output is forced low when timer is disabled
 */
#define DL_TIMER_CCP0_DIS_OUT_ADV_FORCE_LOW (GPTIMER_ODIS_C0CCP0_CCP_OUTPUT_LOW)

/**
 *  @brief CCP0 output is set by the OCTL when timer is disabled
 */
#define DL_TIMER_CCP0_DIS_OUT_ADV_SET_BY_OCTL \
                                           (GPTIMER_ODIS_C0CCP0_CCP_OUTPUT_OCTL)
/** @}*/

/** @addtogroup DL_TIMER_CCP1_DIS_OUT_ADV
 *  @{
 */

/**
 *  @brief CCP1 output is forced low when timer is disabled
 */
#define DL_TIMER_CCP1_DIS_OUT_ADV_FORCE_LOW (GPTIMER_ODIS_C0CCP1_CCP_OUTPUT_LOW)

/**
 *  @brief CCP1 output is set by the OCTL when timer is disabled
 */
#define DL_TIMER_CCP1_DIS_OUT_ADV_SET_BY_OCTL \
                                           (GPTIMER_ODIS_C0CCP1_CCP_OUTPUT_OCTL)
/** @}*/

/** @addtogroup DL_TIMER_CCP2_DIS_OUT_ADV
 *  @{
 */
/**
 *  @brief CCP2 output is forced low when timer is disabled
 */
#define DL_TIMER_CCP2_DIS_OUT_ADV_FORCE_LOW (GPTIMER_ODIS_C0CCP2_CCP_OUTPUT_LOW)

/**
 *  @brief CCP2 output is set by the OCTL when timer is disabled
 */
#define DL_TIMER_CCP2_DIS_OUT_ADV_SET_BY_OCTL \
                                           (GPTIMER_ODIS_C0CCP2_CCP_OUTPUT_OCTL)
/** @}*/

/** @addtogroup DL_TIMER_CCP3_DIS_OUT_ADV
 *  @{
 */

/**
 *  @brief CCP3 output is forced low when timer is disabled
 */
#define DL_TIMER_CCP3_DIS_OUT_ADV_FORCE_LOW (GPTIMER_ODIS_C0CCP3_CCP_OUTPUT_LOW)

/**
 *  @brief CCP3 output is set by the OCTL when timer is disabled
 */
#define DL_TIMER_CCP3_DIS_OUT_ADV_SET_BY_OCTL \
                                           (GPTIMER_ODIS_C0CCP3_CCP_OUTPUT_OCTL)
/** @}*/

/* clang-format on */

/*! @enum DL_TIMER_CLOCK */
typedef enum {
    /*! Selects BUSCLK as clock source */
    DL_TIMER_CLOCK_BUSCLK = GPTIMER_CLKSEL_BUSCLK_SEL_ENABLE,
    /*! Selects 2X BUSCLK as clock source */
    DL_TIMER_CLOCK_2X_BUSCLK = GPTIMER_CLKSEL_BUS2XCLK_SEL_ENABLE,
    /*! Selects MFCLK as clock source */
    DL_TIMER_CLOCK_MFCLK = GPTIMER_CLKSEL_MFCLK_SEL_ENABLE,
    /*! Selects LFCLK as clock source */
    DL_TIMER_CLOCK_LFCLK = GPTIMER_CLKSEL_LFCLK_SEL_ENABLE,
    /*! Disables selected clock source */
    DL_TIMER_CLOCK_DISABLE = GPTIMER_CLKSEL_LFCLK_SEL_DISABLE,
} DL_TIMER_CLOCK;

/*! @enum  DL_TIMER_CLOCK_DIVIDE */
typedef enum {
    /*! Timer source clock divide ratio set to 1 */
    DL_TIMER_CLOCK_DIVIDE_1 = GPTIMER_CLKDIV_RATIO_DIV_BY_1,
    /*! Timer source clock divide ratio set to 2 */
    DL_TIMER_CLOCK_DIVIDE_2 = GPTIMER_CLKDIV_RATIO_DIV_BY_2,
    /*! Timer source clock divide ratio set to 3 */
    DL_TIMER_CLOCK_DIVIDE_3 = GPTIMER_CLKDIV_RATIO_DIV_BY_3,
    /*! Timer source clock divide ratio set to 4 */
    DL_TIMER_CLOCK_DIVIDE_4 = GPTIMER_CLKDIV_RATIO_DIV_BY_4,
    /*! Timer source clock divide ratio set to 5 */
    DL_TIMER_CLOCK_DIVIDE_5 = GPTIMER_CLKDIV_RATIO_DIV_BY_5,
    /*! Timer source clock divide ratio set to 6 */
    DL_TIMER_CLOCK_DIVIDE_6 = GPTIMER_CLKDIV_RATIO_DIV_BY_6,
    /*! Timer source clock divide ratio set to 7 */
    DL_TIMER_CLOCK_DIVIDE_7 = GPTIMER_CLKDIV_RATIO_DIV_BY_7,
    /*! Timer source clock divide ratio set to 8 */
    DL_TIMER_CLOCK_DIVIDE_8 = GPTIMER_CLKDIV_RATIO_DIV_BY_8,
} DL_TIMER_CLOCK_DIVIDE;

/*! @enum  DL_TIMER_CCP_DIS_OUT */
typedef enum {
    /*! CCP output source is disabled and driven low before conditional
     * inversion */
    DL_TIMER_CCP_DIS_OUT_LOW = GPTIMER_ODIS_C0CCP0_CCP_OUTPUT_LOW,
    /*! CCP output source is not disabled */
    DL_TIMER_CCP_DIS_OUT_SET_BY_OCTL = GPTIMER_ODIS_C0CCP0_CCP_OUTPUT_OCTL,
} DL_TIMER_CCP_DIS_OUT;

/*! @enum  DL_TIMER_CC_INDEX */
typedef enum {
    /*! Index associated to Capture Compare 0 */
    DL_TIMER_CC_0_INDEX = 0,
    /*! Index associated to Capture Compare 1 */
    DL_TIMER_CC_1_INDEX = 1,
    /*! Index associated to Capture Compare 2 */
    DL_TIMER_CC_2_INDEX = 2,
    /*! Index associated to Capture Compare 3 */
    DL_TIMER_CC_3_INDEX = 3,

    /*! Index associated to Capture Compare 4 */
    DL_TIMER_CC_4_INDEX = 4,
    /*! Index associated to Capture Compare 5 */
    DL_TIMER_CC_5_INDEX = 5,

} DL_TIMER_CC_INDEX;

/*! @enum  DL_TIMER_EXT_TRIG_SEL*/
typedef enum {
    /*! External trigger 0 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_0 = GPTIMER_TSEL_ETSEL_TRIG0,
    /*! External trigger 1 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_1 = GPTIMER_TSEL_ETSEL_TRIG1,
    /*! External trigger 2 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_2 = GPTIMER_TSEL_ETSEL_TRIG2,
    /*! External trigger 3 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_3 = GPTIMER_TSEL_ETSEL_TRIG3,
    /*! External trigger 4 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_4 = GPTIMER_TSEL_ETSEL_TRIG4,
    /*! External trigger 5 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_5 = GPTIMER_TSEL_ETSEL_TRIG5,
    /*! External trigger 6 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_6 = GPTIMER_TSEL_ETSEL_TRIG6,
    /*! External trigger 7 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_7 = GPTIMER_TSEL_ETSEL_TRIG7,
    /*! External trigger 8 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_8 = GPTIMER_TSEL_ETSEL_TRIG8,
    /*! External trigger 9 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_9 = GPTIMER_TSEL_ETSEL_TRIG9,
    /*! External trigger 10 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_10 = GPTIMER_TSEL_ETSEL_TRIG10,
    /*! External trigger 11 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_11 = GPTIMER_TSEL_ETSEL_TRIG11,
    /*! External trigger 12 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_12 = GPTIMER_TSEL_ETSEL_TRIG12,
    /*! External trigger 13 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_13 = GPTIMER_TSEL_ETSEL_TRIG13,
    /*! External trigger 14 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_14 = GPTIMER_TSEL_ETSEL_TRIG14,
    /*! External trigger 15 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_15 = GPTIMER_TSEL_ETSEL_TRIG15,
    /*! External event subscriber 0 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_SUB_0 = GPTIMER_TSEL_ETSEL_TRIG_SUB0,
    /*! External event subscriber 1 */
    DL_TIMER_EXT_TRIG_SEL_TRIG_SUB_1 = GPTIMER_TSEL_ETSEL_TRIG_SUB1,
} DL_TIMER_EXT_TRIG_SEL;

/*! @enum  DL_TIMER_TIMER_MODE */
typedef enum {
    /*! Configures Timer in one shot mode in DOWN COUNTING mode */
    DL_TIMER_TIMER_MODE_ONE_SHOT =
        (GPTIMER_CTRCTL_CM_DOWN | GPTIMER_CTRCTL_REPEAT_REPEAT_0),
    /*! Configures Timer in periodic mode in DOWN COUNTING mode */
    DL_TIMER_TIMER_MODE_PERIODIC =
        (GPTIMER_CTRCTL_CM_DOWN | GPTIMER_CTRCTL_REPEAT_REPEAT_1),
    /*! Configures Timer in one shot mode in UP COUNTING mode */
    DL_TIMER_TIMER_MODE_ONE_SHOT_UP =
        (GPTIMER_CTRCTL_CM_UP | GPTIMER_CTRCTL_REPEAT_REPEAT_0),
    /*! Configures Timer in periodic mode in UP COUNTING mode */
    DL_TIMER_TIMER_MODE_PERIODIC_UP =
        (GPTIMER_CTRCTL_CM_UP | GPTIMER_CTRCTL_REPEAT_REPEAT_1),
    /*! Configures Timer in one shot mode in UP/DOWN COUNTING mode */
    DL_TIMER_TIMER_MODE_ONE_SHOT_UP_DOWN =
        (GPTIMER_CTRCTL_CM_UP_DOWN | GPTIMER_CTRCTL_REPEAT_REPEAT_0),
    /*! Configures Timer in periodic mode in UP/DOWN COUNTING mode */
    DL_TIMER_TIMER_MODE_PERIODIC_UP_DOWN =
        (GPTIMER_CTRCTL_CM_UP_DOWN | GPTIMER_CTRCTL_REPEAT_REPEAT_1),
} DL_TIMER_TIMER_MODE;

/*! @enum  DL_TIMER_CAPTURE_MODE */
typedef enum {
    /*! Configures Timer in edge time capture mode and timer is configured
     *! in down counting mode */
    DL_TIMER_CAPTURE_MODE_EDGE_TIME,
    /*! Configures Timer in period capture mode and timer is configured
     *! in down counting mode */
    DL_TIMER_CAPTURE_MODE_PERIOD_CAPTURE,
    /*! Configures Timer in pulse width capture mode and timer is configured
     *! in down counting mode */
    DL_TIMER_CAPTURE_MODE_PULSE_WIDTH,
    /*! Configures Timer in edge time capture mode and timer is configured
     *! in up counting mode */
    DL_TIMER_CAPTURE_MODE_EDGE_TIME_UP,
    /*! Configures Timer in period capture mode and timer is configured
     *! in up counting mode */
    DL_TIMER_CAPTURE_MODE_PERIOD_CAPTURE_UP,
    /*! Configures Timer in pulse width capture mode and timer is configured
     *! in up counting mode */
    DL_TIMER_CAPTURE_MODE_PULSE_WIDTH_UP,
} DL_TIMER_CAPTURE_MODE;

/*! @enum  DL_TIMER_CAPTURE_COMBINED_MODE */
typedef enum {
    /*! Configures Timer in pulse width and period mode and timer is configured
     *! in down counting mode */
    DL_TIMER_CAPTURE_COMBINED_MODE_PULSE_WIDTH_AND_PERIOD,
    /*! Configures Timer in pulse width and period mode and timer is configured
     *! in up counting mode */
    DL_TIMER_CAPTURE_COMBINED_MODE_PULSE_WIDTH_AND_PERIOD_UP,
} DL_TIMER_CAPTURE_COMBINED_MODE;

/*! @enum  DL_TIMER_COMPARE_MODE */
typedef enum {
    /*! Configures Timer in edge count mode and timer is configured
     *! in down counting mode */
    DL_TIMER_COMPARE_MODE_EDGE_COUNT,
    /*! Configures Timer in edge count mode and timer is configured
     *! in up counting mode */
    DL_TIMER_COMPARE_MODE_EDGE_COUNT_UP,
    /*! Configures Timer in edge count mode and timer is configured
     *! in up/down counting mode */
    DL_TIMER_COMPARE_MODE_EDGE_COUNT_UP_DOWN,
} DL_TIMER_COMPARE_MODE;

/*! @enum  DL_TIMER_COUNT_MODE */
typedef enum {
    /*! Timer counts in DOWN mode */
    DL_TIMER_COUNT_MODE_DOWN = GPTIMER_CTRCTL_CM_DOWN,
    /*! Timer counts in UP/DOWN mode */
    DL_TIMER_COUNT_MODE_UP_DOWN = GPTIMER_CTRCTL_CM_UP_DOWN,
    /*! Timer counts in UP mode */
    DL_TIMER_COUNT_MODE_UP = GPTIMER_CTRCTL_CM_UP,
} DL_TIMER_COUNT_MODE;

/*! @enum  DL_TIMER */
typedef enum {
    /*! Start running timer */
    DL_TIMER_START = GPTIMER_CTRCTL_EN_ENABLED,
    /*! Don't start running timer */
    DL_TIMER_STOP = GPTIMER_CTRCTL_EN_DISABLED,
} DL_TIMER;

/*! @enum DL_TIMER_INTERM_INT */
typedef enum {

    /*! Enables intermediate interrupt in timer mode */
    DL_TIMER_INTERM_INT_ENABLED = GPTIMER_CCCTL_01_COC_COMPARE,
    /*! Disabled intermediate interrupt in timer mode */
    DL_TIMER_INTERM_INT_DISABLED = GPTIMER_CCCTL_01_COC_CAPTURE,

} DL_TIMER_INTERM_INT;

/*! @enum  DL_TIMER_CAPTURE_EDGE_DETECTION_MODE */
typedef enum {
    /*! Selects rising edge detection */
    DL_TIMER_CAPTURE_EDGE_DETECTION_MODE_RISING =
        GPTIMER_CCCTL_01_CCOND_CC_TRIG_RISE,
    /*! Selects falling edge detection */
    DL_TIMER_CAPTURE_EDGE_DETECTION_MODE_FALLING =
        GPTIMER_CCCTL_01_CCOND_CC_TRIG_FALL,
} DL_TIMER_CAPTURE_EDGE_DETECTION_MODE;

/*! @enum  DL_TIMER_COMPARE_EDGE_DETECTION_MODE */
typedef enum {
    /*! Selects rising edge detection */
    DL_TIMER_COMPARE_EDGE_DETECTION_MODE_RISING =
        GPTIMER_CCCTL_01_ACOND_CC_TRIG_RISE,
    /*! Selects falling edge detection */
    DL_TIMER_COMPARE_EDGE_DETECTION_MODE_FALLING =
        GPTIMER_CCCTL_01_ACOND_CC_TRIG_FALL,
    /*! Selects both (rising and falling) edge detection */
    DL_TIMER_COMPARE_EDGE_DETECTION_MODE_EDGE =
        GPTIMER_CCCTL_01_ACOND_CC_TRIG_EDGE,
} DL_TIMER_COMPARE_EDGE_DETECTION_MODE;

/*! @enum DL_TIMER_PWM_MODE */
typedef enum {
    /*! Configured Timer for PWM in edge align mode */
    DL_TIMER_PWM_MODE_EDGE_ALIGN = GPTIMER_CTRCTL_CM_DOWN,
    /*! Configured Timer for PWM in edge align mode */
    DL_TIMER_PWM_MODE_EDGE_ALIGN_UP = GPTIMER_CTRCTL_CM_UP,
    /*! Configured Timer for PWM in center align mode */
    DL_TIMER_PWM_MODE_CENTER_ALIGN = GPTIMER_CTRCTL_CM_UP_DOWN,
} DL_TIMER_PWM_MODE;

/*! @enum DL_TIMER_DEAD_BAND_MODE */
typedef enum {
    /*! Selects dead band insertion mode 0 */
    DL_TIMER_DEAD_BAND_MODE_0 = GPTIMER_DBCTL_M1_ENABLE_DISABLED,
    /*! Selects dead band insertion mode 1 */
    DL_TIMER_DEAD_BAND_MODE_1 = GPTIMER_DBCTL_M1_ENABLE_ENABLED,
} DL_TIMER_DEAD_BAND_MODE;

/*! @enum DL_TIMER_FAULT_ENTRY_CCP */

typedef enum {
    /*! The CCP output value is not affected by the event */
    DL_TIMER_FAULT_ENTRY_CCP_DISABLED = GPTIMER_CCACT_01_FENACT_DISABLED,
    /*! The CCP output value is set high */
    DL_TIMER_FAULT_ENTRY_CCP_HIGH = GPTIMER_CCACT_01_FENACT_CCP_HIGH,
    /*! The CCP output value is set to low  */
    DL_TIMER_FAULT_ENTRY_CCP_LOW = GPTIMER_CCACT_01_FENACT_CCP_LOW,
    /*! The CCP output value is toggled*/
    DL_TIMER_FAULT_ENTRY_CCP_TOGGLE = GPTIMER_CCACT_01_FENACT_CCP_TOGGLE,

    /*! The CCP output value is High-Z*/
    DL_TIMER_FAULT_ENTRY_CCP_HIGHZ = GPTIMER_CCACT_01_FENACT_CCP_HIGHZ,

} DL_TIMER_FAULT_ENTRY_CCP;

/*! @enum DL_TIMER_FAULT_EXIT_CCP */
typedef enum {
    /*! The CCP output value is not affected by the event */
    DL_TIMER_FAULT_EXIT_CCP_DISABLED = GPTIMER_CCACT_01_FEXACT_DISABLED,
    /*! The CCP output value is set high */
    DL_TIMER_FAULT_EXIT_CCP_HIGH = GPTIMER_CCACT_01_FEXACT_CCP_HIGH,
    /*! The CCP output value is set to low  */
    DL_TIMER_FAULT_EXIT_CCP_LOW = GPTIMER_CCACT_01_FEXACT_CCP_LOW,
    /*! The CCP output value is toggled*/
    DL_TIMER_FAULT_EXIT_CCP_TOGGLE = GPTIMER_CCACT_01_FEXACT_CCP_TOGGLE,

    /*! The CCP output value is High-Z*/
    DL_TIMER_FAULT_EXIT_CCP_HIGHZ = GPTIMER_CCACT_01_FEXACT_CCP_HIGHZ,

} DL_TIMER_FAULT_EXIT_CCP;

/*! @enum DL_TIMER_FAULT_EXIT_CTR */
typedef enum {
    /*! Timer resumes counting upon release of fault condition */
    DL_TIMER_FAULT_EXIT_CTR_RESUME = GPTIMER_CTRCTL_FRB_RESUME,
    /*! Timer resumes operation based on counter value after enable
     *  configuration */
    DL_TIMER_FAULT_EXIT_CTR_CVAE_ACTION = GPTIMER_CTRCTL_FRB_CVAE_ACTION,
} DL_TIMER_FAULT_EXIT_CTR;

/*! @enum DL_TIMER_FAULT_ENTRY_CTR */
typedef enum {
    /*! Timer counter continues running during fault */
    DL_TIMER_FAULT_ENTRY_CTR_CONT_COUNT = GPTIMER_CTRCTL_FB_CONT_COUNT,
    /*! Timer counter continues is suspended during fault */
    DL_TIMER_FAULT_ENTRY_CTR_SUSP_COUNT = GPTIMER_CTRCTL_FB_SUSP_COUNT,
} DL_TIMER_FAULT_ENTRY_CTR;

/*! @enum DL_TIMER_CROSS_TRIG_SRC */
typedef enum {
    /*! Use FSUB0 for Event manager */
    DL_TIMER_CROSS_TRIG_SRC_FSUB0 = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_FSUB0,
    /*! Use FSUB1 for Event manager */
    DL_TIMER_CROSS_TRIG_SRC_FSUB1 = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_FSUB1,
    /*! Use Zero event  as cross trigger source */
    DL_TIMER_CROSS_TRIG_SRC_ZERO = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_Z,
    /*! Use Load event  as cross trigger source */
    DL_TIMER_CROSS_TRIG_SRC_LOAD = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_L,
    /*! Use Capture Compare Down 0 event  as cross trigger source. */
    DL_TIMER_CROSS_TRIG_SRC_CCD0 = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCD0,
    /*! Use Capture Compare Down 1 event  as cross trigger source. */
    DL_TIMER_CROSS_TRIG_SRC_CCD1 = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCD1,
    /*! Use Capture Compare Down 2 event  as cross trigger source. */
    DL_TIMER_CROSS_TRIG_SRC_CCD2 = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCD2,
    /*! Use Capture Compare Down 3 event  as cross trigger source. */
    DL_TIMER_CROSS_TRIG_SRC_CCD3 = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCD3,
    /*! Use Capture Compare Up 0 event  as cross trigger source. */
    DL_TIMER_CROSS_TRIG_SRC_CCU0 = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCU0,
    /*! Use Capture Compare Up 1 event  as cross trigger source. */
    DL_TIMER_CROSS_TRIG_SRC_CCU1 = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCU1,
    /*! Use Capture Compare Up 2 event  as cross trigger source. */
    DL_TIMER_CROSS_TRIG_SRC_CCU2 = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCU2,
    /*! Use Capture Compare Up 3 event  as cross trigger source. */
    DL_TIMER_CROSS_TRIG_SRC_CCU3 = GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCU3,

} DL_TIMER_CROSS_TRIG_SRC;

/*! @enum DL_TIMER_CROSS_TRIGGER_INPUT */
typedef enum {
    /*! Cross Triggering through subscriber ports enabled */
    DL_TIMER_CROSS_TRIGGER_INPUT_ENABLED = GPTIMER_CTTRIGCTL_EVTCTEN_ENABLE,
    /*! Cross Triggering through subscriber ports disabled */
    DL_TIMER_CROSS_TRIGGER_INPUT_DISABLED = GPTIMER_CTTRIGCTL_EVTCTEN_DISABLED,
} DL_TIMER_CROSS_TRIGGER_INPUT;

/*! @enum DL_TIMER_CROSS_TRIGGER_MODE */
typedef enum {
    /*! Cross Triggering Enabled */
    DL_TIMER_CROSS_TRIGGER_MODE_ENABLED = GPTIMER_CTTRIGCTL_CTEN_ENABLE,
    /*! Cross Triggering Disabled */
    DL_TIMER_CROSS_TRIGGER_MODE_DISABLED = GPTIMER_CTTRIGCTL_CTEN_DISABLED,
} DL_TIMER_CROSS_TRIGGER_MODE;

/*! @enum DL_TIMER_IIDX */
typedef enum {
    /*! Timer interrupt index for zero interrupt */
    DL_TIMER_IIDX_ZERO = GPTIMER_CPU_INT_IIDX_STAT_Z,
    /*! Timer interrupt index for load interrupt */
    DL_TIMER_IIDX_LOAD = GPTIMER_CPU_INT_IIDX_STAT_L,
    /*! Timer interrupt index for compare 0 down interrupt */
    DL_TIMER_IIDX_CC0_DN = GPTIMER_CPU_INT_IIDX_STAT_CCD0,
    /*! Timer interrupt index for compare 1 down interrupt */
    DL_TIMER_IIDX_CC1_DN = GPTIMER_CPU_INT_IIDX_STAT_CCD1,
    /*! Timer interrupt index for compare 2 down interrupt */
    DL_TIMER_IIDX_CC2_DN = GPTIMER_CPU_INT_IIDX_STAT_CCD2,
    /*! Timer interrupt index for compare 3 down interrupt */
    DL_TIMER_IIDX_CC3_DN = GPTIMER_CPU_INT_IIDX_STAT_CCD3,
    /*! Timer interrupt index for compare 0 up interrupt */
    DL_TIMER_IIDX_CC0_UP = GPTIMER_CPU_INT_IIDX_STAT_CCU0,
    /*! Timer interrupt index for compare 1 up interrupt */
    DL_TIMER_IIDX_CC1_UP = GPTIMER_CPU_INT_IIDX_STAT_CCU1,
    /*! Timer interrupt index for compare 2 up interrupt */
    DL_TIMER_IIDX_CC2_UP = GPTIMER_CPU_INT_IIDX_STAT_CCU2,
    /*! Timer interrupt index for compare 3 up interrupt */
    DL_TIMER_IIDX_CC3_UP = GPTIMER_CPU_INT_IIDX_STAT_CCU3,

    /*! Timer interrupt index for compare 4 down interrupt */
    DL_TIMER_IIDX_CC4_DN = GPTIMER_CPU_INT_IIDX_STAT_CCD4,
    /*! Timer interrupt index for compare 5 down interrupt */
    DL_TIMER_IIDX_CC5_DN = GPTIMER_CPU_INT_IIDX_STAT_CCD5,
    /*! Timer interrupt index for compare 4 up interrupt */
    DL_TIMER_IIDX_CC4_UP = GPTIMER_CPU_INT_IIDX_STAT_CCU4,
    /*! Timer interrupt index for compare 5 up interrupt */
    DL_TIMER_IIDX_CC5_UP = GPTIMER_CPU_INT_IIDX_STAT_CCU5,

    /*! Timer interrupt index for fault interrupt */
    DL_TIMER_IIDX_FAULT = GPTIMER_CPU_INT_IIDX_STAT_F,
    /*! Timer interrupt index for timer overflow interrupt */
    DL_TIMER_IIDX_OVERFLOW = GPTIMER_CPU_INT_IIDX_STAT_TOV,
    /*! Timer interrupt index for repeat counter
     * @note <b> This is a Timer A specific interrupt. </b>
     */
    DL_TIMER_IIDX_REPEAT_COUNT = GPTIMER_CPU_INT_IIDX_STAT_REPC,
    /*! Timer interrupt index for direction change interrupt
     * @note <b> Please refer the Timer TRM to determine TIMG instances which
     * support this feature. </b> */
    DL_TIMER_IIDX_DIR_CHANGE = GPTIMER_CPU_INT_IIDX_STAT_DC,
} DL_TIMER_IIDX;

/*! @enum DL_TIMER_PUBLISHER_INDEX */
typedef enum {
    /*! TIMER Publisher index 0 */
    DL_TIMER_PUBLISHER_INDEX_0 = 0,
    /*! TIMER Publisher index 1 */
    DL_TIMER_PUBLISHER_INDEX_1 = 1
} DL_TIMER_PUBLISHER_INDEX;

/*! @enum DL_TIMER_SUBSCRIBER_INDEX */
typedef enum {
    /*! TIMER Subscriber index 0 */
    DL_TIMER_SUBSCRIBER_INDEX_0 = 0,
    /*! TIMER Subscriber index 1 */
    DL_TIMER_SUBSCRIBER_INDEX_1 = 1
} DL_TIMER_SUBSCRIBER_INDEX;

/*! @enum DL_TIMER_EVENT_ROUTE */
typedef enum {
    /*! TIMER event route 1 */
    DL_TIMER_EVENT_ROUTE_1 = 0,
    /*! TIMER event route 2 */
    DL_TIMER_EVENT_ROUTE_2 = 12
} DL_TIMER_EVENT_ROUTE;

/*! @enum DL_TIMER_INPUT_CHAN */
typedef enum {
    /*! Selected timer instance channel 0 as input capture channel */
    DL_TIMER_INPUT_CHAN_0,
    /*! Selects timer instance channel 1 as input capture channel */
    DL_TIMER_INPUT_CHAN_1,
    /*! Selects timer instance channel 2 as input capture channel.
     *  Please refer to device DS to determine number of input channels
     *  by the timer instance */
    DL_TIMER_INPUT_CHAN_2,
    /*! Selects timer instance channel 3 as input capture channel.
     *  Please refer to device DS to determine number of input channels
     *  by the timer instance */
    DL_TIMER_INPUT_CHAN_3,
} DL_TIMER_INPUT_CHAN;

/*! @enum  DL_TIMER_DEBUG_RES */
typedef enum {
    /*! Resume counting */
    DL_TIMER_DEBUG_RES_RESUME = GPTIMER_CTRCTL_DRB_RESUME,
    /*! Perform the action as specified by the Counter Value After Enable (CVAE)
     *! field. */
    DL_TIMER_DEBUG_RES_CVAE_ACTION = GPTIMER_CTRCTL_DRB_CVAE_ACTION,
} DL_TIMER_DEBUG_RES;

/*! @enum  DL_TIMER_CZC */
typedef enum {
    /*! Zero event is controlled by CCCTL0 Zero condition */
    DL_TIMER_CZC_CCCTL0_ZCOND = GPTIMER_CTRCTL_CZC_CCCTL0_ZCOND,
    /*! Zero event is controlled by CCCTL1 Zero condition */
    DL_TIMER_CZC_CCCTL1_ZCOND = GPTIMER_CTRCTL_CZC_CCCTL1_ZCOND,
    /*! Zero event is controlled by CCCTL2 Zero condition */
    DL_TIMER_CZC_CCCTL2_ZCOND = GPTIMER_CTRCTL_CZC_CCCTL2_ZCOND,
    /*! Zero event is controlled by CCCTL3 Zero condition */
    DL_TIMER_CZC_CCCTL3_ZCOND = GPTIMER_CTRCTL_CZC_CCCTL3_ZCOND,
    /*! Zero event is controlled by 2-input QEI mode */
    DL_TIMER_CZC_QEI_2INP = GPTIMER_CTRCTL_CZC_QEI_2INP,
    /*! Zero event is controlled by 3-input QEI mode */
    DL_TIMER_CZC_QEI_3INP = GPTIMER_CTRCTL_CZC_QEI_3INP,
} DL_TIMER_CZC;

/*! @enum  DL_TIMER_CAC */
typedef enum {
    /*! Advance event is controlled by CCCTL0 advance condition */
    DL_TIMER_CAC_CCCTL0_ACOND = GPTIMER_CTRCTL_CAC_CCCTL0_ACOND,
    /*! Advance event is controlled by CCCTL1 advance condition */
    DL_TIMER_CAC_CCCTL1_ACOND = GPTIMER_CTRCTL_CAC_CCCTL1_ACOND,
    /*! Advance event is controlled by CCCTL2 advance condition */
    DL_TIMER_CAC_CCCTL2_ACOND = GPTIMER_CTRCTL_CAC_CCCTL2_ACOND,
    /*! Advance event is controlled by CCCTL3 advance condition */
    DL_TIMER_CAC_CCCTL3_ACOND = GPTIMER_CTRCTL_CAC_CCCTL3_ACOND,
    /*! Advance event is controlled by 2-input QEI mode */
    DL_TIMER_CAC_QEI_2INP = GPTIMER_CTRCTL_CAC_QEI_2INP,
    /*! Advance event is controlled by 3-input QEI mode */
    DL_TIMER_CAC_QEI_3INP = GPTIMER_CTRCTL_CAC_QEI_3INP,
} DL_TIMER_CAC;

/*! @enum  DL_TIMER_CLC */
typedef enum {
    /*! Load event is controlled by CCCTL0 load condition */
    DL_TIMER_CLC_CCCTL0_LCOND = GPTIMER_CTRCTL_CLC_CCCTL0_LCOND,
    /*! Load event is controlled by CCCTL1 load condition */
    DL_TIMER_CLC_CCCTL1_LCOND = GPTIMER_CTRCTL_CLC_CCCTL1_LCOND,
    /*! Load event is controlled by CCCTL2 load condition */
    DL_TIMER_CLC_CCCTL2_LCOND = GPTIMER_CTRCTL_CLC_CCCTL2_LCOND,
    /*! Load event is controlled by CCCTL3 load condition */
    DL_TIMER_CLC_CCCTL3_LCOND = GPTIMER_CTRCTL_CLC_CCCTL3_LCOND,
    /*! Load event is controlled by 2-input QEI mode */
    DL_TIMER_CLC_QEI_2INP = GPTIMER_CTRCTL_CLC_QEI_2INP,
    /*! Load event is controlled by 3-input QEI mode */
    DL_TIMER_CLC_QEI_3INP = GPTIMER_CTRCTL_CLC_QEI_3INP,
} DL_TIMER_CLC;

/*! @enum  DL_TIMER_COUNT_AFTER_EN */
typedef enum {
    /*! The counter is set to the LOAD register value */
    DL_TIMER_COUNT_AFTER_EN_LOAD_VAL = GPTIMER_CTRCTL_CVAE_LDVAL,
    /*! The counter value is unchanged from its current value */
    DL_TIMER_COUNT_AFTER_EN_NO_CHANGE = GPTIMER_CTRCTL_CVAE_NOCHANGE,
    /*! The counter is set to zero */
    DL_TIMER_COUNT_AFTER_EN_ZERO = GPTIMER_CTRCTL_CVAE_ZEROVAL,

} DL_TIMER_COUNT_AFTER_EN;

/*! @enum  DL_TIMER_REPEAT_MODE */
typedef enum {
    /*! Does not automatically advance following a zero event */
    DL_TIMER_REPEAT_MODE_DISABLED = GPTIMER_CTRCTL_REPEAT_REPEAT_0,
    /*! Continues to advance following a zero event */
    DL_TIMER_REPEAT_MODE_ENABLED = GPTIMER_CTRCTL_REPEAT_REPEAT_1,
    /*! Continues to advance following a zero event if the debug mode is not in
     *! effect, or following the release of the debug mode */
    DL_TIMER_REPEAT_MODE_ENABLED_DEBUG = GPTIMER_CTRCTL_REPEAT_REPEAT_3,
} DL_TIMER_REPEAT_MODE;

/*! @enum  DL_TIMER_CC_UPDATE_METHOD */
typedef enum {
    /*! Value written to the CCACT.SWFRCACT register has immediate effect */
    DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE = (GPTIMER_CCCTL_01_CCUPD_IMMEDIATELY),
    /*! Following a zero event. Writes to the CCx_y register are stored in
     *  Shadow register and transferred to CCx_y in the TIMCLK cycle following
     *  CTR equals 0 */
    DL_TIMER_CC_UPDATE_METHOD_ZERO_EVT = (GPTIMER_CCCTL_01_CCUPD_ZERO_EVT),
    /*! Following a compare (down) event. Writes to the CCx_y register are
     *  stored in Shadow register and transferred to CCx_y in the TIMCLK cycle
     *  following CTR equals the CCx_y register value.*/
    DL_TIMER_CC_UPDATE_METHOD_COMP_DN_EVT =
        (GPTIMER_CCCTL_01_CCUPD_COMPARE_DOWN_EVT),
    /*! Following a compare (up) event. Writes to the CCx_y register are stored
     *  in Shadow register and transferred to CCx_y in the TIMCLK cycle
     *  following CTR equals the CCx_y register value. */
    DL_TIMER_CC_UPDATE_METHOD_COMP_UP_EVT =
        (GPTIMER_CCCTL_01_CCUPD_COMPARE_UP_EVT),
    /*! Following a zero or load event. Writes to the CCx_y register are stored
     *  in Shadow register and transferred to CCx_y in the TIMCLK cycle
     *  following CTR equals 0 or CTR. Equals LDn.  Note this update mechanism
     *  is defined for use only in configurations using up/down counting.
     *  This mode is not intended for use in down count configurations */
    DL_TIMER_CC_UPDATE_METHOD_ZERO_OR_LOAD_EVT =
        (GPTIMER_CCCTL_01_CCUPD_ZERO_LOAD_EVT),
    /*! Following a zero event with repeat count also zero.  Writes to the CCx_y
     *  register are stored in Shadow register and transferred to CCx_y in the
     *  TIMCLK cycle following CTR equals 0 and if RC equal 0.*/
    DL_TIMER_CC_UPDATE_METHOD_ZERO_RC_EVT =
        (GPTIMER_CCCTL_01_CCUPD_ZERO_RC_ZERO_EVT),
    /*! Following a TRIG pulse, writes to the
     *! Capture Compare register are stored in shadow register and transferred
     *! to Capture Compare register in the TIMCLK cycle following timer counter
     *! equal to zero AND repeaet counter value is 0 */
    DL_TIMER_CC_UPDATE_METHOD_TRIG_EVT = (GPTIMER_CCCTL_01_CCUPD_TRIG),
} DL_TIMER_CC_UPDATE_METHOD;

/*! @enum  DL_TIMER_SEC_COMP_DOWN_EVT */
typedef enum {
    /*! Selects Capture Compare down event based on Capture Compare register 0
     *! value */
    DL_TIMER_SEC_COMP_DOWN_EVT_SEL_CC0 = (GPTIMER_CCCTL_01_CC2SELD_SEL_CCD0),
    /*! Selects Capture Compare down event based on Capture Compare register 1
     *! value */
    DL_TIMER_SEC_COMP_DOWN_EVT_SEL_CC1 = (GPTIMER_CCCTL_01_CC2SELD_SEL_CCD1),
    /*! Selects Capture Compare down event based on Capture Compare register 2
     *! value */
    DL_TIMER_SEC_COMP_DOWN_EVT_SEL_CC2 = (GPTIMER_CCCTL_01_CC2SELD_SEL_CCD2),
    /*! Selects Capture Compare down event based on Capture Compare register 3
     *! value */
    DL_TIMER_SEC_COMP_DOWN_EVT_SEL_CC3 = (GPTIMER_CCCTL_01_CC2SELD_SEL_CCD3),
    /*! Selects Capture Compare down event based on Capture Compare register 4
     *! value */
    DL_TIMER_SEC_COMP_DOWN_EVT_SEL_CC4 = (GPTIMER_CCCTL_01_CC2SELD_SEL_CCD4),
    /*! Selects Capture Compare down event based on Capture Compare register 5
     *! value */
    DL_TIMER_SEC_COMP_DOWN_EVT_SEL_CC5 = (GPTIMER_CCCTL_01_CC2SELD_SEL_CCD5),
} DL_TIMER_SEC_COMP_DOWN_EVT;

/*! @enum  DL_TIMER_SEC_COMP_UP_EVT */
typedef enum {
    /*! Selects Capture Compare up event based on Capture Compare register 0
     *! value */
    DL_TIMER_SEC_COMP_UP_EVT_SEL_CC0 = (GPTIMER_CCCTL_01_CC2SELU_SEL_CCU0),
    /*! Selects Capture Compare up event based on Capture Compare register 1
     *! value */
    DL_TIMER_SEC_COMP_UP_EVT_SEL_CC1 = (GPTIMER_CCCTL_01_CC2SELU_SEL_CCU1),
    /*! Selects Capture Compare up event based on Capture Compare register 2
     *! value */
    DL_TIMER_SEC_COMP_UP_EVT_SEL_CC2 = (GPTIMER_CCCTL_01_CC2SELU_SEL_CCU2),
    /*! Selects Capture Compare up event based on Capture Compare register 3
     *! value */
    DL_TIMER_SEC_COMP_UP_EVT_SEL_CC3 = (GPTIMER_CCCTL_01_CC2SELU_SEL_CCU3),
    /*! Selects Capture Compare up event based on Capture Compare register 4
     *! value */
    DL_TIMER_SEC_COMP_UP_EVT_SEL_CC4 = (GPTIMER_CCCTL_01_CC2SELU_SEL_CCU4),
    /*! Selects Capture Compare up event based on Capture Compare register 5
     *! value */
    DL_TIMER_SEC_COMP_UP_EVT_SEL_CC5 = (GPTIMER_CCCTL_01_CC2SELU_SEL_CCU5),
} DL_TIMER_SEC_COMP_UP_EVT;

/*! @enum  DL_TIMER_SEC_COMP_UP_ACT_SEL */
typedef enum {
    /*! Second comparator output action is disabled. */
    DL_TIMER_SEC_COMP_UP_ACT_SEL_DISABLE = GPTIMER_CCACT_01_CC2UACT_DISABLED,
    /*! Timer channel is set high when the second comparator up counting event
     * is detected */
    DL_TIMER_SEC_COMP_UP_ACT_SEL_HIGH = GPTIMER_CCACT_01_CC2UACT_CCP_HIGH,
    /*! Timer channel is set low when the second comparator up counting event
     * is detected */
    DL_TIMER_SEC_COMP_UP_ACT_SEL_LOW = GPTIMER_CCACT_01_CC2UACT_CCP_LOW,
    /*! Timer channel is toggles when the second comparator up counting event
     * is detected */
    DL_TIMER_SEC_COMP_UP_ACT_SEL_TOGGLE = GPTIMER_CCACT_01_CC2UACT_CCP_TOGGLE,
} DL_TIMER_SEC_COMP_UP_ACT_SEL;

/*! @enum  DL_TIMER_SEC_COMP_DOWN_ACT_SEL */
typedef enum {
    /*! Second comparator output action is disabled. */
    DL_TIMER_SEC_COMP_DOWN_ACT_SEL_DISABLE = GPTIMER_CCACT_01_CC2DACT_DISABLED,
    /*! Timer channel is set high when the second comparator down counting event
     * is detected */
    DL_TIMER_SEC_COMP_DOWN_ACT_SEL_HIGH = GPTIMER_CCACT_01_CC2DACT_CCP_HIGH,
    /*! Timer channel is set low when the second comparator down counting event
     * is detected */
    DL_TIMER_SEC_COMP_DOWN_ACT_SEL_LOW = GPTIMER_CCACT_01_CC2DACT_CCP_LOW,
    /*! Timer channel is toggles when the second comparator down counting event
     * is detected */
    DL_TIMER_SEC_COMP_DOWN_ACT_SEL_TOGGLE =
        GPTIMER_CCACT_01_CC2DACT_CCP_TOGGLE,
} DL_TIMER_SEC_COMP_DOWN_ACT_SEL;

/*! @enum  DL_TIMER_SUPP_COMP_EVT_RC */
typedef enum {
    /*! Capture compare up and down events are always generated from the counter
     *! when their conditions are genreated */
    DL_TIMER_SUPP_COMP_EVT_RC_DISABLED = (GPTIMER_CCCTL_01_SCERCNEZ_DISABLED),
    /*! Capture compare up and down events are generated from the counter when
     *! their conditions are genreated and the repeat counter value is 0 */
    DL_TIMER_SUPP_COMP_EVT_RC_ENABLED = (GPTIMER_CCCTL_01_SCERCNEZ_ENABLED),
} DL_TIMER_SUPP_COMP_EVT_RC;

/*! @enum  DL_TIMER_FORCE_OUT */
typedef enum {
    /*! The CCP output value is unaffected */
    DL_TIMER_FORCE_OUT_DISABLED = (GPTIMER_CCACT_01_SWFRCACT_DISABLED),
    /*! Output value is set high */
    DL_TIMER_FORCE_OUT_HIGH = (GPTIMER_CCACT_01_SWFRCACT_CCP_HIGH),
    /*! Output value is set low */
    DL_TIMER_FORCE_OUT_LOW = (GPTIMER_CCACT_01_SWFRCACT_CCP_LOW),

} DL_TIMER_FORCE_OUT;

/*! @enum  DL_TIMER_FORCE_CMPL_OUT */
typedef enum {
    /*! The complementary CCP output value is unaffected */
    DL_TIMER_FORCE_CMPL_OUT_DISABLED =
        (GPTIMER_CCACT_01_SWFRCACT_CMPL_DISABLED),
    /*! Complementary CCP output is set high */
    DL_TIMER_FORCE_CMPL_OUT_HIGH = (GPTIMER_CCACT_01_SWFRCACT_CMPL_CCP_HIGH),
    /*! Complementary CCP output is set low */
    DL_TIMER_FORCE_CMPL_OUT_LOW = (GPTIMER_CCACT_01_SWFRCACT_CMPL_CCP_LOW),

} DL_TIMER_FORCE_CMPL_OUT;

/*! @enum  DL_TIMER_CORE_HALT */
typedef enum {
    /*! Timer will halt immediately, even if the resultant state will result in
        corruption if the system is restarted */
    DL_TIMER_CORE_HALT_IMMEDIATE =
        (GPTIMER_PDBGCTL_FREE_STOP | GPTIMER_PDBGCTL_SOFT_IMMEDIATE),
    /*! Timer blocks the debug freeze until it has reached a boundary where it
        can resume without corruption */
    DL_TIMER_CORE_HALT_DELAYED =
        (GPTIMER_PDBGCTL_FREE_STOP | GPTIMER_PDBGCTL_SOFT_DELAYED),
    /*! Timer ignores the state of the Core Halted input */
    DL_TIMER_CORE_HALT_FREE_RUN =
        (GPTIMER_PDBGCTL_FREE_RUN | GPTIMER_PDBGCTL_SOFT_DELAYED),
} DL_TIMER_CORE_HALT;

/*!
 *  @brief  Configuration struct for @ref DL_Timer_setClockConfig.
 */
typedef struct {
    /*! Selects timer module clock source @ref DL_TIMER_CLOCK*/
    DL_TIMER_CLOCK clockSel;
    /*! Selects the timer module clock divide ratio
    @ref DL_TIMER_CLOCK_DIVIDE */
    DL_TIMER_CLOCK_DIVIDE divideRatio;
    /*! Selects the timer module clock prescaler. Valid range 0-255 */
    uint8_t prescale;
} DL_Timer_ClockConfig;

/*!
 *  @brief  Configuration struct for @ref DL_Timer_initTimerMode.
 */
typedef struct {
    /*! One shot or Periodic mode configuration. One of
     * @ref DL_TIMER_TIMER_MODE */
    DL_TIMER_TIMER_MODE timerMode;
    /*! Actual period will be period_actual=(period +1)T_TIMCLK
     * where T_TIMCLK is the period of the timer source clock. */
    uint32_t period;
    /*! Start timer after configuration @ref DL_TIMER */
    DL_TIMER startTimer;
    /*! Generate intermediate counter interrupt
     * @ref DL_TIMER_INTERM_INT*/
    DL_TIMER_INTERM_INT genIntermInt;
    /*! Counter value when intermediate interrupt should be generated. This
     * member must be set to 0 when
     * @ref genIntermInt == DL_TIMER_INTERM_INT_DISABLED */
    uint32_t counterVal;
} DL_Timer_TimerConfig;

/*!
 * @brief Configuration struct for @ref DL_Timer_initCaptureMode.
 */
typedef struct {
    /*! Selects capture mode. One of @ref DL_TIMER_CAPTURE_MODE */
    DL_TIMER_CAPTURE_MODE captureMode;
    /*! Specifies the capture period. period_actual=(period +1)T_TIMCLK
     * where T_TIMCLK is the period of the timer source clock. */
    uint32_t period;
    /*! Start timer after configuration @ref DL_TIMER */
    DL_TIMER startTimer;
    /*! Specifies the edge detection mode. One of
        @ref DL_TIMER_CAPTURE_EDGE_DETECTION_MODE*/
    DL_TIMER_CAPTURE_EDGE_DETECTION_MODE edgeCaptMode;
    /*! Selects input channel used for capture mode */
    DL_TIMER_INPUT_CHAN inputChan;
    /*! Specifies if input should be inverted. One of
     *  @ref DL_TIMER_CC_INPUT_INV */
    uint32_t inputInvMode;
} DL_Timer_CaptureConfig;

/*!
 * @brief Configuration struct for @ref DL_Timer_initCaptureTriggerMode.
 */
typedef struct {
    /*! Selects capture mode. One of @ref DL_TIMER_CAPTURE_MODE */
    DL_TIMER_CAPTURE_MODE captureMode;
    /*! Specifies the capture period. period_actual=(period +1) * T_TIMCLK
     * where T_TIMCLK is the period of the timer source clock. */
    uint32_t period;
    /*! Start timer after configuration. One of @ref DL_TIMER */
    DL_TIMER startTimer;
} DL_Timer_CaptureTriggerConfig;

/*!
 * @brief Configuration struct for @ref DL_Timer_initCaptureCombinedMode.
 */
typedef struct {
    /*! Selects capture mode. One of @ref DL_TIMER_CAPTURE_COMBINED_MODE */
    DL_TIMER_CAPTURE_COMBINED_MODE captureMode;
    /*! Specifies the capture period. period_actual=(period +1)T_TIMCLK
     * where T_TIMCLK is the period of the timer source clock. */
    uint32_t period;
    /*! Start timer after configuration @ref DL_TIMER */
    DL_TIMER startTimer;
    /*! Selects input channel used for capture mode. One of @ref DL_TIMER_INPUT_CHAN */
    DL_TIMER_INPUT_CHAN inputChan;
    /*! Specifies if input should be inverted. One of
     *  @ref DL_TIMER_CC_INPUT_INV */
    uint32_t inputInvMode;
} DL_Timer_CaptureCombinedConfig;

/*!
 * @brief Configuration struct for @ref DL_Timer_initCompareMode.
 */
typedef struct {
    /*! Selects capture mode. One of @ref DL_TIMER_COMPARE_MODE */
    DL_TIMER_COMPARE_MODE compareMode;
    /*! Specifies the intial count value. In edge count mode this value will
     *  decrease everytime the configured edge detection mode is detected.
     *  The counter will be reset to this value after the reaching zero.
     */
    uint32_t count;
    /*! Specifies the edge detection mode. One of
        @ref DL_TIMER_CAPTURE_EDGE_DETECTION_MODE*/
    DL_TIMER_COMPARE_EDGE_DETECTION_MODE edgeDetectMode;
    /*! Selects input channel used for compare mode. One of @ref DL_TIMER_INPUT_CHAN */
    DL_TIMER_INPUT_CHAN inputChan;
    /*! Specifies if input should be inverted. One of
     *  @ref DL_TIMER_CC_INPUT_INV */
    uint32_t inputInvMode;
    /*! Start timer after configuration. One of @ref DL_TIMER */
    DL_TIMER startTimer;
} DL_Timer_CompareConfig;

/*!
 * @brief Configuration struct for @ref DL_Timer_initCompareTriggerMode.
 */
typedef struct {
    /*! Selects capture mode. One of @ref DL_TIMER_COMPARE_MODE */
    DL_TIMER_COMPARE_MODE compareMode;
    /*! Specifies the intial count value. In edge count mode this value will
     *  decrease everytime the configured edge detection mode is detected.
     *  The counter will be reset to this value after the reaching zero.
     */
    uint32_t count;
    /*! Specifies the edge detection mode. One of
        @ref DL_TIMER_CAPTURE_EDGE_DETECTION_MODE*/
    DL_TIMER_COMPARE_EDGE_DETECTION_MODE edgeDetectMode;
    /*! Start timer after configuration. One of @ref DL_TIMER */
    DL_TIMER startTimer;
} DL_Timer_CompareTriggerConfig;

/**
 * @brief Configuration struct for @ref DL_Timer_initPWMMode.
 */
typedef struct {
    /*! Specifies the pwm period. The actual value configured to LOAD register
     *  depends on the pwmMode selected. When
     *  pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN, LOAD = (period -1). When
     *  pwmMode = DL_TIMER_PWM_MODE_CENTER_ALIGN, LOAD = (period / 2).
     *  Actual PWM freq = (Timer_freq/(prescaler * divideRatio * period))
     */
    uint32_t period;
    /*! Specifies the PWM Mode. One of @ref DL_TIMER_PWM_MODE */
    DL_TIMER_PWM_MODE pwmMode;
    /*! Start timer after configuration @ref DL_TIMER */
    DL_TIMER startTimer;
} DL_Timer_PWMConfig;

/**
 * @brief Configuration structure to backup Timer peripheral state before
 *        entering STOP or STANDBY mode. Not required after PG 1.0 silicon.
 *        Used by @ref DL_Timer_saveConfiguration and
 *        @ref DL_Timer_restoreConfiguration
 */
typedef struct {
    /*! Timer subscriber 0 channel ID. Value between 0 - 15. */
    uint32_t sub0PortConf;
    /*! Timer subscriber 1 channel ID. Value between 0 - 15. */
    uint32_t sub1PortConf;
    /*! Timer publisher 0 channel ID. Value between 0 - 15. */
    uint32_t pub0PortConf;
    /*! Timer publisher 1 channel ID. Value between 0 - 15. */
    uint32_t pub1PortConf;
    /*! Timer clockDivider configuration.*/
    uint32_t clkDivConf;
    /*! Timer clock prescaler configuration.*/
    uint32_t clockPscConf;
    /*! Timer Clock Source Select configuration.*/
    uint32_t clkSelConf;
    /*! Timer Clock configuration.*/
    uint32_t countClkConf;
    /*! Timer interrupt configuration for EVENT0.*/
    uint32_t intEvnt0Conf;
    /*! Timer interrupt configuration for EVENT1.*/
    uint32_t intEvnt1Conf;
    /*! Timer interrupt configuration for EVENT2.*/
    uint32_t intEvnt2Conf;
    /*! Timer CCP Direction configuration.*/
    uint32_t ccpDirConf;
    /*! Timer CCP Output forced low configuration.*/
    uint32_t outDisConf;
    /*! Timer Cross Timer Trigger Control configuration.*/
    uint32_t crossTrigCtl;
    /*! Timer Cross Trigger Configuration */
    uint32_t tSelConf;
    /*! Timer Cross Timer Trigger*/
    uint32_t crossTrigConf;
    /*! Timer counter value. Timer counter value is stored but user can
     *  specify if counter is restore via restoreCounter argument in
     *  @ref DL_Timer_restoreConfiguration */
    uint32_t cntVal;
    /*! Timer counter control configuration */
    uint32_t cntCtlConf;
    /*! Timer load value */
    uint32_t loadVal;
    /*! Timer Capture or Compare 0 value */
    uint32_t cc0Val;
    /*! Timer Capture or Compare 1 value */
    uint32_t cc1Val;
    /*! Timer Capture or Compare Control Register 0 */
    uint32_t cc0Ctl;
    /*! Timer Capture or Compare Control Register 1 */
    uint32_t cc1Ctl;
    /*! Timer Capture or Compare Output Control Register 0 */
    uint32_t cc0OutCtl;
    /*! Timer Capture or Compare Output Control Register 1 */
    uint32_t cc1OutCtl;
    /*! Timer Capture or Compare Signal Generator Action Control Register 0 */
    uint32_t cc0ActCtl;
    /*! Timer Capture or Compare Signal Generator Action Control Register 1 */
    uint32_t cc1ActCtl;
    /*! Timer Capture or Compare Input Filter and Inversion Control
     *  Register 0 */
    uint32_t in0FiltCtl;
    /*! Timer Capture or Compare Input Filter and Inversion Control
     *  Register 1 */
    uint32_t in1FiltCtl;
    /*! Boolean flag indicating whether or not a valid configuration structure
     *  exists. Should not be modified by the user. */
    bool backupRdy;
} DL_Timer_backupConfig;

/*! @enum DL_TIMER_QEI_MODE */
typedef enum {
    /*! Set QEI to 2 input mode: PHA->CCP0, PHB->CCP1. */
    DL_TIMER_QEI_MODE_2_INPUT =
        (GPTIMER_CTRCTL_CLC_QEI_2INP | GPTIMER_CTRCTL_CAC_QEI_2INP |
            GPTIMER_CTRCTL_CZC_QEI_2INP),
    /*! Set QEI to 3 input mode: PHA->CCP0, PHB->CCP1, Index input signal->IDX. */
    DL_TIMER_QEI_MODE_3_INPUT =
        (GPTIMER_CTRCTL_CLC_QEI_3INP | GPTIMER_CTRCTL_CAC_QEI_3INP |
            GPTIMER_CTRCTL_CZC_QEI_3INP),
} DL_TIMER_QEI_MODE;

/*! @enum DL_TIMER_QEI_DIRECTION */
typedef enum {
    /*! Encoder counter going down */
    DL_TIMER_QEI_DIR_DOWN = GPTIMER_QDIR_DIR_DOWN,
    /*! Encoder counter going up */
    DL_TIMER_QEI_DIR_UP = GPTIMER_QDIR_DIR_UP,
} DL_TIMER_QEI_DIRECTION;

/**
 * @brief Enables power on timer module
 *
 * @param gptimer              Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_Timer_enablePower(GPTIMER_Regs *gptimer)
{
    gptimer->GPRCM.PWREN =
        (GPTIMER_PWREN_KEY_UNLOCK_W | GPTIMER_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Disables power on timer module
 *
 * @param gptimer              Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_Timer_disablePower(GPTIMER_Regs *gptimer)
{
    gptimer->GPRCM.PWREN =
        (GPTIMER_PWREN_KEY_UNLOCK_W | GPTIMER_PWREN_ENABLE_DISABLE);
}

/**
 * @brief Returns if power on timer module is enabled
 *
 * @param gptimer              Pointer to the register overlay for the
 *                             peripheral
 *
 * @return true if power is enabled
 * @return false if power is disabled
 */
__STATIC_INLINE bool DL_Timer_isPowerEnabled(GPTIMER_Regs *gptimer)
{
    return ((gptimer->GPRCM.PWREN & GPTIMER_PWREN_ENABLE_MASK) ==
            GPTIMER_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Resets timer peripheral
 *
 * @param gptimer              Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_Timer_reset(GPTIMER_Regs *gptimer)
{
    gptimer->GPRCM.RSTCTL =
        (GPTIMER_RSTCTL_KEY_UNLOCK_W | GPTIMER_RSTCTL_RESETSTKYCLR_CLR |
            GPTIMER_RSTCTL_RESETASSERT_ASSERT);
}

/**
 * @brief Returns if timer peripheral has been reset
 *
 * @param gptimer              Pointer to the register overlay for the
 *                             peripheral
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 */
__STATIC_INLINE bool DL_Timer_isReset(GPTIMER_Regs *gptimer)
{
    return ((gptimer->GPRCM.STAT & GPTIMER_STAT_RESETSTKY_MASK) ==
            GPTIMER_STAT_RESETSTKY_RESET);
}

/**
 *  @brief      Sets CCP Direction
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccpConfig      Direction configuration for CCP as input or
 *                             output. Bitwise OR  of @ref DL_TIMER_CCx
 */
__STATIC_INLINE void DL_Timer_setCCPDirection(
    GPTIMER_Regs *gptimer, uint32_t ccpConfig)
{
    gptimer->COMMONREGS.CCPD = (ccpConfig);
}

/**
 *  @brief      Gets CCP Direction
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     Bitwise OR of CCP Direction configuration @ref DL_TIMER_CCx
 */
__STATIC_INLINE uint32_t DL_Timer_getCCPDirection(GPTIMER_Regs *gptimer)
{
    return (gptimer->COMMONREGS.CCPD);
}

/**
 *  @brief      Forces the output of the timer low via the ODIS register.
 *              This can be useful during shutdown or configuring the timer.
 *              The output pin still passes through the inversion (INV) bit.
 *              See figure "Output connection for TIMG" in Technical
 *              Reference Manual (TRM) for diagram.
 *              DL_Timer_overrideCCPOut() can be used for for similar
 *              functionality, where independent overrride settings for the
 *              output and complementary output channels can be configured.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccp0Config     Output Configuration for CCP0. One of @ref
 *                             DL_TIMER_CCP_DIS_OUT
 *  @param[in]  ccp1Config     Output Configuration for CCP1. One of @ref
 *                             DL_TIMER_CCP_DIS_OUT
 */
__STATIC_INLINE void DL_Timer_setCCPOutputDisabled(GPTIMER_Regs *gptimer,
    DL_TIMER_CCP_DIS_OUT ccp0Config, DL_TIMER_CCP_DIS_OUT ccp1Config)
{
    DL_Common_updateReg(&gptimer->COMMONREGS.ODIS,
        (((uint32_t) ccp0Config) |
            ((uint32_t) ccp1Config << GPTIMER_ODIS_C0CCP1_OFS)),
        (GPTIMER_ODIS_C0CCP0_MASK | GPTIMER_ODIS_C0CCP1_MASK));
}

/**
 *  @brief      Sets CCP Output configuration for timer instances with more than
 *  two CCP channels via the ODIS register. The output pin still passes through
 *  the inversion (INV) bit.
 *
 *  @note Refer to device datasheet to determine if timer instance supports
 *  this feature. Only Timer instance which supports more than two CCP channels
 *  should use this API.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccpOdisConfig  Output Configuration for CCP channels. Bitwise OR
 *                             @ref DL_TIMER_CCP0_DIS_OUT_ADV,
 *                             @ref DL_TIMER_CCP1_DIS_OUT_ADV,
 *                             @ref DL_TIMER_CCP2_DIS_OUT_ADV,
 *                             @ref DL_TIMER_CCP3_DIS_OUT_ADV
 */
__STATIC_INLINE void DL_Timer_setCCPOutputDisabledAdv(
    GPTIMER_Regs *gptimer, uint32_t ccpOdisConfig)
{
    DL_Common_updateReg(&gptimer->COMMONREGS.ODIS, (ccpOdisConfig),
        (GPTIMER_ODIS_C0CCP0_MASK | GPTIMER_ODIS_C0CCP1_MASK |
            GPTIMER_ODIS_C0CCP2_MASK | GPTIMER_ODIS_C0CCP3_MASK));
}

/**
 *  @brief      Configure timer source clock
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  config         Pointer to the clock configuration struct
 *                             @ref DL_Timer_ClockConfig.
 */
void DL_Timer_setClockConfig(
    GPTIMER_Regs *gptimer, DL_Timer_ClockConfig *config);

/**
 *  @brief      Get  timer source clock configuration
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  config         Pointer to the clock configuration struct
 *                             @ref DL_Timer_ClockConfig.
 */
void DL_Timer_getClockConfig(
    GPTIMER_Regs *gptimer, DL_Timer_ClockConfig *config);

/**
 *  @brief      Enable timer clock
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 */
__STATIC_INLINE void DL_Timer_enableClock(GPTIMER_Regs *gptimer)
{
    gptimer->COMMONREGS.CCLKCTL = (GPTIMER_CCLKCTL_CLKEN_ENABLED);
}

/**
 *  @brief      Disable timer clock
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 */
__STATIC_INLINE void DL_Timer_disableClock(GPTIMER_Regs *gptimer)
{
    gptimer->COMMONREGS.CCLKCTL = (GPTIMER_CCLKCTL_CLKEN_DISABLED);
}

/**
 *  @brief      Returns if timer clock is disabled
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return true if clock is enabled
 *  @return false if clock is disabled
 */
__STATIC_INLINE bool DL_Timer_isClockEnabled(GPTIMER_Regs *gptimer)
{
    return ((gptimer->COMMONREGS.CCLKCTL & GPTIMER_CCLKCTL_CLKEN_MASK) ==
            GPTIMER_CCLKCTL_CLKEN_ENABLED);
}

/**
 *  @brief      Configure Cross Timer Trigger
 *
 *  @param[in]  gptimer           Pointer to the register overlay for the
 *                                peripheral
 *  @param[in]  ctSource          Selects cross trigger source.
 *                                @ref DL_TIMER_CROSS_TRIG_SRC
 *
 *  @param[in]  enInTrigCond      Cofigures Input Trigger Conditions to the
 *                                Timer module as a condition for Cross Triggers *                                @ref DL_TIMER_CROSS_TRIGGER_INPUT
 *
 * @param[in]  enCrossTrig        Configures Timer Cross trigger
 *                                @ref DL_TIMER_CROSS_TRIGGER_MODE
 *
 */
__STATIC_INLINE void DL_Timer_configCrossTrigger(GPTIMER_Regs *gptimer,
    DL_TIMER_CROSS_TRIG_SRC ctSource,
    DL_TIMER_CROSS_TRIGGER_INPUT enInTrigCond,
    DL_TIMER_CROSS_TRIGGER_MODE enCrossTrig)
{
    gptimer->COMMONREGS.CTTRIGCTL =
        (uint32_t)((uint32_t) ctSource | (uint32_t) enInTrigCond |
                   (uint32_t) enCrossTrig);
}

/**
 *  @brief      Configure Cross Timer Trigger source
 *
 *  @param[in]  gptimer           Pointer to the register overlay for the
 *                                peripheral
  *  @param[in]  ctSource          Selects cross trigger source.
 *                                @ref DL_TIMER_CROSS_TRIG_SRC
 *
 */
__STATIC_INLINE void DL_Timer_configCrossTriggerSrc(
    GPTIMER_Regs *gptimer, DL_TIMER_CROSS_TRIG_SRC ctSource)
{
    DL_Common_updateReg(&gptimer->COMMONREGS.CTTRIGCTL, (uint32_t) ctSource,
        GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_MASK);
}

/**
 *  @brief      Enables/DIsables Input Trigger condition for Cross Timer Trigger
 *
 *  @param[in]  gptimer           Pointer to the register overlay for the
 *                                peripheral
 *
 *  @param[in]  enInTrigCond      Cofigures Input Trigger Conditions to the
 *                                Timer module as a condition for Cross Triggers
 *                                @ref DL_TIMER_CROSS_TRIGGER_INPUT
 *
 */
__STATIC_INLINE void DL_Timer_configCrossTriggerInputCond(
    GPTIMER_Regs *gptimer, DL_TIMER_CROSS_TRIGGER_INPUT enInTrigCond)
{
    DL_Common_updateReg(&gptimer->COMMONREGS.CTTRIGCTL,
        (uint32_t) enInTrigCond, GPTIMER_CTTRIGCTL_EVTCTEN_MASK);
}

/**
 *  @brief      Enable/Disable Cross Timer Trigger
 *
 *  @param[in]  gptimer           Pointer to the register overlay for the
 *                                peripheral
 * @param[in]  enCrossTrig        Configures Timer Cross trigger
 *                                @ref DL_TIMER_CROSS_TRIGGER_MODE
 *
 */
__STATIC_INLINE void DL_Timer_configCrossTriggerEnable(
    GPTIMER_Regs *gptimer, DL_TIMER_CROSS_TRIGGER_MODE enCrossTrig)
{
    DL_Common_updateReg(&gptimer->COMMONREGS.CTTRIGCTL, (uint32_t) enCrossTrig,
        GPTIMER_CTTRIGCTL_CTEN_MASK);
}

/**
 *  @brief      Get Cross Timer Trigger configuration
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return Bitwise OR of @ref DL_TIMER_CROSS_TRIG_SRC,
 *          @ref DL_TIMER_CROSS_TRIGGER_INPUT, @ref DL_TIMER_CROSS_TRIGGER_MODE,
 *
 */
__STATIC_INLINE uint32_t DL_Timer_getCrossTriggerConfig(GPTIMER_Regs *gptimer)
{
    return (gptimer->COMMONREGS.CTTRIGCTL);
}

/**
 *  @brief      Get Cross Timer Trigger source
 *
 *  @param[in]  gptimer           Pointer to the register overlay for the
 *                                peripheral
 *
 *  @return One of @ref DL_TIMER_CROSS_TRIG_SRC
 *
 */
__STATIC_INLINE DL_TIMER_CROSS_TRIG_SRC DL_Timer_getCrossTriggerSrc(
    GPTIMER_Regs *gptimer)
{
    uint32_t ctSource =
        gptimer->COMMONREGS.CTTRIGCTL & GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_MASK;

    return (DL_TIMER_CROSS_TRIG_SRC)(ctSource);
}

/**
 *  @brief      Get Input Trigger condition for Cross Timer Trigger
 *
 *  @param[in]  gptimer           Pointer to the register overlay for the
 *                                peripheral
 *
 *  @return One of @ref DL_TIMER_CROSS_TRIGGER_INPUT
 *
 */
__STATIC_INLINE DL_TIMER_CROSS_TRIGGER_INPUT DL_Timer_getCrossTriggerInputCond(
    GPTIMER_Regs *gptimer)
{
    uint32_t triggerCondition =
        gptimer->COMMONREGS.CTTRIGCTL & GPTIMER_CTTRIGCTL_EVTCTEN_MASK;

    return (DL_TIMER_CROSS_TRIGGER_INPUT)(triggerCondition);
}

/**
 *  @brief      Checks if Cross Timer Trigger is enabled or disabled
 *
 *  @param[in]  gptimer           Pointer to the register overlay for the
 *                                peripheral
 *
 *  @return One of @ref DL_TIMER_CROSS_TRIGGER_MODE
 *
 */
__STATIC_INLINE DL_TIMER_CROSS_TRIGGER_MODE DL_Timer_getCrossTriggerEnable(
    GPTIMER_Regs *gptimer)
{
    uint32_t mode =
        gptimer->COMMONREGS.CTTRIGCTL & GPTIMER_CTTRIGCTL_CTEN_MASK;

    return (DL_TIMER_CROSS_TRIGGER_MODE)(mode);
}

/**
 *  @brief      Generates a synchronized trigger condition across all trigger
 *              enabled Timer instances
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_Timer_generateCrossTrigger(GPTIMER_Regs *gptimer)
{
    gptimer->COMMONREGS.CTTRIG = GPTIMER_CTTRIG_TRIG_GENERATE;
}

/**
 *  @brief      Enable shadow to activate load of buffered registers and
 *              register fields.
 *
 *  @note Please refer to the device datasheet to determine shadow features
 *        avaialable per timer instance.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_Timer_enableShadowFeatures(GPTIMER_Regs *gptimer)
{
    gptimer->COMMONREGS.GCTL |= GPTIMER_GCTL_SHDWLDEN_ENABLE;
}

/**
 *  @brief      Disable shadow to activate load of buffered registers and
 *              register fields.
 *
 *  @note Please refer to the device datasheet to determine shadow features
 *        avaialable per timer instance.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 */
__STATIC_INLINE void DL_Timer_disableShadowFeatures(GPTIMER_Regs *gptimer)
{
    gptimer->COMMONREGS.GCTL &= ~(GPTIMER_GCTL_SHDWLDEN_ENABLE);
}

/**
 *  @brief      Sets timer LOAD register value
 *
 *  @param[in]  gptimer      Pointer to the register overlay for the
 *                           peripheral
 *  @param[in]  value        Value to be loaded to timer LOAD
 *                           register. Refer to the device datasheet to
 *                           determine the bit width of the counter for
 *                           the selected Timer instance.
 *
 */
__STATIC_INLINE void DL_Timer_setLoadValue(
    GPTIMER_Regs *gptimer, uint32_t value)
{
    gptimer->COUNTERREGS.LOAD = value;
}

/**
 *  @brief      Gets the timer LOAD register value
 *
 *  @param[in]  gptimer      Pointer to the register overlay for the
 *                           peripheral
 *
 *  @return     Returns the timer's LOAD register value.
 *
 */
__STATIC_INLINE uint32_t DL_Timer_getLoadValue(GPTIMER_Regs *gptimer)
{
    return (gptimer->COUNTERREGS.LOAD & GPTIMER_LOAD_LD_MAXIMUM);
}

/**
 *  @brief      Gets the current counter value of the timer
 *
 *  @param[in]  gptimer      Pointer to the register overlay for the
 *                           peripheral
 *
 *  @return     Returns the timer counter value
 */
__STATIC_INLINE uint32_t DL_Timer_getTimerCount(GPTIMER_Regs *gptimer)
{
    return (gptimer->COUNTERREGS.CTR & GPTIMER_CTR_CCTR_MASK);
}

/**
 *  @brief      Set timer counter value
 *
 *  @note       <b>Warning</b> setting the counter value directly while the
 *              timer's counter is running can lead to unpredictable behavior.
 *              This function should only be used when the timer's counter
 *              isn't running. If you need to change the counter value while
 *              it is running then use DL_Timer_setLoadValue(). For TimerH use
 *              DL_TimerH_setLoadValue() instead. These functions will
 *              update the LOAD register which will safely copy its
 *              value to the counter register.
 *
 *  @param[in]  gptimer      Pointer to the register overlay for the
 *                           peripheral
 *  @param[in]  value        Value to set the timer counter value to
 *
 */
__STATIC_INLINE void DL_Timer_setTimerCount(
    GPTIMER_Regs *gptimer, uint32_t value)
{
    gptimer->COUNTERREGS.CTR = value;
}

/**
 *  @brief     Enable suppression of load and zero events
 *
 *  @note Refer to device datasheet to determine if timer instance supports
 *  this feature. Only Timer instance which supports Repeat Counter supports
 *  this feature.
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *
 */
__STATIC_INLINE void DL_Timer_enableLZEventSuppression(GPTIMER_Regs *gptimer)
{
    gptimer->COUNTERREGS.CTRCTL |= (GPTIMER_CTRCTL_SLZERCNEZ_ENABLED);
}

/**
 *  @brief     Disable suppression of load and zero events
 *
 *  @note Refer to device datasheet to determine if timer instance supports
 *  this feature. Only Timer instances which supports Repeat Counter supports
 *  this feature.
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *
 */
__STATIC_INLINE void DL_Timer_disableLZEventSuppression(GPTIMER_Regs *gptimer)
{
    gptimer->COUNTERREGS.CTRCTL &= ~(GPTIMER_CTRCTL_SLZERCNEZ_ENABLED);
}

/**
 *  @brief     Checks if suppression of load and zero events is enabled
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @return Returns the status ofsuppression of load and zero events
 *
 *  @retval     true  suppression of load and zero events is enabled
 *  @retval     false suppression of load and zero events is disabled
 *
 */
__STATIC_INLINE bool DL_Timer_isLZEventSuppressionEnabled(
    GPTIMER_Regs *gptimer)
{
    return (GPTIMER_CTRCTL_SLZERCNEZ_ENABLED ==
            (gptimer->COUNTERREGS.CTRCTL & GPTIMER_CTRCTL_SLZERCNEZ_MASK));
}

/**
 *  @brief     Configures timer behavior during debug release/exit
 *
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  debResB       Specifies timer behavior upon
 *                              relase/exit of debug mode.
 *                              @ref DL_TIMER_DEBUG_RES
 *
 */
__STATIC_INLINE void DL_Timer_setDebugReleaseBehavior(
    GPTIMER_Regs *gptimer, DL_TIMER_DEBUG_RES debResB)
{
    DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL, (uint32_t) debResB,
        GPTIMER_CTRCTL_DRB_MASK);
}

/**
 *  @brief     Get timer resume behavior after relase/exit of debug mode.
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @return @ref DL_TIMER_DEBUG_RES
 *
 */
__STATIC_INLINE DL_TIMER_DEBUG_RES DL_Timer_getDebugReleaseBehavior(
    GPTIMER_Regs *gptimer)
{
    uint32_t debResB = gptimer->COUNTERREGS.CTRCTL & GPTIMER_CTRCTL_DRB_MASK;

    return ((DL_TIMER_DEBUG_RES)(debResB));
}

/**
 *  @brief     Configure timer counter control operation
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  zeroCtl         Specifies event which zeroes the counter value.
 *                              @ref DL_TIMER_CZC
 *  @param[in]  advCtl          Specifies event which increments or
 *                              decrements the counter value.
 *                              @ref DL_TIMER_CAC
 *  @param[in]  loadCtl         Specifies event which sets counter value
 *                              with LD register value.
 *                              @ref DL_TIMER_CLC
 */
__STATIC_INLINE void DL_Timer_setCounterControl(GPTIMER_Regs *gptimer,
    DL_TIMER_CZC zeroCtl, DL_TIMER_CAC advCtl, DL_TIMER_CLC loadCtl)
{
    DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
        ((uint32_t) zeroCtl | (uint32_t) advCtl | (uint32_t) loadCtl),
        (GPTIMER_CTRCTL_CZC_MASK | GPTIMER_CTRCTL_CAC_MASK |
            GPTIMER_CTRCTL_CLC_MASK));
}

/**
 *  @brief     Get timer counter zero control operation
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @return @ref DL_TIMER_CZC
 */
__STATIC_INLINE DL_TIMER_CZC DL_Timer_getCounterZeroControl(
    GPTIMER_Regs *gptimer)
{
    uint32_t zeroCtl = gptimer->COUNTERREGS.CTRCTL & GPTIMER_CTRCTL_CZC_MASK;

    return ((DL_TIMER_CZC)(zeroCtl));
}

/**
 *  @brief     Get timer counter advance control operation
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @return @ref DL_TIMER_CAC
 */
__STATIC_INLINE DL_TIMER_CAC DL_Timer_getCounterAdvanceControl(
    GPTIMER_Regs *gptimer)
{
    uint32_t advCtl = gptimer->COUNTERREGS.CTRCTL & GPTIMER_CTRCTL_CAC_MASK;

    return ((DL_TIMER_CAC)(advCtl));
}

/**
 *  @brief     Get timer counter load control operation
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @return @ref DL_TIMER_CLC
 */
__STATIC_INLINE DL_TIMER_CLC DL_Timer_getCounterLoadControl(
    GPTIMER_Regs *gptimer)
{
    uint32_t loadCtl = gptimer->COUNTERREGS.CTRCTL & GPTIMER_CTRCTL_CLC_MASK;

    return ((DL_TIMER_CLC)(loadCtl));
}

/**
 *  @brief     Configure timer counter couting mode
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  countMode       Specifies timer counter couting mode.
 *                              @ref DL_TIMER_COUNT_MODE
 */
__STATIC_INLINE void DL_Timer_setCounterMode(
    GPTIMER_Regs *gptimer, DL_TIMER_COUNT_MODE countMode)
{
    DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL, ((uint32_t) countMode),
        (GPTIMER_CTRCTL_CM_MASK));
}

/**
 *  @brief     Get timer counter couting mode
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *
 *  @return @ref DL_TIMER_COUNT_MODE
 */
__STATIC_INLINE DL_TIMER_COUNT_MODE DL_Timer_getCounterMode(
    GPTIMER_Regs *gptimer)
{
    uint32_t cmMode = (gptimer->COUNTERREGS.CTRCTL & GPTIMER_CTRCTL_CM_MASK);
    return ((DL_TIMER_COUNT_MODE) cmMode);
}

/**
 *  @brief      Configures counter value after enable
 *
 *  @param[in]  gptimer      Pointer to the register overlay for the
 *                           peripheral
 *  @param[in]  cvae         Speficies counter value after enable.
 *                           @ref DL_TIMER_COUNT_AFTER_EN
 *
 */
__STATIC_INLINE void DL_Timer_setCounterValueAfterEnable(
    GPTIMER_Regs *gptimer, DL_TIMER_COUNT_AFTER_EN cvae)
{
    DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL, (uint32_t) cvae,
        GPTIMER_CTRCTL_CVAE_MASK);
}

/**
 *  @brief      Returns counter value after enable cofiguration
 *
 *  @param[in]  gptimer      Pointer to the register overlay for the
 *                           peripheral
 *  @return  @ref DL_TIMER_COUNT_AFTER_EN
 *
 */
__STATIC_INLINE DL_TIMER_COUNT_AFTER_EN DL_Timer_getCounterValueAfterEnable(
    GPTIMER_Regs *gptimer)
{
    uint32_t cvae = gptimer->COUNTERREGS.CTRCTL & GPTIMER_CTRCTL_CVAE_MASK;

    return ((DL_TIMER_COUNT_AFTER_EN)(cvae));
}

/**
 *  @brief     Configure timer repeat counter mode
 *
 *  @note Refer to device datasheet to determine if timer instance supports
 *  this feature. Only Timer instances which supports repeat counter supports
 *  this feature.
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  repeatMode      Specifies timer repeat counter mode
 *                              @ref DL_TIMER_REPEAT_MODE
 */
__STATIC_INLINE void DL_Timer_setCounterRepeatMode(
    GPTIMER_Regs *gptimer, DL_TIMER_REPEAT_MODE repeatMode)
{
    DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL, (uint32_t) repeatMode,
        GPTIMER_CTRCTL_REPEAT_MASK);
}

/**
 *  @brief     Get timer repeat counter mode
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @return @ref DL_TIMER_REPEAT_MODE
 */
__STATIC_INLINE DL_TIMER_REPEAT_MODE DL_Timer_getCounterRepeatMode(
    GPTIMER_Regs *gptimer)
{
    uint32_t repeatMode =
        gptimer->COUNTERREGS.CTRCTL & GPTIMER_CTRCTL_REPEAT_MASK;

    return ((DL_TIMER_REPEAT_MODE)(repeatMode));
}

/**
 *  @brief      Configure timer in one shot or periodic timer mode
 *  Initializes all the common configurable options for the TIMx peripheral when
 *  used in Timer mode. Any other custom configuration can be done after calling
 *  this API.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  config         Pointer to the mode configuration struct
 *                             @ref DL_Timer_TimerConfig.
 *
 */
void DL_Timer_initTimerMode(
    GPTIMER_Regs *gptimer, DL_Timer_TimerConfig *config);

/**
 *  @brief      Configure timer in edge count, period capture, edge time or
 *              pulse-width capture mode
 *  Initializes all the common configurable options for the TIMx peripheral when
 *  used in Capture mode. Any other custom configuration can be done after
 *  calling this API.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  config         Pointer to the mode configuration struct
 *                             @ref DL_Timer_CaptureConfig.
 *
 */
void DL_Timer_initCaptureMode(
    GPTIMER_Regs *gptimer, DL_Timer_CaptureConfig *config);

/**
 *  @brief      Configure timer in edge count, period capture, edge time or
 *              pulse-width capture mode using the trigger as input source
 *  Initializes all the common configurable options for the TIMx peripheral when
 *  used in Capture mode. Any other custom configuration can be done after
 *  calling this API.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  config         Pointer to the mode configuration struct
 *                             @ref DL_Timer_CaptureTriggerConfig.
 *
 */
void DL_Timer_initCaptureTriggerMode(
    GPTIMER_Regs *gptimer, DL_Timer_CaptureTriggerConfig *config);

/**
 *  @brief      Configure timer in combined pulse-width and period capture
 *  Initializes all the common configurable options for the TIMx peripheral when
 *  used in Capture mode. Any other custom configuration can be done after
 *  calling this API.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  config         Pointer to the mode configuration struct
 *                             @ref DL_Timer_CaptureCombinedConfig.
 *
 */
void DL_Timer_initCaptureCombinedMode(
    GPTIMER_Regs *gptimer, DL_Timer_CaptureCombinedConfig *config);

/**
 *  @brief      Configure timer in edge count compare mode
 *  Initializes all the common configurable options for the TIMx peripheral when
 *  used in Compare mode. Any other custom configuration can be done after
 *  calling this API.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  config         Pointer to the mode configuration struct
 *                             @ref DL_Timer_CompareConfig.
 *
 */
void DL_Timer_initCompareMode(
    GPTIMER_Regs *gptimer, DL_Timer_CompareConfig *config);

/**
 *  @brief      Configure timer in edge count compare mode using the trigger as
 *              input source
 *  Initializes all the common configurable options for the TIMx peripheral when
 *  used in Compare mode. Any other custom configuration can be done after
 *  calling this API.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  config         Pointer to the mode configuration struct
 *                             @ref DL_Timer_CompareTriggerConfig.
 *
 */
void DL_Timer_initCompareTriggerMode(
    GPTIMER_Regs *gptimer, DL_Timer_CompareTriggerConfig *config);

/**
 * @brief Configure timer in Pulse Width Modulation Mode
 *  Initializes all the common configurable options for the TIMx peripheral when
 *  used in PWM mode. Any other custom configuration can be done after calling
 *  this API.
 *
 * @param gptimer              Pointer to the register overlay for the
 *                             peripheral
 * @param config               Pointer to the mode configuration struct
 *                             @ref DL_Timer_PWMConfig.
 */
void DL_Timer_initPWMMode(GPTIMER_Regs *gptimer, DL_Timer_PWMConfig *config);

/**
 *  @brief      Reset register controlling counter operation
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 */
__STATIC_INLINE void DL_Timer_resetCounterMode(GPTIMER_Regs *gptimer)
{
    gptimer->COUNTERREGS.CTRCTL = GPTIMER_CTRCTL_EN_DISABLED;
}

/**
 *  @brief      Sets Timer Capture Compare Value
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  value          Value to write to capture compare register
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 */
void DL_Timer_setCaptureCompareValue(
    GPTIMER_Regs *gptimer, uint32_t value, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief      Get Timer Capture Compare value
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral

 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 *  @return     The current capture compare value
 *
 *
 */
uint32_t DL_Timer_getCaptureCompareValue(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Sets Capture Compare Control configuration
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccMode         Specifies whether the CC register is used as a
 *                             capture register or a compare register
 *                             @ref DL_TIMER_CC_MODE
 *  @param[in]  ccCondMask     Specifies zero, load, advance and capture
 *                             conditions. Bitwise OR of @ref DL_TIMER_CC_ZCOND,
 *                             @ref DL_TIMER_CC_LCOND, @ref DL_TIMER_CC_ACOND,
 *                             @ref DL_TIMER_CC_CCOND
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 */
void DL_Timer_setCaptureCompareCtl(GPTIMER_Regs *gptimer, uint32_t ccMode,
    uint32_t ccCondMask, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief   Gets Capture Compare Control configuration
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 *  @return Bitwise OR of @ref DL_TIMER_CC_MODE, @ref DL_TIMER_CC_ZCOND,
 *          @ref DL_TIMER_CC_LCOND, @ref DL_TIMER_CC_ACOND,
 *          @ref DL_TIMER_CC_CCOND
 *
 */
uint32_t DL_Timer_getCaptureCompareCtl(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Configures source for second capture compare down event
 *
 *  @param[in] gptimer       Pointer to the register overlay for the
 *                           peripheral
 *  @param[in] secCompDn     Specifies second capture compare down event
 *                           source. @ref DL_TIMER_SEC_COMP_DOWN_EVT
 *  @param[in] ccIndex       Index associated to capture compare register
 *                           @ref DL_TIMER_CC_INDEX.
 *
 */
void DL_Timer_setSecondCompSrcDn(GPTIMER_Regs *gptimer,
    DL_TIMER_SEC_COMP_DOWN_EVT secCompDn, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Gets source for second capture compare down event
 *
 *  @param[in] gptimer       Pointer to the register overlay for the
 *                           peripheral
 *  @param[in]  ccIndex      Index associated to capture compare register
 *                           @ref DL_TIMER_CC_INDEX.
 *  @return @ref DL_TIMER_SEC_COMP_DOWN_EVT
 */
DL_TIMER_SEC_COMP_DOWN_EVT DL_Timer_getSecondCompSrcDn(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Configures source for second capture compare up event
 *
 *  @param[in] gptimer       Pointer to the register overlay for the
 *                           peripheral
 *  @param[in] secCompUp     Specifies second capture compare up event
 *                           source. @ref DL_TIMER_SEC_COMP_UP_EVT
 *  @param[in] ccIndex       Index associated to capture compare register
 *                           @ref DL_TIMER_CC_INDEX.
 *
 */
void DL_Timer_setSecondCompSrcUp(GPTIMER_Regs *gptimer,
    DL_TIMER_SEC_COMP_UP_EVT secCompUp, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Gets source for second capture compare down event
 *
 *  @param[in] gptimer       Pointer to the register overlay for the
 *                           peripheral
 *  @param[in]  ccIndex      Index associated to capture compare register
 *                           @ref DL_TIMER_CC_INDEX.
 *  @return @ref DL_TIMER_SEC_COMP_UP_EVT
 */
DL_TIMER_SEC_COMP_UP_EVT DL_Timer_getSecondCompSrcUp(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Enables suppression of compare event if repeat counter is not equal to
 *         zero
 *
 *  @param[in] gptimer       Pointer to the register overlay for the
 *                           peripheral
 *  @param[in]  ccIndex      Index associated to capture compare register
 *                           @ref DL_TIMER_CC_INDEX.
 */
void DL_Timer_enableSuppressionOfCompEvent(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Disables suppression of compare event if repeat counter is not equal
 *         to zero
 *
 *  @param[in] gptimer       Pointer to the register overlay for the
 *                           peripheral
 *  @param[in]  ccIndex      Index associated to capture compare register
 *                           @ref DL_TIMER_CC_INDEX.
 */
void DL_Timer_disableSuppressionOfCompEvent(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Configures capture compare shadow register update method
 *
 *  @param[in] gptimer       Pointer to the register overlay for the
 *                           peripheral
 *  @param[in] ccUpdtMode    Specifies capture compare shadow register update
 *                           method. @ref DL_TIMER_CC_UPDATE_METHOD
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 */
void DL_Timer_setCaptCompUpdateMethod(GPTIMER_Regs *gptimer,
    DL_TIMER_CC_UPDATE_METHOD ccUpdtMode, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Gets capture compare shadow register update method
 *
 *  @param[in] gptimer       Pointer to the register overlay for the
 *                           peripheral
 *  @param[in]  ccIndex      Index associated to capture compare register
 *                           @ref DL_TIMER_CC_INDEX.
 * @return @ref DL_TIMER_CC_UPDATE_METHOD
 */
DL_TIMER_CC_UPDATE_METHOD DL_Timer_getCaptCompUpdateMethod(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief     Sets Capture Compare Output Control
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccpIV          Specifies the logical value put on the CCP
 *                             output while the output is disabled
 *                             @ref DL_TIMER_CC_OCTL_INIT_VAL
 *  @param[in]  ccpOInv        Specifies if the he output as selected by ccpo is
 *                             inverted. @ref DL_TIMER_CC_OCTL_INV_OUT
 *  @param[in]  ccpO           CCP Output Source @ref DL_TIMER_CC_OCTL_SRC
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 */
void DL_Timer_setCaptureCompareOutCtl(GPTIMER_Regs *gptimer, uint32_t ccpIV,
    uint32_t ccpOInv, uint32_t ccpO, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief    Gets Capture Compare Output Control
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 *  @return Bitwise OR of @ref DL_TIMER_CC_OCTL_INIT_VAL,
 *          @ref DL_TIMER_CC_OCTL_INV_OUT, @ref DL_TIMER_CC_OCTL_SRC
 *
 */
uint32_t DL_Timer_getCaptureCompareOutCtl(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief     Sets actions of the signal generator
 *
 *  @param[in] gptimer       Pointer to the register overlay for the
 *                           peripheral
 *  @param[in] actionsMask   Bit mask of signal generator actions. Bitwise OR of
 *                           @ref DL_TIMER_CC_SWFRCACT_CMPL, @ref DL_TIMER_CC_SWFRCACT,
 *                           @ref DL_TIMER_CC_CC2UACT, @ref DL_TIMER_CC_CC2DACT,
 *                           @ref DL_TIMER_CC_FEXACT, @ref DL_TIMER_CC_FENACT,
 *                           @ref DL_TIMER_CC_CUACT, @ref DL_TIMER_CC_CDACT,
 *                           @ref DL_TIMER_CC_LACT, @ref DL_TIMER_CC_ZACT,
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 */
void DL_Timer_setCaptureCompareAction(
    GPTIMER_Regs *gptimer, uint32_t actionsMask, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief    Gets actions of the signal generator
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 *  @return Bitwise OR of @ref DL_TIMER_CC_SWFRCACT_CMPL, @ref DL_TIMER_CC_SWFRCACT,
 *          @ref DL_TIMER_CC_CC2UACT, @ref DL_TIMER_CC_CC2DACT,
 *          @ref DL_TIMER_CC_FEXACT, @ref DL_TIMER_CC_FENACT,
 *          @ref DL_TIMER_CC_CUACT, @ref DL_TIMER_CC_CDACT,
 *          @ref DL_TIMER_CC_LACT, @ref DL_TIMER_CC_ZACT.
 *
 */
uint32_t DL_Timer_getCaptureCompareAction(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief    Set second comparator down counting timer channel output action
 *
 *  The timer channel output will be set to selected
 *  @ref DL_TIMER_SEC_COMP_DOWN_ACT_SEL when the timer counter reaches the
 *  configured capture compare value configure by
 *  @sa DL_Timer_setSecondCompSrcDn
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  secCompDnAct   One of @ref DL_TIMER_SEC_COMP_DOWN_ACT_SEL.
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 */
void DL_Timer_setSecondCompActionDn(GPTIMER_Regs *gptimer,
    DL_TIMER_SEC_COMP_DOWN_ACT_SEL secCompDnAct, DL_TIMER_CC_INDEX ccIndex);
/**
 *  @brief    Gets second comparator down counting timer channel output action
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 *  @return @ref DL_TIMER_SEC_COMP_DOWN_ACT_SEL
 *
 */
DL_TIMER_SEC_COMP_DOWN_ACT_SEL DL_Timer_getSecondCompActionDn(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief    Sets second comparator up counting timer channel output action
 *
 *  The timer channel output will be set to selected
 *  @ref DL_TIMER_SEC_COMP_UP_ACT_SEL when the timer counter reaches the
 *  configured capture compare value configure by
 *  @sa DL_Timer_setSecondCompSrcUp
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  secCompUpAct   One of @ref DL_TIMER_SEC_COMP_UP_ACT_SEL.
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 */
void DL_Timer_setSecondCompActionUp(GPTIMER_Regs *gptimer,
    DL_TIMER_SEC_COMP_UP_ACT_SEL secCompUpAct, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief    Gets second comparator up counting timer channel output action
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 *  @return @ref DL_TIMER_SEC_COMP_UP_ACT_SEL
 *
 */
DL_TIMER_SEC_COMP_UP_ACT_SEL DL_Timer_getSecondCompActionUp(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Overrides the timer CCP output
 *
 *  @param[in]  gptimer       Pointer to the register overlay for the
 *                            peripheral
 *  @param[in]  out           Specifies the CCP output state.
 *                            @ref DL_TIMER_FORCE_OUT
 *  @param[in]  outComp       If timer insatance supports complementary output,
 *                            it allows to override complementary out also.
 *                            If timer instance doesn't support complementary
 *                            output, this parameter is ignored.
 *                            @ref DL_TIMER_FORCE_CMPL_OUT
 *  @param[in]  ccIndex       Index associated to capture compare register
 *                            @ref DL_TIMER_CC_INDEX.
 */
void DL_Timer_overrideCCPOut(GPTIMER_Regs *gptimer, DL_TIMER_FORCE_OUT out,
    DL_TIMER_FORCE_CMPL_OUT outComp, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief     Sets Capture Compare Input
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  inv            Specifies whether the selected input is
 *                             inverted. @ref DL_TIMER_CC_INPUT_INV
 *  @param[in]  isel           Selects the input source to the filter
 *                             input. @ref DL_TIMER_CC_IN_SEL
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 */
void DL_Timer_setCaptureCompareInput(GPTIMER_Regs *gptimer, uint32_t inv,
    uint32_t isel, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief    Gets Capture Compare Input
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 *  @return Bitwise OR of @ref DL_TIMER_CC_INPUT_FILT_CPV,
 *          @ref DL_TIMER_CC_INPUT_FILT_FP
 *
 */
uint32_t DL_Timer_getCaptureCompareInput(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief     Sets Capture Compare Input Filter
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  cpv            Specifies fitering mode.
 *                             @ref DL_TIMER_CC_INPUT_FILT_CPV
 *  @param[in]  fp             Specifies the filter period.
 *                             @ref DL_TIMER_CC_INPUT_FILT_FP
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 */
void DL_Timer_setCaptureCompareInputFilter(GPTIMER_Regs *gptimer, uint32_t cpv,
    uint32_t fp, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief    Gets Capture Compare Input Filter
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *
 *  @return Bitwise OR of @ref DL_TIMER_CC_INPUT_FILT_CPV,
 *          @ref DL_TIMER_CC_INPUT_FILT_FP
 *
 */
uint32_t DL_Timer_getCaptureCompareInputFilter(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Enables the capture compare input filter
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 */
void DL_Timer_enableCaptureCompareInputFilter(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Disables the capture compare input filter
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 */
void DL_Timer_disableCaptureCompareInputFilter(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief Checks if the capture compare input filter is enabled
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 *  @return Returns the status of capture compare input filter
 *
 *  @retval     true  capture compare input filter is enabled
 *  @retval     false capture compare input filter is disabled
 */
bool DL_Timer_isCaptureCompareInputFilterEnabled(
    GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex);

/**
 *  @brief     Sets dead band fall and raise delay
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  falldelay      The number of TIMCLK periods inserted between
 *                             the fall of CCPi and the rise of CCPBo. Valid
 *                             range [0- 4095]
 *  @param[in]  risedelay      The number of TIMCLK periods inserted
 *                             between the fall of CCPi and the rise of CCPAo.
 *                             Valid range [0- 4095].
 *  @param[in]  mode           Specifies the dead band insertion mode. One of
 *                             @ref DL_TIMER_DEAD_BAND_MODE
 *
 */
__STATIC_INLINE void DL_Timer_setDeadBand(GPTIMER_Regs *gptimer,
    uint16_t falldelay, uint16_t risedelay, uint32_t mode)
{
    gptimer->COUNTERREGS.DBCTL =
        (((uint32_t) falldelay << GPTIMER_DBCTL_FALLDELAY_OFS) |
            (uint32_t) risedelay | mode);
}

/**
 *  @brief    Gets dead band fall delay
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return Dead Band Fall delay in TIMCLK
 */
__STATIC_INLINE uint16_t DL_Timer_getDeadBandFallDelay(GPTIMER_Regs *gptimer)
{
    uint32_t temp =
        (gptimer->COUNTERREGS.DBCTL & GPTIMER_DBCTL_FALLDELAY_MASK) >>
        GPTIMER_DBCTL_FALLDELAY_OFS;

    return ((uint16_t) temp);
}

/**
 *  @brief    Gets dead band rise delay
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return Dead Band Rise delay in TIMCLK
 */
__STATIC_INLINE uint16_t DL_Timer_getDeadBandRiseDelay(GPTIMER_Regs *gptimer)
{
    return (uint16_t)(
        (gptimer->COUNTERREGS.DBCTL) & (GPTIMER_DBCTL_RISEDELAY_MASK));
}

/**
 *  @brief     Set External Trigger Event
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  trigSel        External Trigger Select
 *                             @ref DL_TIMER_EXT_TRIG_SEL
 *
 */
__STATIC_INLINE void DL_Timer_setExternalTriggerEvent(
    GPTIMER_Regs *gptimer, DL_TIMER_EXT_TRIG_SEL trigSel)
{
    DL_Common_updateReg(&gptimer->COUNTERREGS.TSEL, (uint32_t) trigSel,
        GPTIMER_TSEL_ETSEL_MASK);
}

/**
 *  @brief    Gets External Trigger Event
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return @ref DL_TIMER_EXT_TRIG_SEL
 *
 */
__STATIC_INLINE DL_TIMER_EXT_TRIG_SEL DL_Timer_getExternalTriggerEvent(
    GPTIMER_Regs *gptimer)
{
    uint32_t trigSel = gptimer->COUNTERREGS.TSEL & GPTIMER_TSEL_ETSEL_MASK;

    return (DL_TIMER_EXT_TRIG_SEL)(trigSel);
}

/**
 *  @brief     Enables external trigger
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 */
__STATIC_INLINE void DL_Timer_enableExternalTrigger(GPTIMER_Regs *gptimer)
{
    gptimer->COUNTERREGS.TSEL |= (GPTIMER_TSEL_TE_ENABLED);
}

/**
 *  @brief     Disables external trigger
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 */
__STATIC_INLINE void DL_Timer_disableExternalTrigger(GPTIMER_Regs *gptimer)
{
    gptimer->COUNTERREGS.TSEL &= ~(GPTIMER_TSEL_TE_ENABLED);
}

/**
 *  @brief     Checks if  external trigger is enabled
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return Returns the status of external trigger
 *
 *  @retval     true  external trigger is enabled
 *  @retval     false external trigger is disabled
 */
__STATIC_INLINE bool DL_Timer_isExternalTriggerEnabled(GPTIMER_Regs *gptimer)
{
    return ((gptimer->COUNTERREGS.TSEL & GPTIMER_TSEL_TE_MASK) ==
            GPTIMER_TSEL_TE_ENABLED);
}

/**
 *  @brief     Sets repeat counter value. Repeat counter feature is used to
 *             reduce interupt overhead.
 *  @note      <b>This feature is not supported by all TimerA instances.</b>
 *             Please refer to the "TIMx Configurations" table in the
 *             device specific datasheet to determine TimerA instances which
 *             support "Repeat Counter" configuration.
 *
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  repeatCount     Specifies repeat counter value
 *
 */
__STATIC_INLINE void DL_Timer_setRepeatCounter(
    GPTIMER_Regs *gptimer, uint8_t repeatCount)
{
    gptimer->COUNTERREGS.RCLD = (repeatCount);
}

/**
 *  @brief     Gets repeat counter value.
 *  @note      <b>This feature is not supported by all TimerA instances.</b>
 *             Please refer to the "TIMx Configurations" table in the
 *             device specific datasheet to determine TimerA instances which
 *             support "Repeat Counter" configuration.
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *
 *  @return Repeat counter value.
 *
 */
__STATIC_INLINE uint8_t DL_Timer_getRepeatCounter(GPTIMER_Regs *gptimer)
{
    return ((uint8_t)(gptimer->COUNTERREGS.RC & GPTIMER_RC_RC_MASK));
}

/**
 *  @brief     Enables phase load
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *
 */
__STATIC_INLINE void DL_Timer_enablePhaseLoad(GPTIMER_Regs *gptimer)
{
    gptimer->COUNTERREGS.CTRCTL |= (GPTIMER_CTRCTL_PLEN_ENABLED);
}

/**
 *  @brief     Disables phase load
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *
 *
 */
__STATIC_INLINE void DL_Timer_disablePhaseLoad(GPTIMER_Regs *gptimer)
{
    gptimer->COUNTERREGS.CTRCTL &= ~(GPTIMER_CTRCTL_PLEN_ENABLED);
}

/**
 *  @brief     Checks if phase load enabled
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @return Returns the status of phase load
 *
 *  @retval     true  phase load is enabled
 *  @retval     false phase load is disabled
 *
 */
__STATIC_INLINE bool DL_Timer_isPhaseLoadEnabled(GPTIMER_Regs *gptimer)
{
    return (GPTIMER_CTRCTL_PLEN_ENABLED ==
            (gptimer->COUNTERREGS.CTRCTL & GPTIMER_CTRCTL_PLEN_MASK));
}

/**
 *  @brief     Sets phase load value
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  value           Phase load value
 *
 */
__STATIC_INLINE void DL_Timer_setPhaseLoadValue(
    GPTIMER_Regs *gptimer, uint32_t value)
{
    gptimer->COUNTERREGS.PL = (value);
}

/**
 *  @brief     Gets phase load value
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *
 *  @return Phase load value
 */
__STATIC_INLINE uint32_t DL_Timer_getPhaseLoadValue(GPTIMER_Regs *gptimer)
{
    return ((uint32_t)(gptimer->COUNTERREGS.PL & GPTIMER_PL_PHASE_MASK));
}

/**
 *  @brief      Starts Timer Counter
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 */
__STATIC_INLINE void DL_Timer_startCounter(GPTIMER_Regs *gptimer)
{
    gptimer->COUNTERREGS.CTRCTL |= (GPTIMER_CTRCTL_EN_ENABLED);
}

/**
 *  @brief      Stops Timer Counter
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 */
__STATIC_INLINE void DL_Timer_stopCounter(GPTIMER_Regs *gptimer)
{
    gptimer->COUNTERREGS.CTRCTL &= ~(GPTIMER_CTRCTL_EN_ENABLED);
}

/**
 *  @brief      Check if timer is actively running
 *
 *  @param[in]  gptimer      Pointer to the register overlay for the
 *                            peripheral
 *
 *  @return     Returns the running status of the Timer
 *
 *  @retval     true  Timer is running
 *  @retval     false Timer is not running
 */
__STATIC_INLINE bool DL_Timer_isRunning(GPTIMER_Regs *gptimer)
{
    return ((gptimer->COUNTERREGS.CTRCTL & GPTIMER_CTRCTL_EN_MASK) ==
            GPTIMER_CTRCTL_EN_ENABLED);
}

/**
 *  @brief      Configure Quadrature Encoder Interface (QEI)
 *
 *  @post User should call @ref DL_Timer_setLoadValue and
 *  @ref DL_Timer_startCounter to complete the QEI Configuration.
 *  Refer to Timer TRM for more details.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  mode           Choose QEI input mode. One of @ref DL_TIMER_QEI_MODE
 *  @param[in]  invert         Control whether selected input is inverted.
 *                             One of @ref DL_TIMER_CC_INPUT_INV
 *  @param[in]  ccIndex        Index associated to capture compare register
 *                             @ref DL_TIMER_CC_INDEX.
 */
__STATIC_INLINE void DL_Timer_configQEI(GPTIMER_Regs *gptimer,
    DL_TIMER_QEI_MODE mode, uint32_t invert, DL_TIMER_CC_INDEX ccIndex)
{
    gptimer->COUNTERREGS.CCCTL_01[ccIndex] =
        GPTIMER_CCCTL_01_CCOND_CC_TRIG_RISE | GPTIMER_CCCTL_01_COC_CAPTURE;
    gptimer->COUNTERREGS.IFCTL_01[ccIndex] =
        GPTIMER_IFCTL_01_ISEL_CCPX_INPUT | invert;
    gptimer->COUNTERREGS.CTRCTL =
        (uint32_t) mode | GPTIMER_CTRCTL_CVAE_NOCHANGE |
        GPTIMER_CTRCTL_CM_UP_DOWN | GPTIMER_CTRCTL_REPEAT_REPEAT_1;
}

/**
 *  @brief      Configure Hall Input Mode
 *
 *  @note Refer to device datasheet to determine if timer instance supports
 *  this feature. Only TIMGx instances with QEI support should use this API.
 *
 *  @post User should call @ref DL_Timer_setLoadValue and
 *  @ref DL_Timer_startCounter to complete the Hall Input Mode Configuration.
 *  Refer to Timer TRM for more details.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 */
void DL_Timer_configQEIHallInputMode(GPTIMER_Regs *gptimer);

/**
 *  @brief      Get direction of Quadrature Encoder Interface (QEI) count
 *
 *  @param[in]  gptimer  Pointer to the register overlay for the
 *                       peripheral
 *  @retval     One of @ref DL_TIMER_QEI_DIRECTION values
 */
__STATIC_INLINE DL_TIMER_QEI_DIRECTION DL_Timer_getQEIDirection(
    GPTIMER_Regs *gptimer)
{
    uint32_t qeiDirection = gptimer->COUNTERREGS.QDIR & GPTIMER_QDIR_DIR_MASK;

    return (DL_TIMER_QEI_DIRECTION)(qeiDirection);
}

/**
  *  @brief     Sets Fault Configuration
  *
  *  @param[in]  gptimer        Pointer to the register overlay for the
  *                             peripheral
  *  @param[in]  faultConfMask  Specifies faults configuration. Bitwise OR of
  *                             @ref DL_TIMER_FAULT_CONFIG_TFIM,
  *                             @ref DL_TIMER_FAULT_CONFIG_FL,
  *                             @ref DL_TIMER_FAULT_CONFIG_FI,
  *                             @ref DL_TIMER_FAULT_CONFIG_FIEN
  *
  */
__STATIC_INLINE void DL_Timer_setFaultConfig(
    GPTIMER_Regs *gptimer, uint32_t faultConfMask)
{
    DL_Common_updateReg(&gptimer->COUNTERREGS.FCTL, faultConfMask,
        (GPTIMER_FCTL_TFIM_MASK | GPTIMER_FCTL_FL_MASK | GPTIMER_FCTL_FI_MASK |
            GPTIMER_FCTL_FIEN_MASK));
}

/**
  *  @brief     Gets Fault Configuration
  *
  *  @param[in]  gptimer        Pointer to the register overlay for the
  *                             peripheral
  *
  *  @return Bitwise OR value of @ref DL_TIMER_FAULT_CONFIG_TFIM,
  *          @ref DL_TIMER_FAULT_CONFIG_FL, @ref DL_TIMER_FAULT_CONFIG_FI,
  *          @ref DL_TIMER_FAULT_CONFIG_FIEN
  *
  */
__STATIC_INLINE uint32_t DL_Timer_getFaultConfig(GPTIMER_Regs *gptimer)
{
    return (gptimer->COUNTERREGS.FCTL &
            (GPTIMER_FCTL_FIEN_MASK | GPTIMER_FCTL_FI_MASK |
                GPTIMER_FCTL_FL_MASK | GPTIMER_FCTL_TFIM_MASK));
}

/**
  *  @brief Enables fault input detection
  *
  *  @param[in] gptimer   Pointer to the register overlay for the
  *                       peripheral
  */
__STATIC_INLINE void DL_Timer_enableFaultInput(GPTIMER_Regs *gptimer)
{
    gptimer->COUNTERREGS.FCTL |= (GPTIMER_FCTL_FIEN_ENABLED);
}

/**
  *  @brief Disables fault input detection
  *
  *  @param[in] gptimer   Pointer to the register overlay for the
  *                       peripheral
  */
__STATIC_INLINE void DL_Timer_disableFaultInput(GPTIMER_Regs *gptimer)
{
    gptimer->COUNTERREGS.FCTL &= ~(GPTIMER_FCTL_FIEN_ENABLED);
}

/**
  *  @brief Specifies if fault input is enabled
  *
  *  @param[in] gptimer   Pointer to the register overlay for the
  *                       peripheral
  *  @return  true  Fault input is enabled
  *  @return  false Fault input is disabled
  */
__STATIC_INLINE bool DL_Timer_isFaultInputEnabled(GPTIMER_Regs *gptimer)
{
    return (GPTIMER_FCTL_FIEN_ENABLED ==
            (gptimer->COUNTERREGS.FCTL & GPTIMER_FCTL_FIEN_MASK));
}

/**
 *  @brief Enables source clock fault detection
 *
 *  @param[in] gptimer Pointer to the register overlay for the
 *                     peripheral
 */
__STATIC_INLINE void DL_Timer_enableClockFaultDetection(GPTIMER_Regs *gptimer)
{
    gptimer->COMMONREGS.FSCTL |= (GPTIMER_FSCTL_FCEN_DISABLE);
}

/**
 *  @brief Disables source clock fault detection
 *
 *  @param[in] gptimer Pointer to the register overlay for the
 *                     peripheral
 */
__STATIC_INLINE void DL_Timer_disableClockFaultDetection(GPTIMER_Regs *gptimer)
{
    gptimer->COMMONREGS.FSCTL &= ~(GPTIMER_FSCTL_FCEN_DISABLE);
}

/**
 *  @brief Specifies if source clock fault detection is enabled
 *
 *  @param[in] gptimer Pointer to the register overlay for the
 *                    peripheral
 *  @return true if source clock fault detection is enabled
 *  @return false if source clock fault detection is disabled
 */
__STATIC_INLINE bool DL_Timer_isClockFaultDetectionEnabled(
    GPTIMER_Regs *gptimer)
{
    return (GPTIMER_FSCTL_FCEN_ENABLE ==
            (gptimer->COMMONREGS.FSCTL & GPTIMER_FSCTL_FCEN_MASK));
}

/**
  *  @brief Configures the fault source and and fault input mode
  *
  *  @param[in] gptimer Pointer to the register overlay for the
  *                     peripheral
  *  @param[in] source  Selects fault source and and fault input mode. One of
  *                     @ref DL_TIMER_FAULT_SOURCE.
  *
  */
void DL_Timer_setFaultSourceConfig(GPTIMER_Regs *gptimer, uint32_t source);

/**
  *  @brief
  *
  *  @param[in] gptimer Pointer to the register overlay for the
  *                     peripheral
  *  @return The fault source and and fault input mode. One of
  *          @ref DL_TIMER_FAULT_SOURCE.
  */
uint32_t DL_Timer_getFaultSourceConfig(GPTIMER_Regs *gptimer);

/**
  *  @brief     Set Fault Input Filtering Configuration
  *
  *  @param[in]  gptimer        Pointer to the register overlay for the
  *                             peripheral
  *  @param[in]  filten         Specifies input is filter mode
  *                             @ref DL_TIMER_FAULT_FILT
  *  @param[in]  cpv            Specifies input filter type
  *                             @ref DL_TIMER_FAULT_FILTER_CPV
  *  @param[in]  fp             Specifies sample period for the input filter
  *                             @ref DL_TIMER_FAULT_FILTER_FP
  *
  */
__STATIC_INLINE void DL_Timer_setFaultInputFilterConfig(
    GPTIMER_Regs *gptimer, uint32_t filten, uint32_t cpv, uint32_t fp)
{
    gptimer->COUNTERREGS.FIFCTL = (filten | cpv | fp);
}

/**
  *  @brief     Get Fault Input Filtering Configuration
  *
  *  @param[in]  gptimer        Pointer to the register overlay for the
  *                             peripheral
  *  @return Bitwise OR of @ref DL_TIMER_FAULT_FILT,
  *          @ref DL_TIMER_FAULT_FILTER_CPV and  @ref DL_TIMER_FAULT_FILTER_FP
  *
  */
__STATIC_INLINE uint32_t DL_Timer_getFaultInputFilterConfig(
    GPTIMER_Regs *gptimer)
{
    return (gptimer->COUNTERREGS.FIFCTL);
}

/**
 *  @brief     Configures output behavior upon fault entry and exit
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  faultEntry      Specifies the fault entry behavior.
 *                              One of @ref DL_TIMER_FAULT_ENTRY_CCP
 *  @param[in]  faultExit       Specifies the fault exit behavior.
 *                              One of @ref DL_TIMER_FAULT_EXIT_CCP
 *  @param[in]  ccIndex         Index associated to capture compare register
 *                              @ref DL_TIMER_CC_INDEX.
 *
 */
__STATIC_INLINE void DL_Timer_configFaultOutputAction(GPTIMER_Regs *gptimer,
    DL_TIMER_FAULT_ENTRY_CCP faultEntry, DL_TIMER_FAULT_EXIT_CCP faultExit,
    DL_TIMER_CC_INDEX ccIndex)
{
    DL_Common_updateReg(&gptimer->COUNTERREGS.CCACT_01[ccIndex],
        ((uint32_t) faultEntry | (uint32_t) faultExit),
        (GPTIMER_CCACT_01_FEXACT_MASK | GPTIMER_CCACT_01_FENACT_MASK));
}

/**
 *  @brief     Configures timer counter behavior upon fault entry and exit
 *
 *  @param[in]  gptimer         Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  faultEntry      Specifies the fault entry behavior.
 *                              One of @ref DL_TIMER_FAULT_ENTRY_CTR
 *  @param[in]  faultExit       Specifies the fault exit behavior.
 *                              One of @ref DL_TIMER_FAULT_EXIT_CTR
 *
 */
__STATIC_INLINE void DL_Timer_configFaultCounter(GPTIMER_Regs *gptimer,
    DL_TIMER_FAULT_ENTRY_CTR faultEntry, DL_TIMER_FAULT_EXIT_CTR faultExit)
{
    DL_Common_updateReg(&gptimer->COUNTERREGS.CTRCTL,
        ((uint32_t) faultEntry | (uint32_t) faultExit),
        (GPTIMER_CTRCTL_FRB_MASK | GPTIMER_CTRCTL_FB_MASK));
}

/**
 *  @brief      Enable timer interrupts
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_TIMER_INTERRUPT.
 */
__STATIC_INLINE void DL_Timer_enableInterrupt(
    GPTIMER_Regs *gptimer, uint32_t interruptMask)
{
    gptimer->CPU_INT.IMASK |= interruptMask;
}

/**
 *  @brief      Disable timer interrupts
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_TIMER_INTERRUPT.
 */
__STATIC_INLINE void DL_Timer_disableInterrupt(
    GPTIMER_Regs *gptimer, uint32_t interruptMask)
{
    gptimer->CPU_INT.IMASK &= ~(interruptMask);
}

/**
 *  @brief      Check which timer interrupts are enabled
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TIMER_INTERRUPT.
 *
 *  @return     Which of the requested timer interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_TIMER_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_Timer_getEnabledInterrupts(
    GPTIMER_Regs *gptimer, uint32_t interruptMask)
{
    return (gptimer->CPU_INT.IMASK & interruptMask);
}

/**
 *  @brief      Check interrupt flag of enabled timer interrupts
 *
 *  Checks if any of the timer interrupts that were previously enabled are
 *  pending.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TIMER_INTERRUPT.
 *
 *  @return     Which of the requested timer interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_TIMER_INTERRUPT values
 *
 *  @sa         DL_Timer_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_Timer_getEnabledInterruptStatus(
    GPTIMER_Regs *gptimer, uint32_t interruptMask)
{
    return (gptimer->CPU_INT.MIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of any timer interrupt
 *
 *  Checks if any of the timer interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TIMER_INTERRUPT.
 *
 *  @return     Which of the requested timer interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_TIMER_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_Timer_getRawInterruptStatus(
    GPTIMER_Regs *gptimer, uint32_t interruptMask)
{
    return (gptimer->CPU_INT.RIS & interruptMask);
}

/**
 *  @brief      Get highest priority pending timer interrupt
 *
 *  Checks if any of the timer interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *
 *  @return     The highest priority pending timer interrupt. One of
 *              @ref DL_TIMER_IIDX
 */
__STATIC_INLINE DL_TIMER_IIDX DL_Timer_getPendingInterrupt(
    GPTIMER_Regs *gptimer)
{
    return ((DL_TIMER_IIDX) gptimer->CPU_INT.IIDX);
}

/**
 *  @brief      Clear pending timer interrupts
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_TIMER_INTERRUPT.
 */
__STATIC_INLINE void DL_Timer_clearInterruptStatus(
    GPTIMER_Regs *gptimer, uint32_t interruptMask)
{
    gptimer->CPU_INT.ICLR = interruptMask;
}

/**
 *  @brief Sets the event publisher channel id
 *
 *  @param[in]  gptimer Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  index   Specifies the register event index to be configured
 *  @param[in]  chanID  Channel ID number. Valid range 0-15. If ChanID == 0
 *                      publisher is disconnected.
 */
__STATIC_INLINE void DL_Timer_setPublisherChanID(
    GPTIMER_Regs *gptimer, DL_TIMER_PUBLISHER_INDEX index, uint8_t chanID)
{
    volatile uint32_t *pReg = &gptimer->FPUB_0;

    *(pReg + (uint32_t) index) = (chanID & GPTIMER_FPUB_0_CHANID_MAXIMUM);
}

/**
 *  @brief Gets the event publisher channel id
 *
 *  @param[in]  gptimer Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  index  Specifies the register event index to be configured
 *
 *  @return     Event publisher channel ID
 *
 */
__STATIC_INLINE uint8_t DL_Timer_getPublisherChanID(
    GPTIMER_Regs *gptimer, DL_TIMER_PUBLISHER_INDEX index)
{
    volatile uint32_t *pReg = &gptimer->FPUB_0;

    return (
        (uint8_t)(*(pReg + (uint32_t) index) & GPTIMER_FPUB_0_CHANID_MASK));
}

/**
 *  @brief Sets the event subscriber channel id
 *
 *  @param[in]  gptimer Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  index   Specifies the register event index to be configured
 *  @param[in]  chanID  Channel ID number. Valid range 0-15. If ChanID == 0
 *                      subscriber is disconnected.
 */
__STATIC_INLINE void DL_Timer_setSubscriberChanID(
    GPTIMER_Regs *gptimer, DL_TIMER_SUBSCRIBER_INDEX index, uint8_t chanID)
{
    volatile uint32_t *pReg = &gptimer->FSUB_0;

    *(pReg + (uint32_t) index) = (chanID & GPTIMER_FSUB_0_CHANID_MAXIMUM);
}

/**
 *  @brief Gets the event subscriber channel id
 *
 *  @param[in]  gptimer Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  index  Specifies the register event index to be configured
 *
 *  @return     Event subscriber channel ID
 *
 */
__STATIC_INLINE uint8_t DL_Timer_getSubscriberChanID(
    GPTIMER_Regs *gptimer, DL_TIMER_SUBSCRIBER_INDEX index)
{
    volatile uint32_t *pReg = &gptimer->FSUB_0;

    return (
        (uint8_t)(*(pReg + (uint32_t) index) & GPTIMER_FSUB_0_CHANID_MASK));
}

/**
 *  @brief      Enable timer event
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  index          Specifies the register event index to be
 *                             configured
 *  @param[in]  eventMask      Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_TIMER_EVENT.
 */
__STATIC_INLINE void DL_Timer_enableEvent(
    GPTIMER_Regs *gptimer, DL_TIMER_EVENT_ROUTE index, uint32_t eventMask)
{
    volatile uint32_t *pReg = (volatile uint32_t *) &gptimer->GEN_EVENT0.IMASK;

    *(pReg + (uint32_t) index) |= (eventMask);
}

/**
 *  @brief      Disable timer event
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  index          Specifies the register event index to be
 *                             configured
 *  @param[in]  eventMask      Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_TIMER_EVENT.
 */
__STATIC_INLINE void DL_Timer_disableEvent(
    GPTIMER_Regs *gptimer, DL_TIMER_EVENT_ROUTE index, uint32_t eventMask)
{
    volatile uint32_t *pReg = (volatile uint32_t *) &gptimer->GEN_EVENT0.IMASK;

    *(pReg + (uint32_t) index) &= ~(eventMask);
}

/**
 *  @brief      Check which timer events are enabled
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  index          Specifies the register event index to be
 *                             configured
 *  @param[in]  eventMask      Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TIMER_EVENT.
 *
 *  @return     Which of the requested timer interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_TIMER_EVENT values
 */
__STATIC_INLINE uint32_t DL_Timer_getEnabledEvents(
    GPTIMER_Regs *gptimer, DL_TIMER_EVENT_ROUTE index, uint32_t eventMask)
{
    volatile uint32_t *pReg = (volatile uint32_t *) &gptimer->GEN_EVENT0.IMASK;

    return ((*(pReg + (uint32_t) index) & eventMask));
}

/**
 *  @brief      Check event flag of enabled timer event
 *
 *  Checks if any of the timer events that were previously enabled are
 *  pending.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  index          Specifies the register event index to be
 *                             configured
 *  @param[in]  eventMask      Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TIMER_EVENT.
 *
 *  @return     Which of the requested timer interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_TIMER_EVENT values
 *
 *  @sa         DL_Timer_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_Timer_getEnabledEventStatus(
    GPTIMER_Regs *gptimer, DL_TIMER_EVENT_ROUTE index, uint32_t eventMask)
{
    const volatile uint32_t *pReg =
        (const volatile uint32_t *) &gptimer->GEN_EVENT0.MIS;

    return ((*(pReg + (uint32_t) index) & eventMask));
}

/**
 *  @brief      Check interrupt flag of any timer event
 *
 *  Checks if any events are pending. Events do not have to
 *  be previously enabled.
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  index          Specifies the register event index to be
 *                             configured
 *  @param[in]  eventMask      Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_TIMER_EVENT.
 *
 *  @return     Which of the requested timer interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_TIMER_EVENT values
 */
__STATIC_INLINE uint32_t DL_Timer_getRawEventsStatus(
    GPTIMER_Regs *gptimer, DL_TIMER_EVENT_ROUTE index, uint32_t eventMask)
{
    const volatile uint32_t *pReg =
        (const volatile uint32_t *) &gptimer->GEN_EVENT0.RIS;

    return ((*(pReg + (uint32_t) index) & eventMask));
}

/**
 *  @brief      Clear pending timer events
 *
 *  @param[in]  gptimer        Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  index          Specifies the register event index to be
 *                             configured
 *  @param[in]  eventMask  Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_TIMER_EVENT.
 */
__STATIC_INLINE void DL_Timer_clearEventsStatus(
    GPTIMER_Regs *gptimer, DL_TIMER_EVENT_ROUTE index, uint32_t eventMask)
{
    volatile uint32_t *pReg = (volatile uint32_t *) &gptimer->GEN_EVENT0.ICLR;

    *(pReg + (uint32_t) index) |= (eventMask);
}

/**
 *  @brief      Saves Timer configuration before entering STOP or STANDBY mode.
 *              Only necessary for PG 1.0 silicon. Timer must be in IDLE state
 *              before calling this API. Timer can be put IDLE state by calling
 *              DL_TimerG_stopCounter or DL_TimerH_stopCounter.
 *
 *  @param[in]  gptimer  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr      Configuration backup setup structure. See
 *                       @ref DL_Timer_backupConfig.
 *
 *  @retval     FALSE if a configuration already exists in ptr (will not be
 *              overwritten). TRUE if a configuration was successfully saved
 *
 */
bool DL_Timer_saveConfiguration(
    GPTIMER_Regs *gptimer, DL_Timer_backupConfig *ptr);

/**
 *  @brief      Restore Timer configuration after leaving STOP or STANDBY mode.
 *              Only necessary for PG 1.0 silicon.
 *
 *  @param[in]  gptimer  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  ptr      Configuration backup setup structure. See
 *                       @ref DL_Timer_backupConfig.
 *  @param[in]  restoreCounter If true timer counter value is also
 *                             restored (e.g. resume counts of edge counts).
 *                             If false timer counter is not restored.
 *
 *  @retval     FALSE if a configuration does not exist in ptr (will not be
 *              loaded). TRUE if a configuration successfully loaded
 *
 */
bool DL_Timer_restoreConfiguration(
    GPTIMER_Regs *gptimer, DL_Timer_backupConfig *ptr, bool restoreCounter);

/**
 *  @brief      Configures timer behavior when the core is halted.
 *
 *  @param[in]  gptimer  Pointer to the register overlay for the peripheral
 *
 *  @param[in]  haltMode Timer halt behavior. One of @ref DL_TIMER_CORE_HALT.
 *
 */
__STATIC_INLINE void DL_Timer_setCoreHaltBehavior(
    GPTIMER_Regs *gptimer, DL_TIMER_CORE_HALT haltMode)
{
    gptimer->PDBGCTL = ((uint32_t) haltMode & (GPTIMER_PDBGCTL_FREE_MASK |
                                                  GPTIMER_PDBGCTL_SOFT_MASK));
}

/**
 *  @brief      Get timer behavior when the core is halted.
 *
 *  @param[in]  gptimer  Pointer to the register overlay for the peripheral
 *
 *  @return     Timer bahvior when core is halted. One of
 *              @ref DL_TIMER_CORE_HALT
 *
 */
__STATIC_INLINE DL_TIMER_CORE_HALT DL_Timer_getCoreHaltBehavior(
    GPTIMER_Regs *gptimer)
{
    uint32_t haltMode = (gptimer->PDBGCTL & (GPTIMER_PDBGCTL_FREE_MASK |
                                                GPTIMER_PDBGCTL_SOFT_MASK));

    return (DL_TIMER_CORE_HALT)(haltMode);
}

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_TIMER_A__ || __MSPM0_HAS_TIMER_G__ */

#else
#warning \
    "TI highly recommends accessing timer with dl_timera and dl_timerg only."
#endif /* ti_dl_dl_timera__include ti_dl_dl_timerg__include*/

#endif /* ti_dl_dl_timer__include */
/** @}*/
