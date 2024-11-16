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
#include <ti/driverlib/dl_lcd.h>

#ifdef __MSPM0_HAS_LCD__

/**
 *  @brief LCD APIs
 */

void DL_LCD_init(LCD_Regs *lcd, DL_LCD_Config *config)
{
    DL_Common_updateReg(&lcd->LCDCTL0,
        (uint32_t) config->frequencyDivider | (uint32_t) config->muxRate |
            (uint32_t) config->lowPowerWaveform,
        LCD_LCDCTL0_LCDDIVX_MASK | LCD_LCDCTL0_LCDMXX_MASK |
            LCD_LCDCTL0_LCDLP_MASK);
}

void DL_LCD_setPinAsLCDFunction(LCD_Regs *lcd, uint32_t pin)
{
    lcd->LCDCTL0 &= ~(LCD_LCDCTL0_LCDON_MASK); /* turn off LCD module */

    uint8_t idx  = pin >> 4; /* get index in corresponding port control reg */
    uint16_t val = 1 << (pin & 0x0F); /* get mask to set that specific bit */

    switch (idx) {
        case 0:
            lcd->LCDPCTL0 |= val;
            break;
        case 1:
            lcd->LCDPCTL1 |= val;
            break;
        case 2:
            lcd->LCDPCTL2 |= val;
            break;
        case 3:
            lcd->LCDPCTL3 |= val;
            break;
        default:
            break;
    }
}

void DL_LCD_setPinAsPortFunction(LCD_Regs *lcd, uint8_t pin)
{
    lcd->LCDCTL0 &= ~(LCD_LCDCTL0_LCDON_MASK); /* turn off LCD module */

    uint8_t idx  = pin >> 4; /* get index in corresponding port control reg */
    uint16_t val = 1 << (pin & 0x0F); /* get mask to set that specific bit */

    switch (idx) {
        case 0:
            lcd->LCDPCTL0 &= ~(val);
            break;
        case 1:
            lcd->LCDPCTL1 &= ~(val);
            break;
        case 2:
            lcd->LCDPCTL2 &= ~(val);
            break;
        case 3:
            lcd->LCDPCTL3 &= ~(val);
            break;
        default:
            break;
    }
}

void DL_LCD_setPinAsCommon(LCD_Regs *lcd, uint8_t pin, uint32_t com)
{
    lcd->LCDCTL0 &= ~(LCD_LCDCTL0_LCDON_MASK);

    uint8_t idx  = pin >> 4;          /* 0-15 -> 0, 16-31 -> 1, etc. */
    uint16_t val = 1 << (pin & 0x0F); /* getting mask for val based on pin */
    uint8_t muxRate = lcd->LCDCTL0 & (LCD_LCDCTL0_LCDMXX_MASK);

    switch (idx) {
        case 0:
            lcd->LCDCSSEL0 |= val;
            break;
        case 1:
            lcd->LCDCSSEL1 |= val;
            break;
        case 2:
            lcd->LCDCSSEL2 |= val;
            break;
        case 3:
            lcd->LCDCSSEL3 |= val;
            break;
        default:
            break;
    }

    /* Set LCDMem to COM as well for corresponding pins */
    if (muxRate == (LCD_LCDCTL0_LCDMXX_MX_STATIC | LCD_LCDCTL0_LCDMXX_MX_2 |
                       LCD_LCDCTL0_LCDMXX_MX_3 | LCD_LCDCTL0_LCDMXX_MX_4)) {
        if (pin & 1) {
            /* upper nibble */
            lcd->LCDM[pin / 2] |= (com & 0xF) << 4;
            lcd->LCDBM[pin / 2] |= (com & 0xF) << 4;
        } else {
            /* lower nibble */
            lcd->LCDM[pin / 2] |= (com & 0xF);
            lcd->LCDBM[pin / 2] |= (com & 0xF);
        }
    } else {
        /* 5-mux, 6-mux, 7-mux, 8-mux, whole byte per segment pin */
        lcd->LCDM[pin] |= com;
        lcd->LCDBM[pin] |= com;
    }
}

void DL_LCD_setPinAsSegment(LCD_Regs *lcd, uint8_t pin)
{
    lcd->LCDCTL0 &= ~(LCD_LCDCTL0_LCDON_MASK);

    uint8_t idx  = pin >> 4;          /* 0-15 -> 0, 16-31 -> 1, etc. */
    uint16_t val = 1 << (pin & 0x0F); /* getting mask for val based on pin */

    switch (idx) {
        case 0:
            lcd->LCDCSSEL0 &= ~val;
            break;
        case 1:
            lcd->LCDCSSEL1 &= ~val;
            break;
        case 2:
            lcd->LCDCSSEL2 &= ~val;
            break;
        case 3:
            lcd->LCDCSSEL3 &= ~val;
            break;
        default:
            break;
    }
}

#endif /* __MSPM0_HAS_LCD__ */
