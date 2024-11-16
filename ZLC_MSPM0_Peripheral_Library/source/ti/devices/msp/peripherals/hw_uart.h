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

#ifndef ti_devices_msp_peripherals_hw_uart__include
#define ti_devices_msp_peripherals_hw_uart__include

/* Filename: hw_uart.h */
/* Revised: 2023-05-01 11:26:08 */
/* Revision: 04a99860157777ec8b82069fbacd72235a1fb09e */

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
* UART Registers
******************************************************************************/
#define UART_DMA_TRIG_TX_OFS                     ((uint32_t)0x00001080U)
#define UART_DMA_TRIG_RX_OFS                     ((uint32_t)0x00001050U)
#define UART_CPU_INT_OFS                         ((uint32_t)0x00001020U)
#define UART_GPRCM_OFS                           ((uint32_t)0x00000800U)


/** @addtogroup UART_DMA_TRIG_TX
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
} UART_DMA_TRIG_TX_Regs;

/*@}*/ /* end of group UART_DMA_TRIG_TX */

/** @addtogroup UART_DMA_TRIG_RX
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
} UART_DMA_TRIG_RX_Regs;

/*@}*/ /* end of group UART_DMA_TRIG_RX */

/** @addtogroup UART_CPU_INT
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
} UART_CPU_INT_Regs;

/*@}*/ /* end of group UART_CPU_INT */

/** @addtogroup UART_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00000808) Peripheral Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} UART_GPRCM_Regs;

/*@}*/ /* end of group UART_GPRCM */

/** @addtogroup UART
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  UART_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED1[506];
  __IO uint32_t CLKDIV;                            /* !< (@ 0x00001000) Clock Divider */
       uint32_t RESERVED2;
  __IO uint32_t CLKSEL;                            /* !< (@ 0x00001008) Clock Select for Ultra Low Power peripherals */
       uint32_t RESERVED3[3];
  __IO uint32_t PDBGCTL;                           /* !< (@ 0x00001018) Peripheral Debug Control */
       uint32_t RESERVED4;
  UART_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED5;
  UART_DMA_TRIG_RX_Regs  DMA_TRIG_RX;                       /* !< (@ 0x00001050) */
       uint32_t RESERVED6;
  UART_DMA_TRIG_TX_Regs  DMA_TRIG_TX;                       /* !< (@ 0x00001080) */
       uint32_t RESERVED7[13];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
  __IO uint32_t INTCTL;                            /* !< (@ 0x000010E4) Interrupt control register */
       uint32_t RESERVED8[6];
  __IO uint32_t CTL0;                              /* !< (@ 0x00001100) UART Control Register 0 */
  __IO uint32_t LCRH;                              /* !< (@ 0x00001104) UART Line Control Register */
  __I  uint32_t STAT;                              /* !< (@ 0x00001108) UART Status Register */
  __IO uint32_t IFLS;                              /* !< (@ 0x0000110C) UART Interrupt FIFO Level Select Register */
  __IO uint32_t IBRD;                              /* !< (@ 0x00001110) UART Integer Baud-Rate Divisor Register */
  __IO uint32_t FBRD;                              /* !< (@ 0x00001114) UART Fractional Baud-Rate Divisor Register */
  __IO uint32_t GFCTL;                             /* !< (@ 0x00001118) Glitch Filter Control */
       uint32_t RESERVED9;
  __IO uint32_t TXDATA;                            /* !< (@ 0x00001120) UART Transmit Data Register */
  __I  uint32_t RXDATA;                            /* !< (@ 0x00001124) UART Receive Data Register */
       uint32_t RESERVED10[2];
  __IO uint32_t LINCNT;                            /* !< (@ 0x00001130) UART LIN Mode Counter Register */
  __IO uint32_t LINCTL;                            /* !< (@ 0x00001134) UART LIN Mode Control Register */
  __IO uint32_t LINC0;                             /* !< (@ 0x00001138) UART LIN Mode Capture 0 Register */
  __IO uint32_t LINC1;                             /* !< (@ 0x0000113C) UART LIN Mode Capture 1 Register */
  __IO uint32_t IRCTL;                             /* !< (@ 0x00001140) eUSCI_Ax IrDA Control Word Register */
       uint32_t RESERVED11;
  __IO uint32_t AMASK;                             /* !< (@ 0x00001148) Self Address Mask Register */
  __IO uint32_t ADDR;                              /* !< (@ 0x0000114C) Self Address Register */
       uint32_t RESERVED12[4];
  __IO uint32_t CLKDIV2;                           /* !< (@ 0x00001160) Clock Divider */
} UART_Regs;

/*@}*/ /* end of group UART */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* UART Register Control Bits
******************************************************************************/

/* UART_DMA_TRIG_TX_IIDX Bits */
/* UART_DMA_TRIG_TX_IIDX[STAT] Bits */
#define UART_DMA_TRIG_TX_IIDX_STAT_OFS           (0)                             /* !< STAT Offset */
#define UART_DMA_TRIG_TX_IIDX_STAT_MASK          ((uint32_t)0x000000FFU)         /* !< UART Module Interrupt Vector Value.
                                                                                    This register provides the highes
                                                                                    priority interrupt index. A read
                                                                                    clears the corresponding interrupt
                                                                                    flag in UARTRIS and UARTMISC. 15h-1Fh
                                                                                    = Reserved */
#define UART_DMA_TRIG_TX_IIDX_STAT_NO_INTR       ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define UART_DMA_TRIG_TX_IIDX_STAT_TXIFG         ((uint32_t)0x0000000CU)         /* !< UART transmit interrupt; Interrupt
                                                                                    Flag: TX */

/* UART_DMA_TRIG_TX_IMASK Bits */
/* UART_DMA_TRIG_TX_IMASK[TXINT] Bits */
#define UART_DMA_TRIG_TX_IMASK_TXINT_OFS         (11)                            /* !< TXINT Offset */
#define UART_DMA_TRIG_TX_IMASK_TXINT_MASK        ((uint32_t)0x00000800U)         /* !< Enable UART Transmit Interrupt. */
#define UART_DMA_TRIG_TX_IMASK_TXINT_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_DMA_TRIG_TX_IMASK_TXINT_SET         ((uint32_t)0x00000800U)         /* !< Set Interrupt Mask */

/* UART_DMA_TRIG_TX_RIS Bits */
/* UART_DMA_TRIG_TX_RIS[TXINT] Bits */
#define UART_DMA_TRIG_TX_RIS_TXINT_OFS           (11)                            /* !< TXINT Offset */
#define UART_DMA_TRIG_TX_RIS_TXINT_MASK          ((uint32_t)0x00000800U)         /* !< UART Transmit Interrupt. */
#define UART_DMA_TRIG_TX_RIS_TXINT_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_DMA_TRIG_TX_RIS_TXINT_SET           ((uint32_t)0x00000800U)         /* !< Interrupt occured */

/* UART_DMA_TRIG_TX_MIS Bits */
/* UART_DMA_TRIG_TX_MIS[TXINT] Bits */
#define UART_DMA_TRIG_TX_MIS_TXINT_OFS           (11)                            /* !< TXINT Offset */
#define UART_DMA_TRIG_TX_MIS_TXINT_MASK          ((uint32_t)0x00000800U)         /* !< Masked UART Transmit Interrupt. */
#define UART_DMA_TRIG_TX_MIS_TXINT_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_DMA_TRIG_TX_MIS_TXINT_SET           ((uint32_t)0x00000800U)         /* !< Interrupt occured */

/* UART_DMA_TRIG_TX_ISET Bits */
/* UART_DMA_TRIG_TX_ISET[TXINT] Bits */
#define UART_DMA_TRIG_TX_ISET_TXINT_OFS          (11)                            /* !< TXINT Offset */
#define UART_DMA_TRIG_TX_ISET_TXINT_MASK         ((uint32_t)0x00000800U)         /* !< Set UART Transmit Interrupt. */
#define UART_DMA_TRIG_TX_ISET_TXINT_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_DMA_TRIG_TX_ISET_TXINT_SET          ((uint32_t)0x00000800U)         /* !< Set Interrupt */

/* UART_DMA_TRIG_TX_ICLR Bits */
/* UART_DMA_TRIG_TX_ICLR[TXINT] Bits */
#define UART_DMA_TRIG_TX_ICLR_TXINT_OFS          (11)                            /* !< TXINT Offset */
#define UART_DMA_TRIG_TX_ICLR_TXINT_MASK         ((uint32_t)0x00000800U)         /* !< Clear UART Transmit Interrupt. */
#define UART_DMA_TRIG_TX_ICLR_TXINT_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_DMA_TRIG_TX_ICLR_TXINT_CLR          ((uint32_t)0x00000800U)         /* !< Clear Interrupt */

/* UART_DMA_TRIG_RX_IIDX Bits */
/* UART_DMA_TRIG_RX_IIDX[STAT] Bits */
#define UART_DMA_TRIG_RX_IIDX_STAT_OFS           (0)                             /* !< STAT Offset */
#define UART_DMA_TRIG_RX_IIDX_STAT_MASK          ((uint32_t)0x000000FFU)         /* !< UART Module Interrupt Vector Value.
                                                                                    This register provides the highes
                                                                                    priority interrupt index. A read
                                                                                    clears the corresponding interrupt
                                                                                    flag in UARTRIS and UARTMISC. 15h-1Fh
                                                                                    = Reserved */
#define UART_DMA_TRIG_RX_IIDX_STAT_NO_INTR       ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define UART_DMA_TRIG_RX_IIDX_STAT_RTFG          ((uint32_t)0x00000001U)         /* !< UART receive time-out interrupt;
                                                                                    Interrupt Flag: RT; Interrupt
                                                                                    Priority: Highest */
#define UART_DMA_TRIG_RX_IIDX_STAT_RXIFG         ((uint32_t)0x0000000BU)         /* !< UART receive interrupt; Interrupt
                                                                                    Flag: RX */

/* UART_DMA_TRIG_RX_IMASK Bits */
/* UART_DMA_TRIG_RX_IMASK[RTOUT] Bits */
#define UART_DMA_TRIG_RX_IMASK_RTOUT_OFS         (0)                             /* !< RTOUT Offset */
#define UART_DMA_TRIG_RX_IMASK_RTOUT_MASK        ((uint32_t)0x00000001U)         /* !< Enable UARTOUT Receive Time-Out
                                                                                    Interrupt. */
#define UART_DMA_TRIG_RX_IMASK_RTOUT_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_DMA_TRIG_RX_IMASK_RTOUT_SET         ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* UART_DMA_TRIG_RX_IMASK[RXINT] Bits */
#define UART_DMA_TRIG_RX_IMASK_RXINT_OFS         (10)                            /* !< RXINT Offset */
#define UART_DMA_TRIG_RX_IMASK_RXINT_MASK        ((uint32_t)0x00000400U)         /* !< Enable UART Receive Interrupt. */
#define UART_DMA_TRIG_RX_IMASK_RXINT_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_DMA_TRIG_RX_IMASK_RXINT_SET         ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */

/* UART_DMA_TRIG_RX_RIS Bits */
/* UART_DMA_TRIG_RX_RIS[RTOUT] Bits */
#define UART_DMA_TRIG_RX_RIS_RTOUT_OFS           (0)                             /* !< RTOUT Offset */
#define UART_DMA_TRIG_RX_RIS_RTOUT_MASK          ((uint32_t)0x00000001U)         /* !< UARTOUT Receive Time-Out Interrupt. */
#define UART_DMA_TRIG_RX_RIS_RTOUT_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_DMA_TRIG_RX_RIS_RTOUT_SET           ((uint32_t)0x00000001U)         /* !< Interrupt occured */
/* UART_DMA_TRIG_RX_RIS[RXINT] Bits */
#define UART_DMA_TRIG_RX_RIS_RXINT_OFS           (10)                            /* !< RXINT Offset */
#define UART_DMA_TRIG_RX_RIS_RXINT_MASK          ((uint32_t)0x00000400U)         /* !< UART Receive Interrupt. */
#define UART_DMA_TRIG_RX_RIS_RXINT_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_DMA_TRIG_RX_RIS_RXINT_SET           ((uint32_t)0x00000400U)         /* !< Interrupt occured */

/* UART_DMA_TRIG_RX_MIS Bits */
/* UART_DMA_TRIG_RX_MIS[RTOUT] Bits */
#define UART_DMA_TRIG_RX_MIS_RTOUT_OFS           (0)                             /* !< RTOUT Offset */
#define UART_DMA_TRIG_RX_MIS_RTOUT_MASK          ((uint32_t)0x00000001U)         /* !< Masked UARTOUT Receive Time-Out
                                                                                    Interrupt. */
#define UART_DMA_TRIG_RX_MIS_RTOUT_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_DMA_TRIG_RX_MIS_RTOUT_SET           ((uint32_t)0x00000001U)         /* !< Interrupt occured */
/* UART_DMA_TRIG_RX_MIS[RXINT] Bits */
#define UART_DMA_TRIG_RX_MIS_RXINT_OFS           (10)                            /* !< RXINT Offset */
#define UART_DMA_TRIG_RX_MIS_RXINT_MASK          ((uint32_t)0x00000400U)         /* !< Masked UART Receive Interrupt. */
#define UART_DMA_TRIG_RX_MIS_RXINT_CLR           ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_DMA_TRIG_RX_MIS_RXINT_SET           ((uint32_t)0x00000400U)         /* !< Interrupt occured */

/* UART_DMA_TRIG_RX_ISET Bits */
/* UART_DMA_TRIG_RX_ISET[RTOUT] Bits */
#define UART_DMA_TRIG_RX_ISET_RTOUT_OFS          (0)                             /* !< RTOUT Offset */
#define UART_DMA_TRIG_RX_ISET_RTOUT_MASK         ((uint32_t)0x00000001U)         /* !< Set UARTOUT Receive Time-Out
                                                                                    Interrupt. */
#define UART_DMA_TRIG_RX_ISET_RTOUT_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_DMA_TRIG_RX_ISET_RTOUT_SET          ((uint32_t)0x00000001U)         /* !< Set Interrupt */
/* UART_DMA_TRIG_RX_ISET[RXINT] Bits */
#define UART_DMA_TRIG_RX_ISET_RXINT_OFS          (10)                            /* !< RXINT Offset */
#define UART_DMA_TRIG_RX_ISET_RXINT_MASK         ((uint32_t)0x00000400U)         /* !< Set UART Receive Interrupt. */
#define UART_DMA_TRIG_RX_ISET_RXINT_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_DMA_TRIG_RX_ISET_RXINT_SET          ((uint32_t)0x00000400U)         /* !< Set Interrupt */

/* UART_DMA_TRIG_RX_ICLR Bits */
/* UART_DMA_TRIG_RX_ICLR[RTOUT] Bits */
#define UART_DMA_TRIG_RX_ICLR_RTOUT_OFS          (0)                             /* !< RTOUT Offset */
#define UART_DMA_TRIG_RX_ICLR_RTOUT_MASK         ((uint32_t)0x00000001U)         /* !< Clear UARTOUT Receive Time-Out
                                                                                    Interrupt. */
#define UART_DMA_TRIG_RX_ICLR_RTOUT_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_DMA_TRIG_RX_ICLR_RTOUT_CLR          ((uint32_t)0x00000001U)         /* !< Clear Interrupt */
/* UART_DMA_TRIG_RX_ICLR[RXINT] Bits */
#define UART_DMA_TRIG_RX_ICLR_RXINT_OFS          (10)                            /* !< RXINT Offset */
#define UART_DMA_TRIG_RX_ICLR_RXINT_MASK         ((uint32_t)0x00000400U)         /* !< Clear UART Receive Interrupt. */
#define UART_DMA_TRIG_RX_ICLR_RXINT_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_DMA_TRIG_RX_ICLR_RXINT_CLR          ((uint32_t)0x00000400U)         /* !< Clear Interrupt */

