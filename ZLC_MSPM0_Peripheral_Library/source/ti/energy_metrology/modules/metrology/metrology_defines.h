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

/*!****************************************************************************
 *  @file       metrology_defines.h
 *  @brief      Defines constants enums used in Metrology module
 *
 *  @anchor metrology_defines_h
 *  # Overview
 *
 *  Defines constants enums used in Metrology module
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup Metrology
 * @{
 */

#ifndef _METROLOGY_DEFINES_H_
#define _METROLOGY_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdbool.h"
#include "hal.h"
#include "template.h"

/*! @brief Defines Vrms Support */
#define VRMS_SUPPORT                                    0x00000001
/*! @brief Defines Irms Support */
#define IRMS_SUPPORT                                    0x00000002
/*! @brief Defines Active Power Support   */
#define ACTIVE_POWER_SUPPORT                            0x00000006
/*! @brief Defines Reactive Power Support */
#define REACTIVE_POWER_SUPPORT                          0x0000000A
/*! @brief Defines Apparent Power Support */
#define APPARENT_POWER_SUPPORT                          0x0000000E
/*! @brief Defines Fundamental Vrms Support */
#define FUNDAMENTAL_VRMS_SUPPORT                        0x00000011
/*! @brief Defines Fundamental Irms Support */
#define FUNDAMENTAL_IRMS_SUPPORT                        0x000000EE
/*! @brief Defines Fundamental Active Power Support   */
#define FUNDAMENTAL_ACTIVE_POWER_SUPPORT                0x00000046
/*! @brief Defines Fundamental Reactive Power Support */
#define FUNDAMENTAL_REACTIVE_POWER_SUPPORT              0x0000008A
/*! @brief Defines Fundamental Apparent Power Support */
#define FUNDAMENTAL_APPARENT_POWER_SUPPORT              0x000000CE
/*! @brief Defines Active Energy Support */
#define ACTIVE_ENERGY_SUPPORT                           0x00000106
/*! @brief Defines Reactive Energy Support */
#define REACTIVE_ENERGY_SUPPORT                         0x0000020A
/*! @brief Defines Apparent Energy Support */
#define APPARENT_ENERGY_SUPPORT                         0x0000040E
/*! @brief Defines Fundamental Active Energy Support   */
#define FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT               0x00000846
/*! @brief Defines Fundamental Reactive Energy Support */
#define FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT             0x0000108A
/*! @brief Defines Fundamental Apparent Energy Support */
#define FUNDAMENTAL_APPARENT_ENERGY_SUPPORT             0x000020CE
/*! @brief Defines Power factor Support */
#define POWER_FACTOR_SUPPORT                            0x00000200
/*! @brief Defines Power factor angle Support */
#define POWER_FACTOR_ANGLE_SUPPORT                      0x00000300
/*! @brief Defines voltage under deviation Support */
#define VOLTAGE_UNDER_DEVIATION                         0x00000041
/*! @brief Defines voltage over deviation Support */
#define VOLTAGE_OVER_DEVIATION                          0x00000081
/*! @brief Defines sag swell Support */
#define SAG_SWELL_SUPPORT                               0x00000801
/*! @brief Defines voltage THD Support */
#define VOLTAGE_THD_SUPPORT                             0x00000015
/*! @brief Defines current THD Support */
#define CURRENT_THD_SUPPORT                             0x0000002A
/*! @brief Defines frequency Support */
#define FREQUENCY_SUPPORT                               0x00000105
/*! @brief Defines Total Active Power Support */
#define TOTAL_ACTIVE_POWER_SUPPORT                      0x00000006
/*! @brief Defines Total Reactive Power Support */
#define TOTAL_REACTIVE_POWER_SUPPORT                    0x0000000A
/*! @brief Defines Total Apparent Power Support */
#define TOTAL_APPARENT_POWER_SUPPORT                    0x0000000E
/*! @brief Defines Total Fundamental Active Power Support */
#define TOTAL_FUNDAMENTAL_ACTIVE_POWER_SUPPORT          0x00000046
/*! @brief Defines Total Fundamental Reactive Power Support */
#define TOTAL_FUNDAMENTAL_REACTIVE_POWER_SUPPORT        0x0000008A
/*! @brief Defines Total Fundamental Apparent Power Support */
#define TOTAL_FUNDAMENTAL_APPARENT_POWER_SUPPORT        0x000000CE
/*! @brief Defines Total Active Energy Support */
#define TOTAL_ACTIVE_ENERGY_SUPPORT                     0x00000106
/*! @brief Defines Total Reactive Energy Support */
#define TOTAL_REACTIVE_ENERGY_SUPPORT                   0x0000020A
/*! @brief Defines Total Apparent Energy Support */
#define TOTAL_APPARENT_ENERGY_SUPPORT                   0x0000040E
/*! @brief Defines Total Fundamental Active Energy Support */
#define TOTAL_FUNDAMENTAL_ACTIVE_ENERGY_SUPPORT         0x00000846
/*! @brief Defines Total Fundamental Reactive Energy Support */
#define TOTAL_FUNDAMENTAL_REACTIVE_ENERGY_SUPPORT       0x0000108A
/*! @brief Defines Total Fundamental Apparent Energy Support */
#define TOTAL_FUNDAMENTAL_APPARENT_ENERGY_SUPPORT       0x000020CE
/*! @brief Defines Line to Line voltage Support */
#define LINETOLINE_VOLTAGE_SUPPORT                      0x00000201
/*! @brief Defines Fundamental Line to Line voltage Support */
#define FUNDAMENTAL_LINETOLINE_VOLTAGE_SUPPORT          0x00000405
/*! @brief Defines Aggregate power factor Support */
#define AGGREGATE_POWER_FACTOR                          0x00000020
/*! @brief Defines Current vector sum Support */
#define CURRENT_VECTOR_SUM                              0x00000010
/*! @brief Defines Phase to Phase angle Support */
#define PHASE_TO_PHASE_ANGLE_SUPPORT                    0x00000040
/*! @brief Defines Neutral Support */
#define NEUTRAL_MONITOR_SUPPORT                         0x00001000
/*! @brief Defines Minimum Voltage ADC input in per units   */
#define V_ADC_MIN                       _IQ23(-0.9)
/*! @brief Defines Maximum Voltage ADC input in per units   */
#define V_ADC_MAX                       _IQ23(0.9)
/*! @brief Defines Minimum Current ADC input in per units   */
#define I_ADC_MIN                       _IQ23(-0.9)
/*! @brief Defines Maximum Current ADC input in per units   */
#define I_ADC_MAX                       _IQ23(0.9)
/*! @brief Defines Number of Overload hits      */
#define ENDSTOP_HITS_FOR_OVERLOAD       (20)
/*! @brief Defines Minimum Voltage Slew rate    */
#define MAX_PER_SAMPLE_VOLTAGE_SLEW     _IQ23(1)
/*! @brief Defines Maximum number of FIR table elements */
#define PHASE_SHIFT_FIR_TABLE_ELEMENTS  (256)
/*! @brief Defines Voltage history array mask   */
#define V_HISTORY_MASK                  (0x3F)
/*! @brief Defines RMS Voltage over range value */
#define RMS_VOLTAGE_OVERRANGE           (0xFFFFFF)
/*! @brief Defines RMS Current over range value */
#define RMS_CURRENT_OVERRANGE           (0xFFFFFF)
/*! @brief Defines RMS Power over range value   */
#define POWER_OVERRANGE                 (0xFFFFFF)
/*! @brief Defines minimum power measured in watts  */
#define TOTAL_RESIDUAL_POWER_CUTOFF     _IQ13(0.5)
/*! @brief Defines current history samples to be stored */
#define I_HISTORY_STEPS                 2
/*! @brief Defines sampling rate    */
#define SAMPLES_PER_SECOND              SAMPLE_RATE
/*! @brief Defines samples per 10 seconds   */
#define INT_SAMPLES_PER_10_SECONDS      (SAMPLES_PER_SECOND * 10)
/*!
 * @brief Defines Energy threshold value 100 milliwatts-hr`
 *        100 milliwatt-hr = 360 watt-sec
 */
