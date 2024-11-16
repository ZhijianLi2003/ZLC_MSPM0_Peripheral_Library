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

#ifndef ti_devices_msp_peripherals_hw_keystorectl__include
#define ti_devices_msp_peripherals_hw_keystorectl__include

/* This preliminary header file does not have a version number */
/* MMR repo: https://bitbucket.itg.ti.com/projects/cmcu_msp65ip/repos/f65mspkeystorectl */
/* MMR revision: da65027d31f78c7139cd945e99c27064d5e09c65 */
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
* KEYSTORECTL Registers
******************************************************************************/


/** @addtogroup KEYSTORECTL
  @{
*/

typedef struct {
       uint32_t RESERVED0[1088];
  __IO uint32_t CFG;                               /* !< (@ 0x00001100) Keystore configuration */
  __IO uint32_t KEYWR;                             /* !< (@ 0x00001104) Key write configuration */
  __IO uint32_t KEYRD;                             /* !< (@ 0x00001108) Key read configuration */
  __I  uint32_t STATUS;                            /* !< (@ 0x0000110C) Status */
  __O  uint32_t KEYIN;                             /* !< (@ 0x00001110) Input key */
} KEYSTORECTL_Regs;

/*@}*/ /* end of group KEYSTORECTL */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* KEYSTORECTL Register Control Bits
******************************************************************************/

/* KEYSTORECTL_CFG Bits */
/* KEYSTORECTL_CFG[NK256] Bits */
#define KEYSTORECTL_CFG_NK256_OFS                (0)                             /* !< NK256 Offset */
#define KEYSTORECTL_CFG_NK256_MASK               ((uint32_t)0x0000000FU)         /* !< Number of 256 bit keys to be held
                                                                                    in the key-store. Can not exceed the
                                                                                    total number of slots present in the
                                                                                    hardware / 2. For eg: if SYS_N_SLOTS
                                                                                    = 4, then atmost 2 256-bit keys can
                                                                                    be held in the key-store. Incorrect
                                                                                    setting of this field will be
                                                                                    reported via STATUS register */
#define KEYSTORECTL_CFG_NK256_ZERO               ((uint32_t)0x00000000U)         /* !< No 256-bit keys */
#define KEYSTORECTL_CFG_NK256_ONE                ((uint32_t)0x00000001U)         /* !< One 256-bit key */
#define KEYSTORECTL_CFG_NK256_TWO                ((uint32_t)0x00000002U)         /* !< Two 256-bit keys */
#define KEYSTORECTL_CFG_NK256_THREE              ((uint32_t)0x00000003U)         /* !< Three 256-bit keys */
#define KEYSTORECTL_CFG_NK256_FOUR               ((uint32_t)0x00000004U)         /* !< Four 256-bit keys */

/* KEYSTORECTL_KEYWR Bits */
/* KEYSTORECTL_KEYWR[KEYSZSEL] Bits */
#define KEYSTORECTL_KEYWR_KEYSZSEL_OFS           (0)                             /* !< KEYSZSEL Offset */
#define KEYSTORECTL_KEYWR_KEYSZSEL_MASK          ((uint32_t)0x00000007U)         /* !< Key size selection. Selection of
                                                                                    128 or 256 bit keys */
#define KEYSTORECTL_KEYWR_KEYSZSEL_K256          ((uint32_t)0x00000000U)         /* !< 256 bit key */
#define KEYSTORECTL_KEYWR_KEYSZSEL_K128          ((uint32_t)0x00000001U)         /* !< 128 bit key */
/* KEYSTORECTL_KEYWR[KEYSLOTSEL] Bits */
#define KEYSTORECTL_KEYWR_KEYSLOTSEL_OFS         (4)                             /* !< KEYSLOTSEL Offset */
#define KEYSTORECTL_KEYWR_KEYSLOTSEL_MASK        ((uint32_t)0x000000F0U)         /* !< Select the key slot to write the
                                                                                    key into. NOTE: SW needs to ensure
                                                                                    that it is writing to the correct
                                                                                    slots. The slot numbering is from 0
                                                                                    through SYS_N_SLOTS-1. Each slot is a
                                                                                    128-bit slot. Therefore, when writing
                                                                                    a 256-bit key, two slots will need to
                                                                                    budgeted. */
#define KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT0       ((uint32_t)0x00000000U)         /* !< Slot 0 */
#define KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT1       ((uint32_t)0x00000010U)         /* !< Slot 1 */
#define KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT2       ((uint32_t)0x00000020U)         /* !< Slot 2 */
#define KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT3       ((uint32_t)0x00000030U)         /* !< Slot 3 */
#define KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT4       ((uint32_t)0x00000040U)         /* !< Slot 4 */
#define KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT5       ((uint32_t)0x00000050U)         /* !< Slot 5 */
#define KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT6       ((uint32_t)0x00000060U)         /* !< Slot 6 */
#define KEYSTORECTL_KEYWR_KEYSLOTSEL_SLOT7       ((uint32_t)0x00000070U)         /* !< Slot 7 */

