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

#ifndef ti_devices_msp_peripherals_hw_spi__include
#define ti_devices_msp_peripherals_hw_spi__include

/* Filename: hw_spi.h */
/* Revised: 2023-05-01 11:44:28 */
/* Revision: e59cc9a0a7fab62c1b5a05a01c0efbbc96c33ec7 */

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
* SPI Registers
******************************************************************************/
#define SPI_DMA_TRIG_TX_OFS                      ((uint32_t)0x00001080U)
#define SPI_DMA_TRIG_RX_OFS                      ((uint32_t)0x00001050U)
#define SPI_CPU_INT_OFS                          ((uint32_t)0x00001020U)
#define SPI_GPRCM_OFS                            ((uint32_t)0x00000800U)


/** @addtogroup SPI_DMA_TRIG_TX
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
} SPI_DMA_TRIG_TX_Regs;

/*@}*/ /* end of group SPI_DMA_TRIG_TX */

/** @addtogroup SPI_DMA_TRIG_RX
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
} SPI_DMA_TRIG_RX_Regs;

/*@}*/ /* end of group SPI_DMA_TRIG_RX */

/** @addtogroup SPI_CPU_INT
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
} SPI_CPU_INT_Regs;

/*@}*/ /* end of group SPI_CPU_INT */

/** @addtogroup SPI_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00000808) Peripheral Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} SPI_GPRCM_Regs;

/*@}*/ /* end of group SPI_GPRCM */

/** @addtogroup SPI
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  SPI_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED1[506];
  __IO uint32_t CLKDIV;                            /* !< (@ 0x00001000) Clock Divider */
  __IO uint32_t CLKSEL;                            /* !< (@ 0x00001004) Clock Select for Ultra Low Power peripherals */
       uint32_t RESERVED2[4];
  __IO uint32_t PDBGCTL;                           /* !< (@ 0x00001018) Peripheral Debug Control */
       uint32_t RESERVED3;
  SPI_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED4;
  SPI_DMA_TRIG_RX_Regs  DMA_TRIG_RX;                       /* !< (@ 0x00001050) */
       uint32_t RESERVED5;
  SPI_DMA_TRIG_TX_Regs  DMA_TRIG_TX;                       /* !< (@ 0x00001080) */
       uint32_t RESERVED6[13];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
  __IO uint32_t INTCTL;                            /* !< (@ 0x000010E4) Interrupt control register */
       uint32_t RESERVED7[6];
  __IO uint32_t CTL0;                              /* !< (@ 0x00001100) SPI control register 0 */
  __IO uint32_t CTL1;                              /* !< (@ 0x00001104) SPI control register 1 */
  __IO uint32_t CLKCTL;                            /* !< (@ 0x00001108) Clock prescaler and divider register. */
  __IO uint32_t IFLS;                              /* !< (@ 0x0000110C) Interrupt FIFO Level Select Register */
  __I  uint32_t STAT;                              /* !< (@ 0x00001110) Status Register */
       uint32_t RESERVED8[7];
  __I  uint32_t RXDATA;                            /* !< (@ 0x00001130) RXDATA Register */
       uint32_t RESERVED9[3];
  __IO uint32_t TXDATA;                            /* !< (@ 0x00001140) TXDATA Register */
} SPI_Regs;

/*@}*/ /* end of group SPI */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* SPI Register Control Bits
******************************************************************************/

/* SPI_DMA_TRIG_TX_IIDX Bits */
/* SPI_DMA_TRIG_TX_IIDX[STAT] Bits */
#define SPI_DMA_TRIG_TX_IIDX_STAT_OFS            (0)                             /* !< STAT Offset */
#define SPI_DMA_TRIG_TX_IIDX_STAT_MASK           ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define SPI_DMA_TRIG_TX_IIDX_STAT_NO_INTR        ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define SPI_DMA_TRIG_TX_IIDX_STAT_TX_EVT         ((uint32_t)0x00000005U)         /* !< Transmit Event/interrupt pending */

/* SPI_DMA_TRIG_TX_IMASK Bits */
/* SPI_DMA_TRIG_TX_IMASK[TX] Bits */
#define SPI_DMA_TRIG_TX_IMASK_TX_OFS             (4)                             /* !< TX Offset */
#define SPI_DMA_TRIG_TX_IMASK_TX_MASK            ((uint32_t)0x00000010U)         /* !< Transmit FIFO event mask. */
#define SPI_DMA_TRIG_TX_IMASK_TX_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_DMA_TRIG_TX_IMASK_TX_SET             ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */

/* SPI_DMA_TRIG_TX_RIS Bits */
/* SPI_DMA_TRIG_TX_RIS[TX] Bits */
#define SPI_DMA_TRIG_TX_RIS_TX_OFS               (4)                             /* !< TX Offset */
#define SPI_DMA_TRIG_TX_RIS_TX_MASK              ((uint32_t)0x00000010U)         /* !< Transmit FIFO event: A read returns
                                                                                    the current mask for transmit FIFO
                                                                                    interrupt. On a write of 1, the mask
                                                                                    for transmit FIFO interrupt is set
                                                                                    which means the interrupt state will
                                                                                    be reflected in MIS.TXMIS. A write of
                                                                                    0 clears the mask which means
                                                                                    MIS.TXMIS will not reflect the
                                                                                    interrupt. */
#define SPI_DMA_TRIG_TX_RIS_TX_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_DMA_TRIG_TX_RIS_TX_SET               ((uint32_t)0x00000010U)         /* !< Interrupt occurred */

/* SPI_DMA_TRIG_TX_MIS Bits */
/* SPI_DMA_TRIG_TX_MIS[TX] Bits */
#define SPI_DMA_TRIG_TX_MIS_TX_OFS               (4)                             /* !< TX Offset */
#define SPI_DMA_TRIG_TX_MIS_TX_MASK              ((uint32_t)0x00000010U)         /* !< Masked Transmit FIFO event */
#define SPI_DMA_TRIG_TX_MIS_TX_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_DMA_TRIG_TX_MIS_TX_SET               ((uint32_t)0x00000010U)         /* !< Interrupt occurred */

/* SPI_DMA_TRIG_TX_ISET Bits */
/* SPI_DMA_TRIG_TX_ISET[TX] Bits */
#define SPI_DMA_TRIG_TX_ISET_TX_OFS              (4)                             /* !< TX Offset */
#define SPI_DMA_TRIG_TX_ISET_TX_MASK             ((uint32_t)0x00000010U)         /* !< Set Transmit FIFO event. */
#define SPI_DMA_TRIG_TX_ISET_TX_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_DMA_TRIG_TX_ISET_TX_SET              ((uint32_t)0x00000010U)         /* !< Set Interrupt */

/* SPI_DMA_TRIG_TX_ICLR Bits */
/* SPI_DMA_TRIG_TX_ICLR[TX] Bits */
#define SPI_DMA_TRIG_TX_ICLR_TX_OFS              (4)                             /* !< TX Offset */
#define SPI_DMA_TRIG_TX_ICLR_TX_MASK             ((uint32_t)0x00000010U)         /* !< Clear Transmit FIFO event. */
#define SPI_DMA_TRIG_TX_ICLR_TX_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_DMA_TRIG_TX_ICLR_TX_CLR              ((uint32_t)0x00000010U)         /* !< Clear Interrupt */

/* SPI_DMA_TRIG_RX_IIDX Bits */
/* SPI_DMA_TRIG_RX_IIDX[STAT] Bits */
#define SPI_DMA_TRIG_RX_IIDX_STAT_OFS            (0)                             /* !< STAT Offset */
#define SPI_DMA_TRIG_RX_IIDX_STAT_MASK           ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define SPI_DMA_TRIG_RX_IIDX_STAT_NO_INTR        ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define SPI_DMA_TRIG_RX_IIDX_STAT_RTOUT_EVT      ((uint32_t)0x00000003U)         /* !< SPI receive time-out interrupt */
#define SPI_DMA_TRIG_RX_IIDX_STAT_RX_EVT         ((uint32_t)0x00000004U)         /* !< Receive Event/interrupt pending */

/* SPI_DMA_TRIG_RX_IMASK Bits */
/* SPI_DMA_TRIG_RX_IMASK[RX] Bits */
#define SPI_DMA_TRIG_RX_IMASK_RX_OFS             (3)                             /* !< RX Offset */
#define SPI_DMA_TRIG_RX_IMASK_RX_MASK            ((uint32_t)0x00000008U)         /* !< Receive FIFO event mask. */
#define SPI_DMA_TRIG_RX_IMASK_RX_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_DMA_TRIG_RX_IMASK_RX_SET             ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */
/* SPI_DMA_TRIG_RX_IMASK[RTOUT] Bits */
#define SPI_DMA_TRIG_RX_IMASK_RTOUT_OFS          (2)                             /* !< RTOUT Offset */
#define SPI_DMA_TRIG_RX_IMASK_RTOUT_MASK         ((uint32_t)0x00000004U)         /* !< SPI Receive Time-Out event mask. */
#define SPI_DMA_TRIG_RX_IMASK_RTOUT_CLR          ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_DMA_TRIG_RX_IMASK_RTOUT_SET          ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */

/* SPI_DMA_TRIG_RX_RIS Bits */
/* SPI_DMA_TRIG_RX_RIS[RX] Bits */
#define SPI_DMA_TRIG_RX_RIS_RX_OFS               (3)                             /* !< RX Offset */
#define SPI_DMA_TRIG_RX_RIS_RX_MASK              ((uint32_t)0x00000008U)         /* !< Receive FIFO event.This interrupt
                                                                                    is set if the selected Receive FIFO
                                                                                    level has been reached */
#define SPI_DMA_TRIG_RX_RIS_RX_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_DMA_TRIG_RX_RIS_RX_SET               ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* SPI_DMA_TRIG_RX_RIS[RTOUT] Bits */
#define SPI_DMA_TRIG_RX_RIS_RTOUT_OFS            (2)                             /* !< RTOUT Offset */
#define SPI_DMA_TRIG_RX_RIS_RTOUT_MASK           ((uint32_t)0x00000004U)         /* !< SPI Receive Time-Out Event. */
#define SPI_DMA_TRIG_RX_RIS_RTOUT_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_DMA_TRIG_RX_RIS_RTOUT_SET            ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */

