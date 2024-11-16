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

#ifndef ti_devices_msp_peripherals_hw_aes__include
#define ti_devices_msp_peripherals_hw_aes__include

/* Filename: hw_aes.h */
/* Revised: 2023-06-13 16:16:59 */
/* Revision: af41564566f5317723aed3e5efba7edbc3faf9e6 */

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
* AES Registers
******************************************************************************/
#define AES_DMA_TRIG2_OFS                        ((uint32_t)0x000010B0U)
#define AES_DMA_TRIG1_OFS                        ((uint32_t)0x00001080U)
#define AES_DMA_TRIG0_OFS                        ((uint32_t)0x00001050U)
#define AES_CPU_INT_OFS                          ((uint32_t)0x00001020U)
#define AES_GPRCM_OFS                            ((uint32_t)0x00000800U)


/** @addtogroup AES_DMA_TRIG2
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x000010B0) Interrupt Index Register */
       uint32_t RESERVED0;
  __IO uint32_t IMASK;                             /* !< (@ 0x000010B8) Interrupt mask */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x000010C0) Raw interrupt status */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x000010C8) Masked interrupt status */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x000010D0) Interrupt set */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x000010D8) Interrupt clear */
} AES_DMA_TRIG2_Regs;

/*@}*/ /* end of group AES_DMA_TRIG2 */

/** @addtogroup AES_DMA_TRIG1
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001080) Interrupt Index Register */
       uint32_t RESERVED0;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001088) Interrupt mask */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x00001090) Raw interrupt status */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x00001098) Masked interrupt status */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x000010A0) Interrupt set */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x000010A8) Interrupt clear */
} AES_DMA_TRIG1_Regs;

/*@}*/ /* end of group AES_DMA_TRIG1 */

/** @addtogroup AES_DMA_TRIG0
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001050) Interrupt Index Register */
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
} AES_DMA_TRIG0_Regs;

/*@}*/ /* end of group AES_DMA_TRIG0 */

/** @addtogroup AES_CPU_INT
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001020) Interrupt Index Register */
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
} AES_CPU_INT_Regs;

/*@}*/ /* end of group AES_CPU_INT */

/** @addtogroup AES_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} AES_GPRCM_Regs;

/*@}*/ /* end of group AES_GPRCM */

/** @addtogroup AES
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  AES_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED1[512];
  __IO uint32_t PDBGCTL;                           /* !< (@ 0x00001018) Peripheral Debug Control */
       uint32_t RESERVED2;
  AES_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED3;
  AES_DMA_TRIG0_Regs  DMA_TRIG0;                         /* !< (@ 0x00001050) */
       uint32_t RESERVED4;
  AES_DMA_TRIG1_Regs  DMA_TRIG1;                         /* !< (@ 0x00001080) */
       uint32_t RESERVED5;
  AES_DMA_TRIG2_Regs  DMA_TRIG2;                         /* !< (@ 0x000010B0) */
       uint32_t RESERVED6;
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED7[7];
  __IO uint32_t AESACTL0;                          /* !< (@ 0x00001100) AES accelerator control register 0 */
  __IO uint32_t AESACTL1;                          /* !< (@ 0x00001104) AES accelerator control register 1 */
  __IO uint32_t AESASTAT;                          /* !< (@ 0x00001108) aes accelerator status register */
  __O  uint32_t AESAKEY;                           /* !< (@ 0x0000110C) aes accelerator key register */
  __O  uint32_t AESADIN;                           /* !< (@ 0x00001110) aes accelerator data in register */
  __I  uint32_t AESADOUT;                          /* !< (@ 0x00001114) aes accelerator data out register */
  __O  uint32_t AESAXDIN;                          /* !< (@ 0x00001118) aes accelerator xored data in register */
  __O  uint32_t AESAXIN;                           /* !< (@ 0x0000111C) aes accelerator xored data in register (no
                                                      trigger) */
} AES_Regs;

/*@}*/ /* end of group AES */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* AES Register Control Bits
******************************************************************************/

/* AES_DMA_TRIG2_IIDX Bits */
/* AES_DMA_TRIG2_IIDX[STAT] Bits */
#define AES_DMA_TRIG2_IIDX_STAT_OFS              (0)                             /* !< STAT Offset */
#define AES_DMA_TRIG2_IIDX_STAT_MASK             ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define AES_DMA_TRIG2_IIDX_STAT_NO_INTR          ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define AES_DMA_TRIG2_IIDX_STAT_DMA2             ((uint32_t)0x00000004U)         /* !< AES trigger 2 DMA */

/* AES_DMA_TRIG2_IMASK Bits */
/* AES_DMA_TRIG2_IMASK[DMA2] Bits */
#define AES_DMA_TRIG2_IMASK_DMA2_OFS             (3)                             /* !< DMA2 Offset */
#define AES_DMA_TRIG2_IMASK_DMA2_MASK            ((uint32_t)0x00000008U)         /* !< DMA2 event mask. */
#define AES_DMA_TRIG2_IMASK_DMA2_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define AES_DMA_TRIG2_IMASK_DMA2_SET             ((uint32_t)0x00000008U)         /* !< Set Interrrupt Mask */

/* AES_DMA_TRIG2_RIS Bits */
/* AES_DMA_TRIG2_RIS[DMA2] Bits */
#define AES_DMA_TRIG2_RIS_DMA2_OFS               (3)                             /* !< DMA2 Offset */
#define AES_DMA_TRIG2_RIS_DMA2_MASK              ((uint32_t)0x00000008U)         /* !< DMA2 event */
#define AES_DMA_TRIG2_RIS_DMA2_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define AES_DMA_TRIG2_RIS_DMA2_SET               ((uint32_t)0x00000008U)         /* !< Interrupt occured */

/* AES_DMA_TRIG2_MIS Bits */
/* AES_DMA_TRIG2_MIS[DMA2] Bits */
#define AES_DMA_TRIG2_MIS_DMA2_OFS               (3)                             /* !< DMA2 Offset */
#define AES_DMA_TRIG2_MIS_DMA2_MASK              ((uint32_t)0x00000008U)         /* !< DMA2 event */
#define AES_DMA_TRIG2_MIS_DMA2_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define AES_DMA_TRIG2_MIS_DMA2_SET               ((uint32_t)0x00000008U)         /* !< Interrupt occured */

