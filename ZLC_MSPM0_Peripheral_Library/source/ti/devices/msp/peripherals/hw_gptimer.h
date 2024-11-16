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

#ifndef ti_devices_msp_peripherals_hw_gptimer__include
#define ti_devices_msp_peripherals_hw_gptimer__include

/* Filename: hw_gptimer.h */
/* Revised: 2024-06-04 10:48:04 */
/* Revision: a6be75578aae0bf7330b042a9fb5c36fc4988a43 */

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
* GPTIMER Registers
******************************************************************************/
#define GPTIMER_COUNTERREGS_OFS                  ((uint32_t)0x00001800U)
#define GPTIMER_COMMONREGS_OFS                   ((uint32_t)0x00001100U)
#define GPTIMER_GEN_EVENT1_OFS                   ((uint32_t)0x00001080U)
#define GPTIMER_GEN_EVENT0_OFS                   ((uint32_t)0x00001050U)
#define GPTIMER_CPU_INT_OFS                      ((uint32_t)0x00001020U)
#define GPTIMER_GPRCM_OFS                        ((uint32_t)0x00000800U)


/** @addtogroup GPTIMER_COUNTERREGS
  @{
*/

typedef struct {
  __IO uint32_t CTR;                               /* !< (@ 0x00001800) Counter Register */
  __IO uint32_t CTRCTL;                            /* !< (@ 0x00001804) Counter Control Register */
  __IO uint32_t LOAD;                              /* !< (@ 0x00001808) Load Register */
       uint32_t RESERVED0;
  __IO uint32_t CC_01[2];                          /* !< (@ 0x00001810) Capture or Compare Register 0/1 */
  __IO uint32_t CC_23[2];                          /* !< (@ 0x00001818) Capture or Compare Register 2/3 */
  __IO uint32_t CC_45[2];                          /* !< (@ 0x00001820) The CC_45 register are a registers which can be
                                                      used as compare to the current CTR to create an events CC4U, CC4D,
                                                      CC5U and CC5D. */
       uint32_t RESERVED1[2];
  __IO uint32_t CCCTL_01[2];                       /* !< (@ 0x00001830) Capture or Compare Control Registers 0/1 */
  __IO uint32_t CCCTL_23[2];                       /* !< (@ 0x00001838) Capture or Compare Control Registers 2/3 */
  __IO uint32_t CCCTL_45[2];                       /* !< (@ 0x00001840) Capture or Compare Control Registers 4/5 */
       uint32_t RESERVED2[2];
  __IO uint32_t OCTL_01[2];                        /* !< (@ 0x00001850) CCP Output Control Registers 0/1 */
  __IO uint32_t OCTL_23[2];                        /* !< (@ 0x00001858) CCP Output Control Registers 2/3 */
       uint32_t RESERVED3[4];
  __IO uint32_t CCACT_01[2];                       /* !< (@ 0x00001870) Capture or Compare Action Registers 0/1 */
  __IO uint32_t CCACT_23[2];                       /* !< (@ 0x00001878) Capture or Compare Action Registers 2/3 */
  __IO uint32_t IFCTL_01[2];                       /* !< (@ 0x00001880) Input Filter Control Register 0/1 */
  __IO uint32_t IFCTL_23[2];                       /* !< (@ 0x00001888) Input Filter Control Register 2/3 */
       uint32_t RESERVED4[4];
  __IO uint32_t PL;                                /* !< (@ 0x000018A0) Phase Load Register */
  __IO uint32_t DBCTL;                             /* !< (@ 0x000018A4) Dead Band insertion control register */
       uint32_t RESERVED5[2];
  __IO uint32_t TSEL;                              /* !< (@ 0x000018B0) Trigger Select Register */
  __I  uint32_t RC;                                /* !< (@ 0x000018B4) Repeat counter Register */
  __IO uint32_t RCLD;                              /* !< (@ 0x000018B8) Repeat counter load Register */
  __I  uint32_t QDIR;                              /* !< (@ 0x000018BC) QEI Count Direction Register */
       uint32_t RESERVED6[4];
  __IO uint32_t FCTL;                              /* !< (@ 0x000018D0) Fault Control Register */
  __IO uint32_t FIFCTL;                            /* !< (@ 0x000018D4) Fault input Filter control register */
} GPTIMER_COUNTERREGS_Regs;

/*@}*/ /* end of group GPTIMER_COUNTERREGS */

/** @addtogroup GPTIMER_COMMONREGS
  @{
*/

typedef struct {
  __IO uint32_t CCPD;                              /* !< (@ 0x00001100) CCP Direction */
  __IO uint32_t ODIS;                              /* !< (@ 0x00001104) Output Disable */
  __IO uint32_t CCLKCTL;                           /* !< (@ 0x00001108) Counter Clock Control Register */
  __IO uint32_t CPS;                               /* !< (@ 0x0000110C) Clock Prescale Register */
  __I  uint32_t CPSV;                              /* !< (@ 0x00001110) Clock prescale count status register */
  __IO uint32_t CTTRIGCTL;                         /* !< (@ 0x00001114) Timer Cross Trigger Control Register */
       uint32_t RESERVED0;
  __O  uint32_t CTTRIG;                            /* !< (@ 0x0000111C) Timer Cross Trigger Register */
  __IO uint32_t FSCTL;                             /* !< (@ 0x00001120) Fault Source Control */
  __IO uint32_t GCTL;                              /* !< (@ 0x00001124) Global control register */
} GPTIMER_COMMONREGS_Regs;

/*@}*/ /* end of group GPTIMER_COMMONREGS */

/** @addtogroup GPTIMER_GEN_EVENT1
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
} GPTIMER_GEN_EVENT1_Regs;

/*@}*/ /* end of group GPTIMER_GEN_EVENT1 */

/** @addtogroup GPTIMER_GEN_EVENT0
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
} GPTIMER_GEN_EVENT0_Regs;

/*@}*/ /* end of group GPTIMER_GEN_EVENT0 */

/** @addtogroup GPTIMER_CPU_INT
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
} GPTIMER_CPU_INT_Regs;

/*@}*/ /* end of group GPTIMER_CPU_INT */

/** @addtogroup GPTIMER_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} GPTIMER_GPRCM_Regs;

/*@}*/ /* end of group GPTIMER_GPRCM */

/** @addtogroup GPTIMER
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
  GPTIMER_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED3[506];
  __IO uint32_t CLKDIV;                            /* !< (@ 0x00001000) Clock Divider */
       uint32_t RESERVED4;
  __IO uint32_t CLKSEL;                            /* !< (@ 0x00001008) Clock Select for Ultra Low Power peripherals */
       uint32_t RESERVED5[3];
  __IO uint32_t PDBGCTL;                           /* !< (@ 0x00001018) Peripheral Debug Control */
       uint32_t RESERVED6;
  GPTIMER_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED7;
  GPTIMER_GEN_EVENT0_Regs  GEN_EVENT0;                        /* !< (@ 0x00001050) */
       uint32_t RESERVED8;
  GPTIMER_GEN_EVENT1_Regs  GEN_EVENT1;                        /* !< (@ 0x00001080) */
       uint32_t RESERVED9[13];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED10[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
  GPTIMER_COMMONREGS_Regs  COMMONREGS;                        /* !< (@ 0x00001100) */
       uint32_t RESERVED11[438];
  GPTIMER_COUNTERREGS_Regs  COUNTERREGS;                       /* !< (@ 0x00001800) */
} GPTIMER_Regs;

/*@}*/ /* end of group GPTIMER */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* GPTIMER Register Control Bits
******************************************************************************/

/* GPTIMER_CTR Bits */
/* GPTIMER_CTR[CCTR] Bits */
#define GPTIMER_CTR_CCTR_OFS                     (0)                             /* !< CCTR Offset */
#define GPTIMER_CTR_CCTR_MASK                    ((uint32_t)0xFFFFFFFFU)         /* !< Current Counter value */
#define GPTIMER_CTR_CCTR_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_CTR_CCTR_MAXIMUM                 ((uint32_t)0xFFFFFFFFU)         /* !< Maximum Value */

/* GPTIMER_CTRCTL Bits */
/* GPTIMER_CTRCTL[EN] Bits */
#define GPTIMER_CTRCTL_EN_OFS                    (0)                             /* !< EN Offset */
#define GPTIMER_CTRCTL_EN_MASK                   ((uint32_t)0x00000001U)         /* !< Counter Enable.  This bit allows
                                                                                    the timer to advance  This bit is
                                                                                    automatically cleared if REPEAT=0 (do
                                                                                    not automatically reload) and the
                                                                                    counter value equals zero.  CPU
                                                                                    Write: A register write that sets the
                                                                                    EN bit, the counter value is set per
                                                                                    the CVAE value. Hardware: This bit
                                                                                    may also be set as the result of an
                                                                                    LCOND or ZCOND condition being met
                                                                                    and the counter value changed to the
                                                                                    load value or zero value,
                                                                                    respectively. */
#define GPTIMER_CTRCTL_EN_DISABLED               ((uint32_t)0x00000000U)         /* !< Disabled */
#define GPTIMER_CTRCTL_EN_ENABLED                ((uint32_t)0x00000001U)         /* !< Enabled */
/* GPTIMER_CTRCTL[REPEAT] Bits */
#define GPTIMER_CTRCTL_REPEAT_OFS                (1)                             /* !< REPEAT Offset */
#define GPTIMER_CTRCTL_REPEAT_MASK               ((uint32_t)0x0000000EU)         /* !< Repeat.  The repeat bit controls
                                                                                    whether the counter continues to
                                                                                    advance following a zero event, or
                                                                                    the exiting of a debug or fault
                                                                                    condition.  If counting down, a zero
                                                                                    event is followed by a load at the
                                                                                    next advance condition. If counting
                                                                                    up-down, a zero event is followed by
                                                                                    an advance event (+1). The intent of
                                                                                    encoding 3 is that if the debug
                                                                                    condition is in effect, the
                                                                                    generation of the load pulse is
                                                                                    deferred until the debug condition is
                                                                                    over. This allows the counter to
                                                                                    reach zero before counting is
                                                                                    suspended. */
#define GPTIMER_CTRCTL_REPEAT_REPEAT_0           ((uint32_t)0x00000000U)         /* !< Does not automatically advance
                                                                                    following a zero event. */
#define GPTIMER_CTRCTL_REPEAT_REPEAT_1           ((uint32_t)0x00000002U)         /* !< Continues to advance following a
                                                                                    zero event. */
#define GPTIMER_CTRCTL_REPEAT_REPEAT_2           ((uint32_t)0x00000004U)         /* !< Reserved */
#define GPTIMER_CTRCTL_REPEAT_REPEAT_3           ((uint32_t)0x00000006U)         /* !< Continues to advance following a
                                                                                    zero event if the debug mode is not
                                                                                    in effect, or following the release
                                                                                    of the debug mode. */
#define GPTIMER_CTRCTL_REPEAT_REPEAT_4           ((uint32_t)0x00000008U)         /* !< Reserved */
/* GPTIMER_CTRCTL[CM] Bits */
#define GPTIMER_CTRCTL_CM_OFS                    (4)                             /* !< CM Offset */
#define GPTIMER_CTRCTL_CM_MASK                   ((uint32_t)0x00000030U)         /* !< Count Mode */
#define GPTIMER_CTRCTL_CM_DOWN                   ((uint32_t)0x00000000U)         /* !< Down */
#define GPTIMER_CTRCTL_CM_UP_DOWN                ((uint32_t)0x00000010U)         /* !< Up/Down */
#define GPTIMER_CTRCTL_CM_UP                     ((uint32_t)0x00000020U)         /* !< Counter counts up. */
/* GPTIMER_CTRCTL[CVAE] Bits */
#define GPTIMER_CTRCTL_CVAE_OFS                  (28)                            /* !< CVAE Offset */
#define GPTIMER_CTRCTL_CVAE_MASK                 ((uint32_t)0x30000000U)         /* !< Counter Value After Enable.  This
                                                                                    field specifies the initialization
                                                                                    condition of the counter when the EN
                                                                                    bit is changed from 0 to 1 by a write
                                                                                    to the CTRCTL register. Note that an
                                                                                    external event can also cause the EN
                                                                                    bit to go active. */
#define GPTIMER_CTRCTL_CVAE_LDVAL                ((uint32_t)0x00000000U)         /* !< The counter is set to the LOAD
                                                                                    register value */
#define GPTIMER_CTRCTL_CVAE_NOCHANGE             ((uint32_t)0x10000000U)         /* !< The counter value is unchanged from
                                                                                    its current value which could have
                                                                                    been initialized by software */
#define GPTIMER_CTRCTL_CVAE_ZEROVAL              ((uint32_t)0x20000000U)         /* !< The counter is set to zero */
/* GPTIMER_CTRCTL[DRB] Bits */
#define GPTIMER_CTRCTL_DRB_OFS                   (17)                            /* !< DRB Offset */
#define GPTIMER_CTRCTL_DRB_MASK                  ((uint32_t)0x00020000U)         /* !< Debug Resume Behavior This bit
                                                                                    specifies what the device does
                                                                                    following the release/exit of debug
                                                                                    mode. */
#define GPTIMER_CTRCTL_DRB_RESUME                ((uint32_t)0x00000000U)         /* !< Resume counting */
#define GPTIMER_CTRCTL_DRB_CVAE_ACTION           ((uint32_t)0x00020000U)         /* !< Perform the action as specified by
                                                                                    the CVAE field. */
/* GPTIMER_CTRCTL[FB] Bits */
#define GPTIMER_CTRCTL_FB_OFS                    (18)                            /* !< FB Offset */
#define GPTIMER_CTRCTL_FB_MASK                   ((uint32_t)0x00040000U)         /* !< Fault Behavior This bit specifies
                                                                                    whether the counter continues running
                                                                                    or suspends during a fault mode.
                                                                                    There is a separate control under
                                                                                    REPEAT to indicate whether counting
                                                                                    is to suspend at next Counter==0 */
#define GPTIMER_CTRCTL_FB_CONT_COUNT             ((uint32_t)0x00000000U)         /* !< Continues counting */
#define GPTIMER_CTRCTL_FB_SUSP_COUNT             ((uint32_t)0x00040000U)         /* !< Suspends counting */
/* GPTIMER_CTRCTL[FRB] Bits */
#define GPTIMER_CTRCTL_FRB_OFS                   (19)                            /* !< FRB Offset */
#define GPTIMER_CTRCTL_FRB_MASK                  ((uint32_t)0x00080000U)         /* !< Fault Resume Behavior This bit
                                                                                    specifies what the device does
                                                                                    following the release/exit of fault
                                                                                    condition. */
#define GPTIMER_CTRCTL_FRB_RESUME                ((uint32_t)0x00000000U)         /* !< Resume counting */
#define GPTIMER_CTRCTL_FRB_CVAE_ACTION           ((uint32_t)0x00080000U)         /* !< Perform the action as specified by
                                                                                    the CVAE field. */
/* GPTIMER_CTRCTL[PLEN] Bits */
#define GPTIMER_CTRCTL_PLEN_OFS                  (24)                            /* !< PLEN Offset */
#define GPTIMER_CTRCTL_PLEN_MASK                 ((uint32_t)0x01000000U)         /* !< Phase Load Enable.  This bit allows
                                                                                    the timer to have phase load feature. */
#define GPTIMER_CTRCTL_PLEN_DISABLED             ((uint32_t)0x00000000U)         /* !< Disabled */
#define GPTIMER_CTRCTL_PLEN_ENABLED              ((uint32_t)0x01000000U)         /* !< Enabled */
/* GPTIMER_CTRCTL[SLZERCNEZ] Bits */
#define GPTIMER_CTRCTL_SLZERCNEZ_OFS             (23)                            /* !< SLZERCNEZ Offset */
#define GPTIMER_CTRCTL_SLZERCNEZ_MASK            ((uint32_t)0x00800000U)         /* !< Suppress Load and Zero Events if
                                                                                    Repeat Counter is Not Equal to Zero.
                                                                                    This bit suppresses the generation of
                                                                                    the Z (zero) and L (load) events from
                                                                                    the counter when the repeat counter
                                                                                    (RC) value is not 0. */
#define GPTIMER_CTRCTL_SLZERCNEZ_DISABLED        ((uint32_t)0x00000000U)         /* !< Disabled. Z and L events are always
                                                                                    generated from the counter when their
                                                                                    conditions are generated. */
#define GPTIMER_CTRCTL_SLZERCNEZ_ENABLED         ((uint32_t)0x00800000U)         /* !< Enabled. Z and L events are
                                                                                    generated from the counter when their
                                                                                    conditions are generated and the RC
                                                                                    register value is 0. */
/* GPTIMER_CTRCTL[CLC] Bits */
#define GPTIMER_CTRCTL_CLC_OFS                   (7)                             /* !< CLC Offset */
#define GPTIMER_CTRCTL_CLC_MASK                  ((uint32_t)0x00000380U)         /* !< Counter Load Control.  This field
                                                                                    specifies what controls the counter
                                                                                    operation with respect to setting the
                                                                                    counter to the LD register value.
                                                                                    Encodings 1-3 are present based on
                                                                                    the CCPC parameter value. Bits 4-5
                                                                                    are present based on the HQEI
                                                                                    parameter value. Any encodings not
                                                                                    provided are documented as reserved. */
#define GPTIMER_CTRCTL_CLC_CCCTL0_LCOND          ((uint32_t)0x00000000U)         /* !< CCCTL_0 LCOND */
#define GPTIMER_CTRCTL_CLC_CCCTL1_LCOND          ((uint32_t)0x00000080U)         /* !< CCCTL_1 LCOND */
#define GPTIMER_CTRCTL_CLC_CCCTL2_LCOND          ((uint32_t)0x00000100U)         /* !< CCCTL_2 LCOND This value exists
                                                                                    when there are 4 channels. */
#define GPTIMER_CTRCTL_CLC_CCCTL3_LCOND          ((uint32_t)0x00000180U)         /* !< CCCTL_3 LCOND This value exists
                                                                                    when there are 4 channels. */
#define GPTIMER_CTRCTL_CLC_QEI_2INP              ((uint32_t)0x00000200U)         /* !< Controlled by 2 input QEI mode.
                                                                                    This value exists when TIMER support
                                                                                    QEI feature. */
#define GPTIMER_CTRCTL_CLC_QEI_3INP              ((uint32_t)0x00000280U)         /* !< Controlled by 3 input QEI mode.
                                                                                    This value exists when TIMER support
                                                                                    QEI feature. */
/* GPTIMER_CTRCTL[CAC] Bits */
#define GPTIMER_CTRCTL_CAC_OFS                   (10)                            /* !< CAC Offset */
#define GPTIMER_CTRCTL_CAC_MASK                  ((uint32_t)0x00001C00U)         /* !< Counter Advance Control.  This
                                                                                    field specifies what controls the
                                                                                    counter operation with respect to
                                                                                    advancing (incrementing or
                                                                                    decrementing) the counter value.
                                                                                    Encodings 1-3 are present based on
                                                                                    the CCPC parameter value. Bits 4-5
                                                                                    are present based on the HQEI
                                                                                    parameter value. Any encodings not
                                                                                    provided are documented as reserved. */
#define GPTIMER_CTRCTL_CAC_CCCTL0_ACOND          ((uint32_t)0x00000000U)         /* !< CCCTL_0 ACOND */
#define GPTIMER_CTRCTL_CAC_CCCTL1_ACOND          ((uint32_t)0x00000400U)         /* !< CCCTL_1 ACOND */
#define GPTIMER_CTRCTL_CAC_CCCTL2_ACOND          ((uint32_t)0x00000800U)         /* !< CCCTL_2 ACOND This value exists
                                                                                    when there are 4 channels. */
#define GPTIMER_CTRCTL_CAC_CCCTL3_ACOND          ((uint32_t)0x00000C00U)         /* !< CCCTL_3 ACOND This value exists
                                                                                    when there are 4 channels. */
#define GPTIMER_CTRCTL_CAC_QEI_2INP              ((uint32_t)0x00001000U)         /* !< Controlled by 2-input QEI mode
                                                                                    This value exists when TIMER support
                                                                                    QEI feature. */
#define GPTIMER_CTRCTL_CAC_QEI_3INP              ((uint32_t)0x00001400U)         /* !< Controlled by 3-input QEI mode
                                                                                    This value exists when TIMER support
                                                                                    QEI feature. */
/* GPTIMER_CTRCTL[CZC] Bits */
#define GPTIMER_CTRCTL_CZC_OFS                   (13)                            /* !< CZC Offset */
#define GPTIMER_CTRCTL_CZC_MASK                  ((uint32_t)0x0000E000U)         /* !< Counter Zero Control This field
                                                                                    specifies what controls the counter
                                                                                    operation with respect to zeroing the
                                                                                    counter value.    Encodings 1-3 are
                                                                                    present based on the CCPC parameter
                                                                                    value. Bits 4-5 are present based on
                                                                                    the HQEI parameter value. Any
                                                                                    encodings not provided are documented
                                                                                    as reserved. */
#define GPTIMER_CTRCTL_CZC_CCCTL0_ZCOND          ((uint32_t)0x00000000U)         /* !< CCCTL_0 ZCOND */
#define GPTIMER_CTRCTL_CZC_CCCTL1_ZCOND          ((uint32_t)0x00002000U)         /* !< CCCTL_1 ZCOND */
#define GPTIMER_CTRCTL_CZC_CCCTL2_ZCOND          ((uint32_t)0x00004000U)         /* !< CCCTL_2 ZCOND This value exists
                                                                                    when there are 4 channels. */
#define GPTIMER_CTRCTL_CZC_CCCTL3_ZCOND          ((uint32_t)0x00006000U)         /* !< CCCTL_3 ZCOND This value exists
                                                                                    when there are 4 channels. */
#define GPTIMER_CTRCTL_CZC_QEI_2INP              ((uint32_t)0x00008000U)         /* !< Controlled by 2-input QEI mode
                                                                                    This value exists when TIMER support
                                                                                    QEI feature. */
#define GPTIMER_CTRCTL_CZC_QEI_3INP              ((uint32_t)0x0000A000U)         /* !< Controlled by 3-input QEI mode
                                                                                    This value exists when TIMER support
                                                                                    QEI feature. */

/* GPTIMER_LOAD Bits */
/* GPTIMER_LOAD[LD] Bits */
#define GPTIMER_LOAD_LD_OFS                      (0)                             /* !< LD Offset */
#define GPTIMER_LOAD_LD_MASK                     ((uint32_t)0xFFFFFFFFU)         /* !< Load Value */
#define GPTIMER_LOAD_LD_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_LOAD_LD_MAXIMUM                  ((uint32_t)0xFFFFFFFFU)         /* !< Maximum Value */

/* GPTIMER_CC_01 Bits */
/* GPTIMER_CC_01[CCVAL] Bits */
#define GPTIMER_CC_01_CCVAL_OFS                  (0)                             /* !< CCVAL Offset */
#define GPTIMER_CC_01_CCVAL_MASK                 ((uint32_t)0xFFFFFFFFU)         /* !< Capture or compare value */
#define GPTIMER_CC_01_CCVAL_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_CC_01_CCVAL_MAXIMUM              ((uint32_t)0xFFFFFFFFU)         /* !< Maximum Value */

/* GPTIMER_CC_23 Bits */
/* GPTIMER_CC_23[CCVAL] Bits */
#define GPTIMER_CC_23_CCVAL_OFS                  (0)                             /* !< CCVAL Offset */
#define GPTIMER_CC_23_CCVAL_MASK                 ((uint32_t)0xFFFFFFFFU)         /* !< Capture or compare value */
#define GPTIMER_CC_23_CCVAL_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_CC_23_CCVAL_MAXIMUM              ((uint32_t)0xFFFFFFFFU)         /* !< Maximum Value */

/* GPTIMER_CC_45 Bits */
/* GPTIMER_CC_45[CCVAL] Bits */
#define GPTIMER_CC_45_CCVAL_OFS                  (0)                             /* !< CCVAL Offset */
#define GPTIMER_CC_45_CCVAL_MASK                 ((uint32_t)0xFFFFFFFFU)         /* !< Capture or compare value */
#define GPTIMER_CC_45_CCVAL_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_CC_45_CCVAL_MAXIMUM              ((uint32_t)0xFFFFFFFFU)         /* !< Maximum Value */

/* GPTIMER_CCCTL_01 Bits */
/* GPTIMER_CCCTL_01[CCOND] Bits */
#define GPTIMER_CCCTL_01_CCOND_OFS               (0)                             /* !< CCOND Offset */
#define GPTIMER_CCCTL_01_CCOND_MASK              ((uint32_t)0x00000007U)         /* !< Capture Condition. #br# Specifies
                                                                                    the condition that generates a
                                                                                    capture pulse. */
#define GPTIMER_CCCTL_01_CCOND_NOCAPTURE         ((uint32_t)0x00000000U)         /* !< None (never captures) */
#define GPTIMER_CCCTL_01_CCOND_CC_TRIG_RISE      ((uint32_t)0x00000001U)         /* !< Rising edge of CCP or trigger
                                                                                    assertion edge */
#define GPTIMER_CCCTL_01_CCOND_CC_TRIG_FALL      ((uint32_t)0x00000002U)         /* !< Falling edge of CCP or trigger
                                                                                    de-assertion edge */
#define GPTIMER_CCCTL_01_CCOND_CC_TRIG_EDGE      ((uint32_t)0x00000003U)         /* !< Either edge of CCP or trigger
                                                                                    change (assertion/de-assertion edge) */
/* GPTIMER_CCCTL_01[ACOND] Bits */
#define GPTIMER_CCCTL_01_ACOND_OFS               (4)                             /* !< ACOND Offset */
#define GPTIMER_CCCTL_01_ACOND_MASK              ((uint32_t)0x00000070U)         /* !< Advance Condition. #br# Specifies
                                                                                    the condition that generates an
                                                                                    advance pulse. */
#define GPTIMER_CCCTL_01_ACOND_TIMCLK            ((uint32_t)0x00000000U)         /* !< Each TIMCLK */
#define GPTIMER_CCCTL_01_ACOND_CC_TRIG_RISE      ((uint32_t)0x00000010U)         /* !< Rising edge of CCP or trigger
                                                                                    assertion edge */
#define GPTIMER_CCCTL_01_ACOND_CC_TRIG_FALL      ((uint32_t)0x00000020U)         /* !< Falling edge of CCP or trigger
                                                                                    de-assertion edge */
#define GPTIMER_CCCTL_01_ACOND_CC_TRIG_EDGE      ((uint32_t)0x00000030U)         /* !< Either edge of CCP or trigger
                                                                                    change (assertion/de-assertion edge) */
#define GPTIMER_CCCTL_01_ACOND_CC_TRIG_HIGH      ((uint32_t)0x00000050U)         /* !< CCP High or Trigger assertion
                                                                                    (level) */
/* GPTIMER_CCCTL_01[LCOND] Bits */
#define GPTIMER_CCCTL_01_LCOND_OFS               (8)                             /* !< LCOND Offset */
#define GPTIMER_CCCTL_01_LCOND_MASK              ((uint32_t)0x00000700U)         /* !< Load Condition. #br# Specifies the
                                                                                    condition that generates a load
                                                                                    pulse. */
#define GPTIMER_CCCTL_01_LCOND_CC_TRIG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< CCP edges have no effect */
#define GPTIMER_CCCTL_01_LCOND_CC_TRIG_RISE      ((uint32_t)0x00000100U)         /* !< Rising edge of CCP or trigger
                                                                                    assertion edge */
#define GPTIMER_CCCTL_01_LCOND_CC_TRIG_FALL      ((uint32_t)0x00000200U)         /* !< Falling edge of CCP or trigger
                                                                                    de-assertion edge */
#define GPTIMER_CCCTL_01_LCOND_CC_TRIG_EDGE      ((uint32_t)0x00000300U)         /* !< Either edge of CCP or trigger
                                                                                    change (assertion/de-assertion edge) */
/* GPTIMER_CCCTL_01[ZCOND] Bits */
#define GPTIMER_CCCTL_01_ZCOND_OFS               (12)                            /* !< ZCOND Offset */
#define GPTIMER_CCCTL_01_ZCOND_MASK              ((uint32_t)0x00007000U)         /* !< Zero Condition. #br# This field
                                                                                    specifies the condition that
                                                                                    generates a zero pulse. */
#define GPTIMER_CCCTL_01_ZCOND_CC_TRIG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< CCP edges have no effect */
#define GPTIMER_CCCTL_01_ZCOND_CC_TRIG_RISE      ((uint32_t)0x00001000U)         /* !< Rising edge of CCP or trigger
                                                                                    assertion edge */
#define GPTIMER_CCCTL_01_ZCOND_CC_TRIG_FALL      ((uint32_t)0x00002000U)         /* !< Falling edge of CCP or trigger
                                                                                    de-assertion edge */
#define GPTIMER_CCCTL_01_ZCOND_CC_TRIG_EDGE      ((uint32_t)0x00003000U)         /* !< Either edge of CCP or trigger
                                                                                    change (assertion/de-assertion edge) */
/* GPTIMER_CCCTL_01[COC] Bits */
#define GPTIMER_CCCTL_01_COC_OFS                 (17)                            /* !< COC Offset */
#define GPTIMER_CCCTL_01_COC_MASK                ((uint32_t)0x00020000U)         /* !< Capture or Compare. #br# Specifies
                                                                                    whether the corresponding CC register
                                                                                    is used as a capture register or a
                                                                                    compare register (never both). */
#define GPTIMER_CCCTL_01_COC_COMPARE             ((uint32_t)0x00000000U)         /* !< Compare */
#define GPTIMER_CCCTL_01_COC_CAPTURE             ((uint32_t)0x00020000U)         /* !< Capture */
/* GPTIMER_CCCTL_01[SCERCNEZ] Bits */
#define GPTIMER_CCCTL_01_SCERCNEZ_OFS            (25)                            /* !< SCERCNEZ Offset */
#define GPTIMER_CCCTL_01_SCERCNEZ_MASK           ((uint32_t)0x02000000U)         /* !< Suppress Compare Event if Repeat
                                                                                    Counter is Not Equal to Zero This bit
                                                                                    suppresses the generation of the
                                                                                    compare (CCD, CCU and RC) events from
                                                                                    the counter when the repeat counter
                                                                                    (RC) value is not 0. */
#define GPTIMER_CCCTL_01_SCERCNEZ_DISABLED       ((uint32_t)0x00000000U)         /* !< CCD, CCU  and RC events are always
                                                                                    generated from the counter when their
                                                                                    conditions are generated. */
#define GPTIMER_CCCTL_01_SCERCNEZ_ENABLED        ((uint32_t)0x02000000U)         /* !< CCD, CCU and RC events are
                                                                                    generated from the counter when their
                                                                                    conditions are generated and the RC
                                                                                    register value is 0. */
/* GPTIMER_CCCTL_01[CCUPD] Bits */
#define GPTIMER_CCCTL_01_CCUPD_OFS               (18)                            /* !< CCUPD Offset */
#define GPTIMER_CCCTL_01_CCUPD_MASK              ((uint32_t)0x001C0000U)         /* !< Capture and Compare Update Method
                                                                                    This field controls how updates to
                                                                                    the shadow capture and compare
                                                                                    register are performed (when
                                                                                    operating in compare mode, COC=0). */
