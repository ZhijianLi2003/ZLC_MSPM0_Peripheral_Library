/*
 * Copyright (c) 2021, Texas Instruments Incorporated
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
 *  @file       UARTSupportMSPM0.h
 *
 *  @brief      UART driver support APIs for the MSPM0 devices.
 *
 *  @defgroup   UARTSupportMSPM0 UART driver supporting APIs
 *
 *  # Overview
 *  Refer to @ref ti_drivers_UART_Overview for a complete description of APIs and examples
 *  of use.
 *
 ******************************************************************************
 */
/** @addtogroup UARTSupportMSPM0
 *  @ingroup UART
* @{
*/
/* clang-format off */
#ifndef ti_drivers_uart_UARTSupportMSPM0__include
#define ti_drivers_uart_UARTSupportMSPM0__include

#include <ti/drivers/dpl/ClockP.h>
#include <ti/drivers/dpl/SemaphoreP.h>

#include <ti/drivers/dma/DMAMSPM0.h>
#include <ti/drivers/utils/RingBuf.h>
#include <ti/drivers/UART.h>

/*!
 *  @brief      Function pointers to implementation/hardware specific logic.
 */
typedef struct {
   /*!
    *  @brief      Enable the hardware, typically called during UART_open().
    *
    *  @param[in]  handle    UART_Handle instance from UART_open().
    *  @param[in]  params    Reference to the UART_Params struct passed in by
    *                        the user.
    *  @return Returns true on success, else false.
    */
    bool (*enable)(UART_Handle handle, UART_Params *params);

   /*!
    *  @brief      Disable the hardware, typically called during UART_close().
    *
    *  @param[in]  handle    UART_Handle instance from UART_open().
    */
    void (*disable)(UART_Handle handle);

   /*!
    *  @brief      Kick the transmitter in the hardware.
    *
    *  @param[in]  handle    UART_Handle instance from UART_open().
    */
    void (*txChar)(UART_Handle handle);

   /*!
    *  @brief      Read method to use.
    *
    *  @param[in]  handle    UART_Handle instance from UART_open().
    *  @param[out] buf       location to read data into.
    *  @param[in]  size      amount of data to read in bytes.
    *  @param[out] bytesRead If non-NULL, the location to store the number
    *                        of bytes actually read into the buffer. If NULL,
    *                        this parameter will be ignored. In callback mode,
    *                        NULL could be passed in for this parameter, since
    *                        the callback function will be passed the number of
    *                        bytes read.
    *  @return Returns a status indicating success or failure of the read.
    *
    *  @retval #UART_STATUS_SUCCESS    The call was successful.
    *  @retval #UART_STATUS_EINUSE     Another read from the UART is currently
    *                                   ongoing.
    *  @retval #UART_STATUS_ECANCELLED In #UART_Mode_BLOCKING, the read was
    *                                   canceled by a call to UART_readCancel()
    *                                   before any data could be received.
    */
    int_fast16_t (*read)(
        UART_Handle, void *buf, size_t size, size_t *bytesRead);

   /*!
    *  @brief      Write method to use.
    *
    *  @param[in]  handle    UART_Handle instance from UART_open().
    *  @param[in]  buf       location to write data from.
    *  @param[in]  size      amount of data to write in bytes.
    *  @param[out] bytesWritten If non-NULL, the location to store the number
    *                        of bytes actually written into the buffer. If
    *                        NULL, this parameter will be ignored. In callback
    *                        mode, NULL could be passed in for this parameter,
    *                        since the callback function will be passed the
    *                        number of bytes written.
    *  @return Returns a status indicating success or failure of the write.
    *
    *  @retval #UART_STATUS_SUCCESS The call was successful.
    *  @retval #UART_STATUS_EINUSE  Another write to the UART is currently
    *                                ongoing.
    */
    int_fast16_t (*write)(
        UART_Handle, const void *buf, size_t size, size_t *bytesWritten);
} UARTSupport_Fxns;

/*!
 *  @brief      Private Metadata structure for a UART instance.
 */
