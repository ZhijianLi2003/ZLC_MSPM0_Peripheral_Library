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

#include <ti/driverlib/dl_spi.h>

#ifdef __MSPM0_HAS_SPI__

void DL_SPI_init(SPI_Regs *spi, DL_SPI_Config *config)
{
    DL_Common_updateReg(&spi->CTL0,
        (uint32_t) config->chipSelectPin | (uint32_t) config->frameFormat |
            (uint32_t) config->dataSize,
        SPI_CTL0_CSSEL_MASK | SPI_CTL0_FRF_MASK | SPI_CTL0_SPO_MASK |
            SPI_CTL0_SPH_MASK | SPI_CTL0_DSS_MASK);

    DL_Common_updateReg(&spi->CTL1,
        (uint32_t) config->parity | (uint32_t) config->bitOrder |
            (uint32_t) config->mode,
        SPI_CTL1_PES_MASK | SPI_CTL1_PREN_MASK | SPI_CTL1_PTEN_MASK |
            SPI_CTL1_MSB_MASK | SPI_CTL1_CP_MASK);
}

void DL_SPI_setClockConfig(SPI_Regs *spi, DL_SPI_ClockConfig *config)
{
    spi->CLKSEL = (uint32_t) config->clockSel;

    spi->CLKDIV = (uint32_t) config->divideRatio;
}

void DL_SPI_getClockConfig(SPI_Regs *spi, DL_SPI_ClockConfig *config)
{
    config->clockSel = (DL_SPI_CLOCK) spi->CLKSEL;

    config->divideRatio = (DL_SPI_CLOCK_DIVIDE_RATIO) spi->CLKDIV;
}

uint8_t DL_SPI_receiveDataBlocking8(SPI_Regs *spi)
{
    while (DL_SPI_isRXFIFOEmpty(spi)) {
    };

    return DL_SPI_receiveData8(spi);
}

uint16_t DL_SPI_receiveDataBlocking16(SPI_Regs *spi)
{
    while (DL_SPI_isRXFIFOEmpty(spi)) {
    };
    return DL_SPI_receiveData16(spi);
}

uint32_t DL_SPI_receiveDataBlocking32(SPI_Regs *spi)
{
    while (DL_SPI_isRXFIFOEmpty(spi)) {
    };
    return DL_SPI_receiveData32(spi);
}

void DL_SPI_transmitDataBlocking8(SPI_Regs *spi, uint8_t data)
{
    while (DL_SPI_isTXFIFOFull(spi)) {
    };
    DL_SPI_transmitData8(spi, data);
}

void DL_SPI_transmitDataBlocking16(SPI_Regs *spi, uint16_t data)
{
    while (DL_SPI_isTXFIFOFull(spi)) {
    };
    DL_SPI_transmitData16(spi, data);
}

void DL_SPI_transmitDataBlocking32(SPI_Regs *spi, uint32_t data)
{
    while (DL_SPI_isTXFIFOFull(spi)) {
    };
    DL_SPI_transmitData32(spi, data);
}

bool DL_SPI_receiveDataCheck8(SPI_Regs *spi, uint8_t *buffer)
{
    bool status;
    if (DL_SPI_isRXFIFOEmpty(spi)) {
        status = false;
    } else {
        *buffer = DL_SPI_receiveData8(spi);
        status  = true;
    }

    return status;
}

bool DL_SPI_receiveDataCheck16(SPI_Regs *spi, uint16_t *buffer)
{
    bool status;
    if (DL_SPI_isRXFIFOEmpty(spi)) {
        status = false;
    } else {
        *buffer = DL_SPI_receiveData16(spi);
        status  = true;
    }

    return status;
}

bool DL_SPI_receiveDataCheck32(SPI_Regs *spi, uint32_t *buffer)
{
    bool status;
    if (DL_SPI_isRXFIFOEmpty(spi)) {
        status = false;
    } else {
        *buffer = DL_SPI_receiveData32(spi);
        status  = true;
    }

    return status;
}

bool DL_SPI_transmitDataCheck8(SPI_Regs *spi, uint8_t data)
{
    bool status;
    if (DL_SPI_isTXFIFOFull(spi)) {
        status = false;
    } else {
        DL_SPI_transmitData8(spi, data);
        status = true;
    }

    return status;
}

bool DL_SPI_transmitDataCheck16(SPI_Regs *spi, uint16_t data)
{
    bool status;
    if (DL_SPI_isTXFIFOFull(spi)) {
        status = false;
    } else {
        DL_SPI_transmitData16(spi, data);
        status = true;
    }

    return status;
}

