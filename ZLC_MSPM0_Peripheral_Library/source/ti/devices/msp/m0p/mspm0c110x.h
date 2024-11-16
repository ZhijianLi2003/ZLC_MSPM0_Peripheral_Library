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

#ifndef ti_devices_msp_m0p_mspm0c110x__include
#define ti_devices_msp_m0p_mspm0c110x__include

/* Filename: mspm0c110x.h */
/* Revised: 2023-06-19 05:18:05 */

/* Use standard integer types with explicit width */
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup MSPM0C110X_Definitions MSPM0C110X Definitions
  This file defines all structures and symbols for MSPM0C110X
  @{
*/

/** @addtogroup MSPM0C110X_CMSIS Device CMSIS Definitions
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
  FLASHCTL_INT_IRQn           = 0,      /* 16 FLASHCTL_INT Interrupt */
  DEBUGSS_INT_IRQn            = 0,      /* 16 DEBUGSS_INT Interrupt */
  SYSCTL_INT_IRQn             = 0,      /* 16 SYSCTL_INT Interrupt */
  WWDT0_INT_IRQn              = 0,      /* 16 WWDT0_INT Interrupt */
  GPIOA_INT_IRQn              = 1,      /* 17 GPIOA_INT Interrupt */
  TIMG8_INT_IRQn              = 2,      /* 18 TIMG8_INT Interrupt */
  ADC0_INT_IRQn               = 4,      /* 20 ADC0_INT Interrupt */
  SPI0_INT_IRQn               = 9,      /* 25 SPI0_INT Interrupt */
  UART0_INT_IRQn              = 15,     /* 31 UART0_INT Interrupt */
  TIMG14_INT_IRQn             = 16,     /* 32 TIMG14_INT Interrupt */
  TIMA0_INT_IRQn              = 18,     /* 34 TIMA0_INT Interrupt */
  I2C0_INT_IRQn               = 24,     /* 40 I2C0_INT Interrupt */
  DMA_INT_IRQn                = 31,     /* 47 DMA_INT Interrupt */
} IRQn_Type;

#define NonMaskableInt_VECn     2     /* Non Maskable Interrupt */
#define HardFault_VECn          3     /* Hard Fault Interrupt */
#define SVCall_VECn             11    /* SV Call Interrupt */
#define PendSV_VECn             14    /* Pend SV Interrupt */
#define SysTick_VECn            15    /* System Tick Interrupt */
#define FLASHCTL_INT_VECn       16    /* FLASHCTL_INT Interrupt */
#define DEBUGSS_INT_VECn        16    /* DEBUGSS_INT Interrupt */
#define SYSCTL_INT_VECn         16    /* SYSCTL_INT Interrupt */
#define WWDT0_INT_VECn          16    /* WWDT0_INT Interrupt */
#define GPIOA_INT_VECn          17    /* GPIOA_INT Interrupt */
#define TIMG8_INT_VECn          18    /* TIMG8_INT Interrupt */
#define ADC0_INT_VECn           20    /* ADC0_INT Interrupt */
#define SPI0_INT_VECn           25    /* SPI0_INT Interrupt */
#define UART0_INT_VECn          31    /* UART0_INT Interrupt */
#define TIMG14_INT_VECn         32    /* TIMG14_INT Interrupt */
#define TIMA0_INT_VECn          34    /* TIMA0_INT Interrupt */
#define I2C0_INT_VECn           40    /* I2C0_INT Interrupt */
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
/** @addtogroup MSPM0C110X_Peripherals MSPM0C110X Peripherals
  MSPM0C110X Peripheral registers structures
  @{
*/

#include <ti/devices/msp/peripherals/hw_adc12.h>
#include <ti/devices/msp/peripherals/hw_crc.h>
#include <ti/devices/msp/peripherals/hw_dma.h>
#include <ti/devices/msp/peripherals/hw_flashctl.h>
#include <ti/devices/msp/peripherals/hw_gpio.h>
#include <ti/devices/msp/peripherals/hw_gptimer.h>
#include <ti/devices/msp/peripherals/hw_i2c.h>
#include <ti/devices/msp/peripherals/hw_iomux.h>
#include <ti/devices/msp/peripherals/hw_spi.h>
#include <ti/devices/msp/peripherals/hw_uart.h>
#include <ti/devices/msp/peripherals/hw_vref.h>
#include <ti/devices/msp/peripherals/hw_wuc.h>
#include <ti/devices/msp/peripherals/hw_wwdt.h>
#include <ti/devices/msp/peripherals/m0p/hw_factoryregion.h>
#include <ti/devices/msp/peripherals/m0p/hw_cpuss.h>
#include <ti/devices/msp/peripherals/m0p/hw_debugss.h>
#include <ti/devices/msp/peripherals/m0p/hw_sysctl.h>

