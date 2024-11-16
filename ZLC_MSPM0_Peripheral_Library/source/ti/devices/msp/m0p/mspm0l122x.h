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

#ifndef ti_devices_msp_m0p_mspm0l122x__include
#define ti_devices_msp_m0p_mspm0l122x__include

/* Filename: mspm0l122x.h */
/* Revised: 2023-11-15 16:54:18*/

/* Use standard integer types with explicit width */
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup MSPM0L122X_Definitions MSPM0L122X Definitions
  This file defines all structures and symbols for MSPM0L122X
  @{
*/

/** @addtogroup MSPM0L122X_CMSIS Device CMSIS Definitions
  Configuration of the Processor and Core Peripherals
  @{
*/
/******************************************************************************
* Interrupt Definitions                                                       *
******************************************************************************/
typedef enum IRQn
{
  NonMaskableInt_IRQn         = -14,    /* 2  Non Maskable Interrupt */
  HardFault_IRQn              = -13,    /* 3  Hard Fault Interrupt */
  SVCall_IRQn                 = -5,     /* 11 SV Call Interrupt */
  PendSV_IRQn                 = -2,     /* 14 Pend SV Interrupt */
  SysTick_IRQn                = -1,     /* 15 System Tick Interrupt */
  DEBUGSS_INT_IRQn            = 0,      /* 16 DEBUGSS_INT Interrupt */
  WWDT0_INT_IRQn              = 0,      /* 16 WWDT0_INT Interrupt */
  FLASHCTL_INT_IRQn           = 0,      /* 16 FLASHCTL_INT Interrupt */
  SYSCTL_INT_IRQn             = 0,      /* 16 SYSCTL_INT Interrupt */
  COMP0_INT_IRQn              = 1,      /* 17 COMP0_INT Interrupt */
  GPIOA_INT_IRQn              = 1,      /* 17 GPIOA_INT Interrupt */
  TRNG_INT_IRQn               = 1,      /* 17 TRNG_INT Interrupt */
  GPIOB_INT_IRQn              = 1,      /* 17 GPIOB_INT Interrupt */
  GPIOC_INT_IRQn              = 1,      /* 17 GPIOC_INT Interrupt */
  TIMG12_INT_IRQn             = 2,      /* 18 TIMG12_INT Interrupt */
  UART4_INT_IRQn              = 3,      /* 19 UART4_INT Interrupt */
  ADC0_INT_IRQn               = 4,      /* 20 ADC0_INT Interrupt */
  SPI0_INT_IRQn               = 9,      /* 25 SPI0_INT Interrupt */
  SPI1_INT_IRQn               = 10,     /* 26 SPI1_INT Interrupt */
  UART2_INT_IRQn              = 13,     /* 29 UART2_INT Interrupt */
  UART3_INT_IRQn              = 14,     /* 30 UART3_INT Interrupt */
  UART0_INT_IRQn              = 15,     /* 31 UART0_INT Interrupt */
  UART1_INT_IRQn              = 16,     /* 32 UART1_INT Interrupt */
  TIMA0_INT_IRQn              = 18,     /* 34 TIMA0_INT Interrupt */
  TIMG8_INT_IRQn              = 20,     /* 36 TIMG8_INT Interrupt */
  TIMG0_INT_IRQn              = 21,     /* 37 TIMG0_INT Interrupt */
  TIMG4_INT_IRQn              = 22,     /* 38 TIMG4_INT Interrupt */
  TIMG5_INT_IRQn              = 23,     /* 39 TIMG5_INT Interrupt */
  I2C0_INT_IRQn               = 24,     /* 40 I2C0_INT Interrupt */
  I2C1_INT_IRQn               = 25,     /* 41 I2C1_INT Interrupt */
  I2C2_INT_IRQn               = 26,     /* 42 I2C2_INT Interrupt */
  AESADV_INT_IRQn             = 28,     /* 44 AESADV_INT Interrupt */
  LFSS_INT_IRQn               = 30,     /* 46 LFSS_INT Interrupt */
  RTC_A_INT_IRQn              = 30,     /* 46 RTC_A_INT Interrupt */
  TAMPERIO_INT_IRQn           = 30,     /* 46 TAMPERIO_INT Interrupt */
  DMA_INT_IRQn                = 31,     /* 47 DMA_INT Interrupt */
} IRQn_Type;

#define NonMaskableInt_VECn     2     /* Non Maskable Interrupt */
#define HardFault_VECn          3     /* Hard Fault Interrupt */
#define SVCall_VECn             11    /* SV Call Interrupt */
#define PendSV_VECn             14    /* Pend SV Interrupt */
#define SysTick_VECn            15    /* System Tick Interrupt */
#define DEBUGSS_INT_VECn        16    /* DEBUGSS_INT Interrupt */
#define WWDT0_INT_VECn          16    /* WWDT0_INT Interrupt */
#define FLASHCTL_INT_VECn       16    /* FLASHCTL_INT Interrupt */
#define SYSCTL_INT_VECn         16    /* SYSCTL_INT Interrupt */
#define COMP0_INT_VECn          17    /* COMP0_INT Interrupt */
#define GPIOA_INT_VECn          17    /* GPIOA_INT Interrupt */
#define TRNG_INT_VECn           17    /* TRNG_INT Interrupt */
#define GPIOB_INT_VECn          17    /* GPIOB_INT Interrupt */
#define GPIOC_INT_VECn          17    /* GPIOC_INT Interrupt */
#define TIMG12_INT_VECn         18    /* TIMG12_INT Interrupt */
#define UART4_INT_VECn          19    /* UART4_INT Interrupt */
#define ADC0_INT_VECn           20    /* ADC0_INT Interrupt */
#define SPI0_INT_VECn           25    /* SPI0_INT Interrupt */
#define SPI1_INT_VECn           26    /* SPI1_INT Interrupt */
#define UART2_INT_VECn          29    /* UART2_INT Interrupt */
#define UART3_INT_VECn          30    /* UART3_INT Interrupt */
#define UART0_INT_VECn          31    /* UART0_INT Interrupt */
#define UART1_INT_VECn          32    /* UART1_INT Interrupt */
#define TIMA0_INT_VECn          34    /* TIMA0_INT Interrupt */
#define TIMG8_INT_VECn          36    /* TIMG8_INT Interrupt */
#define TIMG0_INT_VECn          37    /* TIMG0_INT Interrupt */
#define TIMG4_INT_VECn          38    /* TIMG4_INT Interrupt */
#define TIMG5_INT_VECn          39    /* TIMG5_INT Interrupt */
#define I2C0_INT_VECn           40    /* I2C0_INT Interrupt */
#define I2C1_INT_VECn           41    /* I2C1_INT Interrupt */
#define I2C2_INT_VECn           42    /* I2C2_INT Interrupt */
#define AESADV_INT_VECn         44    /* AESADV_INT Interrupt */
#define LFSS_INT_VECn           46    /* LFSS_INT Interrupt */
#define RTC_A_INT_VECn          46    /* RTC_A_INT Interrupt */
#define TAMPERIO_INT_VECn       46    /* TAMPERIO_INT Interrupt */
#define DMA_INT_VECn            47    /* DMA_INT Interrupt */


/******************************************************************************
* Ignore unused variables                                                     *
******************************************************************************/

#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/******************************************************************************
* Processor and Core Peripheral Section                                       *
******************************************************************************/

#define __CM0PLUS_REV           0x0001U    /* Core revision r0p1 */
#define __MPU_PRESENT           0x0001U    /* MPU present */
#define __VTOR_PRESENT          0x0001U    /* VTOR present */
#define __NVIC_PRIO_BITS        0x0002U    /* Number of bits used for Priority Levels */
#define __Vendor_SysTickConfig  0x0000U    /* Set to 1 if different SysTick Config is used */

#include "core_cm0plus.h"                  /* Processor and core peripherals */

/******************************************************************************
* Peripheral headers                                                          *
******************************************************************************/
/** @addtogroup MSPM0L122X_Peripherals MSPM0L122X Peripherals
  MSPM0L122X Peripheral registers structures
  @{
*/

#include <ti/devices/msp/peripherals/hw_adc12.h>
#include <ti/devices/msp/peripherals/hw_aesadv.h>
#include <ti/devices/msp/peripherals/hw_comp.h>
#include <ti/devices/msp/peripherals/hw_crcp.h>
#include <ti/devices/msp/peripherals/hw_dma.h>
#include <ti/devices/msp/peripherals/hw_flashctl.h>
#include <ti/devices/msp/peripherals/hw_gpio.h>
#include <ti/devices/msp/peripherals/hw_gptimer.h>
#include <ti/devices/msp/peripherals/hw_i2c.h>
#include <ti/devices/msp/peripherals/hw_lfss.h>
#include <ti/devices/msp/peripherals/hw_iomux.h>
#include <ti/devices/msp/peripherals/hw_keystorectl.h>
#include <ti/devices/msp/peripherals/hw_lfss.h>
#include <ti/devices/msp/peripherals/hw_rtc.h>
#include <ti/devices/msp/peripherals/hw_spi.h>
#include <ti/devices/msp/peripherals/hw_trng.h>
#include <ti/devices/msp/peripherals/hw_uart.h>
#include <ti/devices/msp/peripherals/hw_vref.h>
#include <ti/devices/msp/peripherals/hw_wuc.h>
#include <ti/devices/msp/peripherals/hw_wwdt.h>
#include <ti/devices/msp/peripherals/m0p/hw_factoryregion.h>
#include <ti/devices/msp/peripherals/m0p/hw_cpuss.h>
#include <ti/devices/msp/peripherals/m0p/hw_debugss.h>
#include <ti/devices/msp/peripherals/m0p/hw_sysctl.h>

#define __MSPM0_HAS_ADC12__
#define __MSPM0_HAS_COMP__
#define __MSPM0_HAS_GPIO__
#define __MSPM0_HAS_TIMER_A__
#define __MSPM0_HAS_TIMER_G__
#define __MSPM0_HAS_I2C__
#define __MSPM0_HAS_SPI__
#define __MSPM0_HAS_TRNG__
#define __MSPM0_HAS_RTC_A__
#define __MSPM0_HAS_UART_EXTD__
#define __MSPM0_HAS_UART_MAIN__
#define __MSPM0_HAS_VREF__
#define __MSPM0_HAS_WWDT__
#define __MSPM0_HAS_AESADV__
#define __MSPM0_HAS_CRCP__
#define __MSPM0_HAS_KEYSTORE_CTL__
#define __MSPM0_HAS_LFSS__
#define __MSPM0_HAS_SCRATCHPAD__
#define __MSPM0_HAS_TIO__
#define __MSPM0_HAS_WDT__
#define __MSPM0_HAS_ECC__


/*@}*/ /* end of group MSPM0L122X_Peripherals */

/******************************************************************************
* Device and peripheral memory map                                            *
******************************************************************************/
/** @addtogroup MSPM0L122X_MemoryMap MSPM0L122X Memory Mapping
  @{
*/

#define DEBUGSS_BASE                   (0x400C7000U)     /*!< Base address of module DEBUGSS */
#define COMP0_BASE                     (0x40008000U)     /*!< Base address of module COMP0 */
#define WWDT0_BASE                     (0x40080000U)     /*!< Base address of module WWDT0 */
#define I2C1_BASE                      (0x400F2000U)     /*!< Base address of module I2C1 */
#define UART0_BASE                     (0x40108000U)     /*!< Base address of module UART0 */
#define GPIOA_BASE                     (0x400A0000U)     /*!< Base address of module GPIOA */
#define I2C0_BASE                      (0x400F0000U)     /*!< Base address of module I2C0 */
#define UART2_BASE                     (0x40100000U)     /*!< Base address of module UART2 */
#define ADC0_BASE                      (0x40004000U)     /*!< Base address of module ADC0 */
#define ADC0_PERIPHERALREGIONSVT_BASE  (0x4055A000U)     /*!< Base address of module ADC0_PERIPHERALREGIONSVT */
#define SPI0_BASE                      (0x40468000U)     /*!< Base address of module SPI0 */
#define VREF_BASE                      (0x40030000U)     /*!< Base address of module VREF */
#define SPI1_BASE                      (0x4046A000U)     /*!< Base address of module SPI1 */
#define KEYSTORECTL_BASE               (0x400AC000U)     /*!< Base address of module KEYSTORECTL */
#define TRNG_BASE                      (0x40444000U)     /*!< Base address of module TRNG */
#define UART3_BASE                     (0x40102000U)     /*!< Base address of module UART3 */
#define UART1_BASE                     (0x4010A000U)     /*!< Base address of module UART1 */
#define UART4_BASE                     (0x40104000U)     /*!< Base address of module UART4 */
#define I2C2_BASE                      (0x400F4000U)     /*!< Base address of module I2C2 */
#define GPIOB_BASE                     (0x400A2000U)     /*!< Base address of module GPIOB */
#define GPIOC_BASE                     (0x400A4000U)     /*!< Base address of module GPIOC */
#define FLASHCTL_BASE                  (0x400CD000U)     /*!< Base address of module FLASHCTL */
#define AESADV_BASE                    (0x40442000U)     /*!< Base address of module AESADV */
#define CRCP0_BASE                     (0x40440000U)     /*!< Base address of module CRCP0 */
#define TIMG0_BASE                     (0x40084000U)     /*!< Base address of module TIMG0 */
#define TIMG4_BASE                     (0x4008C000U)     /*!< Base address of module TIMG4 */
#define TIMG8_BASE                     (0x40090000U)     /*!< Base address of module TIMG8 */
#define TIMG12_BASE                    (0x40870000U)     /*!< Base address of module TIMG12 */
#define TIMA0_BASE                     (0x40860000U)     /*!< Base address of module TIMA0 */
#define DMA_BASE                       (0x4042A000U)     /*!< Base address of module DMA */
#define LFSS_BASE                      (0x40094000U)     /*!< Base address of module LFSS */
#define RTC_A_BASE                     (0x40094000U)     /*!< Base address of module RTC_A */
#define SYSCTL_BASE                    (0x400AF000U)     /*!< Base address of module SYSCTL */
#define TIMG5_BASE                     (0x4008E000U)     /*!< Base address of module TIMG5 */
#define IOMUX_BASE                     (0x40428000U)     /*!< Base address of module IOMUX */
#define CPUSS_BASE                     (0x40400000U)     /*!< Base address of module CPUSS */
#define WUC_BASE                       (0x40424000U)     /*!< Base address of module WUC */
#define FACTORYREGION_BASE             (0x41C40000U)     /*!< Base address of module FACTORYREGION */


/*@}*/ /* end of group MSPM0L122X_MemoryMap */

/******************************************************************************
* Peripheral declarations                                                     *
******************************************************************************/
/** @addtogroup MSPM0L122X_PeripheralDecl MSPM0L122X Peripheral Declaration
  @{
*/

static DEBUGSS_Regs                             * const DEBUGSS                        = ((DEBUGSS_Regs *) DEBUGSS_BASE);
static COMP_Regs                                * const COMP0                          = ((COMP_Regs *) COMP0_BASE);
static WWDT_Regs                                * const WWDT0                          = ((WWDT_Regs *) WWDT0_BASE);
static I2C_Regs                                 * const I2C1                           = ((I2C_Regs *) I2C1_BASE);
static UART_Regs                                * const UART0                          = ((UART_Regs *) UART0_BASE);
static GPIO_Regs                                * const GPIOA                          = ((GPIO_Regs *) GPIOA_BASE);
static I2C_Regs                                 * const I2C0                           = ((I2C_Regs *) I2C0_BASE);
static UART_Regs                                * const UART2                          = ((UART_Regs *) UART2_BASE);
static ADC12_Regs                               * const ADC0                           = ((ADC12_Regs *) ADC0_BASE);
static ADC12_PERIPHERALREGIONSVT_Regs           * const ADC0_PERIPHERALREGIONSVT       = ((ADC12_PERIPHERALREGIONSVT_Regs *) ADC0_PERIPHERALREGIONSVT_BASE);
static SPI_Regs                                 * const SPI0                           = ((SPI_Regs *) SPI0_BASE);
static VREF_Regs                                * const VREF                           = ((VREF_Regs *) VREF_BASE);
static SPI_Regs                                 * const SPI1                           = ((SPI_Regs *) SPI1_BASE);
static KEYSTORECTL_Regs                         * const KEYSTORECTL                    = ((KEYSTORECTL_Regs *) KEYSTORECTL_BASE);
static TRNG_Regs                                * const TRNG                           = ((TRNG_Regs *) TRNG_BASE);
static UART_Regs                                * const UART3                          = ((UART_Regs *) UART3_BASE);
static UART_Regs                                * const UART1                          = ((UART_Regs *) UART1_BASE);
static UART_Regs                                * const UART4                          = ((UART_Regs *) UART4_BASE);
static I2C_Regs                                 * const I2C2                           = ((I2C_Regs *) I2C2_BASE);
static GPIO_Regs                                * const GPIOB                          = ((GPIO_Regs *) GPIOB_BASE);
static GPIO_Regs                                * const GPIOC                          = ((GPIO_Regs *) GPIOC_BASE);
static FLASHCTL_Regs                            * const FLASHCTL                       = ((FLASHCTL_Regs *) FLASHCTL_BASE);
static AESADV_Regs                              * const AESADV                         = ((AESADV_Regs *) AESADV_BASE);
static CRCP_Regs                                * const CRCP0                          = ((CRCP_Regs *) CRCP0_BASE);
static GPTIMER_Regs                             * const TIMG0                          = ((GPTIMER_Regs *) TIMG0_BASE);
static GPTIMER_Regs                             * const TIMG4                          = ((GPTIMER_Regs *) TIMG4_BASE);
static GPTIMER_Regs                             * const TIMG8                          = ((GPTIMER_Regs *) TIMG8_BASE);
static GPTIMER_Regs                             * const TIMG12                         = ((GPTIMER_Regs *) TIMG12_BASE);
static GPTIMER_Regs                             * const TIMA0                          = ((GPTIMER_Regs *) TIMA0_BASE);
static DMA_Regs                                 * const DMA                            = ((DMA_Regs *) DMA_BASE);
static LFSS_Regs                                * const LFSS                           = ((LFSS_Regs *) LFSS_BASE);
static RTC_Regs                                 * const RTC_A                          = ((RTC_Regs *) RTC_A_BASE);
static SYSCTL_Regs                              * const SYSCTL                         = ((SYSCTL_Regs *) SYSCTL_BASE);
static GPTIMER_Regs                             * const TIMG5                          = ((GPTIMER_Regs *) TIMG5_BASE);
static IOMUX_Regs                               * const IOMUX                          = ((IOMUX_Regs *) IOMUX_BASE);
static CPUSS_Regs                               * const CPUSS                          = ((CPUSS_Regs *) CPUSS_BASE);
static WUC_Regs                                 * const WUC                            = ((WUC_Regs *) WUC_BASE);
static FACTORYREGION_OPEN_Regs                  * const FACTORYREGION                  = ((FACTORYREGION_OPEN_Regs *) FACTORYREGION_BASE);

/******************************************************************************
* SYS parameters                                                              *
******************************************************************************/

#define DMA_SYS_N_DMA_CHANNEL                         (7)       /* !< Number of DMA channels implemented in DMA. */
#define DMA_SYS_N_DMA_FULL_CHANNEL                    (3)       /* !< Number of FULL-DMA channels implemented in DMA. */
#define FLASHCTL_SYS_DATAWIDTH                        (64)      /* !< Data bit width of a single flash word. */
#define ADC_SYS_NUM_ANALOG_CHAN                       (32)      /* !< Number of analog channels. */
#define I2C_SYS_FENTRIES                              (8)       /* !< Number of FIFO entries */
#define FLASHCTL_SYS_WEPROTAWIDTH                     (32)      /* !< Bit width of WEPROTA register */
#define FLASHCTL_SYS_WEPROTBWIDTH                     (16)      /* !< Bit width of WEPROTB register */
#define FLASHCTL_SYS_WEPROTCWIDTH                     (0)       /* !< Bit width of WEPROTC register */

/******************************************************************************
* DMA Triggers                                                                *
******************************************************************************/

/* External DMA Triggers */
#define DMA_SOFTWARE_TRIG                             (0)
#define DMA_GENERIC_SUB0_TRIG                         (1)
#define DMA_GENERIC_SUB1_TRIG                         (2)
#define DMA_AESADV_AES_0_TRIG                         (3)
#define DMA_AESADV_AES_1_TRIG                         (4)
#define DMA_I2C0_TX_TRIG                              (5)
#define DMA_I2C0_RX_TRIG                              (6)
#define DMA_I2C1_TX_TRIG                              (7)
#define DMA_I2C1_RX_TRIG                              (8)
#define DMA_I2C2_TX_TRIG                              (9)
#define DMA_I2C2_RX_TRIG                              (10)
#define DMA_SPI0_RX_TRIG                              (11)
#define DMA_SPI0_TX_TRIG                              (12)
#define DMA_SPI1_RX_TRIG                              (13)
#define DMA_SPI1_TX_TRIG                              (14)
#define DMA_UART0_RX_TRIG                             (15)
#define DMA_UART0_TX_TRIG                             (16)
#define DMA_UART1_RX_TRIG                             (17)
#define DMA_UART1_TX_TRIG                             (18)
#define DMA_UART2_RX_TRIG                             (19)
#define DMA_UART2_TX_TRIG                             (20)
#define DMA_UART3_RX_TRIG                             (21)
#define DMA_UART3_TX_TRIG                             (22)
#define DMA_UART4_RX_TRIG                             (23)
#define DMA_UART4_TX_TRIG                             (24)
#define DMA_ADC0_EVT_GEN_BD_TRIG                      (25)

/* Internal DMA Triggers */
#define DMA_CH_0_TRIG                                 (0)
#define DMA_CH_1_TRIG                                 (1)
#define DMA_CH_2_TRIG                                 (2)
#define DMA_CH_3_TRIG                                 (3)
#define DMA_CH_4_TRIG                                 (4)
#define DMA_CH_5_TRIG                                 (5)
#define DMA_CH_6_TRIG                                 (6)
#define DMA_CH_7_TRIG                                 (7)
#define DMA_CH_8_TRIG                                 (8)
#define DMA_CH_9_TRIG                                 (9)
#define DMA_CH_10_TRIG                                (10)
#define DMA_CH_11_TRIG                                (11)
#define DMA_CH_12_TRIG                                (12)
#define DMA_CH_13_TRIG                                (13)
#define DMA_CH_14_TRIG                                (14)
#define DMA_CH_15_TRIG                                (15)


/******************************************************************************
* IOMUX Pin Definitions                                                       *
******************************************************************************/

typedef enum IOMUX_PINCM
{
  IOMUX_PINCM1         = (0),
  IOMUX_PINCM2         = (1),
  IOMUX_PINCM3         = (2),
  IOMUX_PINCM4         = (3),
  IOMUX_PINCM5         = (4),
  IOMUX_PINCM6         = (5),
  IOMUX_PINCM7         = (6),
  IOMUX_PINCM8         = (7),
  IOMUX_PINCM9         = (8),
  IOMUX_PINCM10        = (9),
  IOMUX_PINCM11        = (10),
  IOMUX_PINCM12        = (11),
  IOMUX_PINCM13        = (12),
  IOMUX_PINCM14        = (13),
  IOMUX_PINCM15        = (14),
  IOMUX_PINCM16        = (15),
  IOMUX_PINCM17        = (16),
  IOMUX_PINCM18        = (17),
  IOMUX_PINCM19        = (18),
  IOMUX_PINCM20        = (19),
  IOMUX_PINCM21        = (20),
  IOMUX_PINCM22        = (21),
  IOMUX_PINCM23        = (22),
  IOMUX_PINCM24        = (23),
  IOMUX_PINCM25        = (24),
  IOMUX_PINCM26        = (25),
  IOMUX_PINCM27        = (26),
  IOMUX_PINCM28        = (27),
  IOMUX_PINCM29        = (28),
  IOMUX_PINCM30        = (29),
  IOMUX_PINCM31        = (30),
  IOMUX_PINCM32        = (31),
  IOMUX_PINCM33        = (32),
  IOMUX_PINCM34        = (33),
  IOMUX_PINCM35        = (34),
  IOMUX_PINCM36        = (35),
  IOMUX_PINCM37        = (36),
  IOMUX_PINCM38        = (37),
  IOMUX_PINCM39        = (38),
  IOMUX_PINCM40        = (39),
  IOMUX_PINCM41        = (40),
  IOMUX_PINCM42        = (41),
  IOMUX_PINCM43        = (42),
  IOMUX_PINCM44        = (43),
  IOMUX_PINCM45        = (44),
  IOMUX_PINCM46        = (45),
  IOMUX_PINCM47        = (46),
  IOMUX_PINCM48        = (47),
  IOMUX_PINCM49        = (48),
  IOMUX_PINCM50        = (49),
  IOMUX_PINCM51        = (50),
  IOMUX_PINCM52        = (51),
  IOMUX_PINCM53        = (52),
  IOMUX_PINCM54        = (53),
  IOMUX_PINCM55        = (54),
  IOMUX_PINCM56        = (55),
  IOMUX_PINCM57        = (56),
  IOMUX_PINCM58        = (57),
  IOMUX_PINCM59        = (58),
  IOMUX_PINCM60        = (59),
  IOMUX_PINCM61        = (60),
  IOMUX_PINCM62        = (61),
  IOMUX_PINCM63        = (62),
  IOMUX_PINCM64        = (63),
  IOMUX_PINCM65        = (64),
  IOMUX_PINCM66        = (65),
  IOMUX_PINCM67        = (66),
  IOMUX_PINCM68        = (67),
  IOMUX_PINCM69        = (68),
  IOMUX_PINCM70        = (69),
  IOMUX_PINCM71        = (70),
  IOMUX_PINCM72        = (71),
  IOMUX_PINCM73        = (72),
  IOMUX_PINCM74        = (73),
} IOMUX_PINCM;


/* IOMUX_PINCM1[PF] Bits */
#define IOMUX_PINCM1_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM1_PF_GPIOA_DIO00                   ((uint32_t)0X00000001)
#define IOMUX_PINCM1_PF_UART0_TX                      ((uint32_t)0X00000002)
#define IOMUX_PINCM1_PF_I2C0_SDA                      ((uint32_t)0X00000003)
#define IOMUX_PINCM1_PF_TIMA0_CCP0                    ((uint32_t)0X00000004)
#define IOMUX_PINCM1_PF_TIMA_FAULT1                   ((uint32_t)0X00000005)
#define IOMUX_PINCM1_PF_SYSCTL_FCC_IN                 ((uint32_t)0X00000006)
#define IOMUX_PINCM1_PF_TIMG8_CCP1                    ((uint32_t)0X00000007)
#define IOMUX_PINCM1_PF_TIMG12_CCP0                   ((uint32_t)0X00000008)
#define IOMUX_PINCM1_PF_TIMG0_CCP0                    ((uint32_t)0X00000009)

/* IOMUX_PINCM2[PF] Bits */
#define IOMUX_PINCM2_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM2_PF_GPIOA_DIO01                   ((uint32_t)0X00000001)
#define IOMUX_PINCM2_PF_UART0_RX                      ((uint32_t)0X00000002)
#define IOMUX_PINCM2_PF_I2C0_SCL                      ((uint32_t)0X00000003)
#define IOMUX_PINCM2_PF_TIMA0_CCP1                    ((uint32_t)0X00000004)
#define IOMUX_PINCM2_PF_TIMA_FAULT2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM2_PF_TIMG8_IDX                     ((uint32_t)0X00000006)
#define IOMUX_PINCM2_PF_TIMG8_CCP0                    ((uint32_t)0X00000007)
#define IOMUX_PINCM2_PF_TIMG12_CCP1                   ((uint32_t)0X00000008)
#define IOMUX_PINCM2_PF_TIMG0_CCP1                    ((uint32_t)0X00000009)
#define IOMUX_PINCM2_PF_SPI0_CS3_CD_POCI3             ((uint32_t)0X0000000A)

/* IOMUX_PINCM3[PF] Bits */
#define IOMUX_PINCM3_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM3_PF_GPIOA_DIO28                   ((uint32_t)0X00000001)
#define IOMUX_PINCM3_PF_UART0_TX                      ((uint32_t)0X00000002)
#define IOMUX_PINCM3_PF_I2C0_SDA                      ((uint32_t)0X00000003)
#define IOMUX_PINCM3_PF_TIMA0_CCP3                    ((uint32_t)0X00000004)
#define IOMUX_PINCM3_PF_TIMA_FAULT0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM3_PF_TIMG5_CCP0                    ((uint32_t)0X00000006)
#define IOMUX_PINCM3_PF_TIMA0_CCP1                    ((uint32_t)0X00000007)

/* IOMUX_PINCM4[PF] Bits */
#define IOMUX_PINCM4_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM4_PF_GPIOA_DIO29                   ((uint32_t)0X00000001)
#define IOMUX_PINCM4_PF_I2C1_SCL                      ((uint32_t)0X00000002)
#define IOMUX_PINCM4_PF_UART2_RTS                     ((uint32_t)0X00000003)
#define IOMUX_PINCM4_PF_TIMG8_CCP0                    ((uint32_t)0X00000004)
#define IOMUX_PINCM4_PF_TIMG4_CCP0                    ((uint32_t)0X00000005)
#define IOMUX_PINCM4_PF_I2C2_SCL                      ((uint32_t)0X00000006)
#define IOMUX_PINCM4_PF_UART0_CTS                     ((uint32_t)0X00000007)
#define IOMUX_PINCM4_PF_SPI0_CS3_CD_POCI3             ((uint32_t)0X00000008)

/* IOMUX_PINCM5[PF] Bits */
#define IOMUX_PINCM5_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM5_PF_GPIOA_DIO30                   ((uint32_t)0X00000001)
#define IOMUX_PINCM5_PF_I2C1_SDA                      ((uint32_t)0X00000002)
#define IOMUX_PINCM5_PF_UART2_CTS                     ((uint32_t)0X00000003)
#define IOMUX_PINCM5_PF_TIMG8_CCP1                    ((uint32_t)0X00000004)
#define IOMUX_PINCM5_PF_TIMG4_CCP1                    ((uint32_t)0X00000005)
#define IOMUX_PINCM5_PF_I2C2_SDA                      ((uint32_t)0X00000006)
#define IOMUX_PINCM5_PF_UART0_RTS                     ((uint32_t)0X00000007)
#define IOMUX_PINCM5_PF_SPI0_CS2_POCI2                ((uint32_t)0X00000008)

/* IOMUX_PINCM6[PF] Bits */
#define IOMUX_PINCM6_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM6_PF_GPIOA_DIO31                   ((uint32_t)0X00000001)
#define IOMUX_PINCM6_PF_UART0_RX                      ((uint32_t)0X00000002)
#define IOMUX_PINCM6_PF_I2C0_SCL                      ((uint32_t)0X00000003)
#define IOMUX_PINCM6_PF_TIMA0_CCP3_CMPL               ((uint32_t)0X00000004)
#define IOMUX_PINCM6_PF_TIMG12_CCP1                   ((uint32_t)0X00000005)
#define IOMUX_PINCM6_PF_SYSCTL_CLK_OUT                ((uint32_t)0X00000006)
#define IOMUX_PINCM6_PF_TIMG5_CCP1                    ((uint32_t)0X00000007)
#define IOMUX_PINCM6_PF_SPI0_CS3_CD_POCI3             ((uint32_t)0X00000008)

/* IOMUX_PINCM7[PF] Bits */
#define IOMUX_PINCM7_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM7_PF_GPIOA_DIO02                   ((uint32_t)0X00000001)
#define IOMUX_PINCM7_PF_TIMG8_CCP1                    ((uint32_t)0X00000002)
#define IOMUX_PINCM7_PF_SPI0_CS0                      ((uint32_t)0X00000003)
#define IOMUX_PINCM7_PF_TIMG5_CCP1                    ((uint32_t)0X00000004)
#define IOMUX_PINCM7_PF_SPI1_CS0                      ((uint32_t)0X00000005)
#define IOMUX_PINCM7_PF_TIMA0_CCP3_CMPL               ((uint32_t)0X00000006)
#define IOMUX_PINCM7_PF_TIMA0_CCP2_CMPL               ((uint32_t)0X00000007)
#define IOMUX_PINCM7_PF_TIMA_FAULT0                   ((uint32_t)0X00000008)
#define IOMUX_PINCM7_PF_TIMA_FAULT1                   ((uint32_t)0X00000009)
#define IOMUX_PINCM7_PF_UART4_CTS                     ((uint32_t)0X0000000A)
#define IOMUX_PINCM7_PF_TIMA0_CCP0                    ((uint32_t)0X0000000B)

/* IOMUX_PINCM8[PF] Bits */
#define IOMUX_PINCM8_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM8_PF_GPIOA_DIO03                   ((uint32_t)0X00000001)
#define IOMUX_PINCM8_PF_TIMG8_CCP0                    ((uint32_t)0X00000002)
#define IOMUX_PINCM8_PF_SPI0_CS1_POCI1                ((uint32_t)0X00000003)
#define IOMUX_PINCM8_PF_I2C1_SDA                      ((uint32_t)0X00000004)
#define IOMUX_PINCM8_PF_TIMA0_CCP1                    ((uint32_t)0X00000005)
#define IOMUX_PINCM8_PF_COMP0_OUT                     ((uint32_t)0X00000006)
#define IOMUX_PINCM8_PF_TIMG5_CCP0                    ((uint32_t)0X00000007)
#define IOMUX_PINCM8_PF_TIMA0_CCP2                    ((uint32_t)0X00000008)
#define IOMUX_PINCM8_PF_UART2_CTS                     ((uint32_t)0X00000009)
#define IOMUX_PINCM8_PF_UART1_TX                      ((uint32_t)0X0000000A)
#define IOMUX_PINCM8_PF_SPI0_CS3_CD_POCI3             ((uint32_t)0X0000000B)

/* IOMUX_PINCM9[PF] Bits */
#define IOMUX_PINCM9_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM9_PF_GPIOA_DIO04                   ((uint32_t)0X00000001)
#define IOMUX_PINCM9_PF_TIMG8_CCP1                    ((uint32_t)0X00000002)
#define IOMUX_PINCM9_PF_SPI0_POCI                     ((uint32_t)0X00000003)
#define IOMUX_PINCM9_PF_I2C1_SCL                      ((uint32_t)0X00000004)
#define IOMUX_PINCM9_PF_TIMA0_CCP1_CMPL               ((uint32_t)0X00000005)
#define IOMUX_PINCM9_PF_SYSCTL_LFCLKIN                ((uint32_t)0X00000006)
#define IOMUX_PINCM9_PF_TIMG5_CCP1                    ((uint32_t)0X00000007)
#define IOMUX_PINCM9_PF_TIMA0_CCP3                    ((uint32_t)0X00000008)
#define IOMUX_PINCM9_PF_UART2_RTS                     ((uint32_t)0X00000009)
#define IOMUX_PINCM9_PF_UART1_RX                      ((uint32_t)0X0000000A)
#define IOMUX_PINCM9_PF_SPI0_CS0                      ((uint32_t)0X0000000B)

/* IOMUX_PINCM10[PF] Bits */
#define IOMUX_PINCM10_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM10_PF_GPIOA_DIO05                  ((uint32_t)0X00000001)
#define IOMUX_PINCM10_PF_TIMG8_CCP0                   ((uint32_t)0X00000002)
#define IOMUX_PINCM10_PF_SPI0_PICO                    ((uint32_t)0X00000003)
#define IOMUX_PINCM10_PF_I2C1_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM10_PF_TIMG0_CCP0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM10_PF_SYSCTL_FCC_IN                ((uint32_t)0X00000006)
#define IOMUX_PINCM10_PF_TIMG4_CCP0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM10_PF_TIMA_FAULT1                  ((uint32_t)0X00000008)
#define IOMUX_PINCM10_PF_UART0_CTS                    ((uint32_t)0X00000009)
#define IOMUX_PINCM10_PF_UART4_RTS                    ((uint32_t)0X0000000A)
#define IOMUX_PINCM10_PF_UART1_TX                     ((uint32_t)0X0000000B)

/* IOMUX_PINCM11[PF] Bits */
#define IOMUX_PINCM11_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM11_PF_GPIOA_DIO06                  ((uint32_t)0X00000001)
#define IOMUX_PINCM11_PF_TIMG8_CCP1                   ((uint32_t)0X00000002)
#define IOMUX_PINCM11_PF_SPI0_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM11_PF_I2C1_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM11_PF_TIMG0_CCP1                   ((uint32_t)0X00000005)
#define IOMUX_PINCM11_PF_SYSCTL_HFCLKIN               ((uint32_t)0X00000006)
#define IOMUX_PINCM11_PF_TIMG4_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM11_PF_TIMA_FAULT0                  ((uint32_t)0X00000008)
#define IOMUX_PINCM11_PF_UART0_RTS                    ((uint32_t)0X00000009)
#define IOMUX_PINCM11_PF_TIMA0_CCP2_CMPL              ((uint32_t)0X0000000A)
#define IOMUX_PINCM11_PF_UART1_RX                     ((uint32_t)0X0000000B)

/* IOMUX_PINCM12[PF] Bits */
#define IOMUX_PINCM12_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM12_PF_GPIOB_DIO00                  ((uint32_t)0X00000001)
#define IOMUX_PINCM12_PF_UART0_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM12_PF_SPI1_CS2_POCI2               ((uint32_t)0X00000003)
#define IOMUX_PINCM12_PF_I2C0_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM12_PF_TIMA0_CCP2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM12_PF_TIMG0_CCP0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM12_PF_SPI0_CS3_CD_POCI3            ((uint32_t)0X00000007)

/* IOMUX_PINCM13[PF] Bits */
#define IOMUX_PINCM13_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM13_PF_GPIOB_DIO01                  ((uint32_t)0X00000001)
#define IOMUX_PINCM13_PF_UART0_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM13_PF_SPI1_CS3_CD_POCI3            ((uint32_t)0X00000003)
#define IOMUX_PINCM13_PF_I2C0_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM13_PF_TIMA0_CCP2_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM13_PF_TIMG0_CCP1                   ((uint32_t)0X00000006)
#define IOMUX_PINCM13_PF_SPI0_CS2_POCI2               ((uint32_t)0X00000007)

/* IOMUX_PINCM14[PF] Bits */
#define IOMUX_PINCM14_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM14_PF_GPIOA_DIO07                  ((uint32_t)0X00000001)
#define IOMUX_PINCM14_PF_COMP0_OUT                    ((uint32_t)0X00000002)
#define IOMUX_PINCM14_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000003)
#define IOMUX_PINCM14_PF_TIMG8_CCP0                   ((uint32_t)0X00000004)
#define IOMUX_PINCM14_PF_TIMA0_CCP2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM14_PF_TIMG8_IDX                    ((uint32_t)0X00000006)
#define IOMUX_PINCM14_PF_TIMG5_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM14_PF_TIMA0_CCP1                   ((uint32_t)0X00000008)
#define IOMUX_PINCM14_PF_SPI0_CS2_POCI2               ((uint32_t)0X00000009)
#define IOMUX_PINCM14_PF_SYSCTL_FCC_IN                ((uint32_t)0X0000000A)
#define IOMUX_PINCM14_PF_SPI0_POCI                    ((uint32_t)0X0000000B)

/* IOMUX_PINCM15[PF] Bits */
#define IOMUX_PINCM15_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM15_PF_GPIOB_DIO02                  ((uint32_t)0X00000001)
#define IOMUX_PINCM15_PF_UART3_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM15_PF_UART2_CTS                    ((uint32_t)0X00000003)
#define IOMUX_PINCM15_PF_I2C1_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM15_PF_TIMA0_CCP3                   ((uint32_t)0X00000005)
#define IOMUX_PINCM15_PF_UART1_CTS                    ((uint32_t)0X00000006)
#define IOMUX_PINCM15_PF_TIMG4_CCP0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM15_PF_UART2_TX                     ((uint32_t)0X00000008)
#define IOMUX_PINCM15_PF_TIMG12_CCP0                  ((uint32_t)0X00000009)
#define IOMUX_PINCM15_PF_SYSCTL_HFCLKIN               ((uint32_t)0X0000000A)
#define IOMUX_PINCM15_PF_SPI0_PICO                    ((uint32_t)0X0000000B)

/* IOMUX_PINCM16[PF] Bits */
#define IOMUX_PINCM16_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM16_PF_GPIOB_DIO03                  ((uint32_t)0X00000001)
#define IOMUX_PINCM16_PF_UART3_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM16_PF_UART2_RTS                    ((uint32_t)0X00000003)
#define IOMUX_PINCM16_PF_I2C1_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM16_PF_TIMA0_CCP3_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM16_PF_UART1_RTS                    ((uint32_t)0X00000006)
#define IOMUX_PINCM16_PF_TIMG4_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM16_PF_UART2_RX                     ((uint32_t)0X00000008)
#define IOMUX_PINCM16_PF_TIMG12_CCP1                  ((uint32_t)0X00000009)
#define IOMUX_PINCM16_PF_TIMA0_CCP0                   ((uint32_t)0X0000000A)
#define IOMUX_PINCM16_PF_SPI0_SCLK                    ((uint32_t)0X0000000B)

/* IOMUX_PINCM17[PF] Bits */
#define IOMUX_PINCM17_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM17_PF_GPIOB_DIO04                  ((uint32_t)0X00000001)
#define IOMUX_PINCM17_PF_UART1_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM17_PF_UART3_CTS                    ((uint32_t)0X00000003)
#define IOMUX_PINCM17_PF_TIMA0_CCP1                   ((uint32_t)0X00000004)
#define IOMUX_PINCM17_PF_TIMA0_CCP2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM17_PF_TIMG0_CCP0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM17_PF_TIMG4_CCP0                   ((uint32_t)0X00000007)

/* IOMUX_PINCM18[PF] Bits */
#define IOMUX_PINCM18_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM18_PF_GPIOB_DIO05                  ((uint32_t)0X00000001)
#define IOMUX_PINCM18_PF_UART1_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM18_PF_UART3_RTS                    ((uint32_t)0X00000003)
#define IOMUX_PINCM18_PF_TIMA0_CCP1_CMPL              ((uint32_t)0X00000004)
#define IOMUX_PINCM18_PF_TIMA0_CCP2_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM18_PF_TIMG0_CCP1                   ((uint32_t)0X00000006)
#define IOMUX_PINCM18_PF_TIMG4_CCP1                   ((uint32_t)0X00000007)

/* IOMUX_PINCM19[PF] Bits */
#define IOMUX_PINCM19_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM19_PF_GPIOA_DIO08                  ((uint32_t)0X00000001)
#define IOMUX_PINCM19_PF_UART1_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM19_PF_SPI0_CS0                     ((uint32_t)0X00000003)
#define IOMUX_PINCM19_PF_I2C0_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM19_PF_TIMA0_CCP0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM19_PF_TIMA_FAULT2                  ((uint32_t)0X00000006)
#define IOMUX_PINCM19_PF_TIMA_FAULT0                  ((uint32_t)0X00000007)
#define IOMUX_PINCM19_PF_SPI0_CS3_CD_POCI3            ((uint32_t)0X00000008)
#define IOMUX_PINCM19_PF_TIMG5_CCP1                   ((uint32_t)0X00000009)
#define IOMUX_PINCM19_PF_SYSCTL_HFCLKIN               ((uint32_t)0X0000000A)
#define IOMUX_PINCM19_PF_UART0_RTS                    ((uint32_t)0X0000000B)

/* IOMUX_PINCM20[PF] Bits */
#define IOMUX_PINCM20_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM20_PF_GPIOA_DIO09                  ((uint32_t)0X00000001)
#define IOMUX_PINCM20_PF_UART1_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM20_PF_SPI0_PICO                    ((uint32_t)0X00000003)
#define IOMUX_PINCM20_PF_I2C0_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM20_PF_TIMA0_CCP0_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM20_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000006)
#define IOMUX_PINCM20_PF_TIMA0_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM20_PF_LFSS_RTC_OUT                 ((uint32_t)0X00000008)
#define IOMUX_PINCM20_PF_TIMG5_CCP0                   ((uint32_t)0X00000009)
#define IOMUX_PINCM20_PF_UART4_RTS                    ((uint32_t)0X0000000A)
#define IOMUX_PINCM20_PF_UART0_CTS                    ((uint32_t)0X0000000B)

/* IOMUX_PINCM21[PF] Bits */
#define IOMUX_PINCM21_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM21_PF_GPIOB_DIO28                  ((uint32_t)0X00000001)
#define IOMUX_PINCM21_PF_I2C2_SCL                     ((uint32_t)0X00000002)
#define IOMUX_PINCM21_PF_SPI1_CS0                     ((uint32_t)0X00000003)
#define IOMUX_PINCM21_PF_TIMA_FAULT0                  ((uint32_t)0X00000004)
#define IOMUX_PINCM21_PF_TIMA0_CCP0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM21_PF_TIMG0_CCP0                   ((uint32_t)0X00000006)

/* IOMUX_PINCM22[PF] Bits */
#define IOMUX_PINCM22_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM22_PF_GPIOB_DIO29                  ((uint32_t)0X00000001)
#define IOMUX_PINCM22_PF_I2C2_SDA                     ((uint32_t)0X00000002)
#define IOMUX_PINCM22_PF_SPI1_POCI                    ((uint32_t)0X00000003)
#define IOMUX_PINCM22_PF_TIMA_FAULT1                  ((uint32_t)0X00000004)
#define IOMUX_PINCM22_PF_TIMA0_CCP0_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM22_PF_TIMG0_CCP1                   ((uint32_t)0X00000006)

/* IOMUX_PINCM23[PF] Bits */
#define IOMUX_PINCM23_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM23_PF_GPIOB_DIO30                  ((uint32_t)0X00000001)
#define IOMUX_PINCM23_PF_UART1_CTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM23_PF_SPI1_PICO                    ((uint32_t)0X00000003)
#define IOMUX_PINCM23_PF_TIMA_FAULT2                  ((uint32_t)0X00000004)
#define IOMUX_PINCM23_PF_TIMA0_CCP1                   ((uint32_t)0X00000005)
#define IOMUX_PINCM23_PF_TIMG4_CCP0                   ((uint32_t)0X00000006)

/* IOMUX_PINCM24[PF] Bits */
#define IOMUX_PINCM24_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM24_PF_GPIOB_DIO31                  ((uint32_t)0X00000001)
#define IOMUX_PINCM24_PF_UART1_RTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM24_PF_SPI1_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM24_PF_TIMG8_IDX                    ((uint32_t)0X00000004)
#define IOMUX_PINCM24_PF_TIMA0_CCP1_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM24_PF_TIMG4_CCP1                   ((uint32_t)0X00000006)

/* IOMUX_PINCM25[PF] Bits */
#define IOMUX_PINCM25_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM25_PF_GPIOA_DIO10                  ((uint32_t)0X00000001)
#define IOMUX_PINCM25_PF_UART0_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM25_PF_SPI0_POCI                    ((uint32_t)0X00000003)
#define IOMUX_PINCM25_PF_I2C0_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM25_PF_TIMA0_CCP2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM25_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000006)
#define IOMUX_PINCM25_PF_TIMG0_CCP0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM25_PF_I2C1_SDA                     ((uint32_t)0X00000008)
#define IOMUX_PINCM25_PF_TIMG12_CCP0                  ((uint32_t)0X00000009)
#define IOMUX_PINCM25_PF_TIMA_FAULT1                  ((uint32_t)0X0000000A)

/* IOMUX_PINCM26[PF] Bits */
#define IOMUX_PINCM26_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM26_PF_GPIOA_DIO11                  ((uint32_t)0X00000001)
#define IOMUX_PINCM26_PF_UART0_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM26_PF_SPI0_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM26_PF_I2C0_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM26_PF_TIMA0_CCP2_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM26_PF_COMP0_OUT                    ((uint32_t)0X00000006)
#define IOMUX_PINCM26_PF_TIMG0_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM26_PF_I2C1_SCL                     ((uint32_t)0X00000008)
#define IOMUX_PINCM26_PF_TIMG12_CCP1                  ((uint32_t)0X00000009)
#define IOMUX_PINCM26_PF_TIMA_FAULT0                  ((uint32_t)0X0000000A)

/* IOMUX_PINCM27[PF] Bits */
#define IOMUX_PINCM27_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM27_PF_GPIOB_DIO06                  ((uint32_t)0X00000001)
#define IOMUX_PINCM27_PF_UART1_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM27_PF_SPI1_CS0                     ((uint32_t)0X00000003)
#define IOMUX_PINCM27_PF_I2C2_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM27_PF_TIMG8_CCP0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM27_PF_UART2_CTS                    ((uint32_t)0X00000006)
#define IOMUX_PINCM27_PF_TIMG4_CCP0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM27_PF_TIMA_FAULT2                  ((uint32_t)0X00000008)
#define IOMUX_PINCM27_PF_SPI0_CS1_POCI1               ((uint32_t)0X00000009)
#define IOMUX_PINCM27_PF_TIMG12_CCP0                  ((uint32_t)0X0000000A)

/* IOMUX_PINCM28[PF] Bits */
#define IOMUX_PINCM28_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM28_PF_GPIOB_DIO07                  ((uint32_t)0X00000001)
#define IOMUX_PINCM28_PF_UART1_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM28_PF_SPI1_POCI                    ((uint32_t)0X00000003)
#define IOMUX_PINCM28_PF_I2C2_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM28_PF_TIMG8_CCP1                   ((uint32_t)0X00000005)
#define IOMUX_PINCM28_PF_UART2_RTS                    ((uint32_t)0X00000006)
#define IOMUX_PINCM28_PF_TIMG4_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM28_PF_LCD_LCDLFCLK                 ((uint32_t)0X00000008)
#define IOMUX_PINCM28_PF_SPI0_CS2_POCI2               ((uint32_t)0X00000009)
#define IOMUX_PINCM28_PF_TIMG12_CCP1                  ((uint32_t)0X0000000A)

/* IOMUX_PINCM29[PF] Bits */
#define IOMUX_PINCM29_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM29_PF_GPIOB_DIO08                  ((uint32_t)0X00000001)
#define IOMUX_PINCM29_PF_UART1_CTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM29_PF_SPI1_PICO                    ((uint32_t)0X00000003)
#define IOMUX_PINCM29_PF_I2C2_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM29_PF_TIMA0_CCP0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM29_PF_COMP0_OUT                    ((uint32_t)0X00000006)
#define IOMUX_PINCM29_PF_TIMG4_CCP0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM29_PF_LCD_LCDSON                   ((uint32_t)0X00000008)

/* IOMUX_PINCM30[PF] Bits */
#define IOMUX_PINCM30_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM30_PF_GPIOB_DIO09                  ((uint32_t)0X00000001)
#define IOMUX_PINCM30_PF_UART1_RTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM30_PF_SPI1_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM30_PF_I2C2_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM30_PF_TIMA0_CCP0_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM30_PF_TIMA0_CCP1                   ((uint32_t)0X00000006)
#define IOMUX_PINCM30_PF_TIMG4_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM30_PF_LCD_LCDEN                    ((uint32_t)0X00000008)

/* IOMUX_PINCM31[PF] Bits */
#define IOMUX_PINCM31_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM31_PF_GPIOB_DIO10                  ((uint32_t)0X00000001)
#define IOMUX_PINCM31_PF_TIMG0_CCP0                   ((uint32_t)0X00000002)
#define IOMUX_PINCM31_PF_TIMG8_CCP0                   ((uint32_t)0X00000003)
#define IOMUX_PINCM31_PF_COMP0_OUT                    ((uint32_t)0X00000004)
#define IOMUX_PINCM31_PF_TIMG4_CCP0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM31_PF_UART4_TX                     ((uint32_t)0X00000006)
#define IOMUX_PINCM31_PF_SPI1_CS3_CD_POCI3            ((uint32_t)0X00000007)

/* IOMUX_PINCM32[PF] Bits */
#define IOMUX_PINCM32_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM32_PF_GPIOB_DIO11                  ((uint32_t)0X00000001)
#define IOMUX_PINCM32_PF_TIMG0_CCP1                   ((uint32_t)0X00000002)
#define IOMUX_PINCM32_PF_TIMG8_CCP1                   ((uint32_t)0X00000003)
#define IOMUX_PINCM32_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000004)
#define IOMUX_PINCM32_PF_TIMG4_CCP1                   ((uint32_t)0X00000005)
#define IOMUX_PINCM32_PF_UART4_RX                     ((uint32_t)0X00000006)
#define IOMUX_PINCM32_PF_SPI1_CS2_POCI2               ((uint32_t)0X00000007)

/* IOMUX_PINCM33[PF] Bits */
#define IOMUX_PINCM33_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM33_PF_GPIOB_DIO12                  ((uint32_t)0X00000001)
#define IOMUX_PINCM33_PF_UART3_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM33_PF_TIMA0_CCP2                   ((uint32_t)0X00000003)
#define IOMUX_PINCM33_PF_TIMA_FAULT1                  ((uint32_t)0X00000004)
#define IOMUX_PINCM33_PF_TIMA0_CCP1                   ((uint32_t)0X00000005)
#define IOMUX_PINCM33_PF_UART4_CTS                    ((uint32_t)0X00000006)
#define IOMUX_PINCM33_PF_SPI1_CS1_POCI1               ((uint32_t)0X00000007)

/* IOMUX_PINCM34[PF] Bits */
#define IOMUX_PINCM34_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM34_PF_GPIOB_DIO13                  ((uint32_t)0X00000001)
#define IOMUX_PINCM34_PF_UART3_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM34_PF_TIMA0_CCP3                   ((uint32_t)0X00000003)
#define IOMUX_PINCM34_PF_TIMG12_CCP0                  ((uint32_t)0X00000004)
#define IOMUX_PINCM34_PF_TIMA0_CCP1_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM34_PF_UART4_RTS                    ((uint32_t)0X00000006)
#define IOMUX_PINCM34_PF_SPI1_CS0                     ((uint32_t)0X00000007)

/* IOMUX_PINCM35[PF] Bits */
#define IOMUX_PINCM35_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM35_PF_GPIOB_DIO14                  ((uint32_t)0X00000001)
#define IOMUX_PINCM35_PF_SPI1_CS3_CD_POCI3            ((uint32_t)0X00000002)
#define IOMUX_PINCM35_PF_SPI1_POCI                    ((uint32_t)0X00000003)
#define IOMUX_PINCM35_PF_TIMG12_CCP1                  ((uint32_t)0X00000004)
#define IOMUX_PINCM35_PF_TIMA0_CCP0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM35_PF_TIMG8_IDX                    ((uint32_t)0X00000006)
#define IOMUX_PINCM35_PF_SPI0_CS3_CD_POCI3            ((uint32_t)0X00000007)

/* IOMUX_PINCM36[PF] Bits */
#define IOMUX_PINCM36_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM36_PF_GPIOB_DIO15                  ((uint32_t)0X00000001)
#define IOMUX_PINCM36_PF_UART2_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM36_PF_SPI1_PICO                    ((uint32_t)0X00000003)
#define IOMUX_PINCM36_PF_UART3_CTS                    ((uint32_t)0X00000004)
#define IOMUX_PINCM36_PF_TIMG8_CCP0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM36_PF_TIMG5_CCP0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM36_PF_I2C2_SCL                     ((uint32_t)0X00000007)

/* IOMUX_PINCM37[PF] Bits */
#define IOMUX_PINCM37_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM37_PF_GPIOB_DIO16                  ((uint32_t)0X00000001)
#define IOMUX_PINCM37_PF_UART2_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM37_PF_SPI1_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM37_PF_UART3_RTS                    ((uint32_t)0X00000004)
#define IOMUX_PINCM37_PF_TIMG8_CCP1                   ((uint32_t)0X00000005)
#define IOMUX_PINCM37_PF_TIMG5_CCP1                   ((uint32_t)0X00000006)
#define IOMUX_PINCM37_PF_I2C2_SDA                     ((uint32_t)0X00000007)

/* IOMUX_PINCM38[PF] Bits */
#define IOMUX_PINCM38_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM38_PF_GPIOA_DIO12                  ((uint32_t)0X00000001)
#define IOMUX_PINCM38_PF_UART3_CTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM38_PF_SPI0_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM38_PF_COMP0_OUT                    ((uint32_t)0X00000004)
#define IOMUX_PINCM38_PF_TIMA0_CCP3                   ((uint32_t)0X00000005)
#define IOMUX_PINCM38_PF_SYSCTL_FCC_IN                ((uint32_t)0X00000006)
#define IOMUX_PINCM38_PF_TIMG0_CCP0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM38_PF_SPI1_CS1_POCI1               ((uint32_t)0X00000008)
#define IOMUX_PINCM38_PF_SPI0_CS1_POCI1               ((uint32_t)0X00000009)
#define IOMUX_PINCM38_PF_UART2_CTS                    ((uint32_t)0X0000000A)
#define IOMUX_PINCM38_PF_UART1_CTS                    ((uint32_t)0X0000000B)

/* IOMUX_PINCM39[PF] Bits */
#define IOMUX_PINCM39_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM39_PF_GPIOA_DIO13                  ((uint32_t)0X00000001)
#define IOMUX_PINCM39_PF_UART3_RTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM39_PF_SPI0_POCI                    ((uint32_t)0X00000003)
#define IOMUX_PINCM39_PF_UART3_RX                     ((uint32_t)0X00000004)
#define IOMUX_PINCM39_PF_TIMA0_CCP3_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM39_PF_LFSS_RTC_OUT                 ((uint32_t)0X00000006)
#define IOMUX_PINCM39_PF_TIMG0_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM39_PF_SPI1_CS0                     ((uint32_t)0X00000008)
#define IOMUX_PINCM39_PF_SPI0_CS3_CD_POCI3            ((uint32_t)0X00000009)
#define IOMUX_PINCM39_PF_UART2_TX                     ((uint32_t)0X0000000A)
#define IOMUX_PINCM39_PF_UART1_RTS                    ((uint32_t)0X0000000B)

/* IOMUX_PINCM40[PF] Bits */
#define IOMUX_PINCM40_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM40_PF_GPIOA_DIO14                  ((uint32_t)0X00000001)
#define IOMUX_PINCM40_PF_UART0_CTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM40_PF_SPI0_PICO                    ((uint32_t)0X00000003)
#define IOMUX_PINCM40_PF_UART3_TX                     ((uint32_t)0X00000004)
#define IOMUX_PINCM40_PF_TIMG12_CCP0                  ((uint32_t)0X00000005)
#define IOMUX_PINCM40_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000006)
#define IOMUX_PINCM40_PF_TIMG12_CCP1                  ((uint32_t)0X00000007)
#define IOMUX_PINCM40_PF_SPI1_CS2_POCI2               ((uint32_t)0X00000008)
#define IOMUX_PINCM40_PF_SPI0_CS2_POCI2               ((uint32_t)0X00000009)
#define IOMUX_PINCM40_PF_UART2_RX                     ((uint32_t)0X0000000A)

/* IOMUX_PINCM41[PF] Bits */
#define IOMUX_PINCM41_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM41_PF_GPIOA_DIO15                  ((uint32_t)0X00000001)
#define IOMUX_PINCM41_PF_UART0_RTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM41_PF_SPI1_CS2_POCI2               ((uint32_t)0X00000003)
#define IOMUX_PINCM41_PF_I2C1_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM41_PF_TIMA0_CCP2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM41_PF_I2C2_SCL                     ((uint32_t)0X00000006)
#define IOMUX_PINCM41_PF_TIMG8_IDX                    ((uint32_t)0X00000007)
#define IOMUX_PINCM41_PF_TIMG12_CCP0                  ((uint32_t)0X00000008)
#define IOMUX_PINCM41_PF_LCD_LCDEN                    ((uint32_t)0X00000009)
#define IOMUX_PINCM41_PF_UART2_RTS                    ((uint32_t)0X0000000A)

/* IOMUX_PINCM42[PF] Bits */
#define IOMUX_PINCM42_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM42_PF_GPIOA_DIO16                  ((uint32_t)0X00000001)
#define IOMUX_PINCM42_PF_COMP0_OUT                    ((uint32_t)0X00000002)
#define IOMUX_PINCM42_PF_SPI1_POCI                    ((uint32_t)0X00000003)
#define IOMUX_PINCM42_PF_I2C1_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM42_PF_TIMA0_CCP2_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM42_PF_I2C2_SDA                     ((uint32_t)0X00000006)
#define IOMUX_PINCM42_PF_SYSCTL_FCC_IN                ((uint32_t)0X00000007)
#define IOMUX_PINCM42_PF_TIMG12_CCP1                  ((uint32_t)0X00000008)
#define IOMUX_PINCM42_PF_LCD_LCDSON                   ((uint32_t)0X00000009)
#define IOMUX_PINCM42_PF_UART2_CTS                    ((uint32_t)0X0000000A)

/* IOMUX_PINCM43[PF] Bits */
#define IOMUX_PINCM43_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM43_PF_GPIOC_DIO00                  ((uint32_t)0X00000001)
#define IOMUX_PINCM43_PF_UART1_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM43_PF_SPI1_CS3_CD_POCI3            ((uint32_t)0X00000003)
#define IOMUX_PINCM43_PF_TIMG8_CCP0                   ((uint32_t)0X00000004)
#define IOMUX_PINCM43_PF_TIMA0_CCP2                   ((uint32_t)0X00000005)

/* IOMUX_PINCM44[PF] Bits */
#define IOMUX_PINCM44_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM44_PF_GPIOC_DIO01                  ((uint32_t)0X00000001)
#define IOMUX_PINCM44_PF_UART1_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM44_PF_SPI1_CS2_POCI2               ((uint32_t)0X00000003)
#define IOMUX_PINCM44_PF_TIMG8_CCP1                   ((uint32_t)0X00000004)
#define IOMUX_PINCM44_PF_TIMA0_CCP2_CMPL              ((uint32_t)0X00000005)

/* IOMUX_PINCM45[PF] Bits */
#define IOMUX_PINCM45_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM45_PF_GPIOC_DIO02                  ((uint32_t)0X00000001)
#define IOMUX_PINCM45_PF_I2C2_SCL                     ((uint32_t)0X00000002)
#define IOMUX_PINCM45_PF_SPI1_CS0                     ((uint32_t)0X00000003)
#define IOMUX_PINCM45_PF_TIMA_FAULT0                  ((uint32_t)0X00000004)
#define IOMUX_PINCM45_PF_TIMA0_CCP0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM45_PF_TIMG0_CCP0                   ((uint32_t)0X00000006)

/* IOMUX_PINCM46[PF] Bits */
#define IOMUX_PINCM46_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM46_PF_GPIOC_DIO03                  ((uint32_t)0X00000001)
#define IOMUX_PINCM46_PF_I2C2_SDA                     ((uint32_t)0X00000002)
#define IOMUX_PINCM46_PF_SPI1_CS1_POCI1               ((uint32_t)0X00000003)
#define IOMUX_PINCM46_PF_TIMA_FAULT1                  ((uint32_t)0X00000004)
#define IOMUX_PINCM46_PF_TIMA0_CCP0_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM46_PF_TIMG0_CCP1                   ((uint32_t)0X00000006)

/* IOMUX_PINCM47[PF] Bits */
#define IOMUX_PINCM47_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM47_PF_GPIOC_DIO04                  ((uint32_t)0X00000001)
#define IOMUX_PINCM47_PF_UART3_CTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM47_PF_SPI1_CS2_POCI2               ((uint32_t)0X00000003)
#define IOMUX_PINCM47_PF_TIMA_FAULT2                  ((uint32_t)0X00000004)
#define IOMUX_PINCM47_PF_TIMA0_CCP1                   ((uint32_t)0X00000005)
#define IOMUX_PINCM47_PF_TIMG4_CCP0                   ((uint32_t)0X00000006)

/* IOMUX_PINCM48[PF] Bits */
#define IOMUX_PINCM48_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM48_PF_GPIOC_DIO05                  ((uint32_t)0X00000001)
#define IOMUX_PINCM48_PF_UART3_RTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM48_PF_SPI1_CS3_CD_POCI3            ((uint32_t)0X00000003)
#define IOMUX_PINCM48_PF_TIMG8_IDX                    ((uint32_t)0X00000004)
#define IOMUX_PINCM48_PF_TIMA0_CCP1_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM48_PF_TIMG4_CCP1                   ((uint32_t)0X00000006)

/* IOMUX_PINCM49[PF] Bits */
#define IOMUX_PINCM49_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM49_PF_GPIOA_DIO17                  ((uint32_t)0X00000001)
#define IOMUX_PINCM49_PF_UART1_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM49_PF_SPI1_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM49_PF_I2C1_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM49_PF_TIMA0_CCP3                   ((uint32_t)0X00000005)
#define IOMUX_PINCM49_PF_TIMG5_CCP0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM49_PF_TIMG8_CCP0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM49_PF_TIMG12_CCP0                  ((uint32_t)0X00000008)
#define IOMUX_PINCM49_PF_SPI0_CS1_POCI1               ((uint32_t)0X00000009)
#define IOMUX_PINCM49_PF_LCD_LCDLFCLK                 ((uint32_t)0X0000000A)

/* IOMUX_PINCM50[PF] Bits */
#define IOMUX_PINCM50_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM50_PF_GPIOA_DIO18                  ((uint32_t)0X00000001)
#define IOMUX_PINCM50_PF_UART1_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM50_PF_SPI1_PICO                    ((uint32_t)0X00000003)
#define IOMUX_PINCM50_PF_I2C1_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM50_PF_TIMA0_CCP3_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM50_PF_TIMG5_CCP1                   ((uint32_t)0X00000006)
#define IOMUX_PINCM50_PF_TIMG8_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM50_PF_TIMG12_CCP1                  ((uint32_t)0X00000008)
#define IOMUX_PINCM50_PF_SPI0_CS0                     ((uint32_t)0X00000009)
#define IOMUX_PINCM50_PF_LCD_LCDEN                    ((uint32_t)0X0000000A)

/* IOMUX_PINCM51[PF] Bits */
#define IOMUX_PINCM51_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM51_PF_GPIOA_DIO19                  ((uint32_t)0X00000001)
#define IOMUX_PINCM51_PF_DEBUGSS_SWDIO                ((uint32_t)0X00000002)
#define IOMUX_PINCM51_PF_SPI1_POCI                    ((uint32_t)0X00000003)
#define IOMUX_PINCM51_PF_I2C1_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM51_PF_TIMA0_CCP2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM51_PF_TIMG0_CCP0                   ((uint32_t)0X00000006)

/* IOMUX_PINCM52[PF] Bits */
#define IOMUX_PINCM52_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM52_PF_GPIOA_DIO20                  ((uint32_t)0X00000001)
#define IOMUX_PINCM52_PF_DEBUGSS_SWCLK                ((uint32_t)0X00000002)
#define IOMUX_PINCM52_PF_SPI1_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM52_PF_I2C1_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM52_PF_TIMA0_CCP2_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM52_PF_TIMG0_CCP1                   ((uint32_t)0X00000006)

/* IOMUX_PINCM53[PF] Bits */
#define IOMUX_PINCM53_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM53_PF_GPIOB_DIO17                  ((uint32_t)0X00000001)
#define IOMUX_PINCM53_PF_UART2_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM53_PF_SPI0_PICO                    ((uint32_t)0X00000003)
#define IOMUX_PINCM53_PF_I2C0_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM53_PF_TIMA0_CCP2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM53_PF_TIMG0_CCP0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM53_PF_SPI1_CS1_POCI1               ((uint32_t)0X00000007)
#define IOMUX_PINCM53_PF_UART4_TX                     ((uint32_t)0X00000008)
#define IOMUX_PINCM53_PF_TIMG4_CCP0                   ((uint32_t)0X00000009)
#define IOMUX_PINCM53_PF_LCD_LCDSON                   ((uint32_t)0X0000000A)

/* IOMUX_PINCM54[PF] Bits */
#define IOMUX_PINCM54_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM54_PF_GPIOB_DIO18                  ((uint32_t)0X00000001)
#define IOMUX_PINCM54_PF_UART2_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM54_PF_SPI0_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM54_PF_I2C0_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM54_PF_TIMA0_CCP2_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM54_PF_TIMG0_CCP1                   ((uint32_t)0X00000006)
#define IOMUX_PINCM54_PF_SPI1_CS2_POCI2               ((uint32_t)0X00000007)
#define IOMUX_PINCM54_PF_UART4_RX                     ((uint32_t)0X00000008)
#define IOMUX_PINCM54_PF_TIMG4_CCP1                   ((uint32_t)0X00000009)
#define IOMUX_PINCM54_PF_LCD_LCDLFCLK                 ((uint32_t)0X0000000A)

/* IOMUX_PINCM55[PF] Bits */
#define IOMUX_PINCM55_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM55_PF_GPIOB_DIO19                  ((uint32_t)0X00000001)
#define IOMUX_PINCM55_PF_COMP0_OUT                    ((uint32_t)0X00000002)
#define IOMUX_PINCM55_PF_SPI0_POCI                    ((uint32_t)0X00000003)
#define IOMUX_PINCM55_PF_TIMG8_CCP1                   ((uint32_t)0X00000004)
#define IOMUX_PINCM55_PF_UART0_CTS                    ((uint32_t)0X00000005)
#define IOMUX_PINCM55_PF_TIMG5_CCP1                   ((uint32_t)0X00000006)
#define IOMUX_PINCM55_PF_TIMG8_IDX                    ((uint32_t)0X00000007)
#define IOMUX_PINCM55_PF_UART2_CTS                    ((uint32_t)0X00000008)
#define IOMUX_PINCM55_PF_UART4_CTS                    ((uint32_t)0X00000009)
#define IOMUX_PINCM55_PF_SPI1_CS3_CD_POCI3            ((uint32_t)0X0000000A)

/* IOMUX_PINCM56[PF] Bits */
#define IOMUX_PINCM56_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM56_PF_GPIOA_DIO21                  ((uint32_t)0X00000001)
#define IOMUX_PINCM56_PF_UART2_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM56_PF_SPI0_CS3_CD_POCI3            ((uint32_t)0X00000003)
#define IOMUX_PINCM56_PF_UART1_CTS                    ((uint32_t)0X00000004)
#define IOMUX_PINCM56_PF_TIMA0_CCP0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM56_PF_TIMG4_CCP0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM56_PF_SPI1_CS1_POCI1               ((uint32_t)0X00000007)
#define IOMUX_PINCM56_PF_UART2_CTS                    ((uint32_t)0X00000008)
#define IOMUX_PINCM56_PF_UART4_RTS                    ((uint32_t)0X00000009)
#define IOMUX_PINCM56_PF_TIMG8_CCP0                   ((uint32_t)0X0000000A)

/* IOMUX_PINCM57[PF] Bits */
#define IOMUX_PINCM57_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM57_PF_GPIOA_DIO22                  ((uint32_t)0X00000001)
#define IOMUX_PINCM57_PF_UART2_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM57_PF_SPI0_CS2_POCI2               ((uint32_t)0X00000003)
#define IOMUX_PINCM57_PF_UART1_RTS                    ((uint32_t)0X00000004)
#define IOMUX_PINCM57_PF_TIMA0_CCP0_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM57_PF_TIMG4_CCP1                   ((uint32_t)0X00000006)
#define IOMUX_PINCM57_PF_TIMA0_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM57_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000008)
#define IOMUX_PINCM57_PF_I2C0_SCL                     ((uint32_t)0X00000009)
#define IOMUX_PINCM57_PF_TIMG8_CCP1                   ((uint32_t)0X0000000A)

/* IOMUX_PINCM58[PF] Bits */
#define IOMUX_PINCM58_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM58_PF_GPIOC_DIO06                  ((uint32_t)0X00000001)
#define IOMUX_PINCM58_PF_UART3_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM58_PF_SPI0_CS1_POCI1               ((uint32_t)0X00000003)
#define IOMUX_PINCM58_PF_TIMG8_CCP0                   ((uint32_t)0X00000004)
#define IOMUX_PINCM58_PF_TIMA0_CCP0                   ((uint32_t)0X00000005)

/* IOMUX_PINCM59[PF] Bits */
#define IOMUX_PINCM59_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM59_PF_GPIOC_DIO07                  ((uint32_t)0X00000001)
#define IOMUX_PINCM59_PF_UART3_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM59_PF_SPI0_CS0                     ((uint32_t)0X00000003)
#define IOMUX_PINCM59_PF_TIMG8_CCP1                   ((uint32_t)0X00000004)
#define IOMUX_PINCM59_PF_TIMA0_CCP0_CMPL              ((uint32_t)0X00000005)

/* IOMUX_PINCM60[PF] Bits */
#define IOMUX_PINCM60_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM60_PF_GPIOC_DIO08                  ((uint32_t)0X00000001)
#define IOMUX_PINCM60_PF_UART3_CTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM60_PF_SPI1_CS2_POCI2               ((uint32_t)0X00000003)
#define IOMUX_PINCM60_PF_TIMG5_CCP0                   ((uint32_t)0X00000004)
#define IOMUX_PINCM60_PF_TIMA0_CCP1                   ((uint32_t)0X00000005)

/* IOMUX_PINCM61[PF] Bits */
#define IOMUX_PINCM61_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM61_PF_GPIOC_DIO09                  ((uint32_t)0X00000001)
#define IOMUX_PINCM61_PF_UART3_RTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM61_PF_SPI1_CS1_POCI1               ((uint32_t)0X00000003)
#define IOMUX_PINCM61_PF_TIMG5_CCP1                   ((uint32_t)0X00000004)
#define IOMUX_PINCM61_PF_TIMA0_CCP1_CMPL              ((uint32_t)0X00000005)

/* IOMUX_PINCM62[PF] Bits */
#define IOMUX_PINCM62_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM62_PF_GPIOB_DIO20                  ((uint32_t)0X00000001)
#define IOMUX_PINCM62_PF_SPI0_CS2_POCI2               ((uint32_t)0X00000002)
#define IOMUX_PINCM62_PF_SPI1_CS0                     ((uint32_t)0X00000003)
#define IOMUX_PINCM62_PF_TIMG12_CCP0                  ((uint32_t)0X00000004)
#define IOMUX_PINCM62_PF_TIMA0_CCP2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM62_PF_TIMA_FAULT1                  ((uint32_t)0X00000006)
#define IOMUX_PINCM62_PF_TIMA0_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM62_PF_UART2_RTS                    ((uint32_t)0X00000008)
#define IOMUX_PINCM62_PF_I2C0_SDA                     ((uint32_t)0X00000009)

/* IOMUX_PINCM63[PF] Bits */
#define IOMUX_PINCM63_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM63_PF_GPIOB_DIO21                  ((uint32_t)0X00000001)
#define IOMUX_PINCM63_PF_UART4_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM63_PF_SPI1_POCI                    ((uint32_t)0X00000003)
#define IOMUX_PINCM63_PF_I2C0_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM63_PF_TIMG8_CCP0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM63_PF_UART1_TX                     ((uint32_t)0X00000006)

/* IOMUX_PINCM64[PF] Bits */
#define IOMUX_PINCM64_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM64_PF_GPIOB_DIO22                  ((uint32_t)0X00000001)
#define IOMUX_PINCM64_PF_UART4_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM64_PF_SPI1_PICO                    ((uint32_t)0X00000003)
#define IOMUX_PINCM64_PF_I2C0_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM64_PF_TIMG8_CCP1                   ((uint32_t)0X00000005)
#define IOMUX_PINCM64_PF_UART1_RX                     ((uint32_t)0X00000006)

/* IOMUX_PINCM65[PF] Bits */
#define IOMUX_PINCM65_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM65_PF_GPIOB_DIO23                  ((uint32_t)0X00000001)
#define IOMUX_PINCM65_PF_UART1_CTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM65_PF_SPI1_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM65_PF_TIMA_FAULT0                  ((uint32_t)0X00000004)
#define IOMUX_PINCM65_PF_COMP0_OUT                    ((uint32_t)0X00000005)

/* IOMUX_PINCM66[PF] Bits */
#define IOMUX_PINCM66_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM66_PF_GPIOB_DIO24                  ((uint32_t)0X00000001)
#define IOMUX_PINCM66_PF_SPI0_CS3_CD_POCI3            ((uint32_t)0X00000002)
#define IOMUX_PINCM66_PF_SPI0_CS1_POCI1               ((uint32_t)0X00000003)
#define IOMUX_PINCM66_PF_TIMG12_CCP1                  ((uint32_t)0X00000004)
#define IOMUX_PINCM66_PF_TIMA0_CCP3                   ((uint32_t)0X00000005)
#define IOMUX_PINCM66_PF_TIMA0_CCP1_CMPL              ((uint32_t)0X00000006)
#define IOMUX_PINCM66_PF_SPI1_CS1_POCI1               ((uint32_t)0X00000007)
#define IOMUX_PINCM66_PF_UART2_RTS                    ((uint32_t)0X00000008)

/* IOMUX_PINCM67[PF] Bits */
#define IOMUX_PINCM67_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM67_PF_GPIOA_DIO23                  ((uint32_t)0X00000001)
#define IOMUX_PINCM67_PF_UART2_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM67_PF_SPI0_CS3_CD_POCI3            ((uint32_t)0X00000003)
#define IOMUX_PINCM67_PF_I2C2_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM67_PF_TIMA0_CCP3                   ((uint32_t)0X00000005)
#define IOMUX_PINCM67_PF_TIMG8_CCP0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM67_PF_TIMG5_CCP0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM67_PF_UART3_CTS                    ((uint32_t)0X00000008)
#define IOMUX_PINCM67_PF_TIMG0_CCP0                   ((uint32_t)0X00000009)
#define IOMUX_PINCM67_PF_SPI1_CS1_POCI1               ((uint32_t)0X0000000A)

/* IOMUX_PINCM68[PF] Bits */
#define IOMUX_PINCM68_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM68_PF_GPIOA_DIO24                  ((uint32_t)0X00000001)
#define IOMUX_PINCM68_PF_UART2_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM68_PF_SPI0_CS2_POCI2               ((uint32_t)0X00000003)
#define IOMUX_PINCM68_PF_I2C2_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM68_PF_TIMA0_CCP3_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM68_PF_TIMG8_CCP1                   ((uint32_t)0X00000006)
#define IOMUX_PINCM68_PF_TIMG5_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM68_PF_UART3_RTS                    ((uint32_t)0X00000008)
#define IOMUX_PINCM68_PF_TIMG0_CCP1                   ((uint32_t)0X00000009)
#define IOMUX_PINCM68_PF_SPI1_CS2_POCI2               ((uint32_t)0X0000000A)

/* IOMUX_PINCM69[PF] Bits */
#define IOMUX_PINCM69_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM69_PF_GPIOA_DIO25                  ((uint32_t)0X00000001)
#define IOMUX_PINCM69_PF_UART3_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM69_PF_SPI1_CS3_CD_POCI3            ((uint32_t)0X00000003)
#define IOMUX_PINCM69_PF_TIMG12_CCP1                  ((uint32_t)0X00000004)
#define IOMUX_PINCM69_PF_TIMA0_CCP3                   ((uint32_t)0X00000005)
#define IOMUX_PINCM69_PF_TIMA0_CCP1_CMPL              ((uint32_t)0X00000006)
#define IOMUX_PINCM69_PF_COMP0_OUT                    ((uint32_t)0X00000007)
#define IOMUX_PINCM69_PF_UART2_CTS                    ((uint32_t)0X00000008)
#define IOMUX_PINCM69_PF_UART3_TX                     ((uint32_t)0X00000009)
#define IOMUX_PINCM69_PF_TIMG4_CCP0                   ((uint32_t)0X0000000A)

/* IOMUX_PINCM70[PF] Bits */
#define IOMUX_PINCM70_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM70_PF_GPIOB_DIO25                  ((uint32_t)0X00000001)
#define IOMUX_PINCM70_PF_UART0_CTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM70_PF_SPI0_CS0                     ((uint32_t)0X00000003)
#define IOMUX_PINCM70_PF_TIMA_FAULT0                  ((uint32_t)0X00000004)
#define IOMUX_PINCM70_PF_TIMA_FAULT1                  ((uint32_t)0X00000005)
#define IOMUX_PINCM70_PF_TIMA_FAULT2                  ((uint32_t)0X00000006)
#define IOMUX_PINCM70_PF_COMP0_OUT                    ((uint32_t)0X00000007)
#define IOMUX_PINCM70_PF_SYSCTL_FCC_IN                ((uint32_t)0X00000008)

/* IOMUX_PINCM71[PF] Bits */
#define IOMUX_PINCM71_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM71_PF_GPIOB_DIO26                  ((uint32_t)0X00000001)
#define IOMUX_PINCM71_PF_UART0_RTS                    ((uint32_t)0X00000002)
#define IOMUX_PINCM71_PF_SPI0_CS1_POCI1               ((uint32_t)0X00000003)
#define IOMUX_PINCM71_PF_TIMA0_CCP0                   ((uint32_t)0X00000004)
#define IOMUX_PINCM71_PF_TIMA0_CCP3                   ((uint32_t)0X00000005)
#define IOMUX_PINCM71_PF_TIMG4_CCP0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM71_PF_COMP0_OUT                    ((uint32_t)0X00000007)
#define IOMUX_PINCM71_PF_SYSCTL_FCC_IN                ((uint32_t)0X00000008)

/* IOMUX_PINCM72[PF] Bits */
#define IOMUX_PINCM72_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM72_PF_GPIOB_DIO27                  ((uint32_t)0X00000001)
#define IOMUX_PINCM72_PF_COMP0_OUT                    ((uint32_t)0X00000002)
#define IOMUX_PINCM72_PF_SPI1_CS1_POCI1               ((uint32_t)0X00000003)
#define IOMUX_PINCM72_PF_TIMA0_CCP0_CMPL              ((uint32_t)0X00000004)
#define IOMUX_PINCM72_PF_TIMA0_CCP3_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM72_PF_TIMG4_CCP1                   ((uint32_t)0X00000006)

/* IOMUX_PINCM73[PF] Bits */
#define IOMUX_PINCM73_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM73_PF_GPIOA_DIO26                  ((uint32_t)0X00000001)
#define IOMUX_PINCM73_PF_UART3_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM73_PF_SPI1_CS0                     ((uint32_t)0X00000003)
#define IOMUX_PINCM73_PF_TIMG8_CCP0                   ((uint32_t)0X00000004)
#define IOMUX_PINCM73_PF_TIMA_FAULT0                  ((uint32_t)0X00000005)
#define IOMUX_PINCM73_PF_TIMA0_CCP3_CMPL              ((uint32_t)0X00000006)
#define IOMUX_PINCM73_PF_TIMG5_CCP0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM73_PF_UART2_RTS                    ((uint32_t)0X00000008)
#define IOMUX_PINCM73_PF_UART3_RX                     ((uint32_t)0X00000009)
#define IOMUX_PINCM73_PF_TIMG4_CCP1                   ((uint32_t)0X0000000A)

/* IOMUX_PINCM74[PF] Bits */
#define IOMUX_PINCM74_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM74_PF_GPIOA_DIO27                  ((uint32_t)0X00000001)
#define IOMUX_PINCM74_PF_UART3_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM74_PF_SPI1_CS1_POCI1               ((uint32_t)0X00000003)
#define IOMUX_PINCM74_PF_TIMG8_CCP1                   ((uint32_t)0X00000004)
#define IOMUX_PINCM74_PF_TIMA_FAULT2                  ((uint32_t)0X00000005)
#define IOMUX_PINCM74_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000006)
#define IOMUX_PINCM74_PF_TIMG5_CCP1                   ((uint32_t)0X00000007)
#define IOMUX_PINCM74_PF_LFSS_RTC_OUT                 ((uint32_t)0X00000008)
#define IOMUX_PINCM74_PF_COMP0_OUT                    ((uint32_t)0X00000009)


#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/*@}*/ /* end of group MSPM0L122X_PeripheralDecl */

/*@}*/ /* end of group MSPM0L122X_Definitions */

#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_m0p_mspm0l122x__include */