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

#ifndef ti_devices_msp_peripherals_hw_vref__include
#define ti_devices_msp_peripherals_hw_vref__include

/* Filename: hw_vref.h */
/* Revised: 2023-05-10 21:34:47 */
/* Revision: 346daa750fb9270ab4d9c503b44addb19c7cc8cc */

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
* VREF Registers
******************************************************************************/
#define VREF_GPRCM_OFS                           ((uint32_t)0x00000800U)


/** @addtogroup VREF_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} VREF_GPRCM_Regs;

/*@}*/ /* end of group VREF_GPRCM */

/** @addtogroup VREF
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  VREF_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED1[506];
  __IO uint32_t CLKDIV;                            /* !< (@ 0x00001000) Clock Divider */
       uint32_t RESERVED2;
  __IO uint32_t CLKSEL;                            /* !< (@ 0x00001008) Clock Selection */
       uint32_t RESERVED3[61];
  __IO uint32_t CTL0;                              /* !< (@ 0x00001100) Control 0 */
  __IO uint32_t CTL1;                              /* !< (@ 0x00001104) Control 1 */
  __IO uint32_t CTL2;                              /* !< (@ 0x00001108) Control 2 */
} VREF_Regs;

/*@}*/ /* end of group VREF */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* VREF Register Control Bits
******************************************************************************/

/* VREF_PWREN Bits */
/* VREF_PWREN[ENABLE] Bits */
#define VREF_PWREN_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define VREF_PWREN_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< Enable the power */
#define VREF_PWREN_ENABLE_DISABLE                ((uint32_t)0x00000000U)         /* !< Disable Power */
#define VREF_PWREN_ENABLE_ENABLE                 ((uint32_t)0x00000001U)         /* !< Enable Power */
/* VREF_PWREN[KEY] Bits */
#define VREF_PWREN_KEY_OFS                       (24)                            /* !< KEY Offset */
#define VREF_PWREN_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define VREF_PWREN_KEY_UNLOCK_W                  ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* VREF_RSTCTL Bits */
/* VREF_RSTCTL[RESETSTKYCLR] Bits */
#define VREF_RSTCTL_RESETSTKYCLR_OFS             (1)                             /* !< RESETSTKYCLR Offset */
#define VREF_RSTCTL_RESETSTKYCLR_MASK            ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define VREF_RSTCTL_RESETSTKYCLR_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define VREF_RSTCTL_RESETSTKYCLR_CLR             ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* VREF_RSTCTL[RESETASSERT] Bits */
#define VREF_RSTCTL_RESETASSERT_OFS              (0)                             /* !< RESETASSERT Offset */
#define VREF_RSTCTL_RESETASSERT_MASK             ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define VREF_RSTCTL_RESETASSERT_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define VREF_RSTCTL_RESETASSERT_ASSERT           ((uint32_t)0x00000001U)         /* !< Assert reset */
/* VREF_RSTCTL[KEY] Bits */
#define VREF_RSTCTL_KEY_OFS                      (24)                            /* !< KEY Offset */
#define VREF_RSTCTL_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define VREF_RSTCTL_KEY_UNLOCK_W                 ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* VREF_STAT Bits */
/* VREF_STAT[RESETSTKY] Bits */
#define VREF_STAT_RESETSTKY_OFS                  (16)                            /* !< RESETSTKY Offset */
#define VREF_STAT_RESETSTKY_MASK                 ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define VREF_STAT_RESETSTKY_NORES                ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define VREF_STAT_RESETSTKY_RESET                ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* VREF_CLKDIV Bits */
/* VREF_CLKDIV[RATIO] Bits */
#define VREF_CLKDIV_RATIO_OFS                    (0)                             /* !< RATIO Offset */
#define VREF_CLKDIV_RATIO_MASK                   ((uint32_t)0x00000007U)         /* !< Selects divide ratio of module
                                                                                    clock to be used in sample and hold
                                                                                    logic */

/* VREF_CLKSEL Bits */
/* VREF_CLKSEL[LFCLK_SEL] Bits */
#define VREF_CLKSEL_LFCLK_SEL_OFS                (1)                             /* !< LFCLK_SEL Offset */
#define VREF_CLKSEL_LFCLK_SEL_MASK               ((uint32_t)0x00000002U)         /* !< Selects LFCLK as clock source if
                                                                                    enabled */
/* VREF_CLKSEL[MFCLK_SEL] Bits */
#define VREF_CLKSEL_MFCLK_SEL_OFS                (2)                             /* !< MFCLK_SEL Offset */
#define VREF_CLKSEL_MFCLK_SEL_MASK               ((uint32_t)0x00000004U)         /* !< Selects MFCLK as clock source if
                                                                                    enabled */
/* VREF_CLKSEL[BUSCLK_SEL] Bits */
#define VREF_CLKSEL_BUSCLK_SEL_OFS               (3)                             /* !< BUSCLK_SEL Offset */
#define VREF_CLKSEL_BUSCLK_SEL_MASK              ((uint32_t)0x00000008U)         /* !< Selects BUSCLK as clock source if
                                                                                    enabled */

