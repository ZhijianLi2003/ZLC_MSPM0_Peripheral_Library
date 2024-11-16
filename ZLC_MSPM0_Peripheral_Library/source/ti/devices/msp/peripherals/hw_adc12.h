/*****************************************************************************

  Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/

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

#ifndef ti_devices_msp_peripherals_hw_adc12__include
#define ti_devices_msp_peripherals_hw_adc12__include

/* Filename: hw_adc12.h */
/* Revised: 2024-02-04 23:18:52 */
/* Revision: 8d44a0380c79ed6c597a10a9f2b1bed57fc8b226 */

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
* ADC12 Registers
******************************************************************************/
#define ADC12_SVTMEM_OFS                         ((uint32_t)0x00000000U)
#define ADC12_DMA_TRIG_OFS                       ((uint32_t)0x00001080U)
#define ADC12_GEN_EVENT_OFS                      ((uint32_t)0x00001050U)
#define ADC12_CPU_INT_OFS                        ((uint32_t)0x00001020U)
#define ADC12_GPRCM_OFS                          ((uint32_t)0x00000800U)
#define ADC12_ULLMEM_OFS                         ((uint32_t)0x00000000U)


/** @addtogroup ADC12_SVTMEM
  @{
*/

typedef struct {
       uint32_t RESERVED0[88];
  __I  uint32_t FIFODATA;                          /* !< (@ 0x00000160) FIFO Data Register */
       uint32_t RESERVED1[71];
  __I  uint32_t MEMRES[24];                        /* !< (@ 0x00000280) Memory Result Register */
} ADC12_SVTMEM_Regs;

/*@}*/ /* end of group ADC12_SVTMEM */

/** @addtogroup ADC12_PERIPHERALREGIONSVT
  @{
*/

typedef struct {
  ADC12_SVTMEM_Regs  SVTMEM;                            /* !< (@ 0x00000000) */
} ADC12_PERIPHERALREGIONSVT_Regs;

/*@}*/ /* end of group ADC12_PERIPHERALREGIONSVT */

/** @addtogroup ADC12_DMA_TRIG
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001080) Interrupt index */
       uint32_t RESERVED0;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001088) Interrupt mask extension */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x00001090) Raw interrupt status extension */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x00001098) Masked interrupt status extension */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x000010A0) Interrupt set extension */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x000010A8) Interrupt clear extension */
} ADC12_DMA_TRIG_Regs;

/*@}*/ /* end of group ADC12_DMA_TRIG */

/** @addtogroup ADC12_GEN_EVENT
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
} ADC12_GEN_EVENT_Regs;

/*@}*/ /* end of group ADC12_GEN_EVENT */

/** @addtogroup ADC12_CPU_INT
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
} ADC12_CPU_INT_Regs;

/*@}*/ /* end of group ADC12_CPU_INT */

/** @addtogroup ADC12_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00000808) ADC clock configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} ADC12_GPRCM_Regs;

/*@}*/ /* end of group ADC12_GPRCM */

/** @addtogroup ADC12_ULLMEM
  @{
*/

typedef struct {
       uint32_t RESERVED0[256];
  __IO uint32_t FSUB_0;                            /* !< (@ 0x00000400) Subscriber Configuration Register. */
       uint32_t RESERVED1[16];
  __IO uint32_t FPUB_1;                            /* !< (@ 0x00000444) Publisher Configuration Register. */
       uint32_t RESERVED2[238];
  ADC12_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED3[514];
  ADC12_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED4;
  ADC12_GEN_EVENT_Regs  GEN_EVENT;                         /* !< (@ 0x00001050) */
       uint32_t RESERVED5;
  ADC12_DMA_TRIG_Regs  DMA_TRIG;                          /* !< (@ 0x00001080) */
       uint32_t RESERVED6[13];
  __I  uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED7[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
  __IO uint32_t CTL0;                              /* !< (@ 0x00001100) Control Register 0 */
  __IO uint32_t CTL1;                              /* !< (@ 0x00001104) Control Register 1 */
  __IO uint32_t CTL2;                              /* !< (@ 0x00001108) Control Register 2 */
       uint32_t RESERVED8;
  __IO uint32_t CLKFREQ;                           /* !< (@ 0x00001110) Sample Clock Frequency Range Register */
  __IO uint32_t SCOMP0;                            /* !< (@ 0x00001114) Sample Time Compare 0 Register */
  __IO uint32_t SCOMP1;                            /* !< (@ 0x00001118) Sample Time Compare 1 Register */
       uint32_t RESERVED9[11];
  __IO uint32_t WCLOW;                             /* !< (@ 0x00001148) Window Comparator Low Threshold Register */
       uint32_t RESERVED10;
  __IO uint32_t WCHIGH;                            /* !< (@ 0x00001150) Window Comparator High Threshold Register */
       uint32_t RESERVED11[3];
  __I  uint32_t FIFODATA;                          /* !< (@ 0x00001160) FIFO Data Register */
       uint32_t RESERVED12[7];
  __IO uint32_t MEMCTL[24];                        /* !< (@ 0x00001180) Conversion Memory Control Register */
       uint32_t RESERVED13[40];
  __I  uint32_t MEMRES[24];                        /* !< (@ 0x00001280) Memory Result Register */
       uint32_t RESERVED14[24];
  __I  uint32_t STATUS;                            /* !< (@ 0x00001340) Status Register */
} ADC12_ULLMEM_Regs;

/*@}*/ /* end of group ADC12_ULLMEM */

/** @addtogroup ADC12
  @{
*/

typedef struct {
  ADC12_ULLMEM_Regs  ULLMEM;                            /* !< (@ 0x00000000) */
} ADC12_Regs;

/*@}*/ /* end of group ADC12 */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* ADC12 Register Control Bits
******************************************************************************/

/* ADC12_PERIPHERALREGIONSVT_SVTMEM_FIFODATA Bits */
/* ADC12_PERIPHERALREGIONSVT_SVTMEM_FIFODATA[DATA] Bits */
#define ADC12_PERIPHERALREGIONSVT_SVTMEM_FIFODATA_DATA_OFS (0)                             /* !< DATA Offset */
#define ADC12_PERIPHERALREGIONSVT_SVTMEM_FIFODATA_DATA_MASK ((uint32_t)0xFFFFFFFFU)         /* !< Read from this data field returns
                                                                                    the ADC sample from FIFO. */

/* ADC12_PERIPHERALREGIONSVT_SVTMEM_MEMRES Bits */
/* ADC12_PERIPHERALREGIONSVT_SVTMEM_MEMRES[DATA] Bits */
#define ADC12_PERIPHERALREGIONSVT_SVTMEM_MEMRES_DATA_OFS (0)                             /* !< DATA Offset */
#define ADC12_PERIPHERALREGIONSVT_SVTMEM_MEMRES_DATA_MASK ((uint32_t)0x0000FFFFU)         /* !< MEMRES result register. If DF = 0,
                                                                                    unsigned binary: The conversion
                                                                                    results are right aligned. In 10 and
                                                                                    8 bit modes, the unused MSB bits are
                                                                                    forced to 0.  If DF = 1,
                                                                                    2s-complement format: The conversion
                                                                                    results are left aligned. In 10 and 8
                                                                                    bit modes, the unused LSB bits are
                                                                                    forced to 0. The data is stored in
                                                                                    the right-justified format and is
                                                                                    converted to the left-justified
                                                                                    2s-complement format during read
                                                                                    back. */

/* ADC12_DMA_TRIG_IIDX Bits */
/* ADC12_DMA_TRIG_IIDX[STAT] Bits */
#define ADC12_DMA_TRIG_IIDX_STAT_OFS             (0)                             /* !< STAT Offset */
#define ADC12_DMA_TRIG_IIDX_STAT_MASK            ((uint32_t)0x000003FFU)         /* !< Interrupt index status */
#define ADC12_DMA_TRIG_IIDX_STAT_NO_INTR         ((uint32_t)0x00000000U)         /* !< No bit is set means there is no
                                                                                    pending interrupt request */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG0      ((uint32_t)0x00000009U)         /* !< MEMRES0 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG1      ((uint32_t)0x0000000AU)         /* !< MEMRES1 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG2      ((uint32_t)0x0000000BU)         /* !< MEMRES2 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG3      ((uint32_t)0x0000000CU)         /* !< MEMRES3 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG4      ((uint32_t)0x0000000DU)         /* !< MEMRES4 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG5      ((uint32_t)0x0000000EU)         /* !< MEMRES5 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG6      ((uint32_t)0x0000000FU)         /* !< MEMRES6 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG7      ((uint32_t)0x00000010U)         /* !< MEMRES7 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG8      ((uint32_t)0x00000011U)         /* !< MEMRES8 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG9      ((uint32_t)0x00000012U)         /* !< MEMRES9 data  loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG10     ((uint32_t)0x00000013U)         /* !< MEMRES10 data  loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG11     ((uint32_t)0x00000014U)         /* !< MEMRES11 data  loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG12     ((uint32_t)0x00000015U)         /* !< MEMRES12 data  loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG13     ((uint32_t)0x00000016U)         /* !< MEMRES13 data  loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG14     ((uint32_t)0x00000017U)         /* !< MEMRES14 data  loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG15     ((uint32_t)0x00000018U)         /* !< MEMRES15 data  loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG16     ((uint32_t)0x00000019U)         /* !< MEMRES16 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG17     ((uint32_t)0x0000001AU)         /* !< MEMRES17 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG18     ((uint32_t)0x0000001BU)         /* !< MEMRES18 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG19     ((uint32_t)0x0000001CU)         /* !< MEMRES19 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG20     ((uint32_t)0x0000001DU)         /* !< MEMRES20 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG21     ((uint32_t)0x0000001EU)         /* !< MEMRES21 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG22     ((uint32_t)0x0000001FU)         /* !< MEMRES22 data loaded interrupt */
#define ADC12_DMA_TRIG_IIDX_STAT_MEMRESIFG23     ((uint32_t)0x00000020U)         /* !< MEMRES23 data loaded interrupt */

/* ADC12_DMA_TRIG_IMASK Bits */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG0] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG0_OFS      (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG0_MASK     ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG0_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG0_SET      ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG1] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG1_OFS      (9)                             /* !< MEMRESIFG1 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG1_MASK     ((uint32_t)0x00000200U)         /* !< Raw interrupt status for MEMRES1.
                                                                                    This bit is set to 1 when MEMRES1 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES1 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG1_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG1_SET      ((uint32_t)0x00000200U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG2] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG2_OFS      (10)                            /* !< MEMRESIFG2 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG2_MASK     ((uint32_t)0x00000400U)         /* !< Raw interrupt status for MEMRES2.
                                                                                    This bit is set to 1 when MEMRES2 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES2 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG2_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG2_SET      ((uint32_t)0x00000400U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG3] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG3_OFS      (11)                            /* !< MEMRESIFG3 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG3_MASK     ((uint32_t)0x00000800U)         /* !< Raw interrupt status for MEMRES3.
                                                                                    This bit is set to 1 when MEMRES3 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES3 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG3_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG3_SET      ((uint32_t)0x00000800U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG4] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG4_OFS      (12)                            /* !< MEMRESIFG4 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG4_MASK     ((uint32_t)0x00001000U)         /* !< Raw interrupt status for MEMRES4.
                                                                                    This bit is set to 1 when MEMRES4 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES4 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG4_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG4_SET      ((uint32_t)0x00001000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG5] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG5_OFS      (13)                            /* !< MEMRESIFG5 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG5_MASK     ((uint32_t)0x00002000U)         /* !< Raw interrupt status for MEMRES5.
                                                                                    This bit is set to 1 when MEMRES5 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES5 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG5_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG5_SET      ((uint32_t)0x00002000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG6] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG6_OFS      (14)                            /* !< MEMRESIFG6 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG6_MASK     ((uint32_t)0x00004000U)         /* !< Raw interrupt status for MEMRES6.
                                                                                    This bit is set to 1 when MEMRES6 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES6 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG6_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG6_SET      ((uint32_t)0x00004000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG7] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG7_OFS      (15)                            /* !< MEMRESIFG7 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG7_MASK     ((uint32_t)0x00008000U)         /* !< Raw interrupt status for MEMRES7.
                                                                                    This bit is set to 1 when MEMRES7 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES7 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG7_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG7_SET      ((uint32_t)0x00008000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG9] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG9_OFS      (17)                            /* !< MEMRESIFG9 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG9_MASK     ((uint32_t)0x00020000U)         /* !< Raw interrupt status for MEMRES9.
                                                                                    This bit is set to 1 when MEMRES9 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES9 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG9_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG9_SET      ((uint32_t)0x00020000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG10] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG10_OFS     (18)                            /* !< MEMRESIFG10 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG10_MASK    ((uint32_t)0x00040000U)         /* !< Raw interrupt status for MEMRES10.
                                                                                    This bit is set to 1 when MEMRES10 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES10 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG10_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG10_SET     ((uint32_t)0x00040000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG11] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG11_OFS     (19)                            /* !< MEMRESIFG11 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG11_MASK    ((uint32_t)0x00080000U)         /* !< Raw interrupt status for MEMRES11.
                                                                                    This bit is set to 1 when MEMRES11 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES11 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG11_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG11_SET     ((uint32_t)0x00080000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG12] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG12_OFS     (20)                            /* !< MEMRESIFG12 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG12_MASK    ((uint32_t)0x00100000U)         /* !< Raw interrupt status for MEMRES12.
                                                                                    This bit is set to 1 when MEMRES12 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES12 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG12_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG12_SET     ((uint32_t)0x00100000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG13] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG13_OFS     (21)                            /* !< MEMRESIFG13 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG13_MASK    ((uint32_t)0x00200000U)         /* !< Raw interrupt status for MEMRES13.
                                                                                    This bit is set to 1 when MEMRES13 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES13 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG13_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG13_SET     ((uint32_t)0x00200000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG14] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG14_OFS     (22)                            /* !< MEMRESIFG14 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG14_MASK    ((uint32_t)0x00400000U)         /* !< Raw interrupt status for MEMRES14.
                                                                                    This bit is set to 1 when MEMRES14 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES14 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG14_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG14_SET     ((uint32_t)0x00400000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG15] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG15_OFS     (23)                            /* !< MEMRESIFG15 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG15_MASK    ((uint32_t)0x00800000U)         /* !< Raw interrupt status for MEMRES15.
                                                                                    This bit is set to 1 when MEMRES15 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES15 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG15_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG15_SET     ((uint32_t)0x00800000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG16] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG16_OFS     (24)                            /* !< MEMRESIFG16 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG16_MASK    ((uint32_t)0x01000000U)         /* !< Raw interrupt status for MEMRES16.
                                                                                    This bit is set to 1 when MEMRES16 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES16 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG16_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG16_SET     ((uint32_t)0x01000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG17] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG17_OFS     (25)                            /* !< MEMRESIFG17 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG17_MASK    ((uint32_t)0x02000000U)         /* !< Raw interrupt status for MEMRES17.
                                                                                    This bit is set to 1 when MEMRES17 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES17 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG17_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG17_SET     ((uint32_t)0x02000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG18] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG18_OFS     (26)                            /* !< MEMRESIFG18 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG18_MASK    ((uint32_t)0x04000000U)         /* !< Raw interrupt status for MEMRES18.
                                                                                    This bit is set to 1 when MEMRES18 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES18 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG18_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG18_SET     ((uint32_t)0x04000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG19] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG19_OFS     (27)                            /* !< MEMRESIFG19 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG19_MASK    ((uint32_t)0x08000000U)         /* !< Raw interrupt status for MEMRES19.
                                                                                    This bit is set to 1 when MEMRES19 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES19 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG19_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG19_SET     ((uint32_t)0x08000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG20] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG20_OFS     (28)                            /* !< MEMRESIFG20 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG20_MASK    ((uint32_t)0x10000000U)         /* !< Raw interrupt status for MEMRES20.
                                                                                    This bit is set to 1 when MEMRES20 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES20 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG20_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG20_SET     ((uint32_t)0x10000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG22] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG22_OFS     (30)                            /* !< MEMRESIFG22 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG22_MASK    ((uint32_t)0x40000000U)         /* !< Raw interrupt status for MEMRES22.
                                                                                    This bit is set to 1 when MEMRES22 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES22 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG22_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG22_SET     ((uint32_t)0x40000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG23] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG23_OFS     (31)                            /* !< MEMRESIFG23 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG23_MASK    ((uint32_t)0x80000000U)         /* !< Raw interrupt status for MEMRES23.
                                                                                    This bit is set to 1 when MEMRES23 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES23 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG23_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG23_SET     ((uint32_t)0x80000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG8] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG8_OFS      (16)                            /* !< MEMRESIFG8 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG8_MASK     ((uint32_t)0x00010000U)         /* !< Raw interrupt status for MEMRES8.
                                                                                    This bit is set to 1 when MEMRES8 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES8 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG8_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG8_SET      ((uint32_t)0x00010000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_IMASK[MEMRESIFG21] Bits */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG21_OFS     (29)                            /* !< MEMRESIFG21 Offset */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG21_MASK    ((uint32_t)0x20000000U)         /* !< Raw interrupt status for MEMRES21.
                                                                                    This bit is set to 1 when MEMRES21 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES21 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG21_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_IMASK_MEMRESIFG21_SET     ((uint32_t)0x20000000U)         /* !< A new data is ready to be read. */

