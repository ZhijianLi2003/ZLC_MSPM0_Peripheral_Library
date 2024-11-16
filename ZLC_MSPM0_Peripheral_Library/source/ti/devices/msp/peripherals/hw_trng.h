/*****************************************************************************

  Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

   Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the
   distribution.

   Neither the name of Texas Instruments Incorporated nor the names of
   its contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*****************************************************************************/

#ifndef ti_devices_msp_peripherals_hw_trng__include
#define ti_devices_msp_peripherals_hw_trng__include

/* Filename: hw_trng.h */
/* Revised: 2023-06-13 16:12:38 */
/* Revision: f9b237fa1b82e8166ce3ead25b505b784578352a */

#ifndef __CORTEX_M
  #ifdef __cplusplus
    #define __I  volatile        /*!< Defines 'read only' permissions */
  #else
    #define __I  volatile const  /*!< Defines 'read only' permissions */
  #endif
  #define __O  volatile          /*!< Defines 'write only' permissions */
  #define __IO  volatile         /*!< Defines 'read / write' permissions */

  /* following defines should be used for structure members */
  #define __IM  volatile const   /*! Defines 'read only' structure member permissions */
  #define __OM  volatile         /*! Defines 'write only' structure member permissions */
  #define __IOM  volatile        /*! Defines 'read / write' structure member permissions */
#endif

/* Use standard integer types with explicit width */
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

#if defined ( __CC_ARM )
#pragma anon_unions
#endif

/******************************************************************************
* TRNG Registers
******************************************************************************/
#define TRNG_CPU_INT_OFS                         ((uint32_t)0x00001020U)
#define TRNG_GPRCM_OFS                           ((uint32_t)0x00000800U)


/** @addtogroup TRNG_CPU_INT
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001020) Interrupt index */
       uint32_t RESERVED0;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001028) Interrupt mask */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x00001030) Raw interrupt status */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x00001038) Masked interrupt status */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x00001040) Interrupt set */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x00001048) Interrupt clear */
} TRNG_CPU_INT_Regs;

/*@}*/ /* end of group TRNG_CPU_INT */

/** @addtogroup TRNG_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} TRNG_GPRCM_Regs;

/*@}*/ /* end of group TRNG_GPRCM */

/** @addtogroup TRNG
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  TRNG_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED1[514];
  TRNG_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED2[44];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module descriptions */
  __IO uint32_t CTL;                               /* !< (@ 0x00001100) Controls the command and decimation rate */
  __I  uint32_t STAT;                              /* !< (@ 0x00001104) Status register that informs health test results
                                                      and last issued command */
  __I  uint32_t DATA_CAPTURE;                      /* !< (@ 0x00001108) Captured word buffer of RNG data */
  __I  uint32_t TEST_RESULTS;                      /* !< (@ 0x0000110C) Test results from TEST_ANA and TEST_DIG */
  __IO uint32_t CLKDIVIDE;                         /* !< (@ 0x00001110) Clock Divider */
} TRNG_Regs;

/*@}*/ /* end of group TRNG */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* TRNG Register Control Bits
******************************************************************************/

/* TRNG_IIDX Bits */
/* TRNG_IIDX[STAT] Bits */
#define TRNG_IIDX_STAT_OFS                       (0)                             /* !< STAT Offset */
#define TRNG_IIDX_STAT_MASK                      ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define TRNG_IIDX_STAT_NO_INTR                   ((uint32_t)0x00000000U)         /* !< No bit is set means there is no
                                                                                    pending interrupt request */
#define TRNG_IIDX_STAT_IRQ_HEALTH_FAIL           ((uint32_t)0x00000001U)         /* !< Indicates that a health test has
                                                                                    failed. The TRNG is in an error state
                                                                                    until the interrupt is cleared. */
#define TRNG_IIDX_STAT_IRQ_CMD_FAIL              ((uint32_t)0x00000002U)         /* !< Indicates that the just issued
                                                                                    command was rejected and is not being
                                                                                    performed. */
#define TRNG_IIDX_STAT_IRQ_CMD_DONE              ((uint32_t)0x00000003U)         /* !< Indicates that the current
                                                                                    command/mode is done. This may have
                                                                                    different meanings based on the mode:
                                                                                    OFF --> Power has been turned off
                                                                                    PWRUP_DIG --> Digital powerup tests
                                                                                    are done PWRUP_ANA --> Analog powerup
                                                                                    tests are done NORM_FUNC --> No IRQ,
                                                                                    since mode runs indefinitely until a
                                                                                    new command is issued */