#define __MSPM0_HAS_ADC12__
#define __MSPM0_HAS_CRC__
#define __MSPM0_HAS_GPIO__
#define __MSPM0_HAS_TIMER_A__
#define __MSPM0_HAS_TIMER_G__
#define __MSPM0_HAS_I2C__
#define __MSPM0_HAS_SPI__
#define __MSPM0_HAS_UART_EXTD__
#define __MSPM0_HAS_UART_MAIN__
#define __MSPM0_HAS_VREF__
#define __MSPM0_HAS_WWDT__

#define MSPM0C110X_ADC_ERR_06

/*@}*/ /* end of group MSPM0C110X_Peripherals */

/******************************************************************************
* Device and peripheral memory map                                            *
******************************************************************************/
/** @addtogroup MSPM0C110X_MemoryMap MSPM0C110X Memory Mapping
  @{
*/

#define FLASHCTL_BASE                  (0x400CD000U)     /*!< Base address of module FLASHCTL */
#define IOMUX_BASE                     (0x40428000U)     /*!< Base address of module IOMUX */
#define DEBUGSS_BASE                   (0x400C7000U)     /*!< Base address of module DEBUGSS */
#define SYSCTL_BASE                    (0x400AF000U)     /*!< Base address of module SYSCTL */
#define CRC_BASE                       (0x40440000U)     /*!< Base address of module CRC */
#define WWDT0_BASE                     (0x40080000U)     /*!< Base address of module WWDT0 */
#define UART0_BASE                     (0x40108000U)     /*!< Base address of module UART0 */
#define GPIOA_BASE                     (0x400A0000U)     /*!< Base address of module GPIOA */
#define I2C0_BASE                      (0x400F0000U)     /*!< Base address of module I2C0 */
#define DMA_BASE                       (0x4042A000U)     /*!< Base address of module DMA */
#define CPUSS_BASE                     (0x40400000U)     /*!< Base address of module CPUSS */
#define ADC0_BASE                      (0x40004000U)     /*!< Base address of module ADC0 */
#define ADC0_PERIPHERALREGIONSVT_BASE  (0x4055A000U)     /*!< Base address of module ADC0_PERIPHERALREGIONSVT */
#define SPI0_BASE                      (0x40468000U)     /*!< Base address of module SPI0 */
#define WUC_BASE                       (0x40424000U)     /*!< Base address of module WUC */
#define FACTORYREGION_BASE             (0x41C40000U)     /*!< Base address of module FACTORYREGION */
#define VREF_BASE                      (0x40030000U)     /*!< Base address of module VREF */
#define TIMA0_BASE                     (0x40860000U)     /*!< Base address of module TIMA0 */
#define TIMG8_BASE                     (0x40090000U)     /*!< Base address of module TIMG8 */
#define TIMG14_BASE                    (0x40084000U)     /*!< Base address of module TIMG14 */


/*@}*/ /* end of group MSPM0C110X_MemoryMap */

/******************************************************************************
* Peripheral declarations                                                     *
******************************************************************************/
/** @addtogroup MSPM0C110X_PeripheralDecl MSPM0C110X Peripheral Declaration
  @{
*/