/* AES_DMA_TRIG2_ISET Bits */
/* AES_DMA_TRIG2_ISET[DMA2] Bits */
#define AES_DMA_TRIG2_ISET_DMA2_OFS              (3)                             /* !< DMA2 Offset */
#define AES_DMA_TRIG2_ISET_DMA2_MASK             ((uint32_t)0x00000008U)         /* !< DMA2 event */
#define AES_DMA_TRIG2_ISET_DMA2_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define AES_DMA_TRIG2_ISET_DMA2_SET              ((uint32_t)0x00000008U)         /* !< Set Interrupt */

/* AES_DMA_TRIG2_ICLR Bits */
/* AES_DMA_TRIG2_ICLR[DMA2] Bits */
#define AES_DMA_TRIG2_ICLR_DMA2_OFS              (3)                             /* !< DMA2 Offset */
#define AES_DMA_TRIG2_ICLR_DMA2_MASK             ((uint32_t)0x00000008U)         /* !< DMA2 event */
#define AES_DMA_TRIG2_ICLR_DMA2_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define AES_DMA_TRIG2_ICLR_DMA2_CLR              ((uint32_t)0x00000008U)         /* !< Clear Interrupt */

/* AES_DMA_TRIG1_IIDX Bits */
/* AES_DMA_TRIG1_IIDX[STAT] Bits */
#define AES_DMA_TRIG1_IIDX_STAT_OFS              (0)                             /* !< STAT Offset */
#define AES_DMA_TRIG1_IIDX_STAT_MASK             ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define AES_DMA_TRIG1_IIDX_STAT_NO_INTR          ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define AES_DMA_TRIG1_IIDX_STAT_DMA1             ((uint32_t)0x00000003U)         /* !< AES trigger 1 DMA */

/* AES_DMA_TRIG1_IMASK Bits */
/* AES_DMA_TRIG1_IMASK[DMA1] Bits */
#define AES_DMA_TRIG1_IMASK_DMA1_OFS             (2)                             /* !< DMA1 Offset */
#define AES_DMA_TRIG1_IMASK_DMA1_MASK            ((uint32_t)0x00000004U)         /* !< DMA1 event mask. */
#define AES_DMA_TRIG1_IMASK_DMA1_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define AES_DMA_TRIG1_IMASK_DMA1_SET             ((uint32_t)0x00000004U)         /* !< Set Interrrupt Mask */

/* AES_DMA_TRIG1_RIS Bits */
/* AES_DMA_TRIG1_RIS[DMA1] Bits */
#define AES_DMA_TRIG1_RIS_DMA1_OFS               (2)                             /* !< DMA1 Offset */
#define AES_DMA_TRIG1_RIS_DMA1_MASK              ((uint32_t)0x00000004U)         /* !< DMA1 event */
#define AES_DMA_TRIG1_RIS_DMA1_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define AES_DMA_TRIG1_RIS_DMA1_SET               ((uint32_t)0x00000004U)         /* !< Interrupt occured */

/* AES_DMA_TRIG1_MIS Bits */
/* AES_DMA_TRIG1_MIS[DMA1] Bits */
#define AES_DMA_TRIG1_MIS_DMA1_OFS               (2)                             /* !< DMA1 Offset */
#define AES_DMA_TRIG1_MIS_DMA1_MASK              ((uint32_t)0x00000004U)         /* !< DMA1 event */
#define AES_DMA_TRIG1_MIS_DMA1_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define AES_DMA_TRIG1_MIS_DMA1_SET               ((uint32_t)0x00000004U)         /* !< Interrupt occured */

/* AES_DMA_TRIG1_ISET Bits */
/* AES_DMA_TRIG1_ISET[DMA1] Bits */
#define AES_DMA_TRIG1_ISET_DMA1_OFS              (2)                             /* !< DMA1 Offset */
#define AES_DMA_TRIG1_ISET_DMA1_MASK             ((uint32_t)0x00000004U)         /* !< DMA1 event */
#define AES_DMA_TRIG1_ISET_DMA1_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define AES_DMA_TRIG1_ISET_DMA1_SET              ((uint32_t)0x00000004U)         /* !< Set Interrupt */

/* AES_DMA_TRIG1_ICLR Bits */
/* AES_DMA_TRIG1_ICLR[DMA1] Bits */
#define AES_DMA_TRIG1_ICLR_DMA1_OFS              (2)                             /* !< DMA1 Offset */
#define AES_DMA_TRIG1_ICLR_DMA1_MASK             ((uint32_t)0x00000004U)         /* !< DMA1 event */
#define AES_DMA_TRIG1_ICLR_DMA1_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define AES_DMA_TRIG1_ICLR_DMA1_CLR              ((uint32_t)0x00000004U)         /* !< Clear Interrupt */

/* AES_DMA_TRIG0_IIDX Bits */
/* AES_DMA_TRIG0_IIDX[STAT] Bits */
#define AES_DMA_TRIG0_IIDX_STAT_OFS              (0)                             /* !< STAT Offset */
#define AES_DMA_TRIG0_IIDX_STAT_MASK             ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define AES_DMA_TRIG0_IIDX_STAT_NO_INTR          ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define AES_DMA_TRIG0_IIDX_STAT_DMA0             ((uint32_t)0x00000002U)         /* !< AES trigger 0 DMA */

/* AES_DMA_TRIG0_IMASK Bits */
/* AES_DMA_TRIG0_IMASK[DMA0] Bits */
#define AES_DMA_TRIG0_IMASK_DMA0_OFS             (1)                             /* !< DMA0 Offset */
#define AES_DMA_TRIG0_IMASK_DMA0_MASK            ((uint32_t)0x00000002U)         /* !< DMA0 event mask. */
#define AES_DMA_TRIG0_IMASK_DMA0_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define AES_DMA_TRIG0_IMASK_DMA0_SET             ((uint32_t)0x00000002U)         /* !< Set Interrrupt Mask */