/* UART_CPU_INT_IIDX Bits */
/* UART_CPU_INT_IIDX[STAT] Bits */
#define UART_CPU_INT_IIDX_STAT_OFS               (0)                             /* !< STAT Offset */
#define UART_CPU_INT_IIDX_STAT_MASK              ((uint32_t)0x000000FFU)         /* !< UART Module Interrupt Vector Value.
                                                                                    This register provides the highes
                                                                                    priority interrupt index. A read
                                                                                    clears the corresponding interrupt
                                                                                    flag in RIS and MIS registers.
                                                                                    15h-1Fh = Reserved */
#define UART_CPU_INT_IIDX_STAT_NO_INTR           ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define UART_CPU_INT_IIDX_STAT_RTFG              ((uint32_t)0x00000001U)         /* !< UART receive time-out interrupt;
                                                                                    Interrupt Flag: RT; Interrupt
                                                                                    Priority: Highest */
#define UART_CPU_INT_IIDX_STAT_FEFG              ((uint32_t)0x00000002U)         /* !< UART framing error interrupt;
                                                                                    Interrupt Flag: FE */
#define UART_CPU_INT_IIDX_STAT_PEFG              ((uint32_t)0x00000003U)         /* !< UART parity error interrupt;
                                                                                    Interrupt Flag: PE */
#define UART_CPU_INT_IIDX_STAT_BEFG              ((uint32_t)0x00000004U)         /* !< UART break error interrupt;
                                                                                    Interrupt Flag: BE */
#define UART_CPU_INT_IIDX_STAT_OEFG              ((uint32_t)0x00000005U)         /* !< UART receive overrun error
                                                                                    interrupt; Interrupt Flag: OE */
#define UART_CPU_INT_IIDX_STAT_RXNE              ((uint32_t)0x00000006U)         /* !< Negative edge on UARTxRXD
                                                                                    interrupt; Interrupt Flag: RXNE */
#define UART_CPU_INT_IIDX_STAT_RXPE              ((uint32_t)0x00000007U)         /* !< Positive edge on UARTxRXD
                                                                                    interrupt; Interrupt Flag: RXPE */
#define UART_CPU_INT_IIDX_STAT_LINC0             ((uint32_t)0x00000008U)         /* !< LIN capture 0 / match interrupt;
                                                                                    Interrupt Flag: LINC0 */
#define UART_CPU_INT_IIDX_STAT_LINC1             ((uint32_t)0x00000009U)         /* !< LIN capture 1 interrupt; Interrupt
                                                                                    Flag: LINC1 */
#define UART_CPU_INT_IIDX_STAT_LINOVF            ((uint32_t)0x0000000AU)         /* !< LIN hardware counter overflow
                                                                                    interrupt; Interrupt Flag: LINOVF */
#define UART_CPU_INT_IIDX_STAT_RXIFG             ((uint32_t)0x0000000BU)         /* !< UART receive interrupt; Interrupt
                                                                                    Flag: RX */
#define UART_CPU_INT_IIDX_STAT_TXIFG             ((uint32_t)0x0000000CU)         /* !< UART transmit interrupt; Interrupt
                                                                                    Flag: TX */
#define UART_CPU_INT_IIDX_STAT_EOT               ((uint32_t)0x0000000DU)         /* !< UART end of transmission interrupt
                                                                                    (transmit serializer empty);
                                                                                    Interrupt Flag: EOT */
#define UART_CPU_INT_IIDX_STAT_MODE_9B           ((uint32_t)0x0000000EU)         /* !< 9-bit mode address match interrupt;
                                                                                    Interrupt Flag: MODE_9B */
#define UART_CPU_INT_IIDX_STAT_CTS               ((uint32_t)0x0000000FU)         /* !< UART Clear to Send Modem interrupt;
                                                                                    Interrupt Flag: CTS */
#define UART_CPU_INT_IIDX_STAT_DMA_DONE_RX       ((uint32_t)0x00000010U)         /* !< DMA DONE on RX */
#define UART_CPU_INT_IIDX_STAT_DMA_DONE_TX       ((uint32_t)0x00000011U)         /* !< DMA DONE on TX */
#define UART_CPU_INT_IIDX_STAT_NERR_EVT          ((uint32_t)0x00000012U)         /* !< Noise Error Event */

/* UART_CPU_INT_IMASK Bits */
/* UART_CPU_INT_IMASK[FRMERR] Bits */
#define UART_CPU_INT_IMASK_FRMERR_OFS            (1)                             /* !< FRMERR Offset */
#define UART_CPU_INT_IMASK_FRMERR_MASK           ((uint32_t)0x00000002U)         /* !< Enable UART Framing Error
                                                                                    Interrupt. */
#define UART_CPU_INT_IMASK_FRMERR_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_FRMERR_SET            ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[PARERR] Bits */
#define UART_CPU_INT_IMASK_PARERR_OFS            (2)                             /* !< PARERR Offset */
#define UART_CPU_INT_IMASK_PARERR_MASK           ((uint32_t)0x00000004U)         /* !< Enable UART Parity Error Interrupt. */
#define UART_CPU_INT_IMASK_PARERR_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_PARERR_SET            ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[BRKERR] Bits */
#define UART_CPU_INT_IMASK_BRKERR_OFS            (3)                             /* !< BRKERR Offset */
#define UART_CPU_INT_IMASK_BRKERR_MASK           ((uint32_t)0x00000008U)         /* !< Enable UART Break Error Interrupt. */
#define UART_CPU_INT_IMASK_BRKERR_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_BRKERR_SET            ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[OVRERR] Bits */
#define UART_CPU_INT_IMASK_OVRERR_OFS            (4)                             /* !< OVRERR Offset */
#define UART_CPU_INT_IMASK_OVRERR_MASK           ((uint32_t)0x00000010U)         /* !< Enable UART Receive Overrun Error
                                                                                    Interrupt. */
#define UART_CPU_INT_IMASK_OVRERR_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_OVRERR_SET            ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[RXNE] Bits */
#define UART_CPU_INT_IMASK_RXNE_OFS              (5)                             /* !< RXNE Offset */
#define UART_CPU_INT_IMASK_RXNE_MASK             ((uint32_t)0x00000020U)         /* !< Enable Negative Edge on UARTxRXD
                                                                                    Interrupt. */
#define UART_CPU_INT_IMASK_RXNE_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_RXNE_SET              ((uint32_t)0x00000020U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[RXPE] Bits */
#define UART_CPU_INT_IMASK_RXPE_OFS              (6)                             /* !< RXPE Offset */
#define UART_CPU_INT_IMASK_RXPE_MASK             ((uint32_t)0x00000040U)         /* !< Enable Positive Edge on UARTxRXD
                                                                                    Interrupt. */
#define UART_CPU_INT_IMASK_RXPE_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_RXPE_SET              ((uint32_t)0x00000040U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[LINOVF] Bits */
#define UART_CPU_INT_IMASK_LINOVF_OFS            (9)                             /* !< LINOVF Offset */
#define UART_CPU_INT_IMASK_LINOVF_MASK           ((uint32_t)0x00000200U)         /* !< Enable LIN Hardware Counter
                                                                                    Overflow Interrupt. */
#define UART_CPU_INT_IMASK_LINOVF_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_LINOVF_SET            ((uint32_t)0x00000200U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[RXINT] Bits */
#define UART_CPU_INT_IMASK_RXINT_OFS             (10)                            /* !< RXINT Offset */
#define UART_CPU_INT_IMASK_RXINT_MASK            ((uint32_t)0x00000400U)         /* !< Enable UART Receive Interrupt. */
#define UART_CPU_INT_IMASK_RXINT_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_RXINT_SET             ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[TXINT] Bits */
#define UART_CPU_INT_IMASK_TXINT_OFS             (11)                            /* !< TXINT Offset */
#define UART_CPU_INT_IMASK_TXINT_MASK            ((uint32_t)0x00000800U)         /* !< Enable UART Transmit Interrupt. */
#define UART_CPU_INT_IMASK_TXINT_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_TXINT_SET             ((uint32_t)0x00000800U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[EOT] Bits */
#define UART_CPU_INT_IMASK_EOT_OFS               (12)                            /* !< EOT Offset */
#define UART_CPU_INT_IMASK_EOT_MASK              ((uint32_t)0x00001000U)         /* !< Enable UART End of Transmission
                                                                                    Interrupt Indicates that the last bit
                                                                                    of all transmitted data and flags has
                                                                                    left the serializer and without any
                                                                                    further Data in the TX Fifo or
                                                                                    Buffer. */
#define UART_CPU_INT_IMASK_EOT_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_EOT_SET               ((uint32_t)0x00001000U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[ADDR_MATCH] Bits */
#define UART_CPU_INT_IMASK_ADDR_MATCH_OFS        (13)                            /* !< ADDR_MATCH Offset */
#define UART_CPU_INT_IMASK_ADDR_MATCH_MASK       ((uint32_t)0x00002000U)         /* !< Enable Address Match Interrupt. */
#define UART_CPU_INT_IMASK_ADDR_MATCH_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_ADDR_MATCH_SET        ((uint32_t)0x00002000U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[CTS] Bits */
#define UART_CPU_INT_IMASK_CTS_OFS               (14)                            /* !< CTS Offset */
#define UART_CPU_INT_IMASK_CTS_MASK              ((uint32_t)0x00004000U)         /* !< Enable UART Clear to Send Modem
                                                                                    Interrupt. */
#define UART_CPU_INT_IMASK_CTS_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define UART_CPU_INT_IMASK_CTS_SET               ((uint32_t)0x00004000U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[DMA_DONE_RX] Bits */
#define UART_CPU_INT_IMASK_DMA_DONE_RX_OFS       (15)                            /* !< DMA_DONE_RX Offset */
#define UART_CPU_INT_IMASK_DMA_DONE_RX_MASK      ((uint32_t)0x00008000U)         /* !< Enable DMA Done on RX Event Channel
                                                                                    Interrupt */
#define UART_CPU_INT_IMASK_DMA_DONE_RX_CLR       ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define UART_CPU_INT_IMASK_DMA_DONE_RX_SET       ((uint32_t)0x00008000U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[DMA_DONE_TX] Bits */
#define UART_CPU_INT_IMASK_DMA_DONE_TX_OFS       (16)                            /* !< DMA_DONE_TX Offset */
#define UART_CPU_INT_IMASK_DMA_DONE_TX_MASK      ((uint32_t)0x00010000U)         /* !< Enable DMA Done on TX Event Channel
                                                                                    Interrupt */
#define UART_CPU_INT_IMASK_DMA_DONE_TX_CLR       ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define UART_CPU_INT_IMASK_DMA_DONE_TX_SET       ((uint32_t)0x00010000U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[RTOUT] Bits */
#define UART_CPU_INT_IMASK_RTOUT_OFS             (0)                             /* !< RTOUT Offset */
#define UART_CPU_INT_IMASK_RTOUT_MASK            ((uint32_t)0x00000001U)         /* !< Enable UARTOUT Receive Time-Out
                                                                                    Interrupt. */
#define UART_CPU_INT_IMASK_RTOUT_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_RTOUT_SET             ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[LINC0] Bits */
#define UART_CPU_INT_IMASK_LINC0_OFS             (7)                             /* !< LINC0 Offset */
#define UART_CPU_INT_IMASK_LINC0_MASK            ((uint32_t)0x00000080U)         /* !< Enable LIN Capture 0 / Match
                                                                                    Interrupt . */
#define UART_CPU_INT_IMASK_LINC0_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_LINC0_SET             ((uint32_t)0x00000080U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[LINC1] Bits */
#define UART_CPU_INT_IMASK_LINC1_OFS             (8)                             /* !< LINC1 Offset */
#define UART_CPU_INT_IMASK_LINC1_MASK            ((uint32_t)0x00000100U)         /* !< Enable LIN Capture 1 Interrupt. */
#define UART_CPU_INT_IMASK_LINC1_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_LINC1_SET             ((uint32_t)0x00000100U)         /* !< Set Interrupt Mask */
/* UART_CPU_INT_IMASK[NERR] Bits */
#define UART_CPU_INT_IMASK_NERR_OFS              (17)                            /* !< NERR Offset */
#define UART_CPU_INT_IMASK_NERR_MASK             ((uint32_t)0x00020000U)         /* !< Noise Error on triple voting.
                                                                                    Asserted when the 3 samples of
                                                                                    majority voting are not equal */
#define UART_CPU_INT_IMASK_NERR_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define UART_CPU_INT_IMASK_NERR_SET              ((uint32_t)0x00020000U)         /* !< Set Interrupt Mask */

/* UART_CPU_INT_RIS Bits */
/* UART_CPU_INT_RIS[RTOUT] Bits */
#define UART_CPU_INT_RIS_RTOUT_OFS               (0)                             /* !< RTOUT Offset */
#define UART_CPU_INT_RIS_RTOUT_MASK              ((uint32_t)0x00000001U)         /* !< UARTOUT Receive Time-Out Interrupt. */
#define UART_CPU_INT_RIS_RTOUT_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_RTOUT_SET               ((uint32_t)0x00000001U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[FRMERR] Bits */
#define UART_CPU_INT_RIS_FRMERR_OFS              (1)                             /* !< FRMERR Offset */
#define UART_CPU_INT_RIS_FRMERR_MASK             ((uint32_t)0x00000002U)         /* !< UART Framing Error Interrupt. */
#define UART_CPU_INT_RIS_FRMERR_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_FRMERR_SET              ((uint32_t)0x00000002U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[PARERR] Bits */
#define UART_CPU_INT_RIS_PARERR_OFS              (2)                             /* !< PARERR Offset */
#define UART_CPU_INT_RIS_PARERR_MASK             ((uint32_t)0x00000004U)         /* !< UART Parity Error Interrupt. */
#define UART_CPU_INT_RIS_PARERR_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_PARERR_SET              ((uint32_t)0x00000004U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[BRKERR] Bits */
#define UART_CPU_INT_RIS_BRKERR_OFS              (3)                             /* !< BRKERR Offset */
#define UART_CPU_INT_RIS_BRKERR_MASK             ((uint32_t)0x00000008U)         /* !< UART Break Error Interrupt. */
#define UART_CPU_INT_RIS_BRKERR_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_BRKERR_SET              ((uint32_t)0x00000008U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[OVRERR] Bits */
#define UART_CPU_INT_RIS_OVRERR_OFS              (4)                             /* !< OVRERR Offset */
#define UART_CPU_INT_RIS_OVRERR_MASK             ((uint32_t)0x00000010U)         /* !< UART Receive Overrun Error
                                                                                    Interrupt. */
#define UART_CPU_INT_RIS_OVRERR_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_OVRERR_SET              ((uint32_t)0x00000010U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[RXNE] Bits */
#define UART_CPU_INT_RIS_RXNE_OFS                (5)                             /* !< RXNE Offset */
#define UART_CPU_INT_RIS_RXNE_MASK               ((uint32_t)0x00000020U)         /* !< Negative Edge on UARTxRXD
                                                                                    Interrupt. */
#define UART_CPU_INT_RIS_RXNE_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_RXNE_SET                ((uint32_t)0x00000020U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[RXPE] Bits */
#define UART_CPU_INT_RIS_RXPE_OFS                (6)                             /* !< RXPE Offset */
#define UART_CPU_INT_RIS_RXPE_MASK               ((uint32_t)0x00000040U)         /* !< Positive Edge on UARTxRXD
                                                                                    Interrupt. */
