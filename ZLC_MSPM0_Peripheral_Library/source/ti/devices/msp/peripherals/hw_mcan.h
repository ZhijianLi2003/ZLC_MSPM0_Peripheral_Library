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

#ifndef ti_devices_msp_peripherals_hw_mcan__include
#define ti_devices_msp_peripherals_hw_mcan__include

/* Filename: hw_mcan.h */
/* Revised: 2023-06-13 16:25:08 */
/* Revision: 80c507b5f57e662daefb523742741547f0b08eb5 */

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
* MCAN Registers
******************************************************************************/
#define MCAN_CPU_INT_OFS                         ((uint32_t)0x00007820U)
#define MCAN_MSP_OFS                             ((uint32_t)0x00007800U)
#define MCAN_ECC_REGS_OFS                        ((uint32_t)0x00007400U)
#define MCAN_REGS_OFS                            ((uint32_t)0x00007200U)
#define MCAN_PROCESSORS_OFS                      ((uint32_t)0x00007200U)
#define MCAN_TI_WRAPPER_OFS                      ((uint32_t)0x00007200U)
#define MCAN_MCAN_OFS                            ((uint32_t)0x00007000U)
#define MCAN_MCANSS_OFS                          ((uint32_t)0x00006000U)


/** @addtogroup MCAN_CPU_INT
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00007820) Interrupt Index Register */
       uint32_t RESERVED0;
  __IO uint32_t IMASK;                             /* !< (@ 0x00007828) Interrupt mask */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x00007830) Raw interrupt status */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x00007838) Masked interrupt status */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x00007840) Interrupt set */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x00007848) Interrupt clear */
} MCAN_CPU_INT_Regs;

/*@}*/ /* end of group MCAN_CPU_INT */

/** @addtogroup MCAN_MSP
  @{
*/

typedef struct {
       uint32_t RESERVED0[8];
  MCAN_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00007820) */
       uint32_t RESERVED1[37];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000078E0) Event Mode */
       uint32_t RESERVED2[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000078FC) Module Description */
  __IO uint32_t MCANSS_CLKEN;                      /* !< (@ 0x00007900) MCAN module clock enable */
  __IO uint32_t MCANSS_CLKDIV;                     /* !< (@ 0x00007904) Clock divider */
  __IO uint32_t MCANSS_CLKCTL;                     /* !< (@ 0x00007908) MCAN-SS clock stop control register */
  __I  uint32_t MCANSS_CLKSTS;                     /* !< (@ 0x0000790C) MCANSS clock stop status register */
} MCAN_MSP_Regs;

/*@}*/ /* end of group MCAN_MSP */

/** @addtogroup MCAN_ECC_REGS
  @{
*/

typedef struct {
  __I  uint32_t MCANERR_REV;                       /* !< (@ 0x00007400) MCAN Error Aggregator Revision Register */
       uint32_t RESERVED0;
  __IO uint32_t MCANERR_VECTOR;                    /* !< (@ 0x00007408) MCAN ECC Vector Register */
  __I  uint32_t MCANERR_STAT;                      /* !< (@ 0x0000740C) MCAN Error Misc Status */
  __I  uint32_t MCANERR_WRAP_REV;                  /* !< (@ 0x00007410) MCAN ECC Wrapper Revision Register */
  __IO uint32_t MCANERR_CTRL;                      /* !< (@ 0x00007414) MCAN ECC Control */
  __IO uint32_t MCANERR_ERR_CTRL1;                 /* !< (@ 0x00007418) MCAN ECC Error Control 1 Register */
  __IO uint32_t MCANERR_ERR_CTRL2;                 /* !< (@ 0x0000741C) MCAN ECC Error Control 2 Register */
  __IO uint32_t MCANERR_ERR_STAT1;                 /* !< (@ 0x00007420) MCAN ECC Error Status 1 Register */
  __I  uint32_t MCANERR_ERR_STAT2;                 /* !< (@ 0x00007424) MCAN ECC Error Status 2 Register */
  __IO uint32_t MCANERR_ERR_STAT3;                 /* !< (@ 0x00007428) MCAN ECC Error Status 3 Register */
       uint32_t RESERVED1[4];
  __IO uint32_t MCANERR_SEC_EOI;                   /* !< (@ 0x0000743C) MCAN Single Error Corrected End of Interrupt
                                                      Register */
  __IO uint32_t MCANERR_SEC_STATUS;                /* !< (@ 0x00007440) MCAN Single Error Corrected Interrupt Status
                                                      Register */
       uint32_t RESERVED2[15];
  __IO uint32_t MCANERR_SEC_ENABLE_SET;            /* !< (@ 0x00007480) MCAN Single Error Corrected Interrupt Enable Set
                                                      Register */
       uint32_t RESERVED3[15];
  __IO uint32_t MCANERR_SEC_ENABLE_CLR;            /* !< (@ 0x000074C0) MCAN Single Error Corrected Interrupt Enable Clear
                                                      Register */
       uint32_t RESERVED4[30];
  __IO uint32_t MCANERR_DED_EOI;                   /* !< (@ 0x0000753C) MCAN Double Error Detected End of Interrupt
                                                      Register */
  __IO uint32_t MCANERR_DED_STATUS;                /* !< (@ 0x00007540) MCAN Double Error Detected Interrupt Status
                                                      Register */
       uint32_t RESERVED5[15];
  __IO uint32_t MCANERR_DED_ENABLE_SET;            /* !< (@ 0x00007580) MCAN Double Error Detected Interrupt Enable Set
                                                      Register */
       uint32_t RESERVED6[15];
  __IO uint32_t MCANERR_DED_ENABLE_CLR;            /* !< (@ 0x000075C0) MCAN Double Error Detected Interrupt Enable Clear
                                                      Register */
       uint32_t RESERVED7[15];
  __IO uint32_t MCANERR_AGGR_ENABLE_SET;           /* !< (@ 0x00007600) MCAN Error Aggregator Enable Set Register */
  __IO uint32_t MCANERR_AGGR_ENABLE_CLR;           /* !< (@ 0x00007604) MCAN Error Aggregator Enable Clear Register */
  __IO uint32_t MCANERR_AGGR_STATUS_SET;           /* !< (@ 0x00007608) MCAN Error Aggregator Status Set Register */
  __IO uint32_t MCANERR_AGGR_STATUS_CLR;           /* !< (@ 0x0000760C) MCAN Error Aggregator Status Clear Register */
} MCAN_ECC_REGS_Regs;

/*@}*/ /* end of group MCAN_ECC_REGS */

/** @addtogroup MCAN_REGS
  @{
*/

typedef struct {
  __I  uint32_t MCANSS_PID;                        /* !< (@ 0x00007200) MCAN Subsystem Revision Register */
  __IO uint32_t MCANSS_CTRL;                       /* !< (@ 0x00007204) MCAN Subsystem Control Register */
  __I  uint32_t MCANSS_STAT;                       /* !< (@ 0x00007208) MCAN Subsystem Status Register */
  __IO uint32_t MCANSS_ICS;                        /* !< (@ 0x0000720C) MCAN Subsystem Interrupt Clear Shadow Register */
  __IO uint32_t MCANSS_IRS;                        /* !< (@ 0x00007210) MCAN Subsystem Interrupt Raw Satus Register */
  __IO uint32_t MCANSS_IECS;                       /* !< (@ 0x00007214) MCAN Subsystem Interrupt Enable Clear Shadow
                                                      Register */
  __IO uint32_t MCANSS_IE;                         /* !< (@ 0x00007218) MCAN Subsystem Interrupt Enable Register */
  __I  uint32_t MCANSS_IES;                        /* !< (@ 0x0000721C) MCAN Subsystem Interrupt Enable Status */
  __IO uint32_t MCANSS_EOI;                        /* !< (@ 0x00007220) MCAN Subsystem End of Interrupt */
  __IO uint32_t MCANSS_EXT_TS_PRESCALER;           /* !< (@ 0x00007224) MCAN Subsystem External Timestamp Prescaler 0 */
  __I  uint32_t MCANSS_EXT_TS_UNSERVICED_INTR_CNTR;/* !< (@ 0x00007228) MCAN Subsystem External Timestamp Unserviced
                                                      Interrupts Counter */
} MCAN_REGS_Regs;

/*@}*/ /* end of group MCAN_REGS */

/** @addtogroup MCAN_PROCESSORS
  @{
*/

typedef struct {
  MCAN_REGS_Regs  MCANSS_REGS;                       /* !< (@ 0x00007200) */
       uint32_t RESERVED0[117];
  MCAN_ECC_REGS_Regs  MCAN_ECC_REGS;                     /* !< (@ 0x00007400) */
} MCAN_PROCESSORS_Regs;

/*@}*/ /* end of group MCAN_PROCESSORS */

/** @addtogroup MCAN_TI_WRAPPER
  @{
*/

typedef struct {
  MCAN_PROCESSORS_Regs  PROCESSORS;                        /* !< (@ 0x00007200) */
       uint32_t RESERVED0[124];
  MCAN_MSP_Regs  MSP;                               /* !< (@ 0x00007800) */
} MCAN_TI_WRAPPER_Regs;

/*@}*/ /* end of group MCAN_TI_WRAPPER */

/** @addtogroup MCAN_MCAN
  @{
*/

typedef struct {
  __I  uint32_t MCAN_CREL;                         /* !< (@ 0x00007000) MCAN Core Release Register */
  __I  uint32_t MCAN_ENDN;                         /* !< (@ 0x00007004) MCAN Endian Register */
       uint32_t RESERVED0;
  __IO uint32_t MCAN_DBTP;                         /* !< (@ 0x0000700C) MCAN Data Bit Timing and Prescaler Register */
  __IO uint32_t MCAN_TEST;                         /* !< (@ 0x00007010) MCAN Test Register */
  __IO uint32_t MCAN_RWD;                          /* !< (@ 0x00007014) MCAN RAM Watchdog */
  __IO uint32_t MCAN_CCCR;                         /* !< (@ 0x00007018) MCAN CC Control Register */
  __IO uint32_t MCAN_NBTP;                         /* !< (@ 0x0000701C) MCAN Nominal Bit Timing and Prescaler Register */
  __IO uint32_t MCAN_TSCC;                         /* !< (@ 0x00007020) MCAN Timestamp Counter Configuration */
  __IO uint32_t MCAN_TSCV;                         /* !< (@ 0x00007024) MCAN Timestamp Counter Value */
  __IO uint32_t MCAN_TOCC;                         /* !< (@ 0x00007028) MCAN Timeout Counter Configuration */
  __IO uint32_t MCAN_TOCV;                         /* !< (@ 0x0000702C) MCAN Timeout Counter Value */
       uint32_t RESERVED1[4];
  __I  uint32_t MCAN_ECR;                          /* !< (@ 0x00007040) MCAN Error Counter Register */
  __I  uint32_t MCAN_PSR;                          /* !< (@ 0x00007044) MCAN Protocol Status Register */
  __IO uint32_t MCAN_TDCR;                         /* !< (@ 0x00007048) MCAN Transmitter Delay Compensation Register */
       uint32_t RESERVED2;
  __IO uint32_t MCAN_IR;                           /* !< (@ 0x00007050) MCAN Interrupt Register */
  __IO uint32_t MCAN_IE;                           /* !< (@ 0x00007054) MCAN Interrupt Enable */
  __IO uint32_t MCAN_ILS;                          /* !< (@ 0x00007058) MCAN Interrupt Line Select */
  __IO uint32_t MCAN_ILE;                          /* !< (@ 0x0000705C) MCAN Interrupt Line Enable */
       uint32_t RESERVED3[8];
  __IO uint32_t MCAN_GFC;                          /* !< (@ 0x00007080) MCAN Global Filter Configuration */
  __IO uint32_t MCAN_SIDFC;                        /* !< (@ 0x00007084) MCAN Standard ID Filter Configuration */
  __IO uint32_t MCAN_XIDFC;                        /* !< (@ 0x00007088) MCAN Extended ID Filter Configuration */
       uint32_t RESERVED4;
  __IO uint32_t MCAN_XIDAM;                        /* !< (@ 0x00007090) MCAN Extended ID and Mask */
  __I  uint32_t MCAN_HPMS;                         /* !< (@ 0x00007094) MCAN High Priority Message Status */
  __IO uint32_t MCAN_NDAT1;                        /* !< (@ 0x00007098) MCAN New Data 1 */
  __IO uint32_t MCAN_NDAT2;                        /* !< (@ 0x0000709C) MCAN New Data 2 */
  __IO uint32_t MCAN_RXF0C;                        /* !< (@ 0x000070A0) MCAN Rx FIFO 0 Configuration */
  __I  uint32_t MCAN_RXF0S;                        /* !< (@ 0x000070A4) MCAN Rx FIFO 0 Status */
  __IO uint32_t MCAN_RXF0A;                        /* !< (@ 0x000070A8) MCAN Rx FIFO 0 Acknowledge */
  __IO uint32_t MCAN_RXBC;                         /* !< (@ 0x000070AC) MCAN Rx Buffer Configuration */
  __IO uint32_t MCAN_RXF1C;                        /* !< (@ 0x000070B0) MCAN Rx FIFO 1 Configuration */
  __I  uint32_t MCAN_RXF1S;                        /* !< (@ 0x000070B4) MCAN Rx FIFO 1 Status */
  __IO uint32_t MCAN_RXF1A;                        /* !< (@ 0x000070B8) MCAN Rx FIFO 1 Acknowledge */
  __IO uint32_t MCAN_RXESC;                        /* !< (@ 0x000070BC) MCAN Rx Buffer / FIFO Element Size Configuration */
  __IO uint32_t MCAN_TXBC;                         /* !< (@ 0x000070C0) MCAN Tx Buffer Configuration */
  __I  uint32_t MCAN_TXFQS;                        /* !< (@ 0x000070C4) MCAN Tx FIFO / Queue Status */
  __IO uint32_t MCAN_TXESC;                        /* !< (@ 0x000070C8) MCAN Tx Buffer Element Size Configuration */
  __I  uint32_t MCAN_TXBRP;                        /* !< (@ 0x000070CC) MCAN Tx Buffer Request Pending */
  __IO uint32_t MCAN_TXBAR;                        /* !< (@ 0x000070D0) MCAN Tx Buffer Add Request */
  __IO uint32_t MCAN_TXBCR;                        /* !< (@ 0x000070D4) MCAN Tx Buffer Cancellation Request */
  __I  uint32_t MCAN_TXBTO;                        /* !< (@ 0x000070D8) MCAN Tx Buffer Transmission Occurred */
  __I  uint32_t MCAN_TXBCF;                        /* !< (@ 0x000070DC) MCAN Tx Buffer Cancellation Finished */
  __IO uint32_t MCAN_TXBTIE;                       /* !< (@ 0x000070E0) MCAN Tx Buffer Transmission Interrupt Enable */
  __IO uint32_t MCAN_TXBCIE;                       /* !< (@ 0x000070E4) MCAN Tx Buffer Cancellation Finished Interrupt
                                                      Enable */
       uint32_t RESERVED5[2];
  __IO uint32_t MCAN_TXEFC;                        /* !< (@ 0x000070F0) MCAN Tx Event FIFO Configuration */
  __I  uint32_t MCAN_TXEFS;                        /* !< (@ 0x000070F4) MCAN Tx Event FIFO Status */
  __IO uint32_t MCAN_TXEFA;                        /* !< (@ 0x000070F8) MCAN Tx Event FIFO Acknowledge */
} MCAN_MCAN_Regs;

/*@}*/ /* end of group MCAN_MCAN */

/** @addtogroup MCAN_MCANSS
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  __IO uint32_t PWREN;                             /* !< (@ 0x00006800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00006804) Reset Control */
       uint32_t RESERVED1[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00006814) Status Register */
       uint32_t RESERVED2[506];
  MCAN_MCAN_Regs  MCAN;                              /* !< (@ 0x00007000) */
       uint32_t RESERVED3[65];
  MCAN_TI_WRAPPER_Regs  TI_WRAPPER;                        /* !< (@ 0x00007200) */
} MCAN_MCANSS_Regs;

/*@}*/ /* end of group MCAN_MCANSS */

/** @addtogroup MCAN
  @{
*/

typedef struct {
       uint32_t RESERVED0[6144];
  MCAN_MCANSS_Regs  MCANSS;                            /* !< (@ 0x00006000) */
} MCAN_Regs;

/*@}*/ /* end of group MCAN */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* MCAN Register Control Bits
******************************************************************************/

/* MCAN_IIDX Bits */
/* MCAN_IIDX[STAT] Bits */
#define MCAN_IIDX_STAT_OFS                       (0)                             /* !< STAT Offset */
#define MCAN_IIDX_STAT_MASK                      ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define MCAN_IIDX_STAT_NO_INTR                   ((uint32_t)0x00000000U)         /* !< No interrupt pending. */
#define MCAN_IIDX_STAT_INTL0                     ((uint32_t)0x00000001U)         /* !< MCAN Interrupt Line 0 interrupt
                                                                                    pending. */
#define MCAN_IIDX_STAT_INTL1                     ((uint32_t)0x00000002U)         /* !< MCAN Interrupt Line 1 interrupt
                                                                                    pending. */
#define MCAN_IIDX_STAT_SEC                       ((uint32_t)0x00000003U)         /* !< Message RAM SEC (Single Error
                                                                                    Correction) interrupt pending. */
#define MCAN_IIDX_STAT_DED                       ((uint32_t)0x00000004U)         /* !< Message RAM DED (Double Error
                                                                                    Detection)  interrupt pending. */
#define MCAN_IIDX_STAT_EXT_TS_CNTR_OVFL          ((uint32_t)0x00000005U)         /* !< External Timestamp Counter Overflow
                                                                                    interrupt pending. */
#define MCAN_IIDX_STAT_WAKEUP                    ((uint32_t)0x00000006U)         /* !< Clock Stop Wake Up interrupt
                                                                                    pending. */

/* MCAN_IMASK Bits */
/* MCAN_IMASK[INTL0] Bits */
#define MCAN_IMASK_INTL0_OFS                     (0)                             /* !< INTL0 Offset */
#define MCAN_IMASK_INTL0_MASK                    ((uint32_t)0x00000001U)         /* !< MCAN Interrupt Line 0 mask. */
#define MCAN_IMASK_INTL0_CLR                     ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define MCAN_IMASK_INTL0_SET                     ((uint32_t)0x00000001U)         /* !< Set Interrrupt Mask */
/* MCAN_IMASK[INTL1] Bits */
#define MCAN_IMASK_INTL1_OFS                     (1)                             /* !< INTL1 Offset */
#define MCAN_IMASK_INTL1_MASK                    ((uint32_t)0x00000002U)         /* !< MCAN Interrupt Line 1 mask. */
#define MCAN_IMASK_INTL1_CLR                     ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define MCAN_IMASK_INTL1_SET                     ((uint32_t)0x00000002U)         /* !< Set Interrrupt Mask */
/* MCAN_IMASK[SEC] Bits */
#define MCAN_IMASK_SEC_OFS                       (2)                             /* !< SEC Offset */
#define MCAN_IMASK_SEC_MASK                      ((uint32_t)0x00000004U)         /* !< Message RAM SEC interrupt mask. */
#define MCAN_IMASK_SEC_CLR                       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define MCAN_IMASK_SEC_SET                       ((uint32_t)0x00000004U)         /* !< Set Interrrupt Mask */
/* MCAN_IMASK[DED] Bits */
#define MCAN_IMASK_DED_OFS                       (3)                             /* !< DED Offset */
#define MCAN_IMASK_DED_MASK                      ((uint32_t)0x00000008U)         /* !< Massage RAM DED interrupt mask. */
#define MCAN_IMASK_DED_CLR                       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define MCAN_IMASK_DED_SET                       ((uint32_t)0x00000008U)         /* !< Set Interrrupt Mask */
/* MCAN_IMASK[EXT_TS_CNTR_OVFL] Bits */
#define MCAN_IMASK_EXT_TS_CNTR_OVFL_OFS          (4)                             /* !< EXT_TS_CNTR_OVFL Offset */
#define MCAN_IMASK_EXT_TS_CNTR_OVFL_MASK         ((uint32_t)0x00000010U)         /* !< External Timestamp Counter Overflow
                                                                                    interrupt mask. */
#define MCAN_IMASK_EXT_TS_CNTR_OVFL_CLR          ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define MCAN_IMASK_EXT_TS_CNTR_OVFL_SET          ((uint32_t)0x00000010U)         /* !< Set Interrrupt Mask */
/* MCAN_IMASK[WAKEUP] Bits */
#define MCAN_IMASK_WAKEUP_OFS                    (5)                             /* !< WAKEUP Offset */
#define MCAN_IMASK_WAKEUP_MASK                   ((uint32_t)0x00000020U)         /* !< Clock Stop Wake Up interrupt mask. */
#define MCAN_IMASK_WAKEUP_CLR                    ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define MCAN_IMASK_WAKEUP_SET                    ((uint32_t)0x00000020U)         /* !< Set Interrrupt Mask */

/* MCAN_RIS Bits */
/* MCAN_RIS[INTL0] Bits */
#define MCAN_RIS_INTL0_OFS                       (0)                             /* !< INTL0 Offset */
#define MCAN_RIS_INTL0_MASK                      ((uint32_t)0x00000001U)         /* !< MCAN Interrupt Line 0. */
#define MCAN_RIS_INTL0_CLR                       ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_RIS_INTL0_SET                       ((uint32_t)0x00000001U)         /* !< Interrupt occured */
/* MCAN_RIS[INTL1] Bits */
#define MCAN_RIS_INTL1_OFS                       (1)                             /* !< INTL1 Offset */
#define MCAN_RIS_INTL1_MASK                      ((uint32_t)0x00000002U)         /* !< MCAN Interrupt Line 1. */
#define MCAN_RIS_INTL1_CLR                       ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_RIS_INTL1_SET                       ((uint32_t)0x00000002U)         /* !< Interrupt occured */
/* MCAN_RIS[SEC] Bits */
#define MCAN_RIS_SEC_OFS                         (2)                             /* !< SEC Offset */
#define MCAN_RIS_SEC_MASK                        ((uint32_t)0x00000004U)         /* !< Message RAM SEC interrupt. */
#define MCAN_RIS_SEC_CLR                         ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_RIS_SEC_SET                         ((uint32_t)0x00000004U)         /* !< Interrupt occured */
/* MCAN_RIS[DED] Bits */
#define MCAN_RIS_DED_OFS                         (3)                             /* !< DED Offset */
#define MCAN_RIS_DED_MASK                        ((uint32_t)0x00000008U)         /* !< Message RAM DED interrupt. */
#define MCAN_RIS_DED_CLR                         ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_RIS_DED_SET                         ((uint32_t)0x00000008U)         /* !< Interrupt occured */
/* MCAN_RIS[EXT_TS_CNTR_OVFL] Bits */
#define MCAN_RIS_EXT_TS_CNTR_OVFL_OFS            (4)                             /* !< EXT_TS_CNTR_OVFL Offset */
#define MCAN_RIS_EXT_TS_CNTR_OVFL_MASK           ((uint32_t)0x00000010U)         /* !< External Timestamp Counter Overflow
                                                                                    interrupt. */
#define MCAN_RIS_EXT_TS_CNTR_OVFL_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_RIS_EXT_TS_CNTR_OVFL_SET            ((uint32_t)0x00000010U)         /* !< Interrupt occured */
/* MCAN_RIS[WAKEUP] Bits */
#define MCAN_RIS_WAKEUP_OFS                      (5)                             /* !< WAKEUP Offset */
#define MCAN_RIS_WAKEUP_MASK                     ((uint32_t)0x00000020U)         /* !< Clock Stop Wake Up interrupt. */
#define MCAN_RIS_WAKEUP_CLR                      ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_RIS_WAKEUP_SET                      ((uint32_t)0x00000020U)         /* !< Interrupt occured */

/* MCAN_MIS Bits */
/* MCAN_MIS[INTL0] Bits */
#define MCAN_MIS_INTL0_OFS                       (0)                             /* !< INTL0 Offset */
#define MCAN_MIS_INTL0_MASK                      ((uint32_t)0x00000001U)         /* !< Masked MCAN Interrupt Line 0. */
#define MCAN_MIS_INTL0_CLR                       ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_MIS_INTL0_SET                       ((uint32_t)0x00000001U)         /* !< Interrupt occured */
/* MCAN_MIS[INTL1] Bits */
#define MCAN_MIS_INTL1_OFS                       (1)                             /* !< INTL1 Offset */
#define MCAN_MIS_INTL1_MASK                      ((uint32_t)0x00000002U)         /* !< Masked MCAN Interrupt Line 1. */
#define MCAN_MIS_INTL1_CLR                       ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_MIS_INTL1_SET                       ((uint32_t)0x00000002U)         /* !< Interrupt occured */
/* MCAN_MIS[SEC] Bits */
#define MCAN_MIS_SEC_OFS                         (2)                             /* !< SEC Offset */
#define MCAN_MIS_SEC_MASK                        ((uint32_t)0x00000004U)         /* !< Masked Message RAM SEC interrupt. */
#define MCAN_MIS_SEC_CLR                         ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_MIS_SEC_SET                         ((uint32_t)0x00000004U)         /* !< Interrupt occured */
/* MCAN_MIS[DED] Bits */
#define MCAN_MIS_DED_OFS                         (3)                             /* !< DED Offset */
#define MCAN_MIS_DED_MASK                        ((uint32_t)0x00000008U)         /* !< Masked Message RAM DED interrupt. */
#define MCAN_MIS_DED_CLR                         ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_MIS_DED_SET                         ((uint32_t)0x00000008U)         /* !< Interrupt occured */
/* MCAN_MIS[EXT_TS_CNTR_OVFL] Bits */
#define MCAN_MIS_EXT_TS_CNTR_OVFL_OFS            (4)                             /* !< EXT_TS_CNTR_OVFL Offset */
#define MCAN_MIS_EXT_TS_CNTR_OVFL_MASK           ((uint32_t)0x00000010U)         /* !< Masked External Timestamp Counter
                                                                                    Overflow interrupt. */
#define MCAN_MIS_EXT_TS_CNTR_OVFL_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_MIS_EXT_TS_CNTR_OVFL_SET            ((uint32_t)0x00000010U)         /* !< Interrupt occured */
/* MCAN_MIS[WAKEUP] Bits */
#define MCAN_MIS_WAKEUP_OFS                      (5)                             /* !< WAKEUP Offset */
#define MCAN_MIS_WAKEUP_MASK                     ((uint32_t)0x00000020U)         /* !< Masked Clock Stop Wake Up
                                                                                    interrupt. */
#define MCAN_MIS_WAKEUP_CLR                      ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define MCAN_MIS_WAKEUP_SET                      ((uint32_t)0x00000020U)         /* !< Interrupt occured */

/* MCAN_ISET Bits */
/* MCAN_ISET[INTL0] Bits */
#define MCAN_ISET_INTL0_OFS                      (0)                             /* !< INTL0 Offset */
#define MCAN_ISET_INTL0_MASK                     ((uint32_t)0x00000001U)         /* !< Set MCAN Interrupt Line 0. */
#define MCAN_ISET_INTL0_NO_EFFECT                ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ISET_INTL0_SET                      ((uint32_t)0x00000001U)         /* !< Set Interrupt */
/* MCAN_ISET[INTL1] Bits */
#define MCAN_ISET_INTL1_OFS                      (1)                             /* !< INTL1 Offset */
#define MCAN_ISET_INTL1_MASK                     ((uint32_t)0x00000002U)         /* !< Set MCAN Interrupt Line 1. */
#define MCAN_ISET_INTL1_NO_EFFECT                ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ISET_INTL1_SET                      ((uint32_t)0x00000002U)         /* !< Set Interrupt */
/* MCAN_ISET[SEC] Bits */
#define MCAN_ISET_SEC_OFS                        (2)                             /* !< SEC Offset */
#define MCAN_ISET_SEC_MASK                       ((uint32_t)0x00000004U)         /* !< Set Message RAM SEC interrupt. */
#define MCAN_ISET_SEC_NO_EFFECT                  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ISET_SEC_SET                        ((uint32_t)0x00000004U)         /* !< Set Interrupt */
/* MCAN_ISET[DED] Bits */
#define MCAN_ISET_DED_OFS                        (3)                             /* !< DED Offset */
#define MCAN_ISET_DED_MASK                       ((uint32_t)0x00000008U)         /* !< Set Message RAM DED interrupt. */
#define MCAN_ISET_DED_NO_EFFECT                  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ISET_DED_SET                        ((uint32_t)0x00000008U)         /* !< Set Interrupt */
/* MCAN_ISET[EXT_TS_CNTR_OVFL] Bits */
#define MCAN_ISET_EXT_TS_CNTR_OVFL_OFS           (4)                             /* !< EXT_TS_CNTR_OVFL Offset */
#define MCAN_ISET_EXT_TS_CNTR_OVFL_MASK          ((uint32_t)0x00000010U)         /* !< Set External Timestamp Counter
                                                                                    Overflow interrupt. */
#define MCAN_ISET_EXT_TS_CNTR_OVFL_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ISET_EXT_TS_CNTR_OVFL_SET           ((uint32_t)0x00000010U)         /* !< Set Interrupt */
/* MCAN_ISET[WAKEUP] Bits */
#define MCAN_ISET_WAKEUP_OFS                     (5)                             /* !< WAKEUP Offset */
#define MCAN_ISET_WAKEUP_MASK                    ((uint32_t)0x00000020U)         /* !< Set Clock Stop Wake Up interrupt. */
#define MCAN_ISET_WAKEUP_NO_EFFECT               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ISET_WAKEUP_SET                     ((uint32_t)0x00000020U)         /* !< Set Interrupt */

/* MCAN_ICLR Bits */
/* MCAN_ICLR[INTL0] Bits */
#define MCAN_ICLR_INTL0_OFS                      (0)                             /* !< INTL0 Offset */
#define MCAN_ICLR_INTL0_MASK                     ((uint32_t)0x00000001U)         /* !< Clear MCAN Interrupt Line 0. */
#define MCAN_ICLR_INTL0_NO_EFFECT                ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ICLR_INTL0_CLR                      ((uint32_t)0x00000001U)         /* !< Clear Interrupt */
/* MCAN_ICLR[INTL1] Bits */
#define MCAN_ICLR_INTL1_OFS                      (1)                             /* !< INTL1 Offset */
#define MCAN_ICLR_INTL1_MASK                     ((uint32_t)0x00000002U)         /* !< Clear MCAN Interrupt Line 1. */
#define MCAN_ICLR_INTL1_NO_EFFECT                ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ICLR_INTL1_CLR                      ((uint32_t)0x00000002U)         /* !< Clear Interrupt */
/* MCAN_ICLR[SEC] Bits */
#define MCAN_ICLR_SEC_OFS                        (2)                             /* !< SEC Offset */
#define MCAN_ICLR_SEC_MASK                       ((uint32_t)0x00000004U)         /* !< Clear Message RAM SEC interrupt. */
#define MCAN_ICLR_SEC_NO_EFFECT                  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ICLR_SEC_CLR                        ((uint32_t)0x00000004U)         /* !< Clear Interrupt */
/* MCAN_ICLR[DED] Bits */
#define MCAN_ICLR_DED_OFS                        (3)                             /* !< DED Offset */
#define MCAN_ICLR_DED_MASK                       ((uint32_t)0x00000008U)         /* !< Clear Message RAM DED interrupt. */
#define MCAN_ICLR_DED_NO_EFFECT                  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ICLR_DED_CLR                        ((uint32_t)0x00000008U)         /* !< Clear Interrupt */
/* MCAN_ICLR[EXT_TS_CNTR_OVFL] Bits */
#define MCAN_ICLR_EXT_TS_CNTR_OVFL_OFS           (4)                             /* !< EXT_TS_CNTR_OVFL Offset */
#define MCAN_ICLR_EXT_TS_CNTR_OVFL_MASK          ((uint32_t)0x00000010U)         /* !< Clear External Timestamp Counter
                                                                                    Overflow interrupt. */
#define MCAN_ICLR_EXT_TS_CNTR_OVFL_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ICLR_EXT_TS_CNTR_OVFL_CLR           ((uint32_t)0x00000010U)         /* !< Clear Interrupt */
/* MCAN_ICLR[WAKEUP] Bits */
#define MCAN_ICLR_WAKEUP_OFS                     (5)                             /* !< WAKEUP Offset */
#define MCAN_ICLR_WAKEUP_MASK                    ((uint32_t)0x00000020U)         /* !< Clear Clock Stop Wake Up interrupt. */
#define MCAN_ICLR_WAKEUP_NO_EFFECT               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_ICLR_WAKEUP_CLR                     ((uint32_t)0x00000020U)         /* !< Clear Interrupt */