#define TRNG_IIDX_STAT_IRQ_CAPTURED_RDY          ((uint32_t)0x00000004U)         /* !< Indicates that the captured word
                                                                                    buffer is ready to be copied to
                                                                                    memory */

/* TRNG_IMASK Bits */
/* TRNG_IMASK[IRQ_HEALTH_FAIL] Bits */
#define TRNG_IMASK_IRQ_HEALTH_FAIL_OFS           (0)                             /* !< IRQ_HEALTH_FAIL Offset */
#define TRNG_IMASK_IRQ_HEALTH_FAIL_MASK          ((uint32_t)0x00000001U)         /* !< Mask for IRQ_HEALTH_FAIL. Indicates
                                                                                    that a health test has failed. */
#define TRNG_IMASK_IRQ_HEALTH_FAIL_DISABLED      ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define TRNG_IMASK_IRQ_HEALTH_FAIL_ENABLED       ((uint32_t)0x00000001U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* TRNG_IMASK[IRQ_CAPTURED_RDY] Bits */
#define TRNG_IMASK_IRQ_CAPTURED_RDY_OFS          (3)                             /* !< IRQ_CAPTURED_RDY Offset */
#define TRNG_IMASK_IRQ_CAPTURED_RDY_MASK         ((uint32_t)0x00000008U)         /* !< Mask for IRQ_CAPTURED_RDY.
                                                                                    Indicates to the CPU that the
                                                                                    Captured Word is ready to be read. */
#define TRNG_IMASK_IRQ_CAPTURED_RDY_DISABLED     ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define TRNG_IMASK_IRQ_CAPTURED_RDY_ENABLED      ((uint32_t)0x00000008U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* TRNG_IMASK[IRQ_CMD_DONE] Bits */
#define TRNG_IMASK_IRQ_CMD_DONE_OFS              (2)                             /* !< IRQ_CMD_DONE Offset */
#define TRNG_IMASK_IRQ_CMD_DONE_MASK             ((uint32_t)0x00000004U)         /* !< Mask for IRQ_CMD_DONE. Indicates
                                                                                    that a command has finished */
#define TRNG_IMASK_IRQ_CMD_DONE_DISABLED         ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define TRNG_IMASK_IRQ_CMD_DONE_ENABLED          ((uint32_t)0x00000004U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* TRNG_IMASK[IRQ_CMD_FAIL] Bits */
#define TRNG_IMASK_IRQ_CMD_FAIL_OFS              (1)                             /* !< IRQ_CMD_FAIL Offset */
#define TRNG_IMASK_IRQ_CMD_FAIL_MASK             ((uint32_t)0x00000002U)         /* !< Masked interrupt source for
                                                                                    IRQ_CMD_FAIL. Indicates that the just
                                                                                    issued command/mode has been
                                                                                    rejected. */
#define TRNG_IMASK_IRQ_CMD_FAIL_DISABLED         ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define TRNG_IMASK_IRQ_CMD_FAIL_ENABLED          ((uint32_t)0x00000002U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */

/* TRNG_RIS Bits */
/* TRNG_RIS[IRQ_CAPTURED_RDY] Bits */
#define TRNG_RIS_IRQ_CAPTURED_RDY_OFS            (3)                             /* !< IRQ_CAPTURED_RDY Offset */
#define TRNG_RIS_IRQ_CAPTURED_RDY_MASK           ((uint32_t)0x00000008U)         /* !< Indicates to the CPU that the
                                                                                    Captured Word is ready to be read.
                                                                                    Reading the IIDX will clear this
                                                                                    interrupt. */
#define TRNG_RIS_IRQ_CAPTURED_RDY_CLR            ((uint32_t)0x00000000U)         /* !< IRQ_CAPTURED_READY did not occur */
#define TRNG_RIS_IRQ_CAPTURED_RDY_SET            ((uint32_t)0x00000008U)         /* !< IRQ_CAPTURED_READY occurred */
/* TRNG_RIS[IRQ_HEALTH_FAIL] Bits */
#define TRNG_RIS_IRQ_HEALTH_FAIL_OFS             (0)                             /* !< IRQ_HEALTH_FAIL Offset */
#define TRNG_RIS_IRQ_HEALTH_FAIL_MASK            ((uint32_t)0x00000001U)         /* !< Indicates to the CPU that any of
                                                                                    the health tests have failed. Reading
                                                                                    the IIDX  will clear this interrupt. */
