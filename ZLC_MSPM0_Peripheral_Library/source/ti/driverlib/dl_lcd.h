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
 *  @file       dl_lcd.h
 *  @brief      Liquid Crystal Display (LCD) Driver Library
 *  @defgroup   LCD Liquid Crystal Display (LCD)
 *
 *  @anchor ti_dl_dl_lcd_Overview
 *  # Overview
 *
 *  The LCD Library allows full configuration of the MSPM0 LCD module.
 *  The LCD controller creates the AC segment and common voltage signals to
 *  directly drive LCD displays.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup LCD
 * @{
 */
#ifndef ti_dl_dl_lcd__include
#define ti_dl_dl_lcd__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_LCD__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/** @addtogroup DL_LCD_INTERRUPT
 *  @{
 */
/*!
 *  @brief Interrupt raised when there is the start of a new LCD frame
 */
#define DL_LCD_INTERRUPT_FRAME_START                    (LCD_IMASK_FRMSTART_SET)

/*!
 *  @brief Interrupt raised when blinking segments are turned off
 */
#define DL_LCD_INTERRUPT_BLINKING_SEGMENTS_OFF            (LCD_IMASK_BLKOFF_SET)

/*!
 *  @brief Interrupt raised when blinking segments are turned on
 */
#define DL_LCD_INTERRUPT_BLINKING_SEGMENTS_ON              (LCD_IMASK_BLKON_SET)

/** @}*/

/** @addtogroup DL_LCD_SEGMENT_LINE
 *  @{
 */
/*!
 *  @brief LCD Pin 0
 */
#define DL_LCD_SEGMENT_LINE_0                                                (0)
/*!
 *  @brief LCD Pin 1
 */
#define DL_LCD_SEGMENT_LINE_1                                                (1)
/*!
 *  @brief LCD Pin 2
 */
#define DL_LCD_SEGMENT_LINE_2                                                (2)
/*!
 *  @brief LCD Pin 3
 */
#define DL_LCD_SEGMENT_LINE_3                                                (3)
/*!
 *  @brief LCD Pin 4
 */
#define DL_LCD_SEGMENT_LINE_4                                                (4)
/*!
 *  @brief LCD Pin 5
 */
#define DL_LCD_SEGMENT_LINE_5                                                (5)
/*!
 *  @brief LCD Pin 6
 */
#define DL_LCD_SEGMENT_LINE_6                                                (6)
/*!
 *  @brief LCD Pin 7
 */
#define DL_LCD_SEGMENT_LINE_7                                                (7)
/*!
 *  @brief LCD Pin 8
 */
#define DL_LCD_SEGMENT_LINE_8                                                (8)
/*!
 *  @brief LCD Pin 9
 */
#define DL_LCD_SEGMENT_LINE_9                                                (9)
/*!
 *  @brief LCD Pin 10
 */
#define DL_LCD_SEGMENT_LINE_10                                              (10)
/*!
 *  @brief LCD Pin 11
 */
#define DL_LCD_SEGMENT_LINE_11                                              (11)
/*!
 *  @brief LCD Pin 12
 */
#define DL_LCD_SEGMENT_LINE_12                                              (12)
/*!
 *  @brief LCD Pin 13
 */
#define DL_LCD_SEGMENT_LINE_13                                              (13)
/*!
 *  @brief LCD Pin 14
 */
#define DL_LCD_SEGMENT_LINE_14                                              (14)
/*!
 *  @brief LCD Pin 15
 */
#define DL_LCD_SEGMENT_LINE_15                                              (15)
/*!
 *  @brief LCD Pin 16
 */
#define DL_LCD_SEGMENT_LINE_16                                              (16)
/*!
 *  @brief LCD Pin 17
 */
#define DL_LCD_SEGMENT_LINE_17                                              (17)
/*!
 *  @brief LCD Pin 18
 */
#define DL_LCD_SEGMENT_LINE_18                                              (18)
/*!
 *  @brief LCD Pin 19
 */
#define DL_LCD_SEGMENT_LINE_19                                              (19)
/*!
 *  @brief LCD Pin 20
 */
#define DL_LCD_SEGMENT_LINE_20                                              (20)
/*!
 *  @brief LCD Pin 21
 */
#define DL_LCD_SEGMENT_LINE_21                                              (21)
/*!
 *  @brief LCD Pin 22
 */
#define DL_LCD_SEGMENT_LINE_22                                              (22)
/*!
 *  @brief LCD Pin 23
 */
#define DL_LCD_SEGMENT_LINE_23                                              (23)
/*!
 *  @brief LCD Pin 24
 */
#define DL_LCD_SEGMENT_LINE_24                                              (24)
/*!
 *  @brief LCD Pin 25
 */
#define DL_LCD_SEGMENT_LINE_25                                              (25)
/*!
 *  @brief LCD Pin 26
 */
#define DL_LCD_SEGMENT_LINE_26                                              (26)
/*!
 *  @brief LCD Pin 27
 */
#define DL_LCD_SEGMENT_LINE_27                                              (27)
/*!
 *  @brief LCD Pin 28
 */
#define DL_LCD_SEGMENT_LINE_28                                              (28)
/*!
 *  @brief LCD Pin 29
 */
#define DL_LCD_SEGMENT_LINE_29                                              (29)
/*!
 *  @brief LCD Pin 30
 */
#define DL_LCD_SEGMENT_LINE_30                                              (30)
/*!
 *  @brief LCD Pin 31
 */
#define DL_LCD_SEGMENT_LINE_31                                              (31)
/*!
 *  @brief LCD Pin 32
 */
#define DL_LCD_SEGMENT_LINE_32                                              (32)
/*!
 *  @brief LCD Pin 33
 */
#define DL_LCD_SEGMENT_LINE_33                                              (33)
/*!
 *  @brief LCD Pin 34
 */
#define DL_LCD_SEGMENT_LINE_34                                              (34)
/*!
 *  @brief LCD Pin 35
 */
#define DL_LCD_SEGMENT_LINE_35                                              (35)
/*!
 *  @brief LCD Pin 36
 */
#define DL_LCD_SEGMENT_LINE_36                                              (36)
/*!
 *  @brief LCD Pin 37
 */
#define DL_LCD_SEGMENT_LINE_37                                              (37)
/*!
 *  @brief LCD Pin 38
 */
#define DL_LCD_SEGMENT_LINE_38                                              (38)
/*!
 *  @brief LCD Pin 39
 */
#define DL_LCD_SEGMENT_LINE_39                                              (39)
/*!
 *  @brief LCD Pin 40
 */
#define DL_LCD_SEGMENT_LINE_40                                              (40)
/*!
 *  @brief LCD Pin 41
 */
#define DL_LCD_SEGMENT_LINE_41                                              (41)
/*!
 *  @brief LCD Pin 42
 */
#define DL_LCD_SEGMENT_LINE_42                                              (42)
/*!
 *  @brief LCD Pin 43
 */
#define DL_LCD_SEGMENT_LINE_43                                              (43)
/*!
 *  @brief LCD Pin 44
 */
#define DL_LCD_SEGMENT_LINE_44                                              (44)
/*!
 *  @brief LCD Pin 45
 */
#define DL_LCD_SEGMENT_LINE_45                                              (45)
/*!
 *  @brief LCD Pin 46
 */
#define DL_LCD_SEGMENT_LINE_46                                              (46)
/*!
 *  @brief LCD Pin 47
 */
#define DL_LCD_SEGMENT_LINE_47                                              (47)
/*!
 *  @brief LCD Pin 48
 */
#define DL_LCD_SEGMENT_LINE_48                                              (48)
/*!
 *  @brief LCD Pin 49
 */
#define DL_LCD_SEGMENT_LINE_49                                              (49)
/*!
 *  @brief LCD Pin 50
 */
#define DL_LCD_SEGMENT_LINE_50                                              (50)
/*!
 *  @brief LCD Pin 51
 */
#define DL_LCD_SEGMENT_LINE_51                                              (51)
/*!
 *  @brief LCD Pin 52
 */
#define DL_LCD_SEGMENT_LINE_52                                              (52)
/*!
 *  @brief LCD Pin 53
 */
#define DL_LCD_SEGMENT_LINE_53                                              (53)
/*!
 *  @brief LCD Pin 54
 */
#define DL_LCD_SEGMENT_LINE_54                                              (54)
/*!
 *  @brief LCD Pin 55
 */
#define DL_LCD_SEGMENT_LINE_55                                              (55)
/*!
 *  @brief LCD Pin 56
 */
#define DL_LCD_SEGMENT_LINE_56                                              (56)
/*!
 *  @brief LCD Pin 57
 */
#define DL_LCD_SEGMENT_LINE_57                                              (57)
/*!
 *  @brief LCD Pin 58
 */
#define DL_LCD_SEGMENT_LINE_58                                              (58)
/*!
 *  @brief LCD Pin 59
 */
#define DL_LCD_SEGMENT_LINE_59                                              (59)
/*!
 *  @brief LCD Pin 60
 */
#define DL_LCD_SEGMENT_LINE_60                                              (60)
/*!
 *  @brief LCD Pin 61
 */
#define DL_LCD_SEGMENT_LINE_61                                              (61)
/*!
 *  @brief LCD Pin 62
 */
#define DL_LCD_SEGMENT_LINE_62                                              (62)
/*!
 *  @brief LCD Pin 63
 */
#define DL_LCD_SEGMENT_LINE_63                                              (63)
 /** @}*/

/** @addtogroup DL_LCD_MEMORY_BIT
 *  @{
 */
/*!
 *  @brief  Bit 0 inside LCD memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM0
 *  1b = Pin L[2*index] is used as COM0
 */
#define DL_LCD_MEMORY_BIT_0                                (LCD_LCDM_MBIT0_MASK)

/*!
 *  @brief  Bit 1 inside LCD memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM1
 *  1b = Pin L[2*index] is used as COM1
 */
#define DL_LCD_MEMORY_BIT_1                                (LCD_LCDM_MBIT1_MASK)

/*!
 *  @brief  Bit 2 inside LCD memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM2
 *  1b = Pin L[2*index] is used as COM2
 */
#define DL_LCD_MEMORY_BIT_2                                (LCD_LCDM_MBIT2_MASK)

/*!
 *  @brief  Bit 3 inside LCD memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM3
 *  1b = Pin L[2*index] is used as COM3
 */
#define DL_LCD_MEMORY_BIT_3                                (LCD_LCDM_MBIT3_MASK)

/*!
 *  @brief  Bit 4 inside LCD memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM4
 *  1b = Pin L[2*index] is used as COM4
 */
#define DL_LCD_MEMORY_BIT_4                                (LCD_LCDM_MBIT4_MASK)

/*!
 *  @brief  Bit 5 inside LCD memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM5
 *  1b = Pin L[2*index] is used as COM5
 */
#define DL_LCD_MEMORY_BIT_5                                (LCD_LCDM_MBIT5_MASK)

/*!
 *  @brief  Bit 6 inside LCD memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM6
 *  1b = Pin L[2*index] is used as COM6
 */
#define DL_LCD_MEMORY_BIT_6                                (LCD_LCDM_MBIT6_MASK)

/*!
 *  @brief  Bit 7 inside LCD memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM7
 *  1b = Pin L[2*index] is used as COM7
 */
#define DL_LCD_MEMORY_BIT_7                                (LCD_LCDM_MBIT7_MASK)

/** @}*/

/** @addtogroup DL_LCD_BLINK_MEMORY_BIT
 *  @{
 */
/*!
 *  @brief  Bit 0 inside LCD blink memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM0
 *  1b = Pin L[2*index] is used as COM0
 */
#define DL_LCD_BLINK_MEMORY_BIT_0                         (LCD_LCDBM_MBIT0_MASK)

/*!
 *  @brief  Bit 1 inside LCD blink memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM1
 *  1b = Pin L[2*index] is used as COM1
 */
#define DL_LCD_BLINK_MEMORY_BIT_1                         (LCD_LCDBM_MBIT1_MASK)

/*!
 *  @brief  Bit 2 inside LCD blink memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM2
 *  1b = Pin L[2*index] is used as COM2
 */
#define DL_LCD_BLINK_MEMORY_BIT_2                         (LCD_LCDBM_MBIT2_MASK)

/*!
 *  @brief Bit 3 inside LCD blink memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM3
 *  1b = Pin L[2*index] is used as COM3
 */
#define DL_LCD_BLINK_MEMORY_BIT_3                         (LCD_LCDBM_MBIT3_MASK)

/*!
 *  @brief  Bit 4 inside LCD blink memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM4
 *  1b = Pin L[2*index] is used as COM4
 */
#define DL_LCD_BLINK_MEMORY_BIT_4                         (LCD_LCDBM_MBIT4_MASK)

/*!
 *  @brief  Bit 5 inside LCD blink memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM5
 *  1b = Pin L[2*index] is used as COM5
 */
#define DL_LCD_BLINK_MEMORY_BIT_5                         (LCD_LCDBM_MBIT5_MASK)

/*!
 *  @brief  Bit 6 inside LCD blink memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM6
 *  1b = Pin L[2*index] is used as COM6
 */
#define DL_LCD_BLINK_MEMORY_BIT_6                         (LCD_LCDBM_MBIT6_MASK)

/*!
 *  @brief  Bit 7 inside LCD blink memory index registers
 *
 *  If LCD L[2*index] is selected as (1) segment line: 0b = LCD segment off
 *  1b = LCD segment on (2) common line: 0b = Pin L[2*index] not used as COM7
 *  1b = Pin L[2*index] is used as COM7
 */
#define DL_LCD_BLINK_MEMORY_BIT_7                         (LCD_LCDBM_MBIT7_MASK)

/** @}*/

/*! @enum DL_LCD_FREQ_DIVIDE */
typedef enum {
    /*! Divide fLCD by 1 */
    DL_LCD_FREQ_DIVIDE_1 = LCD_LCDCTL0_LCDDIVX_DIV_BY_1,
    /*! Divide fLCD by 2 */
    DL_LCD_FREQ_DIVIDE_2 = LCD_LCDCTL0_LCDDIVX_DIV_BY_2,
    /*! Divide fLCD by 3 */
    DL_LCD_FREQ_DIVIDE_3 = LCD_LCDCTL0_LCDDIVX_DIV_BY_3,
    /*! Divide fLCD by 4 */
    DL_LCD_FREQ_DIVIDE_4 = LCD_LCDCTL0_LCDDIVX_DIV_BY_4,
    /*! Divide fLCD by 5 */
    DL_LCD_FREQ_DIVIDE_5 = LCD_LCDCTL0_LCDDIVX_DIV_BY_5,
    /*! Divide fLCD by 6 */
    DL_LCD_FREQ_DIVIDE_6 = LCD_LCDCTL0_LCDDIVX_DIV_BY_6,
    /*! Divide fLCD by 7 */
    DL_LCD_FREQ_DIVIDE_7 = LCD_LCDCTL0_LCDDIVX_DIV_BY_7,
    /*! Divide fLCD by 8 */
    DL_LCD_FREQ_DIVIDE_8 = LCD_LCDCTL0_LCDDIVX_DIV_BY_8,
    /*! Divide fLCD by 9 */
    DL_LCD_FREQ_DIVIDE_9 = LCD_LCDCTL0_LCDDIVX_DIV_BY_9,
    /*! Divide fLCD by 10 */
    DL_LCD_FREQ_DIVIDE_10 = LCD_LCDCTL0_LCDDIVX_DIV_BY_10,
    /*! Divide fLCD by 11 */
    DL_LCD_FREQ_DIVIDE_11 = LCD_LCDCTL0_LCDDIVX_DIV_BY_11,
    /*! Divide fLCD by 12 */
    DL_LCD_FREQ_DIVIDE_12 = LCD_LCDCTL0_LCDDIVX_DIV_BY_12,
    /*! Divide fLCD by 13 */
    DL_LCD_FREQ_DIVIDE_13 = LCD_LCDCTL0_LCDDIVX_DIV_BY_13,
    /*! Divide fLCD by 14 */
    DL_LCD_FREQ_DIVIDE_14 = LCD_LCDCTL0_LCDDIVX_DIV_BY_14,
    /*! Divide fLCD by 15 */
    DL_LCD_FREQ_DIVIDE_15 = LCD_LCDCTL0_LCDDIVX_DIV_BY_15,
    /*! Divide fLCD by 16 */
    DL_LCD_FREQ_DIVIDE_16 = LCD_LCDCTL0_LCDDIVX_DIV_BY_16,
    /*! Divide fLCD by 17 */
    DL_LCD_FREQ_DIVIDE_17 = LCD_LCDCTL0_LCDDIVX_DIV_BY_17,
    /*! Divide fLCD by 18 */
    DL_LCD_FREQ_DIVIDE_18 = LCD_LCDCTL0_LCDDIVX_DIV_BY_18,
    /*! Divide fLCD by 19 */
    DL_LCD_FREQ_DIVIDE_19 = LCD_LCDCTL0_LCDDIVX_DIV_BY_19,
    /*! Divide fLCD by 20 */
    DL_LCD_FREQ_DIVIDE_20 = LCD_LCDCTL0_LCDDIVX_DIV_BY_20,
    /*! Divide fLCD by 21 */
    DL_LCD_FREQ_DIVIDE_21 = LCD_LCDCTL0_LCDDIVX_DIV_BY_21,
    /*! Divide fLCD by 22 */
    DL_LCD_FREQ_DIVIDE_22 = LCD_LCDCTL0_LCDDIVX_DIV_BY_22,
    /*! Divide fLCD by 23 */
    DL_LCD_FREQ_DIVIDE_23 = LCD_LCDCTL0_LCDDIVX_DIV_BY_23,
    /*! Divide fLCD by 24 */
    DL_LCD_FREQ_DIVIDE_24 = LCD_LCDCTL0_LCDDIVX_DIV_BY_24,
    /*! Divide fLCD by 25 */
    DL_LCD_FREQ_DIVIDE_25 = LCD_LCDCTL0_LCDDIVX_DIV_BY_25,
    /*! Divide fLCD by 26 */
    DL_LCD_FREQ_DIVIDE_26 = LCD_LCDCTL0_LCDDIVX_DIV_BY_26,
    /*! Divide fLCD by 27 */
    DL_LCD_FREQ_DIVIDE_27 = LCD_LCDCTL0_LCDDIVX_DIV_BY_27,
    /*! Divide fLCD by 28 */
    DL_LCD_FREQ_DIVIDE_28 = LCD_LCDCTL0_LCDDIVX_DIV_BY_28,
    /*! Divide fLCD by 29 */
    DL_LCD_FREQ_DIVIDE_29 = LCD_LCDCTL0_LCDDIVX_DIV_BY_29,
    /*! Divide fLCD by 30 */
    DL_LCD_FREQ_DIVIDE_30 = LCD_LCDCTL0_LCDDIVX_DIV_BY_30,
    /*! Divide fLCD by 31 */
    DL_LCD_FREQ_DIVIDE_31 = LCD_LCDCTL0_LCDDIVX_DIV_BY_31,
    /*! Divide fLCD by 32 */
    DL_LCD_FREQ_DIVIDE_32 = LCD_LCDCTL0_LCDDIVX_DIV_BY_32,
} DL_LCD_FREQ_DIVIDE;

/*! @enum DL_LCD_MUX_RATE */
typedef enum {
    /*! Select LCD Mode: static */
    DL_LCD_MUX_RATE_STATIC = LCD_LCDCTL0_LCDMXX_MX_STATIC,
    /*! Select LCD Mode: 2-mux */
    DL_LCD_MUX_RATE_2 = LCD_LCDCTL0_LCDMXX_MX_2,
    /*! Select LCD Mode: 3-mux */
    DL_LCD_MUX_RATE_3 = LCD_LCDCTL0_LCDMXX_MX_3,
    /*! Select LCD Mode: 4-mux */
    DL_LCD_MUX_RATE_4 = LCD_LCDCTL0_LCDMXX_MX_4,
    /*! Select LCD Mode: 5-mux */
    DL_LCD_MUX_RATE_5 = LCD_LCDCTL0_LCDMXX_MX_5,
    /*! Select LCD Mode: 6-mux */
    DL_LCD_MUX_RATE_6 = LCD_LCDCTL0_LCDMXX_MX_6,
    /*! Select LCD Mode: 7-mux */
    DL_LCD_MUX_RATE_7 = LCD_LCDCTL0_LCDMXX_MX_7,
    /*! Select LCD Mode: 8-mux */
    DL_LCD_MUX_RATE_8 = LCD_LCDCTL0_LCDMXX_MX_8,
} DL_LCD_MUX_RATE;

/*! @enum DL_LCD_WAVEFORM_POWERMODE */
typedef enum {
    /*! Select low power LCD waveforms */
    DL_LCD_WAVEFORM_POWERMODE_LOWPOWER = LCD_LCDCTL0_LCDLP_LP_LCD,
    /*! Select standard LCD waveforms */
    DL_LCD_WAVEFORM_POWERMODE_STANDARD = LCD_LCDCTL0_LCDLP_STD_LCD,
} DL_LCD_WAVEFORM_POWERMODE;

/*! @enum DL_LCD_BLINKING_DIVIDE */
typedef enum {
    /*! Divide LCD blinking frequency by 2 */
    DL_LCD_BLINKING_DIVIDE_BY_2 = LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_2,
    /*! Divide LCD blinking frequency by 4 */
    DL_LCD_BLINKING_DIVIDE_BY_4 = LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_4,
    /*! Divide LCD blinking frequency by 8 */
    DL_LCD_BLINKING_DIVIDE_BY_8 = LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_8,
    /*! Divide LCD blinking frequency by 16 */
    DL_LCD_BLINKING_DIVIDE_BY_16 = LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_16,
    /*! Divide LCD blinking frequency by 32 */
    DL_LCD_BLINKING_DIVIDE_BY_32 = LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_32,
    /*! Divide LCD blinking frequency by 64 */
    DL_LCD_BLINKING_DIVIDE_BY_64 = LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_64,
    /*! Divide LCD blinking frequency by 128 */
    DL_LCD_BLINKING_DIVIDE_BY_128 = LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_128,
    /*! Divide LCD blinking frequency by 256 */
    DL_LCD_BLINKING_DIVIDE_BY_256 = LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_256,
} DL_LCD_BLINKING_DIVIDE;

/*! @enum DL_LCD_BLINKING_MODE */
typedef enum {
    /*! Blinking disabled */
    DL_LCD_BLINKING_MODE_DISABLED = LCD_LCDBLKCTL_LCDBLKMODX_BLINK_DISABLE,
    /*! Blinking of individual segments as enabled in LCDBMx */
    DL_LCD_BLINKING_MODE_INDIVIDUAL_SEGMENTS =
        LCD_LCDBLKCTL_LCDBLKMODX_BLINK_SELECED,
    /*! Blinking of all segments */
    DL_LCD_BLINKING_MODE_ALL_SEGMENTS = LCD_LCDBLKCTL_LCDBLKMODX_BLINK_ALL,
    /*! Switch between display contents stored in LCDMx and LCDMBx */
    DL_LCD_BLINKING_MODE_TOGGLE = LCD_LCDBLKCTL_LCDBLKMODX_BKINK_TOGGLE,
} DL_LCD_BLINKING_MODE;

/*! @enum DL_LCD_CHARGE_PUMP_FREQUENCY */
typedef enum {
    /*! 32.768 kHz / 1 / 8 = 4.096 kHz  */
    DL_LCD_CHARGE_PUMP_FREQUENCY_4096HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_1_BY_8,
    /*! 32.768 kHz / 2 / 8 = 2.048 kHz  */
    DL_LCD_CHARGE_PUMP_FREQUENCY_2048HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_2_BY_8,
    /*! 32.768 kHz / 3 / 8 = 1.365 kHz  */
    DL_LCD_CHARGE_PUMP_FREQUENCY_1365HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_3_BY_8,
    /*! 32.768 kHz / 4 / 8 = 1.024 kHz  */
    DL_LCD_CHARGE_PUMP_FREQUENCY_1024HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_4_BY_8,
    /*! 32.768 kHz / 5 / 8 = 819 Hz     */
    DL_LCD_CHARGE_PUMP_FREQUENCY_819HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_5_BY_8,
    /*! 32.768 kHz / 6 / 8 = 682 Hz     */
    DL_LCD_CHARGE_PUMP_FREQUENCY_682HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_6_BY_8,
    /*! 32.768 kHz / 7 / 8 = 585 Hz     */
    DL_LCD_CHARGE_PUMP_FREQUENCY_585HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_7_BY_8,
    /*! 32.768 kHz / 8 / 8 = 512 Hz     */
    DL_LCD_CHARGE_PUMP_FREQUENCY_512HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_8_BY_8,
    /*! 32.768 kHz / 9 / 8 = 455 Hz     */
    DL_LCD_CHARGE_PUMP_FREQUENCY_455HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_9_BY_8,
    /*! 32.768 kHz / 10 / 8 = 409 Hz    */
    DL_LCD_CHARGE_PUMP_FREQUENCY_409HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_10_BY_8,
    /*! 32.768 kHz / 11 / 8 = 372 Hz    */
    DL_LCD_CHARGE_PUMP_FREQUENCY_372HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_11_BY_8,
    /*! 32.768 kHz / 12 / 8 = 341 Hz    */
    DL_LCD_CHARGE_PUMP_FREQUENCY_341HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_12_BY_8,
    /*! 32.768 kHz / 13 / 8 = 315 Hz    */
    DL_LCD_CHARGE_PUMP_FREQUENCY_315HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_13_BY_8,
    /*! 32.768 kHz / 14 / 8 = 292 Hz    */
    DL_LCD_CHARGE_PUMP_FREQUENCY_292HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_14_BY_8,
    /*! 32.768 kHz / 15 / 8 = 273 Hz    */
    DL_LCD_CHARGE_PUMP_FREQUENCY_273HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_15_BY_8,
    /*! 32.768 kHz / 16 / 8 = 256 Hz   */
    DL_LCD_CHARGE_PUMP_FREQUENCY_256HZ = LCD_LCDVCTL_LCDCPFSELX_DIV_BY_16_BY_8,
} DL_LCD_CHARGE_PUMP_FREQUENCY;

/*! @enum DL_LCD_VREF_INTERNAL */
typedef enum {
    /*! 2.60 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_2_60V = LCD_LCDVCTL_VLCDX_SEL_2P60V,
    /*! 2.66 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_2_66V = LCD_LCDVCTL_VLCDX_SEL_2P66V,
    /*! 2.72 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_2_72V = LCD_LCDVCTL_VLCDX_SEL_2P72V,
    /*! 2.78 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_2_78V = LCD_LCDVCTL_VLCDX_SEL_2P78V,
    /*! 2.84 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_2_84V = LCD_LCDVCTL_VLCDX_SEL_2P84V,
    /*! 2.90 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_2_90V = LCD_LCDVCTL_VLCDX_SEL_2P90V,
    /*! 2.96 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_2_96V = LCD_LCDVCTL_VLCDX_SEL_2P96V,
    /*! 3.02 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_3_02V = LCD_LCDVCTL_VLCDX_SEL_3P02V,
    /*! 3.08 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_3_08V = LCD_LCDVCTL_VLCDX_SEL_3P08V,
    /*! 3.14 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_3_14V = LCD_LCDVCTL_VLCDX_SEL_3P14V,
    /*! 3.20 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_3_20V = LCD_LCDVCTL_VLCDX_SEL_3P20V,
    /*! 3.26 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_3_26V = LCD_LCDVCTL_VLCDX_SEL_3P26V,
    /*! 3.32 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_3_32V = LCD_LCDVCTL_VLCDX_SEL_3P32V,
    /*! 3.38 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_3_38V = LCD_LCDVCTL_VLCDX_SEL_3P38V,
    /*! 3.44 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_3_44V = LCD_LCDVCTL_VLCDX_SEL_3P44V,
    /*! 3.50 V internal reference voltage select on R13  */
    DL_LCD_VREF_INTERNAL_3_50V = LCD_LCDVCTL_VLCDX_SEL_3P50V,
} DL_LCD_VREF_INTERNAL;

/*! @enum DL_LCD_R33_SOURCE */
typedef enum {
    /*! R33 is supplied from charge pump */
    DL_LCD_R33_SOURCE_EXTERNAL = LCD_LCDVCTL_LCDSELVDD_SEL_EXT_SUPPLY,
    /*! R33 is supplied from AVDD internally */
    DL_LCD_R33_SOURCE_INTERNAL = LCD_LCDVCTL_LCDSELVDD_SEL_AVDD,
} DL_LCD_R33_SOURCE;

/*! @enum DL_LCD_POWER_MODE */
typedef enum {
    /*! Low power resistor ladder generates bias voltage for the LCD */
    DL_LCD_POWER_MODE_LOW = LCD_LCDVCTL_LCD_HP_LP_LP_MODE,
    /*! Higher power resistor ladder generates bias voltage for the LCD */
    DL_LCD_POWER_MODE_HIGH = LCD_LCDVCTL_LCD_HP_LP_HP_MODE,
} DL_LCD_POWER_MODE;

/*! @enum DL_LCD_BIAS_VOLTAGE_SOURCE */
typedef enum {
    /*! Bias voltage sourced from R33 pin */
    DL_LCD_BIAS_VOLTAGE_SOURCE_R33 = LCD_LCDVCTL_VLCDSEL_VDD_R33_SEL_R33,
    /*! Bias voltage sourced from internal supply voltage AVDD */
    DL_LCD_BIAS_VOLTAGE_SOURCE_AVDD = LCD_LCDVCTL_VLCDSEL_VDD_R33_SEL_AVDD,
} DL_LCD_BIAS_VOLTAGE_SOURCE;

/*! @enum DL_LCD_BIAS */
typedef enum {
    /*! For 5-mux to 8-mux modes only. 1/3 bias */
    DL_LCD_BIAS_ONE_THIRD = LCD_LCDVCTL_LCDBIASSEL_ONE_BY_3_BIAS,
    /*! For 5-mux to 8-mux modes only. 1/4 bias */
    DL_LCD_BIAS_ONE_FOURTH = LCD_LCDVCTL_LCDBIASSEL_ONE_BY_4_BIAS,
} DL_LCD_BIAS;

/*! @enum DL_LCD_REFERENCE_MODE */
typedef enum {
    /*! R13 voltage in static mode */
    DL_LCD_REFERENCE_MODE_STATIC = LCD_LCDVCTL_LCDREFMODE_STATIC_MODE,
    /*! R13 voltage in switched mode */
    DL_LCD_REFERENCE_MODE_SWITCHED = LCD_LCDVCTL_LCDREFMODE_SWITCHED_MODE,
} DL_LCD_REFERENCE_MODE;

/*! @enum DL_LCD_DISP */
typedef enum {
    /*! Display content of LCD memory registers LCDMx */
    DL_LCD_DISPLAY_REGISTERS_MEMORY = LCD_LCDMEMCTL_LCDDISP_SEL_LCD_MEM_REGS,
    /*! Display content of LCD blinking memory registers LCDBMx */
    DL_LCD_DISPLAY_REGISTERS_BLINKING_MEMORY =
        LCD_LCDMEMCTL_LCDDISP_SEL_BLNK_MEM_REGS,
} DL_LCD_DISP;

/*! @enum DL_LCD_EVENT_LINE_MODE */
typedef enum {
    /*! The interrupt or event line is disabled. */
    DL_LCD_EVENT_LINE_MODE_DISABLED = LCD_EVT_MODE_INT0_CFG_DISABLE,
    /*! The interrupt/event line is in sw mode. Software must clear the RIS. */
    DL_LCD_EVENT_LINE_MODE_SOFTWARE = LCD_EVT_MODE_INT0_CFG_SOFTWARE,
    /*! The interrupt/event line is in hw mode. The hardware clears RIS flag. */
    DL_LCD_EVENT_LINE_MODE_HARDWARE = LCD_EVT_MODE_INT0_CFG_HARDWARE,
} DL_LCD_EVENT_LINE_MODE;

/*! @enum DL_LCD_IIDX */
typedef enum {
    /*! LCD interrupt index for no interrupt pending */
    DL_LCD_IIDX_NO_INT = LCD_IIDX_STAT_NO_INTR,
    /*! LCD interrupt index when start of new frame interrupt */
    DL_LCD_IIDX_FRAME_START = LCD_IIDX_STAT_FRAME_START,
    /*! LCD interrupt index when blinking segments off */
    DL_LCD_IIDX_BLINKING_SEGMENTS_OFF = LCD_IIDX_STAT_BLK_OFF,
    /*! LCD interrupt index when blinking segments on */
    DL_LCD_IIDX_BLINKING_SEGMENTS_ON = LCD_IIDX_STAT_BLK_ON,
} DL_LCD_IIDX;

/*! @enum DL_LCD_MEMORY */
typedef enum {
    /*! Index to access LCD memory register 0 */
    DL_LCD_MEMORY_0 = 0,
    /*! Index to access LCD memory register 1 */
    DL_LCD_MEMORY_1 = 1,
    /*! Index to access LCD memory register 2 */
    DL_LCD_MEMORY_2 = 2,
    /*! Index to access LCD memory register 3 */
    DL_LCD_MEMORY_3 = 3,
    /*! Index to access LCD memory register 4 */
    DL_LCD_MEMORY_4 = 4,
    /*! Index to access LCD memory register 5 */
    DL_LCD_MEMORY_5 = 5,
    /*! Index to access LCD memory register 6 */
    DL_LCD_MEMORY_6 = 6,
    /*! Index to access LCD memory register 7 */
    DL_LCD_MEMORY_7 = 7,
    /*! Index to access LCD memory register 8 */
    DL_LCD_MEMORY_8 = 8,
    /*! Index to access LCD memory register 9 */
    DL_LCD_MEMORY_9 = 9,
    /*! Index to access LCD memory register 10 */
    DL_LCD_MEMORY_10 = 10,
    /*! Index to access LCD memory register 11 */
    DL_LCD_MEMORY_11 = 11,
    /*! Index to access LCD memory register 12 */
    DL_LCD_MEMORY_12 = 12,
    /*! Index to access LCD memory register 13 */
    DL_LCD_MEMORY_13 = 13,
    /*! Index to access LCD memory register 14 */
    DL_LCD_MEMORY_14 = 14,
    /*! Index to access LCD memory register 15 */
    DL_LCD_MEMORY_15 = 15,
    /*! Index to access LCD memory register 16 */
    DL_LCD_MEMORY_16 = 16,
    /*! Index to access LCD memory register 17 */
    DL_LCD_MEMORY_17 = 17,
    /*! Index to access LCD memory register 18 */
    DL_LCD_MEMORY_18 = 18,
    /*! Index to access LCD memory register 19 */
    DL_LCD_MEMORY_19 = 19,
    /*! Index to access LCD memory register 20 */
    DL_LCD_MEMORY_20 = 20,
    /*! Index to access LCD memory register 21 */
    DL_LCD_MEMORY_21 = 21,
    /*! Index to access LCD memory register 22 */
    DL_LCD_MEMORY_22 = 22,
    /*! Index to access LCD memory register 23 */
    DL_LCD_MEMORY_23 = 23,
    /*! Index to access LCD memory register 24 */
    DL_LCD_MEMORY_24 = 24,
    /*! Index to access LCD memory register 25 */
    DL_LCD_MEMORY_25 = 25,
    /*! Index to access LCD memory register 26 */
    DL_LCD_MEMORY_26 = 26,
    /*! Index to access LCD memory register 27 */
    DL_LCD_MEMORY_27 = 27,
    /*! Index to access LCD memory register 28 */
    DL_LCD_MEMORY_28 = 28,
    /*! Index to access LCD memory register 29 */
    DL_LCD_MEMORY_29 = 29,
    /*! Index to access LCD memory register 30 */
    DL_LCD_MEMORY_30 = 30,
    /*! Index to access LCD memory register 31 */
    DL_LCD_MEMORY_31 = 31,
    /*! Index to access LCD memory register 32 */
    DL_LCD_MEMORY_32 = 32,
    /*! Index to access LCD memory register 33 */
    DL_LCD_MEMORY_33 = 33,
    /*! Index to access LCD memory register 34 */
    DL_LCD_MEMORY_34 = 34,
    /*! Index to access LCD memory register 35 */
    DL_LCD_MEMORY_35 = 35,
    /*! Index to access LCD memory register 36 */
    DL_LCD_MEMORY_36 = 36,
    /*! Index to access LCD memory register 37 */
    DL_LCD_MEMORY_37 = 37,
    /*! Index to access LCD memory register 38 */
    DL_LCD_MEMORY_38 = 38,
    /*! Index to access LCD memory register 39 */
    DL_LCD_MEMORY_39 = 39,
    /*! Index to access LCD memory register 40 */
    DL_LCD_MEMORY_40 = 40,
    /*! Index to access LCD memory register 41 */
    DL_LCD_MEMORY_41 = 41,
    /*! Index to access LCD memory register 42 */
    DL_LCD_MEMORY_42 = 42,
    /*! Index to access LCD memory register 43 */
    DL_LCD_MEMORY_43 = 43,
    /*! Index to access LCD memory register 44 */
    DL_LCD_MEMORY_44 = 44,
    /*! Index to access LCD memory register 45 */
    DL_LCD_MEMORY_45 = 45,
    /*! Index to access LCD memory register 46 */
    DL_LCD_MEMORY_46 = 46,
    /*! Index to access LCD memory register 47 */
    DL_LCD_MEMORY_47 = 47,
    /*! Index to access LCD memory register 48 */
    DL_LCD_MEMORY_48 = 48,
    /*! Index to access LCD memory register 49 */
    DL_LCD_MEMORY_49 = 49,
    /*! Index to access LCD memory register 50 */
    DL_LCD_MEMORY_50 = 50,
    /*! Index to access LCD memory register 51 */
    DL_LCD_MEMORY_51 = 51,
    /*! Index to access LCD memory register 52 */
    DL_LCD_MEMORY_52 = 52,
    /*! Index to access LCD memory register 53*/
    DL_LCD_MEMORY_53 = 53,
    /*! Index to access LCD memory register 54 */
    DL_LCD_MEMORY_54 = 54,
    /*! Index to access LCD memory register 55 */
    DL_LCD_MEMORY_55 = 55,
    /*! Index to access LCD memory register 56 */
    DL_LCD_MEMORY_56 = 56,
    /*! Index to access LCD memory register 57 */
    DL_LCD_MEMORY_57 = 57,
    /*! Index to access LCD memory register 58 */
    DL_LCD_MEMORY_58 = 58,
    /*! Index to access LCD memory register 59 */
    DL_LCD_MEMORY_59 = 59,
    /*! Index to access LCD memory register 60 */
    DL_LCD_MEMORY_60 = 60,
    /*! Index to access LCD memory register 61 */
    DL_LCD_MEMORY_61 = 61,
    /*! Index to access LCD memory register 62 */
    DL_LCD_MEMORY_62 = 62,
    /*! Index to access LCD memory register 63 */
    DL_LCD_MEMORY_63 = 63,
} DL_LCD_MEMORY;

/*! @enum DL_LCD_BLINKING_MEMORY */
typedef enum {
    /*! Index to access LCD blink memory register 0 */
    DL_LCD_BLINKING_MEMORY_0 = 0,
    /*! Index to access LCD blink memory register 1 */
    DL_LCD_BLINKING_MEMORY_1 = 1,
    /*! Index to access LCD blink memory register 2 */
    DL_LCD_BLINKING_MEMORY_2 = 2,
    /*! Index to access LCD blink memory register 3 */
    DL_LCD_BLINKING_MEMORY_3 = 3,
    /*! Index to access LCD blink memory register 4 */
    DL_LCD_BLINKING_MEMORY_4 = 4,
    /*! Index to access LCD blink memory register 5 */
    DL_LCD_BLINKING_MEMORY_5 = 5,
    /*! Index to access LCD blink memory register 6 */
    DL_LCD_BLINKING_MEMORY_6 = 6,
    /*! Index to access LCD blink memory register 7 */
    DL_LCD_BLINKING_MEMORY_7 = 7,
    /*! Index to access LCD blink memory register 8 */
    DL_LCD_BLINKING_MEMORY_8 = 8,
    /*! Index to access LCD blink memory register 9 */
    DL_LCD_BLINKING_MEMORY_9 = 9,
    /*! Index to access LCD blink memory register 10 */
    DL_LCD_BLINKING_MEMORY_10 = 10,
    /*! Index to access LCD blink memory register 11 */
    DL_LCD_BLINKING_MEMORY_11 = 11,
    /*! Index to access LCD blink memory register 12 */
    DL_LCD_BLINKING_MEMORY_12 = 12,
    /*! Index to access LCD blink memory register 13 */
    DL_LCD_BLINKING_MEMORY_13 = 13,
    /*! Index to access LCD blink memory register 14 */
    DL_LCD_BLINKING_MEMORY_14 = 14,
    /*! Index to access LCD blink memory register 15 */
    DL_LCD_BLINKING_MEMORY_15 = 15,
    /*! Index to access LCD blink memory register 16 */
    DL_LCD_BLINKING_MEMORY_16 = 16,
    /*! Index to access LCD blink memory register 17 */
    DL_LCD_BLINKING_MEMORY_17 = 17,
    /*! Index to access LCD blink memory register 18 */
    DL_LCD_BLINKING_MEMORY_18 = 18,
    /*! Index to access LCD blink memory register 19 */
    DL_LCD_BLINKING_MEMORY_19 = 19,
    /*! Index to access LCD blink memory register 20 */
    DL_LCD_BLINKING_MEMORY_20 = 20,
    /*! Index to access LCD blink memory register 21 */
    DL_LCD_BLINKING_MEMORY_21 = 21,
    /*! Index to access LCD blink memory register 22 */
    DL_LCD_BLINKING_MEMORY_22 = 22,
    /*! Index to access LCD blink memory register 23 */
    DL_LCD_BLINKING_MEMORY_23 = 23,
    /*! Index to access LCD blink memory register 24 */
    DL_LCD_BLINKING_MEMORY_24 = 24,
    /*! Index to access LCD blink memory register 25 */
    DL_LCD_BLINKING_MEMORY_25 = 25,
    /*! Index to access LCD blink memory register 26 */
    DL_LCD_BLINKING_MEMORY_26 = 26,
    /*! Index to access LCD blink memory register 27 */
    DL_LCD_BLINKING_MEMORY_27 = 27,
    /*! Index to access LCD blink memory register 28 */
    DL_LCD_BLINKING_MEMORY_28 = 28,
    /*! Index to access LCD blink memory register 29 */
    DL_LCD_BLINKING_MEMORY_29 = 29,
    /*! Index to access LCD blink memory register 30*/
    DL_LCD_BLINKING_MEMORY_30 = 30,
    /*! Index to access LCD blink memory register 31 */
    DL_LCD_BLINKING_MEMORY_31 = 31,
} DL_LCD_BLINKING_MEMORY;

/*! @enum DL_LCD_COM */
typedef enum {
    /*! Index to access COM 0 */
    DL_LCD_COM_0 = 0x01,
    /*! Index to access COM 1 */
    DL_LCD_COM_1 = 0x02,
    /*! Index to access COM 2 */
    DL_LCD_COM_2 = 0x04,
    /*! Index to access COM 3 */
    DL_LCD_COM_3 = 0x08,
    /*! Index to access COM 4 */
    DL_LCD_COM_4 = 0x10,
    /*! Index to access COM 5 */
    DL_LCD_COM_5 = 0x20,
    /*! Index to access COM 6 */
    DL_LCD_COM_6 = 0x40,
    /*! Index to access COM 7 */
    DL_LCD_COM_7 = 0x80,
} DL_LCD_COM;

/*! @enum DL_LCD_VREFGEN_CYCLES */
typedef enum {
    /*! Turn on VREF generation circuitry for 16 clock cycles */
    DL_LCD_VREFGEN_CYCLES_16 = LCD_LCDVREFCFG_ONTIME_ONTIME16,
    /*! Turn on VREF generation circuitry for 32 clock cycles */
    DL_LCD_VREFGEN_CYCLES_32 = LCD_LCDVREFCFG_ONTIME_ONTIME32,
    /*! Turn on VREF generation circuitry for 128 clock cycles */
    DL_LCD_VREFGEN_CYCLES_128 = LCD_LCDVREFCFG_ONTIME_ONTIME128,
    /*! Turn on VREF generation circuitry for 256 clock cycles */
    DL_LCD_VREFGEN_CYCLES_256 = LCD_LCDVREFCFG_ONTIME_ONTIME256,
} DL_LCD_VREFGEN_CYCLES;

/**
 * @brief Configuration struct for @ref DL_LCD_init
 */
typedef struct {
    /*! The frequency divider to set. One of @ref DL_LCD_FREQ_DIVIDE */
    DL_LCD_FREQ_DIVIDE frequencyDivider;
    /*! The mux rate. One of @ref DL_LCD_MUX_RATE. */
    DL_LCD_MUX_RATE muxRate;
    /*! Select waveforms power mode. One of @ref DL_LCD_WAVEFORM_POWERMODE */
    DL_LCD_WAVEFORM_POWERMODE lowPowerWaveform;
} DL_LCD_Config;

/**
 *  @brief Initialize the LCD peripheral
 *
 *  Initializes all the common configurable options for the LCD peripheral. Any
 *  other custom configuration can be done after calling this API. The LCD is
 *  not enabled in this API.
 *
 *  @param[in] lcd      Pointer to the register overlay for the peripheral
 *  @param[in] config   Configuration for LCD peripheral
 */
void DL_LCD_init(LCD_Regs *lcd, DL_LCD_Config *config);

/**
 *  @brief Enable a pin as LCD function
 *
 *  @param[in] lcd      Pointer to the register overlay for the peripheral
 *  @param[in] pin      Pin to set as LCD function
 *                      One of @ref DL_LCD_SEGMENT_LINE
 *  @note               This function will disable power to the LCD module.
 *                      If needed, enable the module after by calling
 *                      @ref DL_LCD_enable
 */

void DL_LCD_setPinAsLCDFunction(LCD_Regs *lcd, uint32_t pin);

/**
 *  @brief Enable a pin as port function
 *
 *  @param[in] lcd      Pointer to the register overlay for the peripheral
 *  @param[in] pin      Pin to set as port function.
 *                      One of @ref DL_LCD_SEGMENT_LINE
 *  @note               This function will disable power to the LCD module.
 *                      If needed, enable the module after by calling
 *                      @ref DL_LCD_enable
 */
void DL_LCD_setPinAsPortFunction(LCD_Regs *lcd, uint8_t pin);

/**
 *  @brief Enable an LCD function pin as COM
 *
 *  @param[in] lcd      Pointer to the register overlay for the peripheral
 *  @param[in] pin      Pin to set as common.
 *                      One of @ref DL_LCD_SEGMENT_LINE
 *  @param[in] com      The selected COM number for the common line.
 *                      One of @ref DL_LCD_COM
 */
void DL_LCD_setPinAsCommon(LCD_Regs *lcd, uint8_t pin, uint32_t com);

/**
 *  @brief Enable an LCD function pin as Segment
 *
 *  @param[in] lcd      Pointer to the register overlay for the peripheral
 *  @param[in] pin      Pin to set as segment line.
 *                      One of @ref DL_LCD_SEGMENT_LINE
 */
void DL_LCD_setPinAsSegment(LCD_Regs *lcd, uint8_t pin);

/**
 *  @brief Enables power to the LCD module
 *
 *  @param[in] lcd  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_LCD_enablePower(LCD_Regs *lcd)
{
    lcd->PWREN |= (LCD_PWREN_KEY_UNLOCK_W | LCD_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Disables power to the LCD module
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_disablePower(LCD_Regs *lcd)
{
    lcd->PWREN = (LCD_PWREN_KEY_UNLOCK_W | LCD_PWREN_ENABLE_DISABLE);
}

/**
 *  @brief Checks if power module on LCD is enabled
 *
 *  @param[in]  lcd  Pointer to the register overlay for the peripheral
 *
 *  @return     If power module on LCD is enabled
 *
 *  @retval     true if power module on LCD is enabled
 *  @retval     false if power module on LCD is disabled
 */
__STATIC_INLINE bool DL_LCD_isPowerEnabled(LCD_Regs *lcd)
{
    return ((lcd->PWREN & LCD_PWREN_ENABLE_MASK) ==
            LCD_PWREN_ENABLE_ENABLE);
}

/**
 *  @brief Resets LCD peripheral
 *
 *  @param[in] lcd  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_LCD_reset(LCD_Regs *lcd)
{
    lcd->RSTCTL = (LCD_RSTCTL_KEY_UNLOCK_W | LCD_RSTCTL_RESETSTKYCLR_CLR |
            LCD_RSTCTL_RESETASSERT_ASSERT);
}

/**
 *  @brief Checks if LCD peripheral was reset
 *
 *  @param[in]  lcd  Pointer to the register overlay for the peripheral
 *
 *  @return     If peripheral was reset
 *
 *  @retval     true if peripheral was reset since this bit was last cleared by
 *              RESETSTKYCLR in the RSTCTL register
 *  @retval     false if peripheral was not reset since the last bit clear
 */
__STATIC_INLINE bool DL_LCD_isReset(LCD_Regs *lcd)
{
    return ((lcd->STAT & LCD_STAT_RESETSTKY_MASK) ==
            LCD_STAT_RESETSTKY_RESET);
}

/**
 *  @brief Get the event line mode
 *
 *  @param[in]  lcd  Pointer to the register overlay for the peripheral
 *
 *  @return     event line mode
 *
 *  @retval     One of @ref DL_LCD_EVENT_LINE_MODE
 */
__STATIC_INLINE DL_LCD_EVENT_LINE_MODE DL_LCD_getEventLineMode(LCD_Regs *lcd)
{
    uint32_t eventLineMode = (lcd->EVT_MODE & LCD_EVT_MODE_INT0_CFG_MASK);

    return (DL_LCD_EVENT_LINE_MODE)(eventLineMode);
}

/**
 *  @brief Gets the highest priority pending interrupt
 *
 *  Accesses and reads the IIDX register to obtain the highest currently
 *  pending interrupt. A read clears the corresponding interrupt flag in RIS
 *  and MIS.
 *
 *  @param[in]  lcd  pointer to the register overlay of the peripheral
 *
 *  @return     The highest priority pending interrupt
 *
 *  @retval     One of @ref DL_LCD_IIDX
 */
__STATIC_INLINE DL_LCD_IIDX DL_LCD_getPendingInterrupt(LCD_Regs *lcd)
{
    return ((DL_LCD_IIDX) lcd->INT_EVENT0.IIDX);
}

/**
 *  @brief Enable LCD interrupts
 *
 *  @param[in] lcd              Pointer to the register overlay for the
 *                              peripheral
 *  @param[in] interruptMask    Bit mask of interrupts to enable. Bitwise OR of
 *                              @ref DL_LCD_INTERRUPT.
 */
__STATIC_INLINE void DL_LCD_enableInterrupt(
    LCD_Regs *lcd, uint32_t interruptMask)
{
    lcd->INT_EVENT0.IMASK |= interruptMask;
}

/**
 *  @brief Disable LCD interrupts
 *
 *  @param[in] lcd              Pointer to the register overlay for the
 *                              peripheral
 *  @param[in] interruptMask    Bit mask of interrupts to disable. Bitwise OR of
 *                              @ref DL_LCD_INTERRUPT.
 */
__STATIC_INLINE void DL_LCD_disableInterrupt(
    LCD_Regs *lcd, uint32_t interruptMask)
{
    lcd->INT_EVENT0.IMASK &= ~(interruptMask);
}

/**
 *  @brief Check which LCD interrupts are enabled
 *
 *  @param[in]  lcd             Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  interruptMask   Bit mask of interrupts to check. Bitwise OR of
 *                              @ref DL_LCD_INTERRUPT.
 *
 *  @return     Which of the requested LCD interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_LCD_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_LCD_getEnabledInterrupts(
    LCD_Regs *lcd, uint32_t interruptMask)
{
    return (lcd->INT_EVENT0.IMASK & interruptMask);
}

/**
 *  @brief Check interrupt flag of any LCD interrupt
 *
 *  Checks if any of the LCD interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  lcd             Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  interruptMask   Bit mask of interrupts to check. Bitwise OR of
 *                              @ref DL_LCD_INTERRUPT.
 *
 *  @return     Which of the requested LCD interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_LCD_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_LCD_getRawInterruptStatus(
    LCD_Regs *lcd, uint32_t interruptMask)
{
    return (lcd->INT_EVENT0.RIS & interruptMask);
}

/**
 *  @brief Check interrupt flag of enabled LCD interrupts
 *
 *  Checks if any of the LCD interrupts that were previously enabled are
 *  pending.
 *
 *  @param[in]  lcd             Pointer to the register overlay for the
 *                              peripheral
 *  @param[in]  interruptMask   Bit mask of interrupts to check. Bitwise OR of
 *                              @ref DL_LCD_INTERRUPT.
 *
 *  @return     Which of the requested LCD interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_LCD_INTERRUPT values
 *
 *  @sa         DL_LCD_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_LCD_getEnabledInterruptStatus(
    LCD_Regs *lcd, uint32_t interruptMask)
{
    return (lcd->INT_EVENT0.MIS & interruptMask);
}

/**
 *  @brief Set LCD interrupts
 *
 *  @param[in] lcd              Pointer to the register overlay for the
 *                              peripheral
 *  @param[in] interruptMask    Bit mask of interrupts to set. Bitwise OR of
 *                              @ref DL_LCD_INTERRUPT.
 */
__STATIC_INLINE void DL_LCD_setInterrupts(
    LCD_Regs *lcd, uint32_t interruptMask)
{
    lcd->INT_EVENT0.ISET = interruptMask;
}

/**
 *  @brief Clear pending LCD interrupts
 *
 *  @param[in] lcd              Pointer to the register overlay for the
 *                              peripheral
 *  @param[in] interruptMask    Bit mask of interrupts to clear. Bitwise OR of
 *                              @ref DL_LCD_INTERRUPT.
 */
__STATIC_INLINE void DL_LCD_clearInterruptStatus(
    LCD_Regs *lcd, uint32_t interruptMask)
{
    lcd->INT_EVENT0.ICLR = interruptMask;
}

/**
 *  @brief Enable external synchronization
 *
 *  @param[in] lcd  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_enableExternalSync(LCD_Regs *lcd)
{
    lcd->LCDCTL0 |= LCD_LCDCTL0_LCDSYNCEXT_LCD_EXT_SYNC_ON;
}

/**
 *  @brief Disable external synchronization
 *
 *  @param[in] lcd  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_disableExternalSync(LCD_Regs *lcd)
{
    lcd->LCDCTL0 &= ~(LCD_LCDCTL0_LCDSYNCEXT_MASK);
}

/**
 *  @brief Checks if external synchronization is enabled
 *
 *  @param[in]  lcd  Pointer to the register overlay for the peripheral
 *
 *  @return     If external synchronization is enabled
 *
 *  @retval     true if external synchronization enabled
 *  @retval     false if external synchronization is disabled
 */
__STATIC_INLINE bool DL_LCD_isExternalSyncEnabled(LCD_Regs *lcd)
{
    return ((lcd->LCDCTL0 & LCD_LCDCTL0_LCDSYNCEXT_MASK) ==
            LCD_LCDCTL0_LCDSYNCEXT_LCD_EXT_SYNC_ON);
}

/**
 *  @brief Set the LCD frequency divider.
 *
 *  fLCD = fSOURCE / ((LCDDIVx + 1) × Value[LCDMXx])
 *
 *  @param[in]  lcd     Pointer to the register overlay for the peripheral
 *  @param[in]  fDiv    The frequency divider to set.
 *                      One of @ref DL_LCD_FREQ_DIVIDE
 *
 *  @pre        The LCD module must be off (LCDCTL0.LCDON == 0) before setting
 *              this configuration.
 */
__STATIC_INLINE void DL_LCD_setFreqDiv(
    LCD_Regs *lcd, DL_LCD_FREQ_DIVIDE fDiv)
{
    DL_Common_updateReg(
        &lcd->LCDCTL0, (uint32_t) fDiv, LCD_LCDCTL0_LCDDIVX_MASK);
}

/**
 *  @brief Get the LCD frequency divider
 *
 *  @param[in]  lcd     Pointer to the register overlay for the peripheral
 *
 *  @return     The current frequency divider
 *
 *  @retval     One of @ref DL_LCD_FREQ_DIVIDE
 */
__STATIC_INLINE DL_LCD_FREQ_DIVIDE DL_LCD_getFreqDiv(LCD_Regs *lcd)
{
    uint32_t fDiv = (lcd->LCDCTL0 & LCD_LCDCTL0_LCDDIVX_MASK);

    return (DL_LCD_FREQ_DIVIDE)(fDiv);
}

/**
 *  @brief Set the LCD mux rate
 *
 *  @param[in]  lcd        Pointer to the register overlay for the peripheral
 *  @param[in]  muxRate    The mux rate to set. One of @ref DL_LCD_MUX_RATE
 *
 *
 *  @pre        The LCD module must be off (LCDCTL0.LCDON == 0) before setting
 *              this configuration. The LCD module can be disabled by calling
 *              DL_LCD_disableModule.
 *
 */
__STATIC_INLINE void DL_LCD_setMuxRate(
    LCD_Regs *lcd, DL_LCD_MUX_RATE muxRate)
{
    DL_Common_updateReg(
        &lcd->LCDCTL0, (uint32_t) muxRate, LCD_LCDCTL0_LCDMXX_MASK);
}

/**
 *  @brief Get the LCD mux rate
 *
 *  @param[in]  lcd     Pointer to the register overlay for the peripheral
 *
 *  @return     The mux rate
 *
 *  @retval     One of @ref DL_LCD_MUX_RATE
 */
__STATIC_INLINE DL_LCD_MUX_RATE DL_LCD_getMuxRate(LCD_Regs *lcd)
{
    uint32_t muxRate = (lcd->LCDCTL0 & LCD_LCDCTL0_LCDMXX_MASK);

    return (DL_LCD_MUX_RATE)(muxRate);
}

/**
 * @brief Turns LCD segments on
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_turnSegmentsOn(LCD_Regs *lcd)
{
    lcd->LCDCTL0 |= LCD_LCDCTL0_LCDSON_LCD_SEG_ON;
}

/**
 * @brief Turns LCD segments off
 *
 * Can be used to flash LCD applications by turning off segment lines
 * and leaving LCD timing generator and R33 enabled.
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_turnSegmentsOff(LCD_Regs *lcd)
{
    lcd->LCDCTL0 &= ~(LCD_LCDCTL0_LCDSON_MASK);
}

/**
 *  @brief Set the waveform power mode
 *
 *  @param[in]  lcd                 Pointer to the register overlay for the
 *                                  peripheral
 *  @param[in]  waveformPowerMode   The power mode for LCD waveforms.
 *                                  One of @ref DL_LCD_WAVEFORM_POWERMODE
 *
 *  @pre        The LCD module must be in 1/3 bias mode (LCDBIASSEL == 0)
 *              before setting this configuration.
 */
__STATIC_INLINE void DL_LCD_setWaveformPowerMode(
    LCD_Regs *lcd, DL_LCD_WAVEFORM_POWERMODE waveformPowerMode)
{
    DL_Common_updateReg(
        &lcd->LCDCTL0, (uint32_t) waveformPowerMode, LCD_LCDCTL0_LCDLP_MASK);
}

/**
 *  @brief Get the waveform power mode
 *
 *  @param[in]  lcd Pointer to the register overlay for the peripheral
 *
 *  @return     The waveform power mode
 *
 *  @retval     One of @ref DL_LCD_WAVEFORM_POWERMODE
 */
__STATIC_INLINE DL_LCD_WAVEFORM_POWERMODE DL_LCD_getWaveformPowerMode(
    LCD_Regs *lcd)
{
    uint32_t waveformPowerMode = (lcd->LCDCTL0 & LCD_LCDCTL0_LCDLP_MASK);

    return (DL_LCD_WAVEFORM_POWERMODE)(waveformPowerMode);
}

/**
 * @brief Enables the LCD module
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_enable(LCD_Regs *lcd)
{
    lcd->LCDCTL0 |= LCD_LCDCTL0_LCDON_LCD_MOD_ENABLE;
}

/**
 * @brief Disables the LCD module
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_disable(LCD_Regs *lcd)
{
    lcd->LCDCTL0 &= ~(LCD_LCDCTL0_LCDON_MASK);
}

/**
 *  @brief Set the blinking frequency divider and blinking mode
 *
 *  @param[in] lcd          Pointer to the register overlay for the peripheral
 *  @param[in] blinkFreqDiv The blinking frequency divider to set.
 *                          One of @ref DL_LCD_BLINKING_DIVIDE
 *  @param[in] blinkMode    The blinking mode to select.
 *                          One of @ref DL_LCD_BLINKING_MODE
 */
__STATIC_INLINE void DL_LCD_setBlinkingControl(
    LCD_Regs *lcd, DL_LCD_BLINKING_DIVIDE blinkFreqDiv,
    DL_LCD_BLINKING_MODE blinkMode)
{
    DL_Common_updateReg(&lcd->LCDBLKCTL, (uint32_t) blinkFreqDiv |
        (uint32_t) blinkMode, LCD_LCDBLKCTL_LCDBLKPREX_MASK |
        LCD_LCDBLKCTL_LCDBLKMODX_MASK);
}

/**
 *  @brief Get the blinking frequency divider
 *
 *  @param[in]  lcd Pointer to the register overlay for the peripheral
 *
 *  @return     The current blinking frequency divider
 *
 *  @retval     One of @ref DL_LCD_BLINKING_DIVIDE
 */
__STATIC_INLINE DL_LCD_BLINKING_DIVIDE DL_LCD_getBlinkingFreqDiv(LCD_Regs *lcd)
{
    uint32_t blinkFreqDiv = (lcd->LCDBLKCTL & LCD_LCDBLKCTL_LCDBLKPREX_MASK);

    return (DL_LCD_BLINKING_DIVIDE)(blinkFreqDiv);
}

/**
 *  @brief Get the blinking mode
 *
 *  @param[in]  lcd Pointer to the register overlay for the peripheral
 *
 *  @return     The current blinking mode
 *
 *  @retval     One of @ref DL_LCD_BLINKING_MODE
 */
__STATIC_INLINE DL_LCD_BLINKING_MODE DL_LCD_getBlinkingMode(LCD_Regs *lcd)
{
    uint32_t blinkMode = (lcd->LCDBLKCTL & LCD_LCDBLKCTL_LCDBLKMODX_MASK);

    return (DL_LCD_BLINKING_MODE)(blinkMode);
}

/**
 *  @brief Clear LCD blinking memory
 *
 *  Clears all blinking memory registers LCDBMx.
 *  The bit is automatically reset when blinking memory cleared.
 *
 *  @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_clearAllBlinkingMemoryRegs(LCD_Regs *lcd)
{
    DL_Common_updateReg(&lcd->LCDMEMCTL,
        LCD_LCDMEMCTL_LCDCLRBM_CLR_BLNK_MEM_REGS, LCD_LCDMEMCTL_LCDCLRBM_MASK);
}

/**
 *  @brief Clear LCD memory
 *
 *  Clears all memory registers LCDMx.
 *  The bit is automatically reset when LCD memory cleared.
 *
 *  @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_clearAllMemoryRegs(LCD_Regs *lcd)
{
    DL_Common_updateReg(&lcd->LCDMEMCTL, LCD_LCDMEMCTL_LCDCLRM_CLR_LCD_MEM_REGS,
        LCD_LCDMEMCTL_LCDCLRM_MASK);
}

/**
 *  @brief Select LCD memory registers for display
 *
 *  @param[in]  lcd     Pointer to the register overlay for the peripheral
 *  @param[in]  dispSel The memory registers to select. One of @ref DL_LCD_DISP
 *
 *  @pre        LCDDISP can only be set by software when LCDBLKMODx is disabled.
 *              Bit cleared/cannot be changed by software when
 *              LCDBLKMODx == DL_LCD_BLINKING_MODE_INDIVIDUAL_SEGMENTS,
 *              DL_LCD_BLINKING_MODE_ALL_SEGMENTS or if a mux mode = 5 selected.
 */
__STATIC_INLINE void DL_LCD_selectMemRegsForDisplay(
    LCD_Regs *lcd, DL_LCD_DISP dispSel)
{
    DL_Common_updateReg(&lcd->LCDMEMCTL, (uint32_t) dispSel,
        LCD_LCDMEMCTL_LCDDISP_MASK);
}

/**
 *  @brief Get the LCD memory registers selected for display
 *
 *  When LCDBLKMODx = DL_LCD_BLINKING_MODE_TOGGLE, this bit reflects the
 *  currently displayed memory but cannot be changed by software.
 *  When returning to LCDBLKMODx is disabled, bit is cleared.
 *
 *  @param[in]  lcd Pointer to the register overlay for the peripheral
 *
 *  @return     LCD memory registers selected for display
 *
 *  @retval     One of @ref DL_LCD_DISP
 */
__STATIC_INLINE DL_LCD_DISP DL_LCD_getSelectedMemRegsForDisplay(LCD_Regs *lcd)
{
    uint32_t dispSel = (lcd->LCDMEMCTL & LCD_LCDMEMCTL_LCDDISP_MASK);

    return (DL_LCD_DISP)(dispSel);
}

/**
 * @brief Enables VBOOST on LCD module
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_enableVBOOST(LCD_Regs *lcd)
{
    lcd->LCDVCTL |= LCD_LCDVCTL_LCDVBSTEN_ENABLE;
}

/**
 * @brief Disables VBOOST on LCD module
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_disableVBOOST(LCD_Regs *lcd)
{
    lcd->LCDVCTL &= ~(LCD_LCDVCTL_LCDVBSTEN_MASK);
}

/**
 *  @brief Set charge pump frequency
 *
 *  @param[in] lcd              Pointer to the register overlay for the
 *                              peripheral
 *  @param[in] chargePumpFreq   The charge pump frequency to select.
 *                              One of @ref DL_LCD_CHARGE_PUMP_FREQUENCY
 *
 */
__STATIC_INLINE void DL_LCD_setChargePumpFreq(
    LCD_Regs *lcd, DL_LCD_CHARGE_PUMP_FREQUENCY chargePumpFreq)
{
    DL_Common_updateReg(&lcd->LCDVCTL, (uint32_t) chargePumpFreq,
        LCD_LCDVCTL_LCDCPFSELX_MASK);
}

/**
 *  @brief Get the charge pump frequency
 *
 *  @param[in]  lcd Pointer to the register overlay for the peripheral
 *
 *  @return     The current charge pump frequency
 *
 *  @retval     One of @ref DL_LCD_CHARGE_PUMP_FREQUENCY
 */
__STATIC_INLINE DL_LCD_CHARGE_PUMP_FREQUENCY DL_LCD_getChargePumpFreq(
    LCD_Regs *lcd)
{
    uint32_t chargePumpFreq = (lcd->LCDVCTL & LCD_LCDVCTL_LCDCPFSELX_MASK);

    return (DL_LCD_CHARGE_PUMP_FREQUENCY)(chargePumpFreq);
}

/**
 *  @brief Set internal reference voltage
 *
 *  @param[in] lcd          Pointer to the register overlay for the peripheral
 *  @param[in] vrefInternal The internal reference voltage to select.
 *                          One of @ref DL_LCD_VREF_INTERNAL
 *
 */
__STATIC_INLINE void DL_LCD_setVREFInternal(
    LCD_Regs *lcd, DL_LCD_VREF_INTERNAL vrefInternal)
{
    DL_Common_updateReg(&lcd->LCDVCTL, (uint32_t) vrefInternal,
        LCD_LCDVCTL_VLCDX_MASK);
}

/**
 *  @brief Get the internal reference voltage
 *
 *  @param[in]  lcd Pointer to the register overlay for the peripheral
 *
 *  @return     The current internal reference voltage
 *
 *  @retval     One of @ref DL_LCD_VREF_INTERNAL
 */
__STATIC_INLINE DL_LCD_VREF_INTERNAL DL_LCD_getVREFInternal(LCD_Regs *lcd)
{
    uint32_t vrefInternal = (lcd->LCDVCTL & LCD_LCDVCTL_VLCDX_MASK);

    return (DL_LCD_VREF_INTERNAL)(vrefInternal);
}

/**
 * @brief Enables charge pump
 *
 * @param   lcd    Pointer to the register overlay for the peripheral
 *
 * @pre     VLCD must be generated internally (VLCDEXT = 0) and VLCD > 0 or
 *          VLCDREFx > 0 in order to use this configuration.
 */
__STATIC_INLINE void DL_LCD_enableChargePump(LCD_Regs *lcd)
{
    lcd->LCDVCTL |= LCD_LCDVCTL_LCDCPEN_CP_ENABLE;
}

/**
 * @brief Disables charge pump
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_disableChargePump(LCD_Regs *lcd)
{
    lcd->LCDVCTL &= ~(LCD_LCDVCTL_LCDCPEN_MASK);
}

/**
 * @brief Enables internal reference voltage
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_LCD_enableVREFInternal(LCD_Regs *lcd)
{
    lcd->LCDVCTL |= LCD_LCDVCTL_LCDREFEN_INT_REF_ENABLE;
}

/**
 * @brief Disables internal reference voltage
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_disableVREFInternal(LCD_Regs *lcd)
{
    lcd->LCDVCTL &= ~(LCD_LCDVCTL_LCDREFEN_MASK);
}

/**
 *  @brief Set source for R33
 *
 *  @param[in] lcd          Pointer to the register overlay for the peripheral
 *  @param[in] r33Source    The internal reference voltage to select.
 *                          One of @ref DL_LCD_R33_SOURCE
 *
 */
__STATIC_INLINE void DL_LCD_setR33source(
    LCD_Regs *lcd, DL_LCD_R33_SOURCE r33Source)
{
    DL_Common_updateReg(&lcd->LCDVCTL, (uint32_t) r33Source,
        LCD_LCDVCTL_LCDSELVDD_MASK);
}

/**
 *  @brief Get the source for R33
 *
 *  @param[in]  lcd Pointer to the register overlay for the peripheral
 *
 *  @return     The current source for R33
 *
 *  @retval     One of @ref DL_LCD_R33_SOURCE
 */
__STATIC_INLINE DL_LCD_R33_SOURCE DL_LCD_getR33Source(LCD_Regs *lcd)
{
    uint32_t r33Source = (lcd->LCDVCTL & LCD_LCDVCTL_LCDSELVDD_MASK);

    return (DL_LCD_R33_SOURCE)(r33Source);
}

/**
 *  @brief Select internal bias power mode
 *
 *  @param[in]  lcd         Pointer to the register overlay for the peripheral
 *  @param[in]  powerMode   The power mode to use for generating bias voltage
 *                          for LCD. One of @ref DL_LCD_POWER_MODE
 *
 *  @pre    The user must first enable the internal bias voltage resistor
 *          divider by calling @ref DL_LCD_enableInternalBias
 */
__STATIC_INLINE void DL_LCD_setInternalBiasPowerMode(
    LCD_Regs *lcd, DL_LCD_POWER_MODE powerMode)
{
    DL_Common_updateReg(&lcd->LCDVCTL, (uint32_t) powerMode,
        LCD_LCDVCTL_LCD_HP_LP_MASK);
}

/**
 *  @brief Get power mode
 *
 *  @param[in]  lcd Pointer to the register overlay for the peripheral
 *
 *  @return     The power mode
 *
 *  @retval     One of @ref DL_LCD_POWER_MODE
 */
__STATIC_INLINE DL_LCD_POWER_MODE DL_LCD_getPowerMode(LCD_Regs *lcd)
{
    uint32_t powerMode = (lcd->LCDVCTL & LCD_LCDVCTL_LCDSELVDD_MASK);

    return (DL_LCD_POWER_MODE)(powerMode);
}

/**
 *  @brief Set bias voltage source
 *
 *  @param[in]  lcd                 Pointer to the register overlay for the
 *                                  peripheral
 *  @param[in]  biasVoltageSource   The bias voltage source.
 *                                  One of @ref DL_LCD_BIAS_VOLTAGE_SOURCE
 *
 *  @pre        The user must first enable the internal bias voltage resistor
                divider by calling @ref DL_LCD_enableInternalBias
 */
__STATIC_INLINE void DL_LCD_setBiasVoltageSource(
    LCD_Regs *lcd, DL_LCD_BIAS_VOLTAGE_SOURCE biasVoltageSource)
{
    DL_Common_updateReg(&lcd->LCDVCTL, (uint32_t) biasVoltageSource,
        LCD_LCDVCTL_VLCDSEL_VDD_R33_MASK);
}

/**
 *  @brief Get bias voltage source
 *
 *  @param[in]  lcd Pointer to the register overlay for the peripheral
 *
 *  @return     The bias voltage source
 *
 *  @retval     One of @ref DL_LCD_BIAS_VOLTAGE_SOURCE
 */
__STATIC_INLINE DL_LCD_BIAS_VOLTAGE_SOURCE DL_LCD_getBiasVoltageSource(
    LCD_Regs *lcd)
{
    uint32_t biasVoltageSource = (
        lcd->LCDVCTL & LCD_LCDVCTL_VLCDSEL_VDD_R33_MASK);

    return (DL_LCD_BIAS_VOLTAGE_SOURCE)(biasVoltageSource);
}

/**
 * @brief Enables internal bias voltage resistor divider
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_LCD_enableInternalBias(LCD_Regs *lcd)
{
    lcd->LCDVCTL |= LCD_LCDVCTL_LCDINTBIASEN_INT_BIAS_ENABLE;
}

/**
 * @brief Disables internal bias voltage resistor divider
 *
 * @param lcd   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_LCD_disableInternalBias(LCD_Regs *lcd)
{
    lcd->LCDVCTL &= ~(LCD_LCDVCTL_LCDINTBIASEN_MASK);
}

/**
 *  @brief Select LCD bias
 *
 *  @param[in]  lcd     Pointer to the register overlay for the peripheral
 *  @param[in]  biasSel The bias. One of @ref DL_LCD_BIAS
 *
 *  @note       This bit (LCDBIASSEL) is ignored in static mode and for 2-mux,
 *              3-mux, and 4-mux LCD modes
 */
__STATIC_INLINE void DL_LCD_setBias(
    LCD_Regs *lcd, DL_LCD_BIAS biasSel)
{
    DL_Common_updateReg(
        &lcd->LCDVCTL, (uint32_t) biasSel, LCD_LCDVCTL_LCDBIASSEL_MASK);
}

/**
 *  @brief Get bias for LCD
 *
 *  @param[in]  lcd Pointer to the register overlay for the peripheral
 *
 *  @return     The bias for the LCD
 *
 *  @retval     One of @ref DL_LCD_BIAS
 */
__STATIC_INLINE DL_LCD_BIAS DL_LCD_getBias(LCD_Regs *lcd)
{
    uint32_t biasSel = (lcd->LCDVCTL & LCD_LCDVCTL_LCDBIASSEL_MASK);

    return (DL_LCD_BIAS)(biasSel);
}

/**
 *  @brief Set reference mode for R13 voltage
 *
 *  @param[in] lcd      Pointer to the register overlay for the peripheral
 *  @param[in] refMode  Ref mode. One of @ref DL_LCD_REFERENCE_MODE
 *
 */
__STATIC_INLINE void DL_LCD_setRefMode(
    LCD_Regs *lcd, DL_LCD_REFERENCE_MODE refMode)
{
    DL_Common_updateReg(
        &lcd->LCDVCTL, (uint32_t) refMode, LCD_LCDVCTL_LCDREFMODE_MASK);
}

/**
 *  @brief Get reference mode for R13 voltage
 *
 *  @param[in]  lcd Pointer to the register overlay for the peripheral
 *
 *  @return     Voltage reference mode
 *
 *  @retval     One of @ref DL_LCD_REFERENCE_MODE
 */
__STATIC_INLINE DL_LCD_REFERENCE_MODE DL_LCD_getRefMode(LCD_Regs *lcd)
{
    uint32_t refMode = (lcd->LCDVCTL & LCD_LCDVCTL_LCDREFMODE_MASK);

    return (DL_LCD_REFERENCE_MODE)(refMode);
}

/**
 *  @brief Write to bits in LCD memory index register
 *
 *  @param[in]  lcd         Pointer to the register overlay for the peripheral
 *  @param[in]  memIndex    Index of LCDMx register to write to.
 *                          One of @ref DL_LCD_MEMORY.
 *  @param[in]  mask        Registers to set in LCDMx register.
 *                          Bitwise OR of @ref DL_LCD_MEMORY_BIT.
 */
__STATIC_INLINE void DL_LCD_writeMemory(
    LCD_Regs *lcd, DL_LCD_MEMORY memIndex, uint32_t mask)
{
    lcd -> LCDM[(uint32_t) memIndex] = mask;
}

/**
 *  @brief Set bits in LCD memory index register
 *
 *  @param[in]  lcd         Pointer to the register overlay for the peripheral
 *  @param[in]  memIndex    Index of LCDMx register to write to.
 *                          One of @ref DL_LCD_MEMORY.
 *  @param[in]  mask        Registers to set in LCDMx register.
 *                          Bitwise OR of @ref DL_LCD_MEMORY_BIT.
 */
__STATIC_INLINE void DL_LCD_setMemory(
    LCD_Regs *lcd, DL_LCD_MEMORY memIndex, uint32_t mask)
{
    lcd -> LCDM[(uint32_t) memIndex] |= mask;
}

/**
 *  @brief Toggle bits in LCD memory index register
 *
 *  @param[in]  lcd         Pointer to the register overlay for the peripheral
 *  @param[in]  memIndex    Index of LCDMx register to write to.
 *                          One of @ref DL_LCD_MEMORY.
 *  @param[in]  mask        Registers to set in LCDMx register.
 *                          Bitwise OR of @ref DL_LCD_MEMORY_BIT.
 */
__STATIC_INLINE void DL_LCD_toggleMemory(
    LCD_Regs *lcd, DL_LCD_MEMORY memIndex, uint32_t mask)
{
    lcd -> LCDM[(uint32_t) memIndex] ^= mask;
}

/**
 *  @brief Clear bits in LCD memory index register
 *
 *  @param[in]  lcd         Pointer to the register overlay for the peripheral
 *  @param[in]  memIndex    Index of LCDMx register to write to.
 *                          One of @ref DL_LCD_MEMORY.
 *  @param[in]  mask        Registers to set in LCDMx register.
 *                          Bitwise OR of @ref DL_LCD_MEMORY_BIT.
 */
__STATIC_INLINE void DL_LCD_clearMemory(
    LCD_Regs *lcd, DL_LCD_MEMORY memIndex, uint32_t mask)
{
    lcd -> LCDM[(uint32_t) memIndex] &= ~(mask);
}

/**
 *  @brief Get bits in LCD memory index register
 *
 *  @param[in]  lcd         Pointer to the register overlay for the peripheral
 *  @param[in]  memIndex    Index of LCDMx register to read from.
 *
 *  @retval     32 bit value of register
 *
 *  @sa         DL_LCD_MEMORY_BIT
 */
__STATIC_INLINE uint32_t DL_LCD_getMemory(
    LCD_Regs *lcd, DL_LCD_MEMORY memIndex)
{
    return lcd -> LCDM[(uint32_t) memIndex];
}

/**
 *  @brief Write to bits in LCD blinking memory index register
 *
 *  @param[in]  lcd         Pointer to the register overlay for the peripheral
 *  @param[in]  memIndex    Index of LCDMx register to write to.
 *                          One of @ref DL_LCD_BLINKING_MEMORY.
 *  @param[in]  mask        Registers to set in LCDBMx register.
 *                          Bitwise OR of @ref DL_LCD_BLINK_MEMORY_BIT.
 */
__STATIC_INLINE void DL_LCD_writeBlinkingMemory(
    LCD_Regs *lcd, DL_LCD_BLINKING_MEMORY memIndex, uint32_t mask)
{
    lcd -> LCDBM[(uint32_t) memIndex] = mask;
}

/**
 *  @brief Set bits in LCD blinking memory index register
 *
 *  @param[in]  lcd         Pointer to the register overlay for the peripheral
 *  @param[in]  memIndex    Index of LCDMx register to write to.
 *                          One of @ref DL_LCD_BLINKING_MEMORY.
 *  @param[in]  mask        Registers to set in LCDBMx register.
 *                          Bitwise OR of @ref DL_LCD_BLINK_MEMORY_BIT.
 */
__STATIC_INLINE void DL_LCD_setBlinkingMemory(
    LCD_Regs *lcd, DL_LCD_BLINKING_MEMORY memIndex, uint32_t mask)
{
    lcd -> LCDBM[(uint32_t) memIndex] |= mask;
}

/**
 *  @brief Toggle bits in LCD blinking memory index register
 *
 *  @param[in]  lcd         Pointer to the register overlay for the peripheral
 *  @param[in]  memIndex    Index of LCDMx register to write to.
 *                          One of @ref DL_LCD_BLINKING_MEMORY.
 *  @param[in]  mask        Registers to set in LCDBMx register.
 *                          Bitwise OR of @ref DL_LCD_BLINK_MEMORY_BIT.
 */
__STATIC_INLINE void DL_LCD_toggleBlinkingMemory(
    LCD_Regs *lcd, DL_LCD_BLINKING_MEMORY memIndex, uint32_t mask)
{
    lcd -> LCDBM[(uint32_t) memIndex] ^= mask;
}

/**
 *  @brief Clear bits in LCD blinking memory index register
 *
 *  @param[in]  lcd         Pointer to the register overlay for the peripheral
 *  @param[in]  memIndex    Index of LCDMx register to write to.
 *                          One of @ref DL_LCD_BLINKING_MEMORY.
 *  @param[in]  mask        Registers to set in LCDBMx register.
 *                          Bitwise OR of @ref DL_LCD_BLINK_MEMORY_BIT.
 */
__STATIC_INLINE void DL_LCD_clearBlinkingMemory(
    LCD_Regs *lcd, DL_LCD_BLINKING_MEMORY memIndex, uint32_t mask)
{
    lcd -> LCDBM[(uint32_t) memIndex] &= ~(mask);
}

/**
 *  @brief Get bits in LCD blinking memory index register
 *
 *  @param[in]  lcd         Pointer to the register overlay for the peripheral
 *  @param[in]  memIndex    Index of LCDMx register to read from.
 *
 *  @retval     32 bit value of register
 *
 *  @sa         DL_LCD_BLINK_MEMORY_BIT
 */
__STATIC_INLINE uint32_t DL_LCD_getBlinkingMemory(
    LCD_Regs *lcd, DL_LCD_BLINKING_MEMORY memIndex)
{
    return lcd -> LCDBM[(uint32_t) memIndex];
}

/**
 *  @brief Set number of cycles to enable voltage generation circuitry
 *
 *  @param[in] lcd      Pointer to the register overlay for the peripheral
 *  @param[in] cycles   The number of cycles to enable voltage generation circuitry.
 *                      One of @ref DL_LCD_VREFGEN_CYCLES.
 */
__STATIC_INLINE void DL_LCD_setVrefOnTimeCycles(
    LCD_Regs *lcd, DL_LCD_VREFGEN_CYCLES cycles)
{
    DL_Common_updateReg(&lcd->LCDVREFCFG, (uint32_t) cycles,
        LCD_LCDVREFCFG_ONTIME_MASK);
}

/**
 *  @brief Get the number of cycles set to enable voltage generation circuitry
 *
 *  @param[in]  lcd  Pointer to the register overlay for the peripheral
 *
 *  @return     The number of cycles
 *
 *  @retval     One of @ref DL_LCD_VREFGEN_CYCLES
 */
__STATIC_INLINE DL_LCD_VREFGEN_CYCLES DL_LCD_getVrefOnTimeCycles(LCD_Regs *lcd)
{
    uint32_t cycles = (lcd->LCDVREFCFG & LCD_LCDVREFCFG_ONTIME_MASK);

    return (DL_LCD_VREFGEN_CYCLES)(cycles);
}

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_LCD__ */

#endif /* ti_dl_dl_lcd__include */
/** @}*/