/* AES_DMA_TRIG0_RIS Bits */
/* AES_DMA_TRIG0_RIS[DMA0] Bits */
#define AES_DMA_TRIG0_RIS_DMA0_OFS               (1)                             /* !< DMA0 Offset */
#define AES_DMA_TRIG0_RIS_DMA0_MASK              ((uint32_t)0x00000002U)         /* !< DMA0 event */
#define AES_DMA_TRIG0_RIS_DMA0_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define AES_DMA_TRIG0_RIS_DMA0_SET               ((uint32_t)0x00000002U)         /* !< Interrupt occured */

/* AES_DMA_TRIG0_MIS Bits */
/* AES_DMA_TRIG0_MIS[DMA0] Bits */
#define AES_DMA_TRIG0_MIS_DMA0_OFS               (1)                             /* !< DMA0 Offset */
#define AES_DMA_TRIG0_MIS_DMA0_MASK              ((uint32_t)0x00000002U)         /* !< DMA0 event */
#define AES_DMA_TRIG0_MIS_DMA0_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define AES_DMA_TRIG0_MIS_DMA0_SET               ((uint32_t)0x00000002U)         /* !< Interrupt occured */

/* AES_DMA_TRIG0_ISET Bits */
/* AES_DMA_TRIG0_ISET[DMA0] Bits */
#define AES_DMA_TRIG0_ISET_DMA0_OFS              (1)                             /* !< DMA0 Offset */
#define AES_DMA_TRIG0_ISET_DMA0_MASK             ((uint32_t)0x00000002U)         /* !< DMA0 */
#define AES_DMA_TRIG0_ISET_DMA0_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define AES_DMA_TRIG0_ISET_DMA0_SET              ((uint32_t)0x00000002U)         /* !< Set Interrupt */

/* AES_DMA_TRIG0_ICLR Bits */
/* AES_DMA_TRIG0_ICLR[DMA0] Bits */
#define AES_DMA_TRIG0_ICLR_DMA0_OFS              (1)                             /* !< DMA0 Offset */
#define AES_DMA_TRIG0_ICLR_DMA0_MASK             ((uint32_t)0x00000002U)         /* !< DMA0 event */
#define AES_DMA_TRIG0_ICLR_DMA0_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define AES_DMA_TRIG0_ICLR_DMA0_CLR              ((uint32_t)0x00000002U)         /* !< Clear Interrupt */

/* AES_CPU_INT_IIDX Bits */
/* AES_CPU_INT_IIDX[STAT] Bits */
#define AES_CPU_INT_IIDX_STAT_OFS                (0)                             /* !< STAT Offset */
#define AES_CPU_INT_IIDX_STAT_MASK               ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define AES_CPU_INT_IIDX_STAT_NO_INTR            ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define AES_CPU_INT_IIDX_STAT_AESRDY             ((uint32_t)0x00000001U)         /* !< AES ready interrupt, set when the
                                                                                    selected AES operation was completed
                                                                                    and the result can be read from
                                                                                    AESADOUT */

/* AES_CPU_INT_IMASK Bits */
/* AES_CPU_INT_IMASK[AESRDY] Bits */
#define AES_CPU_INT_IMASK_AESRDY_OFS             (0)                             /* !< AESRDY Offset */
#define AES_CPU_INT_IMASK_AESRDY_MASK            ((uint32_t)0x00000001U)         /* !< AES ready interrupt, set when the
                                                                                    selected AES operation was completed
                                                                                    and the result can be read from
                                                                                    AESADOUT. */
#define AES_CPU_INT_IMASK_AESRDY_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define AES_CPU_INT_IMASK_AESRDY_SET             ((uint32_t)0x00000001U)         /* !< Set Interrrupt Mask */

/* AES_CPU_INT_RIS Bits */
/* AES_CPU_INT_RIS[AESRDY] Bits */
#define AES_CPU_INT_RIS_AESRDY_OFS               (0)                             /* !< AESRDY Offset */
#define AES_CPU_INT_RIS_AESRDY_MASK              ((uint32_t)0x00000001U)         /* !< AES ready interrupt, set when the
                                                                                    selected AES operation was completed
                                                                                    and the result can be read from
                                                                                    AESADOUT. */
#define AES_CPU_INT_RIS_AESRDY_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define AES_CPU_INT_RIS_AESRDY_SET               ((uint32_t)0x00000001U)         /* !< Interrupt occured */

/* AES_CPU_INT_MIS Bits */
/* AES_CPU_INT_MIS[AESRDY] Bits */
#define AES_CPU_INT_MIS_AESRDY_OFS               (0)                             /* !< AESRDY Offset */
#define AES_CPU_INT_MIS_AESRDY_MASK              ((uint32_t)0x00000001U)         /* !< AES ready interrupt, set when the
                                                                                    selected AES operation was completed
                                                                                    and the result can be read from
                                                                                    AESADOUT. */
#define AES_CPU_INT_MIS_AESRDY_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define AES_CPU_INT_MIS_AESRDY_SET               ((uint32_t)0x00000001U)         /* !< Interrupt occured */

/* AES_CPU_INT_ISET Bits */
/* AES_CPU_INT_ISET[AESRDY] Bits */
#define AES_CPU_INT_ISET_AESRDY_OFS              (0)                             /* !< AESRDY Offset */
#define AES_CPU_INT_ISET_AESRDY_MASK             ((uint32_t)0x00000001U)         /* !< AES ready interrupt, set when the
                                                                                    selected AES operation was completed
                                                                                    and the result can be read from
                                                                                    AESADOUT. */
#define AES_CPU_INT_ISET_AESRDY_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define AES_CPU_INT_ISET_AESRDY_SET              ((uint32_t)0x00000001U)         /* !< Set Interrupt */

/* AES_CPU_INT_ICLR Bits */
/* AES_CPU_INT_ICLR[AESRDY] Bits */
#define AES_CPU_INT_ICLR_AESRDY_OFS              (0)                             /* !< AESRDY Offset */
#define AES_CPU_INT_ICLR_AESRDY_MASK             ((uint32_t)0x00000001U)         /* !< AES ready interrupt, set when the
                                                                                    selected AES operation was completed
                                                                                    and the result can be read from
                                                                                    AESADOUT. */
#define AES_CPU_INT_ICLR_AESRDY_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define AES_CPU_INT_ICLR_AESRDY_CLR              ((uint32_t)0x00000001U)         /* !< Clear Interrupt */

