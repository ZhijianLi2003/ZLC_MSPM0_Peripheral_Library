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

#ifndef ti_devices_msp_peripherals_hw_comp__include
#define ti_devices_msp_peripherals_hw_comp__include

/* Filename: hw_comp.h */
/* Revised: 2023-05-10 21:23:38 */
/* Revision: 5c29864c187960f76e656cbc0f0f844cdb69a263 */

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
* COMP Registers
******************************************************************************/
#define COMP_GEN_EVENT_OFS                       ((uint32_t)0x00001050U)
#define COMP_CPU_INT_OFS                         ((uint32_t)0x00001020U)
#define COMP_GPRCM_OFS                           ((uint32_t)0x00000800U)


/** @addtogroup COMP_GEN_EVENT
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001050) Interrupt index */
       uint32_t RESERVED0;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001058) Interrupt mask */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x00001060) Raw interrupt status */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x00001068) Masked interrupt status */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x00001070) Interrupt set */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x00001078) Interrupt clear */
} COMP_GEN_EVENT_Regs;

/*@}*/ /* end of group COMP_GEN_EVENT */

/** @addtogroup COMP_CPU_INT
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
} COMP_CPU_INT_Regs;

/*@}*/ /* end of group COMP_CPU_INT */

/** @addtogroup COMP_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00000808) Peripheral Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} COMP_GPRCM_Regs;

/*@}*/ /* end of group COMP_GPRCM */

/** @addtogroup COMP
  @{
*/