/* KEYSTORECTL_KEYRD Bits */
/* KEYSTORECTL_KEYRD[KEYSZSEL] Bits */
#define KEYSTORECTL_KEYRD_KEYSZSEL_OFS           (0)                             /* !< KEYSZSEL Offset */
#define KEYSTORECTL_KEYRD_KEYSZSEL_MASK          ((uint32_t)0x00000007U)         /* !< Key size selection. Selection of
                                                                                    128 or 256 bit keys */
#define KEYSTORECTL_KEYRD_KEYSZSEL_K256          ((uint32_t)0x00000000U)         /* !< 256 bit key */
#define KEYSTORECTL_KEYRD_KEYSZSEL_K128          ((uint32_t)0x00000001U)         /* !< 128 bit key */
/* KEYSTORECTL_KEYRD[KEYSLOTSEL] Bits */
#define KEYSTORECTL_KEYRD_KEYSLOTSEL_OFS         (4)                             /* !< KEYSLOTSEL Offset */
#define KEYSTORECTL_KEYRD_KEYSLOTSEL_MASK        ((uint32_t)0x000000F0U)         /* !< Select the key slot to read the key
                                                                                    from. NOTE: SW needs to ensure that
                                                                                    it is reading from the correct slots.
                                                                                    The slot numbering is from 0 through
                                                                                    SYS_N_SLOTS-1. Each slot is a 128-bit
                                                                                    slot. Therefore, when reading a
                                                                                    256-bit key, two adjacent slots will
                                                                                    be read. */
/* KEYSTORECTL_KEYRD[CRYPTOSEL] Bits */
#define KEYSTORECTL_KEYRD_CRYPTOSEL_OFS          (8)                             /* !< CRYPTOSEL Offset */
#define KEYSTORECTL_KEYRD_CRYPTOSEL_MASK         ((uint32_t)0x00000300U)         /* !< Crypto engine selector */
#define KEYSTORECTL_KEYRD_CRYPTOSEL_AES          ((uint32_t)0x00000000U)         /* !< Transfer key to AES */

/* KEYSTORECTL_STATUS Bits */
/* KEYSTORECTL_STATUS[STAT] Bits */
#define KEYSTORECTL_STATUS_STAT_OFS              (0)                             /* !< STAT Offset */
#define KEYSTORECTL_STATUS_STAT_MASK             ((uint32_t)0x0000000FU)         /* !< Status information */
#define KEYSTORECTL_STATUS_STAT_VALID            ((uint32_t)0x00000000U)         /* !< Valid configuration */
#define KEYSTORECTL_STATUS_STAT_NO_CFG           ((uint32_t)0x00000001U)         /* !< Key-store has not been configured.
                                                                                    NK256 has not been set. */
#define KEYSTORECTL_STATUS_STAT_INVALID_NK256    ((uint32_t)0x00000002U)         /* !< Invalid value for NK256 field in
                                                                                    CFG. */
#define KEYSTORECTL_STATUS_STAT_BUSY_RECEIVE     ((uint32_t)0x00000003U)         /* !< Busy receiving a key deposit */
#define KEYSTORECTL_STATUS_STAT_BUSY_TRANSMIT    ((uint32_t)0x00000004U)         /* !< Busy transmitting a key to a crypto
                                                                                    engine */
#define KEYSTORECTL_STATUS_STAT_INVALID_KEYSLOTSELW ((uint32_t)0x00000005U)         /* !< Invalid keyslot selection for
                                                                                    writing */
#define KEYSTORECTL_STATUS_STAT_INVALID_KEYSLOTSELR ((uint32_t)0x00000006U)         /* !< Invalid keyslot selection for
                                                                                    reading */
/* KEYSTORECTL_STATUS[VALID] Bits */
#define KEYSTORECTL_STATUS_VALID_OFS             (4)                             /* !< VALID Offset */
#define KEYSTORECTL_STATUS_VALID_MASK            ((uint32_t)0x00000FF0U)         /* !< Bitvector of valid bits to indicate
                                                                                    which slots have been configured */
/* KEYSTORECTL_STATUS[NKEYSLOTS] Bits */
#define KEYSTORECTL_STATUS_NKEYSLOTS_OFS         (16)                            /* !< NKEYSLOTS Offset */
#define KEYSTORECTL_STATUS_NKEYSLOTS_MASK        ((uint32_t)0x00030000U)         /* !< Size of keystorage: Number of
                                                                                    128-bit key slots */
#define KEYSTORECTL_STATUS_NKEYSLOTS_TWO         ((uint32_t)0x00000000U)         /* !< Two slots */
#define KEYSTORECTL_STATUS_NKEYSLOTS_THREE       ((uint32_t)0x00010000U)         /* !< Three slots */
#define KEYSTORECTL_STATUS_NKEYSLOTS_FOUR        ((uint32_t)0x00020000U)         /* !< Four slots */

/* KEYSTORECTL_KEYIN Bits */
/* KEYSTORECTL_KEYIN[DATA] Bits */
#define KEYSTORECTL_KEYIN_DATA_OFS               (0)                             /* !< DATA Offset */
#define KEYSTORECTL_KEYIN_DATA_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< 32-bit key data */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_keystorectl__include */