/* AES_PWREN Bits */
/* AES_PWREN[ENABLE] Bits */
#define AES_PWREN_ENABLE_OFS                     (0)                             /* !< ENABLE Offset */
#define AES_PWREN_ENABLE_MASK                    ((uint32_t)0x00000001U)         /* !< Enable the power */
#define AES_PWREN_ENABLE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Disable Power */
#define AES_PWREN_ENABLE_ENABLE                  ((uint32_t)0x00000001U)         /* !< Enable Power */
/* AES_PWREN[KEY] Bits */
#define AES_PWREN_KEY_OFS                        (24)                            /* !< KEY Offset */
#define AES_PWREN_KEY_MASK                       ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define AES_PWREN_KEY_UNLOCK_W                   ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* AES_RSTCTL Bits */
/* AES_RSTCTL[RESETSTKYCLR] Bits */
#define AES_RSTCTL_RESETSTKYCLR_OFS              (1)                             /* !< RESETSTKYCLR Offset */
#define AES_RSTCTL_RESETSTKYCLR_MASK             ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define AES_RSTCTL_RESETSTKYCLR_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define AES_RSTCTL_RESETSTKYCLR_CLR              ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* AES_RSTCTL[RESETASSERT] Bits */
#define AES_RSTCTL_RESETASSERT_OFS               (0)                             /* !< RESETASSERT Offset */
#define AES_RSTCTL_RESETASSERT_MASK              ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define AES_RSTCTL_RESETASSERT_NOP               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define AES_RSTCTL_RESETASSERT_ASSERT            ((uint32_t)0x00000001U)         /* !< Assert reset */
/* AES_RSTCTL[KEY] Bits */
#define AES_RSTCTL_KEY_OFS                       (24)                            /* !< KEY Offset */
#define AES_RSTCTL_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define AES_RSTCTL_KEY_UNLOCK_W                  ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* AES_STAT Bits */
/* AES_STAT[RESETSTKY] Bits */
#define AES_STAT_RESETSTKY_OFS                   (16)                            /* !< RESETSTKY Offset */
#define AES_STAT_RESETSTKY_MASK                  ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define AES_STAT_RESETSTKY_NORES                 ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define AES_STAT_RESETSTKY_RESET                 ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* AES_PDBGCTL Bits */
/* AES_PDBGCTL[FREE] Bits */
#define AES_PDBGCTL_FREE_OFS                     (0)                             /* !< FREE Offset */
#define AES_PDBGCTL_FREE_MASK                    ((uint32_t)0x00000001U)         /* !< Free run control */
#define AES_PDBGCTL_FREE_STOP                    ((uint32_t)0x00000000U)         /* !< The peripheral freezes
                                                                                    functionality while the Core Halted
                                                                                    input is asserted and resumes when it
                                                                                    is deasserted. */
#define AES_PDBGCTL_FREE_RUN                     ((uint32_t)0x00000001U)         /* !< The peripheral ignores the state of
                                                                                    the Core Halted input */
/* AES_PDBGCTL[SOFT] Bits */
#define AES_PDBGCTL_SOFT_OFS                     (1)                             /* !< SOFT Offset */
#define AES_PDBGCTL_SOFT_MASK                    ((uint32_t)0x00000002U)         /* !< Soft halt boundary control. This
                                                                                    function is only available, if [FREE]
                                                                                    is set to 'STOP' */
#define AES_PDBGCTL_SOFT_IMMEDIATE               ((uint32_t)0x00000000U)         /* !< The peripheral will halt
                                                                                    immediately, even if the resultant
                                                                                    state will result in corruption if
                                                                                    the system is restarted */
#define AES_PDBGCTL_SOFT_DELAYED                 ((uint32_t)0x00000002U)         /* !< The peripheral blocks the debug
                                                                                    freeze until it has reached a
                                                                                    boundary where it can resume without
                                                                                    corruption */

/* AES_EVT_MODE Bits */
/* AES_EVT_MODE[INT0_CFG] Bits */
#define AES_EVT_MODE_INT0_CFG_OFS                (0)                             /* !< INT0_CFG Offset */
#define AES_EVT_MODE_INT0_CFG_MASK               ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT0] */
#define AES_EVT_MODE_INT0_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define AES_EVT_MODE_INT0_CFG_SOFTWARE           ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define AES_EVT_MODE_INT0_CFG_HARDWARE           ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* AES_EVT_MODE[EVT1_CFG] Bits */
#define AES_EVT_MODE_EVT1_CFG_OFS                (2)                             /* !< EVT1_CFG Offset */
#define AES_EVT_MODE_EVT1_CFG_MASK               ((uint32_t)0x0000000CU)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT1] */
#define AES_EVT_MODE_EVT1_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define AES_EVT_MODE_EVT1_CFG_SOFTWARE           ((uint32_t)0x00000004U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define AES_EVT_MODE_EVT1_CFG_HARDWARE           ((uint32_t)0x00000008U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* AES_EVT_MODE[EVT2_CFG] Bits */
#define AES_EVT_MODE_EVT2_CFG_OFS                (4)                             /* !< EVT2_CFG Offset */
#define AES_EVT_MODE_EVT2_CFG_MASK               ((uint32_t)0x00000030U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT2] */
#define AES_EVT_MODE_EVT2_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define AES_EVT_MODE_EVT2_CFG_SOFTWARE           ((uint32_t)0x00000010U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define AES_EVT_MODE_EVT2_CFG_HARDWARE           ((uint32_t)0x00000020U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* AES_EVT_MODE[EVT3_CFG] Bits */
#define AES_EVT_MODE_EVT3_CFG_OFS                (6)                             /* !< EVT3_CFG Offset */
#define AES_EVT_MODE_EVT3_CFG_MASK               ((uint32_t)0x000000C0U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT2] */
#define AES_EVT_MODE_EVT3_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define AES_EVT_MODE_EVT3_CFG_SOFTWARE           ((uint32_t)0x00000040U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define AES_EVT_MODE_EVT3_CFG_HARDWARE           ((uint32_t)0x00000080U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* AES_AESACTL0 Bits */
/* AES_AESACTL0[OPX] Bits */
#define AES_AESACTL0_OPX_OFS                     (0)                             /* !< OPX Offset */
#define AES_AESACTL0_OPX_MASK                    ((uint32_t)0x00000003U)         /* !< AES operation. The AESOPx bits are
                                                                                    not reset by AESSWRST = 1. Writes are
                                                                                    ignored when AESCMEN = 1 and
                                                                                    AESBLKCNTx > 0. 00b = Encryption. 01b
                                                                                    = Decryption. The provided key is the
                                                                                    same key used for encryption. 10b =
                                                                                    Generate first round key required for
                                                                                    decryption. 11b = Decryption. The
                                                                                    provided key is the first round key
                                                                                    required for decryption. */
