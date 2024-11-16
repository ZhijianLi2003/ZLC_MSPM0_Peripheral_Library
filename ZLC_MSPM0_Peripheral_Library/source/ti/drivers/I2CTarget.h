/*
 * Copyright (c) 2023-2024, Texas Instruments Incorporated
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
/*!*****************************************************************************
 *  @file       I2CTarget.h
 *
 *  @brief      I2CTarget driver interface
 *
 *  @defgroup   I2CTarget Inter-Integrated Circuit Target (I2CTarget)
 *
 *  To use the I2CTarget driver, ensure that the correct driver library for your
 *  device is linked in and include this header file as follows:
 *  @code
 *  #include <ti/drivers/I2CTarget.h>
 *  @endcode
 *
 *  @anchor ti_drivers_I2C_Target_Overview
 *  # Overview
 *
 *  The I2CTarget driver operates the I2C peripheral as a target on an I2C bus.
 *  The I2CTarget driver is event driven. When an  @ref I2CTarget_Event occurs,
 *  the I2CTarget driver will call a user-specified callback function
 *  (from HWI context). It is the user-specified callback's responsibility to
 *  process the @ref I2CTarget_Event events, and to manipulate and interperet
 *  the data. The manual ACK has been used. If automatic FIFO reception is desired
 *  disable the manual ACK using DL_I2C_disableTargetACKOverride().
 *
 *  <hr>
 *  @anchor ti_drivers_I2CTARGET_Usage
 *  # Usage
 *
 *  This documentation provides a basic @ref ti_drivers_I2CTARGET_Synopsis
 *  "usage summary" and a set of @ref ti_drivers_I2CTARGET_Examples "examples"
 *  in the form of commented code fragments.  Detailed descriptions of the
 *  APIs are provided in subsequent sections.
 *
 *  @anchor ti_drivers_I2CTARGET_Synopsis
 *  ## Synopsis
 *  @anchor ti_drivers_I2CTARGET_Synopsis_Code
 *  @code
 *  // Import the I2CTarget driver definitions
 *  #include <ti/drivers/I2CTarget.h>
 *
 *  // Define own I2C bus address
 *  #define OWN_ADDRESS     0x48
 *
 *  // Initialize I2CTarget driver
 *  I2CTarget_init();
 *
 *  // Initialize I2CTarget parameters
 *  I2CTarget_Params params;
 *  I2CTarget_Params_init(&params);
 *  params.eventCallbackFxn = myEventCallbackFunction;
 *  params.targetAddress = OWN_ADDRESS;
 *
 *  // Open the I2CTarget driver
 *  I2CTarget_Handle i2c;
 *  i2c = I2CTarget_open(CONFIG_I2C_TARGET_0, &params);
 *  if (i2c == NULL) {
 *      // Error opening I2CTarget
 *      while (1) {}
 *  }
 *
 *  // Start I2C Target operation. The driver will send
 *  // events to the user-specified event callback function
 *  I2CTarget_start(i2c);
 *
 *  // Transmitting and receiving bytes is handled by the
 *  // user-specified callback function. It is up to the user
 *  // to implement the appropriate state machine for its I2C
 *  // protocol.
 *
 *  // Stop operation. The I2CTarget driver will no longer trigger
 *  // events and the device can enter low-power modes.
 *  I2CTarget_stop(i2c);
 *
 *  // Close the I2CTarget driver
 *  I2CTarget_close(i2c);
 *  @endcode
 *
 *  <hr>
 *  @anchor ti_drivers_I2CTARGET_Examples
 *  # Examples
 *  @anchor ti_drivers_I2CTARGET_Example_open
 *  ## Opening the I2CTarget Driver
 *
 *  Opening a I2CTarget requires four steps:
 *  1.  Create and initialize a @ref I2CTarget_Params structure.
 *  2.  Fill in the desired parameters.
 *  3.  Call @ref I2CTarget_open(), passing the index of the I2C in the
 *      I2CTarget_config structure, and the address of the @ref I2CTarget_Params
 *      structure.  The I2C peripheral instance is specified by the index in
 *      the I2CTarget_config structure.
 *  4.  Check that the I2CTarget handle returned by @ref I2CTarget_open() is non-NULL,
 *      and save it.  The handle will be used to start and stop I2C Target operation
 *      of the I2C instance you just opened.
 *
 * @code
 *  I2CTarget_Handle i2c;
 *  I2CTarget_Params params;
 *  params.eventCallbackFxn = myEventCallbackFunction;
 *  params.targetAddress = 0x48;
 *
 *  i2c = I2CTarget_open(CONFIG_I2C_TARGET_0, NULL);
 *
 *  if (i2c == NULL) {
 *      // Error opening I2CTarget
 *      while (1) {}
 *  }
 * @endcode
 *
 *  Only one I2CTarget index can be used at a time; calling @ref I2CTarget_open() a
 *  second time with the same index previosly passed to @ref I2CTarget_open() will
 *  result in an error.  You can, though, re-use the index if the instance is closed
 *  via @ref I2CTarget_close().
 *  In the previous example code, CONFIG_I2C_TARGET_0 is passed to @ref I2CTarget_open().
 *  This macro is defined in the example's ti_drivers_config.h file.
 *
 *  @anchor ti_drivers_I2CTARGET_Example_start_stop_operation
 *  ## Start/Stop I2C Operation #
 *  The I2CTarget driver will start operation when calling @ref I2CTarget_start().
 *  It is the application's responsibility to process all incoming
 *  @ref I2CTarget_Event events in the @ref I2CTarget_Params.eventCallbackFxn and
 *  implement the necessary state machine for the I2C protocol used.
 *
 *  @code
 *  I2CTarget_start(i2cTargetHandle);
 *  @endcode
 *
 *  The I2CTarget driver operation is stopped by calling @ref I2CTarget_stop().
 *
 *  @code
 *  I2CTarget_stop(i2cTargetHandle);
 *  @endcode
 *
 *  @anchor ti_drivers_I2CTARGET_Example_receive_byte
 *  ## Transferring data
 *  This example shows a simplified example on how to transmit and receive data.
 *
 *  @code
 *  // No command input
 *  #define NO_COMMAND          0x00
 *  // Define command to reset value of txData
 *  #define CMD_RESET_TXDATA    0x55
 *
 *  // Variable storing data to transmit
 *  volatile uint8_t txData = 0;
 *
 *  // Variable storing command received from an I2C controller
 *  volatile uint8_t command = 0;
 *
 *  // User callback function
 *  int_fast16_t targetCallbackFxn(I2CTarget_Handle handle, I2CTarget_Event event, uint8_t *val) {
 *      if (event == I2CTarget_Event_WRITE_REQUESTED)
 *      {
 *          // Early event (before data is received) that the controller wants
 *          //  to write a byte to us (target-receiver).
 *          // This event may be used to set up receive buffers, or other
 *          // preparations.
 *      }
 *
 *      if (event == I2CTarget_Event_WRITE_RECEIVED) {
 *          // Controller has written a byte to the target (target-receiver)
 *          command = *data;
 *
 *          // Tell driver data has been read
 *          return I2CTarget_STATUS_SUCCESS;
 *      }
 *
 *      if (event  == I2CTarget_Event_READ_REQUESTED || event == I2CTarget_Event_READ_PROCESSED) {
 *          // Controller wants to read from target (target-transmitter)
 *          *data = txData++;
 *
 *          // Tell driver that data has been provided.
 *          return I2CTarget_STATUS_SUCCESS;
 *
 *          // If the user callback does not have data, return
 *          // I2CTarget_STATUS_ERROR and the I2CTarget driver will
 *          // NACK the request (if supported by the device-specific driver implementation).
 *      }
 *
 *      if (event == I2CTarget_Event_STOP) {
 *          // Stop condition received. Here we could, for example, reset
 *          // our I2C protocol state machine.
 *      }
 *
 *      // Return success by default
 *      return I2CTarget_STATUS_SUCCESS;
 * }
 *
 *  // Main thread
 *  void *mainThread(void *arg0) {
 *      // Call driver init functions
 *      I2CTarget_init();
 *
 *      // Open I2CTarget driver
 *      I2CTarget_Params params;
 *      I2CTarget_Params_init(&params);
 *      params.eventCallbackFxn = targetCallbackFxn;
 *      params.targetAddress = 0x48;
 *      I2CTarget_Handle handle = I2CTarget_open(CONFIG_I2C_TARGET_0, &params);
 *      if (handle == NULL) {
 *          // Error
 *          while (1) {}
 *      }
 *
 *      // Start operation
 *      I2CTarget_start(handle);
 *
 *      // Data transfers happens in targetCallbackFxn
 *      while (1) {
 *          if (command == CMD_RESET_TXDATA) {
 *              command = NO_COMMAND;
 *             txData = 0;
 *          }
 *      }
 *  }
 *  @endcode
 *
 *  <hr>
 *  @anchor ti_drivers_I2CTarget_Configuration
 *  # Configuration
 *
 *  Refer to the driver_configuration "Driver's Configuration" section
 *  for driver configuration information.
 *  <hr>
 *
 *  ============================================================================
 */
