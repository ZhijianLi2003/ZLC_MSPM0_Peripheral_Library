/*****************************************************************************

  Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/

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

#ifndef ti_devices_msp_peripherals_hw_oa__include
#define ti_devices_msp_peripherals_hw_oa__include

/* This preliminary header file does not have a version number */
/* MMR repo: https://bitbucket.itg.ti.com/projects/cmcu_msp65ip/repos/f65mspoa */
/* MMR revision: 89377c76ba10fe939dabf3c32948d02a456b2167 */
/* Generator revision: b581896b67084e57bafba0cd5bf5aa0fc4c1ca1a
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
* OA Registers
******************************************************************************/
#define OA_GPRCM_OFS                             ((uint32_t)0x00000800U)


/** @addtogroup OA_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} OA_GPRCM_Regs;

/*@}*/ /* end of group OA_GPRCM */

/** @addtogroup OA
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  OA_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED1[510];
  __IO uint32_t CLKOVR;                            /* !< (@ 0x00001010) Clock Override */
       uint32_t RESERVED2[2];
  __IO uint32_t PWRCTL;                            /* !< (@ 0x0000101C) Power Control */
       uint32_t RESERVED3[56];
  __IO uint32_t CTL;                               /* !< (@ 0x00001100) Control Register */
  __IO uint32_t CFGBASE;                           /* !< (@ 0x00001104) Configuration Base Register */
  __IO uint32_t CFG;                               /* !< (@ 0x00001108) Configuration Register */
       uint32_t RESERVED4[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00001118) Status Register */
} OA_Regs;

/*@}*/ /* end of group OA */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* OA Register Control Bits
******************************************************************************/

/* OA_PWREN Bits */
/* OA_PWREN[ENABLE] Bits */
#define OA_PWREN_ENABLE_OFS                      (0)                             /* !< ENABLE Offset */
#define OA_PWREN_ENABLE_MASK                     ((uint32_t)0x00000001U)         /* !< Enable the power */
#define OA_PWREN_ENABLE_DISABLE                  ((uint32_t)0x00000000U)         /* !< Disable Power */
#define OA_PWREN_ENABLE_ENABLE                   ((uint32_t)0x00000001U)         /* !< Enable Power */
/* OA_PWREN[KEY] Bits */
#define OA_PWREN_KEY_OFS                         (24)                            /* !< KEY Offset */
#define OA_PWREN_KEY_MASK                        ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define OA_PWREN_KEY_UNLOCK_W                    ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* OA_RSTCTL Bits */
/* OA_RSTCTL[RESETSTKYCLR] Bits */
#define OA_RSTCTL_RESETSTKYCLR_OFS               (1)                             /* !< RESETSTKYCLR Offset */
#define OA_RSTCTL_RESETSTKYCLR_MASK              ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define OA_RSTCTL_RESETSTKYCLR_NOP               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define OA_RSTCTL_RESETSTKYCLR_CLR               ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* OA_RSTCTL[RESETASSERT] Bits */
#define OA_RSTCTL_RESETASSERT_OFS                (0)                             /* !< RESETASSERT Offset */
#define OA_RSTCTL_RESETASSERT_MASK               ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define OA_RSTCTL_RESETASSERT_NOP                ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define OA_RSTCTL_RESETASSERT_ASSERT             ((uint32_t)0x00000001U)         /* !< Assert reset */
/* OA_RSTCTL[KEY] Bits */
#define OA_RSTCTL_KEY_OFS                        (24)                            /* !< KEY Offset */
#define OA_RSTCTL_KEY_MASK                       ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define OA_RSTCTL_KEY_UNLOCK_W                   ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* OA_GPRCM_STAT Bits */
/* OA_GPRCM_STAT[RESETSTKY] Bits */
#define OA_GPRCM_STAT_RESETSTKY_OFS              (16)                            /* !< RESETSTKY Offset */
#define OA_GPRCM_STAT_RESETSTKY_MASK             ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define OA_GPRCM_STAT_RESETSTKY_NORES            ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define OA_GPRCM_STAT_RESETSTKY_RESET            ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* OA_CLKOVR Bits */
/* OA_CLKOVR[OVERRIDE] Bits */
#define OA_CLKOVR_OVERRIDE_OFS                   (0)                             /* !< OVERRIDE Offset */
#define OA_CLKOVR_OVERRIDE_MASK                  ((uint32_t)0x00000001U)         /* !< Unlocks the functionality of
                                                                                    [RUN_STOP] to override the automatic
                                                                                    peripheral clock request */
#define OA_CLKOVR_OVERRIDE_DISABLED              ((uint32_t)0x00000000U)         /* !< Override disabled */
#define OA_CLKOVR_OVERRIDE_ENABLED               ((uint32_t)0x00000001U)         /* !< Override enabled */
/* OA_CLKOVR[RUN_STOP] Bits */
#define OA_CLKOVR_RUN_STOP_OFS                   (1)                             /* !< RUN_STOP Offset */
#define OA_CLKOVR_RUN_STOP_MASK                  ((uint32_t)0x00000002U)         /* !< If [OVERRIDE] is enabled, this
                                                                                    register is used to manually control
                                                                                    the peripheral's clock request to the
                                                                                    system */
