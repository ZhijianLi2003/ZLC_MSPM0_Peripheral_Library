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

#ifndef ti_devices_msp_peripherals_hw_factoryregion__include
#define ti_devices_msp_peripherals_hw_factoryregion__include

/* This preliminary header file does not have a version number */
/* MMR repo: https://bitbucket.itg.ti.com/projects/cmcu_msp65soc/repos/trim_platform_constants */
/* MMR revision: ff4b6bcad5d93ca548bdb94b818a30dc3f4acd3f */
/* Generator revision: c98c4ac511e2bd0d918c5d427bd46b7a359dacf1
   (MInT: ec7ec7482a60c6871be32db8b378ec27aa4771f6) */

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
* FACTORYREGION Registers
******************************************************************************/
#define FACTORYREGION_OPEN_OFS                   ((uint32_t)0x41C40000U)


/** @addtogroup FACTORYREGION_OPEN
  @{
*/

typedef struct {
  __I  uint32_t TRACEID;                           /* !< (@ 0x41C40000) Defined by TI, during ATE, based on wafer */
  __I  uint32_t DEVICEID;                          /* !< (@ 0x41C40004) This is the JTAGIDCODE that comes from the Ramp
                                                      system */
  __I  uint32_t USERID;                            /* !< (@ 0x41C40008) Defined by TI, depending on device spin */
  __I  uint32_t BSLPIN_UART;                       /* !< (@ 0x41C4000C) BSL UART Pin Configuration */
  __I  uint32_t BSLPIN_I2C;                        /* !< (@ 0x41C40010) BSL I2C Pin Configuration */
  __I  uint32_t BSLPIN_INVOKE;                     /* !< (@ 0x41C40014) BSL Pin Invocation Configuration */
  __I  uint32_t SRAMFLASH;                         /* !< (@ 0x41C40018) */
  __I  uint32_t PLLSTARTUP0_4_8MHZ;                /* !< (@ 0x41C4001C) */
  __I  uint32_t PLLSTARTUP1_4_8MHZ;                /* !< (@ 0x41C40020) System PLL Paramater 1 MMR --- Data from Flash
                                                      Table Lookup */
  __I  uint32_t PLLSTARTUP0_8_16MHZ;               /* !< (@ 0x41C40024) */
  __I  uint32_t PLLSTARTUP1_8_16MHZ;               /* !< (@ 0x41C40028) System PLL Paramater 1 MMR --- Data from Flash
                                                      Table Lookup */
  __I  uint32_t PLLSTARTUP0_16_32MHZ;              /* !< (@ 0x41C4002C) */
  __I  uint32_t PLLSTARTUP1_16_32MHZ;              /* !< (@ 0x41C40030) System PLL Paramater 1 MMR --- Data from Flash
                                                      Table Lookup */
  __I  uint32_t PLLSTARTUP0_32_48MHZ;              /* !< (@ 0x41C40034) */
  __I  uint32_t PLLSTARTUP1_32_48MHZ;              /* !< (@ 0x41C40038) System PLL Paramater 1 MMR --- Data from Flash
                                                      Table Lookup */
  __I  uint32_t TEMP_SENSE0;                       /* !< (@ 0x41C4003C) Temperature sensor room temperature calibration
                                                      code. This is ADC conversion results of temperature sensor output
                                                      voltage.  Included in BOOTCRC calculation. */
  __I  uint32_t RESERVED0;                         /* !< (@ 0x41C40040) */
  __I  uint32_t RESERVED1;                         /* !< (@ 0x41C40044) */
  __I  uint32_t RESERVED2;                         /* !< (@ 0x41C40048) */
  __I  uint32_t RESERVED3;                         /* !< (@ 0x41C4004C) */
  __I  uint32_t RESERVED4;                         /* !< (@ 0x41C40050) */
  __I  uint32_t RESERVED5;                         /* !< (@ 0x41C40054) */
  __I  uint32_t RESERVED6;                         /* !< (@ 0x41C40058) */
  __I  uint32_t RESERVED7;                         /* !< (@ 0x41C4005C) */
  __I  uint32_t RESERVED8;                         /* !< (@ 0x41C40060) */
  __I  uint32_t RESERVED9;                         /* !< (@ 0x41C40064) */
  __I  uint32_t RESERVED10;                        /* !< (@ 0x41C40068) */
  __I  uint32_t RESERVED11;                        /* !< (@ 0x41C4006C) */
  __I  uint32_t RESERVED12;                        /* !< (@ 0x41C40070) */
  __I  uint32_t RESERVED13;                        /* !< (@ 0x41C40074) */
  __I  uint32_t RESERVED14;                        /* !< (@ 0x41C40078) */
  __I  uint32_t BOOTCRC;                           /* !< (@ 0x41C4007C) BOOTCRC records the 32-bit CRC of all locations in
                                                      OPEN including reserved locations. */
} FACTORYREGION_OPEN_Regs;