/* ADC12_DMA_TRIG_RIS Bits */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG0] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG0_OFS        (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG0_MASK       ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG0_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG0_SET        ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG1] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG1_OFS        (9)                             /* !< MEMRESIFG1 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG1_MASK       ((uint32_t)0x00000200U)         /* !< Raw interrupt status for MEMRES1.
                                                                                    This bit is set to 1 when MEMRES1 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES1 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG1_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG1_SET        ((uint32_t)0x00000200U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG2] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG2_OFS        (10)                            /* !< MEMRESIFG2 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG2_MASK       ((uint32_t)0x00000400U)         /* !< Raw interrupt status for MEMRES2.
                                                                                    This bit is set to 1 when MEMRES2 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES2 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG2_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG2_SET        ((uint32_t)0x00000400U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG3] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG3_OFS        (11)                            /* !< MEMRESIFG3 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG3_MASK       ((uint32_t)0x00000800U)         /* !< Raw interrupt status for MEMRES3.
                                                                                    This bit is set to 1 when MEMRES3 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES3 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG3_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG3_SET        ((uint32_t)0x00000800U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG4] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG4_OFS        (12)                            /* !< MEMRESIFG4 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG4_MASK       ((uint32_t)0x00001000U)         /* !< Raw interrupt status for MEMRES4.
                                                                                    This bit is set to 1 when MEMRES4 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES4 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG4_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG4_SET        ((uint32_t)0x00001000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG5] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG5_OFS        (13)                            /* !< MEMRESIFG5 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG5_MASK       ((uint32_t)0x00002000U)         /* !< Raw interrupt status for MEMRES5.
                                                                                    This bit is set to 1 when MEMRES5 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES5 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG5_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG5_SET        ((uint32_t)0x00002000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG6] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG6_OFS        (14)                            /* !< MEMRESIFG6 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG6_MASK       ((uint32_t)0x00004000U)         /* !< Raw interrupt status for MEMRES6.
                                                                                    This bit is set to 1 when MEMRES6 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES6 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG6_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG6_SET        ((uint32_t)0x00004000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG7] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG7_OFS        (15)                            /* !< MEMRESIFG7 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG7_MASK       ((uint32_t)0x00008000U)         /* !< Raw interrupt status for MEMRES7.
                                                                                    This bit is set to 1 when MEMRES7 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES7 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG7_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG7_SET        ((uint32_t)0x00008000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG9] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG9_OFS        (17)                            /* !< MEMRESIFG9 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG9_MASK       ((uint32_t)0x00020000U)         /* !< Raw interrupt status for MEMRES9.
                                                                                    This bit is set to 1 when MEMRES9 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES9 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG9_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG9_SET        ((uint32_t)0x00020000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG10] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG10_OFS       (18)                            /* !< MEMRESIFG10 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG10_MASK      ((uint32_t)0x00040000U)         /* !< Raw interrupt status for MEMRES10.
                                                                                    This bit is set to 1 when MEMRES10 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES10 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG10_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG10_SET       ((uint32_t)0x00040000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG11] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG11_OFS       (19)                            /* !< MEMRESIFG11 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG11_MASK      ((uint32_t)0x00080000U)         /* !< Raw interrupt status for MEMRES11.
                                                                                    This bit is set to 1 when MEMRES11 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES11 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG11_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG11_SET       ((uint32_t)0x00080000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG12] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG12_OFS       (20)                            /* !< MEMRESIFG12 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG12_MASK      ((uint32_t)0x00100000U)         /* !< Raw interrupt status for MEMRES12.
                                                                                    This bit is set to 1 when MEMRES12 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES12 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG12_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG12_SET       ((uint32_t)0x00100000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG13] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG13_OFS       (21)                            /* !< MEMRESIFG13 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG13_MASK      ((uint32_t)0x00200000U)         /* !< Raw interrupt status for MEMRES13.
                                                                                    This bit is set to 1 when MEMRES13 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES13 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG13_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG13_SET       ((uint32_t)0x00200000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG14] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG14_OFS       (22)                            /* !< MEMRESIFG14 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG14_MASK      ((uint32_t)0x00400000U)         /* !< Raw interrupt status for MEMRES14.
                                                                                    This bit is set to 1 when MEMRES14 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES14 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG14_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG14_SET       ((uint32_t)0x00400000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG15] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG15_OFS       (23)                            /* !< MEMRESIFG15 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG15_MASK      ((uint32_t)0x00800000U)         /* !< Raw interrupt status for MEMRES15.
                                                                                    This bit is set to 1 when MEMRES15 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES15 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG15_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG15_SET       ((uint32_t)0x00800000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG16] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG16_OFS       (24)                            /* !< MEMRESIFG16 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG16_MASK      ((uint32_t)0x01000000U)         /* !< Raw interrupt status for MEMRES16.
                                                                                    This bit is set to 1 when MEMRES16 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES16 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG16_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG16_SET       ((uint32_t)0x01000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG17] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG17_OFS       (25)                            /* !< MEMRESIFG17 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG17_MASK      ((uint32_t)0x02000000U)         /* !< Raw interrupt status for MEMRES17.
                                                                                    This bit is set to 1 when MEMRES17 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES17 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG17_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG17_SET       ((uint32_t)0x02000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG18] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG18_OFS       (26)                            /* !< MEMRESIFG18 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG18_MASK      ((uint32_t)0x04000000U)         /* !< Raw interrupt status for MEMRES18.
                                                                                    This bit is set to 1 when MEMRES18 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES18 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG18_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG18_SET       ((uint32_t)0x04000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG19] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG19_OFS       (27)                            /* !< MEMRESIFG19 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG19_MASK      ((uint32_t)0x08000000U)         /* !< Raw interrupt status for MEMRES19.
                                                                                    This bit is set to 1 when MEMRES19 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES19 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG19_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG19_SET       ((uint32_t)0x08000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG20] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG20_OFS       (28)                            /* !< MEMRESIFG20 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG20_MASK      ((uint32_t)0x10000000U)         /* !< Raw interrupt status for MEMRES20.
                                                                                    This bit is set to 1 when MEMRES20 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES20 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG20_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG20_SET       ((uint32_t)0x10000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG22] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG22_OFS       (30)                            /* !< MEMRESIFG22 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG22_MASK      ((uint32_t)0x40000000U)         /* !< Raw interrupt status for MEMRES22.
                                                                                    This bit is set to 1 when MEMRES22 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES22 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG22_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG22_SET       ((uint32_t)0x40000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG23] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG23_OFS       (31)                            /* !< MEMRESIFG23 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG23_MASK      ((uint32_t)0x80000000U)         /* !< Raw interrupt status for MEMRES23.
                                                                                    This bit is set to 1 when MEMRES23 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES23 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG23_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG23_SET       ((uint32_t)0x80000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG8] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG8_OFS        (16)                            /* !< MEMRESIFG8 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG8_MASK       ((uint32_t)0x00010000U)         /* !< Raw interrupt status for MEMRES8.
                                                                                    This bit is set to 1 when MEMRES8 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES8 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG8_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG8_SET        ((uint32_t)0x00010000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_RIS[MEMRESIFG21] Bits */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG21_OFS       (29)                            /* !< MEMRESIFG21 Offset */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG21_MASK      ((uint32_t)0x20000000U)         /* !< Raw interrupt status for MEMRES21.
                                                                                    This bit is set to 1 when MEMRES21 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES21 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG21_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_RIS_MEMRESIFG21_SET       ((uint32_t)0x20000000U)         /* !< A new data is ready to be read. */

/* ADC12_DMA_TRIG_MIS Bits */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG0] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG0_OFS        (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG0_MASK       ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG0_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG0_SET        ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG1] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG1_OFS        (9)                             /* !< MEMRESIFG1 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG1_MASK       ((uint32_t)0x00000200U)         /* !< Raw interrupt status for MEMRES1.
                                                                                    This bit is set to 1 when MEMRES1 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES1 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG1_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG1_SET        ((uint32_t)0x00000200U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG2] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG2_OFS        (10)                            /* !< MEMRESIFG2 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG2_MASK       ((uint32_t)0x00000400U)         /* !< Raw interrupt status for MEMRES2.
                                                                                    This bit is set to 1 when MEMRES2 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES2 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG2_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG2_SET        ((uint32_t)0x00000400U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG3] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG3_OFS        (11)                            /* !< MEMRESIFG3 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG3_MASK       ((uint32_t)0x00000800U)         /* !< Raw interrupt status for MEMRES3.
                                                                                    This bit is set to 1 when MEMRES3 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES3 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG3_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG3_SET        ((uint32_t)0x00000800U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG4] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG4_OFS        (12)                            /* !< MEMRESIFG4 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG4_MASK       ((uint32_t)0x00001000U)         /* !< Raw interrupt status for MEMRES4.
                                                                                    This bit is set to 1 when MEMRES4 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES4 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG4_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG4_SET        ((uint32_t)0x00001000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG5] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG5_OFS        (13)                            /* !< MEMRESIFG5 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG5_MASK       ((uint32_t)0x00002000U)         /* !< Raw interrupt status for MEMRES5.
                                                                                    This bit is set to 1 when MEMRES5 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES5 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG5_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG5_SET        ((uint32_t)0x00002000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG6] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG6_OFS        (14)                            /* !< MEMRESIFG6 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG6_MASK       ((uint32_t)0x00004000U)         /* !< Raw interrupt status for MEMRES6.
                                                                                    This bit is set to 1 when MEMRES6 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES6 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG6_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG6_SET        ((uint32_t)0x00004000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG7] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG7_OFS        (15)                            /* !< MEMRESIFG7 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG7_MASK       ((uint32_t)0x00008000U)         /* !< Raw interrupt status for MEMRES7.
                                                                                    This bit is set to 1 when MEMRES7 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES7 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG7_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG7_SET        ((uint32_t)0x00008000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG9] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG9_OFS        (17)                            /* !< MEMRESIFG9 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG9_MASK       ((uint32_t)0x00020000U)         /* !< Raw interrupt status for MEMRES9.
                                                                                    This bit is set to 1 when MEMRES9 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES9 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG9_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG9_SET        ((uint32_t)0x00020000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG10] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG10_OFS       (18)                            /* !< MEMRESIFG10 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG10_MASK      ((uint32_t)0x00040000U)         /* !< Raw interrupt status for MEMRES10.
                                                                                    This bit is set to 1 when MEMRES10 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES10 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG10_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG10_SET       ((uint32_t)0x00040000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG11] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG11_OFS       (19)                            /* !< MEMRESIFG11 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG11_MASK      ((uint32_t)0x00080000U)         /* !< Raw interrupt status for MEMRES11.
                                                                                    This bit is set to 1 when MEMRES11 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES11 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG11_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG11_SET       ((uint32_t)0x00080000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG12] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG12_OFS       (20)                            /* !< MEMRESIFG12 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG12_MASK      ((uint32_t)0x00100000U)         /* !< Raw interrupt status for MEMRES12.
                                                                                    This bit is set to 1 when MEMRES12 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES12 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG12_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG12_SET       ((uint32_t)0x00100000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG13] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG13_OFS       (21)                            /* !< MEMRESIFG13 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG13_MASK      ((uint32_t)0x00200000U)         /* !< Raw interrupt status for MEMRES13.
                                                                                    This bit is set to 1 when MEMRES13 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES13 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG13_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG13_SET       ((uint32_t)0x00200000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG14] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG14_OFS       (22)                            /* !< MEMRESIFG14 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG14_MASK      ((uint32_t)0x00400000U)         /* !< Raw interrupt status for MEMRES14.
                                                                                    This bit is set to 1 when MEMRES14 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES14 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG14_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG14_SET       ((uint32_t)0x00400000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG15] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG15_OFS       (23)                            /* !< MEMRESIFG15 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG15_MASK      ((uint32_t)0x00800000U)         /* !< Raw interrupt status for MEMRES15.
                                                                                    This bit is set to 1 when MEMRES15 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES15 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG15_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG15_SET       ((uint32_t)0x00800000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG16] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG16_OFS       (24)                            /* !< MEMRESIFG16 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG16_MASK      ((uint32_t)0x01000000U)         /* !< Raw interrupt status for MEMRES16.
                                                                                    This bit is set to 1 when MEMRES16 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES16 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG16_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG16_SET       ((uint32_t)0x01000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG17] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG17_OFS       (25)                            /* !< MEMRESIFG17 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG17_MASK      ((uint32_t)0x02000000U)         /* !< Raw interrupt status for MEMRES17.
                                                                                    This bit is set to 1 when MEMRES17 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES17 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG17_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG17_SET       ((uint32_t)0x02000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG18] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG18_OFS       (26)                            /* !< MEMRESIFG18 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG18_MASK      ((uint32_t)0x04000000U)         /* !< Raw interrupt status for MEMRES18.
                                                                                    This bit is set to 1 when MEMRES18 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES18 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG18_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG18_SET       ((uint32_t)0x04000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG19] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG19_OFS       (27)                            /* !< MEMRESIFG19 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG19_MASK      ((uint32_t)0x08000000U)         /* !< Raw interrupt status for MEMRES19.
                                                                                    This bit is set to 1 when MEMRES19 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES19 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG19_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG19_SET       ((uint32_t)0x08000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG20] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG20_OFS       (28)                            /* !< MEMRESIFG20 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG20_MASK      ((uint32_t)0x10000000U)         /* !< Raw interrupt status for MEMRES20.
                                                                                    This bit is set to 1 when MEMRES20 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES20 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG20_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG20_SET       ((uint32_t)0x10000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG22] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG22_OFS       (30)                            /* !< MEMRESIFG22 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG22_MASK      ((uint32_t)0x40000000U)         /* !< Raw interrupt status for MEMRES22.
                                                                                    This bit is set to 1 when MEMRES22 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES22 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG22_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG22_SET       ((uint32_t)0x40000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG23] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG23_OFS       (31)                            /* !< MEMRESIFG23 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG23_MASK      ((uint32_t)0x80000000U)         /* !< Raw interrupt status for MEMRES23.
                                                                                    This bit is set to 1 when MEMRES23 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES23 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG23_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG23_SET       ((uint32_t)0x80000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG8] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG8_OFS        (16)                            /* !< MEMRESIFG8 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG8_MASK       ((uint32_t)0x00010000U)         /* !< Raw interrupt status for MEMRES8.
                                                                                    This bit is set to 1 when MEMRES8 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES8 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG8_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG8_SET        ((uint32_t)0x00010000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_MIS[MEMRESIFG21] Bits */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG21_OFS       (29)                            /* !< MEMRESIFG21 Offset */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG21_MASK      ((uint32_t)0x20000000U)         /* !< Raw interrupt status for MEMRES21.
                                                                                    This bit is set to 1 when MEMRES21 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES21 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG21_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_MIS_MEMRESIFG21_SET       ((uint32_t)0x20000000U)         /* !< A new data is ready to be read. */

/* ADC12_DMA_TRIG_ISET Bits */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG0] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG0_OFS       (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG0_MASK      ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG0_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG0_SET       ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG1] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG1_OFS       (9)                             /* !< MEMRESIFG1 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG1_MASK      ((uint32_t)0x00000200U)         /* !< Raw interrupt status for MEMRES1.
                                                                                    This bit is set to 1 when MEMRES1 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES1 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG1_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG1_SET       ((uint32_t)0x00000200U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG2] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG2_OFS       (10)                            /* !< MEMRESIFG2 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG2_MASK      ((uint32_t)0x00000400U)         /* !< Raw interrupt status for MEMRES2.
                                                                                    This bit is set to 1 when MEMRES2 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES2 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG2_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG2_SET       ((uint32_t)0x00000400U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG3] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG3_OFS       (11)                            /* !< MEMRESIFG3 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG3_MASK      ((uint32_t)0x00000800U)         /* !< Raw interrupt status for MEMRES3.
                                                                                    This bit is set to 1 when MEMRES3 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES3 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG3_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG3_SET       ((uint32_t)0x00000800U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG4] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG4_OFS       (12)                            /* !< MEMRESIFG4 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG4_MASK      ((uint32_t)0x00001000U)         /* !< Raw interrupt status for MEMRES4.
                                                                                    This bit is set to 1 when MEMRES4 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES4 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG4_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG4_SET       ((uint32_t)0x00001000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG5] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG5_OFS       (13)                            /* !< MEMRESIFG5 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG5_MASK      ((uint32_t)0x00002000U)         /* !< Raw interrupt status for MEMRES5.
                                                                                    This bit is set to 1 when MEMRES5 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES5 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG5_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG5_SET       ((uint32_t)0x00002000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG6] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG6_OFS       (14)                            /* !< MEMRESIFG6 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG6_MASK      ((uint32_t)0x00004000U)         /* !< Raw interrupt status for MEMRES6.
                                                                                    This bit is set to 1 when MEMRES6 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES6 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG6_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG6_SET       ((uint32_t)0x00004000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG7] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG7_OFS       (15)                            /* !< MEMRESIFG7 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG7_MASK      ((uint32_t)0x00008000U)         /* !< Raw interrupt status for MEMRES7.
                                                                                    This bit is set to 1 when MEMRES7 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES7 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG7_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG7_SET       ((uint32_t)0x00008000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG9] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG9_OFS       (17)                            /* !< MEMRESIFG9 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG9_MASK      ((uint32_t)0x00020000U)         /* !< Raw interrupt status for MEMRES9.
                                                                                    This bit is set to 1 when MEMRES9 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES9 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG9_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG9_SET       ((uint32_t)0x00020000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG10] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG10_OFS      (18)                            /* !< MEMRESIFG10 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG10_MASK     ((uint32_t)0x00040000U)         /* !< Raw interrupt status for MEMRES10.
                                                                                    This bit is set to 1 when MEMRES10 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES10 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG10_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG10_SET      ((uint32_t)0x00040000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG11] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG11_OFS      (19)                            /* !< MEMRESIFG11 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG11_MASK     ((uint32_t)0x00080000U)         /* !< Raw interrupt status for MEMRES11.
                                                                                    This bit is set to 1 when MEMRES11 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES11 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG11_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG11_SET      ((uint32_t)0x00080000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG12] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG12_OFS      (20)                            /* !< MEMRESIFG12 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG12_MASK     ((uint32_t)0x00100000U)         /* !< Raw interrupt status for MEMRES12.
                                                                                    This bit is set to 1 when MEMRES12 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES12 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG12_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG12_SET      ((uint32_t)0x00100000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG13] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG13_OFS      (21)                            /* !< MEMRESIFG13 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG13_MASK     ((uint32_t)0x00200000U)         /* !< Raw interrupt status for MEMRES13.
                                                                                    This bit is set to 1 when MEMRES13 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES13 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG13_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG13_SET      ((uint32_t)0x00200000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG14] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG14_OFS      (22)                            /* !< MEMRESIFG14 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG14_MASK     ((uint32_t)0x00400000U)         /* !< Raw interrupt status for MEMRES14.
                                                                                    This bit is set to 1 when MEMRES14 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES14 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG14_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG14_SET      ((uint32_t)0x00400000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG15] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG15_OFS      (23)                            /* !< MEMRESIFG15 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG15_MASK     ((uint32_t)0x00800000U)         /* !< Raw interrupt status for MEMRES15.
                                                                                    This bit is set to 1 when MEMRES15 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES15 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG15_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG15_SET      ((uint32_t)0x00800000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG16] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG16_OFS      (24)                            /* !< MEMRESIFG16 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG16_MASK     ((uint32_t)0x01000000U)         /* !< Raw interrupt status for MEMRES16.
                                                                                    This bit is set to 1 when MEMRES16 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES16 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG16_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG16_SET      ((uint32_t)0x01000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG17] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG17_OFS      (25)                            /* !< MEMRESIFG17 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG17_MASK     ((uint32_t)0x02000000U)         /* !< Raw interrupt status for MEMRES17.
                                                                                    This bit is set to 1 when MEMRES17 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES17 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG17_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG17_SET      ((uint32_t)0x02000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG18] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG18_OFS      (26)                            /* !< MEMRESIFG18 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG18_MASK     ((uint32_t)0x04000000U)         /* !< Raw interrupt status for MEMRES18.
                                                                                    This bit is set to 1 when MEMRES18 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES18 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG18_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG18_SET      ((uint32_t)0x04000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG19] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG19_OFS      (27)                            /* !< MEMRESIFG19 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG19_MASK     ((uint32_t)0x08000000U)         /* !< Raw interrupt status for MEMRES19.
                                                                                    This bit is set to 1 when MEMRES19 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES19 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG19_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG19_SET      ((uint32_t)0x08000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG20] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG20_OFS      (28)                            /* !< MEMRESIFG20 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG20_MASK     ((uint32_t)0x10000000U)         /* !< Raw interrupt status for MEMRES20.
                                                                                    This bit is set to 1 when MEMRES20 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES20 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG20_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG20_SET      ((uint32_t)0x10000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG22] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG22_OFS      (30)                            /* !< MEMRESIFG22 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG22_MASK     ((uint32_t)0x40000000U)         /* !< Raw interrupt status for MEMRES22.
                                                                                    This bit is set to 1 when MEMRES22 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES22 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG22_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG22_SET      ((uint32_t)0x40000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG23] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG23_OFS      (31)                            /* !< MEMRESIFG23 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG23_MASK     ((uint32_t)0x80000000U)         /* !< Raw interrupt status for MEMRES23.
                                                                                    This bit is set to 1 when MEMRES23 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES23 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG23_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG23_SET      ((uint32_t)0x80000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG8] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG8_OFS       (16)                            /* !< MEMRESIFG8 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG8_MASK      ((uint32_t)0x00010000U)         /* !< Raw interrupt status for MEMRES8.
                                                                                    This bit is set to 1 when MEMRES8 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES8 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG8_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG8_SET       ((uint32_t)0x00010000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ISET[MEMRESIFG21] Bits */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG21_OFS      (29)                            /* !< MEMRESIFG21 Offset */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG21_MASK     ((uint32_t)0x20000000U)         /* !< Raw interrupt status for MEMRES21.
                                                                                    This bit is set to 1 when MEMRES21 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES21 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG21_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ISET_MEMRESIFG21_SET      ((uint32_t)0x20000000U)         /* !< A new data is ready to be read. */