#define AES_AESACTL0_OPX_OP0                     ((uint32_t)0x00000000U)         /* !< Encryption */
#define AES_AESACTL0_OPX_OP1                     ((uint32_t)0x00000001U)         /* !< Decryption. The provided key is the
                                                                                    same key used for encryption. */
#define AES_AESACTL0_OPX_OP2                     ((uint32_t)0x00000002U)         /* !< Generate first round key required
                                                                                    for decryption. */
#define AES_AESACTL0_OPX_OP3                     ((uint32_t)0x00000003U)         /* !< Decryption. The provided key is the
                                                                                    first round key required for
                                                                                    decryption. */
/* AES_AESACTL0[KLX] Bits */
#define AES_AESACTL0_KLX_OFS                     (2)                             /* !< KLX Offset */
#define AES_AESACTL0_KLX_MASK                    ((uint32_t)0x0000000CU)         /* !< AES key length.  These bits define
                                                                                    which of the 1 AES standards is
                                                                                    performed. The AESKLx bits are not
                                                                                    reset by AESSWRST = 1. Writes are
                                                                                    ignored when AESCMEN = 1 and
                                                                                    AESBLKCNTx > 0. */
#define AES_AESACTL0_KLX_AES128                  ((uint32_t)0x00000000U)         /* !< The key size is 128 bit. */
#define AES_AESACTL0_KLX_AES256                  ((uint32_t)0x00000008U)         /* !< The key size is 256 bit. */
/* AES_AESACTL0[CMX] Bits */
#define AES_AESACTL0_CMX_OFS                     (5)                             /* !< CMX Offset */
#define AES_AESACTL0_CMX_MASK                    ((uint32_t)0x00000060U)         /* !< AES cipher mode select. These bits
                                                                                    are ignored for AESCMEN = 0. Writes
                                                                                    are ignored when AESCMEN = 1 and
                                                                                    AESBLKCNTx > 0. 00b = ECB 01b = CBC
                                                                                    10b = OFB 11b = CFB */
#define AES_AESACTL0_CMX_ECB                     ((uint32_t)0x00000000U)         /* !< ECB */
#define AES_AESACTL0_CMX_CBC                     ((uint32_t)0x00000020U)         /* !< CBC */
#define AES_AESACTL0_CMX_OFB                     ((uint32_t)0x00000040U)         /* !< OFB */
#define AES_AESACTL0_CMX_CFB                     ((uint32_t)0x00000060U)         /* !< CFB */
/* AES_AESACTL0[SWRST] Bits */
#define AES_AESACTL0_SWRST_OFS                   (7)                             /* !< SWRST Offset */
#define AES_AESACTL0_SWRST_MASK                  ((uint32_t)0x00000080U)         /* !< AES software reset.  Immediately
                                                                                    resets the complete AES accelerator
                                                                                    module even when busy except for the
                                                                                    AESRDYIE, the AESKLx and the AESOPx
                                                                                    bits. It also clears the (internal)
                                                                                    state memory. The AESSWRST bit is
                                                                                    automatically reset and is always
                                                                                    read as zero. 0b = No reset 1b =
                                                                                    Reset AES accelerator module */
#define AES_AESACTL0_SWRST_NORST                 ((uint32_t)0x00000000U)         /* !< No reset. */
#define AES_AESACTL0_SWRST_RST                   ((uint32_t)0x00000080U)         /* !< Reset AES accelerator module. */
/* AES_AESACTL0[ERRFG] Bits */
#define AES_AESACTL0_ERRFG_OFS                   (11)                            /* !< ERRFG Offset */
#define AES_AESACTL0_ERRFG_MASK                  ((uint32_t)0x00000800U)         /* !< AES error flag.  AESAKEY or AESADIN
                                                                                    were written while an AES operation
                                                                                    was in progress. The bit must be
                                                                                    cleared by software. 0b = No error 1b
                                                                                    = Error occurred */
#define AES_AESACTL0_ERRFG_NOERR                 ((uint32_t)0x00000000U)         /* !< No error */
#define AES_AESACTL0_ERRFG_ERR                   ((uint32_t)0x00000800U)         /* !< Error occurred */
/* AES_AESACTL0[CMEN] Bits */
#define AES_AESACTL0_CMEN_OFS                    (15)                            /* !< CMEN Offset */
#define AES_AESACTL0_CMEN_MASK                   ((uint32_t)0x00008000U)         /* !< AESCMEN enables the support of the
                                                                                    cipher modes ECB, CBC, OFB and CFB
                                                                                    together with the DMA. Writes are
                                                                                    ignored when AESCMEN = 1 and
                                                                                    AESBLKCNTx > 0. 0 = No DMA triggers
                                                                                    are generated. 1 = DMA cipher mode
                                                                                    support operation is enabled and the
                                                                                    corresponding DMA triggers are
                                                                                    generated. */
#define AES_AESACTL0_CMEN_DISABLE                ((uint32_t)0x00000000U)         /* !< No DMA triggers are generated. */
#define AES_AESACTL0_CMEN_ENABLE                 ((uint32_t)0x00008000U)         /* !< DMA cipher mode support operation
                                                                                    is enabled and the corresponding DMA
                                                                                    triggers are generated. */