#define UART_CPU_INT_RIS_RXPE_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_RXPE_SET                ((uint32_t)0x00000040U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[LINC0] Bits */
#define UART_CPU_INT_RIS_LINC0_OFS               (7)                             /* !< LINC0 Offset */
#define UART_CPU_INT_RIS_LINC0_MASK              ((uint32_t)0x00000080U)         /* !< LIN Capture 0 / Match Interrupt . */
#define UART_CPU_INT_RIS_LINC0_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_LINC0_SET               ((uint32_t)0x00000080U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[LINC1] Bits */
#define UART_CPU_INT_RIS_LINC1_OFS               (8)                             /* !< LINC1 Offset */
#define UART_CPU_INT_RIS_LINC1_MASK              ((uint32_t)0x00000100U)         /* !< LIN Capture 1 Interrupt. */
#define UART_CPU_INT_RIS_LINC1_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_LINC1_SET               ((uint32_t)0x00000100U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[LINOVF] Bits */
#define UART_CPU_INT_RIS_LINOVF_OFS              (9)                             /* !< LINOVF Offset */
#define UART_CPU_INT_RIS_LINOVF_MASK             ((uint32_t)0x00000200U)         /* !< LIN Hardware Counter Overflow
                                                                                    Interrupt. */
#define UART_CPU_INT_RIS_LINOVF_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_LINOVF_SET              ((uint32_t)0x00000200U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[RXINT] Bits */
#define UART_CPU_INT_RIS_RXINT_OFS               (10)                            /* !< RXINT Offset */
#define UART_CPU_INT_RIS_RXINT_MASK              ((uint32_t)0x00000400U)         /* !< UART Receive Interrupt. */
#define UART_CPU_INT_RIS_RXINT_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_RXINT_SET               ((uint32_t)0x00000400U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[TXINT] Bits */
#define UART_CPU_INT_RIS_TXINT_OFS               (11)                            /* !< TXINT Offset */
#define UART_CPU_INT_RIS_TXINT_MASK              ((uint32_t)0x00000800U)         /* !< UART Transmit Interrupt. */
#define UART_CPU_INT_RIS_TXINT_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_TXINT_SET               ((uint32_t)0x00000800U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[EOT] Bits */
#define UART_CPU_INT_RIS_EOT_OFS                 (12)                            /* !< EOT Offset */
#define UART_CPU_INT_RIS_EOT_MASK                ((uint32_t)0x00001000U)         /* !< UART End of Transmission Interrupt
                                                                                    Indicates that the last bit of all
                                                                                    transmitted data and flags has left
                                                                                    the serializer and without any
                                                                                    further Data in the TX Fifo or
                                                                                    Buffer. */
#define UART_CPU_INT_RIS_EOT_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_EOT_SET                 ((uint32_t)0x00001000U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[ADDR_MATCH] Bits */
#define UART_CPU_INT_RIS_ADDR_MATCH_OFS          (13)                            /* !< ADDR_MATCH Offset */
#define UART_CPU_INT_RIS_ADDR_MATCH_MASK         ((uint32_t)0x00002000U)         /* !< Address Match Interrupt. */
#define UART_CPU_INT_RIS_ADDR_MATCH_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_ADDR_MATCH_SET          ((uint32_t)0x00002000U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[CTS] Bits */
#define UART_CPU_INT_RIS_CTS_OFS                 (14)                            /* !< CTS Offset */
#define UART_CPU_INT_RIS_CTS_MASK                ((uint32_t)0x00004000U)         /* !< UART Clear to Send Modem Interrupt. */
#define UART_CPU_INT_RIS_CTS_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define UART_CPU_INT_RIS_CTS_SET                 ((uint32_t)0x00004000U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[DMA_DONE_RX] Bits */
#define UART_CPU_INT_RIS_DMA_DONE_RX_OFS         (15)                            /* !< DMA_DONE_RX Offset */
#define UART_CPU_INT_RIS_DMA_DONE_RX_MASK        ((uint32_t)0x00008000U)         /* !< DMA Done on RX Event Channel
                                                                                    Interrupt */
#define UART_CPU_INT_RIS_DMA_DONE_RX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define UART_CPU_INT_RIS_DMA_DONE_RX_SET         ((uint32_t)0x00008000U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[DMA_DONE_TX] Bits */
#define UART_CPU_INT_RIS_DMA_DONE_TX_OFS         (16)                            /* !< DMA_DONE_TX Offset */
#define UART_CPU_INT_RIS_DMA_DONE_TX_MASK        ((uint32_t)0x00010000U)         /* !< DMA Done on TX Event Channel
                                                                                    Interrupt */
#define UART_CPU_INT_RIS_DMA_DONE_TX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define UART_CPU_INT_RIS_DMA_DONE_TX_SET         ((uint32_t)0x00010000U)         /* !< Interrupt occured */
/* UART_CPU_INT_RIS[NERR] Bits */
#define UART_CPU_INT_RIS_NERR_OFS                (17)                            /* !< NERR Offset */
#define UART_CPU_INT_RIS_NERR_MASK               ((uint32_t)0x00020000U)         /* !< Noise Error on triple voting.
                                                                                    Asserted when the 3 samples of
                                                                                    majority voting are not equal */
#define UART_CPU_INT_RIS_NERR_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_RIS_NERR_SET                ((uint32_t)0x00020000U)         /* !< Interrupt occured */

/* UART_CPU_INT_MIS Bits */
/* UART_CPU_INT_MIS[RTOUT] Bits */
#define UART_CPU_INT_MIS_RTOUT_OFS               (0)                             /* !< RTOUT Offset */
#define UART_CPU_INT_MIS_RTOUT_MASK              ((uint32_t)0x00000001U)         /* !< Masked UARTOUT Receive Time-Out
                                                                                    Interrupt. */
#define UART_CPU_INT_MIS_RTOUT_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_RTOUT_SET               ((uint32_t)0x00000001U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[FRMERR] Bits */
#define UART_CPU_INT_MIS_FRMERR_OFS              (1)                             /* !< FRMERR Offset */
#define UART_CPU_INT_MIS_FRMERR_MASK             ((uint32_t)0x00000002U)         /* !< Masked UART Framing Error
                                                                                    Interrupt. */
#define UART_CPU_INT_MIS_FRMERR_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_FRMERR_SET              ((uint32_t)0x00000002U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[PARERR] Bits */
#define UART_CPU_INT_MIS_PARERR_OFS              (2)                             /* !< PARERR Offset */
#define UART_CPU_INT_MIS_PARERR_MASK             ((uint32_t)0x00000004U)         /* !< Masked UART Parity Error Interrupt. */
#define UART_CPU_INT_MIS_PARERR_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_PARERR_SET              ((uint32_t)0x00000004U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[BRKERR] Bits */
#define UART_CPU_INT_MIS_BRKERR_OFS              (3)                             /* !< BRKERR Offset */
#define UART_CPU_INT_MIS_BRKERR_MASK             ((uint32_t)0x00000008U)         /* !< Masked UART Break Error Interrupt. */
#define UART_CPU_INT_MIS_BRKERR_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_BRKERR_SET              ((uint32_t)0x00000008U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[OVRERR] Bits */
#define UART_CPU_INT_MIS_OVRERR_OFS              (4)                             /* !< OVRERR Offset */
#define UART_CPU_INT_MIS_OVRERR_MASK             ((uint32_t)0x00000010U)         /* !< Masked UART Receive Overrun Error
                                                                                    Interrupt. */
#define UART_CPU_INT_MIS_OVRERR_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_OVRERR_SET              ((uint32_t)0x00000010U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[RXNE] Bits */
#define UART_CPU_INT_MIS_RXNE_OFS                (5)                             /* !< RXNE Offset */
#define UART_CPU_INT_MIS_RXNE_MASK               ((uint32_t)0x00000020U)         /* !< Masked Negative Edge on UARTxRXD
                                                                                    Interrupt. */
#define UART_CPU_INT_MIS_RXNE_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_RXNE_SET                ((uint32_t)0x00000020U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[RXPE] Bits */
#define UART_CPU_INT_MIS_RXPE_OFS                (6)                             /* !< RXPE Offset */
#define UART_CPU_INT_MIS_RXPE_MASK               ((uint32_t)0x00000040U)         /* !< Masked Positive Edge on UARTxRXD
                                                                                    Interrupt. */
#define UART_CPU_INT_MIS_RXPE_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_RXPE_SET                ((uint32_t)0x00000040U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[LINC0] Bits */
#define UART_CPU_INT_MIS_LINC0_OFS               (7)                             /* !< LINC0 Offset */
#define UART_CPU_INT_MIS_LINC0_MASK              ((uint32_t)0x00000080U)         /* !< Masked LIN Capture 0 / Match
                                                                                    Interrupt . */
#define UART_CPU_INT_MIS_LINC0_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_LINC0_SET               ((uint32_t)0x00000080U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[LINC1] Bits */
#define UART_CPU_INT_MIS_LINC1_OFS               (8)                             /* !< LINC1 Offset */
#define UART_CPU_INT_MIS_LINC1_MASK              ((uint32_t)0x00000100U)         /* !< Masked LIN Capture 1 Interrupt. */
#define UART_CPU_INT_MIS_LINC1_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_LINC1_SET               ((uint32_t)0x00000100U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[LINOVF] Bits */
#define UART_CPU_INT_MIS_LINOVF_OFS              (9)                             /* !< LINOVF Offset */
#define UART_CPU_INT_MIS_LINOVF_MASK             ((uint32_t)0x00000200U)         /* !< Masked LIN Hardware Counter
                                                                                    Overflow Interrupt. */
#define UART_CPU_INT_MIS_LINOVF_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_LINOVF_SET              ((uint32_t)0x00000200U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[RXINT] Bits */
#define UART_CPU_INT_MIS_RXINT_OFS               (10)                            /* !< RXINT Offset */
#define UART_CPU_INT_MIS_RXINT_MASK              ((uint32_t)0x00000400U)         /* !< Masked UART Receive Interrupt. */
#define UART_CPU_INT_MIS_RXINT_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_RXINT_SET               ((uint32_t)0x00000400U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[TXINT] Bits */
#define UART_CPU_INT_MIS_TXINT_OFS               (11)                            /* !< TXINT Offset */
#define UART_CPU_INT_MIS_TXINT_MASK              ((uint32_t)0x00000800U)         /* !< Masked UART Transmit Interrupt. */
#define UART_CPU_INT_MIS_TXINT_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_TXINT_SET               ((uint32_t)0x00000800U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[EOT] Bits */
#define UART_CPU_INT_MIS_EOT_OFS                 (12)                            /* !< EOT Offset */
#define UART_CPU_INT_MIS_EOT_MASK                ((uint32_t)0x00001000U)         /* !< UART End of Transmission Interrupt
                                                                                    Indicates that the last bit of all
                                                                                    transmitted data and flags has left
                                                                                    the serializer and without any
                                                                                    further Data in the TX Fifo or
                                                                                    Buffer. */
#define UART_CPU_INT_MIS_EOT_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_EOT_SET                 ((uint32_t)0x00001000U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[ADDR_MATCH] Bits */
#define UART_CPU_INT_MIS_ADDR_MATCH_OFS          (13)                            /* !< ADDR_MATCH Offset */
#define UART_CPU_INT_MIS_ADDR_MATCH_MASK         ((uint32_t)0x00002000U)         /* !< Masked Address Match Interrupt. */
#define UART_CPU_INT_MIS_ADDR_MATCH_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_ADDR_MATCH_SET          ((uint32_t)0x00002000U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[CTS] Bits */
#define UART_CPU_INT_MIS_CTS_OFS                 (14)                            /* !< CTS Offset */
#define UART_CPU_INT_MIS_CTS_MASK                ((uint32_t)0x00004000U)         /* !< Masked UART Clear to Send Modem
                                                                                    Interrupt. */
#define UART_CPU_INT_MIS_CTS_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_CTS_SET                 ((uint32_t)0x00004000U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[DMA_DONE_RX] Bits */
#define UART_CPU_INT_MIS_DMA_DONE_RX_OFS         (15)                            /* !< DMA_DONE_RX Offset */
#define UART_CPU_INT_MIS_DMA_DONE_RX_MASK        ((uint32_t)0x00008000U)         /* !< Masked DMA Done on RX Event Channel
                                                                                    Interrupt */
#define UART_CPU_INT_MIS_DMA_DONE_RX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_DMA_DONE_RX_SET         ((uint32_t)0x00008000U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[DMA_DONE_TX] Bits */
#define UART_CPU_INT_MIS_DMA_DONE_TX_OFS         (16)                            /* !< DMA_DONE_TX Offset */
#define UART_CPU_INT_MIS_DMA_DONE_TX_MASK        ((uint32_t)0x00010000U)         /* !< Masked DMA Done on TX Event Channel
                                                                                    Interrupt */
#define UART_CPU_INT_MIS_DMA_DONE_TX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_DMA_DONE_TX_SET         ((uint32_t)0x00010000U)         /* !< Interrupt occured */
/* UART_CPU_INT_MIS[NERR] Bits */
#define UART_CPU_INT_MIS_NERR_OFS                (17)                            /* !< NERR Offset */
#define UART_CPU_INT_MIS_NERR_MASK               ((uint32_t)0x00020000U)         /* !< Noise Error on triple voting.
                                                                                    Asserted when the 3 samples of
                                                                                    majority voting are not equal */
#define UART_CPU_INT_MIS_NERR_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define UART_CPU_INT_MIS_NERR_SET                ((uint32_t)0x00020000U)         /* !< Interrupt occured */

/* UART_CPU_INT_ISET Bits */
/* UART_CPU_INT_ISET[FRMERR] Bits */
#define UART_CPU_INT_ISET_FRMERR_OFS             (1)                             /* !< FRMERR Offset */
#define UART_CPU_INT_ISET_FRMERR_MASK            ((uint32_t)0x00000002U)         /* !< Set UART Framing Error Interrupt. */
#define UART_CPU_INT_ISET_FRMERR_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_FRMERR_SET             ((uint32_t)0x00000002U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[PARERR] Bits */
#define UART_CPU_INT_ISET_PARERR_OFS             (2)                             /* !< PARERR Offset */
#define UART_CPU_INT_ISET_PARERR_MASK            ((uint32_t)0x00000004U)         /* !< Set UART Parity Error Interrupt. */
#define UART_CPU_INT_ISET_PARERR_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_PARERR_SET             ((uint32_t)0x00000004U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[BRKERR] Bits */
#define UART_CPU_INT_ISET_BRKERR_OFS             (3)                             /* !< BRKERR Offset */
#define UART_CPU_INT_ISET_BRKERR_MASK            ((uint32_t)0x00000008U)         /* !< Set UART Break Error Interrupt. */
#define UART_CPU_INT_ISET_BRKERR_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_BRKERR_SET             ((uint32_t)0x00000008U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[OVRERR] Bits */
#define UART_CPU_INT_ISET_OVRERR_OFS             (4)                             /* !< OVRERR Offset */
#define UART_CPU_INT_ISET_OVRERR_MASK            ((uint32_t)0x00000010U)         /* !< Set  UART Receive Overrun Error
                                                                                    Interrupt. */
#define UART_CPU_INT_ISET_OVRERR_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_OVRERR_SET             ((uint32_t)0x00000010U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[RXNE] Bits */
#define UART_CPU_INT_ISET_RXNE_OFS               (5)                             /* !< RXNE Offset */
#define UART_CPU_INT_ISET_RXNE_MASK              ((uint32_t)0x00000020U)         /* !< Set Negative Edge on UARTxRXD
                                                                                    Interrupt. */
