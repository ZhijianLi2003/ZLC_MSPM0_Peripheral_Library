/*
 * Copyright (c) 2022-2023, Texas Instruments Incorporated
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
 *  @file       I2CMSPM0.h
 *
 *  @brief      I2C driver implementation for a MSPM0 I2C controller.
 *
 *  @defgroup   I2CMSPM0 I2C driver APIs
 *
 *  # Overview
 *  Refer to @ref ti_drivers_I2C_Overview for a complete description of APIs and examples
 *  of use.
 *
 *  The general I2C API is normally used in application code, e.g. I2C_open()
 *  is used instead of I2CMSPM0_open(). The board file will define the device
 *  specific config, and casting in the general API will ensure that the correct
 *  device specific functions are called.
 *
 *  ## General Behavior #
 *  Before using the I2C:
 *   - The I2C driver is initialized by calling I2C_init().
 *   - The I2C HW is configured and system dependencies are declared (e.g. IOs,
 *     power, etc.) by calling I2C_open().
 *   .
 *  The following is true for receive operation:
 *   - RX is enabled by calling I2C_transfer().
 *     The readCount of the ::I2C_Transaction must be set to a non-zero value.
 *   - If the I2C_transfer() succeeds, the I2C remains enabled.
 *   - The application must check the return value from I2C_transfer()
 *     to verify that the transfer succeeded.
 *   .
 *  The following apply for transmit operation:
 *   - TX is enabled by calling I2C_transfer().
 *     The writeCount of the ::I2C_Transaction must be set to a non-zero value.
 *   - If the I2C_transfer() succeeds, the I2C remains enabled.
 *   - The application must check the return value from I2C_transfer()
 *     to verify that the transfer succeeded.
 *   .
 *  After I2C operation has ended:
 *   - Release system dependencies for I2C by calling I2C_close().
 *
 *  ## Error handling #
 *  If an error occurs during operation:
 *   - The I2C Controller transmits a stop bit and remains enabled.
 *
 *  ## Power Management #
 *  The I2C driver sets a power constraint during transactions to keep
 *  the device out of standby; so when all tasks are blocked, the device will
 *  enter idle mode instead of standby.  When the transactions have finished,
 *  the power constraint to prohibit standby is released.
 *  The following statements are valid:
 *    - After I2C_open() call: I2C is enabled, there are no active I2C
 *      transactions, the device can enter standby.
 *    - After I2C_transfer() call: active I2C transactions exist, the device
 *      might enter idle, but not standby.
 *    - When I2C_transfer() completes, either after success or error, I2C
 *      remains enabled, and the device can enter standby.
 *    - After I2C_close() call: I2C is disabled
 *    - If the device goes into idle during a transaction, the state of
 *      SDA is undefined in the time between the transaction completing and
 *      the device waking up. SCL will go low until the device wakes up and
 *      starts another transaction or releases the bus. If this is a problem
 *      for another device on the I2C bus, you can set a power constraint for
 *      PowerMSPM0_DISALLOW_IDLE before the transaction and release it
 *      when the transaction completes.
 *
 *  ## Supported Functions ##
 *  | Generic API Function | API Function              | Description                                       |
 *  |--------------------- |---------------------------|---------------------------------------------------|
 *  | I2C_init()           | I2CMSPM0_initHw()         | Initialize I2C driver                             |
 *  | I2C_open()           | I2C_open()                | Initialize I2C HW and set system dependencies     |
 *  | I2C_close()          | I2C_close()               | Disable I2C HW and release system dependencies    |
 *  | I2C_transfer()       | I2CSupport_primeTransfer()| Start I2C transfer                                |
 *
 *  @note All calls should go through the generic API.
 *
 *  ## Supported Bit Rates ##
 *    - #I2C_100kHz
 *    - #I2C_400kHz
 *    - #I2C_1000kHz
 *  ## Unsupported Functionality #
 *  The I2C driver currently does not support:
 *    - Multi-controller mode
 *    - I2C target mode
 *
 *  ## Use Cases @anchor I2C_USE_CASES ##
 *  ### Basic Receive #
 *  Receive 10 bytes over I2C in ::I2C_MODE_BLOCKING.
 *  @code
 *  // Locals
 *  I2C_Handle handle;
 *  I2C_Params params;
 *  I2C_Transaction i2cTrans;
 *  uint8_t rxBuf[32];      // Receive buffer
 *  uint8_t txBuf[32];      // Transmit buffer
 *
 *  // Configure I2C parameters.
 *  I2C_Params_init(&params);
 *
 *  // Initialize I2C transaction structure
 *  i2cTrans.writeCount    = 0;
 *  i2cTrans.writeBuf      = txBuf;
 *  i2cTrans.readCount     = 10;
 *  i2cTrans.readBuf       = rxBuf;
 *  i2cTrans.targetAddress = 0x3C;
 *
 *  // Open I2C
 *  handle = I2C_open(CONFIG_I2C, &params);
 *
 *  // Do I2C transfer receive
 *  I2C_transfer(handle, &i2cTrans);
 *  @endcode
 *
 *  ### Basic Transmit #
 *  Transmit 16 bytes over I2C in ::I2C_MODE_CALLBACK.
 *  @code
 *  uint8_t rxBuffer[32];            // Receive buffer
 *  uint8_t txBuffer[32];            // Transmit buffer
 *  bool transferDone = false;
 *
 *  static void transferCallback(I2C_Handle handle, I2C_Transaction *transac, bool result)
 *  {
 *      // Set length bytes
 *      if (result) {
 *          transferDone = true;
 *      } else {
 *          // Transaction failed, act accordingly...
 *          .
 *          .
 *      }
 *  }
 *
 *  static void taskFxn(uintptr_t a0, uintptr_t a1)
 *  {
 *      // Locals
 *      I2C_Handle handle;
 *      I2C_Params params;
 *      I2C_Transaction i2cTrans;
 *
 *      // Configure I2C parameters.
 *      I2C_Params_init(&params);
 *      params.transferMode = I2C_MODE_CALLBACK;
 *      params.transferCallbackFxn = transferCallback;
 *
 *      // Prepare data to send, send 0x00, 0x01, 0x02, ...0xFF, 0x00, 0x01...
 *      for(uint32_t i = 0; i < numTxBytes; i++)
 *          txBuffer[i] = (uint8_t) i;
 *
 *      // Initialize I2C transaction structure
 *      i2cTrans.writeCount    = 16;
 *      i2cTrans.writeBuf      = txBuffer;
 *      i2cTrans.readCount     = 0;
 *      i2cTrans.readBuf       = rxBuffer;
 *      i2cTrans.targetAddress = 0x3C;
 *
 *      // Open I2C
 *      handle = I2C_open(CONFIG_I2C, &params);
 *
 *      // Do I2C transfer (in callback mode)
 *      I2C_transfer(handle, &i2cTrans);
 *
 *      // Do other stuff while I2C is handling the transfer.
 *      .
 *      .
 *
 *      // Do something if I2C transfer is finished.
 *      if(transferDone) {
 *          .
 *          .
 *      }
 *
 *      // Continue...
 *      .
 *      .
 *  }
 *  @endcode
 *
 *  ### Chained Transactions #
 *  Transmit 10 bytes and then 32 bytes over I2C in ::I2C_MODE_CALLBACK.
 *  @code
 *  uint8_t rxBuffer[32];            // Receive buffer
 *  uint8_t txBuffer[32];            // Transmit buffer
 *  uint8_t rxBuffer2[64];           // Receive buffer 2
 *  uint8_t txBuffer2[64];           // Transmit buffer 2
 *  bool transferDone = false;
 *
 *  static void writeCallbackDefault(I2C_Handle handle, I2C_Transaction *transac, bool result)
 *  {
 *      // Set length bytes
 *      if (result) {
 *          transferDone = true;
 *      } else {
 *          // Transaction failed, act accordingly...
 *          .
 *          .
 *      }
 *  }
 *
 *  static void taskFxn(uintptr_t a0, uintptr_t a1)
 *  {
 *      // Locals
 *      I2C_Handle handle;
 *      I2C_Params params;
 *      I2C_Transaction i2cTrans;
 *      I2C_Transaction i2cTrans2;
 *
 *      // Configure I2C parameters.
 *      I2C_Params_init(&params);
 *      params.transferMode = I2C_MODE_CALLBACK;
 *      params.transferCallbackFxn = writeCallbackDefault;
 *
 *      // Prepare data to send, send 0x00, 0x01, 0x02, ...0xFF, 0x00, 0x01...
 *      for(uint32_t i = 0; i < numTxBytes; i++)
 *          txBuffer[i] = (uint8_t) i;
 *
 *      // Initialize first I2C transaction structure
 *      i2cTrans.writeCount    = 10;
 *      i2cTrans.writeBuf      = txBuffer;
 *      i2cTrans.readCount     = 0;
 *      i2cTrans.readBuf       = rxBuffer;
 *      i2cTrans.targetAddress = 0x3C;
 *
 *      // Second transaction
 *      i2cTrans2.writeCount    = 32;
 *      i2cTrans2.writeBuf      = txBuffer2;
 *      i2cTrans2.readCount     = 0;
 *      i2cTrans2.readBuf       = rxBuffer2;
 *      i2cTrans2.targetAddress = 0x2E;
 *
 *      // Open I2C
 *      handle = I2C_open(CONFIG_I2C, &params);
 *
 *      // Do chained I2C transfers (in callback mode).
 *      I2C_transfer(handle, &i2cTrans);
 *      I2C_transfer(handle, &i2cTrans2);
 *
 *      // Do other stuff while I2C is handling the transfers.
 *      .
 *      .
 *
 *      // Do something if I2C transfers are finished.
 *      if(transferDone) {
 *          .
 *          .
 *      }
 *
 *      // Continue...
 *      .
 *      .
 *  }
 *  @endcode
 *
 *  # Instrumentation #
 *  The I2C driver interface produces log statements if instrumentation is
 *  enabled.
 *
 *  Diagnostics Mask | Log details |
 *  ---------------- | ----------- |
 *  Diags_USER1      | basic I2C operations performed |
 *  Diags_USER2      | detailed I2C operations performed |
 *
 ******************************************************************************
 */