#define GPTIMER_CCCTL_01_CCUPD_IMMEDIATELY       ((uint32_t)0x00000000U)         /* !< Writes to the CCx_y register is
                                                                                    written to the register directly and
                                                                                    has immediate effect. */
#define GPTIMER_CCCTL_01_CCUPD_ZERO_EVT          ((uint32_t)0x00040000U)         /* !< Following a zero event (CTR=0)
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals 0. */
#define GPTIMER_CCCTL_01_CCUPD_COMPARE_DOWN_EVT  ((uint32_t)0x00080000U)         /* !< Following a CCD event (CTR=CC_xy)
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals the CCx_y
                                                                                    register value. */
#define GPTIMER_CCCTL_01_CCUPD_COMPARE_UP_EVT    ((uint32_t)0x000C0000U)         /* !< Following a CCU event (CTR=CC_xy)
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals the CCx_y
                                                                                    register value. */
#define GPTIMER_CCCTL_01_CCUPD_ZERO_LOAD_EVT     ((uint32_t)0x00100000U)         /* !< Following a zero event(CTR=0) or
                                                                                    load event (CTR=LOAD) Writes to the
                                                                                    CCx_y register are stored in shadow
                                                                                    register and transferred to ECCx_y in
                                                                                    the TIMCLK cycle following CTR equals
                                                                                    0 or CTR. Equals LD.  Note this
                                                                                    update mechanism is defined for use
                                                                                    only in configurations using up/down
                                                                                    counting. This mode is not intended
                                                                                    for use in down count configurations. */
#define GPTIMER_CCCTL_01_CCUPD_ZERO_RC_ZERO_EVT  ((uint32_t)0x00140000U)         /* !< Following a zero event (CTR=0) with
                                                                                    repeat count also zero (RC=0).
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals 0 and if
                                                                                    RC equal 0. */
#define GPTIMER_CCCTL_01_CCUPD_TRIG              ((uint32_t)0x00180000U)         /* !< Following a TRIG pulse.  Writes to
                                                                                    the CCx_y register are stored in
                                                                                    shadow register and transferred to
                                                                                    CCx_y */
/* GPTIMER_CCCTL_01[CCACTUPD] Bits */
#define GPTIMER_CCCTL_01_CCACTUPD_OFS            (26)                            /* !< CCACTUPD Offset */
#define GPTIMER_CCCTL_01_CCACTUPD_MASK           ((uint32_t)0x1C000000U)         /* !< CCACT shadow register Update Method
                                                                                    This field controls how updates to
                                                                                    the CCACT shadow register are
                                                                                    performed */
#define GPTIMER_CCCTL_01_CCACTUPD_IMMEDIATELY    ((uint32_t)0x00000000U)         /* !< Value written to the CCACT register
                                                                                    has immediate effect. */
#define GPTIMER_CCCTL_01_CCACTUPD_ZERO_EVT       ((uint32_t)0x04000000U)         /* !< Following a zero event (CTR=0)
                                                                                    Writes to the CCACTx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCACTx_y in the TIMCLK
                                                                                    cycle following CTR equals 0. */
#define GPTIMER_CCCTL_01_CCACTUPD_COMPARE_DOWN_EVT ((uint32_t)0x08000000U)         /* !< Following a CCD event (CTR=CC_xy)
                                                                                    Writes to the CCACTx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCACTx_y in the TIMCLK
                                                                                    cycle following CTR equals the CCx_y
                                                                                    register value. */
#define GPTIMER_CCCTL_01_CCACTUPD_COMPARE_UP_EVT ((uint32_t)0x0C000000U)         /* !< Following a CCU event (CTR=CC_xy)
                                                                                    Writes to the CCACTx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCACTx_y in the TIMCLK
                                                                                    cycle following CTR equals the CCx_y
                                                                                    register value. */
#define GPTIMER_CCCTL_01_CCACTUPD_ZERO_LOAD_EVT  ((uint32_t)0x10000000U)         /* !< Following a zero event (CTR=0) or
                                                                                    load event (CTR = LOAD) Writes to the
                                                                                    CCACTx_y register are stored in
                                                                                    shadow register and transferred to
                                                                                    CCACTx_y in the TIMCLK cycle
                                                                                    following CTR equals 0 or CTR. Equals
                                                                                    LDn.  Note this update mechanism is
                                                                                    defined for use only in
                                                                                    configurations using up/down
                                                                                    counting. This mode is not intended
                                                                                    for use in down count configurations. */
#define GPTIMER_CCCTL_01_CCACTUPD_ZERO_RC_ZERO_EVT ((uint32_t)0x14000000U)         /* !< Following a zero event (CTR=0) with
                                                                                    repeat count also zero (RC=0).
                                                                                    Writes to the CCACTx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCACTx_y in the TIMCLK
                                                                                    cycle following CTR equals 0 and if
                                                                                    RC equal 0. */
#define GPTIMER_CCCTL_01_CCACTUPD_TRIG           ((uint32_t)0x18000000U)         /* !< On a TRIG pulse, the value stored
                                                                                    in CCACT_xy shadow register is loaded
                                                                                    into CCACT_xy register. */
/* GPTIMER_CCCTL_01[CC2SELU] Bits */
#define GPTIMER_CCCTL_01_CC2SELU_OFS             (22)                            /* !< CC2SELU Offset */
#define GPTIMER_CCCTL_01_CC2SELU_MASK            ((uint32_t)0x01C00000U)         /* !< Selects the source second CCU
                                                                                    event. */
#define GPTIMER_CCCTL_01_CC2SELU_SEL_CCU0        ((uint32_t)0x00000000U)         /* !< Selects CCU from CC0. */
#define GPTIMER_CCCTL_01_CC2SELU_SEL_CCU1        ((uint32_t)0x00400000U)         /* !< Selects CCU from CC1. */
#define GPTIMER_CCCTL_01_CC2SELU_SEL_CCU2        ((uint32_t)0x00800000U)         /* !< Selects CCU from CC2. */
#define GPTIMER_CCCTL_01_CC2SELU_SEL_CCU3        ((uint32_t)0x00C00000U)         /* !< Selects CCU from CC3. */
#define GPTIMER_CCCTL_01_CC2SELU_SEL_CCU4        ((uint32_t)0x01000000U)         /* !< Selects CCU from CC4. */
#define GPTIMER_CCCTL_01_CC2SELU_SEL_CCU5        ((uint32_t)0x01400000U)         /* !< Selects CCU from CC5. */
/* GPTIMER_CCCTL_01[CC2SELD] Bits */
#define GPTIMER_CCCTL_01_CC2SELD_OFS             (29)                            /* !< CC2SELD Offset */
#define GPTIMER_CCCTL_01_CC2SELD_MASK            ((uint32_t)0xE0000000U)         /* !< Selects the source second CCD
                                                                                    event. */
#define GPTIMER_CCCTL_01_CC2SELD_SEL_CCD0        ((uint32_t)0x00000000U)         /* !< Selects CCD from CC0. */
#define GPTIMER_CCCTL_01_CC2SELD_SEL_CCD1        ((uint32_t)0x20000000U)         /* !< Selects CCD from CC1. */
#define GPTIMER_CCCTL_01_CC2SELD_SEL_CCD2        ((uint32_t)0x40000000U)         /* !< Selects CCD from CC2. */
#define GPTIMER_CCCTL_01_CC2SELD_SEL_CCD3        ((uint32_t)0x60000000U)         /* !< Selects CCD from CC3. */
#define GPTIMER_CCCTL_01_CC2SELD_SEL_CCD4        ((uint32_t)0x80000000U)         /* !< Selects CCD from CC4. */
#define GPTIMER_CCCTL_01_CC2SELD_SEL_CCD5        ((uint32_t)0xA0000000U)         /* !< Selects CCD from CC5. */

/* GPTIMER_CCCTL_23 Bits */
/* GPTIMER_CCCTL_23[CCOND] Bits */
#define GPTIMER_CCCTL_23_CCOND_OFS               (0)                             /* !< CCOND Offset */
#define GPTIMER_CCCTL_23_CCOND_MASK              ((uint32_t)0x00000007U)         /* !< Capture Condition. #br# Specifies
                                                                                    the condition that generates a
                                                                                    capture pulse. 4h-Fh = Reserved */
#define GPTIMER_CCCTL_23_CCOND_NOCAPTURE         ((uint32_t)0x00000000U)         /* !< None (never captures) */
#define GPTIMER_CCCTL_23_CCOND_CC_TRIG_RISE      ((uint32_t)0x00000001U)         /* !< Rising edge of CCP or trigger
                                                                                    assertion edge */
#define GPTIMER_CCCTL_23_CCOND_CC_TRIG_FALL      ((uint32_t)0x00000002U)         /* !< Falling edge of CCP or trigger
                                                                                    de-assertion edge */
#define GPTIMER_CCCTL_23_CCOND_CC_TRIG_EDGE      ((uint32_t)0x00000003U)         /* !< Either edge of CCP or trigger
                                                                                    change (assertion/de-assertion edge) */
/* GPTIMER_CCCTL_23[ACOND] Bits */
#define GPTIMER_CCCTL_23_ACOND_OFS               (4)                             /* !< ACOND Offset */
#define GPTIMER_CCCTL_23_ACOND_MASK              ((uint32_t)0x00000070U)         /* !< Advance Condition. #br# Specifies
                                                                                    the condition that generates an
                                                                                    advance pulse. 6h-Fh = Reserved */
#define GPTIMER_CCCTL_23_ACOND_TIMCLK            ((uint32_t)0x00000000U)         /* !< Each TIMCLK */
#define GPTIMER_CCCTL_23_ACOND_CC_TRIG_RISE      ((uint32_t)0x00000010U)         /* !< Rising edge of CCP or trigger
                                                                                    assertion edge */
#define GPTIMER_CCCTL_23_ACOND_CC_TRIG_FALL      ((uint32_t)0x00000020U)         /* !< Falling edge of CCP or trigger
                                                                                    de-assertion edge */
#define GPTIMER_CCCTL_23_ACOND_CC_TRIG_EDGE      ((uint32_t)0x00000030U)         /* !< Either edge of CCP or trigger
                                                                                    change (assertion/de-assertion edge) */
#define GPTIMER_CCCTL_23_ACOND_CC_TRIG_HIGH      ((uint32_t)0x00000050U)         /* !< CCP High or Trigger assertion
                                                                                    (level) */
/* GPTIMER_CCCTL_23[LCOND] Bits */
#define GPTIMER_CCCTL_23_LCOND_OFS               (8)                             /* !< LCOND Offset */
#define GPTIMER_CCCTL_23_LCOND_MASK              ((uint32_t)0x00000700U)         /* !< Load Condition. #br# Specifies the
                                                                                    condition that generates a load
                                                                                    pulse.  4h-Fh = Reserved */
#define GPTIMER_CCCTL_23_LCOND_CC_TRIG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< CCP edges have no effect */
#define GPTIMER_CCCTL_23_LCOND_CC_TRIG_RISE      ((uint32_t)0x00000100U)         /* !< Rising edge of CCP or trigger
                                                                                    assertion edge */
#define GPTIMER_CCCTL_23_LCOND_CC_TRIG_FALL      ((uint32_t)0x00000200U)         /* !< Falling edge of CCP or trigger
                                                                                    de-assertion edge */
#define GPTIMER_CCCTL_23_LCOND_CC_TRIG_EDGE      ((uint32_t)0x00000300U)         /* !< Either edge of CCP or trigger
                                                                                    change (assertion/de-assertion edge) */
/* GPTIMER_CCCTL_23[ZCOND] Bits */
#define GPTIMER_CCCTL_23_ZCOND_OFS               (12)                            /* !< ZCOND Offset */
#define GPTIMER_CCCTL_23_ZCOND_MASK              ((uint32_t)0x00007000U)         /* !< Zero Condition. #br# This field
                                                                                    specifies the condition that
                                                                                    generates a zero pulse. 4h-Fh =
                                                                                    Reserved */
#define GPTIMER_CCCTL_23_ZCOND_CC_TRIG_NO_EFFECT ((uint32_t)0x00000000U)         /* !< CCP edges have no effect */
#define GPTIMER_CCCTL_23_ZCOND_CC_TRIG_RISE      ((uint32_t)0x00001000U)         /* !< Rising edge of CCP or trigger
                                                                                    assertion edge */
#define GPTIMER_CCCTL_23_ZCOND_CC_TRIG_FALL      ((uint32_t)0x00002000U)         /* !< Falling edge of CCP or trigger
                                                                                    de-assertion edge */
#define GPTIMER_CCCTL_23_ZCOND_CC_TRIG_EDGE      ((uint32_t)0x00003000U)         /* !< Either edge of CCP or trigger
                                                                                    change (assertion/de-assertion edge) */
/* GPTIMER_CCCTL_23[COC] Bits */
#define GPTIMER_CCCTL_23_COC_OFS                 (17)                            /* !< COC Offset */
#define GPTIMER_CCCTL_23_COC_MASK                ((uint32_t)0x00020000U)         /* !< Capture or Compare. #br# Specifies
                                                                                    whether the corresponding CC register
                                                                                    is used as a capture register or a
                                                                                    compare register (never both). */
#define GPTIMER_CCCTL_23_COC_COMPARE             ((uint32_t)0x00000000U)         /* !< Compare */
#define GPTIMER_CCCTL_23_COC_CAPTURE             ((uint32_t)0x00020000U)         /* !< Capture */
/* GPTIMER_CCCTL_23[SCERCNEZ] Bits */
#define GPTIMER_CCCTL_23_SCERCNEZ_OFS            (25)                            /* !< SCERCNEZ Offset */
#define GPTIMER_CCCTL_23_SCERCNEZ_MASK           ((uint32_t)0x02000000U)         /* !< Suppress Compare Event if Repeat
                                                                                    Counter is Not Equal to Zero This bit
                                                                                    suppresses the generation of the
                                                                                    compare (CCD, CCU and RC) events from
                                                                                    the counter when the repeat counter
                                                                                    (RCn) value is not 0. */
#define GPTIMER_CCCTL_23_SCERCNEZ_DISABLED       ((uint32_t)0x00000000U)         /* !< CCD, CCU and RC events are always
                                                                                    generated from the counter when their
                                                                                    conditions are generated. */
#define GPTIMER_CCCTL_23_SCERCNEZ_ENABLED        ((uint32_t)0x02000000U)         /* !< CCD, CCU and RC events are
                                                                                    generated from the counter when their
                                                                                    conditions are generated and the RC
                                                                                    register value is 0. */
/* GPTIMER_CCCTL_23[CCUPD] Bits */
#define GPTIMER_CCCTL_23_CCUPD_OFS               (18)                            /* !< CCUPD Offset */
#define GPTIMER_CCCTL_23_CCUPD_MASK              ((uint32_t)0x001C0000U)         /* !< Capture and Compare Update Method
                                                                                    This field controls how updates to
                                                                                    the shadow capture and compare
                                                                                    register are performed (when
                                                                                    operating in compare mode, COC=0). */
#define GPTIMER_CCCTL_23_CCUPD_IMMEDIATELY       ((uint32_t)0x00000000U)         /* !< Writes to the CCx_y register is
                                                                                    written to the register directly and
                                                                                    has immediate effect. */
#define GPTIMER_CCCTL_23_CCUPD_ZERO_EVT          ((uint32_t)0x00040000U)         /* !< Following a zero event (CTR=0)
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals 0. */
#define GPTIMER_CCCTL_23_CCUPD_COMPARE_DOWN_EVT  ((uint32_t)0x00080000U)         /* !< Following a CCD event (CTR=CC_xy)
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals the CCx_y
                                                                                    register value. */
#define GPTIMER_CCCTL_23_CCUPD_COMPARE_UP_EVT    ((uint32_t)0x000C0000U)         /* !< Following a CCU event (CTR=CC_xy)
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals the CCx_y
                                                                                    register value. */
#define GPTIMER_CCCTL_23_CCUPD_ZERO_LOAD_EVT     ((uint32_t)0x00100000U)         /* !< Following a zero or load event
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals 0 or CTR.
                                                                                    Equals LDn.  Note this update
                                                                                    mechanism is defined for use only in
                                                                                    configurations using up/down
                                                                                    counting. This mode is not intended
                                                                                    for use in down count configurations. */
#define GPTIMER_CCCTL_23_CCUPD_ZERO_RC_ZERO_EVT  ((uint32_t)0x00140000U)         /* !< Following a zero event (CTR=0) with
                                                                                    repeat count also zero (RC=0).
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals 0 and if
                                                                                    RC equal 0. */
#define GPTIMER_CCCTL_23_CCUPD_TRIG              ((uint32_t)0x00180000U)         /* !< Following a TRIG pulse.  Writes to
                                                                                    the CCx_y register are stored in
                                                                                    shadow register and transferred to
                                                                                    CCx_y #xD; 0. */
/* GPTIMER_CCCTL_23[CCACTUPD] Bits */
#define GPTIMER_CCCTL_23_CCACTUPD_OFS            (26)                            /* !< CCACTUPD Offset */
#define GPTIMER_CCCTL_23_CCACTUPD_MASK           ((uint32_t)0x1C000000U)         /* !< CCACT shadow register Update Method
                                                                                    This field controls how updates to
                                                                                    the CCCACT shadow register are
                                                                                    performed */
#define GPTIMER_CCCTL_23_CCACTUPD_IMMEDIATELY    ((uint32_t)0x00000000U)         /* !< Value written to the CCACTx_y
                                                                                    register has immediate effect. */
#define GPTIMER_CCCTL_23_CCACTUPD_ZERO_EVT       ((uint32_t)0x04000000U)         /* !< Following a zero event (CTR=0)
                                                                                    Writes to the CCACTx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCACTx_y in the TIMCLK
                                                                                    cycle following CTR equals 0. */
#define GPTIMER_CCCTL_23_CCACTUPD_COMPARE_DOWN_EVT ((uint32_t)0x08000000U)         /* !< Following a CCD event (CTR=CC_xy)
                                                                                    Writes to the CCACTx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCACTx_y in the TIMCLK
                                                                                    cycle following CTR equals the CCx_y
                                                                                    register value. */
#define GPTIMER_CCCTL_23_CCACTUPD_COMPARE_UP_EVT ((uint32_t)0x0C000000U)         /* !< Following a CCU event (CTR=cc_xy)
                                                                                    Writes to the CCACTx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCACTx_y in the TIMCLK
                                                                                    cycle following CTR equals the CCx_y
                                                                                    register value. */
#define GPTIMER_CCCTL_23_CCACTUPD_ZERO_LOAD_EVT  ((uint32_t)0x10000000U)         /* !< Following a zero event (CTR=0) or
                                                                                    load event (CTR=LOAD) Writes to the
                                                                                    CCACTx_y register are stored in
                                                                                    shadow register and transferred to
                                                                                    CCACTx_y in the TIMCLK cycle
                                                                                    following CTR equals 0 or CTR. Equals
                                                                                    LDn.  Note this update mechanism is
                                                                                    defined for use only in
                                                                                    configurations using up/down
                                                                                    counting. This mode is not intended
                                                                                    for use in down count configurations. */
#define GPTIMER_CCCTL_23_CCACTUPD_ZERO_RC_ZERO_EVT ((uint32_t)0x14000000U)         /* !< Following a zero event (CTR=0) with
                                                                                    repeat count also zero (RC=0).
                                                                                    Writes to the CCACTx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCACTx_y in the TIMCLK
                                                                                    cycle following CTR equals 0 and if
                                                                                    RC equal 0. */
#define GPTIMER_CCCTL_23_CCACTUPD_TRIG           ((uint32_t)0x18000000U)         /* !< On a TRIG pulse, the value stored
                                                                                    in CCACTx_y shadow register is loaded
                                                                                    into CCACTx_y active register. */
/* GPTIMER_CCCTL_23[CC2SELU] Bits */
#define GPTIMER_CCCTL_23_CC2SELU_OFS             (22)                            /* !< CC2SELU Offset */
#define GPTIMER_CCCTL_23_CC2SELU_MASK            ((uint32_t)0x01C00000U)         /* !< Selects the source second CCU
                                                                                    event. */
#define GPTIMER_CCCTL_23_CC2SELU_SEL_CCU0        ((uint32_t)0x00000000U)         /* !< Selects CCU from CC0. */
#define GPTIMER_CCCTL_23_CC2SELU_SEL_CCU1        ((uint32_t)0x00400000U)         /* !< Selects CCU from CC1. */
#define GPTIMER_CCCTL_23_CC2SELU_SEL_CCU2        ((uint32_t)0x00800000U)         /* !< Selects CCU from CC2. */
#define GPTIMER_CCCTL_23_CC2SELU_SEL_CCU3        ((uint32_t)0x00C00000U)         /* !< Selects CCU from CC3. */
#define GPTIMER_CCCTL_23_CC2SELU_SEL_CCU4        ((uint32_t)0x01000000U)         /* !< Selects CCU from CC4. */
#define GPTIMER_CCCTL_23_CC2SELU_SEL_CCU5        ((uint32_t)0x01400000U)         /* !< Selects CCU from CC5. */
/* GPTIMER_CCCTL_23[CC2SELD] Bits */
#define GPTIMER_CCCTL_23_CC2SELD_OFS             (29)                            /* !< CC2SELD Offset */
#define GPTIMER_CCCTL_23_CC2SELD_MASK            ((uint32_t)0xE0000000U)         /* !< Selects the source second CCD
                                                                                    event. */
#define GPTIMER_CCCTL_23_CC2SELD_SEL_CCD0        ((uint32_t)0x00000000U)         /* !< Selects CCD from CC0. */
#define GPTIMER_CCCTL_23_CC2SELD_SEL_CCD1        ((uint32_t)0x20000000U)         /* !< Selects CCD from CC1. */
#define GPTIMER_CCCTL_23_CC2SELD_SEL_CCD2        ((uint32_t)0x40000000U)         /* !< Selects CCD from CC2. */
#define GPTIMER_CCCTL_23_CC2SELD_SEL_CCD3        ((uint32_t)0x60000000U)         /* !< Selects CCD from CC3. */
#define GPTIMER_CCCTL_23_CC2SELD_SEL_CCD4        ((uint32_t)0x80000000U)         /* !< Selects CCD from CC4. */
#define GPTIMER_CCCTL_23_CC2SELD_SEL_CCD5        ((uint32_t)0xA0000000U)         /* !< Selects CCD from CC5. */

/* GPTIMER_CCCTL_45 Bits */
/* GPTIMER_CCCTL_45[SCERCNEZ] Bits */
#define GPTIMER_CCCTL_45_SCERCNEZ_OFS            (25)                            /* !< SCERCNEZ Offset */
#define GPTIMER_CCCTL_45_SCERCNEZ_MASK           ((uint32_t)0x02000000U)         /* !< Suppress Compare Event if Repeat
                                                                                    Counter is Not Equal to Zero This bit
                                                                                    suppresses the generation of the
                                                                                    compare (CCD, CCU and RC) events from
                                                                                    the counter when the repeat counter
                                                                                    (RC) value is not 0. */
#define GPTIMER_CCCTL_45_SCERCNEZ_DISABLED       ((uint32_t)0x00000000U)         /* !< CCD, CCU and RC events are always
                                                                                    generated from the counter when their
                                                                                    conditions are generated. */
#define GPTIMER_CCCTL_45_SCERCNEZ_ENABLED        ((uint32_t)0x02000000U)         /* !< CCD, CCU and RC events are
                                                                                    generated from the counter when their
                                                                                    conditions are generated and the RC
                                                                                    register value is 0. */
/* GPTIMER_CCCTL_45[CCUPD] Bits */
#define GPTIMER_CCCTL_45_CCUPD_OFS               (18)                            /* !< CCUPD Offset */
#define GPTIMER_CCCTL_45_CCUPD_MASK              ((uint32_t)0x001C0000U)         /* !< Capture and Compare Update Method
                                                                                    This field controls how updates to
                                                                                    the shadow capture and compare
                                                                                    register are performed (when
                                                                                    operating in compare mode, COC=0). */
#define GPTIMER_CCCTL_45_CCUPD_IMMEDIATELY       ((uint32_t)0x00000000U)         /* !< Writes to the CCx_y register is
                                                                                    written to the register directly and
                                                                                    has immediate effect. */
#define GPTIMER_CCCTL_45_CCUPD_ZERO_EVT          ((uint32_t)0x00040000U)         /* !< Following a zero event (CTR=0)
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to ECCx_y in the TIMCLK
                                                                                    cycle following CTR equals 0. */
#define GPTIMER_CCCTL_45_CCUPD_COMPARE_DOWN_EVT  ((uint32_t)0x00080000U)         /* !< Following a CCD event (CTR=CC_xy)
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals the CCx_y
                                                                                    register value. */
#define GPTIMER_CCCTL_45_CCUPD_COMPARE_UP_EVT    ((uint32_t)0x000C0000U)         /* !< Following a CCU event (CTR=CC_xy)
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals the CCx_y
                                                                                    register value. */
#define GPTIMER_CCCTL_45_CCUPD_ZERO_LOAD_EVT     ((uint32_t)0x00100000U)         /* !< Following a zero event (CTR=0) or
                                                                                    load event (CTR=LOAD) Writes to the
                                                                                    CCx_y register are stored in shadow
                                                                                    register and transferred to CCx_y in
                                                                                    the TIMCLK cycle following CTR equals
                                                                                    0 or CTR. Equals LD.  Note this
                                                                                    update mechanism is defined for use
                                                                                    only in configurations using up/down
                                                                                    counting. This mode is not intended
                                                                                    for use in down count configurations. */
#define GPTIMER_CCCTL_45_CCUPD_ZERO_RC_ZERO_EVT  ((uint32_t)0x00140000U)         /* !< Following a zero event (CTR=0) with
                                                                                    repeat count also zero (RC=0).
                                                                                    Writes to the CCx_y register are
                                                                                    stored in shadow register and
                                                                                    transferred to CCx_y in the TIMCLK
                                                                                    cycle following CTR equals 0 and if
                                                                                    RC equal 0. */
#define GPTIMER_CCCTL_45_CCUPD_TRIG              ((uint32_t)0x00180000U)         /* !< Following a TRIG pulse.  Writes to
                                                                                    the CCx_y register are stored in
                                                                                    shadow register and transferred to
                                                                                    CCx_y #xD; 0. */

/* GPTIMER_OCTL_01 Bits */
/* GPTIMER_OCTL_01[CCPOINV] Bits */
#define GPTIMER_OCTL_01_CCPOINV_OFS              (4)                             /* !< CCPOINV Offset */
#define GPTIMER_OCTL_01_CCPOINV_MASK             ((uint32_t)0x00000010U)         /* !< CCP Output Invert The output as
                                                                                    selected by CCPO is conditionally
                                                                                    inverted. */
#define GPTIMER_OCTL_01_CCPOINV_NOINV            ((uint32_t)0x00000000U)         /* !< No inversion */
#define GPTIMER_OCTL_01_CCPOINV_INV              ((uint32_t)0x00000010U)         /* !< Invert */
/* GPTIMER_OCTL_01[CCPIV] Bits */
#define GPTIMER_OCTL_01_CCPIV_OFS                (5)                             /* !< CCPIV Offset */
#define GPTIMER_OCTL_01_CCPIV_MASK               ((uint32_t)0x00000020U)         /* !< CCP Initial Value This bit
                                                                                    specifies the logical value put on
                                                                                    the signal generator state while the
                                                                                    counter is disabled (CTRCTL.EN == 0). */
#define GPTIMER_OCTL_01_CCPIV_LOW                ((uint32_t)0x00000000U)         /* !< Low */
#define GPTIMER_OCTL_01_CCPIV_HIGH               ((uint32_t)0x00000020U)         /* !< High */
/* GPTIMER_OCTL_01[CCPO] Bits */
#define GPTIMER_OCTL_01_CCPO_OFS                 (0)                             /* !< CCPO Offset */
#define GPTIMER_OCTL_01_CCPO_MASK                ((uint32_t)0x0000000FU)         /* !< CCP Output Source */
#define GPTIMER_OCTL_01_CCPO_FUNCVAL             ((uint32_t)0x00000000U)         /* !< Signal generator value (for
                                                                                    example, PWM, triggered PWM) */
#define GPTIMER_OCTL_01_CCPO_LOAD                ((uint32_t)0x00000001U)         /* !< Load event */
#define GPTIMER_OCTL_01_CCPO_CMPVAL              ((uint32_t)0x00000002U)         /* !< CCU event or CCD event */
#define GPTIMER_OCTL_01_CCPO_ZERO                ((uint32_t)0x00000004U)         /* !< Zero event */
#define GPTIMER_OCTL_01_CCPO_CAPCOND             ((uint32_t)0x00000005U)         /* !< Capture event */
#define GPTIMER_OCTL_01_CCPO_FAULTCOND           ((uint32_t)0x00000006U)         /* !< Fault condition */
#define GPTIMER_OCTL_01_CCPO_CC0_MIRROR_ALL      ((uint32_t)0x00000008U)         /* !< Mirror CCP of first capture and
                                                                                    compare register to other capture
                                                                                    compare blocks */
#define GPTIMER_OCTL_01_CCPO_CC1_MIRROR_ALL      ((uint32_t)0x00000009U)         /* !< Mirror CCP of second capture and
                                                                                    compare register in other capture
                                                                                    compare blocks */
#define GPTIMER_OCTL_01_CCPO_DEADBAND            ((uint32_t)0x0000000CU)         /* !< Signal generator output after
                                                                                    deadband insertion */
#define GPTIMER_OCTL_01_CCPO_CNTDIR              ((uint32_t)0x0000000DU)         /* !< Counter direction */

/* GPTIMER_OCTL_23 Bits */
/* GPTIMER_OCTL_23[CCPOINV] Bits */
#define GPTIMER_OCTL_23_CCPOINV_OFS              (4)                             /* !< CCPOINV Offset */
#define GPTIMER_OCTL_23_CCPOINV_MASK             ((uint32_t)0x00000010U)         /* !< CCP Output Invert The output as
                                                                                    selected by CCPO is conditionally
                                                                                    inverted. */
#define GPTIMER_OCTL_23_CCPOINV_NOINV            ((uint32_t)0x00000000U)         /* !< No inversion */
#define GPTIMER_OCTL_23_CCPOINV_INV              ((uint32_t)0x00000010U)         /* !< Invert */
/* GPTIMER_OCTL_23[CCPIV] Bits */
#define GPTIMER_OCTL_23_CCPIV_OFS                (5)                             /* !< CCPIV Offset */
#define GPTIMER_OCTL_23_CCPIV_MASK               ((uint32_t)0x00000020U)         /* !< CCP Initial Value This bit
                                                                                    specifies the logical value put on
                                                                                    the signal generator state while the
                                                                                    counter is disabled (CTRCTL.EN == 0). */
