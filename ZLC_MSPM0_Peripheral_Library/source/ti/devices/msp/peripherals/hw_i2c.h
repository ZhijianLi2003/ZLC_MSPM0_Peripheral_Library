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

#ifndef ti_devices_msp_peripherals_hw_i2c__include
#define ti_devices_msp_peripherals_hw_i2c__include

/* Filename: hw_i2c.h */
/* Revised: 2023-06-14 10:18:34 */
/* Revision: 638bba738cb61945408cf5e8bcfecf08798f4b8b */

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
* I2C Registers
******************************************************************************/
#define I2C_SLAVE_OFS                            ((uint32_t)0x00001250U)
#define I2C_MASTER_OFS                           ((uint32_t)0x00001210U)
#define I2C_DMA_TRIG0_OFS                        ((uint32_t)0x00001080U)
#define I2C_DMA_TRIG1_OFS                        ((uint32_t)0x00001050U)
#define I2C_CPU_INT_OFS                          ((uint32_t)0x00001020U)
#define I2C_GPRCM_OFS                            ((uint32_t)0x00000800U)


/** @addtogroup I2C_SLAVE
  @{
*/

typedef struct {
  __IO uint32_t SOAR;                              /* !< (@ 0x00001250) I2C Target Own Address */
  __IO uint32_t SOAR2;                             /* !< (@ 0x00001254) I2C Target Own Address 2 */
  __IO uint32_t SCTR;                              /* !< (@ 0x00001258) I2C Target Control Register */
  __I  uint32_t SSR;                               /* !< (@ 0x0000125C) I2C Target Status Register */
  __I  uint32_t SRXDATA;                           /* !< (@ 0x00001260) I2C Target RXData */
  __IO uint32_t STXDATA;                           /* !< (@ 0x00001264) I2C Target TXData */
  __IO uint32_t SACKCTL;                           /* !< (@ 0x00001268) I2C Target ACK Control */
  __IO uint32_t SFIFOCTL;                          /* !< (@ 0x0000126C) I2C Target FIFO Control */
  __I  uint32_t SFIFOSR;                           /* !< (@ 0x00001270) I2C Target FIFO Status Register */
  __IO uint32_t TARGET_PECCTL;                     /* !< (@ 0x00001274) I2C Target PEC control register */
  __I  uint32_t TARGET_PECSR;                      /* !< (@ 0x00001278) I2C Target PEC status register */
} I2C_SLAVE_Regs;

/*@}*/ /* end of group I2C_SLAVE */

/** @addtogroup I2C_MASTER
  @{
*/

typedef struct {
  __IO uint32_t MSA;                               /* !< (@ 0x00001210) I2C Controller Target Address Register */
  __IO uint32_t MCTR;                              /* !< (@ 0x00001214) I2C Controller Control Register */
  __I  uint32_t MSR;                               /* !< (@ 0x00001218) I2C Controller Status Register */
  __I  uint32_t MRXDATA;                           /* !< (@ 0x0000121C) I2C Controller RXData */
  __IO uint32_t MTXDATA;                           /* !< (@ 0x00001220) I2C Controller TXData */
  __IO uint32_t MTPR;                              /* !< (@ 0x00001224) I2C Controller Timer Period */
  __IO uint32_t MCR;                               /* !< (@ 0x00001228) I2C Controller Configuration */
       uint32_t RESERVED0[2];
  __I  uint32_t MBMON;                             /* !< (@ 0x00001234) I2C Controller Bus Monitor */
  __IO uint32_t MFIFOCTL;                          /* !< (@ 0x00001238) I2C Controller FIFO Control */
  __I  uint32_t MFIFOSR;                           /* !< (@ 0x0000123C) I2C Controller FIFO Status Register */
  __IO uint32_t CONTROLLER_I2CPECCTL;              /* !< (@ 0x00001240) I2C Controller PEC control register */
  __I  uint32_t CONTROLLER_PECSR;                  /* !< (@ 0x00001244) I2C Controller PEC status register */
} I2C_MASTER_Regs;

/*@}*/ /* end of group I2C_MASTER */

/** @addtogroup I2C_DMA_TRIG0
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
} I2C_DMA_TRIG0_Regs;

/*@}*/ /* end of group I2C_DMA_TRIG0 */

/** @addtogroup I2C_DMA_TRIG1
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
} I2C_DMA_TRIG1_Regs;

/*@}*/ /* end of group I2C_DMA_TRIG1 */

/** @addtogroup I2C_CPU_INT
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
} I2C_CPU_INT_Regs;

/*@}*/ /* end of group I2C_CPU_INT */

/** @addtogroup I2C_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00000808) Peripheral Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} I2C_GPRCM_Regs;

/*@}*/ /* end of group I2C_GPRCM */

/** @addtogroup I2C
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  I2C_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED1[506];
  __IO uint32_t CLKDIV;                            /* !< (@ 0x00001000) Clock Divider */
  __IO uint32_t CLKSEL;                            /* !< (@ 0x00001004) Clock Select for Ultra Low Power peripherals */
       uint32_t RESERVED2[4];
  __IO uint32_t PDBGCTL;                           /* !< (@ 0x00001018) Peripheral Debug Control */
       uint32_t RESERVED3;
  I2C_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED4;
  I2C_DMA_TRIG1_Regs  DMA_TRIG1;                         /* !< (@ 0x00001050) */
       uint32_t RESERVED5;
  I2C_DMA_TRIG0_Regs  DMA_TRIG0;                         /* !< (@ 0x00001080) */
       uint32_t RESERVED6[13];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
  __IO uint32_t INTCTL;                            /* !< (@ 0x000010E4) Interrupt control register */
       uint32_t RESERVED7[5];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
       uint32_t RESERVED8[64];
  __IO uint32_t GFCTL;                             /* !< (@ 0x00001200) I2C Glitch Filter Control */
  __IO uint32_t TIMEOUT_CTL;                       /* !< (@ 0x00001204) I2C Timeout Count Control Register */
  __I  uint32_t TIMEOUT_CNT;                       /* !< (@ 0x00001208) I2C Timeout Count Register */
       uint32_t RESERVED9;
  I2C_MASTER_Regs  MASTER;                            /* !< (@ 0x00001210) */
       uint32_t RESERVED10[2];
  I2C_SLAVE_Regs  SLAVE;                             /* !< (@ 0x00001250) */
} I2C_Regs;

/*@}*/ /* end of group I2C */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* I2C Register Control Bits
******************************************************************************/

/* I2C_SOAR Bits */
/* I2C_SOAR[OAR] Bits */
#define I2C_SOAR_OAR_OFS                         (0)                             /* !< OAR Offset */
#define I2C_SOAR_OAR_MASK                        ((uint32_t)0x000003FFU)         /* !< I2C Target Own Address: This field
                                                                                    specifies bits A9 through A0 of the
                                                                                    Target address. In 7-bit addressing
                                                                                    mode as selected by I2CSOAR.MODE bit,
                                                                                    the top 3 bits are don't care */
#define I2C_SOAR_OAR_MINIMUM                     ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_SOAR_OAR_MAXIMUM                     ((uint32_t)0x000003FFU)         /* !< Highest possible value */
/* I2C_SOAR[OAREN] Bits */
#define I2C_SOAR_OAREN_OFS                       (14)                            /* !< OAREN Offset */
#define I2C_SOAR_OAREN_MASK                      ((uint32_t)0x00004000U)         /* !< I2C Target Own Address Enable */
#define I2C_SOAR_OAREN_DISABLE                   ((uint32_t)0x00000000U)         /* !< Disable OAR address */
#define I2C_SOAR_OAREN_ENABLE                    ((uint32_t)0x00004000U)         /* !< Enable OAR address */
/* I2C_SOAR[SMODE] Bits */
#define I2C_SOAR_SMODE_OFS                       (15)                            /* !< SMODE Offset */
#define I2C_SOAR_SMODE_MASK                      ((uint32_t)0x00008000U)         /* !< This bit selects the adressing mode
                                                                                    to be used in Target mode. When 0,
                                                                                    7-bit addressing is used. When 1,
                                                                                    10-bit addressing is used. */
#define I2C_SOAR_SMODE_MODE7                     ((uint32_t)0x00000000U)         /* !< Enable 7-bit addressing */
#define I2C_SOAR_SMODE_MODE10                    ((uint32_t)0x00008000U)         /* !< Enable 10-bit addressing */

/* I2C_SOAR2 Bits */
/* I2C_SOAR2[OAR2] Bits */
#define I2C_SOAR2_OAR2_OFS                       (0)                             /* !< OAR2 Offset */
#define I2C_SOAR2_OAR2_MASK                      ((uint32_t)0x0000007FU)         /* !< I2C Target Own Address 2This field
                                                                                    specifies the alternate OAR2 address. */
#define I2C_SOAR2_OAR2_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_SOAR2_OAR2_MAXIMUM                   ((uint32_t)0x0000007FU)         /* !< Highest possible value */
/* I2C_SOAR2[OAR2EN] Bits */
#define I2C_SOAR2_OAR2EN_OFS                     (7)                             /* !< OAR2EN Offset */
#define I2C_SOAR2_OAR2EN_MASK                    ((uint32_t)0x00000080U)         /* !< I2C Target Own Address 2 Enable */
#define I2C_SOAR2_OAR2EN_DISABLE                 ((uint32_t)0x00000000U)         /* !< The alternate address is disabled. */
#define I2C_SOAR2_OAR2EN_ENABLE                  ((uint32_t)0x00000080U)         /* !< Enables the use of the alternate
                                                                                    address in the OAR2 field. */
/* I2C_SOAR2[OAR2_MASK] Bits */
#define I2C_SOAR2_OAR2_MASK_OFS                  (16)                            /* !< OAR2_MASK Offset */
#define I2C_SOAR2_OAR2_MASK_MASK                 ((uint32_t)0x007F0000U)         /* !< I2C Target Own Address 2 Mask: This
                                                                                    field specifies bits A6 through A0 of
                                                                                    the Target address. The bits with
                                                                                    value 1 in SOAR2.OAR2_MASK field will
                                                                                    make the corresponding incoming
                                                                                    address bits to match by default
                                                                                    regardless of the value inside
                                                                                    SOAR2.OAR2 i.e. corresponding
                                                                                    SOAR2.OAR2 bit is a dont care. */
#define I2C_SOAR2_OAR2_MASK_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum Value */
#define I2C_SOAR2_OAR2_MASK_MAXIMUM              ((uint32_t)0x007F0000U)         /* !< Maximum Value */

/* I2C_SCTR Bits */
/* I2C_SCTR[ACTIVE] Bits */
#define I2C_SCTR_ACTIVE_OFS                      (0)                             /* !< ACTIVE Offset */
#define I2C_SCTR_ACTIVE_MASK                     ((uint32_t)0x00000001U)         /* !< Device Active. Setting this bit
                                                                                    enables the Target functionality. */
#define I2C_SCTR_ACTIVE_DISABLE                  ((uint32_t)0x00000000U)         /* !< Disables the I2C Target operation. */
#define I2C_SCTR_ACTIVE_ENABLE                   ((uint32_t)0x00000001U)         /* !< Enables the I2C Target operation. */
/* I2C_SCTR[GENCALL] Bits */
#define I2C_SCTR_GENCALL_OFS                     (1)                             /* !< GENCALL Offset */
#define I2C_SCTR_GENCALL_MASK                    ((uint32_t)0x00000002U)         /* !< General call response enable Modify
                                                                                    only when UCSWRST = 1. 0b = Do not
                                                                                    respond to a general call 1b =
                                                                                    Respond to a general call */
#define I2C_SCTR_GENCALL_DISABLE                 ((uint32_t)0x00000000U)         /* !< Do not respond to a general call */
#define I2C_SCTR_GENCALL_ENABLE                  ((uint32_t)0x00000002U)         /* !< Respond to a general call */
/* I2C_SCTR[SCLKSTRETCH] Bits */
#define I2C_SCTR_SCLKSTRETCH_OFS                 (2)                             /* !< SCLKSTRETCH Offset */
#define I2C_SCTR_SCLKSTRETCH_MASK                ((uint32_t)0x00000004U)         /* !< Target Clock Stretch Enable */
#define I2C_SCTR_SCLKSTRETCH_DISABLE             ((uint32_t)0x00000000U)         /* !< Target clock stretching is disabled */
#define I2C_SCTR_SCLKSTRETCH_ENABLE              ((uint32_t)0x00000004U)         /* !< Target clock stretching is enabled */
/* I2C_SCTR[TXEMPTY_ON_TREQ] Bits */
#define I2C_SCTR_TXEMPTY_ON_TREQ_OFS             (3)                             /* !< TXEMPTY_ON_TREQ Offset */
#define I2C_SCTR_TXEMPTY_ON_TREQ_MASK            ((uint32_t)0x00000008U)         /* !< Tx Empty Interrupt on TREQ */
#define I2C_SCTR_TXEMPTY_ON_TREQ_DISABLE         ((uint32_t)0x00000000U)         /* !< When 0, RIS:STXEMPTY will be set
                                                                                    when only the Target TX FIFO is
                                                                                    empty. This allows the STXEMPTY
                                                                                    interrupt to be used to indicate that
                                                                                    the I2C bus is being clock stretched
                                                                                    and that Target TX data is required. */
#define I2C_SCTR_TXEMPTY_ON_TREQ_ENABLE          ((uint32_t)0x00000008U)         /* !< When 1, RIS:STXEMPTY will be set
                                                                                    when the Target State Machine is in
                                                                                    the TX_WAIT state which occurs when
                                                                                    the TX FIFO is empty AND the I2C
                                                                                    transaction is clock stretched
                                                                                    waiting for the FIFO to receive data. */
/* I2C_SCTR[TXTRIG_TXMODE] Bits */
#define I2C_SCTR_TXTRIG_TXMODE_OFS               (4)                             /* !< TXTRIG_TXMODE Offset */
#define I2C_SCTR_TXTRIG_TXMODE_MASK              ((uint32_t)0x00000010U)         /* !< Tx Trigger when Target FSM is in Tx
                                                                                    Mode */
#define I2C_SCTR_TXTRIG_TXMODE_DISABLE           ((uint32_t)0x00000000U)         /* !< No special behavior */
#define I2C_SCTR_TXTRIG_TXMODE_ENABLE            ((uint32_t)0x00000010U)         /* !< When 1, RIS:TXFIFOTRG will be set
                                                                                    when the Target TX FIFO has reached
                                                                                    the trigger level AND the Target
                                                                                    State Machine is in the TXMODE as
                                                                                    defined in the SSR register. When
                                                                                    cleared RIS:TXFIFOTRG will be set
                                                                                    when the Target TX FIFO is at or
                                                                                    above the trigger level. This setting
                                                                                    can be used to hold off the TX DMA
                                                                                    until a transaction starts. This
                                                                                    allows the DMA to be configured when
                                                                                    the I2C is idle but have it wait till
                                                                                    the transaction starts to load the
                                                                                    Target TX FIFO, so it can load from a
                                                                                    memory buffer that might be changing
                                                                                    over time. */
/* I2C_SCTR[TXWAIT_STALE_TXFIFO] Bits */
#define I2C_SCTR_TXWAIT_STALE_TXFIFO_OFS         (5)                             /* !< TXWAIT_STALE_TXFIFO Offset */
#define I2C_SCTR_TXWAIT_STALE_TXFIFO_MASK        ((uint32_t)0x00000020U)         /* !< Tx transfer waits when stale data
                                                                                    in Tx FIFO. This prevents stale bytes
                                                                                    left in the TX FIFO from
                                                                                    automatically being sent on the next
                                                                                    I2C packet. Note: this should be used
                                                                                    with TXEMPTY_ON_TREQ set to prevent
                                                                                    the Target State Machine from waiting
                                                                                    for TX FIFO data without an interrupt
                                                                                    notification when the FIFO data is
                                                                                    stale. */
#define I2C_SCTR_TXWAIT_STALE_TXFIFO_DISABLE     ((uint32_t)0x00000000U)         /* !< When 0, the TX FIFO empty signal to
                                                                                    the Target State Machine indicates
                                                                                    that the TX FIFO is empty. */
#define I2C_SCTR_TXWAIT_STALE_TXFIFO_ENABLE      ((uint32_t)0x00000020U)         /* !< When 1, the TX FIFO empty signal to
                                                                                    the Target State Machine will
                                                                                    indicate that the TX FIFO is empty or
                                                                                    that the TX FIFO data is stale. The
                                                                                    TX FIFO data is determined to be
                                                                                    stale when there is data in the TX
                                                                                    FIFO when the Target State Machine
                                                                                    leaves the TXMODE as defined in the
                                                                                    SSR register. This can occur is a
                                                                                    Stop or timeout occur when there are
                                                                                    bytes left in the TX FIFO. */
/* I2C_SCTR[RXFULL_ON_RREQ] Bits */
#define I2C_SCTR_RXFULL_ON_RREQ_OFS              (6)                             /* !< RXFULL_ON_RREQ Offset */
#define I2C_SCTR_RXFULL_ON_RREQ_MASK             ((uint32_t)0x00000040U)         /* !< Rx full interrupt generated on RREQ
                                                                                    condition as indicated in SSR */
#define I2C_SCTR_RXFULL_ON_RREQ_DISABLE          ((uint32_t)0x00000000U)         /* !< When 0, RIS:SRXFULL will be set
                                                                                    when only the Target RX FIFO is full.
                                                                                    This allows the SRXFULL interrupt to
                                                                                    be used to indicate that the I2C bus
                                                                                    is being clock stretched and that the
                                                                                    FW must either read the RX FIFO or
                                                                                    ACK/NACK the current Rx byte. */
#define I2C_SCTR_RXFULL_ON_RREQ_ENABLE           ((uint32_t)0x00000040U)         /* !< When 1, RIS:SRXFULL will be set
                                                                                    when the Target State Machine is in
                                                                                    the RX_WAIT or RX_ACK_WAIT states
                                                                                    which occurs when the I2C transaction
                                                                                    is clock stretched because the RX
                                                                                    FIFO is full or the ACKOEN has been
                                                                                    set and the state machine is waiting
                                                                                    for FW to ACK/NACK the current byte. */
/* I2C_SCTR[EN_DEFHOSTADR] Bits */
#define I2C_SCTR_EN_DEFHOSTADR_OFS               (7)                             /* !< EN_DEFHOSTADR Offset */
#define I2C_SCTR_EN_DEFHOSTADR_MASK              ((uint32_t)0x00000080U)         /* !< Enable Default Host Address */
#define I2C_SCTR_EN_DEFHOSTADR_DISABLE           ((uint32_t)0x00000000U)         /* !< When this bit is 0, the default
                                                                                    host address is not matched NOTE: it
                                                                                    may still be matched if programmed
                                                                                    inside SOAR/SOAR2 */
#define I2C_SCTR_EN_DEFHOSTADR_ENABLE            ((uint32_t)0x00000080U)         /* !< When this bit is 1, default host
                                                                                    address of 7h000_1000 is always
                                                                                    matched by the Target address match
                                                                                    logic. */
/* I2C_SCTR[EN_ALRESPADR] Bits */
#define I2C_SCTR_EN_ALRESPADR_OFS                (8)                             /* !< EN_ALRESPADR Offset */
#define I2C_SCTR_EN_ALRESPADR_MASK               ((uint32_t)0x00000100U)         /* !< Enable Alert Response Address */
#define I2C_SCTR_EN_ALRESPADR_DISABLE            ((uint32_t)0x00000000U)         /* !< When this bit is 0, the alert
                                                                                    response address is not matched.
                                                                                    NOTE: it may still be matched if
                                                                                    programmed inside SOAR/SOAR2 */
#define I2C_SCTR_EN_ALRESPADR_ENABLE             ((uint32_t)0x00000100U)         /* !< When this bit is 1, alert response
                                                                                    address of 7h000_1100 is always
                                                                                    matched by the Target address match
                                                                                    logic. */
/* I2C_SCTR[EN_DEFDEVADR] Bits */
#define I2C_SCTR_EN_DEFDEVADR_OFS                (9)                             /* !< EN_DEFDEVADR Offset */
#define I2C_SCTR_EN_DEFDEVADR_MASK               ((uint32_t)0x00000200U)         /* !< Enable Deault device address */
#define I2C_SCTR_EN_DEFDEVADR_DISABLE            ((uint32_t)0x00000000U)         /* !< When this bit is 0, the default
                                                                                    device address is not matched. NOTE:
                                                                                    it may still be matched if programmed
                                                                                    inside SOAR/SOAR2. */
#define I2C_SCTR_EN_DEFDEVADR_ENABLE             ((uint32_t)0x00000200U)         /* !< When this bit is 1, default device
                                                                                    address of 7h110_0001 is always
                                                                                    matched by the Target address match
                                                                                    logic. */
/* I2C_SCTR[SWUEN] Bits */
#define I2C_SCTR_SWUEN_OFS                       (10)                            /* !< SWUEN Offset */
#define I2C_SCTR_SWUEN_MASK                      ((uint32_t)0x00000400U)         /* !< Target Wakeup Enable */
#define I2C_SCTR_SWUEN_DISABLE                   ((uint32_t)0x00000000U)         /* !< When 0, the Target is not allowed
                                                                                    to clock stretch on START detection */
#define I2C_SCTR_SWUEN_ENABLE                    ((uint32_t)0x00000400U)         /* !< When 1, the Target is allowed to
                                                                                    clock stretch on START detection and
                                                                                    wait for faster clock to be
                                                                                    abvailable. This allows clean wake up
                                                                                    support for I2C in low power mode use
                                                                                    cases */

/* I2C_SSR Bits */
/* I2C_SSR[RREQ] Bits */
#define I2C_SSR_RREQ_OFS                         (0)                             /* !< RREQ Offset */
#define I2C_SSR_RREQ_MASK                        ((uint32_t)0x00000001U)         /* !< Receive Request */
#define I2C_SSR_RREQ_CLEARED                     ((uint32_t)0x00000000U)         /* !< No outstanding receive data. */
#define I2C_SSR_RREQ_SET                         ((uint32_t)0x00000001U)         /* !< The I2C controller has outstanding
                                                                                    receive data from the I2C Controller
                                                                                    and is using clock stretching to
                                                                                    delay the Controller until the data
                                                                                    has been read from the SRXDATA FIFO
                                                                                    (Target RX FIFO is full). */
/* I2C_SSR[TREQ] Bits */
#define I2C_SSR_TREQ_OFS                         (1)                             /* !< TREQ Offset */
#define I2C_SSR_TREQ_MASK                        ((uint32_t)0x00000002U)         /* !< Transmit Request */
#define I2C_SSR_TREQ_CLEARED                     ((uint32_t)0x00000000U)         /* !< No outstanding transmit request. */
#define I2C_SSR_TREQ_SET                         ((uint32_t)0x00000002U)         /* !< The I2C controller has been
                                                                                    addressed as a Target transmitter and
                                                                                    is using clock stretching to delay
                                                                                    the Controller until data has been
                                                                                    written to the STXDATA FIFO (Target
                                                                                    TX FIFO is empty). */
/* I2C_SSR[OAR2SEL] Bits */
#define I2C_SSR_OAR2SEL_OFS                      (3)                             /* !< OAR2SEL Offset */
#define I2C_SSR_OAR2SEL_MASK                     ((uint32_t)0x00000008U)         /* !< OAR2 Address Matched This bit gets
                                                                                    reevaluated after every address
                                                                                    comparison. */
#define I2C_SSR_OAR2SEL_CLEARED                  ((uint32_t)0x00000000U)         /* !< Either the OAR2 address is not
                                                                                    matched or the match is in legacy
                                                                                    mode. */
#define I2C_SSR_OAR2SEL_SET                      ((uint32_t)0x00000008U)         /* !< OAR2 address matched and ACKed by
                                                                                    the Target. */
/* I2C_SSR[QCMDST] Bits */
#define I2C_SSR_QCMDST_OFS                       (4)                             /* !< QCMDST Offset */
#define I2C_SSR_QCMDST_MASK                      ((uint32_t)0x00000010U)         /* !< Quick Command Status Value
                                                                                    Description: 0: The last transaction
                                                                                    was a normal transaction or a
                                                                                    transaction has not occurred. 1: The
                                                                                    last transaction was a Quick Command
                                                                                    transaction */
#define I2C_SSR_QCMDST_CLEARED                   ((uint32_t)0x00000000U)         /* !< The last transaction was a normal
                                                                                    transaction or a transaction has not
                                                                                    occurred. */
#define I2C_SSR_QCMDST_SET                       ((uint32_t)0x00000010U)         /* !< The last transaction was a Quick
                                                                                    Command transaction. */
/* I2C_SSR[QCMDRW] Bits */
#define I2C_SSR_QCMDRW_OFS                       (5)                             /* !< QCMDRW Offset */
#define I2C_SSR_QCMDRW_MASK                      ((uint32_t)0x00000020U)         /* !< Quick Command Read / Write  This
                                                                                    bit only has meaning when the QCMDST
                                                                                    bit is set.  Value Description: 0:
                                                                                    Quick command was a write 1: Quick
                                                                                    command was a read */
#define I2C_SSR_QCMDRW_CLEARED                   ((uint32_t)0x00000000U)         /* !< Quick command was a write */
#define I2C_SSR_QCMDRW_SET                       ((uint32_t)0x00000020U)         /* !< Quick command was a read */
/* I2C_SSR[RXMODE] Bits */
#define I2C_SSR_RXMODE_OFS                       (2)                             /* !< RXMODE Offset */
#define I2C_SSR_RXMODE_MASK                      ((uint32_t)0x00000004U)         /* !< Target FSM is in Rx MODE */
#define I2C_SSR_RXMODE_CLEARED                   ((uint32_t)0x00000000U)         /* !< The Target State Machine is not in
                                                                                    the RX_DATA, RX_ACK, RX_WAIT,
                                                                                    RX_ACK_WAIT or ADDR_ACK state with
                                                                                    the bus direction set to write. */
