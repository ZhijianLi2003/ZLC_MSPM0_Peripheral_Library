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

#ifndef ti_devices_msp_peripherals_m0p_hw_sysctl_mspm0l11xx_l13xx__include
#define ti_devices_msp_peripherals_m0p_hw_sysctl_mspm0l11xx_l13xx__include

/* Filename: hw_sysctl_mspm0l11xx_l13xx.h */
/* Revised: 2023-05-10 22:02:57 */
/* Revision: b49f666483ca5daed24b338ee5f46878c932893a */

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
* SYSCTL Registers
******************************************************************************/
#define SYSCTL_MGMT_SPI0_OFS                     ((uint32_t)0x00468800U)
#define SYSCTL_MGMT_CRC0_OFS                     ((uint32_t)0x00440800U)
#define SYSCTL_MGMT_UARTADVLP0_OFS               ((uint32_t)0x00108800U)
#define SYSCTL_MGMT_UARTLP0_OFS                  ((uint32_t)0x00100800U)
#define SYSCTL_MGMT_I2C1_OFS                     ((uint32_t)0x000F2800U)
#define SYSCTL_MGMT_I2C0_OFS                     ((uint32_t)0x000F0800U)
#define SYSCTL_MGMT_GPIO0_OFS                    ((uint32_t)0x000A0800U)
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_OFS       ((uint32_t)0x0008C800U)
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_OFS         ((uint32_t)0x00088800U)
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_OFS         ((uint32_t)0x00086800U)
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_OFS         ((uint32_t)0x00084800U)
#define SYSCTL_MGMT_WWDTLP0_OFS                  ((uint32_t)0x00080800U)
#define SYSCTL_MGMT_VREF_OFS                     ((uint32_t)0x00030800U)
#define SYSCTL_MGMT_OPAMP1_OFS                   ((uint32_t)0x00022800U)
#define SYSCTL_MGMT_OPAMP0_OFS                   ((uint32_t)0x00020800U)
#define SYSCTL_MGMT_ANACOMP0_OFS                 ((uint32_t)0x00008800U)
#define SYSCTL_MGMT_ADC12B1MSPS0_OFS             ((uint32_t)0x00004800U)
#define SYSCTL_SOCLOCK_OFS                       ((uint32_t)0x00001000U)


/** @addtogroup SYSCTL_MGMT_SPI0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00468800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00468804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00468808) IP Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00468814) IP State Register - Read Only */
} SYSCTL_MGMT_SPI0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_SPI0 */

/** @addtogroup SYSCTL_MGMT_CRC0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00440800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00440804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00440814) IP State Register - Read Only */
} SYSCTL_MGMT_CRC0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_CRC0 */

/** @addtogroup SYSCTL_MGMT_UARTADVLP0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00108800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00108804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00108808) IP Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00108814) IP State Register - Read Only */
} SYSCTL_MGMT_UARTADVLP0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_UARTADVLP0 */

/** @addtogroup SYSCTL_MGMT_UARTLP0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00100800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00100804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00100808) IP Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00100814) IP State Register - Read Only */
} SYSCTL_MGMT_UARTLP0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_UARTLP0 */

/** @addtogroup SYSCTL_MGMT_I2C1
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x000F2800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x000F2804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x000F2808) IP Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x000F2814) IP State Register - Read Only */
} SYSCTL_MGMT_I2C1_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_I2C1 */

/** @addtogroup SYSCTL_MGMT_I2C0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x000F0800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x000F0804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x000F0808) IP Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x000F0814) IP State Register - Read Only */
} SYSCTL_MGMT_I2C0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_I2C0 */

/** @addtogroup SYSCTL_MGMT_GPIO0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x000A0800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x000A0804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x000A0814) IP State Register - Read Only */
} SYSCTL_MGMT_GPIO0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_GPIO0 */

/** @addtogroup SYSCTL_MGMT_GPTIMER16B2CCSPLP0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x0008C800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x0008C804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x0008C814) IP State Register - Read Only */
} SYSCTL_MGMT_GPTIMER16B2CCSPLP0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_GPTIMER16B2CCSPLP0 */

/** @addtogroup SYSCTL_MGMT_GPTIMER16B2CCLP2
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00088800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00088804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00088814) IP State Register - Read Only */
} SYSCTL_MGMT_GPTIMER16B2CCLP2_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_GPTIMER16B2CCLP2 */

/** @addtogroup SYSCTL_MGMT_GPTIMER16B2CCLP1
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00086800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00086804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00086814) IP State Register - Read Only */
} SYSCTL_MGMT_GPTIMER16B2CCLP1_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_GPTIMER16B2CCLP1 */

/** @addtogroup SYSCTL_MGMT_GPTIMER16B2CCLP0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00084800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00084804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00084814) IP State Register - Read Only */
} SYSCTL_MGMT_GPTIMER16B2CCLP0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_GPTIMER16B2CCLP0 */

/** @addtogroup SYSCTL_MGMT_WWDTLP0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00080800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00080804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00080814) IP State Register - Read Only */
} SYSCTL_MGMT_WWDTLP0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_WWDTLP0 */

/** @addtogroup SYSCTL_MGMT_VREF
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00030800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00030804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00030814) IP State Register - Read Only */
} SYSCTL_MGMT_VREF_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_VREF */

/** @addtogroup SYSCTL_MGMT_OPAMP1
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00022800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00022804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00022814) IP State Register - Read Only */
} SYSCTL_MGMT_OPAMP1_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_OPAMP1 */

/** @addtogroup SYSCTL_MGMT_OPAMP0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00020800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00020804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00020814) IP State Register - Read Only */
} SYSCTL_MGMT_OPAMP0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_OPAMP0 */

/** @addtogroup SYSCTL_MGMT_ANACOMP0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00008800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00008804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00008808) IP Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00008814) IP State Register - Read Only */
} SYSCTL_MGMT_ANACOMP0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_ANACOMP0 */

/** @addtogroup SYSCTL_MGMT_ADC12B1MSPS0
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00004800) IP Enable Register */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00004804) Power Control Register - Write Only Register,
                                                      Always Read as 0 */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00004808) IP Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00004814) IP State Register - Read Only */
} SYSCTL_MGMT_ADC12B1MSPS0_Regs;

/*@}*/ /* end of group SYSCTL_MGMT_ADC12B1MSPS0 */

/** @addtogroup SYSCTL_SOCLOCK
  @{
*/

typedef struct {
       uint32_t RESERVED0[8];
  __I  uint32_t IIDX;                              /* !< (@ 0x00001020) SYSCTL interrupt index */
       uint32_t RESERVED1;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001028) SYSCTL interrupt mask */
       uint32_t RESERVED2;
  __I  uint32_t RIS;                               /* !< (@ 0x00001030) SYSCTL raw interrupt status */
       uint32_t RESERVED3;
  __I  uint32_t MIS;                               /* !< (@ 0x00001038) SYSCTL masked interrupt status */
       uint32_t RESERVED4;
  __O  uint32_t ISET;                              /* !< (@ 0x00001040) SYSCTL interrupt set */
       uint32_t RESERVED5;
  __O  uint32_t ICLR;                              /* !< (@ 0x00001048) SYSCTL interrupt clear */
       uint32_t RESERVED6;
  __I  uint32_t NMIIIDX;                           /* !< (@ 0x00001050) NMI interrupt index */
       uint32_t RESERVED7[3];
  __I  uint32_t NMIRIS;                            /* !< (@ 0x00001060) NMI raw interrupt status */
       uint32_t RESERVED8[3];
  __O  uint32_t NMIISET;                           /* !< (@ 0x00001070) NMI interrupt set */
       uint32_t RESERVED9;
  __O  uint32_t NMIICLR;                           /* !< (@ 0x00001078) NMI interrupt clear */
       uint32_t RESERVED10[33];
  __IO uint32_t SYSOSCCFG;                         /* !< (@ 0x00001100) SYSOSC configuration */
  __IO uint32_t MCLKCFG;                           /* !< (@ 0x00001104) Main clock (MCLK) configuration */
       uint32_t RESERVED11[12];
  __IO uint32_t GENCLKCFG;                         /* !< (@ 0x00001138) General clock configuration */
  __IO uint32_t GENCLKEN;                          /* !< (@ 0x0000113C) General clock enable control */
  __IO uint32_t PMODECFG;                          /* !< (@ 0x00001140) Power mode configuration */
       uint32_t RESERVED12[3];
  __I  uint32_t FCC;                               /* !< (@ 0x00001150) Frequency clock counter (FCC) count */
       uint32_t RESERVED13[7];
  __IO uint32_t SYSOSCTRIMUSER;                    /* !< (@ 0x00001170) SYSOSC user-specified trim */
       uint32_t RESERVED14;
  __IO uint32_t SRAMBOUNDARY;                      /* !< (@ 0x00001178) SRAM Write Boundary */
       uint32_t RESERVED15;
  __IO uint32_t SYSTEMCFG;                         /* !< (@ 0x00001180) System configuration */
       uint32_t RESERVED16[31];
  __IO uint32_t WRITELOCK;                         /* !< (@ 0x00001200) SYSCTL register write lockout */
  __I  uint32_t CLKSTATUS;                         /* !< (@ 0x00001204) Clock module (CKM) status */
  __I  uint32_t SYSSTATUS;                         /* !< (@ 0x00001208) System status information */
       uint32_t RESERVED17[5];
  __I  uint32_t RSTCAUSE;                          /* !< (@ 0x00001220) Reset cause */
       uint32_t RESERVED18[55];
  __IO uint32_t RESETLEVEL;                        /* !< (@ 0x00001300) Reset level for application-triggered reset
                                                      command */
  __O  uint32_t RESETCMD;                          /* !< (@ 0x00001304) Execute an application-triggered reset command */
  __IO uint32_t BORTHRESHOLD;                      /* !< (@ 0x00001308) BOR threshold selection */
  __O  uint32_t BORCLRCMD;                         /* !< (@ 0x0000130C) Set the BOR threshold */
  __O  uint32_t SYSOSCFCLCTL;                      /* !< (@ 0x00001310) SYSOSC frequency correction loop (FCL) ROSC enable */
       uint32_t RESERVED19[2];
  __O  uint32_t SHDNIOREL;                         /* !< (@ 0x0000131C) SHUTDOWN IO release control */
  __O  uint32_t EXRSTPIN;                          /* !< (@ 0x00001320) Disable the reset function of the NRST pin */
  __O  uint32_t SYSSTATUSCLR;                      /* !< (@ 0x00001324) Clear sticky bits of SYSSTATUS */
  __O  uint32_t SWDCFG;                            /* !< (@ 0x00001328) Disable the SWD function on the SWD pins */
  __O  uint32_t FCCCMD;                            /* !< (@ 0x0000132C) Frequency clock counter start capture */
       uint32_t RESERVED20[20];
  __IO uint32_t PMUOPAMP;                          /* !< (@ 0x00001380) GPAMP control */
       uint32_t RESERVED21[31];
  __IO uint32_t SHUTDNSTORE0;                      /* !< (@ 0x00001400) Shutdown storage memory (byte 0) */
  __IO uint32_t SHUTDNSTORE1;                      /* !< (@ 0x00001404) Shutdown storage memory (byte 1) */
  __IO uint32_t SHUTDNSTORE2;                      /* !< (@ 0x00001408) Shutdown storage memory (byte 2) */
  __IO uint32_t SHUTDNSTORE3;                      /* !< (@ 0x0000140C) Shutdown storage memory (byte 3) */
} SYSCTL_SOCLOCK_Regs;

/*@}*/ /* end of group SYSCTL_SOCLOCK */

/** @addtogroup SYSCTL
  @{
*/

typedef struct {
       uint32_t RESERVED0[1024];
  SYSCTL_SOCLOCK_Regs  SOCLOCK;                           /* !< (@ 0x00001000) SYSCTL SOCLOCK Region */
       uint32_t RESERVED1[3324];
  SYSCTL_MGMT_ADC12B1MSPS0_Regs  MGMT_ADC12B1MSPS0;                 /* !< (@ 0x00004800) SYSCTL Mgmt sub-region for IPD adc12b1msps0 */
       uint32_t RESERVED2[4090];
  SYSCTL_MGMT_ANACOMP0_Regs  MGMT_ANACOMP0;                     /* !< (@ 0x00008800) SYSCTL Mgmt sub-region for IPD anacomp0 */
       uint32_t RESERVED3[24570];
  SYSCTL_MGMT_OPAMP0_Regs  MGMT_OPAMP0;                       /* !< (@ 0x00020800) SYSCTL Mgmt sub-region for IPD opamp0 */
       uint32_t RESERVED4[2042];
  SYSCTL_MGMT_OPAMP1_Regs  MGMT_OPAMP1;                       /* !< (@ 0x00022800) SYSCTL Mgmt sub-region for IPD opamp1 */
       uint32_t RESERVED5[14330];
  SYSCTL_MGMT_VREF_Regs  MGMT_VREF;                         /* !< (@ 0x00030800) SYSCTL Mgmt sub-region for IPD vref */
       uint32_t RESERVED6[81914];
  SYSCTL_MGMT_WWDTLP0_Regs  MGMT_WWDTLP0;                      /* !< (@ 0x00080800) SYSCTL Mgmt sub-region for IPD wwdtlp0 */
       uint32_t RESERVED7[4090];
  SYSCTL_MGMT_GPTIMER16B2CCLP0_Regs  MGMT_GPTIMER16B2CCLP0;             /* !< (@ 0x00084800) SYSCTL Mgmt sub-region for IPD gptimer16b2cclp0 */
       uint32_t RESERVED8[2042];
  SYSCTL_MGMT_GPTIMER16B2CCLP1_Regs  MGMT_GPTIMER16B2CCLP1;             /* !< (@ 0x00086800) SYSCTL Mgmt sub-region for IPD gptimer16b2cclp1 */
       uint32_t RESERVED9[2042];
  SYSCTL_MGMT_GPTIMER16B2CCLP2_Regs  MGMT_GPTIMER16B2CCLP2;             /* !< (@ 0x00088800) SYSCTL Mgmt sub-region for IPD gptimer16b2cclp2 */
       uint32_t RESERVED10[4090];
  SYSCTL_MGMT_GPTIMER16B2CCSPLP0_Regs  MGMT_GPTIMER16B2CCSPLP0;           /* !< (@ 0x0008C800) SYSCTL Mgmt sub-region for IPD gptimer16b2ccsplp0 */
       uint32_t RESERVED11[20474];
  SYSCTL_MGMT_GPIO0_Regs  MGMT_GPIO0;                        /* !< (@ 0x000A0800) SYSCTL Mgmt sub-region for IPD gpio0 */
       uint32_t RESERVED12[81914];
  SYSCTL_MGMT_I2C0_Regs  MGMT_I2C0;                         /* !< (@ 0x000F0800) SYSCTL Mgmt sub-region for IPD i2c0 */
       uint32_t RESERVED13[2042];
  SYSCTL_MGMT_I2C1_Regs  MGMT_I2C1;                         /* !< (@ 0x000F2800) SYSCTL Mgmt sub-region for IPD i2c1 */
       uint32_t RESERVED14[14330];
  SYSCTL_MGMT_UARTLP0_Regs  MGMT_UARTLP0;                      /* !< (@ 0x00100800) SYSCTL Mgmt sub-region for IPD uartlp0 */
       uint32_t RESERVED15[8186];
  SYSCTL_MGMT_UARTADVLP0_Regs  MGMT_UARTADVLP0;                   /* !< (@ 0x00108800) SYSCTL Mgmt sub-region for IPD uartadvlp0 */
       uint32_t RESERVED16[843770];
  SYSCTL_MGMT_CRC0_Regs  MGMT_CRC0;                         /* !< (@ 0x00440800) SYSCTL Mgmt sub-region for IPD crc0 */
       uint32_t RESERVED17[40954];
  SYSCTL_MGMT_SPI0_Regs  MGMT_SPI0;                         /* !< (@ 0x00468800) SYSCTL Mgmt sub-region for IPD spi0 */
} SYSCTL_Regs;