/* AES_AESACTL1 Bits */
/* AES_AESACTL1[BLKCNTX] Bits */
#define AES_AESACTL1_BLKCNTX_OFS                 (0)                             /* !< BLKCNTX Offset */
#define AES_AESACTL1_BLKCNTX_MASK                ((uint32_t)0x000000FFU)         /* !< Cipher Block Counter. Number of
                                                                                    blocks to be encrypted or decrypted
                                                                                    with block cipher modes enabled
                                                                                    (AESCMEN = 1). Ignored if AESCMEN =
                                                                                    0. The block counter decrements with
                                                                                    each performed encryption or
                                                                                    decryption. Writes are ignored when
                                                                                    AESCMEN = 1 and AESBLKCNTx > 0. */
#define AES_AESACTL1_BLKCNTX_MINNUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define AES_AESACTL1_BLKCNTX_ENABLE              ((uint32_t)0x000000FFU)         /* !< Highest possible value */

/* AES_AESASTAT Bits */
/* AES_AESASTAT[BUSY] Bits */
#define AES_AESASTAT_BUSY_OFS                    (0)                             /* !< BUSY Offset */
#define AES_AESASTAT_BUSY_MASK                   ((uint32_t)0x00000001U)         /* !< AES accelerator module busy;
                                                                                    encryption, decryption, or key
                                                                                    generation in progress.  0 = Not busy
                                                                                    1 = Busy */
#define AES_AESASTAT_BUSY_IDLE                   ((uint32_t)0x00000000U)         /* !< Not busy */
#define AES_AESASTAT_BUSY_BUSY                   ((uint32_t)0x00000001U)         /* !< Busy */
/* AES_AESASTAT[KEYWR] Bits */
#define AES_AESASTAT_KEYWR_OFS                   (1)                             /* !< KEYWR Offset */
#define AES_AESASTAT_KEYWR_MASK                  ((uint32_t)0x00000002U)         /* !< All bytes written to AESAKEY. This
                                                                                    bit can be modified by software but
                                                                                    it must not be reset by software (10)
                                                                                    if AESCMEN=1. Changing its state by
                                                                                    software also resets the AESKEYCNTx
                                                                                    bits. AESKEYWR is reset by PUC,
                                                                                    AESSWRST, an error condition,
                                                                                    changing AESOPx, changing AESKLx, and
                                                                                    the start to (over)write a new key.
                                                                                    Because it is reset when AESOPx is
                                                                                    changed it can be set by software
                                                                                    again to indicate that the loaded key
                                                                                    is still valid. */
#define AES_AESASTAT_KEYWR_NALL                  ((uint32_t)0x00000000U)         /* !< Not all bytes written */
#define AES_AESASTAT_KEYWR_ALL                   ((uint32_t)0x00000002U)         /* !< All bytes written */
/* AES_AESASTAT[DINWR] Bits */
#define AES_AESASTAT_DINWR_OFS                   (2)                             /* !< DINWR Offset */
#define AES_AESASTAT_DINWR_MASK                  ((uint32_t)0x00000004U)         /* !< All 16 bytes written to AESADIN,
                                                                                    AESAXDIN or AESAXIN. Changing its
                                                                                    state by software also resets the
                                                                                    AESDINCNTx bits. AESDINWR is reset by
                                                                                    PUC, AESSWRST, an error condition,
                                                                                    changing AESOPx, changing AESKLx, the
                                                                                    start to (over)write the data, and
                                                                                    when the AES accelerator is busy.
                                                                                    Because it is reset when AESOPx or
                                                                                    AESKLx is changed it can be set by
                                                                                    software again to indicate that the
                                                                                    current data is still valid.  0 = Not
                                                                                    all bytes written  1 = All bytes
                                                                                    written */
#define AES_AESASTAT_DINWR_NALL                  ((uint32_t)0x00000000U)         /* !< Not all bytes written */
#define AES_AESASTAT_DINWR_ALL                   ((uint32_t)0x00000004U)         /* !< All bytes written */
/* AES_AESASTAT[DOUTRD] Bits */
#define AES_AESASTAT_DOUTRD_OFS                  (3)                             /* !< DOUTRD Offset */
#define AES_AESASTAT_DOUTRD_MASK                 ((uint32_t)0x00000008U)         /* !< All 16 bytes read from AESADOUT.
                                                                                    AESDOUTRD is reset by PUC, AESSWRST,
                                                                                    an error condition, changing AESOPx,
                                                                                    changing AESKLx, when the AES
                                                                                    accelerator is busy, and when the
                                                                                    output data is read again.  0 = Not
                                                                                    all bytes read 1 = All bytes read */
#define AES_AESASTAT_DOUTRD_NALL                 ((uint32_t)0x00000000U)         /* !< Not all bytes read */
#define AES_AESASTAT_DOUTRD_ALL                  ((uint32_t)0x00000008U)         /* !< All bytes read */
/* AES_AESASTAT[KEYCNTX] Bits */
#define AES_AESASTAT_KEYCNTX_OFS                 (4)                             /* !< KEYCNTX Offset */
#define AES_AESASTAT_KEYCNTX_MASK                ((uint32_t)0x000000F0U)         /* !< Bytes written to AESAKEY when
                                                                                    AESKLx = 00, half-words written to
                                                                                    AESAKEY if AESKLx = b10. Reset when
                                                                                    AESKEYWR is reset. If AESKEYCNTx = 0
                                                                                    and AESKEYWR = 0, no bytes were
                                                                                    written. If AESKEYCNTx = 0 and
                                                                                    AESKEYWR = 1, all bytes were written. */
#define AES_AESASTAT_KEYCNTX_MINNUM              ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESASTAT_KEYCNTX_MAXNUM              ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* AES_AESASTAT[DINCNTX] Bits */
#define AES_AESASTAT_DINCNTX_OFS                 (8)                             /* !< DINCNTX Offset */
#define AES_AESASTAT_DINCNTX_MASK                ((uint32_t)0x00000F00U)         /* !< Bytes written to AESADIN, AESAXDIN
                                                                                    or AESAXIN. Reset when AESDINWR is
                                                                                    reset. If AESDINCNTx = 0 and AESDINWR
                                                                                    = 0, no bytes were written. If
                                                                                    AESDINCNTx = 0 and AESDINWR = 1, all
                                                                                    bytes were written. */