#define ENERGY_100mWATT_HOUR_THRESHOLD  (360)
/*! @brief Defines Energy threshold in IQ   */
#define ENERGY_100mWATT_HOUR_THRESHOLD_IQ  _IQ13(360)
/*! @brief Mains nominal voltage in IQ15 format */
#define MAINS_NOMINAL_VOLTAGE_IQ19      _IQ19(MAINS_NOMINAL_VOLTAGE)
/*! @brief Mains basic current  */
#define MAINS_BASIS_CURRENT             10
/*! @brief Mians maximum current */
#define MAINS_MAXIMUM_CURRENT           100
/*! @brief Defines sag threshold value in percentage    */
#define SAG_THRESHOLD                   (20)
/*! @brief Defines sag hysteresis value in milli volts  */
#define SAG_HYSTERESIS                  _IQ15(1)
/*! @brief Defines swell threshold value in percentage    */
#define SWELL_THRESHOLD                 (20)
/*! @brief Defines swell hysteresis value in milli volts  */
#define SWELL_HYSTERESIS                _IQ19(1)
/*! @brief Defines minimum voltage in milli volts to be considered as sag   */
#define MIN_SAG_VOLTAGE                 _IQ19(100)
/*! @brief Hysteresis voltage amount for an event to be considered a voltage interruption.  */
#define INTERRUPTION_HYSTERESIS         _IQ19(100)
/*! @brief Defines minimum samples per cycle    */
#define METROLOGY_MIN_CYCLE_SAMPLES         (256 * SAMPLE_RATE / MAINS_MAX_FREQUENCY)
/*! @brief Defines maximum samples per cycle    */
#define METROLOGY_MAX_CYCLE_SAMPLES         (256 * SAMPLE_RATE / MAINS_MIN_FREQUENCY)
/*! @brief Defines two times the samples per cycle  */
#define TWICE_CYCLES_PER_NOMINAL_FREQUENCY  (2 * SAMPLES_PER_SECOND/MAINS_NOMINAL_FREQUENCY)
/*! @brief Defines cycles per computations  */
#if(MAINS_NOMINAL_FREQUENCY == 50)
    #define CYCLES_PER_COMPUTATION          (10)