/* SPI_DMA_TRIG_RX_MIS Bits */
/* SPI_DMA_TRIG_RX_MIS[RX] Bits */
#define SPI_DMA_TRIG_RX_MIS_RX_OFS               (3)                             /* !< RX Offset */
#define SPI_DMA_TRIG_RX_MIS_RX_MASK              ((uint32_t)0x00000008U)         /* !< Receive FIFO event mask. */
#define SPI_DMA_TRIG_RX_MIS_RX_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_DMA_TRIG_RX_MIS_RX_SET               ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* SPI_DMA_TRIG_RX_MIS[RTOUT] Bits */
#define SPI_DMA_TRIG_RX_MIS_RTOUT_OFS            (2)                             /* !< RTOUT Offset */
#define SPI_DMA_TRIG_RX_MIS_RTOUT_MASK           ((uint32_t)0x00000004U)         /* !< SPI Receive Time-Out event mask. */
#define SPI_DMA_TRIG_RX_MIS_RTOUT_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_DMA_TRIG_RX_MIS_RTOUT_SET            ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */

/* SPI_DMA_TRIG_RX_ISET Bits */
/* SPI_DMA_TRIG_RX_ISET[RX] Bits */
#define SPI_DMA_TRIG_RX_ISET_RX_OFS              (3)                             /* !< RX Offset */
#define SPI_DMA_TRIG_RX_ISET_RX_MASK             ((uint32_t)0x00000008U)         /* !< Set Receive FIFO event. */
#define SPI_DMA_TRIG_RX_ISET_RX_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_DMA_TRIG_RX_ISET_RX_SET              ((uint32_t)0x00000008U)         /* !< Set Interrupt */
/* SPI_DMA_TRIG_RX_ISET[RTOUT] Bits */
#define SPI_DMA_TRIG_RX_ISET_RTOUT_OFS           (2)                             /* !< RTOUT Offset */
#define SPI_DMA_TRIG_RX_ISET_RTOUT_MASK          ((uint32_t)0x00000004U)         /* !< Set SPI Receive Time-Out event. */
#define SPI_DMA_TRIG_RX_ISET_RTOUT_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_DMA_TRIG_RX_ISET_RTOUT_SET           ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */

/* SPI_DMA_TRIG_RX_ICLR Bits */
/* SPI_DMA_TRIG_RX_ICLR[RX] Bits */
#define SPI_DMA_TRIG_RX_ICLR_RX_OFS              (3)                             /* !< RX Offset */
#define SPI_DMA_TRIG_RX_ICLR_RX_MASK             ((uint32_t)0x00000008U)         /* !< Clear Receive FIFO event. */
#define SPI_DMA_TRIG_RX_ICLR_RX_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_DMA_TRIG_RX_ICLR_RX_CLR              ((uint32_t)0x00000008U)         /* !< Clear Interrupt */
/* SPI_DMA_TRIG_RX_ICLR[RTOUT] Bits */
#define SPI_DMA_TRIG_RX_ICLR_RTOUT_OFS           (2)                             /* !< RTOUT Offset */
#define SPI_DMA_TRIG_RX_ICLR_RTOUT_MASK          ((uint32_t)0x00000004U)         /* !< Clear SPI Receive Time-Out event. */
#define SPI_DMA_TRIG_RX_ICLR_RTOUT_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_DMA_TRIG_RX_ICLR_RTOUT_CLR           ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */

/* SPI_CPU_INT_IIDX Bits */
/* SPI_CPU_INT_IIDX[STAT] Bits */
#define SPI_CPU_INT_IIDX_STAT_OFS                (0)                             /* !< STAT Offset */
#define SPI_CPU_INT_IIDX_STAT_MASK               ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define SPI_CPU_INT_IIDX_STAT_NO_INTR            ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define SPI_CPU_INT_IIDX_STAT_RXFIFO_OFV_EVT     ((uint32_t)0x00000001U)         /* !< RX FIFO Overflow Event/interrupt
                                                                                    pending */
#define SPI_CPU_INT_IIDX_STAT_PER_EVT            ((uint32_t)0x00000002U)         /* !< Transmit Parity Event/interrupt
                                                                                    pending */
#define SPI_CPU_INT_IIDX_STAT_RTOUT_EVT          ((uint32_t)0x00000003U)         /* !< SPI receive time-out interrupt */
#define SPI_CPU_INT_IIDX_STAT_RX_EVT             ((uint32_t)0x00000004U)         /* !< Receive Event/interrupt pending */
#define SPI_CPU_INT_IIDX_STAT_TX_EVT             ((uint32_t)0x00000005U)         /* !< Transmit Event/interrupt pending */
#define SPI_CPU_INT_IIDX_STAT_TX_EMPTY           ((uint32_t)0x00000006U)         /* !< Transmit Buffer Empty
                                                                                    Event/interrupt pending */
#define SPI_CPU_INT_IIDX_STAT_IDLE_EVT           ((uint32_t)0x00000007U)         /* !< End of Transmit Event/interrupt
                                                                                    pending */
#define SPI_CPU_INT_IIDX_STAT_DMA_DONE_RX_EVT    ((uint32_t)0x00000008U)         /* !< DMA Done for Receive
                                                                                    Event/interrupt pending */
#define SPI_CPU_INT_IIDX_STAT_DMA_DONE_TX_EVT    ((uint32_t)0x00000009U)         /* !< DMA Done for Transmit
                                                                                    Event/interrupt pending */
#define SPI_CPU_INT_IIDX_STAT_TXFIFO_UNF_EVT     ((uint32_t)0x0000000AU)         /* !< TX FIFO underflow interrupt */
#define SPI_CPU_INT_IIDX_STAT_RXFULL_EVT         ((uint32_t)0x0000000BU)         /* !< RX FIFO Full Interrupt */

/* SPI_CPU_INT_IMASK Bits */
/* SPI_CPU_INT_IMASK[RX] Bits */
#define SPI_CPU_INT_IMASK_RX_OFS                 (3)                             /* !< RX Offset */
#define SPI_CPU_INT_IMASK_RX_MASK                ((uint32_t)0x00000008U)         /* !< Receive FIFO event.This interrupt
                                                                                    is set if the selected Receive FIFO
                                                                                    level has been reached */
#define SPI_CPU_INT_IMASK_RX_CLR                 ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_IMASK_RX_SET                 ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_IMASK[TX] Bits */
#define SPI_CPU_INT_IMASK_TX_OFS                 (4)                             /* !< TX Offset */
#define SPI_CPU_INT_IMASK_TX_MASK                ((uint32_t)0x00000010U)         /* !< Transmit FIFO event mask. */
#define SPI_CPU_INT_IMASK_TX_CLR                 ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_IMASK_TX_SET                 ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_IMASK[TXEMPTY] Bits */
#define SPI_CPU_INT_IMASK_TXEMPTY_OFS            (5)                             /* !< TXEMPTY Offset */
#define SPI_CPU_INT_IMASK_TXEMPTY_MASK           ((uint32_t)0x00000020U)         /* !< Transmit FIFO Empty event mask. */
#define SPI_CPU_INT_IMASK_TXEMPTY_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_IMASK_TXEMPTY_SET            ((uint32_t)0x00000020U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_IMASK[PER] Bits */
#define SPI_CPU_INT_IMASK_PER_OFS                (1)                             /* !< PER Offset */
#define SPI_CPU_INT_IMASK_PER_MASK               ((uint32_t)0x00000002U)         /* !< Parity error event mask. */
#define SPI_CPU_INT_IMASK_PER_CLR                ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_IMASK_PER_SET                ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_IMASK[DMA_DONE_RX] Bits */
#define SPI_CPU_INT_IMASK_DMA_DONE_RX_OFS        (7)                             /* !< DMA_DONE_RX Offset */
#define SPI_CPU_INT_IMASK_DMA_DONE_RX_MASK       ((uint32_t)0x00000080U)         /* !< DMA Done 1 event for RX event mask. */
#define SPI_CPU_INT_IMASK_DMA_DONE_RX_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_IMASK_DMA_DONE_RX_SET        ((uint32_t)0x00000080U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_IMASK[RXFIFO_OVF] Bits */
#define SPI_CPU_INT_IMASK_RXFIFO_OVF_OFS         (0)                             /* !< RXFIFO_OVF Offset */
#define SPI_CPU_INT_IMASK_RXFIFO_OVF_MASK        ((uint32_t)0x00000001U)         /* !< RXFIFO overflow event mask. */
#define SPI_CPU_INT_IMASK_RXFIFO_OVF_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_IMASK_RXFIFO_OVF_SET         ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_IMASK[DMA_DONE_TX] Bits */
#define SPI_CPU_INT_IMASK_DMA_DONE_TX_OFS        (8)                             /* !< DMA_DONE_TX Offset */
#define SPI_CPU_INT_IMASK_DMA_DONE_TX_MASK       ((uint32_t)0x00000100U)         /* !< DMA Done 1 event for TX event mask. */
#define SPI_CPU_INT_IMASK_DMA_DONE_TX_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_IMASK_DMA_DONE_TX_SET        ((uint32_t)0x00000100U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_IMASK[IDLE] Bits */
#define SPI_CPU_INT_IMASK_IDLE_OFS               (6)                             /* !< IDLE Offset */
#define SPI_CPU_INT_IMASK_IDLE_MASK              ((uint32_t)0x00000040U)         /* !< SPI Idle event mask. */
#define SPI_CPU_INT_IMASK_IDLE_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_IMASK_IDLE_SET               ((uint32_t)0x00000040U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_IMASK[RTOUT] Bits */
#define SPI_CPU_INT_IMASK_RTOUT_OFS              (2)                             /* !< RTOUT Offset */
#define SPI_CPU_INT_IMASK_RTOUT_MASK             ((uint32_t)0x00000004U)         /* !< Enable SPI Receive Time-Out event
                                                                                    mask. */