typedef struct {
    const UARTSupport_Fxns *supportFxns; /*!< implementation specific */
    void *userArg;                  /*!< User supplied argument for callback */
    uint8_t buffersSupported : 1;   /*!< RX/TX buffers supported */
    uint8_t eventsSupported : 1;    /*!< True if events are supported */
    uint8_t callbacksSupported : 1; /*!< True if callbacks are supported */
    uint8_t dmaSupported : 1;       /*!< True if dma is supported */
    uint8_t returnMode : 1;         /*!< @ref UART_ReadReturnMode(partial/full) */
    uint8_t inUse : 1;              /*!< True if driver already open */
    uint8_t readCancel : 1;         /*!< True if a read has been canceled */
    uint8_t writeCancel : 1;        /*!< True if a write has been canceled */
    uint8_t overrunActive : 1;      /*!< Is a RX overrun active */
    uint8_t readTimedOut : 1;       /*!< Has read timed out */
    uint8_t writeTimedOut : 1;      /*!< Has write timed out */
    uint8_t readMode : 2;           /*!< Read @ref UART_Mode */
    uint8_t writeMode : 2;          /*!< Write @ref UART_Mode */
    uint8_t rxDmaChannel;           /*!< DMA rx channel number */
    uint8_t txDmaChannel;           /*!< DMA tx channel number */
    uint8_t readInUse : 1;          /*!< Flag to show ongoing read */
    uint8_t writeInUse : 1;         /*!< Flag to show ongoing write */
    uint32_t overrunCount;          /*!< Total counts of overruns */
#ifndef UART_NO_DMA
    uint8_t noOfDMAChannels;        /*!< Total DMA channels used */
    DMAMSPM0_Handle DMA_Handle;     /*!< DMA handle */
#endif
} UART_Object;


/*!
 *  @brief      Private Metadata structure for a UART instance supporting
 *              buffers.
 */
typedef struct {
    uint8_t *rxBufPtr;          /*!< RX buffer memory address */
    uint8_t *txBufPtr;          /*!< TX buffer memory address */
    uint16_t rxBufSize;         /*!< RX buffer size in bytes, length of an array */
    uint16_t txBufSize;         /*!< TX buffer size in bytes */
    RingBuf_Object rxBuf;       /*!< Receive data buffer */
    RingBuf_Object txBuf;       /*!< Transmit data buffer */
    SemaphoreP_Handle rxSem;    /*!< Semaphore for receive */
    SemaphoreP_Handle txSem;    /*!< Semaphore for transmit */
} UART_Buffers_Object;

/*!
 *  @brief      Private Metadata structure for a UART instance supporting
 *              events.
 */
typedef struct {
    UART_EventCallback eventCallback; /*!< Pointer to event callback function */
    uint32_t eventMask; /*!< Mask of events that application is interacted in */
} UART_EventCallback_Object;

/*!
 *  @brief      Private Metadata structure for a UART instance supporting
 *              callbacks.
 */
typedef struct {
    UART_Callback readCallback;  /*!< Pointer to read callback */
    UART_Callback writeCallback; /*!< Pointer to write callback */
    uint8_t *readBuf;            /*!< Buffer data pointer */
    const uint8_t *writeBuf;     /*!< Buffer data pointer */
    uint16_t readSize;           /*!< Number of bytes to read */
    uint16_t writeSize;          /*!< Number of bytes to write */
    uint16_t writeCount;         /*!< Number of bytes left to write */
    uint16_t readCount;          /*!< Number of bytes left to read */
    uint16_t bytesRead;          /*!< Number of bytes read */
    uint16_t bytesWritten;       /*!< Number of bytes written */
    int32_t rxStatus;            /*!< Rx Status */
    int32_t txStatus;            /*!< Tx Status */
    size_t rxSize;               /*!< Number of bytes to read in DMA xfer */
    size_t txSize;               /*!< Number of bytes to write with DMA */
    void *userArg;               /*!< User supplied arg for callbacks */
} UART_Callback_Object;

/*!
 *  @brief      Private Metadata structure for a UART instance supporting
 *              data structures needed for UART TX/RX execution.
 */
/* Warning! The sequence in the below structure must NOT be modified. */
typedef struct
{
    UART_Object object;                /*!< Struct of UART object parameters */
    UART_Buffers_Object buffersObject; /*!< Struct of UART buffer object to support buffers */
    UART_EventCallback_Object eventCallbackObject; /*!< Struct of UART event object */
    UART_Callback_Object callbackObject; /*!< Struct of UART callback object */

}UART_Data_Object;

/*!
 *  @brief  UART Global configuration.
 *
 *  The @ref UART_Config structure contains a set of pointers used to characterize
 *  the UART driver implementation.
 *
 */
typedef struct UART_Config_
{
    /*! Pointer to a driver specific data object. */
    void *object;

    /*! Pointer to a driver specific hardware attributes structure. */
    void const *hwAttrs;
} UART_Config;

/*!
 *  @brief  Array of @ref UART_Config structure.
 *
 */
extern  const UART_Config UART_config[];
/*!
 *  @brief  Count of UART instances.
 *
 */
extern const uint_least8_t UART_count;



