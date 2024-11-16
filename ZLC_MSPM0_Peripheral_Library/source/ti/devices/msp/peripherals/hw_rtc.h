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

#ifndef ti_devices_msp_peripherals_hw_rtc__include
#define ti_devices_msp_peripherals_hw_rtc__include

/* Filename: hw_rtc.h */
/* Revised: 2023-11-10 23:33:05 */
/* Revision: 57bdd406cc3983634d43d73d4088fae123c0b478 */

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
* RTC Registers
******************************************************************************/
#define RTC_GEN_EVENT_OFS                        ((uint32_t)0x00001050U)
#define RTC_CPU_INT_OFS                          ((uint32_t)0x00001020U)
#define RTC_GPRCM_OFS                            ((uint32_t)0x00000800U)


/** @addtogroup RTC_GEN_EVENT
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001050) Interrupt Index Register */
  __IO uint32_t IMASK;                             /* !< (@ 0x00001054) Interrupt mask */
  __I  uint32_t RIS;                               /* !< (@ 0x00001058) Raw interrupt status */
  __I  uint32_t MIS;                               /* !< (@ 0x0000105C) Masked interrupt status */
  __O  uint32_t ISET;                              /* !< (@ 0x00001060) Interrupt set */
  __O  uint32_t ICLR;                              /* !< (@ 0x00001064) Interrupt clear */
} RTC_GEN_EVENT_Regs;

/*@}*/ /* end of group RTC_GEN_EVENT */

/** @addtogroup RTC_CPU_INT
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
} RTC_CPU_INT_Regs;

/*@}*/ /* end of group RTC_CPU_INT */

/** @addtogroup RTC_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00000808) Peripheral Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} RTC_GPRCM_Regs;

/*@}*/ /* end of group RTC_GPRCM */

/** @addtogroup RTC
  @{
*/

typedef struct {
       uint32_t RESERVED0[273];
  __IO uint32_t FPUB_0;                            /* !< (@ 0x00000444) Publisher Port 0 */
       uint32_t RESERVED1[238];
  RTC_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED2[507];
  __I  uint32_t CLKSEL;                            /* !< (@ 0x00001004) Clock Select for Ultra Low Power peripherals */
       uint32_t RESERVED3[6];
  RTC_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED4;
  RTC_GEN_EVENT_Regs  GEN_EVENT;                         /* !< (@ 0x00001050) */
       uint32_t RESERVED5[30];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED6[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) RTC Descriptor Register */
  __IO uint32_t CLKCTL;                            /* !< (@ 0x00001100) RTC Clock Control Register */
  __IO uint32_t DBGCTL;                            /* !< (@ 0x00001104) RTC Module Debug Control Register */
  __IO uint32_t CTL;                               /* !< (@ 0x00001108) RTC Control Register */
  __I  uint32_t STA;                               /* !< (@ 0x0000110C) RTC Status Register */
  __IO uint32_t CAL;                               /* !< (@ 0x00001110) RTC Clock Offset Calibration Register */
  __IO uint32_t TCMP;                              /* !< (@ 0x00001114) RTC Temperature Compensation Register */
  __IO uint32_t SEC;                               /* !< (@ 0x00001118) RTC Seconds Register - Calendar Mode With Binary /
                                                      BCD Format */
  __IO uint32_t MIN;                               /* !< (@ 0x0000111C) RTC Minutes Register - Calendar Mode With Binary /
                                                      BCD Format */
  __IO uint32_t HOUR;                              /* !< (@ 0x00001120) RTC Hours Register - Calendar Mode With Binary /
                                                      BCD Format */
  __IO uint32_t DAY;                               /* !< (@ 0x00001124) RTC Day Of Week / Month Register - Calendar Mode
                                                      With Binary / BCD Format */
  __IO uint32_t MON;                               /* !< (@ 0x00001128) RTC Month Register - Calendar Mode With Binary /
                                                      BCD Format */
  __IO uint32_t YEAR;                              /* !< (@ 0x0000112C) RTC Year Register - Calendar Mode With Binary /
                                                      BCD Format */
  __IO uint32_t A1MIN;                             /* !< (@ 0x00001130) RTC Minute Alarm Register - Calendar Mode With
                                                      Binary / BCD Format */
  __IO uint32_t A1HOUR;                            /* !< (@ 0x00001134) RTC Hours Alarm Register - Calendar Mode With
                                                      Binary / BCD Format */
  __IO uint32_t A1DAY;                             /* !< (@ 0x00001138) RTC Alarm Day Of Week / Month Register - Calendar
                                                      Mode With Binary / BCD Format */
  __IO uint32_t A2MIN;                             /* !< (@ 0x0000113C) RTC Minute Alarm Register - Calendar Mode With
                                                      Binary / BCD Format */
  __IO uint32_t A2HOUR;                            /* !< (@ 0x00001140) RTC Hours Alarm Register - Calendar Mode With
                                                      Binary / BCD Format */
  __IO uint32_t A2DAY;                             /* !< (@ 0x00001144) RTC Alarm Day Of Week / Month Register - Calendar
                                                      Mode With Binary / BCD Format */
  __IO uint32_t PSCTL;                             /* !< (@ 0x00001148) RTC Prescale Timer 0/1 Control Register */
  __IO uint32_t EXTPSCTL;                          /* !< (@ 0x0000114C) RTC Prescale Timer 2 Control Register */
  __I  uint32_t TSSEC;                             /* !< (@ 0x00001150) Time Stamp Seconds Register - Calendar Mode With
                                                      Binary / BCD Format */
  __I  uint32_t TSMIN;                             /* !< (@ 0x00001154) Time Stamp Minutes Register - Calendar Mode With
                                                      Binary / BCD Format */
  __I  uint32_t TSHOUR;                            /* !< (@ 0x00001158) Time Stamp Hours Register - Calendar Mode With
                                                      Binary / BCD Format */
  __I  uint32_t TSDAY;                             /* !< (@ 0x0000115C) Time Stamp Day Of Week / MonthRegister - Calendar
                                                      Mode With Binary / BCD Format */
  __I  uint32_t TSMON;                             /* !< (@ 0x00001160) Time Stamp Month Register - Calendar Mode With
                                                      Binary / BCD Format */
  __I  uint32_t TSYEAR;                            /* !< (@ 0x00001164) Time Stamp Years Register - Calendar Mode With
                                                      Binary / BCD Format */
  __I  uint32_t TSSTAT;                            /* !< (@ 0x00001168) Time Stamp Status Register */
  __IO uint32_t TSCTL;                             /* !< (@ 0x0000116C) Time Stamp Control Register */
  __O  uint32_t TSCLR;                             /* !< (@ 0x00001170) Time Stamp Clear Register */
  __IO uint32_t LFSSRST;                           /* !< (@ 0x00001174) Low frequency sub-system reset request */
  __IO uint32_t RTCLOCK;                           /* !< (@ 0x00001178) Real time clock lock register */
} RTC_Regs;

/*@}*/ /* end of group RTC */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* RTC Register Control Bits
******************************************************************************/

/* RTC_GEN_EVENT_IIDX Bits */
/* RTC_GEN_EVENT_IIDX[STAT] Bits */
#define RTC_GEN_EVENT_IIDX_STAT_OFS              (0)                             /* !< STAT Offset */
#define RTC_GEN_EVENT_IIDX_STAT_MASK             ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define RTC_GEN_EVENT_IIDX_STAT_NO_INTR          ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define RTC_GEN_EVENT_IIDX_STAT_RTCRDY           ((uint32_t)0x00000001U)         /* !< RTC ready */
#define RTC_GEN_EVENT_IIDX_STAT_RTCTEV           ((uint32_t)0x00000002U)         /* !< RTC time event */
#define RTC_GEN_EVENT_IIDX_STAT_RTCA1            ((uint32_t)0x00000003U)         /* !< RTC alarm 1 */
#define RTC_GEN_EVENT_IIDX_STAT_RTCA2            ((uint32_t)0x00000004U)         /* !< RTC alarm 2 */
#define RTC_GEN_EVENT_IIDX_STAT_RT0PS            ((uint32_t)0x00000005U)         /* !< RTC prescale timer 0 */
#define RTC_GEN_EVENT_IIDX_STAT_RT1PS            ((uint32_t)0x00000006U)         /* !< RTC prescale timer 1 */
#define RTC_GEN_EVENT_IIDX_STAT_RT2PS            ((uint32_t)0x00000007U)         /* !< RTC prescale timer 2 */
#define RTC_GEN_EVENT_IIDX_STAT_TSEVT            ((uint32_t)0x00000008U)         /* !< Time stamp event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO0             ((uint32_t)0x00000009U)         /* !< Tamper I/O 0 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO1             ((uint32_t)0x0000000AU)         /* !< Tamper I/O 1 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO2             ((uint32_t)0x0000000BU)         /* !< Tamper I/O 2 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO3             ((uint32_t)0x0000000CU)         /* !< Tamper I/O 3 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO4             ((uint32_t)0x0000000DU)         /* !< Tamper I/O 4 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO5             ((uint32_t)0x0000000EU)         /* !< Tamper I/O 5 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO6             ((uint32_t)0x0000000FU)         /* !< Tamper I/O 6 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO7             ((uint32_t)0x00000010U)         /* !< Tamper I/O 7 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO8             ((uint32_t)0x00000011U)         /* !< Tamper I/O 8 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO9             ((uint32_t)0x00000012U)         /* !< Tamper I/O 9 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO10            ((uint32_t)0x00000013U)         /* !< Tamper I/O 10 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO11            ((uint32_t)0x00000014U)         /* !< Tamper I/O 11 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO12            ((uint32_t)0x00000015U)         /* !< Tamper I/O 12 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO13            ((uint32_t)0x00000016U)         /* !< Tamper I/O 13 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO14            ((uint32_t)0x00000017U)         /* !< Tamper I/O 14 event */
#define RTC_GEN_EVENT_IIDX_STAT_TIO15            ((uint32_t)0x00000018U)         /* !< Tamper I/O 15 event */

/* RTC_GEN_EVENT_IMASK Bits */
/* RTC_GEN_EVENT_IMASK[RTCRDY] Bits */
#define RTC_GEN_EVENT_IMASK_RTCRDY_OFS           (0)                             /* !< RTCRDY Offset */
#define RTC_GEN_EVENT_IMASK_RTCRDY_MASK          ((uint32_t)0x00000001U)         /* !< RTC ready */
#define RTC_GEN_EVENT_IMASK_RTCRDY_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_RTCRDY_SET           ((uint32_t)0x00000001U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[RTCTEV] Bits */
#define RTC_GEN_EVENT_IMASK_RTCTEV_OFS           (1)                             /* !< RTCTEV Offset */
#define RTC_GEN_EVENT_IMASK_RTCTEV_MASK          ((uint32_t)0x00000002U)         /* !< RTC time event */
#define RTC_GEN_EVENT_IMASK_RTCTEV_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_RTCTEV_SET           ((uint32_t)0x00000002U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[RTCA1] Bits */
#define RTC_GEN_EVENT_IMASK_RTCA1_OFS            (2)                             /* !< RTCA1 Offset */
#define RTC_GEN_EVENT_IMASK_RTCA1_MASK           ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define RTC_GEN_EVENT_IMASK_RTCA1_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_RTCA1_SET            ((uint32_t)0x00000004U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[RTCA2] Bits */
#define RTC_GEN_EVENT_IMASK_RTCA2_OFS            (3)                             /* !< RTCA2 Offset */
#define RTC_GEN_EVENT_IMASK_RTCA2_MASK           ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define RTC_GEN_EVENT_IMASK_RTCA2_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_RTCA2_SET            ((uint32_t)0x00000008U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[RT0PS] Bits */
#define RTC_GEN_EVENT_IMASK_RT0PS_OFS            (4)                             /* !< RT0PS Offset */
#define RTC_GEN_EVENT_IMASK_RT0PS_MASK           ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define RTC_GEN_EVENT_IMASK_RT0PS_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_RT0PS_SET            ((uint32_t)0x00000010U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[RT1PS] Bits */
#define RTC_GEN_EVENT_IMASK_RT1PS_OFS            (5)                             /* !< RT1PS Offset */
#define RTC_GEN_EVENT_IMASK_RT1PS_MASK           ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define RTC_GEN_EVENT_IMASK_RT1PS_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_RT1PS_SET            ((uint32_t)0x00000020U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[RT2PS] Bits */
#define RTC_GEN_EVENT_IMASK_RT2PS_OFS            (6)                             /* !< RT2PS Offset */
#define RTC_GEN_EVENT_IMASK_RT2PS_MASK           ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define RTC_GEN_EVENT_IMASK_RT2PS_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_RT2PS_SET            ((uint32_t)0x00000040U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TSEVT] Bits */
#define RTC_GEN_EVENT_IMASK_TSEVT_OFS            (7)                             /* !< TSEVT Offset */
#define RTC_GEN_EVENT_IMASK_TSEVT_MASK           ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define RTC_GEN_EVENT_IMASK_TSEVT_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TSEVT_SET            ((uint32_t)0x00000080U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO0] Bits */
#define RTC_GEN_EVENT_IMASK_TIO0_OFS             (8)                             /* !< TIO0 Offset */
#define RTC_GEN_EVENT_IMASK_TIO0_MASK            ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define RTC_GEN_EVENT_IMASK_TIO0_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO0_SET             ((uint32_t)0x00000100U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO1] Bits */
#define RTC_GEN_EVENT_IMASK_TIO1_OFS             (9)                             /* !< TIO1 Offset */
#define RTC_GEN_EVENT_IMASK_TIO1_MASK            ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define RTC_GEN_EVENT_IMASK_TIO1_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO1_SET             ((uint32_t)0x00000200U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO2] Bits */
#define RTC_GEN_EVENT_IMASK_TIO2_OFS             (10)                            /* !< TIO2 Offset */
#define RTC_GEN_EVENT_IMASK_TIO2_MASK            ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define RTC_GEN_EVENT_IMASK_TIO2_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO2_SET             ((uint32_t)0x00000400U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO3] Bits */
#define RTC_GEN_EVENT_IMASK_TIO3_OFS             (11)                            /* !< TIO3 Offset */
#define RTC_GEN_EVENT_IMASK_TIO3_MASK            ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define RTC_GEN_EVENT_IMASK_TIO3_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO3_SET             ((uint32_t)0x00000800U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO4] Bits */
#define RTC_GEN_EVENT_IMASK_TIO4_OFS             (12)                            /* !< TIO4 Offset */
#define RTC_GEN_EVENT_IMASK_TIO4_MASK            ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define RTC_GEN_EVENT_IMASK_TIO4_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO4_SET             ((uint32_t)0x00001000U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO5] Bits */
#define RTC_GEN_EVENT_IMASK_TIO5_OFS             (13)                            /* !< TIO5 Offset */
#define RTC_GEN_EVENT_IMASK_TIO5_MASK            ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define RTC_GEN_EVENT_IMASK_TIO5_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO5_SET             ((uint32_t)0x00002000U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO6] Bits */
#define RTC_GEN_EVENT_IMASK_TIO6_OFS             (14)                            /* !< TIO6 Offset */
#define RTC_GEN_EVENT_IMASK_TIO6_MASK            ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define RTC_GEN_EVENT_IMASK_TIO6_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO6_SET             ((uint32_t)0x00004000U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO7] Bits */
#define RTC_GEN_EVENT_IMASK_TIO7_OFS             (15)                            /* !< TIO7 Offset */
#define RTC_GEN_EVENT_IMASK_TIO7_MASK            ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define RTC_GEN_EVENT_IMASK_TIO7_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO7_SET             ((uint32_t)0x00008000U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO8] Bits */
#define RTC_GEN_EVENT_IMASK_TIO8_OFS             (16)                            /* !< TIO8 Offset */
#define RTC_GEN_EVENT_IMASK_TIO8_MASK            ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define RTC_GEN_EVENT_IMASK_TIO8_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO8_SET             ((uint32_t)0x00010000U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO9] Bits */
#define RTC_GEN_EVENT_IMASK_TIO9_OFS             (17)                            /* !< TIO9 Offset */
#define RTC_GEN_EVENT_IMASK_TIO9_MASK            ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define RTC_GEN_EVENT_IMASK_TIO9_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO9_SET             ((uint32_t)0x00020000U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO10] Bits */
#define RTC_GEN_EVENT_IMASK_TIO10_OFS            (18)                            /* !< TIO10 Offset */
#define RTC_GEN_EVENT_IMASK_TIO10_MASK           ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define RTC_GEN_EVENT_IMASK_TIO10_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO10_SET            ((uint32_t)0x00040000U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO11] Bits */
#define RTC_GEN_EVENT_IMASK_TIO11_OFS            (19)                            /* !< TIO11 Offset */
#define RTC_GEN_EVENT_IMASK_TIO11_MASK           ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define RTC_GEN_EVENT_IMASK_TIO11_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO11_SET            ((uint32_t)0x00080000U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO12] Bits */
#define RTC_GEN_EVENT_IMASK_TIO12_OFS            (20)                            /* !< TIO12 Offset */
#define RTC_GEN_EVENT_IMASK_TIO12_MASK           ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define RTC_GEN_EVENT_IMASK_TIO12_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO12_SET            ((uint32_t)0x00100000U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO13] Bits */
#define RTC_GEN_EVENT_IMASK_TIO13_OFS            (21)                            /* !< TIO13 Offset */
#define RTC_GEN_EVENT_IMASK_TIO13_MASK           ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define RTC_GEN_EVENT_IMASK_TIO13_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO13_SET            ((uint32_t)0x00200000U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO14] Bits */
#define RTC_GEN_EVENT_IMASK_TIO14_OFS            (22)                            /* !< TIO14 Offset */
#define RTC_GEN_EVENT_IMASK_TIO14_MASK           ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define RTC_GEN_EVENT_IMASK_TIO14_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO14_SET            ((uint32_t)0x00400000U)         /* !< Set Interrrupt Mask */
/* RTC_GEN_EVENT_IMASK[TIO15] Bits */
#define RTC_GEN_EVENT_IMASK_TIO15_OFS            (23)                            /* !< TIO15 Offset */
#define RTC_GEN_EVENT_IMASK_TIO15_MASK           ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define RTC_GEN_EVENT_IMASK_TIO15_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_GEN_EVENT_IMASK_TIO15_SET            ((uint32_t)0x00800000U)         /* !< Set Interrrupt Mask */

/* RTC_GEN_EVENT_RIS Bits */
/* RTC_GEN_EVENT_RIS[RTCRDY] Bits */
#define RTC_GEN_EVENT_RIS_RTCRDY_OFS             (0)                             /* !< RTCRDY Offset */
#define RTC_GEN_EVENT_RIS_RTCRDY_MASK            ((uint32_t)0x00000001U)         /* !< RTC ready */
#define RTC_GEN_EVENT_RIS_RTCRDY_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_RTCRDY_SET             ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[RTCTEV] Bits */
#define RTC_GEN_EVENT_RIS_RTCTEV_OFS             (1)                             /* !< RTCTEV Offset */
#define RTC_GEN_EVENT_RIS_RTCTEV_MASK            ((uint32_t)0x00000002U)         /* !< RTC time event */
#define RTC_GEN_EVENT_RIS_RTCTEV_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_RTCTEV_SET             ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[RTCA1] Bits */
#define RTC_GEN_EVENT_RIS_RTCA1_OFS              (2)                             /* !< RTCA1 Offset */
#define RTC_GEN_EVENT_RIS_RTCA1_MASK             ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define RTC_GEN_EVENT_RIS_RTCA1_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_RTCA1_SET              ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[RTCA2] Bits */
#define RTC_GEN_EVENT_RIS_RTCA2_OFS              (3)                             /* !< RTCA2 Offset */
#define RTC_GEN_EVENT_RIS_RTCA2_MASK             ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define RTC_GEN_EVENT_RIS_RTCA2_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_RTCA2_SET              ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[RT0PS] Bits */
#define RTC_GEN_EVENT_RIS_RT0PS_OFS              (4)                             /* !< RT0PS Offset */
#define RTC_GEN_EVENT_RIS_RT0PS_MASK             ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define RTC_GEN_EVENT_RIS_RT0PS_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_RT0PS_SET              ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[RT1PS] Bits */
#define RTC_GEN_EVENT_RIS_RT1PS_OFS              (5)                             /* !< RT1PS Offset */
#define RTC_GEN_EVENT_RIS_RT1PS_MASK             ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define RTC_GEN_EVENT_RIS_RT1PS_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_RT1PS_SET              ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[RT2PS] Bits */
#define RTC_GEN_EVENT_RIS_RT2PS_OFS              (6)                             /* !< RT2PS Offset */
#define RTC_GEN_EVENT_RIS_RT2PS_MASK             ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define RTC_GEN_EVENT_RIS_RT2PS_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_RT2PS_SET              ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TSEVT] Bits */
#define RTC_GEN_EVENT_RIS_TSEVT_OFS              (7)                             /* !< TSEVT Offset */
#define RTC_GEN_EVENT_RIS_TSEVT_MASK             ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define RTC_GEN_EVENT_RIS_TSEVT_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TSEVT_SET              ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO0] Bits */
#define RTC_GEN_EVENT_RIS_TIO0_OFS               (8)                             /* !< TIO0 Offset */
#define RTC_GEN_EVENT_RIS_TIO0_MASK              ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define RTC_GEN_EVENT_RIS_TIO0_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO0_SET               ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO1] Bits */
#define RTC_GEN_EVENT_RIS_TIO1_OFS               (9)                             /* !< TIO1 Offset */
#define RTC_GEN_EVENT_RIS_TIO1_MASK              ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define RTC_GEN_EVENT_RIS_TIO1_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO1_SET               ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO2] Bits */
#define RTC_GEN_EVENT_RIS_TIO2_OFS               (10)                            /* !< TIO2 Offset */
#define RTC_GEN_EVENT_RIS_TIO2_MASK              ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define RTC_GEN_EVENT_RIS_TIO2_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO2_SET               ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO3] Bits */
#define RTC_GEN_EVENT_RIS_TIO3_OFS               (11)                            /* !< TIO3 Offset */
#define RTC_GEN_EVENT_RIS_TIO3_MASK              ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define RTC_GEN_EVENT_RIS_TIO3_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO3_SET               ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO4] Bits */
#define RTC_GEN_EVENT_RIS_TIO4_OFS               (12)                            /* !< TIO4 Offset */
#define RTC_GEN_EVENT_RIS_TIO4_MASK              ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define RTC_GEN_EVENT_RIS_TIO4_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO4_SET               ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO5] Bits */
#define RTC_GEN_EVENT_RIS_TIO5_OFS               (13)                            /* !< TIO5 Offset */
#define RTC_GEN_EVENT_RIS_TIO5_MASK              ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define RTC_GEN_EVENT_RIS_TIO5_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO5_SET               ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO6] Bits */
#define RTC_GEN_EVENT_RIS_TIO6_OFS               (14)                            /* !< TIO6 Offset */
#define RTC_GEN_EVENT_RIS_TIO6_MASK              ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define RTC_GEN_EVENT_RIS_TIO6_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO6_SET               ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO7] Bits */
#define RTC_GEN_EVENT_RIS_TIO7_OFS               (15)                            /* !< TIO7 Offset */
#define RTC_GEN_EVENT_RIS_TIO7_MASK              ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define RTC_GEN_EVENT_RIS_TIO7_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO7_SET               ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO8] Bits */
#define RTC_GEN_EVENT_RIS_TIO8_OFS               (16)                            /* !< TIO8 Offset */
#define RTC_GEN_EVENT_RIS_TIO8_MASK              ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define RTC_GEN_EVENT_RIS_TIO8_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO8_SET               ((uint32_t)0x00010000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO9] Bits */
#define RTC_GEN_EVENT_RIS_TIO9_OFS               (17)                            /* !< TIO9 Offset */
#define RTC_GEN_EVENT_RIS_TIO9_MASK              ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define RTC_GEN_EVENT_RIS_TIO9_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO9_SET               ((uint32_t)0x00020000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO10] Bits */
#define RTC_GEN_EVENT_RIS_TIO10_OFS              (18)                            /* !< TIO10 Offset */
#define RTC_GEN_EVENT_RIS_TIO10_MASK             ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define RTC_GEN_EVENT_RIS_TIO10_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO10_SET              ((uint32_t)0x00040000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO11] Bits */
#define RTC_GEN_EVENT_RIS_TIO11_OFS              (19)                            /* !< TIO11 Offset */
#define RTC_GEN_EVENT_RIS_TIO11_MASK             ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define RTC_GEN_EVENT_RIS_TIO11_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO11_SET              ((uint32_t)0x00080000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO12] Bits */
#define RTC_GEN_EVENT_RIS_TIO12_OFS              (20)                            /* !< TIO12 Offset */
#define RTC_GEN_EVENT_RIS_TIO12_MASK             ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define RTC_GEN_EVENT_RIS_TIO12_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO12_SET              ((uint32_t)0x00100000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO13] Bits */
#define RTC_GEN_EVENT_RIS_TIO13_OFS              (21)                            /* !< TIO13 Offset */
#define RTC_GEN_EVENT_RIS_TIO13_MASK             ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define RTC_GEN_EVENT_RIS_TIO13_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO13_SET              ((uint32_t)0x00200000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO14] Bits */
#define RTC_GEN_EVENT_RIS_TIO14_OFS              (22)                            /* !< TIO14 Offset */
#define RTC_GEN_EVENT_RIS_TIO14_MASK             ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define RTC_GEN_EVENT_RIS_TIO14_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO14_SET              ((uint32_t)0x00400000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_RIS[TIO15] Bits */
#define RTC_GEN_EVENT_RIS_TIO15_OFS              (23)                            /* !< TIO15 Offset */
#define RTC_GEN_EVENT_RIS_TIO15_MASK             ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define RTC_GEN_EVENT_RIS_TIO15_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_GEN_EVENT_RIS_TIO15_SET              ((uint32_t)0x00800000U)         /* !< Interrupt occurred */

