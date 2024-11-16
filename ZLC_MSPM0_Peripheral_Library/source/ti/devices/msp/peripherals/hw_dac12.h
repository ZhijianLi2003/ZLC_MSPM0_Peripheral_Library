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

#ifndef ti_devices_msp_peripherals_hw_dac12__include
#define ti_devices_msp_peripherals_hw_dac12__include

/* Filename: hw_dac12.h */
/* Revised: 2023-05-23 20:53:14 */
/* Revision: ca7bbc3215c1e62bd43f32ecfdd7c7ce7f9b65b3 */

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
* DAC12 Registers
******************************************************************************/
#define DAC12_GEN_EVENT_OFS                      ((uint32_t)0x00001050U)
#define DAC12_CPU_INT_OFS                        ((uint32_t)0x00001020U)
#define DAC12_GPRCM_OFS                          ((uint32_t)0x00000800U)


/** @addtogroup DAC12_GEN_EVENT
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
} DAC12_GEN_EVENT_Regs;

/*@}*/ /* end of group DAC12_GEN_EVENT */

/** @addtogroup DAC12_CPU_INT
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
} DAC12_CPU_INT_Regs;

/*@}*/ /* end of group DAC12_CPU_INT */

/** @addtogroup DAC12_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} DAC12_GPRCM_Regs;

/*@}*/ /* end of group DAC12_GPRCM */

/** @addtogroup DAC12
  @{
*/