/*@}*/ /* end of group FACTORYREGION_OPEN */

/** @addtogroup FACTORYREGION
  @{
*/

typedef struct {
       uint32_t RESERVED0[275841024];
  FACTORYREGION_OPEN_Regs  OPEN;                              /* !< (@ 0x41C40000) Customer-visible data (IDs, PLL trims,...) */
} FACTORYREGION_Regs;

/*@}*/ /* end of group FACTORYREGION */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* FACTORYREGION Register Control Bits
******************************************************************************/

/* FACTORYREGION_TRACEID Bits */
/* FACTORYREGION_TRACEID[DATA] Bits */
#define FACTORYREGION_TRACEID_DATA_OFS           (0)                             /* !< DATA Offset */
#define FACTORYREGION_TRACEID_DATA_MASK          ((uint32_t)0xFFFFFFFFU)

/* FACTORYREGION_DEVICEID Bits */
/* FACTORYREGION_DEVICEID[VERSION] Bits */
#define FACTORYREGION_DEVICEID_VERSION_OFS       (28)                            /* !< VERSION Offset */
#define FACTORYREGION_DEVICEID_VERSION_MASK      ((uint32_t)0xF0000000U)         /* !< Revision of the device. This field
                                                                                    should change each time that the
                                                                                    logic or mask set of the device is
                                                                                    revised. */
/* FACTORYREGION_DEVICEID[PARTNUM] Bits */
#define FACTORYREGION_DEVICEID_PARTNUM_OFS       (12)                            /* !< PARTNUM Offset */
#define FACTORYREGION_DEVICEID_PARTNUM_MASK      ((uint32_t)0x0FFFF000U)         /* !< Part number of the device. */
/* FACTORYREGION_DEVICEID[MANUFACTURER] Bits */
#define FACTORYREGION_DEVICEID_MANUFACTURER_OFS  (1)                             /* !< MANUFACTURER Offset */
#define FACTORYREGION_DEVICEID_MANUFACTURER_MASK ((uint32_t)0x00000FFEU)         /* !< TI's JEDEC bank and company code,
                                                                                    which is: 00000010111b */
/* FACTORYREGION_DEVICEID[ALWAYS_1] Bits */
#define FACTORYREGION_DEVICEID_ALWAYS_1_OFS      (0)                             /* !< ALWAYS_1 Offset */
#define FACTORYREGION_DEVICEID_ALWAYS_1_MASK     ((uint32_t)0x00000001U)         /* !< This is always 1 */

/* FACTORYREGION_USERID Bits */
/* FACTORYREGION_USERID[PART] Bits */
#define FACTORYREGION_USERID_PART_OFS            (0)                             /* !< PART Offset */
#define FACTORYREGION_USERID_PART_MASK           ((uint32_t)0x0000FFFFU)         /* !< Bit pattern that uniquely
                                                                                    identifying a part. This is used to
                                                                                    identify the specific part based on
                                                                                    the die identified in
                                                                                    DEVICEID.device. This number shall be
                                                                                    selected at random among the
                                                                                    remaining numbers for DEVICEID.device
                                                                                    such that the order of creation
                                                                                    cannot be inferred by the number.
                                                                                    This value does not encode the part
                                                                                    number directly. */
