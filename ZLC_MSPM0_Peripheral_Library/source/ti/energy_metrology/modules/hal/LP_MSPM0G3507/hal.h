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
 *  @file       hal.h
 *  @brief      Energy Library HAL Module
 *  @defgroup   ENERGY_LIBRARY_HAL LP_MSPM0G3507 - \
 *  Hardware Abstraction Layer (HAL)
 *
 *
 *  @anchor energy_library_hal_Overview
 *  # Overview
 *
 *  The HAL module provides micro-controller agnostic set of application
 *  programming interfaces (APIs) to be used by other module's in the library
 *  as well as in the user's application code.
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup ENERGY_LIBRARY_HAL
 * @{
 */

#ifndef HAL_H
#define HAL_H

//*****************************************************************************
// the includes
//*****************************************************************************
#include "ti_msp_dl_config.h"
#include <ti/iqmath/include/IQmathLib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! @brief Define 1*/
#define TRUE    0x1
/*! @brief Defines 0*/
#define FALSE   0x0

/*! @brief Defines the system clock frequency, MHz */
#define HAL_SYSTEM_FREQ_MHZ        ((int32_t)80)
/*! @brief Defines CRC_IN memory address    */
#define CRC_IN_ADDRESS             0x40441800

/*! @brief Defines output port for pin 1*/
#ifndef GEN_GPIO_OUT_PINO_01_PORT
#define GEN_GPIO_OUT_PINO_01_PORT  GEN_GPIO_OUT_PORT
#endif

/*! @brief Defines output port for pin 2*/
#ifndef GEN_GPIO_OUT_PINO_02_PORT
#define GEN_GPIO_OUT_PINO_02_PORT  GEN_GPIO_OUT_PORT
#endif


/*! @brief Defines output port for pin 3*/
#ifndef GEN_GPIO_OUT_PINO_03_PORT
#define GEN_GPIO_OUT_PINO_03_PORT  GEN_GPIO_OUT_PORT
#endif

/*! @brief Defines output port for pin 4*/
#ifndef GEN_GPIO_OUT_PINO_04_PORT
#define GEN_GPIO_OUT_PINO_04_PORT  GEN_GPIO_OUT_PORT
#endif

/*! @brief Defines input port for pin 1*/
#ifndef GEN_GPIO_IN_PINI_01_PORT
#define GEN_GPIO_IN_PINI_01_PORT   GEN_GPIO_IN_PORT
#endif

/*! @brief Defines input port for pin 2*/
#ifndef GEN_GPIO_IN_PINI_02_PORT
#define GEN_GPIO_IN_PINI_02_PORT   GEN_GPIO_IN_PORT
#endif

/*! @brief Defines input port for pin 3*/
#ifndef GEN_GPIO_IN_PINI_03_PORT
#define GEN_GPIO_IN_PINI_03_PORT   GEN_GPIO_IN_PORT
#endif

/*! @brief Defines input port for pin 4*/
#ifndef GEN_GPIO_IN_PINI_04_PORT
#define GEN_GPIO_IN_PINI_04_PORT   GEN_GPIO_IN_PORT
#endif

/*! @enum HAL_MEMORY_BLOCK_STARTADDR*/
typedef enum
{
    /*! @brief Memory block start address   */
#ifdef CONFIG_MSPM0G350X
    HAL_MEMORY_BLOCK_STARTADDR01 = 0x0001FC00
#else 
    HAL_MEMORY_BLOCK_STARTADDR01 = 0x0000FC00 
#endif
}HAL_MEMORY_BLOCK_STARTADDR;

/*! @enum HAL_GPIO_STATE*/
typedef enum
{
    /*! @brief GPIO set to low */
    HAL_GPIO_PIN_LOW = 0,
    /*! @brief GPIO set to high */
    HAL_GPIO_PIN_HIGH
}HAL_GPIO_STATE;

/*! @enum HAL_GPIO_IN */
typedef enum
{
    /*! @brief Index associated to input GPIO PIN 0 */
    HAL_GPIO_IN_00 = 0,
    /*! @brief Index associated to input GPIO PIN 1 */
    HAL_GPIO_IN_01,
    /*! @brief Index associated to input GPIO PIN 2 */
    HAL_GPIO_IN_02,
    /*! @brief Index associated to input GPIO PIN 3 */
    HAL_GPIO_IN_03,
    /*! @brief Index associated to input GPIO PIN 4 */
    HAL_GPIO_IN_04,
    /*! @brief Total number of input GPIO pins */
    HAL_GPIO_IN_MAX
}HAL_GPIO_IN;

/*! @enum HAL_GPIO_OUT*/
typedef enum
{
    /*! @brief Index associated to output GPIO PIN 0 */
    HAL_GPIO_OUT_00 = 0,
    /*! @brief Index associated to output GPIO PIN 1 */
    HAL_GPIO_OUT_01,
    /*! @brief Index associated to output GPIO PIN 2 */
    HAL_GPIO_OUT_02,
    /*! @brief Index associated to output GPIO PIN 3 */
    HAL_GPIO_OUT_03,
    /*! @brief Total number of output GPIO pins */
    HAL_GPIO_OUT_MAX
}HAL_GPIO_OUT;

/*! @enum HAL_SPI_CHAN */
typedef enum
{
    /*! @brief Index associated to SPI channel 0 */
    HAL_SPI_CHAN_0 = 0,
    /*! @brief Total number of SPI channels */
    HAL_SPI_CHAN_MAX
} HAL_SPI_CHAN;

/*! @enum HAL_UART_CHAN */
typedef enum
{
    /*! @brief Index associated to UART channel 0 */
    HAL_UART_CHAN_0 = 0,
    /*! @brief Total number of UART channels */
    HAL_UART_CHAN_MAX
}HAL_UART_CHAN;

/*! @enum HAL_SPI_CS */
typedef enum
{
    /*! @brief Index associated to chip select 0 */
    HAL_SPI_CS_0 = 0,
    /*! @brief Index associated to chip select 0 */
    HAL_SPI_CS_1,
    /*! @brief Index associated to chip select 0 */
    HAL_SPI_CS_2,
    /*! @brief Index associated to chip select 0 */
    HAL_SPI_CS_3,
    /*! @brief Total number of chip select pins */
    HAL_SPI_CS_MAX
} HAL_SPI_CS;

/*! @enum HAL_DMA_CHAN  */
typedef enum
{
    /*! @brief Index associated to DMA Channel 0 */
    HAL_DMA_CHAN_0 = DMA_CH0_CHAN_ID,
    /*! @brief Index associated to DMA Channel 1 */
    HAL_DMA_CHAN_1 = DMA_CH1_CHAN_ID,
    /*! @brief Total number of DMA Channels */
    HAL_DMA_CHAN_MAX
}HAL_DMA_CHAN;

/*! @enum HAL_CRC   */
typedef enum
{
    /*! @brief Index associated to CRC 0 */
    HAL_CRC_0 = 0,
    /*! @brief CRC count */
    HAL_CRC_MAX
}HAL_CRC;

/*! @brief Defines a GPIO instance  */
typedef struct HAL_GPIO_Instance_
{
    /*! @brief IOMUX    */
    IOMUX_PINCM         iomux;
    /*! @brief GPIO port    */
    GPIO_Regs *         port;
    /*! @brief GPIO pin    */
    uint32_t            pin;
    /*! @brief GPIO IRQN    */
    IRQn_Type           IRQn;
}HAL_GPIOInstance;

/*! @brief Defines a SPI instance  */
typedef struct HAL_SPIInstance_
{
    /*! @brief SPI Channel  */
    SPI_Regs      *inst;
    /*! @brief DMA channel for SPI transfer */
    HAL_DMA_CHAN  dmaChanIdTx;
    /*! @brief DMA channel for SPI Receive */
    HAL_DMA_CHAN  dmaChanIdRx;
}HAL_SPIInstance;

/*! @brief Defines a UART instance  */
typedef struct HAL_UARTInstance_
{
    /*! @brief UART Channel  */
    UART_Regs     *inst;
    /*! @brief DMA channel for UART transfer */
    HAL_DMA_CHAN  dmaChanIdTx;
    /*! @brief DMA channel for UART Receive */
    HAL_DMA_CHAN  dmaChanIdRx;
}HAL_UARTInstance;

/*! @brief Defines a CRC instance  */
typedef struct HAL_CRCInstance_
{
    CRC_Regs     *inst;
}HAL_CRCInstance;

extern HAL_GPIOInstance    gpioInputPin[HAL_GPIO_IN_MAX];

/**
 * @brief     Delays for specific time in microseconds
 * @param[in] microSeconds   delayed time in microseconds
 */
__STATIC_INLINE void HAL_delayMicroSeconds(uint32_t microSeconds)
{
  delay_cycles(HAL_SYSTEM_FREQ_MHZ * microSeconds);
  return;
}

/**
 * @brief     Initializes the hal object
 */
void HAL_init();

/*!
 * @brief     reads a gpio
 * @param[in] pin   gpiopin
 * @return    status of pin
 */
bool HAL_readGPIOPin(HAL_GPIO_IN pin);

/*!
 * @brief     write to a gpio
 * @param[in] pin       gpiopin
 * @param[in] pinState  pin state
 */
void HAL_writeGPIOPin(HAL_GPIO_OUT pin, HAL_GPIO_STATE pinState);

/*!
 * @brief     enables GPIO Interrupt
 * @param[in] pin       gpiopin
 */
void HAL_enableGPIOInterrupt(HAL_GPIO_IN pin);

/*!
 * @brief     get gpio enabled interrupt status
 * @param[in] pin       gpiopin
 * @return gpio interrupt status
 */
uint32_t HAL_getGPIOEnabledInterruptStatus(HAL_GPIO_IN pin);

/*!
 * @brief     clear gpio interrupt status
 * @param[in] pin       gpiopin
 */
void HAL_clearGPIOInterruptStatus(HAL_GPIO_IN pin);

/*!
 * @brief Start SPI data transfer through DMA
 * @param[in]  dataTx[]  The transfer data
 * @param[in]  dataRx[]  The receive data
 * @param[in]  byteLength Number of bytes transfered
 * @param[in]  chan      The SPI channel
 * @param[in]  cs        The SPI Chip select pin
 */
void HAL_startSPIDataTransfer(uint8_t dataTx[], uint8_t dataRx[], uint8_t byteLength, HAL_SPI_CHAN chan, HAL_SPI_CS cs);

/*!
 * @brief Start UART Receive DMA
 * @param[in] chan       The UART channel
 * @param[in] dataRx[]   Array to store received data
 * @param[in] byteLength Number of bytes transfered
 */
void HAL_startUARTDMARecieve(HAL_UART_CHAN chan, uint8_t dataRx[], uint8_t byteLength);

/*!
 * @brief Start UART Transmit DMA
 * @param[in] chan       The UART channel
 * @param[in] dataTx[]   The transmit data
 * @param[in] byteLength Number of bytes to transfer
 */
void HAL_startUARTDMATransmit(HAL_UART_CHAN chan, uint8_t dataTx[], uint8_t byteLength);

/*!
 * @brief clear Memory block
 * @param[in] startAddr  The start address of Memory block
 */
void HAL_clearMemoryBlock(HAL_MEMORY_BLOCK_STARTADDR startAddr);

/*!
 * @brief secure Memory block
 * @param[in] startAddr  The start address of Memory block
 */
void HAL_secureMemoryBlock(HAL_MEMORY_BLOCK_STARTADDR startAddr);

/*!
 * @brief copy block data to flash
 * @param[in] dstAddr   The pointer to destination address
 * @param[in] srcAddr   The pointer to source address
 * @param[in] len The length of data
 * @param[in] startAddr  The start address of Memory block
*  @return status
 */
int HAL_copyMemoryBlock(void *dstAddr, void *srcAddr, int len, HAL_MEMORY_BLOCK_STARTADDR startAddr);

/*!
 * @brief Get real time clock
 * @param[in] buf[] buffer to store clock data
 */
void HAL_getRTC(uint8_t buf[6]);

/*!
 * @brief Set real time clock
 * @param[in] buf[] buffer to store clock data
 */
void HAL_setRTC(const uint8_t buf[6]);

/*!
 * @brief Get CRC out
 * @param[in] chan The CRC module
 */
uint16_t HAL_getCRCOut(HAL_CRC chan);

/*!
 * @brief Get CRC out
 * @param[in] chan The CRC module
 * @param[in] value CRC SEED value
 */
void HAL_setCRCSeed(HAL_CRC chan, uint16_t value);


void HAL_enableUARTInterrupt(HAL_UART_CHAN Chan);

#ifdef __cplusplus
}
#endif
#endif /* HAL_H */
/** @}*/