/** @addtogroup I2CMSPM0
 *  @ingroup I2C
* @{
*/
#ifndef ti_drivers_I2CMSPM0_include
#define ti_drivers_I2CMSPM0_include

#include <stdbool.h>
#include <stdint.h>

#include <ti/drivers/I2C.h>
#include <ti/drivers/i2c/I2CSupport.h>

#ifdef POWER_MANAGEMENT_MSPM0
#include <ti/drivers/Power.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  @brief I2C controller interrupt mask.
 */
#define I2C_CONTROLLER_INTERRUPTS_MASK 0xFFFF

/*!
 *  @brief  I2C Pin Configuration
 *
 *  Pin configuration that holds non-default pins. The default pin configuration
 *  is typically defined in @ref I2CMSPM0_HWAttrs placed in the board file.
 *  The pin configuration structure is used by setting the custom void
 *  pointer in the ::I2C_Params to point to this struct. If the custom
 *  void pointer is NULL, the ::I2CMSPM0_HWAttrs pin mapping will be used.
 *  @code
 *  I2C_Handle handle;
 *  I2C_Params i2cParams;
 *  I2CMSPM0_I2CPinCfg pinCfg;
 *
 *  I2C_Params_init(&i2cParams);     // sets custom to NULL.
 *  pinCfg.pinSDA = CONFIG_I2C0_SDA1;
 *  pinCfg.pinSCL = CONFIG_I2C0_SCL1;
 *  i2cParams.custom = &pinCfg; //set to NULL if values in I2CMSPM0_HWAttrs to be used.
 *
 *  handle = I2C_open(CONFIG_I2C, &i2cParams);
 *  @endcode
 */