/* FACTORYREGION_USERID[VARIANT] Bits */
#define FACTORYREGION_USERID_VARIANT_OFS         (16)                            /* !< VARIANT Offset */
#define FACTORYREGION_USERID_VARIANT_MASK        ((uint32_t)0x00FF0000U)         /* !< Bit pattern uniquely identifying a
                                                                                    variant of a part. This is used to
                                                                                    indicate memory or package variations
                                                                                    of the same part number. This number
                                                                                    shall be selected at random among the
                                                                                    remaining numbers for the relevant
                                                                                    combination of IDCODE.device and
                                                                                    USERCODE.part such that the order of
                                                                                    creation cannot be inferred by the
                                                                                    number. The variant number does not
                                                                                    encode specifics of the variant
                                                                                    directly. */
/* FACTORYREGION_USERID[MINORREV] Bits */
#define FACTORYREGION_USERID_MINORREV_OFS        (24)                            /* !< MINORREV Offset */
#define FACTORYREGION_USERID_MINORREV_MASK       ((uint32_t)0x0F000000U)         /* !< Monotonic increasing value
                                                                                    indicating a new revision of the SKU
                                                                                    that preserves compatibility with
                                                                                    lesser minorrev values. New
                                                                                    capability may be introduced such
                                                                                    that lesser minorrev numbers may not
                                                                                    be compatible with greater if the new
                                                                                    capability is used. */
/* FACTORYREGION_USERID[MAJORREV] Bits */
#define FACTORYREGION_USERID_MAJORREV_OFS        (28)                            /* !< MAJORREV Offset */
#define FACTORYREGION_USERID_MAJORREV_MASK       ((uint32_t)0x70000000U)         /* !< Monotonic increasing value
                                                                                    indicating a new revision of the SKU
                                                                                    significant enough that users of the
                                                                                    device may have to revise PCB or or
                                                                                    software design */
/* FACTORYREGION_USERID[START] Bits */
#define FACTORYREGION_USERID_START_OFS           (31)                            /* !< START Offset */
#define FACTORYREGION_USERID_START_MASK          ((uint32_t)0x80000000U)

/* FACTORYREGION_BSLPIN_UART Bits */
/* FACTORYREGION_BSLPIN_UART[UART_RXD_PAD] Bits */
#define FACTORYREGION_BSLPIN_UART_UART_RXD_PAD_OFS (0)                             /* !< UART_RXD_PAD Offset */
#define FACTORYREGION_BSLPIN_UART_UART_RXD_PAD_MASK ((uint32_t)0x000000FFU)         /* !< UART RXD Pad used by BSL */
/* FACTORYREGION_BSLPIN_UART[UART_RXD_PF] Bits */
#define FACTORYREGION_BSLPIN_UART_UART_RXD_PF_OFS (8)                             /* !< UART_RXD_PF Offset */
#define FACTORYREGION_BSLPIN_UART_UART_RXD_PF_MASK ((uint32_t)0x0000FF00U)         /* !< UART RXD Pin Function Selection
                                                                                    Value */
/* FACTORYREGION_BSLPIN_UART[UART_TXD_PAD] Bits */
#define FACTORYREGION_BSLPIN_UART_UART_TXD_PAD_OFS (16)                            /* !< UART_TXD_PAD Offset */
#define FACTORYREGION_BSLPIN_UART_UART_TXD_PAD_MASK ((uint32_t)0x00FF0000U)         /* !< UART TXD Pin used by BSL */
/* FACTORYREGION_BSLPIN_UART[UART_TXD_PF] Bits */
#define FACTORYREGION_BSLPIN_UART_UART_TXD_PF_OFS (24)                            /* !< UART_TXD_PF Offset */
#define FACTORYREGION_BSLPIN_UART_UART_TXD_PF_MASK ((uint32_t)0xFF000000U)         /* !< UART TXD Pin Function Selection
                                                                                    Value */