/* RTC_GEN_EVENT_MIS Bits */
/* RTC_GEN_EVENT_MIS[RTCRDY] Bits */
#define RTC_GEN_EVENT_MIS_RTCRDY_OFS             (0)                             /* !< RTCRDY Offset */
#define RTC_GEN_EVENT_MIS_RTCRDY_MASK            ((uint32_t)0x00000001U)         /* !< RTC ready */
#define RTC_GEN_EVENT_MIS_RTCRDY_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_RTCRDY_SET             ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[RTCTEV] Bits */
#define RTC_GEN_EVENT_MIS_RTCTEV_OFS             (1)                             /* !< RTCTEV Offset */
#define RTC_GEN_EVENT_MIS_RTCTEV_MASK            ((uint32_t)0x00000002U)         /* !< RTC time event */
#define RTC_GEN_EVENT_MIS_RTCTEV_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_RTCTEV_SET             ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[RTCA1] Bits */
#define RTC_GEN_EVENT_MIS_RTCA1_OFS              (2)                             /* !< RTCA1 Offset */
#define RTC_GEN_EVENT_MIS_RTCA1_MASK             ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define RTC_GEN_EVENT_MIS_RTCA1_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_RTCA1_SET              ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[RTCA2] Bits */
#define RTC_GEN_EVENT_MIS_RTCA2_OFS              (3)                             /* !< RTCA2 Offset */
#define RTC_GEN_EVENT_MIS_RTCA2_MASK             ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define RTC_GEN_EVENT_MIS_RTCA2_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_RTCA2_SET              ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[RT0PS] Bits */
#define RTC_GEN_EVENT_MIS_RT0PS_OFS              (4)                             /* !< RT0PS Offset */
#define RTC_GEN_EVENT_MIS_RT0PS_MASK             ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define RTC_GEN_EVENT_MIS_RT0PS_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_RT0PS_SET              ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[RT1PS] Bits */
#define RTC_GEN_EVENT_MIS_RT1PS_OFS              (5)                             /* !< RT1PS Offset */
#define RTC_GEN_EVENT_MIS_RT1PS_MASK             ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define RTC_GEN_EVENT_MIS_RT1PS_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_RT1PS_SET              ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[RT2PS] Bits */
#define RTC_GEN_EVENT_MIS_RT2PS_OFS              (6)                             /* !< RT2PS Offset */
#define RTC_GEN_EVENT_MIS_RT2PS_MASK             ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define RTC_GEN_EVENT_MIS_RT2PS_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_RT2PS_SET              ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TSEVT] Bits */
#define RTC_GEN_EVENT_MIS_TSEVT_OFS              (7)                             /* !< TSEVT Offset */
#define RTC_GEN_EVENT_MIS_TSEVT_MASK             ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define RTC_GEN_EVENT_MIS_TSEVT_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TSEVT_SET              ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO0] Bits */
#define RTC_GEN_EVENT_MIS_TIO0_OFS               (8)                             /* !< TIO0 Offset */
#define RTC_GEN_EVENT_MIS_TIO0_MASK              ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define RTC_GEN_EVENT_MIS_TIO0_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO0_SET               ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO1] Bits */
#define RTC_GEN_EVENT_MIS_TIO1_OFS               (9)                             /* !< TIO1 Offset */
#define RTC_GEN_EVENT_MIS_TIO1_MASK              ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define RTC_GEN_EVENT_MIS_TIO1_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO1_SET               ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO2] Bits */
#define RTC_GEN_EVENT_MIS_TIO2_OFS               (10)                            /* !< TIO2 Offset */
#define RTC_GEN_EVENT_MIS_TIO2_MASK              ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define RTC_GEN_EVENT_MIS_TIO2_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO2_SET               ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO3] Bits */
#define RTC_GEN_EVENT_MIS_TIO3_OFS               (11)                            /* !< TIO3 Offset */
#define RTC_GEN_EVENT_MIS_TIO3_MASK              ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define RTC_GEN_EVENT_MIS_TIO3_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO3_SET               ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO4] Bits */
#define RTC_GEN_EVENT_MIS_TIO4_OFS               (12)                            /* !< TIO4 Offset */
#define RTC_GEN_EVENT_MIS_TIO4_MASK              ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define RTC_GEN_EVENT_MIS_TIO4_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO4_SET               ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO5] Bits */
#define RTC_GEN_EVENT_MIS_TIO5_OFS               (13)                            /* !< TIO5 Offset */
#define RTC_GEN_EVENT_MIS_TIO5_MASK              ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define RTC_GEN_EVENT_MIS_TIO5_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO5_SET               ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO6] Bits */
#define RTC_GEN_EVENT_MIS_TIO6_OFS               (14)                            /* !< TIO6 Offset */
#define RTC_GEN_EVENT_MIS_TIO6_MASK              ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define RTC_GEN_EVENT_MIS_TIO6_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO6_SET               ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO7] Bits */
#define RTC_GEN_EVENT_MIS_TIO7_OFS               (15)                            /* !< TIO7 Offset */
#define RTC_GEN_EVENT_MIS_TIO7_MASK              ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define RTC_GEN_EVENT_MIS_TIO7_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO7_SET               ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO8] Bits */
#define RTC_GEN_EVENT_MIS_TIO8_OFS               (16)                            /* !< TIO8 Offset */
#define RTC_GEN_EVENT_MIS_TIO8_MASK              ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define RTC_GEN_EVENT_MIS_TIO8_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO8_SET               ((uint32_t)0x00010000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO9] Bits */
#define RTC_GEN_EVENT_MIS_TIO9_OFS               (17)                            /* !< TIO9 Offset */
#define RTC_GEN_EVENT_MIS_TIO9_MASK              ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define RTC_GEN_EVENT_MIS_TIO9_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO9_SET               ((uint32_t)0x00020000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO10] Bits */
#define RTC_GEN_EVENT_MIS_TIO10_OFS              (18)                            /* !< TIO10 Offset */
#define RTC_GEN_EVENT_MIS_TIO10_MASK             ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define RTC_GEN_EVENT_MIS_TIO10_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO10_SET              ((uint32_t)0x00040000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO11] Bits */
#define RTC_GEN_EVENT_MIS_TIO11_OFS              (19)                            /* !< TIO11 Offset */
#define RTC_GEN_EVENT_MIS_TIO11_MASK             ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define RTC_GEN_EVENT_MIS_TIO11_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO11_SET              ((uint32_t)0x00080000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO12] Bits */
#define RTC_GEN_EVENT_MIS_TIO12_OFS              (20)                            /* !< TIO12 Offset */
#define RTC_GEN_EVENT_MIS_TIO12_MASK             ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define RTC_GEN_EVENT_MIS_TIO12_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO12_SET              ((uint32_t)0x00100000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO13] Bits */
#define RTC_GEN_EVENT_MIS_TIO13_OFS              (21)                            /* !< TIO13 Offset */
#define RTC_GEN_EVENT_MIS_TIO13_MASK             ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define RTC_GEN_EVENT_MIS_TIO13_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO13_SET              ((uint32_t)0x00200000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO14] Bits */
#define RTC_GEN_EVENT_MIS_TIO14_OFS              (22)                            /* !< TIO14 Offset */
#define RTC_GEN_EVENT_MIS_TIO14_MASK             ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define RTC_GEN_EVENT_MIS_TIO14_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO14_SET              ((uint32_t)0x00400000U)         /* !< Interrupt occurred */
/* RTC_GEN_EVENT_MIS[TIO15] Bits */
#define RTC_GEN_EVENT_MIS_TIO15_OFS              (23)                            /* !< TIO15 Offset */
#define RTC_GEN_EVENT_MIS_TIO15_MASK             ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define RTC_GEN_EVENT_MIS_TIO15_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_GEN_EVENT_MIS_TIO15_SET              ((uint32_t)0x00800000U)         /* !< Interrupt occurred */

/* RTC_GEN_EVENT_ISET Bits */
/* RTC_GEN_EVENT_ISET[RTCRDY] Bits */
#define RTC_GEN_EVENT_ISET_RTCRDY_OFS            (0)                             /* !< RTCRDY Offset */
#define RTC_GEN_EVENT_ISET_RTCRDY_MASK           ((uint32_t)0x00000001U)         /* !< RTC ready */
#define RTC_GEN_EVENT_ISET_RTCRDY_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_RTCRDY_SET            ((uint32_t)0x00000001U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[RTCTEV] Bits */
#define RTC_GEN_EVENT_ISET_RTCTEV_OFS            (1)                             /* !< RTCTEV Offset */
#define RTC_GEN_EVENT_ISET_RTCTEV_MASK           ((uint32_t)0x00000002U)         /* !< RTC time event */
#define RTC_GEN_EVENT_ISET_RTCTEV_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_RTCTEV_SET            ((uint32_t)0x00000002U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[RTCA1] Bits */
#define RTC_GEN_EVENT_ISET_RTCA1_OFS             (2)                             /* !< RTCA1 Offset */
#define RTC_GEN_EVENT_ISET_RTCA1_MASK            ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define RTC_GEN_EVENT_ISET_RTCA1_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_RTCA1_SET             ((uint32_t)0x00000004U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[RTCA2] Bits */
#define RTC_GEN_EVENT_ISET_RTCA2_OFS             (3)                             /* !< RTCA2 Offset */
#define RTC_GEN_EVENT_ISET_RTCA2_MASK            ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define RTC_GEN_EVENT_ISET_RTCA2_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_RTCA2_SET             ((uint32_t)0x00000008U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[RT0PS] Bits */
#define RTC_GEN_EVENT_ISET_RT0PS_OFS             (4)                             /* !< RT0PS Offset */
#define RTC_GEN_EVENT_ISET_RT0PS_MASK            ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define RTC_GEN_EVENT_ISET_RT0PS_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_RT0PS_SET             ((uint32_t)0x00000010U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[RT1PS] Bits */
#define RTC_GEN_EVENT_ISET_RT1PS_OFS             (5)                             /* !< RT1PS Offset */
#define RTC_GEN_EVENT_ISET_RT1PS_MASK            ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define RTC_GEN_EVENT_ISET_RT1PS_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_RT1PS_SET             ((uint32_t)0x00000020U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[RT2PS] Bits */
#define RTC_GEN_EVENT_ISET_RT2PS_OFS             (6)                             /* !< RT2PS Offset */
#define RTC_GEN_EVENT_ISET_RT2PS_MASK            ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define RTC_GEN_EVENT_ISET_RT2PS_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_RT2PS_SET             ((uint32_t)0x00000040U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TSEVT] Bits */
#define RTC_GEN_EVENT_ISET_TSEVT_OFS             (7)                             /* !< TSEVT Offset */
#define RTC_GEN_EVENT_ISET_TSEVT_MASK            ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define RTC_GEN_EVENT_ISET_TSEVT_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TSEVT_SET             ((uint32_t)0x00000080U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO0] Bits */
#define RTC_GEN_EVENT_ISET_TIO0_OFS              (8)                             /* !< TIO0 Offset */
#define RTC_GEN_EVENT_ISET_TIO0_MASK             ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define RTC_GEN_EVENT_ISET_TIO0_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO0_SET              ((uint32_t)0x00000100U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO1] Bits */
#define RTC_GEN_EVENT_ISET_TIO1_OFS              (9)                             /* !< TIO1 Offset */
#define RTC_GEN_EVENT_ISET_TIO1_MASK             ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define RTC_GEN_EVENT_ISET_TIO1_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO1_SET              ((uint32_t)0x00000200U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO2] Bits */
#define RTC_GEN_EVENT_ISET_TIO2_OFS              (10)                            /* !< TIO2 Offset */
#define RTC_GEN_EVENT_ISET_TIO2_MASK             ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define RTC_GEN_EVENT_ISET_TIO2_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO2_SET              ((uint32_t)0x00000400U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO3] Bits */
#define RTC_GEN_EVENT_ISET_TIO3_OFS              (11)                            /* !< TIO3 Offset */
#define RTC_GEN_EVENT_ISET_TIO3_MASK             ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define RTC_GEN_EVENT_ISET_TIO3_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO3_SET              ((uint32_t)0x00000800U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO4] Bits */
#define RTC_GEN_EVENT_ISET_TIO4_OFS              (12)                            /* !< TIO4 Offset */
#define RTC_GEN_EVENT_ISET_TIO4_MASK             ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define RTC_GEN_EVENT_ISET_TIO4_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO4_SET              ((uint32_t)0x00001000U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO5] Bits */
#define RTC_GEN_EVENT_ISET_TIO5_OFS              (13)                            /* !< TIO5 Offset */
#define RTC_GEN_EVENT_ISET_TIO5_MASK             ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define RTC_GEN_EVENT_ISET_TIO5_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO5_SET              ((uint32_t)0x00002000U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO6] Bits */
#define RTC_GEN_EVENT_ISET_TIO6_OFS              (14)                            /* !< TIO6 Offset */
#define RTC_GEN_EVENT_ISET_TIO6_MASK             ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define RTC_GEN_EVENT_ISET_TIO6_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO6_SET              ((uint32_t)0x00004000U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO7] Bits */
#define RTC_GEN_EVENT_ISET_TIO7_OFS              (15)                            /* !< TIO7 Offset */
#define RTC_GEN_EVENT_ISET_TIO7_MASK             ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define RTC_GEN_EVENT_ISET_TIO7_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO7_SET              ((uint32_t)0x00008000U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO8] Bits */
#define RTC_GEN_EVENT_ISET_TIO8_OFS              (16)                            /* !< TIO8 Offset */
#define RTC_GEN_EVENT_ISET_TIO8_MASK             ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define RTC_GEN_EVENT_ISET_TIO8_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO8_SET              ((uint32_t)0x00010000U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO9] Bits */
#define RTC_GEN_EVENT_ISET_TIO9_OFS              (17)                            /* !< TIO9 Offset */
#define RTC_GEN_EVENT_ISET_TIO9_MASK             ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define RTC_GEN_EVENT_ISET_TIO9_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO9_SET              ((uint32_t)0x00020000U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO10] Bits */
#define RTC_GEN_EVENT_ISET_TIO10_OFS             (18)                            /* !< TIO10 Offset */
#define RTC_GEN_EVENT_ISET_TIO10_MASK            ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define RTC_GEN_EVENT_ISET_TIO10_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO10_SET             ((uint32_t)0x00040000U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO11] Bits */
#define RTC_GEN_EVENT_ISET_TIO11_OFS             (19)                            /* !< TIO11 Offset */
#define RTC_GEN_EVENT_ISET_TIO11_MASK            ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define RTC_GEN_EVENT_ISET_TIO11_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO11_SET             ((uint32_t)0x00080000U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO12] Bits */
#define RTC_GEN_EVENT_ISET_TIO12_OFS             (20)                            /* !< TIO12 Offset */
#define RTC_GEN_EVENT_ISET_TIO12_MASK            ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define RTC_GEN_EVENT_ISET_TIO12_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO12_SET             ((uint32_t)0x00100000U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO13] Bits */
#define RTC_GEN_EVENT_ISET_TIO13_OFS             (21)                            /* !< TIO13 Offset */
#define RTC_GEN_EVENT_ISET_TIO13_MASK            ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define RTC_GEN_EVENT_ISET_TIO13_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO13_SET             ((uint32_t)0x00200000U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO14] Bits */
#define RTC_GEN_EVENT_ISET_TIO14_OFS             (22)                            /* !< TIO14 Offset */
#define RTC_GEN_EVENT_ISET_TIO14_MASK            ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define RTC_GEN_EVENT_ISET_TIO14_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO14_SET             ((uint32_t)0x00400000U)         /* !< Set interrupt */
/* RTC_GEN_EVENT_ISET[TIO15] Bits */
#define RTC_GEN_EVENT_ISET_TIO15_OFS             (23)                            /* !< TIO15 Offset */
#define RTC_GEN_EVENT_ISET_TIO15_MASK            ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define RTC_GEN_EVENT_ISET_TIO15_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ISET_TIO15_SET             ((uint32_t)0x00800000U)         /* !< Set interrupt */

/* RTC_GEN_EVENT_ICLR Bits */
/* RTC_GEN_EVENT_ICLR[RTCRDY] Bits */
#define RTC_GEN_EVENT_ICLR_RTCRDY_OFS            (0)                             /* !< RTCRDY Offset */
#define RTC_GEN_EVENT_ICLR_RTCRDY_MASK           ((uint32_t)0x00000001U)         /* !< RTC ready */
#define RTC_GEN_EVENT_ICLR_RTCRDY_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_RTCRDY_CLR            ((uint32_t)0x00000001U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[RTCTEV] Bits */
#define RTC_GEN_EVENT_ICLR_RTCTEV_OFS            (1)                             /* !< RTCTEV Offset */
#define RTC_GEN_EVENT_ICLR_RTCTEV_MASK           ((uint32_t)0x00000002U)         /* !< RTC time event */
#define RTC_GEN_EVENT_ICLR_RTCTEV_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_RTCTEV_CLR            ((uint32_t)0x00000002U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[RTCA1] Bits */
#define RTC_GEN_EVENT_ICLR_RTCA1_OFS             (2)                             /* !< RTCA1 Offset */
#define RTC_GEN_EVENT_ICLR_RTCA1_MASK            ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define RTC_GEN_EVENT_ICLR_RTCA1_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_RTCA1_CLR             ((uint32_t)0x00000004U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[RTCA2] Bits */
#define RTC_GEN_EVENT_ICLR_RTCA2_OFS             (3)                             /* !< RTCA2 Offset */
#define RTC_GEN_EVENT_ICLR_RTCA2_MASK            ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define RTC_GEN_EVENT_ICLR_RTCA2_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_RTCA2_CLR             ((uint32_t)0x00000008U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[RT0PS] Bits */
#define RTC_GEN_EVENT_ICLR_RT0PS_OFS             (4)                             /* !< RT0PS Offset */
#define RTC_GEN_EVENT_ICLR_RT0PS_MASK            ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define RTC_GEN_EVENT_ICLR_RT0PS_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_RT0PS_CLR             ((uint32_t)0x00000010U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[RT1PS] Bits */
#define RTC_GEN_EVENT_ICLR_RT1PS_OFS             (5)                             /* !< RT1PS Offset */
#define RTC_GEN_EVENT_ICLR_RT1PS_MASK            ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define RTC_GEN_EVENT_ICLR_RT1PS_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_RT1PS_CLR             ((uint32_t)0x00000020U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[RT2PS] Bits */
#define RTC_GEN_EVENT_ICLR_RT2PS_OFS             (6)                             /* !< RT2PS Offset */
#define RTC_GEN_EVENT_ICLR_RT2PS_MASK            ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define RTC_GEN_EVENT_ICLR_RT2PS_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_RT2PS_CLR             ((uint32_t)0x00000040U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TSEVT] Bits */
#define RTC_GEN_EVENT_ICLR_TSEVT_OFS             (7)                             /* !< TSEVT Offset */
#define RTC_GEN_EVENT_ICLR_TSEVT_MASK            ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define RTC_GEN_EVENT_ICLR_TSEVT_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TSEVT_CLR             ((uint32_t)0x00000080U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO0] Bits */
#define RTC_GEN_EVENT_ICLR_TIO0_OFS              (8)                             /* !< TIO0 Offset */
#define RTC_GEN_EVENT_ICLR_TIO0_MASK             ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define RTC_GEN_EVENT_ICLR_TIO0_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO0_CLR              ((uint32_t)0x00000100U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO1] Bits */
#define RTC_GEN_EVENT_ICLR_TIO1_OFS              (9)                             /* !< TIO1 Offset */
#define RTC_GEN_EVENT_ICLR_TIO1_MASK             ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define RTC_GEN_EVENT_ICLR_TIO1_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO1_CLR              ((uint32_t)0x00000200U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO2] Bits */
#define RTC_GEN_EVENT_ICLR_TIO2_OFS              (10)                            /* !< TIO2 Offset */
#define RTC_GEN_EVENT_ICLR_TIO2_MASK             ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define RTC_GEN_EVENT_ICLR_TIO2_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO2_CLR              ((uint32_t)0x00000400U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO3] Bits */
#define RTC_GEN_EVENT_ICLR_TIO3_OFS              (11)                            /* !< TIO3 Offset */
#define RTC_GEN_EVENT_ICLR_TIO3_MASK             ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define RTC_GEN_EVENT_ICLR_TIO3_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO3_CLR              ((uint32_t)0x00000800U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO4] Bits */
#define RTC_GEN_EVENT_ICLR_TIO4_OFS              (12)                            /* !< TIO4 Offset */
#define RTC_GEN_EVENT_ICLR_TIO4_MASK             ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define RTC_GEN_EVENT_ICLR_TIO4_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO4_CLR              ((uint32_t)0x00001000U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO5] Bits */
#define RTC_GEN_EVENT_ICLR_TIO5_OFS              (13)                            /* !< TIO5 Offset */
#define RTC_GEN_EVENT_ICLR_TIO5_MASK             ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define RTC_GEN_EVENT_ICLR_TIO5_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO5_CLR              ((uint32_t)0x00002000U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO6] Bits */
#define RTC_GEN_EVENT_ICLR_TIO6_OFS              (14)                            /* !< TIO6 Offset */
#define RTC_GEN_EVENT_ICLR_TIO6_MASK             ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define RTC_GEN_EVENT_ICLR_TIO6_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO6_CLR              ((uint32_t)0x00004000U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO7] Bits */
#define RTC_GEN_EVENT_ICLR_TIO7_OFS              (15)                            /* !< TIO7 Offset */
#define RTC_GEN_EVENT_ICLR_TIO7_MASK             ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define RTC_GEN_EVENT_ICLR_TIO7_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO7_CLR              ((uint32_t)0x00008000U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO8] Bits */
#define RTC_GEN_EVENT_ICLR_TIO8_OFS              (16)                            /* !< TIO8 Offset */
#define RTC_GEN_EVENT_ICLR_TIO8_MASK             ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define RTC_GEN_EVENT_ICLR_TIO8_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO8_CLR              ((uint32_t)0x00010000U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO9] Bits */
#define RTC_GEN_EVENT_ICLR_TIO9_OFS              (17)                            /* !< TIO9 Offset */
#define RTC_GEN_EVENT_ICLR_TIO9_MASK             ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define RTC_GEN_EVENT_ICLR_TIO9_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO9_CLR              ((uint32_t)0x00020000U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO10] Bits */
#define RTC_GEN_EVENT_ICLR_TIO10_OFS             (18)                            /* !< TIO10 Offset */
#define RTC_GEN_EVENT_ICLR_TIO10_MASK            ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define RTC_GEN_EVENT_ICLR_TIO10_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO10_CLR             ((uint32_t)0x00040000U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO11] Bits */
#define RTC_GEN_EVENT_ICLR_TIO11_OFS             (19)                            /* !< TIO11 Offset */
#define RTC_GEN_EVENT_ICLR_TIO11_MASK            ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define RTC_GEN_EVENT_ICLR_TIO11_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO11_CLR             ((uint32_t)0x00080000U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO12] Bits */
#define RTC_GEN_EVENT_ICLR_TIO12_OFS             (20)                            /* !< TIO12 Offset */
#define RTC_GEN_EVENT_ICLR_TIO12_MASK            ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define RTC_GEN_EVENT_ICLR_TIO12_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO12_CLR             ((uint32_t)0x00100000U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO13] Bits */
#define RTC_GEN_EVENT_ICLR_TIO13_OFS             (21)                            /* !< TIO13 Offset */
#define RTC_GEN_EVENT_ICLR_TIO13_MASK            ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define RTC_GEN_EVENT_ICLR_TIO13_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO13_CLR             ((uint32_t)0x00200000U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO14] Bits */
#define RTC_GEN_EVENT_ICLR_TIO14_OFS             (22)                            /* !< TIO14 Offset */
#define RTC_GEN_EVENT_ICLR_TIO14_MASK            ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define RTC_GEN_EVENT_ICLR_TIO14_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO14_CLR             ((uint32_t)0x00400000U)         /* !< Clear interrupt */
/* RTC_GEN_EVENT_ICLR[TIO15] Bits */
#define RTC_GEN_EVENT_ICLR_TIO15_OFS             (23)                            /* !< TIO15 Offset */
#define RTC_GEN_EVENT_ICLR_TIO15_MASK            ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define RTC_GEN_EVENT_ICLR_TIO15_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_GEN_EVENT_ICLR_TIO15_CLR             ((uint32_t)0x00800000U)         /* !< Clear interrupt */

