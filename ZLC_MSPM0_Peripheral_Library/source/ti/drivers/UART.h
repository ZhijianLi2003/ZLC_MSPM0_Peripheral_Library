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
 *  @file       UART.h
 *
 *  @brief      UART driver interface.
 *
 *  @defgroup   UART Universal Asynchronous Receiver-Transmitter (UART)
 *
 *  The UART header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/UART.h>
 *  @endcode
 *
 *  @anchor ti_drivers_UART_Overview
 *  # Overview
 *  UART has both RX and TX ring buffers for receiving/sending data.
 *  UART uses DMA to transfer data between the UART FIFOs and the
 *        RX and TX ring buffers in blocking mode. In callback mode,
 *        DMA will transfer data straight between the hardware
 *        FIFO and the source/destination buffer supplied by the application.
 *        NOTE: If the source-buffer for a TX operation resides in flash,
 *        the driver will constrain the flash to remain on during idle.
 *  The UART APIs for reading and writing data have been made more
 *        posix-like.
 *  UART provides for event notification, allowing the application
 *        to receive TX start and completion events, and RX error events.
 *        @note These events are synchronous to what can be observed on the data
 *        lines. A UART_STAT_TXFE_SET event will for example only occur
 *        after all data has been shifted from the hardware FIFO out onto the
 *        TX-pin. In contrast, read and write-callbacks are invoked when the
 *        driver has finished writing data into the hardware FIFO.
 *
 *  To use the UART driver, ensure that the correct driver library for your
 *  device is linked in and include this header file as follows:
 *  @code
 *  #include <ti/drivers/UART.h>
 *  @endcode
 *
 ******************************************************************************
 */
/** @addtogroup UART
 * @{
 */
/* clang-format off */
#ifndef ti_drivers_uart_UART__include
#define ti_drivers_uart_UART__include

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
#include <ti/driverlib/dl_gpio.h>
#include <ti/driverlib/dl_uart_main.h>

/** @addtogroup UART_STATUS UART status codes
 *  @{
 */
/*!
 * @brief   Successful status code returned by UART APIs.
 */
#define UART_STATUS_SUCCESS (0)

/*!
 * @brief  A  read timeout occurred (not an error).
 */
#define UART_STATUS_SREADTIMEOUT (1)

/*!
 * @brief  A framing error occurred.
 */
#define UART_STATUS_EFRAMING (-1)

/*!
 * @brief  A parity error occurred.
 */
#define UART_STATUS_EPARITY (-2)

/*!
 * @brief  A break error occurred.
 */
#define UART_STATUS_EBREAK (-4)

/*!
 * @brief  A FIFO overrun occurred.
 */
#define UART_STATUS_EOVERRUN (-8)

/*!
 * @brief  The UART is currently in use.
 */
#define UART_STATUS_EINUSE (-9)

/*!
 * @brief  An invalid argument or @ref UART_Params field was passed to UART API.
 */
#define UART_STATUS_EINVALID (-10)

/*!
 * @brief  General failure status returned by UART API.
 */
#define UART_STATUS_EFAIL (-11)

/*!
 * @brief  A memory allocation failure occurred.
 */
#define UART_STATUS_EMEMORY (-12)

/*!
 * @brief  A timeout occurred for a blocking UART_read or UART_write call.
 */
#define UART_STATUS_ETIMEOUT (-13)

/*!
 * @brief  A UART_write() or UART_read() operation was cancelled.
 */
#define UART_STATUS_ECANCELLED (-14)

/*!
 * @brief  A UART_write() or UART_read() called on a device not opened.
 */
#define UART_STATUS_ENOTOPEN (-15)

/*!
 * @brief  A UART_write() or UART_read() in UART_Mode_NONBLOCKING would
 *         have blocked.
 */
#define UART_STATUS_EAGAIN (-16)

/** @} */

/*!
 *  @brief      A handle that is returned from a UART_open() call.
 */