#define I2C_SSR_RXMODE_SET                       ((uint32_t)0x00000004U)         /* !< The Target State Machine is in the
                                                                                    RX_DATA, RX_ACK, RX_WAIT, RX_ACK_WAIT
                                                                                    or ADDR_ACK state with the bus
                                                                                    direction set to write. */
/* I2C_SSR[BUSBSY] Bits */
#define I2C_SSR_BUSBSY_OFS                       (6)                             /* !< BUSBSY Offset */
#define I2C_SSR_BUSBSY_MASK                      ((uint32_t)0x00000040U)         /* !< I2C bus is busy */
#define I2C_SSR_BUSBSY_CLEARED                   ((uint32_t)0x00000000U)         /* !< The I2C Bus is not busy */
#define I2C_SSR_BUSBSY_SET                       ((uint32_t)0x00000040U)         /* !< The I2C Bus is busy. This is
                                                                                    cleared on a timeout. */
/* I2C_SSR[TXMODE] Bits */
#define I2C_SSR_TXMODE_OFS                       (7)                             /* !< TXMODE Offset */
#define I2C_SSR_TXMODE_MASK                      ((uint32_t)0x00000080U)         /* !< Target FSM is in TX MODE */
#define I2C_SSR_TXMODE_CLEARED                   ((uint32_t)0x00000000U)         /* !< The Target State Machine is not in
                                                                                    TX_DATA, TX_WAIT, TX_ACK  or ADDR_ACK
                                                                                    state with the bus direction set to
                                                                                    read. */
#define I2C_SSR_TXMODE_SET                       ((uint32_t)0x00000080U)         /* !< The Target State Machine is in
                                                                                    TX_DATA, TX_WAIT, TX_ACK  or ADDR_ACK
                                                                                    state with the bus direction set to
                                                                                    read. */
/* I2C_SSR[STALE_TXFIFO] Bits */
#define I2C_SSR_STALE_TXFIFO_OFS                 (8)                             /* !< STALE_TXFIFO Offset */
#define I2C_SSR_STALE_TXFIFO_MASK                ((uint32_t)0x00000100U)         /* !< Stale Tx FIFO */
#define I2C_SSR_STALE_TXFIFO_CLEARED             ((uint32_t)0x00000000U)         /* !< Tx FIFO is not stale */
#define I2C_SSR_STALE_TXFIFO_SET                 ((uint32_t)0x00000100U)         /* !< The TX FIFO is stale. This occurs
                                                                                    when the TX FIFO was not emptied
                                                                                    during the previous I2C transaction. */
/* I2C_SSR[ADDRMATCH] Bits */
#define I2C_SSR_ADDRMATCH_OFS                    (9)                             /* !< ADDRMATCH Offset */
#define I2C_SSR_ADDRMATCH_MASK                   ((uint32_t)0x0007FE00U)         /* !< Indicates the address for which
                                                                                    Target address match happened */
#define I2C_SSR_ADDRMATCH_MINIMUM                ((uint32_t)0x00000000U)         /* !< Minimum Value */
#define I2C_SSR_ADDRMATCH_MAXIMUM                ((uint32_t)0x0007FE00U)         /* !< Maximum Value */

/* I2C_SRXDATA Bits */
/* I2C_SRXDATA[VALUE] Bits */
#define I2C_SRXDATA_VALUE_OFS                    (0)                             /* !< VALUE Offset */
#define I2C_SRXDATA_VALUE_MASK                   ((uint32_t)0x000000FFU)         /* !< Received Data.  This field contains
                                                                                    the last received data. */
#define I2C_SRXDATA_VALUE_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_SRXDATA_VALUE_MAXIMUM                ((uint32_t)0x000000FFU)         /* !< Highest possible value */

/* I2C_STXDATA Bits */
/* I2C_STXDATA[VALUE] Bits */
#define I2C_STXDATA_VALUE_OFS                    (0)                             /* !< VALUE Offset */
#define I2C_STXDATA_VALUE_MASK                   ((uint32_t)0x000000FFU)         /* !< Transmit Data This byte contains
                                                                                    the data to be transferred during the
                                                                                    next transaction. */
#define I2C_STXDATA_VALUE_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_STXDATA_VALUE_MAXIMUM                ((uint32_t)0x000000FFU)         /* !< Highest possible value */

/* I2C_SACKCTL Bits */
/* I2C_SACKCTL[ACKOEN] Bits */
#define I2C_SACKCTL_ACKOEN_OFS                   (0)                             /* !< ACKOEN Offset */
#define I2C_SACKCTL_ACKOEN_MASK                  ((uint32_t)0x00000001U)         /* !< I2C Target ACK Override Enable */
#define I2C_SACKCTL_ACKOEN_DISABLE               ((uint32_t)0x00000000U)         /* !< A response in not provided. */
#define I2C_SACKCTL_ACKOEN_ENABLE                ((uint32_t)0x00000001U)         /* !< An ACK or NACK is sent according to
                                                                                    the value written to the ACKOVAL bit. */
/* I2C_SACKCTL[ACKOVAL] Bits */
#define I2C_SACKCTL_ACKOVAL_OFS                  (1)                             /* !< ACKOVAL Offset */
#define I2C_SACKCTL_ACKOVAL_MASK                 ((uint32_t)0x00000002U)         /* !< I2C Target ACK Override Value Note:
                                                                                    for General Call this bit will be
                                                                                    ignored if set to NACK and Target
                                                                                    continues to receive data. */
#define I2C_SACKCTL_ACKOVAL_DISABLE              ((uint32_t)0x00000000U)         /* !< An ACK is sent indicating valid
                                                                                    data or command. */
#define I2C_SACKCTL_ACKOVAL_ENABLE               ((uint32_t)0x00000002U)         /* !< A NACK is sent indicating invalid
                                                                                    data or command. */
/* I2C_SACKCTL[ACKOEN_ON_START] Bits */
#define I2C_SACKCTL_ACKOEN_ON_START_OFS          (2)                             /* !< ACKOEN_ON_START Offset */
#define I2C_SACKCTL_ACKOEN_ON_START_MASK         ((uint32_t)0x00000004U)         /* !< When set this bit will
                                                                                    automatically turn on the Target
                                                                                    ACKOEN field following a Start
                                                                                    Condition. */
#define I2C_SACKCTL_ACKOEN_ON_START_DISABLE      ((uint32_t)0x00000000U)         /* !< No special behavior */
#define I2C_SACKCTL_ACKOEN_ON_START_ENABLE       ((uint32_t)0x00000004U)         /* !< When set this bit will
                                                                                    automatically turn on the Target
                                                                                    ACKOEN field following a Start
                                                                                    Condition. */
/* I2C_SACKCTL[ACKOEN_ON_PECNEXT] Bits */
#define I2C_SACKCTL_ACKOEN_ON_PECNEXT_OFS        (3)                             /* !< ACKOEN_ON_PECNEXT Offset */
#define I2C_SACKCTL_ACKOEN_ON_PECNEXT_MASK       ((uint32_t)0x00000008U)         /* !< When set this bit will
                                                                                    automatically turn on the Target
                                                                                    ACKOEN field following the ACK/NACK
                                                                                    of the byte received just prior to
                                                                                    the PEC byte. Note that when ACKOEN
                                                                                    is set the PEC byte will not
                                                                                    automatically be ACKed/NACKed by the
                                                                                    State Machine and FW must perform
                                                                                    this function by writing
                                                                                    Target_SACKCTL. */
#define I2C_SACKCTL_ACKOEN_ON_PECNEXT_DISABLE    ((uint32_t)0x00000000U)         /* !< No special behavior */
#define I2C_SACKCTL_ACKOEN_ON_PECNEXT_ENABLE     ((uint32_t)0x00000008U)         /* !< When set this bit will
                                                                                    automatically turn on the Target
                                                                                    ACKOEN field following the ACK/NACK
                                                                                    of the byte received just prior to
                                                                                    the PEC byte. Note that when ACKOEN
                                                                                    is set the PEC byte will not
                                                                                    automatically be ACKed/NACKed by the
                                                                                    State Machine and FW must perform
                                                                                    this function by writing
                                                                                    Target_SACKCTL. */
/* I2C_SACKCTL[ACKOEN_ON_PECDONE] Bits */
#define I2C_SACKCTL_ACKOEN_ON_PECDONE_OFS        (4)                             /* !< ACKOEN_ON_PECDONE Offset */
#define I2C_SACKCTL_ACKOEN_ON_PECDONE_MASK       ((uint32_t)0x00000010U)         /* !< When set this bit will
                                                                                    automatically turn on the Target
                                                                                    ACKOEN field following the ACK/NACK
                                                                                    of the received PEC byte. */
#define I2C_SACKCTL_ACKOEN_ON_PECDONE_DISABLE    ((uint32_t)0x00000000U)         /* !< No special behavior */
#define I2C_SACKCTL_ACKOEN_ON_PECDONE_ENABLE     ((uint32_t)0x00000010U)         /* !< When set this bit will
                                                                                    automatically turn on the Target
                                                                                    ACKOEN field following the ACK/NACK
                                                                                    of the received PEC byte. */

/* I2C_SFIFOCTL Bits */
/* I2C_SFIFOCTL[TXTRIG] Bits */
#define I2C_SFIFOCTL_TXTRIG_OFS                  (0)                             /* !< TXTRIG Offset */
#define I2C_SFIFOCTL_TXTRIG_MASK                 ((uint32_t)0x00000007U)         /* !< TX FIFO Trigger Indicates at what
                                                                                    fill level in the TX FIFO a trigger
                                                                                    will be generated. */
#define I2C_SFIFOCTL_TXTRIG_LEVEL_4              ((uint32_t)0x00000004U)         /* !< Trigger when TX FIFO contains  4
                                                                                    byte */
#define I2C_SFIFOCTL_TXTRIG_LEVEL_5              ((uint32_t)0x00000005U)         /* !< Trigger when TX FIFO contains  5
                                                                                    byte */
#define I2C_SFIFOCTL_TXTRIG_LEVEL_6              ((uint32_t)0x00000006U)         /* !< Trigger when TX FIFO contains  6
                                                                                    byte */
#define I2C_SFIFOCTL_TXTRIG_LEVEL_7              ((uint32_t)0x00000007U)         /* !< Trigger when TX FIFO contains  7
                                                                                    byte */
/* I2C_SFIFOCTL[TXFLUSH] Bits */
#define I2C_SFIFOCTL_TXFLUSH_OFS                 (7)                             /* !< TXFLUSH Offset */
#define I2C_SFIFOCTL_TXFLUSH_MASK                ((uint32_t)0x00000080U)         /* !< TX FIFO Flush Setting this bit will
                                                                                    Flush the TX FIFO. Before clearing
                                                                                    this bit to stop Flush the TXFIFOCNT
                                                                                    should be checked to be 8 and
                                                                                    indicating that the Flush has
                                                                                    completed. */
#define I2C_SFIFOCTL_TXFLUSH_NOFLUSH             ((uint32_t)0x00000000U)         /* !< Do not Flush FIFO */
#define I2C_SFIFOCTL_TXFLUSH_FLUSH               ((uint32_t)0x00000080U)         /* !< Flush FIFO */
/* I2C_SFIFOCTL[RXFLUSH] Bits */
#define I2C_SFIFOCTL_RXFLUSH_OFS                 (15)                            /* !< RXFLUSH Offset */
#define I2C_SFIFOCTL_RXFLUSH_MASK                ((uint32_t)0x00008000U)         /* !< RX FIFO Flush Setting this bit will
                                                                                    Flush the RX FIFO. Before clearing
                                                                                    this bit to stop Flush the RXFIFOCNT
                                                                                    should be checked to be 0 and
                                                                                    indicating that the Flush has
                                                                                    completed. */
#define I2C_SFIFOCTL_RXFLUSH_NOFLUSH             ((uint32_t)0x00000000U)         /* !< Do not Flush FIFO */
#define I2C_SFIFOCTL_RXFLUSH_FLUSH               ((uint32_t)0x00008000U)         /* !< Flush FIFO */
/* I2C_SFIFOCTL[RXTRIG] Bits */
#define I2C_SFIFOCTL_RXTRIG_OFS                  (8)                             /* !< RXTRIG Offset */
#define I2C_SFIFOCTL_RXTRIG_MASK                 ((uint32_t)0x00000700U)         /* !< RX FIFO Trigger Indicates at what
                                                                                    fill level in the RX FIFO a trigger
                                                                                    will be generated. Note: Programming
                                                                                    RXTRIG to 0x0 has no effect since no
                                                                                    data is present to transfer out of RX
                                                                                    FIFO. */
#define I2C_SFIFOCTL_RXTRIG_LEVEL_5              ((uint32_t)0x00000400U)         /* !< Trigger when RX FIFO contains >= 5
                                                                                    byte */
#define I2C_SFIFOCTL_RXTRIG_LEVEL_6              ((uint32_t)0x00000500U)         /* !< Trigger when RX FIFO contains >= 6
                                                                                    byte */
#define I2C_SFIFOCTL_RXTRIG_LEVEL_7              ((uint32_t)0x00000600U)         /* !< Trigger when RX FIFO contains >= 7
                                                                                    byte */
#define I2C_SFIFOCTL_RXTRIG_LEVEL_8              ((uint32_t)0x00000700U)         /* !< Trigger when RX FIFO contains >= 8
                                                                                    byte */

/* I2C_SFIFOSR Bits */
/* I2C_SFIFOSR[RXFIFOCNT] Bits */
#define I2C_SFIFOSR_RXFIFOCNT_OFS                (0)                             /* !< RXFIFOCNT Offset */
#define I2C_SFIFOSR_RXFIFOCNT_MASK               ((uint32_t)0x0000000FU)         /* !< Number of Bytes which could be read
                                                                                    from the RX FIFO */
#define I2C_SFIFOSR_RXFIFOCNT_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_SFIFOSR_RXFIFOCNT_MAXIMUM            ((uint32_t)0x00000008U)         /* !< Highest possible value */
/* I2C_SFIFOSR[TXFIFOCNT] Bits */
#define I2C_SFIFOSR_TXFIFOCNT_OFS                (8)                             /* !< TXFIFOCNT Offset */
#define I2C_SFIFOSR_TXFIFOCNT_MASK               ((uint32_t)0x00000F00U)         /* !< Number of Bytes which could be put
                                                                                    into the TX FIFO */
#define I2C_SFIFOSR_TXFIFOCNT_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_SFIFOSR_TXFIFOCNT_MAXIMUM            ((uint32_t)0x00000800U)         /* !< Highest possible value */
/* I2C_SFIFOSR[TXFLUSH] Bits */
#define I2C_SFIFOSR_TXFLUSH_OFS                  (15)                            /* !< TXFLUSH Offset */
#define I2C_SFIFOSR_TXFLUSH_MASK                 ((uint32_t)0x00008000U)         /* !< TX FIFO Flush When this bit is set
                                                                                    a Flush operation for the TX FIFO is
                                                                                    active. Clear the TXFLUSH bit in the
                                                                                    control register to stop. */
#define I2C_SFIFOSR_TXFLUSH_INACTIVE             ((uint32_t)0x00000000U)         /* !< FIFO Flush not active */
#define I2C_SFIFOSR_TXFLUSH_ACTIVE               ((uint32_t)0x00008000U)         /* !< FIFO Flush active */
/* I2C_SFIFOSR[RXFLUSH] Bits */
#define I2C_SFIFOSR_RXFLUSH_OFS                  (7)                             /* !< RXFLUSH Offset */
#define I2C_SFIFOSR_RXFLUSH_MASK                 ((uint32_t)0x00000080U)         /* !< RX FIFO Flush When this bit is set
                                                                                    a Flush operation for the RX FIFO is
                                                                                    active. Clear the RXFLUSH bit in the
                                                                                    control register to stop. */
#define I2C_SFIFOSR_RXFLUSH_INACTIVE             ((uint32_t)0x00000000U)         /* !< FIFOFlush not active */
#define I2C_SFIFOSR_RXFLUSH_ACTIVE               ((uint32_t)0x00000080U)         /* !< FIFO Flush active */

/* I2C_TARGET_PECCTL Bits */
/* I2C_TARGET_PECCTL[PECCNT] Bits */
#define I2C_TARGET_PECCTL_PECCNT_OFS             (0)                             /* !< PECCNT Offset */
#define I2C_TARGET_PECCTL_PECCNT_MASK            ((uint32_t)0x000001FFU)         /* !< When this field is non zero, the
                                                                                    number of I2C data bytes are counted.
                                                                                    When the byte count = PECCNT and the
                                                                                    state machine is transmitting, the
                                                                                    contents of the LSFR is loaded into
                                                                                    the shift register instead of the
                                                                                    byte received from the Tx FIFO. When
                                                                                    the state machine is receiving, after
                                                                                    the last bit of this byte is received
                                                                                    the LSFR is checked and if it is
                                                                                    non-zero, a PEC RX Error interrupt is
                                                                                    generated. The I2C packet must be
                                                                                    padded to include the PEC byte for
                                                                                    both transmit and receive. In
                                                                                    transmit mode the FIFO must be loaded
                                                                                    with a dummy PEC byte. In receive
                                                                                    mode the PEC byte will be passed to
                                                                                    the Rx FIFO.  In the normal Target
                                                                                    use case, FW would set PECEN=1 and
                                                                                    PECCNT=0 and use the ACKOEN until the
                                                                                    remaining SMB packet length is known.
                                                                                    FW would then set the PECCNT to the
                                                                                    remaining packet length (Including
                                                                                    PEC bye). FW would then configure DMA
                                                                                    to allow the packet to complete
                                                                                    unassisted and exit NoAck mode.  Note
                                                                                    that when the byte count = PEC CNT,
                                                                                    the byte count is reset to 0 and
                                                                                    multiple PEC calculation can
                                                                                    automatically occur within a single
                                                                                    I2C transaction */
#define I2C_TARGET_PECCTL_PECCNT_MINIMUM         ((uint32_t)0x00000000U)         /* !< Minimum Value */
#define I2C_TARGET_PECCTL_PECCNT_MAXIMUM         ((uint32_t)0x000001FFU)         /* !< Maximum Value */
/* I2C_TARGET_PECCTL[PECEN] Bits */
#define I2C_TARGET_PECCTL_PECEN_OFS              (12)                            /* !< PECEN Offset */
#define I2C_TARGET_PECCTL_PECEN_MASK             ((uint32_t)0x00001000U)         /* !< PEC Enable This bit enables the SMB
                                                                                    Packet Error Checking (PEC). When
                                                                                    enabled the PEC is calculated on all
                                                                                    bits except the Start, Stop, Ack and
                                                                                    Nack. The PEC LSFR and the Byte
                                                                                    Counter is set to 0 when the State
                                                                                    Machine is in the IDLE state, which
                                                                                    occur following a Stop or when a
                                                                                    timeout occurs. The Counter is also
                                                                                    set to 0 after the PEC byte is sent
                                                                                    or received. Note that the NACK is
                                                                                    automatically send following a PEC
                                                                                    byte that results in a PEC error. The
                                                                                    PEC Polynomial is x^8 + x^2 + x^1 +
                                                                                    1. */
#define I2C_TARGET_PECCTL_PECEN_DISABLE          ((uint32_t)0x00000000U)         /* !< PEC transmission and check is
                                                                                    disabled */
#define I2C_TARGET_PECCTL_PECEN_ENABLE           ((uint32_t)0x00001000U)         /* !< PEC transmission and check is
                                                                                    enabled */

/* I2C_TARGET_PECSR Bits */
/* I2C_TARGET_PECSR[PECBYTECNT] Bits */
#define I2C_TARGET_PECSR_PECBYTECNT_OFS          (0)                             /* !< PECBYTECNT Offset */
#define I2C_TARGET_PECSR_PECBYTECNT_MASK         ((uint32_t)0x000001FFU)         /* !< This is the current PEC Byte Count
                                                                                    of the Target State Machine. */
#define I2C_TARGET_PECSR_PECBYTECNT_MINIMUM      ((uint32_t)0x00000000U)         /* !< Minimum Value */
#define I2C_TARGET_PECSR_PECBYTECNT_MAXIMUM      ((uint32_t)0x000001FFU)         /* !< Maximum Value */
/* I2C_TARGET_PECSR[PECSTS_CHECK] Bits */
#define I2C_TARGET_PECSR_PECSTS_CHECK_OFS        (16)                            /* !< PECSTS_CHECK Offset */
#define I2C_TARGET_PECSR_PECSTS_CHECK_MASK       ((uint32_t)0x00010000U)         /* !< This status bit indicates if the
                                                                                    PEC was checked in the transaction
                                                                                    that occurred before the last Stop.
                                                                                    Latched on Stop. */
#define I2C_TARGET_PECSR_PECSTS_CHECK_CLEARED    ((uint32_t)0x00000000U)         /* !< Indicates PEC was not checked in
                                                                                    the transaction that occurred before
                                                                                    the last Stop */
#define I2C_TARGET_PECSR_PECSTS_CHECK_SET        ((uint32_t)0x00010000U)         /* !< Indicates PEC was checked in the
                                                                                    transaction that occurred before the
                                                                                    last Stop */
/* I2C_TARGET_PECSR[PECSTS_ERROR] Bits */
#define I2C_TARGET_PECSR_PECSTS_ERROR_OFS        (17)                            /* !< PECSTS_ERROR Offset */
#define I2C_TARGET_PECSR_PECSTS_ERROR_MASK       ((uint32_t)0x00020000U)         /* !< This status bit indicates if a PEC
                                                                                    check error occurred in the
                                                                                    transaction that occurred before the
                                                                                    last Stop. Latched on Stop. */
#define I2C_TARGET_PECSR_PECSTS_ERROR_CLEARED    ((uint32_t)0x00000000U)         /* !< Indicates PEC check error did not
                                                                                    occurr in the transaction that
                                                                                    occurred before the last Stop */
#define I2C_TARGET_PECSR_PECSTS_ERROR_SET        ((uint32_t)0x00020000U)         /* !< Indicates PEC check error occurred
                                                                                    in the transaction that occurred
                                                                                    before the last Stop */

/* I2C_MSA Bits */
/* I2C_MSA[DIR] Bits */
#define I2C_MSA_DIR_OFS                          (0)                             /* !< DIR Offset */
#define I2C_MSA_DIR_MASK                         ((uint32_t)0x00000001U)         /* !< Receive/Send The DIR bit specifies
                                                                                    if the next Controller operation is a
                                                                                    Receive (High) or Transmit (Low). 0h
                                                                                    = Transmit 1h = Receive */
#define I2C_MSA_DIR_TRANSMIT                     ((uint32_t)0x00000000U)         /* !< The Controller is in transmit mode. */
#define I2C_MSA_DIR_RECEIVE                      ((uint32_t)0x00000001U)         /* !< The Controller is in receive mode. */
/* I2C_MSA[SADDR] Bits */
#define I2C_MSA_SADDR_OFS                        (1)                             /* !< SADDR Offset */
#define I2C_MSA_SADDR_MASK                       ((uint32_t)0x000007FEU)         /* !< I2C Target Address This field
                                                                                    specifies bits A9 through A0 of the
                                                                                    Target address. In 7-bit addressing
                                                                                    mode as selected by MSA.MODE bit, the
                                                                                    top 3 bits are don't care */
#define I2C_MSA_SADDR_MINIMUM                    ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_MSA_SADDR_MAXIMUM                    ((uint32_t)0x000007FEU)         /* !< Highest possible value */
/* I2C_MSA[MMODE] Bits */
#define I2C_MSA_MMODE_OFS                        (15)                            /* !< MMODE Offset */
#define I2C_MSA_MMODE_MASK                       ((uint32_t)0x00008000U)         /* !< This bit selects the adressing mode
                                                                                    to be used in Controller mode When 0,
                                                                                    7-bit addressing is used. When 1,
                                                                                    10-bit addressing is used. */
#define I2C_MSA_MMODE_MODE7                      ((uint32_t)0x00000000U)         /* !< 7-bit addressing mode */
#define I2C_MSA_MMODE_MODE10                     ((uint32_t)0x00008000U)         /* !< 10-bit addressing mode */

/* I2C_MCTR Bits */
/* I2C_MCTR[BURSTRUN] Bits */
#define I2C_MCTR_BURSTRUN_OFS                    (0)                             /* !< BURSTRUN Offset */
#define I2C_MCTR_BURSTRUN_MASK                   ((uint32_t)0x00000001U)         /* !< I2C Controller Enable and start
                                                                                    transaction */
#define I2C_MCTR_BURSTRUN_DISABLE                ((uint32_t)0x00000000U)         /* !< In standard mode, this encoding
                                                                                    means the Controller is unable to
                                                                                    transmit or receive data. */
#define I2C_MCTR_BURSTRUN_ENABLE                 ((uint32_t)0x00000001U)         /* !< The Controller is able to transmit
                                                                                    or receive data. See field decoding
                                                                                    in Table: MCTR Field decoding. */
/* I2C_MCTR[START] Bits */
#define I2C_MCTR_START_OFS                       (1)                             /* !< START Offset */
#define I2C_MCTR_START_MASK                      ((uint32_t)0x00000002U)         /* !< Generate START */
#define I2C_MCTR_START_DISABLE                   ((uint32_t)0x00000000U)         /* !< The controller does not generate
                                                                                    the START condition. */
#define I2C_MCTR_START_ENABLE                    ((uint32_t)0x00000002U)         /* !< The controller generates the START
                                                                                    or repeated START condition. See
                                                                                    field decoding in Table: MCTR Field
                                                                                    decoding. */
/* I2C_MCTR[STOP] Bits */
#define I2C_MCTR_STOP_OFS                        (2)                             /* !< STOP Offset */
#define I2C_MCTR_STOP_MASK                       ((uint32_t)0x00000004U)         /* !< Generate STOP */
#define I2C_MCTR_STOP_DISABLE                    ((uint32_t)0x00000000U)         /* !< The controller does not generate
                                                                                    the STOP condition. */