/* RTC_CPU_INT_IIDX Bits */
/* RTC_CPU_INT_IIDX[STAT] Bits */
#define RTC_CPU_INT_IIDX_STAT_OFS                (0)                             /* !< STAT Offset */
#define RTC_CPU_INT_IIDX_STAT_MASK               ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define RTC_CPU_INT_IIDX_STAT_NO_INTR            ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define RTC_CPU_INT_IIDX_STAT_RTCRDY             ((uint32_t)0x00000001U)         /* !< RTC-Ready interrupt; Interrupt
                                                                                    flag: RTCRDY */
#define RTC_CPU_INT_IIDX_STAT_RTCTEV             ((uint32_t)0x00000002U)         /* !< Time-Event interrupt; Interrupt
                                                                                    flag: RTCTEV */
#define RTC_CPU_INT_IIDX_STAT_RTCA1              ((uint32_t)0x00000003U)         /* !< Alarm-1 interrupt; Interrupt flag:
                                                                                    RTCA1 */
#define RTC_CPU_INT_IIDX_STAT_RTCA2              ((uint32_t)0x00000004U)         /* !< Alarm-2 interrupt; Interrupt flag:
                                                                                    RTCA2 */
#define RTC_CPU_INT_IIDX_STAT_RT0PS              ((uint32_t)0x00000005U)         /* !< Prescaler-0 interrupt; Interrupt
                                                                                    flag: RT0PS */
#define RTC_CPU_INT_IIDX_STAT_RT1PS              ((uint32_t)0x00000006U)         /* !< Prescaler-1 interrupt; Interrupt
                                                                                    flag: RT1PS */
#define RTC_CPU_INT_IIDX_STAT_RT2PS              ((uint32_t)0x00000007U)         /* !< RTC prescale timer 2 */
#define RTC_CPU_INT_IIDX_STAT_TSEVT              ((uint32_t)0x00000008U)         /* !< Time stamp event */
#define RTC_CPU_INT_IIDX_STAT_TIO0               ((uint32_t)0x00000009U)         /* !< Tamper I/O 0 event */
#define RTC_CPU_INT_IIDX_STAT_TIO1               ((uint32_t)0x0000000AU)         /* !< Tamper I/O 1 event */
#define RTC_CPU_INT_IIDX_STAT_TIO2               ((uint32_t)0x0000000BU)         /* !< Tamper I/O 2 event */
#define RTC_CPU_INT_IIDX_STAT_TIO3               ((uint32_t)0x0000000CU)         /* !< Tamper I/O 3 event */
#define RTC_CPU_INT_IIDX_STAT_TIO4               ((uint32_t)0x0000000DU)         /* !< Tamper I/O 4 event */
#define RTC_CPU_INT_IIDX_STAT_TIO5               ((uint32_t)0x0000000EU)         /* !< Tamper I/O 5 event */
#define RTC_CPU_INT_IIDX_STAT_TIO6               ((uint32_t)0x0000000FU)         /* !< Tamper I/O 6 event */
#define RTC_CPU_INT_IIDX_STAT_TIO7               ((uint32_t)0x00000010U)         /* !< Tamper I/O 7 event */
#define RTC_CPU_INT_IIDX_STAT_TIO8               ((uint32_t)0x00000011U)         /* !< Tamper I/O 8 event */
#define RTC_CPU_INT_IIDX_STAT_TIO9               ((uint32_t)0x00000012U)         /* !< Tamper I/O 9 event */
#define RTC_CPU_INT_IIDX_STAT_TIO10              ((uint32_t)0x00000013U)         /* !< Tamper I/O 10 event */
#define RTC_CPU_INT_IIDX_STAT_TIO11              ((uint32_t)0x00000014U)         /* !< Tamper I/O 11 event */
#define RTC_CPU_INT_IIDX_STAT_TIO12              ((uint32_t)0x00000015U)         /* !< Tamper I/O 12 event */
#define RTC_CPU_INT_IIDX_STAT_TIO13              ((uint32_t)0x00000016U)         /* !< Tamper I/O 13 event */
#define RTC_CPU_INT_IIDX_STAT_TIO14              ((uint32_t)0x00000017U)         /* !< Tamper I/O 14 event */
#define RTC_CPU_INT_IIDX_STAT_TIO15              ((uint32_t)0x00000018U)         /* !< Tamper I/O 15 event */

/* RTC_CPU_INT_IMASK Bits */
/* RTC_CPU_INT_IMASK[RTCA2] Bits */
#define RTC_CPU_INT_IMASK_RTCA2_OFS              (3)                             /* !< RTCA2 Offset */
#define RTC_CPU_INT_IMASK_RTCA2_MASK             ((uint32_t)0x00000008U)         /* !< Enable Alarm-2 interrupt */
#define RTC_CPU_INT_IMASK_RTCA2_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_RTCA2_SET              ((uint32_t)0x00000008U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[RT0PS] Bits */
#define RTC_CPU_INT_IMASK_RT0PS_OFS              (4)                             /* !< RT0PS Offset */
#define RTC_CPU_INT_IMASK_RT0PS_MASK             ((uint32_t)0x00000010U)         /* !< Enable Prescaler-0 interrupt */
#define RTC_CPU_INT_IMASK_RT0PS_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_RT0PS_SET              ((uint32_t)0x00000010U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[RT1PS] Bits */
#define RTC_CPU_INT_IMASK_RT1PS_OFS              (5)                             /* !< RT1PS Offset */
#define RTC_CPU_INT_IMASK_RT1PS_MASK             ((uint32_t)0x00000020U)         /* !< Enable Prescaler-1 interrupt */
#define RTC_CPU_INT_IMASK_RT1PS_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_RT1PS_SET              ((uint32_t)0x00000020U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[RTCTEV] Bits */
#define RTC_CPU_INT_IMASK_RTCTEV_OFS             (1)                             /* !< RTCTEV Offset */
#define RTC_CPU_INT_IMASK_RTCTEV_MASK            ((uint32_t)0x00000002U)         /* !< Enable Time-Event interrupt */
#define RTC_CPU_INT_IMASK_RTCTEV_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_RTCTEV_SET             ((uint32_t)0x00000002U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[RTCRDY] Bits */
#define RTC_CPU_INT_IMASK_RTCRDY_OFS             (0)                             /* !< RTCRDY Offset */
#define RTC_CPU_INT_IMASK_RTCRDY_MASK            ((uint32_t)0x00000001U)         /* !< Enable RTC-Ready interrupt */
#define RTC_CPU_INT_IMASK_RTCRDY_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_RTCRDY_SET             ((uint32_t)0x00000001U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[RTCA1] Bits */
#define RTC_CPU_INT_IMASK_RTCA1_OFS              (2)                             /* !< RTCA1 Offset */
#define RTC_CPU_INT_IMASK_RTCA1_MASK             ((uint32_t)0x00000004U)         /* !< Enable Alarm-1 interrupt */
#define RTC_CPU_INT_IMASK_RTCA1_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_RTCA1_SET              ((uint32_t)0x00000004U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[RT2PS] Bits */
#define RTC_CPU_INT_IMASK_RT2PS_OFS              (6)                             /* !< RT2PS Offset */
#define RTC_CPU_INT_IMASK_RT2PS_MASK             ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define RTC_CPU_INT_IMASK_RT2PS_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_RT2PS_SET              ((uint32_t)0x00000040U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TSEVT] Bits */
#define RTC_CPU_INT_IMASK_TSEVT_OFS              (7)                             /* !< TSEVT Offset */
#define RTC_CPU_INT_IMASK_TSEVT_MASK             ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define RTC_CPU_INT_IMASK_TSEVT_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TSEVT_SET              ((uint32_t)0x00000080U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO0] Bits */
#define RTC_CPU_INT_IMASK_TIO0_OFS               (8)                             /* !< TIO0 Offset */
#define RTC_CPU_INT_IMASK_TIO0_MASK              ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define RTC_CPU_INT_IMASK_TIO0_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO0_SET               ((uint32_t)0x00000100U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO1] Bits */
#define RTC_CPU_INT_IMASK_TIO1_OFS               (9)                             /* !< TIO1 Offset */
#define RTC_CPU_INT_IMASK_TIO1_MASK              ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define RTC_CPU_INT_IMASK_TIO1_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO1_SET               ((uint32_t)0x00000200U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO2] Bits */
#define RTC_CPU_INT_IMASK_TIO2_OFS               (10)                            /* !< TIO2 Offset */
#define RTC_CPU_INT_IMASK_TIO2_MASK              ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define RTC_CPU_INT_IMASK_TIO2_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO2_SET               ((uint32_t)0x00000400U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO3] Bits */
#define RTC_CPU_INT_IMASK_TIO3_OFS               (11)                            /* !< TIO3 Offset */
#define RTC_CPU_INT_IMASK_TIO3_MASK              ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define RTC_CPU_INT_IMASK_TIO3_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO3_SET               ((uint32_t)0x00000800U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO4] Bits */
#define RTC_CPU_INT_IMASK_TIO4_OFS               (12)                            /* !< TIO4 Offset */
#define RTC_CPU_INT_IMASK_TIO4_MASK              ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define RTC_CPU_INT_IMASK_TIO4_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO4_SET               ((uint32_t)0x00001000U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO5] Bits */
#define RTC_CPU_INT_IMASK_TIO5_OFS               (13)                            /* !< TIO5 Offset */
#define RTC_CPU_INT_IMASK_TIO5_MASK              ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define RTC_CPU_INT_IMASK_TIO5_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO5_SET               ((uint32_t)0x00002000U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO6] Bits */
#define RTC_CPU_INT_IMASK_TIO6_OFS               (14)                            /* !< TIO6 Offset */
#define RTC_CPU_INT_IMASK_TIO6_MASK              ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define RTC_CPU_INT_IMASK_TIO6_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO6_SET               ((uint32_t)0x00004000U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO7] Bits */
#define RTC_CPU_INT_IMASK_TIO7_OFS               (15)                            /* !< TIO7 Offset */
#define RTC_CPU_INT_IMASK_TIO7_MASK              ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define RTC_CPU_INT_IMASK_TIO7_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO7_SET               ((uint32_t)0x00008000U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO8] Bits */
#define RTC_CPU_INT_IMASK_TIO8_OFS               (16)                            /* !< TIO8 Offset */
#define RTC_CPU_INT_IMASK_TIO8_MASK              ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define RTC_CPU_INT_IMASK_TIO8_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO8_SET               ((uint32_t)0x00010000U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO9] Bits */
#define RTC_CPU_INT_IMASK_TIO9_OFS               (17)                            /* !< TIO9 Offset */
#define RTC_CPU_INT_IMASK_TIO9_MASK              ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define RTC_CPU_INT_IMASK_TIO9_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO9_SET               ((uint32_t)0x00020000U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO10] Bits */
#define RTC_CPU_INT_IMASK_TIO10_OFS              (18)                            /* !< TIO10 Offset */
#define RTC_CPU_INT_IMASK_TIO10_MASK             ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define RTC_CPU_INT_IMASK_TIO10_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO10_SET              ((uint32_t)0x00040000U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO11] Bits */
#define RTC_CPU_INT_IMASK_TIO11_OFS              (19)                            /* !< TIO11 Offset */
#define RTC_CPU_INT_IMASK_TIO11_MASK             ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define RTC_CPU_INT_IMASK_TIO11_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO11_SET              ((uint32_t)0x00080000U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO12] Bits */
#define RTC_CPU_INT_IMASK_TIO12_OFS              (20)                            /* !< TIO12 Offset */
#define RTC_CPU_INT_IMASK_TIO12_MASK             ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define RTC_CPU_INT_IMASK_TIO12_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO12_SET              ((uint32_t)0x00100000U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO13] Bits */
#define RTC_CPU_INT_IMASK_TIO13_OFS              (21)                            /* !< TIO13 Offset */
#define RTC_CPU_INT_IMASK_TIO13_MASK             ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define RTC_CPU_INT_IMASK_TIO13_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO13_SET              ((uint32_t)0x00200000U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO14] Bits */
#define RTC_CPU_INT_IMASK_TIO14_OFS              (22)                            /* !< TIO14 Offset */
#define RTC_CPU_INT_IMASK_TIO14_MASK             ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define RTC_CPU_INT_IMASK_TIO14_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO14_SET              ((uint32_t)0x00400000U)         /* !< Set Interrrupt Mask */
/* RTC_CPU_INT_IMASK[TIO15] Bits */
#define RTC_CPU_INT_IMASK_TIO15_OFS              (23)                            /* !< TIO15 Offset */
#define RTC_CPU_INT_IMASK_TIO15_MASK             ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define RTC_CPU_INT_IMASK_TIO15_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define RTC_CPU_INT_IMASK_TIO15_SET              ((uint32_t)0x00800000U)         /* !< Set Interrrupt Mask */

/* RTC_CPU_INT_RIS Bits */
/* RTC_CPU_INT_RIS[RTCRDY] Bits */
#define RTC_CPU_INT_RIS_RTCRDY_OFS               (0)                             /* !< RTCRDY Offset */
#define RTC_CPU_INT_RIS_RTCRDY_MASK              ((uint32_t)0x00000001U)         /* !< Raw RTC-Ready interrupts status */
#define RTC_CPU_INT_RIS_RTCRDY_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_RTCRDY_SET               ((uint32_t)0x00000001U)         /* !< Interrupt occured */
/* RTC_CPU_INT_RIS[RTCTEV] Bits */
#define RTC_CPU_INT_RIS_RTCTEV_OFS               (1)                             /* !< RTCTEV Offset */
#define RTC_CPU_INT_RIS_RTCTEV_MASK              ((uint32_t)0x00000002U)         /* !< Raw Time-Event interrupt status */
#define RTC_CPU_INT_RIS_RTCTEV_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_RTCTEV_SET               ((uint32_t)0x00000002U)         /* !< Interrupt occured */
/* RTC_CPU_INT_RIS[RTCA1] Bits */
#define RTC_CPU_INT_RIS_RTCA1_OFS                (2)                             /* !< RTCA1 Offset */
#define RTC_CPU_INT_RIS_RTCA1_MASK               ((uint32_t)0x00000004U)         /* !< Raw Alarm-1 interrupt status */
#define RTC_CPU_INT_RIS_RTCA1_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_RTCA1_SET                ((uint32_t)0x00000004U)         /* !< Interrupt occured */
/* RTC_CPU_INT_RIS[RTCA2] Bits */
#define RTC_CPU_INT_RIS_RTCA2_OFS                (3)                             /* !< RTCA2 Offset */
#define RTC_CPU_INT_RIS_RTCA2_MASK               ((uint32_t)0x00000008U)         /* !< Raw Alarm-2 interrupts status */
#define RTC_CPU_INT_RIS_RTCA2_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_RTCA2_SET                ((uint32_t)0x00000008U)         /* !< Interrupt occured */
/* RTC_CPU_INT_RIS[RT0PS] Bits */
#define RTC_CPU_INT_RIS_RT0PS_OFS                (4)                             /* !< RT0PS Offset */
#define RTC_CPU_INT_RIS_RT0PS_MASK               ((uint32_t)0x00000010U)         /* !< Raw Prescaler-0 interrupt status */
#define RTC_CPU_INT_RIS_RT0PS_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_RT0PS_SET                ((uint32_t)0x00000010U)         /* !< Interrupt occured */
/* RTC_CPU_INT_RIS[RT1PS] Bits */
#define RTC_CPU_INT_RIS_RT1PS_OFS                (5)                             /* !< RT1PS Offset */
#define RTC_CPU_INT_RIS_RT1PS_MASK               ((uint32_t)0x00000020U)         /* !< Raw Prescaler-1 interrupt status */
#define RTC_CPU_INT_RIS_RT1PS_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_RT1PS_SET                ((uint32_t)0x00000020U)         /* !< Interrupt occured */
/* RTC_CPU_INT_RIS[RT2PS] Bits */
#define RTC_CPU_INT_RIS_RT2PS_OFS                (6)                             /* !< RT2PS Offset */
#define RTC_CPU_INT_RIS_RT2PS_MASK               ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define RTC_CPU_INT_RIS_RT2PS_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_RT2PS_SET                ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TSEVT] Bits */
#define RTC_CPU_INT_RIS_TSEVT_OFS                (7)                             /* !< TSEVT Offset */
#define RTC_CPU_INT_RIS_TSEVT_MASK               ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define RTC_CPU_INT_RIS_TSEVT_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TSEVT_SET                ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO0] Bits */
#define RTC_CPU_INT_RIS_TIO0_OFS                 (8)                             /* !< TIO0 Offset */
#define RTC_CPU_INT_RIS_TIO0_MASK                ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define RTC_CPU_INT_RIS_TIO0_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO0_SET                 ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO1] Bits */
#define RTC_CPU_INT_RIS_TIO1_OFS                 (9)                             /* !< TIO1 Offset */
#define RTC_CPU_INT_RIS_TIO1_MASK                ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define RTC_CPU_INT_RIS_TIO1_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO1_SET                 ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO2] Bits */
#define RTC_CPU_INT_RIS_TIO2_OFS                 (10)                            /* !< TIO2 Offset */
#define RTC_CPU_INT_RIS_TIO2_MASK                ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define RTC_CPU_INT_RIS_TIO2_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO2_SET                 ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO3] Bits */
#define RTC_CPU_INT_RIS_TIO3_OFS                 (11)                            /* !< TIO3 Offset */
#define RTC_CPU_INT_RIS_TIO3_MASK                ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define RTC_CPU_INT_RIS_TIO3_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO3_SET                 ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO4] Bits */
#define RTC_CPU_INT_RIS_TIO4_OFS                 (12)                            /* !< TIO4 Offset */
#define RTC_CPU_INT_RIS_TIO4_MASK                ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define RTC_CPU_INT_RIS_TIO4_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO4_SET                 ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO5] Bits */
#define RTC_CPU_INT_RIS_TIO5_OFS                 (13)                            /* !< TIO5 Offset */
#define RTC_CPU_INT_RIS_TIO5_MASK                ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define RTC_CPU_INT_RIS_TIO5_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO5_SET                 ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO6] Bits */
#define RTC_CPU_INT_RIS_TIO6_OFS                 (14)                            /* !< TIO6 Offset */
#define RTC_CPU_INT_RIS_TIO6_MASK                ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define RTC_CPU_INT_RIS_TIO6_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO6_SET                 ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO7] Bits */
#define RTC_CPU_INT_RIS_TIO7_OFS                 (15)                            /* !< TIO7 Offset */
#define RTC_CPU_INT_RIS_TIO7_MASK                ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define RTC_CPU_INT_RIS_TIO7_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO7_SET                 ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO8] Bits */
#define RTC_CPU_INT_RIS_TIO8_OFS                 (16)                            /* !< TIO8 Offset */
#define RTC_CPU_INT_RIS_TIO8_MASK                ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define RTC_CPU_INT_RIS_TIO8_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO8_SET                 ((uint32_t)0x00010000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO9] Bits */
#define RTC_CPU_INT_RIS_TIO9_OFS                 (17)                            /* !< TIO9 Offset */
#define RTC_CPU_INT_RIS_TIO9_MASK                ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define RTC_CPU_INT_RIS_TIO9_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO9_SET                 ((uint32_t)0x00020000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO10] Bits */
#define RTC_CPU_INT_RIS_TIO10_OFS                (18)                            /* !< TIO10 Offset */
#define RTC_CPU_INT_RIS_TIO10_MASK               ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define RTC_CPU_INT_RIS_TIO10_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO10_SET                ((uint32_t)0x00040000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO11] Bits */
#define RTC_CPU_INT_RIS_TIO11_OFS                (19)                            /* !< TIO11 Offset */
#define RTC_CPU_INT_RIS_TIO11_MASK               ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define RTC_CPU_INT_RIS_TIO11_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO11_SET                ((uint32_t)0x00080000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO12] Bits */
#define RTC_CPU_INT_RIS_TIO12_OFS                (20)                            /* !< TIO12 Offset */
#define RTC_CPU_INT_RIS_TIO12_MASK               ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define RTC_CPU_INT_RIS_TIO12_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO12_SET                ((uint32_t)0x00100000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO13] Bits */
#define RTC_CPU_INT_RIS_TIO13_OFS                (21)                            /* !< TIO13 Offset */
#define RTC_CPU_INT_RIS_TIO13_MASK               ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define RTC_CPU_INT_RIS_TIO13_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO13_SET                ((uint32_t)0x00200000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO14] Bits */
#define RTC_CPU_INT_RIS_TIO14_OFS                (22)                            /* !< TIO14 Offset */
#define RTC_CPU_INT_RIS_TIO14_MASK               ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define RTC_CPU_INT_RIS_TIO14_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO14_SET                ((uint32_t)0x00400000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_RIS[TIO15] Bits */
#define RTC_CPU_INT_RIS_TIO15_OFS                (23)                            /* !< TIO15 Offset */
#define RTC_CPU_INT_RIS_TIO15_MASK               ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define RTC_CPU_INT_RIS_TIO15_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_RIS_TIO15_SET                ((uint32_t)0x00800000U)         /* !< Interrupt occurred */