typedef struct {
    uint8_t pinSDA; /*!< SDA Pincm value */
    uint8_t pinSCL; /*!< SCL Pincm value */
} I2CMSPM0_I2CPinCfg;

/*!
 *  @brief  I2C Hardware attributes
 *
 *  The i2c and intNum fields define the base address and the interrupt
 *  number of the I2C peripheral.  These values are passed to driverlib APIs
 *  and therefore must be populated by driverlib macro definitions.
 *
 *  The powerMngrId is the Power driver resource ID for the I2C peripheral.
 *  These macros are defined in PowerMSP.h

 *  intPriority is the I2C peripheral's interrupt priority, This value is passed
 *  unmodified to Hwi_create().
 *
 *  sdaPinMux and sclPinMux are values drawn from the GPIO driver. They indicate
 *  the function for that specific IO pin that select I2C mode.
 *
 *  A sample structure is shown below:
 *  @code
 *  const I2CMSPM0_HWAttrs I2CHWAttrs[CONFIG_I2C_COUNT] = {
 *      {
 *          .i2c                      = I2C_INST,
 *          .intNum                   = I2C_INST_INT_IRQN,
 *          .intPriority              = (~0),
 *          .sdaPin                   = GPIO_I2C_IOMUX_SDA,
 *          .sdaPinIndex              = GPIO_I2C_SDA_PIN,
 *          .sdaPinMux                = GPIO_I2C_IOMUX_SDA_FUNC,
 *          .sclPin                   = GPIO_I2C_IOMUX_SCL,
 *          .sclPinIndex              = GPIO_I2C_SCL_PIN,
 *          .sclPinMux                = GPIO_I2C_IOMUX_SCL_FUNC,
 *          .clockSource              = DL_I2C_CLOCK_BUSCLK,
 *          .clockDivider             = DL_I2C_CLOCK_DIVIDE_1,
 *          .txIntFifoThr             = DL_I2C_TX_FIFO_LEVEL_BYTES_1,
 *          .rxIntFifoThr             = DL_I2C_RX_FIFO_LEVEL_BYTES_1,
 *          .isClockStretchingEnabled = true,
 *          .i2cClk                   = I2C_CLOCK_MHZ,
 *      },
 *  };
 *  @endcode
 */