/** @addtogroup I2CTarget
* @{
*/
/* clang-format off */

#ifndef ti_drivers_I2CTARGET__include
#define ti_drivers_I2CTARGET__include

#ifdef __cplusplus
extern "C" {
#endif

/*! @cond */
#include <stdint.h>

#include <ti/drivers/dpl/HwiP.h>
#include <ti/drivers/dpl/SemaphoreP.h>
#include <ti/driverlib/dl_i2c.h>
/*! @endcond */

/**
 *  @defgroup I2C_TARGET_STATUS I2CTarget status codes
 *  These macros are reservations for I2CTarget.h.
 *  @{
 */

/*!
 * @brief    Successful status code returned by application event callback function.
 *
 * Status code returned from application's @ref I2CTarget_EventCallbackFxn on success.
 */
#define I2CTarget_STATUS_SUCCESS (0)

/*!
 * @brief    Generic error status code returned by application event callback function.
 *
 * Status code returned from @ref I2CTarget_EventCallbackFxn on error.
 */
#define I2CTarget_STATUS_ERROR (-1)
/** @} */
/*!
 * @brief    Default own address of the I2C Target.
 *
 */
#define I2C_TARGET_OWN_ADDRESS   (0x48)

/*!
 *  @brief      A handle that is returned from a I2CTarget_open() call.
 */
typedef struct I2CTarget_Config_ *I2CTarget_Handle;

/*!
 *  @brief      I2CTarget events that the application's
 *              @ref I2CTarget_EventCallbackFxn must support.
 */
typedef enum
{
    /*! The target has been addressed with a write (target-receiver).
     * The resulting @c val passed in is unused, the return value should always
     * be @ref I2CTarget_STATUS_SUCCESS.
     */
    I2CTarget_Event_WRITE_REQUESTED,

    /*! The target has been addressed with a read (target-transmitter).
     * The callback should fill the @c val parameter with the data byte, the
     * return value should always be @ref I2CTarget_STATUS_SUCCESS.
     */
    I2CTarget_Event_READ_REQUESTED,

    /*! The target has received a byte of data (target-receiver). The resulting
     * @c val parameter contains this data. The return should be
     * @ref I2CTarget_STATUS_SUCCESS if the byte should be ACKed, or
     * @ref I2CTarget_STATUS_ERROR if the byte should be NACKed.
     */
    I2CTarget_Event_WRITE_RECEIVED,

    /*! The target driver requests the next read byte (target-transmitter).
     * Note that this does not necessarily mean that the previous byte has been
     * ACKed, or that this next byte will actually be sent. This depends
     * entirely on if the controller sends an ACK for the previous byte. The
     * resulting @c val should be filled in with the next read data byte.
     * The return value should always be @ref I2CTarget_STATUS_SUCCESS.
     */
    I2CTarget_Event_READ_PROCESSED,

    /*! A stop condition was received.
     * The application should reset its state machine.
     */
    I2CTarget_Event_STOP
} I2CTarget_Event;

/*!
 *  @cond NODOC
 *  I2CTarget driver internal state.
 */
typedef enum
{
    I2CTarget_State_STOPPED, /* I2CTarget driver is not started. */
    I2CTarget_State_IDLE,    /* I2CTarget driver is started, no ongoing transactions */
    I2CTarget_State_RECEIVE, /* I2CTarget driver is receiving data */
    I2CTarget_State_TRANSMIT /* I2CTarget driver is transmitting */
} I2CTarget_State;
/*! @endcond */

/*!
 *  @brief  I2CTarget event callback function
 *
 *  User defined callback function that is called whenever an @ref I2CTarget_Event event
 *  occurs. The callback function must handle all the @ref I2CTarget_Event events.
 *
 *  @param[in]      handle  A I2CTarget_Handle returned from I2CTarget_open
 *
 *  @param[in]      event   The @ref I2CTarget_Event event causing the callback
 *
 *  @param[in,out]  val     Parameter containing the data byte
 *
 *  @return See @ref I2CTarget_Event
 */
typedef int_fast16_t (*I2CTarget_EventCallbackFxn)(I2CTarget_Handle handle, I2CTarget_Event event, uint8_t *val);

/*!
 *  @brief  I2CTarget Parameters
 *
 *  I2CTarget parameters are used to with the @ref I2CTarget_open() call. Default
 *  values for these parameters are set using @ref I2CTarget_Params_init().
 *
 *  @sa     I2CTarget_Params_init()
 */
typedef struct
{
    /*! Interrupt context event callback for the user */
    I2CTarget_EventCallbackFxn eventCallbackFxn;
    /*! Device's own address on the I2C bus */
    uint_least16_t targetAddress;
    /*! Custom argument used by driver implementation */
    void *custom;
} I2CTarget_Params;

/*! @cond NODOC */
#define I2CTARGET_BASE_OBJECT                                                              \
    /* I2CTarget control variables */                                                      \
    I2CTarget_EventCallbackFxn eventCallbackFxn; /* Callback function pointer */           \
    uint_least16_t targetAddress;                /* Device's own address on the I2C bus */ \
    I2CTarget_State currentState;                /* Internal state machine */              \
                                                                                           \
    /* I2CTarget RTOS objects */                                                           \
    HwiP_Struct hwi;         /* Hwi object handle */                                       \
    SemaphoreP_Struct mutex; /* Grants exclusive access to I2C module */                   \
                                                                                           \
    bool isOpen; /* Flag to show module is open */                                         \
/*! @endcond */

/*!
 *  @cond NODOC
 *  I2CTarget Object. Applications must not access any member variables of
 *  this structure!
 */
typedef struct
{
    I2CTARGET_BASE_OBJECT
} I2CTarget_Object;
/*! @endcond */

/*! @cond NODOC */
#define I2CTARGET_BASE_HWATTRS                                                    \
    /*! I2C Peripheral's instance */                                              \
    I2C_Regs *i2c;                                                                \
    /*! I2C Peripheral's interrupt vector */                                      \
    uint32_t intNum;                                                              \
    /*! I2C Peripheral's interrupt priority.                                    \
     *                                                                          \
     *  Note for MSPM0: The Arm Cortex-M0+ uses two of the priority bits,       \
     *  meaning ~0 has the same effect as (3 << 6).                             \
     *                                                                          \
     *  (3 << 6) will apply the lowest priority.                                \
     *  (1 << 6) will apply the highest priority.                               \
     *                                                                          \
     *  Setting the priority to 0 is not supported by the I2C driver.           \
     *                                                                          \
     *  Hwi's with priority 0 ignore the Hwi dispatcher to support zero-latency \
     *  interrupts, thus invalidating the critical sections in this driver.     \
     */ 																		\
    uint32_t intPriority;														\

/*! @endcond */

/*!
 *  @cond NODOC
 *  I2C HWAttrs.
 */
typedef struct
{
    I2CTARGET_BASE_HWATTRS
} I2CTarget_HWAttrs;
/*! @endcond */

/*!
 *  @brief  I2CTarget Global configuration
 *
 *  The I2CTarget_Config structure contains a set of pointers used to
 *  characterize the I2CTarget driver implementation.
 *
 *  This structure needs to be defined before calling I2CTarget_init() and it
 *  must not be changed thereafter.
 *
 *  @sa     I2CTarget_init()
 */
typedef struct I2CTarget_Config_
{
    /*! Pointer to a driver specific data object */
    void *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void const *hwAttrs;
} I2CTarget_Config;

/*! I2CTarget config structure */
extern const I2CTarget_Config I2CTarget_config[];
/*! I2CTarget count */
extern const uint_least8_t I2CTarget_count;

/*!
 *  @brief  Function to initializes the I2CTarget module
 *
 *  @pre    The I2CTarget_config structure must exist and be persistent before
 *          this function can be called. This function must also be called
 *          before any other I2CTarget driver APIs. This function call does not
 *          modify any peripheral registers.
 */
extern void I2CTarget_init(void);

/*!
 *  @brief  Function to initialize the I2CTarget_Params struct to its defaults
 *
 *  @param  params      An pointer to I2CTarget_Params structure for
 *                      initialization
 *
 *  Defaults values are:
 *      eventCallbackFxn = NULL
 *      targetAddress = 0x48
 */
extern void I2CTarget_Params_init(I2CTarget_Params *params);

/*!
 *  @brief  Function to initialize a given I2C target peripheral specified by the
 *          particular index value. The parameter specifies which mode the
 *          I2CTarget will operate.
 *
 *  @pre    @ref I2CTarget_init() has to be called first.
 *
 *  @param  index       Logical peripheral number for the I2CTarget indexed
 *                      into the I2CTarget_config table
 *
 *  @param  params      Pointer to a parameter block, if NULL it will use
 *                      default values. All the fields in this structure are
 *                      RO (read-only).
 *
 *  @return A I2CTarget_Handle on success or a NULL on an error or if it has been
 *          opened already.
 *
 *  @sa     I2CTarget_init()
 *  @sa     I2CTarget_start()
 *  @sa     I2CTarget_stop()
 *  @sa     I2CTarget_close()
 */
extern I2CTarget_Handle I2CTarget_open(uint_least8_t index, I2CTarget_Params *params);

/*!
 *  @brief  Start I2CTarget driver listening on I2C bus.
 *
 *  @param  handle  A @ref I2CTarget_Handle returned from I2CTarget_open
 *
 *  @sa     I2CTarget_stop()
 */
extern void I2CTarget_start(I2CTarget_Handle handle);

/*!
 *  @brief  Stop I2CTarget driver from listening on I2C bus.
 *
 *  @param  handle  A I2CTarget_Handle returned from I2CTarget_open
 *
 *  @sa     I2CTarget_start()
 */
extern void I2CTarget_stop(I2CTarget_Handle handle);

/*!
 *
 *  After calling the close function, the I2C is disabled.
 *
 *  @pre    I2CTarget_open() has to be called first.
 *
 *  @param  handle  A @ref I2CTarget_Handle returned from I2CTarget_open
 *
 *  @sa     I2CTarget_open(), I2CTarget_start(), I2CTarget_stop()
 */
extern void I2CTarget_close(I2CTarget_Handle handle);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_I2CTARGET__include */
/* clang-format on */
/** @}*/