#else
    #define CYCLES_PER_COMPUTATION          (12)
#endif
/*!
 * @brief The duration of the LED on time for an energy pulse. This is measured in ADC samples,
 *        giving a duration = (ENERGY_PULSE_DURATION - 1)/SAMPLE_RATE). The maximum allowed is 255.
 */
#define ENERGY_PULSE_DURATION               (20)
/*! @brief Defines active energy pulses per kwh */
#define TOTAL_ACTIVE_ENERGY_PULSES_PER_KW_HOUR      (6400)
/*! @brief Defines reactive energy pulses per kwh */
#define TOTAL_REACTIVE_ENERGY_PULSES_PER_KW_HOUR    (6400)
/*! @brief Defines active energy pulse threshlod */
#define TOTAL_ACTIVE_ENERGY_PULSE_THRESHOLD         ((int64_t)ENERGY_100mWATT_HOUR_THRESHOLD * 1000L * SAMPLE_RATE * 10000LL)/(TOTAL_ACTIVE_ENERGY_PULSES_PER_KW_HOUR)
/*! @brief Defines reactive energy pulse threshlod */
#define TOTAL_REACTIVE_ENERGY_PULSE_THRESHOLD       ((int64_t)ENERGY_100mWATT_HOUR_THRESHOLD * 1000L * SAMPLE_RATE * 10000LL)/(TOTAL_REACTIVE_ENERGY_PULSES_PER_KW_HOUR)
/*! @brief Defines sin table bit resolution */
#define METROLOGY_DDS_BIT_RESOLUTION     8
/*! @brief Defines sin table resolution */
#define METROLOGY_DDS_TABLE_RESOLUTION   24
/*! @brief Defines steps in sin table   */
#define METROLOGY_DDS_STEPS   (1 << METROLOGY_DDS_BIT_RESOLUTION)
/*! @brief Defines DDS bit shifted  */
#define METROLOGY_DDS_BIT_SHIFT   (32 - 2 - METROLOGY_DDS_BIT_RESOLUTION)