#define SPI_CPU_INT_IMASK_RTOUT_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_IMASK_RTOUT_SET              ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_IMASK[RXFULL] Bits */
#define SPI_CPU_INT_IMASK_RXFULL_OFS             (10)                            /* !< RXFULL Offset */
#define SPI_CPU_INT_IMASK_RXFULL_MASK            ((uint32_t)0x00000400U)         /* !< RX FIFO Full Interrupt Mask */
#define SPI_CPU_INT_IMASK_RXFULL_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_IMASK_RXFULL_SET             ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_IMASK[TXFIFO_UNF] Bits */
#define SPI_CPU_INT_IMASK_TXFIFO_UNF_OFS         (9)                             /* !< TXFIFO_UNF Offset */
#define SPI_CPU_INT_IMASK_TXFIFO_UNF_MASK        ((uint32_t)0x00000200U)         /* !< TX FIFO underflow interrupt mask */
#define SPI_CPU_INT_IMASK_TXFIFO_UNF_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_IMASK_TXFIFO_UNF_SET         ((uint32_t)0x00000200U)         /* !< Set Interrupt Mask */

/* SPI_CPU_INT_RIS Bits */
/* SPI_CPU_INT_RIS[RX] Bits */
#define SPI_CPU_INT_RIS_RX_OFS                   (3)                             /* !< RX Offset */
#define SPI_CPU_INT_RIS_RX_MASK                  ((uint32_t)0x00000008U)         /* !< Receive FIFO event.This interrupt
                                                                                    is set if the selected Receive FIFO
                                                                                    level has been reached */
#define SPI_CPU_INT_RIS_RX_CLR                   ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_RIS_RX_SET                   ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_RIS[TX] Bits */
#define SPI_CPU_INT_RIS_TX_OFS                   (4)                             /* !< TX Offset */
#define SPI_CPU_INT_RIS_TX_MASK                  ((uint32_t)0x00000010U)         /* !< Transmit FIFO event..This interrupt
                                                                                    is set if the selected Transmit FIFO
                                                                                    level has been reached. */
#define SPI_CPU_INT_RIS_TX_CLR                   ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_RIS_TX_SET                   ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_RIS[TXEMPTY] Bits */
#define SPI_CPU_INT_RIS_TXEMPTY_OFS              (5)                             /* !< TXEMPTY Offset */
#define SPI_CPU_INT_RIS_TXEMPTY_MASK             ((uint32_t)0x00000020U)         /* !< Transmit FIFO Empty interrupt mask.
                                                                                    This interrupt is set if all data in
                                                                                    the Transmit FIFO have been move to
                                                                                    the shift register. */
#define SPI_CPU_INT_RIS_TXEMPTY_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_RIS_TXEMPTY_SET              ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_RIS[PER] Bits */
#define SPI_CPU_INT_RIS_PER_OFS                  (1)                             /* !< PER Offset */
#define SPI_CPU_INT_RIS_PER_MASK                 ((uint32_t)0x00000002U)         /* !< Parity error event: this bit is set
                                                                                    if a Parity error has been detected */
#define SPI_CPU_INT_RIS_PER_CLR                  ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_RIS_PER_SET                  ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_RIS[DMA_DONE_RX] Bits */
#define SPI_CPU_INT_RIS_DMA_DONE_RX_OFS          (7)                             /* !< DMA_DONE_RX Offset */
#define SPI_CPU_INT_RIS_DMA_DONE_RX_MASK         ((uint32_t)0x00000080U)         /* !< DMA Done 1 event for RX. This
                                                                                    interrupt is set if the RX DMA
                                                                                    channel sends the DONE signal. This
                                                                                    allows the handling of the DMA event
                                                                                    inside the mapped peripheral. */
#define SPI_CPU_INT_RIS_DMA_DONE_RX_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_RIS_DMA_DONE_RX_SET          ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_RIS[RXFIFO_OVF] Bits */
#define SPI_CPU_INT_RIS_RXFIFO_OVF_OFS           (0)                             /* !< RXFIFO_OVF Offset */
#define SPI_CPU_INT_RIS_RXFIFO_OVF_MASK          ((uint32_t)0x00000001U)         /* !< RXFIFO overflow event. This
                                                                                    interrupt is set if an RX FIFO
                                                                                    overflow has been detected. */
#define SPI_CPU_INT_RIS_RXFIFO_OVF_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_RIS_RXFIFO_OVF_SET           ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_RIS[DMA_DONE_TX] Bits */
#define SPI_CPU_INT_RIS_DMA_DONE_TX_OFS          (8)                             /* !< DMA_DONE_TX Offset */
#define SPI_CPU_INT_RIS_DMA_DONE_TX_MASK         ((uint32_t)0x00000100U)         /* !< DMA Done 1 event for TX. This
                                                                                    interrupt is set if the TX DMA
                                                                                    channel sends the DONE signal. This
                                                                                    allows the handling of the DMA event
                                                                                    inside the mapped peripheral. */
#define SPI_CPU_INT_RIS_DMA_DONE_TX_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_RIS_DMA_DONE_TX_SET          ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_RIS[IDLE] Bits */
#define SPI_CPU_INT_RIS_IDLE_OFS                 (6)                             /* !< IDLE Offset */
#define SPI_CPU_INT_RIS_IDLE_MASK                ((uint32_t)0x00000040U)         /* !< SPI has done finished transfers and
                                                                                    changed into IDLE mode. This bit is
                                                                                    set when BUSY goes low. */
#define SPI_CPU_INT_RIS_IDLE_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_RIS_IDLE_SET                 ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_RIS[RTOUT] Bits */
#define SPI_CPU_INT_RIS_RTOUT_OFS                (2)                             /* !< RTOUT Offset */
#define SPI_CPU_INT_RIS_RTOUT_MASK               ((uint32_t)0x00000004U)         /* !< SPI Receive Time-Out event. */
#define SPI_CPU_INT_RIS_RTOUT_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_RIS_RTOUT_SET                ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_RIS[TXFIFO_UNF] Bits */
#define SPI_CPU_INT_RIS_TXFIFO_UNF_OFS           (9)                             /* !< TXFIFO_UNF Offset */
#define SPI_CPU_INT_RIS_TXFIFO_UNF_MASK          ((uint32_t)0x00000200U)         /* !< TX FIFO Underflow Interrupt */
#define SPI_CPU_INT_RIS_TXFIFO_UNF_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_RIS_TXFIFO_UNF_SET           ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_RIS[RXFULL] Bits */
#define SPI_CPU_INT_RIS_RXFULL_OFS               (10)                            /* !< RXFULL Offset */
#define SPI_CPU_INT_RIS_RXFULL_MASK              ((uint32_t)0x00000400U)         /* !< RX FIFO Full Interrupt */
#define SPI_CPU_INT_RIS_RXFULL_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_RIS_RXFULL_SET               ((uint32_t)0x00000400U)         /* !< Interrupt occurred */

/* SPI_CPU_INT_MIS Bits */
/* SPI_CPU_INT_MIS[RX] Bits */
#define SPI_CPU_INT_MIS_RX_OFS                   (3)                             /* !< RX Offset */
#define SPI_CPU_INT_MIS_RX_MASK                  ((uint32_t)0x00000008U)         /* !< Masked receive FIFO event.This
                                                                                    interrupt is set if the selected
                                                                                    Receive FIFO level has been reached */
#define SPI_CPU_INT_MIS_RX_CLR                   ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_MIS_RX_SET                   ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_MIS[TX] Bits */
#define SPI_CPU_INT_MIS_TX_OFS                   (4)                             /* !< TX Offset */
#define SPI_CPU_INT_MIS_TX_MASK                  ((uint32_t)0x00000010U)         /* !< Masked Transmit FIFO event. This
                                                                                    interrupt is set if the selected
                                                                                    Transmit FIFO level has been reached. */
#define SPI_CPU_INT_MIS_TX_CLR                   ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_MIS_TX_SET                   ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_MIS[TXEMPTY] Bits */
#define SPI_CPU_INT_MIS_TXEMPTY_OFS              (5)                             /* !< TXEMPTY Offset */
#define SPI_CPU_INT_MIS_TXEMPTY_MASK             ((uint32_t)0x00000020U)         /* !< Masked Transmit FIFO Empty event. */
#define SPI_CPU_INT_MIS_TXEMPTY_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_MIS_TXEMPTY_SET              ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_MIS[PER] Bits */
#define SPI_CPU_INT_MIS_PER_OFS                  (1)                             /* !< PER Offset */
#define SPI_CPU_INT_MIS_PER_MASK                 ((uint32_t)0x00000002U)         /* !< Masked Parity error event: this bit
                                                                                    if a Parity error has been detected */
#define SPI_CPU_INT_MIS_PER_CLR                  ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_MIS_PER_SET                  ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_MIS[DMA_DONE_RX] Bits */
#define SPI_CPU_INT_MIS_DMA_DONE_RX_OFS          (7)                             /* !< DMA_DONE_RX Offset */
#define SPI_CPU_INT_MIS_DMA_DONE_RX_MASK         ((uint32_t)0x00000080U)         /* !< Masked DMA Done 1 event for RX. */
#define SPI_CPU_INT_MIS_DMA_DONE_RX_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_MIS_DMA_DONE_RX_SET          ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_MIS[RXFIFO_OVF] Bits */
#define SPI_CPU_INT_MIS_RXFIFO_OVF_OFS           (0)                             /* !< RXFIFO_OVF Offset */
#define SPI_CPU_INT_MIS_RXFIFO_OVF_MASK          ((uint32_t)0x00000001U)         /* !< Masked RXFIFO overflow event. This
                                                                                    interrupt is set if an RX FIFO
                                                                                    overflow has been detected. */
#define SPI_CPU_INT_MIS_RXFIFO_OVF_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_MIS_RXFIFO_OVF_SET           ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_MIS[DMA_DONE_TX] Bits */
#define SPI_CPU_INT_MIS_DMA_DONE_TX_OFS          (8)                             /* !< DMA_DONE_TX Offset */
#define SPI_CPU_INT_MIS_DMA_DONE_TX_MASK         ((uint32_t)0x00000100U)         /* !< Masked DMA Done 1 event for TX. */
#define SPI_CPU_INT_MIS_DMA_DONE_TX_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_MIS_DMA_DONE_TX_SET          ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_MIS[IDLE] Bits */
#define SPI_CPU_INT_MIS_IDLE_OFS                 (6)                             /* !< IDLE Offset */
#define SPI_CPU_INT_MIS_IDLE_MASK                ((uint32_t)0x00000040U)         /* !< Masked SPI IDLE mode event. */
#define SPI_CPU_INT_MIS_IDLE_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_MIS_IDLE_SET                 ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_MIS[RTOUT] Bits */
#define SPI_CPU_INT_MIS_RTOUT_OFS                (2)                             /* !< RTOUT Offset */
#define SPI_CPU_INT_MIS_RTOUT_MASK               ((uint32_t)0x00000004U)         /* !< Masked SPI Receive Time-Out
                                                                                    Interrupt. */