/* RTC_CPU_INT_MIS Bits */
/* RTC_CPU_INT_MIS[RTCRDY] Bits */
#define RTC_CPU_INT_MIS_RTCRDY_OFS               (0)                             /* !< RTCRDY Offset */
#define RTC_CPU_INT_MIS_RTCRDY_MASK              ((uint32_t)0x00000001U)         /* !< Masked RTC-Ready interrupt status */
#define RTC_CPU_INT_MIS_RTCRDY_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_MIS_RTCRDY_SET               ((uint32_t)0x00000001U)         /* !< Interrupt occured */
/* RTC_CPU_INT_MIS[RTCTEV] Bits */
#define RTC_CPU_INT_MIS_RTCTEV_OFS               (1)                             /* !< RTCTEV Offset */
#define RTC_CPU_INT_MIS_RTCTEV_MASK              ((uint32_t)0x00000002U)         /* !< Masked Time-Event interrupt status */
#define RTC_CPU_INT_MIS_RTCTEV_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_MIS_RTCTEV_SET               ((uint32_t)0x00000002U)         /* !< Interrupt occured */
/* RTC_CPU_INT_MIS[RTCA1] Bits */
#define RTC_CPU_INT_MIS_RTCA1_OFS                (2)                             /* !< RTCA1 Offset */
#define RTC_CPU_INT_MIS_RTCA1_MASK               ((uint32_t)0x00000004U)         /* !< Masked Alarm-1 interrupt status */
#define RTC_CPU_INT_MIS_RTCA1_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_MIS_RTCA1_SET                ((uint32_t)0x00000004U)         /* !< Interrupt occured */
/* RTC_CPU_INT_MIS[RTCA2] Bits */
#define RTC_CPU_INT_MIS_RTCA2_OFS                (3)                             /* !< RTCA2 Offset */
#define RTC_CPU_INT_MIS_RTCA2_MASK               ((uint32_t)0x00000008U)         /* !< Masked Alarm-2 interrupt status */
#define RTC_CPU_INT_MIS_RTCA2_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_MIS_RTCA2_SET                ((uint32_t)0x00000008U)         /* !< Interrupt occured */
/* RTC_CPU_INT_MIS[RT0PS] Bits */
#define RTC_CPU_INT_MIS_RT0PS_OFS                (4)                             /* !< RT0PS Offset */
#define RTC_CPU_INT_MIS_RT0PS_MASK               ((uint32_t)0x00000010U)         /* !< Masked Prescaler-0 interrupt status */
#define RTC_CPU_INT_MIS_RT0PS_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_MIS_RT0PS_SET                ((uint32_t)0x00000010U)         /* !< Interrupt occured */
/* RTC_CPU_INT_MIS[RT1PS] Bits */
#define RTC_CPU_INT_MIS_RT1PS_OFS                (5)                             /* !< RT1PS Offset */
#define RTC_CPU_INT_MIS_RT1PS_MASK               ((uint32_t)0x00000020U)         /* !< Masked Prescaler-1 interrupt status */
#define RTC_CPU_INT_MIS_RT1PS_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define RTC_CPU_INT_MIS_RT1PS_SET                ((uint32_t)0x00000020U)         /* !< Interrupt occured */
/* RTC_CPU_INT_MIS[RT2PS] Bits */
#define RTC_CPU_INT_MIS_RT2PS_OFS                (6)                             /* !< RT2PS Offset */
#define RTC_CPU_INT_MIS_RT2PS_MASK               ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define RTC_CPU_INT_MIS_RT2PS_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_RT2PS_SET                ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TSEVT] Bits */
#define RTC_CPU_INT_MIS_TSEVT_OFS                (7)                             /* !< TSEVT Offset */
#define RTC_CPU_INT_MIS_TSEVT_MASK               ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define RTC_CPU_INT_MIS_TSEVT_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TSEVT_SET                ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO0] Bits */
#define RTC_CPU_INT_MIS_TIO0_OFS                 (8)                             /* !< TIO0 Offset */
#define RTC_CPU_INT_MIS_TIO0_MASK                ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define RTC_CPU_INT_MIS_TIO0_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO0_SET                 ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO1] Bits */
#define RTC_CPU_INT_MIS_TIO1_OFS                 (9)                             /* !< TIO1 Offset */
#define RTC_CPU_INT_MIS_TIO1_MASK                ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define RTC_CPU_INT_MIS_TIO1_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO1_SET                 ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO2] Bits */
#define RTC_CPU_INT_MIS_TIO2_OFS                 (10)                            /* !< TIO2 Offset */
#define RTC_CPU_INT_MIS_TIO2_MASK                ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define RTC_CPU_INT_MIS_TIO2_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO2_SET                 ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO3] Bits */
#define RTC_CPU_INT_MIS_TIO3_OFS                 (11)                            /* !< TIO3 Offset */
#define RTC_CPU_INT_MIS_TIO3_MASK                ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define RTC_CPU_INT_MIS_TIO3_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO3_SET                 ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO4] Bits */
#define RTC_CPU_INT_MIS_TIO4_OFS                 (12)                            /* !< TIO4 Offset */
#define RTC_CPU_INT_MIS_TIO4_MASK                ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define RTC_CPU_INT_MIS_TIO4_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO4_SET                 ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO5] Bits */
#define RTC_CPU_INT_MIS_TIO5_OFS                 (13)                            /* !< TIO5 Offset */
#define RTC_CPU_INT_MIS_TIO5_MASK                ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define RTC_CPU_INT_MIS_TIO5_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO5_SET                 ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO6] Bits */
#define RTC_CPU_INT_MIS_TIO6_OFS                 (14)                            /* !< TIO6 Offset */
#define RTC_CPU_INT_MIS_TIO6_MASK                ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define RTC_CPU_INT_MIS_TIO6_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO6_SET                 ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO7] Bits */
#define RTC_CPU_INT_MIS_TIO7_OFS                 (15)                            /* !< TIO7 Offset */
#define RTC_CPU_INT_MIS_TIO7_MASK                ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define RTC_CPU_INT_MIS_TIO7_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO7_SET                 ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO8] Bits */
#define RTC_CPU_INT_MIS_TIO8_OFS                 (16)                            /* !< TIO8 Offset */
#define RTC_CPU_INT_MIS_TIO8_MASK                ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define RTC_CPU_INT_MIS_TIO8_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO8_SET                 ((uint32_t)0x00010000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO9] Bits */
#define RTC_CPU_INT_MIS_TIO9_OFS                 (17)                            /* !< TIO9 Offset */
#define RTC_CPU_INT_MIS_TIO9_MASK                ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define RTC_CPU_INT_MIS_TIO9_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO9_SET                 ((uint32_t)0x00020000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO10] Bits */
#define RTC_CPU_INT_MIS_TIO10_OFS                (18)                            /* !< TIO10 Offset */
#define RTC_CPU_INT_MIS_TIO10_MASK               ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define RTC_CPU_INT_MIS_TIO10_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO10_SET                ((uint32_t)0x00040000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO11] Bits */
#define RTC_CPU_INT_MIS_TIO11_OFS                (19)                            /* !< TIO11 Offset */
#define RTC_CPU_INT_MIS_TIO11_MASK               ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define RTC_CPU_INT_MIS_TIO11_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO11_SET                ((uint32_t)0x00080000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO12] Bits */
#define RTC_CPU_INT_MIS_TIO12_OFS                (20)                            /* !< TIO12 Offset */
#define RTC_CPU_INT_MIS_TIO12_MASK               ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define RTC_CPU_INT_MIS_TIO12_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO12_SET                ((uint32_t)0x00100000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO13] Bits */
#define RTC_CPU_INT_MIS_TIO13_OFS                (21)                            /* !< TIO13 Offset */
#define RTC_CPU_INT_MIS_TIO13_MASK               ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define RTC_CPU_INT_MIS_TIO13_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO13_SET                ((uint32_t)0x00200000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO14] Bits */
#define RTC_CPU_INT_MIS_TIO14_OFS                (22)                            /* !< TIO14 Offset */
#define RTC_CPU_INT_MIS_TIO14_MASK               ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define RTC_CPU_INT_MIS_TIO14_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO14_SET                ((uint32_t)0x00400000U)         /* !< Interrupt occurred */
/* RTC_CPU_INT_MIS[TIO15] Bits */
#define RTC_CPU_INT_MIS_TIO15_OFS                (23)                            /* !< TIO15 Offset */
#define RTC_CPU_INT_MIS_TIO15_MASK               ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define RTC_CPU_INT_MIS_TIO15_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define RTC_CPU_INT_MIS_TIO15_SET                ((uint32_t)0x00800000U)         /* !< Interrupt occurred */

/* RTC_CPU_INT_ISET Bits */
/* RTC_CPU_INT_ISET[RTCRDY] Bits */
#define RTC_CPU_INT_ISET_RTCRDY_OFS              (0)                             /* !< RTCRDY Offset */
#define RTC_CPU_INT_ISET_RTCRDY_MASK             ((uint32_t)0x00000001U)         /* !< Set RTC-Ready interrupt */
#define RTC_CPU_INT_ISET_RTCRDY_CLR              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_RTCRDY_SET              ((uint32_t)0x00000001U)         /* !< Set Interrupt */
/* RTC_CPU_INT_ISET[RTCTEV] Bits */
#define RTC_CPU_INT_ISET_RTCTEV_OFS              (1)                             /* !< RTCTEV Offset */
#define RTC_CPU_INT_ISET_RTCTEV_MASK             ((uint32_t)0x00000002U)         /* !< Set Time-Event interrupt */
#define RTC_CPU_INT_ISET_RTCTEV_CLR              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_RTCTEV_SET              ((uint32_t)0x00000002U)         /* !< Set Interrupt */
/* RTC_CPU_INT_ISET[RTCA1] Bits */
#define RTC_CPU_INT_ISET_RTCA1_OFS               (2)                             /* !< RTCA1 Offset */
#define RTC_CPU_INT_ISET_RTCA1_MASK              ((uint32_t)0x00000004U)         /* !< Set Alarm-1 interrupt */
#define RTC_CPU_INT_ISET_RTCA1_CLR               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_RTCA1_SET               ((uint32_t)0x00000004U)         /* !< Set Interrupt */
/* RTC_CPU_INT_ISET[RTCA2] Bits */
#define RTC_CPU_INT_ISET_RTCA2_OFS               (3)                             /* !< RTCA2 Offset */
#define RTC_CPU_INT_ISET_RTCA2_MASK              ((uint32_t)0x00000008U)         /* !< Set Alarm-2 interrupt */
#define RTC_CPU_INT_ISET_RTCA2_CLR               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_RTCA2_SET               ((uint32_t)0x00000008U)         /* !< Set Interrupt */
/* RTC_CPU_INT_ISET[RT0PS] Bits */
#define RTC_CPU_INT_ISET_RT0PS_OFS               (4)                             /* !< RT0PS Offset */
#define RTC_CPU_INT_ISET_RT0PS_MASK              ((uint32_t)0x00000010U)         /* !< Set Prescaler-0 interrupt */
#define RTC_CPU_INT_ISET_RT0PS_CLR               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_RT0PS_SET               ((uint32_t)0x00000010U)         /* !< Set Interrupt */
/* RTC_CPU_INT_ISET[RT1PS] Bits */
#define RTC_CPU_INT_ISET_RT1PS_OFS               (5)                             /* !< RT1PS Offset */
#define RTC_CPU_INT_ISET_RT1PS_MASK              ((uint32_t)0x00000020U)         /* !< Set Prescaler-1 interrupt */
#define RTC_CPU_INT_ISET_RT1PS_CLR               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_RT1PS_SET               ((uint32_t)0x00000020U)         /* !< Set Interrupt */
/* RTC_CPU_INT_ISET[RT2PS] Bits */
#define RTC_CPU_INT_ISET_RT2PS_OFS               (6)                             /* !< RT2PS Offset */
#define RTC_CPU_INT_ISET_RT2PS_MASK              ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define RTC_CPU_INT_ISET_RT2PS_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_RT2PS_SET               ((uint32_t)0x00000040U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TSEVT] Bits */
#define RTC_CPU_INT_ISET_TSEVT_OFS               (7)                             /* !< TSEVT Offset */
#define RTC_CPU_INT_ISET_TSEVT_MASK              ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define RTC_CPU_INT_ISET_TSEVT_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TSEVT_SET               ((uint32_t)0x00000080U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO0] Bits */
#define RTC_CPU_INT_ISET_TIO0_OFS                (8)                             /* !< TIO0 Offset */
#define RTC_CPU_INT_ISET_TIO0_MASK               ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define RTC_CPU_INT_ISET_TIO0_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO0_SET                ((uint32_t)0x00000100U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO1] Bits */
#define RTC_CPU_INT_ISET_TIO1_OFS                (9)                             /* !< TIO1 Offset */
#define RTC_CPU_INT_ISET_TIO1_MASK               ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define RTC_CPU_INT_ISET_TIO1_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO1_SET                ((uint32_t)0x00000200U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO2] Bits */
#define RTC_CPU_INT_ISET_TIO2_OFS                (10)                            /* !< TIO2 Offset */
#define RTC_CPU_INT_ISET_TIO2_MASK               ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define RTC_CPU_INT_ISET_TIO2_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO2_SET                ((uint32_t)0x00000400U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO3] Bits */
#define RTC_CPU_INT_ISET_TIO3_OFS                (11)                            /* !< TIO3 Offset */
#define RTC_CPU_INT_ISET_TIO3_MASK               ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define RTC_CPU_INT_ISET_TIO3_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO3_SET                ((uint32_t)0x00000800U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO4] Bits */
#define RTC_CPU_INT_ISET_TIO4_OFS                (12)                            /* !< TIO4 Offset */
#define RTC_CPU_INT_ISET_TIO4_MASK               ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define RTC_CPU_INT_ISET_TIO4_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO4_SET                ((uint32_t)0x00001000U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO5] Bits */
#define RTC_CPU_INT_ISET_TIO5_OFS                (13)                            /* !< TIO5 Offset */
#define RTC_CPU_INT_ISET_TIO5_MASK               ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define RTC_CPU_INT_ISET_TIO5_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO5_SET                ((uint32_t)0x00002000U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO6] Bits */
#define RTC_CPU_INT_ISET_TIO6_OFS                (14)                            /* !< TIO6 Offset */
#define RTC_CPU_INT_ISET_TIO6_MASK               ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define RTC_CPU_INT_ISET_TIO6_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO6_SET                ((uint32_t)0x00004000U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO7] Bits */
#define RTC_CPU_INT_ISET_TIO7_OFS                (15)                            /* !< TIO7 Offset */
#define RTC_CPU_INT_ISET_TIO7_MASK               ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define RTC_CPU_INT_ISET_TIO7_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO7_SET                ((uint32_t)0x00008000U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO8] Bits */
#define RTC_CPU_INT_ISET_TIO8_OFS                (16)                            /* !< TIO8 Offset */
#define RTC_CPU_INT_ISET_TIO8_MASK               ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define RTC_CPU_INT_ISET_TIO8_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO8_SET                ((uint32_t)0x00010000U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO9] Bits */
#define RTC_CPU_INT_ISET_TIO9_OFS                (17)                            /* !< TIO9 Offset */
#define RTC_CPU_INT_ISET_TIO9_MASK               ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define RTC_CPU_INT_ISET_TIO9_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO9_SET                ((uint32_t)0x00020000U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO10] Bits */
#define RTC_CPU_INT_ISET_TIO10_OFS               (18)                            /* !< TIO10 Offset */
#define RTC_CPU_INT_ISET_TIO10_MASK              ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define RTC_CPU_INT_ISET_TIO10_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO10_SET               ((uint32_t)0x00040000U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO11] Bits */
#define RTC_CPU_INT_ISET_TIO11_OFS               (19)                            /* !< TIO11 Offset */
#define RTC_CPU_INT_ISET_TIO11_MASK              ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define RTC_CPU_INT_ISET_TIO11_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO11_SET               ((uint32_t)0x00080000U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO12] Bits */
#define RTC_CPU_INT_ISET_TIO12_OFS               (20)                            /* !< TIO12 Offset */
#define RTC_CPU_INT_ISET_TIO12_MASK              ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define RTC_CPU_INT_ISET_TIO12_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO12_SET               ((uint32_t)0x00100000U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO13] Bits */
#define RTC_CPU_INT_ISET_TIO13_OFS               (21)                            /* !< TIO13 Offset */
#define RTC_CPU_INT_ISET_TIO13_MASK              ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define RTC_CPU_INT_ISET_TIO13_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO13_SET               ((uint32_t)0x00200000U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO14] Bits */
#define RTC_CPU_INT_ISET_TIO14_OFS               (22)                            /* !< TIO14 Offset */
#define RTC_CPU_INT_ISET_TIO14_MASK              ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define RTC_CPU_INT_ISET_TIO14_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO14_SET               ((uint32_t)0x00400000U)         /* !< Set interrupt */
/* RTC_CPU_INT_ISET[TIO15] Bits */
#define RTC_CPU_INT_ISET_TIO15_OFS               (23)                            /* !< TIO15 Offset */
#define RTC_CPU_INT_ISET_TIO15_MASK              ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define RTC_CPU_INT_ISET_TIO15_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ISET_TIO15_SET               ((uint32_t)0x00800000U)         /* !< Set interrupt */