#define OA_CLKOVR_RUN_STOP_RUN                   ((uint32_t)0x00000000U)         /* !< Run/ungate functional clock */
#define OA_CLKOVR_RUN_STOP_STOP                  ((uint32_t)0x00000002U)         /* !< Stop/gate functional clock */

/* OA_PWRCTL Bits */
/* OA_PWRCTL[AUTO_OFF] Bits */
#define OA_PWRCTL_AUTO_OFF_OFS                   (0)                             /* !< AUTO_OFF Offset */
#define OA_PWRCTL_AUTO_OFF_MASK                  ((uint32_t)0x00000001U)         /* !< When set the peripheral will remove
                                                                                    its local IP request for enable so
                                                                                    that it can be disabled if no other
                                                                                    entities in the system are requesting
                                                                                    it to be enabled. */
#define OA_PWRCTL_AUTO_OFF_DISABLE               ((uint32_t)0x00000000U)         /* !< Disable automatic power off
                                                                                    function */
#define OA_PWRCTL_AUTO_OFF_ENABLE                ((uint32_t)0x00000001U)         /* !< Enable automatic power off function */

/* OA_CTL Bits */
/* OA_CTL[ENABLE] Bits */
#define OA_CTL_ENABLE_OFS                        (0)                             /* !< ENABLE Offset */
#define OA_CTL_ENABLE_MASK                       ((uint32_t)0x00000001U)         /* !< OAxn Enable. */
#define OA_CTL_ENABLE_OFF                        ((uint32_t)0x00000000U)         /* !< OAxn OFF */
#define OA_CTL_ENABLE_ON                         ((uint32_t)0x00000001U)         /* !< OAxn ON */

/* OA_CFGBASE Bits */
/* OA_CFGBASE[GBW] Bits */
#define OA_CFGBASE_GBW_OFS                       (0)                             /* !< GBW Offset */
#define OA_CFGBASE_GBW_MASK                      ((uint32_t)0x00000001U)         /* !< Select gain bandwidth which affects
                                                                                    current as well the gain bandwidth.
                                                                                    The lower gain bandwidth has lower
                                                                                    current. See device specific
                                                                                    datasheet for values. Can only be
                                                                                    modified when STAT.BUSY=0. */
#define OA_CFGBASE_GBW_LOWGAIN                   ((uint32_t)0x00000000U)         /* !< Low gain bandwidth. See device
                                                                                    specific datasheet for gain
                                                                                    bandwidth. */
#define OA_CFGBASE_GBW_HIGHGAIN                  ((uint32_t)0x00000001U)         /* !< High gain bandwidth. See device
                                                                                    specific datasheet for gain
                                                                                    bandwidth. */
/* OA_CFGBASE[RRI] Bits */
#define OA_CFGBASE_RRI_OFS                       (2)                             /* !< RRI Offset */
#define OA_CFGBASE_RRI_MASK                      ((uint32_t)0x00000004U)         /* !< Rail-to-rail input enable. Can only
                                                                                    be modified when STAT.BUSY=0 */
#define OA_CFGBASE_RRI_OFF                       ((uint32_t)0x00000000U)         /* !< Rail-to-rail input disable. */
#define OA_CFGBASE_RRI_ON                        ((uint32_t)0x00000004U)         /* !< Rail-to-rail input enable. */

/* OA_CFG Bits */
/* OA_CFG[CHOP] Bits */
#define OA_CFG_CHOP_OFS                          (0)                             /* !< CHOP Offset */
#define OA_CFG_CHOP_MASK                         ((uint32_t)0x00000003U)         /* !< Chopping enable. */
#define OA_CFG_CHOP_OFF                          ((uint32_t)0x00000000U)         /* !< Chopping disable. */
#define OA_CFG_CHOP_ON                           ((uint32_t)0x00000001U)         /* !< Standard chopping enable. */
#define OA_CFG_CHOP_AVGON                        ((uint32_t)0x00000002U)         /* !< Chop with post average on. Requires
                                                                                    output to be connect to ADC in
                                                                                    average mode. */
/* OA_CFG[OUTPIN] Bits */
#define OA_CFG_OUTPIN_OFS                        (2)                             /* !< OUTPIN Offset */
#define OA_CFG_OUTPIN_MASK                       ((uint32_t)0x00000004U)         /* !< Enable output pin */
#define OA_CFG_OUTPIN_DISABLED                   ((uint32_t)0x00000000U)         /* !< Output pin disabled */
#define OA_CFG_OUTPIN_ENABLED                    ((uint32_t)0x00000004U)         /* !< Output pin enabled */
/* OA_CFG[PSEL] Bits */
#define OA_CFG_PSEL_OFS                          (3)                             /* !< PSEL Offset */
#define OA_CFG_PSEL_MASK                         ((uint32_t)0x00000078U)         /* !< Positive OA input selection.
                                                                                    Please refer to the device specific
                                                                                    datasheet for exact channels
                                                                                    available. */