static FLASHCTL_Regs                            * const FLASHCTL                       = ((FLASHCTL_Regs *) FLASHCTL_BASE);
static IOMUX_Regs                               * const IOMUX                          = ((IOMUX_Regs *) IOMUX_BASE);
static DEBUGSS_Regs                             * const DEBUGSS                        = ((DEBUGSS_Regs *) DEBUGSS_BASE);
static SYSCTL_Regs                              * const SYSCTL                         = ((SYSCTL_Regs *) SYSCTL_BASE);
static CRC_Regs                                 * const CRC                            = ((CRC_Regs *) CRC_BASE);
static WWDT_Regs                                * const WWDT0                          = ((WWDT_Regs *) WWDT0_BASE);
static UART_Regs                                * const UART0                          = ((UART_Regs *) UART0_BASE);
static GPIO_Regs                                * const GPIOA                          = ((GPIO_Regs *) GPIOA_BASE);
static I2C_Regs                                 * const I2C0                           = ((I2C_Regs *) I2C0_BASE);
static DMA_Regs                                 * const DMA                            = ((DMA_Regs *) DMA_BASE);
static CPUSS_Regs                               * const CPUSS                          = ((CPUSS_Regs *) CPUSS_BASE);
static ADC12_Regs                               * const ADC0                           = ((ADC12_Regs *) ADC0_BASE);
static ADC12_PERIPHERALREGIONSVT_Regs           * const ADC0_PERIPHERALREGIONSVT       = ((ADC12_PERIPHERALREGIONSVT_Regs *) ADC0_PERIPHERALREGIONSVT_BASE);
static SPI_Regs                                 * const SPI0                           = ((SPI_Regs *) SPI0_BASE);
static WUC_Regs                                 * const WUC                            = ((WUC_Regs *) WUC_BASE);
static FACTORYREGION_OPEN_Regs                  * const FACTORYREGION                  = ((FACTORYREGION_OPEN_Regs *) FACTORYREGION_BASE);
static VREF_Regs                                * const VREF                           = ((VREF_Regs *) VREF_BASE);
static GPTIMER_Regs                             * const TIMA0                          = ((GPTIMER_Regs *) TIMA0_BASE);
static GPTIMER_Regs                             * const TIMG8                          = ((GPTIMER_Regs *) TIMG8_BASE);
static GPTIMER_Regs                             * const TIMG14                         = ((GPTIMER_Regs *) TIMG14_BASE);


/******************************************************************************
* SYS parameters                                                              *
******************************************************************************/

#define DMA_SYS_N_DMA_CHANNEL                         (1)       /* !< Number of DMA channels implemented in DMA. */
#define DMA_SYS_N_DMA_FULL_CHANNEL                    (0)       /* !< Number of FULL-DMA channels implemented in DMA. */
#define CRC_SYS_CRC32_ENABLE                          (0)       /* !< Parameter to exclude or include 32-bit CRC. */
#define FLASHCTL_SYS_DATAWIDTH                        (64)      /* !< Data bit width of a single flash word. */
#define ADC_SYS_NUM_ANALOG_CHAN                       (16)      /* !< Number of analog channels. */
#define I2C_SYS_FENTRIES                              (4)       /* !< Number of FIFO entries */
#define FLASHCTL_SYS_WEPROTAWIDTH                     (16)      /* !< Bit width of WEPROTA register */
#define FLASHCTL_SYS_WEPROTBWIDTH                     (0)       /* !< Bit width of WEPROTB register */
#define FLASHCTL_SYS_WEPROTCWIDTH                     (0)       /* !< Bit width of WEPROTC register */

/******************************************************************************
* DMA Triggers                                                                *
******************************************************************************/

/* External DMA Triggers */
#define DMA_SOFTWARE_TRIG                             (0)
#define DMA_GENERIC_SUB0_TRIG                         (1)
#define DMA_GENERIC_SUB1_TRIG                         (2)
#define DMA_ADC0_EVT_GEN_BD_TRIG                      (3)

/* Internal DMA Triggers */
#define DMA_CH_0_TRIG                                 (0)


/******************************************************************************
* IOMUX Pin Definitions                                                       *
******************************************************************************/

typedef enum IOMUX_PINCM
{
  IOMUX_PINCM1         = (0),
  IOMUX_PINCM2         = (1),
  IOMUX_PINCM3         = (2),
  IOMUX_PINCM5         = (4),
  IOMUX_PINCM7         = (6),
  IOMUX_PINCM12        = (11),
  IOMUX_PINCM17        = (16),
  IOMUX_PINCM18        = (17),
  IOMUX_PINCM19        = (18),
  IOMUX_PINCM20        = (19),
  IOMUX_PINCM21        = (20),
  IOMUX_PINCM23        = (22),
  IOMUX_PINCM24        = (23),
  IOMUX_PINCM25        = (24),
  IOMUX_PINCM26        = (25),
  IOMUX_PINCM27        = (26),
  IOMUX_PINCM28        = (27),
  IOMUX_PINCM29        = (28),
} IOMUX_PINCM;