/*@}*/ /* end of group SYSCTL */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* SYSCTL Register Control Bits
******************************************************************************/

/* SYSCTL_MGMT_SPI0_PWREN Bits */
/* SYSCTL_MGMT_SPI0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_SPI0_PWREN_KEY_OFS           (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_SPI0_PWREN_KEY_MASK          ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_SPI0_PWREN_KEY_UNLOCK        ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_SPI0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_SPI0_PWREN_ENABLE_OFS        (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_SPI0_PWREN_ENABLE_MASK       ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_SPI0_PWREN_ENABLE_DISABLE    ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_SPI0_PWREN_ENABLE_ENABLE     ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_SPI0_RSTCTL Bits */
/* SYSCTL_MGMT_SPI0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_SPI0_RSTCTL_KEY_OFS          (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_SPI0_RSTCTL_KEY_MASK         ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_SPI0_RSTCTL_KEY_UNLOCK       ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_SPI0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_SPI0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_SPI0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_SPI0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_SPI0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_SPI0_RSTCTL_RESETASSERT_OFS  (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_SPI0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_SPI0_RSTCTL_RESETASSERT_DO   ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_SPI0_CLKCFG Bits */
/* SYSCTL_MGMT_SPI0_CLKCFG[KEY] Bits */
#define SYSCTL_MGMT_SPI0_CLKCFG_KEY_OFS          (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_SPI0_CLKCFG_KEY_MASK         ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define SYSCTL_MGMT_SPI0_CLKCFG_KEY_UNLOCK       ((uint32_t)0xA9000000U)
/* SYSCTL_MGMT_SPI0_CLKCFG[BLOCKASYNC] Bits */
#define SYSCTL_MGMT_SPI0_CLKCFG_BLOCKASYNC_OFS   (8)                             /* !< BLOCKASYNC Offset */
#define SYSCTL_MGMT_SPI0_CLKCFG_BLOCKASYNC_MASK  ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define SYSCTL_MGMT_SPI0_CLKCFG_BLOCKASYNC_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_SPI0_CLKCFG_BLOCKASYNC_ENABLE ((uint32_t)0x00000100U)

/* SYSCTL_MGMT_SPI0_STAT Bits */
/* SYSCTL_MGMT_SPI0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_SPI0_STAT_RESETSTKY_OFS      (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_SPI0_STAT_RESETSTKY_MASK     ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_SPI0_STAT_RESETSTKY_CLEAR    ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_SPI0_STAT_RESETSTKY_SET      ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_CRC0_PWREN Bits */
/* SYSCTL_MGMT_CRC0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_CRC0_PWREN_KEY_OFS           (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_CRC0_PWREN_KEY_MASK          ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_CRC0_PWREN_KEY_UNLOCK        ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_CRC0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_CRC0_PWREN_ENABLE_OFS        (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_CRC0_PWREN_ENABLE_MASK       ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_CRC0_PWREN_ENABLE_DISABLE    ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_CRC0_PWREN_ENABLE_ENABLE     ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_CRC0_RSTCTL Bits */
/* SYSCTL_MGMT_CRC0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_CRC0_RSTCTL_KEY_OFS          (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_CRC0_RSTCTL_KEY_MASK         ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_CRC0_RSTCTL_KEY_UNLOCK       ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_CRC0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_CRC0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_CRC0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_CRC0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_CRC0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_CRC0_RSTCTL_RESETASSERT_OFS  (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_CRC0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_CRC0_RSTCTL_RESETASSERT_DO   ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_CRC0_STAT Bits */
/* SYSCTL_MGMT_CRC0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_CRC0_STAT_RESETSTKY_OFS      (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_CRC0_STAT_RESETSTKY_MASK     ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_CRC0_STAT_RESETSTKY_CLEAR    ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_CRC0_STAT_RESETSTKY_SET      ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_UARTADVLP0_PWREN Bits */
/* SYSCTL_MGMT_UARTADVLP0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_UARTADVLP0_PWREN_KEY_OFS     (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_UARTADVLP0_PWREN_KEY_MASK    ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_UARTADVLP0_PWREN_KEY_UNLOCK  ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_UARTADVLP0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_UARTADVLP0_PWREN_ENABLE_OFS  (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_UARTADVLP0_PWREN_ENABLE_MASK ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_UARTADVLP0_PWREN_ENABLE_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_UARTADVLP0_PWREN_ENABLE_ENABLE ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_UARTADVLP0_RSTCTL Bits */
/* SYSCTL_MGMT_UARTADVLP0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_UARTADVLP0_RSTCTL_KEY_OFS    (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_UARTADVLP0_RSTCTL_KEY_MASK   ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_UARTADVLP0_RSTCTL_KEY_UNLOCK ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_UARTADVLP0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_UARTADVLP0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_UARTADVLP0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_UARTADVLP0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_UARTADVLP0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_UARTADVLP0_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_UARTADVLP0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_UARTADVLP0_RSTCTL_RESETASSERT_DO ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_UARTADVLP0_CLKCFG Bits */
/* SYSCTL_MGMT_UARTADVLP0_CLKCFG[KEY] Bits */
#define SYSCTL_MGMT_UARTADVLP0_CLKCFG_KEY_OFS    (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_UARTADVLP0_CLKCFG_KEY_MASK   ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define SYSCTL_MGMT_UARTADVLP0_CLKCFG_KEY_UNLOCK ((uint32_t)0xA9000000U)
/* SYSCTL_MGMT_UARTADVLP0_CLKCFG[BLOCKASYNC] Bits */
#define SYSCTL_MGMT_UARTADVLP0_CLKCFG_BLOCKASYNC_OFS (8)                             /* !< BLOCKASYNC Offset */
#define SYSCTL_MGMT_UARTADVLP0_CLKCFG_BLOCKASYNC_MASK ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define SYSCTL_MGMT_UARTADVLP0_CLKCFG_BLOCKASYNC_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_UARTADVLP0_CLKCFG_BLOCKASYNC_ENABLE ((uint32_t)0x00000100U)

/* SYSCTL_MGMT_UARTADVLP0_STAT Bits */
/* SYSCTL_MGMT_UARTADVLP0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_UARTADVLP0_STAT_RESETSTKY_OFS (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_UARTADVLP0_STAT_RESETSTKY_MASK ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_UARTADVLP0_STAT_RESETSTKY_CLEAR ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_UARTADVLP0_STAT_RESETSTKY_SET ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_UARTLP0_PWREN Bits */
/* SYSCTL_MGMT_UARTLP0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_UARTLP0_PWREN_KEY_OFS        (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_UARTLP0_PWREN_KEY_MASK       ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_UARTLP0_PWREN_KEY_UNLOCK     ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_UARTLP0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_UARTLP0_PWREN_ENABLE_OFS     (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_UARTLP0_PWREN_ENABLE_MASK    ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_UARTLP0_PWREN_ENABLE_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_UARTLP0_PWREN_ENABLE_ENABLE  ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_UARTLP0_RSTCTL Bits */
/* SYSCTL_MGMT_UARTLP0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_UARTLP0_RSTCTL_KEY_OFS       (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_UARTLP0_RSTCTL_KEY_MASK      ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_UARTLP0_RSTCTL_KEY_UNLOCK    ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_UARTLP0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_UARTLP0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_UARTLP0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_UARTLP0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_UARTLP0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_UARTLP0_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_UARTLP0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_UARTLP0_RSTCTL_RESETASSERT_DO ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_UARTLP0_CLKCFG Bits */
/* SYSCTL_MGMT_UARTLP0_CLKCFG[KEY] Bits */
#define SYSCTL_MGMT_UARTLP0_CLKCFG_KEY_OFS       (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_UARTLP0_CLKCFG_KEY_MASK      ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define SYSCTL_MGMT_UARTLP0_CLKCFG_KEY_UNLOCK    ((uint32_t)0xA9000000U)
/* SYSCTL_MGMT_UARTLP0_CLKCFG[BLOCKASYNC] Bits */
#define SYSCTL_MGMT_UARTLP0_CLKCFG_BLOCKASYNC_OFS (8)                             /* !< BLOCKASYNC Offset */
#define SYSCTL_MGMT_UARTLP0_CLKCFG_BLOCKASYNC_MASK ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define SYSCTL_MGMT_UARTLP0_CLKCFG_BLOCKASYNC_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_UARTLP0_CLKCFG_BLOCKASYNC_ENABLE ((uint32_t)0x00000100U)

/* SYSCTL_MGMT_UARTLP0_STAT Bits */
/* SYSCTL_MGMT_UARTLP0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_UARTLP0_STAT_RESETSTKY_OFS   (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_UARTLP0_STAT_RESETSTKY_MASK  ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_UARTLP0_STAT_RESETSTKY_CLEAR ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_UARTLP0_STAT_RESETSTKY_SET   ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_I2C1_PWREN Bits */
/* SYSCTL_MGMT_I2C1_PWREN[KEY] Bits */
#define SYSCTL_MGMT_I2C1_PWREN_KEY_OFS           (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_I2C1_PWREN_KEY_MASK          ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_I2C1_PWREN_KEY_UNLOCK        ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_I2C1_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_I2C1_PWREN_ENABLE_OFS        (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_I2C1_PWREN_ENABLE_MASK       ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_I2C1_PWREN_ENABLE_DISABLE    ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_I2C1_PWREN_ENABLE_ENABLE     ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_I2C1_RSTCTL Bits */
/* SYSCTL_MGMT_I2C1_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_I2C1_RSTCTL_KEY_OFS          (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_I2C1_RSTCTL_KEY_MASK         ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_I2C1_RSTCTL_KEY_UNLOCK       ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_I2C1_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_I2C1_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_I2C1_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_I2C1_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_I2C1_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_I2C1_RSTCTL_RESETASSERT_OFS  (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_I2C1_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_I2C1_RSTCTL_RESETASSERT_DO   ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_I2C1_CLKCFG Bits */
/* SYSCTL_MGMT_I2C1_CLKCFG[KEY] Bits */
#define SYSCTL_MGMT_I2C1_CLKCFG_KEY_OFS          (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_I2C1_CLKCFG_KEY_MASK         ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define SYSCTL_MGMT_I2C1_CLKCFG_KEY_UNLOCK       ((uint32_t)0xA9000000U)
/* SYSCTL_MGMT_I2C1_CLKCFG[BLOCKASYNC] Bits */
#define SYSCTL_MGMT_I2C1_CLKCFG_BLOCKASYNC_OFS   (8)                             /* !< BLOCKASYNC Offset */
#define SYSCTL_MGMT_I2C1_CLKCFG_BLOCKASYNC_MASK  ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define SYSCTL_MGMT_I2C1_CLKCFG_BLOCKASYNC_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_I2C1_CLKCFG_BLOCKASYNC_ENABLE ((uint32_t)0x00000100U)

/* SYSCTL_MGMT_I2C1_STAT Bits */
/* SYSCTL_MGMT_I2C1_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_I2C1_STAT_RESETSTKY_OFS      (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_I2C1_STAT_RESETSTKY_MASK     ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_I2C1_STAT_RESETSTKY_CLEAR    ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_I2C1_STAT_RESETSTKY_SET      ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_I2C0_PWREN Bits */
/* SYSCTL_MGMT_I2C0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_I2C0_PWREN_KEY_OFS           (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_I2C0_PWREN_KEY_MASK          ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_I2C0_PWREN_KEY_UNLOCK        ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_I2C0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_I2C0_PWREN_ENABLE_OFS        (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_I2C0_PWREN_ENABLE_MASK       ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_I2C0_PWREN_ENABLE_DISABLE    ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_I2C0_PWREN_ENABLE_ENABLE     ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_I2C0_RSTCTL Bits */
/* SYSCTL_MGMT_I2C0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_I2C0_RSTCTL_KEY_OFS          (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_I2C0_RSTCTL_KEY_MASK         ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_I2C0_RSTCTL_KEY_UNLOCK       ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_I2C0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_I2C0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_I2C0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_I2C0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_I2C0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_I2C0_RSTCTL_RESETASSERT_OFS  (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_I2C0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_I2C0_RSTCTL_RESETASSERT_DO   ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_I2C0_CLKCFG Bits */
/* SYSCTL_MGMT_I2C0_CLKCFG[KEY] Bits */
#define SYSCTL_MGMT_I2C0_CLKCFG_KEY_OFS          (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_I2C0_CLKCFG_KEY_MASK         ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define SYSCTL_MGMT_I2C0_CLKCFG_KEY_UNLOCK       ((uint32_t)0xA9000000U)
/* SYSCTL_MGMT_I2C0_CLKCFG[BLOCKASYNC] Bits */
#define SYSCTL_MGMT_I2C0_CLKCFG_BLOCKASYNC_OFS   (8)                             /* !< BLOCKASYNC Offset */
#define SYSCTL_MGMT_I2C0_CLKCFG_BLOCKASYNC_MASK  ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define SYSCTL_MGMT_I2C0_CLKCFG_BLOCKASYNC_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_I2C0_CLKCFG_BLOCKASYNC_ENABLE ((uint32_t)0x00000100U)