#define AES_AESASTAT_DINCNTX_MINNUM              ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESASTAT_DINCNTX_MAXNUM              ((uint32_t)0x00000F00U)         /* !< Highest possible value */
/* AES_AESASTAT[DOUTCNTX] Bits */
#define AES_AESASTAT_DOUTCNTX_OFS                (12)                            /* !< DOUTCNTX Offset */
#define AES_AESASTAT_DOUTCNTX_MASK               ((uint32_t)0x0000F000U)         /* !< Bytes read from AESADOUT. Reset
                                                                                    when AESDOUTRD is reset. If
                                                                                    AESDOUTCNTx = 0 and AESDOUTRD = 0, no
                                                                                    bytes were read. If AESDOUTCNTx = 0
                                                                                    and AESDOUTRD = 1, all bytes were
                                                                                    read. */
#define AES_AESASTAT_DOUTCNTX_MINNUM             ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESASTAT_DOUTCNTX_MAXNUM             ((uint32_t)0x0000F000U)         /* !< Highest possible value */

/* AES_AESAKEY Bits */
/* AES_AESAKEY[KEY0X] Bits */
#define AES_AESAKEY_KEY0X_OFS                    (0)                             /* !< KEY0X Offset */
#define AES_AESAKEY_KEY0X_MASK                   ((uint32_t)0x000000FFU)         /* !< AES key byte n when AESAKEY is
                                                                                    written as word. AES next key byte
                                                                                    when AESAKEY is written as byte. Do
                                                                                    not mix word and byte access. Always
                                                                                    reads as zero. The key is reset by
                                                                                    PUC or by AESSWRST = 1. */
#define AES_AESAKEY_KEY0X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAKEY_KEY0X_MAXNUM                 ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* AES_AESAKEY[KEY1X] Bits */
#define AES_AESAKEY_KEY1X_OFS                    (8)                             /* !< KEY1X Offset */
#define AES_AESAKEY_KEY1X_MASK                   ((uint32_t)0x0000FF00U)         /* !< AES key byte n+1 when AESAKEY is
                                                                                    written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. The key is reset by PUC or by
                                                                                    AESSWRST = 1. */
#define AES_AESAKEY_KEY1X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAKEY_KEY1X_MAXNUM                 ((uint32_t)0x0000FF00U)         /* !< Highest possible value */
/* AES_AESAKEY[KEY2X] Bits */
#define AES_AESAKEY_KEY2X_OFS                    (16)                            /* !< KEY2X Offset */
#define AES_AESAKEY_KEY2X_MASK                   ((uint32_t)0x00FF0000U)         /* !< AES key byte n+2 when AESAKEY is
                                                                                    written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. The key is reset by PUC or by
                                                                                    AESSWRST = 1. */
#define AES_AESAKEY_KEY2X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAKEY_KEY2X_MAXNUM                 ((uint32_t)0x00FF0000U)         /* !< Highest possible value */
/* AES_AESAKEY[KEY3X] Bits */
#define AES_AESAKEY_KEY3X_OFS                    (24)                            /* !< KEY3X Offset */
#define AES_AESAKEY_KEY3X_MASK                   ((uint32_t)0xFF000000U)         /* !< AES key byte n+3 when AESAKEY is
                                                                                    written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. The key is reset by PUC or by
                                                                                    AESSWRST = 1. */
#define AES_AESAKEY_KEY3X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAKEY_KEY3X_MAXNUM                 ((uint32_t)0xFF000000U)         /* !< Highest possible value */

/* AES_AESADIN Bits */
/* AES_AESADIN[DIN0X] Bits */
#define AES_AESADIN_DIN0X_OFS                    (0)                             /* !< DIN0X Offset */
#define AES_AESADIN_DIN0X_MASK                   ((uint32_t)0x000000FFU)         /* !< AES data in byte n when AESADIN is
                                                                                    written as word. AES next data in
                                                                                    byte when AESADIN is written as byte.
                                                                                    Do not mix word and byte access.
                                                                                    Always reads as zero. */
#define AES_AESADIN_DIN0X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESADIN_DIN0X_MAXNUM                 ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* AES_AESADIN[DIN1X] Bits */
#define AES_AESADIN_DIN1X_OFS                    (8)                             /* !< DIN1X Offset */
#define AES_AESADIN_DIN1X_MASK                   ((uint32_t)0x0000FF00U)         /* !< AES data in byte n+1 when AESADIN
                                                                                    is written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. */
#define AES_AESADIN_DIN1X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESADIN_DIN1X_MAXNUM                 ((uint32_t)0x0000FF00U)         /* !< Highest possible value */
/* AES_AESADIN[DIN2X] Bits */
#define AES_AESADIN_DIN2X_OFS                    (16)                            /* !< DIN2X Offset */
#define AES_AESADIN_DIN2X_MASK                   ((uint32_t)0x00FF0000U)         /* !< AES data in byte n+2 when AESADIN
                                                                                    is written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. */
#define AES_AESADIN_DIN2X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESADIN_DIN2X_MAXNUM                 ((uint32_t)0x00FF0000U)         /* !< Highest possible value */
/* AES_AESADIN[DIN3X] Bits */
#define AES_AESADIN_DIN3X_OFS                    (24)                            /* !< DIN3X Offset */
#define AES_AESADIN_DIN3X_MASK                   ((uint32_t)0xFF000000U)         /* !< AES data in byte n+3 when AESADIN
                                                                                    is written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. */
#define AES_AESADIN_DIN3X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESADIN_DIN3X_MAXNUM                 ((uint32_t)0xFF000000U)         /* !< Highest possible value */

/* AES_AESADOUT Bits */
/* AES_AESADOUT[DOUT0X] Bits */
#define AES_AESADOUT_DOUT0X_OFS                  (0)                             /* !< DOUT0X Offset */
#define AES_AESADOUT_DOUT0X_MASK                 ((uint32_t)0x000000FFU)         /* !< AES data out byte n when AESADOUT
                                                                                    is read as word. AES next data out
                                                                                    byte when AESADOUT is read as byte.
                                                                                    Do not mix word and byte access. */
#define AES_AESADOUT_DOUT0X_MINNUM               ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESADOUT_DOUT0X_MAXNUM               ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* AES_AESADOUT[DOUT1X] Bits */
#define AES_AESADOUT_DOUT1X_OFS                  (8)                             /* !< DOUT1X Offset */
#define AES_AESADOUT_DOUT1X_MASK                 ((uint32_t)0x0000FF00U)         /* !< AES data out byte n+1 when AESADOUT
                                                                                    is read as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. */
