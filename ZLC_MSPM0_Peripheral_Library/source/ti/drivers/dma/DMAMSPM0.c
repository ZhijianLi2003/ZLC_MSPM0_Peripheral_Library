/*
 * Copyright (c) 2022, Texas Instruments Incorporated
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
/* clang-format off */
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <ti/devices/DeviceFamily.h>

#include <ti/driverlib/dl_dma.h>
#include <ti/drivers/dma/DMAMSPM0.h>
#include <ti/drivers/dpl/HwiP.h>
#include <ti/drivers/dpl/SemaphoreP.h>

/* This structure must be defined in the peripheral application using DMA */
__WEAK const DMAMSPM0_Cfg DMAMSPM0_Config[];

/*
 * Lock for exclusive access to hwiFxnArgs, hwiFxnHandlers & hwiHandles arrays
 * during DMAMSPM0_open() & DMAMSPM0_close()
 */
static SemaphoreP_Handle interruptSetupLock = NULL;

/* Bit-mask of DMA channels currently being used */
static uint32_t channelsInUse = 0;

/* Bit-mask of DMA channels for transfer is currently setup or not */
static uint32_t chTransferSet = 0;

static bool dmaInitialized = false;

static uint32_t dmaIntRefCount = 0;

/* The Hwi handle for DMA interrupt */
static HwiP_Handle hwiHandle;

/* Array of ISR pointers called when a channel causes an interrupt on DMA_INT0 */
static void (*hwiFxnHandlers[NUM_DMA_CHANNELS])(uintptr_t);

/* Array of ISR arguments */
static uintptr_t hwiFxnArgs[NUM_DMA_CHANNELS];

static void DMAMSPM0_hwiFxn(uintptr_t arg);


/* Default DMA parameters structure */
const DMAMSPM0_Transfer DMA_Ch_defaultParams =
{
    .txTrigger = DMA_SOFTWARE_TRIG,  /* default is sw trigger */
    .rxTrigger = DMA_SOFTWARE_TRIG,  /* default is sw trigger */
    .txTriggerType = DL_DMA_TRIGGER_TYPE_EXTERNAL,
    .rxTriggerType = DL_DMA_TRIGGER_TYPE_EXTERNAL,
    .extendedMode = DL_DMA_NORMAL_MODE,  /* default is normal extended mode */
    .transferMode = DL_DMA_SINGLE_TRANSFER_MODE,        /* default is single transfer mode */
    .srcWidth  = DL_DMA_WIDTH_BYTE,  /* default src width is 32-bit */
    .destWidth = DL_DMA_WIDTH_BYTE,  /* default dest width is 32-bit */
    .srcIncrement = DL_DMA_ADDR_INCREMENT,  /* default is increment DMA src address */
    .destIncrement = DL_DMA_ADDR_INCREMENT,        /* default is increment DMA dest address */
    .dmaChannel             = 0,      /* default DMA ch is 0 */
    .dmaTransferSource      = NULL,   /* default source address is null */
    .dmaTransferDestination = NULL,   /* default destination address is null */
    .dmaChIsrFxn            = NULL,   /* default the DMA channel isr function is NULL */
    .enableDMAISR           = false,  /* default the DMA channel isr is disabled */
};

/*
 *  ======== DMAMSPM0_close ========
 */
void DMAMSPM0_close(DMA_Regs *handle, uint8_t channel)
{
    uintptr_t key;
    uint16_t channelMask;
    uint8_t channelNum;

    channelNum  = channel;
    channelMask = 1 << channelNum;

    if (channelNum >= NUM_DMA_CHANNELS)
    {
        return;
    }

    if ((channelsInUse & channelMask) == 0)
    {
        return;
    }

    if (channelNum < NUM_DMA_CHANNELS)
    {
        /* Acquire exclusive access to interrupt arrays & masks */
        SemaphoreP_pend(interruptSetupLock, SemaphoreP_WAIT_FOREVER);

        hwiFxnHandlers[channelNum] = NULL;
        hwiFxnArgs[channelNum]     = (uintptr_t) NULL;

        dmaIntRefCount--;

        if (dmaIntRefCount == 0)
        {
            HwiP_delete(hwiHandle);
            hwiHandle = NULL;

            chTransferSet &= ~channelMask;
        }

        SemaphoreP_post(interruptSetupLock);
    }

    /* Free the channel */
    key = HwiP_disable();

    channelsInUse &= ~channelMask;

    HwiP_restore(key);
}

/*
 *  ======== DMAMSPM0_init ========
 */