#define GPTIMER_OCTL_23_CCPIV_LOW                ((uint32_t)0x00000000U)         /* !< Low */
#define GPTIMER_OCTL_23_CCPIV_HIGH               ((uint32_t)0x00000020U)         /* !< High */
/* GPTIMER_OCTL_23[CCPO] Bits */
#define GPTIMER_OCTL_23_CCPO_OFS                 (0)                             /* !< CCPO Offset */
#define GPTIMER_OCTL_23_CCPO_MASK                ((uint32_t)0x0000000FU)         /* !< CCP Output Source */
#define GPTIMER_OCTL_23_CCPO_FUNCVAL             ((uint32_t)0x00000000U)         /* !< Signal generator value (for
                                                                                    example, PWM, triggered PWM) */
#define GPTIMER_OCTL_23_CCPO_LOAD                ((uint32_t)0x00000001U)         /* !< Load condition */
#define GPTIMER_OCTL_23_CCPO_CMPVAL              ((uint32_t)0x00000002U)         /* !< CCU event or CCD event */
#define GPTIMER_OCTL_23_CCPO_ZERO                ((uint32_t)0x00000004U)         /* !< Zero event */
#define GPTIMER_OCTL_23_CCPO_CAPCOND             ((uint32_t)0x00000005U)         /* !< Capture event */
#define GPTIMER_OCTL_23_CCPO_FAULTCOND           ((uint32_t)0x00000006U)         /* !< Fault Condition */
#define GPTIMER_OCTL_23_CCPO_CC0_MIRROR_ALL      ((uint32_t)0x00000008U)         /* !< Mirror CCP of first capture and
                                                                                    compare register in other capture
                                                                                    compare blocks */
#define GPTIMER_OCTL_23_CCPO_CC1_MIRROR_ALL      ((uint32_t)0x00000009U)         /* !< Mirror CCP of second capture and
                                                                                    compare register in other capture
                                                                                    compare blocksi /bn,. */
#define GPTIMER_OCTL_23_CCPO_DEADBAND            ((uint32_t)0x0000000CU)         /* !< Deadband Inserted Output */
#define GPTIMER_OCTL_23_CCPO_CNTDIR              ((uint32_t)0x0000000DU)         /* !< Counter direction */

/* GPTIMER_CCACT_01 Bits */
/* GPTIMER_CCACT_01[ZACT] Bits */
#define GPTIMER_CCACT_01_ZACT_OFS                (0)                             /* !< ZACT Offset */
#define GPTIMER_CCACT_01_ZACT_MASK               ((uint32_t)0x00000003U)         /* !< CCP Output Action on Zero
                                                                                    Specifies what changes occur to CCP
                                                                                    output as the result of a zero event. */
#define GPTIMER_CCACT_01_ZACT_DISABLED           ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_01_ZACT_CCP_HIGH           ((uint32_t)0x00000001U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_01_ZACT_CCP_LOW            ((uint32_t)0x00000002U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_01_ZACT_CCP_TOGGLE         ((uint32_t)0x00000003U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_01[LACT] Bits */
#define GPTIMER_CCACT_01_LACT_OFS                (3)                             /* !< LACT Offset */
#define GPTIMER_CCACT_01_LACT_MASK               ((uint32_t)0x00000018U)         /* !< CCP Output Action on Load
                                                                                    Specifies what changes occur to CCP
                                                                                    output as the result of a load event. */
#define GPTIMER_CCACT_01_LACT_DISABLED           ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_01_LACT_CCP_HIGH           ((uint32_t)0x00000008U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_01_LACT_CCP_LOW            ((uint32_t)0x00000010U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_01_LACT_CCP_TOGGLE         ((uint32_t)0x00000018U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_01[CDACT] Bits */
#define GPTIMER_CCACT_01_CDACT_OFS               (6)                             /* !< CDACT Offset */
#define GPTIMER_CCACT_01_CDACT_MASK              ((uint32_t)0x000000C0U)         /* !< CCP Output Action on Compare (Down)
                                                                                    This field describes the resulting
                                                                                    action of the signal generator upon
                                                                                    detecting a compare event while
                                                                                    counting down. */
#define GPTIMER_CCACT_01_CDACT_DISABLED          ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_01_CDACT_CCP_HIGH          ((uint32_t)0x00000040U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_01_CDACT_CCP_LOW           ((uint32_t)0x00000080U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_01_CDACT_CCP_TOGGLE        ((uint32_t)0x000000C0U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_01[CUACT] Bits */
#define GPTIMER_CCACT_01_CUACT_OFS               (9)                             /* !< CUACT Offset */
#define GPTIMER_CCACT_01_CUACT_MASK              ((uint32_t)0x00000600U)         /* !< CCP Output Action on Compare (Up)
                                                                                    This field describes the resulting
                                                                                    action of the signal generator upon
                                                                                    detecting a compare event while
                                                                                    counting up. */
#define GPTIMER_CCACT_01_CUACT_DISABLED          ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_01_CUACT_CCP_HIGH          ((uint32_t)0x00000200U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_01_CUACT_CCP_LOW           ((uint32_t)0x00000400U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_01_CUACT_CCP_TOGGLE        ((uint32_t)0x00000600U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_01[CC2DACT] Bits */
#define GPTIMER_CCACT_01_CC2DACT_OFS             (12)                            /* !< CC2DACT Offset */
#define GPTIMER_CCACT_01_CC2DACT_MASK            ((uint32_t)0x00003000U)         /* !< CCP Output Action on CC2D event. */
#define GPTIMER_CCACT_01_CC2DACT_DISABLED        ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_01_CC2DACT_CCP_HIGH        ((uint32_t)0x00001000U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_01_CC2DACT_CCP_LOW         ((uint32_t)0x00002000U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_01_CC2DACT_CCP_TOGGLE      ((uint32_t)0x00003000U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_01[CC2UACT] Bits */
#define GPTIMER_CCACT_01_CC2UACT_OFS             (15)                            /* !< CC2UACT Offset */
#define GPTIMER_CCACT_01_CC2UACT_MASK            ((uint32_t)0x00018000U)         /* !< CCP Output Action on CC2U event. */
#define GPTIMER_CCACT_01_CC2UACT_DISABLED        ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_01_CC2UACT_CCP_HIGH        ((uint32_t)0x00008000U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_01_CC2UACT_CCP_LOW         ((uint32_t)0x00010000U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_01_CC2UACT_CCP_TOGGLE      ((uint32_t)0x00018000U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_01[FENACT] Bits */
#define GPTIMER_CCACT_01_FENACT_OFS              (22)                            /* !< FENACT Offset */
#define GPTIMER_CCACT_01_FENACT_MASK             ((uint32_t)0x01C00000U)         /* !< CCP Output Action on Fault Entry
                                                                                    This field describes the resulting
                                                                                    action of the signal generator upon
                                                                                    detecting a fault. */
#define GPTIMER_CCACT_01_FENACT_DISABLED         ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_01_FENACT_CCP_HIGH         ((uint32_t)0x00400000U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_01_FENACT_CCP_LOW          ((uint32_t)0x00800000U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_01_FENACT_CCP_TOGGLE       ((uint32_t)0x00C00000U)         /* !< CCP output value is toggled */
#define GPTIMER_CCACT_01_FENACT_CCP_HIGHZ        ((uint32_t)0x01000000U)         /* !< CCP output value is tristated */
/* GPTIMER_CCACT_01[FEXACT] Bits */
#define GPTIMER_CCACT_01_FEXACT_OFS              (25)                            /* !< FEXACT Offset */
#define GPTIMER_CCACT_01_FEXACT_MASK             ((uint32_t)0x0E000000U)         /* !< CCP Output Action on Fault Exit
                                                                                    This field describes the resulting
                                                                                    action of the signal generator upon
                                                                                    exiting the fault condition. */
#define GPTIMER_CCACT_01_FEXACT_DISABLED         ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_01_FEXACT_CCP_HIGH         ((uint32_t)0x02000000U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_01_FEXACT_CCP_LOW          ((uint32_t)0x04000000U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_01_FEXACT_CCP_TOGGLE       ((uint32_t)0x06000000U)         /* !< CCP output value is toggled */
#define GPTIMER_CCACT_01_FEXACT_CCP_HIGHZ        ((uint32_t)0x08000000U)         /* !< CCP output value is tristated */
/* GPTIMER_CCACT_01[SWFRCACT] Bits */
#define GPTIMER_CCACT_01_SWFRCACT_OFS            (28)                            /* !< SWFRCACT Offset */
#define GPTIMER_CCACT_01_SWFRCACT_MASK           ((uint32_t)0x30000000U)         /* !< CCP Output Action on Software Force
                                                                                    Output  This field describes the
                                                                                    resulting action of software force.
                                                                                    This action has a shadow register,
                                                                                    which will be updated under specific
                                                                                    condition.  So that this register
                                                                                    cannot take into effect immediately. */
#define GPTIMER_CCACT_01_SWFRCACT_DISABLED       ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_01_SWFRCACT_CCP_HIGH       ((uint32_t)0x10000000U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_01_SWFRCACT_CCP_LOW        ((uint32_t)0x20000000U)         /* !< CCP output value is set low */
/* GPTIMER_CCACT_01[SWFRCACT_CMPL] Bits */
#define GPTIMER_CCACT_01_SWFRCACT_CMPL_OFS       (30)                            /* !< SWFRCACT_CMPL Offset */
#define GPTIMER_CCACT_01_SWFRCACT_CMPL_MASK      ((uint32_t)0xC0000000U)         /* !< CCP Complimentary output Action on
                                                                                    Software Force Output  This field
                                                                                    describes the resulting action of
                                                                                    software force.  This action has a
                                                                                    shadow register, which will be
                                                                                    updated under specific condition.  So
                                                                                    that this register cannot take into
                                                                                    effect immediately. */
#define GPTIMER_CCACT_01_SWFRCACT_CMPL_DISABLED  ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_01_SWFRCACT_CMPL_CCP_HIGH  ((uint32_t)0x40000000U)         /* !< CCP Complimentary output value is
                                                                                    set high */
#define GPTIMER_CCACT_01_SWFRCACT_CMPL_CCP_LOW   ((uint32_t)0x80000000U)         /* !< CCP Complimentary output value is
                                                                                    set low */

/* GPTIMER_CCACT_23 Bits */
/* GPTIMER_CCACT_23[ZACT] Bits */
#define GPTIMER_CCACT_23_ZACT_OFS                (0)                             /* !< ZACT Offset */
#define GPTIMER_CCACT_23_ZACT_MASK               ((uint32_t)0x00000003U)         /* !< CCP Output Action on Zero
                                                                                    Specifies what changes occur to CCP
                                                                                    output as the result of a zero event. */
#define GPTIMER_CCACT_23_ZACT_DISABLED           ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_23_ZACT_CCP_HIGH           ((uint32_t)0x00000001U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_23_ZACT_CCP_LOW            ((uint32_t)0x00000002U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_23_ZACT_CCP_TOGGLE         ((uint32_t)0x00000003U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_23[LACT] Bits */
#define GPTIMER_CCACT_23_LACT_OFS                (3)                             /* !< LACT Offset */
#define GPTIMER_CCACT_23_LACT_MASK               ((uint32_t)0x00000018U)         /* !< CCP Output Action on Load
                                                                                    Specifies what changes occur to CCP
                                                                                    output as the result of a load event. */
#define GPTIMER_CCACT_23_LACT_DISABLED           ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_23_LACT_CCP_HIGH           ((uint32_t)0x00000008U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_23_LACT_CCP_LOW            ((uint32_t)0x00000010U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_23_LACT_CCP_TOGGLE         ((uint32_t)0x00000018U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_23[CDACT] Bits */
#define GPTIMER_CCACT_23_CDACT_OFS               (6)                             /* !< CDACT Offset */
#define GPTIMER_CCACT_23_CDACT_MASK              ((uint32_t)0x000000C0U)         /* !< CCP Output Action on Compare (Down)
                                                                                    This field describes the resulting
                                                                                    action of the signal generator upon
                                                                                    detecting a compare event while
                                                                                    counting down. */
#define GPTIMER_CCACT_23_CDACT_DISABLED          ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_23_CDACT_CCP_HIGH          ((uint32_t)0x00000040U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_23_CDACT_CCP_LOW           ((uint32_t)0x00000080U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_23_CDACT_CCP_TOGGLE        ((uint32_t)0x000000C0U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_23[CUACT] Bits */
#define GPTIMER_CCACT_23_CUACT_OFS               (9)                             /* !< CUACT Offset */
#define GPTIMER_CCACT_23_CUACT_MASK              ((uint32_t)0x00000600U)         /* !< CCP Output Action on Compare (Up)
                                                                                    This field describes the resulting
                                                                                    action of the signal generator upon
                                                                                    detecting a compare event while
                                                                                    counting up. */
#define GPTIMER_CCACT_23_CUACT_DISABLED          ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_23_CUACT_CCP_HIGH          ((uint32_t)0x00000200U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_23_CUACT_CCP_LOW           ((uint32_t)0x00000400U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_23_CUACT_CCP_TOGGLE        ((uint32_t)0x00000600U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_23[CC2DACT] Bits */
#define GPTIMER_CCACT_23_CC2DACT_OFS             (12)                            /* !< CC2DACT Offset */
#define GPTIMER_CCACT_23_CC2DACT_MASK            ((uint32_t)0x00003000U)         /* !< CCP Output Action on CC2D event. */
#define GPTIMER_CCACT_23_CC2DACT_DISABLED        ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_23_CC2DACT_CCP_HIGH        ((uint32_t)0x00001000U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_23_CC2DACT_CCP_LOW         ((uint32_t)0x00002000U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_23_CC2DACT_CCP_TOGGLE      ((uint32_t)0x00003000U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_23[CC2UACT] Bits */
#define GPTIMER_CCACT_23_CC2UACT_OFS             (15)                            /* !< CC2UACT Offset */
#define GPTIMER_CCACT_23_CC2UACT_MASK            ((uint32_t)0x00018000U)         /* !< CCP Output Action on CC2U event. */
#define GPTIMER_CCACT_23_CC2UACT_DISABLED        ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_23_CC2UACT_CCP_HIGH        ((uint32_t)0x00008000U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_23_CC2UACT_CCP_LOW         ((uint32_t)0x00010000U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_23_CC2UACT_CCP_TOGGLE      ((uint32_t)0x00018000U)         /* !< CCP output value is toggled */
/* GPTIMER_CCACT_23[FENACT] Bits */
#define GPTIMER_CCACT_23_FENACT_OFS              (22)                            /* !< FENACT Offset */
#define GPTIMER_CCACT_23_FENACT_MASK             ((uint32_t)0x01C00000U)         /* !< CCP Output Action on Fault Entry
                                                                                    This field describes the resulting
                                                                                    action of the signal generator upon
                                                                                    detecting a fault. */
#define GPTIMER_CCACT_23_FENACT_DISABLED         ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_23_FENACT_CCP_HIGH         ((uint32_t)0x00400000U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_23_FENACT_CCP_LOW          ((uint32_t)0x00800000U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_23_FENACT_CCP_TOGGLE       ((uint32_t)0x00C00000U)         /* !< CCP output value is toggled */
#define GPTIMER_CCACT_23_FENACT_CCP_HIGHZ        ((uint32_t)0x01000000U)         /* !< CCP output value is tristated */
/* GPTIMER_CCACT_23[FEXACT] Bits */
#define GPTIMER_CCACT_23_FEXACT_OFS              (25)                            /* !< FEXACT Offset */
#define GPTIMER_CCACT_23_FEXACT_MASK             ((uint32_t)0x0E000000U)         /* !< CCP Output Action on Fault Exit
                                                                                    This field describes the resulting
                                                                                    action of the signal generator upon
                                                                                    exiting the fault condition. */
#define GPTIMER_CCACT_23_FEXACT_DISABLED         ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_23_FEXACT_CCP_HIGH         ((uint32_t)0x02000000U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_23_FEXACT_CCP_LOW          ((uint32_t)0x04000000U)         /* !< CCP output value is set low */
#define GPTIMER_CCACT_23_FEXACT_CCP_TOGGLE       ((uint32_t)0x06000000U)         /* !< CCP output value is toggled */
#define GPTIMER_CCACT_23_FEXACT_CCP_HIGHZ        ((uint32_t)0x08000000U)         /* !< CCP output value is tristated */
/* GPTIMER_CCACT_23[SWFRCACT] Bits */
#define GPTIMER_CCACT_23_SWFRCACT_OFS            (28)                            /* !< SWFRCACT Offset */
#define GPTIMER_CCACT_23_SWFRCACT_MASK           ((uint32_t)0x30000000U)         /* !< CCP Output Action on Software Force
                                                                                    Output  This field describes the
                                                                                    resulting action of software force.
                                                                                    This action has a shadow register,
                                                                                    which will be updated under specific
                                                                                    condition.  So that this register
                                                                                    cannot take into effect immediately. */
#define GPTIMER_CCACT_23_SWFRCACT_DISABLED       ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_23_SWFRCACT_CCP_HIGH       ((uint32_t)0x10000000U)         /* !< CCP output value is set high */
#define GPTIMER_CCACT_23_SWFRCACT_CCP_LOW        ((uint32_t)0x20000000U)         /* !< CCP output value is set low */
/* GPTIMER_CCACT_23[SWFRCACT_CMPL] Bits */
#define GPTIMER_CCACT_23_SWFRCACT_CMPL_OFS       (30)                            /* !< SWFRCACT_CMPL Offset */
#define GPTIMER_CCACT_23_SWFRCACT_CMPL_MASK      ((uint32_t)0xC0000000U)         /* !< CCP Complimentary Output Action on
                                                                                    Software Force Output  This field
                                                                                    describes the resulting action of
                                                                                    software force.  This action has a
                                                                                    shadow register, which will be
                                                                                    updated under specific condition.  So
                                                                                    that this register cannot take into
                                                                                    effect immediately. */
#define GPTIMER_CCACT_23_SWFRCACT_CMPL_DISABLED  ((uint32_t)0x00000000U)         /* !< This event is disabled and a lower
                                                                                    priority event is selected if
                                                                                    asserting. The CCP output value is
                                                                                    unaffected by the event. */
#define GPTIMER_CCACT_23_SWFRCACT_CMPL_CCP_HIGH  ((uint32_t)0x40000000U)         /* !< CCP Complimentary output value is
                                                                                    set high */
#define GPTIMER_CCACT_23_SWFRCACT_CMPL_CCP_LOW   ((uint32_t)0x80000000U)         /* !< CCP Complimentary output value is
                                                                                    set low */

/* GPTIMER_IFCTL_01 Bits */
/* GPTIMER_IFCTL_01[ISEL] Bits */
#define GPTIMER_IFCTL_01_ISEL_OFS                (0)                             /* !< ISEL Offset */
#define GPTIMER_IFCTL_01_ISEL_MASK               ((uint32_t)0x0000000FU)         /* !< Input Select (CCP0)  This field
                                                                                    selects the input source to the
                                                                                    filter input. 4h-7h = Reserved */
#define GPTIMER_IFCTL_01_ISEL_CCPX_INPUT         ((uint32_t)0x00000000U)         /* !< CCP of the corresponding capture
                                                                                    compare unit */
#define GPTIMER_IFCTL_01_ISEL_CCPX_INPUT_PAIR    ((uint32_t)0x00000001U)         /* !< Input pair CCPX of the capture
                                                                                    compare unit. For CCP0 input pair is
                                                                                    CCP1 and for CCP1 input pair is CCP0. */
#define GPTIMER_IFCTL_01_ISEL_CCP0_INPUT         ((uint32_t)0x00000002U)         /* !< CCP0 of the counter */
#define GPTIMER_IFCTL_01_ISEL_TRIG_INPUT         ((uint32_t)0x00000003U)         /* !< Trigger */
#define GPTIMER_IFCTL_01_ISEL_CCP_XOR            ((uint32_t)0x00000004U)         /* !< XOR of CCP inputs as input source
                                                                                    (Used in Hall input mode). */
#define GPTIMER_IFCTL_01_ISEL_FSUB0              ((uint32_t)0x00000005U)         /* !< subscriber 0 event as input source. */
#define GPTIMER_IFCTL_01_ISEL_FSUB1              ((uint32_t)0x00000006U)         /* !< subscriber 1 event as input source. */
#define GPTIMER_IFCTL_01_ISEL_COMP0              ((uint32_t)0x00000007U)         /* !< Comparator 0 output. */
#define GPTIMER_IFCTL_01_ISEL_COMP1              ((uint32_t)0x00000008U)         /* !< Comparator 1 output. */
#define GPTIMER_IFCTL_01_ISEL_COMP2              ((uint32_t)0x00000009U)         /* !< Comparator 2 output. */
/* GPTIMER_IFCTL_01[INV] Bits */
#define GPTIMER_IFCTL_01_INV_OFS                 (7)                             /* !< INV Offset */
#define GPTIMER_IFCTL_01_INV_MASK                ((uint32_t)0x00000080U)         /* !< Input Inversion This bit controls
                                                                                    whether the selected input is
                                                                                    inverted. */
#define GPTIMER_IFCTL_01_INV_NOINVERT            ((uint32_t)0x00000000U)         /* !< Noninverted */
#define GPTIMER_IFCTL_01_INV_INVERT              ((uint32_t)0x00000080U)         /* !< Inverted */
/* GPTIMER_IFCTL_01[FP] Bits */
#define GPTIMER_IFCTL_01_FP_OFS                  (8)                             /* !< FP Offset */
#define GPTIMER_IFCTL_01_FP_MASK                 ((uint32_t)0x00000300U)         /* !< Filter Period. This field specifies
                                                                                    the sample period for the input
                                                                                    filter. I.e. The input is sampled for
                                                                                    FP timer clocks during filtering. */
#define GPTIMER_IFCTL_01_FP__3                   ((uint32_t)0x00000000U)         /* !< The division factor is 3 */
#define GPTIMER_IFCTL_01_FP__5                   ((uint32_t)0x00000100U)         /* !< The division factor is 5 */
#define GPTIMER_IFCTL_01_FP__8                   ((uint32_t)0x00000200U)         /* !< The division factor is 8 */
/* GPTIMER_IFCTL_01[CPV] Bits */
#define GPTIMER_IFCTL_01_CPV_OFS                 (11)                            /* !< CPV Offset */
#define GPTIMER_IFCTL_01_CPV_MASK                ((uint32_t)0x00000800U)         /* !< Consecutive Period/Voting Select
                                                                                    This bit controls whether the input
                                                                                    filter uses a stricter consecutive
                                                                                    period count or majority voting. */
#define GPTIMER_IFCTL_01_CPV_CONSECUTIVE         ((uint32_t)0x00000000U)         /* !< Consecutive Periods The input must
                                                                                    be at a specific logic level for the
                                                                                    period defined by FP before it is
                                                                                    passed to the filter output. */
#define GPTIMER_IFCTL_01_CPV_VOTING              ((uint32_t)0x00000800U)         /* !< Voting  The filter ignores one
                                                                                    clock of opposite logic over the
                                                                                    filter period. I.e. Over FP samples
                                                                                    of the input, up to 1 sample may be
                                                                                    of an opposite logic value (glitch)
                                                                                    without affecting the output. */
/* GPTIMER_IFCTL_01[FE] Bits */
#define GPTIMER_IFCTL_01_FE_OFS                  (12)                            /* !< FE Offset */
#define GPTIMER_IFCTL_01_FE_MASK                 ((uint32_t)0x00001000U)         /* !< Filter Enable This bit controls
                                                                                    whether the input is filtered by the
                                                                                    input filter or bypasses to the edge
                                                                                    detect. */
#define GPTIMER_IFCTL_01_FE_DISABLED             ((uint32_t)0x00000000U)         /* !< Bypass. */
#define GPTIMER_IFCTL_01_FE_ENABLED              ((uint32_t)0x00001000U)         /* !< Filtered. */

/* GPTIMER_IFCTL_23 Bits */
/* GPTIMER_IFCTL_23[ISEL] Bits */
#define GPTIMER_IFCTL_23_ISEL_OFS                (0)                             /* !< ISEL Offset */
#define GPTIMER_IFCTL_23_ISEL_MASK               ((uint32_t)0x0000000FU)         /* !< Input Select (CCP0)  This field
                                                                                    selects the input source to the
                                                                                    filter input. 4h-7h = Reserved */
#define GPTIMER_IFCTL_23_ISEL_CCPX_INPUT         ((uint32_t)0x00000000U)         /* !< CCP of the corresponding capture
                                                                                    compare unit */
#define GPTIMER_IFCTL_23_ISEL_CCPX_INPUT_PAIR    ((uint32_t)0x00000001U)         /* !< Input pair CCPX of the capture
                                                                                    compare unit. For CCP0 input pair is
                                                                                    CCP1 and for CCP1 input pair is CCP0. */
#define GPTIMER_IFCTL_23_ISEL_CCP0_INPUT         ((uint32_t)0x00000002U)         /* !< CCP0 of the counter */
#define GPTIMER_IFCTL_23_ISEL_TRIG_INPUT         ((uint32_t)0x00000003U)         /* !< Trigger */
#define GPTIMER_IFCTL_23_ISEL_CCP_XOR            ((uint32_t)0x00000004U)         /* !< XOR of CCP inputs as input source
                                                                                    (Used in Hall input mode). */
#define GPTIMER_IFCTL_23_ISEL_FSUB0              ((uint32_t)0x00000005U)         /* !< subscriber 0 event as input source. */
#define GPTIMER_IFCTL_23_ISEL_FSUB1              ((uint32_t)0x00000006U)         /* !< subscriber 1 event as input source. */
#define GPTIMER_IFCTL_23_ISEL_COMP0              ((uint32_t)0x00000007U)         /* !< Comparator 0 output. */
#define GPTIMER_IFCTL_23_ISEL_COMP1              ((uint32_t)0x00000008U)         /* !< Comparator 1 output. */
#define GPTIMER_IFCTL_23_ISEL_COMP2              ((uint32_t)0x00000009U)         /* !< Comparator 2 output. */
/* GPTIMER_IFCTL_23[INV] Bits */
#define GPTIMER_IFCTL_23_INV_OFS                 (7)                             /* !< INV Offset */
#define GPTIMER_IFCTL_23_INV_MASK                ((uint32_t)0x00000080U)         /* !< Input Inversion This bit controls
                                                                                    whether the selected input is
                                                                                    inverted. */
#define GPTIMER_IFCTL_23_INV_NOINVERT            ((uint32_t)0x00000000U)         /* !< Noninverted */
#define GPTIMER_IFCTL_23_INV_INVERT              ((uint32_t)0x00000080U)         /* !< Inverted */
/* GPTIMER_IFCTL_23[FP] Bits */
#define GPTIMER_IFCTL_23_FP_OFS                  (8)                             /* !< FP Offset */
#define GPTIMER_IFCTL_23_FP_MASK                 ((uint32_t)0x00000300U)         /* !< Filter Period. This field specifies
                                                                                    the sample period for the input
                                                                                    filter. I.e. The input is sampled for
                                                                                    FP timer clocks during filtering. */
#define GPTIMER_IFCTL_23_FP__3                   ((uint32_t)0x00000000U)         /* !< The division factor is 3 */
#define GPTIMER_IFCTL_23_FP__5                   ((uint32_t)0x00000100U)         /* !< The division factor is 5 */
#define GPTIMER_IFCTL_23_FP__8                   ((uint32_t)0x00000200U)         /* !< The division factor is 8 */
/* GPTIMER_IFCTL_23[CPV] Bits */
#define GPTIMER_IFCTL_23_CPV_OFS                 (11)                            /* !< CPV Offset */
#define GPTIMER_IFCTL_23_CPV_MASK                ((uint32_t)0x00000800U)         /* !< Consecutive Period/Voting Select
                                                                                    This bit controls whether the input
                                                                                    filter uses a stricter consecutive
                                                                                    period count or majority voting. */
#define GPTIMER_IFCTL_23_CPV_CONSECUTIVE         ((uint32_t)0x00000000U)         /* !< Consecutive Periods The input must
                                                                                    be at a specific logic level for the
                                                                                    period defined by FP before it is
                                                                                    passed to the filter output. */
#define GPTIMER_IFCTL_23_CPV_VOTING              ((uint32_t)0x00000800U)         /* !< Voting  The filter ignores one
                                                                                    clock of opposite logic over the
                                                                                    filter period. I.e. Over FP samples
                                                                                    of the input, up to 1 sample may be
                                                                                    of an opposite logic value (glitch)
                                                                                    without affecting the output. */
/* GPTIMER_IFCTL_23[FE] Bits */
#define GPTIMER_IFCTL_23_FE_OFS                  (12)                            /* !< FE Offset */
#define GPTIMER_IFCTL_23_FE_MASK                 ((uint32_t)0x00001000U)         /* !< Filter Enable This bit controls
                                                                                    whether the input is filtered by the
                                                                                    input filter or bypasses to the edge
                                                                                    detect. */
#define GPTIMER_IFCTL_23_FE_DISABLED             ((uint32_t)0x00000000U)         /* !< Bypass. */
#define GPTIMER_IFCTL_23_FE_ENABLED              ((uint32_t)0x00001000U)         /* !< Filtered. */

/* GPTIMER_PL Bits */
/* GPTIMER_PL[PHASE] Bits */
#define GPTIMER_PL_PHASE_OFS                     (0)                             /* !< PHASE Offset */
#define GPTIMER_PL_PHASE_MASK                    ((uint32_t)0xFFFFFFFFU)         /* !< Phase Load value */
#define GPTIMER_PL_PHASE_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_PL_PHASE_MAXIMUM                 ((uint32_t)0xFFFFFFFFU)         /* !< Maximum Value */

/* GPTIMER_DBCTL Bits */
/* GPTIMER_DBCTL[RISEDELAY] Bits */
#define GPTIMER_DBCTL_RISEDELAY_OFS              (0)                             /* !< RISEDELAY Offset */
#define GPTIMER_DBCTL_RISEDELAY_MASK             ((uint32_t)0x00000FFFU)         /* !< Rise Delay The number of TIMCLK
                                                                                    periods inserted between the fall
                                                                                    edge of CCP signal and the rise edge
                                                                                    of CCP complimentary signal. */
#define GPTIMER_DBCTL_RISEDELAY_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_DBCTL_RISEDELAY_MAXIMUM          ((uint32_t)0x00000FFFU)         /* !< Maximum Value */
/* GPTIMER_DBCTL[FALLDELAY] Bits */
#define GPTIMER_DBCTL_FALLDELAY_OFS              (16)                            /* !< FALLDELAY Offset */
#define GPTIMER_DBCTL_FALLDELAY_MASK             ((uint32_t)0x0FFF0000U)         /* !< Fall Delay The number of TIMCLK
                                                                                    periods inserted between the fall
                                                                                    edge of CCP signal and the rise edge
                                                                                    of CCP complimentary signal. */
#define GPTIMER_DBCTL_FALLDELAY_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_DBCTL_FALLDELAY_MAXIMUM          ((uint32_t)0x0FFF0000U)         /* !< Maximum Value */
/* GPTIMER_DBCTL[M1_ENABLE] Bits */
#define GPTIMER_DBCTL_M1_ENABLE_OFS              (12)                            /* !< M1_ENABLE Offset */
#define GPTIMER_DBCTL_M1_ENABLE_MASK             ((uint32_t)0x00001000U)         /* !< Dead Band Mode 1 Enable. */
#define GPTIMER_DBCTL_M1_ENABLE_DISABLED         ((uint32_t)0x00000000U)         /* !< Disabled */
#define GPTIMER_DBCTL_M1_ENABLE_ENABLED          ((uint32_t)0x00001000U)         /* !< Enabled */