typedef struct UART_Config_ *UART_Handle;
/*!
 *  @brief      The definition of a callback function used by the UART driver
 *              when used in #UART_Mode_CALLBACK.
 *              The callback can occur in task or interrupt context.
 *
 *  @param[in]  UART_Handle             UART_Handle.
 *
 *  @param[in]  buf                     Pointer to read/write buffer.
 *
 *  @param[in]  count                   Number of elements read/written.
 *
 *  @param[in]  userArg                 A user supplied argument specified
 *                                      in @ref UART_Params.
 *
 *  @param[in]  status                  A @ref UART_STATUS code indicating
 *                                      success or failure of the transfer.
 */
typedef void (*UART_Callback)(UART_Handle handle, void *buf, size_t count,
    void *userArg, int_fast16_t status);

/*!
 *  @brief      The definition of a callback function used by the UART driver.
 *              The callback can occur in task or interrupt context.
 *
 *  @param[in]  UART_Handle             UART_Handle.
 *
 *  @param[in]  event                   UART_EVENT that has occurred.
 *
 *  @param[in]  data                    One of the following
 *                                      * UART_EVENT_OVERRUN: accumulated count
 *                                      * UART_EVENT_BREAK: unused
 *                                      * UART_EVENT_PARITY: unused
 *                                      * UART_EVENT_FRAMING: unused
 *
 *  @param[in]  userArg                 A user supplied argument specified
 *                                      in @ref UART_Params.
 *
 *  @param[in]  status                  A UART_STATUS code indicating
 *                                      success or failure of the transfer.
 */
typedef void (*UART_EventCallback)(
    UART_Handle handle, uint32_t event, uint32_t data, void *userArg);

/*!
 *  @brief      UART mode settings
 *
 *  This enum defines the read and write modes for the configured UART.
 */
typedef enum {
    /*!
      *  UART_write() will block the calling task until all of the data can be
      *  accepted by the device driver. UART_read() will block until some data
      *  becomes available.
      */
    UART_Mode_BLOCKING = 0,

    /*!
      *  Non-blocking, UART_write() or UART_read() will return immediately.
      *  When the transfer has finished, the callback function is called
      *  from either the caller's context or from an interrupt context.
      */
    UART_Mode_CALLBACK,

    /*!
      *  Non-blocking, UART_write() or UART_read() will return immediately.
      *  UART_write() will copy as much data into the transmit buffer as space
      *  allows. UART_read() will copy as much data from the receive buffer
      *  as is immediately available.
      */
    UART_Mode_NONBLOCKING,
} UART_Mode;

/*!
 *  @brief      UART return mode settings
 *
 *  This enumeration defines the return modes for UART_read().
 *
 *  #UART_ReadReturnMode_FULL unblocks or performs a callback when the read
 *  buffer has been filled with the number of bytes passed to #UART_read().
 *  #UART_ReadReturnMode_PARTIAL unblocks or performs a callback whenever a
 *  read timeout error occurs on the UART peripheral.  This timeout
 *  error is not the same as the blocking read timeout in the @ref UART_Params;
 *  the read timeout occurs if the read FIFO is non-empty and no new
 *  data has been received for a device/baudrate dependent number of
 *  clock cycles.  This mode can be used when the exact number of bytes to
 *  be read is not known.
 */
typedef enum {
    /*! Unblock/callback when buffer is full. */
    UART_ReadReturnMode_FULL = 0,

    /*! Unblock/callback when no new data comes in. */
    UART_ReadReturnMode_PARTIAL
} UART_ReadReturnMode;

/*!
 *  @brief    UART data length settings.
 *
 *  This enumeration defines the UART data lengths.
 */
typedef enum {
    UART_DataLen_5 = DL_UART_WORD_LENGTH_5_BITS, /*!< Data length is 5 bits */
    UART_DataLen_6 = DL_UART_WORD_LENGTH_6_BITS, /*!< Data length is 6 bits */
    UART_DataLen_7 = DL_UART_WORD_LENGTH_7_BITS, /*!< Data length is 7 bits */
    UART_DataLen_8 = DL_UART_WORD_LENGTH_8_BITS  /*!< Data length is 8 bits */
} UART_DataLen;