#define UART_CPU_INT_ISET_RXNE_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_RXNE_SET               ((uint32_t)0x00000020U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[RXPE] Bits */
#define UART_CPU_INT_ISET_RXPE_OFS               (6)                             /* !< RXPE Offset */
#define UART_CPU_INT_ISET_RXPE_MASK              ((uint32_t)0x00000040U)         /* !< Set Positive Edge on UARTxRXD
                                                                                    Interrupt. */
#define UART_CPU_INT_ISET_RXPE_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_RXPE_SET               ((uint32_t)0x00000040U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[LINC0] Bits */
#define UART_CPU_INT_ISET_LINC0_OFS              (7)                             /* !< LINC0 Offset */
#define UART_CPU_INT_ISET_LINC0_MASK             ((uint32_t)0x00000080U)         /* !< Set LIN Capture 0 / Match Interrupt
                                                                                    . */
#define UART_CPU_INT_ISET_LINC0_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_LINC0_SET              ((uint32_t)0x00000080U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[LINC1] Bits */
#define UART_CPU_INT_ISET_LINC1_OFS              (8)                             /* !< LINC1 Offset */
#define UART_CPU_INT_ISET_LINC1_MASK             ((uint32_t)0x00000100U)         /* !< Set LIN Capture 1 Interrupt. */
#define UART_CPU_INT_ISET_LINC1_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_LINC1_SET              ((uint32_t)0x00000100U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[LINOVF] Bits */
#define UART_CPU_INT_ISET_LINOVF_OFS             (9)                             /* !< LINOVF Offset */
#define UART_CPU_INT_ISET_LINOVF_MASK            ((uint32_t)0x00000200U)         /* !< Set LIN Hardware Counter Overflow
                                                                                    Interrupt. */
#define UART_CPU_INT_ISET_LINOVF_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_LINOVF_SET             ((uint32_t)0x00000200U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[RXINT] Bits */
#define UART_CPU_INT_ISET_RXINT_OFS              (10)                            /* !< RXINT Offset */
#define UART_CPU_INT_ISET_RXINT_MASK             ((uint32_t)0x00000400U)         /* !< Set UART Receive Interrupt. */
#define UART_CPU_INT_ISET_RXINT_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_RXINT_SET              ((uint32_t)0x00000400U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[TXINT] Bits */
#define UART_CPU_INT_ISET_TXINT_OFS              (11)                            /* !< TXINT Offset */
#define UART_CPU_INT_ISET_TXINT_MASK             ((uint32_t)0x00000800U)         /* !< Set UART Transmit Interrupt. */
#define UART_CPU_INT_ISET_TXINT_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_TXINT_SET              ((uint32_t)0x00000800U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[EOT] Bits */
#define UART_CPU_INT_ISET_EOT_OFS                (12)                            /* !< EOT Offset */
#define UART_CPU_INT_ISET_EOT_MASK               ((uint32_t)0x00001000U)         /* !< Set UART End of Transmission
                                                                                    Interrupt Indicates that the last bit
                                                                                    of all transmitted data and flags has
                                                                                    left the serializer and without any
                                                                                    further Data in the TX Fifo or
                                                                                    Buffer. */
#define UART_CPU_INT_ISET_EOT_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_EOT_SET                ((uint32_t)0x00001000U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[ADDR_MATCH] Bits */
#define UART_CPU_INT_ISET_ADDR_MATCH_OFS         (13)                            /* !< ADDR_MATCH Offset */
#define UART_CPU_INT_ISET_ADDR_MATCH_MASK        ((uint32_t)0x00002000U)         /* !< Set Address Match Interrupt. */
#define UART_CPU_INT_ISET_ADDR_MATCH_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_ADDR_MATCH_SET         ((uint32_t)0x00002000U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[CTS] Bits */
#define UART_CPU_INT_ISET_CTS_OFS                (14)                            /* !< CTS Offset */
#define UART_CPU_INT_ISET_CTS_MASK               ((uint32_t)0x00004000U)         /* !< Set UART Clear to Send Modem
                                                                                    Interrupt. */
#define UART_CPU_INT_ISET_CTS_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_CTS_SET                ((uint32_t)0x00004000U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[DMA_DONE_RX] Bits */
#define UART_CPU_INT_ISET_DMA_DONE_RX_OFS        (15)                            /* !< DMA_DONE_RX Offset */
#define UART_CPU_INT_ISET_DMA_DONE_RX_MASK       ((uint32_t)0x00008000U)         /* !< Set DMA Done on RX Event Channel
                                                                                    Interrupt */
#define UART_CPU_INT_ISET_DMA_DONE_RX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define UART_CPU_INT_ISET_DMA_DONE_RX_SET        ((uint32_t)0x00008000U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[DMA_DONE_TX] Bits */
#define UART_CPU_INT_ISET_DMA_DONE_TX_OFS        (16)                            /* !< DMA_DONE_TX Offset */
#define UART_CPU_INT_ISET_DMA_DONE_TX_MASK       ((uint32_t)0x00010000U)         /* !< Set DMA Done on TX Event Channel
                                                                                    Interrupt */
#define UART_CPU_INT_ISET_DMA_DONE_TX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define UART_CPU_INT_ISET_DMA_DONE_TX_SET        ((uint32_t)0x00010000U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[RTOUT] Bits */
#define UART_CPU_INT_ISET_RTOUT_OFS              (0)                             /* !< RTOUT Offset */
#define UART_CPU_INT_ISET_RTOUT_MASK             ((uint32_t)0x00000001U)         /* !< Set UARTOUT Receive Time-Out
                                                                                    Interrupt. */
#define UART_CPU_INT_ISET_RTOUT_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ISET_RTOUT_SET              ((uint32_t)0x00000001U)         /* !< Set Interrupt */
/* UART_CPU_INT_ISET[NERR] Bits */
#define UART_CPU_INT_ISET_NERR_OFS               (17)                            /* !< NERR Offset */
#define UART_CPU_INT_ISET_NERR_MASK              ((uint32_t)0x00020000U)         /* !< Noise Error on triple voting.
                                                                                    Asserted when the 3 samples of
                                                                                    majority voting are not equal */
#define UART_CPU_INT_ISET_NERR_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing this has no effect */
#define UART_CPU_INT_ISET_NERR_SET               ((uint32_t)0x00020000U)         /* !< Set the interrupt */

/* UART_CPU_INT_ICLR Bits */
/* UART_CPU_INT_ICLR[FRMERR] Bits */
#define UART_CPU_INT_ICLR_FRMERR_OFS             (1)                             /* !< FRMERR Offset */
#define UART_CPU_INT_ICLR_FRMERR_MASK            ((uint32_t)0x00000002U)         /* !< Clear UART Framing Error Interrupt. */
#define UART_CPU_INT_ICLR_FRMERR_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_FRMERR_CLR             ((uint32_t)0x00000002U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[PARERR] Bits */
#define UART_CPU_INT_ICLR_PARERR_OFS             (2)                             /* !< PARERR Offset */
#define UART_CPU_INT_ICLR_PARERR_MASK            ((uint32_t)0x00000004U)         /* !< Clear UART Parity Error Interrupt. */
#define UART_CPU_INT_ICLR_PARERR_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_PARERR_CLR             ((uint32_t)0x00000004U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[BRKERR] Bits */
#define UART_CPU_INT_ICLR_BRKERR_OFS             (3)                             /* !< BRKERR Offset */
#define UART_CPU_INT_ICLR_BRKERR_MASK            ((uint32_t)0x00000008U)         /* !< Clear UART Break Error Interrupt. */
#define UART_CPU_INT_ICLR_BRKERR_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_BRKERR_CLR             ((uint32_t)0x00000008U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[OVRERR] Bits */
#define UART_CPU_INT_ICLR_OVRERR_OFS             (4)                             /* !< OVRERR Offset */
#define UART_CPU_INT_ICLR_OVRERR_MASK            ((uint32_t)0x00000010U)         /* !< Clear UART Receive Overrun Error
                                                                                    Interrupt. */
#define UART_CPU_INT_ICLR_OVRERR_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_OVRERR_CLR             ((uint32_t)0x00000010U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[RXNE] Bits */
#define UART_CPU_INT_ICLR_RXNE_OFS               (5)                             /* !< RXNE Offset */
#define UART_CPU_INT_ICLR_RXNE_MASK              ((uint32_t)0x00000020U)         /* !< Clear Negative Edge on UARTxRXD
                                                                                    Interrupt. */
#define UART_CPU_INT_ICLR_RXNE_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_RXNE_CLR               ((uint32_t)0x00000020U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[RXPE] Bits */
#define UART_CPU_INT_ICLR_RXPE_OFS               (6)                             /* !< RXPE Offset */
#define UART_CPU_INT_ICLR_RXPE_MASK              ((uint32_t)0x00000040U)         /* !< Clear Positive Edge on UARTxRXD
                                                                                    Interrupt. */
#define UART_CPU_INT_ICLR_RXPE_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_RXPE_CLR               ((uint32_t)0x00000040U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[LINC0] Bits */
#define UART_CPU_INT_ICLR_LINC0_OFS              (7)                             /* !< LINC0 Offset */
#define UART_CPU_INT_ICLR_LINC0_MASK             ((uint32_t)0x00000080U)         /* !< Clear LIN Capture 0 / Match
                                                                                    Interrupt . */
#define UART_CPU_INT_ICLR_LINC0_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_LINC0_CLR              ((uint32_t)0x00000080U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[LINC1] Bits */
#define UART_CPU_INT_ICLR_LINC1_OFS              (8)                             /* !< LINC1 Offset */
#define UART_CPU_INT_ICLR_LINC1_MASK             ((uint32_t)0x00000100U)         /* !< Clear LIN Capture 1 Interrupt. */
#define UART_CPU_INT_ICLR_LINC1_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_LINC1_CLR              ((uint32_t)0x00000100U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[LINOVF] Bits */
#define UART_CPU_INT_ICLR_LINOVF_OFS             (9)                             /* !< LINOVF Offset */
#define UART_CPU_INT_ICLR_LINOVF_MASK            ((uint32_t)0x00000200U)         /* !< Clear LIN Hardware Counter Overflow
                                                                                    Interrupt. */
#define UART_CPU_INT_ICLR_LINOVF_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_LINOVF_CLR             ((uint32_t)0x00000200U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[RXINT] Bits */
#define UART_CPU_INT_ICLR_RXINT_OFS              (10)                            /* !< RXINT Offset */
#define UART_CPU_INT_ICLR_RXINT_MASK             ((uint32_t)0x00000400U)         /* !< Clear UART Receive Interrupt. */
#define UART_CPU_INT_ICLR_RXINT_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_RXINT_CLR              ((uint32_t)0x00000400U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[TXINT] Bits */
#define UART_CPU_INT_ICLR_TXINT_OFS              (11)                            /* !< TXINT Offset */
#define UART_CPU_INT_ICLR_TXINT_MASK             ((uint32_t)0x00000800U)         /* !< Clear UART Transmit Interrupt. */
#define UART_CPU_INT_ICLR_TXINT_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_TXINT_CLR              ((uint32_t)0x00000800U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[EOT] Bits */
#define UART_CPU_INT_ICLR_EOT_OFS                (12)                            /* !< EOT Offset */
#define UART_CPU_INT_ICLR_EOT_MASK               ((uint32_t)0x00001000U)         /* !< Clear UART End of Transmission
                                                                                    Interrupt Indicates that the last bit
                                                                                    of all transmitted data and flags has
                                                                                    left the serializer and without any
                                                                                    further Data in the TX Fifo or
                                                                                    Buffer. */
#define UART_CPU_INT_ICLR_EOT_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_EOT_CLR                ((uint32_t)0x00001000U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[ADDR_MATCH] Bits */
#define UART_CPU_INT_ICLR_ADDR_MATCH_OFS         (13)                            /* !< ADDR_MATCH Offset */
#define UART_CPU_INT_ICLR_ADDR_MATCH_MASK        ((uint32_t)0x00002000U)         /* !< Clear Address Match Interrupt. */
#define UART_CPU_INT_ICLR_ADDR_MATCH_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_ADDR_MATCH_CLR         ((uint32_t)0x00002000U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[CTS] Bits */
#define UART_CPU_INT_ICLR_CTS_OFS                (14)                            /* !< CTS Offset */
#define UART_CPU_INT_ICLR_CTS_MASK               ((uint32_t)0x00004000U)         /* !< Clear UART Clear to Send Modem
                                                                                    Interrupt. */
#define UART_CPU_INT_ICLR_CTS_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_CTS_CLR                ((uint32_t)0x00004000U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[DMA_DONE_RX] Bits */
#define UART_CPU_INT_ICLR_DMA_DONE_RX_OFS        (15)                            /* !< DMA_DONE_RX Offset */
#define UART_CPU_INT_ICLR_DMA_DONE_RX_MASK       ((uint32_t)0x00008000U)         /* !< Clear DMA Done on RX Event Channel
                                                                                    Interrupt */
#define UART_CPU_INT_ICLR_DMA_DONE_RX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define UART_CPU_INT_ICLR_DMA_DONE_RX_CLR        ((uint32_t)0x00008000U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[DMA_DONE_TX] Bits */
#define UART_CPU_INT_ICLR_DMA_DONE_TX_OFS        (16)                            /* !< DMA_DONE_TX Offset */
#define UART_CPU_INT_ICLR_DMA_DONE_TX_MASK       ((uint32_t)0x00010000U)         /* !< Clear DMA Done on TX Event Channel
                                                                                    Interrupt */
#define UART_CPU_INT_ICLR_DMA_DONE_TX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define UART_CPU_INT_ICLR_DMA_DONE_TX_CLR        ((uint32_t)0x00010000U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[RTOUT] Bits */
#define UART_CPU_INT_ICLR_RTOUT_OFS              (0)                             /* !< RTOUT Offset */
#define UART_CPU_INT_ICLR_RTOUT_MASK             ((uint32_t)0x00000001U)         /* !< Clear UARTOUT Receive Time-Out
                                                                                    Interrupt. */
#define UART_CPU_INT_ICLR_RTOUT_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_RTOUT_CLR              ((uint32_t)0x00000001U)         /* !< Clear Interrupt */
/* UART_CPU_INT_ICLR[NERR] Bits */
#define UART_CPU_INT_ICLR_NERR_OFS               (17)                            /* !< NERR Offset */
#define UART_CPU_INT_ICLR_NERR_MASK              ((uint32_t)0x00020000U)         /* !< Noise Error on triple voting.
                                                                                    Asserted when the 3 samples of
                                                                                    majority voting are not equal */
#define UART_CPU_INT_ICLR_NERR_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_CPU_INT_ICLR_NERR_CLR               ((uint32_t)0x00020000U)         /* !< Clear Interrupt */