/* MCAN_EVT_MODE Bits */
/* MCAN_EVT_MODE[INT0_CFG] Bits */
#define MCAN_EVT_MODE_INT0_CFG_OFS               (0)                             /* !< INT0_CFG Offset */
#define MCAN_EVT_MODE_INT0_CFG_MASK              ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT0] */
#define MCAN_EVT_MODE_INT0_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define MCAN_EVT_MODE_INT0_CFG_SOFTWARE          ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define MCAN_EVT_MODE_INT0_CFG_HARDWARE          ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* MCAN_DESC Bits */
/* MCAN_DESC[MINREV] Bits */
#define MCAN_DESC_MINREV_OFS                     (0)                             /* !< MINREV Offset */
#define MCAN_DESC_MINREV_MASK                    ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
#define MCAN_DESC_MINREV_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define MCAN_DESC_MINREV_MAXIMUM                 ((uint32_t)0x0000000FU)         /* !< Highest possible value */
/* MCAN_DESC[MAJREV] Bits */
#define MCAN_DESC_MAJREV_OFS                     (4)                             /* !< MAJREV Offset */
#define MCAN_DESC_MAJREV_MASK                    ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
#define MCAN_DESC_MAJREV_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define MCAN_DESC_MAJREV_MAXIMUM                 ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* MCAN_DESC[FEATUREVER] Bits */
#define MCAN_DESC_FEATUREVER_OFS                 (12)                            /* !< FEATUREVER Offset */
#define MCAN_DESC_FEATUREVER_MASK                ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
#define MCAN_DESC_FEATUREVER_VERSION_0           ((uint32_t)0x00000000U)         /* !< MCAN module with CAN-FD mode
                                                                                    enabled  <<Internal Note: This is an
                                                                                    in-IP paper spin variant. How does
                                                                                    this map to the SYS_MCAN_ENABLE_FD
                                                                                    choice value?>> */
#define MCAN_DESC_FEATUREVER_VERSION_1           ((uint32_t)0x00001000U)         /* !< MCAN module with CAN-FD mode
                                                                                    disabled  <<Internal Note: This is an
                                                                                    in-IP paper spin variant. How does
                                                                                    this map to the SYS_MCAN_ENABLE_FD
                                                                                    choice value?>> */
/* MCAN_DESC[MODULEID] Bits */
#define MCAN_DESC_MODULEID_OFS                   (16)                            /* !< MODULEID Offset */
#define MCAN_DESC_MODULEID_MASK                  ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */
#define MCAN_DESC_MODULEID_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define MCAN_DESC_MODULEID_MAXIMUM               ((uint32_t)0xFFFF0000U)         /* !< Highest possible value */

/* MCAN_CLKEN Bits */
/* MCAN_CLKEN[CLK_REQEN] Bits */
#define MCAN_CLKEN_CLK_REQEN_OFS                 (0)                             /* !< CLK_REQEN Offset */
#define MCAN_CLKEN_CLK_REQEN_MASK                ((uint32_t)0x00000001U)         /* !< MCAN functional and MCAN/MCANSS MMR
                                                                                    clock request enable bit */
#define MCAN_CLKEN_CLK_REQEN_CLR                 ((uint32_t)0x00000000U)         /* !< MCAN module functional clock and
                                                                                    Vbusp is not requested.  These clocks
                                                                                    are gated to the MCAN module. */
#define MCAN_CLKEN_CLK_REQEN_SET                 ((uint32_t)0x00000001U)         /* !< Setting this bit requests MCAN
                                                                                    module functional clock and Vbusp.
                                                                                    These clocks are not gated to MCAN
                                                                                    module. */

/* MCAN_CLKDIV Bits */
/* MCAN_CLKDIV[RATIO] Bits */
#define MCAN_CLKDIV_RATIO_OFS                    (0)                             /* !< RATIO Offset */
#define MCAN_CLKDIV_RATIO_MASK                   ((uint32_t)0x00000003U)         /* !< Clock divide ratio specification.
                                                                                    Enables configuring clock divide
                                                                                    settings for the MCAN functional
                                                                                    clock input to the MCAN-SS. */
#define MCAN_CLKDIV_RATIO_DIV_BY_1_              ((uint32_t)0x00000000U)         /* !< Divides input clock by 1 */
#define MCAN_CLKDIV_RATIO_DIV_BY_2_              ((uint32_t)0x00000001U)         /* !< Divides input clock by 2 */
#define MCAN_CLKDIV_RATIO_DIV_BY_4_              ((uint32_t)0x00000002U)         /* !< Divides input clock by 4 */
#define MCAN_CLKDIV_RATIO_DIV_BY_1_1             ((uint32_t)0x00000003U)         /* !< Divides input clock by 1 */

/* MCAN_CLKCTL Bits */
/* MCAN_CLKCTL[STOPREQ] Bits */
#define MCAN_CLKCTL_STOPREQ_OFS                  (0)                             /* !< STOPREQ Offset */
#define MCAN_CLKCTL_STOPREQ_MASK                 ((uint32_t)0x00000001U)         /* !< This bit is used to enable/disable
                                                                                    MCAN clock (both host clock and
                                                                                    functional clock) gating request.
                                                                                    Note: This bit can be reset by HW by
                                                                                    Clock-Stop Wake-up via CAN RX
                                                                                    Activity. See spec for more details. */
#define MCAN_CLKCTL_STOPREQ_DISABLE              ((uint32_t)0x00000000U)         /* !< Disable MCAN-SS clock stop request */
#define MCAN_CLKCTL_STOPREQ_ENABLE               ((uint32_t)0x00000001U)         /* !< Enable MCAN-SS clock stop request */
/* MCAN_CLKCTL[WAKEUP_INT_EN] Bits */
#define MCAN_CLKCTL_WAKEUP_INT_EN_OFS            (4)                             /* !< WAKEUP_INT_EN Offset */
#define MCAN_CLKCTL_WAKEUP_INT_EN_MASK           ((uint32_t)0x00000010U)         /* !< This bit contols enabling or
                                                                                    disabling the MCAN IP clock stop
                                                                                    wakeup interrupt (when
                                                                                    MCANSS_CTRL.WAKEUPREQEN wakeup
                                                                                    request is enabled to wakeup MCAN IP
                                                                                    upon CAN RXD activity) */
#define MCAN_CLKCTL_WAKEUP_INT_EN_DISABLE        ((uint32_t)0x00000000U)         /* !< Disable MCAN IP clock stop wakeup
                                                                                    interrupt */
#define MCAN_CLKCTL_WAKEUP_INT_EN_ENABLE         ((uint32_t)0x00000010U)         /* !< Enable MCAN IP clock stop wakeup
                                                                                    interrupt */
/* MCAN_CLKCTL[WKUP_GLTFLT_EN] Bits */
#define MCAN_CLKCTL_WKUP_GLTFLT_EN_OFS           (8)                             /* !< WKUP_GLTFLT_EN Offset */
#define MCAN_CLKCTL_WKUP_GLTFLT_EN_MASK          ((uint32_t)0x00000100U)         /* !< Setting this bit enables the glitch
                                                                                    filter on MCAN RXD input, which wakes
                                                                                    up the MCAN controller to exit clock
                                                                                    gating. */
#define MCAN_CLKCTL_WKUP_GLTFLT_EN_DISABLE       ((uint32_t)0x00000000U)         /* !< Disable glitch filter enable on RXD
                                                                                    input when MCAN is in clock stop mode
                                                                                    (waiting for event on RXD input for
                                                                                    clock stop wakeup). */
#define MCAN_CLKCTL_WKUP_GLTFLT_EN_ENABLE        ((uint32_t)0x00000100U)         /* !< Enable glitch filter enable on RXD
                                                                                    input when MCAN is in clock stop mode
                                                                                    (waiting for event on RXD input for
                                                                                    clock stop wakeup). */

/* MCAN_CLKSTS Bits */
/* MCAN_CLKSTS[CLKSTOP_ACKSTS] Bits */
#define MCAN_CLKSTS_CLKSTOP_ACKSTS_OFS           (0)                             /* !< CLKSTOP_ACKSTS Offset */
#define MCAN_CLKSTS_CLKSTOP_ACKSTS_MASK          ((uint32_t)0x00000001U)         /* !< Clock stop acknowledge status from
                                                                                    MCAN IP */
#define MCAN_CLKSTS_CLKSTOP_ACKSTS_RESET         ((uint32_t)0x00000000U)         /* !< No clock stop acknowledged. */
#define MCAN_CLKSTS_CLKSTOP_ACKSTS_SET           ((uint32_t)0x00000001U)         /* !< Clock stop has been acknowledged by
                                                                                    MCAN IP; MCAN-SS may be clock gated
                                                                                    by stopping both the CAN host and
                                                                                    functional clocks. */
/* MCAN_CLKSTS[STOPREQ_HW_OVR] Bits */
#define MCAN_CLKSTS_STOPREQ_HW_OVR_OFS           (4)                             /* !< STOPREQ_HW_OVR Offset */
#define MCAN_CLKSTS_STOPREQ_HW_OVR_MASK          ((uint32_t)0x00000010U)         /* !< MCANSS clock stop HW override
                                                                                    status bit.   This bit indicates when
                                                                                    the MCANSS_CLKCTL.STOPREQ bit has
                                                                                    been cleared by HW when a clock-stop
                                                                                    wake-up event via CAN RX activity is
                                                                                    triggered. */
#define MCAN_CLKSTS_STOPREQ_HW_OVR_RESET         ((uint32_t)0x00000000U)         /* !< MCANSS_CLKCTL.STOPREQ bit has not
                                                                                    been cleared by HW. */
#define MCAN_CLKSTS_STOPREQ_HW_OVR_SET           ((uint32_t)0x00000010U)         /* !< MCANSS_CLKCTL.STOPREQ bit has been
                                                                                    cleared by HW. */
/* MCAN_CLKSTS[CCLKDONE] Bits */
#define MCAN_CLKSTS_CCLKDONE_OFS                 (8)                             /* !< CCLKDONE Offset */
#define MCAN_CLKSTS_CCLKDONE_MASK                ((uint32_t)0x00000100U)         /* !< This bit indicates the status of
                                                                                    MCAN contoller clock request from
                                                                                    GPRCM. */
#define MCAN_CLKSTS_CCLKDONE_RESET               ((uint32_t)0x00000000U)         /* !< MCAN controller clock is not
                                                                                    available to the MCAN IP. */
#define MCAN_CLKSTS_CCLKDONE_SET                 ((uint32_t)0x00000100U)         /* !< MCAN controller clock is enabled
                                                                                    and available to the MCAN IP. */

/* MCAN_REV Bits */
/* MCAN_REV[REVMIN] Bits */
#define MCAN_REV_REVMIN_OFS                      (0)                             /* !< REVMIN Offset */
#define MCAN_REV_REVMIN_MASK                     ((uint32_t)0x0000003FU)         /* !< Minor Revision of the Error
                                                                                    Aggregator */
/* MCAN_REV[REVMAJ] Bits */
#define MCAN_REV_REVMAJ_OFS                      (8)                             /* !< REVMAJ Offset */
#define MCAN_REV_REVMAJ_MASK                     ((uint32_t)0x00000700U)         /* !< Major Revision of the Error
                                                                                    Aggregator */
/* MCAN_REV[MODULE_ID] Bits */
#define MCAN_REV_MODULE_ID_OFS                   (16)                            /* !< MODULE_ID Offset */
#define MCAN_REV_MODULE_ID_MASK                  ((uint32_t)0x0FFF0000U)         /* !< Module Identification Number */
/* MCAN_REV[SCHEME] Bits */
#define MCAN_REV_SCHEME_OFS                      (30)                            /* !< SCHEME Offset */
#define MCAN_REV_SCHEME_MASK                     ((uint32_t)0xC0000000U)         /* !< PID Register Scheme */

/* MCAN_VECTOR Bits */
/* MCAN_VECTOR[ECC_VECTOR] Bits */
#define MCAN_VECTOR_ECC_VECTOR_OFS               (0)                             /* !< ECC_VECTOR Offset */
#define MCAN_VECTOR_ECC_VECTOR_MASK              ((uint32_t)0x000007FFU)         /* !< ECC RAM ID. Each error detection
                                                                                    and correction (EDC) controller has a
                                                                                    bank of error registers (offsets 0x10
                                                                                    - 0x3B) associated with it. These
                                                                                    registers are accessed via an
                                                                                    internal serial bus (SVBUS). To
                                                                                    access them through the ECC
                                                                                    aggregator the controller ID desired
                                                                                    must be written to the ECC_VECTOR
                                                                                    field, together with the RD_SVBUS
                                                                                    trigger and RD_SVBUS_ADDRESS bit
                                                                                    field. This initiates the serial read
                                                                                    which consummates by setting the
                                                                                    RD_SVBUS_DONE bit. At this point the
                                                                                    addressed register may be read by a
                                                                                    normal CPU read of the appropriate
                                                                                    offset address.   0x000  Message RAM
                                                                                    ECC controller is selected   Others
                                                                                    Reserved (do not use)   Subsequent
                                                                                    writes through the SVBUS (offsets
                                                                                    0x10 - 0x3B) have a delayed
                                                                                    completion. To avoid conflicts,
                                                                                    perform a read back of a register
                                                                                    within this range after writing. */
/* MCAN_VECTOR[RD_SVBUS] Bits */
#define MCAN_VECTOR_RD_SVBUS_OFS                 (15)                            /* !< RD_SVBUS Offset */
#define MCAN_VECTOR_RD_SVBUS_MASK                ((uint32_t)0x00008000U)         /* !< Read Trigger */
/* MCAN_VECTOR[RD_SVBUS_ADDRESS] Bits */
#define MCAN_VECTOR_RD_SVBUS_ADDRESS_OFS         (16)                            /* !< RD_SVBUS_ADDRESS Offset */
#define MCAN_VECTOR_RD_SVBUS_ADDRESS_MASK        ((uint32_t)0x00FF0000U)         /* !< Read Address Offset */
/* MCAN_VECTOR[RD_SVBUS_DONE] Bits */
#define MCAN_VECTOR_RD_SVBUS_DONE_OFS            (24)                            /* !< RD_SVBUS_DONE Offset */
#define MCAN_VECTOR_RD_SVBUS_DONE_MASK           ((uint32_t)0x01000000U)         /* !< Read Completion Flag */

/* MCAN_TI_WRAPPER_PROCESSORS_ECC_REGS_STAT Bits */
/* MCAN_TI_WRAPPER_PROCESSORS_ECC_REGS_STAT[NUM_RAMS] Bits */
#define MCAN_TI_WRAPPER_PROCESSORS_ECC_REGS_STAT_NUM_RAMS_OFS (0)                             /* !< NUM_RAMS Offset */
#define MCAN_TI_WRAPPER_PROCESSORS_ECC_REGS_STAT_NUM_RAMS_MASK ((uint32_t)0x000007FFU)         /* !< Number of RAMs. Number of ECC RAMs
                                                                                    serviced by the aggregator. */

/* MCAN_WRAP_REV Bits */
/* MCAN_WRAP_REV[REVMIN] Bits */
#define MCAN_WRAP_REV_REVMIN_OFS                 (0)                             /* !< REVMIN Offset */
#define MCAN_WRAP_REV_REVMIN_MASK                ((uint32_t)0x0000003FU)         /* !< Minor Revision of the Error
                                                                                    Aggregator */
/* MCAN_WRAP_REV[REVMAJ] Bits */
#define MCAN_WRAP_REV_REVMAJ_OFS                 (8)                             /* !< REVMAJ Offset */
#define MCAN_WRAP_REV_REVMAJ_MASK                ((uint32_t)0x00000700U)         /* !< Major Revision of the Error
                                                                                    Aggregator */
/* MCAN_WRAP_REV[MODULE_ID] Bits */
#define MCAN_WRAP_REV_MODULE_ID_OFS              (16)                            /* !< MODULE_ID Offset */
#define MCAN_WRAP_REV_MODULE_ID_MASK             ((uint32_t)0x0FFF0000U)         /* !< Module Identification Number */
/* MCAN_WRAP_REV[SCHEME] Bits */
#define MCAN_WRAP_REV_SCHEME_OFS                 (30)                            /* !< SCHEME Offset */
#define MCAN_WRAP_REV_SCHEME_MASK                ((uint32_t)0xC0000000U)         /* !< PID Register Scheme */

/* MCAN_TI_WRAPPER_ECC_REGS_CTRL Bits */
/* MCAN_TI_WRAPPER_ECC_REGS_CTRL[ECC_ENABLE] Bits */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_ECC_ENABLE_OFS (0)                             /* !< ECC_ENABLE Offset */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_ECC_ENABLE_MASK ((uint32_t)0x00000001U)         /* !< Enable ECC Generation */
/* MCAN_TI_WRAPPER_ECC_REGS_CTRL[ECC_CHECK] Bits */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_ECC_CHECK_OFS (1)                             /* !< ECC_CHECK Offset */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_ECC_CHECK_MASK ((uint32_t)0x00000002U)         /* !< Enable ECC Check. ECC is completely
                                                                                    bypassed if both ECC_ENABLE and
                                                                                    ECC_CHECK are '0'. */
/* MCAN_TI_WRAPPER_ECC_REGS_CTRL[ENABLE_RMW] Bits */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_ENABLE_RMW_OFS (2)                             /* !< ENABLE_RMW Offset */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_ENABLE_RMW_MASK ((uint32_t)0x00000004U)         /* !< Enable read-modify-write on partial
                                                                                    word writes */
/* MCAN_TI_WRAPPER_ECC_REGS_CTRL[FORCE_SEC] Bits */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_FORCE_SEC_OFS (3)                             /* !< FORCE_SEC Offset */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_FORCE_SEC_MASK ((uint32_t)0x00000008U)         /* !< Force single-bit error. Cleared on
                                                                                    a writeback or the cycle following
                                                                                    the error if ERROR_ONCE is asserted.
                                                                                    For write through mode, this applies
                                                                                    to writes as well as reads.
                                                                                    MCANERR_ERR_CTRL1 and
                                                                                    MCANERR_ERR_CTRL2 should be
                                                                                    configured prior to setting this bit. */
/* MCAN_TI_WRAPPER_ECC_REGS_CTRL[FORCE_DED] Bits */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_FORCE_DED_OFS (4)                             /* !< FORCE_DED Offset */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_FORCE_DED_MASK ((uint32_t)0x00000010U)         /* !< Force double-bit error. Cleared the
                                                                                    cycle following the error if
                                                                                    ERROR_ONCE is asserted. For write
                                                                                    through mode, this applies to writes
                                                                                    as well as reads. MCANERR_ERR_CTRL1
                                                                                    and MCANERR_ERR_CTRL2 should be
                                                                                    configured prior to setting this bit. */
/* MCAN_TI_WRAPPER_ECC_REGS_CTRL[FORCE_N_ROW] Bits */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_FORCE_N_ROW_OFS (5)                             /* !< FORCE_N_ROW Offset */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_FORCE_N_ROW_MASK ((uint32_t)0x00000020U)         /* !< Enable single/double-bit error on
                                                                                    the next RAM read, regardless of the
                                                                                    MCANERR_ERR_CTRL1.ECC_ROW setting.
                                                                                    For write through mode, this applies
                                                                                    to writes as well as reads. */
/* MCAN_TI_WRAPPER_ECC_REGS_CTRL[ERROR_ONCE] Bits */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_ERROR_ONCE_OFS (6)                             /* !< ERROR_ONCE Offset */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_ERROR_ONCE_MASK ((uint32_t)0x00000040U)         /* !< If this bit is set, the
                                                                                    FORCE_SEC/FORCE_DED will inject an
                                                                                    error to the specified row only once.
                                                                                    The FORCE_SEC bit will be cleared
                                                                                    once a writeback happens. If
                                                                                    writeback is not enabled, this error
                                                                                    will be cleared the cycle following
                                                                                    the read when the data is corrected.
                                                                                    For double-bit errors, the FORCE_DED
                                                                                    bit will be cleared the cycle
                                                                                    following the double-bit error. Any
                                                                                    subsequent reads will not force an
                                                                                    error. */
/* MCAN_TI_WRAPPER_ECC_REGS_CTRL[CHECK_SVBUS_TIMEOUT] Bits */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_CHECK_SVBUS_TIMEOUT_OFS (8)                             /* !< CHECK_SVBUS_TIMEOUT Offset */
#define MCAN_TI_WRAPPER_ECC_REGS_CTRL_CHECK_SVBUS_TIMEOUT_MASK ((uint32_t)0x00000100U)         /* !< Enables Serial VBUS timeout
                                                                                    mechanism */

/* MCAN_ERR_CTRL1 Bits */
/* MCAN_ERR_CTRL1[ECC_ROW] Bits */
#define MCAN_ERR_CTRL1_ECC_ROW_OFS               (0)                             /* !< ECC_ROW Offset */
#define MCAN_ERR_CTRL1_ECC_ROW_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< Row address where FORCE_SEC or
                                                                                    FORCE_DED needs to be applied. This
                                                                                    is ignored if FORCE_N_ROW is set. */

/* MCAN_ERR_CTRL2 Bits */
/* MCAN_ERR_CTRL2[ECC_BIT1] Bits */
#define MCAN_ERR_CTRL2_ECC_BIT1_OFS              (0)                             /* !< ECC_BIT1 Offset */
#define MCAN_ERR_CTRL2_ECC_BIT1_MASK             ((uint32_t)0x0000FFFFU)         /* !< Column/Data bit that needs to be
                                                                                    flipped when FORCE_SEC or FORCE_DED
                                                                                    is set */
/* MCAN_ERR_CTRL2[ECC_BIT2] Bits */
#define MCAN_ERR_CTRL2_ECC_BIT2_OFS              (16)                            /* !< ECC_BIT2 Offset */
#define MCAN_ERR_CTRL2_ECC_BIT2_MASK             ((uint32_t)0xFFFF0000U)         /* !< Second column/data bit that needs
                                                                                    to be flipped when FORCE_DED is set */

/* MCAN_ERR_STAT1 Bits */
/* MCAN_ERR_STAT1[ECC_SEC] Bits */
#define MCAN_ERR_STAT1_ECC_SEC_OFS               (0)                             /* !< ECC_SEC Offset */
#define MCAN_ERR_STAT1_ECC_SEC_MASK              ((uint32_t)0x00000003U)         /* !< Single Bit Error Corrected Status.
                                                                                    A 2-bit saturating counter of the
                                                                                    number of SEC errors that have
                                                                                    occurred since last cleared.     0
                                                                                    No single-bit error detected   1  One
                                                                                    single-bit error was detected and
                                                                                    corrected   2  Two single-bit errors
                                                                                    were detected and corrected   3
                                                                                    Three single-bit errors were detected
                                                                                    and corrected   A write of a non-zero
                                                                                    value to this bit field increments it
                                                                                    by the value provided. */
/* MCAN_ERR_STAT1[ECC_DED] Bits */
#define MCAN_ERR_STAT1_ECC_DED_OFS               (2)                             /* !< ECC_DED Offset */
#define MCAN_ERR_STAT1_ECC_DED_MASK              ((uint32_t)0x0000000CU)         /* !< Double Bit Error Detected Status. A
                                                                                    2-bit saturating counter of the
                                                                                    number of DED errors that have
                                                                                    occurred since last cleared.     0
                                                                                    No double-bit error detected   1  One
                                                                                    double-bit error was detected   2
                                                                                    Two double-bit errors were detected
                                                                                    3  Three double-bit errors were
                                                                                    detected   A write of a non-zero
                                                                                    value to this bit field increments it
                                                                                    by the value provided. */
/* MCAN_ERR_STAT1[ECC_OTHER] Bits */
#define MCAN_ERR_STAT1_ECC_OTHER_OFS             (4)                             /* !< ECC_OTHER Offset */
#define MCAN_ERR_STAT1_ECC_OTHER_MASK            ((uint32_t)0x00000010U)         /* !< SEC While Writeback Error Status
                                                                                    0  No SEC error while writeback
                                                                                    pending   1  Indicates that
                                                                                    successive single-bit errors have
                                                                                    occurred while a writeback is still
                                                                                    pending */
/* MCAN_ERR_STAT1[CTRL_REG_ERROR] Bits */
#define MCAN_ERR_STAT1_CTRL_REG_ERROR_OFS        (7)                             /* !< CTRL_REG_ERROR Offset */
#define MCAN_ERR_STAT1_CTRL_REG_ERROR_MASK       ((uint32_t)0x00000080U)         /* !< Control Register Error. A bit field
                                                                                    in the control register is in an
                                                                                    ambiguous state. This means that the
                                                                                    redundancy registers have detected a
                                                                                    state where not all values are the
                                                                                    same and has defaulted to the reset
                                                                                    state. S/W needs to re-write these
                                                                                    registers to a known state. A write
                                                                                    of 1 will set this interrupt flag. */
/* MCAN_ERR_STAT1[CLR_ECC_SEC] Bits */
#define MCAN_ERR_STAT1_CLR_ECC_SEC_OFS           (8)                             /* !< CLR_ECC_SEC Offset */
#define MCAN_ERR_STAT1_CLR_ECC_SEC_MASK          ((uint32_t)0x00000300U)         /* !< Clear ECC_SEC. A write of a
                                                                                    non-zero value to this bit field
                                                                                    decrements the ECC_SEC bit field by
                                                                                    the value provided. */
/* MCAN_ERR_STAT1[CLR_ECC_DED] Bits */
#define MCAN_ERR_STAT1_CLR_ECC_DED_OFS           (10)                            /* !< CLR_ECC_DED Offset */
#define MCAN_ERR_STAT1_CLR_ECC_DED_MASK          ((uint32_t)0x00000C00U)         /* !< Clear ECC_DED. A write of a
                                                                                    non-zero value to this bit field
                                                                                    decrements the ECC_DED bit field by
                                                                                    the value provided. */
/* MCAN_ERR_STAT1[CLR_ECC_OTHER] Bits */
#define MCAN_ERR_STAT1_CLR_ECC_OTHER_OFS         (12)                            /* !< CLR_ECC_OTHER Offset */
#define MCAN_ERR_STAT1_CLR_ECC_OTHER_MASK        ((uint32_t)0x00001000U)         /* !< Writing a '1' clears the ECC_OTHER
                                                                                    bit. */
/* MCAN_ERR_STAT1[CLR_CTRL_REG_ERROR] Bits */
#define MCAN_ERR_STAT1_CLR_CTRL_REG_ERROR_OFS    (15)                            /* !< CLR_CTRL_REG_ERROR Offset */
#define MCAN_ERR_STAT1_CLR_CTRL_REG_ERROR_MASK   ((uint32_t)0x00008000U)         /* !< Writing a '1' clears the
                                                                                    CTRL_REG_ERROR bit */
/* MCAN_ERR_STAT1[ECC_BIT1] Bits */
#define MCAN_ERR_STAT1_ECC_BIT1_OFS              (16)                            /* !< ECC_BIT1 Offset */
#define MCAN_ERR_STAT1_ECC_BIT1_MASK             ((uint32_t)0xFFFF0000U)         /* !< ECC Error Bit Position. Indicates
                                                                                    the bit position in the RAM data that
                                                                                    is in error on an SEC error. Only
                                                                                    valid on an SEC error.   0  Bit 0 is
                                                                                    in error   1  Bit 1 is in error   2
                                                                                    Bit 2 is in error   3  Bit 3 is in
                                                                                    error   ...   31 Bit 31 is in error
                                                                                    >32 Invalid */

/* MCAN_ERR_STAT2 Bits */
/* MCAN_ERR_STAT2[ECC_ROW] Bits */
#define MCAN_ERR_STAT2_ECC_ROW_OFS               (0)                             /* !< ECC_ROW Offset */
#define MCAN_ERR_STAT2_ECC_ROW_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< Indicates the row address where the
                                                                                    single or double-bit error occurred.
                                                                                    This value is address offset/4. */

/* MCAN_ERR_STAT3 Bits */
/* MCAN_ERR_STAT3[WB_PEND] Bits */
#define MCAN_ERR_STAT3_WB_PEND_OFS               (0)                             /* !< WB_PEND Offset */
#define MCAN_ERR_STAT3_WB_PEND_MASK              ((uint32_t)0x00000001U)         /* !< Delayed Write Back Pending Status
                                                                                    0  No write back pending   1  An ECC
                                                                                    data correction write back is pending */
/* MCAN_ERR_STAT3[SVBUS_TIMEOUT] Bits */
#define MCAN_ERR_STAT3_SVBUS_TIMEOUT_OFS         (1)                             /* !< SVBUS_TIMEOUT Offset */
#define MCAN_ERR_STAT3_SVBUS_TIMEOUT_MASK        ((uint32_t)0x00000002U)         /* !< Serial VBUS Timeout Flag. Write 1
                                                                                    to set. */
/* MCAN_ERR_STAT3[CLR_SVBUS_TIMEOUT] Bits */
#define MCAN_ERR_STAT3_CLR_SVBUS_TIMEOUT_OFS     (9)                             /* !< CLR_SVBUS_TIMEOUT Offset */
#define MCAN_ERR_STAT3_CLR_SVBUS_TIMEOUT_MASK    ((uint32_t)0x00000200U)         /* !< Write 1 to clear the Serial VBUS
                                                                                    Timeout Flag */

/* MCAN_SEC_EOI Bits */
/* MCAN_SEC_EOI[EOI_WR] Bits */
#define MCAN_SEC_EOI_EOI_WR_OFS                  (0)                             /* !< EOI_WR Offset */
#define MCAN_SEC_EOI_EOI_WR_MASK                 ((uint32_t)0x00000001U)         /* !< Write to this register indicates
                                                                                    that software has acknowledged the
                                                                                    pending interrupt and the next
                                                                                    interrupt can be sent to the host.
                                                                                    Note that a write to the
                                                                                    MCANERR_ERR_STAT1.CLR_ECC_SEC goes
                                                                                    through the SVBUS and has a delayed
                                                                                    completion. To avoid an additional
                                                                                    interrupt, read the MCANERR_ERR_STAT1
                                                                                    register back prior to writing to
                                                                                    this bit field. */

/* MCAN_SEC_STATUS Bits */
/* MCAN_SEC_STATUS[MSGMEM_PEND] Bits */
#define MCAN_SEC_STATUS_MSGMEM_PEND_OFS          (0)                             /* !< MSGMEM_PEND Offset */
#define MCAN_SEC_STATUS_MSGMEM_PEND_MASK         ((uint32_t)0x00000001U)         /* !< Message RAM SEC Interrupt Pending
                                                                                    0  No SEC interrupt is pending   1
                                                                                    SEC interrupt is pending */

/* MCAN_SEC_ENABLE_SET Bits */
/* MCAN_SEC_ENABLE_SET[MSGMEM_ENABLE_SET] Bits */
#define MCAN_SEC_ENABLE_SET_MSGMEM_ENABLE_SET_OFS (0)                             /* !< MSGMEM_ENABLE_SET Offset */
#define MCAN_SEC_ENABLE_SET_MSGMEM_ENABLE_SET_MASK ((uint32_t)0x00000001U)         /* !< Message RAM SEC Interrupt Pending
                                                                                    Enable Set. Writing a 1 to this bit
                                                                                    enables the Message RAM SEC error
                                                                                    interrupts. Writing a 0 has no
                                                                                    effect. Reads return the
                                                                                    corresponding enable bit's current
                                                                                    value. */

/* MCAN_SEC_ENABLE_CLR Bits */
/* MCAN_SEC_ENABLE_CLR[MSGMEM_ENABLE_CLR] Bits */
#define MCAN_SEC_ENABLE_CLR_MSGMEM_ENABLE_CLR_OFS (0)                             /* !< MSGMEM_ENABLE_CLR Offset */
#define MCAN_SEC_ENABLE_CLR_MSGMEM_ENABLE_CLR_MASK ((uint32_t)0x00000001U)         /* !< Message RAM SEC Interrupt Pending
                                                                                    Enable Clear. Writing a 1 to this bit
                                                                                    disables the Message RAM SEC error
                                                                                    interrupts. Writing a 0 has no
                                                                                    effect. Reads return the
                                                                                    corresponding enable bit's current
                                                                                    value. */

/* MCAN_DED_EOI Bits */
/* MCAN_DED_EOI[EOI_WR] Bits */
#define MCAN_DED_EOI_EOI_WR_OFS                  (0)                             /* !< EOI_WR Offset */
#define MCAN_DED_EOI_EOI_WR_MASK                 ((uint32_t)0x00000001U)         /* !< Write to this register indicates
                                                                                    that software has acknowledged the
                                                                                    pending interrupt and the next
                                                                                    interrupt can be sent to the host.
                                                                                    Note that a write to the
                                                                                    MCANERR_ERR_STAT1.CLR_ECC_DED goes
                                                                                    through the SVBUS and has a delayed
                                                                                    completion. To avoid an additional
                                                                                    interrupt, read the MCANERR_ERR_STAT1
                                                                                    register back prior to writing to
                                                                                    this bit field. */

/* MCAN_DED_STATUS Bits */
/* MCAN_DED_STATUS[MSGMEM_PEND] Bits */
#define MCAN_DED_STATUS_MSGMEM_PEND_OFS          (0)                             /* !< MSGMEM_PEND Offset */
#define MCAN_DED_STATUS_MSGMEM_PEND_MASK         ((uint32_t)0x00000001U)         /* !< Message RAM DED Interrupt Pending
                                                                                    0  No DED interrupt is pending   1
                                                                                    DED interrupt is pending */

/* MCAN_DED_ENABLE_SET Bits */
/* MCAN_DED_ENABLE_SET[MSGMEM_ENABLE_SET] Bits */
#define MCAN_DED_ENABLE_SET_MSGMEM_ENABLE_SET_OFS (0)                             /* !< MSGMEM_ENABLE_SET Offset */
#define MCAN_DED_ENABLE_SET_MSGMEM_ENABLE_SET_MASK ((uint32_t)0x00000001U)         /* !< Message RAM DED Interrupt Pending
                                                                                    Enable Set. Writing a 1 to this bit
                                                                                    enables the Message RAM DED error
                                                                                    interrupts. Writing a 0 has no
                                                                                    effect. Reads return the
                                                                                    corresponding enable bit's current
                                                                                    value. */

