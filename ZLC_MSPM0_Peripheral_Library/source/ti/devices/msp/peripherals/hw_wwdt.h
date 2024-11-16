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

#ifndef ti_devices_msp_peripherals_hw_wwdt__include
#define ti_devices_msp_peripherals_hw_wwdt__include

/* Filename: hw_wwdt.h */
/* Revised: 2023-05-10 21:36:51 */
/* Revision: 662977591cca7f583e1df6fe4b402c6c07949212 */

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
* WWDT Registers
******************************************************************************/
#define WWDT_CPU_INT_OFS                         ((uint32_t)0x00001020U)
#define WWDT_GPRCM_OFS                           ((uint32_t)0x00000800U)


/** @addtogroup WWDT_CPU_INT
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
} WWDT_CPU_INT_Regs;

/*@}*/ /* end of group WWDT_CPU_INT */

/** @addtogroup WWDT_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} WWDT_GPRCM_Regs;

/*@}*/ /* end of group WWDT_GPRCM */

/** @addtogroup WWDT
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  WWDT_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED1[512];
  __IO uint32_t PDBGCTL;                           /* !< (@ 0x00001018) Peripheral Debug Control */
       uint32_t RESERVED2;
  WWDT_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED3[37];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED4[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
  __IO uint32_t WWDTCTL0;                          /* !< (@ 0x00001100) Window Watchdog Timer Control Register 0 */
  __IO uint32_t WWDTCTL1;                          /* !< (@ 0x00001104) Window Watchdog Timer Control Register 0 */
  __IO uint32_t WWDTCNTRST;                        /* !< (@ 0x00001108) Window Watchdog Timer Counter Reset Register */
  __I  uint32_t WWDTSTAT;                          /* !< (@ 0x0000110C) Window Watchdog Timer Status Register */
} WWDT_Regs;

/*@}*/ /* end of group WWDT */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* WWDT Register Control Bits
******************************************************************************/

/* WWDT_IIDX Bits */
/* WWDT_IIDX[STAT] Bits */
#define WWDT_IIDX_STAT_OFS                       (0)                             /* !< STAT Offset */
#define WWDT_IIDX_STAT_MASK                      ((uint32_t)0x0000001FU)         /* !< Module Interrupt Vector Value.
                                                                                    This register provides the highest
                                                                                    priority interrupt index. A read
                                                                                    clears the corresponding interrupt
                                                                                    flag in RIS and MISC. */
#define WWDT_IIDX_STAT_NO_INTR                   ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define WWDT_IIDX_STAT_INTTIM                    ((uint32_t)0x00000001U)         /* !< Interval Timer Interrupt; Interrupt
                                                                                    Flag: INTTIM; Interrupt Priority:
                                                                                    Highest */

/* WWDT_IMASK Bits */
/* WWDT_IMASK[INTTIM] Bits */
#define WWDT_IMASK_INTTIM_OFS                    (0)                             /* !< INTTIM Offset */
#define WWDT_IMASK_INTTIM_MASK                   ((uint32_t)0x00000001U)         /* !< Interval Timer Interrupt. */
#define WWDT_IMASK_INTTIM_CLR                    ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define WWDT_IMASK_INTTIM_SET                    ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */

/* WWDT_RIS Bits */
/* WWDT_RIS[INTTIM] Bits */
#define WWDT_RIS_INTTIM_OFS                      (0)                             /* !< INTTIM Offset */
#define WWDT_RIS_INTTIM_MASK                     ((uint32_t)0x00000001U)         /* !< Interval Timer Interrupt. */
#define WWDT_RIS_INTTIM_CLR                      ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define WWDT_RIS_INTTIM_SET                      ((uint32_t)0x00000001U)         /* !< Interrupt occurred */

/* WWDT_MIS Bits */
/* WWDT_MIS[INTTIM] Bits */
#define WWDT_MIS_INTTIM_OFS                      (0)                             /* !< INTTIM Offset */
#define WWDT_MIS_INTTIM_MASK                     ((uint32_t)0x00000001U)         /* !< Interval Timer Interrupt. */
#define WWDT_MIS_INTTIM_CLR                      ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define WWDT_MIS_INTTIM_SET                      ((uint32_t)0x00000001U)         /* !< Interrupt occurred */