/* UART_PWREN Bits */
/* UART_PWREN[ENABLE] Bits */
#define UART_PWREN_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define UART_PWREN_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< Enable the power */
#define UART_PWREN_ENABLE_DISABLE                ((uint32_t)0x00000000U)         /* !< Disable Power */
#define UART_PWREN_ENABLE_ENABLE                 ((uint32_t)0x00000001U)         /* !< Enable Power */
/* UART_PWREN[KEY] Bits */
#define UART_PWREN_KEY_OFS                       (24)                            /* !< KEY Offset */
#define UART_PWREN_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define UART_PWREN_KEY_UNLOCK_W                  ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* UART_RSTCTL Bits */
/* UART_RSTCTL[RESETSTKYCLR] Bits */
#define UART_RSTCTL_RESETSTKYCLR_OFS             (1)                             /* !< RESETSTKYCLR Offset */
#define UART_RSTCTL_RESETSTKYCLR_MASK            ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define UART_RSTCTL_RESETSTKYCLR_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_RSTCTL_RESETSTKYCLR_CLR             ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* UART_RSTCTL[RESETASSERT] Bits */
#define UART_RSTCTL_RESETASSERT_OFS              (0)                             /* !< RESETASSERT Offset */
#define UART_RSTCTL_RESETASSERT_MASK             ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define UART_RSTCTL_RESETASSERT_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define UART_RSTCTL_RESETASSERT_ASSERT           ((uint32_t)0x00000001U)         /* !< Assert reset */
/* UART_RSTCTL[KEY] Bits */
#define UART_RSTCTL_KEY_OFS                      (24)                            /* !< KEY Offset */
#define UART_RSTCTL_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define UART_RSTCTL_KEY_UNLOCK_W                 ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* UART_CLKCFG Bits */
/* UART_CLKCFG[KEY] Bits */
#define UART_CLKCFG_KEY_OFS                      (24)                            /* !< KEY Offset */
#define UART_CLKCFG_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define UART_CLKCFG_KEY_UNLOCK                   ((uint32_t)0xA9000000U)
/* UART_CLKCFG[BLOCKASYNC] Bits */
#define UART_CLKCFG_BLOCKASYNC_OFS               (8)                             /* !< BLOCKASYNC Offset */
#define UART_CLKCFG_BLOCKASYNC_MASK              ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define UART_CLKCFG_BLOCKASYNC_DISABLE           ((uint32_t)0x00000000U)
#define UART_CLKCFG_BLOCKASYNC_ENABLE            ((uint32_t)0x00000100U)

/* UART_GPRCM_STAT Bits */
/* UART_GPRCM_STAT[RESETSTKY] Bits */
#define UART_GPRCM_STAT_RESETSTKY_OFS            (16)                            /* !< RESETSTKY Offset */
#define UART_GPRCM_STAT_RESETSTKY_MASK           ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define UART_GPRCM_STAT_RESETSTKY_NORES          ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define UART_GPRCM_STAT_RESETSTKY_RESET          ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* UART_CLKDIV Bits */
/* UART_CLKDIV[RATIO] Bits */
#define UART_CLKDIV_RATIO_OFS                    (0)                             /* !< RATIO Offset */
#define UART_CLKDIV_RATIO_MASK                   ((uint32_t)0x00000007U)         /* !< Selects divide ratio of module
                                                                                    clock */
#define UART_CLKDIV_RATIO_DIV_BY_1               ((uint32_t)0x00000000U)         /* !< Do not divide clock source */
#define UART_CLKDIV_RATIO_DIV_BY_2               ((uint32_t)0x00000001U)         /* !< Divide clock source by 2 */
#define UART_CLKDIV_RATIO_DIV_BY_3               ((uint32_t)0x00000002U)         /* !< Divide clock source by 3 */
#define UART_CLKDIV_RATIO_DIV_BY_4               ((uint32_t)0x00000003U)         /* !< Divide clock source by 4 */
#define UART_CLKDIV_RATIO_DIV_BY_5               ((uint32_t)0x00000004U)         /* !< Divide clock source by 5 */
#define UART_CLKDIV_RATIO_DIV_BY_6               ((uint32_t)0x00000005U)         /* !< Divide clock source by 6 */
#define UART_CLKDIV_RATIO_DIV_BY_7               ((uint32_t)0x00000006U)         /* !< Divide clock source by 7 */
#define UART_CLKDIV_RATIO_DIV_BY_8               ((uint32_t)0x00000007U)         /* !< Divide clock source by 8 */

/* UART_CLKSEL Bits */
/* UART_CLKSEL[MFCLK_SEL] Bits */
#define UART_CLKSEL_MFCLK_SEL_OFS                (2)                             /* !< MFCLK_SEL Offset */
#define UART_CLKSEL_MFCLK_SEL_MASK               ((uint32_t)0x00000004U)         /* !< Selects MFCLK as clock source if
                                                                                    enabled */
#define UART_CLKSEL_MFCLK_SEL_DISABLE            ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define UART_CLKSEL_MFCLK_SEL_ENABLE             ((uint32_t)0x00000004U)         /* !< Select this clock as a source */
/* UART_CLKSEL[BUSCLK_SEL] Bits */
#define UART_CLKSEL_BUSCLK_SEL_OFS               (3)                             /* !< BUSCLK_SEL Offset */
#define UART_CLKSEL_BUSCLK_SEL_MASK              ((uint32_t)0x00000008U)         /* !< Selects BUS CLK as clock source if
                                                                                    enabled */
#define UART_CLKSEL_BUSCLK_SEL_DISABLE           ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define UART_CLKSEL_BUSCLK_SEL_ENABLE            ((uint32_t)0x00000008U)         /* !< Select this clock as a source */
/* UART_CLKSEL[LFCLK_SEL] Bits */
#define UART_CLKSEL_LFCLK_SEL_OFS                (1)                             /* !< LFCLK_SEL Offset */
#define UART_CLKSEL_LFCLK_SEL_MASK               ((uint32_t)0x00000002U)         /* !< Selects LFCLK as clock source if
                                                                                    enabled */
#define UART_CLKSEL_LFCLK_SEL_DISABLE            ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define UART_CLKSEL_LFCLK_SEL_ENABLE             ((uint32_t)0x00000002U)         /* !< Select this clock as a source */

/* UART_PDBGCTL Bits */
/* UART_PDBGCTL[FREE] Bits */
#define UART_PDBGCTL_FREE_OFS                    (0)                             /* !< FREE Offset */
#define UART_PDBGCTL_FREE_MASK                   ((uint32_t)0x00000001U)         /* !< Free run control */
#define UART_PDBGCTL_FREE_STOP                   ((uint32_t)0x00000000U)         /* !< The peripheral freezes
                                                                                    functionality while the Core Halted
                                                                                    input is asserted and resumes when it
                                                                                    is deasserted. */
#define UART_PDBGCTL_FREE_RUN                    ((uint32_t)0x00000001U)         /* !< The peripheral ignores the state of
                                                                                    the Core Halted input */
/* UART_PDBGCTL[SOFT] Bits */
#define UART_PDBGCTL_SOFT_OFS                    (1)                             /* !< SOFT Offset */
#define UART_PDBGCTL_SOFT_MASK                   ((uint32_t)0x00000002U)         /* !< Soft halt boundary control. This
                                                                                    function is only available, if [FREE]
                                                                                    is set to 'STOP' */
#define UART_PDBGCTL_SOFT_IMMEDIATE              ((uint32_t)0x00000000U)         /* !< The peripheral will halt
                                                                                    immediately, even if the resultant
                                                                                    state will result in corruption if
                                                                                    the system is restarted */
#define UART_PDBGCTL_SOFT_DELAYED                ((uint32_t)0x00000002U)         /* !< The peripheral blocks the debug
                                                                                    freeze until it has reached a
                                                                                    boundary where it can resume without
                                                                                    corruption */

/* UART_EVT_MODE Bits */
/* UART_EVT_MODE[INT0_CFG] Bits */
#define UART_EVT_MODE_INT0_CFG_OFS               (0)                             /* !< INT0_CFG Offset */
#define UART_EVT_MODE_INT0_CFG_MASK              ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT0] */
#define UART_EVT_MODE_INT0_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define UART_EVT_MODE_INT0_CFG_SOFTWARE          ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define UART_EVT_MODE_INT0_CFG_HARDWARE          ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* UART_EVT_MODE[INT1_CFG] Bits */
#define UART_EVT_MODE_INT1_CFG_OFS               (2)                             /* !< INT1_CFG Offset */
#define UART_EVT_MODE_INT1_CFG_MASK              ((uint32_t)0x0000000CU)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT1] */
#define UART_EVT_MODE_INT1_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define UART_EVT_MODE_INT1_CFG_SOFTWARE          ((uint32_t)0x00000004U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define UART_EVT_MODE_INT1_CFG_HARDWARE          ((uint32_t)0x00000008U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* UART_EVT_MODE[INT2_CFG] Bits */
#define UART_EVT_MODE_INT2_CFG_OFS               (4)                             /* !< INT2_CFG Offset */
#define UART_EVT_MODE_INT2_CFG_MASK              ((uint32_t)0x00000030U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT2] */
#define UART_EVT_MODE_INT2_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define UART_EVT_MODE_INT2_CFG_SOFTWARE          ((uint32_t)0x00000010U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define UART_EVT_MODE_INT2_CFG_HARDWARE          ((uint32_t)0x00000020U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* UART_INTCTL Bits */
/* UART_INTCTL[INTEVAL] Bits */
#define UART_INTCTL_INTEVAL_OFS                  (0)                             /* !< INTEVAL Offset */
#define UART_INTCTL_INTEVAL_MASK                 ((uint32_t)0x00000001U)         /* !< Writing a 1 to this field
                                                                                    re-evaluates the interrupt sources. */
#define UART_INTCTL_INTEVAL_DISABLE              ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define UART_INTCTL_INTEVAL_EVAL                 ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */

/* UART_CTL0 Bits */
/* UART_CTL0[ENABLE] Bits */
#define UART_CTL0_ENABLE_OFS                     (0)                             /* !< ENABLE Offset */
#define UART_CTL0_ENABLE_MASK                    ((uint32_t)0x00000001U)         /* !< UART Module Enable.  If the UART is
                                                                                    disabled in the middle of
                                                                                    transmission or reception, it
                                                                                    completes the current character
                                                                                    before stopping.  If the ENABLE bit
                                                                                    is not set, all registers can still
                                                                                    be accessed and updated. It is
                                                                                    recommended to setup and change the
                                                                                    UART operation mode with having the
                                                                                    ENABLE bit cleared to avoid
                                                                                    unpredictable behavior during the
                                                                                    setup or update. If disabled the UART
                                                                                    module will not send or receive any
                                                                                    data and the logic is held in reset
                                                                                    state. */
#define UART_CTL0_ENABLE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Disable Module */
#define UART_CTL0_ENABLE_ENABLE                  ((uint32_t)0x00000001U)         /* !< Enable module */
/* UART_CTL0[HSE] Bits */
#define UART_CTL0_HSE_OFS                        (15)                            /* !< HSE Offset */
#define UART_CTL0_HSE_MASK                       ((uint32_t)0x00018000U)         /* !< High-Speed Bit Oversampling Enable
                                                                                    #b#NOTE:#/b# The bit oversampling
                                                                                    influences the UART baud-rate
                                                                                    configuration.  The state of this bit
                                                                                    has no effect on clock generation in
                                                                                    ISO7816 smart card mode (the SMART
                                                                                    bit is set). */
#define UART_CTL0_HSE_OVS16                      ((uint32_t)0x00000000U)         /* !< 16x oversampling. */
#define UART_CTL0_HSE_OVS8                       ((uint32_t)0x00008000U)         /* !< 8x oversampling. */
#define UART_CTL0_HSE_OVS3                       ((uint32_t)0x00010000U)         /* !< 3x oversampling. IrDA, Manchester
                                                                                    and DALI not supported when 3x
                                                                                    oversampling is enabled. */
/* UART_CTL0[LBE] Bits */
#define UART_CTL0_LBE_OFS                        (2)                             /* !< LBE Offset */
#define UART_CTL0_LBE_MASK                       ((uint32_t)0x00000004U)         /* !< UART Loop Back Enable */
#define UART_CTL0_LBE_DISABLE                    ((uint32_t)0x00000000U)         /* !< Normal operation. */
#define UART_CTL0_LBE_ENABLE                     ((uint32_t)0x00000004U)         /* !< The UARTxTX path is fed through the
                                                                                    UARTxRX path internally. */
/* UART_CTL0[RXE] Bits */
#define UART_CTL0_RXE_OFS                        (3)                             /* !< RXE Offset */
#define UART_CTL0_RXE_MASK                       ((uint32_t)0x00000008U)         /* !< UART Receive Enable  If the UART is
                                                                                    disabled in the middle of a receive,
                                                                                    it completes the current character
                                                                                    before stopping.   #b#NOTE:#/b# To
                                                                                    enable reception, the UARTEN bit must
                                                                                    be set. */
#define UART_CTL0_RXE_DISABLE                    ((uint32_t)0x00000000U)         /* !< The receive section of the UART is
                                                                                    disabled. */
#define UART_CTL0_RXE_ENABLE                     ((uint32_t)0x00000008U)         /* !< The receive section of the UART is
                                                                                    enabled. */
/* UART_CTL0[TXE] Bits */
#define UART_CTL0_TXE_OFS                        (4)                             /* !< TXE Offset */
#define UART_CTL0_TXE_MASK                       ((uint32_t)0x00000010U)         /* !< UART Transmit Enable  If the UART
                                                                                    is disabled in the middle of a
                                                                                    transmission, it completes the
                                                                                    current character before stopping.
                                                                                    #b#NOTE:#/b# To enable transmission,
                                                                                    the UARTEN bit must be set. */
#define UART_CTL0_TXE_DISABLE                    ((uint32_t)0x00000000U)         /* !< The transmit section of the UART is
                                                                                    disabled. The UARTxTXD pin of the
                                                                                    UART can be controlled by the TXD_CTL
                                                                                    bit when enabled. */
#define UART_CTL0_TXE_ENABLE                     ((uint32_t)0x00000010U)         /* !< The transmit section of the UART is
                                                                                    enabled. */
/* UART_CTL0[RTS] Bits */
#define UART_CTL0_RTS_OFS                        (12)                            /* !< RTS Offset */
#define UART_CTL0_RTS_MASK                       ((uint32_t)0x00001000U)         /* !< Request to Send    If RTSEN is set
                                                                                    the RTS output signals is controlled
                                                                                    by the hardware logic using the FIFO
                                                                                    fill level or TXDATA buffer.  If
                                                                                    RTSEN is cleared the RTS output is
                                                                                    controlled by the RTS bit. The bit is
                                                                                    the complement of the UART request to
                                                                                    send, RTS modem status output. */
#define UART_CTL0_RTS_CLR                        ((uint32_t)0x00000000U)         /* !< Signal not RTS */
#define UART_CTL0_RTS_SET                        ((uint32_t)0x00001000U)         /* !< Signal RTS */
/* UART_CTL0[RTSEN] Bits */
#define UART_CTL0_RTSEN_OFS                      (13)                            /* !< RTSEN Offset */
#define UART_CTL0_RTSEN_MASK                     ((uint32_t)0x00002000U)         /* !< Enable hardware controlled Request
                                                                                    to Send */
#define UART_CTL0_RTSEN_DISABLE                  ((uint32_t)0x00000000U)         /* !< RTS hardware flow control is
                                                                                    disabled. */
#define UART_CTL0_RTSEN_ENABLE                   ((uint32_t)0x00002000U)         /* !< RTS hardware flow control is
                                                                                    enabled. Data is only requested (by
                                                                                    asserting UARTxRTS) when the receive
                                                                                    FIFO has available entries. */
/* UART_CTL0[CTSEN] Bits */
#define UART_CTL0_CTSEN_OFS                      (14)                            /* !< CTSEN Offset */
#define UART_CTL0_CTSEN_MASK                     ((uint32_t)0x00004000U)         /* !< Enable Clear To Send */
#define UART_CTL0_CTSEN_DISABLE                  ((uint32_t)0x00000000U)         /* !< CTS hardware flow control is
                                                                                    disabled. */
#define UART_CTL0_CTSEN_ENABLE                   ((uint32_t)0x00004000U)         /* !< CTS hardware flow control is
                                                                                    enabled. Data is only transmitted
                                                                                    when the UARTxCTS signal is asserted. */
