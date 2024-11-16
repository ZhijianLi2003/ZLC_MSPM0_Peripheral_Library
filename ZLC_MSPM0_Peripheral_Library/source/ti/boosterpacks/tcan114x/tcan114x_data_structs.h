/*
 * Copyright (c) 2022, Texas Instruments Incorporated
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
/*
 * tcan114x_data_structs.h
 *
 *  Created on: December 4, 2018
 *      Author: a0225039
 */

#ifndef TESTER_SUITE_CAN_TCAN114X_DATA_STRUCTS_H_
#define TESTER_SUITE_CAN_TCAN114X_DATA_STRUCTS_H_

#include <stdint.h>

#define TCAN114X_SLEEP 1
#define TCAN114X_STANDBY 4
#define TCAN114X_LISTEN 5
#define TCAN114X_NORMAL 7

/**
 * @brief Mode Control bitfield
 */
typedef union {
    //! Full word of the register
    uint8_t word;

    struct {
        //! Current mode of device
        uint8_t MODE_SEL : 3;

        //! Test Mode Enable --> RSVD
        uint8_t reserved : 2;

        //! Fault Detection Enable
        uint8_t FAULT_DETECT_EN : 1;

        //! Sleep wake error disable --> RMVD
        //uint8_t SWE_DIS : 1;

        //! Fail safe disable
        uint8_t DTO_DIS : 1;

        //! Selective Wake Enable
        uint8_t SW_EN : 1;
    };
} TCAN114x_Mode_Control;
//Addr 10h

#define TCAN114X_WAKE_CONFIG_BIDIRECTIONAL 0
#define TCAN114X_WAKE_CONFIG_RISING_EDGE 1
#define TCAN114X_WAKE_CONFIG_FALLING_EDGE 2
#define TCAN114X_WAKE_CONFIG_PULSE 3

#define TCAN114X_WAKE_WIDTH_MIN_10MS 0
#define TCAN114X_WAKE_WIDTH_MIN_20MS 1
#define TCAN114X_WAKE_WIDTH_MIN_40MS 2
#define TCAN114X_WAKE_WIDTH_MIN_80MS 3

#define TCAN114X_WAKE_WIDTH_INVALID_5MS 0
#define TCAN114X_WAKE_WIDTH_INVALID_10MS 1
#define TCAN114X_WAKE_WIDTH_INVALID_20MS 2
#define TCAN114X_WAKE_WIDTH_INVALID_40MS 3

#define TCAN114X_WAKE_WIDTH_MAX_750MS 0
#define TCAN114X_WAKE_WIDTH_MAX_1000MS 1
#define TCAN114X_WAKE_WIDTH_MAX_1500MS 2
#define TCAN114X_WAKE_WIDTH_MAX_2000MS 3

/**
 * @brief Sleep wake error disable register

typedef union
{
    //! Full word of the register
    uint8_t word;

    struct
    {
        //! RSVD
        uint8_t reserved1 : 2;

        //! SWE timer will be disabled from CANSLNT flag
        uint8_t CANSLNT_SWE_DIS : 1;

        //! RSVD
        uint8_t reserved2 : 4;

        //! Sleep wake error disable
        uint8_t SWE_DIS : 1;

    };
} TCAN114x_SWE_DIS;
//Addr 1Ch

*/

/**
 * @brief Wake Pin Configuration Register
 */
typedef union {
    //! Full word of the register
    uint8_t word;

    struct {
        //! Maximum WAKE pin input pulse width to be considered valid
        uint8_t WAKE_WIDTH_MAX : 2;

        //! Pulses less than or equal to this are considered invalid
        uint8_t WAKE_WIDTH_INVALID : 2;

        //! Minimum wake pulse width to wake up
        //uint8_t WAKE_WIDTH_MIN : 2;

        //! Minimum wake pulse width to wake up
        uint8_t WAKE_STAT : 2;

        //! Wake Pin Configuration
        uint8_t WAKE_CONFIG : 2;
    };
} TCAN114x_Wake_Pin_Config;
//Addr 11h