/* MCAN_DED_ENABLE_CLR Bits */
/* MCAN_DED_ENABLE_CLR[MSGMEM_ENABLE_CLR] Bits */
#define MCAN_DED_ENABLE_CLR_MSGMEM_ENABLE_CLR_OFS (0)                             /* !< MSGMEM_ENABLE_CLR Offset */
#define MCAN_DED_ENABLE_CLR_MSGMEM_ENABLE_CLR_MASK ((uint32_t)0x00000001U)         /* !< Message RAM DED Interrupt Pending
                                                                                    Enable Clear. Writing a 1 to this bit
                                                                                    disables the Message RAM DED error
                                                                                    interrupts. Writing a 0 has no
                                                                                    effect. Reads return the
                                                                                    corresponding enable bit's current
                                                                                    value. */

/* MCAN_AGGR_ENABLE_SET Bits */
/* MCAN_AGGR_ENABLE_SET[ENABLE_PARITY_SET] Bits */
#define MCAN_AGGR_ENABLE_SET_ENABLE_PARITY_SET_OFS (0)                             /* !< ENABLE_PARITY_SET Offset */
#define MCAN_AGGR_ENABLE_SET_ENABLE_PARITY_SET_MASK ((uint32_t)0x00000001U)         /* !< Write 1 to enable parity errors.
                                                                                    Reads return the corresponding enable
                                                                                    bit's current value. */
/* MCAN_AGGR_ENABLE_SET[ENABLE_TIMEOUT_SET] Bits */
#define MCAN_AGGR_ENABLE_SET_ENABLE_TIMEOUT_SET_OFS (1)                             /* !< ENABLE_TIMEOUT_SET Offset */
#define MCAN_AGGR_ENABLE_SET_ENABLE_TIMEOUT_SET_MASK ((uint32_t)0x00000002U)         /* !< Write 1 to enable timeout errors.
                                                                                    Reads return the corresponding enable
                                                                                    bit's current value. */

/* MCAN_AGGR_ENABLE_CLR Bits */
/* MCAN_AGGR_ENABLE_CLR[ENABLE_PARITY_CLR] Bits */
#define MCAN_AGGR_ENABLE_CLR_ENABLE_PARITY_CLR_OFS (0)                             /* !< ENABLE_PARITY_CLR Offset */
#define MCAN_AGGR_ENABLE_CLR_ENABLE_PARITY_CLR_MASK ((uint32_t)0x00000001U)         /* !< Write 1 to disable parity errors.
                                                                                    Reads return the corresponding enable
                                                                                    bit's current value. */
/* MCAN_AGGR_ENABLE_CLR[ENABLE_TIMEOUT_CLR] Bits */
#define MCAN_AGGR_ENABLE_CLR_ENABLE_TIMEOUT_CLR_OFS (1)                             /* !< ENABLE_TIMEOUT_CLR Offset */
#define MCAN_AGGR_ENABLE_CLR_ENABLE_TIMEOUT_CLR_MASK ((uint32_t)0x00000002U)         /* !< Write 1 to disable timeout errors.
                                                                                    Reads return the corresponding enable
                                                                                    bit's current value. */

/* MCAN_AGGR_STATUS_SET Bits */
/* MCAN_AGGR_STATUS_SET[AGGR_PARITY_ERR] Bits */
#define MCAN_AGGR_STATUS_SET_AGGR_PARITY_ERR_OFS (0)                             /* !< AGGR_PARITY_ERR Offset */
#define MCAN_AGGR_STATUS_SET_AGGR_PARITY_ERR_MASK ((uint32_t)0x00000003U)         /* !< Aggregator Parity Error Status
                                                                                    2-bit saturating counter of the
                                                                                    number of parity errors that have
                                                                                    occurred since last cleared.   0  No
                                                                                    parity errors have occurred   1  One
                                                                                    parity error has occurred   2  Two
                                                                                    parity errors have occurred   3
                                                                                    Three parity errors have occurred   A
                                                                                    write of a non-zero value to this bit
                                                                                    field increments it by the value
                                                                                    provided. */
/* MCAN_AGGR_STATUS_SET[SVBUS_TIMEOUT] Bits */
#define MCAN_AGGR_STATUS_SET_SVBUS_TIMEOUT_OFS   (2)                             /* !< SVBUS_TIMEOUT Offset */
#define MCAN_AGGR_STATUS_SET_SVBUS_TIMEOUT_MASK  ((uint32_t)0x0000000CU)         /* !< Aggregator Serial VBUS Timeout
                                                                                    Error Status   2-bit saturating
                                                                                    counter of the number of SVBUS
                                                                                    timeout errors that have occurred
                                                                                    since last cleared.   0  No timeout
                                                                                    errors have occurred   1  One timeout
                                                                                    error has occurred   2  Two timeout
                                                                                    errors have occurred   3  Three
                                                                                    timeout errors have occurred   A
                                                                                    write of a non-zero value to this bit
                                                                                    field increments it by the value
                                                                                    provided. */

/* MCAN_AGGR_STATUS_CLR Bits */
/* MCAN_AGGR_STATUS_CLR[AGGR_PARITY_ERR] Bits */
#define MCAN_AGGR_STATUS_CLR_AGGR_PARITY_ERR_OFS (0)                             /* !< AGGR_PARITY_ERR Offset */
#define MCAN_AGGR_STATUS_CLR_AGGR_PARITY_ERR_MASK ((uint32_t)0x00000003U)         /* !< Aggregator Parity Error Status
                                                                                    2-bit saturating counter of the
                                                                                    number of parity errors that have
                                                                                    occurred since last cleared.   0  No
                                                                                    parity errors have occurred   1  One
                                                                                    parity error has occurred   2  Two
                                                                                    parity errors have occurred   3
                                                                                    Three parity errors have occurred   A
                                                                                    write of a non-zero value to this bit
                                                                                    field decrements it by the value
                                                                                    provided. */
/* MCAN_AGGR_STATUS_CLR[SVBUS_TIMEOUT] Bits */
#define MCAN_AGGR_STATUS_CLR_SVBUS_TIMEOUT_OFS   (2)                             /* !< SVBUS_TIMEOUT Offset */
#define MCAN_AGGR_STATUS_CLR_SVBUS_TIMEOUT_MASK  ((uint32_t)0x0000000CU)         /* !< Aggregator Serial VBUS Timeout
                                                                                    Error Status   2-bit saturating
                                                                                    counter of the number of SVBUS
                                                                                    timeout errors that have occurred
                                                                                    since last cleared.   0  No timeout
                                                                                    errors have occurred   1  One timeout
                                                                                    error has occurred   2  Two timeout
                                                                                    errors have occurred   3  Three
                                                                                    timeout errors have occurred   A
                                                                                    write of a non-zero value to this bit
                                                                                    field decrements it by the value
                                                                                    provided. */

/* MCAN_PID Bits */
/* MCAN_PID[MINOR] Bits */
#define MCAN_PID_MINOR_OFS                       (0)                             /* !< MINOR Offset */
#define MCAN_PID_MINOR_MASK                      ((uint32_t)0x0000003FU)         /* !< Minor Revision of the MCAN
                                                                                    Subsystem */
/* MCAN_PID[MAJOR] Bits */
#define MCAN_PID_MAJOR_OFS                       (8)                             /* !< MAJOR Offset */
#define MCAN_PID_MAJOR_MASK                      ((uint32_t)0x00000700U)         /* !< Major Revision of the MCAN
                                                                                    Subsystem */
/* MCAN_PID[MODULE_ID] Bits */
#define MCAN_PID_MODULE_ID_OFS                   (16)                            /* !< MODULE_ID Offset */
#define MCAN_PID_MODULE_ID_MASK                  ((uint32_t)0x0FFF0000U)         /* !< Module Identification Number */
/* MCAN_PID[SCHEME] Bits */
#define MCAN_PID_SCHEME_OFS                      (30)                            /* !< SCHEME Offset */
#define MCAN_PID_SCHEME_MASK                     ((uint32_t)0xC0000000U)         /* !< PID Register Scheme */

/* MCAN_TI_WRAPPER_REGS_CTRL Bits */
/* MCAN_TI_WRAPPER_REGS_CTRL[DBGSUSP_FREE] Bits */
#define MCAN_TI_WRAPPER_REGS_CTRL_DBGSUSP_FREE_OFS (3)                             /* !< DBGSUSP_FREE Offset */
#define MCAN_TI_WRAPPER_REGS_CTRL_DBGSUSP_FREE_MASK ((uint32_t)0x00000008U)         /* !< Debug Suspend Free Bit. Enables
                                                                                    debug suspend.   0  Disable debug
                                                                                    suspend   1  Enable debug suspend */
/* MCAN_TI_WRAPPER_REGS_CTRL[WAKEUPREQEN] Bits */
#define MCAN_TI_WRAPPER_REGS_CTRL_WAKEUPREQEN_OFS (4)                             /* !< WAKEUPREQEN Offset */
#define MCAN_TI_WRAPPER_REGS_CTRL_WAKEUPREQEN_MASK ((uint32_t)0x00000010U)         /* !< Wakeup Request Enable. Enables the
                                                                                    MCANSS to wakeup on CAN RXD activity.
                                                                                    0  Disable wakeup request   1
                                                                                    Enables wakeup request */
/* MCAN_TI_WRAPPER_REGS_CTRL[AUTOWAKEUP] Bits */
#define MCAN_TI_WRAPPER_REGS_CTRL_AUTOWAKEUP_OFS (5)                             /* !< AUTOWAKEUP Offset */
#define MCAN_TI_WRAPPER_REGS_CTRL_AUTOWAKEUP_MASK ((uint32_t)0x00000020U)         /* !< Automatic Wakeup Enable. Enables
                                                                                    the MCANSS to automatically clear the
                                                                                    MCAN CCCR.INIT bit, fully waking the
                                                                                    MCAN up, on an enabled wakeup
                                                                                    request.   0  Disable the automatic
                                                                                    write to CCCR.INIT   1  Enable the
                                                                                    automatic write to CCCR.INIT */
/* MCAN_TI_WRAPPER_REGS_CTRL[EXT_TS_CNTR_EN] Bits */
#define MCAN_TI_WRAPPER_REGS_CTRL_EXT_TS_CNTR_EN_OFS (6)                             /* !< EXT_TS_CNTR_EN Offset */
#define MCAN_TI_WRAPPER_REGS_CTRL_EXT_TS_CNTR_EN_MASK ((uint32_t)0x00000040U)         /* !< External Timestamp Counter Enable.
                                                                                    0  External timestamp counter
                                                                                    disabled   1  External timestamp
                                                                                    counter enabled */

/* MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT Bits */
/* MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT[RESET] Bits */
#define MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT_RESET_OFS (0)                             /* !< RESET Offset */
#define MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT_RESET_MASK ((uint32_t)0x00000001U)         /* !< Soft Reset Status.   0  Not in
                                                                                    reset   1  Reset is in progress */
/* MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT[MEM_INIT_DONE] Bits */
#define MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT_MEM_INIT_DONE_OFS (1)                             /* !< MEM_INIT_DONE Offset */
#define MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT_MEM_INIT_DONE_MASK ((uint32_t)0x00000002U)         /* !< Memory Initialization Done.   0
                                                                                    Message RAM initialization is in
                                                                                    progress   1  Message RAM is
                                                                                    initialized for use */
/* MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT[ENABLE_FDOE] Bits */
#define MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT_ENABLE_FDOE_OFS (2)                             /* !< ENABLE_FDOE Offset */
#define MCAN_TI_WRAPPER_PROCESSORS_REGS_STAT_ENABLE_FDOE_MASK ((uint32_t)0x00000004U)         /* !< Enable FD (Flexible Data-Rate)
                                                                                    Configuration Reflects the value of
                                                                                    mcanss_enable_fdoe configuration
                                                                                    port, -h = mcanss_enable_fdoe. */

/* MCAN_ICS Bits */
/* MCAN_ICS[EXT_TS_CNTR_OVFL] Bits */
#define MCAN_ICS_EXT_TS_CNTR_OVFL_OFS            (0)                             /* !< EXT_TS_CNTR_OVFL Offset */
#define MCAN_ICS_EXT_TS_CNTR_OVFL_MASK           ((uint32_t)0x00000001U)         /* !< External Timestamp Counter Overflow
                                                                                    Interrupt Status Clear. Reads always
                                                                                    return a 0.   0  Write of '0' has no
                                                                                    effect   1  Write of '1' clears the
                                                                                    MCANSS_IRS.EXT_TS_CNTR_OVFL bit */

/* MCAN_IRS Bits */
/* MCAN_IRS[EXT_TS_CNTR_OVFL] Bits */
#define MCAN_IRS_EXT_TS_CNTR_OVFL_OFS            (0)                             /* !< EXT_TS_CNTR_OVFL Offset */
#define MCAN_IRS_EXT_TS_CNTR_OVFL_MASK           ((uint32_t)0x00000001U)         /* !< External Timestamp Counter Overflow
                                                                                    Interrupt Status. This bit is set by
                                                                                    HW or by a SW write of '1'. To clear,
                                                                                    use the MCANSS_ICS.EXT_TS_CNTR_OVFL
                                                                                    bit.   0  External timestamp counter
                                                                                    has not overflowed   1  External
                                                                                    timestamp counter has overflowed
                                                                                    When this bit is set to '1' by HW or
                                                                                    SW, the
                                                                                    MCANSS_EXT_TS_UNSERVICED_INTR_CNTR
                                                                                    .EXT_TS_INTR_CNTR bit field will
                                                                                    increment by 1. */

/* MCAN_IECS Bits */
/* MCAN_IECS[EXT_TS_CNTR_OVFL] Bits */
#define MCAN_IECS_EXT_TS_CNTR_OVFL_OFS           (0)                             /* !< EXT_TS_CNTR_OVFL Offset */
#define MCAN_IECS_EXT_TS_CNTR_OVFL_MASK          ((uint32_t)0x00000001U)         /* !< External Timestamp Counter Overflow
                                                                                    Interrupt Enable Clear. Reads always
                                                                                    return a 0.   0  Write of '0' has no
                                                                                    effect   1  Write of '1' clears the
                                                                                    MCANSS_IES.EXT_TS_CNTR_OVFL bit */

/* MCAN_TI_WRAPPER_PROCESSORS_REGS_IE Bits */
/* MCAN_TI_WRAPPER_PROCESSORS_REGS_IE[EXT_TS_CNTR_OVFL] Bits */
#define MCAN_TI_WRAPPER_PROCESSORS_REGS_IE_EXT_TS_CNTR_OVFL_OFS (0)                             /* !< EXT_TS_CNTR_OVFL Offset */
#define MCAN_TI_WRAPPER_PROCESSORS_REGS_IE_EXT_TS_CNTR_OVFL_MASK ((uint32_t)0x00000001U)         /* !< External Timestamp Counter Overflow
                                                                                    Interrupt Enable. A write of '0' has
                                                                                    no effect. A write of '1' sets the
                                                                                    MCANSS_IES.EXT_TS_CNTR_OVFL bit. */

/* MCAN_IES Bits */
/* MCAN_IES[EXT_TS_CNTR_OVFL] Bits */
#define MCAN_IES_EXT_TS_CNTR_OVFL_OFS            (0)                             /* !< EXT_TS_CNTR_OVFL Offset */
#define MCAN_IES_EXT_TS_CNTR_OVFL_MASK           ((uint32_t)0x00000001U)         /* !< External Timestamp Counter Overflow
                                                                                    Interrupt Enable Status. To set, use
                                                                                    the CANSS_IE.EXT_TS_CNTR_OVFL bit. To
                                                                                    clear, use the
                                                                                    MCANSS_IECS.EXT_TS_CNTR_OVFL bit.   0
                                                                                    External timestamp counter overflow
                                                                                    interrupt is not enabled   1
                                                                                    External timestamp counter overflow
                                                                                    interrupt is enabled */

/* MCAN_EOI Bits */
/* MCAN_EOI[EOI] Bits */
#define MCAN_EOI_EOI_OFS                         (0)                             /* !< EOI Offset */
#define MCAN_EOI_EOI_MASK                        ((uint32_t)0x000000FFU)         /* !< End of Interrupt. A write to this
                                                                                    register will clear the associated
                                                                                    interrupt. If the unserviced
                                                                                    interrupt counter is > 1, another
                                                                                    interrupt is generated.   0x00
                                                                                    External TS Interrupt is cleared
                                                                                    0x01  MCAN(0) interrupt is cleared
                                                                                    0x02  MCAN(1) interrupt is cleared
                                                                                    Other writes are ignored. */

/* MCAN_EXT_TS_PRESCALER Bits */
/* MCAN_EXT_TS_PRESCALER[PRESCALER] Bits */
#define MCAN_EXT_TS_PRESCALER_PRESCALER_OFS      (0)                             /* !< PRESCALER Offset */
#define MCAN_EXT_TS_PRESCALER_PRESCALER_MASK     ((uint32_t)0x00FFFFFFU)         /* !< External Timestamp Prescaler Reload
                                                                                    Value. The external timestamp count
                                                                                    rate is the host (system) clock rate
                                                                                    divided by this value, except in the
                                                                                    case of 0. A zero value in this bit
                                                                                    field will act identically to a value
                                                                                    of 0x000001. */

/* MCAN_EXT_TS_UNSERVICED_INTR_CNTR Bits */
/* MCAN_EXT_TS_UNSERVICED_INTR_CNTR[EXT_TS_INTR_CNTR] Bits */
#define MCAN_EXT_TS_UNSERVICED_INTR_CNTR_EXT_TS_INTR_CNTR_OFS (0)                             /* !< EXT_TS_INTR_CNTR Offset */
#define MCAN_EXT_TS_UNSERVICED_INTR_CNTR_EXT_TS_INTR_CNTR_MASK ((uint32_t)0x0000001FU)         /* !< External Timestamp Counter
                                                                                    Unserviced Rollover Interrupts. If
                                                                                    this value is > 1, an MCANSS_EOI
                                                                                    write of '1' to bit 0 will issue
                                                                                    another interrupt.   The status of
                                                                                    this bit field is affected by the
                                                                                    MCANSS_IRS.EXT_TS_CNTR_OVFL bit
                                                                                    field. */

/* MCAN_CREL Bits */
/* MCAN_CREL[DAY] Bits */
#define MCAN_CREL_DAY_OFS                        (0)                             /* !< DAY Offset */
#define MCAN_CREL_DAY_MASK                       ((uint32_t)0x000000FFU)         /* !< Time Stamp Day. Two digits,
                                                                                    BCD-coded. */
/* MCAN_CREL[MON] Bits */
#define MCAN_CREL_MON_OFS                        (8)                             /* !< MON Offset */
#define MCAN_CREL_MON_MASK                       ((uint32_t)0x0000FF00U)         /* !< Time Stamp Month. Two digits,
                                                                                    BCD-coded. */
/* MCAN_CREL[YEAR] Bits */
#define MCAN_CREL_YEAR_OFS                       (16)                            /* !< YEAR Offset */
#define MCAN_CREL_YEAR_MASK                      ((uint32_t)0x000F0000U)         /* !< Time Stamp Year. One digit,
                                                                                    BCD-coded. */
/* MCAN_CREL[SUBSTEP] Bits */
#define MCAN_CREL_SUBSTEP_OFS                    (20)                            /* !< SUBSTEP Offset */
#define MCAN_CREL_SUBSTEP_MASK                   ((uint32_t)0x00F00000U)         /* !< Sub-Step of Core Release. One
                                                                                    digit, BCD-coded. */
/* MCAN_CREL[STEP] Bits */
#define MCAN_CREL_STEP_OFS                       (24)                            /* !< STEP Offset */
#define MCAN_CREL_STEP_MASK                      ((uint32_t)0x0F000000U)         /* !< Step of Core Release. One digit,
                                                                                    BCD-coded. */
/* MCAN_CREL[REL] Bits */
#define MCAN_CREL_REL_OFS                        (28)                            /* !< REL Offset */
#define MCAN_CREL_REL_MASK                       ((uint32_t)0xF0000000U)         /* !< Core Release. One digit, BCD-coded. */

/* MCAN_ENDN Bits */
/* MCAN_ENDN[ETV] Bits */
#define MCAN_ENDN_ETV_OFS                        (0)                             /* !< ETV Offset */
#define MCAN_ENDN_ETV_MASK                       ((uint32_t)0xFFFFFFFFU)         /* !< Endianess Test Value. Reading the
                                                                                    constant value maintained in this
                                                                                    register allows software to determine
                                                                                    the endianess of the host CPU. */

/* MCAN_DBTP Bits */
/* MCAN_DBTP[DSJW] Bits */
#define MCAN_DBTP_DSJW_OFS                       (0)                             /* !< DSJW Offset */
#define MCAN_DBTP_DSJW_MASK                      ((uint32_t)0x0000000FU)         /* !< Data Resynchronization Jump Width.
                                                                                    Valid values are 0 to 15. The actual
                                                                                    interpretation by the hardware of
                                                                                    this value is such that one more than
                                                                                    the value programmed here is used.
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_DBTP[DTSEG2] Bits */
#define MCAN_DBTP_DTSEG2_OFS                     (4)                             /* !< DTSEG2 Offset */
#define MCAN_DBTP_DTSEG2_MASK                    ((uint32_t)0x000000F0U)         /* !< Data Time Segment After Sample
                                                                                    Point. Valid values are 0 to 15. The
                                                                                    actual interpretation by the hardware
                                                                                    of this value is such that one more
                                                                                    than the programmed value is used.
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_DBTP[DTSEG1] Bits */
#define MCAN_DBTP_DTSEG1_OFS                     (8)                             /* !< DTSEG1 Offset */
#define MCAN_DBTP_DTSEG1_MASK                    ((uint32_t)0x00001F00U)         /* !< Data Time Segment Before Sample
                                                                                    Point. Valid values are 0 to 31. The
                                                                                    actual interpretation by the hardware
                                                                                    of this value is such that one more
                                                                                    than the programmed value is used.
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_DBTP[DBRP] Bits */
#define MCAN_DBTP_DBRP_OFS                       (16)                            /* !< DBRP Offset */
#define MCAN_DBTP_DBRP_MASK                      ((uint32_t)0x001F0000U)         /* !< Data Bit Rate Prescaler. The value
                                                                                    by which the oscillator frequency is
                                                                                    divided for generating the bit time
                                                                                    quanta. The bit time is built up from
                                                                                    a multiple of this quanta. Valid
                                                                                    values for the Bit Rate Prescaler are
                                                                                    0 to 31. The actual interpretation by
                                                                                    the hardware of this value is such
                                                                                    that one more than the value
                                                                                    programmed here is used.   Qualified
                                                                                    Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_DBTP[TDC] Bits */
#define MCAN_DBTP_TDC_OFS                        (23)                            /* !< TDC Offset */
#define MCAN_DBTP_TDC_MASK                       ((uint32_t)0x00800000U)         /* !< Transmitter Delay Compensation   0
                                                                                    Transmitter Delay Compensation
                                                                                    disabled   1  Transmitter Delay
                                                                                    Compensation enabled */

/* MCAN_TEST Bits */
/* MCAN_TEST[LBCK] Bits */
#define MCAN_TEST_LBCK_OFS                       (4)                             /* !< LBCK Offset */
#define MCAN_TEST_LBCK_MASK                      ((uint32_t)0x00000010U)         /* !< Loop Back Mode. Qualified Write is
                                                                                    possible only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */
#define MCAN_TEST_LBCK_DISABLE                   ((uint32_t)0x00000000U)         /* !< Reset value, Loop Back Mode is
                                                                                    disabled */
#define MCAN_TEST_LBCK_ENABLE                    ((uint32_t)0x00000010U)         /* !< Loop Back Mode is enabled */
/* MCAN_TEST[TX] Bits */
#define MCAN_TEST_TX_OFS                         (5)                             /* !< TX Offset */
#define MCAN_TEST_TX_MASK                        ((uint32_t)0x00000060U)         /* !< Control of Transmit Pin   00  CAN
                                                                                    TX pin controlled by the CAN Core,
                                                                                    updated at the end of the CAN bit
                                                                                    time   01  Sample Point can be
                                                                                    monitored at CAN TX pin   10
                                                                                    Dominant ('0') level at CAN TX pin
                                                                                    11  Recessive ('1') at CAN TX pin
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_TEST[RX] Bits */
#define MCAN_TEST_RX_OFS                         (7)                             /* !< RX Offset */
#define MCAN_TEST_RX_MASK                        ((uint32_t)0x00000080U)         /* !< Receive Pin. Monitors the actual
                                                                                    value of the CAN receive pin. */
#define MCAN_TEST_RX_DOMINANT                    ((uint32_t)0x00000000U)         /* !< The CAN bus is dominant (CAN RX pin
                                                                                    = '0') */
#define MCAN_TEST_RX_RECESSIVE                   ((uint32_t)0x00000080U)         /* !< The CAN bus is recessive (CAN RX
                                                                                    pin = '1') */

/* MCAN_RWD Bits */
/* MCAN_RWD[WDC] Bits */
#define MCAN_RWD_WDC_OFS                         (0)                             /* !< WDC Offset */
#define MCAN_RWD_WDC_MASK                        ((uint32_t)0x000000FFU)         /* !< Watchdog Configuration. Start value
                                                                                    of the Message RAM Watchdog Counter.
                                                                                    With the reset value of "00" the
                                                                                    counter is disabled.   Qualified
                                                                                    Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_RWD[WDV] Bits */
#define MCAN_RWD_WDV_OFS                         (8)                             /* !< WDV Offset */
#define MCAN_RWD_WDV_MASK                        ((uint32_t)0x0000FF00U)         /* !< Watchdog Value. Acutal Message RAM
                                                                                    Watchdog Counter Value.   The RAM
                                                                                    Watchdog monitors the READY output of
                                                                                    the Message RAM. A Message RAM access
                                                                                    via the MCAN's Generic Master
                                                                                    Interface starts the Message RAM
                                                                                    Watchdog Counter with the value
                                                                                    configured by the WDC field. The
                                                                                    counter is reloaded with WDC when the
                                                                                    Message RAM signals successful
                                                                                    completion by activating its READY
                                                                                    output. In case there is no response
                                                                                    from the Message RAM until the
                                                                                    counter has counted down to zero, the
                                                                                    counter stops and interrupt flag
                                                                                    MCAN_IR.WDI is set. The RAM Watchdog
                                                                                    Counter is clocked by the host
                                                                                    (system) clock. */

/* MCAN_CCCR Bits */
/* MCAN_CCCR[INIT] Bits */
#define MCAN_CCCR_INIT_OFS                       (0)                             /* !< INIT Offset */
#define MCAN_CCCR_INIT_MASK                      ((uint32_t)0x00000001U)         /* !< Initialization   0  Normal
                                                                                    Operation   1  Initialization is
                                                                                    started Note: Due to the
                                                                                    synchronization mechanism between the
                                                                                    two clock domains, there may be a
                                                                                    delay until the value written to INIT
                                                                                    can be read back. Therefore the
                                                                                    programmer has to assure that the
                                                                                    previous value written to INIT has
                                                                                    been accepted by reading INIT before
                                                                                    setting INIT to a new value. */
/* MCAN_CCCR[CCE] Bits */
#define MCAN_CCCR_CCE_OFS                        (1)                             /* !< CCE Offset */
#define MCAN_CCCR_CCE_MASK                       ((uint32_t)0x00000002U)         /* !< Configuration Change Enable   0
                                                                                    The CPU has no write access to the
                                                                                    protected configuration registers   1
                                                                                    The CPU has write access to the
                                                                                    protected configuration registers
                                                                                    (while CCCR.INIT = '1')   Qualified
                                                                                    Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_CCCR[ASM] Bits */
#define MCAN_CCCR_ASM_OFS                        (2)                             /* !< ASM Offset */
#define MCAN_CCCR_ASM_MASK                       ((uint32_t)0x00000004U)         /* !< Restricted Operation Mode. Bit ASM
                                                                                    can only be set by SW when both CCE
                                                                                    and INIT are set to '1'. The bit can
                                                                                    be reset by SW at any time.   0
                                                                                    Normal CAN operation   1  Restricted
                                                                                    Operation Mode active   Qualified
                                                                                    Write 1 to Set is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_CCCR[CSA] Bits */
#define MCAN_CCCR_CSA_OFS                        (3)                             /* !< CSA Offset */
#define MCAN_CCCR_CSA_MASK                       ((uint32_t)0x00000008U)         /* !< Clock Stop Acknowledge   0  No
                                                                                    clock stop acknowledged   1  MCAN may
                                                                                    be set in power down by stopping the
                                                                                    Host and CAN clocks */
/* MCAN_CCCR[CSR] Bits */
#define MCAN_CCCR_CSR_OFS                        (4)                             /* !< CSR Offset */
#define MCAN_CCCR_CSR_MASK                       ((uint32_t)0x00000010U)         /* !< Clock Stop Request   0  No clock
                                                                                    stop is requested   1  Clock stop
                                                                                    requested. When clock stop is
                                                                                    requested, first INIT and then CSA
                                                                                    will be set after all pending
                                                                                    transfer requests have been completed
                                                                                    and the CAN bus reached idle. */
/* MCAN_CCCR[MON] Bits */
#define MCAN_CCCR_MON_OFS                        (5)                             /* !< MON Offset */
#define MCAN_CCCR_MON_MASK                       ((uint32_t)0x00000020U)         /* !< Bus Monitoring Mode. Bit MON can
                                                                                    only be set by SW when both CCE and
                                                                                    INIT are set to '1'. The bit can be
                                                                                    reset by SW at any time.   0  Bus
                                                                                    Monitoring Mode is disabled   1  Bus
                                                                                    Monitoring Mode is enabled
                                                                                    Qualified Write 1 to Set is possible
                                                                                    only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */
/* MCAN_CCCR[DAR] Bits */
#define MCAN_CCCR_DAR_OFS                        (6)                             /* !< DAR Offset */
#define MCAN_CCCR_DAR_MASK                       ((uint32_t)0x00000040U)         /* !< Disable Automatic Retransmission
                                                                                    0  Automatic retransmission of
                                                                                    messages not transmitted successfully
                                                                                    enabled   1  Automatic retransmission
                                                                                    disabled   Qualified Write is
                                                                                    possible only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */
/* MCAN_CCCR[TEST] Bits */
#define MCAN_CCCR_TEST_OFS                       (7)                             /* !< TEST Offset */
#define MCAN_CCCR_TEST_MASK                      ((uint32_t)0x00000080U)         /* !< Test Mode Enable   0  Normal
                                                                                    operation, register TEST holds reset
                                                                                    values   1  Test Mode, write access
                                                                                    to register TEST enabled   Qualified
                                                                                    Write 1 to Set is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_CCCR[FDOE] Bits */
#define MCAN_CCCR_FDOE_OFS                       (8)                             /* !< FDOE Offset */
#define MCAN_CCCR_FDOE_MASK                      ((uint32_t)0x00000100U)         /* !< Flexible Datarate Operation Enable
                                                                                    0  FD operation disabled   1  FD
                                                                                    operation enabled   Qualified Write
                                                                                    is possible only with CCCR.CCE='1'
                                                                                    and CCCR.INIT='1'. */
/* MCAN_CCCR[BRSE] Bits */
#define MCAN_CCCR_BRSE_OFS                       (9)                             /* !< BRSE Offset */
#define MCAN_CCCR_BRSE_MASK                      ((uint32_t)0x00000200U)         /* !< Bit Rate Switch Enable   0  Bit
                                                                                    rate switching for transmissions
                                                                                    disabled   1  Bit rate switching for
                                                                                    transmissions enabled Note: When CAN
                                                                                    FD operation is disabled FDOE = '0',
                                                                                    BRSE is not evaluated.   Qualified
                                                                                    Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_CCCR[PXHD] Bits */
#define MCAN_CCCR_PXHD_OFS                       (12)                            /* !< PXHD Offset */
#define MCAN_CCCR_PXHD_MASK                      ((uint32_t)0x00001000U)         /* !< Protocol Exception Handling Disable
                                                                                    0  Protocol exception handling
                                                                                    enabled   1  Protocol exception
                                                                                    handling disabled Note: When protocol
                                                                                    exception handling is disabled, the
                                                                                    MCAN will transmit an error frame
                                                                                    when it detects a protocol exception
                                                                                    condition.   Qualified Write is
                                                                                    possible only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */
/* MCAN_CCCR[EFBI] Bits */
#define MCAN_CCCR_EFBI_OFS                       (13)                            /* !< EFBI Offset */
#define MCAN_CCCR_EFBI_MASK                      ((uint32_t)0x00002000U)         /* !< Edge Filtering during Bus
                                                                                    Integration   0  Edge filtering
                                                                                    disabled   1  Two consecutive
                                                                                    dominant tq required to detect an
                                                                                    edge for hard synchronization
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_CCCR[TXP] Bits */
#define MCAN_CCCR_TXP_OFS                        (14)                            /* !< TXP Offset */
#define MCAN_CCCR_TXP_MASK                       ((uint32_t)0x00004000U)         /* !< Transmit Pause. If this bit is set,
                                                                                    the MCAN pauses for two CAN bit times
                                                                                    before starting the next transmission
                                                                                    after itself has successfully
                                                                                    transmitted a frame.   0  Transmit
                                                                                    pause disabled   1  Transmit pause
                                                                                    enabled   Qualified Write is possible
                                                                                    only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */
/* MCAN_CCCR[NISO] Bits */
#define MCAN_CCCR_NISO_OFS                       (15)                            /* !< NISO Offset */
#define MCAN_CCCR_NISO_MASK                      ((uint32_t)0x00008000U)         /* !< Non ISO Operation. If this bit is
                                                                                    set, the MCAN uses the CAN FD frame
                                                                                    format as specified by the Bosch CAN
                                                                                    FD Specification V1.0.   0  CAN FD
                                                                                    frame format according to ISO
                                                                                    11898-1:2015   1  CAN FD frame format
                                                                                    according to Bosch CAN FD
                                                                                    Specification V1.0 */