/* WWDT_ISET Bits */
/* WWDT_ISET[INTTIM] Bits */
#define WWDT_ISET_INTTIM_OFS                     (0)                             /* !< INTTIM Offset */
#define WWDT_ISET_INTTIM_MASK                    ((uint32_t)0x00000001U)         /* !< Interval Timer Interrupt. */
#define WWDT_ISET_INTTIM_NO_EFFECT               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define WWDT_ISET_INTTIM_SET                     ((uint32_t)0x00000001U)         /* !< Set Interrupt */

/* WWDT_ICLR Bits */
/* WWDT_ICLR[INTTIM] Bits */
#define WWDT_ICLR_INTTIM_OFS                     (0)                             /* !< INTTIM Offset */
#define WWDT_ICLR_INTTIM_MASK                    ((uint32_t)0x00000001U)         /* !< Interval Timer Interrupt. */
#define WWDT_ICLR_INTTIM_NO_EFFECT               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define WWDT_ICLR_INTTIM_CLR                     ((uint32_t)0x00000001U)         /* !< Clear Interrupt */

/* WWDT_PWREN Bits */
/* WWDT_PWREN[ENABLE] Bits */
#define WWDT_PWREN_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define WWDT_PWREN_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< Enable the power Note: For safety
                                                                                    devices the power cannot be disabled
                                                                                    once enabled. */
#define WWDT_PWREN_ENABLE_DISABLE                ((uint32_t)0x00000000U)         /* !< Disable Power */
#define WWDT_PWREN_ENABLE_ENABLE                 ((uint32_t)0x00000001U)         /* !< Enable Power */
/* WWDT_PWREN[KEY] Bits */
#define WWDT_PWREN_KEY_OFS                       (24)                            /* !< KEY Offset */
#define WWDT_PWREN_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define WWDT_PWREN_KEY_UNLOCK_W                  ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* WWDT_RSTCTL Bits */
/* WWDT_RSTCTL[RESETSTKYCLR] Bits */
#define WWDT_RSTCTL_RESETSTKYCLR_OFS             (1)                             /* !< RESETSTKYCLR Offset */
#define WWDT_RSTCTL_RESETSTKYCLR_MASK            ((uint32_t)0x00000002U)         /* !< Clear [GPRCM.STAT.RESETSTKY] */
#define WWDT_RSTCTL_RESETSTKYCLR_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define WWDT_RSTCTL_RESETSTKYCLR_CLR             ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* WWDT_RSTCTL[RESETASSERT] Bits */
#define WWDT_RSTCTL_RESETASSERT_OFS              (0)                             /* !< RESETASSERT Offset */
#define WWDT_RSTCTL_RESETASSERT_MASK             ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral
                                                                                    Note: For safety devices a watchdog
                                                                                    reset by software is not possible. */
#define WWDT_RSTCTL_RESETASSERT_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define WWDT_RSTCTL_RESETASSERT_ASSERT           ((uint32_t)0x00000001U)         /* !< Assert reset */
/* WWDT_RSTCTL[KEY] Bits */
#define WWDT_RSTCTL_KEY_OFS                      (24)                            /* !< KEY Offset */
#define WWDT_RSTCTL_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define WWDT_RSTCTL_KEY_UNLOCK_W                 ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* WWDT_STAT Bits */
/* WWDT_STAT[RESETSTKY] Bits */
#define WWDT_STAT_RESETSTKY_OFS                  (16)                            /* !< RESETSTKY Offset */
#define WWDT_STAT_RESETSTKY_MASK                 ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define WWDT_STAT_RESETSTKY_NORES                ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define WWDT_STAT_RESETSTKY_RESET                ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* WWDT_PDBGCTL Bits */
/* WWDT_PDBGCTL[FREE] Bits */
#define WWDT_PDBGCTL_FREE_OFS                    (0)                             /* !< FREE Offset */
#define WWDT_PDBGCTL_FREE_MASK                   ((uint32_t)0x00000001U)         /* !< Free run control */
#define WWDT_PDBGCTL_FREE_STOP                   ((uint32_t)0x00000000U)         /* !< The peripheral freezes
                                                                                    functionality while the Core Halted
                                                                                    input is asserted and resumes when it
                                                                                    is deasserted. */
#define WWDT_PDBGCTL_FREE_RUN                    ((uint32_t)0x00000001U)         /* !< The peripheral ignores the state of
                                                                                    the Core Halted input */