/* SYSCTL_MGMT_I2C0_STAT Bits */
/* SYSCTL_MGMT_I2C0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_I2C0_STAT_RESETSTKY_OFS      (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_I2C0_STAT_RESETSTKY_MASK     ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_I2C0_STAT_RESETSTKY_CLEAR    ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_I2C0_STAT_RESETSTKY_SET      ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_GPIO0_PWREN Bits */
/* SYSCTL_MGMT_GPIO0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_GPIO0_PWREN_KEY_OFS          (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_GPIO0_PWREN_KEY_MASK         ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_GPIO0_PWREN_KEY_UNLOCK       ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_GPIO0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_GPIO0_PWREN_ENABLE_OFS       (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_GPIO0_PWREN_ENABLE_MASK      ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_GPIO0_PWREN_ENABLE_DISABLE   ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_GPIO0_PWREN_ENABLE_ENABLE    ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_GPIO0_RSTCTL Bits */
/* SYSCTL_MGMT_GPIO0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_GPIO0_RSTCTL_KEY_OFS         (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_GPIO0_RSTCTL_KEY_MASK        ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_GPIO0_RSTCTL_KEY_UNLOCK      ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_GPIO0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_GPIO0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_GPIO0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_GPIO0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_GPIO0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_GPIO0_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_GPIO0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_GPIO0_RSTCTL_RESETASSERT_DO  ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_GPIO0_STAT Bits */
/* SYSCTL_MGMT_GPIO0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_GPIO0_STAT_RESETSTKY_OFS     (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_GPIO0_STAT_RESETSTKY_MASK    ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_GPIO0_STAT_RESETSTKY_CLEAR   ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_GPIO0_STAT_RESETSTKY_SET     ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_GPTIMER16B2CCSPLP0_PWREN Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCSPLP0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_PWREN_KEY_OFS (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_PWREN_KEY_MASK ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_PWREN_KEY_UNLOCK ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_GPTIMER16B2CCSPLP0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_PWREN_ENABLE_OFS (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_PWREN_ENABLE_MASK ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_PWREN_ENABLE_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_PWREN_ENABLE_ENABLE ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL_KEY_OFS (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL_KEY_MASK ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL_KEY_UNLOCK ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_RSTCTL_RESETASSERT_DO ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_GPTIMER16B2CCSPLP0_STAT Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCSPLP0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_STAT_RESETSTKY_OFS (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_STAT_RESETSTKY_MASK ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_STAT_RESETSTKY_CLEAR ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_GPTIMER16B2CCSPLP0_STAT_RESETSTKY_SET ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_GPTIMER16B2CCLP2_PWREN Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCLP2_PWREN[KEY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_PWREN_KEY_OFS (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_PWREN_KEY_MASK ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_PWREN_KEY_UNLOCK ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_GPTIMER16B2CCLP2_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_PWREN_ENABLE_OFS (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_PWREN_ENABLE_MASK ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_PWREN_ENABLE_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_PWREN_ENABLE_ENABLE ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL_KEY_OFS (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL_KEY_MASK ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL_KEY_UNLOCK ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_RSTCTL_RESETASSERT_DO ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_GPTIMER16B2CCLP2_STAT Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCLP2_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_STAT_RESETSTKY_OFS (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_STAT_RESETSTKY_MASK ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_STAT_RESETSTKY_CLEAR ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_GPTIMER16B2CCLP2_STAT_RESETSTKY_SET ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_GPTIMER16B2CCLP1_PWREN Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCLP1_PWREN[KEY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_PWREN_KEY_OFS (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_PWREN_KEY_MASK ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_PWREN_KEY_UNLOCK ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_GPTIMER16B2CCLP1_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_PWREN_ENABLE_OFS (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_PWREN_ENABLE_MASK ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_PWREN_ENABLE_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_PWREN_ENABLE_ENABLE ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL_KEY_OFS (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL_KEY_MASK ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL_KEY_UNLOCK ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_RSTCTL_RESETASSERT_DO ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_GPTIMER16B2CCLP1_STAT Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCLP1_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_STAT_RESETSTKY_OFS (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_STAT_RESETSTKY_MASK ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_STAT_RESETSTKY_CLEAR ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_GPTIMER16B2CCLP1_STAT_RESETSTKY_SET ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_GPTIMER16B2CCLP0_PWREN Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCLP0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_PWREN_KEY_OFS (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_PWREN_KEY_MASK ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_PWREN_KEY_UNLOCK ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_GPTIMER16B2CCLP0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_PWREN_ENABLE_OFS (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_PWREN_ENABLE_MASK ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_PWREN_ENABLE_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_PWREN_ENABLE_ENABLE ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL_KEY_OFS (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL_KEY_MASK ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL_KEY_UNLOCK ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_RSTCTL_RESETASSERT_DO ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_GPTIMER16B2CCLP0_STAT Bits */
/* SYSCTL_MGMT_GPTIMER16B2CCLP0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_STAT_RESETSTKY_OFS (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_STAT_RESETSTKY_MASK ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_STAT_RESETSTKY_CLEAR ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_GPTIMER16B2CCLP0_STAT_RESETSTKY_SET ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_WWDTLP0_PWREN Bits */
/* SYSCTL_MGMT_WWDTLP0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_WWDTLP0_PWREN_KEY_OFS        (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_WWDTLP0_PWREN_KEY_MASK       ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_WWDTLP0_PWREN_KEY_UNLOCK     ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_WWDTLP0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_WWDTLP0_PWREN_ENABLE_OFS     (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_WWDTLP0_PWREN_ENABLE_MASK    ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_WWDTLP0_PWREN_ENABLE_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_WWDTLP0_PWREN_ENABLE_ENABLE  ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_WWDTLP0_RSTCTL Bits */
/* SYSCTL_MGMT_WWDTLP0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_WWDTLP0_RSTCTL_KEY_OFS       (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_WWDTLP0_RSTCTL_KEY_MASK      ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_WWDTLP0_RSTCTL_KEY_UNLOCK    ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_WWDTLP0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_WWDTLP0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_WWDTLP0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_WWDTLP0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_WWDTLP0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_WWDTLP0_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_WWDTLP0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_WWDTLP0_RSTCTL_RESETASSERT_DO ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_WWDTLP0_STAT Bits */
/* SYSCTL_MGMT_WWDTLP0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_WWDTLP0_STAT_RESETSTKY_OFS   (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_WWDTLP0_STAT_RESETSTKY_MASK  ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_WWDTLP0_STAT_RESETSTKY_CLEAR ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_WWDTLP0_STAT_RESETSTKY_SET   ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_VREF_PWREN Bits */
/* SYSCTL_MGMT_VREF_PWREN[KEY] Bits */
#define SYSCTL_MGMT_VREF_PWREN_KEY_OFS           (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_VREF_PWREN_KEY_MASK          ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_VREF_PWREN_KEY_UNLOCK        ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_VREF_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_VREF_PWREN_ENABLE_OFS        (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_VREF_PWREN_ENABLE_MASK       ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_VREF_PWREN_ENABLE_DISABLE    ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_VREF_PWREN_ENABLE_ENABLE     ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_VREF_RSTCTL Bits */
/* SYSCTL_MGMT_VREF_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_VREF_RSTCTL_KEY_OFS          (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_VREF_RSTCTL_KEY_MASK         ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_VREF_RSTCTL_KEY_UNLOCK       ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_VREF_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_VREF_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_VREF_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_VREF_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_VREF_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_VREF_RSTCTL_RESETASSERT_OFS  (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_VREF_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_VREF_RSTCTL_RESETASSERT_DO   ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_VREF_STAT Bits */
/* SYSCTL_MGMT_VREF_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_VREF_STAT_RESETSTKY_OFS      (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_VREF_STAT_RESETSTKY_MASK     ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_VREF_STAT_RESETSTKY_CLEAR    ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_VREF_STAT_RESETSTKY_SET      ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_OPAMP1_PWREN Bits */
/* SYSCTL_MGMT_OPAMP1_PWREN[KEY] Bits */
#define SYSCTL_MGMT_OPAMP1_PWREN_KEY_OFS         (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_OPAMP1_PWREN_KEY_MASK        ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_OPAMP1_PWREN_KEY_UNLOCK      ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_OPAMP1_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_OPAMP1_PWREN_ENABLE_OFS      (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_OPAMP1_PWREN_ENABLE_MASK     ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_OPAMP1_PWREN_ENABLE_DISABLE  ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_OPAMP1_PWREN_ENABLE_ENABLE   ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_OPAMP1_RSTCTL Bits */
/* SYSCTL_MGMT_OPAMP1_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_OPAMP1_RSTCTL_KEY_OFS        (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_OPAMP1_RSTCTL_KEY_MASK       ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_OPAMP1_RSTCTL_KEY_UNLOCK     ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_OPAMP1_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_OPAMP1_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_OPAMP1_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_OPAMP1_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_OPAMP1_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_OPAMP1_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_OPAMP1_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_OPAMP1_RSTCTL_RESETASSERT_DO ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_OPAMP1_STAT Bits */
/* SYSCTL_MGMT_OPAMP1_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_OPAMP1_STAT_RESETSTKY_OFS    (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_OPAMP1_STAT_RESETSTKY_MASK   ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_OPAMP1_STAT_RESETSTKY_CLEAR  ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_OPAMP1_STAT_RESETSTKY_SET    ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_OPAMP0_PWREN Bits */
/* SYSCTL_MGMT_OPAMP0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_OPAMP0_PWREN_KEY_OFS         (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_OPAMP0_PWREN_KEY_MASK        ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_OPAMP0_PWREN_KEY_UNLOCK      ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_OPAMP0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_OPAMP0_PWREN_ENABLE_OFS      (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_OPAMP0_PWREN_ENABLE_MASK     ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_OPAMP0_PWREN_ENABLE_DISABLE  ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_OPAMP0_PWREN_ENABLE_ENABLE   ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_OPAMP0_RSTCTL Bits */
/* SYSCTL_MGMT_OPAMP0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_OPAMP0_RSTCTL_KEY_OFS        (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_OPAMP0_RSTCTL_KEY_MASK       ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_OPAMP0_RSTCTL_KEY_UNLOCK     ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_OPAMP0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_OPAMP0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_OPAMP0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_OPAMP0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_OPAMP0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_OPAMP0_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_OPAMP0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_OPAMP0_RSTCTL_RESETASSERT_DO ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_OPAMP0_STAT Bits */
/* SYSCTL_MGMT_OPAMP0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_OPAMP0_STAT_RESETSTKY_OFS    (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_OPAMP0_STAT_RESETSTKY_MASK   ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_OPAMP0_STAT_RESETSTKY_CLEAR  ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_OPAMP0_STAT_RESETSTKY_SET    ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_ANACOMP0_PWREN Bits */
/* SYSCTL_MGMT_ANACOMP0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_ANACOMP0_PWREN_KEY_OFS       (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_ANACOMP0_PWREN_KEY_MASK      ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_ANACOMP0_PWREN_KEY_UNLOCK    ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_ANACOMP0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_ANACOMP0_PWREN_ENABLE_OFS    (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_ANACOMP0_PWREN_ENABLE_MASK   ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_ANACOMP0_PWREN_ENABLE_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_ANACOMP0_PWREN_ENABLE_ENABLE ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_ANACOMP0_RSTCTL Bits */
/* SYSCTL_MGMT_ANACOMP0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_ANACOMP0_RSTCTL_KEY_OFS      (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_ANACOMP0_RSTCTL_KEY_MASK     ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_ANACOMP0_RSTCTL_KEY_UNLOCK   ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_ANACOMP0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_ANACOMP0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_ANACOMP0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_ANACOMP0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_ANACOMP0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_ANACOMP0_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_ANACOMP0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_ANACOMP0_RSTCTL_RESETASSERT_DO ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_ANACOMP0_CLKCFG Bits */
/* SYSCTL_MGMT_ANACOMP0_CLKCFG[KEY] Bits */
#define SYSCTL_MGMT_ANACOMP0_CLKCFG_KEY_OFS      (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_ANACOMP0_CLKCFG_KEY_MASK     ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define SYSCTL_MGMT_ANACOMP0_CLKCFG_KEY_UNLOCK   ((uint32_t)0xA9000000U)
/* SYSCTL_MGMT_ANACOMP0_CLKCFG[BLOCKASYNC] Bits */
#define SYSCTL_MGMT_ANACOMP0_CLKCFG_BLOCKASYNC_OFS (8)                             /* !< BLOCKASYNC Offset */
#define SYSCTL_MGMT_ANACOMP0_CLKCFG_BLOCKASYNC_MASK ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define SYSCTL_MGMT_ANACOMP0_CLKCFG_BLOCKASYNC_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_ANACOMP0_CLKCFG_BLOCKASYNC_ENABLE ((uint32_t)0x00000100U)

/* SYSCTL_MGMT_ANACOMP0_STAT Bits */
/* SYSCTL_MGMT_ANACOMP0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_ANACOMP0_STAT_RESETSTKY_OFS  (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_ANACOMP0_STAT_RESETSTKY_MASK ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_ANACOMP0_STAT_RESETSTKY_CLEAR ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_ANACOMP0_STAT_RESETSTKY_SET  ((uint32_t)0x00010000U)

/* SYSCTL_MGMT_ADC12B1MSPS0_PWREN Bits */
/* SYSCTL_MGMT_ADC12B1MSPS0_PWREN[KEY] Bits */
#define SYSCTL_MGMT_ADC12B1MSPS0_PWREN_KEY_OFS   (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_ADC12B1MSPS0_PWREN_KEY_MASK  ((uint32_t)0xFF000000U)         /* !< KEY to Allow Enable State Change --
                                                                                    0x26 */
#define SYSCTL_MGMT_ADC12B1MSPS0_PWREN_KEY_UNLOCK ((uint32_t)0x26000000U)
/* SYSCTL_MGMT_ADC12B1MSPS0_PWREN[ENABLE] Bits */
#define SYSCTL_MGMT_ADC12B1MSPS0_PWREN_ENABLE_OFS (0)                             /* !< ENABLE Offset */
#define SYSCTL_MGMT_ADC12B1MSPS0_PWREN_ENABLE_MASK ((uint32_t)0x00000001U)         /* !< IP Enable */
#define SYSCTL_MGMT_ADC12B1MSPS0_PWREN_ENABLE_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_ADC12B1MSPS0_PWREN_ENABLE_ENABLE ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL Bits */
/* SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL[KEY] Bits */
#define SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL_KEY_OFS  (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL_KEY_MASK ((uint32_t)0xFF000000U)         /* !< KEY to Allow Reset -- 0xb1 */
#define SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL_KEY_UNLOCK ((uint32_t)0xB1000000U)
/* SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL[RESETSTKYCLR] Bits */
#define SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL_RESETSTKYCLR_OFS (1)                             /* !< RESETSTKYCLR Offset */
#define SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL_RESETSTKYCLR_MASK ((uint32_t)0x00000002U)         /* !< Clear the RESET STICKY Bit */
#define SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL_RESETSTKYCLR_CLEAR ((uint32_t)0x00000002U)
/* SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL[RESETASSERT] Bits */
#define SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL_RESETASSERT_OFS (0)                             /* !< RESETASSERT Offset */
#define SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL_RESETASSERT_MASK ((uint32_t)0x00000001U)         /* !< Assert Reset to IP Domain. */
#define SYSCTL_MGMT_ADC12B1MSPS0_RSTCTL_RESETASSERT_DO ((uint32_t)0x00000001U)

/* SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG Bits */
/* SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG[KEY] Bits */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_KEY_OFS  (24)                            /* !< KEY Offset */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_KEY_MASK ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_KEY_UNLOCK ((uint32_t)0xA9000000U)
/* SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG[CCONSTOP] Bits */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_CCONSTOP_OFS (5)                             /* !< CCONSTOP Offset */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_CCONSTOP_MASK ((uint32_t)0x00000020U)         /* !< Conversion Clock is ON during STOP
                                                                                    Mode */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_CCONSTOP_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_CCONSTOP_ENABLE ((uint32_t)0x00000020U)
/* SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG[CCONRUN] Bits */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_CCONRUN_OFS (4)                             /* !< CCONRUN Offset */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_CCONRUN_MASK ((uint32_t)0x00000010U)         /* !< Conversion Clock is ON during RUN
                                                                                    Mode */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_CCONRUN_DISABLE ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_CCONRUN_ENABLE ((uint32_t)0x00000010U)
/* SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG[SAMPCLK] Bits */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_SAMPCLK_OFS (0)                             /* !< SAMPCLK Offset */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_SAMPCLK_MASK ((uint32_t)0x00000003U)         /* !< Sample Window Clock */
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_SAMPCLK_ULPCLK ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_SAMPCLK_SYSOSC ((uint32_t)0x00000001U)
#define SYSCTL_MGMT_ADC12B1MSPS0_CLKCFG_SAMPCLK_HFCLK ((uint32_t)0x00000002U)

/* SYSCTL_MGMT_ADC12B1MSPS0_STAT Bits */
/* SYSCTL_MGMT_ADC12B1MSPS0_STAT[RESETSTKY] Bits */
#define SYSCTL_MGMT_ADC12B1MSPS0_STAT_RESETSTKY_OFS (16)                            /* !< RESETSTKY Offset */
#define SYSCTL_MGMT_ADC12B1MSPS0_STAT_RESETSTKY_MASK ((uint32_t)0x00010000U)         /* !< IP has been Reset */
#define SYSCTL_MGMT_ADC12B1MSPS0_STAT_RESETSTKY_CLEAR ((uint32_t)0x00000000U)
#define SYSCTL_MGMT_ADC12B1MSPS0_STAT_RESETSTKY_SET ((uint32_t)0x00010000U)

/* SYSCTL_IIDX Bits */
/* SYSCTL_IIDX[STAT] Bits */
#define SYSCTL_IIDX_STAT_OFS                     (0)                             /* !< STAT Offset */
#define SYSCTL_IIDX_STAT_MASK                    ((uint32_t)0x00000003U)         /* !< The SYSCTL interrupt index (IIDX)
                                                                                    register generates a value
                                                                                    corresponding to the highest priority
                                                                                    pending interrupt source.  This value
                                                                                    may be used as an address offset for
                                                                                    fast, deterministic handling in the
                                                                                    interrupt service routine.  A read of
                                                                                    the IIDX register will clear the
                                                                                    corresponding interrupt status in the
                                                                                    RIS and MIS registers. */