#define TRNG_RIS_IRQ_HEALTH_FAIL_CLR             ((uint32_t)0x00000000U)         /* !< IRQ_CAPTURED_READY did not occur */
#define TRNG_RIS_IRQ_HEALTH_FAIL_SET             ((uint32_t)0x00000001U)         /* !< IRQ_CAPTURED_READY occurred */
/* TRNG_RIS[IRQ_CMD_DONE] Bits */
#define TRNG_RIS_IRQ_CMD_DONE_OFS                (2)                             /* !< IRQ_CMD_DONE Offset */
#define TRNG_RIS_IRQ_CMD_DONE_MASK               ((uint32_t)0x00000004U)         /* !< Raw interrupt source for
                                                                                    IRQ_CMD_DONE. Indicates that the
                                                                                    issued command/mode has completed. */
#define TRNG_RIS_IRQ_CMD_DONE_CLR                ((uint32_t)0x00000000U)         /* !< IRQ_CMD_DONE did not occur */
#define TRNG_RIS_IRQ_CMD_DONE_SET                ((uint32_t)0x00000004U)         /* !< IRQ_CMD_DONE occurred */
/* TRNG_RIS[IRQ_CMD_FAIL] Bits */
#define TRNG_RIS_IRQ_CMD_FAIL_OFS                (1)                             /* !< IRQ_CMD_FAIL Offset */
#define TRNG_RIS_IRQ_CMD_FAIL_MASK               ((uint32_t)0x00000002U)         /* !< Masked interrupt source for
                                                                                    IRQ_CMD_FAIL. Indicates that the just
                                                                                    issued command/mode has been
                                                                                    rejected. */
#define TRNG_RIS_IRQ_CMD_FAIL_CLR                ((uint32_t)0x00000000U)         /* !< IRQ_CMD_FAIL did not occur */
#define TRNG_RIS_IRQ_CMD_FAIL_SET                ((uint32_t)0x00000002U)         /* !< IRQ_CMD_FAIL occurred */

/* TRNG_MIS Bits */
/* TRNG_MIS[IRQ_CAPTURED_RDY] Bits */
#define TRNG_MIS_IRQ_CAPTURED_RDY_OFS            (3)                             /* !< IRQ_CAPTURED_RDY Offset */
#define TRNG_MIS_IRQ_CAPTURED_RDY_MASK           ((uint32_t)0x00000008U)         /* !< Masked interrupt result for
                                                                                    CAPTURED_READY. Indicates to the CPU
                                                                                    that the Captured Word is ready to be
                                                                                    read. Reading the IIDX  will clear
                                                                                    this interrupt. */
#define TRNG_MIS_IRQ_CAPTURED_RDY_CLR            ((uint32_t)0x00000000U)         /* !< IRQ_CAPTURED_READY did not request
                                                                                    an interrupt service routine */
#define TRNG_MIS_IRQ_CAPTURED_RDY_SET            ((uint32_t)0x00000008U)         /* !< IRQ_CAPTURED_READY requests an
                                                                                    interrupt service routine */
/* TRNG_MIS[IRQ_HEALTH_FAIL] Bits */
#define TRNG_MIS_IRQ_HEALTH_FAIL_OFS             (0)                             /* !< IRQ_HEALTH_FAIL Offset */
#define TRNG_MIS_IRQ_HEALTH_FAIL_MASK            ((uint32_t)0x00000001U)         /* !< Masked interrupt result for
                                                                                    HEALTH_FAIL. Indicates to the CPU
                                                                                    that any of the health tests have
                                                                                    failed for the latest 1024-bit
                                                                                    window. */
#define TRNG_MIS_IRQ_HEALTH_FAIL_CLR             ((uint32_t)0x00000000U)         /* !< IRQ_CAPTURED_READY did not request
                                                                                    an interrupt service routine */
#define TRNG_MIS_IRQ_HEALTH_FAIL_SET             ((uint32_t)0x00000001U)         /* !< IRQ_CAPTURED_READY requests an
                                                                                    interrupt service routine */