typedef struct {
       uint32_t RESERVED0[256];
  __IO uint32_t FSUB_0;                            /* !< (@ 0x00000400) Subscriber Port 0 */
       uint32_t RESERVED1[16];
  __IO uint32_t FPUB_1;                            /* !< (@ 0x00000444) Publisher port 1 */
       uint32_t RESERVED2[238];
  DAC12_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED3[514];
  DAC12_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED4;
  DAC12_GEN_EVENT_Regs  GEN_EVENT;                         /* !< (@ 0x00001050) */
       uint32_t RESERVED5[25];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED6[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
  __IO uint32_t CTL0;                              /* !< (@ 0x00001100) Control 0 */
       uint32_t RESERVED7[3];
  __IO uint32_t CTL1;                              /* !< (@ 0x00001110) Control 1 */
       uint32_t RESERVED8[3];
  __IO uint32_t CTL2;                              /* !< (@ 0x00001120) Control 2 */
       uint32_t RESERVED9[3];
  __IO uint32_t CTL3;                              /* !< (@ 0x00001130) Control 3 */
       uint32_t RESERVED10[3];
  __IO uint32_t CALCTL;                            /* !< (@ 0x00001140) Calibration control */
       uint32_t RESERVED11[7];
  __I  uint32_t CALDATA;                           /* !< (@ 0x00001160) Calibration data */
       uint32_t RESERVED12[39];
  __IO uint32_t DATA0;                             /* !< (@ 0x00001200) Data 0 */
} DAC12_Regs;

/*@}*/ /* end of group DAC12 */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* DAC12 Register Control Bits
******************************************************************************/

/* DAC12_GEN_EVENT_IIDX Bits */
/* DAC12_GEN_EVENT_IIDX[STAT] Bits */
#define DAC12_GEN_EVENT_IIDX_STAT_OFS            (0)                             /* !< STAT Offset */
#define DAC12_GEN_EVENT_IIDX_STAT_MASK           ((uint32_t)0x0000000FU)         /* !< Interrupt index status */
#define DAC12_GEN_EVENT_IIDX_STAT_NO_INTR        ((uint32_t)0x00000000U)         /* !< No pending interrupt */
#define DAC12_GEN_EVENT_IIDX_STAT_MODRDYIFG      ((uint32_t)0x00000002U)         /* !< Module ready interrupt */
#define DAC12_GEN_EVENT_IIDX_STAT_FIFOFULLIFG    ((uint32_t)0x00000009U)         /* !< FIFO full interrupt */
#define DAC12_GEN_EVENT_IIDX_STAT_FIFO1B4IFG     ((uint32_t)0x0000000AU)         /* !< FIFO one fourth empty interrupt */
#define DAC12_GEN_EVENT_IIDX_STAT_FIFO1B2IFG     ((uint32_t)0x0000000BU)         /* !< FIFO half empty interrupt */
#define DAC12_GEN_EVENT_IIDX_STAT_FIFO3B4IFG     ((uint32_t)0x0000000CU)         /* !< FIFO three fourth empty interrupt */
#define DAC12_GEN_EVENT_IIDX_STAT_FIFOEMPTYIFG   ((uint32_t)0x0000000DU)         /* !< FIFO empty interrupt */
#define DAC12_GEN_EVENT_IIDX_STAT_FIFOURUNIFG    ((uint32_t)0x0000000EU)         /* !< FIFO underrun interrupt */
#define DAC12_GEN_EVENT_IIDX_STAT_DMADONEIFG     ((uint32_t)0x0000000FU)         /* !< DMA done interrupt */

/* DAC12_GEN_EVENT_IMASK Bits */
/* DAC12_GEN_EVENT_IMASK[MODRDYIFG] Bits */
#define DAC12_GEN_EVENT_IMASK_MODRDYIFG_OFS      (1)                             /* !< MODRDYIFG Offset */
#define DAC12_GEN_EVENT_IMASK_MODRDYIFG_MASK     ((uint32_t)0x00000002U)         /* !< Masks MODRDYIFG */
#define DAC12_GEN_EVENT_IMASK_MODRDYIFG_CLR      ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_GEN_EVENT_IMASK_MODRDYIFG_SET      ((uint32_t)0x00000002U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_GEN_EVENT_IMASK[FIFO1B2IFG] Bits */
#define DAC12_GEN_EVENT_IMASK_FIFO1B2IFG_OFS     (10)                            /* !< FIFO1B2IFG Offset */
#define DAC12_GEN_EVENT_IMASK_FIFO1B2IFG_MASK    ((uint32_t)0x00000400U)         /* !< Masks FIFO1B2IFG */
#define DAC12_GEN_EVENT_IMASK_FIFO1B2IFG_CLR     ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_GEN_EVENT_IMASK_FIFO1B2IFG_SET     ((uint32_t)0x00000400U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_GEN_EVENT_IMASK[FIFOEMPTYIFG] Bits */
#define DAC12_GEN_EVENT_IMASK_FIFOEMPTYIFG_OFS   (12)                            /* !< FIFOEMPTYIFG Offset */
#define DAC12_GEN_EVENT_IMASK_FIFOEMPTYIFG_MASK  ((uint32_t)0x00001000U)         /* !< Masks FIFOEMPTYIFG */
#define DAC12_GEN_EVENT_IMASK_FIFOEMPTYIFG_CLR   ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_GEN_EVENT_IMASK_FIFOEMPTYIFG_SET   ((uint32_t)0x00001000U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_GEN_EVENT_IMASK[FIFO1B4IFG] Bits */
#define DAC12_GEN_EVENT_IMASK_FIFO1B4IFG_OFS     (9)                             /* !< FIFO1B4IFG Offset */
#define DAC12_GEN_EVENT_IMASK_FIFO1B4IFG_MASK    ((uint32_t)0x00000200U)         /* !< Masks FIFO1B4IFG */
#define DAC12_GEN_EVENT_IMASK_FIFO1B4IFG_CLR     ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_GEN_EVENT_IMASK_FIFO1B4IFG_SET     ((uint32_t)0x00000200U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_GEN_EVENT_IMASK[FIFO3B4IFG] Bits */
#define DAC12_GEN_EVENT_IMASK_FIFO3B4IFG_OFS     (11)                            /* !< FIFO3B4IFG Offset */
#define DAC12_GEN_EVENT_IMASK_FIFO3B4IFG_MASK    ((uint32_t)0x00000800U)         /* !< Masks FIFO3B4IFG */
#define DAC12_GEN_EVENT_IMASK_FIFO3B4IFG_CLR     ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_GEN_EVENT_IMASK_FIFO3B4IFG_SET     ((uint32_t)0x00000800U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_GEN_EVENT_IMASK[FIFOFULLIFG] Bits */
#define DAC12_GEN_EVENT_IMASK_FIFOFULLIFG_OFS    (8)                             /* !< FIFOFULLIFG Offset */
#define DAC12_GEN_EVENT_IMASK_FIFOFULLIFG_MASK   ((uint32_t)0x00000100U)         /* !< Masks FIFOFULLIFG */
#define DAC12_GEN_EVENT_IMASK_FIFOFULLIFG_CLR    ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_GEN_EVENT_IMASK_FIFOFULLIFG_SET    ((uint32_t)0x00000100U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_GEN_EVENT_IMASK[FIFOURUNIFG] Bits */
#define DAC12_GEN_EVENT_IMASK_FIFOURUNIFG_OFS    (13)                            /* !< FIFOURUNIFG Offset */
#define DAC12_GEN_EVENT_IMASK_FIFOURUNIFG_MASK   ((uint32_t)0x00002000U)         /* !< Masks FIFOURUNIFG */
#define DAC12_GEN_EVENT_IMASK_FIFOURUNIFG_CLR    ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_GEN_EVENT_IMASK_FIFOURUNIFG_SET    ((uint32_t)0x00002000U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_GEN_EVENT_IMASK[DMADONEIFG] Bits */
#define DAC12_GEN_EVENT_IMASK_DMADONEIFG_OFS     (14)                            /* !< DMADONEIFG Offset */
#define DAC12_GEN_EVENT_IMASK_DMADONEIFG_MASK    ((uint32_t)0x00004000U)         /* !< Masks DMADONEIFG */
#define DAC12_GEN_EVENT_IMASK_DMADONEIFG_CLR     ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_GEN_EVENT_IMASK_DMADONEIFG_SET     ((uint32_t)0x00004000U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */

/* DAC12_GEN_EVENT_RIS Bits */
/* DAC12_GEN_EVENT_RIS[MODRDYIFG] Bits */
#define DAC12_GEN_EVENT_RIS_MODRDYIFG_OFS        (1)                             /* !< MODRDYIFG Offset */
#define DAC12_GEN_EVENT_RIS_MODRDYIFG_MASK       ((uint32_t)0x00000002U)         /* !< Raw interrupt status for MODRDYIFG */
#define DAC12_GEN_EVENT_RIS_MODRDYIFG_CLR        ((uint32_t)0x00000000U)         /* !< DAC module ready event did not
                                                                                    occur */
#define DAC12_GEN_EVENT_RIS_MODRDYIFG_SET        ((uint32_t)0x00000002U)         /* !< DAC module ready event occurred */
/* DAC12_GEN_EVENT_RIS[FIFOEMPTYIFG] Bits */
#define DAC12_GEN_EVENT_RIS_FIFOEMPTYIFG_OFS     (12)                            /* !< FIFOEMPTYIFG Offset */
#define DAC12_GEN_EVENT_RIS_FIFOEMPTYIFG_MASK    ((uint32_t)0x00001000U)         /* !< Raw interrupt status for
                                                                                    FIFOEMPTYIFG */
#define DAC12_GEN_EVENT_RIS_FIFOEMPTYIFG_CLR     ((uint32_t)0x00000000U)         /* !< FIFO empty condition did not occur */
#define DAC12_GEN_EVENT_RIS_FIFOEMPTYIFG_SET     ((uint32_t)0x00001000U)         /* !< FIFO empty condition occurred */
/* DAC12_GEN_EVENT_RIS[FIFO1B4IFG] Bits */
#define DAC12_GEN_EVENT_RIS_FIFO1B4IFG_OFS       (9)                             /* !< FIFO1B4IFG Offset */
#define DAC12_GEN_EVENT_RIS_FIFO1B4IFG_MASK      ((uint32_t)0x00000200U)         /* !< Raw interrupt status for FIFO1B4IFG */
#define DAC12_GEN_EVENT_RIS_FIFO1B4IFG_CLR       ((uint32_t)0x00000000U)         /* !< FIFO one fourth empty condition did
                                                                                    not occur */
#define DAC12_GEN_EVENT_RIS_FIFO1B4IFG_SET       ((uint32_t)0x00000200U)         /* !< FIFO one fourth empty condition
                                                                                    occurred */
/* DAC12_GEN_EVENT_RIS[FIFO1B2IFG] Bits */
#define DAC12_GEN_EVENT_RIS_FIFO1B2IFG_OFS       (10)                            /* !< FIFO1B2IFG Offset */
#define DAC12_GEN_EVENT_RIS_FIFO1B2IFG_MASK      ((uint32_t)0x00000400U)         /* !< Raw interrupt status for FIFO1B2IFG */
#define DAC12_GEN_EVENT_RIS_FIFO1B2IFG_CLR       ((uint32_t)0x00000000U)         /* !< FIFO half empty condition did not
                                                                                    occur */
#define DAC12_GEN_EVENT_RIS_FIFO1B2IFG_SET       ((uint32_t)0x00000400U)         /* !< FIFO half empty condition occurred */
/* DAC12_GEN_EVENT_RIS[FIFO3B4IFG] Bits */
#define DAC12_GEN_EVENT_RIS_FIFO3B4IFG_OFS       (11)                            /* !< FIFO3B4IFG Offset */
#define DAC12_GEN_EVENT_RIS_FIFO3B4IFG_MASK      ((uint32_t)0x00000800U)         /* !< Raw interrupt status for FIFO3B4IFG */
#define DAC12_GEN_EVENT_RIS_FIFO3B4IFG_CLR       ((uint32_t)0x00000000U)         /* !< FIFO three fourth empty condition
                                                                                    did not occur */
#define DAC12_GEN_EVENT_RIS_FIFO3B4IFG_SET       ((uint32_t)0x00000800U)         /* !< FIFO three fourth empty condition
                                                                                    occurred */
/* DAC12_GEN_EVENT_RIS[FIFOFULLIFG] Bits */
#define DAC12_GEN_EVENT_RIS_FIFOFULLIFG_OFS      (8)                             /* !< FIFOFULLIFG Offset */
#define DAC12_GEN_EVENT_RIS_FIFOFULLIFG_MASK     ((uint32_t)0x00000100U)         /* !< Raw interrupt status for
                                                                                    FIFOFULLIFG */
#define DAC12_GEN_EVENT_RIS_FIFOFULLIFG_CLR      ((uint32_t)0x00000000U)         /* !< FIFO full condition did not occur */
#define DAC12_GEN_EVENT_RIS_FIFOFULLIFG_SET      ((uint32_t)0x00000100U)         /* !< FIFO full condition occurred */
/* DAC12_GEN_EVENT_RIS[FIFOURUNIFG] Bits */
#define DAC12_GEN_EVENT_RIS_FIFOURUNIFG_OFS      (13)                            /* !< FIFOURUNIFG Offset */
#define DAC12_GEN_EVENT_RIS_FIFOURUNIFG_MASK     ((uint32_t)0x00002000U)         /* !< Raw interrupt status for
                                                                                    FIFOURUNIFG */
#define DAC12_GEN_EVENT_RIS_FIFOURUNIFG_CLR      ((uint32_t)0x00000000U)         /* !< FIFO underrun condition did not
                                                                                    occur */
#define DAC12_GEN_EVENT_RIS_FIFOURUNIFG_SET      ((uint32_t)0x00002000U)         /* !< FIFO underrun condition occurred */
/* DAC12_GEN_EVENT_RIS[DMADONEIFG] Bits */
#define DAC12_GEN_EVENT_RIS_DMADONEIFG_OFS       (14)                            /* !< DMADONEIFG Offset */
#define DAC12_GEN_EVENT_RIS_DMADONEIFG_MASK      ((uint32_t)0x00004000U)         /* !< Raw interrupt status for DMADONEIFG */
#define DAC12_GEN_EVENT_RIS_DMADONEIFG_CLR       ((uint32_t)0x00000000U)         /* !< DMA done condition did not occur */
#define DAC12_GEN_EVENT_RIS_DMADONEIFG_SET       ((uint32_t)0x00004000U)         /* !< DMA done condition occurred */

/* DAC12_GEN_EVENT_MIS Bits */
/* DAC12_GEN_EVENT_MIS[MODRDYIFG] Bits */
#define DAC12_GEN_EVENT_MIS_MODRDYIFG_OFS        (1)                             /* !< MODRDYIFG Offset */
#define DAC12_GEN_EVENT_MIS_MODRDYIFG_MASK       ((uint32_t)0x00000002U)         /* !< Masked interrupt status for
                                                                                    MODRDYIFG */
#define DAC12_GEN_EVENT_MIS_MODRDYIFG_CLR        ((uint32_t)0x00000000U)         /* !< MODRDYIFG does not request an
                                                                                    interrupt service routine */
#define DAC12_GEN_EVENT_MIS_MODRDYIFG_SET        ((uint32_t)0x00000002U)         /* !< MODRDYIFG requests an interrupt
                                                                                    service routine */
/* DAC12_GEN_EVENT_MIS[FIFOEMPTYIFG] Bits */
#define DAC12_GEN_EVENT_MIS_FIFOEMPTYIFG_OFS     (12)                            /* !< FIFOEMPTYIFG Offset */
#define DAC12_GEN_EVENT_MIS_FIFOEMPTYIFG_MASK    ((uint32_t)0x00001000U)         /* !< Masked interrupt status for
                                                                                    FIFOEMPTYIFG */
#define DAC12_GEN_EVENT_MIS_FIFOEMPTYIFG_CLR     ((uint32_t)0x00000000U)         /* !< FIFOEMPTYIFG does not request an
                                                                                    interrupt service routine */
#define DAC12_GEN_EVENT_MIS_FIFOEMPTYIFG_SET     ((uint32_t)0x00001000U)         /* !< FIFOEMPTYIFG requests an interrupt
                                                                                    service routine */
/* DAC12_GEN_EVENT_MIS[FIFO1B4IFG] Bits */
#define DAC12_GEN_EVENT_MIS_FIFO1B4IFG_OFS       (9)                             /* !< FIFO1B4IFG Offset */
#define DAC12_GEN_EVENT_MIS_FIFO1B4IFG_MASK      ((uint32_t)0x00000200U)         /* !< Masked interrupt status for
                                                                                    FIFO1B4IFG */
#define DAC12_GEN_EVENT_MIS_FIFO1B4IFG_CLR       ((uint32_t)0x00000000U)         /* !< FIFO1B4IFG does not request an
                                                                                    interrupt service routine */
#define DAC12_GEN_EVENT_MIS_FIFO1B4IFG_SET       ((uint32_t)0x00000200U)         /* !< FIFO1B4IFG requests an interrupt
                                                                                    service routine */
/* DAC12_GEN_EVENT_MIS[FIFO1B2IFG] Bits */
#define DAC12_GEN_EVENT_MIS_FIFO1B2IFG_OFS       (10)                            /* !< FIFO1B2IFG Offset */
#define DAC12_GEN_EVENT_MIS_FIFO1B2IFG_MASK      ((uint32_t)0x00000400U)         /* !< Masked interrupt status for
                                                                                    FIFO1B2IFG */
#define DAC12_GEN_EVENT_MIS_FIFO1B2IFG_CLR       ((uint32_t)0x00000000U)         /* !< FIFO1B2IFG does not request an
                                                                                    interrupt service routine */
#define DAC12_GEN_EVENT_MIS_FIFO1B2IFG_SET       ((uint32_t)0x00000400U)         /* !< FIFO1B2IFG requests an interrupt
                                                                                    service routine */
/* DAC12_GEN_EVENT_MIS[FIFO3B4IFG] Bits */
#define DAC12_GEN_EVENT_MIS_FIFO3B4IFG_OFS       (11)                            /* !< FIFO3B4IFG Offset */
#define DAC12_GEN_EVENT_MIS_FIFO3B4IFG_MASK      ((uint32_t)0x00000800U)         /* !< Masked interrupt status for
                                                                                    FIFO3B4IFG */
#define DAC12_GEN_EVENT_MIS_FIFO3B4IFG_CLR       ((uint32_t)0x00000000U)         /* !< FIFO3B4IFG does not request an
                                                                                    interrupt service routine */
#define DAC12_GEN_EVENT_MIS_FIFO3B4IFG_SET       ((uint32_t)0x00000800U)         /* !< FIFO3B4IFG requests an interrupt
                                                                                    service routine */
/* DAC12_GEN_EVENT_MIS[FIFOFULLIFG] Bits */
#define DAC12_GEN_EVENT_MIS_FIFOFULLIFG_OFS      (8)                             /* !< FIFOFULLIFG Offset */
#define DAC12_GEN_EVENT_MIS_FIFOFULLIFG_MASK     ((uint32_t)0x00000100U)         /* !< Masked interrupt status for
                                                                                    FIFOFULLIFG */
#define DAC12_GEN_EVENT_MIS_FIFOFULLIFG_CLR      ((uint32_t)0x00000000U)         /* !< FIFOFULLIFG does not request an
                                                                                    interrupt service routine */
#define DAC12_GEN_EVENT_MIS_FIFOFULLIFG_SET      ((uint32_t)0x00000100U)         /* !< FIFOFULLIFG requests an interrupt
                                                                                    service routine */
/* DAC12_GEN_EVENT_MIS[FIFOURUNIFG] Bits */
#define DAC12_GEN_EVENT_MIS_FIFOURUNIFG_OFS      (13)                            /* !< FIFOURUNIFG Offset */
#define DAC12_GEN_EVENT_MIS_FIFOURUNIFG_MASK     ((uint32_t)0x00002000U)         /* !< Masked interrupt status for
                                                                                    FIFOURUNIFG */
#define DAC12_GEN_EVENT_MIS_FIFOURUNIFG_CLR      ((uint32_t)0x00000000U)         /* !< FIFOURUNIFG does not request an
                                                                                    interrupt service routine */
#define DAC12_GEN_EVENT_MIS_FIFOURUNIFG_SET      ((uint32_t)0x00002000U)         /* !< FIFOURUNIFG requests an interrupt
                                                                                    service routine */
/* DAC12_GEN_EVENT_MIS[DMADONEIFG] Bits */
#define DAC12_GEN_EVENT_MIS_DMADONEIFG_OFS       (14)                            /* !< DMADONEIFG Offset */
#define DAC12_GEN_EVENT_MIS_DMADONEIFG_MASK      ((uint32_t)0x00004000U)         /* !< Masked interrupt status for
                                                                                    DMADONEIFG */
#define DAC12_GEN_EVENT_MIS_DMADONEIFG_CLR       ((uint32_t)0x00000000U)         /* !< DMADONEIFG does not request an
                                                                                    interrupt service routine */
#define DAC12_GEN_EVENT_MIS_DMADONEIFG_SET       ((uint32_t)0x00004000U)         /* !< DMADONEIFG requests an interrupt
                                                                                    service routine */

/* DAC12_GEN_EVENT_ISET Bits */
/* DAC12_GEN_EVENT_ISET[MODRDYIFG] Bits */
#define DAC12_GEN_EVENT_ISET_MODRDYIFG_OFS       (1)                             /* !< MODRDYIFG Offset */
#define DAC12_GEN_EVENT_ISET_MODRDYIFG_MASK      ((uint32_t)0x00000002U)         /* !< Sets MODRDYIFG in RIS register */
#define DAC12_GEN_EVENT_ISET_MODRDYIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ISET_MODRDYIFG_SET       ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to MODRDYIFG
                                                                                    is set */
/* DAC12_GEN_EVENT_ISET[FIFOEMPTYIFG] Bits */
#define DAC12_GEN_EVENT_ISET_FIFOEMPTYIFG_OFS    (12)                            /* !< FIFOEMPTYIFG Offset */
#define DAC12_GEN_EVENT_ISET_FIFOEMPTYIFG_MASK   ((uint32_t)0x00001000U)         /* !< Sets FIFOEMPTYIFG in RIS register */
#define DAC12_GEN_EVENT_ISET_FIFOEMPTYIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ISET_FIFOEMPTYIFG_SET    ((uint32_t)0x00001000U)         /* !< RIS bit corresponding to
                                                                                    FIFOEMPTYIFG is set */
/* DAC12_GEN_EVENT_ISET[FIFO1B4IFG] Bits */
#define DAC12_GEN_EVENT_ISET_FIFO1B4IFG_OFS      (9)                             /* !< FIFO1B4IFG Offset */
#define DAC12_GEN_EVENT_ISET_FIFO1B4IFG_MASK     ((uint32_t)0x00000200U)         /* !< Sets FIFO1B4IFG in RIS register */
#define DAC12_GEN_EVENT_ISET_FIFO1B4IFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ISET_FIFO1B4IFG_SET      ((uint32_t)0x00000200U)         /* !< RIS bit corresponding to FIFO1B4IFG
                                                                                    is set */
/* DAC12_GEN_EVENT_ISET[FIFO1B2IFG] Bits */
#define DAC12_GEN_EVENT_ISET_FIFO1B2IFG_OFS      (10)                            /* !< FIFO1B2IFG Offset */
#define DAC12_GEN_EVENT_ISET_FIFO1B2IFG_MASK     ((uint32_t)0x00000400U)         /* !< Sets FIFO1B2IFG in RIS register */
#define DAC12_GEN_EVENT_ISET_FIFO1B2IFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ISET_FIFO1B2IFG_SET      ((uint32_t)0x00000400U)         /* !< RIS bit corresponding to FIFO1B2IFG
                                                                                    is set */
/* DAC12_GEN_EVENT_ISET[FIFO3B4IFG] Bits */
#define DAC12_GEN_EVENT_ISET_FIFO3B4IFG_OFS      (11)                            /* !< FIFO3B4IFG Offset */
#define DAC12_GEN_EVENT_ISET_FIFO3B4IFG_MASK     ((uint32_t)0x00000800U)         /* !< Sets FIFO3B4IFG in RIS register */
#define DAC12_GEN_EVENT_ISET_FIFO3B4IFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ISET_FIFO3B4IFG_SET      ((uint32_t)0x00000800U)         /* !< RIS bit corresponding to FIFO3B4IFG
                                                                                    is set */
/* DAC12_GEN_EVENT_ISET[FIFOFULLIFG] Bits */
#define DAC12_GEN_EVENT_ISET_FIFOFULLIFG_OFS     (8)                             /* !< FIFOFULLIFG Offset */
#define DAC12_GEN_EVENT_ISET_FIFOFULLIFG_MASK    ((uint32_t)0x00000100U)         /* !< Sets FIFOFULLIFG in RIS register */
#define DAC12_GEN_EVENT_ISET_FIFOFULLIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ISET_FIFOFULLIFG_SET     ((uint32_t)0x00000100U)         /* !< RIS bit corresponding to
                                                                                    FIFOFULLIFG is set */
/* DAC12_GEN_EVENT_ISET[FIFOURUNIFG] Bits */
#define DAC12_GEN_EVENT_ISET_FIFOURUNIFG_OFS     (13)                            /* !< FIFOURUNIFG Offset */
#define DAC12_GEN_EVENT_ISET_FIFOURUNIFG_MASK    ((uint32_t)0x00002000U)         /* !< Sets FIFOURUNIFG in RIS register */
#define DAC12_GEN_EVENT_ISET_FIFOURUNIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ISET_FIFOURUNIFG_SET     ((uint32_t)0x00002000U)         /* !< RIS bit corresponding to
                                                                                    FIFOURUNIFG is set */
/* DAC12_GEN_EVENT_ISET[DMADONEIFG] Bits */
#define DAC12_GEN_EVENT_ISET_DMADONEIFG_OFS      (14)                            /* !< DMADONEIFG Offset */
#define DAC12_GEN_EVENT_ISET_DMADONEIFG_MASK     ((uint32_t)0x00004000U)         /* !< Sets DMADONEIFG in RIS register */
#define DAC12_GEN_EVENT_ISET_DMADONEIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ISET_DMADONEIFG_SET      ((uint32_t)0x00004000U)         /* !< RIS bit corresponding to DMADONEIFG
                                                                                    is set */

/* DAC12_GEN_EVENT_ICLR Bits */
/* DAC12_GEN_EVENT_ICLR[MODRDYIFG] Bits */
#define DAC12_GEN_EVENT_ICLR_MODRDYIFG_OFS       (1)                             /* !< MODRDYIFG Offset */
#define DAC12_GEN_EVENT_ICLR_MODRDYIFG_MASK      ((uint32_t)0x00000002U)         /* !< Clears MODRDYIFG in RIS register */
#define DAC12_GEN_EVENT_ICLR_MODRDYIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ICLR_MODRDYIFG_CLR       ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to MODRDYIFG
                                                                                    is cleared */
/* DAC12_GEN_EVENT_ICLR[FIFOEMPTYIFG] Bits */
#define DAC12_GEN_EVENT_ICLR_FIFOEMPTYIFG_OFS    (12)                            /* !< FIFOEMPTYIFG Offset */
#define DAC12_GEN_EVENT_ICLR_FIFOEMPTYIFG_MASK   ((uint32_t)0x00001000U)         /* !< Clears FIFOEMPTYIFG in RIS register */
#define DAC12_GEN_EVENT_ICLR_FIFOEMPTYIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ICLR_FIFOEMPTYIFG_CLR    ((uint32_t)0x00001000U)         /* !< RIS bit corresponding to
                                                                                    FIFOEMPTYIFG is cleared */
/* DAC12_GEN_EVENT_ICLR[FIFO1B4IFG] Bits */
#define DAC12_GEN_EVENT_ICLR_FIFO1B4IFG_OFS      (9)                             /* !< FIFO1B4IFG Offset */
#define DAC12_GEN_EVENT_ICLR_FIFO1B4IFG_MASK     ((uint32_t)0x00000200U)         /* !< Clears FIFO1B4IFG in RIS register */
#define DAC12_GEN_EVENT_ICLR_FIFO1B4IFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ICLR_FIFO1B4IFG_CLR      ((uint32_t)0x00000200U)         /* !< RIS bit corresponding to FIFO1B4IFG
                                                                                    is cleared */
/* DAC12_GEN_EVENT_ICLR[FIFO1B2IFG] Bits */
#define DAC12_GEN_EVENT_ICLR_FIFO1B2IFG_OFS      (10)                            /* !< FIFO1B2IFG Offset */
#define DAC12_GEN_EVENT_ICLR_FIFO1B2IFG_MASK     ((uint32_t)0x00000400U)         /* !< Clears FIFO1B2IFG in RIS register */
#define DAC12_GEN_EVENT_ICLR_FIFO1B2IFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ICLR_FIFO1B2IFG_CLR      ((uint32_t)0x00000400U)         /* !< RIS bit corresponding to FIFO1B2IFG
                                                                                    is cleared */
/* DAC12_GEN_EVENT_ICLR[FIFO3B4IFG] Bits */
#define DAC12_GEN_EVENT_ICLR_FIFO3B4IFG_OFS      (11)                            /* !< FIFO3B4IFG Offset */
#define DAC12_GEN_EVENT_ICLR_FIFO3B4IFG_MASK     ((uint32_t)0x00000800U)         /* !< Clears FIFO3B4IFG in RIS register */
#define DAC12_GEN_EVENT_ICLR_FIFO3B4IFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ICLR_FIFO3B4IFG_CLR      ((uint32_t)0x00000800U)         /* !< RIS bit corresponding to FIFO3B4IFG
                                                                                    is cleared */
/* DAC12_GEN_EVENT_ICLR[FIFOFULLIFG] Bits */
#define DAC12_GEN_EVENT_ICLR_FIFOFULLIFG_OFS     (8)                             /* !< FIFOFULLIFG Offset */
#define DAC12_GEN_EVENT_ICLR_FIFOFULLIFG_MASK    ((uint32_t)0x00000100U)         /* !< Clears FIFOFULLIFG in RIS register */
#define DAC12_GEN_EVENT_ICLR_FIFOFULLIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ICLR_FIFOFULLIFG_CLR     ((uint32_t)0x00000100U)         /* !< RIS bit corresponding to
                                                                                    FIFOFULLIFG is cleared */
/* DAC12_GEN_EVENT_ICLR[FIFOURUNIFG] Bits */
#define DAC12_GEN_EVENT_ICLR_FIFOURUNIFG_OFS     (13)                            /* !< FIFOURUNIFG Offset */
#define DAC12_GEN_EVENT_ICLR_FIFOURUNIFG_MASK    ((uint32_t)0x00002000U)         /* !< Clears FIFOURUNIFG in RIS register */
#define DAC12_GEN_EVENT_ICLR_FIFOURUNIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ICLR_FIFOURUNIFG_CLR     ((uint32_t)0x00002000U)         /* !< RIS bit corresponding to
                                                                                    FIFOURUNIFG is cleared */
/* DAC12_GEN_EVENT_ICLR[DMADONEIFG] Bits */
#define DAC12_GEN_EVENT_ICLR_DMADONEIFG_OFS      (14)                            /* !< DMADONEIFG Offset */
#define DAC12_GEN_EVENT_ICLR_DMADONEIFG_MASK     ((uint32_t)0x00004000U)         /* !< Clears DMADONEIFG in RIS register */
#define DAC12_GEN_EVENT_ICLR_DMADONEIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_GEN_EVENT_ICLR_DMADONEIFG_CLR      ((uint32_t)0x00004000U)         /* !< RIS bit corresponding to DMADONEIFG
                                                                                    is cleared */

/* DAC12_CPU_INT_IIDX Bits */
/* DAC12_CPU_INT_IIDX[STAT] Bits */
#define DAC12_CPU_INT_IIDX_STAT_OFS              (0)                             /* !< STAT Offset */
#define DAC12_CPU_INT_IIDX_STAT_MASK             ((uint32_t)0x0000000FU)         /* !< Interrupt index status */
#define DAC12_CPU_INT_IIDX_STAT_NO_INTR          ((uint32_t)0x00000000U)         /* !< No pending interrupt */
#define DAC12_CPU_INT_IIDX_STAT_MODRDYIFG        ((uint32_t)0x00000002U)         /* !< Module ready interrupt */
#define DAC12_CPU_INT_IIDX_STAT_FIFOFULLIFG      ((uint32_t)0x00000009U)         /* !< FIFO full interrupt */
#define DAC12_CPU_INT_IIDX_STAT_FIFO1B4IFG       ((uint32_t)0x0000000AU)         /* !< FIFO one fourth empty interrupt */
#define DAC12_CPU_INT_IIDX_STAT_FIFO1B2IFG       ((uint32_t)0x0000000BU)         /* !< FIFO half empty interrupt */
#define DAC12_CPU_INT_IIDX_STAT_FIFO3B4IFG       ((uint32_t)0x0000000CU)         /* !< FIFO three fourth empty interrupt */
#define DAC12_CPU_INT_IIDX_STAT_FIFOEMPTYIFG     ((uint32_t)0x0000000DU)         /* !< FIFO empty interrupt */
#define DAC12_CPU_INT_IIDX_STAT_FIFOURUNIFG      ((uint32_t)0x0000000EU)         /* !< FIFO underrun interrupt */
#define DAC12_CPU_INT_IIDX_STAT_DMADONEIFG       ((uint32_t)0x0000000FU)         /* !< DMA done interrupt */

/* DAC12_CPU_INT_IMASK Bits */
/* DAC12_CPU_INT_IMASK[MODRDYIFG] Bits */
#define DAC12_CPU_INT_IMASK_MODRDYIFG_OFS        (1)                             /* !< MODRDYIFG Offset */
#define DAC12_CPU_INT_IMASK_MODRDYIFG_MASK       ((uint32_t)0x00000002U)         /* !< Masks MODRDYIFG */
#define DAC12_CPU_INT_IMASK_MODRDYIFG_CLR        ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_CPU_INT_IMASK_MODRDYIFG_SET        ((uint32_t)0x00000002U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_CPU_INT_IMASK[FIFO1B2IFG] Bits */
#define DAC12_CPU_INT_IMASK_FIFO1B2IFG_OFS       (10)                            /* !< FIFO1B2IFG Offset */
#define DAC12_CPU_INT_IMASK_FIFO1B2IFG_MASK      ((uint32_t)0x00000400U)         /* !< Masks FIFO1B2IFG */
#define DAC12_CPU_INT_IMASK_FIFO1B2IFG_CLR       ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_CPU_INT_IMASK_FIFO1B2IFG_SET       ((uint32_t)0x00000400U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_CPU_INT_IMASK[FIFOEMPTYIFG] Bits */
#define DAC12_CPU_INT_IMASK_FIFOEMPTYIFG_OFS     (12)                            /* !< FIFOEMPTYIFG Offset */
#define DAC12_CPU_INT_IMASK_FIFOEMPTYIFG_MASK    ((uint32_t)0x00001000U)         /* !< Masks FIFOEMPTYIFG */
#define DAC12_CPU_INT_IMASK_FIFOEMPTYIFG_CLR     ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_CPU_INT_IMASK_FIFOEMPTYIFG_SET     ((uint32_t)0x00001000U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_CPU_INT_IMASK[FIFO1B4IFG] Bits */
#define DAC12_CPU_INT_IMASK_FIFO1B4IFG_OFS       (9)                             /* !< FIFO1B4IFG Offset */
#define DAC12_CPU_INT_IMASK_FIFO1B4IFG_MASK      ((uint32_t)0x00000200U)         /* !< Masks FIFO1B4IFG */
#define DAC12_CPU_INT_IMASK_FIFO1B4IFG_CLR       ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_CPU_INT_IMASK_FIFO1B4IFG_SET       ((uint32_t)0x00000200U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_CPU_INT_IMASK[FIFO3B4IFG] Bits */
#define DAC12_CPU_INT_IMASK_FIFO3B4IFG_OFS       (11)                            /* !< FIFO3B4IFG Offset */
#define DAC12_CPU_INT_IMASK_FIFO3B4IFG_MASK      ((uint32_t)0x00000800U)         /* !< Masks FIFO3B4IFG */
#define DAC12_CPU_INT_IMASK_FIFO3B4IFG_CLR       ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_CPU_INT_IMASK_FIFO3B4IFG_SET       ((uint32_t)0x00000800U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_CPU_INT_IMASK[FIFOFULLIFG] Bits */
#define DAC12_CPU_INT_IMASK_FIFOFULLIFG_OFS      (8)                             /* !< FIFOFULLIFG Offset */
#define DAC12_CPU_INT_IMASK_FIFOFULLIFG_MASK     ((uint32_t)0x00000100U)         /* !< Masks FIFOFULLIFG */
#define DAC12_CPU_INT_IMASK_FIFOFULLIFG_CLR      ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_CPU_INT_IMASK_FIFOFULLIFG_SET      ((uint32_t)0x00000100U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_CPU_INT_IMASK[FIFOURUNIFG] Bits */
#define DAC12_CPU_INT_IMASK_FIFOURUNIFG_OFS      (13)                            /* !< FIFOURUNIFG Offset */
#define DAC12_CPU_INT_IMASK_FIFOURUNIFG_MASK     ((uint32_t)0x00002000U)         /* !< Masks FIFOURUNIFG */
#define DAC12_CPU_INT_IMASK_FIFOURUNIFG_CLR      ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_CPU_INT_IMASK_FIFOURUNIFG_SET      ((uint32_t)0x00002000U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DAC12_CPU_INT_IMASK[DMADONEIFG] Bits */
#define DAC12_CPU_INT_IMASK_DMADONEIFG_OFS       (14)                            /* !< DMADONEIFG Offset */
#define DAC12_CPU_INT_IMASK_DMADONEIFG_MASK      ((uint32_t)0x00004000U)         /* !< Masks DMADONEIFG */
#define DAC12_CPU_INT_IMASK_DMADONEIFG_CLR       ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DAC12_CPU_INT_IMASK_DMADONEIFG_SET       ((uint32_t)0x00004000U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */

/* DAC12_CPU_INT_RIS Bits */
/* DAC12_CPU_INT_RIS[MODRDYIFG] Bits */
#define DAC12_CPU_INT_RIS_MODRDYIFG_OFS          (1)                             /* !< MODRDYIFG Offset */
#define DAC12_CPU_INT_RIS_MODRDYIFG_MASK         ((uint32_t)0x00000002U)         /* !< Raw interrupt status for MODRDYIFG */
#define DAC12_CPU_INT_RIS_MODRDYIFG_CLR          ((uint32_t)0x00000000U)         /* !< DAC module ready event did not
                                                                                    occur */
#define DAC12_CPU_INT_RIS_MODRDYIFG_SET          ((uint32_t)0x00000002U)         /* !< DAC module ready event occurred */
/* DAC12_CPU_INT_RIS[FIFOEMPTYIFG] Bits */
#define DAC12_CPU_INT_RIS_FIFOEMPTYIFG_OFS       (12)                            /* !< FIFOEMPTYIFG Offset */
#define DAC12_CPU_INT_RIS_FIFOEMPTYIFG_MASK      ((uint32_t)0x00001000U)         /* !< Raw interrupt status for
                                                                                    FIFOEMPTYIFG */
#define DAC12_CPU_INT_RIS_FIFOEMPTYIFG_CLR       ((uint32_t)0x00000000U)         /* !< FIFO empty condition did not occur */
#define DAC12_CPU_INT_RIS_FIFOEMPTYIFG_SET       ((uint32_t)0x00001000U)         /* !< FIFO empty condition occurred */
/* DAC12_CPU_INT_RIS[FIFO1B4IFG] Bits */
#define DAC12_CPU_INT_RIS_FIFO1B4IFG_OFS         (9)                             /* !< FIFO1B4IFG Offset */
#define DAC12_CPU_INT_RIS_FIFO1B4IFG_MASK        ((uint32_t)0x00000200U)         /* !< Raw interrupt status for FIFO1B4IFG */
#define DAC12_CPU_INT_RIS_FIFO1B4IFG_CLR         ((uint32_t)0x00000000U)         /* !< FIFO one fourth empty condition did
                                                                                    not occur */
#define DAC12_CPU_INT_RIS_FIFO1B4IFG_SET         ((uint32_t)0x00000200U)         /* !< FIFO one fourth empty condition
                                                                                    occurred */
/* DAC12_CPU_INT_RIS[FIFO1B2IFG] Bits */
#define DAC12_CPU_INT_RIS_FIFO1B2IFG_OFS         (10)                            /* !< FIFO1B2IFG Offset */
#define DAC12_CPU_INT_RIS_FIFO1B2IFG_MASK        ((uint32_t)0x00000400U)         /* !< Raw interrupt status for FIFO1B2IFG */
#define DAC12_CPU_INT_RIS_FIFO1B2IFG_CLR         ((uint32_t)0x00000000U)         /* !< FIFO half empty condition did not
                                                                                    occur */
#define DAC12_CPU_INT_RIS_FIFO1B2IFG_SET         ((uint32_t)0x00000400U)         /* !< FIFO half empty condition occurred */
/* DAC12_CPU_INT_RIS[FIFO3B4IFG] Bits */
#define DAC12_CPU_INT_RIS_FIFO3B4IFG_OFS         (11)                            /* !< FIFO3B4IFG Offset */
#define DAC12_CPU_INT_RIS_FIFO3B4IFG_MASK        ((uint32_t)0x00000800U)         /* !< Raw interrupt status for FIFO3B4IFG */
#define DAC12_CPU_INT_RIS_FIFO3B4IFG_CLR         ((uint32_t)0x00000000U)         /* !< FIFO three fourth empty condition
                                                                                    did not occur */
#define DAC12_CPU_INT_RIS_FIFO3B4IFG_SET         ((uint32_t)0x00000800U)         /* !< FIFO three fourth empty condition
                                                                                    occurred */
/* DAC12_CPU_INT_RIS[FIFOFULLIFG] Bits */
#define DAC12_CPU_INT_RIS_FIFOFULLIFG_OFS        (8)                             /* !< FIFOFULLIFG Offset */
#define DAC12_CPU_INT_RIS_FIFOFULLIFG_MASK       ((uint32_t)0x00000100U)         /* !< Raw interrupt status for
                                                                                    FIFOFULLIFG */
#define DAC12_CPU_INT_RIS_FIFOFULLIFG_CLR        ((uint32_t)0x00000000U)         /* !< FIFO full condition did not occur */
#define DAC12_CPU_INT_RIS_FIFOFULLIFG_SET        ((uint32_t)0x00000100U)         /* !< FIFO full condition occurred */
/* DAC12_CPU_INT_RIS[FIFOURUNIFG] Bits */
#define DAC12_CPU_INT_RIS_FIFOURUNIFG_OFS        (13)                            /* !< FIFOURUNIFG Offset */
#define DAC12_CPU_INT_RIS_FIFOURUNIFG_MASK       ((uint32_t)0x00002000U)         /* !< Raw interrupt status for
                                                                                    FIFOURUNIFG */
#define DAC12_CPU_INT_RIS_FIFOURUNIFG_CLR        ((uint32_t)0x00000000U)         /* !< FIFO underrun condition did not
                                                                                    occur */
#define DAC12_CPU_INT_RIS_FIFOURUNIFG_SET        ((uint32_t)0x00002000U)         /* !< FIFO underrun condition occurred */
/* DAC12_CPU_INT_RIS[DMADONEIFG] Bits */
#define DAC12_CPU_INT_RIS_DMADONEIFG_OFS         (14)                            /* !< DMADONEIFG Offset */
#define DAC12_CPU_INT_RIS_DMADONEIFG_MASK        ((uint32_t)0x00004000U)         /* !< Raw interrupt status for DMADONEIFG */
#define DAC12_CPU_INT_RIS_DMADONEIFG_CLR         ((uint32_t)0x00000000U)         /* !< DMA done condition did not occur */
#define DAC12_CPU_INT_RIS_DMADONEIFG_SET         ((uint32_t)0x00004000U)         /* !< DMA done condition occurred */

/* DAC12_CPU_INT_MIS Bits */
/* DAC12_CPU_INT_MIS[MODRDYIFG] Bits */
#define DAC12_CPU_INT_MIS_MODRDYIFG_OFS          (1)                             /* !< MODRDYIFG Offset */
#define DAC12_CPU_INT_MIS_MODRDYIFG_MASK         ((uint32_t)0x00000002U)         /* !< Masked interrupt status for
                                                                                    MODRDYIFG */
#define DAC12_CPU_INT_MIS_MODRDYIFG_CLR          ((uint32_t)0x00000000U)         /* !< MODRDYIFG does not request an
                                                                                    interrupt service routine */
#define DAC12_CPU_INT_MIS_MODRDYIFG_SET          ((uint32_t)0x00000002U)         /* !< MODRDYIFG requests an interrupt
                                                                                    service routine */
/* DAC12_CPU_INT_MIS[FIFOEMPTYIFG] Bits */
#define DAC12_CPU_INT_MIS_FIFOEMPTYIFG_OFS       (12)                            /* !< FIFOEMPTYIFG Offset */
#define DAC12_CPU_INT_MIS_FIFOEMPTYIFG_MASK      ((uint32_t)0x00001000U)         /* !< Masked interrupt status for
                                                                                    FIFOEMPTYIFG */
#define DAC12_CPU_INT_MIS_FIFOEMPTYIFG_CLR       ((uint32_t)0x00000000U)         /* !< FIFOEMPTYIFG does not request an
                                                                                    interrupt service routine */
#define DAC12_CPU_INT_MIS_FIFOEMPTYIFG_SET       ((uint32_t)0x00001000U)         /* !< FIFOEMPTYIFG requests an interrupt
                                                                                    service routine */
/* DAC12_CPU_INT_MIS[FIFO1B4IFG] Bits */
#define DAC12_CPU_INT_MIS_FIFO1B4IFG_OFS         (9)                             /* !< FIFO1B4IFG Offset */
#define DAC12_CPU_INT_MIS_FIFO1B4IFG_MASK        ((uint32_t)0x00000200U)         /* !< Masked interrupt status for
                                                                                    FIFO1B4IFG */
#define DAC12_CPU_INT_MIS_FIFO1B4IFG_CLR         ((uint32_t)0x00000000U)         /* !< FIFO1B4IFG does not request an
                                                                                    interrupt service routine */
#define DAC12_CPU_INT_MIS_FIFO1B4IFG_SET         ((uint32_t)0x00000200U)         /* !< FIFO1B4IFG requests an interrupt
                                                                                    service routine */
/* DAC12_CPU_INT_MIS[FIFO1B2IFG] Bits */
#define DAC12_CPU_INT_MIS_FIFO1B2IFG_OFS         (10)                            /* !< FIFO1B2IFG Offset */
#define DAC12_CPU_INT_MIS_FIFO1B2IFG_MASK        ((uint32_t)0x00000400U)         /* !< Masked interrupt status for
                                                                                    FIFO1B2IFG */
#define DAC12_CPU_INT_MIS_FIFO1B2IFG_CLR         ((uint32_t)0x00000000U)         /* !< FIFO1B2IFG does not request an
                                                                                    interrupt service routine */
#define DAC12_CPU_INT_MIS_FIFO1B2IFG_SET         ((uint32_t)0x00000400U)         /* !< FIFO1B2IFG requests an interrupt
                                                                                    service routine */
/* DAC12_CPU_INT_MIS[FIFO3B4IFG] Bits */
#define DAC12_CPU_INT_MIS_FIFO3B4IFG_OFS         (11)                            /* !< FIFO3B4IFG Offset */
#define DAC12_CPU_INT_MIS_FIFO3B4IFG_MASK        ((uint32_t)0x00000800U)         /* !< Masked interrupt status for
                                                                                    FIFO3B4IFG */
#define DAC12_CPU_INT_MIS_FIFO3B4IFG_CLR         ((uint32_t)0x00000000U)         /* !< FIFO3B4IFG does not request an
                                                                                    interrupt service routine */
#define DAC12_CPU_INT_MIS_FIFO3B4IFG_SET         ((uint32_t)0x00000800U)         /* !< FIFO3B4IFG requests an interrupt
                                                                                    service routine */
/* DAC12_CPU_INT_MIS[FIFOFULLIFG] Bits */
#define DAC12_CPU_INT_MIS_FIFOFULLIFG_OFS        (8)                             /* !< FIFOFULLIFG Offset */
#define DAC12_CPU_INT_MIS_FIFOFULLIFG_MASK       ((uint32_t)0x00000100U)         /* !< Masked interrupt status for
                                                                                    FIFOFULLIFG */
#define DAC12_CPU_INT_MIS_FIFOFULLIFG_CLR        ((uint32_t)0x00000000U)         /* !< FIFOFULLIFG does not request an
                                                                                    interrupt service routine */
#define DAC12_CPU_INT_MIS_FIFOFULLIFG_SET        ((uint32_t)0x00000100U)         /* !< FIFOFULLIFG requests an interrupt
                                                                                    service routine */
/* DAC12_CPU_INT_MIS[FIFOURUNIFG] Bits */
#define DAC12_CPU_INT_MIS_FIFOURUNIFG_OFS        (13)                            /* !< FIFOURUNIFG Offset */
#define DAC12_CPU_INT_MIS_FIFOURUNIFG_MASK       ((uint32_t)0x00002000U)         /* !< Masked interrupt status for
                                                                                    FIFOURUNIFG */
#define DAC12_CPU_INT_MIS_FIFOURUNIFG_CLR        ((uint32_t)0x00000000U)         /* !< FIFOURUNIFG does not request an
                                                                                    interrupt service routine */
#define DAC12_CPU_INT_MIS_FIFOURUNIFG_SET        ((uint32_t)0x00002000U)         /* !< FIFOURUNIFG requests an interrupt
                                                                                    service routine */
/* DAC12_CPU_INT_MIS[DMADONEIFG] Bits */
#define DAC12_CPU_INT_MIS_DMADONEIFG_OFS         (14)                            /* !< DMADONEIFG Offset */
#define DAC12_CPU_INT_MIS_DMADONEIFG_MASK        ((uint32_t)0x00004000U)         /* !< Masked interrupt status for
                                                                                    DMADONEIFG */
#define DAC12_CPU_INT_MIS_DMADONEIFG_CLR         ((uint32_t)0x00000000U)         /* !< DMADONEIFG does not request an
                                                                                    interrupt service routine */
#define DAC12_CPU_INT_MIS_DMADONEIFG_SET         ((uint32_t)0x00004000U)         /* !< DMADONEIFG requests an interrupt
                                                                                    service routine */

/* DAC12_CPU_INT_ISET Bits */
/* DAC12_CPU_INT_ISET[MODRDYIFG] Bits */
#define DAC12_CPU_INT_ISET_MODRDYIFG_OFS         (1)                             /* !< MODRDYIFG Offset */
#define DAC12_CPU_INT_ISET_MODRDYIFG_MASK        ((uint32_t)0x00000002U)         /* !< Sets MODRDYIFG in RIS register */
#define DAC12_CPU_INT_ISET_MODRDYIFG_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ISET_MODRDYIFG_SET         ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to MODRDYIFG
                                                                                    is set */
/* DAC12_CPU_INT_ISET[FIFOEMPTYIFG] Bits */
#define DAC12_CPU_INT_ISET_FIFOEMPTYIFG_OFS      (12)                            /* !< FIFOEMPTYIFG Offset */
#define DAC12_CPU_INT_ISET_FIFOEMPTYIFG_MASK     ((uint32_t)0x00001000U)         /* !< Sets FIFOEMPTYIFG in RIS register */
#define DAC12_CPU_INT_ISET_FIFOEMPTYIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ISET_FIFOEMPTYIFG_SET      ((uint32_t)0x00001000U)         /* !< RIS bit corresponding to
                                                                                    FIFOEMPTYIFG is set */
/* DAC12_CPU_INT_ISET[FIFO1B4IFG] Bits */
#define DAC12_CPU_INT_ISET_FIFO1B4IFG_OFS        (9)                             /* !< FIFO1B4IFG Offset */
#define DAC12_CPU_INT_ISET_FIFO1B4IFG_MASK       ((uint32_t)0x00000200U)         /* !< Sets FIFO1B4IFG in RIS register */
#define DAC12_CPU_INT_ISET_FIFO1B4IFG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ISET_FIFO1B4IFG_SET        ((uint32_t)0x00000200U)         /* !< RIS bit corresponding to FIFO1B4IFG
                                                                                    is set */
/* DAC12_CPU_INT_ISET[FIFO1B2IFG] Bits */
#define DAC12_CPU_INT_ISET_FIFO1B2IFG_OFS        (10)                            /* !< FIFO1B2IFG Offset */
#define DAC12_CPU_INT_ISET_FIFO1B2IFG_MASK       ((uint32_t)0x00000400U)         /* !< Sets FIFO1B2IFG in RIS register */
#define DAC12_CPU_INT_ISET_FIFO1B2IFG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ISET_FIFO1B2IFG_SET        ((uint32_t)0x00000400U)         /* !< RIS bit corresponding to FIFO1B2IFG
                                                                                    is set */
/* DAC12_CPU_INT_ISET[FIFO3B4IFG] Bits */
#define DAC12_CPU_INT_ISET_FIFO3B4IFG_OFS        (11)                            /* !< FIFO3B4IFG Offset */
#define DAC12_CPU_INT_ISET_FIFO3B4IFG_MASK       ((uint32_t)0x00000800U)         /* !< Sets FIFO3B4IFG in RIS register */
#define DAC12_CPU_INT_ISET_FIFO3B4IFG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ISET_FIFO3B4IFG_SET        ((uint32_t)0x00000800U)         /* !< RIS bit corresponding to FIFO3B4IFG
                                                                                    is set */
/* DAC12_CPU_INT_ISET[FIFOFULLIFG] Bits */
#define DAC12_CPU_INT_ISET_FIFOFULLIFG_OFS       (8)                             /* !< FIFOFULLIFG Offset */
#define DAC12_CPU_INT_ISET_FIFOFULLIFG_MASK      ((uint32_t)0x00000100U)         /* !< Sets FIFOFULLIFG in RIS register */
#define DAC12_CPU_INT_ISET_FIFOFULLIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ISET_FIFOFULLIFG_SET       ((uint32_t)0x00000100U)         /* !< RIS bit corresponding to
                                                                                    FIFOFULLIFG is set */
/* DAC12_CPU_INT_ISET[FIFOURUNIFG] Bits */
#define DAC12_CPU_INT_ISET_FIFOURUNIFG_OFS       (13)                            /* !< FIFOURUNIFG Offset */
#define DAC12_CPU_INT_ISET_FIFOURUNIFG_MASK      ((uint32_t)0x00002000U)         /* !< Sets FIFOURUNIFG in RIS register */
#define DAC12_CPU_INT_ISET_FIFOURUNIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ISET_FIFOURUNIFG_SET       ((uint32_t)0x00002000U)         /* !< RIS bit corresponding to
                                                                                    FIFOURUNIFG is set */
/* DAC12_CPU_INT_ISET[DMADONEIFG] Bits */
#define DAC12_CPU_INT_ISET_DMADONEIFG_OFS        (14)                            /* !< DMADONEIFG Offset */
#define DAC12_CPU_INT_ISET_DMADONEIFG_MASK       ((uint32_t)0x00004000U)         /* !< Sets DMADONEIFG in RIS register */
#define DAC12_CPU_INT_ISET_DMADONEIFG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ISET_DMADONEIFG_SET        ((uint32_t)0x00004000U)         /* !< RIS bit corresponding to DMADONEIFG
                                                                                    is set */

/* DAC12_CPU_INT_ICLR Bits */
/* DAC12_CPU_INT_ICLR[MODRDYIFG] Bits */
#define DAC12_CPU_INT_ICLR_MODRDYIFG_OFS         (1)                             /* !< MODRDYIFG Offset */
#define DAC12_CPU_INT_ICLR_MODRDYIFG_MASK        ((uint32_t)0x00000002U)         /* !< Clears MODRDYIFG in RIS register */
#define DAC12_CPU_INT_ICLR_MODRDYIFG_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ICLR_MODRDYIFG_CLR         ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to MODRDYIFG
                                                                                    is cleared */
/* DAC12_CPU_INT_ICLR[FIFOEMPTYIFG] Bits */
#define DAC12_CPU_INT_ICLR_FIFOEMPTYIFG_OFS      (12)                            /* !< FIFOEMPTYIFG Offset */
#define DAC12_CPU_INT_ICLR_FIFOEMPTYIFG_MASK     ((uint32_t)0x00001000U)         /* !< Clears FIFOEMPTYIFG in RIS register */
#define DAC12_CPU_INT_ICLR_FIFOEMPTYIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ICLR_FIFOEMPTYIFG_CLR      ((uint32_t)0x00001000U)         /* !< RIS bit corresponding to
                                                                                    FIFOEMPTYIFG is cleared */
/* DAC12_CPU_INT_ICLR[FIFO1B4IFG] Bits */
#define DAC12_CPU_INT_ICLR_FIFO1B4IFG_OFS        (9)                             /* !< FIFO1B4IFG Offset */
#define DAC12_CPU_INT_ICLR_FIFO1B4IFG_MASK       ((uint32_t)0x00000200U)         /* !< Clears FIFO1B4IFG in RIS register */
#define DAC12_CPU_INT_ICLR_FIFO1B4IFG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ICLR_FIFO1B4IFG_CLR        ((uint32_t)0x00000200U)         /* !< RIS bit corresponding to FIFO1B4IFG
                                                                                    is cleared */
/* DAC12_CPU_INT_ICLR[FIFO1B2IFG] Bits */
#define DAC12_CPU_INT_ICLR_FIFO1B2IFG_OFS        (10)                            /* !< FIFO1B2IFG Offset */
#define DAC12_CPU_INT_ICLR_FIFO1B2IFG_MASK       ((uint32_t)0x00000400U)         /* !< Clears FIFO1B2IFG in RIS register */
#define DAC12_CPU_INT_ICLR_FIFO1B2IFG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ICLR_FIFO1B2IFG_CLR        ((uint32_t)0x00000400U)         /* !< RIS bit corresponding to FIFO1B2IFG
                                                                                    is cleared */
/* DAC12_CPU_INT_ICLR[FIFO3B4IFG] Bits */
#define DAC12_CPU_INT_ICLR_FIFO3B4IFG_OFS        (11)                            /* !< FIFO3B4IFG Offset */
#define DAC12_CPU_INT_ICLR_FIFO3B4IFG_MASK       ((uint32_t)0x00000800U)         /* !< Clears FIFO3B4IFG in RIS register */
#define DAC12_CPU_INT_ICLR_FIFO3B4IFG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ICLR_FIFO3B4IFG_CLR        ((uint32_t)0x00000800U)         /* !< RIS bit corresponding to FIFO3B4IFG
                                                                                    is cleared */
/* DAC12_CPU_INT_ICLR[FIFOFULLIFG] Bits */
#define DAC12_CPU_INT_ICLR_FIFOFULLIFG_OFS       (8)                             /* !< FIFOFULLIFG Offset */
#define DAC12_CPU_INT_ICLR_FIFOFULLIFG_MASK      ((uint32_t)0x00000100U)         /* !< Clears FIFOFULLIFG in RIS register */
#define DAC12_CPU_INT_ICLR_FIFOFULLIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ICLR_FIFOFULLIFG_CLR       ((uint32_t)0x00000100U)         /* !< RIS bit corresponding to
                                                                                    FIFOFULLIFG is cleared */
/* DAC12_CPU_INT_ICLR[FIFOURUNIFG] Bits */
#define DAC12_CPU_INT_ICLR_FIFOURUNIFG_OFS       (13)                            /* !< FIFOURUNIFG Offset */
#define DAC12_CPU_INT_ICLR_FIFOURUNIFG_MASK      ((uint32_t)0x00002000U)         /* !< Clears FIFOURUNIFG in RIS register */
#define DAC12_CPU_INT_ICLR_FIFOURUNIFG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ICLR_FIFOURUNIFG_CLR       ((uint32_t)0x00002000U)         /* !< RIS bit corresponding to
                                                                                    FIFOURUNIFG is cleared */
/* DAC12_CPU_INT_ICLR[DMADONEIFG] Bits */
#define DAC12_CPU_INT_ICLR_DMADONEIFG_OFS        (14)                            /* !< DMADONEIFG Offset */
#define DAC12_CPU_INT_ICLR_DMADONEIFG_MASK       ((uint32_t)0x00004000U)         /* !< Clears DMADONEIFG in RIS register */
#define DAC12_CPU_INT_ICLR_DMADONEIFG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DAC12_CPU_INT_ICLR_DMADONEIFG_CLR        ((uint32_t)0x00004000U)         /* !< RIS bit corresponding to DMADONEIFG
                                                                                    is cleared */

/* DAC12_PWREN Bits */
/* DAC12_PWREN[ENABLE] Bits */
#define DAC12_PWREN_ENABLE_OFS                   (0)                             /* !< ENABLE Offset */
#define DAC12_PWREN_ENABLE_MASK                  ((uint32_t)0x00000001U)         /* !< Enable the power */
#define DAC12_PWREN_ENABLE_DISABLE               ((uint32_t)0x00000000U)         /* !< Disable Power */
#define DAC12_PWREN_ENABLE_ENABLE                ((uint32_t)0x00000001U)         /* !< Enable Power */
/* DAC12_PWREN[KEY] Bits */
#define DAC12_PWREN_KEY_OFS                      (24)                            /* !< KEY Offset */
#define DAC12_PWREN_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define DAC12_PWREN_KEY_UNLOCK_W                 ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* DAC12_RSTCTL Bits */
/* DAC12_RSTCTL[RESETSTKYCLR] Bits */
#define DAC12_RSTCTL_RESETSTKYCLR_OFS            (1)                             /* !< RESETSTKYCLR Offset */
#define DAC12_RSTCTL_RESETSTKYCLR_MASK           ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define DAC12_RSTCTL_RESETSTKYCLR_NOP            ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DAC12_RSTCTL_RESETSTKYCLR_CLR            ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* DAC12_RSTCTL[RESETASSERT] Bits */
#define DAC12_RSTCTL_RESETASSERT_OFS             (0)                             /* !< RESETASSERT Offset */
#define DAC12_RSTCTL_RESETASSERT_MASK            ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define DAC12_RSTCTL_RESETASSERT_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DAC12_RSTCTL_RESETASSERT_ASSERT          ((uint32_t)0x00000001U)         /* !< Assert reset */
/* DAC12_RSTCTL[KEY] Bits */
#define DAC12_RSTCTL_KEY_OFS                     (24)                            /* !< KEY Offset */
#define DAC12_RSTCTL_KEY_MASK                    ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define DAC12_RSTCTL_KEY_UNLOCK_W                ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* DAC12_STAT Bits */
/* DAC12_STAT[RESETSTKY] Bits */
#define DAC12_STAT_RESETSTKY_OFS                 (16)                            /* !< RESETSTKY Offset */
#define DAC12_STAT_RESETSTKY_MASK                ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define DAC12_STAT_RESETSTKY_NORES               ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define DAC12_STAT_RESETSTKY_RESET               ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* DAC12_FSUB_0 Bits */
/* DAC12_FSUB_0[CHANID] Bits */
#define DAC12_FSUB_0_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define DAC12_FSUB_0_CHANID_MASK                 ((uint32_t)0x00007FFFU)         /* !< 0 = disconnected. others =
                                                                                    connected to channel_ID = CHANID. */
#define DAC12_FSUB_0_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define DAC12_FSUB_0_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define DAC12_FSUB_0_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* DAC12_FPUB_1 Bits */
/* DAC12_FPUB_1[CHANID] Bits */
#define DAC12_FPUB_1_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define DAC12_FPUB_1_CHANID_MASK                 ((uint32_t)0x00007FFFU)         /* !< 0 = disconnected. others =
                                                                                    connected to channel_ID = CHANID. */
#define DAC12_FPUB_1_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define DAC12_FPUB_1_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define DAC12_FPUB_1_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* DAC12_EVT_MODE Bits */
/* DAC12_EVT_MODE[INT0_CFG] Bits */
#define DAC12_EVT_MODE_INT0_CFG_OFS              (0)                             /* !< INT0_CFG Offset */
#define DAC12_EVT_MODE_INT0_CFG_MASK             ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT][0] */
#define DAC12_EVT_MODE_INT0_CFG_DISABLE          ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define DAC12_EVT_MODE_INT0_CFG_SOFTWARE         ((uint32_t)0x00000001U)         /* !< Event handled by software. Software
                                                                                    must clear the associated RIS flag. */
#define DAC12_EVT_MODE_INT0_CFG_HARDWARE         ((uint32_t)0x00000002U)         /* !< Event handled by hardware. The
                                                                                    hardware (another module) clears
                                                                                    automatically the associated RIS
                                                                                    flag. */
/* DAC12_EVT_MODE[EVT1_CFG] Bits */
#define DAC12_EVT_MODE_EVT1_CFG_OFS              (2)                             /* !< EVT1_CFG Offset */
#define DAC12_EVT_MODE_EVT1_CFG_MASK             ((uint32_t)0x0000000CU)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT][0] */
#define DAC12_EVT_MODE_EVT1_CFG_DISABLE          ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define DAC12_EVT_MODE_EVT1_CFG_SOFTWARE         ((uint32_t)0x00000004U)         /* !< Event handled by software. Software
                                                                                    must clear the associated RIS flag. */
#define DAC12_EVT_MODE_EVT1_CFG_HARDWARE         ((uint32_t)0x00000008U)         /* !< Event handled by hardware. The
                                                                                    hardware (another module) clears
                                                                                    automatically the associated RIS
                                                                                    flag. */

/* DAC12_DESC Bits */
/* DAC12_DESC[MINREV] Bits */
#define DAC12_DESC_MINREV_OFS                    (0)                             /* !< MINREV Offset */
#define DAC12_DESC_MINREV_MASK                   ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
/* DAC12_DESC[MAJREV] Bits */
#define DAC12_DESC_MAJREV_OFS                    (4)                             /* !< MAJREV Offset */
#define DAC12_DESC_MAJREV_MASK                   ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
/* DAC12_DESC[FEATUREVER] Bits */
#define DAC12_DESC_FEATUREVER_OFS                (12)                            /* !< FEATUREVER Offset */
#define DAC12_DESC_FEATUREVER_MASK               ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
/* DAC12_DESC[MODULEID] Bits */
#define DAC12_DESC_MODULEID_OFS                  (16)                            /* !< MODULEID Offset */
#define DAC12_DESC_MODULEID_MASK                 ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */

/* DAC12_CTL0 Bits */
/* DAC12_CTL0[DFM] Bits */
#define DAC12_CTL0_DFM_OFS                       (16)                            /* !< DFM Offset */
#define DAC12_CTL0_DFM_MASK                      ((uint32_t)0x00010000U)         /* !< This bit defines the DAC input data
                                                                                    format. */
#define DAC12_CTL0_DFM_BINARY                    ((uint32_t)0x00000000U)         /* !< Straight binary */
#define DAC12_CTL0_DFM_TWOS_COMP                 ((uint32_t)0x00010000U)         /* !< Twos complement */
/* DAC12_CTL0[ENABLE] Bits */
#define DAC12_CTL0_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define DAC12_CTL0_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< This bit enables the DAC module. */
#define DAC12_CTL0_ENABLE_CLR                    ((uint32_t)0x00000000U)         /* !< DAC is disabled */
#define DAC12_CTL0_ENABLE_SET                    ((uint32_t)0x00000001U)         /* !< DAC is enabled */
/* DAC12_CTL0[RES] Bits */
#define DAC12_CTL0_RES_OFS                       (8)                             /* !< RES Offset */
#define DAC12_CTL0_RES_MASK                      ((uint32_t)0x00000100U)         /* !< These bits define the DAC output
                                                                                    voltage resolution. */
#define DAC12_CTL0_RES__8BITS                    ((uint32_t)0x00000000U)         /* !< 8-bits resolution */
#define DAC12_CTL0_RES__12BITS                   ((uint32_t)0x00000100U)         /* !< 12-bit resolution */

/* DAC12_CTL1 Bits */
/* DAC12_CTL1[AMPEN] Bits */
#define DAC12_CTL1_AMPEN_OFS                     (0)                             /* !< AMPEN Offset */
#define DAC12_CTL1_AMPEN_MASK                    ((uint32_t)0x00000001U)         /* !< AMP_EN - output amplifier enabled
                                                                                    or disabled 0 : disabled  1 : enabled */
#define DAC12_CTL1_AMPEN_DISABLE                 ((uint32_t)0x00000000U)         /* !< disable */
#define DAC12_CTL1_AMPEN_ENABLE                  ((uint32_t)0x00000001U)         /* !< enable */
/* DAC12_CTL1[REFSP] Bits */
#define DAC12_CTL1_REFSP_OFS                     (8)                             /* !< REFSP Offset */
#define DAC12_CTL1_REFSP_MASK                    ((uint32_t)0x00000100U)         /* !< This bit selects the DAC voltage
                                                                                    reference source + input. */
#define DAC12_CTL1_REFSP_VDDA                    ((uint32_t)0x00000000U)         /* !< Analog supply (VDDA) as VR+ */
#define DAC12_CTL1_REFSP_VEREFP                  ((uint32_t)0x00000100U)         /* !< VEREFP pin as VR+ */
/* DAC12_CTL1[OPS] Bits */
#define DAC12_CTL1_OPS_OFS                       (24)                            /* !< OPS Offset */
#define DAC12_CTL1_OPS_MASK                      ((uint32_t)0x01000000U)         /* !< These bits select the DAC output on
                                                                                    device pin. */
#define DAC12_CTL1_OPS_NOC0                      ((uint32_t)0x00000000U)         /* !< No connect. Both DAC output
                                                                                    switches are open. */
#define DAC12_CTL1_OPS_OUT0                      ((uint32_t)0x01000000U)         /* !< OUT0 output is selected */
/* DAC12_CTL1[REFSN] Bits */
#define DAC12_CTL1_REFSN_OFS                     (9)                             /* !< REFSN Offset */
#define DAC12_CTL1_REFSN_MASK                    ((uint32_t)0x00000200U)         /* !< This bit selects the DAC voltage
                                                                                    reference source + input. */
#define DAC12_CTL1_REFSN_VEREFN                  ((uint32_t)0x00000000U)         /* !< VEREFN pin as VR- */
#define DAC12_CTL1_REFSN_VSSA                    ((uint32_t)0x00000200U)         /* !< Analog supply (VSSA) as VR- */
/* DAC12_CTL1[AMPHIZ] Bits */
#define DAC12_CTL1_AMPHIZ_OFS                    (1)                             /* !< AMPHIZ Offset */
#define DAC12_CTL1_AMPHIZ_MASK                   ((uint32_t)0x00000002U)         /* !< AMPHIZ - amplifier output value  0
                                                                                    : amplifier output is high impedance
                                                                                    1 : amplifier output is pulled down
                                                                                    to ground */
#define DAC12_CTL1_AMPHIZ_HIZ                    ((uint32_t)0x00000000U)         /* !< HiZ when disable */
#define DAC12_CTL1_AMPHIZ_PULLDOWN               ((uint32_t)0x00000002U)         /* !< dacout pulldown when disable */

/* DAC12_CTL2 Bits */
/* DAC12_CTL2[FIFOEN] Bits */
#define DAC12_CTL2_FIFOEN_OFS                    (0)                             /* !< FIFOEN Offset */
#define DAC12_CTL2_FIFOEN_MASK                   ((uint32_t)0x00000001U)         /* !< This bit enables the FIFO and the
                                                                                    FIFO hardware control state machine. */
#define DAC12_CTL2_FIFOEN_CLR                    ((uint32_t)0x00000000U)         /* !< FIFO is disabled */
#define DAC12_CTL2_FIFOEN_SET                    ((uint32_t)0x00000001U)         /* !< FIFO is enabled */
/* DAC12_CTL2[FIFOTH] Bits */
#define DAC12_CTL2_FIFOTH_OFS                    (8)                             /* !< FIFOTH Offset */
#define DAC12_CTL2_FIFOTH_MASK                   ((uint32_t)0x00000300U)         /* !< These bits determine the FIFO
                                                                                    threshold. In case of DMA based
                                                                                    operation, DAC generates new DMA
                                                                                    trigger when the number of empty
                                                                                    locations in FIFO match the selected
                                                                                    FIFO threshold level.  In case of CPU
                                                                                    based operation, the FIFO threshold
                                                                                    bits are don't care and FIFO level is
                                                                                    directly indicated through the
                                                                                    respective bits in the RIS register. */
#define DAC12_CTL2_FIFOTH_LOW                    ((uint32_t)0x00000000U)         /* !< One fourth of the FIFO locations
                                                                                    are empty */
#define DAC12_CTL2_FIFOTH_MED                    ((uint32_t)0x00000100U)         /* !< Half of the FIFO locations are
                                                                                    empty */
#define DAC12_CTL2_FIFOTH_HIGH                   ((uint32_t)0x00000200U)         /* !< Three fourth of the FIFO locations
                                                                                    are empty */
#define DAC12_CTL2_FIFOTH_SPARE                  ((uint32_t)0x00000300U)         /* !< Reserved value. Defaults to same
                                                                                    effect as FIFOTH = 0 (One fourth of
                                                                                    the FIFO locations are empty). */
/* DAC12_CTL2[FIFOTRIGSEL] Bits */
#define DAC12_CTL2_FIFOTRIGSEL_OFS               (16)                            /* !< FIFOTRIGSEL Offset */
#define DAC12_CTL2_FIFOTRIGSEL_MASK              ((uint32_t)0x00030000U)         /* !< These bits select the source for
                                                                                    FIFO read trigger. When the selected
                                                                                    FIFO read trigger is asserted, the
                                                                                    data from FIFO (as indicated by read
                                                                                    pointer) is moved into internal DAC
                                                                                    data register. */
#define DAC12_CTL2_FIFOTRIGSEL_STIM              ((uint32_t)0x00000000U)         /* !< Sample time generator output */
#define DAC12_CTL2_FIFOTRIGSEL_TRIG0             ((uint32_t)0x00010000U)         /* !< Hardware trigger-0 from event
                                                                                    fabric */
#define DAC12_CTL2_FIFOTRIGSEL_SPARE1            ((uint32_t)0x00020000U)         /* !< Reserved - unimplemented */
#define DAC12_CTL2_FIFOTRIGSEL_SPARE2            ((uint32_t)0x00030000U)         /* !< Reserved - unimplemented */
/* DAC12_CTL2[DMATRIGEN] Bits */
#define DAC12_CTL2_DMATRIGEN_OFS                 (24)                            /* !< DMATRIGEN Offset */
#define DAC12_CTL2_DMATRIGEN_MASK                ((uint32_t)0x01000000U)         /* !< This bit enables the DMA trigger
                                                                                    generation mechanism. When this bit
                                                                                    is set along with FIFOEN, the DMA
                                                                                    trigger is generated based on the
                                                                                    empty FIFO locations qualified by
                                                                                    FIFOTH settings. This bit should be
                                                                                    cleared by software to stop further
                                                                                    DMA triggers. */
#define DAC12_CTL2_DMATRIGEN_CLR                 ((uint32_t)0x00000000U)         /* !< DMA trigger generation mechanism is
                                                                                    disabled */
#define DAC12_CTL2_DMATRIGEN_SET                 ((uint32_t)0x01000000U)         /* !< DMA trigger generation mechanism is
                                                                                    enabled */

/* DAC12_CTL3 Bits */
/* DAC12_CTL3[STIMEN] Bits */
#define DAC12_CTL3_STIMEN_OFS                    (0)                             /* !< STIMEN Offset */
#define DAC12_CTL3_STIMEN_MASK                   ((uint32_t)0x00000001U)         /* !< This bit enables the sample time
                                                                                    generator. */
#define DAC12_CTL3_STIMEN_CLR                    ((uint32_t)0x00000000U)         /* !< Sample time generator is disabled */
#define DAC12_CTL3_STIMEN_SET                    ((uint32_t)0x00000001U)         /* !< Sample time generator is enabled */
/* DAC12_CTL3[STIMCONFIG] Bits */
#define DAC12_CTL3_STIMCONFIG_OFS                (8)                             /* !< STIMCONFIG Offset */
#define DAC12_CTL3_STIMCONFIG_MASK               ((uint32_t)0x00000F00U)         /* !< These bits are used to configure
                                                                                    the trigger rate from the sample time
                                                                                    generator. The STIMCONFIG values 10
                                                                                    to 15 are reserved and default to
                                                                                    same effect as value 0 (500SPS). */
#define DAC12_CTL3_STIMCONFIG__500SPS            ((uint32_t)0x00000000U)         /* !< Trigger rate is 500 sps (clock
                                                                                    divide value is 4000) */
