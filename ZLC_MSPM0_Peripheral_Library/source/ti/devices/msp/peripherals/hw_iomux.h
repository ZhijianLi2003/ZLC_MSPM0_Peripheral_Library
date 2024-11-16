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

#ifndef ti_devices_msp_peripherals_hw_iomux__include
#define ti_devices_msp_peripherals_hw_iomux__include

/* Filename: hw_iomux.h */
/* Revised: 2023-05-10 21:32:43 */
/* Revision: ccc8d5592eceba00f0e63b10bdaec9c7cd64733b */

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
* IOMUX Registers
******************************************************************************/
#define IOMUX_SECCFG_OFS                         ((uint32_t)0x00000000U)


/** @addtogroup IOMUX_SECCFG
  @{
*/

typedef struct {
       uint32_t RESERVED0;
  __IO uint32_t PINCM[251];                        /* !< (@ 0x00000004) Pin Control Management Register in SECCFG region */
} IOMUX_SECCFG_Regs;

/*@}*/ /* end of group IOMUX_SECCFG */

/** @addtogroup IOMUX
  @{
*/

typedef struct {
  IOMUX_SECCFG_Regs  SECCFG;                            /* !< (@ 0x00000000) SECCFG register region */
} IOMUX_Regs;

/*@}*/ /* end of group IOMUX */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* IOMUX Register Control Bits
******************************************************************************/

/* IOMUX_PINCM Bits */
/* IOMUX_PINCM[PF] Bits */
#define IOMUX_PINCM_PF_OFS                       (0)                             /* !< PF Offset */
#define IOMUX_PINCM_PF_MASK                      ((uint32_t)0x0000003FU)         /* !< Peripheral Function selection bits */
#define IOMUX_PINCM_PF_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Reserved as unconnected */
#define IOMUX_PINCM_PF_MAXIMUM                   ((uint32_t)0x0000003FU)         /* !< An encoding per function that can
                                                                                    be connected to this pin. */
/* IOMUX_PINCM[PC] Bits */
#define IOMUX_PINCM_PC_OFS                       (7)                             /* !< PC Offset */
#define IOMUX_PINCM_PC_MASK                      ((uint32_t)0x00000080U)         /* !< Peripheral is Connected */
#define IOMUX_PINCM_PC_UNCONNECTED               ((uint32_t)0x00000000U)         /* !< The output of the peripheral (and
                                                                                    its output enable) will not propagate
                                                                                    to the IOCELL */
#define IOMUX_PINCM_PC_CONNECTED                 ((uint32_t)0x00000080U)         /* !< The output latch of the dataflow
                                                                                    will be transparent */
/* IOMUX_PINCM[WAKESTAT] Bits */
#define IOMUX_PINCM_WAKESTAT_OFS                 (13)                            /* !< WAKESTAT Offset */
#define IOMUX_PINCM_WAKESTAT_MASK                ((uint32_t)0x00002000U)         /* !< This has the IOPAD WAKEUP signal as
                                                                                    status bit. */
#define IOMUX_PINCM_WAKESTAT_DISABLE             ((uint32_t)0x00000000U)         /* !< wakeup source is NOT from this
                                                                                    IOCELL */
