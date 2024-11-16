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
 * tcan114x_reg.h
 *
 *  Version 1.0.1
 *
 *  Created on: December 4, 2018
 *      Author: a0225039
 *
 *  Version 1.0.1: August 12, 2019
 *      - Added soft reset register bits
 *
 */

#ifndef TESTER_SUITE_CAN_TCAN114X_REG_H_
#define TESTER_SUITE_CAN_TCAN114X_REG_H_

#define REG_TCAN114X_DEVICEID0 0x00
#define REG_TCAN114X_DEVICEID1 0x01
#define REG_TCAN114X_DEVICEID2 0x02
#define REG_TCAN114X_DEVICEID3 0x03
#define REG_TCAN114X_DEVICEID4 0x04
#define REG_TCAN114X_DEVICEID5 0x05
#define REG_TCAN114X_DEVICEID6 0x06
#define REG_TCAN114X_DEVICEID7 0x07

#define REG_TCAN114X_REVID_MAJOR 0x08
#define REG_TCAN114X_REVID_MINOR 0x09

//formula RSVD Registers not included     0x0A+
//Scratch Pad SPI register not included   0x0F

#define REG_TCAN114X_MODE_CONTROL 0x10
#define REG_TCAN114X_WAKE_PIN_CONFIG 0x11
#define REG_TCAN114X_PIN_CONFIG 0x12
#define REG_TCAN114X_WD_CONFIG_1 0x13
#define REG_TCAN114X_WD_CONFIG_2 0x14
#define REG_TCAN114X_WD_INPUT_TRIG 0x15
#define REG_TCAN114X_WD_RST_PULSE 0x16
#define REG_TCAN114X_FSM_CONFIG 0x17
#define REG_TCAN114X_FSM_COUNTER 0x18
#define REG_TCAN114X_DEVICE_RESET 0x19
#define REG_TCAN114X_DEVICE_CONFIG 0x1A

// DEVICE_CONFIG2 not included            0x1B
//
// SWE_DIS not included                   0x1C
//
//#define REG_TCAN114X_SWE_DIS            0x1C
//
//
// SO_CONFIG not included                 0x29

#define REG_TCAN114X_WD_QA_CONFIG 0x2D
#define REG_TCAN114X_WD_QA_ANSWER 0x2E
#define REG_TCAN114X_WD_QA_QUESTION 0x2F

/*
 * Selective wake registers
 */
#define REG_TCAN114X_SW_ID_1 0x30
#define REG_TCAN114X_SW_ID_2 0x31
#define REG_TCAN114X_SW_ID_3 0x32
#define REG_TCAN114X_SW_ID_4 0x33
#define REG_TCAN114X_SW_ID_MASK_1 0x34
#define REG_TCAN114X_SW_ID_MASK_2 0x35
#define REG_TCAN114X_SW_ID_MASK_3 0x36
#define REG_TCAN114X_SW_ID_MASK_4 0x37
#define REG_TCAN114X_SW_ID_MASK_DLC 0x38
#define REG_TCAN114X_SW_DATA_0 0x39
#define REG_TCAN114X_SW_DATA_1 0x3A
#define REG_TCAN114X_SW_DATA_2 0x3B
#define REG_TCAN114X_SW_DATA_3 0x3C
#define REG_TCAN114X_SW_DATA_4 0x3D
#define REG_TCAN114X_SW_DATA_5 0x3E
#define REG_TCAN114X_SW_DATA_6 0x3F
#define REG_TCAN114X_SW_DATA_7 0x40

// SW_RSVD_y not included                 0x41+

#define REG_TCAN114X_SW_CONFIG_1 0x44
#define REG_TCAN114X_SW_CONFIG_2 0x45
#define REG_TCAN114X_SW_CONFIG_3 0x46
#define REG_TCAN114X_SW_CONFIG_4 0x47

// SW_CONFIG_RSVD_y not included          0x48+

