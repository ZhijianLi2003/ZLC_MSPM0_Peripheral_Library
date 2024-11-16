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
 *  @file       DMAMSPM0.h
 *
 *  @brief      DMA driver implementation for MSPM0.
 *
 *  @defgroup   DMA Direct Memory Access (DMA)
 *
 *  The DMA header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/dma/DMAMSPM0.h>
 *  @endcode
 *
 *  @anchor ti_drivers_DMA_Overview
 *  # Overview
 *
 *  This driver is intended for use only by drivers that use the DMA
 *  peripheral (e.g., SPI).  This driver is mainly used for management of
 *  the control table base address of the DMA peripheral.
 *
 *  The application should set up the DMAMSPM0_HWAttrs and DMAMSPM0_Config structures.
 *
 *  The DMAMSPM0 header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/dma/DMAMSPM0.h>
 *  @endcode
 *
 ******************************************************************************
 */
/** @addtogroup DMA
* @{
*/
/* clang-format off */
#ifndef ti_drivers_dma_DMAMSPM0__include
#define ti_drivers_dma_DMAMSPM0__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/driverlib/dl_dma.h>
#include <ti/drivers/dpl/HwiP.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  @brief      Number of DMA channels supported by Device.
 *              The same can be used to define the number of interrupts.
 *
 *  @note       DMA_SYS_N_DMA_CHANNEL can be found in the device specific
 *              header file (e.g. source/ti/devices/msp/m0p/mspm0g350x.h)
 */
#define NUM_DMA_CHANNELS (DMA_SYS_N_DMA_CHANNEL)

/*!
 *  @brief      DMA error function pointers
 */
typedef void (*DMAMSPM0_IsrFxn)(uintptr_t arg);

/*!
 *  @brief      DMAMSPM0 Hardware attributes.
 *
 *  This structure contains the error interrupt attributes.
 *
 *  dmaIsrFxn is the DMA peripheral's  interrupt handler.
 *
 *  intPriority is priority of the DMA peripheral's error interrupt, as
 *  defined by the underlying OS.  It is passed unmodified to the
 *  underlying OS's interrupt handler creation code, so you need to
 *  refer to the OS documentation(FreeRTOS) for usage.  If the
 *  driver uses the ti.dpl interface instead of making OS
 *  calls directly, then the HwiP port handles the interrupt priority
 *  in an OS specific way.
 *
 *  A sample structure is shown below:
 *  @code
 *
 *  #include <ti/driverlib/dl_dma.h>
 *
 *  #include <ti/drivers/dma/DMAMSPM0.h>
 *
 *  DMAMSPM0_Object dmaMSPM0Object;
 *
 *  const DMAMSPM0_HWAttrs DMAMSPM0HWAttrs =
 *  {
 *      .dmaIsrFxn = NULL,
 *      .intPriority = DEFAULT_DMA_PRIORITY,
 *      .roundRobinPriority = false,
 *  };
 *  @endcode
 *
 */
typedef struct
{
    DMAMSPM0_IsrFxn dmaIsrFxn; /*!< interrupt handler*/
    uint8_t intPriority;       /*!< interrupt priority */
    bool roundRobinPriority;   /*!< Round robin priority for DMA channels*/
} DMAMSPM0_HWAttrs;



/*!
 *  @brief  DMAMSPM0 channel based Transfer configuration.
 *
 *  The DMAMSPM0_Transfer structure contains parameters for initializing a
 *  DMA transfer using a given DMA channel number.
 *
 *  This struct is used in DMAMSPM0_setupTransfer().
 */
typedef struct
{
    uint8_t txTrigger;                  /*!< DMA Tx trigger */
    uint8_t rxTrigger;                  /*!< DMA Rx trigger */
    DL_DMA_TRIGGER_TYPE txTriggerType;  /*!< DMA Tx trigger type */
    DL_DMA_TRIGGER_TYPE rxTriggerType;  /*!< DMA Rx trigger type */
    DL_DMA_TRANSFER_MODE transferMode;  /*!< DMA transfer mode */
    DL_DMA_EXTENDED_MODE extendedMode;  /*!< DMA extended mode */
    DL_DMA_WIDTH srcWidth;              /*!< DMA source width in bytes */
    DL_DMA_WIDTH destWidth;             /*!< DMA destination width in bytes */
    DL_DMA_INCREMENT srcIncrement;      /*!< DMA source increment selection */
    DL_DMA_INCREMENT destIncrement;     /*!< DMA destination increment selection */

    uint8_t dmaChannel;                 /*!< DMA channel */
    void *dmaTransferSource;            /*!< Source of DMA transfer */
    void *dmaTransferDestination;       /*!< Destination of DMA transfer */
    uint32_t noOfData;                  /*!< no of data bytes to be transferred (DMASZ) */
    DMAMSPM0_IsrFxn dmaChIsrFxn;        /*!< Channel based interrupt handler*/
    bool enableDMAISR;                  /*!< true: Enable DMA ISR for the channel, false:use Peripheral ISR*/
} DMAMSPM0_Transfer;

/*!
 *  @brief  DMAMSPM0 object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct
{
    /*! dmaTransfer should me configured for each DMA channels using configuration */
    DMAMSPM0_Transfer dmaTransfer;
} DMAMSPM0_Object;
/*!
 *  @brief      DMAMSPM0 Global configuration.
 *
 *  The DMAMSPM0_Cfg structure contains pointers used by the DMAMSPM0
 *  driver.
 *
 *  This structure needs to be defined before calling DMAMSPM0_init() and
 *  it must not be changed thereafter.
 */