/* TRNG_MIS[IRQ_CMD_DONE] Bits */
#define TRNG_MIS_IRQ_CMD_DONE_OFS                (2)                             /* !< IRQ_CMD_DONE Offset */
#define TRNG_MIS_IRQ_CMD_DONE_MASK               ((uint32_t)0x00000004U)         /* !< Masked interrupt source for
                                                                                    IRQ_CMD_DONE. Indicates that the
                                                                                    issued command/mode has completed. */
#define TRNG_MIS_IRQ_CMD_DONE_CLR                ((uint32_t)0x00000000U)         /* !< IRQ_CAPTURED_READY did not request
                                                                                    an interrupt service routine */
#define TRNG_MIS_IRQ_CMD_DONE_SET                ((uint32_t)0x00000004U)         /* !< IRQ_CMD_DONE requests an interrupt
                                                                                    service routine */
/* TRNG_MIS[IRQ_CMD_FAIL] Bits */
#define TRNG_MIS_IRQ_CMD_FAIL_OFS                (1)                             /* !< IRQ_CMD_FAIL Offset */
#define TRNG_MIS_IRQ_CMD_FAIL_MASK               ((uint32_t)0x00000002U)         /* !< Masked interrupt source for
                                                                                    IRQ_CMD_FAIL. Indicates that the just
                                                                                    issued command/mode has been
                                                                                    rejected. */
#define TRNG_MIS_IRQ_CMD_FAIL_CLR                ((uint32_t)0x00000000U)         /* !< IRQ_CMD_FAIL did not request an
                                                                                    interrupt service routine */
#define TRNG_MIS_IRQ_CMD_FAIL_SET                ((uint32_t)0x00000002U)         /* !< IRQ_CMD_FAIL requests an interrupt
                                                                                    service routine */

/* TRNG_ISET Bits */
/* TRNG_ISET[IRQ_CAPTURED_RDY] Bits */
#define TRNG_ISET_IRQ_CAPTURED_RDY_OFS           (3)                             /* !< IRQ_CAPTURED_RDY Offset */
#define TRNG_ISET_IRQ_CAPTURED_RDY_MASK          ((uint32_t)0x00000008U)         /* !< Indicates to the CPU that the
                                                                                    Captured Word is ready to be read.
                                                                                    Reading the IIDX or DATA_CAPTURE
                                                                                    registers will clear this interrupt. */
#define TRNG_ISET_IRQ_CAPTURED_RDY_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define TRNG_ISET_IRQ_CAPTURED_RDY_SET           ((uint32_t)0x00000008U)         /* !< RIS bit corresponding to
                                                                                    CAPTURED_READY is set */
/* TRNG_ISET[IRQ_HEALTH_FAIL] Bits */
#define TRNG_ISET_IRQ_HEALTH_FAIL_OFS            (0)                             /* !< IRQ_HEALTH_FAIL Offset */
#define TRNG_ISET_IRQ_HEALTH_FAIL_MASK           ((uint32_t)0x00000001U)         /* !< Indicates to the CPU that any of
                                                                                    the health tests have failed. Reading
                                                                                    the IIDX or DATA_CAPTURE registers
                                                                                    will clear this interrupt. */
#define TRNG_ISET_IRQ_HEALTH_FAIL_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define TRNG_ISET_IRQ_HEALTH_FAIL_SET            ((uint32_t)0x00000001U)         /* !< RIS bit corresponding to
                                                                                    HEALTH_FAIL is set */
/* TRNG_ISET[IRQ_CMD_DONE] Bits */
#define TRNG_ISET_IRQ_CMD_DONE_OFS               (2)                             /* !< IRQ_CMD_DONE Offset */
#define TRNG_ISET_IRQ_CMD_DONE_MASK              ((uint32_t)0x00000004U)         /* !< Write to turn on CMD_DONE IRQ.
                                                                                    Indicates that the last issued TRNG
                                                                                    command has finished. */
#define TRNG_ISET_IRQ_CMD_DONE_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect. */
#define TRNG_ISET_IRQ_CMD_DONE_SET               ((uint32_t)0x00000004U)         /* !< RIS bit corresponding to CMD_DONE
                                                                                    is set */