#define IOMUX_PINCM_WAKESTAT_ENABLE              ((uint32_t)0x00002000U)         /* !< wakeup source is from this IOCELL */
/* IOMUX_PINCM[PIPD] Bits */
#define IOMUX_PINCM_PIPD_OFS                     (16)                            /* !< PIPD Offset */
#define IOMUX_PINCM_PIPD_MASK                    ((uint32_t)0x00010000U)         /* !< Pull Down control selection */
#define IOMUX_PINCM_PIPD_DISABLE                 ((uint32_t)0x00000000U)         /* !< Pull down is disabled. */
#define IOMUX_PINCM_PIPD_ENABLE                  ((uint32_t)0x00010000U)         /* !< Pull down is enabled */
/* IOMUX_PINCM[PIPU] Bits */
#define IOMUX_PINCM_PIPU_OFS                     (17)                            /* !< PIPU Offset */
#define IOMUX_PINCM_PIPU_MASK                    ((uint32_t)0x00020000U)         /* !< Pull Up control selection */
#define IOMUX_PINCM_PIPU_DISABLE                 ((uint32_t)0x00000000U)         /* !< Pull up is disabled. */
#define IOMUX_PINCM_PIPU_ENABLE                  ((uint32_t)0x00020000U)         /* !< Pull up is enabled */
/* IOMUX_PINCM[INENA] Bits */
#define IOMUX_PINCM_INENA_OFS                    (18)                            /* !< INENA Offset */
#define IOMUX_PINCM_INENA_MASK                   ((uint32_t)0x00040000U)         /* !< Input Enable Control Selection */
#define IOMUX_PINCM_INENA_DISABLE                ((uint32_t)0x00000000U)         /* !< Input enable is disabled. */
#define IOMUX_PINCM_INENA_ENABLE                 ((uint32_t)0x00040000U)         /* !< Input enable is enabled. */
/* IOMUX_PINCM[HYSTEN] Bits */
#define IOMUX_PINCM_HYSTEN_OFS                   (19)                            /* !< HYSTEN Offset */
#define IOMUX_PINCM_HYSTEN_MASK                  ((uint32_t)0x00080000U)         /* !< Hysteresis Enable Control Selection */
#define IOMUX_PINCM_HYSTEN_DISABLE               ((uint32_t)0x00000000U)         /* !< hysteresis is disabled. */
#define IOMUX_PINCM_HYSTEN_ENABLE                ((uint32_t)0x00080000U)         /* !< hysteresis is enabled */
/* IOMUX_PINCM[DRV] Bits */
#define IOMUX_PINCM_DRV_OFS                      (20)                            /* !< DRV Offset */
#define IOMUX_PINCM_DRV_MASK                     ((uint32_t)0x00100000U)         /* !< Drive strength control selection,
                                                                                    for HS IOCELL only */
#define IOMUX_PINCM_DRV_DRVVAL0                  ((uint32_t)0x00000000U)         /* !< Drive setting of 0 selected */
#define IOMUX_PINCM_DRV_DRVVAL1                  ((uint32_t)0x00100000U)         /* !< Drive setting of 1 selected */
/* IOMUX_PINCM[HIZ1] Bits */
#define IOMUX_PINCM_HIZ1_OFS                     (25)                            /* !< HIZ1 Offset */
#define IOMUX_PINCM_HIZ1_MASK                    ((uint32_t)0x02000000U)         /* !< High output value will tri-state
                                                                                    the output when this bit is enabled */
#define IOMUX_PINCM_HIZ1_DISABLE                 ((uint32_t)0x00000000U)         /* !< open-drain is disabled. */
#define IOMUX_PINCM_HIZ1_ENABLE                  ((uint32_t)0x02000000U)         /* !< open-drain is enabled. */
/* IOMUX_PINCM[WUEN] Bits */
#define IOMUX_PINCM_WUEN_OFS                     (27)                            /* !< WUEN Offset */
#define IOMUX_PINCM_WUEN_MASK                    ((uint32_t)0x08000000U)         /* !< Wakeup Enable bit */
#define IOMUX_PINCM_WUEN_DISABLE                 ((uint32_t)0x00000000U)         /* !< wakeup is disabled. */
#define IOMUX_PINCM_WUEN_ENABLE                  ((uint32_t)0x08000000U)         /* !< wakeup is enabled */
/* IOMUX_PINCM[WCOMP] Bits */
#define IOMUX_PINCM_WCOMP_OFS                    (28)                            /* !< WCOMP Offset */
#define IOMUX_PINCM_WCOMP_MASK                   ((uint32_t)0x10000000U)         /* !< Wakeup Compare Value bit */
#define IOMUX_PINCM_WCOMP_MATCH0                 ((uint32_t)0x00000000U)         /* !< Wakeup on a match of 0 */
#define IOMUX_PINCM_WCOMP_MATCH1                 ((uint32_t)0x10000000U)         /* !< Wakeup on a match of 1 */
/* IOMUX_PINCM[INV] Bits */
#define IOMUX_PINCM_INV_OFS                      (26)                            /* !< INV Offset */
#define IOMUX_PINCM_INV_MASK                     ((uint32_t)0x04000000U)         /* !< Data inversion selection */
#define IOMUX_PINCM_INV_DISABLE                  ((uint32_t)0x00000000U)         /* !< Data inversion is disabled. */
#define IOMUX_PINCM_INV_ENABLE                   ((uint32_t)0x04000000U)         /* !< Data inversion is enabled */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_iomux__include */