#define SYSCTL_IIDX_STAT_NO_INTR                 ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define SYSCTL_IIDX_STAT_LFOSCGOOD               ((uint32_t)0x00000001U)         /* !< LFOSCGOOD interrupt pending */
#define SYSCTL_IIDX_STAT_ANACLKERR               ((uint32_t)0x00000002U)

/* SYSCTL_IMASK Bits */
/* SYSCTL_IMASK[LFOSCGOOD] Bits */
#define SYSCTL_IMASK_LFOSCGOOD_OFS               (0)                             /* !< LFOSCGOOD Offset */
#define SYSCTL_IMASK_LFOSCGOOD_MASK              ((uint32_t)0x00000001U)         /* !< Enable or disable the LFOSCGOOD
                                                                                    interrupt. LFOSCGOOD indicates that
                                                                                    the LFOSC has started successfully. */
#define SYSCTL_IMASK_LFOSCGOOD_DISABLE           ((uint32_t)0x00000000U)         /* !< Interrupt disabled */
#define SYSCTL_IMASK_LFOSCGOOD_ENABLE            ((uint32_t)0x00000001U)         /* !< Interrupt enabled */
/* SYSCTL_IMASK[ANACLKERR] Bits */
#define SYSCTL_IMASK_ANACLKERR_OFS               (1)                             /* !< ANACLKERR Offset */
#define SYSCTL_IMASK_ANACLKERR_MASK              ((uint32_t)0x00000002U)         /* !< Analog Clocking Consistency Error */
#define SYSCTL_IMASK_ANACLKERR_DISABLE           ((uint32_t)0x00000000U)
#define SYSCTL_IMASK_ANACLKERR_ENABLE            ((uint32_t)0x00000002U)

/* SYSCTL_RIS Bits */
/* SYSCTL_RIS[LFOSCGOOD] Bits */
#define SYSCTL_RIS_LFOSCGOOD_OFS                 (0)                             /* !< LFOSCGOOD Offset */
#define SYSCTL_RIS_LFOSCGOOD_MASK                ((uint32_t)0x00000001U)         /* !< Raw status of the LFOSCGOOD
                                                                                    interrupt. */
#define SYSCTL_RIS_LFOSCGOOD_FALSE               ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define SYSCTL_RIS_LFOSCGOOD_TRUE                ((uint32_t)0x00000001U)         /* !< Interrupt pending */
/* SYSCTL_RIS[ANACLKERR] Bits */
#define SYSCTL_RIS_ANACLKERR_OFS                 (1)                             /* !< ANACLKERR Offset */
#define SYSCTL_RIS_ANACLKERR_MASK                ((uint32_t)0x00000002U)         /* !< Analog Clocking Consistency Error */
#define SYSCTL_RIS_ANACLKERR_FALSE               ((uint32_t)0x00000000U)
#define SYSCTL_RIS_ANACLKERR_TRUE                ((uint32_t)0x00000002U)

/* SYSCTL_MIS Bits */
/* SYSCTL_MIS[LFOSCGOOD] Bits */
#define SYSCTL_MIS_LFOSCGOOD_OFS                 (0)                             /* !< LFOSCGOOD Offset */
#define SYSCTL_MIS_LFOSCGOOD_MASK                ((uint32_t)0x00000001U)         /* !< Masked status of the LFOSCGOOD
                                                                                    interrupt. */
#define SYSCTL_MIS_LFOSCGOOD_FALSE               ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define SYSCTL_MIS_LFOSCGOOD_TRUE                ((uint32_t)0x00000001U)         /* !< Interrupt pending */
/* SYSCTL_MIS[ANACLKERR] Bits */
#define SYSCTL_MIS_ANACLKERR_OFS                 (1)                             /* !< ANACLKERR Offset */
#define SYSCTL_MIS_ANACLKERR_MASK                ((uint32_t)0x00000002U)         /* !< Analog Clocking Consistency Error */
#define SYSCTL_MIS_ANACLKERR_FALSE               ((uint32_t)0x00000000U)
#define SYSCTL_MIS_ANACLKERR_TRUE                ((uint32_t)0x00000002U)

/* SYSCTL_ISET Bits */
/* SYSCTL_ISET[LFOSCGOOD] Bits */
#define SYSCTL_ISET_LFOSCGOOD_OFS                (0)                             /* !< LFOSCGOOD Offset */
#define SYSCTL_ISET_LFOSCGOOD_MASK               ((uint32_t)0x00000001U)         /* !< Set the LFOSCGOOD interrupt. */
#define SYSCTL_ISET_LFOSCGOOD_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0h hs no effect */
#define SYSCTL_ISET_LFOSCGOOD_SET                ((uint32_t)0x00000001U)         /* !< Set interrupt */
/* SYSCTL_ISET[ANACLKERR] Bits */
#define SYSCTL_ISET_ANACLKERR_OFS                (1)                             /* !< ANACLKERR Offset */
#define SYSCTL_ISET_ANACLKERR_MASK               ((uint32_t)0x00000002U)         /* !< Analog Clocking Consistency Error */
#define SYSCTL_ISET_ANACLKERR_NO_EFFECT          ((uint32_t)0x00000000U)
#define SYSCTL_ISET_ANACLKERR_SET                ((uint32_t)0x00000002U)

/* SYSCTL_ICLR Bits */
/* SYSCTL_ICLR[LFOSCGOOD] Bits */
#define SYSCTL_ICLR_LFOSCGOOD_OFS                (0)                             /* !< LFOSCGOOD Offset */
#define SYSCTL_ICLR_LFOSCGOOD_MASK               ((uint32_t)0x00000001U)         /* !< Clear the LFOSCGOOD interrupt. */
#define SYSCTL_ICLR_LFOSCGOOD_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0h has no effect */
#define SYSCTL_ICLR_LFOSCGOOD_CLR                ((uint32_t)0x00000001U)         /* !< Clear interrupt */
/* SYSCTL_ICLR[ANACLKERR] Bits */
#define SYSCTL_ICLR_ANACLKERR_OFS                (1)                             /* !< ANACLKERR Offset */
#define SYSCTL_ICLR_ANACLKERR_MASK               ((uint32_t)0x00000002U)         /* !< Analog Clocking Consistency Error */
#define SYSCTL_ICLR_ANACLKERR_NO_EFFECT          ((uint32_t)0x00000000U)
#define SYSCTL_ICLR_ANACLKERR_CLR                ((uint32_t)0x00000002U)

/* SYSCTL_NMIIIDX Bits */
/* SYSCTL_NMIIIDX[STAT] Bits */
#define SYSCTL_NMIIIDX_STAT_OFS                  (0)                             /* !< STAT Offset */
#define SYSCTL_NMIIIDX_STAT_MASK                 ((uint32_t)0x00000003U)         /* !< The NMI interrupt index (NMIIIDX)
                                                                                    register generates a value
                                                                                    corresponding to the highest priority
                                                                                    pending NMI source.  This value may
                                                                                    be used as an address offset for
                                                                                    fast, deterministic handling in the
                                                                                    NMI service routine.  A read of the
                                                                                    NMIIIDX register will clear the
                                                                                    corresponding interrupt status in the
                                                                                    NMIRIS register. */
#define SYSCTL_NMIIIDX_STAT_NO_INTR              ((uint32_t)0x00000000U)         /* !< No NMI pending */
#define SYSCTL_NMIIIDX_STAT_BORLVL               ((uint32_t)0x00000001U)         /* !< BOR Threshold NMI pending */
#define SYSCTL_NMIIIDX_STAT_WWDT0                ((uint32_t)0x00000002U)

/* SYSCTL_NMIRIS Bits */
/* SYSCTL_NMIRIS[BORLVL] Bits */
#define SYSCTL_NMIRIS_BORLVL_OFS                 (0)                             /* !< BORLVL Offset */
#define SYSCTL_NMIRIS_BORLVL_MASK                ((uint32_t)0x00000001U)         /* !< Raw status of the BORLVL NMI */
#define SYSCTL_NMIRIS_BORLVL_FALSE               ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define SYSCTL_NMIRIS_BORLVL_TRUE                ((uint32_t)0x00000001U)         /* !< Interrupt pending */
/* SYSCTL_NMIRIS[WWDT0] Bits */
#define SYSCTL_NMIRIS_WWDT0_OFS                  (1)                             /* !< WWDT0 Offset */
#define SYSCTL_NMIRIS_WWDT0_MASK                 ((uint32_t)0x00000002U)         /* !< Watch Dog 0 Fault */
#define SYSCTL_NMIRIS_WWDT0_FALSE                ((uint32_t)0x00000000U)
#define SYSCTL_NMIRIS_WWDT0_TRUE                 ((uint32_t)0x00000002U)

/* SYSCTL_NMIISET Bits */
/* SYSCTL_NMIISET[BORLVL] Bits */
#define SYSCTL_NMIISET_BORLVL_OFS                (0)                             /* !< BORLVL Offset */
#define SYSCTL_NMIISET_BORLVL_MASK               ((uint32_t)0x00000001U)         /* !< Set the BORLVL NMI */
#define SYSCTL_NMIISET_BORLVL_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0h hs no effect */
#define SYSCTL_NMIISET_BORLVL_SET                ((uint32_t)0x00000001U)         /* !< Set interrupt */
/* SYSCTL_NMIISET[WWDT0] Bits */
#define SYSCTL_NMIISET_WWDT0_OFS                 (1)                             /* !< WWDT0 Offset */
#define SYSCTL_NMIISET_WWDT0_MASK                ((uint32_t)0x00000002U)         /* !< Watch Dog 0 Fault */
#define SYSCTL_NMIISET_WWDT0_NO_EFFECT           ((uint32_t)0x00000000U)
#define SYSCTL_NMIISET_WWDT0_SET                 ((uint32_t)0x00000002U)

/* SYSCTL_NMIICLR Bits */
/* SYSCTL_NMIICLR[BORLVL] Bits */
#define SYSCTL_NMIICLR_BORLVL_OFS                (0)                             /* !< BORLVL Offset */
#define SYSCTL_NMIICLR_BORLVL_MASK               ((uint32_t)0x00000001U)         /* !< Clr the BORLVL NMI */
#define SYSCTL_NMIICLR_BORLVL_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0h hs no effect */
#define SYSCTL_NMIICLR_BORLVL_CLR                ((uint32_t)0x00000001U)         /* !< Clear interrupt */
/* SYSCTL_NMIICLR[WWDT0] Bits */
#define SYSCTL_NMIICLR_WWDT0_OFS                 (1)                             /* !< WWDT0 Offset */
#define SYSCTL_NMIICLR_WWDT0_MASK                ((uint32_t)0x00000002U)         /* !< Watch Dog 0 Fault */
#define SYSCTL_NMIICLR_WWDT0_NO_EFFECT           ((uint32_t)0x00000000U)
#define SYSCTL_NMIICLR_WWDT0_CLR                 ((uint32_t)0x00000002U)

/* SYSCTL_SYSOSCCFG Bits */
/* SYSCTL_SYSOSCCFG[USE4MHZSTOP] Bits */
#define SYSCTL_SYSOSCCFG_USE4MHZSTOP_OFS         (8)                             /* !< USE4MHZSTOP Offset */
#define SYSCTL_SYSOSCCFG_USE4MHZSTOP_MASK        ((uint32_t)0x00000100U)         /* !< USE4MHZSTOP sets the SYSOSC stop
                                                                                    mode frequency policy.  When entering
                                                                                    STOP mode, the SYSOSC frequency may
                                                                                    be automatically switched to 4MHz to
                                                                                    reduce SYSOSC power consumption. */
#define SYSCTL_SYSOSCCFG_USE4MHZSTOP_DISABLE     ((uint32_t)0x00000000U)         /* !< Do not gear shift the SYSOSC to
                                                                                    4MHz in STOP mode */
#define SYSCTL_SYSOSCCFG_USE4MHZSTOP_ENABLE      ((uint32_t)0x00000100U)         /* !< Gear shift SYSOSC to 4MHz in STOP
                                                                                    mode */
/* SYSCTL_SYSOSCCFG[DISABLESTOP] Bits */
#define SYSCTL_SYSOSCCFG_DISABLESTOP_OFS         (9)                             /* !< DISABLESTOP Offset */
#define SYSCTL_SYSOSCCFG_DISABLESTOP_MASK        ((uint32_t)0x00000200U)         /* !< DISABLESTOP sets the SYSOSC stop
                                                                                    mode enable/disable policy.  When
                                                                                    operating in STOP mode, the SYSOSC
                                                                                    may be automatically disabled.  When
                                                                                    set, ULPCLK will run from LFCLK in
                                                                                    STOP mode and SYSOSC will be disabled
                                                                                    to reduce power consumption. */
#define SYSCTL_SYSOSCCFG_DISABLESTOP_DISABLE     ((uint32_t)0x00000000U)         /* !< Do not disable SYSOSC in STOP mode */
#define SYSCTL_SYSOSCCFG_DISABLESTOP_ENABLE      ((uint32_t)0x00000200U)         /* !< Disable SYSOSC in STOP mode and
                                                                                    source ULPCLK from LFCLK */
/* SYSCTL_SYSOSCCFG[BLOCKASYNCALL] Bits */
#define SYSCTL_SYSOSCCFG_BLOCKASYNCALL_OFS       (16)                            /* !< BLOCKASYNCALL Offset */
#define SYSCTL_SYSOSCCFG_BLOCKASYNCALL_MASK      ((uint32_t)0x00010000U)         /* !< BLOCKASYNCALL may be used to mask
                                                                                    block all asynchronous fast clock
                                                                                    requests, preventing hardware from
                                                                                    dynamically changing the active clock
                                                                                    configuration when operating in a
                                                                                    given mode. */
#define SYSCTL_SYSOSCCFG_BLOCKASYNCALL_DISABLE   ((uint32_t)0x00000000U)         /* !< Asynchronous fast clock requests
                                                                                    are controlled by the requesting
                                                                                    peripheral */
#define SYSCTL_SYSOSCCFG_BLOCKASYNCALL_ENABLE    ((uint32_t)0x00010000U)         /* !< All asynchronous fast clock
                                                                                    requests are blocked */
/* SYSCTL_SYSOSCCFG[DISABLE] Bits */
#define SYSCTL_SYSOSCCFG_DISABLE_OFS             (10)                            /* !< DISABLE Offset */
#define SYSCTL_SYSOSCCFG_DISABLE_MASK            ((uint32_t)0x00000400U)         /* !< DISABLE sets the SYSOSC
                                                                                    enable/disable policy.  SYSOSC may be
                                                                                    powered off in RUN, SLEEP, and STOP
                                                                                    modes to reduce power consumption.
                                                                                    When SYSOSC is disabled, MCLK and
                                                                                    ULPCLK are sourced from LFCLK. */
#define SYSCTL_SYSOSCCFG_DISABLE_DISABLE         ((uint32_t)0x00000000U)         /* !< Do not disable SYSOSC */
#define SYSCTL_SYSOSCCFG_DISABLE_ENABLE          ((uint32_t)0x00000400U)         /* !< Disable SYSOSC immediately and
                                                                                    source MCLK and ULPCLK from LFCLK */
/* SYSCTL_SYSOSCCFG[FASTCPUEVENT] Bits */
#define SYSCTL_SYSOSCCFG_FASTCPUEVENT_OFS        (17)                            /* !< FASTCPUEVENT Offset */
#define SYSCTL_SYSOSCCFG_FASTCPUEVENT_MASK       ((uint32_t)0x00020000U)         /* !< FASTCPUEVENT may be used to assert
                                                                                    a fast clock request when an
                                                                                    interrupt is asserted to the CPU,
                                                                                    reducing interrupt latency. */