/*! @enum PHASES    */
typedef enum
{
#ifdef SINGLE_PHASE_SUPPORT
    /*! @brief Phase 1 */
    PHASE_ONE = 0,
#endif

#if defined(SPLIT_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT)
    /*! @brief Phase 1 */
    PHASE_ONE = 0,
    /*! @brief Phase 2 */
    PHASE_TWO,
#endif

#ifdef THREE_PHASE_SUPPORT
    /*! @brief Phase 1 */
    PHASE_ONE = 0,
    /*! @brief Phase 2 */
    PHASE_TWO,
    /*! @brief Phase 3 */
    PHASE_THERE,
#endif
    /*! @brief Total number of phases */
    MAX_PHASES
}PHASES;

/*! @enum METROLOGY_STATUS */
typedef enum
{
    /*! This bit indicates the meter is in the power down state. */
    METROLOGY_STATUS_POWER_DOWN = 0x0004,

    /*! This bit indicates the current status of the meter is "current flow is reversed", after
        all persistence checking, and other safeguards, have been used to check the validity of the
        reverse indication. */
    METROLOGY_STATUS_REVERSED = 0x0100,

    /*! This bit indicates the current status of the meter is "current flow is earthed", after
        all persistence checking, and other safeguards, have been used to check the validity of the
        earthed indication. */
    METROLOGY_STATUS_EARTHED = 0x0200,

    /*! This bit indicates the phase voltage is OK. */
    METROLOGY_STATUS_PHASE_VOLTAGE_OK = 0x0400,

    /*! This bit indicates the battery condition is OK. If battery monitoring is not enabled, this bit
        is not used. */
    METROLOGY_STATUS_BATTERY_OK = 0x0800
}METROLOGY_STATUS;

/*! @enum OPERATING_MODES */
typedef enum
{
    /*! The meter is operating normally*/
    OPERATING_MODE_NORMAL = 0,
#if defined(LIMP_MODE_SUPPORT)
    /*! The meter is an anti-tamper meter in limp (live only) mode */
    OPERATING_MODE_LIMP = 1,
    /*! The meter is an anti-tamper meter in limp (live only) mode, reading in short bursts */
    OPERATING_MODE_LIMP_BURST = 2,
#endif
    /*! The meter is in a battery powered state with automated meter reading, LCD and RTC functioning. */
    OPERATING_MODE_AMR_ONLY = 3,
    /*! The meter is in a battery powered state with only the LCD and RTC functioning. */
    OPERATING_MODE_LCD_ONLY = 4,
    /*! The meter is in a battery powered state with only the minimum of features (probably just the RTC) functioning. */
    OPERATING_MODE_POWERFAIL = 5
}OPERATING_MODES;

/*! @enum SAG_SWELL_EVENTS  */
typedef enum
{
    /*! @brief Voltage interruptions continuing */
    SAG_SWELL_VOLTAGE_INTERRUPTION_CONTINUING = -4,
    SAG_SWELL_VOLTAGE_INTERRUPTION_ONSET      = -3,
    SAG_SWELL_VOLTAGE_SAG_CONTINUING          = -2,
    SAG_SWELL_VOLTAGE_SAG_ONSET               = -1,
    SAG_SWELL_VOLTAGE_NORMAL                  = 0,
    SAG_SWELL_VOLTAGE_SWELL_ONSET             = 1,
    SAG_SWELL_VOLTAGE_SWELL_CONTINUING        = 2,
    SAG_SWELL_VOLTAGE_POWER_DOWN_OK           = 3
}SAG_SWELL_EVENTS;