/* FACTORYREGION_BSLPIN_I2C Bits */
/* FACTORYREGION_BSLPIN_I2C[I2C_SDA_PAD] Bits */
#define FACTORYREGION_BSLPIN_I2C_I2C_SDA_PAD_OFS (0)                             /* !< I2C_SDA_PAD Offset */
#define FACTORYREGION_BSLPIN_I2C_I2C_SDA_PAD_MASK ((uint32_t)0x000000FFU)         /* !< I2C SDA Pin used by BSL */
/* FACTORYREGION_BSLPIN_I2C[I2C_SDA_PF] Bits */
#define FACTORYREGION_BSLPIN_I2C_I2C_SDA_PF_OFS  (8)                             /* !< I2C_SDA_PF Offset */
#define FACTORYREGION_BSLPIN_I2C_I2C_SDA_PF_MASK ((uint32_t)0x0000FF00U)         /* !< I2C SDA Pin Function Selection
                                                                                    Value */
/* FACTORYREGION_BSLPIN_I2C[I2C_SCL_PAD] Bits */
#define FACTORYREGION_BSLPIN_I2C_I2C_SCL_PAD_OFS (16)                            /* !< I2C_SCL_PAD Offset */
#define FACTORYREGION_BSLPIN_I2C_I2C_SCL_PAD_MASK ((uint32_t)0x00FF0000U)         /* !< I2C SCL Pin used by BSL */
/* FACTORYREGION_BSLPIN_I2C[I2C_SCL_PF] Bits */
#define FACTORYREGION_BSLPIN_I2C_I2C_SCL_PF_OFS  (24)                            /* !< I2C_SCL_PF Offset */
#define FACTORYREGION_BSLPIN_I2C_I2C_SCL_PF_MASK ((uint32_t)0xFF000000U)         /* !< I2C SCL Pin Function Selection
                                                                                    Value */

/* FACTORYREGION_BSLPIN_INVOKE Bits */
/* FACTORYREGION_BSLPIN_INVOKE[BSL_PAD] Bits */
#define FACTORYREGION_BSLPIN_INVOKE_BSL_PAD_OFS  (0)                             /* !< BSL_PAD Offset */
#define FACTORYREGION_BSLPIN_INVOKE_BSL_PAD_MASK ((uint32_t)0x0000007FU)         /* !< BSL Invocation Pin Number */
/* FACTORYREGION_BSLPIN_INVOKE[GPIO_LEVEL] Bits */
#define FACTORYREGION_BSLPIN_INVOKE_GPIO_LEVEL_OFS (7)                             /* !< GPIO_LEVEL Offset */
#define FACTORYREGION_BSLPIN_INVOKE_GPIO_LEVEL_MASK ((uint32_t)0x00000080U)         /* !< GPIO Level Configuration for BSL
                                                                                    Invocation */
/* FACTORYREGION_BSLPIN_INVOKE[GPIO_PIN_SEL] Bits */
#define FACTORYREGION_BSLPIN_INVOKE_GPIO_PIN_SEL_OFS (8)                             /* !< GPIO_PIN_SEL Offset */
#define FACTORYREGION_BSLPIN_INVOKE_GPIO_PIN_SEL_MASK ((uint32_t)0x00001F00U)         /* !< GPIO Pin Number in GPIO Module */
/* FACTORYREGION_BSLPIN_INVOKE[GPIO_REG_SEL] Bits */
#define FACTORYREGION_BSLPIN_INVOKE_GPIO_REG_SEL_OFS (13)                            /* !< GPIO_REG_SEL Offset */
#define FACTORYREGION_BSLPIN_INVOKE_GPIO_REG_SEL_MASK ((uint32_t)0x00006000U)         /* !< GPIO Module Selection */

/* FACTORYREGION_SRAMFLASH Bits */
/* FACTORYREGION_SRAMFLASH[MAINFLASH_SZ] Bits */
#define FACTORYREGION_SRAMFLASH_MAINFLASH_SZ_OFS (0)                             /* !< MAINFLASH_SZ Offset */
#define FACTORYREGION_SRAMFLASH_MAINFLASH_SZ_MASK ((uint32_t)0x00000FFFU)         /* !< The encoding of the field is that
                                                                                    the value of the field is an integer
                                                                                    to be interpreted as number of KBs.
                                                                                    For eg: if the value of the field id
                                                                                    4, then it is 4KB, if the value is
                                                                                    32, then 32KB, and so on. */