#define DAC12_CTL3_STIMCONFIG__1KSPS             ((uint32_t)0x00000100U)         /* !< Trigger rate is 1 ksps (clock
                                                                                    divide value is 2000) */
#define DAC12_CTL3_STIMCONFIG__2KSPS             ((uint32_t)0x00000200U)         /* !< Trigger rate is 2 ksps (clock
                                                                                    divide value is 1000) */
#define DAC12_CTL3_STIMCONFIG__4KSPS             ((uint32_t)0x00000300U)         /* !< Trigger rate is 4 ksps (clock
                                                                                    divide value is 500) */
#define DAC12_CTL3_STIMCONFIG__8KSPS             ((uint32_t)0x00000400U)         /* !< Trigger rate is 8 ksps (clock
                                                                                    divide value is 250) */
#define DAC12_CTL3_STIMCONFIG__16KSPS            ((uint32_t)0x00000500U)         /* !< Trigger rate is 16 ksps (clock
                                                                                    divide value is 125) */
#define DAC12_CTL3_STIMCONFIG__100KSPS           ((uint32_t)0x00000600U)         /* !< Trigger rate is 100 ksps (clock
                                                                                    divide value is 20) */
#define DAC12_CTL3_STIMCONFIG__200KSPS           ((uint32_t)0x00000700U)         /* !< Trigger rate is 200 ksps (clock
                                                                                    divide value is 10) */
