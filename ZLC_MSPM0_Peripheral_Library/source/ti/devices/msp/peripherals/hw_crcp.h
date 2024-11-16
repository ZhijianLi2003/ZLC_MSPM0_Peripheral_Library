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

#ifndef ti_devices_msp_peripherals_hw_crcp__include
#define ti_devices_msp_peripherals_hw_crcp__include

/* This preliminary header file does not have a version number */
/* MMR repo: https://bitbucket.itg.ti.com/projects/cmcu_msp65ip/repos/f65mspcrcp */
/* MMR revision: c7a923985b92a7b6b96f570800afdbf6fa370b4e */
/* Generator revision: 0afd252131372f6ff2599f3ff4321e731df2364d
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
* CRCP Registers
******************************************************************************/
#define CRCP_GPRCM_OFS                           ((uint32_t)0x00000800U)


/** @addtogroup CRCP_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} CRCP_GPRCM_Regs;

/*@}*/ /* end of group CRCP_GPRCM */

/** @addtogroup CRCP
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  CRCP_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED1[507];
  __I  uint32_t CLKSEL;                            /* !< (@ 0x00001004) Clock Select */
       uint32_t RESERVED2[61];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
  __IO uint32_t CRCCTRL;                           /* !< (@ 0x00001100) CRC Control Register */
  __O  uint32_t CRCSEED;                           /* !< (@ 0x00001104) CRC Seed Register */
  __O  uint32_t CRCIN;                             /* !< (@ 0x00001108) CRC Input Data Register */
  __I  uint32_t CRCOUT;                            /* !< (@ 0x0000110C) CRC Output Result Register */
  __IO uint32_t CRCPOLY;                           /* !< (@ 0x00001110) CRC Polynomial configuration register */
       uint32_t RESERVED3[443];
  __O  uint32_t CRCIN_IDX[512];                    /* !< (@ 0x00001800) CRC Input Data Array Register */
} CRCP_Regs;

/*@}*/ /* end of group CRCP */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* CRCP Register Control Bits
******************************************************************************/

/* CRCP_PWREN Bits */
/* CRCP_PWREN[ENABLE] Bits */
#define CRCP_PWREN_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define CRCP_PWREN_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< Enable the power */
#define CRCP_PWREN_ENABLE_DISABLE                ((uint32_t)0x00000000U)         /* !< Disable Power */
#define CRCP_PWREN_ENABLE_ENABLE                 ((uint32_t)0x00000001U)         /* !< Enable Power */
/* CRCP_PWREN[KEY] Bits */
#define CRCP_PWREN_KEY_OFS                       (24)                            /* !< KEY Offset */
#define CRCP_PWREN_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define CRCP_PWREN_KEY_UNLOCK_W                  ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* CRCP_RSTCTL Bits */
/* CRCP_RSTCTL[RESETSTKYCLR] Bits */
#define CRCP_RSTCTL_RESETSTKYCLR_OFS             (1)                             /* !< RESETSTKYCLR Offset */
#define CRCP_RSTCTL_RESETSTKYCLR_MASK            ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define CRCP_RSTCTL_RESETSTKYCLR_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define CRCP_RSTCTL_RESETSTKYCLR_CLR             ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* CRCP_RSTCTL[RESETASSERT] Bits */
#define CRCP_RSTCTL_RESETASSERT_OFS              (0)                             /* !< RESETASSERT Offset */
#define CRCP_RSTCTL_RESETASSERT_MASK             ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define CRCP_RSTCTL_RESETASSERT_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define CRCP_RSTCTL_RESETASSERT_ASSERT           ((uint32_t)0x00000001U)         /* !< Assert reset */
/* CRCP_RSTCTL[KEY] Bits */
#define CRCP_RSTCTL_KEY_OFS                      (24)                            /* !< KEY Offset */
#define CRCP_RSTCTL_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define CRCP_RSTCTL_KEY_UNLOCK_W                 ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* CRCP_STAT Bits */
/* CRCP_STAT[RESETSTKY] Bits */
#define CRCP_STAT_RESETSTKY_OFS                  (16)                            /* !< RESETSTKY Offset */
#define CRCP_STAT_RESETSTKY_MASK                 ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define CRCP_STAT_RESETSTKY_NORES                ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define CRCP_STAT_RESETSTKY_RESET                ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* CRCP_CLKSEL Bits */
/* CRCP_CLKSEL[MCLK_SEL] Bits */
#define CRCP_CLKSEL_MCLK_SEL_OFS                 (0)                             /* !< MCLK_SEL Offset */
#define CRCP_CLKSEL_MCLK_SEL_MASK                ((uint32_t)0x00000001U)         /* !< Selects main clock (MCLK) if
                                                                                    enabled */