/* FACTORYREGION_SRAMFLASH[SRAM_SZ] Bits */
#define FACTORYREGION_SRAMFLASH_SRAM_SZ_OFS      (16)                            /* !< SRAM_SZ Offset */
#define FACTORYREGION_SRAMFLASH_SRAM_SZ_MASK     ((uint32_t)0x03FF0000U)         /* !< The encoding of the field is that
                                                                                    the value of the field is an integer
                                                                                    to be interpreted as number of KBs.
                                                                                    For eg: if the value of the field id
                                                                                    4, then it is 4KB, if the value is
                                                                                    32, then 32KB, and so on. */
/* FACTORYREGION_SRAMFLASH[DATAFLASH_SZ] Bits */
#define FACTORYREGION_SRAMFLASH_DATAFLASH_SZ_OFS (26)                            /* !< DATAFLASH_SZ Offset */
#define FACTORYREGION_SRAMFLASH_DATAFLASH_SZ_MASK ((uint32_t)0xFC000000U)         /* !< The encoding of the field is that
                                                                                    the value of the field is an integer
                                                                                    to be interpreted as number of KBs.
                                                                                    For eg: if the value of the field id
                                                                                    4, then it is 4KB, if the value is
                                                                                    32, then 32KB, and so on. */
/* FACTORYREGION_SRAMFLASH[MAINNUMBANKS] Bits */
#define FACTORYREGION_SRAMFLASH_MAINNUMBANKS_OFS (12)                            /* !< MAINNUMBANKS Offset */
#define FACTORYREGION_SRAMFLASH_MAINNUMBANKS_MASK ((uint32_t)0x00003000U)
#define FACTORYREGION_SRAMFLASH_MAINNUMBANKS_ONEBANK ((uint32_t)0x00000000U)
#define FACTORYREGION_SRAMFLASH_MAINNUMBANKS_TWOBANKS ((uint32_t)0x00001000U)
#define FACTORYREGION_SRAMFLASH_MAINNUMBANKS_THREEBANKS ((uint32_t)0x00002000U)
#define FACTORYREGION_SRAMFLASH_MAINNUMBANKS_FOURBANKS ((uint32_t)0x00003000U)

/* FACTORYREGION_PLLSTARTUP0_4_8MHZ Bits */
/* FACTORYREGION_PLLSTARTUP0_4_8MHZ[STARTTIME] Bits */
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_STARTTIME_OFS (0)                             /* !< STARTTIME Offset */
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_STARTTIME_MASK ((uint32_t)0x0000003FU)         /* !< Startup time from Enable to Locked
                                                                                    Clock in resolution of 1usec */
/* FACTORYREGION_PLLSTARTUP0_4_8MHZ[STARTTIMELP] Bits */
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_STARTTIMELP_OFS (8)                             /* !< STARTTIMELP Offset */
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_STARTTIMELP_MASK ((uint32_t)0x00003F00U)         /* !< Startup time from Low Power Exit to
                                                                                    Locked Clock in resolution of 1usec */
/* FACTORYREGION_PLLSTARTUP0_4_8MHZ[CPCURRENT] Bits */
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_CPCURRENT_OFS (16)                            /* !< CPCURRENT Offset */
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_CPCURRENT_MASK ((uint32_t)0x003F0000U)         /* !< Charge Pump Current */
/* FACTORYREGION_PLLSTARTUP0_4_8MHZ[CAPBVAL] Bits */
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_CAPBVAL_OFS (24)                            /* !< CAPBVAL Offset */
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_CAPBVAL_MASK ((uint32_t)0x1F000000U)         /* !< Override Value for Cap B */
/* FACTORYREGION_PLLSTARTUP0_4_8MHZ[CAPBOVERRIDE] Bits */
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_CAPBOVERRIDE_OFS (31)                            /* !< CAPBOVERRIDE Offset */
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_CAPBOVERRIDE_MASK ((uint32_t)0x80000000U)         /* !< Override Enable For Cap B */
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_CAPBOVERRIDE_DISABLE ((uint32_t)0x00000000U)
#define FACTORYREGION_PLLSTARTUP0_4_8MHZ_CAPBOVERRIDE_ENABLE ((uint32_t)0x80000000U)