typedef struct
{
    void const *hwAttrs;        /*!< Pointer to hardware attributes */
    void *object;        /*!< Pointer to DMAMSPM0 object */
} DMAMSPM0_Cfg;

/*!
 *  @brief      Instance of a DMA Config structure.
 */
extern const DMAMSPM0_Cfg DMAMSPM0_Config[];

/*!
 *  @brief      Number of DMA channels.
 */
extern const uint_least8_t DMA_Count;

/*!
 *  @brief      A handle that is returned from a DMAMSPM0_open() call.
 */
typedef DMAMSPM0_Cfg* DMAMSPM0_Handle;

/*!
 *  @brief  Function to close the DMA channel.
 *
 *  Close a DMA handle returned from DMAMSPM0_open(). After this function
 *  if a new channel can be initialize then just call DMAMSPM0_open().
 *  It is not necessary to call DMA init again.
 *  @pre    DMAMSPM0_open() has to be called first.
 *          Calling context: Task
 *
 *  @param  handle:  A DMAMSPM0_Handle returned from DMAMSPM0_open()
 *  @param  channelNum:  A DMA channel defined in dl_dma.h (e.g. DL_DMA_EVENT_IIDX_DMACHX)
 *  @return none
 *
 *  @sa     DMAMSPM0_open
 */
extern void DMAMSPM0_close(DMA_Regs *handle, uint8_t channelNum);
/*!
 *  @brief  Function to initialize the MSPM0 DMA driver.
 *
 *  The function initialize the DMA HWI, and should be called prior
 *  to opening the DMA driver.
 *  This function will be called in DMA_Init().
 *  @return bool : Status if DMA is successfully initialized.
 *
 *  @sa     DMAMSPM0_open()
 */
extern bool DMAMSPM0_init(void);

/*!
 *  @brief  Function to initialize the MSPM0 DMA peripheral and corresponding interrupt.
 *
 *  DMAMSPM0_open() opens the DMA peripheral. It setup an interrupt for specified channel
 *  This function can be called multiple times. This function is being called in DMA_Init().
 *  @pre    DMAMSPM0_init() has to be called first.
 *          Calling context: Task
 *  @param  index:  A DMA config index.
 *  @param  channelNum:  A DMA channel.
 *
 *  @return DMAMSPM0_Handle on success or NULL if an error has occurred.
 *
 *  @sa     DMAMSPM0_close()
 */
extern DMAMSPM0_Handle DMAMSPM0_open(uint_least8_t index, uint8_t channelNum);

/*!
 *  @brief  Function to set up a DMA channel for data transfer.
 *
 *  The function will set the channel control, set the channel transfer,
 *  assign the channel, and enable the channel.
 *
 *  @pre    DMAMSPM0_open() has to be called first.
 *
 *  @param  transfer:  Pointer to a DMAMSPM0_Transfer param struct.
 *  @param  DMACfg:    Pointer to the DL_DMA_Config struct.
 *
 *  @return true on success or false if an error has occurred.
 */
bool DMAMSPM0_setupTransfer(DMAMSPM0_Transfer *transfer, DL_DMA_Config* DMACfg);
/*!
 *  @brief  One Function that initialize DMA by calling all needed functions in sequence.
 *          User may call this function to initialize DMA without calling other needed
 *          functions separately.
 *
 *  @pre    Config Parameters.
 *          Calling context: Task
 *
 *  @param  dmaParams:  Pointer to DMA transfer params.
 *  @param  DMACfg:   Pointer to DMA config params.
 *  @param  noOfChs:   No of DMA channels being used
 *
 *  @return DMAMSPM0_Handle on success or NULL if an error has occurred.
 *
 *  @sa     DMAMSPM0_close()
 */
DMAMSPM0_Handle DMA_Init(DMAMSPM0_Transfer* dmaParams, DL_DMA_Config* DMACfg, uint8_t noOfChs);

/*!
 *  @brief  This function will disable the channel and related flags.
 *
 *  @pre    Config Parameters.
 *          Calling context: Task
 *
 *  @param  handle:  DMA Config Handle.
 *  @param  dmaChannel:  DMA Channel
 *
 *  @return void
 *
 *  @sa     DMAMSPM0_close()
 */
void DMAMSPM0_disableChannel(DMAMSPM0_Handle handle, uint8_t dmaChannel);

/*!
 *  @brief  This function will return the DMA transfer size in bytes for given channel.
 *
 *  @pre    Config Parameters.
 *          Calling context: Task
 *
 *  @param  dmaChannel:  DMA Channel
 *
 *  @return Returns the current transfer size in bytes.
 *
 *  @sa     DMAMSPM0_close()
 */
uint16_t DMAMSPM0_getCurrTransferSize(uint8_t dmaChannel);

/*!
 *  @brief  This function will initialize the default params.
 *
 *  @pre    Config Parameters.
 *          Calling context: Task
 *
 *  @param  params:  Pointer to the DMA Transfer Params
 *
 *  @return void
 *
 *  @sa     DMAMSPM0_close()
 */
void DMA_Params_init(DMAMSPM0_Transfer *params);

/*!
 *  @brief  This function will extract parameters from DMA Config struct
 *          to DMA Transfer struct.
 *
 *  @pre    Config Parameters.
 *          Calling context: Task
 *
 *  @param  dmaParams:  Current DMA Transfer Params.
 *  @param  dmaConfig:  DMA Config Params.
 *
 *  @return void
 *
 *  @sa     DMAMSPM0_close()
 */
void DMAMSPM0_copyDMAParams(DMAMSPM0_Transfer* dmaParams, DL_DMA_Config* dmaConfig);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_dma_DMAMSPM0__include */
/* clang-format on */
/** @}*/