/* RTC_CPU_INT_ICLR Bits */
/* RTC_CPU_INT_ICLR[RTCRDY] Bits */
#define RTC_CPU_INT_ICLR_RTCRDY_OFS              (0)                             /* !< RTCRDY Offset */
#define RTC_CPU_INT_ICLR_RTCRDY_MASK             ((uint32_t)0x00000001U)         /* !< Clear RTC-Ready interrupt */
#define RTC_CPU_INT_ICLR_RTCRDY_CLR              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_RTCRDY_SET              ((uint32_t)0x00000001U)         /* !< Clear Interrupt */
/* RTC_CPU_INT_ICLR[RTCTEV] Bits */
#define RTC_CPU_INT_ICLR_RTCTEV_OFS              (1)                             /* !< RTCTEV Offset */
#define RTC_CPU_INT_ICLR_RTCTEV_MASK             ((uint32_t)0x00000002U)         /* !< Clear Time-Event interrupt */
#define RTC_CPU_INT_ICLR_RTCTEV_CLR              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_RTCTEV_SET              ((uint32_t)0x00000002U)         /* !< Clear Interrupt */
/* RTC_CPU_INT_ICLR[RTCA1] Bits */
#define RTC_CPU_INT_ICLR_RTCA1_OFS               (2)                             /* !< RTCA1 Offset */
#define RTC_CPU_INT_ICLR_RTCA1_MASK              ((uint32_t)0x00000004U)         /* !< Clear Alarm-1 interrupt */
#define RTC_CPU_INT_ICLR_RTCA1_CLR               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_RTCA1_SET               ((uint32_t)0x00000004U)         /* !< Clear Interrupt */
/* RTC_CPU_INT_ICLR[RTCA2] Bits */
#define RTC_CPU_INT_ICLR_RTCA2_OFS               (3)                             /* !< RTCA2 Offset */
#define RTC_CPU_INT_ICLR_RTCA2_MASK              ((uint32_t)0x00000008U)         /* !< Clear Alarm-2 interrupt */
#define RTC_CPU_INT_ICLR_RTCA2_CLR               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_RTCA2_SET               ((uint32_t)0x00000008U)         /* !< Clear Interrupt */
/* RTC_CPU_INT_ICLR[RT0PS] Bits */
#define RTC_CPU_INT_ICLR_RT0PS_OFS               (4)                             /* !< RT0PS Offset */
#define RTC_CPU_INT_ICLR_RT0PS_MASK              ((uint32_t)0x00000010U)         /* !< Clear Prescaler-0 interrupt */
#define RTC_CPU_INT_ICLR_RT0PS_CLR               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_RT0PS_SET               ((uint32_t)0x00000010U)         /* !< Clear Interrupt */
/* RTC_CPU_INT_ICLR[RT1PS] Bits */
#define RTC_CPU_INT_ICLR_RT1PS_OFS               (5)                             /* !< RT1PS Offset */
#define RTC_CPU_INT_ICLR_RT1PS_MASK              ((uint32_t)0x00000020U)         /* !< Clear Prescaler-1 interrupt */
#define RTC_CPU_INT_ICLR_RT1PS_CLR               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_RT1PS_SET               ((uint32_t)0x00000020U)         /* !< Clear Interrupt */
/* RTC_CPU_INT_ICLR[RT2PS] Bits */
#define RTC_CPU_INT_ICLR_RT2PS_OFS               (6)                             /* !< RT2PS Offset */
#define RTC_CPU_INT_ICLR_RT2PS_MASK              ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define RTC_CPU_INT_ICLR_RT2PS_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_RT2PS_CLR               ((uint32_t)0x00000040U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TSEVT] Bits */
#define RTC_CPU_INT_ICLR_TSEVT_OFS               (7)                             /* !< TSEVT Offset */
#define RTC_CPU_INT_ICLR_TSEVT_MASK              ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define RTC_CPU_INT_ICLR_TSEVT_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TSEVT_CLR               ((uint32_t)0x00000080U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO0] Bits */
#define RTC_CPU_INT_ICLR_TIO0_OFS                (8)                             /* !< TIO0 Offset */
#define RTC_CPU_INT_ICLR_TIO0_MASK               ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define RTC_CPU_INT_ICLR_TIO0_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO0_CLR                ((uint32_t)0x00000100U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO1] Bits */
#define RTC_CPU_INT_ICLR_TIO1_OFS                (9)                             /* !< TIO1 Offset */
#define RTC_CPU_INT_ICLR_TIO1_MASK               ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define RTC_CPU_INT_ICLR_TIO1_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO1_CLR                ((uint32_t)0x00000200U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO2] Bits */
#define RTC_CPU_INT_ICLR_TIO2_OFS                (10)                            /* !< TIO2 Offset */
#define RTC_CPU_INT_ICLR_TIO2_MASK               ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define RTC_CPU_INT_ICLR_TIO2_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO2_CLR                ((uint32_t)0x00000400U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO3] Bits */
#define RTC_CPU_INT_ICLR_TIO3_OFS                (11)                            /* !< TIO3 Offset */
#define RTC_CPU_INT_ICLR_TIO3_MASK               ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define RTC_CPU_INT_ICLR_TIO3_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO3_CLR                ((uint32_t)0x00000800U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO4] Bits */
#define RTC_CPU_INT_ICLR_TIO4_OFS                (12)                            /* !< TIO4 Offset */
#define RTC_CPU_INT_ICLR_TIO4_MASK               ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define RTC_CPU_INT_ICLR_TIO4_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO4_CLR                ((uint32_t)0x00001000U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO5] Bits */
#define RTC_CPU_INT_ICLR_TIO5_OFS                (13)                            /* !< TIO5 Offset */
#define RTC_CPU_INT_ICLR_TIO5_MASK               ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define RTC_CPU_INT_ICLR_TIO5_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO5_CLR                ((uint32_t)0x00002000U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO6] Bits */
#define RTC_CPU_INT_ICLR_TIO6_OFS                (14)                            /* !< TIO6 Offset */
#define RTC_CPU_INT_ICLR_TIO6_MASK               ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define RTC_CPU_INT_ICLR_TIO6_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO6_CLR                ((uint32_t)0x00004000U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO7] Bits */
#define RTC_CPU_INT_ICLR_TIO7_OFS                (15)                            /* !< TIO7 Offset */
#define RTC_CPU_INT_ICLR_TIO7_MASK               ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define RTC_CPU_INT_ICLR_TIO7_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO7_CLR                ((uint32_t)0x00008000U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO8] Bits */
#define RTC_CPU_INT_ICLR_TIO8_OFS                (16)                            /* !< TIO8 Offset */
#define RTC_CPU_INT_ICLR_TIO8_MASK               ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define RTC_CPU_INT_ICLR_TIO8_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO8_CLR                ((uint32_t)0x00010000U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO9] Bits */
#define RTC_CPU_INT_ICLR_TIO9_OFS                (17)                            /* !< TIO9 Offset */
#define RTC_CPU_INT_ICLR_TIO9_MASK               ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define RTC_CPU_INT_ICLR_TIO9_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO9_CLR                ((uint32_t)0x00020000U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO10] Bits */
#define RTC_CPU_INT_ICLR_TIO10_OFS               (18)                            /* !< TIO10 Offset */
#define RTC_CPU_INT_ICLR_TIO10_MASK              ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define RTC_CPU_INT_ICLR_TIO10_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO10_CLR               ((uint32_t)0x00040000U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO11] Bits */
#define RTC_CPU_INT_ICLR_TIO11_OFS               (19)                            /* !< TIO11 Offset */
#define RTC_CPU_INT_ICLR_TIO11_MASK              ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define RTC_CPU_INT_ICLR_TIO11_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO11_CLR               ((uint32_t)0x00080000U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO12] Bits */
#define RTC_CPU_INT_ICLR_TIO12_OFS               (20)                            /* !< TIO12 Offset */
#define RTC_CPU_INT_ICLR_TIO12_MASK              ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define RTC_CPU_INT_ICLR_TIO12_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO12_CLR               ((uint32_t)0x00100000U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO13] Bits */
#define RTC_CPU_INT_ICLR_TIO13_OFS               (21)                            /* !< TIO13 Offset */
#define RTC_CPU_INT_ICLR_TIO13_MASK              ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define RTC_CPU_INT_ICLR_TIO13_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO13_CLR               ((uint32_t)0x00200000U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO14] Bits */
#define RTC_CPU_INT_ICLR_TIO14_OFS               (22)                            /* !< TIO14 Offset */
#define RTC_CPU_INT_ICLR_TIO14_MASK              ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define RTC_CPU_INT_ICLR_TIO14_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO14_CLR               ((uint32_t)0x00400000U)         /* !< Clear interrupt */
/* RTC_CPU_INT_ICLR[TIO15] Bits */
#define RTC_CPU_INT_ICLR_TIO15_OFS               (23)                            /* !< TIO15 Offset */
#define RTC_CPU_INT_ICLR_TIO15_MASK              ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define RTC_CPU_INT_ICLR_TIO15_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_CPU_INT_ICLR_TIO15_CLR               ((uint32_t)0x00800000U)         /* !< Clear interrupt */

/* RTC_PWREN Bits */
/* RTC_PWREN[ENABLE] Bits */
#define RTC_PWREN_ENABLE_OFS                     (0)                             /* !< ENABLE Offset */
#define RTC_PWREN_ENABLE_MASK                    ((uint32_t)0x00000001U)         /* !< Enable the power */
#define RTC_PWREN_ENABLE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Disable Power */
#define RTC_PWREN_ENABLE_ENABLE                  ((uint32_t)0x00000001U)         /* !< Enable Power */
/* RTC_PWREN[KEY] Bits */
#define RTC_PWREN_KEY_OFS                        (24)                            /* !< KEY Offset */
#define RTC_PWREN_KEY_MASK                       ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define RTC_PWREN_KEY_UNLOCK_W                   ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* RTC_RSTCTL Bits */
/* RTC_RSTCTL[RESETSTKYCLR] Bits */
#define RTC_RSTCTL_RESETSTKYCLR_OFS              (1)                             /* !< RESETSTKYCLR Offset */
#define RTC_RSTCTL_RESETSTKYCLR_MASK             ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define RTC_RSTCTL_RESETSTKYCLR_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_RSTCTL_RESETSTKYCLR_CLR              ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* RTC_RSTCTL[RESETASSERT] Bits */
#define RTC_RSTCTL_RESETASSERT_OFS               (0)                             /* !< RESETASSERT Offset */
#define RTC_RSTCTL_RESETASSERT_MASK              ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define RTC_RSTCTL_RESETASSERT_NOP               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_RSTCTL_RESETASSERT_ASSERT            ((uint32_t)0x00000001U)         /* !< Assert reset */
/* RTC_RSTCTL[KEY] Bits */
#define RTC_RSTCTL_KEY_OFS                       (24)                            /* !< KEY Offset */
#define RTC_RSTCTL_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define RTC_RSTCTL_KEY_UNLOCK_W                  ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* RTC_CLKCFG Bits */
/* RTC_CLKCFG[KEY] Bits */
#define RTC_CLKCFG_KEY_OFS                       (24)                            /* !< KEY Offset */
#define RTC_CLKCFG_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define RTC_CLKCFG_KEY_UNLOCK_W                  ((uint32_t)0xA9000000U)         /* !< key value to allow change field of
                                                                                    GPRCM */
/* RTC_CLKCFG[BLOCKASYNC] Bits */
#define RTC_CLKCFG_BLOCKASYNC_OFS                (8)                             /* !< BLOCKASYNC Offset */
#define RTC_CLKCFG_BLOCKASYNC_MASK               ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define RTC_CLKCFG_BLOCKASYNC_DISABLE            ((uint32_t)0x00000000U)         /* !< Not block async clock request */
#define RTC_CLKCFG_BLOCKASYNC_ENABLE             ((uint32_t)0x00000100U)         /* !< Block async clock request */

/* RTC_STAT Bits */
/* RTC_STAT[RESETSTKY] Bits */
#define RTC_STAT_RESETSTKY_OFS                   (16)                            /* !< RESETSTKY Offset */
#define RTC_STAT_RESETSTKY_MASK                  ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define RTC_STAT_RESETSTKY_NORES                 ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define RTC_STAT_RESETSTKY_RESET                 ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* RTC_FPUB_0 Bits */
/* RTC_FPUB_0[CHANID] Bits */
#define RTC_FPUB_0_CHANID_OFS                    (0)                             /* !< CHANID Offset */
#define RTC_FPUB_0_CHANID_MASK                   ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define RTC_FPUB_0_CHANID_MNIMUM                 ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define RTC_FPUB_0_CHANID_UNCONNECTED            ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define RTC_FPUB_0_CHANID_MAXIMUM                ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* RTC_CLKSEL Bits */
/* RTC_CLKSEL[LFCLK_SEL] Bits */
#define RTC_CLKSEL_LFCLK_SEL_OFS                 (1)                             /* !< LFCLK_SEL Offset */
#define RTC_CLKSEL_LFCLK_SEL_MASK                ((uint32_t)0x00000002U)         /* !< Selects LFCLK as clock source if
                                                                                    enabled */
#define RTC_CLKSEL_LFCLK_SEL_DISABLE             ((uint32_t)0x00000000U)         /* !< LFCLK is disabled as clock source */
#define RTC_CLKSEL_LFCLK_SEL_ENABLE              ((uint32_t)0x00000002U)         /* !< LFCLK is enabled as clock source */

/* RTC_EVT_MODE Bits */
/* RTC_EVT_MODE[EVT0_CFG] Bits */
#define RTC_EVT_MODE_EVT0_CFG_OFS                (0)                             /* !< EVT0_CFG Offset */
#define RTC_EVT_MODE_EVT0_CFG_MASK               ((uint32_t)0x00000003U)         /* !< Event line mode 0 select */
#define RTC_EVT_MODE_EVT0_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define RTC_EVT_MODE_EVT0_CFG_SOFTWARE           ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. The software ISR
                                                                                    clears the associated RIS flag. */
#define RTC_EVT_MODE_EVT0_CFG_HARDWARE           ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* RTC_EVT_MODE[EVT1_CFG] Bits */
#define RTC_EVT_MODE_EVT1_CFG_OFS                (2)                             /* !< EVT1_CFG Offset */
#define RTC_EVT_MODE_EVT1_CFG_MASK               ((uint32_t)0x0000000CU)         /* !< Event line mode 1 select */
#define RTC_EVT_MODE_EVT1_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define RTC_EVT_MODE_EVT1_CFG_SOFTWARE           ((uint32_t)0x00000004U)         /* !< The interrupt or event line is in
                                                                                    software mode. The software ISR
                                                                                    clears the associated RIS flag. */
#define RTC_EVT_MODE_EVT1_CFG_HARDWARE           ((uint32_t)0x00000008U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* RTC_DESC Bits */
/* RTC_DESC[MINREV] Bits */
#define RTC_DESC_MINREV_OFS                      (0)                             /* !< MINREV Offset */
#define RTC_DESC_MINREV_MASK                     ((uint32_t)0x0000000FU)         /* !< Minor revision. This number holds
                                                                                    the module revision and is
                                                                                    incremented by the module developers.
                                                                                    n = Minor module revision (see
                                                                                    device-specific data sheet) */
#define RTC_DESC_MINREV_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_DESC_MINREV_MAXIMUM                  ((uint32_t)0x0000000FU)         /* !< Maximum value */
/* RTC_DESC[MAJREV] Bits */
#define RTC_DESC_MAJREV_OFS                      (4)                             /* !< MAJREV Offset */
#define RTC_DESC_MAJREV_MASK                     ((uint32_t)0x000000F0U)         /* !< Major revision. This number holds
                                                                                    the module revision and is
                                                                                    incremented by the module developers.
                                                                                    n = Major version (see
                                                                                    device-specific data sheet) */
#define RTC_DESC_MAJREV_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_DESC_MAJREV_MAXIMUM                  ((uint32_t)0x000000F0U)         /* !< Maximum value */
/* RTC_DESC[INSTNUM] Bits */
#define RTC_DESC_INSTNUM_OFS                     (8)                             /* !< INSTNUM Offset */
#define RTC_DESC_INSTNUM_MASK                    ((uint32_t)0x00000F00U)         /* !< Instantiated version. Describes
                                                                                    which instance of the module
                                                                                    accessed. */
#define RTC_DESC_INSTNUM_INST0                   ((uint32_t)0x00000000U)         /* !< This is the default, if there is
                                                                                    only one instance - like for SSIM */
/* RTC_DESC[FEATUREVER] Bits */
#define RTC_DESC_FEATUREVER_OFS                  (12)                            /* !< FEATUREVER Offset */
#define RTC_DESC_FEATUREVER_MASK                 ((uint32_t)0x0000F000U)         /* !< Feature set of this module.
                                                                                    Differentiates the complexity of the
                                                                                    actually instantiated module if there
                                                                                    are differences. */
#define RTC_DESC_FEATUREVER_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_DESC_FEATUREVER_MAXIMUM              ((uint32_t)0x0000F000U)         /* !< Maximum value */
/* RTC_DESC[MODULEID] Bits */
#define RTC_DESC_MODULEID_OFS                    (16)                            /* !< MODULEID Offset */
#define RTC_DESC_MODULEID_MASK                   ((uint32_t)0xFFFF0000U)         /* !< Module identifier. This ID is
                                                                                    unique for each module. 0x0911 =
                                                                                    Module ID of the RTC Module */
#define RTC_DESC_MODULEID_MINIMUM                ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_DESC_MODULEID_MAXIMUM                ((uint32_t)0xFFFF0000U)         /* !< Maximum value */

/* RTC_CLKCTL Bits */
/* RTC_CLKCTL[MODCLKEN] Bits */
#define RTC_CLKCTL_MODCLKEN_OFS                  (31)                            /* !< MODCLKEN Offset */
#define RTC_CLKCTL_MODCLKEN_MASK                 ((uint32_t)0x80000000U)         /* !< This bit enables the supply of the
                                                                                    32kHz clock to the RTC. It will not
                                                                                    power-up the 32kHz crystal oscillator
                                                                                    this needs to be done in the Clock
                                                                                    System Module. */
#define RTC_CLKCTL_MODCLKEN_DISABLE              ((uint32_t)0x00000000U)         /* !< 32kHz clock is not supplied to the
                                                                                    RTC. */
#define RTC_CLKCTL_MODCLKEN_ENABLE               ((uint32_t)0x80000000U)         /* !< 32kHz clock is supplied to the RTC. */

/* RTC_DBGCTL Bits */
/* RTC_DBGCTL[DBGRUN] Bits */
#define RTC_DBGCTL_DBGRUN_OFS                    (0)                             /* !< DBGRUN Offset */
#define RTC_DBGCTL_DBGRUN_MASK                   ((uint32_t)0x00000001U)         /* !< Debug Run. */
#define RTC_DBGCTL_DBGRUN_HALT                   ((uint32_t)0x00000000U)         /* !< Counter is halted if CPU is in
                                                                                    debug state. */
#define RTC_DBGCTL_DBGRUN_RUN                    ((uint32_t)0x00000001U)         /* !< Continue to operate normally
                                                                                    ignoring the debug state of the CPU. */
/* RTC_DBGCTL[DBGINT] Bits */
#define RTC_DBGCTL_DBGINT_OFS                    (1)                             /* !< DBGINT Offset */
#define RTC_DBGCTL_DBGINT_MASK                   ((uint32_t)0x00000002U)         /* !< Debug Interrupt Enable. */
#define RTC_DBGCTL_DBGINT_OFF                    ((uint32_t)0x00000000U)         /* !< Interrupts of the module will not
                                                                                    be captured anymore if CPU is in
                                                                                    debug state. Which means no update to
                                                                                    the RTCRIS, RTCMISC and RTCIIDX
                                                                                    register. */
#define RTC_DBGCTL_DBGINT_ON                     ((uint32_t)0x00000002U)         /* !< Interrupts are enabled in debug
                                                                                    mode. Interrupt requests are signaled
                                                                                    to the interrupt controller. If the
                                                                                    flags are required by software
                                                                                    (polling mode) the DGBINT bit need to
                                                                                    be set to 1. */

/* RTC_CTL Bits */
/* RTC_CTL[RTCTEVTX] Bits */
#define RTC_CTL_RTCTEVTX_OFS                     (0)                             /* !< RTCTEVTX Offset */
#define RTC_CTL_RTCTEVTX_MASK                    ((uint32_t)0x00000003U)         /* !< Real-time clock time event. */
#define RTC_CTL_RTCTEVTX_MINUTE                  ((uint32_t)0x00000000U)         /* !< Minute changed. */
#define RTC_CTL_RTCTEVTX_HOUR                    ((uint32_t)0x00000001U)         /* !< Hour changed. */
#define RTC_CTL_RTCTEVTX_MIDNIGHT                ((uint32_t)0x00000002U)         /* !< Every day at midnight (00:00). */
#define RTC_CTL_RTCTEVTX_NOON                    ((uint32_t)0x00000003U)         /* !< Every day at noon (12:00). */
/* RTC_CTL[RTCBCD] Bits */
#define RTC_CTL_RTCBCD_OFS                       (7)                             /* !< RTCBCD Offset */
#define RTC_CTL_RTCBCD_MASK                      ((uint32_t)0x00000080U)         /* !< Real-time clock BCD select. Selects
                                                                                    BCD counting for real-time clock. */
#define RTC_CTL_RTCBCD_BINARY                    ((uint32_t)0x00000000U)         /* !< Binary code selected */
#define RTC_CTL_RTCBCD_BCD                       ((uint32_t)0x00000080U)         /* !< Binary coded decimal (BCD) code
                                                                                    selected */

/* RTC_STA Bits */
/* RTC_STA[RTCRDY] Bits */
#define RTC_STA_RTCRDY_OFS                       (0)                             /* !< RTCRDY Offset */
#define RTC_STA_RTCRDY_MASK                      ((uint32_t)0x00000001U)         /* !< Real-time clock ready. This bit
                                                                                    indicates when the real-time clock
                                                                                    time values are safe for reading. */
#define RTC_STA_RTCRDY_NOT_READY                 ((uint32_t)0x00000000U)         /* !< RTC time values in transition */
#define RTC_STA_RTCRDY_READY                     ((uint32_t)0x00000001U)         /* !< RTC time values safe for reading */
/* RTC_STA[RTCTCRDY] Bits */
#define RTC_STA_RTCTCRDY_OFS                     (1)                             /* !< RTCTCRDY Offset */
#define RTC_STA_RTCTCRDY_MASK                    ((uint32_t)0x00000002U)         /* !< Real-time clock temperature
                                                                                    compensation ready. This is a read
                                                                                    only bit that indicates when the
                                                                                    RTCTCMPx can be written. Write to
                                                                                    RTCTCMPx should be avoided when
                                                                                    RTCTCRDY is reset. */
#define RTC_STA_RTCTCRDY_NOT_READY               ((uint32_t)0x00000000U)         /* !< Real-time clock temperature
                                                                                    compensation not ready */
#define RTC_STA_RTCTCRDY_READY                   ((uint32_t)0x00000002U)         /* !< Real-time clock temperature
                                                                                    compensation ready */
/* RTC_STA[RTCTCOK] Bits */
#define RTC_STA_RTCTCOK_OFS                      (2)                             /* !< RTCTCOK Offset */
#define RTC_STA_RTCTCOK_MASK                     ((uint32_t)0x00000004U)         /* !< Real-time clock temperature
                                                                                    compensation write OK. This is a
                                                                                    read-only bit that indicates if the
                                                                                    write to RTCTCMP is successful or
                                                                                    not. */
#define RTC_STA_RTCTCOK_NOT_OK                   ((uint32_t)0x00000000U)         /* !< Write to RTCTCMPx is unsuccessful */
#define RTC_STA_RTCTCOK_OK                       ((uint32_t)0x00000004U)         /* !< Write to RTCTCMPx is successful */

/* RTC_CAL Bits */
/* RTC_CAL[RTCOCALX] Bits */
#define RTC_CAL_RTCOCALX_OFS                     (0)                             /* !< RTCOCALX Offset */
#define RTC_CAL_RTCOCALX_MASK                    ((uint32_t)0x000000FFU)         /* !< Real-time clock offset error
                                                                                    calibration. Each LSB represents
                                                                                    approximately +1ppm (RTCOCALXS = 1)
                                                                                    or -1ppm (RTCOCALXS = 0) adjustment
                                                                                    in frequency. Maximum effective
                                                                                    calibration value is +/-240ppm.
                                                                                    Excess values written above +/-240ppm
                                                                                    will be ignored by hardware. */
#define RTC_CAL_RTCOCALX_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Minimum effective calibration
                                                                                    value. */
#define RTC_CAL_RTCOCALX_MAXIMUM                 ((uint32_t)0x000000FFU)         /* !< Maximum effective calibration value
                                                                                    is +/-240ppm. Excess values written
                                                                                    above +/-240ppm will be ignored by
                                                                                    hardware. */
/* RTC_CAL[RTCOCALS] Bits */
#define RTC_CAL_RTCOCALS_OFS                     (15)                            /* !< RTCOCALS Offset */
#define RTC_CAL_RTCOCALS_MASK                    ((uint32_t)0x00008000U)         /* !< Real-time clock offset error
                                                                                    calibration sign. This bit decides
                                                                                    the sign of offset error calibration. */
#define RTC_CAL_RTCOCALS_DOWN                    ((uint32_t)0x00000000U)         /* !< Down calibration. Frequency
                                                                                    adjusted down. */
#define RTC_CAL_RTCOCALS_UP                      ((uint32_t)0x00008000U)         /* !< Up calibration. Frequency adjusted
                                                                                    up. */
/* RTC_CAL[RTCCALFX] Bits */
#define RTC_CAL_RTCCALFX_OFS                     (16)                            /* !< RTCCALFX Offset */
#define RTC_CAL_RTCCALFX_MASK                    ((uint32_t)0x00030000U)         /* !< Real-time clock calibration
                                                                                    frequency. Selects frequency output
                                                                                    to RTC_OUT pin for calibration
                                                                                    measurement. The corresponding port
                                                                                    must be configured for the peripheral
                                                                                    module function. */
#define RTC_CAL_RTCCALFX_OFF                     ((uint32_t)0x00000000U)         /* !< No frequency output to RTC_OUT pin */
#define RTC_CAL_RTCCALFX_F512HZ                  ((uint32_t)0x00010000U)         /* !< 512 Hz */
#define RTC_CAL_RTCCALFX_F256HZ                  ((uint32_t)0x00020000U)         /* !< 256 Hz */
#define RTC_CAL_RTCCALFX_F1HZ                    ((uint32_t)0x00030000U)         /* !< 1 Hz */

