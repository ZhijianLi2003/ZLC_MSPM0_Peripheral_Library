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

#include <ti/driverlib/dl_uart_extend.h>
#include <ti/driverlib/dl_uart_main.h>

#if defined(__MSPM0_HAS_UART_MAIN__) || defined(__MSPM0_HAS_UART_EXTD__)

void DL_UART_init(UART_Regs *uart, DL_UART_Config *config)
{
    DL_UART_disable(uart);

    DL_Common_updateReg(&uart->CTL0,
        (uint32_t) config->mode | (uint32_t) config->direction |
            (uint32_t) config->flowControl,
        UART_CTL0_RXE_MASK | UART_CTL0_TXE_MASK | UART_CTL0_MODE_MASK |
            UART_CTL0_RTSEN_MASK | UART_CTL0_CTSEN_MASK | UART_CTL0_FEN_MASK);

    DL_Common_updateReg(&uart->LCRH,
        (uint32_t) config->parity | (uint32_t) config->wordLength |
            (uint32_t) config->stopBits,
        UART_LCRH_PEN_ENABLE | UART_LCRH_EPS_MASK | UART_LCRH_SPS_MASK |
            UART_LCRH_WLEN_MASK | UART_LCRH_STP2_MASK);
}

void DL_UART_setClockConfig(UART_Regs *uart, DL_UART_ClockConfig *config)
{
    uart->CLKSEL = (uint32_t) config->clockSel;

    uart->CLKDIV = (uint32_t) config->divideRatio;
}

void DL_UART_getClockConfig(UART_Regs *uart, DL_UART_ClockConfig *config)
{
    config->clockSel = (DL_UART_CLOCK) uart->CLKSEL;

    config->divideRatio = (DL_UART_CLOCK_DIVIDE_RATIO) uart->CLKDIV;
}

void DL_UART_configBaudRate(
    UART_Regs *uart, uint32_t clockFreq, uint32_t baudRate)
{
    uint32_t divisor;

    /*
     *  The baud rate divisor, brd, is calculated with the following formula:
     *  brd = ibrd.fbrd = clockOutput / (OVS * baudRate)
     *  where ibrd is the integer part, fbrd is the fractional part.
     *  Since fbrd is 6 bits, multiply brd by 64:
     *       64 * brd = (clockOutput * 64) / (16 * baudRate)
     *                = (clockOutput * 4) / baudRate
     *    add 1/2 to round the least significant bit of fbrd:
     *        64 * brd + 1/2 = (clockOutput * 8 / (2 * baudRate) + 1/2
     *        divisor = 64*brd+1/2  = [(clockOutput * 8)/ baudRate + 1] / 2
     *
     *  The lower 6 bits is fbrd, upper part is ibrd
     *  Note: If ibrd is 0, FBRD will be ignored and no data will be
     *  transferred.
     */

    /*  Calculate baud rate divisor based on OVS: */
    if ((baudRate * (uint32_t) 8) > clockFreq) {
        DL_UART_setOversampling(uart, DL_UART_OVERSAMPLING_RATE_3X);
        divisor = ((clockFreq * (uint32_t) 64) / (baudRate * (uint32_t) 3)) +
                  ((uint32_t) 1 / (uint32_t) 2);

    } else if ((baudRate * (uint32_t) 16) > clockFreq) {
        DL_UART_setOversampling(uart, DL_UART_OVERSAMPLING_RATE_8X);
        baudRate = baudRate / (uint32_t) 2;
        divisor  = (((clockFreq * (uint32_t) 8) / baudRate) + (uint32_t) 1) /
                  (uint32_t) 2;

    } else {
        DL_UART_setOversampling(uart, DL_UART_OVERSAMPLING_RATE_16X);
        divisor = (((clockFreq * (uint32_t) 8) / baudRate) + (uint32_t) 1) /
                  (uint32_t) 2;
    }

    /* Set the integer and fractional parts of the baud rate divisor */
    DL_UART_setBaudRateDivisor(
        uart, divisor >> (uint32_t) 6, divisor & (uint32_t) 0x3F);
}

// TODO: Verify parameters and units
/**
 *  @brief      Set the IrDA configurations
 *
 *  Calculates the baud rate divisor given the clock output of the UART clock
 *  source and the target baud rate. This API also enables IrDA mode.
 *
 *  @param[in]  uart         Pointer to the register overlay for the peripheral
 *  @param[in]  polarity     The receive input polarity.
 *                           One of @DL_UART_IRDA_POLARITY.
 *  @param[in]  pulseLength  The length of the IrDA transmit pulse.
 *  @param[in]  irdaClk      The clock used for the transmit pulse.
 *                           One of @DL_UART_IRDA_CLOCK.
 */