/* TRNG_ISET[IRQ_CMD_FAIL] Bits */
#define TRNG_ISET_IRQ_CMD_FAIL_OFS               (1)                             /* !< IRQ_CMD_FAIL Offset */
#define TRNG_ISET_IRQ_CMD_FAIL_MASK              ((uint32_t)0x00000002U)         /* !< Masked interrupt source for
                                                                                    IRQ_CMD_FAIL. Indicates that the just
                                                                                    issued command/mode has been
                                                                                    rejected. */
#define TRNG_ISET_IRQ_CMD_FAIL_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect. */
#define TRNG_ISET_IRQ_CMD_FAIL_SET               ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to CMD_FAIL
                                                                                    is set */

/* TRNG_ICLR Bits */
/* TRNG_ICLR[IRQ_CAPTURED_RDY] Bits */
#define TRNG_ICLR_IRQ_CAPTURED_RDY_OFS           (3)                             /* !< IRQ_CAPTURED_RDY Offset */
#define TRNG_ICLR_IRQ_CAPTURED_RDY_MASK          ((uint32_t)0x00000008U)         /* !< Indicates to the CPU that the
                                                                                    Captured Word is ready to be read.
                                                                                    Reading the IIDX or DATA_CAPTURE
                                                                                    registers will clear this interrupt. */
#define TRNG_ICLR_IRQ_CAPTURED_RDY_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define TRNG_ICLR_IRQ_CAPTURED_RDY_CLR           ((uint32_t)0x00000008U)         /* !< RIS bit corresponding to
                                                                                    CAPTURED_READY is cleared */
/* TRNG_ICLR[IRQ_HEALTH_FAIL] Bits */
#define TRNG_ICLR_IRQ_HEALTH_FAIL_OFS            (0)                             /* !< IRQ_HEALTH_FAIL Offset */
#define TRNG_ICLR_IRQ_HEALTH_FAIL_MASK           ((uint32_t)0x00000001U)         /* !< Indicates to the CPU that any of
                                                                                    the health tests have failed. Reading
                                                                                    the IIDX or DATA_CAPTURE registers
                                                                                    will clear this interrupt. */
#define TRNG_ICLR_IRQ_HEALTH_FAIL_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define TRNG_ICLR_IRQ_HEALTH_FAIL_CLR            ((uint32_t)0x00000001U)         /* !< RIS bit corresponding to
                                                                                    CAPTURED_READY is cleared */
/* TRNG_ICLR[IRQ_CMD_DONE] Bits */
#define TRNG_ICLR_IRQ_CMD_DONE_OFS               (2)                             /* !< IRQ_CMD_DONE Offset */
#define TRNG_ICLR_IRQ_CMD_DONE_MASK              ((uint32_t)0x00000004U)         /* !< Write to turn off CMD_DONE IRQ.
                                                                                    Indicates that the last issued TRNG
                                                                                    command has finished. */
#define TRNG_ICLR_IRQ_CMD_DONE_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect. */
#define TRNG_ICLR_IRQ_CMD_DONE_CLR               ((uint32_t)0x00000004U)         /* !< RIS bit corresponding to CMD_DONE
                                                                                    is cleared */
/* TRNG_ICLR[IRQ_CMD_FAIL] Bits */
#define TRNG_ICLR_IRQ_CMD_FAIL_OFS               (1)                             /* !< IRQ_CMD_FAIL Offset */
#define TRNG_ICLR_IRQ_CMD_FAIL_MASK              ((uint32_t)0x00000002U)         /* !< Masked interrupt source for
                                                                                    IRQ_CMD_FAIL. Indicates that the just
                                                                                    issued command/mode has been
                                                                                    rejected. */
#define TRNG_ICLR_IRQ_CMD_FAIL_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect. */
#define TRNG_ICLR_IRQ_CMD_FAIL_CLR               ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to CMD_FAIL
                                                                                    is cleared */