#define DAC12_CTL3_STIMCONFIG__500KSPS           ((uint32_t)0x00000800U)         /* !< Trigger rate is 500 ksps (clock
                                                                                    divide value is 4) */
#define DAC12_CTL3_STIMCONFIG__1MSPS             ((uint32_t)0x00000900U)         /* !< Trigger rate is 1 Msps (clock
                                                                                    divide value is 2) */

/* DAC12_CALCTL Bits */
/* DAC12_CALCTL[CALON] Bits */
#define DAC12_CALCTL_CALON_OFS                   (0)                             /* !< CALON Offset */
#define DAC12_CALCTL_CALON_MASK                  ((uint32_t)0x00000001U)         /* !< This bit when set initiates the DAC
                                                                                    offset error calibration sequence and
                                                                                    is automatically reset when the
                                                                                    offset error calibration completes. */
#define DAC12_CALCTL_CALON_INACTIVE              ((uint32_t)0x00000000U)         /* !< Offset error calibration is not
                                                                                    active */
#define DAC12_CALCTL_CALON_ACTIVE                ((uint32_t)0x00000001U)         /* !< Initiate offset error calibration
                                                                                    or offset error calibration is
                                                                                    already in progress */
/* DAC12_CALCTL[CALSEL] Bits */
#define DAC12_CALCTL_CALSEL_OFS                  (1)                             /* !< CALSEL Offset */
#define DAC12_CALCTL_CALSEL_MASK                 ((uint32_t)0x00000002U)         /* !< This bit is used to select between
                                                                                    factory trim or self calibration
                                                                                    trim. */