#define I2C_MCTR_STOP_ENABLE                     ((uint32_t)0x00000004U)         /* !< The controller generates the STOP
                                                                                    condition. See field decoding in
                                                                                    Table: MCTR Field decoding. */
/* I2C_MCTR[ACK] Bits */
#define I2C_MCTR_ACK_OFS                         (3)                             /* !< ACK Offset */
#define I2C_MCTR_ACK_MASK                        ((uint32_t)0x00000008U)         /* !< Data Acknowledge Enable. Software
                                                                                    needs to configure this bit to send
                                                                                    the ACK or NACK. See field decoding
                                                                                    in Table: MCTR Field decoding. */
#define I2C_MCTR_ACK_DISABLE                     ((uint32_t)0x00000000U)         /* !< The last received data byte of a
                                                                                    transaction is not acknowledged
                                                                                    automatically by the Controller. */
#define I2C_MCTR_ACK_ENABLE                      ((uint32_t)0x00000008U)         /* !< The last received data byte of a
                                                                                    transaction is acknowledged
                                                                                    automatically by the Controller. */
/* I2C_MCTR[MBLEN] Bits */
#define I2C_MCTR_MBLEN_OFS                       (16)                            /* !< MBLEN Offset */
#define I2C_MCTR_MBLEN_MASK                      ((uint32_t)0x0FFF0000U)         /* !< I2C transaction length This field
                                                                                    contains the programmed length of
                                                                                    bytes of the Transaction. */
#define I2C_MCTR_MBLEN_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_MCTR_MBLEN_MAXIMUM                   ((uint32_t)0x0FFF0000U)         /* !< Highest possible value */
/* I2C_MCTR[MACKOEN] Bits */
#define I2C_MCTR_MACKOEN_OFS                     (4)                             /* !< MACKOEN Offset */
#define I2C_MCTR_MACKOEN_MASK                    ((uint32_t)0x00000010U)         /* !< Controller ACK overrride Enable */
#define I2C_MCTR_MACKOEN_DISABLE                 ((uint32_t)0x00000000U)         /* !< No special behavior */
#define I2C_MCTR_MACKOEN_ENABLE                  ((uint32_t)0x00000010U)         /* !< When 1 and the Controller is
                                                                                    receiving data and the number of
                                                                                    bytes indicated in MBLEN have been
                                                                                    received, the state machine will
                                                                                    generate an rxdone interrupt and wait
                                                                                    at the start of the ACK for FW to
                                                                                    indicate if an ACK or NACK should be
                                                                                    sent. The ACK or NACK is selected by
                                                                                    writing the MCTR register and setting
                                                                                    ACK accordingly. The other fields in
                                                                                    this register can also be written at
                                                                                    this time to continue on with the
                                                                                    transaction. If a NACK is sent the
                                                                                    state machine will automatically send
                                                                                    a Stop. */
/* I2C_MCTR[RD_ON_TXEMPTY] Bits */
#define I2C_MCTR_RD_ON_TXEMPTY_OFS               (5)                             /* !< RD_ON_TXEMPTY Offset */
#define I2C_MCTR_RD_ON_TXEMPTY_MASK              ((uint32_t)0x00000020U)         /* !< Read on TX Empty */
#define I2C_MCTR_RD_ON_TXEMPTY_DISABLE           ((uint32_t)0x00000000U)         /* !< No special behavior */
#define I2C_MCTR_RD_ON_TXEMPTY_ENABLE            ((uint32_t)0x00000020U)         /* !< When 1 the Controller will transmit
                                                                                    all bytes from the TX FIFO before
                                                                                    continuing with the programmed Burst
                                                                                    Run Read. If the DIR is not set to
                                                                                    Read in the MSA then this bit is
                                                                                    ignored. The Start must be set in the
                                                                                    MCTR for proper I2C protocol. The
                                                                                    Controller will first send the Start
                                                                                    Condition, I2C Address with R/W bit
                                                                                    set to write, before sending the
                                                                                    bytes in the TX FIFO. When the TX
                                                                                    FIFO is empty, the I2C transaction
                                                                                    will continue as programmed in MTCR
                                                                                    and MSA without sending a Stop
                                                                                    Condition. This is intended to be
                                                                                    used to perform simple I2C command
                                                                                    based reads transition that will
                                                                                    complete after initiating them
                                                                                    without having to get an interrupt to
                                                                                    turn the bus around. */

/* I2C_MSR Bits */
/* I2C_MSR[BUSY] Bits */
#define I2C_MSR_BUSY_OFS                         (0)                             /* !< BUSY Offset */
#define I2C_MSR_BUSY_MASK                        ((uint32_t)0x00000001U)         /* !< I2C Controller FSM Busy The BUSY
                                                                                    bit is set during an ongoing
                                                                                    transaction, so is set during the
                                                                                    transmit/receive of the amount of
                                                                                    data set in MBLEN including START,
                                                                                    RESTART, Address and STOP signal
                                                                                    generation when required for the
                                                                                    current transaction. */
#define I2C_MSR_BUSY_CLEARED                     ((uint32_t)0x00000000U)         /* !< The controller is idle. */
#define I2C_MSR_BUSY_SET                         ((uint32_t)0x00000001U)         /* !< The controller is busy. */
/* I2C_MSR[ERR] Bits */
#define I2C_MSR_ERR_OFS                          (1)                             /* !< ERR Offset */
#define I2C_MSR_ERR_MASK                         ((uint32_t)0x00000002U)         /* !< Error  The error can be from the
                                                                                    Target address not being acknowledged
                                                                                    or the transmit data not being
                                                                                    acknowledged. */
#define I2C_MSR_ERR_CLEARED                      ((uint32_t)0x00000000U)         /* !< No error was detected on the last
                                                                                    operation. */
#define I2C_MSR_ERR_SET                          ((uint32_t)0x00000002U)         /* !< An error occurred on the last
                                                                                    operation. */
/* I2C_MSR[ADRACK] Bits */
#define I2C_MSR_ADRACK_OFS                       (2)                             /* !< ADRACK Offset */
#define I2C_MSR_ADRACK_MASK                      ((uint32_t)0x00000004U)         /* !< Acknowledge Address */
#define I2C_MSR_ADRACK_CLEARED                   ((uint32_t)0x00000000U)         /* !< The transmitted address was
                                                                                    acknowledged */
#define I2C_MSR_ADRACK_SET                       ((uint32_t)0x00000004U)         /* !< The transmitted address was not
                                                                                    acknowledged. */
/* I2C_MSR[DATACK] Bits */
#define I2C_MSR_DATACK_OFS                       (3)                             /* !< DATACK Offset */
#define I2C_MSR_DATACK_MASK                      ((uint32_t)0x00000008U)         /* !< Acknowledge Data */
#define I2C_MSR_DATACK_CLEARED                   ((uint32_t)0x00000000U)         /* !< The transmitted data was
                                                                                    acknowledged */
#define I2C_MSR_DATACK_SET                       ((uint32_t)0x00000008U)         /* !< The transmitted data was not
                                                                                    acknowledged. */
/* I2C_MSR[ARBLST] Bits */
#define I2C_MSR_ARBLST_OFS                       (4)                             /* !< ARBLST Offset */
#define I2C_MSR_ARBLST_MASK                      ((uint32_t)0x00000010U)         /* !< Arbitration Lost */
#define I2C_MSR_ARBLST_CLEARED                   ((uint32_t)0x00000000U)         /* !< The I2C controller won arbitration. */
#define I2C_MSR_ARBLST_SET                       ((uint32_t)0x00000010U)         /* !< The I2C controller lost
                                                                                    arbitration. */
/* I2C_MSR[IDLE] Bits */
#define I2C_MSR_IDLE_OFS                         (5)                             /* !< IDLE Offset */
#define I2C_MSR_IDLE_MASK                        ((uint32_t)0x00000020U)         /* !< I2C Idle */
#define I2C_MSR_IDLE_CLEARED                     ((uint32_t)0x00000000U)         /* !< The I2C controller is not idle. */
#define I2C_MSR_IDLE_SET                         ((uint32_t)0x00000020U)         /* !< The I2C controller is idle. */
/* I2C_MSR[BUSBSY] Bits */
#define I2C_MSR_BUSBSY_OFS                       (6)                             /* !< BUSBSY Offset */
#define I2C_MSR_BUSBSY_MASK                      ((uint32_t)0x00000040U)         /* !< I2C Bus is Busy Controller State
                                                                                    Machine will wait until this bit is
                                                                                    cleared before starting a
                                                                                    transaction. When first enabling the
                                                                                    Controller in multi Controller
                                                                                    environments, FW should wait for one
                                                                                    I2C clock period after setting ACTIVE
                                                                                    high before writing to the MTCR
                                                                                    register to start the transaction so
                                                                                    that if SCL goes low it will trigger
                                                                                    the BUSBSY. */
#define I2C_MSR_BUSBSY_CLEARED                   ((uint32_t)0x00000000U)         /* !< The I2C bus is idle. */
#define I2C_MSR_BUSBSY_SET                       ((uint32_t)0x00000040U)         /* !< 'This Status bit is set on a START
                                                                                    or when SCL goes low. It is cleared
                                                                                    on a STOP,  or when a SCL high bus
                                                                                    busy timeout occurs and SCL and SDA
                                                                                    are both high. This status is cleared
                                                                                    when the ACTIVE bit is low.   Note
                                                                                    that the Controller State Machine
                                                                                    will wait until this bit is cleared
                                                                                    before starting an I2C transaction.
                                                                                    When first enabling the Controller in
                                                                                    multi Controller environments, FW
                                                                                    should wait for one I2C clock period
                                                                                    after setting ACTIVE high before
                                                                                    writing to the MTCR register to start
                                                                                    the transaction so that if SCL goes
                                                                                    low it will trigger the BUSBSY. */
/* I2C_MSR[MBCNT] Bits */
#define I2C_MSR_MBCNT_OFS                        (16)                            /* !< MBCNT Offset */
#define I2C_MSR_MBCNT_MASK                       ((uint32_t)0x0FFF0000U)         /* !< I2C Controller Transaction Count
                                                                                    This field contains the current
                                                                                    count-down value of the transaction. */
#define I2C_MSR_MBCNT_MINIMUM                    ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_MSR_MBCNT_MAXIMUM                    ((uint32_t)0x0FFF0000U)         /* !< Highest possible value */

/* I2C_MRXDATA Bits */
/* I2C_MRXDATA[VALUE] Bits */
#define I2C_MRXDATA_VALUE_OFS                    (0)                             /* !< VALUE Offset */
#define I2C_MRXDATA_VALUE_MASK                   ((uint32_t)0x000000FFU)         /* !< Received Data.  This field contains
                                                                                    the last received data. */
#define I2C_MRXDATA_VALUE_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_MRXDATA_VALUE_MAXIMUM                ((uint32_t)0x000000FFU)         /* !< Highest possible value */

/* I2C_MTXDATA Bits */
/* I2C_MTXDATA[VALUE] Bits */
#define I2C_MTXDATA_VALUE_OFS                    (0)                             /* !< VALUE Offset */
#define I2C_MTXDATA_VALUE_MASK                   ((uint32_t)0x000000FFU)         /* !< Transmit Data This byte contains
                                                                                    the data to be transferred during the
                                                                                    next transaction. */
#define I2C_MTXDATA_VALUE_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_MTXDATA_VALUE_MAXIMUM                ((uint32_t)0x000000FFU)         /* !< Highest possible value */

/* I2C_MTPR Bits */
/* I2C_MTPR[TPR] Bits */
#define I2C_MTPR_TPR_OFS                         (0)                             /* !< TPR Offset */
#define I2C_MTPR_TPR_MASK                        ((uint32_t)0x0000007FU)         /* !< Timer Period  This field is used in
                                                                                    the equation to configure SCL_PERIOD
                                                                                    : SCL_PERIOD = (1 + TPR ) * (SCL_LP +
                                                                                    SCL_HP ) * INT_CLK_PRD where:
                                                                                    SCL_PRD is the SCL line period (I2C
                                                                                    clock).   TPR is the Timer Period
                                                                                    register value (range of 1 to 127).
                                                                                    SCL_LP is the SCL Low period (fixed
                                                                                    at 6).   SCL_HP is the SCL High
                                                                                    period (fixed at 4).   CLK_PRD is the
                                                                                    functional clock period in ns. */
#define I2C_MTPR_TPR_MINIMUM                     ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_MTPR_TPR_MAXIMUM                     ((uint32_t)0x0000007FU)         /* !< Highest possible value */

/* I2C_MCR Bits */
/* I2C_MCR[LPBK] Bits */
#define I2C_MCR_LPBK_OFS                         (8)                             /* !< LPBK Offset */
#define I2C_MCR_LPBK_MASK                        ((uint32_t)0x00000100U)         /* !< I2C Loopback */
#define I2C_MCR_LPBK_DISABLE                     ((uint32_t)0x00000000U)         /* !< Normal operation. */
#define I2C_MCR_LPBK_ENABLE                      ((uint32_t)0x00000100U)         /* !< The controller in a test mode
                                                                                    loopback configuration. */
/* I2C_MCR[MMST] Bits */
#define I2C_MCR_MMST_OFS                         (1)                             /* !< MMST Offset */
#define I2C_MCR_MMST_MASK                        ((uint32_t)0x00000002U)         /* !< MultiController mode. In
                                                                                    MultiController mode the SCL high
                                                                                    time counts once the SCL line has
                                                                                    been detected high. If this is not
                                                                                    enabled the high time counts as soon
                                                                                    as the SCL line has been set high by
                                                                                    the I2C controller. */
#define I2C_MCR_MMST_DISABLE                     ((uint32_t)0x00000000U)         /* !< Disable MultiController mode. */
#define I2C_MCR_MMST_ENABLE                      ((uint32_t)0x00000002U)         /* !< Enable MultiController mode. */
/* I2C_MCR[ACTIVE] Bits */
#define I2C_MCR_ACTIVE_OFS                       (0)                             /* !< ACTIVE Offset */
#define I2C_MCR_ACTIVE_MASK                      ((uint32_t)0x00000001U)         /* !< Device Active  After this bit has
                                                                                    been set, it should not be set again
                                                                                    unless it has been cleared by writing
                                                                                    a 0 or by a reset, otherwise transfer
                                                                                    failures may occur. */
#define I2C_MCR_ACTIVE_DISABLE                   ((uint32_t)0x00000000U)         /* !< Disables the I2C Controller
                                                                                    operation. */
#define I2C_MCR_ACTIVE_ENABLE                    ((uint32_t)0x00000001U)         /* !< Enables the I2C Controller
                                                                                    operation. */
/* I2C_MCR[CLKSTRETCH] Bits */
#define I2C_MCR_CLKSTRETCH_OFS                   (2)                             /* !< CLKSTRETCH Offset */
#define I2C_MCR_CLKSTRETCH_MASK                  ((uint32_t)0x00000004U)         /* !< Clock Stretching. This bit controls
                                                                                    the support for clock stretching of
                                                                                    the I2C bus. */
#define I2C_MCR_CLKSTRETCH_DISABLE               ((uint32_t)0x00000000U)         /* !< Disables the clock stretching
                                                                                    detection. This can be disabled if no
                                                                                    Target on the bus does support clock
                                                                                    stretching, so that the maximum speed
                                                                                    on the bus can be reached. */
#define I2C_MCR_CLKSTRETCH_ENABLE                ((uint32_t)0x00000004U)         /* !< Enables the clock stretching
                                                                                    detection. Enabling the clock
                                                                                    stretching ensures compliance to the
                                                                                    I2C standard but could limit the
                                                                                    speed due the clock stretching. */

/* I2C_MBMON Bits */
/* I2C_MBMON[SCL] Bits */
#define I2C_MBMON_SCL_OFS                        (0)                             /* !< SCL Offset */
#define I2C_MBMON_SCL_MASK                       ((uint32_t)0x00000001U)         /* !< I2C SCL Status */
#define I2C_MBMON_SCL_CLEARED                    ((uint32_t)0x00000000U)         /* !< The I2CSCL signal is low. */
#define I2C_MBMON_SCL_SET                        ((uint32_t)0x00000001U)         /* !< The I2CSCL signal is high. Note:
                                                                                    During and right after reset, the SCL
                                                                                    pin is in GPIO input mode without the
                                                                                    internal pull enabled. For proper I2C
                                                                                    operation, the user should have the
                                                                                    external pull-up resistor in place
                                                                                    before starting any I2C operations. */
/* I2C_MBMON[SDA] Bits */
#define I2C_MBMON_SDA_OFS                        (1)                             /* !< SDA Offset */
#define I2C_MBMON_SDA_MASK                       ((uint32_t)0x00000002U)         /* !< I2C SDA Status */
#define I2C_MBMON_SDA_CLEARED                    ((uint32_t)0x00000000U)         /* !< The I2CSDA signal is low. */
#define I2C_MBMON_SDA_SET                        ((uint32_t)0x00000002U)         /* !< The I2CSDA signal is high. Note:
                                                                                    During and right after reset, the SDA
                                                                                    pin is in GPIO input mode without the
                                                                                    internal pull enabled. For proper I2C
                                                                                    operation, the user should have the
                                                                                    external pull-up resistor in place
                                                                                    before starting any I2C operations. */

/* I2C_MFIFOCTL Bits */
/* I2C_MFIFOCTL[TXTRIG] Bits */
#define I2C_MFIFOCTL_TXTRIG_OFS                  (0)                             /* !< TXTRIG Offset */
#define I2C_MFIFOCTL_TXTRIG_MASK                 ((uint32_t)0x00000007U)         /* !< TX FIFO Trigger Indicates at what
                                                                                    fill level in the TX FIFO a trigger
                                                                                    will be generated. */
#define I2C_MFIFOCTL_TXTRIG_EMPTY                ((uint32_t)0x00000000U)         /* !< Trigger when the TX FIFO is empty. */
#define I2C_MFIFOCTL_TXTRIG_LEVEL_1              ((uint32_t)0x00000001U)         /* !< Trigger when TX FIFO contains  1
                                                                                    byte */
#define I2C_MFIFOCTL_TXTRIG_LEVEL_2              ((uint32_t)0x00000002U)         /* !< Trigger when TX FIFO contains  2
                                                                                    byte */
#define I2C_MFIFOCTL_TXTRIG_LEVEL_3              ((uint32_t)0x00000003U)         /* !< Trigger when TX FIFO contains  3
                                                                                    byte */
#define I2C_MFIFOCTL_TXTRIG_LEVEL_4              ((uint32_t)0x00000004U)         /* !< Trigger when TX FIFO contains  4
                                                                                    byte */
#define I2C_MFIFOCTL_TXTRIG_LEVEL_5              ((uint32_t)0x00000005U)         /* !< Trigger when TX FIFO contains  5
                                                                                    byte */
#define I2C_MFIFOCTL_TXTRIG_LEVEL_6              ((uint32_t)0x00000006U)         /* !< Trigger when TX FIFO contains  6
                                                                                    byte */
#define I2C_MFIFOCTL_TXTRIG_LEVEL_7              ((uint32_t)0x00000007U)         /* !< Trigger when TX FIFO contains  7
                                                                                    byte */
/* I2C_MFIFOCTL[TXFLUSH] Bits */
#define I2C_MFIFOCTL_TXFLUSH_OFS                 (7)                             /* !< TXFLUSH Offset */
#define I2C_MFIFOCTL_TXFLUSH_MASK                ((uint32_t)0x00000080U)         /* !< TX FIFO Flush Setting this bit will
                                                                                    Flush the TX FIFO.  Before clearing
                                                                                    this bit to stop Flush the TXFIFOCNT
                                                                                    should be checked to be 8 and
                                                                                    indicating that the Flush has
                                                                                    completed. */
#define I2C_MFIFOCTL_TXFLUSH_NOFLUSH             ((uint32_t)0x00000000U)         /* !< Do not Flush FIFO */
#define I2C_MFIFOCTL_TXFLUSH_FLUSH               ((uint32_t)0x00000080U)         /* !< Flush FIFO */
/* I2C_MFIFOCTL[RXTRIG] Bits */
#define I2C_MFIFOCTL_RXTRIG_OFS                  (8)                             /* !< RXTRIG Offset */
#define I2C_MFIFOCTL_RXTRIG_MASK                 ((uint32_t)0x00000700U)         /* !< RX FIFO Trigger Indicates at what
                                                                                    fill level in the RX FIFO a trigger
                                                                                    will be generated. Note: Programming
                                                                                    RXTRIG to 0x0 has no effect since no
                                                                                    data is present to transfer out of RX
                                                                                    FIFO. */
#define I2C_MFIFOCTL_RXTRIG_LEVEL_1              ((uint32_t)0x00000000U)         /* !< Trigger when RX FIFO contains >= 1
                                                                                    byte */
#define I2C_MFIFOCTL_RXTRIG_LEVEL_2              ((uint32_t)0x00000100U)         /* !< Trigger when RX FIFO contains >= 2
                                                                                    byte */
#define I2C_MFIFOCTL_RXTRIG_LEVEL_3              ((uint32_t)0x00000200U)         /* !< Trigger when RX FIFO contains >= 3
                                                                                    byte */
#define I2C_MFIFOCTL_RXTRIG_LEVEL_4              ((uint32_t)0x00000300U)         /* !< Trigger when RX FIFO contains >= 4
                                                                                    byte */
#define I2C_MFIFOCTL_RXTRIG_LEVEL_5              ((uint32_t)0x00000400U)         /* !< Trigger when RX FIFO contains >= 5
                                                                                    byte */
#define I2C_MFIFOCTL_RXTRIG_LEVEL_6              ((uint32_t)0x00000500U)         /* !< Trigger when RX FIFO contains >= 6
                                                                                    byte */
#define I2C_MFIFOCTL_RXTRIG_LEVEL_7              ((uint32_t)0x00000600U)         /* !< Trigger when RX FIFO contains >= 7
                                                                                    byte */
#define I2C_MFIFOCTL_RXTRIG_LEVEL_8              ((uint32_t)0x00000700U)         /* !< Trigger when RX FIFO contains >= 8
                                                                                    byte */
/* I2C_MFIFOCTL[RXFLUSH] Bits */
#define I2C_MFIFOCTL_RXFLUSH_OFS                 (15)                            /* !< RXFLUSH Offset */
#define I2C_MFIFOCTL_RXFLUSH_MASK                ((uint32_t)0x00008000U)         /* !< RX FIFO Flush Setting this bit will
                                                                                    Flush the RX FIFO. Before clearing
                                                                                    this bit to stop Flush the RXFIFOCNT
                                                                                    should be checked to be 0 and
                                                                                    indicating that the Flush has
                                                                                    completed. */
#define I2C_MFIFOCTL_RXFLUSH_NOFLUSH             ((uint32_t)0x00000000U)         /* !< Do not Flush FIFO */
#define I2C_MFIFOCTL_RXFLUSH_FLUSH               ((uint32_t)0x00008000U)         /* !< Flush FIFO */

/* I2C_MFIFOSR Bits */
/* I2C_MFIFOSR[RXFIFOCNT] Bits */
#define I2C_MFIFOSR_RXFIFOCNT_OFS                (0)                             /* !< RXFIFOCNT Offset */
#define I2C_MFIFOSR_RXFIFOCNT_MASK               ((uint32_t)0x0000000FU)         /* !< Number of Bytes which could be read
                                                                                    from the RX FIFO */
#define I2C_MFIFOSR_RXFIFOCNT_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_MFIFOSR_RXFIFOCNT_MAXIMUM            ((uint32_t)0x00000008U)         /* !< Highest possible value */
/* I2C_MFIFOSR[TXFIFOCNT] Bits */
#define I2C_MFIFOSR_TXFIFOCNT_OFS                (8)                             /* !< TXFIFOCNT Offset */
#define I2C_MFIFOSR_TXFIFOCNT_MASK               ((uint32_t)0x00000F00U)         /* !< Number of Bytes which could be put
                                                                                    into the TX FIFO */
#define I2C_MFIFOSR_TXFIFOCNT_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_MFIFOSR_TXFIFOCNT_MAXIMUM            ((uint32_t)0x00000800U)         /* !< Highest possible value */
/* I2C_MFIFOSR[RXFLUSH] Bits */
#define I2C_MFIFOSR_RXFLUSH_OFS                  (7)                             /* !< RXFLUSH Offset */
#define I2C_MFIFOSR_RXFLUSH_MASK                 ((uint32_t)0x00000080U)         /* !< RX FIFO Flush When this bit is set
                                                                                    a Flush operation for the RX FIFO is
                                                                                    active. Clear the RXFLUSH bit in the
                                                                                    control register to stop. */
#define I2C_MFIFOSR_RXFLUSH_INACTIVE             ((uint32_t)0x00000000U)         /* !< FIFO Flush not active */
#define I2C_MFIFOSR_RXFLUSH_ACTIVE               ((uint32_t)0x00000080U)         /* !< FIFO Flush active */
/* I2C_MFIFOSR[TXFLUSH] Bits */
#define I2C_MFIFOSR_TXFLUSH_OFS                  (15)                            /* !< TXFLUSH Offset */
#define I2C_MFIFOSR_TXFLUSH_MASK                 ((uint32_t)0x00008000U)         /* !< TX FIFO Flush When this bit is set
                                                                                    a Flush operation for the TX FIFO is
                                                                                    active. Clear the TXFLUSH bit in the
                                                                                    control register to stop. */
#define I2C_MFIFOSR_TXFLUSH_INACTIVE             ((uint32_t)0x00000000U)         /* !< FIFO Flush not active */
#define I2C_MFIFOSR_TXFLUSH_ACTIVE               ((uint32_t)0x00008000U)         /* !< FIFO Flush active */