bool DMAMSPM0_init(void)
{
    uintptr_t key;
    HwiP_Params hwiParams;
    SemaphoreP_Handle sem;
    DMAMSPM0_Handle handle    = (DMAMSPM0_Handle)&DMAMSPM0_Config;
    DMAMSPM0_HWAttrs *hwAttrs = (DMAMSPM0_HWAttrs *)handle->hwAttrs;

    /* speculatively create a binary semaphore for thread safety */
    sem = SemaphoreP_createBinary(1);

    key = HwiP_disable();

    if (interruptSetupLock == NULL)
    {
        /* use the binary sem created above */
        interruptSetupLock = sem;

        HwiP_restore(key);
    }
    else  /* if this function called again before DMA_Close(), then delete sem */
    {
        /* delete unused Semaphore */
        if (sem)
        {
            SemaphoreP_delete(sem);
        }
        HwiP_restore(key);
        return false;
    }
     key = HwiP_disable();
    if (interruptSetupLock == NULL)  /* semaphore is not set */
    {
        HwiP_restore(key);
        return false;
    }
    HwiP_restore(key);
    /* Acquire exclusive access while initializing */
    SemaphoreP_pend(interruptSetupLock, SemaphoreP_WAIT_FOREVER);

    if (!dmaInitialized)
    {
        hwAttrs->dmaIsrFxn = &DMAMSPM0_hwiFxn;

        HwiP_Params_init(&hwiParams);
        hwiParams.arg      = (uintptr_t) handle;
        hwiParams.priority = hwAttrs->intPriority;
        hwiHandle = HwiP_create(DMA_INT_VECn, hwAttrs->dmaIsrFxn, &hwiParams);

        if (hwiHandle == NULL)
        {
            SemaphoreP_post(interruptSetupLock);
            return false;
        }

        dmaInitialized = true;

        /* if round robin priority is not enabled before then enable it */
        if ((hwAttrs->roundRobinPriority) && (!DL_DMA_isRoundRobinPriorityEnabled(DMA)))
        {
            DL_DMA_enableRoundRobinPriority(DMA);
        }
        else if (!(hwAttrs->roundRobinPriority) && (DL_DMA_isRoundRobinPriorityEnabled(DMA)))
        {
            DL_DMA_disableRoundRobinPriority(DMA);
        }
    }

    SemaphoreP_post(interruptSetupLock);
    return true;
}

/*
 * ======== DMA_Params_init ========
 */
void DMA_Params_init(DMAMSPM0_Transfer *params)
{
    *params = DMA_Ch_defaultParams;
}

/*
 *  ======== DMAMSPM0_open ========
 * index: DMA object struct index
 * channelNum: 0-3 or 0-7
 *
 */
DMAMSPM0_Handle DMAMSPM0_open(uint_least8_t index, uint8_t channelNum)
{
    uintptr_t key;
    uint8_t channelNo;
    uint32_t channelMask;

    DMAMSPM0_Handle handle = (DMAMSPM0_Handle)DMAMSPM0_Config;
    DMAMSPM0_Transfer* object = ((DMAMSPM0_Transfer*)handle->object)+index;
    if (!dmaInitialized || hwiHandle == NULL)
    {
        /* Driver did not initialize correctly */
        return (NULL);
    }

    channelNo   = channelNum;
    channelMask = 1 << channelNo;

    if (channelNo >= NUM_DMA_CHANNELS)
    {
        return (NULL);
    }

    key = HwiP_disable();

    /*
     *  If the desired channel is already being used by another peripheral
     *  abort. Otherwise, claim the channel and set it up to transfer data.
     */
    if (channelsInUse & channelMask)
    {
        HwiP_restore(key);
        return (NULL);
    }

    channelsInUse |= channelMask;

    /* Configure Hwi for DMA channel */
    if (object->enableDMAISR && (object->dmaChIsrFxn != NULL))
    {
        /* Acquire exclusive access to interrupt arrays & masks */
        SemaphoreP_pend(interruptSetupLock, SemaphoreP_WAIT_FOREVER);

        /* Clear DMA interrupt flags before creating the Hwi */
        DL_DMA_clearInterruptStatus(DMA, channelMask);

        hwiFxnHandlers[channelNum] = object->dmaChIsrFxn;
        hwiFxnArgs[channelNum]     = (uintptr_t) handle;
        dmaIntRefCount++;

        SemaphoreP_post(interruptSetupLock);

        /* Setup the peripheral interrupt */
        DL_DMA_enableInterrupt(DMA, channelMask);
    }

    HwiP_restore(key);

    return handle;
}

/*
 *  ======== DMAMSPM0_setupTransfer ========
 */
bool DMAMSPM0_setupTransfer(DMAMSPM0_Transfer *transfer, DL_DMA_Config* DMACfg)
{
    uintptr_t key;
    uint32_t chMask                   = 0;
    DMAMSPM0_Transfer *transferHandle = transfer;
    uint8_t dmaChannelIndex           = transferHandle->dmaChannel;
    chMask                            = 1 << dmaChannelIndex;

    /* The DMA must be open in order to configure a channel */
    if (!dmaInitialized)
    {
        return (false);
    }
    /* The channel transfer should not be set */
    if (chTransferSet & chMask)
    {
        return (false);
    }

    /* A lock is needed because we are accessing shared DMA registers */
    key = HwiP_disable();

    /* set source address */
    DL_DMA_setSrcAddr(DMA, dmaChannelIndex, (uint32_t)transferHandle->dmaTransferSource);

    /* set destination address */
    DL_DMA_setDestAddr(DMA, dmaChannelIndex,(uint32_t)transferHandle->dmaTransferDestination);

    /* Initialize the channel for transfer */
    DL_DMA_initChannel(DMA, dmaChannelIndex, DMACfg);

    /* Set transfer Size */
    DL_DMA_setTransferSize(DMA, dmaChannelIndex, transferHandle->noOfData);

    /* Enable the channel */
    DL_DMA_enableChannel(DMA, dmaChannelIndex);

    /* setup for channel is done */
    chTransferSet |= chMask;

    /* Clear the channel interrupt */
    DL_DMA_clearInterruptStatus(DMA, ((uint32_t)(1 << dmaChannelIndex)));

    /* start transfer */
    DL_DMA_startTransfer(DMA, dmaChannelIndex);

    HwiP_restore(key);

    return (true);
}