/* ADC12_DMA_TRIG_ICLR Bits */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG0] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG0_OFS       (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG0_MASK      ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG0_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG0_CLR       ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG1] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG1_OFS       (9)                             /* !< MEMRESIFG1 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG1_MASK      ((uint32_t)0x00000200U)         /* !< Raw interrupt status for MEMRES1.
                                                                                    This bit is set to 1 when MEMRES1 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES1 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG1_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG1_CLR       ((uint32_t)0x00000200U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG2] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG2_OFS       (10)                            /* !< MEMRESIFG2 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG2_MASK      ((uint32_t)0x00000400U)         /* !< Raw interrupt status for MEMRES2.
                                                                                    This bit is set to 1 when MEMRES2 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES2 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG2_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG2_CLR       ((uint32_t)0x00000400U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG3] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG3_OFS       (11)                            /* !< MEMRESIFG3 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG3_MASK      ((uint32_t)0x00000800U)         /* !< Raw interrupt status for MEMRES3.
                                                                                    This bit is set to 1 when MEMRES3 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES3 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG3_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG3_CLR       ((uint32_t)0x00000800U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG4] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG4_OFS       (12)                            /* !< MEMRESIFG4 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG4_MASK      ((uint32_t)0x00001000U)         /* !< Raw interrupt status for MEMRES4.
                                                                                    This bit is set to 1 when MEMRES4 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES4 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG4_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG4_CLR       ((uint32_t)0x00001000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG5] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG5_OFS       (13)                            /* !< MEMRESIFG5 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG5_MASK      ((uint32_t)0x00002000U)         /* !< Raw interrupt status for MEMRES5.
                                                                                    This bit is set to 1 when MEMRES5 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES5 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG5_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG5_CLR       ((uint32_t)0x00002000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG6] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG6_OFS       (14)                            /* !< MEMRESIFG6 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG6_MASK      ((uint32_t)0x00004000U)         /* !< Raw interrupt status for MEMRES6.
                                                                                    This bit is set to 1 when MEMRES6 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES6 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG6_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG6_CLR       ((uint32_t)0x00004000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG7] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG7_OFS       (15)                            /* !< MEMRESIFG7 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG7_MASK      ((uint32_t)0x00008000U)         /* !< Raw interrupt status for MEMRES7.
                                                                                    This bit is set to 1 when MEMRES7 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES7 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG7_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG7_CLR       ((uint32_t)0x00008000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG9] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG9_OFS       (17)                            /* !< MEMRESIFG9 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG9_MASK      ((uint32_t)0x00020000U)         /* !< Raw interrupt status for MEMRES9.
                                                                                    This bit is set to 1 when MEMRES9 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES9 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG9_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG9_CLR       ((uint32_t)0x00020000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG10] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG10_OFS      (18)                            /* !< MEMRESIFG10 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG10_MASK     ((uint32_t)0x00040000U)         /* !< Raw interrupt status for MEMRES10.
                                                                                    This bit is set to 1 when MEMRES10 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES10 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG10_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG10_CLR      ((uint32_t)0x00040000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG11] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG11_OFS      (19)                            /* !< MEMRESIFG11 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG11_MASK     ((uint32_t)0x00080000U)         /* !< Raw interrupt status for MEMRES11.
                                                                                    This bit is set to 1 when MEMRES11 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES11 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG11_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG11_CLR      ((uint32_t)0x00080000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG12] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG12_OFS      (20)                            /* !< MEMRESIFG12 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG12_MASK     ((uint32_t)0x00100000U)         /* !< Raw interrupt status for MEMRES12.
                                                                                    This bit is set to 1 when MEMRES12 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES12 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG12_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG12_CLR      ((uint32_t)0x00100000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG13] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG13_OFS      (21)                            /* !< MEMRESIFG13 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG13_MASK     ((uint32_t)0x00200000U)         /* !< Raw interrupt status for MEMRES13.
                                                                                    This bit is set to 1 when MEMRES13 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES13 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG13_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG13_CLR      ((uint32_t)0x00200000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG14] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG14_OFS      (22)                            /* !< MEMRESIFG14 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG14_MASK     ((uint32_t)0x00400000U)         /* !< Raw interrupt status for MEMRES14.
                                                                                    This bit is set to 1 when MEMRES14 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES14 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG14_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG14_CLR      ((uint32_t)0x00400000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG15] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG15_OFS      (23)                            /* !< MEMRESIFG15 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG15_MASK     ((uint32_t)0x00800000U)         /* !< Raw interrupt status for MEMRES15.
                                                                                    This bit is set to 1 when MEMRES15 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES15 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG15_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG15_CLR      ((uint32_t)0x00800000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG16] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG16_OFS      (24)                            /* !< MEMRESIFG16 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG16_MASK     ((uint32_t)0x01000000U)         /* !< Raw interrupt status for MEMRES16.
                                                                                    This bit is set to 1 when MEMRES16 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES16 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG16_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG16_CLR      ((uint32_t)0x01000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG17] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG17_OFS      (25)                            /* !< MEMRESIFG17 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG17_MASK     ((uint32_t)0x02000000U)         /* !< Raw interrupt status for MEMRES17.
                                                                                    This bit is set to 1 when MEMRES17 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES17 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG17_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG17_CLR      ((uint32_t)0x02000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG18] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG18_OFS      (26)                            /* !< MEMRESIFG18 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG18_MASK     ((uint32_t)0x04000000U)         /* !< Raw interrupt status for MEMRES18.
                                                                                    This bit is set to 1 when MEMRES18 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES18 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG18_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG18_CLR      ((uint32_t)0x04000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG19] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG19_OFS      (27)                            /* !< MEMRESIFG19 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG19_MASK     ((uint32_t)0x08000000U)         /* !< Raw interrupt status for MEMRES19.
                                                                                    This bit is set to 1 when MEMRES19 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES19 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG19_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG19_CLR      ((uint32_t)0x08000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG20] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG20_OFS      (28)                            /* !< MEMRESIFG20 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG20_MASK     ((uint32_t)0x10000000U)         /* !< Raw interrupt status for MEMRES20.
                                                                                    This bit is set to 1 when MEMRES20 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES20 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG20_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG20_CLR      ((uint32_t)0x10000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG22] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG22_OFS      (30)                            /* !< MEMRESIFG22 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG22_MASK     ((uint32_t)0x40000000U)         /* !< Raw interrupt status for MEMRES22.
                                                                                    This bit is set to 1 when MEMRES22 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES22 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG22_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG22_CLR      ((uint32_t)0x40000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG23] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG23_OFS      (31)                            /* !< MEMRESIFG23 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG23_MASK     ((uint32_t)0x80000000U)         /* !< Raw interrupt status for MEMRES23.
                                                                                    This bit is set to 1 when MEMRES23 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES23 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG23_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG23_CLR      ((uint32_t)0x80000000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG8] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG8_OFS       (16)                            /* !< MEMRESIFG8 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG8_MASK      ((uint32_t)0x00010000U)         /* !< Raw interrupt status for MEMRES8.
                                                                                    This bit is set to 1 when MEMRES8 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES8 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG8_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG8_CLR       ((uint32_t)0x00010000U)         /* !< A new data is ready to be read. */
/* ADC12_DMA_TRIG_ICLR[MEMRESIFG21] Bits */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG21_OFS      (29)                            /* !< MEMRESIFG21 Offset */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG21_MASK     ((uint32_t)0x20000000U)         /* !< Raw interrupt status for MEMRES21.
                                                                                    This bit is set to 1 when MEMRES21 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES21 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG21_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_DMA_TRIG_ICLR_MEMRESIFG21_CLR      ((uint32_t)0x20000000U)         /* !< A new data is ready to be read. */

/* ADC12_GEN_EVENT_IIDX Bits */
/* ADC12_GEN_EVENT_IIDX[STAT] Bits */
#define ADC12_GEN_EVENT_IIDX_STAT_OFS            (0)                             /* !< STAT Offset */
#define ADC12_GEN_EVENT_IIDX_STAT_MASK           ((uint32_t)0x000003FFU)         /* !< Interrupt index status */
#define ADC12_GEN_EVENT_IIDX_STAT_NO_INTR        ((uint32_t)0x00000000U)         /* !< No bit is set means there is no
                                                                                    pending interrupt request */
#define ADC12_GEN_EVENT_IIDX_STAT_HIGHIFG        ((uint32_t)0x00000003U)         /* !< High threshold compare interrupt */
#define ADC12_GEN_EVENT_IIDX_STAT_LOWIFG         ((uint32_t)0x00000004U)         /* !< Low threshold compare interrupt */
#define ADC12_GEN_EVENT_IIDX_STAT_INIFG          ((uint32_t)0x00000005U)         /* !< Primary Sequence In range
                                                                                    comparator interrupt */
#define ADC12_GEN_EVENT_IIDX_STAT_MEMRESIFG0     ((uint32_t)0x00000009U)         /* !< MEMRES0 data loaded interrupt */