//! Wake Pin Pulse Direction: Low -> High -> Low
#define TCAN114X_PIN_CONFIG_WAKE_PULSE_LHL 0
//! Wake Pin Pulse Direction: High -> Low -> High
#define TCAN114X_PIN_CONFIG_WAKE_PULSE_HLH 1

#define TCAN114X_PIN_CONFIG_SDO_ONLY 0
#define TCAN114X_PIN_CONFIG_SDO_AND_NINT 1

#define TCAN114X_PIN_CONFIG_NINT_SEL_GLOBAL_INT 0
#define TCAN114X_PIN_CONFIG_NINT_SEL_WDT_FAILURE 1
#define TCAN114X_PIN_CONFIG_NINT_SEL_BUS_FAULT 2
#define TCAN114X_PIN_CONFIG_NINT_SEL_WAKE_REQUEST 3

#define TCAN114X_PIN_CONFIG_RXD_WK_PULLED_LOW 0
#define TCAN114X_PIN_CONFIG_RXD_WK_TOGGLE 1

#define TCAN114X_PIN_CONFIG_GPO_SEL_WDT_FAILURE 0
#define TCAN114X_PIN_CONFIG_GPO_SEL_GLOBAL_INT 1
#define TCAN114X_PIN_CONFIG_GPO_SEL_BUS_FAULT 2
#define TCAN114X_PIN_CONFIG_GPO_SEL_WAKE_REQUEST 3

/**
 * @brief Pin Configuration
 */
typedef union {
    //! Full word of the register
    uint8_t word;

    struct {
        //! GPO pin configuration selection, active low -> RSVD
        uint8_t reserved1 : 2;

        //! Configures RXD pin behavior from a wake event. 0 = pull low, 1 = toggle
        uint8_t RXD_WK_CONFIG : 1;

        //! Dominate time out disable ->RMVD
        //uint8_t DTO_DIS : 1;

        //! nINT configuration selection, active low
        uint8_t nINT_SEL : 2;

        //! SDO pin configuration. When configured as SDO and nINT, the pin will behave as SDO when nCS is low and behave as nINT when nCS is high --> RSVD
        uint8_t reserved2 : 2;

        //! Sets the WAKE pin expected pulse direction
        uint8_t WAKE_PULSE_CONFIG : 1;
    };
} TCAN114x_Pin_Config;
//Addr 12h

/* *********************************************************** *
 *                     Watchdog Structures                     *
 * *********************************************************** */
#define TCAN114X_WDT_CONFIG_WD_CONFIG_MODE_DISABLED 0
#define TCAN114X_WDT_CONFIG_WD_CONFIG_MODE_TIMEOUT 1
#define TCAN114X_WDT_CONFIG_WD_CONFIG_MODE_WINDOW 2
#define TCAN114X_WDT_CONFIG_WD_CONFIG_MODE_QA 3

#define TCAN114X_WDT_CONFIG_WD_PRE_FACTOR_1 0
#define TCAN114X_WDT_CONFIG_WD_PRE_FACTOR_2 1
#define TCAN114X_WDT_CONFIG_WD_PRE_FACTOR_3 2
#define TCAN114X_WDT_CONFIG_WD_PRE_FACTOR_4 3

#define TCAN114X_WDT_CONFIG_WD_ERR_CNT_IMMEDIATE 0
#define TCAN114X_WDT_CONFIG_WD_ERR_CNT_5TH_EVENT 1
#define TCAN114X_WDT_CONFIG_WD_ERR_CNT_9TH_EVENT 2
#define TCAN114X_WDT_CONFIG_WD_ERR_CNT_15TH_EVENT 3

#define TCAN114X_WDT_CONFIG_WD_ACT_INH_TOGGLE 0
#define TCAN114X_WDT_CONFIG_WD_ACT_GPO_LOW 1
#define TCAN114X_WDT_CONFIG_WD_ACT_WD_INT 2