/* RTC_TCMP Bits */
/* RTC_TCMP[RTCTCMPX] Bits */
#define RTC_TCMP_RTCTCMPX_OFS                    (0)                             /* !< RTCTCMPX Offset */
#define RTC_TCMP_RTCTCMPX_MASK                   ((uint32_t)0x000000FFU)         /* !< Real-time clock temperature
                                                                                    compensation. Value written into this
                                                                                    register is used for temperature
                                                                                    compensation of RTC. Each LSB
                                                                                    represents approximately +1ppm
                                                                                    (RTCTCMPS = 1) or -1ppm (RTCTCMPS =
                                                                                    0) adjustment in frequency. Maximum
                                                                                    effective calibration value is
                                                                                    +/-240ppm. Excess values written
                                                                                    above +/-240ppm are ignored by
                                                                                    hardware. Reading from RTCTCMP
                                                                                    register at any time returns the
                                                                                    cumulative value which is the signed
                                                                                    addition of RTCOCALx and RTCTCMPX
                                                                                    values, and the updated sign bit
                                                                                    (RTCTCMPS) of the addition result. */
#define RTC_TCMP_RTCTCMPX_MINIMUM                ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_TCMP_RTCTCMPX_MAXIMUM                ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* RTC_TCMP[RTCTCMPS] Bits */
#define RTC_TCMP_RTCTCMPS_OFS                    (15)                            /* !< RTCTCMPS Offset */
#define RTC_TCMP_RTCTCMPS_MASK                   ((uint32_t)0x00008000U)         /* !< Real-time clock temperature
                                                                                    compensation sign. This bit decides
                                                                                    the sign of temperature compensation. */
#define RTC_TCMP_RTCTCMPS_DOWN                   ((uint32_t)0x00000000U)         /* !< Down calibration. Frequency
                                                                                    adjusted down. */
#define RTC_TCMP_RTCTCMPS_UP                     ((uint32_t)0x00008000U)         /* !< Up calibration. Frequency adjusted
                                                                                    up. */

/* RTC_SEC Bits */
/* RTC_SEC[SECBIN] Bits */
#define RTC_SEC_SECBIN_OFS                       (0)                             /* !< SECBIN Offset */
#define RTC_SEC_SECBIN_MASK                      ((uint32_t)0x0000003FU)         /* !< Seconds Binary (0 to 59). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_SEC_SECBIN_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_SEC_SECBIN_MAXIMUM                   ((uint32_t)0x0000003BU)         /* !< Maximum value */
/* RTC_SEC[SECLOWBCD] Bits */
#define RTC_SEC_SECLOWBCD_OFS                    (8)                             /* !< SECLOWBCD Offset */
#define RTC_SEC_SECLOWBCD_MASK                   ((uint32_t)0x00000F00U)         /* !< Seconds BCD  low digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_SEC_SECLOWBCD_MINIMUM                ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_SEC_SECLOWBCD_MAXIMUM                ((uint32_t)0x00000900U)         /* !< Maximum value */
/* RTC_SEC[SECHIGHBCD] Bits */
#define RTC_SEC_SECHIGHBCD_OFS                   (12)                            /* !< SECHIGHBCD Offset */
#define RTC_SEC_SECHIGHBCD_MASK                  ((uint32_t)0x00007000U)         /* !< Seconds BCD  high digit (0 to 5).
                                                                                    If RTCBCD=0 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define RTC_SEC_SECHIGHBCD_MINIMUM               ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_SEC_SECHIGHBCD_MAXIMUM               ((uint32_t)0x00005000U)         /* !< Maximum value */

/* RTC_MIN Bits */
/* RTC_MIN[MINBIN] Bits */
#define RTC_MIN_MINBIN_OFS                       (0)                             /* !< MINBIN Offset */
#define RTC_MIN_MINBIN_MASK                      ((uint32_t)0x0000003FU)         /* !< Minutes Binary (0 to 59). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_MIN_MINBIN_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_MIN_MINBIN_MAXIMUM                   ((uint32_t)0x0000003BU)         /* !< Maximum value */
/* RTC_MIN[MINLOWBCD] Bits */
#define RTC_MIN_MINLOWBCD_OFS                    (8)                             /* !< MINLOWBCD Offset */
#define RTC_MIN_MINLOWBCD_MASK                   ((uint32_t)0x00000F00U)         /* !< Minutes BCD  low digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_MIN_MINLOWBCD_MINIMUM                ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_MIN_MINLOWBCD_MAXIMUM                ((uint32_t)0x00000900U)         /* !< Maximum value */
/* RTC_MIN[MINHIGHBCD] Bits */
#define RTC_MIN_MINHIGHBCD_OFS                   (12)                            /* !< MINHIGHBCD Offset */
#define RTC_MIN_MINHIGHBCD_MASK                  ((uint32_t)0x00007000U)         /* !< Minutes BCD  high digit (0 to 5).
                                                                                    If RTCBCD=0 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define RTC_MIN_MINHIGHBCD_MINIMUM               ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_MIN_MINHIGHBCD_MAXIMUM               ((uint32_t)0x00005000U)         /* !< Maximum value */

/* RTC_HOUR Bits */
/* RTC_HOUR[HOURBIN] Bits */
#define RTC_HOUR_HOURBIN_OFS                     (0)                             /* !< HOURBIN Offset */
#define RTC_HOUR_HOURBIN_MASK                    ((uint32_t)0x0000001FU)         /* !< Hours Binary (0 to 23). If RTCBCD=1
                                                                                    write to these bits will be ignored
                                                                                    and read give the value 0. */
#define RTC_HOUR_HOURBIN_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Minimum value. */
#define RTC_HOUR_HOURBIN_MAXIMUM                 ((uint32_t)0x00000017U)         /* !< Maximum value. */
/* RTC_HOUR[HOURLOWBCD] Bits */
#define RTC_HOUR_HOURLOWBCD_OFS                  (8)                             /* !< HOURLOWBCD Offset */
#define RTC_HOUR_HOURLOWBCD_MASK                 ((uint32_t)0x00000F00U)         /* !< Hours BCD  low digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_HOUR_HOURLOWBCD_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum value. */
#define RTC_HOUR_HOURLOWBCD_MAXIMUM              ((uint32_t)0x00000900U)         /* !< Maximum value. */
/* RTC_HOUR[HOURHIGHBCD] Bits */
#define RTC_HOUR_HOURHIGHBCD_OFS                 (12)                            /* !< HOURHIGHBCD Offset */
#define RTC_HOUR_HOURHIGHBCD_MASK                ((uint32_t)0x00003000U)         /* !< Hours BCD  high digit (0 to 2). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_HOUR_HOURHIGHBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Minimum value. */
#define RTC_HOUR_HOURHIGHBCD_MAXIMUM             ((uint32_t)0x00002000U)         /* !< Maximum value. */

/* RTC_DAY Bits */
/* RTC_DAY[DOW] Bits */
#define RTC_DAY_DOW_OFS                          (0)                             /* !< DOW Offset */
#define RTC_DAY_DOW_MASK                         ((uint32_t)0x00000007U)         /* !< Day of week (0 to 6). These bits
                                                                                    are valid if RTCBCD=1 or RTCBCD=0. */
#define RTC_DAY_DOW_MINIMUM                      ((uint32_t)0x00000000U)         /* !< Mimimum value */
#define RTC_DAY_DOW_MAXIMUM                      ((uint32_t)0x00000006U)         /* !< Maximum value */
/* RTC_DAY[DOMBIN] Bits */
#define RTC_DAY_DOMBIN_OFS                       (8)                             /* !< DOMBIN Offset */
#define RTC_DAY_DOMBIN_MASK                      ((uint32_t)0x00001F00U)         /* !< Day of month Binary (1 to 28, 29,
                                                                                    30, 31). If RTCBCD=1 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_DAY_DOMBIN_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Mimimum value */
#define RTC_DAY_DOMBIN_MAXIMUM                   ((uint32_t)0x00001F00U)         /* !< Maximum value */
/* RTC_DAY[DOMLOWBCD] Bits */
#define RTC_DAY_DOMLOWBCD_OFS                    (16)                            /* !< DOMLOWBCD Offset */
#define RTC_DAY_DOMLOWBCD_MASK                   ((uint32_t)0x000F0000U)         /* !< Day of month BCD  low digit (0 to
                                                                                    9). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define RTC_DAY_DOMLOWBCD_MINIMUM                ((uint32_t)0x00000000U)         /* !< Mimimum value */
#define RTC_DAY_DOMLOWBCD_MAXIMUM                ((uint32_t)0x00090000U)         /* !< Maximum value */
/* RTC_DAY[DOMHIGHBCD] Bits */
#define RTC_DAY_DOMHIGHBCD_OFS                   (20)                            /* !< DOMHIGHBCD Offset */
#define RTC_DAY_DOMHIGHBCD_MASK                  ((uint32_t)0x00300000U)         /* !< Day of month BCD  high digit (0 to
                                                                                    3). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define RTC_DAY_DOMHIGHBCD_MINIMUM               ((uint32_t)0x00000000U)         /* !< Mimimum value */
#define RTC_DAY_DOMHIGHBCD_MAXIMUM               ((uint32_t)0x00300000U)         /* !< Maximum value */

/* RTC_MON Bits */
/* RTC_MON[MONBIN] Bits */
#define RTC_MON_MONBIN_OFS                       (0)                             /* !< MONBIN Offset */
#define RTC_MON_MONBIN_MASK                      ((uint32_t)0x0000000FU)         /* !< Month Binary (1 to 12). If RTCBCD=1
                                                                                    write to these bits will be ignored
                                                                                    and read give the value 0. */
#define RTC_MON_MONBIN_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Mimimum value */
#define RTC_MON_MONBIN_MAXIMUM                   ((uint32_t)0x0000000CU)         /* !< Maximum value */
/* RTC_MON[MONLOWBCD] Bits */
#define RTC_MON_MONLOWBCD_OFS                    (8)                             /* !< MONLOWBCD Offset */
#define RTC_MON_MONLOWBCD_MASK                   ((uint32_t)0x00000F00U)         /* !< Month BCD  low digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_MON_MONLOWBCD_MINIMUM                ((uint32_t)0x00000000U)         /* !< Mimimum value */
#define RTC_MON_MONLOWBCD_MAXIMUM                ((uint32_t)0x00000900U)         /* !< Maximum value */
/* RTC_MON[MONHIGHBCD] Bits */
#define RTC_MON_MONHIGHBCD_OFS                   (12)                            /* !< MONHIGHBCD Offset */
#define RTC_MON_MONHIGHBCD_MASK                  ((uint32_t)0x00001000U)         /* !< Month BCD  high digit (0 or 1). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_MON_MONHIGHBCD_MINIMUM               ((uint32_t)0x00000000U)         /* !< Mimimum value */
#define RTC_MON_MONHIGHBCD_MAXIMUM               ((uint32_t)0x00001000U)         /* !< Maximum value */

/* RTC_YEAR Bits */
/* RTC_YEAR[YEARLOWBIN] Bits */
#define RTC_YEAR_YEARLOWBIN_OFS                  (0)                             /* !< YEARLOWBIN Offset */
#define RTC_YEAR_YEARLOWBIN_MASK                 ((uint32_t)0x000000FFU)         /* !< Year Binary  low byte. Valid values
                                                                                    for Year are 0 to 4095. If RTCBCD=1
                                                                                    write to these bits will be ignored
                                                                                    and read give the value 0. */
#define RTC_YEAR_YEARLOWBIN_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_YEAR_YEARLOWBIN_MAXIMUM              ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* RTC_YEAR[YEARHIGHBIN] Bits */
#define RTC_YEAR_YEARHIGHBIN_OFS                 (8)                             /* !< YEARHIGHBIN Offset */
#define RTC_YEAR_YEARHIGHBIN_MASK                ((uint32_t)0x00000F00U)         /* !< Year Binary  high byte. Valid
                                                                                    values for Year are 0 to 4095. If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_YEAR_YEARHIGHBIN_MINIMUM             ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_YEAR_YEARHIGHBIN_MAXIMUM             ((uint32_t)0x00000F00U)         /* !< Maximum value */
/* RTC_YEAR[YEARLOWESTBCD] Bits */
#define RTC_YEAR_YEARLOWESTBCD_OFS               (16)                            /* !< YEARLOWESTBCD Offset */
#define RTC_YEAR_YEARLOWESTBCD_MASK              ((uint32_t)0x000F0000U)         /* !< Year BCD  lowest digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_YEAR_YEARLOWESTBCD_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_YEAR_YEARLOWESTBCD_MAXIMUM           ((uint32_t)0x00090000U)         /* !< Maximum value */
/* RTC_YEAR[DECADEBCD] Bits */
#define RTC_YEAR_DECADEBCD_OFS                   (20)                            /* !< DECADEBCD Offset */
#define RTC_YEAR_DECADEBCD_MASK                  ((uint32_t)0x00F00000U)         /* !< Decade BCD (0 to 9). If RTCBCD=0
                                                                                    write to these bits will be ignored
                                                                                    and read give the value 0. */
#define RTC_YEAR_DECADEBCD_MINIMUM               ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_YEAR_DECADEBCD_MAXIMUM               ((uint32_t)0x00900000U)         /* !< Maximum value */
/* RTC_YEAR[CENTLOWBCD] Bits */
#define RTC_YEAR_CENTLOWBCD_OFS                  (24)                            /* !< CENTLOWBCD Offset */
#define RTC_YEAR_CENTLOWBCD_MASK                 ((uint32_t)0x0F000000U)         /* !< Century BCD  low digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_YEAR_CENTLOWBCD_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_YEAR_CENTLOWBCD_MAXIMUM              ((uint32_t)0x09000000U)         /* !< Maximum value */
/* RTC_YEAR[CENTHIGHBCD] Bits */
#define RTC_YEAR_CENTHIGHBCD_OFS                 (28)                            /* !< CENTHIGHBCD Offset */
#define RTC_YEAR_CENTHIGHBCD_MASK                ((uint32_t)0x70000000U)         /* !< Century BCD  high digit (0 to 4).
                                                                                    If RTCBCD=0 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define RTC_YEAR_CENTHIGHBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_YEAR_CENTHIGHBCD_MAXIMUM             ((uint32_t)0x40000000U)         /* !< Maximum value */

/* RTC_A1MIN Bits */
/* RTC_A1MIN[AMINBIN] Bits */
#define RTC_A1MIN_AMINBIN_OFS                    (0)                             /* !< AMINBIN Offset */
#define RTC_A1MIN_AMINBIN_MASK                   ((uint32_t)0x0000003FU)         /* !< Alarm Minutes Binary (0 to 59). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_A1MIN_AMINBIN_MINIMUM                ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A1MIN_AMINBIN_MAXIMUM                ((uint32_t)0x0000003BU)         /* !< Maximum value */
/* RTC_A1MIN[AMINAEBIN] Bits */
#define RTC_A1MIN_AMINAEBIN_OFS                  (7)                             /* !< AMINAEBIN Offset */
#define RTC_A1MIN_AMINAEBIN_MASK                 ((uint32_t)0x00000080U)         /* !< Alarm Minutes Binary enable. If
                                                                                    RTCBCD=1 this bit is always 0. Write
                                                                                    to this bit will be ignored. */
#define RTC_A1MIN_AMINAEBIN_DISABLE              ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A1MIN_AMINAEBIN_ENABLE               ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* RTC_A1MIN[AMINLOWBCD] Bits */
#define RTC_A1MIN_AMINLOWBCD_OFS                 (8)                             /* !< AMINLOWBCD Offset */
#define RTC_A1MIN_AMINLOWBCD_MASK                ((uint32_t)0x00000F00U)         /* !< Alarm Minutes BCD  low digit (0 to
                                                                                    9). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define RTC_A1MIN_AMINLOWBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A1MIN_AMINLOWBCD_MAXIMUM             ((uint32_t)0x00000900U)         /* !< Maximum value */
/* RTC_A1MIN[AMINHIGHBCD] Bits */
#define RTC_A1MIN_AMINHIGHBCD_OFS                (12)                            /* !< AMINHIGHBCD Offset */
#define RTC_A1MIN_AMINHIGHBCD_MASK               ((uint32_t)0x00007000U)         /* !< Alarm Minutes BCD  high digit (0 to
                                                                                    5). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define RTC_A1MIN_AMINHIGHBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A1MIN_AMINHIGHBCD_MAXIMUM            ((uint32_t)0x00005000U)         /* !< Maximum value */
/* RTC_A1MIN[AMINAEBCD] Bits */
#define RTC_A1MIN_AMINAEBCD_OFS                  (15)                            /* !< AMINAEBCD Offset */
#define RTC_A1MIN_AMINAEBCD_MASK                 ((uint32_t)0x00008000U)         /* !< Alarm Minutes BCD enable. If
                                                                                    RTCBCD=0 this bit is always 0. Write
                                                                                    to this bit will be ignored. */
#define RTC_A1MIN_AMINAEBCD_DISABLE              ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A1MIN_AMINAEBCD_ENABLE               ((uint32_t)0x00008000U)         /* !< Alarm enabled */

/* RTC_A1HOUR Bits */
/* RTC_A1HOUR[AHOURBIN] Bits */
#define RTC_A1HOUR_AHOURBIN_OFS                  (0)                             /* !< AHOURBIN Offset */
#define RTC_A1HOUR_AHOURBIN_MASK                 ((uint32_t)0x0000001FU)         /* !< Alarm Hours Binary (0 to 23). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_A1HOUR_AHOURBIN_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A1HOUR_AHOURBIN_MAXIMUM              ((uint32_t)0x00000017U)         /* !< Maximum value */
/* RTC_A1HOUR[AHOURAEBIN] Bits */
#define RTC_A1HOUR_AHOURAEBIN_OFS                (7)                             /* !< AHOURAEBIN Offset */
#define RTC_A1HOUR_AHOURAEBIN_MASK               ((uint32_t)0x00000080U)         /* !< Alarm Hours Binary enable. If
                                                                                    RTCBCD=1 this bit is always 0. Write
                                                                                    to this bit will be ignored. */
#define RTC_A1HOUR_AHOURAEBIN_DISABLE            ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A1HOUR_AHOURAEBIN_ENABLE             ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* RTC_A1HOUR[AHOURLOWBCD] Bits */
#define RTC_A1HOUR_AHOURLOWBCD_OFS               (8)                             /* !< AHOURLOWBCD Offset */
#define RTC_A1HOUR_AHOURLOWBCD_MASK              ((uint32_t)0x00000F00U)         /* !< Alarm Hours BCD  low digit (0 to
                                                                                    9). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define RTC_A1HOUR_AHOURLOWBCD_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A1HOUR_AHOURLOWBCD_MAXIMUM           ((uint32_t)0x00000900U)         /* !< Maximum value */
/* RTC_A1HOUR[AHOURHIGHBCD] Bits */
#define RTC_A1HOUR_AHOURHIGHBCD_OFS              (12)                            /* !< AHOURHIGHBCD Offset */
#define RTC_A1HOUR_AHOURHIGHBCD_MASK             ((uint32_t)0x00003000U)         /* !< Alarm Hours BCD  high digit (0 to
                                                                                    2). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0.. */
#define RTC_A1HOUR_AHOURHIGHBCD_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A1HOUR_AHOURHIGHBCD_MAXIMUM          ((uint32_t)0x00002000U)         /* !< Maximum value */
/* RTC_A1HOUR[AHOURAEBCD] Bits */
#define RTC_A1HOUR_AHOURAEBCD_OFS                (15)                            /* !< AHOURAEBCD Offset */
#define RTC_A1HOUR_AHOURAEBCD_MASK               ((uint32_t)0x00008000U)         /* !< Alarm Hours BCD enable. If RTCBCD=0
                                                                                    this bit is always 0. Write to this
                                                                                    bit will be ignored. */
#define RTC_A1HOUR_AHOURAEBCD_DISABLE            ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A1HOUR_AHOURAEBCD_ENABLE             ((uint32_t)0x00008000U)         /* !< Alarm enabled */

/* RTC_A1DAY Bits */
/* RTC_A1DAY[ADOW] Bits */
#define RTC_A1DAY_ADOW_OFS                       (0)                             /* !< ADOW Offset */
#define RTC_A1DAY_ADOW_MASK                      ((uint32_t)0x00000007U)         /* !< Alarm Day of week (0 to 6). These
                                                                                    bits are valid if RTCBCD=1 or
                                                                                    RTCBCD=0. */
#define RTC_A1DAY_ADOW_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A1DAY_ADOW_MAXIMUM                   ((uint32_t)0x00000006U)         /* !< Maximum value */
/* RTC_A1DAY[ADOWAE] Bits */
#define RTC_A1DAY_ADOWAE_OFS                     (7)                             /* !< ADOWAE Offset */
#define RTC_A1DAY_ADOWAE_MASK                    ((uint32_t)0x00000080U)         /* !< Alarm Day of week enable. This bit
                                                                                    are valid if RTCBCD=1 or RTCBCD=0. */
#define RTC_A1DAY_ADOWAE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A1DAY_ADOWAE_ENABLE                  ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* RTC_A1DAY[ADOMBIN] Bits */
#define RTC_A1DAY_ADOMBIN_OFS                    (8)                             /* !< ADOMBIN Offset */
#define RTC_A1DAY_ADOMBIN_MASK                   ((uint32_t)0x00001F00U)         /* !< Alarm Day of month Binary (1 to 28,
                                                                                    29, 30, 31) If RTCBCD=1 write to
                                                                                    these bits will be ignored and read
                                                                                    give the value 0. */
#define RTC_A1DAY_ADOMBIN_MINIMUM                ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A1DAY_ADOMBIN_MAXIMUM                ((uint32_t)0x00001F00U)         /* !< Maximum value */
/* RTC_A1DAY[ADOMAEBIN] Bits */
#define RTC_A1DAY_ADOMAEBIN_OFS                  (15)                            /* !< ADOMAEBIN Offset */
#define RTC_A1DAY_ADOMAEBIN_MASK                 ((uint32_t)0x00008000U)         /* !< Alarm Day of month Binary enable.
                                                                                    If RTCBCD=1 this bit is always 0.
                                                                                    Write to this bit will be ignored. */
#define RTC_A1DAY_ADOMAEBIN_DISABLE              ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A1DAY_ADOMAEBIN_ENABLE               ((uint32_t)0x00008000U)         /* !< Alarm enabled */
/* RTC_A1DAY[ADOMLOWBCD] Bits */
#define RTC_A1DAY_ADOMLOWBCD_OFS                 (16)                            /* !< ADOMLOWBCD Offset */
#define RTC_A1DAY_ADOMLOWBCD_MASK                ((uint32_t)0x000F0000U)         /* !< Alarm Day of month BCD  low digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_A1DAY_ADOMLOWBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A1DAY_ADOMLOWBCD_MAXIMUM             ((uint32_t)0x00090000U)         /* !< Maximum value */
/* RTC_A1DAY[ADOMHIGHBCD] Bits */
#define RTC_A1DAY_ADOMHIGHBCD_OFS                (20)                            /* !< ADOMHIGHBCD Offset */
#define RTC_A1DAY_ADOMHIGHBCD_MASK               ((uint32_t)0x00300000U)         /* !< Alarm Day of month BCD  high digit
                                                                                    (0 to 3). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_A1DAY_ADOMHIGHBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A1DAY_ADOMHIGHBCD_MAXIMUM            ((uint32_t)0x00300000U)         /* !< Maximum value */