#define SPI_CPU_INT_MIS_RTOUT_CLR                ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define SPI_CPU_INT_MIS_RTOUT_SET                ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_MIS[RXFULL] Bits */
#define SPI_CPU_INT_MIS_RXFULL_OFS               (10)                            /* !< RXFULL Offset */
#define SPI_CPU_INT_MIS_RXFULL_MASK              ((uint32_t)0x00000400U)         /* !< RX FIFO Full Interrupt */
#define SPI_CPU_INT_MIS_RXFULL_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_MIS_RXFULL_SET               ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* SPI_CPU_INT_MIS[TXFIFO_UNF] Bits */
#define SPI_CPU_INT_MIS_TXFIFO_UNF_OFS           (9)                             /* !< TXFIFO_UNF Offset */
#define SPI_CPU_INT_MIS_TXFIFO_UNF_MASK          ((uint32_t)0x00000200U)         /* !< TX FIFO underflow interrupt */
#define SPI_CPU_INT_MIS_TXFIFO_UNF_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define SPI_CPU_INT_MIS_TXFIFO_UNF_SET           ((uint32_t)0x00000200U)         /* !< Interrupt occurred */

/* SPI_CPU_INT_ISET Bits */
/* SPI_CPU_INT_ISET[RX] Bits */
#define SPI_CPU_INT_ISET_RX_OFS                  (3)                             /* !< RX Offset */
#define SPI_CPU_INT_ISET_RX_MASK                 ((uint32_t)0x00000008U)         /* !< Set Receive FIFO event. */
#define SPI_CPU_INT_ISET_RX_NO_EFFECT            ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ISET_RX_SET                  ((uint32_t)0x00000008U)         /* !< Set Interrupt */
/* SPI_CPU_INT_ISET[TX] Bits */
#define SPI_CPU_INT_ISET_TX_OFS                  (4)                             /* !< TX Offset */
#define SPI_CPU_INT_ISET_TX_MASK                 ((uint32_t)0x00000010U)         /* !< Set Transmit FIFO event. */
#define SPI_CPU_INT_ISET_TX_NO_EFFECT            ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ISET_TX_SET                  ((uint32_t)0x00000010U)         /* !< Set Interrupt */
/* SPI_CPU_INT_ISET[TXEMPTY] Bits */
#define SPI_CPU_INT_ISET_TXEMPTY_OFS             (5)                             /* !< TXEMPTY Offset */
#define SPI_CPU_INT_ISET_TXEMPTY_MASK            ((uint32_t)0x00000020U)         /* !< Set Transmit FIFO Empty event. */
#define SPI_CPU_INT_ISET_TXEMPTY_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ISET_TXEMPTY_SET             ((uint32_t)0x00000020U)         /* !< Set Interrupt */
/* SPI_CPU_INT_ISET[PER] Bits */
#define SPI_CPU_INT_ISET_PER_OFS                 (1)                             /* !< PER Offset */
#define SPI_CPU_INT_ISET_PER_MASK                ((uint32_t)0x00000002U)         /* !< Set Parity error event. */
#define SPI_CPU_INT_ISET_PER_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ISET_PER_SET                 ((uint32_t)0x00000002U)         /* !< Set Interrupt */
/* SPI_CPU_INT_ISET[DMA_DONE_RX] Bits */
#define SPI_CPU_INT_ISET_DMA_DONE_RX_OFS         (7)                             /* !< DMA_DONE_RX Offset */
#define SPI_CPU_INT_ISET_DMA_DONE_RX_MASK        ((uint32_t)0x00000080U)         /* !< Set DMA Done 1 event for RX. */
#define SPI_CPU_INT_ISET_DMA_DONE_RX_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ISET_DMA_DONE_RX_SET         ((uint32_t)0x00000080U)         /* !< Set Interrupt */
/* SPI_CPU_INT_ISET[RXFIFO_OVF] Bits */
#define SPI_CPU_INT_ISET_RXFIFO_OVF_OFS          (0)                             /* !< RXFIFO_OVF Offset */
#define SPI_CPU_INT_ISET_RXFIFO_OVF_MASK         ((uint32_t)0x00000001U)         /* !< Set RXFIFO overflow event. */
#define SPI_CPU_INT_ISET_RXFIFO_OVF_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ISET_RXFIFO_OVF_SET          ((uint32_t)0x00000001U)         /* !< Set Interrupt */
/* SPI_CPU_INT_ISET[DMA_DONE_TX] Bits */
#define SPI_CPU_INT_ISET_DMA_DONE_TX_OFS         (8)                             /* !< DMA_DONE_TX Offset */
#define SPI_CPU_INT_ISET_DMA_DONE_TX_MASK        ((uint32_t)0x00000100U)         /* !< Set DMA Done 1 event for TX. */
#define SPI_CPU_INT_ISET_DMA_DONE_TX_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ISET_DMA_DONE_TX_SET         ((uint32_t)0x00000100U)         /* !< Set Interrupt */
/* SPI_CPU_INT_ISET[IDLE] Bits */
#define SPI_CPU_INT_ISET_IDLE_OFS                (6)                             /* !< IDLE Offset */
#define SPI_CPU_INT_ISET_IDLE_MASK               ((uint32_t)0x00000040U)         /* !< Set SPI IDLE mode event. */
#define SPI_CPU_INT_ISET_IDLE_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ISET_IDLE_SET                ((uint32_t)0x00000040U)         /* !< Set Interrupt */
/* SPI_CPU_INT_ISET[RTOUT] Bits */
#define SPI_CPU_INT_ISET_RTOUT_OFS               (2)                             /* !< RTOUT Offset */
#define SPI_CPU_INT_ISET_RTOUT_MASK              ((uint32_t)0x00000004U)         /* !< Set SPI Receive Time-Out Event. */
#define SPI_CPU_INT_ISET_RTOUT_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ISET_RTOUT_SET               ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_ISET[TXFIFO_UNF] Bits */
#define SPI_CPU_INT_ISET_TXFIFO_UNF_OFS          (9)                             /* !< TXFIFO_UNF Offset */
#define SPI_CPU_INT_ISET_TXFIFO_UNF_MASK         ((uint32_t)0x00000200U)         /* !< Set TX FIFO Underflow Event */
#define SPI_CPU_INT_ISET_TXFIFO_UNF_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing has no effect */
#define SPI_CPU_INT_ISET_TXFIFO_UNF_SET          ((uint32_t)0x00000200U)         /* !< Set interrupt */
/* SPI_CPU_INT_ISET[RXFULL] Bits */
#define SPI_CPU_INT_ISET_RXFULL_OFS              (10)                            /* !< RXFULL Offset */
#define SPI_CPU_INT_ISET_RXFULL_MASK             ((uint32_t)0x00000400U)         /* !< Set RX FIFO Full Event */
#define SPI_CPU_INT_ISET_RXFULL_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing has no effect */
#define SPI_CPU_INT_ISET_RXFULL_SET              ((uint32_t)0x00000400U)         /* !< Set Interrupt */