/*!
 *  @brief    UART stop bit settings.
 *
 *  This enumeration defines the UART stop bits.
 */
typedef enum {
    UART_StopBits_1 = DL_UART_STOP_BITS_ONE, /*!< One stop bit */
    UART_StopBits_2 = DL_UART_STOP_BITS_TWO  /*!< Two stop bits */
} UART_StopBits;

/*!
 *  @brief    UART parity type settings.
 *
 *  This enumeration defines the UART parity types.
 */
typedef enum {
    UART_Parity_NONE = DL_UART_PARITY_NONE, /*!< No parity */
    UART_Parity_EVEN = DL_UART_PARITY_EVEN, /*!< Parity bit is even */
    UART_Parity_ODD  = DL_UART_PARITY_ODD,  /*!< Parity bit is odd */
    UART_Parity_ZERO = DL_UART_PARITY_STICK_ZERO, /*!< Parity bit is always zero */
    UART_Parity_ONE = DL_UART_PARITY_STICK_ONE /*!< Parity bit is always one */
} UART_Parity;

/*!
 *  @brief    UART Parameters.
 *
 *  UART parameters are used with the UART_open() call. Default values for
 *  these parameters are set using @ref UART_Params_init().
 *
 *  @sa       @ref UART_Params_init()
 */
typedef struct {
    UART_Mode readMode;  /*!< Mode for all read calls */
    UART_Mode writeMode; /*!< Mode for all write calls */
    /*! Pointer to read callback function for callback mode. */
    UART_Callback readCallback;
    /*! Pointer to write callback function for callback mode. */
    UART_Callback writeCallback;
    /*! Pointer to event callback function. */
    UART_EventCallback eventCallback;
    /*! mask of events that the application is interested in */
    uint32_t eventMask;
    UART_ReadReturnMode readReturnMode; /*!< Receive return mode */
    uint32_t baudRate;                  /*!< Baud rate for UART */
    UART_DataLen dataLength;            /*!< Data length for UART */
    UART_StopBits stopBits;             /*!< Stop bits for UART */
    UART_Parity parityType;             /*!< Parity bit type for UART */
    void *userArg; /*!< User supplied argument for callback functions */
} UART_Params;

/*!
 *  @brief  Function to initialize the @ref UART_Params struct to its defaults.
 *
 *  @param[in]  params  A pointer to @ref UART_Params structure for
 *                      initialization.
 *
 *  Defaults values are:
 *  @arg readMode = UART_Mode_BLOCKING;
 *  @arg writeMode = UART_Mode_BLOCKING;
 *  @arg eventCallback = NULL;
 *  @arg eventMask = 0;
 *  @arg readCallback = NULL;
 *  @arg writeCallback = NULL;
 *  @arg readReturnMode = UART_ReadReturnMode_PARTIAL;
 *  @arg baudRate = 9600;
 *  @arg dataLength = UART_DataLen_8;
 *  @arg stopBits = UART_StopBits_1;
 *  @arg parityType = UART_Parity_NONE;
 *  @arg userArg = NULL;
 */
void UART_Params_init(UART_Params *params);

/*!
 *  @brief  Function to initialize a given UART peripheral.
 *
 *  Function to initialize a given UART peripheral specified by the
 *  particular index value.
 *
 *  @param[in]  index     Logical peripheral number for the UART indexed into
 *                        the UART_config table.
 *
 *  @param[in]  params    Pointer to a @ref UART_Params structure. If NULL, default
 *                        parameter values will be used. All the fields in
 *                        this structure are read-only.
 *  @return UART handle
 *  @sa     UART_close()
 */
UART_Handle UART_open(uint_least8_t index, UART_Params *params);