typedef struct {
    I2C_BASE_HWATTRS /*!< I2C base hardware attributes */

        /* SDA pin PINCM index and mux */
        uint8_t sdaPincm; /*!< SDA Pincm value */
    uint8_t sdaPinIndex;  /*!< SDA pin index */
    uint32_t sdaPinMux;   /*!< SDA pin function */
    /* SCL pin PINCM index and mux */
    uint8_t sclPincm;    /*!< SCL Pincm value */
    uint8_t sclPinIndex; /*!< SCL pin index */
    uint32_t sclPinMux;  /*!< SCL pin function */

    DL_I2C_CLOCK clockSource; /*!< I2C clock source */
    DL_I2C_CLOCK_DIVIDE
    clockDivider; /*!< I2C clock divider to get the required bps */
    DL_I2C_RX_FIFO_LEVEL
    rxIntFifoThr; /*!< I2C receive FIFO interrupt threshold */
    DL_I2C_TX_FIFO_LEVEL
    txIntFifoThr; /*!< I2C transmit FIFO interrupt threshold */
    bool isClockStretchingEnabled; /*!< Clock stretching enable/disable flag */
    uint16_t i2cClk;               /*!< The clock must be in MHz */
} I2CMSPM0_HWAttrs;

/*!
 *  @brief      I2C Object.
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct {
    I2C_BASE_OBJECT /*!< I2C object parameters */

        uint16_t burstCount; /*!< Number of bytes are being sent in a burst */
    bool burstStarted;       /*!< Burst started status flag */
    uint32_t bitRate;        /*!< Bitrate of the I2C module */
    /* Pincm: We need to cache these because we might have custom pins */
    uint8_t sdaPincm; /*!< SDA Pincm Value */
    uint8_t sclPincm; /*!< SCL Pincm Value */

    void *i2cPostFxn; /*!< I2C power notification */
    bool
        isReadInProgress; /*!< Flag to check if read is done before issuing another read */

#ifdef POWER_MANAGEMENT_MSPM0
    Power_NotifyObj i2cPostObj; /*!< Not supported yet */
#endif
} I2CMSPM0_Object;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_I2CMSPM0_include */
/** @}*/
