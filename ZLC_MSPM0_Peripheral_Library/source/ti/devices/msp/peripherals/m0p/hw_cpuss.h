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

#ifndef ti_devices_msp_peripherals_m0p_hw_cpuss__include
#define ti_devices_msp_peripherals_m0p_hw_cpuss__include

/* Filename: hw_cpuss.h */
/* Revised: 2023-04-30 21:36:20 */
/* Revision: ec4f3de051dafa6135b4867f4e796eec5f1a339b */

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
* CPUSS Registers
******************************************************************************/
#define CPUSS_INT_GROUP_OFS                      ((uint32_t)0x00001100U)


/** @addtogroup CPUSS_INT_GROUP
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001100) Interrupt index */
       uint32_t RESERVED0;
  __I  uint32_t IMASK;                             /* !< (@ 0x00001108) Interrupt mask */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x00001110) Raw interrupt status */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x00001118) Masked interrupt status */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x00001120) Interrupt set */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x00001128) Interrupt clear */
       uint32_t RESERVED5;
} CPUSS_INT_GROUP_Regs;

/*@}*/ /* end of group CPUSS_INT_GROUP */

/** @addtogroup CPUSS
  @{
*/

typedef struct {
       uint32_t RESERVED0[1080];
  __I  uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED1[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
  CPUSS_INT_GROUP_Regs  INT_GROUP[5];                      /* !< (@ 0x00001100) */
       uint32_t RESERVED2[68];
  __IO uint32_t CTL;                               /* !< (@ 0x00001300) Prefetch/Cache control */
} CPUSS_Regs;

/*@}*/ /* end of group CPUSS */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* CPUSS Register Control Bits
******************************************************************************/

/* CPUSS_INT_GROUP_IIDX Bits */
/* CPUSS_INT_GROUP_IIDX[STAT] Bits */
#define CPUSS_INT_GROUP_IIDX_STAT_OFS            (0)                             /* !< STAT Offset */
#define CPUSS_INT_GROUP_IIDX_STAT_MASK           ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define CPUSS_INT_GROUP_IIDX_STAT_NO_INTR        ((uint32_t)0x00000000U)         /* !< No pending interrupt */
#define CPUSS_INT_GROUP_IIDX_STAT_INT0           ((uint32_t)0x00000001U)         /* !< Interrupt 0 */
#define CPUSS_INT_GROUP_IIDX_STAT_INT1           ((uint32_t)0x00000002U)         /* !< Interrupt 1 */
#define CPUSS_INT_GROUP_IIDX_STAT_INT2           ((uint32_t)0x00000003U)         /* !< Interrupt 2 */
#define CPUSS_INT_GROUP_IIDX_STAT_INT3           ((uint32_t)0x00000004U)         /* !< Interrupt 3 */
#define CPUSS_INT_GROUP_IIDX_STAT_INT4           ((uint32_t)0x00000005U)         /* !< Interrupt 4 */
#define CPUSS_INT_GROUP_IIDX_STAT_INT5           ((uint32_t)0x00000006U)         /* !< Interrupt 5 */
#define CPUSS_INT_GROUP_IIDX_STAT_INT6           ((uint32_t)0x00000007U)         /* !< Interrupt 6 */
#define CPUSS_INT_GROUP_IIDX_STAT_INT7           ((uint32_t)0x00000008U)         /* !< Interrupt 7 */

/* CPUSS_INT_GROUP_IMASK Bits */
/* CPUSS_INT_GROUP_IMASK[INT] Bits */
#define CPUSS_INT_GROUP_IMASK_INT_OFS            (0)                             /* !< INT Offset */
#define CPUSS_INT_GROUP_IMASK_INT_MASK           ((uint32_t)0x000000FFU)         /* !< Masks the corresponding interrupt */
#define CPUSS_INT_GROUP_IMASK_INT_INT0           ((uint32_t)0x00000001U)         /* !< Interrupt 0 */
#define CPUSS_INT_GROUP_IMASK_INT_INT1           ((uint32_t)0x00000002U)         /* !< Interrupt 1 */
#define CPUSS_INT_GROUP_IMASK_INT_INT2           ((uint32_t)0x00000004U)         /* !< Interrupt 2 */
#define CPUSS_INT_GROUP_IMASK_INT_INT3           ((uint32_t)0x00000008U)         /* !< Interrupt 3 */
#define CPUSS_INT_GROUP_IMASK_INT_INT4           ((uint32_t)0x00000010U)         /* !< Interrupt 4 */
#define CPUSS_INT_GROUP_IMASK_INT_INT5           ((uint32_t)0x00000020U)         /* !< Interrupt 5 */
#define CPUSS_INT_GROUP_IMASK_INT_INT6           ((uint32_t)0x00000040U)         /* !< Interrupt 6 */
#define CPUSS_INT_GROUP_IMASK_INT_INT7           ((uint32_t)0x00000080U)         /* !< Interrupt 7 */

/* CPUSS_INT_GROUP_RIS Bits */
/* CPUSS_INT_GROUP_RIS[INT] Bits */
#define CPUSS_INT_GROUP_RIS_INT_OFS              (0)                             /* !< INT Offset */
#define CPUSS_INT_GROUP_RIS_INT_MASK             ((uint32_t)0x000000FFU)         /* !< Raw interrupt status for INT */
#define CPUSS_INT_GROUP_RIS_INT_INT0             ((uint32_t)0x00000001U)         /* !< Interrupt 0 */
#define CPUSS_INT_GROUP_RIS_INT_INT1             ((uint32_t)0x00000002U)         /* !< Interrupt 1 */
#define CPUSS_INT_GROUP_RIS_INT_INT2             ((uint32_t)0x00000004U)         /* !< Interrupt 2 */
#define CPUSS_INT_GROUP_RIS_INT_INT3             ((uint32_t)0x00000008U)         /* !< Interrupt 3 */
#define CPUSS_INT_GROUP_RIS_INT_INT4             ((uint32_t)0x00000010U)         /* !< Interrupt 4 */
#define CPUSS_INT_GROUP_RIS_INT_INT5             ((uint32_t)0x00000020U)         /* !< Interrupt 5 */
#define CPUSS_INT_GROUP_RIS_INT_INT6             ((uint32_t)0x00000040U)         /* !< Interrupt 6 */
#define CPUSS_INT_GROUP_RIS_INT_INT7             ((uint32_t)0x00000080U)         /* !< Interrupt 7 */

/* CPUSS_INT_GROUP_MIS Bits */
/* CPUSS_INT_GROUP_MIS[INT] Bits */
#define CPUSS_INT_GROUP_MIS_INT_OFS              (0)                             /* !< INT Offset */
#define CPUSS_INT_GROUP_MIS_INT_MASK             ((uint32_t)0x000000FFU)         /* !< Masked interrupt status for INT0 */
#define CPUSS_INT_GROUP_MIS_INT_INT0             ((uint32_t)0x00000001U)         /* !< Interrupt 0 */
#define CPUSS_INT_GROUP_MIS_INT_INT1             ((uint32_t)0x00000002U)         /* !< Interrupt 1 */
#define CPUSS_INT_GROUP_MIS_INT_INT2             ((uint32_t)0x00000004U)         /* !< Interrupt 2 */
#define CPUSS_INT_GROUP_MIS_INT_INT3             ((uint32_t)0x00000008U)         /* !< Interrupt 3 */
#define CPUSS_INT_GROUP_MIS_INT_INT4             ((uint32_t)0x00000010U)         /* !< Interrupt 4 */
#define CPUSS_INT_GROUP_MIS_INT_INT5             ((uint32_t)0x00000020U)         /* !< Interrupt 5 */
#define CPUSS_INT_GROUP_MIS_INT_INT6             ((uint32_t)0x00000040U)         /* !< Interrupt 6 */
#define CPUSS_INT_GROUP_MIS_INT_INT7             ((uint32_t)0x00000080U)         /* !< Interrupt 7 */

/* CPUSS_INT_GROUP_ISET Bits */
/* CPUSS_INT_GROUP_ISET[INT] Bits */
#define CPUSS_INT_GROUP_ISET_INT_OFS             (0)                             /* !< INT Offset */
#define CPUSS_INT_GROUP_ISET_INT_MASK            ((uint32_t)0x000000FFU)         /* !< Sets INT in RIS register */
#define CPUSS_INT_GROUP_ISET_INT_INT0            ((uint32_t)0x00000001U)         /* !< Interrupt 0 */
#define CPUSS_INT_GROUP_ISET_INT_INT1            ((uint32_t)0x00000002U)         /* !< Interrupt 1 */
#define CPUSS_INT_GROUP_ISET_INT_INT2            ((uint32_t)0x00000004U)         /* !< Interrupt 2 */
#define CPUSS_INT_GROUP_ISET_INT_INT3            ((uint32_t)0x00000008U)         /* !< Interrupt 3 */
#define CPUSS_INT_GROUP_ISET_INT_INT4            ((uint32_t)0x00000010U)         /* !< Interrupt 4 */
#define CPUSS_INT_GROUP_ISET_INT_INT5            ((uint32_t)0x00000020U)         /* !< Interrupt 5 */
#define CPUSS_INT_GROUP_ISET_INT_INT6            ((uint32_t)0x00000040U)         /* !< Interrupt 6 */
#define CPUSS_INT_GROUP_ISET_INT_INT7            ((uint32_t)0x00000080U)         /* !< Interrupt 7 */

/* CPUSS_INT_GROUP_ICLR Bits */
/* CPUSS_INT_GROUP_ICLR[INT] Bits */
#define CPUSS_INT_GROUP_ICLR_INT_OFS             (0)                             /* !< INT Offset */
#define CPUSS_INT_GROUP_ICLR_INT_MASK            ((uint32_t)0x000000FFU)         /* !< Clears INT in RIS register */
#define CPUSS_INT_GROUP_ICLR_INT_INT0            ((uint32_t)0x00000001U)         /* !< Interrupt 0 */
#define CPUSS_INT_GROUP_ICLR_INT_INT1            ((uint32_t)0x00000002U)         /* !< Interrupt 1 */
#define CPUSS_INT_GROUP_ICLR_INT_INT2            ((uint32_t)0x00000004U)         /* !< Interrupt 2 */
#define CPUSS_INT_GROUP_ICLR_INT_INT3            ((uint32_t)0x00000008U)         /* !< Interrupt 3 */
#define CPUSS_INT_GROUP_ICLR_INT_INT4            ((uint32_t)0x00000010U)         /* !< Interrupt 4 */
#define CPUSS_INT_GROUP_ICLR_INT_INT5            ((uint32_t)0x00000020U)         /* !< Interrupt 5 */
#define CPUSS_INT_GROUP_ICLR_INT_INT6            ((uint32_t)0x00000040U)         /* !< Interrupt 6 */
#define CPUSS_INT_GROUP_ICLR_INT_INT7            ((uint32_t)0x00000080U)         /* !< Interrupt 7 */

/* CPUSS_EVT_MODE Bits */
/* CPUSS_EVT_MODE[INT_CFG] Bits */
#define CPUSS_EVT_MODE_INT_CFG_OFS               (0)                             /* !< INT_CFG Offset */
#define CPUSS_EVT_MODE_INT_CFG_MASK              ((uint32_t)0x00000003U)         /* !< Event line mode select */
#define CPUSS_EVT_MODE_INT_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define CPUSS_EVT_MODE_INT_CFG_SOFTWARE          ((uint32_t)0x00000001U)         /* !< Event handled by software. Software
                                                                                    must clear the associated RIS flag. */
#define CPUSS_EVT_MODE_INT_CFG_HARDWARE          ((uint32_t)0x00000002U)         /* !< Event handled by hardware. The
                                                                                    hardware (another module) clears
                                                                                    automatically the associated RIS
                                                                                    flag. */

/* CPUSS_DESC Bits */
/* CPUSS_DESC[MINREV] Bits */
#define CPUSS_DESC_MINREV_OFS                    (0)                             /* !< MINREV Offset */
#define CPUSS_DESC_MINREV_MASK                   ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
/* CPUSS_DESC[MAJREV] Bits */
#define CPUSS_DESC_MAJREV_OFS                    (4)                             /* !< MAJREV Offset */
#define CPUSS_DESC_MAJREV_MASK                   ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
/* CPUSS_DESC[FEATUREVER] Bits */
#define CPUSS_DESC_FEATUREVER_OFS                (12)                            /* !< FEATUREVER Offset */
#define CPUSS_DESC_FEATUREVER_MASK               ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
/* CPUSS_DESC[MODULEID] Bits */
#define CPUSS_DESC_MODULEID_OFS                  (16)                            /* !< MODULEID Offset */
#define CPUSS_DESC_MODULEID_MASK                 ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */

/* CPUSS_CTL Bits */
/* CPUSS_CTL[PREFETCH] Bits */
#define CPUSS_CTL_PREFETCH_OFS                   (0)                             /* !< PREFETCH Offset */
#define CPUSS_CTL_PREFETCH_MASK                  ((uint32_t)0x00000001U)         /* !< Used to enable/disable instruction
                                                                                    prefetch to Flash. */
#define CPUSS_CTL_PREFETCH_DISABLE               ((uint32_t)0x00000000U)         /* !< Disable instruction prefetch. */
#define CPUSS_CTL_PREFETCH_ENABLE                ((uint32_t)0x00000001U)         /* !< Enable instruction prefetch. */
/* CPUSS_CTL[ICACHE] Bits */
#define CPUSS_CTL_ICACHE_OFS                     (1)                             /* !< ICACHE Offset */
#define CPUSS_CTL_ICACHE_MASK                    ((uint32_t)0x00000002U)         /* !< Used to enable/disable Instruction
                                                                                    caching on flash access. */
#define CPUSS_CTL_ICACHE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Disable instruction caching. */
#define CPUSS_CTL_ICACHE_ENABLE                  ((uint32_t)0x00000002U)         /* !< Enable instruction caching. */
/* CPUSS_CTL[LITEN] Bits */
#define CPUSS_CTL_LITEN_OFS                      (2)                             /* !< LITEN Offset */
#define CPUSS_CTL_LITEN_MASK                     ((uint32_t)0x00000004U)         /* !< Literal caching and prefetch
                                                                                    enable.  This bit is a subset of
                                                                                    ICACHE/PREFETCH bit i.e. literal
                                                                                    caching or literal prefetching will
                                                                                    only happen if ICACHE or PREFETCH
                                                                                    bits have been set respectively  When
                                                                                    enabled, the cache and prefetcher
                                                                                    structures inside CPUSS will cache
                                                                                    and prefetch literals When disabled,
                                                                                    the cache and prefetcher structures
                                                                                    inside CPUSS will not cache and
                                                                                    prefetch literals */
#define CPUSS_CTL_LITEN_DISABLE                  ((uint32_t)0x00000000U)         /* !< Literal caching disabled */
#define CPUSS_CTL_LITEN_ENABLE                   ((uint32_t)0x00000004U)         /* !< Literal caching enabled */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_m0p_hw_cpuss__include */
