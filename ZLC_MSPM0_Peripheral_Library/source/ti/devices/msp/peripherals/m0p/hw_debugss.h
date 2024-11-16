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

#ifndef ti_devices_msp_peripherals_m0p_hw_debugss__include
#define ti_devices_msp_peripherals_m0p_hw_debugss__include

/* Filename: hw_debugss.h */
/* Revised: 2023-05-10 21:16:53 */
/* Revision: 2f29710894b537f621c6ebedd563efb234664827 */

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
* DEBUGSS Registers
******************************************************************************/
#define DEBUGSS_CPU_INT_OFS                      ((uint32_t)0x00001020U)


/** @addtogroup DEBUGSS_CPU_INT
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001020) Interrupt index */
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
} DEBUGSS_CPU_INT_Regs;

/*@}*/ /* end of group DEBUGSS_CPU_INT */

/** @addtogroup DEBUGSS
  @{
*/

typedef struct {
       uint32_t RESERVED0[1032];
  DEBUGSS_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED1[37];
  __I  uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED2[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
  __I  uint32_t TXD;                               /* !< (@ 0x00001100) Transmit data register */
  __I  uint32_t TXCTL;                             /* !< (@ 0x00001104) Transmit control register */
  __IO uint32_t RXD;                               /* !< (@ 0x00001108) Receive data register */
  __IO uint32_t RXCTL;                             /* !< (@ 0x0000110C) Receive control register */
       uint32_t RESERVED3[60];
  __I  uint32_t SPECIAL_AUTH;                      /* !< (@ 0x00001200) Special enable authorization register */
       uint32_t RESERVED4[3];
  __I  uint32_t APP_AUTH;                          /* !< (@ 0x00001210) Application CPU0 authorization register */
} DEBUGSS_Regs;

/*@}*/ /* end of group DEBUGSS */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* DEBUGSS Register Control Bits
******************************************************************************/

/* DEBUGSS_IIDX Bits */
/* DEBUGSS_IIDX[STAT] Bits */
#define DEBUGSS_IIDX_STAT_OFS                    (0)                             /* !< STAT Offset */
#define DEBUGSS_IIDX_STAT_MASK                   ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define DEBUGSS_IIDX_STAT_NO_INTR                ((uint32_t)0x00000000U)         /* !< No pending interrupt request */
#define DEBUGSS_IIDX_STAT_TXIFG                  ((uint32_t)0x00000001U)         /* !< TX interrupt */
#define DEBUGSS_IIDX_STAT_RXIFG                  ((uint32_t)0x00000002U)         /* !< RX interrupt */
#define DEBUGSS_IIDX_STAT_PWRUP                  ((uint32_t)0x00000003U)         /* !< Power-up interrupt. A debug session
                                                                                    has started. */
#define DEBUGSS_IIDX_STAT_PWRDWN                 ((uint32_t)0x00000004U)         /* !< Power-up interrupt. A debug session
                                                                                    has started. */

/* DEBUGSS_IMASK Bits */
/* DEBUGSS_IMASK[TXIFG] Bits */
#define DEBUGSS_IMASK_TXIFG_OFS                  (0)                             /* !< TXIFG Offset */
#define DEBUGSS_IMASK_TXIFG_MASK                 ((uint32_t)0x00000001U)         /* !< Masks TXIFG in MIS register */
#define DEBUGSS_IMASK_TXIFG_CLR                  ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DEBUGSS_IMASK_TXIFG_SET                  ((uint32_t)0x00000001U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DEBUGSS_IMASK[RXIFG] Bits */
#define DEBUGSS_IMASK_RXIFG_OFS                  (1)                             /* !< RXIFG Offset */
#define DEBUGSS_IMASK_RXIFG_MASK                 ((uint32_t)0x00000002U)         /* !< Masks RXIFG in MIS register */
#define DEBUGSS_IMASK_RXIFG_CLR                  ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DEBUGSS_IMASK_RXIFG_SET                  ((uint32_t)0x00000002U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DEBUGSS_IMASK[PWRUPIFG] Bits */
#define DEBUGSS_IMASK_PWRUPIFG_OFS               (2)                             /* !< PWRUPIFG Offset */
#define DEBUGSS_IMASK_PWRUPIFG_MASK              ((uint32_t)0x00000004U)         /* !< Masks PWRUPIFG in MIS register */
#define DEBUGSS_IMASK_PWRUPIFG_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DEBUGSS_IMASK_PWRUPIFG_SET               ((uint32_t)0x00000004U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DEBUGSS_IMASK[PWRDWNIFG] Bits */
#define DEBUGSS_IMASK_PWRDWNIFG_OFS              (3)                             /* !< PWRDWNIFG Offset */
#define DEBUGSS_IMASK_PWRDWNIFG_MASK             ((uint32_t)0x00000008U)         /* !< Masks PWRDWNIFG in MIS register */
#define DEBUGSS_IMASK_PWRDWNIFG_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DEBUGSS_IMASK_PWRDWNIFG_SET              ((uint32_t)0x00000008U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */

/* DEBUGSS_RIS Bits */
/* DEBUGSS_RIS[TXIFG] Bits */
#define DEBUGSS_RIS_TXIFG_OFS                    (0)                             /* !< TXIFG Offset */
#define DEBUGSS_RIS_TXIFG_MASK                   ((uint32_t)0x00000001U)         /* !< Raw interrupt status for TXIFG */
#define DEBUGSS_RIS_TXIFG_CLR                    ((uint32_t)0x00000000U)         /* !< TXIFG did not occur */
#define DEBUGSS_RIS_TXIFG_SET                    ((uint32_t)0x00000001U)         /* !< TXIFG occurred */
/* DEBUGSS_RIS[RXIFG] Bits */
#define DEBUGSS_RIS_RXIFG_OFS                    (1)                             /* !< RXIFG Offset */
#define DEBUGSS_RIS_RXIFG_MASK                   ((uint32_t)0x00000002U)         /* !< Raw interrupt status for RXIFG */
#define DEBUGSS_RIS_RXIFG_CLR                    ((uint32_t)0x00000000U)         /* !< RXIFG did not occur */
#define DEBUGSS_RIS_RXIFG_SET                    ((uint32_t)0x00000002U)         /* !< RXIFG occurred */
/* DEBUGSS_RIS[PWRUPIFG] Bits */
#define DEBUGSS_RIS_PWRUPIFG_OFS                 (2)                             /* !< PWRUPIFG Offset */
#define DEBUGSS_RIS_PWRUPIFG_MASK                ((uint32_t)0x00000004U)         /* !< Raw interrupt status for PWRUPIFG */
#define DEBUGSS_RIS_PWRUPIFG_CLR                 ((uint32_t)0x00000000U)         /* !< PWRUPIFG did not occur */
#define DEBUGSS_RIS_PWRUPIFG_SET                 ((uint32_t)0x00000004U)         /* !< PWRUPIFG occurred */
/* DEBUGSS_RIS[PWRDWNIFG] Bits */
#define DEBUGSS_RIS_PWRDWNIFG_OFS                (3)                             /* !< PWRDWNIFG Offset */
#define DEBUGSS_RIS_PWRDWNIFG_MASK               ((uint32_t)0x00000008U)         /* !< Raw interrupt status for PWRDWNIFG */
#define DEBUGSS_RIS_PWRDWNIFG_CLR                ((uint32_t)0x00000000U)         /* !< PWRUPIFG did not occur */
#define DEBUGSS_RIS_PWRDWNIFG_SET                ((uint32_t)0x00000008U)         /* !< PWRUPIFG occurred */

/* DEBUGSS_MIS Bits */
/* DEBUGSS_MIS[TXIFG] Bits */
#define DEBUGSS_MIS_TXIFG_OFS                    (0)                             /* !< TXIFG Offset */
#define DEBUGSS_MIS_TXIFG_MASK                   ((uint32_t)0x00000001U)         /* !< Masked interrupt status for TXIFG */
#define DEBUGSS_MIS_TXIFG_CLR                    ((uint32_t)0x00000000U)         /* !< TXIFG did not request an interrupt
                                                                                    service routine */
#define DEBUGSS_MIS_TXIFG_SET                    ((uint32_t)0x00000001U)         /* !< TXIFG requests an interrupt service
                                                                                    routine */
/* DEBUGSS_MIS[RXIFG] Bits */
#define DEBUGSS_MIS_RXIFG_OFS                    (1)                             /* !< RXIFG Offset */
#define DEBUGSS_MIS_RXIFG_MASK                   ((uint32_t)0x00000002U)         /* !< Masked interrupt status for RXIFG */
#define DEBUGSS_MIS_RXIFG_CLR                    ((uint32_t)0x00000000U)         /* !< RXIFG did not request an interrupt
                                                                                    service routine */
#define DEBUGSS_MIS_RXIFG_SET                    ((uint32_t)0x00000002U)         /* !< RXIFG requests an interrupt service
                                                                                    routine */
/* DEBUGSS_MIS[PWRUPIFG] Bits */
#define DEBUGSS_MIS_PWRUPIFG_OFS                 (2)                             /* !< PWRUPIFG Offset */
#define DEBUGSS_MIS_PWRUPIFG_MASK                ((uint32_t)0x00000004U)         /* !< Masked interrupt status for
                                                                                    PWRUPIFG */
#define DEBUGSS_MIS_PWRUPIFG_CLR                 ((uint32_t)0x00000000U)         /* !< PWRUPIFG did not request an
                                                                                    interrupt service routine */
#define DEBUGSS_MIS_PWRUPIFG_SET                 ((uint32_t)0x00000004U)         /* !< PWRUPIFG requests an interrupt
                                                                                    service routine */
/* DEBUGSS_MIS[PWRDWNIFG] Bits */
#define DEBUGSS_MIS_PWRDWNIFG_OFS                (3)                             /* !< PWRDWNIFG Offset */
#define DEBUGSS_MIS_PWRDWNIFG_MASK               ((uint32_t)0x00000008U)         /* !< Masked interrupt status for
                                                                                    PWRDWNIFG */
#define DEBUGSS_MIS_PWRDWNIFG_CLR                ((uint32_t)0x00000000U)         /* !< PWRUPIFG did not request an
                                                                                    interrupt service routine */
#define DEBUGSS_MIS_PWRDWNIFG_SET                ((uint32_t)0x00000008U)         /* !< PWRUPIFG requests an interrupt
                                                                                    service routine */

/* DEBUGSS_ISET Bits */
/* DEBUGSS_ISET[TXIFG] Bits */
#define DEBUGSS_ISET_TXIFG_OFS                   (0)                             /* !< TXIFG Offset */
#define DEBUGSS_ISET_TXIFG_MASK                  ((uint32_t)0x00000001U)         /* !< Sets TXIFG in RIS register */
#define DEBUGSS_ISET_TXIFG_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ISET_TXIFG_SET                   ((uint32_t)0x00000001U)         /* !< RIS bit corresponding to TXIFG is
                                                                                    set */
/* DEBUGSS_ISET[RXIFG] Bits */
#define DEBUGSS_ISET_RXIFG_OFS                   (1)                             /* !< RXIFG Offset */
#define DEBUGSS_ISET_RXIFG_MASK                  ((uint32_t)0x00000002U)         /* !< Sets RXIFG in RIS register */
#define DEBUGSS_ISET_RXIFG_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ISET_RXIFG_SET                   ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to RXIFG is
                                                                                    set */
/* DEBUGSS_ISET[PWRUPIFG] Bits */
#define DEBUGSS_ISET_PWRUPIFG_OFS                (2)                             /* !< PWRUPIFG Offset */
#define DEBUGSS_ISET_PWRUPIFG_MASK               ((uint32_t)0x00000004U)         /* !< Sets PWRUPIFG in RIS register */
#define DEBUGSS_ISET_PWRUPIFG_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ISET_PWRUPIFG_SET                ((uint32_t)0x00000004U)         /* !< RIS bit corresponding to PWRUPIFG
                                                                                    is set */
/* DEBUGSS_ISET[PWRDWNIFG] Bits */
#define DEBUGSS_ISET_PWRDWNIFG_OFS               (3)                             /* !< PWRDWNIFG Offset */
#define DEBUGSS_ISET_PWRDWNIFG_MASK              ((uint32_t)0x00000008U)         /* !< Sets PWRDWNIFG in RIS register */
#define DEBUGSS_ISET_PWRDWNIFG_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ISET_PWRDWNIFG_SET               ((uint32_t)0x00000008U)         /* !< RIS bit corresponding to PWRUPIFG
                                                                                    is set */

/* DEBUGSS_ICLR Bits */
/* DEBUGSS_ICLR[TXIFG] Bits */
#define DEBUGSS_ICLR_TXIFG_OFS                   (0)                             /* !< TXIFG Offset */
#define DEBUGSS_ICLR_TXIFG_MASK                  ((uint32_t)0x00000001U)         /* !< Clears TXIFG in RIS register */
#define DEBUGSS_ICLR_TXIFG_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ICLR_TXIFG_CLR                   ((uint32_t)0x00000001U)         /* !< RIS bit corresponding to TXIFG is
                                                                                    cleared */
/* DEBUGSS_ICLR[RXIFG] Bits */
#define DEBUGSS_ICLR_RXIFG_OFS                   (1)                             /* !< RXIFG Offset */
#define DEBUGSS_ICLR_RXIFG_MASK                  ((uint32_t)0x00000002U)         /* !< Clears RXIFG in RIS register */
#define DEBUGSS_ICLR_RXIFG_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ICLR_RXIFG_CLR                   ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to RXIFG is
                                                                                    cleared */
/* DEBUGSS_ICLR[PWRUPIFG] Bits */
#define DEBUGSS_ICLR_PWRUPIFG_OFS                (2)                             /* !< PWRUPIFG Offset */
#define DEBUGSS_ICLR_PWRUPIFG_MASK               ((uint32_t)0x00000004U)         /* !< Clears PWRUPIFG in RIS register */
#define DEBUGSS_ICLR_PWRUPIFG_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ICLR_PWRUPIFG_CLR                ((uint32_t)0x00000004U)         /* !< RIS bit corresponding to PWRUPIFG
                                                                                    is cleared */
/* DEBUGSS_ICLR[PWRDWNIFG] Bits */
#define DEBUGSS_ICLR_PWRDWNIFG_OFS               (3)                             /* !< PWRDWNIFG Offset */
#define DEBUGSS_ICLR_PWRDWNIFG_MASK              ((uint32_t)0x00000008U)         /* !< Clears PWRDWNIFG in RIS register */
#define DEBUGSS_ICLR_PWRDWNIFG_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ICLR_PWRDWNIFG_CLR               ((uint32_t)0x00000008U)         /* !< RIS bit corresponding to PWRUPIFG
                                                                                    is cleared */

/* DEBUGSS_EVT_MODE Bits */
/* DEBUGSS_EVT_MODE[INT0_CFG] Bits */
#define DEBUGSS_EVT_MODE_INT0_CFG_OFS            (0)                             /* !< INT0_CFG Offset */
#define DEBUGSS_EVT_MODE_INT0_CFG_MASK           ((uint32_t)0x00000003U)         /* !< Event line mode select for
                                                                                    peripheral events */
#define DEBUGSS_EVT_MODE_INT0_CFG_DISABLE        ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define DEBUGSS_EVT_MODE_INT0_CFG_SOFTWARE       ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define DEBUGSS_EVT_MODE_INT0_CFG_HARDWARE       ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* DEBUGSS_DESC Bits */
/* DEBUGSS_DESC[MINREV] Bits */
#define DEBUGSS_DESC_MINREV_OFS                  (0)                             /* !< MINREV Offset */
#define DEBUGSS_DESC_MINREV_MASK                 ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
/* DEBUGSS_DESC[MAJREV] Bits */
#define DEBUGSS_DESC_MAJREV_OFS                  (4)                             /* !< MAJREV Offset */
#define DEBUGSS_DESC_MAJREV_MASK                 ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
/* DEBUGSS_DESC[INSTNUM] Bits */
#define DEBUGSS_DESC_INSTNUM_OFS                 (8)                             /* !< INSTNUM Offset */
#define DEBUGSS_DESC_INSTNUM_MASK                ((uint32_t)0x00000F00U)         /* !< Instance Number within the device.
                                                                                    This will be a parameter to the RTL
                                                                                    for modules that can have multiple
                                                                                    instances */
/* DEBUGSS_DESC[FEATUREVER] Bits */
#define DEBUGSS_DESC_FEATUREVER_OFS              (12)                            /* !< FEATUREVER Offset */
#define DEBUGSS_DESC_FEATUREVER_MASK             ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
/* DEBUGSS_DESC[MODULEID] Bits */
#define DEBUGSS_DESC_MODULEID_OFS                (16)                            /* !< MODULEID Offset */
#define DEBUGSS_DESC_MODULEID_MASK               ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */

/* DEBUGSS_TXD Bits */
/* DEBUGSS_TXD[TX_DATA] Bits */
#define DEBUGSS_TXD_TX_DATA_OFS                  (0)                             /* !< TX_DATA Offset */
#define DEBUGSS_TXD_TX_DATA_MASK                 ((uint32_t)0xFFFFFFFFU)         /* !< Contains data written by an
                                                                                    external debug tool to the SEC-AP
                                                                                    TXDATA register */

/* DEBUGSS_TXCTL Bits */
/* DEBUGSS_TXCTL[TRANSMIT] Bits */
#define DEBUGSS_TXCTL_TRANSMIT_OFS               (0)                             /* !< TRANSMIT Offset */
#define DEBUGSS_TXCTL_TRANSMIT_MASK              ((uint32_t)0x00000001U)         /* !< Indicates data request in DSSM.TXD,
                                                                                    set on write via Debug AP to
                                                                                    DSSM.TXD.  A read of the DSSM.TXD
                                                                                    register by SW will clear the TX
                                                                                    field. The tool can check that TXD is
                                                                                    empty by reading this field. */
#define DEBUGSS_TXCTL_TRANSMIT_EMPTY             ((uint32_t)0x00000000U)         /* !< TXD is empty */
#define DEBUGSS_TXCTL_TRANSMIT_FULL              ((uint32_t)0x00000001U)         /* !< TXD is full */
/* DEBUGSS_TXCTL[TRANSMIT_FLAGS] Bits */
#define DEBUGSS_TXCTL_TRANSMIT_FLAGS_OFS         (1)                             /* !< TRANSMIT_FLAGS Offset */
#define DEBUGSS_TXCTL_TRANSMIT_FLAGS_MASK        ((uint32_t)0xFFFFFFFEU)         /* !< Generic TX flags that can be set by
                                                                                    external debug tool. Functionality is
                                                                                    defined by SW. */

/* DEBUGSS_RXD Bits */
/* DEBUGSS_RXD[RX_DATA] Bits */
#define DEBUGSS_RXD_RX_DATA_OFS                  (0)                             /* !< RX_DATA Offset */
#define DEBUGSS_RXD_RX_DATA_MASK                 ((uint32_t)0xFFFFFFFFU)         /* !< Contains data written by SM/OW. */

/* DEBUGSS_RXCTL Bits */
/* DEBUGSS_RXCTL[RECEIVE] Bits */
#define DEBUGSS_RXCTL_RECEIVE_OFS                (0)                             /* !< RECEIVE Offset */
#define DEBUGSS_RXCTL_RECEIVE_MASK               ((uint32_t)0x00000001U)         /* !< Indicates SW write to the DSSM.RXD
                                                                                    register. A read of the DSSM.RXD
                                                                                    register by SWD Access Port will
                                                                                    clear the RX field. */
#define DEBUGSS_RXCTL_RECEIVE_EMPTY              ((uint32_t)0x00000000U)         /* !< RXD empty */
#define DEBUGSS_RXCTL_RECEIVE_FULL               ((uint32_t)0x00000001U)         /* !< RXD full */
/* DEBUGSS_RXCTL[RECEIVE_FLAGS] Bits */
#define DEBUGSS_RXCTL_RECEIVE_FLAGS_OFS          (1)                             /* !< RECEIVE_FLAGS Offset */
#define DEBUGSS_RXCTL_RECEIVE_FLAGS_MASK         ((uint32_t)0x000000FEU)         /* !< Generic RX flags that can be set by
                                                                                    SW and read by external debug tool.
                                                                                    Functionality is defined by SW. */

/* DEBUGSS_SPECIAL_AUTH Bits */
/* DEBUGSS_SPECIAL_AUTH[SECAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_SECAPEN_OFS         (0)                             /* !< SECAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_SECAPEN_MASK        ((uint32_t)0x00000001U)         /* !< An active high input. When asserted
                                                                                    (and SWD access is also permitted),
                                                                                    the debug tools can use the
                                                                                    Security-AP to communicate with
                                                                                    security control logic. When
                                                                                    deasserted, a DAPBUS firewall will
                                                                                    isolate the AP and prevent access to
                                                                                    the Security-AP. */
#define DEBUGSS_SPECIAL_AUTH_SECAPEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable SEC-AP */
#define DEBUGSS_SPECIAL_AUTH_SECAPEN_ENABLE      ((uint32_t)0x00000001U)         /* !< Enable SEC-AP */
/* DEBUGSS_SPECIAL_AUTH[SWDPORTEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_SWDPORTEN_OFS       (1)                             /* !< SWDPORTEN Offset */
#define DEBUGSS_SPECIAL_AUTH_SWDPORTEN_MASK      ((uint32_t)0x00000002U)         /* !< When asserted, the SW-DP functions
                                                                                    normally.  When deasserted, the SW-DP
                                                                                    effectively disables all external
                                                                                    debug access. */
#define DEBUGSS_SPECIAL_AUTH_SWDPORTEN_DISABLE   ((uint32_t)0x00000000U)         /* !< Disable SWD port */
#define DEBUGSS_SPECIAL_AUTH_SWDPORTEN_ENABLE    ((uint32_t)0x00000002U)         /* !< Enable SWD port */
/* DEBUGSS_SPECIAL_AUTH[DFTAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_DFTAPEN_OFS         (2)                             /* !< DFTAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_DFTAPEN_MASK        ((uint32_t)0x00000004U)         /* !< An active high input. When asserted
                                                                                    (and SWD access is also permitted),
                                                                                    the debug tools can then access the
                                                                                    DFT-AP external to the DebugSS lite.
                                                                                    When deasserted, a DAPBUS firewall
                                                                                    will isolate the AP and prevent
                                                                                    access. */
#define DEBUGSS_SPECIAL_AUTH_DFTAPEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable DFT-TAP */
#define DEBUGSS_SPECIAL_AUTH_DFTAPEN_ENABLE      ((uint32_t)0x00000004U)         /* !< Enable DFT-TAP */
/* DEBUGSS_SPECIAL_AUTH[ETAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_ETAPEN_OFS          (3)                             /* !< ETAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_ETAPEN_MASK         ((uint32_t)0x00000008U)         /* !< An active high input. When asserted
                                                                                    (and SWD access is also permitted),
                                                                                    the debug tools can then access an
                                                                                    ET-AP external to the DebugSS lite.
                                                                                    When deasserted, a DAPBUS firewall
                                                                                    will isolate the AP and prevent
                                                                                    access. */
#define DEBUGSS_SPECIAL_AUTH_ETAPEN_DISABLE      ((uint32_t)0x00000000U)         /* !< Disable ET+ -AP */
#define DEBUGSS_SPECIAL_AUTH_ETAPEN_ENABLE       ((uint32_t)0x00000008U)         /* !< Enable ET+ -AP */
/* DEBUGSS_SPECIAL_AUTH[CFGAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_CFGAPEN_OFS         (4)                             /* !< CFGAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_CFGAPEN_MASK        ((uint32_t)0x00000010U)         /* !< An active high input. When asserted
                                                                                    (and SWD access is also permitted),
                                                                                    the debug tools can use the Config-AP
                                                                                    to read device configuration
                                                                                    information. When deasserted, a
                                                                                    DAPBUS firewall will isolate the AP
                                                                                    and prevent access to the Config-AP. */
#define DEBUGSS_SPECIAL_AUTH_CFGAPEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable CFG-AP */
#define DEBUGSS_SPECIAL_AUTH_CFGAPEN_ENABLE      ((uint32_t)0x00000010U)         /* !< Enable CFG-AP */
/* DEBUGSS_SPECIAL_AUTH[AHBAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_AHBAPEN_OFS         (5)                             /* !< AHBAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_AHBAPEN_MASK        ((uint32_t)0x00000020U)         /* !< Disabling / enabling debug access
                                                                                    to the M0+ Core via the AHB-AP DAP
                                                                                    bus isolation. */
#define DEBUGSS_SPECIAL_AUTH_AHBAPEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable AHB-AP */
#define DEBUGSS_SPECIAL_AUTH_AHBAPEN_ENABLE      ((uint32_t)0x00000020U)         /* !< Enable AHB-AP */
/* DEBUGSS_SPECIAL_AUTH[PWRAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_PWRAPEN_OFS         (6)                             /* !< PWRAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_PWRAPEN_MASK        ((uint32_t)0x00000040U)         /* !< An active high input. When asserted
                                                                                    (and SWD access is also permitted),
                                                                                    the debug tools can then access the
                                                                                    PWR-AP to power and reset state of
                                                                                    the CPU. When deasserted, a DAPBUS
                                                                                    firewall will isolate the AP and
                                                                                    prevent access. */
#define DEBUGSS_SPECIAL_AUTH_PWRAPEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable PWR-AP */
#define DEBUGSS_SPECIAL_AUTH_PWRAPEN_ENABLE      ((uint32_t)0x00000040U)         /* !< Enable PWR-AP */

/* DEBUGSS_APP_AUTH Bits */
/* DEBUGSS_APP_AUTH[DBGEN] Bits */
#define DEBUGSS_APP_AUTH_DBGEN_OFS               (0)                             /* !< DBGEN Offset */
#define DEBUGSS_APP_AUTH_DBGEN_MASK              ((uint32_t)0x00000001U)         /* !< Controls invasive debug enable. */
#define DEBUGSS_APP_AUTH_DBGEN_DISABLE           ((uint32_t)0x00000000U)         /* !< Invasive debug disabled */
#define DEBUGSS_APP_AUTH_DBGEN_ENABLE            ((uint32_t)0x00000001U)         /* !< Invasive debug enabled */
/* DEBUGSS_APP_AUTH[NIDEN] Bits */
#define DEBUGSS_APP_AUTH_NIDEN_OFS               (1)                             /* !< NIDEN Offset */
#define DEBUGSS_APP_AUTH_NIDEN_MASK              ((uint32_t)0x00000002U)         /* !< Controls non-invasive debug enable. */
#define DEBUGSS_APP_AUTH_NIDEN_DISABLE           ((uint32_t)0x00000000U)         /* !< Non-invasive debug disabled */
#define DEBUGSS_APP_AUTH_NIDEN_ENABLE            ((uint32_t)0x00000002U)         /* !< Non-invasive debug enabled */
/* DEBUGSS_APP_AUTH[SPIDEN] Bits */
#define DEBUGSS_APP_AUTH_SPIDEN_OFS              (2)                             /* !< SPIDEN Offset */
#define DEBUGSS_APP_AUTH_SPIDEN_MASK             ((uint32_t)0x00000004U)         /* !< Secure invasive debug enable. */
#define DEBUGSS_APP_AUTH_SPIDEN_DISABLE          ((uint32_t)0x00000000U)         /* !< Invasive debug disabled */
#define DEBUGSS_APP_AUTH_SPIDEN_ENABLE           ((uint32_t)0x00000004U)         /* !< Invasive debug enabled */
/* DEBUGSS_APP_AUTH[SPNIDEN] Bits */
#define DEBUGSS_APP_AUTH_SPNIDEN_OFS             (3)                             /* !< SPNIDEN Offset */
#define DEBUGSS_APP_AUTH_SPNIDEN_MASK            ((uint32_t)0x00000008U)         /* !< Secure non-invasive debug enable. */
#define DEBUGSS_APP_AUTH_SPNIDEN_DISABLE         ((uint32_t)0x00000000U)         /* !< Invasive debug disabled */
#define DEBUGSS_APP_AUTH_SPNIDEN_ENABLE          ((uint32_t)0x00000008U)         /* !< Invasive debug enabled */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_m0p_hw_debugss__include */
