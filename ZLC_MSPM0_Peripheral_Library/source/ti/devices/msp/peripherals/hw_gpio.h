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

#ifndef ti_devices_msp_peripherals_hw_gpio__include
#define ti_devices_msp_peripherals_hw_gpio__include

/* Filename: hw_gpio.h */
/* Revised: 2023-05-10 21:28:12 */
/* Revision: 63b77c412ca552f19fdd3e7971450ee8560270af */

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
* GPIO Registers
******************************************************************************/
#define GPIO_GEN_EVENT1_OFS                      ((uint32_t)0x00001080U)
#define GPIO_GEN_EVENT0_OFS                      ((uint32_t)0x00001050U)
#define GPIO_CPU_INT_OFS                         ((uint32_t)0x00001020U)
#define GPIO_GPRCM_OFS                           ((uint32_t)0x00000800U)


/** @addtogroup GPIO_GEN_EVENT1
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001080) Interrupt index */
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
} GPIO_GEN_EVENT1_Regs;

/*@}*/ /* end of group GPIO_GEN_EVENT1 */

/** @addtogroup GPIO_GEN_EVENT0
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
} GPIO_GEN_EVENT0_Regs;

/*@}*/ /* end of group GPIO_GEN_EVENT0 */

/** @addtogroup GPIO_CPU_INT
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
} GPIO_CPU_INT_Regs;

/*@}*/ /* end of group GPIO_CPU_INT */

/** @addtogroup GPIO_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} GPIO_GPRCM_Regs;

/*@}*/ /* end of group GPIO_GPRCM */

/** @addtogroup GPIO
  @{
*/

typedef struct {
       uint32_t RESERVED0[256];
  __IO uint32_t FSUB_0;                            /* !< (@ 0x00000400) Subsciber Port 0 */
  __IO uint32_t FSUB_1;                            /* !< (@ 0x00000404) Subscriber Port 1 */
       uint32_t RESERVED1[15];
  __IO uint32_t FPUB_0;                            /* !< (@ 0x00000444) Publisher Port 0 */
  __IO uint32_t FPUB_1;                            /* !< (@ 0x00000448) Publisher Port 1 */
       uint32_t RESERVED2[237];
  GPIO_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED3[510];
  __IO uint32_t CLKOVR;                            /* !< (@ 0x00001010) Clock Override */
       uint32_t RESERVED4;
  __IO uint32_t PDBGCTL;                           /* !< (@ 0x00001018) Peripheral Debug Control */
       uint32_t RESERVED5;
  GPIO_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED6;
  GPIO_GEN_EVENT0_Regs  GEN_EVENT0;                        /* !< (@ 0x00001050) */
       uint32_t RESERVED7;
  GPIO_GEN_EVENT1_Regs  GEN_EVENT1;                        /* !< (@ 0x00001080) */
       uint32_t RESERVED8[13];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED9[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
       uint32_t RESERVED10[64];
  __O  uint32_t DOUT3_0;                           /* !< (@ 0x00001200) Data output 3 to 0 */
  __O  uint32_t DOUT7_4;                           /* !< (@ 0x00001204) Data output 7 to 4 */
  __O  uint32_t DOUT11_8;                          /* !< (@ 0x00001208) Data output 11 to 8 */
  __O  uint32_t DOUT15_12;                         /* !< (@ 0x0000120C) Data output 15 to 12 */
  __O  uint32_t DOUT19_16;                         /* !< (@ 0x00001210) Data output 19 to 16 */
  __O  uint32_t DOUT23_20;                         /* !< (@ 0x00001214) Data output 23 to 20 */
  __O  uint32_t DOUT27_24;                         /* !< (@ 0x00001218) Data output 27 to 24 */
  __O  uint32_t DOUT31_28;                         /* !< (@ 0x0000121C) Data output 31 to 28 */
       uint32_t RESERVED11[24];
  __IO uint32_t DOUT31_0;                          /* !< (@ 0x00001280) Data output 31 to 0 */
       uint32_t RESERVED12[3];
  __O  uint32_t DOUTSET31_0;                       /* !< (@ 0x00001290) Data output set 31 to 0 */
       uint32_t RESERVED13[3];
  __O  uint32_t DOUTCLR31_0;                       /* !< (@ 0x000012A0) Data output clear 31 to 0 */
       uint32_t RESERVED14[3];
  __O  uint32_t DOUTTGL31_0;                       /* !< (@ 0x000012B0) Data output toggle 31 to 0 */
       uint32_t RESERVED15[3];
  __IO uint32_t DOE31_0;                           /* !< (@ 0x000012C0) Data output enable 31 to 0 */
       uint32_t RESERVED16[3];
  __O  uint32_t DOESET31_0;                        /* !< (@ 0x000012D0) Data output enable set 31 to 0 */
       uint32_t RESERVED17[3];
  __O  uint32_t DOECLR31_0;                        /* !< (@ 0x000012E0) Data output enable clear 31 to 0 */
       uint32_t RESERVED18[7];
  __I  uint32_t DIN3_0;                            /* !< (@ 0x00001300) Data input 3 to 0 */
  __I  uint32_t DIN7_4;                            /* !< (@ 0x00001304) Data input 7 to 4 */
  __I  uint32_t DIN11_8;                           /* !< (@ 0x00001308) Data input 11 to 8 */
  __I  uint32_t DIN15_12;                          /* !< (@ 0x0000130C) Data input 15 to 12 */
  __I  uint32_t DIN19_16;                          /* !< (@ 0x00001310) Data input 19 to 16 */
  __I  uint32_t DIN23_20;                          /* !< (@ 0x00001314) Data input 23 to 20 */
  __I  uint32_t DIN27_24;                          /* !< (@ 0x00001318) Data input 27 to 24 */
  __I  uint32_t DIN31_28;                          /* !< (@ 0x0000131C) Data input 31 to 28 */
       uint32_t RESERVED19[24];
  __I  uint32_t DIN31_0;                           /* !< (@ 0x00001380) Data input 31 to 0 */
       uint32_t RESERVED20[3];
  __IO uint32_t POLARITY15_0;                      /* !< (@ 0x00001390) Polarity 15 to 0 */
       uint32_t RESERVED21[3];
  __IO uint32_t POLARITY31_16;                     /* !< (@ 0x000013A0) Polarity 31 to 16 */
       uint32_t RESERVED22[23];
  __IO uint32_t CTL;                               /* !< (@ 0x00001400) FAST WAKE GLOBAL EN */
  __IO uint32_t FASTWAKE;                          /* !< (@ 0x00001404) FAST WAKE ENABLE */
       uint32_t RESERVED23[62];
  __IO uint32_t SUB0CFG;                           /* !< (@ 0x00001500) Subscriber 0 configuration */
       uint32_t RESERVED24;
  __IO uint32_t FILTEREN15_0;                      /* !< (@ 0x00001508) Filter Enable 15 to 0 */
  __IO uint32_t FILTEREN31_16;                     /* !< (@ 0x0000150C) Filter Enable 31 to 16 */
  __IO uint32_t DMAMASK;                           /* !< (@ 0x00001510) DMA Write MASK */
       uint32_t RESERVED25[3];
  __IO uint32_t SUB1CFG;                           /* !< (@ 0x00001520) Subscriber 1 configuration */
} GPIO_Regs;

/*@}*/ /* end of group GPIO */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* GPIO Register Control Bits
******************************************************************************/

/* GPIO_GEN_EVENT1_IIDX Bits */
/* GPIO_GEN_EVENT1_IIDX[STAT] Bits */
#define GPIO_GEN_EVENT1_IIDX_STAT_OFS            (0)                             /* !< STAT Offset */
#define GPIO_GEN_EVENT1_IIDX_STAT_MASK           ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define GPIO_GEN_EVENT1_IIDX_STAT_NO_INTR        ((uint32_t)0x00000000U)         /* !< No bit is set means there is no
                                                                                    pending interrupt request */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO16          ((uint32_t)0x00000001U)         /* !< DIO0 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO17          ((uint32_t)0x00000002U)         /* !< DIO1 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO18          ((uint32_t)0x00000003U)         /* !< DIO2 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO19          ((uint32_t)0x00000004U)         /* !< DIO3 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO20          ((uint32_t)0x00000005U)         /* !< DIO4 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO21          ((uint32_t)0x00000006U)         /* !< DIO5 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO22          ((uint32_t)0x00000007U)         /* !< DIO6 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO23          ((uint32_t)0x00000008U)         /* !< DIO7 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO24          ((uint32_t)0x00000009U)         /* !< DIO8 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO25          ((uint32_t)0x0000000AU)         /* !< DIO9 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO26          ((uint32_t)0x0000000BU)         /* !< DIO10 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO27          ((uint32_t)0x0000000CU)         /* !< DIO11 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO28          ((uint32_t)0x0000000DU)         /* !< DIO12 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO29          ((uint32_t)0x0000000EU)         /* !< DIO13 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO30          ((uint32_t)0x0000000FU)         /* !< DIO14 interrupt */
#define GPIO_GEN_EVENT1_IIDX_STAT_DIO31          ((uint32_t)0x00000010U)         /* !< DIO15 interrupt */

/* GPIO_GEN_EVENT1_IMASK Bits */
/* GPIO_GEN_EVENT1_IMASK[DIO16] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO16_OFS          (16)                            /* !< DIO16 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO16_MASK         ((uint32_t)0x00010000U)         /* !< DIO16 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO16_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO16_SET          ((uint32_t)0x00010000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO17] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO17_OFS          (17)                            /* !< DIO17 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO17_MASK         ((uint32_t)0x00020000U)         /* !< DIO17 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO17_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO17_SET          ((uint32_t)0x00020000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO18] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO18_OFS          (18)                            /* !< DIO18 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO18_MASK         ((uint32_t)0x00040000U)         /* !< DIO18 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO18_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO18_SET          ((uint32_t)0x00040000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO19] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO19_OFS          (19)                            /* !< DIO19 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO19_MASK         ((uint32_t)0x00080000U)         /* !< DIO19 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO19_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO19_SET          ((uint32_t)0x00080000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO20] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO20_OFS          (20)                            /* !< DIO20 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO20_MASK         ((uint32_t)0x00100000U)         /* !< DIO20 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO20_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO20_SET          ((uint32_t)0x00100000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO21] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO21_OFS          (21)                            /* !< DIO21 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO21_MASK         ((uint32_t)0x00200000U)         /* !< DIO21 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO21_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO21_SET          ((uint32_t)0x00200000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO22] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO22_OFS          (22)                            /* !< DIO22 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO22_MASK         ((uint32_t)0x00400000U)         /* !< DIO22 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO22_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO22_SET          ((uint32_t)0x00400000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO23] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO23_OFS          (23)                            /* !< DIO23 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO23_MASK         ((uint32_t)0x00800000U)         /* !< DIO23 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO23_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO23_SET          ((uint32_t)0x00800000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO24] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO24_OFS          (24)                            /* !< DIO24 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO24_MASK         ((uint32_t)0x01000000U)         /* !< DIO24 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO24_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO24_SET          ((uint32_t)0x01000000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO25] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO25_OFS          (25)                            /* !< DIO25 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO25_MASK         ((uint32_t)0x02000000U)         /* !< DIO25 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO25_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO25_SET          ((uint32_t)0x02000000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO26] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO26_OFS          (26)                            /* !< DIO26 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO26_MASK         ((uint32_t)0x04000000U)         /* !< DIO26 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO26_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO26_SET          ((uint32_t)0x04000000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO27] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO27_OFS          (27)                            /* !< DIO27 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO27_MASK         ((uint32_t)0x08000000U)         /* !< DIO27 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO27_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO27_SET          ((uint32_t)0x08000000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO28] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO28_OFS          (28)                            /* !< DIO28 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO28_MASK         ((uint32_t)0x10000000U)         /* !< DIO28 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO28_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO28_SET          ((uint32_t)0x10000000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO29] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO29_OFS          (29)                            /* !< DIO29 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO29_MASK         ((uint32_t)0x20000000U)         /* !< DIO29 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO29_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO29_SET          ((uint32_t)0x20000000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO30] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO30_OFS          (30)                            /* !< DIO30 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO30_MASK         ((uint32_t)0x40000000U)         /* !< DIO30 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO30_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO30_SET          ((uint32_t)0x40000000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT1_IMASK[DIO31] Bits */
#define GPIO_GEN_EVENT1_IMASK_DIO31_OFS          (31)                            /* !< DIO31 Offset */
#define GPIO_GEN_EVENT1_IMASK_DIO31_MASK         ((uint32_t)0x80000000U)         /* !< DIO31 event mask */
#define GPIO_GEN_EVENT1_IMASK_DIO31_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT1_IMASK_DIO31_SET          ((uint32_t)0x80000000U)         /* !< Event is unmasked */

/* GPIO_GEN_EVENT1_RIS Bits */
/* GPIO_GEN_EVENT1_RIS[DIO16] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO16_OFS            (16)                            /* !< DIO16 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO16_MASK           ((uint32_t)0x00010000U)         /* !< DIO16 event */
#define GPIO_GEN_EVENT1_RIS_DIO16_CLR            ((uint32_t)0x00000000U)         /* !< DIO16 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO16_SET            ((uint32_t)0x00010000U)         /* !< DIO16 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO17] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO17_OFS            (17)                            /* !< DIO17 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO17_MASK           ((uint32_t)0x00020000U)         /* !< DIO17 event */
#define GPIO_GEN_EVENT1_RIS_DIO17_CLR            ((uint32_t)0x00000000U)         /* !< DIO17 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO17_SET            ((uint32_t)0x00020000U)         /* !< DIO17 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO18] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO18_OFS            (18)                            /* !< DIO18 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO18_MASK           ((uint32_t)0x00040000U)         /* !< DIO18 event */
#define GPIO_GEN_EVENT1_RIS_DIO18_CLR            ((uint32_t)0x00000000U)         /* !< DIO18 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO18_SET            ((uint32_t)0x00040000U)         /* !< DIO18 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO19] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO19_OFS            (19)                            /* !< DIO19 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO19_MASK           ((uint32_t)0x00080000U)         /* !< DIO19 event */
#define GPIO_GEN_EVENT1_RIS_DIO19_CLR            ((uint32_t)0x00000000U)         /* !< DIO19 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO19_SET            ((uint32_t)0x00080000U)         /* !< DIO19 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO20] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO20_OFS            (20)                            /* !< DIO20 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO20_MASK           ((uint32_t)0x00100000U)         /* !< DIO20 event */
#define GPIO_GEN_EVENT1_RIS_DIO20_CLR            ((uint32_t)0x00000000U)         /* !< DIO20 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO20_SET            ((uint32_t)0x00100000U)         /* !< DIO20 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO21] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO21_OFS            (21)                            /* !< DIO21 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO21_MASK           ((uint32_t)0x00200000U)         /* !< DIO21 event */
#define GPIO_GEN_EVENT1_RIS_DIO21_CLR            ((uint32_t)0x00000000U)         /* !< DIO21 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO21_SET            ((uint32_t)0x00200000U)         /* !< DIO21 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO22] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO22_OFS            (22)                            /* !< DIO22 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO22_MASK           ((uint32_t)0x00400000U)         /* !< DIO22 event */
#define GPIO_GEN_EVENT1_RIS_DIO22_CLR            ((uint32_t)0x00000000U)         /* !< DIO22 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO22_SET            ((uint32_t)0x00400000U)         /* !< DIO22 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO23] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO23_OFS            (23)                            /* !< DIO23 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO23_MASK           ((uint32_t)0x00800000U)         /* !< DIO23 event */
#define GPIO_GEN_EVENT1_RIS_DIO23_CLR            ((uint32_t)0x00000000U)         /* !< DIO23 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO23_SET            ((uint32_t)0x00800000U)         /* !< DIO23 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO24] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO24_OFS            (24)                            /* !< DIO24 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO24_MASK           ((uint32_t)0x01000000U)         /* !< DIO24 event */
#define GPIO_GEN_EVENT1_RIS_DIO24_CLR            ((uint32_t)0x00000000U)         /* !< DIO24 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO24_SET            ((uint32_t)0x01000000U)         /* !< DIO24 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO25] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO25_OFS            (25)                            /* !< DIO25 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO25_MASK           ((uint32_t)0x02000000U)         /* !< DIO25 event */
#define GPIO_GEN_EVENT1_RIS_DIO25_CLR            ((uint32_t)0x00000000U)         /* !< DIO25 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO25_SET            ((uint32_t)0x02000000U)         /* !< DIO25 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO26] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO26_OFS            (26)                            /* !< DIO26 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO26_MASK           ((uint32_t)0x04000000U)         /* !< DIO26 event */
#define GPIO_GEN_EVENT1_RIS_DIO26_CLR            ((uint32_t)0x00000000U)         /* !< DIO26 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO26_SET            ((uint32_t)0x04000000U)         /* !< DIO26 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO27] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO27_OFS            (27)                            /* !< DIO27 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO27_MASK           ((uint32_t)0x08000000U)         /* !< DIO27 event */
#define GPIO_GEN_EVENT1_RIS_DIO27_CLR            ((uint32_t)0x00000000U)         /* !< DIO27 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO27_SET            ((uint32_t)0x08000000U)         /* !< DIO27 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO28] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO28_OFS            (28)                            /* !< DIO28 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO28_MASK           ((uint32_t)0x10000000U)         /* !< DIO28 event */
#define GPIO_GEN_EVENT1_RIS_DIO28_CLR            ((uint32_t)0x00000000U)         /* !< DIO28 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO28_SET            ((uint32_t)0x10000000U)         /* !< DIO28 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO29] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO29_OFS            (29)                            /* !< DIO29 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO29_MASK           ((uint32_t)0x20000000U)         /* !< DIO29 event */
#define GPIO_GEN_EVENT1_RIS_DIO29_CLR            ((uint32_t)0x00000000U)         /* !< DIO29 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO29_SET            ((uint32_t)0x20000000U)         /* !< DIO29 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO30] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO30_OFS            (30)                            /* !< DIO30 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO30_MASK           ((uint32_t)0x40000000U)         /* !< DIO30 event */
#define GPIO_GEN_EVENT1_RIS_DIO30_CLR            ((uint32_t)0x00000000U)         /* !< DIO30 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO30_SET            ((uint32_t)0x40000000U)         /* !< DIO30 event occurred */
/* GPIO_GEN_EVENT1_RIS[DIO31] Bits */
#define GPIO_GEN_EVENT1_RIS_DIO31_OFS            (31)                            /* !< DIO31 Offset */
#define GPIO_GEN_EVENT1_RIS_DIO31_MASK           ((uint32_t)0x80000000U)         /* !< DIO31 event */
#define GPIO_GEN_EVENT1_RIS_DIO31_CLR            ((uint32_t)0x00000000U)         /* !< DIO31 event did not occur */
#define GPIO_GEN_EVENT1_RIS_DIO31_SET            ((uint32_t)0x80000000U)         /* !< DIO31 event occurred */

/* GPIO_GEN_EVENT1_MIS Bits */
/* GPIO_GEN_EVENT1_MIS[DIO16] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO16_OFS            (16)                            /* !< DIO16 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO16_MASK           ((uint32_t)0x00010000U)         /* !< DIO16 event */
#define GPIO_GEN_EVENT1_MIS_DIO16_CLR            ((uint32_t)0x00000000U)         /* !< DIO16 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO16_SET            ((uint32_t)0x00010000U)         /* !< DIO16 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO17] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO17_OFS            (17)                            /* !< DIO17 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO17_MASK           ((uint32_t)0x00020000U)         /* !< DIO17 event */
#define GPIO_GEN_EVENT1_MIS_DIO17_CLR            ((uint32_t)0x00000000U)         /* !< DIO17 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO17_SET            ((uint32_t)0x00020000U)         /* !< DIO17 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO18] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO18_OFS            (18)                            /* !< DIO18 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO18_MASK           ((uint32_t)0x00040000U)         /* !< DIO18 event */
#define GPIO_GEN_EVENT1_MIS_DIO18_CLR            ((uint32_t)0x00000000U)         /* !< DIO18 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO18_SET            ((uint32_t)0x00040000U)         /* !< DIO18 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO19] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO19_OFS            (19)                            /* !< DIO19 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO19_MASK           ((uint32_t)0x00080000U)         /* !< DIO19 event */
#define GPIO_GEN_EVENT1_MIS_DIO19_CLR            ((uint32_t)0x00000000U)         /* !< DIO19 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO19_SET            ((uint32_t)0x00080000U)         /* !< DIO19 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO20] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO20_OFS            (20)                            /* !< DIO20 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO20_MASK           ((uint32_t)0x00100000U)         /* !< DIO20 event */
#define GPIO_GEN_EVENT1_MIS_DIO20_CLR            ((uint32_t)0x00000000U)         /* !< DIO20 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO20_SET            ((uint32_t)0x00100000U)         /* !< DIO20 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO21] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO21_OFS            (21)                            /* !< DIO21 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO21_MASK           ((uint32_t)0x00200000U)         /* !< DIO21 event */
#define GPIO_GEN_EVENT1_MIS_DIO21_CLR            ((uint32_t)0x00000000U)         /* !< DIO21 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO21_SET            ((uint32_t)0x00200000U)         /* !< DIO21 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO22] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO22_OFS            (22)                            /* !< DIO22 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO22_MASK           ((uint32_t)0x00400000U)         /* !< DIO22 event */
#define GPIO_GEN_EVENT1_MIS_DIO22_CLR            ((uint32_t)0x00000000U)         /* !< DIO22 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO22_SET            ((uint32_t)0x00400000U)         /* !< DIO22 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO23] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO23_OFS            (23)                            /* !< DIO23 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO23_MASK           ((uint32_t)0x00800000U)         /* !< DIO23 event */
#define GPIO_GEN_EVENT1_MIS_DIO23_CLR            ((uint32_t)0x00000000U)         /* !< DIO23 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO23_SET            ((uint32_t)0x00800000U)         /* !< DIO23 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO24] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO24_OFS            (24)                            /* !< DIO24 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO24_MASK           ((uint32_t)0x01000000U)         /* !< DIO24 event */
#define GPIO_GEN_EVENT1_MIS_DIO24_CLR            ((uint32_t)0x00000000U)         /* !< DIO24 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO24_SET            ((uint32_t)0x01000000U)         /* !< DIO24 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO25] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO25_OFS            (25)                            /* !< DIO25 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO25_MASK           ((uint32_t)0x02000000U)         /* !< DIO25 event */
#define GPIO_GEN_EVENT1_MIS_DIO25_CLR            ((uint32_t)0x00000000U)         /* !< DIO25 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO25_SET            ((uint32_t)0x02000000U)         /* !< DIO25 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO26] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO26_OFS            (26)                            /* !< DIO26 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO26_MASK           ((uint32_t)0x04000000U)         /* !< DIO26 event */
#define GPIO_GEN_EVENT1_MIS_DIO26_CLR            ((uint32_t)0x00000000U)         /* !< DIO26 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO26_SET            ((uint32_t)0x04000000U)         /* !< DIO26 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO27] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO27_OFS            (27)                            /* !< DIO27 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO27_MASK           ((uint32_t)0x08000000U)         /* !< DIO27 event */
#define GPIO_GEN_EVENT1_MIS_DIO27_CLR            ((uint32_t)0x00000000U)         /* !< DIO27 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO27_SET            ((uint32_t)0x08000000U)         /* !< DIO27 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO28] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO28_OFS            (28)                            /* !< DIO28 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO28_MASK           ((uint32_t)0x10000000U)         /* !< DIO28 event */
#define GPIO_GEN_EVENT1_MIS_DIO28_CLR            ((uint32_t)0x00000000U)         /* !< DIO28 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO28_SET            ((uint32_t)0x10000000U)         /* !< DIO28 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO29] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO29_OFS            (29)                            /* !< DIO29 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO29_MASK           ((uint32_t)0x20000000U)         /* !< DIO29 event */
#define GPIO_GEN_EVENT1_MIS_DIO29_CLR            ((uint32_t)0x00000000U)         /* !< DIO29 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO29_SET            ((uint32_t)0x20000000U)         /* !< DIO29 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO30] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO30_OFS            (30)                            /* !< DIO30 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO30_MASK           ((uint32_t)0x40000000U)         /* !< DIO30 event */
#define GPIO_GEN_EVENT1_MIS_DIO30_CLR            ((uint32_t)0x00000000U)         /* !< DIO30 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO30_SET            ((uint32_t)0x40000000U)         /* !< DIO30 event occurred */
/* GPIO_GEN_EVENT1_MIS[DIO31] Bits */
#define GPIO_GEN_EVENT1_MIS_DIO31_OFS            (31)                            /* !< DIO31 Offset */
#define GPIO_GEN_EVENT1_MIS_DIO31_MASK           ((uint32_t)0x80000000U)         /* !< DIO31 event */
#define GPIO_GEN_EVENT1_MIS_DIO31_CLR            ((uint32_t)0x00000000U)         /* !< DIO31 event did not occur */
#define GPIO_GEN_EVENT1_MIS_DIO31_SET            ((uint32_t)0x80000000U)         /* !< DIO31 event occurred */

/* GPIO_GEN_EVENT1_ISET Bits */
/* GPIO_GEN_EVENT1_ISET[DIO16] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO16_OFS           (16)                            /* !< DIO16 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO16_MASK          ((uint32_t)0x00010000U)         /* !< DIO16 event */
#define GPIO_GEN_EVENT1_ISET_DIO16_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO16_SET           ((uint32_t)0x00010000U)         /* !< Sets DIO16 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO17] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO17_OFS           (17)                            /* !< DIO17 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO17_MASK          ((uint32_t)0x00020000U)         /* !< DIO17 event */
#define GPIO_GEN_EVENT1_ISET_DIO17_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO17_SET           ((uint32_t)0x00020000U)         /* !< Sets DIO17 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO18] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO18_OFS           (18)                            /* !< DIO18 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO18_MASK          ((uint32_t)0x00040000U)         /* !< DIO18 event */
#define GPIO_GEN_EVENT1_ISET_DIO18_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO18_SET           ((uint32_t)0x00040000U)         /* !< Sets DIO18 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO19] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO19_OFS           (19)                            /* !< DIO19 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO19_MASK          ((uint32_t)0x00080000U)         /* !< DIO19 event */
#define GPIO_GEN_EVENT1_ISET_DIO19_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO19_SET           ((uint32_t)0x00080000U)         /* !< Sets DIO19 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO20] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO20_OFS           (20)                            /* !< DIO20 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO20_MASK          ((uint32_t)0x00100000U)         /* !< DIO20 event */
#define GPIO_GEN_EVENT1_ISET_DIO20_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO20_SET           ((uint32_t)0x00100000U)         /* !< Sets DIO20 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO21] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO21_OFS           (21)                            /* !< DIO21 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO21_MASK          ((uint32_t)0x00200000U)         /* !< DIO21 event */
#define GPIO_GEN_EVENT1_ISET_DIO21_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO21_SET           ((uint32_t)0x00200000U)         /* !< Sets DIO21 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO22] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO22_OFS           (22)                            /* !< DIO22 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO22_MASK          ((uint32_t)0x00400000U)         /* !< DIO22 event */
#define GPIO_GEN_EVENT1_ISET_DIO22_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO22_SET           ((uint32_t)0x00400000U)         /* !< Sets DIO22 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO23] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO23_OFS           (23)                            /* !< DIO23 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO23_MASK          ((uint32_t)0x00800000U)         /* !< DIO23 event */
#define GPIO_GEN_EVENT1_ISET_DIO23_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO23_SET           ((uint32_t)0x00800000U)         /* !< Sets DIO23 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO24] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO24_OFS           (24)                            /* !< DIO24 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO24_MASK          ((uint32_t)0x01000000U)         /* !< DIO24 event */
#define GPIO_GEN_EVENT1_ISET_DIO24_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO24_SET           ((uint32_t)0x01000000U)         /* !< Sets DIO24 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO25] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO25_OFS           (25)                            /* !< DIO25 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO25_MASK          ((uint32_t)0x02000000U)         /* !< DIO25 event */
#define GPIO_GEN_EVENT1_ISET_DIO25_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO25_SET           ((uint32_t)0x02000000U)         /* !< Sets DIO25 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO26] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO26_OFS           (26)                            /* !< DIO26 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO26_MASK          ((uint32_t)0x04000000U)         /* !< DIO26 event */
#define GPIO_GEN_EVENT1_ISET_DIO26_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO26_SET           ((uint32_t)0x04000000U)         /* !< Sets DIO26 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO27] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO27_OFS           (27)                            /* !< DIO27 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO27_MASK          ((uint32_t)0x08000000U)         /* !< DIO27 event */
#define GPIO_GEN_EVENT1_ISET_DIO27_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO27_SET           ((uint32_t)0x08000000U)         /* !< Sets DIO27 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO28] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO28_OFS           (28)                            /* !< DIO28 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO28_MASK          ((uint32_t)0x10000000U)         /* !< DIO28 event */
#define GPIO_GEN_EVENT1_ISET_DIO28_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO28_SET           ((uint32_t)0x10000000U)         /* !< Sets DIO28 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO29] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO29_OFS           (29)                            /* !< DIO29 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO29_MASK          ((uint32_t)0x20000000U)         /* !< DIO29 event */
#define GPIO_GEN_EVENT1_ISET_DIO29_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO29_SET           ((uint32_t)0x20000000U)         /* !< Sets DIO29 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO30] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO30_OFS           (30)                            /* !< DIO30 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO30_MASK          ((uint32_t)0x40000000U)         /* !< DIO30 event */
#define GPIO_GEN_EVENT1_ISET_DIO30_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO30_SET           ((uint32_t)0x40000000U)         /* !< Sets DIO30 in RIS register */
/* GPIO_GEN_EVENT1_ISET[DIO31] Bits */
#define GPIO_GEN_EVENT1_ISET_DIO31_OFS           (31)                            /* !< DIO31 Offset */
#define GPIO_GEN_EVENT1_ISET_DIO31_MASK          ((uint32_t)0x80000000U)         /* !< DIO31 event */
#define GPIO_GEN_EVENT1_ISET_DIO31_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ISET_DIO31_SET           ((uint32_t)0x80000000U)         /* !< Sets DIO31 in RIS register */

/* GPIO_GEN_EVENT1_ICLR Bits */
/* GPIO_GEN_EVENT1_ICLR[DIO16] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO16_OFS           (16)                            /* !< DIO16 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO16_MASK          ((uint32_t)0x00010000U)         /* !< DIO16 event */
#define GPIO_GEN_EVENT1_ICLR_DIO16_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO16_CLR           ((uint32_t)0x00010000U)         /* !< Clears DIO16 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO17] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO17_OFS           (17)                            /* !< DIO17 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO17_MASK          ((uint32_t)0x00020000U)         /* !< DIO17 event */
#define GPIO_GEN_EVENT1_ICLR_DIO17_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO17_CLR           ((uint32_t)0x00020000U)         /* !< Clears DIO17 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO18] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO18_OFS           (18)                            /* !< DIO18 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO18_MASK          ((uint32_t)0x00040000U)         /* !< DIO18 event */
#define GPIO_GEN_EVENT1_ICLR_DIO18_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO18_CLR           ((uint32_t)0x00040000U)         /* !< Clears DIO18 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO19] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO19_OFS           (19)                            /* !< DIO19 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO19_MASK          ((uint32_t)0x00080000U)         /* !< DIO19 event */
#define GPIO_GEN_EVENT1_ICLR_DIO19_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO19_CLR           ((uint32_t)0x00080000U)         /* !< Clears DIO19 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO20] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO20_OFS           (20)                            /* !< DIO20 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO20_MASK          ((uint32_t)0x00100000U)         /* !< DIO20 event */
#define GPIO_GEN_EVENT1_ICLR_DIO20_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO20_CLR           ((uint32_t)0x00100000U)         /* !< Clears DIO20 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO21] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO21_OFS           (21)                            /* !< DIO21 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO21_MASK          ((uint32_t)0x00200000U)         /* !< DIO21 event */
#define GPIO_GEN_EVENT1_ICLR_DIO21_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO21_CLR           ((uint32_t)0x00200000U)         /* !< Clears DIO21 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO22] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO22_OFS           (22)                            /* !< DIO22 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO22_MASK          ((uint32_t)0x00400000U)         /* !< DIO22 event */
#define GPIO_GEN_EVENT1_ICLR_DIO22_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO22_CLR           ((uint32_t)0x00400000U)         /* !< Clears DIO22 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO23] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO23_OFS           (23)                            /* !< DIO23 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO23_MASK          ((uint32_t)0x00800000U)         /* !< DIO23 event */
#define GPIO_GEN_EVENT1_ICLR_DIO23_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO23_CLR           ((uint32_t)0x00800000U)         /* !< Clears DIO23 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO24] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO24_OFS           (24)                            /* !< DIO24 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO24_MASK          ((uint32_t)0x01000000U)         /* !< DIO24 event */
#define GPIO_GEN_EVENT1_ICLR_DIO24_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO24_CLR           ((uint32_t)0x01000000U)         /* !< Clears DIO24 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO25] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO25_OFS           (25)                            /* !< DIO25 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO25_MASK          ((uint32_t)0x02000000U)         /* !< DIO25 event */
#define GPIO_GEN_EVENT1_ICLR_DIO25_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO25_CLR           ((uint32_t)0x02000000U)         /* !< Clears DIO25 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO26] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO26_OFS           (26)                            /* !< DIO26 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO26_MASK          ((uint32_t)0x04000000U)         /* !< DIO26 event */
#define GPIO_GEN_EVENT1_ICLR_DIO26_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO26_CLR           ((uint32_t)0x04000000U)         /* !< Clears DIO26 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO27] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO27_OFS           (27)                            /* !< DIO27 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO27_MASK          ((uint32_t)0x08000000U)         /* !< DIO27 event */
#define GPIO_GEN_EVENT1_ICLR_DIO27_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO27_CLR           ((uint32_t)0x08000000U)         /* !< Clears DIO27 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO28] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO28_OFS           (28)                            /* !< DIO28 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO28_MASK          ((uint32_t)0x10000000U)         /* !< DIO28 event */
#define GPIO_GEN_EVENT1_ICLR_DIO28_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO28_CLR           ((uint32_t)0x10000000U)         /* !< Clears DIO28 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO29] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO29_OFS           (29)                            /* !< DIO29 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO29_MASK          ((uint32_t)0x20000000U)         /* !< DIO29 event */
#define GPIO_GEN_EVENT1_ICLR_DIO29_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO29_CLR           ((uint32_t)0x20000000U)         /* !< Clears DIO29 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO30] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO30_OFS           (30)                            /* !< DIO30 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO30_MASK          ((uint32_t)0x40000000U)         /* !< DIO30 event */
#define GPIO_GEN_EVENT1_ICLR_DIO30_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO30_CLR           ((uint32_t)0x40000000U)         /* !< Clears DIO30 in RIS register */
/* GPIO_GEN_EVENT1_ICLR[DIO31] Bits */
#define GPIO_GEN_EVENT1_ICLR_DIO31_OFS           (31)                            /* !< DIO31 Offset */
#define GPIO_GEN_EVENT1_ICLR_DIO31_MASK          ((uint32_t)0x80000000U)         /* !< DIO31 event */
#define GPIO_GEN_EVENT1_ICLR_DIO31_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT1_ICLR_DIO31_CLR           ((uint32_t)0x80000000U)         /* !< Clears DIO31 in RIS register */

/* GPIO_GEN_EVENT0_IIDX Bits */
/* GPIO_GEN_EVENT0_IIDX[STAT] Bits */
#define GPIO_GEN_EVENT0_IIDX_STAT_OFS            (0)                             /* !< STAT Offset */
#define GPIO_GEN_EVENT0_IIDX_STAT_MASK           ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define GPIO_GEN_EVENT0_IIDX_STAT_NO_INTR        ((uint32_t)0x00000000U)         /* !< No bit is set means there is no
                                                                                    pending interrupt request */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO0           ((uint32_t)0x00000001U)         /* !< DIO0 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO1           ((uint32_t)0x00000002U)         /* !< DIO1 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO2           ((uint32_t)0x00000003U)         /* !< DIO2 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO3           ((uint32_t)0x00000004U)         /* !< DIO3 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO4           ((uint32_t)0x00000005U)         /* !< DIO4 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO5           ((uint32_t)0x00000006U)         /* !< DIO5 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO6           ((uint32_t)0x00000007U)         /* !< DIO6 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO7           ((uint32_t)0x00000008U)         /* !< DIO7 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO8           ((uint32_t)0x00000009U)         /* !< DIO8 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO9           ((uint32_t)0x0000000AU)         /* !< DIO9 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO10          ((uint32_t)0x0000000BU)         /* !< DIO10 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO11          ((uint32_t)0x0000000CU)         /* !< DIO11 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO12          ((uint32_t)0x0000000DU)         /* !< DIO12 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO13          ((uint32_t)0x0000000EU)         /* !< DIO13 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO14          ((uint32_t)0x0000000FU)         /* !< DIO14 interrupt */
#define GPIO_GEN_EVENT0_IIDX_STAT_DIO15          ((uint32_t)0x00000010U)         /* !< DIO15 interrupt */

/* GPIO_GEN_EVENT0_IMASK Bits */
/* GPIO_GEN_EVENT0_IMASK[DIO0] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO0_OFS           (0)                             /* !< DIO0 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO0_MASK          ((uint32_t)0x00000001U)         /* !< DIO0 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO0_CLR           ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO0_SET           ((uint32_t)0x00000001U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO1] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO1_OFS           (1)                             /* !< DIO1 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO1_MASK          ((uint32_t)0x00000002U)         /* !< DIO1 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO1_CLR           ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO1_SET           ((uint32_t)0x00000002U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO2] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO2_OFS           (2)                             /* !< DIO2 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO2_MASK          ((uint32_t)0x00000004U)         /* !< DIO2 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO2_CLR           ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO2_SET           ((uint32_t)0x00000004U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO3] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO3_OFS           (3)                             /* !< DIO3 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO3_MASK          ((uint32_t)0x00000008U)         /* !< DIO3 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO3_CLR           ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO3_SET           ((uint32_t)0x00000008U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO4] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO4_OFS           (4)                             /* !< DIO4 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO4_MASK          ((uint32_t)0x00000010U)         /* !< DIO4 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO4_CLR           ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO4_SET           ((uint32_t)0x00000010U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO5] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO5_OFS           (5)                             /* !< DIO5 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO5_MASK          ((uint32_t)0x00000020U)         /* !< DIO5 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO5_CLR           ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO5_SET           ((uint32_t)0x00000020U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO6] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO6_OFS           (6)                             /* !< DIO6 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO6_MASK          ((uint32_t)0x00000040U)         /* !< DIO6 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO6_CLR           ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO6_SET           ((uint32_t)0x00000040U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO7] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO7_OFS           (7)                             /* !< DIO7 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO7_MASK          ((uint32_t)0x00000080U)         /* !< DIO7 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO7_CLR           ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO7_SET           ((uint32_t)0x00000080U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO8] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO8_OFS           (8)                             /* !< DIO8 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO8_MASK          ((uint32_t)0x00000100U)         /* !< DIO8 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO8_CLR           ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO8_SET           ((uint32_t)0x00000100U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO9] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO9_OFS           (9)                             /* !< DIO9 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO9_MASK          ((uint32_t)0x00000200U)         /* !< DIO9 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO9_CLR           ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO9_SET           ((uint32_t)0x00000200U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO10] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO10_OFS          (10)                            /* !< DIO10 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO10_MASK         ((uint32_t)0x00000400U)         /* !< DIO10 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO10_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO10_SET          ((uint32_t)0x00000400U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO11] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO11_OFS          (11)                            /* !< DIO11 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO11_MASK         ((uint32_t)0x00000800U)         /* !< DIO11 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO11_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO11_SET          ((uint32_t)0x00000800U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO12] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO12_OFS          (12)                            /* !< DIO12 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO12_MASK         ((uint32_t)0x00001000U)         /* !< DIO12 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO12_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO12_SET          ((uint32_t)0x00001000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO13] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO13_OFS          (13)                            /* !< DIO13 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO13_MASK         ((uint32_t)0x00002000U)         /* !< DIO13 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO13_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO13_SET          ((uint32_t)0x00002000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO14] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO14_OFS          (14)                            /* !< DIO14 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO14_MASK         ((uint32_t)0x00004000U)         /* !< DIO14 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO14_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO14_SET          ((uint32_t)0x00004000U)         /* !< Event is unmasked */
/* GPIO_GEN_EVENT0_IMASK[DIO15] Bits */
#define GPIO_GEN_EVENT0_IMASK_DIO15_OFS          (15)                            /* !< DIO15 Offset */
#define GPIO_GEN_EVENT0_IMASK_DIO15_MASK         ((uint32_t)0x00008000U)         /* !< DIO15 event mask */
#define GPIO_GEN_EVENT0_IMASK_DIO15_CLR          ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_GEN_EVENT0_IMASK_DIO15_SET          ((uint32_t)0x00008000U)         /* !< Event is unmasked */

/* GPIO_GEN_EVENT0_RIS Bits */
/* GPIO_GEN_EVENT0_RIS[DIO0] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO0_OFS             (0)                             /* !< DIO0 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO0_MASK            ((uint32_t)0x00000001U)         /* !< DIO0 event */
#define GPIO_GEN_EVENT0_RIS_DIO0_CLR             ((uint32_t)0x00000000U)         /* !< DIO0 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO0_SET             ((uint32_t)0x00000001U)         /* !< DIO0 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO1] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO1_OFS             (1)                             /* !< DIO1 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO1_MASK            ((uint32_t)0x00000002U)         /* !< DIO1 event */
#define GPIO_GEN_EVENT0_RIS_DIO1_CLR             ((uint32_t)0x00000000U)         /* !< DIO1 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO1_SET             ((uint32_t)0x00000002U)         /* !< DIO1 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO2] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO2_OFS             (2)                             /* !< DIO2 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO2_MASK            ((uint32_t)0x00000004U)         /* !< DIO2 event */
#define GPIO_GEN_EVENT0_RIS_DIO2_CLR             ((uint32_t)0x00000000U)         /* !< DIO2 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO2_SET             ((uint32_t)0x00000004U)         /* !< DIO2 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO3] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO3_OFS             (3)                             /* !< DIO3 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO3_MASK            ((uint32_t)0x00000008U)         /* !< DIO3 event */
#define GPIO_GEN_EVENT0_RIS_DIO3_CLR             ((uint32_t)0x00000000U)         /* !< DIO3 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO3_SET             ((uint32_t)0x00000008U)         /* !< DIO3 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO4] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO4_OFS             (4)                             /* !< DIO4 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO4_MASK            ((uint32_t)0x00000010U)         /* !< DIO4 event */
#define GPIO_GEN_EVENT0_RIS_DIO4_CLR             ((uint32_t)0x00000000U)         /* !< DIO4 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO4_SET             ((uint32_t)0x00000010U)         /* !< DIO4 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO5] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO5_OFS             (5)                             /* !< DIO5 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO5_MASK            ((uint32_t)0x00000020U)         /* !< DIO5 event */
#define GPIO_GEN_EVENT0_RIS_DIO5_CLR             ((uint32_t)0x00000000U)         /* !< DIO5 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO5_SET             ((uint32_t)0x00000020U)         /* !< DIO5 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO6] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO6_OFS             (6)                             /* !< DIO6 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO6_MASK            ((uint32_t)0x00000040U)         /* !< DIO6 event */
#define GPIO_GEN_EVENT0_RIS_DIO6_CLR             ((uint32_t)0x00000000U)         /* !< DIO6 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO6_SET             ((uint32_t)0x00000040U)         /* !< DIO6 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO7] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO7_OFS             (7)                             /* !< DIO7 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO7_MASK            ((uint32_t)0x00000080U)         /* !< DIO7 event */
#define GPIO_GEN_EVENT0_RIS_DIO7_CLR             ((uint32_t)0x00000000U)         /* !< DIO7 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO7_SET             ((uint32_t)0x00000080U)         /* !< DIO7 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO8] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO8_OFS             (8)                             /* !< DIO8 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO8_MASK            ((uint32_t)0x00000100U)         /* !< DIO8 event */
#define GPIO_GEN_EVENT0_RIS_DIO8_CLR             ((uint32_t)0x00000000U)         /* !< DIO8 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO8_SET             ((uint32_t)0x00000100U)         /* !< DIO8 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO9] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO9_OFS             (9)                             /* !< DIO9 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO9_MASK            ((uint32_t)0x00000200U)         /* !< DIO9 event */
#define GPIO_GEN_EVENT0_RIS_DIO9_CLR             ((uint32_t)0x00000000U)         /* !< DIO9 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO9_SET             ((uint32_t)0x00000200U)         /* !< DIO9 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO10] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO10_OFS            (10)                            /* !< DIO10 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO10_MASK           ((uint32_t)0x00000400U)         /* !< DIO10 event */
#define GPIO_GEN_EVENT0_RIS_DIO10_CLR            ((uint32_t)0x00000000U)         /* !< DIO10 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO10_SET            ((uint32_t)0x00000400U)         /* !< DIO10 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO11] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO11_OFS            (11)                            /* !< DIO11 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO11_MASK           ((uint32_t)0x00000800U)         /* !< DIO11 event */
#define GPIO_GEN_EVENT0_RIS_DIO11_CLR            ((uint32_t)0x00000000U)         /* !< DIO11 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO11_SET            ((uint32_t)0x00000800U)         /* !< DIO11 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO12] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO12_OFS            (12)                            /* !< DIO12 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO12_MASK           ((uint32_t)0x00001000U)         /* !< DIO12 event */
#define GPIO_GEN_EVENT0_RIS_DIO12_CLR            ((uint32_t)0x00000000U)         /* !< DIO12 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO12_SET            ((uint32_t)0x00001000U)         /* !< DIO12 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO13] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO13_OFS            (13)                            /* !< DIO13 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO13_MASK           ((uint32_t)0x00002000U)         /* !< DIO13 event */
#define GPIO_GEN_EVENT0_RIS_DIO13_CLR            ((uint32_t)0x00000000U)         /* !< DIO13 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO13_SET            ((uint32_t)0x00002000U)         /* !< DIO13 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO14] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO14_OFS            (14)                            /* !< DIO14 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO14_MASK           ((uint32_t)0x00004000U)         /* !< DIO14 event */
#define GPIO_GEN_EVENT0_RIS_DIO14_CLR            ((uint32_t)0x00000000U)         /* !< DIO14 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO14_SET            ((uint32_t)0x00004000U)         /* !< DIO14 event occurred */
/* GPIO_GEN_EVENT0_RIS[DIO15] Bits */
#define GPIO_GEN_EVENT0_RIS_DIO15_OFS            (15)                            /* !< DIO15 Offset */
#define GPIO_GEN_EVENT0_RIS_DIO15_MASK           ((uint32_t)0x00008000U)         /* !< DIO15 event */
#define GPIO_GEN_EVENT0_RIS_DIO15_CLR            ((uint32_t)0x00000000U)         /* !< DIO15 event did not occur */
#define GPIO_GEN_EVENT0_RIS_DIO15_SET            ((uint32_t)0x00008000U)         /* !< DIO15 event occurred */

/* GPIO_GEN_EVENT0_MIS Bits */
/* GPIO_GEN_EVENT0_MIS[DIO0] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO0_OFS             (0)                             /* !< DIO0 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO0_MASK            ((uint32_t)0x00000001U)         /* !< DIO0 event */
#define GPIO_GEN_EVENT0_MIS_DIO0_CLR             ((uint32_t)0x00000000U)         /* !< DIO0 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO0_SET             ((uint32_t)0x00000001U)         /* !< DIO0 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO1] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO1_OFS             (1)                             /* !< DIO1 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO1_MASK            ((uint32_t)0x00000002U)         /* !< DIO1 event */
#define GPIO_GEN_EVENT0_MIS_DIO1_CLR             ((uint32_t)0x00000000U)         /* !< DIO1 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO1_SET             ((uint32_t)0x00000002U)         /* !< DIO1 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO2] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO2_OFS             (2)                             /* !< DIO2 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO2_MASK            ((uint32_t)0x00000004U)         /* !< DIO2 event */
#define GPIO_GEN_EVENT0_MIS_DIO2_CLR             ((uint32_t)0x00000000U)         /* !< DIO2 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO2_SET             ((uint32_t)0x00000004U)         /* !< DIO2 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO3] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO3_OFS             (3)                             /* !< DIO3 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO3_MASK            ((uint32_t)0x00000008U)         /* !< DIO3 event */
#define GPIO_GEN_EVENT0_MIS_DIO3_CLR             ((uint32_t)0x00000000U)         /* !< DIO3 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO3_SET             ((uint32_t)0x00000008U)         /* !< DIO3 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO4] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO4_OFS             (4)                             /* !< DIO4 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO4_MASK            ((uint32_t)0x00000010U)         /* !< DIO4 event */
#define GPIO_GEN_EVENT0_MIS_DIO4_CLR             ((uint32_t)0x00000000U)         /* !< DIO4 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO4_SET             ((uint32_t)0x00000010U)         /* !< DIO4 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO5] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO5_OFS             (5)                             /* !< DIO5 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO5_MASK            ((uint32_t)0x00000020U)         /* !< DIO5 event */
#define GPIO_GEN_EVENT0_MIS_DIO5_CLR             ((uint32_t)0x00000000U)         /* !< DIO5 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO5_SET             ((uint32_t)0x00000020U)         /* !< DIO5 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO6] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO6_OFS             (6)                             /* !< DIO6 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO6_MASK            ((uint32_t)0x00000040U)         /* !< DIO6 event */
#define GPIO_GEN_EVENT0_MIS_DIO6_CLR             ((uint32_t)0x00000000U)         /* !< DIO6 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO6_SET             ((uint32_t)0x00000040U)         /* !< DIO6 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO7] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO7_OFS             (7)                             /* !< DIO7 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO7_MASK            ((uint32_t)0x00000080U)         /* !< DIO7 event */
#define GPIO_GEN_EVENT0_MIS_DIO7_CLR             ((uint32_t)0x00000000U)         /* !< DIO7 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO7_SET             ((uint32_t)0x00000080U)         /* !< DIO7 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO8] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO8_OFS             (8)                             /* !< DIO8 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO8_MASK            ((uint32_t)0x00000100U)         /* !< DIO8 event */
#define GPIO_GEN_EVENT0_MIS_DIO8_CLR             ((uint32_t)0x00000000U)         /* !< DIO8 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO8_SET             ((uint32_t)0x00000100U)         /* !< DIO8 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO9] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO9_OFS             (9)                             /* !< DIO9 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO9_MASK            ((uint32_t)0x00000200U)         /* !< DIO9 event */
#define GPIO_GEN_EVENT0_MIS_DIO9_CLR             ((uint32_t)0x00000000U)         /* !< DIO9 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO9_SET             ((uint32_t)0x00000200U)         /* !< DIO9 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO10] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO10_OFS            (10)                            /* !< DIO10 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO10_MASK           ((uint32_t)0x00000400U)         /* !< DIO10 event */
#define GPIO_GEN_EVENT0_MIS_DIO10_CLR            ((uint32_t)0x00000000U)         /* !< DIO10 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO10_SET            ((uint32_t)0x00000400U)         /* !< DIO10 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO11] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO11_OFS            (11)                            /* !< DIO11 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO11_MASK           ((uint32_t)0x00000800U)         /* !< DIO11 event */
#define GPIO_GEN_EVENT0_MIS_DIO11_CLR            ((uint32_t)0x00000000U)         /* !< DIO11 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO11_SET            ((uint32_t)0x00000800U)         /* !< DIO11 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO12] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO12_OFS            (12)                            /* !< DIO12 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO12_MASK           ((uint32_t)0x00001000U)         /* !< DIO12 event */
#define GPIO_GEN_EVENT0_MIS_DIO12_CLR            ((uint32_t)0x00000000U)         /* !< DIO12 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO12_SET            ((uint32_t)0x00001000U)         /* !< DIO12 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO13] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO13_OFS            (13)                            /* !< DIO13 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO13_MASK           ((uint32_t)0x00002000U)         /* !< DIO13 event */
#define GPIO_GEN_EVENT0_MIS_DIO13_CLR            ((uint32_t)0x00000000U)         /* !< DIO13 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO13_SET            ((uint32_t)0x00002000U)         /* !< DIO13 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO14] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO14_OFS            (14)                            /* !< DIO14 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO14_MASK           ((uint32_t)0x00004000U)         /* !< DIO14 event */
#define GPIO_GEN_EVENT0_MIS_DIO14_CLR            ((uint32_t)0x00000000U)         /* !< DIO14 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO14_SET            ((uint32_t)0x00004000U)         /* !< DIO14 event occurred */
/* GPIO_GEN_EVENT0_MIS[DIO15] Bits */
#define GPIO_GEN_EVENT0_MIS_DIO15_OFS            (15)                            /* !< DIO15 Offset */
#define GPIO_GEN_EVENT0_MIS_DIO15_MASK           ((uint32_t)0x00008000U)         /* !< DIO15 event */
#define GPIO_GEN_EVENT0_MIS_DIO15_CLR            ((uint32_t)0x00000000U)         /* !< DIO15 event did not occur */
#define GPIO_GEN_EVENT0_MIS_DIO15_SET            ((uint32_t)0x00008000U)         /* !< DIO15 event occurred */

/* GPIO_GEN_EVENT0_ISET Bits */
/* GPIO_GEN_EVENT0_ISET[DIO0] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO0_OFS            (0)                             /* !< DIO0 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO0_MASK           ((uint32_t)0x00000001U)         /* !< DIO0 event */
#define GPIO_GEN_EVENT0_ISET_DIO0_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO0_SET            ((uint32_t)0x00000001U)         /* !< Sets DIO0 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO1] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO1_OFS            (1)                             /* !< DIO1 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO1_MASK           ((uint32_t)0x00000002U)         /* !< DIO1 event */
#define GPIO_GEN_EVENT0_ISET_DIO1_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO1_SET            ((uint32_t)0x00000002U)         /* !< Sets DIO1 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO2] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO2_OFS            (2)                             /* !< DIO2 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO2_MASK           ((uint32_t)0x00000004U)         /* !< DIO2 event */
#define GPIO_GEN_EVENT0_ISET_DIO2_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO2_SET            ((uint32_t)0x00000004U)         /* !< Sets DIO2 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO3] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO3_OFS            (3)                             /* !< DIO3 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO3_MASK           ((uint32_t)0x00000008U)         /* !< DIO3 event */
#define GPIO_GEN_EVENT0_ISET_DIO3_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO3_SET            ((uint32_t)0x00000008U)         /* !< Sets DIO3 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO4] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO4_OFS            (4)                             /* !< DIO4 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO4_MASK           ((uint32_t)0x00000010U)         /* !< DIO4 event */
#define GPIO_GEN_EVENT0_ISET_DIO4_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO4_SET            ((uint32_t)0x00000010U)         /* !< Sets DIO4 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO5] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO5_OFS            (5)                             /* !< DIO5 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO5_MASK           ((uint32_t)0x00000020U)         /* !< DIO5 event */
#define GPIO_GEN_EVENT0_ISET_DIO5_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO5_SET            ((uint32_t)0x00000020U)         /* !< Sets DIO5 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO6] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO6_OFS            (6)                             /* !< DIO6 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO6_MASK           ((uint32_t)0x00000040U)         /* !< DIO6 event */
#define GPIO_GEN_EVENT0_ISET_DIO6_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO6_SET            ((uint32_t)0x00000040U)         /* !< Sets DIO6 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO7] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO7_OFS            (7)                             /* !< DIO7 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO7_MASK           ((uint32_t)0x00000080U)         /* !< DIO7 event */
#define GPIO_GEN_EVENT0_ISET_DIO7_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO7_SET            ((uint32_t)0x00000080U)         /* !< Sets DIO7 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO8] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO8_OFS            (8)                             /* !< DIO8 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO8_MASK           ((uint32_t)0x00000100U)         /* !< DIO8 event */
#define GPIO_GEN_EVENT0_ISET_DIO8_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO8_SET            ((uint32_t)0x00000100U)         /* !< Sets DIO8 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO9] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO9_OFS            (9)                             /* !< DIO9 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO9_MASK           ((uint32_t)0x00000200U)         /* !< DIO9 event */
#define GPIO_GEN_EVENT0_ISET_DIO9_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO9_SET            ((uint32_t)0x00000200U)         /* !< Sets DIO9 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO10] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO10_OFS           (10)                            /* !< DIO10 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO10_MASK          ((uint32_t)0x00000400U)         /* !< DIO10 event */
#define GPIO_GEN_EVENT0_ISET_DIO10_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO10_SET           ((uint32_t)0x00000400U)         /* !< Sets DIO10 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO11] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO11_OFS           (11)                            /* !< DIO11 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO11_MASK          ((uint32_t)0x00000800U)         /* !< DIO11 event */
#define GPIO_GEN_EVENT0_ISET_DIO11_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO11_SET           ((uint32_t)0x00000800U)         /* !< Sets DIO11 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO12] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO12_OFS           (12)                            /* !< DIO12 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO12_MASK          ((uint32_t)0x00001000U)         /* !< DIO12 event */
#define GPIO_GEN_EVENT0_ISET_DIO12_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO12_SET           ((uint32_t)0x00001000U)         /* !< Sets DIO12 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO13] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO13_OFS           (13)                            /* !< DIO13 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO13_MASK          ((uint32_t)0x00002000U)         /* !< DIO13 event */
#define GPIO_GEN_EVENT0_ISET_DIO13_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO13_SET           ((uint32_t)0x00002000U)         /* !< Sets DIO13 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO14] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO14_OFS           (14)                            /* !< DIO14 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO14_MASK          ((uint32_t)0x00004000U)         /* !< DIO14 event */
#define GPIO_GEN_EVENT0_ISET_DIO14_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO14_SET           ((uint32_t)0x00004000U)         /* !< Sets DIO14 in RIS register */
/* GPIO_GEN_EVENT0_ISET[DIO15] Bits */
#define GPIO_GEN_EVENT0_ISET_DIO15_OFS           (15)                            /* !< DIO15 Offset */
#define GPIO_GEN_EVENT0_ISET_DIO15_MASK          ((uint32_t)0x00008000U)         /* !< DIO15 event */
#define GPIO_GEN_EVENT0_ISET_DIO15_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ISET_DIO15_SET           ((uint32_t)0x00008000U)         /* !< Sets DIO15 in RIS register */

/* GPIO_GEN_EVENT0_ICLR Bits */
/* GPIO_GEN_EVENT0_ICLR[DIO0] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO0_OFS            (0)                             /* !< DIO0 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO0_MASK           ((uint32_t)0x00000001U)         /* !< DIO0 event */
#define GPIO_GEN_EVENT0_ICLR_DIO0_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO0_CLR            ((uint32_t)0x00000001U)         /* !< Clears DIO0 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO1] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO1_OFS            (1)                             /* !< DIO1 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO1_MASK           ((uint32_t)0x00000002U)         /* !< DIO1 event */
#define GPIO_GEN_EVENT0_ICLR_DIO1_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO1_CLR            ((uint32_t)0x00000002U)         /* !< Clears DIO1 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO2] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO2_OFS            (2)                             /* !< DIO2 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO2_MASK           ((uint32_t)0x00000004U)         /* !< DIO2 event */
#define GPIO_GEN_EVENT0_ICLR_DIO2_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO2_CLR            ((uint32_t)0x00000004U)         /* !< Clears DIO2 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO3] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO3_OFS            (3)                             /* !< DIO3 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO3_MASK           ((uint32_t)0x00000008U)         /* !< DIO3 event */
#define GPIO_GEN_EVENT0_ICLR_DIO3_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO3_CLR            ((uint32_t)0x00000008U)         /* !< Clears DIO3 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO4] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO4_OFS            (4)                             /* !< DIO4 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO4_MASK           ((uint32_t)0x00000010U)         /* !< DIO4 event */
#define GPIO_GEN_EVENT0_ICLR_DIO4_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO4_CLR            ((uint32_t)0x00000010U)         /* !< Clears DIO4 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO5] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO5_OFS            (5)                             /* !< DIO5 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO5_MASK           ((uint32_t)0x00000020U)         /* !< DIO5 event */
#define GPIO_GEN_EVENT0_ICLR_DIO5_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO5_CLR            ((uint32_t)0x00000020U)         /* !< Clears DIO5 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO6] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO6_OFS            (6)                             /* !< DIO6 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO6_MASK           ((uint32_t)0x00000040U)         /* !< DIO6 event */
#define GPIO_GEN_EVENT0_ICLR_DIO6_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO6_CLR            ((uint32_t)0x00000040U)         /* !< Clears DIO6 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO7] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO7_OFS            (7)                             /* !< DIO7 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO7_MASK           ((uint32_t)0x00000080U)         /* !< DIO7 event */
#define GPIO_GEN_EVENT0_ICLR_DIO7_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO7_CLR            ((uint32_t)0x00000080U)         /* !< Clears DIO7 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO8] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO8_OFS            (8)                             /* !< DIO8 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO8_MASK           ((uint32_t)0x00000100U)         /* !< DIO8 event */
#define GPIO_GEN_EVENT0_ICLR_DIO8_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO8_CLR            ((uint32_t)0x00000100U)         /* !< Clears DIO8 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO9] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO9_OFS            (9)                             /* !< DIO9 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO9_MASK           ((uint32_t)0x00000200U)         /* !< DIO9 event */
#define GPIO_GEN_EVENT0_ICLR_DIO9_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO9_CLR            ((uint32_t)0x00000200U)         /* !< Clears DIO9 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO10] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO10_OFS           (10)                            /* !< DIO10 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO10_MASK          ((uint32_t)0x00000400U)         /* !< DIO10 event */
#define GPIO_GEN_EVENT0_ICLR_DIO10_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO10_CLR           ((uint32_t)0x00000400U)         /* !< Clears DIO10 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO11] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO11_OFS           (11)                            /* !< DIO11 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO11_MASK          ((uint32_t)0x00000800U)         /* !< DIO11 event */
#define GPIO_GEN_EVENT0_ICLR_DIO11_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO11_CLR           ((uint32_t)0x00000800U)         /* !< Clears DIO11 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO12] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO12_OFS           (12)                            /* !< DIO12 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO12_MASK          ((uint32_t)0x00001000U)         /* !< DIO12 event */
#define GPIO_GEN_EVENT0_ICLR_DIO12_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO12_CLR           ((uint32_t)0x00001000U)         /* !< Clears DIO12 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO13] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO13_OFS           (13)                            /* !< DIO13 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO13_MASK          ((uint32_t)0x00002000U)         /* !< DIO13 event */
#define GPIO_GEN_EVENT0_ICLR_DIO13_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO13_CLR           ((uint32_t)0x00002000U)         /* !< Clears DIO13 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO14] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO14_OFS           (14)                            /* !< DIO14 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO14_MASK          ((uint32_t)0x00004000U)         /* !< DIO14 event */
#define GPIO_GEN_EVENT0_ICLR_DIO14_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO14_CLR           ((uint32_t)0x00004000U)         /* !< Clears DIO14 in RIS register */
/* GPIO_GEN_EVENT0_ICLR[DIO15] Bits */
#define GPIO_GEN_EVENT0_ICLR_DIO15_OFS           (15)                            /* !< DIO15 Offset */
#define GPIO_GEN_EVENT0_ICLR_DIO15_MASK          ((uint32_t)0x00008000U)         /* !< DIO15 event */
#define GPIO_GEN_EVENT0_ICLR_DIO15_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_GEN_EVENT0_ICLR_DIO15_CLR           ((uint32_t)0x00008000U)         /* !< Clears DIO15 in RIS register */

/* GPIO_CPU_INT_IIDX Bits */
/* GPIO_CPU_INT_IIDX[STAT] Bits */
#define GPIO_CPU_INT_IIDX_STAT_OFS               (0)                             /* !< STAT Offset */
#define GPIO_CPU_INT_IIDX_STAT_MASK              ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define GPIO_CPU_INT_IIDX_STAT_NO_INTR           ((uint32_t)0x00000000U)         /* !< No bit is set means there is no
                                                                                    pending interrupt request */
#define GPIO_CPU_INT_IIDX_STAT_DIO0              ((uint32_t)0x00000001U)         /* !< DIO0 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO1              ((uint32_t)0x00000002U)         /* !< DIO1 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO2              ((uint32_t)0x00000003U)         /* !< DIO2 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO3              ((uint32_t)0x00000004U)         /* !< DIO3 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO4              ((uint32_t)0x00000005U)         /* !< DIO4 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO5              ((uint32_t)0x00000006U)         /* !< DIO5 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO6              ((uint32_t)0x00000007U)         /* !< DIO6 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO7              ((uint32_t)0x00000008U)         /* !< DIO7 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO8              ((uint32_t)0x00000009U)         /* !< DIO8 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO9              ((uint32_t)0x0000000AU)         /* !< DIO9 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO10             ((uint32_t)0x0000000BU)         /* !< DIO10 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO11             ((uint32_t)0x0000000CU)         /* !< DIO11 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO12             ((uint32_t)0x0000000DU)         /* !< DIO12 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO13             ((uint32_t)0x0000000EU)         /* !< DIO13 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO14             ((uint32_t)0x0000000FU)         /* !< DIO14 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO15             ((uint32_t)0x00000010U)         /* !< DIO15 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO16             ((uint32_t)0x00000011U)         /* !< DIO16 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO17             ((uint32_t)0x00000012U)         /* !< DIO17 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO18             ((uint32_t)0x00000013U)         /* !< DIO18 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO19             ((uint32_t)0x00000014U)         /* !< DIO19 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO20             ((uint32_t)0x00000015U)         /* !< DIO20 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO21             ((uint32_t)0x00000016U)         /* !< DIO21 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO22             ((uint32_t)0x00000017U)         /* !< DIO22 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO23             ((uint32_t)0x00000018U)         /* !< DIO23 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO24             ((uint32_t)0x00000019U)         /* !< DIO24 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO25             ((uint32_t)0x0000001AU)         /* !< DIO25 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO26             ((uint32_t)0x0000001BU)         /* !< DIO26 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO27             ((uint32_t)0x0000001CU)         /* !< DIO27 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO28             ((uint32_t)0x0000001DU)         /* !< DIO28 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO29             ((uint32_t)0x0000001EU)         /* !< DIO29 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO30             ((uint32_t)0x0000001FU)         /* !< DIO30 interrupt */
#define GPIO_CPU_INT_IIDX_STAT_DIO31             ((uint32_t)0x00000020U)         /* !< DIO31 interrupt */

/* GPIO_CPU_INT_IMASK Bits */
/* GPIO_CPU_INT_IMASK[DIO0] Bits */
#define GPIO_CPU_INT_IMASK_DIO0_OFS              (0)                             /* !< DIO0 Offset */
#define GPIO_CPU_INT_IMASK_DIO0_MASK             ((uint32_t)0x00000001U)         /* !< DIO0 event mask */
#define GPIO_CPU_INT_IMASK_DIO0_CLR              ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO0_SET              ((uint32_t)0x00000001U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO1] Bits */
#define GPIO_CPU_INT_IMASK_DIO1_OFS              (1)                             /* !< DIO1 Offset */
#define GPIO_CPU_INT_IMASK_DIO1_MASK             ((uint32_t)0x00000002U)         /* !< DIO1 event mask */
#define GPIO_CPU_INT_IMASK_DIO1_CLR              ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO1_SET              ((uint32_t)0x00000002U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO2] Bits */
#define GPIO_CPU_INT_IMASK_DIO2_OFS              (2)                             /* !< DIO2 Offset */
#define GPIO_CPU_INT_IMASK_DIO2_MASK             ((uint32_t)0x00000004U)         /* !< DIO2 event mask */
#define GPIO_CPU_INT_IMASK_DIO2_CLR              ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO2_SET              ((uint32_t)0x00000004U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO3] Bits */
#define GPIO_CPU_INT_IMASK_DIO3_OFS              (3)                             /* !< DIO3 Offset */
#define GPIO_CPU_INT_IMASK_DIO3_MASK             ((uint32_t)0x00000008U)         /* !< DIO3 event mask */
#define GPIO_CPU_INT_IMASK_DIO3_CLR              ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO3_SET              ((uint32_t)0x00000008U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO4] Bits */
#define GPIO_CPU_INT_IMASK_DIO4_OFS              (4)                             /* !< DIO4 Offset */
#define GPIO_CPU_INT_IMASK_DIO4_MASK             ((uint32_t)0x00000010U)         /* !< DIO4 event mask */
#define GPIO_CPU_INT_IMASK_DIO4_CLR              ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO4_SET              ((uint32_t)0x00000010U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO5] Bits */
#define GPIO_CPU_INT_IMASK_DIO5_OFS              (5)                             /* !< DIO5 Offset */
#define GPIO_CPU_INT_IMASK_DIO5_MASK             ((uint32_t)0x00000020U)         /* !< DIO5 event mask */
#define GPIO_CPU_INT_IMASK_DIO5_CLR              ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO5_SET              ((uint32_t)0x00000020U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO6] Bits */
#define GPIO_CPU_INT_IMASK_DIO6_OFS              (6)                             /* !< DIO6 Offset */
#define GPIO_CPU_INT_IMASK_DIO6_MASK             ((uint32_t)0x00000040U)         /* !< DIO6 event mask */
#define GPIO_CPU_INT_IMASK_DIO6_CLR              ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO6_SET              ((uint32_t)0x00000040U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO7] Bits */
#define GPIO_CPU_INT_IMASK_DIO7_OFS              (7)                             /* !< DIO7 Offset */
#define GPIO_CPU_INT_IMASK_DIO7_MASK             ((uint32_t)0x00000080U)         /* !< DIO7 event mask */
#define GPIO_CPU_INT_IMASK_DIO7_CLR              ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO7_SET              ((uint32_t)0x00000080U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO8] Bits */
#define GPIO_CPU_INT_IMASK_DIO8_OFS              (8)                             /* !< DIO8 Offset */
#define GPIO_CPU_INT_IMASK_DIO8_MASK             ((uint32_t)0x00000100U)         /* !< DIO8 event mask */
#define GPIO_CPU_INT_IMASK_DIO8_CLR              ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO8_SET              ((uint32_t)0x00000100U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO9] Bits */
#define GPIO_CPU_INT_IMASK_DIO9_OFS              (9)                             /* !< DIO9 Offset */
#define GPIO_CPU_INT_IMASK_DIO9_MASK             ((uint32_t)0x00000200U)         /* !< DIO9 event mask */
#define GPIO_CPU_INT_IMASK_DIO9_CLR              ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO9_SET              ((uint32_t)0x00000200U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO10] Bits */
#define GPIO_CPU_INT_IMASK_DIO10_OFS             (10)                            /* !< DIO10 Offset */
#define GPIO_CPU_INT_IMASK_DIO10_MASK            ((uint32_t)0x00000400U)         /* !< DIO10 event mask */
#define GPIO_CPU_INT_IMASK_DIO10_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO10_SET             ((uint32_t)0x00000400U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO11] Bits */
#define GPIO_CPU_INT_IMASK_DIO11_OFS             (11)                            /* !< DIO11 Offset */
#define GPIO_CPU_INT_IMASK_DIO11_MASK            ((uint32_t)0x00000800U)         /* !< DIO11 event mask */
#define GPIO_CPU_INT_IMASK_DIO11_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO11_SET             ((uint32_t)0x00000800U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO12] Bits */
#define GPIO_CPU_INT_IMASK_DIO12_OFS             (12)                            /* !< DIO12 Offset */
#define GPIO_CPU_INT_IMASK_DIO12_MASK            ((uint32_t)0x00001000U)         /* !< DIO12 event mask */
#define GPIO_CPU_INT_IMASK_DIO12_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO12_SET             ((uint32_t)0x00001000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO13] Bits */
#define GPIO_CPU_INT_IMASK_DIO13_OFS             (13)                            /* !< DIO13 Offset */
#define GPIO_CPU_INT_IMASK_DIO13_MASK            ((uint32_t)0x00002000U)         /* !< DIO13 event mask */
#define GPIO_CPU_INT_IMASK_DIO13_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO13_SET             ((uint32_t)0x00002000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO14] Bits */
#define GPIO_CPU_INT_IMASK_DIO14_OFS             (14)                            /* !< DIO14 Offset */
#define GPIO_CPU_INT_IMASK_DIO14_MASK            ((uint32_t)0x00004000U)         /* !< DIO14 event mask */
#define GPIO_CPU_INT_IMASK_DIO14_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO14_SET             ((uint32_t)0x00004000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO15] Bits */
#define GPIO_CPU_INT_IMASK_DIO15_OFS             (15)                            /* !< DIO15 Offset */
#define GPIO_CPU_INT_IMASK_DIO15_MASK            ((uint32_t)0x00008000U)         /* !< DIO15 event mask */
#define GPIO_CPU_INT_IMASK_DIO15_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO15_SET             ((uint32_t)0x00008000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO16] Bits */
#define GPIO_CPU_INT_IMASK_DIO16_OFS             (16)                            /* !< DIO16 Offset */
#define GPIO_CPU_INT_IMASK_DIO16_MASK            ((uint32_t)0x00010000U)         /* !< DIO16 event mask */
#define GPIO_CPU_INT_IMASK_DIO16_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO16_SET             ((uint32_t)0x00010000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO17] Bits */
#define GPIO_CPU_INT_IMASK_DIO17_OFS             (17)                            /* !< DIO17 Offset */
#define GPIO_CPU_INT_IMASK_DIO17_MASK            ((uint32_t)0x00020000U)         /* !< DIO17 event mask */
#define GPIO_CPU_INT_IMASK_DIO17_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO17_SET             ((uint32_t)0x00020000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO18] Bits */
#define GPIO_CPU_INT_IMASK_DIO18_OFS             (18)                            /* !< DIO18 Offset */
#define GPIO_CPU_INT_IMASK_DIO18_MASK            ((uint32_t)0x00040000U)         /* !< DIO18 event mask */
#define GPIO_CPU_INT_IMASK_DIO18_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO18_SET             ((uint32_t)0x00040000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO19] Bits */
#define GPIO_CPU_INT_IMASK_DIO19_OFS             (19)                            /* !< DIO19 Offset */
#define GPIO_CPU_INT_IMASK_DIO19_MASK            ((uint32_t)0x00080000U)         /* !< DIO19 event mask */
#define GPIO_CPU_INT_IMASK_DIO19_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO19_SET             ((uint32_t)0x00080000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO20] Bits */
#define GPIO_CPU_INT_IMASK_DIO20_OFS             (20)                            /* !< DIO20 Offset */
#define GPIO_CPU_INT_IMASK_DIO20_MASK            ((uint32_t)0x00100000U)         /* !< DIO20 event mask */
#define GPIO_CPU_INT_IMASK_DIO20_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO20_SET             ((uint32_t)0x00100000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO21] Bits */
#define GPIO_CPU_INT_IMASK_DIO21_OFS             (21)                            /* !< DIO21 Offset */
#define GPIO_CPU_INT_IMASK_DIO21_MASK            ((uint32_t)0x00200000U)         /* !< DIO21 event mask */
#define GPIO_CPU_INT_IMASK_DIO21_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO21_SET             ((uint32_t)0x00200000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO22] Bits */
#define GPIO_CPU_INT_IMASK_DIO22_OFS             (22)                            /* !< DIO22 Offset */
#define GPIO_CPU_INT_IMASK_DIO22_MASK            ((uint32_t)0x00400000U)         /* !< DIO22 event mask */
#define GPIO_CPU_INT_IMASK_DIO22_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO22_SET             ((uint32_t)0x00400000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO23] Bits */
#define GPIO_CPU_INT_IMASK_DIO23_OFS             (23)                            /* !< DIO23 Offset */
#define GPIO_CPU_INT_IMASK_DIO23_MASK            ((uint32_t)0x00800000U)         /* !< DIO23 event mask */
#define GPIO_CPU_INT_IMASK_DIO23_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO23_SET             ((uint32_t)0x00800000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO24] Bits */
#define GPIO_CPU_INT_IMASK_DIO24_OFS             (24)                            /* !< DIO24 Offset */
#define GPIO_CPU_INT_IMASK_DIO24_MASK            ((uint32_t)0x01000000U)         /* !< DIO24 event mask */
#define GPIO_CPU_INT_IMASK_DIO24_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO24_SET             ((uint32_t)0x01000000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO25] Bits */
#define GPIO_CPU_INT_IMASK_DIO25_OFS             (25)                            /* !< DIO25 Offset */
#define GPIO_CPU_INT_IMASK_DIO25_MASK            ((uint32_t)0x02000000U)         /* !< DIO25 event mask */
#define GPIO_CPU_INT_IMASK_DIO25_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO25_SET             ((uint32_t)0x02000000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO26] Bits */
#define GPIO_CPU_INT_IMASK_DIO26_OFS             (26)                            /* !< DIO26 Offset */
#define GPIO_CPU_INT_IMASK_DIO26_MASK            ((uint32_t)0x04000000U)         /* !< DIO26 event mask */
#define GPIO_CPU_INT_IMASK_DIO26_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO26_SET             ((uint32_t)0x04000000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO27] Bits */
#define GPIO_CPU_INT_IMASK_DIO27_OFS             (27)                            /* !< DIO27 Offset */
#define GPIO_CPU_INT_IMASK_DIO27_MASK            ((uint32_t)0x08000000U)         /* !< DIO27 event mask */
#define GPIO_CPU_INT_IMASK_DIO27_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO27_SET             ((uint32_t)0x08000000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO28] Bits */
#define GPIO_CPU_INT_IMASK_DIO28_OFS             (28)                            /* !< DIO28 Offset */
#define GPIO_CPU_INT_IMASK_DIO28_MASK            ((uint32_t)0x10000000U)         /* !< DIO28 event mask */
#define GPIO_CPU_INT_IMASK_DIO28_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO28_SET             ((uint32_t)0x10000000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO29] Bits */
#define GPIO_CPU_INT_IMASK_DIO29_OFS             (29)                            /* !< DIO29 Offset */
#define GPIO_CPU_INT_IMASK_DIO29_MASK            ((uint32_t)0x20000000U)         /* !< DIO29 event mask */
#define GPIO_CPU_INT_IMASK_DIO29_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO29_SET             ((uint32_t)0x20000000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO30] Bits */
#define GPIO_CPU_INT_IMASK_DIO30_OFS             (30)                            /* !< DIO30 Offset */
#define GPIO_CPU_INT_IMASK_DIO30_MASK            ((uint32_t)0x40000000U)         /* !< DIO30 event mask */
#define GPIO_CPU_INT_IMASK_DIO30_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO30_SET             ((uint32_t)0x40000000U)         /* !< Event is unmasked */
/* GPIO_CPU_INT_IMASK[DIO31] Bits */
#define GPIO_CPU_INT_IMASK_DIO31_OFS             (31)                            /* !< DIO31 Offset */
#define GPIO_CPU_INT_IMASK_DIO31_MASK            ((uint32_t)0x80000000U)         /* !< DIO31 event mask */
#define GPIO_CPU_INT_IMASK_DIO31_CLR             ((uint32_t)0x00000000U)         /* !< Event is masked */
#define GPIO_CPU_INT_IMASK_DIO31_SET             ((uint32_t)0x80000000U)         /* !< Event is unmasked */

/* GPIO_CPU_INT_RIS Bits */
/* GPIO_CPU_INT_RIS[DIO0] Bits */
#define GPIO_CPU_INT_RIS_DIO0_OFS                (0)                             /* !< DIO0 Offset */
#define GPIO_CPU_INT_RIS_DIO0_MASK               ((uint32_t)0x00000001U)         /* !< DIO0 event */
#define GPIO_CPU_INT_RIS_DIO0_CLR                ((uint32_t)0x00000000U)         /* !< DIO0 event did not occur */
#define GPIO_CPU_INT_RIS_DIO0_SET                ((uint32_t)0x00000001U)         /* !< DIO0 event occurred */
/* GPIO_CPU_INT_RIS[DIO1] Bits */
#define GPIO_CPU_INT_RIS_DIO1_OFS                (1)                             /* !< DIO1 Offset */
#define GPIO_CPU_INT_RIS_DIO1_MASK               ((uint32_t)0x00000002U)         /* !< DIO1 event */
#define GPIO_CPU_INT_RIS_DIO1_CLR                ((uint32_t)0x00000000U)         /* !< DIO1 event did not occur */
#define GPIO_CPU_INT_RIS_DIO1_SET                ((uint32_t)0x00000002U)         /* !< DIO1 event occurred */
/* GPIO_CPU_INT_RIS[DIO2] Bits */
#define GPIO_CPU_INT_RIS_DIO2_OFS                (2)                             /* !< DIO2 Offset */
#define GPIO_CPU_INT_RIS_DIO2_MASK               ((uint32_t)0x00000004U)         /* !< DIO2 event */
#define GPIO_CPU_INT_RIS_DIO2_CLR                ((uint32_t)0x00000000U)         /* !< DIO2 event did not occur */
#define GPIO_CPU_INT_RIS_DIO2_SET                ((uint32_t)0x00000004U)         /* !< DIO2 event occurred */
/* GPIO_CPU_INT_RIS[DIO3] Bits */
#define GPIO_CPU_INT_RIS_DIO3_OFS                (3)                             /* !< DIO3 Offset */
#define GPIO_CPU_INT_RIS_DIO3_MASK               ((uint32_t)0x00000008U)         /* !< DIO3 event */
#define GPIO_CPU_INT_RIS_DIO3_CLR                ((uint32_t)0x00000000U)         /* !< DIO3 event did not occur */
#define GPIO_CPU_INT_RIS_DIO3_SET                ((uint32_t)0x00000008U)         /* !< DIO3 event occurred */
/* GPIO_CPU_INT_RIS[DIO4] Bits */
#define GPIO_CPU_INT_RIS_DIO4_OFS                (4)                             /* !< DIO4 Offset */
#define GPIO_CPU_INT_RIS_DIO4_MASK               ((uint32_t)0x00000010U)         /* !< DIO4 event */
#define GPIO_CPU_INT_RIS_DIO4_CLR                ((uint32_t)0x00000000U)         /* !< DIO4 event did not occur */
#define GPIO_CPU_INT_RIS_DIO4_SET                ((uint32_t)0x00000010U)         /* !< DIO4 event occurred */
/* GPIO_CPU_INT_RIS[DIO5] Bits */
#define GPIO_CPU_INT_RIS_DIO5_OFS                (5)                             /* !< DIO5 Offset */
#define GPIO_CPU_INT_RIS_DIO5_MASK               ((uint32_t)0x00000020U)         /* !< DIO5 event */
#define GPIO_CPU_INT_RIS_DIO5_CLR                ((uint32_t)0x00000000U)         /* !< DIO5 event did not occur */
#define GPIO_CPU_INT_RIS_DIO5_SET                ((uint32_t)0x00000020U)         /* !< DIO5 event occurred */
/* GPIO_CPU_INT_RIS[DIO6] Bits */
#define GPIO_CPU_INT_RIS_DIO6_OFS                (6)                             /* !< DIO6 Offset */
#define GPIO_CPU_INT_RIS_DIO6_MASK               ((uint32_t)0x00000040U)         /* !< DIO6 event */
#define GPIO_CPU_INT_RIS_DIO6_CLR                ((uint32_t)0x00000000U)         /* !< DIO6 event did not occur */
#define GPIO_CPU_INT_RIS_DIO6_SET                ((uint32_t)0x00000040U)         /* !< DIO6 event occurred */
/* GPIO_CPU_INT_RIS[DIO7] Bits */
#define GPIO_CPU_INT_RIS_DIO7_OFS                (7)                             /* !< DIO7 Offset */
#define GPIO_CPU_INT_RIS_DIO7_MASK               ((uint32_t)0x00000080U)         /* !< DIO7 event */
#define GPIO_CPU_INT_RIS_DIO7_CLR                ((uint32_t)0x00000000U)         /* !< DIO7 event did not occur */
#define GPIO_CPU_INT_RIS_DIO7_SET                ((uint32_t)0x00000080U)         /* !< DIO7 event occurred */
/* GPIO_CPU_INT_RIS[DIO8] Bits */
#define GPIO_CPU_INT_RIS_DIO8_OFS                (8)                             /* !< DIO8 Offset */
#define GPIO_CPU_INT_RIS_DIO8_MASK               ((uint32_t)0x00000100U)         /* !< DIO8 event */
#define GPIO_CPU_INT_RIS_DIO8_CLR                ((uint32_t)0x00000000U)         /* !< DIO8 event did not occur */
#define GPIO_CPU_INT_RIS_DIO8_SET                ((uint32_t)0x00000100U)         /* !< DIO8 event occurred */
/* GPIO_CPU_INT_RIS[DIO9] Bits */
#define GPIO_CPU_INT_RIS_DIO9_OFS                (9)                             /* !< DIO9 Offset */
#define GPIO_CPU_INT_RIS_DIO9_MASK               ((uint32_t)0x00000200U)         /* !< DIO9 event */
#define GPIO_CPU_INT_RIS_DIO9_CLR                ((uint32_t)0x00000000U)         /* !< DIO9 event did not occur */
#define GPIO_CPU_INT_RIS_DIO9_SET                ((uint32_t)0x00000200U)         /* !< DIO9 event occurred */
/* GPIO_CPU_INT_RIS[DIO10] Bits */
#define GPIO_CPU_INT_RIS_DIO10_OFS               (10)                            /* !< DIO10 Offset */
#define GPIO_CPU_INT_RIS_DIO10_MASK              ((uint32_t)0x00000400U)         /* !< DIO10 event */
#define GPIO_CPU_INT_RIS_DIO10_CLR               ((uint32_t)0x00000000U)         /* !< DIO10 event did not occur */
#define GPIO_CPU_INT_RIS_DIO10_SET               ((uint32_t)0x00000400U)         /* !< DIO10 event occurred */
/* GPIO_CPU_INT_RIS[DIO11] Bits */
#define GPIO_CPU_INT_RIS_DIO11_OFS               (11)                            /* !< DIO11 Offset */
#define GPIO_CPU_INT_RIS_DIO11_MASK              ((uint32_t)0x00000800U)         /* !< DIO11 event */
#define GPIO_CPU_INT_RIS_DIO11_CLR               ((uint32_t)0x00000000U)         /* !< DIO11 event did not occur */
#define GPIO_CPU_INT_RIS_DIO11_SET               ((uint32_t)0x00000800U)         /* !< DIO11 event occurred */
/* GPIO_CPU_INT_RIS[DIO12] Bits */
#define GPIO_CPU_INT_RIS_DIO12_OFS               (12)                            /* !< DIO12 Offset */
#define GPIO_CPU_INT_RIS_DIO12_MASK              ((uint32_t)0x00001000U)         /* !< DIO12 event */
#define GPIO_CPU_INT_RIS_DIO12_CLR               ((uint32_t)0x00000000U)         /* !< DIO12 event did not occur */
#define GPIO_CPU_INT_RIS_DIO12_SET               ((uint32_t)0x00001000U)         /* !< DIO12 event occurred */
/* GPIO_CPU_INT_RIS[DIO13] Bits */
#define GPIO_CPU_INT_RIS_DIO13_OFS               (13)                            /* !< DIO13 Offset */
#define GPIO_CPU_INT_RIS_DIO13_MASK              ((uint32_t)0x00002000U)         /* !< DIO13 event */
#define GPIO_CPU_INT_RIS_DIO13_CLR               ((uint32_t)0x00000000U)         /* !< DIO13 event did not occur */
#define GPIO_CPU_INT_RIS_DIO13_SET               ((uint32_t)0x00002000U)         /* !< DIO13 event occurred */
/* GPIO_CPU_INT_RIS[DIO14] Bits */
#define GPIO_CPU_INT_RIS_DIO14_OFS               (14)                            /* !< DIO14 Offset */
#define GPIO_CPU_INT_RIS_DIO14_MASK              ((uint32_t)0x00004000U)         /* !< DIO14 event */
#define GPIO_CPU_INT_RIS_DIO14_CLR               ((uint32_t)0x00000000U)         /* !< DIO14 event did not occur */
#define GPIO_CPU_INT_RIS_DIO14_SET               ((uint32_t)0x00004000U)         /* !< DIO14 event occurred */
/* GPIO_CPU_INT_RIS[DIO15] Bits */
#define GPIO_CPU_INT_RIS_DIO15_OFS               (15)                            /* !< DIO15 Offset */
#define GPIO_CPU_INT_RIS_DIO15_MASK              ((uint32_t)0x00008000U)         /* !< DIO15 event */
#define GPIO_CPU_INT_RIS_DIO15_CLR               ((uint32_t)0x00000000U)         /* !< DIO15 event did not occur */
#define GPIO_CPU_INT_RIS_DIO15_SET               ((uint32_t)0x00008000U)         /* !< DIO15 event occurred */
/* GPIO_CPU_INT_RIS[DIO16] Bits */
#define GPIO_CPU_INT_RIS_DIO16_OFS               (16)                            /* !< DIO16 Offset */
#define GPIO_CPU_INT_RIS_DIO16_MASK              ((uint32_t)0x00010000U)         /* !< DIO16 event */
#define GPIO_CPU_INT_RIS_DIO16_CLR               ((uint32_t)0x00000000U)         /* !< DIO16 event did not occur */
#define GPIO_CPU_INT_RIS_DIO16_SET               ((uint32_t)0x00010000U)         /* !< DIO16 event occurred */
/* GPIO_CPU_INT_RIS[DIO17] Bits */
#define GPIO_CPU_INT_RIS_DIO17_OFS               (17)                            /* !< DIO17 Offset */
#define GPIO_CPU_INT_RIS_DIO17_MASK              ((uint32_t)0x00020000U)         /* !< DIO17 event */
#define GPIO_CPU_INT_RIS_DIO17_CLR               ((uint32_t)0x00000000U)         /* !< DIO17 event did not occur */
#define GPIO_CPU_INT_RIS_DIO17_SET               ((uint32_t)0x00020000U)         /* !< DIO17 event occurred */
/* GPIO_CPU_INT_RIS[DIO18] Bits */
#define GPIO_CPU_INT_RIS_DIO18_OFS               (18)                            /* !< DIO18 Offset */
#define GPIO_CPU_INT_RIS_DIO18_MASK              ((uint32_t)0x00040000U)         /* !< DIO18 event */
#define GPIO_CPU_INT_RIS_DIO18_CLR               ((uint32_t)0x00000000U)         /* !< DIO18 event did not occur */
#define GPIO_CPU_INT_RIS_DIO18_SET               ((uint32_t)0x00040000U)         /* !< DIO18 event occurred */
/* GPIO_CPU_INT_RIS[DIO19] Bits */
#define GPIO_CPU_INT_RIS_DIO19_OFS               (19)                            /* !< DIO19 Offset */
#define GPIO_CPU_INT_RIS_DIO19_MASK              ((uint32_t)0x00080000U)         /* !< DIO19 event */
#define GPIO_CPU_INT_RIS_DIO19_CLR               ((uint32_t)0x00000000U)         /* !< DIO19 event did not occur */
#define GPIO_CPU_INT_RIS_DIO19_SET               ((uint32_t)0x00080000U)         /* !< DIO19 event occurred */
/* GPIO_CPU_INT_RIS[DIO20] Bits */
#define GPIO_CPU_INT_RIS_DIO20_OFS               (20)                            /* !< DIO20 Offset */
#define GPIO_CPU_INT_RIS_DIO20_MASK              ((uint32_t)0x00100000U)         /* !< DIO20 event */
#define GPIO_CPU_INT_RIS_DIO20_CLR               ((uint32_t)0x00000000U)         /* !< DIO20 event did not occur */
#define GPIO_CPU_INT_RIS_DIO20_SET               ((uint32_t)0x00100000U)         /* !< DIO20 event occurred */
/* GPIO_CPU_INT_RIS[DIO21] Bits */
#define GPIO_CPU_INT_RIS_DIO21_OFS               (21)                            /* !< DIO21 Offset */
#define GPIO_CPU_INT_RIS_DIO21_MASK              ((uint32_t)0x00200000U)         /* !< DIO21 event */
#define GPIO_CPU_INT_RIS_DIO21_CLR               ((uint32_t)0x00000000U)         /* !< DIO21 event did not occur */
#define GPIO_CPU_INT_RIS_DIO21_SET               ((uint32_t)0x00200000U)         /* !< DIO21 event occurred */
/* GPIO_CPU_INT_RIS[DIO22] Bits */
#define GPIO_CPU_INT_RIS_DIO22_OFS               (22)                            /* !< DIO22 Offset */
#define GPIO_CPU_INT_RIS_DIO22_MASK              ((uint32_t)0x00400000U)         /* !< DIO22 event */
#define GPIO_CPU_INT_RIS_DIO22_CLR               ((uint32_t)0x00000000U)         /* !< DIO22 event did not occur */
#define GPIO_CPU_INT_RIS_DIO22_SET               ((uint32_t)0x00400000U)         /* !< DIO22 event occurred */
/* GPIO_CPU_INT_RIS[DIO23] Bits */
#define GPIO_CPU_INT_RIS_DIO23_OFS               (23)                            /* !< DIO23 Offset */
#define GPIO_CPU_INT_RIS_DIO23_MASK              ((uint32_t)0x00800000U)         /* !< DIO23 event */
#define GPIO_CPU_INT_RIS_DIO23_CLR               ((uint32_t)0x00000000U)         /* !< DIO23 event did not occur */
#define GPIO_CPU_INT_RIS_DIO23_SET               ((uint32_t)0x00800000U)         /* !< DIO23 event occurred */
/* GPIO_CPU_INT_RIS[DIO24] Bits */
#define GPIO_CPU_INT_RIS_DIO24_OFS               (24)                            /* !< DIO24 Offset */
#define GPIO_CPU_INT_RIS_DIO24_MASK              ((uint32_t)0x01000000U)         /* !< DIO24 event */
#define GPIO_CPU_INT_RIS_DIO24_CLR               ((uint32_t)0x00000000U)         /* !< DIO24 event did not occur */
#define GPIO_CPU_INT_RIS_DIO24_SET               ((uint32_t)0x01000000U)         /* !< DIO24 event occurred */
/* GPIO_CPU_INT_RIS[DIO25] Bits */
#define GPIO_CPU_INT_RIS_DIO25_OFS               (25)                            /* !< DIO25 Offset */
#define GPIO_CPU_INT_RIS_DIO25_MASK              ((uint32_t)0x02000000U)         /* !< DIO25 event */
#define GPIO_CPU_INT_RIS_DIO25_CLR               ((uint32_t)0x00000000U)         /* !< DIO25 event did not occur */
#define GPIO_CPU_INT_RIS_DIO25_SET               ((uint32_t)0x02000000U)         /* !< DIO25 event occurred */
/* GPIO_CPU_INT_RIS[DIO26] Bits */
#define GPIO_CPU_INT_RIS_DIO26_OFS               (26)                            /* !< DIO26 Offset */
#define GPIO_CPU_INT_RIS_DIO26_MASK              ((uint32_t)0x04000000U)         /* !< DIO26 event */
#define GPIO_CPU_INT_RIS_DIO26_CLR               ((uint32_t)0x00000000U)         /* !< DIO26 event did not occur */
#define GPIO_CPU_INT_RIS_DIO26_SET               ((uint32_t)0x04000000U)         /* !< DIO26 event occurred */
/* GPIO_CPU_INT_RIS[DIO27] Bits */
#define GPIO_CPU_INT_RIS_DIO27_OFS               (27)                            /* !< DIO27 Offset */
#define GPIO_CPU_INT_RIS_DIO27_MASK              ((uint32_t)0x08000000U)         /* !< DIO27 event */
#define GPIO_CPU_INT_RIS_DIO27_CLR               ((uint32_t)0x00000000U)         /* !< DIO27 event did not occur */
#define GPIO_CPU_INT_RIS_DIO27_SET               ((uint32_t)0x08000000U)         /* !< DIO27 event occurred */
/* GPIO_CPU_INT_RIS[DIO28] Bits */
#define GPIO_CPU_INT_RIS_DIO28_OFS               (28)                            /* !< DIO28 Offset */
#define GPIO_CPU_INT_RIS_DIO28_MASK              ((uint32_t)0x10000000U)         /* !< DIO28 event */
#define GPIO_CPU_INT_RIS_DIO28_CLR               ((uint32_t)0x00000000U)         /* !< DIO28 event did not occur */
#define GPIO_CPU_INT_RIS_DIO28_SET               ((uint32_t)0x10000000U)         /* !< DIO28 event occurred */
/* GPIO_CPU_INT_RIS[DIO29] Bits */
#define GPIO_CPU_INT_RIS_DIO29_OFS               (29)                            /* !< DIO29 Offset */
#define GPIO_CPU_INT_RIS_DIO29_MASK              ((uint32_t)0x20000000U)         /* !< DIO29 event */
#define GPIO_CPU_INT_RIS_DIO29_CLR               ((uint32_t)0x00000000U)         /* !< DIO29 event did not occur */
#define GPIO_CPU_INT_RIS_DIO29_SET               ((uint32_t)0x20000000U)         /* !< DIO29 event occurred */
/* GPIO_CPU_INT_RIS[DIO30] Bits */
#define GPIO_CPU_INT_RIS_DIO30_OFS               (30)                            /* !< DIO30 Offset */
#define GPIO_CPU_INT_RIS_DIO30_MASK              ((uint32_t)0x40000000U)         /* !< DIO30 event */
#define GPIO_CPU_INT_RIS_DIO30_CLR               ((uint32_t)0x00000000U)         /* !< DIO30 event did not occur */
#define GPIO_CPU_INT_RIS_DIO30_SET               ((uint32_t)0x40000000U)         /* !< DIO30 event occurred */
/* GPIO_CPU_INT_RIS[DIO31] Bits */
#define GPIO_CPU_INT_RIS_DIO31_OFS               (31)                            /* !< DIO31 Offset */
#define GPIO_CPU_INT_RIS_DIO31_MASK              ((uint32_t)0x80000000U)         /* !< DIO31 event */
#define GPIO_CPU_INT_RIS_DIO31_CLR               ((uint32_t)0x00000000U)         /* !< DIO31 event did not occur */
#define GPIO_CPU_INT_RIS_DIO31_SET               ((uint32_t)0x80000000U)         /* !< DIO31 event occurred */

/* GPIO_CPU_INT_MIS Bits */
/* GPIO_CPU_INT_MIS[DIO0] Bits */
#define GPIO_CPU_INT_MIS_DIO0_OFS                (0)                             /* !< DIO0 Offset */
#define GPIO_CPU_INT_MIS_DIO0_MASK               ((uint32_t)0x00000001U)         /* !< DIO0 event */
#define GPIO_CPU_INT_MIS_DIO0_CLR                ((uint32_t)0x00000000U)         /* !< DIO0 event did not occur */
#define GPIO_CPU_INT_MIS_DIO0_SET                ((uint32_t)0x00000001U)         /* !< DIO0 event occurred */
/* GPIO_CPU_INT_MIS[DIO1] Bits */
#define GPIO_CPU_INT_MIS_DIO1_OFS                (1)                             /* !< DIO1 Offset */
#define GPIO_CPU_INT_MIS_DIO1_MASK               ((uint32_t)0x00000002U)         /* !< DIO1 event */
#define GPIO_CPU_INT_MIS_DIO1_CLR                ((uint32_t)0x00000000U)         /* !< DIO1 event did not occur */
#define GPIO_CPU_INT_MIS_DIO1_SET                ((uint32_t)0x00000002U)         /* !< DIO1 event occurred */
/* GPIO_CPU_INT_MIS[DIO2] Bits */
#define GPIO_CPU_INT_MIS_DIO2_OFS                (2)                             /* !< DIO2 Offset */
#define GPIO_CPU_INT_MIS_DIO2_MASK               ((uint32_t)0x00000004U)         /* !< DIO2 event */
#define GPIO_CPU_INT_MIS_DIO2_CLR                ((uint32_t)0x00000000U)         /* !< DIO2 event did not occur */
#define GPIO_CPU_INT_MIS_DIO2_SET                ((uint32_t)0x00000004U)         /* !< DIO2 event occurred */
/* GPIO_CPU_INT_MIS[DIO3] Bits */
#define GPIO_CPU_INT_MIS_DIO3_OFS                (3)                             /* !< DIO3 Offset */
#define GPIO_CPU_INT_MIS_DIO3_MASK               ((uint32_t)0x00000008U)         /* !< DIO3 event */
#define GPIO_CPU_INT_MIS_DIO3_CLR                ((uint32_t)0x00000000U)         /* !< DIO3 event did not occur */
#define GPIO_CPU_INT_MIS_DIO3_SET                ((uint32_t)0x00000008U)         /* !< DIO3 event occurred */
/* GPIO_CPU_INT_MIS[DIO4] Bits */
#define GPIO_CPU_INT_MIS_DIO4_OFS                (4)                             /* !< DIO4 Offset */
#define GPIO_CPU_INT_MIS_DIO4_MASK               ((uint32_t)0x00000010U)         /* !< DIO4 event */
#define GPIO_CPU_INT_MIS_DIO4_CLR                ((uint32_t)0x00000000U)         /* !< DIO4 event did not occur */
#define GPIO_CPU_INT_MIS_DIO4_SET                ((uint32_t)0x00000010U)         /* !< DIO4 event occurred */
/* GPIO_CPU_INT_MIS[DIO5] Bits */
#define GPIO_CPU_INT_MIS_DIO5_OFS                (5)                             /* !< DIO5 Offset */
#define GPIO_CPU_INT_MIS_DIO5_MASK               ((uint32_t)0x00000020U)         /* !< DIO5 event */
#define GPIO_CPU_INT_MIS_DIO5_CLR                ((uint32_t)0x00000000U)         /* !< DIO5 event did not occur */
#define GPIO_CPU_INT_MIS_DIO5_SET                ((uint32_t)0x00000020U)         /* !< DIO5 event occurred */
/* GPIO_CPU_INT_MIS[DIO6] Bits */
#define GPIO_CPU_INT_MIS_DIO6_OFS                (6)                             /* !< DIO6 Offset */
#define GPIO_CPU_INT_MIS_DIO6_MASK               ((uint32_t)0x00000040U)         /* !< DIO6 event */
#define GPIO_CPU_INT_MIS_DIO6_CLR                ((uint32_t)0x00000000U)         /* !< DIO6 event did not occur */
#define GPIO_CPU_INT_MIS_DIO6_SET                ((uint32_t)0x00000040U)         /* !< DIO6 event occurred */
/* GPIO_CPU_INT_MIS[DIO7] Bits */
#define GPIO_CPU_INT_MIS_DIO7_OFS                (7)                             /* !< DIO7 Offset */
#define GPIO_CPU_INT_MIS_DIO7_MASK               ((uint32_t)0x00000080U)         /* !< DIO7 event */
#define GPIO_CPU_INT_MIS_DIO7_CLR                ((uint32_t)0x00000000U)         /* !< DIO7 event did not occur */
#define GPIO_CPU_INT_MIS_DIO7_SET                ((uint32_t)0x00000080U)         /* !< DIO7 event occurred */
/* GPIO_CPU_INT_MIS[DIO8] Bits */
#define GPIO_CPU_INT_MIS_DIO8_OFS                (8)                             /* !< DIO8 Offset */
#define GPIO_CPU_INT_MIS_DIO8_MASK               ((uint32_t)0x00000100U)         /* !< DIO8 event */
#define GPIO_CPU_INT_MIS_DIO8_CLR                ((uint32_t)0x00000000U)         /* !< DIO8 event did not occur */
#define GPIO_CPU_INT_MIS_DIO8_SET                ((uint32_t)0x00000100U)         /* !< DIO8 event occurred */
/* GPIO_CPU_INT_MIS[DIO9] Bits */
#define GPIO_CPU_INT_MIS_DIO9_OFS                (9)                             /* !< DIO9 Offset */
#define GPIO_CPU_INT_MIS_DIO9_MASK               ((uint32_t)0x00000200U)         /* !< DIO9 event */
#define GPIO_CPU_INT_MIS_DIO9_CLR                ((uint32_t)0x00000000U)         /* !< DIO9 event did not occur */
#define GPIO_CPU_INT_MIS_DIO9_SET                ((uint32_t)0x00000200U)         /* !< DIO9 event occurred */
/* GPIO_CPU_INT_MIS[DIO10] Bits */
#define GPIO_CPU_INT_MIS_DIO10_OFS               (10)                            /* !< DIO10 Offset */
#define GPIO_CPU_INT_MIS_DIO10_MASK              ((uint32_t)0x00000400U)         /* !< DIO10 event */
#define GPIO_CPU_INT_MIS_DIO10_CLR               ((uint32_t)0x00000000U)         /* !< DIO10 event did not occur */
#define GPIO_CPU_INT_MIS_DIO10_SET               ((uint32_t)0x00000400U)         /* !< DIO10 event occurred */
/* GPIO_CPU_INT_MIS[DIO11] Bits */
#define GPIO_CPU_INT_MIS_DIO11_OFS               (11)                            /* !< DIO11 Offset */
#define GPIO_CPU_INT_MIS_DIO11_MASK              ((uint32_t)0x00000800U)         /* !< DIO11 event */
#define GPIO_CPU_INT_MIS_DIO11_CLR               ((uint32_t)0x00000000U)         /* !< DIO11 event did not occur */
#define GPIO_CPU_INT_MIS_DIO11_SET               ((uint32_t)0x00000800U)         /* !< DIO11 event occurred */
/* GPIO_CPU_INT_MIS[DIO12] Bits */
#define GPIO_CPU_INT_MIS_DIO12_OFS               (12)                            /* !< DIO12 Offset */
#define GPIO_CPU_INT_MIS_DIO12_MASK              ((uint32_t)0x00001000U)         /* !< DIO12 event */
#define GPIO_CPU_INT_MIS_DIO12_CLR               ((uint32_t)0x00000000U)         /* !< DIO12 event did not occur */
#define GPIO_CPU_INT_MIS_DIO12_SET               ((uint32_t)0x00001000U)         /* !< DIO12 event occurred */
/* GPIO_CPU_INT_MIS[DIO13] Bits */
#define GPIO_CPU_INT_MIS_DIO13_OFS               (13)                            /* !< DIO13 Offset */
#define GPIO_CPU_INT_MIS_DIO13_MASK              ((uint32_t)0x00002000U)         /* !< DIO13 event */
#define GPIO_CPU_INT_MIS_DIO13_CLR               ((uint32_t)0x00000000U)         /* !< DIO13 event did not occur */
#define GPIO_CPU_INT_MIS_DIO13_SET               ((uint32_t)0x00002000U)         /* !< DIO13 event occurred */
/* GPIO_CPU_INT_MIS[DIO14] Bits */
#define GPIO_CPU_INT_MIS_DIO14_OFS               (14)                            /* !< DIO14 Offset */
#define GPIO_CPU_INT_MIS_DIO14_MASK              ((uint32_t)0x00004000U)         /* !< DIO14 event */
#define GPIO_CPU_INT_MIS_DIO14_CLR               ((uint32_t)0x00000000U)         /* !< DIO14 event did not occur */
#define GPIO_CPU_INT_MIS_DIO14_SET               ((uint32_t)0x00004000U)         /* !< DIO14 event occurred */
/* GPIO_CPU_INT_MIS[DIO15] Bits */
#define GPIO_CPU_INT_MIS_DIO15_OFS               (15)                            /* !< DIO15 Offset */
#define GPIO_CPU_INT_MIS_DIO15_MASK              ((uint32_t)0x00008000U)         /* !< DIO15 event */
#define GPIO_CPU_INT_MIS_DIO15_CLR               ((uint32_t)0x00000000U)         /* !< DIO15 event did not occur */
#define GPIO_CPU_INT_MIS_DIO15_SET               ((uint32_t)0x00008000U)         /* !< DIO15 event occurred */
/* GPIO_CPU_INT_MIS[DIO16] Bits */
#define GPIO_CPU_INT_MIS_DIO16_OFS               (16)                            /* !< DIO16 Offset */
#define GPIO_CPU_INT_MIS_DIO16_MASK              ((uint32_t)0x00010000U)         /* !< DIO16 event */
#define GPIO_CPU_INT_MIS_DIO16_CLR               ((uint32_t)0x00000000U)         /* !< DIO16 event did not occur */
#define GPIO_CPU_INT_MIS_DIO16_SET               ((uint32_t)0x00010000U)         /* !< DIO16 event occurred */
/* GPIO_CPU_INT_MIS[DIO17] Bits */
#define GPIO_CPU_INT_MIS_DIO17_OFS               (17)                            /* !< DIO17 Offset */
#define GPIO_CPU_INT_MIS_DIO17_MASK              ((uint32_t)0x00020000U)         /* !< DIO17 event */
#define GPIO_CPU_INT_MIS_DIO17_CLR               ((uint32_t)0x00000000U)         /* !< DIO17 event did not occur */
#define GPIO_CPU_INT_MIS_DIO17_SET               ((uint32_t)0x00020000U)         /* !< DIO17 event occurred */
/* GPIO_CPU_INT_MIS[DIO18] Bits */
#define GPIO_CPU_INT_MIS_DIO18_OFS               (18)                            /* !< DIO18 Offset */
#define GPIO_CPU_INT_MIS_DIO18_MASK              ((uint32_t)0x00040000U)         /* !< DIO18 event */
#define GPIO_CPU_INT_MIS_DIO18_CLR               ((uint32_t)0x00000000U)         /* !< DIO18 event did not occur */
#define GPIO_CPU_INT_MIS_DIO18_SET               ((uint32_t)0x00040000U)         /* !< DIO18 event occurred */
/* GPIO_CPU_INT_MIS[DIO19] Bits */
#define GPIO_CPU_INT_MIS_DIO19_OFS               (19)                            /* !< DIO19 Offset */
#define GPIO_CPU_INT_MIS_DIO19_MASK              ((uint32_t)0x00080000U)         /* !< DIO19 event */
#define GPIO_CPU_INT_MIS_DIO19_CLR               ((uint32_t)0x00000000U)         /* !< DIO19 event did not occur */
#define GPIO_CPU_INT_MIS_DIO19_SET               ((uint32_t)0x00080000U)         /* !< DIO19 event occurred */
/* GPIO_CPU_INT_MIS[DIO20] Bits */
#define GPIO_CPU_INT_MIS_DIO20_OFS               (20)                            /* !< DIO20 Offset */
#define GPIO_CPU_INT_MIS_DIO20_MASK              ((uint32_t)0x00100000U)         /* !< DIO20 event */
#define GPIO_CPU_INT_MIS_DIO20_CLR               ((uint32_t)0x00000000U)         /* !< DIO20 event did not occur */
#define GPIO_CPU_INT_MIS_DIO20_SET               ((uint32_t)0x00100000U)         /* !< DIO20 event occurred */
/* GPIO_CPU_INT_MIS[DIO21] Bits */
#define GPIO_CPU_INT_MIS_DIO21_OFS               (21)                            /* !< DIO21 Offset */
#define GPIO_CPU_INT_MIS_DIO21_MASK              ((uint32_t)0x00200000U)         /* !< DIO21 event */
#define GPIO_CPU_INT_MIS_DIO21_CLR               ((uint32_t)0x00000000U)         /* !< DIO21 event did not occur */
#define GPIO_CPU_INT_MIS_DIO21_SET               ((uint32_t)0x00200000U)         /* !< DIO21 event occurred */
/* GPIO_CPU_INT_MIS[DIO22] Bits */
#define GPIO_CPU_INT_MIS_DIO22_OFS               (22)                            /* !< DIO22 Offset */
#define GPIO_CPU_INT_MIS_DIO22_MASK              ((uint32_t)0x00400000U)         /* !< DIO22 event */
#define GPIO_CPU_INT_MIS_DIO22_CLR               ((uint32_t)0x00000000U)         /* !< DIO22 event did not occur */
#define GPIO_CPU_INT_MIS_DIO22_SET               ((uint32_t)0x00400000U)         /* !< DIO22 event occurred */
/* GPIO_CPU_INT_MIS[DIO23] Bits */
#define GPIO_CPU_INT_MIS_DIO23_OFS               (23)                            /* !< DIO23 Offset */
#define GPIO_CPU_INT_MIS_DIO23_MASK              ((uint32_t)0x00800000U)         /* !< DIO23 event */
#define GPIO_CPU_INT_MIS_DIO23_CLR               ((uint32_t)0x00000000U)         /* !< DIO23 event did not occur */
#define GPIO_CPU_INT_MIS_DIO23_SET               ((uint32_t)0x00800000U)         /* !< DIO23 event occurred */
/* GPIO_CPU_INT_MIS[DIO24] Bits */
#define GPIO_CPU_INT_MIS_DIO24_OFS               (24)                            /* !< DIO24 Offset */
#define GPIO_CPU_INT_MIS_DIO24_MASK              ((uint32_t)0x01000000U)         /* !< DIO24 event */
#define GPIO_CPU_INT_MIS_DIO24_CLR               ((uint32_t)0x00000000U)         /* !< DIO24 event did not occur */
#define GPIO_CPU_INT_MIS_DIO24_SET               ((uint32_t)0x01000000U)         /* !< DIO24 event occurred */
/* GPIO_CPU_INT_MIS[DIO25] Bits */
#define GPIO_CPU_INT_MIS_DIO25_OFS               (25)                            /* !< DIO25 Offset */
#define GPIO_CPU_INT_MIS_DIO25_MASK              ((uint32_t)0x02000000U)         /* !< DIO25 event */
#define GPIO_CPU_INT_MIS_DIO25_CLR               ((uint32_t)0x00000000U)         /* !< DIO25 event did not occur */
#define GPIO_CPU_INT_MIS_DIO25_SET               ((uint32_t)0x02000000U)         /* !< DIO25 event occurred */
/* GPIO_CPU_INT_MIS[DIO26] Bits */
#define GPIO_CPU_INT_MIS_DIO26_OFS               (26)                            /* !< DIO26 Offset */
#define GPIO_CPU_INT_MIS_DIO26_MASK              ((uint32_t)0x04000000U)         /* !< DIO26 event */
#define GPIO_CPU_INT_MIS_DIO26_CLR               ((uint32_t)0x00000000U)         /* !< DIO26 event did not occur */
#define GPIO_CPU_INT_MIS_DIO26_SET               ((uint32_t)0x04000000U)         /* !< DIO26 event occurred */
/* GPIO_CPU_INT_MIS[DIO27] Bits */
#define GPIO_CPU_INT_MIS_DIO27_OFS               (27)                            /* !< DIO27 Offset */
#define GPIO_CPU_INT_MIS_DIO27_MASK              ((uint32_t)0x08000000U)         /* !< DIO27 event */
#define GPIO_CPU_INT_MIS_DIO27_CLR               ((uint32_t)0x00000000U)         /* !< DIO27 event did not occur */
#define GPIO_CPU_INT_MIS_DIO27_SET               ((uint32_t)0x08000000U)         /* !< DIO27 event occurred */
/* GPIO_CPU_INT_MIS[DIO28] Bits */
#define GPIO_CPU_INT_MIS_DIO28_OFS               (28)                            /* !< DIO28 Offset */
#define GPIO_CPU_INT_MIS_DIO28_MASK              ((uint32_t)0x10000000U)         /* !< DIO28 event */
#define GPIO_CPU_INT_MIS_DIO28_CLR               ((uint32_t)0x00000000U)         /* !< DIO28 event did not occur */
#define GPIO_CPU_INT_MIS_DIO28_SET               ((uint32_t)0x10000000U)         /* !< DIO28 event occurred */
/* GPIO_CPU_INT_MIS[DIO29] Bits */
#define GPIO_CPU_INT_MIS_DIO29_OFS               (29)                            /* !< DIO29 Offset */
#define GPIO_CPU_INT_MIS_DIO29_MASK              ((uint32_t)0x20000000U)         /* !< DIO29 event */
#define GPIO_CPU_INT_MIS_DIO29_CLR               ((uint32_t)0x00000000U)         /* !< DIO29 event did not occur */
#define GPIO_CPU_INT_MIS_DIO29_SET               ((uint32_t)0x20000000U)         /* !< DIO29 event occurred */
/* GPIO_CPU_INT_MIS[DIO30] Bits */
#define GPIO_CPU_INT_MIS_DIO30_OFS               (30)                            /* !< DIO30 Offset */
#define GPIO_CPU_INT_MIS_DIO30_MASK              ((uint32_t)0x40000000U)         /* !< DIO30 event */
#define GPIO_CPU_INT_MIS_DIO30_CLR               ((uint32_t)0x00000000U)         /* !< DIO30 event did not occur */
#define GPIO_CPU_INT_MIS_DIO30_SET               ((uint32_t)0x40000000U)         /* !< DIO30 event occurred */
/* GPIO_CPU_INT_MIS[DIO31] Bits */
#define GPIO_CPU_INT_MIS_DIO31_OFS               (31)                            /* !< DIO31 Offset */
#define GPIO_CPU_INT_MIS_DIO31_MASK              ((uint32_t)0x80000000U)         /* !< DIO31 event */
#define GPIO_CPU_INT_MIS_DIO31_CLR               ((uint32_t)0x00000000U)         /* !< DIO31 event did not occur */
#define GPIO_CPU_INT_MIS_DIO31_SET               ((uint32_t)0x80000000U)         /* !< DIO31 event occurred */

/* GPIO_CPU_INT_ISET Bits */
/* GPIO_CPU_INT_ISET[DIO0] Bits */
#define GPIO_CPU_INT_ISET_DIO0_OFS               (0)                             /* !< DIO0 Offset */
#define GPIO_CPU_INT_ISET_DIO0_MASK              ((uint32_t)0x00000001U)         /* !< DIO0 event */
#define GPIO_CPU_INT_ISET_DIO0_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO0_SET               ((uint32_t)0x00000001U)         /* !< Sets DIO0 in RIS register */
/* GPIO_CPU_INT_ISET[DIO1] Bits */
#define GPIO_CPU_INT_ISET_DIO1_OFS               (1)                             /* !< DIO1 Offset */
#define GPIO_CPU_INT_ISET_DIO1_MASK              ((uint32_t)0x00000002U)         /* !< DIO1 event */
#define GPIO_CPU_INT_ISET_DIO1_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO1_SET               ((uint32_t)0x00000002U)         /* !< Sets DIO1 in RIS register */
/* GPIO_CPU_INT_ISET[DIO2] Bits */
#define GPIO_CPU_INT_ISET_DIO2_OFS               (2)                             /* !< DIO2 Offset */
#define GPIO_CPU_INT_ISET_DIO2_MASK              ((uint32_t)0x00000004U)         /* !< DIO2 event */
#define GPIO_CPU_INT_ISET_DIO2_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO2_SET               ((uint32_t)0x00000004U)         /* !< Sets DIO2 in RIS register */
/* GPIO_CPU_INT_ISET[DIO3] Bits */
#define GPIO_CPU_INT_ISET_DIO3_OFS               (3)                             /* !< DIO3 Offset */
#define GPIO_CPU_INT_ISET_DIO3_MASK              ((uint32_t)0x00000008U)         /* !< DIO3 event */
#define GPIO_CPU_INT_ISET_DIO3_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO3_SET               ((uint32_t)0x00000008U)         /* !< Sets DIO3 in RIS register */
/* GPIO_CPU_INT_ISET[DIO4] Bits */
#define GPIO_CPU_INT_ISET_DIO4_OFS               (4)                             /* !< DIO4 Offset */
#define GPIO_CPU_INT_ISET_DIO4_MASK              ((uint32_t)0x00000010U)         /* !< DIO4 event */
#define GPIO_CPU_INT_ISET_DIO4_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO4_SET               ((uint32_t)0x00000010U)         /* !< Sets DIO4 in RIS register */
/* GPIO_CPU_INT_ISET[DIO5] Bits */
#define GPIO_CPU_INT_ISET_DIO5_OFS               (5)                             /* !< DIO5 Offset */
#define GPIO_CPU_INT_ISET_DIO5_MASK              ((uint32_t)0x00000020U)         /* !< DIO5 event */
#define GPIO_CPU_INT_ISET_DIO5_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO5_SET               ((uint32_t)0x00000020U)         /* !< Sets DIO5 in RIS register */
/* GPIO_CPU_INT_ISET[DIO6] Bits */
#define GPIO_CPU_INT_ISET_DIO6_OFS               (6)                             /* !< DIO6 Offset */
#define GPIO_CPU_INT_ISET_DIO6_MASK              ((uint32_t)0x00000040U)         /* !< DIO6 event */
#define GPIO_CPU_INT_ISET_DIO6_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO6_SET               ((uint32_t)0x00000040U)         /* !< Sets DIO6 in RIS register */
/* GPIO_CPU_INT_ISET[DIO7] Bits */
#define GPIO_CPU_INT_ISET_DIO7_OFS               (7)                             /* !< DIO7 Offset */
#define GPIO_CPU_INT_ISET_DIO7_MASK              ((uint32_t)0x00000080U)         /* !< DIO7 event */
#define GPIO_CPU_INT_ISET_DIO7_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO7_SET               ((uint32_t)0x00000080U)         /* !< Sets DIO7 in RIS register */
/* GPIO_CPU_INT_ISET[DIO8] Bits */
#define GPIO_CPU_INT_ISET_DIO8_OFS               (8)                             /* !< DIO8 Offset */
#define GPIO_CPU_INT_ISET_DIO8_MASK              ((uint32_t)0x00000100U)         /* !< DIO8 event */
#define GPIO_CPU_INT_ISET_DIO8_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO8_SET               ((uint32_t)0x00000100U)         /* !< Sets DIO8 in RIS register */
/* GPIO_CPU_INT_ISET[DIO9] Bits */
#define GPIO_CPU_INT_ISET_DIO9_OFS               (9)                             /* !< DIO9 Offset */
#define GPIO_CPU_INT_ISET_DIO9_MASK              ((uint32_t)0x00000200U)         /* !< DIO9 event */
#define GPIO_CPU_INT_ISET_DIO9_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO9_SET               ((uint32_t)0x00000200U)         /* !< Sets DIO9 in RIS register */
/* GPIO_CPU_INT_ISET[DIO10] Bits */
#define GPIO_CPU_INT_ISET_DIO10_OFS              (10)                            /* !< DIO10 Offset */
#define GPIO_CPU_INT_ISET_DIO10_MASK             ((uint32_t)0x00000400U)         /* !< DIO10 event */
#define GPIO_CPU_INT_ISET_DIO10_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO10_SET              ((uint32_t)0x00000400U)         /* !< Sets DIO10 in RIS register */
/* GPIO_CPU_INT_ISET[DIO11] Bits */
#define GPIO_CPU_INT_ISET_DIO11_OFS              (11)                            /* !< DIO11 Offset */
#define GPIO_CPU_INT_ISET_DIO11_MASK             ((uint32_t)0x00000800U)         /* !< DIO11 event */
#define GPIO_CPU_INT_ISET_DIO11_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO11_SET              ((uint32_t)0x00000800U)         /* !< Sets DIO11 in RIS register */
/* GPIO_CPU_INT_ISET[DIO12] Bits */
#define GPIO_CPU_INT_ISET_DIO12_OFS              (12)                            /* !< DIO12 Offset */
#define GPIO_CPU_INT_ISET_DIO12_MASK             ((uint32_t)0x00001000U)         /* !< DIO12 event */
#define GPIO_CPU_INT_ISET_DIO12_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO12_SET              ((uint32_t)0x00001000U)         /* !< Sets DIO12 in RIS register */
/* GPIO_CPU_INT_ISET[DIO13] Bits */
#define GPIO_CPU_INT_ISET_DIO13_OFS              (13)                            /* !< DIO13 Offset */
#define GPIO_CPU_INT_ISET_DIO13_MASK             ((uint32_t)0x00002000U)         /* !< DIO13 event */
#define GPIO_CPU_INT_ISET_DIO13_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO13_SET              ((uint32_t)0x00002000U)         /* !< Sets DIO13 in RIS register */
/* GPIO_CPU_INT_ISET[DIO14] Bits */
#define GPIO_CPU_INT_ISET_DIO14_OFS              (14)                            /* !< DIO14 Offset */
#define GPIO_CPU_INT_ISET_DIO14_MASK             ((uint32_t)0x00004000U)         /* !< DIO14 event */
#define GPIO_CPU_INT_ISET_DIO14_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO14_SET              ((uint32_t)0x00004000U)         /* !< Sets DIO14 in RIS register */
/* GPIO_CPU_INT_ISET[DIO15] Bits */
#define GPIO_CPU_INT_ISET_DIO15_OFS              (15)                            /* !< DIO15 Offset */
#define GPIO_CPU_INT_ISET_DIO15_MASK             ((uint32_t)0x00008000U)         /* !< DIO15 event */
#define GPIO_CPU_INT_ISET_DIO15_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO15_SET              ((uint32_t)0x00008000U)         /* !< Sets DIO15 in RIS register */
/* GPIO_CPU_INT_ISET[DIO16] Bits */
#define GPIO_CPU_INT_ISET_DIO16_OFS              (16)                            /* !< DIO16 Offset */
#define GPIO_CPU_INT_ISET_DIO16_MASK             ((uint32_t)0x00010000U)         /* !< DIO16 event */
#define GPIO_CPU_INT_ISET_DIO16_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO16_SET              ((uint32_t)0x00010000U)         /* !< Sets DIO16 in RIS register */
/* GPIO_CPU_INT_ISET[DIO17] Bits */
#define GPIO_CPU_INT_ISET_DIO17_OFS              (17)                            /* !< DIO17 Offset */
#define GPIO_CPU_INT_ISET_DIO17_MASK             ((uint32_t)0x00020000U)         /* !< DIO17 event */
#define GPIO_CPU_INT_ISET_DIO17_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO17_SET              ((uint32_t)0x00020000U)         /* !< Sets DIO17 in RIS register */
/* GPIO_CPU_INT_ISET[DIO18] Bits */
#define GPIO_CPU_INT_ISET_DIO18_OFS              (18)                            /* !< DIO18 Offset */
#define GPIO_CPU_INT_ISET_DIO18_MASK             ((uint32_t)0x00040000U)         /* !< DIO18 event */
#define GPIO_CPU_INT_ISET_DIO18_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO18_SET              ((uint32_t)0x00040000U)         /* !< Sets DIO18 in RIS register */
/* GPIO_CPU_INT_ISET[DIO19] Bits */
#define GPIO_CPU_INT_ISET_DIO19_OFS              (19)                            /* !< DIO19 Offset */
#define GPIO_CPU_INT_ISET_DIO19_MASK             ((uint32_t)0x00080000U)         /* !< DIO19 event */
#define GPIO_CPU_INT_ISET_DIO19_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO19_SET              ((uint32_t)0x00080000U)         /* !< Sets DIO19 in RIS register */
/* GPIO_CPU_INT_ISET[DIO20] Bits */
#define GPIO_CPU_INT_ISET_DIO20_OFS              (20)                            /* !< DIO20 Offset */
#define GPIO_CPU_INT_ISET_DIO20_MASK             ((uint32_t)0x00100000U)         /* !< DIO20 event */
#define GPIO_CPU_INT_ISET_DIO20_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO20_SET              ((uint32_t)0x00100000U)         /* !< Sets DIO20 in RIS register */
/* GPIO_CPU_INT_ISET[DIO21] Bits */
#define GPIO_CPU_INT_ISET_DIO21_OFS              (21)                            /* !< DIO21 Offset */
#define GPIO_CPU_INT_ISET_DIO21_MASK             ((uint32_t)0x00200000U)         /* !< DIO21 event */
#define GPIO_CPU_INT_ISET_DIO21_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO21_SET              ((uint32_t)0x00200000U)         /* !< Sets DIO21 in RIS register */
/* GPIO_CPU_INT_ISET[DIO22] Bits */
#define GPIO_CPU_INT_ISET_DIO22_OFS              (22)                            /* !< DIO22 Offset */
#define GPIO_CPU_INT_ISET_DIO22_MASK             ((uint32_t)0x00400000U)         /* !< DIO22 event */
#define GPIO_CPU_INT_ISET_DIO22_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO22_SET              ((uint32_t)0x00400000U)         /* !< Sets DIO22 in RIS register */
/* GPIO_CPU_INT_ISET[DIO23] Bits */
#define GPIO_CPU_INT_ISET_DIO23_OFS              (23)                            /* !< DIO23 Offset */
#define GPIO_CPU_INT_ISET_DIO23_MASK             ((uint32_t)0x00800000U)         /* !< DIO23 event */
#define GPIO_CPU_INT_ISET_DIO23_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO23_SET              ((uint32_t)0x00800000U)         /* !< Sets DIO23 in RIS register */
/* GPIO_CPU_INT_ISET[DIO24] Bits */
#define GPIO_CPU_INT_ISET_DIO24_OFS              (24)                            /* !< DIO24 Offset */
#define GPIO_CPU_INT_ISET_DIO24_MASK             ((uint32_t)0x01000000U)         /* !< DIO24 event */
#define GPIO_CPU_INT_ISET_DIO24_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO24_SET              ((uint32_t)0x01000000U)         /* !< Sets DIO24 in RIS register */
/* GPIO_CPU_INT_ISET[DIO25] Bits */
#define GPIO_CPU_INT_ISET_DIO25_OFS              (25)                            /* !< DIO25 Offset */
#define GPIO_CPU_INT_ISET_DIO25_MASK             ((uint32_t)0x02000000U)         /* !< DIO25 event */
#define GPIO_CPU_INT_ISET_DIO25_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO25_SET              ((uint32_t)0x02000000U)         /* !< Sets DIO25 in RIS register */
/* GPIO_CPU_INT_ISET[DIO26] Bits */
#define GPIO_CPU_INT_ISET_DIO26_OFS              (26)                            /* !< DIO26 Offset */
#define GPIO_CPU_INT_ISET_DIO26_MASK             ((uint32_t)0x04000000U)         /* !< DIO26 event */
#define GPIO_CPU_INT_ISET_DIO26_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO26_SET              ((uint32_t)0x04000000U)         /* !< Sets DIO26 in RIS register */
/* GPIO_CPU_INT_ISET[DIO27] Bits */
#define GPIO_CPU_INT_ISET_DIO27_OFS              (27)                            /* !< DIO27 Offset */
#define GPIO_CPU_INT_ISET_DIO27_MASK             ((uint32_t)0x08000000U)         /* !< DIO27 event */
#define GPIO_CPU_INT_ISET_DIO27_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO27_SET              ((uint32_t)0x08000000U)         /* !< Sets DIO27 in RIS register */
/* GPIO_CPU_INT_ISET[DIO28] Bits */
#define GPIO_CPU_INT_ISET_DIO28_OFS              (28)                            /* !< DIO28 Offset */
#define GPIO_CPU_INT_ISET_DIO28_MASK             ((uint32_t)0x10000000U)         /* !< DIO28 event */
#define GPIO_CPU_INT_ISET_DIO28_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO28_SET              ((uint32_t)0x10000000U)         /* !< Sets DIO28 in RIS register */
/* GPIO_CPU_INT_ISET[DIO29] Bits */
#define GPIO_CPU_INT_ISET_DIO29_OFS              (29)                            /* !< DIO29 Offset */
#define GPIO_CPU_INT_ISET_DIO29_MASK             ((uint32_t)0x20000000U)         /* !< DIO29 event */
#define GPIO_CPU_INT_ISET_DIO29_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO29_SET              ((uint32_t)0x20000000U)         /* !< Sets DIO29 in RIS register */
/* GPIO_CPU_INT_ISET[DIO30] Bits */
#define GPIO_CPU_INT_ISET_DIO30_OFS              (30)                            /* !< DIO30 Offset */
#define GPIO_CPU_INT_ISET_DIO30_MASK             ((uint32_t)0x40000000U)         /* !< DIO30 event */
#define GPIO_CPU_INT_ISET_DIO30_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO30_SET              ((uint32_t)0x40000000U)         /* !< Sets DIO30 in RIS register */
/* GPIO_CPU_INT_ISET[DIO31] Bits */
#define GPIO_CPU_INT_ISET_DIO31_OFS              (31)                            /* !< DIO31 Offset */
#define GPIO_CPU_INT_ISET_DIO31_MASK             ((uint32_t)0x80000000U)         /* !< DIO31 event */
#define GPIO_CPU_INT_ISET_DIO31_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ISET_DIO31_SET              ((uint32_t)0x80000000U)         /* !< Sets DIO31 in RIS register */

/* GPIO_CPU_INT_ICLR Bits */
/* GPIO_CPU_INT_ICLR[DIO0] Bits */
#define GPIO_CPU_INT_ICLR_DIO0_OFS               (0)                             /* !< DIO0 Offset */
#define GPIO_CPU_INT_ICLR_DIO0_MASK              ((uint32_t)0x00000001U)         /* !< DIO0 event */
#define GPIO_CPU_INT_ICLR_DIO0_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO0_CLR               ((uint32_t)0x00000001U)         /* !< Clears DIO0 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO1] Bits */
#define GPIO_CPU_INT_ICLR_DIO1_OFS               (1)                             /* !< DIO1 Offset */
#define GPIO_CPU_INT_ICLR_DIO1_MASK              ((uint32_t)0x00000002U)         /* !< DIO1 event */
#define GPIO_CPU_INT_ICLR_DIO1_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO1_CLR               ((uint32_t)0x00000002U)         /* !< Clears DIO1 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO2] Bits */
#define GPIO_CPU_INT_ICLR_DIO2_OFS               (2)                             /* !< DIO2 Offset */
#define GPIO_CPU_INT_ICLR_DIO2_MASK              ((uint32_t)0x00000004U)         /* !< DIO2 event */
#define GPIO_CPU_INT_ICLR_DIO2_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO2_CLR               ((uint32_t)0x00000004U)         /* !< Clears DIO2 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO3] Bits */
#define GPIO_CPU_INT_ICLR_DIO3_OFS               (3)                             /* !< DIO3 Offset */
#define GPIO_CPU_INT_ICLR_DIO3_MASK              ((uint32_t)0x00000008U)         /* !< DIO3 event */
#define GPIO_CPU_INT_ICLR_DIO3_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO3_CLR               ((uint32_t)0x00000008U)         /* !< Clears DIO3 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO4] Bits */
#define GPIO_CPU_INT_ICLR_DIO4_OFS               (4)                             /* !< DIO4 Offset */
#define GPIO_CPU_INT_ICLR_DIO4_MASK              ((uint32_t)0x00000010U)         /* !< DIO4 event */
#define GPIO_CPU_INT_ICLR_DIO4_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO4_CLR               ((uint32_t)0x00000010U)         /* !< Clears DIO4 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO5] Bits */
#define GPIO_CPU_INT_ICLR_DIO5_OFS               (5)                             /* !< DIO5 Offset */
#define GPIO_CPU_INT_ICLR_DIO5_MASK              ((uint32_t)0x00000020U)         /* !< DIO5 event */
#define GPIO_CPU_INT_ICLR_DIO5_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO5_CLR               ((uint32_t)0x00000020U)         /* !< Clears DIO5 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO6] Bits */
#define GPIO_CPU_INT_ICLR_DIO6_OFS               (6)                             /* !< DIO6 Offset */
#define GPIO_CPU_INT_ICLR_DIO6_MASK              ((uint32_t)0x00000040U)         /* !< DIO6 event */
#define GPIO_CPU_INT_ICLR_DIO6_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO6_CLR               ((uint32_t)0x00000040U)         /* !< Clears DIO6 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO7] Bits */
#define GPIO_CPU_INT_ICLR_DIO7_OFS               (7)                             /* !< DIO7 Offset */
#define GPIO_CPU_INT_ICLR_DIO7_MASK              ((uint32_t)0x00000080U)         /* !< DIO7 event */
#define GPIO_CPU_INT_ICLR_DIO7_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO7_CLR               ((uint32_t)0x00000080U)         /* !< Clears DIO7 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO8] Bits */
#define GPIO_CPU_INT_ICLR_DIO8_OFS               (8)                             /* !< DIO8 Offset */
#define GPIO_CPU_INT_ICLR_DIO8_MASK              ((uint32_t)0x00000100U)         /* !< DIO8 event */
#define GPIO_CPU_INT_ICLR_DIO8_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO8_CLR               ((uint32_t)0x00000100U)         /* !< Clears DIO8 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO9] Bits */
#define GPIO_CPU_INT_ICLR_DIO9_OFS               (9)                             /* !< DIO9 Offset */
#define GPIO_CPU_INT_ICLR_DIO9_MASK              ((uint32_t)0x00000200U)         /* !< DIO9 event */
#define GPIO_CPU_INT_ICLR_DIO9_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO9_CLR               ((uint32_t)0x00000200U)         /* !< Clears DIO9 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO10] Bits */
#define GPIO_CPU_INT_ICLR_DIO10_OFS              (10)                            /* !< DIO10 Offset */
#define GPIO_CPU_INT_ICLR_DIO10_MASK             ((uint32_t)0x00000400U)         /* !< DIO10 event */
#define GPIO_CPU_INT_ICLR_DIO10_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO10_CLR              ((uint32_t)0x00000400U)         /* !< Clears DIO10 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO11] Bits */
#define GPIO_CPU_INT_ICLR_DIO11_OFS              (11)                            /* !< DIO11 Offset */
#define GPIO_CPU_INT_ICLR_DIO11_MASK             ((uint32_t)0x00000800U)         /* !< DIO11 event */
#define GPIO_CPU_INT_ICLR_DIO11_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO11_CLR              ((uint32_t)0x00000800U)         /* !< Clears DIO11 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO12] Bits */
#define GPIO_CPU_INT_ICLR_DIO12_OFS              (12)                            /* !< DIO12 Offset */
#define GPIO_CPU_INT_ICLR_DIO12_MASK             ((uint32_t)0x00001000U)         /* !< DIO12 event */
#define GPIO_CPU_INT_ICLR_DIO12_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO12_CLR              ((uint32_t)0x00001000U)         /* !< Clears DIO12 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO13] Bits */
#define GPIO_CPU_INT_ICLR_DIO13_OFS              (13)                            /* !< DIO13 Offset */
#define GPIO_CPU_INT_ICLR_DIO13_MASK             ((uint32_t)0x00002000U)         /* !< DIO13 event */
#define GPIO_CPU_INT_ICLR_DIO13_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO13_CLR              ((uint32_t)0x00002000U)         /* !< Clears DIO13 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO14] Bits */
#define GPIO_CPU_INT_ICLR_DIO14_OFS              (14)                            /* !< DIO14 Offset */
#define GPIO_CPU_INT_ICLR_DIO14_MASK             ((uint32_t)0x00004000U)         /* !< DIO14 event */
#define GPIO_CPU_INT_ICLR_DIO14_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO14_CLR              ((uint32_t)0x00004000U)         /* !< Clears DIO14 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO15] Bits */
#define GPIO_CPU_INT_ICLR_DIO15_OFS              (15)                            /* !< DIO15 Offset */
#define GPIO_CPU_INT_ICLR_DIO15_MASK             ((uint32_t)0x00008000U)         /* !< DIO15 event */
#define GPIO_CPU_INT_ICLR_DIO15_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO15_CLR              ((uint32_t)0x00008000U)         /* !< Clears DIO15 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO16] Bits */
#define GPIO_CPU_INT_ICLR_DIO16_OFS              (16)                            /* !< DIO16 Offset */
#define GPIO_CPU_INT_ICLR_DIO16_MASK             ((uint32_t)0x00010000U)         /* !< DIO16 event */
#define GPIO_CPU_INT_ICLR_DIO16_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO16_CLR              ((uint32_t)0x00010000U)         /* !< Clears DIO16 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO17] Bits */
#define GPIO_CPU_INT_ICLR_DIO17_OFS              (17)                            /* !< DIO17 Offset */
#define GPIO_CPU_INT_ICLR_DIO17_MASK             ((uint32_t)0x00020000U)         /* !< DIO17 event */
#define GPIO_CPU_INT_ICLR_DIO17_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO17_CLR              ((uint32_t)0x00020000U)         /* !< Clears DIO17 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO18] Bits */
#define GPIO_CPU_INT_ICLR_DIO18_OFS              (18)                            /* !< DIO18 Offset */
#define GPIO_CPU_INT_ICLR_DIO18_MASK             ((uint32_t)0x00040000U)         /* !< DIO18 event */
#define GPIO_CPU_INT_ICLR_DIO18_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO18_CLR              ((uint32_t)0x00040000U)         /* !< Clears DIO18 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO19] Bits */
#define GPIO_CPU_INT_ICLR_DIO19_OFS              (19)                            /* !< DIO19 Offset */
#define GPIO_CPU_INT_ICLR_DIO19_MASK             ((uint32_t)0x00080000U)         /* !< DIO19 event */
#define GPIO_CPU_INT_ICLR_DIO19_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO19_CLR              ((uint32_t)0x00080000U)         /* !< Clears DIO19 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO20] Bits */
#define GPIO_CPU_INT_ICLR_DIO20_OFS              (20)                            /* !< DIO20 Offset */
#define GPIO_CPU_INT_ICLR_DIO20_MASK             ((uint32_t)0x00100000U)         /* !< DIO20 event */
#define GPIO_CPU_INT_ICLR_DIO20_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO20_CLR              ((uint32_t)0x00100000U)         /* !< Clears DIO20 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO21] Bits */
#define GPIO_CPU_INT_ICLR_DIO21_OFS              (21)                            /* !< DIO21 Offset */
#define GPIO_CPU_INT_ICLR_DIO21_MASK             ((uint32_t)0x00200000U)         /* !< DIO21 event */
#define GPIO_CPU_INT_ICLR_DIO21_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO21_CLR              ((uint32_t)0x00200000U)         /* !< Clears DIO21 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO22] Bits */
#define GPIO_CPU_INT_ICLR_DIO22_OFS              (22)                            /* !< DIO22 Offset */
#define GPIO_CPU_INT_ICLR_DIO22_MASK             ((uint32_t)0x00400000U)         /* !< DIO22 event */
#define GPIO_CPU_INT_ICLR_DIO22_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO22_CLR              ((uint32_t)0x00400000U)         /* !< Clears DIO22 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO23] Bits */
#define GPIO_CPU_INT_ICLR_DIO23_OFS              (23)                            /* !< DIO23 Offset */
#define GPIO_CPU_INT_ICLR_DIO23_MASK             ((uint32_t)0x00800000U)         /* !< DIO23 event */
#define GPIO_CPU_INT_ICLR_DIO23_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO23_CLR              ((uint32_t)0x00800000U)         /* !< Clears DIO23 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO24] Bits */
#define GPIO_CPU_INT_ICLR_DIO24_OFS              (24)                            /* !< DIO24 Offset */
#define GPIO_CPU_INT_ICLR_DIO24_MASK             ((uint32_t)0x01000000U)         /* !< DIO24 event */
#define GPIO_CPU_INT_ICLR_DIO24_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO24_CLR              ((uint32_t)0x01000000U)         /* !< Clears DIO24 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO25] Bits */
#define GPIO_CPU_INT_ICLR_DIO25_OFS              (25)                            /* !< DIO25 Offset */
#define GPIO_CPU_INT_ICLR_DIO25_MASK             ((uint32_t)0x02000000U)         /* !< DIO25 event */
#define GPIO_CPU_INT_ICLR_DIO25_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO25_CLR              ((uint32_t)0x02000000U)         /* !< Clears DIO25 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO26] Bits */
#define GPIO_CPU_INT_ICLR_DIO26_OFS              (26)                            /* !< DIO26 Offset */
#define GPIO_CPU_INT_ICLR_DIO26_MASK             ((uint32_t)0x04000000U)         /* !< DIO26 event */
#define GPIO_CPU_INT_ICLR_DIO26_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO26_CLR              ((uint32_t)0x04000000U)         /* !< Clears DIO26 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO27] Bits */
#define GPIO_CPU_INT_ICLR_DIO27_OFS              (27)                            /* !< DIO27 Offset */
#define GPIO_CPU_INT_ICLR_DIO27_MASK             ((uint32_t)0x08000000U)         /* !< DIO27 event */
#define GPIO_CPU_INT_ICLR_DIO27_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO27_CLR              ((uint32_t)0x08000000U)         /* !< Clears DIO27 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO28] Bits */
#define GPIO_CPU_INT_ICLR_DIO28_OFS              (28)                            /* !< DIO28 Offset */
#define GPIO_CPU_INT_ICLR_DIO28_MASK             ((uint32_t)0x10000000U)         /* !< DIO28 event */
#define GPIO_CPU_INT_ICLR_DIO28_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO28_CLR              ((uint32_t)0x10000000U)         /* !< Clears DIO28 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO29] Bits */
#define GPIO_CPU_INT_ICLR_DIO29_OFS              (29)                            /* !< DIO29 Offset */
#define GPIO_CPU_INT_ICLR_DIO29_MASK             ((uint32_t)0x20000000U)         /* !< DIO29 event */
#define GPIO_CPU_INT_ICLR_DIO29_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO29_CLR              ((uint32_t)0x20000000U)         /* !< Clears DIO29 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO30] Bits */
#define GPIO_CPU_INT_ICLR_DIO30_OFS              (30)                            /* !< DIO30 Offset */
#define GPIO_CPU_INT_ICLR_DIO30_MASK             ((uint32_t)0x40000000U)         /* !< DIO30 event */
#define GPIO_CPU_INT_ICLR_DIO30_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO30_CLR              ((uint32_t)0x40000000U)         /* !< Clears DIO30 in RIS register */
/* GPIO_CPU_INT_ICLR[DIO31] Bits */
#define GPIO_CPU_INT_ICLR_DIO31_OFS              (31)                            /* !< DIO31 Offset */
#define GPIO_CPU_INT_ICLR_DIO31_MASK             ((uint32_t)0x80000000U)         /* !< DIO31 event */
#define GPIO_CPU_INT_ICLR_DIO31_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_CPU_INT_ICLR_DIO31_CLR              ((uint32_t)0x80000000U)         /* !< Clears DIO31 in RIS register */

/* GPIO_PWREN Bits */
/* GPIO_PWREN[ENABLE] Bits */
#define GPIO_PWREN_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define GPIO_PWREN_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< Enable the power */
#define GPIO_PWREN_ENABLE_DISABLE                ((uint32_t)0x00000000U)         /* !< Disable Power */
#define GPIO_PWREN_ENABLE_ENABLE                 ((uint32_t)0x00000001U)         /* !< Enable Power */
/* GPIO_PWREN[KEY] Bits */
#define GPIO_PWREN_KEY_OFS                       (24)                            /* !< KEY Offset */
#define GPIO_PWREN_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define GPIO_PWREN_KEY_UNLOCK_W                  ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* GPIO_RSTCTL Bits */
/* GPIO_RSTCTL[RESETSTKYCLR] Bits */
#define GPIO_RSTCTL_RESETSTKYCLR_OFS             (1)                             /* !< RESETSTKYCLR Offset */
#define GPIO_RSTCTL_RESETSTKYCLR_MASK            ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define GPIO_RSTCTL_RESETSTKYCLR_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define GPIO_RSTCTL_RESETSTKYCLR_CLR             ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* GPIO_RSTCTL[RESETASSERT] Bits */
#define GPIO_RSTCTL_RESETASSERT_OFS              (0)                             /* !< RESETASSERT Offset */
#define GPIO_RSTCTL_RESETASSERT_MASK             ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define GPIO_RSTCTL_RESETASSERT_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define GPIO_RSTCTL_RESETASSERT_ASSERT           ((uint32_t)0x00000001U)         /* !< Assert reset */
/* GPIO_RSTCTL[KEY] Bits */
#define GPIO_RSTCTL_KEY_OFS                      (24)                            /* !< KEY Offset */
#define GPIO_RSTCTL_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define GPIO_RSTCTL_KEY_UNLOCK_W                 ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* GPIO_STAT Bits */
/* GPIO_STAT[RESETSTKY] Bits */
#define GPIO_STAT_RESETSTKY_OFS                  (16)                            /* !< RESETSTKY Offset */
#define GPIO_STAT_RESETSTKY_MASK                 ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define GPIO_STAT_RESETSTKY_NORES                ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define GPIO_STAT_RESETSTKY_RESET                ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* GPIO_FSUB_0 Bits */
/* GPIO_FSUB_0[CHANID] Bits */
#define GPIO_FSUB_0_CHANID_OFS                   (0)                             /* !< CHANID Offset */
#define GPIO_FSUB_0_CHANID_MASK                  ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define GPIO_FSUB_0_CHANID_MNIMUM                ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define GPIO_FSUB_0_CHANID_UNCONNECTED           ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define GPIO_FSUB_0_CHANID_MAXIMUM               ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* GPIO_FSUB_1 Bits */
/* GPIO_FSUB_1[CHANID] Bits */
#define GPIO_FSUB_1_CHANID_OFS                   (0)                             /* !< CHANID Offset */
#define GPIO_FSUB_1_CHANID_MASK                  ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define GPIO_FSUB_1_CHANID_MNIMUM                ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define GPIO_FSUB_1_CHANID_UNCONNECTED           ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define GPIO_FSUB_1_CHANID_MAXIMUM               ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* GPIO_FPUB_0 Bits */
/* GPIO_FPUB_0[CHANID] Bits */
#define GPIO_FPUB_0_CHANID_OFS                   (0)                             /* !< CHANID Offset */
#define GPIO_FPUB_0_CHANID_MASK                  ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define GPIO_FPUB_0_CHANID_MNIMUM                ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define GPIO_FPUB_0_CHANID_UNCONNECTED           ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define GPIO_FPUB_0_CHANID_MAXIMUM               ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* GPIO_FPUB_1 Bits */
/* GPIO_FPUB_1[CHANID] Bits */
#define GPIO_FPUB_1_CHANID_OFS                   (0)                             /* !< CHANID Offset */
#define GPIO_FPUB_1_CHANID_MASK                  ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define GPIO_FPUB_1_CHANID_MNIMUM                ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define GPIO_FPUB_1_CHANID_UNCONNECTED           ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define GPIO_FPUB_1_CHANID_MAXIMUM               ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* GPIO_CLKOVR Bits */
/* GPIO_CLKOVR[OVERRIDE] Bits */
#define GPIO_CLKOVR_OVERRIDE_OFS                 (0)                             /* !< OVERRIDE Offset */
#define GPIO_CLKOVR_OVERRIDE_MASK                ((uint32_t)0x00000001U)         /* !< Unlocks the functionality of
                                                                                    [RUN_STOP] to override the automatic
                                                                                    peripheral clock request */
#define GPIO_CLKOVR_OVERRIDE_DISABLED            ((uint32_t)0x00000000U)         /* !< Override disabled */
#define GPIO_CLKOVR_OVERRIDE_ENABLED             ((uint32_t)0x00000001U)         /* !< Override enabled */
/* GPIO_CLKOVR[RUN_STOP] Bits */
#define GPIO_CLKOVR_RUN_STOP_OFS                 (1)                             /* !< RUN_STOP Offset */
#define GPIO_CLKOVR_RUN_STOP_MASK                ((uint32_t)0x00000002U)         /* !< If [OVERRIDE] is enabled, this
                                                                                    register is used to manually control
                                                                                    the peripheral's clock request to the
                                                                                    system */
#define GPIO_CLKOVR_RUN_STOP_RUN                 ((uint32_t)0x00000000U)         /* !< Run/ungate functional clock */
#define GPIO_CLKOVR_RUN_STOP_STOP                ((uint32_t)0x00000002U)         /* !< Stop/gate functional clock */

/* GPIO_PDBGCTL Bits */
/* GPIO_PDBGCTL[FREE] Bits */
#define GPIO_PDBGCTL_FREE_OFS                    (0)                             /* !< FREE Offset */
#define GPIO_PDBGCTL_FREE_MASK                   ((uint32_t)0x00000001U)         /* !< Free run control */
#define GPIO_PDBGCTL_FREE_STOP                   ((uint32_t)0x00000000U)         /* !< The peripheral freezes
                                                                                    functionality while the Core Halted
                                                                                    input is asserted and resumes when it
                                                                                    is deasserted. */
#define GPIO_PDBGCTL_FREE_RUN                    ((uint32_t)0x00000001U)         /* !< The peripheral ignores the state of
                                                                                    the Core Halted input */

/* GPIO_EVT_MODE Bits */
/* GPIO_EVT_MODE[INT0_CFG] Bits */
#define GPIO_EVT_MODE_INT0_CFG_OFS               (0)                             /* !< INT0_CFG Offset */
#define GPIO_EVT_MODE_INT0_CFG_MASK              ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to [IPSTANDARD.CPU_INT] */
#define GPIO_EVT_MODE_INT0_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define GPIO_EVT_MODE_INT0_CFG_SOFTWARE          ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define GPIO_EVT_MODE_INT0_CFG_HARDWARE          ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* GPIO_EVT_MODE[EVT1_CFG] Bits */
#define GPIO_EVT_MODE_EVT1_CFG_OFS               (2)                             /* !< EVT1_CFG Offset */
#define GPIO_EVT_MODE_EVT1_CFG_MASK              ((uint32_t)0x0000000CU)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.GEN_EVENT0] */
#define GPIO_EVT_MODE_EVT1_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define GPIO_EVT_MODE_EVT1_CFG_SOFTWARE          ((uint32_t)0x00000004U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define GPIO_EVT_MODE_EVT1_CFG_HARDWARE          ((uint32_t)0x00000008U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* GPIO_EVT_MODE[EVT2_CFG] Bits */
#define GPIO_EVT_MODE_EVT2_CFG_OFS               (4)                             /* !< EVT2_CFG Offset */
#define GPIO_EVT_MODE_EVT2_CFG_MASK              ((uint32_t)0x00000030U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.GEN_EVENT1] */
#define GPIO_EVT_MODE_EVT2_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define GPIO_EVT_MODE_EVT2_CFG_SOFTWARE          ((uint32_t)0x00000010U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define GPIO_EVT_MODE_EVT2_CFG_HARDWARE          ((uint32_t)0x00000020U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* GPIO_DESC Bits */
/* GPIO_DESC[MINREV] Bits */
#define GPIO_DESC_MINREV_OFS                     (0)                             /* !< MINREV Offset */
#define GPIO_DESC_MINREV_MASK                    ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
#define GPIO_DESC_MINREV_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define GPIO_DESC_MINREV_MAXIMUM                 ((uint32_t)0x0000000FU)         /* !< Highest possible value */
/* GPIO_DESC[MAJREV] Bits */
#define GPIO_DESC_MAJREV_OFS                     (4)                             /* !< MAJREV Offset */
#define GPIO_DESC_MAJREV_MASK                    ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
#define GPIO_DESC_MAJREV_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define GPIO_DESC_MAJREV_MAXIMUM                 ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* GPIO_DESC[FEATUREVER] Bits */
#define GPIO_DESC_FEATUREVER_OFS                 (12)                            /* !< FEATUREVER Offset */
#define GPIO_DESC_FEATUREVER_MASK                ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
#define GPIO_DESC_FEATUREVER_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define GPIO_DESC_FEATUREVER_MAXIMUM             ((uint32_t)0x0000F000U)         /* !< Highest possible value */
/* GPIO_DESC[MODULEID] Bits */
#define GPIO_DESC_MODULEID_OFS                   (16)                            /* !< MODULEID Offset */
#define GPIO_DESC_MODULEID_MASK                  ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */
#define GPIO_DESC_MODULEID_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define GPIO_DESC_MODULEID_MAXIMUM               ((uint32_t)0xFFFF0000U)         /* !< Highest possible value */

/* GPIO_DOUT3_0 Bits */
/* GPIO_DOUT3_0[DIO0] Bits */
#define GPIO_DOUT3_0_DIO0_OFS                    (0)                             /* !< DIO0 Offset */
#define GPIO_DOUT3_0_DIO0_MASK                   ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO0 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT3_0_DIO0_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT3_0_DIO0_ONE                    ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* GPIO_DOUT3_0[DIO1] Bits */
#define GPIO_DOUT3_0_DIO1_OFS                    (8)                             /* !< DIO1 Offset */
#define GPIO_DOUT3_0_DIO1_MASK                   ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO1 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT3_0_DIO1_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT3_0_DIO1_ONE                    ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* GPIO_DOUT3_0[DIO2] Bits */
#define GPIO_DOUT3_0_DIO2_OFS                    (16)                            /* !< DIO2 Offset */
#define GPIO_DOUT3_0_DIO2_MASK                   ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO2 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT3_0_DIO2_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT3_0_DIO2_ONE                    ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* GPIO_DOUT3_0[DIO3] Bits */
#define GPIO_DOUT3_0_DIO3_OFS                    (24)                            /* !< DIO3 Offset */
#define GPIO_DOUT3_0_DIO3_MASK                   ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO3 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT3_0_DIO3_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT3_0_DIO3_ONE                    ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* GPIO_DOUT7_4 Bits */
/* GPIO_DOUT7_4[DIO4] Bits */
#define GPIO_DOUT7_4_DIO4_OFS                    (0)                             /* !< DIO4 Offset */
#define GPIO_DOUT7_4_DIO4_MASK                   ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO4 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT7_4_DIO4_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT7_4_DIO4_ONE                    ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* GPIO_DOUT7_4[DIO5] Bits */
#define GPIO_DOUT7_4_DIO5_OFS                    (8)                             /* !< DIO5 Offset */
#define GPIO_DOUT7_4_DIO5_MASK                   ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO5 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT7_4_DIO5_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT7_4_DIO5_ONE                    ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* GPIO_DOUT7_4[DIO6] Bits */
#define GPIO_DOUT7_4_DIO6_OFS                    (16)                            /* !< DIO6 Offset */
#define GPIO_DOUT7_4_DIO6_MASK                   ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO6 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT7_4_DIO6_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT7_4_DIO6_ONE                    ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* GPIO_DOUT7_4[DIO7] Bits */
#define GPIO_DOUT7_4_DIO7_OFS                    (24)                            /* !< DIO7 Offset */
#define GPIO_DOUT7_4_DIO7_MASK                   ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO7 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT7_4_DIO7_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT7_4_DIO7_ONE                    ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* GPIO_DOUT11_8 Bits */
/* GPIO_DOUT11_8[DIO8] Bits */
#define GPIO_DOUT11_8_DIO8_OFS                   (0)                             /* !< DIO8 Offset */
#define GPIO_DOUT11_8_DIO8_MASK                  ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO8 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT11_8_DIO8_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT11_8_DIO8_ONE                   ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* GPIO_DOUT11_8[DIO9] Bits */
#define GPIO_DOUT11_8_DIO9_OFS                   (8)                             /* !< DIO9 Offset */
#define GPIO_DOUT11_8_DIO9_MASK                  ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO9 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT11_8_DIO9_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT11_8_DIO9_ONE                   ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* GPIO_DOUT11_8[DIO10] Bits */
#define GPIO_DOUT11_8_DIO10_OFS                  (16)                            /* !< DIO10 Offset */
#define GPIO_DOUT11_8_DIO10_MASK                 ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO10 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT11_8_DIO10_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT11_8_DIO10_ONE                  ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* GPIO_DOUT11_8[DIO11] Bits */
#define GPIO_DOUT11_8_DIO11_OFS                  (24)                            /* !< DIO11 Offset */
#define GPIO_DOUT11_8_DIO11_MASK                 ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO11 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT11_8_DIO11_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT11_8_DIO11_ONE                  ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* GPIO_DOUT15_12 Bits */
/* GPIO_DOUT15_12[DIO12] Bits */
#define GPIO_DOUT15_12_DIO12_OFS                 (0)                             /* !< DIO12 Offset */
#define GPIO_DOUT15_12_DIO12_MASK                ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO12 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT15_12_DIO12_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT15_12_DIO12_ONE                 ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* GPIO_DOUT15_12[DIO13] Bits */
#define GPIO_DOUT15_12_DIO13_OFS                 (8)                             /* !< DIO13 Offset */
#define GPIO_DOUT15_12_DIO13_MASK                ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO13 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT15_12_DIO13_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT15_12_DIO13_ONE                 ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* GPIO_DOUT15_12[DIO14] Bits */
#define GPIO_DOUT15_12_DIO14_OFS                 (16)                            /* !< DIO14 Offset */
#define GPIO_DOUT15_12_DIO14_MASK                ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO14 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT15_12_DIO14_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT15_12_DIO14_ONE                 ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* GPIO_DOUT15_12[DIO15] Bits */
#define GPIO_DOUT15_12_DIO15_OFS                 (24)                            /* !< DIO15 Offset */
#define GPIO_DOUT15_12_DIO15_MASK                ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO15 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT15_12_DIO15_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT15_12_DIO15_ONE                 ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* GPIO_DOUT19_16 Bits */
/* GPIO_DOUT19_16[DIO16] Bits */
#define GPIO_DOUT19_16_DIO16_OFS                 (0)                             /* !< DIO16 Offset */
#define GPIO_DOUT19_16_DIO16_MASK                ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO16 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT19_16_DIO16_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT19_16_DIO16_ONE                 ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* GPIO_DOUT19_16[DIO17] Bits */
#define GPIO_DOUT19_16_DIO17_OFS                 (8)                             /* !< DIO17 Offset */
#define GPIO_DOUT19_16_DIO17_MASK                ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO17 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT19_16_DIO17_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT19_16_DIO17_ONE                 ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* GPIO_DOUT19_16[DIO18] Bits */
#define GPIO_DOUT19_16_DIO18_OFS                 (16)                            /* !< DIO18 Offset */
#define GPIO_DOUT19_16_DIO18_MASK                ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO18 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT19_16_DIO18_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT19_16_DIO18_ONE                 ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* GPIO_DOUT19_16[DIO19] Bits */
#define GPIO_DOUT19_16_DIO19_OFS                 (24)                            /* !< DIO19 Offset */
#define GPIO_DOUT19_16_DIO19_MASK                ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO19 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT19_16_DIO19_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT19_16_DIO19_ONE                 ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* GPIO_DOUT23_20 Bits */
/* GPIO_DOUT23_20[DIO20] Bits */
#define GPIO_DOUT23_20_DIO20_OFS                 (0)                             /* !< DIO20 Offset */
#define GPIO_DOUT23_20_DIO20_MASK                ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO20 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT23_20_DIO20_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT23_20_DIO20_ONE                 ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* GPIO_DOUT23_20[DIO21] Bits */
#define GPIO_DOUT23_20_DIO21_OFS                 (8)                             /* !< DIO21 Offset */
#define GPIO_DOUT23_20_DIO21_MASK                ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO21 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT23_20_DIO21_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT23_20_DIO21_ONE                 ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* GPIO_DOUT23_20[DIO22] Bits */
#define GPIO_DOUT23_20_DIO22_OFS                 (16)                            /* !< DIO22 Offset */
#define GPIO_DOUT23_20_DIO22_MASK                ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO22 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT23_20_DIO22_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT23_20_DIO22_ONE                 ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* GPIO_DOUT23_20[DIO23] Bits */
#define GPIO_DOUT23_20_DIO23_OFS                 (24)                            /* !< DIO23 Offset */
#define GPIO_DOUT23_20_DIO23_MASK                ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO23 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT23_20_DIO23_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT23_20_DIO23_ONE                 ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* GPIO_DOUT27_24 Bits */
/* GPIO_DOUT27_24[DIO24] Bits */
#define GPIO_DOUT27_24_DIO24_OFS                 (0)                             /* !< DIO24 Offset */
#define GPIO_DOUT27_24_DIO24_MASK                ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO24 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT27_24_DIO24_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT27_24_DIO24_ONE                 ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* GPIO_DOUT27_24[DIO25] Bits */
#define GPIO_DOUT27_24_DIO25_OFS                 (8)                             /* !< DIO25 Offset */
#define GPIO_DOUT27_24_DIO25_MASK                ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO25 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT27_24_DIO25_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT27_24_DIO25_ONE                 ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* GPIO_DOUT27_24[DIO26] Bits */
#define GPIO_DOUT27_24_DIO26_OFS                 (16)                            /* !< DIO26 Offset */
#define GPIO_DOUT27_24_DIO26_MASK                ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO26 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT27_24_DIO26_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT27_24_DIO26_ONE                 ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* GPIO_DOUT27_24[DIO27] Bits */
#define GPIO_DOUT27_24_DIO27_OFS                 (24)                            /* !< DIO27 Offset */
#define GPIO_DOUT27_24_DIO27_MASK                ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO27 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT27_24_DIO27_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT27_24_DIO27_ONE                 ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* GPIO_DOUT31_28 Bits */
/* GPIO_DOUT31_28[DIO28] Bits */
#define GPIO_DOUT31_28_DIO28_OFS                 (0)                             /* !< DIO28 Offset */
#define GPIO_DOUT31_28_DIO28_MASK                ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO28 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_28_DIO28_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_28_DIO28_ONE                 ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_28[DIO29] Bits */
#define GPIO_DOUT31_28_DIO29_OFS                 (8)                             /* !< DIO29 Offset */
#define GPIO_DOUT31_28_DIO29_MASK                ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO29 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_28_DIO29_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_28_DIO29_ONE                 ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_28[DIO30] Bits */
#define GPIO_DOUT31_28_DIO30_OFS                 (16)                            /* !< DIO30 Offset */
#define GPIO_DOUT31_28_DIO30_MASK                ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO30 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_28_DIO30_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_28_DIO30_ONE                 ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_28[DIO31] Bits */
#define GPIO_DOUT31_28_DIO31_OFS                 (24)                            /* !< DIO31 Offset */
#define GPIO_DOUT31_28_DIO31_MASK                ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO31 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_28_DIO31_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_28_DIO31_ONE                 ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* GPIO_DOUT31_0 Bits */
/* GPIO_DOUT31_0[DIO0] Bits */
#define GPIO_DOUT31_0_DIO0_OFS                   (0)                             /* !< DIO0 Offset */
#define GPIO_DOUT31_0_DIO0_MASK                  ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO0 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO0_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO0_ONE                   ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO1] Bits */
#define GPIO_DOUT31_0_DIO1_OFS                   (1)                             /* !< DIO1 Offset */
#define GPIO_DOUT31_0_DIO1_MASK                  ((uint32_t)0x00000002U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO1 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO1_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO1_ONE                   ((uint32_t)0x00000002U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO2] Bits */
#define GPIO_DOUT31_0_DIO2_OFS                   (2)                             /* !< DIO2 Offset */
#define GPIO_DOUT31_0_DIO2_MASK                  ((uint32_t)0x00000004U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO2 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO2_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO2_ONE                   ((uint32_t)0x00000004U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO3] Bits */
#define GPIO_DOUT31_0_DIO3_OFS                   (3)                             /* !< DIO3 Offset */
#define GPIO_DOUT31_0_DIO3_MASK                  ((uint32_t)0x00000008U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO3 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO3_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO3_ONE                   ((uint32_t)0x00000008U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO4] Bits */
#define GPIO_DOUT31_0_DIO4_OFS                   (4)                             /* !< DIO4 Offset */
#define GPIO_DOUT31_0_DIO4_MASK                  ((uint32_t)0x00000010U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO4 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO4_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO4_ONE                   ((uint32_t)0x00000010U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO5] Bits */
#define GPIO_DOUT31_0_DIO5_OFS                   (5)                             /* !< DIO5 Offset */
#define GPIO_DOUT31_0_DIO5_MASK                  ((uint32_t)0x00000020U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO5 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO5_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO5_ONE                   ((uint32_t)0x00000020U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO6] Bits */
#define GPIO_DOUT31_0_DIO6_OFS                   (6)                             /* !< DIO6 Offset */
#define GPIO_DOUT31_0_DIO6_MASK                  ((uint32_t)0x00000040U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO6 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO6_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO6_ONE                   ((uint32_t)0x00000040U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO7] Bits */
#define GPIO_DOUT31_0_DIO7_OFS                   (7)                             /* !< DIO7 Offset */
#define GPIO_DOUT31_0_DIO7_MASK                  ((uint32_t)0x00000080U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO7 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO7_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO7_ONE                   ((uint32_t)0x00000080U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO8] Bits */
#define GPIO_DOUT31_0_DIO8_OFS                   (8)                             /* !< DIO8 Offset */
#define GPIO_DOUT31_0_DIO8_MASK                  ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO8 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO8_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO8_ONE                   ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO9] Bits */
#define GPIO_DOUT31_0_DIO9_OFS                   (9)                             /* !< DIO9 Offset */
#define GPIO_DOUT31_0_DIO9_MASK                  ((uint32_t)0x00000200U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO9 when the output is
                                                                                    enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO9_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO9_ONE                   ((uint32_t)0x00000200U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO10] Bits */
#define GPIO_DOUT31_0_DIO10_OFS                  (10)                            /* !< DIO10 Offset */
#define GPIO_DOUT31_0_DIO10_MASK                 ((uint32_t)0x00000400U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO10 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO10_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO10_ONE                  ((uint32_t)0x00000400U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO11] Bits */
#define GPIO_DOUT31_0_DIO11_OFS                  (11)                            /* !< DIO11 Offset */
#define GPIO_DOUT31_0_DIO11_MASK                 ((uint32_t)0x00000800U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO11 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO11_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO11_ONE                  ((uint32_t)0x00000800U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO12] Bits */
#define GPIO_DOUT31_0_DIO12_OFS                  (12)                            /* !< DIO12 Offset */
#define GPIO_DOUT31_0_DIO12_MASK                 ((uint32_t)0x00001000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO12 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO12_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO12_ONE                  ((uint32_t)0x00001000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO13] Bits */
#define GPIO_DOUT31_0_DIO13_OFS                  (13)                            /* !< DIO13 Offset */
#define GPIO_DOUT31_0_DIO13_MASK                 ((uint32_t)0x00002000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO13 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO13_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO13_ONE                  ((uint32_t)0x00002000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO14] Bits */
#define GPIO_DOUT31_0_DIO14_OFS                  (14)                            /* !< DIO14 Offset */
#define GPIO_DOUT31_0_DIO14_MASK                 ((uint32_t)0x00004000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO14 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO14_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO14_ONE                  ((uint32_t)0x00004000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO15] Bits */
#define GPIO_DOUT31_0_DIO15_OFS                  (15)                            /* !< DIO15 Offset */
#define GPIO_DOUT31_0_DIO15_MASK                 ((uint32_t)0x00008000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO15 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO15_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO15_ONE                  ((uint32_t)0x00008000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO16] Bits */
#define GPIO_DOUT31_0_DIO16_OFS                  (16)                            /* !< DIO16 Offset */
#define GPIO_DOUT31_0_DIO16_MASK                 ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO16 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO16_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO16_ONE                  ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO17] Bits */
#define GPIO_DOUT31_0_DIO17_OFS                  (17)                            /* !< DIO17 Offset */
#define GPIO_DOUT31_0_DIO17_MASK                 ((uint32_t)0x00020000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO17 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO17_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO17_ONE                  ((uint32_t)0x00020000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO18] Bits */
#define GPIO_DOUT31_0_DIO18_OFS                  (18)                            /* !< DIO18 Offset */
#define GPIO_DOUT31_0_DIO18_MASK                 ((uint32_t)0x00040000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO18 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO18_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO18_ONE                  ((uint32_t)0x00040000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO19] Bits */
#define GPIO_DOUT31_0_DIO19_OFS                  (19)                            /* !< DIO19 Offset */
#define GPIO_DOUT31_0_DIO19_MASK                 ((uint32_t)0x00080000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO19 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO19_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO19_ONE                  ((uint32_t)0x00080000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO20] Bits */
#define GPIO_DOUT31_0_DIO20_OFS                  (20)                            /* !< DIO20 Offset */
#define GPIO_DOUT31_0_DIO20_MASK                 ((uint32_t)0x00100000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO20 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO20_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO20_ONE                  ((uint32_t)0x00100000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO21] Bits */
#define GPIO_DOUT31_0_DIO21_OFS                  (21)                            /* !< DIO21 Offset */
#define GPIO_DOUT31_0_DIO21_MASK                 ((uint32_t)0x00200000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO21 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO21_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO21_ONE                  ((uint32_t)0x00200000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO22] Bits */
#define GPIO_DOUT31_0_DIO22_OFS                  (22)                            /* !< DIO22 Offset */
#define GPIO_DOUT31_0_DIO22_MASK                 ((uint32_t)0x00400000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO22 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO22_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO22_ONE                  ((uint32_t)0x00400000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO23] Bits */
#define GPIO_DOUT31_0_DIO23_OFS                  (23)                            /* !< DIO23 Offset */
#define GPIO_DOUT31_0_DIO23_MASK                 ((uint32_t)0x00800000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO23 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO23_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO23_ONE                  ((uint32_t)0x00800000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO24] Bits */
#define GPIO_DOUT31_0_DIO24_OFS                  (24)                            /* !< DIO24 Offset */
#define GPIO_DOUT31_0_DIO24_MASK                 ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO24 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO24_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO24_ONE                  ((uint32_t)0x01000000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO25] Bits */
#define GPIO_DOUT31_0_DIO25_OFS                  (25)                            /* !< DIO25 Offset */
#define GPIO_DOUT31_0_DIO25_MASK                 ((uint32_t)0x02000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO25 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO25_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO25_ONE                  ((uint32_t)0x02000000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO26] Bits */
#define GPIO_DOUT31_0_DIO26_OFS                  (26)                            /* !< DIO26 Offset */
#define GPIO_DOUT31_0_DIO26_MASK                 ((uint32_t)0x04000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO26 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO26_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO26_ONE                  ((uint32_t)0x04000000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO27] Bits */
#define GPIO_DOUT31_0_DIO27_OFS                  (27)                            /* !< DIO27 Offset */
#define GPIO_DOUT31_0_DIO27_MASK                 ((uint32_t)0x08000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO27 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO27_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO27_ONE                  ((uint32_t)0x08000000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO28] Bits */
#define GPIO_DOUT31_0_DIO28_OFS                  (28)                            /* !< DIO28 Offset */
#define GPIO_DOUT31_0_DIO28_MASK                 ((uint32_t)0x10000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO28 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO28_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO28_ONE                  ((uint32_t)0x10000000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO29] Bits */
#define GPIO_DOUT31_0_DIO29_OFS                  (29)                            /* !< DIO29 Offset */
#define GPIO_DOUT31_0_DIO29_MASK                 ((uint32_t)0x20000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO29 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO29_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO29_ONE                  ((uint32_t)0x20000000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO30] Bits */
#define GPIO_DOUT31_0_DIO30_OFS                  (30)                            /* !< DIO30 Offset */
#define GPIO_DOUT31_0_DIO30_MASK                 ((uint32_t)0x40000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO30 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO30_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO30_ONE                  ((uint32_t)0x40000000U)         /* !< Output is set to 1 */
/* GPIO_DOUT31_0[DIO31] Bits */
#define GPIO_DOUT31_0_DIO31_OFS                  (31)                            /* !< DIO31 Offset */
#define GPIO_DOUT31_0_DIO31_MASK                 ((uint32_t)0x80000000U)         /* !< This bit sets the value of the pin
                                                                                    configured as DIO31 when the output
                                                                                    is enabled through DOE31_0 register. */
#define GPIO_DOUT31_0_DIO31_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define GPIO_DOUT31_0_DIO31_ONE                  ((uint32_t)0x80000000U)         /* !< Output is set to 1 */

/* GPIO_DOUTSET31_0 Bits */
/* GPIO_DOUTSET31_0[DIO0] Bits */
#define GPIO_DOUTSET31_0_DIO0_OFS                (0)                             /* !< DIO0 Offset */
#define GPIO_DOUTSET31_0_DIO0_MASK               ((uint32_t)0x00000001U)         /* !< Writing 1 to this bit sets the DIO0
                                                                                    bit in the DOUT31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOUTSET31_0_DIO0_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO0_SET                ((uint32_t)0x00000001U)         /* !< Sets DIO0 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO1] Bits */
#define GPIO_DOUTSET31_0_DIO1_OFS                (1)                             /* !< DIO1 Offset */
#define GPIO_DOUTSET31_0_DIO1_MASK               ((uint32_t)0x00000002U)         /* !< Writing 1 to this bit sets the DIO1
                                                                                    bit in the DOUT31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOUTSET31_0_DIO1_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO1_SET                ((uint32_t)0x00000002U)         /* !< Sets DIO1 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO2] Bits */
#define GPIO_DOUTSET31_0_DIO2_OFS                (2)                             /* !< DIO2 Offset */
#define GPIO_DOUTSET31_0_DIO2_MASK               ((uint32_t)0x00000004U)         /* !< Writing 1 to this bit sets the DIO2
                                                                                    bit in the DOUT31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOUTSET31_0_DIO2_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO2_SET                ((uint32_t)0x00000004U)         /* !< Sets DIO2 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO3] Bits */
#define GPIO_DOUTSET31_0_DIO3_OFS                (3)                             /* !< DIO3 Offset */
#define GPIO_DOUTSET31_0_DIO3_MASK               ((uint32_t)0x00000008U)         /* !< Writing 1 to this bit sets the DIO3
                                                                                    bit in the DOUT31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOUTSET31_0_DIO3_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO3_SET                ((uint32_t)0x00000008U)         /* !< Sets DIO3 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO4] Bits */
#define GPIO_DOUTSET31_0_DIO4_OFS                (4)                             /* !< DIO4 Offset */
#define GPIO_DOUTSET31_0_DIO4_MASK               ((uint32_t)0x00000010U)         /* !< Writing 1 to this bit sets the DIO4
                                                                                    bit in the DOUT31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOUTSET31_0_DIO4_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO4_SET                ((uint32_t)0x00000010U)         /* !< Sets DIO4 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO5] Bits */
#define GPIO_DOUTSET31_0_DIO5_OFS                (5)                             /* !< DIO5 Offset */
#define GPIO_DOUTSET31_0_DIO5_MASK               ((uint32_t)0x00000020U)         /* !< Writing 1 to this bit sets the DIO5
                                                                                    bit in the DOUT31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOUTSET31_0_DIO5_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO5_SET                ((uint32_t)0x00000020U)         /* !< Sets DIO5 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO6] Bits */
#define GPIO_DOUTSET31_0_DIO6_OFS                (6)                             /* !< DIO6 Offset */
#define GPIO_DOUTSET31_0_DIO6_MASK               ((uint32_t)0x00000040U)         /* !< Writing 1 to this bit sets the DIO6
                                                                                    bit in the DOUT31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOUTSET31_0_DIO6_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO6_SET                ((uint32_t)0x00000040U)         /* !< Sets DIO6 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO7] Bits */
#define GPIO_DOUTSET31_0_DIO7_OFS                (7)                             /* !< DIO7 Offset */
#define GPIO_DOUTSET31_0_DIO7_MASK               ((uint32_t)0x00000080U)         /* !< Writing 1 to this bit sets the DIO7
                                                                                    bit in the DOUT31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOUTSET31_0_DIO7_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO7_SET                ((uint32_t)0x00000080U)         /* !< Sets DIO7 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO8] Bits */
#define GPIO_DOUTSET31_0_DIO8_OFS                (8)                             /* !< DIO8 Offset */
#define GPIO_DOUTSET31_0_DIO8_MASK               ((uint32_t)0x00000100U)         /* !< Writing 1 to this bit sets the DIO8
                                                                                    bit in the DOUT31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOUTSET31_0_DIO8_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO8_SET                ((uint32_t)0x00000100U)         /* !< Sets DIO8 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO9] Bits */
#define GPIO_DOUTSET31_0_DIO9_OFS                (9)                             /* !< DIO9 Offset */
#define GPIO_DOUTSET31_0_DIO9_MASK               ((uint32_t)0x00000200U)         /* !< Writing 1 to this bit sets the DIO9
                                                                                    bit in the DOUT31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOUTSET31_0_DIO9_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO9_SET                ((uint32_t)0x00000200U)         /* !< Sets DIO9 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO10] Bits */
#define GPIO_DOUTSET31_0_DIO10_OFS               (10)                            /* !< DIO10 Offset */
#define GPIO_DOUTSET31_0_DIO10_MASK              ((uint32_t)0x00000400U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO10 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO10_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO10_SET               ((uint32_t)0x00000400U)         /* !< Sets DIO10 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO11] Bits */
#define GPIO_DOUTSET31_0_DIO11_OFS               (11)                            /* !< DIO11 Offset */
#define GPIO_DOUTSET31_0_DIO11_MASK              ((uint32_t)0x00000800U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO11 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO11_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO11_SET               ((uint32_t)0x00000800U)         /* !< Sets DIO11 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO12] Bits */
#define GPIO_DOUTSET31_0_DIO12_OFS               (12)                            /* !< DIO12 Offset */
#define GPIO_DOUTSET31_0_DIO12_MASK              ((uint32_t)0x00001000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO12 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO12_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO12_SET               ((uint32_t)0x00001000U)         /* !< Sets DIO12 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO13] Bits */
#define GPIO_DOUTSET31_0_DIO13_OFS               (13)                            /* !< DIO13 Offset */
#define GPIO_DOUTSET31_0_DIO13_MASK              ((uint32_t)0x00002000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO13 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO13_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO13_SET               ((uint32_t)0x00002000U)         /* !< Sets DIO13 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO14] Bits */
#define GPIO_DOUTSET31_0_DIO14_OFS               (14)                            /* !< DIO14 Offset */
#define GPIO_DOUTSET31_0_DIO14_MASK              ((uint32_t)0x00004000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO14 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO14_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO14_SET               ((uint32_t)0x00004000U)         /* !< Sets DIO14 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO15] Bits */
#define GPIO_DOUTSET31_0_DIO15_OFS               (15)                            /* !< DIO15 Offset */
#define GPIO_DOUTSET31_0_DIO15_MASK              ((uint32_t)0x00008000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO15 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO15_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO15_SET               ((uint32_t)0x00008000U)         /* !< Sets DIO15 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO16] Bits */
#define GPIO_DOUTSET31_0_DIO16_OFS               (16)                            /* !< DIO16 Offset */
#define GPIO_DOUTSET31_0_DIO16_MASK              ((uint32_t)0x00010000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO16 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO16_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO16_SET               ((uint32_t)0x00010000U)         /* !< Sets DIO16 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO17] Bits */
#define GPIO_DOUTSET31_0_DIO17_OFS               (17)                            /* !< DIO17 Offset */
#define GPIO_DOUTSET31_0_DIO17_MASK              ((uint32_t)0x00020000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO17 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO17_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO17_SET               ((uint32_t)0x00020000U)         /* !< Sets DIO17 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO18] Bits */
#define GPIO_DOUTSET31_0_DIO18_OFS               (18)                            /* !< DIO18 Offset */
#define GPIO_DOUTSET31_0_DIO18_MASK              ((uint32_t)0x00040000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO18 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO18_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO18_SET               ((uint32_t)0x00040000U)         /* !< Sets DIO18 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO19] Bits */
#define GPIO_DOUTSET31_0_DIO19_OFS               (19)                            /* !< DIO19 Offset */
#define GPIO_DOUTSET31_0_DIO19_MASK              ((uint32_t)0x00080000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO19 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO19_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO19_SET               ((uint32_t)0x00080000U)         /* !< Sets DIO19 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO20] Bits */
#define GPIO_DOUTSET31_0_DIO20_OFS               (20)                            /* !< DIO20 Offset */
#define GPIO_DOUTSET31_0_DIO20_MASK              ((uint32_t)0x00100000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO20 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO20_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO20_SET               ((uint32_t)0x00100000U)         /* !< Sets DIO20 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO21] Bits */
#define GPIO_DOUTSET31_0_DIO21_OFS               (21)                            /* !< DIO21 Offset */
#define GPIO_DOUTSET31_0_DIO21_MASK              ((uint32_t)0x00200000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO21 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO21_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO21_SET               ((uint32_t)0x00200000U)         /* !< Sets DIO21 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO22] Bits */
#define GPIO_DOUTSET31_0_DIO22_OFS               (22)                            /* !< DIO22 Offset */
#define GPIO_DOUTSET31_0_DIO22_MASK              ((uint32_t)0x00400000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO22 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO22_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO22_SET               ((uint32_t)0x00400000U)         /* !< Sets DIO22 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO23] Bits */
#define GPIO_DOUTSET31_0_DIO23_OFS               (23)                            /* !< DIO23 Offset */
#define GPIO_DOUTSET31_0_DIO23_MASK              ((uint32_t)0x00800000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO23 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO23_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO23_SET               ((uint32_t)0x00800000U)         /* !< Sets DIO23 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO24] Bits */
#define GPIO_DOUTSET31_0_DIO24_OFS               (24)                            /* !< DIO24 Offset */
#define GPIO_DOUTSET31_0_DIO24_MASK              ((uint32_t)0x01000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO24 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO24_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO24_SET               ((uint32_t)0x01000000U)         /* !< Sets DIO24 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO25] Bits */
#define GPIO_DOUTSET31_0_DIO25_OFS               (25)                            /* !< DIO25 Offset */
#define GPIO_DOUTSET31_0_DIO25_MASK              ((uint32_t)0x02000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO25 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO25_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO25_SET               ((uint32_t)0x02000000U)         /* !< Sets DIO25 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO26] Bits */
#define GPIO_DOUTSET31_0_DIO26_OFS               (26)                            /* !< DIO26 Offset */
#define GPIO_DOUTSET31_0_DIO26_MASK              ((uint32_t)0x04000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO26 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO26_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO26_SET               ((uint32_t)0x04000000U)         /* !< Sets DIO26 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO27] Bits */
#define GPIO_DOUTSET31_0_DIO27_OFS               (27)                            /* !< DIO27 Offset */
#define GPIO_DOUTSET31_0_DIO27_MASK              ((uint32_t)0x08000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO27 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO27_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO27_SET               ((uint32_t)0x08000000U)         /* !< Sets DIO27 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO28] Bits */
#define GPIO_DOUTSET31_0_DIO28_OFS               (28)                            /* !< DIO28 Offset */
#define GPIO_DOUTSET31_0_DIO28_MASK              ((uint32_t)0x10000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO28 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO28_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO28_SET               ((uint32_t)0x10000000U)         /* !< Sets DIO28 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO29] Bits */
#define GPIO_DOUTSET31_0_DIO29_OFS               (29)                            /* !< DIO29 Offset */
#define GPIO_DOUTSET31_0_DIO29_MASK              ((uint32_t)0x20000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO29 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO29_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO29_SET               ((uint32_t)0x20000000U)         /* !< Sets DIO29 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO30] Bits */
#define GPIO_DOUTSET31_0_DIO30_OFS               (30)                            /* !< DIO30 Offset */
#define GPIO_DOUTSET31_0_DIO30_MASK              ((uint32_t)0x40000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO30 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO30_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO30_SET               ((uint32_t)0x40000000U)         /* !< Sets DIO30 in DOUT31_0 */
/* GPIO_DOUTSET31_0[DIO31] Bits */
#define GPIO_DOUTSET31_0_DIO31_OFS               (31)                            /* !< DIO31 Offset */
#define GPIO_DOUTSET31_0_DIO31_MASK              ((uint32_t)0x80000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO31 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTSET31_0_DIO31_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTSET31_0_DIO31_SET               ((uint32_t)0x80000000U)         /* !< Sets DIO31 in DOUT31_0 */

/* GPIO_DOUTCLR31_0 Bits */
/* GPIO_DOUTCLR31_0[DIO0] Bits */
#define GPIO_DOUTCLR31_0_DIO0_OFS                (0)                             /* !< DIO0 Offset */
#define GPIO_DOUTCLR31_0_DIO0_MASK               ((uint32_t)0x00000001U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO0 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO0_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO0_CLR                ((uint32_t)0x00000001U)         /* !< Clears DIO0 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO1] Bits */
#define GPIO_DOUTCLR31_0_DIO1_OFS                (1)                             /* !< DIO1 Offset */
#define GPIO_DOUTCLR31_0_DIO1_MASK               ((uint32_t)0x00000002U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO1 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO1_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO1_CLR                ((uint32_t)0x00000002U)         /* !< Clears DIO1 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO2] Bits */
#define GPIO_DOUTCLR31_0_DIO2_OFS                (2)                             /* !< DIO2 Offset */
#define GPIO_DOUTCLR31_0_DIO2_MASK               ((uint32_t)0x00000004U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO2 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO2_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO2_CLR                ((uint32_t)0x00000004U)         /* !< Clears DIO2 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO3] Bits */
#define GPIO_DOUTCLR31_0_DIO3_OFS                (3)                             /* !< DIO3 Offset */
#define GPIO_DOUTCLR31_0_DIO3_MASK               ((uint32_t)0x00000008U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO3 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO3_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO3_CLR                ((uint32_t)0x00000008U)         /* !< Clears DIO3 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO4] Bits */
#define GPIO_DOUTCLR31_0_DIO4_OFS                (4)                             /* !< DIO4 Offset */
#define GPIO_DOUTCLR31_0_DIO4_MASK               ((uint32_t)0x00000010U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO4 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO4_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO4_CLR                ((uint32_t)0x00000010U)         /* !< Clears DIO4 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO5] Bits */
#define GPIO_DOUTCLR31_0_DIO5_OFS                (5)                             /* !< DIO5 Offset */
#define GPIO_DOUTCLR31_0_DIO5_MASK               ((uint32_t)0x00000020U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO5 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO5_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO5_CLR                ((uint32_t)0x00000020U)         /* !< Clears DIO5 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO6] Bits */
#define GPIO_DOUTCLR31_0_DIO6_OFS                (6)                             /* !< DIO6 Offset */
#define GPIO_DOUTCLR31_0_DIO6_MASK               ((uint32_t)0x00000040U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO6 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO6_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO6_CLR                ((uint32_t)0x00000040U)         /* !< Clears DIO6 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO7] Bits */
#define GPIO_DOUTCLR31_0_DIO7_OFS                (7)                             /* !< DIO7 Offset */
#define GPIO_DOUTCLR31_0_DIO7_MASK               ((uint32_t)0x00000080U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO7 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO7_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO7_CLR                ((uint32_t)0x00000080U)         /* !< Clears DIO7 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO8] Bits */
#define GPIO_DOUTCLR31_0_DIO8_OFS                (8)                             /* !< DIO8 Offset */
#define GPIO_DOUTCLR31_0_DIO8_MASK               ((uint32_t)0x00000100U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO8 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO8_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO8_CLR                ((uint32_t)0x00000100U)         /* !< Clears DIO8 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO9] Bits */
#define GPIO_DOUTCLR31_0_DIO9_OFS                (9)                             /* !< DIO9 Offset */
#define GPIO_DOUTCLR31_0_DIO9_MASK               ((uint32_t)0x00000200U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO9 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO9_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO9_CLR                ((uint32_t)0x00000200U)         /* !< Clears DIO9 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO10] Bits */
#define GPIO_DOUTCLR31_0_DIO10_OFS               (10)                            /* !< DIO10 Offset */
#define GPIO_DOUTCLR31_0_DIO10_MASK              ((uint32_t)0x00000400U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO10 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO10_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO10_CLR               ((uint32_t)0x00000400U)         /* !< Clears DIO10 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO11] Bits */
#define GPIO_DOUTCLR31_0_DIO11_OFS               (11)                            /* !< DIO11 Offset */
#define GPIO_DOUTCLR31_0_DIO11_MASK              ((uint32_t)0x00000800U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO11 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO11_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO11_CLR               ((uint32_t)0x00000800U)         /* !< Clears DIO11 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO12] Bits */
#define GPIO_DOUTCLR31_0_DIO12_OFS               (12)                            /* !< DIO12 Offset */
#define GPIO_DOUTCLR31_0_DIO12_MASK              ((uint32_t)0x00001000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO12 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO12_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO12_CLR               ((uint32_t)0x00001000U)         /* !< Clears DIO12 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO13] Bits */
#define GPIO_DOUTCLR31_0_DIO13_OFS               (13)                            /* !< DIO13 Offset */
#define GPIO_DOUTCLR31_0_DIO13_MASK              ((uint32_t)0x00002000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO13 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO13_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO13_CLR               ((uint32_t)0x00002000U)         /* !< Clears DIO13 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO14] Bits */
#define GPIO_DOUTCLR31_0_DIO14_OFS               (14)                            /* !< DIO14 Offset */
#define GPIO_DOUTCLR31_0_DIO14_MASK              ((uint32_t)0x00004000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO14 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO14_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO14_CLR               ((uint32_t)0x00004000U)         /* !< Clears DIO14 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO15] Bits */
#define GPIO_DOUTCLR31_0_DIO15_OFS               (15)                            /* !< DIO15 Offset */
#define GPIO_DOUTCLR31_0_DIO15_MASK              ((uint32_t)0x00008000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO15 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO15_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO15_CLR               ((uint32_t)0x00008000U)         /* !< Clears DIO15 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO16] Bits */
#define GPIO_DOUTCLR31_0_DIO16_OFS               (16)                            /* !< DIO16 Offset */
#define GPIO_DOUTCLR31_0_DIO16_MASK              ((uint32_t)0x00010000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO16 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO16_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO16_CLR               ((uint32_t)0x00010000U)         /* !< Clears DIO16 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO17] Bits */
#define GPIO_DOUTCLR31_0_DIO17_OFS               (17)                            /* !< DIO17 Offset */
#define GPIO_DOUTCLR31_0_DIO17_MASK              ((uint32_t)0x00020000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO17 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO17_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO17_CLR               ((uint32_t)0x00020000U)         /* !< Clears DIO17 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO18] Bits */
#define GPIO_DOUTCLR31_0_DIO18_OFS               (18)                            /* !< DIO18 Offset */
#define GPIO_DOUTCLR31_0_DIO18_MASK              ((uint32_t)0x00040000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO18 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO18_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO18_CLR               ((uint32_t)0x00040000U)         /* !< Clears DIO18 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO19] Bits */
#define GPIO_DOUTCLR31_0_DIO19_OFS               (19)                            /* !< DIO19 Offset */
#define GPIO_DOUTCLR31_0_DIO19_MASK              ((uint32_t)0x00080000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO19 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO19_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO19_CLR               ((uint32_t)0x00080000U)         /* !< Clears DIO19 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO20] Bits */
#define GPIO_DOUTCLR31_0_DIO20_OFS               (20)                            /* !< DIO20 Offset */
#define GPIO_DOUTCLR31_0_DIO20_MASK              ((uint32_t)0x00100000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO20 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO20_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO20_CLR               ((uint32_t)0x00100000U)         /* !< Clears DIO20 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO21] Bits */
#define GPIO_DOUTCLR31_0_DIO21_OFS               (21)                            /* !< DIO21 Offset */
#define GPIO_DOUTCLR31_0_DIO21_MASK              ((uint32_t)0x00200000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO21 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO21_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO21_CLR               ((uint32_t)0x00200000U)         /* !< Clears DIO21 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO22] Bits */
#define GPIO_DOUTCLR31_0_DIO22_OFS               (22)                            /* !< DIO22 Offset */
#define GPIO_DOUTCLR31_0_DIO22_MASK              ((uint32_t)0x00400000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO22 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO22_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO22_CLR               ((uint32_t)0x00400000U)         /* !< Clears DIO22 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO23] Bits */
#define GPIO_DOUTCLR31_0_DIO23_OFS               (23)                            /* !< DIO23 Offset */
#define GPIO_DOUTCLR31_0_DIO23_MASK              ((uint32_t)0x00800000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO23 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO23_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO23_CLR               ((uint32_t)0x00800000U)         /* !< Clears DIO23 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO24] Bits */
#define GPIO_DOUTCLR31_0_DIO24_OFS               (24)                            /* !< DIO24 Offset */
#define GPIO_DOUTCLR31_0_DIO24_MASK              ((uint32_t)0x01000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO24 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO24_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO24_CLR               ((uint32_t)0x01000000U)         /* !< Clears DIO24 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO25] Bits */
#define GPIO_DOUTCLR31_0_DIO25_OFS               (25)                            /* !< DIO25 Offset */
#define GPIO_DOUTCLR31_0_DIO25_MASK              ((uint32_t)0x02000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO25 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO25_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO25_CLR               ((uint32_t)0x02000000U)         /* !< Clears DIO25 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO26] Bits */
#define GPIO_DOUTCLR31_0_DIO26_OFS               (26)                            /* !< DIO26 Offset */
#define GPIO_DOUTCLR31_0_DIO26_MASK              ((uint32_t)0x04000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO26 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO26_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO26_CLR               ((uint32_t)0x04000000U)         /* !< Clears DIO26 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO27] Bits */
#define GPIO_DOUTCLR31_0_DIO27_OFS               (27)                            /* !< DIO27 Offset */
#define GPIO_DOUTCLR31_0_DIO27_MASK              ((uint32_t)0x08000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO27 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO27_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO27_CLR               ((uint32_t)0x08000000U)         /* !< Clears DIO27 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO28] Bits */
#define GPIO_DOUTCLR31_0_DIO28_OFS               (28)                            /* !< DIO28 Offset */
#define GPIO_DOUTCLR31_0_DIO28_MASK              ((uint32_t)0x10000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO28 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO28_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO28_CLR               ((uint32_t)0x10000000U)         /* !< Clears DIO28 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO29] Bits */
#define GPIO_DOUTCLR31_0_DIO29_OFS               (29)                            /* !< DIO29 Offset */
#define GPIO_DOUTCLR31_0_DIO29_MASK              ((uint32_t)0x20000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO29 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO29_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO29_CLR               ((uint32_t)0x20000000U)         /* !< Clears DIO29 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO30] Bits */
#define GPIO_DOUTCLR31_0_DIO30_OFS               (30)                            /* !< DIO30 Offset */
#define GPIO_DOUTCLR31_0_DIO30_MASK              ((uint32_t)0x40000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO30 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO30_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO30_CLR               ((uint32_t)0x40000000U)         /* !< Clears DIO30 in DOUT31_0 */
/* GPIO_DOUTCLR31_0[DIO31] Bits */
#define GPIO_DOUTCLR31_0_DIO31_OFS               (31)                            /* !< DIO31 Offset */
#define GPIO_DOUTCLR31_0_DIO31_MASK              ((uint32_t)0x80000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO31 bit in the DOUT31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOUTCLR31_0_DIO31_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTCLR31_0_DIO31_CLR               ((uint32_t)0x80000000U)         /* !< Clears DIO31 in DOUT31_0 */

/* GPIO_DOUTTGL31_0 Bits */
/* GPIO_DOUTTGL31_0[DIO0] Bits */
#define GPIO_DOUTTGL31_0_DIO0_OFS                (0)                             /* !< DIO0 Offset */
#define GPIO_DOUTTGL31_0_DIO0_MASK               ((uint32_t)0x00000001U)         /* !< This bit is used to toggle DIO0
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO0_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO0_TOGGLE             ((uint32_t)0x00000001U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO1] Bits */
#define GPIO_DOUTTGL31_0_DIO1_OFS                (1)                             /* !< DIO1 Offset */
#define GPIO_DOUTTGL31_0_DIO1_MASK               ((uint32_t)0x00000002U)         /* !< This bit is used to toggle DIO1
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO1_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO1_TOGGLE             ((uint32_t)0x00000002U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO2] Bits */
#define GPIO_DOUTTGL31_0_DIO2_OFS                (2)                             /* !< DIO2 Offset */
#define GPIO_DOUTTGL31_0_DIO2_MASK               ((uint32_t)0x00000004U)         /* !< This bit is used to toggle DIO2
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO2_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO2_TOGGLE             ((uint32_t)0x00000004U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO3] Bits */
#define GPIO_DOUTTGL31_0_DIO3_OFS                (3)                             /* !< DIO3 Offset */
#define GPIO_DOUTTGL31_0_DIO3_MASK               ((uint32_t)0x00000008U)         /* !< This bit is used to toggle DIO3
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO3_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO3_TOGGLE             ((uint32_t)0x00000008U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO4] Bits */
#define GPIO_DOUTTGL31_0_DIO4_OFS                (4)                             /* !< DIO4 Offset */
#define GPIO_DOUTTGL31_0_DIO4_MASK               ((uint32_t)0x00000010U)         /* !< This bit is used to toggle DIO4
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO4_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO4_TOGGLE             ((uint32_t)0x00000010U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO5] Bits */
#define GPIO_DOUTTGL31_0_DIO5_OFS                (5)                             /* !< DIO5 Offset */
#define GPIO_DOUTTGL31_0_DIO5_MASK               ((uint32_t)0x00000020U)         /* !< This bit is used to toggle DIO5
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO5_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO5_TOGGLE             ((uint32_t)0x00000020U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO6] Bits */
#define GPIO_DOUTTGL31_0_DIO6_OFS                (6)                             /* !< DIO6 Offset */
#define GPIO_DOUTTGL31_0_DIO6_MASK               ((uint32_t)0x00000040U)         /* !< This bit is used to toggle DIO6
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO6_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO6_TOGGLE             ((uint32_t)0x00000040U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO7] Bits */
#define GPIO_DOUTTGL31_0_DIO7_OFS                (7)                             /* !< DIO7 Offset */
#define GPIO_DOUTTGL31_0_DIO7_MASK               ((uint32_t)0x00000080U)         /* !< This bit is used to toggle DIO7
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO7_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO7_TOGGLE             ((uint32_t)0x00000080U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO8] Bits */
#define GPIO_DOUTTGL31_0_DIO8_OFS                (8)                             /* !< DIO8 Offset */
#define GPIO_DOUTTGL31_0_DIO8_MASK               ((uint32_t)0x00000100U)         /* !< This bit is used to toggle DIO8
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO8_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO8_TOGGLE             ((uint32_t)0x00000100U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO9] Bits */
#define GPIO_DOUTTGL31_0_DIO9_OFS                (9)                             /* !< DIO9 Offset */
#define GPIO_DOUTTGL31_0_DIO9_MASK               ((uint32_t)0x00000200U)         /* !< This bit is used to toggle DIO9
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO9_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO9_TOGGLE             ((uint32_t)0x00000200U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO10] Bits */
#define GPIO_DOUTTGL31_0_DIO10_OFS               (10)                            /* !< DIO10 Offset */
#define GPIO_DOUTTGL31_0_DIO10_MASK              ((uint32_t)0x00000400U)         /* !< This bit is used to toggle DIO10
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO10_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO10_TOGGLE            ((uint32_t)0x00000400U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO11] Bits */
#define GPIO_DOUTTGL31_0_DIO11_OFS               (11)                            /* !< DIO11 Offset */
#define GPIO_DOUTTGL31_0_DIO11_MASK              ((uint32_t)0x00000800U)         /* !< This bit is used to toggle DIO11
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO11_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO11_TOGGLE            ((uint32_t)0x00000800U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO12] Bits */
#define GPIO_DOUTTGL31_0_DIO12_OFS               (12)                            /* !< DIO12 Offset */
#define GPIO_DOUTTGL31_0_DIO12_MASK              ((uint32_t)0x00001000U)         /* !< This bit is used to toggle DIO12
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO12_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO12_TOGGLE            ((uint32_t)0x00001000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO13] Bits */
#define GPIO_DOUTTGL31_0_DIO13_OFS               (13)                            /* !< DIO13 Offset */
#define GPIO_DOUTTGL31_0_DIO13_MASK              ((uint32_t)0x00002000U)         /* !< This bit is used to toggle DIO13
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO13_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO13_TOGGLE            ((uint32_t)0x00002000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO14] Bits */
#define GPIO_DOUTTGL31_0_DIO14_OFS               (14)                            /* !< DIO14 Offset */
#define GPIO_DOUTTGL31_0_DIO14_MASK              ((uint32_t)0x00004000U)         /* !< This bit is used to toggle DIO14
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO14_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO14_TOGGLE            ((uint32_t)0x00004000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO15] Bits */
#define GPIO_DOUTTGL31_0_DIO15_OFS               (15)                            /* !< DIO15 Offset */
#define GPIO_DOUTTGL31_0_DIO15_MASK              ((uint32_t)0x00008000U)         /* !< This bit is used to toggle DIO15
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO15_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO15_TOGGLE            ((uint32_t)0x00008000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO16] Bits */
#define GPIO_DOUTTGL31_0_DIO16_OFS               (16)                            /* !< DIO16 Offset */
#define GPIO_DOUTTGL31_0_DIO16_MASK              ((uint32_t)0x00010000U)         /* !< This bit is used to toggle DIO16
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO16_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO16_TOGGLE            ((uint32_t)0x00010000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO17] Bits */
#define GPIO_DOUTTGL31_0_DIO17_OFS               (17)                            /* !< DIO17 Offset */
#define GPIO_DOUTTGL31_0_DIO17_MASK              ((uint32_t)0x00020000U)         /* !< This bit is used to toggle DIO17
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO17_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO17_TOGGLE            ((uint32_t)0x00020000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO18] Bits */
#define GPIO_DOUTTGL31_0_DIO18_OFS               (18)                            /* !< DIO18 Offset */
#define GPIO_DOUTTGL31_0_DIO18_MASK              ((uint32_t)0x00040000U)         /* !< This bit is used to toggle DIO18
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO18_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO18_TOGGLE            ((uint32_t)0x00040000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO19] Bits */
#define GPIO_DOUTTGL31_0_DIO19_OFS               (19)                            /* !< DIO19 Offset */
#define GPIO_DOUTTGL31_0_DIO19_MASK              ((uint32_t)0x00080000U)         /* !< This bit is used to toggle DIO19
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO19_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO19_TOGGLE            ((uint32_t)0x00080000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO20] Bits */
#define GPIO_DOUTTGL31_0_DIO20_OFS               (20)                            /* !< DIO20 Offset */
#define GPIO_DOUTTGL31_0_DIO20_MASK              ((uint32_t)0x00100000U)         /* !< This bit is used to toggle DIO20
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO20_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO20_TOGGLE            ((uint32_t)0x00100000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO21] Bits */
#define GPIO_DOUTTGL31_0_DIO21_OFS               (21)                            /* !< DIO21 Offset */
#define GPIO_DOUTTGL31_0_DIO21_MASK              ((uint32_t)0x00200000U)         /* !< This bit is used to toggle DIO21
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO21_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO21_TOGGLE            ((uint32_t)0x00200000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO22] Bits */
#define GPIO_DOUTTGL31_0_DIO22_OFS               (22)                            /* !< DIO22 Offset */
#define GPIO_DOUTTGL31_0_DIO22_MASK              ((uint32_t)0x00400000U)         /* !< This bit is used to toggle DIO22
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO22_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO22_TOGGLE            ((uint32_t)0x00400000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO23] Bits */
#define GPIO_DOUTTGL31_0_DIO23_OFS               (23)                            /* !< DIO23 Offset */
#define GPIO_DOUTTGL31_0_DIO23_MASK              ((uint32_t)0x00800000U)         /* !< This bit is used to toggle DIO23
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO23_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO23_TOGGLE            ((uint32_t)0x00800000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO24] Bits */
#define GPIO_DOUTTGL31_0_DIO24_OFS               (24)                            /* !< DIO24 Offset */
#define GPIO_DOUTTGL31_0_DIO24_MASK              ((uint32_t)0x01000000U)         /* !< This bit is used to toggle DIO24
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO24_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO24_TOGGLE            ((uint32_t)0x01000000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO25] Bits */
#define GPIO_DOUTTGL31_0_DIO25_OFS               (25)                            /* !< DIO25 Offset */
#define GPIO_DOUTTGL31_0_DIO25_MASK              ((uint32_t)0x02000000U)         /* !< This bit is used to toggle DIO25
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO25_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO25_TOGGLE            ((uint32_t)0x02000000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO26] Bits */
#define GPIO_DOUTTGL31_0_DIO26_OFS               (26)                            /* !< DIO26 Offset */
#define GPIO_DOUTTGL31_0_DIO26_MASK              ((uint32_t)0x04000000U)         /* !< This bit is used to toggle DIO26
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO26_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO26_TOGGLE            ((uint32_t)0x04000000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO27] Bits */
#define GPIO_DOUTTGL31_0_DIO27_OFS               (27)                            /* !< DIO27 Offset */
#define GPIO_DOUTTGL31_0_DIO27_MASK              ((uint32_t)0x08000000U)         /* !< This bit is used to toggle DIO27
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO27_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO27_TOGGLE            ((uint32_t)0x08000000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO28] Bits */
#define GPIO_DOUTTGL31_0_DIO28_OFS               (28)                            /* !< DIO28 Offset */
#define GPIO_DOUTTGL31_0_DIO28_MASK              ((uint32_t)0x10000000U)         /* !< This bit is used to toggle DIO28
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO28_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO28_TOGGLE            ((uint32_t)0x10000000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO29] Bits */
#define GPIO_DOUTTGL31_0_DIO29_OFS               (29)                            /* !< DIO29 Offset */
#define GPIO_DOUTTGL31_0_DIO29_MASK              ((uint32_t)0x20000000U)         /* !< This bit is used to toggle DIO29
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO29_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO29_TOGGLE            ((uint32_t)0x20000000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO30] Bits */
#define GPIO_DOUTTGL31_0_DIO30_OFS               (30)                            /* !< DIO30 Offset */
#define GPIO_DOUTTGL31_0_DIO30_MASK              ((uint32_t)0x40000000U)         /* !< This bit is used to toggle DIO30
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO30_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO30_TOGGLE            ((uint32_t)0x40000000U)         /* !< Toggle output */
/* GPIO_DOUTTGL31_0[DIO31] Bits */
#define GPIO_DOUTTGL31_0_DIO31_OFS               (31)                            /* !< DIO31 Offset */
#define GPIO_DOUTTGL31_0_DIO31_MASK              ((uint32_t)0x80000000U)         /* !< This bit is used to toggle DIO31
                                                                                    output. */
#define GPIO_DOUTTGL31_0_DIO31_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOUTTGL31_0_DIO31_TOGGLE            ((uint32_t)0x80000000U)         /* !< Toggle output */

/* GPIO_DOE31_0 Bits */
/* GPIO_DOE31_0[DIO0] Bits */
#define GPIO_DOE31_0_DIO0_OFS                    (0)                             /* !< DIO0 Offset */
#define GPIO_DOE31_0_DIO0_MASK                   ((uint32_t)0x00000001U)         /* !< Enables data output for DIO0. */
#define GPIO_DOE31_0_DIO0_DISABLE                ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO0_ENABLE                 ((uint32_t)0x00000001U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO1] Bits */
#define GPIO_DOE31_0_DIO1_OFS                    (1)                             /* !< DIO1 Offset */
#define GPIO_DOE31_0_DIO1_MASK                   ((uint32_t)0x00000002U)         /* !< Enables data output for DIO1. */
#define GPIO_DOE31_0_DIO1_DISABLE                ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO1_ENABLE                 ((uint32_t)0x00000002U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO2] Bits */
#define GPIO_DOE31_0_DIO2_OFS                    (2)                             /* !< DIO2 Offset */
#define GPIO_DOE31_0_DIO2_MASK                   ((uint32_t)0x00000004U)         /* !< Enables data output for DIO2. */
#define GPIO_DOE31_0_DIO2_DISABLE                ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO2_ENABLE                 ((uint32_t)0x00000004U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO3] Bits */
#define GPIO_DOE31_0_DIO3_OFS                    (3)                             /* !< DIO3 Offset */
#define GPIO_DOE31_0_DIO3_MASK                   ((uint32_t)0x00000008U)         /* !< Enables data output for DIO3. */
#define GPIO_DOE31_0_DIO3_DISABLE                ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO3_ENABLE                 ((uint32_t)0x00000008U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO4] Bits */
#define GPIO_DOE31_0_DIO4_OFS                    (4)                             /* !< DIO4 Offset */
#define GPIO_DOE31_0_DIO4_MASK                   ((uint32_t)0x00000010U)         /* !< Enables data output for DIO4. */
#define GPIO_DOE31_0_DIO4_DISABLE                ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO4_ENABLE                 ((uint32_t)0x00000010U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO5] Bits */
#define GPIO_DOE31_0_DIO5_OFS                    (5)                             /* !< DIO5 Offset */
#define GPIO_DOE31_0_DIO5_MASK                   ((uint32_t)0x00000020U)         /* !< Enables data output for DIO5. */
#define GPIO_DOE31_0_DIO5_DISABLE                ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO5_ENABLE                 ((uint32_t)0x00000020U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO6] Bits */
#define GPIO_DOE31_0_DIO6_OFS                    (6)                             /* !< DIO6 Offset */
#define GPIO_DOE31_0_DIO6_MASK                   ((uint32_t)0x00000040U)         /* !< Enables data output for DIO6. */
#define GPIO_DOE31_0_DIO6_DISABLE                ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO6_ENABLE                 ((uint32_t)0x00000040U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO7] Bits */
#define GPIO_DOE31_0_DIO7_OFS                    (7)                             /* !< DIO7 Offset */
#define GPIO_DOE31_0_DIO7_MASK                   ((uint32_t)0x00000080U)         /* !< Enables data output for DIO7. */
#define GPIO_DOE31_0_DIO7_DISABLE                ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO7_ENABLE                 ((uint32_t)0x00000080U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO8] Bits */
#define GPIO_DOE31_0_DIO8_OFS                    (8)                             /* !< DIO8 Offset */
#define GPIO_DOE31_0_DIO8_MASK                   ((uint32_t)0x00000100U)         /* !< Enables data output for DIO8. */
#define GPIO_DOE31_0_DIO8_DISABLE                ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO8_ENABLE                 ((uint32_t)0x00000100U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO9] Bits */
#define GPIO_DOE31_0_DIO9_OFS                    (9)                             /* !< DIO9 Offset */
#define GPIO_DOE31_0_DIO9_MASK                   ((uint32_t)0x00000200U)         /* !< Enables data output for DIO9. */
#define GPIO_DOE31_0_DIO9_DISABLE                ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO9_ENABLE                 ((uint32_t)0x00000200U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO10] Bits */
#define GPIO_DOE31_0_DIO10_OFS                   (10)                            /* !< DIO10 Offset */
#define GPIO_DOE31_0_DIO10_MASK                  ((uint32_t)0x00000400U)         /* !< Enables data output for DIO10. */
#define GPIO_DOE31_0_DIO10_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO10_ENABLE                ((uint32_t)0x00000400U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO11] Bits */
#define GPIO_DOE31_0_DIO11_OFS                   (11)                            /* !< DIO11 Offset */
#define GPIO_DOE31_0_DIO11_MASK                  ((uint32_t)0x00000800U)         /* !< Enables data output for DIO11. */
#define GPIO_DOE31_0_DIO11_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO11_ENABLE                ((uint32_t)0x00000800U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO12] Bits */
#define GPIO_DOE31_0_DIO12_OFS                   (12)                            /* !< DIO12 Offset */
#define GPIO_DOE31_0_DIO12_MASK                  ((uint32_t)0x00001000U)         /* !< Enables data output for DIO12. */
#define GPIO_DOE31_0_DIO12_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO12_ENABLE                ((uint32_t)0x00001000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO13] Bits */
#define GPIO_DOE31_0_DIO13_OFS                   (13)                            /* !< DIO13 Offset */
#define GPIO_DOE31_0_DIO13_MASK                  ((uint32_t)0x00002000U)         /* !< Enables data output for DIO13. */
#define GPIO_DOE31_0_DIO13_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO13_ENABLE                ((uint32_t)0x00002000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO14] Bits */
#define GPIO_DOE31_0_DIO14_OFS                   (14)                            /* !< DIO14 Offset */
#define GPIO_DOE31_0_DIO14_MASK                  ((uint32_t)0x00004000U)         /* !< Enables data output for DIO14. */
#define GPIO_DOE31_0_DIO14_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO14_ENABLE                ((uint32_t)0x00004000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO15] Bits */
#define GPIO_DOE31_0_DIO15_OFS                   (15)                            /* !< DIO15 Offset */
#define GPIO_DOE31_0_DIO15_MASK                  ((uint32_t)0x00008000U)         /* !< Enables data output for DIO15. */
#define GPIO_DOE31_0_DIO15_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO15_ENABLE                ((uint32_t)0x00008000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO16] Bits */
#define GPIO_DOE31_0_DIO16_OFS                   (16)                            /* !< DIO16 Offset */
#define GPIO_DOE31_0_DIO16_MASK                  ((uint32_t)0x00010000U)         /* !< Enables data output for DIO16. */
#define GPIO_DOE31_0_DIO16_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO16_ENABLE                ((uint32_t)0x00010000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO17] Bits */
#define GPIO_DOE31_0_DIO17_OFS                   (17)                            /* !< DIO17 Offset */
#define GPIO_DOE31_0_DIO17_MASK                  ((uint32_t)0x00020000U)         /* !< Enables data output for DIO17. */
#define GPIO_DOE31_0_DIO17_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO17_ENABLE                ((uint32_t)0x00020000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO18] Bits */
#define GPIO_DOE31_0_DIO18_OFS                   (18)                            /* !< DIO18 Offset */
#define GPIO_DOE31_0_DIO18_MASK                  ((uint32_t)0x00040000U)         /* !< Enables data output for DIO18. */
#define GPIO_DOE31_0_DIO18_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO18_ENABLE                ((uint32_t)0x00040000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO19] Bits */
#define GPIO_DOE31_0_DIO19_OFS                   (19)                            /* !< DIO19 Offset */
#define GPIO_DOE31_0_DIO19_MASK                  ((uint32_t)0x00080000U)         /* !< Enables data output for DIO19. */
#define GPIO_DOE31_0_DIO19_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO19_ENABLE                ((uint32_t)0x00080000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO20] Bits */
#define GPIO_DOE31_0_DIO20_OFS                   (20)                            /* !< DIO20 Offset */
#define GPIO_DOE31_0_DIO20_MASK                  ((uint32_t)0x00100000U)         /* !< Enables data output for DIO20. */
#define GPIO_DOE31_0_DIO20_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO20_ENABLE                ((uint32_t)0x00100000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO21] Bits */
#define GPIO_DOE31_0_DIO21_OFS                   (21)                            /* !< DIO21 Offset */
#define GPIO_DOE31_0_DIO21_MASK                  ((uint32_t)0x00200000U)         /* !< Enables data output for DIO21. */
#define GPIO_DOE31_0_DIO21_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO21_ENABLE                ((uint32_t)0x00200000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO22] Bits */
#define GPIO_DOE31_0_DIO22_OFS                   (22)                            /* !< DIO22 Offset */
#define GPIO_DOE31_0_DIO22_MASK                  ((uint32_t)0x00400000U)         /* !< Enables data output for DIO22. */
#define GPIO_DOE31_0_DIO22_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO22_ENABLE                ((uint32_t)0x00400000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO23] Bits */
#define GPIO_DOE31_0_DIO23_OFS                   (23)                            /* !< DIO23 Offset */
#define GPIO_DOE31_0_DIO23_MASK                  ((uint32_t)0x00800000U)         /* !< Enables data output for DIO23. */
#define GPIO_DOE31_0_DIO23_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO23_ENABLE                ((uint32_t)0x00800000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO24] Bits */
#define GPIO_DOE31_0_DIO24_OFS                   (24)                            /* !< DIO24 Offset */
#define GPIO_DOE31_0_DIO24_MASK                  ((uint32_t)0x01000000U)         /* !< Enables data output for DIO24. */
#define GPIO_DOE31_0_DIO24_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO24_ENABLE                ((uint32_t)0x01000000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO25] Bits */
#define GPIO_DOE31_0_DIO25_OFS                   (25)                            /* !< DIO25 Offset */
#define GPIO_DOE31_0_DIO25_MASK                  ((uint32_t)0x02000000U)         /* !< Enables data output for DIO25. */
#define GPIO_DOE31_0_DIO25_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO25_ENABLE                ((uint32_t)0x02000000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO26] Bits */
#define GPIO_DOE31_0_DIO26_OFS                   (26)                            /* !< DIO26 Offset */
#define GPIO_DOE31_0_DIO26_MASK                  ((uint32_t)0x04000000U)         /* !< Enables data output for DIO26. */
#define GPIO_DOE31_0_DIO26_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO26_ENABLE                ((uint32_t)0x04000000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO27] Bits */
#define GPIO_DOE31_0_DIO27_OFS                   (27)                            /* !< DIO27 Offset */
#define GPIO_DOE31_0_DIO27_MASK                  ((uint32_t)0x08000000U)         /* !< Enables data output for DIO27. */
#define GPIO_DOE31_0_DIO27_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO27_ENABLE                ((uint32_t)0x08000000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO28] Bits */
#define GPIO_DOE31_0_DIO28_OFS                   (28)                            /* !< DIO28 Offset */
#define GPIO_DOE31_0_DIO28_MASK                  ((uint32_t)0x10000000U)         /* !< Enables data output for DIO28. */
#define GPIO_DOE31_0_DIO28_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO28_ENABLE                ((uint32_t)0x10000000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO29] Bits */
#define GPIO_DOE31_0_DIO29_OFS                   (29)                            /* !< DIO29 Offset */
#define GPIO_DOE31_0_DIO29_MASK                  ((uint32_t)0x20000000U)         /* !< Enables data output for DIO29. */
#define GPIO_DOE31_0_DIO29_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO29_ENABLE                ((uint32_t)0x20000000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO30] Bits */
#define GPIO_DOE31_0_DIO30_OFS                   (30)                            /* !< DIO30 Offset */
#define GPIO_DOE31_0_DIO30_MASK                  ((uint32_t)0x40000000U)         /* !< Enables data output for DIO30. */
#define GPIO_DOE31_0_DIO30_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO30_ENABLE                ((uint32_t)0x40000000U)         /* !< Output enabled */
/* GPIO_DOE31_0[DIO31] Bits */
#define GPIO_DOE31_0_DIO31_OFS                   (31)                            /* !< DIO31 Offset */
#define GPIO_DOE31_0_DIO31_MASK                  ((uint32_t)0x80000000U)         /* !< Enables data output for DIO31. */
#define GPIO_DOE31_0_DIO31_DISABLE               ((uint32_t)0x00000000U)         /* !< Output disabled */
#define GPIO_DOE31_0_DIO31_ENABLE                ((uint32_t)0x80000000U)         /* !< Output enabled */

/* GPIO_DOESET31_0 Bits */
/* GPIO_DOESET31_0[DIO0] Bits */
#define GPIO_DOESET31_0_DIO0_OFS                 (0)                             /* !< DIO0 Offset */
#define GPIO_DOESET31_0_DIO0_MASK                ((uint32_t)0x00000001U)         /* !< Writing 1 to this bit sets the DIO0
                                                                                    bit in the DOE31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOESET31_0_DIO0_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO0_SET                 ((uint32_t)0x00000001U)         /* !< Sets DIO0 in DOE31_0 */
/* GPIO_DOESET31_0[DIO1] Bits */
#define GPIO_DOESET31_0_DIO1_OFS                 (1)                             /* !< DIO1 Offset */
#define GPIO_DOESET31_0_DIO1_MASK                ((uint32_t)0x00000002U)         /* !< Writing 1 to this bit sets the DIO1
                                                                                    bit in the DOE31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOESET31_0_DIO1_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO1_SET                 ((uint32_t)0x00000002U)         /* !< Sets DIO1 in DOE31_0 */
/* GPIO_DOESET31_0[DIO2] Bits */
#define GPIO_DOESET31_0_DIO2_OFS                 (2)                             /* !< DIO2 Offset */
#define GPIO_DOESET31_0_DIO2_MASK                ((uint32_t)0x00000004U)         /* !< Writing 1 to this bit sets the DIO2
                                                                                    bit in the DOE31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOESET31_0_DIO2_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO2_SET                 ((uint32_t)0x00000004U)         /* !< Sets DIO2 in DOE31_0 */
/* GPIO_DOESET31_0[DIO3] Bits */
#define GPIO_DOESET31_0_DIO3_OFS                 (3)                             /* !< DIO3 Offset */
#define GPIO_DOESET31_0_DIO3_MASK                ((uint32_t)0x00000008U)         /* !< Writing 1 to this bit sets the DIO3
                                                                                    bit in the DOE31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOESET31_0_DIO3_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO3_SET                 ((uint32_t)0x00000008U)         /* !< Sets DIO3 in DOE31_0 */
/* GPIO_DOESET31_0[DIO4] Bits */
#define GPIO_DOESET31_0_DIO4_OFS                 (4)                             /* !< DIO4 Offset */
#define GPIO_DOESET31_0_DIO4_MASK                ((uint32_t)0x00000010U)         /* !< Writing 1 to this bit sets the DIO4
                                                                                    bit in the DOE31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOESET31_0_DIO4_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO4_SET                 ((uint32_t)0x00000010U)         /* !< Sets DIO4 in DOE31_0 */
/* GPIO_DOESET31_0[DIO5] Bits */
#define GPIO_DOESET31_0_DIO5_OFS                 (5)                             /* !< DIO5 Offset */
#define GPIO_DOESET31_0_DIO5_MASK                ((uint32_t)0x00000020U)         /* !< Writing 1 to this bit sets the DIO5
                                                                                    bit in the DOE31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOESET31_0_DIO5_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO5_SET                 ((uint32_t)0x00000020U)         /* !< Sets DIO5 in DOE31_0 */
/* GPIO_DOESET31_0[DIO6] Bits */
#define GPIO_DOESET31_0_DIO6_OFS                 (6)                             /* !< DIO6 Offset */
#define GPIO_DOESET31_0_DIO6_MASK                ((uint32_t)0x00000040U)         /* !< Writing 1 to this bit sets the DIO6
                                                                                    bit in the DOE31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOESET31_0_DIO6_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO6_SET                 ((uint32_t)0x00000040U)         /* !< Sets DIO6 in DOE31_0 */
/* GPIO_DOESET31_0[DIO7] Bits */
#define GPIO_DOESET31_0_DIO7_OFS                 (7)                             /* !< DIO7 Offset */
#define GPIO_DOESET31_0_DIO7_MASK                ((uint32_t)0x00000080U)         /* !< Writing 1 to this bit sets the DIO7
                                                                                    bit in the DOE31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOESET31_0_DIO7_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO7_SET                 ((uint32_t)0x00000080U)         /* !< Sets DIO7 in DOE31_0 */
/* GPIO_DOESET31_0[DIO8] Bits */
#define GPIO_DOESET31_0_DIO8_OFS                 (8)                             /* !< DIO8 Offset */
#define GPIO_DOESET31_0_DIO8_MASK                ((uint32_t)0x00000100U)         /* !< Writing 1 to this bit sets the DIO8
                                                                                    bit in the DOE31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOESET31_0_DIO8_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO8_SET                 ((uint32_t)0x00000100U)         /* !< Sets DIO8 in DOE31_0 */
/* GPIO_DOESET31_0[DIO9] Bits */
#define GPIO_DOESET31_0_DIO9_OFS                 (9)                             /* !< DIO9 Offset */
#define GPIO_DOESET31_0_DIO9_MASK                ((uint32_t)0x00000200U)         /* !< Writing 1 to this bit sets the DIO9
                                                                                    bit in the DOE31_0 register. Writing
                                                                                    0 has no effect. */
#define GPIO_DOESET31_0_DIO9_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO9_SET                 ((uint32_t)0x00000200U)         /* !< Sets DIO9 in DOE31_0 */
/* GPIO_DOESET31_0[DIO10] Bits */
#define GPIO_DOESET31_0_DIO10_OFS                (10)                            /* !< DIO10 Offset */
#define GPIO_DOESET31_0_DIO10_MASK               ((uint32_t)0x00000400U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO10 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO10_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO10_SET                ((uint32_t)0x00000400U)         /* !< Sets DIO10 in DOE31_0 */
/* GPIO_DOESET31_0[DIO11] Bits */
#define GPIO_DOESET31_0_DIO11_OFS                (11)                            /* !< DIO11 Offset */
#define GPIO_DOESET31_0_DIO11_MASK               ((uint32_t)0x00000800U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO11 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO11_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO11_SET                ((uint32_t)0x00000800U)         /* !< Sets DIO11 in DOE31_0 */
/* GPIO_DOESET31_0[DIO12] Bits */
#define GPIO_DOESET31_0_DIO12_OFS                (12)                            /* !< DIO12 Offset */
#define GPIO_DOESET31_0_DIO12_MASK               ((uint32_t)0x00001000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO12 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO12_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO12_SET                ((uint32_t)0x00001000U)         /* !< Sets DIO12 in DOE31_0 */
/* GPIO_DOESET31_0[DIO13] Bits */
#define GPIO_DOESET31_0_DIO13_OFS                (13)                            /* !< DIO13 Offset */
#define GPIO_DOESET31_0_DIO13_MASK               ((uint32_t)0x00002000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO13 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO13_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO13_SET                ((uint32_t)0x00002000U)         /* !< Sets DIO13 in DOE31_0 */
/* GPIO_DOESET31_0[DIO14] Bits */
#define GPIO_DOESET31_0_DIO14_OFS                (14)                            /* !< DIO14 Offset */
#define GPIO_DOESET31_0_DIO14_MASK               ((uint32_t)0x00004000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO14 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO14_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO14_SET                ((uint32_t)0x00004000U)         /* !< Sets DIO14 in DOE31_0 */
/* GPIO_DOESET31_0[DIO15] Bits */
#define GPIO_DOESET31_0_DIO15_OFS                (15)                            /* !< DIO15 Offset */
#define GPIO_DOESET31_0_DIO15_MASK               ((uint32_t)0x00008000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO15 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO15_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO15_SET                ((uint32_t)0x00008000U)         /* !< Sets DIO15 in DOE31_0 */
/* GPIO_DOESET31_0[DIO16] Bits */
#define GPIO_DOESET31_0_DIO16_OFS                (16)                            /* !< DIO16 Offset */
#define GPIO_DOESET31_0_DIO16_MASK               ((uint32_t)0x00010000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO16 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO16_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO16_SET                ((uint32_t)0x00010000U)         /* !< Sets DIO16 in DOE31_0 */
/* GPIO_DOESET31_0[DIO17] Bits */
#define GPIO_DOESET31_0_DIO17_OFS                (17)                            /* !< DIO17 Offset */
#define GPIO_DOESET31_0_DIO17_MASK               ((uint32_t)0x00020000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO17 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO17_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO17_SET                ((uint32_t)0x00020000U)         /* !< Sets DIO17 in DOE31_0 */
/* GPIO_DOESET31_0[DIO18] Bits */
#define GPIO_DOESET31_0_DIO18_OFS                (18)                            /* !< DIO18 Offset */
#define GPIO_DOESET31_0_DIO18_MASK               ((uint32_t)0x00040000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO18 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO18_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO18_SET                ((uint32_t)0x00040000U)         /* !< Sets DIO18 in DOE31_0 */
/* GPIO_DOESET31_0[DIO19] Bits */
#define GPIO_DOESET31_0_DIO19_OFS                (19)                            /* !< DIO19 Offset */
#define GPIO_DOESET31_0_DIO19_MASK               ((uint32_t)0x00080000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO19 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO19_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO19_SET                ((uint32_t)0x00080000U)         /* !< Sets DIO19 in DOE31_0 */
/* GPIO_DOESET31_0[DIO20] Bits */
#define GPIO_DOESET31_0_DIO20_OFS                (20)                            /* !< DIO20 Offset */
#define GPIO_DOESET31_0_DIO20_MASK               ((uint32_t)0x00100000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO20 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO20_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO20_SET                ((uint32_t)0x00100000U)         /* !< Sets DIO20 in DOE31_0 */
/* GPIO_DOESET31_0[DIO21] Bits */
#define GPIO_DOESET31_0_DIO21_OFS                (21)                            /* !< DIO21 Offset */
#define GPIO_DOESET31_0_DIO21_MASK               ((uint32_t)0x00200000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO21 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO21_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO21_SET                ((uint32_t)0x00200000U)         /* !< Sets DIO21 in DOE31_0 */
/* GPIO_DOESET31_0[DIO22] Bits */
#define GPIO_DOESET31_0_DIO22_OFS                (22)                            /* !< DIO22 Offset */
#define GPIO_DOESET31_0_DIO22_MASK               ((uint32_t)0x00400000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO22 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO22_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO22_SET                ((uint32_t)0x00400000U)         /* !< Sets DIO22 in DOE31_0 */
/* GPIO_DOESET31_0[DIO23] Bits */
#define GPIO_DOESET31_0_DIO23_OFS                (23)                            /* !< DIO23 Offset */
#define GPIO_DOESET31_0_DIO23_MASK               ((uint32_t)0x00800000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO23 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO23_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO23_SET                ((uint32_t)0x00800000U)         /* !< Sets DIO23 in DOE31_0 */
/* GPIO_DOESET31_0[DIO24] Bits */
#define GPIO_DOESET31_0_DIO24_OFS                (24)                            /* !< DIO24 Offset */
#define GPIO_DOESET31_0_DIO24_MASK               ((uint32_t)0x01000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO24 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO24_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO24_SET                ((uint32_t)0x01000000U)         /* !< Sets DIO24 in DOE31_0 */
/* GPIO_DOESET31_0[DIO25] Bits */
#define GPIO_DOESET31_0_DIO25_OFS                (25)                            /* !< DIO25 Offset */
#define GPIO_DOESET31_0_DIO25_MASK               ((uint32_t)0x02000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO25 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO25_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO25_SET                ((uint32_t)0x02000000U)         /* !< Sets DIO25 in DOE31_0 */
/* GPIO_DOESET31_0[DIO26] Bits */
#define GPIO_DOESET31_0_DIO26_OFS                (26)                            /* !< DIO26 Offset */
#define GPIO_DOESET31_0_DIO26_MASK               ((uint32_t)0x04000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO26 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO26_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO26_SET                ((uint32_t)0x04000000U)         /* !< Sets DIO26 in DOE31_0 */
/* GPIO_DOESET31_0[DIO27] Bits */
#define GPIO_DOESET31_0_DIO27_OFS                (27)                            /* !< DIO27 Offset */
#define GPIO_DOESET31_0_DIO27_MASK               ((uint32_t)0x08000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO27 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO27_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO27_SET                ((uint32_t)0x08000000U)         /* !< Sets DIO27 in DOE31_0 */
/* GPIO_DOESET31_0[DIO28] Bits */
#define GPIO_DOESET31_0_DIO28_OFS                (28)                            /* !< DIO28 Offset */
#define GPIO_DOESET31_0_DIO28_MASK               ((uint32_t)0x10000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO28 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO28_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO28_SET                ((uint32_t)0x10000000U)         /* !< Sets DIO28 in DOE31_0 */
/* GPIO_DOESET31_0[DIO29] Bits */
#define GPIO_DOESET31_0_DIO29_OFS                (29)                            /* !< DIO29 Offset */
#define GPIO_DOESET31_0_DIO29_MASK               ((uint32_t)0x20000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO29 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO29_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO29_SET                ((uint32_t)0x20000000U)         /* !< Sets DIO29 in DOE31_0 */
/* GPIO_DOESET31_0[DIO30] Bits */
#define GPIO_DOESET31_0_DIO30_OFS                (30)                            /* !< DIO30 Offset */
#define GPIO_DOESET31_0_DIO30_MASK               ((uint32_t)0x40000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO30 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO30_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO30_SET                ((uint32_t)0x40000000U)         /* !< Sets DIO30 in DOE31_0 */
/* GPIO_DOESET31_0[DIO31] Bits */
#define GPIO_DOESET31_0_DIO31_OFS                (31)                            /* !< DIO31 Offset */
#define GPIO_DOESET31_0_DIO31_MASK               ((uint32_t)0x80000000U)         /* !< Writing 1 to this bit sets the
                                                                                    DIO31 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOESET31_0_DIO31_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOESET31_0_DIO31_SET                ((uint32_t)0x80000000U)         /* !< Sets DIO31 in DOE31_0 */

/* GPIO_DOECLR31_0 Bits */
/* GPIO_DOECLR31_0[DIO0] Bits */
#define GPIO_DOECLR31_0_DIO0_OFS                 (0)                             /* !< DIO0 Offset */
#define GPIO_DOECLR31_0_DIO0_MASK                ((uint32_t)0x00000001U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO0 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO0_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO0_CLR                 ((uint32_t)0x00000001U)         /* !< Clears DIO0 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO1] Bits */
#define GPIO_DOECLR31_0_DIO1_OFS                 (1)                             /* !< DIO1 Offset */
#define GPIO_DOECLR31_0_DIO1_MASK                ((uint32_t)0x00000002U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO1 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO1_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO1_CLR                 ((uint32_t)0x00000002U)         /* !< Clears DIO1 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO2] Bits */
#define GPIO_DOECLR31_0_DIO2_OFS                 (2)                             /* !< DIO2 Offset */
#define GPIO_DOECLR31_0_DIO2_MASK                ((uint32_t)0x00000004U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO2 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO2_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO2_CLR                 ((uint32_t)0x00000004U)         /* !< Clears DIO2 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO3] Bits */
#define GPIO_DOECLR31_0_DIO3_OFS                 (3)                             /* !< DIO3 Offset */
#define GPIO_DOECLR31_0_DIO3_MASK                ((uint32_t)0x00000008U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO3 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO3_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO3_CLR                 ((uint32_t)0x00000008U)         /* !< Clears DIO3 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO4] Bits */
#define GPIO_DOECLR31_0_DIO4_OFS                 (4)                             /* !< DIO4 Offset */
#define GPIO_DOECLR31_0_DIO4_MASK                ((uint32_t)0x00000010U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO4 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO4_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO4_CLR                 ((uint32_t)0x00000010U)         /* !< Clears DIO4 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO5] Bits */
#define GPIO_DOECLR31_0_DIO5_OFS                 (5)                             /* !< DIO5 Offset */
#define GPIO_DOECLR31_0_DIO5_MASK                ((uint32_t)0x00000020U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO5 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO5_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO5_CLR                 ((uint32_t)0x00000020U)         /* !< Clears DIO5 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO6] Bits */
#define GPIO_DOECLR31_0_DIO6_OFS                 (6)                             /* !< DIO6 Offset */
#define GPIO_DOECLR31_0_DIO6_MASK                ((uint32_t)0x00000040U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO6 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO6_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO6_CLR                 ((uint32_t)0x00000040U)         /* !< Clears DIO6 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO7] Bits */
#define GPIO_DOECLR31_0_DIO7_OFS                 (7)                             /* !< DIO7 Offset */
#define GPIO_DOECLR31_0_DIO7_MASK                ((uint32_t)0x00000080U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO7 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO7_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO7_CLR                 ((uint32_t)0x00000080U)         /* !< Clears DIO7 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO8] Bits */
#define GPIO_DOECLR31_0_DIO8_OFS                 (8)                             /* !< DIO8 Offset */
#define GPIO_DOECLR31_0_DIO8_MASK                ((uint32_t)0x00000100U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO8 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO8_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO8_CLR                 ((uint32_t)0x00000100U)         /* !< Clears DIO8 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO9] Bits */
#define GPIO_DOECLR31_0_DIO9_OFS                 (9)                             /* !< DIO9 Offset */
#define GPIO_DOECLR31_0_DIO9_MASK                ((uint32_t)0x00000200U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO9 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO9_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO9_CLR                 ((uint32_t)0x00000200U)         /* !< Clears DIO9 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO10] Bits */
#define GPIO_DOECLR31_0_DIO10_OFS                (10)                            /* !< DIO10 Offset */
#define GPIO_DOECLR31_0_DIO10_MASK               ((uint32_t)0x00000400U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO10 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO10_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO10_CLR                ((uint32_t)0x00000400U)         /* !< Clears DIO10 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO11] Bits */
#define GPIO_DOECLR31_0_DIO11_OFS                (11)                            /* !< DIO11 Offset */
#define GPIO_DOECLR31_0_DIO11_MASK               ((uint32_t)0x00000800U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO11 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO11_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO11_CLR                ((uint32_t)0x00000800U)         /* !< Clears DIO11 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO12] Bits */
#define GPIO_DOECLR31_0_DIO12_OFS                (12)                            /* !< DIO12 Offset */
#define GPIO_DOECLR31_0_DIO12_MASK               ((uint32_t)0x00001000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO12 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO12_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO12_CLR                ((uint32_t)0x00001000U)         /* !< Clears DIO12 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO13] Bits */
#define GPIO_DOECLR31_0_DIO13_OFS                (13)                            /* !< DIO13 Offset */
#define GPIO_DOECLR31_0_DIO13_MASK               ((uint32_t)0x00002000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO13 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO13_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO13_CLR                ((uint32_t)0x00002000U)         /* !< Clears DIO13 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO14] Bits */
#define GPIO_DOECLR31_0_DIO14_OFS                (14)                            /* !< DIO14 Offset */
#define GPIO_DOECLR31_0_DIO14_MASK               ((uint32_t)0x00004000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO14 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO14_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO14_CLR                ((uint32_t)0x00004000U)         /* !< Clears DIO14 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO15] Bits */
#define GPIO_DOECLR31_0_DIO15_OFS                (15)                            /* !< DIO15 Offset */
#define GPIO_DOECLR31_0_DIO15_MASK               ((uint32_t)0x00008000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO15 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO15_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO15_CLR                ((uint32_t)0x00008000U)         /* !< Clears DIO15 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO16] Bits */
#define GPIO_DOECLR31_0_DIO16_OFS                (16)                            /* !< DIO16 Offset */
#define GPIO_DOECLR31_0_DIO16_MASK               ((uint32_t)0x00010000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO16 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO16_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO16_CLR                ((uint32_t)0x00010000U)         /* !< Clears DIO16 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO17] Bits */
#define GPIO_DOECLR31_0_DIO17_OFS                (17)                            /* !< DIO17 Offset */
#define GPIO_DOECLR31_0_DIO17_MASK               ((uint32_t)0x00020000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO17 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO17_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO17_CLR                ((uint32_t)0x00020000U)         /* !< Clears DIO17 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO18] Bits */
#define GPIO_DOECLR31_0_DIO18_OFS                (18)                            /* !< DIO18 Offset */
#define GPIO_DOECLR31_0_DIO18_MASK               ((uint32_t)0x00040000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO18 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO18_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO18_CLR                ((uint32_t)0x00040000U)         /* !< Clears DIO18 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO19] Bits */
#define GPIO_DOECLR31_0_DIO19_OFS                (19)                            /* !< DIO19 Offset */
#define GPIO_DOECLR31_0_DIO19_MASK               ((uint32_t)0x00080000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO19 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO19_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO19_CLR                ((uint32_t)0x00080000U)         /* !< Clears DIO19 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO20] Bits */
#define GPIO_DOECLR31_0_DIO20_OFS                (20)                            /* !< DIO20 Offset */
#define GPIO_DOECLR31_0_DIO20_MASK               ((uint32_t)0x00100000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO20 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO20_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO20_CLR                ((uint32_t)0x00100000U)         /* !< Clears DIO20 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO21] Bits */
#define GPIO_DOECLR31_0_DIO21_OFS                (21)                            /* !< DIO21 Offset */
#define GPIO_DOECLR31_0_DIO21_MASK               ((uint32_t)0x00200000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO21 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO21_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO21_CLR                ((uint32_t)0x00200000U)         /* !< Clears DIO21 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO22] Bits */
#define GPIO_DOECLR31_0_DIO22_OFS                (22)                            /* !< DIO22 Offset */
#define GPIO_DOECLR31_0_DIO22_MASK               ((uint32_t)0x00400000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO22 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO22_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO22_CLR                ((uint32_t)0x00400000U)         /* !< Clears DIO22 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO23] Bits */
#define GPIO_DOECLR31_0_DIO23_OFS                (23)                            /* !< DIO23 Offset */
#define GPIO_DOECLR31_0_DIO23_MASK               ((uint32_t)0x00800000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO23 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO23_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO23_CLR                ((uint32_t)0x00800000U)         /* !< Clears DIO23 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO24] Bits */
#define GPIO_DOECLR31_0_DIO24_OFS                (24)                            /* !< DIO24 Offset */
#define GPIO_DOECLR31_0_DIO24_MASK               ((uint32_t)0x01000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO24 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO24_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO24_CLR                ((uint32_t)0x01000000U)         /* !< Clears DIO24 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO25] Bits */
#define GPIO_DOECLR31_0_DIO25_OFS                (25)                            /* !< DIO25 Offset */
#define GPIO_DOECLR31_0_DIO25_MASK               ((uint32_t)0x02000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO25 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO25_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO25_CLR                ((uint32_t)0x02000000U)         /* !< Clears DIO25 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO26] Bits */
#define GPIO_DOECLR31_0_DIO26_OFS                (26)                            /* !< DIO26 Offset */
#define GPIO_DOECLR31_0_DIO26_MASK               ((uint32_t)0x04000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO26 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO26_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO26_CLR                ((uint32_t)0x04000000U)         /* !< Clears DIO26 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO27] Bits */
#define GPIO_DOECLR31_0_DIO27_OFS                (27)                            /* !< DIO27 Offset */
#define GPIO_DOECLR31_0_DIO27_MASK               ((uint32_t)0x08000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO27 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO27_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO27_CLR                ((uint32_t)0x08000000U)         /* !< Clears DIO27 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO28] Bits */
#define GPIO_DOECLR31_0_DIO28_OFS                (28)                            /* !< DIO28 Offset */
#define GPIO_DOECLR31_0_DIO28_MASK               ((uint32_t)0x10000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO28 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO28_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO28_CLR                ((uint32_t)0x10000000U)         /* !< Clears DIO28 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO29] Bits */
#define GPIO_DOECLR31_0_DIO29_OFS                (29)                            /* !< DIO29 Offset */
#define GPIO_DOECLR31_0_DIO29_MASK               ((uint32_t)0x20000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO29 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO29_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO29_CLR                ((uint32_t)0x20000000U)         /* !< Clears DIO29 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO30] Bits */
#define GPIO_DOECLR31_0_DIO30_OFS                (30)                            /* !< DIO30 Offset */
#define GPIO_DOECLR31_0_DIO30_MASK               ((uint32_t)0x40000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO30 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO30_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO30_CLR                ((uint32_t)0x40000000U)         /* !< Clears DIO30 in DOE31_0 */
/* GPIO_DOECLR31_0[DIO31] Bits */
#define GPIO_DOECLR31_0_DIO31_OFS                (31)                            /* !< DIO31 Offset */
#define GPIO_DOECLR31_0_DIO31_MASK               ((uint32_t)0x80000000U)         /* !< Writing 1 to this bit clears the
                                                                                    DIO31 bit in the DOE31_0 register.
                                                                                    Writing 0 has no effect. */
#define GPIO_DOECLR31_0_DIO31_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< No effect */
#define GPIO_DOECLR31_0_DIO31_CLR                ((uint32_t)0x80000000U)         /* !< Clears DIO31 in DOE31_0 */

/* GPIO_DIN3_0 Bits */
/* GPIO_DIN3_0[DIO0] Bits */
#define GPIO_DIN3_0_DIO0_OFS                     (0)                             /* !< DIO0 Offset */
#define GPIO_DIN3_0_DIO0_MASK                    ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of DIO0. */
#define GPIO_DIN3_0_DIO0_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN3_0_DIO0_ONE                     ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* GPIO_DIN3_0[DIO1] Bits */
#define GPIO_DIN3_0_DIO1_OFS                     (8)                             /* !< DIO1 Offset */
#define GPIO_DIN3_0_DIO1_MASK                    ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of DIO1. */
#define GPIO_DIN3_0_DIO1_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN3_0_DIO1_ONE                     ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* GPIO_DIN3_0[DIO2] Bits */
#define GPIO_DIN3_0_DIO2_OFS                     (16)                            /* !< DIO2 Offset */
#define GPIO_DIN3_0_DIO2_MASK                    ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of DIO2. */
#define GPIO_DIN3_0_DIO2_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN3_0_DIO2_ONE                     ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* GPIO_DIN3_0[DIO3] Bits */
#define GPIO_DIN3_0_DIO3_OFS                     (24)                            /* !< DIO3 Offset */
#define GPIO_DIN3_0_DIO3_MASK                    ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of DIO3. */
#define GPIO_DIN3_0_DIO3_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN3_0_DIO3_ONE                     ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* GPIO_DIN7_4 Bits */
/* GPIO_DIN7_4[DIO4] Bits */
#define GPIO_DIN7_4_DIO4_OFS                     (0)                             /* !< DIO4 Offset */
#define GPIO_DIN7_4_DIO4_MASK                    ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of DIO4. */
#define GPIO_DIN7_4_DIO4_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN7_4_DIO4_ONE                     ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* GPIO_DIN7_4[DIO5] Bits */
#define GPIO_DIN7_4_DIO5_OFS                     (8)                             /* !< DIO5 Offset */
#define GPIO_DIN7_4_DIO5_MASK                    ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of DIO5. */
#define GPIO_DIN7_4_DIO5_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN7_4_DIO5_ONE                     ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* GPIO_DIN7_4[DIO6] Bits */
#define GPIO_DIN7_4_DIO6_OFS                     (16)                            /* !< DIO6 Offset */
#define GPIO_DIN7_4_DIO6_MASK                    ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of DIO6. */
#define GPIO_DIN7_4_DIO6_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN7_4_DIO6_ONE                     ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* GPIO_DIN7_4[DIO7] Bits */
#define GPIO_DIN7_4_DIO7_OFS                     (24)                            /* !< DIO7 Offset */
#define GPIO_DIN7_4_DIO7_MASK                    ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of DIO7. */
#define GPIO_DIN7_4_DIO7_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN7_4_DIO7_ONE                     ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* GPIO_DIN11_8 Bits */
/* GPIO_DIN11_8[DIO8] Bits */
#define GPIO_DIN11_8_DIO8_OFS                    (0)                             /* !< DIO8 Offset */
#define GPIO_DIN11_8_DIO8_MASK                   ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of DIO8. */
#define GPIO_DIN11_8_DIO8_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN11_8_DIO8_ONE                    ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* GPIO_DIN11_8[DIO9] Bits */
#define GPIO_DIN11_8_DIO9_OFS                    (8)                             /* !< DIO9 Offset */
#define GPIO_DIN11_8_DIO9_MASK                   ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of DIO9. */
#define GPIO_DIN11_8_DIO9_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN11_8_DIO9_ONE                    ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* GPIO_DIN11_8[DIO10] Bits */
#define GPIO_DIN11_8_DIO10_OFS                   (16)                            /* !< DIO10 Offset */
#define GPIO_DIN11_8_DIO10_MASK                  ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of DIO10. */
#define GPIO_DIN11_8_DIO10_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN11_8_DIO10_ONE                   ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* GPIO_DIN11_8[DIO11] Bits */
#define GPIO_DIN11_8_DIO11_OFS                   (24)                            /* !< DIO11 Offset */
#define GPIO_DIN11_8_DIO11_MASK                  ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of DIO11. */
#define GPIO_DIN11_8_DIO11_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN11_8_DIO11_ONE                   ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* GPIO_DIN15_12 Bits */
/* GPIO_DIN15_12[DIO12] Bits */
#define GPIO_DIN15_12_DIO12_OFS                  (0)                             /* !< DIO12 Offset */
#define GPIO_DIN15_12_DIO12_MASK                 ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of DIO12. */
#define GPIO_DIN15_12_DIO12_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN15_12_DIO12_ONE                  ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* GPIO_DIN15_12[DIO13] Bits */
#define GPIO_DIN15_12_DIO13_OFS                  (8)                             /* !< DIO13 Offset */
#define GPIO_DIN15_12_DIO13_MASK                 ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of DIO13. */
#define GPIO_DIN15_12_DIO13_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN15_12_DIO13_ONE                  ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* GPIO_DIN15_12[DIO14] Bits */
#define GPIO_DIN15_12_DIO14_OFS                  (16)                            /* !< DIO14 Offset */
#define GPIO_DIN15_12_DIO14_MASK                 ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of DIO14. */
#define GPIO_DIN15_12_DIO14_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN15_12_DIO14_ONE                  ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* GPIO_DIN15_12[DIO15] Bits */
#define GPIO_DIN15_12_DIO15_OFS                  (24)                            /* !< DIO15 Offset */
#define GPIO_DIN15_12_DIO15_MASK                 ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of DIO15. */
#define GPIO_DIN15_12_DIO15_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN15_12_DIO15_ONE                  ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* GPIO_DIN19_16 Bits */
/* GPIO_DIN19_16[DIO16] Bits */
#define GPIO_DIN19_16_DIO16_OFS                  (0)                             /* !< DIO16 Offset */
#define GPIO_DIN19_16_DIO16_MASK                 ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of DIO16. */
#define GPIO_DIN19_16_DIO16_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN19_16_DIO16_ONE                  ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* GPIO_DIN19_16[DIO17] Bits */
#define GPIO_DIN19_16_DIO17_OFS                  (8)                             /* !< DIO17 Offset */
#define GPIO_DIN19_16_DIO17_MASK                 ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of DIO17. */
#define GPIO_DIN19_16_DIO17_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN19_16_DIO17_ONE                  ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* GPIO_DIN19_16[DIO18] Bits */
#define GPIO_DIN19_16_DIO18_OFS                  (16)                            /* !< DIO18 Offset */
#define GPIO_DIN19_16_DIO18_MASK                 ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of DIO18. */
#define GPIO_DIN19_16_DIO18_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN19_16_DIO18_ONE                  ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* GPIO_DIN19_16[DIO19] Bits */
#define GPIO_DIN19_16_DIO19_OFS                  (24)                            /* !< DIO19 Offset */
#define GPIO_DIN19_16_DIO19_MASK                 ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of DIO19. */
#define GPIO_DIN19_16_DIO19_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN19_16_DIO19_ONE                  ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* GPIO_DIN23_20 Bits */
/* GPIO_DIN23_20[DIO20] Bits */
#define GPIO_DIN23_20_DIO20_OFS                  (0)                             /* !< DIO20 Offset */
#define GPIO_DIN23_20_DIO20_MASK                 ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of DIO20. */
#define GPIO_DIN23_20_DIO20_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN23_20_DIO20_ONE                  ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* GPIO_DIN23_20[DIO21] Bits */
#define GPIO_DIN23_20_DIO21_OFS                  (8)                             /* !< DIO21 Offset */
#define GPIO_DIN23_20_DIO21_MASK                 ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of DIO21. */
#define GPIO_DIN23_20_DIO21_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN23_20_DIO21_ONE                  ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* GPIO_DIN23_20[DIO22] Bits */
#define GPIO_DIN23_20_DIO22_OFS                  (16)                            /* !< DIO22 Offset */
#define GPIO_DIN23_20_DIO22_MASK                 ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of DIO22. */
#define GPIO_DIN23_20_DIO22_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN23_20_DIO22_ONE                  ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* GPIO_DIN23_20[DIO23] Bits */
#define GPIO_DIN23_20_DIO23_OFS                  (24)                            /* !< DIO23 Offset */
#define GPIO_DIN23_20_DIO23_MASK                 ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of DIO23. */
#define GPIO_DIN23_20_DIO23_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN23_20_DIO23_ONE                  ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* GPIO_DIN27_24 Bits */
/* GPIO_DIN27_24[DIO24] Bits */
#define GPIO_DIN27_24_DIO24_OFS                  (0)                             /* !< DIO24 Offset */
#define GPIO_DIN27_24_DIO24_MASK                 ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of DIO24. */
#define GPIO_DIN27_24_DIO24_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN27_24_DIO24_ONE                  ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* GPIO_DIN27_24[DIO25] Bits */
#define GPIO_DIN27_24_DIO25_OFS                  (8)                             /* !< DIO25 Offset */
#define GPIO_DIN27_24_DIO25_MASK                 ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of DIO25. */
#define GPIO_DIN27_24_DIO25_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN27_24_DIO25_ONE                  ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* GPIO_DIN27_24[DIO26] Bits */
#define GPIO_DIN27_24_DIO26_OFS                  (16)                            /* !< DIO26 Offset */
#define GPIO_DIN27_24_DIO26_MASK                 ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of DIO26. */
#define GPIO_DIN27_24_DIO26_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN27_24_DIO26_ONE                  ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* GPIO_DIN27_24[DIO27] Bits */
#define GPIO_DIN27_24_DIO27_OFS                  (24)                            /* !< DIO27 Offset */
#define GPIO_DIN27_24_DIO27_MASK                 ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of DIO27. */
#define GPIO_DIN27_24_DIO27_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN27_24_DIO27_ONE                  ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* GPIO_DIN31_28 Bits */
/* GPIO_DIN31_28[DIO28] Bits */
#define GPIO_DIN31_28_DIO28_OFS                  (0)                             /* !< DIO28 Offset */
#define GPIO_DIN31_28_DIO28_MASK                 ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of DIO28. */
#define GPIO_DIN31_28_DIO28_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_28_DIO28_ONE                  ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* GPIO_DIN31_28[DIO29] Bits */
#define GPIO_DIN31_28_DIO29_OFS                  (8)                             /* !< DIO29 Offset */
#define GPIO_DIN31_28_DIO29_MASK                 ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of DIO29. */
#define GPIO_DIN31_28_DIO29_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_28_DIO29_ONE                  ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* GPIO_DIN31_28[DIO30] Bits */
#define GPIO_DIN31_28_DIO30_OFS                  (16)                            /* !< DIO30 Offset */
#define GPIO_DIN31_28_DIO30_MASK                 ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of DIO30. */
#define GPIO_DIN31_28_DIO30_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_28_DIO30_ONE                  ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* GPIO_DIN31_28[DIO31] Bits */
#define GPIO_DIN31_28_DIO31_OFS                  (24)                            /* !< DIO31 Offset */
#define GPIO_DIN31_28_DIO31_MASK                 ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of DIO31. */
#define GPIO_DIN31_28_DIO31_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_28_DIO31_ONE                  ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* GPIO_DIN31_0 Bits */
/* GPIO_DIN31_0[DIO0] Bits */
#define GPIO_DIN31_0_DIO0_OFS                    (0)                             /* !< DIO0 Offset */
#define GPIO_DIN31_0_DIO0_MASK                   ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of DIO0. */
#define GPIO_DIN31_0_DIO0_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO0_ONE                    ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO1] Bits */
#define GPIO_DIN31_0_DIO1_OFS                    (1)                             /* !< DIO1 Offset */
#define GPIO_DIN31_0_DIO1_MASK                   ((uint32_t)0x00000002U)         /* !< This bit reads the data input value
                                                                                    of DIO1. */
#define GPIO_DIN31_0_DIO1_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO1_ONE                    ((uint32_t)0x00000002U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO2] Bits */
#define GPIO_DIN31_0_DIO2_OFS                    (2)                             /* !< DIO2 Offset */
#define GPIO_DIN31_0_DIO2_MASK                   ((uint32_t)0x00000004U)         /* !< This bit reads the data input value
                                                                                    of DIO2. */
#define GPIO_DIN31_0_DIO2_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO2_ONE                    ((uint32_t)0x00000004U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO3] Bits */
#define GPIO_DIN31_0_DIO3_OFS                    (3)                             /* !< DIO3 Offset */
#define GPIO_DIN31_0_DIO3_MASK                   ((uint32_t)0x00000008U)         /* !< This bit reads the data input value
                                                                                    of DIO3. */
#define GPIO_DIN31_0_DIO3_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO3_ONE                    ((uint32_t)0x00000008U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO4] Bits */
#define GPIO_DIN31_0_DIO4_OFS                    (4)                             /* !< DIO4 Offset */
#define GPIO_DIN31_0_DIO4_MASK                   ((uint32_t)0x00000010U)         /* !< This bit reads the data input value
                                                                                    of DIO4. */
#define GPIO_DIN31_0_DIO4_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO4_ONE                    ((uint32_t)0x00000010U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO5] Bits */
#define GPIO_DIN31_0_DIO5_OFS                    (5)                             /* !< DIO5 Offset */
#define GPIO_DIN31_0_DIO5_MASK                   ((uint32_t)0x00000020U)         /* !< This bit reads the data input value
                                                                                    of DIO5. */
#define GPIO_DIN31_0_DIO5_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO5_ONE                    ((uint32_t)0x00000020U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO6] Bits */
#define GPIO_DIN31_0_DIO6_OFS                    (6)                             /* !< DIO6 Offset */
#define GPIO_DIN31_0_DIO6_MASK                   ((uint32_t)0x00000040U)         /* !< This bit reads the data input value
                                                                                    of DIO6. */
#define GPIO_DIN31_0_DIO6_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO6_ONE                    ((uint32_t)0x00000040U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO7] Bits */
#define GPIO_DIN31_0_DIO7_OFS                    (7)                             /* !< DIO7 Offset */
#define GPIO_DIN31_0_DIO7_MASK                   ((uint32_t)0x00000080U)         /* !< This bit reads the data input value
                                                                                    of DIO7. */
#define GPIO_DIN31_0_DIO7_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO7_ONE                    ((uint32_t)0x00000080U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO8] Bits */
#define GPIO_DIN31_0_DIO8_OFS                    (8)                             /* !< DIO8 Offset */
#define GPIO_DIN31_0_DIO8_MASK                   ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of DIO8. */
#define GPIO_DIN31_0_DIO8_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO8_ONE                    ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO9] Bits */
#define GPIO_DIN31_0_DIO9_OFS                    (9)                             /* !< DIO9 Offset */
#define GPIO_DIN31_0_DIO9_MASK                   ((uint32_t)0x00000200U)         /* !< This bit reads the data input value
                                                                                    of DIO9. */
#define GPIO_DIN31_0_DIO9_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO9_ONE                    ((uint32_t)0x00000200U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO10] Bits */
#define GPIO_DIN31_0_DIO10_OFS                   (10)                            /* !< DIO10 Offset */
#define GPIO_DIN31_0_DIO10_MASK                  ((uint32_t)0x00000400U)         /* !< This bit reads the data input value
                                                                                    of DIO10. */
#define GPIO_DIN31_0_DIO10_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO10_ONE                   ((uint32_t)0x00000400U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO11] Bits */
#define GPIO_DIN31_0_DIO11_OFS                   (11)                            /* !< DIO11 Offset */
#define GPIO_DIN31_0_DIO11_MASK                  ((uint32_t)0x00000800U)         /* !< This bit reads the data input value
                                                                                    of DIO11. */
#define GPIO_DIN31_0_DIO11_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO11_ONE                   ((uint32_t)0x00000800U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO12] Bits */
#define GPIO_DIN31_0_DIO12_OFS                   (12)                            /* !< DIO12 Offset */
#define GPIO_DIN31_0_DIO12_MASK                  ((uint32_t)0x00001000U)         /* !< This bit reads the data input value
                                                                                    of DIO12. */
#define GPIO_DIN31_0_DIO12_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO12_ONE                   ((uint32_t)0x00001000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO13] Bits */
#define GPIO_DIN31_0_DIO13_OFS                   (13)                            /* !< DIO13 Offset */
#define GPIO_DIN31_0_DIO13_MASK                  ((uint32_t)0x00002000U)         /* !< This bit reads the data input value
                                                                                    of DIO13. */
#define GPIO_DIN31_0_DIO13_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO13_ONE                   ((uint32_t)0x00002000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO14] Bits */
#define GPIO_DIN31_0_DIO14_OFS                   (14)                            /* !< DIO14 Offset */
#define GPIO_DIN31_0_DIO14_MASK                  ((uint32_t)0x00004000U)         /* !< This bit reads the data input value
                                                                                    of DIO14. */
#define GPIO_DIN31_0_DIO14_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO14_ONE                   ((uint32_t)0x00004000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO15] Bits */
#define GPIO_DIN31_0_DIO15_OFS                   (15)                            /* !< DIO15 Offset */
#define GPIO_DIN31_0_DIO15_MASK                  ((uint32_t)0x00008000U)         /* !< This bit reads the data input value
                                                                                    of DIO15. */
#define GPIO_DIN31_0_DIO15_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO15_ONE                   ((uint32_t)0x00008000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO16] Bits */
#define GPIO_DIN31_0_DIO16_OFS                   (16)                            /* !< DIO16 Offset */
#define GPIO_DIN31_0_DIO16_MASK                  ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of DIO16. */
#define GPIO_DIN31_0_DIO16_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO16_ONE                   ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO17] Bits */
#define GPIO_DIN31_0_DIO17_OFS                   (17)                            /* !< DIO17 Offset */
#define GPIO_DIN31_0_DIO17_MASK                  ((uint32_t)0x00020000U)         /* !< This bit reads the data input value
                                                                                    of DIO17. */
#define GPIO_DIN31_0_DIO17_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO17_ONE                   ((uint32_t)0x00020000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO18] Bits */
#define GPIO_DIN31_0_DIO18_OFS                   (18)                            /* !< DIO18 Offset */
#define GPIO_DIN31_0_DIO18_MASK                  ((uint32_t)0x00040000U)         /* !< This bit reads the data input value
                                                                                    of DIO18. */
#define GPIO_DIN31_0_DIO18_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO18_ONE                   ((uint32_t)0x00040000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO19] Bits */
#define GPIO_DIN31_0_DIO19_OFS                   (19)                            /* !< DIO19 Offset */
#define GPIO_DIN31_0_DIO19_MASK                  ((uint32_t)0x00080000U)         /* !< This bit reads the data input value
                                                                                    of DIO19. */
#define GPIO_DIN31_0_DIO19_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO19_ONE                   ((uint32_t)0x00080000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO20] Bits */
#define GPIO_DIN31_0_DIO20_OFS                   (20)                            /* !< DIO20 Offset */
#define GPIO_DIN31_0_DIO20_MASK                  ((uint32_t)0x00100000U)         /* !< This bit reads the data input value
                                                                                    of DIO20. */
#define GPIO_DIN31_0_DIO20_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO20_ONE                   ((uint32_t)0x00100000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO21] Bits */
#define GPIO_DIN31_0_DIO21_OFS                   (21)                            /* !< DIO21 Offset */
#define GPIO_DIN31_0_DIO21_MASK                  ((uint32_t)0x00200000U)         /* !< This bit reads the data input value
                                                                                    of DIO21. */
#define GPIO_DIN31_0_DIO21_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO21_ONE                   ((uint32_t)0x00200000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO22] Bits */
#define GPIO_DIN31_0_DIO22_OFS                   (22)                            /* !< DIO22 Offset */
#define GPIO_DIN31_0_DIO22_MASK                  ((uint32_t)0x00400000U)         /* !< This bit reads the data input value
                                                                                    of DIO22. */
#define GPIO_DIN31_0_DIO22_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO22_ONE                   ((uint32_t)0x00400000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO23] Bits */
#define GPIO_DIN31_0_DIO23_OFS                   (23)                            /* !< DIO23 Offset */
#define GPIO_DIN31_0_DIO23_MASK                  ((uint32_t)0x00800000U)         /* !< This bit reads the data input value
                                                                                    of DIO23. */
#define GPIO_DIN31_0_DIO23_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO23_ONE                   ((uint32_t)0x00800000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO24] Bits */
#define GPIO_DIN31_0_DIO24_OFS                   (24)                            /* !< DIO24 Offset */
#define GPIO_DIN31_0_DIO24_MASK                  ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of DIO24. */
#define GPIO_DIN31_0_DIO24_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO24_ONE                   ((uint32_t)0x01000000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO25] Bits */
#define GPIO_DIN31_0_DIO25_OFS                   (25)                            /* !< DIO25 Offset */
#define GPIO_DIN31_0_DIO25_MASK                  ((uint32_t)0x02000000U)         /* !< This bit reads the data input value
                                                                                    of DIO25. */
#define GPIO_DIN31_0_DIO25_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO25_ONE                   ((uint32_t)0x02000000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO26] Bits */
#define GPIO_DIN31_0_DIO26_OFS                   (26)                            /* !< DIO26 Offset */
#define GPIO_DIN31_0_DIO26_MASK                  ((uint32_t)0x04000000U)         /* !< This bit reads the data input value
                                                                                    of DIO26. */
#define GPIO_DIN31_0_DIO26_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO26_ONE                   ((uint32_t)0x04000000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO27] Bits */
#define GPIO_DIN31_0_DIO27_OFS                   (27)                            /* !< DIO27 Offset */
#define GPIO_DIN31_0_DIO27_MASK                  ((uint32_t)0x08000000U)         /* !< This bit reads the data input value
                                                                                    of DIO27. */
#define GPIO_DIN31_0_DIO27_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO27_ONE                   ((uint32_t)0x08000000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO28] Bits */
#define GPIO_DIN31_0_DIO28_OFS                   (28)                            /* !< DIO28 Offset */
#define GPIO_DIN31_0_DIO28_MASK                  ((uint32_t)0x10000000U)         /* !< This bit reads the data input value
                                                                                    of DIO28. */
#define GPIO_DIN31_0_DIO28_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO28_ONE                   ((uint32_t)0x10000000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO29] Bits */
#define GPIO_DIN31_0_DIO29_OFS                   (29)                            /* !< DIO29 Offset */
#define GPIO_DIN31_0_DIO29_MASK                  ((uint32_t)0x20000000U)         /* !< This bit reads the data input value
                                                                                    of DIO29. */
#define GPIO_DIN31_0_DIO29_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO29_ONE                   ((uint32_t)0x20000000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO30] Bits */
#define GPIO_DIN31_0_DIO30_OFS                   (30)                            /* !< DIO30 Offset */
#define GPIO_DIN31_0_DIO30_MASK                  ((uint32_t)0x40000000U)         /* !< This bit reads the data input value
                                                                                    of DIO30. */
#define GPIO_DIN31_0_DIO30_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO30_ONE                   ((uint32_t)0x40000000U)         /* !< Input value is 1 */
/* GPIO_DIN31_0[DIO31] Bits */
#define GPIO_DIN31_0_DIO31_OFS                   (31)                            /* !< DIO31 Offset */
#define GPIO_DIN31_0_DIO31_MASK                  ((uint32_t)0x80000000U)         /* !< This bit reads the data input value
                                                                                    of DIO31. */
#define GPIO_DIN31_0_DIO31_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define GPIO_DIN31_0_DIO31_ONE                   ((uint32_t)0x80000000U)         /* !< Input value is 1 */

/* GPIO_POLARITY15_0 Bits */
/* GPIO_POLARITY15_0[DIO0] Bits */
#define GPIO_POLARITY15_0_DIO0_OFS               (0)                             /* !< DIO0 Offset */
#define GPIO_POLARITY15_0_DIO0_MASK              ((uint32_t)0x00000003U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO0. */
#define GPIO_POLARITY15_0_DIO0_DISABLE           ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO0_RISE              ((uint32_t)0x00000001U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO0_FALL              ((uint32_t)0x00000002U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO0_RISE_FALL         ((uint32_t)0x00000003U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO1] Bits */
#define GPIO_POLARITY15_0_DIO1_OFS               (2)                             /* !< DIO1 Offset */
#define GPIO_POLARITY15_0_DIO1_MASK              ((uint32_t)0x0000000CU)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO1. */
#define GPIO_POLARITY15_0_DIO1_DISABLE           ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO1_RISE              ((uint32_t)0x00000004U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO1_FALL              ((uint32_t)0x00000008U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO1_RISE_FALL         ((uint32_t)0x0000000CU)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO2] Bits */
#define GPIO_POLARITY15_0_DIO2_OFS               (4)                             /* !< DIO2 Offset */
#define GPIO_POLARITY15_0_DIO2_MASK              ((uint32_t)0x00000030U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO2. */
#define GPIO_POLARITY15_0_DIO2_DISABLE           ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO2_RISE              ((uint32_t)0x00000010U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO2_FALL              ((uint32_t)0x00000020U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO2_RISE_FALL         ((uint32_t)0x00000030U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO3] Bits */
#define GPIO_POLARITY15_0_DIO3_OFS               (6)                             /* !< DIO3 Offset */
#define GPIO_POLARITY15_0_DIO3_MASK              ((uint32_t)0x000000C0U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO3. */
#define GPIO_POLARITY15_0_DIO3_DISABLE           ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO3_RISE              ((uint32_t)0x00000040U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO3_FALL              ((uint32_t)0x00000080U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO3_RISE_FALL         ((uint32_t)0x000000C0U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO4] Bits */
#define GPIO_POLARITY15_0_DIO4_OFS               (8)                             /* !< DIO4 Offset */
#define GPIO_POLARITY15_0_DIO4_MASK              ((uint32_t)0x00000300U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO4. */
#define GPIO_POLARITY15_0_DIO4_DISABLE           ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO4_RISE              ((uint32_t)0x00000100U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO4_FALL              ((uint32_t)0x00000200U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO4_RISE_FALL         ((uint32_t)0x00000300U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO5] Bits */
#define GPIO_POLARITY15_0_DIO5_OFS               (10)                            /* !< DIO5 Offset */
#define GPIO_POLARITY15_0_DIO5_MASK              ((uint32_t)0x00000C00U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO5. */
#define GPIO_POLARITY15_0_DIO5_DISABLE           ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO5_RISE              ((uint32_t)0x00000400U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO5_FALL              ((uint32_t)0x00000800U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO5_RISE_FALL         ((uint32_t)0x00000C00U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO6] Bits */
#define GPIO_POLARITY15_0_DIO6_OFS               (12)                            /* !< DIO6 Offset */
#define GPIO_POLARITY15_0_DIO6_MASK              ((uint32_t)0x00003000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO6. */
#define GPIO_POLARITY15_0_DIO6_DISABLE           ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO6_RISE              ((uint32_t)0x00001000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO6_FALL              ((uint32_t)0x00002000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO6_RISE_FALL         ((uint32_t)0x00003000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO7] Bits */
#define GPIO_POLARITY15_0_DIO7_OFS               (14)                            /* !< DIO7 Offset */
#define GPIO_POLARITY15_0_DIO7_MASK              ((uint32_t)0x0000C000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO7. */
#define GPIO_POLARITY15_0_DIO7_DISABLE           ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO7_RISE              ((uint32_t)0x00004000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO7_FALL              ((uint32_t)0x00008000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO7_RISE_FALL         ((uint32_t)0x0000C000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO8] Bits */
#define GPIO_POLARITY15_0_DIO8_OFS               (16)                            /* !< DIO8 Offset */
#define GPIO_POLARITY15_0_DIO8_MASK              ((uint32_t)0x00030000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO8. */
#define GPIO_POLARITY15_0_DIO8_DISABLE           ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO8_RISE              ((uint32_t)0x00010000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO8_FALL              ((uint32_t)0x00020000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO8_RISE_FALL         ((uint32_t)0x00030000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO9] Bits */
#define GPIO_POLARITY15_0_DIO9_OFS               (18)                            /* !< DIO9 Offset */
#define GPIO_POLARITY15_0_DIO9_MASK              ((uint32_t)0x000C0000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO9. */
#define GPIO_POLARITY15_0_DIO9_DISABLE           ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO9_RISE              ((uint32_t)0x00040000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO9_FALL              ((uint32_t)0x00080000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO9_RISE_FALL         ((uint32_t)0x000C0000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO10] Bits */
#define GPIO_POLARITY15_0_DIO10_OFS              (20)                            /* !< DIO10 Offset */
#define GPIO_POLARITY15_0_DIO10_MASK             ((uint32_t)0x00300000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO10. */
#define GPIO_POLARITY15_0_DIO10_DISABLE          ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO10_RISE             ((uint32_t)0x00100000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO10_FALL             ((uint32_t)0x00200000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO10_RISE_FALL        ((uint32_t)0x00300000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO11] Bits */
#define GPIO_POLARITY15_0_DIO11_OFS              (22)                            /* !< DIO11 Offset */
#define GPIO_POLARITY15_0_DIO11_MASK             ((uint32_t)0x00C00000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO11. */
#define GPIO_POLARITY15_0_DIO11_DISABLE          ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO11_RISE             ((uint32_t)0x00400000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO11_FALL             ((uint32_t)0x00800000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO11_RISE_FALL        ((uint32_t)0x00C00000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO12] Bits */
#define GPIO_POLARITY15_0_DIO12_OFS              (24)                            /* !< DIO12 Offset */
#define GPIO_POLARITY15_0_DIO12_MASK             ((uint32_t)0x03000000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO12. */
#define GPIO_POLARITY15_0_DIO12_DISABLE          ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO12_RISE             ((uint32_t)0x01000000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO12_FALL             ((uint32_t)0x02000000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO12_RISE_FALL        ((uint32_t)0x03000000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO13] Bits */
#define GPIO_POLARITY15_0_DIO13_OFS              (26)                            /* !< DIO13 Offset */
#define GPIO_POLARITY15_0_DIO13_MASK             ((uint32_t)0x0C000000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO13. */
#define GPIO_POLARITY15_0_DIO13_DISABLE          ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO13_RISE             ((uint32_t)0x04000000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO13_FALL             ((uint32_t)0x08000000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO13_RISE_FALL        ((uint32_t)0x0C000000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO14] Bits */
#define GPIO_POLARITY15_0_DIO14_OFS              (28)                            /* !< DIO14 Offset */
#define GPIO_POLARITY15_0_DIO14_MASK             ((uint32_t)0x30000000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO14. */
#define GPIO_POLARITY15_0_DIO14_DISABLE          ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO14_RISE             ((uint32_t)0x10000000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO14_FALL             ((uint32_t)0x20000000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO14_RISE_FALL        ((uint32_t)0x30000000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY15_0[DIO15] Bits */
#define GPIO_POLARITY15_0_DIO15_OFS              (30)                            /* !< DIO15 Offset */
#define GPIO_POLARITY15_0_DIO15_MASK             ((uint32_t)0xC0000000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO15. */
#define GPIO_POLARITY15_0_DIO15_DISABLE          ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY15_0_DIO15_RISE             ((uint32_t)0x40000000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY15_0_DIO15_FALL             ((uint32_t)0x80000000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY15_0_DIO15_RISE_FALL        ((uint32_t)0xC0000000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */

/* GPIO_POLARITY31_16 Bits */
/* GPIO_POLARITY31_16[DIO16] Bits */
#define GPIO_POLARITY31_16_DIO16_OFS             (0)                             /* !< DIO16 Offset */
#define GPIO_POLARITY31_16_DIO16_MASK            ((uint32_t)0x00000003U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO16. */
#define GPIO_POLARITY31_16_DIO16_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO16_RISE            ((uint32_t)0x00000001U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO16_FALL            ((uint32_t)0x00000002U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO16_RISE_FALL       ((uint32_t)0x00000003U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO17] Bits */
#define GPIO_POLARITY31_16_DIO17_OFS             (2)                             /* !< DIO17 Offset */
#define GPIO_POLARITY31_16_DIO17_MASK            ((uint32_t)0x0000000CU)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO17. */
#define GPIO_POLARITY31_16_DIO17_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO17_RISE            ((uint32_t)0x00000004U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO17_FALL            ((uint32_t)0x00000008U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO17_RISE_FALL       ((uint32_t)0x0000000CU)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO18] Bits */
#define GPIO_POLARITY31_16_DIO18_OFS             (4)                             /* !< DIO18 Offset */
#define GPIO_POLARITY31_16_DIO18_MASK            ((uint32_t)0x00000030U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO18. */
#define GPIO_POLARITY31_16_DIO18_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO18_RISE            ((uint32_t)0x00000010U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO18_FALL            ((uint32_t)0x00000020U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO18_RISE_FALL       ((uint32_t)0x00000030U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO19] Bits */
#define GPIO_POLARITY31_16_DIO19_OFS             (6)                             /* !< DIO19 Offset */
#define GPIO_POLARITY31_16_DIO19_MASK            ((uint32_t)0x000000C0U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO19. */
#define GPIO_POLARITY31_16_DIO19_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO19_RISE            ((uint32_t)0x00000040U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO19_FALL            ((uint32_t)0x00000080U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO19_RISE_FALL       ((uint32_t)0x000000C0U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO20] Bits */
#define GPIO_POLARITY31_16_DIO20_OFS             (8)                             /* !< DIO20 Offset */
#define GPIO_POLARITY31_16_DIO20_MASK            ((uint32_t)0x00000300U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO20. */
#define GPIO_POLARITY31_16_DIO20_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO20_RISE            ((uint32_t)0x00000100U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO20_FALL            ((uint32_t)0x00000200U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO20_RISE_FALL       ((uint32_t)0x00000300U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO21] Bits */
#define GPIO_POLARITY31_16_DIO21_OFS             (10)                            /* !< DIO21 Offset */
#define GPIO_POLARITY31_16_DIO21_MASK            ((uint32_t)0x00000C00U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO21. */
#define GPIO_POLARITY31_16_DIO21_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO21_RISE            ((uint32_t)0x00000400U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO21_FALL            ((uint32_t)0x00000800U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO21_RISE_FALL       ((uint32_t)0x00000C00U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO22] Bits */
#define GPIO_POLARITY31_16_DIO22_OFS             (12)                            /* !< DIO22 Offset */
#define GPIO_POLARITY31_16_DIO22_MASK            ((uint32_t)0x00003000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO22. */
#define GPIO_POLARITY31_16_DIO22_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO22_RISE            ((uint32_t)0x00001000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO22_FALL            ((uint32_t)0x00002000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO22_RISE_FALL       ((uint32_t)0x00003000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO23] Bits */
#define GPIO_POLARITY31_16_DIO23_OFS             (14)                            /* !< DIO23 Offset */
#define GPIO_POLARITY31_16_DIO23_MASK            ((uint32_t)0x0000C000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO23. */
#define GPIO_POLARITY31_16_DIO23_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO23_RISE            ((uint32_t)0x00004000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO23_FALL            ((uint32_t)0x00008000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO23_RISE_FALL       ((uint32_t)0x0000C000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO24] Bits */
#define GPIO_POLARITY31_16_DIO24_OFS             (16)                            /* !< DIO24 Offset */
#define GPIO_POLARITY31_16_DIO24_MASK            ((uint32_t)0x00030000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO24. */
#define GPIO_POLARITY31_16_DIO24_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO24_RISE            ((uint32_t)0x00010000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO24_FALL            ((uint32_t)0x00020000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO24_RISE_FALL       ((uint32_t)0x00030000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO25] Bits */
#define GPIO_POLARITY31_16_DIO25_OFS             (18)                            /* !< DIO25 Offset */
#define GPIO_POLARITY31_16_DIO25_MASK            ((uint32_t)0x000C0000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO25. */
#define GPIO_POLARITY31_16_DIO25_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO25_RISE            ((uint32_t)0x00040000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO25_FALL            ((uint32_t)0x00080000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO25_RISE_FALL       ((uint32_t)0x000C0000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO26] Bits */
#define GPIO_POLARITY31_16_DIO26_OFS             (20)                            /* !< DIO26 Offset */
#define GPIO_POLARITY31_16_DIO26_MASK            ((uint32_t)0x00300000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO26. */
#define GPIO_POLARITY31_16_DIO26_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO26_RISE            ((uint32_t)0x00100000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO26_FALL            ((uint32_t)0x00200000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO26_RISE_FALL       ((uint32_t)0x00300000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO27] Bits */
#define GPIO_POLARITY31_16_DIO27_OFS             (22)                            /* !< DIO27 Offset */
#define GPIO_POLARITY31_16_DIO27_MASK            ((uint32_t)0x00C00000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO27. */
#define GPIO_POLARITY31_16_DIO27_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO27_RISE            ((uint32_t)0x00400000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO27_FALL            ((uint32_t)0x00800000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO27_RISE_FALL       ((uint32_t)0x00C00000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO28] Bits */
#define GPIO_POLARITY31_16_DIO28_OFS             (24)                            /* !< DIO28 Offset */
#define GPIO_POLARITY31_16_DIO28_MASK            ((uint32_t)0x03000000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO28. */
#define GPIO_POLARITY31_16_DIO28_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO28_RISE            ((uint32_t)0x01000000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO28_FALL            ((uint32_t)0x02000000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO28_RISE_FALL       ((uint32_t)0x03000000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO29] Bits */
#define GPIO_POLARITY31_16_DIO29_OFS             (26)                            /* !< DIO29 Offset */
#define GPIO_POLARITY31_16_DIO29_MASK            ((uint32_t)0x0C000000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO29. */
#define GPIO_POLARITY31_16_DIO29_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO29_RISE            ((uint32_t)0x04000000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO29_FALL            ((uint32_t)0x08000000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO29_RISE_FALL       ((uint32_t)0x0C000000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO30] Bits */
#define GPIO_POLARITY31_16_DIO30_OFS             (28)                            /* !< DIO30 Offset */
#define GPIO_POLARITY31_16_DIO30_MASK            ((uint32_t)0x30000000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO30. */
#define GPIO_POLARITY31_16_DIO30_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO30_RISE            ((uint32_t)0x10000000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO30_FALL            ((uint32_t)0x20000000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO30_RISE_FALL       ((uint32_t)0x30000000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* GPIO_POLARITY31_16[DIO31] Bits */
#define GPIO_POLARITY31_16_DIO31_OFS             (30)                            /* !< DIO31 Offset */
#define GPIO_POLARITY31_16_DIO31_MASK            ((uint32_t)0xC0000000U)         /* !< Enables and configures edge
                                                                                    detection polarity for DIO31. */
#define GPIO_POLARITY31_16_DIO31_DISABLE         ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define GPIO_POLARITY31_16_DIO31_RISE            ((uint32_t)0x40000000U)         /* !< Detects rising edge of input event */
#define GPIO_POLARITY31_16_DIO31_FALL            ((uint32_t)0x80000000U)         /* !< Detects falling edge of input event */
#define GPIO_POLARITY31_16_DIO31_RISE_FALL       ((uint32_t)0xC0000000U)         /* !< Detects both rising and falling
                                                                                    edge of input event */

/* GPIO_CTL Bits */
/* GPIO_CTL[FASTWAKEONLY] Bits */
#define GPIO_CTL_FASTWAKEONLY_OFS                (0)                             /* !< FASTWAKEONLY Offset */
#define GPIO_CTL_FASTWAKEONLY_MASK               ((uint32_t)0x00000001U)         /* !< FASTWAKEONLY for the global control
                                                                                    of fastwake */
#define GPIO_CTL_FASTWAKEONLY_NOT_GLOBAL_EN      ((uint32_t)0x00000000U)         /* !< The global control of fastwake is
                                                                                    not enabled, per bit fast wake
                                                                                    feature depends on FASTWAKE.DIN */
#define GPIO_CTL_FASTWAKEONLY_GLOBAL_EN          ((uint32_t)0x00000001U)         /* !< The global control of fastwake is
                                                                                    enabled */

/* GPIO_FASTWAKE Bits */
/* GPIO_FASTWAKE[DIN0] Bits */
#define GPIO_FASTWAKE_DIN0_OFS                   (0)                             /* !< DIN0 Offset */
#define GPIO_FASTWAKE_DIN0_MASK                  ((uint32_t)0x00000001U)         /* !< Enable fastwake feature for DIN0 */
#define GPIO_FASTWAKE_DIN0_DISABLE               ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN0_ENABLE                ((uint32_t)0x00000001U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN1] Bits */
#define GPIO_FASTWAKE_DIN1_OFS                   (1)                             /* !< DIN1 Offset */
#define GPIO_FASTWAKE_DIN1_MASK                  ((uint32_t)0x00000002U)         /* !< Enable fastwake feature for DIN1 */
#define GPIO_FASTWAKE_DIN1_DISABLE               ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN1_ENABLE                ((uint32_t)0x00000002U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN2] Bits */
#define GPIO_FASTWAKE_DIN2_OFS                   (2)                             /* !< DIN2 Offset */
#define GPIO_FASTWAKE_DIN2_MASK                  ((uint32_t)0x00000004U)         /* !< Enable fastwake feature for DIN2 */
#define GPIO_FASTWAKE_DIN2_DISABLE               ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN2_ENABLE                ((uint32_t)0x00000004U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN3] Bits */
#define GPIO_FASTWAKE_DIN3_OFS                   (3)                             /* !< DIN3 Offset */
#define GPIO_FASTWAKE_DIN3_MASK                  ((uint32_t)0x00000008U)         /* !< Enable fastwake feature for DIN3 */
#define GPIO_FASTWAKE_DIN3_DISABLE               ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN3_ENABLE                ((uint32_t)0x00000008U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN4] Bits */
#define GPIO_FASTWAKE_DIN4_OFS                   (4)                             /* !< DIN4 Offset */
#define GPIO_FASTWAKE_DIN4_MASK                  ((uint32_t)0x00000010U)         /* !< Enable fastwake feature for DIN4 */
#define GPIO_FASTWAKE_DIN4_DISABLE               ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN4_ENABLE                ((uint32_t)0x00000010U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN5] Bits */
#define GPIO_FASTWAKE_DIN5_OFS                   (5)                             /* !< DIN5 Offset */
#define GPIO_FASTWAKE_DIN5_MASK                  ((uint32_t)0x00000020U)         /* !< Enable fastwake feature for DIN5 */
#define GPIO_FASTWAKE_DIN5_DISABLE               ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN5_ENABLE                ((uint32_t)0x00000020U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN6] Bits */
#define GPIO_FASTWAKE_DIN6_OFS                   (6)                             /* !< DIN6 Offset */
#define GPIO_FASTWAKE_DIN6_MASK                  ((uint32_t)0x00000040U)         /* !< Enable fastwake feature for DIN6 */
#define GPIO_FASTWAKE_DIN6_DISABLE               ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN6_ENABLE                ((uint32_t)0x00000040U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN7] Bits */
#define GPIO_FASTWAKE_DIN7_OFS                   (7)                             /* !< DIN7 Offset */
#define GPIO_FASTWAKE_DIN7_MASK                  ((uint32_t)0x00000080U)         /* !< Enable fastwake feature for DIN7 */
#define GPIO_FASTWAKE_DIN7_DISABLE               ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN7_ENABLE                ((uint32_t)0x00000080U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN8] Bits */
#define GPIO_FASTWAKE_DIN8_OFS                   (8)                             /* !< DIN8 Offset */
#define GPIO_FASTWAKE_DIN8_MASK                  ((uint32_t)0x00000100U)         /* !< Enable fastwake feature for DIN8 */
#define GPIO_FASTWAKE_DIN8_DISABLE               ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN8_ENABLE                ((uint32_t)0x00000100U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN9] Bits */
#define GPIO_FASTWAKE_DIN9_OFS                   (9)                             /* !< DIN9 Offset */
#define GPIO_FASTWAKE_DIN9_MASK                  ((uint32_t)0x00000200U)         /* !< Enable fastwake feature for DIN9 */
#define GPIO_FASTWAKE_DIN9_DISABLE               ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN9_ENABLE                ((uint32_t)0x00000200U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN10] Bits */
#define GPIO_FASTWAKE_DIN10_OFS                  (10)                            /* !< DIN10 Offset */
#define GPIO_FASTWAKE_DIN10_MASK                 ((uint32_t)0x00000400U)         /* !< Enable fastwake feature for DIN10 */
#define GPIO_FASTWAKE_DIN10_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN10_ENABLE               ((uint32_t)0x00000400U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN11] Bits */
#define GPIO_FASTWAKE_DIN11_OFS                  (11)                            /* !< DIN11 Offset */
#define GPIO_FASTWAKE_DIN11_MASK                 ((uint32_t)0x00000800U)         /* !< Enable fastwake feature for DIN11 */
#define GPIO_FASTWAKE_DIN11_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN11_ENABLE               ((uint32_t)0x00000800U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN12] Bits */
#define GPIO_FASTWAKE_DIN12_OFS                  (12)                            /* !< DIN12 Offset */
#define GPIO_FASTWAKE_DIN12_MASK                 ((uint32_t)0x00001000U)         /* !< Enable fastwake feature for DIN12 */
#define GPIO_FASTWAKE_DIN12_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN12_ENABLE               ((uint32_t)0x00001000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN13] Bits */
#define GPIO_FASTWAKE_DIN13_OFS                  (13)                            /* !< DIN13 Offset */
#define GPIO_FASTWAKE_DIN13_MASK                 ((uint32_t)0x00002000U)         /* !< Enable fastwake feature for DIN13 */
#define GPIO_FASTWAKE_DIN13_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN13_ENABLE               ((uint32_t)0x00002000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN14] Bits */
#define GPIO_FASTWAKE_DIN14_OFS                  (14)                            /* !< DIN14 Offset */
#define GPIO_FASTWAKE_DIN14_MASK                 ((uint32_t)0x00004000U)         /* !< Enable fastwake feature for DIN14 */
#define GPIO_FASTWAKE_DIN14_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN14_ENABLE               ((uint32_t)0x00004000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN15] Bits */
#define GPIO_FASTWAKE_DIN15_OFS                  (15)                            /* !< DIN15 Offset */
#define GPIO_FASTWAKE_DIN15_MASK                 ((uint32_t)0x00008000U)         /* !< Enable fastwake feature for DIN15 */
#define GPIO_FASTWAKE_DIN15_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN15_ENABLE               ((uint32_t)0x00008000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN16] Bits */
#define GPIO_FASTWAKE_DIN16_OFS                  (16)                            /* !< DIN16 Offset */
#define GPIO_FASTWAKE_DIN16_MASK                 ((uint32_t)0x00010000U)         /* !< Enable fastwake feature for DIN16 */
#define GPIO_FASTWAKE_DIN16_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN16_ENABLE               ((uint32_t)0x00010000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN17] Bits */
#define GPIO_FASTWAKE_DIN17_OFS                  (17)                            /* !< DIN17 Offset */
#define GPIO_FASTWAKE_DIN17_MASK                 ((uint32_t)0x00020000U)         /* !< Enable fastwake feature for DIN17 */
#define GPIO_FASTWAKE_DIN17_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN17_ENABLE               ((uint32_t)0x00020000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN18] Bits */
#define GPIO_FASTWAKE_DIN18_OFS                  (18)                            /* !< DIN18 Offset */
#define GPIO_FASTWAKE_DIN18_MASK                 ((uint32_t)0x00040000U)         /* !< Enable fastwake feature for DIN18 */
#define GPIO_FASTWAKE_DIN18_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN18_ENABLE               ((uint32_t)0x00040000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN19] Bits */
#define GPIO_FASTWAKE_DIN19_OFS                  (19)                            /* !< DIN19 Offset */
#define GPIO_FASTWAKE_DIN19_MASK                 ((uint32_t)0x00080000U)         /* !< Enable fastwake feature for DIN19 */
#define GPIO_FASTWAKE_DIN19_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN19_ENABLE               ((uint32_t)0x00080000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN20] Bits */
#define GPIO_FASTWAKE_DIN20_OFS                  (20)                            /* !< DIN20 Offset */
#define GPIO_FASTWAKE_DIN20_MASK                 ((uint32_t)0x00100000U)         /* !< Enable fastwake feature for DIN20 */
#define GPIO_FASTWAKE_DIN20_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN20_ENABLE               ((uint32_t)0x00100000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN21] Bits */
#define GPIO_FASTWAKE_DIN21_OFS                  (21)                            /* !< DIN21 Offset */
#define GPIO_FASTWAKE_DIN21_MASK                 ((uint32_t)0x00200000U)         /* !< Enable fastwake feature for DIN21 */
#define GPIO_FASTWAKE_DIN21_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN21_ENABLE               ((uint32_t)0x00200000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN22] Bits */
#define GPIO_FASTWAKE_DIN22_OFS                  (22)                            /* !< DIN22 Offset */
#define GPIO_FASTWAKE_DIN22_MASK                 ((uint32_t)0x00400000U)         /* !< Enable fastwake feature for DIN22 */
#define GPIO_FASTWAKE_DIN22_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN22_ENABLE               ((uint32_t)0x00400000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN23] Bits */
#define GPIO_FASTWAKE_DIN23_OFS                  (23)                            /* !< DIN23 Offset */
#define GPIO_FASTWAKE_DIN23_MASK                 ((uint32_t)0x00800000U)         /* !< Enable fastwake feature for DIN23 */
#define GPIO_FASTWAKE_DIN23_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN23_ENABLE               ((uint32_t)0x00800000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN24] Bits */
#define GPIO_FASTWAKE_DIN24_OFS                  (24)                            /* !< DIN24 Offset */
#define GPIO_FASTWAKE_DIN24_MASK                 ((uint32_t)0x01000000U)         /* !< Enable fastwake feature for DIN24 */
#define GPIO_FASTWAKE_DIN24_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN24_ENABLE               ((uint32_t)0x01000000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN25] Bits */
#define GPIO_FASTWAKE_DIN25_OFS                  (25)                            /* !< DIN25 Offset */
#define GPIO_FASTWAKE_DIN25_MASK                 ((uint32_t)0x02000000U)         /* !< Enable fastwake feature for DIN25 */
#define GPIO_FASTWAKE_DIN25_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN25_ENABLE               ((uint32_t)0x02000000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN26] Bits */
#define GPIO_FASTWAKE_DIN26_OFS                  (26)                            /* !< DIN26 Offset */
#define GPIO_FASTWAKE_DIN26_MASK                 ((uint32_t)0x04000000U)         /* !< Enable fastwake feature for DIN26 */
#define GPIO_FASTWAKE_DIN26_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN26_ENABLE               ((uint32_t)0x04000000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN27] Bits */
#define GPIO_FASTWAKE_DIN27_OFS                  (27)                            /* !< DIN27 Offset */
#define GPIO_FASTWAKE_DIN27_MASK                 ((uint32_t)0x08000000U)         /* !< Enable fastwake feature for DIN27 */
#define GPIO_FASTWAKE_DIN27_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN27_ENABLE               ((uint32_t)0x08000000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN28] Bits */
#define GPIO_FASTWAKE_DIN28_OFS                  (28)                            /* !< DIN28 Offset */
#define GPIO_FASTWAKE_DIN28_MASK                 ((uint32_t)0x10000000U)         /* !< Enable fastwake feature for DIN29 */
#define GPIO_FASTWAKE_DIN28_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN28_ENABLE               ((uint32_t)0x10000000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN29] Bits */
#define GPIO_FASTWAKE_DIN29_OFS                  (29)                            /* !< DIN29 Offset */
#define GPIO_FASTWAKE_DIN29_MASK                 ((uint32_t)0x20000000U)         /* !< Enable fastwake feature for DIN29 */
#define GPIO_FASTWAKE_DIN29_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN29_ENABLE               ((uint32_t)0x20000000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN30] Bits */
#define GPIO_FASTWAKE_DIN30_OFS                  (30)                            /* !< DIN30 Offset */
#define GPIO_FASTWAKE_DIN30_MASK                 ((uint32_t)0x40000000U)         /* !< Enable fastwake feature for DIN30 */
#define GPIO_FASTWAKE_DIN30_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN30_ENABLE               ((uint32_t)0x40000000U)         /* !< fastwake feature is enabled */
/* GPIO_FASTWAKE[DIN31] Bits */
#define GPIO_FASTWAKE_DIN31_OFS                  (31)                            /* !< DIN31 Offset */
#define GPIO_FASTWAKE_DIN31_MASK                 ((uint32_t)0x80000000U)         /* !< Enable fastwake feature for DIN31 */
#define GPIO_FASTWAKE_DIN31_DISABLE              ((uint32_t)0x00000000U)         /* !< fastwake feature is disabled */
#define GPIO_FASTWAKE_DIN31_ENABLE               ((uint32_t)0x80000000U)         /* !< fastwake feature is enabled */

/* GPIO_SUB0CFG Bits */
/* GPIO_SUB0CFG[ENABLE] Bits */
#define GPIO_SUB0CFG_ENABLE_OFS                  (0)                             /* !< ENABLE Offset */
#define GPIO_SUB0CFG_ENABLE_MASK                 ((uint32_t)0x00000001U)         /* !< This bit is used to enable
                                                                                    subscriber 0 event. */
#define GPIO_SUB0CFG_ENABLE_CLR                  ((uint32_t)0x00000000U)         /* !< Subscriber 0 event is disabled */
#define GPIO_SUB0CFG_ENABLE_SET                  ((uint32_t)0x00000001U)         /* !< Subscriber 0 event is enabled */
/* GPIO_SUB0CFG[OUTPOLICY] Bits */
#define GPIO_SUB0CFG_OUTPOLICY_OFS               (8)                             /* !< OUTPOLICY Offset */
#define GPIO_SUB0CFG_OUTPOLICY_MASK              ((uint32_t)0x00000300U)         /* !< These bits configure the output
                                                                                    policy for subscriber 0 event. */
#define GPIO_SUB0CFG_OUTPOLICY_SET               ((uint32_t)0x00000000U)         /* !< Selected DIO pins are set */
#define GPIO_SUB0CFG_OUTPOLICY_CLR               ((uint32_t)0x00000100U)         /* !< Selected DIO pins are cleared */
#define GPIO_SUB0CFG_OUTPOLICY_TOGGLE            ((uint32_t)0x00000200U)         /* !< Selected DIO pins are toggled */
/* GPIO_SUB0CFG[INDEX] Bits */
#define GPIO_SUB0CFG_INDEX_OFS                   (16)                            /* !< INDEX Offset */
#define GPIO_SUB0CFG_INDEX_MASK                  ((uint32_t)0x000F0000U)         /* !< Indicates the specific bit among
                                                                                    lower 16 bits that is targeted by the
                                                                                    subscriber action */
#define GPIO_SUB0CFG_INDEX_MIN                   ((uint32_t)0x00000000U)         /* !< specific bit targeted by the
                                                                                    subscriber action is bit0 */
#define GPIO_SUB0CFG_INDEX_MAX                   ((uint32_t)0x000F0000U)         /* !< specific bit targeted by the
                                                                                    subscriber action is bit15 */

/* GPIO_FILTEREN15_0 Bits */
/* GPIO_FILTEREN15_0[DIN0] Bits */
#define GPIO_FILTEREN15_0_DIN0_OFS               (0)                             /* !< DIN0 Offset */
#define GPIO_FILTEREN15_0_DIN0_MASK              ((uint32_t)0x00000003U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN0 */
#define GPIO_FILTEREN15_0_DIN0_DISABLE           ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN0_ONE_CYCLE         ((uint32_t)0x00000001U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN0_THREE_CYCLE       ((uint32_t)0x00000002U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN0_EIGHT_CYCLE       ((uint32_t)0x00000003U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN1] Bits */
#define GPIO_FILTEREN15_0_DIN1_OFS               (2)                             /* !< DIN1 Offset */
#define GPIO_FILTEREN15_0_DIN1_MASK              ((uint32_t)0x0000000CU)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN1 */
#define GPIO_FILTEREN15_0_DIN1_DISABLE           ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN1_ONE_CYCLE         ((uint32_t)0x00000004U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN1_THREE_CYCLE       ((uint32_t)0x00000008U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN1_EIGHT_CYCLE       ((uint32_t)0x0000000CU)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN2] Bits */
#define GPIO_FILTEREN15_0_DIN2_OFS               (4)                             /* !< DIN2 Offset */
#define GPIO_FILTEREN15_0_DIN2_MASK              ((uint32_t)0x00000030U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN2 */
#define GPIO_FILTEREN15_0_DIN2_DISABLE           ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN2_ONE_CYCLE         ((uint32_t)0x00000010U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN2_THREE_CYCLE       ((uint32_t)0x00000020U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN2_EIGHT_CYCLE       ((uint32_t)0x00000030U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN3] Bits */
#define GPIO_FILTEREN15_0_DIN3_OFS               (6)                             /* !< DIN3 Offset */
#define GPIO_FILTEREN15_0_DIN3_MASK              ((uint32_t)0x000000C0U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN3 */
#define GPIO_FILTEREN15_0_DIN3_DISABLE           ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN3_ONE_CYCLE         ((uint32_t)0x00000040U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN3_THREE_CYCLE       ((uint32_t)0x00000080U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN3_EIGHT_CYCLE       ((uint32_t)0x000000C0U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN4] Bits */
#define GPIO_FILTEREN15_0_DIN4_OFS               (8)                             /* !< DIN4 Offset */
#define GPIO_FILTEREN15_0_DIN4_MASK              ((uint32_t)0x00000300U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN4 */
#define GPIO_FILTEREN15_0_DIN4_DISABLE           ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN4_ONE_CYCLE         ((uint32_t)0x00000100U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN4_THREE_CYCLE       ((uint32_t)0x00000200U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN4_EIGHT_CYCLE       ((uint32_t)0x00000300U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN5] Bits */
#define GPIO_FILTEREN15_0_DIN5_OFS               (10)                            /* !< DIN5 Offset */
#define GPIO_FILTEREN15_0_DIN5_MASK              ((uint32_t)0x00000C00U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN5 */
#define GPIO_FILTEREN15_0_DIN5_DISABLE           ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN5_ONE_CYCLE         ((uint32_t)0x00000400U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN5_THREE_CYCLE       ((uint32_t)0x00000800U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN5_EIGHT_CYCLE       ((uint32_t)0x00000C00U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN6] Bits */
#define GPIO_FILTEREN15_0_DIN6_OFS               (12)                            /* !< DIN6 Offset */
#define GPIO_FILTEREN15_0_DIN6_MASK              ((uint32_t)0x00003000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN6 */
#define GPIO_FILTEREN15_0_DIN6_DISABLE           ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN6_ONE_CYCLE         ((uint32_t)0x00001000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN6_THREE_CYCLE       ((uint32_t)0x00002000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN6_EIGHT_CYCLE       ((uint32_t)0x00003000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN7] Bits */
#define GPIO_FILTEREN15_0_DIN7_OFS               (14)                            /* !< DIN7 Offset */
#define GPIO_FILTEREN15_0_DIN7_MASK              ((uint32_t)0x0000C000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN7 */
#define GPIO_FILTEREN15_0_DIN7_DISABLE           ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN7_ONE_CYCLE         ((uint32_t)0x00004000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN7_THREE_CYCLE       ((uint32_t)0x00008000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN7_EIGHT_CYCLE       ((uint32_t)0x0000C000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN8] Bits */
#define GPIO_FILTEREN15_0_DIN8_OFS               (16)                            /* !< DIN8 Offset */
#define GPIO_FILTEREN15_0_DIN8_MASK              ((uint32_t)0x00030000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN8 */
#define GPIO_FILTEREN15_0_DIN8_DISABLE           ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN8_ONE_CYCLE         ((uint32_t)0x00010000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN8_THREE_CYCLE       ((uint32_t)0x00020000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN8_EIGHT_CYCLE       ((uint32_t)0x00030000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN9] Bits */
#define GPIO_FILTEREN15_0_DIN9_OFS               (18)                            /* !< DIN9 Offset */
#define GPIO_FILTEREN15_0_DIN9_MASK              ((uint32_t)0x000C0000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN9 */
#define GPIO_FILTEREN15_0_DIN9_DISABLE           ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN9_ONE_CYCLE         ((uint32_t)0x00040000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN9_THREE_CYCLE       ((uint32_t)0x00080000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN9_EIGHT_CYCLE       ((uint32_t)0x000C0000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN10] Bits */
#define GPIO_FILTEREN15_0_DIN10_OFS              (20)                            /* !< DIN10 Offset */
#define GPIO_FILTEREN15_0_DIN10_MASK             ((uint32_t)0x00300000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN10 */
#define GPIO_FILTEREN15_0_DIN10_DISABLE          ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN10_ONE_CYCLE        ((uint32_t)0x00100000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN10_THREE_CYCLE      ((uint32_t)0x00200000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN10_EIGHT_CYCLE      ((uint32_t)0x00300000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN11] Bits */
#define GPIO_FILTEREN15_0_DIN11_OFS              (22)                            /* !< DIN11 Offset */
#define GPIO_FILTEREN15_0_DIN11_MASK             ((uint32_t)0x00C00000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN11 */
#define GPIO_FILTEREN15_0_DIN11_DISABLE          ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN11_ONE_CYCLE        ((uint32_t)0x00400000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN11_THREE_CYCLE      ((uint32_t)0x00800000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN11_EIGHT_CYCLE      ((uint32_t)0x00C00000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN12] Bits */
#define GPIO_FILTEREN15_0_DIN12_OFS              (24)                            /* !< DIN12 Offset */
#define GPIO_FILTEREN15_0_DIN12_MASK             ((uint32_t)0x03000000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN12 */
#define GPIO_FILTEREN15_0_DIN12_DISABLE          ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN12_ONE_CYCLE        ((uint32_t)0x01000000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN12_THREE_CYCLE      ((uint32_t)0x02000000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN12_EIGHT_CYCLE      ((uint32_t)0x03000000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN13] Bits */
#define GPIO_FILTEREN15_0_DIN13_OFS              (26)                            /* !< DIN13 Offset */
#define GPIO_FILTEREN15_0_DIN13_MASK             ((uint32_t)0x0C000000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN13 */
#define GPIO_FILTEREN15_0_DIN13_DISABLE          ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN13_ONE_CYCLE        ((uint32_t)0x04000000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN13_THREE_CYCLE      ((uint32_t)0x08000000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN13_EIGHT_CYCLE      ((uint32_t)0x0C000000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN14] Bits */
#define GPIO_FILTEREN15_0_DIN14_OFS              (28)                            /* !< DIN14 Offset */
#define GPIO_FILTEREN15_0_DIN14_MASK             ((uint32_t)0x30000000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN14 */
#define GPIO_FILTEREN15_0_DIN14_DISABLE          ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN14_ONE_CYCLE        ((uint32_t)0x10000000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN14_THREE_CYCLE      ((uint32_t)0x20000000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN14_EIGHT_CYCLE      ((uint32_t)0x30000000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN15_0[DIN15] Bits */
#define GPIO_FILTEREN15_0_DIN15_OFS              (30)                            /* !< DIN15 Offset */
#define GPIO_FILTEREN15_0_DIN15_MASK             ((uint32_t)0xC0000000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN15 */
#define GPIO_FILTEREN15_0_DIN15_DISABLE          ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN15_0_DIN15_ONE_CYCLE        ((uint32_t)0x40000000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN15_THREE_CYCLE      ((uint32_t)0x80000000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN15_0_DIN15_EIGHT_CYCLE      ((uint32_t)0xC0000000U)         /* !< 8 ULPCLK minimum sample */

/* GPIO_FILTEREN31_16 Bits */
/* GPIO_FILTEREN31_16[DIN16] Bits */
#define GPIO_FILTEREN31_16_DIN16_OFS             (0)                             /* !< DIN16 Offset */
#define GPIO_FILTEREN31_16_DIN16_MASK            ((uint32_t)0x00000003U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN16 */
#define GPIO_FILTEREN31_16_DIN16_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN16_ONE_CYCLE       ((uint32_t)0x00000001U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN16_THREE_CYCLE     ((uint32_t)0x00000002U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN16_EIGHT_CYCLE     ((uint32_t)0x00000003U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN17] Bits */
#define GPIO_FILTEREN31_16_DIN17_OFS             (2)                             /* !< DIN17 Offset */
#define GPIO_FILTEREN31_16_DIN17_MASK            ((uint32_t)0x0000000CU)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN17 */
#define GPIO_FILTEREN31_16_DIN17_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN17_ONE_CYCLE       ((uint32_t)0x00000004U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN17_THREE_CYCLE     ((uint32_t)0x00000008U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN17_EIGHT_CYCLE     ((uint32_t)0x0000000CU)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN18] Bits */
#define GPIO_FILTEREN31_16_DIN18_OFS             (4)                             /* !< DIN18 Offset */
#define GPIO_FILTEREN31_16_DIN18_MASK            ((uint32_t)0x00000030U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN18 */
#define GPIO_FILTEREN31_16_DIN18_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN18_ONE_CYCLE       ((uint32_t)0x00000010U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN18_THREE_CYCLE     ((uint32_t)0x00000020U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN18_EIGHT_CYCLE     ((uint32_t)0x00000030U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN19] Bits */
#define GPIO_FILTEREN31_16_DIN19_OFS             (6)                             /* !< DIN19 Offset */
#define GPIO_FILTEREN31_16_DIN19_MASK            ((uint32_t)0x000000C0U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN19 */
#define GPIO_FILTEREN31_16_DIN19_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN19_ONE_CYCLE       ((uint32_t)0x00000040U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN19_THREE_CYCLE     ((uint32_t)0x00000080U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN19_EIGHT_CYCLE     ((uint32_t)0x000000C0U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN20] Bits */
#define GPIO_FILTEREN31_16_DIN20_OFS             (8)                             /* !< DIN20 Offset */
#define GPIO_FILTEREN31_16_DIN20_MASK            ((uint32_t)0x00000300U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN20 */
#define GPIO_FILTEREN31_16_DIN20_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN20_ONE_CYCLE       ((uint32_t)0x00000100U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN20_THREE_CYCLE     ((uint32_t)0x00000200U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN20_EIGHT_CYCLE     ((uint32_t)0x00000300U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN21] Bits */
#define GPIO_FILTEREN31_16_DIN21_OFS             (10)                            /* !< DIN21 Offset */
#define GPIO_FILTEREN31_16_DIN21_MASK            ((uint32_t)0x00000C00U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN21 */
#define GPIO_FILTEREN31_16_DIN21_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN21_ONE_CYCLE       ((uint32_t)0x00000400U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN21_THREE_CYCLE     ((uint32_t)0x00000800U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN21_EIGHT_CYCLE     ((uint32_t)0x00000C00U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN22] Bits */
#define GPIO_FILTEREN31_16_DIN22_OFS             (12)                            /* !< DIN22 Offset */
#define GPIO_FILTEREN31_16_DIN22_MASK            ((uint32_t)0x00003000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN22 */
#define GPIO_FILTEREN31_16_DIN22_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN22_ONE_CYCLE       ((uint32_t)0x00001000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN22_THREE_CYCLE     ((uint32_t)0x00002000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN22_EIGHT_CYCLE     ((uint32_t)0x00003000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN23] Bits */
#define GPIO_FILTEREN31_16_DIN23_OFS             (14)                            /* !< DIN23 Offset */
#define GPIO_FILTEREN31_16_DIN23_MASK            ((uint32_t)0x0000C000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN23 */
#define GPIO_FILTEREN31_16_DIN23_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN23_ONE_CYCLE       ((uint32_t)0x00004000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN23_THREE_CYCLE     ((uint32_t)0x00008000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN23_EIGHT_CYCLE     ((uint32_t)0x0000C000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN24] Bits */
#define GPIO_FILTEREN31_16_DIN24_OFS             (16)                            /* !< DIN24 Offset */
#define GPIO_FILTEREN31_16_DIN24_MASK            ((uint32_t)0x00030000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN24 */
#define GPIO_FILTEREN31_16_DIN24_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN24_ONE_CYCLE       ((uint32_t)0x00010000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN24_THREE_CYCLE     ((uint32_t)0x00020000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN24_EIGHT_CYCLE     ((uint32_t)0x00030000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN25] Bits */
#define GPIO_FILTEREN31_16_DIN25_OFS             (18)                            /* !< DIN25 Offset */
#define GPIO_FILTEREN31_16_DIN25_MASK            ((uint32_t)0x000C0000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN25 */
#define GPIO_FILTEREN31_16_DIN25_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN25_ONE_CYCLE       ((uint32_t)0x00040000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN25_THREE_CYCLE     ((uint32_t)0x00080000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN25_EIGHT_CYCLE     ((uint32_t)0x000C0000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN26] Bits */
#define GPIO_FILTEREN31_16_DIN26_OFS             (20)                            /* !< DIN26 Offset */
#define GPIO_FILTEREN31_16_DIN26_MASK            ((uint32_t)0x00300000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN26 */
#define GPIO_FILTEREN31_16_DIN26_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN26_ONE_CYCLE       ((uint32_t)0x00100000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN26_THREE_CYCLE     ((uint32_t)0x00200000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN26_EIGHT_CYCLE     ((uint32_t)0x00300000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN27] Bits */
#define GPIO_FILTEREN31_16_DIN27_OFS             (22)                            /* !< DIN27 Offset */
#define GPIO_FILTEREN31_16_DIN27_MASK            ((uint32_t)0x00C00000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN27 */
#define GPIO_FILTEREN31_16_DIN27_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN27_ONE_CYCLE       ((uint32_t)0x00400000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN27_THREE_CYCLE     ((uint32_t)0x00800000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN27_EIGHT_CYCLE     ((uint32_t)0x00C00000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN28] Bits */
#define GPIO_FILTEREN31_16_DIN28_OFS             (24)                            /* !< DIN28 Offset */
#define GPIO_FILTEREN31_16_DIN28_MASK            ((uint32_t)0x03000000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN28 */
#define GPIO_FILTEREN31_16_DIN28_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN28_ONE_CYCLE       ((uint32_t)0x01000000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN28_THREE_CYCLE     ((uint32_t)0x02000000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN28_EIGHT_CYCLE     ((uint32_t)0x03000000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN29] Bits */
#define GPIO_FILTEREN31_16_DIN29_OFS             (26)                            /* !< DIN29 Offset */
#define GPIO_FILTEREN31_16_DIN29_MASK            ((uint32_t)0x0C000000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN29 */
#define GPIO_FILTEREN31_16_DIN29_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN29_ONE_CYCLE       ((uint32_t)0x04000000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN29_THREE_CYCLE     ((uint32_t)0x08000000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN29_EIGHT_CYCLE     ((uint32_t)0x0C000000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN30] Bits */
#define GPIO_FILTEREN31_16_DIN30_OFS             (28)                            /* !< DIN30 Offset */
#define GPIO_FILTEREN31_16_DIN30_MASK            ((uint32_t)0x30000000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN30 */
#define GPIO_FILTEREN31_16_DIN30_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN30_ONE_CYCLE       ((uint32_t)0x10000000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN30_THREE_CYCLE     ((uint32_t)0x20000000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN30_EIGHT_CYCLE     ((uint32_t)0x30000000U)         /* !< 8 ULPCLK minimum sample */
/* GPIO_FILTEREN31_16[DIN31] Bits */
#define GPIO_FILTEREN31_16_DIN31_OFS             (30)                            /* !< DIN31 Offset */
#define GPIO_FILTEREN31_16_DIN31_MASK            ((uint32_t)0xC0000000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for DIN31 */
#define GPIO_FILTEREN31_16_DIN31_DISABLE         ((uint32_t)0x00000000U)         /* !< No additional filter beyond the CDC
                                                                                    synchronization sample */
#define GPIO_FILTEREN31_16_DIN31_ONE_CYCLE       ((uint32_t)0x40000000U)         /* !< 1 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN31_THREE_CYCLE     ((uint32_t)0x80000000U)         /* !< 3 ULPCLK minimum sample */
#define GPIO_FILTEREN31_16_DIN31_EIGHT_CYCLE     ((uint32_t)0xC0000000U)         /* !< 8 ULPCLK minimum sample */

/* GPIO_DMAMASK Bits */
/* GPIO_DMAMASK[DOUT0] Bits */
#define GPIO_DMAMASK_DOUT0_OFS                   (0)                             /* !< DOUT0 Offset */
#define GPIO_DMAMASK_DOUT0_MASK                  ((uint32_t)0x00000001U)         /* !< DMA is allowed to modify DOUT0 */
#define GPIO_DMAMASK_DOUT0_DISABLE               ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT0_ENABLE                ((uint32_t)0x00000001U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT1] Bits */
#define GPIO_DMAMASK_DOUT1_OFS                   (1)                             /* !< DOUT1 Offset */
#define GPIO_DMAMASK_DOUT1_MASK                  ((uint32_t)0x00000002U)         /* !< DMA is allowed to modify DOUT1 */
#define GPIO_DMAMASK_DOUT1_DISABLE               ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT1_ENABLE                ((uint32_t)0x00000002U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT2] Bits */
#define GPIO_DMAMASK_DOUT2_OFS                   (2)                             /* !< DOUT2 Offset */
#define GPIO_DMAMASK_DOUT2_MASK                  ((uint32_t)0x00000004U)         /* !< DMA is allowed to modify DOUT2 */
#define GPIO_DMAMASK_DOUT2_DISABLE               ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT2_ENABLE                ((uint32_t)0x00000004U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT3] Bits */
#define GPIO_DMAMASK_DOUT3_OFS                   (3)                             /* !< DOUT3 Offset */
#define GPIO_DMAMASK_DOUT3_MASK                  ((uint32_t)0x00000008U)         /* !< DMA is allowed to modify DOUT3 */
#define GPIO_DMAMASK_DOUT3_DISABLE               ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT3_ENABLE                ((uint32_t)0x00000008U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT4] Bits */
#define GPIO_DMAMASK_DOUT4_OFS                   (4)                             /* !< DOUT4 Offset */
#define GPIO_DMAMASK_DOUT4_MASK                  ((uint32_t)0x00000010U)         /* !< DMA is allowed to modify DOUT4 */
#define GPIO_DMAMASK_DOUT4_DISABLE               ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT4_ENABLE                ((uint32_t)0x00000010U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT5] Bits */
#define GPIO_DMAMASK_DOUT5_OFS                   (5)                             /* !< DOUT5 Offset */
#define GPIO_DMAMASK_DOUT5_MASK                  ((uint32_t)0x00000020U)         /* !< DMA is allowed to modify DOUT5 */
#define GPIO_DMAMASK_DOUT5_DISABLE               ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT5_ENABLE                ((uint32_t)0x00000020U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT6] Bits */
#define GPIO_DMAMASK_DOUT6_OFS                   (6)                             /* !< DOUT6 Offset */
#define GPIO_DMAMASK_DOUT6_MASK                  ((uint32_t)0x00000040U)         /* !< DMA is allowed to modify DOUT6 */
#define GPIO_DMAMASK_DOUT6_DISABLE               ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT6_ENABLE                ((uint32_t)0x00000040U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT7] Bits */
#define GPIO_DMAMASK_DOUT7_OFS                   (7)                             /* !< DOUT7 Offset */
#define GPIO_DMAMASK_DOUT7_MASK                  ((uint32_t)0x00000080U)         /* !< DMA is allowed to modify DOUT7 */
#define GPIO_DMAMASK_DOUT7_DISABLE               ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT7_ENABLE                ((uint32_t)0x00000080U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT8] Bits */
#define GPIO_DMAMASK_DOUT8_OFS                   (8)                             /* !< DOUT8 Offset */
#define GPIO_DMAMASK_DOUT8_MASK                  ((uint32_t)0x00000100U)         /* !< DMA is allowed to modify DOUT8 */
#define GPIO_DMAMASK_DOUT8_DISABLE               ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT8_ENABLE                ((uint32_t)0x00000100U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT9] Bits */
#define GPIO_DMAMASK_DOUT9_OFS                   (9)                             /* !< DOUT9 Offset */
#define GPIO_DMAMASK_DOUT9_MASK                  ((uint32_t)0x00000200U)         /* !< DMA is allowed to modify DOUT9 */
#define GPIO_DMAMASK_DOUT9_DISABLE               ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT9_ENABLE                ((uint32_t)0x00000200U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT10] Bits */
#define GPIO_DMAMASK_DOUT10_OFS                  (10)                            /* !< DOUT10 Offset */
#define GPIO_DMAMASK_DOUT10_MASK                 ((uint32_t)0x00000400U)         /* !< DMA is allowed to modify DOUT10 */
#define GPIO_DMAMASK_DOUT10_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT10_ENABLE               ((uint32_t)0x00000400U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT11] Bits */
#define GPIO_DMAMASK_DOUT11_OFS                  (11)                            /* !< DOUT11 Offset */
#define GPIO_DMAMASK_DOUT11_MASK                 ((uint32_t)0x00000800U)         /* !< DMA is allowed to modify DOUT11 */
#define GPIO_DMAMASK_DOUT11_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT11_ENABLE               ((uint32_t)0x00000800U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT12] Bits */
#define GPIO_DMAMASK_DOUT12_OFS                  (12)                            /* !< DOUT12 Offset */
#define GPIO_DMAMASK_DOUT12_MASK                 ((uint32_t)0x00001000U)         /* !< DMA is allowed to modify DOUT12 */
#define GPIO_DMAMASK_DOUT12_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT12_ENABLE               ((uint32_t)0x00001000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT13] Bits */
#define GPIO_DMAMASK_DOUT13_OFS                  (13)                            /* !< DOUT13 Offset */
#define GPIO_DMAMASK_DOUT13_MASK                 ((uint32_t)0x00002000U)         /* !< DMA is allowed to modify DOUT13 */
#define GPIO_DMAMASK_DOUT13_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT13_ENABLE               ((uint32_t)0x00002000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT14] Bits */
#define GPIO_DMAMASK_DOUT14_OFS                  (14)                            /* !< DOUT14 Offset */
#define GPIO_DMAMASK_DOUT14_MASK                 ((uint32_t)0x00004000U)         /* !< DMA is allowed to modify DOUT14 */
#define GPIO_DMAMASK_DOUT14_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT14_ENABLE               ((uint32_t)0x00004000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT15] Bits */
#define GPIO_DMAMASK_DOUT15_OFS                  (15)                            /* !< DOUT15 Offset */
#define GPIO_DMAMASK_DOUT15_MASK                 ((uint32_t)0x00008000U)         /* !< DMA is allowed to modify DOUT15 */
#define GPIO_DMAMASK_DOUT15_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT15_ENABLE               ((uint32_t)0x00008000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT16] Bits */
#define GPIO_DMAMASK_DOUT16_OFS                  (16)                            /* !< DOUT16 Offset */
#define GPIO_DMAMASK_DOUT16_MASK                 ((uint32_t)0x00010000U)         /* !< DMA is allowed to modify DOUT16 */
#define GPIO_DMAMASK_DOUT16_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT16_ENABLE               ((uint32_t)0x00010000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT17] Bits */
#define GPIO_DMAMASK_DOUT17_OFS                  (17)                            /* !< DOUT17 Offset */
#define GPIO_DMAMASK_DOUT17_MASK                 ((uint32_t)0x00020000U)         /* !< DMA is allowed to modify DOUT17 */
#define GPIO_DMAMASK_DOUT17_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT17_ENABLE               ((uint32_t)0x00020000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT18] Bits */
#define GPIO_DMAMASK_DOUT18_OFS                  (18)                            /* !< DOUT18 Offset */
#define GPIO_DMAMASK_DOUT18_MASK                 ((uint32_t)0x00040000U)         /* !< DMA is allowed to modify DOUT18 */
#define GPIO_DMAMASK_DOUT18_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT18_ENABLE               ((uint32_t)0x00040000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT19] Bits */
#define GPIO_DMAMASK_DOUT19_OFS                  (19)                            /* !< DOUT19 Offset */
#define GPIO_DMAMASK_DOUT19_MASK                 ((uint32_t)0x00080000U)         /* !< DMA is allowed to modify DOUT19 */
#define GPIO_DMAMASK_DOUT19_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT19_ENABLE               ((uint32_t)0x00080000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT20] Bits */
#define GPIO_DMAMASK_DOUT20_OFS                  (20)                            /* !< DOUT20 Offset */
#define GPIO_DMAMASK_DOUT20_MASK                 ((uint32_t)0x00100000U)         /* !< DMA is allowed to modify DOUT20 */
#define GPIO_DMAMASK_DOUT20_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT20_ENABLE               ((uint32_t)0x00100000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT21] Bits */
#define GPIO_DMAMASK_DOUT21_OFS                  (21)                            /* !< DOUT21 Offset */
#define GPIO_DMAMASK_DOUT21_MASK                 ((uint32_t)0x00200000U)         /* !< DMA is allowed to modify DOUT21 */
#define GPIO_DMAMASK_DOUT21_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT21_ENABLE               ((uint32_t)0x00200000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT22] Bits */
#define GPIO_DMAMASK_DOUT22_OFS                  (22)                            /* !< DOUT22 Offset */
#define GPIO_DMAMASK_DOUT22_MASK                 ((uint32_t)0x00400000U)         /* !< DMA is allowed to modify DOUT22 */
#define GPIO_DMAMASK_DOUT22_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT22_ENABLE               ((uint32_t)0x00400000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT23] Bits */
#define GPIO_DMAMASK_DOUT23_OFS                  (23)                            /* !< DOUT23 Offset */
#define GPIO_DMAMASK_DOUT23_MASK                 ((uint32_t)0x00800000U)         /* !< DMA is allowed to modify DOUT23 */
#define GPIO_DMAMASK_DOUT23_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT23_ENABLE               ((uint32_t)0x00800000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT24] Bits */
#define GPIO_DMAMASK_DOUT24_OFS                  (24)                            /* !< DOUT24 Offset */
#define GPIO_DMAMASK_DOUT24_MASK                 ((uint32_t)0x01000000U)         /* !< DMA is allowed to modify DOUT24 */
#define GPIO_DMAMASK_DOUT24_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT24_ENABLE               ((uint32_t)0x01000000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT25] Bits */
#define GPIO_DMAMASK_DOUT25_OFS                  (25)                            /* !< DOUT25 Offset */
#define GPIO_DMAMASK_DOUT25_MASK                 ((uint32_t)0x02000000U)         /* !< DMA is allowed to modify DOUT25 */
#define GPIO_DMAMASK_DOUT25_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT25_ENABLE               ((uint32_t)0x02000000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT26] Bits */
#define GPIO_DMAMASK_DOUT26_OFS                  (26)                            /* !< DOUT26 Offset */
#define GPIO_DMAMASK_DOUT26_MASK                 ((uint32_t)0x04000000U)         /* !< DMA is allowed to modify DOUT26 */
#define GPIO_DMAMASK_DOUT26_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT26_ENABLE               ((uint32_t)0x04000000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT27] Bits */
#define GPIO_DMAMASK_DOUT27_OFS                  (27)                            /* !< DOUT27 Offset */
#define GPIO_DMAMASK_DOUT27_MASK                 ((uint32_t)0x08000000U)         /* !< DMA is allowed to modify DOUT27 */
#define GPIO_DMAMASK_DOUT27_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT27_ENABLE               ((uint32_t)0x08000000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT28] Bits */
#define GPIO_DMAMASK_DOUT28_OFS                  (28)                            /* !< DOUT28 Offset */
#define GPIO_DMAMASK_DOUT28_MASK                 ((uint32_t)0x10000000U)         /* !< DMA is allowed to modify DOUT28 */
#define GPIO_DMAMASK_DOUT28_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT28_ENABLE               ((uint32_t)0x10000000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT29] Bits */
#define GPIO_DMAMASK_DOUT29_OFS                  (29)                            /* !< DOUT29 Offset */
#define GPIO_DMAMASK_DOUT29_MASK                 ((uint32_t)0x20000000U)         /* !< DMA is allowed to modify DOUT29 */
#define GPIO_DMAMASK_DOUT29_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT29_ENABLE               ((uint32_t)0x20000000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT30] Bits */
#define GPIO_DMAMASK_DOUT30_OFS                  (30)                            /* !< DOUT30 Offset */
#define GPIO_DMAMASK_DOUT30_MASK                 ((uint32_t)0x40000000U)         /* !< DMA is allowed to modify DOUT30 */
#define GPIO_DMAMASK_DOUT30_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT30_ENABLE               ((uint32_t)0x40000000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */
/* GPIO_DMAMASK[DOUT31] Bits */
#define GPIO_DMAMASK_DOUT31_OFS                  (31)                            /* !< DOUT31 Offset */
#define GPIO_DMAMASK_DOUT31_MASK                 ((uint32_t)0x80000000U)         /* !< DMA is allowed to modify DOUT31 */
#define GPIO_DMAMASK_DOUT31_DISABLE              ((uint32_t)0x00000000U)         /* !< DMA is not allowed to modify this
                                                                                    bit lane */
#define GPIO_DMAMASK_DOUT31_ENABLE               ((uint32_t)0x80000000U)         /* !< DMA is allowed to modify this bit
                                                                                    lane */

/* GPIO_SUB1CFG Bits */
/* GPIO_SUB1CFG[ENABLE] Bits */
#define GPIO_SUB1CFG_ENABLE_OFS                  (0)                             /* !< ENABLE Offset */
#define GPIO_SUB1CFG_ENABLE_MASK                 ((uint32_t)0x00000001U)         /* !< This bit is used to enable
                                                                                    subscriber 1 event. */
#define GPIO_SUB1CFG_ENABLE_CLR                  ((uint32_t)0x00000000U)         /* !< Subscriber 1 event is disabled */
#define GPIO_SUB1CFG_ENABLE_SET                  ((uint32_t)0x00000001U)         /* !< Subscriber 1 event is enabled */
/* GPIO_SUB1CFG[OUTPOLICY] Bits */
#define GPIO_SUB1CFG_OUTPOLICY_OFS               (8)                             /* !< OUTPOLICY Offset */
#define GPIO_SUB1CFG_OUTPOLICY_MASK              ((uint32_t)0x00000300U)         /* !< These bits configure the output
                                                                                    policy for subscriber 1 event. */
#define GPIO_SUB1CFG_OUTPOLICY_SET               ((uint32_t)0x00000000U)         /* !< Selected DIO pins are set */
#define GPIO_SUB1CFG_OUTPOLICY_CLR               ((uint32_t)0x00000100U)         /* !< Selected DIO pins are cleared */
#define GPIO_SUB1CFG_OUTPOLICY_TOGGLE            ((uint32_t)0x00000200U)         /* !< Selected DIO pins are toggled */
/* GPIO_SUB1CFG[INDEX] Bits */
#define GPIO_SUB1CFG_INDEX_OFS                   (16)                            /* !< INDEX Offset */
#define GPIO_SUB1CFG_INDEX_MASK                  ((uint32_t)0x000F0000U)         /* !< indicates the specific bit in the
                                                                                    upper 16 bits that is targeted by the
                                                                                    subscriber action */
#define GPIO_SUB1CFG_INDEX_MIN                   ((uint32_t)0x00000000U)         /* !< specific bit targeted by the
                                                                                    subscriber action is bit16 */
#define GPIO_SUB1CFG_INDEX_MAX                   ((uint32_t)0x000F0000U)         /* !< specific bit targeted by the
                                                                                    subscriber action is bit31 */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_gpio__include */