/* FACTORYREGION_PLLSTARTUP1_4_8MHZ Bits */
/* FACTORYREGION_PLLSTARTUP1_4_8MHZ[LPFCAPA] Bits */
#define FACTORYREGION_PLLSTARTUP1_4_8MHZ_LPFCAPA_OFS (0)                             /* !< LPFCAPA Offset */
#define FACTORYREGION_PLLSTARTUP1_4_8MHZ_LPFCAPA_MASK ((uint32_t)0x0000001FU)         /* !< Loop Filter Cap A */
/* FACTORYREGION_PLLSTARTUP1_4_8MHZ[LPFRESA] Bits */
#define FACTORYREGION_PLLSTARTUP1_4_8MHZ_LPFRESA_OFS (8)                             /* !< LPFRESA Offset */
#define FACTORYREGION_PLLSTARTUP1_4_8MHZ_LPFRESA_MASK ((uint32_t)0x0003FF00U)         /* !< Loop Filter Res A */
/* FACTORYREGION_PLLSTARTUP1_4_8MHZ[LPFRESC] Bits */
#define FACTORYREGION_PLLSTARTUP1_4_8MHZ_LPFRESC_OFS (24)                            /* !< LPFRESC Offset */
#define FACTORYREGION_PLLSTARTUP1_4_8MHZ_LPFRESC_MASK ((uint32_t)0xFF000000U)         /* !< Loop Filter Res C */

/* FACTORYREGION_PLLSTARTUP0_8_16MHZ Bits */
/* FACTORYREGION_PLLSTARTUP0_8_16MHZ[STARTTIME] Bits */
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_STARTTIME_OFS (0)                             /* !< STARTTIME Offset */
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_STARTTIME_MASK ((uint32_t)0x0000003FU)         /* !< Startup time from Enable to Locked
                                                                                    Clock in resolution of 1usec */
/* FACTORYREGION_PLLSTARTUP0_8_16MHZ[STARTTIMELP] Bits */
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_STARTTIMELP_OFS (8)                             /* !< STARTTIMELP Offset */
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_STARTTIMELP_MASK ((uint32_t)0x00003F00U)         /* !< Startup time from Low Power Exit to
                                                                                    Locked Clock in resolution of 1usec */
/* FACTORYREGION_PLLSTARTUP0_8_16MHZ[CPCURRENT] Bits */
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_CPCURRENT_OFS (16)                            /* !< CPCURRENT Offset */
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_CPCURRENT_MASK ((uint32_t)0x003F0000U)         /* !< Charge Pump Current */
/* FACTORYREGION_PLLSTARTUP0_8_16MHZ[CAPBVAL] Bits */
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_CAPBVAL_OFS (24)                            /* !< CAPBVAL Offset */
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_CAPBVAL_MASK ((uint32_t)0x1F000000U)         /* !< Override Value for Cap B */
/* FACTORYREGION_PLLSTARTUP0_8_16MHZ[CAPBOVERRIDE] Bits */
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_CAPBOVERRIDE_OFS (31)                            /* !< CAPBOVERRIDE Offset */
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_CAPBOVERRIDE_MASK ((uint32_t)0x80000000U)         /* !< Override Enable For Cap B */
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_CAPBOVERRIDE_DISABLE ((uint32_t)0x00000000U)
#define FACTORYREGION_PLLSTARTUP0_8_16MHZ_CAPBOVERRIDE_ENABLE ((uint32_t)0x80000000U)

/* FACTORYREGION_PLLSTARTUP1_8_16MHZ Bits */
/* FACTORYREGION_PLLSTARTUP1_8_16MHZ[LPFCAPA] Bits */
#define FACTORYREGION_PLLSTARTUP1_8_16MHZ_LPFCAPA_OFS (0)                             /* !< LPFCAPA Offset */
#define FACTORYREGION_PLLSTARTUP1_8_16MHZ_LPFCAPA_MASK ((uint32_t)0x0000001FU)         /* !< Loop Filter Cap A */
/* FACTORYREGION_PLLSTARTUP1_8_16MHZ[LPFRESA] Bits */
#define FACTORYREGION_PLLSTARTUP1_8_16MHZ_LPFRESA_OFS (8)                             /* !< LPFRESA Offset */
#define FACTORYREGION_PLLSTARTUP1_8_16MHZ_LPFRESA_MASK ((uint32_t)0x0003FF00U)         /* !< Loop Filter Res A */
/* FACTORYREGION_PLLSTARTUP1_8_16MHZ[LPFRESC] Bits */
#define FACTORYREGION_PLLSTARTUP1_8_16MHZ_LPFRESC_OFS (24)                            /* !< LPFRESC Offset */
#define FACTORYREGION_PLLSTARTUP1_8_16MHZ_LPFRESC_MASK ((uint32_t)0xFF000000U)         /* !< Loop Filter Res C */