/*!
 *  @brief  Function to close a UART peripheral specified by the UART handle.
 *
 *  @pre    UART_open() has been called.
 *  @pre    There are no ongoing read or write calls.  Any ongoing read
 *          or write calls can be cancelled with UART_readCancel() or
 *          UART_writeCancel().
 *
 *  @param[in]  handle      A #UART_Handle returned from UART_open().
 *
 *  @sa     UART_open()
 */
void UART_close(UART_Handle handle);

/*!
 *  @brief  Function that reads data from a UART.
 *
 *  @ref UART_read() reads data from a UART controller. The destination is
 *  specified by \a buffer and the number of bytes to read is given by
 *  \a size.
 *
 *  In #UART_Mode_BLOCKING, @ref UART_read() blocks task execution until all
 *  the data in buffer has been read, if the read return mode is
 *  #UART_ReadReturnMode_FULL.
 *  If the read return mode is #UART_ReadReturnMode_PARTIAL, @ref UART_read()
 *  returns before all the data has been read, if some data has been received,
 *  but reception has been inactive sufficiently long for a hardware read
 *  timeout to occur (e.g., for a 32-bit period).
 *  If a receive error occurs (e.g., framing, FIFO overrun), @ref UART_read()
 *  will return with the number of bytes read up to the occurrence of the
 *  error.
 *
 *  In #UART_Mode_CALLBACK, @ref UART_read() does not block task execution.
 *  Instead, a callback function specified by @ref UART_Params::readCallback
 *  is called when the transfer is finished (#UART_ReadReturnMode_FULL), or
 *  reception has become inactive (#UART_ReadReturnMode_PARTIAL).
 *  The callback function can occur in the caller's context or in SWI
 *  context, depending on the device-specific implementation.
 *  An unfinished asynchronous read operation must always be cancelled using
 *  UART_readCancel() before calling UART_close().
 *
 *  @note It is ok to call @ref UART_read() from its own callback function when in
 *  #UART_Mode_CALLBACK.
 *
 *  @param[in]  handle  A #UART_Handle returned by UART_open().
 *
 *  @param[in]  buf  A pointer to an empty buffer to which
 *                      received data should be read.
 *
 *  @param[in]  size    The number of bytes to be read into buffer.
 *
 *  @param[out]  bytesRead   If non-NULL, the location to store the number of
 *                      bytes actually read into the buffer.  If NULL, this
 *                      parameter will be ignored.  In callback mode, NULL
 *                      could be passed in for this parameter, since the
 *                      callback function will be passed the number of bytes
 *                      read.  In blocking mode, NULL can be passed,
 *                      however, status should be checked in case the number
 *                      of bytes requested was not received due to errors.
 *
 *  @return Returns a status indicating success or failure of the read.
 *
 *  @retval #UART_STATUS_SUCCESS    The call was successful.
 *  @retval #UART_STATUS_EINUSE     Another read from the UART is currently
 *                                   ongoing.
 *  @retval #UART_STATUS_ECANCELLED In #UART_Mode_BLOCKING, the read was
 *                                   canceled by a call to UART_readCancel()
 *                                   before any data could be received.
 */
int_fast16_t UART_read(UART_Handle handle, void *buf, size_t size, size_t *bytesRead);