/* IOMUX_PINCM1[PF] Bits */
#define IOMUX_PINCM1_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM1_PF_GPIOA_DIO00                   ((uint32_t)0X00000001)
#define IOMUX_PINCM1_PF_SYSCTL_BEEPER                 ((uint32_t)0X00000002)
#define IOMUX_PINCM1_PF_I2C0_SDA                      ((uint32_t)0X00000003)
#define IOMUX_PINCM1_PF_TIMG8_CCP0                    ((uint32_t)0X00000004)
#define IOMUX_PINCM1_PF_SPI0_CS1_POCI1                ((uint32_t)0X00000005)
#define IOMUX_PINCM1_PF_SYSCTL_FCC_IN                 ((uint32_t)0X00000006)
#define IOMUX_PINCM1_PF_TIMA_FAULT1                   ((uint32_t)0X00000007)

/* IOMUX_PINCM2[PF] Bits */
#define IOMUX_PINCM2_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM2_PF_GPIOA_DIO01                   ((uint32_t)0X00000001)
#define IOMUX_PINCM2_PF_I2C0_SCL                      ((uint32_t)0X00000003)
#define IOMUX_PINCM2_PF_TIMG8_CCP1                    ((uint32_t)0X00000004)
#define IOMUX_PINCM2_PF_SYSCTL_HFCLKIN                ((uint32_t)0X00000005)
#define IOMUX_PINCM2_PF_TIMA0_CCP1                    ((uint32_t)0X00000007)

/* IOMUX_PINCM3[PF] Bits */
#define IOMUX_PINCM3_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM3_PF_GPIOA_DIO02                   ((uint32_t)0X00000001)
#define IOMUX_PINCM3_PF_TIMG8_CCP1                    ((uint32_t)0X00000002)
#define IOMUX_PINCM3_PF_SPI0_CS0                      ((uint32_t)0X00000003)
#define IOMUX_PINCM3_PF_TIMA0_CCP0                    ((uint32_t)0X00000004)
#define IOMUX_PINCM3_PF_TIMG8_IDX                     ((uint32_t)0X00000007)

/* IOMUX_PINCM5[PF] Bits */
#define IOMUX_PINCM5_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM5_PF_GPIOA_DIO04                   ((uint32_t)0X00000001)
#define IOMUX_PINCM5_PF_TIMA0_CCP0_CMPL               ((uint32_t)0X00000002)
#define IOMUX_PINCM5_PF_SPI0_POCI                     ((uint32_t)0X00000003)
#define IOMUX_PINCM5_PF_SYSCTL_LFCLKIN                ((uint32_t)0X00000004)
#define IOMUX_PINCM5_PF_SYSCTL_HFCLKIN                ((uint32_t)0X00000005)
#define IOMUX_PINCM5_PF_TIMA0_CCP1_CMPL               ((uint32_t)0X00000007)

/* IOMUX_PINCM7[PF] Bits */
#define IOMUX_PINCM7_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM7_PF_GPIOA_DIO06                   ((uint32_t)0X00000001)
#define IOMUX_PINCM7_PF_TIMG14_CCP1                   ((uint32_t)0X00000002)
#define IOMUX_PINCM7_PF_SPI0_SCLK                     ((uint32_t)0X00000003)
#define IOMUX_PINCM7_PF_TIMA0_CCP1                    ((uint32_t)0X00000004)
#define IOMUX_PINCM7_PF_TIMG14_CCP2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM7_PF_SPI0_CS0                      ((uint32_t)0X00000006)
#define IOMUX_PINCM7_PF_TIMA_FAULT0                   ((uint32_t)0X00000007)

/* IOMUX_PINCM12[PF] Bits */
#define IOMUX_PINCM12_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM12_PF_GPIOA_DIO11                  ((uint32_t)0X00000001)
#define IOMUX_PINCM12_PF_SPI0_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM12_PF_I2C0_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM12_PF_TIMA_FAULT0                  ((uint32_t)0X00000005)