#define REG_TCAN114X_INT_GLOBAL 0x50
#define REG_TCAN114X_INT_1 0x51
#define REG_TCAN114X_INT_2 0x52
#define REG_TCAN114X_INT_3 0x53
#define REG_TCAN114X_INT_CANBUS 0x54
#define REG_TCAN114X_INT_GLOBAL_ENABLE 0x55
#define REG_TCAN114X_INT_ENABLE_1 0x56
#define REG_TCAN114X_INT_ENABLE_2 0x57
#define REG_TCAN114X_INT_ENABLE_3 0x58
#define REG_TCAN114X_INT_ENABLE_CANBUS 0x59

// INT_RSVD_y not included                0x5A+

//_________________________________________________________________________________________________________________

/*
 *  Bit masks
 */

//REG_TCAN114X_DEVICE_RESET
//Addr 19h
//--------------------------------------------------------------------
#define REG_BITS_TCAN114X_DEVICE_RESET_HARD_RESET 0x01
#define REG_BITS_TCAN114X_DEVICE_RESET_SOFT_RESET 0x02

//MODE_CNTRL
//Addr 10h
#define REG_BITS_TCAN114X_MODE_CNTRL_SW_EN 0x80
#define REG_BITS_TCAN114X_MODE_CNTRL_FD_EN 0x20  //0x10
#define REG_BITS_TCAN114X_MODE_CNTRL_MODE_SEL_MSK 0x07
#define REG_BITS_TCAN114X_MODE_CNTRL_MODE_SLEEP 0x01
#define REG_BITS_TCAN114X_MODE_CNTRL_MODE_STANDBY 0x04
#define REG_BITS_TCAN114X_MODE_CNTRL_MODE_LISTEN 0x05
#define REG_BITS_TCAN114X_MODE_CNTRL_MODE_NORMAL 0x07
//Added

#define REG_BITS_TCAN114X_MODE_CNTRL_MODE_DTO_DIS 0x40

/*RSVD now
 *
 *#define REG_BITS_TCAN114X_MODE_CNTRL_TM_EN              0x08
 *
 *#define REG_BITS_TCAN114X_MODE_CNTRL_SWE_DIS            0x20
 *
 */

/*Changed to DTO_DIS
 *
 * #define REG_BITS_TCAN114X_MODE_CNTRL_FS_DIS            0x40
 */

//----------------------------------------------------------------------

//REG_TCAN114X_SWE_DIS
//Addr 1Ch
/*
#define REG_BITS_TCAN114X_SWE_DIS_SWE_DIS               0x80
#define REG_BITS_TCAN114X_SWE_DIS_CANSLNT_SWE_DIS       0x04
*/

//----------------------------------------------------------------------

//INT_GLOBAL
//ADDR 50h
#define REG_BITS_TCAN114X_INT_GLOBAL_GLOBALERR 0x80
#define REG_BITS_TCAN114X_INT_GLOBAL_INT_1 0x40
#define REG_BITS_TCAN114X_INT_GLOBAL_INT_2 0x20
#define REG_BITS_TCAN114X_INT_GLOBAL_INT_3 0x10
#define REG_BITS_TCAN114X_INT_GLOBAL_INT_CANBUS 0x08

//----------------------------------------------------------------------

//SW_ID_3
//Addr 32h
#define REG_BITS_TCAN114X_SW_ID3_IDE 0x20

//SW_IDM_DLC
//Addr 38h
#define REG_BITS_TCAN114X_SW_ID_MASK_DLC_DATA_MASK_EN 0x01

//SW_CONFIG_4
//Addr 47h
#define REG_BITS_TCAN114X_SW_CONFIG_4_SWCFG 0x80

//WD_CONFIG_1
//Addr 13h
// Not sure if this does what is intended
// This sets WD_CONFIG to Q&A
#define REG_BITS_TCAN114X_WD_CONFIG_1_WD_CONFIG_MASK 0xC0

//WD_QA_QUESTION
//Addr 2Fh
#define REG_BITS_TCAN114X_WD_QA_QUESTION_QA_ERROR 0x40

#endif
