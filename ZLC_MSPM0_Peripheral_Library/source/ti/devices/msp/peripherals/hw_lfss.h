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

#ifndef ti_devices_msp_peripherals_hw_lfss__include
#define ti_devices_msp_peripherals_hw_lfss__include

/* Filename: hw_lfss.h */
/* Revised: 2023-09-04 05:06:06 */
/* Revision: 031875008c19c251e8c3a56bbee9e382e723e74e */

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
* LFSS Registers
******************************************************************************/
#define LFSS_IPSPECIFIC_MEM_OFS                  ((uint32_t)0x00001400U)
#define LFSS_IPSPECIFIC_WDT_OFS                  ((uint32_t)0x00001300U)
#define LFSS_IPSPECIFIC_TIO_OFS                  ((uint32_t)0x00001200U)
#define LFSS_IPSPECIFIC_RTC_OFS                  ((uint32_t)0x00001100U)
#define LFSS_GEN_EVENT_OFS                       ((uint32_t)0x00001050U)
#define LFSS_CPU_INT_OFS                         ((uint32_t)0x00001020U)


/** @addtogroup LFSS_IPSPECIFIC_MEM
  @{
*/

typedef struct {
  __IO uint32_t SPMEM[32];                         /* !< (@ 0x00001400) Scratch Pad Memory Data Register */
       uint32_t RESERVED0[32];
  __IO uint32_t SPMWPROT0;                         /* !< (@ 0x00001500) Scratch Pad Memory Write Protect Register 0 */
  __IO uint32_t SPMWPROT1;                         /* !< (@ 0x00001504) Scratch Pad Memory Write Protect Register 1 */
  __IO uint32_t SPMWPROT2;                         /* !< (@ 0x00001508) Scratch Pad Memory Write Protect Register 2 */
  __IO uint32_t SPMWPROT3;                         /* !< (@ 0x0000150C) Scratch Pad Memory Write Protect Register 3 */
  __IO uint32_t SPMWPROT4;                         /* !< (@ 0x00001510) Scratch Pad Memory Write Protect Register 4 */
  __IO uint32_t SPMWPROT5;                         /* !< (@ 0x00001514) Scratch Pad Memory Write Protect Register 5 */
  __IO uint32_t SPMWPROT6;                         /* !< (@ 0x00001518) Scratch Pad Memory Write Protect Register 6 */
  __IO uint32_t SPMWPROT7;                         /* !< (@ 0x0000151C) Scratch Pad Memory Write Protect Register 7 */
       uint32_t RESERVED1[8];
  __IO uint32_t SPMTERASE0;                        /* !< (@ 0x00001540) Scratch Pad Memory Tamper Erase Register 0 */
  __IO uint32_t SPMTERASE1;                        /* !< (@ 0x00001544) Scratch Pad Memory Tamper Erase Register 1 */
  __IO uint32_t SPMTERASE2;                        /* !< (@ 0x00001548) Scratch Pad Memory Tamper Erase Register 2 */
  __IO uint32_t SPMTERASE3;                        /* !< (@ 0x0000154C) Scratch Pad Memory Tamper Erase Register 3 */
  __IO uint32_t SPMTERASE4;                        /* !< (@ 0x00001550) Scratch Pad Memory Tamper Erase Register 4 */
  __IO uint32_t SPMTERASE5;                        /* !< (@ 0x00001554) Scratch Pad Memory Tamper Erase Register 5 */
  __IO uint32_t SPMTERASE6;                        /* !< (@ 0x00001558) Scratch Pad Memory Tamper Erase Register 6 */
  __IO uint32_t SPMTERASE7;                        /* !< (@ 0x0000155C) Scratch Pad Memory Tamper Erase Register 7 */
} LFSS_IPSPECIFIC_MEM_Regs;

/*@}*/ /* end of group LFSS_IPSPECIFIC_MEM */

/** @addtogroup LFSS_IPSPECIFIC_WDT
  @{
*/

typedef struct {
  __IO uint32_t WDTEN;                             /* !< (@ 0x00001300) Watchdog Timer Enable Register */
  __IO uint32_t WDTDBGCTL;                         /* !< (@ 0x00001304) Watchdog Timer Debug Control Register */
  __IO uint32_t WDTCTL;                            /* !< (@ 0x00001308) Watchdog Timer Control Register */
  __O  uint32_t WDTCNTRST;                         /* !< (@ 0x0000130C) Watchdog Timer Counter Reset Register */
  __I  uint32_t WDTSTAT;                           /* !< (@ 0x00001310) Watchdog Timer Status Register */
       uint32_t RESERVED0[58];
  __IO uint32_t WDTLOCK;                           /* !< (@ 0x000013FC) Watchdog timer lock register */
} LFSS_IPSPECIFIC_WDT_Regs;

/*@}*/ /* end of group LFSS_IPSPECIFIC_WDT */

/** @addtogroup LFSS_IPSPECIFIC_TIO
  @{
*/

typedef struct {
  __IO uint32_t TIOCTL[16];                        /* !< (@ 0x00001200) Tamper I/O Control Register */
       uint32_t RESERVED0[16];
  __IO uint32_t TOUT3_0;                           /* !< (@ 0x00001280) Tamper Output 3 to 0 */
  __IO uint32_t TOUT7_4;                           /* !< (@ 0x00001284) Tamper Output 7 to 4 */
  __IO uint32_t TOUT11_8;                          /* !< (@ 0x00001288) Tamper Output 11 to 8 */
  __IO uint32_t TOUT15_12;                         /* !< (@ 0x0000128C) Tamper Output 15 to 12 */
  __IO uint32_t TOE3_0;                            /* !< (@ 0x00001290) Tamper Output Enable 3 to 0 */
  __IO uint32_t TOE7_4;                            /* !< (@ 0x00001294) Tamper Output Enable 7 to 4 */
  __IO uint32_t TOE11_8;                           /* !< (@ 0x00001298) Tamper Output Enable 7 to 4 */
  __IO uint32_t TOE15_12;                          /* !< (@ 0x0000129C) Tamper Output Enable 7 to 4 */
  __I  uint32_t TIN3_0;                            /* !< (@ 0x000012A0) Tamper Input Register */
  __I  uint32_t TIN7_4;                            /* !< (@ 0x000012A4) Tamper Input Register */
  __I  uint32_t TIN11_8;                           /* !< (@ 0x000012A8) Tamper Input Register */
  __I  uint32_t TIN15_12;                          /* !< (@ 0x000012AC) Tamper Input Register */
       uint32_t RESERVED1[4];
  __IO uint32_t HEARTBEAT;                         /* !< (@ 0x000012C0) Heartbeat Register */
       uint32_t RESERVED2[14];
  __IO uint32_t TIOLOCK;                           /* !< (@ 0x000012FC) Tamper I/O lock register */
} LFSS_IPSPECIFIC_TIO_Regs;

/*@}*/ /* end of group LFSS_IPSPECIFIC_TIO */

/** @addtogroup LFSS_IPSPECIFIC_RTC
  @{
*/

typedef struct {
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
       uint32_t RESERVED0[31];
  __IO uint32_t LFSSRST;                           /* !< (@ 0x000011F0) Low frequency sub-system reset request */
       uint32_t RESERVED1[2];
  __IO uint32_t RTCLOCK;                           /* !< (@ 0x000011FC) Real time clock lock register */
} LFSS_IPSPECIFIC_RTC_Regs;

/*@}*/ /* end of group LFSS_IPSPECIFIC_RTC */

/** @addtogroup LFSS_GEN_EVENT
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
} LFSS_GEN_EVENT_Regs;

/*@}*/ /* end of group LFSS_GEN_EVENT */

/** @addtogroup LFSS_CPU_INT
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
} LFSS_CPU_INT_Regs;

/*@}*/ /* end of group LFSS_CPU_INT */

/** @addtogroup LFSS
  @{
*/

typedef struct {
       uint32_t RESERVED0[256];
  __IO uint32_t FSUB_0;                            /* !< (@ 0x00000400) Subsciber Port 0 */
       uint32_t RESERVED1[16];
  __IO uint32_t FPUB_0;                            /* !< (@ 0x00000444) Publisher Port 0 */
       uint32_t RESERVED2[751];
  __I  uint32_t CLKSEL;                            /* !< (@ 0x00001004) Clock Select for Ultra Low Power peripherals */
       uint32_t RESERVED3[6];
  LFSS_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED4;
  LFSS_GEN_EVENT_Regs  GEN_EVENT;                         /* !< (@ 0x00001050) */
       uint32_t RESERVED5[25];
  __I  uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED6[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) LFSS Descriptor Register */
  LFSS_IPSPECIFIC_RTC_Regs  IPSPECIFIC_RTC;                    /* !< (@ 0x00001100) */
  LFSS_IPSPECIFIC_TIO_Regs  IPSPECIFIC_TIO;                    /* !< (@ 0x00001200) */
  LFSS_IPSPECIFIC_WDT_Regs  IPSPECIFIC_WDT;                    /* !< (@ 0x00001300) */
  LFSS_IPSPECIFIC_MEM_Regs  IPSPECIFIC_MEM;                    /* !< (@ 0x00001400) */
} LFSS_Regs;

/*@}*/ /* end of group LFSS */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* LFSS Register Control Bits
******************************************************************************/

/* LFSS_SPMEM Bits */
/* LFSS_SPMEM[DATA3] Bits */
#define LFSS_SPMEM_DATA3_OFS                     (24)                            /* !< DATA3 Offset */
#define LFSS_SPMEM_DATA3_MASK                    ((uint32_t)0xFF000000U)         /* !< memory data byte 3 */
#define LFSS_SPMEM_DATA3_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_SPMEM_DATA3_MAXIMUM                 ((uint32_t)0xFF000000U)         /* !< Highest possible value */
/* LFSS_SPMEM[DATA2] Bits */
#define LFSS_SPMEM_DATA2_OFS                     (16)                            /* !< DATA2 Offset */
#define LFSS_SPMEM_DATA2_MASK                    ((uint32_t)0x00FF0000U)         /* !< memory data byte 2 */
#define LFSS_SPMEM_DATA2_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_SPMEM_DATA2_MAXIMUM                 ((uint32_t)0x00FF0000U)         /* !< Highest possible value */
/* LFSS_SPMEM[DATA1] Bits */
#define LFSS_SPMEM_DATA1_OFS                     (8)                             /* !< DATA1 Offset */
#define LFSS_SPMEM_DATA1_MASK                    ((uint32_t)0x0000FF00U)         /* !< memory data byte 1 */
#define LFSS_SPMEM_DATA1_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_SPMEM_DATA1_MAXIMUM                 ((uint32_t)0x0000FF00U)         /* !< Highest possible value */
/* LFSS_SPMEM[DATA0] Bits */
#define LFSS_SPMEM_DATA0_OFS                     (0)                             /* !< DATA0 Offset */
#define LFSS_SPMEM_DATA0_MASK                    ((uint32_t)0x000000FFU)         /* !< memory data byte 0 */
#define LFSS_SPMEM_DATA0_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_SPMEM_DATA0_MAXIMUM                 ((uint32_t)0x000000FFU)         /* !< Highest possible value */

/* LFSS_SPMWPROT0 Bits */
/* LFSS_SPMWPROT0[KEY] Bits */
#define LFSS_SPMWPROT0_KEY_OFS                   (24)                            /* !< KEY Offset */
#define LFSS_SPMWPROT0_KEY_MASK                  ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xE8) to update
                                                                                    this register */
#define LFSS_SPMWPROT0_KEY_UNLOCK_W              ((uint32_t)0xE8000000U)         /* !< This field must be written with
                                                                                    0xE8 to be update the write protect
                                                                                    bits. */
/* LFSS_SPMWPROT0[WP_3_3] Bits */
#define LFSS_SPMWPROT0_WP_3_3_OFS                (15)                            /* !< WP_3_3 Offset */
#define LFSS_SPMWPROT0_WP_3_3_MASK               ((uint32_t)0x00008000U)         /* !< write protect SPMEM3 - DATA3 */
#define LFSS_SPMWPROT0_WP_3_3_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_3_3_READONLY           ((uint32_t)0x00008000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_3_2] Bits */
#define LFSS_SPMWPROT0_WP_3_2_OFS                (14)                            /* !< WP_3_2 Offset */
#define LFSS_SPMWPROT0_WP_3_2_MASK               ((uint32_t)0x00004000U)         /* !< write protect SPMEM3 - DATA2 */
#define LFSS_SPMWPROT0_WP_3_2_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_3_2_READONLY           ((uint32_t)0x00004000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_3_1] Bits */
#define LFSS_SPMWPROT0_WP_3_1_OFS                (13)                            /* !< WP_3_1 Offset */
#define LFSS_SPMWPROT0_WP_3_1_MASK               ((uint32_t)0x00002000U)         /* !< write protect SPMEM3 - DATA1 */
#define LFSS_SPMWPROT0_WP_3_1_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_3_1_READONLY           ((uint32_t)0x00002000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_3_0] Bits */
#define LFSS_SPMWPROT0_WP_3_0_OFS                (12)                            /* !< WP_3_0 Offset */
#define LFSS_SPMWPROT0_WP_3_0_MASK               ((uint32_t)0x00001000U)         /* !< write protect SPMEM3 - DATA0 */
#define LFSS_SPMWPROT0_WP_3_0_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_3_0_READONLY           ((uint32_t)0x00001000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_2_3] Bits */
#define LFSS_SPMWPROT0_WP_2_3_OFS                (11)                            /* !< WP_2_3 Offset */
#define LFSS_SPMWPROT0_WP_2_3_MASK               ((uint32_t)0x00000800U)         /* !< write protect SPMEM2 - DATA3 */
#define LFSS_SPMWPROT0_WP_2_3_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_2_3_READONLY           ((uint32_t)0x00000800U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_2_2] Bits */
#define LFSS_SPMWPROT0_WP_2_2_OFS                (10)                            /* !< WP_2_2 Offset */
#define LFSS_SPMWPROT0_WP_2_2_MASK               ((uint32_t)0x00000400U)         /* !< write protect SPMEM2 - DATA2 */
#define LFSS_SPMWPROT0_WP_2_2_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_2_2_READONLY           ((uint32_t)0x00000400U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_2_1] Bits */
#define LFSS_SPMWPROT0_WP_2_1_OFS                (9)                             /* !< WP_2_1 Offset */
#define LFSS_SPMWPROT0_WP_2_1_MASK               ((uint32_t)0x00000200U)         /* !< write protect SPMEM2 - DATA1 */
#define LFSS_SPMWPROT0_WP_2_1_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_2_1_READONLY           ((uint32_t)0x00000200U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_2_0] Bits */
#define LFSS_SPMWPROT0_WP_2_0_OFS                (8)                             /* !< WP_2_0 Offset */
#define LFSS_SPMWPROT0_WP_2_0_MASK               ((uint32_t)0x00000100U)         /* !< write protect SPMEM2 - DATA0 */
#define LFSS_SPMWPROT0_WP_2_0_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_2_0_READONLY           ((uint32_t)0x00000100U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_1_3] Bits */
#define LFSS_SPMWPROT0_WP_1_3_OFS                (7)                             /* !< WP_1_3 Offset */
#define LFSS_SPMWPROT0_WP_1_3_MASK               ((uint32_t)0x00000080U)         /* !< write protect SPMEM1 - DATA3 */
#define LFSS_SPMWPROT0_WP_1_3_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_1_3_READONLY           ((uint32_t)0x00000080U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_1_2] Bits */
#define LFSS_SPMWPROT0_WP_1_2_OFS                (6)                             /* !< WP_1_2 Offset */
#define LFSS_SPMWPROT0_WP_1_2_MASK               ((uint32_t)0x00000040U)         /* !< write protect SPMEM1 - DATA2 */
#define LFSS_SPMWPROT0_WP_1_2_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_1_2_READONLY           ((uint32_t)0x00000040U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_1_1] Bits */
#define LFSS_SPMWPROT0_WP_1_1_OFS                (5)                             /* !< WP_1_1 Offset */
#define LFSS_SPMWPROT0_WP_1_1_MASK               ((uint32_t)0x00000020U)         /* !< write protect SPMEM1 - DATA1 */
#define LFSS_SPMWPROT0_WP_1_1_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_1_1_READONLY           ((uint32_t)0x00000020U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_1_0] Bits */
#define LFSS_SPMWPROT0_WP_1_0_OFS                (4)                             /* !< WP_1_0 Offset */
#define LFSS_SPMWPROT0_WP_1_0_MASK               ((uint32_t)0x00000010U)         /* !< write protect SPMEM1 - DATA0 */
#define LFSS_SPMWPROT0_WP_1_0_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_1_0_READONLY           ((uint32_t)0x00000010U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_0_3] Bits */
#define LFSS_SPMWPROT0_WP_0_3_OFS                (3)                             /* !< WP_0_3 Offset */
#define LFSS_SPMWPROT0_WP_0_3_MASK               ((uint32_t)0x00000008U)         /* !< write protect SPMEM0 - DATA3 */
#define LFSS_SPMWPROT0_WP_0_3_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_0_3_READONLY           ((uint32_t)0x00000008U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_0_2] Bits */
#define LFSS_SPMWPROT0_WP_0_2_OFS                (2)                             /* !< WP_0_2 Offset */
#define LFSS_SPMWPROT0_WP_0_2_MASK               ((uint32_t)0x00000004U)         /* !< write protect SPMEM0 - DATA2 */
#define LFSS_SPMWPROT0_WP_0_2_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_0_2_READONLY           ((uint32_t)0x00000004U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_0_1] Bits */
#define LFSS_SPMWPROT0_WP_0_1_OFS                (1)                             /* !< WP_0_1 Offset */
#define LFSS_SPMWPROT0_WP_0_1_MASK               ((uint32_t)0x00000002U)         /* !< write protect SPMEM0 - DATA1 */
#define LFSS_SPMWPROT0_WP_0_1_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_0_1_READONLY           ((uint32_t)0x00000002U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT0[WP_0_0] Bits */
#define LFSS_SPMWPROT0_WP_0_0_OFS                (0)                             /* !< WP_0_0 Offset */
#define LFSS_SPMWPROT0_WP_0_0_MASK               ((uint32_t)0x00000001U)         /* !< write protect SPMEM0 - DATA0 */
#define LFSS_SPMWPROT0_WP_0_0_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT0_WP_0_0_READONLY           ((uint32_t)0x00000001U)         /* !< SPMEM is read only access */

/* LFSS_SPMWPROT1 Bits */
/* LFSS_SPMWPROT1[KEY] Bits */
#define LFSS_SPMWPROT1_KEY_OFS                   (24)                            /* !< KEY Offset */
#define LFSS_SPMWPROT1_KEY_MASK                  ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xE8) to update
                                                                                    this register */
#define LFSS_SPMWPROT1_KEY_UNLOCK_W              ((uint32_t)0xE8000000U)         /* !< This field must be written with
                                                                                    0xE8 to be update the write protect
                                                                                    bits. */
/* LFSS_SPMWPROT1[WP_7_3] Bits */
#define LFSS_SPMWPROT1_WP_7_3_OFS                (15)                            /* !< WP_7_3 Offset */
#define LFSS_SPMWPROT1_WP_7_3_MASK               ((uint32_t)0x00008000U)         /* !< write protect SPMEM7 - DATA3 */
#define LFSS_SPMWPROT1_WP_7_3_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_7_3_READONLY           ((uint32_t)0x00008000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_7_2] Bits */
#define LFSS_SPMWPROT1_WP_7_2_OFS                (14)                            /* !< WP_7_2 Offset */
#define LFSS_SPMWPROT1_WP_7_2_MASK               ((uint32_t)0x00004000U)         /* !< write protect SPMEM7 - DATA2 */
#define LFSS_SPMWPROT1_WP_7_2_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_7_2_READONLY           ((uint32_t)0x00004000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_7_1] Bits */
#define LFSS_SPMWPROT1_WP_7_1_OFS                (13)                            /* !< WP_7_1 Offset */
#define LFSS_SPMWPROT1_WP_7_1_MASK               ((uint32_t)0x00002000U)         /* !< write protect SPMEM7 - DATA1 */
#define LFSS_SPMWPROT1_WP_7_1_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_7_1_READONLY           ((uint32_t)0x00002000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_7_0] Bits */
#define LFSS_SPMWPROT1_WP_7_0_OFS                (12)                            /* !< WP_7_0 Offset */
#define LFSS_SPMWPROT1_WP_7_0_MASK               ((uint32_t)0x00001000U)         /* !< write protect SPMEM7 - DATA0 */
#define LFSS_SPMWPROT1_WP_7_0_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_7_0_READONLY           ((uint32_t)0x00001000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_6_3] Bits */
#define LFSS_SPMWPROT1_WP_6_3_OFS                (11)                            /* !< WP_6_3 Offset */
#define LFSS_SPMWPROT1_WP_6_3_MASK               ((uint32_t)0x00000800U)         /* !< write protect SPMEM6 - DATA3 */
#define LFSS_SPMWPROT1_WP_6_3_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_6_3_READONLY           ((uint32_t)0x00000800U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_6_2] Bits */
#define LFSS_SPMWPROT1_WP_6_2_OFS                (10)                            /* !< WP_6_2 Offset */
#define LFSS_SPMWPROT1_WP_6_2_MASK               ((uint32_t)0x00000400U)         /* !< write protect SPMEM6 - DATA2 */
#define LFSS_SPMWPROT1_WP_6_2_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_6_2_READONLY           ((uint32_t)0x00000400U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_6_1] Bits */
#define LFSS_SPMWPROT1_WP_6_1_OFS                (9)                             /* !< WP_6_1 Offset */
#define LFSS_SPMWPROT1_WP_6_1_MASK               ((uint32_t)0x00000200U)         /* !< write protect SPMEM6 - DATA1 */
#define LFSS_SPMWPROT1_WP_6_1_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_6_1_READONLY           ((uint32_t)0x00000200U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_6_0] Bits */
#define LFSS_SPMWPROT1_WP_6_0_OFS                (8)                             /* !< WP_6_0 Offset */
#define LFSS_SPMWPROT1_WP_6_0_MASK               ((uint32_t)0x00000100U)         /* !< write protect SPMEM6 - DATA0 */
#define LFSS_SPMWPROT1_WP_6_0_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_6_0_READONLY           ((uint32_t)0x00000100U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_5_3] Bits */
#define LFSS_SPMWPROT1_WP_5_3_OFS                (7)                             /* !< WP_5_3 Offset */
#define LFSS_SPMWPROT1_WP_5_3_MASK               ((uint32_t)0x00000080U)         /* !< write protect SPMEM5 - DATA3 */
#define LFSS_SPMWPROT1_WP_5_3_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_5_3_READONLY           ((uint32_t)0x00000080U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_5_2] Bits */
#define LFSS_SPMWPROT1_WP_5_2_OFS                (6)                             /* !< WP_5_2 Offset */
#define LFSS_SPMWPROT1_WP_5_2_MASK               ((uint32_t)0x00000040U)         /* !< write protect SPMEM5 - DATA2 */
#define LFSS_SPMWPROT1_WP_5_2_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_5_2_READONLY           ((uint32_t)0x00000040U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_5_1] Bits */
#define LFSS_SPMWPROT1_WP_5_1_OFS                (5)                             /* !< WP_5_1 Offset */
#define LFSS_SPMWPROT1_WP_5_1_MASK               ((uint32_t)0x00000020U)         /* !< write protect SPMEM5 - DATA1 */
#define LFSS_SPMWPROT1_WP_5_1_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_5_1_READONLY           ((uint32_t)0x00000020U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_5_0] Bits */
#define LFSS_SPMWPROT1_WP_5_0_OFS                (4)                             /* !< WP_5_0 Offset */
#define LFSS_SPMWPROT1_WP_5_0_MASK               ((uint32_t)0x00000010U)         /* !< write protect SPMEM5 - DATA0 */
#define LFSS_SPMWPROT1_WP_5_0_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_5_0_READONLY           ((uint32_t)0x00000010U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_4_3] Bits */
#define LFSS_SPMWPROT1_WP_4_3_OFS                (3)                             /* !< WP_4_3 Offset */
#define LFSS_SPMWPROT1_WP_4_3_MASK               ((uint32_t)0x00000008U)         /* !< write protect SPMEM4 - DATA3 */
#define LFSS_SPMWPROT1_WP_4_3_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_4_3_READONLY           ((uint32_t)0x00000008U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_4_2] Bits */
#define LFSS_SPMWPROT1_WP_4_2_OFS                (2)                             /* !< WP_4_2 Offset */
#define LFSS_SPMWPROT1_WP_4_2_MASK               ((uint32_t)0x00000004U)         /* !< write protect SPMEM4 - DATA2 */
#define LFSS_SPMWPROT1_WP_4_2_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_4_2_READONLY           ((uint32_t)0x00000004U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_4_1] Bits */
#define LFSS_SPMWPROT1_WP_4_1_OFS                (1)                             /* !< WP_4_1 Offset */
#define LFSS_SPMWPROT1_WP_4_1_MASK               ((uint32_t)0x00000002U)         /* !< write protect SPMEM4 - DATA1 */
#define LFSS_SPMWPROT1_WP_4_1_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_4_1_READONLY           ((uint32_t)0x00000002U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT1[WP_4_0] Bits */
#define LFSS_SPMWPROT1_WP_4_0_OFS                (0)                             /* !< WP_4_0 Offset */
#define LFSS_SPMWPROT1_WP_4_0_MASK               ((uint32_t)0x00000001U)         /* !< write protect SPMEM4 - DATA0 */
#define LFSS_SPMWPROT1_WP_4_0_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT1_WP_4_0_READONLY           ((uint32_t)0x00000001U)         /* !< SPMEM is read only access */

/* LFSS_SPMWPROT2 Bits */
/* LFSS_SPMWPROT2[KEY] Bits */
#define LFSS_SPMWPROT2_KEY_OFS                   (24)                            /* !< KEY Offset */
#define LFSS_SPMWPROT2_KEY_MASK                  ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xE8) to update
                                                                                    this register */
#define LFSS_SPMWPROT2_KEY_UNLOCK_W              ((uint32_t)0xE8000000U)         /* !< This field must be written with
                                                                                    0xE8 to be update the write protect
                                                                                    bits. */
/* LFSS_SPMWPROT2[WP_11_3] Bits */
#define LFSS_SPMWPROT2_WP_11_3_OFS               (15)                            /* !< WP_11_3 Offset */
#define LFSS_SPMWPROT2_WP_11_3_MASK              ((uint32_t)0x00008000U)         /* !< write protect SPMEM11 - DATA3 */
#define LFSS_SPMWPROT2_WP_11_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_11_3_READONLY          ((uint32_t)0x00008000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_11_2] Bits */
#define LFSS_SPMWPROT2_WP_11_2_OFS               (14)                            /* !< WP_11_2 Offset */
#define LFSS_SPMWPROT2_WP_11_2_MASK              ((uint32_t)0x00004000U)         /* !< write protect SPMEM11 - DATA2 */
#define LFSS_SPMWPROT2_WP_11_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_11_2_READONLY          ((uint32_t)0x00004000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_11_1] Bits */
#define LFSS_SPMWPROT2_WP_11_1_OFS               (13)                            /* !< WP_11_1 Offset */
#define LFSS_SPMWPROT2_WP_11_1_MASK              ((uint32_t)0x00002000U)         /* !< write protect SPMEM11 - DATA1 */
#define LFSS_SPMWPROT2_WP_11_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_11_1_READONLY          ((uint32_t)0x00002000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_11_0] Bits */
#define LFSS_SPMWPROT2_WP_11_0_OFS               (12)                            /* !< WP_11_0 Offset */
#define LFSS_SPMWPROT2_WP_11_0_MASK              ((uint32_t)0x00001000U)         /* !< write protect SPMEM11 - DATA0 */
#define LFSS_SPMWPROT2_WP_11_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_11_0_READONLY          ((uint32_t)0x00001000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_10_3] Bits */
#define LFSS_SPMWPROT2_WP_10_3_OFS               (11)                            /* !< WP_10_3 Offset */
#define LFSS_SPMWPROT2_WP_10_3_MASK              ((uint32_t)0x00000800U)         /* !< write protect SPMEM10 - DATA3 */
#define LFSS_SPMWPROT2_WP_10_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_10_3_READONLY          ((uint32_t)0x00000800U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_10_2] Bits */
#define LFSS_SPMWPROT2_WP_10_2_OFS               (10)                            /* !< WP_10_2 Offset */
#define LFSS_SPMWPROT2_WP_10_2_MASK              ((uint32_t)0x00000400U)         /* !< write protect SPMEM610- DATA2 */
#define LFSS_SPMWPROT2_WP_10_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_10_2_READONLY          ((uint32_t)0x00000400U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_10_1] Bits */
#define LFSS_SPMWPROT2_WP_10_1_OFS               (9)                             /* !< WP_10_1 Offset */
#define LFSS_SPMWPROT2_WP_10_1_MASK              ((uint32_t)0x00000200U)         /* !< write protect SPMEM10 - DATA1 */
#define LFSS_SPMWPROT2_WP_10_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_10_1_READONLY          ((uint32_t)0x00000200U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_10_0] Bits */
#define LFSS_SPMWPROT2_WP_10_0_OFS               (8)                             /* !< WP_10_0 Offset */
#define LFSS_SPMWPROT2_WP_10_0_MASK              ((uint32_t)0x00000100U)         /* !< write protect SPMEM10 - DATA0 */
#define LFSS_SPMWPROT2_WP_10_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_10_0_READONLY          ((uint32_t)0x00000100U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_9_3] Bits */
#define LFSS_SPMWPROT2_WP_9_3_OFS                (7)                             /* !< WP_9_3 Offset */
#define LFSS_SPMWPROT2_WP_9_3_MASK               ((uint32_t)0x00000080U)         /* !< write protect SPMEM9 - DATA3 */
#define LFSS_SPMWPROT2_WP_9_3_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_9_3_READONLY           ((uint32_t)0x00000080U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_9_2] Bits */
#define LFSS_SPMWPROT2_WP_9_2_OFS                (6)                             /* !< WP_9_2 Offset */
#define LFSS_SPMWPROT2_WP_9_2_MASK               ((uint32_t)0x00000040U)         /* !< write protect SPMEM9 - DATA2 */
#define LFSS_SPMWPROT2_WP_9_2_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_9_2_READONLY           ((uint32_t)0x00000040U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_9_1] Bits */
#define LFSS_SPMWPROT2_WP_9_1_OFS                (5)                             /* !< WP_9_1 Offset */
#define LFSS_SPMWPROT2_WP_9_1_MASK               ((uint32_t)0x00000020U)         /* !< write protect SPMEM9 - DATA1 */
#define LFSS_SPMWPROT2_WP_9_1_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_9_1_READONLY           ((uint32_t)0x00000020U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_9_0] Bits */
#define LFSS_SPMWPROT2_WP_9_0_OFS                (4)                             /* !< WP_9_0 Offset */
#define LFSS_SPMWPROT2_WP_9_0_MASK               ((uint32_t)0x00000010U)         /* !< write protect SPMEM9 - DATA0 */
#define LFSS_SPMWPROT2_WP_9_0_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_9_0_READONLY           ((uint32_t)0x00000010U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_8_3] Bits */
#define LFSS_SPMWPROT2_WP_8_3_OFS                (3)                             /* !< WP_8_3 Offset */
#define LFSS_SPMWPROT2_WP_8_3_MASK               ((uint32_t)0x00000008U)         /* !< write protect SPMEM8 - DATA3 */
#define LFSS_SPMWPROT2_WP_8_3_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_8_3_READONLY           ((uint32_t)0x00000008U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_8_2] Bits */
#define LFSS_SPMWPROT2_WP_8_2_OFS                (2)                             /* !< WP_8_2 Offset */
#define LFSS_SPMWPROT2_WP_8_2_MASK               ((uint32_t)0x00000004U)         /* !< write protect SPMEM8 - DATA2 */
#define LFSS_SPMWPROT2_WP_8_2_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_8_2_READONLY           ((uint32_t)0x00000004U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_8_1] Bits */
#define LFSS_SPMWPROT2_WP_8_1_OFS                (1)                             /* !< WP_8_1 Offset */
#define LFSS_SPMWPROT2_WP_8_1_MASK               ((uint32_t)0x00000002U)         /* !< write protect SPMEM8 - DATA1 */
#define LFSS_SPMWPROT2_WP_8_1_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_8_1_READONLY           ((uint32_t)0x00000002U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT2[WP_8_0] Bits */
#define LFSS_SPMWPROT2_WP_8_0_OFS                (0)                             /* !< WP_8_0 Offset */
#define LFSS_SPMWPROT2_WP_8_0_MASK               ((uint32_t)0x00000001U)         /* !< write protect SPMEM8 - DATA0 */
#define LFSS_SPMWPROT2_WP_8_0_READWRITE          ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT2_WP_8_0_READONLY           ((uint32_t)0x00000001U)         /* !< SPMEM is read only access */

/* LFSS_SPMWPROT3 Bits */
/* LFSS_SPMWPROT3[KEY] Bits */
#define LFSS_SPMWPROT3_KEY_OFS                   (24)                            /* !< KEY Offset */
#define LFSS_SPMWPROT3_KEY_MASK                  ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xE8) to update
                                                                                    this register */
#define LFSS_SPMWPROT3_KEY_UNLOCK_W              ((uint32_t)0xE8000000U)         /* !< This field must be written with
                                                                                    0xE8 to be update the write protect
                                                                                    bits. */
/* LFSS_SPMWPROT3[WP_15_3] Bits */
#define LFSS_SPMWPROT3_WP_15_3_OFS               (15)                            /* !< WP_15_3 Offset */
#define LFSS_SPMWPROT3_WP_15_3_MASK              ((uint32_t)0x00008000U)         /* !< write protect SPMEM15 - DATA3 */
#define LFSS_SPMWPROT3_WP_15_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_15_3_READONLY          ((uint32_t)0x00008000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_15_2] Bits */
#define LFSS_SPMWPROT3_WP_15_2_OFS               (14)                            /* !< WP_15_2 Offset */
#define LFSS_SPMWPROT3_WP_15_2_MASK              ((uint32_t)0x00004000U)         /* !< write protect SPMEM15 - DATA2 */
#define LFSS_SPMWPROT3_WP_15_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_15_2_READONLY          ((uint32_t)0x00004000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_15_1] Bits */
#define LFSS_SPMWPROT3_WP_15_1_OFS               (13)                            /* !< WP_15_1 Offset */
#define LFSS_SPMWPROT3_WP_15_1_MASK              ((uint32_t)0x00002000U)         /* !< write protect SPMEM15 - DATA1 */
#define LFSS_SPMWPROT3_WP_15_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_15_1_READONLY          ((uint32_t)0x00002000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_15_0] Bits */
#define LFSS_SPMWPROT3_WP_15_0_OFS               (12)                            /* !< WP_15_0 Offset */
#define LFSS_SPMWPROT3_WP_15_0_MASK              ((uint32_t)0x00001000U)         /* !< write protect SPMEM15 - DATA0 */
#define LFSS_SPMWPROT3_WP_15_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_15_0_READONLY          ((uint32_t)0x00001000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_14_3] Bits */
#define LFSS_SPMWPROT3_WP_14_3_OFS               (11)                            /* !< WP_14_3 Offset */
#define LFSS_SPMWPROT3_WP_14_3_MASK              ((uint32_t)0x00000800U)         /* !< write protect SPMEM14 - DATA3 */
#define LFSS_SPMWPROT3_WP_14_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_14_3_READONLY          ((uint32_t)0x00000800U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_14_2] Bits */
#define LFSS_SPMWPROT3_WP_14_2_OFS               (10)                            /* !< WP_14_2 Offset */
#define LFSS_SPMWPROT3_WP_14_2_MASK              ((uint32_t)0x00000400U)         /* !< write protect SPMEM14- DATA2 */
#define LFSS_SPMWPROT3_WP_14_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_14_2_READONLY          ((uint32_t)0x00000400U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_14_1] Bits */
#define LFSS_SPMWPROT3_WP_14_1_OFS               (9)                             /* !< WP_14_1 Offset */
#define LFSS_SPMWPROT3_WP_14_1_MASK              ((uint32_t)0x00000200U)         /* !< write protect SPMEM14 - DATA1 */
#define LFSS_SPMWPROT3_WP_14_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_14_1_READONLY          ((uint32_t)0x00000200U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_14_0] Bits */
#define LFSS_SPMWPROT3_WP_14_0_OFS               (8)                             /* !< WP_14_0 Offset */
#define LFSS_SPMWPROT3_WP_14_0_MASK              ((uint32_t)0x00000100U)         /* !< write protect SPMEM14 - DATA0 */
#define LFSS_SPMWPROT3_WP_14_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_14_0_READONLY          ((uint32_t)0x00000100U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_13_3] Bits */
#define LFSS_SPMWPROT3_WP_13_3_OFS               (7)                             /* !< WP_13_3 Offset */
#define LFSS_SPMWPROT3_WP_13_3_MASK              ((uint32_t)0x00000080U)         /* !< write protect SPMEM13 - DATA3 */
#define LFSS_SPMWPROT3_WP_13_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_13_3_READONLY          ((uint32_t)0x00000080U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_13_2] Bits */
#define LFSS_SPMWPROT3_WP_13_2_OFS               (6)                             /* !< WP_13_2 Offset */
#define LFSS_SPMWPROT3_WP_13_2_MASK              ((uint32_t)0x00000040U)         /* !< write protect SPMEM13 - DATA2 */
#define LFSS_SPMWPROT3_WP_13_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_13_2_READONLY          ((uint32_t)0x00000040U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_13_1] Bits */
#define LFSS_SPMWPROT3_WP_13_1_OFS               (5)                             /* !< WP_13_1 Offset */
#define LFSS_SPMWPROT3_WP_13_1_MASK              ((uint32_t)0x00000020U)         /* !< write protect SPMEM13 - DATA1 */
#define LFSS_SPMWPROT3_WP_13_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_13_1_READONLY          ((uint32_t)0x00000020U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_13_0] Bits */
#define LFSS_SPMWPROT3_WP_13_0_OFS               (4)                             /* !< WP_13_0 Offset */
#define LFSS_SPMWPROT3_WP_13_0_MASK              ((uint32_t)0x00000010U)         /* !< write protect SPMEM13 - DATA0 */
#define LFSS_SPMWPROT3_WP_13_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_13_0_READONLY          ((uint32_t)0x00000010U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_12_3] Bits */
#define LFSS_SPMWPROT3_WP_12_3_OFS               (3)                             /* !< WP_12_3 Offset */
#define LFSS_SPMWPROT3_WP_12_3_MASK              ((uint32_t)0x00000008U)         /* !< write protect SPMEM12 - DATA3 */
#define LFSS_SPMWPROT3_WP_12_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_12_3_READONLY          ((uint32_t)0x00000008U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_12_2] Bits */
#define LFSS_SPMWPROT3_WP_12_2_OFS               (2)                             /* !< WP_12_2 Offset */
#define LFSS_SPMWPROT3_WP_12_2_MASK              ((uint32_t)0x00000004U)         /* !< write protect SPMEM12 - DATA2 */
#define LFSS_SPMWPROT3_WP_12_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_12_2_READONLY          ((uint32_t)0x00000004U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_12_1] Bits */
#define LFSS_SPMWPROT3_WP_12_1_OFS               (1)                             /* !< WP_12_1 Offset */
#define LFSS_SPMWPROT3_WP_12_1_MASK              ((uint32_t)0x00000002U)         /* !< write protect SPMEM12 - DATA1 */
#define LFSS_SPMWPROT3_WP_12_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_12_1_READONLY          ((uint32_t)0x00000002U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT3[WP_12_0] Bits */
#define LFSS_SPMWPROT3_WP_12_0_OFS               (0)                             /* !< WP_12_0 Offset */
#define LFSS_SPMWPROT3_WP_12_0_MASK              ((uint32_t)0x00000001U)         /* !< write protect SPMEM12 - DATA0 */
#define LFSS_SPMWPROT3_WP_12_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT3_WP_12_0_READONLY          ((uint32_t)0x00000001U)         /* !< SPMEM is read only access */

/* LFSS_SPMWPROT4 Bits */
/* LFSS_SPMWPROT4[KEY] Bits */
#define LFSS_SPMWPROT4_KEY_OFS                   (24)                            /* !< KEY Offset */
#define LFSS_SPMWPROT4_KEY_MASK                  ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xE8) to update
                                                                                    this register */
#define LFSS_SPMWPROT4_KEY_UNLOCK_W              ((uint32_t)0xE8000000U)         /* !< This field must be written with
                                                                                    0xE8 to be update the write protect
                                                                                    bits. */
/* LFSS_SPMWPROT4[WP_19_3] Bits */
#define LFSS_SPMWPROT4_WP_19_3_OFS               (15)                            /* !< WP_19_3 Offset */
#define LFSS_SPMWPROT4_WP_19_3_MASK              ((uint32_t)0x00008000U)         /* !< write protect SPMEM19 - DATA3 */
#define LFSS_SPMWPROT4_WP_19_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_19_3_READONLY          ((uint32_t)0x00008000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_19_2] Bits */
#define LFSS_SPMWPROT4_WP_19_2_OFS               (14)                            /* !< WP_19_2 Offset */
#define LFSS_SPMWPROT4_WP_19_2_MASK              ((uint32_t)0x00004000U)         /* !< write protect SPMEM19 - DATA2 */
#define LFSS_SPMWPROT4_WP_19_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_19_2_READONLY          ((uint32_t)0x00004000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_19_1] Bits */
#define LFSS_SPMWPROT4_WP_19_1_OFS               (13)                            /* !< WP_19_1 Offset */
#define LFSS_SPMWPROT4_WP_19_1_MASK              ((uint32_t)0x00002000U)         /* !< write protect SPMEM19 - DATA1 */
#define LFSS_SPMWPROT4_WP_19_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_19_1_READONLY          ((uint32_t)0x00002000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_19_0] Bits */
#define LFSS_SPMWPROT4_WP_19_0_OFS               (12)                            /* !< WP_19_0 Offset */
#define LFSS_SPMWPROT4_WP_19_0_MASK              ((uint32_t)0x00001000U)         /* !< write protect SPMEM19 - DATA0 */
#define LFSS_SPMWPROT4_WP_19_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_19_0_READONLY          ((uint32_t)0x00001000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_18_3] Bits */
#define LFSS_SPMWPROT4_WP_18_3_OFS               (11)                            /* !< WP_18_3 Offset */
#define LFSS_SPMWPROT4_WP_18_3_MASK              ((uint32_t)0x00000800U)         /* !< write protect SPMEM18 - DATA3 */
#define LFSS_SPMWPROT4_WP_18_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_18_3_READONLY          ((uint32_t)0x00000800U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_18_2] Bits */
#define LFSS_SPMWPROT4_WP_18_2_OFS               (10)                            /* !< WP_18_2 Offset */
#define LFSS_SPMWPROT4_WP_18_2_MASK              ((uint32_t)0x00000400U)         /* !< write protect SPMEM18- DATA2 */
#define LFSS_SPMWPROT4_WP_18_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_18_2_READONLY          ((uint32_t)0x00000400U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_18_1] Bits */
#define LFSS_SPMWPROT4_WP_18_1_OFS               (9)                             /* !< WP_18_1 Offset */
#define LFSS_SPMWPROT4_WP_18_1_MASK              ((uint32_t)0x00000200U)         /* !< write protect SPMEM18 - DATA1 */
#define LFSS_SPMWPROT4_WP_18_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_18_1_READONLY          ((uint32_t)0x00000200U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_18_0] Bits */
#define LFSS_SPMWPROT4_WP_18_0_OFS               (8)                             /* !< WP_18_0 Offset */
#define LFSS_SPMWPROT4_WP_18_0_MASK              ((uint32_t)0x00000100U)         /* !< write protect SPMEM18 - DATA0 */
#define LFSS_SPMWPROT4_WP_18_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_18_0_READONLY          ((uint32_t)0x00000100U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_17_3] Bits */
#define LFSS_SPMWPROT4_WP_17_3_OFS               (7)                             /* !< WP_17_3 Offset */
#define LFSS_SPMWPROT4_WP_17_3_MASK              ((uint32_t)0x00000080U)         /* !< write protect SPMEM17 - DATA3 */
#define LFSS_SPMWPROT4_WP_17_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_17_3_READONLY          ((uint32_t)0x00000080U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_17_2] Bits */
#define LFSS_SPMWPROT4_WP_17_2_OFS               (6)                             /* !< WP_17_2 Offset */
#define LFSS_SPMWPROT4_WP_17_2_MASK              ((uint32_t)0x00000040U)         /* !< write protect SPMEM17 - DATA2 */
#define LFSS_SPMWPROT4_WP_17_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_17_2_READONLY          ((uint32_t)0x00000040U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_17_1] Bits */
#define LFSS_SPMWPROT4_WP_17_1_OFS               (5)                             /* !< WP_17_1 Offset */
#define LFSS_SPMWPROT4_WP_17_1_MASK              ((uint32_t)0x00000020U)         /* !< write protect SPMEM17 - DATA1 */
#define LFSS_SPMWPROT4_WP_17_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_17_1_READONLY          ((uint32_t)0x00000020U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_17_0] Bits */
#define LFSS_SPMWPROT4_WP_17_0_OFS               (4)                             /* !< WP_17_0 Offset */
#define LFSS_SPMWPROT4_WP_17_0_MASK              ((uint32_t)0x00000010U)         /* !< write protect SPMEM17 - DATA0 */
#define LFSS_SPMWPROT4_WP_17_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_17_0_READONLY          ((uint32_t)0x00000010U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_16_3] Bits */
#define LFSS_SPMWPROT4_WP_16_3_OFS               (3)                             /* !< WP_16_3 Offset */
#define LFSS_SPMWPROT4_WP_16_3_MASK              ((uint32_t)0x00000008U)         /* !< write protect SPMEM16 - DATA3 */
#define LFSS_SPMWPROT4_WP_16_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_16_3_READONLY          ((uint32_t)0x00000008U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_16_2] Bits */
#define LFSS_SPMWPROT4_WP_16_2_OFS               (2)                             /* !< WP_16_2 Offset */
#define LFSS_SPMWPROT4_WP_16_2_MASK              ((uint32_t)0x00000004U)         /* !< write protect SPMEM16 - DATA2 */
#define LFSS_SPMWPROT4_WP_16_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_16_2_READONLY          ((uint32_t)0x00000004U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_16_1] Bits */
#define LFSS_SPMWPROT4_WP_16_1_OFS               (1)                             /* !< WP_16_1 Offset */
#define LFSS_SPMWPROT4_WP_16_1_MASK              ((uint32_t)0x00000002U)         /* !< write protect SPMEM16 - DATA1 */
#define LFSS_SPMWPROT4_WP_16_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_16_1_READONLY          ((uint32_t)0x00000002U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT4[WP_16_0] Bits */
#define LFSS_SPMWPROT4_WP_16_0_OFS               (0)                             /* !< WP_16_0 Offset */
#define LFSS_SPMWPROT4_WP_16_0_MASK              ((uint32_t)0x00000001U)         /* !< write protect SPMEM16 - DATA0 */
#define LFSS_SPMWPROT4_WP_16_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT4_WP_16_0_READONLY          ((uint32_t)0x00000001U)         /* !< SPMEM is read only access */

/* LFSS_SPMWPROT5 Bits */
/* LFSS_SPMWPROT5[KEY] Bits */
#define LFSS_SPMWPROT5_KEY_OFS                   (24)                            /* !< KEY Offset */
#define LFSS_SPMWPROT5_KEY_MASK                  ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xE8) to update
                                                                                    this register */
#define LFSS_SPMWPROT5_KEY_UNLOCK_W              ((uint32_t)0xE8000000U)         /* !< This field must be written with
                                                                                    0xE8 to be update the write protect
                                                                                    bits. */
/* LFSS_SPMWPROT5[WP_23_3] Bits */
#define LFSS_SPMWPROT5_WP_23_3_OFS               (15)                            /* !< WP_23_3 Offset */
#define LFSS_SPMWPROT5_WP_23_3_MASK              ((uint32_t)0x00008000U)         /* !< write protect SPMEM23 - DATA3 */
#define LFSS_SPMWPROT5_WP_23_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_23_3_READONLY          ((uint32_t)0x00008000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_23_2] Bits */
#define LFSS_SPMWPROT5_WP_23_2_OFS               (14)                            /* !< WP_23_2 Offset */
#define LFSS_SPMWPROT5_WP_23_2_MASK              ((uint32_t)0x00004000U)         /* !< write protect SPMEM23 - DATA2 */
#define LFSS_SPMWPROT5_WP_23_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_23_2_READONLY          ((uint32_t)0x00004000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_23_1] Bits */
#define LFSS_SPMWPROT5_WP_23_1_OFS               (13)                            /* !< WP_23_1 Offset */
#define LFSS_SPMWPROT5_WP_23_1_MASK              ((uint32_t)0x00002000U)         /* !< write protect SPMEM23 - DATA1 */
#define LFSS_SPMWPROT5_WP_23_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_23_1_READONLY          ((uint32_t)0x00002000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_23_0] Bits */
#define LFSS_SPMWPROT5_WP_23_0_OFS               (12)                            /* !< WP_23_0 Offset */
#define LFSS_SPMWPROT5_WP_23_0_MASK              ((uint32_t)0x00001000U)         /* !< write protect SPMEM23 - DATA0 */
#define LFSS_SPMWPROT5_WP_23_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_23_0_READONLY          ((uint32_t)0x00001000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_22_3] Bits */
#define LFSS_SPMWPROT5_WP_22_3_OFS               (11)                            /* !< WP_22_3 Offset */
#define LFSS_SPMWPROT5_WP_22_3_MASK              ((uint32_t)0x00000800U)         /* !< write protect SPMEM22 - DATA3 */
#define LFSS_SPMWPROT5_WP_22_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_22_3_READONLY          ((uint32_t)0x00000800U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_22_2] Bits */
#define LFSS_SPMWPROT5_WP_22_2_OFS               (10)                            /* !< WP_22_2 Offset */
#define LFSS_SPMWPROT5_WP_22_2_MASK              ((uint32_t)0x00000400U)         /* !< write protect SPMEM22- DATA2 */
#define LFSS_SPMWPROT5_WP_22_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_22_2_READONLY          ((uint32_t)0x00000400U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_22_1] Bits */
#define LFSS_SPMWPROT5_WP_22_1_OFS               (9)                             /* !< WP_22_1 Offset */
#define LFSS_SPMWPROT5_WP_22_1_MASK              ((uint32_t)0x00000200U)         /* !< write protect SPMEM22 - DATA1 */
#define LFSS_SPMWPROT5_WP_22_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_22_1_READONLY          ((uint32_t)0x00000200U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_22_0] Bits */
#define LFSS_SPMWPROT5_WP_22_0_OFS               (8)                             /* !< WP_22_0 Offset */
#define LFSS_SPMWPROT5_WP_22_0_MASK              ((uint32_t)0x00000100U)         /* !< write protect SPMEM22 - DATA0 */
#define LFSS_SPMWPROT5_WP_22_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_22_0_READONLY          ((uint32_t)0x00000100U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_21_3] Bits */
#define LFSS_SPMWPROT5_WP_21_3_OFS               (7)                             /* !< WP_21_3 Offset */
#define LFSS_SPMWPROT5_WP_21_3_MASK              ((uint32_t)0x00000080U)         /* !< write protect SPMEM21 - DATA3 */
#define LFSS_SPMWPROT5_WP_21_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_21_3_READONLY          ((uint32_t)0x00000080U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_21_2] Bits */
#define LFSS_SPMWPROT5_WP_21_2_OFS               (6)                             /* !< WP_21_2 Offset */
#define LFSS_SPMWPROT5_WP_21_2_MASK              ((uint32_t)0x00000040U)         /* !< write protect SPMEM21 - DATA2 */
#define LFSS_SPMWPROT5_WP_21_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_21_2_READONLY          ((uint32_t)0x00000040U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_21_1] Bits */
#define LFSS_SPMWPROT5_WP_21_1_OFS               (5)                             /* !< WP_21_1 Offset */
#define LFSS_SPMWPROT5_WP_21_1_MASK              ((uint32_t)0x00000020U)         /* !< write protect SPMEM21 - DATA1 */
#define LFSS_SPMWPROT5_WP_21_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_21_1_READONLY          ((uint32_t)0x00000020U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_21_0] Bits */
#define LFSS_SPMWPROT5_WP_21_0_OFS               (4)                             /* !< WP_21_0 Offset */
#define LFSS_SPMWPROT5_WP_21_0_MASK              ((uint32_t)0x00000010U)         /* !< write protect SPMEM21 - DATA0 */
#define LFSS_SPMWPROT5_WP_21_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_21_0_READONLY          ((uint32_t)0x00000010U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_20_3] Bits */
#define LFSS_SPMWPROT5_WP_20_3_OFS               (3)                             /* !< WP_20_3 Offset */
#define LFSS_SPMWPROT5_WP_20_3_MASK              ((uint32_t)0x00000008U)         /* !< write protect SPMEM20 - DATA3 */
#define LFSS_SPMWPROT5_WP_20_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_20_3_READONLY          ((uint32_t)0x00000008U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_20_2] Bits */
#define LFSS_SPMWPROT5_WP_20_2_OFS               (2)                             /* !< WP_20_2 Offset */
#define LFSS_SPMWPROT5_WP_20_2_MASK              ((uint32_t)0x00000004U)         /* !< write protect SPMEM20 - DATA2 */
#define LFSS_SPMWPROT5_WP_20_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_20_2_READONLY          ((uint32_t)0x00000004U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_20_1] Bits */
#define LFSS_SPMWPROT5_WP_20_1_OFS               (1)                             /* !< WP_20_1 Offset */
#define LFSS_SPMWPROT5_WP_20_1_MASK              ((uint32_t)0x00000002U)         /* !< write protect SPMEM20 - DATA1 */
#define LFSS_SPMWPROT5_WP_20_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_20_1_READONLY          ((uint32_t)0x00000002U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT5[WP_20_0] Bits */
#define LFSS_SPMWPROT5_WP_20_0_OFS               (0)                             /* !< WP_20_0 Offset */
#define LFSS_SPMWPROT5_WP_20_0_MASK              ((uint32_t)0x00000001U)         /* !< write protect SPMEM20 - DATA0 */
#define LFSS_SPMWPROT5_WP_20_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT5_WP_20_0_READONLY          ((uint32_t)0x00000001U)         /* !< SPMEM is read only access */

/* LFSS_SPMWPROT6 Bits */
/* LFSS_SPMWPROT6[KEY] Bits */
#define LFSS_SPMWPROT6_KEY_OFS                   (24)                            /* !< KEY Offset */
#define LFSS_SPMWPROT6_KEY_MASK                  ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xE8) to update
                                                                                    this register */
#define LFSS_SPMWPROT6_KEY_UNLOCK_W              ((uint32_t)0xE8000000U)         /* !< This field must be written with
                                                                                    0xE8 to be update the write protect
                                                                                    bits. */
/* LFSS_SPMWPROT6[WP_27_3] Bits */
#define LFSS_SPMWPROT6_WP_27_3_OFS               (15)                            /* !< WP_27_3 Offset */
#define LFSS_SPMWPROT6_WP_27_3_MASK              ((uint32_t)0x00008000U)         /* !< write protect SPMEM27 - DATA3 */
#define LFSS_SPMWPROT6_WP_27_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_27_3_READONLY          ((uint32_t)0x00008000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_27_2] Bits */
#define LFSS_SPMWPROT6_WP_27_2_OFS               (14)                            /* !< WP_27_2 Offset */
#define LFSS_SPMWPROT6_WP_27_2_MASK              ((uint32_t)0x00004000U)         /* !< write protect SPMEM27 - DATA2 */
#define LFSS_SPMWPROT6_WP_27_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_27_2_READONLY          ((uint32_t)0x00004000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_27_1] Bits */
#define LFSS_SPMWPROT6_WP_27_1_OFS               (13)                            /* !< WP_27_1 Offset */
#define LFSS_SPMWPROT6_WP_27_1_MASK              ((uint32_t)0x00002000U)         /* !< write protect SPMEM27 - DATA1 */
#define LFSS_SPMWPROT6_WP_27_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_27_1_READONLY          ((uint32_t)0x00002000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_27_0] Bits */
#define LFSS_SPMWPROT6_WP_27_0_OFS               (12)                            /* !< WP_27_0 Offset */
#define LFSS_SPMWPROT6_WP_27_0_MASK              ((uint32_t)0x00001000U)         /* !< write protect SPMEM27 - DATA0 */
#define LFSS_SPMWPROT6_WP_27_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_27_0_READONLY          ((uint32_t)0x00001000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_26_3] Bits */
#define LFSS_SPMWPROT6_WP_26_3_OFS               (11)                            /* !< WP_26_3 Offset */
#define LFSS_SPMWPROT6_WP_26_3_MASK              ((uint32_t)0x00000800U)         /* !< write protect SPMEM26 - DATA3 */
#define LFSS_SPMWPROT6_WP_26_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_26_3_READONLY          ((uint32_t)0x00000800U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_26_2] Bits */
#define LFSS_SPMWPROT6_WP_26_2_OFS               (10)                            /* !< WP_26_2 Offset */
#define LFSS_SPMWPROT6_WP_26_2_MASK              ((uint32_t)0x00000400U)         /* !< write protect SPMEM26- DATA2 */
#define LFSS_SPMWPROT6_WP_26_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_26_2_READONLY          ((uint32_t)0x00000400U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_26_1] Bits */
#define LFSS_SPMWPROT6_WP_26_1_OFS               (9)                             /* !< WP_26_1 Offset */
#define LFSS_SPMWPROT6_WP_26_1_MASK              ((uint32_t)0x00000200U)         /* !< write protect SPMEM26 - DATA1 */
#define LFSS_SPMWPROT6_WP_26_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_26_1_READONLY          ((uint32_t)0x00000200U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_26_0] Bits */
#define LFSS_SPMWPROT6_WP_26_0_OFS               (8)                             /* !< WP_26_0 Offset */
#define LFSS_SPMWPROT6_WP_26_0_MASK              ((uint32_t)0x00000100U)         /* !< write protect SPMEM26 - DATA0 */
#define LFSS_SPMWPROT6_WP_26_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_26_0_READONLY          ((uint32_t)0x00000100U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_25_3] Bits */
#define LFSS_SPMWPROT6_WP_25_3_OFS               (7)                             /* !< WP_25_3 Offset */
#define LFSS_SPMWPROT6_WP_25_3_MASK              ((uint32_t)0x00000080U)         /* !< write protect SPMEM25 - DATA3 */
#define LFSS_SPMWPROT6_WP_25_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_25_3_READONLY          ((uint32_t)0x00000080U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_25_2] Bits */
#define LFSS_SPMWPROT6_WP_25_2_OFS               (6)                             /* !< WP_25_2 Offset */
#define LFSS_SPMWPROT6_WP_25_2_MASK              ((uint32_t)0x00000040U)         /* !< write protect SPMEM25 - DATA2 */
#define LFSS_SPMWPROT6_WP_25_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_25_2_READONLY          ((uint32_t)0x00000040U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_25_1] Bits */
#define LFSS_SPMWPROT6_WP_25_1_OFS               (5)                             /* !< WP_25_1 Offset */
#define LFSS_SPMWPROT6_WP_25_1_MASK              ((uint32_t)0x00000020U)         /* !< write protect SPMEM25 - DATA1 */
#define LFSS_SPMWPROT6_WP_25_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_25_1_READONLY          ((uint32_t)0x00000020U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_25_0] Bits */
#define LFSS_SPMWPROT6_WP_25_0_OFS               (4)                             /* !< WP_25_0 Offset */
#define LFSS_SPMWPROT6_WP_25_0_MASK              ((uint32_t)0x00000010U)         /* !< write protect SPMEM25 - DATA0 */
#define LFSS_SPMWPROT6_WP_25_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_25_0_READONLY          ((uint32_t)0x00000010U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_24_3] Bits */
#define LFSS_SPMWPROT6_WP_24_3_OFS               (3)                             /* !< WP_24_3 Offset */
#define LFSS_SPMWPROT6_WP_24_3_MASK              ((uint32_t)0x00000008U)         /* !< write protect SPMEM24 - DATA3 */
#define LFSS_SPMWPROT6_WP_24_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_24_3_READONLY          ((uint32_t)0x00000008U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_24_2] Bits */
#define LFSS_SPMWPROT6_WP_24_2_OFS               (2)                             /* !< WP_24_2 Offset */
#define LFSS_SPMWPROT6_WP_24_2_MASK              ((uint32_t)0x00000004U)         /* !< write protect SPMEM24 - DATA2 */
#define LFSS_SPMWPROT6_WP_24_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_24_2_READONLY          ((uint32_t)0x00000004U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_24_1] Bits */
#define LFSS_SPMWPROT6_WP_24_1_OFS               (1)                             /* !< WP_24_1 Offset */
#define LFSS_SPMWPROT6_WP_24_1_MASK              ((uint32_t)0x00000002U)         /* !< write protect SPMEM24 - DATA1 */
#define LFSS_SPMWPROT6_WP_24_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_24_1_READONLY          ((uint32_t)0x00000002U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT6[WP_24_0] Bits */
#define LFSS_SPMWPROT6_WP_24_0_OFS               (0)                             /* !< WP_24_0 Offset */
#define LFSS_SPMWPROT6_WP_24_0_MASK              ((uint32_t)0x00000001U)         /* !< write protect SPMEM24 - DATA0 */
#define LFSS_SPMWPROT6_WP_24_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT6_WP_24_0_READONLY          ((uint32_t)0x00000001U)         /* !< SPMEM is read only access */

/* LFSS_SPMWPROT7 Bits */
/* LFSS_SPMWPROT7[KEY] Bits */
#define LFSS_SPMWPROT7_KEY_OFS                   (24)                            /* !< KEY Offset */
#define LFSS_SPMWPROT7_KEY_MASK                  ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xE8) to update
                                                                                    this register */
#define LFSS_SPMWPROT7_KEY_UNLOCK_W              ((uint32_t)0xE8000000U)         /* !< This field must be written with
                                                                                    0xE8 to be update the write protect
                                                                                    bits. */
/* LFSS_SPMWPROT7[WP_31_3] Bits */
#define LFSS_SPMWPROT7_WP_31_3_OFS               (15)                            /* !< WP_31_3 Offset */
#define LFSS_SPMWPROT7_WP_31_3_MASK              ((uint32_t)0x00008000U)         /* !< write protect SPMEM31 - DATA3 */
#define LFSS_SPMWPROT7_WP_31_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_31_3_READONLY          ((uint32_t)0x00008000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_31_2] Bits */
#define LFSS_SPMWPROT7_WP_31_2_OFS               (14)                            /* !< WP_31_2 Offset */
#define LFSS_SPMWPROT7_WP_31_2_MASK              ((uint32_t)0x00004000U)         /* !< write protect SPMEM31 - DATA2 */
#define LFSS_SPMWPROT7_WP_31_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_31_2_READONLY          ((uint32_t)0x00004000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_31_1] Bits */
#define LFSS_SPMWPROT7_WP_31_1_OFS               (13)                            /* !< WP_31_1 Offset */
#define LFSS_SPMWPROT7_WP_31_1_MASK              ((uint32_t)0x00002000U)         /* !< write protect SPMEM31 - DATA1 */
#define LFSS_SPMWPROT7_WP_31_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_31_1_READONLY          ((uint32_t)0x00002000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_31_0] Bits */
#define LFSS_SPMWPROT7_WP_31_0_OFS               (12)                            /* !< WP_31_0 Offset */
#define LFSS_SPMWPROT7_WP_31_0_MASK              ((uint32_t)0x00001000U)         /* !< write protect SPMEM31 - DATA0 */
#define LFSS_SPMWPROT7_WP_31_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_31_0_READONLY          ((uint32_t)0x00001000U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_30_3] Bits */
#define LFSS_SPMWPROT7_WP_30_3_OFS               (11)                            /* !< WP_30_3 Offset */
#define LFSS_SPMWPROT7_WP_30_3_MASK              ((uint32_t)0x00000800U)         /* !< write protect SPMEM30 - DATA3 */
#define LFSS_SPMWPROT7_WP_30_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_30_3_READONLY          ((uint32_t)0x00000800U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_30_2] Bits */
#define LFSS_SPMWPROT7_WP_30_2_OFS               (10)                            /* !< WP_30_2 Offset */
#define LFSS_SPMWPROT7_WP_30_2_MASK              ((uint32_t)0x00000400U)         /* !< write protect SPMEM30- DATA2 */
#define LFSS_SPMWPROT7_WP_30_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_30_2_READONLY          ((uint32_t)0x00000400U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_30_1] Bits */
#define LFSS_SPMWPROT7_WP_30_1_OFS               (9)                             /* !< WP_30_1 Offset */
#define LFSS_SPMWPROT7_WP_30_1_MASK              ((uint32_t)0x00000200U)         /* !< write protect SPMEM30 - DATA1 */
#define LFSS_SPMWPROT7_WP_30_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_30_1_READONLY          ((uint32_t)0x00000200U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_30_0] Bits */
#define LFSS_SPMWPROT7_WP_30_0_OFS               (8)                             /* !< WP_30_0 Offset */
#define LFSS_SPMWPROT7_WP_30_0_MASK              ((uint32_t)0x00000100U)         /* !< write protect SPMEM30 - DATA0 */
#define LFSS_SPMWPROT7_WP_30_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_30_0_READONLY          ((uint32_t)0x00000100U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_29_3] Bits */
#define LFSS_SPMWPROT7_WP_29_3_OFS               (7)                             /* !< WP_29_3 Offset */
#define LFSS_SPMWPROT7_WP_29_3_MASK              ((uint32_t)0x00000080U)         /* !< write protect SPMEM29 - DATA3 */
#define LFSS_SPMWPROT7_WP_29_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_29_3_READONLY          ((uint32_t)0x00000080U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_29_2] Bits */
#define LFSS_SPMWPROT7_WP_29_2_OFS               (6)                             /* !< WP_29_2 Offset */
#define LFSS_SPMWPROT7_WP_29_2_MASK              ((uint32_t)0x00000040U)         /* !< write protect SPMEM29 - DATA2 */
#define LFSS_SPMWPROT7_WP_29_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_29_2_READONLY          ((uint32_t)0x00000040U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_29_1] Bits */
#define LFSS_SPMWPROT7_WP_29_1_OFS               (5)                             /* !< WP_29_1 Offset */
#define LFSS_SPMWPROT7_WP_29_1_MASK              ((uint32_t)0x00000020U)         /* !< write protect SPMEM29 - DATA1 */
#define LFSS_SPMWPROT7_WP_29_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_29_1_READONLY          ((uint32_t)0x00000020U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_29_0] Bits */
#define LFSS_SPMWPROT7_WP_29_0_OFS               (4)                             /* !< WP_29_0 Offset */
#define LFSS_SPMWPROT7_WP_29_0_MASK              ((uint32_t)0x00000010U)         /* !< write protect SPMEM29 - DATA0 */
#define LFSS_SPMWPROT7_WP_29_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_29_0_READONLY          ((uint32_t)0x00000010U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_28_3] Bits */
#define LFSS_SPMWPROT7_WP_28_3_OFS               (3)                             /* !< WP_28_3 Offset */
#define LFSS_SPMWPROT7_WP_28_3_MASK              ((uint32_t)0x00000008U)         /* !< write protect SPMEM28 - DATA3 */
#define LFSS_SPMWPROT7_WP_28_3_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_28_3_READONLY          ((uint32_t)0x00000008U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_28_2] Bits */
#define LFSS_SPMWPROT7_WP_28_2_OFS               (2)                             /* !< WP_28_2 Offset */
#define LFSS_SPMWPROT7_WP_28_2_MASK              ((uint32_t)0x00000004U)         /* !< write protect SPMEM28 - DATA2 */
#define LFSS_SPMWPROT7_WP_28_2_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_28_2_READONLY          ((uint32_t)0x00000004U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_28_1] Bits */
#define LFSS_SPMWPROT7_WP_28_1_OFS               (1)                             /* !< WP_28_1 Offset */
#define LFSS_SPMWPROT7_WP_28_1_MASK              ((uint32_t)0x00000002U)         /* !< write protect SPMEM28 - DATA1 */
#define LFSS_SPMWPROT7_WP_28_1_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_28_1_READONLY          ((uint32_t)0x00000002U)         /* !< SPMEM is read only access */
/* LFSS_SPMWPROT7[WP_28_0] Bits */
#define LFSS_SPMWPROT7_WP_28_0_OFS               (0)                             /* !< WP_28_0 Offset */
#define LFSS_SPMWPROT7_WP_28_0_MASK              ((uint32_t)0x00000001U)         /* !< write protect SPMEM28 - DATA0 */
#define LFSS_SPMWPROT7_WP_28_0_READWRITE         ((uint32_t)0x00000000U)         /* !< SPMEM is read and write access */
#define LFSS_SPMWPROT7_WP_28_0_READONLY          ((uint32_t)0x00000001U)         /* !< SPMEM is read only access */

/* LFSS_SPMTERASE0 Bits */
/* LFSS_SPMTERASE0[KEY] Bits */
#define LFSS_SPMTERASE0_KEY_OFS                  (24)                            /* !< KEY Offset */
#define LFSS_SPMTERASE0_KEY_MASK                 ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xA3) to update
                                                                                    this register */
#define LFSS_SPMTERASE0_KEY_UNLOCK_W             ((uint32_t)0xA3000000U)         /* !< This field must be written with
                                                                                    0xA3 to be update the tamper erase
                                                                                    enable bit. */
/* LFSS_SPMTERASE0[TE_3_3] Bits */
#define LFSS_SPMTERASE0_TE_3_3_OFS               (15)                            /* !< TE_3_3 Offset */
#define LFSS_SPMTERASE0_TE_3_3_MASK              ((uint32_t)0x00008000U)         /* !< tamper erase enable SPMEM3 - DATA3 */
#define LFSS_SPMTERASE0_TE_3_3_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_3_3_ENABLE            ((uint32_t)0x00008000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_3_2] Bits */
#define LFSS_SPMTERASE0_TE_3_2_OFS               (14)                            /* !< TE_3_2 Offset */
#define LFSS_SPMTERASE0_TE_3_2_MASK              ((uint32_t)0x00004000U)         /* !< tamper erase enable SPMEM3 - DATA2 */
#define LFSS_SPMTERASE0_TE_3_2_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_3_2_ENABLE            ((uint32_t)0x00004000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_3_1] Bits */
#define LFSS_SPMTERASE0_TE_3_1_OFS               (13)                            /* !< TE_3_1 Offset */
#define LFSS_SPMTERASE0_TE_3_1_MASK              ((uint32_t)0x00002000U)         /* !< tamper erase enable SPMEM3 - DATA1 */
#define LFSS_SPMTERASE0_TE_3_1_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_3_1_ENABLE            ((uint32_t)0x00002000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_3_0] Bits */
#define LFSS_SPMTERASE0_TE_3_0_OFS               (12)                            /* !< TE_3_0 Offset */
#define LFSS_SPMTERASE0_TE_3_0_MASK              ((uint32_t)0x00001000U)         /* !< tamper erase enable SPMEM3 - DATA0 */
#define LFSS_SPMTERASE0_TE_3_0_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_3_0_ENABLE            ((uint32_t)0x00001000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_2_3] Bits */
#define LFSS_SPMTERASE0_TE_2_3_OFS               (11)                            /* !< TE_2_3 Offset */
#define LFSS_SPMTERASE0_TE_2_3_MASK              ((uint32_t)0x00000800U)         /* !< tamper erase enable SPMEM2 - DATA3 */
#define LFSS_SPMTERASE0_TE_2_3_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_2_3_ENABLE            ((uint32_t)0x00000800U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_2_2] Bits */
#define LFSS_SPMTERASE0_TE_2_2_OFS               (10)                            /* !< TE_2_2 Offset */
#define LFSS_SPMTERASE0_TE_2_2_MASK              ((uint32_t)0x00000400U)         /* !< tamper erase enable SPMEM2 - DATA2 */
#define LFSS_SPMTERASE0_TE_2_2_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_2_2_ENABLE            ((uint32_t)0x00000400U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_2_1] Bits */
#define LFSS_SPMTERASE0_TE_2_1_OFS               (9)                             /* !< TE_2_1 Offset */
#define LFSS_SPMTERASE0_TE_2_1_MASK              ((uint32_t)0x00000200U)         /* !< tamper erase enable SPMEM2 - DATA1 */
#define LFSS_SPMTERASE0_TE_2_1_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_2_1_ENABLE            ((uint32_t)0x00000200U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_2_0] Bits */
#define LFSS_SPMTERASE0_TE_2_0_OFS               (8)                             /* !< TE_2_0 Offset */
#define LFSS_SPMTERASE0_TE_2_0_MASK              ((uint32_t)0x00000100U)         /* !< tamper erase enable SPMEM2 - DATA0 */
#define LFSS_SPMTERASE0_TE_2_0_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_2_0_ENABLE            ((uint32_t)0x00000100U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_1_3] Bits */
#define LFSS_SPMTERASE0_TE_1_3_OFS               (7)                             /* !< TE_1_3 Offset */
#define LFSS_SPMTERASE0_TE_1_3_MASK              ((uint32_t)0x00000080U)         /* !< tamper erase enable SPMEM1 - DATA3 */
#define LFSS_SPMTERASE0_TE_1_3_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_1_3_ENABLE            ((uint32_t)0x00000080U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_1_2] Bits */
#define LFSS_SPMTERASE0_TE_1_2_OFS               (6)                             /* !< TE_1_2 Offset */
#define LFSS_SPMTERASE0_TE_1_2_MASK              ((uint32_t)0x00000040U)         /* !< tamper erase enable SPMEM1 - DATA2 */
#define LFSS_SPMTERASE0_TE_1_2_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_1_2_ENABLE            ((uint32_t)0x00000040U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_1_1] Bits */
#define LFSS_SPMTERASE0_TE_1_1_OFS               (5)                             /* !< TE_1_1 Offset */
#define LFSS_SPMTERASE0_TE_1_1_MASK              ((uint32_t)0x00000020U)         /* !< tamper erase enable SPMEM1 - DATA1 */
#define LFSS_SPMTERASE0_TE_1_1_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_1_1_ENABLE            ((uint32_t)0x00000020U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_1_0] Bits */
#define LFSS_SPMTERASE0_TE_1_0_OFS               (4)                             /* !< TE_1_0 Offset */
#define LFSS_SPMTERASE0_TE_1_0_MASK              ((uint32_t)0x00000010U)         /* !< tamper erase enable SPMEM1 - DATA0 */
#define LFSS_SPMTERASE0_TE_1_0_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_1_0_ENABLE            ((uint32_t)0x00000010U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_0_3] Bits */
#define LFSS_SPMTERASE0_TE_0_3_OFS               (3)                             /* !< TE_0_3 Offset */
#define LFSS_SPMTERASE0_TE_0_3_MASK              ((uint32_t)0x00000008U)         /* !< tamper erase enable SPMEM0 - DATA3 */
#define LFSS_SPMTERASE0_TE_0_3_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_0_3_ENABLE            ((uint32_t)0x00000008U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_0_2] Bits */
#define LFSS_SPMTERASE0_TE_0_2_OFS               (2)                             /* !< TE_0_2 Offset */
#define LFSS_SPMTERASE0_TE_0_2_MASK              ((uint32_t)0x00000004U)         /* !< tamper erase enable SPMEM0 - DATA2 */
#define LFSS_SPMTERASE0_TE_0_2_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_0_2_ENABLE            ((uint32_t)0x00000004U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_0_1] Bits */
#define LFSS_SPMTERASE0_TE_0_1_OFS               (1)                             /* !< TE_0_1 Offset */
#define LFSS_SPMTERASE0_TE_0_1_MASK              ((uint32_t)0x00000002U)         /* !< tamper erase enable SPMEM0 - DATA1 */
#define LFSS_SPMTERASE0_TE_0_1_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_0_1_ENABLE            ((uint32_t)0x00000002U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE0[TE_0_0] Bits */
#define LFSS_SPMTERASE0_TE_0_0_OFS               (0)                             /* !< TE_0_0 Offset */
#define LFSS_SPMTERASE0_TE_0_0_MASK              ((uint32_t)0x00000001U)         /* !< tamper erase enable SPMEM0 - DATA0 */
#define LFSS_SPMTERASE0_TE_0_0_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE0_TE_0_0_ENABLE            ((uint32_t)0x00000001U)         /* !< SPMEM will be erased with tamper
                                                                                    event */

/* LFSS_SPMTERASE1 Bits */
/* LFSS_SPMTERASE1[KEY] Bits */
#define LFSS_SPMTERASE1_KEY_OFS                  (24)                            /* !< KEY Offset */
#define LFSS_SPMTERASE1_KEY_MASK                 ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xA3) to update
                                                                                    this register */
#define LFSS_SPMTERASE1_KEY_UNLOCK_W             ((uint32_t)0xA3000000U)         /* !< This field must be written with
                                                                                    0xA3 to be update the tamper erase
                                                                                    enable bit. */
/* LFSS_SPMTERASE1[TE_7_3] Bits */
#define LFSS_SPMTERASE1_TE_7_3_OFS               (15)                            /* !< TE_7_3 Offset */
#define LFSS_SPMTERASE1_TE_7_3_MASK              ((uint32_t)0x00008000U)         /* !< tamper erase enable SPMEM7 - DATA3 */
#define LFSS_SPMTERASE1_TE_7_3_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_7_3_ENABLE            ((uint32_t)0x00008000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_7_2] Bits */
#define LFSS_SPMTERASE1_TE_7_2_OFS               (14)                            /* !< TE_7_2 Offset */
#define LFSS_SPMTERASE1_TE_7_2_MASK              ((uint32_t)0x00004000U)         /* !< tamper erase enable SPMEM7 - DATA2 */
#define LFSS_SPMTERASE1_TE_7_2_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_7_2_ENABLE            ((uint32_t)0x00004000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_7_1] Bits */
#define LFSS_SPMTERASE1_TE_7_1_OFS               (13)                            /* !< TE_7_1 Offset */
#define LFSS_SPMTERASE1_TE_7_1_MASK              ((uint32_t)0x00002000U)         /* !< tamper erase enable SPMEM7 - DATA1 */
#define LFSS_SPMTERASE1_TE_7_1_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_7_1_ENABLE            ((uint32_t)0x00002000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_7_0] Bits */
#define LFSS_SPMTERASE1_TE_7_0_OFS               (12)                            /* !< TE_7_0 Offset */
#define LFSS_SPMTERASE1_TE_7_0_MASK              ((uint32_t)0x00001000U)         /* !< tamper erase enable SPMEM7 - DATA0 */
#define LFSS_SPMTERASE1_TE_7_0_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_7_0_ENABLE            ((uint32_t)0x00001000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_6_3] Bits */
#define LFSS_SPMTERASE1_TE_6_3_OFS               (11)                            /* !< TE_6_3 Offset */
#define LFSS_SPMTERASE1_TE_6_3_MASK              ((uint32_t)0x00000800U)         /* !< tamper erase enable SPMEM6 - DATA3 */
#define LFSS_SPMTERASE1_TE_6_3_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_6_3_ENABLE            ((uint32_t)0x00000800U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_6_2] Bits */
#define LFSS_SPMTERASE1_TE_6_2_OFS               (10)                            /* !< TE_6_2 Offset */
#define LFSS_SPMTERASE1_TE_6_2_MASK              ((uint32_t)0x00000400U)         /* !< tamper erase enable SPMEM6 - DATA2 */
#define LFSS_SPMTERASE1_TE_6_2_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_6_2_ENABLE            ((uint32_t)0x00000400U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_6_1] Bits */
#define LFSS_SPMTERASE1_TE_6_1_OFS               (9)                             /* !< TE_6_1 Offset */
#define LFSS_SPMTERASE1_TE_6_1_MASK              ((uint32_t)0x00000200U)         /* !< tamper erase enable SPMEM6 - DATA1 */
#define LFSS_SPMTERASE1_TE_6_1_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_6_1_ENABLE            ((uint32_t)0x00000200U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_6_0] Bits */
#define LFSS_SPMTERASE1_TE_6_0_OFS               (8)                             /* !< TE_6_0 Offset */
#define LFSS_SPMTERASE1_TE_6_0_MASK              ((uint32_t)0x00000100U)         /* !< tamper erase enable SPMEM6 - DATA0 */
#define LFSS_SPMTERASE1_TE_6_0_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_6_0_ENABLE            ((uint32_t)0x00000100U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_5_3] Bits */
#define LFSS_SPMTERASE1_TE_5_3_OFS               (7)                             /* !< TE_5_3 Offset */
#define LFSS_SPMTERASE1_TE_5_3_MASK              ((uint32_t)0x00000080U)         /* !< tamper erase enable SPMEM5 - DATA3 */
#define LFSS_SPMTERASE1_TE_5_3_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_5_3_ENABLE            ((uint32_t)0x00000080U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_5_2] Bits */
#define LFSS_SPMTERASE1_TE_5_2_OFS               (6)                             /* !< TE_5_2 Offset */
#define LFSS_SPMTERASE1_TE_5_2_MASK              ((uint32_t)0x00000040U)         /* !< tamper erase enable SPMEM5 - DATA2 */
#define LFSS_SPMTERASE1_TE_5_2_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_5_2_ENABLE            ((uint32_t)0x00000040U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_5_1] Bits */
#define LFSS_SPMTERASE1_TE_5_1_OFS               (5)                             /* !< TE_5_1 Offset */
#define LFSS_SPMTERASE1_TE_5_1_MASK              ((uint32_t)0x00000020U)         /* !< tamper erase enable SPMEM5 - DATA1 */
#define LFSS_SPMTERASE1_TE_5_1_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_5_1_ENABLE            ((uint32_t)0x00000020U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_5_0] Bits */
#define LFSS_SPMTERASE1_TE_5_0_OFS               (4)                             /* !< TE_5_0 Offset */
#define LFSS_SPMTERASE1_TE_5_0_MASK              ((uint32_t)0x00000010U)         /* !< tamper erase enable SPMEM5 - DATA0 */
#define LFSS_SPMTERASE1_TE_5_0_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_5_0_ENABLE            ((uint32_t)0x00000010U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_4_3] Bits */
#define LFSS_SPMTERASE1_TE_4_3_OFS               (3)                             /* !< TE_4_3 Offset */
#define LFSS_SPMTERASE1_TE_4_3_MASK              ((uint32_t)0x00000008U)         /* !< tamper erase enable SPMEM4 - DATA3 */
#define LFSS_SPMTERASE1_TE_4_3_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_4_3_ENABLE            ((uint32_t)0x00000008U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_4_2] Bits */
#define LFSS_SPMTERASE1_TE_4_2_OFS               (2)                             /* !< TE_4_2 Offset */
#define LFSS_SPMTERASE1_TE_4_2_MASK              ((uint32_t)0x00000004U)         /* !< tamper erase enable SPMEM4 - DATA2 */
#define LFSS_SPMTERASE1_TE_4_2_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_4_2_ENABLE            ((uint32_t)0x00000004U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_4_1] Bits */
#define LFSS_SPMTERASE1_TE_4_1_OFS               (1)                             /* !< TE_4_1 Offset */
#define LFSS_SPMTERASE1_TE_4_1_MASK              ((uint32_t)0x00000002U)         /* !< tamper erase enable SPMEM4 - DATA1 */
#define LFSS_SPMTERASE1_TE_4_1_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_4_1_ENABLE            ((uint32_t)0x00000002U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE1[TE_4_0] Bits */
#define LFSS_SPMTERASE1_TE_4_0_OFS               (0)                             /* !< TE_4_0 Offset */
#define LFSS_SPMTERASE1_TE_4_0_MASK              ((uint32_t)0x00000001U)         /* !< tamper erase enable SPMEM4 - DATA0 */
#define LFSS_SPMTERASE1_TE_4_0_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE1_TE_4_0_ENABLE            ((uint32_t)0x00000001U)         /* !< SPMEM will be erased with tamper
                                                                                    event */

/* LFSS_SPMTERASE2 Bits */
/* LFSS_SPMTERASE2[KEY] Bits */
#define LFSS_SPMTERASE2_KEY_OFS                  (24)                            /* !< KEY Offset */
#define LFSS_SPMTERASE2_KEY_MASK                 ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xA3) to update
                                                                                    this register */
#define LFSS_SPMTERASE2_KEY_UNLOCK_W             ((uint32_t)0xA3000000U)         /* !< This field must be written with
                                                                                    0xA3 to be update the tamper erase
                                                                                    enable bit. */
/* LFSS_SPMTERASE2[TE_11_3] Bits */
#define LFSS_SPMTERASE2_TE_11_3_OFS              (15)                            /* !< TE_11_3 Offset */
#define LFSS_SPMTERASE2_TE_11_3_MASK             ((uint32_t)0x00008000U)         /* !< tamper erase enable SPMEM11 - DATA3 */
#define LFSS_SPMTERASE2_TE_11_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_11_3_ENABLE           ((uint32_t)0x00008000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_11_2] Bits */
#define LFSS_SPMTERASE2_TE_11_2_OFS              (14)                            /* !< TE_11_2 Offset */
#define LFSS_SPMTERASE2_TE_11_2_MASK             ((uint32_t)0x00004000U)         /* !< tamper erase enable SPMEM11 - DATA2 */
#define LFSS_SPMTERASE2_TE_11_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_11_2_ENABLE           ((uint32_t)0x00004000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_11_1] Bits */
#define LFSS_SPMTERASE2_TE_11_1_OFS              (13)                            /* !< TE_11_1 Offset */
#define LFSS_SPMTERASE2_TE_11_1_MASK             ((uint32_t)0x00002000U)         /* !< tamper erase enable SPMEM11 - DATA1 */
#define LFSS_SPMTERASE2_TE_11_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_11_1_ENABLE           ((uint32_t)0x00002000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_11_0] Bits */
#define LFSS_SPMTERASE2_TE_11_0_OFS              (12)                            /* !< TE_11_0 Offset */
#define LFSS_SPMTERASE2_TE_11_0_MASK             ((uint32_t)0x00001000U)         /* !< tamper erase enable SPMEM11 - DATA0 */
#define LFSS_SPMTERASE2_TE_11_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_11_0_ENABLE           ((uint32_t)0x00001000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_10_3] Bits */
#define LFSS_SPMTERASE2_TE_10_3_OFS              (11)                            /* !< TE_10_3 Offset */
#define LFSS_SPMTERASE2_TE_10_3_MASK             ((uint32_t)0x00000800U)         /* !< tamper erase enable SPMEM10 - DATA3 */
#define LFSS_SPMTERASE2_TE_10_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_10_3_ENABLE           ((uint32_t)0x00000800U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_10_2] Bits */
#define LFSS_SPMTERASE2_TE_10_2_OFS              (10)                            /* !< TE_10_2 Offset */
#define LFSS_SPMTERASE2_TE_10_2_MASK             ((uint32_t)0x00000400U)         /* !< tamper erase enable SPMEM10 - DATA2 */
#define LFSS_SPMTERASE2_TE_10_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_10_2_ENABLE           ((uint32_t)0x00000400U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_10_1] Bits */
#define LFSS_SPMTERASE2_TE_10_1_OFS              (9)                             /* !< TE_10_1 Offset */
#define LFSS_SPMTERASE2_TE_10_1_MASK             ((uint32_t)0x00000200U)         /* !< tamper erase enable SPMEM10 - DATA1 */
#define LFSS_SPMTERASE2_TE_10_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_10_1_ENABLE           ((uint32_t)0x00000200U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_10_0] Bits */
#define LFSS_SPMTERASE2_TE_10_0_OFS              (8)                             /* !< TE_10_0 Offset */
#define LFSS_SPMTERASE2_TE_10_0_MASK             ((uint32_t)0x00000100U)         /* !< tamper erase enable SPMEM10 - DATA0 */
#define LFSS_SPMTERASE2_TE_10_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_10_0_ENABLE           ((uint32_t)0x00000100U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_9_3] Bits */
#define LFSS_SPMTERASE2_TE_9_3_OFS               (7)                             /* !< TE_9_3 Offset */
#define LFSS_SPMTERASE2_TE_9_3_MASK              ((uint32_t)0x00000080U)         /* !< tamper erase enable SPMEM9 - DATA3 */
#define LFSS_SPMTERASE2_TE_9_3_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_9_3_ENABLE            ((uint32_t)0x00000080U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_9_2] Bits */
#define LFSS_SPMTERASE2_TE_9_2_OFS               (6)                             /* !< TE_9_2 Offset */
#define LFSS_SPMTERASE2_TE_9_2_MASK              ((uint32_t)0x00000040U)         /* !< tamper erase enable SPMEM9 - DATA2 */
#define LFSS_SPMTERASE2_TE_9_2_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_9_2_ENABLE            ((uint32_t)0x00000040U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_9_1] Bits */
#define LFSS_SPMTERASE2_TE_9_1_OFS               (5)                             /* !< TE_9_1 Offset */
#define LFSS_SPMTERASE2_TE_9_1_MASK              ((uint32_t)0x00000020U)         /* !< tamper erase enable SPMEM9 - DATA1 */
#define LFSS_SPMTERASE2_TE_9_1_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_9_1_ENABLE            ((uint32_t)0x00000020U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_9_0] Bits */
#define LFSS_SPMTERASE2_TE_9_0_OFS               (4)                             /* !< TE_9_0 Offset */
#define LFSS_SPMTERASE2_TE_9_0_MASK              ((uint32_t)0x00000010U)         /* !< tamper erase enable SPMEM9 - DATA0 */
#define LFSS_SPMTERASE2_TE_9_0_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_9_0_ENABLE            ((uint32_t)0x00000010U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_8_3] Bits */
#define LFSS_SPMTERASE2_TE_8_3_OFS               (3)                             /* !< TE_8_3 Offset */
#define LFSS_SPMTERASE2_TE_8_3_MASK              ((uint32_t)0x00000008U)         /* !< tamper erase enable SPMEM8 - DATA3 */
#define LFSS_SPMTERASE2_TE_8_3_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_8_3_ENABLE            ((uint32_t)0x00000008U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_8_2] Bits */
#define LFSS_SPMTERASE2_TE_8_2_OFS               (2)                             /* !< TE_8_2 Offset */
#define LFSS_SPMTERASE2_TE_8_2_MASK              ((uint32_t)0x00000004U)         /* !< tamper erase enable SPMEM8 - DATA2 */
#define LFSS_SPMTERASE2_TE_8_2_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_8_2_ENABLE            ((uint32_t)0x00000004U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_8_1] Bits */
#define LFSS_SPMTERASE2_TE_8_1_OFS               (1)                             /* !< TE_8_1 Offset */
#define LFSS_SPMTERASE2_TE_8_1_MASK              ((uint32_t)0x00000002U)         /* !< tamper erase enable SPMEM8 - DATA1 */
#define LFSS_SPMTERASE2_TE_8_1_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_8_1_ENABLE            ((uint32_t)0x00000002U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE2[TE_8_0] Bits */
#define LFSS_SPMTERASE2_TE_8_0_OFS               (0)                             /* !< TE_8_0 Offset */
#define LFSS_SPMTERASE2_TE_8_0_MASK              ((uint32_t)0x00000001U)         /* !< tamper erase enable SPMEM8 - DATA0 */
#define LFSS_SPMTERASE2_TE_8_0_DISABLE           ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE2_TE_8_0_ENABLE            ((uint32_t)0x00000001U)         /* !< SPMEM will be erased with tamper
                                                                                    event */

/* LFSS_SPMTERASE3 Bits */
/* LFSS_SPMTERASE3[KEY] Bits */
#define LFSS_SPMTERASE3_KEY_OFS                  (24)                            /* !< KEY Offset */
#define LFSS_SPMTERASE3_KEY_MASK                 ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xA3) to update
                                                                                    this register */
#define LFSS_SPMTERASE3_KEY_UNLOCK_W             ((uint32_t)0xA3000000U)         /* !< This field must be written with
                                                                                    0xA3 to be update the tamper erase
                                                                                    enable bit. */
/* LFSS_SPMTERASE3[TE_15_3] Bits */
#define LFSS_SPMTERASE3_TE_15_3_OFS              (15)                            /* !< TE_15_3 Offset */
#define LFSS_SPMTERASE3_TE_15_3_MASK             ((uint32_t)0x00008000U)         /* !< tamper erase enable SPMEM15 - DATA3 */
#define LFSS_SPMTERASE3_TE_15_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_15_3_ENABLE           ((uint32_t)0x00008000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_15_2] Bits */
#define LFSS_SPMTERASE3_TE_15_2_OFS              (14)                            /* !< TE_15_2 Offset */
#define LFSS_SPMTERASE3_TE_15_2_MASK             ((uint32_t)0x00004000U)         /* !< tamper erase enable SPMEM15 - DATA2 */
#define LFSS_SPMTERASE3_TE_15_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_15_2_ENABLE           ((uint32_t)0x00004000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_15_1] Bits */
#define LFSS_SPMTERASE3_TE_15_1_OFS              (13)                            /* !< TE_15_1 Offset */
#define LFSS_SPMTERASE3_TE_15_1_MASK             ((uint32_t)0x00002000U)         /* !< tamper erase enable SPMEM15 - DATA1 */
#define LFSS_SPMTERASE3_TE_15_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_15_1_ENABLE           ((uint32_t)0x00002000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_15_0] Bits */
#define LFSS_SPMTERASE3_TE_15_0_OFS              (12)                            /* !< TE_15_0 Offset */
#define LFSS_SPMTERASE3_TE_15_0_MASK             ((uint32_t)0x00001000U)         /* !< tamper erase enable SPMEM15 - DATA0 */
#define LFSS_SPMTERASE3_TE_15_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_15_0_ENABLE           ((uint32_t)0x00001000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_14_3] Bits */
#define LFSS_SPMTERASE3_TE_14_3_OFS              (11)                            /* !< TE_14_3 Offset */
#define LFSS_SPMTERASE3_TE_14_3_MASK             ((uint32_t)0x00000800U)         /* !< tamper erase enable SPMEM14 - DATA3 */
#define LFSS_SPMTERASE3_TE_14_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_14_3_ENABLE           ((uint32_t)0x00000800U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_14_2] Bits */
#define LFSS_SPMTERASE3_TE_14_2_OFS              (10)                            /* !< TE_14_2 Offset */
#define LFSS_SPMTERASE3_TE_14_2_MASK             ((uint32_t)0x00000400U)         /* !< tamper erase enable SPMEM14 - DATA2 */
#define LFSS_SPMTERASE3_TE_14_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_14_2_ENABLE           ((uint32_t)0x00000400U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_14_1] Bits */
#define LFSS_SPMTERASE3_TE_14_1_OFS              (9)                             /* !< TE_14_1 Offset */
#define LFSS_SPMTERASE3_TE_14_1_MASK             ((uint32_t)0x00000200U)         /* !< tamper erase enable SPMEM14 - DATA1 */
#define LFSS_SPMTERASE3_TE_14_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_14_1_ENABLE           ((uint32_t)0x00000200U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_14_0] Bits */
#define LFSS_SPMTERASE3_TE_14_0_OFS              (8)                             /* !< TE_14_0 Offset */
#define LFSS_SPMTERASE3_TE_14_0_MASK             ((uint32_t)0x00000100U)         /* !< tamper erase enable SPMEM14 - DATA0 */
#define LFSS_SPMTERASE3_TE_14_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_14_0_ENABLE           ((uint32_t)0x00000100U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_13_3] Bits */
#define LFSS_SPMTERASE3_TE_13_3_OFS              (7)                             /* !< TE_13_3 Offset */
#define LFSS_SPMTERASE3_TE_13_3_MASK             ((uint32_t)0x00000080U)         /* !< tamper erase enable SPMEM13 - DATA3 */
#define LFSS_SPMTERASE3_TE_13_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_13_3_ENABLE           ((uint32_t)0x00000080U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_13_2] Bits */
#define LFSS_SPMTERASE3_TE_13_2_OFS              (6)                             /* !< TE_13_2 Offset */
#define LFSS_SPMTERASE3_TE_13_2_MASK             ((uint32_t)0x00000040U)         /* !< tamper erase enable SPMEM13 - DATA2 */
#define LFSS_SPMTERASE3_TE_13_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_13_2_ENABLE           ((uint32_t)0x00000040U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_13_1] Bits */
#define LFSS_SPMTERASE3_TE_13_1_OFS              (5)                             /* !< TE_13_1 Offset */
#define LFSS_SPMTERASE3_TE_13_1_MASK             ((uint32_t)0x00000020U)         /* !< tamper erase enable SPMEM13 - DATA1 */
#define LFSS_SPMTERASE3_TE_13_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_13_1_ENABLE           ((uint32_t)0x00000020U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_13_0] Bits */
#define LFSS_SPMTERASE3_TE_13_0_OFS              (4)                             /* !< TE_13_0 Offset */
#define LFSS_SPMTERASE3_TE_13_0_MASK             ((uint32_t)0x00000010U)         /* !< tamper erase enable SPMEM13 - DATA0 */
#define LFSS_SPMTERASE3_TE_13_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_13_0_ENABLE           ((uint32_t)0x00000010U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_12_3] Bits */
#define LFSS_SPMTERASE3_TE_12_3_OFS              (3)                             /* !< TE_12_3 Offset */
#define LFSS_SPMTERASE3_TE_12_3_MASK             ((uint32_t)0x00000008U)         /* !< tamper erase enable SPMEM12 - DATA3 */
#define LFSS_SPMTERASE3_TE_12_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_12_3_ENABLE           ((uint32_t)0x00000008U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_12_2] Bits */
#define LFSS_SPMTERASE3_TE_12_2_OFS              (2)                             /* !< TE_12_2 Offset */
#define LFSS_SPMTERASE3_TE_12_2_MASK             ((uint32_t)0x00000004U)         /* !< tamper erase enable SPMEM12 - DATA2 */
#define LFSS_SPMTERASE3_TE_12_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_12_2_ENABLE           ((uint32_t)0x00000004U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_12_1] Bits */
#define LFSS_SPMTERASE3_TE_12_1_OFS              (1)                             /* !< TE_12_1 Offset */
#define LFSS_SPMTERASE3_TE_12_1_MASK             ((uint32_t)0x00000002U)         /* !< tamper erase enable SPMEM12 - DATA1 */
#define LFSS_SPMTERASE3_TE_12_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_12_1_ENABLE           ((uint32_t)0x00000002U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE3[TE_12_0] Bits */
#define LFSS_SPMTERASE3_TE_12_0_OFS              (0)                             /* !< TE_12_0 Offset */
#define LFSS_SPMTERASE3_TE_12_0_MASK             ((uint32_t)0x00000001U)         /* !< tamper erase enable SPMEM12 - DATA0 */
#define LFSS_SPMTERASE3_TE_12_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE3_TE_12_0_ENABLE           ((uint32_t)0x00000001U)         /* !< SPMEM will be erased with tamper
                                                                                    event */

/* LFSS_SPMTERASE4 Bits */
/* LFSS_SPMTERASE4[KEY] Bits */
#define LFSS_SPMTERASE4_KEY_OFS                  (24)                            /* !< KEY Offset */
#define LFSS_SPMTERASE4_KEY_MASK                 ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xA3) to update
                                                                                    this register */
#define LFSS_SPMTERASE4_KEY_UNLOCK_W             ((uint32_t)0xA3000000U)         /* !< This field must be written with
                                                                                    0xA3 to be update the tamper erase
                                                                                    enable bit. */
/* LFSS_SPMTERASE4[TE_19_3] Bits */
#define LFSS_SPMTERASE4_TE_19_3_OFS              (15)                            /* !< TE_19_3 Offset */
#define LFSS_SPMTERASE4_TE_19_3_MASK             ((uint32_t)0x00008000U)         /* !< tamper erase enable SPMEM19 - DATA3 */
#define LFSS_SPMTERASE4_TE_19_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_19_3_ENABLE           ((uint32_t)0x00008000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_19_2] Bits */
#define LFSS_SPMTERASE4_TE_19_2_OFS              (14)                            /* !< TE_19_2 Offset */
#define LFSS_SPMTERASE4_TE_19_2_MASK             ((uint32_t)0x00004000U)         /* !< tamper erase enable SPMEM19 - DATA2 */
#define LFSS_SPMTERASE4_TE_19_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_19_2_ENABLE           ((uint32_t)0x00004000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_19_1] Bits */
#define LFSS_SPMTERASE4_TE_19_1_OFS              (13)                            /* !< TE_19_1 Offset */
#define LFSS_SPMTERASE4_TE_19_1_MASK             ((uint32_t)0x00002000U)         /* !< tamper erase enable SPMEM19 - DATA1 */
#define LFSS_SPMTERASE4_TE_19_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_19_1_ENABLE           ((uint32_t)0x00002000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_19_0] Bits */
#define LFSS_SPMTERASE4_TE_19_0_OFS              (12)                            /* !< TE_19_0 Offset */
#define LFSS_SPMTERASE4_TE_19_0_MASK             ((uint32_t)0x00001000U)         /* !< tamper erase enable SPMEM19 - DATA0 */
#define LFSS_SPMTERASE4_TE_19_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_19_0_ENABLE           ((uint32_t)0x00001000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_18_3] Bits */
#define LFSS_SPMTERASE4_TE_18_3_OFS              (11)                            /* !< TE_18_3 Offset */
#define LFSS_SPMTERASE4_TE_18_3_MASK             ((uint32_t)0x00000800U)         /* !< tamper erase enable SPMEM18 - DATA3 */
#define LFSS_SPMTERASE4_TE_18_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_18_3_ENABLE           ((uint32_t)0x00000800U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_18_2] Bits */
#define LFSS_SPMTERASE4_TE_18_2_OFS              (10)                            /* !< TE_18_2 Offset */
#define LFSS_SPMTERASE4_TE_18_2_MASK             ((uint32_t)0x00000400U)         /* !< tamper erase enable SPMEM18 - DATA2 */
#define LFSS_SPMTERASE4_TE_18_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_18_2_ENABLE           ((uint32_t)0x00000400U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_18_1] Bits */
#define LFSS_SPMTERASE4_TE_18_1_OFS              (9)                             /* !< TE_18_1 Offset */
#define LFSS_SPMTERASE4_TE_18_1_MASK             ((uint32_t)0x00000200U)         /* !< tamper erase enable SPMEM18 - DATA1 */
#define LFSS_SPMTERASE4_TE_18_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_18_1_ENABLE           ((uint32_t)0x00000200U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_18_0] Bits */
#define LFSS_SPMTERASE4_TE_18_0_OFS              (8)                             /* !< TE_18_0 Offset */
#define LFSS_SPMTERASE4_TE_18_0_MASK             ((uint32_t)0x00000100U)         /* !< tamper erase enable SPMEM18 - DATA0 */
#define LFSS_SPMTERASE4_TE_18_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_18_0_ENABLE           ((uint32_t)0x00000100U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_17_3] Bits */
#define LFSS_SPMTERASE4_TE_17_3_OFS              (7)                             /* !< TE_17_3 Offset */
#define LFSS_SPMTERASE4_TE_17_3_MASK             ((uint32_t)0x00000080U)         /* !< tamper erase enable SPMEM17 - DATA3 */
#define LFSS_SPMTERASE4_TE_17_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_17_3_ENABLE           ((uint32_t)0x00000080U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_17_2] Bits */
#define LFSS_SPMTERASE4_TE_17_2_OFS              (6)                             /* !< TE_17_2 Offset */
#define LFSS_SPMTERASE4_TE_17_2_MASK             ((uint32_t)0x00000040U)         /* !< tamper erase enable SPMEM17 - DATA2 */
#define LFSS_SPMTERASE4_TE_17_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_17_2_ENABLE           ((uint32_t)0x00000040U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_17_1] Bits */
#define LFSS_SPMTERASE4_TE_17_1_OFS              (5)                             /* !< TE_17_1 Offset */
#define LFSS_SPMTERASE4_TE_17_1_MASK             ((uint32_t)0x00000020U)         /* !< tamper erase enable SPMEM17 - DATA1 */
#define LFSS_SPMTERASE4_TE_17_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_17_1_ENABLE           ((uint32_t)0x00000020U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_17_0] Bits */
#define LFSS_SPMTERASE4_TE_17_0_OFS              (4)                             /* !< TE_17_0 Offset */
#define LFSS_SPMTERASE4_TE_17_0_MASK             ((uint32_t)0x00000010U)         /* !< tamper erase enable SPMEM17 - DATA0 */
#define LFSS_SPMTERASE4_TE_17_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_17_0_ENABLE           ((uint32_t)0x00000010U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_16_3] Bits */
#define LFSS_SPMTERASE4_TE_16_3_OFS              (3)                             /* !< TE_16_3 Offset */
#define LFSS_SPMTERASE4_TE_16_3_MASK             ((uint32_t)0x00000008U)         /* !< tamper erase enable SPMEM16 - DATA3 */
#define LFSS_SPMTERASE4_TE_16_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_16_3_ENABLE           ((uint32_t)0x00000008U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_16_2] Bits */
#define LFSS_SPMTERASE4_TE_16_2_OFS              (2)                             /* !< TE_16_2 Offset */
#define LFSS_SPMTERASE4_TE_16_2_MASK             ((uint32_t)0x00000004U)         /* !< tamper erase enable SPMEM16 - DATA2 */
#define LFSS_SPMTERASE4_TE_16_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_16_2_ENABLE           ((uint32_t)0x00000004U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_16_1] Bits */
#define LFSS_SPMTERASE4_TE_16_1_OFS              (1)                             /* !< TE_16_1 Offset */
#define LFSS_SPMTERASE4_TE_16_1_MASK             ((uint32_t)0x00000002U)         /* !< tamper erase enable SPMEM16 - DATA1 */
#define LFSS_SPMTERASE4_TE_16_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_16_1_ENABLE           ((uint32_t)0x00000002U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE4[TE_16_0] Bits */
#define LFSS_SPMTERASE4_TE_16_0_OFS              (0)                             /* !< TE_16_0 Offset */
#define LFSS_SPMTERASE4_TE_16_0_MASK             ((uint32_t)0x00000001U)         /* !< tamper erase enable SPMEM16 - DATA0 */
#define LFSS_SPMTERASE4_TE_16_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE4_TE_16_0_ENABLE           ((uint32_t)0x00000001U)         /* !< SPMEM will be erased with tamper
                                                                                    event */

/* LFSS_SPMTERASE5 Bits */
/* LFSS_SPMTERASE5[KEY] Bits */
#define LFSS_SPMTERASE5_KEY_OFS                  (24)                            /* !< KEY Offset */
#define LFSS_SPMTERASE5_KEY_MASK                 ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xA3) to update
                                                                                    this register */
#define LFSS_SPMTERASE5_KEY_UNLOCK_W             ((uint32_t)0xA3000000U)         /* !< This field must be written with
                                                                                    0xA3 to be update the tamper erase
                                                                                    enable bit. */
/* LFSS_SPMTERASE5[TE_23_3] Bits */
#define LFSS_SPMTERASE5_TE_23_3_OFS              (15)                            /* !< TE_23_3 Offset */
#define LFSS_SPMTERASE5_TE_23_3_MASK             ((uint32_t)0x00008000U)         /* !< tamper erase enable SPMEM23 - DATA3 */
#define LFSS_SPMTERASE5_TE_23_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_23_3_ENABLE           ((uint32_t)0x00008000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_23_2] Bits */
#define LFSS_SPMTERASE5_TE_23_2_OFS              (14)                            /* !< TE_23_2 Offset */
#define LFSS_SPMTERASE5_TE_23_2_MASK             ((uint32_t)0x00004000U)         /* !< tamper erase enable SPMEM23 - DATA2 */
#define LFSS_SPMTERASE5_TE_23_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_23_2_ENABLE           ((uint32_t)0x00004000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_23_1] Bits */
#define LFSS_SPMTERASE5_TE_23_1_OFS              (13)                            /* !< TE_23_1 Offset */
#define LFSS_SPMTERASE5_TE_23_1_MASK             ((uint32_t)0x00002000U)         /* !< tamper erase enable SPMEM23 - DATA1 */
#define LFSS_SPMTERASE5_TE_23_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_23_1_ENABLE           ((uint32_t)0x00002000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_23_0] Bits */
#define LFSS_SPMTERASE5_TE_23_0_OFS              (12)                            /* !< TE_23_0 Offset */
#define LFSS_SPMTERASE5_TE_23_0_MASK             ((uint32_t)0x00001000U)         /* !< tamper erase enable SPMEM23 - DATA0 */
#define LFSS_SPMTERASE5_TE_23_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_23_0_ENABLE           ((uint32_t)0x00001000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_22_3] Bits */
#define LFSS_SPMTERASE5_TE_22_3_OFS              (11)                            /* !< TE_22_3 Offset */
#define LFSS_SPMTERASE5_TE_22_3_MASK             ((uint32_t)0x00000800U)         /* !< tamper erase enable SPMEM22 - DATA3 */
#define LFSS_SPMTERASE5_TE_22_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_22_3_ENABLE           ((uint32_t)0x00000800U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_22_2] Bits */
#define LFSS_SPMTERASE5_TE_22_2_OFS              (10)                            /* !< TE_22_2 Offset */
#define LFSS_SPMTERASE5_TE_22_2_MASK             ((uint32_t)0x00000400U)         /* !< tamper erase enable SPMEM22 - DATA2 */
#define LFSS_SPMTERASE5_TE_22_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_22_2_ENABLE           ((uint32_t)0x00000400U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_22_1] Bits */
#define LFSS_SPMTERASE5_TE_22_1_OFS              (9)                             /* !< TE_22_1 Offset */
#define LFSS_SPMTERASE5_TE_22_1_MASK             ((uint32_t)0x00000200U)         /* !< tamper erase enable SPMEM22 - DATA1 */
#define LFSS_SPMTERASE5_TE_22_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_22_1_ENABLE           ((uint32_t)0x00000200U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_22_0] Bits */
#define LFSS_SPMTERASE5_TE_22_0_OFS              (8)                             /* !< TE_22_0 Offset */
#define LFSS_SPMTERASE5_TE_22_0_MASK             ((uint32_t)0x00000100U)         /* !< tamper erase enable SPMEM22 - DATA0 */
#define LFSS_SPMTERASE5_TE_22_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_22_0_ENABLE           ((uint32_t)0x00000100U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_21_3] Bits */
#define LFSS_SPMTERASE5_TE_21_3_OFS              (7)                             /* !< TE_21_3 Offset */
#define LFSS_SPMTERASE5_TE_21_3_MASK             ((uint32_t)0x00000080U)         /* !< tamper erase enable SPMEM21 - DATA3 */
#define LFSS_SPMTERASE5_TE_21_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_21_3_ENABLE           ((uint32_t)0x00000080U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_21_2] Bits */
#define LFSS_SPMTERASE5_TE_21_2_OFS              (6)                             /* !< TE_21_2 Offset */
#define LFSS_SPMTERASE5_TE_21_2_MASK             ((uint32_t)0x00000040U)         /* !< tamper erase enable SPMEM21 - DATA2 */
#define LFSS_SPMTERASE5_TE_21_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_21_2_ENABLE           ((uint32_t)0x00000040U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_21_1] Bits */
#define LFSS_SPMTERASE5_TE_21_1_OFS              (5)                             /* !< TE_21_1 Offset */
#define LFSS_SPMTERASE5_TE_21_1_MASK             ((uint32_t)0x00000020U)         /* !< tamper erase enable SPMEM21 - DATA1 */
#define LFSS_SPMTERASE5_TE_21_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_21_1_ENABLE           ((uint32_t)0x00000020U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_21_0] Bits */
#define LFSS_SPMTERASE5_TE_21_0_OFS              (4)                             /* !< TE_21_0 Offset */
#define LFSS_SPMTERASE5_TE_21_0_MASK             ((uint32_t)0x00000010U)         /* !< tamper erase enable SPMEM21 - DATA0 */
#define LFSS_SPMTERASE5_TE_21_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_21_0_ENABLE           ((uint32_t)0x00000010U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_20_3] Bits */
#define LFSS_SPMTERASE5_TE_20_3_OFS              (3)                             /* !< TE_20_3 Offset */
#define LFSS_SPMTERASE5_TE_20_3_MASK             ((uint32_t)0x00000008U)         /* !< tamper erase enable SPMEM20 - DATA3 */
#define LFSS_SPMTERASE5_TE_20_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_20_3_ENABLE           ((uint32_t)0x00000008U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_20_2] Bits */
#define LFSS_SPMTERASE5_TE_20_2_OFS              (2)                             /* !< TE_20_2 Offset */
#define LFSS_SPMTERASE5_TE_20_2_MASK             ((uint32_t)0x00000004U)         /* !< tamper erase enable SPMEM20 - DATA2 */
#define LFSS_SPMTERASE5_TE_20_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_20_2_ENABLE           ((uint32_t)0x00000004U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_20_1] Bits */
#define LFSS_SPMTERASE5_TE_20_1_OFS              (1)                             /* !< TE_20_1 Offset */
#define LFSS_SPMTERASE5_TE_20_1_MASK             ((uint32_t)0x00000002U)         /* !< tamper erase enable SPMEM20 - DATA1 */
#define LFSS_SPMTERASE5_TE_20_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_20_1_ENABLE           ((uint32_t)0x00000002U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE5[TE_20_0] Bits */
#define LFSS_SPMTERASE5_TE_20_0_OFS              (0)                             /* !< TE_20_0 Offset */
#define LFSS_SPMTERASE5_TE_20_0_MASK             ((uint32_t)0x00000001U)         /* !< tamper erase enable SPMEM20 - DATA0 */
#define LFSS_SPMTERASE5_TE_20_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE5_TE_20_0_ENABLE           ((uint32_t)0x00000001U)         /* !< SPMEM will be erased with tamper
                                                                                    event */

/* LFSS_SPMTERASE6 Bits */
/* LFSS_SPMTERASE6[KEY] Bits */
#define LFSS_SPMTERASE6_KEY_OFS                  (24)                            /* !< KEY Offset */
#define LFSS_SPMTERASE6_KEY_MASK                 ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xA3) to update
                                                                                    this register */
#define LFSS_SPMTERASE6_KEY_UNLOCK_W             ((uint32_t)0xA3000000U)         /* !< This field must be written with
                                                                                    0xA3 to be update the tamper erase
                                                                                    enable bit. */
/* LFSS_SPMTERASE6[TE_27_3] Bits */
#define LFSS_SPMTERASE6_TE_27_3_OFS              (15)                            /* !< TE_27_3 Offset */
#define LFSS_SPMTERASE6_TE_27_3_MASK             ((uint32_t)0x00008000U)         /* !< tamper erase enable SPMEM27 - DATA3 */
#define LFSS_SPMTERASE6_TE_27_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_27_3_ENABLE           ((uint32_t)0x00008000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_27_2] Bits */
#define LFSS_SPMTERASE6_TE_27_2_OFS              (14)                            /* !< TE_27_2 Offset */
#define LFSS_SPMTERASE6_TE_27_2_MASK             ((uint32_t)0x00004000U)         /* !< tamper erase enable SPMEM27 - DATA2 */
#define LFSS_SPMTERASE6_TE_27_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_27_2_ENABLE           ((uint32_t)0x00004000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_27_1] Bits */
#define LFSS_SPMTERASE6_TE_27_1_OFS              (13)                            /* !< TE_27_1 Offset */
#define LFSS_SPMTERASE6_TE_27_1_MASK             ((uint32_t)0x00002000U)         /* !< tamper erase enable SPMEM27 - DATA1 */
#define LFSS_SPMTERASE6_TE_27_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_27_1_ENABLE           ((uint32_t)0x00002000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_27_0] Bits */
#define LFSS_SPMTERASE6_TE_27_0_OFS              (12)                            /* !< TE_27_0 Offset */
#define LFSS_SPMTERASE6_TE_27_0_MASK             ((uint32_t)0x00001000U)         /* !< tamper erase enable SPMEM27 - DATA0 */
#define LFSS_SPMTERASE6_TE_27_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_27_0_ENABLE           ((uint32_t)0x00001000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_26_3] Bits */
#define LFSS_SPMTERASE6_TE_26_3_OFS              (11)                            /* !< TE_26_3 Offset */
#define LFSS_SPMTERASE6_TE_26_3_MASK             ((uint32_t)0x00000800U)         /* !< tamper erase enable SPMEM26 - DATA3 */
#define LFSS_SPMTERASE6_TE_26_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_26_3_ENABLE           ((uint32_t)0x00000800U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_26_2] Bits */
#define LFSS_SPMTERASE6_TE_26_2_OFS              (10)                            /* !< TE_26_2 Offset */
#define LFSS_SPMTERASE6_TE_26_2_MASK             ((uint32_t)0x00000400U)         /* !< tamper erase enable SPMEM26 - DATA2 */
#define LFSS_SPMTERASE6_TE_26_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_26_2_ENABLE           ((uint32_t)0x00000400U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_26_1] Bits */
#define LFSS_SPMTERASE6_TE_26_1_OFS              (9)                             /* !< TE_26_1 Offset */
#define LFSS_SPMTERASE6_TE_26_1_MASK             ((uint32_t)0x00000200U)         /* !< tamper erase enable SPMEM26 - DATA1 */
#define LFSS_SPMTERASE6_TE_26_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_26_1_ENABLE           ((uint32_t)0x00000200U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_26_0] Bits */
#define LFSS_SPMTERASE6_TE_26_0_OFS              (8)                             /* !< TE_26_0 Offset */
#define LFSS_SPMTERASE6_TE_26_0_MASK             ((uint32_t)0x00000100U)         /* !< tamper erase enable SPMEM26 - DATA0 */
#define LFSS_SPMTERASE6_TE_26_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_26_0_ENABLE           ((uint32_t)0x00000100U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_25_3] Bits */
#define LFSS_SPMTERASE6_TE_25_3_OFS              (7)                             /* !< TE_25_3 Offset */
#define LFSS_SPMTERASE6_TE_25_3_MASK             ((uint32_t)0x00000080U)         /* !< tamper erase enable SPMEM25 - DATA3 */
#define LFSS_SPMTERASE6_TE_25_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_25_3_ENABLE           ((uint32_t)0x00000080U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_25_2] Bits */
#define LFSS_SPMTERASE6_TE_25_2_OFS              (6)                             /* !< TE_25_2 Offset */
#define LFSS_SPMTERASE6_TE_25_2_MASK             ((uint32_t)0x00000040U)         /* !< tamper erase enable SPMEM25 - DATA2 */
#define LFSS_SPMTERASE6_TE_25_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_25_2_ENABLE           ((uint32_t)0x00000040U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_25_1] Bits */
#define LFSS_SPMTERASE6_TE_25_1_OFS              (5)                             /* !< TE_25_1 Offset */
#define LFSS_SPMTERASE6_TE_25_1_MASK             ((uint32_t)0x00000020U)         /* !< tamper erase enable SPMEM25 - DATA1 */
#define LFSS_SPMTERASE6_TE_25_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_25_1_ENABLE           ((uint32_t)0x00000020U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_25_0] Bits */
#define LFSS_SPMTERASE6_TE_25_0_OFS              (4)                             /* !< TE_25_0 Offset */
#define LFSS_SPMTERASE6_TE_25_0_MASK             ((uint32_t)0x00000010U)         /* !< tamper erase enable SPMEM25 - DATA0 */
#define LFSS_SPMTERASE6_TE_25_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_25_0_ENABLE           ((uint32_t)0x00000010U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_24_3] Bits */
#define LFSS_SPMTERASE6_TE_24_3_OFS              (3)                             /* !< TE_24_3 Offset */
#define LFSS_SPMTERASE6_TE_24_3_MASK             ((uint32_t)0x00000008U)         /* !< tamper erase enable SPMEM24 - DATA3 */
#define LFSS_SPMTERASE6_TE_24_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_24_3_ENABLE           ((uint32_t)0x00000008U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_24_2] Bits */
#define LFSS_SPMTERASE6_TE_24_2_OFS              (2)                             /* !< TE_24_2 Offset */
#define LFSS_SPMTERASE6_TE_24_2_MASK             ((uint32_t)0x00000004U)         /* !< tamper erase enable SPMEM24 - DATA2 */
#define LFSS_SPMTERASE6_TE_24_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_24_2_ENABLE           ((uint32_t)0x00000004U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_24_1] Bits */
#define LFSS_SPMTERASE6_TE_24_1_OFS              (1)                             /* !< TE_24_1 Offset */
#define LFSS_SPMTERASE6_TE_24_1_MASK             ((uint32_t)0x00000002U)         /* !< tamper erase enable SPMEM24 - DATA1 */
#define LFSS_SPMTERASE6_TE_24_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_24_1_ENABLE           ((uint32_t)0x00000002U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE6[TE_24_0] Bits */
#define LFSS_SPMTERASE6_TE_24_0_OFS              (0)                             /* !< TE_24_0 Offset */
#define LFSS_SPMTERASE6_TE_24_0_MASK             ((uint32_t)0x00000001U)         /* !< tamper erase enable SPMEM24 - DATA0 */
#define LFSS_SPMTERASE6_TE_24_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE6_TE_24_0_ENABLE           ((uint32_t)0x00000001U)         /* !< SPMEM will be erased with tamper
                                                                                    event */

/* LFSS_SPMTERASE7 Bits */
/* LFSS_SPMTERASE7[KEY] Bits */
#define LFSS_SPMTERASE7_KEY_OFS                  (24)                            /* !< KEY Offset */
#define LFSS_SPMTERASE7_KEY_MASK                 ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xA3) to update
                                                                                    this register */
#define LFSS_SPMTERASE7_KEY_UNLOCK_W             ((uint32_t)0xA3000000U)         /* !< This field must be written with
                                                                                    0xA3 to be update the tamper erase
                                                                                    enable bit. */
/* LFSS_SPMTERASE7[TE_31_3] Bits */
#define LFSS_SPMTERASE7_TE_31_3_OFS              (15)                            /* !< TE_31_3 Offset */
#define LFSS_SPMTERASE7_TE_31_3_MASK             ((uint32_t)0x00008000U)         /* !< tamper erase enable SPMEM31 - DATA3 */
#define LFSS_SPMTERASE7_TE_31_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_31_3_ENABLE           ((uint32_t)0x00008000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_31_2] Bits */
#define LFSS_SPMTERASE7_TE_31_2_OFS              (14)                            /* !< TE_31_2 Offset */
#define LFSS_SPMTERASE7_TE_31_2_MASK             ((uint32_t)0x00004000U)         /* !< tamper erase enable SPMEM31 - DATA2 */
#define LFSS_SPMTERASE7_TE_31_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_31_2_ENABLE           ((uint32_t)0x00004000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_31_1] Bits */
#define LFSS_SPMTERASE7_TE_31_1_OFS              (13)                            /* !< TE_31_1 Offset */
#define LFSS_SPMTERASE7_TE_31_1_MASK             ((uint32_t)0x00002000U)         /* !< tamper erase enable SPMEM31 - DATA1 */
#define LFSS_SPMTERASE7_TE_31_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_31_1_ENABLE           ((uint32_t)0x00002000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_31_0] Bits */
#define LFSS_SPMTERASE7_TE_31_0_OFS              (12)                            /* !< TE_31_0 Offset */
#define LFSS_SPMTERASE7_TE_31_0_MASK             ((uint32_t)0x00001000U)         /* !< tamper erase enable SPMEM31 - DATA0 */
#define LFSS_SPMTERASE7_TE_31_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_31_0_ENABLE           ((uint32_t)0x00001000U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_30_3] Bits */
#define LFSS_SPMTERASE7_TE_30_3_OFS              (11)                            /* !< TE_30_3 Offset */
#define LFSS_SPMTERASE7_TE_30_3_MASK             ((uint32_t)0x00000800U)         /* !< tamper erase enable SPMEM30 - DATA3 */
#define LFSS_SPMTERASE7_TE_30_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_30_3_ENABLE           ((uint32_t)0x00000800U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_30_2] Bits */
#define LFSS_SPMTERASE7_TE_30_2_OFS              (10)                            /* !< TE_30_2 Offset */
#define LFSS_SPMTERASE7_TE_30_2_MASK             ((uint32_t)0x00000400U)         /* !< tamper erase enable SPMEM30 - DATA2 */
#define LFSS_SPMTERASE7_TE_30_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_30_2_ENABLE           ((uint32_t)0x00000400U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_30_1] Bits */
#define LFSS_SPMTERASE7_TE_30_1_OFS              (9)                             /* !< TE_30_1 Offset */
#define LFSS_SPMTERASE7_TE_30_1_MASK             ((uint32_t)0x00000200U)         /* !< tamper erase enable SPMEM30 - DATA1 */
#define LFSS_SPMTERASE7_TE_30_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_30_1_ENABLE           ((uint32_t)0x00000200U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_30_0] Bits */
#define LFSS_SPMTERASE7_TE_30_0_OFS              (8)                             /* !< TE_30_0 Offset */
#define LFSS_SPMTERASE7_TE_30_0_MASK             ((uint32_t)0x00000100U)         /* !< tamper erase enable SPMEM30 - DATA0 */
#define LFSS_SPMTERASE7_TE_30_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_30_0_ENABLE           ((uint32_t)0x00000100U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_29_3] Bits */
#define LFSS_SPMTERASE7_TE_29_3_OFS              (7)                             /* !< TE_29_3 Offset */
#define LFSS_SPMTERASE7_TE_29_3_MASK             ((uint32_t)0x00000080U)         /* !< tamper erase enable SPMEM29 - DATA3 */
#define LFSS_SPMTERASE7_TE_29_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_29_3_ENABLE           ((uint32_t)0x00000080U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_29_2] Bits */
#define LFSS_SPMTERASE7_TE_29_2_OFS              (6)                             /* !< TE_29_2 Offset */
#define LFSS_SPMTERASE7_TE_29_2_MASK             ((uint32_t)0x00000040U)         /* !< tamper erase enable SPMEM29 - DATA2 */
#define LFSS_SPMTERASE7_TE_29_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_29_2_ENABLE           ((uint32_t)0x00000040U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_29_1] Bits */
#define LFSS_SPMTERASE7_TE_29_1_OFS              (5)                             /* !< TE_29_1 Offset */
#define LFSS_SPMTERASE7_TE_29_1_MASK             ((uint32_t)0x00000020U)         /* !< tamper erase enable SPMEM29 - DATA1 */
#define LFSS_SPMTERASE7_TE_29_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_29_1_ENABLE           ((uint32_t)0x00000020U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_29_0] Bits */
#define LFSS_SPMTERASE7_TE_29_0_OFS              (4)                             /* !< TE_29_0 Offset */
#define LFSS_SPMTERASE7_TE_29_0_MASK             ((uint32_t)0x00000010U)         /* !< tamper erase enable SPMEM29 - DATA0 */
#define LFSS_SPMTERASE7_TE_29_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_29_0_ENABLE           ((uint32_t)0x00000010U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_28_3] Bits */
#define LFSS_SPMTERASE7_TE_28_3_OFS              (3)                             /* !< TE_28_3 Offset */
#define LFSS_SPMTERASE7_TE_28_3_MASK             ((uint32_t)0x00000008U)         /* !< tamper erase enable SPMEM28 - DATA3 */
#define LFSS_SPMTERASE7_TE_28_3_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_28_3_ENABLE           ((uint32_t)0x00000008U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_28_2] Bits */
#define LFSS_SPMTERASE7_TE_28_2_OFS              (2)                             /* !< TE_28_2 Offset */
#define LFSS_SPMTERASE7_TE_28_2_MASK             ((uint32_t)0x00000004U)         /* !< tamper erase enable SPMEM28 - DATA2 */
#define LFSS_SPMTERASE7_TE_28_2_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_28_2_ENABLE           ((uint32_t)0x00000004U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_28_1] Bits */
#define LFSS_SPMTERASE7_TE_28_1_OFS              (1)                             /* !< TE_28_1 Offset */
#define LFSS_SPMTERASE7_TE_28_1_MASK             ((uint32_t)0x00000002U)         /* !< tamper erase enable SPMEM28 - DATA1 */
#define LFSS_SPMTERASE7_TE_28_1_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_28_1_ENABLE           ((uint32_t)0x00000002U)         /* !< SPMEM will be erased with tamper
                                                                                    event */
/* LFSS_SPMTERASE7[TE_28_0] Bits */
#define LFSS_SPMTERASE7_TE_28_0_OFS              (0)                             /* !< TE_28_0 Offset */
#define LFSS_SPMTERASE7_TE_28_0_MASK             ((uint32_t)0x00000001U)         /* !< tamper erase enable SPMEM28 - DATA0 */
#define LFSS_SPMTERASE7_TE_28_0_DISABLE          ((uint32_t)0x00000000U)         /* !< SPMEM is unmodified during tamper
                                                                                    event */
#define LFSS_SPMTERASE7_TE_28_0_ENABLE           ((uint32_t)0x00000001U)         /* !< SPMEM will be erased with tamper
                                                                                    event */

/* LFSS_WDTEN Bits */
/* LFSS_WDTEN[ENABLE] Bits */
#define LFSS_WDTEN_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define LFSS_WDTEN_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< Enable bit for the WDT. */
#define LFSS_WDTEN_ENABLE_CLR                    ((uint32_t)0x00000000U)         /* !< Disable WDT */
#define LFSS_WDTEN_ENABLE_SET                    ((uint32_t)0x00000001U)         /* !< Enable WDT */
/* LFSS_WDTEN[KEY] Bits */
#define LFSS_WDTEN_KEY_OFS                       (24)                            /* !< KEY Offset */
#define LFSS_WDTEN_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to allow write access to this
                                                                                    register. Writing to this register
                                                                                    with an incorrect key causes a POR
                                                                                    level reset. Read as 0. */
#define LFSS_WDTEN_KEY_UNLOCK_W                  ((uint32_t)0xEE000000U)         /* !< This field must be written with
                                                                                    0xEE to be update the enable bit. */

/* LFSS_WDTDBGCTL Bits */
/* LFSS_WDTDBGCTL[FREE] Bits */
#define LFSS_WDTDBGCTL_FREE_OFS                  (0)                             /* !< FREE Offset */
#define LFSS_WDTDBGCTL_FREE_MASK                 ((uint32_t)0x00000001U)         /* !< Free run control */
#define LFSS_WDTDBGCTL_FREE_STOP                 ((uint32_t)0x00000000U)         /* !< The WDT freezes functionality while
                                                                                    the CPU is Halted during debug and
                                                                                    resumes when the CPU is active. */
#define LFSS_WDTDBGCTL_FREE_RUN                  ((uint32_t)0x00000001U)         /* !< The WDT ignores the state of the
                                                                                    CPU Halted debug state. */

/* LFSS_WDTCTL Bits */
/* LFSS_WDTCTL[CLKDIV] Bits */
#define LFSS_WDTCTL_CLKDIV_OFS                   (0)                             /* !< CLKDIV Offset */
#define LFSS_WDTCTL_CLKDIV_MASK                  ((uint32_t)0x00000007U)         /* !< Module Clock Divider, Divide the
                                                                                    clock source by CLKDIV+1. Divider
                                                                                    values from /1 to /8 are possible. */
#define LFSS_WDTCTL_CLKDIV_MIN                   ((uint32_t)0x00000000U)         /* !< Minimum value */
#define LFSS_WDTCTL_CLKDIV_MAX                   ((uint32_t)0x00000007U)         /* !< Maximum value */
/* LFSS_WDTCTL[PER] Bits */
#define LFSS_WDTCTL_PER_OFS                      (4)                             /* !< PER Offset */
#define LFSS_WDTCTL_PER_MASK                     ((uint32_t)0x00000070U)         /* !< Timer Period of the WDT. These bits
                                                                                    select the total watchdog timer
                                                                                    count. */
#define LFSS_WDTCTL_PER_PER_EN_25                ((uint32_t)0x00000000U)         /* !< Total timer count is 2^25 */
#define LFSS_WDTCTL_PER_PER_EN_21                ((uint32_t)0x00000010U)         /* !< Total timer count is 2^21 */
#define LFSS_WDTCTL_PER_PER_EN_18                ((uint32_t)0x00000020U)         /* !< Total timer count is 2^18 */
#define LFSS_WDTCTL_PER_PER_EN_15                ((uint32_t)0x00000030U)         /* !< Total timer count is 2^15 */
#define LFSS_WDTCTL_PER_PER_EN_12                ((uint32_t)0x00000040U)         /* !< Total timer count is 2^12 (default) */
#define LFSS_WDTCTL_PER_PER_EN_10                ((uint32_t)0x00000050U)         /* !< Total timer count is 2^10 */
#define LFSS_WDTCTL_PER_PER_EN_8                 ((uint32_t)0x00000060U)         /* !< Total timer count is 2^8 */
#define LFSS_WDTCTL_PER_PER_EN_6                 ((uint32_t)0x00000070U)         /* !< Total timer count is 2^6 */
/* LFSS_WDTCTL[KEY] Bits */
#define LFSS_WDTCTL_KEY_OFS                      (24)                            /* !< KEY Offset */
#define LFSS_WDTCTL_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< KEY to allow write access to this
                                                                                    register. Writing to this register
                                                                                    with an incorrect key causes a POR
                                                                                    level reset. Read as 0. */
#define LFSS_WDTCTL_KEY_UNLOCK_W                 ((uint32_t)0xC6000000U)         /* !< This field must be written with
                                                                                    0xC6 to be able to write any of the
                                                                                    enable bits */

/* LFSS_WDTCNTRST Bits */
/* LFSS_WDTCNTRST[RESTART] Bits */
#define LFSS_WDTCNTRST_RESTART_OFS               (0)                             /* !< RESTART Offset */
#define LFSS_WDTCNTRST_RESTART_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< Writing 03A7h to this register
                                                                                    restarts the WDT Counter. Writing any
                                                                                    other value causes a POR level reset.
                                                                                    Read as 0x0h. */
#define LFSS_WDTCNTRST_RESTART_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value */
#define LFSS_WDTCNTRST_RESTART_VALUE             ((uint32_t)0x000003A7U)         /* !< VALUE to restart the WDT counter */
#define LFSS_WDTCNTRST_RESTART_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value */

/* LFSS_WDTSTAT Bits */
/* LFSS_WDTSTAT[RUN] Bits */
#define LFSS_WDTSTAT_RUN_OFS                     (0)                             /* !< RUN Offset */
#define LFSS_WDTSTAT_RUN_MASK                    ((uint32_t)0x00000001U)         /* !< Watchdog running status flag. */
#define LFSS_WDTSTAT_RUN_STOP                    ((uint32_t)0x00000000U)         /* !< Watchdog counter stopped. */
#define LFSS_WDTSTAT_RUN_RUN                     ((uint32_t)0x00000001U)         /* !< Watchdog running. */

/* LFSS_WDTLOCK Bits */
/* LFSS_WDTLOCK[PROTECT] Bits */
#define LFSS_WDTLOCK_PROTECT_OFS                 (0)                             /* !< PROTECT Offset */
#define LFSS_WDTLOCK_PROTECT_MASK                ((uint32_t)0x00000001U)         /* !< If set, the register bit will
                                                                                    protect the WDTEN and WDTCTL from
                                                                                    accidental writes. */
#define LFSS_WDTLOCK_PROTECT_CLR                 ((uint32_t)0x00000000U)         /* !< Watchdog timer control is writable. */
#define LFSS_WDTLOCK_PROTECT_SET                 ((uint32_t)0x00000001U)         /* !< Watchdog timer control is read only
                                                                                    access. */
/* LFSS_WDTLOCK[KEY] Bits */
#define LFSS_WDTLOCK_KEY_OFS                     (24)                            /* !< KEY Offset */
#define LFSS_WDTLOCK_KEY_MASK                    ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xBD) to update
                                                                                    this register */
#define LFSS_WDTLOCK_KEY_UNLOCK_W                ((uint32_t)0xBD000000U)         /* !< This field must be written with
                                                                                    0xBD to be able to clear any of the
                                                                                    enable bits */

/* LFSS_TIOCTL Bits */
/* LFSS_TIOCTL[IOMUX] Bits */
#define LFSS_TIOCTL_IOMUX_OFS                    (0)                             /* !< IOMUX Offset */
#define LFSS_TIOCTL_IOMUX_MASK                   ((uint32_t)0x00000001U)         /* !< tamper I/O is controlled by SoC
                                                                                    IOMUX module */
#define LFSS_TIOCTL_IOMUX_IOMUX                  ((uint32_t)0x00000000U)         /* !< The tamper I/O is controlled by the
                                                                                    IOMUX of the SoC and does allow
                                                                                    assignment to a peripheral function.
                                                                                    In the case the main supply (VDD) is
                                                                                    lost, this I/O will go into a Hi-Z
                                                                                    state. */
#define LFSS_TIOCTL_IOMUX_TAMPER                 ((uint32_t)0x00000001U)         /* !< The tamper I/O is controlled by the
                                                                                    TIOCTL register and stays functional
                                                                                    during loss of the main supply (VDD). */
/* LFSS_TIOCTL[PIPD] Bits */
#define LFSS_TIOCTL_PIPD_OFS                     (16)                            /* !< PIPD Offset */
#define LFSS_TIOCTL_PIPD_MASK                    ((uint32_t)0x00010000U)         /* !< pull down enable */
#define LFSS_TIOCTL_PIPD_DISABLE                 ((uint32_t)0x00000000U)         /* !< The pull-down function is disabled. */
#define LFSS_TIOCTL_PIPD_ENABLE                  ((uint32_t)0x00010000U)         /* !< The pull-down function is enabled. */
/* LFSS_TIOCTL[PIPU] Bits */
#define LFSS_TIOCTL_PIPU_OFS                     (17)                            /* !< PIPU Offset */
#define LFSS_TIOCTL_PIPU_MASK                    ((uint32_t)0x00020000U)         /* !< pull up enable */
#define LFSS_TIOCTL_PIPU_DISABLE                 ((uint32_t)0x00000000U)         /* !< The pull-up function is disabled. */
#define LFSS_TIOCTL_PIPU_ENABLE                  ((uint32_t)0x00020000U)         /* !< The pull-up function is enabled. */
/* LFSS_TIOCTL[INENA] Bits */
#define LFSS_TIOCTL_INENA_OFS                    (18)                            /* !< INENA Offset */
#define LFSS_TIOCTL_INENA_MASK                   ((uint32_t)0x00040000U)         /* !< input enable */
#define LFSS_TIOCTL_INENA_DISABLE                ((uint32_t)0x00000000U)         /* !< The input path is disabled. */
#define LFSS_TIOCTL_INENA_ENABLE                 ((uint32_t)0x00040000U)         /* !< The input path is enabled. */
/* LFSS_TIOCTL[POLARITY] Bits */
#define LFSS_TIOCTL_POLARITY_OFS                 (8)                             /* !< POLARITY Offset */
#define LFSS_TIOCTL_POLARITY_MASK                ((uint32_t)0x00000300U)         /* !< Enables and configures edge
                                                                                    detection polarity for TIO */
#define LFSS_TIOCTL_POLARITY_DISABLE             ((uint32_t)0x00000000U)         /* !< Edge detection disabled */
#define LFSS_TIOCTL_POLARITY_RISE                ((uint32_t)0x00000100U)         /* !< Detects rising edge of input event */
#define LFSS_TIOCTL_POLARITY_FALL                ((uint32_t)0x00000200U)         /* !< Detects falling edge of input event */
#define LFSS_TIOCTL_POLARITY_BOTH                ((uint32_t)0x00000300U)         /* !< Detects both rising and falling
                                                                                    edge of input event */
/* LFSS_TIOCTL[FILTEREN] Bits */
#define LFSS_TIOCTL_FILTEREN_OFS                 (12)                            /* !< FILTEREN Offset */
#define LFSS_TIOCTL_FILTEREN_MASK                ((uint32_t)0x00003000U)         /* !< Programmable counter length of
                                                                                    digital glitch filter for TIO0 */
#define LFSS_TIOCTL_FILTEREN_NO_FLT              ((uint32_t)0x00000000U)         /* !< no filter on the tamper I/O beyond
                                                                                    CDC synchronization sample */
#define LFSS_TIOCTL_FILTEREN_FLT_1               ((uint32_t)0x00001000U)         /* !< 1 FLCLK minimum sample (30us) */
#define LFSS_TIOCTL_FILTEREN_FLT_2               ((uint32_t)0x00002000U)         /* !< 3 LFCLK minimum sample (100us) */
#define LFSS_TIOCTL_FILTEREN_FLT_3               ((uint32_t)0x00003000U)         /* !< 6 LFCLK minimum sample (200us) */
/* LFSS_TIOCTL[TOUTSEL] Bits */
#define LFSS_TIOCTL_TOUTSEL_OFS                  (4)                             /* !< TOUTSEL Offset */
#define LFSS_TIOCTL_TOUTSEL_MASK                 ((uint32_t)0x00000030U)         /* !< Selects the source for TOUT control */
#define LFSS_TIOCTL_TOUTSEL_TOUT                 ((uint32_t)0x00000000U)         /* !< The TOUT register is the source for
                                                                                    TOUT */
#define LFSS_TIOCTL_TOUTSEL_LFCLKEXT             ((uint32_t)0x00000010U)         /* !< The LFCLK is the source for TOUT */
#define LFSS_TIOCTL_TOUTSEL_HEARTBEAT            ((uint32_t)0x00000020U)         /* !< The heart beat generatore is the
                                                                                    source for TOUT */
#define LFSS_TIOCTL_TOUTSEL_TSEVTSTAT            ((uint32_t)0x00000030U)         /* !< The time stamp event status is the
                                                                                    source for TOUT */
/* LFSS_TIOCTL[OUTINV] Bits */
#define LFSS_TIOCTL_OUTINV_OFS                   (19)                            /* !< OUTINV Offset */
#define LFSS_TIOCTL_OUTINV_MASK                  ((uint32_t)0x00080000U)         /* !< Output inversion enable */
#define LFSS_TIOCTL_OUTINV_DISBALE               ((uint32_t)0x00000000U)         /* !< The output inversion is disabled. */
#define LFSS_TIOCTL_OUTINV_ENABLE                ((uint32_t)0x00080000U)         /* !< The output inversion is enabled. */

/* LFSS_TOUT3_0 Bits */
/* LFSS_TOUT3_0[TIO0] Bits */
#define LFSS_TOUT3_0_TIO0_OFS                    (0)                             /* !< TIO0 Offset */
#define LFSS_TOUT3_0_TIO0_MASK                   ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 0 (TIO0) when the output
                                                                                    is enabled through TOE0 register. */
#define LFSS_TOUT3_0_TIO0_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT3_0_TIO0_ONE                    ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* LFSS_TOUT3_0[TIO1] Bits */
#define LFSS_TOUT3_0_TIO1_OFS                    (8)                             /* !< TIO1 Offset */
#define LFSS_TOUT3_0_TIO1_MASK                   ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 1 (TIO1) when the output
                                                                                    is enabled through TOE1 register. */
#define LFSS_TOUT3_0_TIO1_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT3_0_TIO1_ONE                    ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* LFSS_TOUT3_0[TIO2] Bits */
#define LFSS_TOUT3_0_TIO2_OFS                    (16)                            /* !< TIO2 Offset */
#define LFSS_TOUT3_0_TIO2_MASK                   ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 2 (TIO0) when the output
                                                                                    is enabled through TOE2 register. */
#define LFSS_TOUT3_0_TIO2_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT3_0_TIO2_ONE                    ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* LFSS_TOUT3_0[TIO3] Bits */
#define LFSS_TOUT3_0_TIO3_OFS                    (24)                            /* !< TIO3 Offset */
#define LFSS_TOUT3_0_TIO3_MASK                   ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 3 (TIO3) when the output
                                                                                    is enabled through TOE3 register. */
#define LFSS_TOUT3_0_TIO3_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT3_0_TIO3_ONE                    ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* LFSS_TOUT7_4 Bits */
/* LFSS_TOUT7_4[TIO4] Bits */
#define LFSS_TOUT7_4_TIO4_OFS                    (0)                             /* !< TIO4 Offset */
#define LFSS_TOUT7_4_TIO4_MASK                   ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 4 (TIO4) when the output
                                                                                    is enabled through TOE4 register. */
#define LFSS_TOUT7_4_TIO4_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT7_4_TIO4_ONE                    ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* LFSS_TOUT7_4[TIO5] Bits */
#define LFSS_TOUT7_4_TIO5_OFS                    (8)                             /* !< TIO5 Offset */
#define LFSS_TOUT7_4_TIO5_MASK                   ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 5 (TIO5) when the output
                                                                                    is enabled through TOE5 register. */
#define LFSS_TOUT7_4_TIO5_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT7_4_TIO5_ONE                    ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* LFSS_TOUT7_4[TIO6] Bits */
#define LFSS_TOUT7_4_TIO6_OFS                    (16)                            /* !< TIO6 Offset */
#define LFSS_TOUT7_4_TIO6_MASK                   ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 2 (TIO6) when the output
                                                                                    is enabled through TOE6 register. */
#define LFSS_TOUT7_4_TIO6_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT7_4_TIO6_ONE                    ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* LFSS_TOUT7_4[TIO7] Bits */
#define LFSS_TOUT7_4_TIO7_OFS                    (24)                            /* !< TIO7 Offset */
#define LFSS_TOUT7_4_TIO7_MASK                   ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 7 (TIO7) when the output
                                                                                    is enabled through TOE7 register. */
#define LFSS_TOUT7_4_TIO7_ZERO                   ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT7_4_TIO7_ONE                    ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* LFSS_TOUT11_8 Bits */
/* LFSS_TOUT11_8[TIO8] Bits */
#define LFSS_TOUT11_8_TIO8_OFS                   (0)                             /* !< TIO8 Offset */
#define LFSS_TOUT11_8_TIO8_MASK                  ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 8 (TIO8) when the output
                                                                                    is enabled through TOE8 register. */
#define LFSS_TOUT11_8_TIO8_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT11_8_TIO8_ONE                   ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* LFSS_TOUT11_8[TIO9] Bits */
#define LFSS_TOUT11_8_TIO9_OFS                   (8)                             /* !< TIO9 Offset */
#define LFSS_TOUT11_8_TIO9_MASK                  ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 9 (TIO9) when the output
                                                                                    is enabled through TOE9 register. */
#define LFSS_TOUT11_8_TIO9_ZERO                  ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT11_8_TIO9_ONE                   ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* LFSS_TOUT11_8[TIO10] Bits */
#define LFSS_TOUT11_8_TIO10_OFS                  (16)                            /* !< TIO10 Offset */
#define LFSS_TOUT11_8_TIO10_MASK                 ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 10 (TIO10) when the output
                                                                                    is enabled through TOE10 register. */
#define LFSS_TOUT11_8_TIO10_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT11_8_TIO10_ONE                  ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* LFSS_TOUT11_8[TIO11] Bits */
#define LFSS_TOUT11_8_TIO11_OFS                  (24)                            /* !< TIO11 Offset */
#define LFSS_TOUT11_8_TIO11_MASK                 ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 11 (TIO11) when the output
                                                                                    is enabled through TOE11 register. */
#define LFSS_TOUT11_8_TIO11_ZERO                 ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT11_8_TIO11_ONE                  ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* LFSS_TOUT15_12 Bits */
/* LFSS_TOUT15_12[TIO12] Bits */
#define LFSS_TOUT15_12_TIO12_OFS                 (0)                             /* !< TIO12 Offset */
#define LFSS_TOUT15_12_TIO12_MASK                ((uint32_t)0x00000001U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 12 (TIO12) when the output
                                                                                    is enabled through TOE12 register. */
#define LFSS_TOUT15_12_TIO12_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT15_12_TIO12_ONE                 ((uint32_t)0x00000001U)         /* !< Output is set to 1 */
/* LFSS_TOUT15_12[TIO13] Bits */
#define LFSS_TOUT15_12_TIO13_OFS                 (8)                             /* !< TIO13 Offset */
#define LFSS_TOUT15_12_TIO13_MASK                ((uint32_t)0x00000100U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 13 (TIO13) when the output
                                                                                    is enabled through TOE13 register. */
#define LFSS_TOUT15_12_TIO13_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT15_12_TIO13_ONE                 ((uint32_t)0x00000100U)         /* !< Output is set to 1 */
/* LFSS_TOUT15_12[TIO14] Bits */
#define LFSS_TOUT15_12_TIO14_OFS                 (16)                            /* !< TIO14 Offset */
#define LFSS_TOUT15_12_TIO14_MASK                ((uint32_t)0x00010000U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 14 (TIO14) when the output
                                                                                    is enabled through TOE14 register. */
#define LFSS_TOUT15_12_TIO14_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT15_12_TIO14_ONE                 ((uint32_t)0x00010000U)         /* !< Output is set to 1 */
/* LFSS_TOUT15_12[TIO15] Bits */
#define LFSS_TOUT15_12_TIO15_OFS                 (24)                            /* !< TIO15 Offset */
#define LFSS_TOUT15_12_TIO15_MASK                ((uint32_t)0x01000000U)         /* !< This bit sets the value of the pin
                                                                                    tamper I/O 15 (TIO15) when the output
                                                                                    is enabled through TOE15 register. */
#define LFSS_TOUT15_12_TIO15_ZERO                ((uint32_t)0x00000000U)         /* !< Output is set to 0 */
#define LFSS_TOUT15_12_TIO15_ONE                 ((uint32_t)0x01000000U)         /* !< Output is set to 1 */

/* LFSS_TOE3_0 Bits */
/* LFSS_TOE3_0[TIO0] Bits */
#define LFSS_TOE3_0_TIO0_OFS                     (0)                             /* !< TIO0 Offset */
#define LFSS_TOE3_0_TIO0_MASK                    ((uint32_t)0x00000001U)         /* !< Enables data output for tamper I/O
                                                                                    0 */
#define LFSS_TOE3_0_TIO0_DISABLE                 ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE3_0_TIO0_ENABLE                  ((uint32_t)0x00000001U)         /* !< output enabled */
/* LFSS_TOE3_0[TIO1] Bits */
#define LFSS_TOE3_0_TIO1_OFS                     (8)                             /* !< TIO1 Offset */
#define LFSS_TOE3_0_TIO1_MASK                    ((uint32_t)0x00000100U)         /* !< Enables data output for tamper I/O
                                                                                    1 */
#define LFSS_TOE3_0_TIO1_DISABLE                 ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE3_0_TIO1_ENABLE                  ((uint32_t)0x00000100U)         /* !< output enabled */
/* LFSS_TOE3_0[TIO2] Bits */
#define LFSS_TOE3_0_TIO2_OFS                     (16)                            /* !< TIO2 Offset */
#define LFSS_TOE3_0_TIO2_MASK                    ((uint32_t)0x00010000U)         /* !< Enables data output for tamper I/O
                                                                                    2 */
#define LFSS_TOE3_0_TIO2_DISABLE                 ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE3_0_TIO2_ENABLE                  ((uint32_t)0x00010000U)         /* !< output enabled */
/* LFSS_TOE3_0[TIO3] Bits */
#define LFSS_TOE3_0_TIO3_OFS                     (24)                            /* !< TIO3 Offset */
#define LFSS_TOE3_0_TIO3_MASK                    ((uint32_t)0x01000000U)         /* !< Enables data output for tamper I/O
                                                                                    3 */
#define LFSS_TOE3_0_TIO3_DISABLE                 ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE3_0_TIO3_ENABLE                  ((uint32_t)0x01000000U)         /* !< output enabled */

/* LFSS_TOE7_4 Bits */
/* LFSS_TOE7_4[TIO4] Bits */
#define LFSS_TOE7_4_TIO4_OFS                     (0)                             /* !< TIO4 Offset */
#define LFSS_TOE7_4_TIO4_MASK                    ((uint32_t)0x00000001U)         /* !< Enables data output for tamper I/O
                                                                                    4 */
#define LFSS_TOE7_4_TIO4_DISABLE                 ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE7_4_TIO4_ENABLE                  ((uint32_t)0x00000001U)         /* !< output enabled */
/* LFSS_TOE7_4[TIO5] Bits */
#define LFSS_TOE7_4_TIO5_OFS                     (8)                             /* !< TIO5 Offset */
#define LFSS_TOE7_4_TIO5_MASK                    ((uint32_t)0x00000100U)         /* !< Enables data output for tamper I/O
                                                                                    5 */
#define LFSS_TOE7_4_TIO5_DISABLE                 ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE7_4_TIO5_ENABLE                  ((uint32_t)0x00000100U)         /* !< output enabled */
/* LFSS_TOE7_4[TIO6] Bits */
#define LFSS_TOE7_4_TIO6_OFS                     (16)                            /* !< TIO6 Offset */
#define LFSS_TOE7_4_TIO6_MASK                    ((uint32_t)0x00010000U)         /* !< Enables data output for tamper I/O
                                                                                    6 */
#define LFSS_TOE7_4_TIO6_DISABLE                 ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE7_4_TIO6_ENABLE                  ((uint32_t)0x00010000U)         /* !< output enabled */
/* LFSS_TOE7_4[TIO7] Bits */
#define LFSS_TOE7_4_TIO7_OFS                     (24)                            /* !< TIO7 Offset */
#define LFSS_TOE7_4_TIO7_MASK                    ((uint32_t)0x01000000U)         /* !< Enables data output for tamper I/O
                                                                                    7 */
#define LFSS_TOE7_4_TIO7_DISABLE                 ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE7_4_TIO7_ENABLE                  ((uint32_t)0x01000000U)         /* !< output enabled */

/* LFSS_TOE11_8 Bits */
/* LFSS_TOE11_8[TIO8] Bits */
#define LFSS_TOE11_8_TIO8_OFS                    (0)                             /* !< TIO8 Offset */
#define LFSS_TOE11_8_TIO8_MASK                   ((uint32_t)0x00000001U)         /* !< Enables data output for tamper I/O
                                                                                    8 */
#define LFSS_TOE11_8_TIO8_DISABLE                ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE11_8_TIO8_ENABLE                 ((uint32_t)0x00000001U)         /* !< output enabled */
/* LFSS_TOE11_8[TIO9] Bits */
#define LFSS_TOE11_8_TIO9_OFS                    (8)                             /* !< TIO9 Offset */
#define LFSS_TOE11_8_TIO9_MASK                   ((uint32_t)0x00000100U)         /* !< Enables data output for tamper I/O
                                                                                    9 */
#define LFSS_TOE11_8_TIO9_DISABLE                ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE11_8_TIO9_ENABLE                 ((uint32_t)0x00000100U)         /* !< output enabled */
/* LFSS_TOE11_8[TIO10] Bits */
#define LFSS_TOE11_8_TIO10_OFS                   (16)                            /* !< TIO10 Offset */
#define LFSS_TOE11_8_TIO10_MASK                  ((uint32_t)0x00010000U)         /* !< Enables data output for tamper I/O
                                                                                    10 */
#define LFSS_TOE11_8_TIO10_DISABLE               ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE11_8_TIO10_ENABLE                ((uint32_t)0x00010000U)         /* !< output enabled */
/* LFSS_TOE11_8[TIO11] Bits */
#define LFSS_TOE11_8_TIO11_OFS                   (24)                            /* !< TIO11 Offset */
#define LFSS_TOE11_8_TIO11_MASK                  ((uint32_t)0x01000000U)         /* !< Enables data output for tamper I/O
                                                                                    11 */
#define LFSS_TOE11_8_TIO11_DISABLE               ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE11_8_TIO11_ENABLE                ((uint32_t)0x01000000U)         /* !< output enabled */

/* LFSS_TOE15_12 Bits */
/* LFSS_TOE15_12[TIO12] Bits */
#define LFSS_TOE15_12_TIO12_OFS                  (0)                             /* !< TIO12 Offset */
#define LFSS_TOE15_12_TIO12_MASK                 ((uint32_t)0x00000001U)         /* !< Enables data output for tamper I/O
                                                                                    12 */
#define LFSS_TOE15_12_TIO12_DISABLE              ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE15_12_TIO12_ENABLE               ((uint32_t)0x00000001U)         /* !< output enabled */
/* LFSS_TOE15_12[TIO13] Bits */
#define LFSS_TOE15_12_TIO13_OFS                  (8)                             /* !< TIO13 Offset */
#define LFSS_TOE15_12_TIO13_MASK                 ((uint32_t)0x00000100U)         /* !< Enables data output for tamper I/O
                                                                                    13 */
#define LFSS_TOE15_12_TIO13_DISABLE              ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE15_12_TIO13_ENABLE               ((uint32_t)0x00000100U)         /* !< output enabled */
/* LFSS_TOE15_12[TIO14] Bits */
#define LFSS_TOE15_12_TIO14_OFS                  (16)                            /* !< TIO14 Offset */
#define LFSS_TOE15_12_TIO14_MASK                 ((uint32_t)0x00010000U)         /* !< Enables data output for tamper I/O
                                                                                    14 */
#define LFSS_TOE15_12_TIO14_DISABLE              ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE15_12_TIO14_ENABLE               ((uint32_t)0x00010000U)         /* !< output enabled */
/* LFSS_TOE15_12[TIO15] Bits */
#define LFSS_TOE15_12_TIO15_OFS                  (24)                            /* !< TIO15 Offset */
#define LFSS_TOE15_12_TIO15_MASK                 ((uint32_t)0x01000000U)         /* !< Enables data output for tamper I/O
                                                                                    15 */
#define LFSS_TOE15_12_TIO15_DISABLE              ((uint32_t)0x00000000U)         /* !< output disabled */
#define LFSS_TOE15_12_TIO15_ENABLE               ((uint32_t)0x01000000U)         /* !< output enabled */

/* LFSS_TIN3_0 Bits */
/* LFSS_TIN3_0[TIO0] Bits */
#define LFSS_TIN3_0_TIO0_OFS                     (0)                             /* !< TIO0 Offset */
#define LFSS_TIN3_0_TIO0_MASK                    ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 0. */
#define LFSS_TIN3_0_TIO0_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN3_0_TIO0_ONE                     ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* LFSS_TIN3_0[TIO1] Bits */
#define LFSS_TIN3_0_TIO1_OFS                     (8)                             /* !< TIO1 Offset */
#define LFSS_TIN3_0_TIO1_MASK                    ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 1. */
#define LFSS_TIN3_0_TIO1_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN3_0_TIO1_ONE                     ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* LFSS_TIN3_0[TIO2] Bits */
#define LFSS_TIN3_0_TIO2_OFS                     (16)                            /* !< TIO2 Offset */
#define LFSS_TIN3_0_TIO2_MASK                    ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 2. */
#define LFSS_TIN3_0_TIO2_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN3_0_TIO2_ONE                     ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* LFSS_TIN3_0[TIO3] Bits */
#define LFSS_TIN3_0_TIO3_OFS                     (24)                            /* !< TIO3 Offset */
#define LFSS_TIN3_0_TIO3_MASK                    ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 3. */
#define LFSS_TIN3_0_TIO3_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN3_0_TIO3_ONE                     ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* LFSS_TIN7_4 Bits */
/* LFSS_TIN7_4[TIO4] Bits */
#define LFSS_TIN7_4_TIO4_OFS                     (0)                             /* !< TIO4 Offset */
#define LFSS_TIN7_4_TIO4_MASK                    ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 4. */
#define LFSS_TIN7_4_TIO4_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN7_4_TIO4_ONE                     ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* LFSS_TIN7_4[TIO5] Bits */
#define LFSS_TIN7_4_TIO5_OFS                     (8)                             /* !< TIO5 Offset */
#define LFSS_TIN7_4_TIO5_MASK                    ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 5. */
#define LFSS_TIN7_4_TIO5_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN7_4_TIO5_ONE                     ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* LFSS_TIN7_4[TIO6] Bits */
#define LFSS_TIN7_4_TIO6_OFS                     (16)                            /* !< TIO6 Offset */
#define LFSS_TIN7_4_TIO6_MASK                    ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 6. */
#define LFSS_TIN7_4_TIO6_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN7_4_TIO6_ONE                     ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* LFSS_TIN7_4[TIO7] Bits */
#define LFSS_TIN7_4_TIO7_OFS                     (24)                            /* !< TIO7 Offset */
#define LFSS_TIN7_4_TIO7_MASK                    ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 7. */
#define LFSS_TIN7_4_TIO7_ZERO                    ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN7_4_TIO7_ONE                     ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* LFSS_TIN11_8 Bits */
/* LFSS_TIN11_8[TIO8] Bits */
#define LFSS_TIN11_8_TIO8_OFS                    (0)                             /* !< TIO8 Offset */
#define LFSS_TIN11_8_TIO8_MASK                   ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 8. */
#define LFSS_TIN11_8_TIO8_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN11_8_TIO8_ONE                    ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* LFSS_TIN11_8[TIO9] Bits */
#define LFSS_TIN11_8_TIO9_OFS                    (8)                             /* !< TIO9 Offset */
#define LFSS_TIN11_8_TIO9_MASK                   ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 9. */
#define LFSS_TIN11_8_TIO9_ZERO                   ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN11_8_TIO9_ONE                    ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* LFSS_TIN11_8[TIO10] Bits */
#define LFSS_TIN11_8_TIO10_OFS                   (16)                            /* !< TIO10 Offset */
#define LFSS_TIN11_8_TIO10_MASK                  ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 10. */
#define LFSS_TIN11_8_TIO10_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN11_8_TIO10_ONE                   ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* LFSS_TIN11_8[TIO11] Bits */
#define LFSS_TIN11_8_TIO11_OFS                   (24)                            /* !< TIO11 Offset */
#define LFSS_TIN11_8_TIO11_MASK                  ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 11. */
#define LFSS_TIN11_8_TIO11_ZERO                  ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN11_8_TIO11_ONE                   ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* LFSS_TIN15_12 Bits */
/* LFSS_TIN15_12[TIO12] Bits */
#define LFSS_TIN15_12_TIO12_OFS                  (0)                             /* !< TIO12 Offset */
#define LFSS_TIN15_12_TIO12_MASK                 ((uint32_t)0x00000001U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 12. */
#define LFSS_TIN15_12_TIO12_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN15_12_TIO12_ONE                  ((uint32_t)0x00000001U)         /* !< Input value is 1 */
/* LFSS_TIN15_12[TIO13] Bits */
#define LFSS_TIN15_12_TIO13_OFS                  (8)                             /* !< TIO13 Offset */
#define LFSS_TIN15_12_TIO13_MASK                 ((uint32_t)0x00000100U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 13. */
#define LFSS_TIN15_12_TIO13_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN15_12_TIO13_ONE                  ((uint32_t)0x00000100U)         /* !< Input value is 1 */
/* LFSS_TIN15_12[TIO14] Bits */
#define LFSS_TIN15_12_TIO14_OFS                  (16)                            /* !< TIO14 Offset */
#define LFSS_TIN15_12_TIO14_MASK                 ((uint32_t)0x00010000U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 14. */
#define LFSS_TIN15_12_TIO14_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN15_12_TIO14_ONE                  ((uint32_t)0x00010000U)         /* !< Input value is 1 */
/* LFSS_TIN15_12[TIO15] Bits */
#define LFSS_TIN15_12_TIO15_OFS                  (24)                            /* !< TIO15 Offset */
#define LFSS_TIN15_12_TIO15_MASK                 ((uint32_t)0x01000000U)         /* !< This bit reads the data input value
                                                                                    of tamper I/O 15. */
#define LFSS_TIN15_12_TIO15_ZERO                 ((uint32_t)0x00000000U)         /* !< Input value is 0 */
#define LFSS_TIN15_12_TIO15_ONE                  ((uint32_t)0x01000000U)         /* !< Input value is 1 */

/* LFSS_HEARTBEAT Bits */
/* LFSS_HEARTBEAT[HBINTERVAL] Bits */
#define LFSS_HEARTBEAT_HBINTERVAL_OFS            (0)                             /* !< HBINTERVAL Offset */
#define LFSS_HEARTBEAT_HBINTERVAL_MASK           ((uint32_t)0x00000007U)         /* !< Heart beat interval */
#define LFSS_HEARTBEAT_HBINTERVAL_HBINT0P125     ((uint32_t)0x00000000U)         /* !< Heart beat interval 0.125 sec */
#define LFSS_HEARTBEAT_HBINTERVAL_HBINT0P25      ((uint32_t)0x00000001U)         /* !< Heart beat interval 0.25 sec */
#define LFSS_HEARTBEAT_HBINTERVAL_HBINT0P5       ((uint32_t)0x00000002U)         /* !< Heart beat interval 0.5 sec */
#define LFSS_HEARTBEAT_HBINTERVAL_HBINT1         ((uint32_t)0x00000003U)         /* !< Heart beat interval 1 sec */
#define LFSS_HEARTBEAT_HBINTERVAL_HBINT2         ((uint32_t)0x00000004U)         /* !< Heart beat interval 2 sec */
#define LFSS_HEARTBEAT_HBINTERVAL_HBINT4         ((uint32_t)0x00000005U)         /* !< Heart beat interval 4 sec */
#define LFSS_HEARTBEAT_HBINTERVAL_HBINT8         ((uint32_t)0x00000006U)         /* !< Heart beat interval 8 sec */
#define LFSS_HEARTBEAT_HBINTERVAL_HBINT16        ((uint32_t)0x00000007U)         /* !< Heart beat interval 16 sec */
/* LFSS_HEARTBEAT[HBWIDTH] Bits */
#define LFSS_HEARTBEAT_HBWIDTH_OFS               (8)                             /* !< HBWIDTH Offset */
#define LFSS_HEARTBEAT_HBWIDTH_MASK              ((uint32_t)0x00000700U)         /* !< Heart beat interval width */
#define LFSS_HEARTBEAT_HBWIDTH_HBPWDTH1          ((uint32_t)0x00000000U)         /* !< Heart beat pulse width 1 msec */
#define LFSS_HEARTBEAT_HBWIDTH_HBPWDTH2          ((uint32_t)0x00000100U)         /* !< Heart beat pulse width 2 msec */
#define LFSS_HEARTBEAT_HBWIDTH_HBPWDTH4          ((uint32_t)0x00000200U)         /* !< Heart beat pulse width 4 msec */
#define LFSS_HEARTBEAT_HBWIDTH_HBPWDTH8          ((uint32_t)0x00000300U)         /* !< Heart beat pulse width 8 msec */
#define LFSS_HEARTBEAT_HBWIDTH_HBPWDTH16         ((uint32_t)0x00000400U)         /* !< Heart beat pulse width 16 msec */
#define LFSS_HEARTBEAT_HBWIDTH_HBPWDTH32         ((uint32_t)0x00000500U)         /* !< Heart beat pulse width 32 msec */
#define LFSS_HEARTBEAT_HBWIDTH_HBPWDTH64         ((uint32_t)0x00000600U)         /* !< Heart beat pulse width 64 msec */
#define LFSS_HEARTBEAT_HBWIDTH_HBPWDTH128        ((uint32_t)0x00000700U)         /* !< Heart beat pulse width 128 msec */
/* LFSS_HEARTBEAT[HBMODE] Bits */
#define LFSS_HEARTBEAT_HBMODE_OFS                (16)                            /* !< HBMODE Offset */
#define LFSS_HEARTBEAT_HBMODE_MASK               ((uint32_t)0x00030000U)         /* !< Heart beat mode */
#define LFSS_HEARTBEAT_HBMODE_HB_DIS             ((uint32_t)0x00000000U)         /* !< Heart beat disabled */
#define LFSS_HEARTBEAT_HBMODE_HB_ALLWAYS         ((uint32_t)0x00010000U)         /* !< Heart beat allways enabled */
#define LFSS_HEARTBEAT_HBMODE_HB_TS              ((uint32_t)0x00020000U)         /* !< Heart beat enabled when time stamp
                                                                                    event detected */
#define LFSS_HEARTBEAT_HBMODE_HB_VDDFAIL         ((uint32_t)0x00030000U)         /* !< Heart beat when VDD has fail
                                                                                    condition */

/* LFSS_TIOLOCK Bits */
/* LFSS_TIOLOCK[PROTECT] Bits */
#define LFSS_TIOLOCK_PROTECT_OFS                 (0)                             /* !< PROTECT Offset */
#define LFSS_TIOLOCK_PROTECT_MASK                ((uint32_t)0x00000001U)         /* !< If set, the register bit will
                                                                                    protect the TIOCTL and HEARTBEAT from
                                                                                    accidental writes. */
#define LFSS_TIOLOCK_PROTECT_CLR                 ((uint32_t)0x00000000U)         /* !< Tamper I/O control is writable. */
#define LFSS_TIOLOCK_PROTECT_SET                 ((uint32_t)0x00000001U)         /* !< Tamper I/O control is read only
                                                                                    access. */
/* LFSS_TIOLOCK[KEY] Bits */
#define LFSS_TIOLOCK_KEY_OFS                     (24)                            /* !< KEY Offset */
#define LFSS_TIOLOCK_KEY_MASK                    ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0x18) to update
                                                                                    this register */
#define LFSS_TIOLOCK_KEY_UNLOCK_W                ((uint32_t)0x18000000U)         /* !< This field must be written with
                                                                                    0x18 to be able to clear any of the
                                                                                    enable bits */

/* LFSS_CLKCTL Bits */
/* LFSS_CLKCTL[MODCLKEN] Bits */
#define LFSS_CLKCTL_MODCLKEN_OFS                 (31)                            /* !< MODCLKEN Offset */
#define LFSS_CLKCTL_MODCLKEN_MASK                ((uint32_t)0x80000000U)         /* !< This bit enables the supply of the
                                                                                    32kHz clock to the RTC. It will not
                                                                                    power-up the 32kHz crystal oscillator
                                                                                    this needs to be done in the Clock
                                                                                    System Module. */
#define LFSS_CLKCTL_MODCLKEN_DISABLE             ((uint32_t)0x00000000U)         /* !< 32kHz clock is not supplied to the
                                                                                    RTC. */
#define LFSS_CLKCTL_MODCLKEN_ENABLE              ((uint32_t)0x80000000U)         /* !< 32kHz clock is supplied to the RTC. */

/* LFSS_DBGCTL Bits */
/* LFSS_DBGCTL[DBGRUN] Bits */
#define LFSS_DBGCTL_DBGRUN_OFS                   (0)                             /* !< DBGRUN Offset */
#define LFSS_DBGCTL_DBGRUN_MASK                  ((uint32_t)0x00000001U)         /* !< Debug Run. */
#define LFSS_DBGCTL_DBGRUN_HALT                  ((uint32_t)0x00000000U)         /* !< Counter is halted if CPU is in
                                                                                    debug state. */
#define LFSS_DBGCTL_DBGRUN_RUN                   ((uint32_t)0x00000001U)         /* !< Continue to operate normally
                                                                                    ignoring the debug state of the CPU. */
/* LFSS_DBGCTL[DBGINT] Bits */
#define LFSS_DBGCTL_DBGINT_OFS                   (1)                             /* !< DBGINT Offset */
#define LFSS_DBGCTL_DBGINT_MASK                  ((uint32_t)0x00000002U)         /* !< Debug Interrupt Enable. */
#define LFSS_DBGCTL_DBGINT_OFF                   ((uint32_t)0x00000000U)         /* !< Interrupts of the module will not
                                                                                    be captured anymore if CPU is in
                                                                                    debug state. Which means no update to
                                                                                    the RTCRIS, RTCMISC and RTCIIDX
                                                                                    register. */
#define LFSS_DBGCTL_DBGINT_ON                    ((uint32_t)0x00000002U)         /* !< Interrupts are enabled in debug
                                                                                    mode. Interrupt requests are signaled
                                                                                    to the interrupt controller. If the
                                                                                    flags are required by software
                                                                                    (polling mode) the DGBINT bit need to
                                                                                    be set to 1. */

/* LFSS_CTL Bits */
/* LFSS_CTL[RTCTEVTX] Bits */
#define LFSS_CTL_RTCTEVTX_OFS                    (0)                             /* !< RTCTEVTX Offset */
#define LFSS_CTL_RTCTEVTX_MASK                   ((uint32_t)0x00000003U)         /* !< Real-time clock time event 0x0 =
                                                                                    Minute changed 0x1 = Hour changed 0x2
                                                                                    = Every day at midnight (00:00) 0x3 =
                                                                                    Every day at noon (12:00) */
#define LFSS_CTL_RTCTEVTX_MINUTE                 ((uint32_t)0x00000000U)         /* !< Generate RTC event every minute. */
#define LFSS_CTL_RTCTEVTX_HOUR                   ((uint32_t)0x00000001U)         /* !< Generate RTC event every hour. */
#define LFSS_CTL_RTCTEVTX_MIDNIGHT               ((uint32_t)0x00000002U)         /* !< Generate RTC event at midnight. */
#define LFSS_CTL_RTCTEVTX_NOON                   ((uint32_t)0x00000003U)         /* !< Generate RTC event at noon. */
/* LFSS_CTL[RTCBCD] Bits */
#define LFSS_CTL_RTCBCD_OFS                      (7)                             /* !< RTCBCD Offset */
#define LFSS_CTL_RTCBCD_MASK                     ((uint32_t)0x00000080U)         /* !< Real-time clock BCD select. Selects
                                                                                    BCD counting for real-time clock. */
#define LFSS_CTL_RTCBCD_BINARY                   ((uint32_t)0x00000000U)         /* !< Binary code selected */
#define LFSS_CTL_RTCBCD_BCD                      ((uint32_t)0x00000080U)         /* !< Binary coded decimal (BCD) code
                                                                                    selected */

/* LFSS_STA Bits */
/* LFSS_STA[RTCRDY] Bits */
#define LFSS_STA_RTCRDY_OFS                      (0)                             /* !< RTCRDY Offset */
#define LFSS_STA_RTCRDY_MASK                     ((uint32_t)0x00000001U)         /* !< Real-time clock ready. This bit
                                                                                    indicates when the real-time clock
                                                                                    time values are safe for reading. */
#define LFSS_STA_RTCRDY_NOT_READY                ((uint32_t)0x00000000U)         /* !< RTC time values in transition */
#define LFSS_STA_RTCRDY_READY                    ((uint32_t)0x00000001U)         /* !< RTC time values safe for reading. */
/* LFSS_STA[RTCTCRDY] Bits */
#define LFSS_STA_RTCTCRDY_OFS                    (1)                             /* !< RTCTCRDY Offset */
#define LFSS_STA_RTCTCRDY_MASK                   ((uint32_t)0x00000002U)         /* !< Real-time clock temperature
                                                                                    compensation ready. This is a read
                                                                                    only bit that indicates when the
                                                                                    RTCTCMPx can be written. Write to
                                                                                    RTCTCMPx should be avoided when
                                                                                    RTCTCRDY is reset. */
#define LFSS_STA_RTCTCRDY_NOT_READY              ((uint32_t)0x00000000U)         /* !< RTC temperature compensation in
                                                                                    transition */
#define LFSS_STA_RTCTCRDY_READY                  ((uint32_t)0x00000002U)         /* !< RTC temperature compensation ready */
/* LFSS_STA[RTCTCOK] Bits */
#define LFSS_STA_RTCTCOK_OFS                     (2)                             /* !< RTCTCOK Offset */
#define LFSS_STA_RTCTCOK_MASK                    ((uint32_t)0x00000004U)         /* !< Real-time clock temperature
                                                                                    compensation write OK. This is a
                                                                                    read-only bit that indicates if the
                                                                                    write to RTCTCMP is successful or
                                                                                    not. */
#define LFSS_STA_RTCTCOK_NOT_OK                  ((uint32_t)0x00000000U)         /* !< Write to RTCTCMPx is unsuccessful */
#define LFSS_STA_RTCTCOK_OK                      ((uint32_t)0x00000004U)         /* !< Write to RTCTCMPx is successful */

/* LFSS_CAL Bits */
/* LFSS_CAL[RTCOCALX] Bits */
#define LFSS_CAL_RTCOCALX_OFS                    (0)                             /* !< RTCOCALX Offset */
#define LFSS_CAL_RTCOCALX_MASK                   ((uint32_t)0x000000FFU)         /* !< Real-time clock offset error
                                                                                    calibration. Each LSB represents
                                                                                    approximately +1ppm (RTCOCALXS = 1)
                                                                                    or -1ppm (RTCOCALXS = 0) adjustment
                                                                                    in frequency. Maximum effective
                                                                                    calibration value is +/-240ppm.
                                                                                    Excess values written above +/-240ppm
                                                                                    will be ignored by hardware. */
#define LFSS_CAL_RTCOCALX_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_CAL_RTCOCALX_MAXIMUM                ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* LFSS_CAL[RTCOCALS] Bits */
#define LFSS_CAL_RTCOCALS_OFS                    (15)                            /* !< RTCOCALS Offset */
#define LFSS_CAL_RTCOCALS_MASK                   ((uint32_t)0x00008000U)         /* !< Real-time clock offset error
                                                                                    calibration sign. This bit decides
                                                                                    the sign of offset error calibration. */
#define LFSS_CAL_RTCOCALS_DOWN                   ((uint32_t)0x00000000U)         /* !< Down calibration. Frequency
                                                                                    adjusted down. */
#define LFSS_CAL_RTCOCALS_UP                     ((uint32_t)0x00008000U)         /* !< Up calibration. Frequency adjusted
                                                                                    up. */
/* LFSS_CAL[RTCCALFX] Bits */
#define LFSS_CAL_RTCCALFX_OFS                    (16)                            /* !< RTCCALFX Offset */
#define LFSS_CAL_RTCCALFX_MASK                   ((uint32_t)0x00030000U)         /* !< Real-time clock calibration
                                                                                    frequency. Selects frequency output
                                                                                    to RTCCLK pin for calibration
                                                                                    measurement. The corresponding port
                                                                                    must be configured for the peripheral
                                                                                    module function. */
#define LFSS_CAL_RTCCALFX_F32KHZ                 ((uint32_t)0x00000000U)         /* !< 32 kHz */
#define LFSS_CAL_RTCCALFX_F512HZ                 ((uint32_t)0x00010000U)         /* !< 512 Hz */
#define LFSS_CAL_RTCCALFX_F256HZ                 ((uint32_t)0x00020000U)         /* !< 256 Hz */
#define LFSS_CAL_RTCCALFX_F1HZ                   ((uint32_t)0x00030000U)         /* !< 1 Hz */

/* LFSS_TCMP Bits */
/* LFSS_TCMP[RTCTCMPX] Bits */
#define LFSS_TCMP_RTCTCMPX_OFS                   (0)                             /* !< RTCTCMPX Offset */
#define LFSS_TCMP_RTCTCMPX_MASK                  ((uint32_t)0x000000FFU)         /* !< Real-time clock temperature
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
#define LFSS_TCMP_RTCTCMPX_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TCMP_RTCTCMPX_MAXIMUM               ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* LFSS_TCMP[RTCTCMPS] Bits */
#define LFSS_TCMP_RTCTCMPS_OFS                   (15)                            /* !< RTCTCMPS Offset */
#define LFSS_TCMP_RTCTCMPS_MASK                  ((uint32_t)0x00008000U)         /* !< Real-time clock temperature
                                                                                    compensation sign. This bit decides
                                                                                    the sign of temperature compensation. */
#define LFSS_TCMP_RTCTCMPS_DOWN                  ((uint32_t)0x00000000U)         /* !< Down calibration. Frequency
                                                                                    adjusted down. */
#define LFSS_TCMP_RTCTCMPS_UP                    ((uint32_t)0x00008000U)         /* !< Up calibration. Frequency adjusted
                                                                                    up. */

/* LFSS_SEC Bits */
/* LFSS_SEC[SECBIN] Bits */
#define LFSS_SEC_SECBIN_OFS                      (0)                             /* !< SECBIN Offset */
#define LFSS_SEC_SECBIN_MASK                     ((uint32_t)0x0000003FU)         /* !< Seconds Binary (0 to 59). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_SEC_SECBIN_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_SEC_SECBIN_MAXIMUM                  ((uint32_t)0x0000003BU)         /* !< Highest possible value */
/* LFSS_SEC[SECLOWBCD] Bits */
#define LFSS_SEC_SECLOWBCD_OFS                   (8)                             /* !< SECLOWBCD Offset */
#define LFSS_SEC_SECLOWBCD_MASK                  ((uint32_t)0x00000F00U)         /* !< Seconds BCD  low digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_SEC_SECLOWBCD_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_SEC_SECLOWBCD_MAXIMUM               ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_SEC[SECHIGHBCD] Bits */
#define LFSS_SEC_SECHIGHBCD_OFS                  (12)                            /* !< SECHIGHBCD Offset */
#define LFSS_SEC_SECHIGHBCD_MASK                 ((uint32_t)0x00007000U)         /* !< Seconds BCD  high digit (0 to 5).
                                                                                    If RTCBCD=0 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define LFSS_SEC_SECHIGHBCD_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_SEC_SECHIGHBCD_MAXIMUM              ((uint32_t)0x00005000U)         /* !< Highest possible value */

/* LFSS_MIN Bits */
/* LFSS_MIN[MINBIN] Bits */
#define LFSS_MIN_MINBIN_OFS                      (0)                             /* !< MINBIN Offset */
#define LFSS_MIN_MINBIN_MASK                     ((uint32_t)0x0000003FU)         /* !< Minutes Binary (0 to 59). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_MIN_MINBIN_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_MIN_MINBIN_MAXIMUM                  ((uint32_t)0x0000003BU)         /* !< Highest possible value */
/* LFSS_MIN[MINLOWBCD] Bits */
#define LFSS_MIN_MINLOWBCD_OFS                   (8)                             /* !< MINLOWBCD Offset */
#define LFSS_MIN_MINLOWBCD_MASK                  ((uint32_t)0x00000F00U)         /* !< Minutes BCD  low digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_MIN_MINLOWBCD_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_MIN_MINLOWBCD_MAXIMUM               ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_MIN[MINHIGHBCD] Bits */
#define LFSS_MIN_MINHIGHBCD_OFS                  (12)                            /* !< MINHIGHBCD Offset */
#define LFSS_MIN_MINHIGHBCD_MASK                 ((uint32_t)0x00007000U)         /* !< Minutes BCD  high digit (0 to 5).
                                                                                    If RTCBCD=0 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define LFSS_MIN_MINHIGHBCD_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_MIN_MINHIGHBCD_MAXIMUM              ((uint32_t)0x00005000U)         /* !< Highest possible value */

/* LFSS_HOUR Bits */
/* LFSS_HOUR[HOURBIN] Bits */
#define LFSS_HOUR_HOURBIN_OFS                    (0)                             /* !< HOURBIN Offset */
#define LFSS_HOUR_HOURBIN_MASK                   ((uint32_t)0x0000001FU)         /* !< Hours Binary (0 to 23). If RTCBCD=1
                                                                                    write to these bits will be ignored
                                                                                    and read give the value 0. */
#define LFSS_HOUR_HOURBIN_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_HOUR_HOURBIN_MAXIMUM                ((uint32_t)0x00000017U)         /* !< Highest possible value */
/* LFSS_HOUR[HOURLOWBCD] Bits */
#define LFSS_HOUR_HOURLOWBCD_OFS                 (8)                             /* !< HOURLOWBCD Offset */
#define LFSS_HOUR_HOURLOWBCD_MASK                ((uint32_t)0x00000F00U)         /* !< Hours BCD  low digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_HOUR_HOURLOWBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_HOUR_HOURLOWBCD_MAXIMUM             ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_HOUR[HOURHIGHBCD] Bits */
#define LFSS_HOUR_HOURHIGHBCD_OFS                (12)                            /* !< HOURHIGHBCD Offset */
#define LFSS_HOUR_HOURHIGHBCD_MASK               ((uint32_t)0x00003000U)         /* !< Hours BCD  high digit (0 to 2). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_HOUR_HOURHIGHBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_HOUR_HOURHIGHBCD_MAXIMUM            ((uint32_t)0x00002000U)         /* !< Highest possible value */

/* LFSS_DAY Bits */
/* LFSS_DAY[DOW] Bits */
#define LFSS_DAY_DOW_OFS                         (0)                             /* !< DOW Offset */
#define LFSS_DAY_DOW_MASK                        ((uint32_t)0x00000007U)         /* !< Day of week (0 to 6). These bits
                                                                                    are valid if RTCBCD=1 or RTCBCD=0. */
#define LFSS_DAY_DOW_MINIMUM                     ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_DAY_DOW_MAXIMUM                     ((uint32_t)0x00000006U)         /* !< Highest possible value */
/* LFSS_DAY[DOMBIN] Bits */
#define LFSS_DAY_DOMBIN_OFS                      (8)                             /* !< DOMBIN Offset */
#define LFSS_DAY_DOMBIN_MASK                     ((uint32_t)0x00001F00U)         /* !< Day of month Binary (1 to 28, 29,
                                                                                    30, 31). If RTCBCD=1 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_DAY_DOMBIN_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_DAY_DOMBIN_MAXIMUM                  ((uint32_t)0x00001F00U)         /* !< Highest possible value */
/* LFSS_DAY[DOMLOWBCD] Bits */
#define LFSS_DAY_DOMLOWBCD_OFS                   (16)                            /* !< DOMLOWBCD Offset */
#define LFSS_DAY_DOMLOWBCD_MASK                  ((uint32_t)0x000F0000U)         /* !< Day of month BCD  low digit (0 to
                                                                                    9). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define LFSS_DAY_DOMLOWBCD_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_DAY_DOMLOWBCD_MAXIMUM               ((uint32_t)0x00090000U)         /* !< Highest possible value */
/* LFSS_DAY[DOMHIGHBCD] Bits */
#define LFSS_DAY_DOMHIGHBCD_OFS                  (20)                            /* !< DOMHIGHBCD Offset */
#define LFSS_DAY_DOMHIGHBCD_MASK                 ((uint32_t)0x00300000U)         /* !< Day of month BCD  high digit (0 to
                                                                                    3). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define LFSS_DAY_DOMHIGHBCD_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_DAY_DOMHIGHBCD_MAXIMUM              ((uint32_t)0x00300000U)         /* !< Highest possible value */

/* LFSS_MON Bits */
/* LFSS_MON[MONBIN] Bits */
#define LFSS_MON_MONBIN_OFS                      (0)                             /* !< MONBIN Offset */
#define LFSS_MON_MONBIN_MASK                     ((uint32_t)0x0000000FU)         /* !< Month Binary (1 to 12). If RTCBCD=1
                                                                                    write to these bits will be ignored
                                                                                    and read give the value 0. */
#define LFSS_MON_MONBIN_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_MON_MONBIN_MAXIMUM                  ((uint32_t)0x0000000CU)         /* !< Highest possible value */
/* LFSS_MON[MONLOWBCD] Bits */
#define LFSS_MON_MONLOWBCD_OFS                   (8)                             /* !< MONLOWBCD Offset */
#define LFSS_MON_MONLOWBCD_MASK                  ((uint32_t)0x00000F00U)         /* !< Month BCD  low digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_MON_MONLOWBCD_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_MON_MONLOWBCD_MAXIMUM               ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_MON[MONHIGHBCD] Bits */
#define LFSS_MON_MONHIGHBCD_OFS                  (12)                            /* !< MONHIGHBCD Offset */
#define LFSS_MON_MONHIGHBCD_MASK                 ((uint32_t)0x00001000U)         /* !< Month BCD  high digit (0 or 1). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_MON_MONHIGHBCD_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_MON_MONHIGHBCD_MAXIMUM              ((uint32_t)0x00001000U)         /* !< Highest possible value */

/* LFSS_YEAR Bits */
/* LFSS_YEAR[YEARLOWBIN] Bits */
#define LFSS_YEAR_YEARLOWBIN_OFS                 (0)                             /* !< YEARLOWBIN Offset */
#define LFSS_YEAR_YEARLOWBIN_MASK                ((uint32_t)0x000000FFU)         /* !< Year Binary  low byte. Valid values
                                                                                    for Year are 0 to 4095. If RTCBCD=1
                                                                                    write to these bits will be ignored
                                                                                    and read give the value 0. */
#define LFSS_YEAR_YEARLOWBIN_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_YEAR_YEARLOWBIN_MAXIMUM             ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* LFSS_YEAR[YEARHIGHBIN] Bits */
#define LFSS_YEAR_YEARHIGHBIN_OFS                (8)                             /* !< YEARHIGHBIN Offset */
#define LFSS_YEAR_YEARHIGHBIN_MASK               ((uint32_t)0x00000F00U)         /* !< Year Binary  high byte. Valid
                                                                                    values for Year are 0 to 4095. If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_YEAR_YEARHIGHBIN_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_YEAR_YEARHIGHBIN_MAXIMUM            ((uint32_t)0x00000F00U)         /* !< Highest possible value */
/* LFSS_YEAR[YEARLOWESTBCD] Bits */
#define LFSS_YEAR_YEARLOWESTBCD_OFS              (16)                            /* !< YEARLOWESTBCD Offset */
#define LFSS_YEAR_YEARLOWESTBCD_MASK             ((uint32_t)0x000F0000U)         /* !< Year BCD  lowest digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_YEAR_YEARLOWESTBCD_MINIMUM          ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_YEAR_YEARLOWESTBCD_MAXIMUM          ((uint32_t)0x00090000U)         /* !< Highest possible value */
/* LFSS_YEAR[DECADEBCD] Bits */
#define LFSS_YEAR_DECADEBCD_OFS                  (20)                            /* !< DECADEBCD Offset */
#define LFSS_YEAR_DECADEBCD_MASK                 ((uint32_t)0x00F00000U)         /* !< Decade BCD (0 to 9). If RTCBCD=0
                                                                                    write to these bits will be ignored
                                                                                    and read give the value 0. */
#define LFSS_YEAR_DECADEBCD_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_YEAR_DECADEBCD_MAXIMUM              ((uint32_t)0x00900000U)         /* !< Highest possible value */
/* LFSS_YEAR[CENTLOWBCD] Bits */
#define LFSS_YEAR_CENTLOWBCD_OFS                 (24)                            /* !< CENTLOWBCD Offset */
#define LFSS_YEAR_CENTLOWBCD_MASK                ((uint32_t)0x0F000000U)         /* !< Century BCD  low digit (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_YEAR_CENTLOWBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_YEAR_CENTLOWBCD_MAXIMUM             ((uint32_t)0x09000000U)         /* !< Highest possible value */
/* LFSS_YEAR[CENTHIGHBCD] Bits */
#define LFSS_YEAR_CENTHIGHBCD_OFS                (28)                            /* !< CENTHIGHBCD Offset */
#define LFSS_YEAR_CENTHIGHBCD_MASK               ((uint32_t)0x70000000U)         /* !< Century BCD  high digit (0 to 4).
                                                                                    If RTCBCD=0 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define LFSS_YEAR_CENTHIGHBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_YEAR_CENTHIGHBCD_MAXIMUM            ((uint32_t)0x40000000U)         /* !< Highest possible value */

/* LFSS_A1MIN Bits */
/* LFSS_A1MIN[AMINBIN] Bits */
#define LFSS_A1MIN_AMINBIN_OFS                   (0)                             /* !< AMINBIN Offset */
#define LFSS_A1MIN_AMINBIN_MASK                  ((uint32_t)0x0000003FU)         /* !< Alarm Minutes Binary (0 to 59). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_A1MIN_AMINBIN_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A1MIN_AMINBIN_MAXIMUM               ((uint32_t)0x0000003BU)         /* !< Highest possible value */
/* LFSS_A1MIN[AMINAEBIN] Bits */
#define LFSS_A1MIN_AMINAEBIN_OFS                 (7)                             /* !< AMINAEBIN Offset */
#define LFSS_A1MIN_AMINAEBIN_MASK                ((uint32_t)0x00000080U)         /* !< Alarm Minutes Binary enable. If
                                                                                    RTCBCD=1 this bit is always 0. Write
                                                                                    to this bit will be ignored.   0x0=
                                                                                    Alarm disabled.   0x1= Alarm enabled. */
#define LFSS_A1MIN_AMINAEBIN_DISABLE             ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A1MIN_AMINAEBIN_ENABLE              ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* LFSS_A1MIN[AMINLOWBCD] Bits */
#define LFSS_A1MIN_AMINLOWBCD_OFS                (8)                             /* !< AMINLOWBCD Offset */
#define LFSS_A1MIN_AMINLOWBCD_MASK               ((uint32_t)0x00000F00U)         /* !< Alarm Minutes BCD  low digit (0 to
                                                                                    9). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define LFSS_A1MIN_AMINLOWBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A1MIN_AMINLOWBCD_MAXIMUM            ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_A1MIN[AMINHIGHBCD] Bits */
#define LFSS_A1MIN_AMINHIGHBCD_OFS               (12)                            /* !< AMINHIGHBCD Offset */
#define LFSS_A1MIN_AMINHIGHBCD_MASK              ((uint32_t)0x00007000U)         /* !< Alarm Minutes BCD  high digit (0 to
                                                                                    5). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define LFSS_A1MIN_AMINHIGHBCD_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A1MIN_AMINHIGHBCD_MAXIMUM           ((uint32_t)0x00005000U)         /* !< Highest possible value */
/* LFSS_A1MIN[AMINAEBCD] Bits */
#define LFSS_A1MIN_AMINAEBCD_OFS                 (15)                            /* !< AMINAEBCD Offset */
#define LFSS_A1MIN_AMINAEBCD_MASK                ((uint32_t)0x00008000U)         /* !< Alarm Minutes BCD enable. If
                                                                                    RTCBCD=0 this bit is always 0. Write
                                                                                    to this bit will be ignored.   0x0=
                                                                                    Alarm disabled.   0x1= Alarm enabled. */
#define LFSS_A1MIN_AMINAEBCD_DISABLE             ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A1MIN_AMINAEBCD_ENABLE              ((uint32_t)0x00008000U)         /* !< Alarm enabled */

/* LFSS_A1HOUR Bits */
/* LFSS_A1HOUR[AHOURBIN] Bits */
#define LFSS_A1HOUR_AHOURBIN_OFS                 (0)                             /* !< AHOURBIN Offset */
#define LFSS_A1HOUR_AHOURBIN_MASK                ((uint32_t)0x0000001FU)         /* !< Alarm Hours Binary (0 to 23). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_A1HOUR_AHOURBIN_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A1HOUR_AHOURBIN_MAXIMUM             ((uint32_t)0x00000017U)         /* !< Highest possible value */
/* LFSS_A1HOUR[AHOURAEBIN] Bits */
#define LFSS_A1HOUR_AHOURAEBIN_OFS               (7)                             /* !< AHOURAEBIN Offset */
#define LFSS_A1HOUR_AHOURAEBIN_MASK              ((uint32_t)0x00000080U)         /* !< Alarm Hours Binary enable. If
                                                                                    RTCBCD=1 this bit is always 0. Write
                                                                                    to this bit will be ignored.   0x0=
                                                                                    Alarm disabled.   0x1= Alarm enabled. */
#define LFSS_A1HOUR_AHOURAEBIN_DISABLE           ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A1HOUR_AHOURAEBIN_ENABLE            ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* LFSS_A1HOUR[AHOURLOWBCD] Bits */
#define LFSS_A1HOUR_AHOURLOWBCD_OFS              (8)                             /* !< AHOURLOWBCD Offset */
#define LFSS_A1HOUR_AHOURLOWBCD_MASK             ((uint32_t)0x00000F00U)         /* !< Alarm Hours BCD  low digit (0 to
                                                                                    9). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define LFSS_A1HOUR_AHOURLOWBCD_MINIMUM          ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A1HOUR_AHOURLOWBCD_MAXIMUM          ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_A1HOUR[AHOURHIGHBCD] Bits */
#define LFSS_A1HOUR_AHOURHIGHBCD_OFS             (12)                            /* !< AHOURHIGHBCD Offset */
#define LFSS_A1HOUR_AHOURHIGHBCD_MASK            ((uint32_t)0x00003000U)         /* !< Alarm Hours BCD  high digit (0 to
                                                                                    2). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0.. */
#define LFSS_A1HOUR_AHOURHIGHBCD_MINIMUM         ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A1HOUR_AHOURHIGHBCD_MAXIMUM         ((uint32_t)0x00002000U)         /* !< Highest possible value */
/* LFSS_A1HOUR[AHOURAEBCD] Bits */
#define LFSS_A1HOUR_AHOURAEBCD_OFS               (15)                            /* !< AHOURAEBCD Offset */
#define LFSS_A1HOUR_AHOURAEBCD_MASK              ((uint32_t)0x00008000U)         /* !< Alarm Hours BCD enable. If RTCBCD=0
                                                                                    this bit is always 0. Write to this
                                                                                    bit will be ignored.   0x0= Alarm
                                                                                    disabled.   0x1= Alarm enabled. */
#define LFSS_A1HOUR_AHOURAEBCD_DISABLE           ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A1HOUR_AHOURAEBCD_ENABLE            ((uint32_t)0x00008000U)         /* !< Alarm enabled */

/* LFSS_A1DAY Bits */
/* LFSS_A1DAY[ADOW] Bits */
#define LFSS_A1DAY_ADOW_OFS                      (0)                             /* !< ADOW Offset */
#define LFSS_A1DAY_ADOW_MASK                     ((uint32_t)0x00000007U)         /* !< Alarm Day of week (0 to 6). These
                                                                                    bits are valid if RTCBCD=1 or
                                                                                    RTCBCD=0. */
#define LFSS_A1DAY_ADOW_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A1DAY_ADOW_MAXIMUM                  ((uint32_t)0x00000006U)         /* !< Highest possible value */
/* LFSS_A1DAY[ADOWAE] Bits */
#define LFSS_A1DAY_ADOWAE_OFS                    (7)                             /* !< ADOWAE Offset */
#define LFSS_A1DAY_ADOWAE_MASK                   ((uint32_t)0x00000080U)         /* !< Alarm Day of week enable. This bit
                                                                                    are valid if RTCBCD=1 or RTCBCD=0. */
#define LFSS_A1DAY_ADOWAE_DISABLE                ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A1DAY_ADOWAE_ENABLE                 ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* LFSS_A1DAY[ADOMBIN] Bits */
#define LFSS_A1DAY_ADOMBIN_OFS                   (8)                             /* !< ADOMBIN Offset */
#define LFSS_A1DAY_ADOMBIN_MASK                  ((uint32_t)0x00001F00U)         /* !< Alarm Day of month Binary (1 to 28,
                                                                                    29, 30, 31) If RTCBCD=1 write to
                                                                                    these bits will be ignored and read
                                                                                    give the value 0. */
#define LFSS_A1DAY_ADOMBIN_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A1DAY_ADOMBIN_MAXIMUM               ((uint32_t)0x00001F00U)         /* !< Highest possible value */
/* LFSS_A1DAY[ADOMAEBIN] Bits */
#define LFSS_A1DAY_ADOMAEBIN_OFS                 (15)                            /* !< ADOMAEBIN Offset */
#define LFSS_A1DAY_ADOMAEBIN_MASK                ((uint32_t)0x00008000U)         /* !< Alarm Day of month Binary enable.
                                                                                    If RTCBCD=1 this bit is always 0.
                                                                                    Write to this bit will be ignored.
                                                                                    0x0= Alarm disabled.   0x1= Alarm
                                                                                    enabled. */
#define LFSS_A1DAY_ADOMAEBIN_DISABLE             ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A1DAY_ADOMAEBIN_ENABLE              ((uint32_t)0x00008000U)         /* !< Alarm enabled */
/* LFSS_A1DAY[ADOMLOWBCD] Bits */
#define LFSS_A1DAY_ADOMLOWBCD_OFS                (16)                            /* !< ADOMLOWBCD Offset */
#define LFSS_A1DAY_ADOMLOWBCD_MASK               ((uint32_t)0x000F0000U)         /* !< Alarm Day of month BCD  low digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_A1DAY_ADOMLOWBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A1DAY_ADOMLOWBCD_MAXIMUM            ((uint32_t)0x00090000U)         /* !< Highest possible value */
/* LFSS_A1DAY[ADOMHIGHBCD] Bits */
#define LFSS_A1DAY_ADOMHIGHBCD_OFS               (20)                            /* !< ADOMHIGHBCD Offset */
#define LFSS_A1DAY_ADOMHIGHBCD_MASK              ((uint32_t)0x00300000U)         /* !< Alarm Day of month BCD  high digit
                                                                                    (0 to 3). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_A1DAY_ADOMHIGHBCD_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A1DAY_ADOMHIGHBCD_MAXIMUM           ((uint32_t)0x00300000U)         /* !< Highest possible value */
/* LFSS_A1DAY[ADOMAEBCD] Bits */
#define LFSS_A1DAY_ADOMAEBCD_OFS                 (23)                            /* !< ADOMAEBCD Offset */
#define LFSS_A1DAY_ADOMAEBCD_MASK                ((uint32_t)0x00800000U)         /* !< Alarm Day of month BCD enable. If
                                                                                    RTCBCD=0 this bit is always 0. Write
                                                                                    to this bit will be ignored.   0x0=
                                                                                    Alarm disabled.   0x1= Alarm enabled. */
#define LFSS_A1DAY_ADOMAEBCD_DISABLE             ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A1DAY_ADOMAEBCD_ENABLE              ((uint32_t)0x00800000U)         /* !< Alarm enabled */

/* LFSS_A2MIN Bits */
/* LFSS_A2MIN[AMINBIN] Bits */
#define LFSS_A2MIN_AMINBIN_OFS                   (0)                             /* !< AMINBIN Offset */
#define LFSS_A2MIN_AMINBIN_MASK                  ((uint32_t)0x0000003FU)         /* !< Alarm Minutes Binary (0 to 59). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_A2MIN_AMINBIN_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A2MIN_AMINBIN_MAXIMUM               ((uint32_t)0x0000003BU)         /* !< Highest possible value */
/* LFSS_A2MIN[AMINAEBIN] Bits */
#define LFSS_A2MIN_AMINAEBIN_OFS                 (7)                             /* !< AMINAEBIN Offset */
#define LFSS_A2MIN_AMINAEBIN_MASK                ((uint32_t)0x00000080U)         /* !< Alarm Minutes Binary enable. If
                                                                                    RTCBCD=1 this bit is always 0. Write
                                                                                    to this bit will be ignored.   0x0=
                                                                                    Alarm disabled.   0x1= Alarm enabled. */
#define LFSS_A2MIN_AMINAEBIN_DISABLE             ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A2MIN_AMINAEBIN_ENABLE              ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* LFSS_A2MIN[AMINLOWBCD] Bits */
#define LFSS_A2MIN_AMINLOWBCD_OFS                (8)                             /* !< AMINLOWBCD Offset */
#define LFSS_A2MIN_AMINLOWBCD_MASK               ((uint32_t)0x00000F00U)         /* !< Alarm Minutes BCD  low digit (0 to
                                                                                    9). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define LFSS_A2MIN_AMINLOWBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A2MIN_AMINLOWBCD_MAXIMUM            ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_A2MIN[AMINHIGHBCD] Bits */
#define LFSS_A2MIN_AMINHIGHBCD_OFS               (12)                            /* !< AMINHIGHBCD Offset */
#define LFSS_A2MIN_AMINHIGHBCD_MASK              ((uint32_t)0x00007000U)         /* !< Alarm Minutes BCD  high digit (0 to
                                                                                    5). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define LFSS_A2MIN_AMINHIGHBCD_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A2MIN_AMINHIGHBCD_MAXIMUM           ((uint32_t)0x00005000U)         /* !< Highest possible value */
/* LFSS_A2MIN[AMINAEBCD] Bits */
#define LFSS_A2MIN_AMINAEBCD_OFS                 (15)                            /* !< AMINAEBCD Offset */
#define LFSS_A2MIN_AMINAEBCD_MASK                ((uint32_t)0x00008000U)         /* !< Alarm Minutes BCD enable. If
                                                                                    RTCBCD=0 this bit is always 0. Write
                                                                                    to this bit will be ignored.   0x0=
                                                                                    Alarm disabled.   0x1= Alarm enabled. */
#define LFSS_A2MIN_AMINAEBCD_DISABLE             ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A2MIN_AMINAEBCD_ENABLE              ((uint32_t)0x00008000U)         /* !< Alarm enabled */

/* LFSS_A2HOUR Bits */
/* LFSS_A2HOUR[AHOURBIN] Bits */
#define LFSS_A2HOUR_AHOURBIN_OFS                 (0)                             /* !< AHOURBIN Offset */
#define LFSS_A2HOUR_AHOURBIN_MASK                ((uint32_t)0x0000001FU)         /* !< Alarm Hours Binary (0 to 23). If
                                                                                    RTCBCD=1 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_A2HOUR_AHOURBIN_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A2HOUR_AHOURBIN_MAXIMUM             ((uint32_t)0x00000017U)         /* !< Highest possible value */
/* LFSS_A2HOUR[AHOURAEBIN] Bits */
#define LFSS_A2HOUR_AHOURAEBIN_OFS               (7)                             /* !< AHOURAEBIN Offset */
#define LFSS_A2HOUR_AHOURAEBIN_MASK              ((uint32_t)0x00000080U)         /* !< Alarm Hours Binary enable. If
                                                                                    RTCBCD=1 this bit is always 0. Write
                                                                                    to this bit will be ignored.   0x0=
                                                                                    Alarm disabled.   0x1= Alarm enabled. */
#define LFSS_A2HOUR_AHOURAEBIN_DISABLE           ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A2HOUR_AHOURAEBIN_ENABLE            ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* LFSS_A2HOUR[AHOURLOWBCD] Bits */
#define LFSS_A2HOUR_AHOURLOWBCD_OFS              (8)                             /* !< AHOURLOWBCD Offset */
#define LFSS_A2HOUR_AHOURLOWBCD_MASK             ((uint32_t)0x00000F00U)         /* !< Alarm Hours BCD  low digit (0 to
                                                                                    9). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define LFSS_A2HOUR_AHOURLOWBCD_MINIMUM          ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A2HOUR_AHOURLOWBCD_MAXIMUM          ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_A2HOUR[AHOURHIGHBCD] Bits */
#define LFSS_A2HOUR_AHOURHIGHBCD_OFS             (12)                            /* !< AHOURHIGHBCD Offset */
#define LFSS_A2HOUR_AHOURHIGHBCD_MASK            ((uint32_t)0x00003000U)         /* !< Alarm Hours BCD  high digit (0 to
                                                                                    2). If RTCBCD=0 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0.. */
#define LFSS_A2HOUR_AHOURHIGHBCD_MINIMUM         ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A2HOUR_AHOURHIGHBCD_MAXIMUM         ((uint32_t)0x00002000U)         /* !< Highest possible value */
/* LFSS_A2HOUR[AHOURAEBCD] Bits */
#define LFSS_A2HOUR_AHOURAEBCD_OFS               (15)                            /* !< AHOURAEBCD Offset */
#define LFSS_A2HOUR_AHOURAEBCD_MASK              ((uint32_t)0x00008000U)         /* !< Alarm Hours BCD enable. If RTCBCD=0
                                                                                    this bit is always 0. Write to this
                                                                                    bit will be ignored.   0x0= Alarm
                                                                                    disabled.   0x1= Alarm enabled. */
#define LFSS_A2HOUR_AHOURAEBCD_DISABLE           ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A2HOUR_AHOURAEBCD_ENABLE            ((uint32_t)0x00008000U)         /* !< Alarm enabled */

/* LFSS_A2DAY Bits */
/* LFSS_A2DAY[ADOW] Bits */
#define LFSS_A2DAY_ADOW_OFS                      (0)                             /* !< ADOW Offset */
#define LFSS_A2DAY_ADOW_MASK                     ((uint32_t)0x00000007U)         /* !< Alarm Day of week (0 to 6). These
                                                                                    bits are valid if RTCBCD=1 or
                                                                                    RTCBCD=0. */
#define LFSS_A2DAY_ADOW_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A2DAY_ADOW_MAXIMUM                  ((uint32_t)0x00000006U)         /* !< Highest possible value */
/* LFSS_A2DAY[ADOWAE] Bits */
#define LFSS_A2DAY_ADOWAE_OFS                    (7)                             /* !< ADOWAE Offset */
#define LFSS_A2DAY_ADOWAE_MASK                   ((uint32_t)0x00000080U)         /* !< Alarm Day of week enable. This bit
                                                                                    are valid if RTCBCD=1 or RTCBCD=0. */
#define LFSS_A2DAY_ADOWAE_DISABLE                ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A2DAY_ADOWAE_ENABLE                 ((uint32_t)0x00000080U)         /* !< Alarm enabled */
/* LFSS_A2DAY[ADOMBIN] Bits */
#define LFSS_A2DAY_ADOMBIN_OFS                   (8)                             /* !< ADOMBIN Offset */
#define LFSS_A2DAY_ADOMBIN_MASK                  ((uint32_t)0x00001F00U)         /* !< Alarm Day of month Binary (1 to 28,
                                                                                    29, 30, 31) If RTCBCD=1 write to
                                                                                    these bits will be ignored and read
                                                                                    give the value 0. */
#define LFSS_A2DAY_ADOMBIN_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A2DAY_ADOMBIN_MAXIMUM               ((uint32_t)0x00001F00U)         /* !< Highest possible value */
/* LFSS_A2DAY[ADOMAEBIN] Bits */
#define LFSS_A2DAY_ADOMAEBIN_OFS                 (15)                            /* !< ADOMAEBIN Offset */
#define LFSS_A2DAY_ADOMAEBIN_MASK                ((uint32_t)0x00008000U)         /* !< Alarm Day of month Binary enable.
                                                                                    If RTCBCD=1 this bit is always 0.
                                                                                    Write to this bit will be ignored.
                                                                                    0x0= Alarm disabled.   0x1= Alarm
                                                                                    enabled. */
#define LFSS_A2DAY_ADOMAEBIN_DISABLE             ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A2DAY_ADOMAEBIN_ENABLE              ((uint32_t)0x00008000U)         /* !< Alarm enabled */
/* LFSS_A2DAY[ADOMLOWBCD] Bits */
#define LFSS_A2DAY_ADOMLOWBCD_OFS                (16)                            /* !< ADOMLOWBCD Offset */
#define LFSS_A2DAY_ADOMLOWBCD_MASK               ((uint32_t)0x000F0000U)         /* !< Alarm Day of month BCD  low digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_A2DAY_ADOMLOWBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A2DAY_ADOMLOWBCD_MAXIMUM            ((uint32_t)0x00090000U)         /* !< Highest possible value */
/* LFSS_A2DAY[ADOMHIGHBCD] Bits */
#define LFSS_A2DAY_ADOMHIGHBCD_OFS               (20)                            /* !< ADOMHIGHBCD Offset */
#define LFSS_A2DAY_ADOMHIGHBCD_MASK              ((uint32_t)0x00300000U)         /* !< Alarm Day of month BCD  high digit
                                                                                    (0 to 3). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_A2DAY_ADOMHIGHBCD_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_A2DAY_ADOMHIGHBCD_MAXIMUM           ((uint32_t)0x00300000U)         /* !< Highest possible value */
/* LFSS_A2DAY[ADOMAEBCD] Bits */
#define LFSS_A2DAY_ADOMAEBCD_OFS                 (23)                            /* !< ADOMAEBCD Offset */
#define LFSS_A2DAY_ADOMAEBCD_MASK                ((uint32_t)0x00800000U)         /* !< Alarm Day of month BCD enable. If
                                                                                    RTCBCD=0 this bit is always 0. Write
                                                                                    to this bit will be ignored.   0x0=
                                                                                    Alarm disabled.   0x1= Alarm enabled. */
#define LFSS_A2DAY_ADOMAEBCD_DISABLE             ((uint32_t)0x00000000U)         /* !< No alarm */
#define LFSS_A2DAY_ADOMAEBCD_ENABLE              ((uint32_t)0x00800000U)         /* !< Alarm enabled */

/* LFSS_PSCTL Bits */
/* LFSS_PSCTL[RT0IP] Bits */
#define LFSS_PSCTL_RT0IP_OFS                     (2)                             /* !< RT0IP Offset */
#define LFSS_PSCTL_RT0IP_MASK                    ((uint32_t)0x0000001CU)         /* !< Prescale timer 0 interrupt interval */
#define LFSS_PSCTL_RT0IP_INT244US                ((uint32_t)0x00000008U)         /* !< Interval every 244 microsecond */
#define LFSS_PSCTL_RT0IP_INT488US                ((uint32_t)0x0000000CU)         /* !< Interval every 488 microsecond */
#define LFSS_PSCTL_RT0IP_INT0P98MS               ((uint32_t)0x00000010U)         /* !< Interval every 0.98 milisecond */
#define LFSS_PSCTL_RT0IP_INT1P95MS               ((uint32_t)0x00000014U)         /* !< Interval every 1.95 milisecond */
#define LFSS_PSCTL_RT0IP_INT3P91MS               ((uint32_t)0x00000018U)         /* !< Interval every 3.91 milisecond */
#define LFSS_PSCTL_RT0IP_INT7P81MS               ((uint32_t)0x0000001CU)         /* !< Interval every 7.81 milisecond */
/* LFSS_PSCTL[RT1IP] Bits */
#define LFSS_PSCTL_RT1IP_OFS                     (18)                            /* !< RT1IP Offset */
#define LFSS_PSCTL_RT1IP_MASK                    ((uint32_t)0x001C0000U)         /* !< Prescale timer 1 interrupt interval */
#define LFSS_PSCTL_RT1IP_INT15P6MS               ((uint32_t)0x00000000U)         /* !< Interval every 15.6 milisecond */
#define LFSS_PSCTL_RT1IP_INT31P3MS               ((uint32_t)0x00040000U)         /* !< Interval every 31.3 milisecond */
#define LFSS_PSCTL_RT1IP_INT62P5MS               ((uint32_t)0x00080000U)         /* !< Interval every 62.5 milisecond */
#define LFSS_PSCTL_RT1IP_INT125MS                ((uint32_t)0x000C0000U)         /* !< Interval every 125 milisecond */
#define LFSS_PSCTL_RT1IP_INT250MS                ((uint32_t)0x00100000U)         /* !< Interval every 250 milisecond */
#define LFSS_PSCTL_RT1IP_INT500MS                ((uint32_t)0x00140000U)         /* !< Interval every 500 milisecond */
#define LFSS_PSCTL_RT1IP_INT1S                   ((uint32_t)0x00180000U)         /* !< Interval every 1 second */
#define LFSS_PSCTL_RT1IP_INT2S                   ((uint32_t)0x001C0000U)         /* !< Interval every 2 second */

/* LFSS_EXTPSCTL Bits */
/* LFSS_EXTPSCTL[RT2PS] Bits */
#define LFSS_EXTPSCTL_RT2PS_OFS                  (2)                             /* !< RT2PS Offset */
#define LFSS_EXTPSCTL_RT2PS_MASK                 ((uint32_t)0x0000000CU)         /* !< Prescale timer 2 interrupt interval */
#define LFSS_EXTPSCTL_RT2PS_INT4S                ((uint32_t)0x00000000U)         /* !< Interval every 4 second */
#define LFSS_EXTPSCTL_RT2PS_INT8S                ((uint32_t)0x00000004U)         /* !< Interval every 8 second */
#define LFSS_EXTPSCTL_RT2PS_INT16S               ((uint32_t)0x00000008U)         /* !< Interval every 16 second */

/* LFSS_TSSEC Bits */
/* LFSS_TSSEC[SECBIN] Bits */
#define LFSS_TSSEC_SECBIN_OFS                    (0)                             /* !< SECBIN Offset */
#define LFSS_TSSEC_SECBIN_MASK                   ((uint32_t)0x0000003FU)         /* !< Time Stamp Second Binary (0 to 59).
                                                                                    If RTCBCD=1 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define LFSS_TSSEC_SECBIN_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSSEC_SECBIN_MAXIMUM                ((uint32_t)0x0000003BU)         /* !< Highest possible value */
/* LFSS_TSSEC[SECLOWBCD] Bits */
#define LFSS_TSSEC_SECLOWBCD_OFS                 (8)                             /* !< SECLOWBCD Offset */
#define LFSS_TSSEC_SECLOWBCD_MASK                ((uint32_t)0x00000F00U)         /* !< Time Stamp Seconds BCD  low digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_TSSEC_SECLOWBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSSEC_SECLOWBCD_MAXIMUM             ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_TSSEC[SECHIGHBCD] Bits */
#define LFSS_TSSEC_SECHIGHBCD_OFS                (12)                            /* !< SECHIGHBCD Offset */
#define LFSS_TSSEC_SECHIGHBCD_MASK               ((uint32_t)0x00007000U)         /* !< Time Stamp Seconds BCD  high digit
                                                                                    (0 to 5). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_TSSEC_SECHIGHBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSSEC_SECHIGHBCD_MAXIMUM            ((uint32_t)0x00005000U)         /* !< Highest possible value */

/* LFSS_TSMIN Bits */
/* LFSS_TSMIN[MINBIN] Bits */
#define LFSS_TSMIN_MINBIN_OFS                    (0)                             /* !< MINBIN Offset */
#define LFSS_TSMIN_MINBIN_MASK                   ((uint32_t)0x0000003FU)         /* !< Time Stamp Minutes Binary (0 to
                                                                                    59). If RTCBCD=1 write to these bits
                                                                                    will be ignored and read give the
                                                                                    value 0. */
#define LFSS_TSMIN_MINBIN_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSMIN_MINBIN_MAXIMUM                ((uint32_t)0x0000003BU)         /* !< Highest possible value */
/* LFSS_TSMIN[MINLOWBCD] Bits */
#define LFSS_TSMIN_MINLOWBCD_OFS                 (8)                             /* !< MINLOWBCD Offset */
#define LFSS_TSMIN_MINLOWBCD_MASK                ((uint32_t)0x00000F00U)         /* !< Time Stamp Minutes BCD  low digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_TSMIN_MINLOWBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSMIN_MINLOWBCD_MAXIMUM             ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_TSMIN[MINHIGHBCD] Bits */
#define LFSS_TSMIN_MINHIGHBCD_OFS                (12)                            /* !< MINHIGHBCD Offset */
#define LFSS_TSMIN_MINHIGHBCD_MASK               ((uint32_t)0x00007000U)         /* !< Time Stamp Minutes BCD  high digit
                                                                                    (0 to 5). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_TSMIN_MINHIGHBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSMIN_MINHIGHBCD_MAXIMUM            ((uint32_t)0x00005000U)         /* !< Highest possible value */

/* LFSS_TSHOUR Bits */
/* LFSS_TSHOUR[HOURBIN] Bits */
#define LFSS_TSHOUR_HOURBIN_OFS                  (0)                             /* !< HOURBIN Offset */
#define LFSS_TSHOUR_HOURBIN_MASK                 ((uint32_t)0x0000001FU)         /* !< Time Stamp Hours Binary (0 to 23).
                                                                                    If RTCBCD=1 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define LFSS_TSHOUR_HOURBIN_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSHOUR_HOURBIN_MAXIMUM              ((uint32_t)0x00000017U)         /* !< Highest possible value */
/* LFSS_TSHOUR[HOURLOWBCD] Bits */
#define LFSS_TSHOUR_HOURLOWBCD_OFS               (8)                             /* !< HOURLOWBCD Offset */
#define LFSS_TSHOUR_HOURLOWBCD_MASK              ((uint32_t)0x00000F00U)         /* !< Time Stamp Hours BCD  low digit (0
                                                                                    to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_TSHOUR_HOURLOWBCD_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSHOUR_HOURLOWBCD_MAXIMUM           ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_TSHOUR[HOURHIGHBCD] Bits */
#define LFSS_TSHOUR_HOURHIGHBCD_OFS              (12)                            /* !< HOURHIGHBCD Offset */
#define LFSS_TSHOUR_HOURHIGHBCD_MASK             ((uint32_t)0x00003000U)         /* !< Time Stamp Hours BCD  high digit (0
                                                                                    to 2). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_TSHOUR_HOURHIGHBCD_MINIMUM          ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSHOUR_HOURHIGHBCD_MAXIMUM          ((uint32_t)0x00002000U)         /* !< Highest possible value */

/* LFSS_TSDAY Bits */
/* LFSS_TSDAY[DOW] Bits */
#define LFSS_TSDAY_DOW_OFS                       (0)                             /* !< DOW Offset */
#define LFSS_TSDAY_DOW_MASK                      ((uint32_t)0x00000007U)         /* !< Time Stamp Day of week (0 to 6).
                                                                                    These bits are valid if RTCBCD=1 or
                                                                                    RTCBCD=0. */
#define LFSS_TSDAY_DOW_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSDAY_DOW_MAXIMUM                   ((uint32_t)0x00000006U)         /* !< Highest possible value */
/* LFSS_TSDAY[DOMBIN] Bits */
#define LFSS_TSDAY_DOMBIN_OFS                    (8)                             /* !< DOMBIN Offset */
#define LFSS_TSDAY_DOMBIN_MASK                   ((uint32_t)0x00001F00U)         /* !< Time Stamp Day of month Binary (1
                                                                                    to 28, 29, 30, 31) If RTCBCD=1 write
                                                                                    to these bits will be ignored and
                                                                                    read give the value 0. */
#define LFSS_TSDAY_DOMBIN_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSDAY_DOMBIN_MAXIMUM                ((uint32_t)0x00001F00U)         /* !< Highest possible value */
/* LFSS_TSDAY[DOMLOWBCD] Bits */
#define LFSS_TSDAY_DOMLOWBCD_OFS                 (16)                            /* !< DOMLOWBCD Offset */
#define LFSS_TSDAY_DOMLOWBCD_MASK                ((uint32_t)0x000F0000U)         /* !< Time Stamp Day of month BCD  low
                                                                                    digit (0 to 9). If RTCBCD=0 write to
                                                                                    these bits will be ignored and read
                                                                                    give the value 0. */
#define LFSS_TSDAY_DOMLOWBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSDAY_DOMLOWBCD_MAXIMUM             ((uint32_t)0x00090000U)         /* !< Highest possible value */
/* LFSS_TSDAY[DOMHIGHBCD] Bits */
#define LFSS_TSDAY_DOMHIGHBCD_OFS                (20)                            /* !< DOMHIGHBCD Offset */
#define LFSS_TSDAY_DOMHIGHBCD_MASK               ((uint32_t)0x00300000U)         /* !< Time Stamp Day of month BCD  high
                                                                                    digit (0 to 3). If RTCBCD=0 write to
                                                                                    these bits will be ignored and read
                                                                                    give the value 0. */
#define LFSS_TSDAY_DOMHIGHBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSDAY_DOMHIGHBCD_MAXIMUM            ((uint32_t)0x00300000U)         /* !< Highest possible value */

/* LFSS_TSMON Bits */
/* LFSS_TSMON[MONBIN] Bits */
#define LFSS_TSMON_MONBIN_OFS                    (0)                             /* !< MONBIN Offset */
#define LFSS_TSMON_MONBIN_MASK                   ((uint32_t)0x0000000FU)         /* !< Time Stamp Month Binary (1 to 12).
                                                                                    If RTCBCD=1 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define LFSS_TSMON_MONBIN_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSMON_MONBIN_MAXIMUM                ((uint32_t)0x0000000CU)         /* !< Highest possible value */
/* LFSS_TSMON[MONLOWBCD] Bits */
#define LFSS_TSMON_MONLOWBCD_OFS                 (8)                             /* !< MONLOWBCD Offset */
#define LFSS_TSMON_MONLOWBCD_MASK                ((uint32_t)0x00000F00U)         /* !< Time Stamp Month BCD  low digit (0
                                                                                    to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_TSMON_MONLOWBCD_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSMON_MONLOWBCD_MAXIMUM             ((uint32_t)0x00000900U)         /* !< Highest possible value */
/* LFSS_TSMON[MONHIGHBCD] Bits */
#define LFSS_TSMON_MONHIGHBCD_OFS                (12)                            /* !< MONHIGHBCD Offset */
#define LFSS_TSMON_MONHIGHBCD_MASK               ((uint32_t)0x00001000U)         /* !< Time Stamp Month BCD  high digit (0
                                                                                    or 1). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_TSMON_MONHIGHBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSMON_MONHIGHBCD_MAXIMUM            ((uint32_t)0x00001000U)         /* !< Highest possible value */

/* LFSS_TSYEAR Bits */
/* LFSS_TSYEAR[YEARLOWBIN] Bits */
#define LFSS_TSYEAR_YEARLOWBIN_OFS               (0)                             /* !< YEARLOWBIN Offset */
#define LFSS_TSYEAR_YEARLOWBIN_MASK              ((uint32_t)0x000000FFU)         /* !< Time Stamp Year Binary  low byte.
                                                                                    Valid values for Year are 0 to 4095.
                                                                                    If RTCBCD=1 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define LFSS_TSYEAR_YEARLOWBIN_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSYEAR_YEARLOWBIN_MAXIMUM           ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* LFSS_TSYEAR[YEARHIGHBIN] Bits */
#define LFSS_TSYEAR_YEARHIGHBIN_OFS              (8)                             /* !< YEARHIGHBIN Offset */
#define LFSS_TSYEAR_YEARHIGHBIN_MASK             ((uint32_t)0x00000F00U)         /* !< Time Stamp Year Binary  high byte.
                                                                                    Valid values for Year are 0 to 4095.
                                                                                    If RTCBCD=1 write to these bits will
                                                                                    be ignored and read give the value 0. */
#define LFSS_TSYEAR_YEARHIGHBIN_MINIMUM          ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSYEAR_YEARHIGHBIN_MAXIMUM          ((uint32_t)0x00000F00U)         /* !< Highest possible value */
/* LFSS_TSYEAR[YERARLOWESTBCD] Bits */
#define LFSS_TSYEAR_YERARLOWESTBCD_OFS           (16)                            /* !< YERARLOWESTBCD Offset */
#define LFSS_TSYEAR_YERARLOWESTBCD_MASK          ((uint32_t)0x000F0000U)         /* !< Time Stamp Year BCD  lowest digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_TSYEAR_YERARLOWESTBCD_MINIMUM       ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSYEAR_YERARLOWESTBCD_MAXIMUM       ((uint32_t)0x00090000U)         /* !< Highest possible value */
/* LFSS_TSYEAR[DECADEBCD] Bits */
#define LFSS_TSYEAR_DECADEBCD_OFS                (20)                            /* !< DECADEBCD Offset */
#define LFSS_TSYEAR_DECADEBCD_MASK               ((uint32_t)0x00F00000U)         /* !< Time Stamp Decade BCD (0 to 9). If
                                                                                    RTCBCD=0 write to these bits will be
                                                                                    ignored and read give the value 0. */
#define LFSS_TSYEAR_DECADEBCD_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSYEAR_DECADEBCD_MAXIMUM            ((uint32_t)0x00900000U)         /* !< Highest possible value */
/* LFSS_TSYEAR[CENTLOWBCD] Bits */
#define LFSS_TSYEAR_CENTLOWBCD_OFS               (24)                            /* !< CENTLOWBCD Offset */
#define LFSS_TSYEAR_CENTLOWBCD_MASK              ((uint32_t)0x0F000000U)         /* !< Time Stamp Century BCD  low digit
                                                                                    (0 to 9). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_TSYEAR_CENTLOWBCD_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSYEAR_CENTLOWBCD_MAXIMUM           ((uint32_t)0x09000000U)         /* !< Highest possible value */
/* LFSS_TSYEAR[CENTHIGHBCD] Bits */
#define LFSS_TSYEAR_CENTHIGHBCD_OFS              (28)                            /* !< CENTHIGHBCD Offset */
#define LFSS_TSYEAR_CENTHIGHBCD_MASK             ((uint32_t)0x70000000U)         /* !< Time Stamp Century BCD  high digit
                                                                                    (0 to 4). If RTCBCD=0 write to these
                                                                                    bits will be ignored and read give
                                                                                    the value 0. */
#define LFSS_TSYEAR_CENTHIGHBCD_MINIMUM          ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_TSYEAR_CENTHIGHBCD_MAXIMUM          ((uint32_t)0x40000000U)         /* !< Highest possible value */

/* LFSS_TSSTAT Bits */
/* LFSS_TSSTAT[TSTIOEVT0] Bits */
#define LFSS_TSSTAT_TSTIOEVT0_OFS                (0)                             /* !< TSTIOEVT0 Offset */
#define LFSS_TSSTAT_TSTIOEVT0_MASK               ((uint32_t)0x00000001U)         /* !< Tamper I/O 0 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT0_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT0_SET                ((uint32_t)0x00000001U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT1] Bits */
#define LFSS_TSSTAT_TSTIOEVT1_OFS                (1)                             /* !< TSTIOEVT1 Offset */
#define LFSS_TSSTAT_TSTIOEVT1_MASK               ((uint32_t)0x00000002U)         /* !< Tamper I/O 1 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT1_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT1_SET                ((uint32_t)0x00000002U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT2] Bits */
#define LFSS_TSSTAT_TSTIOEVT2_OFS                (2)                             /* !< TSTIOEVT2 Offset */
#define LFSS_TSSTAT_TSTIOEVT2_MASK               ((uint32_t)0x00000004U)         /* !< Tamper I/O 2 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT2_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT2_SET                ((uint32_t)0x00000004U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT3] Bits */
#define LFSS_TSSTAT_TSTIOEVT3_OFS                (3)                             /* !< TSTIOEVT3 Offset */
#define LFSS_TSSTAT_TSTIOEVT3_MASK               ((uint32_t)0x00000008U)         /* !< Tamper I/O 3 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT3_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT3_SET                ((uint32_t)0x00000008U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT4] Bits */
#define LFSS_TSSTAT_TSTIOEVT4_OFS                (4)                             /* !< TSTIOEVT4 Offset */
#define LFSS_TSSTAT_TSTIOEVT4_MASK               ((uint32_t)0x00000010U)         /* !< Tamper I/O 4 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT4_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT4_SET                ((uint32_t)0x00000010U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT5] Bits */
#define LFSS_TSSTAT_TSTIOEVT5_OFS                (5)                             /* !< TSTIOEVT5 Offset */
#define LFSS_TSSTAT_TSTIOEVT5_MASK               ((uint32_t)0x00000020U)         /* !< Tamper I/O 5 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT5_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT5_SET                ((uint32_t)0x00000020U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT6] Bits */
#define LFSS_TSSTAT_TSTIOEVT6_OFS                (6)                             /* !< TSTIOEVT6 Offset */
#define LFSS_TSSTAT_TSTIOEVT6_MASK               ((uint32_t)0x00000040U)         /* !< Tamper I/O 6 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT6_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT6_SET                ((uint32_t)0x00000040U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT7] Bits */
#define LFSS_TSSTAT_TSTIOEVT7_OFS                (7)                             /* !< TSTIOEVT7 Offset */
#define LFSS_TSSTAT_TSTIOEVT7_MASK               ((uint32_t)0x00000080U)         /* !< Tamper I/O 7 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT7_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT7_SET                ((uint32_t)0x00000080U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT8] Bits */
#define LFSS_TSSTAT_TSTIOEVT8_OFS                (8)                             /* !< TSTIOEVT8 Offset */
#define LFSS_TSSTAT_TSTIOEVT8_MASK               ((uint32_t)0x00000100U)         /* !< Tamper I/O 8 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT8_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT8_SET                ((uint32_t)0x00000100U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT9] Bits */
#define LFSS_TSSTAT_TSTIOEVT9_OFS                (9)                             /* !< TSTIOEVT9 Offset */
#define LFSS_TSSTAT_TSTIOEVT9_MASK               ((uint32_t)0x00000200U)         /* !< Tamper I/O 9 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT9_CLR                ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT9_SET                ((uint32_t)0x00000200U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT10] Bits */
#define LFSS_TSSTAT_TSTIOEVT10_OFS               (10)                            /* !< TSTIOEVT10 Offset */
#define LFSS_TSSTAT_TSTIOEVT10_MASK              ((uint32_t)0x00000400U)         /* !< Tamper I/O 10 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT10_CLR               ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT10_SET               ((uint32_t)0x00000400U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT11] Bits */
#define LFSS_TSSTAT_TSTIOEVT11_OFS               (11)                            /* !< TSTIOEVT11 Offset */
#define LFSS_TSSTAT_TSTIOEVT11_MASK              ((uint32_t)0x00000800U)         /* !< Tamper I/O 11 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT11_CLR               ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT11_SET               ((uint32_t)0x00000800U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT12] Bits */
#define LFSS_TSSTAT_TSTIOEVT12_OFS               (12)                            /* !< TSTIOEVT12 Offset */
#define LFSS_TSSTAT_TSTIOEVT12_MASK              ((uint32_t)0x00001000U)         /* !< Tamper I/O 12 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT12_CLR               ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT12_SET               ((uint32_t)0x00001000U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT13] Bits */
#define LFSS_TSSTAT_TSTIOEVT13_OFS               (13)                            /* !< TSTIOEVT13 Offset */
#define LFSS_TSSTAT_TSTIOEVT13_MASK              ((uint32_t)0x00002000U)         /* !< Tamper I/O 13 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT13_CLR               ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT13_SET               ((uint32_t)0x00002000U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT14] Bits */
#define LFSS_TSSTAT_TSTIOEVT14_OFS               (14)                            /* !< TSTIOEVT14 Offset */
#define LFSS_TSSTAT_TSTIOEVT14_MASK              ((uint32_t)0x00004000U)         /* !< Tamper I/O 14 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT14_CLR               ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT14_SET               ((uint32_t)0x00004000U)         /* !< event detected */
/* LFSS_TSSTAT[TSTIOEVT15] Bits */
#define LFSS_TSSTAT_TSTIOEVT15_OFS               (15)                            /* !< TSTIOEVT15 Offset */
#define LFSS_TSSTAT_TSTIOEVT15_MASK              ((uint32_t)0x00008000U)         /* !< Tamper I/O 15 caused time stamp
                                                                                    event */
#define LFSS_TSSTAT_TSTIOEVT15_CLR               ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSTIOEVT15_SET               ((uint32_t)0x00008000U)         /* !< event detected */
/* LFSS_TSSTAT[TSVDDEVT] Bits */
#define LFSS_TSSTAT_TSVDDEVT_OFS                 (16)                            /* !< TSVDDEVT Offset */
#define LFSS_TSSTAT_TSVDDEVT_MASK                ((uint32_t)0x00010000U)         /* !< Loss of VDD caused time stamp event */
#define LFSS_TSSTAT_TSVDDEVT_CLR                 ((uint32_t)0x00000000U)         /* !< no event detected */
#define LFSS_TSSTAT_TSVDDEVT_SET                 ((uint32_t)0x00010000U)         /* !< event detected */

/* LFSS_TSCTL Bits */
/* LFSS_TSCTL[TSTIOEN0] Bits */
#define LFSS_TSCTL_TSTIOEN0_OFS                  (0)                             /* !< TSTIOEN0 Offset */
#define LFSS_TSCTL_TSTIOEN0_MASK                 ((uint32_t)0x00000001U)         /* !< Time Stamp by Tamper I/O 0 enable */
#define LFSS_TSCTL_TSTIOEN0_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN0_ENABLE               ((uint32_t)0x00000001U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN1] Bits */
#define LFSS_TSCTL_TSTIOEN1_OFS                  (1)                             /* !< TSTIOEN1 Offset */
#define LFSS_TSCTL_TSTIOEN1_MASK                 ((uint32_t)0x00000002U)         /* !< Time Stamp by Tamper I/O 1 enable */
#define LFSS_TSCTL_TSTIOEN1_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN1_ENABLE               ((uint32_t)0x00000002U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN2] Bits */
#define LFSS_TSCTL_TSTIOEN2_OFS                  (2)                             /* !< TSTIOEN2 Offset */
#define LFSS_TSCTL_TSTIOEN2_MASK                 ((uint32_t)0x00000004U)         /* !< Time Stamp by Tamper I/O 2 enable */
#define LFSS_TSCTL_TSTIOEN2_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN2_ENABLE               ((uint32_t)0x00000004U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN3] Bits */
#define LFSS_TSCTL_TSTIOEN3_OFS                  (3)                             /* !< TSTIOEN3 Offset */
#define LFSS_TSCTL_TSTIOEN3_MASK                 ((uint32_t)0x00000008U)         /* !< Time Stamp by Tamper I/O 3 enable */
#define LFSS_TSCTL_TSTIOEN3_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN3_ENABLE               ((uint32_t)0x00000008U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN4] Bits */
#define LFSS_TSCTL_TSTIOEN4_OFS                  (4)                             /* !< TSTIOEN4 Offset */
#define LFSS_TSCTL_TSTIOEN4_MASK                 ((uint32_t)0x00000010U)         /* !< Time Stamp by Tamper I/O 4 enable */
#define LFSS_TSCTL_TSTIOEN4_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN4_ENABLE               ((uint32_t)0x00000010U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN5] Bits */
#define LFSS_TSCTL_TSTIOEN5_OFS                  (5)                             /* !< TSTIOEN5 Offset */
#define LFSS_TSCTL_TSTIOEN5_MASK                 ((uint32_t)0x00000020U)         /* !< Time Stamp by Tamper I/O 5 enable */
#define LFSS_TSCTL_TSTIOEN5_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN5_ENABLE               ((uint32_t)0x00000020U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN6] Bits */
#define LFSS_TSCTL_TSTIOEN6_OFS                  (6)                             /* !< TSTIOEN6 Offset */
#define LFSS_TSCTL_TSTIOEN6_MASK                 ((uint32_t)0x00000040U)         /* !< Time Stamp by Tamper I/O 6 enable */
#define LFSS_TSCTL_TSTIOEN6_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN6_ENABLE               ((uint32_t)0x00000040U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN7] Bits */
#define LFSS_TSCTL_TSTIOEN7_OFS                  (7)                             /* !< TSTIOEN7 Offset */
#define LFSS_TSCTL_TSTIOEN7_MASK                 ((uint32_t)0x00000080U)         /* !< Time Stamp by Tamper I/O 7 enable */
#define LFSS_TSCTL_TSTIOEN7_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN7_ENABLE               ((uint32_t)0x00000080U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN8] Bits */
#define LFSS_TSCTL_TSTIOEN8_OFS                  (8)                             /* !< TSTIOEN8 Offset */
#define LFSS_TSCTL_TSTIOEN8_MASK                 ((uint32_t)0x00000100U)         /* !< Time Stamp by Tamper I/O 8 enable */
#define LFSS_TSCTL_TSTIOEN8_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN8_ENABLE               ((uint32_t)0x00000100U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN9] Bits */
#define LFSS_TSCTL_TSTIOEN9_OFS                  (9)                             /* !< TSTIOEN9 Offset */
#define LFSS_TSCTL_TSTIOEN9_MASK                 ((uint32_t)0x00000200U)         /* !< Time Stamp by Tamper I/O 9 enable */
#define LFSS_TSCTL_TSTIOEN9_DISABLE              ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN9_ENABLE               ((uint32_t)0x00000200U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN10] Bits */
#define LFSS_TSCTL_TSTIOEN10_OFS                 (10)                            /* !< TSTIOEN10 Offset */
#define LFSS_TSCTL_TSTIOEN10_MASK                ((uint32_t)0x00000400U)         /* !< Time Stamp by Tamper I/O 10 enable */
#define LFSS_TSCTL_TSTIOEN10_DISABLE             ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN10_ENABLE              ((uint32_t)0x00000400U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN11] Bits */
#define LFSS_TSCTL_TSTIOEN11_OFS                 (11)                            /* !< TSTIOEN11 Offset */
#define LFSS_TSCTL_TSTIOEN11_MASK                ((uint32_t)0x00000800U)         /* !< Time Stamp by Tamper I/O 11 enable */
#define LFSS_TSCTL_TSTIOEN11_DISABLE             ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN11_ENABLE              ((uint32_t)0x00000800U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN12] Bits */
#define LFSS_TSCTL_TSTIOEN12_OFS                 (12)                            /* !< TSTIOEN12 Offset */
#define LFSS_TSCTL_TSTIOEN12_MASK                ((uint32_t)0x00001000U)         /* !< Time Stamp by Tamper I/O 12 enable */
#define LFSS_TSCTL_TSTIOEN12_DISABLE             ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN12_ENABLE              ((uint32_t)0x00001000U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN13] Bits */
#define LFSS_TSCTL_TSTIOEN13_OFS                 (13)                            /* !< TSTIOEN13 Offset */
#define LFSS_TSCTL_TSTIOEN13_MASK                ((uint32_t)0x00002000U)         /* !< Time Stamp by Tamper I/O 13 enable */
#define LFSS_TSCTL_TSTIOEN13_DISABLE             ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN13_ENABLE              ((uint32_t)0x00002000U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN14] Bits */
#define LFSS_TSCTL_TSTIOEN14_OFS                 (14)                            /* !< TSTIOEN14 Offset */
#define LFSS_TSCTL_TSTIOEN14_MASK                ((uint32_t)0x00004000U)         /* !< Time Stamp by Tamper I/O 14 enable */
#define LFSS_TSCTL_TSTIOEN14_DISABLE             ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN14_ENABLE              ((uint32_t)0x00004000U)         /* !< function enabled */
/* LFSS_TSCTL[TSTIOEN15] Bits */
#define LFSS_TSCTL_TSTIOEN15_OFS                 (15)                            /* !< TSTIOEN15 Offset */
#define LFSS_TSCTL_TSTIOEN15_MASK                ((uint32_t)0x00008000U)         /* !< Time Stamp by Tamper I/O 15 enable */
#define LFSS_TSCTL_TSTIOEN15_DISABLE             ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSTIOEN15_ENABLE              ((uint32_t)0x00008000U)         /* !< function enabled */
/* LFSS_TSCTL[TSVDDEN] Bits */
#define LFSS_TSCTL_TSVDDEN_OFS                   (16)                            /* !< TSVDDEN Offset */
#define LFSS_TSCTL_TSVDDEN_MASK                  ((uint32_t)0x00010000U)         /* !< Time Stamp by VDD Loss detection
                                                                                    enable */
#define LFSS_TSCTL_TSVDDEN_DISABLE               ((uint32_t)0x00000000U)         /* !< function disabled */
#define LFSS_TSCTL_TSVDDEN_ENABLE                ((uint32_t)0x00010000U)         /* !< function enabled */
/* LFSS_TSCTL[TSCAPTURE] Bits */
#define LFSS_TSCTL_TSCAPTURE_OFS                 (20)                            /* !< TSCAPTURE Offset */
#define LFSS_TSCTL_TSCAPTURE_MASK                ((uint32_t)0x00100000U)         /* !< Defines the capture method of the
                                                                                    RTC timestamp when a time stamp event
                                                                                    occurens. */
#define LFSS_TSCTL_TSCAPTURE_FIRST               ((uint32_t)0x00000000U)         /* !< Time stamp holds RTC capture at
                                                                                    first occurrence of time stamp event. */
#define LFSS_TSCTL_TSCAPTURE_LAST                ((uint32_t)0x00100000U)         /* !< Time stamp holds RTC capture at
                                                                                    last occurrence of time stamp event. */
/* LFSS_TSCTL[KEY] Bits */
#define LFSS_TSCTL_KEY_OFS                       (24)                            /* !< KEY Offset */
#define LFSS_TSCTL_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xC5) to update
                                                                                    this register */
#define LFSS_TSCTL_KEY_UNLOCK_W                  ((uint32_t)0xC5000000U)         /* !< This field must be written with
                                                                                    0xC5 to be able to clear any of the
                                                                                    enable bits */

/* LFSS_TSCLR Bits */
/* LFSS_TSCLR[CLR] Bits */
#define LFSS_TSCLR_CLR_OFS                       (0)                             /* !< CLR Offset */
#define LFSS_TSCLR_CLR_MASK                      ((uint32_t)0x00000001U)         /* !< Clear time stamp and status
                                                                                    register. */
#define LFSS_TSCLR_CLR_NO_EFFECT                 ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_TSCLR_CLR_CLR                       ((uint32_t)0x00000001U)         /* !< clear time stamp event */
/* LFSS_TSCLR[KEY] Bits */
#define LFSS_TSCLR_KEY_OFS                       (24)                            /* !< KEY Offset */
#define LFSS_TSCLR_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0xE2) to update
                                                                                    this register */
#define LFSS_TSCLR_KEY_UNLOCK_W                  ((uint32_t)0xE2000000U)         /* !< This field must be written with
                                                                                    0xE2 to be able to clear any of the
                                                                                    enable bits */

/* LFSS_LFSSRST Bits */
/* LFSS_LFSSRST[VBATPOR] Bits */
#define LFSS_LFSSRST_VBATPOR_OFS                 (0)                             /* !< VBATPOR Offset */
#define LFSS_LFSSRST_VBATPOR_MASK                ((uint32_t)0x00000001U)         /* !< If set, the register bit will
                                                                                    request a power on reset to the PMU
                                                                                    of the LFSS. */
#define LFSS_LFSSRST_VBATPOR_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< Writing this value has no effect. */
#define LFSS_LFSSRST_VBATPOR_SET                 ((uint32_t)0x00000001U)         /* !< Request power on reset to the LFSS. */
/* LFSS_LFSSRST[KEY] Bits */
#define LFSS_LFSSRST_KEY_OFS                     (24)                            /* !< KEY Offset */
#define LFSS_LFSSRST_KEY_MASK                    ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0x12) to update
                                                                                    this register */
#define LFSS_LFSSRST_KEY_UNLOCK_W                ((uint32_t)0x12000000U)         /* !< This field must be written with
                                                                                    0x12 to be able to request the power
                                                                                    on reset. */

/* LFSS_RTCLOCK Bits */
/* LFSS_RTCLOCK[PROTECT] Bits */
#define LFSS_RTCLOCK_PROTECT_OFS                 (0)                             /* !< PROTECT Offset */
#define LFSS_RTCLOCK_PROTECT_MASK                ((uint32_t)0x00000001U)         /* !< If set, the register bit will
                                                                                    protect the CLKCTL, SEC, MIN, HOUR,
                                                                                    DAY, MON, YEAR and LFSSRST from
                                                                                    accidental writes. */
#define LFSS_RTCLOCK_PROTECT_CLR                 ((uint32_t)0x00000000U)         /* !< RTC counter is writable. */
#define LFSS_RTCLOCK_PROTECT_SET                 ((uint32_t)0x00000001U)         /* !< RTC counter is read only access. */
/* LFSS_RTCLOCK[KEY] Bits */
#define LFSS_RTCLOCK_KEY_OFS                     (24)                            /* !< KEY Offset */
#define LFSS_RTCLOCK_KEY_MASK                    ((uint32_t)0xFF000000U)         /* !< need to write (KEY=0x22) to update
                                                                                    this register */
#define LFSS_RTCLOCK_KEY_UNLOCK_W                ((uint32_t)0x22000000U)         /* !< This field must be written with
                                                                                    0x22 to be able to update any of the
                                                                                    bits. */

/* LFSS_GEN_EVENT_IIDX Bits */
/* LFSS_GEN_EVENT_IIDX[STAT] Bits */
#define LFSS_GEN_EVENT_IIDX_STAT_OFS             (0)                             /* !< STAT Offset */
#define LFSS_GEN_EVENT_IIDX_STAT_MASK            ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define LFSS_GEN_EVENT_IIDX_STAT_NO_INTR         ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define LFSS_GEN_EVENT_IIDX_STAT_RTCRDY          ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_GEN_EVENT_IIDX_STAT_RTCTEV          ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_GEN_EVENT_IIDX_STAT_RTCA1           ((uint32_t)0x00000003U)         /* !< RTC alarm 1 */
#define LFSS_GEN_EVENT_IIDX_STAT_RTCA2           ((uint32_t)0x00000004U)         /* !< RTC alarm 2 */
#define LFSS_GEN_EVENT_IIDX_STAT_RT0PS           ((uint32_t)0x00000005U)         /* !< RTC prescale timer 0 */
#define LFSS_GEN_EVENT_IIDX_STAT_RT1PS           ((uint32_t)0x00000006U)         /* !< RTC prescale timer 1 */
#define LFSS_GEN_EVENT_IIDX_STAT_RT2PS           ((uint32_t)0x00000007U)         /* !< RTC prescale timer 2 */
#define LFSS_GEN_EVENT_IIDX_STAT_TSEVT           ((uint32_t)0x00000008U)         /* !< Time stamp event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO0            ((uint32_t)0x00000009U)         /* !< Tamper I/O 0 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO1            ((uint32_t)0x0000000AU)         /* !< Tamper I/O 1 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO2            ((uint32_t)0x0000000BU)         /* !< Tamper I/O 2 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO3            ((uint32_t)0x0000000CU)         /* !< Tamper I/O 3 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO4            ((uint32_t)0x0000000DU)         /* !< Tamper I/O 4 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO5            ((uint32_t)0x0000000EU)         /* !< Tamper I/O 5 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO6            ((uint32_t)0x0000000FU)         /* !< Tamper I/O 6 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO7            ((uint32_t)0x00000010U)         /* !< Tamper I/O 7 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO8            ((uint32_t)0x00000011U)         /* !< Tamper I/O 8 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO9            ((uint32_t)0x00000012U)         /* !< Tamper I/O 9 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO10           ((uint32_t)0x00000013U)         /* !< Tamper I/O 10 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO11           ((uint32_t)0x00000014U)         /* !< Tamper I/O 11 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO12           ((uint32_t)0x00000015U)         /* !< Tamper I/O 12 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO13           ((uint32_t)0x00000016U)         /* !< Tamper I/O 13 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO14           ((uint32_t)0x00000017U)         /* !< Tamper I/O 14 event */
#define LFSS_GEN_EVENT_IIDX_STAT_TIO15           ((uint32_t)0x00000018U)         /* !< Tamper I/O 15 event */

/* LFSS_GEN_EVENT_IMASK Bits */
/* LFSS_GEN_EVENT_IMASK[RTCRDY] Bits */
#define LFSS_GEN_EVENT_IMASK_RTCRDY_OFS          (0)                             /* !< RTCRDY Offset */
#define LFSS_GEN_EVENT_IMASK_RTCRDY_MASK         ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_GEN_EVENT_IMASK_RTCRDY_CLR          ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_RTCRDY_SET          ((uint32_t)0x00000001U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[RTCTEV] Bits */
#define LFSS_GEN_EVENT_IMASK_RTCTEV_OFS          (1)                             /* !< RTCTEV Offset */
#define LFSS_GEN_EVENT_IMASK_RTCTEV_MASK         ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_GEN_EVENT_IMASK_RTCTEV_CLR          ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_RTCTEV_SET          ((uint32_t)0x00000002U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[RTCA1] Bits */
#define LFSS_GEN_EVENT_IMASK_RTCA1_OFS           (2)                             /* !< RTCA1 Offset */
#define LFSS_GEN_EVENT_IMASK_RTCA1_MASK          ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define LFSS_GEN_EVENT_IMASK_RTCA1_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_RTCA1_SET           ((uint32_t)0x00000004U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[RTCA2] Bits */
#define LFSS_GEN_EVENT_IMASK_RTCA2_OFS           (3)                             /* !< RTCA2 Offset */
#define LFSS_GEN_EVENT_IMASK_RTCA2_MASK          ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define LFSS_GEN_EVENT_IMASK_RTCA2_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_RTCA2_SET           ((uint32_t)0x00000008U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[RT0PS] Bits */
#define LFSS_GEN_EVENT_IMASK_RT0PS_OFS           (4)                             /* !< RT0PS Offset */
#define LFSS_GEN_EVENT_IMASK_RT0PS_MASK          ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define LFSS_GEN_EVENT_IMASK_RT0PS_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_RT0PS_SET           ((uint32_t)0x00000010U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[RT1PS] Bits */
#define LFSS_GEN_EVENT_IMASK_RT1PS_OFS           (5)                             /* !< RT1PS Offset */
#define LFSS_GEN_EVENT_IMASK_RT1PS_MASK          ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define LFSS_GEN_EVENT_IMASK_RT1PS_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_RT1PS_SET           ((uint32_t)0x00000020U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[RT2PS] Bits */
#define LFSS_GEN_EVENT_IMASK_RT2PS_OFS           (6)                             /* !< RT2PS Offset */
#define LFSS_GEN_EVENT_IMASK_RT2PS_MASK          ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define LFSS_GEN_EVENT_IMASK_RT2PS_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_RT2PS_SET           ((uint32_t)0x00000040U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TSEVT] Bits */
#define LFSS_GEN_EVENT_IMASK_TSEVT_OFS           (7)                             /* !< TSEVT Offset */
#define LFSS_GEN_EVENT_IMASK_TSEVT_MASK          ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define LFSS_GEN_EVENT_IMASK_TSEVT_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TSEVT_SET           ((uint32_t)0x00000080U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO0] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO0_OFS            (8)                             /* !< TIO0 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO0_MASK           ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define LFSS_GEN_EVENT_IMASK_TIO0_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO0_SET            ((uint32_t)0x00000100U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO1] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO1_OFS            (9)                             /* !< TIO1 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO1_MASK           ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define LFSS_GEN_EVENT_IMASK_TIO1_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO1_SET            ((uint32_t)0x00000200U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO2] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO2_OFS            (10)                            /* !< TIO2 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO2_MASK           ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define LFSS_GEN_EVENT_IMASK_TIO2_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO2_SET            ((uint32_t)0x00000400U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO3] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO3_OFS            (11)                            /* !< TIO3 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO3_MASK           ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define LFSS_GEN_EVENT_IMASK_TIO3_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO3_SET            ((uint32_t)0x00000800U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO4] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO4_OFS            (12)                            /* !< TIO4 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO4_MASK           ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define LFSS_GEN_EVENT_IMASK_TIO4_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO4_SET            ((uint32_t)0x00001000U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO5] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO5_OFS            (13)                            /* !< TIO5 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO5_MASK           ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define LFSS_GEN_EVENT_IMASK_TIO5_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO5_SET            ((uint32_t)0x00002000U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO6] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO6_OFS            (14)                            /* !< TIO6 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO6_MASK           ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define LFSS_GEN_EVENT_IMASK_TIO6_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO6_SET            ((uint32_t)0x00004000U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO7] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO7_OFS            (15)                            /* !< TIO7 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO7_MASK           ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define LFSS_GEN_EVENT_IMASK_TIO7_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO7_SET            ((uint32_t)0x00008000U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO8] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO8_OFS            (16)                            /* !< TIO8 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO8_MASK           ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define LFSS_GEN_EVENT_IMASK_TIO8_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO8_SET            ((uint32_t)0x00010000U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO9] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO9_OFS            (17)                            /* !< TIO9 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO9_MASK           ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define LFSS_GEN_EVENT_IMASK_TIO9_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO9_SET            ((uint32_t)0x00020000U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO10] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO10_OFS           (18)                            /* !< TIO10 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO10_MASK          ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define LFSS_GEN_EVENT_IMASK_TIO10_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO10_SET           ((uint32_t)0x00040000U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO11] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO11_OFS           (19)                            /* !< TIO11 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO11_MASK          ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define LFSS_GEN_EVENT_IMASK_TIO11_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO11_SET           ((uint32_t)0x00080000U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO12] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO12_OFS           (20)                            /* !< TIO12 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO12_MASK          ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define LFSS_GEN_EVENT_IMASK_TIO12_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO12_SET           ((uint32_t)0x00100000U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO13] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO13_OFS           (21)                            /* !< TIO13 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO13_MASK          ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define LFSS_GEN_EVENT_IMASK_TIO13_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO13_SET           ((uint32_t)0x00200000U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO14] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO14_OFS           (22)                            /* !< TIO14 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO14_MASK          ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define LFSS_GEN_EVENT_IMASK_TIO14_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO14_SET           ((uint32_t)0x00400000U)         /* !< Set Interrrupt Mask */
/* LFSS_GEN_EVENT_IMASK[TIO15] Bits */
#define LFSS_GEN_EVENT_IMASK_TIO15_OFS           (23)                            /* !< TIO15 Offset */
#define LFSS_GEN_EVENT_IMASK_TIO15_MASK          ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define LFSS_GEN_EVENT_IMASK_TIO15_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_GEN_EVENT_IMASK_TIO15_SET           ((uint32_t)0x00800000U)         /* !< Set Interrrupt Mask */

/* LFSS_GEN_EVENT_RIS Bits */
/* LFSS_GEN_EVENT_RIS[RTCRDY] Bits */
#define LFSS_GEN_EVENT_RIS_RTCRDY_OFS            (0)                             /* !< RTCRDY Offset */
#define LFSS_GEN_EVENT_RIS_RTCRDY_MASK           ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_GEN_EVENT_RIS_RTCRDY_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_RTCRDY_SET            ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[RTCTEV] Bits */
#define LFSS_GEN_EVENT_RIS_RTCTEV_OFS            (1)                             /* !< RTCTEV Offset */
#define LFSS_GEN_EVENT_RIS_RTCTEV_MASK           ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_GEN_EVENT_RIS_RTCTEV_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_RTCTEV_SET            ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[RTCA1] Bits */
#define LFSS_GEN_EVENT_RIS_RTCA1_OFS             (2)                             /* !< RTCA1 Offset */
#define LFSS_GEN_EVENT_RIS_RTCA1_MASK            ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define LFSS_GEN_EVENT_RIS_RTCA1_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_RTCA1_SET             ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[RTCA2] Bits */
#define LFSS_GEN_EVENT_RIS_RTCA2_OFS             (3)                             /* !< RTCA2 Offset */
#define LFSS_GEN_EVENT_RIS_RTCA2_MASK            ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define LFSS_GEN_EVENT_RIS_RTCA2_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_RTCA2_SET             ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[RT0PS] Bits */
#define LFSS_GEN_EVENT_RIS_RT0PS_OFS             (4)                             /* !< RT0PS Offset */
#define LFSS_GEN_EVENT_RIS_RT0PS_MASK            ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define LFSS_GEN_EVENT_RIS_RT0PS_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_RT0PS_SET             ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[RT1PS] Bits */
#define LFSS_GEN_EVENT_RIS_RT1PS_OFS             (5)                             /* !< RT1PS Offset */
#define LFSS_GEN_EVENT_RIS_RT1PS_MASK            ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define LFSS_GEN_EVENT_RIS_RT1PS_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_RT1PS_SET             ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[RT2PS] Bits */
#define LFSS_GEN_EVENT_RIS_RT2PS_OFS             (6)                             /* !< RT2PS Offset */
#define LFSS_GEN_EVENT_RIS_RT2PS_MASK            ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define LFSS_GEN_EVENT_RIS_RT2PS_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_RT2PS_SET             ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TSEVT] Bits */
#define LFSS_GEN_EVENT_RIS_TSEVT_OFS             (7)                             /* !< TSEVT Offset */
#define LFSS_GEN_EVENT_RIS_TSEVT_MASK            ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define LFSS_GEN_EVENT_RIS_TSEVT_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TSEVT_SET             ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO0] Bits */
#define LFSS_GEN_EVENT_RIS_TIO0_OFS              (8)                             /* !< TIO0 Offset */
#define LFSS_GEN_EVENT_RIS_TIO0_MASK             ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define LFSS_GEN_EVENT_RIS_TIO0_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO0_SET              ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO1] Bits */
#define LFSS_GEN_EVENT_RIS_TIO1_OFS              (9)                             /* !< TIO1 Offset */
#define LFSS_GEN_EVENT_RIS_TIO1_MASK             ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define LFSS_GEN_EVENT_RIS_TIO1_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO1_SET              ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO2] Bits */
#define LFSS_GEN_EVENT_RIS_TIO2_OFS              (10)                            /* !< TIO2 Offset */
#define LFSS_GEN_EVENT_RIS_TIO2_MASK             ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define LFSS_GEN_EVENT_RIS_TIO2_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO2_SET              ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO3] Bits */
#define LFSS_GEN_EVENT_RIS_TIO3_OFS              (11)                            /* !< TIO3 Offset */
#define LFSS_GEN_EVENT_RIS_TIO3_MASK             ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define LFSS_GEN_EVENT_RIS_TIO3_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO3_SET              ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO4] Bits */
#define LFSS_GEN_EVENT_RIS_TIO4_OFS              (12)                            /* !< TIO4 Offset */
#define LFSS_GEN_EVENT_RIS_TIO4_MASK             ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define LFSS_GEN_EVENT_RIS_TIO4_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO4_SET              ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO5] Bits */
#define LFSS_GEN_EVENT_RIS_TIO5_OFS              (13)                            /* !< TIO5 Offset */
#define LFSS_GEN_EVENT_RIS_TIO5_MASK             ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define LFSS_GEN_EVENT_RIS_TIO5_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO5_SET              ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO6] Bits */
#define LFSS_GEN_EVENT_RIS_TIO6_OFS              (14)                            /* !< TIO6 Offset */
#define LFSS_GEN_EVENT_RIS_TIO6_MASK             ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define LFSS_GEN_EVENT_RIS_TIO6_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO6_SET              ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO7] Bits */
#define LFSS_GEN_EVENT_RIS_TIO7_OFS              (15)                            /* !< TIO7 Offset */
#define LFSS_GEN_EVENT_RIS_TIO7_MASK             ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define LFSS_GEN_EVENT_RIS_TIO7_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO7_SET              ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO8] Bits */
#define LFSS_GEN_EVENT_RIS_TIO8_OFS              (16)                            /* !< TIO8 Offset */
#define LFSS_GEN_EVENT_RIS_TIO8_MASK             ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define LFSS_GEN_EVENT_RIS_TIO8_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO8_SET              ((uint32_t)0x00010000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO9] Bits */
#define LFSS_GEN_EVENT_RIS_TIO9_OFS              (17)                            /* !< TIO9 Offset */
#define LFSS_GEN_EVENT_RIS_TIO9_MASK             ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define LFSS_GEN_EVENT_RIS_TIO9_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO9_SET              ((uint32_t)0x00020000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO10] Bits */
#define LFSS_GEN_EVENT_RIS_TIO10_OFS             (18)                            /* !< TIO10 Offset */
#define LFSS_GEN_EVENT_RIS_TIO10_MASK            ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define LFSS_GEN_EVENT_RIS_TIO10_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO10_SET             ((uint32_t)0x00040000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO11] Bits */
#define LFSS_GEN_EVENT_RIS_TIO11_OFS             (19)                            /* !< TIO11 Offset */
#define LFSS_GEN_EVENT_RIS_TIO11_MASK            ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define LFSS_GEN_EVENT_RIS_TIO11_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO11_SET             ((uint32_t)0x00080000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO12] Bits */
#define LFSS_GEN_EVENT_RIS_TIO12_OFS             (20)                            /* !< TIO12 Offset */
#define LFSS_GEN_EVENT_RIS_TIO12_MASK            ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define LFSS_GEN_EVENT_RIS_TIO12_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO12_SET             ((uint32_t)0x00100000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO13] Bits */
#define LFSS_GEN_EVENT_RIS_TIO13_OFS             (21)                            /* !< TIO13 Offset */
#define LFSS_GEN_EVENT_RIS_TIO13_MASK            ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define LFSS_GEN_EVENT_RIS_TIO13_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO13_SET             ((uint32_t)0x00200000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO14] Bits */
#define LFSS_GEN_EVENT_RIS_TIO14_OFS             (22)                            /* !< TIO14 Offset */
#define LFSS_GEN_EVENT_RIS_TIO14_MASK            ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define LFSS_GEN_EVENT_RIS_TIO14_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO14_SET             ((uint32_t)0x00400000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_RIS[TIO15] Bits */
#define LFSS_GEN_EVENT_RIS_TIO15_OFS             (23)                            /* !< TIO15 Offset */
#define LFSS_GEN_EVENT_RIS_TIO15_MASK            ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define LFSS_GEN_EVENT_RIS_TIO15_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_GEN_EVENT_RIS_TIO15_SET             ((uint32_t)0x00800000U)         /* !< Interrupt occurred */

/* LFSS_GEN_EVENT_MIS Bits */
/* LFSS_GEN_EVENT_MIS[RTCRDY] Bits */
#define LFSS_GEN_EVENT_MIS_RTCRDY_OFS            (0)                             /* !< RTCRDY Offset */
#define LFSS_GEN_EVENT_MIS_RTCRDY_MASK           ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_GEN_EVENT_MIS_RTCRDY_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_RTCRDY_SET            ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[RTCTEV] Bits */
#define LFSS_GEN_EVENT_MIS_RTCTEV_OFS            (1)                             /* !< RTCTEV Offset */
#define LFSS_GEN_EVENT_MIS_RTCTEV_MASK           ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_GEN_EVENT_MIS_RTCTEV_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_RTCTEV_SET            ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[RTCA1] Bits */
#define LFSS_GEN_EVENT_MIS_RTCA1_OFS             (2)                             /* !< RTCA1 Offset */
#define LFSS_GEN_EVENT_MIS_RTCA1_MASK            ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define LFSS_GEN_EVENT_MIS_RTCA1_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_RTCA1_SET             ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[RTCA2] Bits */
#define LFSS_GEN_EVENT_MIS_RTCA2_OFS             (3)                             /* !< RTCA2 Offset */
#define LFSS_GEN_EVENT_MIS_RTCA2_MASK            ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define LFSS_GEN_EVENT_MIS_RTCA2_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_RTCA2_SET             ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[RT0PS] Bits */
#define LFSS_GEN_EVENT_MIS_RT0PS_OFS             (4)                             /* !< RT0PS Offset */
#define LFSS_GEN_EVENT_MIS_RT0PS_MASK            ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define LFSS_GEN_EVENT_MIS_RT0PS_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_RT0PS_SET             ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[RT1PS] Bits */
#define LFSS_GEN_EVENT_MIS_RT1PS_OFS             (5)                             /* !< RT1PS Offset */
#define LFSS_GEN_EVENT_MIS_RT1PS_MASK            ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define LFSS_GEN_EVENT_MIS_RT1PS_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_RT1PS_SET             ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[RT2PS] Bits */
#define LFSS_GEN_EVENT_MIS_RT2PS_OFS             (6)                             /* !< RT2PS Offset */
#define LFSS_GEN_EVENT_MIS_RT2PS_MASK            ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define LFSS_GEN_EVENT_MIS_RT2PS_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_RT2PS_SET             ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TSEVT] Bits */
#define LFSS_GEN_EVENT_MIS_TSEVT_OFS             (7)                             /* !< TSEVT Offset */
#define LFSS_GEN_EVENT_MIS_TSEVT_MASK            ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define LFSS_GEN_EVENT_MIS_TSEVT_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TSEVT_SET             ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO0] Bits */
#define LFSS_GEN_EVENT_MIS_TIO0_OFS              (8)                             /* !< TIO0 Offset */
#define LFSS_GEN_EVENT_MIS_TIO0_MASK             ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define LFSS_GEN_EVENT_MIS_TIO0_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO0_SET              ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO1] Bits */
#define LFSS_GEN_EVENT_MIS_TIO1_OFS              (9)                             /* !< TIO1 Offset */
#define LFSS_GEN_EVENT_MIS_TIO1_MASK             ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define LFSS_GEN_EVENT_MIS_TIO1_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO1_SET              ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO2] Bits */
#define LFSS_GEN_EVENT_MIS_TIO2_OFS              (10)                            /* !< TIO2 Offset */
#define LFSS_GEN_EVENT_MIS_TIO2_MASK             ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define LFSS_GEN_EVENT_MIS_TIO2_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO2_SET              ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO3] Bits */
#define LFSS_GEN_EVENT_MIS_TIO3_OFS              (11)                            /* !< TIO3 Offset */
#define LFSS_GEN_EVENT_MIS_TIO3_MASK             ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define LFSS_GEN_EVENT_MIS_TIO3_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO3_SET              ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO4] Bits */
#define LFSS_GEN_EVENT_MIS_TIO4_OFS              (12)                            /* !< TIO4 Offset */
#define LFSS_GEN_EVENT_MIS_TIO4_MASK             ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define LFSS_GEN_EVENT_MIS_TIO4_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO4_SET              ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO5] Bits */
#define LFSS_GEN_EVENT_MIS_TIO5_OFS              (13)                            /* !< TIO5 Offset */
#define LFSS_GEN_EVENT_MIS_TIO5_MASK             ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define LFSS_GEN_EVENT_MIS_TIO5_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO5_SET              ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO6] Bits */
#define LFSS_GEN_EVENT_MIS_TIO6_OFS              (14)                            /* !< TIO6 Offset */
#define LFSS_GEN_EVENT_MIS_TIO6_MASK             ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define LFSS_GEN_EVENT_MIS_TIO6_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO6_SET              ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO7] Bits */
#define LFSS_GEN_EVENT_MIS_TIO7_OFS              (15)                            /* !< TIO7 Offset */
#define LFSS_GEN_EVENT_MIS_TIO7_MASK             ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define LFSS_GEN_EVENT_MIS_TIO7_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO7_SET              ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO8] Bits */
#define LFSS_GEN_EVENT_MIS_TIO8_OFS              (16)                            /* !< TIO8 Offset */
#define LFSS_GEN_EVENT_MIS_TIO8_MASK             ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define LFSS_GEN_EVENT_MIS_TIO8_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO8_SET              ((uint32_t)0x00010000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO9] Bits */
#define LFSS_GEN_EVENT_MIS_TIO9_OFS              (17)                            /* !< TIO9 Offset */
#define LFSS_GEN_EVENT_MIS_TIO9_MASK             ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define LFSS_GEN_EVENT_MIS_TIO9_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO9_SET              ((uint32_t)0x00020000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO10] Bits */
#define LFSS_GEN_EVENT_MIS_TIO10_OFS             (18)                            /* !< TIO10 Offset */
#define LFSS_GEN_EVENT_MIS_TIO10_MASK            ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define LFSS_GEN_EVENT_MIS_TIO10_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO10_SET             ((uint32_t)0x00040000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO11] Bits */
#define LFSS_GEN_EVENT_MIS_TIO11_OFS             (19)                            /* !< TIO11 Offset */
#define LFSS_GEN_EVENT_MIS_TIO11_MASK            ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define LFSS_GEN_EVENT_MIS_TIO11_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO11_SET             ((uint32_t)0x00080000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO12] Bits */
#define LFSS_GEN_EVENT_MIS_TIO12_OFS             (20)                            /* !< TIO12 Offset */
#define LFSS_GEN_EVENT_MIS_TIO12_MASK            ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define LFSS_GEN_EVENT_MIS_TIO12_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO12_SET             ((uint32_t)0x00100000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO13] Bits */
#define LFSS_GEN_EVENT_MIS_TIO13_OFS             (21)                            /* !< TIO13 Offset */
#define LFSS_GEN_EVENT_MIS_TIO13_MASK            ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define LFSS_GEN_EVENT_MIS_TIO13_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO13_SET             ((uint32_t)0x00200000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO14] Bits */
#define LFSS_GEN_EVENT_MIS_TIO14_OFS             (22)                            /* !< TIO14 Offset */
#define LFSS_GEN_EVENT_MIS_TIO14_MASK            ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define LFSS_GEN_EVENT_MIS_TIO14_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO14_SET             ((uint32_t)0x00400000U)         /* !< Interrupt occurred */
/* LFSS_GEN_EVENT_MIS[TIO15] Bits */
#define LFSS_GEN_EVENT_MIS_TIO15_OFS             (23)                            /* !< TIO15 Offset */
#define LFSS_GEN_EVENT_MIS_TIO15_MASK            ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define LFSS_GEN_EVENT_MIS_TIO15_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_GEN_EVENT_MIS_TIO15_SET             ((uint32_t)0x00800000U)         /* !< Interrupt occurred */

/* LFSS_GEN_EVENT_ISET Bits */
/* LFSS_GEN_EVENT_ISET[RTCRDY] Bits */
#define LFSS_GEN_EVENT_ISET_RTCRDY_OFS           (0)                             /* !< RTCRDY Offset */
#define LFSS_GEN_EVENT_ISET_RTCRDY_MASK          ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_GEN_EVENT_ISET_RTCRDY_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_RTCRDY_SET           ((uint32_t)0x00000001U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[RTCTEV] Bits */
#define LFSS_GEN_EVENT_ISET_RTCTEV_OFS           (1)                             /* !< RTCTEV Offset */
#define LFSS_GEN_EVENT_ISET_RTCTEV_MASK          ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_GEN_EVENT_ISET_RTCTEV_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_RTCTEV_SET           ((uint32_t)0x00000002U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[RTCA1] Bits */
#define LFSS_GEN_EVENT_ISET_RTCA1_OFS            (2)                             /* !< RTCA1 Offset */
#define LFSS_GEN_EVENT_ISET_RTCA1_MASK           ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define LFSS_GEN_EVENT_ISET_RTCA1_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_RTCA1_SET            ((uint32_t)0x00000004U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[RTCA2] Bits */
#define LFSS_GEN_EVENT_ISET_RTCA2_OFS            (3)                             /* !< RTCA2 Offset */
#define LFSS_GEN_EVENT_ISET_RTCA2_MASK           ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define LFSS_GEN_EVENT_ISET_RTCA2_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_RTCA2_SET            ((uint32_t)0x00000008U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[RT0PS] Bits */
#define LFSS_GEN_EVENT_ISET_RT0PS_OFS            (4)                             /* !< RT0PS Offset */
#define LFSS_GEN_EVENT_ISET_RT0PS_MASK           ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define LFSS_GEN_EVENT_ISET_RT0PS_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_RT0PS_SET            ((uint32_t)0x00000010U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[RT1PS] Bits */
#define LFSS_GEN_EVENT_ISET_RT1PS_OFS            (5)                             /* !< RT1PS Offset */
#define LFSS_GEN_EVENT_ISET_RT1PS_MASK           ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define LFSS_GEN_EVENT_ISET_RT1PS_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_RT1PS_SET            ((uint32_t)0x00000020U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[RT2PS] Bits */
#define LFSS_GEN_EVENT_ISET_RT2PS_OFS            (6)                             /* !< RT2PS Offset */
#define LFSS_GEN_EVENT_ISET_RT2PS_MASK           ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define LFSS_GEN_EVENT_ISET_RT2PS_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_RT2PS_SET            ((uint32_t)0x00000040U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TSEVT] Bits */
#define LFSS_GEN_EVENT_ISET_TSEVT_OFS            (7)                             /* !< TSEVT Offset */
#define LFSS_GEN_EVENT_ISET_TSEVT_MASK           ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define LFSS_GEN_EVENT_ISET_TSEVT_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TSEVT_SET            ((uint32_t)0x00000080U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO0] Bits */
#define LFSS_GEN_EVENT_ISET_TIO0_OFS             (8)                             /* !< TIO0 Offset */
#define LFSS_GEN_EVENT_ISET_TIO0_MASK            ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define LFSS_GEN_EVENT_ISET_TIO0_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO0_SET             ((uint32_t)0x00000100U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO1] Bits */
#define LFSS_GEN_EVENT_ISET_TIO1_OFS             (9)                             /* !< TIO1 Offset */
#define LFSS_GEN_EVENT_ISET_TIO1_MASK            ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define LFSS_GEN_EVENT_ISET_TIO1_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO1_SET             ((uint32_t)0x00000200U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO2] Bits */
#define LFSS_GEN_EVENT_ISET_TIO2_OFS             (10)                            /* !< TIO2 Offset */
#define LFSS_GEN_EVENT_ISET_TIO2_MASK            ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define LFSS_GEN_EVENT_ISET_TIO2_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO2_SET             ((uint32_t)0x00000400U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO3] Bits */
#define LFSS_GEN_EVENT_ISET_TIO3_OFS             (11)                            /* !< TIO3 Offset */
#define LFSS_GEN_EVENT_ISET_TIO3_MASK            ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define LFSS_GEN_EVENT_ISET_TIO3_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO3_SET             ((uint32_t)0x00000800U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO4] Bits */
#define LFSS_GEN_EVENT_ISET_TIO4_OFS             (12)                            /* !< TIO4 Offset */
#define LFSS_GEN_EVENT_ISET_TIO4_MASK            ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define LFSS_GEN_EVENT_ISET_TIO4_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO4_SET             ((uint32_t)0x00001000U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO5] Bits */
#define LFSS_GEN_EVENT_ISET_TIO5_OFS             (13)                            /* !< TIO5 Offset */
#define LFSS_GEN_EVENT_ISET_TIO5_MASK            ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define LFSS_GEN_EVENT_ISET_TIO5_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO5_SET             ((uint32_t)0x00002000U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO6] Bits */
#define LFSS_GEN_EVENT_ISET_TIO6_OFS             (14)                            /* !< TIO6 Offset */
#define LFSS_GEN_EVENT_ISET_TIO6_MASK            ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define LFSS_GEN_EVENT_ISET_TIO6_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO6_SET             ((uint32_t)0x00004000U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO7] Bits */
#define LFSS_GEN_EVENT_ISET_TIO7_OFS             (15)                            /* !< TIO7 Offset */
#define LFSS_GEN_EVENT_ISET_TIO7_MASK            ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define LFSS_GEN_EVENT_ISET_TIO7_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO7_SET             ((uint32_t)0x00008000U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO8] Bits */
#define LFSS_GEN_EVENT_ISET_TIO8_OFS             (16)                            /* !< TIO8 Offset */
#define LFSS_GEN_EVENT_ISET_TIO8_MASK            ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define LFSS_GEN_EVENT_ISET_TIO8_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO8_SET             ((uint32_t)0x00010000U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO9] Bits */
#define LFSS_GEN_EVENT_ISET_TIO9_OFS             (17)                            /* !< TIO9 Offset */
#define LFSS_GEN_EVENT_ISET_TIO9_MASK            ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define LFSS_GEN_EVENT_ISET_TIO9_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO9_SET             ((uint32_t)0x00020000U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO10] Bits */
#define LFSS_GEN_EVENT_ISET_TIO10_OFS            (18)                            /* !< TIO10 Offset */
#define LFSS_GEN_EVENT_ISET_TIO10_MASK           ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define LFSS_GEN_EVENT_ISET_TIO10_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO10_SET            ((uint32_t)0x00040000U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO11] Bits */
#define LFSS_GEN_EVENT_ISET_TIO11_OFS            (19)                            /* !< TIO11 Offset */
#define LFSS_GEN_EVENT_ISET_TIO11_MASK           ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define LFSS_GEN_EVENT_ISET_TIO11_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO11_SET            ((uint32_t)0x00080000U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO12] Bits */
#define LFSS_GEN_EVENT_ISET_TIO12_OFS            (20)                            /* !< TIO12 Offset */
#define LFSS_GEN_EVENT_ISET_TIO12_MASK           ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define LFSS_GEN_EVENT_ISET_TIO12_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO12_SET            ((uint32_t)0x00100000U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO13] Bits */
#define LFSS_GEN_EVENT_ISET_TIO13_OFS            (21)                            /* !< TIO13 Offset */
#define LFSS_GEN_EVENT_ISET_TIO13_MASK           ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define LFSS_GEN_EVENT_ISET_TIO13_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO13_SET            ((uint32_t)0x00200000U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO14] Bits */
#define LFSS_GEN_EVENT_ISET_TIO14_OFS            (22)                            /* !< TIO14 Offset */
#define LFSS_GEN_EVENT_ISET_TIO14_MASK           ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define LFSS_GEN_EVENT_ISET_TIO14_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO14_SET            ((uint32_t)0x00400000U)         /* !< Set interrupt */
/* LFSS_GEN_EVENT_ISET[TIO15] Bits */
#define LFSS_GEN_EVENT_ISET_TIO15_OFS            (23)                            /* !< TIO15 Offset */
#define LFSS_GEN_EVENT_ISET_TIO15_MASK           ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define LFSS_GEN_EVENT_ISET_TIO15_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ISET_TIO15_SET            ((uint32_t)0x00800000U)         /* !< Set interrupt */

/* LFSS_GEN_EVENT_ICLR Bits */
/* LFSS_GEN_EVENT_ICLR[RTCRDY] Bits */
#define LFSS_GEN_EVENT_ICLR_RTCRDY_OFS           (0)                             /* !< RTCRDY Offset */
#define LFSS_GEN_EVENT_ICLR_RTCRDY_MASK          ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_GEN_EVENT_ICLR_RTCRDY_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_RTCRDY_CLR           ((uint32_t)0x00000001U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[RTCTEV] Bits */
#define LFSS_GEN_EVENT_ICLR_RTCTEV_OFS           (1)                             /* !< RTCTEV Offset */
#define LFSS_GEN_EVENT_ICLR_RTCTEV_MASK          ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_GEN_EVENT_ICLR_RTCTEV_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_RTCTEV_CLR           ((uint32_t)0x00000002U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[RTCA1] Bits */
#define LFSS_GEN_EVENT_ICLR_RTCA1_OFS            (2)                             /* !< RTCA1 Offset */
#define LFSS_GEN_EVENT_ICLR_RTCA1_MASK           ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define LFSS_GEN_EVENT_ICLR_RTCA1_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_RTCA1_CLR            ((uint32_t)0x00000004U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[RTCA2] Bits */
#define LFSS_GEN_EVENT_ICLR_RTCA2_OFS            (3)                             /* !< RTCA2 Offset */
#define LFSS_GEN_EVENT_ICLR_RTCA2_MASK           ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define LFSS_GEN_EVENT_ICLR_RTCA2_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_RTCA2_CLR            ((uint32_t)0x00000008U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[RT0PS] Bits */
#define LFSS_GEN_EVENT_ICLR_RT0PS_OFS            (4)                             /* !< RT0PS Offset */
#define LFSS_GEN_EVENT_ICLR_RT0PS_MASK           ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define LFSS_GEN_EVENT_ICLR_RT0PS_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_RT0PS_CLR            ((uint32_t)0x00000010U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[RT1PS] Bits */
#define LFSS_GEN_EVENT_ICLR_RT1PS_OFS            (5)                             /* !< RT1PS Offset */
#define LFSS_GEN_EVENT_ICLR_RT1PS_MASK           ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define LFSS_GEN_EVENT_ICLR_RT1PS_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_RT1PS_CLR            ((uint32_t)0x00000020U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[RT2PS] Bits */
#define LFSS_GEN_EVENT_ICLR_RT2PS_OFS            (6)                             /* !< RT2PS Offset */
#define LFSS_GEN_EVENT_ICLR_RT2PS_MASK           ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define LFSS_GEN_EVENT_ICLR_RT2PS_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_RT2PS_CLR            ((uint32_t)0x00000040U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TSEVT] Bits */
#define LFSS_GEN_EVENT_ICLR_TSEVT_OFS            (7)                             /* !< TSEVT Offset */
#define LFSS_GEN_EVENT_ICLR_TSEVT_MASK           ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define LFSS_GEN_EVENT_ICLR_TSEVT_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TSEVT_CLR            ((uint32_t)0x00000080U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO0] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO0_OFS             (8)                             /* !< TIO0 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO0_MASK            ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define LFSS_GEN_EVENT_ICLR_TIO0_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO0_CLR             ((uint32_t)0x00000100U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO1] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO1_OFS             (9)                             /* !< TIO1 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO1_MASK            ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define LFSS_GEN_EVENT_ICLR_TIO1_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO1_CLR             ((uint32_t)0x00000200U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO2] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO2_OFS             (10)                            /* !< TIO2 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO2_MASK            ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define LFSS_GEN_EVENT_ICLR_TIO2_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO2_CLR             ((uint32_t)0x00000400U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO3] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO3_OFS             (11)                            /* !< TIO3 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO3_MASK            ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define LFSS_GEN_EVENT_ICLR_TIO3_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO3_CLR             ((uint32_t)0x00000800U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO4] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO4_OFS             (12)                            /* !< TIO4 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO4_MASK            ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define LFSS_GEN_EVENT_ICLR_TIO4_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO4_CLR             ((uint32_t)0x00001000U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO5] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO5_OFS             (13)                            /* !< TIO5 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO5_MASK            ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define LFSS_GEN_EVENT_ICLR_TIO5_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO5_CLR             ((uint32_t)0x00002000U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO6] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO6_OFS             (14)                            /* !< TIO6 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO6_MASK            ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define LFSS_GEN_EVENT_ICLR_TIO6_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO6_CLR             ((uint32_t)0x00004000U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO7] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO7_OFS             (15)                            /* !< TIO7 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO7_MASK            ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define LFSS_GEN_EVENT_ICLR_TIO7_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO7_CLR             ((uint32_t)0x00008000U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO8] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO8_OFS             (16)                            /* !< TIO8 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO8_MASK            ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define LFSS_GEN_EVENT_ICLR_TIO8_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO8_CLR             ((uint32_t)0x00010000U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO9] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO9_OFS             (17)                            /* !< TIO9 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO9_MASK            ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define LFSS_GEN_EVENT_ICLR_TIO9_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO9_CLR             ((uint32_t)0x00020000U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO10] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO10_OFS            (18)                            /* !< TIO10 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO10_MASK           ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define LFSS_GEN_EVENT_ICLR_TIO10_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO10_CLR            ((uint32_t)0x00040000U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO11] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO11_OFS            (19)                            /* !< TIO11 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO11_MASK           ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define LFSS_GEN_EVENT_ICLR_TIO11_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO11_CLR            ((uint32_t)0x00080000U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO12] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO12_OFS            (20)                            /* !< TIO12 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO12_MASK           ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define LFSS_GEN_EVENT_ICLR_TIO12_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO12_CLR            ((uint32_t)0x00100000U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO13] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO13_OFS            (21)                            /* !< TIO13 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO13_MASK           ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define LFSS_GEN_EVENT_ICLR_TIO13_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO13_CLR            ((uint32_t)0x00200000U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO14] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO14_OFS            (22)                            /* !< TIO14 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO14_MASK           ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define LFSS_GEN_EVENT_ICLR_TIO14_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO14_CLR            ((uint32_t)0x00400000U)         /* !< Clear interrupt */
/* LFSS_GEN_EVENT_ICLR[TIO15] Bits */
#define LFSS_GEN_EVENT_ICLR_TIO15_OFS            (23)                            /* !< TIO15 Offset */
#define LFSS_GEN_EVENT_ICLR_TIO15_MASK           ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define LFSS_GEN_EVENT_ICLR_TIO15_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_GEN_EVENT_ICLR_TIO15_CLR            ((uint32_t)0x00800000U)         /* !< Clear interrupt */

/* LFSS_CPU_INT_IIDX Bits */
/* LFSS_CPU_INT_IIDX[STAT] Bits */
#define LFSS_CPU_INT_IIDX_STAT_OFS               (0)                             /* !< STAT Offset */
#define LFSS_CPU_INT_IIDX_STAT_MASK              ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define LFSS_CPU_INT_IIDX_STAT_NO_INTR           ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define LFSS_CPU_INT_IIDX_STAT_RTCRDY            ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_CPU_INT_IIDX_STAT_RTCTEV            ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_CPU_INT_IIDX_STAT_RTCA1             ((uint32_t)0x00000003U)         /* !< RTC alarm 1 */
#define LFSS_CPU_INT_IIDX_STAT_RTCA2             ((uint32_t)0x00000004U)         /* !< RTC alarm 2 */
#define LFSS_CPU_INT_IIDX_STAT_RT0PS             ((uint32_t)0x00000005U)         /* !< RTC prescale timer 0 */
#define LFSS_CPU_INT_IIDX_STAT_RT1PS             ((uint32_t)0x00000006U)         /* !< RTC prescale timer 1 */
#define LFSS_CPU_INT_IIDX_STAT_RT2PS             ((uint32_t)0x00000007U)         /* !< RTC prescale timer 2 */
#define LFSS_CPU_INT_IIDX_STAT_TSEVT             ((uint32_t)0x00000008U)         /* !< Time stamp event */
#define LFSS_CPU_INT_IIDX_STAT_TIO0              ((uint32_t)0x00000009U)         /* !< Tamper I/O 0 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO1              ((uint32_t)0x0000000AU)         /* !< Tamper I/O 1 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO2              ((uint32_t)0x0000000BU)         /* !< Tamper I/O 2 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO3              ((uint32_t)0x0000000CU)         /* !< Tamper I/O 3 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO4              ((uint32_t)0x0000000DU)         /* !< Tamper I/O 4 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO5              ((uint32_t)0x0000000EU)         /* !< Tamper I/O 5 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO6              ((uint32_t)0x0000000FU)         /* !< Tamper I/O 6 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO7              ((uint32_t)0x00000010U)         /* !< Tamper I/O 7 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO8              ((uint32_t)0x00000011U)         /* !< Tamper I/O 8 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO9              ((uint32_t)0x00000012U)         /* !< Tamper I/O 9 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO10             ((uint32_t)0x00000013U)         /* !< Tamper I/O 10 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO11             ((uint32_t)0x00000014U)         /* !< Tamper I/O 11 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO12             ((uint32_t)0x00000015U)         /* !< Tamper I/O 12 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO13             ((uint32_t)0x00000016U)         /* !< Tamper I/O 13 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO14             ((uint32_t)0x00000017U)         /* !< Tamper I/O 14 event */
#define LFSS_CPU_INT_IIDX_STAT_TIO15             ((uint32_t)0x00000018U)         /* !< Tamper I/O 15 event */

/* LFSS_CPU_INT_IMASK Bits */
/* LFSS_CPU_INT_IMASK[RTCRDY] Bits */
#define LFSS_CPU_INT_IMASK_RTCRDY_OFS            (0)                             /* !< RTCRDY Offset */
#define LFSS_CPU_INT_IMASK_RTCRDY_MASK           ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_CPU_INT_IMASK_RTCRDY_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_RTCRDY_SET            ((uint32_t)0x00000001U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[RTCTEV] Bits */
#define LFSS_CPU_INT_IMASK_RTCTEV_OFS            (1)                             /* !< RTCTEV Offset */
#define LFSS_CPU_INT_IMASK_RTCTEV_MASK           ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_CPU_INT_IMASK_RTCTEV_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_RTCTEV_SET            ((uint32_t)0x00000002U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[RTCA1] Bits */
#define LFSS_CPU_INT_IMASK_RTCA1_OFS             (2)                             /* !< RTCA1 Offset */
#define LFSS_CPU_INT_IMASK_RTCA1_MASK            ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define LFSS_CPU_INT_IMASK_RTCA1_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_RTCA1_SET             ((uint32_t)0x00000004U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[RTCA2] Bits */
#define LFSS_CPU_INT_IMASK_RTCA2_OFS             (3)                             /* !< RTCA2 Offset */
#define LFSS_CPU_INT_IMASK_RTCA2_MASK            ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define LFSS_CPU_INT_IMASK_RTCA2_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_RTCA2_SET             ((uint32_t)0x00000008U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[RT0PS] Bits */
#define LFSS_CPU_INT_IMASK_RT0PS_OFS             (4)                             /* !< RT0PS Offset */
#define LFSS_CPU_INT_IMASK_RT0PS_MASK            ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define LFSS_CPU_INT_IMASK_RT0PS_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_RT0PS_SET             ((uint32_t)0x00000010U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[RT1PS] Bits */
#define LFSS_CPU_INT_IMASK_RT1PS_OFS             (5)                             /* !< RT1PS Offset */
#define LFSS_CPU_INT_IMASK_RT1PS_MASK            ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define LFSS_CPU_INT_IMASK_RT1PS_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_RT1PS_SET             ((uint32_t)0x00000020U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[RT2PS] Bits */
#define LFSS_CPU_INT_IMASK_RT2PS_OFS             (6)                             /* !< RT2PS Offset */
#define LFSS_CPU_INT_IMASK_RT2PS_MASK            ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define LFSS_CPU_INT_IMASK_RT2PS_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_RT2PS_SET             ((uint32_t)0x00000040U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TSEVT] Bits */
#define LFSS_CPU_INT_IMASK_TSEVT_OFS             (7)                             /* !< TSEVT Offset */
#define LFSS_CPU_INT_IMASK_TSEVT_MASK            ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define LFSS_CPU_INT_IMASK_TSEVT_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TSEVT_SET             ((uint32_t)0x00000080U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO0] Bits */
#define LFSS_CPU_INT_IMASK_TIO0_OFS              (8)                             /* !< TIO0 Offset */
#define LFSS_CPU_INT_IMASK_TIO0_MASK             ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define LFSS_CPU_INT_IMASK_TIO0_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO0_SET              ((uint32_t)0x00000100U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO1] Bits */
#define LFSS_CPU_INT_IMASK_TIO1_OFS              (9)                             /* !< TIO1 Offset */
#define LFSS_CPU_INT_IMASK_TIO1_MASK             ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define LFSS_CPU_INT_IMASK_TIO1_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO1_SET              ((uint32_t)0x00000200U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO2] Bits */
#define LFSS_CPU_INT_IMASK_TIO2_OFS              (10)                            /* !< TIO2 Offset */
#define LFSS_CPU_INT_IMASK_TIO2_MASK             ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define LFSS_CPU_INT_IMASK_TIO2_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO2_SET              ((uint32_t)0x00000400U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO3] Bits */
#define LFSS_CPU_INT_IMASK_TIO3_OFS              (11)                            /* !< TIO3 Offset */
#define LFSS_CPU_INT_IMASK_TIO3_MASK             ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define LFSS_CPU_INT_IMASK_TIO3_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO3_SET              ((uint32_t)0x00000800U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO4] Bits */
#define LFSS_CPU_INT_IMASK_TIO4_OFS              (12)                            /* !< TIO4 Offset */
#define LFSS_CPU_INT_IMASK_TIO4_MASK             ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define LFSS_CPU_INT_IMASK_TIO4_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO4_SET              ((uint32_t)0x00001000U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO5] Bits */
#define LFSS_CPU_INT_IMASK_TIO5_OFS              (13)                            /* !< TIO5 Offset */
#define LFSS_CPU_INT_IMASK_TIO5_MASK             ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define LFSS_CPU_INT_IMASK_TIO5_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO5_SET              ((uint32_t)0x00002000U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO6] Bits */
#define LFSS_CPU_INT_IMASK_TIO6_OFS              (14)                            /* !< TIO6 Offset */
#define LFSS_CPU_INT_IMASK_TIO6_MASK             ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define LFSS_CPU_INT_IMASK_TIO6_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO6_SET              ((uint32_t)0x00004000U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO7] Bits */
#define LFSS_CPU_INT_IMASK_TIO7_OFS              (15)                            /* !< TIO7 Offset */
#define LFSS_CPU_INT_IMASK_TIO7_MASK             ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define LFSS_CPU_INT_IMASK_TIO7_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO7_SET              ((uint32_t)0x00008000U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO8] Bits */
#define LFSS_CPU_INT_IMASK_TIO8_OFS              (16)                            /* !< TIO8 Offset */
#define LFSS_CPU_INT_IMASK_TIO8_MASK             ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define LFSS_CPU_INT_IMASK_TIO8_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO8_SET              ((uint32_t)0x00010000U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO9] Bits */
#define LFSS_CPU_INT_IMASK_TIO9_OFS              (17)                            /* !< TIO9 Offset */
#define LFSS_CPU_INT_IMASK_TIO9_MASK             ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define LFSS_CPU_INT_IMASK_TIO9_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO9_SET              ((uint32_t)0x00020000U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO10] Bits */
#define LFSS_CPU_INT_IMASK_TIO10_OFS             (18)                            /* !< TIO10 Offset */
#define LFSS_CPU_INT_IMASK_TIO10_MASK            ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define LFSS_CPU_INT_IMASK_TIO10_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO10_SET             ((uint32_t)0x00040000U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO11] Bits */
#define LFSS_CPU_INT_IMASK_TIO11_OFS             (19)                            /* !< TIO11 Offset */
#define LFSS_CPU_INT_IMASK_TIO11_MASK            ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define LFSS_CPU_INT_IMASK_TIO11_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO11_SET             ((uint32_t)0x00080000U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO12] Bits */
#define LFSS_CPU_INT_IMASK_TIO12_OFS             (20)                            /* !< TIO12 Offset */
#define LFSS_CPU_INT_IMASK_TIO12_MASK            ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define LFSS_CPU_INT_IMASK_TIO12_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO12_SET             ((uint32_t)0x00100000U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO13] Bits */
#define LFSS_CPU_INT_IMASK_TIO13_OFS             (21)                            /* !< TIO13 Offset */
#define LFSS_CPU_INT_IMASK_TIO13_MASK            ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define LFSS_CPU_INT_IMASK_TIO13_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO13_SET             ((uint32_t)0x00200000U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO14] Bits */
#define LFSS_CPU_INT_IMASK_TIO14_OFS             (22)                            /* !< TIO14 Offset */
#define LFSS_CPU_INT_IMASK_TIO14_MASK            ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define LFSS_CPU_INT_IMASK_TIO14_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO14_SET             ((uint32_t)0x00400000U)         /* !< Set Interrrupt Mask */
/* LFSS_CPU_INT_IMASK[TIO15] Bits */
#define LFSS_CPU_INT_IMASK_TIO15_OFS             (23)                            /* !< TIO15 Offset */
#define LFSS_CPU_INT_IMASK_TIO15_MASK            ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define LFSS_CPU_INT_IMASK_TIO15_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LFSS_CPU_INT_IMASK_TIO15_SET             ((uint32_t)0x00800000U)         /* !< Set Interrrupt Mask */

/* LFSS_CPU_INT_RIS Bits */
/* LFSS_CPU_INT_RIS[RTCRDY] Bits */
#define LFSS_CPU_INT_RIS_RTCRDY_OFS              (0)                             /* !< RTCRDY Offset */
#define LFSS_CPU_INT_RIS_RTCRDY_MASK             ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_CPU_INT_RIS_RTCRDY_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_RTCRDY_SET              ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[RTCTEV] Bits */
#define LFSS_CPU_INT_RIS_RTCTEV_OFS              (1)                             /* !< RTCTEV Offset */
#define LFSS_CPU_INT_RIS_RTCTEV_MASK             ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_CPU_INT_RIS_RTCTEV_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_RTCTEV_SET              ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[RTCA1] Bits */
#define LFSS_CPU_INT_RIS_RTCA1_OFS               (2)                             /* !< RTCA1 Offset */
#define LFSS_CPU_INT_RIS_RTCA1_MASK              ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define LFSS_CPU_INT_RIS_RTCA1_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_RTCA1_SET               ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[RTCA2] Bits */
#define LFSS_CPU_INT_RIS_RTCA2_OFS               (3)                             /* !< RTCA2 Offset */
#define LFSS_CPU_INT_RIS_RTCA2_MASK              ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define LFSS_CPU_INT_RIS_RTCA2_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_RTCA2_SET               ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[RT0PS] Bits */
#define LFSS_CPU_INT_RIS_RT0PS_OFS               (4)                             /* !< RT0PS Offset */
#define LFSS_CPU_INT_RIS_RT0PS_MASK              ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define LFSS_CPU_INT_RIS_RT0PS_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_RT0PS_SET               ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[RT1PS] Bits */
#define LFSS_CPU_INT_RIS_RT1PS_OFS               (5)                             /* !< RT1PS Offset */
#define LFSS_CPU_INT_RIS_RT1PS_MASK              ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define LFSS_CPU_INT_RIS_RT1PS_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_RT1PS_SET               ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[RT2PS] Bits */
#define LFSS_CPU_INT_RIS_RT2PS_OFS               (6)                             /* !< RT2PS Offset */
#define LFSS_CPU_INT_RIS_RT2PS_MASK              ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define LFSS_CPU_INT_RIS_RT2PS_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_RT2PS_SET               ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TSEVT] Bits */
#define LFSS_CPU_INT_RIS_TSEVT_OFS               (7)                             /* !< TSEVT Offset */
#define LFSS_CPU_INT_RIS_TSEVT_MASK              ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define LFSS_CPU_INT_RIS_TSEVT_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TSEVT_SET               ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO0] Bits */
#define LFSS_CPU_INT_RIS_TIO0_OFS                (8)                             /* !< TIO0 Offset */
#define LFSS_CPU_INT_RIS_TIO0_MASK               ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define LFSS_CPU_INT_RIS_TIO0_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO0_SET                ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO1] Bits */
#define LFSS_CPU_INT_RIS_TIO1_OFS                (9)                             /* !< TIO1 Offset */
#define LFSS_CPU_INT_RIS_TIO1_MASK               ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define LFSS_CPU_INT_RIS_TIO1_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO1_SET                ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO2] Bits */
#define LFSS_CPU_INT_RIS_TIO2_OFS                (10)                            /* !< TIO2 Offset */
#define LFSS_CPU_INT_RIS_TIO2_MASK               ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define LFSS_CPU_INT_RIS_TIO2_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO2_SET                ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO3] Bits */
#define LFSS_CPU_INT_RIS_TIO3_OFS                (11)                            /* !< TIO3 Offset */
#define LFSS_CPU_INT_RIS_TIO3_MASK               ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define LFSS_CPU_INT_RIS_TIO3_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO3_SET                ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO4] Bits */
#define LFSS_CPU_INT_RIS_TIO4_OFS                (12)                            /* !< TIO4 Offset */
#define LFSS_CPU_INT_RIS_TIO4_MASK               ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define LFSS_CPU_INT_RIS_TIO4_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO4_SET                ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO5] Bits */
#define LFSS_CPU_INT_RIS_TIO5_OFS                (13)                            /* !< TIO5 Offset */
#define LFSS_CPU_INT_RIS_TIO5_MASK               ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define LFSS_CPU_INT_RIS_TIO5_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO5_SET                ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO6] Bits */
#define LFSS_CPU_INT_RIS_TIO6_OFS                (14)                            /* !< TIO6 Offset */
#define LFSS_CPU_INT_RIS_TIO6_MASK               ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define LFSS_CPU_INT_RIS_TIO6_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO6_SET                ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO7] Bits */
#define LFSS_CPU_INT_RIS_TIO7_OFS                (15)                            /* !< TIO7 Offset */
#define LFSS_CPU_INT_RIS_TIO7_MASK               ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define LFSS_CPU_INT_RIS_TIO7_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO7_SET                ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO8] Bits */
#define LFSS_CPU_INT_RIS_TIO8_OFS                (16)                            /* !< TIO8 Offset */
#define LFSS_CPU_INT_RIS_TIO8_MASK               ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define LFSS_CPU_INT_RIS_TIO8_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO8_SET                ((uint32_t)0x00010000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO9] Bits */
#define LFSS_CPU_INT_RIS_TIO9_OFS                (17)                            /* !< TIO9 Offset */
#define LFSS_CPU_INT_RIS_TIO9_MASK               ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define LFSS_CPU_INT_RIS_TIO9_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO9_SET                ((uint32_t)0x00020000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO10] Bits */
#define LFSS_CPU_INT_RIS_TIO10_OFS               (18)                            /* !< TIO10 Offset */
#define LFSS_CPU_INT_RIS_TIO10_MASK              ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define LFSS_CPU_INT_RIS_TIO10_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO10_SET               ((uint32_t)0x00040000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO11] Bits */
#define LFSS_CPU_INT_RIS_TIO11_OFS               (19)                            /* !< TIO11 Offset */
#define LFSS_CPU_INT_RIS_TIO11_MASK              ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define LFSS_CPU_INT_RIS_TIO11_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO11_SET               ((uint32_t)0x00080000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO12] Bits */
#define LFSS_CPU_INT_RIS_TIO12_OFS               (20)                            /* !< TIO12 Offset */
#define LFSS_CPU_INT_RIS_TIO12_MASK              ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define LFSS_CPU_INT_RIS_TIO12_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO12_SET               ((uint32_t)0x00100000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO13] Bits */
#define LFSS_CPU_INT_RIS_TIO13_OFS               (21)                            /* !< TIO13 Offset */
#define LFSS_CPU_INT_RIS_TIO13_MASK              ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define LFSS_CPU_INT_RIS_TIO13_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO13_SET               ((uint32_t)0x00200000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO14] Bits */
#define LFSS_CPU_INT_RIS_TIO14_OFS               (22)                            /* !< TIO14 Offset */
#define LFSS_CPU_INT_RIS_TIO14_MASK              ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define LFSS_CPU_INT_RIS_TIO14_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO14_SET               ((uint32_t)0x00400000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_RIS[TIO15] Bits */
#define LFSS_CPU_INT_RIS_TIO15_OFS               (23)                            /* !< TIO15 Offset */
#define LFSS_CPU_INT_RIS_TIO15_MASK              ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define LFSS_CPU_INT_RIS_TIO15_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define LFSS_CPU_INT_RIS_TIO15_SET               ((uint32_t)0x00800000U)         /* !< Interrupt occurred */

/* LFSS_CPU_INT_MIS Bits */
/* LFSS_CPU_INT_MIS[RTCRDY] Bits */
#define LFSS_CPU_INT_MIS_RTCRDY_OFS              (0)                             /* !< RTCRDY Offset */
#define LFSS_CPU_INT_MIS_RTCRDY_MASK             ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_CPU_INT_MIS_RTCRDY_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_RTCRDY_SET              ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[RTCTEV] Bits */
#define LFSS_CPU_INT_MIS_RTCTEV_OFS              (1)                             /* !< RTCTEV Offset */
#define LFSS_CPU_INT_MIS_RTCTEV_MASK             ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_CPU_INT_MIS_RTCTEV_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_RTCTEV_SET              ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[RTCA1] Bits */
#define LFSS_CPU_INT_MIS_RTCA1_OFS               (2)                             /* !< RTCA1 Offset */
#define LFSS_CPU_INT_MIS_RTCA1_MASK              ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define LFSS_CPU_INT_MIS_RTCA1_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_RTCA1_SET               ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[RTCA2] Bits */
#define LFSS_CPU_INT_MIS_RTCA2_OFS               (3)                             /* !< RTCA2 Offset */
#define LFSS_CPU_INT_MIS_RTCA2_MASK              ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define LFSS_CPU_INT_MIS_RTCA2_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_RTCA2_SET               ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[RT0PS] Bits */
#define LFSS_CPU_INT_MIS_RT0PS_OFS               (4)                             /* !< RT0PS Offset */
#define LFSS_CPU_INT_MIS_RT0PS_MASK              ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define LFSS_CPU_INT_MIS_RT0PS_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_RT0PS_SET               ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[RT1PS] Bits */
#define LFSS_CPU_INT_MIS_RT1PS_OFS               (5)                             /* !< RT1PS Offset */
#define LFSS_CPU_INT_MIS_RT1PS_MASK              ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define LFSS_CPU_INT_MIS_RT1PS_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_RT1PS_SET               ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[RT2PS] Bits */
#define LFSS_CPU_INT_MIS_RT2PS_OFS               (6)                             /* !< RT2PS Offset */
#define LFSS_CPU_INT_MIS_RT2PS_MASK              ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define LFSS_CPU_INT_MIS_RT2PS_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_RT2PS_SET               ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TSEVT] Bits */
#define LFSS_CPU_INT_MIS_TSEVT_OFS               (7)                             /* !< TSEVT Offset */
#define LFSS_CPU_INT_MIS_TSEVT_MASK              ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define LFSS_CPU_INT_MIS_TSEVT_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TSEVT_SET               ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO0] Bits */
#define LFSS_CPU_INT_MIS_TIO0_OFS                (8)                             /* !< TIO0 Offset */
#define LFSS_CPU_INT_MIS_TIO0_MASK               ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define LFSS_CPU_INT_MIS_TIO0_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO0_SET                ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO1] Bits */
#define LFSS_CPU_INT_MIS_TIO1_OFS                (9)                             /* !< TIO1 Offset */
#define LFSS_CPU_INT_MIS_TIO1_MASK               ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define LFSS_CPU_INT_MIS_TIO1_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO1_SET                ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO2] Bits */
#define LFSS_CPU_INT_MIS_TIO2_OFS                (10)                            /* !< TIO2 Offset */
#define LFSS_CPU_INT_MIS_TIO2_MASK               ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define LFSS_CPU_INT_MIS_TIO2_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO2_SET                ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO3] Bits */
#define LFSS_CPU_INT_MIS_TIO3_OFS                (11)                            /* !< TIO3 Offset */
#define LFSS_CPU_INT_MIS_TIO3_MASK               ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define LFSS_CPU_INT_MIS_TIO3_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO3_SET                ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO4] Bits */
#define LFSS_CPU_INT_MIS_TIO4_OFS                (12)                            /* !< TIO4 Offset */
#define LFSS_CPU_INT_MIS_TIO4_MASK               ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define LFSS_CPU_INT_MIS_TIO4_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO4_SET                ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO5] Bits */
#define LFSS_CPU_INT_MIS_TIO5_OFS                (13)                            /* !< TIO5 Offset */
#define LFSS_CPU_INT_MIS_TIO5_MASK               ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define LFSS_CPU_INT_MIS_TIO5_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO5_SET                ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO6] Bits */
#define LFSS_CPU_INT_MIS_TIO6_OFS                (14)                            /* !< TIO6 Offset */
#define LFSS_CPU_INT_MIS_TIO6_MASK               ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define LFSS_CPU_INT_MIS_TIO6_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO6_SET                ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO7] Bits */
#define LFSS_CPU_INT_MIS_TIO7_OFS                (15)                            /* !< TIO7 Offset */
#define LFSS_CPU_INT_MIS_TIO7_MASK               ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define LFSS_CPU_INT_MIS_TIO7_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO7_SET                ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO8] Bits */
#define LFSS_CPU_INT_MIS_TIO8_OFS                (16)                            /* !< TIO8 Offset */
#define LFSS_CPU_INT_MIS_TIO8_MASK               ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define LFSS_CPU_INT_MIS_TIO8_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO8_SET                ((uint32_t)0x00010000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO9] Bits */
#define LFSS_CPU_INT_MIS_TIO9_OFS                (17)                            /* !< TIO9 Offset */
#define LFSS_CPU_INT_MIS_TIO9_MASK               ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define LFSS_CPU_INT_MIS_TIO9_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO9_SET                ((uint32_t)0x00020000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO10] Bits */
#define LFSS_CPU_INT_MIS_TIO10_OFS               (18)                            /* !< TIO10 Offset */
#define LFSS_CPU_INT_MIS_TIO10_MASK              ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define LFSS_CPU_INT_MIS_TIO10_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO10_SET               ((uint32_t)0x00040000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO11] Bits */
#define LFSS_CPU_INT_MIS_TIO11_OFS               (19)                            /* !< TIO11 Offset */
#define LFSS_CPU_INT_MIS_TIO11_MASK              ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define LFSS_CPU_INT_MIS_TIO11_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO11_SET               ((uint32_t)0x00080000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO12] Bits */
#define LFSS_CPU_INT_MIS_TIO12_OFS               (20)                            /* !< TIO12 Offset */
#define LFSS_CPU_INT_MIS_TIO12_MASK              ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define LFSS_CPU_INT_MIS_TIO12_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO12_SET               ((uint32_t)0x00100000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO13] Bits */
#define LFSS_CPU_INT_MIS_TIO13_OFS               (21)                            /* !< TIO13 Offset */
#define LFSS_CPU_INT_MIS_TIO13_MASK              ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define LFSS_CPU_INT_MIS_TIO13_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO13_SET               ((uint32_t)0x00200000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO14] Bits */
#define LFSS_CPU_INT_MIS_TIO14_OFS               (22)                            /* !< TIO14 Offset */
#define LFSS_CPU_INT_MIS_TIO14_MASK              ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define LFSS_CPU_INT_MIS_TIO14_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO14_SET               ((uint32_t)0x00400000U)         /* !< Interrupt occurred */
/* LFSS_CPU_INT_MIS[TIO15] Bits */
#define LFSS_CPU_INT_MIS_TIO15_OFS               (23)                            /* !< TIO15 Offset */
#define LFSS_CPU_INT_MIS_TIO15_MASK              ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define LFSS_CPU_INT_MIS_TIO15_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define LFSS_CPU_INT_MIS_TIO15_SET               ((uint32_t)0x00800000U)         /* !< Interrupt occurred */

/* LFSS_CPU_INT_ISET Bits */
/* LFSS_CPU_INT_ISET[RTCRDY] Bits */
#define LFSS_CPU_INT_ISET_RTCRDY_OFS             (0)                             /* !< RTCRDY Offset */
#define LFSS_CPU_INT_ISET_RTCRDY_MASK            ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_CPU_INT_ISET_RTCRDY_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_RTCRDY_SET             ((uint32_t)0x00000001U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[RTCTEV] Bits */
#define LFSS_CPU_INT_ISET_RTCTEV_OFS             (1)                             /* !< RTCTEV Offset */
#define LFSS_CPU_INT_ISET_RTCTEV_MASK            ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_CPU_INT_ISET_RTCTEV_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_RTCTEV_SET             ((uint32_t)0x00000002U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[RTCA1] Bits */
#define LFSS_CPU_INT_ISET_RTCA1_OFS              (2)                             /* !< RTCA1 Offset */
#define LFSS_CPU_INT_ISET_RTCA1_MASK             ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define LFSS_CPU_INT_ISET_RTCA1_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_RTCA1_SET              ((uint32_t)0x00000004U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[RTCA2] Bits */
#define LFSS_CPU_INT_ISET_RTCA2_OFS              (3)                             /* !< RTCA2 Offset */
#define LFSS_CPU_INT_ISET_RTCA2_MASK             ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define LFSS_CPU_INT_ISET_RTCA2_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_RTCA2_SET              ((uint32_t)0x00000008U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[RT0PS] Bits */
#define LFSS_CPU_INT_ISET_RT0PS_OFS              (4)                             /* !< RT0PS Offset */
#define LFSS_CPU_INT_ISET_RT0PS_MASK             ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define LFSS_CPU_INT_ISET_RT0PS_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_RT0PS_SET              ((uint32_t)0x00000010U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[RT1PS] Bits */
#define LFSS_CPU_INT_ISET_RT1PS_OFS              (5)                             /* !< RT1PS Offset */
#define LFSS_CPU_INT_ISET_RT1PS_MASK             ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define LFSS_CPU_INT_ISET_RT1PS_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_RT1PS_SET              ((uint32_t)0x00000020U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[RT2PS] Bits */
#define LFSS_CPU_INT_ISET_RT2PS_OFS              (6)                             /* !< RT2PS Offset */
#define LFSS_CPU_INT_ISET_RT2PS_MASK             ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define LFSS_CPU_INT_ISET_RT2PS_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_RT2PS_SET              ((uint32_t)0x00000040U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TSEVT] Bits */
#define LFSS_CPU_INT_ISET_TSEVT_OFS              (7)                             /* !< TSEVT Offset */
#define LFSS_CPU_INT_ISET_TSEVT_MASK             ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define LFSS_CPU_INT_ISET_TSEVT_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TSEVT_SET              ((uint32_t)0x00000080U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO0] Bits */
#define LFSS_CPU_INT_ISET_TIO0_OFS               (8)                             /* !< TIO0 Offset */
#define LFSS_CPU_INT_ISET_TIO0_MASK              ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define LFSS_CPU_INT_ISET_TIO0_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO0_SET               ((uint32_t)0x00000100U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO1] Bits */
#define LFSS_CPU_INT_ISET_TIO1_OFS               (9)                             /* !< TIO1 Offset */
#define LFSS_CPU_INT_ISET_TIO1_MASK              ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define LFSS_CPU_INT_ISET_TIO1_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO1_SET               ((uint32_t)0x00000200U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO2] Bits */
#define LFSS_CPU_INT_ISET_TIO2_OFS               (10)                            /* !< TIO2 Offset */
#define LFSS_CPU_INT_ISET_TIO2_MASK              ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define LFSS_CPU_INT_ISET_TIO2_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO2_SET               ((uint32_t)0x00000400U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO3] Bits */
#define LFSS_CPU_INT_ISET_TIO3_OFS               (11)                            /* !< TIO3 Offset */
#define LFSS_CPU_INT_ISET_TIO3_MASK              ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define LFSS_CPU_INT_ISET_TIO3_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO3_SET               ((uint32_t)0x00000800U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO4] Bits */
#define LFSS_CPU_INT_ISET_TIO4_OFS               (12)                            /* !< TIO4 Offset */
#define LFSS_CPU_INT_ISET_TIO4_MASK              ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define LFSS_CPU_INT_ISET_TIO4_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO4_SET               ((uint32_t)0x00001000U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO5] Bits */
#define LFSS_CPU_INT_ISET_TIO5_OFS               (13)                            /* !< TIO5 Offset */
#define LFSS_CPU_INT_ISET_TIO5_MASK              ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define LFSS_CPU_INT_ISET_TIO5_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO5_SET               ((uint32_t)0x00002000U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO6] Bits */
#define LFSS_CPU_INT_ISET_TIO6_OFS               (14)                            /* !< TIO6 Offset */
#define LFSS_CPU_INT_ISET_TIO6_MASK              ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define LFSS_CPU_INT_ISET_TIO6_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO6_SET               ((uint32_t)0x00004000U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO7] Bits */
#define LFSS_CPU_INT_ISET_TIO7_OFS               (15)                            /* !< TIO7 Offset */
#define LFSS_CPU_INT_ISET_TIO7_MASK              ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define LFSS_CPU_INT_ISET_TIO7_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO7_SET               ((uint32_t)0x00008000U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO8] Bits */
#define LFSS_CPU_INT_ISET_TIO8_OFS               (16)                            /* !< TIO8 Offset */
#define LFSS_CPU_INT_ISET_TIO8_MASK              ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define LFSS_CPU_INT_ISET_TIO8_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO8_SET               ((uint32_t)0x00010000U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO9] Bits */
#define LFSS_CPU_INT_ISET_TIO9_OFS               (17)                            /* !< TIO9 Offset */
#define LFSS_CPU_INT_ISET_TIO9_MASK              ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define LFSS_CPU_INT_ISET_TIO9_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO9_SET               ((uint32_t)0x00020000U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO10] Bits */
#define LFSS_CPU_INT_ISET_TIO10_OFS              (18)                            /* !< TIO10 Offset */
#define LFSS_CPU_INT_ISET_TIO10_MASK             ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define LFSS_CPU_INT_ISET_TIO10_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO10_SET              ((uint32_t)0x00040000U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO11] Bits */
#define LFSS_CPU_INT_ISET_TIO11_OFS              (19)                            /* !< TIO11 Offset */
#define LFSS_CPU_INT_ISET_TIO11_MASK             ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define LFSS_CPU_INT_ISET_TIO11_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO11_SET              ((uint32_t)0x00080000U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO12] Bits */
#define LFSS_CPU_INT_ISET_TIO12_OFS              (20)                            /* !< TIO12 Offset */
#define LFSS_CPU_INT_ISET_TIO12_MASK             ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define LFSS_CPU_INT_ISET_TIO12_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO12_SET              ((uint32_t)0x00100000U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO13] Bits */
#define LFSS_CPU_INT_ISET_TIO13_OFS              (21)                            /* !< TIO13 Offset */
#define LFSS_CPU_INT_ISET_TIO13_MASK             ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define LFSS_CPU_INT_ISET_TIO13_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO13_SET              ((uint32_t)0x00200000U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO14] Bits */
#define LFSS_CPU_INT_ISET_TIO14_OFS              (22)                            /* !< TIO14 Offset */
#define LFSS_CPU_INT_ISET_TIO14_MASK             ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define LFSS_CPU_INT_ISET_TIO14_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO14_SET              ((uint32_t)0x00400000U)         /* !< Set interrupt */
/* LFSS_CPU_INT_ISET[TIO15] Bits */
#define LFSS_CPU_INT_ISET_TIO15_OFS              (23)                            /* !< TIO15 Offset */
#define LFSS_CPU_INT_ISET_TIO15_MASK             ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define LFSS_CPU_INT_ISET_TIO15_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ISET_TIO15_SET              ((uint32_t)0x00800000U)         /* !< Set interrupt */

/* LFSS_CPU_INT_ICLR Bits */
/* LFSS_CPU_INT_ICLR[RTCRDY] Bits */
#define LFSS_CPU_INT_ICLR_RTCRDY_OFS             (0)                             /* !< RTCRDY Offset */
#define LFSS_CPU_INT_ICLR_RTCRDY_MASK            ((uint32_t)0x00000001U)         /* !< RTC ready */
#define LFSS_CPU_INT_ICLR_RTCRDY_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_RTCRDY_CLR             ((uint32_t)0x00000001U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[RTCTEV] Bits */
#define LFSS_CPU_INT_ICLR_RTCTEV_OFS             (1)                             /* !< RTCTEV Offset */
#define LFSS_CPU_INT_ICLR_RTCTEV_MASK            ((uint32_t)0x00000002U)         /* !< RTC time event */
#define LFSS_CPU_INT_ICLR_RTCTEV_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_RTCTEV_CLR             ((uint32_t)0x00000002U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[RTCA1] Bits */
#define LFSS_CPU_INT_ICLR_RTCA1_OFS              (2)                             /* !< RTCA1 Offset */
#define LFSS_CPU_INT_ICLR_RTCA1_MASK             ((uint32_t)0x00000004U)         /* !< RTC alarm 1 */
#define LFSS_CPU_INT_ICLR_RTCA1_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_RTCA1_CLR              ((uint32_t)0x00000004U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[RTCA2] Bits */
#define LFSS_CPU_INT_ICLR_RTCA2_OFS              (3)                             /* !< RTCA2 Offset */
#define LFSS_CPU_INT_ICLR_RTCA2_MASK             ((uint32_t)0x00000008U)         /* !< RTC alarm 2 */
#define LFSS_CPU_INT_ICLR_RTCA2_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_RTCA2_CLR              ((uint32_t)0x00000008U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[RT0PS] Bits */
#define LFSS_CPU_INT_ICLR_RT0PS_OFS              (4)                             /* !< RT0PS Offset */
#define LFSS_CPU_INT_ICLR_RT0PS_MASK             ((uint32_t)0x00000010U)         /* !< RTC prescale timer 0 */
#define LFSS_CPU_INT_ICLR_RT0PS_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_RT0PS_CLR              ((uint32_t)0x00000010U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[RT1PS] Bits */
#define LFSS_CPU_INT_ICLR_RT1PS_OFS              (5)                             /* !< RT1PS Offset */
#define LFSS_CPU_INT_ICLR_RT1PS_MASK             ((uint32_t)0x00000020U)         /* !< RTC prescale timer 1 */
#define LFSS_CPU_INT_ICLR_RT1PS_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_RT1PS_CLR              ((uint32_t)0x00000020U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[RT2PS] Bits */
#define LFSS_CPU_INT_ICLR_RT2PS_OFS              (6)                             /* !< RT2PS Offset */
#define LFSS_CPU_INT_ICLR_RT2PS_MASK             ((uint32_t)0x00000040U)         /* !< RTC prescale timer 2 */
#define LFSS_CPU_INT_ICLR_RT2PS_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_RT2PS_CLR              ((uint32_t)0x00000040U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TSEVT] Bits */
#define LFSS_CPU_INT_ICLR_TSEVT_OFS              (7)                             /* !< TSEVT Offset */
#define LFSS_CPU_INT_ICLR_TSEVT_MASK             ((uint32_t)0x00000080U)         /* !< Time stamp event */
#define LFSS_CPU_INT_ICLR_TSEVT_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TSEVT_CLR              ((uint32_t)0x00000080U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO0] Bits */
#define LFSS_CPU_INT_ICLR_TIO0_OFS               (8)                             /* !< TIO0 Offset */
#define LFSS_CPU_INT_ICLR_TIO0_MASK              ((uint32_t)0x00000100U)         /* !< Tamper I/O 0 event */
#define LFSS_CPU_INT_ICLR_TIO0_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO0_CLR               ((uint32_t)0x00000100U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO1] Bits */
#define LFSS_CPU_INT_ICLR_TIO1_OFS               (9)                             /* !< TIO1 Offset */
#define LFSS_CPU_INT_ICLR_TIO1_MASK              ((uint32_t)0x00000200U)         /* !< Tamper I/O 1 event */
#define LFSS_CPU_INT_ICLR_TIO1_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO1_CLR               ((uint32_t)0x00000200U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO2] Bits */
#define LFSS_CPU_INT_ICLR_TIO2_OFS               (10)                            /* !< TIO2 Offset */
#define LFSS_CPU_INT_ICLR_TIO2_MASK              ((uint32_t)0x00000400U)         /* !< Tamper I/O 2 event */
#define LFSS_CPU_INT_ICLR_TIO2_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO2_CLR               ((uint32_t)0x00000400U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO3] Bits */
#define LFSS_CPU_INT_ICLR_TIO3_OFS               (11)                            /* !< TIO3 Offset */
#define LFSS_CPU_INT_ICLR_TIO3_MASK              ((uint32_t)0x00000800U)         /* !< Tamper I/O 3 event */
#define LFSS_CPU_INT_ICLR_TIO3_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO3_CLR               ((uint32_t)0x00000800U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO4] Bits */
#define LFSS_CPU_INT_ICLR_TIO4_OFS               (12)                            /* !< TIO4 Offset */
#define LFSS_CPU_INT_ICLR_TIO4_MASK              ((uint32_t)0x00001000U)         /* !< Tamper I/O 4 event */
#define LFSS_CPU_INT_ICLR_TIO4_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO4_CLR               ((uint32_t)0x00001000U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO5] Bits */
#define LFSS_CPU_INT_ICLR_TIO5_OFS               (13)                            /* !< TIO5 Offset */
#define LFSS_CPU_INT_ICLR_TIO5_MASK              ((uint32_t)0x00002000U)         /* !< Tamper I/O 5 event */
#define LFSS_CPU_INT_ICLR_TIO5_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO5_CLR               ((uint32_t)0x00002000U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO6] Bits */
#define LFSS_CPU_INT_ICLR_TIO6_OFS               (14)                            /* !< TIO6 Offset */
#define LFSS_CPU_INT_ICLR_TIO6_MASK              ((uint32_t)0x00004000U)         /* !< Tamper I/O 6 event */
#define LFSS_CPU_INT_ICLR_TIO6_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO6_CLR               ((uint32_t)0x00004000U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO7] Bits */
#define LFSS_CPU_INT_ICLR_TIO7_OFS               (15)                            /* !< TIO7 Offset */
#define LFSS_CPU_INT_ICLR_TIO7_MASK              ((uint32_t)0x00008000U)         /* !< Tamper I/O 7 event */
#define LFSS_CPU_INT_ICLR_TIO7_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO7_CLR               ((uint32_t)0x00008000U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO8] Bits */
#define LFSS_CPU_INT_ICLR_TIO8_OFS               (16)                            /* !< TIO8 Offset */
#define LFSS_CPU_INT_ICLR_TIO8_MASK              ((uint32_t)0x00010000U)         /* !< Tamper I/O 8 event */
#define LFSS_CPU_INT_ICLR_TIO8_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO8_CLR               ((uint32_t)0x00010000U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO9] Bits */
#define LFSS_CPU_INT_ICLR_TIO9_OFS               (17)                            /* !< TIO9 Offset */
#define LFSS_CPU_INT_ICLR_TIO9_MASK              ((uint32_t)0x00020000U)         /* !< Tamper I/O 9 event */
#define LFSS_CPU_INT_ICLR_TIO9_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO9_CLR               ((uint32_t)0x00020000U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO10] Bits */
#define LFSS_CPU_INT_ICLR_TIO10_OFS              (18)                            /* !< TIO10 Offset */
#define LFSS_CPU_INT_ICLR_TIO10_MASK             ((uint32_t)0x00040000U)         /* !< Tamper I/O 10 event */
#define LFSS_CPU_INT_ICLR_TIO10_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO10_CLR              ((uint32_t)0x00040000U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO11] Bits */
#define LFSS_CPU_INT_ICLR_TIO11_OFS              (19)                            /* !< TIO11 Offset */
#define LFSS_CPU_INT_ICLR_TIO11_MASK             ((uint32_t)0x00080000U)         /* !< Tamper I/O 11 event */
#define LFSS_CPU_INT_ICLR_TIO11_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO11_CLR              ((uint32_t)0x00080000U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO12] Bits */
#define LFSS_CPU_INT_ICLR_TIO12_OFS              (20)                            /* !< TIO12 Offset */
#define LFSS_CPU_INT_ICLR_TIO12_MASK             ((uint32_t)0x00100000U)         /* !< Tamper I/O 12 event */
#define LFSS_CPU_INT_ICLR_TIO12_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO12_CLR              ((uint32_t)0x00100000U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO13] Bits */
#define LFSS_CPU_INT_ICLR_TIO13_OFS              (21)                            /* !< TIO13 Offset */
#define LFSS_CPU_INT_ICLR_TIO13_MASK             ((uint32_t)0x00200000U)         /* !< Tamper I/O 13 event */
#define LFSS_CPU_INT_ICLR_TIO13_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO13_CLR              ((uint32_t)0x00200000U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO14] Bits */
#define LFSS_CPU_INT_ICLR_TIO14_OFS              (22)                            /* !< TIO14 Offset */
#define LFSS_CPU_INT_ICLR_TIO14_MASK             ((uint32_t)0x00400000U)         /* !< Tamper I/O 14 event */
#define LFSS_CPU_INT_ICLR_TIO14_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO14_CLR              ((uint32_t)0x00400000U)         /* !< Clear interrupt */
/* LFSS_CPU_INT_ICLR[TIO15] Bits */
#define LFSS_CPU_INT_ICLR_TIO15_OFS              (23)                            /* !< TIO15 Offset */
#define LFSS_CPU_INT_ICLR_TIO15_MASK             ((uint32_t)0x00800000U)         /* !< Tamper I/O 15 event */
#define LFSS_CPU_INT_ICLR_TIO15_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LFSS_CPU_INT_ICLR_TIO15_CLR              ((uint32_t)0x00800000U)         /* !< Clear interrupt */

/* LFSS_FSUB_0 Bits */
/* LFSS_FSUB_0[CHANID] Bits */
#define LFSS_FSUB_0_CHANID_OFS                   (0)                             /* !< CHANID Offset */
#define LFSS_FSUB_0_CHANID_MASK                  ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define LFSS_FSUB_0_CHANID_MNIMUM                ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define LFSS_FSUB_0_CHANID_UNCONNECTED           ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define LFSS_FSUB_0_CHANID_MAXIMUM               ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* LFSS_FPUB_0 Bits */
/* LFSS_FPUB_0[CHANID] Bits */
#define LFSS_FPUB_0_CHANID_OFS                   (0)                             /* !< CHANID Offset */
#define LFSS_FPUB_0_CHANID_MASK                  ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define LFSS_FPUB_0_CHANID_MNIMUM                ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define LFSS_FPUB_0_CHANID_UNCONNECTED           ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define LFSS_FPUB_0_CHANID_MAXIMUM               ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* LFSS_CLKSEL Bits */
/* LFSS_CLKSEL[LFCLK_SEL] Bits */
#define LFSS_CLKSEL_LFCLK_SEL_OFS                (1)                             /* !< LFCLK_SEL Offset */
#define LFSS_CLKSEL_LFCLK_SEL_MASK               ((uint32_t)0x00000002U)         /* !< Selects LFCLK as clock source if
                                                                                    enabled */
#define LFSS_CLKSEL_LFCLK_SEL_DISABLE            ((uint32_t)0x00000000U)         /* !< LFCLK is disabled */
#define LFSS_CLKSEL_LFCLK_SEL_ENABLE             ((uint32_t)0x00000002U)         /* !< LFCLK is enabled */

/* LFSS_EVT_MODE Bits */
/* LFSS_EVT_MODE[EVT0_CFG] Bits */
#define LFSS_EVT_MODE_EVT0_CFG_OFS               (0)                             /* !< EVT0_CFG Offset */
#define LFSS_EVT_MODE_EVT0_CFG_MASK              ((uint32_t)0x00000003U)         /* !< Event line mode 0 select */
#define LFSS_EVT_MODE_EVT0_CFG_SOFTWARE          ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. The software ISR
                                                                                    clears the associated RIS flag. */
/* LFSS_EVT_MODE[EVT1_CFG] Bits */
#define LFSS_EVT_MODE_EVT1_CFG_OFS               (2)                             /* !< EVT1_CFG Offset */
#define LFSS_EVT_MODE_EVT1_CFG_MASK              ((uint32_t)0x0000000CU)         /* !< Event line mode 1 select */
#define LFSS_EVT_MODE_EVT1_CFG_HARDWARE          ((uint32_t)0x00000008U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* LFSS_DESC Bits */
/* LFSS_DESC[MINREV] Bits */
#define LFSS_DESC_MINREV_OFS                     (0)                             /* !< MINREV Offset */
#define LFSS_DESC_MINREV_MASK                    ((uint32_t)0x0000000FU)         /* !< Minor revision. This number holds
                                                                                    the module revision and is
                                                                                    incremented by the module developers.
                                                                                    n = Minor module revision (see
                                                                                    device-specific data sheet) */
#define LFSS_DESC_MINREV_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_DESC_MINREV_MAXIMUM                 ((uint32_t)0x0000000FU)         /* !< Highest possible value */
/* LFSS_DESC[MAJREV] Bits */
#define LFSS_DESC_MAJREV_OFS                     (4)                             /* !< MAJREV Offset */
#define LFSS_DESC_MAJREV_MASK                    ((uint32_t)0x000000F0U)         /* !< Major revision. This number holds
                                                                                    the module revision and is
                                                                                    incremented by the module developers.
                                                                                    n = Major version (see
                                                                                    device-specific data sheet) */
#define LFSS_DESC_MAJREV_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_DESC_MAJREV_MAXIMUM                 ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* LFSS_DESC[INSTNUM] Bits */
#define LFSS_DESC_INSTNUM_OFS                    (8)                             /* !< INSTNUM Offset */
#define LFSS_DESC_INSTNUM_MASK                   ((uint32_t)0x00000F00U)         /* !< Instantiated version. Describes
                                                                                    which instance of the module
                                                                                    accessed. */
#define LFSS_DESC_INSTNUM_INST0                  ((uint32_t)0x00000000U)         /* !< This is the default, if there is
                                                                                    only one instance - like for SSIM */
/* LFSS_DESC[FEATUREVER] Bits */
#define LFSS_DESC_FEATUREVER_OFS                 (12)                            /* !< FEATUREVER Offset */
#define LFSS_DESC_FEATUREVER_MASK                ((uint32_t)0x0000F000U)         /* !< Feature set of this module.
                                                                                    Differentiates the complexity of the
                                                                                    actually instantiated module if there
                                                                                    are differences. */
#define LFSS_DESC_FEATUREVER_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_DESC_FEATUREVER_MAXIMUM             ((uint32_t)0x0000F000U)         /* !< Highest possible value */
/* LFSS_DESC[MODULEID] Bits */
#define LFSS_DESC_MODULEID_OFS                   (16)                            /* !< MODULEID Offset */
#define LFSS_DESC_MODULEID_MASK                  ((uint32_t)0xFFFF0000U)         /* !< Module identifier. This ID is
                                                                                    unique for each module. 0x2911 =
                                                                                    Module ID of the LFSS Module */
#define LFSS_DESC_MODULEID_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define LFSS_DESC_MODULEID_MAXIMUM               ((uint32_t)0xFFFF0000U)         /* !< Highest possible value */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_lfss__include */