#define SYSCTL_SYSOSCCFG_FASTCPUEVENT_DISABLE    ((uint32_t)0x00000000U)         /* !< An interrupt to the CPU will not
                                                                                    assert a fast clock request */
#define SYSCTL_SYSOSCCFG_FASTCPUEVENT_ENABLE     ((uint32_t)0x00020000U)         /* !< An interrupt to the CPU will assert
                                                                                    a fast clock request */
/* SYSCTL_SYSOSCCFG[FREQ] Bits */
#define SYSCTL_SYSOSCCFG_FREQ_OFS                (0)                             /* !< FREQ Offset */
#define SYSCTL_SYSOSCCFG_FREQ_MASK               ((uint32_t)0x00000003U)         /* !< Target operating frequency for the
                                                                                    system oscillator (SYSOSC) */
#define SYSCTL_SYSOSCCFG_FREQ_SYSOSCBASE         ((uint32_t)0x00000000U)         /* !< Base frequency (32MHz) */
#define SYSCTL_SYSOSCCFG_FREQ_SYSOSC4M           ((uint32_t)0x00000001U)         /* !< Low frequency (4MHz) */
#define SYSCTL_SYSOSCCFG_FREQ_SYSOSCUSER         ((uint32_t)0x00000002U)         /* !< User-trimmed frequency (16 or 24
                                                                                    MHz) */
#define SYSCTL_SYSOSCCFG_FREQ_SYSOSCTURBO        ((uint32_t)0x00000003U)         /* !< Turbo frequency (48MHz) */

/* SYSCTL_MCLKCFG Bits */
/* SYSCTL_MCLKCFG[USEMFTICK] Bits */
#define SYSCTL_MCLKCFG_USEMFTICK_OFS             (12)                            /* !< USEMFTICK Offset */
#define SYSCTL_MCLKCFG_USEMFTICK_MASK            ((uint32_t)0x00001000U)         /* !< USEMFTICK specifies whether the
                                                                                    4MHz constant-rate clock (MFCLK) to
                                                                                    peripherals is enabled or disabled.
                                                                                    When enabled, MDIV must be disabled
                                                                                    (set to 0h=/1). */
#define SYSCTL_MCLKCFG_USEMFTICK_DISABLE         ((uint32_t)0x00000000U)         /* !< The 4MHz rate MFCLK to peripherals
                                                                                    is enabled */
#define SYSCTL_MCLKCFG_USEMFTICK_ENABLE          ((uint32_t)0x00001000U)         /* !< The 4MHz rate MFCLK to peripherals
                                                                                    is enabled. */
/* SYSCTL_MCLKCFG[MDIV] Bits */
#define SYSCTL_MCLKCFG_MDIV_OFS                  (0)                             /* !< MDIV Offset */
#define SYSCTL_MCLKCFG_MDIV_MASK                 ((uint32_t)0x0000000FU)         /* !< MDIV may be used to divide the MCLK
                                                                                    frequency when MCLK is sourced from
                                                                                    SYSOSC.  MDIV=0h corresponds to /1
                                                                                    (no divider).  MDIV=1h corresponds to
                                                                                    /2 (divide-by-2).  MDIV=Fh
                                                                                    corresponds to /16 (divide-by-16).
                                                                                    MDIV may be set between /1 and /16 on
                                                                                    an integer basis. */
/* SYSCTL_MCLKCFG[USELFCLK] Bits */
#define SYSCTL_MCLKCFG_USELFCLK_OFS              (20)                            /* !< USELFCLK Offset */
#define SYSCTL_MCLKCFG_USELFCLK_MASK             ((uint32_t)0x00100000U)         /* !< USELFCLK sets the MCLK source
                                                                                    policy.  Set USELFCLK to use LFCLK as
                                                                                    the MCLK source.  Note that setting
                                                                                    USELFCLK does not disable SYSOSC, and
                                                                                    SYSOSC remains available for direct
                                                                                    use by analog modules. */
#define SYSCTL_MCLKCFG_USELFCLK_DISABLE          ((uint32_t)0x00000000U)         /* !< MCLK will not use the low frequency
                                                                                    clock (LFCLK) */
#define SYSCTL_MCLKCFG_USELFCLK_ENABLE           ((uint32_t)0x00100000U)         /* !< MCLK will use the low frequency
                                                                                    clock (LFCLK) */
/* SYSCTL_MCLKCFG[STOPCLKSTBY] Bits */
#define SYSCTL_MCLKCFG_STOPCLKSTBY_OFS           (21)                            /* !< STOPCLKSTBY Offset */
#define SYSCTL_MCLKCFG_STOPCLKSTBY_MASK          ((uint32_t)0x00200000U)         /* !< STOPCLKSTBY sets the STANDBY mode
                                                                                    policy (STANDBY0 or STANDBY1).  When
                                                                                    set, ULPCLK and LFCLK are disabled to
                                                                                    all peripherals in STANDBY mode, with
                                                                                    the exception of TIMG0 and TIMG1
                                                                                    which continue to run.  Wake-up is
                                                                                    only possible via an asynchronous
                                                                                    fast clock request. */
#define SYSCTL_MCLKCFG_STOPCLKSTBY_DISABLE       ((uint32_t)0x00000000U)         /* !< ULPCLK/LFCLK runs to all PD0
                                                                                    peripherals in STANDBY mode */
#define SYSCTL_MCLKCFG_STOPCLKSTBY_ENABLE        ((uint32_t)0x00200000U)         /* !< ULPCLK/LFCLK is disabled to all
                                                                                    peripherals in STANDBY mode except
                                                                                    TIMG0 and TIMG1 */
/* SYSCTL_MCLKCFG[FLASHWAIT] Bits */
#define SYSCTL_MCLKCFG_FLASHWAIT_OFS             (8)                             /* !< FLASHWAIT Offset */
#define SYSCTL_MCLKCFG_FLASHWAIT_MASK            ((uint32_t)0x00000F00U)         /* !< FLASHWAIT specifies the number of
                                                                                    flash wait states when MCLK is
                                                                                    sourced from HSCLK.  FLASHWAIT has no
                                                                                    effect when MCLK is sourced from
                                                                                    SYSOSC or LFCLK. */
#define SYSCTL_MCLKCFG_FLASHWAIT_WAIT0           ((uint32_t)0x00000000U)         /* !< No flash wait states are applied */
#define SYSCTL_MCLKCFG_FLASHWAIT_WAIT1           ((uint32_t)0x00000100U)         /* !< One flash wait state is applied */
#define SYSCTL_MCLKCFG_FLASHWAIT_WAIT2           ((uint32_t)0x00000200U)         /* !< 2 flash wait states are applied */
/* SYSCTL_MCLKCFG[MCLKDEADCHK] Bits */
#define SYSCTL_MCLKCFG_MCLKDEADCHK_OFS           (22)                            /* !< MCLKDEADCHK Offset */
#define SYSCTL_MCLKCFG_MCLKDEADCHK_MASK          ((uint32_t)0x00400000U)         /* !< MCLKDEADCHK enables or disables the
                                                                                    continuous MCLK dead check monitor.
                                                                                    LFCLK must be running before
                                                                                    MCLKDEADCHK is enabled. */
#define SYSCTL_MCLKCFG_MCLKDEADCHK_DISABLE       ((uint32_t)0x00000000U)         /* !< The MCLK dead check monitor is
                                                                                    disabled */
#define SYSCTL_MCLKCFG_MCLKDEADCHK_ENABLE        ((uint32_t)0x00400000U)         /* !< The MCLK dead check monitor is
                                                                                    enabled */

/* SYSCTL_GENCLKCFG Bits */
/* SYSCTL_GENCLKCFG[FCCTRIGCNT] Bits */
#define SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS          (24)                            /* !< FCCTRIGCNT Offset */
#define SYSCTL_GENCLKCFG_FCCTRIGCNT_MASK         ((uint32_t)0x1F000000U)         /* !< FCCTRIGCNT specifies the number of
                                                                                    trigger clock periods in the trigger
                                                                                    window. FCCTRIGCNT=0h (one trigger
                                                                                    clock period) up to 1Fh (32 trigger
                                                                                    clock periods) may be specified. */
/* SYSCTL_GENCLKCFG[ANACPUMPCFG] Bits */
#define SYSCTL_GENCLKCFG_ANACPUMPCFG_OFS         (22)                            /* !< ANACPUMPCFG Offset */
#define SYSCTL_GENCLKCFG_ANACPUMPCFG_MASK        ((uint32_t)0x00C00000U)         /* !< ANACPUMPCFG selects the analog mux
                                                                                    charge pump (VBOOST) enable method. */
#define SYSCTL_GENCLKCFG_ANACPUMPCFG_ONDEMAND    ((uint32_t)0x00000000U)         /* !< VBOOST is enabled on request from a
                                                                                    COMP, GPAMP, or OPA */
#define SYSCTL_GENCLKCFG_ANACPUMPCFG_ONACTIVE    ((uint32_t)0x00400000U)         /* !< VBOOST is enabled when the device
                                                                                    is in RUN or SLEEP mode, or when a
                                                                                    COMP/GPAMP/OPA is enabled */
#define SYSCTL_GENCLKCFG_ANACPUMPCFG_ONALWAYS    ((uint32_t)0x00800000U)         /* !< VBOOST is always enabled */
/* SYSCTL_GENCLKCFG[FCCSELCLK] Bits */
#define SYSCTL_GENCLKCFG_FCCSELCLK_OFS           (16)                            /* !< FCCSELCLK Offset */
#define SYSCTL_GENCLKCFG_FCCSELCLK_MASK          ((uint32_t)0x000F0000U)         /* !< FCCSELCLK selectes the frequency
                                                                                    clock counter (FCC) clock source. */
#define SYSCTL_GENCLKCFG_FCCSELCLK_MCLK          ((uint32_t)0x00000000U)         /* !< FCC clock is MCLK */
#define SYSCTL_GENCLKCFG_FCCSELCLK_SYSOSC        ((uint32_t)0x00010000U)         /* !< FCC clock is SYSOSC */
#define SYSCTL_GENCLKCFG_FCCSELCLK_EXTCLK        ((uint32_t)0x00030000U)         /* !< FCC clock is the CLK_OUT selection */
#define SYSCTL_GENCLKCFG_FCCSELCLK_FCCIN         ((uint32_t)0x00070000U)         /* !< FCC clock is the FCCIN external
                                                                                    input */
/* SYSCTL_GENCLKCFG[FCCTRIGSRC] Bits */
#define SYSCTL_GENCLKCFG_FCCTRIGSRC_OFS          (20)                            /* !< FCCTRIGSRC Offset */
#define SYSCTL_GENCLKCFG_FCCTRIGSRC_MASK         ((uint32_t)0x00100000U)         /* !< FCCTRIGSRC selects the frequency
                                                                                    clock counter (FCC) trigger source. */
#define SYSCTL_GENCLKCFG_FCCTRIGSRC_EXTPIN       ((uint32_t)0x00000000U)         /* !< FCC trigger is the external pin */
#define SYSCTL_GENCLKCFG_FCCTRIGSRC_LFCLK        ((uint32_t)0x00100000U)         /* !< FCC trigger is the LFCLK */
/* SYSCTL_GENCLKCFG[FCCLVLTRIG] Bits */
#define SYSCTL_GENCLKCFG_FCCLVLTRIG_OFS          (21)                            /* !< FCCLVLTRIG Offset */
#define SYSCTL_GENCLKCFG_FCCLVLTRIG_MASK         ((uint32_t)0x00200000U)         /* !< FCCLVLTRIG selects the frequency
                                                                                    clock counter (FCC) trigger mode. */
#define SYSCTL_GENCLKCFG_FCCLVLTRIG_RISE2RISE    ((uint32_t)0x00000000U)         /* !< Rising edge to rising edge
                                                                                    triggered */
#define SYSCTL_GENCLKCFG_FCCLVLTRIG_LEVEL        ((uint32_t)0x00200000U)         /* !< Level triggered */
/* SYSCTL_GENCLKCFG[EXCLKSRC] Bits */
#define SYSCTL_GENCLKCFG_EXCLKSRC_OFS            (0)                             /* !< EXCLKSRC Offset */
#define SYSCTL_GENCLKCFG_EXCLKSRC_MASK           ((uint32_t)0x00000007U)         /* !< EXCLKSRC selects the source for the
                                                                                    CLK_OUT external clock output block.
                                                                                    ULPCLK and MFPCLK require the CLK_OUT
                                                                                    divider (EXCLKDIVEN) to be enabled */
#define SYSCTL_GENCLKCFG_EXCLKSRC_SYSOSC         ((uint32_t)0x00000000U)         /* !< CLK_OUT is SYSOSC */
#define SYSCTL_GENCLKCFG_EXCLKSRC_ULPCLK         ((uint32_t)0x00000001U)         /* !< CLK_OUT is ULPCLK (EXCLKDIVEN must
                                                                                    be enabled) */
#define SYSCTL_GENCLKCFG_EXCLKSRC_LFCLK          ((uint32_t)0x00000002U)         /* !< CLK_OUT is LFCLK */
#define SYSCTL_GENCLKCFG_EXCLKSRC_MFPCLK         ((uint32_t)0x00000003U)         /* !< CLK_OUT is MFPCLK (EXCLKDIVEN must
                                                                                    be enabled) */
/* SYSCTL_GENCLKCFG[EXCLKDIVVAL] Bits */
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_OFS         (4)                             /* !< EXCLKDIVVAL Offset */
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_MASK        ((uint32_t)0x00000070U)         /* !< EXCLKDIVVAL selects the divider
                                                                                    value for the divider in the CLK_OUT
                                                                                    external clock output block. */
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV2        ((uint32_t)0x00000000U)         /* !< CLK_OUT source is divided by 2 */
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV4        ((uint32_t)0x00000010U)         /* !< CLK_OUT source is divided by 4 */
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV6        ((uint32_t)0x00000020U)         /* !< CLK_OUT source is divided by 6 */
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV8        ((uint32_t)0x00000030U)         /* !< CLK_OUT source is divided by 8 */
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV10       ((uint32_t)0x00000040U)         /* !< CLK_OUT source is divided by 10 */
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV12       ((uint32_t)0x00000050U)         /* !< CLK_OUT source is divided by 12 */
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV14       ((uint32_t)0x00000060U)         /* !< CLK_OUT source is divided by 14 */
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV16       ((uint32_t)0x00000070U)         /* !< CLK_OUT source is divided by 16 */
/* SYSCTL_GENCLKCFG[EXCLKDIVEN] Bits */
#define SYSCTL_GENCLKCFG_EXCLKDIVEN_OFS          (7)                             /* !< EXCLKDIVEN Offset */
#define SYSCTL_GENCLKCFG_EXCLKDIVEN_MASK         ((uint32_t)0x00000080U)         /* !< EXCLKDIVEN enables or disables the
                                                                                    divider function of the CLK_OUT
                                                                                    external clock output block. */
#define SYSCTL_GENCLKCFG_EXCLKDIVEN_PASSTHRU     ((uint32_t)0x00000000U)         /* !< CLock divider is disabled
                                                                                    (passthrough, EXCLKDIVVAL is not
                                                                                    applied) */
#define SYSCTL_GENCLKCFG_EXCLKDIVEN_ENABLE       ((uint32_t)0x00000080U)         /* !< Clock divider is enabled
                                                                                    (EXCLKDIVVAL is applied) */

/* SYSCTL_GENCLKEN Bits */
/* SYSCTL_GENCLKEN[EXCLKEN] Bits */
#define SYSCTL_GENCLKEN_EXCLKEN_OFS              (0)                             /* !< EXCLKEN Offset */
#define SYSCTL_GENCLKEN_EXCLKEN_MASK             ((uint32_t)0x00000001U)         /* !< EXCLKEN enables the CLK_OUT
                                                                                    external clock output block. */