/* GPTIMER_TSEL Bits */
/* GPTIMER_TSEL[ETSEL] Bits */
#define GPTIMER_TSEL_ETSEL_OFS                   (0)                             /* !< ETSEL Offset */
#define GPTIMER_TSEL_ETSEL_MASK                  ((uint32_t)0x0000001FU)         /* !< External Trigger Select. #br# This
                                                                                    selects which System Event is used if
                                                                                    the input filter selects trigger.
                                                                                    Triggers 0-15 are used to connect
                                                                                    triggers generated by other timer
                                                                                    modules. Refer to the SoC datasheet
                                                                                    for details related to timer trigger
                                                                                    sources. Triggers 16 and  17 are
                                                                                    connected to event manager subscriber
                                                                                    ports. Event lines 18-31 are reserved
                                                                                    for future use. */
#define GPTIMER_TSEL_ETSEL_TRIG0                 ((uint32_t)0x00000000U)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG1                 ((uint32_t)0x00000001U)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG2                 ((uint32_t)0x00000002U)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG3                 ((uint32_t)0x00000003U)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG4                 ((uint32_t)0x00000004U)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG5                 ((uint32_t)0x00000005U)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG6                 ((uint32_t)0x00000006U)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG7                 ((uint32_t)0x00000007U)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG8                 ((uint32_t)0x00000008U)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG9                 ((uint32_t)0x00000009U)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG10                ((uint32_t)0x0000000AU)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG11                ((uint32_t)0x0000000BU)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG12                ((uint32_t)0x0000000CU)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG13                ((uint32_t)0x0000000DU)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG14                ((uint32_t)0x0000000EU)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG15                ((uint32_t)0x0000000FU)         /* !< TRIGx = External trigger input from
                                                                                    TIM x. */
#define GPTIMER_TSEL_ETSEL_TRIG_SUB0             ((uint32_t)0x00000010U)         /* !< TRIG_SUBx = External trigger input
                                                                                    from subscriber port x. */
#define GPTIMER_TSEL_ETSEL_TRIG_SUB1             ((uint32_t)0x00000011U)         /* !< TRIG_SUBx = External trigger input
                                                                                    from subscriber port x. */
/* GPTIMER_TSEL[TE] Bits */
#define GPTIMER_TSEL_TE_OFS                      (9)                             /* !< TE Offset */
#define GPTIMER_TSEL_TE_MASK                     ((uint32_t)0x00000200U)         /* !< Trigger Enable. This selects
                                                                                    whether a trigger is enabled or not
                                                                                    for this counter   0x0 = Triggers are
                                                                                    not used  0x1 = Triggers are used as
                                                                                    selected by the ETSEL field */
#define GPTIMER_TSEL_TE_DISABLED                 ((uint32_t)0x00000000U)         /* !< Triggers are not used. */
#define GPTIMER_TSEL_TE_ENABLED                  ((uint32_t)0x00000200U)         /* !< Triggers are used as selected by
                                                                                    the IE, ITSEL and ETSEL fields. */

/* GPTIMER_RC Bits */
/* GPTIMER_RC[RC] Bits */
#define GPTIMER_RC_RC_OFS                        (0)                             /* !< RC Offset */
#define GPTIMER_RC_RC_MASK                       ((uint32_t)0x000000FFU)         /* !< Repeat Counter Value */
#define GPTIMER_RC_RC_MINIMUM                    ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_RC_RC_MAXIMUM                    ((uint32_t)0x000000FFU)         /* !< Maximum Value */

/* GPTIMER_RCLD Bits */
/* GPTIMER_RCLD[RCLD] Bits */
#define GPTIMER_RCLD_RCLD_OFS                    (0)                             /* !< RCLD Offset */
#define GPTIMER_RCLD_RCLD_MASK                   ((uint32_t)0x000000FFU)         /* !< Repeat Counter Load Value This
                                                                                    field provides the value loaded into
                                                                                    the repeat counter at a load event
                                                                                    following the repeat counter value
                                                                                    equaling 0. */
#define GPTIMER_RCLD_RCLD_MINIMUM                ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_RCLD_RCLD_MAXIMUM                ((uint32_t)0x000000FFU)         /* !< Maximum Value */

/* GPTIMER_QDIR Bits */
/* GPTIMER_QDIR[DIR] Bits */
#define GPTIMER_QDIR_DIR_OFS                     (0)                             /* !< DIR Offset */
#define GPTIMER_QDIR_DIR_MASK                    ((uint32_t)0x00000001U)         /* !< Direction of count */
#define GPTIMER_QDIR_DIR_DOWN                    ((uint32_t)0x00000000U)         /* !< Down (Phase B leads Phase A) */
#define GPTIMER_QDIR_DIR_UP                      ((uint32_t)0x00000001U)         /* !< Up (Phase A leads Phase B) */

/* GPTIMER_FCTL Bits */
/* GPTIMER_FCTL[FIEN] Bits */
#define GPTIMER_FCTL_FIEN_OFS                    (0)                             /* !< FIEN Offset */
#define GPTIMER_FCTL_FIEN_MASK                   ((uint32_t)0x00000001U)         /* !< Fault Input Enable This bit enables
                                                                                    the input for fault detection. */
#define GPTIMER_FCTL_FIEN_DISABLED               ((uint32_t)0x00000000U)         /* !< Fault Input Disabled */
#define GPTIMER_FCTL_FIEN_ENABLED                ((uint32_t)0x00000001U)         /* !< Fault Input Enabled */
/* GPTIMER_FCTL[FI] Bits */
#define GPTIMER_FCTL_FI_OFS                      (2)                             /* !< FI Offset */
#define GPTIMER_FCTL_FI_MASK                     ((uint32_t)0x00000004U)         /* !< Fault Input Specifies whether the
                                                                                    overall fault condition is dependent
                                                                                    on the sensed fault pin. */
#define GPTIMER_FCTL_FI_INDEPENDENT              ((uint32_t)0x00000000U)         /* !< Overall Fault condition is not
                                                                                    dependent on sensed input. */
#define GPTIMER_FCTL_FI_DEPENDENT                ((uint32_t)0x00000004U)         /* !< Overall Fault condition is
                                                                                    dependent on sensed input. */
/* GPTIMER_FCTL[TFIM] Bits */
#define GPTIMER_FCTL_TFIM_OFS                    (7)                             /* !< TFIM Offset */
#define GPTIMER_FCTL_TFIM_MASK                   ((uint32_t)0x00000080U)         /* !< Trigger Fault Input Mask Specifies
                                                                                    whether the selected trigger
                                                                                    participates as a fault input. If
                                                                                    enabled and the trigger asserts, the
                                                                                    trigger is treated as a fault. */
#define GPTIMER_FCTL_TFIM_DISABLED               ((uint32_t)0x00000000U)         /* !< Selected trigger does not
                                                                                    participate in fault condition
                                                                                    generation */
#define GPTIMER_FCTL_TFIM_ENABLED                ((uint32_t)0x00000080U)         /* !< Selected trigger participates in
                                                                                    fault condition generation */
/* GPTIMER_FCTL[FL] Bits */
#define GPTIMER_FCTL_FL_OFS                      (3)                             /* !< FL Offset */
#define GPTIMER_FCTL_FL_MASK                     ((uint32_t)0x00000018U)         /* !< Fault Latch mode Specifies whether
                                                                                    the fault condition is latched and
                                                                                    configures the latch clear
                                                                                    conditions. */
#define GPTIMER_FCTL_FL_NO_LATCH                 ((uint32_t)0x00000000U)         /* !< Overall fault condition is not
                                                                                    dependent on the F bit in RIS */
#define GPTIMER_FCTL_FL_LATCH_SW_CLR             ((uint32_t)0x00000008U)         /* !< Overall fault condition is
                                                                                    dependent on the F bit in RIS */
#define GPTIMER_FCTL_FL_LATCH_Z_CLR              ((uint32_t)0x00000010U)         /* !< Fault condition is latched. Fault
                                                                                    condition is cleared on a zero event
                                                                                    if the fault input is 0. */
#define GPTIMER_FCTL_FL_LATCH_LD_CLR             ((uint32_t)0x00000018U)         /* !< Fault condition is latched. Fault
                                                                                    condition is cleared on a load event
                                                                                    if the fault input is 0. */
/* GPTIMER_FCTL[FSENAC0] Bits */
#define GPTIMER_FCTL_FSENAC0_OFS                 (8)                             /* !< FSENAC0 Offset */
#define GPTIMER_FCTL_FSENAC0_MASK                ((uint32_t)0x00000100U)         /* !< Specifies whether the COMP0 output
                                                                                    high/low is treated as fault
                                                                                    condition. */
#define GPTIMER_FCTL_FSENAC0_LOWCTIVE            ((uint32_t)0x00000000U)         /* !< Fault Input is active low. */
#define GPTIMER_FCTL_FSENAC0_HIGHACTIVE          ((uint32_t)0x00000100U)         /* !< Fault Input is active high. */
/* GPTIMER_FCTL[FSENAC1] Bits */
#define GPTIMER_FCTL_FSENAC1_OFS                 (9)                             /* !< FSENAC1 Offset */
#define GPTIMER_FCTL_FSENAC1_MASK                ((uint32_t)0x00000200U)         /* !< Specifies whether the COMP1 output
                                                                                    high/low is treated as fault
                                                                                    condition. */
#define GPTIMER_FCTL_FSENAC1_LOWCTIVE            ((uint32_t)0x00000000U)         /* !< Fault Input is active low. */
#define GPTIMER_FCTL_FSENAC1_HIGHACTIVE          ((uint32_t)0x00000200U)         /* !< Fault Input is active high. */
/* GPTIMER_FCTL[FSENAC2] Bits */
#define GPTIMER_FCTL_FSENAC2_OFS                 (10)                            /* !< FSENAC2 Offset */
#define GPTIMER_FCTL_FSENAC2_MASK                ((uint32_t)0x00000400U)         /* !< Specifies whether the COMP2 output
                                                                                    high/low is treated as fault
                                                                                    condition. */
#define GPTIMER_FCTL_FSENAC2_LOWCTIVE            ((uint32_t)0x00000000U)         /* !< Fault Input is active low. */
#define GPTIMER_FCTL_FSENAC2_HIGHACTIVE          ((uint32_t)0x00000400U)         /* !< Fault Input is active high. */
/* GPTIMER_FCTL[FSENEXT0] Bits */
#define GPTIMER_FCTL_FSENEXT0_OFS                (11)                            /* !< FSENEXT0 Offset */
#define GPTIMER_FCTL_FSENEXT0_MASK               ((uint32_t)0x00000800U)         /* !< Specifies whether the external
                                                                                    fault pin0 high/low is treated as
                                                                                    fault condition. */
#define GPTIMER_FCTL_FSENEXT0_LOWCTIVE           ((uint32_t)0x00000000U)         /* !< Fault Input is active low. */
#define GPTIMER_FCTL_FSENEXT0_HIGHACTIVE         ((uint32_t)0x00000800U)         /* !< Fault Input is active high. */
/* GPTIMER_FCTL[FSENEXT1] Bits */
#define GPTIMER_FCTL_FSENEXT1_OFS                (12)                            /* !< FSENEXT1 Offset */
#define GPTIMER_FCTL_FSENEXT1_MASK               ((uint32_t)0x00001000U)         /* !< Specifies whether the external
                                                                                    fault pin1 high/low is treated as
                                                                                    fault condition. */
#define GPTIMER_FCTL_FSENEXT1_LOWCTIVE           ((uint32_t)0x00000000U)         /* !< Fault Input is active low. */
#define GPTIMER_FCTL_FSENEXT1_HIGHACTIVE         ((uint32_t)0x00001000U)         /* !< Fault Input is active high. */
/* GPTIMER_FCTL[FSENEXT2] Bits */
#define GPTIMER_FCTL_FSENEXT2_OFS                (13)                            /* !< FSENEXT2 Offset */
#define GPTIMER_FCTL_FSENEXT2_MASK               ((uint32_t)0x00002000U)         /* !< Specifies whether the external
                                                                                    fault pin2 high/low is treated as
                                                                                    fault condition. */
#define GPTIMER_FCTL_FSENEXT2_LOWCTIVE           ((uint32_t)0x00000000U)         /* !< Fault Input is active low. */
#define GPTIMER_FCTL_FSENEXT2_HIGHACTIVE         ((uint32_t)0x00002000U)         /* !< Fault Input is active high. */

/* GPTIMER_FIFCTL Bits */
/* GPTIMER_FIFCTL[FP] Bits */
#define GPTIMER_FIFCTL_FP_OFS                    (0)                             /* !< FP Offset */
#define GPTIMER_FIFCTL_FP_MASK                   ((uint32_t)0x00000003U)         /* !< Filter Period This field specifies
                                                                                    the sample period for the input
                                                                                    filter.  I.e. The input is sampled
                                                                                    for FP timer clocks during filtering. */
#define GPTIMER_FIFCTL_FP_PER_3                  ((uint32_t)0x00000000U)         /* !< Filter Period 3 */
#define GPTIMER_FIFCTL_FP_PER_5                  ((uint32_t)0x00000001U)         /* !< Filter Period 5 */
#define GPTIMER_FIFCTL_FP_PER_8                  ((uint32_t)0x00000002U)         /* !< Filter Period 8 */
/* GPTIMER_FIFCTL[CPV] Bits */
#define GPTIMER_FIFCTL_CPV_OFS                   (3)                             /* !< CPV Offset */
#define GPTIMER_FIFCTL_CPV_MASK                  ((uint32_t)0x00000008U)         /* !< Consecutive Period/Voting Select
                                                                                    This bit controls whether the input
                                                                                    filter uses a stricter consecutive
                                                                                    period count or majority voting. */
#define GPTIMER_FIFCTL_CPV_CONSEC_PER            ((uint32_t)0x00000000U)         /* !< Consecutive Periods. The input must
                                                                                    be at a specific logic level for the
                                                                                    period defined by FP before it is
                                                                                    passed to the filter output. */
#define GPTIMER_FIFCTL_CPV_VOTING                ((uint32_t)0x00000008U)         /* !< Voting. The filter ignores one
                                                                                    clock of opposite logic over the
                                                                                    filter period. I.e. Over FP samples
                                                                                    of the input, up to 1 sample may be
                                                                                    of an opposite logic value (glitch)
                                                                                    without affecting the output */
/* GPTIMER_FIFCTL[FILTEN] Bits */
#define GPTIMER_FIFCTL_FILTEN_OFS                (4)                             /* !< FILTEN Offset */
#define GPTIMER_FIFCTL_FILTEN_MASK               ((uint32_t)0x00000010U)         /* !< Filter Enable This bit controls
                                                                                    whether the input is filtered by the
                                                                                    input filter or bypasses to go
                                                                                    directly to the optional pre-scale
                                                                                    filter and then to the edge detect. */
#define GPTIMER_FIFCTL_FILTEN_BYPASS             ((uint32_t)0x00000000U)         /* !< Bypass */
#define GPTIMER_FIFCTL_FILTEN_FILTERED           ((uint32_t)0x00000010U)         /* !< Filtered. */

/* GPTIMER_CCPD Bits */
/* GPTIMER_CCPD[C0CCP0] Bits */
#define GPTIMER_CCPD_C0CCP0_OFS                  (0)                             /* !< C0CCP0 Offset */
#define GPTIMER_CCPD_C0CCP0_MASK                 ((uint32_t)0x00000001U)         /* !< CCP0 direction */
#define GPTIMER_CCPD_C0CCP0_INPUT                ((uint32_t)0x00000000U)         /* !< Input */
#define GPTIMER_CCPD_C0CCP0_OUTPUT               ((uint32_t)0x00000001U)         /* !< Output */
/* GPTIMER_CCPD[C0CCP1] Bits */
#define GPTIMER_CCPD_C0CCP1_OFS                  (1)                             /* !< C0CCP1 Offset */
#define GPTIMER_CCPD_C0CCP1_MASK                 ((uint32_t)0x00000002U)         /* !< CCP1 direction */
#define GPTIMER_CCPD_C0CCP1_INPUT                ((uint32_t)0x00000000U)         /* !< Input */
#define GPTIMER_CCPD_C0CCP1_OUTPUT               ((uint32_t)0x00000002U)         /* !< Output */
/* GPTIMER_CCPD[C0CCP2] Bits */
#define GPTIMER_CCPD_C0CCP2_OFS                  (2)                             /* !< C0CCP2 Offset */
#define GPTIMER_CCPD_C0CCP2_MASK                 ((uint32_t)0x00000004U)         /* !< CCP2 direction */
#define GPTIMER_CCPD_C0CCP2_INPUT                ((uint32_t)0x00000000U)         /* !< input */
#define GPTIMER_CCPD_C0CCP2_OUTPUT               ((uint32_t)0x00000004U)         /* !< Output */
/* GPTIMER_CCPD[C0CCP3] Bits */
#define GPTIMER_CCPD_C0CCP3_OFS                  (3)                             /* !< C0CCP3 Offset */
#define GPTIMER_CCPD_C0CCP3_MASK                 ((uint32_t)0x00000008U)         /* !< CCP3 direction */
#define GPTIMER_CCPD_C0CCP3_INPUT                ((uint32_t)0x00000000U)         /* !< Input */
#define GPTIMER_CCPD_C0CCP3_OUTPUT               ((uint32_t)0x00000008U)         /* !< Output */

/* GPTIMER_ODIS Bits */
/* GPTIMER_ODIS[C0CCP0] Bits */
#define GPTIMER_ODIS_C0CCP0_OFS                  (0)                             /* !< C0CCP0 Offset */
#define GPTIMER_ODIS_C0CCP0_MASK                 ((uint32_t)0x00000001U)         /* !< Counter CCP0 Disable Mask Defines
                                                                                    whether CCP0 of Counter n is forced
                                                                                    low or not */
#define GPTIMER_ODIS_C0CCP0_CCP_OUTPUT_OCTL      ((uint32_t)0x00000000U)         /* !< Output function as selected by the
                                                                                    OCTL register CCPO field are provided
                                                                                    to output inversion block. */
#define GPTIMER_ODIS_C0CCP0_CCP_OUTPUT_LOW       ((uint32_t)0x00000001U)         /* !< CCP output occpout[0] is forced
                                                                                    low. */
/* GPTIMER_ODIS[C0CCP1] Bits */
#define GPTIMER_ODIS_C0CCP1_OFS                  (1)                             /* !< C0CCP1 Offset */
#define GPTIMER_ODIS_C0CCP1_MASK                 ((uint32_t)0x00000002U)         /* !< Counter CCP1 Disable Mask Defines
                                                                                    whether CCP0 of Counter n is forced
                                                                                    low or not */
#define GPTIMER_ODIS_C0CCP1_CCP_OUTPUT_OCTL      ((uint32_t)0x00000000U)         /* !< Output function as selected by the
                                                                                    OCTL register CCPO field are provided
                                                                                    to output inversion block. */
#define GPTIMER_ODIS_C0CCP1_CCP_OUTPUT_LOW       ((uint32_t)0x00000002U)         /* !< CCP output occpout[1] is forced
                                                                                    low. */
/* GPTIMER_ODIS[C0CCP2] Bits */
#define GPTIMER_ODIS_C0CCP2_OFS                  (2)                             /* !< C0CCP2 Offset */
#define GPTIMER_ODIS_C0CCP2_MASK                 ((uint32_t)0x00000004U)         /* !< Counter CCP2 Disable Mask Defines
                                                                                    whether CCP2 of Counter n is forced
                                                                                    low or not */
#define GPTIMER_ODIS_C0CCP2_CCP_OUTPUT_OCTL      ((uint32_t)0x00000000U)         /* !< Output function as selected by the
                                                                                    OCTL register CCPO field are provided
                                                                                    to output inversion block. */
#define GPTIMER_ODIS_C0CCP2_CCP_OUTPUT_LOW       ((uint32_t)0x00000004U)         /* !< CCP output occpout[2] is forced
                                                                                    low. */
/* GPTIMER_ODIS[C0CCP3] Bits */
#define GPTIMER_ODIS_C0CCP3_OFS                  (3)                             /* !< C0CCP3 Offset */
#define GPTIMER_ODIS_C0CCP3_MASK                 ((uint32_t)0x00000008U)         /* !< Counter CCP3 Disable Mask Defines
                                                                                    whether CCP3 of Counter n is forced
                                                                                    low or not */
#define GPTIMER_ODIS_C0CCP3_CCP_OUTPUT_OCTL      ((uint32_t)0x00000000U)         /* !< Output function as selected by the
                                                                                    OCTL register CCPO field are provided
                                                                                    to occpout[2]. */
#define GPTIMER_ODIS_C0CCP3_CCP_OUTPUT_LOW       ((uint32_t)0x00000008U)         /* !< CCP output occpout[3] is forced
                                                                                    low. */

/* GPTIMER_CCLKCTL Bits */
/* GPTIMER_CCLKCTL[CLKEN] Bits */
#define GPTIMER_CCLKCTL_CLKEN_OFS                (0)                             /* !< CLKEN Offset */
#define GPTIMER_CCLKCTL_CLKEN_MASK               ((uint32_t)0x00000001U)         /* !< Clock Enable Disables the clock
                                                                                    gating to the module. SW has to
                                                                                    explicitly program the value  to 0 to
                                                                                    gate the clock. */
#define GPTIMER_CCLKCTL_CLKEN_DISABLED           ((uint32_t)0x00000000U)         /* !< Clock is disabled. */
#define GPTIMER_CCLKCTL_CLKEN_ENABLED            ((uint32_t)0x00000001U)         /* !< Clock is enabled */

/* GPTIMER_CPS Bits */
/* GPTIMER_CPS[PCNT] Bits */
#define GPTIMER_CPS_PCNT_OFS                     (0)                             /* !< PCNT Offset */
#define GPTIMER_CPS_PCNT_MASK                    ((uint32_t)0x000000FFU)         /* !< Pre-Scale Count This field
                                                                                    specifies the pre-scale count value.
                                                                                    The selected TIMCLK source is divided
                                                                                    by a value of (PCNT+1).  A PCNT value
                                                                                    of 0 divides TIMCLK by 1, effectively
                                                                                    bypassing the divider. A PCNT value
                                                                                    of greater than 0 divides the TIMCLK
                                                                                    source generating a slower clock */
#define GPTIMER_CPS_PCNT_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_CPS_PCNT_MAXIMUM                 ((uint32_t)0x000000FFU)         /* !< Maximum Value */

/* GPTIMER_CPSV Bits */
/* GPTIMER_CPSV[CPSVAL] Bits */
#define GPTIMER_CPSV_CPSVAL_OFS                  (0)                             /* !< CPSVAL Offset */
#define GPTIMER_CPSV_CPSVAL_MASK                 ((uint32_t)0x000000FFU)         /* !< Current Prescale Count Value */
#define GPTIMER_CPSV_CPSVAL_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum value */
#define GPTIMER_CPSV_CPSVAL_MAXIMUM              ((uint32_t)0x000000FFU)         /* !< Maximum Value */

/* GPTIMER_CTTRIGCTL Bits */
/* GPTIMER_CTTRIGCTL[CTEN] Bits */
#define GPTIMER_CTTRIGCTL_CTEN_OFS               (0)                             /* !< CTEN Offset */
#define GPTIMER_CTTRIGCTL_CTEN_MASK              ((uint32_t)0x00000001U)         /* !< Timer Cross trigger enable. This
                                                                                    field is used to enable whether the
                                                                                    SW or HW logic can generate a timer
                                                                                    cross trigger event in the system.
                                                                                    These cross triggers are connected to
                                                                                    the respective timer trigger in of
                                                                                    the other timer IPs in the SOC power
                                                                                    domain.  The timer cross trigger is
                                                                                    essentially the combined logic of the
                                                                                    HW and SW conditions controlling EN
                                                                                    bit in the CTRCTL register. */
#define GPTIMER_CTTRIGCTL_CTEN_DISABLED          ((uint32_t)0x00000000U)         /* !< Cross trigger generation disabled. */
#define GPTIMER_CTTRIGCTL_CTEN_ENABLE            ((uint32_t)0x00000001U)         /* !< Cross trigger generation enabled */
/* GPTIMER_CTTRIGCTL[EVTCTEN] Bits */
#define GPTIMER_CTTRIGCTL_EVTCTEN_OFS            (1)                             /* !< EVTCTEN Offset */
#define GPTIMER_CTTRIGCTL_EVTCTEN_MASK           ((uint32_t)0x00000002U)         /* !< Enable the Input Trigger Conditions
                                                                                    to the Timer module as a condition
                                                                                    for Cross Triggers. */
#define GPTIMER_CTTRIGCTL_EVTCTEN_DISABLED       ((uint32_t)0x00000000U)         /* !< Cross trigger generation disabled. */
#define GPTIMER_CTTRIGCTL_EVTCTEN_ENABLE         ((uint32_t)0x00000002U)         /* !< Cross trigger generation enabled */
/* GPTIMER_CTTRIGCTL[EVTCTTRIGSEL] Bits */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_OFS       (16)                            /* !< EVTCTTRIGSEL Offset */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_MASK      ((uint32_t)0x000F0000U)         /* !< Used to Select the subscriber port
                                                                                    that should be used for input cross
                                                                                    trigger. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_FSUB0     ((uint32_t)0x00000000U)         /* !< Use FSUB0 as cross trigger source. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_FSUB1     ((uint32_t)0x00010000U)         /* !< Use FSUB1 as cross trigger source. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_Z         ((uint32_t)0x00020000U)         /* !< Use Zero event  as cross trigger
                                                                                    source. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_L         ((uint32_t)0x00030000U)         /* !< Use Load event as cross trigger
                                                                                    source. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCD0      ((uint32_t)0x00040000U)         /* !< Use CCD0 event  as cross trigger
                                                                                    source. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCD1      ((uint32_t)0x00050000U)         /* !< Use CCD1 event  as cross trigger
                                                                                    source. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCD2      ((uint32_t)0x00060000U)         /* !< Use CCD2 event  as cross trigger
                                                                                    source. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCD3      ((uint32_t)0x00070000U)         /* !< Use CCD3 event  as cross trigger
                                                                                    source. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCU0      ((uint32_t)0x00080000U)         /* !< Use CCU0 event  as cross trigger
                                                                                    source. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCU1      ((uint32_t)0x00090000U)         /* !< Use CCU1 event  as cross trigger
                                                                                    source. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCU2      ((uint32_t)0x000A0000U)         /* !< Use CCU2 event  as cross trigger
                                                                                    source. */
#define GPTIMER_CTTRIGCTL_EVTCTTRIGSEL_CCU3      ((uint32_t)0x000B0000U)         /* !< Use CCU3 event  as cross trigger
                                                                                    source. */

/* GPTIMER_CTTRIG Bits */
/* GPTIMER_CTTRIG[TRIG] Bits */
#define GPTIMER_CTTRIG_TRIG_OFS                  (0)                             /* !< TRIG Offset */
#define GPTIMER_CTTRIG_TRIG_MASK                 ((uint32_t)0x00000001U)         /* !< Generate Cross Trigger This bit
                                                                                    when programmed will generate a
                                                                                    synchronized trigger condition all
                                                                                    the cross trigger enabled Timer
                                                                                    instances including current timer
                                                                                    instance. */
#define GPTIMER_CTTRIG_TRIG_DISABLED             ((uint32_t)0x00000000U)         /* !< Cross trigger generation disabled */
#define GPTIMER_CTTRIG_TRIG_GENERATE             ((uint32_t)0x00000001U)         /* !< Generate Cross trigger pulse */

/* GPTIMER_FSCTL Bits */
/* GPTIMER_FSCTL[FCEN] Bits */
#define GPTIMER_FSCTL_FCEN_OFS                   (0)                             /* !< FCEN Offset */
#define GPTIMER_FSCTL_FCEN_MASK                  ((uint32_t)0x00000001U)         /* !< This field controls whether the
                                                                                    fault is caused by the system clock
                                                                                    fault. */
#define GPTIMER_FSCTL_FCEN_DISABLE               ((uint32_t)0x00000000U)         /* !< Disable */
#define GPTIMER_FSCTL_FCEN_ENABLE                ((uint32_t)0x00000001U)         /* !< Enable */
/* GPTIMER_FSCTL[FAC0EN] Bits */
#define GPTIMER_FSCTL_FAC0EN_OFS                 (1)                             /* !< FAC0EN Offset */
#define GPTIMER_FSCTL_FAC0EN_MASK                ((uint32_t)0x00000002U)         /* !< This field controls whether the
                                                                                    fault signal is caused by COMP0
                                                                                    output. */
#define GPTIMER_FSCTL_FAC0EN_DISABLE             ((uint32_t)0x00000000U)         /* !< Disable */
#define GPTIMER_FSCTL_FAC0EN_ENABLE              ((uint32_t)0x00000002U)         /* !< Enable */
/* GPTIMER_FSCTL[FAC1EN] Bits */
#define GPTIMER_FSCTL_FAC1EN_OFS                 (2)                             /* !< FAC1EN Offset */
#define GPTIMER_FSCTL_FAC1EN_MASK                ((uint32_t)0x00000004U)         /* !< This field controls whether the
                                                                                    fault is caused by COMP1 output. */
#define GPTIMER_FSCTL_FAC1EN_DISABLE             ((uint32_t)0x00000000U)         /* !< Disable */
#define GPTIMER_FSCTL_FAC1EN_ENABLE              ((uint32_t)0x00000004U)         /* !< Enable */
/* GPTIMER_FSCTL[FAC2EN] Bits */
#define GPTIMER_FSCTL_FAC2EN_OFS                 (3)                             /* !< FAC2EN Offset */
#define GPTIMER_FSCTL_FAC2EN_MASK                ((uint32_t)0x00000008U)         /* !< This field controls whether the
                                                                                    fault is caused by COMP2 output. */
#define GPTIMER_FSCTL_FAC2EN_DISABLE             ((uint32_t)0x00000000U)         /* !< Disable */
#define GPTIMER_FSCTL_FAC2EN_ENABLE              ((uint32_t)0x00000008U)         /* !< Enable */
/* GPTIMER_FSCTL[FEX0EN] Bits */
#define GPTIMER_FSCTL_FEX0EN_OFS                 (4)                             /* !< FEX0EN Offset */
#define GPTIMER_FSCTL_FEX0EN_MASK                ((uint32_t)0x00000010U)         /* !< This field controls whether the
                                                                                    fault is caused by external fault pin
                                                                                    0. */
#define GPTIMER_FSCTL_FEX0EN_DISABLE             ((uint32_t)0x00000000U)         /* !< Disable */
#define GPTIMER_FSCTL_FEX0EN_ENABLE              ((uint32_t)0x00000010U)         /* !< Enable */
/* GPTIMER_FSCTL[FEX1EN] Bits */
#define GPTIMER_FSCTL_FEX1EN_OFS                 (5)                             /* !< FEX1EN Offset */
#define GPTIMER_FSCTL_FEX1EN_MASK                ((uint32_t)0x00000020U)         /* !< This field controls whether the
                                                                                    fault is caused by external fault pin
                                                                                    1. */