/* WWDT_EVT_MODE Bits */
/* WWDT_EVT_MODE[INT0_CFG] Bits */
#define WWDT_EVT_MODE_INT0_CFG_OFS               (0)                             /* !< INT0_CFG Offset */
#define WWDT_EVT_MODE_INT0_CFG_MASK              ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.CPU_INT][0] */
#define WWDT_EVT_MODE_INT0_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define WWDT_EVT_MODE_INT0_CFG_SOFTWARE          ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define WWDT_EVT_MODE_INT0_CFG_HARDWARE          ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* WWDT_DESC Bits */
/* WWDT_DESC[MINREV] Bits */
#define WWDT_DESC_MINREV_OFS                     (0)                             /* !< MINREV Offset */
#define WWDT_DESC_MINREV_MASK                    ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
#define WWDT_DESC_MINREV_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define WWDT_DESC_MINREV_MAXIMUM                 ((uint32_t)0x0000000FU)         /* !< Highest possible value */
/* WWDT_DESC[MAJREV] Bits */
#define WWDT_DESC_MAJREV_OFS                     (4)                             /* !< MAJREV Offset */
#define WWDT_DESC_MAJREV_MASK                    ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
#define WWDT_DESC_MAJREV_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define WWDT_DESC_MAJREV_MAXIMUM                 ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* WWDT_DESC[INSTNUM] Bits */
#define WWDT_DESC_INSTNUM_OFS                    (8)                             /* !< INSTNUM Offset */
#define WWDT_DESC_INSTNUM_MASK                   ((uint32_t)0x00000F00U)         /* !< Instance Number within the device.
                                                                                    This will be a parameter to the RTL
                                                                                    for modules that can have multiple
                                                                                    instances */
#define WWDT_DESC_INSTNUM_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define WWDT_DESC_INSTNUM_MAXIMUM                ((uint32_t)0x00000F00U)         /* !< Highest possible value */
/* WWDT_DESC[FEATUREVER] Bits */
#define WWDT_DESC_FEATUREVER_OFS                 (12)                            /* !< FEATUREVER Offset */
#define WWDT_DESC_FEATUREVER_MASK                ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
#define WWDT_DESC_FEATUREVER_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define WWDT_DESC_FEATUREVER_MAXIMUM             ((uint32_t)0x0000F000U)         /* !< Highest possible value */
/* WWDT_DESC[MODULEID] Bits */
#define WWDT_DESC_MODULEID_OFS                   (16)                            /* !< MODULEID Offset */
#define WWDT_DESC_MODULEID_MASK                  ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */
#define WWDT_DESC_MODULEID_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define WWDT_DESC_MODULEID_MAXIMUM               ((uint32_t)0xFFFF0000U)         /* !< Highest possible value */

/* WWDT_WWDTCTL0 Bits */
/* WWDT_WWDTCTL0[PER] Bits */
#define WWDT_WWDTCTL0_PER_OFS                    (4)                             /* !< PER Offset */
#define WWDT_WWDTCTL0_PER_MASK                   ((uint32_t)0x00000070U)         /* !< Timer Period of the WWDT. These
                                                                                    bits select the total watchdog timer
                                                                                    count. */
#define WWDT_WWDTCTL0_PER_EN_25                  ((uint32_t)0x00000000U)         /* !< Total timer count is 2^25 */
#define WWDT_WWDTCTL0_PER_EN_21                  ((uint32_t)0x00000010U)         /* !< Total timer count is 2^21 */
#define WWDT_WWDTCTL0_PER_EN_18                  ((uint32_t)0x00000020U)         /* !< Total timer count is 2^18 */
#define WWDT_WWDTCTL0_PER_EN_15                  ((uint32_t)0x00000030U)         /* !< Total timer count is 2^15 */
#define WWDT_WWDTCTL0_PER_EN_12                  ((uint32_t)0x00000040U)         /* !< Total timer count is 2^12 (default) */
#define WWDT_WWDTCTL0_PER_EN_10                  ((uint32_t)0x00000050U)         /* !< Total timer count is 2^10 */
#define WWDT_WWDTCTL0_PER_EN_8                   ((uint32_t)0x00000060U)         /* !< Total timer count is 2^8 */
#define WWDT_WWDTCTL0_PER_EN_6                   ((uint32_t)0x00000070U)         /* !< Total timer count is 2^6 */
/* WWDT_WWDTCTL0[WINDOW0] Bits */
#define WWDT_WWDTCTL0_WINDOW0_OFS                (8)                             /* !< WINDOW0 Offset */
#define WWDT_WWDTCTL0_WINDOW0_MASK               ((uint32_t)0x00000700U)         /* !< Closed window period in percentage
                                                                                    of the timer interval.
                                                                                    WWDTCTL1.WINSEL determines the active
                                                                                    window setting (WWDTCTL0.WINDOW0 or
                                                                                    WWDTCTL0.WINDOW1). */