#define SYSCTL_GENCLKEN_EXCLKEN_DISABLE          ((uint32_t)0x00000000U)         /* !< CLK_OUT block is disabled */
#define SYSCTL_GENCLKEN_EXCLKEN_ENABLE           ((uint32_t)0x00000001U)         /* !< CLK_OUT block is enabled */
/* SYSCTL_GENCLKEN[MFPCLKEN] Bits */
#define SYSCTL_GENCLKEN_MFPCLKEN_OFS             (4)                             /* !< MFPCLKEN Offset */
#define SYSCTL_GENCLKEN_MFPCLKEN_MASK            ((uint32_t)0x00000010U)         /* !< MFPCLKEN enables the middle
                                                                                    frequency precision clock (MFPCLK). */
#define SYSCTL_GENCLKEN_MFPCLKEN_DISABLE         ((uint32_t)0x00000000U)         /* !< MFPCLK is disabled */
#define SYSCTL_GENCLKEN_MFPCLKEN_ENABLE          ((uint32_t)0x00000010U)         /* !< MFPCLK is enabled */

/* SYSCTL_PMODECFG Bits */
/* SYSCTL_PMODECFG[SYSSRAMONSTOP] Bits */
#define SYSCTL_PMODECFG_SYSSRAMONSTOP_OFS        (5)                             /* !< SYSSRAMONSTOP Offset */
#define SYSCTL_PMODECFG_SYSSRAMONSTOP_MASK       ((uint32_t)0x00000020U)         /* !< SYSSRAMONSTOP selects whether the
                                                                                    SRAM controller is enabled or
                                                                                    disabled in STOP mode. */
#define SYSCTL_PMODECFG_SYSSRAMONSTOP_DISABLE    ((uint32_t)0x00000000U)         /* !< SRAM controller is disabled in STOP
                                                                                    mode (lower power consumption) */
#define SYSCTL_PMODECFG_SYSSRAMONSTOP_ENABLE     ((uint32_t)0x00000020U)         /* !< SRAM controller is left enabled in
                                                                                    STOP mode (faster wake-up) */
/* SYSCTL_PMODECFG[DSLEEP] Bits */
#define SYSCTL_PMODECFG_DSLEEP_OFS               (0)                             /* !< DSLEEP Offset */
#define SYSCTL_PMODECFG_DSLEEP_MASK              ((uint32_t)0x00000003U)         /* !< DSLEEP selects the operating mode
                                                                                    to enter upon a DEEPSLEEP request
                                                                                    from the CPU. */
#define SYSCTL_PMODECFG_DSLEEP_STOP              ((uint32_t)0x00000000U)         /* !< STOP mode is entered */
#define SYSCTL_PMODECFG_DSLEEP_STANDBY           ((uint32_t)0x00000001U)         /* !< STANDBY mode is entered */
#define SYSCTL_PMODECFG_DSLEEP_SHUTDOWN          ((uint32_t)0x00000002U)         /* !< SHUTDOWN mode is entered */

/* SYSCTL_FCC Bits */
/* SYSCTL_FCC[DATA] Bits */
#define SYSCTL_FCC_DATA_OFS                      (0)                             /* !< DATA Offset */
#define SYSCTL_FCC_DATA_MASK                     ((uint32_t)0x003FFFFFU)         /* !< Frequency clock counter (FCC) count
                                                                                    value. */

/* SYSCTL_SYSOSCTRIMUSER Bits */
/* SYSCTL_SYSOSCTRIMUSER[RESCOARSE] Bits */
#define SYSCTL_SYSOSCTRIMUSER_RESCOARSE_OFS      (8)                             /* !< RESCOARSE Offset */
#define SYSCTL_SYSOSCTRIMUSER_RESCOARSE_MASK     ((uint32_t)0x00003F00U)         /* !< RESCOARSE specifies the resister
                                                                                    coarse trim.  This value changes with
                                                                                    the target frequency. */
/* SYSCTL_SYSOSCTRIMUSER[RESFINE] Bits */
#define SYSCTL_SYSOSCTRIMUSER_RESFINE_OFS        (16)                            /* !< RESFINE Offset */
#define SYSCTL_SYSOSCTRIMUSER_RESFINE_MASK       ((uint32_t)0x000F0000U)         /* !< RESFINE specifies the resister fine
                                                                                    trim.  This value changes with the
                                                                                    target frequency. */
/* SYSCTL_SYSOSCTRIMUSER[RDIV] Bits */
#define SYSCTL_SYSOSCTRIMUSER_RDIV_OFS           (20)                            /* !< RDIV Offset */
#define SYSCTL_SYSOSCTRIMUSER_RDIV_MASK          ((uint32_t)0x1FF00000U)         /* !< RDIV specifies the frequency
                                                                                    correction loop (FCL) resistor trim.
                                                                                    This value changes with the target
                                                                                    frequency. */
/* SYSCTL_SYSOSCTRIMUSER[FREQ] Bits */
#define SYSCTL_SYSOSCTRIMUSER_FREQ_OFS           (0)                             /* !< FREQ Offset */
#define SYSCTL_SYSOSCTRIMUSER_FREQ_MASK          ((uint32_t)0x00000003U)         /* !< FREQ specifies the target
                                                                                    user-trimmed frequency for SYSOSC. */
#define SYSCTL_SYSOSCTRIMUSER_FREQ_SYSOSC16M     ((uint32_t)0x00000001U)         /* !< 16MHz user frequency */
#define SYSCTL_SYSOSCTRIMUSER_FREQ_SYSOSC24M     ((uint32_t)0x00000002U)         /* !< 24MHz user frequency */
/* SYSCTL_SYSOSCTRIMUSER[CAP] Bits */
#define SYSCTL_SYSOSCTRIMUSER_CAP_OFS            (4)                             /* !< CAP Offset */
#define SYSCTL_SYSOSCTRIMUSER_CAP_MASK           ((uint32_t)0x00000070U)         /* !< CAP specifies the SYSOSC capacitor
                                                                                    trim.  This value changes with the
                                                                                    target frequency. */

/* SYSCTL_SRAMBOUNDARY Bits */
/* SYSCTL_SRAMBOUNDARY[ADDR] Bits */
#define SYSCTL_SRAMBOUNDARY_ADDR_OFS             (5)                             /* !< ADDR Offset */
#define SYSCTL_SRAMBOUNDARY_ADDR_MASK            ((uint32_t)0x000FFFE0U)         /* !< SRAM boundary configuration. The
                                                                                    value configured into this acts such
                                                                                    that: SRAM accesses to addresses less
                                                                                    than or equal value will be RW only.
                                                                                    SRAM accesses to addresses greater
                                                                                    than value will be RX only. Value of
                                                                                    0 is not valid (system will have no
                                                                                    stack). If set to 0, the system acts
                                                                                    as if the entire SRAM is RWX.  Any
                                                                                    non-zero value can be configured,
                                                                                    including a value = SRAM size. */

/* SYSCTL_SYSTEMCFG Bits */
/* SYSCTL_SYSTEMCFG[KEY] Bits */
#define SYSCTL_SYSTEMCFG_KEY_OFS                 (24)                            /* !< KEY Offset */
#define SYSCTL_SYSTEMCFG_KEY_MASK                ((uint32_t)0xFF000000U)         /* !< The key value of 1Bh (27) must be
                                                                                    written to KEY together with contents
                                                                                    to be updated. Reads as 0 */
#define SYSCTL_SYSTEMCFG_KEY_VALUE               ((uint32_t)0x1B000000U)         /* !< Issue write */
/* SYSCTL_SYSTEMCFG[WWDTLP0RSTDIS] Bits */
#define SYSCTL_SYSTEMCFG_WWDTLP0RSTDIS_OFS       (0)                             /* !< WWDTLP0RSTDIS Offset */
#define SYSCTL_SYSTEMCFG_WWDTLP0RSTDIS_MASK      ((uint32_t)0x00000001U)         /* !< WWDTLP0RSTDIS specifies whether a
                                                                                    WWDT Error Event will trigger a
                                                                                    BOOTRST or an NMI. */
#define SYSCTL_SYSTEMCFG_WWDTLP0RSTDIS_FALSE     ((uint32_t)0x00000000U)         /* !< WWDTLP0 Error Event will trigger a
                                                                                    BOOTRST */
#define SYSCTL_SYSTEMCFG_WWDTLP0RSTDIS_TRUE      ((uint32_t)0x00000001U)         /* !< WWDTLP0 Error Event will trigger an
                                                                                    NMI */

/* SYSCTL_WRITELOCK Bits */
/* SYSCTL_WRITELOCK[ACTIVE] Bits */
#define SYSCTL_WRITELOCK_ACTIVE_OFS              (0)                             /* !< ACTIVE Offset */
#define SYSCTL_WRITELOCK_ACTIVE_MASK             ((uint32_t)0x00000001U)         /* !< ACTIVE controls whether critical
                                                                                    SYSCTL registers are write protected
                                                                                    or not. */
#define SYSCTL_WRITELOCK_ACTIVE_DISABLE          ((uint32_t)0x00000000U)         /* !< Allow writes to lockable registers */
#define SYSCTL_WRITELOCK_ACTIVE_ENABLE           ((uint32_t)0x00000001U)         /* !< Disallow writes to lockable
                                                                                    registers */

/* SYSCTL_CLKSTATUS Bits */
/* SYSCTL_CLKSTATUS[OPAMPCLKERR] Bits */
#define SYSCTL_CLKSTATUS_OPAMPCLKERR_OFS         (30)                            /* !< OPAMPCLKERR Offset */
#define SYSCTL_CLKSTATUS_OPAMPCLKERR_MASK        ((uint32_t)0x40000000U)         /* !< OPAMPCLKERR is set when the device
                                                                                    clock configuration does not support
                                                                                    an enabled OPA mode and the OPA may
                                                                                    not be functioning as expected. */
#define SYSCTL_CLKSTATUS_OPAMPCLKERR_FALSE       ((uint32_t)0x00000000U)         /* !< No OPA clock generation errors
                                                                                    detected */
#define SYSCTL_CLKSTATUS_OPAMPCLKERR_TRUE        ((uint32_t)0x40000000U)         /* !< OPA clock generation error detected */
/* SYSCTL_CLKSTATUS[LFOSCGOOD] Bits */
#define SYSCTL_CLKSTATUS_LFOSCGOOD_OFS           (11)                            /* !< LFOSCGOOD Offset */
#define SYSCTL_CLKSTATUS_LFOSCGOOD_MASK          ((uint32_t)0x00000800U)         /* !< LFOSCGOOD indicates when the LFOSC
                                                                                    startup has completed and the LFOSC
                                                                                    is ready for use. */
#define SYSCTL_CLKSTATUS_LFOSCGOOD_FALSE         ((uint32_t)0x00000000U)         /* !< LFOSC is not ready */
#define SYSCTL_CLKSTATUS_LFOSCGOOD_TRUE          ((uint32_t)0x00000800U)         /* !< LFOSC is ready */
/* SYSCTL_CLKSTATUS[ANACLKERR] Bits */
#define SYSCTL_CLKSTATUS_ANACLKERR_OFS           (31)                            /* !< ANACLKERR Offset */
#define SYSCTL_CLKSTATUS_ANACLKERR_MASK          ((uint32_t)0x80000000U)         /* !< ANACLKERR is set when the device
                                                                                    clock configuration does not support
                                                                                    an enabled analog peripheral mode and
                                                                                    the analog peripheral may not be
                                                                                    functioning as expected. */
#define SYSCTL_CLKSTATUS_ANACLKERR_FALSE         ((uint32_t)0x00000000U)         /* !< No analog clock errors detected */
#define SYSCTL_CLKSTATUS_ANACLKERR_TRUE          ((uint32_t)0x80000000U)         /* !< Analog clock error detected */
/* SYSCTL_CLKSTATUS[LFCLKMUX] Bits */
#define SYSCTL_CLKSTATUS_LFCLKMUX_OFS            (6)                             /* !< LFCLKMUX Offset */
#define SYSCTL_CLKSTATUS_LFCLKMUX_MASK           ((uint32_t)0x000000C0U)         /* !< LFCLKMUX indicates if LFCLK is
                                                                                    sourced from the internal LFOSC, the
                                                                                    low frequency crystal (LFXT), or the
                                                                                    LFCLK_IN digital clock input. */
#define SYSCTL_CLKSTATUS_LFCLKMUX_LFOSC          ((uint32_t)0x00000000U)         /* !< LFCLK is sourced from the internal
                                                                                    LFOSC */
#define SYSCTL_CLKSTATUS_LFCLKMUX_LFXT           ((uint32_t)0x00000040U)         /* !< LFCLK is sourced from the LFXT
                                                                                    (crystal) */
#define SYSCTL_CLKSTATUS_LFCLKMUX_EXLF           ((uint32_t)0x00000080U)         /* !< LFCLK is sourced from LFCLK_IN
                                                                                    (external digital clock  input) */
/* SYSCTL_CLKSTATUS[SYSOSCFREQ] Bits */
#define SYSCTL_CLKSTATUS_SYSOSCFREQ_OFS          (0)                             /* !< SYSOSCFREQ Offset */
#define SYSCTL_CLKSTATUS_SYSOSCFREQ_MASK         ((uint32_t)0x00000003U)         /* !< SYSOSCFREQ indicates the current
                                                                                    SYSOSC operating frequency. */
#define SYSCTL_CLKSTATUS_SYSOSCFREQ_SYSOSC32M    ((uint32_t)0x00000000U)         /* !< SYSOSC is at base frequency (32MHz) */
#define SYSCTL_CLKSTATUS_SYSOSCFREQ_SYSOSC4M     ((uint32_t)0x00000001U)         /* !< SYSOSC is at low frequency (4MHz) */
#define SYSCTL_CLKSTATUS_SYSOSCFREQ_SYSOSCUSER   ((uint32_t)0x00000002U)         /* !< SYSOSC is at the user-trimmed
                                                                                    frequency (16 or 24MHz) */
#define SYSCTL_CLKSTATUS_SYSOSCFREQ_SYSOSCTURBO  ((uint32_t)0x00000003U)         /* !< Reserved */
/* SYSCTL_CLKSTATUS[FCLMODE] Bits */
#define SYSCTL_CLKSTATUS_FCLMODE_OFS             (24)                            /* !< FCLMODE Offset */
#define SYSCTL_CLKSTATUS_FCLMODE_MASK            ((uint32_t)0x01000000U)         /* !< FCLMODE indicates if the SYSOSC
                                                                                    frequency correction loop (FCL) is
                                                                                    enabled. */
#define SYSCTL_CLKSTATUS_FCLMODE_DISABLED        ((uint32_t)0x00000000U)         /* !< SYSOSC FCL is disabled */
#define SYSCTL_CLKSTATUS_FCLMODE_ENABLED         ((uint32_t)0x01000000U)         /* !< SYSOSC FCL is enabled */
/* SYSCTL_CLKSTATUS[CURMCLKSEL] Bits */
#define SYSCTL_CLKSTATUS_CURMCLKSEL_OFS          (17)                            /* !< CURMCLKSEL Offset */
#define SYSCTL_CLKSTATUS_CURMCLKSEL_MASK         ((uint32_t)0x00020000U)         /* !< CURMCLKSEL indicates if MCLK is
                                                                                    currently sourced from LFCLK. */