bool DL_SPI_transmitDataCheck32(SPI_Regs *spi, uint32_t data)
{
    bool status;
    if (DL_SPI_isTXFIFOFull(spi)) {
        status = false;
    } else {
        DL_SPI_transmitData32(spi, data);
        status = true;
    }

    return status;
}

uint32_t DL_SPI_drainRXFIFO8(SPI_Regs *spi, uint8_t *buffer, uint32_t maxCount)
{
    uint32_t i;
    for (i = 0; i < maxCount; i++) {
        if (!DL_SPI_isRXFIFOEmpty(spi)) {
            buffer[i] = DL_SPI_receiveData8(spi);
        } else {
            break;
        }
    }

    return i;
}

uint32_t DL_SPI_drainRXFIFO16(
    SPI_Regs *spi, uint16_t *buffer, uint32_t maxCount)
{
    uint32_t i;
    for (i = 0; i < maxCount; i++) {
        if (!DL_SPI_isRXFIFOEmpty(spi)) {
            buffer[i] = DL_SPI_receiveData16(spi);
        } else {
            break;
        }
    }

    return i;
}

uint32_t DL_SPI_drainRXFIFO32(
    SPI_Regs *spi, uint32_t *buffer, uint32_t maxCount)
{
    uint32_t i;
    for (i = 0; i < maxCount; i++) {
        if (!DL_SPI_isRXFIFOEmpty(spi)) {
            buffer[i] = DL_SPI_receiveData32(spi);
        } else {
            break;
        }
    }

    return i;
}

uint32_t DL_SPI_fillTXFIFO8(SPI_Regs *spi, uint8_t *buffer, uint32_t count)
{
    uint32_t i;
    for (i = 0; i < count; i++) {
        if (!DL_SPI_isTXFIFOFull(spi)) {
            DL_SPI_transmitData8(spi, buffer[i]);
        } else {
            break;
        }
    }

    return i;
}

uint32_t DL_SPI_fillTXFIFO16(SPI_Regs *spi, uint16_t *buffer, uint32_t count)
{
    uint32_t i;
    for (i = 0; i < count; i++) {
        if (!DL_SPI_isTXFIFOFull(spi)) {
            DL_SPI_transmitData16(spi, buffer[i]);
        } else {
            break;
        }
    }

    return i;
}

bool DL_SPI_saveConfiguration(SPI_Regs *spi, DL_SPI_backupConfig *ptr)
{
    bool stateSaved = !ptr->backupRdy;
    if (stateSaved) {
        ptr->controlWord0                 = spi->CTL0;
        ptr->controlWord1                 = spi->CTL1;
        ptr->clockControl                 = spi->CLKCTL;
        ptr->clockSel                     = spi->CLKSEL;
        ptr->divideRatio                  = spi->CLKDIV;
        ptr->interruptFifoLevelSelectWord = spi->IFLS;
        ptr->interruptMask0               = spi->CPU_INT.IMASK;
        ptr->interruptMask1               = spi->DMA_TRIG_RX.IMASK;
        ptr->interruptMask2               = spi->DMA_TRIG_TX.IMASK;
        ptr->backupRdy                    = true;
    }
    return stateSaved;
}

bool DL_SPI_restoreConfiguration(SPI_Regs *spi, DL_SPI_backupConfig *ptr)
{
    bool stateRestored = ptr->backupRdy;
    if (stateRestored) {
        /* Set CTL1.ENABLE=0 during initialization */
        spi->CTL1              = ptr->controlWord1 & ~(SPI_CTL1_ENABLE_MASK);
        spi->CTL0              = ptr->controlWord0;
        spi->CLKCTL            = ptr->clockControl;
        spi->CLKSEL            = ptr->clockSel;
        spi->CLKDIV            = ptr->divideRatio;
        spi->IFLS              = ptr->interruptFifoLevelSelectWord;
        spi->CPU_INT.IMASK     = ptr->interruptMask0;
        spi->DMA_TRIG_RX.IMASK = ptr->interruptMask1;
        spi->DMA_TRIG_TX.IMASK = ptr->interruptMask2;

        /* Re-enable SPI if it was originally enabled */
        if ((ptr->controlWord1 & SPI_CTL1_ENABLE_MASK) ==
            SPI_CTL1_ENABLE_MASK) {
            DL_SPI_enable(spi);
        }
        ptr->backupRdy = false;
    }
    return stateRestored;
}

uint32_t DL_SPI_fillTXFIFO32(SPI_Regs *spi, uint32_t *buffer, uint32_t count)
{
    uint32_t i;
    for (i = 0; i < count; i++) {
        if (!DL_SPI_isTXFIFOFull(spi)) {
            DL_SPI_transmitData32(spi, buffer[i]);
        } else {
            break;
        }
    }

    return i;
}

#endif /* __MSPM0_HAS_SPI__ */