/* VREF_CTL0 Bits */
/* VREF_CTL0[ENABLE] Bits */
#define VREF_CTL0_ENABLE_OFS                     (0)                             /* !< ENABLE Offset */
#define VREF_CTL0_ENABLE_MASK                    ((uint32_t)0x00000001U)         /* !< This bit enables the VREF module. */
#define VREF_CTL0_ENABLE_DISABLE                 ((uint32_t)0x00000000U)         /* !< VREF is disabled */
#define VREF_CTL0_ENABLE_ENABLE                  ((uint32_t)0x00000001U)         /* !< VREF is enabled */
/* VREF_CTL0[BUFCONFIG] Bits */
#define VREF_CTL0_BUFCONFIG_OFS                  (7)                             /* !< BUFCONFIG Offset */
#define VREF_CTL0_BUFCONFIG_MASK                 ((uint32_t)0x00000080U)         /* !< These bits configure output buffer. */
#define VREF_CTL0_BUFCONFIG_OUTPUT2P5V           ((uint32_t)0x00000000U)         /* !< Configure Output Buffer to 2.5v */
#define VREF_CTL0_BUFCONFIG_OUTPUT1P4V           ((uint32_t)0x00000080U)         /* !< Configure Output Buffer to 1.4v */
/* VREF_CTL0[SHMODE] Bits */
#define VREF_CTL0_SHMODE_OFS                     (8)                             /* !< SHMODE Offset */
#define VREF_CTL0_SHMODE_MASK                    ((uint32_t)0x00000100U)         /* !< This bit enable sample and hold
                                                                                    mode */
#define VREF_CTL0_SHMODE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Sample and hold mode is disable */
#define VREF_CTL0_SHMODE_ENABLE                  ((uint32_t)0x00000100U)         /* !< Sample and hold mode is enable */
/* VREF_CTL0[COMP_VREF_ENABLE] Bits */
#define VREF_CTL0_COMP_VREF_ENABLE_OFS           (1)                             /* !< COMP_VREF_ENABLE Offset */
#define VREF_CTL0_COMP_VREF_ENABLE_MASK          ((uint32_t)0x00000002U)         /* !< Comparator Vref Enable */
#define VREF_CTL0_COMP_VREF_ENABLE_DISABLE       ((uint32_t)0x00000000U)         /* !< COMP VREF is disabled */
#define VREF_CTL0_COMP_VREF_ENABLE_ENABLE        ((uint32_t)0x00000002U)         /* !< COMP VREF is enabled */

/* VREF_CTL1 Bits */
/* VREF_CTL1[READY] Bits */
#define VREF_CTL1_READY_OFS                      (0)                             /* !< READY Offset */
#define VREF_CTL1_READY_MASK                     ((uint32_t)0x00000001U)         /* !< These bits defines status of VREF */
#define VREF_CTL1_READY_NOTRDY                   ((uint32_t)0x00000000U)         /* !< VREF output is not ready */
#define VREF_CTL1_READY_RDY                      ((uint32_t)0x00000001U)         /* !< VREF output is ready */

/* VREF_CTL2 Bits */
/* VREF_CTL2[SHCYCLE] Bits */
#define VREF_CTL2_SHCYCLE_OFS                    (0)                             /* !< SHCYCLE Offset */
#define VREF_CTL2_SHCYCLE_MASK                   ((uint32_t)0x0000FFFFU)         /* !< Sample and Hold cycle count Total
                                                                                    cycles of module clock for sample and
                                                                                    hold phase when VREF is working in
                                                                                    sample and hold mode in STANDBY to
                                                                                    save power. This field should be
                                                                                    greater than HCYCLE field. The
                                                                                    difference between this field and
                                                                                    HCYCLE gives the number of cycles of
                                                                                    sample phase. Please refer VREF
                                                                                    section of datasheet for recommended
                                                                                    values of sample and hold times. */
#define VREF_CTL2_SHCYCLE_MINIMUM                ((uint32_t)0x00000000U)         /* !< smallest sample and hold cycle
                                                                                    count */
#define VREF_CTL2_SHCYCLE_MAXIMUM                ((uint32_t)0x0000FFFFU)         /* !< largest sample and hold cycle */
/* VREF_CTL2[HCYCLE] Bits */
#define VREF_CTL2_HCYCLE_OFS                     (16)                            /* !< HCYCLE Offset */
#define VREF_CTL2_HCYCLE_MASK                    ((uint32_t)0xFFFF0000U)         /* !< Hold cycle count Total cycles of
                                                                                    module clock for hold phase when VREF
                                                                                    is working in sample and hold mode in
                                                                                    STANDBY to save power. Please refer
                                                                                    VREF section of datasheet for
                                                                                    recommended values of sample and hold
                                                                                    times. */
#define VREF_CTL2_HCYCLE_MINIMUM                 ((uint32_t)0x00000000U)         /* !< smallest hold cycle */
#define VREF_CTL2_HCYCLE_MAXIMUM                 ((uint32_t)0xFFFF0000U)         /* !< largest hold cycle */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_vref__include */