#define AES_AESADOUT_DOUT1X_MINNUM               ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESADOUT_DOUT1X_MAXNUM               ((uint32_t)0x0000FF00U)         /* !< Highest possible value */
/* AES_AESADOUT[DOUT2X] Bits */
#define AES_AESADOUT_DOUT2X_OFS                  (16)                            /* !< DOUT2X Offset */
#define AES_AESADOUT_DOUT2X_MASK                 ((uint32_t)0x00FF0000U)         /* !< AES data out byte n+2 when AESADOUT
                                                                                    is read as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. */
#define AES_AESADOUT_DOUT2X_MINNUM               ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESADOUT_DOUT2X_MAXNUM               ((uint32_t)0x00FF0000U)         /* !< Highest possible value */
/* AES_AESADOUT[DOUT3X] Bits */
#define AES_AESADOUT_DOUT3X_OFS                  (24)                            /* !< DOUT3X Offset */
#define AES_AESADOUT_DOUT3X_MASK                 ((uint32_t)0xFF000000U)         /* !< AES data out byte n+3 when AESADOUT
                                                                                    is read as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. */
#define AES_AESADOUT_DOUT3X_MINNUM               ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESADOUT_DOUT3X_MAXNUM               ((uint32_t)0xFF000000U)         /* !< Highest possible value */

/* AES_AESAXDIN Bits */
/* AES_AESAXDIN[XDIN0X] Bits */
#define AES_AESAXDIN_XDIN0X_OFS                  (0)                             /* !< XDIN0X Offset */
#define AES_AESAXDIN_XDIN0X_MASK                 ((uint32_t)0x000000FFU)         /* !< AES data in byte n when AESAXDIN is
                                                                                    written as word. AES next data in
                                                                                    byte when AESAXDIN is written as
                                                                                    byte. Do not mix word and byte
                                                                                    access. Always reads as zero. */
#define AES_AESAXDIN_XDIN0X_MINNUM               ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAXDIN_XDIN0X_MAXNUM               ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* AES_AESAXDIN[XDIN1X] Bits */
#define AES_AESAXDIN_XDIN1X_OFS                  (8)                             /* !< XDIN1X Offset */
#define AES_AESAXDIN_XDIN1X_MASK                 ((uint32_t)0x0000FF00U)         /* !< AES data in byte n+1 when AESAXDIN
                                                                                    is written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. */
#define AES_AESAXDIN_XDIN1X_MINNUM               ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAXDIN_XDIN1X_MAXNUM               ((uint32_t)0x0000FF00U)         /* !< Highest possible value */
/* AES_AESAXDIN[XDIN2X] Bits */
#define AES_AESAXDIN_XDIN2X_OFS                  (16)                            /* !< XDIN2X Offset */
#define AES_AESAXDIN_XDIN2X_MASK                 ((uint32_t)0x00FF0000U)         /* !< AES data in byte n+2 when AESAXDIN
                                                                                    is written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. */
#define AES_AESAXDIN_XDIN2X_MINNUM               ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAXDIN_XDIN2X_MAXNUM               ((uint32_t)0x00FF0000U)         /* !< Highest possible value */
/* AES_AESAXDIN[XDIN3X] Bits */
#define AES_AESAXDIN_XDIN3X_OFS                  (24)                            /* !< XDIN3X Offset */
#define AES_AESAXDIN_XDIN3X_MASK                 ((uint32_t)0xFF000000U)         /* !< AES data in byte n+3 when AESAXDIN
                                                                                    is written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. */
#define AES_AESAXDIN_XDIN3X_MINNUM               ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAXDIN_XDIN3X_MAXNUM               ((uint32_t)0xFF000000U)         /* !< Highest possible value */

/* AES_AESAXIN Bits */
/* AES_AESAXIN[XIN0X] Bits */
#define AES_AESAXIN_XIN0X_OFS                    (0)                             /* !< XIN0X Offset */
#define AES_AESAXIN_XIN0X_MASK                   ((uint32_t)0x000000FFU)         /* !< AES data in byte n when AESAXIN is
                                                                                    written as word. AES next data in
                                                                                    byte when AESAXIN is written as byte.
                                                                                    Do not mix word and byte access.
                                                                                    Always reads as zero. */
#define AES_AESAXIN_XIN0X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAXIN_XIN0X_MAXNUM                 ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* AES_AESAXIN[XIN1X] Bits */
#define AES_AESAXIN_XIN1X_OFS                    (8)                             /* !< XIN1X Offset */
#define AES_AESAXIN_XIN1X_MASK                   ((uint32_t)0x0000FF00U)         /* !< AES data in byte n+1 when AESAXIN
                                                                                    is written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. */
#define AES_AESAXIN_XIN1X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAXIN_XIN1X_MAXNUM                 ((uint32_t)0x0000FF00U)         /* !< Highest possible value */
/* AES_AESAXIN[XIN2X] Bits */
#define AES_AESAXIN_XIN2X_OFS                    (16)                            /* !< XIN2X Offset */
#define AES_AESAXIN_XIN2X_MASK                   ((uint32_t)0x00FF0000U)         /* !< AES data in byte n+2 when AESAXIN
                                                                                    is written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. */
#define AES_AESAXIN_XIN2X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAXIN_XIN2X_MAXNUM                 ((uint32_t)0x00FF0000U)         /* !< Highest possible value */
/* AES_AESAXIN[XIN3X] Bits */
#define AES_AESAXIN_XIN3X_OFS                    (24)                            /* !< XIN3X Offset */
#define AES_AESAXIN_XIN3X_MASK                   ((uint32_t)0xFF000000U)         /* !< AES data in byte n+3 when AESAXIN
                                                                                    is written as word. Do not use these
                                                                                    bits for byte access. Do not mix word
                                                                                    and byte access. Always reads as
                                                                                    zero. */
#define AES_AESAXIN_XIN3X_MINNUM                 ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define AES_AESAXIN_XIN3X_MAXNUM                 ((uint32_t)0xFF000000U)         /* !< Highest possible value */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_aes__include */