#define GPTIMER_FSCTL_FEX1EN_DISABLE             ((uint32_t)0x00000000U)         /* !< Disable */
#define GPTIMER_FSCTL_FEX1EN_ENABLE              ((uint32_t)0x00000020U)         /* !< Enable */
/* GPTIMER_FSCTL[FEX2EN] Bits */
#define GPTIMER_FSCTL_FEX2EN_OFS                 (6)                             /* !< FEX2EN Offset */
#define GPTIMER_FSCTL_FEX2EN_MASK                ((uint32_t)0x00000040U)         /* !< This field controls whether the
                                                                                    fault is caused by external fault pin
                                                                                    2. */
#define GPTIMER_FSCTL_FEX2EN_DISABLE             ((uint32_t)0x00000000U)         /* !< Disable */
#define GPTIMER_FSCTL_FEX2EN_ENABLE              ((uint32_t)0x00000040U)         /* !< Enable */

/* GPTIMER_GCTL Bits */
/* GPTIMER_GCTL[SHDWLDEN] Bits */
#define GPTIMER_GCTL_SHDWLDEN_OFS                (0)                             /* !< SHDWLDEN Offset */
#define GPTIMER_GCTL_SHDWLDEN_MASK               ((uint32_t)0x00000001U)         /* !< Enables shadow to active load of
                                                                                    bufferred registers and register
                                                                                    fields. */
#define GPTIMER_GCTL_SHDWLDEN_DISABLE            ((uint32_t)0x00000000U)         /* !< Disable */
#define GPTIMER_GCTL_SHDWLDEN_ENABLE             ((uint32_t)0x00000001U)         /* !< Enable */

/* GPTIMER_GEN_EVENT1_IIDX Bits */
/* GPTIMER_GEN_EVENT1_IIDX[STAT] Bits */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_OFS         (0)                             /* !< STAT Offset */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_MASK        ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_NO_INTR     ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_Z           ((uint32_t)0x00000001U)         /* !< Interrupt Source: Zero event (Z) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_L           ((uint32_t)0x00000002U)         /* !< nterrupt Source: Load event (L) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCD0        ((uint32_t)0x00000005U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD0) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCD1        ((uint32_t)0x00000006U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD1) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCD2        ((uint32_t)0x00000007U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD2) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCD3        ((uint32_t)0x00000008U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD3) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCU0        ((uint32_t)0x00000009U)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU0) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCU1        ((uint32_t)0x0000000AU)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU1) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCU2        ((uint32_t)0x0000000BU)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU2) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCU3        ((uint32_t)0x0000000CU)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU3) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCD4        ((uint32_t)0x0000000DU)         /* !< Interrupt Source: Compare down
                                                                                    event (CCD4) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCD5        ((uint32_t)0x0000000EU)         /* !< Interrupt Source: Compare down
                                                                                    event (CCD5) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCU4        ((uint32_t)0x0000000FU)         /* !< Interrupt Source: Compare down
                                                                                    event (CCU4) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_CCU5        ((uint32_t)0x00000010U)         /* !< Interrupt Source: Compare down
                                                                                    event (CCU5) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_F           ((uint32_t)0x00000019U)         /* !< Interrupt Source: Fault Event
                                                                                    generated an interrupt. (F) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_TOV         ((uint32_t)0x0000001AU)         /* !< Interrupt Source: Trigger overflow
                                                                                    (TOV) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_REPC        ((uint32_t)0x0000001BU)         /* !< Interrupt Source: Repeat Counter
                                                                                    Zero (REPC) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_DC          ((uint32_t)0x0000001CU)         /* !< Interrupt Source: Direction Change
                                                                                    (DC) */
#define GPTIMER_GEN_EVENT1_IIDX_STAT_QEIERR      ((uint32_t)0x0000001DU)         /* !< Interrupt Source:QEI Incorrect
                                                                                    state transition error (QEIERR) */

/* GPTIMER_GEN_EVENT1_IMASK Bits */
/* GPTIMER_GEN_EVENT1_IMASK[Z] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_Z_OFS           (0)                             /* !< Z Offset */
#define GPTIMER_GEN_EVENT1_IMASK_Z_MASK          ((uint32_t)0x00000001U)         /* !< Zero Event mask */
#define GPTIMER_GEN_EVENT1_IMASK_Z_CLR           ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT1_IMASK_Z_SET           ((uint32_t)0x00000001U)         /* !< Enable Event */
/* GPTIMER_GEN_EVENT1_IMASK[L] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_L_OFS           (1)                             /* !< L Offset */
#define GPTIMER_GEN_EVENT1_IMASK_L_MASK          ((uint32_t)0x00000002U)         /* !< Load Event mask */
#define GPTIMER_GEN_EVENT1_IMASK_L_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_L_SET           ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[CCD0] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCD0_OFS        (4)                             /* !< CCD0 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCD0_MASK       ((uint32_t)0x00000010U)         /* !< Capture or Compare DN event mask
                                                                                    CCP0 */
#define GPTIMER_GEN_EVENT1_IMASK_CCD0_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCD0_SET        ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[CCD1] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCD1_OFS        (5)                             /* !< CCD1 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCD1_MASK       ((uint32_t)0x00000020U)         /* !< Capture or Compare DN event mask
                                                                                    CCP1 */
#define GPTIMER_GEN_EVENT1_IMASK_CCD1_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCD1_SET        ((uint32_t)0x00000020U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[CCU0] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCU0_OFS        (8)                             /* !< CCU0 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCU0_MASK       ((uint32_t)0x00000100U)         /* !< Capture or Compare UP event mask
                                                                                    CCP0 */
#define GPTIMER_GEN_EVENT1_IMASK_CCU0_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCU0_SET        ((uint32_t)0x00000100U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[CCU1] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCU1_OFS        (9)                             /* !< CCU1 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCU1_MASK       ((uint32_t)0x00000200U)         /* !< Capture or Compare UP event mask
                                                                                    CCP1 */
#define GPTIMER_GEN_EVENT1_IMASK_CCU1_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCU1_SET        ((uint32_t)0x00000200U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[F] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_F_OFS           (24)                            /* !< F Offset */
#define GPTIMER_GEN_EVENT1_IMASK_F_MASK          ((uint32_t)0x01000000U)         /* !< Fault Event mask */
#define GPTIMER_GEN_EVENT1_IMASK_F_CLR           ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT1_IMASK_F_SET           ((uint32_t)0x01000000U)         /* !< Enable Event */
/* GPTIMER_GEN_EVENT1_IMASK[TOV] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_TOV_OFS         (25)                            /* !< TOV Offset */
#define GPTIMER_GEN_EVENT1_IMASK_TOV_MASK        ((uint32_t)0x02000000U)         /* !< Trigger Overflow Event mask */
#define GPTIMER_GEN_EVENT1_IMASK_TOV_CLR         ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT1_IMASK_TOV_SET         ((uint32_t)0x02000000U)         /* !< Enable Event */
/* GPTIMER_GEN_EVENT1_IMASK[DC] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_DC_OFS          (27)                            /* !< DC Offset */
#define GPTIMER_GEN_EVENT1_IMASK_DC_MASK         ((uint32_t)0x08000000U)         /* !< Direction Change Event mask */
#define GPTIMER_GEN_EVENT1_IMASK_DC_CLR          ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT1_IMASK_DC_SET          ((uint32_t)0x08000000U)         /* !< Enable Event */
/* GPTIMER_GEN_EVENT1_IMASK[QEIERR] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_QEIERR_OFS      (28)                            /* !< QEIERR Offset */
#define GPTIMER_GEN_EVENT1_IMASK_QEIERR_MASK     ((uint32_t)0x10000000U)         /* !< QEIERR Event mask */
#define GPTIMER_GEN_EVENT1_IMASK_QEIERR_CLR      ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT1_IMASK_QEIERR_SET      ((uint32_t)0x10000000U)         /* !< Enable Event */
/* GPTIMER_GEN_EVENT1_IMASK[CCD2] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCD2_OFS        (6)                             /* !< CCD2 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCD2_MASK       ((uint32_t)0x00000040U)         /* !< Capture or Compare DN event mask
                                                                                    CCP2 */
#define GPTIMER_GEN_EVENT1_IMASK_CCD2_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCD2_SET        ((uint32_t)0x00000040U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[CCD3] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCD3_OFS        (7)                             /* !< CCD3 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCD3_MASK       ((uint32_t)0x00000080U)         /* !< Capture or Compare DN event mask
                                                                                    CCP3 */
#define GPTIMER_GEN_EVENT1_IMASK_CCD3_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCD3_SET        ((uint32_t)0x00000080U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[CCU2] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCU2_OFS        (10)                            /* !< CCU2 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCU2_MASK       ((uint32_t)0x00000400U)         /* !< Capture or Compare UP event mask
                                                                                    CCP2 */
#define GPTIMER_GEN_EVENT1_IMASK_CCU2_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCU2_SET        ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[CCU3] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCU3_OFS        (11)                            /* !< CCU3 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCU3_MASK       ((uint32_t)0x00000800U)         /* !< Capture or Compare UP event mask
                                                                                    CCP3 */
#define GPTIMER_GEN_EVENT1_IMASK_CCU3_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCU3_SET        ((uint32_t)0x00000800U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[CCD4] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCD4_OFS        (12)                            /* !< CCD4 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCD4_MASK       ((uint32_t)0x00001000U)         /* !< Compare DN event mask CCP4 */
#define GPTIMER_GEN_EVENT1_IMASK_CCD4_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCD4_SET        ((uint32_t)0x00001000U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[CCD5] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCD5_OFS        (13)                            /* !< CCD5 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCD5_MASK       ((uint32_t)0x00002000U)         /* !< Compare DN event mask CCP5 */
#define GPTIMER_GEN_EVENT1_IMASK_CCD5_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCD5_SET        ((uint32_t)0x00002000U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[CCU4] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCU4_OFS        (14)                            /* !< CCU4 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCU4_MASK       ((uint32_t)0x00004000U)         /* !< Compare UP event mask CCP4 */
#define GPTIMER_GEN_EVENT1_IMASK_CCU4_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCU4_SET        ((uint32_t)0x00004000U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[CCU5] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_CCU5_OFS        (15)                            /* !< CCU5 Offset */
#define GPTIMER_GEN_EVENT1_IMASK_CCU5_MASK       ((uint32_t)0x00008000U)         /* !< Compare UP event mask CCP5 */
#define GPTIMER_GEN_EVENT1_IMASK_CCU5_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT1_IMASK_CCU5_SET        ((uint32_t)0x00008000U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT1_IMASK[REPC] Bits */
#define GPTIMER_GEN_EVENT1_IMASK_REPC_OFS        (26)                            /* !< REPC Offset */
#define GPTIMER_GEN_EVENT1_IMASK_REPC_MASK       ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero Event mask */
#define GPTIMER_GEN_EVENT1_IMASK_REPC_CLR        ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT1_IMASK_REPC_SET        ((uint32_t)0x04000000U)         /* !< Enable Event */

/* GPTIMER_GEN_EVENT1_RIS Bits */
/* GPTIMER_GEN_EVENT1_RIS[Z] Bits */
#define GPTIMER_GEN_EVENT1_RIS_Z_OFS             (0)                             /* !< Z Offset */
#define GPTIMER_GEN_EVENT1_RIS_Z_MASK            ((uint32_t)0x00000001U)         /* !< Zero event generated an interrupt. */
#define GPTIMER_GEN_EVENT1_RIS_Z_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_Z_SET             ((uint32_t)0x00000001U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[L] Bits */
#define GPTIMER_GEN_EVENT1_RIS_L_OFS             (1)                             /* !< L Offset */
#define GPTIMER_GEN_EVENT1_RIS_L_MASK            ((uint32_t)0x00000002U)         /* !< Load event generated an interrupt. */
#define GPTIMER_GEN_EVENT1_RIS_L_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_L_SET             ((uint32_t)0x00000002U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCD0] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCD0_OFS          (4)                             /* !< CCD0 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCD0_MASK         ((uint32_t)0x00000010U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_GEN_EVENT1_RIS_CCD0_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCD0_SET          ((uint32_t)0x00000010U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCD1] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCD1_OFS          (5)                             /* !< CCD1 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCD1_MASK         ((uint32_t)0x00000020U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_GEN_EVENT1_RIS_CCD1_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCD1_SET          ((uint32_t)0x00000020U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCU0] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCU0_OFS          (8)                             /* !< CCU0 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCU0_MASK         ((uint32_t)0x00000100U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_GEN_EVENT1_RIS_CCU0_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCU0_SET          ((uint32_t)0x00000100U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCU1] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCU1_OFS          (9)                             /* !< CCU1 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCU1_MASK         ((uint32_t)0x00000200U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_GEN_EVENT1_RIS_CCU1_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCU1_SET          ((uint32_t)0x00000200U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[TOV] Bits */
#define GPTIMER_GEN_EVENT1_RIS_TOV_OFS           (25)                            /* !< TOV Offset */
#define GPTIMER_GEN_EVENT1_RIS_TOV_MASK          ((uint32_t)0x02000000U)         /* !< Trigger overflow */
#define GPTIMER_GEN_EVENT1_RIS_TOV_CLR           ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_TOV_SET           ((uint32_t)0x02000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[F] Bits */
#define GPTIMER_GEN_EVENT1_RIS_F_OFS             (24)                            /* !< F Offset */
#define GPTIMER_GEN_EVENT1_RIS_F_MASK            ((uint32_t)0x01000000U)         /* !< Fault */
#define GPTIMER_GEN_EVENT1_RIS_F_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_F_SET             ((uint32_t)0x01000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[DC] Bits */
#define GPTIMER_GEN_EVENT1_RIS_DC_OFS            (27)                            /* !< DC Offset */
#define GPTIMER_GEN_EVENT1_RIS_DC_MASK           ((uint32_t)0x08000000U)         /* !< Direction Change */
#define GPTIMER_GEN_EVENT1_RIS_DC_CLR            ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_DC_SET            ((uint32_t)0x08000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[QEIERR] Bits */
#define GPTIMER_GEN_EVENT1_RIS_QEIERR_OFS        (28)                            /* !< QEIERR Offset */
#define GPTIMER_GEN_EVENT1_RIS_QEIERR_MASK       ((uint32_t)0x10000000U)         /* !< QEIERR, set on an incorrect state
                                                                                    transition on the encoder interface. */
#define GPTIMER_GEN_EVENT1_RIS_QEIERR_CLR        ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_QEIERR_SET        ((uint32_t)0x10000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCD2] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCD2_OFS          (6)                             /* !< CCD2 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCD2_MASK         ((uint32_t)0x00000040U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_GEN_EVENT1_RIS_CCD2_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCD2_SET          ((uint32_t)0x00000040U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCD3] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCD3_OFS          (7)                             /* !< CCD3 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCD3_MASK         ((uint32_t)0x00000080U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_GEN_EVENT1_RIS_CCD3_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCD3_SET          ((uint32_t)0x00000080U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCU2] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCU2_OFS          (10)                            /* !< CCU2 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCU2_MASK         ((uint32_t)0x00000400U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_GEN_EVENT1_RIS_CCU2_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCU2_SET          ((uint32_t)0x00000400U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCU3] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCU3_OFS          (11)                            /* !< CCU3 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCU3_MASK         ((uint32_t)0x00000800U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_GEN_EVENT1_RIS_CCU3_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCU3_SET          ((uint32_t)0x00000800U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCD4] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCD4_OFS          (12)                            /* !< CCD4 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCD4_MASK         ((uint32_t)0x00001000U)         /* !< Compare down event generated an
                                                                                    interrupt CCD4 */
#define GPTIMER_GEN_EVENT1_RIS_CCD4_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCD4_SET          ((uint32_t)0x00001000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCD5] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCD5_OFS          (13)                            /* !< CCD5 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCD5_MASK         ((uint32_t)0x00002000U)         /* !< Compare down event generated an
                                                                                    interrupt CCD5 */
#define GPTIMER_GEN_EVENT1_RIS_CCD5_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCD5_SET          ((uint32_t)0x00002000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCU4] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCU4_OFS          (14)                            /* !< CCU4 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCU4_MASK         ((uint32_t)0x00004000U)         /* !< Compare up event generated an
                                                                                    interrupt CCU4 */
#define GPTIMER_GEN_EVENT1_RIS_CCU4_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCU4_SET          ((uint32_t)0x00004000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[CCU5] Bits */
#define GPTIMER_GEN_EVENT1_RIS_CCU5_OFS          (15)                            /* !< CCU5 Offset */
#define GPTIMER_GEN_EVENT1_RIS_CCU5_MASK         ((uint32_t)0x00008000U)         /* !< Compare up event generated an
                                                                                    interrupt CCP5 */
#define GPTIMER_GEN_EVENT1_RIS_CCU5_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_CCU5_SET          ((uint32_t)0x00008000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_RIS[REPC] Bits */
#define GPTIMER_GEN_EVENT1_RIS_REPC_OFS          (26)                            /* !< REPC Offset */
#define GPTIMER_GEN_EVENT1_RIS_REPC_MASK         ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero */
#define GPTIMER_GEN_EVENT1_RIS_REPC_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_RIS_REPC_SET          ((uint32_t)0x04000000U)         /* !< Event Set */

/* GPTIMER_GEN_EVENT1_MIS Bits */
/* GPTIMER_GEN_EVENT1_MIS[Z] Bits */
#define GPTIMER_GEN_EVENT1_MIS_Z_OFS             (0)                             /* !< Z Offset */
#define GPTIMER_GEN_EVENT1_MIS_Z_MASK            ((uint32_t)0x00000001U)         /* !< Zero event generated an interrupt. */
#define GPTIMER_GEN_EVENT1_MIS_Z_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_Z_SET             ((uint32_t)0x00000001U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[L] Bits */
#define GPTIMER_GEN_EVENT1_MIS_L_OFS             (1)                             /* !< L Offset */
#define GPTIMER_GEN_EVENT1_MIS_L_MASK            ((uint32_t)0x00000002U)         /* !< Load event generated an interrupt. */
#define GPTIMER_GEN_EVENT1_MIS_L_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_L_SET             ((uint32_t)0x00000002U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCD0] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCD0_OFS          (4)                             /* !< CCD0 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCD0_MASK         ((uint32_t)0x00000010U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_GEN_EVENT1_MIS_CCD0_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCD0_SET          ((uint32_t)0x00000010U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCD1] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCD1_OFS          (5)                             /* !< CCD1 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCD1_MASK         ((uint32_t)0x00000020U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_GEN_EVENT1_MIS_CCD1_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCD1_SET          ((uint32_t)0x00000020U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCU0] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCU0_OFS          (8)                             /* !< CCU0 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCU0_MASK         ((uint32_t)0x00000100U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_GEN_EVENT1_MIS_CCU0_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCU0_SET          ((uint32_t)0x00000100U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCU1] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCU1_OFS          (9)                             /* !< CCU1 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCU1_MASK         ((uint32_t)0x00000200U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_GEN_EVENT1_MIS_CCU1_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCU1_SET          ((uint32_t)0x00000200U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[F] Bits */
#define GPTIMER_GEN_EVENT1_MIS_F_OFS             (24)                            /* !< F Offset */
#define GPTIMER_GEN_EVENT1_MIS_F_MASK            ((uint32_t)0x01000000U)         /* !< Fault */
#define GPTIMER_GEN_EVENT1_MIS_F_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_F_SET             ((uint32_t)0x01000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[TOV] Bits */
#define GPTIMER_GEN_EVENT1_MIS_TOV_OFS           (25)                            /* !< TOV Offset */
#define GPTIMER_GEN_EVENT1_MIS_TOV_MASK          ((uint32_t)0x02000000U)         /* !< Trigger overflow */
#define GPTIMER_GEN_EVENT1_MIS_TOV_CLR           ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_TOV_SET           ((uint32_t)0x02000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[DC] Bits */
#define GPTIMER_GEN_EVENT1_MIS_DC_OFS            (27)                            /* !< DC Offset */
#define GPTIMER_GEN_EVENT1_MIS_DC_MASK           ((uint32_t)0x08000000U)         /* !< Direction Change */
#define GPTIMER_GEN_EVENT1_MIS_DC_CLR            ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_DC_SET            ((uint32_t)0x08000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[QEIERR] Bits */
#define GPTIMER_GEN_EVENT1_MIS_QEIERR_OFS        (28)                            /* !< QEIERR Offset */
#define GPTIMER_GEN_EVENT1_MIS_QEIERR_MASK       ((uint32_t)0x10000000U)         /* !< QEIERR */
#define GPTIMER_GEN_EVENT1_MIS_QEIERR_CLR        ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_QEIERR_SET        ((uint32_t)0x10000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCD2] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCD2_OFS          (6)                             /* !< CCD2 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCD2_MASK         ((uint32_t)0x00000040U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_GEN_EVENT1_MIS_CCD2_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCD2_SET          ((uint32_t)0x00000040U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCD3] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCD3_OFS          (7)                             /* !< CCD3 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCD3_MASK         ((uint32_t)0x00000080U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_GEN_EVENT1_MIS_CCD3_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCD3_SET          ((uint32_t)0x00000080U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCU2] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCU2_OFS          (10)                            /* !< CCU2 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCU2_MASK         ((uint32_t)0x00000400U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_GEN_EVENT1_MIS_CCU2_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCU2_SET          ((uint32_t)0x00000400U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCU3] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCU3_OFS          (11)                            /* !< CCU3 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCU3_MASK         ((uint32_t)0x00000800U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_GEN_EVENT1_MIS_CCU3_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCU3_SET          ((uint32_t)0x00000800U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCD4] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCD4_OFS          (12)                            /* !< CCD4 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCD4_MASK         ((uint32_t)0x00001000U)         /* !< Compare down event generated an
                                                                                    interrupt CCP4 */
#define GPTIMER_GEN_EVENT1_MIS_CCD4_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCD4_SET          ((uint32_t)0x00001000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCD5] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCD5_OFS          (13)                            /* !< CCD5 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCD5_MASK         ((uint32_t)0x00002000U)         /* !< Compare down event generated an
                                                                                    interrupt CCP5 */
#define GPTIMER_GEN_EVENT1_MIS_CCD5_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCD5_SET          ((uint32_t)0x00002000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCU4] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCU4_OFS          (14)                            /* !< CCU4 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCU4_MASK         ((uint32_t)0x00004000U)         /* !< Compare up event generated an
                                                                                    interrupt CCP4 */
#define GPTIMER_GEN_EVENT1_MIS_CCU4_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCU4_SET          ((uint32_t)0x00004000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[CCU5] Bits */
#define GPTIMER_GEN_EVENT1_MIS_CCU5_OFS          (15)                            /* !< CCU5 Offset */
#define GPTIMER_GEN_EVENT1_MIS_CCU5_MASK         ((uint32_t)0x00008000U)         /* !< Compare up event generated an
                                                                                    interrupt CCP5 */
#define GPTIMER_GEN_EVENT1_MIS_CCU5_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_CCU5_SET          ((uint32_t)0x00008000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_MIS[REPC] Bits */
#define GPTIMER_GEN_EVENT1_MIS_REPC_OFS          (26)                            /* !< REPC Offset */
#define GPTIMER_GEN_EVENT1_MIS_REPC_MASK         ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero */
#define GPTIMER_GEN_EVENT1_MIS_REPC_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT1_MIS_REPC_SET          ((uint32_t)0x04000000U)         /* !< Event Set */

/* GPTIMER_GEN_EVENT1_ISET Bits */
/* GPTIMER_GEN_EVENT1_ISET[Z] Bits */
#define GPTIMER_GEN_EVENT1_ISET_Z_OFS            (0)                             /* !< Z Offset */
#define GPTIMER_GEN_EVENT1_ISET_Z_MASK           ((uint32_t)0x00000001U)         /* !< Zero event SET */
#define GPTIMER_GEN_EVENT1_ISET_Z_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_Z_SET            ((uint32_t)0x00000001U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[L] Bits */
#define GPTIMER_GEN_EVENT1_ISET_L_OFS            (1)                             /* !< L Offset */
#define GPTIMER_GEN_EVENT1_ISET_L_MASK           ((uint32_t)0x00000002U)         /* !< Load event SET */
#define GPTIMER_GEN_EVENT1_ISET_L_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_L_SET            ((uint32_t)0x00000002U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCD0] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCD0_OFS         (4)                             /* !< CCD0 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCD0_MASK        ((uint32_t)0x00000010U)         /* !< Capture or compare down event SET */
#define GPTIMER_GEN_EVENT1_ISET_CCD0_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCD0_SET         ((uint32_t)0x00000010U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCD1] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCD1_OFS         (5)                             /* !< CCD1 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCD1_MASK        ((uint32_t)0x00000020U)         /* !< Capture or compare down event SET */
#define GPTIMER_GEN_EVENT1_ISET_CCD1_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCD1_SET         ((uint32_t)0x00000020U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCU0] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCU0_OFS         (8)                             /* !< CCU0 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCU0_MASK        ((uint32_t)0x00000100U)         /* !< Capture or compare up event SET */
#define GPTIMER_GEN_EVENT1_ISET_CCU0_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCU0_SET         ((uint32_t)0x00000100U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCU1] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCU1_OFS         (9)                             /* !< CCU1 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCU1_MASK        ((uint32_t)0x00000200U)         /* !< Capture or compare up event SET */
#define GPTIMER_GEN_EVENT1_ISET_CCU1_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCU1_SET         ((uint32_t)0x00000200U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[F] Bits */
#define GPTIMER_GEN_EVENT1_ISET_F_OFS            (24)                            /* !< F Offset */
#define GPTIMER_GEN_EVENT1_ISET_F_MASK           ((uint32_t)0x01000000U)         /* !< Fault event SET */
#define GPTIMER_GEN_EVENT1_ISET_F_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_F_SET            ((uint32_t)0x01000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[TOV] Bits */
#define GPTIMER_GEN_EVENT1_ISET_TOV_OFS          (25)                            /* !< TOV Offset */
#define GPTIMER_GEN_EVENT1_ISET_TOV_MASK         ((uint32_t)0x02000000U)         /* !< Trigger Overflow event SET */
#define GPTIMER_GEN_EVENT1_ISET_TOV_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_TOV_SET          ((uint32_t)0x02000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[DC] Bits */
#define GPTIMER_GEN_EVENT1_ISET_DC_OFS           (27)                            /* !< DC Offset */
#define GPTIMER_GEN_EVENT1_ISET_DC_MASK          ((uint32_t)0x08000000U)         /* !< Direction Change event SET */
#define GPTIMER_GEN_EVENT1_ISET_DC_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_DC_SET           ((uint32_t)0x08000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[QEIERR] Bits */
#define GPTIMER_GEN_EVENT1_ISET_QEIERR_OFS       (28)                            /* !< QEIERR Offset */
#define GPTIMER_GEN_EVENT1_ISET_QEIERR_MASK      ((uint32_t)0x10000000U)         /* !< QEIERR event SET */
#define GPTIMER_GEN_EVENT1_ISET_QEIERR_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_QEIERR_SET       ((uint32_t)0x10000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCD2] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCD2_OFS         (6)                             /* !< CCD2 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCD2_MASK        ((uint32_t)0x00000040U)         /* !< Capture or compare down event SET */
#define GPTIMER_GEN_EVENT1_ISET_CCD2_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCD2_SET         ((uint32_t)0x00000040U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCD3] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCD3_OFS         (7)                             /* !< CCD3 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCD3_MASK        ((uint32_t)0x00000080U)         /* !< Capture or compare down event SET */
#define GPTIMER_GEN_EVENT1_ISET_CCD3_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCD3_SET         ((uint32_t)0x00000080U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCU2] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCU2_OFS         (10)                            /* !< CCU2 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCU2_MASK        ((uint32_t)0x00000400U)         /* !< Capture or compare up event SET */
#define GPTIMER_GEN_EVENT1_ISET_CCU2_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCU2_SET         ((uint32_t)0x00000400U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCU3] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCU3_OFS         (11)                            /* !< CCU3 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCU3_MASK        ((uint32_t)0x00000800U)         /* !< Capture or compare up event SET */
#define GPTIMER_GEN_EVENT1_ISET_CCU3_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCU3_SET         ((uint32_t)0x00000800U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCD4] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCD4_OFS         (12)                            /* !< CCD4 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCD4_MASK        ((uint32_t)0x00001000U)         /* !< Compare down event 4 SET */
#define GPTIMER_GEN_EVENT1_ISET_CCD4_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCD4_SET         ((uint32_t)0x00001000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCD5] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCD5_OFS         (13)                            /* !< CCD5 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCD5_MASK        ((uint32_t)0x00002000U)         /* !< Compare down event 5 SET */
#define GPTIMER_GEN_EVENT1_ISET_CCD5_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCD5_SET         ((uint32_t)0x00002000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCU4] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCU4_OFS         (14)                            /* !< CCU4 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCU4_MASK        ((uint32_t)0x00004000U)         /* !< Compare up event 4 SET */
#define GPTIMER_GEN_EVENT1_ISET_CCU4_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCU4_SET         ((uint32_t)0x00004000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[CCU5] Bits */
#define GPTIMER_GEN_EVENT1_ISET_CCU5_OFS         (15)                            /* !< CCU5 Offset */
#define GPTIMER_GEN_EVENT1_ISET_CCU5_MASK        ((uint32_t)0x00008000U)         /* !< Compare up event 5 SET */
#define GPTIMER_GEN_EVENT1_ISET_CCU5_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_CCU5_SET         ((uint32_t)0x00008000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT1_ISET[REPC] Bits */
#define GPTIMER_GEN_EVENT1_ISET_REPC_OFS         (26)                            /* !< REPC Offset */
#define GPTIMER_GEN_EVENT1_ISET_REPC_MASK        ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero event SET */
#define GPTIMER_GEN_EVENT1_ISET_REPC_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ISET_REPC_SET         ((uint32_t)0x04000000U)         /* !< Event Set */