/* MCAN_NBTP Bits */
/* MCAN_NBTP[NTSEG2] Bits */
#define MCAN_NBTP_NTSEG2_OFS                     (0)                             /* !< NTSEG2 Offset */
#define MCAN_NBTP_NTSEG2_MASK                    ((uint32_t)0x0000007FU)         /* !< Nominal Time Segment After Sample
                                                                                    Point. Valid values are 1 to 127. The
                                                                                    actual interpretation by the hardware
                                                                                    of this value is such that one more
                                                                                    than the programmed value is used.
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_NBTP[NTSEG1] Bits */
#define MCAN_NBTP_NTSEG1_OFS                     (8)                             /* !< NTSEG1 Offset */
#define MCAN_NBTP_NTSEG1_MASK                    ((uint32_t)0x0000FF00U)         /* !< Nominal Time Segment Before Sample
                                                                                    Point. Valid values are 1 to 255. The
                                                                                    actual interpretation by the hardware
                                                                                    of this value is such that one more
                                                                                    than the programmed value is used.
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_NBTP[NBRP] Bits */
#define MCAN_NBTP_NBRP_OFS                       (16)                            /* !< NBRP Offset */
#define MCAN_NBTP_NBRP_MASK                      ((uint32_t)0x01FF0000U)         /* !< Nominal Bit Rate Prescaler. The
                                                                                    value by which the oscillator
                                                                                    frequency is divided for generating
                                                                                    the bit time quanta. The bit time is
                                                                                    built up from a multiple of this
                                                                                    quanta. Valid values for the Bit Rate
                                                                                    Prescaler are 0 to 511. The actual
                                                                                    interpretation by the hardware of
                                                                                    this value is such that one more than
                                                                                    the value programmed here is used.
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_NBTP[NSJW] Bits */
#define MCAN_NBTP_NSJW_OFS                       (25)                            /* !< NSJW Offset */
#define MCAN_NBTP_NSJW_MASK                      ((uint32_t)0xFE000000U)         /* !< Nominal (Re)Synchronization Jump
                                                                                    Width. Valid values are 0 to 127. The
                                                                                    actual interpretation by the hardware
                                                                                    of this value is such that one more
                                                                                    than the value programmed here is
                                                                                    used.   Qualified Write is possible
                                                                                    only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */

/* MCAN_TSCC Bits */
/* MCAN_TSCC[TSS] Bits */
#define MCAN_TSCC_TSS_OFS                        (0)                             /* !< TSS Offset */
#define MCAN_TSCC_TSS_MASK                       ((uint32_t)0x00000003U)         /* !< Timestamp Select   00  Timestamp
                                                                                    counter value always 0x0000   01
                                                                                    Timestamp counter value incremented
                                                                                    according to TCP   10  External
                                                                                    timestamp counter value used   11
                                                                                    Same as "00"   Qualified Write is
                                                                                    possible only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */
/* MCAN_TSCC[TCP] Bits */
#define MCAN_TSCC_TCP_OFS                        (16)                            /* !< TCP Offset */
#define MCAN_TSCC_TCP_MASK                       ((uint32_t)0x000F0000U)         /* !< Timestamp Counter Prescaler.
                                                                                    Configures the timestamp and timeout
                                                                                    counters time unit in multiples of
                                                                                    CAN bit times. Valid values are 0 to
                                                                                    15. The actual interpretation by the
                                                                                    hardware of this value is such that
                                                                                    one more than the value programmed
                                                                                    here is used.   Note: With CAN FD an
                                                                                    external counter is required for
                                                                                    timestamp generation (TSS = "10").
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */

/* MCAN_TSCV Bits */
/* MCAN_TSCV[TSC] Bits */
#define MCAN_TSCV_TSC_OFS                        (0)                             /* !< TSC Offset */
#define MCAN_TSCV_TSC_MASK                       ((uint32_t)0x0000FFFFU)         /* !< Timestamp Counter. The
                                                                                    internal/external Timestamp Counter
                                                                                    value is captured on start of frame
                                                                                    (both Rx and Tx). When TSCC.TSS =
                                                                                    "01", the Timestamp Counter is
                                                                                    incremented in multiples of CAN bit
                                                                                    times, (1...16), depending on the
                                                                                    configuration of TSCC.TCP. A wrap
                                                                                    around sets interrupt flag IR.TSW.
                                                                                    Write access resets the counter to
                                                                                    zero. When TSCC.TSS = "10", TSC
                                                                                    reflects the External Timestamp
                                                                                    Counter value, and a write access has
                                                                                    no impact.   Note: A "wrap around" is
                                                                                    a change of the Timestamp Counter
                                                                                    value from non-zero to zero not
                                                                                    caused by write access to MCAN_TSCV. */

/* MCAN_TOCC Bits */
/* MCAN_TOCC[ETOC] Bits */
#define MCAN_TOCC_ETOC_OFS                       (0)                             /* !< ETOC Offset */
#define MCAN_TOCC_ETOC_MASK                      ((uint32_t)0x00000001U)         /* !< Enable Timeout Counter   0  Timeout
                                                                                    Counter disabled   1  Timeout Counter
                                                                                    enabled   Qualified Write is possible
                                                                                    only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */
/* MCAN_TOCC[TOS] Bits */
#define MCAN_TOCC_TOS_OFS                        (1)                             /* !< TOS Offset */
#define MCAN_TOCC_TOS_MASK                       ((uint32_t)0x00000006U)         /* !< Timeout Select. When operating in
                                                                                    Continuous mode, a write to TOCV
                                                                                    presets the counter to the value
                                                                                    configured by TOCC.TOP and continues
                                                                                    down-counting. When the Timeout
                                                                                    Counter is controlled by one of the
                                                                                    FIFOs, an empty FIFO presets the
                                                                                    counter to the value configured by
                                                                                    TOCC.TOP. Down-counting is started
                                                                                    when the first FIFO element is
                                                                                    stored.   00  Continuous operation
                                                                                    01  Timeout controlled by Tx Event
                                                                                    FIFO   10  Timeout controlled by Rx
                                                                                    FIFO 0   11  Timeout controlled by Rx
                                                                                    FIFO 1   Qualified Write is possible
                                                                                    only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */
/* MCAN_TOCC[TOP] Bits */
#define MCAN_TOCC_TOP_OFS                        (16)                            /* !< TOP Offset */
#define MCAN_TOCC_TOP_MASK                       ((uint32_t)0xFFFF0000U)         /* !< Timeout Period. Start value of the
                                                                                    Timeout Counter (down-counter).
                                                                                    Configures the Timeout Period.
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */

/* MCAN_TOCV Bits */
/* MCAN_TOCV[TOC] Bits */
#define MCAN_TOCV_TOC_OFS                        (0)                             /* !< TOC Offset */
#define MCAN_TOCV_TOC_MASK                       ((uint32_t)0x0000FFFFU)         /* !< Timeout Counter. The Timeout
                                                                                    Counter is decremented in multiples
                                                                                    of CAN bit times, (1...16), depending
                                                                                    on the configuration of TSCC.TCP.
                                                                                    When decremented to zero, interrupt
                                                                                    flag IR.TOO is set and the Timeout
                                                                                    Counter is stopped. Start and
                                                                                    reset/restart conditions are
                                                                                    configured via TOCC.TOS. */

/* MCAN_ECR Bits */
/* MCAN_ECR[TEC] Bits */
#define MCAN_ECR_TEC_OFS                         (0)                             /* !< TEC Offset */
#define MCAN_ECR_TEC_MASK                        ((uint32_t)0x000000FFU)         /* !< Transmit Error Counter. Actual
                                                                                    state of the Transmit Error Counter,
                                                                                    values between 0 and 255.   Note:
                                                                                    When CCCR.ASM is set, the CAN
                                                                                    protocol controller does not
                                                                                    increment TEC and REC when a CAN
                                                                                    protocol error is detected, but CEL
                                                                                    is still incremented. */
/* MCAN_ECR[REC] Bits */
#define MCAN_ECR_REC_OFS                         (8)                             /* !< REC Offset */
#define MCAN_ECR_REC_MASK                        ((uint32_t)0x00007F00U)         /* !< Receive Error Counter. Actual state
                                                                                    of the Receive Error Counter, values
                                                                                    between 0 and 127.   Note: When
                                                                                    CCCR.ASM is set, the CAN protocol
                                                                                    controller does not increment TEC and
                                                                                    REC when a CAN protocol error is
                                                                                    detected, but CEL is still
                                                                                    incremented. */
/* MCAN_ECR[RP] Bits */
#define MCAN_ECR_RP_OFS                          (15)                            /* !< RP Offset */
#define MCAN_ECR_RP_MASK                         ((uint32_t)0x00008000U)         /* !< Receive Error Passive   0  The
                                                                                    Receive Error Counter is below the
                                                                                    error passive level of 128   1  The
                                                                                    Receive Error Counter has reached the
                                                                                    error passive level of 128 */
/* MCAN_ECR[CEL] Bits */
#define MCAN_ECR_CEL_OFS                         (16)                            /* !< CEL Offset */
#define MCAN_ECR_CEL_MASK                        ((uint32_t)0x00FF0000U)         /* !< CAN Error Logging. The counter is
                                                                                    incremented each time when a CAN
                                                                                    protocol error causes the Transmit
                                                                                    Error Counter or the Receive Error
                                                                                    Counter to be incremented. It is
                                                                                    reset by read access to CEL. The
                                                                                    counter stops at 0xFF; the next
                                                                                    increment of TEC or REC sets
                                                                                    interrupt flag IR.ELO.   Note: When
                                                                                    CCCR.ASM is set, the CAN protocol
                                                                                    controller does not increment TEC and
                                                                                    REC when a CAN protocol error is
                                                                                    detected, but CEL is still
                                                                                    incremented. */

/* MCAN_PSR Bits */
/* MCAN_PSR[LEC] Bits */
#define MCAN_PSR_LEC_OFS                         (0)                             /* !< LEC Offset */
#define MCAN_PSR_LEC_MASK                        ((uint32_t)0x00000007U)         /* !< Last Error Code. The LEC indicates
                                                                                    the type of the last error to occur
                                                                                    on the CAN bus. This field will be
                                                                                    cleared to '0' when a message has
                                                                                    been transferred (reception or
                                                                                    transmission) without error.   0  No
                                                                                    Error: No error occurred since LEC
                                                                                    has been reset by successful
                                                                                    reception or transmission.   1  Stuff
                                                                                    Error: More than 5 equal bits in a
                                                                                    sequence have occurred in a part of a
                                                                                    received message where this is not
                                                                                    allowed.   2  Form Error: A fixed
                                                                                    format part of a received frame has
                                                                                    the wrong format.   3  AckError: The
                                                                                    message transmitted by the MCAN was
                                                                                    not acknowledged by another node.   4
                                                                                    Bit1Error: During the transmission
                                                                                    of a message (with the exception of
                                                                                    the arbitration field), the device
                                                                                    wanted to send a recessive level (bit
                                                                                    of logical value '1'), but the
                                                                                    monitored bus value was dominant.   5
                                                                                    Bit0Error: During the transmission
                                                                                    of a message (or acknowledge bit, or
                                                                                    active error flag, or overload flag),
                                                                                    the device wanted to send a dominant
                                                                                    level (data or identifier bit logical
                                                                                    value '0'), but the monitored bus
                                                                                    value was recessive. During Bus_Off
                                                                                    recovery this status is set each time
                                                                                    a sequence of 11 recessive bits has
                                                                                    been monitored. This enables the CPU
                                                                                    to monitor the proceeding of the
                                                                                    Bus_Off recovery sequence (indicating
                                                                                    the bus is not stuck at dominant or
                                                                                    continuously disturbed).   6
                                                                                    CRCError: The CRC check sum of a
                                                                                    received message was incorrect. The
                                                                                    CRC of an incoming message does not
                                                                                    match with the CRC calculated from
                                                                                    the received data.   7  NoChange: Any
                                                                                    read access to the Protocol Status
                                                                                    Register re-initializes the LEC to
                                                                                    '7'. When the LEC shows the value
                                                                                    '7', no CAN bus event was detected
                                                                                    since the last CPU read access to the
                                                                                    Protocol Status Register.   Note:
                                                                                    When a frame in CAN FD format has
                                                                                    reached the data phase with BRS flag
                                                                                    set, the next CAN event (error or
                                                                                    valid frame) will be shown in DLEC
                                                                                    instead of LEC. An error in a fixed
                                                                                    stuff bit of a CAN FD CRC sequence
                                                                                    will be shown as a Form Error, not
                                                                                    Stuff Error. Note: The Bus_Off
                                                                                    recovery sequence (see ISO
                                                                                    11898-1:2015) cannot be shortened by
                                                                                    setting or resetting CCCR.INIT. If
                                                                                    the device goes Bus_Off, it will set
                                                                                    CCCR.INIT of its own accord, stopping
                                                                                    all bus activities. Once CCCR.INIT
                                                                                    has been cleared by the CPU, the
                                                                                    device will then wait for 129
                                                                                    occurrences of Bus Idle (129 * 11
                                                                                    consecutive recessive bits) before
                                                                                    resuming normal operation. At the end
                                                                                    of the Bus_Off recovery sequence, the
                                                                                    Error Management Counters will be
                                                                                    reset. During the waiting time after
                                                                                    the resetting of CCCR.INIT, each time
                                                                                    a sequence of 11 recessive bits has
                                                                                    been monitored, a Bit0Error code is
                                                                                    written to PSR.LEC, enabling the CPU
                                                                                    to readily check up whether the CAN
                                                                                    bus is stuck at dominant or
                                                                                    continuously disturbed and to monitor
                                                                                    the Bus_Off recovery sequence.
                                                                                    ECR.REC is used to count these
                                                                                    sequences. */
/* MCAN_PSR[ACT] Bits */
#define MCAN_PSR_ACT_OFS                         (3)                             /* !< ACT Offset */
#define MCAN_PSR_ACT_MASK                        ((uint32_t)0x00000018U)         /* !< Node Activity.  Monitors the
                                                                                    module's CAN communication state.
                                                                                    00  Synchronizing - node is
                                                                                    synchronizing on CAN communication
                                                                                    01  Idle - node is neither receiver
                                                                                    nor transmitter   10  Receiver - node
                                                                                    is operating as receiver   11
                                                                                    Transmitter - node is operating as
                                                                                    transmitter   Note: ACT is set to
                                                                                    "00" by a Protocol Exception Event. */
/* MCAN_PSR[EP] Bits */
#define MCAN_PSR_EP_OFS                          (5)                             /* !< EP Offset */
#define MCAN_PSR_EP_MASK                         ((uint32_t)0x00000020U)         /* !< Error Passive   0  The M_CAN is in
                                                                                    the Error_Active state. It normally
                                                                                    takes part in bus communication and
                                                                                    sends an active error flag when an
                                                                                    error has been detected   1  The
                                                                                    M_CAN is in the Error_Passive state */
/* MCAN_PSR[EW] Bits */
#define MCAN_PSR_EW_OFS                          (6)                             /* !< EW Offset */
#define MCAN_PSR_EW_MASK                         ((uint32_t)0x00000040U)         /* !< Warning Status   0  Both error
                                                                                    counters are below the Error_Warning
                                                                                    limit of 96   1  At least one of
                                                                                    error counter has reached the
                                                                                    Error_Warning limit of 96 */
/* MCAN_PSR[BO] Bits */
#define MCAN_PSR_BO_OFS                          (7)                             /* !< BO Offset */
#define MCAN_PSR_BO_MASK                         ((uint32_t)0x00000080U)         /* !< Bus_Off Status   0  The M_CAN is
                                                                                    not Bus_Off   1  The M_CAN is in
                                                                                    Bus_Off state */
/* MCAN_PSR[DLEC] Bits */
#define MCAN_PSR_DLEC_OFS                        (8)                             /* !< DLEC Offset */
#define MCAN_PSR_DLEC_MASK                       ((uint32_t)0x00000700U)         /* !< Data Phase Last Error Code. Type of
                                                                                    last error that occurred in the data
                                                                                    phase of a CAN FD format frame with
                                                                                    its BRS flag set. Coding is the same
                                                                                    as for LEC. This field will be
                                                                                    cleared to zero when a CAN FD format
                                                                                    frame with its BRS flag set has been
                                                                                    transferred (reception or
                                                                                    transmission) without error. */
/* MCAN_PSR[RESI] Bits */
#define MCAN_PSR_RESI_OFS                        (11)                            /* !< RESI Offset */
#define MCAN_PSR_RESI_MASK                       ((uint32_t)0x00000800U)         /* !< ESI Flag of Last Received CAN FD
                                                                                    Message. This bit is set together
                                                                                    with RFDF, independent of acceptance
                                                                                    filtering.   0  Last received CAN FD
                                                                                    message did not have its ESI flag set
                                                                                    1  Last received CAN FD message had
                                                                                    its ESI flag set */
/* MCAN_PSR[RBRS] Bits */
#define MCAN_PSR_RBRS_OFS                        (12)                            /* !< RBRS Offset */
#define MCAN_PSR_RBRS_MASK                       ((uint32_t)0x00001000U)         /* !< BRS Flag of Last Received CAN FD
                                                                                    Message. This bit is set together
                                                                                    with RFDF, independent of acceptance
                                                                                    filtering.   0  Last received CAN FD
                                                                                    message did not have its BRS flag set
                                                                                    1  Last received CAN FD message had
                                                                                    its BRS flag set */
/* MCAN_PSR[RFDF] Bits */
#define MCAN_PSR_RFDF_OFS                        (13)                            /* !< RFDF Offset */
#define MCAN_PSR_RFDF_MASK                       ((uint32_t)0x00002000U)         /* !< Received a CAN FD Message.  This
                                                                                    bit is set independent of acceptance
                                                                                    filtering.   0  Since this bit was
                                                                                    reset by the CPU, no CAN FD message
                                                                                    has been received   1  Message in CAN
                                                                                    FD format with FDF flag set has been
                                                                                    received */
/* MCAN_PSR[PXE] Bits */
#define MCAN_PSR_PXE_OFS                         (14)                            /* !< PXE Offset */
#define MCAN_PSR_PXE_MASK                        ((uint32_t)0x00004000U)         /* !< Protocol Exception Event   0  No
                                                                                    protocol exception event occurred
                                                                                    since last read access   1  Protocol
                                                                                    exception event occurred */
/* MCAN_PSR[TDCV] Bits */
#define MCAN_PSR_TDCV_OFS                        (16)                            /* !< TDCV Offset */
#define MCAN_PSR_TDCV_MASK                       ((uint32_t)0x007F0000U)         /* !< Transmitter Delay Compensation
                                                                                    Value. Position of the secondary
                                                                                    sample point, defined by the sum of
                                                                                    the measured delay from the internal
                                                                                    CAN TX signal to the internal CAN RX
                                                                                    signal and TDCR.TDCO. The SSP
                                                                                    position is, in the data phase, the
                                                                                    number of mtq between the start of
                                                                                    the transmitted bit and the secondary
                                                                                    sample point. Valid values are 0 to
                                                                                    127 mtq. */

/* MCAN_TDCR Bits */
/* MCAN_TDCR[TDCF] Bits */
#define MCAN_TDCR_TDCF_OFS                       (0)                             /* !< TDCF Offset */
#define MCAN_TDCR_TDCF_MASK                      ((uint32_t)0x0000007FU)         /* !< Transmitter Delay Compensation
                                                                                    Filter Window Length. Defines the
                                                                                    minimum value for the SSP position,
                                                                                    dominant edges on the internal CAN RX
                                                                                    signal that would result in an
                                                                                    earlier SSP position are ignored for
                                                                                    transmitter delay measurement. The
                                                                                    feature is enabled when TDCF is
                                                                                    configured to a value greater than
                                                                                    TDCO. Valid values are 0 to 127 mtq.
                                                                                    Qualified Write is possible only
                                                                                    with CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_TDCR[TDCO] Bits */
#define MCAN_TDCR_TDCO_OFS                       (8)                             /* !< TDCO Offset */
#define MCAN_TDCR_TDCO_MASK                      ((uint32_t)0x00007F00U)         /* !< Transmitter Delay Compensation
                                                                                    Offset. Offset value defining the
                                                                                    distance between the measured delay
                                                                                    from the internal CAN TX signal to
                                                                                    the internal CAN RX signal and the
                                                                                    secondary sample point. Valid values
                                                                                    are 0 to 127 mtq.   Qualified Write
                                                                                    is possible only with CCCR.CCE='1'
                                                                                    and CCCR.INIT='1'. */

/* MCAN_IR Bits */
/* MCAN_IR[RF0N] Bits */
#define MCAN_IR_RF0N_OFS                         (0)                             /* !< RF0N Offset */
#define MCAN_IR_RF0N_MASK                        ((uint32_t)0x00000001U)         /* !< Rx FIFO 0 New Message   0  No new
                                                                                    message written to Rx FIFO 0   1  New
                                                                                    message written to Rx FIFO 0 */
/* MCAN_IR[RF0W] Bits */
#define MCAN_IR_RF0W_OFS                         (1)                             /* !< RF0W Offset */
#define MCAN_IR_RF0W_MASK                        ((uint32_t)0x00000002U)         /* !< Rx FIFO 0 Watermark Reached   0  Rx
                                                                                    FIFO 0 fill level below watermark   1
                                                                                    Rx FIFO 0 fill level reached
                                                                                    watermark */
/* MCAN_IR[RF0F] Bits */
#define MCAN_IR_RF0F_OFS                         (2)                             /* !< RF0F Offset */
#define MCAN_IR_RF0F_MASK                        ((uint32_t)0x00000004U)         /* !< Rx FIFO 0 Full   0  Rx FIFO 0 not
                                                                                    full   1  Rx FIFO 0 full */
/* MCAN_IR[RF0L] Bits */
#define MCAN_IR_RF0L_OFS                         (3)                             /* !< RF0L Offset */
#define MCAN_IR_RF0L_MASK                        ((uint32_t)0x00000008U)         /* !< Rx FIFO 0 Message Lost   0  No Rx
                                                                                    FIFO 0 message lost   1  Rx FIFO 0
                                                                                    message lost, also set after write
                                                                                    attempt to Rx FIFO 0 of size zero */
/* MCAN_IR[RF1N] Bits */
#define MCAN_IR_RF1N_OFS                         (4)                             /* !< RF1N Offset */
#define MCAN_IR_RF1N_MASK                        ((uint32_t)0x00000010U)         /* !< Rx FIFO 1 New Message   0  No new
                                                                                    message written to Rx FIFO 1   1  New
                                                                                    message written to Rx FIFO 1 */
/* MCAN_IR[RF1W] Bits */
#define MCAN_IR_RF1W_OFS                         (5)                             /* !< RF1W Offset */
#define MCAN_IR_RF1W_MASK                        ((uint32_t)0x00000020U)         /* !< Rx FIFO 1 Watermark Reached   0  Rx
                                                                                    FIFO 1 fill level below watermark   1
                                                                                    Rx FIFO 1 fill level reached
                                                                                    watermark */
/* MCAN_IR[RF1F] Bits */
#define MCAN_IR_RF1F_OFS                         (6)                             /* !< RF1F Offset */
#define MCAN_IR_RF1F_MASK                        ((uint32_t)0x00000040U)         /* !< Rx FIFO 1 Full   0  Rx FIFO 1 not
                                                                                    full   1  Rx FIFO 1 full */
/* MCAN_IR[RF1L] Bits */
#define MCAN_IR_RF1L_OFS                         (7)                             /* !< RF1L Offset */
#define MCAN_IR_RF1L_MASK                        ((uint32_t)0x00000080U)         /* !< Rx FIFO 1 Message Lost   0  No Rx
                                                                                    FIFO 1 message lost   1  Rx FIFO 1
                                                                                    message lost, also set after write
                                                                                    attempt to Rx FIFO 1 of size zero */
/* MCAN_IR[HPM] Bits */
#define MCAN_IR_HPM_OFS                          (8)                             /* !< HPM Offset */
#define MCAN_IR_HPM_MASK                         ((uint32_t)0x00000100U)         /* !< High Priority Message   0  No high
                                                                                    priority message received   1  High
                                                                                    priority message received */
/* MCAN_IR[TC] Bits */
#define MCAN_IR_TC_OFS                           (9)                             /* !< TC Offset */
#define MCAN_IR_TC_MASK                          ((uint32_t)0x00000200U)         /* !< Transmission Completed   0  No
                                                                                    transmission completed   1
                                                                                    Transmission completed */
/* MCAN_IR[TCF] Bits */
#define MCAN_IR_TCF_OFS                          (10)                            /* !< TCF Offset */
#define MCAN_IR_TCF_MASK                         ((uint32_t)0x00000400U)         /* !< Transmission Cancellation Finished
                                                                                    0  No transmission cancellation
                                                                                    finished   1  Transmission
                                                                                    cancellation finished */
/* MCAN_IR[TFE] Bits */
#define MCAN_IR_TFE_OFS                          (11)                            /* !< TFE Offset */
#define MCAN_IR_TFE_MASK                         ((uint32_t)0x00000800U)         /* !< Tx FIFO Empty   0  Tx FIFO
                                                                                    non-empty   1  Tx FIFO empty */
/* MCAN_IR[TEFN] Bits */
#define MCAN_IR_TEFN_OFS                         (12)                            /* !< TEFN Offset */
#define MCAN_IR_TEFN_MASK                        ((uint32_t)0x00001000U)         /* !< Tx Event FIFO New Entry   0  Tx
                                                                                    Event FIFO unchanged   1  Tx Handler
                                                                                    wrote Tx Event FIFO element */
/* MCAN_IR[TEFW] Bits */
#define MCAN_IR_TEFW_OFS                         (13)                            /* !< TEFW Offset */
#define MCAN_IR_TEFW_MASK                        ((uint32_t)0x00002000U)         /* !< Tx Event FIFO Watermark Reached   0
                                                                                    Tx Event FIFO fill level below
                                                                                    watermark   1  Tx Event FIFO fill
                                                                                    level reached watermark */
/* MCAN_IR[TEFF] Bits */
#define MCAN_IR_TEFF_OFS                         (14)                            /* !< TEFF Offset */
#define MCAN_IR_TEFF_MASK                        ((uint32_t)0x00004000U)         /* !< Tx Event FIFO Full   0  Tx Event
                                                                                    FIFO not full   1  Tx Event FIFO full */
/* MCAN_IR[TEFL] Bits */
#define MCAN_IR_TEFL_OFS                         (15)                            /* !< TEFL Offset */
#define MCAN_IR_TEFL_MASK                        ((uint32_t)0x00008000U)         /* !< Tx Event FIFO Element Lost   0  No
                                                                                    Tx Event FIFO element lost   1  Tx
                                                                                    Event FIFO element lost, also set
                                                                                    after write attempt to Tx Event FIFO
                                                                                    of size zero */
/* MCAN_IR[TSW] Bits */
#define MCAN_IR_TSW_OFS                          (16)                            /* !< TSW Offset */
#define MCAN_IR_TSW_MASK                         ((uint32_t)0x00010000U)         /* !< Timestamp Wraparound   0  No
                                                                                    timestamp counter wrap-around   1
                                                                                    Timestamp counter wrapped around */
/* MCAN_IR[MRAF] Bits */
#define MCAN_IR_MRAF_OFS                         (17)                            /* !< MRAF Offset */
#define MCAN_IR_MRAF_MASK                        ((uint32_t)0x00020000U)         /* !< Message RAM Access Failure.  The
                                                                                    flag is set, when the Rx Handler:   -
                                                                                    has not completed acceptance
                                                                                    filtering or storage of an accepted
                                                                                    message until the arbitration field
                                                                                    of the following message has been
                                                                                    received. In this case acceptance
                                                                                    filtering or message storage is
                                                                                    aborted and the Rx Handler starts
                                                                                    processing of the following message.
                                                                                    - was not able to write a message to
                                                                                    the Message RAM. In this case message
                                                                                    storage is aborted.   In both cases
                                                                                    the FIFO put index is not updated
                                                                                    resp. the New Data flag for a
                                                                                    dedicated Rx Buffer is not set, a
                                                                                    partly stored message is overwritten
                                                                                    when the next message is stored to
                                                                                    this location.   The flag is also set
                                                                                    when the Tx Handler was not able to
                                                                                    read a message from the Message RAM
                                                                                    in time. In this case message
                                                                                    transmission is aborted. In case of a
                                                                                    Tx Handler access failure the MCAN is
                                                                                    switched into Restricted Operation
                                                                                    Mode. To leave Restricted Operation
                                                                                    Mode, the Host CPU has to reset
                                                                                    CCCR.ASM.   0  No Message RAM access
                                                                                    failure occurred   1  Message RAM
                                                                                    access failure occurred */
/* MCAN_IR[TOO] Bits */
#define MCAN_IR_TOO_OFS                          (18)                            /* !< TOO Offset */
#define MCAN_IR_TOO_MASK                         ((uint32_t)0x00040000U)         /* !< Timeout Occurred   0  No timeout
                                                                                    1  Timeout reached */
/* MCAN_IR[DRX] Bits */
#define MCAN_IR_DRX_OFS                          (19)                            /* !< DRX Offset */
#define MCAN_IR_DRX_MASK                         ((uint32_t)0x00080000U)         /* !< Message Stored to Dedicated Rx
                                                                                    Buffer. The flag is set whenever a
                                                                                    received message has been stored into
                                                                                    a dedicated Rx Buffer.   0  No Rx
                                                                                    Buffer updated   1  At least one
                                                                                    received message stored into an Rx
                                                                                    Buffer */
/* MCAN_IR[BEU] Bits */
#define MCAN_IR_BEU_OFS                          (21)                            /* !< BEU Offset */
#define MCAN_IR_BEU_MASK                         ((uint32_t)0x00200000U)         /* !< Bit Error Uncorrected. Message RAM
                                                                                    bit error detected, uncorrected. This
                                                                                    bit is set when a double bit error is
                                                                                    detected by the ECC aggregator
                                                                                    attached to the Message RAM. An
                                                                                    uncorrected Message RAM bit error
                                                                                    sets CCCR.INIT to '1'. This is done
                                                                                    to avoid transmission of corrupted
                                                                                    data.   0  No bit error detected when
                                                                                    reading from Message RAM   1  Bit
                                                                                    error detected, uncorrected (e.g.
                                                                                    parity logic) */
/* MCAN_IR[ELO] Bits */
#define MCAN_IR_ELO_OFS                          (22)                            /* !< ELO Offset */
#define MCAN_IR_ELO_MASK                         ((uint32_t)0x00400000U)         /* !< Error Logging Overflow   0  CAN
                                                                                    Error Logging Counter did not
                                                                                    overflow   1  Overflow of CAN Error
                                                                                    Logging Counter occurred */
/* MCAN_IR[EP] Bits */
#define MCAN_IR_EP_OFS                           (23)                            /* !< EP Offset */
#define MCAN_IR_EP_MASK                          ((uint32_t)0x00800000U)         /* !< Error Passive   0  Error_Passive
                                                                                    status unchanged   1  Error_Passive
                                                                                    status changed */
/* MCAN_IR[EW] Bits */
#define MCAN_IR_EW_OFS                           (24)                            /* !< EW Offset */
#define MCAN_IR_EW_MASK                          ((uint32_t)0x01000000U)         /* !< Warning Status   0  Error_Warning
                                                                                    status unchanged   1  Error_Warning
                                                                                    status changed */
/* MCAN_IR[BO] Bits */
#define MCAN_IR_BO_OFS                           (25)                            /* !< BO Offset */
#define MCAN_IR_BO_MASK                          ((uint32_t)0x02000000U)         /* !< Bus_Off Status   0  Bus_Off status
                                                                                    unchanged   1  Bus_Off status changed */
/* MCAN_IR[WDI] Bits */
#define MCAN_IR_WDI_OFS                          (26)                            /* !< WDI Offset */
#define MCAN_IR_WDI_MASK                         ((uint32_t)0x04000000U)         /* !< Watchdog Interrupt   0  No Message
                                                                                    RAM Watchdog event occurred   1
                                                                                    Message RAM Watchdog event due to
                                                                                    missing READY */
/* MCAN_IR[PEA] Bits */
#define MCAN_IR_PEA_OFS                          (27)                            /* !< PEA Offset */
#define MCAN_IR_PEA_MASK                         ((uint32_t)0x08000000U)         /* !< Protocol Error in Arbitration Phase
                                                                                    (Nominal Bit Time is used)   0  No
                                                                                    protocol error in arbitration phase
                                                                                    1  Protocol error in arbitration
                                                                                    phase detected (PSR.LEC ? 0,7) */
/* MCAN_IR[PED] Bits */
#define MCAN_IR_PED_OFS                          (28)                            /* !< PED Offset */
#define MCAN_IR_PED_MASK                         ((uint32_t)0x10000000U)         /* !< Protocol Error in Data Phase (Data
                                                                                    Bit Time is used)   0  No protocol
                                                                                    error in data phase   1  Protocol
                                                                                    error in data phase detected
                                                                                    (PSR.DLEC ? 0,7) */
/* MCAN_IR[ARA] Bits */
#define MCAN_IR_ARA_OFS                          (29)                            /* !< ARA Offset */
#define MCAN_IR_ARA_MASK                         ((uint32_t)0x20000000U)         /* !< Access to Reserved Address   0  No
                                                                                    access to reserved address occurred
                                                                                    1  Access to reserved address
                                                                                    occurred */