/* UART_CTL0[MENC] Bits */
#define UART_CTL0_MENC_OFS                       (7)                             /* !< MENC Offset */
#define UART_CTL0_MENC_MASK                      ((uint32_t)0x00000080U)         /* !< Manchester Encode enable */
#define UART_CTL0_MENC_DISABLE                   ((uint32_t)0x00000000U)         /* !< Disable Manchester Encoding */
#define UART_CTL0_MENC_ENABLE                    ((uint32_t)0x00000080U)         /* !< Enable Manchester Encoding */
/* UART_CTL0[MODE] Bits */
#define UART_CTL0_MODE_OFS                       (8)                             /* !< MODE Offset */
#define UART_CTL0_MODE_MASK                      ((uint32_t)0x00000700U)         /* !< Set the communication mode and
                                                                                    protocol used. (Not defined settings
                                                                                    uses the default setting: 0) */
#define UART_CTL0_MODE_UART                      ((uint32_t)0x00000000U)         /* !< Normal operation */
#define UART_CTL0_MODE_RS485                     ((uint32_t)0x00000100U)         /* !< RS485 mode: UART needs to be IDLE
                                                                                    with receiving data for the in
                                                                                    EXTDIR_HOLD set time. EXTDIR_SETUP
                                                                                    defines the time the RTS line is set
                                                                                    to high before sending. When the
                                                                                    buffer is empty the RTS line is set
                                                                                    low again. A transmit will be delayed
                                                                                    as long the UART is receiving data. */
#define UART_CTL0_MODE_IDLELINE                  ((uint32_t)0x00000200U)         /* !< The UART operates in IDLE Line Mode */
#define UART_CTL0_MODE_ADDR9BIT                  ((uint32_t)0x00000300U)         /* !< The UART operates in 9 Bit Address
                                                                                    mode */
#define UART_CTL0_MODE_SMART                     ((uint32_t)0x00000400U)         /* !< ISO7816 Smart Card Support  The
                                                                                    application must ensure that it sets
                                                                                    8-bit word length (WLEN set to 3h)
                                                                                    and even parity (PEN set to 1, EPS
                                                                                    set to 1, SPS set to 0) in UARTLCRH
                                                                                    when using ISO7816 mode. The value of
                                                                                    the STP2 bit in UARTLCRH is ignored
                                                                                    and the number of stop bits is forced
                                                                                    to 2. */
#define UART_CTL0_MODE_DALI                      ((uint32_t)0x00000500U)         /* !< DALI Mode: */
/* UART_CTL0[FEN] Bits */
#define UART_CTL0_FEN_OFS                        (17)                            /* !< FEN Offset */
#define UART_CTL0_FEN_MASK                       ((uint32_t)0x00020000U)         /* !< UART Enable FIFOs */
#define UART_CTL0_FEN_DISABLE                    ((uint32_t)0x00000000U)         /* !< The FIFOs are disabled (Character
                                                                                    mode). The FIFOs become 1-byte-deep
                                                                                    holding registers. */
#define UART_CTL0_FEN_ENABLE                     ((uint32_t)0x00020000U)         /* !< The transmit and receive FIFO
                                                                                    buffers are enabled (FIFO mode). */
/* UART_CTL0[TXD_OUT] Bits */
#define UART_CTL0_TXD_OUT_OFS                    (6)                             /* !< TXD_OUT Offset */
#define UART_CTL0_TXD_OUT_MASK                   ((uint32_t)0x00000040U)         /* !< TXD Pin Control Controls the TXD
                                                                                    pin when TXD_OUT_EN = 1 and TXE = 0. */
#define UART_CTL0_TXD_OUT_LOW                    ((uint32_t)0x00000000U)         /* !< TXD pin is low */
#define UART_CTL0_TXD_OUT_HIGH                   ((uint32_t)0x00000040U)         /* !< TXD pin is high */
/* UART_CTL0[TXD_OUT_EN] Bits */
#define UART_CTL0_TXD_OUT_EN_OFS                 (5)                             /* !< TXD_OUT_EN Offset */
#define UART_CTL0_TXD_OUT_EN_MASK                ((uint32_t)0x00000020U)         /* !< TXD Pin Control Enable. When the
                                                                                    transmit section of the UART is
                                                                                    disabled (TXE = 0), the TXD pin can
                                                                                    be controlled by the TXD_OUT bit. */
#define UART_CTL0_TXD_OUT_EN_DISABLE             ((uint32_t)0x00000000U)         /* !< TXD pin can not be controlled by
                                                                                    TXD_OUT */
#define UART_CTL0_TXD_OUT_EN_ENABLE              ((uint32_t)0x00000020U)         /* !< TXD pin can be controlled by
                                                                                    TXD_OUT */
/* UART_CTL0[MAJVOTE] Bits */
#define UART_CTL0_MAJVOTE_OFS                    (18)                            /* !< MAJVOTE Offset */
#define UART_CTL0_MAJVOTE_MASK                   ((uint32_t)0x00040000U)         /* !< Majority Vote Enable   When
                                                                                    Majority Voting is enabled, the three
                                                                                    center bits are used to determine
                                                                                    received sample value. In case of
                                                                                    error (i.e. all 3 bits are not the
                                                                                    same), noise error is detected and
                                                                                    bits RIS.NERR and register
                                                                                    RXDATA.NERR are set.
                                                                                    Oversampling of 16 : bits 7, 8, 9 are
                                                                                    used      Oversampling of 8 : bits 3,
                                                                                    4, 5 are used Disabled : Single
                                                                                    sample value (center value) used */
#define UART_CTL0_MAJVOTE_DISABLE                ((uint32_t)0x00000000U)         /* !< Majority voting is disabled */
#define UART_CTL0_MAJVOTE_ENABLE                 ((uint32_t)0x00040000U)         /* !< Majority voting is enabled */
/* UART_CTL0[MSBFIRST] Bits */
#define UART_CTL0_MSBFIRST_OFS                   (19)                            /* !< MSBFIRST Offset */
#define UART_CTL0_MSBFIRST_MASK                  ((uint32_t)0x00080000U)         /* !< Most Significant Bit First This bit
                                                                                    has effect both on the way protocol
                                                                                    byte is transmitted and received.
                                                                                    Notes: User needs to match the
                                                                                    protocol to the correct value of this
                                                                                    bit to send MSb or LSb first. The
                                                                                    hardware engine will send the byte
                                                                                    entirely based on this bit. */
#define UART_CTL0_MSBFIRST_DISABLE               ((uint32_t)0x00000000U)         /* !< Least significant bit is sent first
                                                                                    in the protocol packet */
#define UART_CTL0_MSBFIRST_ENABLE                ((uint32_t)0x00080000U)         /* !< Most significant bit is sent first
                                                                                    in the protocol packet */

/* UART_LCRH Bits */
/* UART_LCRH[BRK] Bits */
#define UART_LCRH_BRK_OFS                        (0)                             /* !< BRK Offset */
#define UART_LCRH_BRK_MASK                       ((uint32_t)0x00000001U)         /* !< UART Send Break (for LIN Protocol) */
#define UART_LCRH_BRK_DISABLE                    ((uint32_t)0x00000000U)         /* !< Normal use. */
#define UART_LCRH_BRK_ENABLE                     ((uint32_t)0x00000001U)         /* !< A low level is continually output
                                                                                    on the UARTxTXD signal, after
                                                                                    completing transmission of the
                                                                                    current character. For the proper
                                                                                    execution of the break command,
                                                                                    software must set this bit for at
                                                                                    least two frames (character periods). */
/* UART_LCRH[PEN] Bits */
#define UART_LCRH_PEN_OFS                        (1)                             /* !< PEN Offset */
#define UART_LCRH_PEN_MASK                       ((uint32_t)0x00000002U)         /* !< UART Parity Enable */
#define UART_LCRH_PEN_DISABLE                    ((uint32_t)0x00000000U)         /* !< Parity is disabled and no parity
                                                                                    bit is added to the data frame. */
#define UART_LCRH_PEN_ENABLE                     ((uint32_t)0x00000002U)         /* !< Parity checking and generation is
                                                                                    enabled. */
/* UART_LCRH[EPS] Bits */
#define UART_LCRH_EPS_OFS                        (2)                             /* !< EPS Offset */
#define UART_LCRH_EPS_MASK                       ((uint32_t)0x00000004U)         /* !< UART Even Parity Select  This bit
                                                                                    has no effect when parity is disabled
                                                                                    by the PEN bit.  For 9-Bit UART Mode
                                                                                    transmissions, this bit controls the
                                                                                    address byte and data byte indication
                                                                                    (9th bit). 0 = The transferred byte
                                                                                    is a data byte 1 = The transferred
                                                                                    byte is an address byte */
#define UART_LCRH_EPS_ODD                        ((uint32_t)0x00000000U)         /* !< Odd parity is performed, which
                                                                                    checks for an odd number of 1s. */
#define UART_LCRH_EPS_EVEN                       ((uint32_t)0x00000004U)         /* !< Even parity generation and checking
                                                                                    is performed during transmission and
                                                                                    reception, which checks for an even
                                                                                    number of 1s in data and parity bits. */
/* UART_LCRH[STP2] Bits */
#define UART_LCRH_STP2_OFS                       (3)                             /* !< STP2 Offset */
#define UART_LCRH_STP2_MASK                      ((uint32_t)0x00000008U)         /* !< UART Two Stop Bits Select     When
                                                                                    in 7816 smart card mode (the SMART
                                                                                    bit is set in the UARTCTL register),
                                                                                    the number of stop bits is forced to
                                                                                    2. */
#define UART_LCRH_STP2_DISABLE                   ((uint32_t)0x00000000U)         /* !< One stop bit is transmitted at the
                                                                                    end of a frame. */
#define UART_LCRH_STP2_ENABLE                    ((uint32_t)0x00000008U)         /* !< Two stop bits are transmitted at
                                                                                    the end of a frame. The receive logic
                                                                                    checks for two stop bits being
                                                                                    received and provide Frame Error if
                                                                                    either is invalid. */
/* UART_LCRH[WLEN] Bits */
#define UART_LCRH_WLEN_OFS                       (4)                             /* !< WLEN Offset */
#define UART_LCRH_WLEN_MASK                      ((uint32_t)0x00000030U)         /* !< UART Word Length  The bits indicate
                                                                                    the number of data bits transmitted
                                                                                    or received in a frame as follows: */
#define UART_LCRH_WLEN_DATABIT5                  ((uint32_t)0x00000000U)         /* !< 5 bits (default) */
#define UART_LCRH_WLEN_DATABIT6                  ((uint32_t)0x00000010U)         /* !< 6 bits */
#define UART_LCRH_WLEN_DATABIT7                  ((uint32_t)0x00000020U)         /* !< 7 bits */
#define UART_LCRH_WLEN_DATABIT8                  ((uint32_t)0x00000030U)         /* !< 8 bits */
/* UART_LCRH[SPS] Bits */
#define UART_LCRH_SPS_OFS                        (6)                             /* !< SPS Offset */
#define UART_LCRH_SPS_MASK                       ((uint32_t)0x00000040U)         /* !< UART Stick Parity Select The Stick
                                                                                    Parity Select (SPS) bit is used to
                                                                                    set either a permanent '1' or a
                                                                                    permanent '0' as parity when
                                                                                    transmitting or receiving data. Its
                                                                                    purpose is to typically indicate the
                                                                                    first byte of a package or to mark an
                                                                                    address byte, for example in a
                                                                                    multi-drop RS-485 network.  When bits
                                                                                    PEN, EPS, and SPS of UARTLCRH are
                                                                                    set, the parity bit is transmitted
                                                                                    and checked as a 0.  When bits PEN
                                                                                    and SPS are set and EPS is cleared,
                                                                                    the parity bit is transmitted and
                                                                                    checked as a 1. */
#define UART_LCRH_SPS_DISABLE                    ((uint32_t)0x00000000U)         /* !< Disable Stick Parity */
#define UART_LCRH_SPS_ENABLE                     ((uint32_t)0x00000040U)         /* !< Enable Stick Parity */
/* UART_LCRH[SENDIDLE] Bits */
#define UART_LCRH_SENDIDLE_OFS                   (7)                             /* !< SENDIDLE Offset */
#define UART_LCRH_SENDIDLE_MASK                  ((uint32_t)0x00000080U)         /* !< UART send IDLE pattern. When this
                                                                                    bit is set an SENDIDLE period of 11
                                                                                    bit times will be sent on the TX
                                                                                    line. The bit is cleared by hardware
                                                                                    afterwards. */
#define UART_LCRH_SENDIDLE_DISABLE               ((uint32_t)0x00000000U)         /* !< Disable Send Idle Pattern */
#define UART_LCRH_SENDIDLE_ENABLE                ((uint32_t)0x00000080U)         /* !< Enable Send Idle Pattern */
/* UART_LCRH[EXTDIR_SETUP] Bits */
#define UART_LCRH_EXTDIR_SETUP_OFS               (16)                            /* !< EXTDIR_SETUP Offset */
#define UART_LCRH_EXTDIR_SETUP_MASK              ((uint32_t)0x001F0000U)         /* !< Defines the number of UARTclk ticks
                                                                                    the signal to control the external
                                                                                    driver for the RS485 will be set
                                                                                    before the START bit is send */
#define UART_LCRH_EXTDIR_SETUP_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_LCRH_EXTDIR_SETUP_MAXIMUM           ((uint32_t)0x001F0000U)         /* !< Highest possible value */
/* UART_LCRH[EXTDIR_HOLD] Bits */
#define UART_LCRH_EXTDIR_HOLD_OFS                (21)                            /* !< EXTDIR_HOLD Offset */
#define UART_LCRH_EXTDIR_HOLD_MASK               ((uint32_t)0x03E00000U)         /* !< Defines the number of UARTclk ticks
                                                                                    the signal to control the external
                                                                                    driver for the RS485 will be reset
                                                                                    after the beginning of the stop bit.
                                                                                    (If 2 STOP bits are enabled the
                                                                                    beginning of the 2nd STOP bit.) */
#define UART_LCRH_EXTDIR_HOLD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_LCRH_EXTDIR_HOLD_MAXIMUM            ((uint32_t)0x03E00000U)         /* !< Highest possible value */

/* UART_STAT Bits */
/* UART_STAT[BUSY] Bits */
#define UART_STAT_BUSY_OFS                       (0)                             /* !< BUSY Offset */
#define UART_STAT_BUSY_MASK                      ((uint32_t)0x00000001U)         /* !< UART Busy This bit is set as soon
                                                                                    as the transmit FIFO or TXDATA
                                                                                    register becomes non-empty
                                                                                    (regardless of whether UART is
                                                                                    enabled) or if a receive data is
                                                                                    currently ongoing (after the start
                                                                                    edge have been detected until a
                                                                                    complete byte, including all stop
                                                                                    bits, has been received by the shift
                                                                                    register). In IDLE_Line mode the Busy
                                                                                    signal also stays set during the idle
                                                                                    time generation. */
#define UART_STAT_BUSY_CLEARED                   ((uint32_t)0x00000000U)         /* !< The UART is not busy. */
#define UART_STAT_BUSY_SET                       ((uint32_t)0x00000001U)         /* !< The UART is busy transmitting data.
                                                                                    This bit remains set until the
                                                                                    complete byte, including all stop
                                                                                    bits, has been sent/received
                                                                                    from/into the shift register. */
/* UART_STAT[TXFF] Bits */
#define UART_STAT_TXFF_OFS                       (7)                             /* !< TXFF Offset */
#define UART_STAT_TXFF_MASK                      ((uint32_t)0x00000080U)         /* !< UART Transmit FIFO Full  The
                                                                                    meaning of this bit depends on the
                                                                                    state of the FEN bit in the CTL0
                                                                                    register. */