#define CRCP_CLKSEL_MCLK_SEL_DISABLE             ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define CRCP_CLKSEL_MCLK_SEL_ENABLE              ((uint32_t)0x00000001U)         /* !< Select this clock as a source */

/* CRCP_DESC Bits */
/* CRCP_DESC[MINREV] Bits */
#define CRCP_DESC_MINREV_OFS                     (0)                             /* !< MINREV Offset */
#define CRCP_DESC_MINREV_MASK                    ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
#define CRCP_DESC_MINREV_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define CRCP_DESC_MINREV_MAXIMUM                 ((uint32_t)0x0000000FU)         /* !< Highest possible value */
/* CRCP_DESC[MAJREV] Bits */
#define CRCP_DESC_MAJREV_OFS                     (4)                             /* !< MAJREV Offset */
#define CRCP_DESC_MAJREV_MASK                    ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
#define CRCP_DESC_MAJREV_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define CRCP_DESC_MAJREV_MAXIMUM                 ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* CRCP_DESC[INSTNUM] Bits */
#define CRCP_DESC_INSTNUM_OFS                    (8)                             /* !< INSTNUM Offset */
#define CRCP_DESC_INSTNUM_MASK                   ((uint32_t)0x00000F00U)         /* !< Instance Number within the device.
                                                                                    This will be a parameter to the RTL
                                                                                    for modules that can have multiple
                                                                                    instances */
#define CRCP_DESC_INSTNUM_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define CRCP_DESC_INSTNUM_MAXIMUM                ((uint32_t)0x00000F00U)         /* !< Highest possible value */
/* CRCP_DESC[FEATUREVER] Bits */
#define CRCP_DESC_FEATUREVER_OFS                 (12)                            /* !< FEATUREVER Offset */
#define CRCP_DESC_FEATUREVER_MASK                ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
#define CRCP_DESC_FEATUREVER_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define CRCP_DESC_FEATUREVER_MAXIMUM             ((uint32_t)0x0000F000U)         /* !< Highest possible value */
/* CRCP_DESC[MODULEID] Bits */
#define CRCP_DESC_MODULEID_OFS                   (16)                            /* !< MODULEID Offset */
#define CRCP_DESC_MODULEID_MASK                  ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */
#define CRCP_DESC_MODULEID_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define CRCP_DESC_MODULEID_MAXIMUM               ((uint32_t)0xFFFF0000U)         /* !< Highest possible value */

/* CRCP_CRCCTRL Bits */
/* CRCP_CRCCTRL[POLYSIZE] Bits */
#define CRCP_CRCCTRL_POLYSIZE_OFS                (0)                             /* !< POLYSIZE Offset */
#define CRCP_CRCCTRL_POLYSIZE_MASK               ((uint32_t)0x00000001U)         /* !< This bit indicates which CRC
                                                                                    calculation is performed by the
                                                                                    generator. */
#define CRCP_CRCCTRL_POLYSIZE_CRC32              ((uint32_t)0x00000000U)         /* !< CRC-32 ISO-3309 calulation is
                                                                                    performed */
#define CRCP_CRCCTRL_POLYSIZE_CRC16              ((uint32_t)0x00000001U)         /* !< CRC-16 CCITT is performed */
/* CRCP_CRCCTRL[BITREVERSE] Bits */
#define CRCP_CRCCTRL_BITREVERSE_OFS              (1)                             /* !< BITREVERSE Offset */
#define CRCP_CRCCTRL_BITREVERSE_MASK             ((uint32_t)0x00000002U)         /* !< CRC Bit Input and output Reverse.
                                                                                    This bit indictes that the bit order
                                                                                    of each input byte used for the CRC
                                                                                    calculation is reversed before it is
                                                                                    passed to the generator, and that the
                                                                                    bit order of the calculated CRC is be
                                                                                    reversed when read from CRC_RESULT. */
#define CRCP_CRCCTRL_BITREVERSE_NOT_REVERSED     ((uint32_t)0x00000000U)         /* !< Bit order is not reversed. */
#define CRCP_CRCCTRL_BITREVERSE_REVERSED         ((uint32_t)0x00000002U)         /* !< Bit order is reversed. */
/* CRCP_CRCCTRL[INPUT_ENDIANNESS] Bits */
#define CRCP_CRCCTRL_INPUT_ENDIANNESS_OFS        (2)                             /* !< INPUT_ENDIANNESS Offset */
#define CRCP_CRCCTRL_INPUT_ENDIANNESS_MASK       ((uint32_t)0x00000004U)         /* !< CRC Endian. This bit indicates the
                                                                                    byte order within a word or half word
                                                                                    of input data. */
#define CRCP_CRCCTRL_INPUT_ENDIANNESS_LITTLE_ENDIAN ((uint32_t)0x00000000U)         /* !< LSB is lowest memory address and
                                                                                    first to be processed. */