/* SPI_CPU_INT_ICLR Bits */
/* SPI_CPU_INT_ICLR[RX] Bits */
#define SPI_CPU_INT_ICLR_RX_OFS                  (3)                             /* !< RX Offset */
#define SPI_CPU_INT_ICLR_RX_MASK                 ((uint32_t)0x00000008U)         /* !< Clear Receive FIFO event. */
#define SPI_CPU_INT_ICLR_RX_NO_EFFECT            ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ICLR_RX_CLR                  ((uint32_t)0x00000008U)         /* !< Clear Interrupt */
/* SPI_CPU_INT_ICLR[TX] Bits */
#define SPI_CPU_INT_ICLR_TX_OFS                  (4)                             /* !< TX Offset */
#define SPI_CPU_INT_ICLR_TX_MASK                 ((uint32_t)0x00000010U)         /* !< Clear Transmit FIFO event. */
#define SPI_CPU_INT_ICLR_TX_NO_EFFECT            ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ICLR_TX_CLR                  ((uint32_t)0x00000010U)         /* !< Clear Interrupt */
/* SPI_CPU_INT_ICLR[TXEMPTY] Bits */
#define SPI_CPU_INT_ICLR_TXEMPTY_OFS             (5)                             /* !< TXEMPTY Offset */
#define SPI_CPU_INT_ICLR_TXEMPTY_MASK            ((uint32_t)0x00000020U)         /* !< Clear Transmit FIFO Empty event. */
#define SPI_CPU_INT_ICLR_TXEMPTY_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ICLR_TXEMPTY_CLR             ((uint32_t)0x00000020U)         /* !< Clear Interrupt */
/* SPI_CPU_INT_ICLR[PER] Bits */
#define SPI_CPU_INT_ICLR_PER_OFS                 (1)                             /* !< PER Offset */
#define SPI_CPU_INT_ICLR_PER_MASK                ((uint32_t)0x00000002U)         /* !< Clear Parity error event. */
#define SPI_CPU_INT_ICLR_PER_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ICLR_PER_CLR                 ((uint32_t)0x00000002U)         /* !< Clear Interrupt */
/* SPI_CPU_INT_ICLR[DMA_DONE_RX] Bits */
#define SPI_CPU_INT_ICLR_DMA_DONE_RX_OFS         (7)                             /* !< DMA_DONE_RX Offset */
#define SPI_CPU_INT_ICLR_DMA_DONE_RX_MASK        ((uint32_t)0x00000080U)         /* !< Clear DMA Done 1 event for RX. */
#define SPI_CPU_INT_ICLR_DMA_DONE_RX_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ICLR_DMA_DONE_RX_CLR         ((uint32_t)0x00000080U)         /* !< Clear Interrupt */
/* SPI_CPU_INT_ICLR[RXFIFO_OVF] Bits */
#define SPI_CPU_INT_ICLR_RXFIFO_OVF_OFS          (0)                             /* !< RXFIFO_OVF Offset */
#define SPI_CPU_INT_ICLR_RXFIFO_OVF_MASK         ((uint32_t)0x00000001U)         /* !< Clear RXFIFO overflow event. */
#define SPI_CPU_INT_ICLR_RXFIFO_OVF_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ICLR_RXFIFO_OVF_CLR          ((uint32_t)0x00000001U)         /* !< Clear Interrupt */
/* SPI_CPU_INT_ICLR[DMA_DONE_TX] Bits */
#define SPI_CPU_INT_ICLR_DMA_DONE_TX_OFS         (8)                             /* !< DMA_DONE_TX Offset */
#define SPI_CPU_INT_ICLR_DMA_DONE_TX_MASK        ((uint32_t)0x00000100U)         /* !< Clear DMA Done 1 event for TX. */
#define SPI_CPU_INT_ICLR_DMA_DONE_TX_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ICLR_DMA_DONE_TX_CLR         ((uint32_t)0x00000100U)         /* !< Clear Interrupt */
/* SPI_CPU_INT_ICLR[IDLE] Bits */
#define SPI_CPU_INT_ICLR_IDLE_OFS                (6)                             /* !< IDLE Offset */
#define SPI_CPU_INT_ICLR_IDLE_MASK               ((uint32_t)0x00000040U)         /* !< Clear SPI IDLE mode event. */
#define SPI_CPU_INT_ICLR_IDLE_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ICLR_IDLE_CLR                ((uint32_t)0x00000040U)         /* !< Clear Interrupt */
/* SPI_CPU_INT_ICLR[RTOUT] Bits */
#define SPI_CPU_INT_ICLR_RTOUT_OFS               (2)                             /* !< RTOUT Offset */
#define SPI_CPU_INT_ICLR_RTOUT_MASK              ((uint32_t)0x00000004U)         /* !< Clear SPI Receive Time-Out Event. */
#define SPI_CPU_INT_ICLR_RTOUT_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_CPU_INT_ICLR_RTOUT_CLR               ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* SPI_CPU_INT_ICLR[TXFIFO_UNF] Bits */
#define SPI_CPU_INT_ICLR_TXFIFO_UNF_OFS          (9)                             /* !< TXFIFO_UNF Offset */
#define SPI_CPU_INT_ICLR_TXFIFO_UNF_MASK         ((uint32_t)0x00000200U)         /* !< Clear TXFIFO underflow event */
#define SPI_CPU_INT_ICLR_TXFIFO_UNF_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing has no effect */
#define SPI_CPU_INT_ICLR_TXFIFO_UNF_CLR          ((uint32_t)0x00000200U)         /* !< Clear interrupt */
/* SPI_CPU_INT_ICLR[RXFULL] Bits */
#define SPI_CPU_INT_ICLR_RXFULL_OFS              (10)                            /* !< RXFULL Offset */
#define SPI_CPU_INT_ICLR_RXFULL_MASK             ((uint32_t)0x00000400U)         /* !< Clear RX FIFO underflow event */
#define SPI_CPU_INT_ICLR_RXFULL_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing has no effect */
#define SPI_CPU_INT_ICLR_RXFULL_CLR              ((uint32_t)0x00000400U)         /* !< Clear interrupt */

/* SPI_PWREN Bits */
/* SPI_PWREN[ENABLE] Bits */
#define SPI_PWREN_ENABLE_OFS                     (0)                             /* !< ENABLE Offset */
#define SPI_PWREN_ENABLE_MASK                    ((uint32_t)0x00000001U)         /* !< Enable the power */
#define SPI_PWREN_ENABLE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Disable Power */
#define SPI_PWREN_ENABLE_ENABLE                  ((uint32_t)0x00000001U)         /* !< Enable Power */
/* SPI_PWREN[KEY] Bits */
#define SPI_PWREN_KEY_OFS                        (24)                            /* !< KEY Offset */
#define SPI_PWREN_KEY_MASK                       ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define SPI_PWREN_KEY_UNLOCK_W                   ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* SPI_RSTCTL Bits */
/* SPI_RSTCTL[RESETSTKYCLR] Bits */
#define SPI_RSTCTL_RESETSTKYCLR_OFS              (1)                             /* !< RESETSTKYCLR Offset */
#define SPI_RSTCTL_RESETSTKYCLR_MASK             ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define SPI_RSTCTL_RESETSTKYCLR_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_RSTCTL_RESETSTKYCLR_CLR              ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* SPI_RSTCTL[RESETASSERT] Bits */
#define SPI_RSTCTL_RESETASSERT_OFS               (0)                             /* !< RESETASSERT Offset */
#define SPI_RSTCTL_RESETASSERT_MASK              ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define SPI_RSTCTL_RESETASSERT_NOP               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SPI_RSTCTL_RESETASSERT_ASSERT            ((uint32_t)0x00000001U)         /* !< Assert reset */
/* SPI_RSTCTL[KEY] Bits */
#define SPI_RSTCTL_KEY_OFS                       (24)                            /* !< KEY Offset */
#define SPI_RSTCTL_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define SPI_RSTCTL_KEY_UNLOCK_W                  ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* SPI_CLKCFG Bits */
/* SPI_CLKCFG[KEY] Bits */
#define SPI_CLKCFG_KEY_OFS                       (24)                            /* !< KEY Offset */
#define SPI_CLKCFG_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define SPI_CLKCFG_KEY_UNLOCK                    ((uint32_t)0xA9000000U)         /* !< key value to allow change field of
                                                                                    GPRCM */
/* SPI_CLKCFG[BLOCKASYNC] Bits */
#define SPI_CLKCFG_BLOCKASYNC_OFS                (8)                             /* !< BLOCKASYNC Offset */
#define SPI_CLKCFG_BLOCKASYNC_MASK               ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define SPI_CLKCFG_BLOCKASYNC_DISABLE            ((uint32_t)0x00000000U)         /* !< Not block async clock request */
#define SPI_CLKCFG_BLOCKASYNC_ENABLE             ((uint32_t)0x00000100U)         /* !< Block async clock request */

/* SPI_GPRCM_STAT Bits */
/* SPI_GPRCM_STAT[RESETSTKY] Bits */
#define SPI_GPRCM_STAT_RESETSTKY_OFS             (16)                            /* !< RESETSTKY Offset */
#define SPI_GPRCM_STAT_RESETSTKY_MASK            ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define SPI_GPRCM_STAT_RESETSTKY_NORES           ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define SPI_GPRCM_STAT_RESETSTKY_RESET           ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* SPI_CLKDIV Bits */
/* SPI_CLKDIV[RATIO] Bits */
#define SPI_CLKDIV_RATIO_OFS                     (0)                             /* !< RATIO Offset */
#define SPI_CLKDIV_RATIO_MASK                    ((uint32_t)0x00000007U)         /* !< Selects divide ratio of module
                                                                                    clock */
#define SPI_CLKDIV_RATIO_DIV_BY_1                ((uint32_t)0x00000000U)         /* !< Do not divide clock source */
#define SPI_CLKDIV_RATIO_DIV_BY_2                ((uint32_t)0x00000001U)         /* !< Divide clock source by 2 */
#define SPI_CLKDIV_RATIO_DIV_BY_3                ((uint32_t)0x00000002U)         /* !< Divide clock source by 3 */
#define SPI_CLKDIV_RATIO_DIV_BY_4                ((uint32_t)0x00000003U)         /* !< Divide clock source by 4 */
#define SPI_CLKDIV_RATIO_DIV_BY_5                ((uint32_t)0x00000004U)         /* !< Divide clock source by 5 */
#define SPI_CLKDIV_RATIO_DIV_BY_6                ((uint32_t)0x00000005U)         /* !< Divide clock source by 6 */
#define SPI_CLKDIV_RATIO_DIV_BY_7                ((uint32_t)0x00000006U)         /* !< Divide clock source by 7 */
#define SPI_CLKDIV_RATIO_DIV_BY_8                ((uint32_t)0x00000007U)         /* !< Divide clock source by 8 */

/* SPI_CLKSEL Bits */
/* SPI_CLKSEL[LFCLK_SEL] Bits */
#define SPI_CLKSEL_LFCLK_SEL_OFS                 (1)                             /* !< LFCLK_SEL Offset */
#define SPI_CLKSEL_LFCLK_SEL_MASK                ((uint32_t)0x00000002U)         /* !< Selects LFCLK as clock source if
                                                                                    enabled */
#define SPI_CLKSEL_LFCLK_SEL_DISABLE             ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define SPI_CLKSEL_LFCLK_SEL_ENABLE              ((uint32_t)0x00000002U)         /* !< Select this clock as a source */
/* SPI_CLKSEL[MFCLK_SEL] Bits */
#define SPI_CLKSEL_MFCLK_SEL_OFS                 (2)                             /* !< MFCLK_SEL Offset */
#define SPI_CLKSEL_MFCLK_SEL_MASK                ((uint32_t)0x00000004U)         /* !< Selects MFCLK as clock source if
                                                                                    enabled */
#define SPI_CLKSEL_MFCLK_SEL_DISABLE             ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define SPI_CLKSEL_MFCLK_SEL_ENABLE              ((uint32_t)0x00000004U)         /* !< Select this clock as a source */
/* SPI_CLKSEL[SYSCLK_SEL] Bits */
#define SPI_CLKSEL_SYSCLK_SEL_OFS                (3)                             /* !< SYSCLK_SEL Offset */
#define SPI_CLKSEL_SYSCLK_SEL_MASK               ((uint32_t)0x00000008U)         /* !< Selects SYSCLK as clock source if
                                                                                    enabled */
#define SPI_CLKSEL_SYSCLK_SEL_DISABLE            ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define SPI_CLKSEL_SYSCLK_SEL_ENABLE             ((uint32_t)0x00000008U)         /* !< Select this clock as a source */

/* SPI_PDBGCTL Bits */
/* SPI_PDBGCTL[FREE] Bits */
#define SPI_PDBGCTL_FREE_OFS                     (0)                             /* !< FREE Offset */
#define SPI_PDBGCTL_FREE_MASK                    ((uint32_t)0x00000001U)         /* !< Free run control */
#define SPI_PDBGCTL_FREE_STOP                    ((uint32_t)0x00000000U)         /* !< The peripheral freezes
                                                                                    functionality while the Core Halted
                                                                                    input is asserted and resumes when it
                                                                                    is deasserted. */