#define SYSCTL_CLKSTATUS_CURMCLKSEL_NOTLFCLK     ((uint32_t)0x00000000U)         /* !< MCLK is not sourced from LFCLK */
#define SYSCTL_CLKSTATUS_CURMCLKSEL_LFCLK        ((uint32_t)0x00020000U)         /* !< MCLK is sourced from LFCLK */
/* SYSCTL_CLKSTATUS[FCCDONE] Bits */
#define SYSCTL_CLKSTATUS_FCCDONE_OFS             (25)                            /* !< FCCDONE Offset */
#define SYSCTL_CLKSTATUS_FCCDONE_MASK            ((uint32_t)0x02000000U)         /* !< FCCDONE indicates when a frequency
                                                                                    clock counter capture is complete. */
#define SYSCTL_CLKSTATUS_FCCDONE_NOTDONE         ((uint32_t)0x00000000U)         /* !< FCC capture is not done */
#define SYSCTL_CLKSTATUS_FCCDONE_DONE            ((uint32_t)0x02000000U)         /* !< FCC capture is done */

/* SYSCTL_SYSSTATUS Bits */
/* SYSCTL_SYSSTATUS[SHDNIOLOCK] Bits */
#define SYSCTL_SYSSTATUS_SHDNIOLOCK_OFS          (14)                            /* !< SHDNIOLOCK Offset */
#define SYSCTL_SYSSTATUS_SHDNIOLOCK_MASK         ((uint32_t)0x00004000U)         /* !< SHDNIOLOCK indicates when IO is
                                                                                    locked due to SHUTDOWN */
#define SYSCTL_SYSSTATUS_SHDNIOLOCK_FALSE        ((uint32_t)0x00000000U)         /* !< IO IS NOT Locked due to SHUTDOWN */
#define SYSCTL_SYSSTATUS_SHDNIOLOCK_TRUE         ((uint32_t)0x00004000U)         /* !< IO IS Locked due to SHUTDOWN */
/* SYSCTL_SYSSTATUS[EXTRSTPINDIS] Bits */
#define SYSCTL_SYSSTATUS_EXTRSTPINDIS_OFS        (12)                            /* !< EXTRSTPINDIS Offset */
#define SYSCTL_SYSSTATUS_EXTRSTPINDIS_MASK       ((uint32_t)0x00001000U)         /* !< EXTRSTPINDIS indicates when user
                                                                                    has disabled the use of external
                                                                                    reset pin */
#define SYSCTL_SYSSTATUS_EXTRSTPINDIS_FALSE      ((uint32_t)0x00000000U)         /* !< External Reset Pin Enabled */
#define SYSCTL_SYSSTATUS_EXTRSTPINDIS_TRUE       ((uint32_t)0x00001000U)         /* !< External Reset Pin Disabled */
/* SYSCTL_SYSSTATUS[PMUIREFGOOD] Bits */
#define SYSCTL_SYSSTATUS_PMUIREFGOOD_OFS         (6)                             /* !< PMUIREFGOOD Offset */
#define SYSCTL_SYSSTATUS_PMUIREFGOOD_MASK        ((uint32_t)0x00000040U)         /* !< PMUIREFGOOD is set by hardware when
                                                                                    the PMU current reference is ready. */
#define SYSCTL_SYSSTATUS_PMUIREFGOOD_FALSE       ((uint32_t)0x00000000U)         /* !< IREF is not ready */
#define SYSCTL_SYSSTATUS_PMUIREFGOOD_TRUE        ((uint32_t)0x00000040U)         /* !< IREF is ready */
/* SYSCTL_SYSSTATUS[SWDCFGDIS] Bits */
#define SYSCTL_SYSSTATUS_SWDCFGDIS_OFS           (13)                            /* !< SWDCFGDIS Offset */
#define SYSCTL_SYSSTATUS_SWDCFGDIS_MASK          ((uint32_t)0x00002000U)         /* !< SWDCFGDIS indicates when user has
                                                                                    disabled the use of SWD Port */
#define SYSCTL_SYSSTATUS_SWDCFGDIS_FALSE         ((uint32_t)0x00000000U)         /* !< SWD Port Enabled */
#define SYSCTL_SYSSTATUS_SWDCFGDIS_TRUE          ((uint32_t)0x00002000U)         /* !< SWD Port Disabled */
/* SYSCTL_SYSSTATUS[ANACPUMPGOOD] Bits */
#define SYSCTL_SYSSTATUS_ANACPUMPGOOD_OFS        (5)                             /* !< ANACPUMPGOOD Offset */
#define SYSCTL_SYSSTATUS_ANACPUMPGOOD_MASK       ((uint32_t)0x00000020U)         /* !< ANACPUMPGOOD is set by hardware
                                                                                    when the VBOOST analog mux charge
                                                                                    pump is ready. */
#define SYSCTL_SYSSTATUS_ANACPUMPGOOD_FALSE      ((uint32_t)0x00000000U)         /* !< VBOOST is not ready */
#define SYSCTL_SYSSTATUS_ANACPUMPGOOD_TRUE       ((uint32_t)0x00000020U)         /* !< VBOOST is ready */
/* SYSCTL_SYSSTATUS[REBOOTATTEMPTS] Bits */
#define SYSCTL_SYSSTATUS_REBOOTATTEMPTS_OFS      (30)                            /* !< REBOOTATTEMPTS Offset */
#define SYSCTL_SYSSTATUS_REBOOTATTEMPTS_MASK     ((uint32_t)0xC0000000U)         /* !< REBOOTATTEMPTS indicates the number
                                                                                    of boot attempts taken before the
                                                                                    user application starts. */
/* SYSCTL_SYSSTATUS[BORLVL] Bits */
#define SYSCTL_SYSSTATUS_BORLVL_OFS              (4)                             /* !< BORLVL Offset */
#define SYSCTL_SYSSTATUS_BORLVL_MASK             ((uint32_t)0x00000010U)         /* !< BORLVL indicates if a BOR event
                                                                                    occured and the BOR threshold was
                                                                                    switched to BOR0 by hardware. */
#define SYSCTL_SYSSTATUS_BORLVL_FALSE            ((uint32_t)0x00000000U)         /* !< No BOR violation occured */
#define SYSCTL_SYSSTATUS_BORLVL_TRUE             ((uint32_t)0x00000010U)         /* !< A BOR violation occured and the BOR
                                                                                    threshold was switched to BOR0 */
/* SYSCTL_SYSSTATUS[BORCURTHRESHOLD] Bits */
#define SYSCTL_SYSSTATUS_BORCURTHRESHOLD_OFS     (2)                             /* !< BORCURTHRESHOLD Offset */
#define SYSCTL_SYSSTATUS_BORCURTHRESHOLD_MASK    ((uint32_t)0x0000000CU)         /* !< BORCURTHRESHOLD indicates the
                                                                                    active brown-out reset supply monitor
                                                                                    configuration. */
#define SYSCTL_SYSSTATUS_BORCURTHRESHOLD_BORMIN  ((uint32_t)0x00000000U)         /* !< Default minimum threshold; a BOR0-
                                                                                    violation triggers a BOR */
#define SYSCTL_SYSSTATUS_BORCURTHRESHOLD_BORLEVEL1 ((uint32_t)0x00000004U)         /* !< A BOR1- violation generates a
                                                                                    BORLVL interrupt */
#define SYSCTL_SYSSTATUS_BORCURTHRESHOLD_BORLEVEL2 ((uint32_t)0x00000008U)         /* !< A BOR2- violation generates a
                                                                                    BORLVL interrupt */
#define SYSCTL_SYSSTATUS_BORCURTHRESHOLD_BORLEVEL3 ((uint32_t)0x0000000CU)         /* !< A BOR3- violation generates a
                                                                                    BORLVL interrupt */

/* SYSCTL_RSTCAUSE Bits */
/* SYSCTL_RSTCAUSE[ID] Bits */
#define SYSCTL_RSTCAUSE_ID_OFS                   (0)                             /* !< ID Offset */
#define SYSCTL_RSTCAUSE_ID_MASK                  ((uint32_t)0x0000001FU)         /* !< ID is a read-to-clear field which
                                                                                    indicates the lowest level reset
                                                                                    cause since the last read. */
#define SYSCTL_RSTCAUSE_ID_NORST                 ((uint32_t)0x00000000U)         /* !< No reset since last read */
#define SYSCTL_RSTCAUSE_ID_PORHWFAIL             ((uint32_t)0x00000001U)         /* !< POR- violation, SHUTDNSTOREx or PMU
                                                                                    trim parity fault */
#define SYSCTL_RSTCAUSE_ID_POREXNRST             ((uint32_t)0x00000002U)         /* !< NRST triggered POR (&gt;1s hold) */
#define SYSCTL_RSTCAUSE_ID_PORSW                 ((uint32_t)0x00000003U)         /* !< Software triggered POR */
#define SYSCTL_RSTCAUSE_ID_BORSUPPLY             ((uint32_t)0x00000004U)         /* !< BOR0- violation */
#define SYSCTL_RSTCAUSE_ID_BORWAKESHUTDN         ((uint32_t)0x00000005U)         /* !< SHUTDOWN mode exit */
#define SYSCTL_RSTCAUSE_ID_BOOTNONPMUPARITY      ((uint32_t)0x00000008U)         /* !< Non-PMU trim parity fault */
#define SYSCTL_RSTCAUSE_ID_BOOTCLKFAIL           ((uint32_t)0x00000009U)         /* !< Fatal clock failure */
#define SYSCTL_RSTCAUSE_ID_BOOTEXNRST            ((uint32_t)0x0000000CU)         /* !< NRST triggered BOOTRST (&lt;1s
                                                                                    hold) */
#define SYSCTL_RSTCAUSE_ID_BOOTSW                ((uint32_t)0x0000000DU)         /* !< Software triggered BOOTRST */
#define SYSCTL_RSTCAUSE_ID_SYSWWDT0              ((uint32_t)0x0000000EU)         /* !< WWDT0 violation */
#define SYSCTL_RSTCAUSE_ID_SYSBSLEXIT            ((uint32_t)0x00000010U)         /* !< BSL exit */
#define SYSCTL_RSTCAUSE_ID_SYSBSLENTRY           ((uint32_t)0x00000011U)         /* !< BSL entry */
#define SYSCTL_RSTCAUSE_ID_SYSWWDT1              ((uint32_t)0x00000013U)         /* !< WWDT1 violation */
#define SYSCTL_RSTCAUSE_ID_SYSFLASHECC           ((uint32_t)0x00000014U)         /* !< Flash uncorrectable ECC error */
#define SYSCTL_RSTCAUSE_ID_SYSCPULOCK            ((uint32_t)0x00000015U)         /* !< CPULOCK violation */
#define SYSCTL_RSTCAUSE_ID_SYSDBG                ((uint32_t)0x0000001AU)         /* !< Debug triggered SYSRST */
#define SYSCTL_RSTCAUSE_ID_SYSSW                 ((uint32_t)0x0000001BU)         /* !< Software triggered SYSRST */
#define SYSCTL_RSTCAUSE_ID_CPUDBG                ((uint32_t)0x0000001CU)         /* !< Debug triggered CPURST */
#define SYSCTL_RSTCAUSE_ID_CPUSW                 ((uint32_t)0x0000001DU)         /* !< Software triggered CPURST */

/* SYSCTL_RESETLEVEL Bits */
/* SYSCTL_RESETLEVEL[LEVEL] Bits */
#define SYSCTL_RESETLEVEL_LEVEL_OFS              (0)                             /* !< LEVEL Offset */
#define SYSCTL_RESETLEVEL_LEVEL_MASK             ((uint32_t)0x00000007U)         /* !< LEVEL is used to specify the type
                                                                                    of reset to be issued when RESETCMD
                                                                                    is set to generate a software
                                                                                    triggered reset. */
#define SYSCTL_RESETLEVEL_LEVEL_CPU              ((uint32_t)0x00000000U)         /* !< Issue a SYSRST (CPU plus
                                                                                    peripherals only) */
#define SYSCTL_RESETLEVEL_LEVEL_BOOT             ((uint32_t)0x00000001U)         /* !< Issue a BOOTRST (CPU, peripherals,
                                                                                    and boot configuration routine) */
#define SYSCTL_RESETLEVEL_LEVEL_BOOTLOADERENTRY  ((uint32_t)0x00000002U)         /* !< Issue a SYSRST and enter the boot
                                                                                    strap loader (BSL) */
#define SYSCTL_RESETLEVEL_LEVEL_POR              ((uint32_t)0x00000003U)         /* !< Issue a power-on reset (POR) */
#define SYSCTL_RESETLEVEL_LEVEL_BOOTLOADEREXIT   ((uint32_t)0x00000004U)         /* !< Issue a SYSRST and exit the boot
                                                                                    strap loader (BSL) */

/* SYSCTL_RESETCMD Bits */
/* SYSCTL_RESETCMD[KEY] Bits */
#define SYSCTL_RESETCMD_KEY_OFS                  (24)                            /* !< KEY Offset */
#define SYSCTL_RESETCMD_KEY_MASK                 ((uint32_t)0xFF000000U)         /* !< The key value of E4h (228) must be
                                                                                    written to KEY together with GO to
                                                                                    trigger the reset. */
#define SYSCTL_RESETCMD_KEY_VALUE                ((uint32_t)0xE4000000U)         /* !< Issue reset */
/* SYSCTL_RESETCMD[GO] Bits */
#define SYSCTL_RESETCMD_GO_OFS                   (0)                             /* !< GO Offset */
#define SYSCTL_RESETCMD_GO_MASK                  ((uint32_t)0x00000001U)         /* !< Execute the reset specified in
                                                                                    RESETLEVEL.LEVEL.  Must be written
                                                                                    together with the KEY. */
#define SYSCTL_RESETCMD_GO_TRUE                  ((uint32_t)0x00000001U)         /* !< Issue reset */

/* SYSCTL_BORTHRESHOLD Bits */
/* SYSCTL_BORTHRESHOLD[LEVEL] Bits */
#define SYSCTL_BORTHRESHOLD_LEVEL_OFS            (0)                             /* !< LEVEL Offset */
#define SYSCTL_BORTHRESHOLD_LEVEL_MASK           ((uint32_t)0x00000003U)         /* !< LEVEL specifies the desired BOR
                                                                                    threshold and BOR mode. */
#define SYSCTL_BORTHRESHOLD_LEVEL_BORMIN         ((uint32_t)0x00000000U)         /* !< Default minimum threshold; a BOR0-
                                                                                    violation triggers a BOR */
#define SYSCTL_BORTHRESHOLD_LEVEL_BORLEVEL1      ((uint32_t)0x00000001U)         /* !< A BOR1- violation generates a
                                                                                    BORLVL interrupt */
#define SYSCTL_BORTHRESHOLD_LEVEL_BORLEVEL2      ((uint32_t)0x00000002U)         /* !< A BOR2- violation generates a
                                                                                    BORLVL interrupt */
#define SYSCTL_BORTHRESHOLD_LEVEL_BORLEVEL3      ((uint32_t)0x00000003U)         /* !< A BOR3- violation generates a
                                                                                    BORLVL interrupt */

/* SYSCTL_BORCLRCMD Bits */
/* SYSCTL_BORCLRCMD[KEY] Bits */
#define SYSCTL_BORCLRCMD_KEY_OFS                 (24)                            /* !< KEY Offset */
#define SYSCTL_BORCLRCMD_KEY_MASK                ((uint32_t)0xFF000000U)         /* !< The key value of C7h (199) must be
                                                                                    written to KEY together with GO to
                                                                                    trigger the clear and BOR threshold
                                                                                    change. */