/*! @enum PHASE_STATUS */
typedef enum
{
    /*! This flag in a channel's status variable indicates there is fresh gathered data from the
        background activity to be post-processed by the foreground activity. */
    PHASE_STATUS_NEW_LOG = 0x0001,

    /*! This flag in a channel's status variable indicates the voltage signal is currently in
        the positive half of its cycle. */
    PHASE_STATUS_V_POS = 0x0002,

    /*! This flag in a channel's status variable indicates the current signal is currently in
        the positive half of its cycle. */
    PHASE_STATUS_I_POS = 0x0004,
    PHASE_STATUS_ENERGY_LOGABLE = 0x0008,

    /*! This flag in a channel's status variable indicates the voltage signal was in overload
        during the last logged interval. Overload is determined by an excessive number of
        samples hitting the end-stops of the ADC's range. */
    PHASE_STATUS_V_OVERRANGE = 0x0010,

    /*! This flag in a channel's status variable indicates the phase current signal was in overload
        during the last logged interval. Overload is determined by an excessive number of
        samples hitting the end-stops of the ADC's range. */
    PHASE_STATUS_I_OVERRANGE = 0x0020,

    /*! This flag in a channel's status variable indicates the phase current signal was reversed
        during the last logged interval. */
    PHASE_STATUS_I_REVERSED = 0x0040,

    /*! This flag in a channel's status variable indicates the phase current signal was in overload
        during the last logged interval. Overload is determined by an excessive number of
        samples hitting the end-stops of the ADC's range. This is only used if the meter supports
        monitoring of both the live and neutral leads for anti-tamper management. */
    PHASE_STATUS_I_NEUTRAL_OVERRANGE = 0x0080,

    /*! This flag in a channel's status variable indicates the neutral current signal was
        reversed during the last logged interval. This is only used if the meter supports
        monitoring of both the live and neutral leads for anti-tamper management. */
    PHASE_STATUS_I_NEUTRAL_REVERSED = 0x0100,

    /*! This flag in a channel's status variable indicates the neutral current is the one
        currently being used. This means it has been judged by the anti-tamper logic to be
        the measurement which can best be trusted. This is only used if the meter supports
        monitoring of both the live and neutral leads for anti-tamper management. */
    PHASE_STATUS_CURRENT_FROM_NEUTRAL = 0x0200,

    /*! This flag in a channel's status variable indicates the neutral current signal is
        currently in the positive half of its cycle. This is only used if the meter supports
        monitoring of both the live and neutral leads for anti-tamper management. */
    PHASE_STATUS_I_NEUTRAL_POS = 0x0800,

    /*! This flag in a channel's status variable indicates the power has been declared to be
        reversed, after the anti-tamper logic has processed the raw indications. Live neutral
        or both leads may be reversed when this bit is set. */
    PHASE_STATUS_REVERSED = 0x1000,

    /*! This flag in a channel's status variable indicates the power (current in limp mode)
        has been declared to be unbalanced, after the anti-tamper logic has processed the
        raw indications. */
    PHASE_STATUS_UNBALANCED = 0x2000,

    PHASE_STATUS_ZERO_CROSSING_MISSED = 0x4000
}PHASE_STATUS;

/*!
 * @brief Defines First quarter Sine Table in Q(METROLOGY_DDS_TABLE_RESOLUTION-1)
 * sin(x) for x = [0, PI/4]
 * for ( i = 0; i < METROLOGY_DDS_STEPS; i++ ) {
 *   sineTable[i] = sin(i * PI/(2 * METROLOGY_DDS_STEPS)) * 2^(METROLOGY_DDS_TABLE_RESOLUTION-1)
 *  }
 */