#define WWDT_WWDTCTL0_WINDOW0_SIZE_0             ((uint32_t)0x00000000U)         /* !< 0% (No closed Window) */
#define WWDT_WWDTCTL0_WINDOW0_SIZE_12            ((uint32_t)0x00000100U)         /* !< 12.50% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW0_SIZE_18            ((uint32_t)0x00000200U)         /* !< 18.75% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW0_SIZE_25            ((uint32_t)0x00000300U)         /* !< 25% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW0_SIZE_50            ((uint32_t)0x00000400U)         /* !< 50% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW0_SIZE_75            ((uint32_t)0x00000500U)         /* !< 75% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW0_SIZE_81            ((uint32_t)0x00000600U)         /* !< 81.25% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW0_SIZE_87            ((uint32_t)0x00000700U)         /* !< 87.50% of the total timer period is
                                                                                    closed window */
/* WWDT_WWDTCTL0[MODE] Bits */
#define WWDT_WWDTCTL0_MODE_OFS                   (16)                            /* !< MODE Offset */
#define WWDT_WWDTCTL0_MODE_MASK                  ((uint32_t)0x00010000U)         /* !< Window Watchdog Timer Mode */
#define WWDT_WWDTCTL0_MODE_WINDOW                ((uint32_t)0x00000000U)         /* !< Window Watchdog Timer Mode. The
                                                                                    WWDT will generate a error signal to
                                                                                    the ESM when following conditions
                                                                                    occur: - Timer Expiration (Timeout) -
                                                                                    Reset WWDT during the active window
                                                                                    closed period - Keyword violation */
#define WWDT_WWDTCTL0_MODE_INTERVAL              ((uint32_t)0x00010000U)         /* !< Interval Timer Mode. The WWDT acts
                                                                                    as an interval timer. It generates an
                                                                                    interrupt on timeout. */
/* WWDT_WWDTCTL0[STISM] Bits */
#define WWDT_WWDTCTL0_STISM_OFS                  (17)                            /* !< STISM Offset */
#define WWDT_WWDTCTL0_STISM_MASK                 ((uint32_t)0x00020000U)         /* !< Stop In Sleep Mode.    The
                                                                                    functionality of this bit requires
                                                                                    that POLICY.HWCEN = 0. If
                                                                                    POLICY.HWCEN = 1 the WWDT resets
                                                                                    during sleep and needs
                                                                                    re-configuration. Note: This bit has
                                                                                    no effect for the global Window
                                                                                    Watchdog as Sleep Mode is not
                                                                                    supported. */
#define WWDT_WWDTCTL0_STISM_CONT                 ((uint32_t)0x00000000U)         /* !< The WWDT continues to function in
                                                                                    Sleep mode. */
#define WWDT_WWDTCTL0_STISM_STOP                 ((uint32_t)0x00020000U)         /* !< The WWDT stops in Sleep mode and
                                                                                    resumes where it was stopped after
                                                                                    wakeup. */
/* WWDT_WWDTCTL0[KEY] Bits */
#define WWDT_WWDTCTL0_KEY_OFS                    (24)                            /* !< KEY Offset */
#define WWDT_WWDTCTL0_KEY_MASK                   ((uint32_t)0xFF000000U)         /* !< KEY to allow write access to this
                                                                                    register.  Writing to this register
                                                                                    with an incorrect key activates the
                                                                                    WWDT error signal to the ESM. Read as
                                                                                    0. */
#define WWDT_WWDTCTL0_KEY_UNLOCK_W               ((uint32_t)0xC9000000U)         /* !< KEY to allow write access to this
                                                                                    register */
/* WWDT_WWDTCTL0[CLKDIV] Bits */
#define WWDT_WWDTCTL0_CLKDIV_OFS                 (0)                             /* !< CLKDIV Offset */
#define WWDT_WWDTCTL0_CLKDIV_MASK                ((uint32_t)0x00000007U)         /* !< Module Clock Divider, Divide the
                                                                                    clock source by CLKDIV+1. Divider
                                                                                    values from /1 to /8 are possible.
                                                                                    The clock divider is currently 4
                                                                                    bits. Bit 4 has no effect and should
                                                                                    always be written with 0. */