#define SYSCTL_BORCLRCMD_KEY_VALUE               ((uint32_t)0xC7000000U)         /* !< Issue clear */
/* SYSCTL_BORCLRCMD[GO] Bits */
#define SYSCTL_BORCLRCMD_GO_OFS                  (0)                             /* !< GO Offset */
#define SYSCTL_BORCLRCMD_GO_MASK                 ((uint32_t)0x00000001U)         /* !< GO clears any prior BOR violation
                                                                                    status indications and attempts to
                                                                                    change the active BOR mode to that
                                                                                    specified in the LEVEL field of the
                                                                                    BORTHRESHOLD register. */
#define SYSCTL_BORCLRCMD_GO_TRUE                 ((uint32_t)0x00000001U)         /* !< Issue clear */

/* SYSCTL_SYSOSCFCLCTL Bits */
/* SYSCTL_SYSOSCFCLCTL[KEY] Bits */
#define SYSCTL_SYSOSCFCLCTL_KEY_OFS              (24)                            /* !< KEY Offset */
#define SYSCTL_SYSOSCFCLCTL_KEY_MASK             ((uint32_t)0xFF000000U)         /* !< The key value of 2Ah (42) must be
                                                                                    written to KEY together with
                                                                                    SETUSEFCL to enable the FCL. */
#define SYSCTL_SYSOSCFCLCTL_KEY_VALUE            ((uint32_t)0x2A000000U)         /* !< Issue Command */
/* SYSCTL_SYSOSCFCLCTL[SETUSEFCL] Bits */
#define SYSCTL_SYSOSCFCLCTL_SETUSEFCL_OFS        (0)                             /* !< SETUSEFCL Offset */
#define SYSCTL_SYSOSCFCLCTL_SETUSEFCL_MASK       ((uint32_t)0x00000001U)         /* !< Set SETUSEFCL to enable the
                                                                                    frequency correction loop in SYSOSC.
                                                                                    Once enabled, this state is locked
                                                                                    until the next BOOTRST. */
#define SYSCTL_SYSOSCFCLCTL_SETUSEFCL_TRUE       ((uint32_t)0x00000001U)         /* !< Enable the SYSOSC FCL */

/* SYSCTL_SHDNIOREL Bits */
/* SYSCTL_SHDNIOREL[KEY] Bits */
#define SYSCTL_SHDNIOREL_KEY_OFS                 (24)                            /* !< KEY Offset */
#define SYSCTL_SHDNIOREL_KEY_MASK                ((uint32_t)0xFF000000U)         /* !< The key value 91h must be written
                                                                                    to KEY together with RELEASE to set
                                                                                    RELEASE. */
#define SYSCTL_SHDNIOREL_KEY_VALUE               ((uint32_t)0x91000000U)         /* !< Issue command */
/* SYSCTL_SHDNIOREL[RELEASE] Bits */
#define SYSCTL_SHDNIOREL_RELEASE_OFS             (0)                             /* !< RELEASE Offset */
#define SYSCTL_SHDNIOREL_RELEASE_MASK            ((uint32_t)0x00000001U)         /* !< Set RELEASE to release the IO after
                                                                                    a SHUTDOWN mode exit. */
#define SYSCTL_SHDNIOREL_RELEASE_TRUE            ((uint32_t)0x00000001U)         /* !< Release IO */

/* SYSCTL_EXRSTPIN Bits */
/* SYSCTL_EXRSTPIN[KEY] Bits */
#define SYSCTL_EXRSTPIN_KEY_OFS                  (24)                            /* !< KEY Offset */
#define SYSCTL_EXRSTPIN_KEY_MASK                 ((uint32_t)0xFF000000U)         /* !< The key value 1Eh must be written
                                                                                    together with DISABLE to disable the
                                                                                    reset function. */
#define SYSCTL_EXRSTPIN_KEY_VALUE                ((uint32_t)0x1E000000U)         /* !< Issue command */
/* SYSCTL_EXRSTPIN[DISABLE] Bits */
#define SYSCTL_EXRSTPIN_DISABLE_OFS              (0)                             /* !< DISABLE Offset */
#define SYSCTL_EXRSTPIN_DISABLE_MASK             ((uint32_t)0x00000001U)         /* !< Set DISABLE to disable the reset
                                                                                    function of the NRST pin.  Once set,
                                                                                    this configuration is locked until
                                                                                    the next POR. */
#define SYSCTL_EXRSTPIN_DISABLE_FALSE            ((uint32_t)0x00000000U)         /* !< Reset function of NRST pin is
                                                                                    enabled */
#define SYSCTL_EXRSTPIN_DISABLE_TRUE             ((uint32_t)0x00000001U)         /* !< Reset function of NRST pin is
                                                                                    disabled */

/* SYSCTL_SYSSTATUSCLR Bits */
/* SYSCTL_SYSSTATUSCLR[KEY] Bits */
#define SYSCTL_SYSSTATUSCLR_KEY_OFS              (24)                            /* !< KEY Offset */
#define SYSCTL_SYSSTATUSCLR_KEY_MASK             ((uint32_t)0xFF000000U)         /* !< The key value CEh (206) must be
                                                                                    written to KEY together with ALLECC
                                                                                    to clear the ECC state. */
#define SYSCTL_SYSSTATUSCLR_KEY_VALUE            ((uint32_t)0xCE000000U)         /* !< Issue command */
/* SYSCTL_SYSSTATUSCLR[ALLECC] Bits */
#define SYSCTL_SYSSTATUSCLR_ALLECC_OFS           (0)                             /* !< ALLECC Offset */
#define SYSCTL_SYSSTATUSCLR_ALLECC_MASK          ((uint32_t)0x00000001U)         /* !< Set ALLECC to clear all ECC related
                                                                                    SYSSTATUS indicators. */
#define SYSCTL_SYSSTATUSCLR_ALLECC_CLEAR         ((uint32_t)0x00000001U)         /* !< Clear ECC error state */

/* SYSCTL_SWDCFG Bits */
/* SYSCTL_SWDCFG[KEY] Bits */
#define SYSCTL_SWDCFG_KEY_OFS                    (24)                            /* !< KEY Offset */
#define SYSCTL_SWDCFG_KEY_MASK                   ((uint32_t)0xFF000000U)         /* !< The key value 62h (98) must be
                                                                                    written to KEY together with DISBALE
                                                                                    to disable the SWD functions. */
#define SYSCTL_SWDCFG_KEY_VALUE                  ((uint32_t)0x62000000U)         /* !< Issue command */
/* SYSCTL_SWDCFG[DISABLE] Bits */
#define SYSCTL_SWDCFG_DISABLE_OFS                (0)                             /* !< DISABLE Offset */
#define SYSCTL_SWDCFG_DISABLE_MASK               ((uint32_t)0x00000001U)         /* !< Set DISABLE to disable the SWD
                                                                                    function on SWD pins, allowing the
                                                                                    SWD pins to be used as GPIO. */
#define SYSCTL_SWDCFG_DISABLE_TRUE               ((uint32_t)0x00000001U)         /* !< Disable SWD function on SWD pins */

/* SYSCTL_FCCCMD Bits */
/* SYSCTL_FCCCMD[KEY] Bits */
#define SYSCTL_FCCCMD_KEY_OFS                    (24)                            /* !< KEY Offset */
#define SYSCTL_FCCCMD_KEY_MASK                   ((uint32_t)0xFF000000U)         /* !< The key value 0Eh (14) must be
                                                                                    written with GO to start a capture. */
#define SYSCTL_FCCCMD_KEY_VALUE                  ((uint32_t)0x0E000000U)         /* !< Issue command */
/* SYSCTL_FCCCMD[GO] Bits */
#define SYSCTL_FCCCMD_GO_OFS                     (0)                             /* !< GO Offset */
#define SYSCTL_FCCCMD_GO_MASK                    ((uint32_t)0x00000001U)         /* !< Set GO to start a capture with the
                                                                                    frequency clock counter (FCC). */
#define SYSCTL_FCCCMD_GO_TRUE                    ((uint32_t)0x00000001U)

/* SYSCTL_PMUOPAMP Bits */
/* SYSCTL_PMUOPAMP[RRI] Bits */
#define SYSCTL_PMUOPAMP_RRI_OFS                  (4)                             /* !< RRI Offset */
#define SYSCTL_PMUOPAMP_RRI_MASK                 ((uint32_t)0x00000030U)         /* !< RRI selects the rail-to-rail input
                                                                                    mode. */
#define SYSCTL_PMUOPAMP_RRI_MODE0                ((uint32_t)0x00000000U)         /* !< PMOS input pairs */
#define SYSCTL_PMUOPAMP_RRI_MODE1                ((uint32_t)0x00000010U)         /* !< NMOS input pairs */
#define SYSCTL_PMUOPAMP_RRI_MODE2                ((uint32_t)0x00000020U)         /* !< Rail-to-rail mode */
#define SYSCTL_PMUOPAMP_RRI_MODE3                ((uint32_t)0x00000030U)         /* !< Rail-to-rail mode */
/* SYSCTL_PMUOPAMP[NSEL] Bits */
#define SYSCTL_PMUOPAMP_NSEL_OFS                 (2)                             /* !< NSEL Offset */
#define SYSCTL_PMUOPAMP_NSEL_MASK                ((uint32_t)0x0000000CU)         /* !< NSEL selects the GPAMP negative
                                                                                    channel input. */
#define SYSCTL_PMUOPAMP_NSEL_SEL0                ((uint32_t)0x00000000U)         /* !< GPAMP_OUT pin connected to negative
                                                                                    channel */
#define SYSCTL_PMUOPAMP_NSEL_SEL1                ((uint32_t)0x00000004U)         /* !< GPAMP_IN- pin connected to negative
                                                                                    channel */
#define SYSCTL_PMUOPAMP_NSEL_SEL2                ((uint32_t)0x00000008U)         /* !< GPAMP_OUT signal connected to
                                                                                    negative channel */
#define SYSCTL_PMUOPAMP_NSEL_SEL3                ((uint32_t)0x0000000CU)         /* !< No channel selected */
/* SYSCTL_PMUOPAMP[CHOPCLKMODE] Bits */
#define SYSCTL_PMUOPAMP_CHOPCLKMODE_OFS          (10)                            /* !< CHOPCLKMODE Offset */
#define SYSCTL_PMUOPAMP_CHOPCLKMODE_MASK         ((uint32_t)0x00000C00U)         /* !< CHOPCLKMODE selects the GPAMP
                                                                                    chopping mode. */
#define SYSCTL_PMUOPAMP_CHOPCLKMODE_CHOPDISABLED ((uint32_t)0x00000000U)         /* !< Chopping disabled */
#define SYSCTL_PMUOPAMP_CHOPCLKMODE_REGCHOP      ((uint32_t)0x00000400U)         /* !< Normal chopping */
#define SYSCTL_PMUOPAMP_CHOPCLKMODE_ADCASSIST    ((uint32_t)0x00000800U)         /* !< ADC Assisted chopping */
/* SYSCTL_PMUOPAMP[OUTENABLE] Bits */
#define SYSCTL_PMUOPAMP_OUTENABLE_OFS            (6)                             /* !< OUTENABLE Offset */
#define SYSCTL_PMUOPAMP_OUTENABLE_MASK           ((uint32_t)0x00000040U)         /* !< Set OUTENABLE to connect the GPAMP
                                                                                    output signal to the GPAMP_OUT pin */
#define SYSCTL_PMUOPAMP_OUTENABLE_FALSE          ((uint32_t)0x00000000U)         /* !< GPAMP_OUT signal is not connected
                                                                                    to the GPAMP_OUT pin */
#define SYSCTL_PMUOPAMP_OUTENABLE_TRUE           ((uint32_t)0x00000040U)         /* !< GPAMP_OUT signal is connected to
                                                                                    the GPAMP_OUT pin */
/* SYSCTL_PMUOPAMP[ENABLE] Bits */
#define SYSCTL_PMUOPAMP_ENABLE_OFS               (0)                             /* !< ENABLE Offset */
#define SYSCTL_PMUOPAMP_ENABLE_MASK              ((uint32_t)0x00000001U)         /* !< Set ENABLE to turn on the GPAMP. */
#define SYSCTL_PMUOPAMP_ENABLE_FALSE             ((uint32_t)0x00000000U)         /* !< GPAMP is disabled */
#define SYSCTL_PMUOPAMP_ENABLE_TRUE              ((uint32_t)0x00000001U)         /* !< GPAMP is enabled */
/* SYSCTL_PMUOPAMP[CHOPCLKFREQ] Bits */
#define SYSCTL_PMUOPAMP_CHOPCLKFREQ_OFS          (8)                             /* !< CHOPCLKFREQ Offset */
#define SYSCTL_PMUOPAMP_CHOPCLKFREQ_MASK         ((uint32_t)0x00000300U)         /* !< CHOPCLKFREQ selects the GPAMP
                                                                                    chopping clock frequency */
#define SYSCTL_PMUOPAMP_CHOPCLKFREQ_CLK16KHZ     ((uint32_t)0x00000000U)         /* !< 16kHz */
#define SYSCTL_PMUOPAMP_CHOPCLKFREQ_CLK8KHZ      ((uint32_t)0x00000100U)         /* !< 8kHz */
#define SYSCTL_PMUOPAMP_CHOPCLKFREQ_CLK4KHZ      ((uint32_t)0x00000200U)         /* !< 4kHz */
#define SYSCTL_PMUOPAMP_CHOPCLKFREQ_CLK2KHZ      ((uint32_t)0x00000300U)         /* !< 2kHz */
/* SYSCTL_PMUOPAMP[PCHENABLE] Bits */
#define SYSCTL_PMUOPAMP_PCHENABLE_OFS            (1)                             /* !< PCHENABLE Offset */
#define SYSCTL_PMUOPAMP_PCHENABLE_MASK           ((uint32_t)0x00000002U)         /* !< Set PCHENABLE to enable the
                                                                                    positive channel input. */
#define SYSCTL_PMUOPAMP_PCHENABLE_FALSE          ((uint32_t)0x00000000U)         /* !< Positive channel disabled */
#define SYSCTL_PMUOPAMP_PCHENABLE_TRUE           ((uint32_t)0x00000002U)         /* !< GPAMP_IN+ connected to positive
                                                                                    channel */

/* SYSCTL_SHUTDNSTORE0 Bits */
/* SYSCTL_SHUTDNSTORE0[DATA] Bits */
#define SYSCTL_SHUTDNSTORE0_DATA_OFS             (0)                             /* !< DATA Offset */
#define SYSCTL_SHUTDNSTORE0_DATA_MASK            ((uint32_t)0x000000FFU)         /* !< Shutdown storage byte 0 */

/* SYSCTL_SHUTDNSTORE1 Bits */
/* SYSCTL_SHUTDNSTORE1[DATA] Bits */
#define SYSCTL_SHUTDNSTORE1_DATA_OFS             (0)                             /* !< DATA Offset */
#define SYSCTL_SHUTDNSTORE1_DATA_MASK            ((uint32_t)0x000000FFU)         /* !< Shutdown storage byte 1 */

/* SYSCTL_SHUTDNSTORE2 Bits */
/* SYSCTL_SHUTDNSTORE2[DATA] Bits */
#define SYSCTL_SHUTDNSTORE2_DATA_OFS             (0)                             /* !< DATA Offset */
#define SYSCTL_SHUTDNSTORE2_DATA_MASK            ((uint32_t)0x000000FFU)         /* !< Shutdown storage byte 2 */

/* SYSCTL_SHUTDNSTORE3 Bits */
/* SYSCTL_SHUTDNSTORE3[DATA] Bits */
#define SYSCTL_SHUTDNSTORE3_DATA_OFS             (0)                             /* !< DATA Offset */
#define SYSCTL_SHUTDNSTORE3_DATA_MASK            ((uint32_t)0x000000FFU)         /* !< Shutdown storage byte 3 */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_m0p_hw_sysctl_mspm0l11xx_l13xx__include */