/* RTC_A1DAY[ADOMAEBCD] Bits */
#define RTC_A1DAY_ADOMAEBCD_OFS                  (23)                            /* !< ADOMAEBCD Offset */
#define RTC_A1DAY_ADOMAEBCD_MASK                 ((uint32_t)0x00800000U)         /* !< Alarm Day of month BCD enable. If
                                                                                    RTCBCD=0 this bit is always 0. Write
                                                                                    to this bit will be ignored. */
#define RTC_A1DAY_ADOMAEBCD_DISABLE              ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A1DAY_ADOMAEBCD_ENABLE               ((uint32_t)0x00800000U)         /* !< Alarm enabled */

/* RTC_A2MIN Bits */
/* RTC_A2MIN[AMINBIN] Bits */
#define RTC_A2MIN_AMINBIN_OFS                    (0)                             /* !< AMINBIN Offset */
#define RTC_A2MIN_AMINBIN_MASK                   ((uint32_t)0x0000003FU)         /* !< Alarm Minutes Binary (0 to 59). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_A2MIN_AMINBIN_MINIMUM                ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A2MIN_AMINBIN_MAXIMUM                ((uint32_t)0x0000003BU)         /* !< Maximum value */
/* RTC_A2MIN[AMINAEBIN] Bits */
#define RTC_A2MIN_AMINAEBIN_OFS                  (7)                             /* !< AMINAEBIN Offset */
#define RTC_A2MIN_AMINAEBIN_MASK                 ((uint32_t)0x00000080U)         /* !< Alarm Minutes Binary enable. If
                                                                                    RTCBCD=1 this bit is always 0. Write
                                                                                    to this bit will be ignored. */
#define RTC_A2MIN_AMINAEBIN_DISABLE              ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A2MIN_AMINAEBIN_ENABLE               ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* RTC_A2MIN[AMINLOWBCD] Bits */
#define RTC_A2MIN_AMINLOWBCD_OFS                 (8)                             /* !< AMINLOWBCD Offset */
#define RTC_A2MIN_AMINLOWBCD_MASK                ((uint32_t)0x00000F00U)         /* !< Alarm Minutes BCD  low digit (0 to
                                                                                    9). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define RTC_A2MIN_AMINLOWBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A2MIN_AMINLOWBCD_MAXIMUM             ((uint32_t)0x00000900U)         /* !< Maximum value */
/* RTC_A2MIN[AMINHIGHBCD] Bits */
#define RTC_A2MIN_AMINHIGHBCD_OFS                (12)                            /* !< AMINHIGHBCD Offset */
#define RTC_A2MIN_AMINHIGHBCD_MASK               ((uint32_t)0x00007000U)         /* !< Alarm Minutes BCD  high digit (0 to
                                                                                    5). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define RTC_A2MIN_AMINHIGHBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A2MIN_AMINHIGHBCD_MAXIMUM            ((uint32_t)0x00005000U)         /* !< Maximum value */
/* RTC_A2MIN[AMINAEBCD] Bits */
#define RTC_A2MIN_AMINAEBCD_OFS                  (15)                            /* !< AMINAEBCD Offset */
#define RTC_A2MIN_AMINAEBCD_MASK                 ((uint32_t)0x00008000U)         /* !< Alarm Minutes BCD enable. If
                                                                                    RTCBCD=0 this bit is always 0. Write
                                                                                    to this bit will be ignored. */
#define RTC_A2MIN_AMINAEBCD_DISABLE              ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A2MIN_AMINAEBCD_ENABLE               ((uint32_t)0x00008000U)         /* !< Alarm enabled */

/* RTC_A2HOUR Bits */
/* RTC_A2HOUR[AHOURBIN] Bits */
#define RTC_A2HOUR_AHOURBIN_OFS                  (0)                             /* !< AHOURBIN Offset */
#define RTC_A2HOUR_AHOURBIN_MASK                 ((uint32_t)0x0000001FU)         /* !< Alarm Hours Binary (0 to 23). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_A2HOUR_AHOURBIN_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A2HOUR_AHOURBIN_MAXIMUM              ((uint32_t)0x00000017U)         /* !< Maximum value */
/* RTC_A2HOUR[AHOURAEBIN] Bits */
#define RTC_A2HOUR_AHOURAEBIN_OFS                (7)                             /* !< AHOURAEBIN Offset */
#define RTC_A2HOUR_AHOURAEBIN_MASK               ((uint32_t)0x00000080U)         /* !< Alarm Hours Binary enable. If
                                                                                    RTCBCD=1 this bit is always 0. Write
                                                                                    to this bit will be ignored. */
#define RTC_A2HOUR_AHOURAEBIN_DISABLE            ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A2HOUR_AHOURAEBIN_ENABLE             ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* RTC_A2HOUR[AHOURLOWBCD] Bits */
#define RTC_A2HOUR_AHOURLOWBCD_OFS               (8)                             /* !< AHOURLOWBCD Offset */
#define RTC_A2HOUR_AHOURLOWBCD_MASK              ((uint32_t)0x00000F00U)         /* !< Alarm Hours BCD  low digit (0 to
                                                                                    9). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define RTC_A2HOUR_AHOURLOWBCD_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A2HOUR_AHOURLOWBCD_MAXIMUM           ((uint32_t)0x00000900U)         /* !< Maximum value */
/* RTC_A2HOUR[AHOURHIGHBCD] Bits */
#define RTC_A2HOUR_AHOURHIGHBCD_OFS              (12)                            /* !< AHOURHIGHBCD Offset */
#define RTC_A2HOUR_AHOURHIGHBCD_MASK             ((uint32_t)0x00003000U)         /* !< Alarm Hours BCD  high digit (0 to
                                                                                    2). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0.. */
#define RTC_A2HOUR_AHOURHIGHBCD_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A2HOUR_AHOURHIGHBCD_MAXIMUM          ((uint32_t)0x00002000U)         /* !< Maximum value */
/* RTC_A2HOUR[AHOURAEBCD] Bits */
#define RTC_A2HOUR_AHOURAEBCD_OFS                (15)                            /* !< AHOURAEBCD Offset */
#define RTC_A2HOUR_AHOURAEBCD_MASK               ((uint32_t)0x00008000U)         /* !< Alarm Hours BCD enable. If RTCBCD=0
                                                                                    this bit is always 0. Write to this
                                                                                    bit will be ignored. */
#define RTC_A2HOUR_AHOURAEBCD_DISABLE            ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A2HOUR_AHOURAEBCD_ENABLE             ((uint32_t)0x00008000U)         /* !< Alarm enabled */

/* RTC_A2DAY Bits */
/* RTC_A2DAY[ADOW] Bits */
#define RTC_A2DAY_ADOW_OFS                       (0)                             /* !< ADOW Offset */
#define RTC_A2DAY_ADOW_MASK                      ((uint32_t)0x00000007U)         /* !< Alarm Day of week (0 to 6). These
                                                                                    bits are valid if RTCBCD=1 or
                                                                                    RTCBCD=0. */
#define RTC_A2DAY_ADOW_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A2DAY_ADOW_MAXIMUM                   ((uint32_t)0x00000006U)         /* !< Maximum value */
/* RTC_A2DAY[ADOWAE] Bits */
#define RTC_A2DAY_ADOWAE_OFS                     (7)                             /* !< ADOWAE Offset */
#define RTC_A2DAY_ADOWAE_MASK                    ((uint32_t)0x00000080U)         /* !< Alarm Day of week enable. This bit
                                                                                    are valid if RTCBCD=1 or RTCBCD=0. */
#define RTC_A2DAY_ADOWAE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A2DAY_ADOWAE_ENABLE                  ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* RTC_A2DAY[ADOMBIN] Bits */
#define RTC_A2DAY_ADOMBIN_OFS                    (8)                             /* !< ADOMBIN Offset */
#define RTC_A2DAY_ADOMBIN_MASK                   ((uint32_t)0x00001F00U)         /* !< Alarm Day of month Binary (1 to 28,
                                                                                    29, 30, 31) If RTCBCD=1 write to
                                                                                    these bits will be ignored and read
                                                                                    give the value 0. */
#define RTC_A2DAY_ADOMBIN_MINIMUM                ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A2DAY_ADOMBIN_MAXIMUM                ((uint32_t)0x00001F00U)         /* !< Maximum value */
/* RTC_A2DAY[ADOMAEBIN] Bits */
#define RTC_A2DAY_ADOMAEBIN_OFS                  (15)                            /* !< ADOMAEBIN Offset */
#define RTC_A2DAY_ADOMAEBIN_MASK                 ((uint32_t)0x00008000U)         /* !< Alarm Day of month Binary enable.
                                                                                    If RTCBCD=1 this bit is always 0.
                                                                                    Write to this bit will be ignored. */
#define RTC_A2DAY_ADOMAEBIN_DISABLE              ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A2DAY_ADOMAEBIN_ENABLE               ((uint32_t)0x00008000U)         /* !< Alarm enabled */
/* RTC_A2DAY[ADOMLOWBCD] Bits */
#define RTC_A2DAY_ADOMLOWBCD_OFS                 (16)                            /* !< ADOMLOWBCD Offset */
#define RTC_A2DAY_ADOMLOWBCD_MASK                ((uint32_t)0x000F0000U)         /* !< Alarm Day of month BCD  low digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_A2DAY_ADOMLOWBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A2DAY_ADOMLOWBCD_MAXIMUM             ((uint32_t)0x00090000U)         /* !< Maximum value */
/* RTC_A2DAY[ADOMHIGHBCD] Bits */
#define RTC_A2DAY_ADOMHIGHBCD_OFS                (20)                            /* !< ADOMHIGHBCD Offset */
#define RTC_A2DAY_ADOMHIGHBCD_MASK               ((uint32_t)0x00300000U)         /* !< Alarm Day of month BCD  high digit
                                                                                    (0 to 3). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_A2DAY_ADOMHIGHBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value */
#define RTC_A2DAY_ADOMHIGHBCD_MAXIMUM            ((uint32_t)0x00300000U)         /* !< Maximum value */
/* RTC_A2DAY[ADOMAEBCD] Bits */
#define RTC_A2DAY_ADOMAEBCD_OFS                  (23)                            /* !< ADOMAEBCD Offset */
#define RTC_A2DAY_ADOMAEBCD_MASK                 ((uint32_t)0x00800000U)         /* !< Alarm Day of month BCD enable. If
                                                                                    RTCBCD=0 this bit is always 0. Write
                                                                                    to this bit will be ignored. */
#define RTC_A2DAY_ADOMAEBCD_DISABLE              ((uint32_t)0x00000000U)         /* !< Alarm disabled */
#define RTC_A2DAY_ADOMAEBCD_ENABLE               ((uint32_t)0x00800000U)         /* !< Alarm enabled */

/* RTC_PSCTL Bits */
/* RTC_PSCTL[RT0IP] Bits */
#define RTC_PSCTL_RT0IP_OFS                      (2)                             /* !< RT0IP Offset */
#define RTC_PSCTL_RT0IP_MASK                     ((uint32_t)0x0000001CU)         /* !< Prescale timer 0 interrupt interval */
#define RTC_PSCTL_RT0IP_DIV8                     ((uint32_t)0x00000008U)         /* !< Divide by 8 - 244 microsecond
                                                                                    interval */
#define RTC_PSCTL_RT0IP_DIV16                    ((uint32_t)0x0000000CU)         /* !< Divide by 16  - 488 microsecond
                                                                                    interval */
#define RTC_PSCTL_RT0IP_DIV32                    ((uint32_t)0x00000010U)         /* !< Divide by 32 - 976 microsecond
                                                                                    interval */
#define RTC_PSCTL_RT0IP_DIV64                    ((uint32_t)0x00000014U)         /* !< Divide by 64 - 1.95 millisecond
                                                                                    interval */
#define RTC_PSCTL_RT0IP_DIV128                   ((uint32_t)0x00000018U)         /* !< Divide by 128 - 3.90 millisecond
                                                                                    interval */
#define RTC_PSCTL_RT0IP_DIV256                   ((uint32_t)0x0000001CU)         /* !< Divide by 256 - 7.81 millisecond
                                                                                    interval */
/* RTC_PSCTL[RT1IP] Bits */
#define RTC_PSCTL_RT1IP_OFS                      (18)                            /* !< RT1IP Offset */
#define RTC_PSCTL_RT1IP_MASK                     ((uint32_t)0x001C0000U)         /* !< Prescale timer 1 interrupt interval */
#define RTC_PSCTL_RT1IP_DIV2                     ((uint32_t)0x00000000U)         /* !< Divide by 2 - 15.6 millisecond
                                                                                    interval */
#define RTC_PSCTL_RT1IP_DIV4                     ((uint32_t)0x00040000U)         /* !< Divide by 4 - 31.2 millisecond
                                                                                    interval */
#define RTC_PSCTL_RT1IP_DIV8                     ((uint32_t)0x00080000U)         /* !< Divide by 8 - 62.5 millisecond
                                                                                    interval */
#define RTC_PSCTL_RT1IP_DIV16                    ((uint32_t)0x000C0000U)         /* !< Divide by 16 - 125 millisecond
                                                                                    interval */
#define RTC_PSCTL_RT1IP_DIV32                    ((uint32_t)0x00100000U)         /* !< Divide by 32 - 250 millisecond
                                                                                    interval */
#define RTC_PSCTL_RT1IP_DIV64                    ((uint32_t)0x00140000U)         /* !< Divide by 64 - 500 millisecond
                                                                                    interval */
#define RTC_PSCTL_RT1IP_DIV128                   ((uint32_t)0x00180000U)         /* !< Divide by 128 - 1 second interval */
#define RTC_PSCTL_RT1IP_DIV256                   ((uint32_t)0x001C0000U)         /* !< Divide by 256 - 2 second interval */

/* RTC_EXTPSCTL Bits */
/* RTC_EXTPSCTL[RT2PS] Bits */
#define RTC_EXTPSCTL_RT2PS_OFS                   (2)                             /* !< RT2PS Offset */
#define RTC_EXTPSCTL_RT2PS_MASK                  ((uint32_t)0x0000000CU)         /* !< Prescale timer 2 interrupt interval */
#define RTC_EXTPSCTL_RT2PS_INT4S                 ((uint32_t)0x00000000U)         /* !< Interval every 4 second */
#define RTC_EXTPSCTL_RT2PS_INT8S                 ((uint32_t)0x00000004U)         /* !< Interval every 8 second */
#define RTC_EXTPSCTL_RT2PS_INT16S                ((uint32_t)0x00000008U)         /* !< Interval every 16 second */

/* RTC_TSSEC Bits */
/* RTC_TSSEC[SECBIN] Bits */
#define RTC_TSSEC_SECBIN_OFS                     (0)                             /* !< SECBIN Offset */
#define RTC_TSSEC_SECBIN_MASK                    ((uint32_t)0x0000003FU)         /* !< Time Stamp Second Binary (0 to 59).
                                                                                    If RTCBCD=1 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define RTC_TSSEC_SECBIN_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSSEC_SECBIN_MAXIMUM                 ((uint32_t)0x0000003BU)         /* !< Highest possible value */
/* RTC_TSSEC[SECLOWBCD] Bits */
#define RTC_TSSEC_SECLOWBCD_OFS                  (8)                             /* !< SECLOWBCD Offset */
#define RTC_TSSEC_SECLOWBCD_MASK                 ((uint32_t)0x00000F00U)         /* !< Time Stamp Seconds BCD  low digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_TSSEC_SECLOWBCD_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSSEC_SECLOWBCD_MAXIMUM              ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* RTC_TSSEC[SECHIGHBCD] Bits */
#define RTC_TSSEC_SECHIGHBCD_OFS                 (12)                            /* !< SECHIGHBCD Offset */
#define RTC_TSSEC_SECHIGHBCD_MASK                ((uint32_t)0x00007000U)         /* !< Time Stamp Seconds BCD  high digit
                                                                                    (0 to 5). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_TSSEC_SECHIGHBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSSEC_SECHIGHBCD_MAXIMUM             ((uint32_t)0x00005000U)         /* !< Highest possible value */

/* RTC_TSMIN Bits */
/* RTC_TSMIN[MINBIN] Bits */
#define RTC_TSMIN_MINBIN_OFS                     (0)                             /* !< MINBIN Offset */
#define RTC_TSMIN_MINBIN_MASK                    ((uint32_t)0x0000003FU)         /* !< Time Stamp Minutes Binary (0 to
                                                                                    59). If RTCBCD=1 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define RTC_TSMIN_MINBIN_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSMIN_MINBIN_MAXIMUM                 ((uint32_t)0x0000003BU)         /* !< Highest possible value */
/* RTC_TSMIN[MINLOWBCD] Bits */
#define RTC_TSMIN_MINLOWBCD_OFS                  (8)                             /* !< MINLOWBCD Offset */
#define RTC_TSMIN_MINLOWBCD_MASK                 ((uint32_t)0x00000F00U)         /* !< Time Stamp Minutes BCD  low digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_TSMIN_MINLOWBCD_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSMIN_MINLOWBCD_MAXIMUM              ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* RTC_TSMIN[MINHIGHBCD] Bits */
#define RTC_TSMIN_MINHIGHBCD_OFS                 (12)                            /* !< MINHIGHBCD Offset */
#define RTC_TSMIN_MINHIGHBCD_MASK                ((uint32_t)0x00007000U)         /* !< Time Stamp Minutes BCD  high digit
                                                                                    (0 to 5). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_TSMIN_MINHIGHBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSMIN_MINHIGHBCD_MAXIMUM             ((uint32_t)0x00005000U)         /* !< Highest possible value */

/* RTC_TSHOUR Bits */
/* RTC_TSHOUR[HOURBIN] Bits */
#define RTC_TSHOUR_HOURBIN_OFS                   (0)                             /* !< HOURBIN Offset */
#define RTC_TSHOUR_HOURBIN_MASK                  ((uint32_t)0x0000001FU)         /* !< Time Stamp Hours Binary (0 to 23).
                                                                                    If RTCBCD=1 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define RTC_TSHOUR_HOURBIN_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSHOUR_HOURBIN_MAXIMUM               ((uint32_t)0x00000017U)         /* !< Highest possible value */
/* RTC_TSHOUR[HOURLOWBCD] Bits */
#define RTC_TSHOUR_HOURLOWBCD_OFS                (8)                             /* !< HOURLOWBCD Offset */
#define RTC_TSHOUR_HOURLOWBCD_MASK               ((uint32_t)0x00000F00U)         /* !< Time Stamp Hours BCD  low digit (0
                                                                                    to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_TSHOUR_HOURLOWBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSHOUR_HOURLOWBCD_MAXIMUM            ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* RTC_TSHOUR[HOURHIGHBCD] Bits */
#define RTC_TSHOUR_HOURHIGHBCD_OFS               (12)                            /* !< HOURHIGHBCD Offset */
#define RTC_TSHOUR_HOURHIGHBCD_MASK              ((uint32_t)0x00003000U)         /* !< Time Stamp Hours BCD  high digit (0
                                                                                    to 2). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_TSHOUR_HOURHIGHBCD_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSHOUR_HOURHIGHBCD_MAXIMUM           ((uint32_t)0x00002000U)         /* !< Highest possible value */

/* RTC_TSDAY Bits */
/* RTC_TSDAY[DOW] Bits */
#define RTC_TSDAY_DOW_OFS                        (0)                             /* !< DOW Offset */
#define RTC_TSDAY_DOW_MASK                       ((uint32_t)0x00000007U)         /* !< Time Stamp Day of week (0 to 6).
                                                                                    These bits are valid if RTCBCD=1 or
                                                                                    RTCBCD=0. */
#define RTC_TSDAY_DOW_MINIMUM                    ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSDAY_DOW_MAXIMUM                    ((uint32_t)0x00000006U)         /* !< Highest possible value */
/* RTC_TSDAY[DOMBIN] Bits */
#define RTC_TSDAY_DOMBIN_OFS                     (8)                             /* !< DOMBIN Offset */
#define RTC_TSDAY_DOMBIN_MASK                    ((uint32_t)0x00001F00U)         /* !< Time Stamp Day of month Binary (1
                                                                                    to 28, 29, 30, 31) If RTCBCD=1 write
                                                                                    to these bits will be ignored and
                                                                                    read give the value 0. */
#define RTC_TSDAY_DOMBIN_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSDAY_DOMBIN_MAXIMUM                 ((uint32_t)0x00001F00U)         /* !< Highest possible value */
/* RTC_TSDAY[DOMLOWBCD] Bits */
#define RTC_TSDAY_DOMLOWBCD_OFS                  (16)                            /* !< DOMLOWBCD Offset */
#define RTC_TSDAY_DOMLOWBCD_MASK                 ((uint32_t)0x000F0000U)         /* !< Time Stamp Day of month BCD  low
                                                                                    digit (0 to 9). If RTCBCD=0 write to
                                                                                    these bits will be ignored and read
                                                                                    give the value 0. */
#define RTC_TSDAY_DOMLOWBCD_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSDAY_DOMLOWBCD_MAXIMUM              ((uint32_t)0x00090000U)         /* !< Highest possible value */
/* RTC_TSDAY[DOMHIGHBCD] Bits */
#define RTC_TSDAY_DOMHIGHBCD_OFS                 (20)                            /* !< DOMHIGHBCD Offset */
#define RTC_TSDAY_DOMHIGHBCD_MASK                ((uint32_t)0x00300000U)         /* !< Time Stamp Day of month BCD  high
                                                                                    digit (0 to 3). If RTCBCD=0 write to
                                                                                    these bits will be ignored and read
                                                                                    give the value 0. */
#define RTC_TSDAY_DOMHIGHBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSDAY_DOMHIGHBCD_MAXIMUM             ((uint32_t)0x00300000U)         /* !< Highest possible value */

/* RTC_TSMON Bits */
/* RTC_TSMON[MONBIN] Bits */
#define RTC_TSMON_MONBIN_OFS                     (0)                             /* !< MONBIN Offset */
#define RTC_TSMON_MONBIN_MASK                    ((uint32_t)0x0000000FU)         /* !< Time Stamp Month Binary (1 to 12).
                                                                                    If RTCBCD=1 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define RTC_TSMON_MONBIN_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSMON_MONBIN_MAXIMUM                 ((uint32_t)0x0000000CU)         /* !< Highest possible value */