/* GPTIMER_GEN_EVENT1_ICLR Bits */
/* GPTIMER_GEN_EVENT1_ICLR[Z] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_Z_OFS            (0)                             /* !< Z Offset */
#define GPTIMER_GEN_EVENT1_ICLR_Z_MASK           ((uint32_t)0x00000001U)         /* !< Zero event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_Z_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_Z_CLR            ((uint32_t)0x00000001U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[L] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_L_OFS            (1)                             /* !< L Offset */
#define GPTIMER_GEN_EVENT1_ICLR_L_MASK           ((uint32_t)0x00000002U)         /* !< Load event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_L_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_L_CLR            ((uint32_t)0x00000002U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCD0] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCD0_OFS         (4)                             /* !< CCD0 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCD0_MASK        ((uint32_t)0x00000010U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCD0_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCD0_CLR         ((uint32_t)0x00000010U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCD1] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCD1_OFS         (5)                             /* !< CCD1 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCD1_MASK        ((uint32_t)0x00000020U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCD1_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCD1_CLR         ((uint32_t)0x00000020U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCU0] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCU0_OFS         (8)                             /* !< CCU0 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCU0_MASK        ((uint32_t)0x00000100U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCU0_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCU0_CLR         ((uint32_t)0x00000100U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCU1] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCU1_OFS         (9)                             /* !< CCU1 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCU1_MASK        ((uint32_t)0x00000200U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCU1_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCU1_CLR         ((uint32_t)0x00000200U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[F] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_F_OFS            (24)                            /* !< F Offset */
#define GPTIMER_GEN_EVENT1_ICLR_F_MASK           ((uint32_t)0x01000000U)         /* !< Fault event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_F_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_F_CLR            ((uint32_t)0x01000000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[TOV] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_TOV_OFS          (25)                            /* !< TOV Offset */
#define GPTIMER_GEN_EVENT1_ICLR_TOV_MASK         ((uint32_t)0x02000000U)         /* !< Trigger Overflow event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_TOV_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_TOV_CLR          ((uint32_t)0x02000000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[DC] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_DC_OFS           (27)                            /* !< DC Offset */
#define GPTIMER_GEN_EVENT1_ICLR_DC_MASK          ((uint32_t)0x08000000U)         /* !< Direction Change event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_DC_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_DC_CLR           ((uint32_t)0x08000000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[QEIERR] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_QEIERR_OFS       (28)                            /* !< QEIERR Offset */
#define GPTIMER_GEN_EVENT1_ICLR_QEIERR_MASK      ((uint32_t)0x10000000U)         /* !< QEIERR event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_QEIERR_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_QEIERR_CLR       ((uint32_t)0x10000000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCD2] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCD2_OFS         (6)                             /* !< CCD2 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCD2_MASK        ((uint32_t)0x00000040U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCD2_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCD2_CLR         ((uint32_t)0x00000040U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCD3] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCD3_OFS         (7)                             /* !< CCD3 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCD3_MASK        ((uint32_t)0x00000080U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCD3_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCD3_CLR         ((uint32_t)0x00000080U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCU2] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCU2_OFS         (10)                            /* !< CCU2 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCU2_MASK        ((uint32_t)0x00000400U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCU2_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCU2_CLR         ((uint32_t)0x00000400U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCU3] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCU3_OFS         (11)                            /* !< CCU3 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCU3_MASK        ((uint32_t)0x00000800U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCU3_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCU3_CLR         ((uint32_t)0x00000800U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCD4] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCD4_OFS         (12)                            /* !< CCD4 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCD4_MASK        ((uint32_t)0x00001000U)         /* !< Compare down event 4 CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCD4_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCD4_CLR         ((uint32_t)0x00001000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCD5] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCD5_OFS         (13)                            /* !< CCD5 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCD5_MASK        ((uint32_t)0x00002000U)         /* !< Compare down event 5 CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCD5_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCD5_CLR         ((uint32_t)0x00002000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCU4] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCU4_OFS         (14)                            /* !< CCU4 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCU4_MASK        ((uint32_t)0x00004000U)         /* !< Compare up event 4 CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCU4_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCU4_CLR         ((uint32_t)0x00004000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[CCU5] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_CCU5_OFS         (15)                            /* !< CCU5 Offset */
#define GPTIMER_GEN_EVENT1_ICLR_CCU5_MASK        ((uint32_t)0x00008000U)         /* !< Compare up event 5 CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_CCU5_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_CCU5_CLR         ((uint32_t)0x00008000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT1_ICLR[REPC] Bits */
#define GPTIMER_GEN_EVENT1_ICLR_REPC_OFS         (26)                            /* !< REPC Offset */
#define GPTIMER_GEN_EVENT1_ICLR_REPC_MASK        ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero event CLEAR */
#define GPTIMER_GEN_EVENT1_ICLR_REPC_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT1_ICLR_REPC_CLR         ((uint32_t)0x04000000U)         /* !< Event Clear */

/* GPTIMER_GEN_EVENT0_IIDX Bits */
/* GPTIMER_GEN_EVENT0_IIDX[STAT] Bits */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_OFS         (0)                             /* !< STAT Offset */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_MASK        ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_NO_INTR     ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_Z           ((uint32_t)0x00000001U)         /* !< Interrupt Source: Zero event (Z) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_L           ((uint32_t)0x00000002U)         /* !< nterrupt Source: Load event (L) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCD0        ((uint32_t)0x00000005U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD0) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCD1        ((uint32_t)0x00000006U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD1) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCD2        ((uint32_t)0x00000007U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD2) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCD3        ((uint32_t)0x00000008U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD3) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCU0        ((uint32_t)0x00000009U)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU0) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCU1        ((uint32_t)0x0000000AU)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU1) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCU2        ((uint32_t)0x0000000BU)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU2) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCU3        ((uint32_t)0x0000000CU)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU3) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCD4        ((uint32_t)0x0000000DU)         /* !< Interrupt Source: Compare down
                                                                                    event (CCD4) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCD5        ((uint32_t)0x0000000EU)         /* !< Interrupt Source: Compare down
                                                                                    event (CCD5) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCU4        ((uint32_t)0x0000000FU)         /* !< Interrupt Source: Compare down
                                                                                    event (CCU4) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_CCU5        ((uint32_t)0x00000010U)         /* !< Interrupt Source: Compare down
                                                                                    event (CCU5) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_F           ((uint32_t)0x00000019U)         /* !< Interrupt Source: Fault Event
                                                                                    generated an interrupt. (F) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_TOV         ((uint32_t)0x0000001AU)         /* !< Interrupt Source: Trigger overflow
                                                                                    (TOV) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_REPC        ((uint32_t)0x0000001BU)         /* !< Interrupt Source: Repeat Counter
                                                                                    Zero (REPC) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_DC          ((uint32_t)0x0000001CU)         /* !< Interrupt Source: Direction Change
                                                                                    (DC) */
#define GPTIMER_GEN_EVENT0_IIDX_STAT_QEIERR      ((uint32_t)0x0000001DU)         /* !< Interrupt Source:QEI Incorrect
                                                                                    state transition error (QEIERR) */

/* GPTIMER_GEN_EVENT0_IMASK Bits */
/* GPTIMER_GEN_EVENT0_IMASK[Z] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_Z_OFS           (0)                             /* !< Z Offset */
#define GPTIMER_GEN_EVENT0_IMASK_Z_MASK          ((uint32_t)0x00000001U)         /* !< Zero Event mask */
#define GPTIMER_GEN_EVENT0_IMASK_Z_CLR           ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT0_IMASK_Z_SET           ((uint32_t)0x00000001U)         /* !< Enable Event */
/* GPTIMER_GEN_EVENT0_IMASK[L] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_L_OFS           (1)                             /* !< L Offset */
#define GPTIMER_GEN_EVENT0_IMASK_L_MASK          ((uint32_t)0x00000002U)         /* !< Load Event mask */
#define GPTIMER_GEN_EVENT0_IMASK_L_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_L_SET           ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[CCD0] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCD0_OFS        (4)                             /* !< CCD0 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCD0_MASK       ((uint32_t)0x00000010U)         /* !< Capture or Compare DN event mask
                                                                                    CCP0 */
#define GPTIMER_GEN_EVENT0_IMASK_CCD0_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCD0_SET        ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[CCD1] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCD1_OFS        (5)                             /* !< CCD1 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCD1_MASK       ((uint32_t)0x00000020U)         /* !< Capture or Compare DN event mask
                                                                                    CCP1 */
#define GPTIMER_GEN_EVENT0_IMASK_CCD1_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCD1_SET        ((uint32_t)0x00000020U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[CCU0] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCU0_OFS        (8)                             /* !< CCU0 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCU0_MASK       ((uint32_t)0x00000100U)         /* !< Capture or Compare UP event mask
                                                                                    CCP0 */
#define GPTIMER_GEN_EVENT0_IMASK_CCU0_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCU0_SET        ((uint32_t)0x00000100U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[CCU1] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCU1_OFS        (9)                             /* !< CCU1 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCU1_MASK       ((uint32_t)0x00000200U)         /* !< Capture or Compare UP event mask
                                                                                    CCP1 */
#define GPTIMER_GEN_EVENT0_IMASK_CCU1_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCU1_SET        ((uint32_t)0x00000200U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[F] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_F_OFS           (24)                            /* !< F Offset */
#define GPTIMER_GEN_EVENT0_IMASK_F_MASK          ((uint32_t)0x01000000U)         /* !< Fault Event mask */
#define GPTIMER_GEN_EVENT0_IMASK_F_CLR           ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT0_IMASK_F_SET           ((uint32_t)0x01000000U)         /* !< Enable Event */
/* GPTIMER_GEN_EVENT0_IMASK[TOV] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_TOV_OFS         (25)                            /* !< TOV Offset */
#define GPTIMER_GEN_EVENT0_IMASK_TOV_MASK        ((uint32_t)0x02000000U)         /* !< Trigger Overflow Event mask */
#define GPTIMER_GEN_EVENT0_IMASK_TOV_CLR         ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT0_IMASK_TOV_SET         ((uint32_t)0x02000000U)         /* !< Enable Event */
/* GPTIMER_GEN_EVENT0_IMASK[DC] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_DC_OFS          (27)                            /* !< DC Offset */
#define GPTIMER_GEN_EVENT0_IMASK_DC_MASK         ((uint32_t)0x08000000U)         /* !< Direction Change Event mask */
#define GPTIMER_GEN_EVENT0_IMASK_DC_CLR          ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT0_IMASK_DC_SET          ((uint32_t)0x08000000U)         /* !< Enable Event */
/* GPTIMER_GEN_EVENT0_IMASK[QEIERR] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_QEIERR_OFS      (28)                            /* !< QEIERR Offset */
#define GPTIMER_GEN_EVENT0_IMASK_QEIERR_MASK     ((uint32_t)0x10000000U)         /* !< QEIERR Event mask */
#define GPTIMER_GEN_EVENT0_IMASK_QEIERR_CLR      ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT0_IMASK_QEIERR_SET      ((uint32_t)0x10000000U)         /* !< Enable Event */
/* GPTIMER_GEN_EVENT0_IMASK[CCD2] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCD2_OFS        (6)                             /* !< CCD2 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCD2_MASK       ((uint32_t)0x00000040U)         /* !< Capture or Compare DN event mask
                                                                                    CCP2 */
#define GPTIMER_GEN_EVENT0_IMASK_CCD2_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCD2_SET        ((uint32_t)0x00000040U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[CCD3] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCD3_OFS        (7)                             /* !< CCD3 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCD3_MASK       ((uint32_t)0x00000080U)         /* !< Capture or Compare DN event mask
                                                                                    CCP3 */
#define GPTIMER_GEN_EVENT0_IMASK_CCD3_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCD3_SET        ((uint32_t)0x00000080U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[CCU2] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCU2_OFS        (10)                            /* !< CCU2 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCU2_MASK       ((uint32_t)0x00000400U)         /* !< Capture or Compare UP event mask
                                                                                    CCP2 */
#define GPTIMER_GEN_EVENT0_IMASK_CCU2_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCU2_SET        ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[CCU3] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCU3_OFS        (11)                            /* !< CCU3 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCU3_MASK       ((uint32_t)0x00000800U)         /* !< Capture or Compare UP event mask
                                                                                    CCP3 */
#define GPTIMER_GEN_EVENT0_IMASK_CCU3_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCU3_SET        ((uint32_t)0x00000800U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[CCD4] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCD4_OFS        (12)                            /* !< CCD4 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCD4_MASK       ((uint32_t)0x00001000U)         /* !< Compare DN event mask CCP4 */
#define GPTIMER_GEN_EVENT0_IMASK_CCD4_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCD4_SET        ((uint32_t)0x00001000U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[CCD5] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCD5_OFS        (13)                            /* !< CCD5 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCD5_MASK       ((uint32_t)0x00002000U)         /* !< Compare DN event mask CCP5 */
#define GPTIMER_GEN_EVENT0_IMASK_CCD5_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCD5_SET        ((uint32_t)0x00002000U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[CCU4] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCU4_OFS        (14)                            /* !< CCU4 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCU4_MASK       ((uint32_t)0x00004000U)         /* !< Compare UP event mask CCP4 */
#define GPTIMER_GEN_EVENT0_IMASK_CCU4_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCU4_SET        ((uint32_t)0x00004000U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[CCU5] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_CCU5_OFS        (15)                            /* !< CCU5 Offset */
#define GPTIMER_GEN_EVENT0_IMASK_CCU5_MASK       ((uint32_t)0x00008000U)         /* !< Compare UP event mask CCP5 */
#define GPTIMER_GEN_EVENT0_IMASK_CCU5_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_GEN_EVENT0_IMASK_CCU5_SET        ((uint32_t)0x00008000U)         /* !< Set Interrupt Mask */
/* GPTIMER_GEN_EVENT0_IMASK[REPC] Bits */
#define GPTIMER_GEN_EVENT0_IMASK_REPC_OFS        (26)                            /* !< REPC Offset */
#define GPTIMER_GEN_EVENT0_IMASK_REPC_MASK       ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero Event mask */
#define GPTIMER_GEN_EVENT0_IMASK_REPC_CLR        ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_GEN_EVENT0_IMASK_REPC_SET        ((uint32_t)0x04000000U)         /* !< Enable Event */

/* GPTIMER_GEN_EVENT0_RIS Bits */
/* GPTIMER_GEN_EVENT0_RIS[Z] Bits */
#define GPTIMER_GEN_EVENT0_RIS_Z_OFS             (0)                             /* !< Z Offset */
#define GPTIMER_GEN_EVENT0_RIS_Z_MASK            ((uint32_t)0x00000001U)         /* !< Zero event generated an interrupt. */
#define GPTIMER_GEN_EVENT0_RIS_Z_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_Z_SET             ((uint32_t)0x00000001U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[L] Bits */
#define GPTIMER_GEN_EVENT0_RIS_L_OFS             (1)                             /* !< L Offset */
#define GPTIMER_GEN_EVENT0_RIS_L_MASK            ((uint32_t)0x00000002U)         /* !< Load event generated an interrupt. */
#define GPTIMER_GEN_EVENT0_RIS_L_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_L_SET             ((uint32_t)0x00000002U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCD0] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCD0_OFS          (4)                             /* !< CCD0 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCD0_MASK         ((uint32_t)0x00000010U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_GEN_EVENT0_RIS_CCD0_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCD0_SET          ((uint32_t)0x00000010U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCD1] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCD1_OFS          (5)                             /* !< CCD1 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCD1_MASK         ((uint32_t)0x00000020U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_GEN_EVENT0_RIS_CCD1_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCD1_SET          ((uint32_t)0x00000020U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCU0] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCU0_OFS          (8)                             /* !< CCU0 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCU0_MASK         ((uint32_t)0x00000100U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_GEN_EVENT0_RIS_CCU0_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCU0_SET          ((uint32_t)0x00000100U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCU1] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCU1_OFS          (9)                             /* !< CCU1 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCU1_MASK         ((uint32_t)0x00000200U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_GEN_EVENT0_RIS_CCU1_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCU1_SET          ((uint32_t)0x00000200U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[TOV] Bits */
#define GPTIMER_GEN_EVENT0_RIS_TOV_OFS           (25)                            /* !< TOV Offset */
#define GPTIMER_GEN_EVENT0_RIS_TOV_MASK          ((uint32_t)0x02000000U)         /* !< Trigger overflow */
#define GPTIMER_GEN_EVENT0_RIS_TOV_CLR           ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_TOV_SET           ((uint32_t)0x02000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[F] Bits */
#define GPTIMER_GEN_EVENT0_RIS_F_OFS             (24)                            /* !< F Offset */
#define GPTIMER_GEN_EVENT0_RIS_F_MASK            ((uint32_t)0x01000000U)         /* !< Fault */
#define GPTIMER_GEN_EVENT0_RIS_F_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_F_SET             ((uint32_t)0x01000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[DC] Bits */
#define GPTIMER_GEN_EVENT0_RIS_DC_OFS            (27)                            /* !< DC Offset */
#define GPTIMER_GEN_EVENT0_RIS_DC_MASK           ((uint32_t)0x08000000U)         /* !< Direction Change */
#define GPTIMER_GEN_EVENT0_RIS_DC_CLR            ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_DC_SET            ((uint32_t)0x08000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[QEIERR] Bits */
#define GPTIMER_GEN_EVENT0_RIS_QEIERR_OFS        (28)                            /* !< QEIERR Offset */
#define GPTIMER_GEN_EVENT0_RIS_QEIERR_MASK       ((uint32_t)0x10000000U)         /* !< QEIERR, set on an incorrect state
                                                                                    transition on the encoder interface. */
#define GPTIMER_GEN_EVENT0_RIS_QEIERR_CLR        ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_QEIERR_SET        ((uint32_t)0x10000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCD2] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCD2_OFS          (6)                             /* !< CCD2 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCD2_MASK         ((uint32_t)0x00000040U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_GEN_EVENT0_RIS_CCD2_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCD2_SET          ((uint32_t)0x00000040U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCD3] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCD3_OFS          (7)                             /* !< CCD3 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCD3_MASK         ((uint32_t)0x00000080U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_GEN_EVENT0_RIS_CCD3_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCD3_SET          ((uint32_t)0x00000080U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCU2] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCU2_OFS          (10)                            /* !< CCU2 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCU2_MASK         ((uint32_t)0x00000400U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_GEN_EVENT0_RIS_CCU2_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCU2_SET          ((uint32_t)0x00000400U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCU3] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCU3_OFS          (11)                            /* !< CCU3 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCU3_MASK         ((uint32_t)0x00000800U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_GEN_EVENT0_RIS_CCU3_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCU3_SET          ((uint32_t)0x00000800U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCD4] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCD4_OFS          (12)                            /* !< CCD4 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCD4_MASK         ((uint32_t)0x00001000U)         /* !< Compare down event generated an
                                                                                    interrupt CCD4 */
#define GPTIMER_GEN_EVENT0_RIS_CCD4_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCD4_SET          ((uint32_t)0x00001000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCD5] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCD5_OFS          (13)                            /* !< CCD5 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCD5_MASK         ((uint32_t)0x00002000U)         /* !< Compare down event generated an
                                                                                    interrupt CCD5 */
#define GPTIMER_GEN_EVENT0_RIS_CCD5_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCD5_SET          ((uint32_t)0x00002000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCU4] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCU4_OFS          (14)                            /* !< CCU4 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCU4_MASK         ((uint32_t)0x00004000U)         /* !< Compare up event generated an
                                                                                    interrupt CCU4 */
#define GPTIMER_GEN_EVENT0_RIS_CCU4_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCU4_SET          ((uint32_t)0x00004000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[CCU5] Bits */
#define GPTIMER_GEN_EVENT0_RIS_CCU5_OFS          (15)                            /* !< CCU5 Offset */
#define GPTIMER_GEN_EVENT0_RIS_CCU5_MASK         ((uint32_t)0x00008000U)         /* !< Compare up event generated an
                                                                                    interrupt CCP5 */
#define GPTIMER_GEN_EVENT0_RIS_CCU5_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_CCU5_SET          ((uint32_t)0x00008000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_RIS[REPC] Bits */
#define GPTIMER_GEN_EVENT0_RIS_REPC_OFS          (26)                            /* !< REPC Offset */
#define GPTIMER_GEN_EVENT0_RIS_REPC_MASK         ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero */
#define GPTIMER_GEN_EVENT0_RIS_REPC_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_RIS_REPC_SET          ((uint32_t)0x04000000U)         /* !< Event Set */

/* GPTIMER_GEN_EVENT0_MIS Bits */
/* GPTIMER_GEN_EVENT0_MIS[Z] Bits */
#define GPTIMER_GEN_EVENT0_MIS_Z_OFS             (0)                             /* !< Z Offset */
#define GPTIMER_GEN_EVENT0_MIS_Z_MASK            ((uint32_t)0x00000001U)         /* !< Zero event generated an interrupt. */
#define GPTIMER_GEN_EVENT0_MIS_Z_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_Z_SET             ((uint32_t)0x00000001U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[L] Bits */
#define GPTIMER_GEN_EVENT0_MIS_L_OFS             (1)                             /* !< L Offset */
#define GPTIMER_GEN_EVENT0_MIS_L_MASK            ((uint32_t)0x00000002U)         /* !< Load event generated an interrupt. */
#define GPTIMER_GEN_EVENT0_MIS_L_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_L_SET             ((uint32_t)0x00000002U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCD0] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCD0_OFS          (4)                             /* !< CCD0 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCD0_MASK         ((uint32_t)0x00000010U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_GEN_EVENT0_MIS_CCD0_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCD0_SET          ((uint32_t)0x00000010U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCD1] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCD1_OFS          (5)                             /* !< CCD1 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCD1_MASK         ((uint32_t)0x00000020U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_GEN_EVENT0_MIS_CCD1_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCD1_SET          ((uint32_t)0x00000020U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCU0] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCU0_OFS          (8)                             /* !< CCU0 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCU0_MASK         ((uint32_t)0x00000100U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_GEN_EVENT0_MIS_CCU0_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCU0_SET          ((uint32_t)0x00000100U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCU1] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCU1_OFS          (9)                             /* !< CCU1 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCU1_MASK         ((uint32_t)0x00000200U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_GEN_EVENT0_MIS_CCU1_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCU1_SET          ((uint32_t)0x00000200U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[F] Bits */
#define GPTIMER_GEN_EVENT0_MIS_F_OFS             (24)                            /* !< F Offset */
#define GPTIMER_GEN_EVENT0_MIS_F_MASK            ((uint32_t)0x01000000U)         /* !< Fault */
#define GPTIMER_GEN_EVENT0_MIS_F_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_F_SET             ((uint32_t)0x01000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[TOV] Bits */
#define GPTIMER_GEN_EVENT0_MIS_TOV_OFS           (25)                            /* !< TOV Offset */
#define GPTIMER_GEN_EVENT0_MIS_TOV_MASK          ((uint32_t)0x02000000U)         /* !< Trigger overflow */
#define GPTIMER_GEN_EVENT0_MIS_TOV_CLR           ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_TOV_SET           ((uint32_t)0x02000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[DC] Bits */
#define GPTIMER_GEN_EVENT0_MIS_DC_OFS            (27)                            /* !< DC Offset */
#define GPTIMER_GEN_EVENT0_MIS_DC_MASK           ((uint32_t)0x08000000U)         /* !< Direction Change */
#define GPTIMER_GEN_EVENT0_MIS_DC_CLR            ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_DC_SET            ((uint32_t)0x08000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[QEIERR] Bits */
#define GPTIMER_GEN_EVENT0_MIS_QEIERR_OFS        (28)                            /* !< QEIERR Offset */
#define GPTIMER_GEN_EVENT0_MIS_QEIERR_MASK       ((uint32_t)0x10000000U)         /* !< QEIERR */
#define GPTIMER_GEN_EVENT0_MIS_QEIERR_CLR        ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_QEIERR_SET        ((uint32_t)0x10000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCD2] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCD2_OFS          (6)                             /* !< CCD2 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCD2_MASK         ((uint32_t)0x00000040U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_GEN_EVENT0_MIS_CCD2_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCD2_SET          ((uint32_t)0x00000040U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCD3] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCD3_OFS          (7)                             /* !< CCD3 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCD3_MASK         ((uint32_t)0x00000080U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_GEN_EVENT0_MIS_CCD3_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCD3_SET          ((uint32_t)0x00000080U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCU2] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCU2_OFS          (10)                            /* !< CCU2 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCU2_MASK         ((uint32_t)0x00000400U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_GEN_EVENT0_MIS_CCU2_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCU2_SET          ((uint32_t)0x00000400U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCU3] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCU3_OFS          (11)                            /* !< CCU3 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCU3_MASK         ((uint32_t)0x00000800U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_GEN_EVENT0_MIS_CCU3_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCU3_SET          ((uint32_t)0x00000800U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCD4] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCD4_OFS          (12)                            /* !< CCD4 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCD4_MASK         ((uint32_t)0x00001000U)         /* !< Compare down event generated an
                                                                                    interrupt CCP4 */
#define GPTIMER_GEN_EVENT0_MIS_CCD4_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCD4_SET          ((uint32_t)0x00001000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCD5] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCD5_OFS          (13)                            /* !< CCD5 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCD5_MASK         ((uint32_t)0x00002000U)         /* !< Compare down event generated an
                                                                                    interrupt CCP5 */
#define GPTIMER_GEN_EVENT0_MIS_CCD5_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCD5_SET          ((uint32_t)0x00002000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCU4] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCU4_OFS          (14)                            /* !< CCU4 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCU4_MASK         ((uint32_t)0x00004000U)         /* !< Compare up event generated an
                                                                                    interrupt CCP4 */
#define GPTIMER_GEN_EVENT0_MIS_CCU4_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCU4_SET          ((uint32_t)0x00004000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[CCU5] Bits */
#define GPTIMER_GEN_EVENT0_MIS_CCU5_OFS          (15)                            /* !< CCU5 Offset */
#define GPTIMER_GEN_EVENT0_MIS_CCU5_MASK         ((uint32_t)0x00008000U)         /* !< Compare up event generated an
                                                                                    interrupt CCP5 */
#define GPTIMER_GEN_EVENT0_MIS_CCU5_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_CCU5_SET          ((uint32_t)0x00008000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_MIS[REPC] Bits */
#define GPTIMER_GEN_EVENT0_MIS_REPC_OFS          (26)                            /* !< REPC Offset */
#define GPTIMER_GEN_EVENT0_MIS_REPC_MASK         ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero */
#define GPTIMER_GEN_EVENT0_MIS_REPC_CLR          ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_GEN_EVENT0_MIS_REPC_SET          ((uint32_t)0x04000000U)         /* !< Event Set */

/* GPTIMER_GEN_EVENT0_ISET Bits */
/* GPTIMER_GEN_EVENT0_ISET[Z] Bits */
#define GPTIMER_GEN_EVENT0_ISET_Z_OFS            (0)                             /* !< Z Offset */
#define GPTIMER_GEN_EVENT0_ISET_Z_MASK           ((uint32_t)0x00000001U)         /* !< Zero event SET */
#define GPTIMER_GEN_EVENT0_ISET_Z_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_Z_SET            ((uint32_t)0x00000001U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[L] Bits */
#define GPTIMER_GEN_EVENT0_ISET_L_OFS            (1)                             /* !< L Offset */
#define GPTIMER_GEN_EVENT0_ISET_L_MASK           ((uint32_t)0x00000002U)         /* !< Load event SET */
#define GPTIMER_GEN_EVENT0_ISET_L_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_L_SET            ((uint32_t)0x00000002U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCD0] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCD0_OFS         (4)                             /* !< CCD0 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCD0_MASK        ((uint32_t)0x00000010U)         /* !< Capture or compare down event SET */
#define GPTIMER_GEN_EVENT0_ISET_CCD0_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCD0_SET         ((uint32_t)0x00000010U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCD1] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCD1_OFS         (5)                             /* !< CCD1 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCD1_MASK        ((uint32_t)0x00000020U)         /* !< Capture or compare down event SET */
#define GPTIMER_GEN_EVENT0_ISET_CCD1_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCD1_SET         ((uint32_t)0x00000020U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCU0] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCU0_OFS         (8)                             /* !< CCU0 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCU0_MASK        ((uint32_t)0x00000100U)         /* !< Capture or compare up event SET */
#define GPTIMER_GEN_EVENT0_ISET_CCU0_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCU0_SET         ((uint32_t)0x00000100U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCU1] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCU1_OFS         (9)                             /* !< CCU1 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCU1_MASK        ((uint32_t)0x00000200U)         /* !< Capture or compare up event SET */
#define GPTIMER_GEN_EVENT0_ISET_CCU1_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCU1_SET         ((uint32_t)0x00000200U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[F] Bits */
#define GPTIMER_GEN_EVENT0_ISET_F_OFS            (24)                            /* !< F Offset */
#define GPTIMER_GEN_EVENT0_ISET_F_MASK           ((uint32_t)0x01000000U)         /* !< Fault event SET */
#define GPTIMER_GEN_EVENT0_ISET_F_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_F_SET            ((uint32_t)0x01000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[TOV] Bits */
#define GPTIMER_GEN_EVENT0_ISET_TOV_OFS          (25)                            /* !< TOV Offset */
#define GPTIMER_GEN_EVENT0_ISET_TOV_MASK         ((uint32_t)0x02000000U)         /* !< Trigger Overflow event SET */
#define GPTIMER_GEN_EVENT0_ISET_TOV_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_TOV_SET          ((uint32_t)0x02000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[DC] Bits */
#define GPTIMER_GEN_EVENT0_ISET_DC_OFS           (27)                            /* !< DC Offset */
#define GPTIMER_GEN_EVENT0_ISET_DC_MASK          ((uint32_t)0x08000000U)         /* !< Direction Change event SET */
#define GPTIMER_GEN_EVENT0_ISET_DC_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_DC_SET           ((uint32_t)0x08000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[QEIERR] Bits */
#define GPTIMER_GEN_EVENT0_ISET_QEIERR_OFS       (28)                            /* !< QEIERR Offset */
#define GPTIMER_GEN_EVENT0_ISET_QEIERR_MASK      ((uint32_t)0x10000000U)         /* !< QEIERR event SET */
#define GPTIMER_GEN_EVENT0_ISET_QEIERR_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_QEIERR_SET       ((uint32_t)0x10000000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCD2] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCD2_OFS         (6)                             /* !< CCD2 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCD2_MASK        ((uint32_t)0x00000040U)         /* !< Capture or compare down event SET */
#define GPTIMER_GEN_EVENT0_ISET_CCD2_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCD2_SET         ((uint32_t)0x00000040U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCD3] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCD3_OFS         (7)                             /* !< CCD3 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCD3_MASK        ((uint32_t)0x00000080U)         /* !< Capture or compare down event SET */
#define GPTIMER_GEN_EVENT0_ISET_CCD3_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCD3_SET         ((uint32_t)0x00000080U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCU2] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCU2_OFS         (10)                            /* !< CCU2 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCU2_MASK        ((uint32_t)0x00000400U)         /* !< Capture or compare up event SET */
#define GPTIMER_GEN_EVENT0_ISET_CCU2_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCU2_SET         ((uint32_t)0x00000400U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCU3] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCU3_OFS         (11)                            /* !< CCU3 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCU3_MASK        ((uint32_t)0x00000800U)         /* !< Capture or compare up event SET */
#define GPTIMER_GEN_EVENT0_ISET_CCU3_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCU3_SET         ((uint32_t)0x00000800U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCD4] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCD4_OFS         (12)                            /* !< CCD4 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCD4_MASK        ((uint32_t)0x00001000U)         /* !< Compare down event 4 SET */
#define GPTIMER_GEN_EVENT0_ISET_CCD4_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCD4_SET         ((uint32_t)0x00001000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCD5] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCD5_OFS         (13)                            /* !< CCD5 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCD5_MASK        ((uint32_t)0x00002000U)         /* !< Compare down event 5 SET */
#define GPTIMER_GEN_EVENT0_ISET_CCD5_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCD5_SET         ((uint32_t)0x00002000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCU4] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCU4_OFS         (14)                            /* !< CCU4 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCU4_MASK        ((uint32_t)0x00004000U)         /* !< Compare up event 4 SET */
#define GPTIMER_GEN_EVENT0_ISET_CCU4_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCU4_SET         ((uint32_t)0x00004000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[CCU5] Bits */
#define GPTIMER_GEN_EVENT0_ISET_CCU5_OFS         (15)                            /* !< CCU5 Offset */
#define GPTIMER_GEN_EVENT0_ISET_CCU5_MASK        ((uint32_t)0x00008000U)         /* !< Compare up event 5 SET */
#define GPTIMER_GEN_EVENT0_ISET_CCU5_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_CCU5_SET         ((uint32_t)0x00008000U)         /* !< Event Set */
/* GPTIMER_GEN_EVENT0_ISET[REPC] Bits */
#define GPTIMER_GEN_EVENT0_ISET_REPC_OFS         (26)                            /* !< REPC Offset */
#define GPTIMER_GEN_EVENT0_ISET_REPC_MASK        ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero event SET */
#define GPTIMER_GEN_EVENT0_ISET_REPC_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ISET_REPC_SET         ((uint32_t)0x04000000U)         /* !< Event Set */