void DL_UART_configIrDAMode(UART_Regs *uart, DL_UART_IRDA_POLARITY polarity,
    uint32_t pulseLength, DL_UART_IRDA_CLOCK irdaClk)
{
    DL_Common_updateReg(&uart->IRCTL,
        (uint32_t) polarity | UART_IRCTL_IREN_ENABLE,
        UART_IRCTL_IRRXPL_MASK | UART_IRCTL_IREN_MASK);

    DL_UART_setIrDAPulseLength(uart, pulseLength, irdaClk);
}

void DL_UART_setIrDAPulseLength(
    UART_Regs *uart, uint32_t pulseLength, DL_UART_IRDA_CLOCK irdaClk)
{
    uint32_t IRTXPL;

    if (pulseLength == DL_UART_PULSE_WIDTH_3_16_BIT_PERIOD) {
        // Set IRTXCLK = 0 = BITCLK16 and IRTXPL = 5
        DL_Common_updateReg(&uart->IRCTL, 0x14,
            UART_IRCTL_IRTXCLK_MASK | UART_IRCTL_IRTXPL_MASK);
    } else {
        IRTXPL =
            pulseLength * (uint32_t) 2 * (uint32_t) irdaClk - (uint32_t) 1;

        DL_Common_updateReg(&uart->IRCTL, IRTXPL,
            UART_IRCTL_IRTXCLK_MASK | UART_IRCTL_IRTXPL_MASK);
    }
}

uint8_t DL_UART_receiveDataBlocking(UART_Regs *uart)
{
    while (DL_UART_isRXFIFOEmpty(uart)) {
    };

    return DL_UART_receiveData(uart);
}

void DL_UART_transmitDataBlocking(UART_Regs *uart, uint8_t data)
{
    while (DL_UART_isTXFIFOFull(uart)) {
    };
    DL_UART_transmitData(uart, data);
}

bool DL_UART_receiveDataCheck(UART_Regs *uart, uint8_t *buffer)
{
    bool status;
    if (DL_UART_isRXFIFOEmpty(uart)) {
        status = false;
    } else {
        *buffer = DL_UART_receiveData(uart);
        status  = true;
    }

    return status;
}

bool DL_UART_transmitDataCheck(UART_Regs *uart, uint8_t data)
{
    bool status;
    if (DL_UART_isTXFIFOFull(uart)) {
        status = false;
    } else {
        DL_UART_transmitData(uart, data);
        status = true;
    }

    return status;
}

uint32_t DL_UART_drainRXFIFO(
    UART_Regs *uart, uint8_t *buffer, uint32_t maxCount)
{
    uint32_t i;
    for (i = 0; i < maxCount; i++) {
        if (!DL_UART_isRXFIFOEmpty(uart)) {
            buffer[i] = DL_UART_receiveData(uart);
        } else {
            break;
        }
    }

    return i;
}

uint32_t DL_UART_fillTXFIFO(UART_Regs *uart, uint8_t *buffer, uint32_t count)
{
    uint32_t i;
    for (i = 0; i < count; i++) {
        if (!DL_UART_isTXFIFOFull(uart)) {
            DL_UART_transmitData(uart, buffer[i]);
        } else {
            break;
        }
    }

    return i;
}
#ifdef __MSPM0_HAS_UART_MAIN__

bool DL_UART_Main_saveConfiguration(
    UART_Regs *uart, DL_UART_Main_backupConfig *ptr)
{
    bool stateSaved = !ptr->backupRdy;
    if (stateSaved) {
        ptr->controlWord                  = uart->CTL0;
        ptr->clockSel                     = uart->CLKSEL;
        ptr->divideRatio                  = uart->CLKDIV;
        ptr->interruptFifoLevelSelectWord = uart->IFLS;
        ptr->ibrd                         = uart->IBRD;
        ptr->fbrd                         = uart->FBRD;
        ptr->lineControlRegisterWord      = uart->LCRH;
        ptr->glitchFilterControlWord      = uart->GFCTL;
        ptr->interruptMask0               = uart->CPU_INT.IMASK;
        ptr->interruptMask1               = uart->DMA_TRIG_RX.IMASK;
        ptr->interruptMask2               = uart->DMA_TRIG_TX.IMASK;
        ptr->backupRdy                    = true;
    }
    return stateSaved;
}