/* MCAN_IE Bits */
/* MCAN_IE[RF0NE] Bits */
#define MCAN_IE_RF0NE_OFS                        (0)                             /* !< RF0NE Offset */
#define MCAN_IE_RF0NE_MASK                       ((uint32_t)0x00000001U)         /* !< Rx FIFO 0 New Message Enable */
/* MCAN_IE[RF0WE] Bits */
#define MCAN_IE_RF0WE_OFS                        (1)                             /* !< RF0WE Offset */
#define MCAN_IE_RF0WE_MASK                       ((uint32_t)0x00000002U)         /* !< Rx FIFO 0 Watermark Reached Enable */
/* MCAN_IE[RF0FE] Bits */
#define MCAN_IE_RF0FE_OFS                        (2)                             /* !< RF0FE Offset */
#define MCAN_IE_RF0FE_MASK                       ((uint32_t)0x00000004U)         /* !< Rx FIFO 0 Full Enable */
/* MCAN_IE[RF0LE] Bits */
#define MCAN_IE_RF0LE_OFS                        (3)                             /* !< RF0LE Offset */
#define MCAN_IE_RF0LE_MASK                       ((uint32_t)0x00000008U)         /* !< Rx FIFO 0 Message Lost Enable */
/* MCAN_IE[RF1NE] Bits */
#define MCAN_IE_RF1NE_OFS                        (4)                             /* !< RF1NE Offset */
#define MCAN_IE_RF1NE_MASK                       ((uint32_t)0x00000010U)         /* !< Rx FIFO 1 New Message Enable */
/* MCAN_IE[RF1WE] Bits */
#define MCAN_IE_RF1WE_OFS                        (5)                             /* !< RF1WE Offset */
#define MCAN_IE_RF1WE_MASK                       ((uint32_t)0x00000020U)         /* !< Rx FIFO 1 Watermark Reached Enable */
/* MCAN_IE[RF1FE] Bits */
#define MCAN_IE_RF1FE_OFS                        (6)                             /* !< RF1FE Offset */
#define MCAN_IE_RF1FE_MASK                       ((uint32_t)0x00000040U)         /* !< Rx FIFO 1 Full Enable */
/* MCAN_IE[RF1LE] Bits */
#define MCAN_IE_RF1LE_OFS                        (7)                             /* !< RF1LE Offset */
#define MCAN_IE_RF1LE_MASK                       ((uint32_t)0x00000080U)         /* !< Rx FIFO 1 Message Lost Enable */
/* MCAN_IE[HPME] Bits */
#define MCAN_IE_HPME_OFS                         (8)                             /* !< HPME Offset */
#define MCAN_IE_HPME_MASK                        ((uint32_t)0x00000100U)         /* !< High Priority Message Enable */
/* MCAN_IE[TCE] Bits */
#define MCAN_IE_TCE_OFS                          (9)                             /* !< TCE Offset */
#define MCAN_IE_TCE_MASK                         ((uint32_t)0x00000200U)         /* !< Transmission Completed Enable */
/* MCAN_IE[TCFE] Bits */
#define MCAN_IE_TCFE_OFS                         (10)                            /* !< TCFE Offset */
#define MCAN_IE_TCFE_MASK                        ((uint32_t)0x00000400U)         /* !< Transmission Cancellation Finished
                                                                                    Enable */
/* MCAN_IE[TFEE] Bits */
#define MCAN_IE_TFEE_OFS                         (11)                            /* !< TFEE Offset */
#define MCAN_IE_TFEE_MASK                        ((uint32_t)0x00000800U)         /* !< Tx FIFO Empty Enable */
/* MCAN_IE[TEFNE] Bits */
#define MCAN_IE_TEFNE_OFS                        (12)                            /* !< TEFNE Offset */
#define MCAN_IE_TEFNE_MASK                       ((uint32_t)0x00001000U)         /* !< Tx Event FIFO New Entry Enable */
/* MCAN_IE[TEFWE] Bits */
#define MCAN_IE_TEFWE_OFS                        (13)                            /* !< TEFWE Offset */
#define MCAN_IE_TEFWE_MASK                       ((uint32_t)0x00002000U)         /* !< Tx Event FIFO Watermark Reached
                                                                                    Enable */
/* MCAN_IE[TEFFE] Bits */
#define MCAN_IE_TEFFE_OFS                        (14)                            /* !< TEFFE Offset */
#define MCAN_IE_TEFFE_MASK                       ((uint32_t)0x00004000U)         /* !< Tx Event FIFO Full Enable */
/* MCAN_IE[TEFLE] Bits */
#define MCAN_IE_TEFLE_OFS                        (15)                            /* !< TEFLE Offset */
#define MCAN_IE_TEFLE_MASK                       ((uint32_t)0x00008000U)         /* !< Tx Event FIFO Element Lost Enable */
/* MCAN_IE[TSWE] Bits */
#define MCAN_IE_TSWE_OFS                         (16)                            /* !< TSWE Offset */
#define MCAN_IE_TSWE_MASK                        ((uint32_t)0x00010000U)         /* !< Timestamp Wraparound Enable */
/* MCAN_IE[MRAFE] Bits */
#define MCAN_IE_MRAFE_OFS                        (17)                            /* !< MRAFE Offset */
#define MCAN_IE_MRAFE_MASK                       ((uint32_t)0x00020000U)         /* !< Message RAM Access Failure Enable */
/* MCAN_IE[TOOE] Bits */
#define MCAN_IE_TOOE_OFS                         (18)                            /* !< TOOE Offset */
#define MCAN_IE_TOOE_MASK                        ((uint32_t)0x00040000U)         /* !< Timeout Occurred Enable */
/* MCAN_IE[DRXE] Bits */
#define MCAN_IE_DRXE_OFS                         (19)                            /* !< DRXE Offset */
#define MCAN_IE_DRXE_MASK                        ((uint32_t)0x00080000U)         /* !< Message Stored to Dedicated Rx
                                                                                    Buffer Enable */
/* MCAN_IE[BECE] Bits */
#define MCAN_IE_BECE_OFS                         (20)                            /* !< BECE Offset */
#define MCAN_IE_BECE_MASK                        ((uint32_t)0x00100000U)         /* !< Bit Error Corrected Enable   A
                                                                                    separate interrupt line reserved for
                                                                                    corrected bit errors is provided via
                                                                                    the MCAN_ERROR_REGS. It advised for
                                                                                    the user to use these registers and
                                                                                    leave this bit cleared to '0'. */
/* MCAN_IE[BEUE] Bits */
#define MCAN_IE_BEUE_OFS                         (21)                            /* !< BEUE Offset */
#define MCAN_IE_BEUE_MASK                        ((uint32_t)0x00200000U)         /* !< Bit Error Uncorrected Enable */
/* MCAN_IE[ELOE] Bits */
#define MCAN_IE_ELOE_OFS                         (22)                            /* !< ELOE Offset */
#define MCAN_IE_ELOE_MASK                        ((uint32_t)0x00400000U)         /* !< Error Logging Overflow Enable */
/* MCAN_IE[EPE] Bits */
#define MCAN_IE_EPE_OFS                          (23)                            /* !< EPE Offset */
#define MCAN_IE_EPE_MASK                         ((uint32_t)0x00800000U)         /* !< Error Passive Enable */
/* MCAN_IE[EWE] Bits */
#define MCAN_IE_EWE_OFS                          (24)                            /* !< EWE Offset */
#define MCAN_IE_EWE_MASK                         ((uint32_t)0x01000000U)         /* !< Warning Status Enable */
/* MCAN_IE[BOE] Bits */
#define MCAN_IE_BOE_OFS                          (25)                            /* !< BOE Offset */
#define MCAN_IE_BOE_MASK                         ((uint32_t)0x02000000U)         /* !< Bus_Off Status Enable */
/* MCAN_IE[WDIE] Bits */
#define MCAN_IE_WDIE_OFS                         (26)                            /* !< WDIE Offset */
#define MCAN_IE_WDIE_MASK                        ((uint32_t)0x04000000U)         /* !< Watchdog Interrupt Enable */
/* MCAN_IE[PEAE] Bits */
#define MCAN_IE_PEAE_OFS                         (27)                            /* !< PEAE Offset */
#define MCAN_IE_PEAE_MASK                        ((uint32_t)0x08000000U)         /* !< Protocol Error in Arbitration Phase
                                                                                    Enable */
/* MCAN_IE[PEDE] Bits */
#define MCAN_IE_PEDE_OFS                         (28)                            /* !< PEDE Offset */
#define MCAN_IE_PEDE_MASK                        ((uint32_t)0x10000000U)         /* !< Protocol Error in Data Phase Enable */
/* MCAN_IE[ARAE] Bits */
#define MCAN_IE_ARAE_OFS                         (29)                            /* !< ARAE Offset */
#define MCAN_IE_ARAE_MASK                        ((uint32_t)0x20000000U)         /* !< Access to Reserved Address Enable */

/* MCAN_ILS Bits */
/* MCAN_ILS[RF0NL] Bits */
#define MCAN_ILS_RF0NL_OFS                       (0)                             /* !< RF0NL Offset */
#define MCAN_ILS_RF0NL_MASK                      ((uint32_t)0x00000001U)         /* !< Rx FIFO 0 New Message Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[RF0WL] Bits */
#define MCAN_ILS_RF0WL_OFS                       (1)                             /* !< RF0WL Offset */
#define MCAN_ILS_RF0WL_MASK                      ((uint32_t)0x00000002U)         /* !< Rx FIFO 0 Watermark Reached Line
                                                                                    0  Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[RF0FL] Bits */
#define MCAN_ILS_RF0FL_OFS                       (2)                             /* !< RF0FL Offset */
#define MCAN_ILS_RF0FL_MASK                      ((uint32_t)0x00000004U)         /* !< Rx FIFO 0 Full Line   0  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    0   1  Interrupt source is assigned
                                                                                    to Interrupt Line 1 */
/* MCAN_ILS[RF0LL] Bits */
#define MCAN_ILS_RF0LL_OFS                       (3)                             /* !< RF0LL Offset */
#define MCAN_ILS_RF0LL_MASK                      ((uint32_t)0x00000008U)         /* !< Rx FIFO 0 Message Lost Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[RF1NL] Bits */
#define MCAN_ILS_RF1NL_OFS                       (4)                             /* !< RF1NL Offset */
#define MCAN_ILS_RF1NL_MASK                      ((uint32_t)0x00000010U)         /* !< Rx FIFO 1 New Message Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[RF1WL] Bits */
#define MCAN_ILS_RF1WL_OFS                       (5)                             /* !< RF1WL Offset */
#define MCAN_ILS_RF1WL_MASK                      ((uint32_t)0x00000020U)         /* !< Rx FIFO 1 Watermark Reached Line
                                                                                    0  Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[RF1FL] Bits */
#define MCAN_ILS_RF1FL_OFS                       (6)                             /* !< RF1FL Offset */
#define MCAN_ILS_RF1FL_MASK                      ((uint32_t)0x00000040U)         /* !< Rx FIFO 1 Full Line   0  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    0   1  Interrupt source is assigned
                                                                                    to Interrupt Line 1 */
/* MCAN_ILS[RF1LL] Bits */
#define MCAN_ILS_RF1LL_OFS                       (7)                             /* !< RF1LL Offset */
#define MCAN_ILS_RF1LL_MASK                      ((uint32_t)0x00000080U)         /* !< Rx FIFO 1 Message Lost Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[HPML] Bits */
#define MCAN_ILS_HPML_OFS                        (8)                             /* !< HPML Offset */
#define MCAN_ILS_HPML_MASK                       ((uint32_t)0x00000100U)         /* !< High Priority Message Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[TCL] Bits */
#define MCAN_ILS_TCL_OFS                         (9)                             /* !< TCL Offset */
#define MCAN_ILS_TCL_MASK                        ((uint32_t)0x00000200U)         /* !< Transmission Completed Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[TCFL] Bits */
#define MCAN_ILS_TCFL_OFS                        (10)                            /* !< TCFL Offset */
#define MCAN_ILS_TCFL_MASK                       ((uint32_t)0x00000400U)         /* !< Transmission Cancellation Finished
                                                                                    Line   0  Interrupt source is
                                                                                    assigned to Interrupt Line 0   1
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 1 */
/* MCAN_ILS[TFEL] Bits */
#define MCAN_ILS_TFEL_OFS                        (11)                            /* !< TFEL Offset */
#define MCAN_ILS_TFEL_MASK                       ((uint32_t)0x00000800U)         /* !< Tx FIFO Empty Line   0  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    0   1  Interrupt source is assigned
                                                                                    to Interrupt Line 1 */
/* MCAN_ILS[TEFNL] Bits */
#define MCAN_ILS_TEFNL_OFS                       (12)                            /* !< TEFNL Offset */
#define MCAN_ILS_TEFNL_MASK                      ((uint32_t)0x00001000U)         /* !< Tx Event FIFO New Entry Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[TEFWL] Bits */
#define MCAN_ILS_TEFWL_OFS                       (13)                            /* !< TEFWL Offset */
#define MCAN_ILS_TEFWL_MASK                      ((uint32_t)0x00002000U)         /* !< Tx Event FIFO Watermark Reached
                                                                                    Line   0  Interrupt source is
                                                                                    assigned to Interrupt Line 0   1
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 1 */
/* MCAN_ILS[TEFFL] Bits */
#define MCAN_ILS_TEFFL_OFS                       (14)                            /* !< TEFFL Offset */
#define MCAN_ILS_TEFFL_MASK                      ((uint32_t)0x00004000U)         /* !< Tx Event FIFO Full Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[TEFLL] Bits */
#define MCAN_ILS_TEFLL_OFS                       (15)                            /* !< TEFLL Offset */
#define MCAN_ILS_TEFLL_MASK                      ((uint32_t)0x00008000U)         /* !< Tx Event FIFO Element Lost Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[TSWL] Bits */
#define MCAN_ILS_TSWL_OFS                        (16)                            /* !< TSWL Offset */
#define MCAN_ILS_TSWL_MASK                       ((uint32_t)0x00010000U)         /* !< Timestamp Wraparound Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[MRAFL] Bits */
#define MCAN_ILS_MRAFL_OFS                       (17)                            /* !< MRAFL Offset */
#define MCAN_ILS_MRAFL_MASK                      ((uint32_t)0x00020000U)         /* !< Message RAM Access Failure Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[TOOL] Bits */
#define MCAN_ILS_TOOL_OFS                        (18)                            /* !< TOOL Offset */
#define MCAN_ILS_TOOL_MASK                       ((uint32_t)0x00040000U)         /* !< Timeout Occurred Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[DRXL] Bits */
#define MCAN_ILS_DRXL_OFS                        (19)                            /* !< DRXL Offset */
#define MCAN_ILS_DRXL_MASK                       ((uint32_t)0x00080000U)         /* !< Message Stored to Dedicated Rx
                                                                                    Buffer Line   0  Interrupt source is
                                                                                    assigned to Interrupt Line 0   1
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 1 */
/* MCAN_ILS[BECL] Bits */
#define MCAN_ILS_BECL_OFS                        (20)                            /* !< BECL Offset */
#define MCAN_ILS_BECL_MASK                       ((uint32_t)0x00100000U)         /* !< Bit Error Corrected Line   A
                                                                                    separate interrupt line reserved for
                                                                                    corrected bit errors is provided via
                                                                                    the MCAN_ERROR_REGS. It advised for
                                                                                    the user to use these registers and
                                                                                    leave the MCAN_IE.BECE bit cleared to
                                                                                    '0' (disabled), thereby relegating
                                                                                    this bit to not applicable. */
/* MCAN_ILS[BEUL] Bits */
#define MCAN_ILS_BEUL_OFS                        (21)                            /* !< BEUL Offset */
#define MCAN_ILS_BEUL_MASK                       ((uint32_t)0x00200000U)         /* !< Bit Error Uncorrected Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[ELOL] Bits */
#define MCAN_ILS_ELOL_OFS                        (22)                            /* !< ELOL Offset */
#define MCAN_ILS_ELOL_MASK                       ((uint32_t)0x00400000U)         /* !< Error Logging Overflow Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[EPL] Bits */
#define MCAN_ILS_EPL_OFS                         (23)                            /* !< EPL Offset */
#define MCAN_ILS_EPL_MASK                        ((uint32_t)0x00800000U)         /* !< Error Passive Line   0  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    0   1  Interrupt source is assigned
                                                                                    to Interrupt Line 1 */
/* MCAN_ILS[EWL] Bits */
#define MCAN_ILS_EWL_OFS                         (24)                            /* !< EWL Offset */
#define MCAN_ILS_EWL_MASK                        ((uint32_t)0x01000000U)         /* !< Warning Status Line   0  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    0   1  Interrupt source is assigned
                                                                                    to Interrupt Line 1 */
/* MCAN_ILS[BOL] Bits */
#define MCAN_ILS_BOL_OFS                         (25)                            /* !< BOL Offset */
#define MCAN_ILS_BOL_MASK                        ((uint32_t)0x02000000U)         /* !< Bus_Off Status Line   0  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    0   1  Interrupt source is assigned
                                                                                    to Interrupt Line 1 */
/* MCAN_ILS[WDIL] Bits */
#define MCAN_ILS_WDIL_OFS                        (26)                            /* !< WDIL Offset */
#define MCAN_ILS_WDIL_MASK                       ((uint32_t)0x04000000U)         /* !< Watchdog Interrupt Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[PEAL] Bits */
#define MCAN_ILS_PEAL_OFS                        (27)                            /* !< PEAL Offset */
#define MCAN_ILS_PEAL_MASK                       ((uint32_t)0x08000000U)         /* !< Protocol Error in Arbitration Phase
                                                                                    Line   0  Interrupt source is
                                                                                    assigned to Interrupt Line 0   1
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 1 */
/* MCAN_ILS[PEDL] Bits */
#define MCAN_ILS_PEDL_OFS                        (28)                            /* !< PEDL Offset */
#define MCAN_ILS_PEDL_MASK                       ((uint32_t)0x10000000U)         /* !< Protocol Error in Data Phase Line
                                                                                    0  Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */
/* MCAN_ILS[ARAL] Bits */
#define MCAN_ILS_ARAL_OFS                        (29)                            /* !< ARAL Offset */
#define MCAN_ILS_ARAL_MASK                       ((uint32_t)0x20000000U)         /* !< Access to Reserved Address Line   0
                                                                                    Interrupt source is assigned to
                                                                                    Interrupt Line 0   1  Interrupt
                                                                                    source is assigned to Interrupt Line
                                                                                    1 */

/* MCAN_ILE Bits */
/* MCAN_ILE[EINT0] Bits */
#define MCAN_ILE_EINT0_OFS                       (0)                             /* !< EINT0 Offset */
#define MCAN_ILE_EINT0_MASK                      ((uint32_t)0x00000001U)         /* !< Enable Interrupt Line 0   0
                                                                                    Interrupt Line 0 is disabled   1
                                                                                    Interrupt Line 0 is enabled */
/* MCAN_ILE[EINT1] Bits */
#define MCAN_ILE_EINT1_OFS                       (1)                             /* !< EINT1 Offset */
#define MCAN_ILE_EINT1_MASK                      ((uint32_t)0x00000002U)         /* !< Enable Interrupt Line 1   0
                                                                                    Interrupt Line 1 is disabled   1
                                                                                    Interrupt Line 1 is enabled */

/* MCAN_GFC Bits */
/* MCAN_GFC[RRFE] Bits */
#define MCAN_GFC_RRFE_OFS                        (0)                             /* !< RRFE Offset */
#define MCAN_GFC_RRFE_MASK                       ((uint32_t)0x00000001U)         /* !< Reject Remote Frames Extended   0
                                                                                    Filter remote frames with 29-bit
                                                                                    extended IDs   1  Reject all remote
                                                                                    frames with 29-bit extended IDs
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_GFC[RRFS] Bits */
#define MCAN_GFC_RRFS_OFS                        (1)                             /* !< RRFS Offset */
#define MCAN_GFC_RRFS_MASK                       ((uint32_t)0x00000002U)         /* !< Reject Remote Frames Standard   0
                                                                                    Filter remote frames with 11-bit
                                                                                    standard IDs   1  Reject all remote
                                                                                    frames with 11-bit standard IDs
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_GFC[ANFE] Bits */
#define MCAN_GFC_ANFE_OFS                        (2)                             /* !< ANFE Offset */
#define MCAN_GFC_ANFE_MASK                       ((uint32_t)0x0000000CU)         /* !< Accept Non-matching Frames
                                                                                    Extended. Defines how received
                                                                                    messages with 29-bit IDs that do not
                                                                                    match any element of the filter list
                                                                                    are treated.   00  Accept in Rx FIFO
                                                                                    0   01  Accept in Rx FIFO 1   10
                                                                                    Reject   11  Reject   Qualified Write
                                                                                    is possible only with CCCR.CCE='1'
                                                                                    and CCCR.INIT='1'. */
/* MCAN_GFC[ANFS] Bits */
#define MCAN_GFC_ANFS_OFS                        (4)                             /* !< ANFS Offset */
#define MCAN_GFC_ANFS_MASK                       ((uint32_t)0x00000030U)         /* !< Accept Non-matching Frames
                                                                                    Standard. Defines how received
                                                                                    messages with 11-bit IDs that do not
                                                                                    match any element of the filter list
                                                                                    are treated.   00  Accept in Rx FIFO
                                                                                    0   01  Accept in Rx FIFO 1   10
                                                                                    Reject   11  Reject   Qualified Write
                                                                                    is possible only with CCCR.CCE='1'
                                                                                    and CCCR.INIT='1'. */

/* MCAN_SIDFC Bits */
/* MCAN_SIDFC[FLSSA] Bits */
#define MCAN_SIDFC_FLSSA_OFS                     (2)                             /* !< FLSSA Offset */
#define MCAN_SIDFC_FLSSA_MASK                    ((uint32_t)0x0000FFFCU)         /* !< Filter List Standard Start Address.
                                                                                    Start address of standard Message ID
                                                                                    filter list (32-bit word address). */
/* MCAN_SIDFC[LSS] Bits */
#define MCAN_SIDFC_LSS_OFS                       (16)                            /* !< LSS Offset */
#define MCAN_SIDFC_LSS_MASK                      ((uint32_t)0x00FF0000U)         /* !< List Size Standard   0        No
                                                                                    standard Message ID filter   1-128
                                                                                    Number of standard Message ID filter
                                                                                    elements   >128   Values greater than
                                                                                    128 are interpreted as 128 */

/* MCAN_XIDFC Bits */
/* MCAN_XIDFC[FLESA] Bits */
#define MCAN_XIDFC_FLESA_OFS                     (2)                             /* !< FLESA Offset */
#define MCAN_XIDFC_FLESA_MASK                    ((uint32_t)0x0000FFFCU)         /* !< List Size Extended   0     No
                                                                                    extended Message ID filter   1-64
                                                                                    Number of extended Message ID filter
                                                                                    elements   >64  Values greater than
                                                                                    64 are interpreted as 64   Qualified
                                                                                    Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_XIDFC[LSE] Bits */
#define MCAN_XIDFC_LSE_OFS                       (16)                            /* !< LSE Offset */
#define MCAN_XIDFC_LSE_MASK                      ((uint32_t)0x007F0000U)         /* !< Filter List Extended Start Address.
                                                                                    Start address of extended Message ID
                                                                                    filter list (32-bit word address).
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */

/* MCAN_XIDAM Bits */
/* MCAN_XIDAM[EIDM] Bits */
#define MCAN_XIDAM_EIDM_OFS                      (0)                             /* !< EIDM Offset */
#define MCAN_XIDAM_EIDM_MASK                     ((uint32_t)0x1FFFFFFFU)         /* !< Extended ID Mask. For acceptance
                                                                                    filtering of extended frames the
                                                                                    Extended ID AND Mask is ANDed with
                                                                                    the Message ID of a received frame.
                                                                                    Intended for masking of 29-bit IDs in
                                                                                    SAE J1939. With the reset value of
                                                                                    all bits set to one the mask is not
                                                                                    active.   Qualified Write is possible
                                                                                    only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */

/* MCAN_HPMS Bits */
/* MCAN_HPMS[BIDX] Bits */
#define MCAN_HPMS_BIDX_OFS                       (0)                             /* !< BIDX Offset */
#define MCAN_HPMS_BIDX_MASK                      ((uint32_t)0x0000003FU)         /* !< Buffer Index. Index of Rx FIFO
                                                                                    element to which the message was
                                                                                    stored. Only valid when MSI(1) = '1'. */
/* MCAN_HPMS[MSI] Bits */
#define MCAN_HPMS_MSI_OFS                        (6)                             /* !< MSI Offset */
#define MCAN_HPMS_MSI_MASK                       ((uint32_t)0x000000C0U)         /* !< Message Storage Indicator   00  No
                                                                                    FIFO selected   01  FIFO message lost
                                                                                    10  Message stored in FIFO 0   11
                                                                                    Message stored in FIFO 1 */
/* MCAN_HPMS[FIDX] Bits */
#define MCAN_HPMS_FIDX_OFS                       (8)                             /* !< FIDX Offset */
#define MCAN_HPMS_FIDX_MASK                      ((uint32_t)0x00007F00U)         /* !< Filter Index. Index of matching
                                                                                    filter element. Range is 0 to
                                                                                    SIDFC.LSS - 1 resp. XIDFC.LSE - 1. */
/* MCAN_HPMS[FLST] Bits */
#define MCAN_HPMS_FLST_OFS                       (15)                            /* !< FLST Offset */
#define MCAN_HPMS_FLST_MASK                      ((uint32_t)0x00008000U)         /* !< Filter List. Indicates the filter
                                                                                    list of the matching filter element.
                                                                                    0  Standard Filter List   1
                                                                                    Extended Filter List */

/* MCAN_NDAT1 Bits */
/* MCAN_NDAT1[ND0] Bits */
#define MCAN_NDAT1_ND0_OFS                       (0)                             /* !< ND0 Offset */
#define MCAN_NDAT1_ND0_MASK                      ((uint32_t)0x00000001U)         /* !< New Data RX Buffer 0   0  Rx Buffer
                                                                                    not updated   1  Rx Buffer updated
                                                                                    from new message */
/* MCAN_NDAT1[ND1] Bits */
#define MCAN_NDAT1_ND1_OFS                       (1)                             /* !< ND1 Offset */
#define MCAN_NDAT1_ND1_MASK                      ((uint32_t)0x00000002U)         /* !< New Data RX Buffer 1   0  Rx Buffer
                                                                                    not updated   1  Rx Buffer updated
                                                                                    from new message */
/* MCAN_NDAT1[ND2] Bits */
#define MCAN_NDAT1_ND2_OFS                       (2)                             /* !< ND2 Offset */
#define MCAN_NDAT1_ND2_MASK                      ((uint32_t)0x00000004U)         /* !< New Data RX Buffer 2   0  Rx Buffer
                                                                                    not updated   1  Rx Buffer updated
                                                                                    from new message */
/* MCAN_NDAT1[ND3] Bits */
#define MCAN_NDAT1_ND3_OFS                       (3)                             /* !< ND3 Offset */
#define MCAN_NDAT1_ND3_MASK                      ((uint32_t)0x00000008U)         /* !< New Data RX Buffer 3   0  Rx Buffer
                                                                                    not updated   1  Rx Buffer updated
                                                                                    from new message */
/* MCAN_NDAT1[ND4] Bits */
#define MCAN_NDAT1_ND4_OFS                       (4)                             /* !< ND4 Offset */
#define MCAN_NDAT1_ND4_MASK                      ((uint32_t)0x00000010U)         /* !< New Data RX Buffer 4   0  Rx Buffer
                                                                                    not updated   1  Rx Buffer updated
                                                                                    from new message */
/* MCAN_NDAT1[ND5] Bits */
#define MCAN_NDAT1_ND5_OFS                       (5)                             /* !< ND5 Offset */
#define MCAN_NDAT1_ND5_MASK                      ((uint32_t)0x00000020U)         /* !< New Data RX Buffer 5   0  Rx Buffer
                                                                                    not updated   1  Rx Buffer updated
                                                                                    from new message */
/* MCAN_NDAT1[ND6] Bits */
#define MCAN_NDAT1_ND6_OFS                       (6)                             /* !< ND6 Offset */
#define MCAN_NDAT1_ND6_MASK                      ((uint32_t)0x00000040U)         /* !< New Data RX Buffer 6   0  Rx Buffer
                                                                                    not updated   1  Rx Buffer updated
                                                                                    from new message */
/* MCAN_NDAT1[ND7] Bits */
#define MCAN_NDAT1_ND7_OFS                       (7)                             /* !< ND7 Offset */
#define MCAN_NDAT1_ND7_MASK                      ((uint32_t)0x00000080U)         /* !< New Data RX Buffer 7   0  Rx Buffer
                                                                                    not updated   1  Rx Buffer updated
                                                                                    from new message */
/* MCAN_NDAT1[ND8] Bits */
#define MCAN_NDAT1_ND8_OFS                       (8)                             /* !< ND8 Offset */
#define MCAN_NDAT1_ND8_MASK                      ((uint32_t)0x00000100U)         /* !< New Data RX Buffer 8   0  Rx Buffer
                                                                                    not updated   1  Rx Buffer updated
                                                                                    from new message */
/* MCAN_NDAT1[ND9] Bits */
#define MCAN_NDAT1_ND9_OFS                       (9)                             /* !< ND9 Offset */
#define MCAN_NDAT1_ND9_MASK                      ((uint32_t)0x00000200U)         /* !< New Data RX Buffer 9   0  Rx Buffer
                                                                                    not updated   1  Rx Buffer updated
                                                                                    from new message */
/* MCAN_NDAT1[ND10] Bits */
#define MCAN_NDAT1_ND10_OFS                      (10)                            /* !< ND10 Offset */
#define MCAN_NDAT1_ND10_MASK                     ((uint32_t)0x00000400U)         /* !< New Data RX Buffer 10   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND11] Bits */
#define MCAN_NDAT1_ND11_OFS                      (11)                            /* !< ND11 Offset */
#define MCAN_NDAT1_ND11_MASK                     ((uint32_t)0x00000800U)         /* !< New Data RX Buffer 11   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND12] Bits */
#define MCAN_NDAT1_ND12_OFS                      (12)                            /* !< ND12 Offset */
#define MCAN_NDAT1_ND12_MASK                     ((uint32_t)0x00001000U)         /* !< New Data RX Buffer 12   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND13] Bits */
#define MCAN_NDAT1_ND13_OFS                      (13)                            /* !< ND13 Offset */
#define MCAN_NDAT1_ND13_MASK                     ((uint32_t)0x00002000U)         /* !< New Data RX Buffer 13   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND14] Bits */
#define MCAN_NDAT1_ND14_OFS                      (14)                            /* !< ND14 Offset */
#define MCAN_NDAT1_ND14_MASK                     ((uint32_t)0x00004000U)         /* !< New Data RX Buffer 14   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND15] Bits */
#define MCAN_NDAT1_ND15_OFS                      (15)                            /* !< ND15 Offset */
#define MCAN_NDAT1_ND15_MASK                     ((uint32_t)0x00008000U)         /* !< New Data RX Buffer 15   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND16] Bits */
#define MCAN_NDAT1_ND16_OFS                      (16)                            /* !< ND16 Offset */
#define MCAN_NDAT1_ND16_MASK                     ((uint32_t)0x00010000U)         /* !< New Data RX Buffer 16   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND17] Bits */
#define MCAN_NDAT1_ND17_OFS                      (17)                            /* !< ND17 Offset */
#define MCAN_NDAT1_ND17_MASK                     ((uint32_t)0x00020000U)         /* !< New Data RX Buffer 17   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND18] Bits */
#define MCAN_NDAT1_ND18_OFS                      (18)                            /* !< ND18 Offset */
#define MCAN_NDAT1_ND18_MASK                     ((uint32_t)0x00040000U)         /* !< New Data RX Buffer 18   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND19] Bits */
#define MCAN_NDAT1_ND19_OFS                      (19)                            /* !< ND19 Offset */
#define MCAN_NDAT1_ND19_MASK                     ((uint32_t)0x00080000U)         /* !< New Data RX Buffer 19   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND20] Bits */
#define MCAN_NDAT1_ND20_OFS                      (20)                            /* !< ND20 Offset */
#define MCAN_NDAT1_ND20_MASK                     ((uint32_t)0x00100000U)         /* !< New Data RX Buffer 20   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND21] Bits */
#define MCAN_NDAT1_ND21_OFS                      (21)                            /* !< ND21 Offset */
#define MCAN_NDAT1_ND21_MASK                     ((uint32_t)0x00200000U)         /* !< New Data RX Buffer 21   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND22] Bits */
#define MCAN_NDAT1_ND22_OFS                      (22)                            /* !< ND22 Offset */
#define MCAN_NDAT1_ND22_MASK                     ((uint32_t)0x00400000U)         /* !< New Data RX Buffer 22   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND23] Bits */
#define MCAN_NDAT1_ND23_OFS                      (23)                            /* !< ND23 Offset */
#define MCAN_NDAT1_ND23_MASK                     ((uint32_t)0x00800000U)         /* !< New Data RX Buffer 23   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND24] Bits */
#define MCAN_NDAT1_ND24_OFS                      (24)                            /* !< ND24 Offset */
#define MCAN_NDAT1_ND24_MASK                     ((uint32_t)0x01000000U)         /* !< New Data RX Buffer 24   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND25] Bits */
#define MCAN_NDAT1_ND25_OFS                      (25)                            /* !< ND25 Offset */
#define MCAN_NDAT1_ND25_MASK                     ((uint32_t)0x02000000U)         /* !< New Data RX Buffer 25   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND26] Bits */
#define MCAN_NDAT1_ND26_OFS                      (26)                            /* !< ND26 Offset */
#define MCAN_NDAT1_ND26_MASK                     ((uint32_t)0x04000000U)         /* !< New Data RX Buffer 26   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND27] Bits */
#define MCAN_NDAT1_ND27_OFS                      (27)                            /* !< ND27 Offset */
#define MCAN_NDAT1_ND27_MASK                     ((uint32_t)0x08000000U)         /* !< New Data RX Buffer 27   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND28] Bits */
#define MCAN_NDAT1_ND28_OFS                      (28)                            /* !< ND28 Offset */
#define MCAN_NDAT1_ND28_MASK                     ((uint32_t)0x10000000U)         /* !< New Data RX Buffer 28   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND29] Bits */
#define MCAN_NDAT1_ND29_OFS                      (29)                            /* !< ND29 Offset */
#define MCAN_NDAT1_ND29_MASK                     ((uint32_t)0x20000000U)         /* !< New Data RX Buffer 29   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND30] Bits */
#define MCAN_NDAT1_ND30_OFS                      (30)                            /* !< ND30 Offset */
#define MCAN_NDAT1_ND30_MASK                     ((uint32_t)0x40000000U)         /* !< New Data RX Buffer 30   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT1[ND31] Bits */
#define MCAN_NDAT1_ND31_OFS                      (31)                            /* !< ND31 Offset */
#define MCAN_NDAT1_ND31_MASK                     ((uint32_t)0x80000000U)         /* !< New Data RX Buffer 31   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */

/* MCAN_NDAT2 Bits */
/* MCAN_NDAT2[ND32] Bits */
#define MCAN_NDAT2_ND32_OFS                      (0)                             /* !< ND32 Offset */
#define MCAN_NDAT2_ND32_MASK                     ((uint32_t)0x00000001U)         /* !< New Data RX Buffer 32   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND33] Bits */
#define MCAN_NDAT2_ND33_OFS                      (1)                             /* !< ND33 Offset */
#define MCAN_NDAT2_ND33_MASK                     ((uint32_t)0x00000002U)         /* !< New Data RX Buffer 33   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND34] Bits */
#define MCAN_NDAT2_ND34_OFS                      (2)                             /* !< ND34 Offset */
#define MCAN_NDAT2_ND34_MASK                     ((uint32_t)0x00000004U)         /* !< New Data RX Buffer 34   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND35] Bits */
#define MCAN_NDAT2_ND35_OFS                      (3)                             /* !< ND35 Offset */
#define MCAN_NDAT2_ND35_MASK                     ((uint32_t)0x00000008U)         /* !< New Data RX Buffer 35   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND36] Bits */
#define MCAN_NDAT2_ND36_OFS                      (4)                             /* !< ND36 Offset */
#define MCAN_NDAT2_ND36_MASK                     ((uint32_t)0x00000010U)         /* !< New Data RX Buffer 36   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND37] Bits */
#define MCAN_NDAT2_ND37_OFS                      (5)                             /* !< ND37 Offset */
#define MCAN_NDAT2_ND37_MASK                     ((uint32_t)0x00000020U)         /* !< New Data RX Buffer 37   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND38] Bits */
#define MCAN_NDAT2_ND38_OFS                      (6)                             /* !< ND38 Offset */
#define MCAN_NDAT2_ND38_MASK                     ((uint32_t)0x00000040U)         /* !< New Data RX Buffer 38   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND39] Bits */
#define MCAN_NDAT2_ND39_OFS                      (7)                             /* !< ND39 Offset */
#define MCAN_NDAT2_ND39_MASK                     ((uint32_t)0x00000080U)         /* !< New Data RX Buffer 39   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND40] Bits */
#define MCAN_NDAT2_ND40_OFS                      (8)                             /* !< ND40 Offset */
#define MCAN_NDAT2_ND40_MASK                     ((uint32_t)0x00000100U)         /* !< New Data RX Buffer 40   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND41] Bits */
#define MCAN_NDAT2_ND41_OFS                      (9)                             /* !< ND41 Offset */
#define MCAN_NDAT2_ND41_MASK                     ((uint32_t)0x00000200U)         /* !< New Data RX Buffer 41   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND42] Bits */
#define MCAN_NDAT2_ND42_OFS                      (10)                            /* !< ND42 Offset */
#define MCAN_NDAT2_ND42_MASK                     ((uint32_t)0x00000400U)         /* !< New Data RX Buffer 42   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND43] Bits */
#define MCAN_NDAT2_ND43_OFS                      (11)                            /* !< ND43 Offset */
#define MCAN_NDAT2_ND43_MASK                     ((uint32_t)0x00000800U)         /* !< New Data RX Buffer 43   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND44] Bits */
#define MCAN_NDAT2_ND44_OFS                      (12)                            /* !< ND44 Offset */
#define MCAN_NDAT2_ND44_MASK                     ((uint32_t)0x00001000U)         /* !< New Data RX Buffer 44   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND45] Bits */
#define MCAN_NDAT2_ND45_OFS                      (13)                            /* !< ND45 Offset */
#define MCAN_NDAT2_ND45_MASK                     ((uint32_t)0x00002000U)         /* !< New Data RX Buffer 45   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND46] Bits */
#define MCAN_NDAT2_ND46_OFS                      (14)                            /* !< ND46 Offset */
#define MCAN_NDAT2_ND46_MASK                     ((uint32_t)0x00004000U)         /* !< New Data RX Buffer 46   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND47] Bits */
#define MCAN_NDAT2_ND47_OFS                      (15)                            /* !< ND47 Offset */
#define MCAN_NDAT2_ND47_MASK                     ((uint32_t)0x00008000U)         /* !< New Data RX Buffer 47   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND48] Bits */
#define MCAN_NDAT2_ND48_OFS                      (16)                            /* !< ND48 Offset */
#define MCAN_NDAT2_ND48_MASK                     ((uint32_t)0x00010000U)         /* !< New Data RX Buffer 48   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND49] Bits */
#define MCAN_NDAT2_ND49_OFS                      (17)                            /* !< ND49 Offset */
#define MCAN_NDAT2_ND49_MASK                     ((uint32_t)0x00020000U)         /* !< New Data RX Buffer 49   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND50] Bits */
#define MCAN_NDAT2_ND50_OFS                      (18)                            /* !< ND50 Offset */
#define MCAN_NDAT2_ND50_MASK                     ((uint32_t)0x00040000U)         /* !< New Data RX Buffer 50   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND51] Bits */
#define MCAN_NDAT2_ND51_OFS                      (19)                            /* !< ND51 Offset */
#define MCAN_NDAT2_ND51_MASK                     ((uint32_t)0x00080000U)         /* !< New Data RX Buffer 51   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND52] Bits */
#define MCAN_NDAT2_ND52_OFS                      (20)                            /* !< ND52 Offset */
#define MCAN_NDAT2_ND52_MASK                     ((uint32_t)0x00100000U)         /* !< New Data RX Buffer 52   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND53] Bits */
#define MCAN_NDAT2_ND53_OFS                      (21)                            /* !< ND53 Offset */
#define MCAN_NDAT2_ND53_MASK                     ((uint32_t)0x00200000U)         /* !< New Data RX Buffer 53   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND54] Bits */
#define MCAN_NDAT2_ND54_OFS                      (22)                            /* !< ND54 Offset */
#define MCAN_NDAT2_ND54_MASK                     ((uint32_t)0x00400000U)         /* !< New Data RX Buffer 54   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND55] Bits */
#define MCAN_NDAT2_ND55_OFS                      (23)                            /* !< ND55 Offset */
#define MCAN_NDAT2_ND55_MASK                     ((uint32_t)0x00800000U)         /* !< New Data RX Buffer 55   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND56] Bits */
#define MCAN_NDAT2_ND56_OFS                      (24)                            /* !< ND56 Offset */
#define MCAN_NDAT2_ND56_MASK                     ((uint32_t)0x01000000U)         /* !< New Data RX Buffer 56   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND57] Bits */
#define MCAN_NDAT2_ND57_OFS                      (25)                            /* !< ND57 Offset */
#define MCAN_NDAT2_ND57_MASK                     ((uint32_t)0x02000000U)         /* !< New Data RX Buffer 57   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND58] Bits */
#define MCAN_NDAT2_ND58_OFS                      (26)                            /* !< ND58 Offset */
#define MCAN_NDAT2_ND58_MASK                     ((uint32_t)0x04000000U)         /* !< New Data RX Buffer 58   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND59] Bits */
#define MCAN_NDAT2_ND59_OFS                      (27)                            /* !< ND59 Offset */
#define MCAN_NDAT2_ND59_MASK                     ((uint32_t)0x08000000U)         /* !< New Data RX Buffer 59   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND60] Bits */
#define MCAN_NDAT2_ND60_OFS                      (28)                            /* !< ND60 Offset */
#define MCAN_NDAT2_ND60_MASK                     ((uint32_t)0x10000000U)         /* !< New Data RX Buffer 60   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND61] Bits */
#define MCAN_NDAT2_ND61_OFS                      (29)                            /* !< ND61 Offset */
#define MCAN_NDAT2_ND61_MASK                     ((uint32_t)0x20000000U)         /* !< New Data RX Buffer 61   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND62] Bits */
#define MCAN_NDAT2_ND62_OFS                      (30)                            /* !< ND62 Offset */
#define MCAN_NDAT2_ND62_MASK                     ((uint32_t)0x40000000U)         /* !< New Data RX Buffer 62   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */
/* MCAN_NDAT2[ND63] Bits */
#define MCAN_NDAT2_ND63_OFS                      (31)                            /* !< ND63 Offset */
#define MCAN_NDAT2_ND63_MASK                     ((uint32_t)0x80000000U)         /* !< New Data RX Buffer 63   0  Rx
                                                                                    Buffer not updated   1  Rx Buffer
                                                                                    updated from new message */

/* MCAN_RXF0C Bits */
/* MCAN_RXF0C[F0SA] Bits */
#define MCAN_RXF0C_F0SA_OFS                      (2)                             /* !< F0SA Offset */
#define MCAN_RXF0C_F0SA_MASK                     ((uint32_t)0x0000FFFCU)         /* !< Rx FIFO 0 Start Address. Start
                                                                                    address of Rx FIFO 0 in Message RAM
                                                                                    (32-bit word address).   Qualified
                                                                                    Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_RXF0C[F0S] Bits */
#define MCAN_RXF0C_F0S_OFS                       (16)                            /* !< F0S Offset */
#define MCAN_RXF0C_F0S_MASK                      ((uint32_t)0x007F0000U)         /* !< Rx FIFO 0 Size. The Rx FIFO 0
                                                                                    elements are indexed from 0 to F0S-1.
                                                                                    0      No Rx FIFO 0   1-64  Number
                                                                                    of Rx FIFO 0 elements   >64   Values
                                                                                    greater than 64 are interpreted as 64
                                                                                    Qualified Write is possible only
                                                                                    with CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_RXF0C[F0WM] Bits */
#define MCAN_RXF0C_F0WM_OFS                      (24)                            /* !< F0WM Offset */
#define MCAN_RXF0C_F0WM_MASK                     ((uint32_t)0x7F000000U)         /* !< Rx FIFO 0 Watermark   0
                                                                                    Watermark interrupt disabled   1-64
                                                                                    Level for Rx FIFO 0 watermark
                                                                                    interrupt (IR.RF0W)   >64   Watermark
                                                                                    interrupt disabled   Qualified Write
                                                                                    is possible only with CCCR.CCE='1'
                                                                                    and CCCR.INIT='1'. */
/* MCAN_RXF0C[F0OM] Bits */
#define MCAN_RXF0C_F0OM_OFS                      (31)                            /* !< F0OM Offset */
#define MCAN_RXF0C_F0OM_MASK                     ((uint32_t)0x80000000U)         /* !< FIFO 0 Operation Mode. FIFO 0 can
                                                                                    be operated in blocking or in
                                                                                    overwrite mode.   0  FIFO 0 blocking
                                                                                    mode   1  FIFO 0 overwrite mode
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */

/* MCAN_RXF0S Bits */
/* MCAN_RXF0S[F0FL] Bits */
#define MCAN_RXF0S_F0FL_OFS                      (0)                             /* !< F0FL Offset */
#define MCAN_RXF0S_F0FL_MASK                     ((uint32_t)0x0000007FU)         /* !< Rx FIFO 0 Fill Level. Number of
                                                                                    elements stored in Rx FIFO 0, range 0
                                                                                    to 64. */
/* MCAN_RXF0S[F0GI] Bits */
#define MCAN_RXF0S_F0GI_OFS                      (8)                             /* !< F0GI Offset */
#define MCAN_RXF0S_F0GI_MASK                     ((uint32_t)0x00003F00U)         /* !< Rx FIFO 0 Get Index. Rx FIFO 0 read
                                                                                    index pointer, range 0 to 63. */
/* MCAN_RXF0S[F0PI] Bits */
#define MCAN_RXF0S_F0PI_OFS                      (16)                            /* !< F0PI Offset */
#define MCAN_RXF0S_F0PI_MASK                     ((uint32_t)0x003F0000U)         /* !< Rx FIFO 0 Put Index. Rx FIFO 0
                                                                                    write index pointer, range 0 to 63. */
/* MCAN_RXF0S[F0F] Bits */
#define MCAN_RXF0S_F0F_OFS                       (24)                            /* !< F0F Offset */
#define MCAN_RXF0S_F0F_MASK                      ((uint32_t)0x01000000U)         /* !< Rx FIFO 0 Full   0  Rx FIFO 0 not
                                                                                    full   1  Rx FIFO 0 full */
/* MCAN_RXF0S[RF0L] Bits */
#define MCAN_RXF0S_RF0L_OFS                      (25)                            /* !< RF0L Offset */
#define MCAN_RXF0S_RF0L_MASK                     ((uint32_t)0x02000000U)         /* !< Rx FIFO 0 Message Lost. This bit is
                                                                                    a copy of interrupt flag IR.RF0L.
                                                                                    When IR.RF0L is reset, this bit is
                                                                                    also reset.   0  No Rx FIFO 0 message
                                                                                    lost   1  Rx FIFO 0 message lost,
                                                                                    also set after write attempt to Rx
                                                                                    FIFO 0 of size zero   Note:
                                                                                    Overwriting the oldest message when
                                                                                    RXF0C.F0OM = '1' will not set this
                                                                                    flag. */

/* MCAN_RXF0A Bits */
/* MCAN_RXF0A[F0AI] Bits */
#define MCAN_RXF0A_F0AI_OFS                      (0)                             /* !< F0AI Offset */
#define MCAN_RXF0A_F0AI_MASK                     ((uint32_t)0x0000003FU)         /* !< Rx FIFO 0 Acknowledge Index. After
                                                                                    the Host has read a message or a
                                                                                    sequence of messages from Rx FIFO 0
                                                                                    it has to write the buffer index of
                                                                                    the last element read from Rx FIFO 0
                                                                                    to F0AI. This will set the Rx FIFO 0
                                                                                    Get Index RXF0S.F0GI to F0AI + 1 and
                                                                                    update the FIFO 0 Fill Level
                                                                                    RXF0S.F0FL. */

/* MCAN_RXBC Bits */
/* MCAN_RXBC[RBSA] Bits */
#define MCAN_RXBC_RBSA_OFS                       (2)                             /* !< RBSA Offset */
#define MCAN_RXBC_RBSA_MASK                      ((uint32_t)0x0000FFFCU)         /* !< Rx Buffer Start Address. Configures
                                                                                    the start address of the Rx Buffers
                                                                                    section in the Message RAM (32-bit
                                                                                    word address).   +I466 */

/* MCAN_RXF1C Bits */
/* MCAN_RXF1C[F1SA] Bits */
#define MCAN_RXF1C_F1SA_OFS                      (2)                             /* !< F1SA Offset */
#define MCAN_RXF1C_F1SA_MASK                     ((uint32_t)0x0000FFFCU)         /* !< Rx FIFO 1 Start Address Start
                                                                                    address of Rx FIFO 1 in Message RAM
                                                                                    (32-bit word address). */
/* MCAN_RXF1C[F1S] Bits */
#define MCAN_RXF1C_F1S_OFS                       (16)                            /* !< F1S Offset */
#define MCAN_RXF1C_F1S_MASK                      ((uint32_t)0x007F0000U)         /* !< Rx FIFO 1 Size. The Rx FIFO 1
                                                                                    elements are indexed from 0 to F1S -
                                                                                    1.   0      No Rx FIFO 1   1-64
                                                                                    Number of Rx FIFO 1 elements   >64
                                                                                    Values greater than 64 are
                                                                                    interpreted as 64   Qualified Write
                                                                                    is possible only with CCCR.CCE='1'
                                                                                    and CCCR.INIT='1'. */
/* MCAN_RXF1C[F1WM] Bits */
#define MCAN_RXF1C_F1WM_OFS                      (24)                            /* !< F1WM Offset */
#define MCAN_RXF1C_F1WM_MASK                     ((uint32_t)0x7F000000U)         /* !< Rx FIFO 1 Watermark   0
                                                                                    Watermark interrupt disabled   1-64
                                                                                    Level for Rx FIFO 1 watermark
                                                                                    interrupt (IR.RF1W)   >64   Watermark
                                                                                    interrupt disabled   Qualified Write
                                                                                    is possible only with CCCR.CCE='1'
                                                                                    and CCCR.INIT='1'. */
/* MCAN_RXF1C[F1OM] Bits */
#define MCAN_RXF1C_F1OM_OFS                      (31)                            /* !< F1OM Offset */
#define MCAN_RXF1C_F1OM_MASK                     ((uint32_t)0x80000000U)         /* !< FIFO 1 Operation Mode. FIFO 1 can
                                                                                    be operated in blocking or in
                                                                                    overwrite mode.   0  FIFO 1 blocking
                                                                                    mode   1  FIFO 1 overwrite mode
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */

/* MCAN_RXF1S Bits */
/* MCAN_RXF1S[F1FL] Bits */
#define MCAN_RXF1S_F1FL_OFS                      (0)                             /* !< F1FL Offset */
#define MCAN_RXF1S_F1FL_MASK                     ((uint32_t)0x0000007FU)         /* !< Rx FIFO 1 Fill Level. Number of
                                                                                    elements stored in Rx FIFO 1, range 0
                                                                                    to 64. */
/* MCAN_RXF1S[F1GI] Bits */
#define MCAN_RXF1S_F1GI_OFS                      (8)                             /* !< F1GI Offset */
#define MCAN_RXF1S_F1GI_MASK                     ((uint32_t)0x00003F00U)         /* !< Rx FIFO 1 Get Index. Rx FIFO 1 read
                                                                                    index pointer, range 0 to 63. */
/* MCAN_RXF1S[F1PI] Bits */
#define MCAN_RXF1S_F1PI_OFS                      (16)                            /* !< F1PI Offset */
#define MCAN_RXF1S_F1PI_MASK                     ((uint32_t)0x003F0000U)         /* !< Rx FIFO 1 Put Index. Rx FIFO 1
                                                                                    write index pointer, range 0 to 63. */
/* MCAN_RXF1S[F1F] Bits */
#define MCAN_RXF1S_F1F_OFS                       (24)                            /* !< F1F Offset */
#define MCAN_RXF1S_F1F_MASK                      ((uint32_t)0x01000000U)         /* !< Rx FIFO 1 Full   0  Rx FIFO 1 not
                                                                                    full   1  Rx FIFO 1 full */
/* MCAN_RXF1S[RF1L] Bits */
#define MCAN_RXF1S_RF1L_OFS                      (25)                            /* !< RF1L Offset */
#define MCAN_RXF1S_RF1L_MASK                     ((uint32_t)0x02000000U)         /* !< Rx FIFO 1 Message Lost. This bit is
                                                                                    a copy of interrupt flag IR.RF1L.
                                                                                    When IR.RF1L is reset, this bit is
                                                                                    also reset.   0  No Rx FIFO 1 message
                                                                                    lost   1  Rx FIFO 1 message lost,
                                                                                    also set after write attempt to Rx
                                                                                    FIFO 1 of size zero   Note:
                                                                                    Overwriting the oldest message when
                                                                                    RXF1C.F1OM = '1' will not set this
                                                                                    flag. */
/* MCAN_RXF1S[DMS] Bits */
#define MCAN_RXF1S_DMS_OFS                       (30)                            /* !< DMS Offset */
#define MCAN_RXF1S_DMS_MASK                      ((uint32_t)0xC0000000U)         /* !< Debug Message Status   00  Idle
                                                                                    state, wait for reception of debug
                                                                                    messages   01  Debug message A
                                                                                    received   10  Debug messages A, B
                                                                                    received   11  Debug messages A, B, C
                                                                                    received */

/* MCAN_RXF1A Bits */
/* MCAN_RXF1A[F1AI] Bits */
#define MCAN_RXF1A_F1AI_OFS                      (0)                             /* !< F1AI Offset */
#define MCAN_RXF1A_F1AI_MASK                     ((uint32_t)0x0000003FU)         /* !< Rx FIFO 1 Acknowledge Index. After
                                                                                    the Host has read a message or a
                                                                                    sequence of messages from Rx FIFO 1
                                                                                    it has to write the buffer index of
                                                                                    the last element read from Rx FIFO 1
                                                                                    to F1AI. This will set the Rx FIFO 1
                                                                                    Get Index RXF1S.F1GI to F1AI + 1 and
                                                                                    update the FIFO 1 Fill Level
                                                                                    RXF1S.F1FL. */

/* MCAN_RXESC Bits */
/* MCAN_RXESC[F0DS] Bits */
#define MCAN_RXESC_F0DS_OFS                      (0)                             /* !< F0DS Offset */
#define MCAN_RXESC_F0DS_MASK                     ((uint32_t)0x00000007U)         /* !< Rx FIFO 0 Data Field Size   000  8
                                                                                    byte data field   001  12 byte data
                                                                                    field   010  16 byte data field   011
                                                                                    20 byte data field   100  24 byte
                                                                                    data field   101  32 byte data field
                                                                                    110  48 byte data field   111  64
                                                                                    byte data field   Note: In case the
                                                                                    data field size of an accepted CAN
                                                                                    frame exceeds the data field size
                                                                                    configured for the matching Rx Buffer
                                                                                    or Rx FIFO, only the number of bytes
                                                                                    as configured by RXESC are stored to
                                                                                    the Rx Buffer resp. Rx FIFO element.
                                                                                    The rest of the frame's data field is
                                                                                    ignored.   Qualified Write is
                                                                                    possible only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */
/* MCAN_RXESC[F1DS] Bits */
#define MCAN_RXESC_F1DS_OFS                      (4)                             /* !< F1DS Offset */
#define MCAN_RXESC_F1DS_MASK                     ((uint32_t)0x00000070U)         /* !< Rx FIFO 1 Data Field Size   000  8
                                                                                    byte data field   001  12 byte data
                                                                                    field   010  16 byte data field   011
                                                                                    20 byte data field   100  24 byte
                                                                                    data field   101  32 byte data field
                                                                                    110  48 byte data field   111  64
                                                                                    byte data field   Note: In case the
                                                                                    data field size of an accepted CAN
                                                                                    frame exceeds the data field size
                                                                                    configured for the matching Rx Buffer
                                                                                    or Rx FIFO, only the number of bytes
                                                                                    as configured by RXESC are stored to
                                                                                    the Rx Buffer resp. Rx FIFO element.
                                                                                    The rest of the frame's data field is
                                                                                    ignored.   Qualified Write is
                                                                                    possible only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */
/* MCAN_RXESC[RBDS] Bits */
#define MCAN_RXESC_RBDS_OFS                      (8)                             /* !< RBDS Offset */
#define MCAN_RXESC_RBDS_MASK                     ((uint32_t)0x00000700U)         /* !< Rx Buffer Data Field Size   000  8
                                                                                    byte data field   001  12 byte data
                                                                                    field   010  16 byte data field   011
                                                                                    20 byte data field   100  24 byte
                                                                                    data field   101  32 byte data field
                                                                                    110  48 byte data field   111  64
                                                                                    byte data field   Note: In case the
                                                                                    data field size of an accepted CAN
                                                                                    frame exceeds the data field size
                                                                                    configured for the matching Rx Buffer
                                                                                    or Rx FIFO, only the number of bytes
                                                                                    as configured by RXESC are stored to
                                                                                    the Rx Buffer resp. Rx FIFO element.
                                                                                    The rest of the frame's data field is
                                                                                    ignored.   Qualified Write is
                                                                                    possible only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */

/* MCAN_TXBC Bits */
/* MCAN_TXBC[TBSA] Bits */
#define MCAN_TXBC_TBSA_OFS                       (2)                             /* !< TBSA Offset */
#define MCAN_TXBC_TBSA_MASK                      ((uint32_t)0x0000FFFCU)         /* !< Tx Buffers Start Address. Start
                                                                                    address of Tx Buffers section in
                                                                                    Message RAM (32-bit word address).
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_TXBC[NDTB] Bits */
#define MCAN_TXBC_NDTB_OFS                       (16)                            /* !< NDTB Offset */
#define MCAN_TXBC_NDTB_MASK                      ((uint32_t)0x003F0000U)         /* !< Number of Dedicated Transmit
                                                                                    Buffers   0      No Dedicated Tx
                                                                                    Buffers   1-32  Number of Dedicated
                                                                                    Tx Buffers   >32   Values greater
                                                                                    than 32 are interpreted as 32   Note:
                                                                                    Be aware that the sum of TFQS and
                                                                                    NDTB may be not greater than 32.
                                                                                    There is no check for erroneous
                                                                                    configurations. The Tx Buffers
                                                                                    section in the Message RAM starts
                                                                                    with the dedicated Tx Buffers.
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */
/* MCAN_TXBC[TFQS] Bits */
#define MCAN_TXBC_TFQS_OFS                       (24)                            /* !< TFQS Offset */
#define MCAN_TXBC_TFQS_MASK                      ((uint32_t)0x3F000000U)         /* !< Transmit FIFO/Queue Size   0
                                                                                    No Tx FIFO/Queue   1-32  Number of Tx
                                                                                    Buffers used for Tx FIFO/Queue   >32
                                                                                    Values greater than 32 are
                                                                                    interpreted as 32   Note: Be aware
                                                                                    that the sum of TFQS and NDTB may be
                                                                                    not greater than 32. There is no
                                                                                    check for erroneous configurations.
                                                                                    The Tx Buffers section in the Message
                                                                                    RAM starts with the dedicated Tx
                                                                                    Buffers.   Qualified Write is
                                                                                    possible only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */
/* MCAN_TXBC[TFQM] Bits */
#define MCAN_TXBC_TFQM_OFS                       (30)                            /* !< TFQM Offset */
#define MCAN_TXBC_TFQM_MASK                      ((uint32_t)0x40000000U)         /* !< Tx FIFO/Queue Mode   0  Tx FIFO
                                                                                    operation   1  Tx Queue operation
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='1' and CCCR.INIT='1'. */

/* MCAN_TXFQS Bits */
/* MCAN_TXFQS[TFFL] Bits */
#define MCAN_TXFQS_TFFL_OFS                      (0)                             /* !< TFFL Offset */
#define MCAN_TXFQS_TFFL_MASK                     ((uint32_t)0x0000003FU)         /* !< Tx FIFO Free Level.  Number of
                                                                                    consecutive free Tx FIFO elements
                                                                                    starting from TFGI, range 0 to 32.
                                                                                    Read as zero when Tx Queue operation
                                                                                    is configured (TXBC.TFQM = '1'). */
/* MCAN_TXFQS[TFGI] Bits */
#define MCAN_TXFQS_TFGI_OFS                      (8)                             /* !< TFGI Offset */
#define MCAN_TXFQS_TFGI_MASK                     ((uint32_t)0x00001F00U)         /* !< Tx FIFO Get Index. Tx FIFO read
                                                                                    index pointer, range 0 to 31. Read as
                                                                                    zero when Tx Queue operation is
                                                                                    configured (TXBC.TFQM = '1').   Note:
                                                                                    In case of mixed configurations where
                                                                                    dedicated Tx Buffers are combined
                                                                                    with a Tx FIFO or a Tx Queue, the Put
                                                                                    and Get Indices indicate the number
                                                                                    of the Tx Buffer starting with the
                                                                                    first dedicated Tx Buffers. Example:
                                                                                    For a configuration of 12 dedicated
                                                                                    Tx Buffers and a Tx FIFO of 20
                                                                                    Buffers a Put Index of 15 points to
                                                                                    the fourth buffer of the Tx FIFO. */
/* MCAN_TXFQS[TFQP] Bits */
#define MCAN_TXFQS_TFQP_OFS                      (16)                            /* !< TFQP Offset */
#define MCAN_TXFQS_TFQP_MASK                     ((uint32_t)0x001F0000U)         /* !< Tx FIFO/Queue Put Index. Tx
                                                                                    FIFO/Queue write index pointer, range
                                                                                    0 to 31.   Note: In case of mixed
                                                                                    configurations where dedicated Tx
                                                                                    Buffers are combined with a Tx FIFO
                                                                                    or a Tx Queue, the Put and Get
                                                                                    Indices indicate the number of the Tx
                                                                                    Buffer starting with the first
                                                                                    dedicated Tx Buffers. Example: For a
                                                                                    configuration of 12 dedicated Tx
                                                                                    Buffers and a Tx FIFO of 20 Buffers a
                                                                                    Put Index of 15 points to the fourth
                                                                                    buffer of the Tx FIFO. */
/* MCAN_TXFQS[TFQF] Bits */
#define MCAN_TXFQS_TFQF_OFS                      (21)                            /* !< TFQF Offset */
#define MCAN_TXFQS_TFQF_MASK                     ((uint32_t)0x00200000U)         /* !< Tx FIFO/Queue Full   0  Tx
                                                                                    FIFO/Queue not full   1  Tx
                                                                                    FIFO/Queue full */

/* MCAN_TXESC Bits */
/* MCAN_TXESC[TBDS] Bits */
#define MCAN_TXESC_TBDS_OFS                      (0)                             /* !< TBDS Offset */
#define MCAN_TXESC_TBDS_MASK                     ((uint32_t)0x00000007U)         /* !< Tx Buffer Data Field Size   000  8
                                                                                    byte data field   001  12 byte data
                                                                                    field   010  16 byte data field   011
                                                                                    20 byte data field   100  24 byte
                                                                                    data field   101  32 byte data field
                                                                                    110  48 byte data field   111  64
                                                                                    byte data field   Note: In case the
                                                                                    data length code DLC of a Tx Buffer
                                                                                    element is configured to a value
                                                                                    higher than the Tx Buffer data field
                                                                                    size TXESC.TBDS, the bytes not
                                                                                    defined by the Tx Buffer are
                                                                                    transmitted as "0xCC" (padding
                                                                                    bytes).   Qualified Write is possible
                                                                                    only with CCCR.CCE='1' and
                                                                                    CCCR.INIT='1'. */

/* MCAN_TXBRP Bits */
/* MCAN_TXBRP[TRP0] Bits */
#define MCAN_TXBRP_TRP0_OFS                      (0)                             /* !< TRP0 Offset */
#define MCAN_TXBRP_TRP0_MASK                     ((uint32_t)0x00000001U)         /* !< Transmission Request Pending 0.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Request Pending bit. The
                                                                                    bits are set via register TXBAR. The
                                                                                    bits are reset after a requested
                                                                                    transmission has completed or has
                                                                                    been cancelled via register TXBCR.
                                                                                    TXBRP bits are set only for those Tx
                                                                                    Buffers configured via TXBC. After a
                                                                                    TXBRP bit has been set, a Tx scan is
                                                                                    started to check for the pending Tx
                                                                                    request with the highest priority (Tx
                                                                                    Buffer with lowest Message ID).   A
                                                                                    cancellation request resets the
                                                                                    corresponding transmission request
                                                                                    pending bit of register TXBRP. In
                                                                                    case a transmission has already been
                                                                                    started when a cancellation is
                                                                                    requested, this is done at the end of
                                                                                    the transmission, regardless whether
                                                                                    the transmission was successful or
                                                                                    not. The cancellation request bits
                                                                                    are reset directly after the
                                                                                    corresponding TXBRP bit has been
                                                                                    reset.   After a cancellation has
                                                                                    been requested, a finished
                                                                                    cancellation is signalled via TXBCF -
                                                                                    after successful transmission
                                                                                    together with the corresponding TXBTO
                                                                                    bit - when the transmission has not
                                                                                    yet been started at the point of
                                                                                    cancellation - when the transmission
                                                                                    has been aborted due to lost
                                                                                    arbitration - when an error occurred
                                                                                    during frame transmission   In DAR
                                                                                    mode all transmissions are
                                                                                    automatically cancelled if they are
                                                                                    not successful. The corresponding
                                                                                    TXBCF bit is set for all unsuccessful
                                                                                    transmissions.   0  No transmission
                                                                                    request pending   1  Transmission
                                                                                    request pending   Note: TXBRP bits
                                                                                    which are set while a Tx scan is in
                                                                                    progress are not considered during
                                                                                    this particular Tx scan. In case a
                                                                                    cancellation is requested for such a
                                                                                    Tx Buffer, this Add Request is
                                                                                    cancelled immediately, the
                                                                                    corresponding TXBRP bit is reset. */
/* MCAN_TXBRP[TRP1] Bits */
#define MCAN_TXBRP_TRP1_OFS                      (1)                             /* !< TRP1 Offset */
#define MCAN_TXBRP_TRP1_MASK                     ((uint32_t)0x00000002U)         /* !< Transmission Request Pending 1. See
                                                                                    description for bit 0. */