/* RTC_TSMON[MONLOWBCD] Bits */
#define RTC_TSMON_MONLOWBCD_OFS                  (8)                             /* !< MONLOWBCD Offset */
#define RTC_TSMON_MONLOWBCD_MASK                 ((uint32_t)0x00000F00U)         /* !< Time Stamp Month BCD  low digit (0
                                                                                    to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_TSMON_MONLOWBCD_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSMON_MONLOWBCD_MAXIMUM              ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* RTC_TSMON[MONHIGHBCD] Bits */
#define RTC_TSMON_MONHIGHBCD_OFS                 (12)                            /* !< MONHIGHBCD Offset */
#define RTC_TSMON_MONHIGHBCD_MASK                ((uint32_t)0x00001000U)         /* !< Time Stamp Month BCD  high digit (0
                                                                                    or 1). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_TSMON_MONHIGHBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSMON_MONHIGHBCD_MAXIMUM             ((uint32_t)0x00001000U)         /* !< Highest possible value */

/* RTC_TSYEAR Bits */
/* RTC_TSYEAR[YEARLOWBIN] Bits */
#define RTC_TSYEAR_YEARLOWBIN_OFS                (0)                             /* !< YEARLOWBIN Offset */
#define RTC_TSYEAR_YEARLOWBIN_MASK               ((uint32_t)0x000000FFU)         /* !< Time Stamp Year Binary  low byte.
                                                                                    Valid values for Year are 0 to 4095.
                                                                                    If RTCBCD=1 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define RTC_TSYEAR_YEARLOWBIN_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSYEAR_YEARLOWBIN_MAXIMUM            ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* RTC_TSYEAR[YEARHIGHBIN] Bits */
#define RTC_TSYEAR_YEARHIGHBIN_OFS               (8)                             /* !< YEARHIGHBIN Offset */
#define RTC_TSYEAR_YEARHIGHBIN_MASK              ((uint32_t)0x00000F00U)         /* !< Time Stamp Year Binary  high byte.
                                                                                    Valid values for Year are 0 to 4095.
                                                                                    If RTCBCD=1 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define RTC_TSYEAR_YEARHIGHBIN_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSYEAR_YEARHIGHBIN_MAXIMUM           ((uint32_t)0x00000F00U)         /* !< Highest possible value */
/* RTC_TSYEAR[YERARLOWESTBCD] Bits */
#define RTC_TSYEAR_YERARLOWESTBCD_OFS            (16)                            /* !< YERARLOWESTBCD Offset */
#define RTC_TSYEAR_YERARLOWESTBCD_MASK           ((uint32_t)0x000F0000U)         /* !< Time Stamp Year BCD  lowest digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_TSYEAR_YERARLOWESTBCD_MINIMUM        ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSYEAR_YERARLOWESTBCD_MAXIMUM        ((uint32_t)0x00090000U)         /* !< Highest possible value */
/* RTC_TSYEAR[DECADEBCD] Bits */
#define RTC_TSYEAR_DECADEBCD_OFS                 (20)                            /* !< DECADEBCD Offset */
#define RTC_TSYEAR_DECADEBCD_MASK                ((uint32_t)0x00F00000U)         /* !< Time Stamp Decade BCD (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define RTC_TSYEAR_DECADEBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSYEAR_DECADEBCD_MAXIMUM             ((uint32_t)0x00900000U)         /* !< Highest possible value */
/* RTC_TSYEAR[CENTLOWBCD] Bits */
#define RTC_TSYEAR_CENTLOWBCD_OFS                (24)                            /* !< CENTLOWBCD Offset */
#define RTC_TSYEAR_CENTLOWBCD_MASK               ((uint32_t)0x0F000000U)         /* !< Time Stamp Century BCD  low digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_TSYEAR_CENTLOWBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSYEAR_CENTLOWBCD_MAXIMUM            ((uint32_t)0x09000000U)         /* !< Highest possible value */
/* RTC_TSYEAR[CENTHIGHBCD] Bits */
#define RTC_TSYEAR_CENTHIGHBCD_OFS               (28)                            /* !< CENTHIGHBCD Offset */
#define RTC_TSYEAR_CENTHIGHBCD_MASK              ((uint32_t)0x70000000U)         /* !< Time Stamp Century BCD  high digit
                                                                                    (0 to 4). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define RTC_TSYEAR_CENTHIGHBCD_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define RTC_TSYEAR_CENTHIGHBCD_MAXIMUM           ((uint32_t)0x40000000U)         /* !< Highest possible value */

/* RTC_TSSTAT Bits */
/* RTC_TSSTAT[TSTIOEVT0] Bits */
#define RTC_TSSTAT_TSTIOEVT0_OFS                 (0)                             /* !< TSTIOEVT0 Offset */
#define RTC_TSSTAT_TSTIOEVT0_MASK                ((uint32_t)0x00000001U)         /* !< Tamper I/O 0 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT0_CLR                 ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT0_SET                 ((uint32_t)0x00000001U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT1] Bits */
#define RTC_TSSTAT_TSTIOEVT1_OFS                 (1)                             /* !< TSTIOEVT1 Offset */
#define RTC_TSSTAT_TSTIOEVT1_MASK                ((uint32_t)0x00000002U)         /* !< Tamper I/O 1 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT1_CLR                 ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT1_SET                 ((uint32_t)0x00000002U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT2] Bits */
#define RTC_TSSTAT_TSTIOEVT2_OFS                 (2)                             /* !< TSTIOEVT2 Offset */
#define RTC_TSSTAT_TSTIOEVT2_MASK                ((uint32_t)0x00000004U)         /* !< Tamper I/O 2 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT2_CLR                 ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT2_SET                 ((uint32_t)0x00000004U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT3] Bits */
#define RTC_TSSTAT_TSTIOEVT3_OFS                 (3)                             /* !< TSTIOEVT3 Offset */
#define RTC_TSSTAT_TSTIOEVT3_MASK                ((uint32_t)0x00000008U)         /* !< Tamper I/O 3 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT3_CLR                 ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT3_SET                 ((uint32_t)0x00000008U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT4] Bits */
#define RTC_TSSTAT_TSTIOEVT4_OFS                 (4)                             /* !< TSTIOEVT4 Offset */
#define RTC_TSSTAT_TSTIOEVT4_MASK                ((uint32_t)0x00000010U)         /* !< Tamper I/O 4 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT4_CLR                 ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT4_SET                 ((uint32_t)0x00000010U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT5] Bits */
#define RTC_TSSTAT_TSTIOEVT5_OFS                 (5)                             /* !< TSTIOEVT5 Offset */
#define RTC_TSSTAT_TSTIOEVT5_MASK                ((uint32_t)0x00000020U)         /* !< Tamper I/O 5 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT5_CLR                 ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT5_SET                 ((uint32_t)0x00000020U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT6] Bits */
#define RTC_TSSTAT_TSTIOEVT6_OFS                 (6)                             /* !< TSTIOEVT6 Offset */
#define RTC_TSSTAT_TSTIOEVT6_MASK                ((uint32_t)0x00000040U)         /* !< Tamper I/O 6 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT6_CLR                 ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT6_SET                 ((uint32_t)0x00000040U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT7] Bits */
#define RTC_TSSTAT_TSTIOEVT7_OFS                 (7)                             /* !< TSTIOEVT7 Offset */
#define RTC_TSSTAT_TSTIOEVT7_MASK                ((uint32_t)0x00000080U)         /* !< Tamper I/O 7 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT7_CLR                 ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT7_SET                 ((uint32_t)0x00000080U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT8] Bits */
#define RTC_TSSTAT_TSTIOEVT8_OFS                 (8)                             /* !< TSTIOEVT8 Offset */
#define RTC_TSSTAT_TSTIOEVT8_MASK                ((uint32_t)0x00000100U)         /* !< Tamper I/O 8 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT8_CLR                 ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT8_SET                 ((uint32_t)0x00000100U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT9] Bits */
#define RTC_TSSTAT_TSTIOEVT9_OFS                 (9)                             /* !< TSTIOEVT9 Offset */
#define RTC_TSSTAT_TSTIOEVT9_MASK                ((uint32_t)0x00000200U)         /* !< Tamper I/O 9 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT9_CLR                 ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT9_SET                 ((uint32_t)0x00000200U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT10] Bits */
#define RTC_TSSTAT_TSTIOEVT10_OFS                (10)                            /* !< TSTIOEVT10 Offset */
#define RTC_TSSTAT_TSTIOEVT10_MASK               ((uint32_t)0x00000400U)         /* !< Tamper I/O 10 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT10_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT10_SET                ((uint32_t)0x00000400U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT11] Bits */
#define RTC_TSSTAT_TSTIOEVT11_OFS                (11)                            /* !< TSTIOEVT11 Offset */
#define RTC_TSSTAT_TSTIOEVT11_MASK               ((uint32_t)0x00000800U)         /* !< Tamper I/O 11 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT11_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT11_SET                ((uint32_t)0x00000800U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT12] Bits */
#define RTC_TSSTAT_TSTIOEVT12_OFS                (12)                            /* !< TSTIOEVT12 Offset */
#define RTC_TSSTAT_TSTIOEVT12_MASK               ((uint32_t)0x00001000U)         /* !< Tamper I/O 12 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT12_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT12_SET                ((uint32_t)0x00001000U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT13] Bits */
#define RTC_TSSTAT_TSTIOEVT13_OFS                (13)                            /* !< TSTIOEVT13 Offset */
#define RTC_TSSTAT_TSTIOEVT13_MASK               ((uint32_t)0x00002000U)         /* !< Tamper I/O 13 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT13_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT13_SET                ((uint32_t)0x00002000U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT14] Bits */
#define RTC_TSSTAT_TSTIOEVT14_OFS                (14)                            /* !< TSTIOEVT14 Offset */
#define RTC_TSSTAT_TSTIOEVT14_MASK               ((uint32_t)0x00004000U)         /* !< Tamper I/O 14 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT14_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT14_SET                ((uint32_t)0x00004000U)         /* !< event detected */
/* RTC_TSSTAT[TSTIOEVT15] Bits */
#define RTC_TSSTAT_TSTIOEVT15_OFS                (15)                            /* !< TSTIOEVT15 Offset */
#define RTC_TSSTAT_TSTIOEVT15_MASK               ((uint32_t)0x00008000U)         /* !< Tamper I/O 15 caused time stamp
                                                                                    event */
#define RTC_TSSTAT_TSTIOEVT15_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSTIOEVT15_SET                ((uint32_t)0x00008000U)         /* !< event detected */
/* RTC_TSSTAT[TSVDDEVT] Bits */
#define RTC_TSSTAT_TSVDDEVT_OFS                  (16)                            /* !< TSVDDEVT Offset */
#define RTC_TSSTAT_TSVDDEVT_MASK                 ((uint32_t)0x00010000U)         /* !< Loss of VDD caused time stamp event */
#define RTC_TSSTAT_TSVDDEVT_CLR                  ((uint32_t)0x00000000U)         /* !< no event detected */
#define RTC_TSSTAT_TSVDDEVT_SET                  ((uint32_t)0x00010000U)         /* !< event detected */

/* RTC_TSCTL Bits */
/* RTC_TSCTL[TSTIOEN0] Bits */
#define RTC_TSCTL_TSTIOEN0_OFS                   (0)                             /* !< TSTIOEN0 Offset */
#define RTC_TSCTL_TSTIOEN0_MASK                  ((uint32_t)0x00000001U)         /* !< Time Stamp by Tamper I/O 0 enable */
#define RTC_TSCTL_TSTIOEN0_DISABLE               ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN0_ENABLE                ((uint32_t)0x00000001U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN1] Bits */
#define RTC_TSCTL_TSTIOEN1_OFS                   (1)                             /* !< TSTIOEN1 Offset */
#define RTC_TSCTL_TSTIOEN1_MASK                  ((uint32_t)0x00000002U)         /* !< Time Stamp by Tamper I/O 1 enable */
#define RTC_TSCTL_TSTIOEN1_DISABLE               ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN1_ENABLE                ((uint32_t)0x00000002U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN2] Bits */
#define RTC_TSCTL_TSTIOEN2_OFS                   (2)                             /* !< TSTIOEN2 Offset */
#define RTC_TSCTL_TSTIOEN2_MASK                  ((uint32_t)0x00000004U)         /* !< Time Stamp by Tamper I/O 2 enable */
#define RTC_TSCTL_TSTIOEN2_DISABLE               ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN2_ENABLE                ((uint32_t)0x00000004U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN3] Bits */
#define RTC_TSCTL_TSTIOEN3_OFS                   (3)                             /* !< TSTIOEN3 Offset */
#define RTC_TSCTL_TSTIOEN3_MASK                  ((uint32_t)0x00000008U)         /* !< Time Stamp by Tamper I/O 3 enable */
#define RTC_TSCTL_TSTIOEN3_DISABLE               ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN3_ENABLE                ((uint32_t)0x00000008U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN4] Bits */
#define RTC_TSCTL_TSTIOEN4_OFS                   (4)                             /* !< TSTIOEN4 Offset */
#define RTC_TSCTL_TSTIOEN4_MASK                  ((uint32_t)0x00000010U)         /* !< Time Stamp by Tamper I/O 4 enable */
#define RTC_TSCTL_TSTIOEN4_DISABLE               ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN4_ENABLE                ((uint32_t)0x00000010U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN5] Bits */
#define RTC_TSCTL_TSTIOEN5_OFS                   (5)                             /* !< TSTIOEN5 Offset */
#define RTC_TSCTL_TSTIOEN5_MASK                  ((uint32_t)0x00000020U)         /* !< Time Stamp by Tamper I/O 5 enable */
#define RTC_TSCTL_TSTIOEN5_DISABLE               ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN5_ENABLE                ((uint32_t)0x00000020U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN6] Bits */
#define RTC_TSCTL_TSTIOEN6_OFS                   (6)                             /* !< TSTIOEN6 Offset */
#define RTC_TSCTL_TSTIOEN6_MASK                  ((uint32_t)0x00000040U)         /* !< Time Stamp by Tamper I/O 6 enable */
#define RTC_TSCTL_TSTIOEN6_DISABLE               ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN6_ENABLE                ((uint32_t)0x00000040U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN7] Bits */
#define RTC_TSCTL_TSTIOEN7_OFS                   (7)                             /* !< TSTIOEN7 Offset */
#define RTC_TSCTL_TSTIOEN7_MASK                  ((uint32_t)0x00000080U)         /* !< Time Stamp by Tamper I/O 7 enable */
#define RTC_TSCTL_TSTIOEN7_DISABLE               ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN7_ENABLE                ((uint32_t)0x00000080U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN8] Bits */
#define RTC_TSCTL_TSTIOEN8_OFS                   (8)                             /* !< TSTIOEN8 Offset */
#define RTC_TSCTL_TSTIOEN8_MASK                  ((uint32_t)0x00000100U)         /* !< Time Stamp by Tamper I/O 8 enable */
#define RTC_TSCTL_TSTIOEN8_DISABLE               ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN8_ENABLE                ((uint32_t)0x00000100U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN9] Bits */
#define RTC_TSCTL_TSTIOEN9_OFS                   (9)                             /* !< TSTIOEN9 Offset */
#define RTC_TSCTL_TSTIOEN9_MASK                  ((uint32_t)0x00000200U)         /* !< Time Stamp by Tamper I/O 9 enable */
#define RTC_TSCTL_TSTIOEN9_DISABLE               ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN9_ENABLE                ((uint32_t)0x00000200U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN10] Bits */
#define RTC_TSCTL_TSTIOEN10_OFS                  (10)                            /* !< TSTIOEN10 Offset */
#define RTC_TSCTL_TSTIOEN10_MASK                 ((uint32_t)0x00000400U)         /* !< Time Stamp by Tamper I/O 10 enable */
#define RTC_TSCTL_TSTIOEN10_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN10_ENABLE               ((uint32_t)0x00000400U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN11] Bits */
#define RTC_TSCTL_TSTIOEN11_OFS                  (11)                            /* !< TSTIOEN11 Offset */
#define RTC_TSCTL_TSTIOEN11_MASK                 ((uint32_t)0x00000800U)         /* !< Time Stamp by Tamper I/O 11 enable */
#define RTC_TSCTL_TSTIOEN11_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN11_ENABLE               ((uint32_t)0x00000800U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN12] Bits */
#define RTC_TSCTL_TSTIOEN12_OFS                  (12)                            /* !< TSTIOEN12 Offset */
#define RTC_TSCTL_TSTIOEN12_MASK                 ((uint32_t)0x00001000U)         /* !< Time Stamp by Tamper I/O 12 enable */
#define RTC_TSCTL_TSTIOEN12_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN12_ENABLE               ((uint32_t)0x00001000U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN13] Bits */
#define RTC_TSCTL_TSTIOEN13_OFS                  (13)                            /* !< TSTIOEN13 Offset */
#define RTC_TSCTL_TSTIOEN13_MASK                 ((uint32_t)0x00002000U)         /* !< Time Stamp by Tamper I/O 13 enable */
#define RTC_TSCTL_TSTIOEN13_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN13_ENABLE               ((uint32_t)0x00002000U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN14] Bits */
#define RTC_TSCTL_TSTIOEN14_OFS                  (14)                            /* !< TSTIOEN14 Offset */
#define RTC_TSCTL_TSTIOEN14_MASK                 ((uint32_t)0x00004000U)         /* !< Time Stamp by Tamper I/O 14 enable */
#define RTC_TSCTL_TSTIOEN14_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN14_ENABLE               ((uint32_t)0x00004000U)         /* !< function enabled */
/* RTC_TSCTL[TSTIOEN15] Bits */
#define RTC_TSCTL_TSTIOEN15_OFS                  (15)                            /* !< TSTIOEN15 Offset */
#define RTC_TSCTL_TSTIOEN15_MASK                 ((uint32_t)0x00008000U)         /* !< Time Stamp by Tamper I/O 15 enable */
#define RTC_TSCTL_TSTIOEN15_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSTIOEN15_ENABLE               ((uint32_t)0x00008000U)         /* !< function enabled */
/* RTC_TSCTL[TSVDDEN] Bits */
#define RTC_TSCTL_TSVDDEN_OFS                    (16)                            /* !< TSVDDEN Offset */
#define RTC_TSCTL_TSVDDEN_MASK                   ((uint32_t)0x00010000U)         /* !< Time Stamp by VDD Loss detection
                                                                                    enable */
#define RTC_TSCTL_TSVDDEN_DISABLE                ((uint32_t)0x00000000U)         /* !< function disabled */
#define RTC_TSCTL_TSVDDEN_ENABLE                 ((uint32_t)0x00010000U)         /* !< function enabled */
/* RTC_TSCTL[TSCAPTURE] Bits */
#define RTC_TSCTL_TSCAPTURE_OFS                  (20)                            /* !< TSCAPTURE Offset */
#define RTC_TSCTL_TSCAPTURE_MASK                 ((uint32_t)0x00100000U)         /* !< Defines the capture method of the
                                                                                    RTC timestamp when a time stamp event
                                                                                    occurens. */
#define RTC_TSCTL_TSCAPTURE_FIRST                ((uint32_t)0x00000000U)         /* !< Time stamp holds RTC capture at
                                                                                    first occurrence of time stamp event. */
#define RTC_TSCTL_TSCAPTURE_LAST                 ((uint32_t)0x00100000U)         /* !< Time stamp holds RTC capture at
                                                                                    last occurrence of time stamp event. */
/* RTC_TSCTL[KEY] Bits */
#define RTC_TSCTL_KEY_OFS                        (24)                            /* !< KEY Offset */
#define RTC_TSCTL_KEY_MASK                       ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xC5) to update
                                                                                    this register */
#define RTC_TSCTL_KEY_UNLOCK_W                   ((uint32_t)0xC5000000U)         /* !< This field must be written with
                                                                                    0xC5 to be able to clear any of the
                                                                                    enable bits */

/* RTC_TSCLR Bits */
/* RTC_TSCLR[CLR] Bits */
#define RTC_TSCLR_CLR_OFS                        (0)                             /* !< CLR Offset */
#define RTC_TSCLR_CLR_MASK                       ((uint32_t)0x00000001U)         /* !< Clear time stamp and status
                                                                                    register. */
#define RTC_TSCLR_CLR_NO_EFFECT                  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define RTC_TSCLR_CLR_CLR                        ((uint32_t)0x00000001U)         /* !< clear time stamp event */
/* RTC_TSCLR[KEY] Bits */
#define RTC_TSCLR_KEY_OFS                        (24)                            /* !< KEY Offset */
#define RTC_TSCLR_KEY_MASK                       ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xE2) to update
                                                                                    this register */
#define RTC_TSCLR_KEY_UNLOCK_W                   ((uint32_t)0xE2000000U)         /* !< This field must be written with
                                                                                    0xE2 to be able to clear any of the
                                                                                    enable bits */

/* RTC_LFSSRST Bits */
/* RTC_LFSSRST[VBATPOR] Bits */
#define RTC_LFSSRST_VBATPOR_OFS                  (0)                             /* !< VBATPOR Offset */
#define RTC_LFSSRST_VBATPOR_MASK                 ((uint32_t)0x00000001U)         /* !< If set, the register bit will
                                                                                    request a power on reset to the PMU
                                                                                    of the LFSS. */
#define RTC_LFSSRST_VBATPOR_NO_EFFECT            ((uint32_t)0x00000000U)         /* !< Writing this value has no effect. */
#define RTC_LFSSRST_VBATPOR_SET                  ((uint32_t)0x00000001U)         /* !< Request power on reset to the LFSS. */
/* RTC_LFSSRST[KEY] Bits */
#define RTC_LFSSRST_KEY_OFS                      (24)                            /* !< KEY Offset */
#define RTC_LFSSRST_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0x12) to update
                                                                                    this register */
#define RTC_LFSSRST_KEY_UNLOCK_W                 ((uint32_t)0x12000000U)         /* !< This field must be written with
                                                                                    0x12 to be able to request the power
                                                                                    on reset. */

/* RTC_RTCLOCK Bits */
/* RTC_RTCLOCK[PROTECT] Bits */
#define RTC_RTCLOCK_PROTECT_OFS                  (0)                             /* !< PROTECT Offset */
#define RTC_RTCLOCK_PROTECT_MASK                 ((uint32_t)0x00000001U)         /* !< If set, the register bit will
                                                                                    protect the CLKCTL, SEC, MIN, HOUR,
                                                                                    DAY, MON, YEAR and LFSSRST from
                                                                                    accidental writes. */
#define RTC_RTCLOCK_PROTECT_CLR                  ((uint32_t)0x00000000U)         /* !< RTC counter is writable. */
#define RTC_RTCLOCK_PROTECT_SET                  ((uint32_t)0x00000001U)         /* !< RTC counter is read only access. */
/* RTC_RTCLOCK[KEY] Bits */
#define RTC_RTCLOCK_KEY_OFS                      (24)                            /* !< KEY Offset */
#define RTC_RTCLOCK_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0x22) to update
                                                                                    this register */
#define RTC_RTCLOCK_KEY_UNLOCK_W                 ((uint32_t)0x22000000U)         /* !< This field must be written with
                                                                                    0x22 to be able to update any of the
                                                                                    bits. */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_rtc__include */