/*
 * ============Function to disable one or more DMA channels===============
*/
void DMAMSPM0_disableChannel(DMAMSPM0_Handle handle, uint8_t dmaChannel)
{
    uint32_t chMask                            = 1 << dmaChannel;
    /*Clear the channel interrupt */
    DL_DMA_clearInterruptStatus(DMA, ((uint32_t)(1 << dmaChannel)));
    DL_DMA_disableChannel(DMA, dmaChannel);
    chTransferSet &= ~chMask;

}

/*
* ============== Gets the current transfer size for a DMA channel================
*/
uint16_t DMAMSPM0_getCurrTransferSize(uint8_t dmaChannel)
{
    return (DL_DMA_getTransferSize(DMA, dmaChannel));
}

/*
 *  ======== DMAMSPM0_hwiFxn ========
 */
static void DMAMSPM0_hwiFxn(uintptr_t arg)
{
    uint8_t channelIndex;
    uint32_t dmaInterruptStatus;

    /* On each read, only one interrupt is indicated. On a read, the current
    * interrupt (highest priority) is automatically cleared by the hardware
    * and the corresponding interrupt flag in Section RIS and MIS
    * are cleared as well. After a read from the CPU ,
    * the register is updated with the next highest priority interrupt, if none are
    * pending, then it should display 0x0. */
    dmaInterruptStatus = (uint32_t) DL_DMA_getPendingInterrupt(DMA);

    while (dmaInterruptStatus > 0)
    {
        /* Find which channel caused the interrupt and call its ISR */
        for (channelIndex = 0; channelIndex < NUM_DMA_CHANNELS; channelIndex++)
        {
            if (dmaInterruptStatus == channelIndex)
            {
                DL_DMA_clearInterruptStatus(DMA, ((uint32_t)(1 << channelIndex)));
                if (hwiFxnHandlers[channelIndex])
                {
                    (*hwiFxnHandlers[channelIndex])(hwiFxnArgs[channelIndex]);
                    /*Once ISR is served, the transfer is done so clear the mask */
                    chTransferSet &= ~((uint32_t)(1 << channelIndex));
                }
            }
        }
        /* keep checking interrupt until all are served */
        dmaInterruptStatus = (uint32_t) DL_DMA_getPendingInterrupt(DMA);
    }
}

/*
 *  ======== DMA_Init ========
 *  This function expect dmaParams would be an array of pointers if multiple DMA channels are being configured
 */
DMAMSPM0_Handle DMA_Init(DMAMSPM0_Transfer* dmaParams, DL_DMA_Config* DMACfg, uint8_t noOfChs)
{
    uint8_t i = 0;
    DMAMSPM0_Handle dmaHandle;
    /* This init function will initialize the HWIP */
    DMAMSPM0_init();
    for(i = 0; i < noOfChs; i++)
    {
        /* Init with default params first */
        DMA_Params_init(&dmaParams[i]);
        /* Copy all User config DMA params to use for configuration */
        memcpy(&dmaParams[i], ((DMAMSPM0_Transfer*)DMAMSPM0_Config[0].object)+i, sizeof(DMAMSPM0_Transfer));

        /* channel specific interrupt configuration */
        dmaHandle = DMAMSPM0_open(i, dmaParams[i].dmaChannel);

        if (dmaHandle == NULL)
        {
            return NULL;
        }
        DMAMSPM0_copyDMAParams(&dmaParams[i], DMACfg);
        DL_DMA_initChannel(DMA, dmaParams[i].dmaChannel, DMACfg);
    }
    return dmaHandle;
}

/*
 *  ======== DMAMSPM0_hwiFxn ========
 *  This function will copy data from application struct to the DL struct
 */
void DMAMSPM0_copyDMAParams(DMAMSPM0_Transfer* dmaParams, DL_DMA_Config* dmaConfig)
{
    /* Default value for trigger and triggerType are from RX */
    dmaConfig->trigger     = dmaParams->rxTrigger;
    dmaConfig->triggerType = dmaParams->rxTriggerType;
    dmaConfig->extendedMode = dmaParams->extendedMode;
    dmaConfig->srcWidth    = dmaParams->srcWidth;
    dmaConfig->srcIncrement = dmaParams->srcIncrement;
    dmaConfig ->destWidth   = dmaParams->destWidth;
    dmaConfig->destIncrement = dmaParams->destIncrement;
    dmaConfig->transferMode = dmaParams->transferMode;
}
/* clang-format on */