/* IOMUX_PINCM17[PF] Bits */
#define IOMUX_PINCM17_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM17_PF_GPIOA_DIO16                  ((uint32_t)0X00000001)
#define IOMUX_PINCM17_PF_TIMA0_CCP1_CMPL              ((uint32_t)0X00000002)
#define IOMUX_PINCM17_PF_SPI0_POCI                    ((uint32_t)0X00000004)
#define IOMUX_PINCM17_PF_TIMG14_CCP0                  ((uint32_t)0X00000005)
#define IOMUX_PINCM17_PF_SYSCTL_FCC_IN                ((uint32_t)0X00000006)

/* IOMUX_PINCM18[PF] Bits */
#define IOMUX_PINCM18_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM18_PF_GPIOA_DIO17                  ((uint32_t)0X00000001)
#define IOMUX_PINCM18_PF_UART0_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM18_PF_TIMA0_CCP0_CMPL              ((uint32_t)0X00000003)
#define IOMUX_PINCM18_PF_SPI0_SCLK                    ((uint32_t)0X00000004)
#define IOMUX_PINCM18_PF_TIMA0_CCP2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM18_PF_SPI0_CS1_POCI1               ((uint32_t)0X00000006)
#define IOMUX_PINCM18_PF_TIMA0_CCP3                   ((uint32_t)0X00000007)

/* IOMUX_PINCM19[PF] Bits */
#define IOMUX_PINCM19_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM19_PF_GPIOA_DIO18                  ((uint32_t)0X00000001)
#define IOMUX_PINCM19_PF_UART0_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM19_PF_SPI0_PICO                    ((uint32_t)0X00000003)
#define IOMUX_PINCM19_PF_TIMA0_CCP1_CMPL              ((uint32_t)0X00000004)
#define IOMUX_PINCM19_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000005)
#define IOMUX_PINCM19_PF_TIMA0_CCP3                   ((uint32_t)0X00000006)
#define IOMUX_PINCM19_PF_TIMA0_CCP3_CMPL              ((uint32_t)0X00000007)

/* IOMUX_PINCM20[PF] Bits */
#define IOMUX_PINCM20_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM20_PF_GPIOA_DIO19                  ((uint32_t)0X00000001)
#define IOMUX_PINCM20_PF_DEBUGSS_SWDIO                ((uint32_t)0X00000002)
#define IOMUX_PINCM20_PF_SPI0_SCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM20_PF_SPI0_POCI                    ((uint32_t)0X00000004)
#define IOMUX_PINCM20_PF_TIMA0_CCP2                   ((uint32_t)0X00000005)
#define IOMUX_PINCM20_PF_TIMG14_CCP0                  ((uint32_t)0X00000006)
#define IOMUX_PINCM20_PF_UART0_CTS                    ((uint32_t)0X00000007)

/* IOMUX_PINCM21[PF] Bits */
#define IOMUX_PINCM21_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM21_PF_GPIOA_DIO20                  ((uint32_t)0X00000001)
#define IOMUX_PINCM21_PF_DEBUGSS_SWCLK                ((uint32_t)0X00000002)
#define IOMUX_PINCM21_PF_TIMA_FAULT1                  ((uint32_t)0X00000003)
#define IOMUX_PINCM21_PF_SPI0_PICO                    ((uint32_t)0X00000004)
#define IOMUX_PINCM21_PF_TIMA0_CCP2_CMPL              ((uint32_t)0X00000005)
#define IOMUX_PINCM21_PF_TIMA0_CCP0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM21_PF_UART0_RTS                    ((uint32_t)0X00000007)

/* IOMUX_PINCM23[PF] Bits */
#define IOMUX_PINCM23_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM23_PF_GPIOA_DIO22                  ((uint32_t)0X00000001)
#define IOMUX_PINCM23_PF_UART0_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM23_PF_SPI0_POCI                    ((uint32_t)0X00000003)
#define IOMUX_PINCM23_PF_UART0_RTS                    ((uint32_t)0X00000004)
#define IOMUX_PINCM23_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000005)
#define IOMUX_PINCM23_PF_TIMA0_CCP1                   ((uint32_t)0X00000006)

/* IOMUX_PINCM24[PF] Bits */
#define IOMUX_PINCM24_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM24_PF_GPIOA_DIO23                  ((uint32_t)0X00000001)
#define IOMUX_PINCM24_PF_UART0_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM24_PF_SPI0_CS3_CD_POCI3            ((uint32_t)0X00000003)
#define IOMUX_PINCM24_PF_TIMG14_CCP0                  ((uint32_t)0X00000004)
#define IOMUX_PINCM24_PF_UART0_CTS                    ((uint32_t)0X00000005)
#define IOMUX_PINCM24_PF_TIMA0_CCP3                   ((uint32_t)0X00000006)
#define IOMUX_PINCM24_PF_TIMG14_CCP1                  ((uint32_t)0X00000007)