/*!
 *  @brief  Function that writes data to a UART.
 *
 *  @ref UART_write() writes data from a memory buffer to the UART interface.
 *  The source is specified by \a buffer and the number of bytes to write
 *  is given by \a size.
 *
 *  In #UART_Mode_BLOCKING, UART_write() blocks task execution until all
 *  the data in buffer has been transmitted onto the TX pin.
 *
 *  In #UART_Mode_CALLBACK, @ref UART_write() does not block task execution.
 *  Instead, a callback function specified by @ref UART_Params::writeCallback is
 *  called when all data has been written to the hardware FIFO. This means that
 *  that driver is ready to accept another call to UART_write().
 *  @note In contrast to #UART_Mode_BLOCKING, it is not guaranteed that all
 *  data has been transmitted onto the TX pin when callback is invoked.
 *
 *  The buffer passed to UART_write() in #UART_Mode_CALLBACK is not
 *  copied. The buffer must remain coherent until all the characters have
 *  been sent (ie until the write callback has been called with a byte count
 *  equal to that passed to UART_write()).
 *  The callback function can occur in the caller's task context or in
 *  interrupt context, depending on the device implementation.
 *  An unfinished asynchronous write operation must always be cancelled using
 *  UART_writeCancel() before calling UART_close().
 *
 *  The bytesWritten parameter should not be NULL so the application can
 *  determine the number of bytes actually written.
 *
 *  @param[in]  handle   A #UART_Handle returned by UART_open().
 *
 *  @param[in]  buf   A read-only pointer to buffer containing data to
 *                       be written to the UART.
 *
 *  @param[in]  size     The number of bytes in the buffer that should be
 *                       written to the UART.
 *
 *  @param[out]  bytesWritten If non-NULL, the location to store the number of
 *                       bytes actually written to the UART in
 *                       UART_Mode_BLOCKING.  In UART_Mode_CALLBACK, bytesWritten
 *                       will be set to 0. If bytesWritten is NULL, this parameter will be
 *                       ignored.
 *
 *  @return Returns a status indicating success or failure of the write.
 *
 *  @retval #UART_STATUS_SUCCESS The call was successful.
 *  @retval #UART_STATUS_EINUSE  Another write to the UART is currently
 *                                ongoing.
 */

int_fast16_t UART_write(UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten);

/*!
 *  @brief      UART read with timeout. Note that the timeout parameter is different from the
 *              hardware read timeout.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[in]  buf       location where the data to be written.
 *  @param[in]  size      amount of data to write in bytes.
 *  @param[out] bytesRead If non-NULL, the location to store the number
 *                        of bytes actually read into the buffer. If NULL,
 *                        this parameter will be ignored.
 *  @param[in]  timeout   The number of system clock ticks to wait until
 *                        all data is received.  If not all requested data
 *                        was received within the timeout period, an error of
 *                        UART_STATUS_ETIMEOUT will be returned.  This
 *                        parameter is only applicable to #UART_Mode_BLOCKING.
 *  @return Returns a status indicating success or failure of the read.
 *
 *  @retval #UART_STATUS_SUCCESS    The call was successful.
 *  @retval #UART_STATUS_EINUSE     Another read from the UART is currently
 *                                   ongoing.
 *  @retval #UART_STATUS_ECANCELLED In #UART_Mode_BLOCKING, the read was
 *                                   canceled by a call to UART_readCancel()
 *                                   before any data could be received.
 *  @retval #UART_STATUS_ETIMEOUT   The read operation timed out.
 */
int_fast16_t UART_readTimeout(UART_Handle handle, void *buf, size_t size, size_t *bytesRead, uint32_t timeout);

/*!
 *  @brief      UART write with timeout. Note that the timeout parameter is different from the
 *              hardware read timeout.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[in]  buf       location to write data from.
 *  @param[in]  size      amount of data to write in bytes.
 *  @param[out] bytesWritten If non-NULL, the location to store the number
 *                        of bytes actually written into the buffer. If
 *                        NULL, this parameter will be ignored.
 *  @param[in]  timeout  The number of system clock ticks to wait for the
 *                       write to complete (#UART_Mode_BLOCKING only).  If
 *                       the timeout expires before all bytes are written, a
 *                       status of UART_STATUS_ETIMEOUT will be returned.
 *  @return Returns a status indicating success or failure of the write.
 *
 *  @retval #UART_STATUS_SUCCESS The call was successful.
 *  @retval #UART_STATUS_EINUSE  Another write to the UART is currently
 *                                ongoing.
 *  @retval #UART_STATUS_ETIMEOUT The write operation timed out.
 */