/* TRNG_PWREN Bits */
/* TRNG_PWREN[ENABLE] Bits */
#define TRNG_PWREN_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define TRNG_PWREN_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< Enable the power */
#define TRNG_PWREN_ENABLE_DISABLE                ((uint32_t)0x00000000U)         /* !< Disable Power */
#define TRNG_PWREN_ENABLE_ENABLE                 ((uint32_t)0x00000001U)         /* !< Enable Power */
/* TRNG_PWREN[KEY] Bits */
#define TRNG_PWREN_KEY_OFS                       (24)                            /* !< KEY Offset */
#define TRNG_PWREN_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define TRNG_PWREN_KEY_UNLOCK_W                  ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* TRNG_RSTCTL Bits */
/* TRNG_RSTCTL[RESETSTKYCLR] Bits */
#define TRNG_RSTCTL_RESETSTKYCLR_OFS             (1)                             /* !< RESETSTKYCLR Offset */
#define TRNG_RSTCTL_RESETSTKYCLR_MASK            ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define TRNG_RSTCTL_RESETSTKYCLR_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define TRNG_RSTCTL_RESETSTKYCLR_CLR             ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* TRNG_RSTCTL[RESETASSERT] Bits */
#define TRNG_RSTCTL_RESETASSERT_OFS              (0)                             /* !< RESETASSERT Offset */
#define TRNG_RSTCTL_RESETASSERT_MASK             ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define TRNG_RSTCTL_RESETASSERT_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define TRNG_RSTCTL_RESETASSERT_ASSERT           ((uint32_t)0x00000001U)         /* !< Assert reset */
/* TRNG_RSTCTL[KEY] Bits */
#define TRNG_RSTCTL_KEY_OFS                      (24)                            /* !< KEY Offset */
#define TRNG_RSTCTL_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define TRNG_RSTCTL_KEY_UNLOCK_W                 ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* TRNG_GPRCM_STAT Bits */
/* TRNG_GPRCM_STAT[RESETSTKY] Bits */
#define TRNG_GPRCM_STAT_RESETSTKY_OFS            (16)                            /* !< RESETSTKY Offset */
#define TRNG_GPRCM_STAT_RESETSTKY_MASK           ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define TRNG_GPRCM_STAT_RESETSTKY_NORES          ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define TRNG_GPRCM_STAT_RESETSTKY_RESET          ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* TRNG_DESC Bits */
/* TRNG_DESC[MINREV] Bits */
#define TRNG_DESC_MINREV_OFS                     (0)                             /* !< MINREV Offset */
#define TRNG_DESC_MINREV_MASK                    ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
/* TRNG_DESC[MAJREV] Bits */
#define TRNG_DESC_MAJREV_OFS                     (4)                             /* !< MAJREV Offset */
#define TRNG_DESC_MAJREV_MASK                    ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
/* TRNG_DESC[INSTNUM] Bits */
#define TRNG_DESC_INSTNUM_OFS                    (8)                             /* !< INSTNUM Offset */
#define TRNG_DESC_INSTNUM_MASK                   ((uint32_t)0x00000F00U)         /* !< Instance Number within the device.
                                                                                    This will be a parameter to the RTL
                                                                                    for modules that can have multiple
                                                                                    instances */
/* TRNG_DESC[FEATUREVER] Bits */
#define TRNG_DESC_FEATUREVER_OFS                 (12)                            /* !< FEATUREVER Offset */
#define TRNG_DESC_FEATUREVER_MASK                ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
/* TRNG_DESC[MODULEID] Bits */
#define TRNG_DESC_MODULEID_OFS                   (16)                            /* !< MODULEID Offset */
#define TRNG_DESC_MODULEID_MASK                  ((uint32_t)0xFFFF0000U)         /* !< Module Identifier - An internal TI
                                                                                    page has been created to request
                                                                                    unique module IDs */

/* TRNG_CTL Bits */
/* TRNG_CTL[DECIM_RATE] Bits */
#define TRNG_CTL_DECIM_RATE_OFS                  (8)                             /* !< DECIM_RATE Offset */
#define TRNG_CTL_DECIM_RATE_MASK                 ((uint32_t)0x00000700U)         /* !< Set decimation rate. Decimate by n
                                                                                    0x0 = Decimation by 1 (no decimation)
                                                                                    0x1 = Decimation by 2 (Skip every
                                                                                    other sample)  0x7 = Decimation by 8
                                                                                    (Take every 8th sample) */
/* TRNG_CTL[PWRUP_CLKDIV] Bits */
#define TRNG_CTL_PWRUP_CLKDIV_OFS                (16)                            /* !< PWRUP_CLKDIV Offset */
#define TRNG_CTL_PWRUP_CLKDIV_MASK               ((uint32_t)0x00010000U)         /* !< When '1', the powerup sequence will
                                                                                    take twice as long (i.e., clock
                                                                                    frequency halved) */