/* I2C_CONTROLLER_I2CPECCTL Bits */
/* I2C_CONTROLLER_I2CPECCTL[PECCNT] Bits */
#define I2C_CONTROLLER_I2CPECCTL_PECCNT_OFS      (0)                             /* !< PECCNT Offset */
#define I2C_CONTROLLER_I2CPECCTL_PECCNT_MASK     ((uint32_t)0x000001FFU)         /* !< PEC Count When this field is non
                                                                                    zero, the number of I2C bytes are
                                                                                    counted (Note that although the PEC
                                                                                    is calculated on the I2C address it
                                                                                    is not counted at a byte). When the
                                                                                    byte count = PECCNT and the state
                                                                                    machine is transmitting, the contents
                                                                                    of the LSFR is loaded into the shift
                                                                                    register instead of the byte received
                                                                                    from the Tx FIFO. When the state
                                                                                    machine is receiving, after the last
                                                                                    bit of this byte is received the LSFR
                                                                                    is checked and if it is non-zero, a
                                                                                    PEC RX Error interrupt is generated.
                                                                                    The I2C packet must be padded to
                                                                                    include the PEC byte for both
                                                                                    transmit and receive. In transmit
                                                                                    mode the FIFO must be loaded with a
                                                                                    dummy PEC byte. In receive mode the
                                                                                    PEC byte will be passed to the Rx
                                                                                    FIFO.  In the normal Controller use
                                                                                    case, FW would set PECEN=1 and
                                                                                    PECCNT=SMB packet length (Not
                                                                                    including Target Address byte, but
                                                                                    including the PEC byte). FW would
                                                                                    then configure DMA to allow the
                                                                                    packet to complete unassisted and
                                                                                    write MCTR to initiate the
                                                                                    transaction.  Note that when the byte
                                                                                    count = PEC CNT, the byte count is
                                                                                    reset to 0 and multiple PEC
                                                                                    calculation can automatically occur
                                                                                    within a single I2C transaction.
                                                                                    Note that any write to the
                                                                                    Controller_I2CPECCTL Register will
                                                                                    clear the current PEC Byte Count in
                                                                                    the Controller State Machine. */
#define I2C_CONTROLLER_I2CPECCTL_PECCNT_MINIMUM  ((uint32_t)0x00000000U)         /* !< Minimum Value */
#define I2C_CONTROLLER_I2CPECCTL_PECCNT_MAXIMUM  ((uint32_t)0x000001FFU)         /* !< Maximum Value */
/* I2C_CONTROLLER_I2CPECCTL[PECEN] Bits */
#define I2C_CONTROLLER_I2CPECCTL_PECEN_OFS       (12)                            /* !< PECEN Offset */
#define I2C_CONTROLLER_I2CPECCTL_PECEN_MASK      ((uint32_t)0x00001000U)         /* !< PEC Enable This bit enables the SMB
                                                                                    Packet Error Checking (PEC). When
                                                                                    enabled the PEC is calculated on all
                                                                                    bits except the Start, Stop, Ack and
                                                                                    Nack. The PEC LSFR and the Byte
                                                                                    Counter is set to 0 when the State
                                                                                    Machine is in the IDLE state, which
                                                                                    occur following a Stop or when a
                                                                                    timeout occurs. The Counter is also
                                                                                    set to 0 after the PEC byte is sent
                                                                                    or received. Note that the NACK is
                                                                                    automatically send following a PEC
                                                                                    byte that results in a PEC error. The
                                                                                    PEC Polynomial is x^8 + x^2 + x^1 +
                                                                                    1. */
#define I2C_CONTROLLER_I2CPECCTL_PECEN_DISABLE   ((uint32_t)0x00000000U)         /* !< PEC is disabled in Controller mode */
#define I2C_CONTROLLER_I2CPECCTL_PECEN_ENABLE    ((uint32_t)0x00001000U)         /* !< PEC is enabled in Controller mode */

/* I2C_CONTROLLER_PECSR Bits */
/* I2C_CONTROLLER_PECSR[PECBYTECNT] Bits */
#define I2C_CONTROLLER_PECSR_PECBYTECNT_OFS      (0)                             /* !< PECBYTECNT Offset */
#define I2C_CONTROLLER_PECSR_PECBYTECNT_MASK     ((uint32_t)0x000001FFU)         /* !< PEC Byte Count	 This is the current
                                                                                    PEC Byte Count of the Controller
                                                                                    State Machine. */
#define I2C_CONTROLLER_PECSR_PECBYTECNT_MINIMUM  ((uint32_t)0x00000000U)         /* !< Minimum Value */
#define I2C_CONTROLLER_PECSR_PECBYTECNT_MAXIMUM  ((uint32_t)0x000001FFU)         /* !< Maximum Value */
/* I2C_CONTROLLER_PECSR[PECSTS_CHECK] Bits */
#define I2C_CONTROLLER_PECSR_PECSTS_CHECK_OFS    (16)                            /* !< PECSTS_CHECK Offset */
#define I2C_CONTROLLER_PECSR_PECSTS_CHECK_MASK   ((uint32_t)0x00010000U)         /* !< This status bit indicates if the
                                                                                    PEC was checked in the transaction
                                                                                    that occurred before the last Stop.
                                                                                    Latched on Stop. */
#define I2C_CONTROLLER_PECSR_PECSTS_CHECK_CLEARED ((uint32_t)0x00000000U)         /* !< Indicates PEC was not checked in
                                                                                    the transaction that occurred before
                                                                                    the last Stop */
#define I2C_CONTROLLER_PECSR_PECSTS_CHECK_SET    ((uint32_t)0x00010000U)         /* !< Indicates if the PEC was checked in
                                                                                    the transaction that occurred before
                                                                                    the last Stop */
/* I2C_CONTROLLER_PECSR[PECSTS_ERROR] Bits */
#define I2C_CONTROLLER_PECSR_PECSTS_ERROR_OFS    (17)                            /* !< PECSTS_ERROR Offset */
#define I2C_CONTROLLER_PECSR_PECSTS_ERROR_MASK   ((uint32_t)0x00020000U)         /* !< This status bit indicates if a PEC
                                                                                    check error occurred in the
                                                                                    transaction that occurred before the
                                                                                    last Stop. Latched on Stop. */
#define I2C_CONTROLLER_PECSR_PECSTS_ERROR_CLEARED ((uint32_t)0x00000000U)         /* !< Indicates PEC check error did not
                                                                                    occurr in the transaction that
                                                                                    occurred before the last Stop */
#define I2C_CONTROLLER_PECSR_PECSTS_ERROR_SET    ((uint32_t)0x00020000U)         /* !< Indicates if a PEC check error
                                                                                    occurred in the transaction that
                                                                                    occurred before the last Stop */

/* I2C_DMA_TRIG0_IIDX Bits */
/* I2C_DMA_TRIG0_IIDX[STAT] Bits */
#define I2C_DMA_TRIG0_IIDX_STAT_OFS              (0)                             /* !< STAT Offset */
#define I2C_DMA_TRIG0_IIDX_STAT_MASK             ((uint32_t)0x000000FFU)         /* !< I2C Module Interrupt Vector Value.
                                                                                    This register provides the highes
                                                                                    priority interrupt index. A read
                                                                                    clears the corresponding interrupt
                                                                                    flag in RIS and MISC. 15h-1Fh =
                                                                                    Reserved */
#define I2C_DMA_TRIG0_IIDX_STAT_NO_INTR          ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define I2C_DMA_TRIG0_IIDX_STAT_MRXFIFOTRG       ((uint32_t)0x00000001U)         /* !< Controller receive FIFO Trigger
                                                                                    Level */
#define I2C_DMA_TRIG0_IIDX_STAT_MTXFIFOTRG       ((uint32_t)0x00000002U)         /* !< Controller transmit FIFO Trigger
                                                                                    level */
#define I2C_DMA_TRIG0_IIDX_STAT_SRXFIFOTRG       ((uint32_t)0x00000003U)         /* !< Target receive FIFO Trigger Level */
#define I2C_DMA_TRIG0_IIDX_STAT_STXFIFOTRG       ((uint32_t)0x00000004U)         /* !< Target transmit FIFO Trigger level */

/* I2C_DMA_TRIG0_IMASK Bits */
/* I2C_DMA_TRIG0_IMASK[MRXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_IMASK_MRXFIFOTRG_OFS       (0)                             /* !< MRXFIFOTRG Offset */
#define I2C_DMA_TRIG0_IMASK_MRXFIFOTRG_MASK      ((uint32_t)0x00000001U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_DMA_TRIG0_IMASK_MRXFIFOTRG_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_IMASK_MRXFIFOTRG_SET       ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_IMASK[MTXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_IMASK_MTXFIFOTRG_OFS       (1)                             /* !< MTXFIFOTRG Offset */
#define I2C_DMA_TRIG0_IMASK_MTXFIFOTRG_MASK      ((uint32_t)0x00000002U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_DMA_TRIG0_IMASK_MTXFIFOTRG_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_IMASK_MTXFIFOTRG_SET       ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_IMASK[SRXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_IMASK_SRXFIFOTRG_OFS       (2)                             /* !< SRXFIFOTRG Offset */
#define I2C_DMA_TRIG0_IMASK_SRXFIFOTRG_MASK      ((uint32_t)0x00000004U)         /* !< Target Receive FIFO Trigger */
#define I2C_DMA_TRIG0_IMASK_SRXFIFOTRG_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_IMASK_SRXFIFOTRG_SET       ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_IMASK[STXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_IMASK_STXFIFOTRG_OFS       (3)                             /* !< STXFIFOTRG Offset */
#define I2C_DMA_TRIG0_IMASK_STXFIFOTRG_MASK      ((uint32_t)0x00000008U)         /* !< Target Transmit FIFO Trigger */
#define I2C_DMA_TRIG0_IMASK_STXFIFOTRG_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_IMASK_STXFIFOTRG_SET       ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */

/* I2C_DMA_TRIG0_RIS Bits */
/* I2C_DMA_TRIG0_RIS[MRXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_RIS_MRXFIFOTRG_OFS         (0)                             /* !< MRXFIFOTRG Offset */
#define I2C_DMA_TRIG0_RIS_MRXFIFOTRG_MASK        ((uint32_t)0x00000001U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_DMA_TRIG0_RIS_MRXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_RIS_MRXFIFOTRG_SET         ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_RIS[MTXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_RIS_MTXFIFOTRG_OFS         (1)                             /* !< MTXFIFOTRG Offset */
#define I2C_DMA_TRIG0_RIS_MTXFIFOTRG_MASK        ((uint32_t)0x00000002U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_DMA_TRIG0_RIS_MTXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_RIS_MTXFIFOTRG_SET         ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_RIS[SRXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_RIS_SRXFIFOTRG_OFS         (2)                             /* !< SRXFIFOTRG Offset */
#define I2C_DMA_TRIG0_RIS_SRXFIFOTRG_MASK        ((uint32_t)0x00000004U)         /* !< Target Receive FIFO Trigger */
#define I2C_DMA_TRIG0_RIS_SRXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_RIS_SRXFIFOTRG_SET         ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_RIS[STXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_RIS_STXFIFOTRG_OFS         (3)                             /* !< STXFIFOTRG Offset */
#define I2C_DMA_TRIG0_RIS_STXFIFOTRG_MASK        ((uint32_t)0x00000008U)         /* !< Target Transmit FIFO Trigger */
#define I2C_DMA_TRIG0_RIS_STXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_RIS_STXFIFOTRG_SET         ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */

/* I2C_DMA_TRIG0_MIS Bits */
/* I2C_DMA_TRIG0_MIS[MRXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_MIS_MRXFIFOTRG_OFS         (0)                             /* !< MRXFIFOTRG Offset */
#define I2C_DMA_TRIG0_MIS_MRXFIFOTRG_MASK        ((uint32_t)0x00000001U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_DMA_TRIG0_MIS_MRXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_MIS_MRXFIFOTRG_SET         ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_MIS[MTXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_MIS_MTXFIFOTRG_OFS         (1)                             /* !< MTXFIFOTRG Offset */
#define I2C_DMA_TRIG0_MIS_MTXFIFOTRG_MASK        ((uint32_t)0x00000002U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_DMA_TRIG0_MIS_MTXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_MIS_MTXFIFOTRG_SET         ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_MIS[SRXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_MIS_SRXFIFOTRG_OFS         (2)                             /* !< SRXFIFOTRG Offset */
#define I2C_DMA_TRIG0_MIS_SRXFIFOTRG_MASK        ((uint32_t)0x00000004U)         /* !< Target Receive FIFO Trigger */
#define I2C_DMA_TRIG0_MIS_SRXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_MIS_SRXFIFOTRG_SET         ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_MIS[STXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_MIS_STXFIFOTRG_OFS         (3)                             /* !< STXFIFOTRG Offset */
#define I2C_DMA_TRIG0_MIS_STXFIFOTRG_MASK        ((uint32_t)0x00000008U)         /* !< Target Transmit FIFO Trigger */
#define I2C_DMA_TRIG0_MIS_STXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_MIS_STXFIFOTRG_SET         ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */

/* I2C_DMA_TRIG0_ISET Bits */
/* I2C_DMA_TRIG0_ISET[MRXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_ISET_MRXFIFOTRG_OFS        (0)                             /* !< MRXFIFOTRG Offset */
#define I2C_DMA_TRIG0_ISET_MRXFIFOTRG_MASK       ((uint32_t)0x00000001U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_DMA_TRIG0_ISET_MRXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_ISET_MRXFIFOTRG_SET        ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_ISET[MTXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_ISET_MTXFIFOTRG_OFS        (1)                             /* !< MTXFIFOTRG Offset */
#define I2C_DMA_TRIG0_ISET_MTXFIFOTRG_MASK       ((uint32_t)0x00000002U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_DMA_TRIG0_ISET_MTXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_ISET_MTXFIFOTRG_SET        ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_ISET[SRXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_ISET_SRXFIFOTRG_OFS        (2)                             /* !< SRXFIFOTRG Offset */
#define I2C_DMA_TRIG0_ISET_SRXFIFOTRG_MASK       ((uint32_t)0x00000004U)         /* !< Target Receive FIFO Trigger */
#define I2C_DMA_TRIG0_ISET_SRXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_ISET_SRXFIFOTRG_SET        ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_ISET[STXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_ISET_STXFIFOTRG_OFS        (3)                             /* !< STXFIFOTRG Offset */
#define I2C_DMA_TRIG0_ISET_STXFIFOTRG_MASK       ((uint32_t)0x00000008U)         /* !< Target Transmit FIFO Trigger */
#define I2C_DMA_TRIG0_ISET_STXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_ISET_STXFIFOTRG_SET        ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */

/* I2C_DMA_TRIG0_ICLR Bits */
/* I2C_DMA_TRIG0_ICLR[MRXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_ICLR_MRXFIFOTRG_OFS        (0)                             /* !< MRXFIFOTRG Offset */
#define I2C_DMA_TRIG0_ICLR_MRXFIFOTRG_MASK       ((uint32_t)0x00000001U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_DMA_TRIG0_ICLR_MRXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_ICLR_MRXFIFOTRG_CLR        ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_ICLR[MTXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_ICLR_MTXFIFOTRG_OFS        (1)                             /* !< MTXFIFOTRG Offset */
#define I2C_DMA_TRIG0_ICLR_MTXFIFOTRG_MASK       ((uint32_t)0x00000002U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_DMA_TRIG0_ICLR_MTXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_ICLR_MTXFIFOTRG_CLR        ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_ICLR[SRXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_ICLR_SRXFIFOTRG_OFS        (2)                             /* !< SRXFIFOTRG Offset */
#define I2C_DMA_TRIG0_ICLR_SRXFIFOTRG_MASK       ((uint32_t)0x00000004U)         /* !< Target Receive FIFO Trigger */
#define I2C_DMA_TRIG0_ICLR_SRXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_ICLR_SRXFIFOTRG_CLR        ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG0_ICLR[STXFIFOTRG] Bits */
#define I2C_DMA_TRIG0_ICLR_STXFIFOTRG_OFS        (3)                             /* !< STXFIFOTRG Offset */
#define I2C_DMA_TRIG0_ICLR_STXFIFOTRG_MASK       ((uint32_t)0x00000008U)         /* !< Target Transmit FIFO Trigger */
#define I2C_DMA_TRIG0_ICLR_STXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG0_ICLR_STXFIFOTRG_CLR        ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */

/* I2C_DMA_TRIG1_IIDX Bits */
/* I2C_DMA_TRIG1_IIDX[STAT] Bits */
#define I2C_DMA_TRIG1_IIDX_STAT_OFS              (0)                             /* !< STAT Offset */
#define I2C_DMA_TRIG1_IIDX_STAT_MASK             ((uint32_t)0x000000FFU)         /* !< I2C Module Interrupt Vector Value.
                                                                                    This register provides the highes
                                                                                    priority interrupt index. A read
                                                                                    clears the corresponding interrupt
                                                                                    flag in RIS and MISC. 15h-1Fh =
                                                                                    Reserved */
#define I2C_DMA_TRIG1_IIDX_STAT_NO_INTR          ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define I2C_DMA_TRIG1_IIDX_STAT_MRXFIFOTRG       ((uint32_t)0x00000001U)         /* !< Controller receive FIFO Trigger
                                                                                    Level */
#define I2C_DMA_TRIG1_IIDX_STAT_MTXFIFOTRG       ((uint32_t)0x00000002U)         /* !< Controller transmit FIFO Trigger
                                                                                    level */
#define I2C_DMA_TRIG1_IIDX_STAT_SRXFIFOTRG       ((uint32_t)0x00000003U)         /* !< Target receive FIFO Trigger Level */
#define I2C_DMA_TRIG1_IIDX_STAT_STXFIFOTRG       ((uint32_t)0x00000004U)         /* !< Target transmit FIFO Trigger level */

/* I2C_DMA_TRIG1_IMASK Bits */
/* I2C_DMA_TRIG1_IMASK[MRXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_IMASK_MRXFIFOTRG_OFS       (0)                             /* !< MRXFIFOTRG Offset */
#define I2C_DMA_TRIG1_IMASK_MRXFIFOTRG_MASK      ((uint32_t)0x00000001U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_DMA_TRIG1_IMASK_MRXFIFOTRG_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_IMASK_MRXFIFOTRG_SET       ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_IMASK[MTXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_IMASK_MTXFIFOTRG_OFS       (1)                             /* !< MTXFIFOTRG Offset */
#define I2C_DMA_TRIG1_IMASK_MTXFIFOTRG_MASK      ((uint32_t)0x00000002U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_DMA_TRIG1_IMASK_MTXFIFOTRG_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_IMASK_MTXFIFOTRG_SET       ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_IMASK[SRXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_IMASK_SRXFIFOTRG_OFS       (2)                             /* !< SRXFIFOTRG Offset */
#define I2C_DMA_TRIG1_IMASK_SRXFIFOTRG_MASK      ((uint32_t)0x00000004U)         /* !< Target Receive FIFO Trigger */
#define I2C_DMA_TRIG1_IMASK_SRXFIFOTRG_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_IMASK_SRXFIFOTRG_SET       ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_IMASK[STXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_IMASK_STXFIFOTRG_OFS       (3)                             /* !< STXFIFOTRG Offset */
#define I2C_DMA_TRIG1_IMASK_STXFIFOTRG_MASK      ((uint32_t)0x00000008U)         /* !< Target Transmit FIFO Trigger */
#define I2C_DMA_TRIG1_IMASK_STXFIFOTRG_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_IMASK_STXFIFOTRG_SET       ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */

/* I2C_DMA_TRIG1_RIS Bits */
/* I2C_DMA_TRIG1_RIS[MRXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_RIS_MRXFIFOTRG_OFS         (0)                             /* !< MRXFIFOTRG Offset */
#define I2C_DMA_TRIG1_RIS_MRXFIFOTRG_MASK        ((uint32_t)0x00000001U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_DMA_TRIG1_RIS_MRXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_RIS_MRXFIFOTRG_SET         ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_RIS[MTXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_RIS_MTXFIFOTRG_OFS         (1)                             /* !< MTXFIFOTRG Offset */
#define I2C_DMA_TRIG1_RIS_MTXFIFOTRG_MASK        ((uint32_t)0x00000002U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_DMA_TRIG1_RIS_MTXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_RIS_MTXFIFOTRG_SET         ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_RIS[SRXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_RIS_SRXFIFOTRG_OFS         (2)                             /* !< SRXFIFOTRG Offset */
#define I2C_DMA_TRIG1_RIS_SRXFIFOTRG_MASK        ((uint32_t)0x00000004U)         /* !< Target Receive FIFO Trigger */
#define I2C_DMA_TRIG1_RIS_SRXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_RIS_SRXFIFOTRG_SET         ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_RIS[STXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_RIS_STXFIFOTRG_OFS         (3)                             /* !< STXFIFOTRG Offset */
#define I2C_DMA_TRIG1_RIS_STXFIFOTRG_MASK        ((uint32_t)0x00000008U)         /* !< Target Transmit FIFO Trigger */
#define I2C_DMA_TRIG1_RIS_STXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_RIS_STXFIFOTRG_SET         ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */

/* I2C_DMA_TRIG1_MIS Bits */
/* I2C_DMA_TRIG1_MIS[MRXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_MIS_MRXFIFOTRG_OFS         (0)                             /* !< MRXFIFOTRG Offset */
#define I2C_DMA_TRIG1_MIS_MRXFIFOTRG_MASK        ((uint32_t)0x00000001U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_DMA_TRIG1_MIS_MRXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_MIS_MRXFIFOTRG_SET         ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_MIS[MTXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_MIS_MTXFIFOTRG_OFS         (1)                             /* !< MTXFIFOTRG Offset */
#define I2C_DMA_TRIG1_MIS_MTXFIFOTRG_MASK        ((uint32_t)0x00000002U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_DMA_TRIG1_MIS_MTXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_MIS_MTXFIFOTRG_SET         ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_MIS[SRXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_MIS_SRXFIFOTRG_OFS         (2)                             /* !< SRXFIFOTRG Offset */
#define I2C_DMA_TRIG1_MIS_SRXFIFOTRG_MASK        ((uint32_t)0x00000004U)         /* !< Target Receive FIFO Trigger */
#define I2C_DMA_TRIG1_MIS_SRXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_MIS_SRXFIFOTRG_SET         ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_MIS[STXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_MIS_STXFIFOTRG_OFS         (3)                             /* !< STXFIFOTRG Offset */
#define I2C_DMA_TRIG1_MIS_STXFIFOTRG_MASK        ((uint32_t)0x00000008U)         /* !< Target Transmit FIFO Trigger */
#define I2C_DMA_TRIG1_MIS_STXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_MIS_STXFIFOTRG_SET         ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */

/* I2C_DMA_TRIG1_ISET Bits */
/* I2C_DMA_TRIG1_ISET[MRXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_ISET_MRXFIFOTRG_OFS        (0)                             /* !< MRXFIFOTRG Offset */
#define I2C_DMA_TRIG1_ISET_MRXFIFOTRG_MASK       ((uint32_t)0x00000001U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_DMA_TRIG1_ISET_MRXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_ISET_MRXFIFOTRG_SET        ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_ISET[MTXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_ISET_MTXFIFOTRG_OFS        (1)                             /* !< MTXFIFOTRG Offset */
#define I2C_DMA_TRIG1_ISET_MTXFIFOTRG_MASK       ((uint32_t)0x00000002U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_DMA_TRIG1_ISET_MTXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_ISET_MTXFIFOTRG_SET        ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_ISET[SRXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_ISET_SRXFIFOTRG_OFS        (2)                             /* !< SRXFIFOTRG Offset */
#define I2C_DMA_TRIG1_ISET_SRXFIFOTRG_MASK       ((uint32_t)0x00000004U)         /* !< Target Receive FIFO Trigger */
#define I2C_DMA_TRIG1_ISET_SRXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_ISET_SRXFIFOTRG_SET        ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_ISET[STXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_ISET_STXFIFOTRG_OFS        (3)                             /* !< STXFIFOTRG Offset */
#define I2C_DMA_TRIG1_ISET_STXFIFOTRG_MASK       ((uint32_t)0x00000008U)         /* !< Target Transmit FIFO Trigger */
#define I2C_DMA_TRIG1_ISET_STXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_ISET_STXFIFOTRG_SET        ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */

/* I2C_DMA_TRIG1_ICLR Bits */
/* I2C_DMA_TRIG1_ICLR[MRXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_ICLR_MRXFIFOTRG_OFS        (0)                             /* !< MRXFIFOTRG Offset */
#define I2C_DMA_TRIG1_ICLR_MRXFIFOTRG_MASK       ((uint32_t)0x00000001U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_DMA_TRIG1_ICLR_MRXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_ICLR_MRXFIFOTRG_CLR        ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_ICLR[MTXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_ICLR_MTXFIFOTRG_OFS        (1)                             /* !< MTXFIFOTRG Offset */
#define I2C_DMA_TRIG1_ICLR_MTXFIFOTRG_MASK       ((uint32_t)0x00000002U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_DMA_TRIG1_ICLR_MTXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_ICLR_MTXFIFOTRG_CLR        ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_ICLR[SRXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_ICLR_SRXFIFOTRG_OFS        (2)                             /* !< SRXFIFOTRG Offset */
#define I2C_DMA_TRIG1_ICLR_SRXFIFOTRG_MASK       ((uint32_t)0x00000004U)         /* !< Target Receive FIFO Trigger */
#define I2C_DMA_TRIG1_ICLR_SRXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_ICLR_SRXFIFOTRG_CLR        ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_DMA_TRIG1_ICLR[STXFIFOTRG] Bits */
#define I2C_DMA_TRIG1_ICLR_STXFIFOTRG_OFS        (3)                             /* !< STXFIFOTRG Offset */
#define I2C_DMA_TRIG1_ICLR_STXFIFOTRG_MASK       ((uint32_t)0x00000008U)         /* !< Target Transmit FIFO Trigger */
#define I2C_DMA_TRIG1_ICLR_STXFIFOTRG_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_DMA_TRIG1_ICLR_STXFIFOTRG_CLR        ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */

/* I2C_CPU_INT_IIDX Bits */
/* I2C_CPU_INT_IIDX[STAT] Bits */
#define I2C_CPU_INT_IIDX_STAT_OFS                (0)                             /* !< STAT Offset */
#define I2C_CPU_INT_IIDX_STAT_MASK               ((uint32_t)0x000000FFU)         /* !< I2C Module Interrupt Vector Value.
                                                                                    This register provides the highes
                                                                                    priority interrupt index. A read
                                                                                    clears the corresponding interrupt
                                                                                    flag in RIS and MISC. 15h-1Fh =
                                                                                    Reserved */
#define I2C_CPU_INT_IIDX_STAT_NO_INTR            ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define I2C_CPU_INT_IIDX_STAT_MRXDONEFG          ((uint32_t)0x00000001U)         /* !< Controller data received */
#define I2C_CPU_INT_IIDX_STAT_MTXDONEFG          ((uint32_t)0x00000002U)         /* !< Controller data transmitted */
#define I2C_CPU_INT_IIDX_STAT_MRXFIFOTRG         ((uint32_t)0x00000003U)         /* !< Controller receive FIFO Trigger
                                                                                    Level */
#define I2C_CPU_INT_IIDX_STAT_MTXFIFOTRG         ((uint32_t)0x00000004U)         /* !< Controller transmit FIFO Trigger
                                                                                    level */
#define I2C_CPU_INT_IIDX_STAT_MRXFIFOFULL        ((uint32_t)0x00000005U)         /* !< RX FIFO FULL Event/interrupt
                                                                                    pending */
#define I2C_CPU_INT_IIDX_STAT_MTX_EMPTY          ((uint32_t)0x00000006U)         /* !< Transmit FIFO/Buffer Empty
                                                                                    Event/interrupt pending */
#define I2C_CPU_INT_IIDX_STAT_MNACKFG            ((uint32_t)0x00000008U)         /* !< Address/Data NACK */
#define I2C_CPU_INT_IIDX_STAT_MSTARTFG           ((uint32_t)0x00000009U)         /* !< Start Event */
#define I2C_CPU_INT_IIDX_STAT_MSTOPFG            ((uint32_t)0x0000000AU)         /* !< Stop Event */
#define I2C_CPU_INT_IIDX_STAT_MARBLOSTFG         ((uint32_t)0x0000000BU)         /* !< Arbitration Lost */
#define I2C_CPU_INT_IIDX_STAT_MDMA_DONE_TX       ((uint32_t)0x0000000CU)         /* !< DMA DONE on Channel TX */
#define I2C_CPU_INT_IIDX_STAT_MDMA_DONE_RX       ((uint32_t)0x0000000DU)         /* !< DMA DONE on Channel RX */
#define I2C_CPU_INT_IIDX_STAT_MPEC_RX_ERR        ((uint32_t)0x0000000EU)         /* !< Controller PEC Receive Error Event */
#define I2C_CPU_INT_IIDX_STAT_TIMEOUTA           ((uint32_t)0x0000000FU)         /* !< Timeout A Event */
#define I2C_CPU_INT_IIDX_STAT_TIMEOUTB           ((uint32_t)0x00000010U)         /* !< Timeout B Event */
#define I2C_CPU_INT_IIDX_STAT_SRXDONEFG          ((uint32_t)0x00000011U)         /* !< Target Data Event */
#define I2C_CPU_INT_IIDX_STAT_STXDONEFG          ((uint32_t)0x00000012U)         /* !< Target Data Event */
#define I2C_CPU_INT_IIDX_STAT_SRXFIFOTRG         ((uint32_t)0x00000013U)         /* !< Target receive FIFO Trigger Level */
#define I2C_CPU_INT_IIDX_STAT_STXFIFOTRG         ((uint32_t)0x00000014U)         /* !< Target transmit FIFO Trigger level */
#define I2C_CPU_INT_IIDX_STAT_SRXFIFOFULL        ((uint32_t)0x00000015U)         /* !< RX FIFO FULL Event/interrupt
                                                                                    pending */
#define I2C_CPU_INT_IIDX_STAT_STXEMPTY           ((uint32_t)0x00000016U)         /* !< Transmit FIFO/Buffer Empty
                                                                                    Event/interrupt pending */
#define I2C_CPU_INT_IIDX_STAT_SSTARTFG           ((uint32_t)0x00000017U)         /* !< Start Event */
#define I2C_CPU_INT_IIDX_STAT_SSTOPFG            ((uint32_t)0x00000018U)         /* !< Stop Event */
#define I2C_CPU_INT_IIDX_STAT_SGENCALL           ((uint32_t)0x00000019U)         /* !< General Call Event */
#define I2C_CPU_INT_IIDX_STAT_SDMA_DONE_TX       ((uint32_t)0x0000001AU)         /* !< DMA DONE on Channel TX */
#define I2C_CPU_INT_IIDX_STAT_SDMA_DONE_RX       ((uint32_t)0x0000001BU)         /* !< DMA DONE on Channel RX */
#define I2C_CPU_INT_IIDX_STAT_SPEC_RX_ERR        ((uint32_t)0x0000001CU)         /* !< Target PEC receive error event */
#define I2C_CPU_INT_IIDX_STAT_STX_UNFL           ((uint32_t)0x0000001DU)         /* !< Target TX FIFO underflow */
#define I2C_CPU_INT_IIDX_STAT_SRX_OVFL           ((uint32_t)0x0000001EU)         /* !< Target RX FIFO overflow event */
#define I2C_CPU_INT_IIDX_STAT_SARBLOST           ((uint32_t)0x0000001FU)         /* !< Target arbitration lost event */
#define I2C_CPU_INT_IIDX_STAT_INTR_OVFL          ((uint32_t)0x00000020U)         /* !< Interrupt overflow event */

/* I2C_CPU_INT_IMASK Bits */
/* I2C_CPU_INT_IMASK[MRXDONE] Bits */
#define I2C_CPU_INT_IMASK_MRXDONE_OFS            (0)                             /* !< MRXDONE Offset */
#define I2C_CPU_INT_IMASK_MRXDONE_MASK           ((uint32_t)0x00000001U)         /* !< Controller Receive Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_IMASK_MRXDONE_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_MRXDONE_SET            ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[TIMEOUTA] Bits */
#define I2C_CPU_INT_IMASK_TIMEOUTA_OFS           (14)                            /* !< TIMEOUTA Offset */
#define I2C_CPU_INT_IMASK_TIMEOUTA_MASK          ((uint32_t)0x00004000U)         /* !< Timeout A Interrupt */
#define I2C_CPU_INT_IMASK_TIMEOUTA_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_TIMEOUTA_SET           ((uint32_t)0x00004000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MNACK] Bits */
#define I2C_CPU_INT_IMASK_MNACK_OFS              (7)                             /* !< MNACK Offset */
#define I2C_CPU_INT_IMASK_MNACK_MASK             ((uint32_t)0x00000080U)         /* !< Address/Data NACK Interrupt */
#define I2C_CPU_INT_IMASK_MNACK_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_MNACK_SET              ((uint32_t)0x00000080U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MSTART] Bits */
#define I2C_CPU_INT_IMASK_MSTART_OFS             (8)                             /* !< MSTART Offset */
#define I2C_CPU_INT_IMASK_MSTART_MASK            ((uint32_t)0x00000100U)         /* !< START Detection Interrupt */
#define I2C_CPU_INT_IMASK_MSTART_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_MSTART_SET             ((uint32_t)0x00000100U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MSTOP] Bits */
#define I2C_CPU_INT_IMASK_MSTOP_OFS              (9)                             /* !< MSTOP Offset */
#define I2C_CPU_INT_IMASK_MSTOP_MASK             ((uint32_t)0x00000200U)         /* !< STOP Detection Interrupt */
#define I2C_CPU_INT_IMASK_MSTOP_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_MSTOP_SET              ((uint32_t)0x00000200U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MARBLOST] Bits */
#define I2C_CPU_INT_IMASK_MARBLOST_OFS           (10)                            /* !< MARBLOST Offset */
#define I2C_CPU_INT_IMASK_MARBLOST_MASK          ((uint32_t)0x00000400U)         /* !< Arbitration Lost Interrupt */
#define I2C_CPU_INT_IMASK_MARBLOST_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_MARBLOST_SET           ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MTXDONE] Bits */
#define I2C_CPU_INT_IMASK_MTXDONE_OFS            (1)                             /* !< MTXDONE Offset */
#define I2C_CPU_INT_IMASK_MTXDONE_MASK           ((uint32_t)0x00000002U)         /* !< Controller Transmit Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_IMASK_MTXDONE_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_MTXDONE_SET            ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MRXFIFOFULL] Bits */
#define I2C_CPU_INT_IMASK_MRXFIFOFULL_OFS        (4)                             /* !< MRXFIFOFULL Offset */
#define I2C_CPU_INT_IMASK_MRXFIFOFULL_MASK       ((uint32_t)0x00000010U)         /* !< RXFIFO full event. This interrupt
                                                                                    is set if an RX FIFO is full. */
#define I2C_CPU_INT_IMASK_MRXFIFOFULL_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_MRXFIFOFULL_SET        ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MTXEMPTY] Bits */
#define I2C_CPU_INT_IMASK_MTXEMPTY_OFS           (5)                             /* !< MTXEMPTY Offset */
#define I2C_CPU_INT_IMASK_MTXEMPTY_MASK          ((uint32_t)0x00000020U)         /* !< Transmit FIFO Empty interrupt mask.
                                                                                    This interrupt is set if all data in
                                                                                    the Transmit FIFO have been shifted
                                                                                    out and the transmit goes into idle
                                                                                    mode. */
#define I2C_CPU_INT_IMASK_MTXEMPTY_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_MTXEMPTY_SET           ((uint32_t)0x00000020U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MRXFIFOTRG] Bits */
#define I2C_CPU_INT_IMASK_MRXFIFOTRG_OFS         (2)                             /* !< MRXFIFOTRG Offset */
#define I2C_CPU_INT_IMASK_MRXFIFOTRG_MASK        ((uint32_t)0x00000004U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_CPU_INT_IMASK_MRXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_MRXFIFOTRG_SET         ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MTXFIFOTRG] Bits */
#define I2C_CPU_INT_IMASK_MTXFIFOTRG_OFS         (3)                             /* !< MTXFIFOTRG Offset */
#define I2C_CPU_INT_IMASK_MTXFIFOTRG_MASK        ((uint32_t)0x00000008U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_CPU_INT_IMASK_MTXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_MTXFIFOTRG_SET         ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MDMA_DONE_TX] Bits */
#define I2C_CPU_INT_IMASK_MDMA_DONE_TX_OFS       (11)                            /* !< MDMA_DONE_TX Offset */
#define I2C_CPU_INT_IMASK_MDMA_DONE_TX_MASK      ((uint32_t)0x00000800U)         /* !< DMA Done on Event Channel TX */
#define I2C_CPU_INT_IMASK_MDMA_DONE_TX_CLR       ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define I2C_CPU_INT_IMASK_MDMA_DONE_TX_SET       ((uint32_t)0x00000800U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MDMA_DONE_RX] Bits */
#define I2C_CPU_INT_IMASK_MDMA_DONE_RX_OFS       (12)                            /* !< MDMA_DONE_RX Offset */
#define I2C_CPU_INT_IMASK_MDMA_DONE_RX_MASK      ((uint32_t)0x00001000U)         /* !< DMA Done on Event Channel RX */
#define I2C_CPU_INT_IMASK_MDMA_DONE_RX_CLR       ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define I2C_CPU_INT_IMASK_MDMA_DONE_RX_SET       ((uint32_t)0x00001000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[SRXDONE] Bits */
#define I2C_CPU_INT_IMASK_SRXDONE_OFS            (16)                            /* !< SRXDONE Offset */
#define I2C_CPU_INT_IMASK_SRXDONE_MASK           ((uint32_t)0x00010000U)         /* !< Target Receive Data Interrupt
                                                                                    Signals that a byte has been received */
#define I2C_CPU_INT_IMASK_SRXDONE_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_SRXDONE_SET            ((uint32_t)0x00010000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[STXDONE] Bits */
#define I2C_CPU_INT_IMASK_STXDONE_OFS            (17)                            /* !< STXDONE Offset */
#define I2C_CPU_INT_IMASK_STXDONE_MASK           ((uint32_t)0x00020000U)         /* !< Target Transmit Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_IMASK_STXDONE_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_STXDONE_SET            ((uint32_t)0x00020000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[SGENCALL] Bits */
#define I2C_CPU_INT_IMASK_SGENCALL_OFS           (24)                            /* !< SGENCALL Offset */
#define I2C_CPU_INT_IMASK_SGENCALL_MASK          ((uint32_t)0x01000000U)         /* !< General Call Interrupt */
#define I2C_CPU_INT_IMASK_SGENCALL_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_SGENCALL_SET           ((uint32_t)0x01000000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[STXEMPTY] Bits */
#define I2C_CPU_INT_IMASK_STXEMPTY_OFS           (21)                            /* !< STXEMPTY Offset */
#define I2C_CPU_INT_IMASK_STXEMPTY_MASK          ((uint32_t)0x00200000U)         /* !< Target Transmit FIFO Empty
                                                                                    interrupt mask. This interrupt is set
                                                                                    if all data in the Transmit FIFO have
                                                                                    been shifted out and the transmit
                                                                                    goes into idle mode. */
#define I2C_CPU_INT_IMASK_STXEMPTY_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_STXEMPTY_SET           ((uint32_t)0x00200000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[SRXFIFOFULL] Bits */
#define I2C_CPU_INT_IMASK_SRXFIFOFULL_OFS        (20)                            /* !< SRXFIFOFULL Offset */
#define I2C_CPU_INT_IMASK_SRXFIFOFULL_MASK       ((uint32_t)0x00100000U)         /* !< RXFIFO full event. This interrupt
                                                                                    is set if an Target RX FIFO is full. */
#define I2C_CPU_INT_IMASK_SRXFIFOFULL_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_SRXFIFOFULL_SET        ((uint32_t)0x00100000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[SRXFIFOTRG] Bits */
#define I2C_CPU_INT_IMASK_SRXFIFOTRG_OFS         (18)                            /* !< SRXFIFOTRG Offset */
#define I2C_CPU_INT_IMASK_SRXFIFOTRG_MASK        ((uint32_t)0x00040000U)         /* !< Target Receive FIFO Trigger */
#define I2C_CPU_INT_IMASK_SRXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_SRXFIFOTRG_SET         ((uint32_t)0x00040000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[STXFIFOTRG] Bits */
#define I2C_CPU_INT_IMASK_STXFIFOTRG_OFS         (19)                            /* !< STXFIFOTRG Offset */
#define I2C_CPU_INT_IMASK_STXFIFOTRG_MASK        ((uint32_t)0x00080000U)         /* !< Target Transmit FIFO Trigger */
#define I2C_CPU_INT_IMASK_STXFIFOTRG_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_STXFIFOTRG_SET         ((uint32_t)0x00080000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[SSTART] Bits */
#define I2C_CPU_INT_IMASK_SSTART_OFS             (22)                            /* !< SSTART Offset */
#define I2C_CPU_INT_IMASK_SSTART_MASK            ((uint32_t)0x00400000U)         /* !< Start Condition Interrupt */
#define I2C_CPU_INT_IMASK_SSTART_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_SSTART_SET             ((uint32_t)0x00400000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[SSTOP] Bits */
#define I2C_CPU_INT_IMASK_SSTOP_OFS              (23)                            /* !< SSTOP Offset */
#define I2C_CPU_INT_IMASK_SSTOP_MASK             ((uint32_t)0x00800000U)         /* !< Stop Condition Interrupt */
#define I2C_CPU_INT_IMASK_SSTOP_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_SSTOP_SET              ((uint32_t)0x00800000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[SDMA_DONE_TX] Bits */
#define I2C_CPU_INT_IMASK_SDMA_DONE_TX_OFS       (25)                            /* !< SDMA_DONE_TX Offset */
#define I2C_CPU_INT_IMASK_SDMA_DONE_TX_MASK      ((uint32_t)0x02000000U)         /* !< Target DMA Done on Event Channel TX */
#define I2C_CPU_INT_IMASK_SDMA_DONE_TX_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_SDMA_DONE_TX_SET       ((uint32_t)0x02000000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[SDMA_DONE_RX] Bits */
#define I2C_CPU_INT_IMASK_SDMA_DONE_RX_OFS       (26)                            /* !< SDMA_DONE_RX Offset */
#define I2C_CPU_INT_IMASK_SDMA_DONE_RX_MASK      ((uint32_t)0x04000000U)         /* !< Target DMA Done on Event Channel RX */
#define I2C_CPU_INT_IMASK_SDMA_DONE_RX_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_SDMA_DONE_RX_SET       ((uint32_t)0x04000000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[MPEC_RX_ERR] Bits */
#define I2C_CPU_INT_IMASK_MPEC_RX_ERR_OFS        (13)                            /* !< MPEC_RX_ERR Offset */
#define I2C_CPU_INT_IMASK_MPEC_RX_ERR_MASK       ((uint32_t)0x00002000U)         /* !< Controller RX Pec Error Interrupt */
#define I2C_CPU_INT_IMASK_MPEC_RX_ERR_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_MPEC_RX_ERR_SET        ((uint32_t)0x00002000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[TIMEOUTB] Bits */
#define I2C_CPU_INT_IMASK_TIMEOUTB_OFS           (15)                            /* !< TIMEOUTB Offset */
#define I2C_CPU_INT_IMASK_TIMEOUTB_MASK          ((uint32_t)0x00008000U)         /* !< Timeout B Interrupt */
#define I2C_CPU_INT_IMASK_TIMEOUTB_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_TIMEOUTB_SET           ((uint32_t)0x00008000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[SPEC_RX_ERR] Bits */
#define I2C_CPU_INT_IMASK_SPEC_RX_ERR_OFS        (27)                            /* !< SPEC_RX_ERR Offset */
#define I2C_CPU_INT_IMASK_SPEC_RX_ERR_MASK       ((uint32_t)0x08000000U)         /* !< Target RX Pec Error Interrupt */
#define I2C_CPU_INT_IMASK_SPEC_RX_ERR_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_SPEC_RX_ERR_SET        ((uint32_t)0x08000000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[STX_UNFL] Bits */
#define I2C_CPU_INT_IMASK_STX_UNFL_OFS           (28)                            /* !< STX_UNFL Offset */
#define I2C_CPU_INT_IMASK_STX_UNFL_MASK          ((uint32_t)0x10000000U)         /* !< Target TX FIFO underflow */
#define I2C_CPU_INT_IMASK_STX_UNFL_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_STX_UNFL_SET           ((uint32_t)0x10000000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[SRX_OVFL] Bits */
#define I2C_CPU_INT_IMASK_SRX_OVFL_OFS           (29)                            /* !< SRX_OVFL Offset */
#define I2C_CPU_INT_IMASK_SRX_OVFL_MASK          ((uint32_t)0x20000000U)         /* !< Target RX FIFO overflow */
#define I2C_CPU_INT_IMASK_SRX_OVFL_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_SRX_OVFL_SET           ((uint32_t)0x20000000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[SARBLOST] Bits */
#define I2C_CPU_INT_IMASK_SARBLOST_OFS           (30)                            /* !< SARBLOST Offset */
#define I2C_CPU_INT_IMASK_SARBLOST_MASK          ((uint32_t)0x40000000U)         /* !< Target Arbitration Lost */
#define I2C_CPU_INT_IMASK_SARBLOST_CLR           ((uint32_t)0x00000000U)         /* !< Clear Set Interrupt Mask */
#define I2C_CPU_INT_IMASK_SARBLOST_SET           ((uint32_t)0x40000000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_IMASK[INTR_OVFL] Bits */
#define I2C_CPU_INT_IMASK_INTR_OVFL_OFS          (31)                            /* !< INTR_OVFL Offset */
#define I2C_CPU_INT_IMASK_INTR_OVFL_MASK         ((uint32_t)0x80000000U)         /* !< Interrupt Overflow Interrupt Mask */
#define I2C_CPU_INT_IMASK_INTR_OVFL_CLR          ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_IMASK_INTR_OVFL_SET          ((uint32_t)0x80000000U)         /* !< Set Interrupt Mask */

/* I2C_CPU_INT_RIS Bits */
/* I2C_CPU_INT_RIS[MRXDONE] Bits */
#define I2C_CPU_INT_RIS_MRXDONE_OFS              (0)                             /* !< MRXDONE Offset */
#define I2C_CPU_INT_RIS_MRXDONE_MASK             ((uint32_t)0x00000001U)         /* !< Controller Receive Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_RIS_MRXDONE_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_MRXDONE_SET              ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[TIMEOUTA] Bits */
#define I2C_CPU_INT_RIS_TIMEOUTA_OFS             (14)                            /* !< TIMEOUTA Offset */
#define I2C_CPU_INT_RIS_TIMEOUTA_MASK            ((uint32_t)0x00004000U)         /* !< Timeout A Interrupt */
#define I2C_CPU_INT_RIS_TIMEOUTA_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_TIMEOUTA_SET             ((uint32_t)0x00004000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[MNACK] Bits */
#define I2C_CPU_INT_RIS_MNACK_OFS                (7)                             /* !< MNACK Offset */
#define I2C_CPU_INT_RIS_MNACK_MASK               ((uint32_t)0x00000080U)         /* !< Address/Data NACK Interrupt */
#define I2C_CPU_INT_RIS_MNACK_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_MNACK_SET                ((uint32_t)0x00000080U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[MSTART] Bits */
#define I2C_CPU_INT_RIS_MSTART_OFS               (8)                             /* !< MSTART Offset */
#define I2C_CPU_INT_RIS_MSTART_MASK              ((uint32_t)0x00000100U)         /* !< START Detection Interrupt */
#define I2C_CPU_INT_RIS_MSTART_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_MSTART_SET               ((uint32_t)0x00000100U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[MSTOP] Bits */
#define I2C_CPU_INT_RIS_MSTOP_OFS                (9)                             /* !< MSTOP Offset */
#define I2C_CPU_INT_RIS_MSTOP_MASK               ((uint32_t)0x00000200U)         /* !< STOP Detection Interrupt */
#define I2C_CPU_INT_RIS_MSTOP_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_MSTOP_SET                ((uint32_t)0x00000200U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[MARBLOST] Bits */
#define I2C_CPU_INT_RIS_MARBLOST_OFS             (10)                            /* !< MARBLOST Offset */
#define I2C_CPU_INT_RIS_MARBLOST_MASK            ((uint32_t)0x00000400U)         /* !< Arbitration Lost Interrupt */
#define I2C_CPU_INT_RIS_MARBLOST_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_MARBLOST_SET             ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[MTXDONE] Bits */
#define I2C_CPU_INT_RIS_MTXDONE_OFS              (1)                             /* !< MTXDONE Offset */
#define I2C_CPU_INT_RIS_MTXDONE_MASK             ((uint32_t)0x00000002U)         /* !< Controller Transmit Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_RIS_MTXDONE_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_MTXDONE_SET              ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[MRXFIFOFULL] Bits */
#define I2C_CPU_INT_RIS_MRXFIFOFULL_OFS          (4)                             /* !< MRXFIFOFULL Offset */
#define I2C_CPU_INT_RIS_MRXFIFOFULL_MASK         ((uint32_t)0x00000010U)         /* !< RXFIFO full event. This interrupt
                                                                                    is set if an RX FIFO is full. */
#define I2C_CPU_INT_RIS_MRXFIFOFULL_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_MRXFIFOFULL_SET          ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[MTXEMPTY] Bits */
#define I2C_CPU_INT_RIS_MTXEMPTY_OFS             (5)                             /* !< MTXEMPTY Offset */
#define I2C_CPU_INT_RIS_MTXEMPTY_MASK            ((uint32_t)0x00000020U)         /* !< Transmit FIFO Empty interrupt mask.
                                                                                    This interrupt is set if all data in
                                                                                    the Transmit FIFO have been shifted
                                                                                    out and the transmit goes into idle
                                                                                    mode. */
#define I2C_CPU_INT_RIS_MTXEMPTY_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_MTXEMPTY_SET             ((uint32_t)0x00000020U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[MRXFIFOTRG] Bits */
#define I2C_CPU_INT_RIS_MRXFIFOTRG_OFS           (2)                             /* !< MRXFIFOTRG Offset */
#define I2C_CPU_INT_RIS_MRXFIFOTRG_MASK          ((uint32_t)0x00000004U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_CPU_INT_RIS_MRXFIFOTRG_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_RIS_MRXFIFOTRG_SET           ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[MTXFIFOTRG] Bits */
#define I2C_CPU_INT_RIS_MTXFIFOTRG_OFS           (3)                             /* !< MTXFIFOTRG Offset */
#define I2C_CPU_INT_RIS_MTXFIFOTRG_MASK          ((uint32_t)0x00000008U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_CPU_INT_RIS_MTXFIFOTRG_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_RIS_MTXFIFOTRG_SET           ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[MDMA_DONE_TX] Bits */
#define I2C_CPU_INT_RIS_MDMA_DONE_TX_OFS         (11)                            /* !< MDMA_DONE_TX Offset */
#define I2C_CPU_INT_RIS_MDMA_DONE_TX_MASK        ((uint32_t)0x00000800U)         /* !< DMA Done on Event Channel TX */
#define I2C_CPU_INT_RIS_MDMA_DONE_TX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define I2C_CPU_INT_RIS_MDMA_DONE_TX_SET         ((uint32_t)0x00000800U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[MDMA_DONE_RX] Bits */
#define I2C_CPU_INT_RIS_MDMA_DONE_RX_OFS         (12)                            /* !< MDMA_DONE_RX Offset */
#define I2C_CPU_INT_RIS_MDMA_DONE_RX_MASK        ((uint32_t)0x00001000U)         /* !< DMA Done on Event Channel RX */
#define I2C_CPU_INT_RIS_MDMA_DONE_RX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define I2C_CPU_INT_RIS_MDMA_DONE_RX_SET         ((uint32_t)0x00001000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[SRXDONE] Bits */
#define I2C_CPU_INT_RIS_SRXDONE_OFS              (16)                            /* !< SRXDONE Offset */
#define I2C_CPU_INT_RIS_SRXDONE_MASK             ((uint32_t)0x00010000U)         /* !< Target Receive Data Interrupt
                                                                                    Signals that a byte has been received */