/* MCAN_TXBRP[TRP2] Bits */
#define MCAN_TXBRP_TRP2_OFS                      (2)                             /* !< TRP2 Offset */
#define MCAN_TXBRP_TRP2_MASK                     ((uint32_t)0x00000004U)         /* !< Transmission Request Pending 2. See
                                                                                    description for bit 0. */
/* MCAN_TXBRP[TRP3] Bits */
#define MCAN_TXBRP_TRP3_OFS                      (3)                             /* !< TRP3 Offset */
#define MCAN_TXBRP_TRP3_MASK                     ((uint32_t)0x00000008U)         /* !< Transmission Request Pending 3. See
                                                                                    description for bit 0. */
/* MCAN_TXBRP[TRP4] Bits */
#define MCAN_TXBRP_TRP4_OFS                      (4)                             /* !< TRP4 Offset */
#define MCAN_TXBRP_TRP4_MASK                     ((uint32_t)0x00000010U)         /* !< Transmission Request Pending 4. See
                                                                                    description for bit 0. */
/* MCAN_TXBRP[TRP5] Bits */
#define MCAN_TXBRP_TRP5_OFS                      (5)                             /* !< TRP5 Offset */
#define MCAN_TXBRP_TRP5_MASK                     ((uint32_t)0x00000020U)         /* !< Transmission Request Pending 5. See
                                                                                    description for bit 0. */
/* MCAN_TXBRP[TRP6] Bits */
#define MCAN_TXBRP_TRP6_OFS                      (6)                             /* !< TRP6 Offset */
#define MCAN_TXBRP_TRP6_MASK                     ((uint32_t)0x00000040U)         /* !< Transmission Request Pending 6. See
                                                                                    description for bit 0. */
/* MCAN_TXBRP[TRP7] Bits */
#define MCAN_TXBRP_TRP7_OFS                      (7)                             /* !< TRP7 Offset */
#define MCAN_TXBRP_TRP7_MASK                     ((uint32_t)0x00000080U)         /* !< Transmission Request Pending 7. See
                                                                                    description for bit 0. */
/* MCAN_TXBRP[TRP8] Bits */
#define MCAN_TXBRP_TRP8_OFS                      (8)                             /* !< TRP8 Offset */
#define MCAN_TXBRP_TRP8_MASK                     ((uint32_t)0x00000100U)         /* !< Transmission Request Pending 8. See
                                                                                    description for bit 0. */
/* MCAN_TXBRP[TRP9] Bits */
#define MCAN_TXBRP_TRP9_OFS                      (9)                             /* !< TRP9 Offset */
#define MCAN_TXBRP_TRP9_MASK                     ((uint32_t)0x00000200U)         /* !< Transmission Request Pending 9. See
                                                                                    description for bit 0. */
/* MCAN_TXBRP[TRP10] Bits */
#define MCAN_TXBRP_TRP10_OFS                     (10)                            /* !< TRP10 Offset */
#define MCAN_TXBRP_TRP10_MASK                    ((uint32_t)0x00000400U)         /* !< Transmission Request Pending 10.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP11] Bits */
#define MCAN_TXBRP_TRP11_OFS                     (11)                            /* !< TRP11 Offset */
#define MCAN_TXBRP_TRP11_MASK                    ((uint32_t)0x00000800U)         /* !< Transmission Request Pending 11.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP12] Bits */
#define MCAN_TXBRP_TRP12_OFS                     (12)                            /* !< TRP12 Offset */
#define MCAN_TXBRP_TRP12_MASK                    ((uint32_t)0x00001000U)         /* !< Transmission Request Pending 12.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP13] Bits */
#define MCAN_TXBRP_TRP13_OFS                     (13)                            /* !< TRP13 Offset */
#define MCAN_TXBRP_TRP13_MASK                    ((uint32_t)0x00002000U)         /* !< Transmission Request Pending 13.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP14] Bits */
#define MCAN_TXBRP_TRP14_OFS                     (14)                            /* !< TRP14 Offset */
#define MCAN_TXBRP_TRP14_MASK                    ((uint32_t)0x00004000U)         /* !< Transmission Request Pending 14.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP15] Bits */
#define MCAN_TXBRP_TRP15_OFS                     (15)                            /* !< TRP15 Offset */
#define MCAN_TXBRP_TRP15_MASK                    ((uint32_t)0x00008000U)         /* !< Transmission Request Pending 15.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP16] Bits */
#define MCAN_TXBRP_TRP16_OFS                     (16)                            /* !< TRP16 Offset */
#define MCAN_TXBRP_TRP16_MASK                    ((uint32_t)0x00010000U)         /* !< Transmission Request Pending 16.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP17] Bits */
#define MCAN_TXBRP_TRP17_OFS                     (17)                            /* !< TRP17 Offset */
#define MCAN_TXBRP_TRP17_MASK                    ((uint32_t)0x00020000U)         /* !< Transmission Request Pending 17.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP18] Bits */
#define MCAN_TXBRP_TRP18_OFS                     (18)                            /* !< TRP18 Offset */
#define MCAN_TXBRP_TRP18_MASK                    ((uint32_t)0x00040000U)         /* !< Transmission Request Pending 18.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP19] Bits */
#define MCAN_TXBRP_TRP19_OFS                     (19)                            /* !< TRP19 Offset */
#define MCAN_TXBRP_TRP19_MASK                    ((uint32_t)0x00080000U)         /* !< Transmission Request Pending 19.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP20] Bits */
#define MCAN_TXBRP_TRP20_OFS                     (20)                            /* !< TRP20 Offset */
#define MCAN_TXBRP_TRP20_MASK                    ((uint32_t)0x00100000U)         /* !< Transmission Request Pending 20.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP21] Bits */
#define MCAN_TXBRP_TRP21_OFS                     (21)                            /* !< TRP21 Offset */
#define MCAN_TXBRP_TRP21_MASK                    ((uint32_t)0x00200000U)         /* !< Transmission Request Pending 21.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP22] Bits */
#define MCAN_TXBRP_TRP22_OFS                     (22)                            /* !< TRP22 Offset */
#define MCAN_TXBRP_TRP22_MASK                    ((uint32_t)0x00400000U)         /* !< Transmission Request Pending 22.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP23] Bits */
#define MCAN_TXBRP_TRP23_OFS                     (23)                            /* !< TRP23 Offset */
#define MCAN_TXBRP_TRP23_MASK                    ((uint32_t)0x00800000U)         /* !< Transmission Request Pending 23.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP24] Bits */
#define MCAN_TXBRP_TRP24_OFS                     (24)                            /* !< TRP24 Offset */
#define MCAN_TXBRP_TRP24_MASK                    ((uint32_t)0x01000000U)         /* !< Transmission Request Pending 24.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP25] Bits */
#define MCAN_TXBRP_TRP25_OFS                     (25)                            /* !< TRP25 Offset */
#define MCAN_TXBRP_TRP25_MASK                    ((uint32_t)0x02000000U)         /* !< Transmission Request Pending 25.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP26] Bits */
#define MCAN_TXBRP_TRP26_OFS                     (26)                            /* !< TRP26 Offset */
#define MCAN_TXBRP_TRP26_MASK                    ((uint32_t)0x04000000U)         /* !< Transmission Request Pending 26.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP27] Bits */
#define MCAN_TXBRP_TRP27_OFS                     (27)                            /* !< TRP27 Offset */
#define MCAN_TXBRP_TRP27_MASK                    ((uint32_t)0x08000000U)         /* !< Transmission Request Pending 27.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP28] Bits */
#define MCAN_TXBRP_TRP28_OFS                     (28)                            /* !< TRP28 Offset */
#define MCAN_TXBRP_TRP28_MASK                    ((uint32_t)0x10000000U)         /* !< Transmission Request Pending 28.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP29] Bits */
#define MCAN_TXBRP_TRP29_OFS                     (29)                            /* !< TRP29 Offset */
#define MCAN_TXBRP_TRP29_MASK                    ((uint32_t)0x20000000U)         /* !< Transmission Request Pending 29.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP30] Bits */
#define MCAN_TXBRP_TRP30_OFS                     (30)                            /* !< TRP30 Offset */
#define MCAN_TXBRP_TRP30_MASK                    ((uint32_t)0x40000000U)         /* !< Transmission Request Pending 30.
                                                                                    See description for bit 0. */
/* MCAN_TXBRP[TRP31] Bits */
#define MCAN_TXBRP_TRP31_OFS                     (31)                            /* !< TRP31 Offset */
#define MCAN_TXBRP_TRP31_MASK                    ((uint32_t)0x80000000U)         /* !< Transmission Request Pending 31.
                                                                                    See description for bit 0. */

/* MCAN_TXBAR Bits */
/* MCAN_TXBAR[AR0] Bits */
#define MCAN_TXBAR_AR0_OFS                       (0)                             /* !< AR0 Offset */
#define MCAN_TXBAR_AR0_MASK                      ((uint32_t)0x00000001U)         /* !< Add Request 0.   Each Tx Buffer has
                                                                                    its own Add Request bit. Writing a
                                                                                    '1' will set the corresponding Add
                                                                                    Request bit; writing a '0' has no
                                                                                    impact. This enables the Host to set
                                                                                    transmission requests for multiple Tx
                                                                                    Buffers with one write to TXBAR.
                                                                                    TXBAR bits are set only for those Tx
                                                                                    Buffers configured via TXBC. When no
                                                                                    Tx scan is running, the bits are
                                                                                    reset immediately, else the bits
                                                                                    remain set until the Tx scan process
                                                                                    has completed.   0  No transmission
                                                                                    request added   1  Transmission
                                                                                    requested added   Note: If an add
                                                                                    request is applied for a Tx Buffer
                                                                                    with pending transmission request
                                                                                    (corresponding TXBRP bit already
                                                                                    set), this add request is ignored.
                                                                                    Qualified Write is possible only with
                                                                                    CCCR.CCE='0' */
/* MCAN_TXBAR[AR1] Bits */
#define MCAN_TXBAR_AR1_OFS                       (1)                             /* !< AR1 Offset */
#define MCAN_TXBAR_AR1_MASK                      ((uint32_t)0x00000002U)         /* !< Add Request 1. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR2] Bits */
#define MCAN_TXBAR_AR2_OFS                       (2)                             /* !< AR2 Offset */
#define MCAN_TXBAR_AR2_MASK                      ((uint32_t)0x00000004U)         /* !< Add Request 2. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR3] Bits */
#define MCAN_TXBAR_AR3_OFS                       (3)                             /* !< AR3 Offset */
#define MCAN_TXBAR_AR3_MASK                      ((uint32_t)0x00000008U)         /* !< Add Request 3. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR4] Bits */
#define MCAN_TXBAR_AR4_OFS                       (4)                             /* !< AR4 Offset */
#define MCAN_TXBAR_AR4_MASK                      ((uint32_t)0x00000010U)         /* !< Add Request 4. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR5] Bits */
#define MCAN_TXBAR_AR5_OFS                       (5)                             /* !< AR5 Offset */
#define MCAN_TXBAR_AR5_MASK                      ((uint32_t)0x00000020U)         /* !< Add Request 5. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR6] Bits */
#define MCAN_TXBAR_AR6_OFS                       (6)                             /* !< AR6 Offset */
#define MCAN_TXBAR_AR6_MASK                      ((uint32_t)0x00000040U)         /* !< Add Request 6. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR7] Bits */
#define MCAN_TXBAR_AR7_OFS                       (7)                             /* !< AR7 Offset */
#define MCAN_TXBAR_AR7_MASK                      ((uint32_t)0x00000080U)         /* !< Add Request 7. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR8] Bits */
#define MCAN_TXBAR_AR8_OFS                       (8)                             /* !< AR8 Offset */
#define MCAN_TXBAR_AR8_MASK                      ((uint32_t)0x00000100U)         /* !< Add Request 8. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR9] Bits */
#define MCAN_TXBAR_AR9_OFS                       (9)                             /* !< AR9 Offset */
#define MCAN_TXBAR_AR9_MASK                      ((uint32_t)0x00000200U)         /* !< Add Request 9. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR10] Bits */
#define MCAN_TXBAR_AR10_OFS                      (10)                            /* !< AR10 Offset */
#define MCAN_TXBAR_AR10_MASK                     ((uint32_t)0x00000400U)         /* !< Add Request 10. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR11] Bits */
#define MCAN_TXBAR_AR11_OFS                      (11)                            /* !< AR11 Offset */
#define MCAN_TXBAR_AR11_MASK                     ((uint32_t)0x00000800U)         /* !< Add Request 11. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR12] Bits */
#define MCAN_TXBAR_AR12_OFS                      (12)                            /* !< AR12 Offset */
#define MCAN_TXBAR_AR12_MASK                     ((uint32_t)0x00001000U)         /* !< Add Request 12. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR13] Bits */
#define MCAN_TXBAR_AR13_OFS                      (13)                            /* !< AR13 Offset */
#define MCAN_TXBAR_AR13_MASK                     ((uint32_t)0x00002000U)         /* !< Add Request 13. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR14] Bits */
#define MCAN_TXBAR_AR14_OFS                      (14)                            /* !< AR14 Offset */
#define MCAN_TXBAR_AR14_MASK                     ((uint32_t)0x00004000U)         /* !< Add Request 14. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR15] Bits */
#define MCAN_TXBAR_AR15_OFS                      (15)                            /* !< AR15 Offset */
#define MCAN_TXBAR_AR15_MASK                     ((uint32_t)0x00008000U)         /* !< Add Request 15. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR16] Bits */
#define MCAN_TXBAR_AR16_OFS                      (16)                            /* !< AR16 Offset */
#define MCAN_TXBAR_AR16_MASK                     ((uint32_t)0x00010000U)         /* !< Add Request 16. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR17] Bits */
#define MCAN_TXBAR_AR17_OFS                      (17)                            /* !< AR17 Offset */
#define MCAN_TXBAR_AR17_MASK                     ((uint32_t)0x00020000U)         /* !< Add Request 17. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR18] Bits */
#define MCAN_TXBAR_AR18_OFS                      (18)                            /* !< AR18 Offset */
#define MCAN_TXBAR_AR18_MASK                     ((uint32_t)0x00040000U)         /* !< Add Request 18. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR19] Bits */
#define MCAN_TXBAR_AR19_OFS                      (19)                            /* !< AR19 Offset */
#define MCAN_TXBAR_AR19_MASK                     ((uint32_t)0x00080000U)         /* !< Add Request 19. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR20] Bits */
#define MCAN_TXBAR_AR20_OFS                      (20)                            /* !< AR20 Offset */
#define MCAN_TXBAR_AR20_MASK                     ((uint32_t)0x00100000U)         /* !< Add Request 20. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR21] Bits */
#define MCAN_TXBAR_AR21_OFS                      (21)                            /* !< AR21 Offset */
#define MCAN_TXBAR_AR21_MASK                     ((uint32_t)0x00200000U)         /* !< Add Request 21. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR22] Bits */
#define MCAN_TXBAR_AR22_OFS                      (22)                            /* !< AR22 Offset */
#define MCAN_TXBAR_AR22_MASK                     ((uint32_t)0x00400000U)         /* !< Add Request 22. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR23] Bits */
#define MCAN_TXBAR_AR23_OFS                      (23)                            /* !< AR23 Offset */
#define MCAN_TXBAR_AR23_MASK                     ((uint32_t)0x00800000U)         /* !< Add Request 23. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR24] Bits */
#define MCAN_TXBAR_AR24_OFS                      (24)                            /* !< AR24 Offset */
#define MCAN_TXBAR_AR24_MASK                     ((uint32_t)0x01000000U)         /* !< Add Request 24. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR25] Bits */
#define MCAN_TXBAR_AR25_OFS                      (25)                            /* !< AR25 Offset */
#define MCAN_TXBAR_AR25_MASK                     ((uint32_t)0x02000000U)         /* !< Add Request 25. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR26] Bits */
#define MCAN_TXBAR_AR26_OFS                      (26)                            /* !< AR26 Offset */
#define MCAN_TXBAR_AR26_MASK                     ((uint32_t)0x04000000U)         /* !< Add Request 26. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR27] Bits */
#define MCAN_TXBAR_AR27_OFS                      (27)                            /* !< AR27 Offset */
#define MCAN_TXBAR_AR27_MASK                     ((uint32_t)0x08000000U)         /* !< Add Request 27. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR28] Bits */
#define MCAN_TXBAR_AR28_OFS                      (28)                            /* !< AR28 Offset */
#define MCAN_TXBAR_AR28_MASK                     ((uint32_t)0x10000000U)         /* !< Add Request 28. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR29] Bits */
#define MCAN_TXBAR_AR29_OFS                      (29)                            /* !< AR29 Offset */
#define MCAN_TXBAR_AR29_MASK                     ((uint32_t)0x20000000U)         /* !< Add Request 29. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR30] Bits */
#define MCAN_TXBAR_AR30_OFS                      (30)                            /* !< AR30 Offset */
#define MCAN_TXBAR_AR30_MASK                     ((uint32_t)0x40000000U)         /* !< Add Request 30. See description for
                                                                                    bit 0. */
/* MCAN_TXBAR[AR31] Bits */
#define MCAN_TXBAR_AR31_OFS                      (31)                            /* !< AR31 Offset */
#define MCAN_TXBAR_AR31_MASK                     ((uint32_t)0x80000000U)         /* !< Add Request 31. See description for
                                                                                    bit 0. */

/* MCAN_TXBCR Bits */
/* MCAN_TXBCR[CR0] Bits */
#define MCAN_TXBCR_CR0_OFS                       (0)                             /* !< CR0 Offset */
#define MCAN_TXBCR_CR0_MASK                      ((uint32_t)0x00000001U)         /* !< Cancellation Request 0.   Each Tx
                                                                                    Buffer has its own Cancellation
                                                                                    Request bit. Writing a '1' will set
                                                                                    the corresponding Cancellation
                                                                                    Request bit; writing a '0' has no
                                                                                    impact. This enables the Host to set
                                                                                    cancellation requests for multiple Tx
                                                                                    Buffers with one write to TXBCR.
                                                                                    TXBCR bits are set only for those Tx
                                                                                    Buffers configured via TXBC. The bits
                                                                                    remain set until the corresponding
                                                                                    bit of TXBRP is reset.   0  No
                                                                                    cancellation pending   1
                                                                                    Cancellation pending   Qualified
                                                                                    Write is possible only with
                                                                                    CCCR.CCE='0' */
/* MCAN_TXBCR[CR1] Bits */
#define MCAN_TXBCR_CR1_OFS                       (1)                             /* !< CR1 Offset */
#define MCAN_TXBCR_CR1_MASK                      ((uint32_t)0x00000002U)         /* !< Cancellation Request 1. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR2] Bits */
#define MCAN_TXBCR_CR2_OFS                       (2)                             /* !< CR2 Offset */
#define MCAN_TXBCR_CR2_MASK                      ((uint32_t)0x00000004U)         /* !< Cancellation Request 2. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR3] Bits */
#define MCAN_TXBCR_CR3_OFS                       (3)                             /* !< CR3 Offset */
#define MCAN_TXBCR_CR3_MASK                      ((uint32_t)0x00000008U)         /* !< Cancellation Request 3. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR4] Bits */
#define MCAN_TXBCR_CR4_OFS                       (4)                             /* !< CR4 Offset */
#define MCAN_TXBCR_CR4_MASK                      ((uint32_t)0x00000010U)         /* !< Cancellation Request 4. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR5] Bits */
#define MCAN_TXBCR_CR5_OFS                       (5)                             /* !< CR5 Offset */
#define MCAN_TXBCR_CR5_MASK                      ((uint32_t)0x00000020U)         /* !< Cancellation Request 5. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR6] Bits */
#define MCAN_TXBCR_CR6_OFS                       (6)                             /* !< CR6 Offset */
#define MCAN_TXBCR_CR6_MASK                      ((uint32_t)0x00000040U)         /* !< Cancellation Request 6. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR7] Bits */
#define MCAN_TXBCR_CR7_OFS                       (7)                             /* !< CR7 Offset */
#define MCAN_TXBCR_CR7_MASK                      ((uint32_t)0x00000080U)         /* !< Cancellation Request 7. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR8] Bits */
#define MCAN_TXBCR_CR8_OFS                       (8)                             /* !< CR8 Offset */
#define MCAN_TXBCR_CR8_MASK                      ((uint32_t)0x00000100U)         /* !< Cancellation Request 8. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR9] Bits */
#define MCAN_TXBCR_CR9_OFS                       (9)                             /* !< CR9 Offset */
#define MCAN_TXBCR_CR9_MASK                      ((uint32_t)0x00000200U)         /* !< Cancellation Request 9. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR10] Bits */
#define MCAN_TXBCR_CR10_OFS                      (10)                            /* !< CR10 Offset */
#define MCAN_TXBCR_CR10_MASK                     ((uint32_t)0x00000400U)         /* !< Cancellation Request 10. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR11] Bits */
#define MCAN_TXBCR_CR11_OFS                      (11)                            /* !< CR11 Offset */
#define MCAN_TXBCR_CR11_MASK                     ((uint32_t)0x00000800U)         /* !< Cancellation Request 11. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR12] Bits */
#define MCAN_TXBCR_CR12_OFS                      (12)                            /* !< CR12 Offset */
#define MCAN_TXBCR_CR12_MASK                     ((uint32_t)0x00001000U)         /* !< Cancellation Request 12. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR13] Bits */
#define MCAN_TXBCR_CR13_OFS                      (13)                            /* !< CR13 Offset */
#define MCAN_TXBCR_CR13_MASK                     ((uint32_t)0x00002000U)         /* !< Cancellation Request 13. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR14] Bits */
#define MCAN_TXBCR_CR14_OFS                      (14)                            /* !< CR14 Offset */
#define MCAN_TXBCR_CR14_MASK                     ((uint32_t)0x00004000U)         /* !< Cancellation Request 14. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR15] Bits */
#define MCAN_TXBCR_CR15_OFS                      (15)                            /* !< CR15 Offset */
#define MCAN_TXBCR_CR15_MASK                     ((uint32_t)0x00008000U)         /* !< Cancellation Request 15. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR16] Bits */
#define MCAN_TXBCR_CR16_OFS                      (16)                            /* !< CR16 Offset */
#define MCAN_TXBCR_CR16_MASK                     ((uint32_t)0x00010000U)         /* !< Cancellation Request 16. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR17] Bits */
#define MCAN_TXBCR_CR17_OFS                      (17)                            /* !< CR17 Offset */
#define MCAN_TXBCR_CR17_MASK                     ((uint32_t)0x00020000U)         /* !< Cancellation Request 17. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR18] Bits */
#define MCAN_TXBCR_CR18_OFS                      (18)                            /* !< CR18 Offset */
#define MCAN_TXBCR_CR18_MASK                     ((uint32_t)0x00040000U)         /* !< Cancellation Request 18. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR19] Bits */
#define MCAN_TXBCR_CR19_OFS                      (19)                            /* !< CR19 Offset */
#define MCAN_TXBCR_CR19_MASK                     ((uint32_t)0x00080000U)         /* !< Cancellation Request 19. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR20] Bits */
#define MCAN_TXBCR_CR20_OFS                      (20)                            /* !< CR20 Offset */
#define MCAN_TXBCR_CR20_MASK                     ((uint32_t)0x00100000U)         /* !< Cancellation Request 20. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR21] Bits */
#define MCAN_TXBCR_CR21_OFS                      (21)                            /* !< CR21 Offset */
#define MCAN_TXBCR_CR21_MASK                     ((uint32_t)0x00200000U)         /* !< Cancellation Request 21. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR22] Bits */
#define MCAN_TXBCR_CR22_OFS                      (22)                            /* !< CR22 Offset */
#define MCAN_TXBCR_CR22_MASK                     ((uint32_t)0x00400000U)         /* !< Cancellation Request 22. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR23] Bits */
#define MCAN_TXBCR_CR23_OFS                      (23)                            /* !< CR23 Offset */
#define MCAN_TXBCR_CR23_MASK                     ((uint32_t)0x00800000U)         /* !< Cancellation Request 23. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR24] Bits */
#define MCAN_TXBCR_CR24_OFS                      (24)                            /* !< CR24 Offset */
#define MCAN_TXBCR_CR24_MASK                     ((uint32_t)0x01000000U)         /* !< Cancellation Request 24. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR25] Bits */
#define MCAN_TXBCR_CR25_OFS                      (25)                            /* !< CR25 Offset */
#define MCAN_TXBCR_CR25_MASK                     ((uint32_t)0x02000000U)         /* !< Cancellation Request 25. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR26] Bits */
#define MCAN_TXBCR_CR26_OFS                      (26)                            /* !< CR26 Offset */
#define MCAN_TXBCR_CR26_MASK                     ((uint32_t)0x04000000U)         /* !< Cancellation Request 26. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR27] Bits */
#define MCAN_TXBCR_CR27_OFS                      (27)                            /* !< CR27 Offset */
#define MCAN_TXBCR_CR27_MASK                     ((uint32_t)0x08000000U)         /* !< Cancellation Request 27. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR28] Bits */
#define MCAN_TXBCR_CR28_OFS                      (28)                            /* !< CR28 Offset */
#define MCAN_TXBCR_CR28_MASK                     ((uint32_t)0x10000000U)         /* !< Cancellation Request 28. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR29] Bits */
#define MCAN_TXBCR_CR29_OFS                      (29)                            /* !< CR29 Offset */
#define MCAN_TXBCR_CR29_MASK                     ((uint32_t)0x20000000U)         /* !< Cancellation Request 29. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR30] Bits */
#define MCAN_TXBCR_CR30_OFS                      (30)                            /* !< CR30 Offset */
#define MCAN_TXBCR_CR30_MASK                     ((uint32_t)0x40000000U)         /* !< Cancellation Request 30. See
                                                                                    description for bit 0. */
/* MCAN_TXBCR[CR31] Bits */
#define MCAN_TXBCR_CR31_OFS                      (31)                            /* !< CR31 Offset */
#define MCAN_TXBCR_CR31_MASK                     ((uint32_t)0x80000000U)         /* !< Cancellation Request 31. See
                                                                                    description for bit 0. */

/* MCAN_TXBTO Bits */
/* MCAN_TXBTO[TO0] Bits */
#define MCAN_TXBTO_TO0_OFS                       (0)                             /* !< TO0 Offset */
#define MCAN_TXBTO_TO0_MASK                      ((uint32_t)0x00000001U)         /* !< Transmission Occurred 0.   Each Tx
                                                                                    Buffer has its own Transmission
                                                                                    Occurred bit. The bits are set when
                                                                                    the corresponding TXBRP bit is
                                                                                    cleared after a successful
                                                                                    transmission. The bits are reset when
                                                                                    a new transmission is requested by
                                                                                    writing a '1' to the corresponding
                                                                                    bit of register TXBAR.   0  No
                                                                                    transmission occurred   1
                                                                                    Transmission occurred */
/* MCAN_TXBTO[TO1] Bits */
#define MCAN_TXBTO_TO1_OFS                       (1)                             /* !< TO1 Offset */
#define MCAN_TXBTO_TO1_MASK                      ((uint32_t)0x00000002U)         /* !< Transmission Occurred 1. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO2] Bits */
#define MCAN_TXBTO_TO2_OFS                       (2)                             /* !< TO2 Offset */
#define MCAN_TXBTO_TO2_MASK                      ((uint32_t)0x00000004U)         /* !< Transmission Occurred 2. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO3] Bits */
#define MCAN_TXBTO_TO3_OFS                       (3)                             /* !< TO3 Offset */
#define MCAN_TXBTO_TO3_MASK                      ((uint32_t)0x00000008U)         /* !< Transmission Occurred 3. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO4] Bits */
#define MCAN_TXBTO_TO4_OFS                       (4)                             /* !< TO4 Offset */
#define MCAN_TXBTO_TO4_MASK                      ((uint32_t)0x00000010U)         /* !< Transmission Occurred 4. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO5] Bits */
#define MCAN_TXBTO_TO5_OFS                       (5)                             /* !< TO5 Offset */
#define MCAN_TXBTO_TO5_MASK                      ((uint32_t)0x00000020U)         /* !< Transmission Occurred 5. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO6] Bits */
#define MCAN_TXBTO_TO6_OFS                       (6)                             /* !< TO6 Offset */
#define MCAN_TXBTO_TO6_MASK                      ((uint32_t)0x00000040U)         /* !< Transmission Occurred 6. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO7] Bits */
#define MCAN_TXBTO_TO7_OFS                       (7)                             /* !< TO7 Offset */
#define MCAN_TXBTO_TO7_MASK                      ((uint32_t)0x00000080U)         /* !< Transmission Occurred 7. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO8] Bits */
#define MCAN_TXBTO_TO8_OFS                       (8)                             /* !< TO8 Offset */
#define MCAN_TXBTO_TO8_MASK                      ((uint32_t)0x00000100U)         /* !< Transmission Occurred 8. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO9] Bits */
#define MCAN_TXBTO_TO9_OFS                       (9)                             /* !< TO9 Offset */
#define MCAN_TXBTO_TO9_MASK                      ((uint32_t)0x00000200U)         /* !< Transmission Occurred 9. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO10] Bits */
#define MCAN_TXBTO_TO10_OFS                      (10)                            /* !< TO10 Offset */
#define MCAN_TXBTO_TO10_MASK                     ((uint32_t)0x00000400U)         /* !< Transmission Occurred 10. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO11] Bits */
#define MCAN_TXBTO_TO11_OFS                      (11)                            /* !< TO11 Offset */
#define MCAN_TXBTO_TO11_MASK                     ((uint32_t)0x00000800U)         /* !< Transmission Occurred 11. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO12] Bits */
#define MCAN_TXBTO_TO12_OFS                      (12)                            /* !< TO12 Offset */
#define MCAN_TXBTO_TO12_MASK                     ((uint32_t)0x00001000U)         /* !< Transmission Occurred 12. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO13] Bits */
#define MCAN_TXBTO_TO13_OFS                      (13)                            /* !< TO13 Offset */
#define MCAN_TXBTO_TO13_MASK                     ((uint32_t)0x00002000U)         /* !< Transmission Occurred 13. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO14] Bits */
#define MCAN_TXBTO_TO14_OFS                      (14)                            /* !< TO14 Offset */
#define MCAN_TXBTO_TO14_MASK                     ((uint32_t)0x00004000U)         /* !< Transmission Occurred 14. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO15] Bits */
#define MCAN_TXBTO_TO15_OFS                      (15)                            /* !< TO15 Offset */
#define MCAN_TXBTO_TO15_MASK                     ((uint32_t)0x00008000U)         /* !< Transmission Occurred 15. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO16] Bits */
#define MCAN_TXBTO_TO16_OFS                      (16)                            /* !< TO16 Offset */
#define MCAN_TXBTO_TO16_MASK                     ((uint32_t)0x00010000U)         /* !< Transmission Occurred 16. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO17] Bits */
#define MCAN_TXBTO_TO17_OFS                      (17)                            /* !< TO17 Offset */
#define MCAN_TXBTO_TO17_MASK                     ((uint32_t)0x00020000U)         /* !< Transmission Occurred 17. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO18] Bits */
#define MCAN_TXBTO_TO18_OFS                      (18)                            /* !< TO18 Offset */
#define MCAN_TXBTO_TO18_MASK                     ((uint32_t)0x00040000U)         /* !< Transmission Occurred 18. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO19] Bits */
#define MCAN_TXBTO_TO19_OFS                      (19)                            /* !< TO19 Offset */
#define MCAN_TXBTO_TO19_MASK                     ((uint32_t)0x00080000U)         /* !< Transmission Occurred 19. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO20] Bits */
#define MCAN_TXBTO_TO20_OFS                      (20)                            /* !< TO20 Offset */
#define MCAN_TXBTO_TO20_MASK                     ((uint32_t)0x00100000U)         /* !< Transmission Occurred 20. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO21] Bits */
#define MCAN_TXBTO_TO21_OFS                      (21)                            /* !< TO21 Offset */
#define MCAN_TXBTO_TO21_MASK                     ((uint32_t)0x00200000U)         /* !< Transmission Occurred 21. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO22] Bits */
#define MCAN_TXBTO_TO22_OFS                      (22)                            /* !< TO22 Offset */
#define MCAN_TXBTO_TO22_MASK                     ((uint32_t)0x00400000U)         /* !< Transmission Occurred 22. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO23] Bits */
#define MCAN_TXBTO_TO23_OFS                      (23)                            /* !< TO23 Offset */
#define MCAN_TXBTO_TO23_MASK                     ((uint32_t)0x00800000U)         /* !< Transmission Occurred 23. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO24] Bits */
#define MCAN_TXBTO_TO24_OFS                      (24)                            /* !< TO24 Offset */
#define MCAN_TXBTO_TO24_MASK                     ((uint32_t)0x01000000U)         /* !< Transmission Occurred 24. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO25] Bits */
#define MCAN_TXBTO_TO25_OFS                      (25)                            /* !< TO25 Offset */
#define MCAN_TXBTO_TO25_MASK                     ((uint32_t)0x02000000U)         /* !< Transmission Occurred 25. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO26] Bits */
#define MCAN_TXBTO_TO26_OFS                      (26)                            /* !< TO26 Offset */
#define MCAN_TXBTO_TO26_MASK                     ((uint32_t)0x04000000U)         /* !< Transmission Occurred 26. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO27] Bits */
#define MCAN_TXBTO_TO27_OFS                      (27)                            /* !< TO27 Offset */
#define MCAN_TXBTO_TO27_MASK                     ((uint32_t)0x08000000U)         /* !< Transmission Occurred 27. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO28] Bits */
#define MCAN_TXBTO_TO28_OFS                      (28)                            /* !< TO28 Offset */
#define MCAN_TXBTO_TO28_MASK                     ((uint32_t)0x10000000U)         /* !< Transmission Occurred 28. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO29] Bits */
#define MCAN_TXBTO_TO29_OFS                      (29)                            /* !< TO29 Offset */
#define MCAN_TXBTO_TO29_MASK                     ((uint32_t)0x20000000U)         /* !< Transmission Occurred 29. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO30] Bits */
#define MCAN_TXBTO_TO30_OFS                      (30)                            /* !< TO30 Offset */
#define MCAN_TXBTO_TO30_MASK                     ((uint32_t)0x40000000U)         /* !< Transmission Occurred 30. See
                                                                                    description for bit 0. */