#define OA_CFG_PSEL_NC                           ((uint32_t)0x00000000U)         /* !< No connect */
#define OA_CFG_PSEL_EXTPIN0                      ((uint32_t)0x00000008U)         /* !< external pin OA+0 */
#define OA_CFG_PSEL_EXTPIN1                      ((uint32_t)0x00000010U)         /* !< external pin OAn+1 */
#define OA_CFG_PSEL_DAC12OUT                     ((uint32_t)0x00000018U)         /* !< DAC12OUT */
#define OA_CFG_PSEL_DAC8OUT                      ((uint32_t)0x00000020U)         /* !< DAC8OUT */
#define OA_CFG_PSEL_VREF                         ((uint32_t)0x00000028U)         /* !< VREF Channel */
#define OA_CFG_PSEL_OANM1RTOP                    ((uint32_t)0x00000030U)         /* !< OA[n-1]Rtop */
#define OA_CFG_PSEL_GPAMP_OUT_INT                ((uint32_t)0x00000038U)         /* !< GPAMP_OUT_INT Input */
#define OA_CFG_PSEL_VSS                          ((uint32_t)0x00000040U)         /* !< Internal Grouund Connection */
/* OA_CFG[NSEL] Bits */
#define OA_CFG_NSEL_OFS                          (7)                             /* !< NSEL Offset */
#define OA_CFG_NSEL_MASK                         ((uint32_t)0x00000380U)         /* !< Negative OA input selection. Please
                                                                                    refer to the device specific
                                                                                    datasheet for exact channels
                                                                                    available. */
#define OA_CFG_NSEL_NC                           ((uint32_t)0x00000000U)         /* !< no connect */
#define OA_CFG_NSEL_EXTPIN0                      ((uint32_t)0x00000080U)         /* !< external pin OAn-0 */
#define OA_CFG_NSEL_EXTPIN1                      ((uint32_t)0x00000100U)         /* !< external pin OAn-1 */
#define OA_CFG_NSEL_OANP1RBOT                    ((uint32_t)0x00000180U)         /* !< OA[n+1]Rbot */
#define OA_CFG_NSEL_OANRTAP                      ((uint32_t)0x00000200U)         /* !< OA[n]Rtap */
#define OA_CFG_NSEL_OANRTOP                      ((uint32_t)0x00000280U)         /* !< OA[n]Rtop */
#define OA_CFG_NSEL_SPARE                        ((uint32_t)0x00000300U)         /* !< Spare input */
/* OA_CFG[MSEL] Bits */
#define OA_CFG_MSEL_OFS                          (10)                            /* !< MSEL Offset */
#define OA_CFG_MSEL_MASK                         ((uint32_t)0x00001C00U)         /* !< MSEL Mux selection.  Please refer
                                                                                    to the device specific datasheet for
                                                                                    exact channels available. */
#define OA_CFG_MSEL_NC                           ((uint32_t)0x00000000U)         /* !< no connect */
#define OA_CFG_MSEL_EXTNPIN1                     ((uint32_t)0x00000400U)         /* !< external pin OAn-1 */
#define OA_CFG_MSEL_VSS                          ((uint32_t)0x00000800U)         /* !< VSS */
#define OA_CFG_MSEL_DAC12OUT                     ((uint32_t)0x00000C00U)         /* !< DAC12 Output */
#define OA_CFG_MSEL_OANM1RTOP                    ((uint32_t)0x00001000U)         /* !< OA[n-1]Rtop */
/* OA_CFG[GAIN] Bits */
#define OA_CFG_GAIN_OFS                          (13)                            /* !< GAIN Offset */
#define OA_CFG_GAIN_MASK                         ((uint32_t)0x0000E000U)         /* !< Gain setting. Refer to TRM for
                                                                                    enumeration information. */
#define OA_CFG_GAIN_MINIMUM                      ((uint32_t)0x00000000U)         /* !< Minmum gain value */
#define OA_CFG_GAIN_MAXIMUM                      ((uint32_t)0x0000E000U)         /* !< Maximum gain value. */

/* OA_STAT Bits */
/* OA_STAT[RDY] Bits */
#define OA_STAT_RDY_OFS                          (0)                             /* !< RDY Offset */
#define OA_STAT_RDY_MASK                         ((uint32_t)0x00000001U)         /* !< OA ready status. */
#define OA_STAT_RDY_FALSE                        ((uint32_t)0x00000000U)         /* !< OAxn is not ready. */
#define OA_STAT_RDY_TRUE                         ((uint32_t)0x00000001U)         /* !< OAxn is ready. */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_oa__include */