/* GPTIMER_GEN_EVENT0_ICLR Bits */
/* GPTIMER_GEN_EVENT0_ICLR[Z] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_Z_OFS            (0)                             /* !< Z Offset */
#define GPTIMER_GEN_EVENT0_ICLR_Z_MASK           ((uint32_t)0x00000001U)         /* !< Zero event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_Z_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_Z_CLR            ((uint32_t)0x00000001U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[L] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_L_OFS            (1)                             /* !< L Offset */
#define GPTIMER_GEN_EVENT0_ICLR_L_MASK           ((uint32_t)0x00000002U)         /* !< Load event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_L_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_L_CLR            ((uint32_t)0x00000002U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCD0] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCD0_OFS         (4)                             /* !< CCD0 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCD0_MASK        ((uint32_t)0x00000010U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCD0_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCD0_CLR         ((uint32_t)0x00000010U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCD1] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCD1_OFS         (5)                             /* !< CCD1 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCD1_MASK        ((uint32_t)0x00000020U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCD1_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCD1_CLR         ((uint32_t)0x00000020U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCU0] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCU0_OFS         (8)                             /* !< CCU0 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCU0_MASK        ((uint32_t)0x00000100U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCU0_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCU0_CLR         ((uint32_t)0x00000100U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCU1] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCU1_OFS         (9)                             /* !< CCU1 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCU1_MASK        ((uint32_t)0x00000200U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCU1_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCU1_CLR         ((uint32_t)0x00000200U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[F] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_F_OFS            (24)                            /* !< F Offset */
#define GPTIMER_GEN_EVENT0_ICLR_F_MASK           ((uint32_t)0x01000000U)         /* !< Fault event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_F_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_F_CLR            ((uint32_t)0x01000000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[TOV] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_TOV_OFS          (25)                            /* !< TOV Offset */
#define GPTIMER_GEN_EVENT0_ICLR_TOV_MASK         ((uint32_t)0x02000000U)         /* !< Trigger Overflow event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_TOV_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_TOV_CLR          ((uint32_t)0x02000000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[DC] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_DC_OFS           (27)                            /* !< DC Offset */
#define GPTIMER_GEN_EVENT0_ICLR_DC_MASK          ((uint32_t)0x08000000U)         /* !< Direction Change event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_DC_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_DC_CLR           ((uint32_t)0x08000000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[QEIERR] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_QEIERR_OFS       (28)                            /* !< QEIERR Offset */
#define GPTIMER_GEN_EVENT0_ICLR_QEIERR_MASK      ((uint32_t)0x10000000U)         /* !< QEIERR event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_QEIERR_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_QEIERR_CLR       ((uint32_t)0x10000000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCD2] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCD2_OFS         (6)                             /* !< CCD2 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCD2_MASK        ((uint32_t)0x00000040U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCD2_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCD2_CLR         ((uint32_t)0x00000040U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCD3] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCD3_OFS         (7)                             /* !< CCD3 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCD3_MASK        ((uint32_t)0x00000080U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCD3_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCD3_CLR         ((uint32_t)0x00000080U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCU2] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCU2_OFS         (10)                            /* !< CCU2 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCU2_MASK        ((uint32_t)0x00000400U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCU2_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCU2_CLR         ((uint32_t)0x00000400U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCU3] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCU3_OFS         (11)                            /* !< CCU3 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCU3_MASK        ((uint32_t)0x00000800U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCU3_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCU3_CLR         ((uint32_t)0x00000800U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCD4] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCD4_OFS         (12)                            /* !< CCD4 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCD4_MASK        ((uint32_t)0x00001000U)         /* !< Compare down event 4 CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCD4_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCD4_CLR         ((uint32_t)0x00001000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCD5] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCD5_OFS         (13)                            /* !< CCD5 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCD5_MASK        ((uint32_t)0x00002000U)         /* !< Compare down event 5 CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCD5_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCD5_CLR         ((uint32_t)0x00002000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCU4] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCU4_OFS         (14)                            /* !< CCU4 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCU4_MASK        ((uint32_t)0x00004000U)         /* !< Compare up event 4 CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCU4_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCU4_CLR         ((uint32_t)0x00004000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[CCU5] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_CCU5_OFS         (15)                            /* !< CCU5 Offset */
#define GPTIMER_GEN_EVENT0_ICLR_CCU5_MASK        ((uint32_t)0x00008000U)         /* !< Compare up event 5 CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_CCU5_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_CCU5_CLR         ((uint32_t)0x00008000U)         /* !< Event Clear */
/* GPTIMER_GEN_EVENT0_ICLR[REPC] Bits */
#define GPTIMER_GEN_EVENT0_ICLR_REPC_OFS         (26)                            /* !< REPC Offset */
#define GPTIMER_GEN_EVENT0_ICLR_REPC_MASK        ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero event CLEAR */
#define GPTIMER_GEN_EVENT0_ICLR_REPC_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_GEN_EVENT0_ICLR_REPC_CLR         ((uint32_t)0x04000000U)         /* !< Event Clear */

/* GPTIMER_CPU_INT_IIDX Bits */
/* GPTIMER_CPU_INT_IIDX[STAT] Bits */
#define GPTIMER_CPU_INT_IIDX_STAT_OFS            (0)                             /* !< STAT Offset */
#define GPTIMER_CPU_INT_IIDX_STAT_MASK           ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define GPTIMER_CPU_INT_IIDX_STAT_NO_INTR        ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define GPTIMER_CPU_INT_IIDX_STAT_Z              ((uint32_t)0x00000001U)         /* !< Interrupt Source: Zero event (Z) */
#define GPTIMER_CPU_INT_IIDX_STAT_L              ((uint32_t)0x00000002U)         /* !< nterrupt Source: Load event (L) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCD0           ((uint32_t)0x00000005U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD0) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCD1           ((uint32_t)0x00000006U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD1) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCD2           ((uint32_t)0x00000007U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD2) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCD3           ((uint32_t)0x00000008U)         /* !< Interrupt Source: Capture or
                                                                                    compare down event (CCD3) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCU0           ((uint32_t)0x00000009U)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU0) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCU1           ((uint32_t)0x0000000AU)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU1) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCU2           ((uint32_t)0x0000000BU)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU2) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCU3           ((uint32_t)0x0000000CU)         /* !< Interrupt Source: Capture or
                                                                                    compare up event (CCU3) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCD4           ((uint32_t)0x0000000DU)         /* !< Interrupt Source: Compare down
                                                                                    event (CCD4) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCD5           ((uint32_t)0x0000000EU)         /* !< Interrupt Source: Compare down
                                                                                    event (CCD5) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCU4           ((uint32_t)0x0000000FU)         /* !< Interrupt Source: Compare down
                                                                                    event (CCU4) */
#define GPTIMER_CPU_INT_IIDX_STAT_CCU5           ((uint32_t)0x00000010U)         /* !< Interrupt Source: Compare down
                                                                                    event (CCU5) */
#define GPTIMER_CPU_INT_IIDX_STAT_F              ((uint32_t)0x00000019U)         /* !< Interrupt Source: Fault Event
                                                                                    generated an interrupt. (F) */
#define GPTIMER_CPU_INT_IIDX_STAT_TOV            ((uint32_t)0x0000001AU)         /* !< Interrupt Source: Trigger overflow
                                                                                    (TOV) */
#define GPTIMER_CPU_INT_IIDX_STAT_REPC           ((uint32_t)0x0000001BU)         /* !< Interrupt Source: Repeat Counter
                                                                                    Zero (REPC) */
#define GPTIMER_CPU_INT_IIDX_STAT_DC             ((uint32_t)0x0000001CU)         /* !< Interrupt Source: Direction Change
                                                                                    (DC) */
#define GPTIMER_CPU_INT_IIDX_STAT_QEIERR         ((uint32_t)0x0000001DU)         /* !< Interrupt Source:QEI Incorrect
                                                                                    state transition error (QEIERR) */

/* GPTIMER_CPU_INT_IMASK Bits */
/* GPTIMER_CPU_INT_IMASK[Z] Bits */
#define GPTIMER_CPU_INT_IMASK_Z_OFS              (0)                             /* !< Z Offset */
#define GPTIMER_CPU_INT_IMASK_Z_MASK             ((uint32_t)0x00000001U)         /* !< Zero Event mask */
#define GPTIMER_CPU_INT_IMASK_Z_CLR              ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_CPU_INT_IMASK_Z_SET              ((uint32_t)0x00000001U)         /* !< Enable Event */
/* GPTIMER_CPU_INT_IMASK[L] Bits */
#define GPTIMER_CPU_INT_IMASK_L_OFS              (1)                             /* !< L Offset */
#define GPTIMER_CPU_INT_IMASK_L_MASK             ((uint32_t)0x00000002U)         /* !< Load Event mask */
#define GPTIMER_CPU_INT_IMASK_L_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_L_SET              ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[CCD0] Bits */
#define GPTIMER_CPU_INT_IMASK_CCD0_OFS           (4)                             /* !< CCD0 Offset */
#define GPTIMER_CPU_INT_IMASK_CCD0_MASK          ((uint32_t)0x00000010U)         /* !< Capture or Compare DN event mask
                                                                                    CCP0 */
#define GPTIMER_CPU_INT_IMASK_CCD0_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCD0_SET           ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[CCD1] Bits */
#define GPTIMER_CPU_INT_IMASK_CCD1_OFS           (5)                             /* !< CCD1 Offset */
#define GPTIMER_CPU_INT_IMASK_CCD1_MASK          ((uint32_t)0x00000020U)         /* !< Capture or Compare DN event mask
                                                                                    CCP1 */
#define GPTIMER_CPU_INT_IMASK_CCD1_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCD1_SET           ((uint32_t)0x00000020U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[CCU0] Bits */
#define GPTIMER_CPU_INT_IMASK_CCU0_OFS           (8)                             /* !< CCU0 Offset */
#define GPTIMER_CPU_INT_IMASK_CCU0_MASK          ((uint32_t)0x00000100U)         /* !< Capture or Compare UP event mask
                                                                                    CCP0 */
#define GPTIMER_CPU_INT_IMASK_CCU0_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCU0_SET           ((uint32_t)0x00000100U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[CCU1] Bits */
#define GPTIMER_CPU_INT_IMASK_CCU1_OFS           (9)                             /* !< CCU1 Offset */
#define GPTIMER_CPU_INT_IMASK_CCU1_MASK          ((uint32_t)0x00000200U)         /* !< Capture or Compare UP event mask
                                                                                    CCP1 */
#define GPTIMER_CPU_INT_IMASK_CCU1_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCU1_SET           ((uint32_t)0x00000200U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[F] Bits */
#define GPTIMER_CPU_INT_IMASK_F_OFS              (24)                            /* !< F Offset */
#define GPTIMER_CPU_INT_IMASK_F_MASK             ((uint32_t)0x01000000U)         /* !< Fault Event mask */
#define GPTIMER_CPU_INT_IMASK_F_CLR              ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_CPU_INT_IMASK_F_SET              ((uint32_t)0x01000000U)         /* !< Enable Event */
/* GPTIMER_CPU_INT_IMASK[TOV] Bits */
#define GPTIMER_CPU_INT_IMASK_TOV_OFS            (25)                            /* !< TOV Offset */
#define GPTIMER_CPU_INT_IMASK_TOV_MASK           ((uint32_t)0x02000000U)         /* !< Trigger Overflow Event mask */
#define GPTIMER_CPU_INT_IMASK_TOV_CLR            ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_CPU_INT_IMASK_TOV_SET            ((uint32_t)0x02000000U)         /* !< Enable Event */
/* GPTIMER_CPU_INT_IMASK[DC] Bits */
#define GPTIMER_CPU_INT_IMASK_DC_OFS             (27)                            /* !< DC Offset */
#define GPTIMER_CPU_INT_IMASK_DC_MASK            ((uint32_t)0x08000000U)         /* !< Direction Change Event mask */
#define GPTIMER_CPU_INT_IMASK_DC_CLR             ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_CPU_INT_IMASK_DC_SET             ((uint32_t)0x08000000U)         /* !< Enable Event */
/* GPTIMER_CPU_INT_IMASK[QEIERR] Bits */
#define GPTIMER_CPU_INT_IMASK_QEIERR_OFS         (28)                            /* !< QEIERR Offset */
#define GPTIMER_CPU_INT_IMASK_QEIERR_MASK        ((uint32_t)0x10000000U)         /* !< QEIERR Event mask */
#define GPTIMER_CPU_INT_IMASK_QEIERR_CLR         ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_CPU_INT_IMASK_QEIERR_SET         ((uint32_t)0x10000000U)         /* !< Enable Event */
/* GPTIMER_CPU_INT_IMASK[CCD2] Bits */
#define GPTIMER_CPU_INT_IMASK_CCD2_OFS           (6)                             /* !< CCD2 Offset */
#define GPTIMER_CPU_INT_IMASK_CCD2_MASK          ((uint32_t)0x00000040U)         /* !< Capture or Compare DN event mask
                                                                                    CCP2 */
#define GPTIMER_CPU_INT_IMASK_CCD2_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCD2_SET           ((uint32_t)0x00000040U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[CCD3] Bits */
#define GPTIMER_CPU_INT_IMASK_CCD3_OFS           (7)                             /* !< CCD3 Offset */
#define GPTIMER_CPU_INT_IMASK_CCD3_MASK          ((uint32_t)0x00000080U)         /* !< Capture or Compare DN event mask
                                                                                    CCP3 */
#define GPTIMER_CPU_INT_IMASK_CCD3_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCD3_SET           ((uint32_t)0x00000080U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[CCU2] Bits */
#define GPTIMER_CPU_INT_IMASK_CCU2_OFS           (10)                            /* !< CCU2 Offset */
#define GPTIMER_CPU_INT_IMASK_CCU2_MASK          ((uint32_t)0x00000400U)         /* !< Capture or Compare UP event mask
                                                                                    CCP2 */
#define GPTIMER_CPU_INT_IMASK_CCU2_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCU2_SET           ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[CCU3] Bits */
#define GPTIMER_CPU_INT_IMASK_CCU3_OFS           (11)                            /* !< CCU3 Offset */
#define GPTIMER_CPU_INT_IMASK_CCU3_MASK          ((uint32_t)0x00000800U)         /* !< Capture or Compare UP event mask
                                                                                    CCP3 */
#define GPTIMER_CPU_INT_IMASK_CCU3_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCU3_SET           ((uint32_t)0x00000800U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[CCD4] Bits */
#define GPTIMER_CPU_INT_IMASK_CCD4_OFS           (12)                            /* !< CCD4 Offset */
#define GPTIMER_CPU_INT_IMASK_CCD4_MASK          ((uint32_t)0x00001000U)         /* !< Compare DN event mask CCP4 */
#define GPTIMER_CPU_INT_IMASK_CCD4_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCD4_SET           ((uint32_t)0x00001000U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[CCD5] Bits */
#define GPTIMER_CPU_INT_IMASK_CCD5_OFS           (13)                            /* !< CCD5 Offset */
#define GPTIMER_CPU_INT_IMASK_CCD5_MASK          ((uint32_t)0x00002000U)         /* !< Compare DN event mask CCP5 */
#define GPTIMER_CPU_INT_IMASK_CCD5_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCD5_SET           ((uint32_t)0x00002000U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[CCU4] Bits */
#define GPTIMER_CPU_INT_IMASK_CCU4_OFS           (14)                            /* !< CCU4 Offset */
#define GPTIMER_CPU_INT_IMASK_CCU4_MASK          ((uint32_t)0x00004000U)         /* !< Compare UP event mask CCP4 */
#define GPTIMER_CPU_INT_IMASK_CCU4_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCU4_SET           ((uint32_t)0x00004000U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[CCU5] Bits */
#define GPTIMER_CPU_INT_IMASK_CCU5_OFS           (15)                            /* !< CCU5 Offset */
#define GPTIMER_CPU_INT_IMASK_CCU5_MASK          ((uint32_t)0x00008000U)         /* !< Compare UP event mask CCP5 */
#define GPTIMER_CPU_INT_IMASK_CCU5_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define GPTIMER_CPU_INT_IMASK_CCU5_SET           ((uint32_t)0x00008000U)         /* !< Set Interrupt Mask */
/* GPTIMER_CPU_INT_IMASK[REPC] Bits */
#define GPTIMER_CPU_INT_IMASK_REPC_OFS           (26)                            /* !< REPC Offset */
#define GPTIMER_CPU_INT_IMASK_REPC_MASK          ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero Event mask */
#define GPTIMER_CPU_INT_IMASK_REPC_CLR           ((uint32_t)0x00000000U)         /* !< Disable Event */
#define GPTIMER_CPU_INT_IMASK_REPC_SET           ((uint32_t)0x04000000U)         /* !< Enable Event */

/* GPTIMER_CPU_INT_RIS Bits */
/* GPTIMER_CPU_INT_RIS[Z] Bits */
#define GPTIMER_CPU_INT_RIS_Z_OFS                (0)                             /* !< Z Offset */
#define GPTIMER_CPU_INT_RIS_Z_MASK               ((uint32_t)0x00000001U)         /* !< Zero event generated an interrupt. */
#define GPTIMER_CPU_INT_RIS_Z_CLR                ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_Z_SET                ((uint32_t)0x00000001U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[L] Bits */
#define GPTIMER_CPU_INT_RIS_L_OFS                (1)                             /* !< L Offset */
#define GPTIMER_CPU_INT_RIS_L_MASK               ((uint32_t)0x00000002U)         /* !< Load event generated an interrupt. */
#define GPTIMER_CPU_INT_RIS_L_CLR                ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_L_SET                ((uint32_t)0x00000002U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCD0] Bits */
#define GPTIMER_CPU_INT_RIS_CCD0_OFS             (4)                             /* !< CCD0 Offset */
#define GPTIMER_CPU_INT_RIS_CCD0_MASK            ((uint32_t)0x00000010U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_CPU_INT_RIS_CCD0_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCD0_SET             ((uint32_t)0x00000010U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCD1] Bits */
#define GPTIMER_CPU_INT_RIS_CCD1_OFS             (5)                             /* !< CCD1 Offset */
#define GPTIMER_CPU_INT_RIS_CCD1_MASK            ((uint32_t)0x00000020U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_CPU_INT_RIS_CCD1_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCD1_SET             ((uint32_t)0x00000020U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCU0] Bits */
#define GPTIMER_CPU_INT_RIS_CCU0_OFS             (8)                             /* !< CCU0 Offset */
#define GPTIMER_CPU_INT_RIS_CCU0_MASK            ((uint32_t)0x00000100U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_CPU_INT_RIS_CCU0_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCU0_SET             ((uint32_t)0x00000100U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCU1] Bits */
#define GPTIMER_CPU_INT_RIS_CCU1_OFS             (9)                             /* !< CCU1 Offset */
#define GPTIMER_CPU_INT_RIS_CCU1_MASK            ((uint32_t)0x00000200U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_CPU_INT_RIS_CCU1_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCU1_SET             ((uint32_t)0x00000200U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[TOV] Bits */
#define GPTIMER_CPU_INT_RIS_TOV_OFS              (25)                            /* !< TOV Offset */
#define GPTIMER_CPU_INT_RIS_TOV_MASK             ((uint32_t)0x02000000U)         /* !< Trigger overflow */
#define GPTIMER_CPU_INT_RIS_TOV_CLR              ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_TOV_SET              ((uint32_t)0x02000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[F] Bits */
#define GPTIMER_CPU_INT_RIS_F_OFS                (24)                            /* !< F Offset */
#define GPTIMER_CPU_INT_RIS_F_MASK               ((uint32_t)0x01000000U)         /* !< Fault */
#define GPTIMER_CPU_INT_RIS_F_CLR                ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_F_SET                ((uint32_t)0x01000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[DC] Bits */
#define GPTIMER_CPU_INT_RIS_DC_OFS               (27)                            /* !< DC Offset */
#define GPTIMER_CPU_INT_RIS_DC_MASK              ((uint32_t)0x08000000U)         /* !< Direction Change */
#define GPTIMER_CPU_INT_RIS_DC_CLR               ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_DC_SET               ((uint32_t)0x08000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[QEIERR] Bits */
#define GPTIMER_CPU_INT_RIS_QEIERR_OFS           (28)                            /* !< QEIERR Offset */
#define GPTIMER_CPU_INT_RIS_QEIERR_MASK          ((uint32_t)0x10000000U)         /* !< QEIERR, set on an incorrect state
                                                                                    transition on the encoder interface. */
#define GPTIMER_CPU_INT_RIS_QEIERR_CLR           ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_QEIERR_SET           ((uint32_t)0x10000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCD2] Bits */
#define GPTIMER_CPU_INT_RIS_CCD2_OFS             (6)                             /* !< CCD2 Offset */
#define GPTIMER_CPU_INT_RIS_CCD2_MASK            ((uint32_t)0x00000040U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_CPU_INT_RIS_CCD2_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCD2_SET             ((uint32_t)0x00000040U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCD3] Bits */
#define GPTIMER_CPU_INT_RIS_CCD3_OFS             (7)                             /* !< CCD3 Offset */
#define GPTIMER_CPU_INT_RIS_CCD3_MASK            ((uint32_t)0x00000080U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_CPU_INT_RIS_CCD3_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCD3_SET             ((uint32_t)0x00000080U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCU2] Bits */
#define GPTIMER_CPU_INT_RIS_CCU2_OFS             (10)                            /* !< CCU2 Offset */
#define GPTIMER_CPU_INT_RIS_CCU2_MASK            ((uint32_t)0x00000400U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_CPU_INT_RIS_CCU2_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCU2_SET             ((uint32_t)0x00000400U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCU3] Bits */
#define GPTIMER_CPU_INT_RIS_CCU3_OFS             (11)                            /* !< CCU3 Offset */
#define GPTIMER_CPU_INT_RIS_CCU3_MASK            ((uint32_t)0x00000800U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_CPU_INT_RIS_CCU3_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCU3_SET             ((uint32_t)0x00000800U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCD4] Bits */
#define GPTIMER_CPU_INT_RIS_CCD4_OFS             (12)                            /* !< CCD4 Offset */
#define GPTIMER_CPU_INT_RIS_CCD4_MASK            ((uint32_t)0x00001000U)         /* !< Compare down event generated an
                                                                                    interrupt CCD4 */
#define GPTIMER_CPU_INT_RIS_CCD4_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCD4_SET             ((uint32_t)0x00001000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCD5] Bits */
#define GPTIMER_CPU_INT_RIS_CCD5_OFS             (13)                            /* !< CCD5 Offset */
#define GPTIMER_CPU_INT_RIS_CCD5_MASK            ((uint32_t)0x00002000U)         /* !< Compare down event generated an
                                                                                    interrupt CCD5 */
#define GPTIMER_CPU_INT_RIS_CCD5_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCD5_SET             ((uint32_t)0x00002000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCU4] Bits */
#define GPTIMER_CPU_INT_RIS_CCU4_OFS             (14)                            /* !< CCU4 Offset */
#define GPTIMER_CPU_INT_RIS_CCU4_MASK            ((uint32_t)0x00004000U)         /* !< Compare up event generated an
                                                                                    interrupt CCU4 */
#define GPTIMER_CPU_INT_RIS_CCU4_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCU4_SET             ((uint32_t)0x00004000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[CCU5] Bits */
#define GPTIMER_CPU_INT_RIS_CCU5_OFS             (15)                            /* !< CCU5 Offset */
#define GPTIMER_CPU_INT_RIS_CCU5_MASK            ((uint32_t)0x00008000U)         /* !< Compare up event generated an
                                                                                    interrupt CCP5 */
#define GPTIMER_CPU_INT_RIS_CCU5_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_CCU5_SET             ((uint32_t)0x00008000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_RIS[REPC] Bits */
#define GPTIMER_CPU_INT_RIS_REPC_OFS             (26)                            /* !< REPC Offset */
#define GPTIMER_CPU_INT_RIS_REPC_MASK            ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero */
#define GPTIMER_CPU_INT_RIS_REPC_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_RIS_REPC_SET             ((uint32_t)0x04000000U)         /* !< Event Set */

/* GPTIMER_CPU_INT_MIS Bits */
/* GPTIMER_CPU_INT_MIS[Z] Bits */
#define GPTIMER_CPU_INT_MIS_Z_OFS                (0)                             /* !< Z Offset */
#define GPTIMER_CPU_INT_MIS_Z_MASK               ((uint32_t)0x00000001U)         /* !< Zero event generated an interrupt. */
#define GPTIMER_CPU_INT_MIS_Z_CLR                ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_Z_SET                ((uint32_t)0x00000001U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[L] Bits */
#define GPTIMER_CPU_INT_MIS_L_OFS                (1)                             /* !< L Offset */
#define GPTIMER_CPU_INT_MIS_L_MASK               ((uint32_t)0x00000002U)         /* !< Load event generated an interrupt. */
#define GPTIMER_CPU_INT_MIS_L_CLR                ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_L_SET                ((uint32_t)0x00000002U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCD0] Bits */
#define GPTIMER_CPU_INT_MIS_CCD0_OFS             (4)                             /* !< CCD0 Offset */
#define GPTIMER_CPU_INT_MIS_CCD0_MASK            ((uint32_t)0x00000010U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_CPU_INT_MIS_CCD0_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCD0_SET             ((uint32_t)0x00000010U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCD1] Bits */
#define GPTIMER_CPU_INT_MIS_CCD1_OFS             (5)                             /* !< CCD1 Offset */
#define GPTIMER_CPU_INT_MIS_CCD1_MASK            ((uint32_t)0x00000020U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_CPU_INT_MIS_CCD1_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCD1_SET             ((uint32_t)0x00000020U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCU0] Bits */
#define GPTIMER_CPU_INT_MIS_CCU0_OFS             (8)                             /* !< CCU0 Offset */
#define GPTIMER_CPU_INT_MIS_CCU0_MASK            ((uint32_t)0x00000100U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP0 */
#define GPTIMER_CPU_INT_MIS_CCU0_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCU0_SET             ((uint32_t)0x00000100U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCU1] Bits */
#define GPTIMER_CPU_INT_MIS_CCU1_OFS             (9)                             /* !< CCU1 Offset */
#define GPTIMER_CPU_INT_MIS_CCU1_MASK            ((uint32_t)0x00000200U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP1 */
#define GPTIMER_CPU_INT_MIS_CCU1_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCU1_SET             ((uint32_t)0x00000200U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[F] Bits */
#define GPTIMER_CPU_INT_MIS_F_OFS                (24)                            /* !< F Offset */
#define GPTIMER_CPU_INT_MIS_F_MASK               ((uint32_t)0x01000000U)         /* !< Fault */
#define GPTIMER_CPU_INT_MIS_F_CLR                ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_F_SET                ((uint32_t)0x01000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[TOV] Bits */
#define GPTIMER_CPU_INT_MIS_TOV_OFS              (25)                            /* !< TOV Offset */
#define GPTIMER_CPU_INT_MIS_TOV_MASK             ((uint32_t)0x02000000U)         /* !< Trigger overflow */
#define GPTIMER_CPU_INT_MIS_TOV_CLR              ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_TOV_SET              ((uint32_t)0x02000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[DC] Bits */
#define GPTIMER_CPU_INT_MIS_DC_OFS               (27)                            /* !< DC Offset */
#define GPTIMER_CPU_INT_MIS_DC_MASK              ((uint32_t)0x08000000U)         /* !< Direction Change */
#define GPTIMER_CPU_INT_MIS_DC_CLR               ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_DC_SET               ((uint32_t)0x08000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[QEIERR] Bits */
#define GPTIMER_CPU_INT_MIS_QEIERR_OFS           (28)                            /* !< QEIERR Offset */
#define GPTIMER_CPU_INT_MIS_QEIERR_MASK          ((uint32_t)0x10000000U)         /* !< QEIERR */
#define GPTIMER_CPU_INT_MIS_QEIERR_CLR           ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_QEIERR_SET           ((uint32_t)0x10000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCD2] Bits */
#define GPTIMER_CPU_INT_MIS_CCD2_OFS             (6)                             /* !< CCD2 Offset */
#define GPTIMER_CPU_INT_MIS_CCD2_MASK            ((uint32_t)0x00000040U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_CPU_INT_MIS_CCD2_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCD2_SET             ((uint32_t)0x00000040U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCD3] Bits */
#define GPTIMER_CPU_INT_MIS_CCD3_OFS             (7)                             /* !< CCD3 Offset */
#define GPTIMER_CPU_INT_MIS_CCD3_MASK            ((uint32_t)0x00000080U)         /* !< Capture or compare down event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_CPU_INT_MIS_CCD3_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCD3_SET             ((uint32_t)0x00000080U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCU2] Bits */
#define GPTIMER_CPU_INT_MIS_CCU2_OFS             (10)                            /* !< CCU2 Offset */
#define GPTIMER_CPU_INT_MIS_CCU2_MASK            ((uint32_t)0x00000400U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP2 */
#define GPTIMER_CPU_INT_MIS_CCU2_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCU2_SET             ((uint32_t)0x00000400U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCU3] Bits */
#define GPTIMER_CPU_INT_MIS_CCU3_OFS             (11)                            /* !< CCU3 Offset */
#define GPTIMER_CPU_INT_MIS_CCU3_MASK            ((uint32_t)0x00000800U)         /* !< Capture or compare up event
                                                                                    generated an interrupt CCP3 */
#define GPTIMER_CPU_INT_MIS_CCU3_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCU3_SET             ((uint32_t)0x00000800U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCD4] Bits */
#define GPTIMER_CPU_INT_MIS_CCD4_OFS             (12)                            /* !< CCD4 Offset */
#define GPTIMER_CPU_INT_MIS_CCD4_MASK            ((uint32_t)0x00001000U)         /* !< Compare down event generated an
                                                                                    interrupt CCP4 */
#define GPTIMER_CPU_INT_MIS_CCD4_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCD4_SET             ((uint32_t)0x00001000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCD5] Bits */
#define GPTIMER_CPU_INT_MIS_CCD5_OFS             (13)                            /* !< CCD5 Offset */
#define GPTIMER_CPU_INT_MIS_CCD5_MASK            ((uint32_t)0x00002000U)         /* !< Compare down event generated an
                                                                                    interrupt CCP5 */