#define UART_STAT_TXFF_CLEARED                   ((uint32_t)0x00000000U)         /* !< The transmitter is not full. */
#define UART_STAT_TXFF_SET                       ((uint32_t)0x00000080U)         /* !< If the FIFO is disabled (FEN is 0),
                                                                                    the transmit holding register is
                                                                                    full. If the FIFO is enabled (FEN is
                                                                                    1), the transmit FIFO is full. */
/* UART_STAT[RXFF] Bits */
#define UART_STAT_RXFF_OFS                       (3)                             /* !< RXFF Offset */
#define UART_STAT_RXFF_MASK                      ((uint32_t)0x00000008U)         /* !< UART Receive FIFO Full  The meaning
                                                                                    of this bit depends on the state of
                                                                                    the FEN bit in the CTL0 register. */
#define UART_STAT_RXFF_CLEARED                   ((uint32_t)0x00000000U)         /* !< The receiver can receive data. */
#define UART_STAT_RXFF_SET                       ((uint32_t)0x00000008U)         /* !< If the FIFO is disabled (FEN is 0),
                                                                                    the receive holding register is full.
                                                                                    If the FIFO is enabled (FEN is 1),
                                                                                    the receive FIFO is full. */
/* UART_STAT[TXFE] Bits */
#define UART_STAT_TXFE_OFS                       (6)                             /* !< TXFE Offset */
#define UART_STAT_TXFE_MASK                      ((uint32_t)0x00000040U)         /* !< UART Transmit FIFO Empty  The
                                                                                    meaning of this bit depends on the
                                                                                    state of the FEN bit in the CTL0
                                                                                    register. */
#define UART_STAT_TXFE_CLEARED                   ((uint32_t)0x00000000U)         /* !< The transmitter has data to
                                                                                    transmit. */
#define UART_STAT_TXFE_SET                       ((uint32_t)0x00000040U)         /* !< If the FIFO is disabled (FEN is 0),
                                                                                    the transmit holding register is
                                                                                    empty. If the FIFO is enabled (FEN is
                                                                                    1), the transmit FIFO is empty. */
/* UART_STAT[CTS] Bits */
#define UART_STAT_CTS_OFS                        (8)                             /* !< CTS Offset */
#define UART_STAT_CTS_MASK                       ((uint32_t)0x00000100U)         /* !< Clear To Send */
#define UART_STAT_CTS_CLEARED                    ((uint32_t)0x00000000U)         /* !< The CTS signal is not asserted
                                                                                    (high). */
#define UART_STAT_CTS_SET                        ((uint32_t)0x00000100U)         /* !< The CTS signal is asserted (low). */
/* UART_STAT[IDLE] Bits */
#define UART_STAT_IDLE_OFS                       (9)                             /* !< IDLE Offset */
#define UART_STAT_IDLE_MASK                      ((uint32_t)0x00000200U)         /* !< IDLE mode has been detected in
                                                                                    Idleline-Multiprocessor-Mode. The
                                                                                    IDLE bit is used as an address tag
                                                                                    for each block of characters. In
                                                                                    idle-line multiprocessor format, this
                                                                                    bit is set when a received character
                                                                                    is an address. */
#define UART_STAT_IDLE_CLEARED                   ((uint32_t)0x00000000U)         /* !< IDLE has not been detected before
                                                                                    last received character. (In
                                                                                    idle-line multiprocessor mode). */
#define UART_STAT_IDLE_SET                       ((uint32_t)0x00000200U)         /* !< IDLE has been detected before last
                                                                                    received character. (In idle-line
                                                                                    multiprocessor mode). */
/* UART_STAT[RXFE] Bits */
#define UART_STAT_RXFE_OFS                       (2)                             /* !< RXFE Offset */
#define UART_STAT_RXFE_MASK                      ((uint32_t)0x00000004U)         /* !< UART Receive FIFO Empty  The
                                                                                    meaning of this bit depends on the
                                                                                    state of the FEN bit in the CTL0
                                                                                    register. */
#define UART_STAT_RXFE_CLEARED                   ((uint32_t)0x00000000U)         /* !< The receiver is not empty. */
#define UART_STAT_RXFE_SET                       ((uint32_t)0x00000004U)         /* !< If the FIFO is disabled (FEN is 0),
                                                                                    the receive holding register is
                                                                                    empty. If the FIFO is enabled (FEN is
                                                                                    1), the receive FIFO is empty. */

/* UART_IFLS Bits */
/* UART_IFLS[TXIFLSEL] Bits */
#define UART_IFLS_TXIFLSEL_OFS                   (0)                             /* !< TXIFLSEL Offset */
#define UART_IFLS_TXIFLSEL_MASK                  ((uint32_t)0x00000007U)         /* !< UART Transmit Interrupt FIFO Level
                                                                                    Select  The trigger points for the
                                                                                    transmit interrupt are as follows:
                                                                                    Note: for undefined settings the
                                                                                    default configuration is used. */
#define UART_IFLS_TXIFLSEL_LVL_3_4               ((uint32_t)0x00000001U)         /* !< TX FIFO <= 3/4 empty */
#define UART_IFLS_TXIFLSEL_LVL_1_2               ((uint32_t)0x00000002U)         /* !< TX FIFO <= 1/2 empty (default) */
#define UART_IFLS_TXIFLSEL_LVL_1_4               ((uint32_t)0x00000003U)         /* !< TX FIFO <= 1/4 empty */
#define UART_IFLS_TXIFLSEL_LVL_EMPTY             ((uint32_t)0x00000005U)         /* !< TX FIFO is empty */
#define UART_IFLS_TXIFLSEL_LVL_1                 ((uint32_t)0x00000007U)         /* !< TX FIFO >= 1 entry free Note: esp.
                                                                                    required for DMA Trigger */
/* UART_IFLS[RXIFLSEL] Bits */
#define UART_IFLS_RXIFLSEL_OFS                   (4)                             /* !< RXIFLSEL Offset */
#define UART_IFLS_RXIFLSEL_MASK                  ((uint32_t)0x00000070U)         /* !< UART Receive Interrupt FIFO Level
                                                                                    Select  The trigger points for the
                                                                                    receive interrupt are as follows:
                                                                                    Note:    In ULP domain the trigger
                                                                                    levels are used for:   0: LVL_1_4
                                                                                    4: LVL_FULL   For undefined settings
                                                                                    the default configuration is used. */
#define UART_IFLS_RXIFLSEL_LVL_1_4_RES           ((uint32_t)0x00000000U)         /* !< RX FIFO >= 1/4 full Note: For ULP
                                                                                    Domain */
#define UART_IFLS_RXIFLSEL_LVL_1_4               ((uint32_t)0x00000010U)         /* !< RX FIFO >= 1/4 full */
#define UART_IFLS_RXIFLSEL_LVL_1_2               ((uint32_t)0x00000020U)         /* !< RX FIFO >= 1/2 full (default) */
#define UART_IFLS_RXIFLSEL_LVL_3_4               ((uint32_t)0x00000030U)         /* !< RX FIFO >= 3/4 full */
#define UART_IFLS_RXIFLSEL_LVL_FULL_RES          ((uint32_t)0x00000040U)         /* !< RX FIFO is full Note: For ULP
                                                                                    Domain */
#define UART_IFLS_RXIFLSEL_LVL_FULL              ((uint32_t)0x00000050U)         /* !< RX FIFO is full */
#define UART_IFLS_RXIFLSEL_LVL_1                 ((uint32_t)0x00000070U)         /* !< RX FIFO >= 1 entry available Note:
                                                                                    esp. required for DMA Trigger */
/* UART_IFLS[RXTOSEL] Bits */
#define UART_IFLS_RXTOSEL_OFS                    (8)                             /* !< RXTOSEL Offset */
#define UART_IFLS_RXTOSEL_MASK                   ((uint32_t)0x00000F00U)         /* !< UART Receive Interrupt Timeout
                                                                                    Select. When receiving no start edge
                                                                                    for an additional character within
                                                                                    the set bittimes a RX interrupt is
                                                                                    set even if the FIFO level is not
                                                                                    reached. A value of 0 disables this
                                                                                    function. */
#define UART_IFLS_RXTOSEL_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_IFLS_RXTOSEL_MAXIMUM                ((uint32_t)0x00000F00U)         /* !< Highest possible value */

/* UART_IBRD Bits */
/* UART_IBRD[DIVINT] Bits */
#define UART_IBRD_DIVINT_OFS                     (0)                             /* !< DIVINT Offset */
#define UART_IBRD_DIVINT_MASK                    ((uint32_t)0x0000FFFFU)         /* !< Integer Baud-Rate Divisor */
#define UART_IBRD_DIVINT_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_IBRD_DIVINT_MAXIMUM                 ((uint32_t)0x0000FFFFU)         /* !< Highest possible value */

/* UART_FBRD Bits */
/* UART_FBRD[DIVFRAC] Bits */
#define UART_FBRD_DIVFRAC_OFS                    (0)                             /* !< DIVFRAC Offset */
#define UART_FBRD_DIVFRAC_MASK                   ((uint32_t)0x0000003FU)         /* !< Fractional Baud-Rate Divisor */
#define UART_FBRD_DIVFRAC_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_FBRD_DIVFRAC_MAXIMUM                ((uint32_t)0x0000003FU)         /* !< Highest possible value */

/* UART_GFCTL Bits */
/* UART_GFCTL[AGFSEL] Bits */
#define UART_GFCTL_AGFSEL_OFS                    (9)                             /* !< AGFSEL Offset */
#define UART_GFCTL_AGFSEL_MASK                   ((uint32_t)0x00000600U)         /* !< Analog Glitch Suppression Pulse
                                                                                    Width This field controls the pulse
                                                                                    width select for the analog glitch
                                                                                    suppression on the RX line. See
                                                                                    device datasheet for exact values. */
#define UART_GFCTL_AGFSEL_AGLIT_5                ((uint32_t)0x00000000U)         /* !< Pulses shorter then 5ns length are
                                                                                    filtered. */
#define UART_GFCTL_AGFSEL_AGLIT_10               ((uint32_t)0x00000200U)         /* !< Pulses shorter then 10ns length are
                                                                                    filtered. */
#define UART_GFCTL_AGFSEL_AGLIT_25               ((uint32_t)0x00000400U)         /* !< Pulses shorter then 25ns length are
                                                                                    filtered. */
#define UART_GFCTL_AGFSEL_AGLIT_50               ((uint32_t)0x00000600U)         /* !< Pulses shorter then 50ns length are
                                                                                    filtered. */
/* UART_GFCTL[AGFEN] Bits */
#define UART_GFCTL_AGFEN_OFS                     (8)                             /* !< AGFEN Offset */
#define UART_GFCTL_AGFEN_MASK                    ((uint32_t)0x00000100U)         /* !< Analog Glitch Suppression Enable */
#define UART_GFCTL_AGFEN_DISABLE                 ((uint32_t)0x00000000U)         /* !< Analog Glitch Filter disable */
#define UART_GFCTL_AGFEN_ENABLE                  ((uint32_t)0x00000100U)         /* !< Analog Glitch Filter enable */
/* UART_GFCTL[DGFSEL] Bits */
#define UART_GFCTL_DGFSEL_OFS                    (0)                             /* !< DGFSEL Offset */
#define UART_GFCTL_DGFSEL_MASK                   ((uint32_t)0x0000003FU)         /* !< Glitch Suppression Pulse Width
                                                                                    This field controls the pulse width
                                                                                    select for glitch suppression on the
                                                                                    RX line.  The value programmed in
                                                                                    this field gives the number of cycles
                                                                                    of functional clock up to which the
                                                                                    glitch has to be suppressed on the RX
                                                                                    line.  In IRDA mode: The minimum
                                                                                    pulse length for receive is given by:
                                                                                    t(MIN) = (DGFSEL) / f(IRTXCLK) */
#define UART_GFCTL_DGFSEL_DISABLED               ((uint32_t)0x00000000U)         /* !< Bypass GF */
#define UART_GFCTL_DGFSEL_MAXIMUM                ((uint32_t)0x0000003FU)         /* !< Highest Possible Value */
/* UART_GFCTL[CHAIN] Bits */
#define UART_GFCTL_CHAIN_OFS                     (11)                            /* !< CHAIN Offset */
#define UART_GFCTL_CHAIN_MASK                    ((uint32_t)0x00000800U)         /* !< Analog and digital noise filters
                                                                                    chaining enable.         0 DISABLE:
                                                                                    When 0, chaining is disabled and only
                                                                                    digital filter output is available to
                                                                                    IP logic for sampling         1
                                                                                    ENABLE: When 1, analog and digital
                                                                                    glitch filters are chained and the
                                                                                    output of the combination is made
                                                                                    available to IP logic for sampling */
#define UART_GFCTL_CHAIN_DISABLED                ((uint32_t)0x00000000U)         /* !< Disabled */
#define UART_GFCTL_CHAIN_ENABLED                 ((uint32_t)0x00000800U)         /* !< Enabled */

/* UART_TXDATA Bits */
/* UART_TXDATA[DATA] Bits */
#define UART_TXDATA_DATA_OFS                     (0)                             /* !< DATA Offset */
#define UART_TXDATA_DATA_MASK                    ((uint32_t)0x000000FFU)         /* !< Data Transmitted or Received  Data
                                                                                    that is to be transmitted via the
                                                                                    UART is written to this field.  When
                                                                                    read, this field contains the data
                                                                                    that was received by the UART. */
#define UART_TXDATA_DATA_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_TXDATA_DATA_MAXIMUM                 ((uint32_t)0x000000FFU)         /* !< Highest possible value */

/* UART_RXDATA Bits */
/* UART_RXDATA[DATA] Bits */
#define UART_RXDATA_DATA_OFS                     (0)                             /* !< DATA Offset */
#define UART_RXDATA_DATA_MASK                    ((uint32_t)0x000000FFU)         /* !< Received Data.  When read, this
                                                                                    field contains the data that was
                                                                                    received by the UART. */
#define UART_RXDATA_DATA_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_RXDATA_DATA_MAXIMUM                 ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* UART_RXDATA[FRMERR] Bits */
#define UART_RXDATA_FRMERR_OFS                   (8)                             /* !< FRMERR Offset */
#define UART_RXDATA_FRMERR_MASK                  ((uint32_t)0x00000100U)         /* !< UART Framing Error  Writing to this
                                                                                    bit has no effect. The flag is
                                                                                    cleared by writing 1 to the FRMERR
                                                                                    bit in the UART EVENT ICLR register.
                                                                                    This error is associated with the
                                                                                    character at the top of the FIFO. */
#define UART_RXDATA_FRMERR_CLR                   ((uint32_t)0x00000000U)         /* !< No framing error has occurred */
#define UART_RXDATA_FRMERR_SET                   ((uint32_t)0x00000100U)         /* !< The received character does not
                                                                                    have a valid stop bit sequence, which
                                                                                    is one or two stop bits depending on
                                                                                    the UARTLCRH.STP2 setting (a valid
                                                                                    stop bit is 1). */
/* UART_RXDATA[PARERR] Bits */
#define UART_RXDATA_PARERR_OFS                   (9)                             /* !< PARERR Offset */
#define UART_RXDATA_PARERR_MASK                  ((uint32_t)0x00000200U)         /* !< UART Parity Error   Writing to this
                                                                                    bit has no effect. The flag is
                                                                                    cleared by writing 1 to the PARERR
                                                                                    bit in the UART EVENT ICLR register. */
#define UART_RXDATA_PARERR_CLR                   ((uint32_t)0x00000000U)         /* !< No parity error has occurred */
#define UART_RXDATA_PARERR_SET                   ((uint32_t)0x00000200U)         /* !< The parity of the received data
                                                                                    character does not match the parity
                                                                                    defined by bits 2 and 7 of the
                                                                                    UARTLCRH register. */