/* IOMUX_PINCM25[PF] Bits */
#define IOMUX_PINCM25_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM25_PF_GPIOA_DIO24                  ((uint32_t)0X00000001)
#define IOMUX_PINCM25_PF_SPI0_CS2_POCI2               ((uint32_t)0X00000002)
#define IOMUX_PINCM25_PF_TIMG14_CCP1                  ((uint32_t)0X00000003)
#define IOMUX_PINCM25_PF_UART0_RTS                    ((uint32_t)0X00000004)
#define IOMUX_PINCM25_PF_TIMG14_CCP2                  ((uint32_t)0X00000005)
#define IOMUX_PINCM25_PF_TIMA0_CCP3_CMPL              ((uint32_t)0X00000006)
#define IOMUX_PINCM25_PF_UART0_RX                     ((uint32_t)0X00000007)

/* IOMUX_PINCM26[PF] Bits */
#define IOMUX_PINCM26_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM26_PF_GPIOA_DIO25                  ((uint32_t)0X00000001)
#define IOMUX_PINCM26_PF_TIMG14_CCP3                  ((uint32_t)0X00000002)
#define IOMUX_PINCM26_PF_UART0_TX                     ((uint32_t)0X00000003)
#define IOMUX_PINCM26_PF_SPI0_PICO                    ((uint32_t)0X00000004)
#define IOMUX_PINCM26_PF_TIMG14_CCP1                  ((uint32_t)0X00000005)
#define IOMUX_PINCM26_PF_TIMA_FAULT2                  ((uint32_t)0X00000006)

/* IOMUX_PINCM27[PF] Bits */
#define IOMUX_PINCM27_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM27_PF_GPIOA_DIO26                  ((uint32_t)0X00000001)
#define IOMUX_PINCM27_PF_TIMG8_CCP0                   ((uint32_t)0X00000002)
#define IOMUX_PINCM27_PF_UART0_RX                     ((uint32_t)0X00000003)
#define IOMUX_PINCM27_PF_SPI0_POCI                    ((uint32_t)0X00000004)
#define IOMUX_PINCM27_PF_SYSCTL_BEEPER                ((uint32_t)0X00000005)
#define IOMUX_PINCM27_PF_TIMG14_CCP0                  ((uint32_t)0X00000006)
#define IOMUX_PINCM27_PF_TIMA_FAULT0                  ((uint32_t)0X00000007)

/* IOMUX_PINCM28[PF] Bits */
#define IOMUX_PINCM28_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM28_PF_GPIOA_DIO27                  ((uint32_t)0X00000001)
#define IOMUX_PINCM28_PF_TIMG8_CCP1                   ((uint32_t)0X00000002)
#define IOMUX_PINCM28_PF_SPI0_CS3_CD_POCI3            ((uint32_t)0X00000003)
#define IOMUX_PINCM28_PF_TIMA0_CCP0_CMPL              ((uint32_t)0X00000004)
#define IOMUX_PINCM28_PF_UART0_TX                     ((uint32_t)0X00000005)
#define IOMUX_PINCM28_PF_SPI0_POCI                    ((uint32_t)0X00000006)
#define IOMUX_PINCM28_PF_TIMA_FAULT2                  ((uint32_t)0X00000007)

/* IOMUX_PINCM29[PF] Bits */
#define IOMUX_PINCM29_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM29_PF_GPIOA_DIO28                  ((uint32_t)0X00000001)
#define IOMUX_PINCM29_PF_TIMA0_CCP0                   ((uint32_t)0X00000002)
#define IOMUX_PINCM29_PF_UART0_RX                     ((uint32_t)0X00000005)
#define IOMUX_PINCM29_PF_TIMG8_IDX                    ((uint32_t)0X00000007)

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

/*@}*/ /* end of group MSPM0C110X_PeripheralDecl */

/*@}*/ /* end of group MSPM0C110X_Definitions */

#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_m0p_mspm0c110x__include */