#define GPTIMER_CPU_INT_MIS_CCD5_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCD5_SET             ((uint32_t)0x00002000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCU4] Bits */
#define GPTIMER_CPU_INT_MIS_CCU4_OFS             (14)                            /* !< CCU4 Offset */
#define GPTIMER_CPU_INT_MIS_CCU4_MASK            ((uint32_t)0x00004000U)         /* !< Compare up event generated an
                                                                                    interrupt CCP4 */
#define GPTIMER_CPU_INT_MIS_CCU4_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCU4_SET             ((uint32_t)0x00004000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[CCU5] Bits */
#define GPTIMER_CPU_INT_MIS_CCU5_OFS             (15)                            /* !< CCU5 Offset */
#define GPTIMER_CPU_INT_MIS_CCU5_MASK            ((uint32_t)0x00008000U)         /* !< Compare up event generated an
                                                                                    interrupt CCP5 */
#define GPTIMER_CPU_INT_MIS_CCU5_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_CCU5_SET             ((uint32_t)0x00008000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_MIS[REPC] Bits */
#define GPTIMER_CPU_INT_MIS_REPC_OFS             (26)                            /* !< REPC Offset */
#define GPTIMER_CPU_INT_MIS_REPC_MASK            ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero */
#define GPTIMER_CPU_INT_MIS_REPC_CLR             ((uint32_t)0x00000000U)         /* !< Event Cleared */
#define GPTIMER_CPU_INT_MIS_REPC_SET             ((uint32_t)0x04000000U)         /* !< Event Set */

/* GPTIMER_CPU_INT_ISET Bits */
/* GPTIMER_CPU_INT_ISET[Z] Bits */
#define GPTIMER_CPU_INT_ISET_Z_OFS               (0)                             /* !< Z Offset */
#define GPTIMER_CPU_INT_ISET_Z_MASK              ((uint32_t)0x00000001U)         /* !< Zero event SET */
#define GPTIMER_CPU_INT_ISET_Z_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_Z_SET               ((uint32_t)0x00000001U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[L] Bits */
#define GPTIMER_CPU_INT_ISET_L_OFS               (1)                             /* !< L Offset */
#define GPTIMER_CPU_INT_ISET_L_MASK              ((uint32_t)0x00000002U)         /* !< Load event SET */
#define GPTIMER_CPU_INT_ISET_L_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_L_SET               ((uint32_t)0x00000002U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCD0] Bits */
#define GPTIMER_CPU_INT_ISET_CCD0_OFS            (4)                             /* !< CCD0 Offset */
#define GPTIMER_CPU_INT_ISET_CCD0_MASK           ((uint32_t)0x00000010U)         /* !< Capture or compare down event SET */
#define GPTIMER_CPU_INT_ISET_CCD0_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCD0_SET            ((uint32_t)0x00000010U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCD1] Bits */
#define GPTIMER_CPU_INT_ISET_CCD1_OFS            (5)                             /* !< CCD1 Offset */
#define GPTIMER_CPU_INT_ISET_CCD1_MASK           ((uint32_t)0x00000020U)         /* !< Capture or compare down event SET */
#define GPTIMER_CPU_INT_ISET_CCD1_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCD1_SET            ((uint32_t)0x00000020U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCU0] Bits */
#define GPTIMER_CPU_INT_ISET_CCU0_OFS            (8)                             /* !< CCU0 Offset */
#define GPTIMER_CPU_INT_ISET_CCU0_MASK           ((uint32_t)0x00000100U)         /* !< Capture or compare up event SET */
#define GPTIMER_CPU_INT_ISET_CCU0_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCU0_SET            ((uint32_t)0x00000100U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCU1] Bits */
#define GPTIMER_CPU_INT_ISET_CCU1_OFS            (9)                             /* !< CCU1 Offset */
#define GPTIMER_CPU_INT_ISET_CCU1_MASK           ((uint32_t)0x00000200U)         /* !< Capture or compare up event SET */
#define GPTIMER_CPU_INT_ISET_CCU1_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCU1_SET            ((uint32_t)0x00000200U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[F] Bits */
#define GPTIMER_CPU_INT_ISET_F_OFS               (24)                            /* !< F Offset */
#define GPTIMER_CPU_INT_ISET_F_MASK              ((uint32_t)0x01000000U)         /* !< Fault event SET */
#define GPTIMER_CPU_INT_ISET_F_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_F_SET               ((uint32_t)0x01000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[TOV] Bits */
#define GPTIMER_CPU_INT_ISET_TOV_OFS             (25)                            /* !< TOV Offset */
#define GPTIMER_CPU_INT_ISET_TOV_MASK            ((uint32_t)0x02000000U)         /* !< Trigger Overflow event SET */
#define GPTIMER_CPU_INT_ISET_TOV_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_TOV_SET             ((uint32_t)0x02000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[DC] Bits */
#define GPTIMER_CPU_INT_ISET_DC_OFS              (27)                            /* !< DC Offset */
#define GPTIMER_CPU_INT_ISET_DC_MASK             ((uint32_t)0x08000000U)         /* !< Direction Change event SET */
#define GPTIMER_CPU_INT_ISET_DC_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_DC_SET              ((uint32_t)0x08000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[QEIERR] Bits */
#define GPTIMER_CPU_INT_ISET_QEIERR_OFS          (28)                            /* !< QEIERR Offset */
#define GPTIMER_CPU_INT_ISET_QEIERR_MASK         ((uint32_t)0x10000000U)         /* !< QEIERR event SET */
#define GPTIMER_CPU_INT_ISET_QEIERR_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_QEIERR_SET          ((uint32_t)0x10000000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCD2] Bits */
#define GPTIMER_CPU_INT_ISET_CCD2_OFS            (6)                             /* !< CCD2 Offset */
#define GPTIMER_CPU_INT_ISET_CCD2_MASK           ((uint32_t)0x00000040U)         /* !< Capture or compare down event SET */
#define GPTIMER_CPU_INT_ISET_CCD2_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCD2_SET            ((uint32_t)0x00000040U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCD3] Bits */
#define GPTIMER_CPU_INT_ISET_CCD3_OFS            (7)                             /* !< CCD3 Offset */
#define GPTIMER_CPU_INT_ISET_CCD3_MASK           ((uint32_t)0x00000080U)         /* !< Capture or compare down event SET */
#define GPTIMER_CPU_INT_ISET_CCD3_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCD3_SET            ((uint32_t)0x00000080U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCU2] Bits */
#define GPTIMER_CPU_INT_ISET_CCU2_OFS            (10)                            /* !< CCU2 Offset */
#define GPTIMER_CPU_INT_ISET_CCU2_MASK           ((uint32_t)0x00000400U)         /* !< Capture or compare up event SET */
#define GPTIMER_CPU_INT_ISET_CCU2_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCU2_SET            ((uint32_t)0x00000400U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCU3] Bits */
#define GPTIMER_CPU_INT_ISET_CCU3_OFS            (11)                            /* !< CCU3 Offset */
#define GPTIMER_CPU_INT_ISET_CCU3_MASK           ((uint32_t)0x00000800U)         /* !< Capture or compare up event SET */
#define GPTIMER_CPU_INT_ISET_CCU3_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCU3_SET            ((uint32_t)0x00000800U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCD4] Bits */
#define GPTIMER_CPU_INT_ISET_CCD4_OFS            (12)                            /* !< CCD4 Offset */
#define GPTIMER_CPU_INT_ISET_CCD4_MASK           ((uint32_t)0x00001000U)         /* !< Compare down event 4 SET */
#define GPTIMER_CPU_INT_ISET_CCD4_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCD4_SET            ((uint32_t)0x00001000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCD5] Bits */
#define GPTIMER_CPU_INT_ISET_CCD5_OFS            (13)                            /* !< CCD5 Offset */
#define GPTIMER_CPU_INT_ISET_CCD5_MASK           ((uint32_t)0x00002000U)         /* !< Compare down event 5 SET */
#define GPTIMER_CPU_INT_ISET_CCD5_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCD5_SET            ((uint32_t)0x00002000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCU4] Bits */
#define GPTIMER_CPU_INT_ISET_CCU4_OFS            (14)                            /* !< CCU4 Offset */
#define GPTIMER_CPU_INT_ISET_CCU4_MASK           ((uint32_t)0x00004000U)         /* !< Compare up event 4 SET */
#define GPTIMER_CPU_INT_ISET_CCU4_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCU4_SET            ((uint32_t)0x00004000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[CCU5] Bits */
#define GPTIMER_CPU_INT_ISET_CCU5_OFS            (15)                            /* !< CCU5 Offset */
#define GPTIMER_CPU_INT_ISET_CCU5_MASK           ((uint32_t)0x00008000U)         /* !< Compare up event 5 SET */
#define GPTIMER_CPU_INT_ISET_CCU5_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_CCU5_SET            ((uint32_t)0x00008000U)         /* !< Event Set */
/* GPTIMER_CPU_INT_ISET[REPC] Bits */
#define GPTIMER_CPU_INT_ISET_REPC_OFS            (26)                            /* !< REPC Offset */
#define GPTIMER_CPU_INT_ISET_REPC_MASK           ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero event SET */
#define GPTIMER_CPU_INT_ISET_REPC_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ISET_REPC_SET            ((uint32_t)0x04000000U)         /* !< Event Set */

/* GPTIMER_CPU_INT_ICLR Bits */
/* GPTIMER_CPU_INT_ICLR[Z] Bits */
#define GPTIMER_CPU_INT_ICLR_Z_OFS               (0)                             /* !< Z Offset */
#define GPTIMER_CPU_INT_ICLR_Z_MASK              ((uint32_t)0x00000001U)         /* !< Zero event CLEAR */
#define GPTIMER_CPU_INT_ICLR_Z_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_Z_CLR               ((uint32_t)0x00000001U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[L] Bits */
#define GPTIMER_CPU_INT_ICLR_L_OFS               (1)                             /* !< L Offset */
#define GPTIMER_CPU_INT_ICLR_L_MASK              ((uint32_t)0x00000002U)         /* !< Load event CLEAR */
#define GPTIMER_CPU_INT_ICLR_L_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_L_CLR               ((uint32_t)0x00000002U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCD0] Bits */
#define GPTIMER_CPU_INT_ICLR_CCD0_OFS            (4)                             /* !< CCD0 Offset */
#define GPTIMER_CPU_INT_ICLR_CCD0_MASK           ((uint32_t)0x00000010U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCD0_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCD0_CLR            ((uint32_t)0x00000010U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCD1] Bits */
#define GPTIMER_CPU_INT_ICLR_CCD1_OFS            (5)                             /* !< CCD1 Offset */
#define GPTIMER_CPU_INT_ICLR_CCD1_MASK           ((uint32_t)0x00000020U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCD1_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCD1_CLR            ((uint32_t)0x00000020U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCU0] Bits */
#define GPTIMER_CPU_INT_ICLR_CCU0_OFS            (8)                             /* !< CCU0 Offset */
#define GPTIMER_CPU_INT_ICLR_CCU0_MASK           ((uint32_t)0x00000100U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCU0_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCU0_CLR            ((uint32_t)0x00000100U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCU1] Bits */
#define GPTIMER_CPU_INT_ICLR_CCU1_OFS            (9)                             /* !< CCU1 Offset */
#define GPTIMER_CPU_INT_ICLR_CCU1_MASK           ((uint32_t)0x00000200U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCU1_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCU1_CLR            ((uint32_t)0x00000200U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[F] Bits */
#define GPTIMER_CPU_INT_ICLR_F_OFS               (24)                            /* !< F Offset */
#define GPTIMER_CPU_INT_ICLR_F_MASK              ((uint32_t)0x01000000U)         /* !< Fault event CLEAR */
#define GPTIMER_CPU_INT_ICLR_F_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_F_CLR               ((uint32_t)0x01000000U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[TOV] Bits */
#define GPTIMER_CPU_INT_ICLR_TOV_OFS             (25)                            /* !< TOV Offset */
#define GPTIMER_CPU_INT_ICLR_TOV_MASK            ((uint32_t)0x02000000U)         /* !< Trigger Overflow event CLEAR */
#define GPTIMER_CPU_INT_ICLR_TOV_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_TOV_CLR             ((uint32_t)0x02000000U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[DC] Bits */
#define GPTIMER_CPU_INT_ICLR_DC_OFS              (27)                            /* !< DC Offset */
#define GPTIMER_CPU_INT_ICLR_DC_MASK             ((uint32_t)0x08000000U)         /* !< Direction Change event CLEAR */
#define GPTIMER_CPU_INT_ICLR_DC_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_DC_CLR              ((uint32_t)0x08000000U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[QEIERR] Bits */
#define GPTIMER_CPU_INT_ICLR_QEIERR_OFS          (28)                            /* !< QEIERR Offset */
#define GPTIMER_CPU_INT_ICLR_QEIERR_MASK         ((uint32_t)0x10000000U)         /* !< QEIERR event CLEAR */
#define GPTIMER_CPU_INT_ICLR_QEIERR_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_QEIERR_CLR          ((uint32_t)0x10000000U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCD2] Bits */
#define GPTIMER_CPU_INT_ICLR_CCD2_OFS            (6)                             /* !< CCD2 Offset */
#define GPTIMER_CPU_INT_ICLR_CCD2_MASK           ((uint32_t)0x00000040U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCD2_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCD2_CLR            ((uint32_t)0x00000040U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCD3] Bits */
#define GPTIMER_CPU_INT_ICLR_CCD3_OFS            (7)                             /* !< CCD3 Offset */
#define GPTIMER_CPU_INT_ICLR_CCD3_MASK           ((uint32_t)0x00000080U)         /* !< Capture or compare down event CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCD3_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCD3_CLR            ((uint32_t)0x00000080U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCU2] Bits */
#define GPTIMER_CPU_INT_ICLR_CCU2_OFS            (10)                            /* !< CCU2 Offset */
#define GPTIMER_CPU_INT_ICLR_CCU2_MASK           ((uint32_t)0x00000400U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCU2_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCU2_CLR            ((uint32_t)0x00000400U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCU3] Bits */
#define GPTIMER_CPU_INT_ICLR_CCU3_OFS            (11)                            /* !< CCU3 Offset */
#define GPTIMER_CPU_INT_ICLR_CCU3_MASK           ((uint32_t)0x00000800U)         /* !< Capture or compare up event CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCU3_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCU3_CLR            ((uint32_t)0x00000800U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCD4] Bits */
#define GPTIMER_CPU_INT_ICLR_CCD4_OFS            (12)                            /* !< CCD4 Offset */
#define GPTIMER_CPU_INT_ICLR_CCD4_MASK           ((uint32_t)0x00001000U)         /* !< Compare down event 4 CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCD4_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCD4_CLR            ((uint32_t)0x00001000U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCD5] Bits */
#define GPTIMER_CPU_INT_ICLR_CCD5_OFS            (13)                            /* !< CCD5 Offset */
#define GPTIMER_CPU_INT_ICLR_CCD5_MASK           ((uint32_t)0x00002000U)         /* !< Compare down event 5 CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCD5_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCD5_CLR            ((uint32_t)0x00002000U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCU4] Bits */
#define GPTIMER_CPU_INT_ICLR_CCU4_OFS            (14)                            /* !< CCU4 Offset */
#define GPTIMER_CPU_INT_ICLR_CCU4_MASK           ((uint32_t)0x00004000U)         /* !< Compare up event 4 CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCU4_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCU4_CLR            ((uint32_t)0x00004000U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[CCU5] Bits */
#define GPTIMER_CPU_INT_ICLR_CCU5_OFS            (15)                            /* !< CCU5 Offset */
#define GPTIMER_CPU_INT_ICLR_CCU5_MASK           ((uint32_t)0x00008000U)         /* !< Compare up event 5 CLEAR */
#define GPTIMER_CPU_INT_ICLR_CCU5_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_CCU5_CLR            ((uint32_t)0x00008000U)         /* !< Event Clear */
/* GPTIMER_CPU_INT_ICLR[REPC] Bits */
#define GPTIMER_CPU_INT_ICLR_REPC_OFS            (26)                            /* !< REPC Offset */
#define GPTIMER_CPU_INT_ICLR_REPC_MASK           ((uint32_t)0x04000000U)         /* !< Repeat Counter Zero event CLEAR */
#define GPTIMER_CPU_INT_ICLR_REPC_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect. */
#define GPTIMER_CPU_INT_ICLR_REPC_CLR            ((uint32_t)0x04000000U)         /* !< Event Clear */

/* GPTIMER_PWREN Bits */
/* GPTIMER_PWREN[ENABLE] Bits */
#define GPTIMER_PWREN_ENABLE_OFS                 (0)                             /* !< ENABLE Offset */
#define GPTIMER_PWREN_ENABLE_MASK                ((uint32_t)0x00000001U)         /* !< Enable the power */
#define GPTIMER_PWREN_ENABLE_DISABLE             ((uint32_t)0x00000000U)         /* !< Disable Power */
#define GPTIMER_PWREN_ENABLE_ENABLE              ((uint32_t)0x00000001U)         /* !< Enable Power */
/* GPTIMER_PWREN[KEY] Bits */
#define GPTIMER_PWREN_KEY_OFS                    (24)                            /* !< KEY Offset */
#define GPTIMER_PWREN_KEY_MASK                   ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define GPTIMER_PWREN_KEY_UNLOCK_W               ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* GPTIMER_RSTCTL Bits */
/* GPTIMER_RSTCTL[RESETSTKYCLR] Bits */
#define GPTIMER_RSTCTL_RESETSTKYCLR_OFS          (1)                             /* !< RESETSTKYCLR Offset */
#define GPTIMER_RSTCTL_RESETSTKYCLR_MASK         ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define GPTIMER_RSTCTL_RESETSTKYCLR_NOP          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define GPTIMER_RSTCTL_RESETSTKYCLR_CLR          ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* GPTIMER_RSTCTL[RESETASSERT] Bits */
#define GPTIMER_RSTCTL_RESETASSERT_OFS           (0)                             /* !< RESETASSERT Offset */
#define GPTIMER_RSTCTL_RESETASSERT_MASK          ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define GPTIMER_RSTCTL_RESETASSERT_NOP           ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define GPTIMER_RSTCTL_RESETASSERT_ASSERT        ((uint32_t)0x00000001U)         /* !< Assert reset */
/* GPTIMER_RSTCTL[KEY] Bits */
#define GPTIMER_RSTCTL_KEY_OFS                   (24)                            /* !< KEY Offset */
#define GPTIMER_RSTCTL_KEY_MASK                  ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define GPTIMER_RSTCTL_KEY_UNLOCK_W              ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* GPTIMER_STAT Bits */
/* GPTIMER_STAT[RESETSTKY] Bits */
#define GPTIMER_STAT_RESETSTKY_OFS               (16)                            /* !< RESETSTKY Offset */
#define GPTIMER_STAT_RESETSTKY_MASK              ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define GPTIMER_STAT_RESETSTKY_NORES             ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define GPTIMER_STAT_RESETSTKY_RESET             ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* GPTIMER_FSUB_0 Bits */
/* GPTIMER_FSUB_0[CHANID] Bits */
#define GPTIMER_FSUB_0_CHANID_OFS                (0)                             /* !< CHANID Offset */
#define GPTIMER_FSUB_0_CHANID_MASK               ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define GPTIMER_FSUB_0_CHANID_MNIMUM             ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define GPTIMER_FSUB_0_CHANID_UNCONNECTED        ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define GPTIMER_FSUB_0_CHANID_MAXIMUM            ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* GPTIMER_FSUB_1 Bits */
/* GPTIMER_FSUB_1[CHANID] Bits */
#define GPTIMER_FSUB_1_CHANID_OFS                (0)                             /* !< CHANID Offset */
#define GPTIMER_FSUB_1_CHANID_MASK               ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define GPTIMER_FSUB_1_CHANID_MNIMUM             ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define GPTIMER_FSUB_1_CHANID_UNCONNECTED        ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define GPTIMER_FSUB_1_CHANID_MAXIMUM            ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* GPTIMER_FPUB_0 Bits */
/* GPTIMER_FPUB_0[CHANID] Bits */
#define GPTIMER_FPUB_0_CHANID_OFS                (0)                             /* !< CHANID Offset */
#define GPTIMER_FPUB_0_CHANID_MASK               ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define GPTIMER_FPUB_0_CHANID_MNIMUM             ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define GPTIMER_FPUB_0_CHANID_UNCONNECTED        ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define GPTIMER_FPUB_0_CHANID_MAXIMUM            ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* GPTIMER_FPUB_1 Bits */
/* GPTIMER_FPUB_1[CHANID] Bits */
#define GPTIMER_FPUB_1_CHANID_OFS                (0)                             /* !< CHANID Offset */
#define GPTIMER_FPUB_1_CHANID_MASK               ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define GPTIMER_FPUB_1_CHANID_MNIMUM             ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define GPTIMER_FPUB_1_CHANID_UNCONNECTED        ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define GPTIMER_FPUB_1_CHANID_MAXIMUM            ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* GPTIMER_CLKDIV Bits */
/* GPTIMER_CLKDIV[RATIO] Bits */
#define GPTIMER_CLKDIV_RATIO_OFS                 (0)                             /* !< RATIO Offset */
#define GPTIMER_CLKDIV_RATIO_MASK                ((uint32_t)0x00000007U)         /* !< Selects divide ratio of module
                                                                                    clock */
#define GPTIMER_CLKDIV_RATIO_DIV_BY_1            ((uint32_t)0x00000000U)         /* !< Do not divide clock source */
#define GPTIMER_CLKDIV_RATIO_DIV_BY_2            ((uint32_t)0x00000001U)         /* !< Divide clock source by 2 */
#define GPTIMER_CLKDIV_RATIO_DIV_BY_3            ((uint32_t)0x00000002U)         /* !< Divide clock source by 3 */
#define GPTIMER_CLKDIV_RATIO_DIV_BY_4            ((uint32_t)0x00000003U)         /* !< Divide clock source by 4 */
#define GPTIMER_CLKDIV_RATIO_DIV_BY_5            ((uint32_t)0x00000004U)         /* !< Divide clock source by 5 */
#define GPTIMER_CLKDIV_RATIO_DIV_BY_6            ((uint32_t)0x00000005U)         /* !< Divide clock source by 6 */
#define GPTIMER_CLKDIV_RATIO_DIV_BY_7            ((uint32_t)0x00000006U)         /* !< Divide clock source by 7 */
#define GPTIMER_CLKDIV_RATIO_DIV_BY_8            ((uint32_t)0x00000007U)         /* !< Divide clock source by 8 */

/* GPTIMER_CLKSEL Bits */
/* GPTIMER_CLKSEL[LFCLK_SEL] Bits */
#define GPTIMER_CLKSEL_LFCLK_SEL_OFS             (1)                             /* !< LFCLK_SEL Offset */
#define GPTIMER_CLKSEL_LFCLK_SEL_MASK            ((uint32_t)0x00000002U)         /* !< Selects LFCLK as clock source if
                                                                                    enabled */
#define GPTIMER_CLKSEL_LFCLK_SEL_DISABLE         ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define GPTIMER_CLKSEL_LFCLK_SEL_ENABLE          ((uint32_t)0x00000002U)         /* !< Select this clock as a source */
/* GPTIMER_CLKSEL[MFCLK_SEL] Bits */
#define GPTIMER_CLKSEL_MFCLK_SEL_OFS             (2)                             /* !< MFCLK_SEL Offset */
#define GPTIMER_CLKSEL_MFCLK_SEL_MASK            ((uint32_t)0x00000004U)         /* !< Selects MFCLK as clock source if
                                                                                    enabled */
#define GPTIMER_CLKSEL_MFCLK_SEL_DISABLE         ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define GPTIMER_CLKSEL_MFCLK_SEL_ENABLE          ((uint32_t)0x00000004U)         /* !< Select this clock as a source */
/* GPTIMER_CLKSEL[BUSCLK_SEL] Bits */
#define GPTIMER_CLKSEL_BUSCLK_SEL_OFS            (3)                             /* !< BUSCLK_SEL Offset */
#define GPTIMER_CLKSEL_BUSCLK_SEL_MASK           ((uint32_t)0x00000008U)         /* !< Selects BUSCLK as clock source if
                                                                                    enabled */
#define GPTIMER_CLKSEL_BUSCLK_SEL_DISABLE        ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define GPTIMER_CLKSEL_BUSCLK_SEL_ENABLE         ((uint32_t)0x00000008U)         /* !< Select this clock as a source */
/* GPTIMER_CLKSEL[BUS2XCLK_SEL] Bits */
#define GPTIMER_CLKSEL_BUS2XCLK_SEL_OFS          (4)                             /* !< BUS2XCLK_SEL Offset */
#define GPTIMER_CLKSEL_BUS2XCLK_SEL_MASK         ((uint32_t)0x00000010U)         /* !< Selects 2x BUSCLK as clock source
                                                                                    if enabled */
#define GPTIMER_CLKSEL_BUS2XCLK_SEL_DISABLE      ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define GPTIMER_CLKSEL_BUS2XCLK_SEL_ENABLE       ((uint32_t)0x00000010U)         /* !< Select this clock as a source */

/* GPTIMER_PDBGCTL Bits */
/* GPTIMER_PDBGCTL[FREE] Bits */
#define GPTIMER_PDBGCTL_FREE_OFS                 (0)                             /* !< FREE Offset */
#define GPTIMER_PDBGCTL_FREE_MASK                ((uint32_t)0x00000001U)         /* !< Free run control */
#define GPTIMER_PDBGCTL_FREE_STOP                ((uint32_t)0x00000000U)         /* !< The peripheral freezes
                                                                                    functionality while the Core Halted
                                                                                    input is asserted and resumes when it
                                                                                    is deasserted. */
#define GPTIMER_PDBGCTL_FREE_RUN                 ((uint32_t)0x00000001U)         /* !< The peripheral ignores the state of
                                                                                    the Core Halted input */
/* GPTIMER_PDBGCTL[SOFT] Bits */
#define GPTIMER_PDBGCTL_SOFT_OFS                 (1)                             /* !< SOFT Offset */
#define GPTIMER_PDBGCTL_SOFT_MASK                ((uint32_t)0x00000002U)         /* !< Soft halt boundary control. This
                                                                                    function is only available, if [FREE]
                                                                                    is set to 'STOP' */
#define GPTIMER_PDBGCTL_SOFT_IMMEDIATE           ((uint32_t)0x00000000U)         /* !< The peripheral will halt
                                                                                    immediately, even if the resultant
                                                                                    state will result in corruption if
                                                                                    the system is restarted */
#define GPTIMER_PDBGCTL_SOFT_DELAYED             ((uint32_t)0x00000002U)         /* !< The peripheral blocks the debug
                                                                                    freeze until it has reached a
                                                                                    boundary where it can resume without
                                                                                    corruption */

/* GPTIMER_EVT_MODE Bits */
/* GPTIMER_EVT_MODE[EVT0_CFG] Bits */
#define GPTIMER_EVT_MODE_EVT0_CFG_OFS            (0)                             /* !< EVT0_CFG Offset */
#define GPTIMER_EVT_MODE_EVT0_CFG_MASK           ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to CPU_INT */
#define GPTIMER_EVT_MODE_EVT0_CFG_DISABLE        ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define GPTIMER_EVT_MODE_EVT0_CFG_SOFTWARE       ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define GPTIMER_EVT_MODE_EVT0_CFG_HARDWARE       ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* GPTIMER_EVT_MODE[EVT1_CFG] Bits */
#define GPTIMER_EVT_MODE_EVT1_CFG_OFS            (2)                             /* !< EVT1_CFG Offset */
#define GPTIMER_EVT_MODE_EVT1_CFG_MASK           ((uint32_t)0x0000000CU)         /* !< Event line mode select for event
                                                                                    corresponding to GEN_EVENT0 */
#define GPTIMER_EVT_MODE_EVT1_CFG_DISABLE        ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define GPTIMER_EVT_MODE_EVT1_CFG_SOFTWARE       ((uint32_t)0x00000004U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define GPTIMER_EVT_MODE_EVT1_CFG_HARDWARE       ((uint32_t)0x00000008U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* GPTIMER_EVT_MODE[EVT2_CFG] Bits */
#define GPTIMER_EVT_MODE_EVT2_CFG_OFS            (4)                             /* !< EVT2_CFG Offset */
#define GPTIMER_EVT_MODE_EVT2_CFG_MASK           ((uint32_t)0x00000030U)         /* !< Event line mode select for event
                                                                                    corresponding to GEN_EVENT1 */
#define GPTIMER_EVT_MODE_EVT2_CFG_DISABLE        ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define GPTIMER_EVT_MODE_EVT2_CFG_SOFTWARE       ((uint32_t)0x00000010U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define GPTIMER_EVT_MODE_EVT2_CFG_HARDWARE       ((uint32_t)0x00000020U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* GPTIMER_DESC Bits */
/* GPTIMER_DESC[MINREV] Bits */
#define GPTIMER_DESC_MINREV_OFS                  (0)                             /* !< MINREV Offset */
#define GPTIMER_DESC_MINREV_MASK                 ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
#define GPTIMER_DESC_MINREV_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define GPTIMER_DESC_MINREV_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Highest possible value */
/* GPTIMER_DESC[MAJREV] Bits */
#define GPTIMER_DESC_MAJREV_OFS                  (4)                             /* !< MAJREV Offset */
#define GPTIMER_DESC_MAJREV_MASK                 ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
#define GPTIMER_DESC_MAJREV_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define GPTIMER_DESC_MAJREV_MAXIMUM              ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* GPTIMER_DESC[INSTNUM] Bits */
#define GPTIMER_DESC_INSTNUM_OFS                 (8)                             /* !< INSTNUM Offset */
#define GPTIMER_DESC_INSTNUM_MASK                ((uint32_t)0x00000F00U)         /* !< Instance Number within the device.
                                                                                    This will be a parameter to the RTL
                                                                                    for modules that can have multiple
                                                                                    instances */
#define GPTIMER_DESC_INSTNUM_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define GPTIMER_DESC_INSTNUM_MAXIMUM             ((uint32_t)0x00000F00U)         /* !< Highest possible value */
/* GPTIMER_DESC[FEATUREVER] Bits */
#define GPTIMER_DESC_FEATUREVER_OFS              (12)                            /* !< FEATUREVER Offset */
#define GPTIMER_DESC_FEATUREVER_MASK             ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
#define GPTIMER_DESC_FEATUREVER_MINIMUM          ((uint32_t)0x00000000U)         /* !< Smallest value */
#define GPTIMER_DESC_FEATUREVER_MAXIMUM          ((uint32_t)0x0000F000U)         /* !< Highest possible value */
/* GPTIMER_DESC[MODULEID] Bits */
#define GPTIMER_DESC_MODULEID_OFS                (16)                            /* !< MODULEID Offset */
#define GPTIMER_DESC_MODULEID_MASK               ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */
#define GPTIMER_DESC_MODULEID_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define GPTIMER_DESC_MODULEID_MAXIMUM            ((uint32_t)0xFFFF0000U)         /* !< Highest possible value */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_gptimer__include */