static const int32_t sineTable[METROLOGY_DDS_STEPS + 1] =
{
     0,
     51472,
     102941,
     154407,
     205867,
     257319,
     308761,
     360192,
     411609,
     463011,
     514396,
     565761,
     617104,
     668425,
     719720,
     770988,
     822227,
     873435,
     924611,
     975751,
     1026855,
     1077920,
     1128945,
     1179927,
     1230864,
     1281756,
     1332599,
     1383391,
     1434132,
     1484819,
     1535450,
     1586023,
     1636536,
     1686988,
     1737376,
     1787699,
     1837954,
     1888140,
     1938256,
     1988298,
     2038265,
     2088156,
     2137968,
     2187699,
     2237349,
     2286913,
     2336392,
     2385783,
     2435084,
     2484293,
     2533409,
     2582430,
     2631353,
     2680177,
     2728900,
     2777521,
     2826037,
     2874446,
     2922747,
     2970939,
     3019018,
     3066984,
     3114834,
     3162567,
     3210181,
     3257674,
     3305044,
     3352290,
     3399410,
     3446402,
     3493264,
     3539994,
     3586592,
     3633054,
     3679379,
     3725566,
     3771613,
     3817517,
     3863278,
     3908894,
     3954362,
     3999681,
     4044850,
     4089867,
     4134729,
     4179436,
     4223986,
     4268376,
     4312606,
     4356673,
     4400577,
     4444314,
     4487885,
     4531286,
     4574517,
     4617576,
     4660460,
     4703170,
     4745702,
     4788055,
     4830229,
     4872220,
     4914028,
     4955651,
     4997087,
     5038336,
     5079394,
     5120261,
     5160936,
     5201416,
     5241701,
     5281788,
     5321676,
     5361364,
     5400850,
     5440132,
     5479210,
     5518082,
     5556746,
     5595200,
     5633444,
     5671476,
     5709294,
     5746898,
     5784285,
     5821454,
     5858404,
     5895133,
     5931641,
     5967925,
     6003985,
     6039818,
     6075424,
     6110801,
     6145949,
     6180865,
     6215548,
     6249997,
     6284211,
     6318188,
     6351927,
     6385428,
     6418687,
     6451706,
     6484481,
     6517012,
     6549298,
     6581337,
     6613128,
     6644671,
     6675963,
     6707004,
     6737792,
     6768327,
     6798607,
     6828631,
     6858398,
     6887906,
     6917156,
     6946144,
     6974872,
     7003337,
     7031538,
     7059474,
     7087145,
     7114548,
     7141684,
     7168551,
     7195148,
     7221474,
     7247529,
     7273310,
     7298818,
     7324051,
     7349008,
     7373688,
     7398091,
     7422215,
     7446060,
     7469624,
     7492908,
     7515909,
     7538627,
     7561061,
     7583211,
     7605075,
     7626653,
     7647944,
     7668946,
     7689660,
     7710085,
     7730219,
     7750062,
     7769614,
     7788873,
     7807838,
     7826510,
     7844887,
     7862969,
     7880754,
     7898243,
     7915435,
     7932328,
     7948923,
     7965219,
     7981214,
     7996910,
     8012304,
     8027396,
     8042187,
     8056674,
     8070858,
     8084739,
     8098315,
     8111586,
     8124551,
     8137211,
     8149564,
     8161611,
     8173350,
     8184782,
     8195905,
     8206720,
     8217226,
     8227422,
     8237309,
     8246886,
     8256152,
     8265107,
     8273751,
     8282084,
     8290104,
     8297813,
     8305209,
     8312293,
     8319063,
     8325521,
     8331665,
     8337495,
     8343011,
     8348214,
     8353102,
     8357675,
     8361934,
     8365878,
     8369507,
     8372821,
     8375819,
     8378503,
     8380870,
     8382923,
     8384659,
     8386081,
     8387186,
     8387975,
     8388449,
     8388607
};

/*!
 * @brief Metrology sin lookup
 * @param[in] phase The phase angle
 * @return sinvalue
 */
int32_t Metrology_ddsSinLookup(uint32_t phase);

#ifdef __cplusplus
}
#endif
#endif /* METROLOGY_METROLOGY_DEFINES_H_ */
/** @}*/