/* FACTORYREGION_PLLSTARTUP0_16_32MHZ Bits */
/* FACTORYREGION_PLLSTARTUP0_16_32MHZ[STARTTIME] Bits */
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_STARTTIME_OFS (0)                             /* !< STARTTIME Offset */
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_STARTTIME_MASK ((uint32_t)0x0000003FU)         /* !< Startup time from Enable to Locked
                                                                                    Clock in resolution of 1usec */
/* FACTORYREGION_PLLSTARTUP0_16_32MHZ[STARTTIMELP] Bits */
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_STARTTIMELP_OFS (8)                             /* !< STARTTIMELP Offset */
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_STARTTIMELP_MASK ((uint32_t)0x00003F00U)         /* !< Startup time from Low Power Exit to
                                                                                    Locked Clock in resolution of 1usec */
/* FACTORYREGION_PLLSTARTUP0_16_32MHZ[CPCURRENT] Bits */
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_CPCURRENT_OFS (16)                            /* !< CPCURRENT Offset */
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_CPCURRENT_MASK ((uint32_t)0x003F0000U)         /* !< Charge Pump Current */
/* FACTORYREGION_PLLSTARTUP0_16_32MHZ[CAPBVAL] Bits */
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_CAPBVAL_OFS (24)                            /* !< CAPBVAL Offset */
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_CAPBVAL_MASK ((uint32_t)0x1F000000U)         /* !< Override Value for Cap B */
/* FACTORYREGION_PLLSTARTUP0_16_32MHZ[CAPBOVERRIDE] Bits */
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_CAPBOVERRIDE_OFS (31)                            /* !< CAPBOVERRIDE Offset */
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_CAPBOVERRIDE_MASK ((uint32_t)0x80000000U)         /* !< Override Enable For Cap B */
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_CAPBOVERRIDE_DISABLE ((uint32_t)0x00000000U)
#define FACTORYREGION_PLLSTARTUP0_16_32MHZ_CAPBOVERRIDE_ENABLE ((uint32_t)0x80000000U)

/* FACTORYREGION_PLLSTARTUP1_16_32MHZ Bits */
/* FACTORYREGION_PLLSTARTUP1_16_32MHZ[LPFCAPA] Bits */
#define FACTORYREGION_PLLSTARTUP1_16_32MHZ_LPFCAPA_OFS (0)                             /* !< LPFCAPA Offset */
#define FACTORYREGION_PLLSTARTUP1_16_32MHZ_LPFCAPA_MASK ((uint32_t)0x0000001FU)         /* !< Loop Filter Cap A */
/* FACTORYREGION_PLLSTARTUP1_16_32MHZ[LPFRESA] Bits */
#define FACTORYREGION_PLLSTARTUP1_16_32MHZ_LPFRESA_OFS (8)                             /* !< LPFRESA Offset */
#define FACTORYREGION_PLLSTARTUP1_16_32MHZ_LPFRESA_MASK ((uint32_t)0x0003FF00U)         /* !< Loop Filter Res A */
/* FACTORYREGION_PLLSTARTUP1_16_32MHZ[LPFRESC] Bits */
#define FACTORYREGION_PLLSTARTUP1_16_32MHZ_LPFRESC_OFS (24)                            /* !< LPFRESC Offset */
#define FACTORYREGION_PLLSTARTUP1_16_32MHZ_LPFRESC_MASK ((uint32_t)0xFF000000U)         /* !< Loop Filter Res C */