#define SPI_PDBGCTL_FREE_RUN                     ((uint32_t)0x00000001U)         /* !< The peripheral ignores the state of
                                                                                    the Core Halted input */
/* SPI_PDBGCTL[SOFT] Bits */
#define SPI_PDBGCTL_SOFT_OFS                     (1)                             /* !< SOFT Offset */
#define SPI_PDBGCTL_SOFT_MASK                    ((uint32_t)0x00000002U)         /* !< Soft halt boundary control. This
                                                                                    function is only available, if [FREE]
                                                                                    is set to 'STOP' */
#define SPI_PDBGCTL_SOFT_IMMEDIATE               ((uint32_t)0x00000000U)         /* !< The peripheral will halt
                                                                                    immediately, even if the resultant
                                                                                    state will result in corruption if
                                                                                    the system is restarted */
#define SPI_PDBGCTL_SOFT_DELAYED                 ((uint32_t)0x00000002U)         /* !< The peripheral blocks the debug
                                                                                    freeze until it has reached a
                                                                                    boundary where it can resume without
                                                                                    corruption */

/* SPI_EVT_MODE Bits */
/* SPI_EVT_MODE[INT0_CFG] Bits */
#define SPI_EVT_MODE_INT0_CFG_OFS                (0)                             /* !< INT0_CFG Offset */
#define SPI_EVT_MODE_INT0_CFG_MASK               ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT0] */
#define SPI_EVT_MODE_INT0_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define SPI_EVT_MODE_INT0_CFG_SOFTWARE           ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define SPI_EVT_MODE_INT0_CFG_HARDWARE           ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* SPI_EVT_MODE[INT1_CFG] Bits */
#define SPI_EVT_MODE_INT1_CFG_OFS                (2)                             /* !< INT1_CFG Offset */
#define SPI_EVT_MODE_INT1_CFG_MASK               ((uint32_t)0x0000000CU)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT1] */
#define SPI_EVT_MODE_INT1_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define SPI_EVT_MODE_INT1_CFG_SOFTWARE           ((uint32_t)0x00000004U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define SPI_EVT_MODE_INT1_CFG_HARDWARE           ((uint32_t)0x00000008U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* SPI_EVT_MODE[INT2_CFG] Bits */
#define SPI_EVT_MODE_INT2_CFG_OFS                (4)                             /* !< INT2_CFG Offset */
#define SPI_EVT_MODE_INT2_CFG_MASK               ((uint32_t)0x00000030U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT2] */
#define SPI_EVT_MODE_INT2_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define SPI_EVT_MODE_INT2_CFG_SOFTWARE           ((uint32_t)0x00000010U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define SPI_EVT_MODE_INT2_CFG_HARDWARE           ((uint32_t)0x00000020U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* SPI_INTCTL Bits */
/* SPI_INTCTL[INTEVAL] Bits */
#define SPI_INTCTL_INTEVAL_OFS                   (0)                             /* !< INTEVAL Offset */
#define SPI_INTCTL_INTEVAL_MASK                  ((uint32_t)0x00000001U)         /* !< Writing a 1 to this field
                                                                                    re-evaluates the interrupt sources. */
#define SPI_INTCTL_INTEVAL_DISABLE               ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define SPI_INTCTL_INTEVAL_EVAL                  ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */

/* SPI_CTL0 Bits */
/* SPI_CTL0[DSS] Bits */
#define SPI_CTL0_DSS_OFS                         (0)                             /* !< DSS Offset */
#define SPI_CTL0_DSS_MASK                        ((uint32_t)0x0000001FU)         /* !< Data Size Select. Values 0 - 2 are
                                                                                    reserved and shall not be used. 3h =
                                                                                    4_BIT : 4-bit data SPI allows only
                                                                                    values up to 16 Bit */
#define SPI_CTL0_DSS_DSS_4                       ((uint32_t)0x00000003U)         /* !< Data Size Select bits: 4 */
#define SPI_CTL0_DSS_DSS_5                       ((uint32_t)0x00000004U)         /* !< Data Size Select bits: 5 */
#define SPI_CTL0_DSS_DSS_6                       ((uint32_t)0x00000005U)         /* !< Data Size Select bits: 6 */
#define SPI_CTL0_DSS_DSS_7                       ((uint32_t)0x00000006U)         /* !< Data Size Select bits: 7 */
#define SPI_CTL0_DSS_DSS_8                       ((uint32_t)0x00000007U)         /* !< Data Size Select bits: 8 */
#define SPI_CTL0_DSS_DSS_9                       ((uint32_t)0x00000008U)         /* !< Data Size Select bits: 9 */
#define SPI_CTL0_DSS_DSS_10                      ((uint32_t)0x00000009U)         /* !< Data Size Select bits: 10 */
#define SPI_CTL0_DSS_DSS_11                      ((uint32_t)0x0000000AU)         /* !< Data Size Select bits: 11 */
#define SPI_CTL0_DSS_DSS_12                      ((uint32_t)0x0000000BU)         /* !< Data Size Select bits: 12 */
#define SPI_CTL0_DSS_DSS_13                      ((uint32_t)0x0000000CU)         /* !< Data Size Select bits: 13 */
#define SPI_CTL0_DSS_DSS_14                      ((uint32_t)0x0000000DU)         /* !< Data Size Select bits: 14 */
#define SPI_CTL0_DSS_DSS_15                      ((uint32_t)0x0000000EU)         /* !< Data Size Select bits: 15 */
#define SPI_CTL0_DSS_DSS_16                      ((uint32_t)0x0000000FU)         /* !< Data Size Select bits: 16 */
/* SPI_CTL0[FRF] Bits */
#define SPI_CTL0_FRF_OFS                         (5)                             /* !< FRF Offset */
#define SPI_CTL0_FRF_MASK                        ((uint32_t)0x00000060U)         /* !< Frame format Select */
#define SPI_CTL0_FRF_MOTOROLA_3WIRE              ((uint32_t)0x00000000U)         /* !< Motorola SPI frame format (3 wire
                                                                                    mode) */
#define SPI_CTL0_FRF_MOTOROLA_4WIRE              ((uint32_t)0x00000020U)         /* !< Motorola SPI frame format (4 wire
                                                                                    mode) */
#define SPI_CTL0_FRF_TI_SYNC                     ((uint32_t)0x00000040U)         /* !< TI synchronous serial frame format */
#define SPI_CTL0_FRF_MIRCOWIRE                   ((uint32_t)0x00000060U)         /* !< National Microwire frame format */
/* SPI_CTL0[SPO] Bits */
#define SPI_CTL0_SPO_OFS                         (8)                             /* !< SPO Offset */
#define SPI_CTL0_SPO_MASK                        ((uint32_t)0x00000100U)         /* !< CLKOUT polarity (Motorola SPI frame
                                                                                    format only) */
#define SPI_CTL0_SPO_LOW                         ((uint32_t)0x00000000U)         /* !< SPI produces a steady state LOW
                                                                                    value on the CLKOUT */
#define SPI_CTL0_SPO_HIGH                        ((uint32_t)0x00000100U)         /* !< SPI produces a steady state HIGH
                                                                                    value on the CLKOUT */
/* SPI_CTL0[SPH] Bits */
#define SPI_CTL0_SPH_OFS                         (9)                             /* !< SPH Offset */
#define SPI_CTL0_SPH_MASK                        ((uint32_t)0x00000200U)         /* !< CLKOUT phase (Motorola SPI frame
                                                                                    format only) This bit selects the
                                                                                    clock edge that captures data and
                                                                                    enables it to change state. It has
                                                                                    the most impact on the first bit
                                                                                    transmitted by either permitting or
                                                                                    not permitting a clock transition
                                                                                    before the first data capture edge. */
#define SPI_CTL0_SPH_FIRST                       ((uint32_t)0x00000000U)         /* !< Data is captured on the first clock
                                                                                    edge transition. */
#define SPI_CTL0_SPH_SECOND                      ((uint32_t)0x00000200U)         /* !< Data is captured on the second
                                                                                    clock edge transition. */
/* SPI_CTL0[CSSEL] Bits */
#define SPI_CTL0_CSSEL_OFS                       (12)                            /* !< CSSEL Offset */
#define SPI_CTL0_CSSEL_MASK                      ((uint32_t)0x00003000U)         /* !< Select the CS line to control on
                                                                                    data transfer This bit is applicable
                                                                                    for both controller/target mode */
#define SPI_CTL0_CSSEL_CSSEL_0                   ((uint32_t)0x00000000U)         /* !< CS line select: 0 */
#define SPI_CTL0_CSSEL_CSSEL_1                   ((uint32_t)0x00001000U)         /* !< CS line select: 1 */
#define SPI_CTL0_CSSEL_CSSEL_2                   ((uint32_t)0x00002000U)         /* !< CS line select: 2 */
#define SPI_CTL0_CSSEL_CSSEL_3                   ((uint32_t)0x00003000U)         /* !< CS line select: 3 */
/* SPI_CTL0[CSCLR] Bits */
#define SPI_CTL0_CSCLR_OFS                       (14)                            /* !< CSCLR Offset */
#define SPI_CTL0_CSCLR_MASK                      ((uint32_t)0x00004000U)         /* !< Clear shift register counter on CS
                                                                                    inactive This bit is relevant only in
                                                                                    the peripheral, CTL1.CP=0. */
#define SPI_CTL0_CSCLR_DISABLE                   ((uint32_t)0x00000000U)         /* !< Disable automatic clear of shift
                                                                                    register when CS goes to disable. */
#define SPI_CTL0_CSCLR_ENABLE                    ((uint32_t)0x00004000U)         /* !< Enable automatic clear of shift
                                                                                    register when CS goes to disable. */
/* SPI_CTL0[PACKEN] Bits */
#define SPI_CTL0_PACKEN_OFS                      (7)                             /* !< PACKEN Offset */
#define SPI_CTL0_PACKEN_MASK                     ((uint32_t)0x00000080U)         /* !< Packing Enable. When 1, packing
                                                                                    feature is enabled inside the IP When
                                                                                    0, packing feature is disabled inside
                                                                                    the IP */