#define I2C_CPU_INT_RIS_SRXDONE_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_SRXDONE_SET              ((uint32_t)0x00010000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[STXDONE] Bits */
#define I2C_CPU_INT_RIS_STXDONE_OFS              (17)                            /* !< STXDONE Offset */
#define I2C_CPU_INT_RIS_STXDONE_MASK             ((uint32_t)0x00020000U)         /* !< Target Transmit Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_RIS_STXDONE_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_STXDONE_SET              ((uint32_t)0x00020000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[SGENCALL] Bits */
#define I2C_CPU_INT_RIS_SGENCALL_OFS             (24)                            /* !< SGENCALL Offset */
#define I2C_CPU_INT_RIS_SGENCALL_MASK            ((uint32_t)0x01000000U)         /* !< General Call Interrupt */
#define I2C_CPU_INT_RIS_SGENCALL_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_RIS_SGENCALL_SET             ((uint32_t)0x01000000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[STXEMPTY] Bits */
#define I2C_CPU_INT_RIS_STXEMPTY_OFS             (21)                            /* !< STXEMPTY Offset */
#define I2C_CPU_INT_RIS_STXEMPTY_MASK            ((uint32_t)0x00200000U)         /* !< Transmit FIFO Empty interrupt mask.
                                                                                    This interrupt is set if all data in
                                                                                    the Transmit FIFO have been shifted
                                                                                    out and the transmit goes into idle
                                                                                    mode. */
#define I2C_CPU_INT_RIS_STXEMPTY_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_STXEMPTY_SET             ((uint32_t)0x00200000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[SRXFIFOFULL] Bits */
#define I2C_CPU_INT_RIS_SRXFIFOFULL_OFS          (20)                            /* !< SRXFIFOFULL Offset */
#define I2C_CPU_INT_RIS_SRXFIFOFULL_MASK         ((uint32_t)0x00100000U)         /* !< RXFIFO full event. This interrupt
                                                                                    is set if an RX FIFO is full. */
#define I2C_CPU_INT_RIS_SRXFIFOFULL_CLR          ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_RIS_SRXFIFOFULL_SET          ((uint32_t)0x00100000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[SRXFIFOTRG] Bits */
#define I2C_CPU_INT_RIS_SRXFIFOTRG_OFS           (18)                            /* !< SRXFIFOTRG Offset */
#define I2C_CPU_INT_RIS_SRXFIFOTRG_MASK          ((uint32_t)0x00040000U)         /* !< Target Receive FIFO Trigger */
#define I2C_CPU_INT_RIS_SRXFIFOTRG_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_RIS_SRXFIFOTRG_SET           ((uint32_t)0x00040000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[STXFIFOTRG] Bits */
#define I2C_CPU_INT_RIS_STXFIFOTRG_OFS           (19)                            /* !< STXFIFOTRG Offset */
#define I2C_CPU_INT_RIS_STXFIFOTRG_MASK          ((uint32_t)0x00080000U)         /* !< Target Transmit FIFO Trigger */
#define I2C_CPU_INT_RIS_STXFIFOTRG_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_RIS_STXFIFOTRG_SET           ((uint32_t)0x00080000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_RIS[SSTART] Bits */
#define I2C_CPU_INT_RIS_SSTART_OFS               (22)                            /* !< SSTART Offset */
#define I2C_CPU_INT_RIS_SSTART_MASK              ((uint32_t)0x00400000U)         /* !< Start Condition Interrupt */
#define I2C_CPU_INT_RIS_SSTART_CLR               ((uint32_t)0x00000000U)         /* !< Clear interrupt */
#define I2C_CPU_INT_RIS_SSTART_SET               ((uint32_t)0x00400000U)         /* !< Set Interrupt */
/* I2C_CPU_INT_RIS[SSTOP] Bits */
#define I2C_CPU_INT_RIS_SSTOP_OFS                (23)                            /* !< SSTOP Offset */
#define I2C_CPU_INT_RIS_SSTOP_MASK               ((uint32_t)0x00800000U)         /* !< Stop Condition Interrupt */
#define I2C_CPU_INT_RIS_SSTOP_CLR                ((uint32_t)0x00000000U)         /* !< Clear Interrupt */
#define I2C_CPU_INT_RIS_SSTOP_SET                ((uint32_t)0x00800000U)         /* !< Set interrupt */
/* I2C_CPU_INT_RIS[SDMA_DONE_TX] Bits */
#define I2C_CPU_INT_RIS_SDMA_DONE_TX_OFS         (25)                            /* !< SDMA_DONE_TX Offset */
#define I2C_CPU_INT_RIS_SDMA_DONE_TX_MASK        ((uint32_t)0x02000000U)         /* !< DMA Done on Event Channel TX */
#define I2C_CPU_INT_RIS_SDMA_DONE_TX_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt */
#define I2C_CPU_INT_RIS_SDMA_DONE_TX_SET         ((uint32_t)0x02000000U)         /* !< Set interrupt */
/* I2C_CPU_INT_RIS[SDMA_DONE_RX] Bits */
#define I2C_CPU_INT_RIS_SDMA_DONE_RX_OFS         (26)                            /* !< SDMA_DONE_RX Offset */
#define I2C_CPU_INT_RIS_SDMA_DONE_RX_MASK        ((uint32_t)0x04000000U)         /* !< DMA Done on Event Channel RX */
#define I2C_CPU_INT_RIS_SDMA_DONE_RX_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt */
#define I2C_CPU_INT_RIS_SDMA_DONE_RX_SET         ((uint32_t)0x04000000U)         /* !< Set interrupt */
/* I2C_CPU_INT_RIS[MPEC_RX_ERR] Bits */
#define I2C_CPU_INT_RIS_MPEC_RX_ERR_OFS          (13)                            /* !< MPEC_RX_ERR Offset */
#define I2C_CPU_INT_RIS_MPEC_RX_ERR_MASK         ((uint32_t)0x00002000U)         /* !< Controller RX Pec Error Interrupt */
#define I2C_CPU_INT_RIS_MPEC_RX_ERR_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_MPEC_RX_ERR_SET          ((uint32_t)0x00002000U)         /* !< Interrupt Occured */
/* I2C_CPU_INT_RIS[TIMEOUTB] Bits */
#define I2C_CPU_INT_RIS_TIMEOUTB_OFS             (15)                            /* !< TIMEOUTB Offset */
#define I2C_CPU_INT_RIS_TIMEOUTB_MASK            ((uint32_t)0x00008000U)         /* !< Timeout B Interrupt */
#define I2C_CPU_INT_RIS_TIMEOUTB_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_TIMEOUTB_SET             ((uint32_t)0x00008000U)         /* !< Interrupt occured */
/* I2C_CPU_INT_RIS[SPEC_RX_ERR] Bits */
#define I2C_CPU_INT_RIS_SPEC_RX_ERR_OFS          (27)                            /* !< SPEC_RX_ERR Offset */
#define I2C_CPU_INT_RIS_SPEC_RX_ERR_MASK         ((uint32_t)0x08000000U)         /* !< Target RX Pec Error Interrupt */
#define I2C_CPU_INT_RIS_SPEC_RX_ERR_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_SPEC_RX_ERR_SET          ((uint32_t)0x08000000U)         /* !< Interrupt ocuured */
/* I2C_CPU_INT_RIS[STX_UNFL] Bits */
#define I2C_CPU_INT_RIS_STX_UNFL_OFS             (28)                            /* !< STX_UNFL Offset */
#define I2C_CPU_INT_RIS_STX_UNFL_MASK            ((uint32_t)0x10000000U)         /* !< Target TX FIFO underflow */
#define I2C_CPU_INT_RIS_STX_UNFL_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_STX_UNFL_SET             ((uint32_t)0x10000000U)         /* !< Interrupt occured */
/* I2C_CPU_INT_RIS[SRX_OVFL] Bits */
#define I2C_CPU_INT_RIS_SRX_OVFL_OFS             (29)                            /* !< SRX_OVFL Offset */
#define I2C_CPU_INT_RIS_SRX_OVFL_MASK            ((uint32_t)0x20000000U)         /* !< Target RX FIFO overflow */
#define I2C_CPU_INT_RIS_SRX_OVFL_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_SRX_OVFL_SET             ((uint32_t)0x20000000U)         /* !< Interrupt Occured */
/* I2C_CPU_INT_RIS[SARBLOST] Bits */
#define I2C_CPU_INT_RIS_SARBLOST_OFS             (30)                            /* !< SARBLOST Offset */
#define I2C_CPU_INT_RIS_SARBLOST_MASK            ((uint32_t)0x40000000U)         /* !< Target Arbitration Lost */
#define I2C_CPU_INT_RIS_SARBLOST_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_SARBLOST_SET             ((uint32_t)0x40000000U)         /* !< Interrupt occured */
/* I2C_CPU_INT_RIS[INTR_OVFL] Bits */
#define I2C_CPU_INT_RIS_INTR_OVFL_OFS            (31)                            /* !< INTR_OVFL Offset */
#define I2C_CPU_INT_RIS_INTR_OVFL_MASK           ((uint32_t)0x80000000U)         /* !< Interrupt overflow interrupt It is
                                                                                    set when SSTART or SSTOP interrupts
                                                                                    overflow i.e. occur twice without
                                                                                    being serviced */
#define I2C_CPU_INT_RIS_INTR_OVFL_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_RIS_INTR_OVFL_SET            ((uint32_t)0x80000000U)         /* !< Interrupt occured */

/* I2C_CPU_INT_MIS Bits */
/* I2C_CPU_INT_MIS[MRXDONE] Bits */
#define I2C_CPU_INT_MIS_MRXDONE_OFS              (0)                             /* !< MRXDONE Offset */
#define I2C_CPU_INT_MIS_MRXDONE_MASK             ((uint32_t)0x00000001U)         /* !< Controller Receive Data Interrupt */
#define I2C_CPU_INT_MIS_MRXDONE_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_MRXDONE_SET              ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[TIMEOUTA] Bits */
#define I2C_CPU_INT_MIS_TIMEOUTA_OFS             (14)                            /* !< TIMEOUTA Offset */
#define I2C_CPU_INT_MIS_TIMEOUTA_MASK            ((uint32_t)0x00004000U)         /* !< Timeout A Interrupt */
#define I2C_CPU_INT_MIS_TIMEOUTA_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_TIMEOUTA_SET             ((uint32_t)0x00004000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[MNACK] Bits */
#define I2C_CPU_INT_MIS_MNACK_OFS                (7)                             /* !< MNACK Offset */
#define I2C_CPU_INT_MIS_MNACK_MASK               ((uint32_t)0x00000080U)         /* !< Address/Data NACK Interrupt */
#define I2C_CPU_INT_MIS_MNACK_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_MNACK_SET                ((uint32_t)0x00000080U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[MSTART] Bits */
#define I2C_CPU_INT_MIS_MSTART_OFS               (8)                             /* !< MSTART Offset */
#define I2C_CPU_INT_MIS_MSTART_MASK              ((uint32_t)0x00000100U)         /* !< START Detection Interrupt */
#define I2C_CPU_INT_MIS_MSTART_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_MSTART_SET               ((uint32_t)0x00000100U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[MSTOP] Bits */
#define I2C_CPU_INT_MIS_MSTOP_OFS                (9)                             /* !< MSTOP Offset */
#define I2C_CPU_INT_MIS_MSTOP_MASK               ((uint32_t)0x00000200U)         /* !< STOP Detection Interrupt */
#define I2C_CPU_INT_MIS_MSTOP_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_MSTOP_SET                ((uint32_t)0x00000200U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[MARBLOST] Bits */
#define I2C_CPU_INT_MIS_MARBLOST_OFS             (10)                            /* !< MARBLOST Offset */
#define I2C_CPU_INT_MIS_MARBLOST_MASK            ((uint32_t)0x00000400U)         /* !< Arbitration Lost Interrupt */
#define I2C_CPU_INT_MIS_MARBLOST_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_MARBLOST_SET             ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[MTXDONE] Bits */
#define I2C_CPU_INT_MIS_MTXDONE_OFS              (1)                             /* !< MTXDONE Offset */
#define I2C_CPU_INT_MIS_MTXDONE_MASK             ((uint32_t)0x00000002U)         /* !< Controller Transmit Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_MIS_MTXDONE_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_MTXDONE_SET              ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[MRXFIFOFULL] Bits */
#define I2C_CPU_INT_MIS_MRXFIFOFULL_OFS          (4)                             /* !< MRXFIFOFULL Offset */
#define I2C_CPU_INT_MIS_MRXFIFOFULL_MASK         ((uint32_t)0x00000010U)         /* !< RXFIFO full event. This interrupt
                                                                                    is set if the RX FIFO is full. */
#define I2C_CPU_INT_MIS_MRXFIFOFULL_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_MRXFIFOFULL_SET          ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[MTXEMPTY] Bits */
#define I2C_CPU_INT_MIS_MTXEMPTY_OFS             (5)                             /* !< MTXEMPTY Offset */
#define I2C_CPU_INT_MIS_MTXEMPTY_MASK            ((uint32_t)0x00000020U)         /* !< Transmit FIFO Empty interrupt mask.
                                                                                    This interrupt is set if all data in
                                                                                    the Transmit FIFO have been shifted
                                                                                    out and the transmit goes into idle
                                                                                    mode. */
#define I2C_CPU_INT_MIS_MTXEMPTY_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_MTXEMPTY_SET             ((uint32_t)0x00000020U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[MRXFIFOTRG] Bits */
#define I2C_CPU_INT_MIS_MRXFIFOTRG_OFS           (2)                             /* !< MRXFIFOTRG Offset */
#define I2C_CPU_INT_MIS_MRXFIFOTRG_MASK          ((uint32_t)0x00000004U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_CPU_INT_MIS_MRXFIFOTRG_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_MIS_MRXFIFOTRG_SET           ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[MTXFIFOTRG] Bits */
#define I2C_CPU_INT_MIS_MTXFIFOTRG_OFS           (3)                             /* !< MTXFIFOTRG Offset */
#define I2C_CPU_INT_MIS_MTXFIFOTRG_MASK          ((uint32_t)0x00000008U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_CPU_INT_MIS_MTXFIFOTRG_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_MIS_MTXFIFOTRG_SET           ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[MDMA_DONE_TX] Bits */
#define I2C_CPU_INT_MIS_MDMA_DONE_TX_OFS         (11)                            /* !< MDMA_DONE_TX Offset */
#define I2C_CPU_INT_MIS_MDMA_DONE_TX_MASK        ((uint32_t)0x00000800U)         /* !< DMA Done on Event Channel TX */
#define I2C_CPU_INT_MIS_MDMA_DONE_TX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define I2C_CPU_INT_MIS_MDMA_DONE_TX_SET         ((uint32_t)0x00000800U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[MDMA_DONE_RX] Bits */
#define I2C_CPU_INT_MIS_MDMA_DONE_RX_OFS         (12)                            /* !< MDMA_DONE_RX Offset */
#define I2C_CPU_INT_MIS_MDMA_DONE_RX_MASK        ((uint32_t)0x00001000U)         /* !< DMA Done on Event Channel RX */
#define I2C_CPU_INT_MIS_MDMA_DONE_RX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define I2C_CPU_INT_MIS_MDMA_DONE_RX_SET         ((uint32_t)0x00001000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[SRXDONE] Bits */
#define I2C_CPU_INT_MIS_SRXDONE_OFS              (16)                            /* !< SRXDONE Offset */
#define I2C_CPU_INT_MIS_SRXDONE_MASK             ((uint32_t)0x00010000U)         /* !< Target Receive Data Interrupt
                                                                                    Signals that a byte has been received */
#define I2C_CPU_INT_MIS_SRXDONE_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_SRXDONE_SET              ((uint32_t)0x00010000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[STXDONE] Bits */
#define I2C_CPU_INT_MIS_STXDONE_OFS              (17)                            /* !< STXDONE Offset */
#define I2C_CPU_INT_MIS_STXDONE_MASK             ((uint32_t)0x00020000U)         /* !< Target Transmit Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_MIS_STXDONE_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_STXDONE_SET              ((uint32_t)0x00020000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[SGENCALL] Bits */
#define I2C_CPU_INT_MIS_SGENCALL_OFS             (24)                            /* !< SGENCALL Offset */
#define I2C_CPU_INT_MIS_SGENCALL_MASK            ((uint32_t)0x01000000U)         /* !< General Call Interrupt */
#define I2C_CPU_INT_MIS_SGENCALL_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_SGENCALL_SET             ((uint32_t)0x01000000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[STXEMPTY] Bits */
#define I2C_CPU_INT_MIS_STXEMPTY_OFS             (21)                            /* !< STXEMPTY Offset */
#define I2C_CPU_INT_MIS_STXEMPTY_MASK            ((uint32_t)0x00200000U)         /* !< Transmit FIFO Empty interrupt mask.
                                                                                    This interrupt is set if all data in
                                                                                    the Transmit FIFO have been shifted
                                                                                    out and the transmit goes into idle
                                                                                    mode. */
#define I2C_CPU_INT_MIS_STXEMPTY_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_STXEMPTY_SET             ((uint32_t)0x00200000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[SRXFIFOFULL] Bits */
#define I2C_CPU_INT_MIS_SRXFIFOFULL_OFS          (20)                            /* !< SRXFIFOFULL Offset */
#define I2C_CPU_INT_MIS_SRXFIFOFULL_MASK         ((uint32_t)0x00100000U)         /* !< RXFIFO full event. This interrupt
                                                                                    is set if an RX FIFO is full. */
#define I2C_CPU_INT_MIS_SRXFIFOFULL_CLR          ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_MIS_SRXFIFOFULL_SET          ((uint32_t)0x00100000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[SRXFIFOTRG] Bits */
#define I2C_CPU_INT_MIS_SRXFIFOTRG_OFS           (18)                            /* !< SRXFIFOTRG Offset */
#define I2C_CPU_INT_MIS_SRXFIFOTRG_MASK          ((uint32_t)0x00040000U)         /* !< Target Receive FIFO Trigger */
#define I2C_CPU_INT_MIS_SRXFIFOTRG_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_MIS_SRXFIFOTRG_SET           ((uint32_t)0x00040000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[STXFIFOTRG] Bits */
#define I2C_CPU_INT_MIS_STXFIFOTRG_OFS           (19)                            /* !< STXFIFOTRG Offset */
#define I2C_CPU_INT_MIS_STXFIFOTRG_MASK          ((uint32_t)0x00080000U)         /* !< Target Transmit FIFO Trigger */
#define I2C_CPU_INT_MIS_STXFIFOTRG_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_MIS_STXFIFOTRG_SET           ((uint32_t)0x00080000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_MIS[SSTART] Bits */
#define I2C_CPU_INT_MIS_SSTART_OFS               (22)                            /* !< SSTART Offset */
#define I2C_CPU_INT_MIS_SSTART_MASK              ((uint32_t)0x00400000U)         /* !< Target START Detection Interrupt */
#define I2C_CPU_INT_MIS_SSTART_CLR               ((uint32_t)0x00000000U)         /* !< Clear MIS */
#define I2C_CPU_INT_MIS_SSTART_SET               ((uint32_t)0x00400000U)         /* !< Set MIS */
/* I2C_CPU_INT_MIS[SSTOP] Bits */
#define I2C_CPU_INT_MIS_SSTOP_OFS                (23)                            /* !< SSTOP Offset */
#define I2C_CPU_INT_MIS_SSTOP_MASK               ((uint32_t)0x00800000U)         /* !< Target STOP Detection Interrupt */
#define I2C_CPU_INT_MIS_SSTOP_CLR                ((uint32_t)0x00000000U)         /* !< Clear MIS */
#define I2C_CPU_INT_MIS_SSTOP_SET                ((uint32_t)0x00800000U)         /* !< Set MIS */
/* I2C_CPU_INT_MIS[SDMA_DONE_TX] Bits */
#define I2C_CPU_INT_MIS_SDMA_DONE_TX_OFS         (25)                            /* !< SDMA_DONE_TX Offset */
#define I2C_CPU_INT_MIS_SDMA_DONE_TX_MASK        ((uint32_t)0x02000000U)         /* !< DMA Done on Event Channel TX */
#define I2C_CPU_INT_MIS_SDMA_DONE_TX_CLR         ((uint32_t)0x00000000U)         /* !< Clear MIS */
#define I2C_CPU_INT_MIS_SDMA_DONE_TX_SET         ((uint32_t)0x02000000U)         /* !< Set MIS */
/* I2C_CPU_INT_MIS[SDMA_DONE_RX] Bits */
#define I2C_CPU_INT_MIS_SDMA_DONE_RX_OFS         (26)                            /* !< SDMA_DONE_RX Offset */
#define I2C_CPU_INT_MIS_SDMA_DONE_RX_MASK        ((uint32_t)0x04000000U)         /* !< DMA Done on Event Channel RX */
#define I2C_CPU_INT_MIS_SDMA_DONE_RX_CLR         ((uint32_t)0x00000000U)         /* !< Clear MIS */
#define I2C_CPU_INT_MIS_SDMA_DONE_RX_SET         ((uint32_t)0x04000000U)         /* !< Set MIS */
/* I2C_CPU_INT_MIS[MPEC_RX_ERR] Bits */
#define I2C_CPU_INT_MIS_MPEC_RX_ERR_OFS          (13)                            /* !< MPEC_RX_ERR Offset */
#define I2C_CPU_INT_MIS_MPEC_RX_ERR_MASK         ((uint32_t)0x00002000U)         /* !< Controller RX Pec Error Interrupt */
#define I2C_CPU_INT_MIS_MPEC_RX_ERR_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask */
#define I2C_CPU_INT_MIS_MPEC_RX_ERR_SET          ((uint32_t)0x00002000U)         /* !< Set interrupt mask */
/* I2C_CPU_INT_MIS[TIMEOUTB] Bits */
#define I2C_CPU_INT_MIS_TIMEOUTB_OFS             (15)                            /* !< TIMEOUTB Offset */
#define I2C_CPU_INT_MIS_TIMEOUTB_MASK            ((uint32_t)0x00008000U)         /* !< Timeout B Interrupt */
#define I2C_CPU_INT_MIS_TIMEOUTB_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask */
#define I2C_CPU_INT_MIS_TIMEOUTB_SET             ((uint32_t)0x00008000U)         /* !< Set interrupt mask */
/* I2C_CPU_INT_MIS[SPEC_RX_ERR] Bits */
#define I2C_CPU_INT_MIS_SPEC_RX_ERR_OFS          (27)                            /* !< SPEC_RX_ERR Offset */
#define I2C_CPU_INT_MIS_SPEC_RX_ERR_MASK         ((uint32_t)0x08000000U)         /* !< Target RX Pec Error Interrupt */
#define I2C_CPU_INT_MIS_SPEC_RX_ERR_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask */
#define I2C_CPU_INT_MIS_SPEC_RX_ERR_SET          ((uint32_t)0x08000000U)         /* !< Set interrupt mask */
/* I2C_CPU_INT_MIS[STX_UNFL] Bits */
#define I2C_CPU_INT_MIS_STX_UNFL_OFS             (28)                            /* !< STX_UNFL Offset */
#define I2C_CPU_INT_MIS_STX_UNFL_MASK            ((uint32_t)0x10000000U)         /* !< Target TX FIFO underflow */
#define I2C_CPU_INT_MIS_STX_UNFL_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask */
#define I2C_CPU_INT_MIS_STX_UNFL_SET             ((uint32_t)0x10000000U)         /* !< Set interrupt mask */
/* I2C_CPU_INT_MIS[SRX_OVFL] Bits */
#define I2C_CPU_INT_MIS_SRX_OVFL_OFS             (29)                            /* !< SRX_OVFL Offset */
#define I2C_CPU_INT_MIS_SRX_OVFL_MASK            ((uint32_t)0x20000000U)         /* !< Target RX FIFO overflow */
#define I2C_CPU_INT_MIS_SRX_OVFL_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask */
#define I2C_CPU_INT_MIS_SRX_OVFL_SET             ((uint32_t)0x20000000U)         /* !< Set interrupt mask */
/* I2C_CPU_INT_MIS[SARBLOST] Bits */
#define I2C_CPU_INT_MIS_SARBLOST_OFS             (30)                            /* !< SARBLOST Offset */
#define I2C_CPU_INT_MIS_SARBLOST_MASK            ((uint32_t)0x40000000U)         /* !< Target Arbitration Lost */
#define I2C_CPU_INT_MIS_SARBLOST_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask */
#define I2C_CPU_INT_MIS_SARBLOST_SET             ((uint32_t)0x40000000U)         /* !< Set interrupt mask */
/* I2C_CPU_INT_MIS[INTR_OVFL] Bits */
#define I2C_CPU_INT_MIS_INTR_OVFL_OFS            (31)                            /* !< INTR_OVFL Offset */
#define I2C_CPU_INT_MIS_INTR_OVFL_MASK           ((uint32_t)0x80000000U)         /* !< Interrupt overflow */
#define I2C_CPU_INT_MIS_INTR_OVFL_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define I2C_CPU_INT_MIS_INTR_OVFL_SET            ((uint32_t)0x80000000U)         /* !< Interrupt occured */