int_fast16_t UART_writeTimeout(UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten, uint32_t timeout);

/*!
 *  @brief  Function that cancels a UART_read() function call.
 *
 *  This function cancels an asynchronous UART_read() operation in
 *  in #UART_Mode_CALLBACK, or unblocks a UART_read() call in
 *  #UART_Mode_BLOCKING.
 *  In #UART_Mode_CALLBACK,  UART_readCancel() calls the registered read
 *  callback function with the number of bytes received so far.
 *  It is the application's responsibility to check the count argument
 *  in the callback function and handle the case where only a subset of the
 *  bytes were received.  The callback function will be passed a status of
 *  #UART_STATUS_ECANCELLED.
 *
 *  In #UART_Mode_BLOCKING, #UART_read() will return
 *  #UART_STATUS_ECANCELLED, and the bytesRead parameter will be set to
 *  the number of bytes received so far.
 *
 *  @param[in]  handle      A #UART_Handle returned by UART_open().
 */
void UART_readCancel(UART_Handle handle);

/*!
 *  @brief  Function that cancels a UART_write() function call.
 *
 *  This function cancels an asynchronous UART_write() operation when
 *  write mode is #UART_Mode_CALLBACK.
 *  In callback mode, UART_writeCancel() calls the registered
 *  write callback function no matter how many bytes were sent. It
 *  is the application's responsibility to check the count argument in the
 *  callback function and handle cases where only a subset of the bytes were
 *  sent. The callback function will be passed a status of
 *  #UART_STATUS_ECANCELLED.
 *  In blocking mode, UART_write() will return #UART_STATUS_ECANCELLED.
 *
 *  @note The above applies to @ref UART_writeTimeout() as well.
 *
 *  @param[in]  handle      A #UART_Handle returned by UART_open().
 */
void UART_writeCancel(UART_Handle handle);

/*!
 *  @brief  Function that disables collecting of RX data into the circular
 *          buffer.
 *
 *  The driver implementation uses a circular buffer to collect RX
 *  data while a UART_read() is not in progress.  This function will
 *  disable buffering of RX data into the circular buffer. UART_read() will
 *  read directly from the UART driver's RX buffer.  Disabling the circular
 *  buffer will also allow the device to go into low power modes.
 *
 *  @param[in]  handle      A #UART_Handle returned by UART_open().
 *
 *  @sa     UART_rxEnable()
 */
void UART_rxDisable(UART_Handle handle);

/*!
 *  @brief  Function that enables collecting of RX data into the circular
 *          buffer.
 *
 *  The driver implementation uses a circular buffer to collect RX
 *  data while a UART_read() is not in progress.  This function will
 *  enable buffering of RX data into the circular buffer. UART_read() will
 *  read directly from the UART drivers RX buffer. Enabling the circular
 *  buffer will also prevent the device from going into low power modes.
 *
 *  @param[in]  handle      A #UART_Handle returned by UART_open().
 *
 *  @sa     UART_rxDisable()
 */
void UART_rxEnable(UART_Handle handle);

/*!
 *  @brief  Function to flush data in the UART RX FIFO.
 *
 *  @pre    UART_open() has been called.
 *
 *  This function can be called to remove all data from the RX FIFO, for
 *  example, after a UART read error has occurred.
 *  All data in the RX circular buffer will be discarded.
 *
 *  @param[in]  handle      A #UART_Handle returned from UART_open().
 */
void UART_flushRx(UART_Handle handle);

/*!
 *  @brief  Get the number of bytes available in the circular buffer.
 *
 *  @pre    UART_open() has been called.
 *
 *  @param[in]  handle      A #UART_Handle returned from UART_open().
 *
 *  @return Returns the number of bytes available in the RX circular
 *          buffer.
 *
 *  @sa     UART_rxEnable()
 */
void UART_getRxCount(UART_Handle handle);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ti_drivers_uart_UART__include */
/* clang-format on */
/** @}*/