bool DL_UART_Main_restoreConfiguration(
    UART_Regs *uart, DL_UART_Main_backupConfig *ptr)
{
    bool stateRestored = ptr->backupRdy;
    if (stateRestored) {
        /* Set CTL0.ENABLE=0 during initialization */
        uart->CTL0              = ptr->controlWord & ~(UART_CTL0_ENABLE_MASK);
        uart->CLKSEL            = ptr->clockSel;
        uart->CLKDIV            = ptr->divideRatio;
        uart->IFLS              = ptr->interruptFifoLevelSelectWord;
        uart->IBRD              = ptr->ibrd;
        uart->FBRD              = ptr->fbrd;
        uart->LCRH              = ptr->lineControlRegisterWord;
        uart->GFCTL             = ptr->glitchFilterControlWord;
        uart->CPU_INT.IMASK     = ptr->interruptMask0;
        uart->DMA_TRIG_RX.IMASK = ptr->interruptMask1;
        uart->DMA_TRIG_TX.IMASK = ptr->interruptMask2;

        /* Re-enable UART if it was originally enabled */
        if ((ptr->controlWord & UART_CTL0_ENABLE_MASK) ==
            UART_CTL0_ENABLE_MASK) {
            DL_UART_enable(uart);
        }
        ptr->backupRdy = false;
    }
    return stateRestored;
}

#endif /* __MSPM0_HAS_UART_MAIN__ */

#ifdef __MSPM0_HAS_UART_EXTD__

bool DL_UART_Extend_saveConfiguration(
    UART_Regs *uart, DL_UART_Extend_backupConfig *ptr)
{
    bool stateSaved = !ptr->backupRdy;
    if (stateSaved) {
        ptr->controlWord                  = uart->CTL0;
        ptr->clockSel                     = uart->CLKSEL;
        ptr->divideRatio                  = uart->CLKDIV;
        ptr->interruptFifoLevelSelectWord = uart->IFLS;
        ptr->ibrd                         = uart->IBRD;
        ptr->fbrd                         = uart->FBRD;
        ptr->lineControlRegisterWord      = uart->LCRH;
        ptr->glitchFilterControlWord      = uart->GFCTL;
        ptr->linControlWord               = uart->LINCTL;
        ptr->irdaControlWord              = uart->IRCTL;
        ptr->addressMask                  = uart->AMASK;
        ptr->address                      = uart->ADDR;
        ptr->interruptMask0               = uart->CPU_INT.IMASK;
        ptr->interruptMask1               = uart->DMA_TRIG_RX.IMASK;
        ptr->interruptMask2               = uart->DMA_TRIG_TX.IMASK;
        ptr->backupRdy                    = true;
    }
    return stateSaved;
}

bool DL_UART_Extend_restoreConfiguration(
    UART_Regs *uart, DL_UART_Extend_backupConfig *ptr)
{
    bool stateRestored = ptr->backupRdy;
    if (stateRestored) {
        /* Set CTL0.ENABLE=0 during initialization */
        uart->CTL0              = ptr->controlWord & ~(UART_CTL0_ENABLE_MASK);
        uart->CLKSEL            = ptr->clockSel;
        uart->CLKDIV            = ptr->divideRatio;
        uart->IFLS              = ptr->interruptFifoLevelSelectWord;
        uart->IBRD              = ptr->ibrd;
        uart->FBRD              = ptr->fbrd;
        uart->LCRH              = ptr->lineControlRegisterWord;
        uart->GFCTL             = ptr->glitchFilterControlWord;
        uart->LCRH              = ptr->lineControlRegisterWord;
        uart->IRCTL             = ptr->irdaControlWord;
        uart->AMASK             = ptr->addressMask;
        uart->ADDR              = ptr->address;
        uart->CPU_INT.IMASK     = ptr->interruptMask0;
        uart->DMA_TRIG_RX.IMASK = ptr->interruptMask1;
        uart->DMA_TRIG_TX.IMASK = ptr->interruptMask2;

        /* Re-enable UART if it was originally enabled */
        if ((ptr->controlWord & UART_CTL0_ENABLE_MASK) ==
            UART_CTL0_ENABLE_MASK) {
            DL_UART_enable(uart);
        }
        ptr->backupRdy = false;
    }
    return stateRestored;
}

#endif /* __MSPM0_HAS_UART_EXTD__ */

#endif /* __MSPM0_HAS_UART_MAIN__ || __MSPM0_HAS_UART_EXTD__ */