#define CRCP_CRCCTRL_INPUT_ENDIANNESS_BIG_ENDIAN ((uint32_t)0x00000004U)         /* !< LSB is highest memory address and
                                                                                    last to be processed. */
/* CRCP_CRCCTRL[OUTPUT_BYTESWAP] Bits */
#define CRCP_CRCCTRL_OUTPUT_BYTESWAP_OFS         (4)                             /* !< OUTPUT_BYTESWAP Offset */
#define CRCP_CRCCTRL_OUTPUT_BYTESWAP_MASK        ((uint32_t)0x00000010U)         /* !< CRC Output Byteswap Enable. This
                                                                                    bit controls whether the output is
                                                                                    byte-swapped upon a read of the
                                                                                    CRCOUT register. If CRCOUT is
                                                                                    accessed as a half-word, and the
                                                                                    OUTPUT_BYTESWAP is set to to 1, then
                                                                                    the two bytes in the 16-bit access
                                                                                    are swapped and returned. B1 is
                                                                                    returned as B0 B0 is returned as B1
                                                                                    If CRCOUT is accessed as a word, and
                                                                                    the OUTPUT_BYTESWAP is set to 1, then
                                                                                    the four bytes in the 32-bit read are
                                                                                    swapped. B3 is returned as B0 B2 is
                                                                                    returned as B1 B1 is returned as B2
                                                                                    B0 is returned as B3  Note that if
                                                                                    the CRC POLYSIZE is 16-bit and a
                                                                                    32-bit read of CRCOUT is performed
                                                                                    with OUTPUT_BYTESWAP enabled,  then
                                                                                    the output is: MSB                LSB
                                                                                    0x0   0x0   B0   B1  If the CRC
                                                                                    POLYSIZE is 16-bit and a 32-bit read
                                                                                    of CRCOUT is performed with
                                                                                    OUTPUT_BYTESWAP disabled,  then the
                                                                                    output is: MSB                LSB 0x0
                                                                                    0x0   B1   B0 */
#define CRCP_CRCCTRL_OUTPUT_BYTESWAP_DISABLE     ((uint32_t)0x00000000U)         /* !< Output byteswapping is disabled */
#define CRCP_CRCCTRL_OUTPUT_BYTESWAP_ENABLE      ((uint32_t)0x00000010U)         /* !< Output byteswapping is enabled. */

/* CRCP_CRCSEED Bits */
/* CRCP_CRCSEED[SEED] Bits */
#define CRCP_CRCSEED_SEED_OFS                    (0)                             /* !< SEED Offset */
#define CRCP_CRCSEED_SEED_MASK                   ((uint32_t)0xFFFFFFFFU)         /* !< Seed Data */
#define CRCP_CRCSEED_SEED_MINIMUM                ((uint32_t)0x00000000U)         /* !< Mnimum value */
#define CRCP_CRCSEED_SEED_MAXIMUM                ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value */

/* CRCP_CRCIN Bits */
/* CRCP_CRCIN[DATA] Bits */
#define CRCP_CRCIN_DATA_OFS                      (0)                             /* !< DATA Offset */
#define CRCP_CRCIN_DATA_MASK                     ((uint32_t)0xFFFFFFFFU)         /* !< Input Data */
#define CRCP_CRCIN_DATA_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Mnimum value */
#define CRCP_CRCIN_DATA_MAXIMUM                  ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value */

/* CRCP_CRCOUT Bits */
/* CRCP_CRCOUT[RESULT] Bits */
#define CRCP_CRCOUT_RESULT_OFS                   (0)                             /* !< RESULT Offset */
#define CRCP_CRCOUT_RESULT_MASK                  ((uint32_t)0xFFFFFFFFU)         /* !< Result */
#define CRCP_CRCOUT_RESULT_MINIMUM               ((uint32_t)0x00000000U)         /* !< Mnimum value */
#define CRCP_CRCOUT_RESULT_MAXIMUM               ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value */

/* CRCP_CRCPOLY Bits */
/* CRCP_CRCPOLY[DATA] Bits */
#define CRCP_CRCPOLY_DATA_OFS                    (0)                             /* !< DATA Offset */
#define CRCP_CRCPOLY_DATA_MASK                   ((uint32_t)0xFFFFFFFFU)         /* !< Polynomial definition */

/* CRCP_CRCIN_IDX Bits */
/* CRCP_CRCIN_IDX[DATA] Bits */
#define CRCP_CRCIN_IDX_DATA_OFS                  (0)                             /* !< DATA Offset */
#define CRCP_CRCIN_IDX_DATA_MASK                 ((uint32_t)0xFFFFFFFFU)         /* !< Input Data */
#define CRCP_CRCIN_IDX_DATA_MINIMUM              ((uint32_t)0x00000000U)         /* !< Minimum value */
#define CRCP_CRCIN_IDX_DATA_MAXIMUM              ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_crcp__include */