#define DAC12_CALCTL_CALSEL_FACTORYTRIM          ((uint32_t)0x00000000U)         /* !< Factory Trim Calibration Values are
                                                                                    used when calibration is enabled */
#define DAC12_CALCTL_CALSEL_SELFCALIBRATIONTRIM  ((uint32_t)0x00000002U)         /* !< Self Calibration Trim Values are
                                                                                    used when calibration is enabled */

/* DAC12_CALDATA Bits */
/* DAC12_CALDATA[DATA] Bits */
#define DAC12_CALDATA_DATA_OFS                   (0)                             /* !< DATA Offset */
#define DAC12_CALDATA_DATA_MASK                  ((uint32_t)0x0000007FU)         /* !< DAC offset error calibration data.
                                                                                    The DAC offset error calibration data
                                                                                    is represented in twos complement
                                                                                    format providing a range of 64 to
                                                                                    +63. This is read-only bit,
                                                                                    reflecting the calibration data.
                                                                                    Writing to this register will have no
                                                                                    effect, it will not change the
                                                                                    calibration value. */

/* DAC12_DATA0 Bits */
/* DAC12_DATA0[DATA_VALUE] Bits */
#define DAC12_DATA0_DATA_VALUE_OFS               (0)                             /* !< DATA_VALUE Offset */
#define DAC12_DATA0_DATA_VALUE_MASK              ((uint32_t)0x00000FFFU)         /* !< This is the data written for
                                                                                    digital to analog conversion. */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_dac12__include */