#define WWDT_WWDTCTL0_CLKDIV_MINIMUM             ((uint32_t)0x00000000U)         /* !< Minimum value */
#define WWDT_WWDTCTL0_CLKDIV_MAXIMUM             ((uint32_t)0x00000007U)         /* !< Maximum value */
/* WWDT_WWDTCTL0[WINDOW1] Bits */
#define WWDT_WWDTCTL0_WINDOW1_OFS                (12)                            /* !< WINDOW1 Offset */
#define WWDT_WWDTCTL0_WINDOW1_MASK               ((uint32_t)0x00007000U)         /* !< Closed window period in percentage
                                                                                    of the timer interval.
                                                                                    WWDTCTL1.WINSEL determines the active
                                                                                    window setting (WWDTCTL0.WINDOW0 or
                                                                                    WWDTCTL0.WINDOW1). */
#define WWDT_WWDTCTL0_WINDOW1_SIZE_0             ((uint32_t)0x00000000U)         /* !< 0% (No closed Window) */
#define WWDT_WWDTCTL0_WINDOW1_SIZE_12            ((uint32_t)0x00001000U)         /* !< 12.50% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW1_SIZE_18            ((uint32_t)0x00002000U)         /* !< 18.75% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW1_SIZE_25            ((uint32_t)0x00003000U)         /* !< 25% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW1_SIZE_50            ((uint32_t)0x00004000U)         /* !< 50% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW1_SIZE_75            ((uint32_t)0x00005000U)         /* !< 75% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW1_SIZE_81            ((uint32_t)0x00006000U)         /* !< 81.25% of the total timer period is
                                                                                    closed window */
#define WWDT_WWDTCTL0_WINDOW1_SIZE_87            ((uint32_t)0x00007000U)         /* !< 87.50% of the total timer period is
                                                                                    closed window */

/* WWDT_WWDTCTL1 Bits */
/* WWDT_WWDTCTL1[KEY] Bits */
#define WWDT_WWDTCTL1_KEY_OFS                    (24)                            /* !< KEY Offset */
#define WWDT_WWDTCTL1_KEY_MASK                   ((uint32_t)0xFF000000U)         /* !< KEY to allow write access to this
                                                                                    register.  Writing to this register
                                                                                    with an incorrect key activates the
                                                                                    WWDT error signal to the ESM. Read as
                                                                                    0. */
#define WWDT_WWDTCTL1_KEY_UNLOCK_W               ((uint32_t)0xBE000000U)         /* !< KEY to allow write access to this
                                                                                    register */
/* WWDT_WWDTCTL1[WINSEL] Bits */
#define WWDT_WWDTCTL1_WINSEL_OFS                 (0)                             /* !< WINSEL Offset */
#define WWDT_WWDTCTL1_WINSEL_MASK                ((uint32_t)0x00000001U)         /* !< Close Window Select */
#define WWDT_WWDTCTL1_WINSEL_WIN0                ((uint32_t)0x00000000U)         /* !< In window mode field WINDOW0 of
                                                                                    WDDTCTL0 defines the closed window
                                                                                    size. */
#define WWDT_WWDTCTL1_WINSEL_WIN1                ((uint32_t)0x00000001U)         /* !< In window mode field WINDOW1 of
                                                                                    WDDTCTL0 defines the closed window
                                                                                    size. */

/* WWDT_WWDTCNTRST Bits */
/* WWDT_WWDTCNTRST[RESTART] Bits */
#define WWDT_WWDTCNTRST_RESTART_OFS              (0)                             /* !< RESTART Offset */
#define WWDT_WWDTCNTRST_RESTART_MASK             ((uint32_t)0xFFFFFFFFU)         /* !< Window Watchdog Timer Counter
                                                                                    Restart Writing 00A7h to this
                                                                                    register restarts the WWDT Counter.
                                                                                    Writing any other value causes an
                                                                                    error generation to the ESM. Read as
                                                                                    0. */
#define WWDT_WWDTCNTRST_RESTART_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value */
#define WWDT_WWDTCNTRST_RESTART_MAXIMUM          ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value */

/* WWDT_WWDTSTAT Bits */
/* WWDT_WWDTSTAT[RUN] Bits */
#define WWDT_WWDTSTAT_RUN_OFS                    (0)                             /* !< RUN Offset */
#define WWDT_WWDTSTAT_RUN_MASK                   ((uint32_t)0x00000001U)         /* !< Watchdog running status flag. */
#define WWDT_WWDTSTAT_RUN_OFF                    ((uint32_t)0x00000000U)         /* !< Watchdog counter stopped. */
#define WWDT_WWDTSTAT_RUN_ON                     ((uint32_t)0x00000001U)         /* !< Watchdog running. */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_wwdt__include */