/* UART_RXDATA[BRKERR] Bits */
#define UART_RXDATA_BRKERR_OFS                   (10)                            /* !< BRKERR Offset */
#define UART_RXDATA_BRKERR_MASK                  ((uint32_t)0x00000400U)         /* !< UART Break Error  Writing to this
                                                                                    bit has no effect. The flag is
                                                                                    cleared by writing 1 to the BRKERR
                                                                                    bit in the UART EVENT ICLR register.
                                                                                    This error is associated with the
                                                                                    character at the top of the FIFO.
                                                                                    When a break occurs, only one 0
                                                                                    character is loaded into the FIFO.
                                                                                    The next character is only enabled
                                                                                    after the receive data input goes to
                                                                                    a 1 (marking state) and the next
                                                                                    valid start bit is received. */
#define UART_RXDATA_BRKERR_CLR                   ((uint32_t)0x00000000U)         /* !< No break condition has occurred */
#define UART_RXDATA_BRKERR_SET                   ((uint32_t)0x00000400U)         /* !< A break condition has been
                                                                                    detected, indicating that the receive
                                                                                    data input was held low for longer
                                                                                    than a full-word transmission time
                                                                                    (defined as start, data, parity, and
                                                                                    stop bits). */
/* UART_RXDATA[OVRERR] Bits */
#define UART_RXDATA_OVRERR_OFS                   (11)                            /* !< OVRERR Offset */
#define UART_RXDATA_OVRERR_MASK                  ((uint32_t)0x00000800U)         /* !< UART Receive Overrun Error  Writing
                                                                                    to this bit has no effect. The flag
                                                                                    is cleared by writing 1 to the OVRERR
                                                                                    bit in the UART EVENT ICLR register.
                                                                                    In case of a receive FIFO overflow,
                                                                                    the FIFO contents remain valid
                                                                                    because no further data is written
                                                                                    when the FIFO is full. Only the
                                                                                    contents of the shift register are
                                                                                    overwritten. The CPU must read the
                                                                                    data in order to empty the FIFO. */
#define UART_RXDATA_OVRERR_CLR                   ((uint32_t)0x00000000U)         /* !< No data has been lost due to a
                                                                                    receive overrun. */
#define UART_RXDATA_OVRERR_SET                   ((uint32_t)0x00000800U)         /* !< New data was received but could not
                                                                                    be stored, because the previous data
                                                                                    was not read (resulting in data
                                                                                    loss). */
/* UART_RXDATA[NERR] Bits */
#define UART_RXDATA_NERR_OFS                     (12)                            /* !< NERR Offset */
#define UART_RXDATA_NERR_MASK                    ((uint32_t)0x00001000U)         /* !< Noise Error. Writing to this bit
                                                                                    has no effect. The flag is cleared by
                                                                                    writing 1 to the NERR bit in the UART
                                                                                    EVENT ICLR register. */
#define UART_RXDATA_NERR_CLR                     ((uint32_t)0x00000000U)         /* !< No noise error occured */
#define UART_RXDATA_NERR_SET                     ((uint32_t)0x00001000U)         /* !< Noise error occured during majority
                                                                                    voting */

/* UART_LINCNT Bits */
/* UART_LINCNT[VALUE] Bits */
#define UART_LINCNT_VALUE_OFS                    (0)                             /* !< VALUE Offset */
#define UART_LINCNT_VALUE_MASK                   ((uint32_t)0x0000FFFFU)         /* !< 16 bit up counter clocked by the
                                                                                    functional clock of the UART. */
#define UART_LINCNT_VALUE_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_LINCNT_VALUE_MAXIMUM                ((uint32_t)0x0000FFFFU)         /* !< Highest possible value */

/* UART_LINCTL Bits */
/* UART_LINCTL[CTRENA] Bits */
#define UART_LINCTL_CTRENA_OFS                   (0)                             /* !< CTRENA Offset */
#define UART_LINCTL_CTRENA_MASK                  ((uint32_t)0x00000001U)         /* !< LIN Counter Enable. LIN counter
                                                                                    will only count when enabled. */
#define UART_LINCTL_CTRENA_DISABLE               ((uint32_t)0x00000000U)         /* !< Counter disabled */
#define UART_LINCTL_CTRENA_ENABLE                ((uint32_t)0x00000001U)         /* !< Counter enabled */
/* UART_LINCTL[ZERONE] Bits */
#define UART_LINCTL_ZERONE_OFS                   (1)                             /* !< ZERONE Offset */
#define UART_LINCTL_ZERONE_MASK                  ((uint32_t)0x00000002U)         /* !< Zero on negative Edge of RXD. When
                                                                                    enabled the counter is set to 0 and
                                                                                    starts counting on a negative edge of
                                                                                    RXD */
#define UART_LINCTL_ZERONE_DISABLE               ((uint32_t)0x00000000U)         /* !< Zero on negative edge disabled */
#define UART_LINCTL_ZERONE_ENABLE                ((uint32_t)0x00000002U)         /* !< Zero on negative edge enabled */
/* UART_LINCTL[CNTRXLOW] Bits */
#define UART_LINCTL_CNTRXLOW_OFS                 (2)                             /* !< CNTRXLOW Offset */
#define UART_LINCTL_CNTRXLOW_MASK                ((uint32_t)0x00000004U)         /* !< Count while low Signal on RXD When
                                                                                    counter is enabled and the signal on
                                                                                    RXD is low, the counter increments. */
#define UART_LINCTL_CNTRXLOW_DISABLE             ((uint32_t)0x00000000U)         /* !< Count while low Signal on UARTxRXD
                                                                                    disabled */
#define UART_LINCTL_CNTRXLOW_ENABLE              ((uint32_t)0x00000004U)         /* !< Count while low Signal on UARTxRXD
                                                                                    enabled */
/* UART_LINCTL[LINC0CAP] Bits */
#define UART_LINCTL_LINC0CAP_OFS                 (4)                             /* !< LINC0CAP Offset */
#define UART_LINCTL_LINC0CAP_MASK                ((uint32_t)0x00000010U)         /* !< Capture Counter on negative RXD
                                                                                    Edge. When enabled the counter value
                                                                                    is captured to LINC0 register on each
                                                                                    negative RXD edge. A LINC0 interrupt
                                                                                    is triggered when enabled. */
#define UART_LINCTL_LINC0CAP_DISABLE             ((uint32_t)0x00000000U)         /* !< Capture counter on negative
                                                                                    UARTxRXD edge disabled */
#define UART_LINCTL_LINC0CAP_ENABLE              ((uint32_t)0x00000010U)         /* !< Capture counter on negative
                                                                                    UARTxRXD edge enabled */
/* UART_LINCTL[LINC1CAP] Bits */
#define UART_LINCTL_LINC1CAP_OFS                 (5)                             /* !< LINC1CAP Offset */
#define UART_LINCTL_LINC1CAP_MASK                ((uint32_t)0x00000020U)         /* !< Capture Counter on positive RXD
                                                                                    Edge. When enabled the counter value
                                                                                    is captured to LINC1 register on each
                                                                                    positive RXD edge. A LINC1 interrupt
                                                                                    is triggered when enabled. */
#define UART_LINCTL_LINC1CAP_DISABLE             ((uint32_t)0x00000000U)         /* !< Capture counter on positive
                                                                                    UARTxRXD edge disabled */
#define UART_LINCTL_LINC1CAP_ENABLE              ((uint32_t)0x00000020U)         /* !< Capture counter on positive
                                                                                    UARTxRXD edge enabled */
/* UART_LINCTL[LINC0_MATCH] Bits */
#define UART_LINCTL_LINC0_MATCH_OFS              (6)                             /* !< LINC0_MATCH Offset */
#define UART_LINCTL_LINC0_MATCH_MASK             ((uint32_t)0x00000040U)         /* !< Counter Compare Match Mode  When
                                                                                    this bit is set to 1 a counter
                                                                                    compare match with LINC0 register
                                                                                    triggers an LINC0 interrupt when
                                                                                    enabled. */
#define UART_LINCTL_LINC0_MATCH_DISABLE          ((uint32_t)0x00000000U)         /* !< Counter compare match mode disabled
                                                                                    (capture mode enabled) */
#define UART_LINCTL_LINC0_MATCH_ENABLE           ((uint32_t)0x00000040U)         /* !< Counter compare match enabled
                                                                                    (capture mode disabled) */

/* UART_LINC0 Bits */
/* UART_LINC0[DATA] Bits */
#define UART_LINC0_DATA_OFS                      (0)                             /* !< DATA Offset */
#define UART_LINC0_DATA_MASK                     ((uint32_t)0x0000FFFFU)         /* !< 16 Bit Capture / Compare Register
                                                                                    Captures current LINCTR value on RXD
                                                                                    falling edge and can generate a LINC0
                                                                                    interrupt when capture is enabled
                                                                                    (LINC0CAP = 1).  If compare mode is
                                                                                    enabled (LINC0_MATCH = 1), a counter
                                                                                    match can generate a LINC0 interrupt. */
#define UART_LINC0_DATA_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_LINC0_DATA_MAXIMUM                  ((uint32_t)0x0000FFFFU)         /* !< Highest possible value */

/* UART_LINC1 Bits */
/* UART_LINC1[DATA] Bits */
#define UART_LINC1_DATA_OFS                      (0)                             /* !< DATA Offset */
#define UART_LINC1_DATA_MASK                     ((uint32_t)0x0000FFFFU)         /* !< 16 Bit Capture / Compare Register
                                                                                    Captures current LINCTR value on RXD
                                                                                    rising edge and can generate a LINC1
                                                                                    interrupt when capture is enabled
                                                                                    (LINC1CAP = 1) */
#define UART_LINC1_DATA_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_LINC1_DATA_MAXIMUM                  ((uint32_t)0x0000FFFFU)         /* !< Highest possible value */

/* UART_IRCTL Bits */
/* UART_IRCTL[IRTXPL] Bits */
#define UART_IRCTL_IRTXPL_OFS                    (2)                             /* !< IRTXPL Offset */
#define UART_IRCTL_IRTXPL_MASK                   ((uint32_t)0x000000FCU)         /* !< Transmit pulse length. Pulse length
                                                                                    t(PULSE) = (IRTXPLx + 1) / [2 *
                                                                                    f(IRTXCLK)] (IRTXCLK = functional
                                                                                    clock of the UART) */
#define UART_IRCTL_IRTXPL_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_IRCTL_IRTXPL_MAXIMUM                ((uint32_t)0x000000FCU)         /* !< Highest possible value */
/* UART_IRCTL[IRRXPL] Bits */
#define UART_IRCTL_IRRXPL_OFS                    (9)                             /* !< IRRXPL Offset */
#define UART_IRCTL_IRRXPL_MASK                   ((uint32_t)0x00000200U)         /* !< IrDA receive input UCAxRXD polarity */
#define UART_IRCTL_IRRXPL_HIGH                   ((uint32_t)0x00000000U)         /* !< IrDA transceiver delivers a high
                                                                                    pulse when a light pulse is seen */
#define UART_IRCTL_IRRXPL_LOW                    ((uint32_t)0x00000200U)         /* !< IrDA transceiver delivers a low
                                                                                    pulse when a light pulse is seen */
/* UART_IRCTL[IREN] Bits */
#define UART_IRCTL_IREN_OFS                      (0)                             /* !< IREN Offset */
#define UART_IRCTL_IREN_MASK                     ((uint32_t)0x00000001U)         /* !< IrDA encoder/decoder enable */
#define UART_IRCTL_IREN_DISABLE                  ((uint32_t)0x00000000U)         /* !< IrDA encoder/decoder disabled */
#define UART_IRCTL_IREN_ENABLE                   ((uint32_t)0x00000001U)         /* !< IrDA encoder/decoder enabled */
/* UART_IRCTL[IRTXCLK] Bits */
#define UART_IRCTL_IRTXCLK_OFS                   (1)                             /* !< IRTXCLK Offset */
#define UART_IRCTL_IRTXCLK_MASK                  ((uint32_t)0x00000002U)         /* !< IrDA transmit pulse clock select */
#define UART_IRCTL_IRTXCLK_BITCLK                ((uint32_t)0x00000000U)         /* !< IrDA encode data is based on the
                                                                                    functional clock. */
#define UART_IRCTL_IRTXCLK_BRCLK                 ((uint32_t)0x00000002U)         /* !< IrDA encode data is based on the
                                                                                    Baud Rate clock< when select 8x
                                                                                    oversampling, the IRTXPL cycle should
                                                                                    less 8;  when select 16x
                                                                                    oversampling, the IRTXPL cycle should
                                                                                    less 16. */

/* UART_AMASK Bits */
/* UART_AMASK[VALUE] Bits */
#define UART_AMASK_VALUE_OFS                     (0)                             /* !< VALUE Offset */
#define UART_AMASK_VALUE_MASK                    ((uint32_t)0x000000FFU)         /* !< Self Address Mask for 9-Bit Mode
                                                                                    This field contains the address mask
                                                                                    that creates a set of addresses that
                                                                                    should be matched.  A 0 bit in the
                                                                                    MSK bitfield configures, that the
                                                                                    corresponding bit in the ADDR
                                                                                    bitfield of the UARTxADDR register is
                                                                                    don't care. A 1 bit in the MSK
                                                                                    bitfield configures, that the
                                                                                    corresponding bit in the ADDR
                                                                                    bitfield of the UARTxADDR register
                                                                                    must match. */
#define UART_AMASK_VALUE_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_AMASK_VALUE_MAXIMUM                 ((uint32_t)0x000000FFU)         /* !< Highest possible value */

/* UART_ADDR Bits */
/* UART_ADDR[VALUE] Bits */
#define UART_ADDR_VALUE_OFS                      (0)                             /* !< VALUE Offset */
#define UART_ADDR_VALUE_MASK                     ((uint32_t)0x000000FFU)         /* !< Self Address for 9-Bit Mode  This
                                                                                    field contains the address that
                                                                                    should be matched when UARTxAMASK is
                                                                                    FFh. */
#define UART_ADDR_VALUE_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define UART_ADDR_VALUE_MAXIMUM                  ((uint32_t)0x000000FFU)         /* !< Highest possible value */

/* UART_CLKDIV2 Bits */
/* UART_CLKDIV2[RATIO] Bits */
#define UART_CLKDIV2_RATIO_OFS                   (0)                             /* !< RATIO Offset */
#define UART_CLKDIV2_RATIO_MASK                  ((uint32_t)0x00000007U)         /* !< Selects divide ratio of module
                                                                                    clock */
#define UART_CLKDIV2_RATIO_DIV_BY_1              ((uint32_t)0x00000000U)         /* !< Do not divide clock source */
#define UART_CLKDIV2_RATIO_DIV_BY_2              ((uint32_t)0x00000001U)         /* !< Divide clock source by 2 */
#define UART_CLKDIV2_RATIO_DIV_BY_3              ((uint32_t)0x00000002U)         /* !< Divide clock source by 3 */
#define UART_CLKDIV2_RATIO_DIV_BY_4              ((uint32_t)0x00000003U)         /* !< Divide clock source by 4 */
#define UART_CLKDIV2_RATIO_DIV_BY_5              ((uint32_t)0x00000004U)         /* !< Divide clock source by 5 */
#define UART_CLKDIV2_RATIO_DIV_BY_6              ((uint32_t)0x00000005U)         /* !< Divide clock source by 6 */
#define UART_CLKDIV2_RATIO_DIV_BY_7              ((uint32_t)0x00000006U)         /* !< Divide clock source by 7 */
#define UART_CLKDIV2_RATIO_DIV_BY_8              ((uint32_t)0x00000007U)         /* !< Divide clock source by 8 */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_uart__include */
