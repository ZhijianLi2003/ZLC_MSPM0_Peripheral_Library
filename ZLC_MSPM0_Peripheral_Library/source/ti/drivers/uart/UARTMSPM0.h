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
 *  @file       UARTMSPM0.h
 *
 *  @brief      UART driver interface for the MSPM0 devices.
 *
 *  @defgroup   UARTMSPM0 UART driver APIs
 *
 *  # Overview
 *  Refer to @ref ti_drivers_UART_Overview for a complete description of APIs and examples
 *  of use.
 *
 ******************************************************************************
 */
/** @addtogroup UARTMSPM0
 *  @ingroup UART
* @{
*/
/* clang-format off */
#ifndef ti_drivers_uart_UARTMSPM0__include
#define ti_drivers_uart_UARTMSPM0__include

#include <ti/devices/msp/msp.h>
#include <ti/drivers/uart/UARTSupportMSPM0.h>

/*!
 *  @brief UART support function pointers.
 */
extern const UARTSupport_Fxns UARTMSPSupportFxns;

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  @brief UART receive errors.
 */
#define UART_RX_ERRS                                                         \
    (DL_UART_INTERRUPT_OVERRUN_ERROR | DL_UART_INTERRUPT_BREAK_ERROR | \
        DL_UART_INTERRUPT_PARITY_ERROR |                                  \
        DL_UART_INTERRUPT_FRAMING_ERROR)

/*!
 *  @brief      Private Metadata structure for a UART instance supporting
 *              hardware parameters.
 */
typedef struct
{
    UART_Regs *regs;                        /*!< Pointer to UART register */
    IRQn_Type irq;                          /*!< UART Irq */
    uint32_t rxPin;                         /*!< Rx port pin */
    uint32_t rxPinFunction;                 /*!< Rx pin function */
    uint32_t txPin;                         /*!< Tx port pin */
    uint32_t txPinFunction;                 /*!< Tx pin function */
    DL_UART_MODE mode;                      /*!< UART mode */
    DL_UART_DIRECTION direction;            /*!< UART direction */
    DL_UART_FLOW_CONTROL flowControl;       /*!< Select UART flow control */
    DL_UART_CLOCK clockSource;              /*!< Clock source */
    DL_UART_CLOCK_DIVIDE_RATIO clockDivider;/*!< Clock div */
    DL_UART_RX_FIFO_LEVEL rxIntFifoThr;     /*!< Select threshold for Rx FIFO */
    DL_UART_TX_FIFO_LEVEL txIntFifoThr;     /*!< Select threshold for Tx FIFO */
} UARTMSP_HWAttrs;
/*!
 *  @brief  This function returns a pointer to UART object.
 *
 *  @pre    Config Parameters.
 *          Calling context: function
 *
 *  @param  handle:  A UART handle return by UART_open()
 *
 *  @return Return a UART object pointer.
 *
 */
__STATIC_INLINE UART_Object* UART_Obj_Ptr(UART_Handle handle)
{
    return (UART_Object *) (handle->object);
}

/*!
 *  @brief  This function returns a pointer to UART hardware Attribute.
 *
 *  @pre    Config Parameters.
 *          Calling context: function
 *
 *  @param  handle:  A UART handle return by UART_open().
 *
 *  @return Return a UART HWAttrs pointer.
 *
 */
__STATIC_INLINE UARTMSP_HWAttrs* UART_HWAttrs_Ptr(UART_Handle handle)
{
    return (UARTMSP_HWAttrs *) (handle->hwAttrs);
}
/* The functions given below are based on @ref UART_Data_Object structure.
* These functions return a pointer to particular element in the structure
* which is based on the sequence in the structure. The sequence of elements
* in @ref UART_Data_Object must NOT be modified else below functions will be broken.
*/
/*!
 *  @brief  This function returns a pointer to UART buffers object.
 *
 *  @pre    Config Parameters.
 *          Calling context: function
 *
 *  @param  *object:  A UART object pointer.
 *
 *  @return Return a UART buffers object pointer.
 *
 */
__STATIC_INLINE UART_Buffers_Object *UART_buffersObject(UART_Object *object)
{
    return (UART_Buffers_Object *) (object + 1);
}

/*!
 *  @brief  This function returns a pointer to UART event callback object.
 *
 *  @pre    Config Parameters.
 *          Calling context: function
 *
 *  @param  *object:  A UART object pointer.
 *
 *  @return Return a UART event callback object pointer.
 *
 */
__STATIC_INLINE UART_EventCallback_Object *UART_eventCallbackObject(UART_Object *object)
{
    return (UART_EventCallback_Object *) (UART_buffersObject(object) + 1);
}

/*!
 *  @brief  This function returns a pointer to UART callback object.
 *
 *  @pre    Config Parameters.
 *          Calling context: function
 *
 *  @param  *object:  A UART object pointer.
 *
 *  @return Return a UART callback object pointer.
 *
 */
__STATIC_INLINE UART_Callback_Object *UART_callbackObject(UART_Object *object)
{
    return (UART_Callback_Object *) (UART_eventCallbackObject(object) + 1);
}

/*!
 *  @brief  This function handles the UART interrupts.
 *
 *  @pre    Config Parameters.
 *
 *  @param  handle: A UART handle return by UART_open().
 *
 *  @return void
 *
 */
void UARTMSP_interruptHandler(UART_Handle handle);
#ifndef UART_NO_DMA
/*!
 *  @brief  This function configures and starts DMA transfer.
 *
 *  @pre    Config Parameters.
 *          Calling context: Task
 *
 *  @param  handle: A UART handle return by UART_open().
 *
 *  @return void
 *
 *  @sa     UART_open()
 */
void UARTMSP_dmaTx(UART_Handle handle);

/*!
 *  @brief  This function configures and starts DMA receive.
 *
 *  @pre    Config Parameters.
 *          Calling context: Task
 *
 *  @param  handle: A UART handle return by UART_open().
 *  @param  copyfifo: true: copy fifo.
 *                    false: don't copy fifo.
 *  @return void
 *
 *  @sa     UART_open()
 */
void UARTMSP_dmaRx(UART_Handle handle, bool copyfifo);

/*!
 *  @brief  This function stops DMA rx and disables the channel.
 *
 *  @pre    Config Parameters.
 *          Calling context: Task
 *
 *  @param  handle: A UART handle return by UART_open().
 *
 *  @return void
 *
 *  @sa     UART_open()
 */
void UARTMSP_dmaStopRx(UART_Handle handle);

/*!
 *  @brief  This function stops DMA tx and disables the channel.
 *
 *  @pre    Config Parameters.
 *          Calling context: Task
 *
 *  @param  handle: A UART handle return by UART_open().
 *
 *  @return Returns the remaining bytes to transmit.
 *
 *  @sa     UART_open()
 */
uint32_t UARTMSP_dmaStopTx(UART_Handle handle);
#endif
/*!
 *  @brief  This function enables receive, receive timeout, and error interrupts.
 *
 *  @pre    Config Parameters.
 *          Calling context: Task
 *
 *  @param  handle: A UART handle return by UART_open().
 *
 *  @return void
 *
 *  @sa     UART_open()
 */
void UARTMSP_enableInts(UART_Handle handle);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ti_drivers_uart_UARTMSPM0__include */
/* clang-format on */
/** @}*/