typedef struct {
       uint32_t RESERVED0[256];
  __IO uint32_t FSUB_0;                            /* !< (@ 0x00000400) Subscriber Port 0 */
  __IO uint32_t FSUB_1;                            /* !< (@ 0x00000404) Subscriber Port 1 */
       uint32_t RESERVED1[15];
  __IO uint32_t FPUB_1;                            /* !< (@ 0x00000444) Publisher port 1 */
       uint32_t RESERVED2[238];
  COMP_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED3[514];
  COMP_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED4;
  COMP_GEN_EVENT_Regs  GEN_EVENT;                         /* !< (@ 0x00001050) */
       uint32_t RESERVED5[25];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED6[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
  __IO uint32_t CTL0;                              /* !< (@ 0x00001100) Control 0 */
  __IO uint32_t CTL1;                              /* !< (@ 0x00001104) Control 1 */
  __IO uint32_t CTL2;                              /* !< (@ 0x00001108) Control 2 */
  __IO uint32_t CTL3;                              /* !< (@ 0x0000110C) Control 3 */
       uint32_t RESERVED7[4];
  __I  uint32_t STAT;                              /* !< (@ 0x00001120) Status */
} COMP_Regs;

/*@}*/ /* end of group COMP */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* COMP Register Control Bits
******************************************************************************/

/* COMP_GEN_EVENT_IIDX Bits */
/* COMP_GEN_EVENT_IIDX[STAT] Bits */
#define COMP_GEN_EVENT_IIDX_STAT_OFS             (0)                             /* !< STAT Offset */
#define COMP_GEN_EVENT_IIDX_STAT_MASK            ((uint32_t)0x00000003U)         /* !< Interrupt index status */
#define COMP_GEN_EVENT_IIDX_STAT_NO_INTR         ((uint32_t)0x00000000U)         /* !< No pending interrupt */
#define COMP_GEN_EVENT_IIDX_STAT_COMPIFG         ((uint32_t)0x00000002U)         /* !< Comparator output interrupt */
#define COMP_GEN_EVENT_IIDX_STAT_COMPINVIFG      ((uint32_t)0x00000003U)         /* !< Comparator output inverted
                                                                                    interrupt */
#define COMP_GEN_EVENT_IIDX_STAT_OUTRDYIFG       ((uint32_t)0x00000004U)         /* !< Comparator output ready interrupt */

/* COMP_GEN_EVENT_IMASK Bits */
/* COMP_GEN_EVENT_IMASK[COMPIFG] Bits */
#define COMP_GEN_EVENT_IMASK_COMPIFG_OFS         (1)                             /* !< COMPIFG Offset */
#define COMP_GEN_EVENT_IMASK_COMPIFG_MASK        ((uint32_t)0x00000002U)         /* !< Masks COMPIFG */
#define COMP_GEN_EVENT_IMASK_COMPIFG_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define COMP_GEN_EVENT_IMASK_COMPIFG_SET         ((uint32_t)0x00000002U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* COMP_GEN_EVENT_IMASK[COMPINVIFG] Bits */
#define COMP_GEN_EVENT_IMASK_COMPINVIFG_OFS      (2)                             /* !< COMPINVIFG Offset */
#define COMP_GEN_EVENT_IMASK_COMPINVIFG_MASK     ((uint32_t)0x00000004U)         /* !< Masks COMPINVIFG */
#define COMP_GEN_EVENT_IMASK_COMPINVIFG_CLR      ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define COMP_GEN_EVENT_IMASK_COMPINVIFG_SET      ((uint32_t)0x00000004U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* COMP_GEN_EVENT_IMASK[OUTRDYIFG] Bits */
#define COMP_GEN_EVENT_IMASK_OUTRDYIFG_OFS       (3)                             /* !< OUTRDYIFG Offset */
#define COMP_GEN_EVENT_IMASK_OUTRDYIFG_MASK      ((uint32_t)0x00000008U)         /* !< Masks OUTRDYIFG */
#define COMP_GEN_EVENT_IMASK_OUTRDYIFG_CLR       ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define COMP_GEN_EVENT_IMASK_OUTRDYIFG_SET       ((uint32_t)0x00000008U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */

/* COMP_GEN_EVENT_RIS Bits */
/* COMP_GEN_EVENT_RIS[COMPIFG] Bits */
#define COMP_GEN_EVENT_RIS_COMPIFG_OFS           (1)                             /* !< COMPIFG Offset */
#define COMP_GEN_EVENT_RIS_COMPIFG_MASK          ((uint32_t)0x00000002U)         /* !< Raw interrupt status for comparator
                                                                                    output interrupt flag. The IES bit
                                                                                    defines the transition of the
                                                                                    comparator output setting this bit. */
#define COMP_GEN_EVENT_RIS_COMPIFG_CLR           ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define COMP_GEN_EVENT_RIS_COMPIFG_SET           ((uint32_t)0x00000002U)         /* !< Interrupt pending */
/* COMP_GEN_EVENT_RIS[COMPINVIFG] Bits */
#define COMP_GEN_EVENT_RIS_COMPINVIFG_OFS        (2)                             /* !< COMPINVIFG Offset */
#define COMP_GEN_EVENT_RIS_COMPINVIFG_MASK       ((uint32_t)0x00000004U)         /* !< Raw interrupt status for comparator
                                                                                    output inverted interrupt flag. The
                                                                                    IES bit defines the transition of the
                                                                                    comparator output setting this bit. */
#define COMP_GEN_EVENT_RIS_COMPINVIFG_CLR        ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define COMP_GEN_EVENT_RIS_COMPINVIFG_SET        ((uint32_t)0x00000004U)         /* !< Interrupt pending */
/* COMP_GEN_EVENT_RIS[OUTRDYIFG] Bits */
#define COMP_GEN_EVENT_RIS_OUTRDYIFG_OFS         (3)                             /* !< OUTRDYIFG Offset */
#define COMP_GEN_EVENT_RIS_OUTRDYIFG_MASK        ((uint32_t)0x00000008U)         /* !< Raw interrupt status for comparator
                                                                                    output ready interrupt flag. This bit
                                                                                    is set when the comparator output is
                                                                                    valid. */
#define COMP_GEN_EVENT_RIS_OUTRDYIFG_CLR         ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define COMP_GEN_EVENT_RIS_OUTRDYIFG_SET         ((uint32_t)0x00000008U)         /* !< Interrupt pending */

/* COMP_GEN_EVENT_MIS Bits */
/* COMP_GEN_EVENT_MIS[COMPIFG] Bits */
#define COMP_GEN_EVENT_MIS_COMPIFG_OFS           (1)                             /* !< COMPIFG Offset */
#define COMP_GEN_EVENT_MIS_COMPIFG_MASK          ((uint32_t)0x00000002U)         /* !< Masked interrupt status for COMPIFG */
#define COMP_GEN_EVENT_MIS_COMPIFG_CLR           ((uint32_t)0x00000000U)         /* !< COMPIFG does not request an
                                                                                    interrupt service routine */
#define COMP_GEN_EVENT_MIS_COMPIFG_SET           ((uint32_t)0x00000002U)         /* !< COMPIFG requests an interrupt
                                                                                    service routine */
/* COMP_GEN_EVENT_MIS[COMPINVIFG] Bits */
#define COMP_GEN_EVENT_MIS_COMPINVIFG_OFS        (2)                             /* !< COMPINVIFG Offset */
#define COMP_GEN_EVENT_MIS_COMPINVIFG_MASK       ((uint32_t)0x00000004U)         /* !< Masked interrupt status for
                                                                                    COMPINVIFG */
#define COMP_GEN_EVENT_MIS_COMPINVIFG_CLR        ((uint32_t)0x00000000U)         /* !< COMPINVIFG does not request an
                                                                                    interrupt service routine */
#define COMP_GEN_EVENT_MIS_COMPINVIFG_SET        ((uint32_t)0x00000004U)         /* !< COMPINVIFG requests an interrupt
                                                                                    service routine */
/* COMP_GEN_EVENT_MIS[OUTRDYIFG] Bits */
#define COMP_GEN_EVENT_MIS_OUTRDYIFG_OFS         (3)                             /* !< OUTRDYIFG Offset */
#define COMP_GEN_EVENT_MIS_OUTRDYIFG_MASK        ((uint32_t)0x00000008U)         /* !< Masked interrupt status for
                                                                                    OUTRDYIFG */
#define COMP_GEN_EVENT_MIS_OUTRDYIFG_CLR         ((uint32_t)0x00000000U)         /* !< OUTRDYIFG does not request an
                                                                                    interrupt service routine */
#define COMP_GEN_EVENT_MIS_OUTRDYIFG_SET         ((uint32_t)0x00000008U)         /* !< OUTRDYIFG requests an interrupt
                                                                                    service routine */

/* COMP_GEN_EVENT_ISET Bits */
/* COMP_GEN_EVENT_ISET[COMPIFG] Bits */
#define COMP_GEN_EVENT_ISET_COMPIFG_OFS          (1)                             /* !< COMPIFG Offset */
#define COMP_GEN_EVENT_ISET_COMPIFG_MASK         ((uint32_t)0x00000002U)         /* !< Sets COMPIFG in RIS register */
#define COMP_GEN_EVENT_ISET_COMPIFG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_GEN_EVENT_ISET_COMPIFG_SET          ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to COMPIFG is
                                                                                    set */
/* COMP_GEN_EVENT_ISET[COMPINVIFG] Bits */
#define COMP_GEN_EVENT_ISET_COMPINVIFG_OFS       (2)                             /* !< COMPINVIFG Offset */
#define COMP_GEN_EVENT_ISET_COMPINVIFG_MASK      ((uint32_t)0x00000004U)         /* !< Sets COMPINVIFG in RIS register */
#define COMP_GEN_EVENT_ISET_COMPINVIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_GEN_EVENT_ISET_COMPINVIFG_SET       ((uint32_t)0x00000004U)         /* !< RIS bit corresponding to COMPINVIFG
                                                                                    is set */
/* COMP_GEN_EVENT_ISET[OUTRDYIFG] Bits */
#define COMP_GEN_EVENT_ISET_OUTRDYIFG_OFS        (3)                             /* !< OUTRDYIFG Offset */
#define COMP_GEN_EVENT_ISET_OUTRDYIFG_MASK       ((uint32_t)0x00000008U)         /* !< Sets OUTRDYIFG in RIS register */
#define COMP_GEN_EVENT_ISET_OUTRDYIFG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_GEN_EVENT_ISET_OUTRDYIFG_SET        ((uint32_t)0x00000008U)         /* !< RIS bit corresponding to OUTRDYIFG
                                                                                    is set */

/* COMP_GEN_EVENT_ICLR Bits */
/* COMP_GEN_EVENT_ICLR[COMPIFG] Bits */
#define COMP_GEN_EVENT_ICLR_COMPIFG_OFS          (1)                             /* !< COMPIFG Offset */
#define COMP_GEN_EVENT_ICLR_COMPIFG_MASK         ((uint32_t)0x00000002U)         /* !< Clears COMPIFG in RIS register */
#define COMP_GEN_EVENT_ICLR_COMPIFG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_GEN_EVENT_ICLR_COMPIFG_CLR          ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to COMPIFG is
                                                                                    cleared */
/* COMP_GEN_EVENT_ICLR[COMPINVIFG] Bits */
#define COMP_GEN_EVENT_ICLR_COMPINVIFG_OFS       (2)                             /* !< COMPINVIFG Offset */
#define COMP_GEN_EVENT_ICLR_COMPINVIFG_MASK      ((uint32_t)0x00000004U)         /* !< Clears COMPINVIFG in RIS register */
#define COMP_GEN_EVENT_ICLR_COMPINVIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_GEN_EVENT_ICLR_COMPINVIFG_CLR       ((uint32_t)0x00000004U)         /* !< RIS bit corresponding to COMPINVIFG
                                                                                    is cleared */
/* COMP_GEN_EVENT_ICLR[OUTRDYIFG] Bits */
#define COMP_GEN_EVENT_ICLR_OUTRDYIFG_OFS        (3)                             /* !< OUTRDYIFG Offset */
#define COMP_GEN_EVENT_ICLR_OUTRDYIFG_MASK       ((uint32_t)0x00000008U)         /* !< Clears OUTRDYIFG in RIS register */
#define COMP_GEN_EVENT_ICLR_OUTRDYIFG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_GEN_EVENT_ICLR_OUTRDYIFG_CLR        ((uint32_t)0x00000008U)         /* !< RIS bit corresponding to OUTRDYIFG
                                                                                    is cleared */

/* COMP_CPU_INT_IIDX Bits */
/* COMP_CPU_INT_IIDX[STAT] Bits */
#define COMP_CPU_INT_IIDX_STAT_OFS               (0)                             /* !< STAT Offset */
#define COMP_CPU_INT_IIDX_STAT_MASK              ((uint32_t)0x00000003U)         /* !< Interrupt index status */
#define COMP_CPU_INT_IIDX_STAT_NO_INTR           ((uint32_t)0x00000000U)         /* !< No pending interrupt */
#define COMP_CPU_INT_IIDX_STAT_COMPIFG           ((uint32_t)0x00000002U)         /* !< Comparator output interrupt */
#define COMP_CPU_INT_IIDX_STAT_COMPINVIFG        ((uint32_t)0x00000003U)         /* !< Comparator output inverted
                                                                                    interrupt */
#define COMP_CPU_INT_IIDX_STAT_OUTRDYIFG         ((uint32_t)0x00000004U)         /* !< Comparator output ready interrupt */

/* COMP_CPU_INT_IMASK Bits */
/* COMP_CPU_INT_IMASK[COMPIFG] Bits */
#define COMP_CPU_INT_IMASK_COMPIFG_OFS           (1)                             /* !< COMPIFG Offset */
#define COMP_CPU_INT_IMASK_COMPIFG_MASK          ((uint32_t)0x00000002U)         /* !< Masks COMPIFG */
#define COMP_CPU_INT_IMASK_COMPIFG_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define COMP_CPU_INT_IMASK_COMPIFG_SET           ((uint32_t)0x00000002U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* COMP_CPU_INT_IMASK[COMPINVIFG] Bits */
#define COMP_CPU_INT_IMASK_COMPINVIFG_OFS        (2)                             /* !< COMPINVIFG Offset */
#define COMP_CPU_INT_IMASK_COMPINVIFG_MASK       ((uint32_t)0x00000004U)         /* !< Masks COMPINVIFG */
#define COMP_CPU_INT_IMASK_COMPINVIFG_CLR        ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define COMP_CPU_INT_IMASK_COMPINVIFG_SET        ((uint32_t)0x00000004U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* COMP_CPU_INT_IMASK[OUTRDYIFG] Bits */
#define COMP_CPU_INT_IMASK_OUTRDYIFG_OFS         (3)                             /* !< OUTRDYIFG Offset */
#define COMP_CPU_INT_IMASK_OUTRDYIFG_MASK        ((uint32_t)0x00000008U)         /* !< Masks OUTRDYIFG */
#define COMP_CPU_INT_IMASK_OUTRDYIFG_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define COMP_CPU_INT_IMASK_OUTRDYIFG_SET         ((uint32_t)0x00000008U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */

/* COMP_CPU_INT_RIS Bits */
/* COMP_CPU_INT_RIS[COMPIFG] Bits */
#define COMP_CPU_INT_RIS_COMPIFG_OFS             (1)                             /* !< COMPIFG Offset */
#define COMP_CPU_INT_RIS_COMPIFG_MASK            ((uint32_t)0x00000002U)         /* !< Raw interrupt status for comparator
                                                                                    output interrupt flag. The IES bit
                                                                                    defines the transition of the
                                                                                    comparator output setting this bit. */
#define COMP_CPU_INT_RIS_COMPIFG_CLR             ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define COMP_CPU_INT_RIS_COMPIFG_SET             ((uint32_t)0x00000002U)         /* !< Interrupt pending */
/* COMP_CPU_INT_RIS[COMPINVIFG] Bits */
#define COMP_CPU_INT_RIS_COMPINVIFG_OFS          (2)                             /* !< COMPINVIFG Offset */
#define COMP_CPU_INT_RIS_COMPINVIFG_MASK         ((uint32_t)0x00000004U)         /* !< Raw interrupt status for comparator
                                                                                    output inverted interrupt flag. The
                                                                                    IES bit defines the transition of the
                                                                                    comparator output setting this bit. */
#define COMP_CPU_INT_RIS_COMPINVIFG_CLR          ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define COMP_CPU_INT_RIS_COMPINVIFG_SET          ((uint32_t)0x00000004U)         /* !< Interrupt pending */
/* COMP_CPU_INT_RIS[OUTRDYIFG] Bits */
#define COMP_CPU_INT_RIS_OUTRDYIFG_OFS           (3)                             /* !< OUTRDYIFG Offset */
#define COMP_CPU_INT_RIS_OUTRDYIFG_MASK          ((uint32_t)0x00000008U)         /* !< Raw interrupt status for comparator
                                                                                    output ready interrupt flag. This bit
                                                                                    is set when the comparator output is
                                                                                    valid. */
#define COMP_CPU_INT_RIS_OUTRDYIFG_CLR           ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define COMP_CPU_INT_RIS_OUTRDYIFG_SET           ((uint32_t)0x00000008U)         /* !< Interrupt pending */

/* COMP_CPU_INT_MIS Bits */
/* COMP_CPU_INT_MIS[COMPIFG] Bits */
#define COMP_CPU_INT_MIS_COMPIFG_OFS             (1)                             /* !< COMPIFG Offset */
#define COMP_CPU_INT_MIS_COMPIFG_MASK            ((uint32_t)0x00000002U)         /* !< Masked interrupt status for COMPIFG */
#define COMP_CPU_INT_MIS_COMPIFG_CLR             ((uint32_t)0x00000000U)         /* !< COMPIFG does not request an
                                                                                    interrupt service routine */
#define COMP_CPU_INT_MIS_COMPIFG_SET             ((uint32_t)0x00000002U)         /* !< COMPIFG requests an interrupt
                                                                                    service routine */
/* COMP_CPU_INT_MIS[COMPINVIFG] Bits */
#define COMP_CPU_INT_MIS_COMPINVIFG_OFS          (2)                             /* !< COMPINVIFG Offset */
#define COMP_CPU_INT_MIS_COMPINVIFG_MASK         ((uint32_t)0x00000004U)         /* !< Masked interrupt status for
                                                                                    COMPINVIFG */
#define COMP_CPU_INT_MIS_COMPINVIFG_CLR          ((uint32_t)0x00000000U)         /* !< COMPINVIFG does not request an
                                                                                    interrupt service routine */
#define COMP_CPU_INT_MIS_COMPINVIFG_SET          ((uint32_t)0x00000004U)         /* !< COMPINVIFG requests an interrupt
                                                                                    service routine */
/* COMP_CPU_INT_MIS[OUTRDYIFG] Bits */
#define COMP_CPU_INT_MIS_OUTRDYIFG_OFS           (3)                             /* !< OUTRDYIFG Offset */
#define COMP_CPU_INT_MIS_OUTRDYIFG_MASK          ((uint32_t)0x00000008U)         /* !< Masked interrupt status for
                                                                                    OUTRDYIFG */
#define COMP_CPU_INT_MIS_OUTRDYIFG_CLR           ((uint32_t)0x00000000U)         /* !< OUTRDYIFG does not request an
                                                                                    interrupt service routine */
#define COMP_CPU_INT_MIS_OUTRDYIFG_SET           ((uint32_t)0x00000008U)         /* !< OUTRDYIFG requests an interrupt
                                                                                    service routine */

/* COMP_CPU_INT_ISET Bits */
/* COMP_CPU_INT_ISET[COMPIFG] Bits */
#define COMP_CPU_INT_ISET_COMPIFG_OFS            (1)                             /* !< COMPIFG Offset */
#define COMP_CPU_INT_ISET_COMPIFG_MASK           ((uint32_t)0x00000002U)         /* !< Sets COMPIFG in RIS register */
#define COMP_CPU_INT_ISET_COMPIFG_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_CPU_INT_ISET_COMPIFG_SET            ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to COMPIFG is
                                                                                    set */
/* COMP_CPU_INT_ISET[COMPINVIFG] Bits */
#define COMP_CPU_INT_ISET_COMPINVIFG_OFS         (2)                             /* !< COMPINVIFG Offset */
#define COMP_CPU_INT_ISET_COMPINVIFG_MASK        ((uint32_t)0x00000004U)         /* !< Sets COMPINVIFG in RIS register */
#define COMP_CPU_INT_ISET_COMPINVIFG_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_CPU_INT_ISET_COMPINVIFG_SET         ((uint32_t)0x00000004U)         /* !< RIS bit corresponding to COMPINVIFG
                                                                                    is set */
/* COMP_CPU_INT_ISET[OUTRDYIFG] Bits */
#define COMP_CPU_INT_ISET_OUTRDYIFG_OFS          (3)                             /* !< OUTRDYIFG Offset */
#define COMP_CPU_INT_ISET_OUTRDYIFG_MASK         ((uint32_t)0x00000008U)         /* !< Sets OUTRDYIFG in RIS register */
#define COMP_CPU_INT_ISET_OUTRDYIFG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_CPU_INT_ISET_OUTRDYIFG_SET          ((uint32_t)0x00000008U)         /* !< RIS bit corresponding to OUTRDYIFG
                                                                                    is set */

/* COMP_CPU_INT_ICLR Bits */
/* COMP_CPU_INT_ICLR[COMPIFG] Bits */
#define COMP_CPU_INT_ICLR_COMPIFG_OFS            (1)                             /* !< COMPIFG Offset */
#define COMP_CPU_INT_ICLR_COMPIFG_MASK           ((uint32_t)0x00000002U)         /* !< Clears COMPIFG in RIS register */
#define COMP_CPU_INT_ICLR_COMPIFG_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_CPU_INT_ICLR_COMPIFG_CLR            ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to COMPIFG is
                                                                                    cleared */
/* COMP_CPU_INT_ICLR[COMPINVIFG] Bits */
#define COMP_CPU_INT_ICLR_COMPINVIFG_OFS         (2)                             /* !< COMPINVIFG Offset */
#define COMP_CPU_INT_ICLR_COMPINVIFG_MASK        ((uint32_t)0x00000004U)         /* !< Clears COMPINVIFG in RIS register */
#define COMP_CPU_INT_ICLR_COMPINVIFG_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_CPU_INT_ICLR_COMPINVIFG_CLR         ((uint32_t)0x00000004U)         /* !< RIS bit corresponding to COMPINVIFG
                                                                                    is cleared */
/* COMP_CPU_INT_ICLR[OUTRDYIFG] Bits */
#define COMP_CPU_INT_ICLR_OUTRDYIFG_OFS          (3)                             /* !< OUTRDYIFG Offset */
#define COMP_CPU_INT_ICLR_OUTRDYIFG_MASK         ((uint32_t)0x00000008U)         /* !< Clears OUTRDYIFG in RIS register */
#define COMP_CPU_INT_ICLR_OUTRDYIFG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define COMP_CPU_INT_ICLR_OUTRDYIFG_CLR          ((uint32_t)0x00000008U)         /* !< RIS bit corresponding to OUTRDYIFG
                                                                                    is cleared */

/* COMP_PWREN Bits */
/* COMP_PWREN[ENABLE] Bits */
#define COMP_PWREN_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define COMP_PWREN_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< Enable the power */
#define COMP_PWREN_ENABLE_DISABLE                ((uint32_t)0x00000000U)         /* !< Disable Power */
#define COMP_PWREN_ENABLE_ENABLE                 ((uint32_t)0x00000001U)         /* !< Enable Power */
/* COMP_PWREN[KEY] Bits */
#define COMP_PWREN_KEY_OFS                       (24)                            /* !< KEY Offset */
#define COMP_PWREN_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define COMP_PWREN_KEY_UNLOCK_W                  ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* COMP_RSTCTL Bits */
/* COMP_RSTCTL[RESETSTKYCLR] Bits */
#define COMP_RSTCTL_RESETSTKYCLR_OFS             (1)                             /* !< RESETSTKYCLR Offset */
#define COMP_RSTCTL_RESETSTKYCLR_MASK            ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define COMP_RSTCTL_RESETSTKYCLR_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define COMP_RSTCTL_RESETSTKYCLR_CLR             ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* COMP_RSTCTL[RESETASSERT] Bits */
#define COMP_RSTCTL_RESETASSERT_OFS              (0)                             /* !< RESETASSERT Offset */
#define COMP_RSTCTL_RESETASSERT_MASK             ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define COMP_RSTCTL_RESETASSERT_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define COMP_RSTCTL_RESETASSERT_ASSERT           ((uint32_t)0x00000001U)         /* !< Assert reset */
/* COMP_RSTCTL[KEY] Bits */
#define COMP_RSTCTL_KEY_OFS                      (24)                            /* !< KEY Offset */
#define COMP_RSTCTL_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define COMP_RSTCTL_KEY_UNLOCK_W                 ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* COMP_CLKCFG Bits */
/* COMP_CLKCFG[KEY] Bits */
#define COMP_CLKCFG_KEY_OFS                      (24)                            /* !< KEY Offset */
#define COMP_CLKCFG_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define COMP_CLKCFG_KEY_UNLOCK                   ((uint32_t)0xA9000000U)         /* !< Key value to be used in writing to
                                                                                    this register for the write to take
                                                                                    effect. */
/* COMP_CLKCFG[BLOCKASYNC] Bits */
#define COMP_CLKCFG_BLOCKASYNC_OFS               (8)                             /* !< BLOCKASYNC Offset */
#define COMP_CLKCFG_BLOCKASYNC_MASK              ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define COMP_CLKCFG_BLOCKASYNC_DISABLE           ((uint32_t)0x00000000U)         /* !< disable COMP to request SYSOSC */
#define COMP_CLKCFG_BLOCKASYNC_ENABLE            ((uint32_t)0x00000100U)         /* !< enable COMP to request SYSOSC */

/* COMP_GPRCM_STAT Bits */
/* COMP_GPRCM_STAT[RESETSTKY] Bits */
#define COMP_GPRCM_STAT_RESETSTKY_OFS            (16)                            /* !< RESETSTKY Offset */
#define COMP_GPRCM_STAT_RESETSTKY_MASK           ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define COMP_GPRCM_STAT_RESETSTKY_NORES          ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define COMP_GPRCM_STAT_RESETSTKY_RESET          ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* COMP_FSUB_0 Bits */
/* COMP_FSUB_0[CHANID] Bits */
#define COMP_FSUB_0_CHANID_OFS                   (0)                             /* !< CHANID Offset */
#define COMP_FSUB_0_CHANID_MASK                  ((uint32_t)0x00007FFFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define COMP_FSUB_0_CHANID_MNIMUM                ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define COMP_FSUB_0_CHANID_UNCONNECTED           ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define COMP_FSUB_0_CHANID_MAXIMUM               ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* COMP_FSUB_1 Bits */
/* COMP_FSUB_1[CHANID] Bits */
#define COMP_FSUB_1_CHANID_OFS                   (0)                             /* !< CHANID Offset */
#define COMP_FSUB_1_CHANID_MASK                  ((uint32_t)0x00007FFFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define COMP_FSUB_1_CHANID_MNIMUM                ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define COMP_FSUB_1_CHANID_UNCONNECTED           ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define COMP_FSUB_1_CHANID_MAXIMUM               ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* COMP_FPUB_1 Bits */
/* COMP_FPUB_1[CHANID] Bits */
#define COMP_FPUB_1_CHANID_OFS                   (0)                             /* !< CHANID Offset */
#define COMP_FPUB_1_CHANID_MASK                  ((uint32_t)0x00007FFFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define COMP_FPUB_1_CHANID_MNIMUM                ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define COMP_FPUB_1_CHANID_UNCONNECTED           ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define COMP_FPUB_1_CHANID_MAXIMUM               ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* COMP_EVT_MODE Bits */
/* COMP_EVT_MODE[INT0_CFG] Bits */
#define COMP_EVT_MODE_INT0_CFG_OFS               (0)                             /* !< INT0_CFG Offset */
#define COMP_EVT_MODE_INT0_CFG_MASK              ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to CPU_INT */
#define COMP_EVT_MODE_INT0_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define COMP_EVT_MODE_INT0_CFG_SOFTWARE          ((uint32_t)0x00000001U)         /* !< Event handled by software. Software
                                                                                    must clear the associated RIS flag. */
#define COMP_EVT_MODE_INT0_CFG_HARDWARE          ((uint32_t)0x00000002U)         /* !< Event handled by hardware. The
                                                                                    hardware (another module) clears
                                                                                    automatically the associated RIS
                                                                                    flag. */
/* COMP_EVT_MODE[EVT1_CFG] Bits */
#define COMP_EVT_MODE_EVT1_CFG_OFS               (2)                             /* !< EVT1_CFG Offset */
#define COMP_EVT_MODE_EVT1_CFG_MASK              ((uint32_t)0x0000000CU)         /* !< Event line mode select for event
                                                                                    corresponding to GEN_EVENT */
#define COMP_EVT_MODE_EVT1_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define COMP_EVT_MODE_EVT1_CFG_SOFTWARE          ((uint32_t)0x00000004U)         /* !< Event handled by software. Software
                                                                                    must clear the associated RIS flag. */
#define COMP_EVT_MODE_EVT1_CFG_HARDWARE          ((uint32_t)0x00000008U)         /* !< Event handled by hardware. The
                                                                                    hardware (another module) clears
                                                                                    automatically the associated RIS
                                                                                    flag. */

/* COMP_DESC Bits */
/* COMP_DESC[MINREV] Bits */
#define COMP_DESC_MINREV_OFS                     (0)                             /* !< MINREV Offset */
#define COMP_DESC_MINREV_MASK                    ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
/* COMP_DESC[MAJREV] Bits */
#define COMP_DESC_MAJREV_OFS                     (4)                             /* !< MAJREV Offset */
#define COMP_DESC_MAJREV_MASK                    ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
/* COMP_DESC[FEATUREVER] Bits */
#define COMP_DESC_FEATUREVER_OFS                 (12)                            /* !< FEATUREVER Offset */
#define COMP_DESC_FEATUREVER_MASK                ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
/* COMP_DESC[MODULEID] Bits */
#define COMP_DESC_MODULEID_OFS                   (16)                            /* !< MODULEID Offset */
#define COMP_DESC_MODULEID_MASK                  ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */

/* COMP_CTL0 Bits */
/* COMP_CTL0[IPSEL] Bits */
#define COMP_CTL0_IPSEL_OFS                      (0)                             /* !< IPSEL Offset */
#define COMP_CTL0_IPSEL_MASK                     ((uint32_t)0x00000007U)         /* !< Channel input selected for the
                                                                                    positive terminal of the comparator
                                                                                    if IPEN is set to 1. */
#define COMP_CTL0_IPSEL_CH_0                     ((uint32_t)0x00000000U)         /* !< Channel 0 selected */
#define COMP_CTL0_IPSEL_CH_1                     ((uint32_t)0x00000001U)         /* !< Channel 1 selected */
#define COMP_CTL0_IPSEL_CH_2                     ((uint32_t)0x00000002U)         /* !< Channel 2 selected */
#define COMP_CTL0_IPSEL_CH_3                     ((uint32_t)0x00000003U)         /* !< Channel 3 selected */
#define COMP_CTL0_IPSEL_CH_4                     ((uint32_t)0x00000004U)         /* !< Channel 4 selected */
#define COMP_CTL0_IPSEL_CH_5                     ((uint32_t)0x00000005U)         /* !< Channel 5 selected */
#define COMP_CTL0_IPSEL_CH_6                     ((uint32_t)0x00000006U)         /* !< Channel 6 selected */
#define COMP_CTL0_IPSEL_CH_7                     ((uint32_t)0x00000007U)         /* !< Channel 7  selected */
/* COMP_CTL0[IPEN] Bits */
#define COMP_CTL0_IPEN_OFS                       (15)                            /* !< IPEN Offset */
#define COMP_CTL0_IPEN_MASK                      ((uint32_t)0x00008000U)         /* !< Channel input enable for the
                                                                                    positive terminal of the comparator. */
#define COMP_CTL0_IPEN_DISABLE                   ((uint32_t)0x00000000U)         /* !< Selected analog input channel for
                                                                                    positive terminal is disabled */
#define COMP_CTL0_IPEN_ENABLE                    ((uint32_t)0x00008000U)         /* !< Selected analog input channel for
                                                                                    positive terminal is enabled */
/* COMP_CTL0[IMEN] Bits */
#define COMP_CTL0_IMEN_OFS                       (31)                            /* !< IMEN Offset */
#define COMP_CTL0_IMEN_MASK                      ((uint32_t)0x80000000U)         /* !< Channel input enable for the
                                                                                    negative terminal of the comparator. */
#define COMP_CTL0_IMEN_DISABLE                   ((uint32_t)0x00000000U)         /* !< Selected analog input channel for
                                                                                    negative terminal is disabled */
#define COMP_CTL0_IMEN_ENABLE                    ((uint32_t)0x80000000U)         /* !< Selected analog input channel for
                                                                                    negative terminal is enabled */
/* COMP_CTL0[IMSEL] Bits */
#define COMP_CTL0_IMSEL_OFS                      (16)                            /* !< IMSEL Offset */
#define COMP_CTL0_IMSEL_MASK                     ((uint32_t)0x00070000U)         /* !< Channel input selected for the
                                                                                    negative terminal of the comparator
                                                                                    if IMEN is set to 1. */
#define COMP_CTL0_IMSEL_CH_0                     ((uint32_t)0x00000000U)         /* !< Channel 0 selected */
#define COMP_CTL0_IMSEL_CH_1                     ((uint32_t)0x00010000U)         /* !< Channel 1 selected */
#define COMP_CTL0_IMSEL_CH_2                     ((uint32_t)0x00020000U)         /* !< Channel 2 selected */
#define COMP_CTL0_IMSEL_CH_3                     ((uint32_t)0x00030000U)         /* !< Channel 3 selected */
#define COMP_CTL0_IMSEL_CH_4                     ((uint32_t)0x00040000U)         /* !< Channel 4 selected */
#define COMP_CTL0_IMSEL_CH_5                     ((uint32_t)0x00050000U)         /* !< Channel 5 selected */
#define COMP_CTL0_IMSEL_CH_6                     ((uint32_t)0x00060000U)         /* !< Channel 6 selected */
#define COMP_CTL0_IMSEL_CH_7                     ((uint32_t)0x00070000U)         /* !< Channel 7 selected */

/* COMP_CTL1 Bits */
/* COMP_CTL1[ENABLE] Bits */
#define COMP_CTL1_ENABLE_OFS                     (0)                             /* !< ENABLE Offset */
#define COMP_CTL1_ENABLE_MASK                    ((uint32_t)0x00000001U)         /* !< This bit turns on the comparator.
                                                                                    When the comparator is turned off it
                                                                                    consumes no power. */
#define COMP_CTL1_ENABLE_OFF                     ((uint32_t)0x00000000U)         /* !< Comparator is off */
#define COMP_CTL1_ENABLE_ON                      ((uint32_t)0x00000001U)         /* !< Comparator is on */
/* COMP_CTL1[MODE] Bits */
#define COMP_CTL1_MODE_OFS                       (1)                             /* !< MODE Offset */
#define COMP_CTL1_MODE_MASK                      ((uint32_t)0x00000002U)         /* !< This bit selects the comparator
                                                                                    operating mode. */
#define COMP_CTL1_MODE_FAST                      ((uint32_t)0x00000000U)         /* !< Comparator is in fast mode */
#define COMP_CTL1_MODE_ULP                       ((uint32_t)0x00000002U)         /* !< Comparator is in ultra-low power
                                                                                    mode */
/* COMP_CTL1[EXCH] Bits */
#define COMP_CTL1_EXCH_OFS                       (2)                             /* !< EXCH Offset */
#define COMP_CTL1_EXCH_MASK                      ((uint32_t)0x00000004U)         /* !< This bit exchanges the comparator
                                                                                    inputs and inverts the comparator
                                                                                    output. */
#define COMP_CTL1_EXCH_NO_EXC                    ((uint32_t)0x00000000U)         /* !< Comparator inputs not exchanged and
                                                                                    output not inverted */
#define COMP_CTL1_EXCH_EXC                       ((uint32_t)0x00000004U)         /* !< Comparator inputs exchanged and
                                                                                    output inverted */
/* COMP_CTL1[SHORT] Bits */
#define COMP_CTL1_SHORT_OFS                      (3)                             /* !< SHORT Offset */
#define COMP_CTL1_SHORT_MASK                     ((uint32_t)0x00000008U)         /* !< This bit shorts the positive and
                                                                                    negative input terminals of the
                                                                                    comparator. */
#define COMP_CTL1_SHORT_NO_SHT                   ((uint32_t)0x00000000U)         /* !< Comparator positive and negative
                                                                                    input terminals are not shorted */
#define COMP_CTL1_SHORT_SHT                      ((uint32_t)0x00000008U)         /* !< Comparator positive and negative
                                                                                    input terminals are shorted */
/* COMP_CTL1[IES] Bits */
#define COMP_CTL1_IES_OFS                        (4)                             /* !< IES Offset */
#define COMP_CTL1_IES_MASK                       ((uint32_t)0x00000010U)         /* !< This bit selected the interrupt
                                                                                    edge for COMPIFG and COMPINVIFG. */
#define COMP_CTL1_IES_RISING                     ((uint32_t)0x00000000U)         /* !< Rising edge sets COMPIFG and
                                                                                    falling edge sets COMPINVIFG */
#define COMP_CTL1_IES_FALLING                    ((uint32_t)0x00000010U)         /* !< Falling edge sets COMPIFG and
                                                                                    rising edge sets COMPINVIFG */
/* COMP_CTL1[HYST] Bits */
#define COMP_CTL1_HYST_OFS                       (5)                             /* !< HYST Offset */
#define COMP_CTL1_HYST_MASK                      ((uint32_t)0x00000060U)         /* !< These bits select the hysteresis
                                                                                    setting of the comparator. */
#define COMP_CTL1_HYST_NO_HYS                    ((uint32_t)0x00000000U)         /* !< No hysteresis */
#define COMP_CTL1_HYST_LOW_HYS                   ((uint32_t)0x00000020U)         /* !< Low hysteresis, typical 10mV */
#define COMP_CTL1_HYST_MED_HYS                   ((uint32_t)0x00000040U)         /* !< Medium hysteresis, typical 20mV */
#define COMP_CTL1_HYST_HIGH_HYS                  ((uint32_t)0x00000060U)         /* !< High hysteresis, typical 30mV */
/* COMP_CTL1[OUTPOL] Bits */
#define COMP_CTL1_OUTPOL_OFS                     (7)                             /* !< OUTPOL Offset */
#define COMP_CTL1_OUTPOL_MASK                    ((uint32_t)0x00000080U)         /* !< This bit selects the comparator
                                                                                    output polarity. */
#define COMP_CTL1_OUTPOL_NON_INV                 ((uint32_t)0x00000000U)         /* !< Comparator output is non-inverted */
#define COMP_CTL1_OUTPOL_INV                     ((uint32_t)0x00000080U)         /* !< Comparator output is inverted */
/* COMP_CTL1[FLTEN] Bits */
#define COMP_CTL1_FLTEN_OFS                      (8)                             /* !< FLTEN Offset */
#define COMP_CTL1_FLTEN_MASK                     ((uint32_t)0x00000100U)         /* !< This bit enables the analog filter
                                                                                    at comparator output. */
#define COMP_CTL1_FLTEN_DISABLE                  ((uint32_t)0x00000000U)         /* !< Comparator output filter is
                                                                                    disabled */
#define COMP_CTL1_FLTEN_ENABLE                   ((uint32_t)0x00000100U)         /* !< Comparator output filter is enabled */
/* COMP_CTL1[FLTDLY] Bits */
#define COMP_CTL1_FLTDLY_OFS                     (9)                             /* !< FLTDLY Offset */
#define COMP_CTL1_FLTDLY_MASK                    ((uint32_t)0x00000600U)         /* !< These bits select the comparator
                                                                                    output filter delay. See the
                                                                                    device-specific data sheet for
                                                                                    specific values on comparator
                                                                                    propagation delay for different
                                                                                    filter delay settings. */
#define COMP_CTL1_FLTDLY_DLY_0                   ((uint32_t)0x00000000U)         /* !< Typical filter delay of 70 ns */
#define COMP_CTL1_FLTDLY_DLY_1                   ((uint32_t)0x00000200U)         /* !< Typical filter delay of 500 ns */
#define COMP_CTL1_FLTDLY_DLY_2                   ((uint32_t)0x00000400U)         /* !< Typical filter delay of 1200 ns */
#define COMP_CTL1_FLTDLY_DLY_3                   ((uint32_t)0x00000600U)         /* !< Typical filter delay of 2700 ns */
/* COMP_CTL1[WINCOMPEN] Bits */
#define COMP_CTL1_WINCOMPEN_OFS                  (12)                            /* !< WINCOMPEN Offset */
#define COMP_CTL1_WINCOMPEN_MASK                 ((uint32_t)0x00001000U)         /* !< This bit enables window comparator
                                                                                    operation of comparator. */
#define COMP_CTL1_WINCOMPEN_OFF                  ((uint32_t)0x00000000U)         /* !< window comparator is disable */
#define COMP_CTL1_WINCOMPEN_ON                   ((uint32_t)0x00001000U)         /* !< window comparator is enable */

/* COMP_CTL2 Bits */
/* COMP_CTL2[REFMODE] Bits */
#define COMP_CTL2_REFMODE_OFS                    (0)                             /* !< REFMODE Offset */
#define COMP_CTL2_REFMODE_MASK                   ((uint32_t)0x00000001U)         /* !< This bit requests ULP_REF bandgap
                                                                                    operation in fast mode(static) or low
                                                                                    power mode (sampled). The local
                                                                                    reference buffer and 8-bit DAC inside
                                                                                    comparator module are also configured
                                                                                    accordingly.  Fast mode operation
                                                                                    offers higher accuracy but consumes
                                                                                    higher current. Low power operation
                                                                                    consumes lower current but with
                                                                                    relaxed reference voltage accuracy.
                                                                                    Comparator requests for reference
                                                                                    voltage from ULP_REF only when REFLVL
                                                                                    > 0. */
#define COMP_CTL2_REFMODE_STATIC                 ((uint32_t)0x00000000U)         /* !< ULP_REF bandgap, local reference
                                                                                    buffer and 8-bit DAC inside
                                                                                    comparator operate in static mode. */
#define COMP_CTL2_REFMODE_SAMPLED                ((uint32_t)0x00000001U)         /* !< ULP_REF bandgap, local reference
                                                                                    buffer and 8-bit DAC inside
                                                                                    comparator operate in sampled mode. */
/* COMP_CTL2[REFSRC] Bits */
#define COMP_CTL2_REFSRC_OFS                     (3)                             /* !< REFSRC Offset */
#define COMP_CTL2_REFSRC_MASK                    ((uint32_t)0x00000038U)         /* !< These bits select the reference
                                                                                    source for the comparator. */
#define COMP_CTL2_REFSRC_OFF                     ((uint32_t)0x00000000U)         /* !< Reference voltage generator is
                                                                                    disabled (local reference buffer as
                                                                                    well as DAC). */
#define COMP_CTL2_REFSRC_VDDA_DAC                ((uint32_t)0x00000008U)         /* !< VDDA selected as the reference
                                                                                    source to DAC and DAC output applied
                                                                                    as reference to comparator. */
#define COMP_CTL2_REFSRC_VREF_DAC                ((uint32_t)0x00000010U)         /* !< VREF selected as reference to DAC
                                                                                    and DAC output applied as reference
                                                                                    to comparator. */
#define COMP_CTL2_REFSRC_VREF                    ((uint32_t)0x00000018U)         /* !< In devices where internal VREF is
                                                                                    buffered and hookedup to extrernal
                                                                                    VREF pin, VREF applied as reference
                                                                                    to comparator. DAC is switched off.
                                                                                    Note: In LEGO_A3, DAC is turned off
                                                                                    in this selection, in other deviced
                                                                                    DAC is kept on. */
#define COMP_CTL2_REFSRC_VDDA                    ((uint32_t)0x00000028U)         /* !< VDDA is used as comparator
                                                                                    reference. Note: In LEGO_A3, DAC is
                                                                                    turned off in this selection, in
                                                                                    other deviced DAC is kept on. */
#define COMP_CTL2_REFSRC_INTVREF_DAC             ((uint32_t)0x00000030U)         /* !< Internal reference selected as the
                                                                                    reference source to DAC and DAC
                                                                                    output applied as reference to
                                                                                    comparator. */
#define COMP_CTL2_REFSRC_INTVREF                 ((uint32_t)0x00000038U)         /* !< Internal VREF is used as the source
                                                                                    of comparator. Not all devices will
                                                                                    have this option. */
/* COMP_CTL2[REFSEL] Bits */
#define COMP_CTL2_REFSEL_OFS                     (7)                             /* !< REFSEL Offset */
#define COMP_CTL2_REFSEL_MASK                    ((uint32_t)0x00000080U)         /* !< This bit selects if the selected
                                                                                    reference voltage is applied to
                                                                                    positive or negative terminal of the
                                                                                    comparator. */
#define COMP_CTL2_REFSEL_POSITIVE                ((uint32_t)0x00000000U)         /* !< If EXCH bit is 0, the selected
                                                                                    reference is applied to positive
                                                                                    terminal. If EXCH bit is 1, the
                                                                                    selected reference is applied to
                                                                                    negative terminal. */
#define COMP_CTL2_REFSEL_NEGATIVE                ((uint32_t)0x00000080U)         /* !< If EXCH bit is 0, the selected
                                                                                    reference is applied to negative
                                                                                    terminal. If EXCH bit is 1, the
                                                                                    selected reference is applied to
                                                                                    positive terminal. */
/* COMP_CTL2[DACCTL] Bits */
#define COMP_CTL2_DACCTL_OFS                     (16)                            /* !< DACCTL Offset */
#define COMP_CTL2_DACCTL_MASK                    ((uint32_t)0x00010000U)         /* !< This bit determines if the
                                                                                    comparator output or DACSW bit
                                                                                    controls the selection between
                                                                                    DACCODE0 and DACCODE1. */
#define COMP_CTL2_DACCTL_COMPOUT_SEL             ((uint32_t)0x00000000U)         /* !< Comparator output controls
                                                                                    selection between DACCODE0 and
                                                                                    DACCODE1 */
#define COMP_CTL2_DACCTL_DACSW_SEL               ((uint32_t)0x00010000U)         /* !< DACSW bit controls selection
                                                                                    between DACCODE0 and DACCODE1 */
/* COMP_CTL2[DACSW] Bits */
#define COMP_CTL2_DACSW_OFS                      (17)                            /* !< DACSW Offset */
#define COMP_CTL2_DACSW_MASK                     ((uint32_t)0x00020000U)         /* !< This bit selects between DACCODE0
                                                                                    and DACCODE1 to 8-bit DAC when DACCTL
                                                                                    bit is 1. */
#define COMP_CTL2_DACSW_DACCODE0_SEL             ((uint32_t)0x00000000U)         /* !< DACCODE0 selected for 8-bit DAC */
#define COMP_CTL2_DACSW_DACCODE1_SEL             ((uint32_t)0x00020000U)         /* !< DACCODE1 selected for 8-bit DAC */
/* COMP_CTL2[BLANKSRC] Bits */
#define COMP_CTL2_BLANKSRC_OFS                   (8)                             /* !< BLANKSRC Offset */
#define COMP_CTL2_BLANKSRC_MASK                  ((uint32_t)0x00000700U)         /* !< These bits select the blanking
                                                                                    source for the comparator. */
#define COMP_CTL2_BLANKSRC_DISABLE               ((uint32_t)0x00000000U)         /* !< Blanking source disabled */
#define COMP_CTL2_BLANKSRC_BLANKSRC1             ((uint32_t)0x00000100U)         /* !< Select Blanking Source 1 */
#define COMP_CTL2_BLANKSRC_BLANKSRC2             ((uint32_t)0x00000200U)         /* !< Select Blanking Source 2 */
#define COMP_CTL2_BLANKSRC_BLANKSRC3             ((uint32_t)0x00000300U)         /* !< Select Blanking Source 3 */
#define COMP_CTL2_BLANKSRC_BLANKSRC4             ((uint32_t)0x00000400U)         /* !< Select Blanking Source 4 */
#define COMP_CTL2_BLANKSRC_BLANKSRC5             ((uint32_t)0x00000500U)         /* !< Select Blanking Source 5 */
#define COMP_CTL2_BLANKSRC_BLANKSRC6             ((uint32_t)0x00000600U)         /* !< Select Blanking Source 6 */
/* COMP_CTL2[SAMPMODE] Bits */
#define COMP_CTL2_SAMPMODE_OFS                   (24)                            /* !< SAMPMODE Offset */
#define COMP_CTL2_SAMPMODE_MASK                  ((uint32_t)0x01000000U)         /* !< Enable sampled mode of comparator. */
#define COMP_CTL2_SAMPMODE_DISABLE               ((uint32_t)0x00000000U)         /* !< Sampled mode disabled */
#define COMP_CTL2_SAMPMODE_ENABLE                ((uint32_t)0x01000000U)         /* !< Sampled mode enabled */

/* COMP_CTL3 Bits */
/* COMP_CTL3[DACCODE0] Bits */
#define COMP_CTL3_DACCODE0_OFS                   (0)                             /* !< DACCODE0 Offset */
#define COMP_CTL3_DACCODE0_MASK                  ((uint32_t)0x000000FFU)         /* !< This is the first 8-bit DAC code.
                                                                                    When the DAC code is 0x0 the DAC
                                                                                    output will be 0 V. When the DAC code
                                                                                    is 0xFF the DAC output will be
                                                                                    selected reference voltage x 255/256. */
#define COMP_CTL3_DACCODE0_MNIMUM                ((uint32_t)0x00000000U)         /* !< Minimum DAC code value */
#define COMP_CTL3_DACCODE0_MAXIMUM               ((uint32_t)0x000000FFU)         /* !< Minimum DAC code value */
/* COMP_CTL3[DACCODE1] Bits */
#define COMP_CTL3_DACCODE1_OFS                   (16)                            /* !< DACCODE1 Offset */
#define COMP_CTL3_DACCODE1_MASK                  ((uint32_t)0x00FF0000U)         /* !< This is the second 8-bit DAC code.
                                                                                    When the DAC code is 0x0 the DAC
                                                                                    output will be 0 V. When the DAC code
                                                                                    is 0xFF the DAC output will be
                                                                                    selected reference voltage x 255/256. */
#define COMP_CTL3_DACCODE1_MNIMUM                ((uint32_t)0x00000000U)         /* !< Minimum DAC code value */
#define COMP_CTL3_DACCODE1_MAXIMUM               ((uint32_t)0x00FF0000U)         /* !< Minimum DAC code value */

/* COMP_STAT Bits */
/* COMP_STAT[OUT] Bits */
#define COMP_STAT_OUT_OFS                        (0)                             /* !< OUT Offset */
#define COMP_STAT_OUT_MASK                       ((uint32_t)0x00000001U)         /* !< This bit reflects the value of the
                                                                                    comparator output. Writing to this
                                                                                    bit has no effect on the comparator
                                                                                    output. */
#define COMP_STAT_OUT_LOW                        ((uint32_t)0x00000000U)         /* !< Comparator output is low */
#define COMP_STAT_OUT_HIGH                       ((uint32_t)0x00000001U)         /* !< Comparator output is high */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_comp__include */