/*!
 *  @brief      UART read that only supports buffered mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[out] buf       location to read data into.
 *  @param[in]  size      amount of data to read in bytes.
 *  @param[out] bytesRead If non-NULL, the location to store the number
 *                        of bytes actually read into the buffer. If NULL,
 *                        this parameter will be ignored.
 *  @return Returns a status indicating success or failure of the read.
 *
 *  @retval #UART_STATUS_SUCCESS    The call was successful.
 *  @retval #UART_STATUS_EINUSE     Another read from the UART is currently
 *                                   ongoing.
 *  @retval #UART_STATUS_ECANCELLED In #UART_Mode_BLOCKING, the read was
 *                                   canceled by a call to UART_readCancel()
 *                                   before any data could be received.
 */
int_fast16_t UART_readBuffered(UART_Handle handle, void *buf, size_t size, size_t *bytesRead);

/*!
 *  @brief      UART write that only supports buffered mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[in]  buf       location to write data from.
 *  @param[in]  size      amount of data to write in bytes.
 *  @param[out] bytesWritten If non-NULL, the location to store the number
 *                        of bytes actually written into the buffer. If
 *                        NULL, this parameter will be ignored.
 *  @return Returns a status indicating success or failure of the write.
 *
 *  @retval #UART_STATUS_SUCCESS The call was successful.
 *  @retval #UART_STATUS_EINUSE  Another write to the UART is currently
 *                                ongoing.
 */
int_fast16_t UART_writeBuffered(UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten);

/*!
 *  @brief      UART read that only supports callback mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[out] buf       location to read data into.
 *  @param[in]  size      amount of data to read in bytes.
 *  @param[out] bytesRead If non-NULL, the location to store the number
 *                        of bytes actually read into the buffer. If NULL,
 *                        this parameter will be ignored. In callback mode,
 *                        NULL could be passed in for this parameter, since
 *                        the callback function will be passed the number of
 *                        bytes read.
 *  @return Returns a status indicating success or failure of the read.
 *
 *  @retval #UART_STATUS_SUCCESS    The call was successful.
 *  @retval #UART_STATUS_EINUSE     Another read from the UART is currently
 *                                   ongoing.
 *  @retval #UART_STATUS_ECANCELLED In #UART_Mode_BLOCKING, the read was
 *                                   canceled by a call to UART_readCancel()
 *                                   before any data could be received.
 */
int_fast16_t UART_readCallback(UART_Handle handle, void *buf, size_t size, size_t *bytesRead);

/*!
 *  @brief      UART write that only supports callback mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[in]  buf       location to write data from.
 *  @param[in]  size      amount of data to write in bytes.
 *  @param[out] bytesWritten If non-NULL, the location to store the number
 *                        of bytes actually written into the buffer. If
 *                        NULL, this parameter will be ignored. In callback
 *                        mode, NULL could be passed in for this parameter,
 *                        since the callback function will be passed the
 *                        number of bytes written.
 *  @return Returns a status indicating success or failure of the write.
 *
 *  @retval #UART_STATUS_SUCCESS The call was successful.
 *  @retval #UART_STATUS_EINUSE  Another write to the UART is currently
 *                                ongoing.
 */
int_fast16_t UART_writeCallback(UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten);

/*!
 *  @brief      UART read that only supports buffered and callback mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[out] buf       location to read data into.
 *  @param[in]  size      amount of data to read in bytes.
 *  @param[out] bytesRead If non-NULL, the location to store the number
 *                        of bytes actually read into the buffer. If NULL,
 *                        this parameter will be ignored. In callback mode,
 *                        NULL could be passed in for this parameter, since
 *                        the callback function will be passed the number of
 *                        bytes read.
 *  @return Returns a status indicating success or failure of the read.
 *
 *  @retval #UART_STATUS_SUCCESS    The call was successful.
 *  @retval #UART_STATUS_EINUSE     Another read from the UART is currently
 *                                   ongoing.
 *  @retval #UART_STATUS_ECANCELLED In #UART_Mode_BLOCKING, the read was
 *                                   canceled by a call to UART_readCancel()
 *                                   before any data could be received.
 */
int_fast16_t UART_readFullFeatured(UART_Handle handle, void *buf, size_t size, size_t *bytesRead);

/*!
 *  @brief      UART write that only supports buffered and callback mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[in]  buf       location to write data from.
 *  @param[in]  size      amount of data to write in bytes.
 *  @param[out] bytesWritten If non-NULL, the location to store the number
 *                        of bytes actually written into the buffer. If
 *                        NULL, this parameter will be ignored. In callback
 *                        mode, NULL could be passed in for this parameter,
 *                        since the callback function will be passed the
 *                        number of bytes written.
 *  @return Returns a status indicating success or failure of the write.
 *
 *  @retval #UART_STATUS_SUCCESS The call was successful.
 *  @retval #UART_STATUS_EINUSE  Another write to the UART is currently
 *                                ongoing.
 */
int_fast16_t UART_writeFullFeatured(UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten);


#endif /* ti_drivers_uart_UARTSupportMSPM0__include */
/* clang-format on */
/** @}*/
