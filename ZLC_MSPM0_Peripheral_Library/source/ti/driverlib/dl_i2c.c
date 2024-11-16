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

#include <ti/driverlib/dl_i2c.h>

#ifdef __MSPM0_HAS_I2C__

/**
 *  @brief I2C Controller APIs
 */

void DL_I2C_setClockConfig(I2C_Regs *i2c, DL_I2C_ClockConfig *config)
{
    DL_Common_updateReg(&i2c->CLKSEL, (uint32_t) config->clockSel,
        I2C_CLKSEL_BUSCLK_SEL_MASK | I2C_CLKSEL_MFCLK_SEL_MASK);

    DL_Common_updateReg(
        &i2c->CLKDIV, (uint32_t) config->divideRatio, I2C_CLKDIV_RATIO_MASK);
}

void DL_I2C_getClockConfig(I2C_Regs *i2c, DL_I2C_ClockConfig *config)
{
    uint32_t clockSel =
        i2c->CLKSEL & (I2C_CLKSEL_BUSCLK_SEL_MASK | I2C_CLKSEL_MFCLK_SEL_MASK);
    config->clockSel = (DL_I2C_CLOCK)(clockSel);

    uint32_t divideRatio = i2c->CLKDIV & I2C_CLKDIV_RATIO_MASK;
    config->divideRatio  = (DL_I2C_CLOCK_DIVIDE)(divideRatio);
}

uint16_t DL_I2C_fillControllerTXFIFO(
    I2C_Regs *i2c, uint8_t *buffer, uint16_t count)
{
    uint16_t i;
    for (i = (uint16_t) 0; i < count; i++) {
        if (DL_I2C_isControllerTXFIFOFull(i2c) == false) {
            DL_I2C_transmitControllerData(i2c, buffer[i]);
        } else {  // Controller TX FIFO is full
            break;
        }
    }
    return i;
}

void DL_I2C_flushControllerTXFIFO(I2C_Regs *i2c)
{
    DL_I2C_startFlushControllerTXFIFO(i2c);
    while (DL_I2C_isControllerTXFIFOEmpty(i2c) == false) {
        ;
    }
    DL_I2C_stopFlushControllerTXFIFO(i2c);
}

void DL_I2C_flushControllerRXFIFO(I2C_Regs *i2c)
{
    DL_I2C_startFlushControllerRXFIFO(i2c);
    while (DL_I2C_isControllerRXFIFOEmpty(i2c) == false) {
        ;
    }
    DL_I2C_stopFlushControllerRXFIFO(i2c);
}

/**
 *  @brief I2C Target APIs
 */
uint8_t DL_I2C_fillTargetTXFIFO(I2C_Regs *i2c, uint8_t *buffer, uint8_t count)
{
    uint8_t i;
    for (i = (uint8_t) 0; i < count; i++) {
        if (DL_I2C_isTargetTXFIFOFull(i2c) == false) {
            DL_I2C_transmitTargetData(i2c, buffer[i]);
        } else {  // Target TX FIFO is full
            break;
        }
    }
    return i;
}

void DL_I2C_flushTargetTXFIFO(I2C_Regs *i2c)
{
    DL_I2C_startFlushTargetTXFIFO(i2c);
    while (DL_I2C_isTargetTXFIFOEmpty(i2c) == false) {
        ;
    }
    DL_I2C_stopFlushTargetTXFIFO(i2c);
}

void DL_I2C_flushTargetRXFIFO(I2C_Regs *i2c)
{
    DL_I2C_startFlushTargetRXFIFO(i2c);
    while (DL_I2C_isTargetRXFIFOEmpty(i2c) == false) {
        ;
    }
    DL_I2C_stopFlushTargetRXFIFO(i2c);
}

void DL_I2C_transmitTargetDataBlocking(I2C_Regs *i2c, uint8_t data)
{
    while ((DL_I2C_getTargetStatus(i2c) &
               DL_I2C_TARGET_STATUS_TRANSMIT_REQUEST) !=
           DL_I2C_TARGET_STATUS_TRANSMIT_REQUEST) {
        ;
    }
    DL_I2C_transmitTargetData(i2c, data);
}

bool DL_I2C_transmitTargetDataCheck(I2C_Regs *i2c, uint8_t data)
{
    bool status;
    if (DL_I2C_isTargetTXFIFOFull(i2c)) {
        status = false;
    } else {
        DL_I2C_transmitTargetData(i2c, data);
        status = true;
    }
    return status;
}

uint8_t DL_I2C_receiveTargetDataBlocking(I2C_Regs *i2c)
{
    while (
        (DL_I2C_getTargetStatus(i2c) & DL_I2C_TARGET_STATUS_RECEIVE_REQUEST) !=
        DL_I2C_TARGET_STATUS_RECEIVE_REQUEST) {
        ;
    }
    return DL_I2C_receiveTargetData(i2c);
}

bool DL_I2C_receiveTargetDataCheck(I2C_Regs *i2c, uint8_t *buffer)
{
    bool status;
    if (DL_I2C_isTargetRXFIFOEmpty(i2c)) {
        status = false;
    } else {
        *buffer = DL_I2C_receiveTargetData(i2c);
        status  = true;
    }
    return status;
}

#endif /* __MSPM0_HAS_I2C__ */