#define TCAN114X_WDT_CONFIG_RESET_PULSE_WIDTH_1MS 8
#define TCAN114X_WDT_CONFIG_RESET_PULSE_WIDTH_5MS 1
#define TCAN114X_WDT_CONFIG_RESET_PULSE_WIDTH_12MS 2
#define TCAN114X_WDT_CONFIG_RESET_PULSE_WIDTH_25MS 11
#define TCAN114X_WDT_CONFIG_RESET_PULSE_WIDTH_50MS 4
#define TCAN114X_WDT_CONFIG_RESET_PULSE_WIDTH_75MS 13
#define TCAN114X_WDT_CONFIG_RESET_PULSE_WIDTH_125MS 14
#define TCAN114X_WDT_CONFIG_RESET_PULSE_WIDTH_190MS 7

/*
 * Watchdog Configuration Registers
 */
typedef struct {
    union {
        uint8_t word_config_1;
        struct {
            //! Watchdog output trigger event action
            uint8_t WD_ACT : 2;

            //! Watchdog event error counter threshold
            uint8_t WD_ERR_CNT_SET : 2;

            //! Watchdog Prescaler
            uint8_t WD_PRE : 2;

            //! Watchdog configuration/mode
            uint8_t WD_CONFIG_MODE : 2;
        };
    };

    union {
        uint8_t word_config_2;
        struct {
            uint8_t reserved : 1;

            //! Watchdog Error counter
            uint8_t WD_ERR_CNT : 4;

            //! Watchdog window or timeout time
            uint8_t WD_TIMER : 3;
        };
    };

    union {
        uint8_t word_wd_rst_pulse;
        struct {
            //! Watchdog reset pulse width
            uint8_t RESET_PULSE_WIDTH : 4;

            uint8_t reserved2 : 4;
        };
    };
} TCAN114x_Watchdog_Config;
//Addr 13h-14h, 16h

/*
 * Watchdog QA Configuration Registers
 */
typedef union {
    uint8_t word_qa_config;
    struct {
        //! Watchdog Q&A polynomial seed value loaded when device is in the RESET state
        uint8_t WD_QA_POLY_SEED : 4;

        //! Watchdog Q&A polynomial configuration
        uint8_t WD_QA_POLY_CFG : 2;

        //! Watchdog Q&A answer generation configuration
        uint8_t WD_ANSW_GEN_CFG : 2;
    };
} TCAN114x_Watchdog_QA_Config;
//Addr 2Dh

/*
 * Interrupt Registers
 */
typedef struct {
    union {
        uint8_t word_int_global;
        struct {
            uint8_t reserved1 : 3;
            uint8_t INT_CANBUS : 1;
            uint8_t INT_3 : 1;
            uint8_t INT_2 : 1;
            uint8_t INT_1 : 1;
            uint8_t GLOBALERR : 1;
        };
    };

    union {
        uint8_t word_int1;
        struct {
            uint8_t CANDOM : 1;
            uint8_t CANTO : 1;
            uint8_t CANSLNT : 1;
            uint8_t FRAME_OVF : 1;
            uint8_t WKERR : 1;
            uint8_t LWU : 1;
            uint8_t CANINT : 1;
            uint8_t WD : 1;
        };
    };

    union {
        uint8_t word_int2;
        struct {
            uint8_t TSDW : 1;
            uint8_t TSD : 1;
            uint8_t UVCC : 1;
            uint8_t UVIO : 1;
            uint8_t UVSUP : 1;
            uint8_t reserved2 : 1;
            uint8_t PWRON : 1;
            uint8_t SMS : 1;
        };
    };

    union {
        uint8_t word_int3;
        struct {
            uint8_t CRC_EEPROM : 1;
            uint8_t reserved_int3 : 4;
            uint8_t FSM : 1;
            uint8_t SWERR : 1;
            uint8_t SPIERR : 1;
        };
    };

    union {
        uint8_t word_canbus;
        struct {
            uint8_t CANBUSBAT : 1;
            uint8_t CANBUSGND : 1;
            uint8_t CANBUSOPEN : 1;
            uint8_t CANLGND : 1;
            uint8_t CANHBAT : 1;
            uint8_t CANHCANL : 1;
            uint8_t CANBUSTERMOPEN : 1;
            uint8_t reserved3 : 1;
        };
    };
} TCAN114x_Interrupts;
//Addr 50-54h

#endif /* TESTER_SUITE_CAN_TCAN114X_DATA_STRUCTS_H_ */