/* FACTORYREGION_PLLSTARTUP0_32_48MHZ Bits */
/* FACTORYREGION_PLLSTARTUP0_32_48MHZ[STARTTIME] Bits */
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_STARTTIME_OFS (0)                             /* !< STARTTIME Offset */
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_STARTTIME_MASK ((uint32_t)0x0000003FU)         /* !< Startup time from Enable to Locked
                                                                                    Clock in resolution of 1usec */
/* FACTORYREGION_PLLSTARTUP0_32_48MHZ[STARTTIMELP] Bits */
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_STARTTIMELP_OFS (8)                             /* !< STARTTIMELP Offset */
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_STARTTIMELP_MASK ((uint32_t)0x00003F00U)         /* !< Startup time from Low Power Exit to
                                                                                    Locked Clock in resolution of 1usec */
/* FACTORYREGION_PLLSTARTUP0_32_48MHZ[CPCURRENT] Bits */
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_CPCURRENT_OFS (16)                            /* !< CPCURRENT Offset */
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_CPCURRENT_MASK ((uint32_t)0x003F0000U)         /* !< Charge Pump Current */
/* FACTORYREGION_PLLSTARTUP0_32_48MHZ[CAPBVAL] Bits */
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_CAPBVAL_OFS (24)                            /* !< CAPBVAL Offset */
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_CAPBVAL_MASK ((uint32_t)0x1F000000U)         /* !< Override Value for Cap B */
/* FACTORYREGION_PLLSTARTUP0_32_48MHZ[CAPBOVERRIDE] Bits */
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_CAPBOVERRIDE_OFS (31)                            /* !< CAPBOVERRIDE Offset */
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_CAPBOVERRIDE_MASK ((uint32_t)0x80000000U)         /* !< Override Enable For Cap B */
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_CAPBOVERRIDE_DISABLE ((uint32_t)0x00000000U)
#define FACTORYREGION_PLLSTARTUP0_32_48MHZ_CAPBOVERRIDE_ENABLE ((uint32_t)0x80000000U)

/* FACTORYREGION_PLLSTARTUP1_32_48MHZ Bits */
/* FACTORYREGION_PLLSTARTUP1_32_48MHZ[LPFCAPA] Bits */
#define FACTORYREGION_PLLSTARTUP1_32_48MHZ_LPFCAPA_OFS (0)                             /* !< LPFCAPA Offset */
#define FACTORYREGION_PLLSTARTUP1_32_48MHZ_LPFCAPA_MASK ((uint32_t)0x0000001FU)         /* !< Loop Filter Cap A */
/* FACTORYREGION_PLLSTARTUP1_32_48MHZ[LPFRESA] Bits */
#define FACTORYREGION_PLLSTARTUP1_32_48MHZ_LPFRESA_OFS (8)                             /* !< LPFRESA Offset */
#define FACTORYREGION_PLLSTARTUP1_32_48MHZ_LPFRESA_MASK ((uint32_t)0x0003FF00U)         /* !< Loop Filter Res A */
/* FACTORYREGION_PLLSTARTUP1_32_48MHZ[LPFRESC] Bits */
#define FACTORYREGION_PLLSTARTUP1_32_48MHZ_LPFRESC_OFS (24)                            /* !< LPFRESC Offset */
#define FACTORYREGION_PLLSTARTUP1_32_48MHZ_LPFRESC_MASK ((uint32_t)0xFF000000U)         /* !< Loop Filter Res C */

/* FACTORYREGION_TEMP_SENSE0 Bits */
/* FACTORYREGION_TEMP_SENSE0[DATA] Bits */
#define FACTORYREGION_TEMP_SENSE0_DATA_OFS       (0)                             /* !< DATA Offset */
#define FACTORYREGION_TEMP_SENSE0_DATA_MASK      ((uint32_t)0xFFFFFFFFU)

/* FACTORYREGION_BOOTCRC Bits */
/* FACTORYREGION_BOOTCRC[DATA] Bits */
#define FACTORYREGION_BOOTCRC_DATA_OFS           (0)                             /* !< DATA Offset */
#define FACTORYREGION_BOOTCRC_DATA_MASK          ((uint32_t)0xFFFFFFFFU)


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_factoryregion__include */