/* ADC12_GEN_EVENT_IMASK Bits */
/* ADC12_GEN_EVENT_IMASK[INIFG] Bits */
#define ADC12_GEN_EVENT_IMASK_INIFG_OFS          (4)                             /* !< INIFG Offset */
#define ADC12_GEN_EVENT_IMASK_INIFG_MASK         ((uint32_t)0x00000010U)         /* !< Mask INIFG in MIS_EX register. */
#define ADC12_GEN_EVENT_IMASK_INIFG_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_IMASK_INIFG_SET          ((uint32_t)0x00000010U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_IMASK[LOWIFG] Bits */
#define ADC12_GEN_EVENT_IMASK_LOWIFG_OFS         (3)                             /* !< LOWIFG Offset */
#define ADC12_GEN_EVENT_IMASK_LOWIFG_MASK        ((uint32_t)0x00000008U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being below than the
                                                                                    WCLOWx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_GEN_EVENT_IMASK_LOWIFG_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_IMASK_LOWIFG_SET         ((uint32_t)0x00000008U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_IMASK[HIGHIFG] Bits */
#define ADC12_GEN_EVENT_IMASK_HIGHIFG_OFS        (2)                             /* !< HIGHIFG Offset */
#define ADC12_GEN_EVENT_IMASK_HIGHIFG_MASK       ((uint32_t)0x00000004U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being higher than the
                                                                                    WCHIGHx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_GEN_EVENT_IMASK_HIGHIFG_CLR        ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_IMASK_HIGHIFG_SET        ((uint32_t)0x00000004U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_IMASK[MEMRESIFG0] Bits */
#define ADC12_GEN_EVENT_IMASK_MEMRESIFG0_OFS     (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_GEN_EVENT_IMASK_MEMRESIFG0_MASK    ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_GEN_EVENT_IMASK_MEMRESIFG0_CLR     ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_GEN_EVENT_IMASK_MEMRESIFG0_SET     ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */

/* ADC12_GEN_EVENT_RIS Bits */
/* ADC12_GEN_EVENT_RIS[INIFG] Bits */
#define ADC12_GEN_EVENT_RIS_INIFG_OFS            (4)                             /* !< INIFG Offset */
#define ADC12_GEN_EVENT_RIS_INIFG_MASK           ((uint32_t)0x00000010U)         /* !< Mask INIFG in MIS_EX register. */
#define ADC12_GEN_EVENT_RIS_INIFG_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_RIS_INIFG_SET            ((uint32_t)0x00000010U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_RIS[LOWIFG] Bits */
#define ADC12_GEN_EVENT_RIS_LOWIFG_OFS           (3)                             /* !< LOWIFG Offset */
#define ADC12_GEN_EVENT_RIS_LOWIFG_MASK          ((uint32_t)0x00000008U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being below than the
                                                                                    WCLOWx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_GEN_EVENT_RIS_LOWIFG_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_RIS_LOWIFG_SET           ((uint32_t)0x00000008U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_RIS[HIGHIFG] Bits */
#define ADC12_GEN_EVENT_RIS_HIGHIFG_OFS          (2)                             /* !< HIGHIFG Offset */
#define ADC12_GEN_EVENT_RIS_HIGHIFG_MASK         ((uint32_t)0x00000004U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being higher than the
                                                                                    WCHIGHx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_GEN_EVENT_RIS_HIGHIFG_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_RIS_HIGHIFG_SET          ((uint32_t)0x00000004U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_RIS[MEMRESIFG0] Bits */
#define ADC12_GEN_EVENT_RIS_MEMRESIFG0_OFS       (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_GEN_EVENT_RIS_MEMRESIFG0_MASK      ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_GEN_EVENT_RIS_MEMRESIFG0_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_GEN_EVENT_RIS_MEMRESIFG0_SET       ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */

/* ADC12_GEN_EVENT_MIS Bits */
/* ADC12_GEN_EVENT_MIS[INIFG] Bits */
#define ADC12_GEN_EVENT_MIS_INIFG_OFS            (4)                             /* !< INIFG Offset */
#define ADC12_GEN_EVENT_MIS_INIFG_MASK           ((uint32_t)0x00000010U)         /* !< Mask INIFG in MIS_EX register. */
#define ADC12_GEN_EVENT_MIS_INIFG_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_MIS_INIFG_SET            ((uint32_t)0x00000010U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_MIS[LOWIFG] Bits */
#define ADC12_GEN_EVENT_MIS_LOWIFG_OFS           (3)                             /* !< LOWIFG Offset */
#define ADC12_GEN_EVENT_MIS_LOWIFG_MASK          ((uint32_t)0x00000008U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being below than the
                                                                                    WCLOWx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_GEN_EVENT_MIS_LOWIFG_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_MIS_LOWIFG_SET           ((uint32_t)0x00000008U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_MIS[HIGHIFG] Bits */
#define ADC12_GEN_EVENT_MIS_HIGHIFG_OFS          (2)                             /* !< HIGHIFG Offset */
#define ADC12_GEN_EVENT_MIS_HIGHIFG_MASK         ((uint32_t)0x00000004U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being higher than the
                                                                                    WCHIGHx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_GEN_EVENT_MIS_HIGHIFG_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_MIS_HIGHIFG_SET          ((uint32_t)0x00000004U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_MIS[MEMRESIFG0] Bits */
#define ADC12_GEN_EVENT_MIS_MEMRESIFG0_OFS       (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_GEN_EVENT_MIS_MEMRESIFG0_MASK      ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_GEN_EVENT_MIS_MEMRESIFG0_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_GEN_EVENT_MIS_MEMRESIFG0_SET       ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */

/* ADC12_GEN_EVENT_ISET Bits */
/* ADC12_GEN_EVENT_ISET[INIFG] Bits */
#define ADC12_GEN_EVENT_ISET_INIFG_OFS           (4)                             /* !< INIFG Offset */
#define ADC12_GEN_EVENT_ISET_INIFG_MASK          ((uint32_t)0x00000010U)         /* !< Mask INIFG in MIS_EX register. */
#define ADC12_GEN_EVENT_ISET_INIFG_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_ISET_INIFG_SET           ((uint32_t)0x00000010U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_ISET[LOWIFG] Bits */
#define ADC12_GEN_EVENT_ISET_LOWIFG_OFS          (3)                             /* !< LOWIFG Offset */
#define ADC12_GEN_EVENT_ISET_LOWIFG_MASK         ((uint32_t)0x00000008U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being below than the
                                                                                    WCLOWx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_GEN_EVENT_ISET_LOWIFG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_ISET_LOWIFG_SET          ((uint32_t)0x00000008U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_ISET[HIGHIFG] Bits */
#define ADC12_GEN_EVENT_ISET_HIGHIFG_OFS         (2)                             /* !< HIGHIFG Offset */
#define ADC12_GEN_EVENT_ISET_HIGHIFG_MASK        ((uint32_t)0x00000004U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being higher than the
                                                                                    WCHIGHx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_GEN_EVENT_ISET_HIGHIFG_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_ISET_HIGHIFG_SET         ((uint32_t)0x00000004U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_ISET[MEMRESIFG0] Bits */
#define ADC12_GEN_EVENT_ISET_MEMRESIFG0_OFS      (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_GEN_EVENT_ISET_MEMRESIFG0_MASK     ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_GEN_EVENT_ISET_MEMRESIFG0_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_GEN_EVENT_ISET_MEMRESIFG0_SET      ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */

/* ADC12_GEN_EVENT_ICLR Bits */
/* ADC12_GEN_EVENT_ICLR[INIFG] Bits */
#define ADC12_GEN_EVENT_ICLR_INIFG_OFS           (4)                             /* !< INIFG Offset */
#define ADC12_GEN_EVENT_ICLR_INIFG_MASK          ((uint32_t)0x00000010U)         /* !< Mask INIFG in MIS_EX register. */
#define ADC12_GEN_EVENT_ICLR_INIFG_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_ICLR_INIFG_CLR           ((uint32_t)0x00000010U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_ICLR[LOWIFG] Bits */
#define ADC12_GEN_EVENT_ICLR_LOWIFG_OFS          (3)                             /* !< LOWIFG Offset */
#define ADC12_GEN_EVENT_ICLR_LOWIFG_MASK         ((uint32_t)0x00000008U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being below than the
                                                                                    WCLOWx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_GEN_EVENT_ICLR_LOWIFG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_ICLR_LOWIFG_CLR          ((uint32_t)0x00000008U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_ICLR[HIGHIFG] Bits */
#define ADC12_GEN_EVENT_ICLR_HIGHIFG_OFS         (2)                             /* !< HIGHIFG Offset */
#define ADC12_GEN_EVENT_ICLR_HIGHIFG_MASK        ((uint32_t)0x00000004U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being higher than the
                                                                                    WCHIGHx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_GEN_EVENT_ICLR_HIGHIFG_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_GEN_EVENT_ICLR_HIGHIFG_CLR         ((uint32_t)0x00000004U)         /* !< Interrupt is pending. */
/* ADC12_GEN_EVENT_ICLR[MEMRESIFG0] Bits */
#define ADC12_GEN_EVENT_ICLR_MEMRESIFG0_OFS      (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_GEN_EVENT_ICLR_MEMRESIFG0_MASK     ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_GEN_EVENT_ICLR_MEMRESIFG0_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_GEN_EVENT_ICLR_MEMRESIFG0_CLR      ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */

/* ADC12_CPU_INT_IIDX Bits */
/* ADC12_CPU_INT_IIDX[STAT] Bits */
#define ADC12_CPU_INT_IIDX_STAT_OFS              (0)                             /* !< STAT Offset */
#define ADC12_CPU_INT_IIDX_STAT_MASK             ((uint32_t)0x000003FFU)         /* !< Interrupt index status */
#define ADC12_CPU_INT_IIDX_STAT_NO_INTR          ((uint32_t)0x00000000U)         /* !< No bit is set means there is no
                                                                                    pending interrupt request */
#define ADC12_CPU_INT_IIDX_STAT_OVIFG            ((uint32_t)0x00000001U)         /* !< MEMRESx overflow interrupt */
#define ADC12_CPU_INT_IIDX_STAT_TOVIFG           ((uint32_t)0x00000002U)         /* !< Sequence Conversion time overflow
                                                                                    interrupt */
#define ADC12_CPU_INT_IIDX_STAT_HIGHIFG          ((uint32_t)0x00000003U)         /* !< High threshold compare interrupt */
#define ADC12_CPU_INT_IIDX_STAT_LOWIFG           ((uint32_t)0x00000004U)         /* !< Low threshold compare interrupt */
#define ADC12_CPU_INT_IIDX_STAT_INIFG            ((uint32_t)0x00000005U)         /* !< Primary Sequence In range
                                                                                    comparator interrupt */
#define ADC12_CPU_INT_IIDX_STAT_DMADONE          ((uint32_t)0x00000006U)         /* !< DMA done interrupt, generated on
                                                                                    DMA transfer completion, */
#define ADC12_CPU_INT_IIDX_STAT_UVIFG            ((uint32_t)0x00000007U)         /* !< MEMRESx underflow interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG0       ((uint32_t)0x00000009U)         /* !< MEMRES0 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG1       ((uint32_t)0x0000000AU)         /* !< MEMRES1 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG2       ((uint32_t)0x0000000BU)         /* !< MEMRES2 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG3       ((uint32_t)0x0000000CU)         /* !< MEMRES3 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG4       ((uint32_t)0x0000000DU)         /* !< MEMRES4 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG5       ((uint32_t)0x0000000EU)         /* !< MEMRES5 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG6       ((uint32_t)0x0000000FU)         /* !< MEMRES6 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG7       ((uint32_t)0x00000010U)         /* !< MEMRES7 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG8       ((uint32_t)0x00000011U)         /* !< MEMRES8 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG9       ((uint32_t)0x00000012U)         /* !< MEMRES9 data  loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG10      ((uint32_t)0x00000013U)         /* !< MEMRES10 data  loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG11      ((uint32_t)0x00000014U)         /* !< MEMRES11 data  loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG12      ((uint32_t)0x00000015U)         /* !< MEMRES12 data  loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG13      ((uint32_t)0x00000016U)         /* !< MEMRES13 data  loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG14      ((uint32_t)0x00000017U)         /* !< MEMRES14 data  loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG15      ((uint32_t)0x00000018U)         /* !< MEMRES15 data  loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG16      ((uint32_t)0x00000019U)         /* !< MEMRES16 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG17      ((uint32_t)0x0000001AU)         /* !< MEMRES17 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG18      ((uint32_t)0x0000001BU)         /* !< MEMRES18 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG19      ((uint32_t)0x0000001CU)         /* !< MEMRES19 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG20      ((uint32_t)0x0000001DU)         /* !< MEMRES20 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG21      ((uint32_t)0x0000001EU)         /* !< MEMRES21 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG22      ((uint32_t)0x0000001FU)         /* !< MEMRES22 data loaded interrupt */
#define ADC12_CPU_INT_IIDX_STAT_MEMRESIFG23      ((uint32_t)0x00000020U)         /* !< MEMRES23 data loaded interrupt */

/* ADC12_CPU_INT_IMASK Bits */
/* ADC12_CPU_INT_IMASK[INIFG] Bits */
#define ADC12_CPU_INT_IMASK_INIFG_OFS            (4)                             /* !< INIFG Offset */
#define ADC12_CPU_INT_IMASK_INIFG_MASK           ((uint32_t)0x00000010U)         /* !< Mask INIFG in MIS_EX register. */
#define ADC12_CPU_INT_IMASK_INIFG_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_IMASK_INIFG_SET            ((uint32_t)0x00000010U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_IMASK[LOWIFG] Bits */
#define ADC12_CPU_INT_IMASK_LOWIFG_OFS           (3)                             /* !< LOWIFG Offset */
#define ADC12_CPU_INT_IMASK_LOWIFG_MASK          ((uint32_t)0x00000008U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being below than the
                                                                                    WCLOWx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_IMASK_LOWIFG_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_IMASK_LOWIFG_SET           ((uint32_t)0x00000008U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_IMASK[HIGHIFG] Bits */
#define ADC12_CPU_INT_IMASK_HIGHIFG_OFS          (2)                             /* !< HIGHIFG Offset */
#define ADC12_CPU_INT_IMASK_HIGHIFG_MASK         ((uint32_t)0x00000004U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being higher than the
                                                                                    WCHIGHx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_IMASK_HIGHIFG_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_IMASK_HIGHIFG_SET          ((uint32_t)0x00000004U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_IMASK[OVIFG] Bits */
#define ADC12_CPU_INT_IMASK_OVIFG_OFS            (0)                             /* !< OVIFG Offset */
#define ADC12_CPU_INT_IMASK_OVIFG_MASK           ((uint32_t)0x00000001U)         /* !< Raw interrupt flag for MEMRESx
                                                                                    overflow. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_IMASK_OVIFG_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_IMASK_OVIFG_SET            ((uint32_t)0x00000001U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_IMASK[UVIFG] Bits */
#define ADC12_CPU_INT_IMASK_UVIFG_OFS            (6)                             /* !< UVIFG Offset */
#define ADC12_CPU_INT_IMASK_UVIFG_MASK           ((uint32_t)0x00000040U)         /* !< Raw interrupt flag for MEMRESx
                                                                                    underflow. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR is set to 1. */
#define ADC12_CPU_INT_IMASK_UVIFG_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_IMASK_UVIFG_SET            ((uint32_t)0x00000040U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_IMASK[TOVIFG] Bits */
#define ADC12_CPU_INT_IMASK_TOVIFG_OFS           (1)                             /* !< TOVIFG Offset */
#define ADC12_CPU_INT_IMASK_TOVIFG_MASK          ((uint32_t)0x00000002U)         /* !< Raw interrupt flag for sequence
                                                                                    conversion timeout overflow. This bit
                                                                                    is reset to 0 by IIDX read or when
                                                                                    corresponding bit in ICLR_EX is set
                                                                                    to 1. */
#define ADC12_CPU_INT_IMASK_TOVIFG_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_IMASK_TOVIFG_SET           ((uint32_t)0x00000002U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_IMASK[DMADONE] Bits */
#define ADC12_CPU_INT_IMASK_DMADONE_OFS          (5)                             /* !< DMADONE Offset */
#define ADC12_CPU_INT_IMASK_DMADONE_MASK         ((uint32_t)0x00000020U)         /* !< Raw interrupt flag for DMADONE.
                                                                                    This bit is reset to 0 by IIDX read
                                                                                    or when corresponding bit in ICLR_EX
                                                                                    is set to 1. */
#define ADC12_CPU_INT_IMASK_DMADONE_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_IMASK_DMADONE_SET          ((uint32_t)0x00000020U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG0] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG0_OFS       (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG0_MASK      ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG0_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG0_SET       ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG1] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG1_OFS       (9)                             /* !< MEMRESIFG1 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG1_MASK      ((uint32_t)0x00000200U)         /* !< Raw interrupt status for MEMRES1.
                                                                                    This bit is set to 1 when MEMRES1 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES1 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG1_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG1_SET       ((uint32_t)0x00000200U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG2] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG2_OFS       (10)                            /* !< MEMRESIFG2 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG2_MASK      ((uint32_t)0x00000400U)         /* !< Raw interrupt status for MEMRES2.
                                                                                    This bit is set to 1 when MEMRES2 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES2 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG2_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG2_SET       ((uint32_t)0x00000400U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG3] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG3_OFS       (11)                            /* !< MEMRESIFG3 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG3_MASK      ((uint32_t)0x00000800U)         /* !< Raw interrupt status for MEMRES3.
                                                                                    This bit is set to 1 when MEMRES3 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES3 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG3_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG3_SET       ((uint32_t)0x00000800U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG4] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG4_OFS       (12)                            /* !< MEMRESIFG4 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG4_MASK      ((uint32_t)0x00001000U)         /* !< Raw interrupt status for MEMRES4.
                                                                                    This bit is set to 1 when MEMRES4 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES4 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG4_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG4_SET       ((uint32_t)0x00001000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG5] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG5_OFS       (13)                            /* !< MEMRESIFG5 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG5_MASK      ((uint32_t)0x00002000U)         /* !< Raw interrupt status for MEMRES5.
                                                                                    This bit is set to 1 when MEMRES5 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES5 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG5_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG5_SET       ((uint32_t)0x00002000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG6] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG6_OFS       (14)                            /* !< MEMRESIFG6 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG6_MASK      ((uint32_t)0x00004000U)         /* !< Raw interrupt status for MEMRES6.
                                                                                    This bit is set to 1 when MEMRES6 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES6 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG6_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG6_SET       ((uint32_t)0x00004000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG7] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG7_OFS       (15)                            /* !< MEMRESIFG7 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG7_MASK      ((uint32_t)0x00008000U)         /* !< Raw interrupt status for MEMRES7.
                                                                                    This bit is set to 1 when MEMRES7 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES7 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG7_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG7_SET       ((uint32_t)0x00008000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG9] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG9_OFS       (17)                            /* !< MEMRESIFG9 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG9_MASK      ((uint32_t)0x00020000U)         /* !< Raw interrupt status for MEMRES9.
                                                                                    This bit is set to 1 when MEMRES9 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES9 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG9_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG9_SET       ((uint32_t)0x00020000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG10] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG10_OFS      (18)                            /* !< MEMRESIFG10 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG10_MASK     ((uint32_t)0x00040000U)         /* !< Raw interrupt status for MEMRES10.
                                                                                    This bit is set to 1 when MEMRES10 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES10 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG10_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG10_SET      ((uint32_t)0x00040000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG11] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG11_OFS      (19)                            /* !< MEMRESIFG11 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG11_MASK     ((uint32_t)0x00080000U)         /* !< Raw interrupt status for MEMRES11.
                                                                                    This bit is set to 1 when MEMRES11 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES11 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG11_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG11_SET      ((uint32_t)0x00080000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG12] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG12_OFS      (20)                            /* !< MEMRESIFG12 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG12_MASK     ((uint32_t)0x00100000U)         /* !< Raw interrupt status for MEMRES12.
                                                                                    This bit is set to 1 when MEMRES12 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES12 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG12_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG12_SET      ((uint32_t)0x00100000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG13] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG13_OFS      (21)                            /* !< MEMRESIFG13 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG13_MASK     ((uint32_t)0x00200000U)         /* !< Raw interrupt status for MEMRES13.
                                                                                    This bit is set to 1 when MEMRES13 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES13 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG13_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG13_SET      ((uint32_t)0x00200000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG14] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG14_OFS      (22)                            /* !< MEMRESIFG14 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG14_MASK     ((uint32_t)0x00400000U)         /* !< Raw interrupt status for MEMRES14.
                                                                                    This bit is set to 1 when MEMRES14 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES14 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG14_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG14_SET      ((uint32_t)0x00400000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG15] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG15_OFS      (23)                            /* !< MEMRESIFG15 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG15_MASK     ((uint32_t)0x00800000U)         /* !< Raw interrupt status for MEMRES15.
                                                                                    This bit is set to 1 when MEMRES15 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES15 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG15_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG15_SET      ((uint32_t)0x00800000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG16] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG16_OFS      (24)                            /* !< MEMRESIFG16 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG16_MASK     ((uint32_t)0x01000000U)         /* !< Raw interrupt status for MEMRES16.
                                                                                    This bit is set to 1 when MEMRES16 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES16 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG16_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG16_SET      ((uint32_t)0x01000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG17] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG17_OFS      (25)                            /* !< MEMRESIFG17 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG17_MASK     ((uint32_t)0x02000000U)         /* !< Raw interrupt status for MEMRES17.
                                                                                    This bit is set to 1 when MEMRES17 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES17 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG17_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG17_SET      ((uint32_t)0x02000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG18] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG18_OFS      (26)                            /* !< MEMRESIFG18 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG18_MASK     ((uint32_t)0x04000000U)         /* !< Raw interrupt status for MEMRES18.
                                                                                    This bit is set to 1 when MEMRES18 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES18 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG18_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG18_SET      ((uint32_t)0x04000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG19] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG19_OFS      (27)                            /* !< MEMRESIFG19 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG19_MASK     ((uint32_t)0x08000000U)         /* !< Raw interrupt status for MEMRES19.
                                                                                    This bit is set to 1 when MEMRES19 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES19 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG19_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG19_SET      ((uint32_t)0x08000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG20] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG20_OFS      (28)                            /* !< MEMRESIFG20 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG20_MASK     ((uint32_t)0x10000000U)         /* !< Raw interrupt status for MEMRES20.
                                                                                    This bit is set to 1 when MEMRES20 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES20 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG20_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG20_SET      ((uint32_t)0x10000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG22] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG22_OFS      (30)                            /* !< MEMRESIFG22 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG22_MASK     ((uint32_t)0x40000000U)         /* !< Raw interrupt status for MEMRES22.
                                                                                    This bit is set to 1 when MEMRES22 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES22 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG22_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG22_SET      ((uint32_t)0x40000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG23] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG23_OFS      (31)                            /* !< MEMRESIFG23 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG23_MASK     ((uint32_t)0x80000000U)         /* !< Raw interrupt status for MEMRES23.
                                                                                    This bit is set to 1 when MEMRES23 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES23 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG23_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG23_SET      ((uint32_t)0x80000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG8] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG8_OFS       (16)                            /* !< MEMRESIFG8 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG8_MASK      ((uint32_t)0x00010000U)         /* !< Raw interrupt status for MEMRES8.
                                                                                    This bit is set to 1 when MEMRES8 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES8 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG8_CLR       ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG8_SET       ((uint32_t)0x00010000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_IMASK[MEMRESIFG21] Bits */
#define ADC12_CPU_INT_IMASK_MEMRESIFG21_OFS      (29)                            /* !< MEMRESIFG21 Offset */
#define ADC12_CPU_INT_IMASK_MEMRESIFG21_MASK     ((uint32_t)0x20000000U)         /* !< Raw interrupt status for MEMRES21.
                                                                                    This bit is set to 1 when MEMRES21 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES21 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_IMASK_MEMRESIFG21_CLR      ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_IMASK_MEMRESIFG21_SET      ((uint32_t)0x20000000U)         /* !< A new data is ready to be read. */

/* ADC12_CPU_INT_RIS Bits */
/* ADC12_CPU_INT_RIS[INIFG] Bits */
#define ADC12_CPU_INT_RIS_INIFG_OFS              (4)                             /* !< INIFG Offset */
#define ADC12_CPU_INT_RIS_INIFG_MASK             ((uint32_t)0x00000010U)         /* !< Mask INIFG in MIS_EX register. */
#define ADC12_CPU_INT_RIS_INIFG_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_RIS_INIFG_SET              ((uint32_t)0x00000010U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_RIS[LOWIFG] Bits */
#define ADC12_CPU_INT_RIS_LOWIFG_OFS             (3)                             /* !< LOWIFG Offset */
#define ADC12_CPU_INT_RIS_LOWIFG_MASK            ((uint32_t)0x00000008U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being below than the
                                                                                    WCLOWx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_RIS_LOWIFG_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_RIS_LOWIFG_SET             ((uint32_t)0x00000008U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_RIS[HIGHIFG] Bits */
#define ADC12_CPU_INT_RIS_HIGHIFG_OFS            (2)                             /* !< HIGHIFG Offset */
#define ADC12_CPU_INT_RIS_HIGHIFG_MASK           ((uint32_t)0x00000004U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being higher than the
                                                                                    WCHIGHx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_RIS_HIGHIFG_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_RIS_HIGHIFG_SET            ((uint32_t)0x00000004U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_RIS[OVIFG] Bits */
#define ADC12_CPU_INT_RIS_OVIFG_OFS              (0)                             /* !< OVIFG Offset */
#define ADC12_CPU_INT_RIS_OVIFG_MASK             ((uint32_t)0x00000001U)         /* !< Raw interrupt flag for MEMRESx
                                                                                    overflow. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_RIS_OVIFG_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_RIS_OVIFG_SET              ((uint32_t)0x00000001U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_RIS[UVIFG] Bits */
#define ADC12_CPU_INT_RIS_UVIFG_OFS              (6)                             /* !< UVIFG Offset */
#define ADC12_CPU_INT_RIS_UVIFG_MASK             ((uint32_t)0x00000040U)         /* !< Raw interrupt flag for MEMRESx
                                                                                    underflow. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR is set to 1. */
#define ADC12_CPU_INT_RIS_UVIFG_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_RIS_UVIFG_SET              ((uint32_t)0x00000040U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_RIS[TOVIFG] Bits */
#define ADC12_CPU_INT_RIS_TOVIFG_OFS             (1)                             /* !< TOVIFG Offset */
#define ADC12_CPU_INT_RIS_TOVIFG_MASK            ((uint32_t)0x00000002U)         /* !< Raw interrupt flag for sequence
                                                                                    conversion trigger overflow. This bit
                                                                                    is reset to 0 by IIDX read or when
                                                                                    corresponding bit in ICLR_EX is set
                                                                                    to 1. */
#define ADC12_CPU_INT_RIS_TOVIFG_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_RIS_TOVIFG_SET             ((uint32_t)0x00000002U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_RIS[DMADONE] Bits */
#define ADC12_CPU_INT_RIS_DMADONE_OFS            (5)                             /* !< DMADONE Offset */
#define ADC12_CPU_INT_RIS_DMADONE_MASK           ((uint32_t)0x00000020U)         /* !< Raw interrupt flag for DMADONE.
                                                                                    This bit is reset to 0 by IIDX read
                                                                                    or when corresponding bit in ICLR_EX
                                                                                    is set to 1. */
#define ADC12_CPU_INT_RIS_DMADONE_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_RIS_DMADONE_SET            ((uint32_t)0x00000020U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_RIS[MEMRESIFG0] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG0_OFS         (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG0_MASK        ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG0_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG0_SET         ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG1] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG1_OFS         (9)                             /* !< MEMRESIFG1 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG1_MASK        ((uint32_t)0x00000200U)         /* !< Raw interrupt status for MEMRES1.
                                                                                    This bit is set to 1 when MEMRES1 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES1 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG1_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG1_SET         ((uint32_t)0x00000200U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG2] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG2_OFS         (10)                            /* !< MEMRESIFG2 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG2_MASK        ((uint32_t)0x00000400U)         /* !< Raw interrupt status for MEMRES2.
                                                                                    This bit is set to 1 when MEMRES2 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES2 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG2_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG2_SET         ((uint32_t)0x00000400U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG3] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG3_OFS         (11)                            /* !< MEMRESIFG3 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG3_MASK        ((uint32_t)0x00000800U)         /* !< Raw interrupt status for MEMRES3.
                                                                                    This bit is set to 1 when MEMRES3 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES3 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG3_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG3_SET         ((uint32_t)0x00000800U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG4] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG4_OFS         (12)                            /* !< MEMRESIFG4 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG4_MASK        ((uint32_t)0x00001000U)         /* !< Raw interrupt status for MEMRES4.
                                                                                    This bit is set to 1 when MEMRES4 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES4 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG4_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG4_SET         ((uint32_t)0x00001000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG5] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG5_OFS         (13)                            /* !< MEMRESIFG5 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG5_MASK        ((uint32_t)0x00002000U)         /* !< Raw interrupt status for MEMRES5.
                                                                                    This bit is set to 1 when MEMRES5 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES5 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG5_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG5_SET         ((uint32_t)0x00002000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG6] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG6_OFS         (14)                            /* !< MEMRESIFG6 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG6_MASK        ((uint32_t)0x00004000U)         /* !< Raw interrupt status for MEMRES6.
                                                                                    This bit is set to 1 when MEMRES6 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES6 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG6_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG6_SET         ((uint32_t)0x00004000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG7] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG7_OFS         (15)                            /* !< MEMRESIFG7 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG7_MASK        ((uint32_t)0x00008000U)         /* !< Raw interrupt status for MEMRES7.
                                                                                    This bit is set to 1 when MEMRES7 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES7 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG7_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG7_SET         ((uint32_t)0x00008000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG9] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG9_OFS         (17)                            /* !< MEMRESIFG9 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG9_MASK        ((uint32_t)0x00020000U)         /* !< Raw interrupt status for MEMRES9.
                                                                                    This bit is set to 1 when MEMRES9 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES9 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG9_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG9_SET         ((uint32_t)0x00020000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG10] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG10_OFS        (18)                            /* !< MEMRESIFG10 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG10_MASK       ((uint32_t)0x00040000U)         /* !< Raw interrupt status for MEMRES10.
                                                                                    This bit is set to 1 when MEMRES10 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES10 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG10_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG10_SET        ((uint32_t)0x00040000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG11] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG11_OFS        (19)                            /* !< MEMRESIFG11 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG11_MASK       ((uint32_t)0x00080000U)         /* !< Raw interrupt status for MEMRES11.
                                                                                    This bit is set to 1 when MEMRES11 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES11 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG11_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG11_SET        ((uint32_t)0x00080000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG12] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG12_OFS        (20)                            /* !< MEMRESIFG12 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG12_MASK       ((uint32_t)0x00100000U)         /* !< Raw interrupt status for MEMRES12.
                                                                                    This bit is set to 1 when MEMRES12 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES12 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG12_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG12_SET        ((uint32_t)0x00100000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG13] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG13_OFS        (21)                            /* !< MEMRESIFG13 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG13_MASK       ((uint32_t)0x00200000U)         /* !< Raw interrupt status for MEMRES13.
                                                                                    This bit is set to 1 when MEMRES13 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES13 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG13_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG13_SET        ((uint32_t)0x00200000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG14] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG14_OFS        (22)                            /* !< MEMRESIFG14 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG14_MASK       ((uint32_t)0x00400000U)         /* !< Raw interrupt status for MEMRES14.
                                                                                    This bit is set to 1 when MEMRES14 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES14 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG14_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG14_SET        ((uint32_t)0x00400000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG15] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG15_OFS        (23)                            /* !< MEMRESIFG15 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG15_MASK       ((uint32_t)0x00800000U)         /* !< Raw interrupt status for MEMRES15.
                                                                                    This bit is set to 1 when MEMRES15 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES15 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG15_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG15_SET        ((uint32_t)0x00800000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG16] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG16_OFS        (24)                            /* !< MEMRESIFG16 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG16_MASK       ((uint32_t)0x01000000U)         /* !< Raw interrupt status for MEMRES16.
                                                                                    This bit is set to 1 when MEMRES16 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES16 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG16_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG16_SET        ((uint32_t)0x01000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG17] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG17_OFS        (25)                            /* !< MEMRESIFG17 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG17_MASK       ((uint32_t)0x02000000U)         /* !< Raw interrupt status for MEMRES17.
                                                                                    This bit is set to 1 when MEMRES17 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES17 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG17_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG17_SET        ((uint32_t)0x02000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG18] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG18_OFS        (26)                            /* !< MEMRESIFG18 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG18_MASK       ((uint32_t)0x04000000U)         /* !< Raw interrupt status for MEMRES18.
                                                                                    This bit is set to 1 when MEMRES18 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES18 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG18_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG18_SET        ((uint32_t)0x04000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG19] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG19_OFS        (27)                            /* !< MEMRESIFG19 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG19_MASK       ((uint32_t)0x08000000U)         /* !< Raw interrupt status for MEMRES19.
                                                                                    This bit is set to 1 when MEMRES19 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES19 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG19_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG19_SET        ((uint32_t)0x08000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG20] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG20_OFS        (28)                            /* !< MEMRESIFG20 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG20_MASK       ((uint32_t)0x10000000U)         /* !< Raw interrupt status for MEMRES20.
                                                                                    This bit is set to 1 when MEMRES20 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES20 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG20_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG20_SET        ((uint32_t)0x10000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG22] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG22_OFS        (30)                            /* !< MEMRESIFG22 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG22_MASK       ((uint32_t)0x40000000U)         /* !< Raw interrupt status for MEMRES22.
                                                                                    This bit is set to 1 when MEMRES22 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES22 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG22_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG22_SET        ((uint32_t)0x40000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG23] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG23_OFS        (31)                            /* !< MEMRESIFG23 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG23_MASK       ((uint32_t)0x80000000U)         /* !< Raw interrupt status for MEMRES23.
                                                                                    This bit is set to 1 when MEMRES23 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES23 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG23_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG23_SET        ((uint32_t)0x80000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG8] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG8_OFS         (16)                            /* !< MEMRESIFG8 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG8_MASK        ((uint32_t)0x00010000U)         /* !< Raw interrupt status for MEMRES8.
                                                                                    This bit is set to 1 when MEMRES8 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES8 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG8_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG8_SET         ((uint32_t)0x00010000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_RIS[MEMRESIFG21] Bits */
#define ADC12_CPU_INT_RIS_MEMRESIFG21_OFS        (29)                            /* !< MEMRESIFG21 Offset */
#define ADC12_CPU_INT_RIS_MEMRESIFG21_MASK       ((uint32_t)0x20000000U)         /* !< Raw interrupt status for MEMRES21.
                                                                                    This bit is set to 1 when MEMRES21 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES21 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_RIS_MEMRESIFG21_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_RIS_MEMRESIFG21_SET        ((uint32_t)0x20000000U)         /* !< A new data is ready to be read. */

/* ADC12_CPU_INT_MIS Bits */
/* ADC12_CPU_INT_MIS[INIFG] Bits */
#define ADC12_CPU_INT_MIS_INIFG_OFS              (4)                             /* !< INIFG Offset */
#define ADC12_CPU_INT_MIS_INIFG_MASK             ((uint32_t)0x00000010U)         /* !< Mask INIFG in MIS_EX register. */
#define ADC12_CPU_INT_MIS_INIFG_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_MIS_INIFG_SET              ((uint32_t)0x00000010U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_MIS[LOWIFG] Bits */
#define ADC12_CPU_INT_MIS_LOWIFG_OFS             (3)                             /* !< LOWIFG Offset */
#define ADC12_CPU_INT_MIS_LOWIFG_MASK            ((uint32_t)0x00000008U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being below than the
                                                                                    WCLOWx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_MIS_LOWIFG_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_MIS_LOWIFG_SET             ((uint32_t)0x00000008U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_MIS[HIGHIFG] Bits */
#define ADC12_CPU_INT_MIS_HIGHIFG_OFS            (2)                             /* !< HIGHIFG Offset */
#define ADC12_CPU_INT_MIS_HIGHIFG_MASK           ((uint32_t)0x00000004U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being higher than the
                                                                                    WCHIGHx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_MIS_HIGHIFG_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_MIS_HIGHIFG_SET            ((uint32_t)0x00000004U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_MIS[OVIFG] Bits */
#define ADC12_CPU_INT_MIS_OVIFG_OFS              (0)                             /* !< OVIFG Offset */
#define ADC12_CPU_INT_MIS_OVIFG_MASK             ((uint32_t)0x00000001U)         /* !< Raw interrupt flag for MEMRESx
                                                                                    overflow. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_MIS_OVIFG_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_MIS_OVIFG_SET              ((uint32_t)0x00000001U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_MIS[UVIFG] Bits */
#define ADC12_CPU_INT_MIS_UVIFG_OFS              (6)                             /* !< UVIFG Offset */
#define ADC12_CPU_INT_MIS_UVIFG_MASK             ((uint32_t)0x00000040U)         /* !< Raw interrupt flag for MEMRESx
                                                                                    underflow. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR is set to 1. */
#define ADC12_CPU_INT_MIS_UVIFG_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_MIS_UVIFG_SET              ((uint32_t)0x00000040U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_MIS[TOVIFG] Bits */
#define ADC12_CPU_INT_MIS_TOVIFG_OFS             (1)                             /* !< TOVIFG Offset */
#define ADC12_CPU_INT_MIS_TOVIFG_MASK            ((uint32_t)0x00000002U)         /* !< Raw interrupt flag for sequence
                                                                                    conversion timeout overflow. This bit
                                                                                    is reset to 0 by IIDX read or when
                                                                                    corresponding bit in ICLR_EX is set
                                                                                    to 1. */
#define ADC12_CPU_INT_MIS_TOVIFG_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_MIS_TOVIFG_SET             ((uint32_t)0x00000002U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_MIS[DMADONE] Bits */
#define ADC12_CPU_INT_MIS_DMADONE_OFS            (5)                             /* !< DMADONE Offset */
#define ADC12_CPU_INT_MIS_DMADONE_MASK           ((uint32_t)0x00000020U)         /* !< Raw interrupt flag for DMADONE.
                                                                                    This bit is reset to 0 by IIDX read
                                                                                    or when corresponding bit in ICLR_EX
                                                                                    is set to 1. */
#define ADC12_CPU_INT_MIS_DMADONE_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_MIS_DMADONE_SET            ((uint32_t)0x00000020U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_MIS[MEMRESIFG0] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG0_OFS         (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG0_MASK        ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG0_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG0_SET         ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG1] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG1_OFS         (9)                             /* !< MEMRESIFG1 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG1_MASK        ((uint32_t)0x00000200U)         /* !< Raw interrupt status for MEMRES1.
                                                                                    This bit is set to 1 when MEMRES1 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES1 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG1_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG1_SET         ((uint32_t)0x00000200U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG2] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG2_OFS         (10)                            /* !< MEMRESIFG2 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG2_MASK        ((uint32_t)0x00000400U)         /* !< Raw interrupt status for MEMRES2.
                                                                                    This bit is set to 1 when MEMRES2 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES2 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG2_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG2_SET         ((uint32_t)0x00000400U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG3] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG3_OFS         (11)                            /* !< MEMRESIFG3 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG3_MASK        ((uint32_t)0x00000800U)         /* !< Raw interrupt status for MEMRES3.
                                                                                    This bit is set to 1 when MEMRES3 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES3 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG3_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG3_SET         ((uint32_t)0x00000800U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG4] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG4_OFS         (12)                            /* !< MEMRESIFG4 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG4_MASK        ((uint32_t)0x00001000U)         /* !< Raw interrupt status for MEMRES4.
                                                                                    This bit is set to 1 when MEMRES4 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES4 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG4_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG4_SET         ((uint32_t)0x00001000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG5] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG5_OFS         (13)                            /* !< MEMRESIFG5 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG5_MASK        ((uint32_t)0x00002000U)         /* !< Raw interrupt status for MEMRES5.
                                                                                    This bit is set to 1 when MEMRES5 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES5 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG5_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG5_SET         ((uint32_t)0x00002000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG6] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG6_OFS         (14)                            /* !< MEMRESIFG6 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG6_MASK        ((uint32_t)0x00004000U)         /* !< Raw interrupt status for MEMRES6.
                                                                                    This bit is set to 1 when MEMRES6 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES6 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG6_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG6_SET         ((uint32_t)0x00004000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG7] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG7_OFS         (15)                            /* !< MEMRESIFG7 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG7_MASK        ((uint32_t)0x00008000U)         /* !< Raw interrupt status for MEMRES7.
                                                                                    This bit is set to 1 when MEMRES7 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES7 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG7_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG7_SET         ((uint32_t)0x00008000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG9] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG9_OFS         (17)                            /* !< MEMRESIFG9 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG9_MASK        ((uint32_t)0x00020000U)         /* !< Raw interrupt status for MEMRES9.
                                                                                    This bit is set to 1 when MEMRES9 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES9 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG9_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG9_SET         ((uint32_t)0x00020000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG10] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG10_OFS        (18)                            /* !< MEMRESIFG10 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG10_MASK       ((uint32_t)0x00040000U)         /* !< Raw interrupt status for MEMRES10.
                                                                                    This bit is set to 1 when MEMRES10 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES10 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG10_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG10_SET        ((uint32_t)0x00040000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG11] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG11_OFS        (19)                            /* !< MEMRESIFG11 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG11_MASK       ((uint32_t)0x00080000U)         /* !< Raw interrupt status for MEMRES11.
                                                                                    This bit is set to 1 when MEMRES11 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES11 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG11_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG11_SET        ((uint32_t)0x00080000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG12] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG12_OFS        (20)                            /* !< MEMRESIFG12 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG12_MASK       ((uint32_t)0x00100000U)         /* !< Raw interrupt status for MEMRES12.
                                                                                    This bit is set to 1 when MEMRES12 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES12 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG12_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG12_SET        ((uint32_t)0x00100000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG13] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG13_OFS        (21)                            /* !< MEMRESIFG13 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG13_MASK       ((uint32_t)0x00200000U)         /* !< Raw interrupt status for MEMRES13.
                                                                                    This bit is set to 1 when MEMRES13 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES13 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG13_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG13_SET        ((uint32_t)0x00200000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG14] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG14_OFS        (22)                            /* !< MEMRESIFG14 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG14_MASK       ((uint32_t)0x00400000U)         /* !< Raw interrupt status for MEMRES14.
                                                                                    This bit is set to 1 when MEMRES14 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES14 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG14_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG14_SET        ((uint32_t)0x00400000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG15] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG15_OFS        (23)                            /* !< MEMRESIFG15 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG15_MASK       ((uint32_t)0x00800000U)         /* !< Raw interrupt status for MEMRES15.
                                                                                    This bit is set to 1 when MEMRES15 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES15 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG15_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG15_SET        ((uint32_t)0x00800000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG16] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG16_OFS        (24)                            /* !< MEMRESIFG16 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG16_MASK       ((uint32_t)0x01000000U)         /* !< Raw interrupt status for MEMRES16.
                                                                                    This bit is set to 1 when MEMRES16 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES16 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG16_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG16_SET        ((uint32_t)0x01000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG17] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG17_OFS        (25)                            /* !< MEMRESIFG17 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG17_MASK       ((uint32_t)0x02000000U)         /* !< Raw interrupt status for MEMRES17.
                                                                                    This bit is set to 1 when MEMRES17 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES17 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG17_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG17_SET        ((uint32_t)0x02000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG18] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG18_OFS        (26)                            /* !< MEMRESIFG18 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG18_MASK       ((uint32_t)0x04000000U)         /* !< Raw interrupt status for MEMRES18.
                                                                                    This bit is set to 1 when MEMRES18 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES18 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG18_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG18_SET        ((uint32_t)0x04000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG19] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG19_OFS        (27)                            /* !< MEMRESIFG19 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG19_MASK       ((uint32_t)0x08000000U)         /* !< Raw interrupt status for MEMRES19.
                                                                                    This bit is set to 1 when MEMRES19 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES19 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG19_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG19_SET        ((uint32_t)0x08000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG20] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG20_OFS        (28)                            /* !< MEMRESIFG20 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG20_MASK       ((uint32_t)0x10000000U)         /* !< Raw interrupt status for MEMRES20.
                                                                                    This bit is set to 1 when MEMRES20 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES20 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG20_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG20_SET        ((uint32_t)0x10000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG22] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG22_OFS        (30)                            /* !< MEMRESIFG22 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG22_MASK       ((uint32_t)0x40000000U)         /* !< Raw interrupt status for MEMRES22.
                                                                                    This bit is set to 1 when MEMRES22 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES22 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG22_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG22_SET        ((uint32_t)0x40000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG23] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG23_OFS        (31)                            /* !< MEMRESIFG23 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG23_MASK       ((uint32_t)0x80000000U)         /* !< Raw interrupt status for MEMRES23.
                                                                                    This bit is set to 1 when MEMRES23 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES23 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG23_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG23_SET        ((uint32_t)0x80000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG8] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG8_OFS         (16)                            /* !< MEMRESIFG8 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG8_MASK        ((uint32_t)0x00010000U)         /* !< Raw interrupt status for MEMRES8.
                                                                                    This bit is set to 1 when MEMRES8 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES8 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG8_CLR         ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG8_SET         ((uint32_t)0x00010000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_MIS[MEMRESIFG21] Bits */
#define ADC12_CPU_INT_MIS_MEMRESIFG21_OFS        (29)                            /* !< MEMRESIFG21 Offset */
#define ADC12_CPU_INT_MIS_MEMRESIFG21_MASK       ((uint32_t)0x20000000U)         /* !< Raw interrupt status for MEMRES21.
                                                                                    This bit is set to 1 when MEMRES21 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES21 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_MIS_MEMRESIFG21_CLR        ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_MIS_MEMRESIFG21_SET        ((uint32_t)0x20000000U)         /* !< A new data is ready to be read. */

/* ADC12_CPU_INT_ISET Bits */
/* ADC12_CPU_INT_ISET[INIFG] Bits */
#define ADC12_CPU_INT_ISET_INIFG_OFS             (4)                             /* !< INIFG Offset */
#define ADC12_CPU_INT_ISET_INIFG_MASK            ((uint32_t)0x00000010U)         /* !< Mask INIFG in MIS_EX register. */
#define ADC12_CPU_INT_ISET_INIFG_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ISET_INIFG_SET             ((uint32_t)0x00000010U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ISET[LOWIFG] Bits */
#define ADC12_CPU_INT_ISET_LOWIFG_OFS            (3)                             /* !< LOWIFG Offset */
#define ADC12_CPU_INT_ISET_LOWIFG_MASK           ((uint32_t)0x00000008U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being below than the
                                                                                    WCLOWx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_ISET_LOWIFG_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ISET_LOWIFG_SET            ((uint32_t)0x00000008U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ISET[HIGHIFG] Bits */
#define ADC12_CPU_INT_ISET_HIGHIFG_OFS           (2)                             /* !< HIGHIFG Offset */
#define ADC12_CPU_INT_ISET_HIGHIFG_MASK          ((uint32_t)0x00000004U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being higher than the
                                                                                    WCHIGHx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_ISET_HIGHIFG_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ISET_HIGHIFG_SET           ((uint32_t)0x00000004U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ISET[OVIFG] Bits */
#define ADC12_CPU_INT_ISET_OVIFG_OFS             (0)                             /* !< OVIFG Offset */
#define ADC12_CPU_INT_ISET_OVIFG_MASK            ((uint32_t)0x00000001U)         /* !< Raw interrupt flag for MEMRESx
                                                                                    overflow. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_ISET_OVIFG_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ISET_OVIFG_SET             ((uint32_t)0x00000001U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ISET[UVIFG] Bits */
#define ADC12_CPU_INT_ISET_UVIFG_OFS             (6)                             /* !< UVIFG Offset */
#define ADC12_CPU_INT_ISET_UVIFG_MASK            ((uint32_t)0x00000040U)         /* !< Raw interrupt flag for MEMRESx
                                                                                    underflow. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_ISET_UVIFG_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ISET_UVIFG_SET             ((uint32_t)0x00000040U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ISET[TOVIFG] Bits */
#define ADC12_CPU_INT_ISET_TOVIFG_OFS            (1)                             /* !< TOVIFG Offset */
#define ADC12_CPU_INT_ISET_TOVIFG_MASK           ((uint32_t)0x00000002U)         /* !< Raw interrupt flag for sequence
                                                                                    conversion timeout overflow. This bit
                                                                                    is reset to 0 by IIDX read or when
                                                                                    corresponding bit in ICLR_EX is set
                                                                                    to 1. */
#define ADC12_CPU_INT_ISET_TOVIFG_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ISET_TOVIFG_SET            ((uint32_t)0x00000002U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ISET[DMADONE] Bits */
#define ADC12_CPU_INT_ISET_DMADONE_OFS           (5)                             /* !< DMADONE Offset */
#define ADC12_CPU_INT_ISET_DMADONE_MASK          ((uint32_t)0x00000020U)         /* !< Raw interrupt flag for DMADONE.
                                                                                    This bit is reset to 0 by IIDX read
                                                                                    or when corresponding bit in ICLR_EX
                                                                                    is set to 1. */
#define ADC12_CPU_INT_ISET_DMADONE_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ISET_DMADONE_SET           ((uint32_t)0x00000020U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ISET[MEMRESIFG0] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG0_OFS        (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG0_MASK       ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG0_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG0_SET        ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG1] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG1_OFS        (9)                             /* !< MEMRESIFG1 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG1_MASK       ((uint32_t)0x00000200U)         /* !< Raw interrupt status for MEMRES1.
                                                                                    This bit is set to 1 when MEMRES1 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES1 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG1_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG1_SET        ((uint32_t)0x00000200U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG2] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG2_OFS        (10)                            /* !< MEMRESIFG2 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG2_MASK       ((uint32_t)0x00000400U)         /* !< Raw interrupt status for MEMRES2.
                                                                                    This bit is set to 1 when MEMRES2 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES2 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG2_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG2_SET        ((uint32_t)0x00000400U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG3] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG3_OFS        (11)                            /* !< MEMRESIFG3 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG3_MASK       ((uint32_t)0x00000800U)         /* !< Raw interrupt status for MEMRES3.
                                                                                    This bit is set to 1 when MEMRES3 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES3 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG3_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG3_SET        ((uint32_t)0x00000800U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG4] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG4_OFS        (12)                            /* !< MEMRESIFG4 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG4_MASK       ((uint32_t)0x00001000U)         /* !< Raw interrupt status for MEMRES4.
                                                                                    This bit is set to 1 when MEMRES4 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES4 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG4_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG4_SET        ((uint32_t)0x00001000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG5] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG5_OFS        (13)                            /* !< MEMRESIFG5 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG5_MASK       ((uint32_t)0x00002000U)         /* !< Raw interrupt status for MEMRES5.
                                                                                    This bit is set to 1 when MEMRES5 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES5 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG5_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG5_SET        ((uint32_t)0x00002000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG6] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG6_OFS        (14)                            /* !< MEMRESIFG6 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG6_MASK       ((uint32_t)0x00004000U)         /* !< Raw interrupt status for MEMRES6.
                                                                                    This bit is set to 1 when MEMRES6 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES6 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG6_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG6_SET        ((uint32_t)0x00004000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG7] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG7_OFS        (15)                            /* !< MEMRESIFG7 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG7_MASK       ((uint32_t)0x00008000U)         /* !< Raw interrupt status for MEMRES7.
                                                                                    This bit is set to 1 when MEMRES7 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES7 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG7_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG7_SET        ((uint32_t)0x00008000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG9] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG9_OFS        (17)                            /* !< MEMRESIFG9 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG9_MASK       ((uint32_t)0x00020000U)         /* !< Raw interrupt status for MEMRES9.
                                                                                    This bit is set to 1 when MEMRES9 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES9 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG9_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG9_SET        ((uint32_t)0x00020000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG10] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG10_OFS       (18)                            /* !< MEMRESIFG10 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG10_MASK      ((uint32_t)0x00040000U)         /* !< Raw interrupt status for MEMRES10.
                                                                                    This bit is set to 1 when MEMRES10 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES10 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG10_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG10_SET       ((uint32_t)0x00040000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG11] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG11_OFS       (19)                            /* !< MEMRESIFG11 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG11_MASK      ((uint32_t)0x00080000U)         /* !< Raw interrupt status for MEMRES11.
                                                                                    This bit is set to 1 when MEMRES11 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES11 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG11_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG11_SET       ((uint32_t)0x00080000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG12] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG12_OFS       (20)                            /* !< MEMRESIFG12 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG12_MASK      ((uint32_t)0x00100000U)         /* !< Raw interrupt status for MEMRES12.
                                                                                    This bit is set to 1 when MEMRES12 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES12 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG12_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG12_SET       ((uint32_t)0x00100000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG13] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG13_OFS       (21)                            /* !< MEMRESIFG13 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG13_MASK      ((uint32_t)0x00200000U)         /* !< Raw interrupt status for MEMRES13.
                                                                                    This bit is set to 1 when MEMRES13 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES13 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG13_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG13_SET       ((uint32_t)0x00200000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG14] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG14_OFS       (22)                            /* !< MEMRESIFG14 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG14_MASK      ((uint32_t)0x00400000U)         /* !< Raw interrupt status for MEMRES14.
                                                                                    This bit is set to 1 when MEMRES14 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES14 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG14_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG14_SET       ((uint32_t)0x00400000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG15] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG15_OFS       (23)                            /* !< MEMRESIFG15 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG15_MASK      ((uint32_t)0x00800000U)         /* !< Raw interrupt status for MEMRES15.
                                                                                    This bit is set to 1 when MEMRES15 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES15 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG15_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG15_SET       ((uint32_t)0x00800000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG16] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG16_OFS       (24)                            /* !< MEMRESIFG16 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG16_MASK      ((uint32_t)0x01000000U)         /* !< Raw interrupt status for MEMRES16.
                                                                                    This bit is set to 1 when MEMRES16 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES16 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG16_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG16_SET       ((uint32_t)0x01000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG17] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG17_OFS       (25)                            /* !< MEMRESIFG17 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG17_MASK      ((uint32_t)0x02000000U)         /* !< Raw interrupt status for MEMRES17.
                                                                                    This bit is set to 1 when MEMRES17 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES17 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG17_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG17_SET       ((uint32_t)0x02000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG18] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG18_OFS       (26)                            /* !< MEMRESIFG18 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG18_MASK      ((uint32_t)0x04000000U)         /* !< Raw interrupt status for MEMRES18.
                                                                                    This bit is set to 1 when MEMRES18 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES18 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG18_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG18_SET       ((uint32_t)0x04000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG19] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG19_OFS       (27)                            /* !< MEMRESIFG19 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG19_MASK      ((uint32_t)0x08000000U)         /* !< Raw interrupt status for MEMRES19.
                                                                                    This bit is set to 1 when MEMRES19 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES19 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG19_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG19_SET       ((uint32_t)0x08000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG20] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG20_OFS       (28)                            /* !< MEMRESIFG20 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG20_MASK      ((uint32_t)0x10000000U)         /* !< Raw interrupt status for MEMRES20.
                                                                                    This bit is set to 1 when MEMRES20 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES20 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG20_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG20_SET       ((uint32_t)0x10000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG22] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG22_OFS       (30)                            /* !< MEMRESIFG22 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG22_MASK      ((uint32_t)0x40000000U)         /* !< Raw interrupt status for MEMRES22.
                                                                                    This bit is set to 1 when MEMRES22 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES22 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG22_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG22_SET       ((uint32_t)0x40000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG23] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG23_OFS       (31)                            /* !< MEMRESIFG23 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG23_MASK      ((uint32_t)0x80000000U)         /* !< Raw interrupt status for MEMRES23.
                                                                                    This bit is set to 1 when MEMRES23 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES23 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG23_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG23_SET       ((uint32_t)0x80000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG8] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG8_OFS        (16)                            /* !< MEMRESIFG8 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG8_MASK       ((uint32_t)0x00010000U)         /* !< Raw interrupt status for MEMRES8.
                                                                                    This bit is set to 1 when MEMRES8 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES8 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG8_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG8_SET        ((uint32_t)0x00010000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ISET[MEMRESIFG21] Bits */
#define ADC12_CPU_INT_ISET_MEMRESIFG21_OFS       (29)                            /* !< MEMRESIFG21 Offset */
#define ADC12_CPU_INT_ISET_MEMRESIFG21_MASK      ((uint32_t)0x20000000U)         /* !< Raw interrupt status for MEMRES21.
                                                                                    This bit is set to 1 when MEMRES21 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES21 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ISET_MEMRESIFG21_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ISET_MEMRESIFG21_SET       ((uint32_t)0x20000000U)         /* !< A new data is ready to be read. */

/* ADC12_CPU_INT_ICLR Bits */
/* ADC12_CPU_INT_ICLR[INIFG] Bits */
#define ADC12_CPU_INT_ICLR_INIFG_OFS             (4)                             /* !< INIFG Offset */
#define ADC12_CPU_INT_ICLR_INIFG_MASK            ((uint32_t)0x00000010U)         /* !< Mask INIFG in MIS_EX register. */
#define ADC12_CPU_INT_ICLR_INIFG_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ICLR_INIFG_CLR             ((uint32_t)0x00000010U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ICLR[LOWIFG] Bits */
#define ADC12_CPU_INT_ICLR_LOWIFG_OFS            (3)                             /* !< LOWIFG Offset */
#define ADC12_CPU_INT_ICLR_LOWIFG_MASK           ((uint32_t)0x00000008U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being below than the
                                                                                    WCLOWx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_ICLR_LOWIFG_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ICLR_LOWIFG_CLR            ((uint32_t)0x00000008U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ICLR[HIGHIFG] Bits */
#define ADC12_CPU_INT_ICLR_HIGHIFG_OFS           (2)                             /* !< HIGHIFG Offset */
#define ADC12_CPU_INT_ICLR_HIGHIFG_MASK          ((uint32_t)0x00000004U)         /* !< Raw interrupt flag for the MEMRESx
                                                                                    result register being higher than the
                                                                                    WCHIGHx threshold of the window
                                                                                    comparator. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_ICLR_HIGHIFG_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ICLR_HIGHIFG_CLR           ((uint32_t)0x00000004U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ICLR[OVIFG] Bits */
#define ADC12_CPU_INT_ICLR_OVIFG_OFS             (0)                             /* !< OVIFG Offset */
#define ADC12_CPU_INT_ICLR_OVIFG_MASK            ((uint32_t)0x00000001U)         /* !< Raw interrupt flag for MEMRESx
                                                                                    overflow. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_ICLR_OVIFG_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ICLR_OVIFG_CLR             ((uint32_t)0x00000001U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ICLR[UVIFG] Bits */
#define ADC12_CPU_INT_ICLR_UVIFG_OFS             (6)                             /* !< UVIFG Offset */
#define ADC12_CPU_INT_ICLR_UVIFG_MASK            ((uint32_t)0x00000040U)         /* !< Raw interrupt flag for MEMRESx
                                                                                    underflow. This bit is reset to 0 by
                                                                                    IIDX read or when corresponding bit
                                                                                    in ICLR_EX is set to 1. */
#define ADC12_CPU_INT_ICLR_UVIFG_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ICLR_UVIFG_CLR             ((uint32_t)0x00000040U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ICLR[TOVIFG] Bits */
#define ADC12_CPU_INT_ICLR_TOVIFG_OFS            (1)                             /* !< TOVIFG Offset */
#define ADC12_CPU_INT_ICLR_TOVIFG_MASK           ((uint32_t)0x00000002U)         /* !< Raw interrupt flag for sequence
                                                                                    conversion timeout overflow. This bit
                                                                                    is reset to 0 by IIDX read or when
                                                                                    corresponding bit in ICLR_EX is set
                                                                                    to 1. */
#define ADC12_CPU_INT_ICLR_TOVIFG_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ICLR_TOVIFG_CLR            ((uint32_t)0x00000002U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ICLR[DMADONE] Bits */
#define ADC12_CPU_INT_ICLR_DMADONE_OFS           (5)                             /* !< DMADONE Offset */
#define ADC12_CPU_INT_ICLR_DMADONE_MASK          ((uint32_t)0x00000020U)         /* !< Raw interrupt flag for DMADONE.
                                                                                    This bit is reset to 0 by IIDX read
                                                                                    or when corresponding bit in ICLR_EX
                                                                                    is set to 1. */
#define ADC12_CPU_INT_ICLR_DMADONE_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Interrupt is not pending. */
#define ADC12_CPU_INT_ICLR_DMADONE_CLR           ((uint32_t)0x00000020U)         /* !< Interrupt is pending. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG0] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG0_OFS        (8)                             /* !< MEMRESIFG0 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG0_MASK       ((uint32_t)0x00000100U)         /* !< Raw interrupt status for MEMRES0.
                                                                                    This bit is set to 1 when MEMRES0 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES0 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG0_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG0_CLR        ((uint32_t)0x00000100U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG1] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG1_OFS        (9)                             /* !< MEMRESIFG1 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG1_MASK       ((uint32_t)0x00000200U)         /* !< Raw interrupt status for MEMRES1.
                                                                                    This bit is set to 1 when MEMRES1 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES1 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG1_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG1_CLR        ((uint32_t)0x00000200U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG2] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG2_OFS        (10)                            /* !< MEMRESIFG2 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG2_MASK       ((uint32_t)0x00000400U)         /* !< Raw interrupt status for MEMRES2.
                                                                                    This bit is set to 1 when MEMRES2 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES2 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG2_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG2_CLR        ((uint32_t)0x00000400U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG3] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG3_OFS        (11)                            /* !< MEMRESIFG3 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG3_MASK       ((uint32_t)0x00000800U)         /* !< Raw interrupt status for MEMRES3.
                                                                                    This bit is set to 1 when MEMRES3 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES3 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG3_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG3_CLR        ((uint32_t)0x00000800U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG4] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG4_OFS        (12)                            /* !< MEMRESIFG4 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG4_MASK       ((uint32_t)0x00001000U)         /* !< Raw interrupt status for MEMRES4.
                                                                                    This bit is set to 1 when MEMRES4 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES4 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG4_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG4_CLR        ((uint32_t)0x00001000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG5] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG5_OFS        (13)                            /* !< MEMRESIFG5 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG5_MASK       ((uint32_t)0x00002000U)         /* !< Raw interrupt status for MEMRES5.
                                                                                    This bit is set to 1 when MEMRES5 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES5 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG5_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG5_CLR        ((uint32_t)0x00002000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG6] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG6_OFS        (14)                            /* !< MEMRESIFG6 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG6_MASK       ((uint32_t)0x00004000U)         /* !< Raw interrupt status for MEMRES6.
                                                                                    This bit is set to 1 when MEMRES6 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES6 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG6_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG6_CLR        ((uint32_t)0x00004000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG7] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG7_OFS        (15)                            /* !< MEMRESIFG7 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG7_MASK       ((uint32_t)0x00008000U)         /* !< Raw interrupt status for MEMRES7.
                                                                                    This bit is set to 1 when MEMRES7 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES7 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG7_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG7_CLR        ((uint32_t)0x00008000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG9] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG9_OFS        (17)                            /* !< MEMRESIFG9 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG9_MASK       ((uint32_t)0x00020000U)         /* !< Raw interrupt status for MEMRES9.
                                                                                    This bit is set to 1 when MEMRES9 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES9 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG9_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG9_CLR        ((uint32_t)0x00020000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG10] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG10_OFS       (18)                            /* !< MEMRESIFG10 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG10_MASK      ((uint32_t)0x00040000U)         /* !< Raw interrupt status for MEMRES10.
                                                                                    This bit is set to 1 when MEMRES10 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES10 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG10_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG10_CLR       ((uint32_t)0x00040000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG11] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG11_OFS       (19)                            /* !< MEMRESIFG11 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG11_MASK      ((uint32_t)0x00080000U)         /* !< Raw interrupt status for MEMRES11.
                                                                                    This bit is set to 1 when MEMRES11 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES11 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG11_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG11_CLR       ((uint32_t)0x00080000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG12] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG12_OFS       (20)                            /* !< MEMRESIFG12 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG12_MASK      ((uint32_t)0x00100000U)         /* !< Raw interrupt status for MEMRES12.
                                                                                    This bit is set to 1 when MEMRES12 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES12 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG12_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG12_CLR       ((uint32_t)0x00100000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG13] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG13_OFS       (21)                            /* !< MEMRESIFG13 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG13_MASK      ((uint32_t)0x00200000U)         /* !< Raw interrupt status for MEMRES13.
                                                                                    This bit is set to 1 when MEMRES13 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES13 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG13_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG13_CLR       ((uint32_t)0x00200000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG14] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG14_OFS       (22)                            /* !< MEMRESIFG14 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG14_MASK      ((uint32_t)0x00400000U)         /* !< Raw interrupt status for MEMRES14.
                                                                                    This bit is set to 1 when MEMRES14 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES14 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG14_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG14_CLR       ((uint32_t)0x00400000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG15] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG15_OFS       (23)                            /* !< MEMRESIFG15 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG15_MASK      ((uint32_t)0x00800000U)         /* !< Raw interrupt status for MEMRES15.
                                                                                    This bit is set to 1 when MEMRES15 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES15 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG15_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG15_CLR       ((uint32_t)0x00800000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG16] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG16_OFS       (24)                            /* !< MEMRESIFG16 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG16_MASK      ((uint32_t)0x01000000U)         /* !< Raw interrupt status for MEMRES16.
                                                                                    This bit is set to 1 when MEMRES16 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES16 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG16_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG16_CLR       ((uint32_t)0x01000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG17] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG17_OFS       (25)                            /* !< MEMRESIFG17 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG17_MASK      ((uint32_t)0x02000000U)         /* !< Raw interrupt status for MEMRES17.
                                                                                    This bit is set to 1 when MEMRES17 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES17 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG17_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG17_CLR       ((uint32_t)0x02000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG18] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG18_OFS       (26)                            /* !< MEMRESIFG18 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG18_MASK      ((uint32_t)0x04000000U)         /* !< Raw interrupt status for MEMRES18.
                                                                                    This bit is set to 1 when MEMRES18 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES18 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG18_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG18_CLR       ((uint32_t)0x04000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG19] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG19_OFS       (27)                            /* !< MEMRESIFG19 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG19_MASK      ((uint32_t)0x08000000U)         /* !< Raw interrupt status for MEMRES19.
                                                                                    This bit is set to 1 when MEMRES19 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES19 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG19_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG19_CLR       ((uint32_t)0x08000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG20] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG20_OFS       (28)                            /* !< MEMRESIFG20 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG20_MASK      ((uint32_t)0x10000000U)         /* !< Raw interrupt status for MEMRES20.
                                                                                    This bit is set to 1 when MEMRES20 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES20 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG20_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG20_CLR       ((uint32_t)0x10000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG22] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG22_OFS       (30)                            /* !< MEMRESIFG22 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG22_MASK      ((uint32_t)0x40000000U)         /* !< Raw interrupt status for MEMRES22.
                                                                                    This bit is set to 1 when MEMRES22 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES22 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG22_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG22_CLR       ((uint32_t)0x40000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG23] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG23_OFS       (31)                            /* !< MEMRESIFG23 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG23_MASK      ((uint32_t)0x80000000U)         /* !< Raw interrupt status for MEMRES23.
                                                                                    This bit is set to 1 when MEMRES23 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES23 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG23_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG23_CLR       ((uint32_t)0x80000000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG8] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG8_OFS        (16)                            /* !< MEMRESIFG8 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG8_MASK       ((uint32_t)0x00010000U)         /* !< Raw interrupt status for MEMRES8.
                                                                                    This bit is set to 1 when MEMRES8 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES8 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG8_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG8_CLR        ((uint32_t)0x00010000U)         /* !< A new data is ready to be read. */
/* ADC12_CPU_INT_ICLR[MEMRESIFG21] Bits */
#define ADC12_CPU_INT_ICLR_MEMRESIFG21_OFS       (29)                            /* !< MEMRESIFG21 Offset */
#define ADC12_CPU_INT_ICLR_MEMRESIFG21_MASK      ((uint32_t)0x20000000U)         /* !< Raw interrupt status for MEMRES21.
                                                                                    This bit is set to 1 when MEMRES21 is
                                                                                    loaded with a new conversion result.
                                                                                    Reading MEMRES21 register will clear
                                                                                    this bit, or when the corresponding
                                                                                    bit in ICLR is set to 1 */
#define ADC12_CPU_INT_ICLR_MEMRESIFG21_NO_EFFECT ((uint32_t)0x00000000U)         /* !< No new data ready. */
#define ADC12_CPU_INT_ICLR_MEMRESIFG21_CLR       ((uint32_t)0x20000000U)         /* !< A new data is ready to be read. */

/* ADC12_PWREN Bits */
/* ADC12_PWREN[ENABLE] Bits */
#define ADC12_PWREN_ENABLE_OFS                   (0)                             /* !< ENABLE Offset */
#define ADC12_PWREN_ENABLE_MASK                  ((uint32_t)0x00000001U)         /* !< Enable the power */
#define ADC12_PWREN_ENABLE_DISABLE               ((uint32_t)0x00000000U)         /* !< Disable Power */
#define ADC12_PWREN_ENABLE_ENABLE                ((uint32_t)0x00000001U)         /* !< Enable Power */
/* ADC12_PWREN[KEY] Bits */
#define ADC12_PWREN_KEY_OFS                      (24)                            /* !< KEY Offset */
#define ADC12_PWREN_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define ADC12_PWREN_KEY_UNLOCK_W                 ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* ADC12_RSTCTL Bits */
/* ADC12_RSTCTL[RESETSTKYCLR] Bits */
#define ADC12_RSTCTL_RESETSTKYCLR_OFS            (1)                             /* !< RESETSTKYCLR Offset */
#define ADC12_RSTCTL_RESETSTKYCLR_MASK           ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define ADC12_RSTCTL_RESETSTKYCLR_NOP            ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define ADC12_RSTCTL_RESETSTKYCLR_CLR            ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* ADC12_RSTCTL[RESETASSERT] Bits */
#define ADC12_RSTCTL_RESETASSERT_OFS             (0)                             /* !< RESETASSERT Offset */
#define ADC12_RSTCTL_RESETASSERT_MASK            ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define ADC12_RSTCTL_RESETASSERT_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define ADC12_RSTCTL_RESETASSERT_ASSERT          ((uint32_t)0x00000001U)         /* !< Assert reset */
/* ADC12_RSTCTL[KEY] Bits */
#define ADC12_RSTCTL_KEY_OFS                     (24)                            /* !< KEY Offset */
#define ADC12_RSTCTL_KEY_MASK                    ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define ADC12_RSTCTL_KEY_UNLOCK_W                ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* ADC12_CLKCFG Bits */
/* ADC12_CLKCFG[SAMPCLK] Bits */
#define ADC12_CLKCFG_SAMPCLK_OFS                 (0)                             /* !< SAMPCLK Offset */
#define ADC12_CLKCFG_SAMPCLK_MASK                ((uint32_t)0x00000003U)         /* !< ADC sample clock source selection. */
#define ADC12_CLKCFG_SAMPCLK_ULPCLK              ((uint32_t)0x00000000U)         /* !< ULPCLK is the source of ADC sample
                                                                                    clock. */
#define ADC12_CLKCFG_SAMPCLK_SYSOSC              ((uint32_t)0x00000001U)         /* !< SYSOSC is the source of ADC sample
                                                                                    clock. */
#define ADC12_CLKCFG_SAMPCLK_HFCLK               ((uint32_t)0x00000002U)         /* !< HFCLK clock is the source of ADC
                                                                                    sample clock. Note : HFCLK may not be
                                                                                    available on all the devices. */
/* ADC12_CLKCFG[CCONRUN] Bits */
#define ADC12_CLKCFG_CCONRUN_OFS                 (4)                             /* !< CCONRUN Offset */
#define ADC12_CLKCFG_CCONRUN_MASK                ((uint32_t)0x00000010U)         /* !< CCONRUN: Forces SYSOSC to run at
                                                                                    base frequency when device is in RUN
                                                                                    mode which can be used as ADC sample
                                                                                    or conversion clock source. */
#define ADC12_CLKCFG_CCONRUN_DISABLE             ((uint32_t)0x00000000U)         /* !< ADC conversion clock source is not
                                                                                    kept continuously on during RUN mode. */
#define ADC12_CLKCFG_CCONRUN_ENABLE              ((uint32_t)0x00000010U)         /* !< ADC conversion clock source kept
                                                                                    continuously on during RUN mode. */
/* ADC12_CLKCFG[CCONSTOP] Bits */
#define ADC12_CLKCFG_CCONSTOP_OFS                (5)                             /* !< CCONSTOP Offset */
#define ADC12_CLKCFG_CCONSTOP_MASK               ((uint32_t)0x00000020U)         /* !< CCONSTOP: Forces SYSOSC to run at
                                                                                    base frequency when device is in STOP
                                                                                    mode which can be used as ADC sample
                                                                                    or conversion clock source. */
#define ADC12_CLKCFG_CCONSTOP_DISABLE            ((uint32_t)0x00000000U)         /* !< ADC conversion clock source is not
                                                                                    kept continuously on during STOP
                                                                                    mode. */
#define ADC12_CLKCFG_CCONSTOP_ENABLE             ((uint32_t)0x00000020U)         /* !< ADC conversion clock source kept
                                                                                    continuously on during STOP mode. */
/* ADC12_CLKCFG[KEY] Bits */
#define ADC12_CLKCFG_KEY_OFS                     (24)                            /* !< KEY Offset */
#define ADC12_CLKCFG_KEY_MASK                    ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define ADC12_CLKCFG_KEY_UNLOCK_W                ((uint32_t)0xA9000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* ADC12_STAT Bits */
/* ADC12_STAT[RESETSTKY] Bits */
#define ADC12_STAT_RESETSTKY_OFS                 (16)                            /* !< RESETSTKY Offset */
#define ADC12_STAT_RESETSTKY_MASK                ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define ADC12_STAT_RESETSTKY_NORES               ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define ADC12_STAT_RESETSTKY_RESET               ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* ADC12_FSUB_0 Bits */
/* ADC12_FSUB_0[CHANID] Bits */
#define ADC12_FSUB_0_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define ADC12_FSUB_0_CHANID_MASK                 ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define ADC12_FSUB_0_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define ADC12_FSUB_0_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define ADC12_FSUB_0_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 255. */

/* ADC12_FPUB_1 Bits */
/* ADC12_FPUB_1[CHANID] Bits */
#define ADC12_FPUB_1_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define ADC12_FPUB_1_CHANID_MASK                 ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define ADC12_FPUB_1_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define ADC12_FPUB_1_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define ADC12_FPUB_1_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 255. */

/* ADC12_EVT_MODE Bits */
/* ADC12_EVT_MODE[INT0_CFG] Bits */
#define ADC12_EVT_MODE_INT0_CFG_OFS              (0)                             /* !< INT0_CFG Offset */
#define ADC12_EVT_MODE_INT0_CFG_MASK             ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to CPU_INT */
#define ADC12_EVT_MODE_INT0_CFG_DISABLE          ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define ADC12_EVT_MODE_INT0_CFG_SOFTWARE         ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define ADC12_EVT_MODE_INT0_CFG_HARDWARE         ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* ADC12_EVT_MODE[EVT1_CFG] Bits */
#define ADC12_EVT_MODE_EVT1_CFG_OFS              (2)                             /* !< EVT1_CFG Offset */
#define ADC12_EVT_MODE_EVT1_CFG_MASK             ((uint32_t)0x0000000CU)         /* !< Event line mode select for event
                                                                                    corresponding to GEN_EVENT */
#define ADC12_EVT_MODE_EVT1_CFG_DISABLE          ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define ADC12_EVT_MODE_EVT1_CFG_SOFTWARE         ((uint32_t)0x00000004U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define ADC12_EVT_MODE_EVT1_CFG_HARDWARE         ((uint32_t)0x00000008U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* ADC12_DESC Bits */
/* ADC12_DESC[MINREV] Bits */
#define ADC12_DESC_MINREV_OFS                    (0)                             /* !< MINREV Offset */
#define ADC12_DESC_MINREV_MASK                   ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
#define ADC12_DESC_MINREV_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define ADC12_DESC_MINREV_MAXIMUM                ((uint32_t)0x0000000FU)         /* !< Highest possible value */
/* ADC12_DESC[MAJREV] Bits */
#define ADC12_DESC_MAJREV_OFS                    (4)                             /* !< MAJREV Offset */
#define ADC12_DESC_MAJREV_MASK                   ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
#define ADC12_DESC_MAJREV_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define ADC12_DESC_MAJREV_MAXIMUM                ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* ADC12_DESC[INSTNUM] Bits */
#define ADC12_DESC_INSTNUM_OFS                   (8)                             /* !< INSTNUM Offset */
#define ADC12_DESC_INSTNUM_MASK                  ((uint32_t)0x00000F00U)         /* !< Instance Number within the device.
                                                                                    This will be a parameter to the RTL
                                                                                    for modules that can have multiple
                                                                                    instances */
/* ADC12_DESC[FEATUREVER] Bits */
#define ADC12_DESC_FEATUREVER_OFS                (12)                            /* !< FEATUREVER Offset */
#define ADC12_DESC_FEATUREVER_MASK               ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
#define ADC12_DESC_FEATUREVER_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define ADC12_DESC_FEATUREVER_MAXIMUM            ((uint32_t)0x0000F000U)         /* !< Highest possible value */
/* ADC12_DESC[MODULEID] Bits */
#define ADC12_DESC_MODULEID_OFS                  (16)                            /* !< MODULEID Offset */
#define ADC12_DESC_MODULEID_MASK                 ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */
#define ADC12_DESC_MODULEID_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define ADC12_DESC_MODULEID_MAXIMUM              ((uint32_t)0xFFFF0000U)         /* !< Highest possible value */

/* ADC12_CTL0 Bits */
/* ADC12_CTL0[ENC] Bits */
#define ADC12_CTL0_ENC_OFS                       (0)                             /* !< ENC Offset */
#define ADC12_CTL0_ENC_MASK                      ((uint32_t)0x00000001U)         /* !< Enable conversion */
#define ADC12_CTL0_ENC_OFF                       ((uint32_t)0x00000000U)         /* !< Conversion disabled. ENC change
                                                                                    from ON to OFF will abort single or
                                                                                    repeat sequence on a MEMCTLx
                                                                                    boundary. The current conversion will
                                                                                    finish and result stored in
                                                                                    corresponding MEMRESx. */
#define ADC12_CTL0_ENC_ON                        ((uint32_t)0x00000001U)         /* !< Conversion enabled. ADC sequencer
                                                                                    waits for valid trigger (software or
                                                                                    hardware). */
/* ADC12_CTL0[PWRDN] Bits */
#define ADC12_CTL0_PWRDN_OFS                     (16)                            /* !< PWRDN Offset */
#define ADC12_CTL0_PWRDN_MASK                    ((uint32_t)0x00010000U)         /* !< Power down policy */
#define ADC12_CTL0_PWRDN_AUTO                    ((uint32_t)0x00000000U)         /* !< ADC is powered down on completion
                                                                                    of a conversion if there is no
                                                                                    pending trigger */
#define ADC12_CTL0_PWRDN_MANUAL                  ((uint32_t)0x00010000U)         /* !< ADC remains powered on as long as
                                                                                    it is enabled through software. */
/* ADC12_CTL0[SCLKDIV] Bits */
#define ADC12_CTL0_SCLKDIV_OFS                   (24)                            /* !< SCLKDIV Offset */
#define ADC12_CTL0_SCLKDIV_MASK                  ((uint32_t)0x07000000U)         /* !< Sample clock divider */
#define ADC12_CTL0_SCLKDIV_DIV_BY_1              ((uint32_t)0x00000000U)         /* !< Do not divide clock source */
#define ADC12_CTL0_SCLKDIV_DIV_BY_2              ((uint32_t)0x01000000U)         /* !< Divide clock source by 2 */
#define ADC12_CTL0_SCLKDIV_DIV_BY_4              ((uint32_t)0x02000000U)         /* !< Divide clock source by 4 */
#define ADC12_CTL0_SCLKDIV_DIV_BY_8              ((uint32_t)0x03000000U)         /* !< Divide clock source by 8 */
#define ADC12_CTL0_SCLKDIV_DIV_BY_16             ((uint32_t)0x04000000U)         /* !< Divide clock source by 16 */
#define ADC12_CTL0_SCLKDIV_DIV_BY_24             ((uint32_t)0x05000000U)         /* !< Divide clock source by 24 */
#define ADC12_CTL0_SCLKDIV_DIV_BY_32             ((uint32_t)0x06000000U)         /* !< Divide clock source by 32 */
#define ADC12_CTL0_SCLKDIV_DIV_BY_48             ((uint32_t)0x07000000U)         /* !< Divide clock source by 48 */

/* ADC12_CTL1 Bits */
/* ADC12_CTL1[TRIGSRC] Bits */
#define ADC12_CTL1_TRIGSRC_OFS                   (0)                             /* !< TRIGSRC Offset */
#define ADC12_CTL1_TRIGSRC_MASK                  ((uint32_t)0x00000001U)         /* !< Sample trigger source */
#define ADC12_CTL1_TRIGSRC_SOFTWARE              ((uint32_t)0x00000000U)         /* !< Software trigger */
#define ADC12_CTL1_TRIGSRC_EVENT                 ((uint32_t)0x00000001U)         /* !< Hardware event trigger */
/* ADC12_CTL1[SC] Bits */
#define ADC12_CTL1_SC_OFS                        (8)                             /* !< SC Offset */
#define ADC12_CTL1_SC_MASK                       ((uint32_t)0x00000100U)         /* !< Start of conversion */
#define ADC12_CTL1_SC_STOP                       ((uint32_t)0x00000000U)         /* !< When SAMPMODE is set to MANUAL,
                                                                                    clearing this bit will end the sample
                                                                                    phase and the conversion phase will
                                                                                    start. When SAMPMODE is set to AUTO,
                                                                                    writing 0 has no effect. */
#define ADC12_CTL1_SC_START                      ((uint32_t)0x00000100U)         /* !< When SAMPMODE is set to MANUAL,
                                                                                    setting this bit will start the
                                                                                    sample phase. Sample phase will last
                                                                                    as long as this bit is set.  When
                                                                                    SAMPMODE is set to AUTO, setting this
                                                                                    bit will trigger the timer based
                                                                                    sample time. */
/* ADC12_CTL1[CONSEQ] Bits */
#define ADC12_CTL1_CONSEQ_OFS                    (16)                            /* !< CONSEQ Offset */
#define ADC12_CTL1_CONSEQ_MASK                   ((uint32_t)0x00030000U)         /* !< Conversion sequence mode */
#define ADC12_CTL1_CONSEQ_SINGLE                 ((uint32_t)0x00000000U)         /* !< ADC channel in MEMCTLx pointed by
                                                                                    STARTADD will be converted once */
#define ADC12_CTL1_CONSEQ_SEQUENCE               ((uint32_t)0x00010000U)         /* !< ADC channel sequence pointed by
                                                                                    STARTADD and ENDADD will be converted
                                                                                    once */
#define ADC12_CTL1_CONSEQ_REPEATSINGLE           ((uint32_t)0x00020000U)         /* !< ADC channel in MEMCTLx pointed by
                                                                                    STARTADD will be converted repeatedly */
#define ADC12_CTL1_CONSEQ_REPEATSEQUENCE         ((uint32_t)0x00030000U)         /* !< ADC channel sequence pointed by
                                                                                    STARTADD and ENDADD will be converted
                                                                                    repeatedly */
/* ADC12_CTL1[SAMPMODE] Bits */
#define ADC12_CTL1_SAMPMODE_OFS                  (20)                            /* !< SAMPMODE Offset */
#define ADC12_CTL1_SAMPMODE_MASK                 ((uint32_t)0x00100000U)         /* !< Sample mode. This bit selects the
                                                                                    source of the sampling signal.
                                                                                    MANUAL option is not valid when
                                                                                    TRIGSRC is selected as hardware event
                                                                                    trigger. */
#define ADC12_CTL1_SAMPMODE_AUTO                 ((uint32_t)0x00000000U)         /* !< Sample timer high phase is used as
                                                                                    sample signal */
#define ADC12_CTL1_SAMPMODE_MANUAL               ((uint32_t)0x00100000U)         /* !< Software trigger is used as sample
                                                                                    signal */
/* ADC12_CTL1[AVGN] Bits */
#define ADC12_CTL1_AVGN_OFS                      (24)                            /* !< AVGN Offset */
#define ADC12_CTL1_AVGN_MASK                     ((uint32_t)0x07000000U)         /* !< Hardware averager numerator.
                                                                                    Selects number of conversions to
                                                                                    accumulate for current MEMCTLx and
                                                                                    then it is divided by AVGD. Result
                                                                                    will be stored in MEMRESx. */
#define ADC12_CTL1_AVGN_DISABLE                  ((uint32_t)0x00000000U)         /* !< Disables averager */
#define ADC12_CTL1_AVGN_AVG_2                    ((uint32_t)0x01000000U)         /* !< Averages 2 conversions before
                                                                                    storing in MEMRESx register */
#define ADC12_CTL1_AVGN_AVG_4                    ((uint32_t)0x02000000U)         /* !< Averages 4 conversions before
                                                                                    storing in MEMRESx register */
#define ADC12_CTL1_AVGN_AVG_8                    ((uint32_t)0x03000000U)         /* !< Averages 8 conversions before
                                                                                    storing in MEMRESx register */
#define ADC12_CTL1_AVGN_AVG_16                   ((uint32_t)0x04000000U)         /* !< Averages 16 conversions before
                                                                                    storing in MEMRESx register */
#define ADC12_CTL1_AVGN_AVG_32                   ((uint32_t)0x05000000U)         /* !< Averages 32 conversions before
                                                                                    storing in MEMRESx register */
#define ADC12_CTL1_AVGN_AVG_64                   ((uint32_t)0x06000000U)         /* !< Averages 64 conversions before
                                                                                    storing in MEMRESx register */
#define ADC12_CTL1_AVGN_AVG_128                  ((uint32_t)0x07000000U)         /* !< Averages 128 conversions before
                                                                                    storing in MEMRESx register */
/* ADC12_CTL1[AVGD] Bits */
#define ADC12_CTL1_AVGD_OFS                      (28)                            /* !< AVGD Offset */
#define ADC12_CTL1_AVGD_MASK                     ((uint32_t)0x70000000U)         /* !< Hardware averager denominator. The
                                                                                    number to divide the accumulated
                                                                                    value by (this is a shift). Note
                                                                                    result register is maximum of 16-bits
                                                                                    long so if not shifted appropriately
                                                                                    result will be truncated. */
#define ADC12_CTL1_AVGD_SHIFT0                   ((uint32_t)0x00000000U)         /* !< No shift */
#define ADC12_CTL1_AVGD_SHIFT1                   ((uint32_t)0x10000000U)         /* !< 1 bit shift */
#define ADC12_CTL1_AVGD_SHIFT2                   ((uint32_t)0x20000000U)         /* !< 2 bit shift */
#define ADC12_CTL1_AVGD_SHIFT3                   ((uint32_t)0x30000000U)         /* !< 3 bit shift */
#define ADC12_CTL1_AVGD_SHIFT4                   ((uint32_t)0x40000000U)         /* !< 4 bit shift */
#define ADC12_CTL1_AVGD_SHIFT5                   ((uint32_t)0x50000000U)         /* !< 5 bit shift */
#define ADC12_CTL1_AVGD_SHIFT6                   ((uint32_t)0x60000000U)         /* !< 6 bit shift */
#define ADC12_CTL1_AVGD_SHIFT7                   ((uint32_t)0x70000000U)         /* !< 7 bit shift */

/* ADC12_CTL2 Bits */
/* ADC12_CTL2[DF] Bits */
#define ADC12_CTL2_DF_OFS                        (0)                             /* !< DF Offset */
#define ADC12_CTL2_DF_MASK                       ((uint32_t)0x00000001U)         /* !< Data read-back format. Data is
                                                                                    always stored in binary unsigned
                                                                                    format. */
#define ADC12_CTL2_DF_UNSIGNED                   ((uint32_t)0x00000000U)         /* !< Digital result reads as Binary
                                                                                    Unsigned. */
#define ADC12_CTL2_DF_SIGNED                     ((uint32_t)0x00000001U)         /* !< Digital result reads Signed Binary.
                                                                                    (2s complement), left aligned. */
/* ADC12_CTL2[RES] Bits */
#define ADC12_CTL2_RES_OFS                       (1)                             /* !< RES Offset */
#define ADC12_CTL2_RES_MASK                      ((uint32_t)0x00000006U)         /* !< Resolution. These bits define the
                                                                                    resolution of ADC conversion result.
                                                                                    Note : A value of 3 defaults to
                                                                                    12-bits resolution. */
#define ADC12_CTL2_RES_BIT_12                    ((uint32_t)0x00000000U)         /* !< 12-bits resolution */
#define ADC12_CTL2_RES_BIT_10                    ((uint32_t)0x00000002U)         /* !< 10-bits resolution */
#define ADC12_CTL2_RES_BIT_8                     ((uint32_t)0x00000004U)         /* !< 8-bits resolution */
/* ADC12_CTL2[STARTADD] Bits */
#define ADC12_CTL2_STARTADD_OFS                  (16)                            /* !< STARTADD Offset */
#define ADC12_CTL2_STARTADD_MASK                 ((uint32_t)0x001F0000U)         /* !< Sequencer start address. These bits
                                                                                    select which MEMCTLx is used for
                                                                                    single conversion or as first MEMCTL
                                                                                    for sequence mode.  The value of
                                                                                    STARTADD is 0x00 to 0x17,
                                                                                    corresponding to MEMRES0 to MEMRES23. */
#define ADC12_CTL2_STARTADD_ADDR_00              ((uint32_t)0x00000000U)         /* !< MEMCTL0 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_01              ((uint32_t)0x00010000U)         /* !< MEMCTL1 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_02              ((uint32_t)0x00020000U)         /* !< MEMCTL2 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_03              ((uint32_t)0x00030000U)         /* !< MEMCTL3 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_04              ((uint32_t)0x00040000U)         /* !< MEMCTL4 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_05              ((uint32_t)0x00050000U)         /* !< MEMCTL5 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_06              ((uint32_t)0x00060000U)         /* !< MEMCTL6 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_07              ((uint32_t)0x00070000U)         /* !< MEMCTL7 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_08              ((uint32_t)0x00080000U)         /* !< MEMCTL8 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_09              ((uint32_t)0x00090000U)         /* !< MEMCTL9 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_10              ((uint32_t)0x000A0000U)         /* !< MEMCTL10 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_11              ((uint32_t)0x000B0000U)         /* !< MEMCTL11 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_12              ((uint32_t)0x000C0000U)         /* !< MEMCTL12 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_13              ((uint32_t)0x000D0000U)         /* !< MEMCTL13 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_14              ((uint32_t)0x000E0000U)         /* !< MEMCTL14 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_15              ((uint32_t)0x000F0000U)         /* !< MEMCTL15 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_16              ((uint32_t)0x00100000U)         /* !< MEMCTL16 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_17              ((uint32_t)0x00110000U)         /* !< MEMCTL17 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_18              ((uint32_t)0x00120000U)         /* !< MEMCTL18 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_19              ((uint32_t)0x00130000U)         /* !< MEMCTL19 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_20              ((uint32_t)0x00140000U)         /* !< MEMCTL20 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_21              ((uint32_t)0x00150000U)         /* !< MEMCTL21 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_22              ((uint32_t)0x00160000U)         /* !< MEMCTL22 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
#define ADC12_CTL2_STARTADD_ADDR_23              ((uint32_t)0x00170000U)         /* !< MEMCTL23 is selected as start
                                                                                    address of a sequence or for a single
                                                                                    conversion. */
/* ADC12_CTL2[ENDADD] Bits */
#define ADC12_CTL2_ENDADD_OFS                    (24)                            /* !< ENDADD Offset */
#define ADC12_CTL2_ENDADD_MASK                   ((uint32_t)0x1F000000U)         /* !< Sequence end address. These bits
                                                                                    select which MEMCTLx is the last one
                                                                                    for the sequence mode. The value of
                                                                                    ENDADD is 0x00 to 0x17, corresponding
                                                                                    to MEMRES0 to MEMRES23. */
#define ADC12_CTL2_ENDADD_ADDR_00                ((uint32_t)0x00000000U)         /* !< MEMCTL0 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_01                ((uint32_t)0x01000000U)         /* !< MEMCTL1 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_02                ((uint32_t)0x02000000U)         /* !< MEMCTL2 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_03                ((uint32_t)0x03000000U)         /* !< MEMCTL3 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_04                ((uint32_t)0x04000000U)         /* !< MEMCTL4 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_05                ((uint32_t)0x05000000U)         /* !< MEMCTL5 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_06                ((uint32_t)0x06000000U)         /* !< MEMCTL6 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_07                ((uint32_t)0x07000000U)         /* !< MEMCTL7 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_08                ((uint32_t)0x08000000U)         /* !< MEMCTL8 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_09                ((uint32_t)0x09000000U)         /* !< MEMCTL9 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_10                ((uint32_t)0x0A000000U)         /* !< MEMCTL10 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_11                ((uint32_t)0x0B000000U)         /* !< MEMCTL11 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_12                ((uint32_t)0x0C000000U)         /* !< MEMCTL12 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_13                ((uint32_t)0x0D000000U)         /* !< MEMCTL13 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_14                ((uint32_t)0x0E000000U)         /* !< MEMCTL14 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_15                ((uint32_t)0x0F000000U)         /* !< MEMCTL15 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_16                ((uint32_t)0x10000000U)         /* !< MEMCTL16 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_17                ((uint32_t)0x11000000U)         /* !< MEMCTL17 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_18                ((uint32_t)0x12000000U)         /* !< MEMCTL18 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_19                ((uint32_t)0x13000000U)         /* !< MEMCTL19 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_20                ((uint32_t)0x14000000U)         /* !< MEMCTL20 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_21                ((uint32_t)0x15000000U)         /* !< MEMCTL21 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_22                ((uint32_t)0x16000000U)         /* !< MEMCTL22 is selected as end address
                                                                                    of sequence. */
#define ADC12_CTL2_ENDADD_ADDR_23                ((uint32_t)0x17000000U)         /* !< MEMCTL23 is selected as end address
                                                                                    of sequence. */
/* ADC12_CTL2[DMAEN] Bits */
#define ADC12_CTL2_DMAEN_OFS                     (8)                             /* !< DMAEN Offset */
#define ADC12_CTL2_DMAEN_MASK                    ((uint32_t)0x00000100U)         /* !< Enable DMA trigger for data
                                                                                    transfer.  Note: DMAEN bit is cleared
                                                                                    by hardware based on DMA done signal
                                                                                    at the end of data transfer. Software
                                                                                    has to re-enable DMAEN bit for ADC to
                                                                                    generate DMA triggers. */
#define ADC12_CTL2_DMAEN_DISABLE                 ((uint32_t)0x00000000U)         /* !< DMA trigger not enabled */
#define ADC12_CTL2_DMAEN_ENABLE                  ((uint32_t)0x00000100U)         /* !< DMA trigger enabled */
/* ADC12_CTL2[SAMPCNT] Bits */
#define ADC12_CTL2_SAMPCNT_OFS                   (11)                            /* !< SAMPCNT Offset */
#define ADC12_CTL2_SAMPCNT_MASK                  ((uint32_t)0x0000F800U)         /* !< Number of ADC converted samples to
                                                                                    be transferred on a DMA trigger */
#define ADC12_CTL2_SAMPCNT_MIN                   ((uint32_t)0x00000000U)         /* !< Minimum value */
#define ADC12_CTL2_SAMPCNT_MAX                   ((uint32_t)0x0000C000U)         /* !< Maximum value */
/* ADC12_CTL2[FIFOEN] Bits */
#define ADC12_CTL2_FIFOEN_OFS                    (10)                            /* !< FIFOEN Offset */
#define ADC12_CTL2_FIFOEN_MASK                   ((uint32_t)0x00000400U)         /* !< Enable FIFO based operation */
#define ADC12_CTL2_FIFOEN_DISABLE                ((uint32_t)0x00000000U)         /* !< Disable */
#define ADC12_CTL2_FIFOEN_ENABLE                 ((uint32_t)0x00000400U)         /* !< Enable */
/* ADC12_CTL2[RSTSAMPCAPEN] Bits */
#define ADC12_CTL2_RSTSAMPCAPEN_OFS              (4)                             /* !< RSTSAMPCAPEN Offset */
#define ADC12_CTL2_RSTSAMPCAPEN_MASK             ((uint32_t)0x00000010U)         /* !< 0: Sample and hold capacitor is not
                                                                                    explicitly discharged at the end of
                                                                                    conversion. 1: Sample and hold
                                                                                    capacitor is discharged at the end of
                                                                                    conversion. This incurs one
                                                                                    additional conversion clock cycle. */
#define ADC12_CTL2_RSTSAMPCAPEN_DISABLE          ((uint32_t)0x00000000U)         /* !< Disable sample capacitor discharge
                                                                                    feature. */
#define ADC12_CTL2_RSTSAMPCAPEN_ENABLE           ((uint32_t)0x00000010U)         /* !< Enable sample capacitor discharge
                                                                                    feature. */

/* ADC12_CLKFREQ Bits */
/* ADC12_CLKFREQ[FRANGE] Bits */
#define ADC12_CLKFREQ_FRANGE_OFS                 (0)                             /* !< FRANGE Offset */
#define ADC12_CLKFREQ_FRANGE_MASK                ((uint32_t)0x00000007U)         /* !< Frequency Range. */
#define ADC12_CLKFREQ_FRANGE_RANGE1TO4           ((uint32_t)0x00000000U)         /* !< 1 to 4 MHz */
#define ADC12_CLKFREQ_FRANGE_RANGE4TO8           ((uint32_t)0x00000001U)         /* !< >4 to 8 MHz */
#define ADC12_CLKFREQ_FRANGE_RANGE8TO16          ((uint32_t)0x00000002U)         /* !< >8 to 16 MHz */
#define ADC12_CLKFREQ_FRANGE_RANGE16TO20         ((uint32_t)0x00000003U)         /* !< >16 to 20 MHz */
#define ADC12_CLKFREQ_FRANGE_RANGE20TO24         ((uint32_t)0x00000004U)         /* !< >20 to 24 MHz */
#define ADC12_CLKFREQ_FRANGE_RANGE24TO32         ((uint32_t)0x00000005U)         /* !< >24 to 32 MHz */
#define ADC12_CLKFREQ_FRANGE_RANGE32TO40         ((uint32_t)0x00000006U)         /* !< >32 to 40 MHz */
#define ADC12_CLKFREQ_FRANGE_RANGE40TO48         ((uint32_t)0x00000007U)         /* !< >40 to 48 MHz */

/* ADC12_SCOMP0 Bits */
/* ADC12_SCOMP0[VAL] Bits */
#define ADC12_SCOMP0_VAL_OFS                     (0)                             /* !< VAL Offset */
#define ADC12_SCOMP0_VAL_MASK                    ((uint32_t)0x000003FFU)         /* !< Specifies the number of sample
                                                                                    clocks. When VAL = 0 or 1, number of
                                                                                    sample clocks = Sample clock divide
                                                                                    value. When VAL > 1, number of sample
                                                                                    clocks = VAL x Sample clock divide
                                                                                    value. Note: Sample clock divide
                                                                                    value is not the value written to
                                                                                    SCLKDIV but the actual divide value
                                                                                    (SCLKDIV = 2 implies divide value is
                                                                                    4). Example: VAL = 4, SCLKDIV = 3
                                                                                    implies 32 sample clock cycles. */

/* ADC12_SCOMP1 Bits */
/* ADC12_SCOMP1[VAL] Bits */
#define ADC12_SCOMP1_VAL_OFS                     (0)                             /* !< VAL Offset */
#define ADC12_SCOMP1_VAL_MASK                    ((uint32_t)0x000003FFU)         /* !< Specifies the number of sample
                                                                                    clocks. When VAL = 0 or 1, number of
                                                                                    sample clocks = Sample clock divide
                                                                                    value. When VAL > 1, number of sample
                                                                                    clocks = VAL x Sample clock divide
                                                                                    value. Note: Sample clock divide
                                                                                    value is not the value written to
                                                                                    SCLKDIV but the actual divide value
                                                                                    (SCLKDIV = 2 implies divide value is
                                                                                    4). Example: VAL = 4, SCLKDIV = 3
                                                                                    implies 32 sample clock cycles. */

/* ADC12_WCLOW Bits */
/* ADC12_WCLOW[DATA] Bits */
#define ADC12_WCLOW_DATA_OFS                     (0)                             /* !< DATA Offset */
#define ADC12_WCLOW_DATA_MASK                    ((uint32_t)0x0000FFFFU)         /* !< If DF = 0, unsigned binary format
                                                                                    has to be used.  The value based on
                                                                                    the resolution has to be right
                                                                                    aligned with the MSB on the left. For
                                                                                    10-bits and 8-bits resolution, unused
                                                                                    bits have to be 0s.  If DF = 1,
                                                                                    2s-complement format has to be used.
                                                                                    The value based on the resolution has
                                                                                    to be left aligned with the LSB on
                                                                                    the right.  For 10-bits and 8-bits
                                                                                    resolution, unused bits have to be
                                                                                    0s. */

/* ADC12_WCHIGH Bits */
/* ADC12_WCHIGH[DATA] Bits */
#define ADC12_WCHIGH_DATA_OFS                    (0)                             /* !< DATA Offset */
#define ADC12_WCHIGH_DATA_MASK                   ((uint32_t)0x0000FFFFU)         /* !< If DF = 0, unsigned binary format
                                                                                    has to be used. The threshold value
                                                                                    has to be right aligned, with the MSB
                                                                                    on the left. For 10-bits and 8-bits
                                                                                    resolution, unused bit have to be 0s.
                                                                                    If DF = 1, 2s-complement format has
                                                                                    to be used. The value based on the
                                                                                    resolution has to be left aligned
                                                                                    with the LSB on the right.  For
                                                                                    10-bits and 8-bits resolution, unused
                                                                                    bit have to be 0s. */

/* ADC12_ULLMEM_FIFODATA Bits */
/* ADC12_ULLMEM_FIFODATA[DATA] Bits */
#define ADC12_ULLMEM_FIFODATA_DATA_OFS           (0)                             /* !< DATA Offset */
#define ADC12_ULLMEM_FIFODATA_DATA_MASK          ((uint32_t)0xFFFFFFFFU)         /* !< Read from this data field returns
                                                                                    the ADC sample from FIFO. */

/* ADC12_MEMCTL Bits */
/* ADC12_MEMCTL[CHANSEL] Bits */
#define ADC12_MEMCTL_CHANSEL_OFS                 (0)                             /* !< CHANSEL Offset */
#define ADC12_MEMCTL_CHANSEL_MASK                ((uint32_t)0x0000001FU)         /* !< Input channel select. */
#define ADC12_MEMCTL_CHANSEL_CHAN_0              ((uint32_t)0x00000000U)         /* !< Selects channel 0 */
#define ADC12_MEMCTL_CHANSEL_CHAN_1              ((uint32_t)0x00000001U)         /* !< Selects channel 1 */
#define ADC12_MEMCTL_CHANSEL_CHAN_2              ((uint32_t)0x00000002U)         /* !< Selects channel 2 */
#define ADC12_MEMCTL_CHANSEL_CHAN_3              ((uint32_t)0x00000003U)         /* !< Selects channel 3 */
#define ADC12_MEMCTL_CHANSEL_CHAN_4              ((uint32_t)0x00000004U)         /* !< Selects channel 4 */
#define ADC12_MEMCTL_CHANSEL_CHAN_5              ((uint32_t)0x00000005U)         /* !< Selects channel 5 */
#define ADC12_MEMCTL_CHANSEL_CHAN_6              ((uint32_t)0x00000006U)         /* !< Selects channel 6 */
#define ADC12_MEMCTL_CHANSEL_CHAN_7              ((uint32_t)0x00000007U)         /* !< Selects channel 7 */
#define ADC12_MEMCTL_CHANSEL_CHAN_8              ((uint32_t)0x00000008U)         /* !< Selects channel 8 */
#define ADC12_MEMCTL_CHANSEL_CHAN_9              ((uint32_t)0x00000009U)         /* !< Selects channel 9 */
#define ADC12_MEMCTL_CHANSEL_CHAN_10             ((uint32_t)0x0000000AU)         /* !< Selects channel 10 */
#define ADC12_MEMCTL_CHANSEL_CHAN_11             ((uint32_t)0x0000000BU)         /* !< Selects channel 11 */
#define ADC12_MEMCTL_CHANSEL_CHAN_12             ((uint32_t)0x0000000CU)         /* !< Selects channel 12 */
#define ADC12_MEMCTL_CHANSEL_CHAN_13             ((uint32_t)0x0000000DU)         /* !< Selects channel 13 */
#define ADC12_MEMCTL_CHANSEL_CHAN_14             ((uint32_t)0x0000000EU)         /* !< Selects channel 14 */
#define ADC12_MEMCTL_CHANSEL_CHAN_15             ((uint32_t)0x0000000FU)         /* !< Selects channel 15 */
#define ADC12_MEMCTL_CHANSEL_CHAN_16             ((uint32_t)0x00000010U)         /* !< Selects channel 16 */
#define ADC12_MEMCTL_CHANSEL_CHAN_17             ((uint32_t)0x00000011U)         /* !< Selects channel 17 */
#define ADC12_MEMCTL_CHANSEL_CHAN_18             ((uint32_t)0x00000012U)         /* !< Selects channel 18 */
#define ADC12_MEMCTL_CHANSEL_CHAN_19             ((uint32_t)0x00000013U)         /* !< Selects channel 19 */
#define ADC12_MEMCTL_CHANSEL_CHAN_20             ((uint32_t)0x00000014U)         /* !< Selects channel 20 */
#define ADC12_MEMCTL_CHANSEL_CHAN_21             ((uint32_t)0x00000015U)         /* !< Selects channel 21 */
#define ADC12_MEMCTL_CHANSEL_CHAN_22             ((uint32_t)0x00000016U)         /* !< Selects channel 22 */
#define ADC12_MEMCTL_CHANSEL_CHAN_23             ((uint32_t)0x00000017U)         /* !< Selects channel 23 */
#define ADC12_MEMCTL_CHANSEL_CHAN_24             ((uint32_t)0x00000018U)         /* !< Selects channel 24 */
#define ADC12_MEMCTL_CHANSEL_CHAN_25             ((uint32_t)0x00000019U)         /* !< Selects channel 25 */
#define ADC12_MEMCTL_CHANSEL_CHAN_26             ((uint32_t)0x0000001AU)         /* !< Selects channel 26 */
#define ADC12_MEMCTL_CHANSEL_CHAN_27             ((uint32_t)0x0000001BU)         /* !< Selects channel 27 */
#define ADC12_MEMCTL_CHANSEL_CHAN_28             ((uint32_t)0x0000001CU)         /* !< Selects channel 28 */
#define ADC12_MEMCTL_CHANSEL_CHAN_29             ((uint32_t)0x0000001DU)         /* !< Selects channel 29 */
#define ADC12_MEMCTL_CHANSEL_CHAN_30             ((uint32_t)0x0000001EU)         /* !< Selects channel 30 */
#define ADC12_MEMCTL_CHANSEL_CHAN_31             ((uint32_t)0x0000001FU)         /* !< Selects channel 31 */
/* ADC12_MEMCTL[TRIG] Bits */
#define ADC12_MEMCTL_TRIG_OFS                    (24)                            /* !< TRIG Offset */
#define ADC12_MEMCTL_TRIG_MASK                   ((uint32_t)0x01000000U)         /* !< Trigger policy. Indicates if a
                                                                                    trigger will be needed to step to the
                                                                                    next MEMCTL in the sequence or to
                                                                                    perform next conversion in the case
                                                                                    of repeat single channel conversions. */
#define ADC12_MEMCTL_TRIG_AUTO_NEXT              ((uint32_t)0x00000000U)         /* !< Next conversion is automatic */
#define ADC12_MEMCTL_TRIG_TRIGGER_NEXT           ((uint32_t)0x01000000U)         /* !< Next conversion requires a trigger */
/* ADC12_MEMCTL[VRSEL] Bits */
#define ADC12_MEMCTL_VRSEL_OFS                   (8)                             /* !< VRSEL Offset */
#define ADC12_MEMCTL_VRSEL_MASK                  ((uint32_t)0x00000700U)         /* !< Voltage reference selection. VEREFM
                                                                                    must be connected to on-board ground
                                                                                    when external reference option is
                                                                                    selected. Note: Writing value 0x3
                                                                                    defaults to INTREF. */
#define ADC12_MEMCTL_VRSEL_VDDA_VSSA             ((uint32_t)0x00000000U)         /* !< VDDA reference */
#define ADC12_MEMCTL_VRSEL_EXTREF_VREFM          ((uint32_t)0x00000100U)         /* !< External reference from pin */
#define ADC12_MEMCTL_VRSEL_INTREF_VSSA           ((uint32_t)0x00000200U)         /* !< Internal reference */
#define ADC12_MEMCTL_VRSEL_VDDA_VREFM            ((uint32_t)0x00000300U)         /* !< VDDA and VREFM connected to VREF+
                                                                                    and VREF- of ADC */
#define ADC12_MEMCTL_VRSEL_INTREF_VREFM          ((uint32_t)0x00000400U)         /* !< INTREF and VREFM connected to VREF+
                                                                                    and VREF- of ADC */
/* ADC12_MEMCTL[WINCOMP] Bits */
#define ADC12_MEMCTL_WINCOMP_OFS                 (28)                            /* !< WINCOMP Offset */
#define ADC12_MEMCTL_WINCOMP_MASK                ((uint32_t)0x10000000U)         /* !< Enable window comparator. */
#define ADC12_MEMCTL_WINCOMP_DISABLE             ((uint32_t)0x00000000U)         /* !< Disable */
#define ADC12_MEMCTL_WINCOMP_ENABLE              ((uint32_t)0x10000000U)         /* !< Enable */
/* ADC12_MEMCTL[BCSEN] Bits */
#define ADC12_MEMCTL_BCSEN_OFS                   (20)                            /* !< BCSEN Offset */
#define ADC12_MEMCTL_BCSEN_MASK                  ((uint32_t)0x00100000U)         /* !< Enable burn out current source. */
#define ADC12_MEMCTL_BCSEN_DISABLE               ((uint32_t)0x00000000U)         /* !< Disable */
#define ADC12_MEMCTL_BCSEN_ENABLE                ((uint32_t)0x00100000U)         /* !< Enable */
/* ADC12_MEMCTL[AVGEN] Bits */
#define ADC12_MEMCTL_AVGEN_OFS                   (16)                            /* !< AVGEN Offset */
#define ADC12_MEMCTL_AVGEN_MASK                  ((uint32_t)0x00010000U)         /* !< Enable hardware averaging. */
#define ADC12_MEMCTL_AVGEN_DISABLE               ((uint32_t)0x00000000U)         /* !< Averaging disabled. */
#define ADC12_MEMCTL_AVGEN_ENABLE                ((uint32_t)0x00010000U)         /* !< Averaging enabled. */
/* ADC12_MEMCTL[STIME] Bits */
#define ADC12_MEMCTL_STIME_OFS                   (12)                            /* !< STIME Offset */
#define ADC12_MEMCTL_STIME_MASK                  ((uint32_t)0x00001000U)         /* !< Selects the source of sample timer
                                                                                    period between SCOMP0 and SCOMP1. */
#define ADC12_MEMCTL_STIME_SEL_SCOMP0            ((uint32_t)0x00000000U)         /* !< Select SCOMP0 */
#define ADC12_MEMCTL_STIME_SEL_SCOMP1            ((uint32_t)0x00001000U)         /* !< Select SCOMP1 */

/* ADC12_ULLMEM_MEMRES Bits */
/* ADC12_ULLMEM_MEMRES[DATA] Bits */
#define ADC12_ULLMEM_MEMRES_DATA_OFS             (0)                             /* !< DATA Offset */
#define ADC12_ULLMEM_MEMRES_DATA_MASK            ((uint32_t)0x0000FFFFU)         /* !< MEMRES result register. If DF = 0,
                                                                                    unsigned binary: The conversion
                                                                                    results are right aligned. In 10 and
                                                                                    8 bit modes, the unused MSB bits are
                                                                                    forced to 0.  If DF = 1,
                                                                                    2s-complement format: The conversion
                                                                                    results are left aligned. In 10 and 8
                                                                                    bit modes, the unused LSB bits are
                                                                                    forced to 0. The data is stored in
                                                                                    the right-justified format and is
                                                                                    converted to the left-justified
                                                                                    2s-complement format during read
                                                                                    back. */

/* ADC12_STATUS Bits */
/* ADC12_STATUS[BUSY] Bits */
#define ADC12_STATUS_BUSY_OFS                    (0)                             /* !< BUSY Offset */
#define ADC12_STATUS_BUSY_MASK                   ((uint32_t)0x00000001U)         /* !< Busy. This bit indicates that an
                                                                                    active ADC sample or conversion
                                                                                    operation is in progress. */
#define ADC12_STATUS_BUSY_IDLE                   ((uint32_t)0x00000000U)         /* !< No ADC sampling or conversion in
                                                                                    progress. */
#define ADC12_STATUS_BUSY_ACTIVE                 ((uint32_t)0x00000001U)         /* !< ADC sampling or conversion is in
                                                                                    progress. */
/* ADC12_STATUS[REFBUFRDY] Bits */
#define ADC12_STATUS_REFBUFRDY_OFS               (1)                             /* !< REFBUFRDY Offset */
#define ADC12_STATUS_REFBUFRDY_MASK              ((uint32_t)0x00000002U)         /* !< Indicates reference buffer is
                                                                                    powered up and ready. */
#define ADC12_STATUS_REFBUFRDY_NOTREADY          ((uint32_t)0x00000000U)         /* !< Not ready */
#define ADC12_STATUS_REFBUFRDY_READY             ((uint32_t)0x00000002U)         /* !< Ready */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_adc12__include */