/* I2C_CPU_INT_ISET Bits */
/* I2C_CPU_INT_ISET[MRXDONE] Bits */
#define I2C_CPU_INT_ISET_MRXDONE_OFS             (0)                             /* !< MRXDONE Offset */
#define I2C_CPU_INT_ISET_MRXDONE_MASK            ((uint32_t)0x00000001U)         /* !< Controller Receive Data Interrupt
                                                                                    Signals that a byte has been received */
#define I2C_CPU_INT_ISET_MRXDONE_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_MRXDONE_SET             ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[TIMEOUTA] Bits */
#define I2C_CPU_INT_ISET_TIMEOUTA_OFS            (14)                            /* !< TIMEOUTA Offset */
#define I2C_CPU_INT_ISET_TIMEOUTA_MASK           ((uint32_t)0x00004000U)         /* !< Timeout A interrupt */
#define I2C_CPU_INT_ISET_TIMEOUTA_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_TIMEOUTA_SET            ((uint32_t)0x00004000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[MNACK] Bits */
#define I2C_CPU_INT_ISET_MNACK_OFS               (7)                             /* !< MNACK Offset */
#define I2C_CPU_INT_ISET_MNACK_MASK              ((uint32_t)0x00000080U)         /* !< Address/Data NACK Interrupt */
#define I2C_CPU_INT_ISET_MNACK_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_MNACK_SET               ((uint32_t)0x00000080U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[MSTART] Bits */
#define I2C_CPU_INT_ISET_MSTART_OFS              (8)                             /* !< MSTART Offset */
#define I2C_CPU_INT_ISET_MSTART_MASK             ((uint32_t)0x00000100U)         /* !< START Detection Interrupt */
#define I2C_CPU_INT_ISET_MSTART_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_MSTART_SET              ((uint32_t)0x00000100U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[MSTOP] Bits */
#define I2C_CPU_INT_ISET_MSTOP_OFS               (9)                             /* !< MSTOP Offset */
#define I2C_CPU_INT_ISET_MSTOP_MASK              ((uint32_t)0x00000200U)         /* !< STOP Detection Interrupt */
#define I2C_CPU_INT_ISET_MSTOP_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_MSTOP_SET               ((uint32_t)0x00000200U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[MARBLOST] Bits */
#define I2C_CPU_INT_ISET_MARBLOST_OFS            (10)                            /* !< MARBLOST Offset */
#define I2C_CPU_INT_ISET_MARBLOST_MASK           ((uint32_t)0x00000400U)         /* !< Arbitration Lost Interrupt */
#define I2C_CPU_INT_ISET_MARBLOST_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_MARBLOST_SET            ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[MTXDONE] Bits */
#define I2C_CPU_INT_ISET_MTXDONE_OFS             (1)                             /* !< MTXDONE Offset */
#define I2C_CPU_INT_ISET_MTXDONE_MASK            ((uint32_t)0x00000002U)         /* !< Controller Transmit Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_ISET_MTXDONE_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_MTXDONE_SET             ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[MRXFIFOFULL] Bits */
#define I2C_CPU_INT_ISET_MRXFIFOFULL_OFS         (4)                             /* !< MRXFIFOFULL Offset */
#define I2C_CPU_INT_ISET_MRXFIFOFULL_MASK        ((uint32_t)0x00000010U)         /* !< RXFIFO full event. */
#define I2C_CPU_INT_ISET_MRXFIFOFULL_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_MRXFIFOFULL_SET         ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[MTXEMPTY] Bits */
#define I2C_CPU_INT_ISET_MTXEMPTY_OFS            (5)                             /* !< MTXEMPTY Offset */
#define I2C_CPU_INT_ISET_MTXEMPTY_MASK           ((uint32_t)0x00000020U)         /* !< Transmit FIFO Empty interrupt mask.
                                                                                    This interrupt is set if all data in
                                                                                    the Transmit FIFO have been shifted
                                                                                    out and the transmit goes into idle
                                                                                    mode. */
#define I2C_CPU_INT_ISET_MTXEMPTY_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_MTXEMPTY_SET            ((uint32_t)0x00000020U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[MRXFIFOTRG] Bits */
#define I2C_CPU_INT_ISET_MRXFIFOTRG_OFS          (2)                             /* !< MRXFIFOTRG Offset */
#define I2C_CPU_INT_ISET_MRXFIFOTRG_MASK         ((uint32_t)0x00000004U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_CPU_INT_ISET_MRXFIFOTRG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_ISET_MRXFIFOTRG_SET          ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[MTXFIFOTRG] Bits */
#define I2C_CPU_INT_ISET_MTXFIFOTRG_OFS          (3)                             /* !< MTXFIFOTRG Offset */
#define I2C_CPU_INT_ISET_MTXFIFOTRG_MASK         ((uint32_t)0x00000008U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_CPU_INT_ISET_MTXFIFOTRG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_ISET_MTXFIFOTRG_SET          ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[MDMA_DONE_TX] Bits */
#define I2C_CPU_INT_ISET_MDMA_DONE_TX_OFS        (11)                            /* !< MDMA_DONE_TX Offset */
#define I2C_CPU_INT_ISET_MDMA_DONE_TX_MASK       ((uint32_t)0x00000800U)         /* !< DMA Done on Event Channel TX */
#define I2C_CPU_INT_ISET_MDMA_DONE_TX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define I2C_CPU_INT_ISET_MDMA_DONE_TX_SET        ((uint32_t)0x00000800U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[MDMA_DONE_RX] Bits */
#define I2C_CPU_INT_ISET_MDMA_DONE_RX_OFS        (12)                            /* !< MDMA_DONE_RX Offset */
#define I2C_CPU_INT_ISET_MDMA_DONE_RX_MASK       ((uint32_t)0x00001000U)         /* !< DMA Done on Event Channel RX */
#define I2C_CPU_INT_ISET_MDMA_DONE_RX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define I2C_CPU_INT_ISET_MDMA_DONE_RX_SET        ((uint32_t)0x00001000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[SRXDONE] Bits */
#define I2C_CPU_INT_ISET_SRXDONE_OFS             (16)                            /* !< SRXDONE Offset */
#define I2C_CPU_INT_ISET_SRXDONE_MASK            ((uint32_t)0x00010000U)         /* !< Target Receive Data Interrupt
                                                                                    Signals that a byte has been received */
#define I2C_CPU_INT_ISET_SRXDONE_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_SRXDONE_SET             ((uint32_t)0x00010000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[STXDONE] Bits */
#define I2C_CPU_INT_ISET_STXDONE_OFS             (17)                            /* !< STXDONE Offset */
#define I2C_CPU_INT_ISET_STXDONE_MASK            ((uint32_t)0x00020000U)         /* !< Target Transmit Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_ISET_STXDONE_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_STXDONE_SET             ((uint32_t)0x00020000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[SGENCALL] Bits */
#define I2C_CPU_INT_ISET_SGENCALL_OFS            (24)                            /* !< SGENCALL Offset */
#define I2C_CPU_INT_ISET_SGENCALL_MASK           ((uint32_t)0x01000000U)         /* !< General Call Interrupt */
#define I2C_CPU_INT_ISET_SGENCALL_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_SGENCALL_SET            ((uint32_t)0x01000000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[STXEMPTY] Bits */
#define I2C_CPU_INT_ISET_STXEMPTY_OFS            (21)                            /* !< STXEMPTY Offset */
#define I2C_CPU_INT_ISET_STXEMPTY_MASK           ((uint32_t)0x00200000U)         /* !< Transmit FIFO Empty interrupt mask.
                                                                                    This interrupt is set if all data in
                                                                                    the Transmit FIFO have been shifted
                                                                                    out and the transmit goes into idle
                                                                                    mode. */
#define I2C_CPU_INT_ISET_STXEMPTY_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_STXEMPTY_SET            ((uint32_t)0x00200000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[SRXFIFOFULL] Bits */
#define I2C_CPU_INT_ISET_SRXFIFOFULL_OFS         (20)                            /* !< SRXFIFOFULL Offset */
#define I2C_CPU_INT_ISET_SRXFIFOFULL_MASK        ((uint32_t)0x00100000U)         /* !< RXFIFO full event. This interrupt
                                                                                    is set if an RX FIFO is full. */
#define I2C_CPU_INT_ISET_SRXFIFOFULL_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_ISET_SRXFIFOFULL_SET         ((uint32_t)0x00100000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[SRXFIFOTRG] Bits */
#define I2C_CPU_INT_ISET_SRXFIFOTRG_OFS          (18)                            /* !< SRXFIFOTRG Offset */
#define I2C_CPU_INT_ISET_SRXFIFOTRG_MASK         ((uint32_t)0x00040000U)         /* !< Target Receive FIFO Trigger */
#define I2C_CPU_INT_ISET_SRXFIFOTRG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_ISET_SRXFIFOTRG_SET          ((uint32_t)0x00040000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[STXFIFOTRG] Bits */
#define I2C_CPU_INT_ISET_STXFIFOTRG_OFS          (19)                            /* !< STXFIFOTRG Offset */
#define I2C_CPU_INT_ISET_STXFIFOTRG_MASK         ((uint32_t)0x00080000U)         /* !< Target Transmit FIFO Trigger */
#define I2C_CPU_INT_ISET_STXFIFOTRG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_ISET_STXFIFOTRG_SET          ((uint32_t)0x00080000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ISET[SSTART] Bits */
#define I2C_CPU_INT_ISET_SSTART_OFS              (22)                            /* !< SSTART Offset */
#define I2C_CPU_INT_ISET_SSTART_MASK             ((uint32_t)0x00400000U)         /* !< Start Condition Interrupt */
#define I2C_CPU_INT_ISET_SSTART_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_SSTART_SET              ((uint32_t)0x00400000U)         /* !< Set interrupt */
/* I2C_CPU_INT_ISET[SSTOP] Bits */
#define I2C_CPU_INT_ISET_SSTOP_OFS               (23)                            /* !< SSTOP Offset */
#define I2C_CPU_INT_ISET_SSTOP_MASK              ((uint32_t)0x00800000U)         /* !< Stop Condition Interrupt */
#define I2C_CPU_INT_ISET_SSTOP_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_SSTOP_SET               ((uint32_t)0x00800000U)         /* !< Set interrupt */
/* I2C_CPU_INT_ISET[SDMA_DONE_TX] Bits */
#define I2C_CPU_INT_ISET_SDMA_DONE_TX_OFS        (25)                            /* !< SDMA_DONE_TX Offset */
#define I2C_CPU_INT_ISET_SDMA_DONE_TX_MASK       ((uint32_t)0x02000000U)         /* !< DMA Done on Event Channel TX */
#define I2C_CPU_INT_ISET_SDMA_DONE_TX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_SDMA_DONE_TX_SET        ((uint32_t)0x02000000U)         /* !< Set interrupt */
/* I2C_CPU_INT_ISET[SDMA_DONE_RX] Bits */
#define I2C_CPU_INT_ISET_SDMA_DONE_RX_OFS        (26)                            /* !< SDMA_DONE_RX Offset */
#define I2C_CPU_INT_ISET_SDMA_DONE_RX_MASK       ((uint32_t)0x04000000U)         /* !< DMA Done on Event Channel RX */
#define I2C_CPU_INT_ISET_SDMA_DONE_RX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_SDMA_DONE_RX_SET        ((uint32_t)0x04000000U)         /* !< Set interrupt */
/* I2C_CPU_INT_ISET[MPEC_RX_ERR] Bits */
#define I2C_CPU_INT_ISET_MPEC_RX_ERR_OFS         (13)                            /* !< MPEC_RX_ERR Offset */
#define I2C_CPU_INT_ISET_MPEC_RX_ERR_MASK        ((uint32_t)0x00002000U)         /* !< Controller RX Pec Error Interrupt */
#define I2C_CPU_INT_ISET_MPEC_RX_ERR_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_MPEC_RX_ERR_SET         ((uint32_t)0x00002000U)         /* !< Set interrupt */
/* I2C_CPU_INT_ISET[TIMEOUTB] Bits */
#define I2C_CPU_INT_ISET_TIMEOUTB_OFS            (15)                            /* !< TIMEOUTB Offset */
#define I2C_CPU_INT_ISET_TIMEOUTB_MASK           ((uint32_t)0x00008000U)         /* !< Timeout B Interrupt */
#define I2C_CPU_INT_ISET_TIMEOUTB_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_TIMEOUTB_SET            ((uint32_t)0x00008000U)         /* !< Set interrupt */
/* I2C_CPU_INT_ISET[SPEC_RX_ERR] Bits */
#define I2C_CPU_INT_ISET_SPEC_RX_ERR_OFS         (27)                            /* !< SPEC_RX_ERR Offset */
#define I2C_CPU_INT_ISET_SPEC_RX_ERR_MASK        ((uint32_t)0x08000000U)         /* !< Target RX Pec Error Interrupt */
#define I2C_CPU_INT_ISET_SPEC_RX_ERR_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_SPEC_RX_ERR_SET         ((uint32_t)0x08000000U)         /* !< Set interrupt */
/* I2C_CPU_INT_ISET[STX_UNFL] Bits */
#define I2C_CPU_INT_ISET_STX_UNFL_OFS            (28)                            /* !< STX_UNFL Offset */
#define I2C_CPU_INT_ISET_STX_UNFL_MASK           ((uint32_t)0x10000000U)         /* !< Target TX FIFO underflow */
#define I2C_CPU_INT_ISET_STX_UNFL_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_STX_UNFL_SET            ((uint32_t)0x10000000U)         /* !< Set interrupt */
/* I2C_CPU_INT_ISET[SRX_OVFL] Bits */
#define I2C_CPU_INT_ISET_SRX_OVFL_OFS            (29)                            /* !< SRX_OVFL Offset */
#define I2C_CPU_INT_ISET_SRX_OVFL_MASK           ((uint32_t)0x20000000U)         /* !< Target RX FIFO overflow */
#define I2C_CPU_INT_ISET_SRX_OVFL_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_SRX_OVFL_SET            ((uint32_t)0x20000000U)         /* !< Set interrupt */
/* I2C_CPU_INT_ISET[SARBLOST] Bits */
#define I2C_CPU_INT_ISET_SARBLOST_OFS            (30)                            /* !< SARBLOST Offset */
#define I2C_CPU_INT_ISET_SARBLOST_MASK           ((uint32_t)0x40000000U)         /* !< Target Arbitration Lost */
#define I2C_CPU_INT_ISET_SARBLOST_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ISET_SARBLOST_SET            ((uint32_t)0x40000000U)         /* !< Set interrupt */
/* I2C_CPU_INT_ISET[INTR_OVFL] Bits */
#define I2C_CPU_INT_ISET_INTR_OVFL_OFS           (31)                            /* !< INTR_OVFL Offset */
#define I2C_CPU_INT_ISET_INTR_OVFL_MASK          ((uint32_t)0x80000000U)         /* !< Interrupt overflow */
#define I2C_CPU_INT_ISET_INTR_OVFL_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define I2C_CPU_INT_ISET_INTR_OVFL_SET           ((uint32_t)0x80000000U)         /* !< Set interrupt */

/* I2C_CPU_INT_ICLR Bits */
/* I2C_CPU_INT_ICLR[MRXDONE] Bits */
#define I2C_CPU_INT_ICLR_MRXDONE_OFS             (0)                             /* !< MRXDONE Offset */
#define I2C_CPU_INT_ICLR_MRXDONE_MASK            ((uint32_t)0x00000001U)         /* !< Controller Receive Data Interrupt
                                                                                    Signals that a byte has been received */
#define I2C_CPU_INT_ICLR_MRXDONE_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_MRXDONE_CLR             ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[TIMEOUTA] Bits */
#define I2C_CPU_INT_ICLR_TIMEOUTA_OFS            (14)                            /* !< TIMEOUTA Offset */
#define I2C_CPU_INT_ICLR_TIMEOUTA_MASK           ((uint32_t)0x00004000U)         /* !< Timeout A interrupt */
#define I2C_CPU_INT_ICLR_TIMEOUTA_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_TIMEOUTA_CLR            ((uint32_t)0x00004000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[MNACK] Bits */
#define I2C_CPU_INT_ICLR_MNACK_OFS               (7)                             /* !< MNACK Offset */
#define I2C_CPU_INT_ICLR_MNACK_MASK              ((uint32_t)0x00000080U)         /* !< Address/Data NACK Interrupt */
#define I2C_CPU_INT_ICLR_MNACK_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_MNACK_CLR               ((uint32_t)0x00000080U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[MSTART] Bits */
#define I2C_CPU_INT_ICLR_MSTART_OFS              (8)                             /* !< MSTART Offset */
#define I2C_CPU_INT_ICLR_MSTART_MASK             ((uint32_t)0x00000100U)         /* !< START Detection Interrupt */
#define I2C_CPU_INT_ICLR_MSTART_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_MSTART_CLR              ((uint32_t)0x00000100U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[MSTOP] Bits */
#define I2C_CPU_INT_ICLR_MSTOP_OFS               (9)                             /* !< MSTOP Offset */
#define I2C_CPU_INT_ICLR_MSTOP_MASK              ((uint32_t)0x00000200U)         /* !< STOP Detection Interrupt */
#define I2C_CPU_INT_ICLR_MSTOP_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_MSTOP_CLR               ((uint32_t)0x00000200U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[MARBLOST] Bits */
#define I2C_CPU_INT_ICLR_MARBLOST_OFS            (10)                            /* !< MARBLOST Offset */
#define I2C_CPU_INT_ICLR_MARBLOST_MASK           ((uint32_t)0x00000400U)         /* !< Arbitration Lost Interrupt */
#define I2C_CPU_INT_ICLR_MARBLOST_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_MARBLOST_CLR            ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[MTXDONE] Bits */
#define I2C_CPU_INT_ICLR_MTXDONE_OFS             (1)                             /* !< MTXDONE Offset */
#define I2C_CPU_INT_ICLR_MTXDONE_MASK            ((uint32_t)0x00000002U)         /* !< Controller Transmit Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_ICLR_MTXDONE_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_MTXDONE_CLR             ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[MRXFIFOFULL] Bits */
#define I2C_CPU_INT_ICLR_MRXFIFOFULL_OFS         (4)                             /* !< MRXFIFOFULL Offset */
#define I2C_CPU_INT_ICLR_MRXFIFOFULL_MASK        ((uint32_t)0x00000010U)         /* !< RXFIFO full event. */
#define I2C_CPU_INT_ICLR_MRXFIFOFULL_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_MRXFIFOFULL_CLR         ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[MTXEMPTY] Bits */
#define I2C_CPU_INT_ICLR_MTXEMPTY_OFS            (5)                             /* !< MTXEMPTY Offset */
#define I2C_CPU_INT_ICLR_MTXEMPTY_MASK           ((uint32_t)0x00000020U)         /* !< Transmit FIFO Empty interrupt mask.
                                                                                    This interrupt is set if all data in
                                                                                    the Transmit FIFO have been shifted
                                                                                    out and the transmit goes into idle
                                                                                    mode. */
#define I2C_CPU_INT_ICLR_MTXEMPTY_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_MTXEMPTY_CLR            ((uint32_t)0x00000020U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[MRXFIFOTRG] Bits */
#define I2C_CPU_INT_ICLR_MRXFIFOTRG_OFS          (2)                             /* !< MRXFIFOTRG Offset */
#define I2C_CPU_INT_ICLR_MRXFIFOTRG_MASK         ((uint32_t)0x00000004U)         /* !< Controller Receive FIFO Trigger
                                                                                    Trigger when RX FIFO contains >=
                                                                                    defined bytes */
#define I2C_CPU_INT_ICLR_MRXFIFOTRG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_ICLR_MRXFIFOTRG_CLR          ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[MTXFIFOTRG] Bits */
#define I2C_CPU_INT_ICLR_MTXFIFOTRG_OFS          (3)                             /* !< MTXFIFOTRG Offset */
#define I2C_CPU_INT_ICLR_MTXFIFOTRG_MASK         ((uint32_t)0x00000008U)         /* !< Controller Transmit FIFO Trigger
                                                                                    Trigger when Transmit FIFO contains
                                                                                    <= defined bytes */
#define I2C_CPU_INT_ICLR_MTXFIFOTRG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_ICLR_MTXFIFOTRG_CLR          ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[MDMA_DONE_TX] Bits */
#define I2C_CPU_INT_ICLR_MDMA_DONE_TX_OFS        (11)                            /* !< MDMA_DONE_TX Offset */
#define I2C_CPU_INT_ICLR_MDMA_DONE_TX_MASK       ((uint32_t)0x00000800U)         /* !< DMA Done on Event Channel TX */
#define I2C_CPU_INT_ICLR_MDMA_DONE_TX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define I2C_CPU_INT_ICLR_MDMA_DONE_TX_CLR        ((uint32_t)0x00000800U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[MDMA_DONE_RX] Bits */
#define I2C_CPU_INT_ICLR_MDMA_DONE_RX_OFS        (12)                            /* !< MDMA_DONE_RX Offset */
#define I2C_CPU_INT_ICLR_MDMA_DONE_RX_MASK       ((uint32_t)0x00001000U)         /* !< DMA Done on Event Channel RX */
#define I2C_CPU_INT_ICLR_MDMA_DONE_RX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define I2C_CPU_INT_ICLR_MDMA_DONE_RX_CLR        ((uint32_t)0x00001000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[SRXDONE] Bits */
#define I2C_CPU_INT_ICLR_SRXDONE_OFS             (16)                            /* !< SRXDONE Offset */
#define I2C_CPU_INT_ICLR_SRXDONE_MASK            ((uint32_t)0x00010000U)         /* !< Target Receive Data Interrupt
                                                                                    Signals that a byte has been received */
#define I2C_CPU_INT_ICLR_SRXDONE_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_SRXDONE_CLR             ((uint32_t)0x00010000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[STXDONE] Bits */
#define I2C_CPU_INT_ICLR_STXDONE_OFS             (17)                            /* !< STXDONE Offset */
#define I2C_CPU_INT_ICLR_STXDONE_MASK            ((uint32_t)0x00020000U)         /* !< Target Transmit Transaction
                                                                                    completed Interrupt */
#define I2C_CPU_INT_ICLR_STXDONE_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_STXDONE_CLR             ((uint32_t)0x00020000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[SGENCALL] Bits */
#define I2C_CPU_INT_ICLR_SGENCALL_OFS            (24)                            /* !< SGENCALL Offset */
#define I2C_CPU_INT_ICLR_SGENCALL_MASK           ((uint32_t)0x01000000U)         /* !< General Call Interrupt */
#define I2C_CPU_INT_ICLR_SGENCALL_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_SGENCALL_CLR            ((uint32_t)0x01000000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[STXEMPTY] Bits */
#define I2C_CPU_INT_ICLR_STXEMPTY_OFS            (21)                            /* !< STXEMPTY Offset */
#define I2C_CPU_INT_ICLR_STXEMPTY_MASK           ((uint32_t)0x00200000U)         /* !< Transmit FIFO Empty interrupt mask.
                                                                                    This interrupt is set if all data in
                                                                                    the Transmit FIFO have been shifted
                                                                                    out and the transmit goes into idle
                                                                                    mode. */
#define I2C_CPU_INT_ICLR_STXEMPTY_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_STXEMPTY_CLR            ((uint32_t)0x00200000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[SRXFIFOFULL] Bits */
#define I2C_CPU_INT_ICLR_SRXFIFOFULL_OFS         (20)                            /* !< SRXFIFOFULL Offset */
#define I2C_CPU_INT_ICLR_SRXFIFOFULL_MASK        ((uint32_t)0x00100000U)         /* !< RXFIFO full event. This interrupt
                                                                                    is set if an RX FIFO is full. */