#define SPI_CTL0_PACKEN_DISABLED                 ((uint32_t)0x00000000U)         /* !< Packing feature disabled */
#define SPI_CTL0_PACKEN_ENABLED                  ((uint32_t)0x00000080U)         /* !< Packing feature enabled */

/* SPI_CTL1 Bits */
/* SPI_CTL1[LBM] Bits */
#define SPI_CTL1_LBM_OFS                         (1)                             /* !< LBM Offset */
#define SPI_CTL1_LBM_MASK                        ((uint32_t)0x00000002U)         /* !< Loop back mode */
#define SPI_CTL1_LBM_DISABLE                     ((uint32_t)0x00000000U)         /* !< Disable loopback mode */
#define SPI_CTL1_LBM_ENABLE                      ((uint32_t)0x00000002U)         /* !< Enable loopback mode */
/* SPI_CTL1[CP] Bits */
#define SPI_CTL1_CP_OFS                          (2)                             /* !< CP Offset */
#define SPI_CTL1_CP_MASK                         ((uint32_t)0x00000004U)         /* !< Controller or peripheral mode
                                                                                    select. This bit can be modified only
                                                                                    when SPI is disabled, CTL1.ENABLE=0. */
#define SPI_CTL1_CP_DISABLE                      ((uint32_t)0x00000000U)         /* !< Select Peripheral mode */
#define SPI_CTL1_CP_ENABLE                       ((uint32_t)0x00000004U)         /* !< Select Controller Mode */
/* SPI_CTL1[POD] Bits */
#define SPI_CTL1_POD_OFS                         (3)                             /* !< POD Offset */
#define SPI_CTL1_POD_MASK                        ((uint32_t)0x00000008U)         /* !< Peripheral-mode: Data output
                                                                                    disabled This bit is relevant only in
                                                                                    Peripheral mode. In
                                                                                    multiple-peripheral system
                                                                                    topologies, SPI controller can
                                                                                    broadcast a message to all
                                                                                    peripherals, while only one
                                                                                    peripheral drives the line.  POD can
                                                                                    be used by the SPI peripheral to
                                                                                    disable driving data on the line. */
#define SPI_CTL1_POD_DISABLE                     ((uint32_t)0x00000000U)         /* !< SPI can drive the MISO output in
                                                                                    peripheral mode. */
#define SPI_CTL1_POD_ENABLE                      ((uint32_t)0x00000008U)         /* !< SPI cannot drive the MISO output in
                                                                                    peripheral mode. */
/* SPI_CTL1[MSB] Bits */
#define SPI_CTL1_MSB_OFS                         (4)                             /* !< MSB Offset */
#define SPI_CTL1_MSB_MASK                        ((uint32_t)0x00000010U)         /* !< MSB first select. Controls the
                                                                                    direction of the receive and transmit
                                                                                    shift register. */
#define SPI_CTL1_MSB_DISABLE                     ((uint32_t)0x00000000U)         /* !< LSB first */
#define SPI_CTL1_MSB_ENABLE                      ((uint32_t)0x00000010U)         /* !< MSB first */
/* SPI_CTL1[PREN] Bits */
#define SPI_CTL1_PREN_OFS                        (5)                             /* !< PREN Offset */
#define SPI_CTL1_PREN_MASK                       ((uint32_t)0x00000020U)         /* !< Parity receive enable If enabled,
                                                                                    parity reception check will be done
                                                                                    for both controller and peripheral
                                                                                    modes In case of a parity miss-match
                                                                                    the parity error flag RIS.PER will be
                                                                                    set. */
#define SPI_CTL1_PREN_DISABLE                    ((uint32_t)0x00000000U)         /* !< Disable Parity receive function */
#define SPI_CTL1_PREN_ENABLE                     ((uint32_t)0x00000020U)         /* !< Enable Parity receive function */
/* SPI_CTL1[REPEATTX] Bits */
#define SPI_CTL1_REPEATTX_OFS                    (16)                            /* !< REPEATTX Offset */
#define SPI_CTL1_REPEATTX_MASK                   ((uint32_t)0x00FF0000U)         /* !< Counter to repeat last transfer 0:
                                                                                    repeat last transfer is disabled. x:
                                                                                    repeat the last transfer with the
                                                                                    given number. The transfer will be
                                                                                    started with writing a data into the
                                                                                    TX Buffer. Sending the data will be
                                                                                    repeated with the given value, so the
                                                                                    data will be transferred X+1 times in
                                                                                    total. The behavior is identical as
                                                                                    if the data would be written into the
                                                                                    TX Buffer that many times as defined
                                                                                    by the value here. It can be used to
                                                                                    clean a transfer or to pull a certain
                                                                                    amount of data by a peripheral. */
#define SPI_CTL1_REPEATTX_DISABLE                ((uint32_t)0x00000000U)         /* !< REPEATTX disable */
#define SPI_CTL1_REPEATTX_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define SPI_CTL1_REPEATTX_MAXIMUM                ((uint32_t)0x00FF0000U)         /* !< Highest possible value */
/* SPI_CTL1[PES] Bits */
#define SPI_CTL1_PES_OFS                         (6)                             /* !< PES Offset */
#define SPI_CTL1_PES_MASK                        ((uint32_t)0x00000040U)         /* !< Even Parity Select */
#define SPI_CTL1_PES_DISABLE                     ((uint32_t)0x00000000U)         /* !< Odd Parity mode */
#define SPI_CTL1_PES_ENABLE                      ((uint32_t)0x00000040U)         /* !< Even Parity mode */
/* SPI_CTL1[CDMODE] Bits */
#define SPI_CTL1_CDMODE_OFS                      (12)                            /* !< CDMODE Offset */
#define SPI_CTL1_CDMODE_MASK                     ((uint32_t)0x0000F000U)         /* !< Command/Data Mode Value  When
                                                                                    CTL1.CDENABLE is 1, CS3 line is used
                                                                                    as C/D signal to distinguish between
                                                                                    Command (C/D low) and Data (C/D high)
                                                                                    information.  When a value is written
                                                                                    into the CTL1.CDMODE bits, the C/D
                                                                                    (CS3) line will go low for the given
                                                                                    numbers of byte which are sent by the
                                                                                    SPI, starting with the next value to
                                                                                    be transmitted after which, C/D line
                                                                                    will go high automatically  0: Manual
                                                                                    mode with C/D signal as High 1-14:
                                                                                    C/D is low while this number of bytes
                                                                                    are being sent after which, this
                                                                                    field sets to 0 and C/D goes high.
                                                                                    Reading this field at any time
                                                                                    returns the remaining number of
                                                                                    command bytes. 15: Manual mode with
                                                                                    C/D signal as Low. */
#define SPI_CTL1_CDMODE_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define SPI_CTL1_CDMODE_DATA                     ((uint32_t)0x00000000U)         /* !< Manual mode: Data */
#define SPI_CTL1_CDMODE_MAXIMUM                  ((uint32_t)0x0000F000U)         /* !< Highest possible value */
#define SPI_CTL1_CDMODE_COMMAND                  ((uint32_t)0x0000F000U)         /* !< Manual mode: Command */
/* SPI_CTL1[ENABLE] Bits */
#define SPI_CTL1_ENABLE_OFS                      (0)                             /* !< ENABLE Offset */
#define SPI_CTL1_ENABLE_MASK                     ((uint32_t)0x00000001U)         /* !< SPI enable */
#define SPI_CTL1_ENABLE_DISABLE                  ((uint32_t)0x00000000U)         /* !< Disable module function */
#define SPI_CTL1_ENABLE_ENABLE                   ((uint32_t)0x00000001U)         /* !< Enable module function */
/* SPI_CTL1[RXTIMEOUT] Bits */
#define SPI_CTL1_RXTIMEOUT_OFS                   (24)                            /* !< RXTIMEOUT Offset */
#define SPI_CTL1_RXTIMEOUT_MASK                  ((uint32_t)0x3F000000U)         /* !< Receive Timeout (only for
                                                                                    Peripheral mode) Defines the number
                                                                                    of Clock Cycles before after which
                                                                                    the Receive Timeout flag RTOUT is
                                                                                    set. The time is calculated using the
                                                                                    control register for the clock
                                                                                    selection and divider in the
                                                                                    Controller mode configuration. A
                                                                                    value of 0 disables this function. */
#define SPI_CTL1_RXTIMEOUT_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define SPI_CTL1_RXTIMEOUT_MAXIMUM               ((uint32_t)0x3F000000U)         /* !< Highest possible value */
/* SPI_CTL1[CDENABLE] Bits */
#define SPI_CTL1_CDENABLE_OFS                    (11)                            /* !< CDENABLE Offset */
#define SPI_CTL1_CDENABLE_MASK                   ((uint32_t)0x00000800U)         /* !< Command/Data Mode enable */
#define SPI_CTL1_CDENABLE_DISABLE                ((uint32_t)0x00000000U)         /* !< CS3 is used for Chip Select */
#define SPI_CTL1_CDENABLE_ENABLE                 ((uint32_t)0x00000800U)         /* !< CS3 is used as CD signal */
/* SPI_CTL1[PTEN] Bits */
#define SPI_CTL1_PTEN_OFS                        (8)                             /* !< PTEN Offset */
#define SPI_CTL1_PTEN_MASK                       ((uint32_t)0x00000100U)         /* !< Parity transmit enable If enabled,
                                                                                    parity transmission will be done for
                                                                                    both controller and peripheral modes. */
#define SPI_CTL1_PTEN_DISABLE                    ((uint32_t)0x00000000U)         /* !< Parity transmission is disabled */
#define SPI_CTL1_PTEN_ENABLE                     ((uint32_t)0x00000100U)         /* !< Parity transmission is enabled */

/* SPI_CLKCTL Bits */
/* SPI_CLKCTL[SCR] Bits */
#define SPI_CLKCTL_SCR_OFS                       (0)                             /* !< SCR Offset */
#define SPI_CLKCTL_SCR_MASK                      ((uint32_t)0x000003FFU)         /* !< Serial clock divider: This is used
                                                                                    to generate the transmit and receive
                                                                                    bit rate of the SPI. The SPI bit rate
                                                                                    is (SPI's functional clock
                                                                                    frequency)/((SCR+1)*2). SCR is a
                                                                                    value from 0-1023. */