/* TRNG_CTL[PWRUP_PCHRG_CFG] Bits */
#define TRNG_CTL_PWRUP_PCHRG_CFG_OFS             (17)                            /* !< PWRUP_PCHRG_CFG Offset */
#define TRNG_CTL_PWRUP_PCHRG_CFG_MASK            ((uint32_t)0x00060000U)         /* !< Configure PCHARGE sequence length
                                                                                    b00 = Disabled b01 = 20 us PCHARGE
                                                                                    b10 = 30 us PCHARGE (default) b11 =
                                                                                    40 us PCHARGE */
/* TRNG_CTL[PWRUP_PSTART_CFG] Bits */
#define TRNG_CTL_PWRUP_PSTART_CFG_OFS            (19)                            /* !< PWRUP_PSTART_CFG Offset */
#define TRNG_CTL_PWRUP_PSTART_CFG_MASK           ((uint32_t)0x00180000U)         /* !< Configure pusle startup sequence
                                                                                    length  b00 = Disabled b01 = rise at
                                                                                    10us, fall at 50us b10 = rise at
                                                                                    10us, fall at 70us (default) b11 =
                                                                                    rise at 10us, fall at 90us */
/* TRNG_CTL[CMD] Bits */
#define TRNG_CTL_CMD_OFS                         (0)                             /* !< CMD Offset */
#define TRNG_CTL_CMD_MASK                        ((uint32_t)0x00000003U)         /* !< Sets the TRNG mode through a
                                                                                    command. The mode will not be updated
                                                                                    until the previous command is done,
                                                                                    as indicated by IRQ_CMD_DONE. 00 -->
                                                                                    OFF 01 --> PWRUP_DIG 10 --> PWRUP_ANA
                                                                                    11 --> NORM_FUNC */
#define TRNG_CTL_CMD_PWR_OFF                     ((uint32_t)0x00000000U)         /* !< Turns the power off of the analog
                                                                                    source and clocks the digital
                                                                                    interface */
#define TRNG_CTL_CMD_PWRUP_DIG                   ((uint32_t)0x00000001U)         /* !< Initiates the powerup test sequence
                                                                                    for the digital components. This
                                                                                    verifies that the digital components
                                                                                    are properly working. IRQ_CMD_DONE
                                                                                    indicates that the test is done. The
                                                                                    results of this test are in bits 0:6
                                                                                    in TEST_RESULTS register */
#define TRNG_CTL_CMD_PWRUP_ANA                   ((uint32_t)0x00000002U)         /* !< Initiates the powerup test sequence
                                                                                    for the analog TRNG. This verifies
                                                                                    that the analog component is
                                                                                    generating sequences with enough
                                                                                    entropy. IRQ_CMD_DONE indicates that
                                                                                    the test is done. The results of this
                                                                                    test are in bit 7 in TEST_RESULTS
                                                                                    register */
#define TRNG_CTL_CMD_NORM_FUNC                   ((uint32_t)0x00000003U)         /* !< Normal operating mode for TRNG. All
                                                                                    components are turned on. */

/* TRNG_STAT Bits */
/* TRNG_STAT[ADAP_FAIL] Bits */
#define TRNG_STAT_ADAP_FAIL_OFS                  (0)                             /* !< ADAP_FAIL Offset */
#define TRNG_STAT_ADAP_FAIL_MASK                 ((uint32_t)0x00000001U)         /* !< Indicates that the Adaptive
                                                                                    Proportion Test (1,2,3, or 4-bit
                                                                                    counters) failed by having too many
                                                                                    or too few counted samples in the
                                                                                    last 1024 bit window. */
/* TRNG_STAT[ISSUED_CMD] Bits */
#define TRNG_STAT_ISSUED_CMD_OFS                 (8)                             /* !< ISSUED_CMD Offset */
#define TRNG_STAT_ISSUED_CMD_MASK                ((uint32_t)0x00000300U)         /* !< Indicates the last accepted command
                                                                                    that is issued to the TRNG interface.
                                                                                    Upon writing a valid command, this
                                                                                    register will update and the command
                                                                                    will be in progress until
                                                                                    CMD_DONE_IRQ is set. CMD_DONE_IRQ
                                                                                    indicates that the state is in
                                                                                    PWROFF, NORM_FUNC, or ERROR. These
                                                                                    states will accept new commands. 00
                                                                                    --> OFF 01 --> PWRUP_DIG 10 -->
                                                                                    PWRUP_ANA 11 --> NORM_FUNC */