#define I2C_CPU_INT_ICLR_SRXFIFOFULL_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_ICLR_SRXFIFOFULL_CLR         ((uint32_t)0x00100000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[SRXFIFOTRG] Bits */
#define I2C_CPU_INT_ICLR_SRXFIFOTRG_OFS          (18)                            /* !< SRXFIFOTRG Offset */
#define I2C_CPU_INT_ICLR_SRXFIFOTRG_MASK         ((uint32_t)0x00040000U)         /* !< Target Receive FIFO Trigger */
#define I2C_CPU_INT_ICLR_SRXFIFOTRG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_ICLR_SRXFIFOTRG_CLR          ((uint32_t)0x00040000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[STXFIFOTRG] Bits */
#define I2C_CPU_INT_ICLR_STXFIFOTRG_OFS          (19)                            /* !< STXFIFOTRG Offset */
#define I2C_CPU_INT_ICLR_STXFIFOTRG_MASK         ((uint32_t)0x00080000U)         /* !< Target Transmit FIFO Trigger */
#define I2C_CPU_INT_ICLR_STXFIFOTRG_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define I2C_CPU_INT_ICLR_STXFIFOTRG_CLR          ((uint32_t)0x00080000U)         /* !< Set Interrupt Mask */
/* I2C_CPU_INT_ICLR[SSTART] Bits */
#define I2C_CPU_INT_ICLR_SSTART_OFS              (22)                            /* !< SSTART Offset */
#define I2C_CPU_INT_ICLR_SSTART_MASK             ((uint32_t)0x00400000U)         /* !< Target START Detection Interrupt */
#define I2C_CPU_INT_ICLR_SSTART_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_SSTART_CLR              ((uint32_t)0x00400000U)         /* !< Clear interrupt */
/* I2C_CPU_INT_ICLR[SSTOP] Bits */
#define I2C_CPU_INT_ICLR_SSTOP_OFS               (23)                            /* !< SSTOP Offset */
#define I2C_CPU_INT_ICLR_SSTOP_MASK              ((uint32_t)0x00800000U)         /* !< Target STOP Detection Interrupt */
#define I2C_CPU_INT_ICLR_SSTOP_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_SSTOP_CLR               ((uint32_t)0x00800000U)         /* !< Clear interrupt */
/* I2C_CPU_INT_ICLR[SDMA_DONE_TX] Bits */
#define I2C_CPU_INT_ICLR_SDMA_DONE_TX_OFS        (25)                            /* !< SDMA_DONE_TX Offset */
#define I2C_CPU_INT_ICLR_SDMA_DONE_TX_MASK       ((uint32_t)0x02000000U)         /* !< DMA Done on Event Channel TX */
#define I2C_CPU_INT_ICLR_SDMA_DONE_TX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_SDMA_DONE_TX_CLR        ((uint32_t)0x02000000U)         /* !< Clear interrupt */
/* I2C_CPU_INT_ICLR[SDMA_DONE_RX] Bits */
#define I2C_CPU_INT_ICLR_SDMA_DONE_RX_OFS        (26)                            /* !< SDMA_DONE_RX Offset */
#define I2C_CPU_INT_ICLR_SDMA_DONE_RX_MASK       ((uint32_t)0x04000000U)         /* !< DMA Done on Event Channel RX */
#define I2C_CPU_INT_ICLR_SDMA_DONE_RX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_SDMA_DONE_RX_CLR        ((uint32_t)0x04000000U)         /* !< Clear interrupt */
/* I2C_CPU_INT_ICLR[MPEC_RX_ERR] Bits */
#define I2C_CPU_INT_ICLR_MPEC_RX_ERR_OFS         (13)                            /* !< MPEC_RX_ERR Offset */
#define I2C_CPU_INT_ICLR_MPEC_RX_ERR_MASK        ((uint32_t)0x00002000U)         /* !< Controller RX Pec Error Interrupt */
#define I2C_CPU_INT_ICLR_MPEC_RX_ERR_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_MPEC_RX_ERR_CLR         ((uint32_t)0x00002000U)         /* !< Clear Interrupt */
/* I2C_CPU_INT_ICLR[TIMEOUTB] Bits */
#define I2C_CPU_INT_ICLR_TIMEOUTB_OFS            (15)                            /* !< TIMEOUTB Offset */
#define I2C_CPU_INT_ICLR_TIMEOUTB_MASK           ((uint32_t)0x00008000U)         /* !< Timeout B Interrupt */
#define I2C_CPU_INT_ICLR_TIMEOUTB_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_TIMEOUTB_CLR            ((uint32_t)0x00008000U)         /* !< Clear Interrupt */
/* I2C_CPU_INT_ICLR[SPEC_RX_ERR] Bits */
#define I2C_CPU_INT_ICLR_SPEC_RX_ERR_OFS         (27)                            /* !< SPEC_RX_ERR Offset */
#define I2C_CPU_INT_ICLR_SPEC_RX_ERR_MASK        ((uint32_t)0x08000000U)         /* !< Target RX Pec Error Interrupt */
#define I2C_CPU_INT_ICLR_SPEC_RX_ERR_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_SPEC_RX_ERR_CLR         ((uint32_t)0x08000000U)         /* !< Clear Interrupt */
/* I2C_CPU_INT_ICLR[STX_UNFL] Bits */
#define I2C_CPU_INT_ICLR_STX_UNFL_OFS            (28)                            /* !< STX_UNFL Offset */
#define I2C_CPU_INT_ICLR_STX_UNFL_MASK           ((uint32_t)0x10000000U)         /* !< Target TX FIFO underflow */
#define I2C_CPU_INT_ICLR_STX_UNFL_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_STX_UNFL_CLR            ((uint32_t)0x10000000U)         /* !< Clear Interrupt */
/* I2C_CPU_INT_ICLR[SRX_OVFL] Bits */
#define I2C_CPU_INT_ICLR_SRX_OVFL_OFS            (29)                            /* !< SRX_OVFL Offset */
#define I2C_CPU_INT_ICLR_SRX_OVFL_MASK           ((uint32_t)0x20000000U)         /* !< Target RX FIFO overflow */
#define I2C_CPU_INT_ICLR_SRX_OVFL_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_SRX_OVFL_CLR            ((uint32_t)0x20000000U)         /* !< Clear Interrupt */
/* I2C_CPU_INT_ICLR[SARBLOST] Bits */
#define I2C_CPU_INT_ICLR_SARBLOST_OFS            (30)                            /* !< SARBLOST Offset */
#define I2C_CPU_INT_ICLR_SARBLOST_MASK           ((uint32_t)0x40000000U)         /* !< Target Arbitration Lost */
#define I2C_CPU_INT_ICLR_SARBLOST_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_CPU_INT_ICLR_SARBLOST_CLR            ((uint32_t)0x40000000U)         /* !< Clear Interrupt */
/* I2C_CPU_INT_ICLR[INTR_OVFL] Bits */
#define I2C_CPU_INT_ICLR_INTR_OVFL_OFS           (31)                            /* !< INTR_OVFL Offset */
#define I2C_CPU_INT_ICLR_INTR_OVFL_MASK          ((uint32_t)0x80000000U)         /* !< Interrupt overflow */
#define I2C_CPU_INT_ICLR_INTR_OVFL_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< No effect */
#define I2C_CPU_INT_ICLR_INTR_OVFL_CLR           ((uint32_t)0x80000000U)         /* !< Clear interrupt */

/* I2C_PWREN Bits */
/* I2C_PWREN[ENABLE] Bits */
#define I2C_PWREN_ENABLE_OFS                     (0)                             /* !< ENABLE Offset */
#define I2C_PWREN_ENABLE_MASK                    ((uint32_t)0x00000001U)         /* !< Enable the power */
#define I2C_PWREN_ENABLE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Disable Power */
#define I2C_PWREN_ENABLE_ENABLE                  ((uint32_t)0x00000001U)         /* !< Enable Power */
/* I2C_PWREN[KEY] Bits */
#define I2C_PWREN_KEY_OFS                        (24)                            /* !< KEY Offset */
#define I2C_PWREN_KEY_MASK                       ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define I2C_PWREN_KEY_UNLOCK_W                   ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* I2C_RSTCTL Bits */
/* I2C_RSTCTL[RESETSTKYCLR] Bits */
#define I2C_RSTCTL_RESETSTKYCLR_OFS              (1)                             /* !< RESETSTKYCLR Offset */
#define I2C_RSTCTL_RESETSTKYCLR_MASK             ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define I2C_RSTCTL_RESETSTKYCLR_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_RSTCTL_RESETSTKYCLR_CLR              ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* I2C_RSTCTL[RESETASSERT] Bits */
#define I2C_RSTCTL_RESETASSERT_OFS               (0)                             /* !< RESETASSERT Offset */
#define I2C_RSTCTL_RESETASSERT_MASK              ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define I2C_RSTCTL_RESETASSERT_NOP               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define I2C_RSTCTL_RESETASSERT_ASSERT            ((uint32_t)0x00000001U)         /* !< Assert reset */
/* I2C_RSTCTL[KEY] Bits */
#define I2C_RSTCTL_KEY_OFS                       (24)                            /* !< KEY Offset */
#define I2C_RSTCTL_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define I2C_RSTCTL_KEY_UNLOCK_W                  ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* I2C_CLKCFG Bits */
/* I2C_CLKCFG[KEY] Bits */
#define I2C_CLKCFG_KEY_OFS                       (24)                            /* !< KEY Offset */
#define I2C_CLKCFG_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define I2C_CLKCFG_KEY_UNLOCK                    ((uint32_t)0xA9000000U)         /* !< key value to allow change field of
                                                                                    GPRCM */
/* I2C_CLKCFG[BLOCKASYNC] Bits */
#define I2C_CLKCFG_BLOCKASYNC_OFS                (8)                             /* !< BLOCKASYNC Offset */
#define I2C_CLKCFG_BLOCKASYNC_MASK               ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define I2C_CLKCFG_BLOCKASYNC_DISABLE            ((uint32_t)0x00000000U)         /* !< Not block async clock request */
#define I2C_CLKCFG_BLOCKASYNC_ENABLE             ((uint32_t)0x00000100U)         /* !< Block async clock request */

/* I2C_STAT Bits */
/* I2C_STAT[RESETSTKY] Bits */
#define I2C_STAT_RESETSTKY_OFS                   (16)                            /* !< RESETSTKY Offset */
#define I2C_STAT_RESETSTKY_MASK                  ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define I2C_STAT_RESETSTKY_NORES                 ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define I2C_STAT_RESETSTKY_RESET                 ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* I2C_CLKDIV Bits */
/* I2C_CLKDIV[RATIO] Bits */
#define I2C_CLKDIV_RATIO_OFS                     (0)                             /* !< RATIO Offset */
#define I2C_CLKDIV_RATIO_MASK                    ((uint32_t)0x00000007U)         /* !< Selects divide ratio of module
                                                                                    clock */
#define I2C_CLKDIV_RATIO_DIV_BY_1                ((uint32_t)0x00000000U)         /* !< Do not divide clock source */
#define I2C_CLKDIV_RATIO_DIV_BY_2                ((uint32_t)0x00000001U)         /* !< Divide clock source by 2 */
#define I2C_CLKDIV_RATIO_DIV_BY_3                ((uint32_t)0x00000002U)         /* !< Divide clock source by 3 */
#define I2C_CLKDIV_RATIO_DIV_BY_4                ((uint32_t)0x00000003U)         /* !< Divide clock source by 4 */
#define I2C_CLKDIV_RATIO_DIV_BY_5                ((uint32_t)0x00000004U)         /* !< Divide clock source by 5 */
#define I2C_CLKDIV_RATIO_DIV_BY_6                ((uint32_t)0x00000005U)         /* !< Divide clock source by 6 */
#define I2C_CLKDIV_RATIO_DIV_BY_7                ((uint32_t)0x00000006U)         /* !< Divide clock source by 7 */
#define I2C_CLKDIV_RATIO_DIV_BY_8                ((uint32_t)0x00000007U)         /* !< Divide clock source by 8 */

/* I2C_CLKSEL Bits */
/* I2C_CLKSEL[MFCLK_SEL] Bits */
#define I2C_CLKSEL_MFCLK_SEL_OFS                 (2)                             /* !< MFCLK_SEL Offset */
#define I2C_CLKSEL_MFCLK_SEL_MASK                ((uint32_t)0x00000004U)         /* !< Selects MFCLK as clock source if
                                                                                    enabled */
#define I2C_CLKSEL_MFCLK_SEL_DISABLE             ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define I2C_CLKSEL_MFCLK_SEL_ENABLE              ((uint32_t)0x00000004U)         /* !< Select this clock as a source */
/* I2C_CLKSEL[BUSCLK_SEL] Bits */
#define I2C_CLKSEL_BUSCLK_SEL_OFS                (3)                             /* !< BUSCLK_SEL Offset */
#define I2C_CLKSEL_BUSCLK_SEL_MASK               ((uint32_t)0x00000008U)         /* !< Selects BUSCLK as clock source if
                                                                                    enabled */
#define I2C_CLKSEL_BUSCLK_SEL_DISABLE            ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define I2C_CLKSEL_BUSCLK_SEL_ENABLE             ((uint32_t)0x00000008U)         /* !< Select this clock as a source */

/* I2C_PDBGCTL Bits */
/* I2C_PDBGCTL[FREE] Bits */
#define I2C_PDBGCTL_FREE_OFS                     (0)                             /* !< FREE Offset */
#define I2C_PDBGCTL_FREE_MASK                    ((uint32_t)0x00000001U)         /* !< Free run control */
#define I2C_PDBGCTL_FREE_STOP                    ((uint32_t)0x00000000U)         /* !< The peripheral freezes
                                                                                    functionality while the Core Halted
                                                                                    input is asserted and resumes when it
                                                                                    is deasserted. */
#define I2C_PDBGCTL_FREE_RUN                     ((uint32_t)0x00000001U)         /* !< The peripheral ignores the state of
                                                                                    the Core Halted input */
/* I2C_PDBGCTL[SOFT] Bits */
#define I2C_PDBGCTL_SOFT_OFS                     (1)                             /* !< SOFT Offset */
#define I2C_PDBGCTL_SOFT_MASK                    ((uint32_t)0x00000002U)         /* !< Soft halt boundary control. This
                                                                                    function is only available, if [FREE]
                                                                                    is set to 'STOP' */
#define I2C_PDBGCTL_SOFT_IMMEDIATE               ((uint32_t)0x00000000U)         /* !< The peripheral will halt
                                                                                    immediately, even if the resultant
                                                                                    state will result in corruption if
                                                                                    the system is restarted */
#define I2C_PDBGCTL_SOFT_DELAYED                 ((uint32_t)0x00000002U)         /* !< The peripheral blocks the debug
                                                                                    freeze until it has reached a
                                                                                    boundary where it can resume without
                                                                                    corruption */

/* I2C_EVT_MODE Bits */
/* I2C_EVT_MODE[INT0_CFG] Bits */
#define I2C_EVT_MODE_INT0_CFG_OFS                (0)                             /* !< INT0_CFG Offset */
#define I2C_EVT_MODE_INT0_CFG_MASK               ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT0] */
#define I2C_EVT_MODE_INT0_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define I2C_EVT_MODE_INT0_CFG_SOFTWARE           ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define I2C_EVT_MODE_INT0_CFG_HARDWARE           ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* I2C_EVT_MODE[INT1_CFG] Bits */
#define I2C_EVT_MODE_INT1_CFG_OFS                (2)                             /* !< INT1_CFG Offset */
#define I2C_EVT_MODE_INT1_CFG_MASK               ((uint32_t)0x0000000CU)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT1] */
#define I2C_EVT_MODE_INT1_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define I2C_EVT_MODE_INT1_CFG_SOFTWARE           ((uint32_t)0x00000004U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define I2C_EVT_MODE_INT1_CFG_HARDWARE           ((uint32_t)0x00000008U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* I2C_EVT_MODE[EVT2_CFG] Bits */
#define I2C_EVT_MODE_EVT2_CFG_OFS                (4)                             /* !< EVT2_CFG Offset */
#define I2C_EVT_MODE_EVT2_CFG_MASK               ((uint32_t)0x00000030U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT2] */
#define I2C_EVT_MODE_EVT2_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define I2C_EVT_MODE_EVT2_CFG_SOFTWARE           ((uint32_t)0x00000010U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define I2C_EVT_MODE_EVT2_CFG_HARDWARE           ((uint32_t)0x00000020U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* I2C_INTCTL Bits */
/* I2C_INTCTL[INTEVAL] Bits */
#define I2C_INTCTL_INTEVAL_OFS                   (0)                             /* !< INTEVAL Offset */
#define I2C_INTCTL_INTEVAL_MASK                  ((uint32_t)0x00000001U)         /* !< Writing a 1 to this field
                                                                                    re-evaluates the interrupt sources. */
#define I2C_INTCTL_INTEVAL_DISABLE               ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define I2C_INTCTL_INTEVAL_EVAL                  ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */

/* I2C_DESC Bits */
/* I2C_DESC[MINREV] Bits */
#define I2C_DESC_MINREV_OFS                      (0)                             /* !< MINREV Offset */
#define I2C_DESC_MINREV_MASK                     ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
#define I2C_DESC_MINREV_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_DESC_MINREV_MAXIMUM                  ((uint32_t)0x0000000FU)         /* !< Highest possible value */
/* I2C_DESC[MAJREV] Bits */
#define I2C_DESC_MAJREV_OFS                      (4)                             /* !< MAJREV Offset */
#define I2C_DESC_MAJREV_MASK                     ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
#define I2C_DESC_MAJREV_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_DESC_MAJREV_MAXIMUM                  ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* I2C_DESC[INSTNUM] Bits */
#define I2C_DESC_INSTNUM_OFS                     (8)                             /* !< INSTNUM Offset */
#define I2C_DESC_INSTNUM_MASK                    ((uint32_t)0x00000F00U)         /* !< Instance Number within the device.
                                                                                    This will be a parameter to the RTL
                                                                                    for modules that can have multiple
                                                                                    instances */
#define I2C_DESC_INSTNUM_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_DESC_INSTNUM_MAXIMUM                 ((uint32_t)0x00000F00U)         /* !< Highest possible value */
/* I2C_DESC[FEATUREVER] Bits */
#define I2C_DESC_FEATUREVER_OFS                  (12)                            /* !< FEATUREVER Offset */
#define I2C_DESC_FEATUREVER_MASK                 ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
#define I2C_DESC_FEATUREVER_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_DESC_FEATUREVER_MAXIMUM              ((uint32_t)0x0000F000U)         /* !< Highest possible value */
/* I2C_DESC[MODULEID] Bits */
#define I2C_DESC_MODULEID_OFS                    (16)                            /* !< MODULEID Offset */
#define I2C_DESC_MODULEID_MASK                   ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */
#define I2C_DESC_MODULEID_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define I2C_DESC_MODULEID_MAXIMUM                ((uint32_t)0xFFFF0000U)         /* !< Highest possible value */

/* I2C_GFCTL Bits */
/* I2C_GFCTL[AGFSEL] Bits */
#define I2C_GFCTL_AGFSEL_OFS                     (9)                             /* !< AGFSEL Offset */
#define I2C_GFCTL_AGFSEL_MASK                    ((uint32_t)0x00000600U)         /* !< Analog Glitch Suppression Pulse
                                                                                    Width This field controls the pulse
                                                                                    width select for the analog glitch
                                                                                    suppression on SCL and SDA lines.
                                                                                    See device datasheet for exact
                                                                                    values. (ULP I2C only) */
#define I2C_GFCTL_AGFSEL_AGLIT_5                 ((uint32_t)0x00000000U)         /* !< Pulses shorter then 5ns length are
                                                                                    filtered. */
#define I2C_GFCTL_AGFSEL_AGLIT_10                ((uint32_t)0x00000200U)         /* !< Pulses shorter then 10ns length are
                                                                                    filtered. */
#define I2C_GFCTL_AGFSEL_AGLIT_25                ((uint32_t)0x00000400U)         /* !< Pulses shorter then 25ns length are
                                                                                    filtered. */
#define I2C_GFCTL_AGFSEL_AGLIT_50                ((uint32_t)0x00000600U)         /* !< Pulses shorter then 50ns length are
                                                                                    filtered. */
/* I2C_GFCTL[DGFSEL] Bits */
#define I2C_GFCTL_DGFSEL_OFS                     (0)                             /* !< DGFSEL Offset */
#define I2C_GFCTL_DGFSEL_MASK                    ((uint32_t)0x00000007U)         /* !< Glitch Suppression Pulse Width
                                                                                    This field controls the pulse width
                                                                                    select for glitch suppression on the
                                                                                    SCL and SDA lines. The following
                                                                                    values are the glitch suppression
                                                                                    values in terms of functional clocks.
                                                                                    (Core Domain only) */
#define I2C_GFCTL_DGFSEL_DISABLED                ((uint32_t)0x00000000U)         /* !< Bypass */
#define I2C_GFCTL_DGFSEL_CLK_1                   ((uint32_t)0x00000001U)         /* !< 1 clock */
#define I2C_GFCTL_DGFSEL_CLK_2                   ((uint32_t)0x00000002U)         /* !< 2 clocks */
#define I2C_GFCTL_DGFSEL_CLK_3                   ((uint32_t)0x00000003U)         /* !< 3 clocks */
#define I2C_GFCTL_DGFSEL_CLK_4                   ((uint32_t)0x00000004U)         /* !< 4 clocks */
#define I2C_GFCTL_DGFSEL_CLK_8                   ((uint32_t)0x00000005U)         /* !< 8 clocks */
#define I2C_GFCTL_DGFSEL_CLK_16                  ((uint32_t)0x00000006U)         /* !< 16 clocks */
#define I2C_GFCTL_DGFSEL_CLK_31                  ((uint32_t)0x00000007U)         /* !< 31 clocks */
/* I2C_GFCTL[AGFEN] Bits */
#define I2C_GFCTL_AGFEN_OFS                      (8)                             /* !< AGFEN Offset */
#define I2C_GFCTL_AGFEN_MASK                     ((uint32_t)0x00000100U)         /* !< Analog Glitch Suppression Enable */
#define I2C_GFCTL_AGFEN_DISABLE                  ((uint32_t)0x00000000U)         /* !< Analog Glitch Filter disable */
#define I2C_GFCTL_AGFEN_ENABLE                   ((uint32_t)0x00000100U)         /* !< Analog Glitch Filter enable */
/* I2C_GFCTL[CHAIN] Bits */
#define I2C_GFCTL_CHAIN_OFS                      (11)                            /* !< CHAIN Offset */
#define I2C_GFCTL_CHAIN_MASK                     ((uint32_t)0x00000800U)         /* !< Analog and digital noise filters
                                                                                    chaining enable. */
#define I2C_GFCTL_CHAIN_DISABLE                  ((uint32_t)0x00000000U)         /* !< When 0, chaining is disabled and
                                                                                    only digital filter output is
                                                                                    available to IP logic for
                                                                                    oversampling */
#define I2C_GFCTL_CHAIN_ENABLE                   ((uint32_t)0x00000800U)         /* !< When 1, analog and digital glitch
                                                                                    filters are chained and the output of
                                                                                    the combination is made available to
                                                                                    IP logic for oversampling */

/* I2C_TIMEOUT_CTL Bits */
/* I2C_TIMEOUT_CTL[TCNTLA] Bits */
#define I2C_TIMEOUT_CTL_TCNTLA_OFS               (0)                             /* !< TCNTLA Offset */
#define I2C_TIMEOUT_CTL_TCNTLA_MASK              ((uint32_t)0x000000FFU)         /* !< Timeout counter A load value
                                                                                    Counter A is used for SCL low
                                                                                    detection. This field contains the
                                                                                    upper 8 bits of a 12-bit pre-load
                                                                                    value for the Timeout A count. NOTE:
                                                                                    The value of CNTLA must be greater
                                                                                    than 1h.   Each count is equal to 520
                                                                                    times the timeout period of
                                                                                    functional clock. For example, with
                                                                                    8MHz functional clock and a 100KHz
                                                                                    operating I2C clock, one timeout
                                                                                    period will be equal to (1 / 8MHz) *
                                                                                    520 or 65 us. */
#define I2C_TIMEOUT_CTL_TCNTLA_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest Value */
#define I2C_TIMEOUT_CTL_TCNTLA_MAXIMUM           ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* I2C_TIMEOUT_CTL[TCNTAEN] Bits */
#define I2C_TIMEOUT_CTL_TCNTAEN_OFS              (15)                            /* !< TCNTAEN Offset */
#define I2C_TIMEOUT_CTL_TCNTAEN_MASK             ((uint32_t)0x00008000U)         /* !< Timeout Counter A Enable */
#define I2C_TIMEOUT_CTL_TCNTAEN_DISABLE          ((uint32_t)0x00000000U)         /* !< Disable Timeout Counter B */
#define I2C_TIMEOUT_CTL_TCNTAEN_ENABLE           ((uint32_t)0x00008000U)         /* !< Enable Timeout Counter B */
/* I2C_TIMEOUT_CTL[TCNTLB] Bits */
#define I2C_TIMEOUT_CTL_TCNTLB_OFS               (16)                            /* !< TCNTLB Offset */
#define I2C_TIMEOUT_CTL_TCNTLB_MASK              ((uint32_t)0x00FF0000U)         /* !< Timeout Count B Load: Counter B is
                                                                                    used for SCL High Detection. This
                                                                                    field contains the upper 8 bits of a
                                                                                    12-bit pre-load value for the Timeout
                                                                                    B count. NOTE: The value of CNTLB
                                                                                    must be greater than 1h.   Each count
                                                                                    is equal to 1* clock period. For
                                                                                    example, with 10MHz functional clock
                                                                                    one timeout period will be equal
                                                                                    to1*100ns. */
#define I2C_TIMEOUT_CTL_TCNTLB_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define I2C_TIMEOUT_CTL_TCNTLB_MAXIMUM           ((uint32_t)0x00FF0000U)         /* !< Highest possible value */
/* I2C_TIMEOUT_CTL[TCNTBEN] Bits */
#define I2C_TIMEOUT_CTL_TCNTBEN_OFS              (31)                            /* !< TCNTBEN Offset */
#define I2C_TIMEOUT_CTL_TCNTBEN_MASK             ((uint32_t)0x80000000U)         /* !< Timeout Counter B Enable */
#define I2C_TIMEOUT_CTL_TCNTBEN_DISABLE          ((uint32_t)0x00000000U)         /* !< Disable Timeout Counter B */
#define I2C_TIMEOUT_CTL_TCNTBEN_ENABLE           ((uint32_t)0x80000000U)         /* !< Enable Timeout Counter B */

/* I2C_TIMEOUT_CNT Bits */
/* I2C_TIMEOUT_CNT[TCNTA] Bits */
#define I2C_TIMEOUT_CNT_TCNTA_OFS                (0)                             /* !< TCNTA Offset */
#define I2C_TIMEOUT_CNT_TCNTA_MASK               ((uint32_t)0x000000FFU)         /* !< Timeout Count A Current Count: This
                                                                                    field contains the upper 8 bits of a
                                                                                    12-bit current counter for timeout
                                                                                    counter A */
#define I2C_TIMEOUT_CNT_TCNTA_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest Value */
#define I2C_TIMEOUT_CNT_TCNTA_MAXIMUM            ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* I2C_TIMEOUT_CNT[TCNTB] Bits */
#define I2C_TIMEOUT_CNT_TCNTB_OFS                (16)                            /* !< TCNTB Offset */
#define I2C_TIMEOUT_CNT_TCNTB_MASK               ((uint32_t)0x00FF0000U)         /* !< Timeout Count B Current Count: This
                                                                                    field contains the upper 8 bits of a
                                                                                    12-bit current counter for timeout
                                                                                    counter B */
#define I2C_TIMEOUT_CNT_TCNTB_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest Value */
#define I2C_TIMEOUT_CNT_TCNTB_MAXIMUM            ((uint32_t)0x00FF0000U)         /* !< Highest possible value */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_i2c__include */