#define SPI_CLKCTL_SCR_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Smallest value */
#define SPI_CLKCTL_SCR_MAXIMUM                   ((uint32_t)0x000003FFU)         /* !< Highest possible value */
/* SPI_CLKCTL[DSAMPLE] Bits */
#define SPI_CLKCTL_DSAMPLE_OFS                   (28)                            /* !< DSAMPLE Offset */
#define SPI_CLKCTL_DSAMPLE_MASK                  ((uint32_t)0xF0000000U)         /* !< Delayed sampling value.  In
                                                                                    controller mode the data on the input
                                                                                    pin will be delayed sampled by the
                                                                                    defined clock cycles of internal
                                                                                    functional clock hence relaxing the
                                                                                    setup time of input data. This
                                                                                    setting is useful in systems where
                                                                                    the board delays and external
                                                                                    peripheral delays are more than the
                                                                                    input setup time of the controller.
                                                                                    Please refer to the datasheet for
                                                                                    values of controller input setup time
                                                                                    and assess what DSAMPLE value meets
                                                                                    the requirement of the system. Note:
                                                                                    High values of DSAMPLE can cause HOLD
                                                                                    time violations and must be factored
                                                                                    in the calculations. */
#define SPI_CLKCTL_DSAMPLE_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define SPI_CLKCTL_DSAMPLE_MAXIMUM               ((uint32_t)0xF0000000U)         /* !< Highest possible value */

/* SPI_IFLS Bits */
/* SPI_IFLS[TXIFLSEL] Bits */
#define SPI_IFLS_TXIFLSEL_OFS                    (0)                             /* !< TXIFLSEL Offset */
#define SPI_IFLS_TXIFLSEL_MASK                   ((uint32_t)0x00000007U)         /* !< SPI Transmit Interrupt FIFO Level
                                                                                    Select  The trigger points for the
                                                                                    transmit interrupt are as follows: */
#define SPI_IFLS_TXIFLSEL_LVL_OFF                ((uint32_t)0x00000000U)         /* !< Reserved */
#define SPI_IFLS_TXIFLSEL_LVL_3_4                ((uint32_t)0x00000001U)         /* !< TX FIFO <= 3/4 empty */
#define SPI_IFLS_TXIFLSEL_LVL_1_2                ((uint32_t)0x00000002U)         /* !< TX FIFO <= 1/2 empty (default) */
#define SPI_IFLS_TXIFLSEL_LVL_1_4                ((uint32_t)0x00000003U)         /* !< TX FIFO <= 1/4 empty */
#define SPI_IFLS_TXIFLSEL_LVL_RES4               ((uint32_t)0x00000004U)         /* !< Reserved */
#define SPI_IFLS_TXIFLSEL_LVL_EMPTY              ((uint32_t)0x00000005U)         /* !< TX FIFO is empty */
#define SPI_IFLS_TXIFLSEL_LVL_RES6               ((uint32_t)0x00000006U)         /* !< Reserved */
#define SPI_IFLS_TXIFLSEL_LEVEL_1                ((uint32_t)0x00000007U)         /* !< Trigger when TX FIFO has >= 1 frame
                                                                                    free Should be used with DMA */
/* SPI_IFLS[RXIFLSEL] Bits */
#define SPI_IFLS_RXIFLSEL_OFS                    (3)                             /* !< RXIFLSEL Offset */
#define SPI_IFLS_RXIFLSEL_MASK                   ((uint32_t)0x00000038U)         /* !< SPI Receive Interrupt FIFO Level
                                                                                    Select  The trigger points for the
                                                                                    receive interrupt are as follows: */
#define SPI_IFLS_RXIFLSEL_LVL_OFF                ((uint32_t)0x00000000U)         /* !< Reserved */
#define SPI_IFLS_RXIFLSEL_LVL_1_4                ((uint32_t)0x00000008U)         /* !< RX FIFO >= 1/4 full */
#define SPI_IFLS_RXIFLSEL_LVL_1_2                ((uint32_t)0x00000010U)         /* !< RX FIFO >= 1/2 full (default) */
#define SPI_IFLS_RXIFLSEL_LVL_3_4                ((uint32_t)0x00000018U)         /* !< RX FIFO >= 3/4 full */
#define SPI_IFLS_RXIFLSEL_LVL_RES4               ((uint32_t)0x00000020U)         /* !< Reserved */
#define SPI_IFLS_RXIFLSEL_LVL_FULL               ((uint32_t)0x00000028U)         /* !< RX FIFO is full */
#define SPI_IFLS_RXIFLSEL_LVL_RES6               ((uint32_t)0x00000030U)         /* !< Reserved */
#define SPI_IFLS_RXIFLSEL_LEVEL_1                ((uint32_t)0x00000038U)         /* !< Trigger when RX FIFO contains >= 1
                                                                                    frame */

/* SPI_STAT Bits */
/* SPI_STAT[TFE] Bits */
#define SPI_STAT_TFE_OFS                         (0)                             /* !< TFE Offset */
#define SPI_STAT_TFE_MASK                        ((uint32_t)0x00000001U)         /* !< Transmit FIFO empty. */
#define SPI_STAT_TFE_NOT_EMPTY                   ((uint32_t)0x00000000U)         /* !< Transmit FIFO is not empty. */
#define SPI_STAT_TFE_EMPTY                       ((uint32_t)0x00000001U)         /* !< Transmit FIFO is empty. */
/* SPI_STAT[TNF] Bits */
#define SPI_STAT_TNF_OFS                         (1)                             /* !< TNF Offset */
#define SPI_STAT_TNF_MASK                        ((uint32_t)0x00000002U)         /* !< Transmit FIFO not full */
#define SPI_STAT_TNF_FULL                        ((uint32_t)0x00000000U)         /* !< Transmit FIFO is full. */
#define SPI_STAT_TNF_NOT_FULL                    ((uint32_t)0x00000002U)         /* !< Transmit FIFO is not full. */
/* SPI_STAT[RFE] Bits */
#define SPI_STAT_RFE_OFS                         (2)                             /* !< RFE Offset */
#define SPI_STAT_RFE_MASK                        ((uint32_t)0x00000004U)         /* !< Receive FIFO empty. */
#define SPI_STAT_RFE_NOT_EMPTY                   ((uint32_t)0x00000000U)         /* !< Receive FIFO is not empty. */
#define SPI_STAT_RFE_EMPTY                       ((uint32_t)0x00000004U)         /* !< Receive FIFO is empty. */
/* SPI_STAT[RNF] Bits */
#define SPI_STAT_RNF_OFS                         (3)                             /* !< RNF Offset */
#define SPI_STAT_RNF_MASK                        ((uint32_t)0x00000008U)         /* !< Receive FIFO not full */
#define SPI_STAT_RNF_FULL                        ((uint32_t)0x00000000U)         /* !< Receive FIFO is full. */
#define SPI_STAT_RNF_NOT_FULL                    ((uint32_t)0x00000008U)         /* !< Receive FIFO is not full. */
/* SPI_STAT[BUSY] Bits */
#define SPI_STAT_BUSY_OFS                        (4)                             /* !< BUSY Offset */
#define SPI_STAT_BUSY_MASK                       ((uint32_t)0x00000010U)         /* !< Busy */
#define SPI_STAT_BUSY_IDLE                       ((uint32_t)0x00000000U)         /* !< SPI is in idle mode. */
#define SPI_STAT_BUSY_ACTIVE                     ((uint32_t)0x00000010U)         /* !< SPI is currently transmitting
                                                                                    and/or receiving data, or transmit
                                                                                    FIFO is not empty. */

/* SPI_RXDATA Bits */
/* SPI_RXDATA[DATA] Bits */
#define SPI_RXDATA_DATA_OFS                      (0)                             /* !< DATA Offset */
#define SPI_RXDATA_DATA_MASK                     ((uint32_t)0x0000FFFFU)         /* !< Received Data When PACKEN=1,two
                                                                                    entries of the FIFO are returned as a
                                                                                    32-bit value. When PACKEN=0, 1 entry
                                                                                    of FIFO is returned as 16-bit value.
                                                                                    As data values are removed by the
                                                                                    receive logic from the incoming data
                                                                                    frame, they are placed into the entry
                                                                                    in the receive FIFO, pointed to by
                                                                                    the current FIFO write pointer.
                                                                                    Received data less than 16 bits is
                                                                                    automatically right justified in the
                                                                                    receive buffer. */
#define SPI_RXDATA_DATA_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define SPI_RXDATA_DATA_MAXIMUM                  ((uint32_t)0xFFFFFFFFU)         /* !< Highest possible value */

/* SPI_TXDATA Bits */
/* SPI_TXDATA[DATA] Bits */
#define SPI_TXDATA_DATA_OFS                      (0)                             /* !< DATA Offset */
#define SPI_TXDATA_DATA_MASK                     ((uint32_t)0x0000FFFFU)         /* !< Transmit Data  When read, last
                                                                                    written value will be returned. If
                                                                                    the last write to this field was a
                                                                                    32-bit write (with PACKEN=1), 32-bits
                                                                                    will be returned and if the last
                                                                                    write was a 16-bit write (PACKEN=0),
                                                                                    those 16-bits will be returned.
                                                                                    When written, one or two FIFO entries
                                                                                    will be written depending on PACKEN
                                                                                    value. Data values are removed from
                                                                                    the transmit FIFO one value at a time
                                                                                    by the transmit logic. It is loaded
                                                                                    into the transmit serial shifter,
                                                                                    then serially shifted out onto the
                                                                                    TXD output pin at the programmed bit
                                                                                    rate.   When a data size of less than
                                                                                    16 bits is selected, the user must
                                                                                    right-justify data written to the
                                                                                    transmit FIFO. The transmit logic
                                                                                    ignores the unused bits. */
#define SPI_TXDATA_DATA_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define SPI_TXDATA_DATA_MAXIMUM                  ((uint32_t)0xFFFFFFFFU)         /* !< Highest possible value */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_spi__include */