/* TRNG_STAT[FSM_STATE] Bits */
#define TRNG_STAT_FSM_STATE_OFS                  (16)                            /* !< FSM_STATE Offset */
#define TRNG_STAT_FSM_STATE_MASK                 ((uint32_t)0x000F0000U)         /* !< Current state of the front end FSM
                                                                                    (behind a clock domain crossing). 2
                                                                                    reads are REQUIRED as there is a
                                                                                    chance of metastability when reading
                                                                                    this States: 0000: OFF 0001: PWRUP_ES
                                                                                    0011: NORM_FUNC 0111: TEST_DIG 1011:
                                                                                    TEST_ANA 1010: ERROR 0010: PWRDOWN_ES */
/* TRNG_STAT[REP_FAIL] Bits */
#define TRNG_STAT_REP_FAIL_OFS                   (1)                             /* !< REP_FAIL Offset */
#define TRNG_STAT_REP_FAIL_MASK                  ((uint32_t)0x00000002U)         /* !< Indicates that the repetition
                                                                                    counter test caused the most recent
                                                                                    failure. Thus, the health count
                                                                                    numbers are most likely not for a
                                                                                    complete 1024-bit window. */

/* TRNG_DATA_CAPTURE Bits */
/* TRNG_DATA_CAPTURE[BUFFER] Bits */
#define TRNG_DATA_CAPTURE_BUFFER_OFS             (0)                             /* !< BUFFER Offset */
#define TRNG_DATA_CAPTURE_BUFFER_MASK            ((uint32_t)0xFFFFFFFFU)         /* !< Captured Data from the Decimation
                                                                                    Block */

/* TRNG_TEST_RESULTS Bits */
/* TRNG_TEST_RESULTS[DIG_TEST] Bits */
#define TRNG_TEST_RESULTS_DIG_TEST_OFS           (0)                             /* !< DIG_TEST Offset */
#define TRNG_TEST_RESULTS_DIG_TEST_MASK          ((uint32_t)0x000000FFU)         /* !< Bit 0 indicates if the first
                                                                                    decimation rate test and health
                                                                                    test(verifies conditioning,
                                                                                    decimation, and captured buffer)
                                                                                    fails and Bit 1 indicates if the
                                                                                    second decimation test and health
                                                                                    test fails Bit 0 - decim_test0 (decim
                                                                                    = 0x0) Bit 1 - decim_test1 (decim =
                                                                                    0x1) ... */
/* TRNG_TEST_RESULTS[ANA_TEST] Bits */
#define TRNG_TEST_RESULTS_ANA_TEST_OFS           (8)                             /* !< ANA_TEST Offset */
#define TRNG_TEST_RESULTS_ANA_TEST_MASK          ((uint32_t)0x00000100U)         /* !< Runs through 4096 samples from an
                                                                                    enabled entropy source and verifies
                                                                                    that none of the health tests failed,
                                                                                    indicating sufficient entropy was
                                                                                    produced by the analog components */

/* TRNG_CLKDIVIDE Bits */
/* TRNG_CLKDIVIDE[RATIO] Bits */
#define TRNG_CLKDIVIDE_RATIO_OFS                 (0)                             /* !< RATIO Offset */
#define TRNG_CLKDIVIDE_RATIO_MASK                ((uint32_t)0x00000007U)         /* !< Selects divide ratio of module
                                                                                    clock */
#define TRNG_CLKDIVIDE_RATIO_DIV_BY_1            ((uint32_t)0x00000000U)         /* !< Do not divide clock source */
#define TRNG_CLKDIVIDE_RATIO_DIV_BY_2            ((uint32_t)0x00000001U)         /* !< Divide clock source by 2 */
#define TRNG_CLKDIVIDE_RATIO_DIV_BY_4            ((uint32_t)0x00000003U)         /* !< Divide clock source by 4 */
#define TRNG_CLKDIVIDE_RATIO_DIV_BY_6            ((uint32_t)0x00000005U)         /* !< Divide clock source by 6 */
#define TRNG_CLKDIVIDE_RATIO_DIV_BY_8            ((uint32_t)0x00000007U)         /* !< Divide clock source by 8 */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_trng__include */