/* MCAN_TXBTO[TO31] Bits */
#define MCAN_TXBTO_TO31_OFS                      (31)                            /* !< TO31 Offset */
#define MCAN_TXBTO_TO31_MASK                     ((uint32_t)0x80000000U)         /* !< Transmission Occurred 31. See
                                                                                    description for bit 0. */

/* MCAN_TXBCF Bits */
/* MCAN_TXBCF[CF0] Bits */
#define MCAN_TXBCF_CF0_OFS                       (0)                             /* !< CF0 Offset */
#define MCAN_TXBCF_CF0_MASK                      ((uint32_t)0x00000001U)         /* !< Cancellation Finished 0.   Each Tx
                                                                                    Buffer has its own Cancellation
                                                                                    Finished bit. The bits are set when
                                                                                    the corresponding TXBRP bit is
                                                                                    cleared after a cancellation was
                                                                                    requested via TXBCR. In case the
                                                                                    corresponding TXBRP bit was not set
                                                                                    at the point of cancellation, CF is
                                                                                    set immediately. The bits are reset
                                                                                    when a new transmission is requested
                                                                                    by writing a '1' to the corresponding
                                                                                    bit of register TXBAR.   0  No
                                                                                    transmit buffer cancellation   1
                                                                                    Transmit buffer cancellation finished */
/* MCAN_TXBCF[CF1] Bits */
#define MCAN_TXBCF_CF1_OFS                       (1)                             /* !< CF1 Offset */
#define MCAN_TXBCF_CF1_MASK                      ((uint32_t)0x00000002U)         /* !< Cancellation Finished 1. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF2] Bits */
#define MCAN_TXBCF_CF2_OFS                       (2)                             /* !< CF2 Offset */
#define MCAN_TXBCF_CF2_MASK                      ((uint32_t)0x00000004U)         /* !< Cancellation Finished 2. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF3] Bits */
#define MCAN_TXBCF_CF3_OFS                       (3)                             /* !< CF3 Offset */
#define MCAN_TXBCF_CF3_MASK                      ((uint32_t)0x00000008U)         /* !< Cancellation Finished 3. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF4] Bits */
#define MCAN_TXBCF_CF4_OFS                       (4)                             /* !< CF4 Offset */
#define MCAN_TXBCF_CF4_MASK                      ((uint32_t)0x00000010U)         /* !< Cancellation Finished 4. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF5] Bits */
#define MCAN_TXBCF_CF5_OFS                       (5)                             /* !< CF5 Offset */
#define MCAN_TXBCF_CF5_MASK                      ((uint32_t)0x00000020U)         /* !< Cancellation Finished 5. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF6] Bits */
#define MCAN_TXBCF_CF6_OFS                       (6)                             /* !< CF6 Offset */
#define MCAN_TXBCF_CF6_MASK                      ((uint32_t)0x00000040U)         /* !< Cancellation Finished 6. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF7] Bits */
#define MCAN_TXBCF_CF7_OFS                       (7)                             /* !< CF7 Offset */
#define MCAN_TXBCF_CF7_MASK                      ((uint32_t)0x00000080U)         /* !< Cancellation Finished 7. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF8] Bits */
#define MCAN_TXBCF_CF8_OFS                       (8)                             /* !< CF8 Offset */
#define MCAN_TXBCF_CF8_MASK                      ((uint32_t)0x00000100U)         /* !< Cancellation Finished 8. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF9] Bits */
#define MCAN_TXBCF_CF9_OFS                       (9)                             /* !< CF9 Offset */
#define MCAN_TXBCF_CF9_MASK                      ((uint32_t)0x00000200U)         /* !< Cancellation Finished 9. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF10] Bits */
#define MCAN_TXBCF_CF10_OFS                      (10)                            /* !< CF10 Offset */
#define MCAN_TXBCF_CF10_MASK                     ((uint32_t)0x00000400U)         /* !< Cancellation Finished 10. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF11] Bits */
#define MCAN_TXBCF_CF11_OFS                      (11)                            /* !< CF11 Offset */
#define MCAN_TXBCF_CF11_MASK                     ((uint32_t)0x00000800U)         /* !< Cancellation Finished 11. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF12] Bits */
#define MCAN_TXBCF_CF12_OFS                      (12)                            /* !< CF12 Offset */
#define MCAN_TXBCF_CF12_MASK                     ((uint32_t)0x00001000U)         /* !< Cancellation Finished 12. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF13] Bits */
#define MCAN_TXBCF_CF13_OFS                      (13)                            /* !< CF13 Offset */
#define MCAN_TXBCF_CF13_MASK                     ((uint32_t)0x00002000U)         /* !< Cancellation Finished 13. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF14] Bits */
#define MCAN_TXBCF_CF14_OFS                      (14)                            /* !< CF14 Offset */
#define MCAN_TXBCF_CF14_MASK                     ((uint32_t)0x00004000U)         /* !< Cancellation Finished 14. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF15] Bits */
#define MCAN_TXBCF_CF15_OFS                      (15)                            /* !< CF15 Offset */
#define MCAN_TXBCF_CF15_MASK                     ((uint32_t)0x00008000U)         /* !< Cancellation Finished 15. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF16] Bits */
#define MCAN_TXBCF_CF16_OFS                      (16)                            /* !< CF16 Offset */
#define MCAN_TXBCF_CF16_MASK                     ((uint32_t)0x00010000U)         /* !< Cancellation Finished 16. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF17] Bits */
#define MCAN_TXBCF_CF17_OFS                      (17)                            /* !< CF17 Offset */
#define MCAN_TXBCF_CF17_MASK                     ((uint32_t)0x00020000U)         /* !< Cancellation Finished 17. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF18] Bits */
#define MCAN_TXBCF_CF18_OFS                      (18)                            /* !< CF18 Offset */
#define MCAN_TXBCF_CF18_MASK                     ((uint32_t)0x00040000U)         /* !< Cancellation Finished 18. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF19] Bits */
#define MCAN_TXBCF_CF19_OFS                      (19)                            /* !< CF19 Offset */
#define MCAN_TXBCF_CF19_MASK                     ((uint32_t)0x00080000U)         /* !< Cancellation Finished 19. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF20] Bits */
#define MCAN_TXBCF_CF20_OFS                      (20)                            /* !< CF20 Offset */
#define MCAN_TXBCF_CF20_MASK                     ((uint32_t)0x00100000U)         /* !< Cancellation Finished 20. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF21] Bits */
#define MCAN_TXBCF_CF21_OFS                      (21)                            /* !< CF21 Offset */
#define MCAN_TXBCF_CF21_MASK                     ((uint32_t)0x00200000U)         /* !< Cancellation Finished 21. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF22] Bits */
#define MCAN_TXBCF_CF22_OFS                      (22)                            /* !< CF22 Offset */
#define MCAN_TXBCF_CF22_MASK                     ((uint32_t)0x00400000U)         /* !< Cancellation Finished 22. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF23] Bits */
#define MCAN_TXBCF_CF23_OFS                      (23)                            /* !< CF23 Offset */
#define MCAN_TXBCF_CF23_MASK                     ((uint32_t)0x00800000U)         /* !< Cancellation Finished 23. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF24] Bits */
#define MCAN_TXBCF_CF24_OFS                      (24)                            /* !< CF24 Offset */
#define MCAN_TXBCF_CF24_MASK                     ((uint32_t)0x01000000U)         /* !< Cancellation Finished 24. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF25] Bits */
#define MCAN_TXBCF_CF25_OFS                      (25)                            /* !< CF25 Offset */
#define MCAN_TXBCF_CF25_MASK                     ((uint32_t)0x02000000U)         /* !< Cancellation Finished 25. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF26] Bits */
#define MCAN_TXBCF_CF26_OFS                      (26)                            /* !< CF26 Offset */
#define MCAN_TXBCF_CF26_MASK                     ((uint32_t)0x04000000U)         /* !< Cancellation Finished 26. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF27] Bits */
#define MCAN_TXBCF_CF27_OFS                      (27)                            /* !< CF27 Offset */
#define MCAN_TXBCF_CF27_MASK                     ((uint32_t)0x08000000U)         /* !< Cancellation Finished 27. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF28] Bits */
#define MCAN_TXBCF_CF28_OFS                      (28)                            /* !< CF28 Offset */
#define MCAN_TXBCF_CF28_MASK                     ((uint32_t)0x10000000U)         /* !< Cancellation Finished 28. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF29] Bits */
#define MCAN_TXBCF_CF29_OFS                      (29)                            /* !< CF29 Offset */
#define MCAN_TXBCF_CF29_MASK                     ((uint32_t)0x20000000U)         /* !< Cancellation Finished 29. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF30] Bits */
#define MCAN_TXBCF_CF30_OFS                      (30)                            /* !< CF30 Offset */
#define MCAN_TXBCF_CF30_MASK                     ((uint32_t)0x40000000U)         /* !< Cancellation Finished 30. See
                                                                                    description for bit 0. */
/* MCAN_TXBCF[CF31] Bits */
#define MCAN_TXBCF_CF31_OFS                      (31)                            /* !< CF31 Offset */
#define MCAN_TXBCF_CF31_MASK                     ((uint32_t)0x80000000U)         /* !< Cancellation Finished 31. See
                                                                                    description for bit 0. */

/* MCAN_TXBTIE Bits */
/* MCAN_TXBTIE[TIE0] Bits */
#define MCAN_TXBTIE_TIE0_OFS                     (0)                             /* !< TIE0 Offset */
#define MCAN_TXBTIE_TIE0_MASK                    ((uint32_t)0x00000001U)         /* !< Transmission Interrupt Enable 0.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE1] Bits */
#define MCAN_TXBTIE_TIE1_OFS                     (1)                             /* !< TIE1 Offset */
#define MCAN_TXBTIE_TIE1_MASK                    ((uint32_t)0x00000002U)         /* !< Transmission Interrupt Enable 1.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE2] Bits */
#define MCAN_TXBTIE_TIE2_OFS                     (2)                             /* !< TIE2 Offset */
#define MCAN_TXBTIE_TIE2_MASK                    ((uint32_t)0x00000004U)         /* !< Transmission Interrupt Enable 2.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE3] Bits */
#define MCAN_TXBTIE_TIE3_OFS                     (3)                             /* !< TIE3 Offset */
#define MCAN_TXBTIE_TIE3_MASK                    ((uint32_t)0x00000008U)         /* !< Transmission Interrupt Enable 3.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE4] Bits */
#define MCAN_TXBTIE_TIE4_OFS                     (4)                             /* !< TIE4 Offset */
#define MCAN_TXBTIE_TIE4_MASK                    ((uint32_t)0x00000010U)         /* !< Transmission Interrupt Enable 4.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE5] Bits */
#define MCAN_TXBTIE_TIE5_OFS                     (5)                             /* !< TIE5 Offset */
#define MCAN_TXBTIE_TIE5_MASK                    ((uint32_t)0x00000020U)         /* !< Transmission Interrupt Enable 5.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE6] Bits */
#define MCAN_TXBTIE_TIE6_OFS                     (6)                             /* !< TIE6 Offset */
#define MCAN_TXBTIE_TIE6_MASK                    ((uint32_t)0x00000040U)         /* !< Transmission Interrupt Enable 6.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE7] Bits */
#define MCAN_TXBTIE_TIE7_OFS                     (7)                             /* !< TIE7 Offset */
#define MCAN_TXBTIE_TIE7_MASK                    ((uint32_t)0x00000080U)         /* !< Transmission Interrupt Enable 7.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE8] Bits */
#define MCAN_TXBTIE_TIE8_OFS                     (8)                             /* !< TIE8 Offset */
#define MCAN_TXBTIE_TIE8_MASK                    ((uint32_t)0x00000100U)         /* !< Transmission Interrupt Enable 8.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE9] Bits */
#define MCAN_TXBTIE_TIE9_OFS                     (9)                             /* !< TIE9 Offset */
#define MCAN_TXBTIE_TIE9_MASK                    ((uint32_t)0x00000200U)         /* !< Transmission Interrupt Enable 9.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE10] Bits */
#define MCAN_TXBTIE_TIE10_OFS                    (10)                            /* !< TIE10 Offset */
#define MCAN_TXBTIE_TIE10_MASK                   ((uint32_t)0x00000400U)         /* !< Transmission Interrupt Enable 10.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE11] Bits */
#define MCAN_TXBTIE_TIE11_OFS                    (11)                            /* !< TIE11 Offset */
#define MCAN_TXBTIE_TIE11_MASK                   ((uint32_t)0x00000800U)         /* !< Transmission Interrupt Enable 11.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE12] Bits */
#define MCAN_TXBTIE_TIE12_OFS                    (12)                            /* !< TIE12 Offset */
#define MCAN_TXBTIE_TIE12_MASK                   ((uint32_t)0x00001000U)         /* !< Transmission Interrupt Enable 12.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE13] Bits */
#define MCAN_TXBTIE_TIE13_OFS                    (13)                            /* !< TIE13 Offset */
#define MCAN_TXBTIE_TIE13_MASK                   ((uint32_t)0x00002000U)         /* !< Transmission Interrupt Enable 13.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE14] Bits */
#define MCAN_TXBTIE_TIE14_OFS                    (14)                            /* !< TIE14 Offset */
#define MCAN_TXBTIE_TIE14_MASK                   ((uint32_t)0x00004000U)         /* !< Transmission Interrupt Enable 14.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE15] Bits */
#define MCAN_TXBTIE_TIE15_OFS                    (15)                            /* !< TIE15 Offset */
#define MCAN_TXBTIE_TIE15_MASK                   ((uint32_t)0x00008000U)         /* !< Transmission Interrupt Enable 15.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE16] Bits */
#define MCAN_TXBTIE_TIE16_OFS                    (16)                            /* !< TIE16 Offset */
#define MCAN_TXBTIE_TIE16_MASK                   ((uint32_t)0x00010000U)         /* !< Transmission Interrupt Enable 16.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE17] Bits */
#define MCAN_TXBTIE_TIE17_OFS                    (17)                            /* !< TIE17 Offset */
#define MCAN_TXBTIE_TIE17_MASK                   ((uint32_t)0x00020000U)         /* !< Transmission Interrupt Enable 17.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE18] Bits */
#define MCAN_TXBTIE_TIE18_OFS                    (18)                            /* !< TIE18 Offset */
#define MCAN_TXBTIE_TIE18_MASK                   ((uint32_t)0x00040000U)         /* !< Transmission Interrupt Enable 18.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE19] Bits */
#define MCAN_TXBTIE_TIE19_OFS                    (19)                            /* !< TIE19 Offset */
#define MCAN_TXBTIE_TIE19_MASK                   ((uint32_t)0x00080000U)         /* !< Transmission Interrupt Enable 19.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE20] Bits */
#define MCAN_TXBTIE_TIE20_OFS                    (20)                            /* !< TIE20 Offset */
#define MCAN_TXBTIE_TIE20_MASK                   ((uint32_t)0x00100000U)         /* !< Transmission Interrupt Enable 20.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE21] Bits */
#define MCAN_TXBTIE_TIE21_OFS                    (21)                            /* !< TIE21 Offset */
#define MCAN_TXBTIE_TIE21_MASK                   ((uint32_t)0x00200000U)         /* !< Transmission Interrupt Enable 21.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE22] Bits */
#define MCAN_TXBTIE_TIE22_OFS                    (22)                            /* !< TIE22 Offset */
#define MCAN_TXBTIE_TIE22_MASK                   ((uint32_t)0x00400000U)         /* !< Transmission Interrupt Enable 22.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE23] Bits */
#define MCAN_TXBTIE_TIE23_OFS                    (23)                            /* !< TIE23 Offset */
#define MCAN_TXBTIE_TIE23_MASK                   ((uint32_t)0x00800000U)         /* !< Transmission Interrupt Enable 23.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE24] Bits */
#define MCAN_TXBTIE_TIE24_OFS                    (24)                            /* !< TIE24 Offset */
#define MCAN_TXBTIE_TIE24_MASK                   ((uint32_t)0x01000000U)         /* !< Transmission Interrupt Enable 24.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE25] Bits */
#define MCAN_TXBTIE_TIE25_OFS                    (25)                            /* !< TIE25 Offset */
#define MCAN_TXBTIE_TIE25_MASK                   ((uint32_t)0x02000000U)         /* !< Transmission Interrupt Enable 25.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE26] Bits */
#define MCAN_TXBTIE_TIE26_OFS                    (26)                            /* !< TIE26 Offset */
#define MCAN_TXBTIE_TIE26_MASK                   ((uint32_t)0x04000000U)         /* !< Transmission Interrupt Enable 26.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE27] Bits */
#define MCAN_TXBTIE_TIE27_OFS                    (27)                            /* !< TIE27 Offset */
#define MCAN_TXBTIE_TIE27_MASK                   ((uint32_t)0x08000000U)         /* !< Transmission Interrupt Enable 27.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE28] Bits */
#define MCAN_TXBTIE_TIE28_OFS                    (28)                            /* !< TIE28 Offset */
#define MCAN_TXBTIE_TIE28_MASK                   ((uint32_t)0x10000000U)         /* !< Transmission Interrupt Enable 28.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE29] Bits */
#define MCAN_TXBTIE_TIE29_OFS                    (29)                            /* !< TIE29 Offset */
#define MCAN_TXBTIE_TIE29_MASK                   ((uint32_t)0x20000000U)         /* !< Transmission Interrupt Enable 29.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE30] Bits */
#define MCAN_TXBTIE_TIE30_OFS                    (30)                            /* !< TIE30 Offset */
#define MCAN_TXBTIE_TIE30_MASK                   ((uint32_t)0x40000000U)         /* !< Transmission Interrupt Enable 30.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */
/* MCAN_TXBTIE[TIE31] Bits */
#define MCAN_TXBTIE_TIE31_OFS                    (31)                            /* !< TIE31 Offset */
#define MCAN_TXBTIE_TIE31_MASK                   ((uint32_t)0x80000000U)         /* !< Transmission Interrupt Enable 31.
                                                                                    Each Tx Buffer has its own
                                                                                    Transmission Interrupt Enable bit.
                                                                                    0  Transmission interrupt disabled
                                                                                    1  Transmission interrupt enable */

/* MCAN_TXBCIE Bits */
/* MCAN_TXBCIE[CFIE0] Bits */
#define MCAN_TXBCIE_CFIE0_OFS                    (0)                             /* !< CFIE0 Offset */
#define MCAN_TXBCIE_CFIE0_MASK                   ((uint32_t)0x00000001U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 0. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE1] Bits */
#define MCAN_TXBCIE_CFIE1_OFS                    (1)                             /* !< CFIE1 Offset */
#define MCAN_TXBCIE_CFIE1_MASK                   ((uint32_t)0x00000002U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 1. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE2] Bits */
#define MCAN_TXBCIE_CFIE2_OFS                    (2)                             /* !< CFIE2 Offset */
#define MCAN_TXBCIE_CFIE2_MASK                   ((uint32_t)0x00000004U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 2. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE3] Bits */
#define MCAN_TXBCIE_CFIE3_OFS                    (3)                             /* !< CFIE3 Offset */
#define MCAN_TXBCIE_CFIE3_MASK                   ((uint32_t)0x00000008U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 3. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE4] Bits */
#define MCAN_TXBCIE_CFIE4_OFS                    (4)                             /* !< CFIE4 Offset */
#define MCAN_TXBCIE_CFIE4_MASK                   ((uint32_t)0x00000010U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 4. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE5] Bits */
#define MCAN_TXBCIE_CFIE5_OFS                    (5)                             /* !< CFIE5 Offset */
#define MCAN_TXBCIE_CFIE5_MASK                   ((uint32_t)0x00000020U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 5. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE6] Bits */
#define MCAN_TXBCIE_CFIE6_OFS                    (6)                             /* !< CFIE6 Offset */
#define MCAN_TXBCIE_CFIE6_MASK                   ((uint32_t)0x00000040U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 6. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE7] Bits */
#define MCAN_TXBCIE_CFIE7_OFS                    (7)                             /* !< CFIE7 Offset */
#define MCAN_TXBCIE_CFIE7_MASK                   ((uint32_t)0x00000080U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 7. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE8] Bits */
#define MCAN_TXBCIE_CFIE8_OFS                    (8)                             /* !< CFIE8 Offset */
#define MCAN_TXBCIE_CFIE8_MASK                   ((uint32_t)0x00000100U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 8. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE9] Bits */
#define MCAN_TXBCIE_CFIE9_OFS                    (9)                             /* !< CFIE9 Offset */
#define MCAN_TXBCIE_CFIE9_MASK                   ((uint32_t)0x00000200U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 9. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE10] Bits */
#define MCAN_TXBCIE_CFIE10_OFS                   (10)                            /* !< CFIE10 Offset */
#define MCAN_TXBCIE_CFIE10_MASK                  ((uint32_t)0x00000400U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 10. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE11] Bits */
#define MCAN_TXBCIE_CFIE11_OFS                   (11)                            /* !< CFIE11 Offset */
#define MCAN_TXBCIE_CFIE11_MASK                  ((uint32_t)0x00000800U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 11. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE12] Bits */
#define MCAN_TXBCIE_CFIE12_OFS                   (12)                            /* !< CFIE12 Offset */
#define MCAN_TXBCIE_CFIE12_MASK                  ((uint32_t)0x00001000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 12. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE13] Bits */
#define MCAN_TXBCIE_CFIE13_OFS                   (13)                            /* !< CFIE13 Offset */
#define MCAN_TXBCIE_CFIE13_MASK                  ((uint32_t)0x00002000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 13. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE14] Bits */
#define MCAN_TXBCIE_CFIE14_OFS                   (14)                            /* !< CFIE14 Offset */
#define MCAN_TXBCIE_CFIE14_MASK                  ((uint32_t)0x00004000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 14. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE15] Bits */
#define MCAN_TXBCIE_CFIE15_OFS                   (15)                            /* !< CFIE15 Offset */
#define MCAN_TXBCIE_CFIE15_MASK                  ((uint32_t)0x00008000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 15. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE16] Bits */
#define MCAN_TXBCIE_CFIE16_OFS                   (16)                            /* !< CFIE16 Offset */
#define MCAN_TXBCIE_CFIE16_MASK                  ((uint32_t)0x00010000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 16. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE17] Bits */
#define MCAN_TXBCIE_CFIE17_OFS                   (17)                            /* !< CFIE17 Offset */
#define MCAN_TXBCIE_CFIE17_MASK                  ((uint32_t)0x00020000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 17. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE18] Bits */
#define MCAN_TXBCIE_CFIE18_OFS                   (18)                            /* !< CFIE18 Offset */
#define MCAN_TXBCIE_CFIE18_MASK                  ((uint32_t)0x00040000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 18. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE19] Bits */
#define MCAN_TXBCIE_CFIE19_OFS                   (19)                            /* !< CFIE19 Offset */
#define MCAN_TXBCIE_CFIE19_MASK                  ((uint32_t)0x00080000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 19. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE20] Bits */
#define MCAN_TXBCIE_CFIE20_OFS                   (20)                            /* !< CFIE20 Offset */
#define MCAN_TXBCIE_CFIE20_MASK                  ((uint32_t)0x00100000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 20. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE21] Bits */
#define MCAN_TXBCIE_CFIE21_OFS                   (21)                            /* !< CFIE21 Offset */
#define MCAN_TXBCIE_CFIE21_MASK                  ((uint32_t)0x00200000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 21. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE22] Bits */
#define MCAN_TXBCIE_CFIE22_OFS                   (22)                            /* !< CFIE22 Offset */
#define MCAN_TXBCIE_CFIE22_MASK                  ((uint32_t)0x00400000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 22. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE23] Bits */
#define MCAN_TXBCIE_CFIE23_OFS                   (23)                            /* !< CFIE23 Offset */
#define MCAN_TXBCIE_CFIE23_MASK                  ((uint32_t)0x00800000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 23. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE24] Bits */
#define MCAN_TXBCIE_CFIE24_OFS                   (24)                            /* !< CFIE24 Offset */
#define MCAN_TXBCIE_CFIE24_MASK                  ((uint32_t)0x01000000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 24. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE25] Bits */
#define MCAN_TXBCIE_CFIE25_OFS                   (25)                            /* !< CFIE25 Offset */
#define MCAN_TXBCIE_CFIE25_MASK                  ((uint32_t)0x02000000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 25. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE26] Bits */
#define MCAN_TXBCIE_CFIE26_OFS                   (26)                            /* !< CFIE26 Offset */
#define MCAN_TXBCIE_CFIE26_MASK                  ((uint32_t)0x04000000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 26. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE27] Bits */
#define MCAN_TXBCIE_CFIE27_OFS                   (27)                            /* !< CFIE27 Offset */
#define MCAN_TXBCIE_CFIE27_MASK                  ((uint32_t)0x08000000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 27. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE28] Bits */
#define MCAN_TXBCIE_CFIE28_OFS                   (28)                            /* !< CFIE28 Offset */
#define MCAN_TXBCIE_CFIE28_MASK                  ((uint32_t)0x10000000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 28. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE29] Bits */
#define MCAN_TXBCIE_CFIE29_OFS                   (29)                            /* !< CFIE29 Offset */
#define MCAN_TXBCIE_CFIE29_MASK                  ((uint32_t)0x20000000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 29. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE30] Bits */
#define MCAN_TXBCIE_CFIE30_OFS                   (30)                            /* !< CFIE30 Offset */
#define MCAN_TXBCIE_CFIE30_MASK                  ((uint32_t)0x40000000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 30. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */
/* MCAN_TXBCIE[CFIE31] Bits */
#define MCAN_TXBCIE_CFIE31_OFS                   (31)                            /* !< CFIE31 Offset */
#define MCAN_TXBCIE_CFIE31_MASK                  ((uint32_t)0x80000000U)         /* !< Cancellation Finished Interrupt
                                                                                    Enable 31. Each Tx Buffer has its own
                                                                                    Cancellation Finished Interrupt
                                                                                    Enable bit.   0  Cancellation
                                                                                    finished interrupt disabled   1
                                                                                    Cancellation finished interrupt
                                                                                    enabled */

/* MCAN_TXEFC Bits */
/* MCAN_TXEFC[EFSA] Bits */
#define MCAN_TXEFC_EFSA_OFS                      (2)                             /* !< EFSA Offset */
#define MCAN_TXEFC_EFSA_MASK                     ((uint32_t)0x0000FFFCU)         /* !< Event FIFO Start Address. Start
                                                                                    address of Tx Event FIFO in Message
                                                                                    RAM (32-bit word address). */
/* MCAN_TXEFC[EFS] Bits */
#define MCAN_TXEFC_EFS_OFS                       (16)                            /* !< EFS Offset */
#define MCAN_TXEFC_EFS_MASK                      ((uint32_t)0x003F0000U)         /* !< Event FIFO Size. The Tx Event FIFO
                                                                                    elements are indexed from 0 to EFS -
                                                                                    1.   0      Tx Event FIFO disabled
                                                                                    1-32  Number of Tx Event FIFO
                                                                                    elements   >32   Values greater than
                                                                                    32 are interpreted as 32 */
/* MCAN_TXEFC[EFWM] Bits */
#define MCAN_TXEFC_EFWM_OFS                      (24)                            /* !< EFWM Offset */
#define MCAN_TXEFC_EFWM_MASK                     ((uint32_t)0x3F000000U)         /* !< Event FIFO Watermark   0
                                                                                    Watermark interrupt disabled   1-32
                                                                                    Level for Tx Event FIFO watermark
                                                                                    interrupt (IR.TEFW)   >32   Watermark
                                                                                    interrupt disabled */

/* MCAN_TXEFS Bits */
/* MCAN_TXEFS[EFFL] Bits */
#define MCAN_TXEFS_EFFL_OFS                      (0)                             /* !< EFFL Offset */
#define MCAN_TXEFS_EFFL_MASK                     ((uint32_t)0x0000003FU)         /* !< Event FIFO Fill Level. Number of
                                                                                    elements stored in Tx Event FIFO,
                                                                                    range 0 to 32. */
/* MCAN_TXEFS[EFGI] Bits */
#define MCAN_TXEFS_EFGI_OFS                      (8)                             /* !< EFGI Offset */
#define MCAN_TXEFS_EFGI_MASK                     ((uint32_t)0x00001F00U)         /* !< Event FIFO Get Index. Tx Event FIFO
                                                                                    read index pointer, range 0 to 31. */
/* MCAN_TXEFS[EFPI] Bits */
#define MCAN_TXEFS_EFPI_OFS                      (16)                            /* !< EFPI Offset */
#define MCAN_TXEFS_EFPI_MASK                     ((uint32_t)0x001F0000U)         /* !< Event FIFO Put Index.Tx Event FIFO
                                                                                    write index pointer, range 0 to 31. */
/* MCAN_TXEFS[EFF] Bits */
#define MCAN_TXEFS_EFF_OFS                       (24)                            /* !< EFF Offset */
#define MCAN_TXEFS_EFF_MASK                      ((uint32_t)0x01000000U)         /* !< Event FIFO Full   0  Tx Event FIFO
                                                                                    not full   1  Tx Event FIFO full */
/* MCAN_TXEFS[TEFL] Bits */
#define MCAN_TXEFS_TEFL_OFS                      (25)                            /* !< TEFL Offset */
#define MCAN_TXEFS_TEFL_MASK                     ((uint32_t)0x02000000U)         /* !< Tx Event FIFO Element Lost. This
                                                                                    bit is a copy of interrupt flag
                                                                                    IR.TEFL. When IR.TEFL is reset, this
                                                                                    bit is also reset.   0  No Tx Event
                                                                                    FIFO element lost   1  Tx Event FIFO
                                                                                    element lost, also set after write
                                                                                    attempt to Tx Event FIFO of size
                                                                                    zero. */

/* MCAN_TXEFA Bits */
/* MCAN_TXEFA[EFAI] Bits */
#define MCAN_TXEFA_EFAI_OFS                      (0)                             /* !< EFAI Offset */
#define MCAN_TXEFA_EFAI_MASK                     ((uint32_t)0x0000001FU)         /* !< Event FIFO Acknowledge Index. After
                                                                                    the Host has read an element or a
                                                                                    sequence of elements from the Tx
                                                                                    Event FIFO it has to write the index
                                                                                    of the last element read from Tx
                                                                                    Event FIFO to EFAI. This will set the
                                                                                    Tx Event FIFO Get Index TXEFS.EFGI to
                                                                                    EFAI + 1 and update the Event FIFO
                                                                                    Fill Level TXEFS.EFFL. */

/* MCAN_PWREN Bits */
/* MCAN_PWREN[ENABLE] Bits */
#define MCAN_PWREN_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define MCAN_PWREN_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< Enable the power */
#define MCAN_PWREN_ENABLE_DISABLE                ((uint32_t)0x00000000U)         /* !< Disable Power */
#define MCAN_PWREN_ENABLE_ENABLE                 ((uint32_t)0x00000001U)         /* !< Enable Power */
/* MCAN_PWREN[KEY] Bits */
#define MCAN_PWREN_KEY_OFS                       (24)                            /* !< KEY Offset */
#define MCAN_PWREN_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define MCAN_PWREN_KEY_UNLOCK_W                  ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* MCAN_RSTCTL Bits */
/* MCAN_RSTCTL[RESETSTKYCLR] Bits */
#define MCAN_RSTCTL_RESETSTKYCLR_OFS             (1)                             /* !< RESETSTKYCLR Offset */
#define MCAN_RSTCTL_RESETSTKYCLR_MASK            ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define MCAN_RSTCTL_RESETSTKYCLR_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_RSTCTL_RESETSTKYCLR_CLR             ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* MCAN_RSTCTL[RESETASSERT] Bits */
#define MCAN_RSTCTL_RESETASSERT_OFS              (0)                             /* !< RESETASSERT Offset */
#define MCAN_RSTCTL_RESETASSERT_MASK             ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define MCAN_RSTCTL_RESETASSERT_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define MCAN_RSTCTL_RESETASSERT_ASSERT           ((uint32_t)0x00000001U)         /* !< Assert reset */
/* MCAN_RSTCTL[KEY] Bits */
#define MCAN_RSTCTL_KEY_OFS                      (24)                            /* !< KEY Offset */
#define MCAN_RSTCTL_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define MCAN_RSTCTL_KEY_UNLOCK_W                 ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* MCAN_STAT Bits */
/* MCAN_STAT[RESETSTKY] Bits */
#define MCAN_STAT_RESETSTKY_OFS                  (16)                            /* !< RESETSTKY Offset */
#define MCAN_STAT_RESETSTKY_MASK                 ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define MCAN_STAT_RESETSTKY_NORES                ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define MCAN_STAT_RESETSTKY_RESET                ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_mcan__include */
